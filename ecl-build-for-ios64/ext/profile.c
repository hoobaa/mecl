/*	Compiler: ECL 12.12.1                                         */
/*	Source: EXT:PROFILE;PROFILE.LISP                              */
#include <ecl/ecl-cmp.h>
#include "ext/profile.eclh"
/*	function definition for GET-BYTES-CONSED                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1get_bytes_consed(cl_object v1orig)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2bytes;
   v2bytes = ecl_make_unsigned_integer(GC_get_total_bytes());
   if (!(ecl_number_compare(v2bytes,v1orig)<0)) { goto L2; }
   T0 = ecl_minus(ecl_symbol_value(VV[2]),v1orig);
   value0 = ecl_plus(T0,v2bytes);
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
   value0 = ecl_minus(v2bytes,v1orig);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for MAKE-PROFILE-INFO                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2make_profile_info(cl_narg narg, ...)
{
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
   cl_parse_key(args,5,L2make_profile_infokeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[5])) {
    v1 = ecl_function_dispatch(cl_env_copy,VV[65])(0) /*  MISSING-ARG */;
   } else {
    v1 = keyvars[0];
   }
   if (Null(keyvars[6])) {
    v2 = ecl_function_dispatch(cl_env_copy,VV[65])(0) /*  MISSING-ARG */;
   } else {
    v2 = keyvars[1];
   }
   if (Null(keyvars[7])) {
    v3 = ecl_function_dispatch(cl_env_copy,VV[65])(0) /*  MISSING-ARG */;
   } else {
    v3 = keyvars[2];
   }
   if (Null(keyvars[8])) {
    v4 = ecl_function_dispatch(cl_env_copy,VV[65])(0) /*  MISSING-ARG */;
   } else {
    v4 = keyvars[3];
   }
   if (Null(keyvars[9])) {
    v5 = ecl_function_dispatch(cl_env_copy,VV[65])(0) /*  MISSING-ARG */;
   } else {
    v5 = keyvars[4];
   }
  }
  if ((cl_functionp(v5))!=ECL_NIL) { goto L6; }
  si_structure_type_error(4, v5, ECL_SYM("FUNCTION",396), VV[6], VV[8]);
L6:;
  if ((cl_functionp(v4))!=ECL_NIL) { goto L8; }
  si_structure_type_error(4, v4, ECL_SYM("FUNCTION",396), VV[6], VV[9]);
L8:;
  if ((cl_functionp(v3))!=ECL_NIL) { goto L10; }
  si_structure_type_error(4, v3, ECL_SYM("FUNCTION",396), VV[6], VV[10]);
L10:;
  if ((cl_functionp(v2))!=ECL_NIL) { goto L12; }
  si_structure_type_error(4, v2, ECL_SYM("FUNCTION",396), VV[6], VV[11]);
L12:;
  value0 = si_make_structure(6, VV[12], v1, v2, v3, v4, v5);
  return value0;
 }
}
/*	function definition for MAKE-OVERHEAD                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3make_overhead(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1;
  cl_object v2;
  cl_object v3;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  {
   cl_object keyvars[6];
   cl_parse_key(args,3,L3make_overheadkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[3])) {
    v1 = ecl_function_dispatch(cl_env_copy,VV[65])(0) /*  MISSING-ARG */;
   } else {
    v1 = keyvars[0];
   }
   if (Null(keyvars[4])) {
    v2 = ecl_function_dispatch(cl_env_copy,VV[65])(0) /*  MISSING-ARG */;
   } else {
    v2 = keyvars[1];
   }
   if (Null(keyvars[5])) {
    v3 = ecl_function_dispatch(cl_env_copy,VV[65])(0) /*  MISSING-ARG */;
   } else {
    v3 = keyvars[2];
   }
  }
  if (ECL_SINGLE_FLOAT_P(v3)) { goto L4; }
  si_structure_type_error(4, v3, ECL_SYM("SINGLE-FLOAT",778), VV[18], VV[20]);
L4:;
  if (ECL_SINGLE_FLOAT_P(v2)) { goto L6; }
  si_structure_type_error(4, v2, ECL_SYM("SINGLE-FLOAT",778), VV[18], VV[21]);
L6:;
  if (ECL_SINGLE_FLOAT_P(v1)) { goto L8; }
  si_structure_type_error(4, v1, ECL_SYM("SINGLE-FLOAT",778), VV[18], VV[22]);
