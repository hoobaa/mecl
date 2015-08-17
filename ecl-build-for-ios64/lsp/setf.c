/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:LSP;SETF.LSP                                      */
#include <ecl/ecl-cmp.h>
#include "lsp/setf.eclh"
/*	function definition for CHECK-STORES-NUMBER                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1check_stores_number(cl_object v1context, cl_object v2stores_list, cl_object v3n)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v4;
   v4 = ecl_length(v2stores_list);
   if (ecl_number_equalp(ecl_make_fixnum(v4),v3n)) { goto L1; }
  }
  value0 = cl_error(3, _ecl_static_1, v3n, v1context);
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for DO-SETF-METHOD-EXPANSION              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2do_setf_method_expansion(cl_object v1name, cl_object v2lambda, cl_object v3args)
{
 cl_object T0, T1, T2, T3, T4, T5;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4vars;
   cl_object v5inits;
   cl_object v6all;
   v4vars = ECL_NIL;
   v5inits = ECL_NIL;
   v6all = ECL_NIL;
   {
    cl_object v7;
    v7 = v3args;
    goto L8;
L7:;
    {
     cl_object v8item;
     v8item = ecl_car(v7);
     if (ECL_FIXNUMP(v8item)) { goto L12; }
     if ((cl_keywordp(v8item))!=ECL_NIL) { goto L12; }
     v5inits = CONS(v8item,v5inits);
     v8item = cl_gensym(0);
     v4vars = CONS(v8item,v4vars);
L12:;
     v6all = CONS(v8item,v6all);
    }
    v7 = ecl_cdr(v7);
L8:;
    if (Null(v7)) { goto L24; }
    goto L7;
L24:;
   }
   {
    cl_object v7store;
    cl_object v8all;
    v7store = cl_gensym(0);
    v8all = cl_nreverse(v6all);
    T0 = cl_nreverse(v4vars);
    T1 = cl_nreverse(v5inits);
    T2 = ecl_list1(v7store);
    if (Null(v2lambda)) { goto L29; }
    T3 = cl_apply(3, v2lambda, v7store, v8all);
    goto L28;
L29:;
    T4 = cl_list(2, ECL_SYM("SETF",750), v1name);
    T5 = cl_list(2, ECL_SYM("FUNCTION",396), T4);
    T3 = cl_listX(4, ECL_SYM("FUNCALL",394), T5, v7store, v8all);
L28:;
    T4 = CONS(v1name,v8all);
    cl_env_copy->nvalues = 5;
    cl_env_copy->values[4] = T4;
    cl_env_copy->values[3] = T3;
    cl_env_copy->values[2] = T2;
    cl_env_copy->values[1] = T1;
    cl_env_copy->values[0] = T0;
    return cl_env_copy->values[0];
   }
  }
 }
}
/*	function definition for SETF-METHOD-WRAPPER                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4setf_method_wrapper(cl_object v1name, cl_object v2setf_lambda)
{
 cl_object env0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1name,env0);                /*  NAME            */
  CLV1 = env0 = CONS(v2setf_lambda,env0);         /*  SETF-LAMBDA     */
  {cl_object v3;
   v3 = ECL_NIL;
   v3 = ecl_make_cclosure_va((cl_objectfn)LC3__g6,env0,Cblock);
   value0 = v3;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	closure G6                                                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC3__g6(cl_narg narg, cl_object v1env, ...)
{
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  SETF-LAMBDA     */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2args;
  ecl_va_list args; ecl_va_start(args,v1env,narg,1);
  v2args = cl_grab_rest_args(args);
  ecl_va_end(args);
  value0 = L2do_setf_method_expansion(ECL_CONS_CAR(CLV0), ECL_CONS_CAR(CLV1), v2args);
  return value0;
 }
 }
}
/*	function definition for DO-DEFSETF                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_do_defsetf(cl_object v1access_fn, cl_object v2function)
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v2function,env0);            /*  FUNCTION        */
  if (!(ECL_SYMBOLP(ECL_CONS_CAR(CLV0)))) { goto L1; }
  {cl_object v3;
   v3 = ECL_NIL;
   v3 = ecl_make_cclosure_va((cl_objectfn)LC5__g7,env0,Cblock);
   T0 = v3;
  }
  value0 = si_do_defsetf(v1access_fn, T0);
  return value0;
