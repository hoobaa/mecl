/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:LSP;LOOP2.LSP                                     */
#include <ecl/ecl-cmp.h>
#include "lsp/loop2.eclh"
/*	local function LOOP-UNSAFE                                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC1loop_unsafe(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_cdr(v1);
   value0 = cl_listX(3, ECL_SYM("LOCALLY",490), VV[0], v3);
   return value0;
  }
 }
}
/*	local function LOOP-COPYLIST*                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC2loop_copylist_(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4l;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4l = v5;
   }
   if (Null(v3)) { goto L8; }
   si_dm_too_many_arguments(v1);
L8:;
   value0 = cl_list(2, ECL_SYM("COPY-LIST",257), v4l);
   return value0;
  }
 }
}
/*	function definition for LOOP-OPTIMIZATION-QUANTITIES          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3loop_optimization_quantities(cl_object v1env)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  cl_env_copy->nvalues = 5;
  cl_env_copy->values[4] = ecl_make_fixnum(1);
  cl_env_copy->values[3] = ecl_make_fixnum(1);
  cl_env_copy->values[2] = ecl_make_fixnum(1);
  cl_env_copy->values[1] = ecl_make_fixnum(1);
  cl_env_copy->values[0] = ecl_make_fixnum(1);
  return cl_env_copy->values[0];
 }
}
/*	function definition for HIDE-VARIABLE-REFERENCES              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4hide_variable_references(cl_object v1variable_list, cl_object v2form)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = v2form;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for HIDE-VARIABLE-REFERENCE               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5hide_variable_reference(cl_object v1really_hide, cl_object v2variable, cl_object v3form)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = v3form;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function WITH-LOOP-LIST-COLLECTION-HEAD                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC6with_loop_list_collection_head(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6head_var;
   cl_object v7tail_var;
   cl_object v8user_head_var;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v9;
    v9 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4 = v9;
   }
   v5 = v4;
   if (!(v5==ECL_NIL)) { goto L10; }
   si_dm_too_few_arguments(v1);
L10:;
   {
    cl_object v9;
    v9 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v6head_var = v9;
   }
   if (!(v5==ECL_NIL)) { goto L16; }
   si_dm_too_few_arguments(v1);
L16:;
   {
    cl_object v9;
    v9 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v7tail_var = v9;
   }
   if (Null(v5)) { goto L22; }
   {
    cl_object v9;
    v9 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v8user_head_var = v9;
    goto L21;
   }
L22:;
   v8user_head_var = ECL_NIL;
L21:;
   if (Null(v5)) { goto L27; }
   si_dm_too_many_arguments(v1);
L27:;
   {
    cl_object v9l;
    if (Null(v8user_head_var)) { goto L31; }
    T0 = cl_list(2, v8user_head_var, ECL_NIL);
    v9l = ecl_list1(T0);
    goto L29;
L31:;
    v9l = ECL_NIL;
    goto L29;
L29:;
    T0 = cl_list(2, v6head_var, VV[4]);
    T1 = cl_list(2, v7tail_var, v6head_var);
    T2 = cl_listX(3, T0, T1, v9l);
    value0 = cl_listX(3, ECL_SYM("LET*",478), T2, v3);
    return value0;
   }
  }
 }
}
/*	local function LOOP-COLLECT-RPLACD                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC8loop_collect_rplacd(cl_object v1, cl_object v2env)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6head_var;
   cl_object v7tail_var;
   cl_object v8user_head_var;
   cl_object v9form;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v10;
    v10 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4 = v10;
   }
   v5 = v4;
   if (!(v5==ECL_NIL)) { goto L10; }
   si_dm_too_few_arguments(v1);
L10:;
   {
    cl_object v10;
    v10 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v6head_var = v10;
   }
   if (!(v5==ECL_NIL)) { goto L16; }
   si_dm_too_few_arguments(v1);
L16:;
   {
    cl_object v10;
    v10 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v7tail_var = v10;
   }
   if (Null(v5)) { goto L22; }
   {
    cl_object v10;
    v10 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v8user_head_var = v10;
    goto L21;
   }
L22:;
   v8user_head_var = ECL_NIL;
L21:;
   if (!(v3==ECL_NIL)) { goto L28; }
   si_dm_too_few_arguments(v1);
L28:;
   {
    cl_object v10;
    v10 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v9form = v10;
   }
   if (Null(v3)) { goto L33; }
   si_dm_too_many_arguments(v1);
L33:;
   if (Null(v5)) { goto L35; }
   si_dm_too_many_arguments(v1);
L35:;
   v9form = cl_macroexpand(2, v9form, v2env);
   {
    cl_object v10ncdrs;
    v10ncdrs = ECL_NIL;
    if (!(ECL_CONSP(v9form))) { goto L40; }
    T0 = ecl_car(v9form);
    if (!((T0)==(ECL_SYM("LIST",481)))) { goto L42; }
    T0 = ecl_cdr(v9form);
    {
     cl_fixnum v11;
     v11 = ecl_length(T0);
     v10ncdrs = ecl_make_integer((v11)-1);
    }
    goto L40;
L42:;
    {
     cl_object v11;
     v11 = ecl_car(v9form);
     if (!((v11)==(ECL_SYM("LIST*",482)))) { goto L50; }
     goto L47;
     goto L48;
L50:;
     goto L48;
L48:;
     if (!((v11)==(ECL_SYM("CONS",251)))) { goto L40; }
     goto L45;
L47:;
    }
L45:;
    if (Null(ecl_cddr(v9form))) { goto L40; }
    {
     cl_object v11;
     T0 = ecl_last(v9form,1);
     v11 = ecl_car(T0);
     if (!((v11)==(ECL_NIL))) { goto L59; }
     goto L56;
     goto L57;
L59:;
     goto L57;
L57:;
     if (!(ecl_eql(v11,VV[9]))) { goto L40; }
     goto L53;
L56:;
    }
L53:;
    T0 = ecl_cdr(v9form);
    {
     cl_fixnum v11;
     v11 = ecl_length(T0);
     v10ncdrs = ecl_minus(ecl_make_fixnum(v11),ecl_make_fixnum(2));
    }
L40:;
    {
     cl_object v11answer;
     if (!(v10ncdrs==ECL_NIL)) { goto L64; }
     T0 = cl_list(2, ECL_SYM("CDR",198), v7tail_var);
     T1 = cl_list(3, ECL_SYM("SETF",750), T0, v9form);
     T2 = cl_list(2, ECL_SYM("CDR",198), v7tail_var);
     T3 = cl_list(2, ECL_SYM("LAST",455), T2);
     T4 = cl_list(3, ECL_SYM("SETQ",751), v7tail_var, T3);
     v11answer = cl_list(3, ECL_SYM("WHEN",905), T1, T4);
     goto L63;
L64:;
     if (!(ecl_number_compare(v10ncdrs,ecl_make_fixnum(0))<0)) { goto L66; }
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 1;
     return value0;
L66:;
     if (!(ecl_number_equalp(v10ncdrs,ecl_make_fixnum(0)))) { goto L68; }
     T0 = cl_list(3, ECL_SYM("SETQ",751), v7tail_var, v9form);
     v11answer = cl_list(3, ECL_SYM("RPLACD",733), v7tail_var, T0);
     goto L63;
L68:;
     T1 = cl_list(2, ECL_SYM("CDR",198), v7tail_var);
     T2 = cl_list(3, ECL_SYM("SETF",750), T1, v9form);
     T0 = LC7cdr_wrap(T2, v10ncdrs);
     v11answer = cl_list(3, ECL_SYM("SETQ",751), v7tail_var, T0);
L63:;
     if (Null(v8user_head_var)) { goto L71; }
     T0 = cl_list(2, ECL_SYM("CDR",198), v6head_var);
     T1 = cl_list(3, ECL_SYM("SETQ",751), v8user_head_var, T0);
     v11answer = cl_list(3, ECL_SYM("PROGN",671), v11answer, T1);
L71:;
     value0 = v11answer;
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
  }
 }
}
/*	local function CDR-WRAP                                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC7cdr_wrap(cl_object v1form, cl_object v2n)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_fixnum v3n;
  v3n = ecl_to_fixnum(v2n);
TTL:
  goto L3;
L2:;
  v1form = cl_list(2, ECL_SYM("CDDDDR",195), v1form);
  {
   cl_object v4;
   v4 = ecl_minus(ecl_make_fixnum(v3n),ecl_make_fixnum(4));
   {
    bool v5;
    v5 = ECL_FIXNUMP(v4);
    if (ecl_unlikely(!(v5)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v4);
   }
   v3n = ecl_fixnum(v4);
  }
L3:;
  if ((v3n)<=(4)) { goto L11; }
  goto L2;
L11:;
  if (!((v3n)==(1))) { goto L15; }
  T0 = ECL_SYM("CDR",198);
  goto L14;
L15:;
  if (!((v3n)==(2))) { goto L17; }
  T0 = ECL_SYM("CDDR",197);
  goto L14;
L17:;
  if (!((v3n)==(3))) { goto L19; }
  T0 = ECL_SYM("CDDDR",196);
  goto L14;
L19:;
  if (!((v3n)==(4))) { goto L21; }
  T0 = ECL_SYM("CDDDDR",195);
  goto L14;
L21:;
  T0 = ECL_NIL;
L14:;
  v1form = cl_list(2, T0, v1form);
  value0 = v1form;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function LOOP-COLLECT-ANSWER                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC9loop_collect_answer(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4head_var;
   cl_object v5user_head_var;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4head_var = v6;
   }
   if (Null(v3)) { goto L9; }
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5user_head_var = v6;
    goto L8;
   }
L9:;
   v5user_head_var = ECL_NIL;
L8:;
   if (Null(v3)) { goto L14; }
   si_dm_too_many_arguments(v1);
L14:;
   value0 = v5user_head_var;
   if ((value0)!=ECL_NIL) { goto L17; }
   value0 = cl_list(2, ECL_SYM("CDR",198), v4head_var);
   return value0;
L17:;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for MAKE-LOOP-MINIMAX-INTERNAL            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L10make_loop_minimax_internal(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1;
  cl_object v2;
  cl_object v3;
  cl_object v4;
  cl_object v5;
  cl_object v6;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  {
   cl_object keyvars[12];
   cl_parse_key(args,6,L10make_loop_minimax_internalkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v1 = keyvars[0];
   v2 = keyvars[1];
   v3 = keyvars[2];
   v4 = keyvars[3];
   v5 = keyvars[4];
   v6 = keyvars[5];
  }
  T0 = cl_list(6, v1, v2, v3, v4, v5, v6);
  value0 = cl_make_array(5, VV[15], ECL_SYM("ELEMENT-TYPE",1224), ECL_T, ECL_SYM("INITIAL-CONTENTS",1252), T0);
  return value0;
 }
}
/*	function definition for MAKE-LOOP-MINIMAX                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L11make_loop_minimax(cl_object v1answer_variable, cl_object v2type)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3infinity_data;
   {
    cl_object v4;
    v4 = ecl_symbol_value(VV[17]);
    goto L6;
L5:;
    {
     cl_object v5;
     cl_object v6;
     if (ecl_unlikely(ECL_ATOM(v4))) FEtype_error_cons(v4);
     v5 = v4;
     v6 = ECL_CONS_CAR(v5);
     if (Null(v6)) { goto L8; }
     {
      cl_object v7;
      if (ecl_unlikely(ECL_ATOM(v6))) FEtype_error_cons(v6);
      T1 = v6;
      v7 = ECL_CONS_CAR(T1);
      if (Null(cl_subtypep(2, v2type, v7))) { goto L8; }
      T0 = v6;
      goto L2;
     }
    }
L8:;
    v4 = ECL_CONS_CDR(v4);
L6:;
    if (v4==ECL_NIL) { goto L19; }
    goto L5;
L19:;
    T0 = ECL_NIL;
   }
L2:;
   v3infinity_data = ecl_cdr(T0);
   T0 = cl_gensym(1, _ecl_static_2);
   if ((v3infinity_data)!=ECL_NIL) { goto L23; }
   T1 = cl_gensym(1, _ecl_static_3);
   goto L21;
L23:;
   T1 = ECL_NIL;
   goto L21;
L21:;
   value0 = L10make_loop_minimax_internal(12, VV[18], v1answer_variable, ECL_SYM("TYPE",1318), v2type, VV[19], T0, VV[20], T1, VV[21], ECL_NIL, VV[22], v3infinity_data);
   return value0;
  }
 }
}
/*	function definition for LOOP-NOTE-MINIMAX-OPERATION           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L12loop_note_minimax_operation(cl_object v1operation, cl_object v2minimax)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   T0 = ecl_function_dispatch(cl_env_copy,VV[235])(1, v2minimax) /*  LOOP-MINIMAX-OPERATIONS */;
   v3 = cl_adjoin(2, v1operation, T0);
   ecl_elt_set(v2minimax,4,v3);
  }
  T0 = ecl_function_dispatch(cl_env_copy,VV[235])(1, v2minimax) /*  LOOP-MINIMAX-OPERATIONS */;
  if (Null(ecl_cdr(T0))) { goto L3; }
  if ((ecl_function_dispatch(cl_env_copy,VV[236])(1, v2minimax) /*  LOOP-MINIMAX-FLAG-VARIABLE */)!=ECL_NIL) { goto L3; }
  {
   cl_object v3;
   v3 = cl_gensym(1, _ecl_static_3);
   ecl_elt_set(v2minimax,3,v3);
  }
L3:;
  value0 = v1operation;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function WITH-MINIMAX-VALUE                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC13with_minimax_value(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4lm;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4lm = v5;
   }
   {
    cl_object v5;
    cl_object v6;
    cl_object v7;
    cl_object v8;
    cl_object v9;
    cl_object v10;
    cl_object v11;
    T0 = ecl_function_dispatch(cl_env_copy,VV[238])(1, v4lm) /*  LOOP-MINIMAX-TYPE */;
    v5 = L59loop_typed_init(T0);
    T0 = ecl_function_dispatch(cl_env_copy,VV[235])(1, v4lm) /*  LOOP-MINIMAX-OPERATIONS */;
    v6 = ecl_car(T0);
    v7 = ecl_function_dispatch(cl_env_copy,VV[239])(1, v4lm) /*  LOOP-MINIMAX-INFINITY-DATA */;
    v8 = ecl_function_dispatch(cl_env_copy,VV[240])(1, v4lm) /*  LOOP-MINIMAX-ANSWER-VARIABLE */;
    v9 = ecl_function_dispatch(cl_env_copy,VV[241])(1, v4lm) /*  LOOP-MINIMAX-TEMP-VARIABLE */;
    v10 = ecl_function_dispatch(cl_env_copy,VV[236])(1, v4lm) /*  LOOP-MINIMAX-FLAG-VARIABLE */;
    v11 = ecl_function_dispatch(cl_env_copy,VV[238])(1, v4lm) /*  LOOP-MINIMAX-TYPE */;
    if (Null(v10)) { goto L15; }
    T0 = cl_list(2, v8, v5);
    T1 = cl_list(2, v9, v5);
    T2 = cl_list(2, v10, ECL_NIL);
    T3 = cl_list(3, T0, T1, T2);
    T4 = cl_list(4, ECL_SYM("TYPE",869), v11, v8, v9);
    T5 = cl_list(2, ECL_SYM("DECLARE",274), T4);
    value0 = cl_listX(4, ECL_SYM("LET",477), T3, T5, v3);
    return value0;
L15:;
    if (!((v6)==(ECL_SYM("MIN",557)))) { goto L18; }
    T0 = ecl_car(v7);
    goto L17;
L18:;
    T0 = ecl_cadr(v7);
L17:;
    T1 = cl_list(2, v8, T0);
    T2 = cl_list(2, v9, v5);
    T3 = cl_list(2, T1, T2);
    T4 = cl_list(4, ECL_SYM("TYPE",869), v11, v8, v9);
    T5 = cl_list(2, ECL_SYM("DECLARE",274), T4);
    value0 = cl_listX(4, ECL_SYM("LET",477), T3, T5, v3);
    return value0;
   }
  }
 }
}
/*	local function LOOP-ACCUMULATE-MINIMAX-VALUE                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC14loop_accumulate_minimax_value(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4lm;
   cl_object v5operation;
   cl_object v6form;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v7;
    v7 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4lm = v7;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v7;
    v7 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5operation = v7;
   }
   if (!(v3==ECL_NIL)) { goto L15; }
   si_dm_too_few_arguments(v1);
L15:;
   {
    cl_object v7;
    v7 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v6form = v7;
   }
   if (Null(v3)) { goto L20; }
   si_dm_too_many_arguments(v1);
L20:;
   {
    cl_object v7answer_var;
    cl_object v8temp_var;
    cl_object v9flag_var;
    cl_object v10test;
    v7answer_var = ecl_function_dispatch(cl_env_copy,VV[240])(1, v4lm) /*  LOOP-MINIMAX-ANSWER-VARIABLE */;
    v8temp_var = ecl_function_dispatch(cl_env_copy,VV[241])(1, v4lm) /*  LOOP-MINIMAX-TEMP-VARIABLE */;
    v9flag_var = ecl_function_dispatch(cl_env_copy,VV[236])(1, v4lm) /*  LOOP-MINIMAX-FLAG-VARIABLE */;
    T0 = ecl_function_dispatch(cl_env_copy,VV[240])(1, v4lm) /*  LOOP-MINIMAX-ANSWER-VARIABLE */;
    if (!((v5operation)==(ECL_SYM("MIN",557)))) { goto L27; }
    T1 = ECL_SYM("<",72);
    goto L26;
L27:;
    if (!((v5operation)==(ECL_SYM("MAX",551)))) { goto L29; }
    T1 = ECL_SYM(">",75);
    goto L26;
L29:;
    T1 = si_ecase_error(v5operation, VV[24]);
L26:;
    T2 = cl_list(3, T1, v8temp_var, v7answer_var);
    v10test = L5hide_variable_reference(ECL_T, T0, T2);
    T0 = cl_list(3, ECL_SYM("SETQ",751), v8temp_var, v6form);
    if (Null(v9flag_var)) { goto L32; }
    T2 = cl_list(2, ECL_SYM("NOT",584), v9flag_var);
    T1 = cl_list(3, ECL_SYM("OR",614), T2, v10test);
    goto L31;
L32:;
    T1 = v10test;
L31:;
    if (Null(v9flag_var)) { goto L36; }
    T2 = cl_list(2, v9flag_var, ECL_T);
    goto L34;
L36:;
    T2 = ECL_NIL;
    goto L34;
