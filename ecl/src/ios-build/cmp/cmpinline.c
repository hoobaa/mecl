/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPINLINE.LSP                                 */
#include <ecl/ecl-cmp.h>
#include "cmp/cmpinline.eclh"
/*	function definition for MAKE-INLINE-TEMP-VAR                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1make_inline_temp_var(cl_narg narg, cl_object v1value_type, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2rep_type;
  va_list args; va_start(args,v1value_type);
  {
   int i = 1;
   if (i >= narg) {
    v2rep_type = ECL_NIL;
   } else {
    i++;
    v2rep_type = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v3out_rep_type;
   value0 = v2rep_type;
   if ((value0)!=ECL_NIL) { goto L4; }
   v3out_rep_type = ecl_function_dispatch(cl_env_copy,VV[35])(1, v1value_type) /*  LISP-TYPE->REP-TYPE */;
   goto L2;
L4:;
   v3out_rep_type = value0;
   goto L2;
L2:;
   if (!((v3out_rep_type)==(ECL_SYM("OBJECT",1278)))) { goto L6; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[36])(0) /*  MAKE-TEMP-VAR */;
   return value0;
L6:;
   {
    cl_object v4var;
    v4var = ecl_function_dispatch(cl_env_copy,VV[37])(4, VV[0], v3out_rep_type, ECL_SYM("TYPE",1318), v1value_type) /*  MAKE-LCL-VAR */;
    L15open_inline_block();
    T0 = ecl_function_dispatch(cl_env_copy,VV[38])(1, v3out_rep_type) /*  REP-TYPE-NAME */;
    ecl_function_dispatch(cl_env_copy,VV[39])(4, T0, _ecl_static_1, v4var, _ecl_static_2) /*  WT-NL */;
    value0 = v4var;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for SAVE-INLINE-LOC                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2save_inline_loc(cl_object v1loc)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2rep_type;
   cl_object v3temp;
   T0 = ecl_cadr(v1loc);
   v2rep_type = ecl_function_dispatch(cl_env_copy,VV[41])(1, T0) /*  LOC-REPRESENTATION-TYPE */;
   T0 = ecl_car(v1loc);
   v3temp = L1make_inline_temp_var(2, T0, v2rep_type);
   ecl_bds_bind(cl_env_copy,VV[2],v3temp);        /*  *DESTINATION*   */
   ecl_function_dispatch(cl_env_copy,VV[42])(1, v1loc) /*  SET-LOC    */;
   value0 = v3temp;
   cl_env_copy->nvalues = 1;
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
 }
}
/*	local function WITH-INLINED-LOC                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC3with_inlined_loc(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6temp_loc;
   cl_object v7loc;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v8;
    v8 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4 = v8;
   }
   v5 = v4;
   if (!(v5==ECL_NIL)) { goto L10; }
   si_dm_too_few_arguments(v1);
L10:;
   {
    cl_object v8;
    v8 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v6temp_loc = v8;
   }
   if (!(v5==ECL_NIL)) { goto L16; }
   si_dm_too_few_arguments(v1);
L16:;
   {
    cl_object v8;
    v8 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v7loc = v8;
   }
   if (Null(v5)) { goto L21; }
   si_dm_too_many_arguments(v1);
L21:;
   T0 = cl_list(2, VV[3], v7loc);
   T1 = cl_list(2, v6temp_loc, T0);
   T2 = ecl_list1(T1);
   T3 = cl_list(2, VV[4], v6temp_loc);
   T4 = cl_list(3, ECL_SYM("LIST",481), T3, v6temp_loc);
   T5 = cl_list(3, ECL_SYM("SETF",750), v6temp_loc, T4);
   value0 = cl_listX(4, ECL_SYM("LET",477), T2, T5, v3);
   return value0;
  }
 }
}
/*	function definition for EMIT-INLINED-VARIABLE                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4emit_inlined_variable(cl_object v1form, cl_object v2rest_forms)
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
   T0 = ecl_function_dispatch(cl_env_copy,VV[45])(1, v1form) /*  C1FORM-ARGS */;
   v3 = ecl_car(T0);
   v4 = ecl_function_dispatch(cl_env_copy,VV[46])(1, v1form) /*  C1FORM-PRIMARY-TYPE */;
   if (Null(ecl_function_dispatch(cl_env_copy,VV[47])(2, v3, v2rest_forms) /*  VAR-CHANGED-IN-FORM-LIST */)) { goto L3; }
   {
    cl_object v5temp;
    T0 = ecl_function_dispatch(cl_env_copy,VV[48])(1, v3) /*  VAR-REP-TYPE */;
    v5temp = L1make_inline_temp_var(2, v4, T0);
    ecl_bds_bind(cl_env_copy,VV[2],v5temp);       /*  *DESTINATION*   */
    ecl_function_dispatch(cl_env_copy,VV[42])(1, v3) /*  SET-LOC      */;
    ecl_bds_unwind1(cl_env_copy);
    value0 = cl_list(2, v4, v5temp);
    return value0;
   }