L8:;
  value0 = si_make_structure(4, VV[23], v1, v2, v3);
  return value0;
 }
}
/*	function definition for PROFILE-ENCAPSULATION-LAMBDAS         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7profile_encapsulation_lambdas(cl_object volatile v1encapsulated_fun)
{
 cl_object T0, T1, T2;
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1, CLV2, CLV3, CLV4
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1encapsulated_fun,env0);    /*  ENCAPSULATED-FUN */
  {
   volatile cl_object env1 = env0;
   {
    cl_object v2;
    v2 = ecl_make_fixnum(0);
    v2 = ecl_make_fixnum(0);
    T1 = ecl_make_bool(ecl_number_compare(v2,ecl_make_fixnum(0))>=0);
    goto L3;
    T1 = ECL_NIL;
    goto L3;
   }
L3:;
   if (ecl_unlikely(!((T1)!=ECL_NIL)))
         FEwrong_type_argument(VV[4],ecl_make_fixnum(0));
   T0 = ecl_make_fixnum(0);
   CLV1 = env1 = CONS(T0,env1);                   /*  COUNT           */
   {
    cl_object v2;
    v2 = ecl_make_fixnum(0);
    v2 = ecl_make_fixnum(0);
    T1 = ecl_make_bool(ecl_number_compare(v2,ecl_make_fixnum(0))>=0);
    goto L12;
    T1 = ECL_NIL;
    goto L12;
   }
L12:;
   if (ecl_unlikely(!((T1)!=ECL_NIL)))
         FEwrong_type_argument(VV[4],ecl_make_fixnum(0));
   T0 = ecl_make_fixnum(0);
   CLV2 = env1 = CONS(T0,env1);                   /*  TICKS           */
   {
    cl_object v2;
    v2 = ecl_make_fixnum(0);
    v2 = ecl_make_fixnum(0);
    T1 = ecl_make_bool(ecl_number_compare(v2,ecl_make_fixnum(0))>=0);
    goto L21;
    T1 = ECL_NIL;
    goto L21;
   }
L21:;
   if (ecl_unlikely(!((T1)!=ECL_NIL)))
         FEwrong_type_argument(VV[4],ecl_make_fixnum(0));
   T0 = ecl_make_fixnum(0);
   CLV3 = env1 = CONS(T0,env1);                   /*  CONSING         */
   {
    cl_object v2;
    v2 = ecl_make_fixnum(0);
    v2 = ecl_make_fixnum(0);
    T1 = ecl_make_bool(ecl_number_compare(v2,ecl_make_fixnum(0))>=0);
    goto L30;
    T1 = ECL_NIL;
    goto L30;
   }
L30:;
   if (ecl_unlikely(!((T1)!=ECL_NIL)))
         FEwrong_type_argument(VV[4],ecl_make_fixnum(0));
   T0 = ecl_make_fixnum(0);
   CLV4 = env1 = CONS(T0,env1);                   /*  PROFILES        */
   {cl_object v2;
    v2 = ECL_NIL;
    v2 = ecl_make_cclosure_va((cl_objectfn)LC4__g52,env1,Cblock);
    T0 = v2;
   }
   {cl_object v2;
    v2 = ECL_NIL;
    v2 = ecl_make_cclosure_va((cl_objectfn)LC5__g128,env1,Cblock);
    T1 = v2;
   }
   {cl_object v2;
    v2 = ECL_NIL;
    v2 = ecl_make_cclosure_va((cl_objectfn)LC6__g129,env1,Cblock);
    T2 = v2;
   }
   cl_env_copy->nvalues = 3;
   cl_env_copy->values[2] = T2;
   cl_env_copy->values[1] = T1;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	closure G52                                                   */
/*	optimize speed 3, debug 1, space 1, safety 3                  */
static cl_object LC4__g52(volatile cl_narg narg, ...)
{
 cl_object T0;
 cl_object volatile CLV0, CLV1, CLV2, CLV3, CLV4
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object volatile env0 = cl_env_copy->function->cclosure.env;
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV4 = env0;                                     /*  PROFILES        */
 CLV3 = _ecl_cdr(CLV4);
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 {
  volatile cl_object v1args;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1args = cl_grab_rest_args(args);
  ecl_va_end(args);
  if (!(ecl_boundp(cl_env_copy,VV[17]))) { goto L1; }
  L14unprofile_all();
  cl_error(4, _ecl_static_4, ecl_symbol_value(VV[17]), ECL_CONS_CAR(CLV0), ECL_CONS_CAR(CLV0));
L1:;
  {
   cl_object v2;
   T0 = ECL_CONS_CAR(CLV1);
   v2 = ecl_plus(T0,ecl_make_fixnum(1));
   {
    cl_object v3;
    v3 = ecl_make_fixnum(0);
    v3 = v2;
    T0 = ecl_make_bool(ecl_number_compare(v3,ecl_make_fixnum(0))>=0);
    goto L8;
    T0 = ECL_NIL;
    goto L8;
   }
L8:;
   if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[4],v2);
   ECL_CONS_CAR(CLV1) = v2;
  }
  {
   volatile cl_object v2;
   volatile cl_object v3;
   volatile cl_object v4;
   volatile cl_object v5;
   volatile cl_object v6;
   volatile cl_object v7dticks;
   volatile cl_object v8dconsing;
   volatile cl_object v9inner_enclosed_profiles;
   v2 = ecl_symbol_value(VV[14]);
   v3 = ecl_symbol_value(VV[15]);
   v4 = ecl_symbol_value(VV[16]);
   v5 = cl_get_internal_run_time();
   v6 = L1get_bytes_consed(ecl_make_fixnum(0));
   v7dticks = ecl_make_fixnum(0);
   v8dconsing = ecl_make_fixnum(0);
   v9inner_enclosed_profiles = ecl_make_fixnum(0);
   {
    volatile bool unwinding = FALSE;
    cl_index v10=ECL_STACK_INDEX(cl_env_copy),v11;
    ecl_frame_ptr next_fr;
    if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
      unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
    } else {
    {
     cl_object v12;
     v12 = ecl_make_fixnum(0);
     v12 = ecl_make_fixnum(0);
     T0 = ecl_make_bool(ecl_number_compare(v12,ecl_make_fixnum(0))>=0);
     goto L28;
     T0 = ECL_NIL;
     goto L28;
    }
L28:;
    if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[4],ecl_make_fixnum(0));
    cl_set(VV[14],ecl_make_fixnum(0));
    ecl_symbol_value(VV[14]);
    {
     cl_object v12;
     v12 = ecl_make_fixnum(0);
     v12 = ecl_make_fixnum(0);
     T0 = ecl_make_bool(ecl_number_compare(v12,ecl_make_fixnum(0))>=0);
     goto L38;
     T0 = ECL_NIL;
     goto L38;
    }
L38:;
    if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[4],ecl_make_fixnum(0));
    cl_set(VV[16],ecl_make_fixnum(0));
    ecl_symbol_value(VV[16]);
    {
     cl_object v12;
     v12 = ecl_make_fixnum(0);
     v12 = ecl_make_fixnum(0);
     T0 = ecl_make_bool(ecl_number_compare(v12,ecl_make_fixnum(0))>=0);
     goto L47;
     T0 = ECL_NIL;
     goto L47;
    }
L47:;
    if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[4],ecl_make_fixnum(0));
    cl_set(VV[15],ecl_make_fixnum(0));
    ecl_symbol_value(VV[15]);
    cl_env_copy->values[0] = cl_apply(2, ECL_CONS_CAR(CLV0), v1args);
    }
    ecl_frs_pop(cl_env_copy);
    v11=ecl_stack_push_values(cl_env_copy);
    T0 = cl_get_internal_run_time();
    v7dticks = ecl_minus(T0,v5);
    v8dconsing = L1get_bytes_consed(v6);
    v9inner_enclosed_profiles = ecl_symbol_value(VV[16]);
    {
     cl_object v12net_dticks;
     v12net_dticks = ecl_minus(v7dticks,ecl_symbol_value(VV[14]));
     {
      cl_object v13;
      T0 = ECL_CONS_CAR(CLV2);
      v13 = ecl_plus(T0,v12net_dticks);
      {
       cl_object v14;
       v14 = ecl_make_fixnum(0);
       if (!(ECL_FIXNUMP(v13)||ECL_BIGNUMP(v13))) { goto L69; }
       v14 = v13;
       T0 = ecl_make_bool(ecl_number_compare(v14,ecl_make_fixnum(0))>=0);
       goto L66;
L69:;
       T0 = ECL_NIL;
       goto L66;
      }
L66:;
      if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[4],v13);
      ECL_CONS_CAR(CLV2) = v13;
     }
    }
    {
     cl_object v12net_dconsing;
     v12net_dconsing = ecl_minus(v8dconsing,ecl_symbol_value(VV[15]));
     {
      cl_object v13;
      T0 = ECL_CONS_CAR(CLV3);
      v13 = ecl_plus(T0,v12net_dconsing);
      {
       cl_object v14;
       v14 = ecl_make_fixnum(0);
       if (!(ECL_FIXNUMP(v13)||ECL_BIGNUMP(v13))) { goto L81; }
       v14 = v13;
       T0 = ecl_make_bool(ecl_number_compare(v14,ecl_make_fixnum(0))>=0);
       goto L78;
L81:;
       T0 = ECL_NIL;
       goto L78;
      }
L78:;
      if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[4],v13);
      ECL_CONS_CAR(CLV3) = v13;
     }
    }
    {
     cl_object v12;
     T0 = ECL_CONS_CAR(CLV4);
     v12 = ecl_plus(T0,v9inner_enclosed_profiles);
     {
      cl_object v13;
      v13 = ecl_make_fixnum(0);
      if (!(ECL_FIXNUMP(v12)||ECL_BIGNUMP(v12))) { goto L92; }
      v13 = v12;
      T0 = ecl_make_bool(ecl_number_compare(v13,ecl_make_fixnum(0))>=0);
      goto L89;
L92:;
      T0 = ECL_NIL;
      goto L89;
     }
L89:;
     if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[4],v12);
     ECL_CONS_CAR(CLV4) = v12;
    }
    {
     cl_object v12;
     v12 = ecl_plus(v2,v7dticks);
     {
      cl_object v13;
      v13 = ecl_make_fixnum(0);
      if (!(ECL_FIXNUMP(v12)||ECL_BIGNUMP(v12))) { goto L103; }
      v13 = v12;
      T0 = ecl_make_bool(ecl_number_compare(v13,ecl_make_fixnum(0))>=0);
      goto L100;
L103:;
      T0 = ECL_NIL;
      goto L100;
     }
L100:;
     if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[4],v12);
     cl_set(VV[14],v12);
    }
    ecl_symbol_value(VV[14]);
    {
     cl_object v12;
     v12 = ecl_plus(v3,v8dconsing);
     {
      cl_object v13;
      v13 = ecl_make_fixnum(0);
      if (!(ECL_FIXNUMP(v12)||ECL_BIGNUMP(v12))) { goto L114; }
      v13 = v12;
      T0 = ecl_make_bool(ecl_number_compare(v13,ecl_make_fixnum(0))>=0);
      goto L111;
L114:;
      T0 = ECL_NIL;
      goto L111;
     }
L111:;
     if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[4],v12);
     cl_set(VV[15],v12);
    }
    ecl_symbol_value(VV[15]);
    {
     cl_object v12;
     T0 = ecl_plus(v4,v9inner_enclosed_profiles);
     v12 = ecl_plus(T0,ecl_make_fixnum(1));
     {
      cl_object v13;
      v13 = ecl_make_fixnum(0);
      if (!(ECL_FIXNUMP(v12)||ECL_BIGNUMP(v12))) { goto L124; }
      v13 = v12;
      T0 = ecl_make_bool(ecl_number_compare(v13,ecl_make_fixnum(0))>=0);
      goto L121;
L124:;
      T0 = ECL_NIL;
      goto L121;
     }
L121:;
     if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[4],v12);
     cl_set(VV[16],v12);
    }
    ecl_symbol_value(VV[16]);
    ecl_stack_pop_values(cl_env_copy,v11);
    if (unwinding) ecl_unwind(cl_env_copy,next_fr);
    ECL_STACK_SET_INDEX(cl_env_copy,v10);
    return cl_env_copy->values[0];
   }
  }
 }
 }
}
/*	closure G128                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC5__g128(cl_narg narg, ...)
{
 cl_object T0, T1, T2;
 cl_object CLV0, CLV1, CLV2, CLV3, CLV4
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV4 = env0;                                     /*  PROFILES        */
 CLV3 = _ecl_cdr(CLV4);
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=0)) FEwrong_num_arguments_anonym();
 {
TTL:
  T0 = ECL_CONS_CAR(CLV1);
  T1 = ECL_CONS_CAR(CLV2);
  T2 = ECL_CONS_CAR(CLV3);
  cl_env_copy->nvalues = 4;
  cl_env_copy->values[3] = ECL_CONS_CAR(CLV4);
  cl_env_copy->values[2] = T2;
  cl_env_copy->values[1] = T1;
  cl_env_copy->values[0] = T0;
  return cl_env_copy->values[0];
 }
 }
}
/*	closure G129                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC6__g129(cl_narg narg, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1, CLV2, CLV3, CLV4
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV4 = env0;                                     /*  PROFILES        */
 CLV3 = _ecl_cdr(CLV4);
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=0)) FEwrong_num_arguments_anonym();
 {
TTL:
  {
   cl_object v1;
   v1 = ecl_make_fixnum(0);
   v1 = ecl_make_fixnum(0);
   T0 = ecl_make_bool(ecl_number_compare(v1,ecl_make_fixnum(0))>=0);
   goto L4;
   T0 = ECL_NIL;
   goto L4;
  }
L4:;
  if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[4],ecl_make_fixnum(0));
  ECL_CONS_CAR(CLV1) = ecl_make_fixnum(0);
  {
   cl_object v1;
   v1 = ecl_make_fixnum(0);
   v1 = ecl_make_fixnum(0);
   T0 = ecl_make_bool(ecl_number_compare(v1,ecl_make_fixnum(0))>=0);
   goto L14;
   T0 = ECL_NIL;
   goto L14;
  }