L34:;
    T3 = cl_list(2, v7answer_var, v8temp_var);
    T4 = ecl_append(T2,T3);
    T5 = CONS(ECL_SYM("SETQ",751),T4);
    T6 = cl_list(3, ECL_SYM("WHEN",905), T1, T5);
    value0 = cl_list(3, ECL_SYM("PROGN",671), T0, T6);
    return value0;
   }
  }
 }
}
/*	function definition for LOOP-TEQUAL                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L15loop_tequal(cl_object v1x1, cl_object v2x2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_SYMBOLP(v1x1))) { goto L2; }
  value0 = cl_stringE(2, v1x1, v2x2);
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for LOOP-TASSOC                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L16loop_tassoc(cl_object v1kwd, cl_object v2alist)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_SYMBOLP(v1kwd))) { goto L2; }
  {
   cl_object v3;
   v3 = v2alist;
   goto L7;
L6:;
   {
    cl_object v4;
    cl_object v5;
    if (ecl_unlikely(ECL_ATOM(v3))) FEtype_error_cons(v3);
    v4 = v3;
    v5 = ECL_CONS_CAR(v4);
    if (Null(v5)) { goto L9; }
    {
     cl_object v6;
     if (ecl_unlikely(ECL_ATOM(v5))) FEtype_error_cons(v5);
     T0 = v5;
     v6 = ECL_CONS_CAR(T0);
     if (Null(cl_stringE(2, v1kwd, v6))) { goto L9; }
     value0 = v5;
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
L9:;
   v3 = ECL_CONS_CDR(v3);
L7:;
   if (v3==ECL_NIL) { goto L20; }
   goto L6;
L20:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for LOOP-TMEMBER                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L17loop_tmember(cl_object v1kwd, cl_object v2list)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_SYMBOLP(v1kwd))) { goto L2; }
  {
   cl_object v3;
   v3 = v2list;
   goto L7;
L6:;
   {
    cl_object v4;
    cl_object v5;
    if (ecl_unlikely(ECL_ATOM(v3))) FEtype_error_cons(v3);
    v4 = v3;
    v5 = ECL_CONS_CAR(v4);
    if (Null(cl_stringE(2, v1kwd, v5))) { goto L9; }
    value0 = v4;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L9:;
   v3 = ECL_CONS_CDR(v3);
L7:;
   if (v3==ECL_NIL) { goto L16; }
   goto L6;
L16:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for LOOP-LOOKUP-KEYWORD                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L18loop_lookup_keyword(cl_object v1loop_token, cl_object v2table)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_SYMBOLP(v1loop_token))) { goto L2; }
  T0 = ecl_symbol_name(v1loop_token);
  value0 = ecl_gethash_safe(T0,v2table,ECL_NIL);
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function LOOP-STORE-TABLE-DATA                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC19loop_store_table_data(cl_object v1, cl_object v2)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4symbol;
   cl_object v5table;
   cl_object v6datum;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v7;
    v7 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4symbol = v7;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v7;
    v7 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5table = v7;
   }
   if (!(v3==ECL_NIL)) { goto L15; }
   si_dm_too_few_arguments(v1);
L15:;
   {
    cl_object v7;
    v7 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v6datum = v7;
   }
   if (Null(v3)) { goto L20; }
   si_dm_too_many_arguments(v1);
L20:;
   T0 = cl_list(2, ECL_SYM("SYMBOL-NAME",843), v4symbol);
   T1 = cl_list(3, ECL_SYM("GETHASH",413), T0, v5table);
   value0 = cl_list(3, ECL_SYM("SETF",750), T1, v6datum);
   return value0;
  }
 }
}
/*	function definition for MAKE-LOOP-UNIVERSE                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L20make_loop_universe(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1;
  cl_object v2;
  cl_object v3;
  cl_object v4;
  cl_object v5;
  cl_object v6;
  cl_object v7;
  cl_object v8;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  {
   cl_object keyvars[16];
   cl_parse_key(args,8,L20make_loop_universekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v1 = keyvars[0];
   v2 = keyvars[1];
   v3 = keyvars[2];
   v4 = keyvars[3];
   v5 = keyvars[4];
   v6 = keyvars[5];
   v7 = keyvars[6];
   v8 = keyvars[7];
  }
  T0 = cl_list(8, v1, v2, v3, v4, v5, v6, v7, v8);
  value0 = cl_make_array(5, VV[29], ECL_SYM("ELEMENT-TYPE",1224), ECL_T, ECL_SYM("INITIAL-CONTENTS",1252), T0);
  return value0;
 }
}
/*	function definition for MAKE-STANDARD-LOOP-UNIVERSE           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L22make_standard_loop_universe(cl_narg narg, ...)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1keywords;
  cl_object v2for_keywords;
  cl_object v3iteration_keywords;
  cl_object v4path_keywords;
  cl_object v5type_keywords;
  cl_object v6type_symbols;
  cl_object v7ansi;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  {
   cl_object keyvars[14];
   cl_parse_key(args,7,L22make_standard_loop_universekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v1keywords = keyvars[0];
   v2for_keywords = keyvars[1];
   v3iteration_keywords = keyvars[2];
   v4path_keywords = keyvars[3];
   v5type_keywords = keyvars[4];
   v6type_symbols = keyvars[5];
   v7ansi = keyvars[6];
  }
  {
   cl_object v8;
   v8 = v7ansi;
   if (!((v8)==(ECL_NIL))) { goto L7; }
   goto L3;
   goto L5;
L7:;
   goto L5;
L5:;
   if (!(ecl_eql(v8,ECL_T))) { goto L11; }
   goto L3;
   goto L9;
L11:;
   goto L9;
L9:;
   if (!(ecl_eql(v8,VV[34]))) { goto L14; }
   goto L3;
   goto L4;
L14:;
   goto L4;
L4:;
   v7ansi = si_do_check_type(v8, VV[36], ECL_NIL, VV[37]);
L3:;
  }
  T0 = LC21maketable(v1keywords);
  T1 = LC21maketable(v2for_keywords);
  T2 = LC21maketable(v3iteration_keywords);
  T3 = LC21maketable(v4path_keywords);
  {
   bool v8;
   v8 = v7ansi==ECL_NIL;
   T4 = (v8)?ECL_NIL:ECL_T;
  }
  T5 = LC21maketable(v5type_keywords);
  {
   cl_fixnum v8size;
   cl_object v9ht;
   v8size = ecl_length(v6type_symbols);
   {
    cl_fixnum v10;
    if (!((v8size)<(10))) { goto L27; }
    v10 = 10;
    goto L26;
L27:;
    v10 = v8size;
L26:;
    T7 = (ECL_SYM("EQ",333)->symbol.gfdef);
    v9ht = cl_make_hash_table(4, ECL_SYM("SIZE",1308), ecl_make_fixnum(v10), ECL_SYM("TEST",1316), T7);
   }
   {
    cl_object v10;
    v10 = v6type_symbols;
    goto L34;
L33:;
    {
     cl_object v11x;
     v11x = ecl_car(v10);
     if (!(ECL_ATOM(v11x))) { goto L39; }
     si_hash_set(v11x, v9ht, v11x);
     goto L38;
L39:;
     T7 = ecl_car(v11x);
     T8 = ecl_cadr(v11x);
     si_hash_set(T7, v9ht, T8);
L38:;
    }
    v10 = ecl_cdr(v10);
L34:;
    if (Null(v10)) { goto L43; }
    goto L33;
L43:;
   }
   T6 = v9ht;
  }
  value0 = L20make_loop_universe(16, VV[38], T0, VV[39], T1, VV[40], T2, VV[41], T3, VV[42], v7ansi, VV[43], T4, VV[44], T5, VV[45], T6);
  return value0;
 }
}
/*	local function MAKETABLE                                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC21maketable(cl_object v1entries)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v2size;
   cl_object v3ht;
   v2size = ecl_length(v1entries);
   {
    cl_fixnum v4;
    if (!((v2size)<(10))) { goto L4; }
    v4 = 10;
    goto L3;
L4:;
    v4 = v2size;
L3:;
    T0 = (ECL_SYM("EQUAL",335)->symbol.gfdef);
    v3ht = cl_make_hash_table(4, ECL_SYM("SIZE",1308), ecl_make_fixnum(v4), ECL_SYM("TEST",1316), T0);
   }
   {
    cl_object v4;
    v4 = v1entries;
    goto L11;
L10:;
    {
     cl_object v5x;
     v5x = ecl_car(v4);
     T0 = ecl_car(v5x);
     T1 = ecl_symbol_name(T0);
     T2 = ecl_cadr(v5x);
     si_hash_set(T1, v3ht, T2);
    }
    v4 = ecl_cdr(v4);
L11:;
    if (Null(v4)) { goto L18; }
    goto L10;
L18:;
   }
   value0 = v3ht;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for LOOP-MAKE-PSETQ                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L23loop_make_psetq(cl_object v1frobs)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1frobs)) { goto L2; }
  T0 = ecl_car(v1frobs);
  T2 = ecl_cddr(v1frobs);
  if (!(T2==ECL_NIL)) { goto L5; }
  T1 = ecl_cadr(v1frobs);
  goto L4;
L5:;
  T2 = ecl_cadr(v1frobs);
  T3 = ecl_cddr(v1frobs);
  T4 = L23loop_make_psetq(T3);
  T1 = cl_list(3, ECL_SYM("PROG1",669), T2, T4);
L4:;
  T2 = cl_list(2, T0, T1);
  value0 = L24loop_make_desetq(T2);
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for LOOP-MAKE-DESETQ                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L24loop_make_desetq(cl_object v1var_val_pairs)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(v1var_val_pairs==ECL_NIL)) { goto L1; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (Null(ecl_symbol_value(VV[46]))) { goto L4; }
  T0 = ecl_cadr(ecl_symbol_value(VV[46]));
  goto L3;
L4:;
  T0 = VV[47];
L3:;
  value0 = CONS(T0,v1var_val_pairs);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function LOOP-REALLY-DESETQ                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC27loop_really_desetq(cl_object v1, cl_object v2env)
{
 cl_object T0, T1, T2;
 volatile cl_object lex0[1];
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  lex0[0] = v2env;                                /*  ENV             */
TTL:
  {
   cl_object v3;
   cl_object v4var_val_pairs;
   v3 = ecl_cdr(v1);
   v4var_val_pairs = v3;
   {
    cl_object v5actions;
    v5actions = ECL_NIL;
    goto L6;
L5:;
    {
     cl_object v6;
     v6 = v4var_val_pairs;
     if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
     if (Null(v6)) { goto L15; }
     {
      cl_object v7;
      v7 = ECL_CONS_CDR(v6);
      v4var_val_pairs = v7;
      v6 = ECL_CONS_CAR(v6);
     }
L15:;
     T1 = v6;
    }
    {
     cl_object v6;
     v6 = v4var_val_pairs;
     if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
     if (Null(v6)) { goto L25; }
     {
      cl_object v7;
      v7 = ECL_CONS_CDR(v6);
      v4var_val_pairs = v7;
      v6 = ECL_CONS_CAR(v6);
     }
L25:;
     T2 = v6;
    }
    T0 = LC26loop_desetq_internal(2, lex0, T1, T2);
    v5actions = cl_revappend(T0, v5actions);
L6:;
    if (v4var_val_pairs==ECL_NIL) { goto L31; }
    goto L5;
L31:;
    T0 = ecl_cdr(v5actions);
    if (!(T0==ECL_NIL)) { goto L33; }
    value0 = ecl_car(v5actions);
    cl_env_copy->nvalues = 1;
    return value0;
L33:;
    T0 = cl_nreverse(v5actions);
    value0 = CONS(ECL_SYM("PROGN",671),T0);
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	local function LOOP-DESETQ-INTERNAL                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC26loop_desetq_internal(cl_narg narg, volatile cl_object *lex0, cl_object v1var, cl_object v2val, ...)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v3temp;
  va_list args; va_start(args,v2val);
  {
   int i = 2;
   if (i >= narg) {
    v3temp = ECL_NIL;
   } else {
    i++;
    v3temp = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (!(ECL_CONSP(v2val))) { goto L2; }
  T0 = ecl_car(v2val);
  if (!((T0)==(VV[1]))) { goto L2; }
  {
   cl_object v4forms;
   v4forms = ecl_cdr(v2val);
   if (Null(ecl_cdr(v4forms))) { goto L8; }
   v4forms = CONS(ECL_SYM("PROGN",671),v4forms);
   goto L7;
L8:;
   v4forms = ecl_car(v4forms);
L7:;
   T0 = LC26loop_desetq_internal(2, lex0, v1var, v4forms);
   T1 = CONS(VV[1],T0);
   value0 = ecl_list1(T1);
   cl_env_copy->nvalues = 1;
   return value0;
  }
L2:;
  if (!(v1var==ECL_NIL)) { goto L11; }
  if (!(ECL_CONSP(v2val))) { goto L13; }
  T0 = ecl_car(v2val);
  if (!((T0)==(ECL_SYM("PROG1",669)))) { goto L15; }
  {
   cl_object v4;
   cl_object v5;
   cl_object v6;
   v4 = ecl_cdr(v2val);
   v5 = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
   v6 = v4;
   {
    cl_object v7;
    cl_object v8;
    v7 = ecl_list1(ECL_NIL);
    v8 = v7;
L23:;
    if (!(ecl_endp(v6))) { goto L25; }
    goto L24;
L25:;
    v5 = _ecl_car(v6);
    {
     cl_object v9;
     v9 = _ecl_cdr(v6);
     if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
     v6 = v9;
    }
    {
     cl_object v9;
     {
      cl_object v10x;
      v10x = v5;
      if (!(ECL_CONSP(v10x))) { goto L38; }
      T0 = ecl_car(v10x);
      if (!((T0)==(ECL_SYM("CAR",180)))) { goto L41; }
      T0 = ecl_cadr(v10x);
      if (!(ECL_SYMBOLP(T0))) { goto L41; }
      v10x = cl_macroexpand(2, v10x, lex0[0]);
      if (ECL_SYMBOLP(v10x)) { goto L38; }
      goto L40;
L41:;
L40:;
      v9 = CONS(v10x,ECL_NIL);
      goto L35;
L38:;
      v9 = ECL_NIL;
      goto L35;
     }
L35:;
     if (ecl_unlikely(ECL_ATOM(v8))) FEtype_error_cons(v8);
     T0 = v8;
     (ECL_CONS_CDR(T0)=v9,T0);
     if (Null(v9)) { goto L33; }
    }
    T0 = ecl_cdr(v8);
    v8 = ecl_last(T0,1);
L33:;
    goto L23;
L24:;
    value0 = ecl_cdr(v7);
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
L15:;
  value0 = ecl_list1(v2val);
  cl_env_copy->nvalues = 1;
  return value0;
L13:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L11:;
  if (!(ECL_CONSP(v1var))) { goto L51; }
  {
   cl_object v9car;
   cl_object v10cdr;
   cl_object v11car_non_null;
   cl_object v12cdr_non_null;
   v9car = ecl_car(v1var);
   v10cdr = ecl_cdr(v1var);
   v11car_non_null = LC25find_non_null(v9car);
   v12cdr_non_null = LC25find_non_null(v10cdr);
   if ((v11car_non_null)!=ECL_NIL) { goto L59; }
   if (Null(v12cdr_non_null)) { goto L57; }
   goto L58;
L59:;
L58:;
   if (Null(v12cdr_non_null)) { goto L61; }
   {
    cl_object v13temp;
    cl_object v14body;
    value0 = v3temp;
    if ((value0)!=ECL_NIL) { goto L65; }
    v13temp = ecl_symbol_value(VV[48]);
    goto L63;
L65:;
    v13temp = value0;
    goto L63;
L63:;
    T1 = cl_list(2, ECL_SYM("CAR",180), v13temp);
    T0 = LC26loop_desetq_internal(2, lex0, v9car, T1);
    T1 = cl_list(2, ECL_SYM("CDR",198), v13temp);
    T2 = cl_list(3, ECL_SYM("SETQ",751), v13temp, T1);
    T3 = LC26loop_desetq_internal(3, lex0, v10cdr, v13temp, v13temp);
    T4 = CONS(T2,T3);
    v14body = ecl_append(T0,T4);
    if (Null(v3temp)) { goto L70; }
    if ((v13temp)==(v2val)) { goto L73; }
    T1 = cl_list(3, ECL_SYM("SETQ",751), v13temp, v2val);
    T0 = ecl_list1(T1);
    goto L72;
L73:;
    T0 = ECL_NIL;
L72:;
    value0 = ecl_append(T0,v14body);
    cl_env_copy->nvalues = 1;
    return value0;
L70:;
    T0 = cl_list(2, v13temp, v2val);
    T1 = ecl_list1(T0);
    T2 = cl_listX(3, ECL_SYM("LET",477), T1, v14body);
    value0 = ecl_list1(T2);
    cl_env_copy->nvalues = 1;
    return value0;
   }
L61:;
   T0 = cl_list(2, ECL_SYM("CAR",180), v2val);
   value0 = LC26loop_desetq_internal(3, lex0, v9car, T0, v3temp);
   return value0;
L57:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L51:;
  if ((v1var)==(v2val)) { goto L75; }
  T0 = cl_list(3, ECL_SYM("SETQ",751), v1var, v2val);
  value0 = ecl_list1(T0);
  cl_env_copy->nvalues = 1;
  return value0;
L75:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function FIND-NON-NULL                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC25find_non_null(cl_object v1var)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2tail;
   v2tail = v1var;
   goto L4;
L3:;
   {
    cl_object v3;
    v3 = v2tail;
    if (ecl_unlikely(!ECL_LISTP(v3))) FEtype_error_list(v3);
    if (Null(v3)) { goto L12; }
    {
     cl_object v4;
     v4 = ECL_CONS_CDR(v3);
     v2tail = v4;
     v3 = ECL_CONS_CAR(v3);
    }
L12:;
    T0 = v3;
   }
   if (Null(LC25find_non_null(T0))) { goto L6; }
   value0 = ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
L6:;
L4:;
   if (!(ECL_CONSP(v2tail))) { goto L18; }
   goto L3;
L18:;
   value0 = v2tail;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for LOOP-CONSTANT-FOLD-IF-POSSIBLE        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L28loop_constant_fold_if_possible(cl_narg narg, cl_object v1form, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2expected_type;
  va_list args; va_start(args,v1form);
  {
   int i = 1;
   if (i >= narg) {
    v2expected_type = ECL_NIL;
   } else {
    i++;
    v2expected_type = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v3constantp;
   cl_object v4constant_value;
   v3constantp = ECL_NIL;
   v4constant_value = ECL_NIL;
   v3constantp = cl_constantp(1, v1form);
   if (Null(v3constantp)) { goto L4; }
   v4constant_value = cl_eval(v1form);
L4:;
   if (Null(v3constantp)) { goto L8; }
   if (Null(v2expected_type)) { goto L8; }
   if ((cl_typep(2, v4constant_value, v2expected_type))!=ECL_NIL) { goto L8; }
   L42loop_warn(4, _ecl_static_6, v1form, v4constant_value, v2expected_type);
   v3constantp = ECL_NIL;
   v4constant_value = ECL_NIL;
L8:;
   cl_env_copy->nvalues = 3;
   cl_env_copy->values[2] = v4constant_value;
   cl_env_copy->values[1] = v3constantp;
   cl_env_copy->values[0] = v1form;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for LOOP-CONSTANTP                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L29loop_constantp(cl_object v1form)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_constantp(1, v1form);
  return value0;
 }
}
/*	function definition for LOOP-CODE-DUPLICATION-THRESHOLD       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L30loop_code_duplication_threshold(cl_object v1env)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;                                  /*  SPEED           */
   cl_object v4;                                  /*  SPACE           */
   value0 = L3loop_optimization_quantities(v1env);
   v3 = value0;
   {
    const int v5 = cl_env_copy->nvalues;
    cl_object v6;
    v6 = (v5<=1)? ECL_NIL : cl_env_copy->values[1];
    v4 = v6;
   }
   T0 = ecl_minus(v3,v4);
   T1 = ecl_times(T0,ecl_make_fixnum(10));
   value0 = ecl_plus(ecl_make_fixnum(40),T1);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function LOOP-BODY                                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC34loop_body(cl_object v1, cl_object v2env)
{
 cl_object T0, T1, T2;
 volatile cl_object lex0[6];
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4before_loop;
   cl_object v5after_loop;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L2; }
   si_dm_too_few_arguments(v1);
L2:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    T0 = v6;
   }
   lex0[0] = T0;                                  /*  PROLOGUE        */
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4before_loop = v6;
   }
   if (!(v3==ECL_NIL)) { goto L14; }
   si_dm_too_few_arguments(v1);
L14:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    T0 = v6;
   }
   lex0[1] = T0;                                  /*  MAIN-BODY       */
   if (!(v3==ECL_NIL)) { goto L21; }
   si_dm_too_few_arguments(v1);
L21:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5after_loop = v6;
   }
   if (!(v3==ECL_NIL)) { goto L26; }
   si_dm_too_few_arguments(v1);
L26:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    T0 = v6;
   }
   lex0[2] = T0;                                  /*  EPILOGUE        */
   lex0[3] = ECL_NIL;                             /*  RBEFORE         */
   lex0[4] = ECL_NIL;                             /*  RAFTER          */
   lex0[5] = ECL_NIL;                             /*  FLAGVAR         */
   if (Null(v3)) { goto L32; }
   si_dm_too_many_arguments(v1);
L32:;
   {
    cl_fixnum v6;
    v6 = ecl_length(v4before_loop);
    {
     cl_fixnum v7;
     v7 = ecl_length(v5after_loop);
     if ((v6)==(v7)) { goto L34; }
    }
   }
   cl_error(1, _ecl_static_8);
L34:;
   lex0[3] = cl_reverse(v4before_loop);
   lex0[4] = cl_reverse(v5after_loop);
   if ((ecl_symbol_value(VV[76]))!=ECL_NIL) { goto L42; }
   if ((lex0[3])!=ECL_NIL) { goto L40; }
   goto L41;
L42:;
L41:;
   value0 = LC33makebody(lex0);
   return value0;
L40:;
   {
    cl_fixnum v6threshold;
    {
     cl_object v7;
     v7 = L30loop_code_duplication_threshold(v2env);
     {
      bool v8;
      v8 = ECL_FIXNUMP(v7);
      if (ecl_unlikely(!(v8)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v7);
     }
     v6threshold = ecl_fixnum(v7);
    }
    goto L49;
L48:;
    goto L54;
L53:;
    {
     cl_object v7;
     v7 = lex0[3];
     if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
     if (Null(v7)) { goto L62; }
     {
      cl_object v8;
      v8 = ECL_CONS_CDR(v7);
      lex0[3] = v8;
      v7 = ECL_CONS_CAR(v7);
     }
L62:;
     T0 = v7;
    }
    lex0[1] = CONS(T0,lex0[1]);
    {
     cl_object v7;
     v7 = lex0[4];
     if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
     if (Null(v7)) { goto L72; }
     {
      cl_object v8;
      v8 = ECL_CONS_CDR(v7);
      lex0[4] = v8;
      v7 = ECL_CONS_CAR(v7);
     }
L72:;
    }
L54:;
    if (lex0[3]==ECL_NIL) { goto L78; }
    T0 = ecl_car(lex0[3]);
    T1 = ecl_car(lex0[4]);
    if (!(ecl_equal(T0,T1))) { goto L78; }
    goto L53;
L78:;
    if ((lex0[3])!=ECL_NIL) { goto L81; }
    value0 = LC33makebody(lex0);
    return value0;
L81:;
    {
     cl_object v7;
     cl_object v8;
     cl_object v9bb;
     cl_object v10aa;
     cl_object v11lastdiff;
     cl_object v12count;
     cl_object v13inc;
     v7 = lex0[3];
     v8 = lex0[4];
     v9bb = v7;
     v10aa = v8;
     v11lastdiff = ECL_NIL;
     v12count = ecl_make_fixnum(0);
     v13inc = ECL_NIL;
     goto L93;
L92:;
     T0 = ecl_car(v9bb);
     T1 = ecl_car(v10aa);
     if (ecl_equal(T0,T1)) { goto L96; }
     v11lastdiff = v9bb;
     v12count = ecl_make_fixnum(0);
     goto L95;
L96:;
     T0 = ecl_car(v9bb);
     v13inc = L37estimate_code_size(T0, v2env);
     if (Null(v13inc)) { goto L102; }
     v12count = ecl_plus(v12count,v13inc);
     T0 = v12count;
     if (!(ecl_number_compare(T0,ecl_make_fixnum(v6threshold))>0)) { goto L95; }
     goto L101;
L102:;
L101:;
     {
      cl_object v14then;
      cl_object v15else;
      v14then = ECL_NIL;
      v15else = ECL_NIL;
      goto L113;
L112:;
      {
       cl_object v16;
       v16 = lex0[3];
       if (ecl_unlikely(!ECL_LISTP(v16))) FEtype_error_list(v16);
       if (Null(v16)) { goto L121; }
       {
        cl_object v17;
        v17 = ECL_CONS_CDR(v16);
        lex0[3] = v17;
        v16 = ECL_CONS_CAR(v16);
       }
L121:;
       T0 = v16;
      }
      v15else = CONS(T0,v15else);
      {
       cl_object v16;
       v16 = lex0[4];
       if (ecl_unlikely(!ECL_LISTP(v16))) FEtype_error_list(v16);
       if (Null(v16)) { goto L133; }
       {
        cl_object v17;
        v17 = ECL_CONS_CDR(v16);
        lex0[4] = v17;
        v16 = ECL_CONS_CAR(v16);
       }
L133:;
       T0 = v16;
      }
      v14then = CONS(T0,v14then);
      T0 = ecl_cdr(v11lastdiff);
      if (!((lex0[3])==(T0))) { goto L139; }
      goto L110;
L139:;
L113:;
      goto L112;
L110:;
      if ((lex0[5])!=ECL_NIL) { goto L142; }
      lex0[5] = ecl_symbol_value(VV[77]);
      T0 = cl_list(3, ECL_SYM("SETQ",751), lex0[5], ECL_T);
      v15else = CONS(T0,v15else);
L142:;
      T1 = LC31psimp(v14then);
      T0 = LC32pify(T1);
      T2 = LC31psimp(v15else);
      T1 = LC32pify(T2);
      T2 = cl_list(4, ECL_SYM("IF",946), lex0[5], T0, T1);
      lex0[1] = CONS(T2,lex0[1]);
     }
     goto L154;
L153:;
     {
      cl_object v14;
      v14 = lex0[4];
      if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
      if (Null(v14)) { goto L160; }
      {
       cl_object v15;
       v15 = ECL_CONS_CDR(v14);
       lex0[4] = v15;
       v14 = ECL_CONS_CAR(v14);
      }
L160:;
     }
     {
      cl_object v14;
      v14 = lex0[3];
      if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
      if (Null(v14)) { goto L172; }
      {
       cl_object v15;
       v15 = ECL_CONS_CDR(v14);
       lex0[3] = v15;
       v14 = ECL_CONS_CAR(v14);
      }
L172:;
      T0 = v14;
     }
     lex0[1] = CONS(T0,lex0[1]);
     T0 = ecl_cdr(v9bb);
     if (!((lex0[3])==(T0))) { goto L178; }
     goto L151;
L178:;
L154:;
     goto L153;
L151:;
     goto L83;
L95:;
     v9bb = ecl_cdr(v9bb);
     v10aa = ecl_cdr(v10aa);
L93:;
     if (v9bb==ECL_NIL) { goto L184; }
     goto L92;
L184:;
     value0 = LC33makebody(lex0);
     return value0;
    }
L83:;
L49:;
    goto L48;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	local function MAKEBODY                                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC33makebody(volatile cl_object *lex0)
{
 cl_object T0, T1, T2, T3, T4, T5, T6;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v1form;
   T1 = cl_nreverse(lex0[3]);
   T2 = ecl_append(lex0[0],T1);
   T0 = LC31psimp(T2);
   T2 = cl_nreconc(lex0[4], VV[82]);
   T3 = ecl_append(lex0[1],T2);
   T1 = LC31psimp(T3);
   T2 = LC31psimp(lex0[2]);
   T3 = CONS(VV[83],T2);
   T4 = ecl_append(T1,T3);
   T5 = CONS(VV[81],T4);
   T6 = ecl_append(T0,T5);
   v1form = CONS(ECL_SYM("TAGBODY",850),T6);
   if (Null(lex0[5])) { goto L5; }
   T0 = cl_list(2, lex0[5], ECL_NIL);
   T1 = ecl_list1(T0);
   value0 = cl_list(3, ECL_SYM("LET",477), T1, v1form);
   return value0;
L5:;
   value0 = v1form;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function PIFY                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC32pify(cl_object v1l)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_cdr(v1l);
  if (!(T0==ECL_NIL)) { goto L1; }
  value0 = ecl_car(v1l);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  value0 = CONS(ECL_SYM("PROGN",671),v1l);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function PSIMP                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC31psimp(cl_object v1l)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2ans;
   v2ans = ECL_NIL;
   {
    cl_object v3;
    v3 = v1l;
    goto L6;
L5:;
    {
     cl_object v4x;
     v4x = ecl_car(v3);
     if (Null(v4x)) { goto L10; }
     v2ans = CONS(v4x,v2ans);
     if (!(ECL_CONSP(v4x))) { goto L10; }
     {
      cl_object v5;
      v5 = ecl_car(v4x);
      if (!((v5)==(ECL_SYM("GO",414)))) { goto L20; }
      goto L17;
      goto L18;
L20:;
      goto L18;
L18:;
      if (!((v5)==(ECL_SYM("RETURN",724)))) { goto L24; }
      goto L17;
      goto L22;
L24:;
      goto L22;
L22:;
      if (!((v5)==(ECL_SYM("RETURN-FROM",725)))) { goto L10; }
      goto L14;
L17:;
     }
L14:;
     goto L2;
L10:;
    }
    v3 = ecl_cdr(v3);
L6:;
    if (Null(v3)) { goto L29; }
    goto L5;
L29:;
   }
L2:;
   value0 = cl_nreverse(v2ans);
   return value0;
  }
 }
}
/*	function definition for DUPLICATABLE-CODE-P                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L35duplicatable_code_p(cl_object v1expr, cl_object v2env)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(v1expr==ECL_NIL)) { goto L1; }
  value0 = ecl_make_fixnum(0);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  {
   cl_fixnum v3ans;
   {
    cl_object v4;
    v4 = L37estimate_code_size(v1expr, v2env);
    {
     bool v5;
     v5 = ECL_FIXNUMP(v4);
     if (ecl_unlikely(!(v5)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v4);
    }
    v3ans = ecl_fixnum(v4);
   }
   value0 = ecl_make_fixnum(v3ans);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for DESTRUCTURING-SIZE                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L36destructuring_size(cl_object v1x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2x;
   cl_object v3n;
   v2x = v1x;
   v3n = ecl_make_fixnum(0);
   goto L5;
L4:;
   {
    cl_object v4;
    v4 = ecl_cdr(v2x);
    T0 = ecl_car(v2x);
    T1 = L36destructuring_size(T0);
    v3n = ecl_plus(T1,v3n);
    v2x = v4;
   }
L5:;
   if (ECL_ATOM(v2x)) { goto L10; }
   goto L4;
L10:;
   {
    cl_fixnum v4;
    if (!(v2x==ECL_NIL)) { goto L13; }
    v4 = 0;
    goto L12;
L13:;
    v4 = 1;
L12:;
    value0 = ecl_plus(v3n,ecl_make_fixnum(v4));
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for ESTIMATE-CODE-SIZE                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L37estimate_code_size(cl_object volatile v1x, cl_object volatile v2env)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = VV[87];
  if (ecl_frs_push(cl_env_copy,value0)) {         /*  BEGIN CATCH 1   */
   value0 = cl_env_copy->values[0];
  } else {
   value0 = L39estimate_code_size_1(v1x, v2env);
  }
  ecl_frs_pop(cl_env_copy);                       /*  END CATCH 1     */
  return value0;
 }
}
/*	function definition for ESTIMATE-CODE-SIZE-1                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L39estimate_code_size_1(cl_object v1x, cl_object v2env)
{
 cl_object T0, T1, T2, T3, T4;
 volatile cl_object lex0[1];
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  lex0[0] = v2env;                                /*  ENV             */
TTL:
  if (Null(cl_constantp(1, v1x))) { goto L1; }
  value0 = ecl_make_fixnum(1);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (!(ECL_SYMBOLP(v1x))) { goto L3; }
  {
   cl_object v4;                                  /*  NEW-FORM        */
   cl_object v5;                                  /*  EXPANDED-P      */
   value0 = cl_macroexpand_1(2, v1x, lex0[0]);
   v4 = value0;
   v5 = cl_env_copy->values[1];
   if (Null(v5)) { goto L6; }
   v1x = v4;
   goto TTL;
L6:;
   value0 = ecl_make_fixnum(1);
   cl_env_copy->nvalues = 1;
   return value0;
  }
