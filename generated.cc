#define SHOW_DEBUG

#define der(name)    struct name : fun
#define ovv      ff eval_now(ff x) override
// #define dlajdkladjlkasjdla {}

class fun;
typedef fun * ff;

typedef ff (*exec_t)(ff, ff);

class fun {
protected:
	fun() {}
public:
	const fun * parent = nullptr;
	ff x;
	ff eval(ff x) {
		return eval_now(this, x);
	}
	exec_t eval_now;

#ifdef SHOW_DEBUG
	virtual const char * tostr() = 0;
#endif
};

#include <cstdio>

// der(debug_id) {
// 	debug_id() {}
// 	ovv {
// 		return x;
// 	}
// };
// static debug_id debug_id_instance{};
// static debug_id * debug_id_instance_ptr = &debug_id_instance;

// der(error_not_lambda) {
// 	error_not_lambda() {}
// 	ovv {
// 		throw puts("error: this lambda is not supposed to be evaluated");
// 	}
// };
// static error_not_lambda error_not_lambda_instance{};
// static error_not_lambda * error_not_lambda_ptr = &error_not_lambda_instance;

struct Bind_error : fun {

#ifdef SHOW_DEBUG
	const char * tostr() override { return "ERROR"; }
#endif
};
struct Bind_error * bind_err = new Bind_error;

struct Bind_print_true : fun {
	struct Bind_error * m_Bind_error;

#ifdef SHOW_DEBUG
	const char * tostr() override { return "$print_true"; }
#endif
};
struct Bind_print_false : fun {
	struct Bind_error * m_Bind_error;

#ifdef SHOW_DEBUG
	const char * tostr() override { return "$print_false"; }
#endif
};

ff Exec_Bind_error       (ff me_abs, ff x);
ff Exec_Bind_print_false (ff me_abs, ff x);
ff Exec_Bind_print_true  (ff me_abs, ff x);

int Init_Bind_error (ff me) {
	me->eval_now = Exec_Bind_error;
	return 0;
}

int Init_Bind_print_true (ff me) {
	// puts ("TRUE INITED");
	me->eval_now = Exec_Bind_print_true;
	return 0;
}
int Init_Bind_print_false (ff me) {
	// puts ("FALS INITED");
	me->eval_now = Exec_Bind_print_false;
	return 0;
}

ff Exec_Bind_print_true (ff me_abs, ff x) {
	struct Bind_print_true * me = (struct Bind_print_true *)me_abs;
	if (me->x == NULL) {
		me->m_Bind_error = new Bind_error;
		me->m_Bind_error->parent = me;
		Init_Bind_error(me->m_Bind_error);
	}
	me->x = x;
	puts("TRUE");
	return me->m_Bind_error;
}
ff Exec_Bind_print_false (ff me_abs, ff x) {
	struct Bind_print_false * me = (struct Bind_print_false *)me_abs;
	if (me->x == NULL) {
		me->m_Bind_error = new Bind_error;
		me->m_Bind_error->parent = me;
		Init_Bind_error(me->m_Bind_error);
	}
	me->x = x;
	puts("FALSE");
	return me->m_Bind_error;
}
ff Exec_Bind_error (ff me_abs, ff x) {
	puts("ERROR: This is not supposed to be evaluated!");
	return NULL;
}

// struct Bind_num : fun {
// 	Bind_num() {}
// 	ovv {
		
// 	}
// };



struct Bind_id;
struct Lambda_7;
struct Bind_true;
struct Lambda_12;
struct Bind_false;
struct Bind_not;
struct Lambda_22;
struct Lambda_20;
struct Bind_if;
struct Lambda_29;
struct Lambda_27;
struct Bind_kek;
struct Lambda_36;
struct Lambda_34;
struct Bind_pair;
struct Bind_fst;
struct Bind_snd;
struct Bind_zero;
struct Bind_is0;
struct Leaf_48;
struct Bind_suc;
struct Bind_pred;
struct Bind_get0;
struct Leaf_58;
struct Leaf_59;
struct Leaf_60;
struct Bind_assert;
struct EXPR_0;
struct Leaf_68;
struct Leaf_69;
struct Leaf_70;
struct Leaf_71;