L14:;
  if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[4],ecl_make_fixnum(0));
  ECL_CONS_CAR(CLV2) = ecl_make_fixnum(0);
  {
   cl_object v1;
   v1 = ecl_make_fixnum(0);
   v1 = ecl_make_fixnum(0);
   T0 = ecl_make_bool(ecl_number_compare(v1,ecl_make_fixnum(0))>=0);
   goto L24;
   T0 = ECL_NIL;
   goto L24;
  }
L24:;
  if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[4],ecl_make_fixnum(0));
  ECL_CONS_CAR(CLV3) = ecl_make_fixnum(0);
  {
   cl_object v1;
   v1 = ecl_make_fixnum(0);
   v1 = ecl_make_fixnum(0);
   T0 = ecl_make_bool(ecl_number_compare(v1,ecl_make_fixnum(0))>=0);
   goto L33;
   T0 = ECL_NIL;
   goto L33;
  }
L33:;
  if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[4],ecl_make_fixnum(0));
  ECL_CONS_CAR(CLV4) = ecl_make_fixnum(0);
  value0 = ECL_CONS_CAR(CLV4);
  cl_env_copy->nvalues = 1;
  return value0;
 }
 }
}
/*	function definition for MAPC-ON-NAMED-FUNS                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8mapc_on_named_funs(cl_object v1function, cl_object v2names)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = v2names;
   goto L5;
L4:;
   {
    cl_object v4name;
    v4name = ecl_car(v3);
    if (!(ECL_SYMBOLP(v4name))) { goto L10; }
    ecl_function_dispatch(cl_env_copy,v1function)(1, v4name);
    goto L9;
L10:;
    if (!(ECL_LISTP(v4name))) { goto L12; }
    ecl_function_dispatch(cl_env_copy,VV[77])(1, v4name) /*  LEGAL-FUN-NAME-OR-TYPE-ERROR */;
    ecl_function_dispatch(cl_env_copy,v1function)(1, v4name);
    goto L9;
L12:;
    if (!(ECL_STRINGP(v4name))) { goto L15; }
    {
     cl_object v5package;
     v5package = cl_find_package(v4name);
     {
      cl_object v6;
      cl_object v7;
      cl_object v8symbol;
      v6 = si_packages_iterator(3, v5package, VV[27], ECL_T);
      v7 = ECL_NIL;
      v8symbol = ECL_NIL;
      goto L23;
L22:;
      value0 = ecl_function_dispatch(cl_env_copy,v6)(0);
      v7 = value0;
      {
       const int v9 = cl_env_copy->nvalues;
       cl_object v10;
       v10 = (v9<=1)? ECL_NIL : cl_env_copy->values[1];
       v8symbol = v10;
      }
      if ((v7)!=ECL_NIL) { goto L27; }
      goto L9;
L27:;
      T0 = cl_symbol_package(v8symbol);
      if (!((T0)==(v5package))) { goto L29; }
      if (Null(cl_fboundp(v8symbol))) { goto L31; }
      if ((cl_macro_function(1, v8symbol))!=ECL_NIL) { goto L31; }
      if ((cl_special_operator_p(v8symbol))!=ECL_NIL) { goto L31; }
      ecl_function_dispatch(cl_env_copy,v1function)(1, v8symbol);
L31:;
      {
       cl_object v9setf_name;
       v9setf_name = cl_list(2, ECL_SYM("SETF",750), v8symbol);
       if (Null(cl_fboundp(v9setf_name))) { goto L29; }
       ecl_function_dispatch(cl_env_copy,v1function)(1, v9setf_name);
      }
L29:;
L23:;
      goto L22;
      goto L9;
     }
    }
L15:;
    si_etypecase_error(v4name, VV[28]);
L9:;
   }
   v3 = ecl_cdr(v3);
L5:;
   if (Null(v3)) { goto L40; }
   goto L4;
L40:;
  }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  return value0;
 }
}
/*	function definition for PROFILE-1-UNPROFILED-FUN              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L9profile_1_unprofiled_fun(cl_object volatile v1name)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   volatile cl_object v2encapsulated_fun;
   v2encapsulated_fun = cl_fdefinition(v1name);
   {
    volatile cl_object v4;                        /*  ENCAPSULATION-FUN */
    volatile cl_object v5;                        /*  READ-STATS-FUN  */
    volatile cl_object v6;                        /*  CLEAR-STATS-FUN */
    value0 = L7profile_encapsulation_lambdas(v2encapsulated_fun);
    v4 = value0;
    {
     const int v7 = cl_env_copy->nvalues;
     cl_object v8;
     v8 = (v7<=1)? ECL_NIL : cl_env_copy->values[1];
     v5 = v8;
     v8 = (v7<=2)? ECL_NIL : cl_env_copy->values[2];
     v6 = v8;
    }
    si_fset(4, v1name, v4, ECL_NIL, ECL_NIL);
    {
     volatile cl_object v7;
     volatile cl_object v8;
     volatile cl_object v9;
     v7 = ecl_symbol_value(VV[1]);
     v8 = mp_lock_owner(v7);
     v9 = mp_lock_count(v7);
     {
      struct ecl_stack_frame _ecl_inner_frame_aux;
      volatile cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
      {
       volatile cl_object v10;
       v10 = _ecl_inner_frame;
       {
        volatile cl_object v11;
        v11 = ecl_symbol_value(ECL_SYM("*INTERRUPTS-ENABLED*",1023));
        ecl_bds_bind(cl_env_copy,ECL_SYM("*INTERRUPTS-ENABLED*",1023),ECL_NIL); /*  *INTERRUPTS-ENABLED* */
        ecl_bds_bind(cl_env_copy,ECL_SYM("*ALLOW-WITH-INTERRUPTS*",1730),ECL_NIL); /*  *ALLOW-WITH-INTERRUPTS* */
        {
         volatile bool unwinding = FALSE;
         cl_index v12=ECL_STACK_INDEX(cl_env_copy),v13;
         ecl_frame_ptr next_fr;
         if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
           unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
         } else {
         ecl_bds_bind(cl_env_copy,ECL_SYM("*INTERRUPTS-ENABLED*",1023),v11); /*  *INTERRUPTS-ENABLED* */
         mp_get_lock(1, v7);
         T0 = ecl_symbol_value(VV[5]);
         T1 = L2make_profile_info(10, ECL_SYM("NAME",1273), v1name, VV[30], v2encapsulated_fun, VV[31], v4, VV[32], v5, VV[33], v6);
         cl_env_copy->values[0] = si_hash_set(v1name, T0, T1);
         ecl_bds_unwind1(cl_env_copy);
         }
         ecl_frs_pop(cl_env_copy);
         v13=ecl_stack_push_values(cl_env_copy);
         T0 = ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398));
         T1 = mp_lock_owner(v7);
         if (!((T0)==(T1))) { goto L15; }
         if (!((v8)==(ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398))))) { goto L18; }
         T0 = mp_lock_count(v7);
         if (!(ecl_number_compare(T0,v9)>0)) { goto L15; }
         goto L16;
