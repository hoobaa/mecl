/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPNUM.LSP                                    */
#include <ecl/ecl-cmp.h>
#include "cmp/cmpnum.eclh"
/*	function definition for SIMPLIFY-ARITHMETIC                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1simplify_arithmetic(cl_object v1operator, cl_object v2args, cl_object v3whole)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = (ECL_SYM("NUMBERP",607)->symbol.gfdef);
  if (Null(cl_every(2, T0, v2args))) { goto L1; }
  value0 = cl_apply(2, v1operator, v2args);
  return value0;
L1:;
  {
   cl_fixnum v4l;
   v4l = ecl_length(v2args);
   if (!((v4l)>(2))) { goto L5; }
   {
    cl_object v5;
    v5 = v1operator;
    T0 = ecl_car(v2args);
    T1 = ecl_cadr(v2args);
    T2 = cl_list(2, T0, T1);
    T3 = L1simplify_arithmetic(v1operator, T2, ECL_NIL);
    T4 = ecl_cddr(v2args);
    v2args = CONS(T3,T4);
    v3whole = ECL_NIL;
    v1operator = v5;
   }
   goto TTL;
L5:;
   if (!((v4l)==(2))) { goto L11; }
   value0 = v3whole;
   if ((value0)!=ECL_NIL) { goto L14; }
   value0 = CONS(v1operator,v2args);
   cl_env_copy->nvalues = 1;
   return value0;
L14:;
   cl_env_copy->nvalues = 1;
   return value0;
L11:;
   if (!((v4l)==(1))) { goto L16; }
   if ((v1operator)==(ECL_SYM("*",18))) { goto L20; }
   if (!((v1operator)==(ECL_SYM("+",14)))) { goto L18; }
   goto L19;
L20:;
L19:;
   value0 = ecl_car(v2args);
   cl_env_copy->nvalues = 1;
   return value0;
L18:;
   value0 = v3whole;
   if ((value0)!=ECL_NIL) { goto L23; }
   value0 = CONS(v1operator,v2args);
   cl_env_copy->nvalues = 1;
   return value0;
L23:;
   cl_env_copy->nvalues = 1;
   return value0;
L16:;
   if (!((v1operator)==(ECL_SYM("*",18)))) { goto L25; }
   value0 = ecl_make_fixnum(1);
   cl_env_copy->nvalues = 1;
   return value0;
L25:;
   if (!((v1operator)==(ECL_SYM("+",14)))) { goto L27; }
   value0 = ecl_make_fixnum(0);
   cl_env_copy->nvalues = 1;
   return value0;
L27:;
   value0 = v3whole;
   if ((value0)!=ECL_NIL) { goto L31; }
   T0 = CONS(v1operator,v2args);
   goto L29;
L31:;
   T0 = value0;
   goto L29;
L29:;
   T1 = cl_list(2, v1operator, T0);
   value0 = cl_error(5, VV[0], VV[1], _ecl_static_1, ECL_SYM("FORMAT-ARGUMENTS",1239), T1);
   return value0;
  }
 }
}
/*	local function *                                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC2_(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_cdr(v1);
   value0 = L1simplify_arithmetic(ECL_SYM("*",18), v3, v1);
   return value0;
  }
 }
}
/*	local function +                                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC3_(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_cdr(v1);
   value0 = L1simplify_arithmetic(ECL_SYM("+",14), v3, v1);
   return value0;
  }
 }
}
/*	local function /                                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC4_(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_cdr(v1);
   value0 = L1simplify_arithmetic(ECL_SYM("/",21), v3, v1);
   return value0;
  }
 }
}
/*	local function -                                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC5_(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_cdr(v1);
   value0 = L1simplify_arithmetic(ECL_SYM("-",17), v3, v1);
   return value0;
  }
 }
}
/*	function definition for MAXIMUM-NUMBER-TYPE                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6maximum_number_type(cl_narg narg, cl_object v1t1, cl_object v2t2, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3only_real;
  cl_object v4integer_result;
  ecl_va_list args; ecl_va_start(args,v2t2,narg,2);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L6maximum_number_typekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3only_real = keyvars[0];
   v4integer_result = keyvars[1];
  }
  {
   cl_object v5;
   cl_object v6;
   cl_object v7t1_eq;
   cl_object v8t2_eq;
   cl_object v9output;
   if (Null(v3only_real)) { goto L2; }
   v5 = ECL_SYM("REAL",703);
   goto L1;
L2:;
   v5 = ECL_SYM("NUMBER",606);
L1:;
   if (Null(v3only_real)) { goto L5; }
   v6 = VV[3];
   goto L4;
L5:;
   v6 = VV[4];
L4:;
   v7t1_eq = ECL_NIL;
   v8t2_eq = ECL_NIL;
   v9output = ECL_NIL;
   {
    cl_object v10;
    v10 = v6;
    goto L14;
L13:;
    {
     cl_object v11i;
     v11i = ecl_car(v10);
     if (!(v7t1_eq==ECL_NIL)) { goto L18; }
     if (Null(ecl_function_dispatch(cl_env_copy,VV[30])(2, v11i, v1t1) /*  TYPE>= */)) { goto L18; }
     if (!(ecl_equalp(v1t1,v2t2))) { goto L21; }
     v8t2_eq = v11i;
