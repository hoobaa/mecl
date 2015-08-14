/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPEVAL.LSP                                   */
#include <ecl/ecl-cmp.h>
#include "cmp/cmpeval.eclh"
/*	function definition for C1EXPR-INNER                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1c1expr_inner(cl_object v1form)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_SYMBOLP(v1form))) { goto L1; }
  v1form = ecl_function_dispatch(cl_env_copy,VV[45])(1, v1form) /*  CHK-SYMBOL-MACROLET */;
  if (ECL_SYMBOLP(v1form)) { goto L5; }
  value0 = v1form;
  cl_env_copy->nvalues = 1;
  return value0;
L5:;
  if (!((v1form)==(ECL_NIL))) { goto L7; }
  value0 = L3c1nil();
  return value0;
L7:;
  if (!((v1form)==(ECL_T))) { goto L9; }
  value0 = L4c1t();
  return value0;
L9:;
  if (Null(cl_keywordp(v1form))) { goto L11; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[46])(1, v1form) /*  OBJECT-TYPE */;
  T1 = ecl_function_dispatch(cl_env_copy,VV[47])(1, v1form) /*  ADD-SYMBOL */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[48])(5, ECL_SYM("LOCATION",1763), ECL_SYM("TYPE",1318), T0, VV[0], T1) /*  MAKE-C1FORM* */;
  return value0;
L11:;
  if (Null(cl_constantp(1, v1form))) { goto L13; }
  T0 = cl_symbol_value(v1form);
  value0 = ecl_function_dispatch(cl_env_copy,VV[49])(3, T0, VV[1], ECL_T) /*  C1CONSTANT-VALUE */;
  if ((value0)!=ECL_NIL) { goto L16; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[50])(1, v1form) /*  C1VAR */;
  return value0;
L16:;
  cl_env_copy->nvalues = 1;
  return value0;
L13:;
  value0 = ecl_function_dispatch(cl_env_copy,VV[50])(1, v1form) /*  C1VAR */;
  return value0;
L1:;
  if (!(ECL_CONSP(v1form))) { goto L18; }
  if ((si_proper_list_p(v1form))!=ECL_NIL) { goto L20; }
  ecl_function_dispatch(cl_env_copy,VV[51])(2, _ecl_static_1, v1form) /*  CMPERR */;
L20:;
  {
   cl_object v2fun;
   v2fun = ecl_car(v1form);
   {
    cl_object v3fd;
    v3fd = ecl_gethash_safe(v2fun,ecl_symbol_value(VV[2]),ECL_NIL);
    if (Null(v3fd)) { goto L23; }
    v2fun = v3fd;
    if (Null(v2fun)) { goto L23; }
   }
   T0 = ecl_cdr(v1form);
   value0 = ecl_function_dispatch(cl_env_copy,v2fun)(1, T0);
   return value0;
L23:;
   if (!(ECL_SYMBOLP(v2fun))) { goto L28; }
   T0 = ecl_cdr(v1form);
   value0 = L5c1call(v2fun, T0, ECL_T);
   return value0;
L28:;
   if (!(ECL_CONSP(v2fun))) { goto L30; }
   T0 = ecl_car(v2fun);
   if (!((T0)==(ECL_SYM("LAMBDA",452)))) { goto L30; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[52])(1, v1form) /*  C1FUNCALL */;
   return value0;
L30:;
   value0 = ecl_function_dispatch(cl_env_copy,VV[51])(2, _ecl_static_2, v2fun) /*  CMPERR */;
   return value0;
  }
L18:;
  value0 = ecl_function_dispatch(cl_env_copy,VV[49])(3, v1form, VV[3], ECL_T) /*  C1CONSTANT-VALUE */;
  return value0;
 }
}
/*	function definition for C1EXPR                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2c1expr(cl_object v1form)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_bds_bind(cl_env_copy,VV[4],v1form);         /*  *CURRENT-FORM*  */
L1:;
  v1form = L1c1expr_inner(v1form);
  if (Null(ecl_function_dispatch(cl_env_copy,VV[54])(1, v1form) /*  C1FORM-P */)) { goto L2; }
  value0 = v1form;
  cl_env_copy->nvalues = 1;
  ecl_bds_unwind1(cl_env_copy);
  return value0;
