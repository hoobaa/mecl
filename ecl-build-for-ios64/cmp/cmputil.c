/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPUTIL.LSP                                   */
#include <ecl/ecl-cmp.h>
#include "cmp/cmputil.eclh"
/*	function definition for BRIEF-NAMESTRING                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1brief_namestring(cl_object v1path)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = si_coerce_to_filename(v1path);
  value0 = cl_enough_namestring(1, T0);
  return value0;
 }
}
/*	function definition for INNERMOST-NON-EXPANDED-FORM           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2innermost_non_expanded_form(cl_object v1form)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_LISTP(v1form))) { goto L1; }
  {
   cl_object v2output;
   v2output = ECL_NIL;
   {
    cl_object v3f;
    cl_object v4;
    v3f = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v1form))) FEtype_error_list(v1form);
    v4 = v1form;
L7:;
    if (!(ecl_endp(v4))) { goto L9; }
    goto L8;
L9:;
    v3f = _ecl_car(v4);
    {
     cl_object v5;
     v5 = _ecl_cdr(v4);
     if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
     v4 = v5;
    }
    if (!((v3f)==(ECL_SYM("MACROEXPAND",519)))) { goto L18; }
    v2output = ECL_NIL;
    goto L17;
L18:;
    if (!(v2output==ECL_NIL)) { goto L17; }
    v2output = v3f;
L17:;
    goto L7;
L8:;
    value0 = v2output;
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
/*	function definition for COMPILER-MESSAGE-REPORT               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3compiler_message_report(cl_narg narg, cl_object v1stream, cl_object v2c, cl_object v3format_control, ...)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 {
  cl_object v4format_arguments;
  ecl_va_list args; ecl_va_start(args,v3format_control,narg,3);
  v4format_arguments = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v5;
   cl_object v6;
   cl_object v7;
   cl_object v8;
   v5 = ecl_function_dispatch(cl_env_copy,VV[88])(1, v2c) /*  COMPILER-MESSAGE-FILE-POSITION */;
   v6 = ecl_function_dispatch(cl_env_copy,VV[89])(1, v2c) /*  COMPILER-MESSAGE-PREFIX */;
   v7 = ecl_function_dispatch(cl_env_copy,VV[90])(1, v2c) /*  COMPILER-MESSAGE-FILE */;
   T0 = ecl_function_dispatch(cl_env_copy,VV[91])(1, v2c) /*  COMPILER-MESSAGE-TOPLEVEL-FORM */;
   v8 = L2innermost_non_expanded_form(T0);
   if (Null(v8)) { goto L6; }
   if (Null(v5)) { goto L6; }
   if (ecl_minusp(v5)) { goto L6; }
   if (ecl_equalp(v8,VV[6])) { goto L6; }
   ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-LENGTH*",50),ecl_make_fixnum(2)); /*  *PRINT-LENGTH* */
   ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-LEVEL*",51),ecl_make_fixnum(2)); /*  *PRINT-LEVEL* */
   T0 = cl_pathname_name(1, v7);
   T1 = cl_pathname_type(1, v7);
   T2 = cl_pathname_version(v7);
   T3 = cl_make_pathname(6, ECL_SYM("NAME",1273), T0, ECL_SYM("TYPE",1318), T1, ECL_SYM("VERSION",1326), T2);
   cl_format(6, v1stream, _ecl_static_5, v6, T3, v5, v8);
   ecl_bds_unwind1(cl_env_copy);
   ecl_bds_unwind1(cl_env_copy);
   goto L5;
L6:;
   cl_format(3, v1stream, _ecl_static_6, v6);
L5:;
   T0 = ecl_function_dispatch(cl_env_copy,VV[92])(1, v2c) /*  COMPILER-MESSAGE-FORMAT */;
   value0 = cl_format(4, v1stream, T0, v3format_control, v4format_arguments);
   return value0;
  }
 }
}
/*	local function G9                                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC5__g9()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {cl_object v1;
   v1 = ECL_NIL;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC4__g10,ECL_NIL,Cblock,2);
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G11                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC6__g11()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_symbol_value(ECL_SYM("*COMPILE-FILE-PATHNAME*",26));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G12                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC7__g12()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_symbol_value(VV[9]);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G13                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC8__g13()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_symbol_value(VV[10]);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G14                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC9__g14()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_symbol_value(VV[11]);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G10                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC4__g10(cl_object v1c, cl_object v2stream)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_fdefinition(VV[7]);
  T1 = (cl_env_copy->function=(ECL_SYM("SIMPLE-CONDITION-FORMAT-CONTROL",768)->symbol.gfdef))->cfun.entry(1, v1c) /*  SIMPLE-CONDITION-FORMAT-CONTROL */;
  T2 = (cl_env_copy->function=(ECL_SYM("SIMPLE-CONDITION-FORMAT-ARGUMENTS",769)->symbol.gfdef))->cfun.entry(1, v1c) /*  SIMPLE-CONDITION-FORMAT-ARGUMENTS */;
  value0 = cl_apply(5, T0, v2stream, v1c, T1, T2);
  return value0;
 }
}
/*	local function G15                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC11__g15()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {cl_object v1;
   v1 = ECL_NIL;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC10__g16,ECL_NIL,Cblock,2);
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G16                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC10__g16(cl_object v1c, cl_object v2stream)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_slot_value(v1c, ECL_SYM("VARIABLE",897));
  value0 = L3compiler_message_report(4, v2stream, v1c, _ecl_static_7, T0);
  return value0;
 }
}
/*	function definition for PRINT-COMPILER-MESSAGE                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L12print_compiler_message(cl_object v1c, cl_object v2stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((cl_typep(2, v1c, ecl_symbol_value(VV[21])))!=ECL_NIL) { goto L1; }
  value0 = cl_format(3, v2stream, _ecl_static_8, v1c);
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for HANDLE-COMPILER-NOTE                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L13handle_compiler_note(cl_object v1c)
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
/*	function definition for HANDLE-COMPILER-WARNING               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L14handle_compiler_warning(cl_object v1c)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  cl_set(VV[24],CONS(v1c,ecl_symbol_value(VV[24])));
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for HANDLE-COMPILER-ERROR                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L15handle_compiler_error(cl_object v1c)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  (cl_env_copy->function=(ECL_SYM("SIGNAL",760)->symbol.gfdef))->cfun.entry(1, v1c) /*  SIGNAL */;
  cl_set(VV[24],CONS(v1c,ecl_symbol_value(VV[24])));
  L12print_compiler_message(v1c, ECL_T);
  value0 = cl_abort(0);
  return value0;
 }
}
/*	function definition for HANDLE-COMPILER-INTERNAL-ERROR        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L16handle_compiler_internal_error(cl_object v1c)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_symbol_value(VV[27]))) { goto L1; }
  (cl_env_copy->function=(ECL_SYM("INVOKE-DEBUGGER",445)->symbol.gfdef))->cfun.entry(1, v1c) /*  INVOKE-DEBUGGER */;
