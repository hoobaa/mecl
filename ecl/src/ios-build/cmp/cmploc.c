/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPLOC.LSP                                    */
#include <ecl/ecl-cmp.h>
#include "cmp/cmploc.eclh"
/*	function definition for TMP-DESTINATION                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1tmp_destination(cl_object v1loc)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!((v1loc)==(ECL_SYM("VALUES",895)))) { goto L1; }
  value0 = ECL_SYM("VALUES",895);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (!((v1loc)==(VV[0]))) { goto L3; }
  value0 = VV[0];
  cl_env_copy->nvalues = 1;
  return value0;
L3:;
  value0 = ECL_SYM("RETURN",724);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for PRECISE-LOC-TYPE                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2precise_loc_type(cl_object v1loc, cl_object v2new_type)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[68])(1, v1loc) /*  LOC-TYPE */;
  if (Null(cl_subtypep(2, T0, v2new_type))) { goto L1; }
  value0 = v1loc;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  value0 = cl_list(3, ECL_SYM("THE",856), v2new_type, v1loc);
  return value0;
 }
}
/*	function definition for LOC-IN-C1FORM-MOVABLE-P               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3loc_in_c1form_movable_p(cl_object v1loc)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ecl_eql(v1loc,ECL_T))) { goto L6; }
  goto L3;
  goto L4;
L6:;
  goto L4;
L4:;
  if (!((v1loc)==(ECL_NIL))) { goto L1; }
  goto L2;
L3:;
L2:;
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (!(ECL_FIXNUMP(v1loc))) { goto L9; }
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
L9:;
  if (!(ECL_STRINGP(v1loc))) { goto L11; }
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
L11:;
  if (Null(ecl_function_dispatch(cl_env_copy,VV[70])(1, v1loc) /*  VV-P */)) { goto L13; }
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
L13:;
  if (!((v1loc)==(VV[5]))) { goto L20; }
  goto L17;
  goto L18;
L20:;
  goto L18;
L18:;
  if (!((v1loc)==(ECL_SYM("VALUES",895)))) { goto L24; }
  goto L17;
  goto L22;
L24:;
  goto L22;
L22:;
  if (!((v1loc)==(VV[8]))) { goto L28; }
  goto L17;
  goto L26;
L28:;
  goto L26;
L26:;
  if (!((v1loc)==(VV[10]))) { goto L15; }
  goto L16;
L17:;
L16:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L15:;
  if (!(ECL_ATOM(v1loc))) { goto L31; }
  T0 = ecl_list1(v1loc);
  value0 = ecl_function_dispatch(cl_env_copy,VV[71])(4, ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_1, ECL_SYM("FORMAT-ARGUMENTS",1239), T0) /*  BABOON */;
  return value0;
L31:;
  T0 = ecl_car(v1loc);
  if (!((T0)==(ECL_SYM("THE",856)))) { goto L33; }
  v1loc = ecl_caddr(v1loc);
  goto TTL;
