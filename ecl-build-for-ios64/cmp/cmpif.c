/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPIF.LSP                                     */
#include <ecl/ecl-cmp.h>
#include "cmp/cmpif.eclh"
/*	function definition for C1IF                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1c1if(cl_object v1args)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_function_dispatch(cl_env_copy,VV[34])(4, ECL_SYM("IF",946), v1args, ecl_make_fixnum(2), ecl_make_fixnum(3)) /*  CHECK-ARGS-NUMBER */;
  {
   cl_object v2test;
   T0 = ecl_car(v1args);
   v2test = ecl_function_dispatch(cl_env_copy,VV[35])(1, T0) /*  C1EXPR */;
   {
    cl_object v4;                                 /*  CONSTANT-P      */
    cl_object v5;                                 /*  VALUE           */
    value0 = ecl_function_dispatch(cl_env_copy,VV[36])(1, v2test) /*  C1FORM-CONSTANT-P */;
    v4 = value0;
    {
     const int v6 = cl_env_copy->nvalues;
     cl_object v7;
     v7 = (v6<=1)? ECL_NIL : cl_env_copy->values[1];
     v5 = v7;
    }
    if (Null(v4)) { goto L3; }
    if (Null(v5)) { goto L6; }
    value0 = ecl_cadr(v1args);
    cl_env_copy->nvalues = 1;
    return value0;
L6:;
    value0 = ecl_caddr(v1args);
    cl_env_copy->nvalues = 1;
    return value0;
   }
L3:;
   {
    cl_object v3true_branch;
    cl_object v4false_branch;
    T0 = ecl_cadr(v1args);
    v3true_branch = ecl_function_dispatch(cl_env_copy,VV[35])(1, T0) /*  C1EXPR */;
    T0 = ecl_caddr(v1args);
    v4false_branch = ecl_function_dispatch(cl_env_copy,VV[35])(1, T0) /*  C1EXPR */;
    T0 = ecl_function_dispatch(cl_env_copy,VV[37])(1, v3true_branch) /*  C1FORM-TYPE */;
    T1 = ecl_function_dispatch(cl_env_copy,VV[37])(1, v4false_branch) /*  C1FORM-TYPE */;
    T2 = ecl_function_dispatch(cl_env_copy,VV[38])(2, T0, T1) /*  VALUES-TYPE-OR */;
    value0 = ecl_function_dispatch(cl_env_copy,VV[39])(7, ECL_SYM("IF",946), ECL_SYM("TYPE",1318), T2, VV[0], v2test, v3true_branch, v4false_branch) /*  MAKE-C1FORM* */;
    return value0;
   }
  }
 }
}
/*	function definition for C1NOT                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2c1not(cl_object v1args)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_function_dispatch(cl_env_copy,VV[34])(4, ECL_SYM("NOT",584), v1args, ecl_make_fixnum(1), ecl_make_fixnum(1)) /*  CHECK-ARGS-NUMBER */;
  {
   cl_object v2value;
   T0 = ecl_car(v1args);
   v2value = ecl_function_dispatch(cl_env_copy,VV[35])(1, T0) /*  C1EXPR */;
   {
    cl_object v4;                                 /*  CONSTANT-P      */
    cl_object v5;                                 /*  VALUE           */
    value0 = ecl_function_dispatch(cl_env_copy,VV[36])(1, v2value) /*  C1FORM-CONSTANT-P */;
    v4 = value0;
    {
     const int v6 = cl_env_copy->nvalues;
     cl_object v7;
     v7 = (v6<=1)? ECL_NIL : cl_env_copy->values[1];
     v5 = v7;
    }
    if (Null(v4)) { goto L3; }
    value0 = Null(v5)?ECL_T:ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L3:;
   value0 = ecl_function_dispatch(cl_env_copy,VV[39])(5, VV[2], ECL_SYM("TYPE",1318), VV[3], VV[0], v2value) /*  MAKE-C1FORM* */;
   return value0;
  }
 }
}
/*	function definition for C1AND                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3c1and(cl_object v1args)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(v1args==ECL_NIL)) { goto L1; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[42])(0) /*  C1T       */;
  return value0;