L1:;
  T0 = ecl_list1(v1c);
  v1c = (cl_env_copy->function=(ECL_SYM("MAKE-CONDITION",524)->symbol.gfdef))->cfun.entry(5, VV[18], ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_9, ECL_SYM("FORMAT-ARGUMENTS",1239), T0) /*  MAKE-CONDITION */;
  cl_set(VV[24],CONS(v1c,ecl_symbol_value(VV[24])));
  (cl_env_copy->function=(ECL_SYM("SIGNAL",760)->symbol.gfdef))->cfun.entry(1, v1c) /*  SIGNAL */;
  L12print_compiler_message(v1c, ECL_T);
  value0 = cl_abort(0);
  return value0;
 }
}
/*	function definition for DO-COMPILATION-UNIT                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L17do_compilation_unit(volatile cl_narg narg, cl_object volatile v1closure, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  volatile cl_object v2override;
  ecl_va_list args; ecl_va_start(args,v1closure,narg,1);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L17do_compilation_unitkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v2override = keyvars[0];
  }
  if (Null(v2override)) { goto L1; }
  ecl_bds_bind(cl_env_copy,VV[29],ECL_NIL);       /*  *ACTIVE-PROTECTION* */
  value0 = L17do_compilation_unit(1, v1closure);
  ecl_bds_unwind1(cl_env_copy);
  return value0;
L1:;
  if (!(ecl_symbol_value(VV[29])==ECL_NIL)) { goto L3; }
  ecl_bds_bind(cl_env_copy,VV[29],ECL_T);         /*  *ACTIVE-PROTECTION* */
  ecl_bds_bind(cl_env_copy,VV[30],ECL_NIL);       /*  *PENDING-ACTIONS* */
  {
   volatile bool unwinding = FALSE;
   cl_index v3=ECL_STACK_INDEX(cl_env_copy),v4;
   ecl_frame_ptr next_fr;
   if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
     unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
   } else {
   cl_env_copy->values[0] = L17do_compilation_unit(1, v1closure);
   }
   ecl_frs_pop(cl_env_copy);
   v4=ecl_stack_push_values(cl_env_copy);
   {
    cl_object v5;
    cl_object v6action;
    cl_object v7;
    v5 = ecl_symbol_value(VV[30]);
    v6action = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
    v7 = v5;
L11:;
    if (!(ecl_endp(v7))) { goto L13; }
    goto L12;
L13:;
    v6action = _ecl_car(v7);
    {
     cl_object v8;
     v8 = _ecl_cdr(v7);
     if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
     v7 = v8;
    }
    ecl_function_dispatch(cl_env_copy,v6action)(0);
    goto L11;
L12:;
   }
   ecl_stack_pop_values(cl_env_copy,v4);
   if (unwinding) ecl_unwind(cl_env_copy,next_fr);
   ECL_STACK_SET_INDEX(cl_env_copy,v3);
   ecl_bds_unwind1(cl_env_copy);
   ecl_bds_unwind1(cl_env_copy);
   return cl_env_copy->values[0];
  }
