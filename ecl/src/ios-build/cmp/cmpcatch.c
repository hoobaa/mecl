/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPCATCH.LSP                                  */
#include <ecl/ecl-cmp.h>
#include "cmp/cmpcatch.eclh"
/*	function definition for C1CATCH                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1c1catch(cl_object v1args)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_function_dispatch(cl_env_copy,VV[27])(3, ECL_SYM("CATCH",182), v1args, ecl_make_fixnum(1)) /*  CHECK-ARGS-NUMBER */;
  cl_set(VV[0],ecl_plus(ecl_symbol_value(VV[0]),ecl_make_fixnum(1)));
  T0 = ecl_car(v1args);
  T1 = ecl_function_dispatch(cl_env_copy,VV[28])(1, T0) /*  C1EXPR    */;
  T2 = ecl_cdr(v1args);
  T3 = ecl_function_dispatch(cl_env_copy,VV[29])(1, T2) /*  C1PROGN   */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[30])(8, ECL_SYM("CATCH",182), VV[1], ECL_T, ECL_SYM("TYPE",1318), ECL_T, VV[2], T1, T3) /*  MAKE-C1FORM* */;
  return value0;
 }
}
/*	function definition for C2CATCH                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2c2catch(cl_object v1c1form, cl_object v2tag, cl_object v3body)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4new_destination;
   cl_object v5code;
   v4new_destination = ecl_function_dispatch(cl_env_copy,VV[32])(1, ecl_symbol_value(VV[4])) /*  TMP-DESTINATION */;
   cl_set(VV[5],ecl_plus(ecl_symbol_value(VV[5]),ecl_make_fixnum(1)));
   v5code = ecl_symbol_value(VV[5]);
   ecl_bds_bind(cl_env_copy,VV[4],VV[6]);         /*  *DESTINATION*   */
   ecl_function_dispatch(cl_env_copy,VV[33])(1, v2tag) /*  C2EXPR*    */;
   ecl_bds_unwind1(cl_env_copy);
   ecl_bds_bind(cl_env_copy,VV[4],v4new_destination); /*  *DESTINATION* */
   T0 = CONS(VV[8],ecl_symbol_value(VV[7]));
   ecl_bds_bind(cl_env_copy,VV[7],T0);            /*  *UNWIND-EXIT*   */
   if (!((v4new_destination)==(VV[9]))) { goto L11; }
   goto L8;
   goto L9;
L11:;
   goto L9;
L9:;
   if (!((v4new_destination)==(ECL_SYM("VALUES",895)))) { goto L6; }
   goto L7;
L8:;
L7:;
   ecl_function_dispatch(cl_env_copy,VV[34])(3, _ecl_static_1, VV[6], _ecl_static_2) /*  WT-NL */;
   ecl_function_dispatch(cl_env_copy,VV[35])(2, _ecl_static_3, v5code) /*  WT-COMMENT */;
   T0 = ecl_one_plus(ecl_symbol_value(VV[12]));
   ecl_bds_bind(cl_env_copy,VV[12],T0);           /*  *OPENED-C-BRACES* */
   ecl_function_dispatch(cl_env_copy,VV[33])(1, v3body) /*  C2EXPR*   */;
   ecl_bds_unwind1(cl_env_copy);
   ecl_bds_unwind1(cl_env_copy);
   ecl_bds_unwind1(cl_env_copy);
   goto L5;