L1:;
  {
   cl_object v2values;
   cl_object v3last;
   cl_object v4butlast;
   v2values = ecl_function_dispatch(cl_env_copy,VV[43])(1, v1args) /*  C1ARGS* */;
   T0 = ecl_last(v2values,1);
   v3last = ecl_car(T0);
   v4butlast = ecl_nbutlast(v2values,1);
   if (Null(v4butlast)) { goto L6; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[44])(1, v3last) /*  C1FORM-PRIMARY-TYPE */;
   T1 = ecl_function_dispatch(cl_env_copy,VV[45])(2, ECL_SYM("NULL",605), T0) /*  TYPE-OR */;
   value0 = ecl_function_dispatch(cl_env_copy,VV[39])(6, VV[5], ECL_SYM("TYPE",1318), T1, VV[0], v4butlast, v3last) /*  MAKE-C1FORM* */;
   return value0;
L6:;
   value0 = v3last;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for C1OR                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4c1or(cl_object v1args)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(v1args==ECL_NIL)) { goto L1; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[47])(0) /*  C1NIL     */;
  return value0;
L1:;
  {
   cl_object v2values;
   cl_object v3last;
   cl_object v4butlast;
   v2values = ecl_function_dispatch(cl_env_copy,VV[43])(1, v1args) /*  C1ARGS* */;
   T0 = ecl_last(v2values,1);
   v3last = ecl_car(T0);
   v4butlast = ecl_butlast(v2values,1);
   if (Null(v4butlast)) { goto L6; }
   T0 = ecl_fdefinition(VV[45]);
   T1 = ecl_fdefinition(VV[44]);
   T2 = ecl_function_dispatch(cl_env_copy,VV[44])(1, v3last) /*  C1FORM-PRIMARY-TYPE */;
   T3 = cl_reduce(6, T0, v4butlast, ECL_SYM("KEY",1262), T1, VV[8], T2);
   value0 = ecl_function_dispatch(cl_env_copy,VV[39])(6, VV[7], ECL_SYM("TYPE",1318), T3, VV[0], v4butlast, v3last) /*  MAKE-C1FORM* */;
   return value0;
L6:;
   value0 = v3last;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for C2IF                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5c2if(cl_object v1c1form, cl_object v2fmla, cl_object v3form1, cl_object v4form2)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!((ecl_symbol_value(VV[10]))==(VV[11]))) { goto L1; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[49])(1, v4form2) /*  C1FORM-NAME */;
  if (!((T0)==(ECL_SYM("LOCATION",1763)))) { goto L1; }
  {
   cl_object v5false_label;
   v5false_label = ecl_function_dispatch(cl_env_copy,VV[50])(0) /*  MAYBE-NEXT-LABEL */;
   T0 = cl_adjoin(2, v5false_label, ecl_symbol_value(VV[12]));
   ecl_bds_bind(cl_env_copy,VV[12],T0);           /*  *UNWIND-EXIT*   */
   T0 = cl_list(2, VV[13], v5false_label);
   ecl_bds_bind(cl_env_copy,VV[10],T0);           /*  *DESTINATION*   */
   ecl_function_dispatch(cl_env_copy,VV[51])(1, v2fmla) /*  C2EXPR*   */;
   ecl_bds_unwind1(cl_env_copy);
   ecl_function_dispatch(cl_env_copy,VV[52])(1, v3form1) /*  C2EXPR   */;
   value0 = ecl_function_dispatch(cl_env_copy,VV[53])(1, v5false_label) /*  MAYBE-WT-LABEL */;
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
L1:;
  if (!((ecl_symbol_value(VV[10]))==(VV[11]))) { goto L7; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[49])(1, v3form1) /*  C1FORM-NAME */;
  if (!((T0)==(ECL_SYM("LOCATION",1763)))) { goto L7; }
  {
   cl_object v6true_label;
   v6true_label = ecl_function_dispatch(cl_env_copy,VV[50])(0) /*  MAYBE-NEXT-LABEL */;
   T0 = cl_adjoin(2, v6true_label, ecl_symbol_value(VV[12]));
   ecl_bds_bind(cl_env_copy,VV[12],T0);           /*  *UNWIND-EXIT*   */
   T0 = cl_list(2, VV[14], v6true_label);
   ecl_bds_bind(cl_env_copy,VV[10],T0);           /*  *DESTINATION*   */
   ecl_function_dispatch(cl_env_copy,VV[51])(1, v2fmla) /*  C2EXPR*   */;
   ecl_bds_unwind1(cl_env_copy);
   ecl_function_dispatch(cl_env_copy,VV[52])(1, v4form2) /*  C2EXPR   */;
   value0 = ecl_function_dispatch(cl_env_copy,VV[53])(1, v6true_label) /*  MAYBE-WT-LABEL */;
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
L7:;
  {
   cl_object v7false_label;
   v7false_label = ecl_function_dispatch(cl_env_copy,VV[54])(0) /*  NEXT-LABEL */;
   T0 = CONS(v7false_label,ecl_symbol_value(VV[12]));
   ecl_bds_bind(cl_env_copy,VV[12],T0);           /*  *UNWIND-EXIT*   */
   T0 = cl_list(2, VV[13], v7false_label);
   ecl_bds_bind(cl_env_copy,VV[10],T0);           /*  *DESTINATION*   */
   ecl_function_dispatch(cl_env_copy,VV[51])(1, v2fmla) /*  C2EXPR*   */;
   ecl_bds_unwind1(cl_env_copy);
   ecl_function_dispatch(cl_env_copy,VV[52])(1, v3form1) /*  C2EXPR   */;
   ecl_function_dispatch(cl_env_copy,VV[55])(1, v7false_label) /*  WT-LABEL */;
   ecl_bds_unwind1(cl_env_copy);
  }
  value0 = ecl_function_dispatch(cl_env_copy,VV[52])(1, v4form2) /*  C2EXPR */;
  return value0;
 }
}
/*	function definition for NEGATE-ARGUMENT                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6negate_argument(cl_object v1inlined_arg, cl_object v2dest_loc)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3loc;
   cl_object v4rep_type;
   v3loc = ecl_cadr(v1inlined_arg);
   v4rep_type = ecl_function_dispatch(cl_env_copy,VV[57])(1, v3loc) /*  LOC-REPRESENTATION-TYPE */;
   T0 = ecl_fdefinition(VV[58]);
   T1 = ecl_list1(v1inlined_arg);
   T3 = ecl_function_dispatch(cl_env_copy,VV[57])(1, v2dest_loc) /*  LOC-REPRESENTATION-TYPE */;
   if (!((T3)==(VV[16]))) { goto L5; }
   if (!(ecl_eql(v4rep_type,VV[16]))) { goto L7; }
   T2 = VV[17];
   goto L4;
