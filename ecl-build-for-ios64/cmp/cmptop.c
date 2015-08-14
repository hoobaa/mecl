/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPTOP.LSP                                    */
#include <ecl/ecl-cmp.h>
#include "cmp/cmptop.eclh"
/*	function definition for T1EXPR                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1t1expr(cl_object v1form)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_bds_bind(cl_env_copy,VV[0],ECL_NIL);        /*  *CURRENT-TOPLEVEL-FORM* */
  if (Null(ecl_symbol_value(VV[1]))) { goto L2; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[123])(1, ecl_symbol_value(VV[1])) /*  CMP-ENV-COPY */;
  goto L1;
L2:;
  T0 = ecl_function_dispatch(cl_env_copy,VV[124])(0) /*  CMP-ENV-ROOT */;
L1:;
  ecl_bds_bind(cl_env_copy,VV[1],T0);             /*  *CMP-ENV*       */
  T0 = L2t1expr_(v1form);
  cl_set(VV[2],CONS(T0,ecl_symbol_value(VV[2])));
  value0 = ecl_symbol_value(VV[2]);
  cl_env_copy->nvalues = 1;
  ecl_bds_unwind1(cl_env_copy);
  ecl_bds_unwind1(cl_env_copy);
  return value0;
 }
}
/*	function definition for T1EXPR*                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2t1expr_(cl_object v1form)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = CONS(v1form,ecl_symbol_value(VV[0]));
  ecl_bds_bind(cl_env_copy,VV[0],T0);             /*  *CURRENT-TOPLEVEL-FORM* */
  ecl_bds_bind(cl_env_copy,VV[5],v1form);         /*  *CURRENT-FORM*  */
  ecl_bds_bind(cl_env_copy,VV[6],ECL_T);          /*  *FIRST-ERROR*   */
  ecl_bds_bind(cl_env_copy,VV[7],ecl_make_fixnum(0)); /*  *SETJMPS*   */
  if (!(ECL_CONSP(v1form))) { goto L1; }
  {
   cl_object v2;
   cl_object v3;
   cl_object v4fd;
   v2 = ecl_car(v1form);
   v3 = ecl_cdr(v1form);
   v4fd = ECL_NIL;
   if (Null(ecl_memql(v2,ecl_symbol_value(VV[4])))) { goto L6; }
   ecl_function_dispatch(cl_env_copy,VV[126])(0)  /*  PRINT-CURRENT-FORM */;
L6:;
   if (!(ECL_CONSP(v2))) { goto L8; }
   value0 = L18t1ordinary(v1form);
   ecl_bds_unwind_n(cl_env_copy,4);
   return value0;
L8:;
   if (ECL_SYMBOLP(v2)) { goto L10; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[127])(2, _ecl_static_1, v2) /*  CMPERR */;
   ecl_bds_unwind_n(cl_env_copy,4);
   return value0;
L10:;
   if (!((v2)==(ECL_SYM("QUOTE",679)))) { goto L12; }
   value0 = L18t1ordinary(ECL_NIL);
   ecl_bds_unwind_n(cl_env_copy,4);
   return value0;
L12:;
   v4fd = ecl_gethash_safe(v2,ecl_symbol_value(VV[8]),ECL_NIL);
   if (Null(v4fd)) { goto L14; }
   value0 = ecl_function_dispatch(cl_env_copy,v4fd)(1, v3);
   ecl_bds_unwind_n(cl_env_copy,4);
   return value0;
L14:;
   if (Null(ecl_gethash_safe(v2,ecl_symbol_value(VV[9]),ECL_NIL))) { goto L17; }
   value0 = L18t1ordinary(v1form);
   ecl_bds_unwind_n(cl_env_copy,4);
   return value0;
L17:;
   v4fd = (cl_env_copy->function=(ECL_SYM("COMPILER-MACRO-FUNCTION",239)->symbol.gfdef))->cfun.entry(1, v2) /*  COMPILER-MACRO-FUNCTION */;
   if (Null(v4fd)) { goto L19; }
   if (Null(ecl_function_dispatch(cl_env_copy,VV[128])(1, v2) /*  INLINE-POSSIBLE */)) { goto L19; }
   {
    cl_object v5success;
    v5success = ECL_NIL;
    value0 = ecl_function_dispatch(cl_env_copy,VV[129])(2, v4fd, v1form) /*  CMP-EXPAND-MACRO */;
    v4fd = value0;
    {
     const int v6 = cl_env_copy->nvalues;
     cl_object v7;
     v7 = (v6<=1)? ECL_NIL : cl_env_copy->values[1];
     v5success = v7;
    }
    if (Null(v5success)) { goto L19; }
   }
   cl_set(VV[0],CONS(ECL_SYM("MACROEXPAND",519),ecl_symbol_value(VV[0])));
   value0 = L2t1expr_(v4fd);
   ecl_bds_unwind_n(cl_env_copy,4);
   return value0;
L19:;
   v4fd = ecl_function_dispatch(cl_env_copy,VV[130])(1, v2) /*  CMP-MACRO-FUNCTION */;
   if (Null(v4fd)) { goto L29; }
   cl_set(VV[0],CONS(ECL_SYM("MACROEXPAND",519),ecl_symbol_value(VV[0])));
   T0 = ecl_function_dispatch(cl_env_copy,VV[129])(2, v4fd, v1form) /*  CMP-EXPAND-MACRO */;
   value0 = L2t1expr_(T0);
   ecl_bds_unwind_n(cl_env_copy,4);
   return value0;
L29:;
   value0 = L18t1ordinary(v1form);
   ecl_bds_unwind_n(cl_env_copy,4);
   return value0;
  }
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  ecl_bds_unwind_n(cl_env_copy,4);
  return value0;
 }
}
/*	function definition for T1/C1EXPR                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3t1_c1expr(cl_object v1form)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((ecl_symbol_value(VV[11]))!=ECL_NIL) { goto L1; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[132])(1, v1form) /*  C1EXPR */;
  return value0;
L1:;
  if (!(ECL_ATOM(v1form))) { goto L3; }
  value0 = L18t1ordinary(v1form);
  return value0;
L3:;
  value0 = L2t1expr_(v1form);
  return value0;
 }
}
/*	function definition for T2EXPR                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4t2expr(cl_object v1form)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1form)) { goto L1; }
  {
   cl_object v2def;
   T0 = ecl_function_dispatch(cl_env_copy,VV[134])(1, v1form) /*  C1FORM-NAME */;
   v2def = ecl_gethash_safe(T0,ecl_symbol_value(VV[13]),ECL_NIL);
   if (Null(v2def)) { goto L4; }
   {
    cl_object v3;
    cl_object v4;
    cl_object v5;
    cl_object v6;
    cl_object v7;
    v3 = ecl_function_dispatch(cl_env_copy,VV[135])(1, v1form) /*  C1FORM-FILE */;
    v4 = ecl_function_dispatch(cl_env_copy,VV[136])(1, v1form) /*  C1FORM-FILE-POSITION */;
    v5 = ecl_function_dispatch(cl_env_copy,VV[137])(1, v1form) /*  C1FORM-FORM */;
    v6 = ecl_function_dispatch(cl_env_copy,VV[137])(1, v1form) /*  C1FORM-FORM */;
    v7 = ecl_function_dispatch(cl_env_copy,VV[138])(1, v1form) /*  C1FORM-ENV */;
    ecl_bds_bind(cl_env_copy,ECL_SYM("*COMPILE-FILE-TRUENAME*",27),v3); /*  *COMPILE-FILE-TRUENAME* */
    ecl_bds_bind(cl_env_copy,VV[14],v4);          /*  *COMPILE-FILE-POSITION* */
    ecl_bds_bind(cl_env_copy,VV[0],v5);           /*  *CURRENT-TOPLEVEL-FORM* */
    ecl_bds_bind(cl_env_copy,VV[5],v6);           /*  *CURRENT-FORM*  */
    ecl_bds_bind(cl_env_copy,VV[1],v7);           /*  *CMP-ENV*       */
    T0 = ecl_function_dispatch(cl_env_copy,VV[139])(1, v1form) /*  C1FORM-ARGS */;
    value0 = cl_apply(3, v2def, v1form, T0);
    ecl_bds_unwind_n(cl_env_copy,5);
    return value0;
   }
L4:;
   value0 = ecl_function_dispatch(cl_env_copy,VV[127])(2, _ecl_static_2, v1form) /*  CMPERR */;
   return value0;
  }
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for EMIT-LOCAL-FUNS                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5emit_local_funs()
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_bds_bind(cl_env_copy,VV[17],ECL_NIL);       /*  *COMPILE-TIME-TOO* */
  ecl_bds_bind(cl_env_copy,VV[11],ECL_NIL);       /*  *COMPILE-TOPLEVEL* */
  goto L3;
L2:;
  {
   cl_object v1lfs;
   v1lfs = ecl_symbol_value(VV[18]);
   goto L9;
L8:;
   v1lfs = ecl_cdr(v1lfs);
L9:;
   T0 = ecl_cdr(v1lfs);
   if ((T0)==(ecl_symbol_value(VV[16]))) { goto L13; }
   goto L8;
L13:;
   cl_set(VV[16],v1lfs);
   T0 = ecl_car(v1lfs);
   ecl_function_dispatch(cl_env_copy,VV[102])(1, T0) /*  T3LOCAL-FUN  */;
  }
L3:;
  if ((ecl_symbol_value(VV[16]))==(ecl_symbol_value(VV[18]))) { goto L17; }
  goto L2;