L3:;
   value0 = cl_list(2, v4, v3);
   return value0;
  }
 }
}
/*	function definition for EMIT-INLINED-SETQ                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5emit_inlined_setq(cl_object v1form, cl_object v2rest_forms)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   T0 = ecl_function_dispatch(cl_env_copy,VV[45])(1, v1form) /*  C1FORM-ARGS */;
   v3 = ecl_car(T0);
   T0 = ecl_function_dispatch(cl_env_copy,VV[45])(1, v1form) /*  C1FORM-ARGS */;
   v4 = ecl_cadr(T0);
   ecl_bds_bind(cl_env_copy,VV[2],v3);            /*  *DESTINATION*   */
   ecl_function_dispatch(cl_env_copy,VV[50])(1, v4) /*  C2EXPR*       */;
   ecl_bds_unwind1(cl_env_copy);
   T0 = ecl_function_dispatch(cl_env_copy,VV[51])(1, v4) /*  C1FORM-NAME */;
   if (!((T0)==(ECL_SYM("LOCATION",1763)))) { goto L4; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[46])(1, v4) /*  C1FORM-PRIMARY-TYPE */;
   T1 = ecl_function_dispatch(cl_env_copy,VV[45])(1, v4) /*  C1FORM-ARGS */;
   T2 = ecl_car(T1);
   value0 = cl_list(2, T0, T2);
   return value0;
L4:;
   T0 = ecl_function_dispatch(cl_env_copy,VV[52])(3, VV[7], v1form, v3) /*  MAKE-C1FORM */;
   value0 = L4emit_inlined_variable(T0, v2rest_forms);
   return value0;
  }
 }
}
/*	function definition for EMIT-INLINED-CALL-GLOBAL              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6emit_inlined_call_global(cl_object v1form, cl_object v2expected_type)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3fname;
   cl_object v4args;
   cl_object v5return_type;
   cl_object v6fun;
   cl_object v7loc;
   cl_object v8type;
   cl_object v9temp;
   T0 = ecl_function_dispatch(cl_env_copy,VV[45])(1, v1form) /*  C1FORM-ARGS */;
   v3fname = ecl_car(T0);
   T0 = ecl_function_dispatch(cl_env_copy,VV[45])(1, v1form) /*  C1FORM-ARGS */;
   v4args = ecl_cadr(T0);
   v5return_type = ecl_function_dispatch(cl_env_copy,VV[46])(1, v1form) /*  C1FORM-PRIMARY-TYPE */;
   {
    cl_object v10;
    cl_object v11;
    v10 = ecl_symbol_value(VV[9]);
    v11 = si_make_seq_iterator(2, v10, ecl_make_fixnum(0));
L7:;
    if ((v11)!=ECL_NIL) { goto L9; }
    v6fun = ECL_NIL;
    goto L4;
L9:;
    {
     cl_object v12;
     v12 = si_seq_iterator_ref(v10, v11);
     T0 = ecl_function_dispatch(cl_env_copy,VV[54])(1, v12) /*  FUN-NAME */;
     if (Null(ecl_function_dispatch(cl_env_copy,VV[55])(2, v3fname, T0) /*  SAME-FNAME-P */)) { goto L11; }
     v6fun = v12;
     goto L4;
    }
L11:;
    v11 = si_seq_iterator_next(v10, v11);
    goto L7;
   }
