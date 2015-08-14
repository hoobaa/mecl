/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPBIND.LSP                                   */
#include <ecl/ecl-cmp.h>
#include "cmp/cmpbind.eclh"
/*	function definition for BIND                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1bind(cl_object v1loc, cl_object v2var)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_function_dispatch(cl_env_copy,VV[21])(1, v2var) /*  VAR-KIND */;
   if (!((v3)==(VV[0]))) { goto L2; }
   {
    cl_object v4var_loc;
    v4var_loc = ecl_function_dispatch(cl_env_copy,VV[22])(1, v2var) /*  VAR-LOC */;
    if (ECL_FIXNUMP(v4var_loc)) { goto L5; }
    v4var_loc = ecl_function_dispatch(cl_env_copy,VV[23])(0) /*  NEXT-ENV */;
    ecl_structure_set(v2var,VV[1],10,v4var_loc);
L5:;
    if (!(ecl_zerop(v4var_loc))) { goto L9; }
    ecl_function_dispatch(cl_env_copy,VV[24])(3, _ecl_static_1, ecl_symbol_value(VV[2]), _ecl_static_2) /*  WT-NL */;
L9:;
    ecl_function_dispatch(cl_env_copy,VV[24])(5, _ecl_static_3, v4var_loc, _ecl_static_4, ecl_symbol_value(VV[2]), _ecl_static_5) /*  WT-NL */;
    ecl_function_dispatch(cl_env_copy,VV[25])(2, ECL_SYM("OBJECT",1278), v1loc) /*  WT-COERCE-LOC */;
    ecl_function_dispatch(cl_env_copy,VV[26])(3, _ecl_static_6, ecl_symbol_value(VV[2]), _ecl_static_7) /*  WT */;
    T0 = ecl_function_dispatch(cl_env_copy,VV[27])(1, v2var) /*  VAR-NAME */;
    value0 = ecl_function_dispatch(cl_env_copy,VV[28])(1, T0) /*  WT-COMMENT */;
    return value0;
   }
L2:;
   if (!((v3)==(VV[3]))) { goto L14; }
   {
    cl_object v5var_loc;
    v5var_loc = ecl_function_dispatch(cl_env_copy,VV[22])(1, v2var) /*  VAR-LOC */;
    if (ECL_CONSP(v5var_loc)) { goto L18; }
    v5var_loc = ecl_function_dispatch(cl_env_copy,VV[29])(0) /*  NEXT-LEX */;
    ecl_structure_set(v2var,VV[1],10,v5var_loc);
L18:;
    ecl_function_dispatch(cl_env_copy,VV[24])(0)  /*  WT-NL           */;
    ecl_function_dispatch(cl_env_copy,VV[30])(1, v5var_loc) /*  WT-LEX */;
    ecl_function_dispatch(cl_env_copy,VV[26])(1, _ecl_static_8) /*  WT */;
    ecl_function_dispatch(cl_env_copy,VV[25])(2, ECL_SYM("OBJECT",1278), v1loc) /*  WT-COERCE-LOC */;
    ecl_function_dispatch(cl_env_copy,VV[26])(1, _ecl_static_9) /*  WT */;
   }
   T0 = ecl_function_dispatch(cl_env_copy,VV[27])(1, v2var) /*  VAR-NAME */;
   value0 = ecl_function_dispatch(cl_env_copy,VV[28])(1, T0) /*  WT-COMMENT */;
   return value0;
L14:;
   if (!((v3)==(ECL_SYM("SPECIAL",789)))) { goto L31; }
   goto L28;
   goto L29;
L31:;
   goto L29;
L29:;
   if (!((v3)==(VV[5]))) { goto L26; }
   goto L27;
L28:;
L27:;
   value0 = L3bds_bind(v1loc, v2var);
   return value0;
L26:;
   T0 = ecl_function_dispatch(cl_env_copy,VV[22])(1, v2var) /*  VAR-LOC */;
   if ((T0)==(ECL_SYM("OBJECT",2014))) { goto L34; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[22])(1, v2var) /*  VAR-LOC */;
   if (ecl_equal(T0,v1loc)) { goto L36; }
   ecl_function_dispatch(cl_env_copy,VV[24])(2, v2var, _ecl_static_8) /*  WT-NL */;
   T0 = ecl_function_dispatch(cl_env_copy,VV[31])(1, v2var) /*  VAR-REP-TYPE */;
   ecl_function_dispatch(cl_env_copy,VV[25])(2, T0, v1loc) /*  WT-COERCE-LOC */;
   value0 = ecl_function_dispatch(cl_env_copy,VV[26])(1, _ecl_static_9) /*  WT */;
   return value0;
