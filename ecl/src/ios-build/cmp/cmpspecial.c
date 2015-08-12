/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPSPECIAL.LSP                                */
#include <ecl/ecl-cmp.h>
#include "cmp/cmpspecial.eclh"
/*	function definition for C1QUOTE                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1c1quote(cl_object v1args)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_function_dispatch(cl_env_copy,VV[32])(4, ECL_SYM("QUOTE",679), v1args, ecl_make_fixnum(1), ecl_make_fixnum(1)) /*  CHECK-ARGS-NUMBER */;
  T0 = ecl_car(v1args);
  value0 = ecl_function_dispatch(cl_env_copy,VV[33])(3, T0, VV[0], ECL_T) /*  C1CONSTANT-VALUE */;
  return value0;
 }
}
/*	function definition for C1DECLARE                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2c1declare(cl_object v1args)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = CONS(ECL_SYM("DECLARE",274),v1args);
  value0 = ecl_function_dispatch(cl_env_copy,VV[35])(2, _ecl_static_1, T0) /*  CMPERR */;
  return value0;
 }
}
/*	function definition for C1THE                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3c1the(cl_object v1args)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_function_dispatch(cl_env_copy,VV[32])(4, ECL_SYM("THE",856), v1args, ecl_make_fixnum(2), ecl_make_fixnum(2)) /*  CHECK-ARGS-NUMBER */;
  {
   cl_object v2type;
   v2type = ecl_car(v1args);
   if (Null(ecl_function_dispatch(cl_env_copy,VV[37])(0) /*  POLICY-THE-IS-CHECKED */)) { goto L3; }
   if (!(ECL_CONSP(v2type))) { goto L7; }
   T0 = ecl_car(v2type);
   if ((T0)==(ECL_SYM("VALUES",895))) { goto L3; }
   goto L4;
L7:;
   goto L4;
L4:;
   value0 = ecl_function_dispatch(cl_env_copy,VV[38])(1, v1args) /*  C1CHECKED-VALUE */;
   return value0;
L3:;
   value0 = L4c1truly_the(v1args);
   return value0;
  }
 }
}
/*	function definition for C1TRULY-THE                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4c1truly_the(cl_object v1args)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_function_dispatch(cl_env_copy,VV[32])(4, ECL_SYM("TRULY-THE",1949), v1args, ecl_make_fixnum(2), ecl_make_fixnum(2)) /*  CHECK-ARGS-NUMBER */;
  {
   cl_object v2form;
   cl_object v3the_type;
   cl_object v4type;
   T0 = ecl_cadr(v1args);
   v2form = ecl_function_dispatch(cl_env_copy,VV[40])(1, T0) /*  C1EXPR */;
   v3the_type = ecl_car(v1args);
   v4type = ECL_NIL;
   T0 = ecl_function_dispatch(cl_env_copy,VV[41])(1, v2form) /*  C1FORM-TYPE */;
   v4type = ecl_function_dispatch(cl_env_copy,VV[42])(2, v3the_type, T0) /*  VALUES-TYPE-AND */;
   if (Null(ecl_function_dispatch(cl_env_copy,VV[43])(1, v4type) /*  VALUES-TYPE-PRIMARY-TYPE */)) { goto L8; }
   ecl_structure_set(v2form,VV[4],1,v4type);
   goto L7;
L8:;
   T0 = CONS(ECL_SYM("THE",856),v1args);
   ecl_function_dispatch(cl_env_copy,VV[44])(2, _ecl_static_2, T0) /*  CMPWARN */;
L7:;
   value0 = v2form;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for C1COMPILER-LET                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5c1compiler_let(cl_object v1args)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2symbols;
   cl_object v3values;
   v2symbols = ECL_NIL;
   v3values = ECL_NIL;
   if (!(ecl_endp(v1args))) { goto L3; }
   ecl_function_dispatch(cl_env_copy,VV[46])(3, ECL_SYM("COMPILER-LET",1334), ecl_make_fixnum(1), ecl_make_fixnum(0)) /*  TOO-FEW-ARGS */;
L3:;
   {
    cl_object v4;
    v4 = ecl_car(v1args);
    goto L9;
L8:;
    {
     cl_object v5spec;
     v5spec = ecl_car(v4);
     if (!(ECL_CONSP(v5spec))) { goto L14; }
     T0 = ecl_car(v5spec);
     if (!(ECL_SYMBOLP(T0))) { goto L19; }
     T0 = ecl_cdr(v5spec);
     if (ecl_endp(T0)) { goto L16; }
     T0 = ecl_cddr(v5spec);
     if (ecl_endp(T0)) { goto L16; }
     goto L17;
L19:;
     goto L17;
L17:;
     ecl_function_dispatch(cl_env_copy,VV[35])(2, _ecl_static_3, v5spec) /*  CMPERR */;
L16:;
     T0 = ecl_car(v5spec);
     v2symbols = CONS(T0,v2symbols);
     T1 = ecl_cdr(v5spec);
     if (!(ecl_endp(T1))) { goto L26; }
     T0 = ECL_NIL;
     goto L25;
L26:;
     T1 = ecl_cadr(v5spec);
     T0 = cl_eval(T1);
L25:;
     v3values = CONS(T0,v3values);
     goto L13;
L14:;
     if (!(ECL_SYMBOLP(v5spec))) { goto L28; }
     v2symbols = CONS(v5spec,v2symbols);
     v3values = CONS(ECL_NIL,v3values);
     goto L13;
L28:;
     ecl_function_dispatch(cl_env_copy,VV[35])(2, _ecl_static_3, v5spec) /*  CMPERR */;
L13:;
    }
    v4 = ecl_cdr(v4);
L9:;
    if (Null(v4)) { goto L35; }
    goto L8;
L35:;
   }
   v2symbols = cl_nreverse(v2symbols);
   v3values = cl_nreverse(v3values);
   {
    cl_object v5, v6; cl_index v4;
    v5 = v2symbols;
    v6 = v3values;
    v4 = ecl_progv(cl_env_copy, v5, v6);
    T0 = ecl_cdr(v1args);
    v1args = ecl_function_dispatch(cl_env_copy,VV[47])(1, T0) /*  C1PROGN */;
    ecl_bds_unwind(cl_env_copy,v4);
   }
   value0 = ecl_function_dispatch(cl_env_copy,VV[48])(5, ECL_SYM("COMPILER-LET",1334), v1args, v2symbols, v3values, v1args) /*  MAKE-C1FORM */;
   return value0;
  }
 }
}
/*	function definition for C2COMPILER-LET                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6c2compiler_let(cl_object v1c1form, cl_object v2symbols, cl_object v3values, cl_object v4body)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6, v7; cl_index v5;
   v6 = v2symbols;
   v7 = v3values;
   v5 = ecl_progv(cl_env_copy, v6, v7);
   value0 = ecl_function_dispatch(cl_env_copy,VV[50])(1, v4body) /*  C2EXPR */;
   ecl_bds_unwind(cl_env_copy,v5);
   return value0;
  }
 }
}
/*	function definition for C1FUNCTION                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7c1function(cl_object v1args)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_function_dispatch(cl_env_copy,VV[32])(4, ECL_SYM("FUNCTION",396), v1args, ecl_make_fixnum(1), ecl_make_fixnum(1)) /*  CHECK-ARGS-NUMBER */;
  {
   cl_object v2fun;
   v2fun = ecl_car(v1args);
   if (Null(si_valid_function_name_p(v2fun))) { goto L3; }
   {
    cl_object v3funob;
    v3funob = ecl_function_dispatch(cl_env_copy,VV[52])(2, v2fun, ECL_T) /*  LOCAL-FUNCTION-REF */;
    if (Null(v3funob)) { goto L6; }
    {
     cl_object v4var;
     v4var = ecl_function_dispatch(cl_env_copy,VV[53])(1, v3funob) /*  FUN-VAR */;
     T0 = ecl_function_dispatch(cl_env_copy,VV[54])(3, VV[8], VV[9], v4var) /*  MAKE-C1FORM* */;
     value0 = ecl_function_dispatch(cl_env_copy,VV[55])(2, v4var, T0) /*  ADD-TO-READ-NODES */;
     return value0;
    }
L6:;
    if (!(ECL_SYMBOLP(v2fun))) { goto L12; }
    T1 = si_get_sysprop(v2fun, VV[11]);
    goto L10;
L12:;
    T1 = ECL_NIL;
    goto L10;
L10:;
    T0 = Null(T1)?ECL_T:ECL_NIL;
    value0 = ecl_function_dispatch(cl_env_copy,VV[54])(9, ECL_SYM("FUNCTION",396), ECL_SYM("TYPE",1318), ECL_SYM("FUNCTION",396), VV[10], T0, VV[9], VV[12], ECL_NIL, v2fun) /*  MAKE-C1FORM* */;
    return value0;
   }
L3:;
   if (!(ECL_CONSP(v2fun))) { goto L14; }
   {
    cl_object v5;
    v5 = ecl_car(v2fun);
    if (!((v5)==(ECL_SYM("LAMBDA",452)))) { goto L21; }
    goto L18;
    goto L19;
L21:;
    goto L19;
L19:;
    if (!((v5)==(ECL_SYM("LAMBDA-BLOCK",1339)))) { goto L14; }
    goto L15;
L18:;
   }
L15:;
   T0 = ecl_cdr(v2fun);
   if (!(ecl_endp(T0))) { goto L24; }
   ecl_function_dispatch(cl_env_copy,VV[35])(2, _ecl_static_4, v2fun) /*  CMPERR */;
L24:;
   {
    cl_object v5name;
    cl_object v6body;
    v5name = ECL_NIL;
    v6body = ECL_NIL;
    T0 = ecl_car(v2fun);
    if (!((T0)==(ECL_SYM("LAMBDA",452)))) { goto L29; }
    v5name = cl_gensym(0);
    v6body = ecl_cdr(v2fun);
    goto L28;
L29:;
    v5name = ecl_cadr(v2fun);
    v6body = ecl_cddr(v2fun);
L28:;
    T0 = CONS(v5name,v6body);
    T1 = ecl_list1(T0);
    T2 = cl_list(2, ECL_SYM("FUNCTION",396), v5name);
    T3 = cl_list(3, ECL_SYM("FLET",373), T1, T2);
    value0 = ecl_function_dispatch(cl_env_copy,VV[40])(1, T3) /*  C1EXPR */;
    return value0;
   }
L14:;
   value0 = ecl_function_dispatch(cl_env_copy,VV[35])(2, _ecl_static_5, v2fun) /*  CMPERR */;
   return value0;
  }
 }
}
/*	function definition for C2FUNCTION                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8c2function(cl_object v1c1form, cl_object v2kind, cl_object v3funob, cl_object v4fun)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!((v2kind)==(VV[12]))) { goto L1; }
  T0 = cl_list(2, ECL_SYM("FDEFINITION",349), v4fun);
  value0 = ecl_function_dispatch(cl_env_copy,VV[57])(1, T0) /*  UNWIND-EXIT */;
  return value0;