L17:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  ecl_bds_unwind1(cl_env_copy);
  ecl_bds_unwind1(cl_env_copy);
  return value0;
 }
}
/*	function definition for CTOP-WRITE                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6ctop_write(cl_object v1name, cl_object v2h_pathname, cl_object v3data_pathname)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4top_output_string;
   v4top_output_string = ECL_NIL;
   ecl_bds_bind(cl_env_copy,VV[20],_ecl_static_3); /*  *VOLATILE*     */
   cl_set(VV[2],cl_nreverse(ecl_symbol_value(VV[2])));
   T0 = ecl_function_dispatch(cl_env_copy,VV[142])(1, v2h_pathname) /*  BRIEF-NAMESTRING */;
   ecl_function_dispatch(cl_env_copy,VV[143])(3, _ecl_static_4, T0, _ecl_static_5) /*  WT-NL */;
   ecl_function_dispatch(cl_env_copy,VV[144])(1, _ecl_static_6) /*  WT-NL-H */;
   ecl_function_dispatch(cl_env_copy,VV[144])(1, _ecl_static_7) /*  WT-NL-H */;
   ecl_function_dispatch(cl_env_copy,VV[144])(1, _ecl_static_8) /*  WT-NL-H */;
   ecl_function_dispatch(cl_env_copy,VV[144])(1, _ecl_static_9) /*  WT-NL-H */;
   ecl_function_dispatch(cl_env_copy,VV[144])(1, _ecl_static_10) /*  WT-NL-H */;
   ecl_function_dispatch(cl_env_copy,VV[145])(1, ecl_symbol_value(VV[21])) /*  OUTPUT-CLINES */;
   ecl_function_dispatch(cl_env_copy,VV[144])(1, _ecl_static_11) /*  WT-NL-H */;
   ecl_function_dispatch(cl_env_copy,VV[144])(1, _ecl_static_12) /*  WT-NL-H */;
   ecl_function_dispatch(cl_env_copy,VV[144])(1, _ecl_static_10) /*  WT-NL-H */;
   {
    cl_object v5c_output_file;
    ecl_bds_bind(cl_env_copy,VV[22],ecl_make_fixnum(0)); /*  *OPENED-C-BRACES* */
    ecl_bds_bind(cl_env_copy,VV[23],ECL_NIL);     /*  *AUX-CLOSURE*   */
    v5c_output_file = ecl_symbol_value(VV[24]);
    T0 = cl_make_string_output_stream(0);
    ecl_bds_bind(cl_env_copy,VV[24],T0);          /*  *COMPILER-OUTPUT1* */
    ecl_bds_bind(cl_env_copy,VV[16],ECL_NIL);     /*  *EMITTED-LOCAL-FUNS* */
    T0 = cl_make_hash_table(0);
    ecl_bds_bind(cl_env_copy,VV[25],T0);          /*  *COMPILER-DECLARED-GLOBALS* */
    T0 = ecl_function_dispatch(cl_env_copy,VV[142])(1, v3data_pathname) /*  BRIEF-NAMESTRING */;
    ecl_function_dispatch(cl_env_copy,VV[143])(3, _ecl_static_4, T0, _ecl_static_5) /*  WT-NL */;
    ecl_function_dispatch(cl_env_copy,VV[143])(1, _ecl_static_11) /*  WT-NL */;
    ecl_function_dispatch(cl_env_copy,VV[143])(1, _ecl_static_13) /*  WT-NL */;
    ecl_function_dispatch(cl_env_copy,VV[143])(1, _ecl_static_10) /*  WT-NL */;
    ecl_function_dispatch(cl_env_copy,VV[143])(3, _ecl_static_14, v1name, _ecl_static_15) /*  WT-NL */;
    ecl_function_dispatch(cl_env_copy,VV[146])(0) /*  WT-NL-OPEN-BRACE */;
    ecl_function_dispatch(cl_env_copy,VV[143])(1, _ecl_static_16) /*  WT-NL */;
    ecl_function_dispatch(cl_env_copy,VV[143])(1, _ecl_static_17) /*  WT-NL */;
    ecl_function_dispatch(cl_env_copy,VV[143])(1, _ecl_static_18) /*  WT-NL */;
    ecl_function_dispatch(cl_env_copy,VV[143])(1, _ecl_static_19) /*  WT-NL */;
    ecl_function_dispatch(cl_env_copy,VV[143])(1, _ecl_static_20) /*  WT-NL */;
    ecl_function_dispatch(cl_env_copy,VV[143])(1, _ecl_static_21) /*  WT-NL */;
    ecl_function_dispatch(cl_env_copy,VV[143])(1, _ecl_static_22) /*  WT-NL */;
    ecl_function_dispatch(cl_env_copy,VV[143])(1, _ecl_static_10) /*  WT-NL */;
    if (Null(ecl_symbol_value(VV[26]))) { goto L30; }
    ecl_function_dispatch(cl_env_copy,VV[143])(1, _ecl_static_23) /*  WT-NL */;
L30:;
    ecl_function_dispatch(cl_env_copy,VV[143])(1, _ecl_static_24) /*  WT-NL */;
    ecl_function_dispatch(cl_env_copy,VV[143])(1, _ecl_static_25) /*  WT-NL */;
    if ((ecl_symbol_value(VV[27]))!=ECL_NIL) { goto L36; }
    if (Null(ecl_symbol_value(ECL_SYM("*COMPILER-CONSTANTS*",1017)))) { goto L34; }
    goto L35;
L36:;
L35:;
    ecl_function_dispatch(cl_env_copy,VV[143])(1, _ecl_static_26) /*  WT-NL */;
    ecl_function_dispatch(cl_env_copy,VV[143])(1, _ecl_static_27) /*  WT-NL */;
L34:;
    ecl_function_dispatch(cl_env_copy,VV[143])(1, _ecl_static_28) /*  WT-NL */;
    ecl_function_dispatch(cl_env_copy,VV[143])(1, _ecl_static_29) /*  WT-NL */;
    if (Null(ecl_symbol_value(ECL_SYM("*SOURCE-LOCATION*",1180)))) { goto L41; }
    T0 = ecl_car(ecl_symbol_value(ECL_SYM("*SOURCE-LOCATION*",1180)));
    T1 = cl_namestring(T0);
    ecl_function_dispatch(cl_env_copy,VV[143])(3, _ecl_static_30, T1, _ecl_static_31) /*  WT-NL */;
L41:;
    ecl_function_dispatch(cl_env_copy,VV[143])(1, _ecl_static_32) /*  WT-NL */;
    ecl_function_dispatch(cl_env_copy,VV[143])(1, _ecl_static_6) /*  WT-NL */;
    ecl_function_dispatch(cl_env_copy,VV[143])(1, _ecl_static_33) /*  WT-NL */;
    ecl_function_dispatch(cl_env_copy,VV[143])(1, _ecl_static_10) /*  WT-NL */;
    T0 = ecl_function_dispatch(cl_env_copy,VV[147])(1, v1name) /*  INIT-NAME-TAG */;
    ecl_function_dispatch(cl_env_copy,VV[143])(3, _ecl_static_34, T0, _ecl_static_35) /*  WT-NL */;
    ecl_function_dispatch(cl_env_copy,VV[143])(1, _ecl_static_36) /*  WT-NL */;
    ecl_function_dispatch(cl_env_copy,VV[143])(1, _ecl_static_37) /*  WT-NL */;
    if (Null(ecl_symbol_value(VV[28]))) { goto L50; }
    cl_set(VV[29],VV[30]);
    {
     cl_object v6;
     v6 = ecl_symbol_value(VV[2]);
     goto L58;
L57:;
     {
      cl_object v7form;
      v7form = ecl_car(v6);
      if (Null(v7form)) { goto L62; }
      ecl_function_dispatch(cl_env_copy,VV[30])(2, v7form, ECL_NIL) /*  P1PROPAGATE */;
L62:;
     }
     v6 = ecl_cdr(v6);
L58:;
     if (Null(v6)) { goto L66; }
     goto L57;
L66:;
    }
    {
     cl_object v6;
     v6 = ecl_symbol_value(VV[18]);
     goto L71;
L70:;
     {
      cl_object v7fun;
      v7fun = ecl_car(v6);
      T0 = ecl_function_dispatch(cl_env_copy,VV[148])(1, v7fun) /*  FUN-LAMBDA */;
      ecl_function_dispatch(cl_env_copy,VV[30])(2, T0, ECL_NIL) /*  P1PROPAGATE */;
     }
     v6 = ecl_cdr(v6);
L71:;
     if (Null(v6)) { goto L78; }
     goto L70;
L78:;
    }
L50:;
    cl_set(VV[29],VV[31]);
    {
     cl_object v6;
     cl_object v7form;
     cl_object v8;
     T0 = cl_reverse(ecl_symbol_value(VV[32]));
     v6 = ecl_nconc(T0,ecl_symbol_value(VV[2]));
     v7form = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
     v8 = v6;
L87:;
     if (!(ecl_endp(v8))) { goto L89; }
     goto L88;
L89:;
     v7form = _ecl_car(v8);
     {
      cl_object v9;
      v9 = _ecl_cdr(v8);
      if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
      v8 = v9;
     }
     L7emit_toplevel_form(v7form, v5c_output_file);
     goto L87;
L88:;
    }
    ecl_function_dispatch(cl_env_copy,VV[149])(1, ecl_make_fixnum(0)) /*  WT-NL-CLOSE-MANY-BRACES */;
    v4top_output_string = cl_get_output_stream_string(ecl_symbol_value(VV[24]));
    ecl_bds_unwind_n(cl_env_copy,5);
   }
   ecl_function_dispatch(cl_env_copy,VV[144])(1, _ecl_static_38) /*  WT-NL-H */;
   {
    cl_object v5num_objects;
    v5num_objects = ecl_function_dispatch(cl_env_copy,VV[150])(0) /*  DATA-SIZE */;
    if (!(ecl_zerop(v5num_objects))) { goto L104; }
    ecl_function_dispatch(cl_env_copy,VV[144])(1, _ecl_static_39) /*  WT-NL-H */;
    ecl_function_dispatch(cl_env_copy,VV[144])(1, _ecl_static_40) /*  WT-NL-H */;
    ecl_function_dispatch(cl_env_copy,VV[144])(1, _ecl_static_41) /*  WT-NL-H */;
    ecl_function_dispatch(cl_env_copy,VV[144])(1, _ecl_static_42) /*  WT-NL-H */;
    ecl_function_dispatch(cl_env_copy,VV[144])(1, _ecl_static_43) /*  WT-NL-H */;
    ecl_function_dispatch(cl_env_copy,VV[144])(1, _ecl_static_44) /*  WT-NL-H */;
    goto L102;
L104:;
    T0 = ecl_function_dispatch(cl_env_copy,VV[151])(0) /*  DATA-PERMANENT-STORAGE-SIZE */;
    ecl_function_dispatch(cl_env_copy,VV[144])(2, _ecl_static_45, T0) /*  WT-NL-H */;
    T0 = ecl_function_dispatch(cl_env_copy,VV[152])(0) /*  DATA-TEMPORARY-STORAGE-SIZE */;
    ecl_function_dispatch(cl_env_copy,VV[144])(2, _ecl_static_46, T0) /*  WT-NL-H */;
   }
L102:;
   {
    cl_object v5;
    v5 = ecl_symbol_value(VV[33]);
    goto L116;
L115:;
    {
     cl_object v6l;
     v6l = ecl_car(v5);
     {
      cl_object v7c_name;
      cl_object v8var_name;
      v7c_name = ecl_cadddr(v6l);
      T0 = ecl_cddddr(v6l);
      v8var_name = ecl_car(T0);
      ecl_function_dispatch(cl_env_copy,VV[144])(3, _ecl_static_47, v7c_name, _ecl_static_48) /*  WT-NL-H */;
      ecl_function_dispatch(cl_env_copy,VV[144])(5, _ecl_static_49, v8var_name, _ecl_static_50, v7c_name, _ecl_static_51) /*  WT-NL-H */;
     }
    }
    v5 = ecl_cdr(v5);
L116:;
    if (Null(v5)) { goto L126; }
    goto L115;
L126:;
   }
   {
    cl_object v5;
    v5 = ecl_symbol_value(VV[34]);
    goto L132;
L131:;
    {
     cl_object v6x;
     v6x = ecl_car(v5);
     cl_apply(2, VV[35], v6x);
    }
    v5 = ecl_cdr(v5);
L132:;
    if (Null(v5)) { goto L139; }
    goto L131;
L139:;
   }
   {
    cl_object v5;
    v5 = ecl_symbol_value(VV[33]);
    goto L145;
L144:;
    {
     cl_object v6l;
     v6l = ecl_car(v5);
     {
      cl_object v7var_name;
      cl_object v8c_name;
      cl_object v9lisp_name;
      T0 = ecl_cddddr(v6l);
      v7var_name = ecl_car(T0);
      v8c_name = ecl_cadddr(v6l);
      v9lisp_name = ecl_caddr(v6l);
      ecl_function_dispatch(cl_env_copy,VV[143])(8, _ecl_static_47, v8c_name, _ecl_static_52, _ecl_static_53, v9lisp_name, _ecl_static_54, v7var_name, _ecl_static_55) /*  WT-NL */;
     }
    }
    v5 = ecl_cdr(v5);
L145:;
    if (Null(v5)) { goto L155; }
    goto L144;
L155:;
   }
   ecl_function_dispatch(cl_env_copy,VV[144])(1, _ecl_static_56) /*  WT-NL-H */;
   {
    cl_object v5;
    cl_object v6name;
    cl_object v7setf_vv;
    cl_object v8name_vv;
    cl_object v9;
    v5 = ecl_symbol_value(VV[36]);
    v6name = ECL_NIL;
    v7setf_vv = ECL_NIL;
    v8name_vv = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
    v9 = v5;
L165:;
    if (!(ecl_endp(v9))) { goto L167; }
    goto L166;
L167:;
    {
     cl_object v10;
     v10 = _ecl_car(v9);
     v6name = ecl_car(v10);
     v10 = ecl_cdr(v10);
     v7setf_vv = ecl_car(v10);
     v10 = ecl_cdr(v10);
     v8name_vv = ecl_car(v10);
    }
    {
     cl_object v10;
     v10 = _ecl_cdr(v9);
     if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
     v9 = v10;
    }
    ecl_function_dispatch(cl_env_copy,VV[153])(6, CODE_CHAR(92), CODE_CHAR(10), v7setf_vv, _ecl_static_57, v8name_vv, _ecl_static_58) /*  WT-H */;
    goto L165;
L166:;
   }
   ecl_function_dispatch(cl_env_copy,VV[144])(1, _ecl_static_11) /*  WT-NL-H */;
   ecl_function_dispatch(cl_env_copy,VV[144])(1, _ecl_static_59) /*  WT-NL-H */;
   ecl_function_dispatch(cl_env_copy,VV[144])(1, _ecl_static_10) /*  WT-NL-H */;
   if (!(ECL_LISTP(ecl_symbol_value(VV[37])))) { goto L189; }
   cl_set(VV[37],cl_nreverse(ecl_symbol_value(VV[37])));
   if (Null(ecl_symbol_value(VV[37]))) { goto L189; }
   ecl_function_dispatch(cl_env_copy,VV[144])(1, _ecl_static_60) /*  WT-NL-H */;
   ecl_function_dispatch(cl_env_copy,VV[144])(1, _ecl_static_61) /*  WT-NL-H */;
   ecl_function_dispatch(cl_env_copy,VV[144])(1, _ecl_static_62) /*  WT-NL-H */;
   {
    cl_object v5;
    cl_object v6value;
    cl_object v7name;
    cl_object v8builder;
    cl_object v9;
    v5 = cl_reverse(ecl_symbol_value(VV[37]));
    v6value = ECL_NIL;
    v7name = ECL_NIL;
    v8builder = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
    v9 = v5;
L202:;
    if (!(ecl_endp(v9))) { goto L204; }
    goto L203;
L204:;
    {
     cl_object v10;
     v10 = _ecl_car(v9);
     v6value = ecl_car(v10);
     v10 = ecl_cdr(v10);
     v7name = ecl_car(v10);
     v10 = ecl_cdr(v10);
     v8builder = ecl_car(v10);
    }
    {
     cl_object v10;
     v10 = _ecl_cdr(v9);
     if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
     v9 = v10;
    }
    ecl_terpri(ecl_symbol_value(VV[21]));
    ecl_function_dispatch(cl_env_copy,v8builder)(3, v7name, v6value, ecl_symbol_value(VV[21]));
    goto L202;
L203:;
   }