int Init_Bind_id                   (struct Bind_id *me);
int Init_Lambda_7                  (struct Lambda_7 *me);
int Init_Bind_true                 (struct Bind_true *me);
int Init_Lambda_12                 (struct Lambda_12 *me);
int Init_Bind_false                (struct Bind_false *me);
int Init_Bind_not                  (struct Bind_not *me);
int Init_Lambda_22                 (struct Lambda_22 *me);
int Init_Lambda_20                 (struct Lambda_20 *me);
int Init_Bind_if                   (struct Bind_if *me);
int Init_Lambda_29                 (struct Lambda_29 *me);
int Init_Lambda_27                 (struct Lambda_27 *me);
int Init_Bind_kek                  (struct Bind_kek *me);
int Init_Lambda_36                 (struct Lambda_36 *me);
int Init_Lambda_34                 (struct Lambda_34 *me);
int Init_Bind_pair                 (struct Bind_pair *me);
int Init_Bind_fst                  (struct Bind_fst *me);
int Init_Bind_snd                  (struct Bind_snd *me);
int Init_Bind_zero                 (struct Bind_zero *me);
int Init_Bind_is0                  (struct Bind_is0 *me);
int Init_Leaf_48                   (struct Leaf_48 *me);
int Init_Bind_suc                  (struct Bind_suc *me);
int Init_Bind_pred                 (struct Bind_pred *me);
int Init_Bind_get0                 (struct Bind_get0 *me);
int Init_Leaf_58                   (struct Leaf_58 *me);
int Init_Leaf_59                   (struct Leaf_59 *me);
int Init_Leaf_60                   (struct Leaf_60 *me);
int Init_Bind_assert               (struct Bind_assert *me);
int Init_EXPR_0                    (struct EXPR_0 *me);
int Init_Leaf_68                   (struct Leaf_68 *me);
int Init_Leaf_69                   (struct Leaf_69 *me);
int Init_Leaf_70                   (struct Leaf_70 *me);
int Init_Leaf_71                   (struct Leaf_71 *me);


ff Exec_Bind_id                   (ff me_abs, ff x);
ff Exec_Lambda_7                  (ff me_abs, ff x);
ff Exec_Bind_true                 (ff me_abs, ff x);
ff Exec_Lambda_12                 (ff me_abs, ff x);
ff Exec_Bind_false                (ff me_abs, ff x);
ff Exec_Bind_not                  (ff me_abs, ff x);
ff Exec_Lambda_22                 (ff me_abs, ff x);
ff Exec_Lambda_20                 (ff me_abs, ff x);
ff Exec_Bind_if                   (ff me_abs, ff x);
ff Exec_Lambda_29                 (ff me_abs, ff x);
ff Exec_Lambda_27                 (ff me_abs, ff x);
ff Exec_Bind_kek                  (ff me_abs, ff x);
ff Exec_Lambda_36                 (ff me_abs, ff x);
ff Exec_Lambda_34                 (ff me_abs, ff x);
ff Exec_Bind_pair                 (ff me_abs, ff x);
ff Exec_Bind_fst                  (ff me_abs, ff x);
ff Exec_Bind_snd                  (ff me_abs, ff x);
ff Exec_Bind_zero                 (ff me_abs, ff x);
ff Exec_Bind_is0                  (ff me_abs, ff x);
ff Exec_Leaf_48                   (ff me_abs, ff x);
ff Exec_Bind_suc                  (ff me_abs, ff x);
ff Exec_Bind_pred                 (ff me_abs, ff x);
ff Exec_Bind_get0                 (ff me_abs, ff x);
ff Exec_Leaf_58                   (ff me_abs, ff x);
ff Exec_Leaf_59                   (ff me_abs, ff x);
ff Exec_Leaf_60                   (ff me_abs, ff x);
ff Exec_Bind_assert               (ff me_abs, ff x);
ff Exec_EXPR_0                    (ff me_abs, ff x);
ff Exec_Leaf_68                   (ff me_abs, ff x);
ff Exec_Leaf_69                   (ff me_abs, ff x);
ff Exec_Leaf_70                   (ff me_abs, ff x);
ff Exec_Leaf_71                   (ff me_abs, ff x);


