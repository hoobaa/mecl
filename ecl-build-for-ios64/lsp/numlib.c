/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:LSP;NUMLIB.LSP                                    */
#include <ecl/ecl-cmp.h>
#include "lsp/numlib.eclh"
/*	function definition for ISQRT                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_isqrt(cl_object v1i)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_FIXNUMP(v1i)||ECL_BIGNUMP(v1i))) { goto L4; }
  if (ecl_number_compare(v1i,ecl_make_fixnum(0))>=0) { goto L1; }
  goto L2;
L4:;
  goto L2;
L2:;
  cl_error(5, ECL_SYM("TYPE-ERROR",870), ECL_SYM("DATUM",1214), v1i, ECL_SYM("EXPECTED-TYPE",1232), ECL_SYM("UNSIGNED-BYTE",885));
L1:;
  if (!(ecl_zerop(v1i))) { goto L6; }
  value0 = ecl_make_fixnum(0);
  cl_env_copy->nvalues = 1;
  return value0;
L6:;
  {
   cl_fixnum v2n;
   v2n = (cl_fixnum)(ecl_integer_length(v1i));
   {
    cl_object v3;
    cl_object v4x;
    cl_object v5y;
    T0 = ecl_ceiling2(ecl_make_fixnum(v2n),ecl_make_fixnum(2));
    v3 = cl_ash(ecl_make_fixnum(1), T0);
    v4x = v3;
    v5y = ECL_NIL;
    goto L14;
L13:;
    v5y = ecl_floor2(v1i,v4x);
    if (!(ecl_number_compare(v4x,v5y)<=0)) { goto L18; }
    value0 = v4x;
    cl_env_copy->nvalues = 1;
    return value0;
L18:;
    T0 = ecl_plus(v4x,v5y);
    v4x = ecl_floor2(T0,ecl_make_fixnum(2));
L14:;
    goto L13;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for PHASE                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_phase(cl_object v1x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ecl_zerop(v1x))) { goto L1; }
  if (!((v1x)==(ecl_make_fixnum(0)))) { goto L3; }
  value0 = cl_core.singlefloat_zero;
  cl_env_copy->nvalues = 1;
  return value0;
L3:;
  T0 = cl_realpart(v1x);
  value0 = cl_float(2, ecl_make_fixnum(0), T0);
  return value0;
L1:;
  T0 = cl_imagpart(v1x);
  T1 = cl_realpart(v1x);
  value0 = cl_atan(2, T0, T1);
  return value0;
 }
}
/*	function definition for SIGNUM                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_signum(cl_object v1x)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ecl_zerop(v1x))) { goto L1; }
  value0 = v1x;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  T0 = cl_abs(v1x);
  value0 = ecl_divide(v1x,T0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for CIS                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_cis(cl_object v1x)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_times(ecl_symbol_value(VV[0]),v1x);
  value0 = ecl_exp(T0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for ASIN                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_asin(cl_object v1x)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_complexp(v1x))) { goto L1; }
  value0 = L1complex_asin(v1x);
  return value0;
L1:;
  {
   cl_object v2x;
   long double v3xr;
   v2x = cl_float(1, v1x);
   v3xr = ecl_to_long_double(v2x);
   if (!(((float)  -1.0    )<=(v3xr))) { goto L5; }
   if (!((v3xr)<=((float)   1.0    ))) { goto L5; }
   {
    long double v4;
    v4 = asinl(v3xr);
    value0 = cl_float(2, ecl_make_long_float(v4), v2x);
    return value0;
   }
L5:;
   value0 = L1complex_asin(v2x);
   return value0;
  }
 }
}
/*	function definition for COMPLEX-ASIN                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1complex_asin(cl_object v1z)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   cl_object v3;
   T0 = ecl_minus(ecl_make_fixnum(1),v1z);
   v2 = ecl_sqrt(T0);
   T0 = ecl_plus(ecl_make_fixnum(1),v1z);
   v3 = ecl_sqrt(T0);
   T0 = cl_realpart(v1z);
   T1 = ecl_times(v2,v3);
   T2 = cl_realpart(T1);
   T3 = cl_atan(2, T0, T2);
   T4 = cl_conjugate(v2);
   T5 = ecl_times(T4,v3);
   T6 = cl_imagpart(T5);
   T7 = cl_asinh(T6);
   value0 = cl_complex(2, T3, T7);
   return value0;
  }
 }
}
/*	function definition for ACOS                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_acos(cl_object v1x)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_complexp(v1x))) { goto L1; }
  value0 = L2complex_acos(v1x);
  return value0;
L1:;
  {
   cl_object v2x;
   long double v3xr;
   v2x = cl_float(1, v1x);
   v3xr = ecl_to_long_double(v2x);
   if (!(((float)  -1.0    )<=(v3xr))) { goto L5; }
   if (!((v3xr)<=((float)   1.0    ))) { goto L5; }
   {
    long double v4;
    v4 = acosl(v3xr);
    T0 = cl_float(1, v2x);
    value0 = cl_float(2, ecl_make_long_float(v4), T0);
    return value0;
   }
L5:;
   value0 = L2complex_acos(v2x);
   return value0;
  }
 }
}
/*	function definition for COMPLEX-ACOS                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2complex_acos(cl_object v1z)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   cl_object v3;
   T0 = ecl_plus(ecl_make_fixnum(1),v1z);
   v2 = ecl_sqrt(T0);
   T0 = ecl_minus(ecl_make_fixnum(1),v1z);
   v3 = ecl_sqrt(T0);
   T0 = cl_realpart(v3);
   T1 = cl_realpart(v2);
   T2 = cl_atan(2, T0, T1);
   T3 = ecl_times(ecl_make_fixnum(2),T2);
   T4 = cl_conjugate(v2);
   T5 = ecl_times(T4,v3);
   T6 = cl_imagpart(T5);
   T7 = cl_asinh(T6);
   value0 = cl_complex(2, T3, T7);
   return value0;
  }
 }
}
/*	function definition for ASINH                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_asinh(cl_object v1x)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_complexp(v1x))) { goto L1; }
  {
   cl_object v2iz;
   cl_object v3result;
   T0 = cl_imagpart(v1x);
   T1 = ecl_negate(T0);
   T2 = cl_realpart(v1x);
   v2iz = cl_complex(2, T1, T2);
   v3result = L1complex_asin(v2iz);
   T0 = cl_imagpart(v3result);
   T1 = cl_realpart(v3result);
   T2 = ecl_negate(T1);
   value0 = cl_complex(2, T0, T2);
   return value0;
  }
L1:;
  {
   long double v4;
   v4 = asinhl(ecl_to_long_double(v1x));
   T0 = cl_float(1, v1x);
   value0 = cl_float(2, ecl_make_long_float(v4), T0);
   return value0;
  }
 }
}
/*	function definition for ACOSH                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_acosh(cl_object v1x)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_complexp(v1x))) { goto L1; }
  value0 = L3complex_acosh(v1x);
  return value0;
L1:;
  {
   cl_object v2x;
   double v3xr;
   v2x = cl_float(1, v1x);
   v3xr = ecl_to_double(v2x);
   if (!(((float)   1.0    )<=(v3xr))) { goto L5; }
   {
    long double v4;
    v4 = acoshl((long double)(v3xr));
    T0 = cl_float(1, v2x);
    value0 = cl_float(2, ecl_make_long_float(v4), T0);
    return value0;
   }
L5:;
   value0 = L3complex_acosh(v2x);
   return value0;
  }
 }
}
/*	function definition for COMPLEX-ACOSH                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3complex_acosh(cl_object v1z)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   cl_object v3;
   T0 = ecl_minus(v1z,ecl_make_fixnum(1));
   v2 = ecl_sqrt(T0);
   T0 = ecl_plus(v1z,ecl_make_fixnum(1));
   v3 = ecl_sqrt(T0);
   T0 = cl_conjugate(v2);
   T1 = ecl_times(T0,v3);
   T2 = cl_realpart(T1);
   T3 = cl_asinh(T2);
   T4 = cl_imagpart(v2);
   T5 = cl_realpart(v3);
   T6 = cl_atan(2, T4, T5);
   T7 = ecl_times(ecl_make_fixnum(2),T6);
   value0 = cl_complex(2, T3, T7);
   return value0;
  }
 }
}
/*	function definition for ATANH                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_atanh(cl_object v1x)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_complexp(v1x))) { goto L1; }
  value0 = L4complex_atanh(v1x);
  return value0;
L1:;
  {
   cl_object v2x;
   double v3xr;
   v2x = cl_float(1, v1x);
   v3xr = ecl_to_double(v2x);
   if (!(((float)  -1.0    )<=(v3xr))) { goto L5; }
   if (!((v3xr)<=((float)   1.0    ))) { goto L5; }
   {
    long double v4;
    v4 = atanhl((long double)(v3xr));
    T0 = cl_float(1, v2x);
    value0 = cl_float(2, ecl_make_long_float(v4), T0);
    return value0;
   }
L5:;
   value0 = L4complex_atanh(v2x);
   return value0;
  }
 }
}
/*	function definition for COMPLEX-ATANH                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4complex_atanh(cl_object v1z)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_one_plus(v1z);
  T1 = cl_log(1, T0);
  T2 = ecl_minus(ecl_make_fixnum(1),v1z);
  T3 = cl_log(1, T2);
  T4 = ecl_minus(T1,T3);
  value0 = ecl_divide(T4,ecl_make_fixnum(2));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for FFLOOR                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_ffloor(cl_narg narg, cl_object v1x, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2y;
  va_list args; va_start(args,v1x);
  {
   int i = 1;
   if (i >= narg) {
    v2y = ecl_make_fixnum(1);
   } else {
    i++;
    v2y = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v4;                                  /*  I               */
   cl_object v5;                                  /*  R               */
   value0 = ecl_floor2(v1x,v2y);
   v4 = value0;
   v5 = cl_env_copy->values[1];
   if (!(floatp(v5))) { goto L4; }
   T0 = cl_float(2, v4, v5);
   goto L3;
