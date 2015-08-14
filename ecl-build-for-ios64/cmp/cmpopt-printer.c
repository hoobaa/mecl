/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPOPT-PRINTER.LSP                            */
#include <ecl/ecl-cmp.h>
#include "cmp/cmpopt-printer.eclh"
/*	function definition for PRINTER-DEFAULT-STREAM                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1printer_default_stream(cl_object v1stream, cl_object v2env)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_constantp(2, v1stream, v2env))) { goto L1; }
  {
   cl_object v3value;
   v3value = ecl_function_dispatch(cl_env_copy,VV[12])(2, v1stream, v2env) /*  CMP-EVAL */;
   if (!((v3value)==(ECL_NIL))) { goto L4; }
   value0 = ECL_SYM("*STANDARD-OUTPUT*",67);
   cl_env_copy->nvalues = 1;
   return value0;
L4:;
   if (!(ecl_eql(v3value,ECL_T))) { goto L7; }
   value0 = ECL_SYM("*TERMINAL-IO*",68);
   cl_env_copy->nvalues = 1;
   return value0;
L7:;
   if (Null(cl_streamp(v3value))) { goto L12; }
   T0 = _ecl_static_1;
   goto L11;
L12:;
   T0 = _ecl_static_2;
L11:;
   ecl_function_dispatch(cl_env_copy,VV[13])(2, T0, v1stream) /*  CMPWARN */;
   value0 = v1stream;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L1:;
  T0 = ecl_list1(v1stream);
  value0 = cl_listX(3, ECL_SYM("C-INLINE",1973), T0, VV[2]);
  return value0;
 }
}
/*	local function PRINC                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC2princ(cl_object v1, cl_object v2env)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4expression;
   cl_object v5stream;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4expression = v6;
   }
   if (Null(v3)) { goto L9; }
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5stream = v6;
    goto L8;
   }
L9:;
   v5stream = ECL_NIL;
L8:;
   if (Null(v3)) { goto L14; }
   si_dm_too_many_arguments(v1);
L14:;
   if (Null(cl_constantp(2, v4expression, v2env))) { goto L16; }
   {
    cl_object v6value;
    v6value = ecl_function_dispatch(cl_env_copy,VV[12])(2, v4expression, v2env) /*  CMP-EVAL */;
    if (!(((v6value)==ECL_CODE_CHAR((ecl_character)(10))))) { goto L19; }
    value0 = cl_list(2, ECL_SYM("TERPRI",855), v5stream);
    return value0;
L19:;
    if (!(ECL_CHARACTERP(v6value))) { goto L21; }
    T0 = cl_list(2, v6value, v5stream);
    value0 = cl_listX(3, ECL_SYM("C-INLINE",1973), T0, VV[4]);
    return value0;
L21:;
    if (!(ECL_STRINGP(v6value))) { goto L23; }
    {
     cl_fixnum v7;
     v7 = ecl_length(v6value);
     if (!((v7)==(1))) { goto L23; }
    }
    if (ecl_unlikely((0)>=(v6value)->vector.dim))
           FEwrong_index(ECL_NIL,v6value,-1,ecl_make_fixnum(0),(v6value)->vector.dim);
    T0 = ecl_aref_unsafe(v6value,0);
    T1 = cl_list(2, T0, v5stream);
    value0 = cl_listX(3, ECL_SYM("C-INLINE",1973), T1, VV[4]);
    return value0;
L23:;
    if (Null(si_base_string_p(v6value))) { goto L29; }
    {
     cl_fixnum v7;
     v7 = ecl_length(v6value);
     if (!((v7)<(80))) { goto L29; }
    }
    T0 = ecl_list1(v5stream);
    T1 = ecl_function_dispatch(cl_env_copy,VV[14])(1, v6value) /*  C-INLINE-SAFE-STRING */;
    T2 = cl_concatenate(4, ECL_SYM("STRING",805), _ecl_static_3, T1, _ecl_static_4);
    T3 = cl_listX(6, ECL_SYM("C-INLINE",1973), T0, VV[5], ECL_SYM("VOID",1381), T2, VV[6]);
    value0 = cl_list(3, ECL_SYM("PROGN",671), T3, v6value);
    return value0;
L29:;
    T0 = cl_list(2, v4expression, v5stream);
    value0 = cl_listX(3, ECL_SYM("C-INLINE",1973), T0, VV[7]);
    return value0;
   }
L16:;
   T0 = cl_list(2, v4expression, v5stream);
   value0 = cl_listX(3, ECL_SYM("C-INLINE",1973), T0, VV[7]);
   return value0;
  }
 }
}
/*	local function TERPRI                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC3terpri(cl_object v1, cl_object v2env)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4stream;
   v3 = ecl_cdr(v1);
   if (Null(v3)) { goto L3; }
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4stream = v5;
    goto L2;
   }
L3:;
   v4stream = ECL_NIL;
L2:;
   if (Null(v3)) { goto L8; }
   si_dm_too_many_arguments(v1);
L8:;
   T0 = ecl_list1(v4stream);
   value0 = cl_listX(3, ECL_SYM("C-INLINE",1973), T0, VV[8]);
   return value0;
  }
 }
}
/*	local function PRINT                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC4print(cl_object v1, cl_object v2env)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4value;
   cl_object v5stream;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4value = v6;
   }
   if (Null(v3)) { goto L9; }
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5stream = v6;
    goto L8;
   }
L9:;
   v5stream = ECL_NIL;
L8:;
   if (Null(v3)) { goto L14; }
   si_dm_too_many_arguments(v1);
L14:;
   T0 = cl_list(2, v4value, v5stream);
   value0 = cl_listX(3, ECL_SYM("C-INLINE",1973), T0, VV[9]);
   return value0;
  }
 }
}
/*	local function PRIN1                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC5prin1(cl_object v1, cl_object v2env)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4value;
   cl_object v5stream;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4value = v6;
   }
   if (Null(v3)) { goto L9; }
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5stream = v6;
    goto L8;
   }
L9:;
   v5stream = ECL_NIL;
L8:;
   if (Null(v3)) { goto L14; }
   si_dm_too_many_arguments(v1);
L14:;
   T0 = cl_list(2, v4value, v5stream);
   value0 = cl_listX(3, ECL_SYM("C-INLINE",1973), T0, VV[10]);
   return value0;
  }
 }
}

#include "cmp/cmpopt-printer.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclpPIFoZqQ78bq9_ynrtVE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPOPT-PRINTER.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclpPIFoZqQ78bq9_ynrtVE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[11]);                           /*  PRINTER-DEFAULT-STREAM */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC2princ,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("PRINC",660), ECL_SYM("COMPILER-MACRO",238), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC3terpri,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("TERPRI",855), ECL_SYM("COMPILER-MACRO",238), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC4print,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("PRINT",662), ECL_SYM("COMPILER-MACRO",238), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC5prin1,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("PRIN1",658), ECL_SYM("COMPILER-MACRO",238), T0);
 }
}
