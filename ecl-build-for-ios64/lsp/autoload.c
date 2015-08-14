/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:LSP;AUTOLOAD.LSP                                  */
#include <ecl/ecl-cmp.h>
#include "lsp/autoload.eclh"
/*	function definition for LISP-IMPLEMENTATION-TYPE              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1lisp_implementation_type()
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
/*	function definition for AUTOLOAD                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4autoload(cl_narg narg, cl_object v1pathname, ...)
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2si__function_names;
  ecl_va_list args; ecl_va_start(args,v1pathname,narg,1);
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1pathname,env0);            /*  PATHNAME        */
  v2si__function_names = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v3;
   v3 = v2si__function_names;
   goto L4;
L3:;
   {
    cl_object v4si__fname;
    v4si__fname = ecl_car(v3);
    {
     cl_object env1 = env0;
     CLV1 = env1 = CONS(v4si__fname,env1);        /*  THENAME         */
     {cl_object v5;
      v5 = ECL_NIL;
      v5 = ecl_make_cclosure_va((cl_objectfn)LC3__g4,env1,Cblock);
      T0 = v5;
     }
     si_fset(4, v4si__fname, T0, ECL_NIL, ECL_NIL);
    }
   }
   v3 = ecl_cdr(v3);
L4:;
   if (Null(v3)) { goto L12; }
   goto L3;
L12:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	closure G4                                                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC3__g4(cl_narg narg, ...)
{
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  THENAME         */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 {
  cl_object v1si__args;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1si__args = cl_grab_rest_args(args);
  ecl_va_end(args);
  cl_load(1, ECL_CONS_CAR(CLV0));
  value0 = cl_apply(2, ECL_CONS_CAR(CLV1), v1si__args);
  return value0;
 }
 }
}
/*	function definition for PROCLAIM                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5proclaim(cl_object v1si__d)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_car(v1si__d);
  if (!((T0)==(ECL_SYM("SPECIAL",789)))) { goto L1; }
  {
   cl_object v2;
   v2 = ecl_cdr(v1si__d);
   {
    cl_object v3;
    cl_object v4;
    v3 = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v2))) FEtype_error_list(v2);
    v4 = v2;
L7:;
    if (!(ecl_endp(v4))) { goto L9; }
    goto L8;
L9:;
    v3 = _ecl_car(v4);
    {
     cl_object v5;
     v5 = _ecl_cdr(v4);
     if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
     v4 = v5;
    }
    si_Xmake_special(v3);
    goto L7;
L8:;
    value0 = v2;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function WITH-COMPILATION-UNIT                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC6with_compilation_unit(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4si__options;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4si__options = v5;
   }
   value0 = CONS(ECL_SYM("PROGN",671),v3);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for ED                                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7ed(cl_narg narg, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1si__filename;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1si__filename = ECL_NIL;
   } else {
    i++;
    v1si__filename = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = si_getenv(_ecl_static_3);
  if ((value0)!=ECL_NIL) { goto L4; }
  T0 = _ecl_static_4;
  goto L2;
L4:;
  T0 = value0;
  goto L2;
L2:;
  T1 = cl_format(4, ECL_NIL, _ecl_static_2, T0, v1si__filename);
  value0 = si_system(T1);
  return value0;
 }
}
/*	function definition for ROOM                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8room(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1si__x;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1si__x = ECL_NIL;
   } else {
    i++;
    v1si__x = va_arg(args,cl_object);
   }
  }
  va_end(args);
  cl_format(2, ECL_T, _ecl_static_5);
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  return value0;
 }
}
/*	function definition for HELP                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L9help(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1symbol;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1symbol = VV[8];
   } else {
    i++;
    v1symbol = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = ecl_function_dispatch(cl_env_copy,VV[17])(1, v1symbol) /*  PRINT-DOC */;
  return value0;
 }
}

#include "lsp/autoload.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecl3WFL2k0m36Hi9_nuCcYE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:LSP;AUTOLOAD.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_ecl3WFL2k0m36Hi9_nuCcYE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[10]);                           /*  LISP-IMPLEMENTATION-TYPE */
 ecl_cmp_defun(VV[11]);                           /*  AUTOLOAD        */
 if ((cl_fboundp(ECL_SYM("COMPILE",233)))!=ECL_NIL) { goto L10; }
 ecl_cmp_defun(VV[12]);                           /*  PROCLAIM        */
L10:;
 ecl_cmp_defmacro(VV[13]);                        /*  WITH-COMPILATION-UNIT */
 ecl_cmp_defun(VV[14]);                           /*  ED              */
 ecl_cmp_defun(VV[15]);                           /*  ROOM            */
 L4autoload(3, _ecl_static_6, VV[6], VV[7]);
 ecl_cmp_defun(VV[16]);                           /*  HELP            */
 si_select_package(_ecl_static_7);
 cl_import(1, VVtemp[0]);
}
