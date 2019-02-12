const int Typeid_BindPriv_add_0 = __COUNTER__;
const int Typeid_Bind_add = __COUNTER__ ;
const int Typeid_Bind_bnot = __COUNTER__ ;
const int Typeid_Bind_booly = __COUNTER__ ;
const int Typeid_Bind_ec = __COUNTER__ ;
const int Typeid_Bind_error = __COUNTER__ ;
const int Typeid_Bind_facc = __COUNTER__ ;
const int Typeid_BindPriv_mif_0 = __COUNTER__;
const int Typeid_BindPriv_mif_1 = __COUNTER__;
const int Typeid_Bind_mif = __COUNTER__ ;
const int Typeid_Bind_print_false = __COUNTER__ ;
const int Typeid_Bind_print_true = __COUNTER__ ;

struct BindPriv_add_0;
struct Bind_add;
struct Bind_bnot;
struct Bind_booly;
struct Bind_ec;
struct Bind_error;
struct Bind_facc;
struct BindPriv_mif_0;
struct BindPriv_mif_1;
struct Bind_mif;
struct Bind_print_false;
struct Bind_print_true;

int Init_BindPriv_add_0 (struct BindPriv_add_0 *me);
int Init_Bind_add (struct Bind_add *me);
int Init_Bind_bnot (struct Bind_bnot *me);
int Init_Bind_booly (struct Bind_booly *me);
int Init_Bind_ec (struct Bind_ec *me);
int Init_Bind_error (struct Bind_error *me);
int Init_Bind_facc (struct Bind_facc *me);
int Init_BindPriv_mif_0 (struct BindPriv_mif_0 *me);
int Init_BindPriv_mif_1 (struct BindPriv_mif_1 *me);
int Init_Bind_mif (struct Bind_mif *me);
int Init_Bind_print_false (struct Bind_print_false *me);
int Init_Bind_print_true (struct Bind_print_true *me);

ff Exec_BindPriv_add_0 (ff me_abs, ff __x);
ff Exec_Bind_add (ff me_abs, ff __x);
ff Exec_Bind_bnot (ff me_abs, ff __x);
ff Exec_Bind_booly (ff me_abs, ff __x);
ff Exec_Bind_ec (ff me_abs, ff __x);
ff Exec_Bind_error (ff me_abs, ff __x);
ff Exec_Bind_facc (ff me_abs, ff __x);
ff Exec_BindPriv_mif_0 (ff me_abs, ff __x);
ff Exec_BindPriv_mif_1 (ff me_abs, ff __x);
ff Exec_Bind_mif (ff me_abs, ff __x);
ff Exec_Bind_print_false (ff me_abs, ff __x);
ff Exec_Bind_print_true (ff me_abs, ff __x);

#ifdef DO_CACHING
bool Cache_BindPriv_add_0 (ff me_abs, mapkey_t * ret, recursion_set * set);
bool Cache_Bind_add (ff me_abs, mapkey_t * ret, recursion_set * set);
bool Cache_Bind_bnot (ff me_abs, mapkey_t * ret, recursion_set * set);
bool Cache_Bind_booly (ff me_abs, mapkey_t * ret, recursion_set * set);
bool Cache_Bind_ec (ff me_abs, mapkey_t * ret, recursion_set * set);
bool Cache_Bind_error (ff me_abs, mapkey_t * ret, recursion_set * set);
bool Cache_Bind_facc (ff me_abs, mapkey_t * ret, recursion_set * set);
bool Cache_BindPriv_mif_0 (ff me_abs, mapkey_t * ret, recursion_set * set);
bool Cache_BindPriv_mif_1 (ff me_abs, mapkey_t * ret, recursion_set * set);
bool Cache_Bind_mif (ff me_abs, mapkey_t * ret, recursion_set * set);
bool Cache_Bind_print_false (ff me_abs, mapkey_t * ret, recursion_set * set);
bool Cache_Bind_print_true (ff me_abs, mapkey_t * ret, recursion_set * set);
#endif