L1:;
  T0 = L4setf_method_wrapper(v1access_fn, ECL_CONS_CAR(CLV0));
  value0 = si_do_define_setf_method(v1access_fn, T0);
  return value0;
 }
}
/*	closure G7                                                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC5__g7(cl_narg narg, cl_object v1store, ...)
{
 cl_object T0, T1;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  FUNCTION        */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2args;
  ecl_va_list args; ecl_va_start(args,v1store,narg,1);
  v2args = cl_grab_rest_args(args);
  ecl_va_end(args);
  T0 = ecl_list1(v1store);
  T1 = ecl_append(v2args,T0);
  value0 = CONS(ECL_CONS_CAR(CLV0),T1);
  cl_env_copy->nvalues = 1;
  return value0;
 }
 }
}
/*	function definition for DO-DEFINE-SETF-METHOD                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_do_define_setf_method(cl_object v1access_fn, cl_object v2function)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = si_put_sysprop(v1access_fn, ECL_SYM("SETF-METHOD",1141), v2function);
  return value0;
 }
}
/*	local function DEFSETF                                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC6defsetf(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4access_fn;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4access_fn = v5;
   }
   {
    cl_object v5function;
    cl_object v6documentation;
    v5function = ECL_NIL;
    v6documentation = ECL_NIL;
    if (Null(ecl_car(v3))) { goto L11; }
    T0 = ecl_car(v3);
    if (ECL_SYMBOLP(T0)) { goto L14; }
    T0 = ecl_car(v3);
    if (Null(cl_functionp(T0))) { goto L11; }
    goto L12;
L14:;
L12:;
    T0 = ecl_car(v3);
    v5function = cl_list(2, ECL_SYM("QUOTE",679), T0);
    v6documentation = ecl_cadr(v3);
    goto L10;
L11:;
    {
     cl_object v7store;
     cl_object v8args;
     cl_object v9body;
     v7store = ecl_cadr(v3);
     v8args = ecl_car(v3);
     v9body = ecl_cddr(v3);
     v6documentation = si_find_documentation(1, v9body);
     T0 = ecl_append(v7store,v8args);
     T1 = cl_listX(4, ECL_SYM("LAMBDA-BLOCK",1339), v4access_fn, T0, v9body);
     v5function = cl_list(2, ECL_SYM("FUNCTION",396), T1);
     L1check_stores_number(ECL_SYM("DEFSETF",286), v7store, ecl_make_fixnum(1));
    }
L10:;
    if (Null(ecl_symbol_value(ECL_SYM("*REGISTER-WITH-PDE-HOOK*",1181)))) { goto L27; }
    T1 = cl_copy_tree(ecl_symbol_value(ECL_SYM("*SOURCE-LOCATION*",1180)));
    T2 = cl_list(2, ECL_SYM("QUOTE",679), v4access_fn);
    T3 = cl_list(3, ECL_SYM("DO-DEFSETF",1933), T2, v5function);
    T0 = ecl_function_dispatch(cl_env_copy,ecl_symbol_value(ECL_SYM("*REGISTER-WITH-PDE-HOOK*",1181)))(3, T1, v1, T3);
    goto L26;
L27:;
    T1 = cl_list(2, ECL_SYM("QUOTE",679), v4access_fn);
    T0 = cl_list(3, ECL_SYM("DO-DEFSETF",1933), T1, v5function);
L26:;
    T1 = si_expand_set_documentation(3, v4access_fn, ECL_SYM("SETF",750), v6documentation);
    T2 = cl_list(2, ECL_SYM("QUOTE",679), v4access_fn);
    T3 = ecl_list1(T2);
    T4 = ecl_append(T1,T3);
    value0 = cl_listX(4, ECL_SYM("EVAL-WHEN",340), VV[0], T0, T4);
    return value0;
   }
  }
 }
}
/*	local function DEFINE-SETF-EXPANDER                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC7define_setf_expander(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4access_fn;
   cl_object v5args;
   cl_object v6body;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v7;
    v7 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4access_fn = v7;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v7;
    v7 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5args = v7;
   }
   v6body = v3;
   {
    cl_object v7env;
    v7env = si_memq(ECL_SYM("&ENVIRONMENT",9),v5args);
    if (Null(v7env)) { goto L17; }
    T0 = ecl_cadr(v7env);
    T1 = cl_ldiff(v5args, v7env);
    T2 = ecl_cddr(v7env);
    T3 = ecl_nconc(T1,T2);
    v5args = CONS(T0,T3);
    goto L15;
L17:;
    v7env = cl_gensym(0);
    v5args = CONS(v7env,v5args);
    T0 = cl_list(2, ECL_SYM("IGNORE",428), v7env);
    T1 = cl_list(2, ECL_SYM("DECLARE",274), T0);
    v6body = CONS(T1,v6body);
   }
L15:;
   T0 = cl_list(2, ECL_SYM("QUOTE",679), v4access_fn);
   T1 = cl_listX(4, ECL_SYM("LAMBDA-BLOCK",1339), v4access_fn, v5args, v6body);
   T2 = cl_list(2, ECL_SYM("FUNCTION",396), T1);
   T3 = cl_list(3, ECL_SYM("DO-DEFINE-SETF-METHOD",1934), T0, T2);
   T4 = si_find_documentation(1, v6body);
   T5 = si_expand_set_documentation(3, v4access_fn, ECL_SYM("SETF",750), T4);
   T6 = cl_list(2, ECL_SYM("QUOTE",679), v4access_fn);
   T7 = ecl_list1(T6);
   T8 = ecl_append(T5,T7);
   value0 = cl_listX(4, ECL_SYM("EVAL-WHEN",340), VV[0], T3, T8);
   return value0;
  }
 }
}
/*	function definition for GET-SETF-EXPANSION                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8get_setf_expansion(cl_narg narg, cl_object v1form, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2env;
  va_list args; va_start(args,v1form);
  {
   int i = 1;
   if (i >= narg) {
    v2env = ECL_NIL;
   } else {
    i++;
    v2env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v3f;
   v3f = ECL_NIL;
   if (!(ECL_SYMBOLP(v1form))) { goto L3; }
   v3f = cl_macroexpand_1(2, v1form, v2env);
   if (Null(v3f)) { goto L5; }
   if (ecl_equal(v3f,v1form)) { goto L5; }
   value0 = L8get_setf_expansion(2, v3f, v2env);
   return value0;
L5:;
   {
    cl_object v4store;
    v4store = cl_gensym(0);
    T0 = ecl_list1(v4store);
    T1 = cl_list(3, ECL_SYM("SETQ",751), v1form, v4store);
    cl_env_copy->nvalues = 5;
    cl_env_copy->values[4] = v1form;
    cl_env_copy->values[3] = T1;
    cl_env_copy->values[2] = T0;
    cl_env_copy->values[1] = ECL_NIL;
    cl_env_copy->values[0] = ECL_NIL;
    return cl_env_copy->values[0];
   }
L3:;
   if (!(ECL_CONSP(v1form))) { goto L12; }
   T0 = ecl_car(v1form);
   if (ECL_SYMBOLP(T0)) { goto L10; }
   goto L11;
L12:;
L11:;
   value0 = cl_error(2, _ecl_static_2, v1form);
   return value0;
L10:;
   T0 = ecl_car(v1form);
   v3f = si_get_sysprop(T0, ECL_SYM("SETF-METHOD",1141));
   if (Null(v3f)) { goto L14; }
   T0 = ecl_cdr(v1form);
   value0 = cl_apply(3, v3f, v2env, T0);
   return value0;
L14:;
   v3f = cl_macroexpand_1(2, v1form, v2env);
   if (Null(v3f)) { goto L17; }
   if (ecl_equal(v3f,v1form)) { goto L17; }
   value0 = L8get_setf_expansion(2, v3f, v2env);
   return value0;
L17:;
   T0 = ecl_car(v1form);
   T1 = ecl_cdr(v1form);
   value0 = L2do_setf_method_expansion(T0, ECL_NIL, T1);
   return value0;
  }
 }
}
/*	local function CAR                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC9car(cl_object v1y, cl_object v2x)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(3, ECL_SYM("RPLACA",732), v2x, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T0, v1y);
  return value0;
 }
}
/*	local function CDR                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC10cdr(cl_object v1y, cl_object v2x)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(3, ECL_SYM("RPLACD",733), v2x, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T0, v1y);
  return value0;
 }
}
/*	local function CAAR                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC11caar(cl_object v1y, cl_object v2x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, ECL_SYM("CAR",180), v2x);
  T1 = cl_list(3, ECL_SYM("RPLACA",732), T0, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T1, v1y);
  return value0;
 }
}
/*	local function CDAR                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC12cdar(cl_object v1y, cl_object v2x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, ECL_SYM("CAR",180), v2x);
  T1 = cl_list(3, ECL_SYM("RPLACD",733), T0, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T1, v1y);
  return value0;
 }
}
/*	local function CADR                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC13cadr(cl_object v1y, cl_object v2x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, ECL_SYM("CDR",198), v2x);
  T1 = cl_list(3, ECL_SYM("RPLACA",732), T0, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T1, v1y);
  return value0;
 }
}
/*	local function CDDR                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC14cddr(cl_object v1y, cl_object v2x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, ECL_SYM("CDR",198), v2x);
  T1 = cl_list(3, ECL_SYM("RPLACD",733), T0, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T1, v1y);
  return value0;
 }
}
/*	local function CAAAR                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC15caaar(cl_object v1y, cl_object v2x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, ECL_SYM("CAAR",171), v2x);
  T1 = cl_list(3, ECL_SYM("RPLACA",732), T0, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T1, v1y);
  return value0;
 }
}
/*	local function CDAAR                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC16cdaar(cl_object v1y, cl_object v2x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, ECL_SYM("CAAR",171), v2x);
  T1 = cl_list(3, ECL_SYM("RPLACD",733), T0, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T1, v1y);
  return value0;
 }
}
/*	local function CADAR                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC17cadar(cl_object v1y, cl_object v2x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, ECL_SYM("CDAR",190), v2x);
  T1 = cl_list(3, ECL_SYM("RPLACA",732), T0, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T1, v1y);
  return value0;
 }
}
/*	local function CDDAR                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC18cddar(cl_object v1y, cl_object v2x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, ECL_SYM("CDAR",190), v2x);
  T1 = cl_list(3, ECL_SYM("RPLACD",733), T0, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T1, v1y);
  return value0;
 }
}
/*	local function CAADR                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC19caadr(cl_object v1y, cl_object v2x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, ECL_SYM("CADR",178), v2x);
  T1 = cl_list(3, ECL_SYM("RPLACA",732), T0, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T1, v1y);
  return value0;
 }
}
/*	local function CDADR                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC20cdadr(cl_object v1y, cl_object v2x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, ECL_SYM("CADR",178), v2x);
  T1 = cl_list(3, ECL_SYM("RPLACD",733), T0, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T1, v1y);
  return value0;
 }
}
/*	local function CADDR                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC21caddr(cl_object v1y, cl_object v2x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, ECL_SYM("CDDR",197), v2x);
  T1 = cl_list(3, ECL_SYM("RPLACA",732), T0, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T1, v1y);
  return value0;
 }
}
/*	local function CDDDR                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC22cdddr(cl_object v1y, cl_object v2x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, ECL_SYM("CDDR",197), v2x);
  T1 = cl_list(3, ECL_SYM("RPLACD",733), T0, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T1, v1y);
  return value0;
 }
}
/*	local function CAAAAR                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC23caaaar(cl_object v1y, cl_object v2x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, ECL_SYM("CAAAR",167), v2x);
  T1 = cl_list(3, ECL_SYM("RPLACA",732), T0, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T1, v1y);
  return value0;
 }
}
/*	local function CDAAAR                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC24cdaaar(cl_object v1y, cl_object v2x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, ECL_SYM("CAAAR",167), v2x);
  T1 = cl_list(3, ECL_SYM("RPLACD",733), T0, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T1, v1y);
  return value0;
 }
}
/*	local function CADAAR                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC25cadaar(cl_object v1y, cl_object v2x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, ECL_SYM("CDAAR",186), v2x);
  T1 = cl_list(3, ECL_SYM("RPLACA",732), T0, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T1, v1y);
  return value0;
 }
}
/*	local function CDDAAR                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC26cddaar(cl_object v1y, cl_object v2x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, ECL_SYM("CDAAR",186), v2x);
  T1 = cl_list(3, ECL_SYM("RPLACD",733), T0, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T1, v1y);
  return value0;
 }
}
/*	local function CAADAR                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC27caadar(cl_object v1y, cl_object v2x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, ECL_SYM("CADAR",174), v2x);
  T1 = cl_list(3, ECL_SYM("RPLACA",732), T0, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T1, v1y);
  return value0;
 }
}
/*	local function CDADAR                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC28cdadar(cl_object v1y, cl_object v2x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, ECL_SYM("CADAR",174), v2x);
  T1 = cl_list(3, ECL_SYM("RPLACD",733), T0, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T1, v1y);
  return value0;
 }
}
/*	local function CADDAR                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC29caddar(cl_object v1y, cl_object v2x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, ECL_SYM("CDDAR",193), v2x);
  T1 = cl_list(3, ECL_SYM("RPLACA",732), T0, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T1, v1y);
  return value0;
 }
}
/*	local function CDDDAR                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC30cdddar(cl_object v1y, cl_object v2x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, ECL_SYM("CDDAR",193), v2x);
  T1 = cl_list(3, ECL_SYM("RPLACD",733), T0, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T1, v1y);
  return value0;
 }
}
/*	local function CAAADR                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC31caaadr(cl_object v1y, cl_object v2x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, ECL_SYM("CAADR",170), v2x);
  T1 = cl_list(3, ECL_SYM("RPLACA",732), T0, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T1, v1y);
  return value0;
 }
}
/*	local function CDAADR                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC32cdaadr(cl_object v1y, cl_object v2x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, ECL_SYM("CAADR",170), v2x);
  T1 = cl_list(3, ECL_SYM("RPLACD",733), T0, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T1, v1y);
  return value0;
 }
}
/*	local function CADADR                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC33cadadr(cl_object v1y, cl_object v2x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, ECL_SYM("CDADR",189), v2x);
  T1 = cl_list(3, ECL_SYM("RPLACA",732), T0, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T1, v1y);
  return value0;
 }
}
/*	local function CDDADR                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC34cddadr(cl_object v1y, cl_object v2x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, ECL_SYM("CDADR",189), v2x);
  T1 = cl_list(3, ECL_SYM("RPLACD",733), T0, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T1, v1y);
  return value0;
 }
}
/*	local function CAADDR                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC35caaddr(cl_object v1y, cl_object v2x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, ECL_SYM("CADDR",177), v2x);
  T1 = cl_list(3, ECL_SYM("RPLACA",732), T0, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T1, v1y);
  return value0;
 }
}
/*	local function CDADDR                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC36cdaddr(cl_object v1y, cl_object v2x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, ECL_SYM("CADDR",177), v2x);
  T1 = cl_list(3, ECL_SYM("RPLACD",733), T0, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T1, v1y);
  return value0;
 }
}
/*	local function CADDDR                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC37cadddr(cl_object v1y, cl_object v2x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, ECL_SYM("CDDDR",196), v2x);
  T1 = cl_list(3, ECL_SYM("RPLACA",732), T0, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T1, v1y);
  return value0;
 }
}
/*	local function CDDDDR                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC38cddddr(cl_object v1y, cl_object v2x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, ECL_SYM("CDDDR",196), v2x);
  T1 = cl_list(3, ECL_SYM("RPLACD",733), T0, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T1, v1y);
  return value0;
 }
}
/*	local function FIRST                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC39first(cl_object v1y, cl_object v2x)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(3, ECL_SYM("RPLACA",732), v2x, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T0, v1y);
  return value0;
 }
}
/*	local function SECOND                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC40second(cl_object v1y, cl_object v2x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, ECL_SYM("CDR",198), v2x);
  T1 = cl_list(3, ECL_SYM("RPLACA",732), T0, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T1, v1y);
  return value0;
 }
}
/*	local function THIRD                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC41third(cl_object v1y, cl_object v2x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, ECL_SYM("CDDR",197), v2x);
  T1 = cl_list(3, ECL_SYM("RPLACA",732), T0, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T1, v1y);
  return value0;
 }
}
/*	local function FOURTH                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC42fourth(cl_object v1y, cl_object v2x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, ECL_SYM("CDDDR",196), v2x);
  T1 = cl_list(3, ECL_SYM("RPLACA",732), T0, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T1, v1y);
  return value0;
 }
}
/*	local function FIFTH                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC43fifth(cl_object v1y, cl_object v2x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, ECL_SYM("CDDDDR",195), v2x);
  T1 = cl_list(3, ECL_SYM("RPLACA",732), T0, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T1, v1y);
  return value0;
 }
}
/*	local function SIXTH                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC44sixth(cl_object v1y, cl_object v2x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(3, ECL_SYM("NTHCDR",604), ecl_make_fixnum(5), v2x);
  T1 = cl_list(3, ECL_SYM("RPLACA",732), T0, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T1, v1y);
  return value0;
 }
}
/*	local function SEVENTH                                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC45seventh(cl_object v1y, cl_object v2x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(3, ECL_SYM("NTHCDR",604), ecl_make_fixnum(6), v2x);
  T1 = cl_list(3, ECL_SYM("RPLACA",732), T0, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T1, v1y);
  return value0;
 }
}
/*	local function EIGHTH                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC46eighth(cl_object v1y, cl_object v2x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(3, ECL_SYM("NTHCDR",604), ecl_make_fixnum(7), v2x);
  T1 = cl_list(3, ECL_SYM("RPLACA",732), T0, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T1, v1y);
  return value0;
 }
}
/*	local function NINTH                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC47ninth(cl_object v1y, cl_object v2x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(3, ECL_SYM("NTHCDR",604), ecl_make_fixnum(8), v2x);
  T1 = cl_list(3, ECL_SYM("RPLACA",732), T0, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T1, v1y);
  return value0;
 }
}
/*	local function TENTH                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC48tenth(cl_object v1y, cl_object v2x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(3, ECL_SYM("NTHCDR",604), ecl_make_fixnum(9), v2x);
  T1 = cl_list(3, ECL_SYM("RPLACA",732), T0, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T1, v1y);
  return value0;
 }
}
/*	local function REST                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC49rest(cl_object v1y, cl_object v2x)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(3, ECL_SYM("RPLACD",733), v2x, v1y);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T0, v1y);
  return value0;
 }
}
/*	local function MACRO-FUNCTION                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC50macro_function(cl_narg narg, cl_object v1v, cl_object v2s, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v3env;
  va_list args; va_start(args,v2s);
  {
   int i = 2;
   if (i >= narg) {
    v3env = ECL_NIL;
   } else {
    i++;
    v3env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = cl_list(4, ECL_SYM("FSET",1080), v2s, v1v, ECL_T);
  return value0;
 }
}
/*	local function GET                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC51get(cl_narg narg, cl_object v1v, cl_object v2s, cl_object v3p, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>4)) FEwrong_num_arguments_anonym();
 {
  cl_object v4d;
  va_list args; va_start(args,v3p);
  {
   int i = 3;
   if (i >= narg) {
    v4d = ECL_NIL;
   } else {
    i++;
    v4d = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (Null(v4d)) { goto L2; }
  T0 = cl_list(4, ECL_SYM("PUTPROP",1125), v2s, v1v, v3p);
  value0 = cl_list(3, ECL_SYM("PROGN",671), v4d, T0);
  return value0;
L2:;
  value0 = cl_list(4, ECL_SYM("PUTPROP",1125), v2s, v1v, v3p);
  return value0;
 }
}
/*	local function NTH                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC52nth(cl_object v1v, cl_object v2n, cl_object v3l)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(3, ECL_SYM("NTHCDR",604), v2n, v3l);
  T1 = cl_list(3, ECL_SYM("RPLACA",732), T0, v1v);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T1, v1v);
  return value0;
 }
}
/*	local function GETHASH                                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC53gethash(cl_narg narg, cl_object v1v, cl_object v2k, cl_object v3h, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>4)) FEwrong_num_arguments_anonym();
 {
  cl_object v4d;
  va_list args; va_start(args,v3h);
  {
   int i = 3;
   if (i >= narg) {
    v4d = ECL_NIL;
   } else {
    i++;
    v4d = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = cl_list(4, ECL_SYM("HASH-SET",1088), v2k, v3h, v1v);
  return value0;
 }
}
/*	local function COMPILER-MACRO-FUNCTION                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC54compiler_macro_function(cl_object v1function, cl_object v2fname)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_list(4, ECL_SYM("PUT-SYSPROP",1124), v2fname, VV[4], v1function);
  return value0;
 }
}
/*	local function GETF                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC55getf(cl_narg narg, cl_object v1env, cl_object v2place, cl_object v3indicator, ...)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>4)) FEwrong_num_arguments_anonym();
 {
  cl_object v4default;
  cl_object v5default_p;
  va_list args; va_start(args,v3indicator);
  {
   int i = 3;
   if (i >= narg) {
    v4default = ECL_NIL;
    v5default_p = ECL_NIL;
   } else {
    i++;
    v4default = va_arg(args,cl_object);
    v5default_p = ECL_T;
   }
  }
  va_end(args);
  {
   cl_object v7;                                  /*  VARS            */
   cl_object v8;                                  /*  VALS            */
   cl_object v9;                                  /*  STORES          */
   cl_object v10;                                 /*  STORE-FORM      */
   cl_object v11;                                 /*  ACCESS-FORM     */
   value0 = L8get_setf_expansion(2, v2place, v1env);
   v7 = value0;
   v8 = cl_env_copy->values[1];
   v9 = cl_env_copy->values[2];
   v10 = cl_env_copy->values[3];
   v11 = cl_env_copy->values[4];
   {
    cl_object v12itemp;
    cl_object v13store;
    cl_object v14def;
    v12itemp = cl_gensym(0);
    v13store = cl_gensym(0);
    v14def = cl_gensym(0);
    if (Null(v5default_p)) { goto L7; }
    T0 = ecl_list1(v14def);
    goto L6;
L7:;
    T0 = ECL_NIL;
L6:;
    T1 = CONS(v12itemp,T0);
    T2 = ecl_append(v7,T1);
    if (Null(v5default_p)) { goto L11; }
    T3 = ecl_list1(v4default);
    goto L9;
L11:;
    T3 = ECL_NIL;
    goto L9;
L9:;
    T4 = CONS(v3indicator,T3);
    T5 = ecl_append(v8,T4);
    T6 = ecl_list1(v13store);
    T7 = ecl_car(v9);
    T8 = cl_list(4, ECL_SYM("PUT-F",1122), v11, v13store, v12itemp);
    T9 = cl_list(2, T7, T8);
    T10 = ecl_list1(T9);
    T11 = cl_list(4, ECL_SYM("LET",477), T10, v10, v13store);
    T12 = cl_list(4, ECL_SYM("GETF",412), v11, v12itemp, v4default);
    cl_env_copy->nvalues = 5;
    cl_env_copy->values[4] = T12;
    cl_env_copy->values[3] = T11;
    cl_env_copy->values[2] = T6;
    cl_env_copy->values[1] = T5;
    cl_env_copy->values[0] = T2;
    return cl_env_copy->values[0];
   }
  }
 }
}
/*	local function SUBSEQ                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC56subseq(cl_narg narg, cl_object v1sequence2, cl_object v2sequence1, cl_object v3start1, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>4)) FEwrong_num_arguments_anonym();
 {
  cl_object v4end1;
  va_list args; va_start(args,v3start1);
  {
   int i = 3;
   if (i >= narg) {
    v4end1 = ECL_NIL;
   } else {
    i++;
    v4end1 = va_arg(args,cl_object);
   }
  }
  va_end(args);
  T0 = cl_list(7, ECL_SYM("REPLACE",717), v2sequence1, v1sequence2, ECL_SYM("START1",1311), v3start1, ECL_SYM("END1",1226), v4end1);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T0, v1sequence2);
  return value0;
 }
}
/*	local function THE                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC57the(cl_object v1env, cl_object v2type, cl_object v3place)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v5;                                  /*  VARS            */
   cl_object v6;                                  /*  VALS            */
   cl_object v7;                                  /*  STORES          */
   cl_object v8;                                  /*  STORE-FORM      */
   cl_object v9;                                  /*  ACCESS-FORM     */
   value0 = L8get_setf_expansion(2, v3place, v1env);
   v5 = value0;
   v6 = cl_env_copy->values[1];
   v7 = cl_env_copy->values[2];
   v8 = cl_env_copy->values[3];
   v9 = cl_env_copy->values[4];
   T0 = ecl_car(v7);
   T1 = cl_list(3, ECL_SYM("THE",856), v2type, T0);
   T2 = ecl_car(v7);
   T3 = cl_subst(3, T1, T2, v8);
   T4 = cl_list(3, ECL_SYM("THE",856), v2type, v9);
   cl_env_copy->nvalues = 5;
   cl_env_copy->values[4] = T4;
   cl_env_copy->values[3] = T3;
   cl_env_copy->values[2] = v7;
   cl_env_copy->values[1] = v6;
   cl_env_copy->values[0] = v5;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function APPLY                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC58apply(cl_narg narg, cl_object v1env, cl_object v2fn, ...)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3rest;
  ecl_va_list args; ecl_va_start(args,v2fn,narg,2);
  v3rest = cl_grab_rest_args(args);
  ecl_va_end(args);
  if (!(ECL_CONSP(v2fn))) { goto L4; }
  T0 = ecl_car(v2fn);
  if ((T0)==(ECL_SYM("FUNCTION",396))) { goto L7; }
  T0 = ecl_car(v2fn);
  if (!((T0)==(ECL_SYM("QUOTE",679)))) { goto L4; }
  goto L6;