L2:;
  goto L1;
 }
}
/*	function definition for C1NIL                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3c1nil()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_symbol_value(VV[6]);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for C1T                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4c1t()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_symbol_value(VV[8]);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for C1CALL                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5c1call(cl_object v1fname, cl_object v2args, cl_object v3macros_allowed)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4fd;
   cl_object v5success;
   cl_object v6can_inline;
   v4fd = ECL_NIL;
   v5success = ECL_NIL;
   v6can_inline = ECL_NIL;
   {
    cl_fixnum v7;
    v7 = ecl_length(v2args);
    if (!((v7)>(63))) { goto L4; }
   }
   if (Null(v3macros_allowed)) { goto L6; }
   v4fd = ecl_function_dispatch(cl_env_copy,VV[58])(1, v1fname) /*  CMP-MACRO-FUNCTION */;
   if (Null(v4fd)) { goto L6; }
   T0 = CONS(v1fname,v2args);
   value0 = ecl_function_dispatch(cl_env_copy,VV[59])(2, v4fd, T0) /*  CMP-EXPAND-MACRO */;
   return value0;
L6:;
   T0 = cl_list(2, ECL_SYM("FUNCTION",396), v1fname);
   value0 = ecl_function_dispatch(cl_env_copy,VV[60])(2, T0, v2args) /*  UNOPTIMIZED-LONG-CALL */;
   return value0;
L4:;
   v4fd = ecl_function_dispatch(cl_env_copy,VV[61])(1, v1fname) /*  LOCAL-FUNCTION-REF */;
   if (Null(v4fd)) { goto L10; }
   value0 = L6c1call_local(v1fname, v4fd, v2args);
   return value0;
L10:;
   v6can_inline = ecl_function_dispatch(cl_env_copy,VV[62])(1, v1fname) /*  INLINE-POSSIBLE */;
   if (Null(v6can_inline)) { goto L13; }
   v4fd = (cl_env_copy->function=(ECL_SYM("COMPILER-MACRO-FUNCTION",239)->symbol.gfdef))->cfun.entry(1, v1fname) /*  COMPILER-MACRO-FUNCTION */;
   if (Null(v4fd)) { goto L13; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[63])(3, v4fd, v1fname, v2args) /*  CMP-EXPAND-COMPILER-MACRO */;
   v4fd = value0;
   {
    const int v7 = cl_env_copy->nvalues;
    cl_object v8;
    v8 = (v7<=1)? ECL_NIL : cl_env_copy->values[1];
    v5success = v8;
   }
   if (Null(v5success)) { goto L13; }
   value0 = v4fd;
   cl_env_copy->nvalues = 1;
   return value0;
L13:;
   if (Null(v6can_inline)) { goto L21; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[64])(2, v1fname, v2args) /*  CLOS-COMPILER-MACRO-EXPAND */;
   v4fd = value0;
   {
    const int v7 = cl_env_copy->nvalues;
    cl_object v8;
    v8 = (v7<=1)? ECL_NIL : cl_env_copy->values[1];
    v5success = v8;
   }
   if (Null(v5success)) { goto L21; }
   value0 = v4fd;
   cl_env_copy->nvalues = 1;
   return value0;
L21:;
   if (Null(v3macros_allowed)) { goto L26; }
   v4fd = ecl_function_dispatch(cl_env_copy,VV[58])(1, v1fname) /*  CMP-MACRO-FUNCTION */;
   if (Null(v4fd)) { goto L26; }
   T0 = CONS(v1fname,v2args);
   value0 = ecl_function_dispatch(cl_env_copy,VV[59])(2, v4fd, T0) /*  CMP-EXPAND-MACRO */;
   return value0;
L26:;
   v6can_inline = ecl_function_dispatch(cl_env_copy,VV[65])(1, v1fname) /*  DECLARED-INLINE-P */;
   if (Null(v6can_inline)) { goto L30; }
   if (!(ECL_CONSP(v6can_inline))) { goto L30; }
   T0 = ecl_car(v6can_inline);
   if (!((T0)==(ECL_SYM("FUNCTION",396)))) { goto L30; }
   if (!(ecl_plusp(ecl_symbol_value(VV[10])))) { goto L30; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[66])(1, ECL_SYM("SPACE",788)) /*  CMP-ENV-OPTIMIZATION */;
   if (!(ecl_number_compare(T0,ecl_make_fixnum(1))<=0)) { goto L30; }
   T0 = ecl_one_minus(ecl_symbol_value(VV[10]));
   ecl_bds_bind(cl_env_copy,VV[10],T0);           /*  *INLINE-MAX-DEPTH* */
   ecl_function_dispatch(cl_env_copy,VV[67])(2, _ecl_static_3, v1fname) /*  CMPNOTE */;
   value0 = cl_listX(3, ECL_SYM("FUNCALL",394), v6can_inline, v2args);
   ecl_bds_unwind1(cl_env_copy);
   return value0;
