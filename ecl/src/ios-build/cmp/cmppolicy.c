/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPPOLICY.LSP                                 */
#include <ecl/ecl-cmp.h>
#include "cmp/cmppolicy.eclh"
/*	function definition for POLICY-TO-DEBUG-LEVEL                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1policy_to_debug_level(cl_object v1policy)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v2level;
   v2level = 0;
L2:;
   T0 = ecl_plus(ecl_make_fixnum(v2level),ecl_make_fixnum(0));
   if (Null(cl_logbitp(T0, v1policy))) { goto L4; }
   value0 = ecl_make_fixnum(v2level);
   cl_env_copy->nvalues = 1;
   return value0;
L4:;
   {
    cl_object v3;
    v3 = ecl_make_integer((v2level)+1);
    {
     bool v4;
     v4 = ECL_FIXNUMP(v3);
     if (ecl_unlikely(!(v4)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v3);
    }
    v2level = ecl_fixnum(v3);
   }
   if (!((v2level)>(3))) { goto L10; }
   goto L3;
L10:;
   goto L2;
L3:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for POLICY-TO-SAFETY-LEVEL                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2policy_to_safety_level(cl_object v1policy)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v2level;
   v2level = 0;
L2:;
   T0 = ecl_plus(ecl_make_fixnum(v2level),ecl_make_fixnum(4));
   if (Null(cl_logbitp(T0, v1policy))) { goto L4; }
   value0 = ecl_make_fixnum(v2level);
   cl_env_copy->nvalues = 1;
   return value0;
L4:;
   {
    cl_object v3;
    v3 = ecl_make_integer((v2level)+1);
    {
     bool v4;
     v4 = ECL_FIXNUMP(v3);
     if (ecl_unlikely(!(v4)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v3);
    }
    v2level = ecl_fixnum(v3);
   }
   if (!((v2level)>(3))) { goto L10; }
   goto L3;
L10:;
   goto L2;
L3:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for POLICY-TO-SPEED-LEVEL                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3policy_to_speed_level(cl_object v1policy)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v2level;
   v2level = 0;
L2:;
   T0 = ecl_plus(ecl_make_fixnum(v2level),ecl_make_fixnum(8));
   if (Null(cl_logbitp(T0, v1policy))) { goto L4; }
   value0 = ecl_make_fixnum(v2level);
   cl_env_copy->nvalues = 1;
   return value0;
L4:;
   {
    cl_object v3;
    v3 = ecl_make_integer((v2level)+1);
    {
     bool v4;
     v4 = ECL_FIXNUMP(v3);
     if (ecl_unlikely(!(v4)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v3);
    }
    v2level = ecl_fixnum(v3);
   }
   if (!((v2level)>(3))) { goto L10; }
   goto L3;
L10:;
   goto L2;
L3:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for POLICY-TO-SPACE-LEVEL                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4policy_to_space_level(cl_object v1policy)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v2level;
   v2level = 0;
L2:;
   T0 = ecl_plus(ecl_make_fixnum(v2level),ecl_make_fixnum(12));
   if (Null(cl_logbitp(T0, v1policy))) { goto L4; }
   value0 = ecl_make_fixnum(v2level);
   cl_env_copy->nvalues = 1;
   return value0;
L4:;
   {
    cl_object v3;
    v3 = ecl_make_integer((v2level)+1);
    {
     bool v4;
     v4 = ECL_FIXNUMP(v3);
     if (ecl_unlikely(!(v4)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v3);
    }
    v2level = ecl_fixnum(v3);
   }
   if (!((v2level)>(3))) { goto L10; }
   goto L3;
L10:;
   goto L2;
L3:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for OPTIMIZATION-QUALITY-SWITCHES         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5optimization_quality_switches(cl_object v1type, cl_object v2index)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_gethash(2, v1type, ecl_symbol_value(VV[4]));
  value0 = ecl_nth(ecl_to_size(v2index),T0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for COMPUTE-POLICY                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6compute_policy(cl_object v1arguments, cl_object v2old_bits)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3on;
   cl_object v4off;
   v3on = ecl_make_fixnum(0);
   v4off = ecl_make_fixnum(0);
   {
    cl_object v5;
    v5 = v1arguments;
    goto L7;
L6:;
    {
     cl_object v6x;
     v6x = ecl_car(v5);
     {
      cl_object v7flags;
      cl_object v8name;
      cl_object v9value;
      v7flags = ECL_NIL;
      v8name = ECL_NIL;
      v9value = ECL_NIL;
      if (!(ECL_SYMBOLP(v6x))) { goto L16; }
      v7flags = L5optimization_quality_switches(v6x, ecl_make_fixnum(3));
      v9value = ecl_make_fixnum(3);
      v8name = v6x;
      goto L15;
L16:;
      {
       cl_object v10;
       {
        bool v11;
        v11 = ECL_CONSP(v6x);
        value0 = (v11)?ECL_NIL:ECL_T;
       }
       if ((value0)!=ECL_NIL) { goto L25; }
       T0 = ecl_cdr(v6x);
       {
        bool v11;
        v11 = ECL_CONSP(T0);
        value0 = (v11)?ECL_NIL:ECL_T;
       }
       if ((value0)!=ECL_NIL) { goto L25; }
       T0 = ecl_cadr(v6x);
       {
        bool v11;
        v11 = ecl_numberp(T0);
        value0 = (v11)?ECL_NIL:ECL_T;
       }
       if ((value0)!=ECL_NIL) { goto L25; }
       T0 = ecl_cadr(v6x);
       T1 = cl_LE(3, ecl_make_fixnum(0), T0, ecl_make_fixnum(3));
       v10 = Null(T1)?ECL_T:ECL_NIL;
       goto L23;
L25:;
       v10 = value0;
       goto L23;
L23:;
       if (Null(v10)) { goto L29; }
       goto L15;
L29:;
       v8name = ecl_car(v6x);
       v9value = ecl_cadr(v6x);
       T0 = ecl_cadr(v6x);
       v7flags = L5optimization_quality_switches(v8name, T0);
      }
L15:;
      if (!(v7flags==ECL_NIL)) { goto L36; }
      ecl_function_dispatch(cl_env_copy,VV[49])(2, _ecl_static_1, v6x) /*  CMPWARN */;
      goto L11;