L189:;
   L41output_cfuns(ecl_symbol_value(VV[21]));
   cl_set(VV[29],VV[38]);
   if (Null(ecl_symbol_value(VV[39]))) { goto L227; }
   ecl_function_dispatch(cl_env_copy,VV[144])(1, _ecl_static_63) /*  WT-NL-H */;
   {
    cl_object v5;
    v5 = ecl_symbol_value(VV[39]);
    goto L233;
L232:;
    {
     cl_object v6x;
     v6x = ecl_car(v5);
     T0 = ecl_fdefinition(VV[154]);
     cl_apply(2, T0, v6x);
    }
    v5 = ecl_cdr(v5);
L233:;
    if (Null(v5)) { goto L241; }
    goto L232;
L241:;
   }
L227:;
   value0 = ecl_function_dispatch(cl_env_copy,VV[143])(1, v4top_output_string) /*  WT-NL */;
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
 }
}
/*	function definition for EMIT-TOPLEVEL-FORM                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7emit_toplevel_form(cl_object v1form, cl_object v2c_output_file)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   if (Null(v1form)) { goto L3; }
   v3 = ecl_function_dispatch(cl_env_copy,VV[135])(1, v1form) /*  C1FORM-FILE */;
   goto L1;
L3:;
   v3 = ECL_NIL;
   goto L1;
L1:;
   if (Null(v1form)) { goto L7; }
   v4 = ecl_function_dispatch(cl_env_copy,VV[136])(1, v1form) /*  C1FORM-FILE-POSITION */;
   goto L5;
L7:;
   v4 = ECL_NIL;
   goto L5;
L5:;
   ecl_bds_bind(cl_env_copy,VV[41],ECL_NIL);      /*  *IHS-USED-P*    */
   ecl_bds_bind(cl_env_copy,VV[42],ecl_make_fixnum(0)); /*  *MAX-LEX* */
   ecl_bds_bind(cl_env_copy,VV[43],ecl_make_fixnum(0)); /*  *MAX-ENV* */
   ecl_bds_bind(cl_env_copy,VV[44],ecl_make_fixnum(0)); /*  *MAX-TEMP* */
   ecl_bds_bind(cl_env_copy,VV[45],ecl_make_fixnum(0)); /*  *LCL*     */
   ecl_bds_bind(cl_env_copy,VV[46],ecl_make_fixnum(0)); /*  *LEX*     */
   ecl_bds_bind(cl_env_copy,VV[47],ecl_make_fixnum(0)); /*  *ENV*     */
   ecl_bds_bind(cl_env_copy,VV[48],ecl_make_fixnum(0)); /*  *LEVEL*   */
   ecl_bds_bind(cl_env_copy,VV[49],ecl_make_fixnum(0)); /*  *TEMP*    */
   ecl_bds_bind(cl_env_copy,VV[50],ECL_NIL);      /*  *COMPILE-TO-LINKING-CALL* */
   ecl_bds_bind(cl_env_copy,ECL_SYM("*COMPILE-FILE-TRUENAME*",27),v3); /*  *COMPILE-FILE-TRUENAME* */
   ecl_bds_bind(cl_env_copy,VV[14],v4);           /*  *COMPILE-FILE-POSITION* */
   {
    cl_object v5body;
    T0 = cl_make_string_output_stream(0);
    ecl_bds_bind(cl_env_copy,VV[24],T0);          /*  *COMPILER-OUTPUT1* */
    L4t2expr(v1form);
    v5body = cl_get_output_stream_string(ecl_symbol_value(VV[24]));
    ecl_bds_unwind1(cl_env_copy);
    if (ecl_plusp(ecl_symbol_value(VV[42]))) { goto L14; }
    if (ecl_plusp(ecl_symbol_value(VV[44]))) { goto L14; }
    if (ecl_plusp(ecl_symbol_value(VV[43]))) { goto L14; }
    if (Null(ecl_symbol_value(VV[41]))) { goto L12; }
    goto L13;
L14:;
L13:;
    ecl_function_dispatch(cl_env_copy,VV[146])(0) /*  WT-NL-OPEN-BRACE */;
    L15wt_function_locals(0);
    cl_write_sequence(2, v5body, ecl_symbol_value(VV[24]));
    ecl_function_dispatch(cl_env_copy,VV[156])(0) /*  WT-NL-CLOSE-BRACE */;
    goto L9;
L12:;
    cl_write_sequence(2, v5body, ecl_symbol_value(VV[24]));
   }
L9:;
   ecl_bds_bind(cl_env_copy,VV[24],v2c_output_file); /*  *COMPILER-OUTPUT1* */
   value0 = L5emit_local_funs();
   ecl_bds_unwind_n(cl_env_copy,13);
   return value0;
  }
 }
}
/*	function definition for C1EVAL-WHEN                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8c1eval_when(cl_object v1args)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_function_dispatch(cl_env_copy,VV[158])(3, ECL_SYM("EVAL-WHEN",340), v1args, ecl_make_fixnum(1)) /*  CHECK-ARGS-NUMBER */;
  {
   cl_object v2load_flag;
   cl_object v3compile_flag;
   cl_object v4execute_flag;
   v2load_flag = ECL_NIL;
   v3compile_flag = ECL_NIL;
   v4execute_flag = ECL_NIL;
   {
    cl_object v5;
    v5 = ecl_car(v1args);
    goto L9;
L8:;
    {
     cl_object v6situation;
     v6situation = ecl_car(v5);
     if (!((v6situation)==(ECL_SYM("LOAD",487)))) { goto L19; }
     goto L16;
     goto L17;
L19:;
     goto L17;
L17:;
     if (!(ecl_eql(v6situation,ECL_SYM("LOAD-TOPLEVEL",1270)))) { goto L14; }
     goto L15;
L16:;
L15:;
     v2load_flag = ECL_T;
     goto L13;
L14:;
     if (!((v6situation)==(ECL_SYM("COMPILE",233)))) { goto L28; }
     goto L25;
     goto L26;
L28:;
     goto L26;
L26:;
     if (!(ecl_eql(v6situation,ECL_SYM("COMPILE-TOPLEVEL",1207)))) { goto L23; }
     goto L24;
L25:;
L24:;
     v3compile_flag = ECL_T;
     goto L13;
L23:;
     if (!((v6situation)==(ECL_SYM("EVAL",339)))) { goto L37; }
     goto L34;
     goto L35;
L37:;
     goto L35;
L35:;
     if (!(ecl_eql(v6situation,ECL_SYM("EXECUTE",1231)))) { goto L32; }
     goto L33;
L34:;
L33:;
     if (Null(ecl_symbol_value(VV[11]))) { goto L40; }
     value0 = ecl_symbol_value(VV[17]);
     if ((value0)!=ECL_NIL) { goto L44; }
     goto L42;
L44:;
     v3compile_flag = value0;
     goto L42;
L42:;
     goto L13;
L40:;
     v4execute_flag = ECL_T;
     goto L13;
L32:;
     ecl_function_dispatch(cl_env_copy,VV[127])(2, _ecl_static_64, v6situation) /*  CMPERR */;
L13:;
    }
    v5 = ecl_cdr(v5);
L9:;
    if (Null(v5)) { goto L49; }
    goto L8;
L49:;
   }
   if ((ecl_symbol_value(VV[11]))!=ECL_NIL) { goto L51; }
   if (Null(v4execute_flag)) { goto L55; }
   T0 = ecl_cdr(v1args);
   goto L53;
L55:;
   T0 = ECL_NIL;
   goto L53;
L53:;
   value0 = ecl_function_dispatch(cl_env_copy,VV[159])(1, T0) /*  C1PROGN */;
   return value0;
L51:;
   if (Null(v2load_flag)) { goto L57; }
   ecl_bds_bind(cl_env_copy,VV[17],v3compile_flag); /*  *COMPILE-TIME-TOO* */
   T0 = ecl_cdr(v1args);
   value0 = ecl_function_dispatch(cl_env_copy,VV[159])(1, T0) /*  C1PROGN */;
   ecl_bds_unwind1(cl_env_copy);
   return value0;
L57:;
   if (Null(v3compile_flag)) { goto L59; }
   T0 = ecl_cdr(v1args);
   T1 = CONS(ECL_SYM("PROGN",671),T0);
   ecl_function_dispatch(cl_env_copy,VV[160])(1, T1) /*  CMP-EVAL     */;
   value0 = ecl_function_dispatch(cl_env_copy,VV[159])(1, ECL_NIL) /*  C1PROGN */;
   return value0;
L59:;
   value0 = ecl_function_dispatch(cl_env_copy,VV[159])(1, ECL_NIL) /*  C1PROGN */;
   return value0;
  }
 }
}
/*	function definition for T2COMPILER-LET                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L9t2compiler_let(cl_object v1c1form, cl_object v2symbols, cl_object v3values, cl_object v4body)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6, v7; cl_index v5;
   v6 = v2symbols;
   v7 = v3values;
   v5 = ecl_progv(cl_env_copy, v6, v7);
   value0 = ecl_function_dispatch(cl_env_copy,VV[162])(1, v4body) /*  C2EXPR */;
   ecl_bds_unwind(cl_env_copy,v5);
   return value0;
  }
 }
}
/*	function definition for T2PROGN                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L10t2progn(cl_object v1c1form, cl_object v2args)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   v3 = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v2args))) FEtype_error_list(v2args);
   v4 = v2args;
L4:;
   if (!(ecl_endp(v4))) { goto L6; }
   goto L5;
L6:;
   v3 = _ecl_car(v4);
   {
    cl_object v5;
    v5 = _ecl_cdr(v4);
    if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
    v4 = v5;
   }
   L4t2expr(v3);
   goto L4;
L5:;
   value0 = v2args;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for EXPORTED-FNAME                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L11exported_fname(cl_object v1name)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2cname;
   v2cname = ECL_NIL;
   if (!(ECL_SYMBOLP(v1name))) { goto L2; }
   v2cname = si_get_sysprop(v1name, VV[61]);
   if (Null(v2cname)) { goto L2; }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = ECL_T;
   cl_env_copy->values[0] = v2cname;
   return cl_env_copy->values[0];
L2:;
   T0 = ecl_function_dispatch(cl_env_copy,VV[165])(2, _ecl_static_65, v1name) /*  NEXT-CFUN */;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = ECL_NIL;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for NEW-DEFUN                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L12new_defun(cl_narg narg, cl_object v1new, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2no_entry;
  va_list args; va_start(args,v1new);
  {
   int i = 1;
   if (i >= narg) {
    v2no_entry = ECL_NIL;
   } else {
    i++;
    v2no_entry = va_arg(args,cl_object);
   }
  }
  va_end(args);
  cl_set(VV[63],CONS(v1new,ecl_symbol_value(VV[63])));
  value0 = ecl_symbol_value(VV[63]);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for PRINT-FUNCTION                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L13print_function(cl_object v1x)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[168])(1, v1x) /*  FUN-NAME */;
  T1 = ecl_function_dispatch(cl_env_copy,VV[169])(1, v1x) /*  FUN-CLOSURE */;
  T2 = ecl_function_dispatch(cl_env_copy,VV[170])(1, v1x) /*  FUN-LEVEL */;
  T3 = ecl_function_dispatch(cl_env_copy,VV[171])(1, v1x) /*  FUN-ENV */;
  value0 = cl_format(6, ECL_T, _ecl_static_66, T0, T1, T2, T3);
  return value0;
 }
}
/*	local function AND!                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC14and_(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_cdr(v1);
   T0 = CONS(ECL_SYM("LIST",481),v3);
   T1 = cl_list(2, VV[66], T0);
   T2 = ecl_list1(T1);
   value0 = cl_listX(3, ECL_SYM("LET",477), T2, VV[67]);
   return value0;
  }
 }
}
/*	function definition for WT-FUNCTION-LOCALS                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L15wt_function_locals(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1closure_type;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1closure_type = ECL_NIL;
   } else {
    i++;
    v1closure_type = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (!(ecl_plusp(ecl_symbol_value(VV[44])))) { goto L2; }
  ecl_function_dispatch(cl_env_copy,VV[143])(1, _ecl_static_67) /*  WT-NL */;
  {
   cl_object v2;
   v2 = ecl_symbol_value(VV[44]);
   {
    cl_object v3i;
    v3i = ecl_make_fixnum(0);
    goto L9;
L8:;
    ecl_function_dispatch(cl_env_copy,VV[174])(2, _ecl_static_68, v3i) /*  WT */;
    T0 = ecl_one_plus(v3i);
    if (ecl_number_equalp(T0,ecl_symbol_value(VV[44]))) { goto L12; }
    ecl_function_dispatch(cl_env_copy,VV[174])(1, _ecl_static_69) /*  WT */;
L12:;
    v3i = ecl_one_plus(v3i);
L9:;
    if (!(ecl_number_compare(v3i,v2)<0)) { goto L16; }
    goto L8;
L16:;
   }
  }
  ecl_function_dispatch(cl_env_copy,VV[174])(1, _ecl_static_51) /*  WT */;