L7:;
   if (!(ecl_eql(v4rep_type,ECL_SYM("OBJECT",1278)))) { goto L9; }
   T2 = VV[18];
   goto L4;
L9:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L5:;
   if (!(ecl_eql(v4rep_type,VV[16]))) { goto L11; }
   T2 = VV[19];
   goto L4;
L11:;
   if (!(ecl_eql(v4rep_type,ECL_SYM("OBJECT",1278)))) { goto L13; }
   T2 = VV[20];
   goto L4;
L13:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L4:;
   value0 = cl_apply(3, T0, T1, T2);
   return value0;
  }
 }
}
/*	function definition for C2FMLA-NOT                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7c2fmla_not(cl_object v1c1form, cl_object v2arg)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3dest;
   v3dest = ecl_symbol_value(VV[10]);
   if (Null(L8jump_true_destination_p(v3dest))) { goto L2; }
   T0 = ecl_cdr(v3dest);
   T1 = CONS(VV[13],T0);
   ecl_bds_bind(cl_env_copy,VV[10],T1);           /*  *DESTINATION*   */
   value0 = ecl_function_dispatch(cl_env_copy,VV[52])(1, v2arg) /*  C2EXPR */;
   ecl_bds_unwind1(cl_env_copy);
   return value0;
L2:;
   if (Null(L9jump_false_destination_p(v3dest))) { goto L4; }
   T0 = ecl_cdr(v3dest);
   T1 = CONS(VV[14],T0);
   ecl_bds_bind(cl_env_copy,VV[10],T1);           /*  *DESTINATION*   */
   value0 = ecl_function_dispatch(cl_env_copy,VV[52])(1, v2arg) /*  C2EXPR */;
   ecl_bds_unwind1(cl_env_copy);
   return value0;
