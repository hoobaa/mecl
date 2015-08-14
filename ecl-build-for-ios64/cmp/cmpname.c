/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPNAME.LSP                                   */
#include <ecl/ecl-cmp.h>
#include "cmp/cmpname.eclh"
/*	function definition for ENCODE-NUMBER-IN-NAME                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1encode_number_in_name(cl_object v1number)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ecl_zerop(v1number))) { goto L1; }
  value0 = _ecl_static_1;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (!(ecl_minusp(v1number))) { goto L3; }
  v1number = ecl_negate(v1number);
  goto TTL;
L3:;
  {
   cl_fixnum v2base;
   cl_object v3output;
   cl_object v4digit;
   v2base = ecl_length(_ecl_static_2);
   v3output = ECL_NIL;
   v4digit = ecl_make_fixnum(0);
   goto L12;
L11:;
   value0 = ecl_floor2(v1number,ecl_make_fixnum(v2base));
   v1number = value0;
   v4digit = cl_env_copy->values[1];
   T0 = cl_char(_ecl_static_2, v4digit);
   v3output = CONS(T0,v3output);
L12:;
   if (ecl_zerop(v1number)) { goto L18; }
   goto L11;
L18:;
   T0 = cl_nreverse(v3output);
   value0 = si_coerce_to_vector(T0, ECL_SYM("BASE-CHAR",120), ECL_SYM("*",18), ECL_NIL);
   return value0;
  }
 }
}
/*	function definition for UNIQUE-INIT-NAME                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2unique_init_name(cl_object v1file)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2path;
   cl_object v3path_hash;
   cl_object v4seconds;
   cl_object v5ms;
   cl_object v6tag;
   v2path = cl_pathname(v1file);
   T0 = cl_sxhash(v2path);
   T1 = cl_ash(T0, ecl_make_fixnum(8));
   T2 = cl_pathname_directory(1, v2path);
   T3 = ecl_cddr(T2);
   T4 = cl_sxhash(T3);
   T5 = cl_ash(T4, ecl_make_fixnum(16));
   T6 = cl_pathname_name(1, v2path);
   T7 = cl_sxhash(T6);
   v3path_hash = cl_logxor(3, T1, T5, T7);
   v4seconds = cl_get_universal_time();
   T0 = ecl_times(v4seconds,ecl_make_fixnum(1000));
   T1 = cl_get_internal_real_time();
   T2 = ecl_times(ecl_make_fixnum(1000),T1);
   T3 = ecl_floor2(T2,ecl_make_fixnum(1000));
   T4 = (ecl_floor2(T3,ecl_make_fixnum(1000)),cl_env_copy->values[1]);
   v5ms = ecl_plus(T0,T4);
   T0 = L1encode_number_in_name(v3path_hash);
   T1 = L1encode_number_in_name(v5ms);
   v6tag = cl_concatenate(5, ECL_SYM("BASE-STRING",121), _ecl_static_3, T0, _ecl_static_4, T1);
   value0 = v6tag;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for INIT-NAME-TAG                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3init_name_tag(cl_object v1init_name)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_concatenate(5, ECL_SYM("BASE-STRING",121), _ecl_static_5, _ecl_static_6, v1init_name, _ecl_static_7);
  return value0;
 }
}
/*	function definition for SEARCH-TAG                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4search_tag(cl_object v1stream, cl_object v2tag)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3key;
   cl_object v4string;
   v3key = cl_concatenate(3, ECL_SYM("LIST",481), v2tag, _ecl_static_6);
   v4string = v3key;
   goto L5;
L4:;
   {
    cl_object v5c;
    v5c = cl_read_byte(3, v1stream, ECL_NIL, ECL_NIL);
    if (!(v5c==ECL_NIL)) { goto L9; }
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
L9:;
    {
     cl_object v6;
     v6 = v4string;
     if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
     if (Null(v6)) { goto L17; }
     {
      cl_object v7;
      v7 = ECL_CONS_CDR(v6);
      v4string = v7;
      v6 = ECL_CONS_CAR(v6);
     }
L17:;
     T0 = v6;
    }
    T1 = cl_char_code(T0);
    if (ecl_number_equalp(v5c,T1)) { goto L11; }
    v4string = v3key;
    goto L7;
L11:;
    if (!(v4string==ECL_NIL)) { goto L7; }
    value0 = ECL_T;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L7:;
L5:;
   goto L4;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for READ-NAME                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5read_name(cl_object v1stream)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2c;
   v2c = ECL_T;
   {
    cl_object v3;
    cl_object v4;
    v3 = ecl_list1(ECL_NIL);
    v4 = v3;
L5:;
    v2c = cl_read_byte(3, v1stream, ECL_NIL, ECL_NIL);
    if (v2c==ECL_NIL) { goto L9; }
    if (!(ecl_number_equalp(v2c,ecl_make_fixnum(64)))) { goto L7; }
    goto L8;
L9:;
L8:;
    goto L6;
L7:;
    if (ecl_unlikely(ECL_ATOM(v4))) FEtype_error_cons(v4);
    T1 = v4;
    T2 = cl_code_char(v2c);
    v4 = ecl_list1(T2);
    (ECL_CONS_CDR(T1)=v4,T1);
    goto L5;
L6:;
    T0 = ecl_cdr(v3);
    goto L1;
   }
  }
L1:;
  value0 = cl_concatenate(2, ECL_SYM("STRING",805), T0);
  return value0;
 }
}
/*	function definition for FIND-INIT-NAME                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6find_init_name(volatile cl_narg narg, cl_object volatile v1file, ...)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  volatile cl_object v2tag;
  ecl_va_list args; ecl_va_start(args,v1file,narg,1);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L6find_init_namekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[1])) {
    v2tag = _ecl_static_5;
   } else {
    v2tag = keyvars[0];
   }
  }
  if (Null(ecl_memql(VV[2],ecl_symbol_value(ECL_SYM("*FEATURES*",34))))) { goto L2; }
  {
   cl_object v3pnacl_dis;
   cl_object v4stream;
   value0 = si_getenv(_ecl_static_8);
   if ((value0)!=ECL_NIL) { goto L6; }
   v3pnacl_dis = cl_error(1, _ecl_static_9);
   goto L4;
L6:;
   v3pnacl_dis = value0;
   goto L4;
L4:;
   T0 = cl_translate_logical_pathname(1, v1file);
   T1 = cl_namestring(T0);
   T2 = ecl_list1(T1);
   v4stream = si_run_program(10, v3pnacl_dis, T2, ECL_SYM("WAIT",1329), ECL_NIL, ECL_SYM("INPUT",1254), ECL_NIL, ECL_SYM("OUTPUT",1282), ECL_SYM("STREAM",1313), ECL_SYM("ERROR",1229), ECL_SYM("OUTPUT",1282));
   if ((v4stream)!=ECL_NIL) { goto L9; }
   cl_error(2, _ecl_static_10, v1file);
L9:;
   if (Null(L4search_tag(v4stream, v2tag))) { goto L11; }
   {
    cl_object v5name;
    v5name = L5read_name(v4stream);
    value0 = v5name;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L11:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L2:;
  {
   volatile cl_object v6stream;
   v6stream = cl_open(5, v1file, ECL_SYM("DIRECTION",1218), ECL_SYM("INPUT",1254), ECL_SYM("ELEMENT-TYPE",1224), VV[3]);
   {
    volatile bool unwinding = FALSE;
    cl_index v7=ECL_STACK_INDEX(cl_env_copy),v8;
    ecl_frame_ptr next_fr;
    if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
      unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
    } else {
    {
     struct ecl_stack_frame _ecl_inner_frame_aux;
     volatile cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
     {
      cl_object v9;
      v9 = _ecl_inner_frame;
      if (Null(L4search_tag(v6stream, v2tag))) { goto L20; }
      {
       cl_object v10name;
       v10name = L5read_name(v6stream);
       cl_env_copy->values[0] = v10name;
       cl_env_copy->nvalues = 1;
       goto L19;
      }
L20:;
      cl_env_copy->values[0] = ECL_NIL;
      cl_env_copy->nvalues = 1;
L19:;
      ecl_stack_frame_push_values(v9);
      if (Null(v6stream)) { goto L23; }
      cl_close(1, v6stream);
L23:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v9);
     }
     ecl_stack_frame_close(_ecl_inner_frame);
    }
    }
    ecl_frs_pop(cl_env_copy);
    v8=ecl_stack_push_values(cl_env_copy);
    if (Null(v6stream)) { goto L25; }
    cl_close(3, v6stream, ECL_SYM("ABORT",1195), ECL_T);
L25:;
    ecl_stack_pop_values(cl_env_copy,v8);
    if (unwinding) ecl_unwind(cl_env_copy,next_fr);
    ECL_STACK_SET_INDEX(cl_env_copy,v7);
    return cl_env_copy->values[0];
   }
  }
 }
}
/*	function definition for REMOVE-PREFIX                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7remove_prefix(cl_object v1prefix, cl_object v2name)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_search(2, v1prefix, v2name);
  if (!(ecl_equal(ecl_make_fixnum(0),T0))) { goto L1; }
  {
   cl_fixnum v3;
   v3 = ecl_length(v1prefix);
   value0 = cl_subseq(3, v2name, ecl_make_fixnum(v3), ECL_NIL);
   return value0;
  }
L1:;
  value0 = v2name;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for GUESS-INIT-NAME                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8guess_init_name(cl_object v1pathname, cl_object v2kind)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!((v2kind)==(ECL_SYM("OBJECT",1278)))) { goto L1; }
  if (Null(cl_probe_file(v1pathname))) { goto L7; }
  value0 = L6find_init_name(1, v1pathname);
  goto L5;
L7:;
  value0 = ECL_NIL;
  goto L5;
L5:;
  if ((value0)!=ECL_NIL) { goto L4; }
  value0 = cl_error(2, _ecl_static_11, v1pathname);
  return value0;
L4:;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  value0 = L9compute_init_name(3, v1pathname, VV[6], v2kind);
  return value0;
 }
}
/*	function definition for COMPUTE-INIT-NAME                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L9compute_init_name(cl_narg narg, cl_object v1pathname, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2kind;
  cl_object v3prefix;
  ecl_va_list args; ecl_va_start(args,v1pathname,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L9compute_init_namekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[2])) {
    v2kind = ecl_function_dispatch(cl_env_copy,VV[40])(1, v1pathname) /*  GUESS-KIND */;
   } else {
    v2kind = keyvars[0];
   }
   v3prefix = keyvars[1];
  }
  {
   cl_object v4filename;
   T0 = cl_translate_logical_pathname(1, v1pathname);
   v4filename = cl_pathname_name(1, T0);
   if (!(ecl_eql(v2kind,ECL_SYM("OBJECT",1278)))) { goto L8; }
   goto L5;
   goto L6;
L8:;
   goto L6;
L6:;
   if (!(ecl_eql(v2kind,VV[9]))) { goto L3; }
   goto L4;
L5:;
L4:;
   value0 = L2unique_init_name(v1pathname);
   return value0;
L3:;
   if (!(ecl_eql(v2kind,VV[11]))) { goto L16; }
   goto L13;
   goto L14;
L16:;
   goto L14;
L14:;
   if (!(ecl_eql(v2kind,VV[13]))) { goto L11; }
   goto L12;
L13:;
L12:;
   value0 = L13init_function_name(5, _ecl_static_12, VV[6], VV[13], VV[15], v3prefix);
   return value0;
L11:;
   if (!(ecl_eql(v2kind,VV[16]))) { goto L24; }
   goto L21;
   goto L22;
L24:;
   goto L22;
L22:;
   if (!(ecl_eql(v2kind,VV[18]))) { goto L19; }
   goto L20;
L21:;
L20:;
   T0 = L7remove_prefix(ecl_symbol_value(VV[20]), v4filename);
   value0 = L13init_function_name(5, T0, VV[6], VV[18], VV[15], v3prefix);
   return value0;
L19:;
   if (!(ecl_eql(v2kind,VV[21]))) { goto L32; }
   goto L29;
   goto L30;
L32:;
   goto L30;
L30:;
   if (!(ecl_eql(v2kind,VV[23]))) { goto L27; }
   goto L28;
L29:;
L28:;
   T0 = L7remove_prefix(ecl_symbol_value(VV[25]), v4filename);
   value0 = L13init_function_name(5, T0, VV[6], VV[23], VV[15], v3prefix);
   return value0;
L27:;
   if (!(ecl_eql(v2kind,VV[26]))) { goto L35; }
   value0 = v3prefix;
   if ((value0)!=ECL_NIL) { goto L40; }
   T0 = _ecl_static_13;
   goto L38;
L40:;
   T0 = value0;
   goto L38;
L38:;
   value0 = cl_concatenate(3, ECL_SYM("STRING",805), T0, _ecl_static_14);
   return value0;
L35:;
   value0 = cl_error(2, _ecl_static_15, v2kind);
   return value0;
  }
 }
}
/*	function definition for COMPUTE-MAIN-NAME                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L10compute_main_name(cl_narg narg, cl_object v1pathname, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2args;
  ecl_va_list args; ecl_va_start(args,v1pathname,narg,1);
  v2args = cl_grab_rest_args(args);
  ecl_va_end(args);
  T0 = ecl_fdefinition(VV[28]);
  value0 = cl_apply(5, T0, v1pathname, VV[15], _ecl_static_16, v2args);
  return value0;
 }
}
/*	function definition for INIT-FUNCTION-NAME                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L13init_function_name(cl_narg narg, cl_object v1s, ...)
{
 cl_object T0, T1, T2, T3;
 volatile cl_object lex0[1];
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2prefix;
  ecl_va_list args; ecl_va_start(args,v1s,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L13init_function_namekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[2])) {
    lex0[0] = ECL_SYM("OBJECT",1278);             /*  KIND            */
   } else {
    lex0[0] = keyvars[0];                         /*  KIND            */
   }
   v2prefix = keyvars[1];
  }
  {cl_object v3;
   v3 = ECL_NIL;
   v3 = ecl_make_cfun((cl_objectfn_fixed)LC11translate_char,ECL_NIL,Cblock,1);
   T0 = cl_string(v1s);
   v1s = cl_map(3, ECL_SYM("STRING",805), v3, T0);
   value0 = v2prefix;
   if ((value0)!=ECL_NIL) { goto L5; }
   T0 = _ecl_static_13;
   goto L3;
L5:;
   T0 = value0;
   goto L3;
L3:;
   T1 = LC12disambiguation(lex0, lex0[0]);
   T2 = cl_string(v1s);
   T3 = cl_map(3, ECL_SYM("STRING",805), v3, T2);
   value0 = cl_concatenate(4, ECL_SYM("STRING",805), T0, T1, T3);
   return value0;
  }
 }
}
/*	local function DISAMBIGUATION                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC12disambiguation(volatile cl_object *lex0, cl_object v1c)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ecl_eql(lex0[0],ECL_SYM("OBJECT",1278)))) { goto L1; }
  value0 = _ecl_static_17;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (!(ecl_eql(lex0[0],VV[26]))) { goto L3; }
  value0 = _ecl_static_18;
  cl_env_copy->nvalues = 1;
  return value0;
L3:;
  if (!(ecl_eql(lex0[0],VV[11]))) { goto L10; }
  goto L7;
  goto L8;
L10:;
  goto L8;
L8:;
  if (!(ecl_eql(lex0[0],VV[13]))) { goto L5; }
  goto L6;
L7:;
L6:;
  value0 = _ecl_static_19;
  cl_env_copy->nvalues = 1;
  return value0;
L5:;
  if (!(ecl_eql(lex0[0],VV[30]))) { goto L18; }
  goto L15;
  goto L16;
L18:;
  goto L16;
L16:;
  if (!(ecl_eql(lex0[0],VV[16]))) { goto L22; }
  goto L15;
  goto L20;
L22:;
  goto L20;
L20:;
  if (!(ecl_eql(lex0[0],VV[18]))) { goto L13; }
  goto L14;
L15:;
L14:;
  value0 = _ecl_static_20;
  cl_env_copy->nvalues = 1;
  return value0;
L13:;
  if (!(ecl_eql(lex0[0],VV[21]))) { goto L30; }
  goto L27;
  goto L28;
L30:;
  goto L28;
L28:;
  if (!(ecl_eql(lex0[0],VV[23]))) { goto L25; }
  goto L26;
L27:;
L26:;
  value0 = _ecl_static_21;
  cl_env_copy->nvalues = 1;
  return value0;
L25:;
  value0 = cl_error(2, _ecl_static_22, lex0[0]);
  return value0;
 }
}
/*	local function TRANSLATE-CHAR                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC11translate_char(cl_object v1c)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_charGE(2, v1c, CODE_CHAR(97)))) { goto L1; }
  if (Null(cl_charLE(2, v1c, CODE_CHAR(122)))) { goto L1; }
  value0 = cl_char_upcase(v1c);
  return value0;
L1:;
  if (Null(cl_charGE(2, v1c, CODE_CHAR(65)))) { goto L4; }
  if (Null(cl_charLE(2, v1c, CODE_CHAR(90)))) { goto L4; }
  value0 = v1c;
  cl_env_copy->nvalues = 1;
  return value0;
L4:;
  if ((v1c)==(CODE_CHAR(45))) { goto L9; }
  if (!((v1c)==(CODE_CHAR(95)))) { goto L7; }
  goto L8;
L9:;
L8:;
  value0 = CODE_CHAR(95);
  cl_env_copy->nvalues = 1;
  return value0;
L7:;
  if (!((v1c)==(CODE_CHAR(42)))) { goto L11; }
  value0 = CODE_CHAR(120);
  cl_env_copy->nvalues = 1;
  return value0;
L11:;
  if (!((v1c)==(CODE_CHAR(63)))) { goto L13; }
  value0 = CODE_CHAR(97);
  cl_env_copy->nvalues = 1;
  return value0;
L13:;
  if (Null(cl_digit_char_p(1, v1c))) { goto L15; }
  value0 = v1c;
  cl_env_copy->nvalues = 1;
  return value0;
L15:;
  value0 = CODE_CHAR(112);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}

#include "cmp/cmpname.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecljtotsyjvU1xj9_oZrtVE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPNAME.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_ecljtotsyjvU1xj9_oZrtVE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 (void)0; /* No entry created for ENCODE-NUMBER-IN-NAME */
 ecl_cmp_defun(VV[33]);                           /*  UNIQUE-INIT-NAME */
 ecl_cmp_defun(VV[34]);                           /*  INIT-NAME-TAG   */
 (void)0; /* No entry created for SEARCH-TAG */
 (void)0; /* No entry created for READ-NAME */
 ecl_cmp_defun(VV[35]);                           /*  FIND-INIT-NAME  */
 ecl_cmp_defun(VV[37]);                           /*  REMOVE-PREFIX   */
 ecl_cmp_defun(VV[38]);                           /*  GUESS-INIT-NAME */
 ecl_cmp_defun(VV[39]);                           /*  COMPUTE-INIT-NAME */
 ecl_cmp_defun(VV[43]);                           /*  COMPUTE-MAIN-NAME */
 ecl_cmp_defun(VV[44]);                           /*  INIT-FUNCTION-NAME */
}
