/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPTYPES.LSP                                  */
#include <ecl/ecl-cmp.h>
#include "cmp/cmptypes.eclh"
/*	function definition for MAKE-REF                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1make_ref(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1;
  cl_object v2;
  cl_object v3;
  cl_object v4;
  cl_object v5;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  {
   cl_object keyvars[10];
   cl_parse_key(args,5,L1make_refkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v1 = keyvars[0];
   if (Null(keyvars[6])) {
    v2 = ecl_make_fixnum(0);
   } else {
    v2 = keyvars[1];
   }
   v3 = keyvars[2];
   v4 = keyvars[3];
   v5 = keyvars[4];
  }
  if (ECL_FIXNUMP(v2)) { goto L2; }
  si_structure_type_error(4, v2, ECL_SYM("FIXNUM",372), VV[0], VV[0]);
L2:;
  value0 = si_make_structure(6, VV[4], v1, v2, v3, v4, v5);
  return value0;
 }
}
/*	local function OBJECT                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC2object()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = VV[6];
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for %MAKE-VAR                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3_make_var(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1;
  cl_object v2;
  cl_object v3;
  cl_object v4;
  cl_object v5;
  cl_object v6;
  cl_object v7;
  cl_object v8;
  cl_object v9;
  cl_object v10;
  cl_object v11;
  cl_object v12;
  cl_object v13;
  cl_object v14;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  {
   cl_object keyvars[28];
   cl_parse_key(args,14,L3_make_varkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v1 = keyvars[0];
   if (Null(keyvars[15])) {
    v2 = ecl_make_fixnum(0);
   } else {
    v2 = keyvars[1];
   }
   v3 = keyvars[2];
   v4 = keyvars[3];
   v5 = keyvars[4];
   v6 = keyvars[5];
   v7 = keyvars[6];
   if (Null(keyvars[21])) {
    v8 = ecl_symbol_value(VV[11]);
   } else {
    v8 = keyvars[7];
   }
   v9 = keyvars[8];
   v10 = keyvars[9];
   if (Null(keyvars[24])) {
    v11 = ECL_SYM("OBJECT",2014);
   } else {
    v11 = keyvars[10];
   }
   if (Null(keyvars[25])) {
    v12 = ECL_T;
   } else {
    v12 = keyvars[11];
   }
   if (Null(keyvars[26])) {
    v13 = ecl_make_fixnum(-1);
   } else {
    v13 = keyvars[12];
   }
   v14 = keyvars[13];
  }
  if (ECL_FIXNUMP(v2)) { goto L6; }
  si_structure_type_error(4, v2, ECL_SYM("FIXNUM",372), VV[7], VV[0]);
L6:;
  value0 = si_make_structure(15, VV[12], v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14);
  return value0;
 }
}
/*	function definition for MAKE-FUN                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4make_fun(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1;
  cl_object v2;
  cl_object v3;
  cl_object v4;
  cl_object v5;
  cl_object v6;
  cl_object v7;
  cl_object v8;
  cl_object v9;
  cl_object v10;
  cl_object v11;
  cl_object v12;
  cl_object v13;
  cl_object v14;
  cl_object v15;
  cl_object v16;
  cl_object v17;
  cl_object v18;
  cl_object v19;
  cl_object v20;
  cl_object v21;
  cl_object v22;
  cl_object v23;
  cl_object v24;
  cl_object v25;
  cl_object v26;
  cl_object v27;
  cl_object v28;
  cl_object v29;
  cl_object v30;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  {
   cl_object keyvars[60];
   cl_parse_key(args,30,L4make_funkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v1 = keyvars[0];
   if (Null(keyvars[31])) {
    v2 = ecl_make_fixnum(0);
   } else {
    v2 = keyvars[1];
   }
   v3 = keyvars[2];
   v4 = keyvars[3];
   v5 = keyvars[4];
   v6 = keyvars[5];
   if (Null(keyvars[36])) {
    v7 = ecl_make_fixnum(0);
   } else {
    v7 = keyvars[6];
   }
   if (Null(keyvars[37])) {
    v8 = ecl_make_fixnum(0);
   } else {
    v8 = keyvars[7];
   }
   v9 = keyvars[8];
   v10 = keyvars[9];
   v11 = keyvars[10];
   v12 = keyvars[11];
   v13 = keyvars[12];
   v14 = keyvars[13];
   v15 = keyvars[14];
   v16 = keyvars[15];
   v17 = keyvars[16];
   if (Null(keyvars[47])) {
    v18 = ecl_make_fixnum(0);
   } else {
    v18 = keyvars[17];
   }
   if (Null(keyvars[48])) {
    v19 = ecl_make_fixnum(65536);
   } else {
    v19 = keyvars[18];
   }
   if (Null(keyvars[49])) {
    v20 = VV[17];
   } else {
    v20 = keyvars[19];
   }
   if (Null(keyvars[50])) {
    v21 = ecl_symbol_value(VV[11]);
   } else {
    v21 = keyvars[20];
   }
   v22 = keyvars[21];
   v23 = keyvars[22];
   v24 = keyvars[23];
   v25 = keyvars[24];
   v26 = keyvars[25];
   if (Null(keyvars[56])) {
    v27 = ecl_car(ecl_symbol_value(ECL_SYM("*SOURCE-LOCATION*",1180)));
   } else {
    v27 = keyvars[26];
   }
   if (Null(keyvars[57])) {
    value0 = ecl_cdr(ecl_symbol_value(ECL_SYM("*SOURCE-LOCATION*",1180)));
    if ((value0)!=ECL_NIL) { goto L11; }
    v28 = ecl_symbol_value(VV[18]);
    goto L9;
L11:;
    v28 = value0;
    goto L9;
L9:;
   } else {
    v28 = keyvars[27];
   }
   if (Null(keyvars[58])) {
    v29 = ecl_function_dispatch(cl_env_copy,VV[74])(0) /*  CMP-ENV-COPY */;
   } else {
    v29 = keyvars[28];
   }
   v30 = keyvars[29];
  }
  if (ECL_FIXNUMP(v2)) { goto L14; }
  si_structure_type_error(4, v2, ECL_SYM("FIXNUM",372), VV[14], VV[0]);
