/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPMAC.LSP                                    */
#include <ecl/ecl-cmp.h>
#include "cmp/cmpmac.eclh"
/*	local function DEFUN-CACHED                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC1defun_cached(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4name;
   cl_object v5lambda_list;
   cl_object v6test;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v7;
    v7 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4name = v7;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v7;
    v7 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5lambda_list = v7;
   }
   if (!(v3==ECL_NIL)) { goto L15; }
   si_dm_too_few_arguments(v1);
L15:;
   {
    cl_object v7;
    v7 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v6test = v7;
   }
   {
    cl_object v7cache_name;
    cl_object v8reset_name;
    cl_object v9hash_function;
    T0 = cl_string(v4name);
    T1 = cl_concatenate(4, ECL_SYM("STRING",805), _ecl_static_1, T0, _ecl_static_2);
    T2 = cl_symbol_package(v4name);
    v7cache_name = cl_intern(2, T1, T2);
    T0 = cl_string(v4name);
    T1 = cl_concatenate(3, ECL_SYM("STRING",805), T0, _ecl_static_3);
    T2 = cl_symbol_package(v4name);
    v8reset_name = cl_intern(2, T1, T2);
    {
     cl_object v10;
     v10 = v6test;
     if (!((v10)==(ECL_SYM("EQ",333)))) { goto L24; }
     v9hash_function = VV[2];
     goto L22;
L24:;
     if (!((v10)==(ECL_SYM("EQL",334)))) { goto L26; }
     v9hash_function = ECL_SYM("HASH-EQL",1660);
     goto L22;
L26:;
     if (!((v10)==(ECL_SYM("EQUAL",335)))) { goto L28; }
     v9hash_function = ECL_SYM("HASH-EQUAL",1661);
     goto L22;
L28:;
     v6test = ECL_SYM("EQUALP",336);
     v9hash_function = ECL_SYM("HASH-EQUALP",1662);
    }
L22:;
    T0 = cl_list(3, ECL_SYM("DEFPARAMETER",285), v7cache_name, VV[4]);
    T1 = cl_list(3, ECL_SYM("EVAL-WHEN",340), VV[3], T0);
    T2 = cl_listX(3, ECL_SYM("DEFUN",289), v8reset_name, VV[5]);
    T3 = cl_listX(3, v4name, v5lambda_list, v3);
    T4 = ecl_list1(T3);
    T5 = CONS(v9hash_function,v5lambda_list);
    T6 = cl_list(3, ECL_SYM("LOGAND",492), T5, ecl_make_fixnum(1023));
    T7 = cl_list(2, VV[6], T6);
    T8 = cl_list(3, ECL_SYM("AREF",92), v7cache_name, VV[6]);
    T9 = cl_list(2, ECL_SYM("ELT",327), T8);
    T10 = cl_list(2, T7, T9);
    T11 = cl_list(3, ECL_SYM("TYPE",869), VV[8], v7cache_name);
    T12 = cl_list(3, ECL_SYM("DECLARE",274), VV[7], T11);
    {
     cl_object v10arg;
     cl_object v11;
     v10arg = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v5lambda_list))) FEtype_error_list(v5lambda_list);
     v11 = v5lambda_list;
     {
      cl_object v12;
      cl_object v13;
      v12 = ecl_list1(ECL_NIL);
      v13 = v12;
L38:;
      if (!(ecl_endp(v11))) { goto L40; }
      goto L39;
L40:;
      v10arg = _ecl_car(v11);
      {
       cl_object v14;
       v14 = _ecl_cdr(v11);
       if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
       v11 = v14;
      }
      if (ecl_unlikely(ECL_ATOM(v13))) FEtype_error_cons(v13);
      T14 = v13;
      T15 = cl_list(3, v6test, VV[9], v10arg);
      v13 = ecl_list1(T15);
      (ECL_CONS_CDR(T14)=v13,T14);
      goto L38;
L39:;
      T13 = ecl_cdr(v12);
      goto L32;
     }
    }
L32:;
    T14 = cl_listX(3, ECL_SYM("AND",87), ECL_SYM("ELT",327), T13);
    T15 = CONS(v4name,v5lambda_list);
    T16 = cl_list(2, VV[11], T15);
    T17 = ecl_list1(T16);
    T18 = cl_list(3, ECL_SYM("AREF",92), v7cache_name, VV[6]);
    T19 = ecl_append(v5lambda_list,VV[12]);
    T20 = CONS(ECL_SYM("LIST",481),T19);
    T21 = cl_list(3, ECL_SYM("SETF",750), T18, T20);
    T22 = cl_list(4, ECL_SYM("LET",477), T17, T21, VV[11]);
    T23 = cl_list(4, ECL_SYM("IF",946), T14, VV[10], T22);
    T24 = cl_list(4, ECL_SYM("LET*",478), T10, T12, T23);
    T25 = cl_list(3, ECL_SYM("FLET",373), T4, T24);
    T26 = cl_list(4, ECL_SYM("DEFUN",289), v4name, v5lambda_list, T25);
    value0 = cl_list(4, ECL_SYM("PROGN",671), T1, T2, T26);
    return value0;
   }
  }
 }
}
/*	local function DEFUN-EQUAL-CACHED                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC2defun_equal_cached(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4name;
   cl_object v5lambda_list;
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
    v5lambda_list = v6;
   }
   value0 = cl_listX(5, VV[13], v4name, v5lambda_list, ECL_SYM("EQUAL",335), v3);
   return value0;
  }
 }
}
/*	function definition for ENV-VAR-NAME-EMPTY-CACHE              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3env_var_name_empty_cache()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = si_make_vector(ECL_T, ecl_make_fixnum(1024), ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
  return value0;
 }
}
/*	function definition for ENV-VAR-NAME                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5env_var_name(cl_object v1n)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v2hash;
   cl_object v3elt;
   {
    cl_object v4;
    T0 = si_hash_eql(1, v1n);
    v4 = ecl_boole(ECL_BOOLAND,(T0),(ecl_make_fixnum(1023)));
    {
     cl_fixnum v5;
     v5 = 0;
     if (!(ECL_FIXNUMP(v4))) { goto L7; }
     v5 = ecl_fixnum(v4);
     if (!((v5)<=(1023))) { goto L12; }
     T0 = ecl_make_bool((v5)>=(0));
     goto L4;
L12:;
     T0 = ECL_NIL;
     goto L4;
L7:;
     T0 = ECL_NIL;
     goto L4;
    }
L4:;
    if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[17],v4);
    v2hash = ecl_fixnum(v4);
   }
   {
    cl_object v4;
    v4 = ecl_symbol_value(VV[15]);
    {
     cl_fixnum v5;
     if (ecl_unlikely((v2hash)>=(v4)->vector.dim))
           FEwrong_index(ECL_NIL,v4,-1,ecl_make_fixnum(v2hash),(v4)->vector.dim);
     v5 = v2hash;
     v3elt = ecl_aref_unsafe(v4,v5);
    }
   }
   if (Null(v3elt)) { goto L19; }
   {
    cl_object v4;
    if (ecl_unlikely(ECL_ATOM(v3elt))) FEtype_error_cons(v3elt);
    v4 = v3elt;
    if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
    if (Null(v4)) { goto L27; }
    {
     cl_object v5;
     v5 = ECL_CONS_CDR(v4);
     if (ecl_unlikely(ECL_ATOM(v5))) FEtype_error_cons(v5);
     v3elt = v5;
     v4 = ECL_CONS_CAR(v4);
    }
L27:;
    T0 = v4;
   }
   if (!(ecl_eql(T0,v1n))) { goto L19; }
   value0 = ecl_car(v3elt);
   cl_env_copy->nvalues = 1;
   return value0;
L19:;
   {
    cl_object v4output;
    v4output = LC4env_var_name(v1n);
    {
     cl_object v5;
     v5 = ecl_symbol_value(VV[15]);
     {
      cl_fixnum v6;
      if (ecl_unlikely((v2hash)>=(v5)->vector.dim))
           FEwrong_index(ECL_NIL,v5,-1,ecl_make_fixnum(v2hash),(v5)->vector.dim);
      v6 = v2hash;
      T0 = cl_list(2, v1n, v4output);
      ecl_aset_unsafe(v5,v6,T0);
     }
    }
    value0 = v4output;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	local function ENV-VAR-NAME                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC4env_var_name(cl_object v1n)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_format(3, ECL_NIL, _ecl_static_4, v1n);
  return value0;
 }
}
/*	function definition for LEX-ENV-VAR-NAME-EMPTY-CACHE          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6lex_env_var_name_empty_cache()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = si_make_vector(ECL_T, ecl_make_fixnum(1024), ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
  return value0;
 }
}
/*	function definition for LEX-ENV-VAR-NAME                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8lex_env_var_name(cl_object v1n)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v2hash;
   cl_object v3elt;
   {
    cl_object v4;
    T0 = si_hash_eql(1, v1n);
    v4 = ecl_boole(ECL_BOOLAND,(T0),(ecl_make_fixnum(1023)));
    {
     cl_fixnum v5;
     v5 = 0;
     if (!(ECL_FIXNUMP(v4))) { goto L7; }
     v5 = ecl_fixnum(v4);
     if (!((v5)<=(1023))) { goto L12; }
     T0 = ecl_make_bool((v5)>=(0));
     goto L4;
L12:;
     T0 = ECL_NIL;
     goto L4;
L7:;
     T0 = ECL_NIL;
     goto L4;
    }
L4:;
    if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[17],v4);
    v2hash = ecl_fixnum(v4);
   }
   {
    cl_object v4;
    v4 = ecl_symbol_value(VV[19]);
    {
     cl_fixnum v5;
     if (ecl_unlikely((v2hash)>=(v4)->vector.dim))
           FEwrong_index(ECL_NIL,v4,-1,ecl_make_fixnum(v2hash),(v4)->vector.dim);
     v5 = v2hash;
     v3elt = ecl_aref_unsafe(v4,v5);
    }
   }
   if (Null(v3elt)) { goto L19; }
   {
    cl_object v4;
    if (ecl_unlikely(ECL_ATOM(v3elt))) FEtype_error_cons(v3elt);
    v4 = v3elt;
    if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
    if (Null(v4)) { goto L27; }
    {
     cl_object v5;
     v5 = ECL_CONS_CDR(v4);
     if (ecl_unlikely(ECL_ATOM(v5))) FEtype_error_cons(v5);
     v3elt = v5;
     v4 = ECL_CONS_CAR(v4);
    }
L27:;
    T0 = v4;
   }
   if (!(ecl_eql(T0,v1n))) { goto L19; }
   value0 = ecl_car(v3elt);
   cl_env_copy->nvalues = 1;
   return value0;
L19:;
   {
    cl_object v4output;
    v4output = LC7lex_env_var_name(v1n);
    {
     cl_object v5;
     v5 = ecl_symbol_value(VV[19]);
     {
      cl_fixnum v6;
      if (ecl_unlikely((v2hash)>=(v5)->vector.dim))
           FEwrong_index(ECL_NIL,v5,-1,ecl_make_fixnum(v2hash),(v5)->vector.dim);
      v6 = v2hash;
      T0 = cl_list(2, v1n, v4output);
      ecl_aset_unsafe(v5,v6,T0);
     }
    }
    value0 = v4output;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	local function LEX-ENV-VAR-NAME                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC7lex_env_var_name(cl_object v1n)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_format(3, ECL_NIL, _ecl_static_5, v1n);
  return value0;
 }
}
/*	function definition for SAME-FNAME-P                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L9same_fname_p(cl_object v1name1, cl_object v2name2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_make_bool(ecl_equal(v1name1,v2name2));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function NEXT-CMACRO                                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC10next_cmacro(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_cdr(v1);
   if (Null(v3)) { goto L2; }
   si_dm_too_many_arguments(v1);
L2:;
   value0 = VV[23];
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for NEXT-LABEL                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L11next_label()
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  cl_set(VV[25],ecl_plus(ecl_symbol_value(VV[25]),ecl_make_fixnum(1)));
  T0 = ecl_symbol_value(VV[25]);
  value0 = CONS(T0,ECL_NIL);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for NEXT-LABEL*                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L12next_label_()
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  cl_set(VV[25],ecl_plus(ecl_symbol_value(VV[25]),ecl_make_fixnum(1)));
  T0 = ecl_symbol_value(VV[25]);
  value0 = CONS(T0,ECL_T);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for LABELP                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L13labelp(cl_object v1x)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_CONSP(v1x))) { goto L2; }
  T0 = _ecl_car(v1x);
  value0 = ecl_make_bool(ECL_FIXNUMP(T0)||ECL_BIGNUMP(T0));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for MAYBE-NEXT-LABEL                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L14maybe_next_label()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(L13labelp(ecl_symbol_value(VV[29])))) { goto L1; }
  value0 = ecl_symbol_value(VV[29]);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  value0 = L11next_label();
  return value0;
 }
}
/*	function definition for MAYBE-WT-LABEL                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L15maybe_wt_label(cl_object v1label)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((v1label)==(ecl_symbol_value(VV[29]))) { goto L1; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[34])(1, v1label) /*  WT-LABEL */;
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function WITH-EXIT-LABEL                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC16with_exit_label(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6label;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v7;
    v7 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4 = v7;
   }
   v5 = v4;
   if (!(v5==ECL_NIL)) { goto L10; }
   si_dm_too_few_arguments(v1);
