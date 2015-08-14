/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CLOS;COMBIN.LSP                                   */
#include <ecl/ecl-cmp.h>
#include "clos/combin.eclh"
/*	function definition for EFFECTIVE-METHOD-FUNCTION             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1effective_method_function(cl_narg narg, cl_object v1form, ...)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2top_level;
  va_list args; va_start(args,v1form);
  {
   int i = 1;
   if (i >= narg) {
    v2top_level = ECL_NIL;
   } else {
    i++;
    v2top_level = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v3first;
   v3first = ECL_NIL;
   if (Null(cl_functionp(v1form))) { goto L3; }
   value0 = v1form;
   cl_env_copy->nvalues = 1;
   return value0;
L3:;
   if (Null(ecl_function_dispatch(cl_env_copy,VV[47])(1, v1form) /*  METHOD-P */)) { goto L5; }
   value0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("METHOD-FUNCTION",1531))(1, v1form) /*  METHOD-FUNCTION */;
   return value0;
L5:;
   if (!(ECL_ATOM(v1form))) { goto L7; }
   value0 = cl_error(2, _ecl_static_1, v1form);
   return value0;
L7:;
   v3first = ecl_car(v1form);
   if (!((v3first)==(ECL_SYM("MAKE-METHOD",953)))) { goto L9; }
   T0 = ecl_cadr(v1form);
   T1 = cl_list(4, ECL_SYM("LAMBDA",452), VV[0], VV[1], T0);
   value0 = si_coerce_to_function(T1);
   return value0;
L9:;
   if (!((v3first)==(ECL_SYM("CALL-METHOD",930)))) { goto L12; }
   T0 = ecl_cadr(v1form);
   T1 = L1effective_method_function(1, T0);
   {
    cl_object v4;
    cl_object v5;
    cl_object v6;
    v4 = ecl_caddr(v1form);
    v5 = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
    v6 = v4;
    {
     cl_object v7;
     cl_object v8;
     v7 = ecl_list1(ECL_NIL);
     v8 = v7;
L21:;
     if (!(ecl_endp(v6))) { goto L23; }
     goto L22;
L23:;
     v5 = _ecl_car(v6);
     {
      cl_object v9;
      v9 = _ecl_cdr(v6);
      if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
      v6 = v9;
     }
     if (ecl_unlikely(ECL_ATOM(v8))) FEtype_error_cons(v8);
     T3 = v8;
     T4 = L1effective_method_function(1, v5);
     v8 = ecl_list1(T4);
     (ECL_CONS_CDR(T3)=v8,T3);
     goto L21;
L22:;
     T2 = ecl_cdr(v7);
     goto L14;
    }
   }
L14:;
   value0 = L3combine_method_functions(T1, T2);
   return value0;
L12:;
   if (Null(v2top_level)) { goto L37; }
   T0 = cl_list(4, ECL_SYM("LAMBDA",452), VV[2], VV[3], v1form);
   value0 = si_coerce_to_function(T0);
   return value0;