L21:;
     v7t1_eq = v11i;
     v9output = v11i;
L18:;
     if (!(v8t2_eq==ECL_NIL)) { goto L27; }
     if (Null(ecl_function_dispatch(cl_env_copy,VV[30])(2, v11i, v2t2) /*  TYPE>= */)) { goto L27; }
     v8t2_eq = v11i;
     v9output = v11i;
L27:;
    }
    v10 = ecl_cdr(v10);
L14:;
    if (Null(v10)) { goto L35; }
    goto L13;
L35:;
   }
   if (Null(v7t1_eq)) { goto L40; }
   if (Null(v8t2_eq)) { goto L40; }
   if ((v9output)!=ECL_NIL) { goto L37; }
   goto L38;
L40:;
   goto L38;
L38:;
   v9output = v5;
L37:;
   if (Null(v4integer_result)) { goto L44; }
   if ((v9output)==(ECL_SYM("FIXNUM",372))) { goto L47; }
   if (!((v9output)==(ECL_SYM("INTEGER",437)))) { goto L44; }
   goto L45;
L47:;
L45:;
   v9output = v4integer_result;
L44:;
   if (Null(v7t1_eq)) { goto L51; }
   T0 = v1t1;
   goto L50;
L51:;
   T0 = v5;
L50:;
   if (Null(v8t2_eq)) { goto L54; }
   T1 = v2t2;
   goto L53;
L54:;
   T1 = v5;