L7:;
L6:;
  T0 = ecl_cadr(v2fn);
  if (!(ECL_SYMBOLP(T0))) { goto L4; }
  T0 = ecl_cddr(v2fn);
  if (T0==ECL_NIL) { goto L1; }
  goto L2;
L4:;
  goto L2;
L2:;
  cl_error(2, _ecl_static_3, v2fn);
L1:;
  {
   cl_object v5;                                  /*  VARS            */
   cl_object v6;                                  /*  VALS            */
   cl_object v7;                                  /*  STORES          */
   cl_object v8;                                  /*  STORE-FORM      */
   cl_object v9;                                  /*  ACCESS-FORM     */
   T0 = ecl_cadr(v2fn);
   T1 = CONS(T0,v3rest);
   value0 = L8get_setf_expansion(2, T1, v1env);
   v5 = value0;
   v6 = cl_env_copy->values[1];
   v7 = cl_env_copy->values[2];
   v8 = cl_env_copy->values[3];
   v9 = cl_env_copy->values[4];
   T0 = ecl_last(v8,1);
   T1 = ecl_car(T0);
   T2 = ecl_last(v5,1);
   T3 = ecl_car(T2);
   if (!((T1)==(T3))) { goto L11; }
   T0 = ecl_car(v8);
   T1 = cl_list(2, ECL_SYM("FUNCTION",396), T0);
   T2 = ecl_cdr(v8);
   T3 = cl_listX(3, ECL_SYM("APPLY",89), T1, T2);
   T4 = ecl_cadr(v2fn);
   T5 = cl_list(2, ECL_SYM("FUNCTION",396), T4);
   T6 = ecl_cdr(v9);
   T7 = cl_listX(3, ECL_SYM("APPLY",89), T5, T6);
   cl_env_copy->nvalues = 5;
   cl_env_copy->values[4] = T7;
   cl_env_copy->values[3] = T3;
   cl_env_copy->values[2] = v7;
   cl_env_copy->values[1] = v6;
   cl_env_copy->values[0] = v5;
   return cl_env_copy->values[0];
L11:;
   T0 = ecl_butlast(v8,1);
   T1 = ecl_last(T0,1);
   T2 = ecl_car(T1);
   T3 = ecl_last(v5,1);
   T4 = ecl_car(T3);
   if (!((T2)==(T4))) { goto L13; }
   T0 = ecl_car(v8);
   T1 = cl_list(2, ECL_SYM("FUNCTION",396), T0);
   T2 = cl_butlast(2, v8, ecl_make_fixnum(2));
   T3 = ecl_cdr(T2);
   T4 = ecl_butlast(v8,1);
   T5 = ecl_last(T4,1);
   T6 = ecl_car(T5);
   T7 = ecl_last(v8,1);
   T8 = ecl_car(T7);
   T9 = cl_list(2, ECL_SYM("LIST",481), T8);
   T10 = cl_list(3, ECL_SYM("APPEND",88), T6, T9);
   T11 = ecl_list1(T10);
   T12 = ecl_append(T3,T11);
   T13 = cl_listX(3, ECL_SYM("APPLY",89), T1, T12);
   T14 = ecl_cadr(v2fn);
   T15 = cl_list(2, ECL_SYM("FUNCTION",396), T14);
   T16 = ecl_cdr(v9);
   T17 = cl_listX(3, ECL_SYM("APPLY",89), T15, T16);
   cl_env_copy->nvalues = 5;
   cl_env_copy->values[4] = T17;
   cl_env_copy->values[3] = T13;
   cl_env_copy->values[2] = v7;
   cl_env_copy->values[1] = v6;
   cl_env_copy->values[0] = v5;
   return cl_env_copy->values[0];
L13:;
   value0 = cl_error(2, _ecl_static_3, v2fn);
   return value0;
  }
 }
}
/*	local function LDB                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC59ldb(cl_object v1env, cl_object v2bytespec, cl_object v3int)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v5;                                  /*  TEMPS           */
   cl_object v6;                                  /*  VALS            */
   cl_object v7;                                  /*  STORES          */
   cl_object v8;                                  /*  STORE-FORM      */
   cl_object v9;                                  /*  ACCESS-FORM     */
   value0 = L8get_setf_expansion(2, v3int, v1env);
   v5 = value0;
   v6 = cl_env_copy->values[1];
   v7 = cl_env_copy->values[2];
   v8 = cl_env_copy->values[3];
   v9 = cl_env_copy->values[4];
   {
    cl_object v10btemp;
    cl_object v11store;
    cl_object v12stemp;
    v10btemp = cl_gensym(0);
    v11store = cl_gensym(0);
    v12stemp = ecl_car(v7);
    T0 = CONS(v10btemp,v5);
    T1 = CONS(v2bytespec,v6);
    T2 = ecl_list1(v11store);
    T3 = cl_list(4, ECL_SYM("DPB",318), v11store, v10btemp, v9);
    T4 = cl_list(2, v12stemp, T3);
    T5 = ecl_list1(T4);
    T6 = cl_list(4, ECL_SYM("LET",477), T5, v8, v11store);
    T7 = cl_list(3, ECL_SYM("LDB",457), v10btemp, v9);
    cl_env_copy->nvalues = 5;
    cl_env_copy->values[4] = T7;
    cl_env_copy->values[3] = T6;
    cl_env_copy->values[2] = T2;
    cl_env_copy->values[1] = T1;
    cl_env_copy->values[0] = T0;
    return cl_env_copy->values[0];
   }
  }
 }
}
/*	local function MASK-FIELD                                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC60mask_field(cl_object v1env, cl_object v2bytespec, cl_object v3int)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v5;                                  /*  TEMPS           */
   cl_object v6;                                  /*  VALS            */
   cl_object v7;                                  /*  STORES          */
   cl_object v8;                                  /*  STORE-FORM      */
   cl_object v9;                                  /*  ACCESS-FORM     */
   value0 = L8get_setf_expansion(2, v3int, v1env);
   v5 = value0;
   v6 = cl_env_copy->values[1];
   v7 = cl_env_copy->values[2];
   v8 = cl_env_copy->values[3];
   v9 = cl_env_copy->values[4];
   {
    cl_object v10btemp;
    cl_object v11store;
    cl_object v12stemp;
    v10btemp = cl_gensym(0);
    v11store = cl_gensym(0);
    v12stemp = ecl_car(v7);
    T0 = CONS(v10btemp,v5);
    T1 = CONS(v2bytespec,v6);
    T2 = ecl_list1(v11store);
    T3 = cl_list(4, ECL_SYM("DEPOSIT-FIELD",298), v11store, v10btemp, v9);
    T4 = cl_list(2, v12stemp, T3);
    T5 = ecl_list1(T4);
    T6 = cl_list(4, ECL_SYM("LET",477), T5, v8, v11store);
    T7 = cl_list(3, ECL_SYM("MASK-FIELD",550), v10btemp, v9);
    cl_env_copy->nvalues = 5;
    cl_env_copy->values[4] = T7;
    cl_env_copy->values[3] = T6;
    cl_env_copy->values[2] = T2;
    cl_env_copy->values[1] = T1;
    cl_env_copy->values[0] = T0;
    return cl_env_copy->values[0];
   }
  }
 }
}
/*	function definition for TRIVIAL-SETF-FORM                     */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object L61trivial_setf_form(cl_object v1place, cl_object v2vars, cl_object v3stores, cl_object v4store_form, cl_object v5access_form)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 if (!(ECL_ATOM(v1place))) { goto L2; }
 if (!(v2vars==ECL_NIL)) { goto L2; }
 if (!((v5access_form)==(v1place))) { goto L2; }
 {
  cl_fixnum v6;
  v6 = ecl_length(v3stores);
  if (!((v6)==(1))) { goto L2; }
 }
 if (!(ECL_LISTP(v4store_form))) { goto L2; }
 {
  cl_fixnum v6;
  v6 = ecl_length(v4store_form);
  if (!((v6)==(3))) { goto L2; }
 }
 {
  cl_object v6;
  v6 = _ecl_car(v4store_form);
  if (!((v6)==(ECL_SYM("SETQ",751)))) { goto L14; }
  goto L11;
  goto L12;
L14:;
  goto L12;
L12:;
  if (!((v6)==(ECL_SYM("SETF",750)))) { goto L2; }
  goto L9;
L11:;
 }