L3:;
  value0 = ecl_function_dispatch(cl_env_copy,v1closure)(0);
  return value0;
 }
}
/*	local function WITH-COMPILATION-UNIT                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC18with_compilation_unit(cl_object v1, cl_object v2)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4 = v5;
   }
   T0 = cl_listX(3, ECL_SYM("LAMBDA",452), ECL_NIL, v3);
   T1 = cl_list(2, ECL_SYM("FUNCTION",396), T0);
   value0 = cl_listX(3, VV[31], T1, v4);
   return value0;
  }
 }
}
/*	local function WITH-COMPILER-ENV                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC19with_compiler_env(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6compiler_conditions;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v7;
    v7 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4 = v7;
   }
   v5 = v4;
   if (!(v5==ECL_NIL)) { goto L10; }
   si_dm_too_few_arguments(v1);
L10:;
   {
    cl_object v7;
    v7 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v6compiler_conditions = v7;
   }
   if (Null(v5)) { goto L15; }
   si_dm_too_many_arguments(v1);
L15:;
   T0 = cl_listX(3, VV[32], ECL_NIL, v3);
   T1 = cl_list(3, ECL_SYM("LET",477), ecl_symbol_value(VV[37]), T0);
   T2 = cl_list(3, ECL_SYM("WITH-LOCK",1427), VV[36], T1);
   T3 = cl_list(3, ECL_SYM("HANDLER-BIND",417), VV[35], T2);
   T4 = cl_list(3, ECL_SYM("RESTART-CASE",722), T3, VV[38]);
   T5 = cl_list(3, ECL_SYM("SETF",750), v6compiler_conditions, VV[24]);
   value0 = cl_list(5, ECL_SYM("LET",477), VV[33], VV[34], T4, T5);
   return value0;
  }
 }
}
/*	function definition for PRINT-C1FORMS                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L20print_c1forms(cl_object v1form)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_CONSP(v1form))) { goto L1; }
  T0 = ecl_one_plus(ecl_symbol_value(VV[40]));
  ecl_bds_bind(cl_env_copy,VV[40],T0);            /*  *C1FORM-LEVEL*  */
  {
   cl_object v2;
   cl_object v3;
   v2 = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v1form))) FEtype_error_list(v1form);
   v3 = v1form;
L6:;
   if (!(ecl_endp(v3))) { goto L8; }
   goto L7;
L8:;
   v2 = _ecl_car(v3);
   {
    cl_object v4;
    v4 = _ecl_cdr(v3);
    if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
    v3 = v4;
   }
   L20print_c1forms(v2);
   goto L6;
L7:;
   value0 = v1form;
   cl_env_copy->nvalues = 1;
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
L1:;
  if (Null(ecl_function_dispatch(cl_env_copy,VV[103])(1, v1form) /*  C1FORM-P */)) { goto L19; }
  T0 = ecl_symbol_value(VV[40]);
  T1 = ecl_function_dispatch(cl_env_copy,VV[104])(1, v1form) /*  C1FORM-PARENT */;
  cl_format(5, ECL_T, _ecl_static_10, T0, v1form, T1);
  T0 = ecl_function_dispatch(cl_env_copy,VV[105])(1, v1form) /*  C1FORM-ARGS */;
  L20print_c1forms(T0);
  value0 = v1form;
  cl_env_copy->nvalues = 1;
  return value0;
L19:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for PRINT-REF                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L21print_ref(cl_object v1ref_object, cl_object v2stream)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3name;
   v3name = ecl_function_dispatch(cl_env_copy,VV[107])(1, v1ref_object) /*  REF-NAME */;
   if (Null(v3name)) { goto L2; }
   T0 = cl_type_of(v1ref_object);
   value0 = cl_format(4, v2stream, _ecl_static_11, T0, v3name);
   return value0;
L2:;
   T0 = cl_type_of(v1ref_object);
   value0 = cl_format(3, v2stream, _ecl_static_12, T0);
   return value0;
  }
 }
}
/*	function definition for PRINT-VAR                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L22print_var(cl_object v1var_object, cl_object v2stream)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[109])(1, v1var_object) /*  VAR-NAME */;
  T1 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v1var_object) /*  VAR-KIND */;
  value0 = cl_format(4, v2stream, _ecl_static_13, T0, T1);
  return value0;
 }
}
/*	function definition for CMPPROGRESS                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L23cmpprogress(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1args;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1args = cl_grab_rest_args(args);
  ecl_va_end(args);
  if (Null(ecl_symbol_value(ECL_SYM("*COMPILE-VERBOSE*",29)))) { goto L1; }
  T0 = (ECL_SYM("FORMAT",387)->symbol.gfdef);
  value0 = cl_apply(3, T0, ECL_T, v1args);
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function CMPCK                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC24cmpck(cl_object v1, cl_object v2)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4condition;
   cl_object v5string;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4condition = v6;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5string = v6;
   }
   T0 = cl_listX(3, VV[45], v5string, v3);
   value0 = cl_list(3, ECL_SYM("IF",946), v4condition, T0);
   return value0;
  }
 }
}
/*	local function CMPASSERT                                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC25cmpassert(cl_object v1, cl_object v2)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4condition;
   cl_object v5string;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4condition = v6;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5string = v6;
   }
   T0 = cl_listX(3, VV[45], v5string, v3);
   value0 = cl_list(3, ECL_SYM("UNLESS",883), v4condition, T0);
   return value0;
  }
 }
}
/*	function definition for CMPERR                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L26cmperr(cl_narg narg, cl_object v1string, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2args;
  ecl_va_list args; ecl_va_start(args,v1string,narg,1);
  v2args = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v3c;
   v3c = (cl_env_copy->function=(ECL_SYM("MAKE-CONDITION",524)->symbol.gfdef))->cfun.entry(5, VV[16], ECL_SYM("FORMAT-CONTROL",1240), v1string, ECL_SYM("FORMAT-ARGUMENTS",1239), v2args) /*  MAKE-CONDITION */;
   (cl_env_copy->function=(ECL_SYM("SIGNAL",760)->symbol.gfdef))->cfun.entry(1, v3c) /*  SIGNAL */;
   L12print_compiler_message(v3c, ECL_T);
   value0 = cl_abort(0);
   return value0;
  }
 }
}
/*	function definition for SAFE-LIST-LENGTH                      */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object L27safe_list_length(cl_object v1l)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v2slow;
  v2slow = v1l;
  {
   cl_object v3fast;
   v3fast = v1l;
   {
    cl_object v4flag;
    v4flag = ECL_T;
    {
     cl_fixnum v5l;
     v5l = 0;
L5:;
     if (!(v3fast==ECL_NIL)) { goto L8; }
     value0 = ecl_make_fixnum(v5l);
     cl_env_copy->nvalues = 1;
     return value0;
L8:;
     if (ECL_CONSP(v3fast)) { goto L10; }
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 1;
     return value0;
L10:;
     if (Null(v4flag)) { goto L12; }
     v4flag = ECL_NIL;
     v3fast = ECL_CONS_CDR(v3fast);
     goto L7;
L12:;
     if (!((v2slow)==(v3fast))) { goto L17; }
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 1;
     return value0;
L17:;
     v4flag = ECL_T;
     v2slow = ECL_CONS_CDR(v2slow);
     v3fast = ECL_CONS_CDR(v3fast);
L7:;
     v5l = (v5l)+1;
     goto L5;
     value0 = ecl_make_fixnum(v5l);
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
  }
 }
}
/*	function definition for CHECK-ARGS-NUMBER                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L28check_args_number(cl_narg narg, cl_object v1operator, cl_object v2args, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>4)) FEwrong_num_arguments_anonym();
 {
  cl_object v3min;
  cl_object v4max;
  va_list args; va_start(args,v2args);
  {
   int i = 2;
   if (i >= narg) {
    v3min = ecl_make_fixnum(0);
   } else {
    i++;
    v3min = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v4max = ecl_make_fixnum(2305843009213693951);
   } else {
    i++;
    v4max = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v5l;
   v5l = L27safe_list_length(v2args);
   if (!(v5l==ECL_NIL)) { goto L4; }
   ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-CIRCLE*",47),ECL_T); /*  *PRINT-CIRCLE* */
   L26cmperr(3, _ecl_static_14, v1operator, v2args);
   ecl_bds_unwind1(cl_env_copy);
