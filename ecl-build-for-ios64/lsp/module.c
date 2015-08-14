/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:LSP;MODULE.LSP                                    */
#include <ecl/ecl-cmp.h>
#include "lsp/module.eclh"
/*	function definition for PROVIDE                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_provide(cl_object v1module_name)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_string(v1module_name);
  T1 = ecl_symbol_value(ECL_SYM("*MODULES*",41));
  T2 = (ECL_SYM("STRING=",822)->symbol.gfdef);
  cl_set(ECL_SYM("*MODULES*",41),cl_adjoin(4, T0, T1, ECL_SYM("TEST",1316), T2));
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for REQUIRE-ERROR                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1require_error(cl_narg narg, cl_object v1control, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2arguments;
  ecl_va_list args; ecl_va_start(args,v1control,narg,1);
  v2arguments = cl_grab_rest_args(args);
  ecl_va_end(args);
  value0 = cl_error(3, _ecl_static_1, v1control, v2arguments);
  return value0;
 }
}
/*	function definition for REQUIRE                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_require(cl_narg narg, cl_object v1module_name, ...)
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2pathnames;
  va_list args; va_start(args,v1module_name);
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1module_name,env0);         /*  MODULE-NAME     */
  {
   int i = 1;
   if (i >= narg) {
    v2pathnames = ECL_NIL;
   } else {
    i++;
    v2pathnames = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v3name;
   v3name = cl_string(ECL_CONS_CAR(CLV0));
   {
    cl_object v4;
    v4 = ecl_symbol_value(VV[0]);
    goto L8;
L7:;
    {
     cl_object v5;
     cl_object v6;
     if (ecl_unlikely(ECL_ATOM(v4))) FEtype_error_cons(v4);
     v5 = v4;
     v6 = ECL_CONS_CAR(v5);
     if (Null(cl_stringE(2, v3name, v6))) { goto L10; }
     if (Null(v5)) { goto L3; }
     goto L4;
    }
L10:;
    v4 = ECL_CONS_CDR(v4);
L8:;
    if (v4==ECL_NIL) { goto L17; }
    goto L7;
L17:;
    goto L3;
   }
L4:;
   L1require_error(3, _ecl_static_2, ECL_SYM("REQUIRE",718), ECL_CONS_CAR(CLV0));
L3:;
   {
    cl_object v4;
    cl_object v5;
    v4 = cl_copy_list(ecl_symbol_value(ECL_SYM("*MODULES*",41)));
    v5 = CONS(v3name,ecl_symbol_value(VV[0]));
    ecl_bds_bind(cl_env_copy,VV[0],v5);           /*  *REQUIRING*     */
    {
     cl_object v6;
     v6 = ecl_symbol_value(ECL_SYM("*MODULES*",41));
     goto L26;
L25:;
     {
      cl_object v7;
      cl_object v8;
      if (ecl_unlikely(ECL_ATOM(v6))) FEtype_error_cons(v6);
      v7 = v6;
      v8 = ECL_CONS_CAR(v7);
      if (Null(cl_stringE(2, v3name, v8))) { goto L28; }
      if ((v7)!=ECL_NIL) { goto L21; }
      goto L22;
     }
L28:;
     v6 = ECL_CONS_CDR(v6);
L26:;
     if (v6==ECL_NIL) { goto L35; }
     goto L25;
L35:;
    }
L22:;
    if (Null(v2pathnames)) { goto L37; }
    if (ECL_LISTP(v2pathnames)) { goto L39; }
    v2pathnames = ecl_list1(v2pathnames);
L39:;
    {
     cl_object v6;
     v6 = v2pathnames;
     goto L45;
L44:;
     {
      cl_object v7ele;
      v7ele = ecl_car(v6);
      cl_load(1, v7ele);
     }
     v6 = ecl_cdr(v6);
L45:;
     if (Null(v6)) { goto L52; }
     goto L44;
L52:;
     goto L21;
    }
L37:;
    {cl_object v7;
     v7 = ECL_NIL;
     v7 = ecl_make_cclosure_va((cl_objectfn)LC2__g17,env0,Cblock);
     T0 = v7;
    }
    if ((cl_some(2, T0, ecl_symbol_value(ECL_SYM("*MODULE-PROVIDER-FUNCTIONS*",42))))!=ECL_NIL) { goto L21; }
    L1require_error(3, _ecl_static_3, ECL_SYM("REQUIRE",718), ECL_CONS_CAR(CLV0));
L21:;
    value0 = cl_set_difference(2, ecl_symbol_value(ECL_SYM("*MODULES*",41)), v4);
    ecl_bds_unwind1(cl_env_copy);
    return value0;
   }
  }
 }
}
/*	closure G17                                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC2__g17(cl_narg narg, cl_object v1p, ...)
{
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  MODULE-NAME     */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,v1p)(1, ECL_CONS_CAR(CLV0));
  return value0;
 }
 }
}
/*	local function G19                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC3__g19(cl_object v1module)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2module;
   v2module = cl_string(v1module);
   {
    cl_object v3path;
    v3path = cl_make_pathname(4, ECL_SYM("NAME",1273), v2module, ECL_SYM("DEFAULTS",1216), _ecl_static_4);
    value0 = cl_load(3, v3path, ECL_SYM("IF-DOES-NOT-EXIST",1244), ECL_NIL);
   }
   if ((value0)!=ECL_NIL) { goto L3; }
   {
    cl_object v3path;
    T0 = cl_string_downcase(1, v2module);
    v3path = cl_make_pathname(4, ECL_SYM("NAME",1273), T0, ECL_SYM("DEFAULTS",1216), _ecl_static_4);
    value0 = cl_load(3, v3path, ECL_SYM("IF-DOES-NOT-EXIST",1244), ECL_NIL);
    return value0;
   }
L3:;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}

#include "lsp/module.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecltwS0ObbvOHvl9_tqCcYE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:LSP;MODULE.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_ecltwS0ObbvOHvl9_tqCcYE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 si_Xmake_special(ECL_SYM("*MODULES*",41));
 cl_set(ECL_SYM("*MODULES*",41),ECL_NIL);
 si_Xmake_special(ECL_SYM("*MODULE-PROVIDER-FUNCTIONS*",42));
 cl_set(ECL_SYM("*MODULE-PROVIDER-FUNCTIONS*",42),ECL_NIL);
 (void)0; /* No entry created for PROVIDE */
 si_Xmake_special(VV[0]);
 cl_set(VV[0],ECL_NIL);
 ecl_cmp_defun(VV[2]);                            /*  REQUIRE-ERROR   */
 (void)0; /* No entry created for REQUIRE */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC3__g19,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 cl_set(ECL_SYM("*MODULE-PROVIDER-FUNCTIONS*",42),cl_adjoin(2, T0, ecl_symbol_value(ECL_SYM("*MODULE-PROVIDER-FUNCTIONS*",42))));
 }
}