L3:;
  if (!(ECL_ATOM(v1x))) { goto L11; }
  value0 = ecl_make_fixnum(1);
  cl_env_copy->nvalues = 1;
  return value0;
L11:;
  T0 = ecl_car(v1x);
  if (!(ECL_SYMBOLP(T0))) { goto L13; }
  {
   cl_object v3;
   cl_object v4fn;
   cl_object v5tem;
   cl_fixnum v6n;
   v3 = ecl_car(v1x);
   {
    bool v7;
    v7 = ECL_SYMBOLP(v3);
    if (ecl_unlikely(!(v7)))
         FEwrong_type_argument(ECL_SYM("SYMBOL",840),v3);
   }
   v4fn = v3;
   v5tem = ECL_NIL;
   v6n = 0;
   v5tem = si_get_sysprop(v4fn, VV[87]);
   if (Null(v5tem)) { goto L20; }
   if (!(ECL_FIXNUMP(v5tem))) { goto L23; }
   {
    cl_fixnum v7;
    T0 = ecl_cdr(v1x);
    v7 = ecl_fixnum(LC38list_size(lex0, T0));
    value0 = ecl_plus(v5tem,ecl_make_fixnum(v7));
    cl_env_copy->nvalues = 1;
    return value0;
   }
L23:;
   value0 = ecl_function_dispatch(cl_env_copy,v5tem)(2, v1x, lex0[0]);
   return value0;
L20:;
   v5tem = ecl_assql(v4fn,ecl_symbol_value(VV[85]));
   if (Null(v5tem)) { goto L26; }
   T0 = ecl_cadr(v5tem);
   {
    cl_fixnum v8;
    T1 = ecl_cdr(v1x);
    v8 = ecl_fixnum(LC38list_size(lex0, T1));
    value0 = ecl_plus(T0,ecl_make_fixnum(v8));
    cl_env_copy->nvalues = 1;
    return value0;
   }
L26:;
   if (!((v4fn)==(ECL_SYM("COND",247)))) { goto L30; }
   {
    cl_object v9;
    v9 = ecl_cdr(v1x);
    goto L35;
L34:;
    {
     cl_object v10clause;
     v10clause = ecl_car(v9);
     {
      cl_object v11;
      v11 = LC38list_size(lex0, v10clause);
      {
       cl_object v12;
       v12 = ecl_plus(ecl_make_fixnum(v6n),v11);
       {
        bool v13;
        v13 = ECL_FIXNUMP(v12);
        if (ecl_unlikely(!(v13)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v12);
       }
       v6n = ecl_fixnum(v12);
      }
     }
     {
      cl_object v11;
      v11 = ecl_plus(ecl_make_fixnum(v6n),ecl_make_fixnum(1));
      {
       bool v12;
       v12 = ECL_FIXNUMP(v11);
       if (ecl_unlikely(!(v12)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v11);
      }
      v6n = ecl_fixnum(v11);
     }
    }
    v9 = ecl_cdr(v9);
L35:;
    if (Null(v9)) { goto L50; }
    goto L34;
L50:;
    value0 = ecl_make_fixnum(v6n);
    cl_env_copy->nvalues = 1;
    return value0;
   }
L30:;
   if (!((v4fn)==(VV[88]))) { goto L52; }
   {
    cl_object v10l;
    v10l = ecl_cdr(v1x);
    goto L57;
L56:;
    {
     cl_object v11;
     T0 = ecl_car(v10l);
     T1 = L36destructuring_size(T0);
     T2 = ecl_plus(ecl_make_fixnum(v6n),T1);
     T3 = ecl_cadr(v10l);
     T4 = L39estimate_code_size_1(T3, lex0[0]);
     v11 = ecl_plus(T2,T4);
     {
      bool v12;
      v12 = ECL_FIXNUMP(v11);
      if (ecl_unlikely(!(v12)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v11);
     }
     v6n = ecl_fixnum(v11);
    }
    v10l = ecl_cdr(v10l);
L57:;
    if (v10l==ECL_NIL) { goto L65; }
    goto L56;
L65:;
    value0 = ecl_make_fixnum(v6n);
    cl_env_copy->nvalues = 1;
    return value0;
   }
L52:;
   if (!((v4fn)==(ECL_SYM("SETQ",751)))) { goto L72; }
   goto L69;
   goto L70;
L72:;
   goto L70;
L70:;
   if (!((v4fn)==(ECL_SYM("PSETQ",676)))) { goto L67; }
   goto L68;
L69:;
L68:;
   {
    cl_object v11l;
    v11l = ecl_cdr(v1x);
    goto L78;
L77:;
    {
     cl_object v12;
     T0 = ecl_cadr(v11l);
     T1 = L39estimate_code_size_1(T0, lex0[0]);
     T2 = ecl_plus(ecl_make_fixnum(v6n),T1);
     v12 = ecl_plus(T2,ecl_make_fixnum(1));
     {
      bool v13;
      v13 = ECL_FIXNUMP(v12);
      if (ecl_unlikely(!(v13)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v12);
     }
     v6n = ecl_fixnum(v12);
    }
    v11l = ecl_cdr(v11l);
L78:;
    if (v11l==ECL_NIL) { goto L86; }
    goto L77;
L86:;
    value0 = ecl_make_fixnum(v6n);
    cl_env_copy->nvalues = 1;
    return value0;
   }
L67:;
   if (!((v4fn)==(ECL_SYM("GO",414)))) { goto L88; }
   value0 = ecl_make_fixnum(1);
   cl_env_copy->nvalues = 1;
   return value0;
L88:;
   if (!((v4fn)==(ECL_SYM("FUNCTION",396)))) { goto L90; }
   T0 = ecl_cadr(v1x);
   if (ECL_SYMBOLP(T0)) { goto L94; }
   T0 = ecl_cadr(v1x);
   if (!(ECL_CONSP(T0))) { goto L92; }
   T0 = ecl_caadr(v1x);
   if (!((T0)==(ECL_SYM("SETF",750)))) { goto L92; }
   goto L93;
L94:;
L93:;
   value0 = ecl_make_fixnum(1);
   cl_env_copy->nvalues = 1;
   return value0;
L92:;
   cl_env_copy->values[0] = ECL_NIL;
   cl_env_copy->nvalues = 1;
   cl_throw(VV[91]);
L90:;
   if (!((v4fn)==(ECL_SYM("MULTIPLE-VALUE-SETQ",576)))) { goto L98; }
   T0 = ecl_cadr(v1x);
   {
    cl_fixnum v12;
    v12 = ecl_length(T0);
    {
     cl_fixnum v13;
     T1 = ecl_cddr(v1x);
     v13 = ecl_fixnum(LC38list_size(lex0, T1));
     value0 = ecl_plus(ecl_make_fixnum(v12),ecl_make_fixnum(v13));
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
L98:;
   if (!((v4fn)==(ECL_SYM("RETURN-FROM",725)))) { goto L101; }
   T0 = ecl_caddr(v1x);
   T1 = L39estimate_code_size_1(T0, lex0[0]);
   value0 = ecl_one_plus(T1);
   cl_env_copy->nvalues = 1;
   return value0;
L101:;
   if ((cl_special_operator_p(v4fn))!=ECL_NIL) { goto L105; }
   if (Null(ecl_memql(v4fn,ecl_symbol_value(VV[86])))) { goto L103; }
   goto L104;
L105:;
L104:;
   cl_env_copy->values[0] = ECL_NIL;
   cl_env_copy->nvalues = 1;
   cl_throw(VV[87]);
L103:;
   {
    cl_object v15;                                /*  NEW-FORM        */
    cl_object v16;                                /*  EXPANDED-P      */
    value0 = cl_macroexpand_1(2, v1x, lex0[0]);
    v15 = value0;
    v16 = cl_env_copy->values[1];
    if (Null(v16)) { goto L109; }
    v1x = v15;
    goto TTL;
L109:;
    {
     cl_fixnum v17;
     T0 = ecl_cdr(v1x);
     v17 = ecl_fixnum(LC38list_size(lex0, T0));
     value0 = ecl_plus(ecl_make_fixnum(3),ecl_make_fixnum(v17));
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
  }
L13:;
  cl_env_copy->values[0] = ECL_NIL;
  cl_env_copy->nvalues = 1;
  cl_throw(VV[87]);
 }
}
/*	local function LIST-SIZE                                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC38list_size(volatile cl_object *lex0, cl_object v1l)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v2n;
   v2n = 0;
   {
    cl_object v3;
    v3 = v1l;
    goto L5;
L4:;
    {
     cl_object v4x;
     v4x = ecl_car(v3);
     {
      cl_object v5;
      v5 = L39estimate_code_size_1(v4x, lex0[0]);
      {
       cl_object v6;
       v6 = ecl_plus(ecl_make_fixnum(v2n),v5);
       {
        bool v7;
        v7 = ECL_FIXNUMP(v6);
        if (ecl_unlikely(!(v7)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v6);
       }
       v2n = ecl_fixnum(v6);
      }
     }
    }
    v3 = ecl_cdr(v3);
L5:;
    if (Null(v3)) { goto L16; }
    goto L4;
L16:;
    value0 = ecl_make_fixnum(v2n);
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for LOOP-CONTEXT                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L40loop_context()
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v1;
   cl_object v2l;
   cl_object v3new;
   v1 = ecl_symbol_value(VV[52]);
   v2l = v1;
   v3new = ECL_NIL;
   goto L6;
L5:;
   {
    cl_object v4;
    v4 = ecl_cdr(v2l);
    T0 = ecl_car(v2l);
    v3new = CONS(T0,v3new);
    v2l = v4;
   }
L6:;
   T0 = ecl_cdr(ecl_symbol_value(VV[50]));
   if ((v2l)==(T0)) { goto L11; }
   goto L5;
L11:;
   value0 = cl_nreverse(v3new);
   return value0;
  }
 }
}
/*	function definition for LOOP-ERROR                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L41loop_error(cl_narg narg, cl_object v1format_string, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2format_args;
  ecl_va_list args; ecl_va_start(args,v1format_string,narg,1);
  v2format_args = cl_grab_rest_args(args);
  ecl_va_end(args);
  T0 = L40loop_context();
  value0 = si_simple_program_error(4, _ecl_static_9, v1format_string, v2format_args, T0);
  return value0;
 }
}
/*	function definition for LOOP-WARN                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L42loop_warn(cl_narg narg, cl_object v1format_string, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2format_args;
  ecl_va_list args; ecl_va_start(args,v1format_string,narg,1);
  v2format_args = cl_grab_rest_args(args);
  ecl_va_end(args);
  T0 = L40loop_context();
  T1 = cl_list(3, v1format_string, v2format_args, T0);
  value0 = (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(5, VV[92], ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_9, ECL_SYM("FORMAT-ARGUMENTS",1239), T1) /*  WARN */;
  return value0;
 }
}
/*	function definition for LOOP-CHECK-DATA-TYPE                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L43loop_check_data_type(cl_narg narg, cl_object v1specified_type, cl_object v2required_type, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v3default_type;
  va_list args; va_start(args,v2required_type);
  {
   int i = 2;
   if (i >= narg) {
    v3default_type = v2required_type;
   } else {
    i++;
    v3default_type = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (!(v1specified_type==ECL_NIL)) { goto L2; }
  value0 = v3default_type;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  {
   cl_object v5;                                  /*  A               */
   cl_object v6;                                  /*  B               */
   value0 = cl_subtypep(2, v1specified_type, v2required_type);
   v5 = value0;
   v6 = cl_env_copy->values[1];
   if ((v6)!=ECL_NIL) { goto L6; }
   L42loop_warn(3, _ecl_static_10, v1specified_type, v2required_type);
   goto L5;
L6:;
   if ((v5)!=ECL_NIL) { goto L5; }
   L41loop_error(3, _ecl_static_11, v1specified_type, v2required_type);
L5:;
   value0 = v1specified_type;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function LOOP-FINISH                                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC44loop_finish(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_cdr(v1);
   if (Null(v3)) { goto L2; }
   si_dm_too_many_arguments(v1);
L2:;
   value0 = VV[93];
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for SUBST-GENSYMS-FOR-NIL                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L45subst_gensyms_for_nil(cl_object v1tree)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(v1tree==ECL_NIL)) { goto L1; }
  T0 = cl_gensym(0);
  cl_set(VV[95],CONS(T0,ecl_symbol_value(VV[95])));
  value0 = ecl_car(ecl_symbol_value(VV[95]));
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (!(ECL_ATOM(v1tree))) { goto L4; }
  value0 = v1tree;
  cl_env_copy->nvalues = 1;
  return value0;
L4:;
  T0 = ecl_car(v1tree);
  T1 = L45subst_gensyms_for_nil(T0);
  T2 = ecl_cdr(v1tree);
  T3 = L45subst_gensyms_for_nil(T2);
  value0 = CONS(T1,T3);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for LOOP-BUILD-DESTRUCTURING-BINDINGS     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L46loop_build_destructuring_bindings(cl_object v1crocks, cl_object v2forms)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1crocks)) { goto L1; }
  ecl_bds_bind(cl_env_copy,VV[95],ECL_NIL);       /*  *IGNORES*       */
  T0 = ecl_car(v1crocks);
  T1 = L45subst_gensyms_for_nil(T0);
  T2 = ecl_cadr(v1crocks);
  T3 = CONS(ECL_SYM("IGNORE",428),ecl_symbol_value(VV[95]));
  T4 = cl_list(2, ECL_SYM("DECLARE",274), T3);
  T5 = ecl_cddr(v1crocks);
  T6 = L46loop_build_destructuring_bindings(T5, v2forms);
  T7 = cl_listX(5, ECL_SYM("DESTRUCTURING-BIND",300), T1, T2, T4, T6);
  value0 = ecl_list1(T7);
  cl_env_copy->nvalues = 1;
  ecl_bds_unwind1(cl_env_copy);
  return value0;
L1:;
  value0 = v2forms;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for LOOP-TRANSLATE                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L47loop_translate(cl_object v1_loop_source_code_, cl_object v2_loop_macro_environment_, cl_object v3_loop_universe_)
{
 cl_object T0, T1, T2, T3, T4, T5, T6;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  ecl_bds_bind(cl_env_copy,VV[50],v1_loop_source_code_); /*  *LOOP-SOURCE-CODE* */
  ecl_bds_bind(cl_env_copy,VV[54],v2_loop_macro_environment_); /*  *LOOP-MACRO-ENVIRONMENT* */
  ecl_bds_bind(cl_env_copy,VV[31],v3_loop_universe_); /*  *LOOP-UNIVERSE* */
TTL:
  {
   cl_object v4;
   v4 = ecl_symbol_value(VV[50]);
   ecl_bds_bind(cl_env_copy,VV[51],v4);           /*  *LOOP-ORIGINAL-SOURCE-CODE* */
   ecl_bds_bind(cl_env_copy,VV[52],ECL_NIL);      /*  *LOOP-SOURCE-CONTEXT* */
   ecl_bds_bind(cl_env_copy,VV[62],ECL_NIL);      /*  *LOOP-ITERATION-VARIABLES* */
   ecl_bds_bind(cl_env_copy,VV[56],ECL_NIL);      /*  *LOOP-VARIABLES* */
   ecl_bds_bind(cl_env_copy,VV[61],ECL_NIL);      /*  *LOOP-NODECLARE* */
   ecl_bds_bind(cl_env_copy,VV[55],ECL_NIL);      /*  *LOOP-NAMED-VARIABLES* */
   ecl_bds_bind(cl_env_copy,VV[57],ECL_NIL);      /*  *LOOP-DECLARATIONS* */
   ecl_bds_bind(cl_env_copy,VV[58],ECL_NIL);      /*  *LOOP-DESETQ-CROCKS* */
   ecl_bds_bind(cl_env_copy,VV[60],ECL_NIL);      /*  *LOOP-BIND-STACK* */
   ecl_bds_bind(cl_env_copy,VV[63],ECL_NIL);      /*  *LOOP-PROLOGUE* */
   ecl_bds_bind(cl_env_copy,VV[59],ECL_NIL);      /*  *LOOP-WRAPPERS* */
   ecl_bds_bind(cl_env_copy,VV[64],ECL_NIL);      /*  *LOOP-BEFORE-LOOP* */
   ecl_bds_bind(cl_env_copy,VV[65],ECL_NIL);      /*  *LOOP-BODY*     */
   ecl_bds_bind(cl_env_copy,VV[67],ECL_NIL);      /*  *LOOP-EMITTED-BODY* */
   ecl_bds_bind(cl_env_copy,VV[66],ECL_NIL);      /*  *LOOP-AFTER-BODY* */
   ecl_bds_bind(cl_env_copy,VV[68],ECL_NIL);      /*  *LOOP-EPILOGUE* */
   ecl_bds_bind(cl_env_copy,VV[69],ECL_NIL);      /*  *LOOP-AFTER-EPILOGUE* */
   ecl_bds_bind(cl_env_copy,VV[70],ECL_NIL);      /*  *LOOP-FINAL-VALUE-CULPRIT* */
   ecl_bds_bind(cl_env_copy,VV[71],ECL_NIL);      /*  *LOOP-INSIDE-CONDITIONAL* */
   ecl_bds_bind(cl_env_copy,VV[72],ECL_NIL);      /*  *LOOP-WHEN-IT-VARIABLE* */
   ecl_bds_bind(cl_env_copy,VV[73],ECL_NIL);      /*  *LOOP-NEVER-STEPPED-VARIABLE* */
   ecl_bds_bind(cl_env_copy,VV[53],ECL_NIL);      /*  *LOOP-NAMES*    */
   ecl_bds_bind(cl_env_copy,VV[74],ECL_NIL);      /*  *LOOP-COLLECTION-CRUFT* */
   L48loop_iteration_driver();
   L63loop_bind_block();
   {
    cl_object v5answer;
    T0 = cl_nreverse(ecl_symbol_value(VV[63]));
    T1 = cl_nreverse(ecl_symbol_value(VV[64]));
    T2 = cl_nreverse(ecl_symbol_value(VV[65]));
    T3 = cl_nreverse(ecl_symbol_value(VV[66]));
    T4 = ecl_symbol_value(VV[68]);
    T5 = cl_nreverse(ecl_symbol_value(VV[69]));
    T6 = cl_nreconc(T4, T5);
    v5answer = cl_list(6, VV[84], T0, T1, T2, T3, T6);
    {
     cl_object v6;
     v6 = ecl_symbol_value(VV[60]);
     goto L9;
L8:;
     {
      cl_object v7entry;
      v7entry = ecl_car(v6);
      {
       cl_object v8;
       cl_object v9;
       cl_object v10;
       cl_object v11;
       v8 = ecl_car(v7entry);
       v9 = ecl_cadr(v7entry);
       v10 = ecl_caddr(v7entry);
       v11 = ecl_cadddr(v7entry);
       {
        cl_object v12;
        v12 = v11;
        goto L22;
L21:;
        {
         cl_object v13w;
         v13w = ecl_car(v12);
         T0 = ecl_list1(v5answer);
         v5answer = ecl_append(v13w,T0);
        }
        v12 = ecl_cdr(v12);
L22:;
        if (Null(v12)) { goto L30; }
        goto L21;
L30:;
       }
       if ((v8)!=ECL_NIL) { goto L33; }
       if ((v9)!=ECL_NIL) { goto L33; }
       if (Null(v10)) { goto L13; }
       goto L32;
L33:;
L32:;
       {
        cl_object v12forms;
        v12forms = ecl_list1(v5answer);
        if (Null(v9)) { goto L37; }
        T0 = CONS(ECL_SYM("DECLARE",274),v9);
        v12forms = CONS(T0,v12forms);
L37:;
        if ((v8)!=ECL_NIL) { goto L42; }
        T0 = ECL_SYM("LOCALLY",490);
        goto L41;
L42:;
        if (Null(ecl_symbol_value(VV[46]))) { goto L44; }
        T0 = ecl_car(ecl_symbol_value(VV[46]));
        goto L41;
L44:;
        T0 = ECL_SYM("LET",477);
L41:;
        T1 = L46loop_build_destructuring_bindings(v10, v12forms);
        v5answer = cl_listX(3, T0, v8, T1);
       }
      }
L13:;
     }
     v6 = ecl_cdr(v6);
L9:;
     if (Null(v6)) { goto L48; }
     goto L8;
L48:;
    }
    if (Null(ecl_symbol_value(VV[53]))) { goto L50; }
    goto L54;
L53:;
    {
     cl_object v6;
     v6 = ecl_symbol_value(VV[53]);
     if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
     if (Null(v6)) { goto L62; }
     {
      cl_object v7;
      v7 = ECL_CONS_CDR(v6);
      cl_set(VV[53],v7);
      v6 = ECL_CONS_CAR(v6);
     }
L62:;
     T0 = v6;
    }
    v5answer = cl_list(3, ECL_SYM("BLOCK",137), T0, v5answer);
L54:;
    T0 = ecl_car(ecl_symbol_value(VV[53]));
    if (T0==ECL_NIL) { goto L68; }
    goto L53;
L68:;
    value0 = v5answer;
    cl_env_copy->nvalues = 1;
    ecl_bds_unwind_n(cl_env_copy,26);
    return value0;
L50:;
    value0 = cl_list(3, ECL_SYM("BLOCK",137), ECL_NIL, v5answer);
    ecl_bds_unwind_n(cl_env_copy,26);
    return value0;
   }
  }
 }
}
/*	function definition for LOOP-ITERATION-DRIVER                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L48loop_iteration_driver()
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  goto L3;
L2:;
  {
   cl_object v1;
   cl_object v2tem;
   v1 = ecl_car(ecl_symbol_value(VV[50]));
   v2tem = ECL_NIL;
   if (ECL_SYMBOLP(v1)) { goto L8; }
   L41loop_error(2, _ecl_static_12, v1);
   goto L5;
L8:;
   cl_set(VV[52],ecl_symbol_value(VV[50]));
   L49loop_pop_source();
   T0 = ecl_function_dispatch(cl_env_copy,VV[266])(1, ecl_symbol_value(VV[31])) /*  LOOP-UNIVERSE-KEYWORDS */;
   v2tem = L18loop_lookup_keyword(v1, T0);
   if (Null(v2tem)) { goto L13; }
   T0 = ecl_car(v2tem);
   T1 = cl_symbol_function(T0);
   T2 = ecl_cdr(v2tem);
   cl_apply(2, T1, T2);
   goto L5;
L13:;
   T0 = ecl_function_dispatch(cl_env_copy,VV[267])(1, ecl_symbol_value(VV[31])) /*  LOOP-UNIVERSE-ITERATION-KEYWORDS */;
   v2tem = L18loop_lookup_keyword(v1, T0);
   if (Null(v2tem)) { goto L16; }
   L86loop_hack_iteration(v2tem);
   goto L5;
L16:;
   if (Null(L17loop_tmember(v1, VV[98]))) { goto L19; }
   T0 = ecl_car(ecl_symbol_value(VV[50]));
   T1 = ecl_cadr(ecl_symbol_value(VV[50]));
   L41loop_error(4, _ecl_static_13, v1, T0, T1);
   goto L5;
L19:;
   L41loop_error(2, _ecl_static_14, v1);
  }