L6:;
   ecl_function_dispatch(cl_env_copy,VV[34])(3, _ecl_static_1, VV[6], _ecl_static_4) /*  WT-NL */;
   ecl_function_dispatch(cl_env_copy,VV[35])(2, _ecl_static_3, v5code) /*  WT-COMMENT */;
   T0 = ecl_one_plus(ecl_symbol_value(VV[12]));
   ecl_bds_bind(cl_env_copy,VV[12],T0);           /*  *OPENED-C-BRACES* */
   {
    cl_object v6label;
    v6label = ecl_function_dispatch(cl_env_copy,VV[36])(0) /*  NEXT-LABEL */;
    T0 = CONS(v6label,ecl_symbol_value(VV[7]));
    ecl_bds_bind(cl_env_copy,VV[7],T0);           /*  *UNWIND-EXIT*   */
    ecl_bds_bind(cl_env_copy,VV[13],v6label);     /*  *EXIT*          */
    ecl_function_dispatch(cl_env_copy,VV[37])(1, ECL_SYM("VALUES",895)) /*  UNWIND-EXIT */;
    ecl_bds_unwind1(cl_env_copy);
    ecl_function_dispatch(cl_env_copy,VV[38])(1, v6label) /*  WT-LABEL */;
    ecl_bds_unwind1(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
   }
   ecl_function_dispatch(cl_env_copy,VV[34])(1, _ecl_static_5) /*  WT-NL */;
   T0 = ecl_one_plus(ecl_symbol_value(VV[12]));
   ecl_bds_bind(cl_env_copy,VV[12],T0);           /*  *OPENED-C-BRACES* */
   ecl_function_dispatch(cl_env_copy,VV[33])(1, v3body) /*  C2EXPR*   */;
   ecl_bds_unwind1(cl_env_copy);
   ecl_bds_unwind1(cl_env_copy);
   ecl_bds_unwind1(cl_env_copy);
L5:;
   ecl_function_dispatch(cl_env_copy,VV[34])(1, _ecl_static_6) /*  WT-NL */;
   ecl_function_dispatch(cl_env_copy,VV[34])(1, _ecl_static_7) /*  WT-NL */;
   ecl_function_dispatch(cl_env_copy,VV[35])(2, _ecl_static_8, v5code) /*  WT-COMMENT */;
   value0 = ecl_function_dispatch(cl_env_copy,VV[37])(1, v4new_destination) /*  UNWIND-EXIT */;
   return value0;
  }
 }
}
/*	function definition for C1UNWIND-PROTECT                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3c1unwind_protect(cl_object v1args)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_function_dispatch(cl_env_copy,VV[27])(3, ECL_SYM("UNWIND-PROTECT",888), v1args, ecl_make_fixnum(1)) /*  CHECK-ARGS-NUMBER */;
  cl_set(VV[0],ecl_plus(ecl_symbol_value(VV[0]),ecl_make_fixnum(1)));
  {
   cl_object v2form;
   T0 = ecl_function_dispatch(cl_env_copy,VV[40])(1, ECL_SYM("UNWIND-PROTECT",888)) /*  CMP-ENV-MARK */;
   ecl_bds_bind(cl_env_copy,VV[15],T0);           /*  *CMP-ENV*       */
   T0 = ecl_car(v1args);
   v2form = ecl_function_dispatch(cl_env_copy,VV[28])(1, T0) /*  C1EXPR */;
   ecl_bds_unwind1(cl_env_copy);
   T0 = ecl_function_dispatch(cl_env_copy,VV[41])(1, v2form) /*  C1FORM-TYPE */;
   T1 = ecl_cdr(v1args);
   T2 = ecl_function_dispatch(cl_env_copy,VV[29])(1, T1) /*  C1PROGN  */;
   value0 = ecl_function_dispatch(cl_env_copy,VV[30])(8, ECL_SYM("UNWIND-PROTECT",888), ECL_SYM("TYPE",1318), T0, VV[1], ECL_T, VV[2], v2form, T2) /*  MAKE-C1FORM* */;
   return value0;
  }
 }
}
/*	function definition for C2UNWIND-PROTECT                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4c2unwind_protect(cl_object v1c1form, cl_object v2form, cl_object v3body)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4sp;
   cl_object v5nargs;
   v4sp = ecl_function_dispatch(cl_env_copy,VV[43])(2, VV[17], VV[18]) /*  MAKE-LCL-VAR */;
   v5nargs = ecl_function_dispatch(cl_env_copy,VV[43])(2, VV[17], VV[18]) /*  MAKE-LCL-VAR */;
   T0 = cl_list(2, VV[19], v4sp);
   T1 = CONS(T0,ecl_symbol_value(VV[7]));
   ecl_bds_bind(cl_env_copy,VV[7],T1);            /*  *UNWIND-EXIT*   */
   ecl_function_dispatch(cl_env_copy,VV[44])(0)   /*  WT-NL-OPEN-BRACE */;
   ecl_function_dispatch(cl_env_copy,VV[34])(1, _ecl_static_9) /*  WT-NL */;
   ecl_function_dispatch(cl_env_copy,VV[34])(5, _ecl_static_10, v4sp, _ecl_static_11, v5nargs, _ecl_static_12) /*  WT-NL */;
   ecl_function_dispatch(cl_env_copy,VV[34])(1, _ecl_static_13) /*  WT-NL */;
   ecl_function_dispatch(cl_env_copy,VV[34])(1, _ecl_static_14) /*  WT-NL */;
   ecl_function_dispatch(cl_env_copy,VV[34])(1, _ecl_static_15) /*  WT-NL */;
   ecl_function_dispatch(cl_env_copy,VV[34])(1, _ecl_static_5) /*  WT-NL */;
   {
    cl_object v6;
    v6 = CONS(VV[8],ecl_symbol_value(VV[7]));
    ecl_bds_bind(cl_env_copy,VV[7],v6);           /*  *UNWIND-EXIT*   */
    ecl_bds_bind(cl_env_copy,VV[4],ECL_SYM("VALUES",895)); /*  *DESTINATION* */
    ecl_function_dispatch(cl_env_copy,VV[33])(1, v2form) /*  C2EXPR*  */;
    ecl_bds_unwind1(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
   }
   ecl_function_dispatch(cl_env_copy,VV[34])(1, _ecl_static_6) /*  WT-NL */;
   ecl_function_dispatch(cl_env_copy,VV[34])(1, _ecl_static_7) /*  WT-NL */;
   ecl_function_dispatch(cl_env_copy,VV[34])(2, v5nargs, _ecl_static_16) /*  WT-NL */;
   ecl_bds_bind(cl_env_copy,VV[4],VV[9]);         /*  *DESTINATION*   */
   ecl_function_dispatch(cl_env_copy,VV[33])(1, v3body) /*  C2EXPR*   */;
   ecl_bds_unwind1(cl_env_copy);
   ecl_function_dispatch(cl_env_copy,VV[34])(3, _ecl_static_17, v5nargs, _ecl_static_18) /*  WT-NL */;
   ecl_function_dispatch(cl_env_copy,VV[34])(1, _ecl_static_19) /*  WT-NL */;
   ecl_function_dispatch(cl_env_copy,VV[37])(1, ECL_SYM("VALUES",895)) /*  UNWIND-EXIT */;
   value0 = ecl_function_dispatch(cl_env_copy,VV[45])(0) /*  WT-NL-CLOSE-BRACE */;
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
 }
}
/*	function definition for C1THROW                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5c1throw(cl_object v1args)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_function_dispatch(cl_env_copy,VV[27])(4, ECL_SYM("THROW",858), v1args, ecl_make_fixnum(2), ecl_make_fixnum(2)) /*  CHECK-ARGS-NUMBER */;
  T0 = ecl_car(v1args);
  T1 = ecl_function_dispatch(cl_env_copy,VV[28])(1, T0) /*  C1EXPR    */;
  T2 = ecl_cadr(v1args);
  T3 = ecl_function_dispatch(cl_env_copy,VV[28])(1, T2) /*  C1EXPR    */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[30])(4, ECL_SYM("THROW",858), VV[2], T1, T3) /*  MAKE-C1FORM* */;
  return value0;
 }
}
/*	function definition for C2THROW                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6c2throw(cl_object v1c1form, cl_object v2tag, cl_object v3val)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4loc;
   v4loc = ECL_NIL;
   {
    cl_object v5;
    v5 = ecl_function_dispatch(cl_env_copy,VV[48])(1, v2tag) /*  C1FORM-NAME */;
    if (!((v5)==(VV[22]))) { goto L9; }
    goto L6;
    goto L7;
