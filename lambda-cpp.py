#!/usr/bin/env python3

import parser
from parser import *
from functools import reduce

import inliner
from os import path

class ClassifiedLine:
	def __init__(self, good: str, all: str):
		self.good = good
		self.all = all

class SplittedLine:
	def __init__(self, pre: str, post: str, all: str):
		self.pre = pre
		self.post = post
		self.all = all
	def get_name_and_token(self) -> (str, Branch):
		branch = parse_tokens(self.post) if self.post else None
		return TokenizedLine (bind_name=self.pre, branch=branch, all=self.all)

class TokenizedLine:
	def __init__(self, bind_name: str, branch: Branch, all: str):
		self.bind_name = bind_name
		self.branch = branch
		self.all = all

class ParsedLine:
	def __init__(self, bind: Bind, all: str):
		self.bind = bind
		self.all = all

def split_binding_and_def(cline: ClassifiedLine) -> SplittedLine:
	line = cline.good
	if not line:
		return SplittedLine (pre=None, post=None, all=cline.all)

	(pre, _, p) = line.partition(' ')
	(p2, mid, post) = p.strip().partition('=')

	post = post.strip()
	if len(p2) <= 0:
		if not post:
			raise SyntaxError('Binding at line "{}" cannot have empty definition'.format(line))

		pre = pre.strip()
		if not pre:
			raise SyntaxError('Binding at line "{}" cannot have empty name'.format(line))
		if parser.LAMBDA_SYMBOL in pre or '\\' in pre:
			raise SyntaxError('Binding "{}" has invalid symbols in its name'.format(pre))
	else:
		post = line.strip()
		pre = None
	return SplittedLine (pre=pre, post=post, all=cline.all)
	
def join_lines(lines: iter) -> iter:
	prev = None
	for o in lines:
		if  o.startswith('\t') or o.startswith('    '):
			prev += ' ' + o.strip()
			yield ''
		else:
			if not prev is None:
				yield prev
			prev = o
	prev = prev.strip()
	if prev: yield prev

def filter_lines(lines: iter) -> iter:
	for o in lines:
		if len(o) < 1 or o.isspace() or o[0] == ';':
			yield ClassifiedLine (None, o)
		elif '#' in o:
			(pre, _, _) = o.partition('#')
			pre = pre.strip()
			if len(pre) < 1:
				yield ClassifiedLine (None, o)
			else:
				yield ClassifiedLine (pre, o)
		else:
			yield ClassifiedLine (o, o)

def parse_text(text: str) -> iter:
	linesR = text.split('\n')
	linesR = list(join_lines(linesR))
	lines = list(filter_lines(linesR))
	tuples = map(split_binding_and_def, lines)
	toks = map(SplittedLine.get_name_and_token, tuples)

	def get_tagged_tok(acc, tok):
		(tid, arr) = acc
		return (tid + 1, arr + [(tid, tok)])
	(count, tagged_toks) = list(reduce(get_tagged_tok, toks, (0, [])))

	def get_tok_keyvalue(tagged_tok):
		(tid, t) = tagged_tok
		return (tid, Bind(t.bind_name, target=None))

	# Load all binds first
	bdict = dict( map(get_tok_keyvalue, filter(lambda t: t[1].branch, tagged_toks)) )
	binds = list(bdict.values())

	# Init bind targets
	for tt in tagged_toks:
		(tid, t) = tt
		if t.branch:
			br = t.branch

			b = bdict[tid]
			s = parse_structure( b=br, scope=[], binds=binds, parent=b )
			b.target = s

			yield ParsedLine(bind=b, all=t.all)
		else:
			yield ParsedLine(bind=None, all=t.all)

def get_arguments():
	import argparse
	parser = argparse.ArgumentParser(formatter_class=argparse.ArgumentDefaultsHelpFormatter)

	parser.add_argument('--source', required=True, help='Path to the source file of lambda script')
	parser.add_argument('--dest', required=True, help='Path to the output file')

	parser.add_argument('--show-debug', dest='show_debug', action='store_true', help='Include debug information')
	parser.add_argument('--no-show-debug', dest='show_debug', action='store_false', help=None)
	parser.set_defaults(show_debug=False)

	parser.add_argument('--print-intermediate', dest='print_intermediate', action='store_true', help='Print intermediate representation of lambda script')
	parser.add_argument('--no-print-intermediate', dest='print_intermediate', action='store_false', help=None)
	parser.set_defaults(print_intermediate=True)

	parser.add_argument('--use-typeid', dest='use_typeid', action='store_true', help='Use unique_id to determine lambda type')
	parser.add_argument('--no-use-typeid', dest='use_typeid', action='store_false', help=None)
	parser.set_defaults(use_typeid=True)

	parser.add_argument('--make-inline', dest='make_inline', action='store_true', help='Inline all bindings except for recursive ones')
	parser.add_argument('--no-make-inline', dest='make_inline', action='store_false', help=None)
	parser.set_defaults(make_inline=True)

	parser.add_argument('--do-caching', dest='do_caching', action='store_true', help='Cache all aplications to not repeat the work')
	parser.add_argument('--no-do-caching', dest='do_caching', action='store_false', help=None)
	parser.set_defaults(do_caching=True)

	parser.add_argument('--count-total-exec', dest='count_total_exec', action='store_true', help='Count number of applications')
	parser.add_argument('--no-count-total-exec', dest='count_total_exec', action='store_false', help=None)
	parser.set_defaults(count_total_exec=True)

	parser.add_argument('--echo-expr', dest='echo_expr', action='store_true', help='Echo expression to be evaluated')
	parser.add_argument('--no-echo-expr', dest='echo_expr', action='store_false', help=None)
	parser.set_defaults(echo_expr=True)

	def includehelp(name): return 'File to be included after generated file "{}" section'.format(name)
	parser.add_argument('--headerfile', help=includehelp('header'))
	parser.add_argument('--declare-file', help=includehelp('declare'))
	parser.add_argument('--define-file', help=includehelp('define'))
	parser.add_argument('--footerfile', help=includehelp('footer'))

	return parser.parse_args()

def make_inline(args, parsed: list) -> None:
	args.source = path.splitext(args.source)[0] + '.inline' + path.splitext(args.source)[1]
	args.make_inline = False

	w = open(args.source, 'w+')

	for p in parsed:
		if p.bind:
			if p.bind.name:
				w.write(p.bind.name + ' = ')
			w.write(inliner.get_leaf_text(le=p.bind.target))
		else:
			w.write(p.all)
		w.write('\n')

	w.close()

	return processone(args=args)

def processone(args):
	text = ''
	source = args.source

	with open(source, 'r') as r:
		text = r.read()

	parsed = list(parse_text(text))

	if args.make_inline:
		return make_inline(args=args, parsed=parsed)

	binds = list(filter (lambda b: not b is None, map(lambda p: p.bind, parsed)))
	if args.print_intermediate:
		for b in binds:
			print('{}=\n{}\n\n'.format(b.name, b.target.print(0)))

	import writer
	config = writer.OutConfig(
		filename=args.dest,
		show_debug=args.show_debug,
		use_typeid=args.use_typeid,
		headerfile=args.headerfile,
		declare_file=args.declare_file,
		define_file=args.define_file,
		footerfile=args.footerfile,
		do_caching=args.do_caching,
		count_total_exec=args.count_total_exec,
		echo_expr=args.echo_expr)
	writer.write_some(config=config, binds=binds)

def main():
	args = get_arguments()
	processone(args)
	
if __name__ == '__main__':
	main()