L53:;
   cl_env_copy->nvalues = 3;
   cl_env_copy->values[2] = T1;
   cl_env_copy->values[1] = T0;
   cl_env_copy->values[0] = v9output;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for ENSURE-NUMBER-TYPE                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7ensure_number_type(cl_object v1general_type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L6maximum_number_type(2, v1general_type, v1general_type);
  return value0;
 }
}
/*	function definition for ENSURE-NONRATIONAL-TYPE               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8ensure_nonrational_type(cl_object v1general_type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L6maximum_number_type(2, v1general_type, ECL_SYM("SINGLE-FLOAT",778));
  return value0;
 }
}
/*	function definition for ENSURE-REAL-TYPE                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L9ensure_real_type(cl_object v1general_type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L6maximum_number_type(4, v1general_type, ECL_SYM("INTEGER",437), VV[8], ECL_T);
  return value0;
 }
}
/*	function definition for ARITHMETIC-PROPAGATOR                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L10arithmetic_propagator(cl_object v1op1_type, cl_object v2others, cl_object v3integer_result)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v5;                                  /*  RESULT-TYPE     */
   cl_object v6;                                  /*  OP1-TYPE        */
   value0 = L7ensure_number_type(v1op1_type);
   v5 = value0;
   {
    const int v7 = cl_env_copy->nvalues;
    cl_object v8;
    v8 = (v7<=1)? ECL_NIL : cl_env_copy->values[1];
    v6 = v8;
   }
   {
    cl_object v7arg_types;
    v7arg_types = ecl_list1(v6);
    {
     cl_object v8x;
     cl_object v9;
     v8x = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v2others))) FEtype_error_list(v2others);
     v9 = v2others;
     {
      cl_object v10op2_type;
      v10op2_type = ECL_NIL;
L7:;
      if (!(ecl_endp(v9))) { goto L9; }
      goto L8;
L9:;
      v8x = _ecl_car(v9);
      {
       cl_object v11;
       v11 = _ecl_cdr(v9);
       if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
       v9 = v11;
      }
      v10op2_type = v8x;
      value0 = L6maximum_number_type(4, v5, v10op2_type, VV[10], v3integer_result);
      v5 = value0;
      {
       const int v11 = cl_env_copy->nvalues;
       cl_object v12;
       v12 = (v11<=1)? ECL_NIL : cl_env_copy->values[1];
       v6 = v12;
       v12 = (v11<=2)? ECL_NIL : cl_env_copy->values[2];
       v10op2_type = v12;
      }
      v7arg_types = CONS(v10op2_type,v7arg_types);
      goto L7;
L8:;
      T0 = cl_nreverse(v7arg_types);
      cl_env_copy->nvalues = 2;
      cl_env_copy->values[1] = v5;
      cl_env_copy->values[0] = T0;
      return cl_env_copy->values[0];
     }
    }
   }
  }
 }
}
/*	local function G34                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC11__g34(cl_narg narg, cl_object v1fname, cl_object v2op1, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3others;
  ecl_va_list args; ecl_va_start(args,v2op1,narg,2);
  v3others = cl_grab_rest_args(args);
  ecl_va_end(args);
  value0 = L10arithmetic_propagator(v2op1, v3others, ECL_SYM("INTEGER",437));
  return value0;
 }
}
/*	local function G38                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC12__g38(cl_narg narg, cl_object v1fname, cl_object v2op1, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3others;
  ecl_va_list args; ecl_va_start(args,v2op1,narg,2);
  v3others = cl_grab_rest_args(args);
  ecl_va_end(args);
  value0 = L10arithmetic_propagator(v2op1, v3others, ECL_SYM("RATIONAL",687));
  return value0;
 }
}
/*	function definition for INLINE-BINOP                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L13inline_binop(cl_object v1expected_type, cl_object v2arg1, cl_object v3arg2, cl_object v4integer_result_type, cl_object v5consing, cl_object v6non_consing)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[37])(0) /*  POLICY-ASSUME-RIGHT-TYPE */)) { goto L1; }
  if (Null(ecl_function_dispatch(cl_env_copy,VV[38])(1, v1expected_type) /*  C-NUMBER-TYPE-P */)) { goto L1; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[39])(1, v2arg1) /*  INLINED-ARG-TYPE */;
  if (Null(ecl_function_dispatch(cl_env_copy,VV[38])(1, T0) /*  C-NUMBER-TYPE-P */)) { goto L1; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[39])(1, v3arg2) /*  INLINED-ARG-TYPE */;
  if (Null(ecl_function_dispatch(cl_env_copy,VV[38])(1, T0) /*  C-NUMBER-TYPE-P */)) { goto L1; }
  T0 = cl_list(2, v2arg1, v3arg2);
  T1 = ecl_function_dispatch(cl_env_copy,VV[39])(1, v2arg1) /*  INLINED-ARG-TYPE */;
  T2 = ecl_function_dispatch(cl_env_copy,VV[40])(1, T1) /*  LISP-TYPE->REP-TYPE */;
  T3 = ecl_function_dispatch(cl_env_copy,VV[39])(1, v3arg2) /*  INLINED-ARG-TYPE */;
  T4 = ecl_function_dispatch(cl_env_copy,VV[40])(1, T3) /*  LISP-TYPE->REP-TYPE */;
  T5 = cl_list(2, T2, T4);
  T6 = ecl_function_dispatch(cl_env_copy,VV[40])(1, v1expected_type) /*  LISP-TYPE->REP-TYPE */;
  T7 = ecl_list1(T6);
  value0 = ecl_function_dispatch(cl_env_copy,VV[41])(6, T0, T5, T7, v6non_consing, ECL_NIL, ECL_T) /*  PRODUCE-INLINE-LOC */;
  return value0;