L5:;
L3:;
  if (ecl_symbol_value(VV[50])==ECL_NIL) { goto L21; }
  goto L2;
L21:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for LOOP-POP-SOURCE                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L49loop_pop_source()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_symbol_value(VV[50]))) { goto L1; }
  {
   cl_object v1;
   v1 = ecl_symbol_value(VV[50]);
   if (ecl_unlikely(!ECL_LISTP(v1))) FEtype_error_list(v1);
   if (Null(v1)) { goto L6; }
   {
    cl_object v2;
    v2 = ECL_CONS_CDR(v1);
    cl_set(VV[50],v2);
    v1 = ECL_CONS_CAR(v1);
   }
L6:;
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L1:;
  value0 = L41loop_error(1, _ecl_static_15);
  return value0;
 }
}
/*	function definition for LOOP-GET-COMPOUND-FORM                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L50loop_get_compound_form()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v1form;
   v1form = L52loop_get_form();
   if (ECL_CONSP(v1form)) { goto L2; }
   L41loop_error(2, _ecl_static_16, v1form);
L2:;
   value0 = v1form;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for LOOP-GET-PROGN                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L51loop_get_progn()
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v1;
   cl_object v2;
   cl_object v3forms;
   cl_object v4nextform;
   T0 = L50loop_get_compound_form();
   v1 = ecl_list1(T0);
   v2 = ecl_car(ecl_symbol_value(VV[50]));
   v3forms = v1;
   v4nextform = v2;
   goto L7;
L6:;
   T0 = L50loop_get_compound_form();
   v3forms = CONS(T0,v3forms);
   v4nextform = ecl_car(ecl_symbol_value(VV[50]));
L7:;
   if (ECL_ATOM(v4nextform)) { goto L12; }
   goto L6;
L12:;
   T0 = ecl_cdr(v3forms);
   if (!(T0==ECL_NIL)) { goto L14; }
   value0 = ecl_car(v3forms);
   cl_env_copy->nvalues = 1;
   return value0;
L14:;
   T0 = cl_nreverse(v3forms);
   value0 = CONS(ECL_SYM("PROGN",671),T0);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for LOOP-GET-FORM                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L52loop_get_form()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_symbol_value(VV[50]))) { goto L1; }
  value0 = L49loop_pop_source();
  return value0;
L1:;
  value0 = L41loop_error(1, _ecl_static_17);
  return value0;
 }
}
/*	function definition for LOOP-CONSTRUCT-RETURN                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L53loop_construct_return(cl_object v1form)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_car(ecl_symbol_value(VV[53]));
  value0 = cl_list(3, ECL_SYM("RETURN-FROM",725), T0, v1form);
  return value0;
 }
}
/*	function definition for LOOP-EMIT-BODY                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L54loop_emit_body(cl_object v1form)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  cl_set(VV[67],ECL_T);
  cl_set(VV[65],CONS(v1form,ecl_symbol_value(VV[65])));
  value0 = ecl_symbol_value(VV[65]);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for LOOP-EMIT-FINAL-VALUE                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L55loop_emit_final_value(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1form;
  cl_object v2form_supplied_p;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1form = ECL_NIL;
    v2form_supplied_p = ECL_NIL;
   } else {
    i++;
    v1form = va_arg(args,cl_object);
    v2form_supplied_p = ECL_T;
   }
  }
  va_end(args);
  if (Null(v2form_supplied_p)) { goto L2; }
  T0 = L53loop_construct_return(v1form);
  cl_set(VV[69],CONS(T0,ecl_symbol_value(VV[69])));
L2:;
  if (Null(ecl_symbol_value(VV[70]))) { goto L5; }
  L42loop_warn(2, _ecl_static_18, ecl_symbol_value(VV[70]));
L5:;
  cl_set(VV[70],ecl_car(ecl_symbol_value(VV[52])));
  value0 = ecl_symbol_value(VV[70]);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for LOOP-DISALLOW-CONDITIONAL             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L56loop_disallow_conditional(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1kwd;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1kwd = ECL_NIL;
   } else {
    i++;
    v1kwd = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (Null(ecl_symbol_value(VV[71]))) { goto L2; }
  value0 = L41loop_error(2, _ecl_static_19, v1kwd);
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for LOOP-DISALLOW-ANONYMOUS-COLLECTORS    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L57loop_disallow_anonymous_collectors()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_find_if_not(2, VV[99], ecl_symbol_value(VV[74])))) { goto L1; }
  value0 = L41loop_error(1, _ecl_static_20);
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for LOOP-DISALLOW-AGGREGATE-BOOLEANS      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L58loop_disallow_aggregate_booleans()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(L17loop_tmember(ecl_symbol_value(VV[70]), VV[101]))) { goto L1; }
  value0 = L41loop_error(1, _ecl_static_21);
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for LOOP-TYPED-INIT                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L59loop_typed_init(cl_object v1data_type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(v1data_type==ECL_NIL)) { goto L1; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (Null(cl_subtypep(2, v1data_type, ECL_SYM("CHARACTER",222)))) { goto L3; }
  value0 = CODE_CHAR(48);
  cl_env_copy->nvalues = 1;
  return value0;
L3:;
  if ((cl_subtypep(2, v1data_type, ECL_SYM("NUMBER",606)))!=ECL_NIL) { goto L5; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L5:;
  if (Null(cl_subtypep(2, v1data_type, VV[103]))) { goto L7; }
  value0 = cl_coerce(ecl_make_fixnum(0), v1data_type);
  return value0;
L7:;
  value0 = ecl_make_fixnum(0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for LOOP-OPTIONAL-TYPE                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L62loop_optional_type(cl_narg narg, ...)
{
 cl_object T0, T1;
 volatile cl_object lex0[2];
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    lex0[0] = ECL_NIL;                            /*  VARIABLE        */
   } else {
    i++;
    lex0[0] = va_arg(args,cl_object);             /*  VARIABLE        */
   }
  }
  va_end(args);
  if (Null(ecl_symbol_value(VV[50]))) { goto L2; }
  T0 = ecl_car(ecl_symbol_value(VV[50]));
  lex0[1] = T0;                                   /*  Z               */
  if (Null(L15loop_tequal(lex0[1], VV[104]))) { goto L4; }
  L49loop_pop_source();
  value0 = L49loop_pop_source();
  return value0;
L4:;
  if (!(ECL_SYMBOLP(lex0[1]))) { goto L7; }
  {
   cl_object v1type_spec;
   T0 = ecl_function_dispatch(cl_env_copy,VV[270])(1, ecl_symbol_value(VV[31])) /*  LOOP-UNIVERSE-TYPE-SYMBOLS */;
   value0 = ecl_gethash_safe(lex0[1],T0,ECL_NIL);
   if ((value0)!=ECL_NIL) { goto L11; }
   T0 = ecl_symbol_name(lex0[1]);
   T1 = ecl_function_dispatch(cl_env_copy,VV[271])(1, ecl_symbol_value(VV[31])) /*  LOOP-UNIVERSE-TYPE-KEYWORDS */;
   v1type_spec = ecl_gethash_safe(T0,T1,ECL_NIL);
   goto L9;
L11:;
   v1type_spec = value0;
   goto L9;
L9:;
   if (Null(v1type_spec)) { goto L13; }
   L49loop_pop_source();
   value0 = v1type_spec;
   cl_env_copy->nvalues = 1;
   return value0;
L13:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L7:;
  if (!(ECL_CONSP(lex0[0]))) { goto L17; }
  if (ECL_CONSP(lex0[1])) { goto L16; }
  L41loop_error(2, _ecl_static_22, lex0[1]);
  goto L16;
L17:;
  L41loop_error(2, _ecl_static_23, lex0[1]);
L16:;
  L49loop_pop_source();
  value0 = LC60translate(lex0, lex0[1], lex0[0]);
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function REPLICATE                                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC61replicate(cl_object v1typ, cl_object v2v)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_ATOM(v2v))) { goto L1; }
  value0 = v1typ;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  T1 = ecl_car(v2v);
  T0 = LC61replicate(v1typ, T1);
  T2 = ecl_cdr(v2v);
  T1 = LC61replicate(v1typ, T2);
  value0 = CONS(T0,T1);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function TRANSLATE                                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC60translate(volatile cl_object *lex0, cl_object v1k, cl_object v2v)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(v1k==ECL_NIL)) { goto L1; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (!(ECL_ATOM(v1k))) { goto L3; }
  T1 = ecl_function_dispatch(cl_env_copy,VV[270])(1, ecl_symbol_value(VV[31])) /*  LOOP-UNIVERSE-TYPE-SYMBOLS */;
  value0 = ecl_gethash_safe(v1k,T1,ECL_NIL);
  if ((value0)!=ECL_NIL) { goto L7; }
  T1 = ecl_symbol_name(v1k);
  T2 = ecl_function_dispatch(cl_env_copy,VV[271])(1, ecl_symbol_value(VV[31])) /*  LOOP-UNIVERSE-TYPE-KEYWORDS */;
  value0 = ecl_gethash_safe(T1,T2,ECL_NIL);
  if ((value0)!=ECL_NIL) { goto L7; }
  T0 = L41loop_error(3, _ecl_static_24, lex0[1], v1k);
  goto L5;
L7:;
  T0 = value0;
  goto L5;
L5:;
  value0 = LC61replicate(T0, v2v);
  return value0;
L3:;
  if (!(ECL_ATOM(v2v))) { goto L10; }
  value0 = L41loop_error(3, _ecl_static_25, lex0[1], lex0[0]);
  return value0;
L10:;
  T1 = ecl_car(v1k);
  T2 = ecl_car(v2v);
  T0 = LC60translate(lex0, T1, T2);
  T2 = ecl_cdr(v1k);
  T3 = ecl_cdr(v2v);
  T1 = LC60translate(lex0, T2, T3);
  value0 = CONS(T0,T1);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for LOOP-BIND-BLOCK                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L63loop_bind_block()
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((ecl_symbol_value(VV[56]))!=ECL_NIL) { goto L3; }
  if ((ecl_symbol_value(VV[57]))!=ECL_NIL) { goto L3; }
  if (Null(ecl_symbol_value(VV[59]))) { goto L1; }
  goto L2;
L3:;
L2:;
  T0 = cl_nreverse(ecl_symbol_value(VV[56]));
  T1 = cl_list(4, T0, ecl_symbol_value(VV[57]), ecl_symbol_value(VV[58]), ecl_symbol_value(VV[59]));
  cl_set(VV[60],CONS(T1,ecl_symbol_value(VV[60])));
  cl_set(VV[56],ECL_NIL);
  cl_set(VV[57],ECL_NIL);
  cl_set(VV[58],ECL_NIL);
  cl_set(VV[59],ECL_NIL);
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for LOOP-VARIABLE-P                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L64loop_variable_p(cl_object v1name)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2entry;
   v2entry = ecl_symbol_value(VV[60]);
   goto L4;
L3:;
   if (!(v2entry==ECL_NIL)) { goto L7; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L7:;
   T0 = ecl_caar(v2entry);
   if (Null(ecl_assq(v1name,T0))) { goto L6; }
   value0 = ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
L6:;
   v2entry = ecl_cdr(v2entry);
L4:;
   goto L3;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for LOOP-MAKE-VARIABLE                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L65loop_make_variable(cl_narg narg, cl_object v1name, cl_object v2initialization, cl_object v3dtype, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>4)) FEwrong_num_arguments_anonym();
 {
  cl_object v4iteration_variable_p;
  va_list args; va_start(args,v3dtype);
  {
   int i = 3;
   if (i >= narg) {
    v4iteration_variable_p = ECL_NIL;
   } else {
    i++;
    v4iteration_variable_p = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (!(v1name==ECL_NIL)) { goto L3; }
  if (v2initialization==ECL_NIL) { goto L2; }
  v1name = cl_gensym(1, _ecl_static_26);
  T0 = cl_list(2, v1name, v2initialization);
  cl_set(VV[56],CONS(T0,ecl_symbol_value(VV[56])));
  T0 = cl_list(2, ECL_SYM("IGNORE",428), v1name);
  cl_set(VV[57],CONS(T0,ecl_symbol_value(VV[57])));
  goto L2;
L3:;
  if (!(ECL_ATOM(v1name))) { goto L10; }
  if (Null(v4iteration_variable_p)) { goto L13; }
  if (Null(ecl_memql(v1name,ecl_symbol_value(VV[62])))) { goto L15; }
  L41loop_error(2, _ecl_static_27, v1name);
  goto L12;
L15:;
  cl_set(VV[62],CONS(v1name,ecl_symbol_value(VV[62])));
  goto L12;
L13:;
  if (Null(ecl_assql(v1name,ecl_symbol_value(VV[56])))) { goto L12; }
  L41loop_error(2, _ecl_static_28, v1name);
L12:;
  if (ECL_SYMBOLP(v1name)) { goto L19; }
  L41loop_error(2, _ecl_static_29, v1name);
L19:;
  L67loop_declare_variable(v1name, v3dtype);
  value0 = v2initialization;
  if ((value0)!=ECL_NIL) { goto L25; }
  T0 = L59loop_typed_init(v3dtype);
  goto L23;
L25:;
  T0 = value0;
  goto L23;
L23:;
  T1 = cl_list(2, v1name, T0);
  cl_set(VV[56],CONS(T1,ecl_symbol_value(VV[56])));
  goto L2;
L10:;
  if (Null(v2initialization)) { goto L27; }
  if (Null(ecl_symbol_value(VV[46]))) { goto L29; }
  L67loop_declare_variable(v1name, v3dtype);
  T0 = cl_list(2, v1name, v2initialization);
  cl_set(VV[56],CONS(T0,ecl_symbol_value(VV[56])));
  goto L2;
L29:;
  {
   cl_object v5newvar;
   v5newvar = cl_gensym(1, _ecl_static_30);
   L67loop_declare_variable(v1name, v3dtype);
   T0 = cl_list(2, v5newvar, v2initialization);
   cl_set(VV[56],CONS(T0,ecl_symbol_value(VV[56])));
   cl_set(VV[58],cl_listX(3, v1name, v5newvar, ecl_symbol_value(VV[58])));
   goto L2;
  }
L27:;
  {
   cl_object v6tcar;
   cl_object v7tcdr;
   v6tcar = ECL_NIL;
   v7tcdr = ECL_NIL;
   if (!(ECL_ATOM(v3dtype))) { goto L41; }
   v7tcdr = v3dtype;
   v6tcar = v7tcdr;
   goto L40;
L41:;
   v6tcar = ecl_car(v3dtype);
   v7tcdr = ecl_cdr(v3dtype);
L40:;
   T0 = ecl_car(v1name);
   L65loop_make_variable(4, T0, ECL_NIL, v6tcar, v4iteration_variable_p);
   T0 = ecl_cdr(v1name);
   L65loop_make_variable(4, T0, ECL_NIL, v7tcdr, v4iteration_variable_p);
  }
L2:;
  value0 = v1name;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for LOOP-MAKE-ITERATION-VARIABLE          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L66loop_make_iteration_variable(cl_object v1name, cl_object v2initialization, cl_object v3dtype)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L65loop_make_variable(4, v1name, v2initialization, v3dtype, ECL_T);
  return value0;
 }
}
/*	function definition for LOOP-DECLARE-VARIABLE                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L67loop_declare_variable(cl_object v1name, cl_object v2dtype)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (v1name==ECL_NIL) { goto L3; }
  if (v2dtype==ECL_NIL) { goto L3; }
  if (!((v2dtype)==(ECL_T))) { goto L1; }
  goto L2;
L3:;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (!(ECL_SYMBOLP(v1name))) { goto L6; }
  if ((v2dtype)==(ECL_T)) { goto L8; }
  if ((ecl_memql(v1name,ecl_symbol_value(VV[61])))!=ECL_NIL) { goto L8; }
  {
   cl_object v3previous;
   {
    cl_object v4;
    cl_object v5;
    v4 = ecl_symbol_value(VV[57]);
    v5 = si_make_seq_iterator(2, v4, ecl_make_fixnum(0));
L14:;
    if ((v5)!=ECL_NIL) { goto L16; }
    v3previous = ECL_NIL;
    goto L11;
L16:;
    {
     cl_object v6;
     v6 = si_seq_iterator_ref(v4, v5);
     if (!(ECL_CONSP(v6))) { goto L23; }
     {
      cl_fixnum v7;
      v7 = ecl_length(v6);
      if (!((v7)==(3))) { goto L23; }
     }
     T1 = _ecl_car(v6);
     if (!((T1)==(ECL_SYM("TYPE",869)))) { goto L23; }
     T0 = ecl_caddr(v6);
     goto L21;
L23:;
     T0 = ECL_NIL;
     goto L21;
L21:;
     if (!(ecl_eql(v1name,T0))) { goto L18; }
     v3previous = v6;
     goto L11;
    }
L18:;
    v5 = si_seq_iterator_next(v4, v5);
    goto L14;
   }
L11:;
   if (Null(v3previous)) { goto L29; }
   {
    cl_object v4;
    v4 = ecl_cdr(v3previous);
    if (ecl_unlikely(ECL_ATOM(v4))) FEtype_error_cons(v4);
    T0 = v4;
   }
   (ECL_CONS_CAR(T0)=v2dtype,T0);
   value0 = v2dtype;
   cl_env_copy->nvalues = 1;
   return value0;
L29:;
   T0 = cl_list(3, ECL_SYM("TYPE",869), v2dtype, v1name);
   cl_set(VV[57],CONS(T0,ecl_symbol_value(VV[57])));
   value0 = ecl_symbol_value(VV[57]);
   cl_env_copy->nvalues = 1;
   return value0;
  }
L8:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L6:;
  if (!(ECL_CONSP(v1name))) { goto L36; }
  if (!(ECL_CONSP(v2dtype))) { goto L38; }
  T0 = ecl_car(v1name);
  T1 = ecl_car(v2dtype);
  L67loop_declare_variable(T0, T1);
  v1name = ecl_cdr(v1name);
  v2dtype = ecl_cdr(v2dtype);
  goto TTL;
L38:;
  T0 = ecl_car(v1name);
  L67loop_declare_variable(T0, v2dtype);
  v1name = ecl_cdr(v1name);
  goto TTL;
L36:;
  value0 = cl_error(2, _ecl_static_31, v1name);
  return value0;
 }
}
/*	function definition for LOOP-MAYBE-BIND-FORM                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L68loop_maybe_bind_form(cl_object v1form, cl_object v2data_type)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(L29loop_constantp(v1form))) { goto L1; }
  value0 = v1form;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  T0 = cl_gensym(1, _ecl_static_32);
  value0 = L65loop_make_variable(3, T0, v1form, v2data_type);
  return value0;
 }
}
/*	function definition for LOOP-DO-IF                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L70loop_do_if(cl_object v1for, cl_object v2negatep)
{
 cl_object T0, T1;
 volatile cl_object lex0[2];
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4form;
   v3 = L52loop_get_form();
   v4form = v3;
   ecl_bds_bind(cl_env_copy,VV[71],ECL_T);        /*  *LOOP-INSIDE-CONDITIONAL* */
   lex0[0] = ECL_NIL;                             /*  IT-P            */
   lex0[1] = ECL_T;                               /*  FIRST-CLAUSE-P  */
   {
    cl_object v5;
    cl_object v6;
    v5 = LC69get_clause(lex0, v1for);
    T0 = ecl_car(ecl_symbol_value(VV[50]));
    if (Null(L15loop_tequal(T0, VV[108]))) { goto L5; }
    L49loop_pop_source();
    T0 = LC69get_clause(lex0, VV[108]);
    v6 = ecl_list1(T0);
    goto L4;
L5:;
    v6 = ECL_NIL;
L4:;
    T0 = ecl_car(ecl_symbol_value(VV[50]));
    if (Null(L15loop_tequal(T0, ECL_SYM("END",1225)))) { goto L9; }
    L49loop_pop_source();
L9:;
    if (Null(lex0[0])) { goto L11; }
    T0 = lex0[0];
    v4form = cl_list(3, ECL_SYM("SETQ",751), T0, v4form);
L11:;
    if (Null(v2negatep)) { goto L15; }
    T0 = cl_list(2, ECL_SYM("NOT",584), v4form);
    goto L14;
L15:;
    T0 = v4form;
L14:;
    T1 = cl_listX(4, ECL_SYM("IF",946), T0, v5, v6);
    value0 = L54loop_emit_body(T1);
    ecl_bds_unwind1(cl_env_copy);
    return value0;
   }
  }
 }
}
/*	local function GET-CLAUSE                                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC69get_clause(volatile cl_object *lex0, cl_object v1for)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2body;
   v2body = ECL_NIL;
   goto L4;
L3:;
   {
    cl_object v3;
    cl_object v4data;
    v3 = ecl_car(ecl_symbol_value(VV[50]));
    ecl_bds_bind(cl_env_copy,VV[65],ECL_NIL);     /*  *LOOP-BODY*     */
    v4data = ECL_NIL;
    if (ECL_SYMBOLP(v3)) { goto L9; }
    L41loop_error(3, _ecl_static_33, v3, v1for);
    ecl_bds_unwind1(cl_env_copy);
    goto L6;
L9:;
    cl_set(VV[52],ecl_symbol_value(VV[50]));
    L49loop_pop_source();
    T0 = ecl_car(ecl_symbol_value(VV[50]));
    if (Null(L15loop_tequal(T0, VV[106]))) { goto L14; }
    if (Null(lex0[1])) { goto L14; }
    value0 = lex0[0];
    if ((value0)!=ECL_NIL) { goto L20; }
    lex0[0] = L89loop_when_it_variable();
    T0 = lex0[0];
    goto L18;
