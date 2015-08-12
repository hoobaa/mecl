/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPCALL.LSP                                   */
#include <ecl/ecl-cmp.h>
#include "cmp/cmpcall.eclh"
/*	function definition for UNOPTIMIZED-LONG-CALL                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1unoptimized_long_call(cl_object v1fun, cl_object v2arguments)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3frame;
   v3frame = cl_gensym(0);
   {
    cl_object v4i;
    cl_object v5;
    v4i = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v2arguments))) FEtype_error_list(v2arguments);
    v5 = v2arguments;
    {
     cl_object v6;
     cl_object v7;
     v6 = ecl_list1(ECL_NIL);
     v7 = v6;
L8:;
     if (!(ecl_endp(v5))) { goto L10; }
     goto L9;
L10:;
     v4i = _ecl_car(v5);
     {
      cl_object v8;
      v8 = _ecl_cdr(v5);
      if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
      v5 = v8;
     }
     if (ecl_unlikely(ECL_ATOM(v7))) FEtype_error_cons(v7);
     T1 = v7;
     T2 = cl_list(3, VV[1], v3frame, v4i);
     v7 = ecl_list1(T2);
     (ECL_CONS_CDR(T1)=v7,T1);
     goto L8;
L9:;
     T0 = ecl_cdr(v6);
     goto L2;
    }
   }
L2:;
   T1 = cl_list(3, ECL_SYM("APPLY-FROM-STACK-FRAME",1615), v3frame, v1fun);
   T2 = ecl_list1(T1);
   T3 = ecl_append(T0,T2);
   value0 = cl_listX(3, VV[0], v3frame, T3);
   return value0;
  }
 }
}
/*	function definition for UNOPTIMIZED-FUNCALL                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2unoptimized_funcall(cl_object v1fun, cl_object v2arguments)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v3l;
   v3l = ecl_length(v2arguments);
   if (!((v3l)<=(63))) { goto L2; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[43])(1, v1fun) /*  C1EXPR */;
   T1 = ecl_function_dispatch(cl_env_copy,VV[44])(1, v2arguments) /*  C1ARGS* */;
   value0 = ecl_function_dispatch(cl_env_copy,VV[45])(8, ECL_SYM("FUNCALL",394), VV[3], ECL_T, VV[4], ECL_T, VV[5], T0, T1) /*  MAKE-C1FORM* */;
   return value0;