L18:;
L16:;
         mp_giveup_lock(v7);
L15:;
         ecl_stack_pop_values(cl_env_copy,v13);
         if (unwinding) ecl_unwind(cl_env_copy,next_fr);
         ECL_STACK_SET_INDEX(cl_env_copy,v12);
         ecl_bds_unwind1(cl_env_copy);
         ecl_bds_unwind1(cl_env_copy);
        }
       }
       ecl_stack_frame_push_values(v10);
       if (Null(ecl_symbol_value(ECL_SYM("*INTERRUPTS-ENABLED*",1023)))) { goto L20; }
       si_check_pending_interrupts();
L20:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v10);
      }
      ecl_stack_frame_close(_ecl_inner_frame);
     }
    }
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 0;
    return value0;
   }
  }
 }
}
/*	function definition for PROFILE-1-FUN                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L10profile_1_fun(cl_object volatile v1name)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_fboundp(v1name))) { goto L2; }
  {
   volatile cl_object v2;
   volatile cl_object v3;
   volatile cl_object v4;
   v2 = ecl_symbol_value(VV[1]);
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
       cl_env_copy->values[0] = cl_gethash(2, v1name, ecl_symbol_value(VV[5]));
       ecl_bds_unwind1(cl_env_copy);
       }
       ecl_frs_pop(cl_env_copy);
       v8=ecl_stack_push_values(cl_env_copy);
       T0 = ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398));
       T1 = mp_lock_owner(v2);
       if (!((T0)==(T1))) { goto L16; }
       if (!((v3)==(ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398))))) { goto L19; }
       T0 = mp_lock_count(v2);
       if (!(ecl_number_compare(T0,v4)>0)) { goto L16; }
       goto L17;
L19:;
L17:;
       mp_giveup_lock(v2);
L16:;
       ecl_stack_pop_values(cl_env_copy,v8);
       if (unwinding) ecl_unwind(cl_env_copy,next_fr);
       ECL_STACK_SET_INDEX(cl_env_copy,v7);
       ecl_bds_unwind1(cl_env_copy);
       ecl_bds_unwind1(cl_env_copy);
      }
     }
     ecl_stack_frame_push_values(v5);
     if (Null(ecl_symbol_value(ECL_SYM("*INTERRUPTS-ENABLED*",1023)))) { goto L21; }
     si_check_pending_interrupts();
L21:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v5);
     value0 = cl_env_copy->values[0];
    }
    ecl_stack_frame_close(_ecl_inner_frame);
   }
   if (Null(value0)) { goto L4; }
  }
  (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(2, _ecl_static_5, v1name) /*  WARN */;
  L11unprofile_1_fun(v1name);
L4:;
  L9profile_1_unprofiled_fun(v1name);
  goto L1;
L2:;
  (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(2, _ecl_static_6, v1name) /*  WARN */;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  return value0;
 }
}
/*	function definition for UNPROFILE-1-FUN                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L11unprofile_1_fun(cl_object volatile v1name)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   volatile cl_object v2pinfo;
   {
    volatile cl_object v3;
    volatile cl_object v4;
    volatile cl_object v5;
    v3 = ecl_symbol_value(VV[1]);
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
        cl_env_copy->values[0] = cl_gethash(2, v1name, ecl_symbol_value(VV[5]));
        ecl_bds_unwind1(cl_env_copy);
        }
        ecl_frs_pop(cl_env_copy);
        v9=ecl_stack_push_values(cl_env_copy);
        T0 = ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398));
        T1 = mp_lock_owner(v3);
        if (!((T0)==(T1))) { goto L13; }
        if (!((v4)==(ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398))))) { goto L16; }
        T0 = mp_lock_count(v3);
        if (!(ecl_number_compare(T0,v5)>0)) { goto L13; }
        goto L14;
L16:;
L14:;
        mp_giveup_lock(v3);
L13:;
        ecl_stack_pop_values(cl_env_copy,v9);
        if (unwinding) ecl_unwind(cl_env_copy,next_fr);
        ECL_STACK_SET_INDEX(cl_env_copy,v8);
        ecl_bds_unwind1(cl_env_copy);
        ecl_bds_unwind1(cl_env_copy);
       }
      }
      ecl_stack_frame_push_values(v6);
      if (Null(ecl_symbol_value(ECL_SYM("*INTERRUPTS-ENABLED*",1023)))) { goto L18; }
      si_check_pending_interrupts();
L18:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v6);
      value0 = cl_env_copy->values[0];
     }
     ecl_stack_frame_close(_ecl_inner_frame);
    }
    v2pinfo = value0;
   }
   if (Null(v2pinfo)) { goto L20; }
   {
    volatile cl_object v3;
    volatile cl_object v4;
    volatile cl_object v5;
    v3 = ecl_symbol_value(VV[1]);
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
        cl_env_copy->values[0] = cl_remhash(v1name, ecl_symbol_value(VV[5]));
        ecl_bds_unwind1(cl_env_copy);
        }
        ecl_frs_pop(cl_env_copy);
        v9=ecl_stack_push_values(cl_env_copy);
        T0 = ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398));
        T1 = mp_lock_owner(v3);
        if (!((T0)==(T1))) { goto L33; }
        if (!((v4)==(ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398))))) { goto L36; }
        T0 = mp_lock_count(v3);
        if (!(ecl_number_compare(T0,v5)>0)) { goto L33; }
        goto L34;
L36:;
L34:;
        mp_giveup_lock(v3);
L33:;
        ecl_stack_pop_values(cl_env_copy,v9);
        if (unwinding) ecl_unwind(cl_env_copy,next_fr);
        ECL_STACK_SET_INDEX(cl_env_copy,v8);
        ecl_bds_unwind1(cl_env_copy);
        ecl_bds_unwind1(cl_env_copy);
       }
      }
      ecl_stack_frame_push_values(v6);
      if (Null(ecl_symbol_value(ECL_SYM("*INTERRUPTS-ENABLED*",1023)))) { goto L38; }
      si_check_pending_interrupts();
L38:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v6);
     }
     ecl_stack_frame_close(_ecl_inner_frame);
    }
   }
   T0 = cl_fdefinition(v1name);
   T1 = ecl_function_dispatch(cl_env_copy,VV[81])(1, v2pinfo) /*  PROFILE-INFO-ENCAPSULATION-FUN */;
   if (!((T0)==(T1))) { goto L40; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[82])(1, v2pinfo) /*  PROFILE-INFO-ENCAPSULATED-FUN */;
   si_fset(4, v1name, T0, ECL_NIL, ECL_NIL);
   goto L1;
