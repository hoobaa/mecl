/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPBLOCK.LSP                                  */
#include <ecl/ecl-cmp.h>
#include "cmp/cmpblock.eclh"
/*	function definition for C1BLOCK                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1c1block(cl_object v1args)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_function_dispatch(cl_env_copy,VV[26])(3, ECL_SYM("BLOCK",137), v1args, ecl_make_fixnum(1)) /*  CHECK-ARGS-NUMBER */;
  {
   cl_object v2block_name;
   v2block_name = ecl_car(v1args);
   if (ECL_SYMBOLP(v2block_name)) { goto L3; }
   ecl_function_dispatch(cl_env_copy,VV[27])(2, _ecl_static_1, v2block_name) /*  CMPERR */;
L3:;
   {
    cl_object v3blk_var;
    cl_object v4blk;
    cl_object v5body;
    v3blk_var = ecl_function_dispatch(cl_env_copy,VV[28])(4, ECL_SYM("NAME",1273), v2block_name, VV[0], VV[1]) /*  MAKE-VAR */;
    v4blk = ecl_function_dispatch(cl_env_copy,VV[29])(4, VV[2], v3blk_var, ECL_SYM("NAME",1273), v2block_name) /*  MAKE-BLK */;
    T0 = ecl_function_dispatch(cl_env_copy,VV[30])(0) /*  CMP-ENV-COPY */;
    ecl_bds_bind(cl_env_copy,VV[3],T0);           /*  *CMP-ENV*       */
    ecl_function_dispatch(cl_env_copy,VV[31])(1, v4blk) /*  CMP-ENV-REGISTER-BLOCK */;
    T0 = ecl_cdr(v1args);
    v5body = ecl_function_dispatch(cl_env_copy,VV[32])(1, T0) /*  C1PROGN */;
    ecl_bds_unwind1(cl_env_copy);
    if ((ecl_function_dispatch(cl_env_copy,VV[33])(1, v4blk) /*  BLK-REF-CCB */)!=ECL_NIL) { goto L11; }
    if (Null(ecl_function_dispatch(cl_env_copy,VV[34])(1, v4blk) /*  BLK-REF-CLB */)) { goto L9; }
    goto L10;
L11:;
L10:;
    cl_set(VV[4],ecl_plus(ecl_symbol_value(VV[4]),ecl_make_fixnum(1)));
L9:;
    T0 = ecl_function_dispatch(cl_env_copy,VV[35])(1, v4blk) /*  BLK-REF */;
    if (!(ecl_plusp(T0))) { goto L14; }
    T0 = ecl_list1(v3blk_var);
    T1 = ecl_function_dispatch(cl_env_copy,VV[36])(1, v4blk) /*  BLK-TYPE */;
    T2 = ecl_function_dispatch(cl_env_copy,VV[37])(1, v5body) /*  C1FORM-TYPE */;
    T3 = ecl_function_dispatch(cl_env_copy,VV[38])(2, T1, T2) /*  VALUES-TYPE-OR */;
    value0 = ecl_function_dispatch(cl_env_copy,VV[39])(8, ECL_SYM("BLOCK",137), VV[5], T0, ECL_SYM("TYPE",1318), T3, VV[6], v4blk, v5body) /*  MAKE-C1FORM* */;
    return value0;
L14:;
    value0 = v5body;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for C2BLOCK                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2c2block(cl_object v1c1form, cl_object v2blk, cl_object v3body)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[41])(1, v2blk) /*  BLK-VAR */;
  T1 = ecl_function_dispatch(cl_env_copy,VV[42])(1, T0) /*  VAR-REF   */;
  if (!(ecl_plusp(T1))) { goto L1; }
  {
   cl_object v4blk_var;
   v4blk_var = ecl_function_dispatch(cl_env_copy,VV[41])(1, v2blk) /*  BLK-VAR */;
   ecl_bds_push(cl_env_copy,VV[8]);               /*  *ENV-LVL*       */
   {
    cl_object v5;
    v5 = ecl_symbol_value(VV[9]);
    ecl_structure_set(v2blk,VV[10],5,v5);
   }
   {
    cl_object v5;
    v5 = ecl_symbol_value(VV[11]);
    ecl_structure_set(v2blk,VV[10],6,v5);
   }
   ecl_function_dispatch(cl_env_copy,VV[43])(0)   /*  WT-NL-OPEN-BRACE */;
   if ((ecl_function_dispatch(cl_env_copy,VV[33])(1, v2blk) /*  BLK-REF-CCB */)!=ECL_NIL) { goto L9; }
   if ((ecl_function_dispatch(cl_env_copy,VV[34])(1, v2blk) /*  BLK-REF-CLB */)!=ECL_NIL) { goto L9; }
   ecl_structure_set(v4blk_var,VV[12],6,ECL_SYM("OBJECT",1278));
   {
    cl_object v5;
    v5 = ecl_function_dispatch(cl_env_copy,VV[44])(0) /*  NEXT-LCL    */;
    ecl_structure_set(v4blk_var,VV[12],10,v5);
   }
   ecl_function_dispatch(cl_env_copy,VV[45])(3, _ecl_static_2, v4blk_var, _ecl_static_3) /*  WT-NL */;
L9:;
   T0 = ecl_function_dispatch(cl_env_copy,VV[33])(1, v2blk) /*  BLK-REF-CCB */;
   if (Null(ecl_function_dispatch(cl_env_copy,VV[46])(1, T0) /*  ENV-GROWS */)) { goto L15; }
   {
    cl_object v5env_lvl;
    v5env_lvl = ecl_symbol_value(VV[8]);
    cl_set(VV[8],ecl_plus(ecl_symbol_value(VV[8]),ecl_make_fixnum(1)));
    T0 = ecl_symbol_value(VV[8]);
    ecl_function_dispatch(cl_env_copy,VV[45])(6, ecl_symbol_value(VV[13]), _ecl_static_4, T0, _ecl_static_5, v5env_lvl, _ecl_static_3) /*  WT-NL */;
   }
L15:;
   ecl_function_dispatch(cl_env_copy,VV[47])(2, _ecl_static_6, v4blk_var) /*  BIND */;
   ecl_function_dispatch(cl_env_copy,VV[45])(3, _ecl_static_7, v4blk_var, _ecl_static_8) /*  WT-NL */;
   T0 = CONS(VV[15],ecl_symbol_value(VV[14]));
   ecl_bds_bind(cl_env_copy,VV[14],T0);           /*  *UNWIND-EXIT*   */
   ecl_function_dispatch(cl_env_copy,VV[48])(1, ECL_SYM("VALUES",895)) /*  UNWIND-EXIT */;
   ecl_function_dispatch(cl_env_copy,VV[45])(1, _ecl_static_9) /*  WT-NL */;
   ecl_function_dispatch(cl_env_copy,VV[49])(1, v3body) /*  C2EXPR    */;
   ecl_function_dispatch(cl_env_copy,VV[50])(1, _ecl_static_10) /*  WT */;
   ecl_bds_unwind1(cl_env_copy);
   if (Null(ecl_function_dispatch(cl_env_copy,VV[33])(1, v2blk) /*  BLK-REF-CCB */)) { goto L26; }
   cl_set(VV[16],ecl_minus(ecl_symbol_value(VV[16]),ecl_make_fixnum(1)));
L26:;
   value0 = ecl_function_dispatch(cl_env_copy,VV[51])(0) /*  WT-NL-CLOSE-BRACE */;
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
L1:;
  {
   cl_object v5;
   v5 = ecl_symbol_value(VV[9]);
   ecl_structure_set(v2blk,VV[10],5,v5);
  }
  {
   cl_object v5;
   v5 = ecl_symbol_value(VV[11]);
   ecl_structure_set(v2blk,VV[10],6,v5);
  }
  value0 = ecl_function_dispatch(cl_env_copy,VV[49])(1, v3body) /*  C2EXPR */;
  return value0;
 }
}
/*	function definition for C1RETURN-FROM                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3c1return_from(cl_object v1args)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_function_dispatch(cl_env_copy,VV[26])(4, ECL_SYM("RETURN-FROM",725), v1args, ecl_make_fixnum(1), ecl_make_fixnum(2)) /*  CHECK-ARGS-NUMBER */;
  {
   cl_object v2name;
   v2name = ecl_car(v1args);
   if (ECL_SYMBOLP(v2name)) { goto L3; }
   ecl_function_dispatch(cl_env_copy,VV[27])(2, _ecl_static_1, v2name) /*  CMPERR */;
L3:;
   {
    cl_object v4;                                 /*  BLK             */
    cl_object v5;                                 /*  CCB             */
    cl_object v6;                                 /*  CLB             */
    cl_object v7;                                 /*  UNW             */
    value0 = ecl_function_dispatch(cl_env_copy,VV[53])(1, v2name) /*  CMP-ENV-SEARCH-BLOCK */;
    v4 = value0;
    {
     const int v8 = cl_env_copy->nvalues;
     cl_object v9;
     v9 = (v8<=1)? ECL_NIL : cl_env_copy->values[1];
     v5 = v9;
     v9 = (v8<=2)? ECL_NIL : cl_env_copy->values[2];
     v6 = v9;
     v9 = (v8<=3)? ECL_NIL : cl_env_copy->values[3];
     v7 = v9;
    }
    if ((v4)!=ECL_NIL) { goto L6; }
    ecl_function_dispatch(cl_env_copy,VV[27])(2, _ecl_static_11, v2name) /*  CMPERR */;
L6:;
    {
     cl_object v8val;
     cl_object v9var;
     cl_object v10type;
     T0 = ecl_cadr(v1args);
     v8val = ecl_function_dispatch(cl_env_copy,VV[54])(1, T0) /*  C1EXPR */;
     v9var = ECL_NIL;
     v10type = ECL_T;
     if (Null(v5)) { goto L12; }
     ecl_structure_set(v4,VV[10],2,ECL_T);
     v10type = VV[18];
     v9var = ecl_function_dispatch(cl_env_copy,VV[41])(1, v4) /*  BLK-VAR */;
     ecl_structure_set(v9var,VV[12],6,VV[19]);
     ecl_structure_set(v9var,VV[12],2,ECL_T);
     goto L11;
L12:;
     if (Null(v6)) { goto L20; }
     ecl_structure_set(v4,VV[10],3,ECL_T);
     v10type = VV[20];
     v9var = ecl_function_dispatch(cl_env_copy,VV[41])(1, v4) /*  BLK-VAR */;
     goto L11;
L20:;
     if (Null(v7)) { goto L11; }
     v10type = ECL_SYM("UNWIND-PROTECT",888);
     v9var = ecl_function_dispatch(cl_env_copy,VV[41])(1, v4) /*  BLK-VAR */;
L11:;
     {
      cl_object v11;
      T0 = ecl_function_dispatch(cl_env_copy,VV[35])(1, v4) /*  BLK-REF */;
      v11 = ecl_plus(T0,ecl_make_fixnum(1));
      ecl_structure_set(v4,VV[10],1,v11);
     }
     {
      cl_object v11;
      T0 = ecl_function_dispatch(cl_env_copy,VV[36])(1, v4) /*  BLK-TYPE */;
      T1 = ecl_function_dispatch(cl_env_copy,VV[37])(1, v8val) /*  C1FORM-TYPE */;
      v11 = ecl_function_dispatch(cl_env_copy,VV[38])(2, T0, T1) /*  VALUES-TYPE-OR */;
      ecl_structure_set(v4,VV[10],8,v11);
     }
     {
      cl_object v11output;
      v11output = ecl_function_dispatch(cl_env_copy,VV[39])(8, ECL_SYM("RETURN-FROM",725), ECL_SYM("TYPE",1318), ECL_T, VV[6], v4, v10type, v8val, v9var) /*  MAKE-C1FORM* */;
      if (Null(v9var)) { goto L35; }
      ecl_function_dispatch(cl_env_copy,VV[55])(2, v9var, v11output) /*  ADD-TO-READ-NODES */;
L35:;
      value0 = v11output;
      cl_env_copy->nvalues = 1;
      return value0;
     }
    }
   }
  }
 }
}
/*	function definition for C2RETURN-FROM                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4c2return_from(cl_object v1c1form, cl_object v2blk, cl_object v3type, cl_object v4val, cl_object v5var)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!((v3type)==(VV[18]))) { goto L1; }
  ecl_bds_bind(cl_env_copy,VV[11],ECL_SYM("VALUES",895)); /*  *DESTINATION* */
  ecl_function_dispatch(cl_env_copy,VV[57])(1, v4val) /*  C2EXPR*     */;
  ecl_bds_unwind1(cl_env_copy);
  T0 = ecl_function_dispatch(cl_env_copy,VV[41])(1, v2blk) /*  BLK-VAR */;
  T1 = ecl_function_dispatch(cl_env_copy,VV[58])(1, v2blk) /*  BLK-NAME */;
  T2 = ecl_function_dispatch(cl_env_copy,VV[59])(1, T1) /*  ADD-SYMBOL */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[45])(5, _ecl_static_12, T0, _ecl_static_13, T2, _ecl_static_14) /*  WT-NL */;
  return value0;