L2:;
  if (Null(ecl_symbol_value(VV[41]))) { goto L18; }
  ecl_function_dispatch(cl_env_copy,VV[143])(1, _ecl_static_70) /*  WT-NL */;
  ecl_function_dispatch(cl_env_copy,VV[143])(1, _ecl_static_71) /*  WT-NL */;
L18:;
  if (!(ecl_plusp(ecl_symbol_value(VV[42])))) { goto L21; }
  ecl_function_dispatch(cl_env_copy,VV[143])(5, _ecl_static_72, ecl_symbol_value(VV[48]), _ecl_static_73, ecl_symbol_value(VV[42]), _ecl_static_74) /*  WT-NL */;
L21:;
  if (!(ecl_plusp(ecl_symbol_value(VV[43])))) { goto L23; }
  if ((v1closure_type)==(VV[69])) { goto L25; }
  ecl_function_dispatch(cl_env_copy,VV[143])(3, _ecl_static_67, ecl_symbol_value(VV[20]), _ecl_static_75) /*  WT-NL */;
L25:;
  if (Null(ecl_symbol_value(VV[23]))) { goto L27; }
  ecl_function_dispatch(cl_env_copy,VV[143])(1, _ecl_static_76) /*  WT-NL */;
L27:;
  ecl_function_dispatch(cl_env_copy,VV[143])(2, _ecl_static_67, ecl_symbol_value(VV[20])) /*  WT-NL */;
  {
   cl_object v2;
   v2 = ecl_symbol_value(VV[43]);
   {
    cl_object v3i;
    v3i = ecl_make_fixnum(0);
    goto L34;
L33:;
    ecl_function_dispatch(cl_env_copy,VV[174])(2, _ecl_static_77, v3i) /*  WT */;
    T0 = ecl_one_plus(v3i);
    if (ecl_number_equalp(T0,ecl_symbol_value(VV[43]))) { goto L37; }
    ecl_function_dispatch(cl_env_copy,VV[174])(1, _ecl_static_69) /*  WT */;
L37:;
    v3i = ecl_one_plus(v3i);
L34:;
    if (!(ecl_number_compare(v3i,v2)<0)) { goto L41; }
    goto L33;
L41:;
   }
  }
  value0 = ecl_function_dispatch(cl_env_copy,VV[143])(1, _ecl_static_51) /*  WT-NL */;
  return value0;
L23:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for WT-GLOBAL-ENTRY                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L16wt_global_entry(cl_object v1fname, cl_object v2cfun, cl_object v3arg_types, cl_object v4return_type)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_SYMBOLP(v1fname))) { goto L1; }
  if (Null(si_get_sysprop(v1fname, VV[71]))) { goto L1; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  ecl_function_dispatch(cl_env_copy,VV[176])(2, _ecl_static_78, v1fname) /*  WT-COMMENT-NL */;
  ecl_function_dispatch(cl_env_copy,VV[143])(3, _ecl_static_79, v2cfun, _ecl_static_80) /*  WT-NL */;
  ecl_function_dispatch(cl_env_copy,VV[144])(3, _ecl_static_79, v2cfun, _ecl_static_81) /*  WT-NL-H */;
  {
   cl_object v5;
   cl_object v6vl;
   cl_fixnum v7lcl;
   v5 = ecl_one_plus(ecl_symbol_value(VV[45]));
   v6vl = v3arg_types;
   {
    bool v8;
    v8 = ECL_FIXNUMP(v5);
    if (ecl_unlikely(!(v8)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v5);
   }
   v7lcl = ecl_fixnum(v5);
   goto L14;
L13:;
   ecl_function_dispatch(cl_env_copy,VV[177])(1, _ecl_static_82) /*  WT1 */;
   ecl_function_dispatch(cl_env_copy,VV[178])(1, ecl_make_fixnum(v7lcl)) /*  WT-LCL */;
   ecl_function_dispatch(cl_env_copy,VV[153])(1, _ecl_static_83) /*  WT-H */;
   v6vl = ecl_cdr(v6vl);
   {
    cl_object v8;
    v8 = ecl_make_integer((v7lcl)+1);
    {
     bool v9;
     v9 = ECL_FIXNUMP(v8);
     if (ecl_unlikely(!(v9)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v8);
    }
    v7lcl = ecl_fixnum(v8);
   }
L14:;
   if (ecl_endp(v6vl)) { goto L24; }
   goto L13;
L24:;
   ecl_function_dispatch(cl_env_copy,VV[177])(1, _ecl_static_84) /*  WT1 */;
  }
  ecl_function_dispatch(cl_env_copy,VV[179])(1, _ecl_static_85) /*  WT-H1 */;
  ecl_function_dispatch(cl_env_copy,VV[146])(0)   /*  WT-NL-OPEN-BRACE */;
  if (Null(ecl_function_dispatch(cl_env_copy,VV[180])(0) /*  COMPILER-CHECK-ARGS */)) { goto L28; }
  {
   cl_fixnum v5;
   v5 = ecl_length(v3arg_types);
   ecl_function_dispatch(cl_env_copy,VV[143])(3, _ecl_static_86, ecl_make_fixnum(v5), _ecl_static_85) /*  WT-NL */;
  }
L28:;
  ecl_function_dispatch(cl_env_copy,VV[143])(1, _ecl_static_87) /*  WT-NL */;
  if (!((v4return_type)==(ECL_SYM("FIXNUM",372)))) { goto L33; }
  T0 = _ecl_static_89;
  goto L32;
L33:;
  if (!((v4return_type)==(ECL_SYM("CHARACTER",222)))) { goto L35; }
  T0 = _ecl_static_90;
  goto L32;
L35:;
  if (!((v4return_type)==(ECL_SYM("DOUBLE-FLOAT",315)))) { goto L37; }
  T0 = _ecl_static_91;
  goto L32;
L37:;
  if (!((v4return_type)==(ECL_SYM("SINGLE-FLOAT",778)))) { goto L39; }
  T0 = _ecl_static_92;
  goto L32;
L39:;
  if (!((v4return_type)==(ECL_SYM("LONG-FLOAT",508)))) { goto L41; }
  T0 = _ecl_static_93;
  goto L32;
L41:;
  T0 = _ecl_static_94;
L32:;
  ecl_function_dispatch(cl_env_copy,VV[143])(5, _ecl_static_88, T0, _ecl_static_95, v2cfun, _ecl_static_96) /*  WT-NL */;
  {
   cl_object v5types;
   cl_fixnum v6n;
   v5types = v3arg_types;
   v6n = 1;
   goto L48;
L47:;
   {
    cl_object v7;
    v7 = ecl_car(v5types);
    if (!((v7)==(ECL_SYM("FIXNUM",372)))) { goto L53; }
    T0 = _ecl_static_97;
    goto L51;
L53:;
    if (!((v7)==(ECL_SYM("CHARACTER",222)))) { goto L55; }
    T0 = _ecl_static_98;
    goto L51;
L55:;
    if (!((v7)==(ECL_SYM("DOUBLE-FLOAT",315)))) { goto L57; }
    T0 = _ecl_static_99;
    goto L51;
L57:;
    if (!((v7)==(ECL_SYM("SINGLE-FLOAT",778)))) { goto L59; }
    T0 = _ecl_static_100;
    goto L51;
L59:;
    if (!((v7)==(ECL_SYM("LONG-FLOAT",508)))) { goto L61; }
    T0 = _ecl_static_101;
    goto L51;
L61:;
    T0 = _ecl_static_94;
   }
L51:;
   ecl_function_dispatch(cl_env_copy,VV[174])(2, T0, _ecl_static_96) /*  WT */;
   ecl_function_dispatch(cl_env_copy,VV[178])(1, ecl_make_fixnum(v6n)) /*  WT-LCL */;
   ecl_function_dispatch(cl_env_copy,VV[174])(1, _ecl_static_84) /*  WT */;
   T0 = ecl_cdr(v5types);
   if (ecl_endp(T0)) { goto L65; }
   ecl_function_dispatch(cl_env_copy,VV[174])(1, _ecl_static_102) /*  WT */;
L65:;
   v5types = ecl_cdr(v5types);
   {
    cl_object v7;
    v7 = ecl_make_integer((v6n)+1);
    {
     bool v8;
     v8 = ECL_FIXNUMP(v7);
     if (ecl_unlikely(!(v8)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v7);
    }
    v6n = ecl_fixnum(v7);
   }
L48:;
   if (ecl_endp(v5types)) { goto L72; }
   goto L47;
L72:;
  }
  ecl_function_dispatch(cl_env_copy,VV[174])(1, _ecl_static_103) /*  WT */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[149])(1, ecl_make_fixnum(0)) /*  WT-NL-CLOSE-MANY-BRACES */;
  return value0;
 }
}
/*	function definition for REP-TYPE                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L17rep_type(cl_object v1type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!((v1type)==(ECL_SYM("FIXNUM",372)))) { goto L1; }
  value0 = _ecl_static_104;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (!((v1type)==(ECL_SYM("CHARACTER",222)))) { goto L3; }
  value0 = _ecl_static_105;
  cl_env_copy->nvalues = 1;
  return value0;
L3:;
  if (!((v1type)==(ECL_SYM("SINGLE-FLOAT",778)))) { goto L5; }
  value0 = _ecl_static_106;
  cl_env_copy->nvalues = 1;
  return value0;
L5:;
  if (!((v1type)==(ECL_SYM("DOUBLE-FLOAT",315)))) { goto L7; }
  value0 = _ecl_static_107;
  cl_env_copy->nvalues = 1;
  return value0;
L7:;
  value0 = _ecl_static_67;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for T1ORDINARY                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L18t1ordinary(cl_object v1form)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_symbol_value(VV[17]))) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[160])(1, v1form) /*  CMP-EVAL  */;
L1:;
  ecl_bds_bind(cl_env_copy,VV[11],ECL_NIL);       /*  *COMPILE-TOPLEVEL* */
  ecl_bds_bind(cl_env_copy,VV[17],ECL_NIL);       /*  *COMPILE-TIME-TOO* */
  T0 = ecl_function_dispatch(cl_env_copy,VV[132])(1, v1form) /*  C1EXPR */;
  T1 = ecl_function_dispatch(cl_env_copy,VV[183])(3, VV[74], VV[75], T0) /*  MAKE-C1FORM* */;
  value0 = L21add_load_time_values(T1);
  ecl_bds_unwind1(cl_env_copy);
  ecl_bds_unwind1(cl_env_copy);
  return value0;
 }
}
/*	function definition for P1ORDINARY                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L19p1ordinary(cl_object v1c1form, cl_object v2assumptions, cl_object v3form)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[30])(2, v3form, v2assumptions) /*  P1PROPAGATE */;
  return value0;
 }
}
/*	function definition for T2ORDINARY                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L20t2ordinary(cl_object v1c1form, cl_object v2form)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[186])(0) /*  NEXT-LABEL   */;
  ecl_bds_bind(cl_env_copy,VV[78],T0);            /*  *EXIT*          */
  T0 = ecl_list1(ecl_symbol_value(VV[78]));
  ecl_bds_bind(cl_env_copy,VV[79],T0);            /*  *UNWIND-EXIT*   */
  ecl_bds_bind(cl_env_copy,VV[80],VV[81]);        /*  *DESTINATION*   */
  ecl_function_dispatch(cl_env_copy,VV[162])(1, v2form) /*  C2EXPR    */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[187])(1, ecl_symbol_value(VV[78])) /*  WT-LABEL */;
  ecl_bds_unwind1(cl_env_copy);
  ecl_bds_unwind1(cl_env_copy);
  ecl_bds_unwind1(cl_env_copy);
  return value0;
 }
}
/*	function definition for ADD-LOAD-TIME-VALUES                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L21add_load_time_values(cl_object v1form)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2previous;
   if (!(ECL_CONSP(ecl_symbol_value(VV[83])))) { goto L5; }
   T0 = cl_nreverse(ecl_symbol_value(VV[83]));
   goto L3;
L5:;
   T0 = ECL_NIL;
   goto L3;
L3:;
   T1 = cl_nreverse(ecl_symbol_value(VV[32]));
   v2previous = ecl_append(T0,T1);
   if (Null(v2previous)) { goto L1; }
   cl_set(VV[83],ECL_NIL);
   cl_set(VV[32],ECL_NIL);
   T0 = ecl_list1(v1form);
   T1 = ecl_nconc(v2previous,T0);
   v1form = ecl_function_dispatch(cl_env_copy,VV[183])(3, ECL_SYM("PROGN",671), VV[75], T1) /*  MAKE-C1FORM* */;
  }