L33:;
  v1loc = ecl_car(v1loc);
  if (Null(ecl_memql(v1loc,VV[12]))) { goto L37; }
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
L37:;
  T0 = ecl_list1(v1loc);
  value0 = ecl_function_dispatch(cl_env_copy,VV[71])(4, ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_1, ECL_SYM("FORMAT-ARGUMENTS",1239), T0) /*  BABOON */;
  return value0;
 }
}
/*	function definition for USES-VALUES                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4uses_values(cl_object v1loc)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_CONSP(v1loc))) { goto L2; }
  {
   cl_object v2;
   v2 = ecl_car(v1loc);
   if (!((v2)==(VV[14]))) { goto L12; }
   value0 = VV[15];
   goto L10;
L12:;
   value0 = ECL_NIL;
   goto L10;
L10:;
   if ((value0)!=ECL_NIL) { goto L9; }
   if (!((v2)==(VV[16]))) { goto L16; }
   value0 = VV[17];
   goto L14;
L16:;
   value0 = ECL_NIL;
   goto L14;
L14:;
   if ((value0)!=ECL_NIL) { goto L9; }
   if (!((v2)==(VV[18]))) { goto L19; }
   value0 = VV[19];
   goto L6;
L19:;
   value0 = ECL_NIL;
   goto L6;
L9:;
   goto L6;
  }
L6:;
  if ((value0)!=ECL_NIL) { goto L5; }
  T0 = ecl_car(v1loc);
  if (!((T0)==(ECL_SYM("C-INLINE",1973)))) { goto L22; }
  T0 = ecl_cddddr(v1loc);
  T1 = ecl_cadr(T0);
  value0 = ecl_make_bool((T1)==(ECL_SYM("VALUES",895)));
  cl_env_copy->nvalues = 1;
  return value0;
L22:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L5:;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for LOC-IMMEDIATE-VALUE-P                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5loc_immediate_value_p(cl_object v1loc)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!((v1loc)==(ECL_T))) { goto L1; }
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = ECL_T;
  cl_env_copy->values[0] = ECL_T;
  return cl_env_copy->values[0];
L1:;
  if (!((v1loc)==(ECL_NIL))) { goto L3; }
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = ECL_NIL;
  cl_env_copy->values[0] = ECL_T;
  return cl_env_copy->values[0];
L3:;
  if (!(ECL_FIXNUMP(v1loc))) { goto L5; }
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = v1loc;
  cl_env_copy->values[0] = ECL_T;
  return cl_env_copy->values[0];
L5:;
  if (Null(ecl_function_dispatch(cl_env_copy,VV[70])(1, v1loc) /*  VV-P */)) { goto L7; }
  {
   cl_object v2value;
   v2value = ecl_function_dispatch(cl_env_copy,VV[74])(1, v1loc) /*  VV-VALUE */;
   if (v2value==ECL_NIL) { goto L12; }
   if (!(ECL_FIXNUMP(v2value))) { goto L10; }
   goto L11;
L12:;
L11:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = ECL_NIL;
   cl_env_copy->values[0] = ECL_NIL;
   return cl_env_copy->values[0];
L10:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v2value;
   cl_env_copy->values[0] = ECL_T;
   return cl_env_copy->values[0];
  }
L7:;
  if (!(ECL_ATOM(v1loc))) { goto L14; }
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = ECL_NIL;
  cl_env_copy->values[0] = ECL_NIL;
  return cl_env_copy->values[0];
L14:;
  T0 = ecl_car(v1loc);
  if (!((T0)==(ECL_SYM("THE",856)))) { goto L16; }
  v1loc = ecl_caddr(v1loc);
  goto TTL;
L16:;
  {
   cl_object v3;
   v3 = ecl_car(v1loc);
   if (!((v3)==(VV[21]))) { goto L26; }
   goto L23;
   goto L24;
L26:;
   goto L24;
L24:;
   if (!((v3)==(VV[23]))) { goto L30; }
   goto L23;
   goto L28;
L30:;
   goto L28;
L28:;
   if (!((v3)==(VV[25]))) { goto L34; }
   goto L23;
   goto L32;
L34:;
   goto L32;
L32:;
   if (!((v3)==(VV[27]))) { goto L20; }
   goto L21;
L23:;
  }
L21:;
  T0 = ecl_cadr(v1loc);
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = T0;
  cl_env_copy->values[0] = ECL_T;
  return cl_env_copy->values[0];
L20:;
  T0 = ecl_car(v1loc);
  if (!((T0)==(VV[29]))) { goto L37; }
  T0 = ecl_cadr(v1loc);
  T1 = cl_code_char(T0);
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = T1;
  cl_env_copy->values[0] = ECL_T;
  return cl_env_copy->values[0];
L37:;
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = ECL_NIL;
  cl_env_copy->values[0] = ECL_NIL;
  return cl_env_copy->values[0];
 }
}
/*	function definition for LOC-IMMEDIATE-VALUE                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6loc_immediate_value(cl_object v1loc)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   struct ecl_stack_frame _ecl_inner_frame_aux;
   cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
   {
    cl_object v2;
    v2 = _ecl_inner_frame;
    cl_env_copy->values[0] = L5loc_immediate_value_p(v1loc);
    ecl_stack_frame_push_values(v2);cl_env_copy->values[0]=ecl_apply_from_stack_frame(v2,ECL_SYM("LIST",481));
    value0 = cl_env_copy->values[0];
   }
   ecl_stack_frame_close(_ecl_inner_frame);
  }
  T0 = value0;
  value0 = ecl_cadr(T0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for UNKNOWN-LOCATION                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7unknown_location(cl_object v1where, cl_object v2loc)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, v1where, v2loc);
  value0 = ecl_function_dispatch(cl_env_copy,VV[71])(4, ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_2, ECL_SYM("FORMAT-ARGUMENTS",1239), T0) /*  BABOON */;
  return value0;
 }
}
/*	function definition for WT-LOC                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8wt_loc(cl_object v1loc)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_CONSP(v1loc))) { goto L1; }
  {
   cl_object v2fd;
   T0 = ecl_car(v1loc);
   v2fd = ecl_gethash_safe(T0,ecl_symbol_value(VV[33]),ECL_NIL);
   if (Null(v2fd)) { goto L4; }
   T0 = ecl_cdr(v1loc);
   value0 = cl_apply(2, v2fd, T0);
   return value0;
L4:;
   value0 = L7unknown_location(VV[34], v1loc);
   return value0;
  }
L1:;
  if (!(ECL_SYMBOLP(v1loc))) { goto L6; }
  {
   cl_object v3txt;
   v3txt = ecl_gethash_safe(v1loc,ecl_symbol_value(VV[33]),VV[35]);
   if (!((v3txt)==(VV[35]))) { goto L9; }
   L7unknown_location(VV[34], v1loc);
L9:;
   value0 = ecl_function_dispatch(cl_env_copy,VV[78])(1, v3txt) /*  WT */;
   return value0;
  }
