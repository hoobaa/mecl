/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;PROCLAMATIONS.LSP                             */
#include <ecl/ecl-cmp.h>
#include "cmp/proclamations.eclh"
/*	function definition for PARSE-FUNCTION-PROCLAMATION           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1parse_function_proclamation(cl_narg narg, cl_object v1name, cl_object v2arg_types, cl_object v3return_type, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 {
  cl_object v4properties;
  ecl_va_list args; ecl_va_start(args,v3return_type,narg,3);
  v4properties = cl_grab_rest_args(args);
  ecl_va_end(args);
  if (Null(si_get_sysprop(v1name, VV[0]))) { goto L1; }
  (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(2, _ecl_static_1, v1name) /*  WARN */;
L1:;
  T0 = cl_list(2, v2arg_types, v3return_type);
  ecl_function_dispatch(cl_env_copy,VV[43])(2, v1name, T0) /*  PROCLAIM-FUNCTION */;
  {
   cl_object v5p;
   cl_object v6;
   v5p = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v4properties))) FEtype_error_list(v4properties);
   v6 = v4properties;
L7:;
   if (!(ecl_endp(v6))) { goto L9; }
   goto L8;
L9:;
   v5p = _ecl_car(v6);
   {
    cl_object v7;
    v7 = _ecl_cdr(v6);
    if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
    v6 = v7;
   }
   if (!(ecl_eql(v5p,VV[1]))) { goto L18; }
   si_put_sysprop(v1name, VV[2], ECL_T);
   goto L17;
L18:;
   if (!(ecl_eql(v5p,ECL_SYM("PREDICATE",1287)))) { goto L25; }
   goto L22;
   goto L23;
L25:;
   goto L23;
L23:;
   if (!(ecl_eql(v5p,VV[4]))) { goto L20; }
   goto L21;
L22:;
L21:;
   si_put_sysprop(v1name, VV[6], ECL_T);
   si_put_sysprop(v1name, VV[7], ECL_T);
   goto L17;
L20:;
   if (!(ecl_eql(v5p,VV[8]))) { goto L34; }
   goto L31;
   goto L32;
L34:;
   goto L32;
L32:;
   if (!(ecl_eql(v5p,ECL_SYM("READER",1006)))) { goto L29; }
   goto L30;
L31:;
L30:;
   si_put_sysprop(v1name, VV[7], ECL_T);
   goto L17;
L29:;
   cl_error(3, _ecl_static_2, v5p, v1name);
L17:;
   goto L7;
L8:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}

#include "cmp/proclamations.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclsqrgy6Iu8B5n9_2dstVE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;PROCLAMATIONS.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclsqrgy6Iu8B5n9_2dstVE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[42]);                           /*  PARSE-FUNCTION-PROCLAMATION */
 si_do_deftype(3, VV[12], VVtemp[0], VVtemp[1]);
 si_do_deftype(3, VV[13], VVtemp[2], VVtemp[3]);
 si_do_deftype(3, VV[14], VVtemp[4], ECL_SYM("LIST",481));
 si_do_deftype(3, VV[15], VVtemp[5], VVtemp[6]);
 si_do_deftype(3, VV[16], VVtemp[7], VVtemp[8]);
 si_do_deftype(3, VV[17], VVtemp[9], VVtemp[10]);
 si_do_deftype(3, VV[18], VVtemp[11], VVtemp[12]);
 si_do_deftype(3, VV[19], VVtemp[13], ECL_SYM("LIST",481));
 si_do_deftype(3, VV[20], VVtemp[14], VVtemp[15]);
 si_do_deftype(3, VV[21], VVtemp[16], ECL_SYM("LIST",481));
 si_do_deftype(3, VV[22], VVtemp[17], ECL_T);
 si_do_deftype(3, VV[23], VVtemp[18], VVtemp[19]);
 si_do_deftype(3, VV[24], VVtemp[20], VVtemp[21]);
 si_do_deftype(3, VV[25], VVtemp[22], VVtemp[23]);
 si_do_deftype(3, VV[26], VVtemp[24], ECL_T);
 si_do_deftype(3, ECL_SYM("INTEGER-LENGTH",439), VVtemp[25], ECL_SYM("ARRAY-INDEX",1771));
 si_do_deftype(3, VV[27], VVtemp[26], VVtemp[27]);
 si_do_deftype(3, VV[28], VVtemp[28], VVtemp[29]);
 si_do_deftype(3, VV[29], VVtemp[30], VVtemp[31]);
 si_do_deftype(3, ECL_SYM("PATHNAME-DEVICE",631), VVtemp[32], VVtemp[33]);
 si_do_deftype(3, ECL_SYM("PATHNAME-DIRECTORY",632), VVtemp[34], VVtemp[35]);
 si_do_deftype(3, ECL_SYM("PATHNAME-HOST",633), VVtemp[36], VVtemp[37]);
 si_do_deftype(3, ECL_SYM("PATHNAME-NAME",635), VVtemp[38], VVtemp[39]);
 si_do_deftype(3, ECL_SYM("PATHNAME-TYPE",636), VVtemp[40], VVtemp[39]);
 si_do_deftype(3, ECL_SYM("PATHNAME-VERSION",637), VVtemp[41], VVtemp[42]);
 si_do_deftype(3, VV[30], VVtemp[43], ECL_SYM("LIST",481));
 si_do_deftype(3, VV[31], VVtemp[44], ECL_SYM("LIST",481));
 si_do_deftype(3, VV[32], VVtemp[45], VVtemp[46]);
 si_do_deftype(3, VV[33], VVtemp[47], VVtemp[48]);
 si_do_deftype(3, VV[34], VVtemp[49], VVtemp[50]);
 si_do_deftype(3, VV[35], VVtemp[51], VVtemp[52]);
 si_do_deftype(3, VV[36], VVtemp[53], VVtemp[54]);
 si_do_deftype(3, VV[37], VVtemp[55], VVtemp[56]);
 si_do_deftype(3, VV[38], VVtemp[57], ECL_T);
 si_do_deftype(3, VV[39], VVtemp[58], VVtemp[59]);
 si_do_deftype(3, VV[40], VVtemp[60], ECL_SYM("UNSIGNED-BYTE",885));
 si_do_deftype(3, VV[41], VVtemp[61], ECL_T);
 si_do_deftype(3, ECL_SYM("INSTANCE",1342), VVtemp[62], ECL_SYM("STANDARD-OBJECT",976));
 {
  cl_object T0;
 {
  cl_object v1i;
  cl_object v2;
  v1i = ECL_NIL;
  if (ecl_unlikely(!ECL_LISTP(VVtemp[63]))) FEtype_error_list(VVtemp[63]);
  v2 = VVtemp[63];
L49:;
  v1i = _ecl_car(v2);
  {
   cl_object v3;
   v3 = _ecl_cdr(v2);
   if (ecl_unlikely(!ECL_LISTP(v3))) FEtype_error_list(v3);
   v2 = v3;
  }
  T0 = ecl_fdefinition(VV[11]);
  cl_apply(2, T0, v1i);
  if (!(ecl_endp(v2))) { goto L59; }
  goto L50;
L59:;
  goto L49;
L50:;
 }
 }
}