L10:;
   {
    cl_object v7;
    v7 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v6label = v7;
   }
   if (Null(v5)) { goto L15; }
   si_dm_too_many_arguments(v1);
L15:;
   T0 = cl_list(2, v6label, VV[32]);
   T1 = cl_list(3, ECL_SYM("CONS",251), v6label, VV[33]);
   T2 = cl_list(2, VV[33], T1);
   T3 = cl_list(2, T0, T2);
   T4 = cl_list(2, VV[34], v6label);
   T5 = ecl_list1(T4);
   T6 = ecl_append(v3,T5);
   value0 = cl_listX(3, ECL_SYM("LET*",478), T3, T6);
   return value0;
  }
 }
}
/*	local function WITH-OPTIONAL-EXIT-LABEL                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC17with_optional_exit_label(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6label;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v7;
    v7 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4 = v7;
   }
   v5 = v4;
   if (!(v5==ECL_NIL)) { goto L10; }
   si_dm_too_few_arguments(v1);
L10:;
   {
    cl_object v7;
    v7 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v6label = v7;
   }
   if (Null(v5)) { goto L15; }
   si_dm_too_many_arguments(v1);
L15:;
   T0 = cl_list(2, v6label, VV[36]);
   T1 = cl_list(3, ECL_SYM("ADJOIN",82), v6label, VV[33]);
   T2 = cl_list(2, VV[33], T1);
   T3 = cl_list(2, T0, T2);
   T4 = cl_list(2, VV[31], v6label);
   T5 = ecl_list1(T4);
   T6 = ecl_append(v3,T5);
   value0 = cl_listX(3, ECL_SYM("LET*",478), T3, T6);
   return value0;
  }
 }
}
/*	function definition for NEXT-LCL                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L18next_lcl(cl_narg narg, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1name;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1name = ECL_NIL;
   } else {
    i++;
    v1name = va_arg(args,cl_object);
   }
  }
  va_end(args);
  cl_set(VV[39],ecl_plus(ecl_symbol_value(VV[39]),ecl_make_fixnum(1)));
  T0 = ecl_symbol_value(VV[39]);
  if (Null(v1name)) { goto L5; }
  if (Null(cl_symbol_package(v1name))) { goto L5; }
  T1 = ecl_function_dispatch(cl_env_copy,VV[71])(1, v1name) /*  LISP-TO-C-NAME */;
  goto L4;