L20:;
    T0 = value0;
    goto L18;
L18:;
    T1 = ecl_cdr(ecl_symbol_value(VV[50]));
    cl_set(VV[50],CONS(T0,T1));
L14:;
    T0 = ecl_function_dispatch(cl_env_copy,VV[266])(1, ecl_symbol_value(VV[31])) /*  LOOP-UNIVERSE-KEYWORDS */;
    v4data = L18loop_lookup_keyword(v3, T0);
    if (Null(v4data)) { goto L25; }
    T0 = ecl_car(v4data);
    T1 = cl_symbol_function(T0);
    T2 = ecl_cdr(v4data);
    cl_apply(2, T1, T2);
    if (!(ecl_symbol_value(VV[65])==ECL_NIL)) { goto L23; }
    goto L24;
L25:;
L24:;
    L41loop_error(3, _ecl_static_34, v3, v1for);
    ecl_bds_unwind1(cl_env_copy);
    goto L6;
L23:;
    v2body = cl_nreconc(ecl_symbol_value(VV[65]), v2body);
    ecl_bds_unwind1(cl_env_copy);
   }
L6:;
   lex0[1] = ECL_NIL;
   T0 = ecl_car(ecl_symbol_value(VV[50]));
   if (Null(L15loop_tequal(T0, VV[107]))) { goto L33; }
   L49loop_pop_source();
   goto L32;
L33:;
   if (Null(ecl_cdr(v2body))) { goto L35; }
   T0 = cl_nreverse(v2body);
   value0 = CONS(ECL_SYM("PROGN",671),T0);
   cl_env_copy->nvalues = 1;
   return value0;
L35:;
   value0 = ecl_car(v2body);
   cl_env_copy->nvalues = 1;
   return value0;
L32:;
L4:;
   goto L3;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for LOOP-DO-INITIALLY                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L71loop_do_initially()
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  L56loop_disallow_conditional(1, VV[110]);
  T0 = L51loop_get_progn();
  cl_set(VV[63],CONS(T0,ecl_symbol_value(VV[63])));
  value0 = ecl_symbol_value(VV[63]);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for LOOP-DO-FINALLY                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L72loop_do_finally()
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  L56loop_disallow_conditional(1, VV[112]);
  T0 = L51loop_get_progn();
  cl_set(VV[68],CONS(T0,ecl_symbol_value(VV[68])));
  value0 = ecl_symbol_value(VV[68]);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for LOOP-DO-DO                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L73loop_do_do()
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = L51loop_get_progn();
  value0 = L54loop_emit_body(T0);
  return value0;
 }
}
/*	function definition for LOOP-DO-NAMED                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L74loop_do_named()
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v1name;
   v1name = L49loop_pop_source();
   if (ECL_SYMBOLP(v1name)) { goto L2; }
   L41loop_error(2, _ecl_static_35, v1name);
L2:;
   if ((ecl_symbol_value(VV[64]))!=ECL_NIL) { goto L6; }
   if ((ecl_symbol_value(VV[65]))!=ECL_NIL) { goto L6; }
   if ((ecl_symbol_value(VV[69]))!=ECL_NIL) { goto L6; }
   if (Null(ecl_symbol_value(VV[71]))) { goto L4; }
   goto L5;
L6:;
L5:;
   L41loop_error(2, _ecl_static_36, v1name);
L4:;
   if (Null(ecl_symbol_value(VV[53]))) { goto L10; }
   T0 = ecl_car(ecl_symbol_value(VV[53]));
   L41loop_error(3, _ecl_static_37, T0, v1name);
L10:;
   cl_set(VV[53],cl_list(2, v1name, ECL_NIL));
   value0 = ecl_symbol_value(VV[53]);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for LOOP-DO-RETURN                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L75loop_do_return()
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = L52loop_get_form();
  T1 = L53loop_construct_return(T0);
  value0 = L54loop_emit_body(T1);
  return value0;
 }
}
/*	function definition for MAKE-LOOP-COLLECTOR                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L76make_loop_collector(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1;
  cl_object v2;
  cl_object v3;
  cl_object v4;
  cl_object v5;
  cl_object v6;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  {
   cl_object keyvars[12];
   cl_parse_key(args,6,L76make_loop_collectorkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v1 = keyvars[0];
   v2 = keyvars[1];
   v3 = keyvars[2];
   v4 = keyvars[3];
   v5 = keyvars[4];
   v6 = keyvars[5];
  }
  T0 = cl_list(6, v1, v2, v3, v4, v5, v6);
  value0 = cl_make_array(5, VV[15], ECL_SYM("ELEMENT-TYPE",1224), ECL_T, ECL_SYM("INITIAL-CONTENTS",1252), T0);
  return value0;
 }
}
/*	function definition for LOOP-GET-COLLECTION-INFO              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L77loop_get_collection_info(cl_object v1collector, cl_object v2class, cl_object v3default_type)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4;
   cl_object v5;
   cl_object v6;
   cl_object v7dtype;
   v4 = L52loop_get_form();
   if ((ecl_function_dispatch(cl_env_copy,VV[286])(1, ecl_symbol_value(VV[31])) /*  LOOP-UNIVERSE-ANSI */)!=ECL_NIL) { goto L4; }
   v5 = L62loop_optional_type(0);
   goto L2;
L4:;
   v5 = ECL_NIL;
   goto L2;
L2:;
   T0 = ecl_car(ecl_symbol_value(VV[50]));
   if (Null(L15loop_tequal(T0, VV[120]))) { goto L7; }
   L49loop_pop_source();
   v6 = L49loop_pop_source();
   goto L6;
L7:;
   v6 = ECL_NIL;
L6:;
   v7dtype = v5;
   if (ECL_SYMBOLP(v6)) { goto L11; }
   L41loop_error(2, _ecl_static_39, v6);
L11:;
   if ((v6)!=ECL_NIL) { goto L13; }
   L58loop_disallow_aggregate_booleans();
L13:;
   if ((v7dtype)!=ECL_NIL) { goto L15; }
   value0 = L62loop_optional_type(0);
   if ((value0)!=ECL_NIL) { goto L19; }
   v7dtype = v3default_type;
   goto L17;
L19:;
   v7dtype = value0;
   goto L17;
L17:;
L15:;
   {
    cl_object v8cruft;
    {
     cl_object v9;
     cl_object v10;
     v9 = ecl_symbol_value(VV[74]);
     v10 = si_make_seq_iterator(2, v9, ecl_make_fixnum(0));
L24:;
     if ((v10)!=ECL_NIL) { goto L26; }
     v8cruft = ECL_NIL;
     goto L21;
L26:;
     {
      cl_object v11;
      v11 = si_seq_iterator_ref(v9, v10);
      T0 = ecl_function_dispatch(cl_env_copy,VV[99])(1, v11) /*  LOOP-COLLECTOR-NAME */;
      if (!((v6)==(T0))) { goto L28; }
      v8cruft = v11;
      goto L21;
     }
L28:;
     v10 = si_seq_iterator_next(v9, v10);
     goto L24;
    }
L21:;
    if ((v8cruft)!=ECL_NIL) { goto L34; }
    if (Null(v6)) { goto L36; }
    if (Null(L64loop_variable_p(v6))) { goto L36; }
    L41loop_error(2, _ecl_static_40, v6);
L36:;
    T0 = ecl_list1(v1collector);
    v8cruft = L76make_loop_collector(8, ECL_SYM("NAME",1273), v6, VV[121], v2class, VV[122], T0, VV[123], v7dtype);
    cl_set(VV[74],CONS(v8cruft,ecl_symbol_value(VV[74])));
    goto L33;
L34:;
    T0 = ecl_function_dispatch(cl_env_copy,VV[287])(1, v8cruft) /*  LOOP-COLLECTOR-CLASS */;
    if ((T0)==(v2class)) { goto L41; }
    T0 = ecl_function_dispatch(cl_env_copy,VV[288])(1, v8cruft) /*  LOOP-COLLECTOR-HISTORY */;
    T1 = ecl_car(T0);
    L41loop_error(4, _ecl_static_41, v6, T1, v1collector);
L41:;
    T0 = ecl_function_dispatch(cl_env_copy,VV[289])(1, v8cruft) /*  LOOP-COLLECTOR-DTYPE */;
    if (ecl_equal(v7dtype,T0)) { goto L43; }
    T0 = ecl_function_dispatch(cl_env_copy,VV[289])(1, v8cruft) /*  LOOP-COLLECTOR-DTYPE */;
    L42loop_warn(4, _ecl_static_42, v6, v7dtype, T0);
    T0 = ecl_function_dispatch(cl_env_copy,VV[289])(1, v8cruft) /*  LOOP-COLLECTOR-DTYPE */;
    if (!((T0)==(ECL_T))) { goto L43; }
    ecl_elt_set(v8cruft,4,v7dtype);
L43:;
    {
     cl_object v9;
     T0 = ecl_function_dispatch(cl_env_copy,VV[288])(1, v8cruft) /*  LOOP-COLLECTOR-HISTORY */;
     v9 = CONS(v1collector,T0);
     ecl_elt_set(v8cruft,2,v9);
    }
L33:;
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = v4;
    cl_env_copy->values[0] = v8cruft;
    return cl_env_copy->values[0];
   }
  }
 }
}
/*	function definition for LOOP-LIST-COLLECTION                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L78loop_list_collection(cl_object v1specifically)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;                                  /*  LC              */
   cl_object v4;                                  /*  FORM            */
   value0 = L77loop_get_collection_info(v1specifically, ECL_SYM("LIST",481), ECL_SYM("LIST",481));
   v3 = value0;
   {
    const int v5 = cl_env_copy->nvalues;
    cl_object v6;
    v6 = (v5<=1)? ECL_NIL : cl_env_copy->values[1];
    v4 = v6;
   }
   {
    cl_object v5tempvars;
    v5tempvars = ecl_function_dispatch(cl_env_copy,VV[291])(1, v3) /*  LOOP-COLLECTOR-TEMPVARS */;
    if ((v5tempvars)!=ECL_NIL) { goto L3; }
    {
     cl_object v6;
     T0 = cl_gensym(1, _ecl_static_43);
     T1 = cl_gensym(1, _ecl_static_44);
     if (Null(ecl_function_dispatch(cl_env_copy,VV[99])(1, v3) /*  LOOP-COLLECTOR-NAME */)) { goto L10; }
     T3 = ecl_function_dispatch(cl_env_copy,VV[99])(1, v3) /*  LOOP-COLLECTOR-NAME */;
     T2 = ecl_list1(T3);
     goto L8;
L10:;
     T2 = ECL_NIL;
     goto L8;
L8:;
     v5tempvars = cl_listX(3, T0, T1, T2);
     v6 = v5tempvars;
     ecl_elt_set(v3,3,v6);
    }
    T0 = cl_list(2, VV[5], v5tempvars);
    cl_set(VV[59],CONS(T0,ecl_symbol_value(VV[59])));
    if ((ecl_function_dispatch(cl_env_copy,VV[99])(1, v3) /*  LOOP-COLLECTOR-NAME */)!=ECL_NIL) { goto L3; }
    T0 = ecl_car(v5tempvars);
    T1 = ecl_cddr(v5tempvars);
    T2 = cl_listX(3, VV[12], T0, T1);
    L55loop_emit_final_value(1, T2);
L3:;
    if (!((v1specifically)==(ECL_SYM("LIST",481)))) { goto L16; }
    v4 = cl_list(2, ECL_SYM("LIST",481), v4);
    goto L15;
L16:;
    if ((v1specifically)==(ECL_SYM("NCONC",581))) { goto L15; }
    if (!((v1specifically)==(ECL_SYM("APPEND",88)))) { goto L20; }
    if (!(ECL_CONSP(v4))) { goto L24; }
    T0 = ecl_car(v4);
    if ((T0)==(ECL_SYM("LIST",481))) { goto L15; }
    goto L22;
L24:;
    goto L22;
L22:;
    v4 = cl_list(2, VV[2], v4);
    goto L15;
L20:;
    si_ecase_error(v1specifically, VV[124]);
L15:;
    T0 = cl_list(3, VV[11], v5tempvars, v4);
    value0 = L54loop_emit_body(T0);
    return value0;
   }
  }
 }
}
/*	function definition for LOOP-SUM-COLLECTION                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L79loop_sum_collection(cl_object v1specifically, cl_object v2required_type, cl_object v3default_type)
{
 cl_object T0, T1, T2, T3, T4, T5, T6;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v5;                                  /*  LC              */
   cl_object v6;                                  /*  FORM            */
   value0 = L77loop_get_collection_info(v1specifically, VV[126], v3default_type);
   v5 = value0;
   {
    const int v7 = cl_env_copy->nvalues;
    cl_object v8;
    v8 = (v7<=1)? ECL_NIL : cl_env_copy->values[1];
    v6 = v8;
   }
   T0 = ecl_function_dispatch(cl_env_copy,VV[289])(1, v5) /*  LOOP-COLLECTOR-DTYPE */;
   L43loop_check_data_type(2, T0, v2required_type);
   {
    cl_object v7tempvars;
    v7tempvars = ecl_function_dispatch(cl_env_copy,VV[291])(1, v5) /*  LOOP-COLLECTOR-TEMPVARS */;
    if ((v7tempvars)!=ECL_NIL) { goto L4; }
    {
     cl_object v8;
     value0 = ecl_function_dispatch(cl_env_copy,VV[99])(1, v5) /*  LOOP-COLLECTOR-NAME */;
     if ((value0)!=ECL_NIL) { goto L11; }
     T0 = cl_gensym(1, _ecl_static_45);
     goto L9;
L11:;
     T0 = value0;
     goto L9;
L9:;
     T1 = ecl_function_dispatch(cl_env_copy,VV[289])(1, v5) /*  LOOP-COLLECTOR-DTYPE */;
     T2 = L65loop_make_variable(3, T0, ECL_NIL, T1);
     v7tempvars = ecl_list1(T2);
     v8 = v7tempvars;
     ecl_elt_set(v5,3,v8);
    }
    if ((ecl_function_dispatch(cl_env_copy,VV[99])(1, v5) /*  LOOP-COLLECTOR-NAME */)!=ECL_NIL) { goto L4; }
    T0 = ecl_function_dispatch(cl_env_copy,VV[291])(1, v5) /*  LOOP-COLLECTOR-TEMPVARS */;
    T1 = ecl_car(T0);
    L55loop_emit_final_value(1, T1);
L4:;
    if (!((v1specifically)==(ECL_SYM("COUNT",266)))) { goto L15; }
    T1 = ecl_car(v7tempvars);
    T2 = ecl_car(v7tempvars);
    T3 = ecl_car(v7tempvars);
    T4 = cl_list(2, ECL_SYM("1+",70), T3);
    T5 = L5hide_variable_reference(ECL_T, T2, T4);
    T6 = cl_list(3, ECL_SYM("SETQ",751), T1, T5);
    T0 = cl_list(3, ECL_SYM("WHEN",905), v6, T6);
    goto L14;
L15:;
    T1 = ecl_car(v7tempvars);
    T2 = ecl_car(v7tempvars);
    T3 = ecl_car(v7tempvars);
    T4 = L5hide_variable_reference(ECL_T, T2, T3);
    T5 = cl_list(3, ECL_SYM("+",14), T4, v6);
    T0 = cl_list(3, ECL_SYM("SETQ",751), T1, T5);
L14:;
    value0 = L54loop_emit_body(T0);
    return value0;
   }
  }
 }
}
/*	function definition for LOOP-MAXMIN-COLLECTION                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L80loop_maxmin_collection(cl_object v1specifically)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;                                  /*  LC              */
   cl_object v4;                                  /*  FORM            */
   value0 = L77loop_get_collection_info(v1specifically, VV[128], ecl_symbol_value(VV[3]));
   v3 = value0;
   {
    const int v5 = cl_env_copy->nvalues;
    cl_object v6;
    v6 = (v5<=1)? ECL_NIL : cl_env_copy->values[1];
    v4 = v6;
   }
   T0 = ecl_function_dispatch(cl_env_copy,VV[289])(1, v3) /*  LOOP-COLLECTOR-DTYPE */;
   L43loop_check_data_type(2, T0, ecl_symbol_value(VV[3]));
   {
    cl_object v5data;
    v5data = ecl_function_dispatch(cl_env_copy,VV[294])(1, v3) /*  LOOP-COLLECTOR-DATA */;
    if ((v5data)!=ECL_NIL) { goto L4; }
    {
     cl_object v6;
     value0 = ecl_function_dispatch(cl_env_copy,VV[99])(1, v3) /*  LOOP-COLLECTOR-NAME */;
     if ((value0)!=ECL_NIL) { goto L11; }
     T0 = cl_gensym(1, _ecl_static_46);
     goto L9;
L11:;
     T0 = value0;
     goto L9;
L9:;
     T1 = ecl_function_dispatch(cl_env_copy,VV[289])(1, v3) /*  LOOP-COLLECTOR-DTYPE */;
     v5data = L11make_loop_minimax(T0, T1);
     v6 = v5data;
     ecl_elt_set(v3,5,v6);
    }
    if ((ecl_function_dispatch(cl_env_copy,VV[99])(1, v3) /*  LOOP-COLLECTOR-NAME */)!=ECL_NIL) { goto L4; }
    T0 = ecl_function_dispatch(cl_env_copy,VV[240])(1, v5data) /*  LOOP-MINIMAX-ANSWER-VARIABLE */;
    L55loop_emit_final_value(1, T0);
L4:;
    L12loop_note_minimax_operation(v1specifically, v5data);
    T0 = cl_list(2, VV[23], v5data);
    cl_set(VV[59],CONS(T0,ecl_symbol_value(VV[59])));
    T0 = cl_list(4, VV[25], v5data, v1specifically, v4);
    value0 = L54loop_emit_body(T0);
    return value0;
   }
  }
 }
}
/*	function definition for LOOP-DO-ALWAYS                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L81loop_do_always(cl_object v1restrictive, cl_object v2negate)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3form;
   v3form = L52loop_get_form();
   if (Null(v1restrictive)) { goto L2; }
   L56loop_disallow_conditional(0);
L2:;
   L57loop_disallow_anonymous_collectors();
   if (Null(v2negate)) { goto L7; }
   T0 = ECL_SYM("WHEN",905);
   goto L6;
L7:;
   T0 = ECL_SYM("UNLESS",883);
L6:;
   T1 = L53loop_construct_return(ECL_NIL);
   T2 = cl_list(3, T0, v3form, T1);
   L54loop_emit_body(T2);
   value0 = L55loop_emit_final_value(1, ECL_T);
   return value0;
  }
 }
}
/*	function definition for LOOP-DO-THEREIS                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L82loop_do_thereis(cl_object v1restrictive)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1restrictive)) { goto L1; }
  L56loop_disallow_conditional(0);
L1:;
  L57loop_disallow_anonymous_collectors();
  L55loop_emit_final_value(0);
  T0 = L89loop_when_it_variable();
  T1 = L52loop_get_form();
  T2 = cl_list(3, ECL_SYM("SETQ",751), T0, T1);
  T3 = L53loop_construct_return(ecl_symbol_value(VV[72]));
  T4 = cl_list(3, ECL_SYM("WHEN",905), T2, T3);
  value0 = L54loop_emit_body(T4);
  return value0;
 }
}
/*	function definition for LOOP-DO-WHILE                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L83loop_do_while(cl_object v1negate, cl_object v2kwd)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3form;
   v3form = L52loop_get_form();
   L56loop_disallow_conditional(1, v2kwd);
   if (Null(v1negate)) { goto L4; }
   T0 = ECL_SYM("WHEN",905);
   goto L3;
L4:;
   T0 = ECL_SYM("UNLESS",883);
L3:;
   T1 = cl_list(3, T0, v3form, VV[93]);
   value0 = L54loop_emit_body(T1);
   return value0;
  }
 }
}
/*	function definition for LOOP-DO-WITH                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L84loop_do_with()
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  L56loop_disallow_conditional(1, VV[133]);
  {
   cl_object v1var;
   cl_object v2val;
   cl_object v3dtype;
   v1var = ECL_NIL;
   v2val = ECL_NIL;
   v3dtype = ECL_NIL;
   goto L7;
L6:;
   v1var = L49loop_pop_source();
   v3dtype = L62loop_optional_type(1, v1var);
   T0 = ecl_car(ecl_symbol_value(VV[50]));
   if (Null(L15loop_tequal(T0, VV[134]))) { goto L15; }
   L49loop_pop_source();
   v2val = L52loop_get_form();
   goto L14;
L15:;
   v2val = ECL_NIL;
L14:;
   if (Null(v1var)) { goto L18; }
   if (Null(L64loop_variable_p(v1var))) { goto L18; }
   L41loop_error(2, _ecl_static_47, v1var);
L18:;
   L65loop_make_variable(3, v1var, v2val, v3dtype);
   T0 = ecl_car(ecl_symbol_value(VV[50]));
   if (Null(L15loop_tequal(T0, VV[107]))) { goto L23; }
   L49loop_pop_source();
   goto L22;
L23:;
   value0 = L63loop_bind_block();
   return value0;
L22:;
L7:;
   goto L6;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for LOOP-HACK-ITERATION                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L86loop_hack_iteration(cl_object v1entry)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2pre_step_tests;
   cl_object v3steps;
   cl_object v4post_step_tests;
   cl_object v5pseudo_steps;
   cl_object v6pre_loop_pre_step_tests;
   cl_object v7pre_loop_steps;
   cl_object v8pre_loop_post_step_tests;
   cl_object v9pre_loop_pseudo_steps;
   cl_object v10tem;
   cl_object v11data;
   v2pre_step_tests = ECL_NIL;
   v3steps = ECL_NIL;
   v4post_step_tests = ECL_NIL;
   v5pseudo_steps = ECL_NIL;
   v6pre_loop_pre_step_tests = ECL_NIL;
   v7pre_loop_steps = ECL_NIL;
   v8pre_loop_post_step_tests = ECL_NIL;
   v9pre_loop_pseudo_steps = ECL_NIL;
   v10tem = ECL_NIL;
   v11data = ECL_NIL;
   goto L13;
L12:;
   T0 = ecl_car(v1entry);
   T1 = cl_symbol_function(T0);
   T2 = ecl_cdr(v1entry);
   v11data = cl_apply(2, T1, T2);
   v10tem = v11data;
   if (Null(ecl_car(v10tem))) { goto L20; }
   T0 = ecl_car(v10tem);
   v2pre_step_tests = CONS(T0,v2pre_step_tests);
   goto L18;
L20:;
   goto L18;
L18:;
   v10tem = ecl_cdr(v10tem);
   T0 = ecl_car(v10tem);
   T1 = cl_copy_list(T0);
   v3steps = ecl_nconc(v3steps,T1);
   v10tem = ecl_cdr(v10tem);
   if (Null(ecl_car(v10tem))) { goto L28; }
   T0 = ecl_car(v10tem);
   v4post_step_tests = CONS(T0,v4post_step_tests);
   goto L26;
L28:;
   goto L26;
L26:;
   v10tem = ecl_cdr(v10tem);
   T0 = ecl_car(v10tem);
   T1 = cl_copy_list(T0);
   v5pseudo_steps = ecl_nconc(v5pseudo_steps,T1);
   v10tem = ecl_cdr(v10tem);
   if (Null(ecl_symbol_value(VV[67]))) { goto L37; }
   L42loop_warn(1, _ecl_static_48);
L37:;
   if ((v10tem)!=ECL_NIL) { goto L39; }
   v10tem = v11data;
L39:;
   if (Null(ecl_car(v10tem))) { goto L42; }
   T0 = ecl_car(v10tem);
   v6pre_loop_pre_step_tests = CONS(T0,v6pre_loop_pre_step_tests);
L42:;
   v10tem = ecl_cdr(v10tem);
   T0 = ecl_car(v10tem);
   T1 = cl_copy_list(T0);
   v7pre_loop_steps = ecl_nconc(v7pre_loop_steps,T1);
   v10tem = ecl_cdr(v10tem);
   if (Null(ecl_car(v10tem))) { goto L48; }
   T0 = ecl_car(v10tem);
   v8pre_loop_post_step_tests = CONS(T0,v8pre_loop_post_step_tests);
L48:;
   T0 = ecl_cadr(v10tem);
   T1 = cl_copy_list(T0);
   v9pre_loop_pseudo_steps = ecl_nconc(v9pre_loop_pseudo_steps,T1);
   T0 = ecl_car(ecl_symbol_value(VV[50]));
   if ((L15loop_tequal(T0, VV[107]))!=ECL_NIL) { goto L54; }
   T0 = L24loop_make_desetq(v9pre_loop_pseudo_steps);
   T1 = LC85make_endtest(v8pre_loop_post_step_tests);
   T2 = L23loop_make_psetq(v7pre_loop_steps);
   T3 = LC85make_endtest(v6pre_loop_pre_step_tests);
   cl_set(VV[64],cl_listX(5, T0, T1, T2, T3, ecl_symbol_value(VV[64])));
   T0 = L24loop_make_desetq(v5pseudo_steps);
   T1 = LC85make_endtest(v4post_step_tests);
   T2 = L23loop_make_psetq(v3steps);
   T3 = LC85make_endtest(v2pre_step_tests);
   cl_set(VV[66],cl_listX(5, T0, T1, T2, T3, ecl_symbol_value(VV[66])));
   L63loop_bind_block();
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L54:;
   L49loop_pop_source();
   if ((ecl_function_dispatch(cl_env_copy,VV[299])(1, ecl_symbol_value(VV[31])) /*  LOOP-UNIVERSE-IMPLICIT-FOR-REQUIRED */)!=ECL_NIL) { goto L66; }
   T0 = ecl_car(ecl_symbol_value(VV[50]));
   T1 = ecl_function_dispatch(cl_env_copy,VV[267])(1, ecl_symbol_value(VV[31])) /*  LOOP-UNIVERSE-ITERATION-KEYWORDS */;
   v10tem = L18loop_lookup_keyword(T0, T1);
   if (Null(v10tem)) { goto L66; }
   L49loop_pop_source();
   v1entry = v10tem;