L2:;
   value0 = L1unoptimized_long_call(v1fun, v2arguments);
   return value0;
  }
 }
}
/*	function definition for C1FUNCALL                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3c1funcall(cl_object v1args)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_function_dispatch(cl_env_copy,VV[47])(3, ECL_SYM("FUNCALL",394), v1args, ecl_make_fixnum(1)) /*  CHECK-ARGS-NUMBER */;
  {
   cl_object v2;
   cl_object v3;
   cl_object v4fun;
   cl_object v5fd;
   v2 = ecl_car(v1args);
   v3 = ecl_cdr(v1args);
   v4fun = v2;
   v5fd = ECL_NIL;
   if (!(ECL_CONSP(v4fun))) { goto L6; }
   T0 = ecl_car(v4fun);
   if (!((T0)==(ECL_SYM("LAMBDA",452)))) { goto L6; }
   T0 = ecl_cdr(v4fun);
   value0 = ecl_function_dispatch(cl_env_copy,VV[48])(3, T0, v3, ECL_NIL) /*  OPTIMIZE-FUNCALL/APPLY-LAMBDA */;
   return value0;
L6:;
   if (!(ECL_CONSP(v4fun))) { goto L9; }
   T0 = ecl_car(v4fun);
   if (!((T0)==(ECL_SYM("LAMBDA-BLOCK",1339)))) { goto L9; }
   v4fun = cl_macroexpand_1(1, v4fun);
   T0 = ecl_cdr(v4fun);
   value0 = ecl_function_dispatch(cl_env_copy,VV[48])(3, T0, v3, ECL_NIL) /*  OPTIMIZE-FUNCALL/APPLY-LAMBDA */;
   return value0;
L9:;
   if (!(ECL_ATOM(v4fun))) { goto L14; }
   value0 = L2unoptimized_funcall(v4fun, v3);
   return value0;
L14:;
   {
    cl_object v6name;
    v6name = ecl_car(v4fun);
    if (!(ECL_SYMBOLP(v6name))) { goto L21; }
    if ((v6name)==(ECL_SYM("THE",856))) { goto L21; }
    v5fd = ecl_function_dispatch(cl_env_copy,VV[49])(1, v6name) /*  CMP-MACRO-FUNCTION */;
    goto L19;
L21:;
    v5fd = ECL_NIL;
    goto L19;
L19:;
    if (Null(v5fd)) { goto L16; }
   }
   T0 = ecl_function_dispatch(cl_env_copy,VV[50])(2, v5fd, v4fun) /*  CMP-EXPAND-MACRO */;
   v1args = CONS(T0,v3);
   goto TTL;
L16:;
   T0 = ecl_car(v4fun);
   if ((T0)==(ECL_SYM("FUNCTION",396))) { goto L26; }
   value0 = L2unoptimized_funcall(v4fun, v3);
   return value0;
L26:;
   v4fun = ecl_cadr(v4fun);
   if (Null(si_valid_function_name_p(v4fun))) { goto L28; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[51])(3, v4fun, v3, ECL_NIL) /*  C1CALL */;
   return value0;
L28:;
   if (!(ECL_CONSP(v4fun))) { goto L31; }
   T0 = ecl_car(v4fun);
   if (!((T0)==(ECL_SYM("LAMBDA",452)))) { goto L31; }
   T0 = ecl_cdr(v4fun);
   value0 = ecl_function_dispatch(cl_env_copy,VV[48])(3, T0, v3, ECL_NIL) /*  OPTIMIZE-FUNCALL/APPLY-LAMBDA */;
   return value0;
L31:;
   if (!(ECL_CONSP(v4fun))) { goto L34; }
   T0 = ecl_car(v4fun);
   if (!((T0)==(ECL_SYM("LAMBDA-BLOCK",1339)))) { goto L34; }
   v4fun = cl_macroexpand_1(1, v4fun);
   T0 = ecl_cdr(v4fun);
   value0 = ecl_function_dispatch(cl_env_copy,VV[48])(3, T0, v3, ECL_NIL) /*  OPTIMIZE-FUNCALL/APPLY-LAMBDA */;
   return value0;
L34:;
   value0 = ecl_function_dispatch(cl_env_copy,VV[52])(2, _ecl_static_1, v4fun) /*  CMPERR */;
   return value0;
  }
 }
}
/*	function definition for C2FUNCALL                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4c2funcall(cl_object v1c1form, cl_object v2form, cl_object v3args)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4form_type;
   cl_object v5function_p;
   cl_object v6loc;
   ecl_bds_bind(cl_env_copy,VV[8],ecl_make_fixnum(0)); /*  *INLINE-BLOCKS* */
   ecl_bds_push(cl_env_copy,VV[9]);               /*  *TEMP*          */
   v4form_type = ecl_function_dispatch(cl_env_copy,VV[54])(1, v2form) /*  C1FORM-PRIMARY-TYPE */;
   if (Null(cl_subtypep(2, v4form_type, ECL_SYM("FUNCTION",396)))) { goto L4; }
   v5function_p = ecl_function_dispatch(cl_env_copy,VV[55])(0) /*  POLICY-ASSUME-RIGHT-TYPE */;
   goto L2;
L4:;
   v5function_p = ECL_NIL;
   goto L2;