der(Bind_id) {

	const char * tostr() override { return "Bind_id"; }
};

der(Lambda_7) {

	const char * tostr() override { return "Lambda_7"; }
};

der(Bind_true) {
	Lambda_7                       * m_0;

	const char * tostr() override { return "Bind_true"; }
};

der(Lambda_12) {

	const char * tostr() override { return "Lambda_12"; }
};

der(Bind_false) {
	Lambda_12                      * m_0;

	const char * tostr() override { return "Bind_false"; }
};

der(Bind_not) {
	Bind_false                     * m_1;
	Bind_true                      * m_2;

	const char * tostr() override { return "Bind_not"; }
};

der(Lambda_22) {

	const char * tostr() override { return "Lambda_22"; }
};

der(Lambda_20) {
	Lambda_22                      * m_0;

	const char * tostr() override { return "Lambda_20"; }
};

der(Bind_if) {
	Lambda_20                      * m_0;

	const char * tostr() override { return "Bind_if"; }
};

der(Lambda_29) {

	const char * tostr() override { return "Lambda_29"; }
};

der(Lambda_27) {
	Lambda_29                      * m_0;

	const char * tostr() override { return "Lambda_27"; }
};

der(Bind_kek) {
	Lambda_27                      * m_0;

	const char * tostr() override { return "Bind_kek"; }
};

der(Lambda_36) {

	const char * tostr() override { return "Lambda_36"; }
};

der(Lambda_34) {
	Lambda_36                      * m_0;

	const char * tostr() override { return "Lambda_34"; }
};

der(Bind_pair) {
	Lambda_34                      * m_0;

	const char * tostr() override { return "Bind_pair"; }
};

der(Bind_fst) {
	Bind_true                      * m_1;

	const char * tostr() override { return "Bind_fst"; }
};

der(Bind_snd) {
	Bind_false                     * m_1;

	const char * tostr() override { return "Bind_snd"; }
};

der(Bind_zero) {
	Bind_pair                      * m_0;
	Bind_true                      * m_1;
	Bind_id                        * m_2;

	const char * tostr() override { return "Bind_zero"; }
};

der(Bind_is0) {
	Bind_if                        * m_0;
	Leaf_48                        * m_1;
	Bind_true                      * m_2;
	Bind_false                     * m_3;

	const char * tostr() override { return "Bind_is0"; }
};

der(Leaf_48) {
	Bind_fst                       * m_0;

	const char * tostr() override { return "Leaf_48"; }
};

der(Bind_suc) {
	Bind_pair                      * m_0;
	Bind_false                     * m_1;

	const char * tostr() override { return "Bind_suc"; }
};

der(Bind_pred) {
	Bind_snd                       * m_0;

	const char * tostr() override { return "Bind_pred"; }
};

der(Bind_get0) {
	Bind_if                        * m_0;
	Leaf_58                        * m_1;
	Leaf_59                        * m_3;

	const char * tostr() override { return "Bind_get0"; }
};

der(Leaf_58) {
	Bind_is0                       * m_0;

	const char * tostr() override { return "Leaf_58"; }
};

der(Leaf_59) {
	Bind_get0                      * m_0;
	Leaf_60                        * m_1;

	const char * tostr() override { return "Leaf_59"; }
};

der(Leaf_60) {
	Bind_pred                      * m_0;

	const char * tostr() override { return "Leaf_60"; }
};

der(Bind_assert) {
	Bind_print_true                * m_1;
	Bind_print_false               * m_2;

	const char * tostr() override { return "Bind_assert"; }
};

der(EXPR_0) {
	Bind_assert                    * m_0;
	Leaf_68                        * m_1;

	const char * tostr() override { return "EXPR_0"; }
};

der(Leaf_68) {
	Bind_if                        * m_0;
	Bind_true                      * m_1;
	Bind_false                     * m_2;
	Leaf_69                        * m_3;

	const char * tostr() override { return "Leaf_68"; }
};

der(Leaf_69) {
	Bind_not                       * m_0;
	Leaf_70                        * m_1;

	const char * tostr() override { return "Leaf_69"; }
};