L4:;
   v7loc = ecl_function_dispatch(cl_env_copy,VV[56])(5, v3fname, v6fun, v4args, v5return_type, v2expected_type) /*  CALL-GLOBAL-LOC */;
   T0 = ecl_function_dispatch(cl_env_copy,VV[57])(1, v7loc) /*  LOC-TYPE */;
   v8type = ecl_function_dispatch(cl_env_copy,VV[58])(2, v5return_type, T0) /*  TYPE-AND */;
   T0 = ecl_function_dispatch(cl_env_copy,VV[41])(1, v7loc) /*  LOC-REPRESENTATION-TYPE */;
   v9temp = L1make_inline_temp_var(2, v8type, T0);
   ecl_bds_bind(cl_env_copy,VV[2],v9temp);        /*  *DESTINATION*   */
   ecl_function_dispatch(cl_env_copy,VV[42])(1, v7loc) /*  SET-LOC    */;
   value0 = cl_list(2, v8type, v9temp);
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
 }
}
/*	function definition for EMIT-INLINED-PROGN                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7emit_inlined_progn(cl_object v1form, cl_object v2forms)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3args;
   T0 = ecl_function_dispatch(cl_env_copy,VV[45])(1, v1form) /*  C1FORM-ARGS */;
   v3args = ecl_car(T0);
   ecl_bds_bind(cl_env_copy,VV[2],VV[11]);        /*  *DESTINATION*   */
L3:;
   if ((ecl_cdr(v3args))!=ECL_NIL) { goto L5; }
   goto L4;
L5:;
   {
    cl_object v4;
    v4 = v3args;
    if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
    if (Null(v4)) { goto L12; }
    {
     cl_object v5;
     v5 = ECL_CONS_CDR(v4);
     v3args = v5;
     v4 = ECL_CONS_CAR(v4);
    }
L12:;
    T0 = v4;
   }
   ecl_function_dispatch(cl_env_copy,VV[50])(1, T0) /*  C2EXPR*       */;
   goto L3;
L4:;
   ecl_bds_unwind1(cl_env_copy);
   T0 = ecl_car(v3args);
   value0 = L11emit_inline_form(T0, v2forms);
   return value0;
  }
 }
}
/*	function definition for EMIT-INLINED-VALUES                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8emit_inlined_values(cl_object v1form, cl_object v2forms)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3args;
   T0 = ecl_function_dispatch(cl_env_copy,VV[45])(1, v1form) /*  C1FORM-ARGS */;
   v3args = ecl_car(T0);
   {
    cl_object v4;
    {
     cl_object v5;
     v5 = v3args;
     if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
     if (Null(v5)) { goto L7; }
     {
      cl_object v6;
      v6 = ECL_CONS_CDR(v5);
      v3args = v6;
      v5 = ECL_CONS_CAR(v5);
     }
L7:;
     T0 = v5;
    }
    v4 = L11emit_inline_form(T0, v2forms);
    ecl_bds_bind(cl_env_copy,VV[2],VV[11]);       /*  *DESTINATION*   */
    {
     cl_object v5form;
     cl_object v6;
     v5form = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v3args))) FEtype_error_list(v3args);
     v6 = v3args;
L17:;
     if (!(ecl_endp(v6))) { goto L19; }
     goto L18;
L19:;
     v5form = _ecl_car(v6);
     {
      cl_object v7;
      v7 = _ecl_cdr(v6);
      if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
      v6 = v7;
     }
     ecl_function_dispatch(cl_env_copy,VV[50])(1, v5form) /*  C2EXPR* */;
     goto L17;
L18:;
     ecl_bds_unwind1(cl_env_copy);
    }
    value0 = v4;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for EMIT-INLINED-STRUCTURE-REF            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L9emit_inlined_structure_ref(cl_object v1form, cl_object v2rest_forms)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3type;
   v3type = ecl_function_dispatch(cl_env_copy,VV[46])(1, v1form) /*  C1FORM-PRIMARY-TYPE */;
   if (Null(L18args_cause_side_effect(v2rest_forms))) { goto L2; }
   {
    cl_object v4temp;
    v4temp = L1make_inline_temp_var(2, v3type, ECL_SYM("OBJECT",1278));
    ecl_bds_bind(cl_env_copy,VV[2],v4temp);       /*  *DESTINATION*   */
    ecl_function_dispatch(cl_env_copy,VV[50])(1, v1form) /*  C2EXPR*  */;
    value0 = cl_list(2, v3type, v4temp);
    ecl_bds_unwind1(cl_env_copy);
    return value0;
   }