L66:;
L13:;
   goto L12;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function MAKE-ENDTEST                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC85make_endtest(cl_object v1list_of_forms)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(v1list_of_forms==ECL_NIL)) { goto L1; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (Null(ecl_memql(ECL_T,v1list_of_forms))) { goto L3; }
  value0 = VV[93];
  cl_env_copy->nvalues = 1;
  return value0;
L3:;
  v1list_of_forms = cl_nreverse(v1list_of_forms);
  T1 = ecl_cdr(v1list_of_forms);
  if (!(T1==ECL_NIL)) { goto L6; }
  T0 = ecl_car(v1list_of_forms);
  goto L5;
L6:;
  T0 = CONS(ECL_SYM("OR",614),v1list_of_forms);
L5:;
  value0 = cl_list(3, ECL_SYM("WHEN",905), T0, VV[93]);
  return value0;
 }
}
/*	function definition for LOOP-DO-FOR                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L87loop_do_for()
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v1var;
   cl_object v2data_type;
   cl_object v3keyword;
   cl_object v4first_arg;
   cl_object v5tem;
   v1var = L49loop_pop_source();
   v2data_type = L62loop_optional_type(1, v1var);
   v3keyword = L49loop_pop_source();
   v4first_arg = ECL_NIL;
   v5tem = ECL_NIL;
   v4first_arg = L52loop_get_form();
   if (!(ECL_SYMBOLP(v3keyword))) { goto L11; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[301])(1, ecl_symbol_value(VV[31])) /*  LOOP-UNIVERSE-FOR-KEYWORDS */;
   v5tem = L18loop_lookup_keyword(v3keyword, T0);
   if ((v5tem)!=ECL_NIL) { goto L8; }
   goto L9;
L11:;
   goto L9;
L9:;
   L41loop_error(2, _ecl_static_49, v3keyword);
L8:;
   T0 = ecl_car(v5tem);
   T1 = ecl_cdr(v5tem);
   value0 = cl_apply(5, T0, v1var, v4first_arg, v2data_type, T1);
   return value0;
  }
 }
}
/*	function definition for LOOP-DO-REPEAT                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L88loop_do_repeat()
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  L56loop_disallow_conditional(1, VV[137]);
  {
   cl_object v1form;
   cl_object v2type;
   cl_object v3var;
   cl_object v4form;
   v1form = L52loop_get_form();
   if (!(ECL_FIXNUMP(v1form))) { goto L4; }
   v2type = ECL_SYM("FIXNUM",372);
   goto L3;
L4:;
   v2type = ECL_SYM("REAL",703);
L3:;
   T0 = cl_gensym(0);
   v3var = L65loop_make_variable(3, T0, v1form, v2type);
   T0 = cl_list(2, ECL_SYM("DECF",271), v3var);
   T1 = cl_list(2, ECL_SYM("MINUSP",558), T0);
   T2 = cl_list(3, ECL_SYM("WHEN",905), T1, VV[93]);
   v4form = cl_list(2, VV[1], T2);
   cl_set(VV[64],CONS(v4form,ecl_symbol_value(VV[64])));
   cl_set(VV[66],CONS(v4form,ecl_symbol_value(VV[66])));
   value0 = ecl_symbol_value(VV[66]);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for LOOP-WHEN-IT-VARIABLE                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L89loop_when_it_variable()
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_symbol_value(VV[72]);
  if ((value0)!=ECL_NIL) { goto L2; }
  T0 = cl_gensym(1, _ecl_static_50);
  cl_set(VV[72],L65loop_make_variable(3, T0, ECL_NIL, ECL_NIL));
  value0 = ecl_symbol_value(VV[72]);
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for LOOP-ANSI-FOR-EQUALS                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L90loop_ansi_for_equals(cl_object v1var, cl_object v2val, cl_object v3data_type)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  L66loop_make_iteration_variable(v1var, ECL_NIL, v3data_type);
  T0 = ecl_car(ecl_symbol_value(VV[50]));
  if (Null(L15loop_tequal(T0, VV[139]))) { goto L2; }
  L49loop_pop_source();
  T0 = L52loop_get_form();
  T1 = cl_list(2, v1var, T0);
  T2 = cl_list(2, v1var, v2val);
  value0 = cl_listX(7, ECL_NIL, T1, ECL_NIL, ECL_NIL, ECL_NIL, T2, VV[140]);
  return value0;
L2:;
  T0 = cl_list(2, v1var, v2val);
  value0 = cl_listX(3, ECL_NIL, T0, VV[140]);
  return value0;
 }
}
/*	function definition for LOOP-FOR-ACROSS                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L91loop_for_across(cl_object v1var, cl_object v2val, cl_object v3data_type)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  L66loop_make_iteration_variable(v1var, ECL_NIL, v3data_type);
  {
   cl_object v4;
   cl_object v5;
   v4 = cl_gensym(1, _ecl_static_51);
   v5 = cl_gensym(1, _ecl_static_52);
   {
    cl_object v7;                                 /*  VECTOR-FORM     */
    cl_object v8;                                 /*  CONSTANTP       */
    cl_object v9;                                 /*  VECTOR-VALUE    */
    value0 = L28loop_constant_fold_if_possible(2, v2val, ECL_SYM("VECTOR",898));
    v7 = value0;
    {
     const int v10 = cl_env_copy->nvalues;
     cl_object v11;
     v11 = (v10<=1)? ECL_NIL : cl_env_copy->values[1];
     v8 = v11;
     v11 = (v10<=2)? ECL_NIL : cl_env_copy->values[2];
     v9 = v11;
    }
    if (!(ECL_CONSP(v7))) { goto L7; }
    T1 = ecl_car(v7);
    if (!((T1)==(ECL_SYM("THE",856)))) { goto L7; }
    T0 = ecl_cadr(v7);
    goto L6;
L7:;
    T0 = ECL_SYM("VECTOR",898);
L6:;
    L65loop_make_variable(3, v4, v7, T0);
    L65loop_make_variable(3, v5, ecl_make_fixnum(0), ECL_SYM("FIXNUM",372));
    {
     cl_fixnum v10length;
     cl_object v11length_form;
     cl_object v12first_test;
     cl_object v13other_test;
     cl_object v14step;
     cl_object v15pstep;
     v10length = 0;
     if ((v8)!=ECL_NIL) { goto L13; }
     {
      cl_object v16v;
      v16v = cl_gensym(1, _ecl_static_53);
      T0 = cl_list(2, ECL_SYM("LENGTH",476), v4);
      T1 = cl_list(3, ECL_SYM("SETQ",751), v16v, T0);
      cl_set(VV[63],CONS(T1,ecl_symbol_value(VV[63])));
      v11length_form = L65loop_make_variable(3, v16v, ecl_make_fixnum(0), ECL_SYM("FIXNUM",372));
      goto L12;
     }
L13:;
     v10length = ecl_length(v9);
     v11length_form = ecl_make_fixnum(v10length);
L12:;
     v12first_test = cl_list(3, ECL_SYM(">=",76), v5, v11length_form);
     v13other_test = v12first_test;
     T0 = cl_list(3, ECL_SYM("AREF",92), v4, v5);
     v14step = cl_list(2, v1var, T0);
     T0 = cl_list(2, ECL_SYM("1+",70), v5);
     v15pstep = cl_list(2, v5, T0);
     if (Null(v8)) { goto L23; }
     v12first_test = ecl_make_bool((v10length)==(0));
     if (!((v10length)<=(1))) { goto L23; }
     v13other_test = ECL_T;
L23:;
     if ((v12first_test)==(v13other_test)) { goto L31; }
     T0 = cl_list(4, v12first_test, v14step, ECL_NIL, v15pstep);
     goto L29;
L31:;
     T0 = ECL_NIL;
     goto L29;
L29:;
     value0 = cl_listX(5, v13other_test, v14step, ECL_NIL, v15pstep, T0);
     return value0;
    }
   }
  }
 }
}
/*	function definition for LOOP-LIST-STEP                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L92loop_list_step(cl_object v1listvar)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2stepper;
   T0 = ecl_car(ecl_symbol_value(VV[50]));
   if (Null(L15loop_tequal(T0, VV[143]))) { goto L2; }
   L49loop_pop_source();
   v2stepper = L52loop_get_form();
   goto L1;
L2:;
   v2stepper = VV[144];
L1:;
   if (!(ECL_CONSP(v2stepper))) { goto L5; }
   T0 = ecl_car(v2stepper);
   if (!((T0)==(ECL_SYM("QUOTE",679)))) { goto L5; }
   L42loop_warn(1, _ecl_static_54);
   T0 = cl_list(3, ECL_SYM("FUNCALL",394), v2stepper, v1listvar);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = ECL_NIL;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
L5:;
   if (!(ECL_CONSP(v2stepper))) { goto L9; }
   T0 = ecl_car(v2stepper);
   if (!((T0)==(ECL_SYM("FUNCTION",396)))) { goto L9; }
   T0 = ecl_cadr(v2stepper);
   T1 = cl_list(2, T0, v1listvar);
   T2 = ecl_cadr(v2stepper);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = T2;
   cl_env_copy->values[0] = T1;
   return cl_env_copy->values[0];
L9:;
   T0 = cl_gensym(1, _ecl_static_55);
   T1 = L65loop_make_variable(3, T0, v2stepper, ECL_SYM("FUNCTION",396));
   T2 = cl_list(3, ECL_SYM("FUNCALL",394), T1, v1listvar);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = ECL_NIL;
   cl_env_copy->values[0] = T2;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for LOOP-FOR-ON                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L93loop_for_on(cl_object v1var, cl_object v2val, cl_object v3data_type)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v5;                                  /*  LIST            */
   cl_object v6;                                  /*  CONSTANTP       */
   cl_object v7;                                  /*  LIST-VALUE      */
   value0 = L28loop_constant_fold_if_possible(1, v2val);
   v5 = value0;
   {
    const int v8 = cl_env_copy->nvalues;
    cl_object v9;
    v9 = (v8<=1)? ECL_NIL : cl_env_copy->values[1];
    v6 = v9;
    v9 = (v8<=2)? ECL_NIL : cl_env_copy->values[2];
    v7 = v9;
   }
   {
    cl_object v8listvar;
    v8listvar = v1var;
    if (Null(v1var)) { goto L4; }
    if (!(ECL_SYMBOLP(v1var))) { goto L4; }
    L66loop_make_iteration_variable(v1var, v5, v3data_type);
    goto L3;
L4:;
    v8listvar = cl_gensym(0);
    L65loop_make_variable(3, v8listvar, v5, ECL_SYM("LIST",481));
    L66loop_make_iteration_variable(v1var, ECL_NIL, v3data_type);
L3:;
    {
     cl_object v10;                               /*  LIST-STEP       */
     value0 = L92loop_list_step(v8listvar);
     v10 = value0;
     {
      cl_object v11first_endtest;
      cl_object v12other_endtest;
      {
       bool v13;
       v13 = (v1var)==(v8listvar);
       T0 = cl_list(2, ECL_SYM("ATOM",119), v8listvar);
       v11first_endtest = L5hide_variable_reference(ecl_make_bool(v13), v8listvar, T0);
      }
      v12other_endtest = v11first_endtest;
      if (Null(v6)) { goto L12; }
      if (!(ECL_LISTP(v7))) { goto L12; }
      v11first_endtest = ecl_make_bool(v7==ECL_NIL);
L12:;
      if (!((v1var)==(v8listvar))) { goto L16; }
      T0 = L5hide_variable_reference(ECL_T, v8listvar, v10);
      T1 = cl_list(2, v8listvar, T0);
      value0 = cl_list(8, ECL_NIL, T1, v12other_endtest, ECL_NIL, ECL_NIL, ECL_NIL, v11first_endtest, ECL_NIL);
      return value0;
L16:;
      {
       cl_object v13;
       cl_object v14;
       v13 = cl_list(2, v1var, v8listvar);
       v14 = cl_list(2, v8listvar, v10);
       if ((v11first_endtest)==(v12other_endtest)) { goto L22; }
       T0 = cl_list(4, v11first_endtest, v13, ECL_NIL, v14);
       goto L20;
L22:;
       T0 = ECL_NIL;
       goto L20;
L20:;
       value0 = cl_listX(5, v12other_endtest, v13, ECL_NIL, v14, T0);
       return value0;
      }
     }
    }
   }
  }
 }
}
/*	function definition for LOOP-FOR-IN                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L94loop_for_in(cl_object v1var, cl_object v2val, cl_object v3data_type)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v5;                                  /*  LIST            */
   cl_object v6;                                  /*  CONSTANTP       */
   cl_object v7;                                  /*  LIST-VALUE      */
   value0 = L28loop_constant_fold_if_possible(1, v2val);
   v5 = value0;
   {
    const int v8 = cl_env_copy->nvalues;
    cl_object v9;
    v9 = (v8<=1)? ECL_NIL : cl_env_copy->values[1];
    v6 = v9;
    v9 = (v8<=2)? ECL_NIL : cl_env_copy->values[2];
    v7 = v9;
   }
   {
    cl_object v8listvar;
    v8listvar = cl_gensym(1, _ecl_static_56);
    L66loop_make_iteration_variable(v1var, ECL_NIL, v3data_type);
    L65loop_make_variable(3, v8listvar, v5, ECL_SYM("LIST",481));
    {
     cl_object v10;                               /*  LIST-STEP       */
     value0 = L92loop_list_step(v8listvar);
     v10 = value0;
     {
      cl_object v11first_endtest;
      cl_object v12other_endtest;
      cl_object v13step;
      cl_object v14pseudo_step;
      v11first_endtest = cl_list(2, ECL_SYM("ENDP",330), v8listvar);
      v12other_endtest = v11first_endtest;
      T0 = cl_list(2, ECL_SYM("CONS-CAR",1778), v8listvar);
      v13step = cl_list(2, v1var, T0);
      v14pseudo_step = cl_list(2, v8listvar, v10);
      if (Null(v6)) { goto L10; }
      if (!(ECL_LISTP(v7))) { goto L10; }
      v11first_endtest = ecl_make_bool(v7==ECL_NIL);
L10:;
      if ((v11first_endtest)==(v12other_endtest)) { goto L16; }
      T0 = cl_list(4, v11first_endtest, v13step, ECL_NIL, v14pseudo_step);
      goto L14;
L16:;
      T0 = ECL_NIL;
      goto L14;
L14:;
      value0 = cl_listX(5, v12other_endtest, v13step, ECL_NIL, v14pseudo_step, T0);
      return value0;
     }
    }
   }
  }
 }
}
/*	function definition for MAKE-LOOP-PATH                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L95make_loop_path(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1;
  cl_object v2;
  cl_object v3;
  cl_object v4;
  cl_object v5;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  {
   cl_object keyvars[10];
   cl_parse_key(args,5,L95make_loop_pathkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v1 = keyvars[0];
   v2 = keyvars[1];
   v3 = keyvars[2];
   v4 = keyvars[3];
   v5 = keyvars[4];
  }
  T0 = cl_list(5, v1, v2, v3, v4, v5);
  value0 = cl_make_array(5, VV[149], ECL_SYM("ELEMENT-TYPE",1224), ECL_T, ECL_SYM("INITIAL-CONTENTS",1252), T0);
  return value0;
 }
}
/*	function definition for ADD-LOOP-PATH                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L96add_loop_path(cl_narg narg, cl_object v1names, cl_object v2function, cl_object v3universe, ...)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 {
  cl_object v4preposition_groups;
  cl_object v5inclusive_permitted;
  cl_object v6user_data;
  ecl_va_list args; ecl_va_start(args,v3universe,narg,3);
  {
   cl_object keyvars[6];
   cl_parse_key(args,3,L96add_loop_pathkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v4preposition_groups = keyvars[0];
   v5inclusive_permitted = keyvars[1];
   v6user_data = keyvars[2];
  }
  if (ECL_LISTP(v1names)) { goto L1; }
  v1names = ecl_list1(v1names);
L1:;
  {
   cl_object v7;
   cl_object v8;
   v7 = ecl_function_dispatch(cl_env_copy,VV[316])(1, v3universe) /*  LOOP-UNIVERSE-PATH-KEYWORDS */;
   {
    cl_object v9;
    cl_object v10;
    v9 = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v1names))) FEtype_error_list(v1names);
    v10 = v1names;
    {
     cl_object v11;
     cl_object v12;
     v11 = ecl_list1(ECL_NIL);
     v12 = v11;
L12:;
     if (!(ecl_endp(v10))) { goto L14; }
     goto L13;
L14:;
     v9 = _ecl_car(v10);
     {
      cl_object v13;
      v13 = _ecl_cdr(v10);
      if (ecl_unlikely(!ECL_LISTP(v13))) FEtype_error_list(v13);
      v10 = v13;
     }
     if (ecl_unlikely(ECL_ATOM(v12))) FEtype_error_cons(v12);
     T1 = v12;
     T2 = ecl_symbol_name(v9);
     v12 = ecl_list1(T2);
     (ECL_CONS_CDR(T1)=v12,T1);
     goto L12;
L13:;
     T0 = ecl_cdr(v11);
     goto L6;
    }
   }
L6:;
   {
    cl_object v9;
    cl_object v10;
    v9 = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v4preposition_groups))) FEtype_error_list(v4preposition_groups);
    v10 = v4preposition_groups;
    {
     cl_object v11;
     cl_object v12;
     v11 = ecl_list1(ECL_NIL);
     v12 = v11;
L34:;
     if (!(ecl_endp(v10))) { goto L36; }
     goto L35;
L36:;
     v9 = _ecl_car(v10);
     {
      cl_object v13;
      v13 = _ecl_cdr(v10);
      if (ecl_unlikely(!ECL_LISTP(v13))) FEtype_error_list(v13);
      v10 = v13;
     }
     if (ecl_unlikely(ECL_ATOM(v12))) FEtype_error_cons(v12);
     T2 = v12;
     if (!(ECL_LISTP(v9))) { goto L49; }
     T3 = v9;
     goto L48;
L49:;
     T3 = ecl_list1(v9);
L48:;
     v12 = ecl_list1(T3);
     (ECL_CONS_CDR(T2)=v12,T2);
     goto L34;
L35:;
     T1 = ecl_cdr(v11);
     goto L28;
    }
   }
L28:;
   v8 = L95make_loop_path(10, VV[151], T0, ECL_SYM("FUNCTION",1241), v2function, VV[152], v6user_data, VV[153], T1, VV[154], v5inclusive_permitted);
   {
    cl_object v9;
    v9 = v1names;
    goto L57;
L56:;
    {
     cl_object v10name;
     v10name = ecl_car(v9);
     T0 = ecl_symbol_name(v10name);
     si_hash_set(T0, v7, v8);
    }
    v9 = ecl_cdr(v9);
L57:;
    if (Null(v9)) { goto L64; }
    goto L56;
L64:;
   }
   value0 = v8;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for LOOP-FOR-BEING                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L97loop_for_being(cl_object v1var, cl_object v2val, cl_object v3data_type)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4path;
   cl_object v5data;
   cl_object v6inclusive;
   cl_object v7stuff;
   cl_object v8initial_prepositions;
   v4path = ECL_NIL;
   v5data = ECL_NIL;
   v6inclusive = ECL_NIL;
   v7stuff = ECL_NIL;
   v8initial_prepositions = ECL_NIL;
   if (Null(L17loop_tmember(v2val, VV[155]))) { goto L7; }
   v4path = L49loop_pop_source();
   goto L6;
L7:;
   T0 = ecl_car(ecl_symbol_value(VV[50]));
   if (Null(L15loop_tequal(T0, VV[107]))) { goto L10; }
   L49loop_pop_source();
   v6inclusive = ECL_T;
   T0 = ecl_car(ecl_symbol_value(VV[50]));
   if ((L17loop_tmember(T0, VV[156]))!=ECL_NIL) { goto L15; }
   T0 = ecl_car(ecl_symbol_value(VV[50]));
   L41loop_error(2, _ecl_static_58, T0);
L15:;
   L49loop_pop_source();
   v4path = L49loop_pop_source();
   T0 = cl_list(2, VV[157], v2val);
   v8initial_prepositions = ecl_list1(T0);
   goto L6;
L10:;
   L41loop_error(1, _ecl_static_59);
L6:;
   if (ECL_SYMBOLP(v4path)) { goto L22; }
   L41loop_error(2, _ecl_static_60, v4path);
   goto L21;
L22:;
   T0 = ecl_function_dispatch(cl_env_copy,VV[316])(1, ecl_symbol_value(VV[31])) /*  LOOP-UNIVERSE-PATH-KEYWORDS */;
   v5data = L18loop_lookup_keyword(v4path, T0);
   if ((v5data)!=ECL_NIL) { goto L24; }
   L41loop_error(2, _ecl_static_61, v4path);
   goto L21;
L24:;
   if (Null(v6inclusive)) { goto L21; }
   if ((ecl_function_dispatch(cl_env_copy,VV[318])(1, v5data) /*  LOOP-PATH-INCLUSIVE-PERMITTED */)!=ECL_NIL) { goto L21; }
   L41loop_error(2, _ecl_static_62, v4path);
L21:;
   {
    cl_object v9;
    cl_object v10;
    cl_object v11;
    cl_object v12fun;
    v9 = ecl_function_dispatch(cl_env_copy,VV[319])(1, v5data) /*  LOOP-PATH-FUNCTION */;
    T0 = ecl_function_dispatch(cl_env_copy,VV[320])(1, v5data) /*  LOOP-PATH-PREPOSITION-GROUPS */;
    T1 = L100loop_collect_prepositional_phrases(2, T0, ECL_T);
    v10 = ecl_nconc(v8initial_prepositions,T1);
    v11 = ecl_function_dispatch(cl_env_copy,VV[321])(1, v5data) /*  LOOP-PATH-USER-DATA */;
    v12fun = v9;
    if (!(ECL_SYMBOLP(v12fun))) { goto L34; }
    v12fun = cl_symbol_function(v12fun);
L34:;
    if (Null(v6inclusive)) { goto L38; }
    v7stuff = cl_apply(7, v12fun, v1var, v3data_type, v10, VV[158], ECL_T, v11);
    goto L37;
L38:;
    v7stuff = cl_apply(5, v12fun, v1var, v3data_type, v10, v11);
L37:;
   }
   if (Null(ecl_symbol_value(VV[55]))) { goto L40; }
   L41loop_error(2, _ecl_static_63, ecl_symbol_value(VV[55]));