L9:;
 T0 = _ecl_cadr(v4store_form);
 if (!((T0)==(v1place))) { goto L2; }
 T0 = _ecl_caddr(v4store_form);
 T1 = _ecl_car(v3stores);
 value0 = ecl_make_bool((T0)==(T1));
 cl_env_copy->nvalues = 1;
 return value0;
L2:;
 value0 = ECL_NIL;
 cl_env_copy->nvalues = 1;
 return value0;
}
/*	function definition for TRY-SIMPLER-EXPANSION                 */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object L62try_simpler_expansion(cl_object v1place, cl_object v2vars, cl_object v3vals, cl_object v4stores, cl_object v5newvalue, cl_object v6store_form)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 if (!(ECL_CONSP(v1place))) { goto L1; }
 if (!(ECL_CONSP(v6store_form))) { goto L1; }
 {
  cl_fixnum v7;
  v7 = ecl_length(v1place);
  {
   cl_fixnum v8;
   v8 = ecl_length(v6store_form);
   {
    cl_fixnum v9;
    v9 = (v8)-1;
    if (!((v7)==(v9))) { goto L1; }
   }
  }
 }
 {
  cl_object v7;
  cl_object v8output;
  cl_object v9v;
  {
   cl_object v10;
   v10 = v6store_form;
   if (Null(v10)) { goto L8; }
   {
    cl_object v11;
    v11 = ECL_CONS_CDR(v10);
    v6store_form = v11;
    v10 = ECL_CONS_CAR(v10);
   }
L8:;
   v7 = v10;
  }
  v8output = ECL_NIL;
  v9v = ECL_NIL;
  {
   cl_object v10;
   v10 = _ecl_cdr(v1place);
   goto L19;
L18:;
   {
    cl_object v11i;
    v11i = _ecl_car(v10);
    if (ECL_CONSP(v6store_form)) { goto L23; }
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
L23:;
    v9v = ECL_CONS_CAR(v6store_form);
    v6store_form = ECL_CONS_CDR(v6store_form);
    if ((v9v)==(v11i)) { goto L29; }
    {
     cl_object v12;
     v12 = v2vars;
     if (Null(v12)) { goto L38; }
     {
      cl_object v13;
      v13 = ECL_CONS_CDR(v12);
      v2vars = v13;
      v12 = ECL_CONS_CAR(v12);
     }
L38:;
     T0 = v12;
    }
    if (!((v9v)==(T0))) { goto L33; }
    {
     cl_object v12;
     v12 = v3vals;
     if (Null(v12)) { goto L47; }
     {
      cl_object v13;
      v13 = ECL_CONS_CDR(v12);
      v3vals = v13;
      v12 = ECL_CONS_CAR(v12);
     }
L47:;
     T0 = v12;
    }
    if ((T0)==(v11i)) { goto L29; }
    goto L30;
L33:;
    goto L30;
L30:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
L29:;
    v8output = CONS(v11i,v8output);
   }
   v10 = _ecl_cdr(v10);
L19:;
   if (Null(v10)) { goto L57; }
   goto L18;
L57:;
   T0 = _ecl_car(v4stores);
   T1 = _ecl_car(v6store_form);
   if (!((T0)==(T1))) { goto L59; }
   T0 = CONS(v5newvalue,v8output);
   T1 = cl_nreverse(T0);
   value0 = CONS(v7,T1);
   cl_env_copy->nvalues = 1;
   return value0;
L59:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
L1:;
 value0 = ECL_NIL;
 cl_env_copy->nvalues = 1;
 return value0;
}
/*	function definition for SETF-EXPAND-1                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L63setf_expand_1(cl_object v1place, cl_object v2newvalue, cl_object v3env)
{
 cl_object T0, T1, T2, T3, T4, T5, T6;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v5;                                  /*  VARS            */
   cl_object v6;                                  /*  VALS            */
   cl_object v7;                                  /*  STORES          */
   cl_object v8;                                  /*  STORE-FORM      */
   cl_object v9;                                  /*  ACCESS-FORM     */
   value0 = L8get_setf_expansion(2, v1place, v3env);
   v5 = value0;
   v6 = cl_env_copy->values[1];
   v7 = cl_env_copy->values[2];
   v8 = cl_env_copy->values[3];
   v9 = cl_env_copy->values[4];
   if (Null(L61trivial_setf_form(v1place, v5, v7, v8, v9))) { goto L2; }
   value0 = cl_list(3, ECL_SYM("SETQ",751), v1place, v2newvalue);
   return value0;
L2:;
   {
    cl_object v10;
    v10 = L62try_simpler_expansion(v1place, v5, v6, v7, v2newvalue, v8);
    if (Null(v10)) { goto L5; }
    value0 = v10;
    cl_env_copy->nvalues = 1;
    return value0;
L5:;
    T0 = (ECL_SYM("LIST",481)->symbol.gfdef);
    T1 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(3, T0, v5, v6) /*  MAPCAR */;
    T2 = CONS(VV[7],v5);
    T3 = cl_list(2, ECL_SYM("DECLARE",274), T2);
    T4 = CONS(VV[7],v7);
    T5 = cl_list(2, ECL_SYM("DECLARE",274), T4);
    T6 = cl_list(5, ECL_SYM("MULTIPLE-VALUE-BIND",572), v7, v2newvalue, T5, v8);
    value0 = cl_list(4, ECL_SYM("LET*",478), T1, T3, T6);
    return value0;
   }
  }
 }
}
/*	function definition for SETF-EXPAND                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L64setf_expand(cl_object v1l, cl_object v2env)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ecl_endp(v1l))) { goto L1; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  T0 = ecl_cdr(v1l);
  if (!(ecl_endp(T0))) { goto L3; }
  value0 = cl_error(2, _ecl_static_4, v1l);
  return value0;
L3:;
  T0 = ecl_car(v1l);
  T1 = ecl_cadr(v1l);
  T2 = L63setf_expand_1(T0, T1, v2env);
  T3 = ecl_cddr(v1l);
  T4 = L64setf_expand(T3, v2env);
  value0 = CONS(T2,T4);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function SETF                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC65setf(cl_object v1, cl_object v2env)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_cdr(v1);
   if (!(ecl_endp(v3))) { goto L2; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
   T0 = ecl_cdr(v3);
   if (!(ecl_endp(T0))) { goto L4; }
   value0 = cl_error(2, _ecl_static_4, v3);
   return value0;
L4:;
   T0 = ecl_cddr(v3);
   if (!(ecl_endp(T0))) { goto L6; }
   T0 = ecl_car(v3);
   T1 = ecl_cadr(v3);
   value0 = L63setf_expand_1(T0, T1, v2env);
   return value0;
L6:;
   T0 = L64setf_expand(v3, v2env);
   value0 = CONS(ECL_SYM("PROGN",671),T0);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function PSETF                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC66psetf(cl_object v1, cl_object v2env)
{
 cl_object T0, T1, T2, T3, T4, T5;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_cdr(v1);
   if (!(ecl_endp(v3))) { goto L2; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
   T0 = ecl_cdr(v3);
   if (!(ecl_endp(T0))) { goto L4; }
   value0 = cl_error(2, _ecl_static_5, v3);
   return value0;
L4:;
   T0 = ecl_cddr(v3);
   if (!(ecl_endp(T0))) { goto L6; }
   T0 = ecl_car(v3);
   T1 = ecl_cadr(v3);
   T2 = L63setf_expand_1(T0, T1, v2env);
   value0 = cl_list(3, ECL_SYM("PROGN",671), T2, ECL_NIL);
   return value0;
L6:;
   {
    cl_object v4r;
    cl_object v5pairs;
    cl_object v6store_forms;
    v4r = v3;
    v5pairs = ECL_NIL;
    v6store_forms = ECL_NIL;
    goto L13;
L12:;
    T0 = ecl_cdr(v4r);
    if (!(ecl_endp(T0))) { goto L15; }
    cl_error(2, _ecl_static_5, v3);
L15:;
    {
     cl_object v8;                                /*  VARS            */
     cl_object v9;                                /*  VALS            */
     cl_object v10;                               /*  STORES          */
     cl_object v11;                               /*  STORE-FORM      */
     cl_object v12;                               /*  ACCESS-FORM     */
     T0 = ecl_car(v4r);
     value0 = L8get_setf_expansion(2, T0, v2env);
     v8 = value0;
     v9 = cl_env_copy->values[1];
     v10 = cl_env_copy->values[2];
     v11 = cl_env_copy->values[3];
     v12 = cl_env_copy->values[4];
     v6store_forms = CONS(v11,v6store_forms);
     T0 = (ECL_SYM("LIST",481)->symbol.gfdef);
     T1 = ecl_append(v8,v10);
     T2 = ecl_cadr(v4r);
     T3 = ecl_list1(T2);
     T4 = ecl_append(v9,T3);
     T5 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(3, T0, T1, T4) /*  MAPCAR */;
     v5pairs = ecl_nconc(v5pairs,T5);
    }
    v4r = ecl_cddr(v4r);