L2:;
   v6loc = L10maybe_save_value(2, v2form, v3args);
   T0 = ecl_function_dispatch(cl_env_copy,VV[56])(1, v3args) /*  INLINE-ARGS */;
   T1 = L9call_unknown_global_loc(4, ECL_NIL, v6loc, T0, v5function_p);
   ecl_function_dispatch(cl_env_copy,VV[57])(1, T1) /*  UNWIND-EXIT   */;
   value0 = ecl_function_dispatch(cl_env_copy,VV[58])(0) /*  CLOSE-INLINE-BLOCKS */;
   ecl_bds_unwind1(cl_env_copy);
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
 }
}
/*	function definition for C2CALL-GLOBAL                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5c2call_global(cl_object v1c1form, cl_object v2fname, cl_object v3args)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4fun;
   {
    cl_object v5;
    cl_object v6;
    v5 = ecl_symbol_value(VV[11]);
    v6 = si_make_seq_iterator(2, v5, ecl_make_fixnum(0));
L4:;
    if ((v6)!=ECL_NIL) { goto L6; }
    v4fun = ECL_NIL;
    goto L1;
L6:;
    {
     cl_object v7;
     v7 = si_seq_iterator_ref(v5, v6);
     T0 = ecl_function_dispatch(cl_env_copy,VV[60])(1, v7) /*  FUN-NAME */;
     if (Null(ecl_function_dispatch(cl_env_copy,VV[61])(2, v2fname, T0) /*  SAME-FNAME-P */)) { goto L8; }
     v4fun = v7;
     goto L1;
    }
L8:;
    v6 = si_seq_iterator_next(v5, v6);
    goto L4;
   }
L1:;
   if (Null(v4fun)) { goto L13; }
   if (Null(ecl_function_dispatch(cl_env_copy,VV[62])(2, v4fun, v3args) /*  C2TRY-TAIL-RECURSIVE-CALL */)) { goto L13; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L13:;
   ecl_bds_bind(cl_env_copy,VV[8],ecl_make_fixnum(0)); /*  *INLINE-BLOCKS* */
   ecl_bds_push(cl_env_copy,VV[9]);               /*  *TEMP*          */
   T0 = ecl_function_dispatch(cl_env_copy,VV[54])(1, v1c1form) /*  C1FORM-PRIMARY-TYPE */;
   T1 = ecl_function_dispatch(cl_env_copy,VV[63])(1, ecl_symbol_value(VV[12])) /*  LOC-TYPE */;
   T2 = L6call_global_loc(v2fname, v4fun, v3args, T0, T1);
   ecl_function_dispatch(cl_env_copy,VV[57])(1, T2) /*  UNWIND-EXIT   */;
   value0 = ecl_function_dispatch(cl_env_copy,VV[58])(0) /*  CLOSE-INLINE-BLOCKS */;
   ecl_bds_unwind1(cl_env_copy);
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
 }
}
/*	function definition for CALL-GLOBAL-LOC                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6call_global_loc(cl_object v1fname, cl_object v2fun, cl_object v3args, cl_object v4return_type, cl_object v5expected_type)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (v2fun==ECL_NIL) { goto L4; }
  if (Null(ecl_function_dispatch(cl_env_copy,VV[65])(1, v2fun) /*  FUN-GLOBAL */)) { goto L1; }
  goto L3;
L4:;
L3:;
  if ((ecl_function_dispatch(cl_env_copy,VV[66])(1, v1fname) /*  INLINE-POSSIBLE */)!=ECL_NIL) { goto L1; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[56])(1, v3args) /*  INLINE-ARGS */;
  value0 = L9call_unknown_global_loc(3, v1fname, ECL_NIL, T0);
  return value0;