L30:;
   value0 = L7c1call_global(v1fname, v2args);
   return value0;
  }
 }
}
/*	function definition for C1CALL-LOCAL                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6c1call_local(cl_object v1fname, cl_object v2fun, cl_object v3args)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4lambda;
   v4lambda = ecl_function_dispatch(cl_env_copy,VV[68])(1, v2fun) /*  FUN-LAMBDA-EXPRESSION */;
   if (Null(v4lambda)) { goto L1; }
   if (Null(ecl_function_dispatch(cl_env_copy,VV[65])(1, v1fname) /*  DECLARED-INLINE-P */)) { goto L1; }
   if (!(ecl_plusp(ecl_symbol_value(VV[10])))) { goto L1; }
   T0 = ecl_one_minus(ecl_symbol_value(VV[10]));
   ecl_bds_bind(cl_env_copy,VV[10],T0);           /*  *INLINE-MAX-DEPTH* */
   T0 = cl_list(2, ECL_SYM("FUNCTION",396), v4lambda);
   value0 = cl_listX(3, ECL_SYM("FUNCALL",394), T0, v3args);
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
L1:;
  {
   cl_object v4forms;
   cl_object v5return_type;
   cl_object v6arg_types;
   v4forms = L15c1args_(v3args);
   value0 = ecl_function_dispatch(cl_env_copy,VV[69])(1, v2fun) /*  GET-LOCAL-RETURN-TYPE */;
   if ((value0)!=ECL_NIL) { goto L9; }
   v5return_type = ECL_T;
   goto L7;
L9:;
   v5return_type = value0;
   goto L7;
L7:;
   v6arg_types = ecl_function_dispatch(cl_env_copy,VV[70])(1, v2fun) /*  GET-LOCAL-ARG-TYPES */;
   if (Null(v6arg_types)) { goto L12; }
   {
    cl_object v7fl;
    v7fl = ECL_NIL;
    {
     cl_object v8;
     v8 = v4forms;
     goto L19;
L18:;
     {
      cl_object v9form;
      v9form = ecl_car(v8);
      if (!(ecl_endp(v6arg_types))) { goto L24; }
      v7fl = CONS(v9form,v7fl);
      goto L23;
L24:;
      T0 = ecl_car(v6arg_types);
      T1 = ecl_car(v3args);
      T2 = ecl_function_dispatch(cl_env_copy,VV[71])(6, T0, v9form, T1, VV[12], _ecl_static_4, v1fname) /*  AND-FORM-TYPE */;
      v7fl = CONS(T2,v7fl);
      {
       cl_object v10;
       v10 = v6arg_types;
       if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
       if (Null(v10)) { goto L33; }
       {
        cl_object v11;
        v11 = ECL_CONS_CDR(v10);
        v6arg_types = v11;
        v10 = ECL_CONS_CAR(v10);
       }
L33:;
      }
      {
       cl_object v10;
       v10 = v3args;
       if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
       if (Null(v10)) { goto L42; }
       {
        cl_object v11;
        v11 = ECL_CONS_CDR(v10);
        v3args = v11;
        v10 = ECL_CONS_CAR(v10);
       }
L42:;
      }
L23:;
     }
     v8 = ecl_cdr(v8);
L19:;
     if (Null(v8)) { goto L50; }
     goto L18;
L50:;
    }
    v4forms = cl_nreverse(v7fl);
   }
L12:;
   value0 = ecl_function_dispatch(cl_env_copy,VV[48])(10, VV[13], VV[14], ECL_T, VV[15], ECL_T, ECL_SYM("TYPE",1318), v5return_type, VV[0], v2fun, v4forms) /*  MAKE-C1FORM* */;
   return value0;
  }
 }
}
/*	function definition for C1CALL-GLOBAL                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7c1call_global(cl_object v1fname, cl_object v2args)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3forms;
   v3forms = L15c1args_(v2args);
   {
    cl_object v4value;
    v4value = L9c1call_constant_fold(v1fname, v3forms);
    if (Null(v4value)) { goto L2; }
    value0 = v4value;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L2:;
   T0 = ecl_function_dispatch(cl_env_copy,VV[73])(1, v1fname) /*  FUNCTION-MAY-CHANGE-SP */;
   T1 = ecl_function_dispatch(cl_env_copy,VV[74])(1, v1fname) /*  FUNCTION-MAY-HAVE-SIDE-EFFECTS */;
   T2 = ecl_function_dispatch(cl_env_copy,VV[75])(2, v1fname, v3forms) /*  PROPAGATE-TYPES */;
   value0 = ecl_function_dispatch(cl_env_copy,VV[48])(10, VV[16], VV[14], T0, VV[15], T1, ECL_SYM("TYPE",1318), T2, VV[0], v1fname, v3forms) /*  MAKE-C1FORM* */;
   return value0;
  }
 }
}
/*	function definition for C1CALL-CONSTANT-FOLD                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L9c1call_constant_fold(cl_object volatile v1fname, cl_object volatile v2forms)
{
 cl_object T0, T1, T2, T3;
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(si_get_sysprop(v1fname, VV[18]))) { goto L1; }
  if (Null(ecl_function_dispatch(cl_env_copy,VV[77])(0) /*  POLICY-EVALUATE-FORMS */)) { goto L1; }
  if (Null(ecl_function_dispatch(cl_env_copy,VV[62])(1, v1fname) /*  INLINE-POSSIBLE */)) { goto L1; }
  {
   volatile cl_object env1 = env0;
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(ECL_NIL,env1);
   {
    volatile cl_object env2 = env1;
    CLV1 = env2 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env2); /*  TAGBODY */
    if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV1))) {
    if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L5;
    ecl_internal_error("GO found an inexistent tag");
    }
    {cl_object v3;
     v3 = ECL_NIL;
     v3 = ecl_make_cclosure_va((cl_objectfn)LC8__g16,env2,Cblock);
     T0 = v3;
    }
    T1 = CONS(ECL_SYM("ERROR",337),T0);
    T2 = ecl_list1(T1);
    T3 = CONS(T2,ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5)));
    ecl_bds_bind(cl_env_copy,ECL_SYM("*HANDLER-CLUSTERS*",5),T3); /*  *HANDLER-CLUSTERS* */
    {
     cl_object v3all_values;
     v3all_values = ECL_NIL;
     {
      cl_object v4constant_p;
      v4constant_p = ECL_NIL;
      {
       cl_object v5v;
       v5v = ECL_NIL;
       {
        cl_object v6form;
        cl_object v7;
        v6form = ECL_NIL;
        if (ecl_unlikely(!ECL_LISTP(v2forms))) FEtype_error_list(v2forms);
        v7 = v2forms;
L14:;
        if (!(ecl_endp(v7))) { goto L16; }
        goto L15;
L16:;
        v6form = _ecl_car(v7);
        {
         cl_object v8;
         v8 = _ecl_cdr(v7);
         if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
         v7 = v8;
        }
        value0 = ecl_function_dispatch(cl_env_copy,VV[78])(1, v6form) /*  C1FORM-CONSTANT-P */;
        v4constant_p = value0;
        {
         const int v8 = cl_env_copy->nvalues;
         cl_object v9;
         v9 = (v8<=1)? ECL_NIL : cl_env_copy->values[1];
         v5v = v9;
        }
        if (Null(value0)) { goto L25; }
        v3all_values = CONS(v5v,v3all_values);
        goto L24;
L25:;
        value0 = ECL_NIL;
        cl_env_copy->nvalues = 1;
        ecl_frs_pop(cl_env_copy);
        ecl_bds_unwind1(cl_env_copy);
        return value0;
L24:;
        goto L14;
L15:;
        T0 = cl_nreverse(v3all_values);
        T1 = cl_apply(2, v1fname, T0);
        value0 = ecl_function_dispatch(cl_env_copy,VV[49])(3, T1, VV[1], ECL_NIL) /*  C1CONSTANT-VALUE */;
        ecl_frs_pop(cl_env_copy);
        ecl_bds_unwind1(cl_env_copy);
        return value0;
       }
      }
     }
    }