L1:;
  value0 = v1form;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for T1DEFMACRO                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L22t1defmacro(cl_object v1args)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_function_dispatch(cl_env_copy,VV[158])(3, ECL_SYM("LOAD-TIME-VALUE",489), v1args, ecl_make_fixnum(2)) /*  CHECK-ARGS-NUMBER */;
  {
   cl_object v2;
   cl_object v3name;
   cl_object v4lambda_list;
   v2 = v1args;
   if (!(v2==ECL_NIL)) { goto L4; }
   si_dm_too_few_arguments(v1args);
L4:;
   {
    cl_object v5;
    v5 = ecl_car(v2);
    v2 = ecl_cdr(v2);
    v3name = v5;
   }
   if (!(v2==ECL_NIL)) { goto L10; }
   si_dm_too_few_arguments(v1args);
L10:;
   {
    cl_object v5;
    v5 = ecl_car(v2);
    v2 = ecl_cdr(v2);
    v4lambda_list = v5;
   }
   {
    cl_object v6;                                 /*  FUNCTION        */
    value0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("EXPAND-DEFMACRO",1068))(3, v3name, v4lambda_list, v2) /*  EXPAND-DEFMACRO */;
    v6 = value0;
    {
     cl_object v7fn;
     v7fn = ecl_function_dispatch(cl_env_copy,VV[160])(2, v6, ecl_symbol_value(VV[1])) /*  CMP-EVAL */;
     ecl_function_dispatch(cl_env_copy,VV[190])(2, v3name, v7fn) /*  CMP-ENV-REGISTER-GLOBAL-MACRO */;
    }
    T0 = CONS(ECL_SYM("DEFMACRO",283),v1args);
    T1 = cl_macroexpand(1, T0);
    value0 = L2t1expr_(T1);
    return value0;
   }
  }
 }
}
/*	function definition for C1LOAD-TIME-VALUE                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L23c1load_time_value(cl_object v1args)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_function_dispatch(cl_env_copy,VV[158])(4, ECL_SYM("LOAD-TIME-VALUE",489), v1args, ecl_make_fixnum(1), ecl_make_fixnum(2)) /*  CHECK-ARGS-NUMBER */;
  {
   cl_object v2;
   cl_object v3loc;
   v2 = ecl_car(v1args);
   v3loc = ECL_NIL;
   if (ECL_LISTP(ecl_symbol_value(VV[83]))) { goto L5; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[160])(1, v2) /*  CMP-EVAL */;
   value0 = ecl_function_dispatch(cl_env_copy,VV[192])(3, T0, VV[86], ECL_T) /*  C1CONSTANT-VALUE */;
   return value0;
L5:;
   if (ECL_LISTP(v2)) { goto L9; }
   if (!(ECL_SYMBOLP(v2))) { goto L7; }
   goto L8;
L9:;
L8:;
   v3loc = ecl_function_dispatch(cl_env_copy,VV[193])(0) /*  DATA-EMPTY-LOC */;
   T0 = ecl_function_dispatch(cl_env_copy,VV[132])(1, v2) /*  C1EXPR  */;
   T1 = ecl_function_dispatch(cl_env_copy,VV[183])(4, ECL_SYM("LOAD-TIME-VALUE",489), VV[75], v3loc, T0) /*  MAKE-C1FORM* */;
   cl_set(VV[83],CONS(T1,ecl_symbol_value(VV[83])));
   goto L4;
L7:;
   T0 = ecl_function_dispatch(cl_env_copy,VV[160])(1, v2) /*  CMP-EVAL */;
   v3loc = ecl_function_dispatch(cl_env_copy,VV[194])(1, T0) /*  ADD-OBJECT */;
L4:;
   value0 = ecl_function_dispatch(cl_env_copy,VV[183])(5, ECL_SYM("LOCATION",1763), ECL_SYM("TYPE",1318), ECL_T, VV[75], v3loc) /*  MAKE-C1FORM* */;
   return value0;
  }
 }
}
/*	function definition for T2LOAD-TIME-VALUE                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L24t2load_time_value(cl_object v1c1form, cl_object v2vv_loc, cl_object v3form)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[186])(0) /*  NEXT-LABEL   */;
  ecl_bds_bind(cl_env_copy,VV[78],T0);            /*  *EXIT*          */
  T0 = ecl_list1(ecl_symbol_value(VV[78]));
  ecl_bds_bind(cl_env_copy,VV[79],T0);            /*  *UNWIND-EXIT*   */
  ecl_bds_bind(cl_env_copy,VV[80],v2vv_loc);      /*  *DESTINATION*   */
  ecl_function_dispatch(cl_env_copy,VV[162])(1, v3form) /*  C2EXPR    */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[187])(1, ecl_symbol_value(VV[78])) /*  WT-LABEL */;
  ecl_bds_unwind1(cl_env_copy);
  ecl_bds_unwind1(cl_env_copy);
  ecl_bds_unwind1(cl_env_copy);
  return value0;
 }
}
/*	function definition for T2MAKE-FORM                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L25t2make_form(cl_object v1c1form, cl_object v2vv_loc, cl_object v3form)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[186])(0) /*  NEXT-LABEL   */;
  ecl_bds_bind(cl_env_copy,VV[78],T0);            /*  *EXIT*          */
  T0 = ecl_list1(ecl_symbol_value(VV[78]));
  ecl_bds_bind(cl_env_copy,VV[79],T0);            /*  *UNWIND-EXIT*   */
  ecl_bds_bind(cl_env_copy,VV[80],v2vv_loc);      /*  *DESTINATION*   */
  ecl_function_dispatch(cl_env_copy,VV[162])(1, v3form) /*  C2EXPR    */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[187])(1, ecl_symbol_value(VV[78])) /*  WT-LABEL */;
  ecl_bds_unwind1(cl_env_copy);
  ecl_bds_unwind1(cl_env_copy);
  ecl_bds_unwind1(cl_env_copy);
  return value0;
 }
}
/*	function definition for T2INIT-FORM                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L26t2init_form(cl_object v1c1form, cl_object v2vv_loc, cl_object v3form)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[186])(0) /*  NEXT-LABEL   */;
  ecl_bds_bind(cl_env_copy,VV[78],T0);            /*  *EXIT*          */
  T0 = ecl_list1(ecl_symbol_value(VV[78]));
  ecl_bds_bind(cl_env_copy,VV[79],T0);            /*  *UNWIND-EXIT*   */
  ecl_bds_bind(cl_env_copy,VV[80],VV[81]);        /*  *DESTINATION*   */
  ecl_function_dispatch(cl_env_copy,VV[162])(1, v3form) /*  C2EXPR    */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[187])(1, ecl_symbol_value(VV[78])) /*  WT-LABEL */;
  ecl_bds_unwind1(cl_env_copy);
  ecl_bds_unwind1(cl_env_copy);
  ecl_bds_unwind1(cl_env_copy);
  return value0;
 }
}
/*	function definition for PARSE-CVSPECS                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L27parse_cvspecs(cl_object v1x)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2cvspecs;
   v2cvspecs = ECL_NIL;
   {
    cl_object v3;
    v3 = v1x;
    goto L5;
L4:;
    {
     cl_object v4cvs;
     v4cvs = ecl_car(v3);
     if (!(ECL_SYMBOLP(v4cvs))) { goto L10; }
     T0 = ecl_symbol_name(v4cvs);
     T1 = cl_string_downcase(1, T0);
     T2 = cl_list(2, ECL_SYM("OBJECT",1278), T1);
     v2cvspecs = CONS(T2,v2cvspecs);
     goto L9;
L10:;
     if (!(ECL_STRINGP(v4cvs))) { goto L13; }
     T0 = cl_list(2, ECL_SYM("OBJECT",1278), v4cvs);
     v2cvspecs = CONS(T0,v2cvspecs);
     goto L9;
L13:;
     if (!(ECL_CONSP(v4cvs))) { goto L16; }
     T0 = ecl_car(v4cvs);
     if (Null(ecl_memql(T0,VV[91]))) { goto L16; }
     {
      cl_object v5;
      v5 = ecl_cdr(v4cvs);
      goto L22;
L21:;
      {
       cl_object v6name;
       v6name = ecl_car(v5);
       T0 = ecl_car(v4cvs);
       if (!(ECL_SYMBOLP(v6name))) { goto L29; }
       T2 = ecl_symbol_name(v6name);
       T1 = cl_string_downcase(1, T2);
       goto L28;
L29:;
       if (!(ECL_STRINGP(v6name))) { goto L31; }
       T1 = v6name;
       goto L28;
L31:;
       T1 = ecl_function_dispatch(cl_env_copy,VV[127])(2, _ecl_static_108, v6name) /*  CMPERR */;
L28:;
       T2 = cl_list(2, T0, T1);
       v2cvspecs = CONS(T2,v2cvspecs);
      }
      v5 = ecl_cdr(v5);
L22:;
      if (Null(v5)) { goto L35; }
      goto L21;
L35:;
      goto L9;
     }
L16:;
     ecl_function_dispatch(cl_env_copy,VV[127])(2, _ecl_static_109, v4cvs) /*  CMPERR */;
L9:;
    }
    v3 = ecl_cdr(v3);
L5:;
    if (Null(v3)) { goto L39; }
    goto L4;
L39:;
    value0 = cl_nreverse(v2cvspecs);
    return value0;
   }
  }
 }
}
/*	function definition for LOCATIVE-TYPE-FROM-VAR-KIND           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L28locative_type_from_var_kind(cl_object v1kind)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_assql(v1kind,VV[93]);
  value0 = ecl_cdr(T0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for BUILD-DEBUG-LEXICAL-ENV               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L29build_debug_lexical_env(cl_narg narg, cl_object v1var_locations, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2first;
  va_list args; va_start(args,v1var_locations);
  {
   int i = 1;
   if (i >= narg) {
    v2first = ECL_NIL;
   } else {
    i++;
    v2first = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v3filtered_locations;
   cl_object v4filtered_codes;
   v3filtered_locations = ECL_NIL;
   v4filtered_codes = ECL_NIL;
   {
    cl_object v5var;
    cl_object v6;
    v5var = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v1var_locations))) FEtype_error_list(v1var_locations);
    v6 = v1var_locations;
    {
     cl_object v7name;
     v7name = ECL_NIL;
     {
      cl_object v8code;
      v8code = ECL_NIL;
      {
       cl_object v9loc;
       v9loc = ECL_NIL;
L11:;
       if (!(ecl_endp(v6))) { goto L13; }
       goto L12;
L13:;
       v5var = _ecl_car(v6);
       {
        cl_object v10;
        v10 = _ecl_cdr(v6);
        if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
        v6 = v10;
       }
       T0 = cl_find_package(_ecl_static_110);
       ecl_bds_bind(cl_env_copy,ECL_SYM("*PACKAGE*",43),T0); /*  *PACKAGE* */
       T0 = ecl_function_dispatch(cl_env_copy,VV[201])(1, v5var) /*  VAR-NAME */;
       v7name = cl_format(3, ECL_NIL, _ecl_static_111, T0);
       ecl_bds_unwind1(cl_env_copy);
       T0 = ecl_function_dispatch(cl_env_copy,VV[202])(1, v5var) /*  VAR-KIND */;
       v8code = L28locative_type_from_var_kind(T0);
       v9loc = ecl_function_dispatch(cl_env_copy,VV[203])(1, v5var) /*  VAR-LOC */;
       if (Null(v8code)) { goto L27; }
       if (!(ECL_CONSP(v9loc))) { goto L27; }
       T0 = ecl_car(v9loc);
       if (!((T0)==(VV[95]))) { goto L27; }
       T0 = CONS(v7name,v8code);
       v4filtered_codes = CONS(T0,v4filtered_codes);
       v3filtered_locations = CONS(v9loc,v3filtered_locations);
L27:;
       goto L11;
L12:;
      }
     }
    }
   }
   if (Null(v4filtered_codes)) { goto L35; }
   cl_set(VV[41],ECL_T);
   ecl_function_dispatch(cl_env_copy,VV[143])(1, _ecl_static_112) /*  WT-NL */;
   {
    cl_object v5name;
    cl_object v6code;
    cl_object v7;
    v5name = ECL_NIL;
    v6code = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v4filtered_codes))) FEtype_error_list(v4filtered_codes);
    v7 = v4filtered_codes;
    {
     cl_object v8i;
     v8i = ecl_make_fixnum(0);
     {
      cl_object v9;
      v9 = ECL_NIL;
L47:;
      if (!(ecl_endp(v7))) { goto L49; }
      goto L48;
L49:;
      {
       cl_object v10;
       v10 = _ecl_car(v7);
       v5name = ecl_car(v10);
       v10 = ecl_cdr(v10);
       v6code = v10;
      }
      {
       cl_object v10;
       v10 = _ecl_cdr(v7);
       if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
       v7 = v10;
      }
      if (Null(v9)) { goto L63; }
      v8i = ecl_one_plus(v8i);
      goto L62;
L63:;
      v9 = ECL_T;
L62:;
      if (!(ecl_zerop(v8i))) { goto L69; }
      T0 = _ecl_static_113;
      goto L68;
L69:;
      T0 = _ecl_static_114;
L68:;
      ecl_function_dispatch(cl_env_copy,VV[143])(5, T0, v5name, _ecl_static_102, v6code, _ecl_static_59) /*  WT-NL */;
      goto L47;
L48:;
     }
    }
   }
   ecl_function_dispatch(cl_env_copy,VV[174])(1, _ecl_static_115) /*  WT */;
   ecl_function_dispatch(cl_env_copy,VV[143])(1, _ecl_static_116) /*  WT-NL */;
   if (Null(v2first)) { goto L76; }
   T0 = _ecl_static_117;
   goto L75;