L1:;
  v3args = ecl_function_dispatch(cl_env_copy,VV[56])(1, v3args) /*  INLINE-ARGS */;
  {
   cl_object v6inline_loc;
   T0 = ecl_function_dispatch(cl_env_copy,VV[67])(2, v4return_type, v5expected_type) /*  TYPE-AND */;
   v6inline_loc = ecl_function_dispatch(cl_env_copy,VV[68])(3, v1fname, T0, v3args) /*  APPLY-INLINER */;
   if (Null(v6inline_loc)) { goto L8; }
   value0 = v6inline_loc;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L8:;
  if (Null(ecl_function_dispatch(cl_env_copy,VV[69])(0) /*  POLICY-USE-DIRECT-C-CALL */)) { goto L11; }
  if ((ecl_function_dispatch(cl_env_copy,VV[70])(1, v2fun) /*  FUN-P  */)!=ECL_NIL) { goto L14; }
  if (!(v2fun==ECL_NIL)) { goto L11; }
  {
   cl_object v6;
   cl_object v7;
   v6 = ecl_symbol_value(VV[11]);
   v7 = si_make_seq_iterator(2, v6, ecl_make_fixnum(0));
L20:;
   if ((v7)!=ECL_NIL) { goto L22; }
   v2fun = ECL_NIL;
   goto L17;
L22:;
   {
    cl_object v8;
    v8 = si_seq_iterator_ref(v6, v7);
    T0 = ecl_function_dispatch(cl_env_copy,VV[60])(1, v8) /*  FUN-NAME */;
    if (Null(ecl_function_dispatch(cl_env_copy,VV[61])(2, v1fname, T0) /*  SAME-FNAME-P */)) { goto L24; }
    v2fun = v8;
    goto L17;
   }
L24:;
   v7 = si_seq_iterator_next(v6, v7);
   goto L20;
  }
L17:;
  if (Null(v2fun)) { goto L11; }
  goto L12;
L14:;
L12:;
  value0 = L7call_loc(v1fname, v2fun, v3args, v4return_type);
  return value0;
L11:;
  if (ECL_SYMBOLP(v1fname)) { goto L29; }
  value0 = L9call_unknown_global_loc(3, v1fname, ECL_NIL, v3args);
  return value0;
L29:;
  if (Null(ecl_function_dispatch(cl_env_copy,VV[69])(0) /*  POLICY-USE-DIRECT-C-CALL */)) { goto L31; }
  {
   cl_object v6fd;
   v6fd = si_get_sysprop(v1fname, VV[14]);
   if (Null(v6fd)) { goto L31; }
   {
    cl_object v8;                                 /*  MINARG          */
    cl_object v9;                                 /*  MAXARG          */
    value0 = ecl_function_dispatch(cl_env_copy,VV[71])(1, v1fname) /*  GET-PROCLAIMED-NARG */;
    v8 = value0;
    {
     const int v10 = cl_env_copy->nvalues;
     cl_object v11;
     v11 = (v10<=1)? ECL_NIL : cl_env_copy->values[1];
     v9 = v11;
    }
    T0 = ecl_memql(v1fname,ecl_symbol_value(VV[15]));
    value0 = L8call_exported_function_loc(v1fname, v3args, v6fd, v8, v9, T0, v4return_type);
    return value0;
   }
  }
L31:;
  {
   cl_object v7;                                  /*  FOUND           */
   cl_object v8;                                  /*  FD              */
   cl_object v9;                                  /*  MINARG          */
   cl_object v10;                                 /*  MAXARG          */
   value0 = si_mangle_name(2, v1fname, ECL_T);
   v7 = value0;
   {
    const int v11 = cl_env_copy->nvalues;
    cl_object v12;
    v12 = (v11<=1)? ECL_NIL : cl_env_copy->values[1];
    v8 = v12;
    v12 = (v11<=2)? ECL_NIL : cl_env_copy->values[2];
    v9 = v12;
    v12 = (v11<=3)? ECL_NIL : cl_env_copy->values[3];
    v10 = v12;
   }
   if (Null(v7)) { goto L37; }
   value0 = L8call_exported_function_loc(v1fname, v3args, v8, v9, v10, ECL_T, v4return_type);
   return value0;
  }
L37:;
  value0 = L9call_unknown_global_loc(3, v1fname, ECL_NIL, v3args);
  return value0;
 }
}
/*	function definition for CALL-LOC                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7call_loc(cl_object v1fname, cl_object v2fun, cl_object v3args, cl_object v4type)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[73])(1, v3args) /*  COERCE-LOCS */;
  value0 = cl_list(4, VV[17], v2fun, T0, v4type);
  return value0;
 }
}
/*	function definition for CALL-EXPORTED-FUNCTION-LOC            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8call_exported_function_loc(cl_object v1fname, cl_object v2args, cl_object v3fun_c_name, cl_object v4minarg, cl_object v5maxarg, cl_object v6in_core, cl_object v7return_type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((v6in_core)!=ECL_NIL) { goto L1; }
  {
   cl_object v9;                                  /*  DECLARED        */
   value0 = cl_gethash(2, v3fun_c_name, ecl_symbol_value(VV[19]));
   v9 = cl_env_copy->values[1];
   if ((v9)!=ECL_NIL) { goto L1; }
   if (!(ecl_number_equalp(v5maxarg,v4minarg))) { goto L6; }
   ecl_function_dispatch(cl_env_copy,VV[75])(3, _ecl_static_2, v3fun_c_name, _ecl_static_3) /*  WT-NL-H */;
   {
    cl_object v10i;
    v10i = ecl_make_fixnum(0);
    goto L12;
L11:;
    if (!(ecl_number_compare(v10i,ecl_make_fixnum(0))>0)) { goto L14; }
    ecl_function_dispatch(cl_env_copy,VV[76])(1, _ecl_static_4) /*  WT-H1 */;
L14:;
    ecl_function_dispatch(cl_env_copy,VV[76])(1, _ecl_static_5) /*  WT-H1 */;
    v10i = ecl_one_plus(v10i);
L12:;
    if (!(ecl_number_compare(v10i,v5maxarg)<0)) { goto L19; }
    goto L11;
L19:;
   }
   ecl_function_dispatch(cl_env_copy,VV[76])(1, _ecl_static_6) /*  WT-H1 */;
   goto L5;