L13:;
    if (ecl_endp(v4r)) { goto L25; }
    goto L12;
L25:;
    T0 = cl_nreverse(v6store_forms);
    T1 = ecl_append(T0,VV[9]);
    value0 = cl_listX(3, ECL_SYM("LET*",478), v5pairs, T1);
    return value0;
   }
  }
 }
}
/*	local function SHIFTF                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC67shiftf(cl_object v1, cl_object v2env)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_cdr(v1);
   {
    cl_object v4;
    cl_object v5r;
    cl_object v6pairs;
    cl_object v7stores;
    cl_object v8store_forms;
    cl_object v9access_forms;
    v4 = cl_gensym(0);
    v5r = v3;
    v6pairs = ECL_NIL;
    v7stores = ECL_NIL;
    v8store_forms = ECL_NIL;
    v9access_forms = ECL_NIL;
    goto L10;
L9:;
    {
     cl_object v11;                               /*  VARS            */
     cl_object v12;                               /*  VALS            */
     cl_object v13;                               /*  STORES1         */
     cl_object v14;                               /*  STORE-FORM      */
     cl_object v15;                               /*  ACCESS-FORM     */
     T0 = ecl_car(v5r);
     value0 = L8get_setf_expansion(2, T0, v2env);
     v11 = value0;
     v12 = cl_env_copy->values[1];
     v13 = cl_env_copy->values[2];
     v14 = cl_env_copy->values[3];
     v15 = cl_env_copy->values[4];
     T0 = (ECL_SYM("LIST",481)->symbol.gfdef);
     T1 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(3, T0, v11, v12) /*  MAPCAR */;
     v6pairs = ecl_nconc(v6pairs,T1);
     T0 = ecl_car(v13);
     v7stores = CONS(T0,v7stores);
     v8store_forms = CONS(v14,v8store_forms);
     v9access_forms = CONS(v15,v9access_forms);
    }
    v5r = ecl_cdr(v5r);
L10:;
    T0 = ecl_cdr(v5r);
    if (ecl_endp(T0)) { goto L24; }
    goto L9;
L24:;
    v7stores = cl_nreverse(v7stores);
    v8store_forms = cl_nreverse(v8store_forms);
    v9access_forms = cl_nreverse(v9access_forms);
    T0 = ecl_car(v9access_forms);
    T1 = cl_list(2, v4, T0);
    T2 = ecl_list1(T1);
    T3 = (ECL_SYM("LIST",481)->symbol.gfdef);
    T4 = ecl_cdr(v9access_forms);
    T5 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(3, T3, v7stores, T4) /*  MAPCAR */;
    T6 = ecl_last(v7stores,1);
    T7 = ecl_car(T6);
    T8 = ecl_car(v5r);
    T9 = cl_list(2, T7, T8);
    T10 = ecl_list1(T9);
    T11 = cl_nconc(4, v6pairs, T2, T5, T10);
    T12 = ecl_list1(v4);
    T13 = ecl_append(v8store_forms,T12);
    value0 = cl_listX(3, ECL_SYM("LET*",478), T11, T13);
    return value0;
   }
  }
 }
}
/*	local function ROTATEF                                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC68rotatef(cl_object v1, cl_object v2env)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_cdr(v1);
   {
    cl_object v4r;
    cl_object v5pairs;
    cl_object v6stores;
    cl_object v7store_forms;
    cl_object v8access_forms;
    v4r = v3;
    v5pairs = ECL_NIL;
    v6stores = ECL_NIL;
    v7store_forms = ECL_NIL;
    v8access_forms = ECL_NIL;
    goto L9;
L8:;
    {
     cl_object v10;                               /*  VARS            */
     cl_object v11;                               /*  VALS            */
     cl_object v12;                               /*  STORES1         */
     cl_object v13;                               /*  STORE-FORM      */
     cl_object v14;                               /*  ACCESS-FORM     */
     T0 = ecl_car(v4r);
     value0 = L8get_setf_expansion(2, T0, v2env);
     v10 = value0;
     v11 = cl_env_copy->values[1];
     v12 = cl_env_copy->values[2];
     v13 = cl_env_copy->values[3];
     v14 = cl_env_copy->values[4];
     T0 = (ECL_SYM("LIST",481)->symbol.gfdef);
     T1 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(3, T0, v10, v11) /*  MAPCAR */;
     v5pairs = ecl_nconc(v5pairs,T1);
     T0 = ecl_car(v12);
     v6stores = CONS(T0,v6stores);
     v7store_forms = CONS(v13,v7store_forms);
     v8access_forms = CONS(v14,v8access_forms);
    }
    v4r = ecl_cdr(v4r);
L9:;
    if (ecl_endp(v4r)) { goto L23; }
    goto L8;