L14:;
  value0 = si_make_structure(31, VV[19], v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30);
  return value0;
 }
}
/*	function definition for MAKE-BLK                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5make_blk(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1;
  cl_object v2;
  cl_object v3;
  cl_object v4;
  cl_object v5;
  cl_object v6;
  cl_object v7;
  cl_object v8;
  cl_object v9;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  {
   cl_object keyvars[18];
   cl_parse_key(args,9,L5make_blkkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v1 = keyvars[0];
   if (Null(keyvars[10])) {
    v2 = ecl_make_fixnum(0);
   } else {
    v2 = keyvars[1];
   }
   v3 = keyvars[2];
   v4 = keyvars[3];
   v5 = keyvars[4];
   v6 = keyvars[5];
   v7 = keyvars[6];
   v8 = keyvars[7];
   if (Null(keyvars[17])) {
    v9 = VV[17];
   } else {
    v9 = keyvars[8];
   }
  }
  if (ECL_FIXNUMP(v2)) { goto L3; }
  si_structure_type_error(4, v2, ECL_SYM("FIXNUM",372), VV[21], VV[0]);
L3:;
  value0 = si_make_structure(10, VV[24], v1, v2, v3, v4, v5, v6, v7, v8, v9);
  return value0;
 }
}
/*	function definition for MAKE-TAG                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6make_tag(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1;
  cl_object v2;
  cl_object v3;
  cl_object v4;
  cl_object v5;
  cl_object v6;
  cl_object v7;
  cl_object v8;
  cl_object v9;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  {
   cl_object keyvars[18];
   cl_parse_key(args,9,L6make_tagkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v1 = keyvars[0];
   if (Null(keyvars[10])) {
    v2 = ecl_make_fixnum(0);
   } else {
    v2 = keyvars[1];
   }
   v3 = keyvars[2];
   v4 = keyvars[3];
   v5 = keyvars[4];
   v6 = keyvars[5];
   v7 = keyvars[6];
   v8 = keyvars[7];
   v9 = keyvars[8];
  }
  if (ECL_FIXNUMP(v2)) { goto L2; }
  si_structure_type_error(4, v2, ECL_SYM("FIXNUM",372), VV[26], VV[0]);
L2:;
  value0 = si_make_structure(10, VV[29], v1, v2, v3, v4, v5, v6, v7, v8, v9);
  return value0;
 }
}
/*	function definition for MAKE-INFO                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7make_info(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1;
  cl_object v2;
  cl_object v3;
  cl_object v4;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  {
   cl_object keyvars[8];
   cl_parse_key(args,4,L7make_infokeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v1 = keyvars[0];
   if (Null(keyvars[5])) {
    v2 = VV[17];
   } else {
    v2 = keyvars[1];
   }
   v3 = keyvars[2];
   v4 = keyvars[3];
  }
  value0 = si_make_structure(5, VV[34], v1, v2, v3, v4);
  return value0;
 }
}
/*	function definition for MAKE-INLINE-INFO                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8make_inline_info(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1;
  cl_object v2;
  cl_object v3;
  cl_object v4;
  cl_object v5;
  cl_object v6;
  cl_object v7;
  cl_object v8;
  cl_object v9;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  {
   cl_object keyvars[18];
   cl_parse_key(args,9,L8make_inline_infokeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v1 = keyvars[0];
   v2 = keyvars[1];
   v3 = keyvars[2];
   v4 = keyvars[3];
   v5 = keyvars[4];
   v6 = keyvars[5];
   v7 = keyvars[6];
   v8 = keyvars[7];
   v9 = keyvars[8];
  }
  value0 = si_make_structure(10, VV[39], v1, v2, v3, v4, v5, v6, v7, v8, v9);
  return value0;
 }
}
/*	function definition for DO-MAKE-C1FORM                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L9do_make_c1form(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1;
  cl_object v2;
  cl_object v3;
  cl_object v4;
  cl_object v5;
  cl_object v6;
  cl_object v7;
  cl_object v8;
  cl_object v9;
  cl_object v10;
  cl_object v11;
  cl_object v12;
  cl_object v13;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  {
   cl_object keyvars[26];
   cl_parse_key(args,13,L9do_make_c1formkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v1 = keyvars[0];
   if (Null(keyvars[14])) {
    v2 = VV[17];
   } else {
    v2 = keyvars[1];
   }
   v3 = keyvars[2];
   v4 = keyvars[3];
   v5 = keyvars[4];
   v6 = keyvars[5];
   if (Null(keyvars[19])) {
    v7 = ecl_function_dispatch(cl_env_copy,VV[74])(0) /*  CMP-ENV-COPY */;
   } else {
    v7 = keyvars[6];
   }
   v8 = keyvars[7];
   v9 = keyvars[8];
   v10 = keyvars[9];
   v11 = keyvars[10];
   v12 = keyvars[11];
   if (Null(keyvars[25])) {
    v13 = ecl_make_fixnum(0);
   } else {
    v13 = keyvars[12];
   }
  }
  value0 = si_make_structure(14, VV[45], v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13);
  return value0;
 }
}
/*	function definition for MAKE-VV                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L10make_vv(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1;
  cl_object v2;
  cl_object v3;
  cl_object v4;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  {
   cl_object keyvars[8];
   cl_parse_key(args,4,L10make_vvkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v1 = keyvars[0];
   v2 = keyvars[1];
   if (Null(keyvars[6])) {
    v3 = ECL_T;
   } else {
    v3 = keyvars[2];
   }
   v4 = keyvars[3];
  }
  value0 = si_make_structure(5, VV[50], v1, v2, v3, v4);
  return value0;
 }
}

#include "cmp/cmptypes.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclvQz6Vt3TG0Tp9_MWotVE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPTYPES.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclvQz6Vt3TG0Tp9_MWotVE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 si_define_structure(15, VV[0], _ecl_static_1, ECL_NIL, ECL_NIL, VVtemp[0], VVtemp[1], VV[1], ECL_NIL, ECL_NIL, VV[2], VVtemp[2], ecl_make_fixnum(5), ECL_NIL, ECL_NIL, VV[3]);
 VV[4]= cl_find_class(1, VV[0]);
 ecl_cmp_defun(VV[52]);                           /*  MAKE-REF        */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC2object,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 si_do_deftype(3, ECL_SYM("OBJECT",2014), VVtemp[3], T0);
 }
 si_define_structure(15, VV[7], _ecl_static_2, ECL_NIL, ECL_NIL, VVtemp[4], VVtemp[5], VV[8], VV[0], ECL_NIL, VV[9], VVtemp[6], ecl_make_fixnum(14), ECL_NIL, ECL_NIL, VV[10]);
 VV[12]= cl_find_class(1, VV[7]);
 ecl_cmp_defun(VV[58]);                           /*  %MAKE-VAR       */
 si_define_structure(15, VV[14], _ecl_static_3, ECL_NIL, ECL_NIL, VVtemp[7], VVtemp[8], VV[15], VV[0], ECL_NIL, ECL_NIL, VVtemp[9], ecl_make_fixnum(30), ECL_NIL, ECL_NIL, VV[16]);
 VV[19]= cl_find_class(1, VV[14]);
 ecl_cmp_defun(VV[73]);                           /*  MAKE-FUN        */
 si_define_structure(15, VV[21], _ecl_static_4, ECL_NIL, ECL_NIL, VVtemp[10], VVtemp[11], VV[22], VV[0], ECL_NIL, ECL_NIL, VVtemp[12], ecl_make_fixnum(9), ECL_NIL, ECL_NIL, VV[23]);
 VV[24]= cl_find_class(1, VV[21]);
 ecl_cmp_defun(VV[105]);                          /*  MAKE-BLK        */
 si_define_structure(15, VV[26], _ecl_static_5, ECL_NIL, ECL_NIL, VVtemp[13], VVtemp[14], VV[27], VV[0], ECL_NIL, ECL_NIL, VVtemp[15], ecl_make_fixnum(9), ECL_NIL, ECL_NIL, VV[28]);
 VV[29]= cl_find_class(1, VV[26]);
 ecl_cmp_defun(VV[115]);                          /*  MAKE-TAG        */
 si_define_structure(15, VV[31], _ecl_static_6, ECL_NIL, ECL_NIL, VVtemp[16], VVtemp[17], VV[32], ECL_NIL, ECL_NIL, ECL_NIL, VVtemp[18], ecl_make_fixnum(4), ECL_NIL, ECL_NIL, VV[33]);
 VV[34]= cl_find_class(1, VV[31]);
 ecl_cmp_defun(VV[125]);                          /*  MAKE-INFO       */
 si_define_structure(15, VV[36], _ecl_static_7, ECL_NIL, ECL_NIL, VVtemp[19], VVtemp[20], VV[37], ECL_NIL, ECL_NIL, ECL_NIL, VVtemp[21], ecl_make_fixnum(9), ECL_NIL, ECL_NIL, VV[38]);
 VV[39]= cl_find_class(1, VV[36]);
 ecl_cmp_defun(VV[130]);                          /*  MAKE-INLINE-INFO */
 si_define_structure(15, VV[41], _ecl_static_8, ECL_NIL, ECL_NIL, VVtemp[22], VVtemp[23], VV[42], VV[31], ECL_NIL, VV[43], VVtemp[24], ecl_make_fixnum(13), ECL_NIL, ECL_NIL, VV[44]);
 VV[45]= cl_find_class(1, VV[41]);
 ecl_cmp_defun(VV[140]);                          /*  DO-MAKE-C1FORM  */
 si_define_structure(15, VV[47], _ecl_static_9, ECL_NIL, ECL_NIL, VVtemp[25], VVtemp[26], VV[48], ECL_NIL, ECL_NIL, ECL_NIL, VVtemp[27], ecl_make_fixnum(4), ECL_NIL, ECL_NIL, VV[49]);
 VV[50]= cl_find_class(1, VV[47]);
 ecl_cmp_defun(VV[154]);                          /*  MAKE-VV         */
}