L76:;
   T0 = _ecl_static_118;
L75:;
   ecl_function_dispatch(cl_env_copy,VV[143])(2, T0, _ecl_static_119) /*  WT-NL */;
   {
    cl_object v5var_loc;
    cl_object v6;
    v5var_loc = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v3filtered_locations))) FEtype_error_list(v3filtered_locations);
    v6 = v3filtered_locations;
L82:;
    if (!(ecl_endp(v6))) { goto L84; }
    goto L83;
L84:;
    v5var_loc = _ecl_car(v6);
    {
     cl_object v7;
     v7 = _ecl_cdr(v6);
     if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
     v6 = v7;
    }
    ecl_function_dispatch(cl_env_copy,VV[174])(3, _ecl_static_120, v5var_loc, _ecl_static_84) /*  WT */;
    goto L82;
L83:;
   }
   ecl_function_dispatch(cl_env_copy,VV[174])(1, _ecl_static_115) /*  WT */;
   {
    cl_fixnum v5;
    v5 = ecl_length(v3filtered_locations);
    T0 = ecl_plus(ecl_make_fixnum(2),ecl_make_fixnum(v5));
    ecl_function_dispatch(cl_env_copy,VV[143])(3, _ecl_static_121, T0, _ecl_static_122) /*  WT-NL */;
   }
   if ((v2first)!=ECL_NIL) { goto L35; }
   ecl_function_dispatch(cl_env_copy,VV[143])(1, _ecl_static_123) /*  WT-NL */;
L35:;
   value0 = v4filtered_codes;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for POP-DEBUG-LEXICAL-ENV                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L30pop_debug_lexical_env()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[143])(1, _ecl_static_123) /*  WT-NL */;
  return value0;
 }
}
/*	function definition for T3LOCAL-FUN                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L31t3local_fun(cl_object v1fun)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_function_dispatch(cl_env_copy,VV[206])(1, v1fun) /*  PRINT-EMITTING */;
  {
   cl_object v2lambda_expr;
   v2lambda_expr = ecl_function_dispatch(cl_env_copy,VV[148])(1, v1fun) /*  FUN-LAMBDA */;
   T0 = ecl_function_dispatch(cl_env_copy,VV[138])(1, v2lambda_expr) /*  C1FORM-ENV */;
   ecl_bds_bind(cl_env_copy,VV[1],T0);            /*  *CMP-ENV*       */
   ecl_bds_bind(cl_env_copy,VV[45],ecl_make_fixnum(0)); /*  *LCL*     */
   ecl_bds_bind(cl_env_copy,VV[49],ecl_make_fixnum(0)); /*  *TEMP*    */
   ecl_bds_bind(cl_env_copy,VV[44],ecl_make_fixnum(0)); /*  *MAX-TEMP* */
   ecl_bds_bind(cl_env_copy,VV[98],ecl_make_fixnum(0)); /*  *LAST-LABEL* */
   ecl_bds_bind(cl_env_copy,VV[46],ecl_make_fixnum(0)); /*  *LEX*     */
   ecl_bds_bind(cl_env_copy,VV[42],ecl_make_fixnum(0)); /*  *MAX-LEX* */
   T0 = ecl_function_dispatch(cl_env_copy,VV[171])(1, v1fun) /*  FUN-ENV */;
   ecl_bds_bind(cl_env_copy,VV[47],T0);           /*  *ENV*           */
   ecl_bds_bind(cl_env_copy,VV[43],ecl_symbol_value(VV[47])); /*  *MAX-ENV* */
   ecl_bds_bind(cl_env_copy,VV[99],ecl_make_fixnum(0)); /*  *ENV-LVL* */
   ecl_bds_bind(cl_env_copy,VV[23],ECL_NIL);      /*  *AUX-CLOSURE*   */
   T0 = L36fun_lexical_levels(v1fun);
   ecl_bds_bind(cl_env_copy,VV[48],T0);           /*  *LEVEL*         */
   ecl_bds_bind(cl_env_copy,VV[78],ECL_SYM("RETURN",724)); /*  *EXIT* */
   ecl_bds_bind(cl_env_copy,VV[79],VV[100]);      /*  *UNWIND-EXIT*   */
   ecl_bds_bind(cl_env_copy,VV[80],ECL_SYM("RETURN",724)); /*  *DESTINATION* */
   ecl_bds_bind(cl_env_copy,VV[41],ECL_NIL);      /*  *IHS-USED-P*    */
   ecl_bds_bind(cl_env_copy,VV[22],ecl_make_fixnum(0)); /*  *OPENED-C-BRACES* */
   ecl_bds_bind(cl_env_copy,VV[101],v1fun);       /*  *TAIL-RECURSION-INFO* */
   T0 = ecl_function_dispatch(cl_env_copy,VV[207])(1, v2lambda_expr) /*  C1FORM-VOLATILE* */;
   ecl_bds_bind(cl_env_copy,VV[20],T0);           /*  *VOLATILE*      */
   if (Null(L33t3local_fun_declaration(v1fun))) { goto L3; }
   ecl_function_dispatch(cl_env_copy,VV[146])(0)  /*  WT-NL-OPEN-BRACE */;
   {
    cl_object v3body;
    v3body = L32t3local_fun_body(v1fun);
    T0 = ecl_function_dispatch(cl_env_copy,VV[169])(1, v1fun) /*  FUN-CLOSURE */;
    L15wt_function_locals(1, T0);
    ecl_function_dispatch(cl_env_copy,VV[143])(1, _ecl_static_16) /*  WT-NL */;
    T0 = ecl_function_dispatch(cl_env_copy,VV[169])(1, v1fun) /*  FUN-CLOSURE */;
    if (!((T0)==(VV[69]))) { goto L9; }
    ecl_function_dispatch(cl_env_copy,VV[174])(3, _ecl_static_67, ecl_symbol_value(VV[20]), _ecl_static_124) /*  WT */;
L9:;
    ecl_function_dispatch(cl_env_copy,VV[143])(2, ecl_symbol_value(VV[20]), _ecl_static_17) /*  WT-NL */;
    if (Null(ecl_function_dispatch(cl_env_copy,VV[208])(0) /*  POLICY-CHECK-STACK-OVERFLOW */)) { goto L12; }
    ecl_function_dispatch(cl_env_copy,VV[143])(1, _ecl_static_125) /*  WT-NL */;
L12:;
    T0 = ecl_function_dispatch(cl_env_copy,VV[169])(1, v1fun) /*  FUN-CLOSURE */;
    if (!((T0)==(VV[69]))) { goto L14; }
    L37t3local_fun_closure_scan(v1fun);
L14:;
    cl_write_sequence(2, v3body, ecl_symbol_value(VV[24]));
    value0 = ecl_function_dispatch(cl_env_copy,VV[149])(1, ecl_make_fixnum(0)) /*  WT-NL-CLOSE-MANY-BRACES */;
    ecl_bds_unwind_n(cl_env_copy,19);
    return value0;
   }
L3:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   ecl_bds_unwind_n(cl_env_copy,19);
   return value0;
  }
 }
}
/*	function definition for T3LOCAL-FUN-BODY                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L32t3local_fun_body(cl_object v1fun)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2string;
   v2string = si_make_vector(ECL_SYM("BASE-CHAR",120), ecl_make_fixnum(2048), ECL_T, ecl_make_fixnum(0), ECL_NIL, ecl_make_fixnum(0));
   T0 = si_make_string_output_stream_from_string(v2string);
   ecl_bds_bind(cl_env_copy,VV[24],T0);           /*  *COMPILER-OUTPUT1* */
   {
    cl_object v3lambda_expr;
    v3lambda_expr = ecl_function_dispatch(cl_env_copy,VV[148])(1, v1fun) /*  FUN-LAMBDA */;
    T0 = ecl_function_dispatch(cl_env_copy,VV[139])(1, v3lambda_expr) /*  C1FORM-ARGS */;
    T1 = ecl_car(T0);
    T2 = ecl_function_dispatch(cl_env_copy,VV[139])(1, v3lambda_expr) /*  C1FORM-ARGS */;
    T3 = ecl_caddr(T2);
    T4 = ecl_function_dispatch(cl_env_copy,VV[210])(1, v1fun) /*  FUN-CFUN */;
    T5 = ecl_function_dispatch(cl_env_copy,VV[168])(1, v1fun) /*  FUN-NAME */;
    T6 = ecl_function_dispatch(cl_env_copy,VV[211])(1, v1fun) /*  FUN-NEEDS-NARG */;
    T7 = ecl_function_dispatch(cl_env_copy,VV[212])(1, v1fun) /*  FUN-REQUIRED-LCLS */;
    T8 = ecl_function_dispatch(cl_env_copy,VV[169])(1, v1fun) /*  FUN-CLOSURE */;
    ecl_function_dispatch(cl_env_copy,VV[213])(7, T1, T3, T4, T5, T6, T7, T8) /*  C2LAMBDA-EXPR */;
    ecl_bds_unwind1(cl_env_copy);
   }
   value0 = v2string;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for T3LOCAL-FUN-DECLARATION               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L33t3local_fun_declaration(cl_object v1fun)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[215])(1, v1fun) /*  FUN-GLOBAL */)) { goto L3; }
  T0 = _ecl_static_126;
  goto L2;
L3:;
  T1 = ecl_function_dispatch(cl_env_copy,VV[169])(1, v1fun) /*  FUN-CLOSURE */;
  if (!((T1)==(VV[69]))) { goto L5; }
  T0 = _ecl_static_127;
  goto L2;
L5:;
  T0 = _ecl_static_128;
L2:;
  value0 = ecl_function_dispatch(cl_env_copy,VV[168])(1, v1fun) /*  FUN-NAME */;
  if ((value0)!=ECL_NIL) { goto L9; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[216])(1, v1fun) /*  FUN-DESCRIPTION */;
  if ((value0)!=ECL_NIL) { goto L9; }
  T1 = VV[69];
  goto L7;
L9:;
  T1 = value0;
  goto L7;
