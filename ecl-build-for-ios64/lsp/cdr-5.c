/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:LSP;CDR-5.LSP                                     */
#include <ecl/ecl-cmp.h>
#include "lsp/cdr-5.eclh"
/*	local function NEGATIVE-FIXNUM                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC1negative_fixnum()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_list(3, ECL_SYM("INTEGER",437), ecl_make_fixnum(-536870912), ecl_make_fixnum(-1));
  return value0;
 }
}
/*	local function NON-POSITIVE-FIXNUM                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC2non_positive_fixnum()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_list(3, ECL_SYM("INTEGER",437), ecl_make_fixnum(-536870912), ecl_make_fixnum(0));
  return value0;
 }
}
/*	local function NON-NEGATIVE-FIXNUM                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC3non_negative_fixnum()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_list(3, ECL_SYM("INTEGER",437), ecl_make_fixnum(0), ecl_make_fixnum(536870911));
  return value0;
 }
}
/*	local function POSITIVE-FIXNUM                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC4positive_fixnum()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_list(3, ECL_SYM("INTEGER",437), ecl_make_fixnum(1), ecl_make_fixnum(536870911));
  return value0;
 }
}
/*	function definition for NEGATIVE-FIXNUM-P                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_negative_fixnum_p(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_FIXNUMP(v1p))) { goto L2; }
  value0 = ecl_make_bool((ecl_to_fixnum(v1p))<0);
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for POSITIVE-FIXNUM-P                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_positive_fixnum_p(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_FIXNUMP(v1p))) { goto L2; }
  value0 = ecl_make_bool((ecl_to_fixnum(v1p))>0);
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for NON-NEGATIVE-FIXNUM-P                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_non_negative_fixnum_p(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_FIXNUMP(v1p))) { goto L2; }
  {
   bool v2;
   v2 = (ecl_to_fixnum(v1p))<0;
   value0 = (v2)?ECL_NIL:ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for NON-POSITIVE-FIXNUM-P                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_non_positive_fixnum_p(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_FIXNUMP(v1p))) { goto L2; }
  {
   bool v2;
   v2 = (ecl_to_fixnum(v1p))>0;
   value0 = (v2)?ECL_NIL:ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for ARRAY-INDEX-P                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_array_index_p(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_FIXNUMP(v1p))) { goto L2; }
  value0 = ecl_make_bool(((0)<=(ecl_to_fixnum(v1p)) && (ecl_to_fixnum(v1p))<=(536870911)));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for NEGATIVE-INTEGER-P                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_negative_integer_p(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_FIXNUMP(v1p)||ECL_BIGNUMP(v1p))) { goto L2; }
  value0 = ecl_make_bool(ecl_minusp(v1p));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for POSITIVE-INTEGER-P                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_positive_integer_p(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_FIXNUMP(v1p)||ECL_BIGNUMP(v1p))) { goto L2; }
  value0 = ecl_make_bool(ecl_plusp(v1p));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for NON-NEGATIVE-INTEGER-P                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_non_negative_integer_p(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_FIXNUMP(v1p)||ECL_BIGNUMP(v1p))) { goto L2; }
  {
   bool v2;
   v2 = ecl_minusp(v1p);
   value0 = (v2)?ECL_NIL:ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for NON-POSITIVE-INTEGER-P                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_non_positive_integer_p(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_FIXNUMP(v1p)||ECL_BIGNUMP(v1p))) { goto L2; }
  {
   bool v2;
   v2 = ecl_plusp(v1p);
   value0 = (v2)?ECL_NIL:ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for NEGATIVE-RATIONAL-P                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_negative_rational_p(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_rationalp(v1p))) { goto L2; }
  value0 = ecl_make_bool(ecl_minusp(v1p));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for POSITIVE-RATIONAL-P                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_positive_rational_p(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_rationalp(v1p))) { goto L2; }
  value0 = ecl_make_bool(ecl_plusp(v1p));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for NON-NEGATIVE-RATIONAL-P               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_non_negative_rational_p(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_rationalp(v1p))) { goto L2; }
  {
   bool v2;
   v2 = ecl_minusp(v1p);
   value0 = (v2)?ECL_NIL:ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for NON-POSITIVE-RATIONAL-P               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_non_positive_rational_p(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_rationalp(v1p))) { goto L2; }
  {
   bool v2;
   v2 = ecl_plusp(v1p);
   value0 = (v2)?ECL_NIL:ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for RATIOP                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5ratiop(cl_object v1x)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_type_of(v1x);
  value0 = ecl_make_bool((T0)==(ECL_SYM("RATIO",686)));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for POSITIVE-RATIO-P                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_positive_ratio_p(cl_object v1x)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(L5ratiop(v1x))) { goto L2; }
  value0 = ecl_make_bool(ecl_plusp(v1x));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for NEGATIVE-RATIO-P                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_negative_ratio_p(cl_object v1x)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(L5ratiop(v1x))) { goto L2; }
  value0 = ecl_make_bool(ecl_minusp(v1x));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for NON-NEGATIVE-RATIO-P                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_non_negative_ratio_p(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = si_positive_ratio_p(v1p);
  return value0;
 }
}
/*	function definition for NON-POSITIVE-RATIO-P                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_non_positive_ratio_p(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = si_negative_ratio_p(v1p);
  return value0;
 }
}
/*	function definition for NEGATIVE-REAL-P                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_negative_real_p(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_realp(v1p))) { goto L2; }
  value0 = ecl_make_bool(ecl_minusp(v1p));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for POSITIVE-REAL-P                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_positive_real_p(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_realp(v1p))) { goto L2; }
  value0 = ecl_make_bool(ecl_plusp(v1p));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for NON-NEGATIVE-REAL-P                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_non_negative_real_p(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_realp(v1p))) { goto L2; }
  {
   bool v2;
   v2 = ecl_minusp(v1p);
   value0 = (v2)?ECL_NIL:ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for NON-POSITIVE-REAL-P                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_non_positive_real_p(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_realp(v1p))) { goto L2; }
  {
   bool v2;
   v2 = ecl_plusp(v1p);
   value0 = (v2)?ECL_NIL:ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for NEGATIVE-FLOAT-P                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_negative_float_p(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(floatp(v1p))) { goto L2; }
  value0 = ecl_make_bool(ecl_minusp(v1p));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for POSITIVE-FLOAT-P                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_positive_float_p(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(floatp(v1p))) { goto L2; }
  value0 = ecl_make_bool(ecl_plusp(v1p));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for NON-NEGATIVE-FLOAT-P                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_non_negative_float_p(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(floatp(v1p))) { goto L2; }
  {
   bool v2;
   v2 = ecl_minusp(v1p);
   value0 = (v2)?ECL_NIL:ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for NON-POSITIVE-FLOAT-P                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_non_positive_float_p(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(floatp(v1p))) { goto L2; }
  {
   bool v2;
   v2 = ecl_plusp(v1p);
   value0 = (v2)?ECL_NIL:ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for NEGATIVE-SHORT-FLOAT-P                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_negative_short_float_p(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[2])(1, v1p) /*  SHORT-FLOATP */)) { goto L2; }
  value0 = ecl_make_bool((ecl_to_float(v1p))<0);
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for POSITIVE-SHORT-FLOAT-P                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_positive_short_float_p(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[2])(1, v1p) /*  SHORT-FLOATP */)) { goto L2; }
  value0 = ecl_make_bool((ecl_to_float(v1p))>0);
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for NON-NEGATIVE-SHORT-FLOAT-P            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_non_negative_short_float_p(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[2])(1, v1p) /*  SHORT-FLOATP */)) { goto L2; }
  {
   bool v2;
   v2 = (ecl_to_float(v1p))<0;
   value0 = (v2)?ECL_NIL:ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for NON-POSITIVE-SHORT-FLOAT-P            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_non_positive_short_float_p(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[2])(1, v1p) /*  SHORT-FLOATP */)) { goto L2; }
  {
   bool v2;
   v2 = (ecl_to_float(v1p))>0;
   value0 = (v2)?ECL_NIL:ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for NEGATIVE-SINGLE-FLOAT-P               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_negative_single_float_p(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[3])(1, v1p) /*  SINGLE-FLOATP */)) { goto L2; }
  value0 = ecl_make_bool((ecl_to_float(v1p))<0);
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for POSITIVE-SINGLE-FLOAT-P               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_positive_single_float_p(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[3])(1, v1p) /*  SINGLE-FLOATP */)) { goto L2; }
  value0 = ecl_make_bool((ecl_to_float(v1p))>0);
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for NON-NEGATIVE-SINGLE-FLOAT-P           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_non_negative_single_float_p(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[3])(1, v1p) /*  SINGLE-FLOATP */)) { goto L2; }
  {
   bool v2;
   v2 = (ecl_to_float(v1p))<0;
   value0 = (v2)?ECL_NIL:ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for NON-POSITIVE-SINGLE-FLOAT-P           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_non_positive_single_float_p(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[3])(1, v1p) /*  SINGLE-FLOATP */)) { goto L2; }
  {
   bool v2;
   v2 = (ecl_to_float(v1p))>0;
   value0 = (v2)?ECL_NIL:ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for NEGATIVE-DOUBLE-FLOAT-P               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_negative_double_float_p(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[4])(1, v1p) /*  DOUBLE-FLOATP */)) { goto L2; }
  value0 = ecl_make_bool((ecl_to_double(v1p))<0);
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for POSITIVE-DOUBLE-FLOAT-P               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_positive_double_float_p(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[4])(1, v1p) /*  DOUBLE-FLOATP */)) { goto L2; }
  value0 = ecl_make_bool((ecl_to_double(v1p))>0);
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for NON-NEGATIVE-DOUBLE-FLOAT-P           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_non_negative_double_float_p(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[4])(1, v1p) /*  DOUBLE-FLOATP */)) { goto L2; }
  {
   bool v2;
   v2 = (ecl_to_double(v1p))<0;
   value0 = (v2)?ECL_NIL:ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for NON-POSITIVE-DOUBLE-FLOAT-P           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_non_positive_double_float_p(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[4])(1, v1p) /*  DOUBLE-FLOATP */)) { goto L2; }
  {
   bool v2;
   v2 = (ecl_to_double(v1p))>0;
   value0 = (v2)?ECL_NIL:ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for NEGATIVE-LONG-FLOAT-P                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_negative_long_float_p(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[5])(1, v1p) /*  LONG-FLOATP */)) { goto L2; }
  value0 = ecl_make_bool((ecl_to_double(v1p))<0);
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for POSITIVE-LONG-FLOAT-P                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_positive_long_float_p(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[5])(1, v1p) /*  LONG-FLOATP */)) { goto L2; }
  value0 = ecl_make_bool((ecl_to_double(v1p))>0);
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for NON-NEGATIVE-LONG-FLOAT-P             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_non_negative_long_float_p(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[5])(1, v1p) /*  LONG-FLOATP */)) { goto L2; }
  {
   bool v2;
   v2 = (ecl_to_double(v1p))<0;
   value0 = (v2)?ECL_NIL:ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for NON-POSITIVE-LONG-FLOAT-P             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_non_positive_long_float_p(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[5])(1, v1p) /*  LONG-FLOATP */)) { goto L2; }
  {
   bool v2;
   v2 = (ecl_to_double(v1p))>0;
   value0 = (v2)?ECL_NIL:ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}