L40:;
   (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(2, _ecl_static_7, v1name) /*  WARN */;
   goto L1;
L20:;
   (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(2, _ecl_static_8, v1name) /*  WARN */;
  }
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  return value0;
 }
}
/*	local function PROFILE                                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC12profile(cl_object v1, cl_object v2)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L2; }
   value0 = VV[37];
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
   T0 = cl_list(2, ECL_SYM("QUOTE",679), v3);
   value0 = cl_list(3, VV[29], VV[38], T0);
   return value0;
  }
 }
}
/*	local function UNPROFILE                                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC13unprofile(cl_object v1, cl_object v2)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_cdr(v1);
   if (Null(v3)) { goto L2; }
   T0 = cl_list(2, ECL_SYM("QUOTE",679), v3);
   value0 = cl_list(3, VV[29], VV[40], T0);
   return value0;
L2:;
   value0 = VV[41];
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for UNPROFILE-ALL                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L14unprofile_all()
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   volatile cl_object v1;
   volatile cl_object v2;
   volatile cl_object v3;
   v1 = ecl_symbol_value(VV[1]);
   v2 = mp_lock_owner(v1);
   v3 = mp_lock_count(v1);
   {
    struct ecl_stack_frame _ecl_inner_frame_aux;
    volatile cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
    {
     volatile cl_object v4;
     v4 = _ecl_inner_frame;
     {
      volatile cl_object v5;
      v5 = ecl_symbol_value(ECL_SYM("*INTERRUPTS-ENABLED*",1023));
      ecl_bds_bind(cl_env_copy,ECL_SYM("*INTERRUPTS-ENABLED*",1023),ECL_NIL); /*  *INTERRUPTS-ENABLED* */
      ecl_bds_bind(cl_env_copy,ECL_SYM("*ALLOW-WITH-INTERRUPTS*",1730),ECL_NIL); /*  *ALLOW-WITH-INTERRUPTS* */
      {
       volatile bool unwinding = FALSE;
       cl_index v6=ECL_STACK_INDEX(cl_env_copy),v7;
       ecl_frame_ptr next_fr;
       if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
         unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
       } else {
       ecl_bds_bind(cl_env_copy,ECL_SYM("*INTERRUPTS-ENABLED*",1023),v5); /*  *INTERRUPTS-ENABLED* */
       mp_get_lock(1, v1);
       {
        cl_object v8;
        v8 = si_hash_table_iterator(ecl_symbol_value(VV[5]));
L12:;
        {
         cl_object v10;
         cl_object v11;                           /*  NAME            */
         cl_object v12;                           /*  PROFILE-INFO    */
         value0 = ecl_function_dispatch(cl_env_copy,v8)(0);
         v10 = value0;
         {
          const int v13 = cl_env_copy->nvalues;
          cl_object v14;
          v14 = (v13<=1)? ECL_NIL : cl_env_copy->values[1];
          v11 = v14;
          v14 = (v13<=2)? ECL_NIL : cl_env_copy->values[2];
          v12 = v14;
         }
         if ((v10)!=ECL_NIL) { goto L15; }
         cl_env_copy->values[0] = ECL_NIL;
         cl_env_copy->nvalues = 1;
         ecl_bds_unwind1(cl_env_copy);
         goto L9;
L15:;
         L11unprofile_1_fun(v11);
        }
        goto L12;
       }
L9:;
       }
       ecl_frs_pop(cl_env_copy);
       v7=ecl_stack_push_values(cl_env_copy);
       T0 = ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398));
       T1 = mp_lock_owner(v1);
       if (!((T0)==(T1))) { goto L18; }
       if (!((v2)==(ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398))))) { goto L21; }
       T0 = mp_lock_count(v1);
       if (!(ecl_number_compare(T0,v3)>0)) { goto L18; }
       goto L19;
L21:;
L19:;
       mp_giveup_lock(v1);
L18:;
       ecl_stack_pop_values(cl_env_copy,v7);
       if (unwinding) ecl_unwind(cl_env_copy,next_fr);
       ECL_STACK_SET_INDEX(cl_env_copy,v6);
       ecl_bds_unwind1(cl_env_copy);
       ecl_bds_unwind1(cl_env_copy);
      }
     }
     ecl_stack_frame_push_values(v4);
     if (Null(ecl_symbol_value(ECL_SYM("*INTERRUPTS-ENABLED*",1023)))) { goto L23; }
     si_check_pending_interrupts();
L23:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v4);
     value0 = cl_env_copy->values[0];
    }
    ecl_stack_frame_close(_ecl_inner_frame);
   }
   return value0;
  }
 }
}
/*	function definition for RESET                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L15reset()
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   volatile cl_object v1;
   volatile cl_object v2;
   volatile cl_object v3;
   v1 = ecl_symbol_value(VV[1]);
   v2 = mp_lock_owner(v1);
   v3 = mp_lock_count(v1);
   {
    struct ecl_stack_frame _ecl_inner_frame_aux;
    volatile cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
    {
     volatile cl_object v4;
     v4 = _ecl_inner_frame;
     {
      volatile cl_object v5;
      v5 = ecl_symbol_value(ECL_SYM("*INTERRUPTS-ENABLED*",1023));
      ecl_bds_bind(cl_env_copy,ECL_SYM("*INTERRUPTS-ENABLED*",1023),ECL_NIL); /*  *INTERRUPTS-ENABLED* */
      ecl_bds_bind(cl_env_copy,ECL_SYM("*ALLOW-WITH-INTERRUPTS*",1730),ECL_NIL); /*  *ALLOW-WITH-INTERRUPTS* */
      {
       volatile bool unwinding = FALSE;
       cl_index v6=ECL_STACK_INDEX(cl_env_copy),v7;
       ecl_frame_ptr next_fr;
       if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
         unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
       } else {
       ecl_bds_bind(cl_env_copy,ECL_SYM("*INTERRUPTS-ENABLED*",1023),v5); /*  *INTERRUPTS-ENABLED* */
       mp_get_lock(1, v1);
       {
        cl_object v8;
        v8 = si_hash_table_iterator(ecl_symbol_value(VV[5]));
L12:;
        {
         cl_object v10;
         cl_object v11;                           /*  NAME            */
         cl_object v12;                           /*  PROFILE-INFO    */
         value0 = ecl_function_dispatch(cl_env_copy,v8)(0);
         v10 = value0;
         {
          const int v13 = cl_env_copy->nvalues;
          cl_object v14;
          v14 = (v13<=1)? ECL_NIL : cl_env_copy->values[1];
          v11 = v14;
          v14 = (v13<=2)? ECL_NIL : cl_env_copy->values[2];
          v12 = v14;
         }
         if ((v10)!=ECL_NIL) { goto L15; }
         cl_env_copy->values[0] = ECL_NIL;
         cl_env_copy->nvalues = 1;
         ecl_bds_unwind1(cl_env_copy);
         goto L9;
L15:;
         T0 = ecl_function_dispatch(cl_env_copy,VV[87])(1, v12) /*  PROFILE-INFO-CLEAR-STATS-FUN */;
         ecl_function_dispatch(cl_env_copy,T0)(0);
        }
        goto L12;
       }
L9:;
       }
       ecl_frs_pop(cl_env_copy);
       v7=ecl_stack_push_values(cl_env_copy);
       T0 = ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398));
       T1 = mp_lock_owner(v1);
       if (!((T0)==(T1))) { goto L19; }
       if (!((v2)==(ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398))))) { goto L22; }
       T0 = mp_lock_count(v1);
       if (!(ecl_number_compare(T0,v3)>0)) { goto L19; }
       goto L20;
L22:;
L20:;
       mp_giveup_lock(v1);
L19:;
       ecl_stack_pop_values(cl_env_copy,v7);
       if (unwinding) ecl_unwind(cl_env_copy,next_fr);
       ECL_STACK_SET_INDEX(cl_env_copy,v6);
       ecl_bds_unwind1(cl_env_copy);
       ecl_bds_unwind1(cl_env_copy);
      }
     }
     ecl_stack_frame_push_values(v4);
     if (Null(ecl_symbol_value(ECL_SYM("*INTERRUPTS-ENABLED*",1023)))) { goto L24; }
     si_check_pending_interrupts();
L24:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v4);
     value0 = cl_env_copy->values[0];
    }
    ecl_stack_frame_close(_ecl_inner_frame);
   }
   return value0;
  }
 }
}
/*	function definition for MAKE-TIME-INFO                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L16make_time_info(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1;
  cl_object v2;
  cl_object v3;
  cl_object v4;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  {
   cl_object keyvars[8];
   cl_parse_key(args,4,L16make_time_infokeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v1 = keyvars[0];
   v2 = keyvars[1];
   v3 = keyvars[2];
   v4 = keyvars[3];
  }
  value0 = si_make_structure(5, VV[47], v1, v2, v3, v4);
  return value0;
 }
}
/*	function definition for COMPENSATE-TIME                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L17compensate_time(cl_object v1calls, cl_object v2ticks, cl_object v3profile)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4raw_compensated;
   T0 = cl_float(1, v2ticks);
   T1 = cl_float(1, ecl_make_fixnum(1000));
   T2 = ecl_divide(T0,T1);
   T3 = ecl_function_dispatch(cl_env_copy,VV[94])(1, ecl_symbol_value(VV[25])) /*  OVERHEAD-INTERNAL */;
   T4 = cl_float(1, v1calls);
   T5 = ecl_times(T3,T4);
   T6 = ecl_minus(T2,T5);
   T7 = ecl_function_dispatch(cl_env_copy,VV[95])(1, ecl_symbol_value(VV[25])) /*  OVERHEAD-TOTAL */;
   T8 = ecl_function_dispatch(cl_env_copy,VV[94])(1, ecl_symbol_value(VV[25])) /*  OVERHEAD-INTERNAL */;
   T9 = ecl_minus(T7,T8);
   T10 = cl_float(1, v3profile);
   T11 = ecl_times(T9,T10);
   v4raw_compensated = ecl_minus(T6,T11);
   value0 = (ecl_number_compare(v4raw_compensated,cl_core.singlefloat_zero)>=0?v4raw_compensated:cl_core.singlefloat_zero);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for REPORT                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L19report()
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (ecl_boundp(cl_env_copy,VV[25])) { goto L1; }
  {
   cl_object v1;
   v1 = L24compute_overhead();
   T0 = si_of_class_p(2, v1, VV[18]);
   if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[18],v1);
   cl_set(VV[25],v1);
  }