L5:;
  T1 = _ecl_static_6;
L4:;
  value0 = cl_list(4, VV[38], T0, ECL_T, T1);
  return value0;
 }
}
/*	function definition for NEXT-CFUN                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L19next_cfun(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v1prefix;
  cl_object v2lisp_name;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1prefix = _ecl_static_7;
   } else {
    i++;
    v1prefix = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v2lisp_name = ECL_NIL;
   } else {
    i++;
    v2lisp_name = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v3code;
   cl_set(VV[41],ecl_plus(ecl_symbol_value(VV[41]),ecl_make_fixnum(1)));
   v3code = ecl_symbol_value(VV[41]);
   T0 = ecl_function_dispatch(cl_env_copy,VV[71])(1, v2lisp_name) /*  LISP-TO-C-NAME */;
   value0 = cl_format(4, ECL_NIL, v1prefix, v3code, T0);
   return value0;
  }
 }
}
/*	function definition for NEXT-TEMP                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L20next_temp()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v1;
   v1 = ecl_symbol_value(VV[43]);
   cl_set(VV[43],ecl_plus(ecl_symbol_value(VV[43]),ecl_make_fixnum(1)));
   cl_set(VV[44],(ecl_number_compare(ecl_symbol_value(VV[43]),ecl_symbol_value(VV[44]))>=0?ecl_symbol_value(VV[43]):ecl_symbol_value(VV[44])));
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for NEXT-LEX                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L21next_lex()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v1;
   v1 = CONS(ecl_symbol_value(VV[46]),ecl_symbol_value(VV[47]));
   cl_set(VV[47],ecl_plus(ecl_symbol_value(VV[47]),ecl_make_fixnum(1)));
   cl_set(VV[48],(ecl_number_compare(ecl_symbol_value(VV[47]),ecl_symbol_value(VV[48]))>=0?ecl_symbol_value(VV[47]):ecl_symbol_value(VV[48])));
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for NEXT-ENV                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L22next_env()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v1;
   v1 = ecl_symbol_value(VV[50]);
   cl_set(VV[50],ecl_plus(ecl_symbol_value(VV[50]),ecl_make_fixnum(1)));
   cl_set(VV[51],(ecl_number_compare(ecl_symbol_value(VV[50]),ecl_symbol_value(VV[51]))>=0?ecl_symbol_value(VV[50]):ecl_symbol_value(VV[51])));
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function RECKLESS                                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC23reckless(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_cdr(v1);
   value0 = cl_listX(3, ECL_SYM("LOCALLY",490), VV[53], v3);
   return value0;
  }
 }
}

#include "cmp/cmpmac.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclO3wz0HirQK3l9_5hotVE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPMAC.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclO3wz0HirQK3l9_5hotVE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 cl_import(2, VV[0], _ecl_static_0);
 cl_import(2, VV[1], _ecl_static_0);
 ecl_cmp_defmacro(VV[55]);                        /*  DEFUN-CACHED    */
 ecl_cmp_defmacro(VV[56]);                        /*  DEFUN-EQUAL-CACHED */
 si_Xmake_special(VV[15]);
 cl_set(VV[15],si_make_vector(ECL_T, ecl_make_fixnum(1024), ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0)));
 ecl_cmp_defun(VV[57]);                           /*  ENV-VAR-NAME-EMPTY-CACHE */
 ecl_cmp_defun(VV[58]);                           /*  ENV-VAR-NAME    */
 si_Xmake_special(VV[19]);
 cl_set(VV[19],si_make_vector(ECL_T, ecl_make_fixnum(1024), ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0)));
 ecl_cmp_defun(VV[59]);                           /*  LEX-ENV-VAR-NAME-EMPTY-CACHE */
 ecl_cmp_defun(VV[60]);                           /*  LEX-ENV-VAR-NAME */
 ecl_cmp_defun(VV[61]);                           /*  SAME-FNAME-P    */
 ecl_cmp_defmacro(VV[62]);                        /*  NEXT-CMACRO     */
 ecl_cmp_defun(VV[63]);                           /*  NEXT-LABEL      */
 ecl_cmp_defun(VV[64]);                           /*  NEXT-LABEL*     */
 ecl_cmp_defun(VV[65]);                           /*  LABELP          */
 ecl_cmp_defun(VV[66]);                           /*  MAYBE-NEXT-LABEL */
 ecl_cmp_defun(VV[67]);                           /*  MAYBE-WT-LABEL  */
 ecl_cmp_defmacro(VV[68]);                        /*  WITH-EXIT-LABEL */
 ecl_cmp_defmacro(VV[69]);                        /*  WITH-OPTIONAL-EXIT-LABEL */
 ecl_cmp_defun(VV[70]);                           /*  NEXT-LCL        */
 ecl_cmp_defun(VV[72]);                           /*  NEXT-CFUN       */
 ecl_cmp_defun(VV[73]);                           /*  NEXT-TEMP       */
 ecl_cmp_defun(VV[74]);                           /*  NEXT-LEX        */
 ecl_cmp_defun(VV[75]);                           /*  NEXT-ENV        */
 ecl_cmp_defmacro(VV[76]);                        /*  RECKLESS        */
}
