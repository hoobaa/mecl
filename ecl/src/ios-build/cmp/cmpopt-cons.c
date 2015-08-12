/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPOPT-CONS.LSP                               */
#include <ecl/ecl-cmp.h>
#include "cmp/cmpopt-cons.eclh"
/*	function definition for EXPAND-SIMPLE-OPTIMIZER               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1expand_simple_optimizer(cl_object v1values, cl_object v2arg_types, cl_object v3inline_form, cl_object v4env)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[11])(1, v4env) /*  POLICY-ASSUME-RIGHT-TYPE */)) { goto L2; }
  T0 = v1values;
  goto L1;
L2:;
  {
   cl_object v5v;
   cl_object v6;
   v5v = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v1values))) FEtype_error_list(v1values);
   v6 = v1values;
   {
    cl_object v7value_and_type;
    cl_object v8;
    v7value_and_type = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v2arg_types))) FEtype_error_list(v2arg_types);
    v8 = v2arg_types;
    {
     cl_object v9;
     cl_object v10;
     v9 = ecl_list1(ECL_NIL);
     v10 = v9;
L12:;
     if (!(ecl_endp(v6))) { goto L14; }
     goto L13;
L14:;
     v5v = _ecl_car(v6);
     {
      cl_object v11;
      v11 = _ecl_cdr(v6);
      if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
      v6 = v11;
     }
     if (!(ecl_endp(v8))) { goto L22; }
     goto L13;
L22:;
     v7value_and_type = _ecl_car(v8);
     {
      cl_object v11;
      v11 = _ecl_cdr(v8);
      if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
      v8 = v11;
     }
     if (ecl_unlikely(ECL_ATOM(v10))) FEtype_error_cons(v10);
     T1 = v10;
     if (!(ECL_CONSP(v7value_and_type))) { goto L35; }
     T3 = ecl_cadr(v7value_and_type);
     T2 = cl_list(3, ECL_SYM("CHECKED-VALUE",1950), T3, v5v);
     goto L34;
L35:;
     T2 = v5v;
L34:;
     v10 = ecl_list1(T2);
     (ECL_CONS_CDR(T1)=v10,T1);
     goto L12;
L13:;
     T0 = ecl_cdr(v9);
     goto L1;
    }
   }
  }
L1:;
  value0 = cl_listX(3, ECL_SYM("C-INLINE",1973), T0, v3inline_form);
  return value0;
 }
}
/*	function definition for SIMPLE-OPTIMIZER-FUNCTION             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4simple_optimizer_function(cl_object v1name, cl_object v2args, cl_object v3inline_form)
{
 cl_object T0, T1;
 cl_object env0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v2args,env0);                /*  ARGS            */
  CLV1 = env0 = CONS(v3inline_form,env0);         /*  INLINE-FORM     */
  T1 = (ECL_SYM("SYMBOLP",847)->symbol.gfdef);
  if (Null(cl_every(2, T1, ECL_CONS_CAR(CLV0)))) { goto L2; }
  {cl_object v4;
   v4 = ECL_NIL;
   v4 = ecl_make_cclosure_va((cl_objectfn)LC2__g8,env0,Cblock);
   T0 = v4;
   goto L1;
  }
L2:;
  {cl_object v5;
   v5 = ECL_NIL;
   v5 = ecl_make_cclosure_va((cl_objectfn)LC3__g9,env0,Cblock);
   T0 = v5;
  }
L1:;
  value0 = si_put_sysprop(v1name, ECL_SYM("COMPILER-MACRO",238), T0);
  return value0;
 }
}
/*	closure G8                                                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC2__g8(cl_narg narg, cl_object v1whole, cl_object v2env, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  INLINE-FORM     */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[13])(1, v2env) /*  POLICY-INLINE-ACCESSORS */)) { goto L1; }
  T0 = ecl_cdr(v1whole);
  value0 = cl_listX(3, ECL_SYM("C-INLINE",1973), T0, ECL_CONS_CAR(CLV1));
  return value0;
L1:;
  value0 = v1whole;
  cl_env_copy->nvalues = 1;
  return value0;
 }
 }
}
/*	closure G9                                                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC3__g9(cl_narg narg, cl_object v1whole, cl_object v2env, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  INLINE-FORM     */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[13])(1, v2env) /*  POLICY-INLINE-ACCESSORS */)) { goto L1; }
  T0 = ecl_cdr(v1whole);
  value0 = L1expand_simple_optimizer(T0, ECL_CONS_CAR(CLV0), ECL_CONS_CAR(CLV1), v2env);
  return value0;