L1:;
  T0 = cl_list(2, v2arg1, v3arg2);
  value0 = ecl_function_dispatch(cl_env_copy,VV[41])(6, T0, VV[13], VV[14], v5consing, ECL_NIL, ECL_T) /*  PRODUCE-INLINE-LOC */;
  return value0;
 }
}
/*	function definition for INLINE-ARITH-UNOP                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L14inline_arith_unop(cl_object v1expected_type, cl_object v2arg1, cl_object v3consing, cl_object v4non_consing)
{
 cl_object T0, T1, T2, T3, T4, T5;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[37])(0) /*  POLICY-ASSUME-RIGHT-TYPE */)) { goto L1; }
  if (Null(ecl_function_dispatch(cl_env_copy,VV[38])(1, v1expected_type) /*  C-NUMBER-TYPE-P */)) { goto L1; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[39])(1, v2arg1) /*  INLINED-ARG-TYPE */;
  if (Null(ecl_function_dispatch(cl_env_copy,VV[38])(1, T0) /*  C-NUMBER-TYPE-P */)) { goto L1; }
  T0 = ecl_list1(v2arg1);
  T1 = ecl_function_dispatch(cl_env_copy,VV[39])(1, v2arg1) /*  INLINED-ARG-TYPE */;
  T2 = ecl_function_dispatch(cl_env_copy,VV[40])(1, T1) /*  LISP-TYPE->REP-TYPE */;
  T3 = ecl_list1(T2);
  T4 = ecl_function_dispatch(cl_env_copy,VV[40])(1, v1expected_type) /*  LISP-TYPE->REP-TYPE */;
  T5 = ecl_list1(T4);
  value0 = ecl_function_dispatch(cl_env_copy,VV[41])(6, T0, T3, T5, v4non_consing, ECL_NIL, ECL_T) /*  PRODUCE-INLINE-LOC */;
  return value0;
L1:;
  T0 = ecl_list1(v2arg1);
  value0 = ecl_function_dispatch(cl_env_copy,VV[41])(6, T0, VV[13], VV[14], v3consing, ECL_NIL, ECL_T) /*  PRODUCE-INLINE-LOC */;
  return value0;
 }
}
/*	local function G42                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC15__g42(cl_narg narg, cl_object v1return_type, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2arguments;
  ecl_va_list args; ecl_va_start(args,v1return_type,narg,1);
  v2arguments = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v3arg1;
   v3arg1 = ECL_NIL;
   if (!(v2arguments==ECL_NIL)) { goto L2; }
   value0 = VV[18];
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
   {
    cl_object v4;
    v4 = v2arguments;
    if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
    if (Null(v4)) { goto L9; }
    {
     cl_object v5;
     v5 = ECL_CONS_CDR(v4);
     v2arguments = v5;
     v4 = ECL_CONS_CAR(v4);
    }
L9:;
    v3arg1 = v4;
   }
   if (!(v2arguments==ECL_NIL)) { goto L15; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[43])(1, v3arg1) /*  INLINED-ARG-LOC */;
   return value0;