L40:;
   {
    cl_fixnum v9;
    v9 = ecl_length(v7stuff);
    if (!((v9)==(6))) { goto L47; }
    goto L42;
    goto L45;
L47:;
    goto L45;
L45:;
    if (!((v9)==(10))) { goto L50; }
    goto L42;
    goto L43;
L50:;
    goto L43;
   }
L43:;
   L41loop_error(2, _ecl_static_64, v4path);
L42:;
   {
    cl_object v9;
    cl_object v10l;
    cl_object v11x;
    v9 = ecl_car(v7stuff);
    v10l = v9;
    v11x = ECL_NIL;
    goto L58;
L57:;
    v11x = ecl_car(v10l);
    if (!(ECL_ATOM(v11x))) { goto L61; }
    L66loop_make_iteration_variable(v11x, ECL_NIL, ECL_NIL);
    goto L60;
L61:;
    T0 = ecl_car(v11x);
    T1 = ecl_cadr(v11x);
    T2 = ecl_caddr(v11x);
    L66loop_make_iteration_variable(T0, T1, T2);
L60:;
    v10l = ecl_cdr(v10l);
L58:;
    if (v10l==ECL_NIL) { goto L66; }
    goto L57;
L66:;
   }
   T0 = ecl_cadr(v7stuff);
   T1 = cl_reverse(T0);
   cl_set(VV[63],ecl_nconc(T1,ecl_symbol_value(VV[63])));
   value0 = ecl_cddr(v7stuff);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for NAMED-VARIABLE                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L98named_variable(cl_object v1name)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2tem;
   {
    cl_object v3;
    v3 = L16loop_tassoc(v1name, ecl_symbol_value(VV[55]));
    if (ecl_unlikely(!ECL_LISTP(v3))) FEtype_error_list(v3);
    v2tem = v3;
   }
   if (!(v2tem==ECL_NIL)) { goto L4; }
   T0 = cl_gensym(0);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = ECL_NIL;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
L4:;
   cl_set(VV[55],cl_delete(2, v2tem, ecl_symbol_value(VV[55])));
   T0 = ecl_cdr(v2tem);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = ECL_T;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for LOOP-COLLECT-PREPOSITIONAL-PHRASES    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L100loop_collect_prepositional_phrases(cl_narg narg, cl_object v1preposition_groups, ...)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v2using_allowed;
  cl_object v3initial_phrases;
  va_list args; va_start(args,v1preposition_groups);
  {
   int i = 1;
   if (i >= narg) {
    v2using_allowed = ECL_NIL;
   } else {
    i++;
    v2using_allowed = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v3initial_phrases = ECL_NIL;
   } else {
    i++;
    v3initial_phrases = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v4;
   cl_object v5;
   cl_object v6token;
   cl_object v7prepositional_phrases;
   cl_object v8this_group;
   cl_object v9this_prep;
   cl_object v10used_prepositions;
   {
    cl_object v11;
    cl_object v12;
    v11 = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v3initial_phrases))) FEtype_error_list(v3initial_phrases);
    v12 = v3initial_phrases;
    {
     cl_object v13;
     cl_object v14;
     v13 = ecl_list1(ECL_NIL);
     v14 = v13;
L9:;
     if (!(ecl_endp(v12))) { goto L11; }
     goto L10;
L11:;
     v11 = _ecl_car(v12);
     {
      cl_object v15;
      v15 = _ecl_cdr(v12);
      if (ecl_unlikely(!ECL_LISTP(v15))) FEtype_error_list(v15);
      v12 = v15;
     }
     {
      cl_object v15;
      {
       cl_object v16;
       v16 = ecl_car(v11);
       {
        cl_object v17;
        v17 = si_make_seq_iterator(2, v1preposition_groups, ecl_make_fixnum(0));
L25:;
        if ((v17)!=ECL_NIL) { goto L27; }
        T0 = ECL_NIL;
        goto L22;
L27:;
        {
         cl_object v18;
         v18 = si_seq_iterator_ref(v1preposition_groups, v17);
         if (Null(LC99in_group_p(v16, v18))) { goto L29; }
         T0 = v18;
         goto L22;
        }
L29:;
        v17 = si_seq_iterator_next(v1preposition_groups, v17);
        goto L25;
       }
      }
L22:;
      v15 = cl_copy_list(T0);
      if (ecl_unlikely(ECL_ATOM(v14))) FEtype_error_cons(v14);
      T0 = v14;
      (ECL_CONS_CDR(T0)=v15,T0);
      if (Null(v15)) { goto L19; }
     }
     T0 = ecl_cdr(v14);
     v14 = ecl_last(T0,1);
L19:;
     goto L9;
L10:;
     v4 = ecl_cdr(v13);
     goto L3;
    }
   }
L3:;
   {
    cl_object v11;
    cl_object v12;
    v11 = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v3initial_phrases))) FEtype_error_list(v3initial_phrases);
    v12 = v3initial_phrases;
    {
     cl_object v13;
     cl_object v14;
     v13 = ecl_list1(ECL_NIL);
     v14 = v13;
L46:;
     if (!(ecl_endp(v12))) { goto L48; }
     goto L47;
L48:;
     v11 = _ecl_car(v12);
     {
      cl_object v15;
      v15 = _ecl_cdr(v12);
      if (ecl_unlikely(!ECL_LISTP(v15))) FEtype_error_list(v15);
      v12 = v15;
     }
     if (ecl_unlikely(ECL_ATOM(v14))) FEtype_error_cons(v14);
     T0 = v14;
     T1 = ecl_car(v11);
     v14 = ecl_list1(T1);
     (ECL_CONS_CDR(T0)=v14,T0);
     goto L46;
L47:;
     v5 = ecl_cdr(v13);
     goto L40;
    }
   }
L40:;
   v6token = ECL_NIL;
   v7prepositional_phrases = v3initial_phrases;
   v8this_group = ECL_NIL;
   v9this_prep = ECL_NIL;
   v10used_prepositions = v5;
   goto L69;
L68:;
   v6token = ecl_car(ecl_symbol_value(VV[50]));
   {
    cl_object v11;
    v11 = v1preposition_groups;
    goto L77;
L76:;
    {
     cl_object v12group;
     v12group = ecl_car(v11);
     {
      cl_object v13;
      v13 = LC99in_group_p(v6token, v12group);
      {
       bool v14;
       v14 = ECL_SYMBOLP(v13);
       if (ecl_unlikely(!(v14)))
         FEwrong_type_argument(ECL_SYM("SYMBOL",840),v13);
      }
      v9this_prep = v13;
     }
     if (Null(v9this_prep)) { goto L81; }
     v8this_group = v12group;
     goto L73;
L81:;
    }
    v11 = ecl_cdr(v11);
L77:;
    if (Null(v11)) { goto L89; }
    goto L76;
L89:;
   }
L73:;
   if (Null(v8this_group)) { goto L92; }
   if (Null(ecl_memql(v9this_prep,v4))) { goto L94; }
   if (Null(ecl_memql(v9this_prep,v10used_prepositions))) { goto L97; }
   T0 = _ecl_static_65;
   goto L96;
L97:;
   T0 = _ecl_static_66;
L96:;
   L41loop_error(2, T0, v6token);
L94:;
   if (!(ECL_LISTP(v8this_group))) { goto L101; }
   v10used_prepositions = ecl_append(v8this_group,v10used_prepositions);
   goto L100;
L101:;
   v10used_prepositions = CONS(v8this_group,v10used_prepositions);
L100:;
   L49loop_pop_source();
   T0 = L52loop_get_form();
   T1 = cl_list(2, v9this_prep, T0);
   v7prepositional_phrases = CONS(T1,v7prepositional_phrases);
   goto L91;
L92:;
   if (Null(v2using_allowed)) { goto L105; }
   if (Null(L15loop_tequal(v6token, VV[162]))) { goto L105; }
   L49loop_pop_source();
   {
    cl_object v11;
    cl_object v12z;
    cl_object v13tem;
    v11 = L49loop_pop_source();
    v12z = v11;
    v13tem = ECL_NIL;
    goto L114;
L113:;
    if (Null(ecl_cadr(v12z))) { goto L116; }
    T0 = ecl_car(v12z);
    v13tem = L16loop_tassoc(T0, ecl_symbol_value(VV[55]));
    if (Null(v13tem)) { goto L118; }
    T0 = ecl_car(v12z);
    T1 = ecl_cadr(v12z);
    T2 = ecl_cadr(v13tem);
    L41loop_error(4, _ecl_static_67, T0, T1, T2);
    goto L116;
L118:;
    T0 = ecl_car(v12z);
    T1 = ecl_cadr(v12z);
    T2 = CONS(T0,T1);
    cl_set(VV[55],CONS(T2,ecl_symbol_value(VV[55])));
L116:;
    if (ecl_symbol_value(VV[50])==ECL_NIL) { goto L124; }
    T0 = ecl_car(ecl_symbol_value(VV[50]));
    if (!(ECL_SYMBOLP(T0))) { goto L122; }
    goto L123;
L124:;
L123:;
    goto L91;
L122:;
    v12z = L49loop_pop_source();
L114:;
    goto L113;
    goto L91;
   }
L105:;
   value0 = cl_nreverse(v7prepositional_phrases);
   return value0;
L91:;
   v8this_group = ECL_NIL;
   v9this_prep = ECL_NIL;
L69:;
   if (ecl_symbol_value(VV[50])==ECL_NIL) { goto L132; }
   goto L68;
L132:;
   value0 = cl_nreverse(v7prepositional_phrases);
   return value0;
  }
 }
}
/*	local function IN-GROUP-P                                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC99in_group_p(cl_object v1x, cl_object v2group)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = L17loop_tmember(v1x, v2group);
  value0 = ecl_car(T0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for LOOP-SEQUENCER                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L101loop_sequencer(cl_object v1indexv, cl_object v2indexv_type, cl_object v3indexv_user_specified_p, cl_object v4variable, cl_object v5variable_type, cl_object v6sequence_variable, cl_object v7sequence_type, cl_object v8step_hack, cl_object v9default_top, cl_object v10prep_phrases)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v11;
   cl_object v12endform;
   cl_object v13sequencep;
   cl_object v14testfn;
   cl_object v15test;
   cl_object v16stepby;
   cl_object v17stepby_constantp;
   cl_object v18step;
   cl_object v19dir;
   cl_object v20inclusive_iteration;
   cl_object v21start_given;
   cl_object v22start_value;
   cl_object v23start_constantp;
   cl_object v24limit_given;
   cl_object v25limit_constantp;
   cl_object v26limit_value;
   value0 = L59loop_typed_init(v2indexv_type);
   if ((value0)!=ECL_NIL) { goto L4; }
   T0 = ecl_make_fixnum(0);
   goto L2;
L4:;
   T0 = value0;
   goto L2;
L2:;
   v11 = ecl_one_plus(T0);
   v12endform = ECL_NIL;
   v13sequencep = ECL_NIL;
   v14testfn = ECL_NIL;
   v15test = ECL_NIL;
   v16stepby = v11;
   v17stepby_constantp = ECL_T;
   v18step = ECL_NIL;
   v19dir = ECL_NIL;
   v20inclusive_iteration = ECL_NIL;
   v21start_given = ECL_NIL;
   v22start_value = ECL_NIL;
   v23start_constantp = ECL_NIL;
   v24limit_given = ECL_NIL;
   v25limit_constantp = ECL_NIL;
   v26limit_value = ECL_NIL;
   if (Null(v4variable)) { goto L21; }
   L66loop_make_iteration_variable(v4variable, ECL_NIL, v5variable_type);
L21:;
   {
    cl_object v27l;
    cl_object v28prep;
    cl_object v29form;
    cl_object v30odir;
    v27l = v10prep_phrases;
    v28prep = ECL_NIL;
    v29form = ECL_NIL;
    v30odir = ECL_NIL;
    goto L30;
L29:;
    v28prep = ecl_caar(v27l);
    v29form = ecl_cadar(v27l);
    if (!(ecl_eql(v28prep,VV[163]))) { goto L42; }
    goto L39;
    goto L40;
L42:;
    goto L40;
L40:;
    if (!(ecl_eql(v28prep,VV[157]))) { goto L37; }
    goto L38;
L39:;
L38:;
    v13sequencep = ECL_T;
    L65loop_make_variable(3, v6sequence_variable, v29form, v7sequence_type);
    goto L36;
L37:;
    if (!(ecl_eql(v28prep,VV[166]))) { goto L52; }
    goto L49;
    goto L50;
L52:;
    goto L50;
L50:;
    if (!(ecl_eql(v28prep,VV[168]))) { goto L56; }
    goto L49;
    goto L54;
L56:;
    goto L54;
L54:;
    if (!(ecl_eql(v28prep,VV[170]))) { goto L47; }
    goto L48;
L49:;
L48:;
    v21start_given = ECL_T;
    if (!((v28prep)==(VV[168]))) { goto L62; }
    v19dir = VV[172];
    goto L61;
L62:;
    if (!((v28prep)==(VV[170]))) { goto L61; }
    v19dir = ECL_SYM("UP",1321);
L61:;
    value0 = L28loop_constant_fold_if_possible(2, v29form, v2indexv_type);
    v29form = value0;
    {
     const int v31 = cl_env_copy->nvalues;
     cl_object v32;
     v32 = (v31<=1)? ECL_NIL : cl_env_copy->values[1];
     v23start_constantp = v32;
     v32 = (v31<=2)? ECL_NIL : cl_env_copy->values[2];
     v22start_value = v32;
    }
    L66loop_make_iteration_variable(v1indexv, v29form, v2indexv_type);
    goto L36;
L47:;
    if (Null(ecl_memql(v28prep,VV[173]))) { goto L69; }
    if (Null(L15loop_tequal(v28prep, VV[174]))) { goto L72; }
    v19dir = ECL_SYM("UP",1321);
    v20inclusive_iteration = ECL_SYM("UP",1321);
    goto L71;
L72:;
    if (Null(L15loop_tequal(v28prep, VV[175]))) { goto L76; }
    v20inclusive_iteration = ECL_T;
    goto L71;
L76:;
    if (Null(L15loop_tequal(v28prep, VV[176]))) { goto L79; }
    v19dir = VV[172];
    v20inclusive_iteration = VV[172];
    goto L71;
L79:;
    if (Null(L15loop_tequal(v28prep, VV[177]))) { goto L83; }
    v19dir = VV[172];
    goto L71;
L83:;
    if (Null(L15loop_tequal(v28prep, VV[178]))) { goto L71; }
    v19dir = ECL_SYM("UP",1321);
L71:;
    v24limit_given = ECL_T;
    value0 = L28loop_constant_fold_if_possible(2, v29form, v2indexv_type);
    v29form = value0;
    {
     const int v31 = cl_env_copy->nvalues;
     cl_object v32;
     v32 = (v31<=1)? ECL_NIL : cl_env_copy->values[1];
     v25limit_constantp = v32;
     v32 = (v31<=2)? ECL_NIL : cl_env_copy->values[2];
     v26limit_value = v32;
    }
    if (Null(v25limit_constantp)) { goto L93; }
    v12endform = cl_list(2, ECL_SYM("QUOTE",679), v26limit_value);
    goto L92;
L93:;
    T0 = cl_gensym(1, _ecl_static_68);
    v12endform = L65loop_make_variable(3, T0, v29form, v2indexv_type);
L92:;
    goto L36;
L69:;
    if (!(ecl_eql(v28prep,VV[143]))) { goto L95; }
    value0 = L28loop_constant_fold_if_possible(2, v29form, v2indexv_type);
    v29form = value0;
    {
     const int v31 = cl_env_copy->nvalues;
     cl_object v32;
     v32 = (v31<=1)? ECL_NIL : cl_env_copy->values[1];
     v17stepby_constantp = v32;
     v32 = (v31<=2)? ECL_NIL : cl_env_copy->values[2];
     v16stepby = v32;
    }
    if ((v17stepby_constantp)!=ECL_NIL) { goto L36; }
    v16stepby = cl_gensym(1, _ecl_static_69);
    L65loop_make_variable(3, v16stepby, v29form, v2indexv_type);
    goto L36;
L95:;
    L41loop_error(2, _ecl_static_70, v28prep);
L36:;
    if (Null(v30odir)) { goto L101; }
    if (Null(v19dir)) { goto L101; }
    if ((v19dir)==(v30odir)) { goto L101; }
    L41loop_error(1, _ecl_static_71);
L101:;
    v30odir = v19dir;
    v27l = ecl_cdr(v27l);
L30:;
    if (v27l==ECL_NIL) { goto L109; }
    goto L29;
L109:;
   }
   if (Null(v6sequence_variable)) { goto L111; }
   if ((v13sequencep)!=ECL_NIL) { goto L111; }
   L41loop_error(1, _ecl_static_72);
L111:;
   if ((v21start_given)!=ECL_NIL) { goto L114; }
   v23start_constantp = ECL_T;
   value0 = L59loop_typed_init(v2indexv_type);
   if ((value0)!=ECL_NIL) { goto L120; }
   v22start_value = ecl_make_fixnum(0);
   goto L118;
L120:;
   v22start_value = value0;
   goto L118;
L118:;
   L66loop_make_iteration_variable(v1indexv, v22start_value, v2indexv_type);
L114:;
   if (!((v19dir)==(ECL_NIL))) { goto L128; }
   goto L125;
   goto L126;
L128:;
   goto L126;
L126:;
   if (!(ecl_eql(v19dir,ECL_SYM("UP",1321)))) { goto L123; }
   goto L124;
L125:;
L124:;
   if ((v24limit_given)!=ECL_NIL) { goto L133; }
   if (Null(v9default_top)) { goto L131; }
   goto L132;
L133:;
L132:;
   if ((v24limit_given)!=ECL_NIL) { goto L135; }
   v12endform = cl_gensym(1, _ecl_static_73);
   L65loop_make_variable(3, v12endform, ECL_NIL, v2indexv_type);
   T0 = cl_list(3, ECL_SYM("SETQ",751), v12endform, v9default_top);
   cl_set(VV[63],CONS(T0,ecl_symbol_value(VV[63])));
L135:;
   if (Null(v20inclusive_iteration)) { goto L141; }
   v14testfn = ECL_SYM(">",75);
   goto L140;
L141:;
   v14testfn = ECL_SYM(">=",76);
L140:;
L131:;
   if (!((v16stepby)==(ecl_make_fixnum(1)))) { goto L144; }
   v18step = cl_list(2, ECL_SYM("1+",70), v1indexv);
   goto L143;
L144:;
   v18step = cl_list(3, ECL_SYM("+",14), v1indexv, v16stepby);
L143:;
   goto L122;
L123:;
   if ((v21start_given)!=ECL_NIL) { goto L146; }
   if ((v9default_top)!=ECL_NIL) { goto L148; }
   L41loop_error(1, _ecl_static_74);
L148:;
   T0 = cl_list(2, ECL_SYM("1-",71), v9default_top);
   T1 = cl_list(3, ECL_SYM("SETQ",751), v1indexv, T0);
   cl_set(VV[63],CONS(T1,ecl_symbol_value(VV[63])));
L146:;
   if (Null(v9default_top)) { goto L151; }
   if ((v12endform)!=ECL_NIL) { goto L151; }
   v12endform = L59loop_typed_init(v2indexv_type);
   v20inclusive_iteration = ECL_T;
L151:;
   if (Null(v12endform)) { goto L157; }
   if (Null(v20inclusive_iteration)) { goto L160; }
   v14testfn = ECL_SYM("<",72);
   goto L159;
L160:;
   v14testfn = ECL_SYM("<=",73);
L159:;
L157:;
   if (!((v16stepby)==(ecl_make_fixnum(1)))) { goto L163; }
   v18step = cl_list(2, ECL_SYM("1-",71), v1indexv);
   goto L162;
L163:;
   v18step = cl_list(3, ECL_SYM("-",17), v1indexv, v16stepby);
L162:;
L122:;
   v18step = cl_list(2, VV[1], v18step);
   if (Null(v14testfn)) { goto L167; }
   T0 = cl_list(3, v14testfn, v1indexv, v12endform);
   v15test = L5hide_variable_reference(ECL_T, v1indexv, T0);
L167:;
   if (Null(v8step_hack)) { goto L170; }
   T0 = L5hide_variable_reference(v3indexv_user_specified_p, v1indexv, v8step_hack);
   v8step_hack = cl_list(2, v4variable, T0);
L170:;
   {
    cl_object v27first_test;
    cl_object v28remaining_tests;
    v27first_test = v15test;
    v28remaining_tests = v15test;
    if (Null(v17stepby_constantp)) { goto L175; }
    if (Null(v23start_constantp)) { goto L175; }
    if (Null(v25limit_constantp)) { goto L175; }
    {
     cl_object v29new_type;
     {
      cl_object v30;
      T0 = ecl_plus(v22start_value,v16stepby);
      v30 = ecl_plus(T0,v26limit_value);
      if (!(ECL_FIXNUMP(v30)||ECL_BIGNUMP(v30))) { goto L182; }
      if (!(ECL_FIXNUMP(v22start_value))) { goto L184; }
      if (!(ECL_FIXNUMP(v26limit_value))) { goto L184; }
      v29new_type = ECL_SYM("FIXNUM",372);
      goto L180;
L184:;
      v29new_type = v2indexv_type;
      goto L180;
L182:;
      if (!(ECL_SINGLE_FLOAT_P(v30))) { goto L187; }
      v29new_type = ECL_SYM("SINGLE-FLOAT",778);
      goto L180;
L187:;
      if (!(ECL_DOUBLE_FLOAT_P(v30))) { goto L189; }
      v29new_type = ECL_SYM("DOUBLE-FLOAT",315);
      goto L180;
L189:;
      if (!(ECL_LONG_FLOAT_P(v30))) { goto L191; }
      v29new_type = ECL_SYM("LONG-FLOAT",508);
      goto L180;
L191:;
      if (!(ECL_SINGLE_FLOAT_P(v30))) { goto L193; }
      v29new_type = ECL_SYM("SHORT-FLOAT",756);
      goto L180;
L193:;
      v29new_type = v2indexv_type;
     }
L180:;
     if ((cl_subtypep(2, v2indexv_type, v29new_type))!=ECL_NIL) { goto L179; }
     L67loop_declare_variable(v1indexv, v29new_type);
    }
L179:;
    T0 = cl_symbol_function(v14testfn);
    v27first_test = ecl_function_dispatch(cl_env_copy,T0)(2, v22start_value, v26limit_value);
    if (Null(v27first_test)) { goto L175; }
    v28remaining_tests = ECL_T;
L175:;
    T0 = L5hide_variable_reference(ECL_T, v1indexv, v18step);
    T1 = cl_list(2, v1indexv, T0);
    value0 = cl_list(8, ECL_NIL, T1, v28remaining_tests, v8step_hack, ECL_NIL, ECL_NIL, v27first_test, v8step_hack);
    return value0;
   }
  }
 }
}
/*	function definition for LOOP-FOR-ARITHMETIC                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L102loop_for_arithmetic(cl_object v1var, cl_object v2val, cl_object v3data_type, cl_object v4kwd)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((v1var)!=ECL_NIL) { goto L1; }
  v1var = cl_gensym(0);
L1:;
  T0 = L43loop_check_data_type(2, v3data_type, ecl_symbol_value(VV[3]));
  T1 = cl_list(2, v4kwd, v2val);
  T2 = ecl_list1(T1);
  T3 = L100loop_collect_prepositional_phrases(3, VV[181], ECL_NIL, T2);
  value0 = L101loop_sequencer(v1var, T0, ECL_T, ECL_NIL, ECL_NIL, ECL_NIL, ECL_NIL, ECL_NIL, ECL_NIL, T3);
  return value0;
 }
}
/*	function definition for LOOP-HASH-TABLE-ITERATION-PATH        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L103loop_hash_table_iteration_path(cl_narg narg, cl_object v1variable, cl_object v2data_type, cl_object v3prep_phrases, ...)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 {
  cl_object v4which;
  ecl_va_list args; ecl_va_start(args,v3prep_phrases,narg,3);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L103loop_hash_table_iteration_pathkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v4which = keyvars[0];
  }
  {
   cl_object v5;
   v5 = v4which;
   if (!((v5)==(VV[183]))) { goto L7; }
   goto L3;
   goto L5;
L7:;
   goto L5;
L5:;
   if (!((v5)==(VV[185]))) { goto L10; }
   goto L3;
   goto L4;
L10:;
   goto L4;
L4:;
   v4which = si_do_check_type(v5, VV[187], ECL_NIL, VV[188]);
L3:;
  }
  if ((ecl_cdr(v3prep_phrases))!=ECL_NIL) { goto L16; }
  {
   cl_object v5;
   v5 = ecl_caar(v3prep_phrases);
   if (!(ecl_eql(v5,VV[157]))) { goto L21; }
   goto L14;
   goto L19;
L21:;
   goto L19;
L19:;
   if (!(ecl_eql(v5,VV[163]))) { goto L24; }
   goto L14;
   goto L15;
L24:;
   goto L15;
  }
L16:;
L15:;
  L41loop_error(1, _ecl_static_75);
  goto L13;
L14:;
  if (!(v3prep_phrases==ECL_NIL)) { goto L13; }
  L41loop_error(1, _ecl_static_76);
L13:;
  {
   cl_object v5;
   cl_object v6;
   cl_object v7dummy_predicate_var;
   cl_object v8post_steps;
   v5 = cl_gensym(1, _ecl_static_77);
   v6 = cl_gensym(1, _ecl_static_78);
   v7dummy_predicate_var = ECL_NIL;
   v8post_steps = ECL_NIL;
   {
    cl_object v10;                                /*  OTHER-VAR       */
    cl_object v11;                                /*  OTHER-P         */
    if (!((v4which)==(VV[183]))) { goto L33; }
    T0 = VV[185];
    goto L32;