L37:;
   value0 = cl_error(2, _ecl_static_1, v1form);
   return value0;
  }
 }
}
/*	function definition for COMBINE-METHOD-FUNCTIONS              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3combine_method_functions(cl_object v1method, cl_object v2rest_methods)
{
 cl_object env0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1method,env0);              /*  METHOD          */
  CLV1 = env0 = CONS(v2rest_methods,env0);        /*  REST-METHODS    */
  {cl_object v3;
   v3 = ECL_NIL;
   v3 = ecl_make_cclosure_va((cl_objectfn)LC2__g7,env0,Cblock);
   value0 = v3;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	closure G7                                                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC2__g7(cl_narg narg, cl_object v1_combined_method_args_, cl_object v2no_next_methods, ...)
{
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  REST-METHODS    */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
  ecl_bds_bind(cl_env_copy,ECL_SYM(".COMBINED-METHOD-ARGS.",1473),v1_combined_method_args_); /*  .COMBINED-METHOD-ARGS. */
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,ECL_CONS_CAR(CLV0))(2, ecl_symbol_value(ECL_SYM(".COMBINED-METHOD-ARGS.",1473)), ECL_CONS_CAR(CLV1));
  ecl_bds_unwind1(cl_env_copy);
  return value0;
 }
 }
}
/*	local function CALL-METHOD                                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC4call_method(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4method;
   cl_object v5rest_methods;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4method = v6;
   }
   if (Null(v3)) { goto L9; }
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5rest_methods = v6;
    goto L8;
   }
L9:;
   v5rest_methods = ECL_NIL;
L8:;
   if (Null(v3)) { goto L14; }
   si_dm_too_many_arguments(v1);
L14:;
   T0 = L1effective_method_function(1, v4method);
   if (Null(v5rest_methods)) { goto L18; }
   {
    cl_object v6;
    cl_object v7;
    v6 = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v5rest_methods))) FEtype_error_list(v5rest_methods);
    v7 = v5rest_methods;
    {
     cl_object v8;
     cl_object v9;
     v8 = ecl_list1(ECL_NIL);
     v9 = v8;
L25:;
     if (!(ecl_endp(v7))) { goto L27; }
     goto L26;
L27:;
     v6 = _ecl_car(v7);
     {
      cl_object v10;
      v10 = _ecl_cdr(v7);
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      v7 = v10;
     }
     if (ecl_unlikely(ECL_ATOM(v9))) FEtype_error_cons(v9);
     T2 = v9;
     T3 = L1effective_method_function(1, v6);
     v9 = ecl_list1(T3);
     (ECL_CONS_CDR(T2)=v9,T2);
     goto L25;
L26:;
     T1 = ecl_cdr(v8);
     goto L16;
    }
   }
L18:;
   T1 = ECL_NIL;
   goto L16;
L16:;
   T2 = cl_list(2, ECL_SYM("QUOTE",679), T1);
   value0 = cl_list(4, ECL_SYM("FUNCALL",394), T0, ECL_SYM(".COMBINED-METHOD-ARGS.",1473), T2);
   return value0;
  }
 }
}
/*	function definition for CALL-NEXT-METHOD                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5call_next_method(cl_narg narg, ...)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1args;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1args = cl_grab_rest_args(args);
  ecl_va_end(args);
  if ((ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)))!=ECL_NIL) { goto L1; }
  cl_error(1, _ecl_static_2);
L1:;
  T0 = ecl_car(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
  value0 = v1args;
  if ((value0)!=ECL_NIL) { goto L6; }
  T1 = ecl_symbol_value(ECL_SYM(".COMBINED-METHOD-ARGS.",1473));
  goto L4;
L6:;
  T1 = value0;
  goto L4;
L4:;
  T2 = ecl_cdr(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
  value0 = ecl_function_dispatch(cl_env_copy,T0)(2, T1, T2);
  return value0;
 }
}
/*	function definition for NEXT-METHOD-P                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6next_method_p()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function CALL-NEXT-METHOD                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC7call_next_method(cl_object v1, cl_object v2)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_cdr(v1);
   if (Null(v3)) { goto L3; }
   T0 = CONS(ECL_SYM("LIST",481),v3);
   goto L2;
L3:;
   T0 = ECL_SYM(".COMBINED-METHOD-ARGS.",1473);
L2:;
   T1 = cl_list(4, ECL_SYM("FUNCALL",394), VV[8], T0, VV[9]);
   value0 = cl_list(4, ECL_SYM("IF",946), ECL_SYM("*NEXT-METHODS*",1475), T1, VV[10]);
   return value0;
  }
 }
}
/*	local function NEXT-METHOD-P                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC8next_method_p(cl_object v1, cl_object v2)
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
   value0 = ECL_SYM("*NEXT-METHODS*",1475);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for ERROR-QUALIFIER                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L9error_qualifier(cl_object v1m, cl_object v2qualifier)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_error(3, _ecl_static_3, v1m, v2qualifier);
  return value0;
 }
}
/*	function definition for STANDARD-MAIN-EFFECTIVE-METHOD        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L11standard_main_effective_method(cl_object v1before, cl_object v2primary, cl_object v3after)
{
 cl_object env0;
 cl_object CLV0, CLV1, CLV2
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1before,env0);              /*  BEFORE          */
  CLV1 = env0 = CONS(v2primary,env0);             /*  PRIMARY         */
  CLV2 = env0 = CONS(v3after,env0);               /*  AFTER           */
  {cl_object v4;
   v4 = ECL_NIL;
   v4 = ecl_make_cclosure_va((cl_objectfn)LC10__g28,env0,Cblock);
   value0 = v4;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	closure G28                                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC10__g28(cl_narg narg, cl_object v1_combined_method_args_, cl_object v2no_next_method, ...)
{
 cl_object T0, T1;
 cl_object CLV0, CLV1, CLV2
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV2 = env0;                                     /*  AFTER           */
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
  ecl_bds_bind(cl_env_copy,ECL_SYM(".COMBINED-METHOD-ARGS.",1473),v1_combined_method_args_); /*  .COMBINED-METHOD-ARGS. */
TTL:
  {
   cl_object v3;
   v3 = ECL_CONS_CAR(CLV0);
   goto L5;
L4:;
   {
    cl_object v4i;
    v4i = ecl_car(v3);
    ecl_function_dispatch(cl_env_copy,v4i)(2, ecl_symbol_value(ECL_SYM(".COMBINED-METHOD-ARGS.",1473)), ECL_NIL);
   }
   v3 = ecl_cdr(v3);
L5:;
   if (Null(v3)) { goto L12; }
   goto L4;
L12:;
  }
  if (Null(ECL_CONS_CAR(CLV2))) { goto L14; }
  {
   struct ecl_stack_frame _ecl_inner_frame_aux;
   cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
   {
    cl_object v3;
    v3 = _ecl_inner_frame;
    T0 = ecl_car(ECL_CONS_CAR(CLV1));
    T1 = ecl_cdr(ECL_CONS_CAR(CLV1));
    cl_env_copy->values[0] = ecl_function_dispatch(cl_env_copy,T0)(2, ecl_symbol_value(ECL_SYM(".COMBINED-METHOD-ARGS.",1473)), T1);
    ecl_stack_frame_push_values(v3);
    {
     cl_object v4;
     v4 = ECL_CONS_CAR(CLV2);
     goto L25;
L24:;
     {
      cl_object v5i;
      v5i = ecl_car(v4);
      ecl_function_dispatch(cl_env_copy,v5i)(2, ecl_symbol_value(ECL_SYM(".COMBINED-METHOD-ARGS.",1473)), ECL_NIL);
     }
     v4 = ecl_cdr(v4);
L25:;
     if (Null(v4)) { goto L32; }
     goto L24;
L32:;
    }cl_env_copy->values[0]=ecl_stack_frame_pop_values(v3);
    value0 = cl_env_copy->values[0];
   }
   ecl_stack_frame_close(_ecl_inner_frame);
  }
  ecl_bds_unwind1(cl_env_copy);
  return value0;
L14:;
  T0 = ecl_car(ECL_CONS_CAR(CLV1));
  T1 = ecl_cdr(ECL_CONS_CAR(CLV1));
  value0 = ecl_function_dispatch(cl_env_copy,T0)(2, ecl_symbol_value(ECL_SYM(".COMBINED-METHOD-ARGS.",1473)), T1);
  ecl_bds_unwind1(cl_env_copy);
  return value0;
 }
 }
}
/*	function definition for STANDARD-COMPUTE-EFFECTIVE-METHOD     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L13standard_compute_effective_method(cl_object v1gf, cl_object v2methods)
{
 cl_object T0, T1, T2;
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1gf,env0);                  /*  GF              */
  {
   cl_object v3before;
   cl_object v4primary;
   cl_object v5after;
   cl_object v6around;
   v3before = ECL_NIL;
   v4primary = ECL_NIL;
   v5after = ECL_NIL;
   v6around = ECL_NIL;
   {
    cl_object v7;
    v7 = v2methods;
    goto L9;
L8:;
    {
     cl_object v8m;
     v8m = ecl_car(v7);
     {
      cl_object v9qualifiers;
      cl_object v10f;
      v9qualifiers = ecl_instance_ref((v8m),(3));
      v10f = ecl_instance_ref((v8m),(4));
      if (!(v9qualifiers==ECL_NIL)) { goto L16; }
      v4primary = CONS(v10f,v4primary);
      goto L13;
L16:;
      if (Null(ecl_cdr(v9qualifiers))) { goto L19; }
      L9error_qualifier(v8m, v9qualifiers);
      goto L13;
L19:;
      v9qualifiers = ecl_car(v9qualifiers);
      if (!((v9qualifiers)==(VV[11]))) { goto L21; }
      v3before = CONS(v10f,v3before);
      goto L13;
L21:;
      if (!((v9qualifiers)==(VV[12]))) { goto L25; }
      v5after = CONS(v10f,v5after);
      goto L13;
L25:;
      if (!((v9qualifiers)==(VV[13]))) { goto L28; }
      v6around = CONS(v10f,v6around);
      goto L13;
L28:;
      L9error_qualifier(v8m, v9qualifiers);
     }
L13:;
    }
    v7 = ecl_cdr(v7);
L9:;
    if (Null(v7)) { goto L33; }
    goto L8;
L33:;
   }
   if (!(v4primary==ECL_NIL)) { goto L35; }
   {cl_object v7;
    v7 = ECL_NIL;
    v7 = ecl_make_cclosure_va((cl_objectfn)LC12__g64,env0,Cblock);
    value0 = v7;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L35:;
   v4primary = cl_nreverse(v4primary);
   v3before = cl_nreverse(v3before);
   if (Null(v6around)) { goto L41; }
   {
    cl_object v7main;
    if ((v3before)!=ECL_NIL) { goto L46; }
    if (Null(v5after)) { goto L44; }
    goto L45;
L46:;
L45:;
    T0 = L11standard_main_effective_method(v3before, v4primary, v5after);
    v7main = ecl_list1(T0);
    goto L43;
L44:;
    v7main = v4primary;
L43:;
    v6around = cl_nreverse(v6around);
    T0 = ecl_car(v6around);
    T1 = ecl_cdr(v6around);
    T2 = ecl_nconc(T1,v7main);
    value0 = L3combine_method_functions(T0, T2);
    return value0;
   }
L41:;
   if ((v3before)!=ECL_NIL) { goto L52; }
   if (Null(v5after)) { goto L50; }
   goto L51;
L52:;
L51:;
   value0 = L11standard_main_effective_method(v3before, v4primary, v5after);
   return value0;
L50:;
   T0 = ecl_car(v4primary);
   T1 = ecl_cdr(v4primary);
   value0 = L3combine_method_functions(T0, T1);
   return value0;
  }
 }
}
/*	closure G64                                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC12__g64(cl_narg narg, ...)
{
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  GF              */
 { /* ... closure scanning finished */
 {
  cl_object v1args;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1args = cl_grab_rest_args(args);
  ecl_va_end(args);
  value0 = cl_apply(3, VV[14], ECL_CONS_CAR(CLV0), v1args);
  return value0;
 }
 }
}
/*	function definition for SEARCH-METHOD-COMBINATION             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L14search_method_combination(cl_object volatile v1name)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   volatile cl_object v2;
   volatile cl_object v3;
   volatile cl_object v4;
   v2 = ecl_symbol_value(VV[16]);
   v3 = mp_lock_owner(v2);
   v4 = mp_lock_count(v2);
   {
    struct ecl_stack_frame _ecl_inner_frame_aux;
    volatile cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
    {
     volatile cl_object v5;
     v5 = _ecl_inner_frame;
     {
      volatile cl_object v6;
      v6 = ecl_symbol_value(ECL_SYM("*INTERRUPTS-ENABLED*",1023));
      ecl_bds_bind(cl_env_copy,ECL_SYM("*INTERRUPTS-ENABLED*",1023),ECL_NIL); /*  *INTERRUPTS-ENABLED* */
      ecl_bds_bind(cl_env_copy,ECL_SYM("*ALLOW-WITH-INTERRUPTS*",1730),ECL_NIL); /*  *ALLOW-WITH-INTERRUPTS* */
      {
       volatile bool unwinding = FALSE;
       cl_index v7=ECL_STACK_INDEX(cl_env_copy),v8;
       ecl_frame_ptr next_fr;
       if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
         unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
       } else {
       ecl_bds_bind(cl_env_copy,ECL_SYM("*INTERRUPTS-ENABLED*",1023),v6); /*  *INTERRUPTS-ENABLED* */
       mp_get_lock(1, v2);
       value0 = ecl_gethash_safe(v1name,ecl_symbol_value(VV[17]),ECL_NIL);
       if ((value0)!=ECL_NIL) { goto L12; }
       cl_env_copy->values[0] = cl_error(2, _ecl_static_4, v1name);
       ecl_bds_unwind1(cl_env_copy);
       goto L9;
L12:;
       cl_env_copy->values[0] = value0;
       cl_env_copy->nvalues = 1;
       ecl_bds_unwind1(cl_env_copy);
       goto L9;
L9:;
       }
       ecl_frs_pop(cl_env_copy);
       v8=ecl_stack_push_values(cl_env_copy);
       T0 = ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398));
       T1 = mp_lock_owner(v2);
       if (!((T0)==(T1))) { goto L14; }
       if (!((v3)==(ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398))))) { goto L17; }
       T0 = mp_lock_count(v2);
       if (!(ecl_number_compare(T0,v4)>0)) { goto L14; }
       goto L15;