L6:;
  if (!(ECL_STRINGP(v1loc))) { goto L11; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[78])(1, v1loc) /*  WT */;
  return value0;
L11:;
  if (Null(ecl_function_dispatch(cl_env_copy,VV[79])(1, v1loc) /*  VAR-P */)) { goto L13; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[80])(1, v1loc) /*  WT-VAR */;
  return value0;
L13:;
  if (Null(ecl_function_dispatch(cl_env_copy,VV[70])(1, v1loc) /*  VV-P */)) { goto L15; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[81])(1, v1loc) /*  WT-VV */;
  return value0;
L15:;
  value0 = L7unknown_location(VV[34], v1loc);
  return value0;
 }
}
/*	function definition for LAST-CALL-P                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L9last_call_p()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_memql(ecl_symbol_value(VV[37]),VV[38]);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for WT-LCL                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L10wt_lcl(cl_object v1lcl)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (ecl_numberp(v1lcl)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[71])(0)    /*  BABOON          */;
L1:;
  value0 = ecl_function_dispatch(cl_env_copy,VV[78])(2, _ecl_static_3, v1lcl) /*  WT */;
  return value0;
 }
}
/*	function definition for WT-LCL-LOC                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L11wt_lcl_loc(cl_narg narg, cl_object v1lcl, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v2type;
  cl_object v3name;
  va_list args; va_start(args,v1lcl);
  {
   int i = 1;
   if (i >= narg) {
    v2type = ECL_NIL;
   } else {
    i++;
    v2type = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v3name = ECL_NIL;
   } else {
    i++;
    v3name = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (ecl_numberp(v1lcl)) { goto L3; }
  ecl_function_dispatch(cl_env_copy,VV[71])(0)    /*  BABOON          */;