L1:;
  if (!((v2kind)==(VV[16]))) { goto L3; }
  ecl_function_dispatch(cl_env_copy,VV[58])(0)    /*  BABOON          */;
  L9new_local(v4fun);
  T0 = cl_list(2, VV[17], v4fun);
  value0 = ecl_function_dispatch(cl_env_copy,VV[57])(1, T0) /*  UNWIND-EXIT */;
  return value0;
L3:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for NEW-LOCAL                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L9new_local(cl_object v1fun)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   v2 = ecl_function_dispatch(cl_env_copy,VV[60])(1, v1fun) /*  FUN-CLOSURE */;
   if (!((v2)==(VV[16]))) { goto L3; }
   ecl_structure_set(v1fun,VV[19],6,ecl_make_fixnum(0));
   {
    cl_object v3;
    v3 = ecl_symbol_value(VV[20]);
    ecl_structure_set(v1fun,VV[19],7,v3);
    goto L1;
   }
L3:;
   if (!((v2)==(VV[21]))) { goto L7; }
   {
    cl_object v4parent;
    v4parent = ecl_function_dispatch(cl_env_copy,VV[61])(1, v1fun) /*  FUN-PARENT */;
    {
     cl_object v5;
     if (!(ecl_plusp(ecl_symbol_value(VV[22])))) { goto L12; }
     v5 = ecl_one_plus(ecl_symbol_value(VV[23]));
     goto L11;
L12:;
     v5 = ecl_symbol_value(VV[23]);
L11:;
     ecl_structure_set(v1fun,VV[19],6,v5);
    }
    ecl_structure_set(v1fun,VV[19],7,ecl_make_fixnum(0));
    goto L1;
   }