L7:;
  ecl_function_dispatch(cl_env_copy,VV[176])(2, T0, T1) /*  WT-COMMENT-NL */;
  if (Null(ecl_function_dispatch(cl_env_copy,VV[217])(1, v1fun) /*  FUN-SHARES-WITH */)) { goto L12; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[217])(1, v1fun) /*  FUN-SHARES-WITH */;
  T1 = ecl_function_dispatch(cl_env_copy,VV[168])(1, T0) /*  FUN-NAME */;
  ecl_function_dispatch(cl_env_copy,VV[176])(2, _ecl_static_129, T1) /*  WT-COMMENT-NL */;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L12:;
  {
   cl_object v2comma;
   cl_object v3lambda_expr;
   cl_object v4volatile;
   cl_object v5lambda_list;
   cl_object v6requireds;
   cl_object v7narg;
   v2comma = _ecl_static_94;
   v3lambda_expr = ecl_function_dispatch(cl_env_copy,VV[148])(1, v1fun) /*  FUN-LAMBDA */;
   v4volatile = ecl_function_dispatch(cl_env_copy,VV[207])(1, v3lambda_expr) /*  C1FORM-VOLATILE* */;
   T0 = ecl_function_dispatch(cl_env_copy,VV[139])(1, v3lambda_expr) /*  C1FORM-ARGS */;
   v5lambda_list = ecl_car(T0);
   {
    cl_object v8;
    cl_object v9;
    cl_object v10;
    v8 = ecl_car(v5lambda_list);
    v9 = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
    v10 = v8;
    {
     cl_object v11;
     cl_object v12;
     v11 = ecl_list1(ECL_NIL);
     v12 = v11;
L27:;
     if (!(ecl_endp(v10))) { goto L29; }
     goto L28;
L29:;
     v9 = _ecl_car(v10);
     {
      cl_object v13;
      v13 = _ecl_cdr(v10);
      if (ecl_unlikely(!ECL_LISTP(v13))) FEtype_error_list(v13);
      v10 = v13;
     }
     if (ecl_unlikely(ECL_ATOM(v12))) FEtype_error_cons(v12);
     T0 = v12;
     T2 = ecl_function_dispatch(cl_env_copy,VV[201])(1, v9) /*  VAR-NAME */;
     T1 = ecl_function_dispatch(cl_env_copy,VV[218])(1, T2) /*  NEXT-LCL */;
     v12 = ecl_list1(T1);
     (ECL_CONS_CDR(T0)=v12,T0);
     goto L27;
L28:;
     v6requireds = ecl_cdr(v11);
     goto L20;
    }
   }
L20:;
   v7narg = ecl_function_dispatch(cl_env_copy,VV[211])(1, v1fun) /*  FUN-NEEDS-NARG */;
   {
    cl_object v8cmp_env;
    v8cmp_env = ecl_function_dispatch(cl_env_copy,VV[138])(1, v3lambda_expr) /*  C1FORM-ENV */;
    T0 = ecl_function_dispatch(cl_env_copy,VV[219])(2, ECL_SYM("SPEED",791), v8cmp_env) /*  CMP-ENV-OPTIMIZATION */;
    T1 = ecl_function_dispatch(cl_env_copy,VV[219])(2, ECL_SYM("DEBUG",270), v8cmp_env) /*  CMP-ENV-OPTIMIZATION */;
    T2 = ecl_function_dispatch(cl_env_copy,VV[219])(2, ECL_SYM("SPACE",788), v8cmp_env) /*  CMP-ENV-OPTIMIZATION */;
    T3 = ecl_function_dispatch(cl_env_copy,VV[219])(2, ECL_SYM("SAFETY",734), v8cmp_env) /*  CMP-ENV-OPTIMIZATION */;
    ecl_function_dispatch(cl_env_copy,VV[176])(5, _ecl_static_130, T0, T1, T2, T3) /*  WT-COMMENT-NL */;
   }
   {
    cl_object v8cfun;
    v8cfun = ecl_function_dispatch(cl_env_copy,VV[210])(1, v1fun) /*  FUN-CFUN */;
    if (Null(ecl_function_dispatch(cl_env_copy,VV[220])(1, v1fun) /*  FUN-EXPORTED */)) { goto L49; }
    ecl_function_dispatch(cl_env_copy,VV[144])(3, _ecl_static_131, v8cfun, _ecl_static_96) /*  WT-NL-H */;
    ecl_function_dispatch(cl_env_copy,VV[143])(3, _ecl_static_67, v8cfun, _ecl_static_96) /*  WT-NL */;
    goto L47;
L49:;
    ecl_function_dispatch(cl_env_copy,VV[144])(3, _ecl_static_47, v8cfun, _ecl_static_96) /*  WT-NL-H */;
    ecl_function_dispatch(cl_env_copy,VV[143])(3, _ecl_static_47, v8cfun, _ecl_static_96) /*  WT-NL */;
   }
L47:;
   if (Null(v7narg)) { goto L53; }
   ecl_function_dispatch(cl_env_copy,VV[153])(2, v4volatile, _ecl_static_132) /*  WT-H */;
   ecl_function_dispatch(cl_env_copy,VV[174])(2, v4volatile, _ecl_static_133) /*  WT */;
   v2comma = _ecl_static_69;
L53:;
   {
    cl_object v8;
    v8 = L36fun_lexical_levels(v1fun);
    {
     cl_object v9n;
     v9n = ecl_make_fixnum(0);
     goto L62;
L61:;
     ecl_function_dispatch(cl_env_copy,VV[153])(2, v2comma, _ecl_static_134) /*  WT-H */;
     ecl_function_dispatch(cl_env_copy,VV[174])(3, v2comma, _ecl_static_135, v9n) /*  WT */;
     v2comma = _ecl_static_69;
     v9n = ecl_one_plus(v9n);
L62:;
     if (!(ecl_number_compare(v9n,v8)<0)) { goto L70; }
     goto L61;
L70:;
    }
   }
   {
    cl_object v8;
    cl_object v9lcl;
    cl_object v10;
    v8 = ecl_structure_set(v1fun,VV[104],29,v6requireds);
    v9lcl = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
    v10 = v8;
L77:;
    if (!(ecl_endp(v10))) { goto L79; }
    goto L78;
L79:;
    v9lcl = _ecl_car(v10);
    {
     cl_object v11;
     v11 = _ecl_cdr(v10);
     if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
     v10 = v11;
    }
    ecl_function_dispatch(cl_env_copy,VV[153])(3, v2comma, _ecl_static_67, v4volatile) /*  WT-H */;
    ecl_function_dispatch(cl_env_copy,VV[174])(4, v2comma, _ecl_static_67, v4volatile, v9lcl) /*  WT */;
    v2comma = _ecl_static_69;
    goto L77;
L78:;
   }
   if (Null(v7narg)) { goto L92; }
   ecl_function_dispatch(cl_env_copy,VV[153])(1, _ecl_static_136) /*  WT-H */;
   ecl_function_dispatch(cl_env_copy,VV[174])(1, _ecl_static_136) /*  WT */;
L92:;
   ecl_function_dispatch(cl_env_copy,VV[153])(1, _ecl_static_85) /*  WT-H */;
   ecl_function_dispatch(cl_env_copy,VV[174])(1, _ecl_static_84) /*  WT */;
  }
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for FUN-CLOSURE-VARIABLES                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L35fun_closure_variables(cl_object v1fun)
{
 cl_object T0, T1, T2, T3, T4;
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1fun,env0);                 /*  FUN             */
  {cl_object v2;
   v2 = ECL_NIL;
   v2 = ecl_make_cclosure_va((cl_objectfn)LC34__g162,env0,Cblock);
   T0 = v2;
  }
  T1 = ecl_function_dispatch(cl_env_copy,VV[222])(1, ECL_CONS_CAR(CLV0)) /*  FUN-REFERENCED-VARS */;
  T2 = cl_remove_if(2, T0, T1);
  T3 = (ECL_SYM(">",75)->symbol.gfdef);
  T4 = ecl_fdefinition(VV[203]);
  value0 = cl_sort(4, T2, T3, ECL_SYM("KEY",1262), T4);
  return value0;
 }
}
/*	closure G162                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC34__g162(cl_narg narg, cl_object v1x, ...)
{
 cl_object T0, T1;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  FUN             */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[223])(1, v1x) /*  REF-REF-CCB */;
  value0 = Null(T0)?ECL_T:ECL_NIL;
  if ((value0)!=ECL_NIL) { goto L2; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[202])(1, v1x) /*  VAR-KIND */;
  value0 = ecl_make_bool((T0)==(ECL_SYM("SPECIAL",789)));
  if ((value0)!=ECL_NIL) { goto L2; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[148])(1, ECL_CONS_CAR(CLV0)) /*  FUN-LAMBDA */;
  if ((ecl_function_dispatch(cl_env_copy,VV[224])(2, v1x, T0) /*  VAR-REFERENCED-IN-FORM */)!=ECL_NIL) { goto L7; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[148])(1, ECL_CONS_CAR(CLV0)) /*  FUN-LAMBDA */;
  T1 = ecl_function_dispatch(cl_env_copy,VV[225])(2, v1x, T0) /*  VAR-CHANGED-IN-FORM */;
  value0 = Null(T1)?ECL_T:ECL_NIL;
  goto L5;
L7:;
  value0 = ECL_NIL;
  goto L5;
L5:;
  if ((value0)!=ECL_NIL) { goto L2; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[203])(1, v1x) /*  VAR-LOC */;
  value0 = ecl_make_bool((T0)==(ECL_SYM("OBJECT",2014)));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
 }
}
/*	function definition for FUN-LEXICAL-LEVELS                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L36fun_lexical_levels(cl_object v1fun)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[169])(1, v1fun) /*  FUN-CLOSURE */;
  if (!((T0)==(VV[107]))) { goto L1; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[170])(1, v1fun) /*  FUN-LEVEL */;
  return value0;
L1:;
  value0 = ecl_make_fixnum(0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for T3LOCAL-FUN-CLOSURE-SCAN              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L37t3local_fun_closure_scan(cl_object v1fun)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2clv_used;
   v2clv_used = L35fun_closure_variables(v1fun);
   ecl_function_dispatch(cl_env_copy,VV[143])(1, _ecl_static_137) /*  WT-NL */;
   {
    cl_object v3;
    cl_object v4;
    cl_object v5n;
    cl_object v6first;
    T0 = ecl_function_dispatch(cl_env_copy,VV[171])(1, v1fun) /*  FUN-ENV */;
    v3 = ecl_one_minus(T0);
    v4 = v2clv_used;
    v5n = v3;
    v6first = ECL_T;
    goto L10;
L9:;
    ecl_function_dispatch(cl_env_copy,VV[143])(2, _ecl_static_77, v5n) /*  WT-NL */;
    if (Null(v6first)) { goto L14; }
    ecl_function_dispatch(cl_env_copy,VV[174])(1, _ecl_static_138) /*  WT */;
    v6first = ECL_NIL;
    goto L13;
L14:;
    T0 = ecl_one_plus(v5n);
    ecl_function_dispatch(cl_env_copy,VV[174])(3, _ecl_static_139, T0, _ecl_static_85) /*  WT */;
L13:;
    T0 = ecl_car(v4);
    T1 = ecl_function_dispatch(cl_env_copy,VV[203])(1, T0) /*  VAR-LOC */;
    if (!(ecl_number_equalp(v5n,T1))) { goto L18; }
    T0 = ecl_car(v2clv_used);
    T1 = ecl_function_dispatch(cl_env_copy,VV[201])(1, T0) /*  VAR-NAME */;
    ecl_function_dispatch(cl_env_copy,VV[228])(1, T1) /*  WT-COMMENT  */;
    {
     cl_object v7;
     v7 = v2clv_used;
     if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
     if (Null(v7)) { goto L24; }
     {
      cl_object v8;
      v8 = ECL_CONS_CDR(v7);
      v2clv_used = v8;
      v7 = ECL_CONS_CAR(v7);
     }
L24:;
    }
L18:;
    v5n = ecl_one_minus(v5n);
L10:;
    if (ecl_minusp(v5n)) { goto L32; }
    if (v4==ECL_NIL) { goto L32; }
    goto L9;
L32:;
   }
   ecl_function_dispatch(cl_env_copy,VV[146])(0)  /*  WT-NL-OPEN-BRACE */;
   value0 = ecl_function_dispatch(cl_env_copy,VV[174])(1, _ecl_static_140) /*  WT */;
   return value0;
  }
 }
}
/*	function definition for C1FSET                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L38c1fset(cl_object v1args)
{
 cl_object T0, T1, T2, T3, T4, T5;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   cl_object v3fname;
   cl_object v4def;
   cl_object v5macro;
   cl_object v6pprint;
   v2 = v1args;
   if (!(v2==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1args);
L3:;
   {
    cl_object v7;
    v7 = ecl_car(v2);
    v2 = ecl_cdr(v2);
    v3fname = v7;
   }
   if (!(v2==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1args);
L9:;
   {
    cl_object v7;
    v7 = ecl_car(v2);
    v2 = ecl_cdr(v2);
    v4def = v7;
   }
   if (Null(v2)) { goto L15; }
   {
    cl_object v7;
    v7 = ecl_car(v2);
    v2 = ecl_cdr(v2);
    v5macro = v7;
    goto L14;
   }
L15:;
   v5macro = ECL_NIL;
L14:;
   if (Null(v2)) { goto L21; }
   {
    cl_object v7;
    v7 = ecl_car(v2);
    v2 = ecl_cdr(v2);
    v6pprint = v7;
    goto L20;
   }
L21:;
   v6pprint = ECL_NIL;
L20:;
   if (Null(v2)) { goto L26; }
   si_dm_too_many_arguments(v1args);
L26:;
   {
    cl_object v7fun_form;
    v7fun_form = ecl_function_dispatch(cl_env_copy,VV[132])(1, v4def) /*  C1EXPR */;
    T0 = ecl_function_dispatch(cl_env_copy,VV[134])(1, v7fun_form) /*  C1FORM-NAME */;
    if (!((T0)==(VV[110]))) { goto L28; }
    {
     cl_object v8function_list;
     cl_object v9fun_object;
     cl_object v10form;
     cl_object v11labels;
     T0 = ecl_function_dispatch(cl_env_copy,VV[139])(1, v7fun_form) /*  C1FORM-ARGS */;
     v8function_list = ecl_car(T0);
     {
      cl_object v12;
      v12 = v8function_list;
      if (ecl_unlikely(!ECL_LISTP(v12))) FEtype_error_list(v12);
      if (Null(v12)) { goto L36; }
      {
       cl_object v13;
       v13 = ECL_CONS_CDR(v12);
       v8function_list = v13;
       v12 = ECL_CONS_CAR(v12);
      }
L36:;
      v9fun_object = v12;
     }
     T0 = ecl_function_dispatch(cl_env_copy,VV[139])(1, v7fun_form) /*  C1FORM-ARGS */;
     v10form = ecl_cadr(T0);
     T0 = ecl_function_dispatch(cl_env_copy,VV[139])(1, v7fun_form) /*  C1FORM-ARGS */;
     v11labels = ecl_caddr(T0);
     if (!(v8function_list==ECL_NIL)) { goto L28; }
     T0 = ecl_fdefinition(VV[230]);
     T1 = ecl_function_dispatch(cl_env_copy,VV[222])(1, v9fun_object) /*  FUN-REFERENCED-VARS */;
     if (Null(cl_every(2, T0, T1))) { goto L28; }
     T0 = ecl_function_dispatch(cl_env_copy,VV[134])(1, v10form) /*  C1FORM-NAME */;
     if (!((T0)==(VV[111]))) { goto L28; }
     T0 = ecl_function_dispatch(cl_env_copy,VV[139])(1, v10form) /*  C1FORM-ARGS */;
     T1 = ecl_car(T0);
     T2 = ecl_function_dispatch(cl_env_copy,VV[231])(1, v9fun_object) /*  FUN-VAR */;
     if (!((T1)==(T2))) { goto L28; }
     if (Null(ecl_function_dispatch(cl_env_copy,VV[232])(1, v9fun_object) /*  FUN-NO-ENTRY */)) { goto L49; }
     if (Null(v5macro)) { goto L51; }
     T0 = ecl_function_dispatch(cl_env_copy,VV[168])(1, v9fun_object) /*  FUN-NAME */;
     ecl_function_dispatch(cl_env_copy,VV[127])(2, _ecl_static_141, T0) /*  CMPERR */;
L51:;
     value0 = ecl_function_dispatch(cl_env_copy,VV[183])(7, ECL_SYM("FSET",1080), VV[75], v9fun_object, ECL_NIL, ECL_NIL, ECL_NIL, ECL_NIL) /*  MAKE-C1FORM* */;
     return value0;
L49:;
     if (!((v5macro)==(ECL_NIL))) { goto L58; }
     goto L55;
     goto L56;
L58:;
     goto L56;
L56:;
     if (!(ecl_eql(v5macro,ECL_T))) { goto L28; }
     goto L54;
L55:;
L54:;
     if (ECL_FIXNUMP(v6pprint)||ECL_BIGNUMP(v6pprint)) { goto L62; }
     if (!(v6pprint==ECL_NIL)) { goto L28; }
     goto L61;
L62:;
L61:;
     if (!(ECL_CONSP(v3fname))) { goto L28; }
     T0 = ecl_car(v3fname);
     if (!((T0)==(ECL_SYM("QUOTE",679)))) { goto L28; }
     T0 = ecl_cadr(v3fname);
     T1 = ecl_function_dispatch(cl_env_copy,VV[194])(5, T0, VV[114], ECL_T, VV[115], ECL_T) /*  ADD-OBJECT */;
     T2 = ecl_function_dispatch(cl_env_copy,VV[132])(1, v3fname) /*  C1EXPR */;
     T3 = ecl_function_dispatch(cl_env_copy,VV[132])(1, v5macro) /*  C1EXPR */;
     T4 = ecl_function_dispatch(cl_env_copy,VV[132])(1, v6pprint) /*  C1EXPR */;
     T5 = cl_list(4, T2, v7fun_form, T3, T4);
     value0 = ecl_function_dispatch(cl_env_copy,VV[183])(7, ECL_SYM("FSET",1080), VV[75], v9fun_object, T1, v5macro, v6pprint, T5) /*  MAKE-C1FORM* */;
     return value0;
    }
   }