L23:;
    v6stores = cl_nreverse(v6stores);
    v7store_forms = cl_nreverse(v7store_forms);
    v8access_forms = cl_nreverse(v8access_forms);
    T0 = (ECL_SYM("LIST",481)->symbol.gfdef);
    T1 = ecl_cdr(v8access_forms);
    T2 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(3, T0, v6stores, T1) /*  MAPCAR */;
    T3 = ecl_last(v6stores,1);
    T4 = ecl_car(T3);
    T5 = ecl_car(v8access_forms);
    T6 = cl_list(2, T4, T5);
    T7 = ecl_list1(T6);
    T8 = cl_nconc(3, v5pairs, T2, T7);
    T9 = ecl_append(v7store_forms,VV[9]);
    value0 = cl_listX(3, ECL_SYM("LET*",478), T8, T9);
    return value0;
   }
  }
 }
}
/*	local function DEFINE-MODIFY-MACRO                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC69define_modify_macro(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4name;
   cl_object v5lambdalist;
   cl_object v6function;
   cl_object v7docstring;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v8;
    v8 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4name = v8;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v8;
    v8 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5lambdalist = v8;
   }
   if (!(v3==ECL_NIL)) { goto L15; }
   si_dm_too_few_arguments(v1);
L15:;
   {
    cl_object v8;
    v8 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v6function = v8;
   }
   if (Null(v3)) { goto L21; }
   {
    cl_object v8;
    v8 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v7docstring = v8;
    goto L20;
   }
L21:;
   v7docstring = ECL_NIL;
L20:;
   if (Null(v3)) { goto L26; }
   si_dm_too_many_arguments(v1);
L26:;
   {
    cl_object v8varlist;
    cl_object v9restvar;
    v8varlist = ECL_NIL;
    v9restvar = ECL_NIL;
    {
     cl_object v10lambdalistr;
     cl_object v11next;
     v10lambdalistr = v5lambdalist;
     v11next = ECL_NIL;
     goto L35;
L34:;
     v11next = ecl_car(v10lambdalistr);
     {
      cl_object v12;
      v12 = ecl_make_bool((v11next)==(ECL_SYM("&OPTIONAL",11)));
      if (Null(v12)) { goto L41; }
      goto L39;
L41:;
      if (!((v11next)==(ECL_SYM("&REST",12)))) { goto L43; }
      T0 = ecl_cadr(v10lambdalistr);
      if (!(ECL_SYMBOLP(T0))) { goto L46; }
      v9restvar = ecl_cadr(v10lambdalistr);
      goto L45;
L46:;
      T0 = ecl_cadr(v10lambdalistr);
      cl_error(3, _ecl_static_6, v4name, T0);
L45:;
      T0 = ecl_cddr(v10lambdalistr);
      if (!(T0==ECL_NIL)) { goto L49; }
      goto L30;
L49:;
      cl_error(2, _ecl_static_7, v10lambdalistr);
      goto L39;
L43:;
      if ((v11next)==(ECL_SYM("&KEY",10))) { goto L53; }
      if ((v11next)==(ECL_SYM("&ALLOW-OTHER-KEYS",6))) { goto L53; }
      if (!((v11next)==(ECL_SYM("&AUX",7)))) { goto L51; }
      goto L52;
L53:;
L52:;
      cl_error(2, _ecl_static_8, v11next);
      goto L39;
L51:;
      if (!(ECL_SYMBOLP(v11next))) { goto L56; }
      v8varlist = CONS(v11next,v8varlist);
      goto L39;
L56:;
      if (!(ECL_LISTP(v11next))) { goto L59; }
      T0 = ecl_car(v11next);
      if (!(ECL_SYMBOLP(T0))) { goto L59; }
      T0 = ecl_car(v11next);
      v8varlist = CONS(T0,v8varlist);
      goto L39;
L59:;
      cl_error(2, _ecl_static_9, v11next);
     }
L39:;
     v10lambdalistr = ecl_cdr(v10lambdalistr);
L35:;
     if (v10lambdalistr==ECL_NIL) { goto L65; }
     goto L34;
L65:;
    }
L30:;
    v8varlist = cl_nreverse(v8varlist);
    T0 = cl_listX(4, ECL_SYM("&ENVIRONMENT",9), VV[13], VV[14], v5lambdalist);
    if (Null(v7docstring)) { goto L71; }
    T1 = ecl_list1(v7docstring);
    goto L69;
L71:;
    T1 = ECL_NIL;
    goto L69;
L69:;
    T2 = ecl_list1(v9restvar);
    T3 = ecl_append(v8varlist,T2);
    T4 = CONS(ECL_SYM("LIST*",482),T3);
    T5 = cl_list(3, ECL_SYM("MAPCAR",545), VV[19], T4);
    T6 = cl_list(2, VV[18], T5);
    T7 = ecl_list1(T6);
    T8 = cl_list(2, ECL_SYM("QUOTE",679), v6function);
    T9 = cl_listX(3, ECL_SYM("LIST*",482), T8, VV[21]);
    T10 = cl_listX(3, ECL_SYM("SUBST",831), T9, VV[22]);
    T11 = cl_list(2, ECL_SYM("QUOTE",679), v6function);
    T12 = ecl_list1(v9restvar);
    T13 = ecl_append(v8varlist,T12);
    T14 = cl_listX(4, ECL_SYM("LIST*",482), T11, VV[30], T13);
    T15 = cl_list(4, ECL_SYM("LIST",481), VV[28], VV[29], T14);
    T16 = cl_list(2, ECL_SYM("QUOTE",679), v6function);
    T17 = cl_listX(3, ECL_SYM("LIST*",482), T16, VV[21]);
    T18 = cl_list(4, ECL_SYM("IF",946), VV[27], T15, T17);
    T19 = cl_list(3, ECL_SYM("LIST",481), VV[26], T18);
    T20 = cl_list(3, ECL_SYM("LIST*",482), T19, VV[31]);
    T21 = cl_list(3, ECL_SYM("SETQ",751), VV[25], T20);
    T22 = cl_list(3, VV[24], T21, VV[32]);
    T23 = cl_list(3, ECL_SYM("DO",307), VV[23], T22);
    T24 = cl_list(4, ECL_SYM("IF",946), VV[20], T10, T23);
    T25 = cl_list(3, ECL_SYM("LET",477), T7, T24);
    T26 = cl_list(4, ECL_SYM("MULTIPLE-VALUE-BIND",572), VV[16], VV[17], T25);
    T27 = cl_list(2, VV[15], T26);
    T28 = ecl_append(T1,T27);
    value0 = cl_listX(4, ECL_SYM("DEFMACRO",283), v4name, T0, T28);
    return value0;
   }
  }
 }
}
/*	local function REMF                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC70remf(cl_object v1, cl_object v2env)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4place;
   cl_object v5indicator;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4place = v6;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5indicator = v6;
   }
   if (Null(v3)) { goto L14; }
   si_dm_too_many_arguments(v1);
L14:;
   {
    cl_object v7;                                 /*  VARS            */
    cl_object v8;                                 /*  VALS            */
    cl_object v9;                                 /*  STORES          */
    cl_object v10;                                /*  STORE-FORM      */
    cl_object v11;                                /*  ACCESS-FORM     */
    value0 = L8get_setf_expansion(2, v4place, v2env);
    v7 = value0;
    v8 = cl_env_copy->values[1];
    v9 = cl_env_copy->values[2];
    v10 = cl_env_copy->values[3];
    v11 = cl_env_copy->values[4];
    {
     cl_object v12s;
     v12s = cl_gensym(0);
     T0 = (ECL_SYM("LIST",481)->symbol.gfdef);
     T1 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(3, T0, v7, v8) /*  MAPCAR */;
     T2 = cl_list(2, v12s, v5indicator);
     T3 = ecl_list1(T2);
     T4 = ecl_append(T1,T3);
     T5 = CONS(VV[7],v7);
     T6 = cl_list(2, ECL_SYM("DECLARE",274), T5);
     T7 = ecl_car(v9);
     T8 = cl_list(2, T7, VV[34]);
     T9 = cl_list(3, ECL_SYM("REM-F",1127), v11, v12s);
     T10 = cl_list(5, ECL_SYM("MULTIPLE-VALUE-BIND",572), T8, T9, v10, VV[34]);
     value0 = cl_list(4, ECL_SYM("LET*",478), T4, T6, T10);
     return value0;
    }
   }
  }
 }
}
/*	local function INCF                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC72incf(cl_object v1, cl_object v2env)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4_reference;
   cl_object v5delta;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4_reference = v6;
   }
   if (Null(v3)) { goto L9; }
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5delta = v6;
    goto L8;
   }
L9:;
   v5delta = ecl_make_fixnum(1);
L8:;
   if (Null(v3)) { goto L14; }
   si_dm_too_many_arguments(v1);
L14:;
   {
    cl_object v7;                                 /*  VARS            */
    cl_object v8;                                 /*  VALS            */
    cl_object v9;                                 /*  STORES          */
    cl_object v10;                                /*  SETTER          */
    cl_object v11;                                /*  GETTER          */
    value0 = L8get_setf_expansion(2, v4_reference, v2env);
    v7 = value0;
    v8 = cl_env_copy->values[1];
    v9 = cl_env_copy->values[2];
    v10 = cl_env_copy->values[3];
    v11 = cl_env_copy->values[4];
    {
     cl_object v12all_vars;
     {cl_object v13;
      v13 = ECL_NIL;
      v13 = ecl_make_cfun((cl_objectfn_fixed)LC71__g113,ECL_NIL,Cblock,1);
      T0 = v13;
     }
     T1 = CONS(v5delta,ECL_NIL);
     v12all_vars = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T0, T1) /*  MAPCAR */;
     if (!(ECL_SYMBOLP(v11))) { goto L19; }
     T0 = (ECL_SYM("CAR",180)->symbol.gfdef);
     T1 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T0, v12all_vars) /*  MAPCAR */;
     T2 = cl_listX(3, ECL_SYM("+",14), v11, T1);
     T3 = ecl_car(v9);
     T4 = (ECL_SYM("FIRST",371)->symbol.gfdef);
     T5 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T4, v12all_vars) /*  MAPCAR */;
     T6 = CONS(VV[7],T5);
     T7 = cl_list(2, ECL_SYM("DECLARE",274), T6);
     T8 = cl_list(4, ECL_SYM("LET*",478), v12all_vars, T7, v10);
     value0 = cl_subst(3, T2, T3, T8);
     return value0;
L19:;
     {
      cl_object v13d;
      cl_object v14v;
      cl_object v15let_list;
      v13d = v7;
      v14v = v8;
      v15let_list = ECL_NIL;
      goto L28;
L27:;
      {
       cl_object v16;
       v16 = ecl_cdr(v13d);
       {
        cl_object v17;
        v17 = ecl_cdr(v14v);
        T0 = ecl_car(v13d);
        T1 = ecl_car(v14v);
        T2 = cl_list(2, T0, T1);
        v15let_list = CONS(T2,v15let_list);
        v14v = v17;
        v13d = v16;
       }
      }
L28:;
      if (v13d==ECL_NIL) { goto L34; }
      goto L27;
L34:;
      T0 = ecl_car(v9);
      if (!(ECL_LISTP(v4_reference))) { goto L39; }
      T2 = ecl_car(v4_reference);
      if (!((T2)==(ECL_SYM("THE",856)))) { goto L39; }
      T2 = ecl_cadr(v4_reference);
      T3 = cl_listX(4, ECL_SYM("+",14), v11, v5delta, ECL_NIL);
      T1 = cl_list(3, ECL_SYM("THE",856), T2, T3);
      goto L38;
L39:;
      T2 = (ECL_SYM("CAR",180)->symbol.gfdef);
      T3 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T2, v12all_vars) /*  MAPCAR */;
      T1 = cl_listX(3, ECL_SYM("+",14), v11, T3);