L1:;
  {
   volatile cl_object v1time_info_list;
   volatile cl_object v2no_call_name_list;
   v1time_info_list = ECL_NIL;
   v2no_call_name_list = ECL_NIL;
   {
    volatile cl_object v3;
    volatile cl_object v4;
    volatile cl_object v5;
    v3 = ecl_symbol_value(VV[1]);
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
        {
         cl_object v10;
         v10 = si_hash_table_iterator(ecl_symbol_value(VV[5]));
L20:;
         {
          cl_object v12;
          cl_object v13;                          /*  NAME            */
          cl_object v14;                          /*  PINFO           */
          value0 = ecl_function_dispatch(cl_env_copy,v10)(0);
          v12 = value0;
          {
          const int v15 = cl_env_copy->nvalues;
          cl_object v16;
          v16 = (v15<=1)? ECL_NIL : cl_env_copy->values[1];
          v13 = v16;
          v16 = (v15<=2)? ECL_NIL : cl_env_copy->values[2];
          v14 = v16;
          }
          if ((v12)!=ECL_NIL) { goto L23; }
          cl_env_copy->values[0] = ECL_NIL;
          cl_env_copy->nvalues = 1;
          ecl_bds_unwind1(cl_env_copy);
          goto L17;
L23:;
          T0 = cl_fdefinition(v13);
          T1 = ecl_function_dispatch(cl_env_copy,VV[81])(1, v14) /*  PROFILE-INFO-ENCAPSULATION-FUN */;
          if ((T0)==(T1)) { goto L25; }
          (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(2, _ecl_static_10, v13) /*  WARN */;
L25:;
          {
          cl_object v16;                          /*  CALLS           */
          cl_object v17;                          /*  TICKS           */
          cl_object v18;                          /*  CONSING         */
          cl_object v19;                          /*  PROFILE         */
          T0 = ecl_function_dispatch(cl_env_copy,VV[97])(1, v14) /*  PROFILE-INFO-READ-STATS-FUN */;
          value0 = ecl_function_dispatch(cl_env_copy,T0)(0);
          v16 = value0;
          {
          const int v20 = cl_env_copy->nvalues;
          cl_object v21;
          v21 = (v20<=1)? ECL_NIL : cl_env_copy->values[1];
          v17 = v21;
          v21 = (v20<=2)? ECL_NIL : cl_env_copy->values[2];
          v18 = v21;
          v21 = (v20<=3)? ECL_NIL : cl_env_copy->values[3];
          v19 = v21;
          }
          if (!(ecl_zerop(v16))) { goto L29; }
          v2no_call_name_list = CONS(v13,v2no_call_name_list);
          goto L21;
L29:;
          T0 = L17compensate_time(v16, v17, v19);
          T1 = L16make_time_info(8, ECL_SYM("NAME",1273), v13, VV[50], v16, VV[51], T0, VV[52], v18);
          v1time_info_list = CONS(T1,v1time_info_list);
          }
         }
L21:;
         goto L20;
        }
L17:;
        }
        ecl_frs_pop(cl_env_copy);
        v9=ecl_stack_push_values(cl_env_copy);
        T0 = ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398));
        T1 = mp_lock_owner(v3);
        if (!((T0)==(T1))) { goto L34; }
        if (!((v4)==(ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398))))) { goto L37; }
        T0 = mp_lock_count(v3);
        if (!(ecl_number_compare(T0,v5)>0)) { goto L34; }
        goto L35;
L37:;
L35:;
        mp_giveup_lock(v3);
L34:;
        ecl_stack_pop_values(cl_env_copy,v9);
        if (unwinding) ecl_unwind(cl_env_copy,next_fr);
        ECL_STACK_SET_INDEX(cl_env_copy,v8);
        ecl_bds_unwind1(cl_env_copy);
        ecl_bds_unwind1(cl_env_copy);
       }
      }
      ecl_stack_frame_push_values(v6);
      if (Null(ecl_symbol_value(ECL_SYM("*INTERRUPTS-ENABLED*",1023)))) { goto L39; }
      si_check_pending_interrupts();
L39:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v6);
     }
     ecl_stack_frame_close(_ecl_inner_frame);
    }
   }
   T0 = (ECL_SYM(">=",76)->symbol.gfdef);
   T1 = ecl_fdefinition(VV[98]);
   v1time_info_list = cl_sort(4, v1time_info_list, T0, ECL_SYM("KEY",1262), T1);
   L21print_profile_table(v1time_info_list);
   if (Null(v2no_call_name_list)) { goto L46; }
   T0 = ecl_symbol_value(ECL_SYM("*TRACE-OUTPUT*",69));
   T1 = (ECL_SYM("STRING<",820)->symbol.gfdef);
   {cl_object v3;
    v3 = ECL_NIL;
    v3 = ecl_make_cfun((cl_objectfn_fixed)LC18__g310,ECL_NIL,Cblock,1);
    T2 = v3;
   }
   T3 = cl_sort(4, v2no_call_name_list, T1, ECL_SYM("KEY",1262), T2);
   cl_format(3, T0, _ecl_static_11, T3);