L28:;
   T0 = cl_list(4, v3fname, v4def, v5macro, v6pprint);
   value0 = ecl_function_dispatch(cl_env_copy,VV[233])(2, ECL_SYM("FSET",1080), T0) /*  C1CALL-GLOBAL */;
   return value0;
  }
 }
}
/*	function definition for P1FSET                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L39p1fset(cl_object v1c1form, cl_object v2assumptions, cl_object v3fun, cl_object v4fname, cl_object v5macro, cl_object v6pprint, cl_object v7c1forms)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[148])(1, v3fun) /*  FUN-LAMBDA */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[30])(2, T0, v2assumptions) /*  P1PROPAGATE */;
  return value0;
 }
}
/*	function definition for C2FSET                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L40c2fset(cl_object v1c1form, cl_object v2fun, cl_object v3fname, cl_object v4macro, cl_object v5pprint, cl_object v6c1forms)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[232])(1, v2fun) /*  FUN-NO-ENTRY */)) { goto L1; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[168])(1, v2fun) /*  FUN-NAME */;
  T1 = cl_format(3, ECL_NIL, _ecl_static_143, T0);
  ecl_function_dispatch(cl_env_copy,VV[143])(3, _ecl_static_142, T1, _ecl_static_62) /*  WT-NL */;
  ecl_function_dispatch(cl_env_copy,VV[236])(1, v2fun) /*  NEW-LOCAL  */;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if ((ecl_function_dispatch(cl_env_copy,VV[169])(1, v2fun) /*  FUN-CLOSURE */)!=ECL_NIL) { goto L8; }
  if ((ecl_symbol_value(VV[80]))==(VV[81])) { goto L5; }
  goto L6;
L8:;
  goto L6;
L6:;
  value0 = ecl_function_dispatch(cl_env_copy,VV[237])(3, v1c1form, ECL_SYM("FSET",1080), v6c1forms) /*  C2CALL-GLOBAL */;
  return value0;
L5:;
  {
   cl_object v7;
   v7 = ecl_function_dispatch(cl_env_copy,VV[193])(0) /*  DATA-EMPTY-LOC */;
   ecl_bds_bind(cl_env_copy,VV[118],ecl_make_fixnum(0)); /*  *INLINE-BLOCKS* */
   T0 = cl_list(3, v7, v3fname, v2fun);
   cl_set(VV[119],CONS(T0,ecl_symbol_value(VV[119])));
   ecl_function_dispatch(cl_env_copy,VV[236])(1, v2fun) /*  NEW-LOCAL */;
   if (Null(v4macro)) { goto L16; }
   T0 = _ecl_static_144;
   goto L15;
L16:;
   T0 = _ecl_static_145;
L15:;
   ecl_function_dispatch(cl_env_copy,VV[143])(3, T0, v7, _ecl_static_85) /*  WT-NL */;
   T0 = ecl_function_dispatch(cl_env_copy,VV[238])(1, v3fname) /*  LOC-IMMEDIATE-VALUE */;
   ecl_function_dispatch(cl_env_copy,VV[228])(1, T0) /*  WT-COMMENT   */;
   value0 = ecl_function_dispatch(cl_env_copy,VV[239])(0) /*  CLOSE-INLINE-BLOCKS */;
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
 }
}
/*	function definition for OUTPUT-CFUNS                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L41output_cfuns(cl_object v1stream)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v2n_cfuns;
   v2n_cfuns = ecl_length(ecl_symbol_value(VV[119]));
   ecl_function_dispatch(cl_env_copy,VV[144])(1, _ecl_static_60) /*  WT-NL-H */;
   ecl_function_dispatch(cl_env_copy,VV[144])(1, _ecl_static_146) /*  WT-NL-H */;
   ecl_function_dispatch(cl_env_copy,VV[144])(1, _ecl_static_62) /*  WT-NL-H */;
   ecl_function_dispatch(cl_env_copy,VV[144])(2, _ecl_static_147, ecl_make_fixnum(v2n_cfuns)) /*  WT-NL-H */;
   if (!((v2n_cfuns)==0)) { goto L6; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[144])(1, _ecl_static_148) /*  WT-NL-H */;
   return value0;
L6:;
   cl_format(2, v1stream, _ecl_static_149);
   {
    cl_object v3;
    cl_object v4loc;
    cl_object v5fname_loc;
    cl_object v6fun;
    cl_object v7;
    v3 = cl_nreverse(ecl_symbol_value(VV[119]));
    v4loc = ECL_NIL;
    v5fname_loc = ECL_NIL;
    v6fun = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v3))) FEtype_error_list(v3);
    v7 = v3;
L16:;
    if (!(ecl_endp(v7))) { goto L18; }
    goto L17;
L18:;
    {
     cl_object v8;
     v8 = _ecl_car(v7);
     v4loc = ecl_car(v8);
     v8 = ecl_cdr(v8);
     v5fname_loc = ecl_car(v8);
     v8 = ecl_cdr(v8);
     v6fun = ecl_car(v8);
    }
    {
     cl_object v8;
     v8 = _ecl_cdr(v7);
     if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
     v7 = v8;
    }
    {
     cl_object v8cfun;
     cl_object v9minarg;
     cl_object v10maxarg;
     cl_object v11narg;
     v8cfun = ecl_function_dispatch(cl_env_copy,VV[210])(1, v6fun) /*  FUN-CFUN */;
     v9minarg = ecl_function_dispatch(cl_env_copy,VV[241])(1, v6fun) /*  FUN-MINARG */;
     v10maxarg = ecl_function_dispatch(cl_env_copy,VV[242])(1, v6fun) /*  FUN-MAXARG */;
     if (!(ecl_number_equalp(v9minarg,v10maxarg))) { goto L40; }
     if (!(ecl_number_compare(v10maxarg,ecl_make_fixnum(63))<=0)) { goto L40; }
     v11narg = v10maxarg;
     goto L39;
L40:;
     v11narg = ecl_make_fixnum(-1);
L39:;
     T0 = ecl_function_dispatch(cl_env_copy,VV[243])(1, v4loc) /*  VV-LOCATION */;
     T1 = ecl_function_dispatch(cl_env_copy,VV[243])(1, v5fname_loc) /*  VV-LOCATION */;
     T2 = ecl_function_dispatch(cl_env_copy,VV[244])(1, v6fun) /*  FUN-FILE-POSITION */;
     cl_format(7, v1stream, _ecl_static_150, v11narg, T0, T1, v8cfun, T2);
    }
    goto L16;
L17:;
   }
   value0 = cl_format(2, v1stream, _ecl_static_151);
   return value0;
  }
 }
}

#include "cmp/cmptop.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclKD6SbXDJQTTp9_rhqtVE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPTOP.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclKD6SbXDJQTTp9_rhqtVE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[122]);                          /*  T1EXPR          */
 si_Xmake_special(VV[4]);
 if (ecl_boundp(cl_env_copy,VV[4])) { goto L7; }
 cl_set(VV[4],VVtemp[0]);
L7:;
 ecl_cmp_defun(VV[125]);                          /*  T1EXPR*         */
 ecl_cmp_defun(VV[131]);                          /*  T1/C1EXPR       */
 ecl_cmp_defun(VV[133]);                          /*  T2EXPR          */
 si_Xmake_special(VV[16]);
 if (ecl_boundp(cl_env_copy,VV[16])) { goto L26; }
 cl_set(VV[16],ECL_NIL);
L26:;
 ecl_cmp_defun(VV[140]);                          /*  EMIT-LOCAL-FUNS */
 ecl_cmp_defun(VV[141]);                          /*  CTOP-WRITE      */
 ecl_cmp_defun(VV[155]);                          /*  EMIT-TOPLEVEL-FORM */
 ecl_cmp_defun(VV[157]);                          /*  C1EVAL-WHEN     */
 ecl_cmp_defun(VV[161]);                          /*  T2COMPILER-LET  */
 ecl_cmp_defun(VV[163]);                          /*  T2PROGN         */
 ecl_cmp_defun(VV[164]);                          /*  EXPORTED-FNAME  */
 ecl_cmp_defun(VV[166]);                          /*  NEW-DEFUN       */
 ecl_cmp_defun(VV[167]);                          /*  PRINT-FUNCTION  */
 ecl_cmp_defmacro(VV[172]);                       /*  AND!            */
 ecl_cmp_defun(VV[173]);                          /*  WT-FUNCTION-LOCALS */
 ecl_cmp_defun(VV[175]);                          /*  WT-GLOBAL-ENTRY */
 ecl_cmp_defun(VV[181]);                          /*  REP-TYPE        */
 ecl_cmp_defun(VV[182]);                          /*  T1ORDINARY      */
 ecl_cmp_defun(VV[184]);                          /*  P1ORDINARY      */
 ecl_cmp_defun(VV[185]);                          /*  T2ORDINARY      */
 ecl_cmp_defun(VV[188]);                          /*  ADD-LOAD-TIME-VALUES */
 ecl_cmp_defun(VV[189]);                          /*  T1DEFMACRO      */
 ecl_cmp_defun(VV[191]);                          /*  C1LOAD-TIME-VALUE */
 ecl_cmp_defun(VV[195]);                          /*  T2LOAD-TIME-VALUE */
 ecl_cmp_defun(VV[196]);                          /*  T2MAKE-FORM     */
 ecl_cmp_defun(VV[197]);                          /*  T2INIT-FORM     */
 ecl_cmp_defun(VV[198]);                          /*  PARSE-CVSPECS   */
 ecl_cmp_defun(VV[199]);                          /*  LOCATIVE-TYPE-FROM-VAR-KIND */
 ecl_cmp_defun(VV[200]);                          /*  BUILD-DEBUG-LEXICAL-ENV */
 ecl_cmp_defun(VV[204]);                          /*  POP-DEBUG-LEXICAL-ENV */
 ecl_cmp_defun(VV[205]);                          /*  T3LOCAL-FUN     */
 ecl_cmp_defun(VV[209]);                          /*  T3LOCAL-FUN-BODY */
 ecl_cmp_defun(VV[214]);                          /*  T3LOCAL-FUN-DECLARATION */
 ecl_cmp_defun(VV[221]);                          /*  FUN-CLOSURE-VARIABLES */
 ecl_cmp_defun(VV[226]);                          /*  FUN-LEXICAL-LEVELS */
 ecl_cmp_defun(VV[227]);                          /*  T3LOCAL-FUN-CLOSURE-SCAN */
 ecl_cmp_defun(VV[229]);                          /*  C1FSET          */
 ecl_cmp_defun(VV[234]);                          /*  P1FSET          */
 ecl_cmp_defun(VV[235]);                          /*  C2FSET          */
 ecl_cmp_defun(VV[240]);                          /*  OUTPUT-CFUNS    */
}