L5:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    ecl_frs_pop(cl_env_copy);
    return value0;
   }
  }
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	closure G16                                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC8__g16(cl_narg narg, cl_object v1si__temp, ...)
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
/*	function definition for C2EXPR                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L10c2expr(cl_object v1form)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[80])(1, v1form) /*  C1FORM-FILE */;
  ecl_bds_bind(cl_env_copy,ECL_SYM("*COMPILE-FILE-TRUENAME*",27),T0); /*  *COMPILE-FILE-TRUENAME* */
  T0 = ecl_function_dispatch(cl_env_copy,VV[81])(1, v1form) /*  C1FORM-FILE-POSITION */;
  ecl_bds_bind(cl_env_copy,VV[20],T0);            /*  *COMPILE-FILE-POSITION* */
  T0 = ecl_function_dispatch(cl_env_copy,VV[82])(1, v1form) /*  C1FORM-TOPLEVEL-FORM */;
  ecl_bds_bind(cl_env_copy,VV[21],T0);            /*  *CURRENT-TOPLEVEL-FORM* */
  T0 = ecl_function_dispatch(cl_env_copy,VV[83])(1, v1form) /*  C1FORM-FORM */;
  ecl_bds_bind(cl_env_copy,VV[4],T0);             /*  *CURRENT-FORM*  */
  T0 = ecl_function_dispatch(cl_env_copy,VV[84])(1, v1form) /*  C1FORM-ENV */;
  ecl_bds_bind(cl_env_copy,VV[22],T0);            /*  *CMP-ENV*       */
  {
   cl_object v2name;
   cl_object v3args;
   cl_object v4dispatch;
   v2name = ecl_function_dispatch(cl_env_copy,VV[85])(1, v1form) /*  C1FORM-NAME */;
   v3args = ecl_function_dispatch(cl_env_copy,VV[86])(1, v1form) /*  C1FORM-ARGS */;
   v4dispatch = ecl_gethash_safe(v2name,ecl_symbol_value(VV[23]),ECL_NIL);
   value0 = cl_apply(3, v4dispatch, v1form, v3args);
   ecl_bds_unwind_n(cl_env_copy,5);
   return value0;
  }
 }
}
/*	function definition for C2EXPR*                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L11c2expr_(cl_object v1form)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2label;
   v2label = ecl_function_dispatch(cl_env_copy,VV[88])(0) /*  NEXT-LABEL */;
   T0 = CONS(v2label,ecl_symbol_value(VV[25]));
   ecl_bds_bind(cl_env_copy,VV[25],T0);           /*  *UNWIND-EXIT*   */
   ecl_bds_bind(cl_env_copy,VV[26],v2label);      /*  *EXIT*          */
   T0 = CONS(ecl_symbol_value(VV[26]),ecl_symbol_value(VV[25]));
   ecl_bds_bind(cl_env_copy,VV[25],T0);           /*  *UNWIND-EXIT*   */
   ecl_bds_push(cl_env_copy,VV[27]);              /*  *LCL*           */
   ecl_bds_push(cl_env_copy,VV[28]);              /*  *TEMP*          */
   L10c2expr(v1form);
   ecl_bds_unwind_n(cl_env_copy,4);
   value0 = ecl_function_dispatch(cl_env_copy,VV[89])(1, v2label) /*  WT-LABEL */;
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
 }
}
/*	function definition for C1WITH-BACKEND                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L12c1with_backend(cl_object v1forms)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2tag;
   v2tag = ECL_NIL;
   {
    cl_object v3form;
    v3form = ECL_NIL;
    {
     cl_object v4;
     cl_object v5;
     v4 = ecl_list1(ECL_NIL);
     v5 = v4;
L6:;
     {
      cl_object v6;
      v6 = v1forms;
      if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
      if (Null(v6)) { goto L13; }
      {
       cl_object v7;
       v7 = ECL_CONS_CDR(v6);
       v1forms = v7;
       v6 = ECL_CONS_CAR(v6);
      }
L13:;
      v2tag = v6;
     }
     {
      cl_object v6;
      v6 = v1forms;
      if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
      if (Null(v6)) { goto L24; }
      {
       cl_object v7;
       v7 = ECL_CONS_CDR(v6);
       v1forms = v7;
       v6 = ECL_CONS_CAR(v6);
      }
L24:;
      v3form = v6;
     }
     if ((v2tag)!=ECL_NIL) { goto L30; }
     goto L7;
L30:;
     if (!((v2tag)==(ECL_SYM("C/C++",1770)))) { goto L32; }
     if (ecl_unlikely(ECL_ATOM(v5))) FEtype_error_cons(v5);
     T1 = v5;
     v5 = ecl_list1(v3form);
     (ECL_CONS_CDR(T1)=v5,T1);
L32:;
     goto L6;
L7:;
     T0 = ecl_cdr(v4);
     goto L1;
    }
   }
  }
L1:;
  value0 = L13c1progn(T0);
  return value0;
 }
}
/*	function definition for C1PROGN                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L13c1progn(cl_object v1forms)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ecl_endp(v1forms))) { goto L1; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[92])(1, ECL_NIL) /*  T1/C1EXPR */;
  return value0;
