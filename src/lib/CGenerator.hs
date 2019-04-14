module CGenerator where

import Utils
import Parser
import CompilerConfig
import Tokenizer
import FileSys
import Lexer
import Encoding


defineS :: String -> String
defineS = (++) "#define "

genFlags :: CompilerConfig -> [String]
genFlags cfg =
	pairs |> filter applyfst |> map snd |> map defineS
	where
		pairs = [ (countTotalExecs, "COUNT_TOTAL_EXEC")
		        , (trackAllocs,     "TRACK_ALLOCS")
		        , (trackPoolAllocs, "TRACK_POOL_ALLOCS")
		        ]
		applyfst (f, _) = f cfg


getPrefix :: String -> String
getPrefix = (++) "lambdacc_"

getInitName :: String -> String
getInitName uniqueName = getPrefix "init_" ++ uniqueName

getExecName :: String -> String
getExecName uniqueName = getPrefix "exec_" ++ uniqueName

getTypeid :: String -> String
getTypeid uniqueName = getPrefix "typeid_" ++ uniqueName

getInitDecl :: String -> String
getInitDecl initName = "ff " ++ initName ++ " (ff parent)"

data StructField = 
	StructField
	{ leaf :: Leaf
	, index :: Int
	}

getFields :: Leaf -> [StructField]
getFields l =
	case l of
		(Lambda scope argname leafs) ->
			collect leafs 0
		(SubExpr scope leafs) ->
			collect leafs 0
		(Variable scope id) ->
			error "Getting field of argument"
	where
		collect :: [Leaf] -> Int -> [StructField]
		collect [] index = []
		collect (v@(Variable scope id) : xs) index =
			StructField { leaf = v, index = -1 } : collect xs index
		collcet (l : xs) index =
			StructField { leaf = l, index = index } : collect xs (index + 1)

genTypeuuid :: CompilerConfig -> Leaf -> String -> [String]
genTypeuuid cfg lambda lambdaName =
	if useTypeid cfg then
		undefined
	else []

genInitFunc :: CompilerConfig -> Leaf -> String -> [String]
genInitFunc cfg lambda lambdaName =
	body
	where
		uniqueName = getUniqueName lambda
		initName = getInitName uniqueName
		execName = getExecName uniqueName
		decl = getInitDecl initName

		fields = getFields lambda
		numLeafs = 1 + (foldl max (-1) $ map index fields)

		typeuuid :: String
		typeuuid =
			if useTypeid cfg then
				let typeidName = getTypeid uniqueName
				in "me->typeuuid = " ++ typeidName ++ ";"
			else []

		body = [ "ff me = ALLOC_GET(sizeof(struct fun));"
		       , "me->parent = parent;"
		       , "me->eval_now = " ++ execName ++ ";"
		       , "me->customsize = 0;"
		       , typeuuid
		       , "return me"
		       ]