L7:;
   ecl_structure_set(v1fun,VV[19],7,ecl_make_fixnum(0));
   ecl_structure_set(v1fun,VV[19],6,ecl_make_fixnum(0));
  }
L1:;
  goto L15;
  T0 = ecl_function_dispatch(cl_env_copy,VV[60])(1, v1fun) /*  FUN-CLOSURE */;
  if (!((T0)==(VV[16]))) { goto L18; }
  ecl_function_dispatch(cl_env_copy,VV[62])(1, _ecl_static_6) /*  CMPNOTE */;
  goto L17;
L18:;
  T0 = ecl_function_dispatch(cl_env_copy,VV[63])(1, v1fun) /*  FUN-NAME */;
  ecl_function_dispatch(cl_env_copy,VV[62])(2, _ecl_static_7, T0) /*  CMPNOTE */;
L17:;
  {
   cl_object v2;
   v2 = ecl_function_dispatch(cl_env_copy,VV[64])(1, ECL_NIL) /*  FUN-CFUN */;
   ecl_structure_set(v1fun,VV[19],5,v2);
  }
  ecl_structure_set(v1fun,VV[19],15,ECL_NIL);
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L15:;
  cl_set(VV[24],CONS(v1fun,ecl_symbol_value(VV[24])));
  value0 = ecl_symbol_value(VV[24]);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for WT-FDEFINITION                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L10wt_fdefinition(cl_object v1fun_name)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2name;
   cl_object v3package;
   cl_object v4safe;
   v2name = si_function_block_name(v1fun_name);
   v3package = cl_symbol_package(v2name);
   T0 = ecl_function_dispatch(cl_env_copy,VV[66])(0) /*  SAFE-COMPILE */;
   value0 = Null(T0)?ECL_T:ECL_NIL;
   if ((value0)!=ECL_NIL) { goto L5; }
   T0 = cl_find_package(_ecl_static_8);
   if ((v3package)==(T0)) { goto L10; }
   T0 = cl_find_package(_ecl_static_9);
   if ((v3package)==(T0)) { goto L10; }
   T0 = cl_find_package(_ecl_static_10);
   if (!((v3package)==(T0))) { goto L8; }
   goto L9;