L3:;
  value0 = ecl_function_dispatch(cl_env_copy,VV[78])(3, _ecl_static_3, v1lcl, v3name) /*  WT */;
  return value0;
 }
}
/*	function definition for WT-TEMP                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L12wt_temp(cl_object v1temp)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[78])(2, _ecl_static_4, v1temp) /*  WT */;
  return value0;
 }
}
/*	function definition for WT-NUMBER                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L13wt_number(cl_narg narg, cl_object v1value, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2vv;
  va_list args; va_start(args,v1value);
  {
   int i = 1;
   if (i >= narg) {
    v2vv = ECL_NIL;
   } else {
    i++;
    v2vv = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = ecl_function_dispatch(cl_env_copy,VV[78])(1, v1value) /*  WT */;
  return value0;
 }
}
/*	function definition for WT-CHARACTER                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L14wt_character(cl_narg narg, cl_object v1value, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2vv;
  va_list args; va_start(args,v1value);
  {
   int i = 1;
   if (i >= narg) {
    v2vv = ECL_NIL;
   } else {
    i++;
    v2vv = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = ecl_function_dispatch(cl_env_copy,VV[78])(1, v1value) /*  WT */;
  return value0;
 }
}
/*	function definition for WT-VALUE                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L15wt_value(cl_object v1i)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[78])(3, _ecl_static_5, v1i, _ecl_static_6) /*  WT */;
  return value0;
 }
}
/*	function definition for WT-KEYVARS                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L16wt_keyvars(cl_object v1i)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[78])(3, _ecl_static_7, v1i, _ecl_static_6) /*  WT */;
  return value0;
 }
}
/*	function definition for WT-THE                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L17wt_the(cl_object v1type, cl_object v2loc)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L8wt_loc(v2loc);
  return value0;
 }
}
/*	function definition for LOC-REFERS-TO-SPECIAL                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L18loc_refers_to_special(cl_object v1loc)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[79])(1, v1loc) /*  VAR-P */)) { goto L1; }
  {
   cl_object v2;
   v2 = ecl_function_dispatch(cl_env_copy,VV[92])(1, v1loc) /*  VAR-KIND */;
   if (!((v2)==(ECL_SYM("SPECIAL",789)))) { goto L8; }
   value0 = VV[48];
   goto L6;
L8:;
   value0 = ECL_NIL;
   goto L6;
L6:;
   if ((value0)!=ECL_NIL) { goto L5; }
   if (!((v2)==(VV[49]))) { goto L11; }
   value0 = VV[50];
   cl_env_copy->nvalues = 1;
   return value0;
L11:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L5:;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L1:;
  if (!(ECL_ATOM(v1loc))) { goto L13; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L13:;
  T0 = ecl_car(v1loc);
  if (!((T0)==(ECL_SYM("THE",856)))) { goto L15; }
  v1loc = ecl_caddr(v1loc);
  goto TTL;
L15:;
  v1loc = ecl_car(v1loc);
  if (!((v1loc)==(VV[51]))) { goto L19; }
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
L19:;
  if (!((v1loc)==(ECL_SYM("C-INLINE",1973)))) { goto L22; }
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
L22:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for VALUES-LOC                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L19values_loc(cl_object v1n)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_list(2, VV[53], v1n);
  return value0;
 }
}
/*	function definition for SET-UNKNOWN-LOC                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L20set_unknown_loc(cl_object v1loc)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L7unknown_location(VV[55], ecl_symbol_value(VV[56]));
  return value0;
 }
}
/*	function definition for SET-LOC                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L21set_loc(cl_object v1loc)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2destination;
   v2destination = ecl_symbol_value(VV[56]);
   {
    cl_object v3;
    v3 = ecl_make_bool((v2destination)==(v1loc));
    if (Null(v3)) { goto L3; }
    value0 = v3;
    cl_env_copy->nvalues = 1;
    return value0;
L3:;
    if (!(ECL_SYMBOLP(v2destination))) { goto L5; }
    T0 = ecl_gethash_safe(v2destination,ecl_symbol_value(VV[58]),VV[57]);
    value0 = ecl_function_dispatch(cl_env_copy,T0)(1, v1loc);
    return value0;
L5:;
    if (Null(ecl_function_dispatch(cl_env_copy,VV[79])(1, v2destination) /*  VAR-P */)) { goto L8; }
    value0 = ecl_function_dispatch(cl_env_copy,VV[96])(2, v1loc, v2destination) /*  SET-VAR */;
    return value0;
L8:;
    if (Null(ecl_function_dispatch(cl_env_copy,VV[70])(1, v2destination) /*  VV-P */)) { goto L10; }
    value0 = ecl_function_dispatch(cl_env_copy,VV[97])(2, v1loc, v2destination) /*  SET-VV */;
    return value0;
L10:;
    if (!(ECL_ATOM(v2destination))) { goto L12; }
    value0 = L7unknown_location(VV[55], v2destination);
    return value0;