der(Leaf_70) {
	Bind_not                       * m_0;
	Leaf_71                        * m_1;

	const char * tostr() override { return "Leaf_70"; }
};

der(Leaf_71) {
	Bind_not                       * m_0;
	Bind_false                     * m_1;

	const char * tostr() override { return "Leaf_71"; }
};



int Init_Bind_id                   (struct Bind_id *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Bind_id;
	}

	return 0;
}

int Init_Lambda_7                  (struct Lambda_7 *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Lambda_7;
	}

	return 0;
}

int Init_Bind_true                 (struct Bind_true *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Bind_true;
	}

	return 0;
}

int Init_Lambda_12                 (struct Lambda_12 *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Lambda_12;
	}

	return 0;
}

int Init_Bind_false                (struct Bind_false *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Bind_false;
	}

	return 0;
}

int Init_Bind_not                  (struct Bind_not *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Bind_not;
	}

	return 0;
}

int Init_Lambda_22                 (struct Lambda_22 *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Lambda_22;
	}

	return 0;
}

int Init_Lambda_20                 (struct Lambda_20 *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Lambda_20;
	}

	return 0;
}

int Init_Bind_if                   (struct Bind_if *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Bind_if;
	}

	return 0;
}

int Init_Lambda_29                 (struct Lambda_29 *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Lambda_29;
	}

	return 0;
}

int Init_Lambda_27                 (struct Lambda_27 *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Lambda_27;
	}

	return 0;
}

int Init_Bind_kek                  (struct Bind_kek *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Bind_kek;
	}

	return 0;
}

int Init_Lambda_36                 (struct Lambda_36 *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Lambda_36;
	}

	return 0;
}

int Init_Lambda_34                 (struct Lambda_34 *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Lambda_34;
	}

	return 0;
}

int Init_Bind_pair                 (struct Bind_pair *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Bind_pair;
	}

	return 0;
}

int Init_Bind_fst                  (struct Bind_fst *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Bind_fst;
	}

	return 0;
}

int Init_Bind_snd                  (struct Bind_snd *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Bind_snd;
	}

	return 0;
}

int Init_Bind_zero                 (struct Bind_zero *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Bind_zero;
	}

	return 0;
}

int Init_Bind_is0                  (struct Bind_is0 *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Bind_is0;
	}

	return 0;
}

int Init_Leaf_48                   (struct Leaf_48 *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Leaf_48;
	}

	return 0;
}

int Init_Bind_suc                  (struct Bind_suc *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Bind_suc;
	}

	return 0;
}

int Init_Bind_pred                 (struct Bind_pred *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Bind_pred;
	}

	return 0;
}

int Init_Bind_get0                 (struct Bind_get0 *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Bind_get0;
	}

	return 0;
}

int Init_Leaf_58                   (struct Leaf_58 *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Leaf_58;
	}

	return 0;
}

int Init_Leaf_59                   (struct Leaf_59 *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Leaf_59;
	}

	return 0;
}

int Init_Leaf_60                   (struct Leaf_60 *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Leaf_60;
	}

	return 0;
}

int Init_Bind_assert               (struct Bind_assert *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Bind_assert;
	}

	return 0;
}

int Init_EXPR_0                    (struct EXPR_0 *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_EXPR_0;
	}

	return 0;
}

int Init_Leaf_68                   (struct Leaf_68 *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Leaf_68;
	}

	return 0;
}

int Init_Leaf_69                   (struct Leaf_69 *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Leaf_69;
	}

	return 0;
}

int Init_Leaf_70                   (struct Leaf_70 *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Leaf_70;
	}

	return 0;
}

int Init_Leaf_71                   (struct Leaf_71 *me) {
	if (me->eval_now == NULL) {
		me->eval_now = Exec_Leaf_71;
	}

	return 0;
}



ff Exec_Bind_id                   (ff me_abs, ff x) {
	struct Bind_id * me = (struct Bind_id *)me_abs;
	printf ("Lam [%s] got [%s]\n", me->tostr(), x->tostr());
	if (me->x == NULL) {
	}
	me->x = x;
	return (me->x);
}