L2:;
   T0 = ecl_function_dispatch(cl_env_copy,VV[45])(1, v1form) /*  C1FORM-ARGS */;
   T1 = ecl_car(T0);
   T2 = ecl_list1(T1);
   T3 = L12inline_args(T2);
   T4 = ecl_function_dispatch(cl_env_copy,VV[62])(1, T3) /*  COERCE-LOCS */;
   T5 = ecl_car(T4);
   T6 = ecl_function_dispatch(cl_env_copy,VV[45])(1, v1form) /*  C1FORM-ARGS */;
   T7 = ecl_cadr(T6);
   T8 = ecl_function_dispatch(cl_env_copy,VV[45])(1, v1form) /*  C1FORM-ARGS */;
   T9 = ecl_caddr(T8);
   T10 = ecl_function_dispatch(cl_env_copy,VV[45])(1, v1form) /*  C1FORM-ARGS */;
   T11 = ecl_cadddr(T10);
   T12 = cl_list(5, ECL_SYM("STRUCTURE-REF",1153), T5, T7, T9, T11);
   value0 = cl_list(2, v3type, T12);
   return value0;
  }
 }
}
/*	function definition for EMIT-INLINED-INSTANCE-REF             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L10emit_inlined_instance_ref(cl_object v1form, cl_object v2rest_forms)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3type;
   v3type = ecl_function_dispatch(cl_env_copy,VV[46])(1, v1form) /*  C1FORM-PRIMARY-TYPE */;
   if (Null(L18args_cause_side_effect(v2rest_forms))) { goto L2; }
   {
    cl_object v4temp;
    v4temp = L1make_inline_temp_var(2, v3type, ECL_SYM("OBJECT",1278));
    ecl_bds_bind(cl_env_copy,VV[2],v4temp);       /*  *DESTINATION*   */
    ecl_function_dispatch(cl_env_copy,VV[50])(1, v1form) /*  C2EXPR*  */;
    value0 = cl_list(2, v3type, v4temp);
    ecl_bds_unwind1(cl_env_copy);
    return value0;
   }