L4:;
   if (!(ecl_number_compare(v5l,v3min)<0)) { goto L6; }
   L30too_few_args(v1operator, v3min, v5l);
L6:;
   if (Null(v4max)) { goto L8; }
   if (!(ecl_number_compare(v5l,v4max)>0)) { goto L8; }
   value0 = L29too_many_args(v1operator, v4max, v5l);
   return value0;
L8:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for TOO-MANY-ARGS                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L29too_many_args(cl_object v1name, cl_object v2upper_bound, cl_object v3n)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-CASE*",46),ECL_SYM("UPCASE",1322)); /*  *PRINT-CASE* */
  value0 = L26cmperr(4, _ecl_static_15, v1name, v2upper_bound, v3n);
  ecl_bds_unwind1(cl_env_copy);
  return value0;
 }
}
/*	function definition for TOO-FEW-ARGS                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L30too_few_args(cl_object v1name, cl_object v2lower_bound, cl_object v3n)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L26cmperr(4, _ecl_static_16, v1name, v2lower_bound, v3n);
  return value0;
 }
}
/*	function definition for DO-CMPWARN                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L33do_cmpwarn(volatile cl_narg narg, ...)
{
 cl_object T0, T1, T2, T3, T4;
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  volatile cl_object v1args;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1args = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   volatile cl_object v2condition;
   T0 = (ECL_SYM("MAKE-CONDITION",524)->symbol.gfdef);
   v2condition = cl_apply(2, T0, v1args);
   {
    volatile cl_object env1 = env0;
    env1 = ECL_NIL;
    CLV0 = env1 = CONS(ECL_NIL,env1);
    {
     volatile cl_object env2 = env1;
     CLV1 = env2 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env2); /*  TAGBODY */
     if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV1))) {
     if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L4;
     ecl_internal_error("GO found an inexistent tag");
     }
     {cl_object v3;
      v3 = ECL_NIL;
      v3 = ecl_make_cclosure_va((cl_objectfn)LC31__g77,env2,Cblock);
      T0 = v3;
     }
     {cl_object v3;
      v3 = ECL_NIL;
      v3 = ecl_make_cfun((cl_objectfn_fixed)LC32__g78,ECL_NIL,Cblock,1);
      T1 = v3;
     }
     T2 = ecl_function_dispatch(cl_env_copy,VV[119])(6, ECL_SYM("NAME",1273), ECL_SYM("MUFFLE-WARNING",571), ECL_SYM("FUNCTION",1241), T0, VV[53], T1) /*  MAKE-RESTART */;
     T3 = ecl_list1(T2);
     T4 = CONS(T3,ecl_symbol_value(ECL_SYM("*RESTART-CLUSTERS*",4)));
     ecl_bds_bind(cl_env_copy,ECL_SYM("*RESTART-CLUSTERS*",4),T4); /*  *RESTART-CLUSTERS* */
     T0 = ecl_car(ecl_symbol_value(ECL_SYM("*RESTART-CLUSTERS*",4)));
     T1 = CONS(v2condition,T0);
     T2 = CONS(T1,ecl_symbol_value(VV[54]));
     ecl_bds_bind(cl_env_copy,VV[54],T2);         /*  *CONDITION-RESTARTS* */
     (cl_env_copy->function=(ECL_SYM("SIGNAL",760)->symbol.gfdef))->cfun.entry(1, v2condition) /*  SIGNAL */;
     ecl_frs_pop(cl_env_copy);
     ecl_bds_unwind1(cl_env_copy);
     ecl_bds_unwind1(cl_env_copy);
     goto L3;