ff Exec_Lambda_7                  (ff me_abs, ff x) {
	struct Lambda_7 * me = (struct Lambda_7 *)me_abs;
	printf ("Lam [%s] got [%s]\n", me->tostr(), x->tostr());
	if (me->x == NULL) {
	}
	me->x = x;
	return (me->parent->x);
}

ff Exec_Bind_true                 (ff me_abs, ff x) {
	struct Bind_true * me = (struct Bind_true *)me_abs;
	printf ("Lam [%s] got [%s]\n", me->tostr(), x->tostr());
	if (me->x == NULL) {
		me->m_0 = new Lambda_7;
		me->m_0->parent = me;
		Init_Lambda_7(me->m_0);
	}
	me->x = x;
	return ((me->m_0));
}

ff Exec_Lambda_12                 (ff me_abs, ff x) {
	struct Lambda_12 * me = (struct Lambda_12 *)me_abs;
	printf ("Lam [%s] got [%s]\n", me->tostr(), x->tostr());
	if (me->x == NULL) {
	}
	me->x = x;
	return (me->x);
}

ff Exec_Bind_false                (ff me_abs, ff x) {
	struct Bind_false * me = (struct Bind_false *)me_abs;
	printf ("Lam [%s] got [%s]\n", me->tostr(), x->tostr());
	if (me->x == NULL) {
		me->m_0 = new Lambda_12;
		me->m_0->parent = me;
		Init_Lambda_12(me->m_0);
	}
	me->x = x;
	return ((me->m_0));
}

ff Exec_Bind_not                  (ff me_abs, ff x) {
	struct Bind_not * me = (struct Bind_not *)me_abs;
	printf ("Lam [%s] got [%s]\n", me->tostr(), x->tostr());
	if (me->x == NULL) {
		me->m_1 = new Bind_false;
		me->m_1->parent = me;
		Init_Bind_false(me->m_1);
		me->m_2 = new Bind_true;
		me->m_2->parent = me;
		Init_Bind_true(me->m_2);
	}
	me->x = x;
	return (me->x->eval((me->m_1))->eval((me->m_2)));
}

ff Exec_Lambda_22                 (ff me_abs, ff x) {
	struct Lambda_22 * me = (struct Lambda_22 *)me_abs;
	printf ("Lam [%s] got [%s]\n", me->tostr(), x->tostr());
	if (me->x == NULL) {
	}
	me->x = x;
	return (me->parent->parent->x->eval(me->parent->x)->eval(me->x));
}

ff Exec_Lambda_20                 (ff me_abs, ff x) {
	struct Lambda_20 * me = (struct Lambda_20 *)me_abs;
	printf ("Lam [%s] got [%s]\n", me->tostr(), x->tostr());
	if (me->x == NULL) {
		me->m_0 = new Lambda_22;
		me->m_0->parent = me;
		Init_Lambda_22(me->m_0);
	}
	me->x = x;
	return ((me->m_0));
}

ff Exec_Bind_if                   (ff me_abs, ff x) {
	struct Bind_if * me = (struct Bind_if *)me_abs;
	printf ("Lam [%s] got [%s]\n", me->tostr(), x->tostr());
	if (me->x == NULL) {
		me->m_0 = new Lambda_20;
		me->m_0->parent = me;
		Init_Lambda_20(me->m_0);
	}
	me->x = x;
	return ((me->m_0));
}

ff Exec_Lambda_29                 (ff me_abs, ff x) {
	struct Lambda_29 * me = (struct Lambda_29 *)me_abs;
	printf ("Lam [%s] got [%s]\n", me->tostr(), x->tostr());
	if (me->x == NULL) {
	}
	me->x = x;
	return (me->parent->x);
}

ff Exec_Lambda_27                 (ff me_abs, ff x) {
	struct Lambda_27 * me = (struct Lambda_27 *)me_abs;
	printf ("Lam [%s] got [%s]\n", me->tostr(), x->tostr());
	if (me->x == NULL) {
		me->m_0 = new Lambda_29;
		me->m_0->parent = me;
		Init_Lambda_29(me->m_0);
	}
	me->x = x;
	return ((me->m_0)->eval(me->parent->x));
}