L1:;
  value0 = v1whole;
  cl_env_copy->nvalues = 1;
  return value0;
 }
 }
}
/*	local function CONS-CAR                                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC5cons_car(cl_object v1, cl_object v2)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4x;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4x = v5;
   }
   if (Null(v3)) { goto L8; }
   si_dm_too_many_arguments(v1);
L8:;
   T0 = ecl_list1(v4x);
   value0 = cl_listX(3, ECL_SYM("C-INLINE",1973), T0, VV[2]);
   return value0;
  }
 }
}
/*	local function CONS-CDR                                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC6cons_cdr(cl_object v1, cl_object v2)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4x;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4x = v5;
   }
   if (Null(v3)) { goto L8; }
   si_dm_too_many_arguments(v1);
L8:;
   T0 = ecl_list1(v4x);
   value0 = cl_listX(3, ECL_SYM("C-INLINE",1973), T0, VV[4]);
   return value0;
  }
 }
}
/*	local function CONS                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC8cons(cl_object v1, cl_object v2)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_cdr(v1);
   {
    cl_object v4temp;
    v4temp = ECL_NIL;
    {
     cl_fixnum v5;
     v5 = ecl_length(v3);
     if (!((v5)==(2))) { goto L3; }
    }
    v4temp = LC7cons_to_lista(v3);
    if ((v3)==(v4temp)) { goto L3; }
    T0 = ecl_last(v4temp,1);
    if (!(ecl_equal(VV[6],T0))) { goto L7; }
    T0 = ecl_butlast(v4temp,1);
    value0 = CONS(ECL_SYM("LIST",481),T0);
    cl_env_copy->nvalues = 1;
    return value0;
L7:;
    value0 = CONS(ECL_SYM("LIST*",482),v4temp);
    cl_env_copy->nvalues = 1;
    return value0;
L3:;
    value0 = v1;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	local function CONS-TO-LISTA                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC7cons_to_lista(cl_object v1x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2tem;
   v2tem = ecl_last(v1x,1);
   if (!(ECL_CONSP(v2tem))) { goto L2; }
   T0 = ecl_car(v2tem);
   if (!(ECL_CONSP(T0))) { goto L2; }
   T0 = ecl_caar(v2tem);
   if (!((T0)==(ECL_SYM("CONS",251)))) { goto L2; }
   T0 = ecl_cdar(v2tem);
   {
    cl_fixnum v3;
    v3 = ecl_length(T0);
    if (!((v3)==(2))) { goto L2; }
   }
   T0 = ecl_butlast(v1x,1);
   T1 = ecl_cdar(v2tem);
   v1x = ecl_append(T0,T1);
   goto TTL;
L2:;
   value0 = v1x;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function DEFINE-SIMPLE-OPTIMIZER                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC9define_simple_optimizer(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4name;
   cl_object v5args;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4name = v6;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5args = v6;
   }
   T0 = cl_list(2, ECL_SYM("QUOTE",679), v4name);
   T1 = cl_list(2, ECL_SYM("QUOTE",679), v5args);
   T2 = cl_list(2, ECL_SYM("QUOTE",679), v3);
   value0 = cl_list(4, VV[1], T0, T1, T2);
   return value0;
  }
 }
}
/*	local function NTH                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC10nth(cl_object v1, cl_object v2)
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
   {
    cl_object v4;
    v4 = ecl_car(v3);
    if (!((v4)==(ecl_make_fixnum(0)))) { goto L3; }
    T0 = ecl_cdr(v3);
    value0 = CONS(ECL_SYM("CAR",180),T0);
    cl_env_copy->nvalues = 1;
    return value0;
L3:;
    if (!((v4)==(ecl_make_fixnum(1)))) { goto L5; }
    T0 = ecl_cdr(v3);
    value0 = CONS(ECL_SYM("CADR",178),T0);
    cl_env_copy->nvalues = 1;
    return value0;
L5:;
    if (!((v4)==(ecl_make_fixnum(2)))) { goto L7; }
    T0 = ecl_cdr(v3);
    value0 = CONS(ECL_SYM("CADDR",177),T0);
    cl_env_copy->nvalues = 1;
    return value0;
L7:;
    if (!((v4)==(ecl_make_fixnum(3)))) { goto L9; }
    T0 = ecl_cdr(v3);
    value0 = CONS(ECL_SYM("CADDDR",176),T0);
    cl_env_copy->nvalues = 1;
    return value0;
L9:;
    if (!((v4)==(ecl_make_fixnum(4)))) { goto L11; }
    T0 = ecl_cdr(v3);
    T1 = CONS(ECL_SYM("CDDDDR",195),T0);
    value0 = cl_list(2, ECL_SYM("CAR",180), T1);
    return value0;
L11:;
    if (!((v4)==(ecl_make_fixnum(5)))) { goto L13; }
    T0 = ecl_cdr(v3);
    T1 = CONS(ECL_SYM("CDDDDR",195),T0);
    value0 = cl_list(2, ECL_SYM("CADR",178), T1);
    return value0;
L13:;
    if (!((v4)==(ecl_make_fixnum(6)))) { goto L15; }
    T0 = ecl_cdr(v3);
    T1 = CONS(ECL_SYM("CDDDDR",195),T0);
    value0 = cl_list(2, ECL_SYM("CADDR",177), T1);
    return value0;
L15:;
    if (!((v4)==(ecl_make_fixnum(7)))) { goto L17; }
    T0 = ecl_cdr(v3);
    T1 = CONS(ECL_SYM("CDDDDR",195),T0);
    value0 = cl_list(2, ECL_SYM("CADDDR",176), T1);
    return value0;
L17:;
    value0 = v1;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	local function NTHCDR                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC11nthcdr(cl_object v1, cl_object v2)
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
   {
    cl_object v4;
    v4 = ecl_car(v3);
    if (!((v4)==(ecl_make_fixnum(0)))) { goto L3; }
    value0 = ecl_cadr(v3);
    cl_env_copy->nvalues = 1;
    return value0;
L3:;
    if (!((v4)==(ecl_make_fixnum(1)))) { goto L5; }
    T0 = ecl_cdr(v3);
    value0 = CONS(ECL_SYM("CDR",198),T0);
    cl_env_copy->nvalues = 1;
    return value0;
L5:;
    if (!((v4)==(ecl_make_fixnum(2)))) { goto L7; }
    T0 = ecl_cdr(v3);
    value0 = CONS(ECL_SYM("CDDR",197),T0);
    cl_env_copy->nvalues = 1;
    return value0;
L7:;
    if (!((v4)==(ecl_make_fixnum(3)))) { goto L9; }
    T0 = ecl_cdr(v3);
    value0 = CONS(ECL_SYM("CDDDR",196),T0);
    cl_env_copy->nvalues = 1;
    return value0;
L9:;
    if (!((v4)==(ecl_make_fixnum(4)))) { goto L11; }
    T0 = ecl_cdr(v3);
    value0 = CONS(ECL_SYM("CDDDDR",195),T0);
    cl_env_copy->nvalues = 1;
    return value0;
L11:;
    if (!((v4)==(ecl_make_fixnum(5)))) { goto L13; }
    T0 = ecl_cdr(v3);
    T1 = CONS(ECL_SYM("CDDDDR",195),T0);
    value0 = cl_list(2, ECL_SYM("CDR",198), T1);
    return value0;
L13:;
    if (!((v4)==(ecl_make_fixnum(6)))) { goto L15; }
    T0 = ecl_cdr(v3);
    T1 = CONS(ECL_SYM("CDDDDR",195),T0);
    value0 = cl_list(2, ECL_SYM("CDDR",197), T1);
    return value0;
L15:;
    if (!((v4)==(ecl_make_fixnum(7)))) { goto L17; }
    T0 = ecl_cdr(v3);
    T1 = CONS(ECL_SYM("CDDDDR",195),T0);
    value0 = cl_list(2, ECL_SYM("CDDDR",196), T1);
    return value0;
L17:;
    value0 = v1;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	local function FIRST                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC12first(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4x;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4x = v5;
   }
   if (Null(v3)) { goto L8; }
   si_dm_too_many_arguments(v1);
L8:;
   value0 = cl_list(3, ECL_SYM("NTH",602), ecl_make_fixnum(0), v4x);
   return value0;
  }
 }
}
/*	local function SECOND                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC13second(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4x;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4x = v5;
   }
   if (Null(v3)) { goto L8; }
   si_dm_too_many_arguments(v1);
L8:;
   value0 = cl_list(3, ECL_SYM("NTH",602), ecl_make_fixnum(1), v4x);
   return value0;
  }
 }
}
/*	local function THIRD                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC14third(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4x;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4x = v5;
   }
   if (Null(v3)) { goto L8; }
   si_dm_too_many_arguments(v1);
L8:;
   value0 = cl_list(3, ECL_SYM("NTH",602), ecl_make_fixnum(2), v4x);
   return value0;
  }
 }
}
/*	local function FOURTH                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC15fourth(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4x;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4x = v5;
   }
   if (Null(v3)) { goto L8; }
   si_dm_too_many_arguments(v1);
L8:;
   value0 = cl_list(3, ECL_SYM("NTH",602), ecl_make_fixnum(3), v4x);
   return value0;
  }
 }
}
/*	local function FIFTH                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC16fifth(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4x;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4x = v5;
   }
   if (Null(v3)) { goto L8; }
   si_dm_too_many_arguments(v1);
L8:;
   value0 = cl_list(3, ECL_SYM("NTH",602), ecl_make_fixnum(4), v4x);
   return value0;
  }
 }
}
/*	local function SIXTH                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC17sixth(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4x;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4x = v5;
   }
   if (Null(v3)) { goto L8; }
   si_dm_too_many_arguments(v1);
L8:;
   value0 = cl_list(3, ECL_SYM("NTH",602), ecl_make_fixnum(5), v4x);
   return value0;
  }
 }
}
/*	local function SEVENTH                                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC18seventh(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4x;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4x = v5;
   }
   if (Null(v3)) { goto L8; }
   si_dm_too_many_arguments(v1);
L8:;
   value0 = cl_list(3, ECL_SYM("NTH",602), ecl_make_fixnum(6), v4x);
   return value0;
  }
 }
}
/*	local function EIGHTH                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC19eighth(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4x;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4x = v5;
   }
   if (Null(v3)) { goto L8; }
   si_dm_too_many_arguments(v1);
L8:;
   value0 = cl_list(3, ECL_SYM("NTH",602), ecl_make_fixnum(7), v4x);
   return value0;
  }
 }
}
/*	local function NINTH                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC20ninth(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4x;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4x = v5;
   }
   if (Null(v3)) { goto L8; }
   si_dm_too_many_arguments(v1);
L8:;
   value0 = cl_list(3, ECL_SYM("NTH",602), ecl_make_fixnum(8), v4x);
   return value0;
  }
 }
}
/*	local function TENTH                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC21tenth(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4x;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4x = v5;
   }
   if (Null(v3)) { goto L8; }
   si_dm_too_many_arguments(v1);
L8:;
   value0 = cl_list(3, ECL_SYM("NTH",602), ecl_make_fixnum(9), v4x);
   return value0;
  }
 }
}
/*	local function REST                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC22rest(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4x;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4x = v5;
   }
   if (Null(v3)) { goto L8; }
   si_dm_too_many_arguments(v1);
L8:;
   value0 = cl_list(2, ECL_SYM("CDR",198), v4x);
   return value0;
  }
 }
}
/*	local function POP                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC23pop(cl_object v1, cl_object v2env)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12;
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
   if (Null(ecl_function_dispatch(cl_env_copy,VV[13])(0) /*  POLICY-INLINE-ACCESSORS */)) { goto L10; }
   {
    cl_object v6;                                 /*  VARS            */
    cl_object v7;                                 /*  VALS            */
    cl_object v8;                                 /*  STORES          */
    cl_object v9;                                 /*  STORE-FORM      */
    cl_object v10;                                /*  ACCESS-FORM     */
    value0 = (cl_env_copy->function=(ECL_SYM("GET-SETF-EXPANSION",410)->symbol.gfdef))->cfun.entry(2, v4place, v2env) /*  GET-SETF-EXPANSION */;
    v6 = value0;
    v7 = cl_env_copy->values[1];
    v8 = cl_env_copy->values[2];
    v9 = cl_env_copy->values[3];
    v10 = cl_env_copy->values[4];
    {
     cl_object v11store_var;
     cl_object v12saved_place;
     v11store_var = ecl_car(v8);
     v12saved_place = cl_gensym(0);
     {
      cl_object v13;
      cl_object v14;
      cl_object v15;
      T1 = ecl_list1(v12saved_place);
      v13 = ecl_append(v6,T1);
      v14 = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v13))) FEtype_error_list(v13);
      v15 = v13;
      {
       cl_object v16;
       cl_object v17;
       cl_object v18;
       T1 = ecl_list1(v10);
       v16 = ecl_append(v7,T1);
       v17 = ECL_NIL;
       if (ecl_unlikely(!ECL_LISTP(v16))) FEtype_error_list(v16);
       v18 = v16;
       {
        cl_object v19;
        cl_object v20;
        v19 = ecl_list1(ECL_NIL);
        v20 = v19;
L26:;
        if (!(ecl_endp(v15))) { goto L28; }
        goto L27;
L28:;
        v14 = _ecl_car(v15);
        {
         cl_object v21;
         v21 = _ecl_cdr(v15);
         if (ecl_unlikely(!ECL_LISTP(v21))) FEtype_error_list(v21);
         v15 = v21;
        }
        if (!(ecl_endp(v18))) { goto L36; }
        goto L27;
L36:;
        v17 = _ecl_car(v18);
        {
         cl_object v21;
         v21 = _ecl_cdr(v18);
         if (ecl_unlikely(!ECL_LISTP(v21))) FEtype_error_list(v21);
         v18 = v21;
        }
        if (ecl_unlikely(ECL_ATOM(v20))) FEtype_error_cons(v20);
        T1 = v20;
        T2 = cl_list(2, v14, v17);
        v20 = ecl_list1(T2);
        (ECL_CONS_CDR(T1)=v20,T1);
        goto L26;
L27:;
        T0 = ecl_cdr(v19);
        goto L15;
       }
      }
     }