L38:;
      T2 = cl_list(2, T0, T1);
      T3 = ecl_append(v12all_vars,v15let_list);
      v15let_list = CONS(T2,T3);
      T0 = cl_nreverse(v15let_list);
      T1 = (ECL_SYM("FIRST",371)->symbol.gfdef);
      T2 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T1, v12all_vars) /*  MAPCAR */;
      T3 = ecl_append(T2,v7);
      T4 = CONS(VV[7],T3);
      T5 = cl_list(2, ECL_SYM("DECLARE",274), T4);
      value0 = cl_list(4, ECL_SYM("LET*",478), T0, T5, v10);
      return value0;
     }
    }
   }
  }
 }
}
/*	local function G113                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC71__g113(cl_object v1v)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_gensym(0);
  value0 = cl_list(2, T0, v1v);
  return value0;
 }
}
/*	local function DECF                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC74decf(cl_object v1, cl_object v2env)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4_reference;
   cl_object v5delta;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4_reference = v6;
   }
   if (Null(v3)) { goto L9; }
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5delta = v6;
    goto L8;
   }
L9:;
   v5delta = ecl_make_fixnum(1);
L8:;
   if (Null(v3)) { goto L14; }
   si_dm_too_many_arguments(v1);
L14:;
   {
    cl_object v7;                                 /*  VARS            */
    cl_object v8;                                 /*  VALS            */
    cl_object v9;                                 /*  STORES          */
    cl_object v10;                                /*  SETTER          */
    cl_object v11;                                /*  GETTER          */
    value0 = L8get_setf_expansion(2, v4_reference, v2env);
    v7 = value0;
    v8 = cl_env_copy->values[1];
    v9 = cl_env_copy->values[2];
    v10 = cl_env_copy->values[3];
    v11 = cl_env_copy->values[4];
    {
     cl_object v12all_vars;
     {cl_object v13;
      v13 = ECL_NIL;
      v13 = ecl_make_cfun((cl_objectfn_fixed)LC73__g125,ECL_NIL,Cblock,1);
      T0 = v13;
     }
     T1 = CONS(v5delta,ECL_NIL);
     v12all_vars = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T0, T1) /*  MAPCAR */;
     if (!(ECL_SYMBOLP(v11))) { goto L19; }
     T0 = (ECL_SYM("CAR",180)->symbol.gfdef);
     T1 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T0, v12all_vars) /*  MAPCAR */;
     T2 = cl_listX(3, ECL_SYM("-",17), v11, T1);
     T3 = ecl_car(v9);
     T4 = (ECL_SYM("FIRST",371)->symbol.gfdef);
     T5 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T4, v12all_vars) /*  MAPCAR */;
     T6 = CONS(VV[7],T5);
     T7 = cl_list(2, ECL_SYM("DECLARE",274), T6);
     T8 = cl_list(4, ECL_SYM("LET*",478), v12all_vars, T7, v10);
     value0 = cl_subst(3, T2, T3, T8);
     return value0;
L19:;
     {
      cl_object v13d;
      cl_object v14v;
      cl_object v15let_list;
      v13d = v7;
      v14v = v8;
      v15let_list = ECL_NIL;
      goto L28;
L27:;
      {
       cl_object v16;
       v16 = ecl_cdr(v13d);
       {
        cl_object v17;
        v17 = ecl_cdr(v14v);
        T0 = ecl_car(v13d);
        T1 = ecl_car(v14v);
        T2 = cl_list(2, T0, T1);
        v15let_list = CONS(T2,v15let_list);
        v14v = v17;
        v13d = v16;
       }
      }
L28:;
      if (v13d==ECL_NIL) { goto L34; }
      goto L27;
L34:;
      T0 = ecl_car(v9);
      if (!(ECL_LISTP(v4_reference))) { goto L39; }
      T2 = ecl_car(v4_reference);
      if (!((T2)==(ECL_SYM("THE",856)))) { goto L39; }
      T2 = ecl_cadr(v4_reference);
      T3 = cl_listX(4, ECL_SYM("-",17), v11, v5delta, ECL_NIL);
      T1 = cl_list(3, ECL_SYM("THE",856), T2, T3);
      goto L38;
L39:;
      T2 = (ECL_SYM("CAR",180)->symbol.gfdef);
      T3 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T2, v12all_vars) /*  MAPCAR */;
      T1 = cl_listX(3, ECL_SYM("-",17), v11, T3);
L38:;
      T2 = cl_list(2, T0, T1);
      T3 = ecl_append(v12all_vars,v15let_list);
      v15let_list = CONS(T2,T3);
      T0 = cl_nreverse(v15let_list);
      T1 = (ECL_SYM("FIRST",371)->symbol.gfdef);
      T2 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T1, v12all_vars) /*  MAPCAR */;
      T3 = ecl_append(T2,v7);
      T4 = CONS(VV[7],T3);
      T5 = cl_list(2, ECL_SYM("DECLARE",274), T4);
      value0 = cl_list(4, ECL_SYM("LET*",478), T0, T5, v10);
      return value0;
     }
    }
   }
  }
 }
}
/*	local function G125                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC73__g125(cl_object v1v)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_gensym(0);
  value0 = cl_list(2, T0, v1v);
  return value0;
 }
}
/*	local function PUSH                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC75push(cl_object v1, cl_object v2env)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4item;
   cl_object v5place;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4item = v6;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5place = v6;
   }
   if (Null(v3)) { goto L14; }
   si_dm_too_many_arguments(v1);
L14:;
   {
    cl_object v7;                                 /*  VARS            */
    cl_object v8;                                 /*  VALS            */
    cl_object v9;                                 /*  STORES          */
    cl_object v10;                                /*  STORE-FORM      */
    cl_object v11;                                /*  ACCESS-FORM     */
    value0 = L8get_setf_expansion(2, v5place, v2env);
    v7 = value0;
    v8 = cl_env_copy->values[1];
    v9 = cl_env_copy->values[2];
    v10 = cl_env_copy->values[3];
    v11 = cl_env_copy->values[4];
    if (Null(L61trivial_setf_form(v5place, v7, v9, v10, v11))) { goto L17; }
    T0 = cl_list(3, ECL_SYM("CONS",251), v4item, v5place);
    value0 = cl_list(3, ECL_SYM("SETQ",751), v5place, T0);
    return value0;
L17:;
    if ((cl_constantp(1, v4item))!=ECL_NIL) { goto L19; }
    v8 = CONS(v4item,v8);
    v4item = cl_gensym(0);
    v7 = CONS(v4item,v7);
L19:;
    T0 = (ECL_SYM("LIST",481)->symbol.gfdef);
    T1 = ecl_append(v7,v9);
    T2 = cl_list(3, ECL_SYM("CONS",251), v4item, v11);
    T3 = ecl_list1(T2);
    T4 = ecl_append(v8,T3);
    T5 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(3, T0, T1, T4) /*  MAPCAR */;
    T6 = CONS(VV[7],v7);
    T7 = cl_list(2, ECL_SYM("DECLARE",274), T6);
    value0 = cl_list(4, ECL_SYM("LET*",478), T5, T7, v10);
    return value0;
   }
  }
 }
}
/*	local function PUSHNEW                                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC76pushnew(cl_object v1, cl_object v2env)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4item;
   cl_object v5place;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4item = v6;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5place = v6;
   }
   {
    cl_object v7;                                 /*  VARS            */
    cl_object v8;                                 /*  VALS            */
    cl_object v9;                                 /*  STORES          */
    cl_object v10;                                /*  STORE-FORM      */
    cl_object v11;                                /*  ACCESS-FORM     */
    value0 = L8get_setf_expansion(2, v5place, v2env);
    v7 = value0;
    v8 = cl_env_copy->values[1];
    v9 = cl_env_copy->values[2];
    v10 = cl_env_copy->values[3];
    v11 = cl_env_copy->values[4];
    if (Null(L61trivial_setf_form(v5place, v7, v9, v10, v11))) { goto L15; }
    T0 = cl_listX(4, ECL_SYM("ADJOIN",82), v4item, v5place, v3);
    value0 = cl_list(3, ECL_SYM("SETQ",751), v5place, T0);
    return value0;
L15:;
    if ((cl_constantp(1, v4item))!=ECL_NIL) { goto L17; }
    v8 = CONS(v4item,v8);
    v4item = cl_gensym(0);
    v7 = CONS(v4item,v7);
L17:;
    T0 = (ECL_SYM("LIST",481)->symbol.gfdef);
    T1 = ecl_append(v7,v9);
    T2 = cl_listX(4, ECL_SYM("ADJOIN",82), v4item, v11, v3);
    T3 = ecl_list1(T2);
    T4 = ecl_append(v8,T3);
    T5 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(3, T0, T1, T4) /*  MAPCAR */;
    T6 = CONS(VV[7],v7);
    T7 = cl_list(2, ECL_SYM("DECLARE",274), T6);
    value0 = cl_list(4, ECL_SYM("LET*",478), T5, T7, v10);
    return value0;
   }
  }
 }
}
/*	local function POP                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC77pop(cl_object v1, cl_object v2env)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4place;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4place = v5;
   }
   if (Null(v3)) { goto L8; }
   si_dm_too_many_arguments(v1);
L8:;
   {
    cl_object v6;                                 /*  VARS            */
    cl_object v7;                                 /*  VALS            */
    cl_object v8;                                 /*  STORES          */
    cl_object v9;                                 /*  STORE-FORM      */
    cl_object v10;                                /*  ACCESS-FORM     */
    value0 = L8get_setf_expansion(2, v4place, v2env);
    v6 = value0;
    v7 = cl_env_copy->values[1];
    v8 = cl_env_copy->values[2];
    v9 = cl_env_copy->values[3];
    v10 = cl_env_copy->values[4];
    {
     cl_object v11store_var;
     v11store_var = ecl_car(v8);
     T0 = (ECL_SYM("LIST",481)->symbol.gfdef);
     T1 = ecl_append(v6,v8);
     T2 = ecl_list1(v10);
     T3 = ecl_append(v7,T2);
     T4 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(3, T0, T1, T3) /*  MAPCAR */;
     T5 = CONS(VV[7],v6);
     T6 = cl_list(2, ECL_SYM("DECLARE",274), T5);
     T7 = cl_list(2, ECL_SYM("CAR",180), v11store_var);
     T8 = cl_list(3, ECL_SYM("TRULY-THE",1949), ECL_SYM("LIST",481), v11store_var);
     T9 = cl_list(2, ECL_SYM("CDR",198), T8);
     T10 = cl_list(3, ECL_SYM("SETQ",751), v11store_var, T9);
     T11 = cl_list(4, ECL_SYM("PROG1",669), T7, T10, v9);
     value0 = cl_list(4, ECL_SYM("LET*",478), T4, T6, T11);
     return value0;
    }
   }
  }
 }
}
/*	local function VALUES                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC78values(cl_narg narg, cl_object v1env, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2values;
  ecl_va_list args; ecl_va_start(args,v1env,narg,1);
  v2values = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v3all_vars;
   cl_object v4all_vals;
   cl_object v5all_stores;
   cl_object v6all_storing_forms;
   cl_object v7all_get_forms;
   v3all_vars = ECL_NIL;
   v4all_vals = ECL_NIL;
   v5all_stores = ECL_NIL;
   v6all_storing_forms = ECL_NIL;
   v7all_get_forms = ECL_NIL;
   {
    cl_object v8;
    v8 = cl_reverse(v2values);
    goto L10;
L9:;
    {
     cl_object v9item;
     v9item = ecl_car(v8);
     {
      cl_object v11;                              /*  VARS            */
      cl_object v12;                              /*  VALS            */
      cl_object v13;                              /*  STORES          */
      cl_object v14;                              /*  STORING-FORM    */
      cl_object v15;                              /*  GET-FORM        */
      value0 = L8get_setf_expansion(2, v9item, v1env);
      v11 = value0;
      v12 = cl_env_copy->values[1];
      v13 = cl_env_copy->values[2];
      v14 = cl_env_copy->values[3];
      v15 = cl_env_copy->values[4];
      {
       cl_object v16extra;
       v16extra = ecl_cdr(v13);
       if (ecl_endp(v16extra)) { goto L16; }
       v11 = ecl_append(v16extra,v11);
       {
        cl_fixnum v17;
        v17 = ecl_length(v16extra);
        T0 = cl_make_list(1, ecl_make_fixnum(v17));
        v12 = ecl_append(T0,v12);
       }
       T0 = ecl_car(v13);
       v13 = ecl_list1(T0);
      }