L2:;
   T0 = ecl_function_dispatch(cl_env_copy,VV[45])(1, v1form) /*  C1FORM-ARGS */;
   T1 = ecl_car(T0);
   T2 = ecl_list1(T1);
   T3 = L12inline_args(T2);
   T4 = ecl_function_dispatch(cl_env_copy,VV[62])(1, T3) /*  COERCE-LOCS */;
   T5 = ecl_car(T4);
   T6 = ecl_function_dispatch(cl_env_copy,VV[45])(1, v1form) /*  C1FORM-ARGS */;
   T7 = ecl_cadr(T6);
   T8 = cl_list(3, ECL_SYM("INSTANCE-REF",1169), T5, T7);
   value0 = cl_list(2, v3type, T8);
   return value0;
  }
 }
}
/*	function definition for EMIT-INLINE-FORM                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L11emit_inline_form(cl_object v1form, cl_object v2forms)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[65])(1, v1form) /*  C1FORM-FILE */;
  ecl_bds_bind(cl_env_copy,ECL_SYM("*COMPILE-FILE-TRUENAME*",27),T0); /*  *COMPILE-FILE-TRUENAME* */
  T0 = ecl_function_dispatch(cl_env_copy,VV[66])(1, v1form) /*  C1FORM-FILE-POSITION */;
  ecl_bds_bind(cl_env_copy,VV[16],T0);            /*  *COMPILE-FILE-POSITION* */
  T0 = ecl_function_dispatch(cl_env_copy,VV[67])(1, v1form) /*  C1FORM-TOPLEVEL-FORM */;
  ecl_bds_bind(cl_env_copy,VV[17],T0);            /*  *CURRENT-TOPLEVEL-FORM* */
  T0 = ecl_function_dispatch(cl_env_copy,VV[68])(1, v1form) /*  C1FORM-FORM */;
  ecl_bds_bind(cl_env_copy,VV[18],T0);            /*  *CURRENT-FORM*  */
  T0 = ecl_function_dispatch(cl_env_copy,VV[69])(1, v1form) /*  C1FORM-ENV */;
  ecl_bds_bind(cl_env_copy,VV[19],T0);            /*  *CMP-ENV*       */
  {
   cl_object v3;
   v3 = ecl_function_dispatch(cl_env_copy,VV[51])(1, v1form) /*  C1FORM-NAME */;
   if (!((v3)==(ECL_SYM("LOCATION",1763)))) { goto L2; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[46])(1, v1form) /*  C1FORM-PRIMARY-TYPE */;
   T1 = ecl_function_dispatch(cl_env_copy,VV[45])(1, v1form) /*  C1FORM-ARGS */;
   T2 = ecl_car(T1);
   value0 = cl_list(2, T0, T2);
   ecl_bds_unwind_n(cl_env_copy,5);
   return value0;
L2:;
   if (!((v3)==(VV[7]))) { goto L4; }
   value0 = L4emit_inlined_variable(v1form, v2forms);
   ecl_bds_unwind_n(cl_env_copy,5);
   return value0;
L4:;
   if (!((v3)==(VV[20]))) { goto L6; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[46])(1, v1form) /*  C1FORM-PRIMARY-TYPE */;
   value0 = L6emit_inlined_call_global(v1form, T0);
   ecl_bds_unwind_n(cl_env_copy,5);
   return value0;
L6:;
   if (!((v3)==(ECL_SYM("STRUCTURE-REF",1153)))) { goto L8; }
   value0 = L9emit_inlined_structure_ref(v1form, v2forms);
   ecl_bds_unwind_n(cl_env_copy,5);
   return value0;
L8:;
   if (!((v3)==(ECL_SYM("INSTANCE-REF",1169)))) { goto L10; }
   value0 = L10emit_inlined_instance_ref(v1form, v2forms);
   ecl_bds_unwind_n(cl_env_copy,5);
   return value0;
L10:;
   if (!((v3)==(ECL_SYM("SETQ",751)))) { goto L12; }
   value0 = L5emit_inlined_setq(v1form, v2forms);
   ecl_bds_unwind_n(cl_env_copy,5);
   return value0;
L12:;
   if (!((v3)==(ECL_SYM("PROGN",671)))) { goto L14; }
   value0 = L7emit_inlined_progn(v1form, v2forms);
   ecl_bds_unwind_n(cl_env_copy,5);
   return value0;
L14:;
   if (!((v3)==(ECL_SYM("VALUES",895)))) { goto L16; }
   value0 = L8emit_inlined_values(v1form, v2forms);
   ecl_bds_unwind_n(cl_env_copy,5);
   return value0;
L16:;
   {
    cl_object v4type;
    cl_object v5temp;
    v4type = ecl_function_dispatch(cl_env_copy,VV[46])(1, v1form) /*  C1FORM-PRIMARY-TYPE */;
    v5temp = L1make_inline_temp_var(1, v4type);
    ecl_bds_bind(cl_env_copy,VV[2],v5temp);       /*  *DESTINATION*   */
    ecl_function_dispatch(cl_env_copy,VV[50])(1, v1form) /*  C2EXPR*  */;
    ecl_bds_unwind1(cl_env_copy);
    value0 = cl_list(2, v4type, v5temp);
    ecl_bds_unwind_n(cl_env_copy,5);
    return value0;
   }
  }
 }
}
/*	function definition for INLINE-ARGS                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L12inline_args(cl_object v1forms)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2form_list;
   v2form_list = v1forms;
   {
    cl_object v3form;
    v3form = ECL_NIL;
    {
     cl_object v4;
     cl_object v5;
     v4 = ecl_list1(ECL_NIL);
     v5 = v4;
L5:;
     if (!(ECL_ATOM(v2form_list))) { goto L7; }
     goto L6;
L7:;
     v3form = ecl_car(v2form_list);
     if (ecl_unlikely(ECL_ATOM(v5))) FEtype_error_cons(v5);
     T0 = v5;
     T1 = ecl_cdr(v2form_list);
     T2 = L11emit_inline_form(v3form, T1);
     v5 = ecl_list1(T2);
     (ECL_CONS_CDR(T0)=v5,T0);
     v2form_list = _ecl_cdr(v2form_list);
     goto L5;
L6:;
     value0 = ecl_cdr(v4);
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
  }
 }
}
/*	function definition for DESTINATION-TYPE                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L13destination_type()
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[41])(1, ecl_symbol_value(VV[2])) /*  LOC-REPRESENTATION-TYPE */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[72])(1, T0) /*  REP-TYPE->LISP-TYPE */;
  return value0;
 }
}
/*	function definition for MAYBE-OPEN-INLINE-BLOCK               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L14maybe_open_inline_block()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (ecl_plusp(ecl_symbol_value(VV[24]))) { goto L1; }
  value0 = L15open_inline_block();
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for OPEN-INLINE-BLOCK                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L15open_inline_block()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_function_dispatch(cl_env_copy,VV[75])(0)    /*  WT-NL-OPEN-BRACE */;
  cl_set(VV[24],ecl_plus(ecl_symbol_value(VV[24]),ecl_make_fixnum(1)));
  value0 = ecl_symbol_value(VV[24]);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for CLOSE-INLINE-BLOCKS                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L16close_inline_blocks(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1new_line;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1new_line = ECL_NIL;
   } else {
    i++;
    v1new_line = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v2;
   cl_fixnum v3i;
   cl_fixnum v4;
   v2 = ecl_symbol_value(VV[24]);
   v3i = 0;
   {
    bool v5;
    v5 = ECL_FIXNUMP(v2);
    if (ecl_unlikely(!(v5)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v2);
   }
   v4 = ecl_fixnum(v2);
L6:;
   if (!((v3i)>=(v4))) { goto L8; }
   goto L7;
L8:;
   ecl_function_dispatch(cl_env_copy,VV[77])(0)   /*  WT-NL-CLOSE-BRACE */;
   v3i = (v3i)+1;
   goto L6;
L7:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for FORM-CAUSES-SIDE-EFFECT               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L17form_causes_side_effect(cl_object v1form)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[79])(1, v1form) /*  C1FORM-SIDE-EFFECTS */;
  return value0;
 }
}
/*	function definition for ARGS-CAUSE-SIDE-EFFECT                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L18args_cause_side_effect(cl_object v1forms)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_fdefinition(VV[79]);
  value0 = cl_some(2, T0, v1forms);
  return value0;
 }
}
/*	function definition for FUNCTION-MAY-HAVE-SIDE-EFFECTS        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L19function_may_have_side_effects(cl_object v1fname)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = si_get_sysprop(v1fname, VV[30]);
  value0 = Null(T0)?ECL_T:ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for FUNCTION-MAY-CHANGE-SP                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L20function_may_change_sp(cl_object v1fname)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = si_get_sysprop(v1fname, VV[30]);
  if ((value0)!=ECL_NIL) { goto L3; }
  T0 = si_get_sysprop(v1fname, VV[32]);
  goto L1;
L3:;
  T0 = value0;
  goto L1;
L1:;
  value0 = Null(T0)?ECL_T:ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}

#include "cmp/cmpinline.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclmJ9OwniGC3pl9_86xTOE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPINLINE.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclmJ9OwniGC3pl9_86xTOE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[34]);                           /*  MAKE-INLINE-TEMP-VAR */
 ecl_cmp_defun(VV[40]);                           /*  SAVE-INLINE-LOC */
 ecl_cmp_defmacro(VV[43]);                        /*  WITH-INLINED-LOC */
 ecl_cmp_defun(VV[44]);                           /*  EMIT-INLINED-VARIABLE */
 ecl_cmp_defun(VV[49]);                           /*  EMIT-INLINED-SETQ */
 ecl_cmp_defun(VV[53]);                           /*  EMIT-INLINED-CALL-GLOBAL */
 ecl_cmp_defun(VV[59]);                           /*  EMIT-INLINED-PROGN */
 ecl_cmp_defun(VV[60]);                           /*  EMIT-INLINED-VALUES */
 ecl_cmp_defun(VV[61]);                           /*  EMIT-INLINED-STRUCTURE-REF */
 ecl_cmp_defun(VV[63]);                           /*  EMIT-INLINED-INSTANCE-REF */
 ecl_cmp_defun(VV[64]);                           /*  EMIT-INLINE-FORM */
 ecl_cmp_defun(VV[70]);                           /*  INLINE-ARGS     */
 ecl_cmp_defun(VV[71]);                           /*  DESTINATION-TYPE */
 ecl_cmp_defun(VV[73]);                           /*  MAYBE-OPEN-INLINE-BLOCK */
 ecl_cmp_defun(VV[74]);                           /*  OPEN-INLINE-BLOCK */
 ecl_cmp_defun(VV[76]);                           /*  CLOSE-INLINE-BLOCKS */
 ecl_cmp_defun(VV[78]);                           /*  FORM-CAUSES-SIDE-EFFECT */
 ecl_cmp_defun(VV[80]);                           /*  ARGS-CAUSE-SIDE-EFFECT */
 ecl_cmp_defun(VV[81]);                           /*  FUNCTION-MAY-HAVE-SIDE-EFFECTS */
 ecl_cmp_defun(VV[82]);                           /*  FUNCTION-MAY-CHANGE-SP */
}