L1:;
  if (!((v3type)==(VV[20]))) { goto L9; }
  goto L6;
  goto L7;
L9:;
  goto L7;
L7:;
  if (!((v3type)==(ECL_SYM("UNWIND-PROTECT",888)))) { goto L4; }
  goto L5;
L6:;
L5:;
  ecl_bds_bind(cl_env_copy,VV[11],ECL_SYM("VALUES",895)); /*  *DESTINATION* */
  ecl_function_dispatch(cl_env_copy,VV[57])(1, v4val) /*  C2EXPR*     */;
  ecl_bds_unwind1(cl_env_copy);
  T0 = ecl_function_dispatch(cl_env_copy,VV[41])(1, v2blk) /*  BLK-VAR */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[45])(3, _ecl_static_12, T0, _ecl_static_15) /*  WT-NL */;
  return value0;
L4:;
  {
   cl_object v6;
   cl_object v7;
   v6 = ecl_function_dispatch(cl_env_copy,VV[60])(1, v2blk) /*  BLK-DESTINATION */;
   v7 = ecl_function_dispatch(cl_env_copy,VV[61])(1, v2blk) /*  BLK-EXIT */;
   ecl_bds_bind(cl_env_copy,VV[11],v6);           /*  *DESTINATION*   */
   ecl_bds_bind(cl_env_copy,VV[9],v7);            /*  *EXIT*          */
   value0 = ecl_function_dispatch(cl_env_copy,VV[49])(1, v4val) /*  C2EXPR */;
   ecl_bds_unwind1(cl_env_copy);
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
 }
}

#include "cmp/cmpblock.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclIWYFSXJFmUup9_xpxTOE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPBLOCK.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclIWYFSXJFmUup9_xpxTOE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[25]);                           /*  C1BLOCK         */
 ecl_cmp_defun(VV[40]);                           /*  C2BLOCK         */
 ecl_cmp_defun(VV[52]);                           /*  C1RETURN-FROM   */
 ecl_cmp_defun(VV[56]);                           /*  C2RETURN-FROM   */
}
