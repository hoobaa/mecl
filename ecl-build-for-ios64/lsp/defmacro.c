/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:LSP;DEFMACRO.LSP                                  */
#include <ecl/ecl-cmp.h>
#include "lsp/defmacro.eclh"
/*	function definition for SEARCH-KEYWORD                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_search_keyword(cl_narg narg, cl_object v1list, cl_object v2key, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  if (!(ECL_ATOM(v1list))) { goto L1; }
  value0 = ECL_SYM("MISSING-KEYWORD",1929);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  T0 = ecl_cdr(v1list);
  if (!(ECL_ATOM(T0))) { goto L3; }
  value0 = ECL_SYM("MISSING-KEYWORD",1929);
  cl_env_copy->nvalues = 1;
  return value0;
L3:;
  T0 = ecl_car(v1list);
  if (!((T0)==(v2key))) { goto L5; }
  value0 = ecl_cadr(v1list);
  cl_env_copy->nvalues = 1;
  return value0;
L5:;
  v1list = ecl_cddr(v1list);
  goto TTL;
 }
}
/*	function definition for CHECK-KEYWORD                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_check_keyword(cl_narg narg, cl_object v1tail, cl_object v2keywords, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v3allow_other_keys;
  cl_object v4aok_flag;
  va_list args; va_start(args,v2keywords);
  {
   int i = 2;
   if (i >= narg) {
    v3allow_other_keys = ECL_NIL;
    v4aok_flag = ECL_NIL;
   } else {
    i++;
    v3allow_other_keys = va_arg(args,cl_object);
    v4aok_flag = ECL_T;
   }
  }
  va_end(args);
  {
   cl_object v5head;
   cl_object v6arg;
   cl_object v7err;
   v5head = ECL_NIL;
   v6arg = ECL_NIL;
   v7err = ECL_NIL;
   goto L7;
L6:;
   if (!(ECL_ATOM(v1tail))) { goto L10; }
   cl_error(1, _ecl_static_1);
   goto L9;
L10:;
   v5head = ecl_car(v1tail);
   v1tail = ecl_cdr(v1tail);
L9:;
   if (!(ECL_ATOM(v1tail))) { goto L16; }
   cl_error(1, _ecl_static_1);
   goto L15;
L16:;
   v6arg = ecl_car(v1tail);
   v1tail = ecl_cdr(v1tail);
L15:;
   if (!((v5head)==(ECL_SYM("ALLOW-OTHER-KEYS",1197)))) { goto L22; }
   if ((v4aok_flag)!=ECL_NIL) { goto L21; }
   v3allow_other_keys = v1tail;
   v4aok_flag = ECL_T;
   goto L21;
L22:;
   if ((ecl_memql(v5head,v2keywords))!=ECL_NIL) { goto L21; }
   v7err = v5head;
L21:;
L7:;
   if (v1tail==ECL_NIL) { goto L30; }
   goto L6;
L30:;
   if (Null(v7err)) { goto L32; }
   if ((v3allow_other_keys)!=ECL_NIL) { goto L32; }
   value0 = cl_error(2, _ecl_static_2, v7err);
   return value0;
L32:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for DM-TOO-MANY-ARGUMENTS                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_dm_too_many_arguments(cl_object v1_current_form_)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  ecl_bds_bind(cl_env_copy,ECL_SYM("*CURRENT-FORM*",1612),v1_current_form_); /*  *CURRENT-FORM* */
TTL:
  value0 = cl_error(2, _ecl_static_3, ecl_symbol_value(ECL_SYM("*CURRENT-FORM*",1612)));
  ecl_bds_unwind1(cl_env_copy);
  return value0;
 }
}
/*	function definition for DM-TOO-FEW-ARGUMENTS                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_dm_too_few_arguments(cl_object v1form_or_nil)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1form_or_nil)) { goto L1; }
  ecl_bds_bind(cl_env_copy,ECL_SYM("*CURRENT-FORM*",1612),v1form_or_nil); /*  *CURRENT-FORM* */
  value0 = cl_error(2, _ecl_static_4, ecl_symbol_value(ECL_SYM("*CURRENT-FORM*",1612)));
  ecl_bds_unwind1(cl_env_copy);
  return value0;
L1:;
  value0 = cl_error(1, _ecl_static_5);
  return value0;
 }
}
/*	function definition for DESTRUCTURE                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3destructure(cl_object v1vl, cl_object v2macro)
{