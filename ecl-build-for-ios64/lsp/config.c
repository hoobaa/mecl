/*	Compiler: ECL 12.12.1                                         */
/*	Source: BUILD:LSP;CONFIG.LSP                                  */
#include <ecl/ecl-cmp.h>
#include "lsp/config.eclh"
/*	function definition for UNAME                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1uname()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v1;
   {
	cl_object output;
	struct utsname aux;
	if (uname(&aux) < 0)
		output = ECL_NIL;
	else
		output = cl_list(5, make_base_string_copy(aux.sysname),
			    make_base_string_copy(aux.nodename),
			    make_base_string_copy(aux.release),
			    make_base_string_copy(aux.version),
			    make_base_string_copy(aux.machine));
	v1= output;
}
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for SHORT-SITE-NAME                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2short_site_name()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for LONG-SITE-NAME                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3long_site_name()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for LISP-IMPLEMENTATION-VERSION           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4lisp_implementation_version()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = _ecl_static_1;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for LISP-IMPLEMENTATION-VCS-ID            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5ext_lisp_implementation_vcs_id()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = _ecl_static_2;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for MACHINE-TYPE                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6machine_type()
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = si_getenv(_ecl_static_3);
  if ((value0)!=ECL_NIL) { goto L2; }
  T0 = L1uname();
  T1 = ecl_cddddr(T0);
  value0 = ecl_car(T1);
  if ((value0)!=ECL_NIL) { goto L2; }
  value0 = _ecl_static_4;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for MACHINE-INSTANCE                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7machine_instance()
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = si_getenv(_ecl_static_5);
  if ((value0)!=ECL_NIL) { goto L2; }
  T0 = L1uname();
  value0 = ecl_cadr(T0);
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for MACHINE-VERSION                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8machine_version()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for SOFTWARE-TYPE                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L9software_type()
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = L1uname();
  value0 = ecl_car(T0);
  if ((value0)!=ECL_NIL) { goto L2; }
  value0 = _ecl_static_6;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for SOFTWARE-VERSION                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L10software_version()
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = L1uname();
  value0 = ecl_caddr(T0);
  if ((value0)!=ECL_NIL) { goto L2; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}

#include "lsp/config.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclhzRMKAb7_W68xWE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("BUILD:LSP;CONFIG.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclhzRMKAb7_W68xWE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[11]);                           /*  UNAME           */
 ecl_cmp_defun(VV[12]);                           /*  SHORT-SITE-NAME */
 ecl_cmp_defun(VV[13]);                           /*  LONG-SITE-NAME  */
 ecl_cmp_defun(VV[14]);                           /*  LISP-IMPLEMENTATION-VERSION */
 ecl_cmp_defun(VV[15]);                           /*  LISP-IMPLEMENTATION-VCS-ID */
 ecl_cmp_defun(VV[16]);                           /*  MACHINE-TYPE    */
 ecl_cmp_defun(VV[17]);                           /*  MACHINE-INSTANCE */
 ecl_cmp_defun(VV[18]);                           /*  MACHINE-VERSION */
 cl_set(ECL_SYM("*FEATURES*",34),cl_adjoin(2, VV[8], ecl_symbol_value(ECL_SYM("*FEATURES*",34))));
 ecl_cmp_defun(VV[19]);                           /*  SOFTWARE-TYPE   */
 ecl_cmp_defun(VV[20]);                           /*  SOFTWARE-VERSION */
 si_pathname_translations(2, _ecl_static_7, VVtemp[0]);
 {
  cl_object T0, T1, T2;
 {
  cl_object v1x;
  v1x = ECL_NIL;
  {
   cl_object v2;
   v1x = si_getenv(_ecl_static_8);
   if (Null(v1x)) { goto L51; }
   v2 = cl_probe_file(v1x);
   goto L49;
L51:;
   v2 = ECL_NIL;
   goto L49;
L49:;
   if (Null(v2)) { goto L54; }
   goto L48;
L54:;
   {
    cl_object v3;
    v1x = si_getenv(_ecl_static_9);
    if (Null(v1x)) { goto L58; }
    v3 = cl_probe_file(v1x);
    goto L56;
L58:;
    v3 = ECL_NIL;
    goto L56;
L56:;
    if (Null(v3)) { goto L61; }
    goto L48;
L61:;
    {
     cl_object v4;
     v1x = si_getenv(_ecl_static_10);
     if (Null(v1x)) { goto L65; }
     v4 = cl_probe_file(v1x);
     goto L63;
L65:;
     v4 = ECL_NIL;
     goto L63;
L63:;
     if (Null(v4)) { goto L68; }
     goto L48;
L68:;
     v1x = _ecl_static_11;
    }
   }
  }
L48:;
  T0 = cl_format(3, ECL_NIL, _ecl_static_13, v1x);
  T1 = cl_list(2, _ecl_static_12, T0);
  T2 = ecl_list1(T1);
  si_pathname_translations(2, _ecl_static_10, T2);
 }
 }
 {
  cl_object T0, T1, T2;
 {
  cl_object v1path;
  v1path = si_get_library_pathname();
  if (Null(v1path)) { goto L71; }
  T0 = cl_merge_pathnames(2, _ecl_static_15, v1path);
  T1 = cl_list(2, _ecl_static_12, T0);
  T2 = ecl_list1(T1);
  si_pathname_translations(2, _ecl_static_14, T2);
 }
L71:;
 {
  cl_object v2x;
  v2x = si_getenv(_ecl_static_16);
  if (Null(v2x)) { goto L79; }
  v2x = cl_probe_file(v2x);
  if ((v2x)!=ECL_NIL) { goto L76; }
  goto L77;
L79:;
  goto L77;
L77:;
  v2x = VVtemp[1];
L76:;
  if (Null(v2x)) { goto L83; }
  T0 = cl_merge_pathnames(2, _ecl_static_15, v2x);
  T1 = cl_list(2, _ecl_static_12, T0);
  T2 = ecl_list1(T1);
  si_pathname_translations(2, _ecl_static_17, T2);
L83:;
  {
   cl_object v3path;
   v3path = cl_merge_pathnames(2, _ecl_static_18, v2x);
   if (Null(v3path)) { goto L74; }
   T0 = cl_merge_pathnames(2, _ecl_static_15, v3path);
   T1 = cl_list(2, _ecl_static_12, T0);
   T2 = ecl_list1(T1);
   si_pathname_translations(2, _ecl_static_19, T2);
  }
 }
L74:;
 }
}