L1:;
  T0 = ecl_cdr(v1forms);
  if (!(ecl_endp(T0))) { goto L3; }
  T0 = ecl_car(v1forms);
  value0 = ecl_function_dispatch(cl_env_copy,VV[92])(1, T0) /*  T1/C1EXPR */;
  return value0;
L3:;
  {
   cl_object v2fl;
   cl_object v3output_form;
   cl_object v4output_type;
   {
    cl_object v5;
    cl_object v6;
    v5 = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v1forms))) FEtype_error_list(v1forms);
    v6 = v1forms;
    {
     cl_object v7;
     cl_object v8;
     v7 = ecl_list1(ECL_NIL);
     v8 = v7;
L11:;
     if (!(ecl_endp(v6))) { goto L13; }
     goto L12;
L13:;
     v5 = _ecl_car(v6);
     {
      cl_object v9;
      v9 = _ecl_cdr(v6);
      if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
      v6 = v9;
     }
     if (ecl_unlikely(ECL_ATOM(v8))) FEtype_error_cons(v8);
     T0 = v8;
     T1 = ecl_function_dispatch(cl_env_copy,VV[92])(1, v5) /*  T1/C1EXPR */;
     v8 = ecl_list1(T1);
     (ECL_CONS_CDR(T0)=v8,T0);
     goto L11;
L12:;
     v2fl = ecl_cdr(v7);
     goto L5;
    }
   }