L46:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 0;
   return value0;
  }
 }
}
/*	local function G310                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC18__g310(cl_object v1name)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_symbol_name(v1name);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for PRINT-PROFILE-TABLE                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L21print_profile_table(cl_object v1time_info_list)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8;
 volatile cl_object lex0[5];
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v2;
   cl_fixnum v3;
   cl_fixnum v4;
   cl_object v5total_seconds;
   cl_object v6total_consed;
   cl_object v7total_calls;
   v2 = ecl_length(_ecl_static_12);
   v3 = ecl_length(_ecl_static_13);
   v4 = ecl_length(_ecl_static_14);
   v5total_seconds = cl_core.singlefloat_zero;
   v6total_consed = ecl_make_fixnum(0);
   v7total_calls = ecl_make_fixnum(0);
   lex0[0] = ecl_make_fixnum(v2);                 /*  SECONDS-WIDTH   */
   lex0[1] = ecl_make_fixnum(v3);                 /*  CONSED-WIDTH    */
   lex0[2] = ecl_make_fixnum(v4);                 /*  CALLS-WIDTH     */
   lex0[3] = ecl_make_fixnum(10);                 /*  SEC/CALL-WIDTH  */
   lex0[4] = ecl_make_fixnum(6);                  /*  NAME-WIDTH      */
   {
    cl_object v8;
    v8 = v1time_info_list;
    goto L11;
L10:;
    {
     cl_object v9time_info;
     v9time_info = ecl_car(v8);
     {
      cl_object v10;
      v10 = ecl_function_dispatch(cl_env_copy,VV[98])(1, v9time_info) /*  TIME-INFO-SECONDS */;
      v5total_seconds = ecl_plus(v5total_seconds,v10);
     }
     {
      cl_object v10;
      v10 = ecl_function_dispatch(cl_env_copy,VV[100])(1, v9time_info) /*  TIME-INFO-CONSING */;
      v6total_consed = ecl_plus(v6total_consed,v10);
     }
     {
      cl_object v10;
      v10 = ecl_function_dispatch(cl_env_copy,VV[101])(1, v9time_info) /*  TIME-INFO-CALLS */;
      v7total_calls = ecl_plus(v7total_calls,v10);
     }
    }
    v8 = ecl_cdr(v8);
L11:;
    if (Null(v8)) { goto L26; }
    goto L10;
L26:;
   }
   T0 = cl_format(3, ECL_NIL, _ecl_static_15, v5total_seconds);
   {
    cl_fixnum v8;
    v8 = ecl_length(T0);
    lex0[0] = (ecl_number_compare(ecl_make_fixnum(v8),lex0[0])>=0?ecl_make_fixnum(v8):lex0[0]);
   }
   T0 = cl_format(3, ECL_NIL, _ecl_static_16, v7total_calls);
   {
    cl_fixnum v8;
    v8 = ecl_length(T0);
    lex0[2] = (ecl_number_compare(ecl_make_fixnum(v8),lex0[2])>=0?ecl_make_fixnum(v8):lex0[2]);
   }
   T0 = cl_format(3, ECL_NIL, _ecl_static_16, v6total_consed);
   {
    cl_fixnum v8;
    v8 = ecl_length(T0);
    lex0[1] = (ecl_number_compare(ecl_make_fixnum(v8),lex0[1])>=0?ecl_make_fixnum(v8):lex0[1]);
   }
   T0 = ecl_one_plus(lex0[1]);
   T1 = ecl_one_plus(lex0[2]);
   T2 = ecl_make_integer((ecl_fixnum(lex0[3]))+1);
   T3 = ecl_make_integer((ecl_fixnum(lex0[4]))+1);
   cl_format(12, ecl_symbol_value(ECL_SYM("*TRACE-OUTPUT*",69)), _ecl_static_17, lex0[0], _ecl_static_12, T0, _ecl_static_13, T1, _ecl_static_14, T2, _ecl_static_18, T3, _ecl_static_19);
   LC20dashes(lex0);
   {
    cl_object v8;
    v8 = v1time_info_list;
    goto L40;
L39:;
    {
     cl_object v9time_info;
     v9time_info = ecl_car(v8);
     T0 = ecl_symbol_value(ECL_SYM("*TRACE-OUTPUT*",69));
     T1 = ecl_function_dispatch(cl_env_copy,VV[98])(1, v9time_info) /*  TIME-INFO-SECONDS */;
     T2 = ecl_function_dispatch(cl_env_copy,VV[100])(1, v9time_info) /*  TIME-INFO-CONSING */;
     T3 = ecl_function_dispatch(cl_env_copy,VV[101])(1, v9time_info) /*  TIME-INFO-CALLS */;
     T4 = ecl_function_dispatch(cl_env_copy,VV[98])(1, v9time_info) /*  TIME-INFO-SECONDS */;
     T5 = ecl_function_dispatch(cl_env_copy,VV[101])(1, v9time_info) /*  TIME-INFO-CALLS */;
     T6 = cl_float(1, T5);
     T7 = ecl_divide(T4,T6);
     T8 = ecl_function_dispatch(cl_env_copy,VV[102])(1, v9time_info) /*  TIME-INFO-NAME */;
     cl_format(10, T0, _ecl_static_20, lex0[0], T1, lex0[1], T2, lex0[2], T3, T7, T8);
    }
    v8 = ecl_cdr(v8);
L40:;
    if (Null(v8)) { goto L47; }
    goto L39;
L47:;
   }
   LC20dashes(lex0);
   cl_format(8, ecl_symbol_value(ECL_SYM("*TRACE-OUTPUT*",69)), _ecl_static_21, lex0[0], v5total_seconds, lex0[1], v6total_consed, lex0[2], v7total_calls);
   T0 = ecl_symbol_value(ECL_SYM("*TRACE-OUTPUT*",69));
   T1 = ecl_function_dispatch(cl_env_copy,VV[95])(1, ecl_symbol_value(VV[25])) /*  OVERHEAD-TOTAL */;
   T2 = cl_float(1, v7total_calls);
   T3 = ecl_times(T1,T2);
   cl_format(3, T0, _ecl_static_22, T3);
   T0 = ecl_symbol_value(ECL_SYM("*TRACE-OUTPUT*",69));
   T1 = ecl_function_dispatch(cl_env_copy,VV[103])(1, ecl_symbol_value(VV[25])) /*  OVERHEAD-CALL */;
   T2 = ecl_function_dispatch(cl_env_copy,VV[95])(1, ecl_symbol_value(VV[25])) /*  OVERHEAD-TOTAL */;
   T3 = ecl_function_dispatch(cl_env_copy,VV[94])(1, ecl_symbol_value(VV[25])) /*  OVERHEAD-INTERNAL */;
   value0 = cl_format(5, T0, _ecl_static_23, T1, T2, T3);
   return value0;
  }
 }
}
/*	local function DASHES                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC20dashes(volatile cl_object *lex0)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v1;
   T0 = ecl_plus(lex0[0],lex0[1]);
   T1 = ecl_plus(T0,lex0[2]);
   T2 = ecl_plus(T1,lex0[3]);
   T3 = ecl_plus(T2,lex0[4]);
   v1 = ecl_plus(T3,ecl_make_fixnum(15));
   {
    cl_object v2i;
    v2i = ecl_make_fixnum(0);
    goto L5;
L4:;
    cl_write_char(2, CODE_CHAR(45), ecl_symbol_value(ECL_SYM("*TRACE-OUTPUT*",69)));
    v2i = ecl_one_plus(v2i);
L5:;
    if (!(ecl_number_compare(v2i,v1)<0)) { goto L10; }
    goto L4;
L10:;
   }
  }
  value0 = ecl_terpri(ecl_symbol_value(ECL_SYM("*TRACE-OUTPUT*",69)));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for COMPUTE-OVERHEAD-AUX                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L22compute_overhead_aux(cl_object v1x)
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
/*	function definition for COMPUTE-OVERHEAD                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L24compute_overhead()
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  cl_format(2, ecl_symbol_value(ECL_SYM("*DEBUG-IO*",30)), _ecl_static_24);
  {
   volatile cl_object v1;
   volatile cl_object v2total_overhead;
   volatile cl_object v3internal_overhead;
   v1 = LC23frob();
   v2total_overhead = ECL_NIL;
   v3internal_overhead = ECL_NIL;
   {
    volatile bool unwinding = FALSE;
    cl_index v4=ECL_STACK_INDEX(cl_env_copy),v5;
    ecl_frame_ptr next_fr;
    if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
      unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
    } else {
    T0 = ecl_fdefinition(VV[35]);
    L8mapc_on_named_funs(T0, VV[57]);
    T0 = LC23frob();
    v2total_overhead = ecl_minus(T0,v1);
    cl_env_copy->values[0] = v2total_overhead;
    cl_env_copy->nvalues = 1;
    }
    ecl_frs_pop(cl_env_copy);
    v5=ecl_stack_push_values(cl_env_copy);
    {
     volatile cl_object v6pinfo;
     volatile cl_object v7read_stats_fun;
     volatile cl_object v8time;
     {
      volatile cl_object v9;
      volatile cl_object v10;
      volatile cl_object v11;
      v9 = ecl_symbol_value(VV[1]);
      v10 = mp_lock_owner(v9);
      v11 = mp_lock_count(v9);
      {
       struct ecl_stack_frame _ecl_inner_frame_aux;
       volatile cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
       {
        volatile cl_object v12;
        v12 = _ecl_inner_frame;
        {
         volatile cl_object v13;
         v13 = ecl_symbol_value(ECL_SYM("*INTERRUPTS-ENABLED*",1023));
         ecl_bds_bind(cl_env_copy,ECL_SYM("*INTERRUPTS-ENABLED*",1023),ECL_NIL); /*  *INTERRUPTS-ENABLED* */
         ecl_bds_bind(cl_env_copy,ECL_SYM("*ALLOW-WITH-INTERRUPTS*",1730),ECL_NIL); /*  *ALLOW-WITH-INTERRUPTS* */
         {
          volatile bool unwinding = FALSE;
          cl_index v14=ECL_STACK_INDEX(cl_env_copy),v15;
          ecl_frame_ptr next_fr;
          if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
            unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
          } else {
          ecl_bds_bind(cl_env_copy,ECL_SYM("*INTERRUPTS-ENABLED*",1023),v13); /*  *INTERRUPTS-ENABLED* */
          mp_get_lock(1, v9);
          cl_env_copy->values[0] = cl_gethash(2, VV[56], ecl_symbol_value(VV[5]));
          ecl_bds_unwind1(cl_env_copy);
          }
          ecl_frs_pop(cl_env_copy);
          v15=ecl_stack_push_values(cl_env_copy);
          T0 = ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398));
          T1 = mp_lock_owner(v9);
          if (!((T0)==(T1))) { goto L24; }
          if (!((v10)==(ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398))))) { goto L27; }
          T0 = mp_lock_count(v9);
          if (!(ecl_number_compare(T0,v11)>0)) { goto L24; }
          goto L25;
L27:;
L25:;
          mp_giveup_lock(v9);
L24:;
          ecl_stack_pop_values(cl_env_copy,v15);
          if (unwinding) ecl_unwind(cl_env_copy,next_fr);
          ECL_STACK_SET_INDEX(cl_env_copy,v14);
          ecl_bds_unwind1(cl_env_copy);
          ecl_bds_unwind1(cl_env_copy);
         }
        }
        ecl_stack_frame_push_values(v12);
        if (Null(ecl_symbol_value(ECL_SYM("*INTERRUPTS-ENABLED*",1023)))) { goto L29; }
        si_check_pending_interrupts();