ff Exec_Bind_kek                  (ff me_abs, ff x) {
	struct Bind_kek * me = (struct Bind_kek *)me_abs;
	printf ("Lam [%s] got [%s]\n", me->tostr(), x->tostr());
	if (me->x == NULL) {
		me->m_0 = new Lambda_27;
		me->m_0->parent = me;
		Init_Lambda_27(me->m_0);
	}
	me->x = x;
	return ((me->m_0));
}

ff Exec_Lambda_36                 (ff me_abs, ff x) {
	struct Lambda_36 * me = (struct Lambda_36 *)me_abs;
	printf ("Lam [%s] got [%s]\n", me->tostr(), x->tostr());
	if (me->x == NULL) {
	}
	me->x = x;
	return (me->x->eval(me->parent->parent->x)->eval(me->parent->x));
}

ff Exec_Lambda_34                 (ff me_abs, ff x) {
	struct Lambda_34 * me = (struct Lambda_34 *)me_abs;
	printf ("Lam [%s] got [%s]\n", me->tostr(), x->tostr());
	if (me->x == NULL) {
		me->m_0 = new Lambda_36;
		me->m_0->parent = me;
		Init_Lambda_36(me->m_0);
	}
	me->x = x;
	return ((me->m_0));
}

ff Exec_Bind_pair                 (ff me_abs, ff x) {
	struct Bind_pair * me = (struct Bind_pair *)me_abs;
	printf ("Lam [%s] got [%s]\n", me->tostr(), x->tostr());
	if (me->x == NULL) {
		me->m_0 = new Lambda_34;
		me->m_0->parent = me;
		Init_Lambda_34(me->m_0);
	}
	me->x = x;
	return ((me->m_0));
}

ff Exec_Bind_fst                  (ff me_abs, ff x) {
	struct Bind_fst * me = (struct Bind_fst *)me_abs;
	printf ("Lam [%s] got [%s]\n", me->tostr(), x->tostr());
	if (me->x == NULL) {
		me->m_1 = new Bind_true;
		me->m_1->parent = me;
		Init_Bind_true(me->m_1);
	}
	me->x = x;
	return (me->x->eval((me->m_1)));
}

ff Exec_Bind_snd                  (ff me_abs, ff x) {
	struct Bind_snd * me = (struct Bind_snd *)me_abs;
	printf ("Lam [%s] got [%s]\n", me->tostr(), x->tostr());
	if (me->x == NULL) {
		me->m_1 = new Bind_false;
		me->m_1->parent = me;
		Init_Bind_false(me->m_1);
	}
	me->x = x;
	return (me->x->eval((me->m_1)));
}

ff Exec_Bind_zero                 (ff me_abs, ff x) {
	struct Bind_zero * me = (struct Bind_zero *)me_abs;
	printf ("Lam [%s] got [%s]\n", me->tostr(), x->tostr());
	if (me->x == NULL) {
		me->m_0 = new Bind_pair;
		me->m_0->parent = me;
		Init_Bind_pair(me->m_0);
		me->m_1 = new Bind_true;
		me->m_1->parent = me;
		Init_Bind_true(me->m_1);
		me->m_2 = new Bind_id;
		me->m_2->parent = me;
		Init_Bind_id(me->m_2);
	}
	me->x = x;
	return ((me->m_0)->eval((me->m_1))->eval((me->m_2)))->eval(x);
}

ff Exec_Leaf_48                   (ff me_abs, ff x) {
	struct Leaf_48 * me = (struct Leaf_48 *)me_abs;
	printf ("Lam [%s] got [%s]\n", me->tostr(), x->tostr());
	if (me->x == NULL) {
		me->m_0 = new Bind_fst;
		me->m_0->parent = me;
		Init_Bind_fst(me->m_0);
	}
	me->x = x;
	return ((me->m_0)->eval(me->parent->x))->eval(x);
}