L10:;
L9:;
   if (Null(cl_fboundp(v1fun_name))) { goto L8; }
   T0 = cl_fdefinition(v1fun_name);
   v4safe = cl_functionp(T0);
   goto L3;
L8:;
   v4safe = ECL_NIL;
   goto L3;
L5:;
   v4safe = value0;
   goto L3;
L3:;
   if (!((v2name)==(v1fun_name))) { goto L14; }
   {
    cl_object v5vv;
    v5vv = ecl_function_dispatch(cl_env_copy,VV[67])(1, v2name) /*  ADD-SYMBOL */;
    if (Null(v4safe)) { goto L17; }
    value0 = ecl_function_dispatch(cl_env_copy,VV[68])(3, _ecl_static_11, v5vv, _ecl_static_12) /*  WT */;
    return value0;
L17:;
    value0 = ecl_function_dispatch(cl_env_copy,VV[68])(3, _ecl_static_13, v5vv, _ecl_static_14) /*  WT */;
    return value0;
   }
L14:;
   if (Null(v4safe)) { goto L19; }
   {
    cl_object v6set_loc;
    v6set_loc = ecl_assql(v2name,ecl_symbol_value(VV[26]));
    if ((v6set_loc)!=ECL_NIL) { goto L22; }
    {
     cl_object v7setf_vv;
     cl_object v8name_vv;
     v7setf_vv = ecl_function_dispatch(cl_env_copy,VV[69])(0) /*  DATA-EMPTY-LOC */;
     v8name_vv = ecl_function_dispatch(cl_env_copy,VV[67])(1, v2name) /*  ADD-SYMBOL */;
     v6set_loc = cl_list(3, v2name, v7setf_vv, v8name_vv);
     cl_set(VV[26],CONS(v6set_loc,ecl_symbol_value(VV[26])));
    }
L22:;
    T0 = ecl_cadr(v6set_loc);
    value0 = ecl_function_dispatch(cl_env_copy,VV[68])(3, _ecl_static_15, T0, _ecl_static_14) /*  WT */;
    return value0;
   }