L15:;
   {
    cl_object v4arg2;
    v4arg2 = ECL_NIL;
    {
     cl_object v5result;
     v5result = ECL_NIL;
L19:;
     {
      cl_object v6;
      v6 = v2arguments;
      if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
      if (Null(v6)) { goto L25; }
      {
       cl_object v7;
       v7 = ECL_CONS_CDR(v6);
       v2arguments = v7;
       v6 = ECL_CONS_CAR(v6);
      }
L25:;
      v4arg2 = v6;
     }
     v5result = L13inline_binop(v1return_type, v3arg1, v4arg2, ECL_SYM("INTEGER",437), _ecl_static_2, _ecl_static_3);
     if (Null(v2arguments)) { goto L34; }
     v3arg1 = ecl_function_dispatch(cl_env_copy,VV[44])(1, v5result) /*  SAVE-INLINE-LOC */;
     goto L33;
L34:;
     value0 = v5result;
     cl_env_copy->nvalues = 1;
     return value0;
L33:;
     goto L19;
    }
   }
  }
 }
}
/*	local function G52                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC16__g52(cl_narg narg, cl_object v1return_type, cl_object v2arg1, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3arguments;
  ecl_va_list args; ecl_va_start(args,v2arg1,narg,2);
  v3arguments = cl_grab_rest_args(args);
  ecl_va_end(args);
  if (!(v3arguments==ECL_NIL)) { goto L1; }
  value0 = L14inline_arith_unop(v1return_type, v2arg1, _ecl_static_4, _ecl_static_5);
  return value0;
L1:;
  {
   cl_object v4arg2;
   v4arg2 = ECL_NIL;
   {
    cl_object v5result;
    v5result = ECL_NIL;
L5:;
    {
     cl_object v6;
     v6 = v3arguments;
     if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
     if (Null(v6)) { goto L11; }
     {
      cl_object v7;
      v7 = ECL_CONS_CDR(v6);
      v3arguments = v7;
      v6 = ECL_CONS_CAR(v6);
     }
L11:;
     v4arg2 = v6;
    }
    v5result = L13inline_binop(v1return_type, v2arg1, v4arg2, ECL_SYM("INTEGER",437), _ecl_static_6, _ecl_static_7);
    if (Null(v3arguments)) { goto L20; }
    v2arg1 = ecl_function_dispatch(cl_env_copy,VV[44])(1, v5result) /*  SAVE-INLINE-LOC */;
    goto L19;
L20:;
    value0 = v5result;
    cl_env_copy->nvalues = 1;
    return value0;
L19:;
    goto L5;
   }
  }
 }
}
/*	local function G59                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC17__g59(cl_narg narg, cl_object v1return_type, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2arguments;
  ecl_va_list args; ecl_va_start(args,v1return_type,narg,1);
  v2arguments = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v3arg1;
   v3arg1 = ECL_NIL;
   if (!(v2arguments==ECL_NIL)) { goto L2; }
   value0 = VV[19];
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
   {
    cl_object v4;
    v4 = v2arguments;
    if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
    if (Null(v4)) { goto L9; }
    {
     cl_object v5;
     v5 = ECL_CONS_CDR(v4);
     v2arguments = v5;
     v4 = ECL_CONS_CAR(v4);
    }
L9:;
    v3arg1 = v4;
   }
   if (!(v2arguments==ECL_NIL)) { goto L15; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[43])(1, v3arg1) /*  INLINED-ARG-LOC */;
   return value0;