ff Exec_Bind_is0                  (ff me_abs, ff x) {
	struct Bind_is0 * me = (struct Bind_is0 *)me_abs;
	printf ("Lam [%s] got [%s]\n", me->tostr(), x->tostr());
	if (me->x == NULL) {
		me->m_0 = new Bind_if;
		me->m_0->parent = me;
		Init_Bind_if(me->m_0);
		me->m_1 = new Leaf_48;
		me->m_1->parent = me;
		Init_Leaf_48(me->m_1);
		me->m_2 = new Bind_true;
		me->m_2->parent = me;
		Init_Bind_true(me->m_2);
		me->m_3 = new Bind_false;
		me->m_3->parent = me;
		Init_Bind_false(me->m_3);
	}
	me->x = x;
	return ((me->m_0)->eval((me->m_1))->eval((me->m_2))->eval((me->m_3)));
}

ff Exec_Bind_suc                  (ff me_abs, ff x) {
	struct Bind_suc * me = (struct Bind_suc *)me_abs;
	printf ("Lam [%s] got [%s]\n", me->tostr(), x->tostr());
	if (me->x == NULL) {
		me->m_0 = new Bind_pair;
		me->m_0->parent = me;
		Init_Bind_pair(me->m_0);
		me->m_1 = new Bind_false;
		me->m_1->parent = me;
		Init_Bind_false(me->m_1);
	}
	me->x = x;
	return ((me->m_0)->eval((me->m_1))->eval(me->x));
}

ff Exec_Bind_pred                 (ff me_abs, ff x) {
	struct Bind_pred * me = (struct Bind_pred *)me_abs;
	printf ("Lam [%s] got [%s]\n", me->tostr(), x->tostr());
	if (me->x == NULL) {
		me->m_0 = new Bind_snd;
		me->m_0->parent = me;
		Init_Bind_snd(me->m_0);
	}
	me->x = x;
	return ((me->m_0)->eval(me->x));
}

ff Exec_Leaf_58                   (ff me_abs, ff x) {
	struct Leaf_58 * me = (struct Leaf_58 *)me_abs;
	printf ("Lam [%s] got [%s]\n", me->tostr(), x->tostr());
	if (me->x == NULL) {
		me->m_0 = new Bind_is0;
		me->m_0->parent = me;
		Init_Bind_is0(me->m_0);
	}
	me->x = x;
	return ((me->m_0)->eval(me->parent->x))->eval(x);
}

ff Exec_Leaf_60                   (ff me_abs, ff x) {
	struct Leaf_60 * me = (struct Leaf_60 *)me_abs;
	printf ("Lam [%s] got [%s]\n", me->tostr(), x->tostr());
	if (me->x == NULL) {
		me->m_0 = new Bind_pred;
		me->m_0->parent = me;
		Init_Bind_pred(me->m_0);
	}
	me->x = x;
	return ((me->m_0)->eval(me->parent->parent->x))->eval(x);
}

ff Exec_Leaf_59                   (ff me_abs, ff x) {
	struct Leaf_59 * me = (struct Leaf_59 *)me_abs;
	printf ("Lam [%s] got [%s]\n", me->tostr(), x->tostr());
	if (me->x == NULL) {
		me->m_0 = new Bind_get0;
		me->m_0->parent = me;
		Init_Bind_get0(me->m_0);
		me->m_1 = new Leaf_60;
		me->m_1->parent = me;
		Init_Leaf_60(me->m_1);
	}
	me->x = x;
	return ((me->m_0)->eval((me->m_1)))->eval(x);
}

ff Exec_Bind_get0                 (ff me_abs, ff x) {
	struct Bind_get0 * me = (struct Bind_get0 *)me_abs;
	printf ("Lam [%s] got [%s]\n", me->tostr(), x->tostr());
	if (me->x == NULL) {
		me->m_0 = new Bind_if;
		me->m_0->parent = me;
		Init_Bind_if(me->m_0);
		me->m_1 = new Leaf_58;
		me->m_1->parent = me;
		Init_Leaf_58(me->m_1);
		me->m_3 = new Leaf_59;
		me->m_3->parent = me;
		Init_Leaf_59(me->m_3);
	}
	me->x = x;
	return ((me->m_0)->eval((me->m_1))->eval(me->x)->eval((me->m_3)));
}