L4:;
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 1;
     ecl_frs_pop(cl_env_copy);
     return value0;
    }
   }
L3:;
   value0 = L12print_compiler_message(v2condition, ECL_T);
   return value0;
  }
 }
}
/*	closure G77                                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC31__g77(cl_narg narg, ...)
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
 {
  cl_object v1si__temp;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1si__temp = cl_grab_rest_args(args);
  ecl_va_end(args);
  ECL_CONS_CAR(CLV0) = v1si__temp;
  cl_go(ECL_CONS_CAR(CLV1),ecl_make_fixnum(0));
 }
 }
}
/*	local function G78                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC32__g78(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_write_string(2, _ecl_static_17, v1stream);
  return value0;
 }
}
/*	function definition for CMPWARN-STYLE                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L34cmpwarn_style(cl_narg narg, cl_object v1string, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2args;
  ecl_va_list args; ecl_va_start(args,v1string,narg,1);
  v2args = cl_grab_rest_args(args);
  ecl_va_end(args);
  value0 = L33do_cmpwarn(5, VV[19], ECL_SYM("FORMAT-CONTROL",1240), v1string, ECL_SYM("FORMAT-ARGUMENTS",1239), v2args);
  return value0;
 }
}
/*	function definition for CMPWARN                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L35cmpwarn(cl_narg narg, cl_object v1string, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2args;
  ecl_va_list args; ecl_va_start(args,v1string,narg,1);
  v2args = cl_grab_rest_args(args);
  ecl_va_end(args);
  value0 = L33do_cmpwarn(5, VV[14], ECL_SYM("FORMAT-CONTROL",1240), v1string, ECL_SYM("FORMAT-ARGUMENTS",1239), v2args);
  return value0;
 }
}
/*	function definition for CMPNOTE                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L36cmpnote(cl_narg narg, cl_object v1string, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2args;
  ecl_va_list args; ecl_va_start(args,v1string,narg,1);
  v2args = cl_grab_rest_args(args);
  ecl_va_end(args);
  value0 = L33do_cmpwarn(5, VV[12], ECL_SYM("FORMAT-CONTROL",1240), v1string, ECL_SYM("FORMAT-ARGUMENTS",1239), v2args);
  return value0;
 }
}
/*	function definition for CMPDEBUG                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L37cmpdebug(cl_narg narg, cl_object v1string, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2args;
  ecl_va_list args; ecl_va_start(args,v1string,narg,1);
  v2args = cl_grab_rest_args(args);
  ecl_va_end(args);
  value0 = L33do_cmpwarn(5, VV[13], ECL_SYM("FORMAT-CONTROL",1240), v1string, ECL_SYM("FORMAT-ARGUMENTS",1239), v2args);
  return value0;
 }
}
/*	function definition for PRINT-CURRENT-FORM                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L38print_current_form()
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_symbol_value(ECL_SYM("*COMPILE-PRINT*",28)))) { goto L1; }
  ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-LENGTH*",50),ecl_make_fixnum(2)); /*  *PRINT-LENGTH* */
  ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-LEVEL*",51),ecl_make_fixnum(2)); /*  *PRINT-LEVEL* */
  T0 = L2innermost_non_expanded_form(ecl_symbol_value(VV[10]));
  cl_format(3, ECL_T, _ecl_static_18, T0);
  ecl_bds_unwind1(cl_env_copy);
  ecl_bds_unwind1(cl_env_copy);
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for PRINT-EMITTING                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L39print_emitting(cl_object v1f)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_symbol_value(ECL_SYM("*COMPILE-PRINT*",28)))) { goto L1; }
  {
   cl_object v2name;
   value0 = ecl_function_dispatch(cl_env_copy,VV[126])(1, v1f) /*  FUN-NAME */;
   if ((value0)!=ECL_NIL) { goto L5; }
   v2name = ecl_function_dispatch(cl_env_copy,VV[127])(1, v1f) /*  FUN-DESCRIPTION */;
   goto L3;
L5:;
   v2name = value0;
   goto L3;
L3:;
   if (Null(v2name)) { goto L7; }
   value0 = cl_format(3, ECL_T, _ecl_static_19, v2name);
   return value0;
L7:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for UNDEFINED-VARIABLE                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L40undefined_variable(cl_object v1sym)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L33do_cmpwarn(3, VV[20], ECL_SYM("NAME",1273), v1sym);
  return value0;
 }
}
/*	function definition for BABOON                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L41baboon(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1format_control;
  cl_object v2format_arguments;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L41baboonkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[2])) {
    v1format_control = _ecl_static_20;
   } else {
    v1format_control = keyvars[0];
   }
   v2format_arguments = keyvars[1];
  }
  value0 = (cl_env_copy->function=(ECL_SYM("SIGNAL",760)->symbol.gfdef))->cfun.entry(5, VV[18], ECL_SYM("FORMAT-CONTROL",1240), v1format_control, ECL_SYM("FORMAT-ARGUMENTS",1239), v2format_arguments) /*  SIGNAL */;
  return value0;
 }
}
/*	local function WITH-CMP-PROTECTION                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC42with_cmp_protection(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4main_form;
   cl_object v5error_form;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4main_form = v6;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5error_form = v6;
   }
   if (Null(v3)) { goto L14; }
   si_dm_too_many_arguments(v1);
L14:;
   T0 = cl_list(3, ECL_SYM("HANDLER-BIND",417), VV[64], v4main_form);
   T1 = cl_list(4, ECL_SYM("IF",946), VV[27], T0, v4main_form);
   T2 = cl_list(3, ECL_SYM("MULTIPLE-VALUE-PROG1",575), T1, VV[65]);
   T3 = cl_list(3, ECL_SYM("WHEN",905), VV[66], v5error_form);
   T4 = cl_list(3, ECL_SYM("UNWIND-PROTECT",888), T2, T3);
   value0 = cl_list(3, ECL_SYM("LET*",478), VV[63], T4);
   return value0;
  }
 }
}
/*	function definition for CMP-EVAL                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L44cmp_eval(volatile cl_narg narg, cl_object volatile v1form, ...)
{
 cl_object T0, T1, T2, T3;
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  volatile cl_object v2env;
  va_list args; va_start(args,v1form);
  {
   int i = 1;
   if (i >= narg) {
    v2env = ecl_symbol_value(VV[68]);
   } else {
    i++;
    v2env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   volatile cl_object env1 = env0;
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(ECL_NIL,env1);
   CLV1 = env1 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env1); /*  TAGBODY */
   if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV1))) {
   if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L2;
   ecl_internal_error("GO found an inexistent tag");
   }
   {cl_object v3;
    v3 = ECL_NIL;
    v3 = ecl_make_cclosure_va((cl_objectfn)LC43__g93,env1,Cblock);
    T0 = v3;
   }
   T1 = CONS(ECL_SYM("SERIOUS-CONDITION",742),T0);
   T2 = ecl_list1(T1);
   T3 = CONS(T2,ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5)));
   ecl_bds_bind(cl_env_copy,ECL_SYM("*HANDLER-CLUSTERS*",5),T3); /*  *HANDLER-CLUSTERS* */
   value0 = si_eval_with_env(5, v1form, v2env, ECL_NIL, ECL_T, ECL_T);
   ecl_frs_pop(cl_env_copy);
   ecl_bds_unwind1(cl_env_copy);
   return value0;