L6:;
   ecl_function_dispatch(cl_env_copy,VV[75])(1, _ecl_static_7) /*  WT-NL-H */;
   ecl_function_dispatch(cl_env_copy,VV[75])(3, _ecl_static_2, v3fun_c_name, _ecl_static_8) /*  WT-NL-H */;
   ecl_function_dispatch(cl_env_copy,VV[75])(1, _ecl_static_9) /*  WT-NL-H */;
   ecl_function_dispatch(cl_env_copy,VV[75])(3, _ecl_static_2, v3fun_c_name, _ecl_static_10) /*  WT-NL-H */;
   ecl_function_dispatch(cl_env_copy,VV[75])(1, _ecl_static_11) /*  WT-NL-H */;
L5:;
   si_hash_set(v3fun_c_name, ecl_symbol_value(VV[19]), ecl_make_fixnum(1));
  }
L1:;
  {
   cl_object v8fun;
   v8fun = ecl_function_dispatch(cl_env_copy,VV[77])(12, ECL_SYM("NAME",1273), v1fname, VV[20], ECL_T, VV[21], v3fun_c_name, VV[22], ECL_NIL, VV[23], v4minarg, VV[24], v5maxarg) /*  MAKE-FUN */;
   value0 = L7call_loc(v1fname, v8fun, v2args, v7return_type);
   return value0;
  }
 }
}
/*	function definition for CALL-UNKNOWN-GLOBAL-LOC               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L9call_unknown_global_loc(cl_narg narg, cl_object v1fname, cl_object v2loc, cl_object v3args, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>4)) FEwrong_num_arguments_anonym();
 {
  cl_object v4function_p;
  va_list args; va_start(args,v3args);
  {
   int i = 3;
   if (i >= narg) {
    v4function_p = ECL_NIL;
   } else {
    i++;
    v4function_p = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if ((v2loc)!=ECL_NIL) { goto L2; }
  if (!(ECL_SYMBOLP(v1fname))) { goto L4; }
  T0 = cl_symbol_package(v1fname);
  T1 = cl_find_package(_ecl_static_12);
  if ((T0)==(T1)) { goto L4; }
  v2loc = ecl_function_dispatch(cl_env_copy,VV[79])(1, v1fname) /*  ADD-SYMBOL */;
  v4function_p = ECL_NIL;
  goto L2;
L4:;
  v2loc = cl_list(2, ECL_SYM("FDEFINITION",349), v1fname);
  v4function_p = ECL_T;