L15:;
   {
    cl_object v4arg2;
    v4arg2 = ECL_NIL;
    {
     cl_object v5result;
     v5result = ECL_NIL;
L19:;
     {
      cl_object v6;
      v6 = v2arguments;
      if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
      if (Null(v6)) { goto L25; }
      {
       cl_object v7;
       v7 = ECL_CONS_CDR(v6);
       v2arguments = v7;
       v6 = ECL_CONS_CAR(v6);
      }
L25:;
      v4arg2 = v6;
     }
     v5result = L13inline_binop(v1return_type, v3arg1, v4arg2, ECL_SYM("INTEGER",437), _ecl_static_8, _ecl_static_9);
     if (Null(v2arguments)) { goto L34; }
     v3arg1 = ecl_function_dispatch(cl_env_copy,VV[44])(1, v5result) /*  SAVE-INLINE-LOC */;
     goto L33;
L34:;
     value0 = v5result;
     cl_env_copy->nvalues = 1;
     return value0;
L33:;
     goto L19;
    }
   }
  }
 }
}
/*	local function G69                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC18__g69(cl_narg narg, cl_object v1return_type, cl_object v2arg1, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3arguments;
  ecl_va_list args; ecl_va_start(args,v2arg1,narg,2);
  v3arguments = cl_grab_rest_args(args);
  ecl_va_end(args);
  if (!(v3arguments==ECL_NIL)) { goto L1; }
  value0 = L14inline_arith_unop(v1return_type, v2arg1, _ecl_static_10, _ecl_static_11);
  return value0;
L1:;
  {
   cl_object v4arg2;
   v4arg2 = ECL_NIL;
   {
    cl_object v5result;
    v5result = ECL_NIL;
L5:;
    {
     cl_object v6;
     v6 = v3arguments;
     if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
     if (Null(v6)) { goto L11; }
     {
      cl_object v7;
      v7 = ECL_CONS_CDR(v6);
      v3arguments = v7;
      v6 = ECL_CONS_CAR(v6);
     }
L11:;
     v4arg2 = v6;
    }
    v5result = L13inline_binop(v1return_type, v2arg1, v4arg2, ECL_SYM("RATIONAL",687), _ecl_static_12, _ecl_static_13);
    if (Null(v3arguments)) { goto L20; }
    v2arg1 = ecl_function_dispatch(cl_env_copy,VV[44])(1, v5result) /*  SAVE-INLINE-LOC */;
    goto L19;
L20:;
    value0 = v5result;
    cl_env_copy->nvalues = 1;
    return value0;