L17:;
L15:;
       mp_giveup_lock(v2);
L14:;
       ecl_stack_pop_values(cl_env_copy,v8);
       if (unwinding) ecl_unwind(cl_env_copy,next_fr);
       ECL_STACK_SET_INDEX(cl_env_copy,v7);
       ecl_bds_unwind1(cl_env_copy);
       ecl_bds_unwind1(cl_env_copy);
      }
     }
     ecl_stack_frame_push_values(v5);
     if (Null(ecl_symbol_value(ECL_SYM("*INTERRUPTS-ENABLED*",1023)))) { goto L19; }
     si_check_pending_interrupts();
L19:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v5);
     value0 = cl_env_copy->values[0];
    }
    ecl_stack_frame_close(_ecl_inner_frame);
   }
   return value0;
  }
 }
}
/*	function definition for INSTALL-METHOD-COMBINATION            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L15install_method_combination(cl_object volatile v1name, cl_object volatile v2function)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   volatile cl_object v3;
   volatile cl_object v4;
   volatile cl_object v5;
   v3 = ecl_symbol_value(VV[16]);
   v4 = mp_lock_owner(v3);
   v5 = mp_lock_count(v3);
   {
    struct ecl_stack_frame _ecl_inner_frame_aux;
    volatile cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
    {
     volatile cl_object v6;
     v6 = _ecl_inner_frame;
     {
      volatile cl_object v7;
      v7 = ecl_symbol_value(ECL_SYM("*INTERRUPTS-ENABLED*",1023));
      ecl_bds_bind(cl_env_copy,ECL_SYM("*INTERRUPTS-ENABLED*",1023),ECL_NIL); /*  *INTERRUPTS-ENABLED* */
      ecl_bds_bind(cl_env_copy,ECL_SYM("*ALLOW-WITH-INTERRUPTS*",1730),ECL_NIL); /*  *ALLOW-WITH-INTERRUPTS* */
      {
       volatile bool unwinding = FALSE;
       cl_index v8=ECL_STACK_INDEX(cl_env_copy),v9;
       ecl_frame_ptr next_fr;
       if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
         unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
       } else {
       ecl_bds_bind(cl_env_copy,ECL_SYM("*INTERRUPTS-ENABLED*",1023),v7); /*  *INTERRUPTS-ENABLED* */
       mp_get_lock(1, v3);
       cl_env_copy->values[0] = si_hash_set(v1name, ecl_symbol_value(VV[17]), v2function);
       ecl_bds_unwind1(cl_env_copy);
       }
       ecl_frs_pop(cl_env_copy);
       v9=ecl_stack_push_values(cl_env_copy);
       T0 = ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398));
       T1 = mp_lock_owner(v3);
       if (!((T0)==(T1))) { goto L12; }
       if (!((v4)==(ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398))))) { goto L15; }
       T0 = mp_lock_count(v3);
       if (!(ecl_number_compare(T0,v5)>0)) { goto L12; }
       goto L13;