L19:;
   {
    cl_object v7vv;
    v7vv = ecl_function_dispatch(cl_env_copy,VV[67])(1, v1fun_name) /*  ADD-SYMBOL */;
    value0 = ecl_function_dispatch(cl_env_copy,VV[68])(3, _ecl_static_13, v7vv, _ecl_static_14) /*  WT */;
    return value0;
   }
  }
 }
}
/*	function definition for ENVIRONMENT-ACCESSOR                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L11environment_accessor(cl_object v1fun)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2env_var;
   cl_object v3expected_env_size;
   v2env_var = ecl_function_dispatch(cl_env_copy,VV[71])(1, ecl_symbol_value(VV[28])) /*  ENV-VAR-NAME */;
   v3expected_env_size = ecl_function_dispatch(cl_env_copy,VV[72])(1, v1fun) /*  FUN-ENV */;
   if (!(ecl_number_compare(v3expected_env_size,ecl_symbol_value(VV[20]))<0)) { goto L3; }
   T0 = ecl_minus(ecl_symbol_value(VV[20]),v3expected_env_size);
   value0 = cl_format(4, ECL_NIL, _ecl_static_16, T0, v2env_var);
   return value0;
L3:;
   value0 = v2env_var;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for WT-MAKE-CLOSURE                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L12wt_make_closure(cl_object v1fun)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2cfun;
   v2cfun = ecl_function_dispatch(cl_env_copy,VV[64])(1, v1fun) /*  FUN-CFUN */;
   {
    cl_object v3closure;
    cl_object v4narg;
    v3closure = ecl_function_dispatch(cl_env_copy,VV[60])(1, v1fun) /*  FUN-CLOSURE */;
    v4narg = ECL_NIL;
    if (!((v3closure)==(VV[16]))) { goto L4; }
    T0 = L11environment_accessor(v1fun);
    value0 = ecl_function_dispatch(cl_env_copy,VV[68])(5, _ecl_static_17, v2cfun, _ecl_static_18, T0, _ecl_static_19) /*  WT */;
    return value0;
L4:;
    if (!((v3closure)==(VV[21]))) { goto L6; }
    value0 = ecl_function_dispatch(cl_env_copy,VV[58])(0) /*  BABOON  */;
    return value0;
L6:;
    v4narg = ecl_function_dispatch(cl_env_copy,VV[74])(1, v1fun) /*  FUN-FIXED-NARG */;
    if (Null(v4narg)) { goto L8; }
    value0 = ecl_function_dispatch(cl_env_copy,VV[68])(5, _ecl_static_20, v2cfun, _ecl_static_21, v4narg, _ecl_static_14) /*  WT */;
    return value0;
L8:;
    value0 = ecl_function_dispatch(cl_env_copy,VV[68])(3, _ecl_static_22, v2cfun, _ecl_static_23) /*  WT */;
    return value0;
   }
  }
 }
}

#include "cmp/cmpspecial.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclY8e2V0rEfdBs9_b9zTOE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPSPECIAL.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclY8e2V0rEfdBs9_b9zTOE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[31]);                           /*  C1QUOTE         */
 ecl_cmp_defun(VV[34]);                           /*  C1DECLARE       */
 ecl_cmp_defun(VV[36]);                           /*  C1THE           */
 ecl_cmp_defun(VV[39]);                           /*  C1TRULY-THE     */
 ecl_cmp_defun(VV[45]);                           /*  C1COMPILER-LET  */
 ecl_cmp_defun(VV[49]);                           /*  C2COMPILER-LET  */
 ecl_cmp_defun(VV[51]);                           /*  C1FUNCTION      */
 ecl_cmp_defun(VV[56]);                           /*  C2FUNCTION      */
 ecl_cmp_defun(VV[59]);                           /*  NEW-LOCAL       */
 ecl_cmp_defun(VV[65]);                           /*  WT-FDEFINITION  */
 ecl_cmp_defun(VV[70]);                           /*  ENVIRONMENT-ACCESSOR */
 ecl_cmp_defun(VV[73]);                           /*  WT-MAKE-CLOSURE */
}