L5:;
   T0 = ecl_last(v2fl,1);
   v3output_form = ecl_car(T0);
   if (Null(v3output_form)) { goto L30; }
   v4output_type = ecl_function_dispatch(cl_env_copy,VV[93])(1, v3output_form) /*  C1FORM-TYPE */;
   goto L28;
L30:;
   v4output_type = ECL_NIL;
   goto L28;
L28:;
   value0 = ecl_function_dispatch(cl_env_copy,VV[48])(5, ECL_SYM("PROGN",671), ECL_SYM("TYPE",1318), v4output_type, VV[0], v2fl) /*  MAKE-C1FORM* */;
   return value0;
  }
 }
}
/*	function definition for C2PROGN                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L14c2progn(cl_object v1c1form, cl_object v2forms)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4l;
   v3 = ecl_symbol_value(VV[32]);
   v4l = v2forms;
   goto L5;
L4:;
   {
    cl_object v5this_form;
    cl_object v6name;
    v5this_form = ecl_car(v4l);
    v6name = ecl_function_dispatch(cl_env_copy,VV[85])(1, v5this_form) /*  C1FORM-NAME */;
    ecl_bds_bind(cl_env_copy,VV[33],VV[34]);      /*  *DESTINATION*   */
    T0 = ecl_car(v4l);
    L11c2expr_(T0);
    ecl_bds_unwind1(cl_env_copy);
    cl_set(VV[32],v3);
    if ((v6name)==(ECL_SYM("GO",414))) { goto L14; }
    if (!((v6name)==(ECL_SYM("RETURN-FROM",725)))) { goto L7; }
    goto L13;
L14:;
L13:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L7:;
   v4l = ecl_cdr(v4l);
L5:;
   T0 = ecl_cdr(v4l);
   if (ecl_endp(T0)) { goto L18; }
   goto L4;