L15:;
L13:;
       mp_giveup_lock(v3);
L12:;
       ecl_stack_pop_values(cl_env_copy,v9);
       if (unwinding) ecl_unwind(cl_env_copy,next_fr);
       ECL_STACK_SET_INDEX(cl_env_copy,v8);
       ecl_bds_unwind1(cl_env_copy);
       ecl_bds_unwind1(cl_env_copy);
      }
     }
     ecl_stack_frame_push_values(v6);
     if (Null(ecl_symbol_value(ECL_SYM("*INTERRUPTS-ENABLED*",1023)))) { goto L17; }
     si_check_pending_interrupts();
L17:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v6);
    }
    ecl_stack_frame_close(_ecl_inner_frame);
   }
  }
  value0 = v1name;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for MAKE-METHOD-COMBINATION               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L16make_method_combination(cl_object v1name, cl_object v2compiler, cl_object v3options)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4_class;
   cl_object v5o;
   v4_class = cl_find_class(1, ECL_SYM("METHOD-COMBINATION",956));
   v5o = si_allocate_raw_instance(ECL_NIL, v4_class, ecl_make_fixnum(3));
   si_instance_set(v5o, ecl_make_fixnum(0), v1name);
   si_instance_set(v5o, ecl_make_fixnum(1), v2compiler);
   si_instance_set(v5o, ecl_make_fixnum(2), v3options);
   if (Null(v4_class)) { goto L6; }
   si_instance_sig_set(v5o);