L29:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v12);
        value0 = cl_env_copy->values[0];
       }
       ecl_stack_frame_close(_ecl_inner_frame);
      }
      v6pinfo = value0;
     }
     v7read_stats_fun = ecl_function_dispatch(cl_env_copy,VV[97])(1, v6pinfo) /*  PROFILE-INFO-READ-STATS-FUN */;
     {
      struct ecl_stack_frame _ecl_inner_frame_aux;
      volatile cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
      {
       cl_object v9;
       v9 = _ecl_inner_frame;
       cl_env_copy->values[0] = ecl_function_dispatch(cl_env_copy,v7read_stats_fun)(0);
       ecl_stack_frame_push_values(v9);cl_env_copy->values[0]=ecl_apply_from_stack_frame(v9,ECL_SYM("LIST",481));
       value0 = cl_env_copy->values[0];
      }
      ecl_stack_frame_close(_ecl_inner_frame);
     }
     T0 = value0;
     v8time = ecl_cadr(T0);
     T0 = cl_float(1, v8time);
     T1 = cl_float(1, ecl_make_fixnum(1000));
     T2 = ecl_divide(T0,T1);
     T3 = cl_float(1, ecl_symbol_value(VV[55]));
     v3internal_overhead = ecl_divide(T2,T3);
    }
    T0 = ecl_fdefinition(VV[36]);
    L8mapc_on_named_funs(T0, VV[57]);
    ecl_stack_pop_values(cl_env_copy,v5);
    if (unwinding) ecl_unwind(cl_env_copy,next_fr);
    ECL_STACK_SET_INDEX(cl_env_copy,v4);
   }
   {
    cl_object v4;
    v4 = L3make_overhead(6, VV[58], v1, VV[59], v2total_overhead, ECL_SYM("INTERNAL",1258), v3internal_overhead);
    cl_format(2, ecl_symbol_value(ECL_SYM("*DEBUG-IO*",30)), _ecl_static_25);
    value0 = v4;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	local function FROB                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC23frob()
{
 cl_object T0, T1, T2, T3, T4, T5;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v1;
   cl_object v2;
   cl_object v3fun;
   v1 = cl_get_internal_run_time();
   v2 = cl_symbol_function(VV[56]);
   T0 = cl_functionp(v2);
   if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("FUNCTION",396),v2);
   v3fun = v2;
   {
    cl_object v4;
    v4 = ecl_symbol_value(VV[55]);
    {
     cl_object v5i;
     v5i = ecl_make_fixnum(0);
     goto L9;
L8:;
     ecl_function_dispatch(cl_env_copy,v3fun)(1, v3fun);
     v5i = ecl_one_plus(v5i);
L9:;
     if (!(ecl_number_compare(v5i,v4)<0)) { goto L14; }
     goto L8;
L14:;
    }
   }
   T0 = cl_get_internal_run_time();
   T1 = ecl_minus(T0,v1);
   T2 = cl_float(1, T1);
   T3 = cl_float(1, ecl_make_fixnum(1000));
   T4 = ecl_divide(T2,T3);
   T5 = cl_float(1, ecl_symbol_value(VV[55]));
   value0 = ecl_divide(T4,T5);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for PROFILE-DEINIT                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L25profile_deinit()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_makunbound(VV[25]);
  return value0;
 }
}

#include "ext/profile.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclAbKKDb3rHoCp9_D3wtVE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("EXT:PROFILE;PROFILE.LISP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclAbKKDb3rHoCp9_D3wtVE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 ecl_function_dispatch(cl_env_copy,VV[62])(10, _ecl_static_0, VVtemp[0], ECL_NIL, _ecl_static_1, ECL_NIL, ECL_NIL, VVtemp[1], ECL_NIL, ECL_NIL, ECL_NIL) /*  DODEFPACKAGE */;
 si_select_package(_ecl_static_0);
 si_Xmake_constant(VV[0], ecl_make_fixnum(1000));
 si_Xmake_special(VV[1]);
 if (ecl_boundp(cl_env_copy,VV[1])) { goto L8; }
 cl_set(VV[1],mp_make_lock(0));
L8:;
 {
  cl_object T0;
 T0 = ecl_make_unsigned_integer(~((size_t)0));
 si_Xmake_constant(VV[2], T0);
 }
 ecl_cmp_defun(VV[63]);                           /*  GET-BYTES-CONSED */
 si_do_deftype(3, VV[4], VVtemp[2], VVtemp[3]);
 si_Xmake_special(VV[5]);
 if (ecl_boundp(cl_env_copy,VV[5])) { goto L27; }
 cl_set(VV[5],cl_make_hash_table(2, ECL_SYM("TEST",1316), ECL_SYM("EQUAL",335)));
L27:;
 si_define_structure(15, VV[6], _ecl_static_2, ECL_NIL, ECL_NIL, VVtemp[4], VVtemp[5], ECL_NIL, ECL_NIL, ECL_NIL, ECL_NIL, VVtemp[6], ecl_make_fixnum(5), ECL_NIL, ECL_NIL, VV[7]);
 VV[12]= cl_find_class(1, VV[6]);
 ecl_cmp_defun(VV[64]);                           /*  MAKE-PROFILE-INFO */
 si_Xmake_special(VV[14]);
 if (ecl_boundp(cl_env_copy,VV[14])) { goto L43; }
 cl_set(VV[14],ecl_make_fixnum(0));
L43:;
 si_Xmake_special(VV[15]);
 if (ecl_boundp(cl_env_copy,VV[15])) { goto L50; }
 cl_set(VV[15],ecl_make_fixnum(0));
L50:;
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[7]) /*  MAPC */;
 si_Xmake_special(VV[16]);
 if (ecl_boundp(cl_env_copy,VV[16])) { goto L59; }
 cl_set(VV[16],ecl_make_fixnum(0));
L59:;
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[8]) /*  MAPC */;
 si_Xmake_special(VV[17]);
 si_define_structure(15, VV[18], _ecl_static_3, ECL_NIL, ECL_NIL, VVtemp[9], VVtemp[10], ECL_NIL, ECL_NIL, ECL_NIL, ECL_NIL, VVtemp[11], ecl_make_fixnum(3), ECL_NIL, ECL_NIL, VV[19]);
 VV[23]= cl_find_class(1, VV[18]);
 ecl_cmp_defun(VV[71]);                           /*  MAKE-OVERHEAD   */
 si_Xmake_special(VV[25]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[12]) /*  MAPC */;
 cl_makunbound(VV[25]);
 ecl_cmp_defun(VV[75]);                           /*  PROFILE-ENCAPSULATION-LAMBDAS */
 ecl_cmp_defun(VV[76]);                           /*  MAPC-ON-NAMED-FUNS */
 ecl_cmp_defun(VV[78]);                           /*  PROFILE-1-UNPROFILED-FUN */
 ecl_cmp_defun(VV[79]);                           /*  PROFILE-1-FUN   */
 ecl_cmp_defun(VV[80]);                           /*  UNPROFILE-1-FUN */
 ecl_cmp_defmacro(VV[83]);                        /*  PROFILE         */
 ecl_cmp_defmacro(VV[84]);                        /*  UNPROFILE       */
 ecl_cmp_defun(VV[85]);                           /*  UNPROFILE-ALL   */
 ecl_cmp_defun(VV[86]);                           /*  RESET           */
 si_define_structure(15, VV[45], _ecl_static_9, ECL_NIL, ECL_NIL, VVtemp[13], VVtemp[14], ECL_NIL, ECL_NIL, ECL_NIL, ECL_NIL, VVtemp[15], ecl_make_fixnum(4), ECL_NIL, ECL_NIL, VV[46]);
 VV[47]= cl_find_class(1, VV[45]);
 ecl_cmp_defun(VV[88]);                           /*  MAKE-TIME-INFO  */
 ecl_cmp_defun(VV[93]);                           /*  COMPENSATE-TIME */
 ecl_cmp_defun(VV[96]);                           /*  REPORT          */
 ecl_cmp_defun(VV[99]);                           /*  PRINT-PROFILE-TABLE */
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[16]) /*  MAPC */;
 si_Xmake_special(VV[55]);
 cl_set(VV[55],ecl_make_fixnum(500000));
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[17]) /*  MAPC */;
 ecl_cmp_defun(VV[104]);                          /*  COMPUTE-OVERHEAD-AUX */
 ecl_cmp_defun(VV[105]);                          /*  COMPUTE-OVERHEAD */
 ecl_cmp_defun(VV[106]);                          /*  PROFILE-DEINIT  */
}