L2:;
  T0 = ecl_function_dispatch(cl_env_copy,VV[73])(1, v3args) /*  COERCE-LOCS */;
  value0 = cl_list(5, VV[26], v2loc, T0, v1fname, v4function_p);
  return value0;
 }
}
/*	function definition for MAYBE-SAVE-VALUE                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L10maybe_save_value(cl_narg narg, cl_object v1value, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2other_forms;
  cl_object v3other_forms_flag;
  va_list args; va_start(args,v1value);
  {
   int i = 1;
   if (i >= narg) {
    v2other_forms = ECL_NIL;
    v3other_forms_flag = ECL_NIL;
   } else {
    i++;
    v2other_forms = va_arg(args,cl_object);
    v3other_forms_flag = ECL_T;
   }
  }
  va_end(args);
  {
   cl_object v4name;
   v4name = ecl_function_dispatch(cl_env_copy,VV[81])(1, v1value) /*  C1FORM-NAME */;
   if (!((v4name)==(ECL_SYM("LOCATION",1763)))) { goto L3; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[82])(1, v1value) /*  C1FORM-ARGS */;
   value0 = ecl_car(T0);
   cl_env_copy->nvalues = 1;
   return value0;
L3:;
   if (!((v4name)==(VV[28]))) { goto L5; }
   if (Null(v3other_forms_flag)) { goto L5; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[82])(1, v1value) /*  C1FORM-ARGS */;
   T1 = ecl_car(T0);
   if ((ecl_function_dispatch(cl_env_copy,VV[83])(2, T1, v2other_forms) /*  VAR-CHANGED-IN-FORM-LIST */)!=ECL_NIL) { goto L5; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[82])(1, v1value) /*  C1FORM-ARGS */;
   value0 = ecl_car(T0);
   cl_env_copy->nvalues = 1;
   return value0;
L5:;
   {
    cl_object v5temp;
    v5temp = ecl_function_dispatch(cl_env_copy,VV[84])(0) /*  MAKE-TEMP-VAR */;
    ecl_bds_bind(cl_env_copy,VV[12],v5temp);      /*  *DESTINATION*   */
    ecl_function_dispatch(cl_env_copy,VV[85])(1, v1value) /*  C2EXPR* */;
    value0 = v5temp;
    cl_env_copy->nvalues = 1;
    ecl_bds_unwind1(cl_env_copy);
    return value0;
   }
  }
 }
}
/*	function definition for ENV-VAR-NAME                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L11env_var_name(cl_object v1n)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_nth(ecl_to_size(v1n),ecl_symbol_value(VV[31]));
  if ((value0)!=ECL_NIL) { goto L2; }
  value0 = cl_format(3, ECL_NIL, _ecl_static_13, v1n);
  return value0;
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for WT-STACK-POINTER                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L12wt_stack_pointer(cl_object v1narg)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[88])(2, _ecl_static_14, v1narg) /*  WT */;
  return value0;
 }
}
/*	function definition for WT-CALL                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L13wt_call(cl_narg narg, cl_object v1fun, cl_object v2args, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>4)) FEwrong_num_arguments_anonym();
 {
  cl_object v3fname;
  cl_object v4env;
  va_list args; va_start(args,v2args);
  {
   int i = 2;
   if (i >= narg) {
    v3fname = ECL_NIL;
   } else {
    i++;
    v3fname = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v4env = ECL_NIL;
   } else {
    i++;
    v4env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (Null(v4env)) { goto L4; }
  cl_set(VV[34],ECL_T);
  ecl_function_dispatch(cl_env_copy,VV[88])(3, _ecl_static_15, v4env, _ecl_static_16) /*  WT */;
  L13wt_call(2, v1fun, v2args);
  ecl_function_dispatch(cl_env_copy,VV[88])(1, _ecl_static_17) /*  WT */;
  goto L3;