L36:;
      T0 = ecl_car(v7flags);
      v3on = ecl_boole(ECL_BOOLIOR,(v3on),(T0));
      T0 = ecl_cdr(v7flags);
      v4off = ecl_boole(ECL_BOOLIOR,(v4off),(T0));
     }
L11:;
    }
    v5 = ecl_cdr(v5);
L7:;
    if (Null(v5)) { goto L43; }
    goto L6;
L43:;
   }
   T0 = ecl_boole(ECL_BOOLIOR,(v2old_bits),(v3on));
   value0 = ecl_boole(ECL_BOOLANDC2,(T0),(v4off));
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for DEFAULT-POLICY                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7default_policy()
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, ECL_SYM("SPACE",788), ecl_symbol_value(VV[7]));
  T1 = cl_list(2, ECL_SYM("SAFETY",734), ecl_symbol_value(VV[8]));
  T2 = cl_list(2, ECL_SYM("DEBUG",270), ecl_symbol_value(VV[9]));
  T3 = cl_list(2, ECL_SYM("SPEED",791), ecl_symbol_value(VV[10]));
  T4 = cl_list(4, T0, T1, T2, T3);
  value0 = L6compute_policy(T4, ecl_make_fixnum(0));
  return value0;
 }
}
/*	function definition for CMP-ENV-POLICY                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8cmp_env_policy(cl_object v1env)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[52])(2, VV[12], v1env) /*  CMP-ENV-SEARCH-DECLARATION */;
  value0 = ecl_car(T0);
  if ((value0)!=ECL_NIL) { goto L2; }
  value0 = L7default_policy();
  return value0;
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for CMP-ENV-ADD-OPTIMIZATIONS             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L9cmp_env_add_optimizations(cl_narg narg, cl_object v1decl, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2env;
  va_list args; va_start(args,v1decl);
  {
   int i = 1;
   if (i >= narg) {
    v2env = ecl_symbol_value(VV[14]);
   } else {
    i++;
    v2env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v3old;
   cl_object v4new;
   v3old = L8cmp_env_policy(v2env);
   v4new = L6compute_policy(v1decl, v3old);
   T0 = ecl_list1(v4new);
   value0 = ecl_function_dispatch(cl_env_copy,VV[54])(3, VV[12], T0, v2env) /*  CMP-ENV-ADD-DECLARATION */;
   return value0;
  }
 }
}
/*	function definition for POLICY-DECLARATION-NAME-P             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L10policy_declaration_name_p(cl_object v1name)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_gethash_safe(v1name,ecl_symbol_value(VV[4]),ECL_NIL))) { goto L2; }
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for MAYBE-ADD-POLICY                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L11maybe_add_policy(cl_narg narg, cl_object v1decl, ...)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2env;
  va_list args; va_start(args,v1decl);
  {
   int i = 1;
   if (i >= narg) {
    v2env = ecl_symbol_value(VV[14]);
   } else {
    i++;
    v2env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (!(ECL_CONSP(v1decl))) { goto L2; }
  T0 = cl_list_length(v1decl);
  if (!(ecl_number_compare(T0,ecl_make_fixnum(2))<=0)) { goto L2; }
  T0 = ecl_car(v1decl);
  if (Null(ecl_gethash_safe(T0,ecl_symbol_value(VV[4]),ECL_NIL))) { goto L2; }
  {
   cl_object v3old;
   cl_fixnum v4flag;
   cl_object v5new;
   v3old = L8cmp_env_policy(v2env);
   T0 = ecl_cdr(v1decl);
   if (ecl_endp(T0)) { goto L10; }
   if (Null(ecl_cadr(v1decl))) { goto L8; }
   goto L9;
L10:;
L9:;
   v4flag = 3;
   goto L7;
L8:;
   v4flag = 0;
L7:;
   T0 = ecl_car(v1decl);
   T1 = cl_list(2, T0, ecl_make_fixnum(v4flag));
   T2 = ecl_list1(T1);
   v5new = L6compute_policy(T2, v3old);
   T0 = ecl_list1(v5new);
   value0 = ecl_function_dispatch(cl_env_copy,VV[54])(3, VV[12], T0, v2env) /*  CMP-ENV-ADD-DECLARATION */;
   return value0;
  }
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for ADD-DEFAULT-OPTIMIZATIONS             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L12add_default_optimizations(cl_object v1env)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[52])(2, VV[12], v1env) /*  CMP-ENV-SEARCH-DECLARATION */)) { goto L1; }
  value0 = v1env;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  T0 = L7default_policy();
  T1 = ecl_list1(T0);
  value0 = ecl_function_dispatch(cl_env_copy,VV[54])(3, VV[12], T1, v1env) /*  CMP-ENV-ADD-DECLARATION */;
  return value0;
 }
}
/*	function definition for CMP-ENV-ALL-OPTIMIZATIONS             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L13cmp_env_all_optimizations(cl_narg narg, ...)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1env;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1env = ecl_symbol_value(VV[14]);
   } else {
    i++;
    v1env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v2o;
   v2o = L8cmp_env_policy(v1env);
   T0 = L1policy_to_debug_level(v2o);
   T1 = L2policy_to_safety_level(v2o);
   T2 = L4policy_to_space_level(v2o);
   T3 = L3policy_to_speed_level(v2o);
   value0 = cl_list(4, T0, T1, T2, T3);
   return value0;
  }
 }
}
/*	function definition for CMP-ENV-OPTIMIZATION                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L14cmp_env_optimization(cl_narg narg, cl_object v1property, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2env;
  va_list args; va_start(args,v1property);
  {
   int i = 1;
   if (i >= narg) {
    v2env = ecl_symbol_value(VV[14]);
   } else {
    i++;
    v2env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v3o;
   v3o = L8cmp_env_policy(v2env);
   if (!((v1property)==(ECL_SYM("DEBUG",270)))) { goto L3; }
   value0 = L1policy_to_debug_level(v3o);
   return value0;
L3:;
   if (!((v1property)==(ECL_SYM("SAFETY",734)))) { goto L5; }
   value0 = L2policy_to_safety_level(v3o);
   return value0;
L5:;
   if (!((v1property)==(ECL_SYM("SPACE",788)))) { goto L7; }
   value0 = L4policy_to_space_level(v3o);
   return value0;
L7:;
   if (!((v1property)==(ECL_SYM("SPEED",791)))) { goto L9; }
   value0 = L3policy_to_speed_level(v3o);
   return value0;
L9:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for POLICY-ASSUME-NO-ERRORS               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L15policy_assume_no_errors(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1env;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1env = ecl_symbol_value(VV[14]);
   } else {
    i++;
    v1env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v2bits;
   v2bits = L8cmp_env_policy(v1env);
   value0 = cl_logtest(v2bits, ecl_make_fixnum(131072));
   return value0;
  }
 }
}
/*	function definition for POLICY-ASSUME-RIGHT-TYPE              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L16policy_assume_right_type(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1env;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1env = ecl_symbol_value(VV[14]);
   } else {
    i++;
    v1env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = L15policy_assume_no_errors(1, v1env);
  return value0;
 }
}
/*	function definition for POLICY-TYPE-ASSERTIONS                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L17policy_type_assertions(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1env;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1env = ecl_symbol_value(VV[14]);
   } else {
    i++;
    v1env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  T0 = L15policy_assume_no_errors(1, v1env);
  value0 = Null(T0)?ECL_T:ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for POLICY-CHECK-STACK-OVERFLOW           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L18policy_check_stack_overflow(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1env;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1env = ecl_symbol_value(VV[14]);
   } else {
    i++;
    v1env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v2bits;
   v2bits = L8cmp_env_policy(v1env);
   value0 = cl_logtest(v2bits, ecl_make_fixnum(262144));
   return value0;
  }
 }
}
/*	function definition for POLICY-CHECK-ARGUMENTS-TYPE           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L19policy_check_arguments_type(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1env;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1env = ecl_symbol_value(VV[14]);
   } else {
    i++;
    v1env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v2bits;
   v2bits = L8cmp_env_policy(v1env);
   value0 = cl_logtest(v2bits, ecl_make_fixnum(524288));
   return value0;
  }
 }
}
/*	function definition for POLICY-ARRAY-BOUNDS-CHECK             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L20policy_array_bounds_check(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1env;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1env = ecl_symbol_value(VV[14]);
   } else {
    i++;
    v1env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v2bits;
   v2bits = L8cmp_env_policy(v1env);
   value0 = cl_logtest(v2bits, ecl_make_fixnum(1048576));
   return value0;
  }
 }
}
/*	function definition for POLICY-GLOBAL-VAR-CHECKING            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L21policy_global_var_checking(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1env;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1env = ecl_symbol_value(VV[14]);
   } else {
    i++;
    v1env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v2bits;
   v2bits = L8cmp_env_policy(v1env);
   value0 = cl_logtest(v2bits, ecl_make_fixnum(2097152));
   return value0;
  }
 }
}
/*	function definition for POLICY-GLOBAL-FUNCTION-CHECKING       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L22policy_global_function_checking(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1env;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1env = ecl_symbol_value(VV[14]);
   } else {
    i++;
    v1env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v2bits;
   v2bits = L8cmp_env_policy(v1env);
   value0 = cl_logtest(v2bits, ecl_make_fixnum(4194304));
   return value0;
  }
 }
}
/*	function definition for POLICY-CHECK-NARGS                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L23policy_check_nargs(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1env;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1env = ecl_symbol_value(VV[14]);
   } else {
    i++;
    v1env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v2bits;
   v2bits = L8cmp_env_policy(v1env);
   value0 = cl_logtest(v2bits, ecl_make_fixnum(8388608));
   return value0;
  }
 }
}
/*	function definition for POLICY-THE-IS-CHECKED                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L24policy_the_is_checked(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1env;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1env = ecl_symbol_value(VV[14]);
   } else {
    i++;
    v1env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v2bits;
   v2bits = L8cmp_env_policy(v1env);
   value0 = cl_logtest(v2bits, ecl_make_fixnum(16777216));
   return value0;
  }
 }
}
/*	function definition for POLICY-ASSUME-TYPES-DONT-CHANGE       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L25policy_assume_types_dont_change(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1env;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1env = ecl_symbol_value(VV[14]);
   } else {
    i++;
    v1env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v2bits;
   v2bits = L8cmp_env_policy(v1env);
   value0 = cl_logtest(v2bits, ecl_make_fixnum(33554432));
   return value0;
  }
 }
}
/*	function definition for POLICY-INLINE-SLOT-ACCESS             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L26policy_inline_slot_access(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1env;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1env = ecl_symbol_value(VV[14]);
   } else {
    i++;
    v1env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v2bits;
   v2bits = L8cmp_env_policy(v1env);
   value0 = cl_logtest(v2bits, ecl_make_fixnum(67108864));
   return value0;
  }
 }
}
/*	function definition for POLICY-INLINE-ACCESSORS               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L27policy_inline_accessors(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1env;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1env = ecl_symbol_value(VV[14]);
   } else {
    i++;
    v1env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v2bits;
   v2bits = L8cmp_env_policy(v1env);
   value0 = cl_logtest(v2bits, ecl_make_fixnum(134217728));
   return value0;
  }
 }
}
/*	function definition for POLICY-OPEN-CODE-AREF/ASET            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L28policy_open_code_aref_aset(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1env;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1env = ecl_symbol_value(VV[14]);
   } else {
    i++;
    v1env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = L27policy_inline_accessors(1, v1env);
  return value0;
 }
}
/*	function definition for POLICY-EVALUATE-FORMS                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L29policy_evaluate_forms(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1env;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1env = ecl_symbol_value(VV[14]);
   } else {
    i++;
    v1env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v2bits;
   v2bits = L8cmp_env_policy(v1env);
   value0 = cl_logtest(v2bits, ecl_make_fixnum(268435456));
   return value0;
  }
 }
}
/*	function definition for POLICY-USE-DIRECT-C-CALL              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L30policy_use_direct_c_call(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1env;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1env = ecl_symbol_value(VV[14]);
   } else {
    i++;
    v1env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v2bits;
   v2bits = L8cmp_env_policy(v1env);
   value0 = cl_logtest(v2bits, ecl_make_fixnum(536870912));
   return value0;
  }
 }
}
/*	function definition for POLICY-INLINE-TYPE-CHECKS             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L31policy_inline_type_checks(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1env;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1env = ecl_symbol_value(VV[14]);
   } else {
    i++;
    v1env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v2bits;
   v2bits = L8cmp_env_policy(v1env);
   value0 = cl_logtest(v2bits, ecl_make_fixnum(1073741824));
   return value0;
  }
 }
}
/*	function definition for POLICY-INLINE-SEQUENCE-FUNCTIONS      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L32policy_inline_sequence_functions(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1env;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1env = ecl_symbol_value(VV[14]);
   } else {
    i++;
    v1env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v2bits;
   v2bits = L8cmp_env_policy(v1env);
   value0 = cl_logtest(v2bits, ecl_make_fixnum(2147483648));
   return value0;
  }
 }
}
/*	function definition for POLICY-DEBUG-VARIABLE-BINDINGS        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L33policy_debug_variable_bindings(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1env;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1env = ecl_symbol_value(VV[14]);
   } else {
    i++;
    v1env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v2bits;
   v2bits = L8cmp_env_policy(v1env);
   if (Null(cl_logtest(v2bits, ecl_make_fixnum(4294967296)))) { goto L4; }
   value0 = L34policy_debug_ihs_frame(1, v1env);
   return value0;
L4:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for POLICY-DEBUG-IHS-FRAME                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L34policy_debug_ihs_frame(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1env;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1env = ecl_symbol_value(VV[14]);
   } else {
    i++;
    v1env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v2bits;
   v2bits = L8cmp_env_policy(v1env);
   value0 = cl_logtest(v2bits, ecl_make_fixnum(8589934592));
   return value0;
  }
 }
}
/*	function definition for SAFE-COMPILE                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L35safe_compile()
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = L14cmp_env_optimization(1, ECL_SYM("SAFETY",734));
  value0 = ecl_make_bool(ecl_number_compare(T0,ecl_make_fixnum(2))>=0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for COMPILER-PUSH-EVENTS                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L36compiler_push_events()
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = L14cmp_env_optimization(1, ECL_SYM("SAFETY",734));
  value0 = ecl_make_bool(ecl_number_compare(T0,ecl_make_fixnum(3))>=0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}

#include "cmp/cmppolicy.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclmXc8rDxglsIr9_42yTOE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPPOLICY.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclmXc8rDxglsIr9_42yTOE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[43]);                           /*  POLICY-TO-DEBUG-LEVEL */
 ecl_cmp_defun(VV[44]);                           /*  POLICY-TO-SAFETY-LEVEL */
 ecl_cmp_defun(VV[45]);                           /*  POLICY-TO-SPEED-LEVEL */
 ecl_cmp_defun(VV[46]);                           /*  POLICY-TO-SPACE-LEVEL */
 ecl_cmp_defun(VV[47]);                           /*  OPTIMIZATION-QUALITY-SWITCHES */
 ecl_cmp_defun(VV[48]);                           /*  COMPUTE-POLICY  */
 ecl_cmp_defun(VV[50]);                           /*  DEFAULT-POLICY  */
 ecl_cmp_defun(VV[51]);                           /*  CMP-ENV-POLICY  */
 ecl_cmp_defun(VV[53]);                           /*  CMP-ENV-ADD-OPTIMIZATIONS */
 ecl_cmp_defun(VV[55]);                           /*  POLICY-DECLARATION-NAME-P */
 ecl_cmp_defun(VV[56]);                           /*  MAYBE-ADD-POLICY */
 ecl_cmp_defun(VV[57]);                           /*  ADD-DEFAULT-OPTIMIZATIONS */
 ecl_cmp_defun(VV[58]);                           /*  CMP-ENV-ALL-OPTIMIZATIONS */
 ecl_cmp_defun(VV[59]);                           /*  CMP-ENV-OPTIMIZATION */
 ecl_cmp_defun(VV[60]);                           /*  POLICY-ASSUME-NO-ERRORS */
 ecl_cmp_defun(VV[61]);                           /*  POLICY-ASSUME-RIGHT-TYPE */
 ecl_cmp_defun(VV[62]);                           /*  POLICY-TYPE-ASSERTIONS */
 ecl_cmp_defun(VV[63]);                           /*  POLICY-CHECK-STACK-OVERFLOW */
 ecl_cmp_defun(VV[64]);                           /*  POLICY-CHECK-ARGUMENTS-TYPE */
 ecl_cmp_defun(VV[65]);                           /*  POLICY-ARRAY-BOUNDS-CHECK */
 ecl_cmp_defun(VV[66]);                           /*  POLICY-GLOBAL-VAR-CHECKING */
 ecl_cmp_defun(VV[67]);                           /*  POLICY-GLOBAL-FUNCTION-CHECKING */
 ecl_cmp_defun(VV[68]);                           /*  POLICY-CHECK-NARGS */
 ecl_cmp_defun(VV[69]);                           /*  POLICY-THE-IS-CHECKED */
 ecl_cmp_defun(VV[70]);                           /*  POLICY-ASSUME-TYPES-DONT-CHANGE */
 ecl_cmp_defun(VV[71]);                           /*  POLICY-INLINE-SLOT-ACCESS */
 ecl_cmp_defun(VV[72]);                           /*  POLICY-INLINE-ACCESSORS */
 ecl_cmp_defun(VV[73]);                           /*  POLICY-OPEN-CODE-AREF/ASET */
 ecl_cmp_defun(VV[74]);                           /*  POLICY-EVALUATE-FORMS */
 ecl_cmp_defun(VV[75]);                           /*  POLICY-USE-DIRECT-C-CALL */
 ecl_cmp_defun(VV[76]);                           /*  POLICY-INLINE-TYPE-CHECKS */
 ecl_cmp_defun(VV[77]);                           /*  POLICY-INLINE-SEQUENCE-FUNCTIONS */
 ecl_cmp_defun(VV[78]);                           /*  POLICY-DEBUG-VARIABLE-BINDINGS */
 ecl_cmp_defun(VV[79]);                           /*  POLICY-DEBUG-IHS-FRAME */
 ecl_cmp_defun(VV[80]);                           /*  SAFE-COMPILE    */
 ecl_cmp_defun(VV[81]);                           /*  COMPILER-PUSH-EVENTS */
 {
  cl_object T0;
 si_Xmake_special(VV[4]);
 T0 = cl_make_hash_table(8, ECL_SYM("SIZE",1308), ecl_make_fixnum(64), ECL_SYM("REHASH-SIZE",1297), _ecl_static_2, ECL_SYM("REHASH-THRESHOLD",1298), _ecl_static_3, ECL_SYM("TEST",1316), ECL_SYM("EQ",333));
 VVtemp[0]= si_hash_table_fill(T0, VVtemp[1]);
 cl_set(VV[4],VVtemp[0]);
 }
}