L15:;
     T1 = CONS(VV[8],v6);
     T2 = cl_list(2, ECL_SYM("DECLARE",274), T1);
     T3 = cl_list(3, VV[9], v12saved_place, ECL_SYM("LIST",481));
     T4 = cl_list(2, VV[5], v12saved_place);
     T5 = cl_list(2, v11store_var, T4);
     T6 = ecl_list1(T5);
     T7 = cl_list(2, VV[8], v11store_var);
     T8 = cl_list(2, ECL_SYM("DECLARE",274), T7);
     T9 = cl_list(2, VV[3], v12saved_place);
     T10 = cl_list(3, ECL_SYM("SETQ",751), v12saved_place, T9);
     T11 = cl_list(5, ECL_SYM("LET",477), T6, T8, v9, T10);
     T12 = cl_list(3, ECL_SYM("WHEN",905), v12saved_place, T11);
     value0 = cl_list(6, ECL_SYM("LET*",478), T0, T2, T3, T12, v12saved_place);
     return value0;
    }
   }
L10:;
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}

#include "cmp/cmpopt-cons.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclb7l3yuLt5Sym9_2A0UOE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPOPT-CONS.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclb7l3yuLt5Sym9_2A0UOE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[10]);                           /*  EXPAND-SIMPLE-OPTIMIZER */
 ecl_cmp_defun(VV[12]);                           /*  SIMPLE-OPTIMIZER-FUNCTION */
 ecl_cmp_defmacro(VV[14]);                        /*  CONS-CAR        */
 ecl_cmp_defmacro(VV[15]);                        /*  CONS-CDR        */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC8cons,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("CONS",251), ECL_SYM("COMPILER-MACRO",238), T0);
 }
 ecl_cmp_defmacro(VV[16]);                        /*  DEFINE-SIMPLE-OPTIMIZER */
 L4simple_optimizer_function(ECL_SYM("RPLACA",732), VVtemp[0], VVtemp[1]);
 L4simple_optimizer_function(ECL_SYM("RPLACD",733), VVtemp[0], VVtemp[2]);
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC10nth,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("NTH",602), ECL_SYM("COMPILER-MACRO",238), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC11nthcdr,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("NTHCDR",604), ECL_SYM("COMPILER-MACRO",238), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC12first,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("FIRST",371), ECL_SYM("COMPILER-MACRO",238), T0);
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC13second,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("SECOND",740), ECL_SYM("COMPILER-MACRO",238), T0);
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC14third,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("THIRD",857), ECL_SYM("COMPILER-MACRO",238), T0);
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC15fourth,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("FOURTH",389), ECL_SYM("COMPILER-MACRO",238), T0);
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC16fifth,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("FIFTH",351), ECL_SYM("COMPILER-MACRO",238), T0);
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC17sixth,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("SIXTH",782), ECL_SYM("COMPILER-MACRO",238), T0);
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC18seventh,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("SEVENTH",752), ECL_SYM("COMPILER-MACRO",238), T0);
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC19eighth,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("EIGHTH",326), ECL_SYM("COMPILER-MACRO",238), T0);
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC20ninth,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("NINTH",583), ECL_SYM("COMPILER-MACRO",238), T0);
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC21tenth,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("TENTH",854), ECL_SYM("COMPILER-MACRO",238), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC22rest,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("REST",719), ECL_SYM("COMPILER-MACRO",238), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC23pop,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("POP",643), ECL_SYM("COMPILER-MACRO",238), T0);
 }
}