L12:;
    {
     cl_object v4fd;
     T0 = ecl_car(v2destination);
     v4fd = ecl_gethash_safe(T0,ecl_symbol_value(VV[58]),ECL_NIL);
     if (Null(v4fd)) { goto L15; }
     T0 = ecl_cdr(v2destination);
     value0 = cl_apply(3, v4fd, v1loc, T0);
     return value0;
L15:;
     ecl_function_dispatch(cl_env_copy,VV[98])(0) /*  WT-NL           */;
     L8wt_loc(v2destination);
     ecl_function_dispatch(cl_env_copy,VV[78])(1, _ecl_static_8) /*  WT */;
     T0 = ecl_function_dispatch(cl_env_copy,VV[99])(1, ecl_symbol_value(VV[56])) /*  LOC-REPRESENTATION-TYPE */;
     ecl_function_dispatch(cl_env_copy,VV[100])(2, T0, v1loc) /*  WT-COERCE-LOC */;
     value0 = ecl_function_dispatch(cl_env_copy,VV[78])(1, _ecl_static_9) /*  WT */;
     return value0;
    }
   }
  }
 }
}
/*	function definition for SET-THE-LOC                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L22set_the_loc(cl_object v1loc, cl_object v2type, cl_object v3orig_loc)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_bds_bind(cl_env_copy,VV[56],v3orig_loc);    /*  *DESTINATION*   */
  value0 = L21set_loc(v1loc);
  ecl_bds_unwind1(cl_env_copy);
  return value0;
 }
}
/*	function definition for SET-VALUES-LOC                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L23set_values_loc(cl_object v1loc)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   v2 = ecl_make_bool((v1loc)==(ECL_SYM("VALUES",895)));
   if (Null(v2)) { goto L2; }
   value0 = v2;
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
   if (Null(L4uses_values(v1loc))) { goto L4; }
   ecl_function_dispatch(cl_env_copy,VV[98])(1, _ecl_static_10) /*  WT-NL */;
   ecl_function_dispatch(cl_env_copy,VV[100])(2, ECL_SYM("OBJECT",1278), v1loc) /*  WT-COERCE-LOC */;
   value0 = ecl_function_dispatch(cl_env_copy,VV[78])(1, _ecl_static_9) /*  WT */;
   return value0;
L4:;
   ecl_function_dispatch(cl_env_copy,VV[98])(1, _ecl_static_10) /*  WT-NL */;
   ecl_function_dispatch(cl_env_copy,VV[100])(2, ECL_SYM("OBJECT",1278), v1loc) /*  WT-COERCE-LOC */;
   ecl_function_dispatch(cl_env_copy,VV[78])(1, _ecl_static_9) /*  WT */;
   value0 = ecl_function_dispatch(cl_env_copy,VV[98])(1, _ecl_static_11) /*  WT-NL */;
   return value0;
  }
 }
}
/*	function definition for SET-VALUE0-LOC                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L24set_value0_loc(cl_object v1loc)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_function_dispatch(cl_env_copy,VV[98])(1, _ecl_static_12) /*  WT-NL */;
  ecl_function_dispatch(cl_env_copy,VV[100])(2, ECL_SYM("OBJECT",1278), v1loc) /*  WT-COERCE-LOC */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[78])(1, _ecl_static_9) /*  WT */;
  return value0;
 }
}
/*	function definition for SET-RETURN-LOC                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L25set_return_loc(cl_object v1loc)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((v1loc)==(ECL_SYM("VALUES",895))) { goto L3; }
  if (Null(L4uses_values(v1loc))) { goto L1; }
  goto L2;
L3:;
L2:;
  ecl_function_dispatch(cl_env_copy,VV[98])(1, _ecl_static_12) /*  WT-NL */;
  ecl_function_dispatch(cl_env_copy,VV[100])(2, ECL_SYM("OBJECT",1278), v1loc) /*  WT-COERCE-LOC */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[78])(1, _ecl_static_9) /*  WT */;
  return value0;
L1:;
  if (!((v1loc)==(VV[5]))) { goto L7; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[98])(1, _ecl_static_11) /*  WT-NL */;
  return value0;
L7:;
  {
   cl_object v2;
   v2 = ecl_make_bool((v1loc)==(ECL_SYM("RETURN",724)));
   if (Null(v2)) { goto L10; }
   value0 = v2;
   cl_env_copy->nvalues = 1;
   return value0;
L10:;
   ecl_function_dispatch(cl_env_copy,VV[98])(1, _ecl_static_12) /*  WT-NL */;
   ecl_function_dispatch(cl_env_copy,VV[100])(2, ECL_SYM("OBJECT",1278), v1loc) /*  WT-COERCE-LOC */;
   ecl_function_dispatch(cl_env_copy,VV[78])(1, _ecl_static_9) /*  WT */;
   value0 = ecl_function_dispatch(cl_env_copy,VV[98])(1, _ecl_static_11) /*  WT-NL */;
   return value0;
  }
 }
}
/*	function definition for LOC-WITH-SIDE-EFFECTS-P               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L26loc_with_side_effects_p(cl_object v1loc)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2name;
   v2name = ECL_NIL;
   if (Null(ecl_function_dispatch(cl_env_copy,VV[79])(1, v1loc) /*  VAR-P */)) { goto L2; }
   if (Null(ecl_function_dispatch(cl_env_copy,VV[106])(1, v1loc) /*  GLOBAL-VAR-P */)) { goto L5; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[107])(0) /*  POLICY-GLOBAL-VAR-CHECKING */;
   return value0;