L4:;
   T0 = cl_float(1, v4);
L3:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for FCEILING                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_fceiling(cl_narg narg, cl_object v1x, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2y;
  va_list args; va_start(args,v1x);
  {
   int i = 1;
   if (i >= narg) {
    v2y = _ecl_static_9;
   } else {
    i++;
    v2y = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v4;                                  /*  I               */
   cl_object v5;                                  /*  R               */
   value0 = ecl_ceiling2(v1x,v2y);
   v4 = value0;
   v5 = cl_env_copy->values[1];
   if (!(floatp(v5))) { goto L4; }
   T0 = cl_float(2, v4, v5);
   goto L3;
L4:;
   T0 = cl_float(1, v4);
L3:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for FTRUNCATE                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_ftruncate(cl_narg narg, cl_object v1x, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2y;
  va_list args; va_start(args,v1x);
  {
   int i = 1;
   if (i >= narg) {
    v2y = _ecl_static_9;
   } else {
    i++;
    v2y = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v4;                                  /*  I               */
   cl_object v5;                                  /*  R               */
   value0 = ecl_truncate2(v1x,v2y);
   v4 = value0;
   v5 = cl_env_copy->values[1];
   if (!(floatp(v5))) { goto L4; }
   T0 = cl_float(2, v4, v5);
   goto L3;
L4:;
   T0 = cl_float(1, v4);
L3:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for FROUND                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_fround(cl_narg narg, cl_object v1x, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2y;
  va_list args; va_start(args,v1x);
  {
   int i = 1;
   if (i >= narg) {
    v2y = _ecl_static_9;
   } else {
    i++;
    v2y = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v4;                                  /*  I               */
   cl_object v5;                                  /*  R               */
   value0 = ecl_round2(v1x,v2y);
   v4 = value0;
   v5 = cl_env_copy->values[1];
   if (!(floatp(v5))) { goto L4; }
   T0 = cl_float(2, v4, v5);
   goto L3;
L4:;
   T0 = cl_float(1, v4);
L3:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for LOGTEST                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_logtest(cl_object v1x, cl_object v2y)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_boole(ECL_BOOLAND,(v1x),(v2y));
  {
   bool v3;
   v3 = ecl_zerop(T0);
   value0 = (v3)?ECL_NIL:ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for BYTE                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_byte(cl_object v1size, cl_object v2position)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = CONS(v1size,v2position);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for BYTE-SIZE                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_byte_size(cl_object v1bytespec)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_car(v1bytespec);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for BYTE-POSITION                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_byte_position(cl_object v1bytespec)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_cdr(v1bytespec);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for LDB                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_ldb(cl_object v1bytespec, cl_object v2integer)
{
 cl_object T0, T1, T2, T3, T4, T5;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_byte_position(v1bytespec);
  T1 = ecl_negate(T0);
  T2 = cl_ash(v2integer, T1);
  T3 = cl_byte_size(v1bytespec);
  T4 = cl_ash(ecl_make_fixnum(1), T3);
  T5 = ecl_negate(T4);
  value0 = ecl_boole(ECL_BOOLANDC2,(T2),(T5));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for LDB-TEST                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_ldb_test(cl_object v1bytespec, cl_object v2integer)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_ldb(v1bytespec, v2integer);
  {
   bool v3;
   v3 = ecl_zerop(T0);
   value0 = (v3)?ECL_NIL:ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for MASK-FIELD                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_mask_field(cl_object v1bytespec, cl_object v2integer)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_ldb(v1bytespec, v2integer);
  T1 = cl_byte_position(v1bytespec);
  value0 = cl_ash(T0, T1);
  return value0;
 }
}
/*	function definition for DPB                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_dpb(cl_object v1newbyte, cl_object v2bytespec, cl_object v3integer)
{
 cl_object T0, T1, T2, T3, T4, T5, T6;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_mask_field(v2bytespec, v3integer);
  T1 = cl_byte_size(v2bytespec);
  T2 = cl_ash(ecl_make_fixnum(1), T1);
  T3 = ecl_negate(T2);
  T4 = ecl_boole(ECL_BOOLANDC2,(v1newbyte),(T3));
  T5 = cl_byte_position(v2bytespec);
  T6 = cl_ash(T4, T5);
  value0 = cl_logxor(3, v3integer, T0, T6);
  return value0;
 }
}
/*	function definition for DEPOSIT-FIELD                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_deposit_field(cl_object v1newbyte, cl_object v2bytespec, cl_object v3integer)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_byte_position(v2bytespec);
  T1 = ecl_negate(T0);
  T2 = cl_ash(v1newbyte, T1);
  value0 = cl_dpb(T2, v2bytespec, v3integer);
  return value0;
 }
}

#include "lsp/numlib.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclOnKdKvcLXteh9_mXw9ZE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:LSP;NUMLIB.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclOnKdKvcLXteh9_mXw9ZE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 si_Xmake_constant(ECL_SYM("SHORT-FLOAT-EPSILON",757), _ecl_static_1);
 si_Xmake_constant(ECL_SYM("SINGLE-FLOAT-EPSILON",779), _ecl_static_1);
 si_Xmake_constant(ECL_SYM("DOUBLE-FLOAT-EPSILON",316), _ecl_static_2);
 si_Xmake_constant(ECL_SYM("LONG-FLOAT-EPSILON",509), _ecl_static_3);
 si_Xmake_constant(ECL_SYM("SHORT-FLOAT-NEGATIVE-EPSILON",758), _ecl_static_4);
 si_Xmake_constant(ECL_SYM("SINGLE-FLOAT-NEGATIVE-EPSILON",780), _ecl_static_4);
 si_Xmake_constant(ECL_SYM("DOUBLE-FLOAT-NEGATIVE-EPSILON",317), _ecl_static_5);
 si_Xmake_constant(ECL_SYM("LONG-FLOAT-NEGATIVE-EPSILON",510), _ecl_static_6);
 {
  cl_object T0;
 {
  cl_object v1bits;
  v1bits = si_trap_fpe(ECL_SYM("LAST",455), ECL_NIL);
  {
   cl_object v2a;
   {
    float v3;
    v3 = ecl_to_float(ecl_make_fixnum(1));
    {
     float v4;
     v4 = (float)    0.    ;
     v2a = ecl_divide(ecl_make_single_float(v3),ecl_make_single_float(v4));
    }
   }
   si_Xmake_constant(ECL_SYM("SHORT-FLOAT-POSITIVE-INFINITY",1706), v2a);
   T0 = (cl_env_copy->function=(ECL_SYM("-",17)->symbol.gfdef))->cfun.entry(1, v2a) /*  - */;
   si_Xmake_constant(ECL_SYM("SHORT-FLOAT-NEGATIVE-INFINITY",1710), T0);
  }
  {
   cl_object v2a;
   {
    float v3;
    v3 = ecl_to_float(ecl_make_fixnum(1));
    {
     float v4;
     v4 = (float)    0.    ;
     v2a = ecl_divide(ecl_make_single_float(v3),ecl_make_single_float(v4));
    }
   }
   si_Xmake_constant(ECL_SYM("SINGLE-FLOAT-POSITIVE-INFINITY",1707), v2a);
   T0 = (cl_env_copy->function=(ECL_SYM("-",17)->symbol.gfdef))->cfun.entry(1, v2a) /*  - */;
   si_Xmake_constant(ECL_SYM("SINGLE-FLOAT-NEGATIVE-INFINITY",1711), T0);
  }
  {
   cl_object v2a;
   {
    double v3;
    v3 = ecl_to_double(ecl_make_fixnum(1));
    {
     double v4;
     v4 = ecl_to_double(cl_core.singlefloat_zero);
     v2a = ecl_divide(ecl_make_double_float(v3),ecl_make_double_float(v4));
    }
   }
   si_Xmake_constant(ECL_SYM("DOUBLE-FLOAT-POSITIVE-INFINITY",1708), v2a);
   T0 = (cl_env_copy->function=(ECL_SYM("-",17)->symbol.gfdef))->cfun.entry(1, v2a) /*  - */;
   si_Xmake_constant(ECL_SYM("DOUBLE-FLOAT-NEGATIVE-INFINITY",1712), T0);
  }
  {
   cl_object v2a;
   {
    long double v3;
    v3 = ecl_to_long_double(ecl_make_fixnum(1));
    {
     long double v4;
     v4 = ecl_to_long_double(cl_core.singlefloat_zero);
     v2a = ecl_divide(ecl_make_long_float(v3),ecl_make_long_float(v4));
    }
   }
   si_Xmake_constant(ECL_SYM("LONG-FLOAT-POSITIVE-INFINITY",1709), v2a);
   T0 = (cl_env_copy->function=(ECL_SYM("-",17)->symbol.gfdef))->cfun.entry(1, v2a) /*  - */;
   si_Xmake_constant(ECL_SYM("LONG-FLOAT-NEGATIVE-INFINITY",1713), T0);
  }
  si_trap_fpe(v1bits, ECL_T);
 }
 }
 si_Xmake_constant(VV[0], _ecl_static_7);
 (void)0; /* No entry created for ISQRT */
 (void)0; /* No entry created for PHASE */
 (void)0; /* No entry created for SIGNUM */
 (void)0; /* No entry created for CIS */
 (void)0; /* No entry created for ASIN */
 (void)0; /* No entry created for COMPLEX-ASIN */
 (void)0; /* No entry created for ACOS */
 (void)0; /* No entry created for COMPLEX-ACOS */
 (void)0; /* No entry created for ASINH */
 (void)0; /* No entry created for ACOSH */
 (void)0; /* No entry created for COMPLEX-ACOSH */
 (void)0; /* No entry created for ATANH */
 (void)0; /* No entry created for COMPLEX-ATANH */
 (void)0; /* No entry created for FFLOOR */
 (void)0; /* No entry created for FCEILING */
 (void)0; /* No entry created for FTRUNCATE */
 (void)0; /* No entry created for FROUND */
 (void)0; /* No entry created for LOGTEST */
 (void)0; /* No entry created for BYTE */
 (void)0; /* No entry created for BYTE-SIZE */
 (void)0; /* No entry created for BYTE-POSITION */
 (void)0; /* No entry created for LDB */
 (void)0; /* No entry created for LDB-TEST */
 (void)0; /* No entry created for MASK-FIELD */
 (void)0; /* No entry created for DPB */
 (void)0; /* No entry created for DEPOSIT-FIELD */
}