L18:;
   T0 = ecl_car(v4l);
   value0 = L10c2expr(T0);
   return value0;
  }
 }
}
/*	function definition for C1ARGS*                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L15c1args_(cl_object v1forms)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   cl_object v3;
   v2 = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v1forms))) FEtype_error_list(v1forms);
   v3 = v1forms;
   {
    cl_object v4;
    cl_object v5;
    v4 = ecl_list1(ECL_NIL);
    v5 = v4;
L6:;
    if (!(ecl_endp(v3))) { goto L8; }
    goto L7;
L8:;
    v2 = _ecl_car(v3);
    {
     cl_object v6;
     v6 = _ecl_cdr(v3);
     if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
     v3 = v6;
    }
    if (ecl_unlikely(ECL_ATOM(v5))) FEtype_error_cons(v5);
    T0 = v5;
    T1 = L2c1expr(v2);
    v5 = ecl_list1(T1);
    (ECL_CONS_CDR(T0)=v5,T0);
    goto L6;
L7:;
    value0 = ecl_cdr(v4);
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	local function DEFINE-INLINE-FUNCTION                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC16si__define_inline_function(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4name;
   cl_object v5vars;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4name = v6;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5vars = v6;
   }
   {
    cl_object v6;
    cl_object v7temps;
    v6 = ecl_symbol_value(VV[37]);
    v7temps = ECL_NIL;
    ecl_bds_bind(cl_env_copy,VV[37],v6);          /*  *COMPILER-TEMPS* */
    {
     cl_object v8;
     v8 = v5vars;
     goto L20;
L19:;
     {
      cl_object v9var;
      v9var = ecl_car(v8);
      if (!(ECL_SYMBOLP(v9var))) { goto L25; }
      if (!((v9var)==(ECL_SYM("&OPTIONAL",11)))) { goto L30; }
      goto L25;
      goto L28;
L30:;
      goto L28;
L28:;
      if (!((v9var)==(ECL_SYM("&REST",12)))) { goto L34; }
      goto L25;
      goto L32;
L34:;
      goto L32;
L32:;
      if (!((v9var)==(ECL_SYM("&KEY",10)))) { goto L38; }
      goto L25;
      goto L36;
L38:;
      goto L36;
L36:;
      if (!((v9var)==(ECL_SYM("&AUX",7)))) { goto L41; }
      goto L25;
      goto L26;
L41:;
      goto L26;
L26:;
      {
       cl_object v10;
       v10 = ecl_symbol_value(VV[37]);
       if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
       if (Null(v10)) { goto L51; }
       {
        cl_object v11;
        v11 = ECL_CONS_CDR(v10);
        cl_set(VV[37],v11);
        v10 = ECL_CONS_CAR(v10);
       }
L51:;
       value0 = v10;
      }
      if ((value0)!=ECL_NIL) { goto L46; }
      T1 = cl_find_package(VV[42]);
      T0 = cl_gentemp(2, _ecl_static_5, T1);
      goto L44;
L46:;
      T0 = value0;
      goto L44;
L44:;
      v7temps = CONS(T0,v7temps);
      goto L24;
L25:;
      cl_error(3, _ecl_static_6, v9var, v4name);
L24:;
     }
     v8 = ecl_cdr(v8);
L20:;
     if (Null(v8)) { goto L59; }
     goto L19;
L59:;
    }
    {
     cl_object v8binding;
     {
      cl_object v9;
      cl_object v10;
      v9 = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v5vars))) FEtype_error_list(v5vars);
      v10 = v5vars;
      {
       cl_object v11;
       cl_object v12;
       v11 = ECL_NIL;
       if (ecl_unlikely(!ECL_LISTP(v7temps))) FEtype_error_list(v7temps);
       v12 = v7temps;
       {
        cl_object v13;
        cl_object v14;
        v13 = ecl_list1(ECL_NIL);
        v14 = v13;
L71:;
        if (!(ecl_endp(v10))) { goto L73; }
        goto L72;
L73:;
        v9 = _ecl_car(v10);
        {
         cl_object v15;
         v15 = _ecl_cdr(v10);
         if (ecl_unlikely(!ECL_LISTP(v15))) FEtype_error_list(v15);
         v10 = v15;
        }
        if (!(ecl_endp(v12))) { goto L81; }
        goto L72;
L81:;
        v11 = _ecl_car(v12);
        {
         cl_object v15;
         v15 = _ecl_cdr(v12);
         if (ecl_unlikely(!ECL_LISTP(v15))) FEtype_error_list(v15);
         v12 = v15;
        }
        if (ecl_unlikely(ECL_ATOM(v14))) FEtype_error_cons(v14);
        T1 = v14;
        T3 = cl_list(2, ECL_SYM("QUOTE",679), v9);
        T2 = cl_list(3, ECL_SYM("LIST",481), T3, v11);
        v14 = ecl_list1(T2);
        (ECL_CONS_CDR(T1)=v14,T1);
        goto L71;
L72:;
        T0 = ecl_cdr(v13);
        goto L62;
       }
      }
     }