L5:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
   if (!(ECL_ATOM(v1loc))) { goto L7; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L7:;
   {
    cl_object v3;
    v2name = ecl_car(v1loc);
    v3 = v2name;
    if (!((v3)==(VV[14]))) { goto L16; }
    goto L13;
    goto L14;
L16:;
    goto L14;
L14:;
    if (!((v3)==(VV[16]))) { goto L20; }
    goto L13;
    goto L18;
L20:;
    goto L18;
L18:;
    if (!((v3)==(VV[18]))) { goto L9; }
    goto L10;
L13:;
   }
L10:;
   value0 = ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
L9:;
   if (!((v2name)==(ECL_SYM("THE",856)))) { goto L23; }
   v1loc = ecl_caddr(v1loc);
   goto TTL;
L23:;
   if (!((v2name)==(ECL_SYM("FDEFINITION",349)))) { goto L27; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[108])(0) /*  POLICY-GLOBAL-FUNCTION-CHECKING */;
   return value0;
L27:;
   if (!((v2name)==(ECL_SYM("C-INLINE",1973)))) { goto L29; }
   T0 = ecl_cddddr(v1loc);
   T1 = ecl_cadr(T0);
   value0 = ecl_make_bool((T1)==(ECL_SYM("VALUES",895)));
   if ((value0)!=ECL_NIL) { goto L32; }
   T0 = ecl_cddddr(v1loc);
   value0 = ecl_car(T0);
   cl_env_copy->nvalues = 1;
   return value0;
L32:;
   cl_env_copy->nvalues = 1;
   return value0;
L29:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for SET-TRASH-LOC                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L27set_trash_loc(cl_object v1loc)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(L26loc_with_side_effects_p(v1loc))) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[98])(2, v1loc, _ecl_static_9) /*  WT-NL */;
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}

#include "cmp/cmploc.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclFC7xybqSwcjn9_twyTOE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPLOC.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclFC7xybqSwcjn9_twyTOE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[66]);                           /*  TMP-DESTINATION */
 ecl_cmp_defun(VV[67]);                           /*  PRECISE-LOC-TYPE */
 ecl_cmp_defun(VV[69]);                           /*  LOC-IN-C1FORM-MOVABLE-P */
 ecl_cmp_defun(VV[72]);                           /*  USES-VALUES     */
 ecl_cmp_defun(VV[73]);                           /*  LOC-IMMEDIATE-VALUE-P */
 ecl_cmp_defun(VV[75]);                           /*  LOC-IMMEDIATE-VALUE */
 ecl_cmp_defun(VV[76]);                           /*  UNKNOWN-LOCATION */
 ecl_cmp_defun(VV[77]);                           /*  WT-LOC          */
 ecl_cmp_defun(VV[82]);                           /*  LAST-CALL-P     */
 ecl_cmp_defun(VV[83]);                           /*  WT-LCL          */
 ecl_cmp_defun(VV[84]);                           /*  WT-LCL-LOC      */
 ecl_cmp_defun(VV[85]);                           /*  WT-TEMP         */
 ecl_cmp_defun(VV[86]);                           /*  WT-NUMBER       */
 ecl_cmp_defun(VV[87]);                           /*  WT-CHARACTER    */
 ecl_cmp_defun(VV[88]);                           /*  WT-VALUE        */
 ecl_cmp_defun(VV[89]);                           /*  WT-KEYVARS      */
 ecl_cmp_defun(VV[90]);                           /*  WT-THE          */
 ecl_cmp_defun(VV[91]);                           /*  LOC-REFERS-TO-SPECIAL */
 ecl_cmp_defun(VV[93]);                           /*  VALUES-LOC      */
 ecl_cmp_defun(VV[94]);                           /*  SET-UNKNOWN-LOC */
 ecl_cmp_defun(VV[95]);                           /*  SET-LOC         */
 ecl_cmp_defun(VV[101]);                          /*  SET-THE-LOC     */
 ecl_cmp_defun(VV[102]);                          /*  SET-VALUES-LOC  */
 ecl_cmp_defun(VV[103]);                          /*  SET-VALUE0-LOC  */
 ecl_cmp_defun(VV[104]);                          /*  SET-RETURN-LOC  */
 ecl_cmp_defun(VV[105]);                          /*  LOC-WITH-SIDE-EFFECTS-P */
 ecl_cmp_defun(VV[109]);                          /*  SET-TRASH-LOC   */
}