L4:;
  ecl_function_dispatch(cl_env_copy,VV[88])(2, v1fun, _ecl_static_3) /*  WT */;
  {
   cl_object v5comma;
   v5comma = _ecl_static_18;
   {
    cl_object v6;
    v6 = v2args;
    goto L16;
L15:;
    {
     cl_object v7arg;
     v7arg = ecl_car(v6);
     ecl_function_dispatch(cl_env_copy,VV[88])(2, v5comma, v7arg) /*  WT */;
     v5comma = _ecl_static_19;
    }
    v6 = ecl_cdr(v6);
L16:;
    if (Null(v6)) { goto L25; }
    goto L15;
L25:;
   }
  }
  ecl_function_dispatch(cl_env_copy,VV[88])(1, _ecl_static_17) /*  WT */;
L3:;
  if (Null(v3fname)) { goto L27; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[90])(1, v3fname) /*  WT-COMMENT */;
  return value0;
L27:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for WT-CALL-INDIRECT                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L14wt_call_indirect(cl_object v1fun_loc, cl_object v2args, cl_object v3fname, cl_object v4function_p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v5narg;
   v5narg = ecl_length(v2args);
   if (Null(v4function_p)) { goto L3; }
   ecl_function_dispatch(cl_env_copy,VV[88])(4, _ecl_static_20, v1fun_loc, _ecl_static_21, ecl_make_fixnum(v5narg)) /*  WT */;
   goto L2;
L3:;
   ecl_function_dispatch(cl_env_copy,VV[88])(4, _ecl_static_22, v1fun_loc, _ecl_static_23, ecl_make_fixnum(v5narg)) /*  WT */;
L2:;
   {
    cl_object v6;
    v6 = v2args;
    goto L9;
L8:;
    {
     cl_object v7arg;
     v7arg = ecl_car(v6);
     ecl_function_dispatch(cl_env_copy,VV[88])(2, _ecl_static_19, v7arg) /*  WT */;
    }
    v6 = ecl_cdr(v6);
L9:;
    if (Null(v6)) { goto L16; }
    goto L8;
L16:;
   }
   ecl_function_dispatch(cl_env_copy,VV[88])(1, _ecl_static_17) /*  WT */;
   if (Null(v3fname)) { goto L19; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[90])(1, v3fname) /*  WT-COMMENT */;
   return value0;
L19:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for WT-CALL-NORMAL                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L15wt_call_normal(cl_object v1fun, cl_object v2args, cl_object v3type)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((ecl_function_dispatch(cl_env_copy,VV[93])(1, v1fun) /*  FUN-CFUN */)!=ECL_NIL) { goto L1; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[60])(1, v1fun) /*  FUN-NAME */;
  ecl_function_dispatch(cl_env_copy,VV[94])(2, _ecl_static_24, T0) /*  BABOON */;
L1:;
  {
   cl_object v4minarg;
   cl_object v5maxarg;
   cl_object v6fun_c_name;
   cl_object v7fun_lisp_name;
   cl_fixnum v8narg;
   cl_object v9env;
   v4minarg = ecl_function_dispatch(cl_env_copy,VV[95])(1, v1fun) /*  FUN-MINARG */;
   v5maxarg = ecl_function_dispatch(cl_env_copy,VV[96])(1, v1fun) /*  FUN-MAXARG */;
   v6fun_c_name = ecl_function_dispatch(cl_env_copy,VV[93])(1, v1fun) /*  FUN-CFUN */;
   v7fun_lisp_name = ecl_function_dispatch(cl_env_copy,VV[60])(1, v1fun) /*  FUN-NAME */;
   v8narg = ecl_length(v2args);
   v9env = ECL_NIL;
   {
    cl_object v10;
    v10 = ecl_function_dispatch(cl_env_copy,VV[97])(1, v1fun) /*  FUN-CLOSURE */;
    if (!((v10)==(VV[37]))) { goto L11; }
    v9env = ecl_function_dispatch(cl_env_copy,VV[98])(1, v1fun) /*  ENVIRONMENT-ACCESSOR */;
    goto L9;
L11:;
    if (!((v10)==(VV[38]))) { goto L9; }
    {
     cl_object v11lex_lvl;
     v11lex_lvl = ecl_function_dispatch(cl_env_copy,VV[99])(1, v1fun) /*  FUN-LEVEL */;
     {
      cl_object v12n;
      v12n = ecl_make_fixnum(0);
      goto L18;
L17:;
      {
       cl_object v13j;
       cl_object v14x;
       T0 = ecl_minus(v11lex_lvl,v12n);
       v13j = ecl_minus(T0,ecl_make_fixnum(1));
       v14x = ecl_nth(ecl_to_size(v13j),ecl_symbol_value(VV[30]));
       if ((v14x)!=ECL_NIL) { goto L23; }
       v14x = cl_format(3, ECL_NIL, _ecl_static_25, v13j);
       {
        cl_object v15;
        v15 = ecl_symbol_value(VV[30]);
        {
         cl_object v16;
         v16 = ecl_nthcdr(ecl_to_size(v12n),v15);
         if (ecl_unlikely(ECL_ATOM(v16))) FEtype_error_cons(v16);
         T0 = v16;
        }
        (ECL_CONS_CAR(T0)=v14x,T0);
       }
L23:;
       v2args = CONS(v14x,v2args);
      }
      v12n = ecl_one_plus(v12n);
L18:;
      if (!(ecl_number_compare(v12n,v11lex_lvl)<0)) { goto L35; }
      goto L17;
L35:;
     }
    }
   }
L9:;
   if ((cl_LE(3, v4minarg, ecl_make_fixnum(v8narg), v5maxarg))!=ECL_NIL) { goto L37; }
   value0 = v7fun_lisp_name;
   if ((value0)!=ECL_NIL) { goto L41; }
   T0 = VV[39];
   goto L39;
L41:;
   T0 = value0;
   goto L39;
L39:;
   ecl_function_dispatch(cl_env_copy,VV[52])(2, _ecl_static_26, T0) /*  CMPERR */;
L37:;
   if (Null(ecl_function_dispatch(cl_env_copy,VV[100])(1, v1fun) /*  FUN-NEEDS-NARG */)) { goto L43; }
   v2args = CONS(ecl_make_fixnum(v8narg),v2args);
L43:;
   value0 = L13wt_call(4, v6fun_c_name, v2args, ECL_NIL, v9env);
   return value0;
  }
 }
}