L33:;
    T0 = VV[183];
L32:;
    value0 = L98named_variable(T0);
    v10 = value0;
    {
     const int v12 = cl_env_copy->nvalues;
     cl_object v13;
     v13 = (v12<=1)? ECL_NIL : cl_env_copy->values[1];
     v11 = v13;
    }
    v11 = ECL_T;
    v7dummy_predicate_var = L89loop_when_it_variable();
    {
     cl_object v12key_var;
     cl_object v13val_var;
     cl_object v14temp_val_var;
     cl_object v15temp_key_var;
     cl_object v16temp_predicate_var;
     cl_object v17variable;
     cl_object v18bindings;
     v12key_var = ECL_NIL;
     v13val_var = ECL_NIL;
     v14temp_val_var = cl_gensym(1, _ecl_static_79);
     v15temp_key_var = cl_gensym(1, _ecl_static_80);
     v16temp_predicate_var = cl_gensym(1, _ecl_static_81);
     value0 = v1variable;
     if ((value0)!=ECL_NIL) { goto L46; }
     v17variable = cl_gensym(0);
     goto L44;
L46:;
     v17variable = value0;
     goto L44;
L44:;
     T0 = cl_list(3, v17variable, ECL_NIL, v2data_type);
     T1 = ecl_cadar(v3prep_phrases);
     T2 = cl_list(2, v5, T1);
     if (Null(v11)) { goto L51; }
     if (Null(v10)) { goto L51; }
     T4 = cl_list(2, v10, ECL_NIL);
     T3 = ecl_list1(T4);
     goto L49;
L51:;
     T3 = ECL_NIL;
     goto L49;
L49:;
     v18bindings = cl_listX(3, T0, T2, T3);
     if (!((v4which)==(VV[183]))) { goto L55; }
     v12key_var = v17variable;
     if (Null(v11)) { goto L61; }
     v13val_var = v10;
     goto L59;
L61:;
     v13val_var = ECL_NIL;
     goto L59;
L59:;
     goto L54;
L55:;
     if (Null(v11)) { goto L66; }
     v12key_var = v10;
     goto L64;
L66:;
     v12key_var = ECL_NIL;
     goto L64;
L64:;
     v13val_var = v17variable;
L54:;
     T0 = cl_list(2, v6, v5);
     T1 = cl_list(2, ECL_SYM("WITH-HASH-TABLE-ITERATOR",909), T0);
     cl_set(VV[59],CONS(T1,ecl_symbol_value(VV[59])));
     if (!(ECL_CONSP(v12key_var))) { goto L71; }
     T0 = v12key_var;
     v12key_var = cl_gensym(1, _ecl_static_80);
     v8post_steps = cl_listX(3, T0, v12key_var, v8post_steps);
     T0 = cl_list(2, v12key_var, ECL_NIL);
     v18bindings = CONS(T0,v18bindings);
L71:;
     if (!(ECL_CONSP(v13val_var))) { goto L77; }
     T0 = v13val_var;
     v13val_var = cl_gensym(1, _ecl_static_79);
     v8post_steps = cl_listX(3, T0, v13val_var, v8post_steps);
     T0 = cl_list(2, v13val_var, ECL_NIL);
     v18bindings = CONS(T0,v18bindings);
L77:;
     T0 = cl_list(3, v16temp_predicate_var, v15temp_key_var, v14temp_val_var);
     T1 = ecl_list1(v6);
     T2 = cl_list(3, ECL_SYM("SETQ",751), v13val_var, v14temp_val_var);
     T3 = cl_list(3, ECL_SYM("SETQ",751), v12key_var, v15temp_key_var);
     T4 = cl_list(4, ECL_SYM("WHEN",905), v16temp_predicate_var, T2, T3);
     T5 = cl_list(3, ECL_SYM("SETQ",751), v7dummy_predicate_var, v16temp_predicate_var);
     T6 = cl_list(5, ECL_SYM("MULTIPLE-VALUE-BIND",572), T0, T1, T4, T5);
     T7 = cl_list(2, ECL_SYM("NOT",584), T6);
     value0 = cl_list(6, v18bindings, ECL_NIL, ECL_NIL, ECL_NIL, T7, v8post_steps);
     return value0;
    }
   }
  }
 }
}
/*	function definition for LOOP-PACKAGE-SYMBOLS-ITERATION-PATH   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L104loop_package_symbols_iteration_path(cl_narg narg, cl_object v1variable, cl_object v2data_type, cl_object v3prep_phrases, ...)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 {
  cl_object v4symbol_types;
  ecl_va_list args; ecl_va_start(args,v3prep_phrases,narg,3);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L104loop_package_symbols_iteration_pathkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v4symbol_types = keyvars[0];
  }
  if (Null(v3prep_phrases)) { goto L2; }
  if (Null(ecl_cdr(v3prep_phrases))) { goto L2; }
  L41loop_error(1, _ecl_static_75);
  goto L1;
L2:;
  if (Null(v3prep_phrases)) { goto L1; }
  {
   cl_object v5;
   v5 = ecl_caar(v3prep_phrases);
   if (!(ecl_eql(v5,VV[157]))) { goto L10; }
   goto L1;
   goto L8;
L10:;
   goto L8;
L8:;
   if (!(ecl_eql(v5,VV[163]))) { goto L13; }
   goto L1;
   goto L5;
L13:;
   goto L5;
  }
L5:;
  T0 = ecl_caar(v3prep_phrases);
  L41loop_error(2, _ecl_static_82, T0);
L1:;
  if (ECL_SYMBOLP(v1variable)) { goto L15; }
  L41loop_error(1, _ecl_static_83);
L15:;
  {
   cl_object v5;
   cl_object v6;
   cl_object v7;
   cl_object v8;
   v5 = cl_gensym(1, _ecl_static_84);
   v6 = cl_gensym(1, _ecl_static_85);
   value0 = v1variable;
   if ((value0)!=ECL_NIL) { goto L21; }
   v7 = cl_gensym(0);
   goto L19;
L21:;
   v7 = value0;
   goto L19;
L19:;
   value0 = ecl_cadar(v3prep_phrases);
   if ((value0)!=ECL_NIL) { goto L25; }
   v8 = ECL_SYM("*PACKAGE*",43);
   goto L23;
L25:;
   v8 = value0;
   goto L23;
L23:;
   T0 = cl_listX(3, v6, v5, v4symbol_types);
   T1 = cl_list(2, ECL_SYM("WITH-PACKAGE-ITERATOR",914), T0);
   cl_set(VV[59],CONS(T1,ecl_symbol_value(VV[59])));
   T0 = cl_list(3, v7, ECL_NIL, v2data_type);
   T1 = cl_list(2, v5, v8);
   T2 = cl_list(2, T0, T1);
   T3 = L89loop_when_it_variable();
   T4 = cl_list(2, T3, v7);
   T5 = ecl_list1(v6);
   T6 = cl_list(3, ECL_SYM("MULTIPLE-VALUE-SETQ",576), T4, T5);
   T7 = cl_list(2, ECL_SYM("NOT",584), T6);
   value0 = cl_list(6, T2, ECL_NIL, ECL_NIL, ECL_NIL, T7, ECL_NIL);
   return value0;
  }
 }
}
/*	function definition for MAKE-ANSI-LOOP-UNIVERSE               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L105make_ansi_loop_universe(cl_object v1extended_p)
{
 cl_object T0, T1, T2, T3, T4, T5;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2w;
   T0 = cl_list(4, VV[127], ECL_SYM("COUNT",266), ecl_symbol_value(VV[3]), ECL_SYM("FIXNUM",372));
   T1 = cl_list(2, ECL_SYM("COUNT",266), T0);
   T2 = cl_list(4, VV[127], ECL_SYM("COUNT",266), ecl_symbol_value(VV[3]), ECL_SYM("FIXNUM",372));
   T3 = cl_list(2, VV[205], T2);
   T4 = cl_listX(15, VV[193], VV[194], VV[195], VV[196], VV[197], VV[198], VV[199], VV[200], VV[201], VV[202], VV[203], VV[204], T1, T3, VV[206]);
   if (Null(v1extended_p)) { goto L3; }
   T5 = VV[34];
   goto L2;
L3:;
   T5 = ECL_T;
L2:;
   v2w = L22make_standard_loop_universe(12, VV[38], T4, VV[39], VV[207], VV[40], VV[208], VV[45], VV[209], VV[44], ECL_NIL, VV[42], T5);
   L96add_loop_path(9, VV[210], VV[191], v2w, VV[153], VV[211], VV[154], ECL_NIL, VV[152], VV[212]);
   L96add_loop_path(9, VV[213], VV[191], v2w, VV[153], VV[211], VV[154], ECL_NIL, VV[152], VV[214]);
   L96add_loop_path(9, VV[215], VV[192], v2w, VV[153], VV[211], VV[154], ECL_NIL, VV[152], VV[216]);
   L96add_loop_path(9, VV[217], VV[192], v2w, VV[153], VV[211], VV[154], ECL_NIL, VV[152], VV[218]);
   L96add_loop_path(9, VV[219], VV[192], v2w, VV[153], VV[211], VV[154], ECL_NIL, VV[152], VV[220]);
   value0 = v2w;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for LOOP-STANDARD-EXPANSION               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L106loop_standard_expansion(cl_object v1keywords_and_forms, cl_object v2environment, cl_object v3universe)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1keywords_and_forms)) { goto L1; }
  T0 = ecl_car(v1keywords_and_forms);
  if (!(ECL_SYMBOLP(T0))) { goto L1; }
  value0 = L47loop_translate(v1keywords_and_forms, v2environment, v3universe);
  return value0;
L1:;
  {
   cl_object v4tag;
   v4tag = cl_gensym(0);
   T0 = CONS(ECL_SYM("PROGN",671),v1keywords_and_forms);
   T1 = cl_list(2, ECL_SYM("GO",414), v4tag);
   T2 = cl_list(4, ECL_SYM("TAGBODY",850), v4tag, T0, T1);
   value0 = cl_list(3, ECL_SYM("BLOCK",137), ECL_NIL, T2);
   return value0;
  }
 }
}
/*	local function LOOP                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC107loop(cl_object v1, cl_object v2env)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_cdr(v1);
   value0 = L106loop_standard_expansion(v3, v2env, ecl_symbol_value(VV[221]));
   return value0;
  }
 }
}

#include "lsp/loop2.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecl4Y7b9al0l0sl9_IgN5hE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:LSP;LOOP2.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_ecl4Y7b9al0l0sl9_IgN5hE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defmacro(VV[223]);                       /*  LOOP-UNSAFE     */
 ecl_cmp_defmacro(VV[224]);                       /*  LOOP-COPYLIST*  */
 si_Xmake_special(VV[3]);
 cl_set(VV[3],ECL_SYM("REAL",703));
 (void)0; /* No entry created for LOOP-OPTIMIZATION-QUANTITIES */
 (void)0; /* No entry created for HIDE-VARIABLE-REFERENCES */
 (void)0; /* No entry created for HIDE-VARIABLE-REFERENCE */
 ecl_cmp_defmacro(VV[225]);                       /*  WITH-LOOP-LIST-COLLECTION-HEAD */
 ecl_cmp_defmacro(VV[226]);                       /*  LOOP-COLLECT-RPLACD */
 ecl_cmp_defmacro(VV[227]);                       /*  LOOP-COLLECT-ANSWER */
 si_define_structure(15, VV[13], _ecl_static_1, ECL_SYM("VECTOR",898), ECL_NIL, VVtemp[0], VVtemp[1], VV[14], ECL_NIL, ECL_NIL, ECL_NIL, VVtemp[2], ecl_make_fixnum(6), ECL_NIL, ECL_NIL, ECL_NIL);
 ecl_cmp_defun(VV[228]);                          /*  MAKE-LOOP-MINIMAX-INTERNAL */
 si_Xmake_special(VV[17]);
 cl_set(VV[17],VVtemp[3]);
 (void)0; /* No entry created for MAKE-LOOP-MINIMAX */
 (void)0; /* No entry created for LOOP-NOTE-MINIMAX-OPERATION */
 ecl_cmp_defmacro(VV[237]);                       /*  WITH-MINIMAX-VALUE */
 ecl_cmp_defmacro(VV[242]);                       /*  LOOP-ACCUMULATE-MINIMAX-VALUE */
 (void)0; /* No entry created for LOOP-TEQUAL */
 (void)0; /* No entry created for LOOP-TASSOC */
 (void)0; /* No entry created for LOOP-TMEMBER */
 (void)0; /* No entry created for LOOP-LOOKUP-KEYWORD */
 ecl_cmp_defmacro(VV[243]);                       /*  LOOP-STORE-TABLE-DATA */
 si_define_structure(15, VV[27], _ecl_static_4, ECL_SYM("VECTOR",898), ECL_NIL, VVtemp[4], VVtemp[5], VV[28], ECL_NIL, ECL_NIL, ECL_NIL, VVtemp[6], ecl_make_fixnum(8), ECL_NIL, ECL_NIL, ECL_NIL);
 ecl_cmp_defun(VV[244]);                          /*  MAKE-LOOP-UNIVERSE */
 si_Xmake_special(VV[31]);
 (void)0; /* No entry created for MAKE-STANDARD-LOOP-UNIVERSE */
 si_Xmake_special(VV[46]);
 cl_set(VV[46],ECL_NIL);
 (void)0; /* No entry created for LOOP-MAKE-PSETQ */
 (void)0; /* No entry created for LOOP-MAKE-DESETQ */
 si_Xmake_special(VV[48]);
 cl_set(VV[48],cl_make_symbol(_ecl_static_5));
 ecl_cmp_defmacro(VV[260]);                       /*  LOOP-REALLY-DESETQ */
 si_Xmake_special(VV[50]);
 si_Xmake_special(VV[51]);
 si_Xmake_special(VV[52]);
 si_Xmake_special(VV[53]);
 si_Xmake_special(VV[54]);
 si_Xmake_special(VV[55]);
 si_Xmake_special(VV[56]);
 si_Xmake_special(VV[57]);
 si_Xmake_special(VV[58]);
 si_Xmake_special(VV[59]);
 si_Xmake_special(VV[60]);
 si_Xmake_special(VV[61]);
 si_Xmake_special(VV[62]);
 si_Xmake_special(VV[63]);
 si_Xmake_special(VV[64]);
 si_Xmake_special(VV[65]);
 si_Xmake_special(VV[66]);
 si_Xmake_special(VV[67]);
 si_Xmake_special(VV[68]);
 si_Xmake_special(VV[69]);
 si_Xmake_special(VV[70]);
 si_Xmake_special(VV[71]);
 si_Xmake_special(VV[72]);
 si_Xmake_special(VV[73]);
 si_Xmake_special(VV[74]);
 (void)0; /* No entry created for LOOP-CONSTANT-FOLD-IF-POSSIBLE */
 ecl_cmp_defun(VV[261]);                          /*  LOOP-CONSTANTP  */
 si_Xmake_special(VV[76]);
 cl_set(VV[76],ECL_NIL);
 si_Xmake_special(VV[77]);
 cl_set(VV[77],cl_make_symbol(_ecl_static_7));
 (void)0; /* No entry created for LOOP-CODE-DUPLICATION-THRESHOLD */
 ecl_cmp_defmacro(VV[262]);                       /*  LOOP-BODY       */
 (void)0; /* No entry created for DUPLICATABLE-CODE-P */
 si_Xmake_special(VV[85]);
 cl_set(VV[85],VVtemp[7]);
 si_Xmake_special(VV[86]);
 cl_set(VV[86],VVtemp[8]);
 (void)0; /* No entry created for DESTRUCTURING-SIZE */
 (void)0; /* No entry created for ESTIMATE-CODE-SIZE */
 (void)0; /* No entry created for ESTIMATE-CODE-SIZE-1 */
 (void)0; /* No entry created for LOOP-CONTEXT */
 (void)0; /* No entry created for LOOP-ERROR */
 (void)0; /* No entry created for LOOP-WARN */
 (void)0; /* No entry created for LOOP-CHECK-DATA-TYPE */
 ecl_cmp_defmacro(VV[263]);                       /*  LOOP-FINISH     */
 ecl_cmp_defun(VV[264]);                          /*  SUBST-GENSYMS-FOR-NIL */
 ecl_cmp_defun(VV[265]);                          /*  LOOP-BUILD-DESTRUCTURING-BINDINGS */
 (void)0; /* No entry created for LOOP-TRANSLATE */
 (void)0; /* No entry created for LOOP-ITERATION-DRIVER */
 (void)0; /* No entry created for LOOP-POP-SOURCE */
 (void)0; /* No entry created for LOOP-GET-COMPOUND-FORM */
 (void)0; /* No entry created for LOOP-GET-PROGN */
 (void)0; /* No entry created for LOOP-GET-FORM */
 (void)0; /* No entry created for LOOP-CONSTRUCT-RETURN */
 (void)0; /* No entry created for LOOP-EMIT-BODY */
 (void)0; /* No entry created for LOOP-EMIT-FINAL-VALUE */
 (void)0; /* No entry created for LOOP-DISALLOW-CONDITIONAL */
 ecl_cmp_defun(VV[268]);                          /*  LOOP-DISALLOW-ANONYMOUS-COLLECTORS */
 ecl_cmp_defun(VV[269]);                          /*  LOOP-DISALLOW-AGGREGATE-BOOLEANS */
 (void)0; /* No entry created for LOOP-TYPED-INIT */
 (void)0; /* No entry created for LOOP-OPTIONAL-TYPE */
 (void)0; /* No entry created for LOOP-BIND-BLOCK */
 ecl_cmp_defun(VV[272]);                          /*  LOOP-VARIABLE-P */
 (void)0; /* No entry created for LOOP-MAKE-VARIABLE */
 (void)0; /* No entry created for LOOP-MAKE-ITERATION-VARIABLE */
 (void)0; /* No entry created for LOOP-DECLARE-VARIABLE */
 (void)0; /* No entry created for LOOP-MAYBE-BIND-FORM */
 ecl_cmp_defun(VV[273]);                          /*  LOOP-DO-IF      */
 ecl_cmp_defun(VV[274]);                          /*  LOOP-DO-INITIALLY */
 ecl_cmp_defun(VV[275]);                          /*  LOOP-DO-FINALLY */
 ecl_cmp_defun(VV[276]);                          /*  LOOP-DO-DO      */
 ecl_cmp_defun(VV[277]);                          /*  LOOP-DO-NAMED   */
 ecl_cmp_defun(VV[278]);                          /*  LOOP-DO-RETURN  */
 si_define_structure(15, VV[117], _ecl_static_38, ECL_SYM("VECTOR",898), ECL_NIL, VVtemp[9], VVtemp[10], VV[118], ECL_NIL, ECL_NIL, ECL_NIL, VVtemp[11], ecl_make_fixnum(6), ECL_NIL, ECL_NIL, ECL_NIL);
 ecl_cmp_defun(VV[279]);                          /*  MAKE-LOOP-COLLECTOR */
 (void)0; /* No entry created for LOOP-GET-COLLECTION-INFO */
 ecl_cmp_defun(VV[290]);                          /*  LOOP-LIST-COLLECTION */
 ecl_cmp_defun(VV[292]);                          /*  LOOP-SUM-COLLECTION */
 ecl_cmp_defun(VV[293]);                          /*  LOOP-MAXMIN-COLLECTION */
 ecl_cmp_defun(VV[295]);                          /*  LOOP-DO-ALWAYS  */
 ecl_cmp_defun(VV[296]);                          /*  LOOP-DO-THEREIS */
 ecl_cmp_defun(VV[297]);                          /*  LOOP-DO-WHILE   */
 ecl_cmp_defun(VV[298]);                          /*  LOOP-DO-WITH    */
 (void)0; /* No entry created for LOOP-HACK-ITERATION */
 ecl_cmp_defun(VV[300]);                          /*  LOOP-DO-FOR     */
 ecl_cmp_defun(VV[302]);                          /*  LOOP-DO-REPEAT  */
 (void)0; /* No entry created for LOOP-WHEN-IT-VARIABLE */
 ecl_cmp_defun(VV[303]);                          /*  LOOP-ANSI-FOR-EQUALS */
 ecl_cmp_defun(VV[304]);                          /*  LOOP-FOR-ACROSS */
 (void)0; /* No entry created for LOOP-LIST-STEP */
 ecl_cmp_defun(VV[305]);                          /*  LOOP-FOR-ON     */
 ecl_cmp_defun(VV[306]);                          /*  LOOP-FOR-IN     */
 si_define_structure(15, VV[147], _ecl_static_57, ECL_SYM("VECTOR",898), ECL_NIL, VVtemp[12], VVtemp[13], VV[148], ECL_NIL, ECL_NIL, ECL_NIL, VVtemp[14], ecl_make_fixnum(5), ECL_NIL, ECL_NIL, ECL_NIL);
 ecl_cmp_defun(VV[307]);                          /*  MAKE-LOOP-PATH  */
 (void)0; /* No entry created for ADD-LOOP-PATH */
 ecl_cmp_defun(VV[317]);                          /*  LOOP-FOR-BEING  */
 (void)0; /* No entry created for NAMED-VARIABLE */
 (void)0; /* No entry created for LOOP-COLLECT-PREPOSITIONAL-PHRASES */
 (void)0; /* No entry created for LOOP-SEQUENCER */
 ecl_cmp_defun(VV[322]);                          /*  LOOP-FOR-ARITHMETIC */
 ecl_cmp_defun(VV[323]);                          /*  LOOP-HASH-TABLE-ITERATION-PATH */
 ecl_cmp_defun(VV[325]);                          /*  LOOP-PACKAGE-SYMBOLS-ITERATION-PATH */
 (void)0; /* No entry created for MAKE-ANSI-LOOP-UNIVERSE */
 si_Xmake_special(VV[221]);
 cl_set(VV[221],L105make_ansi_loop_universe(ECL_NIL));
 (void)0; /* No entry created for LOOP-STANDARD-EXPANSION */
 ecl_cmp_defmacro(VV[327]);                       /*  LOOP            */
}