L9:;
    goto L7;
L7:;
    if (!((v5)==(ECL_SYM("LOCATION",1763)))) { goto L4; }
    goto L5;
L6:;
L5:;
    T0 = ecl_function_dispatch(cl_env_copy,VV[49])(1, v2tag) /*  C1FORM-ARGS */;
    v4loc = ecl_car(T0);
    goto L2;
L4:;
    v4loc = ecl_function_dispatch(cl_env_copy,VV[50])(0) /*  MAKE-TEMP-VAR */;
    ecl_bds_bind(cl_env_copy,VV[4],v4loc);        /*  *DESTINATION*   */
    ecl_function_dispatch(cl_env_copy,VV[33])(1, v2tag) /*  C2EXPR*   */;
    ecl_bds_unwind1(cl_env_copy);
   }
L2:;
   ecl_bds_bind(cl_env_copy,VV[4],ECL_SYM("VALUES",895)); /*  *DESTINATION* */
   ecl_function_dispatch(cl_env_copy,VV[33])(1, v3val) /*  C2EXPR*    */;
   ecl_bds_unwind1(cl_env_copy);
   value0 = ecl_function_dispatch(cl_env_copy,VV[34])(3, _ecl_static_20, v4loc, _ecl_static_18) /*  WT-NL */;
   return value0;
  }
 }
}

#include "cmp/cmpcatch.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclJ31veDVSoKtm9_RvxTOE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPCATCH.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclJ31veDVSoKtm9_RvxTOE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[26]);                           /*  C1CATCH         */
 ecl_cmp_defun(VV[31]);                           /*  C2CATCH         */
 ecl_cmp_defun(VV[39]);                           /*  C1UNWIND-PROTECT */
 ecl_cmp_defun(VV[42]);                           /*  C2UNWIND-PROTECT */
 ecl_cmp_defun(VV[46]);                           /*  C1THROW         */
 ecl_cmp_defun(VV[47]);                           /*  C2THROW         */
}