#include "cmp/cmpcall.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclbeL928sD8xjj9_dsxTOE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPCALL.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclbeL928sD8xjj9_dsxTOE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[41]);                           /*  UNOPTIMIZED-LONG-CALL */
 ecl_cmp_defun(VV[42]);                           /*  UNOPTIMIZED-FUNCALL */
 ecl_cmp_defun(VV[46]);                           /*  C1FUNCALL       */
 ecl_cmp_defun(VV[53]);                           /*  C2FUNCALL       */
 ecl_cmp_defun(VV[59]);                           /*  C2CALL-GLOBAL   */
 ecl_cmp_defun(VV[64]);                           /*  CALL-GLOBAL-LOC */
 ecl_cmp_defun(VV[72]);                           /*  CALL-LOC        */
 ecl_cmp_defun(VV[74]);                           /*  CALL-EXPORTED-FUNCTION-LOC */
 ecl_cmp_defun(VV[78]);                           /*  CALL-UNKNOWN-GLOBAL-LOC */
 ecl_cmp_defun(VV[80]);                           /*  MAYBE-SAVE-VALUE */
 si_Xmake_special(VV[30]);
 if (ecl_boundp(cl_env_copy,VV[30])) { goto L43; }
 cl_set(VV[30],VVtemp[0]);
L43:;
 si_Xmake_special(VV[31]);
 if (ecl_boundp(cl_env_copy,VV[31])) { goto L50; }
 cl_set(VV[31],VVtemp[1]);
L50:;
 ecl_cmp_defun(VV[86]);                           /*  ENV-VAR-NAME    */
 ecl_cmp_defun(VV[87]);                           /*  WT-STACK-POINTER */
 ecl_cmp_defun(VV[89]);                           /*  WT-CALL         */
 ecl_cmp_defun(VV[91]);                           /*  WT-CALL-INDIRECT */
 ecl_cmp_defun(VV[92]);                           /*  WT-CALL-NORMAL  */
}