L4:;
   {
    cl_object v4;
    v4 = ecl_symbol_value(VV[22]);
    ecl_bds_bind(cl_env_copy,VV[23],ecl_make_fixnum(0)); /*  *INLINE-BLOCKS* */
    ecl_bds_bind(cl_env_copy,VV[22],v4);          /*  *TEMP*          */
    T0 = ecl_function_dispatch(cl_env_copy,VV[60])(2, v2arg, ECL_NIL) /*  EMIT-INLINE-FORM */;
    T1 = L6negate_argument(T0, v3dest);
    ecl_function_dispatch(cl_env_copy,VV[61])(1, T1) /*  UNWIND-EXIT  */;
    value0 = ecl_function_dispatch(cl_env_copy,VV[62])(0) /*  CLOSE-INLINE-BLOCKS */;
    ecl_bds_unwind1(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    return value0;
   }
  }
 }
}
/*	function definition for JUMP-TRUE-DESTINATION-P               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8jump_true_destination_p(cl_object v1dest)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_CONSP(v1dest))) { goto L2; }
  T0 = _ecl_car(v1dest);
  value0 = ecl_make_bool((T0)==(VV[14]));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for JUMP-FALSE-DESTINATION-P              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L9jump_false_destination_p(cl_object v1dest)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_CONSP(v1dest))) { goto L2; }
  T0 = _ecl_car(v1dest);
  value0 = ecl_make_bool((T0)==(VV[13]));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for C2FMLA-AND                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L10c2fmla_and(cl_object v1c1form, cl_object v2butlast, cl_object v3last)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(L9jump_false_destination_p(ecl_symbol_value(VV[10])))) { goto L1; }
  {
   cl_object v4;
   cl_object v5;
   v4 = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v2butlast))) FEtype_error_list(v2butlast);
   v5 = v2butlast;
L7:;
   if (!(ecl_endp(v5))) { goto L9; }
   goto L8;
L9:;
   v4 = _ecl_car(v5);
   {
    cl_object v6;
    v6 = _ecl_cdr(v5);
    if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
    v5 = v6;
   }
   ecl_function_dispatch(cl_env_copy,VV[51])(1, v4) /*  C2EXPR*       */;
   goto L7;
L8:;
   goto L3;
  }
L3:;
  value0 = ecl_function_dispatch(cl_env_copy,VV[52])(1, v3last) /*  C2EXPR */;
  return value0;
L1:;
  {
   cl_object v4normal_exit;
   v4normal_exit = ecl_function_dispatch(cl_env_copy,VV[54])(0) /*  NEXT-LABEL */;
   T0 = CONS(v4normal_exit,ecl_symbol_value(VV[12]));
   ecl_bds_bind(cl_env_copy,VV[12],T0);           /*  *UNWIND-EXIT*   */
   {
    cl_object v5false_label;
    v5false_label = ecl_function_dispatch(cl_env_copy,VV[54])(0) /*  NEXT-LABEL */;
    T0 = CONS(v5false_label,ecl_symbol_value(VV[12]));
    ecl_bds_bind(cl_env_copy,VV[12],T0);          /*  *UNWIND-EXIT*   */
    T0 = cl_list(2, VV[13], v5false_label);
    ecl_bds_bind(cl_env_copy,VV[10],T0);          /*  *DESTINATION*   */
    {
     cl_object v6;
     cl_object v7;
     v6 = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v2butlast))) FEtype_error_list(v2butlast);
     v7 = v2butlast;
L27:;
     if (!(ecl_endp(v7))) { goto L29; }
     goto L28;
L29:;
     v6 = _ecl_car(v7);
     {
      cl_object v8;
      v8 = _ecl_cdr(v7);
      if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
      v7 = v8;
     }
     ecl_function_dispatch(cl_env_copy,VV[51])(1, v6) /*  C2EXPR*     */;
     goto L27;
L28:;
     ecl_bds_unwind1(cl_env_copy);
     goto L23;
    }