L2:;
   {
    cl_object v3c;
    v3c = ECL_CONS_CAR(CLV0);
    if (Null(ecl_symbol_value(VV[27]))) { goto L7; }
    (cl_env_copy->function=(ECL_SYM("INVOKE-DEBUGGER",445)->symbol.gfdef))->cfun.entry(1, v3c) /*  INVOKE-DEBUGGER */;
L7:;
    L26cmperr(3, _ecl_static_21, v1form, v3c);
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    ecl_frs_pop(cl_env_copy);
    return value0;
   }
  }
 }
}
/*	closure G93                                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC43__g93(cl_narg narg, cl_object v1si__temp, ...)
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
/*	function definition for CMP-MACRO-FUNCTION                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L45cmp_macro_function(cl_object v1name)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[135])(1, v1name) /*  CMP-ENV-SEARCH-MACRO */;
  if ((value0)!=ECL_NIL) { goto L2; }
  value0 = cl_macro_function(1, v1name);
  return value0;
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for CMP-EXPAND-MACRO                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L47cmp_expand_macro(volatile cl_narg narg, cl_object volatile v1fd, cl_object volatile v2form, ...)
{
 cl_object T0, T1, T2, T3;
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  volatile cl_object v3env;
  va_list args; va_start(args,v2form);
  {
   int i = 2;
   if (i >= narg) {
    v3env = ecl_symbol_value(VV[68]);
   } else {
    i++;
    v3env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   volatile cl_object env1 = env0;
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(ECL_NIL,env1);
   CLV1 = env1 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env1); /*  TAGBODY */
   if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV1))) {
   if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L2;
   ecl_internal_error("GO found an inexistent tag");
   }
   {cl_object v4;
    v4 = ECL_NIL;
    v4 = ecl_make_cclosure_va((cl_objectfn)LC46__g97,env1,Cblock);
    T0 = v4;
   }
   T1 = CONS(ECL_SYM("SERIOUS-CONDITION",742),T0);
   T2 = ecl_list1(T1);
   T3 = CONS(T2,ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5)));
   ecl_bds_bind(cl_env_copy,ECL_SYM("*HANDLER-CLUSTERS*",5),T3); /*  *HANDLER-CLUSTERS* */
   {
    cl_object v4new_form;
    v4new_form = ecl_function_dispatch(cl_env_copy,ecl_symbol_value(ECL_SYM("*MACROEXPAND-HOOK*",40)))(3, v1fd, v2form, v3env);
    {
     bool v5;
     v5 = ecl_eql(v4new_form,v2form);
     T0 = (v5)?ECL_NIL:ECL_T;
    }
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = T0;
    cl_env_copy->values[0] = v4new_form;
    value0 = cl_env_copy->values[0];
    ecl_frs_pop(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    return value0;
   }
L2:;
   {
    cl_object v4c;
    v4c = ECL_CONS_CAR(CLV0);
    if (Null(ecl_symbol_value(VV[27]))) { goto L9; }
    (cl_env_copy->function=(ECL_SYM("INVOKE-DEBUGGER",445)->symbol.gfdef))->cfun.entry(1, v4c) /*  INVOKE-DEBUGGER */;
L9:;
    L26cmperr(3, _ecl_static_22, v2form, v4c);
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = ECL_NIL;
    cl_env_copy->values[0] = ECL_NIL;
    value0 = cl_env_copy->values[0];
    ecl_frs_pop(cl_env_copy);
    return value0;
   }
  }
 }
}
/*	closure G97                                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC46__g97(cl_narg narg, cl_object v1si__temp, ...)
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
/*	function definition for CMP-EXPAND-COMPILER-MACRO             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L49cmp_expand_compiler_macro(volatile cl_narg narg, cl_object volatile v1fd, cl_object volatile v2fname, cl_object volatile v3args, ...)
{
 cl_object T0, T1, T2, T3;
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>4)) FEwrong_num_arguments_anonym();
 {
  volatile cl_object v4env;
  va_list args; va_start(args,v3args);
  {
   int i = 3;
   if (i >= narg) {
    v4env = ecl_symbol_value(VV[68]);
   } else {
    i++;
    v4env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   volatile cl_object env1 = env0;
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(ECL_NIL,env1);
   CLV1 = env1 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env1); /*  TAGBODY */
   if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV1))) {
   if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L2;
   ecl_internal_error("GO found an inexistent tag");
   }
   {cl_object v5;
    v5 = ECL_NIL;
    v5 = ecl_make_cclosure_va((cl_objectfn)LC48__g101,env1,Cblock);
    T0 = v5;
   }
   T1 = CONS(ECL_SYM("SERIOUS-CONDITION",742),T0);
   T2 = ecl_list1(T1);
   T3 = CONS(T2,ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5)));
   ecl_bds_bind(cl_env_copy,ECL_SYM("*HANDLER-CLUSTERS*",5),T3); /*  *HANDLER-CLUSTERS* */
   T0 = CONS(v2fname,v3args);
   value0 = L47cmp_expand_macro(3, v1fd, T0, v4env);
   ecl_frs_pop(cl_env_copy);
   ecl_bds_unwind1(cl_env_copy);
   return value0;