#include "lsp/cdr-5.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclzUToeBa7_WX8xWE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:LSP;CDR-5.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclzUToeBa7_WX8xWE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC1negative_fixnum,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 si_do_deftype(3, ECL_SYM("NEGATIVE-FIXNUM",1844), VVtemp[0], T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC2non_positive_fixnum,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 si_do_deftype(3, ECL_SYM("NON-POSITIVE-FIXNUM",1846), VVtemp[1], T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC3non_negative_fixnum,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 si_do_deftype(3, ECL_SYM("NON-NEGATIVE-FIXNUM",1845), VVtemp[2], T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC4positive_fixnum,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 si_do_deftype(3, ECL_SYM("POSITIVE-FIXNUM",1847), VVtemp[3], T0);
 }
 (void)0; /* No entry created for NEGATIVE-FIXNUM-P */
 (void)0; /* No entry created for POSITIVE-FIXNUM-P */
 (void)0; /* No entry created for NON-NEGATIVE-FIXNUM-P */
 (void)0; /* No entry created for NON-POSITIVE-FIXNUM-P */
 (void)0; /* No entry created for ARRAY-INDEX-P */
 si_do_deftype(3, ECL_SYM("NEGATIVE-INTEGER",1852), VVtemp[4], VVtemp[5]);
 si_do_deftype(3, ECL_SYM("NON-POSITIVE-INTEGER",1854), VVtemp[6], VVtemp[7]);
 si_do_deftype(3, ECL_SYM("NON-NEGATIVE-INTEGER",1853), VVtemp[8], VVtemp[9]);
 si_do_deftype(3, ECL_SYM("POSITIVE-INTEGER",1855), VVtemp[10], VVtemp[11]);
 (void)0; /* No entry created for NEGATIVE-INTEGER-P */
 (void)0; /* No entry created for POSITIVE-INTEGER-P */
 (void)0; /* No entry created for NON-NEGATIVE-INTEGER-P */
 (void)0; /* No entry created for NON-POSITIVE-INTEGER-P */
 si_do_deftype(3, ECL_SYM("NEGATIVE-RATIONAL",1860), VVtemp[12], VVtemp[13]);
 si_do_deftype(3, ECL_SYM("NON-POSITIVE-RATIONAL",1862), VVtemp[14], VVtemp[15]);
 si_do_deftype(3, ECL_SYM("NON-NEGATIVE-RATIONAL",1861), VVtemp[16], VVtemp[17]);
 si_do_deftype(3, ECL_SYM("POSITIVE-RATIONAL",1863), VVtemp[18], VVtemp[19]);
 (void)0; /* No entry created for NEGATIVE-RATIONAL-P */
 (void)0; /* No entry created for POSITIVE-RATIONAL-P */
 (void)0; /* No entry created for NON-NEGATIVE-RATIONAL-P */
 (void)0; /* No entry created for NON-POSITIVE-RATIONAL-P */
 ecl_cmp_defun(VV[1]);                            /*  RATIOP          */
 (void)0; /* No entry created for POSITIVE-RATIO-P */
 (void)0; /* No entry created for NEGATIVE-RATIO-P */
 si_do_deftype(3, ECL_SYM("NEGATIVE-RATIO",1868), VVtemp[20], VVtemp[21]);
 si_do_deftype(3, ECL_SYM("NON-POSITIVE-RATIO",1870), VVtemp[22], ECL_SYM("NEGATIVE-RATIO",1868));
 si_do_deftype(3, ECL_SYM("NON-NEGATIVE-RATIO",1869), VVtemp[23], ECL_SYM("POSITIVE-RATIO",1871));
 si_do_deftype(3, ECL_SYM("POSITIVE-RATIO",1871), VVtemp[24], VVtemp[25]);
 (void)0; /* No entry created for NON-NEGATIVE-RATIO-P */
 (void)0; /* No entry created for NON-POSITIVE-RATIO-P */
 si_do_deftype(3, ECL_SYM("NEGATIVE-REAL",1876), VVtemp[26], VVtemp[27]);
 si_do_deftype(3, ECL_SYM("NON-POSITIVE-REAL",1878), VVtemp[28], VVtemp[29]);
 si_do_deftype(3, ECL_SYM("NON-NEGATIVE-REAL",1877), VVtemp[30], VVtemp[31]);
 si_do_deftype(3, ECL_SYM("POSITIVE-REAL",1879), VVtemp[32], VVtemp[33]);
 (void)0; /* No entry created for NEGATIVE-REAL-P */
 (void)0; /* No entry created for POSITIVE-REAL-P */
 (void)0; /* No entry created for NON-NEGATIVE-REAL-P */
 (void)0; /* No entry created for NON-POSITIVE-REAL-P */
 si_do_deftype(3, ECL_SYM("NEGATIVE-FLOAT",1884), VVtemp[34], VVtemp[35]);
 si_do_deftype(3, ECL_SYM("NON-POSITIVE-FLOAT",1886), VVtemp[36], VVtemp[37]);
 si_do_deftype(3, ECL_SYM("NON-NEGATIVE-FLOAT",1885), VVtemp[38], VVtemp[39]);
 si_do_deftype(3, ECL_SYM("POSITIVE-FLOAT",1887), VVtemp[40], VVtemp[41]);
 (void)0; /* No entry created for NEGATIVE-FLOAT-P */
 (void)0; /* No entry created for POSITIVE-FLOAT-P */
 (void)0; /* No entry created for NON-NEGATIVE-FLOAT-P */
 (void)0; /* No entry created for NON-POSITIVE-FLOAT-P */
 si_do_deftype(3, ECL_SYM("NEGATIVE-SHORT-FLOAT",1892), VVtemp[42], VVtemp[43]);
 si_do_deftype(3, ECL_SYM("NON-POSITIVE-SHORT-FLOAT",1894), VVtemp[44], VVtemp[45]);
 si_do_deftype(3, ECL_SYM("NON-NEGATIVE-SHORT-FLOAT",1893), VVtemp[46], VVtemp[47]);
 si_do_deftype(3, ECL_SYM("POSITIVE-SHORT-FLOAT",1895), VVtemp[48], VVtemp[49]);
 (void)0; /* No entry created for NEGATIVE-SHORT-FLOAT-P */
 (void)0; /* No entry created for POSITIVE-SHORT-FLOAT-P */
 (void)0; /* No entry created for NON-NEGATIVE-SHORT-FLOAT-P */
 (void)0; /* No entry created for NON-POSITIVE-SHORT-FLOAT-P */
 si_do_deftype(3, ECL_SYM("NEGATIVE-SINGLE-FLOAT",1900), VVtemp[50], VVtemp[51]);
 si_do_deftype(3, ECL_SYM("NON-POSITIVE-SINGLE-FLOAT",1902), VVtemp[52], VVtemp[53]);
 si_do_deftype(3, ECL_SYM("NON-NEGATIVE-SINGLE-FLOAT",1901), VVtemp[54], VVtemp[55]);
 si_do_deftype(3, ECL_SYM("POSITIVE-SINGLE-FLOAT",1903), VVtemp[56], VVtemp[57]);
 (void)0; /* No entry created for NEGATIVE-SINGLE-FLOAT-P */
 (void)0; /* No entry created for POSITIVE-SINGLE-FLOAT-P */
 (void)0; /* No entry created for NON-NEGATIVE-SINGLE-FLOAT-P */
 (void)0; /* No entry created for NON-POSITIVE-SINGLE-FLOAT-P */
 si_do_deftype(3, ECL_SYM("NEGATIVE-DOUBLE-FLOAT",1908), VVtemp[58], VVtemp[59]);
 si_do_deftype(3, ECL_SYM("NON-POSITIVE-DOUBLE-FLOAT",1910), VVtemp[60], VVtemp[61]);
 si_do_deftype(3, ECL_SYM("NON-NEGATIVE-DOUBLE-FLOAT",1909), VVtemp[62], VVtemp[63]);
 si_do_deftype(3, ECL_SYM("POSITIVE-DOUBLE-FLOAT",1911), VVtemp[64], VVtemp[65]);
 (void)0; /* No entry created for NEGATIVE-DOUBLE-FLOAT-P */
 (void)0; /* No entry created for POSITIVE-DOUBLE-FLOAT-P */
 (void)0; /* No entry created for NON-NEGATIVE-DOUBLE-FLOAT-P */
 (void)0; /* No entry created for NON-POSITIVE-DOUBLE-FLOAT-P */
 si_do_deftype(3, ECL_SYM("NEGATIVE-LONG-FLOAT",1916), VVtemp[66], VVtemp[67]);
 si_do_deftype(3, ECL_SYM("NON-POSITIVE-LONG-FLOAT",1918), VVtemp[68], VVtemp[69]);
 si_do_deftype(3, ECL_SYM("NON-NEGATIVE-LONG-FLOAT",1917), VVtemp[70], VVtemp[71]);
 si_do_deftype(3, ECL_SYM("POSITIVE-LONG-FLOAT",1919), VVtemp[72], VVtemp[73]);
 (void)0; /* No entry created for NEGATIVE-LONG-FLOAT-P */
 (void)0; /* No entry created for POSITIVE-LONG-FLOAT-P */
 (void)0; /* No entry created for NON-NEGATIVE-LONG-FLOAT-P */
 (void)0; /* No entry created for NON-POSITIVE-LONG-FLOAT-P */
}