L23:;
    ecl_function_dispatch(cl_env_copy,VV[52])(1, v3last) /*  C2EXPR   */;
    ecl_function_dispatch(cl_env_copy,VV[55])(1, v5false_label) /*  WT-LABEL */;
    ecl_bds_unwind1(cl_env_copy);
   }
   ecl_function_dispatch(cl_env_copy,VV[61])(1, ECL_NIL) /*  UNWIND-EXIT */;
   value0 = ecl_function_dispatch(cl_env_copy,VV[55])(1, v4normal_exit) /*  WT-LABEL */;
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
 }
}
/*	function definition for C2FMLA-OR                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L11c2fmla_or(cl_object v1c1form, cl_object v2butlast, cl_object v3last)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(L8jump_true_destination_p(ecl_symbol_value(VV[10])))) { goto L1; }
  {
   cl_object v4;
   cl_object v5;
   v4 = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v2butlast))) FEtype_error_list(v2butlast);
   v5 = v2butlast;
L7:;
   if (!(ecl_endp(v5))) { goto L9; }
   goto L8;
L9:;
   v4 = _ecl_car(v5);
   {
    cl_object v6;
    v6 = _ecl_cdr(v5);
    if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
    v5 = v6;
   }
   ecl_function_dispatch(cl_env_copy,VV[51])(1, v4) /*  C2EXPR*       */;
   goto L7;
L8:;
   goto L3;
  }
L3:;
  value0 = ecl_function_dispatch(cl_env_copy,VV[52])(1, v3last) /*  C2EXPR */;
  return value0;
L1:;
  if (Null(L9jump_false_destination_p(ecl_symbol_value(VV[10])))) { goto L20; }
  {
   cl_object v4true_label;
   v4true_label = ecl_function_dispatch(cl_env_copy,VV[54])(0) /*  NEXT-LABEL */;
   T0 = CONS(v4true_label,ecl_symbol_value(VV[12]));
   ecl_bds_bind(cl_env_copy,VV[12],T0);           /*  *UNWIND-EXIT*   */
   T0 = cl_list(2, VV[14], v4true_label);
   ecl_bds_bind(cl_env_copy,VV[10],T0);           /*  *DESTINATION*   */
   {
    cl_object v5;
    cl_object v6;
    v5 = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v2butlast))) FEtype_error_list(v2butlast);
    v6 = v2butlast;
L28:;
    if (!(ecl_endp(v6))) { goto L30; }
    goto L29;
L30:;
    v5 = _ecl_car(v6);
    {
     cl_object v7;
     v7 = _ecl_cdr(v6);
     if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
     v6 = v7;
    }
    ecl_function_dispatch(cl_env_copy,VV[51])(1, v5) /*  C2EXPR*      */;
    goto L28;
L29:;
    ecl_bds_unwind1(cl_env_copy);
    goto L24;
   }
L24:;
   ecl_function_dispatch(cl_env_copy,VV[52])(1, v3last) /*  C2EXPR    */;
   ecl_function_dispatch(cl_env_copy,VV[55])(1, v4true_label) /*  WT-LABEL */;
   ecl_bds_unwind1(cl_env_copy);
  }
  value0 = ecl_function_dispatch(cl_env_copy,VV[61])(1, ECL_T) /*  UNWIND-EXIT */;
  return value0;