L2:;
   {
    cl_object v5c;
    v5c = ECL_CONS_CAR(CLV0);
    T0 = cl_list(2, v2fname, v5c);
    L33do_cmpwarn(5, VV[15], ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_23, ECL_SYM("FORMAT-ARGUMENTS",1239), T0);
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = ECL_NIL;
    cl_env_copy->values[0] = ECL_NIL;
    value0 = cl_env_copy->values[0];
    ecl_frs_pop(cl_env_copy);
    return value0;
   }
  }
 }
}
/*	closure G101                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC48__g101(cl_narg narg, cl_object v1si__temp, ...)
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
/*	function definition for COMPILER-CLEAR-COMPILER-PROPERTIES    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L50si__compiler_clear_compiler_properties(cl_object v1symbol)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  si_rem_sysprop(v1symbol, VV[73]);
  si_rem_sysprop(v1symbol, VV[74]);
  si_rem_sysprop(v1symbol, VV[75]);
  si_rem_sysprop(v1symbol, VV[76]);
  si_rem_sysprop(v1symbol, VV[77]);
  si_rem_sysprop(v1symbol, VV[78]);
  si_rem_sysprop(v1symbol, VV[79]);
  si_rem_sysprop(v1symbol, VV[80]);
  si_rem_sysprop(v1symbol, VV[81]);
  value0 = si_rem_sysprop(v1symbol, VV[82]);
  return value0;
 }
}
/*	function definition for LISP-TO-C-NAME                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L52lisp_to_c_name(cl_object v1obj)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1obj)) { goto L2; }
  {cl_object v2;
   v2 = ECL_NIL;
   v2 = ecl_make_cfun((cl_objectfn_fixed)LC51__g102,ECL_NIL,Cblock,1);
   T0 = v2;
  }
  T1 = cl_prin1_to_string(v1obj);
  T2 = cl_string_downcase(1, T1);
  value0 = cl_map(3, ECL_SYM("STRING",805), T0, T2);
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G102                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC51__g102(cl_object v1c)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v2cc;
   v2cc = ecl_fixnum(cl_char_code(v1c));
   if (((97)<=(v2cc) && (v2cc)<=(122))) { goto L4; }
   if (!(((48)<=(v2cc) && (v2cc)<=(57)))) { goto L2; }
   goto L3;
L4:;
L3:;
   value0 = v1c;
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
   value0 = CODE_CHAR(95);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}

#include "cmp/cmputil.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclvN1x8aNAbT3p9_wwotVE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPUTIL.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclvN1x8aNAbT3p9_wwotVE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 si_Xmake_constant(VV[0], _ecl_static_1);
 si_Xmake_constant(VV[1], _ecl_static_2);
 si_Xmake_constant(VV[2], _ecl_static_3);
 si_Xmake_constant(VV[3], _ecl_static_4);
 ecl_cmp_defun(VV[85]);                           /*  BRIEF-NAMESTRING */
 ecl_cmp_defun(VV[86]);                           /*  INNERMOST-NON-EXPANDED-FORM */
 ecl_cmp_defun(VV[87]);                           /*  COMPILER-MESSAGE-REPORT */
 {
  cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC5__g9,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 T1 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T0, VVtemp[1]);
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC6__g11,ECL_NIL,Cblock,0);
  T2 = v1;
 }
 T3 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T2, VVtemp[4]);
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC7__g12,ECL_NIL,Cblock,0);
  T4 = v1;
 }
 T5 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T4, VVtemp[5]);
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC8__g13,ECL_NIL,Cblock,0);
  T6 = v1;
 }
 T7 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T6, VVtemp[6]);
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC9__g14,ECL_NIL,Cblock,0);
  T8 = v1;
 }
 T9 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T8, VVtemp[7]);
 T10 = cl_list(7, T1, VVtemp[2], VVtemp[3], T3, T5, T7, T9);
 clos_load_defclass(VV[8], VVtemp[0], T10, ECL_NIL);
 }
 clos_load_defclass(VV[12], VVtemp[8], ECL_NIL, ECL_NIL);
 clos_load_defclass(VV[13], VVtemp[9], ECL_NIL, ECL_NIL);
 clos_load_defclass(VV[14], VVtemp[10], VVtemp[11], ECL_NIL);
 clos_load_defclass(VV[15], VVtemp[12], ECL_NIL, ECL_NIL);
 clos_load_defclass(VV[16], VVtemp[8], VVtemp[13], ECL_NIL);
 clos_load_defclass(VV[17], VVtemp[14], VVtemp[15], ECL_NIL);
 clos_load_defclass(VV[18], VVtemp[16], VVtemp[17], ECL_NIL);
 clos_load_defclass(VV[19], VVtemp[10], VVtemp[18], ECL_NIL);
 {
  cl_object T0, T1, T2;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC11__g15,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 T1 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T0, VVtemp[20]);
 T2 = cl_list(2, T1, VVtemp[21]);
 clos_load_defclass(VV[20], VVtemp[19], T2, ECL_NIL);
 }
 ecl_cmp_defun(VV[93]);                           /*  PRINT-COMPILER-MESSAGE */
 ecl_cmp_defun(VV[94]);                           /*  HANDLE-COMPILER-NOTE */
 ecl_cmp_defun(VV[95]);                           /*  HANDLE-COMPILER-WARNING */
 ecl_cmp_defun(VV[96]);                           /*  HANDLE-COMPILER-ERROR */
 ecl_cmp_defun(VV[97]);                           /*  HANDLE-COMPILER-INTERNAL-ERROR */
 ecl_cmp_defun(VV[98]);                           /*  DO-COMPILATION-UNIT */
 ecl_cmp_defmacro(VV[100]);                       /*  WITH-COMPILATION-UNIT */
 ecl_cmp_defmacro(VV[101]);                       /*  WITH-COMPILER-ENV */
 si_Xmake_special(VV[40]);
 if (ecl_boundp(cl_env_copy,VV[40])) { goto L85; }
 cl_set(VV[40],ecl_make_fixnum(0));