L19:;
    goto L5;
   }
  }
 }
}
/*	local function G77                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC19__g77(cl_narg narg, cl_object v1fname, cl_object v2op1_type, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  {
   cl_object v4;                                  /*  OUTPUT-TYPE     */
   cl_object v5;                                  /*  OP1-TYPE        */
   value0 = L8ensure_nonrational_type(v2op1_type);
   v4 = value0;
   {
    const int v6 = cl_env_copy->nvalues;
    cl_object v7;
    v7 = (v6<=1)? ECL_NIL : cl_env_copy->values[1];
    v5 = v7;
   }
   T0 = ecl_list1(v5);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v4;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G82                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC20__g82(cl_narg narg, cl_object v1fname, cl_object v2op1_type, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  {
   cl_object v4;                                  /*  OP1-TYPE        */
   value0 = L8ensure_nonrational_type(v2op1_type);
   {
    const int v5 = cl_env_copy->nvalues;
    cl_object v6;
    v6 = (v5<=1)? ECL_NIL : cl_env_copy->values[1];
    v4 = v6;
   }
   T0 = ecl_list1(v4);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = ECL_SYM("NUMBER",606);
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G87                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC21__g87(cl_narg narg, cl_object v1fname, cl_object v2op1_type, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3op2_type;
  cl_object v4op2_p;
  va_list args; va_start(args,v2op1_type);
  {
   int i = 2;
   if (i >= narg) {
    v3op2_type = ECL_T;
    v4op2_p = ECL_NIL;
   } else {
    i++;
    v3op2_type = va_arg(args,cl_object);
    v4op2_p = ECL_T;
   }
  }
  va_end(args);
  {
   cl_object v6;                                  /*  T1              */
   value0 = L8ensure_nonrational_type(v2op1_type);
   {
    const int v7 = cl_env_copy->nvalues;
    cl_object v8;
    v8 = (v7<=1)? ECL_NIL : cl_env_copy->values[1];
    v6 = v8;
   }
   if (Null(v4op2_p)) { goto L3; }
   {
    cl_object v8;                                 /*  RESULT          */
    cl_object v9;                                 /*  T1              */
    cl_object v10;                                /*  T2              */
    value0 = L6maximum_number_type(4, v6, v3op2_type, VV[8], ECL_T);
    v8 = value0;
    {
     const int v11 = cl_env_copy->nvalues;
     cl_object v12;
     v12 = (v11<=1)? ECL_NIL : cl_env_copy->values[1];
     v9 = v12;
     v12 = (v11<=2)? ECL_NIL : cl_env_copy->values[2];
     v10 = v12;
    }
    T0 = cl_list(2, v9, v10);
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = v8;
    cl_env_copy->values[0] = T0;
    return cl_env_copy->values[0];
   }
L3:;
   T0 = ecl_list1(v6);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v6;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G92                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC22__g92(cl_narg narg, cl_object v1fname, cl_object v2base, cl_object v3exponent, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 {
  {
   cl_object v4exponent;
   v4exponent = L9ensure_real_type(v3exponent);
   T0 = cl_list(2, v2base, v4exponent);
   if (!((v4exponent)==(ECL_SYM("INTEGER",437)))) { goto L3; }
   if (Null(cl_subtypep(2, v2base, ECL_SYM("FIXNUM",372)))) { goto L5; }
   T1 = ECL_SYM("INTEGER",437);
   goto L2;
L5:;
   T1 = v2base;
   goto L2;
L3:;
   if (Null(ecl_function_dispatch(cl_env_copy,VV[30])(2, VV[20], v2base) /*  TYPE>= */)) { goto L7; }
   {
    cl_object v5exponent;
    v5exponent = L8ensure_nonrational_type(v4exponent);
    T1 = L6maximum_number_type(2, v5exponent, v2base);
    goto L2;
   }
L7:;
   T1 = ECL_SYM("NUMBER",606);
L2:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = T1;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G97                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC23__g97(cl_narg narg, cl_object v1fname, cl_object v2arg, ...)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  {
   cl_object v4;                                  /*  OUTPUT          */
   cl_object v5;                                  /*  ARG             */
   value0 = L7ensure_number_type(v2arg);
   v4 = value0;
   {
    const int v6 = cl_env_copy->nvalues;
    cl_object v7;
    v7 = (v6<=1)? ECL_NIL : cl_env_copy->values[1];
    v5 = v7;
   }
   T0 = ecl_list1(v5);
   T2 = ecl_assql(v4,VV[21]);
   value0 = ecl_cdr(T2);
   if ((value0)!=ECL_NIL) { goto L4; }
   T1 = v4;
   goto L2;
L4:;
   T1 = value0;
   goto L2;
L2:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = T1;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G102                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC24__g102(cl_narg narg, cl_object v1fname, cl_object v2arg, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  {
   cl_object v4;                                  /*  OUTPUT          */
   cl_object v5;                                  /*  ARG             */
   value0 = L8ensure_nonrational_type(v2arg);
   v4 = value0;
   {
    const int v6 = cl_env_copy->nvalues;
    cl_object v7;
    v7 = (v6<=1)? ECL_NIL : cl_env_copy->values[1];
    v5 = v7;
   }
   T0 = ecl_list1(v5);
   if (Null(ecl_function_dispatch(cl_env_copy,VV[30])(2, VV[20], v5) /*  TYPE>= */)) { goto L3; }
   T1 = v4;
   goto L2;
L3:;
   T1 = ECL_SYM("NUMBER",606);
L2:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = T1;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G107                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC25__g107(cl_narg narg, cl_object v1fname, cl_object v2arg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  if (Null(ecl_function_dispatch(cl_env_copy,VV[30])(2, VV[22], v2arg) /*  TYPE>= */)) { goto L1; }
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = VV[22];
  cl_env_copy->values[0] = VV[23];
  return cl_env_copy->values[0];
L1:;
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = VV[25];
  cl_env_copy->values[0] = VV[24];
  return cl_env_copy->values[0];
 }
}

#include "cmp/cmpnum.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclDTIWUhX4e14o9_KGrtVE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPNUM.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclDTIWUhX4e14o9_KGrtVE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[26]);                           /*  SIMPLIFY-ARITHMETIC */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC2_,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("*",18), ECL_SYM("COMPILER-MACRO",238), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC3_,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("+",14), ECL_SYM("COMPILER-MACRO",238), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC4_,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("/",21), ECL_SYM("COMPILER-MACRO",238), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC5_,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("-",17), ECL_SYM("COMPILER-MACRO",238), T0);
 }
 ecl_cmp_defun(VV[27]);                           /*  MAXIMUM-NUMBER-TYPE */
 ecl_cmp_defun(VV[31]);                           /*  ENSURE-NUMBER-TYPE */
 ecl_cmp_defun(VV[32]);                           /*  ENSURE-NONRATIONAL-TYPE */
 ecl_cmp_defun(VV[33]);                           /*  ENSURE-REAL-TYPE */
 ecl_cmp_defun(VV[34]);                           /*  ARITHMETIC-PROPAGATOR */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC11__g34,ECL_NIL,Cblock);
  T0 = v1;
 }
 si_hash_set(ECL_SYM("*",18), ecl_symbol_value(VV[12]), T0);
 }
 ecl_function_dispatch(cl_env_copy,VV[35])(2, ECL_SYM("*",18), VVtemp[0]) /*  COPY-TYPE-PROPAGATOR */;
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC12__g38,ECL_NIL,Cblock);
  T0 = v1;
 }
 si_hash_set(ECL_SYM("/",21), ecl_symbol_value(VV[12]), T0);
 }
 ecl_cmp_defun(VV[36]);                           /*  INLINE-BINOP    */
 ecl_cmp_defun(VV[42]);                           /*  INLINE-ARITH-UNOP */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC15__g42,ECL_NIL,Cblock);
  T0 = v1;
 }
 si_hash_set(ECL_SYM("+",14), ecl_symbol_value(VV[17]), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC16__g52,ECL_NIL,Cblock);
  T0 = v1;
 }
 si_hash_set(ECL_SYM("-",17), ecl_symbol_value(VV[17]), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC17__g59,ECL_NIL,Cblock);
  T0 = v1;
 }
 si_hash_set(ECL_SYM("*",18), ecl_symbol_value(VV[17]), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC18__g69,ECL_NIL,Cblock);
  T0 = v1;
 }
 si_hash_set(ECL_SYM("/",21), ecl_symbol_value(VV[17]), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC19__g77,ECL_NIL,Cblock);
  T0 = v1;
 }
 si_hash_set(ECL_SYM("COS",264), ecl_symbol_value(VV[12]), T0);
 }
 ecl_function_dispatch(cl_env_copy,VV[35])(2, ECL_SYM("COS",264), VVtemp[1]) /*  COPY-TYPE-PROPAGATOR */;
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC20__g82,ECL_NIL,Cblock);
  T0 = v1;
 }
 si_hash_set(ECL_SYM("ACOS",80), ecl_symbol_value(VV[12]), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC21__g87,ECL_NIL,Cblock);
  T0 = v1;
 }
 si_hash_set(ECL_SYM("ATAN",117), ecl_symbol_value(VV[12]), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC22__g92,ECL_NIL,Cblock);
  T0 = v1;
 }
 si_hash_set(ECL_SYM("EXPT",345), ecl_symbol_value(VV[12]), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC23__g97,ECL_NIL,Cblock);
  T0 = v1;
 }
 si_hash_set(ECL_SYM("ABS",78), ecl_symbol_value(VV[12]), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC24__g102,ECL_NIL,Cblock);
  T0 = v1;
 }
 si_hash_set(ECL_SYM("SQRT",792), ecl_symbol_value(VV[12]), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC25__g107,ECL_NIL,Cblock);
  T0 = v1;
 }
 si_hash_set(ECL_SYM("ISQRT",448), ecl_symbol_value(VV[12]), T0);
 }
}