L20:;
  {
   cl_object v4common_exit;
   v4common_exit = ecl_function_dispatch(cl_env_copy,VV[54])(0) /*  NEXT-LABEL */;
   T0 = CONS(v4common_exit,ecl_symbol_value(VV[12]));
   ecl_bds_bind(cl_env_copy,VV[12],T0);           /*  *UNWIND-EXIT*   */
   {
    cl_object v5normal_exit;
    v5normal_exit = ecl_function_dispatch(cl_env_copy,VV[54])(0) /*  NEXT-LABEL */;
    T0 = CONS(v5normal_exit,ecl_symbol_value(VV[12]));
    ecl_bds_bind(cl_env_copy,VV[12],T0);          /*  *UNWIND-EXIT*   */
    {
     cl_object v6;
     v6 = v2butlast;
     goto L49;
L48:;
     {
      cl_object v7f;
      v7f = ecl_car(v6);
      ecl_bds_bind(cl_env_copy,VV[10],VV[28]);    /*  *DESTINATION*   */
      ecl_function_dispatch(cl_env_copy,VV[51])(1, v7f) /*  C2EXPR*   */;
      ecl_bds_unwind1(cl_env_copy);
      L12set_jump_true(VV[28], v5normal_exit);
     }
     v6 = ecl_cdr(v6);
L49:;
     if (Null(v6)) { goto L57; }
     goto L48;
L57:;
    }
    ecl_function_dispatch(cl_env_copy,VV[52])(1, v3last) /*  C2EXPR   */;
    ecl_function_dispatch(cl_env_copy,VV[55])(1, v5normal_exit) /*  WT-LABEL */;
    ecl_bds_unwind1(cl_env_copy);
   }
   ecl_function_dispatch(cl_env_copy,VV[61])(1, VV[28]) /*  UNWIND-EXIT */;
   value0 = ecl_function_dispatch(cl_env_copy,VV[55])(1, v4common_exit) /*  WT-LABEL */;
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
 }
}
/*	function definition for SET-JUMP-TRUE                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L12set_jump_true(cl_object v1loc, cl_object v2label)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4;                                  /*  CONSTANTP       */
   cl_object v5;                                  /*  VALUE           */
   value0 = ecl_function_dispatch(cl_env_copy,VV[68])(1, v1loc) /*  LOC-IMMEDIATE-VALUE-P */;
   v4 = value0;
   {
    const int v6 = cl_env_copy->nvalues;
    cl_object v7;
    v7 = (v6<=1)? ECL_NIL : cl_env_copy->values[1];
    v5 = v7;
   }
   if ((v4)!=ECL_NIL) { goto L2; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[57])(1, v1loc) /*  LOC-REPRESENTATION-TYPE */;
   if (!((T0)==(VV[16]))) { goto L5; }
   ecl_function_dispatch(cl_env_copy,VV[69])(3, _ecl_static_1, v1loc, _ecl_static_2) /*  WT-NL */;
   goto L4;
L5:;
   ecl_function_dispatch(cl_env_copy,VV[69])(1, _ecl_static_3) /*  WT-NL */;
   ecl_function_dispatch(cl_env_copy,VV[70])(2, ECL_SYM("OBJECT",1278), v1loc) /*  WT-COERCE-LOC */;
   ecl_function_dispatch(cl_env_copy,VV[71])(1, _ecl_static_4) /*  WT */;
L4:;
   if (Null(ecl_function_dispatch(cl_env_copy,VV[72])(1, v2label) /*  UNWIND-NO-EXIT */)) { goto L9; }
   cl_set(VV[30],ecl_plus(ecl_symbol_value(VV[30]),ecl_make_fixnum(1)));
   ecl_function_dispatch(cl_env_copy,VV[69])(0)   /*  WT-NL           */;
   ecl_function_dispatch(cl_env_copy,VV[73])(1, v2label) /*  WT-GO    */;
   value0 = ecl_function_dispatch(cl_env_copy,VV[74])(0) /*  WT-NL-CLOSE-BRACE */;
   return value0;
L9:;
   ecl_function_dispatch(cl_env_copy,VV[71])(1, _ecl_static_5) /*  WT */;
   ecl_function_dispatch(cl_env_copy,VV[73])(1, v2label) /*  WT-GO    */;
   value0 = ecl_function_dispatch(cl_env_copy,VV[71])(1, _ecl_static_6) /*  WT */;
   return value0;
