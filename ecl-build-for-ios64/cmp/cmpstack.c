/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPSTACK.LSP                                  */
#include <ecl/ecl-cmp.h>
#include "cmp/cmpstack.eclh"
/*	function definition for C1WITH-STACK                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1c1with_stack(cl_object v1forms)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2var;
   cl_object v3body;
   {
    cl_object v4;
    v4 = v1forms;
    if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
    if (Null(v4)) { goto L5; }
    {
     cl_object v5;
     v5 = ECL_CONS_CDR(v4);
     v1forms = v5;
     v4 = ECL_CONS_CAR(v4);
    }
L5:;
    v2var = v4;
   }
   T0 = cl_list(2, v2var, VV[3]);
   T1 = ecl_list1(T0);
   T2 = cl_listX(3, ECL_SYM("LET",477), T1, v1forms);
   v3body = ecl_function_dispatch(cl_env_copy,VV[27])(1, T2) /*  C1EXPR */;
   T0 = ecl_function_dispatch(cl_env_copy,VV[28])(1, v3body) /*  C1FORM-TYPE */;
   value0 = ecl_function_dispatch(cl_env_copy,VV[29])(5, VV[4], ECL_SYM("TYPE",1318), T0, VV[5], v3body) /*  MAKE-C1FORM* */;
   return value0;
  }
 }
}
/*	function definition for C2WITH-STACK                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2c2with_stack(cl_object v1c1form, cl_object v2body)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3new_destination;
   v3new_destination = ecl_function_dispatch(cl_env_copy,VV[31])(1, ecl_symbol_value(VV[7])) /*  TMP-DESTINATION */;
   ecl_bds_push(cl_env_copy,VV[8]);               /*  *TEMP*          */
   ecl_function_dispatch(cl_env_copy,VV[32])(0)   /*  WT-NL-OPEN-BRACE */;
   ecl_function_dispatch(cl_env_copy,VV[33])(1, _ecl_static_4) /*  WT-NL */;
   ecl_function_dispatch(cl_env_copy,VV[33])(2, ecl_symbol_value(VV[9]), _ecl_static_5) /*  WT-NL */;
   ecl_bds_bind(cl_env_copy,VV[7],v3new_destination); /*  *DESTINATION* */
   T0 = cl_list(2, VV[11], ecl_symbol_value(VV[0]));
   T1 = CONS(T0,ecl_symbol_value(VV[10]));
   ecl_bds_bind(cl_env_copy,VV[10],T1);           /*  *UNWIND-EXIT*   */
   ecl_function_dispatch(cl_env_copy,VV[34])(1, v2body) /*  C2EXPR*   */;
   ecl_bds_unwind1(cl_env_copy);
   ecl_bds_unwind1(cl_env_copy);
   ecl_function_dispatch(cl_env_copy,VV[33])(1, _ecl_static_6) /*  WT-NL */;
   ecl_function_dispatch(cl_env_copy,VV[35])(0)   /*  WT-NL-CLOSE-BRACE */;
   value0 = ecl_function_dispatch(cl_env_copy,VV[36])(1, v3new_destination) /*  UNWIND-EXIT */;
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
 }
}
/*	function definition for C1INNERMOST-STACK-FRAME               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3c1innermost_stack_frame(cl_object v1args)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_listX(6, ECL_SYM("C-INLINE",1973), ECL_NIL, ECL_NIL, ECL_SYM("OBJECT",1278), ecl_symbol_value(VV[0]), VV[13]);
  return value0;
 }
}
/*	function definition for C1STACK-PUSH                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4c1stack_push(cl_object v1args)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_listX(3, ECL_SYM("C-INLINE",1973), v1args, VV[15]);
  value0 = cl_list(3, ECL_SYM("PROGN",671), T0, ecl_make_fixnum(1));
  return value0;
 }
}
/*	function definition for C1STACK-PUSH-VALUES                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5c1stack_push_values(cl_object v1args)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   cl_object v3;
   {
    cl_object v4;
    v4 = v1args;
    if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
    if (Null(v4)) { goto L5; }
    {
     cl_object v5;
     v5 = ECL_CONS_CDR(v4);
     v1args = v5;
     v4 = ECL_CONS_CAR(v4);
    }
L5:;
    v2 = v4;
   }
   {
    cl_object v4;
    v4 = v1args;
    if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
    if (Null(v4)) { goto L15; }
    {
     cl_object v5;
     v5 = ECL_CONS_CDR(v4);
     v1args = v5;
     v4 = ECL_CONS_CAR(v4);
    }
L15:;
    v3 = v4;
   }
   T0 = ecl_function_dispatch(cl_env_copy,VV[27])(1, v3) /*  C1EXPR   */;
   T1 = ecl_list1(v2);
   T2 = cl_listX(3, ECL_SYM("C-INLINE",1973), T1, VV[19]);
   T3 = ecl_function_dispatch(cl_env_copy,VV[27])(1, T2) /*  C1EXPR   */;
   value0 = ecl_function_dispatch(cl_env_copy,VV[29])(6, VV[17], ECL_SYM("TYPE",1318), VV[18], VV[5], T0, T3) /*  MAKE-C1FORM* */;
   return value0;
  }
 }
}
/*	function definition for C2STACK-PUSH-VALUES                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6c2stack_push_values(cl_object v1c1form, cl_object v2form, cl_object v3push_statement)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_bds_bind(cl_env_copy,VV[7],ECL_SYM("VALUES",895)); /*  *DESTINATION* */
  ecl_function_dispatch(cl_env_copy,VV[34])(1, v2form) /*  C2EXPR*    */;
  ecl_bds_unwind1(cl_env_copy);
  value0 = ecl_function_dispatch(cl_env_copy,VV[41])(1, v3push_statement) /*  C2EXPR */;
  return value0;
 }
}
/*	function definition for C1STACK-POP                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7c1stack_pop(cl_object v1args)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_listX(3, ECL_SYM("C-INLINE",1973), v1args, VV[22]);
  return value0;
 }
}
/*	function definition for C1APPLY-FROM-STACK-FRAME              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8c1apply_from_stack_frame(cl_object v1args)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_listX(3, ECL_SYM("C-INLINE",1973), v1args, VV[24]);
  return value0;
 }
}

#include "cmp/cmpstack.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecl6ADWaEv2FLgr9_4fqtVE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPSTACK.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_ecl6ADWaEv2FLgr9_4fqtVE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 si_Xmake_constant(VV[0], _ecl_static_1);
 si_Xmake_constant(VV[1], _ecl_static_2);
 si_Xmake_constant(VV[2], _ecl_static_3);
 ecl_cmp_defun(VV[26]);                           /*  C1WITH-STACK    */
 ecl_cmp_defun(VV[30]);                           /*  C2WITH-STACK    */
 ecl_cmp_defun(VV[37]);                           /*  C1INNERMOST-STACK-FRAME */
 ecl_cmp_defun(VV[38]);                           /*  C1STACK-PUSH    */
 ecl_cmp_defun(VV[39]);                           /*  C1STACK-PUSH-VALUES */
 ecl_cmp_defun(VV[40]);                           /*  C2STACK-PUSH-VALUES */
 ecl_cmp_defun(VV[42]);                           /*  C1STACK-POP     */
 ecl_cmp_defun(VV[43]);                           /*  C1APPLY-FROM-STACK-FRAME */
}