L62:;
     v8binding = CONS(ECL_SYM("LIST",481),T0);
     T0 = cl_listX(4, ECL_SYM("DEFUN",289), v4name, v5vars, v3);
     T1 = cl_list(2, ECL_SYM("QUOTE",679), v3);
     T2 = cl_list(4, ECL_SYM("LIST*",482), VV[43], v8binding, T1);
     T3 = cl_list(4, ECL_SYM("DEFINE-COMPILER-MACRO",279), v4name, v7temps, T2);
     value0 = cl_list(3, ECL_SYM("PROGN",671), T0, T3);
     ecl_bds_unwind1(cl_env_copy);
     return value0;
    }
   }
  }
 }
}

#include "cmp/cmpeval.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecl7s006zNsLbCl9_K1qtVE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPEVAL.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_ecl7s006zNsLbCl9_K1qtVE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 (void)0; /* No entry created for C1EXPR-INNER */
 ecl_cmp_defun(VV[53]);                           /*  C1EXPR          */
 {
  cl_object T0;
 si_Xmake_special(VV[6]);
 if (ecl_boundp(cl_env_copy,VV[6])) { goto L11; }
 T0 = ecl_function_dispatch(cl_env_copy,VV[46])(1, ECL_NIL) /*  OBJECT-TYPE */;
 cl_set(VV[6],ecl_function_dispatch(cl_env_copy,VV[48])(5, ECL_SYM("LOCATION",1763), ECL_SYM("TYPE",1318), T0, VV[0], ECL_NIL) /*  MAKE-C1FORM* */);
L11:;
 }
 ecl_cmp_defun(VV[55]);                           /*  C1NIL           */
 {
  cl_object T0;
 si_Xmake_special(VV[8]);
 if (ecl_boundp(cl_env_copy,VV[8])) { goto L22; }
 T0 = ecl_function_dispatch(cl_env_copy,VV[46])(1, ECL_T) /*  OBJECT-TYPE */;
 cl_set(VV[8],ecl_function_dispatch(cl_env_copy,VV[48])(5, ECL_SYM("LOCATION",1763), ECL_SYM("TYPE",1318), T0, VV[0], ECL_T) /*  MAKE-C1FORM* */);
L22:;
 }
 ecl_cmp_defun(VV[56]);                           /*  C1T             */
 ecl_cmp_defun(VV[57]);                           /*  C1CALL          */
 (void)0; /* No entry created for C1CALL-LOCAL */
 ecl_cmp_defun(VV[72]);                           /*  C1CALL-GLOBAL   */
 ecl_cmp_defun(VV[76]);                           /*  C1CALL-CONSTANT-FOLD */
 ecl_cmp_defun(VV[79]);                           /*  C2EXPR          */
 ecl_cmp_defun(VV[87]);                           /*  C2EXPR*         */
 ecl_cmp_defun(VV[90]);                           /*  C1WITH-BACKEND  */
 ecl_cmp_defun(VV[91]);                           /*  C1PROGN         */
 ecl_cmp_defun(VV[94]);                           /*  C2PROGN         */
 ecl_cmp_defun(VV[95]);                           /*  C1ARGS*         */
 si_Xmake_special(VV[37]);
 if (ecl_boundp(cl_env_copy,VV[37])) { goto L73; }
 cl_set(VV[37],VVtemp[0]);
L73:;
 ecl_cmp_defmacro(VV[96]);                        /*  DEFINE-INLINE-FUNCTION */
}