L2:;
   {
    cl_object v6;
    v6 = ecl_make_bool(v5==ECL_NIL);
    if (Null(v6)) { goto L18; }
    value0 = v6;
    cl_env_copy->nvalues = 1;
    return value0;
L18:;
    ecl_function_dispatch(cl_env_copy,VV[72])(1, v2label) /*  UNWIND-NO-EXIT */;
    ecl_function_dispatch(cl_env_copy,VV[69])(0)  /*  WT-NL           */;
    value0 = ecl_function_dispatch(cl_env_copy,VV[73])(1, v2label) /*  WT-GO */;
    return value0;
   }
  }
 }
}
/*	function definition for SET-JUMP-FALSE                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L13set_jump_false(cl_object v1loc, cl_object v2label)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4;                                  /*  CONSTANTP       */
   cl_object v5;                                  /*  VALUE           */
   value0 = ecl_function_dispatch(cl_env_copy,VV[68])(1, v1loc) /*  LOC-IMMEDIATE-VALUE-P */;
   v4 = value0;
   {
    const int v6 = cl_env_copy->nvalues;
    cl_object v7;
    v7 = (v6<=1)? ECL_NIL : cl_env_copy->values[1];
    v5 = v7;
   }
   if ((v4)!=ECL_NIL) { goto L2; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[57])(1, v1loc) /*  LOC-REPRESENTATION-TYPE */;
   if (!((T0)==(VV[16]))) { goto L5; }
   ecl_function_dispatch(cl_env_copy,VV[69])(3, _ecl_static_7, v1loc, _ecl_static_8) /*  WT-NL */;
   goto L4;
L5:;
   ecl_function_dispatch(cl_env_copy,VV[69])(1, _ecl_static_9) /*  WT-NL */;
   ecl_function_dispatch(cl_env_copy,VV[70])(2, ECL_SYM("OBJECT",1278), v1loc) /*  WT-COERCE-LOC */;
   ecl_function_dispatch(cl_env_copy,VV[71])(1, _ecl_static_8) /*  WT */;
L4:;
   if (Null(ecl_function_dispatch(cl_env_copy,VV[72])(1, v2label) /*  UNWIND-NO-EXIT */)) { goto L9; }
   cl_set(VV[30],ecl_plus(ecl_symbol_value(VV[30]),ecl_make_fixnum(1)));
   ecl_function_dispatch(cl_env_copy,VV[69])(0)   /*  WT-NL           */;
   ecl_function_dispatch(cl_env_copy,VV[73])(1, v2label) /*  WT-GO    */;
   value0 = ecl_function_dispatch(cl_env_copy,VV[74])(0) /*  WT-NL-CLOSE-BRACE */;
   return value0;
L9:;
   ecl_function_dispatch(cl_env_copy,VV[71])(1, _ecl_static_5) /*  WT */;
   ecl_function_dispatch(cl_env_copy,VV[73])(1, v2label) /*  WT-GO    */;
   value0 = ecl_function_dispatch(cl_env_copy,VV[71])(1, _ecl_static_6) /*  WT */;
   return value0;
L2:;
   if (Null(v5)) { goto L17; }
   value0 = v5;
   cl_env_copy->nvalues = 1;
   return value0;
L17:;
   ecl_function_dispatch(cl_env_copy,VV[72])(1, v2label) /*  UNWIND-NO-EXIT */;
   ecl_function_dispatch(cl_env_copy,VV[69])(0)   /*  WT-NL           */;
   value0 = ecl_function_dispatch(cl_env_copy,VV[73])(1, v2label) /*  WT-GO */;
   return value0;
  }
 }
}

#include "cmp/cmpif.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecl0Sr2T4drzehh9_oxptVE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPIF.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_ecl0Sr2T4drzehh9_oxptVE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[33]);                           /*  C1IF            */
 ecl_cmp_defun(VV[40]);                           /*  C1NOT           */
 ecl_cmp_defun(VV[41]);                           /*  C1AND           */
 ecl_cmp_defun(VV[46]);                           /*  C1OR            */
 ecl_cmp_defun(VV[48]);                           /*  C2IF            */
 ecl_cmp_defun(VV[56]);                           /*  NEGATE-ARGUMENT */
 ecl_cmp_defun(VV[59]);                           /*  C2FMLA-NOT      */
 ecl_cmp_defun(VV[63]);                           /*  JUMP-TRUE-DESTINATION-P */
 ecl_cmp_defun(VV[64]);                           /*  JUMP-FALSE-DESTINATION-P */
 ecl_cmp_defun(VV[65]);                           /*  C2FMLA-AND      */
 ecl_cmp_defun(VV[66]);                           /*  C2FMLA-OR       */
 ecl_cmp_defun(VV[67]);                           /*  SET-JUMP-TRUE   */
 ecl_cmp_defun(VV[75]);                           /*  SET-JUMP-FALSE  */
}
