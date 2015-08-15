/*	Compiler: ECL 12.12.1                                         */
/*	Source: EXT:QUICKLISP;ECL-QUICKLISP.LISP                      */
#include <ecl/ecl-cmp.h>
#include "ext/ecl-quicklisp.eclh"
/*	function definition for SAFE-DOWNLOAD                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2safe_download(cl_object volatile v1url, cl_object volatile v2filename)
{
 cl_object T0, T1, T2, T3;
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  cl_ensure_directories_exist(1, v2filename);
  {
   volatile cl_object env1 = env0;
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(ECL_NIL,env1);
   {
    volatile cl_object env2 = env1;
    CLV1 = env2 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env2); /*  TAGBODY */
    if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV1))) {
    if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L3;
    ecl_internal_error("GO found an inexistent tag");
    }
    {cl_object v3;
     v3 = ECL_NIL;
     v3 = ecl_make_cclosure_va((cl_objectfn)LC1__g3,env2,Cblock);
     T0 = v3;
    }
    T1 = CONS(VV[4],T0);
    T2 = ecl_list1(T1);
    T3 = CONS(T2,ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5)));
    ecl_bds_bind(cl_env_copy,ECL_SYM("*HANDLER-CLUSTERS*",5),T3); /*  *HANDLER-CLUSTERS* */
    ecl_function_dispatch(cl_env_copy,VV[9])(2, v1url, v2filename) /*  DOWNLOAD-URL-TO-FILE */;
    ecl_frs_pop(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    goto L2;
L3:;
    cl_format(2, ECL_T, _ecl_static_4);
    si_quit(1, ecl_make_fixnum(1));
    ecl_frs_pop(cl_env_copy);
    goto L2;
   }
  }
L2:;
  value0 = v2filename;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	closure G3                                                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC1__g3(cl_narg narg, cl_object v1si__temp, ...)
{
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  TAGBODY         */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  ECL_CONS_CAR(CLV0) = v1si__temp;
  cl_go(ECL_CONS_CAR(CLV1),ecl_make_fixnum(0));
 }
 }
}
/*	function definition for INSTALL-QUICKLISP                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3install_quicklisp(cl_object v1target_directory)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2file;
   v2file = cl_merge_pathnames(2, _ecl_static_5, v1target_directory);
   cl_ensure_directories_exist(1, v2file);
   ecl_function_dispatch(cl_env_copy,VV[9])(2, ecl_symbol_value(VV[1]), v2file) /*  DOWNLOAD-URL-TO-FILE */;
   cl_load(1, v2file);
   T0 = cl_truename(v1target_directory);
   T1 = cl_namestring(T0);
   T2 = cl_format(3, ECL_NIL, _ecl_static_6, T1);
   T3 = cl_read_from_string(1, T2);
   value0 = cl_eval(T3);
   return value0;
  }
 }
}
/*	closure G7                                                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC4__g7(cl_narg narg, cl_object v1si__temp, ...)
{
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  TAGBODY         */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  ECL_CONS_CAR(CLV0) = v1si__temp;
  cl_go(ECL_CONS_CAR(CLV1),ecl_make_fixnum(0));
 }
 }
}

#include "ext/ecl-quicklisp.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecloDJKBvySQGSo9_MN0lfE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("EXT:QUICKLISP;ECL-QUICKLISP.LISP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_ecloDJKBvySQGSo9_MN0lfE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 ecl_function_dispatch(cl_env_copy,VV[7])(10, _ecl_static_0, ECL_NIL, ECL_NIL, VVtemp[0], ECL_NIL, ECL_NIL, ECL_NIL, ECL_NIL, ECL_NIL, ECL_NIL) /*  DODEFPACKAGE */;
 si_select_package(_ecl_static_0);
 cl_require(1, VV[0]);
 si_Xmake_special(VV[1]);
 cl_set(VV[1],_ecl_static_1);
 si_Xmake_special(VV[2]);
 cl_set(VV[2],cl_translate_logical_pathname(1, _ecl_static_2));
 si_Xmake_special(VV[3]);
 cl_set(VV[3],_ecl_static_3);
 ecl_cmp_defun(VV[8]);                            /*  SAFE-DOWNLOAD   */
 ecl_cmp_defun(VV[10]);                           /*  INSTALL-QUICKLISP */
 {
  cl_object T0, T1, T2, T3;
  cl_object  volatile env0;
  cl_object  volatile CLV0, CLV1
  ;
 {
  volatile cl_object env1 = env0;
  env1 = ECL_NIL;
  CLV0 = env1 = CONS(ECL_NIL,env1);
  {
   volatile cl_object env2 = env1;
   CLV1 = env2 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env2); /*  TAGBODY */
   if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV1))) {
   if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L31;
   ecl_internal_error("GO found an inexistent tag");
   }
   {cl_object v1;
    v1 = ECL_NIL;
    v1 = ecl_make_cclosure_va((cl_objectfn)LC4__g7,env2,Cblock);
    T0 = v1;
   }
   T1 = CONS(ECL_SYM("ERROR",337),T0);
   T2 = ecl_list1(T1);
   T3 = CONS(T2,ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5)));
   ecl_bds_bind(cl_env_copy,ECL_SYM("*HANDLER-CLUSTERS*",5),T3); /*  *HANDLER-CLUSTERS* */
   if ((cl_probe_file(ecl_symbol_value(VV[3])))!=ECL_NIL) { goto L34; }
   L3install_quicklisp(ecl_symbol_value(VV[2]));
L34:;
   if ((cl_find_package(_ecl_static_7))!=ECL_NIL) { goto L36; }
   cl_load(1, ecl_symbol_value(VV[3]));
L36:;
   T0 = cl_read_from_string(1, _ecl_static_8);
   cl_eval(T0);
   ecl_frs_pop(cl_env_copy);
   ecl_bds_unwind1(cl_env_copy);
   goto L30;
L31:;
   {
    cl_object v1c;
    v1c = ECL_CONS_CAR(CLV0);
    cl_format(3, ECL_T, _ecl_static_9, v1c);
    ecl_frs_pop(cl_env_copy);
    goto L30;
   }
  }
 }
L30:;
 }
 cl_provide(_ecl_static_10);
}