L36:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L34:;
   if (!(ECL_CONSP(v1loc))) { goto L40; }
   T0 = ecl_car(v1loc);
   if (!((T0)==(VV[7]))) { goto L40; }
   value0 = ecl_structure_set(v2var,VV[1],10,v1loc);
   cl_env_copy->nvalues = 1;
   return value0;
L40:;
   value0 = ecl_function_dispatch(cl_env_copy,VV[32])(0) /*  BABOON   */;
   return value0;
  }
 }
}
/*	function definition for BIND-INIT                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2bind_init(cl_object v1form, cl_object v2var)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3kind;
   v3kind = ecl_function_dispatch(cl_env_copy,VV[21])(1, v2var) /*  VAR-KIND */;
   if (!((v3kind)==(VV[0]))) { goto L7; }
   goto L4;
   goto L5;
L7:;
   goto L5;
L5:;
   if (!((v3kind)==(VV[3]))) { goto L11; }
   goto L4;
   goto L9;
L11:;
   goto L9;
L9:;
   if (!((v3kind)==(ECL_SYM("SPECIAL",789)))) { goto L15; }
   goto L4;
   goto L13;
L15:;
   goto L13;
L13:;
   if (!((v3kind)==(VV[5]))) { goto L2; }
   goto L3;
L4:;
L3:;
   {
    cl_object v4locs;
    ecl_bds_bind(cl_env_copy,VV[11],ecl_make_fixnum(0)); /*  *INLINE-BLOCKS* */
    ecl_bds_push(cl_env_copy,VV[12]);             /*  *TEMP*          */
    T0 = ecl_list1(v1form);
    T1 = ecl_function_dispatch(cl_env_copy,VV[34])(1, T0) /*  INLINE-ARGS */;
    v4locs = ecl_function_dispatch(cl_env_copy,VV[35])(1, T1) /*  COERCE-LOCS */;
    T0 = ecl_car(v4locs);
    L1bind(T0, v2var);
    value0 = ecl_function_dispatch(cl_env_copy,VV[36])(0) /*  CLOSE-INLINE-BLOCKS */;
    ecl_bds_unwind1(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    return value0;
   }
L2:;
   T0 = cl_list(2, VV[8], v2var);
   ecl_bds_bind(cl_env_copy,VV[13],T0);           /*  *DESTINATION*   */
   value0 = ecl_function_dispatch(cl_env_copy,VV[37])(1, v1form) /*  C2EXPR* */;
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
 }
}
/*	function definition for BDS-BIND                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3bds_bind(cl_object v1loc, cl_object v2var)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[39])(1, v1loc) /*  VAR-P */)) { goto L2; }
  {
   cl_object v3;
   v3 = ecl_function_dispatch(cl_env_copy,VV[21])(1, v1loc) /*  VAR-KIND */;
   if (!((v3)==(VV[5]))) { goto L10; }
   goto L7;
   goto L8;
L10:;
   goto L8;
L8:;
   if (!((v3)==(ECL_SYM("SPECIAL",789)))) { goto L2; }
   goto L5;
L7:;
  }
L5:;
  T0 = ecl_function_dispatch(cl_env_copy,VV[27])(1, v1loc) /*  VAR-NAME */;
  T1 = ecl_function_dispatch(cl_env_copy,VV[27])(1, v2var) /*  VAR-NAME */;
  if (!((T0)==(T1))) { goto L2; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[22])(1, v2var) /*  VAR-LOC */;
  ecl_function_dispatch(cl_env_copy,VV[24])(3, _ecl_static_10, T0, _ecl_static_7) /*  WT-NL */;
  goto L1;
L2:;
  T0 = ecl_function_dispatch(cl_env_copy,VV[22])(1, v2var) /*  VAR-LOC */;
  ecl_function_dispatch(cl_env_copy,VV[24])(3, _ecl_static_11, T0, _ecl_static_12) /*  WT-NL */;
  ecl_function_dispatch(cl_env_copy,VV[25])(2, ECL_SYM("OBJECT",1278), v1loc) /*  WT-COERCE-LOC */;
  ecl_function_dispatch(cl_env_copy,VV[26])(1, _ecl_static_7) /*  WT  */;
L1:;
  cl_set(VV[17],CONS(VV[18],ecl_symbol_value(VV[17])));
  T0 = ecl_function_dispatch(cl_env_copy,VV[27])(1, v2var) /*  VAR-NAME */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[28])(1, T0) /*  WT-COMMENT */;
  return value0;
 }
}

#include "cmp/cmpbind.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecloozRJZ1P8VNk9_OUptVE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPBIND.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_ecloozRJZ1P8VNk9_OUptVE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[20]);                           /*  BIND            */
 ecl_cmp_defun(VV[33]);                           /*  BIND-INIT       */
 ecl_cmp_defun(VV[38]);                           /*  BDS-BIND        */
}