ff Exec_Bind_assert               (ff me_abs, ff x) {
	struct Bind_assert * me = (struct Bind_assert *)me_abs;
	printf ("Lam [%s] got [%s]\n", me->tostr(), x->tostr());
	if (me->x == NULL) {
		me->m_1 = new Bind_print_true;
		me->m_1->parent = me;
		Init_Bind_print_true(me->m_1);
		me->m_2 = new Bind_print_false;
		me->m_2->parent = me;
		Init_Bind_print_false(me->m_2);
	}
	me->x = x;
	return (me->x->eval((me->m_1))->eval((me->m_2)));
}

ff Exec_Leaf_71                   (ff me_abs, ff x) {
	struct Leaf_71 * me = (struct Leaf_71 *)me_abs;
	printf ("Lam [%s] got [%s]\n", me->tostr(), x->tostr());
	if (me->x == NULL) {
		me->m_0 = new Bind_not;
		me->m_0->parent = me;
		Init_Bind_not(me->m_0);
		me->m_1 = new Bind_false;
		me->m_1->parent = me;
		Init_Bind_false(me->m_1);
	}
	me->x = x;
	return ((me->m_0)->eval((me->m_1)))->eval(x);
}

ff Exec_Leaf_70                   (ff me_abs, ff x) {
	struct Leaf_70 * me = (struct Leaf_70 *)me_abs;
	printf ("Lam [%s] got [%s]\n", me->tostr(), x->tostr());
	if (me->x == NULL) {
		me->m_0 = new Bind_not;
		me->m_0->parent = me;
		Init_Bind_not(me->m_0);
		me->m_1 = new Leaf_71;
		me->m_1->parent = me;
		Init_Leaf_71(me->m_1);
	}
	me->x = x;
	return ((me->m_0)->eval((me->m_1)))->eval(x);
}

ff Exec_Leaf_69                   (ff me_abs, ff x) {
	struct Leaf_69 * me = (struct Leaf_69 *)me_abs;
	printf ("Lam [%s] got [%s]\n", me->tostr(), x->tostr());
	if (me->x == NULL) {
		me->m_0 = new Bind_not;
		me->m_0->parent = me;
		Init_Bind_not(me->m_0);
		me->m_1 = new Leaf_70;
		me->m_1->parent = me;
		Init_Leaf_70(me->m_1);
	}
	me->x = x;
	return ((me->m_0)->eval((me->m_1)))->eval(x);
}

ff Exec_Leaf_68                   (ff me_abs, ff x) {
	struct Leaf_68 * me = (struct Leaf_68 *)me_abs;
	printf ("Lam [%s] got [%s]\n", me->tostr(), x->tostr());
	if (me->x == NULL) {
		me->m_0 = new Bind_if;
		me->m_0->parent = me;
		Init_Bind_if(me->m_0);
		me->m_1 = new Bind_true;
		me->m_1->parent = me;
		Init_Bind_true(me->m_1);
		me->m_2 = new Bind_false;
		me->m_2->parent = me;
		Init_Bind_false(me->m_2);
		me->m_3 = new Leaf_69;
		me->m_3->parent = me;
		Init_Leaf_69(me->m_3);
	}
	me->x = x;
	return ((me->m_0)->eval((me->m_1))->eval((me->m_2))->eval((me->m_3)))->eval(x);
}

ff Exec_EXPR_0                    (ff me_abs, ff x) {
	struct EXPR_0 * me = (struct EXPR_0 *)me_abs;
	printf ("Lam [%s] got [%s]\n", me->tostr(), x->tostr());
	if (me->x == NULL) {
		me->m_0 = new Bind_assert;
		me->m_0->parent = me;
		Init_Bind_assert(me->m_0);
		me->m_1 = new Leaf_68;
		me->m_1->parent = me;
		Init_Leaf_68(me->m_1);
	}
	me->x = x;
	return ((me->m_0)->eval((me->m_1)))->eval(x);
}



int main() {
	puts("start");
	struct EXPR_0 * EXPR_0_var = new EXPR_0;
	Init_EXPR_0(EXPR_0_var);
	EXPR_0_var->eval(bind_err);

	puts("end");
	return 0; 
}