L6:;
   value0 = v5o;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for FIND-METHOD-COMBINATION               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L17find_method_combination(cl_object v1gf, cl_object v2method_combination_type_name, cl_object v3method_combination_options)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = L14search_method_combination(v2method_combination_type_name);
  value0 = L16make_method_combination(v2method_combination_type_name, T0, v3method_combination_options);
  return value0;
 }
}
/*	function definition for DEFINE-SIMPLE-METHOD-COMBINATION      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L18define_simple_method_combination(cl_narg narg, cl_object v1name, ...)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2documentation;
  cl_object v3identity_with_one_argument;
  cl_object v4operator;
  ecl_va_list args; ecl_va_start(args,v1name,narg,1);
  {
   cl_object keyvars[6];
   cl_parse_key(args,3,L18define_simple_method_combinationkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v2documentation = keyvars[0];
   v3identity_with_one_argument = keyvars[1];
   if (Null(keyvars[5])) {
    v4operator = v1name;
   } else {
    v4operator = keyvars[2];
   }
  }
  T0 = ecl_list1(v1name);
  T1 = cl_listX(3, VV[24], T0, VV[25]);
  T2 = cl_list(2, VV[23], T1);
  T3 = cl_list(2, ECL_SYM("QUOTE",679), v4operator);
  T4 = cl_list(3, ECL_SYM("LIST*",482), T3, VV[27]);
  T5 = cl_list(2, VV[26], T4);
  T6 = ecl_list1(T5);
  if (Null(v3identity_with_one_argument)) { goto L3; }
  T7 = VV[29];
  goto L2;
L3:;
  T7 = ECL_T;
L2:;
  T8 = cl_list(2, T7, VV[26]);
  T9 = cl_list(4, ECL_SYM("COND",247), VV[28], T8, VV[30]);
  T10 = cl_list(3, ECL_SYM("LET",477), T6, T9);
  value0 = cl_list(6, ECL_SYM("DEFINE-METHOD-COMBINATION",939), v1name, VV[22], T2, v2documentation, T10);
  return value0;
 }
}
/*	function definition for DEFINE-COMPLEX-METHOD-COMBINATION     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L20define_complex_method_combination(cl_object v1form)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15;
 volatile cl_object lex0[1];
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  lex0[0] = v1form;                               /*  FORM            */
TTL:
  {
   cl_object v2;
   cl_object v3name;
   cl_object v4lambda_list;
   cl_object v5method_groups;
   cl_object v6body;
   cl_object v7group_names;
   cl_object v8group_checks;
   cl_object v9group_after;
   cl_object v10generic_function;
   v2 = lex0[0];
   if (!(v2==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(lex0[0]);
L3:;
   {
    cl_object v11;
    v11 = ecl_car(v2);
    v2 = ecl_cdr(v2);
    v3name = v11;
   }
   if (!(v2==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(lex0[0]);
L9:;
   {
    cl_object v11;
    v11 = ecl_car(v2);
    v2 = ecl_cdr(v2);
    v4lambda_list = v11;
   }
   if (!(v2==ECL_NIL)) { goto L15; }
   si_dm_too_few_arguments(lex0[0]);
L15:;
   {
    cl_object v11;
    v11 = ecl_car(v2);
    v2 = ecl_cdr(v2);
    v5method_groups = v11;
   }
   v6body = v2;
   v7group_names = ECL_NIL;
   v8group_checks = ECL_NIL;
   v9group_after = ECL_NIL;
   v10generic_function = VV[32];
   if (ECL_SYMBOLP(v3name)) { goto L25; }
   LC19syntax_error(lex0);
L25:;
   {
    cl_object v11x;
    v11x = ecl_car(v6body);
    if (!(ECL_CONSP(v11x))) { goto L27; }
    T0 = ecl_car(v11x);
    if (!(ecl_eql(T0,VV[33]))) { goto L27; }
    cl_error(1, _ecl_static_6);
   }
L27:;
   {
    cl_object v11x;
    v11x = ecl_car(v6body);
    if (!(ECL_CONSP(v11x))) { goto L31; }
    T0 = ecl_car(v11x);
    if (!(ecl_eql(T0,VV[34]))) { goto L31; }
    v6body = ecl_cdr(v6body);
    v10generic_function = ecl_cadr(v11x);
    if (ECL_SYMBOLP(v10generic_function)) { goto L31; }
    LC19syntax_error(lex0);
   }
L31:;
   {
    cl_object v11;
    v11 = v5method_groups;
    goto L43;
L42:;
    {
     cl_object v12group;
     v12group = ecl_car(v11);
     {
      cl_object v13;
      cl_object v14group_name;
      cl_object v15predicate;
      cl_object v16;
      cl_object v17;
      cl_object v18order;
      cl_object v19;
      cl_object v20required;
      v13 = v12group;
      if (!(v13==ECL_NIL)) { goto L50; }
      si_dm_too_few_arguments(v12group);
L50:;
      {
       cl_object v21;
       v21 = ecl_car(v13);
       v13 = ecl_cdr(v13);
       v14group_name = v21;
      }
      if (!(v13==ECL_NIL)) { goto L56; }
      si_dm_too_few_arguments(v12group);
L56:;
      {
       cl_object v21;
       v21 = ecl_car(v13);
       v13 = ecl_cdr(v13);
       v15predicate = v21;
      }
      v16 = si_search_keyword(2, v13, ECL_SYM("DESCRIPTION",988));
      v17 = si_search_keyword(2, v13, ECL_SYM("ORDER",1005));
      if (!((v17)==(ECL_SYM("MISSING-KEYWORD",1929)))) { goto L64; }
      v18order = VV[35];
      goto L63;
L64:;
      v18order = v17;
L63:;
      v19 = si_search_keyword(2, v13, ECL_SYM("REQUIRED",1008));
      if (!((v19)==(ECL_SYM("MISSING-KEYWORD",1929)))) { goto L68; }
      v20required = ECL_NIL;
      goto L67;
L68:;
      v20required = v19;
L67:;
      si_check_keyword(2, v13, VV[36]);
      if (!(ECL_SYMBOLP(v14group_name))) { goto L72; }
      v7group_names = CONS(v14group_name,v7group_names);
      goto L71;
L72:;
      LC19syntax_error(lex0);
L71:;
      {
       cl_object v21condition;
       if (!((v15predicate)==(ECL_SYM("*",18)))) { goto L77; }
       v21condition = ECL_T;
       goto L76;
L77:;
       if (Null(v15predicate)) { goto L79; }
       if (!(ECL_SYMBOLP(v15predicate))) { goto L79; }
       v21condition = cl_list(2, v15predicate, VV[37]);
       goto L76;
L79:;
       {
        cl_object v22;
        if (!(ECL_LISTP(v15predicate))) { goto L84; }
        {
         cl_object v23q;
         cl_object v24p;
         v23q = cl_last(2, v15predicate, ecl_make_fixnum(0));
         T0 = cl_butlast(2, v15predicate, ecl_make_fixnum(0));
         v24p = cl_copy_list(T0);
         T0 = (ECL_SYM("SYMBOLP",847)->symbol.gfdef);
         if (Null(cl_every(2, T0, v24p))) { goto L88; }
         if (!((v23q)==(ECL_SYM("*",18)))) { goto L91; }
         T0 = cl_list(2, ECL_SYM("QUOTE",679), v24p);
         v22 = cl_list(4, ECL_SYM("EVERY",342), VV[38], T0, VV[37]);
         goto L82;
L91:;
         T0 = cl_list(2, ECL_SYM("QUOTE",679), v24p);
         v22 = cl_list(3, ECL_SYM("EQUAL",335), T0, VV[37]);
         goto L82;
L88:;
         v22 = ECL_NIL;
         goto L82;
        }
L84:;
        v22 = ECL_NIL;
        goto L82;
L82:;
        if (Null(v22)) { goto L93; }
        v21condition = v22;
        goto L76;
L93:;
        v21condition = LC19syntax_error(lex0);
       }
L76:;
       T0 = cl_list(3, ECL_SYM("PUSH",677), VV[39], v14group_name);
       T1 = cl_list(2, v21condition, T0);
       v8group_checks = CONS(T1,v8group_checks);
      }
      if (Null(v20required)) { goto L96; }
      T0 = cl_list(4, ECL_SYM("ERROR",337), _ecl_static_7, v3name, v14group_name);
      T1 = cl_list(3, ECL_SYM("UNLESS",883), v14group_name, T0);
      v9group_after = CONS(T1,v9group_after);
L96:;
      if (!(ecl_eql(v18order,VV[35]))) { goto L99; }
      T0 = cl_list(2, ECL_SYM("NREVERSE",589), v14group_name);
      T1 = cl_list(3, ECL_SYM("SETF",750), v14group_name, T0);
      v9group_after = CONS(T1,v9group_after);
      goto L47;
L99:;
      if (ecl_eql(v18order,VV[40])) { goto L47; }
      {
       cl_object v21order_var;
       v21order_var = cl_gensym(0);
       T0 = cl_list(2, v21order_var, v18order);
       T1 = ecl_list1(T0);
       v7group_names = ecl_append(v7group_names,T1);
       T0 = cl_list(3, ECL_SYM("EQ",333), v21order_var, VV[35]);
       T1 = cl_list(2, ECL_SYM("NREVERSE",589), v14group_name);
       T2 = cl_list(3, ECL_SYM("SETF",750), v14group_name, T1);
       T3 = cl_list(3, ECL_SYM("WHEN",905), T0, T2);
       v9group_after = CONS(T3,v9group_after);
      }
     }
L47:;
    }
    v11 = ecl_cdr(v11);
L43:;
    if (Null(v11)) { goto L109; }
    goto L42;
L109:;
   }
   T0 = cl_list(2, ECL_SYM("QUOTE",679), v3name);
   T1 = cl_listX(3, v10generic_function, VV[41], v4lambda_list);
   T2 = cl_nreverse(v8group_checks);
   T3 = cl_list(5, ECL_SYM("INVALID-METHOD-ERROR",948), VV[39], _ecl_static_8, VV[37], v3name);
   T4 = cl_list(2, ECL_T, T3);
   T5 = ecl_list1(T4);
   T6 = ecl_append(T2,T5);
   T7 = CONS(ECL_SYM("COND",247),T6);
   T8 = cl_list(3, ECL_SYM("LET",477), VV[43], T7);
   T9 = cl_list(3, ECL_SYM("DOLIST",313), VV[42], T8);
   T10 = CONS(ECL_SYM("PROGN",671),v6body);
   T11 = cl_list(3, VV[4], T10, ECL_T);
   T12 = ecl_list1(T11);
   T13 = ecl_append(v9group_after,T12);
   T14 = cl_listX(4, ECL_SYM("LET",477), v7group_names, T9, T13);
   T15 = cl_list(4, ECL_SYM("LAMBDA-BLOCK",1339), v3name, T1, T14);
   value0 = cl_list(3, VV[19], T0, T15);
   return value0;
  }
 }
}
/*	local function SYNTAX-ERROR                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC19syntax_error(volatile cl_object *lex0)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_error(2, _ecl_static_5, lex0[0]);
  return value0;
 }
}
/*	local function DEFINE-METHOD-COMBINATION                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC21define_method_combination(cl_object v1, cl_object v2)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4name;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4name = v5;
   }
   if (Null(v3)) { goto L8; }
   T0 = ecl_car(v3);
   if (!(ECL_LISTP(T0))) { goto L8; }
   T0 = CONS(v4name,v3);
   value0 = L20define_complex_method_combination(T0);
   return value0;
L8:;
   T0 = (VV[31]->symbol.gfdef);
   value0 = cl_apply(3, T0, v4name, v3);
   return value0;
  }
 }
}
/*	function definition for METHOD-COMBINATION-ERROR              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_method_combination_error(cl_narg narg, cl_object v1format_control, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2args;
  ecl_va_list args; ecl_va_start(args,v1format_control,narg,1);
  v2args = cl_grab_rest_args(args);
  ecl_va_end(args);
  T0 = (ECL_SYM("FORMAT",387)->symbol.gfdef);
  T1 = cl_apply(4, T0, ECL_NIL, v1format_control, v2args);
  value0 = cl_error(2, _ecl_static_9, T1);
  return value0;
 }
}
/*	function definition for INVALID-METHOD-ERROR                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_invalid_method_error(cl_narg narg, cl_object v1method, cl_object v2format_control, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3args;
  ecl_va_list args; ecl_va_start(args,v2format_control,narg,2);
  v3args = cl_grab_rest_args(args);
  ecl_va_end(args);
  T0 = (ECL_SYM("FORMAT",387)->symbol.gfdef);
  T1 = cl_apply(4, T0, ECL_NIL, v2format_control, v3args);
  value0 = cl_error(3, _ecl_static_10, v1method, T1);
  return value0;
 }
}
/*	function definition for STD-COMPUTE-EFFECTIVE-METHOD          */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
cl_object clos_std_compute_effective_method(cl_object v1gf, cl_object v2method_combination, cl_object v3applicable_methods)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v4compiler;
  cl_object v5options;
  v4compiler = (v2method_combination)->instance.slots[1];
  v5options = (v2method_combination)->instance.slots[2];
  if (Null(v5options)) { goto L3; }
  value0 = cl_apply(4, v4compiler, v1gf, v3applicable_methods, v5options);
  return value0;
L3:;
  value0 = ecl_function_dispatch(cl_env_copy,v4compiler)(2, v1gf, v3applicable_methods);
  return value0;
 }
}
/*	function definition for COMPUTE-EFFECTIVE-METHOD-FUNCTION     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object clos_compute_effective_method_function(cl_object v1gf, cl_object v2method_combination, cl_object v3applicable_methods)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4form;
   v4form = ecl_function_dispatch(cl_env_copy,VV[45])(3, v1gf, v2method_combination, v3applicable_methods) /*  COMPUTE-EFFECTIVE-METHOD */;
   {
    cl_object v5aux;
    cl_object v6f;
    v5aux = v4form;
    v6f = ECL_NIL;
    if (!(ECL_LISTP(v5aux))) { goto L4; }
    {
     cl_object v7;
     v7 = v5aux;
     if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
     if (Null(v7)) { goto L12; }
     {
      cl_object v8;
      v8 = ECL_CONS_CDR(v7);
      v5aux = v8;
      v7 = ECL_CONS_CAR(v7);
     }
L12:;
     T0 = v7;
    }
    if (!((T0)==(ECL_SYM("FUNCALL",394)))) { goto L4; }
    {
     cl_object v7;
     v7 = v5aux;
     if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
     if (Null(v7)) { goto L23; }
     {
      cl_object v8;
      v8 = ECL_CONS_CDR(v7);
      v5aux = v8;
      v7 = ECL_CONS_CAR(v7);
     }
L23:;
     v6f = v7;
    }
    if (Null(cl_functionp(v6f))) { goto L4; }
    {
     cl_object v7;
     v7 = v5aux;
     if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
     if (Null(v7)) { goto L34; }
     {
      cl_object v8;
      v8 = ECL_CONS_CDR(v7);
      v5aux = v8;
      v7 = ECL_CONS_CAR(v7);
     }
L34:;
     T0 = v7;
    }
    if (!((T0)==(ECL_SYM(".COMBINED-METHOD-ARGS.",1473)))) { goto L4; }
    {
     cl_object v7;
     v7 = v5aux;
     if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
     if (Null(v7)) { goto L44; }
     {
      cl_object v8;
      v8 = ECL_CONS_CDR(v7);
      v5aux = v8;
      v7 = ECL_CONS_CAR(v7);
     }
L44:;
     T0 = v7;
    }
    if (!((T0)==(ECL_SYM("*NEXT-METHODS*",1475)))) { goto L4; }
    value0 = v6f;
    cl_env_copy->nvalues = 1;
    return value0;
L4:;
    value0 = L1effective_method_function(2, v4form, ECL_T);
    return value0;
   }
  }
 }
}
/*	function definition for COMPUTE-EFFECTIVE-METHOD              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L22compute_effective_method(cl_object v1gf, cl_object v2method_combination, cl_object v3applicable_methods)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = clos_std_compute_effective_method(v1gf, v2method_combination, v3applicable_methods);
  value0 = cl_listX(3, ECL_SYM("FUNCALL",394), T0, VV[0]);
  return value0;
 }
}

#include "clos/combin.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclMEGaLwT1kakr9_Joy9ZE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CLOS;COMBIN.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclMEGaLwT1kakr9_Joy9ZE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[46]);                           /*  EFFECTIVE-METHOD-FUNCTION */
 (void)0; /* No entry created for COMBINE-METHOD-FUNCTIONS */
 ecl_cmp_defmacro(VV[48]);                        /*  CALL-METHOD     */
 ecl_cmp_defun(VV[49]);                           /*  CALL-NEXT-METHOD */
 ecl_cmp_defun(VV[50]);                           /*  NEXT-METHOD-P   */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC7call_next_method,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(VV[6], ECL_SYM("COMPILER-MACRO",238), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC8next_method_p,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(VV[7], ECL_SYM("COMPILER-MACRO",238), T0);
 }
 (void)0; /* No entry created for ERROR-QUALIFIER */
 (void)0; /* No entry created for STANDARD-MAIN-EFFECTIVE-METHOD */
 ecl_cmp_defun(VV[51]);                           /*  STANDARD-COMPUTE-EFFECTIVE-METHOD */
 si_Xmake_special(VV[16]);
 cl_set(VV[16],mp_make_lock(2, ECL_SYM("NAME",1273), ECL_SYM("FIND-METHOD-COMBINATION",1514)));
 si_Xmake_special(VV[17]);
 cl_set(VV[17],cl_make_hash_table(4, ECL_SYM("SIZE",1308), ecl_make_fixnum(32), ECL_SYM("TEST",1316), ECL_SYM("EQ",333)));
 ecl_cmp_defun(VV[52]);                           /*  SEARCH-METHOD-COMBINATION */
 ecl_cmp_defun(VV[53]);                           /*  INSTALL-METHOD-COMBINATION */
 ecl_cmp_defun(VV[54]);                           /*  MAKE-METHOD-COMBINATION */
 ecl_cmp_defun(VV[55]);                           /*  FIND-METHOD-COMBINATION */
 ecl_cmp_defun(VV[56]);                           /*  DEFINE-SIMPLE-METHOD-COMBINATION */
 (void)0; /* No entry created for DEFINE-COMPLEX-METHOD-COMBINATION */
 ecl_cmp_defmacro(VV[60]);                        /*  DEFINE-METHOD-COMBINATION */
 (void)0; /* No entry created for METHOD-COMBINATION-ERROR */
 (void)0; /* No entry created for INVALID-METHOD-ERROR */
 (void)0; /* No entry created for STD-COMPUTE-EFFECTIVE-METHOD */
 (void)0; /* No entry created for COMPUTE-EFFECTIVE-METHOD-FUNCTION */
 ecl_cmp_defun(VV[61]);                           /*  COMPUTE-EFFECTIVE-METHOD */
 L15install_method_combination(ECL_SYM("STANDARD",972), VV[15]);
 cl_eval(VVtemp[0]);
}