L85:;
 ecl_cmp_defun(VV[102]);                          /*  PRINT-C1FORMS   */
 ecl_cmp_defun(VV[106]);                          /*  PRINT-REF       */
 ecl_cmp_defun(VV[108]);                          /*  PRINT-VAR       */
 ecl_cmp_defun(VV[111]);                          /*  CMPPROGRESS     */
 ecl_cmp_defmacro(VV[112]);                       /*  CMPCK           */
 ecl_cmp_defmacro(VV[113]);                       /*  CMPASSERT       */
 ecl_cmp_defun(VV[114]);                          /*  CMPERR          */
 ecl_cmp_defun(VV[115]);                          /*  SAFE-LIST-LENGTH */
 ecl_cmp_defun(VV[116]);                          /*  CHECK-ARGS-NUMBER */
 ecl_cmp_defun(VV[117]);                          /*  TOO-MANY-ARGS   */
 ecl_cmp_defun(VV[118]);                          /*  TOO-FEW-ARGS    */
 (void)0; /* No entry created for DO-CMPWARN */
 ecl_cmp_defun(VV[120]);                          /*  CMPWARN-STYLE   */
 ecl_cmp_defun(VV[121]);                          /*  CMPWARN         */
 ecl_cmp_defun(VV[122]);                          /*  CMPNOTE         */
 ecl_cmp_defun(VV[123]);                          /*  CMPDEBUG        */
 ecl_cmp_defun(VV[124]);                          /*  PRINT-CURRENT-FORM */
 ecl_cmp_defun(VV[125]);                          /*  PRINT-EMITTING  */
 ecl_cmp_defun(VV[128]);                          /*  UNDEFINED-VARIABLE */
 ecl_cmp_defun(VV[129]);                          /*  BABOON          */
 ecl_cmp_defmacro(VV[132]);                       /*  WITH-CMP-PROTECTION */
 ecl_cmp_defun(VV[133]);                          /*  CMP-EVAL        */
 ecl_cmp_defun(VV[134]);                          /*  CMP-MACRO-FUNCTION */
 ecl_cmp_defun(VV[136]);                          /*  CMP-EXPAND-MACRO */
 ecl_cmp_defun(VV[137]);                          /*  CMP-EXPAND-COMPILER-MACRO */
 ecl_cmp_defun(VV[138]);                          /*  COMPILER-CLEAR-COMPILER-PROPERTIES */
 ecl_cmp_defun(VV[139]);                          /*  LISP-TO-C-NAME  */
}