L16:;
      v3all_vars = ecl_append(v11,v3all_vars);
      v4all_vals = ecl_append(v12,v4all_vals);
      v5all_stores = ecl_append(v13,v5all_stores);
      v6all_storing_forms = CONS(v14,v6all_storing_forms);
      v7all_get_forms = CONS(v15,v7all_get_forms);
     }
    }
    v8 = ecl_cdr(v8);
L10:;
    if (Null(v8)) { goto L35; }
    goto L9;
L35:;
   }
   T0 = CONS(ECL_SYM("VALUES",895),v6all_storing_forms);
   T1 = CONS(ECL_SYM("VALUES",895),v7all_get_forms);
   cl_env_copy->nvalues = 5;
   cl_env_copy->values[4] = T1;
   cl_env_copy->values[3] = T0;
   cl_env_copy->values[2] = v5all_stores;
   cl_env_copy->values[1] = v4all_vals;
   cl_env_copy->values[0] = v3all_vars;
   return cl_env_copy->values[0];
  }
 }
}

#include "lsp/setf.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecldsIhADcO3Hii9_Z57SoE21(cl_object flag)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 cl_object *VVtemp;
 if (flag != OBJNULL){
 Cblock = flag;
 #ifndef ECL_DYNAMIC_VV
 flag->cblock.data = VV;
 #endif
 flag->cblock.data_size = VM;
 flag->cblock.temp_data_size = VMtemp;
 flag->cblock.data_text = compiler_data_text;
 flag->cblock.data_text_size = compiler_data_text_size;
 flag->cblock.cfuns_size = compiler_cfuns_size;
 flag->cblock.cfuns = compiler_cfuns;
 flag->cblock.source = make_constant_base_string("SRC:LSP;SETF.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_ecldsIhADcO3Hii9_Z57SoE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 (void)0; /* No entry created for CHECK-STORES-NUMBER */
 (void)0; /* No entry created for DO-SETF-METHOD-EXPANSION */
 (void)0; /* No entry created for SETF-METHOD-WRAPPER */
 (void)0; /* No entry created for DO-DEFSETF */
 (void)0; /* No entry created for DO-DEFINE-SETF-METHOD */
 ecl_cmp_defmacro(VV[41]);                        /*  DEFSETF         */
 ecl_cmp_defmacro(VV[42]);                        /*  DEFINE-SETF-EXPANDER */
 ecl_cmp_defun(VV[43]);                           /*  GET-SETF-EXPANSION */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC9car,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("CAR",180), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC10cdr,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("CDR",198), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC11caar,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("CAAR",171), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC12cdar,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("CDAR",190), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC13cadr,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("CADR",178), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC14cddr,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("CDDR",197), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC15caaar,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("CAAAR",167), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC16cdaar,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("CDAAR",186), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC17cadar,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("CADAR",174), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC18cddar,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("CDDAR",193), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC19caadr,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("CAADR",170), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC20cdadr,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("CDADR",189), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC21caddr,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("CADDR",177), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC22cdddr,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("CDDDR",196), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC23caaaar,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("CAAAAR",165), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC24cdaaar,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("CDAAAR",184), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC25cadaar,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("CADAAR",172), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC26cddaar,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("CDDAAR",191), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC27caadar,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("CAADAR",168), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC28cdadar,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("CDADAR",187), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC29caddar,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("CADDAR",175), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC30cdddar,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("CDDDAR",194), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC31caaadr,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("CAAADR",166), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC32cdaadr,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("CDAADR",185), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC33cadadr,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("CADADR",173), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC34cddadr,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("CDDADR",192), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC35caaddr,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("CAADDR",169), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC36cdaddr,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("CDADDR",188), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC37cadddr,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("CADDDR",176), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC38cddddr,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("CDDDDR",195), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC39first,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("FIRST",371), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC40second,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("SECOND",740), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC41third,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("THIRD",857), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC42fourth,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("FOURTH",389), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC43fifth,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("FIFTH",351), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC44sixth,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("SIXTH",782), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC45seventh,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("SEVENTH",752), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC46eighth,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("EIGHTH",326), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC47ninth,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("NINTH",583), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC48tenth,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("TENTH",854), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC49rest,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("REST",719), T0);
 }
 si_do_defsetf(ECL_SYM("SVREF",838), ECL_SYM("SVSET",1158));
 si_do_defsetf(ECL_SYM("ELT",327), ECL_SYM("ELT-SET",1066));
 si_do_defsetf(ECL_SYM("SYMBOL-VALUE",846), ECL_SYM("SET",743));
 si_do_defsetf(ECL_SYM("SYMBOL-FUNCTION",841), ECL_SYM("FSET",1080));
 si_do_defsetf(ECL_SYM("FDEFINITION",349), ECL_SYM("FSET",1080));
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC50macro_function,ECL_NIL,Cblock);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("MACRO-FUNCTION",518), T0);
 }
 si_do_defsetf(ECL_SYM("AREF",92), ECL_SYM("ASET",1041));
 si_do_defsetf(ECL_SYM("ROW-MAJOR-AREF",731), ECL_SYM("ROW-MAJOR-ASET",1130));
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC51get,ECL_NIL,Cblock);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("GET",402), T0);
 }
 si_do_defsetf(ECL_SYM("GET-SYSPROP",1083), ECL_SYM("PUT-SYSPROP",1124));
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC52nth,ECL_NIL,Cblock,3);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("NTH",602), T0);
 }
 si_do_defsetf(ECL_SYM("CHAR",203), ECL_SYM("CHAR-SET",1052));
 si_do_defsetf(ECL_SYM("SCHAR",738), ECL_SYM("SCHAR-SET",1135));
 si_do_defsetf(ECL_SYM("BIT",123), ECL_SYM("ASET",1041));
 si_do_defsetf(ECL_SYM("SBIT",736), ECL_SYM("ASET",1041));
 si_do_defsetf(ECL_SYM("FILL-POINTER",362), ECL_SYM("FILL-POINTER-SET",1071));
 si_do_defsetf(ECL_SYM("SYMBOL-PLIST",845), ECL_SYM("SET-SYMBOL-PLIST",1139));
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC53gethash,ECL_NIL,Cblock);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("GETHASH",413), T0);
 }
 si_do_defsetf(ECL_SYM("INSTANCE-REF",1169), ECL_SYM("INSTANCE-SET",1170));
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC54compiler_macro_function,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("COMPILER-MACRO-FUNCTION",239), T0);
 }
 si_do_defsetf(ECL_SYM("READTABLE-CASE",701), ECL_SYM("READTABLE-CASE-SET",1126));
 si_do_defsetf(ECL_SYM("STREAM-EXTERNAL-FORMAT",803), ECL_SYM("STREAM-EXTERNAL-FORMAT-SET",1723));
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC55getf,ECL_NIL,Cblock);
  T0 = v1;
 }
 si_do_define_setf_method(ECL_SYM("GETF",412), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC56subseq,ECL_NIL,Cblock);
  T0 = v1;
 }
 si_do_defsetf(ECL_SYM("SUBSEQ",829), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC57the,ECL_NIL,Cblock,3);
  T0 = v1;
 }
 si_do_define_setf_method(ECL_SYM("THE",856), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC58apply,ECL_NIL,Cblock);
  T0 = v1;
 }
 si_do_define_setf_method(ECL_SYM("APPLY",89), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC59ldb,ECL_NIL,Cblock,3);
  T0 = v1;
 }
 si_do_define_setf_method(ECL_SYM("LDB",457), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC60mask_field,ECL_NIL,Cblock,3);
  T0 = v1;
 }
 si_do_define_setf_method(ECL_SYM("MASK-FIELD",550), T0);
 }
 (void)0; /* No entry created for TRIVIAL-SETF-FORM */
 (void)0; /* No entry created for TRY-SIMPLER-EXPANSION */
 (void)0; /* No entry created for SETF-EXPAND-1 */
 (void)0; /* No entry created for SETF-EXPAND */
 ecl_cmp_defmacro(VV[44]);                        /*  SETF            */
 ecl_cmp_defmacro(VV[45]);                        /*  PSETF           */
 ecl_cmp_defmacro(VV[46]);                        /*  SHIFTF          */
 ecl_cmp_defmacro(VV[47]);                        /*  ROTATEF         */
 ecl_cmp_defmacro(VV[48]);                        /*  DEFINE-MODIFY-MACRO */
 ecl_cmp_defmacro(VV[49]);                        /*  REMF            */
 ecl_cmp_defmacro(VV[50]);                        /*  INCF            */
 ecl_cmp_defmacro(VV[51]);                        /*  DECF            */
 ecl_cmp_defmacro(VV[52]);                        /*  PUSH            */
 ecl_cmp_defmacro(VV[53]);                        /*  PUSHNEW         */
 ecl_cmp_defmacro(VV[54]);                        /*  POP             */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC78values,ECL_NIL,Cblock);
  T0 = v1;
 }
 si_do_define_setf_method(ECL_SYM("VALUES",895), T0);
 }
}
