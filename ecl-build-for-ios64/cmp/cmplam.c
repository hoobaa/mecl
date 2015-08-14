/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPLAM.LSP                                    */
#include <ecl/ecl-cmp.h>
#include "cmp/cmplam.eclh"
/*	function definition for C1LAMBDA-DOC                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1c1lambda_doc(cl_object v1form)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[47])(1, v1form) /*  C1FORM-ARGS */;
  value0 = ecl_cadr(T0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for C1LAMBDA-BODY                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2c1lambda_body(cl_object v1form)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[47])(1, v1form) /*  C1FORM-ARGS */;
  value0 = ecl_caddr(T0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for C1LAMBDA-LIST                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3c1lambda_list(cl_object v1form)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[47])(1, v1form) /*  C1FORM-ARGS */;
  value0 = ecl_car(T0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for FUN-NEEDS-NARG                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4fun_needs_narg(cl_object v1fun)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = L5fun_fixed_narg(v1fun);
  value0 = Null(T0)?ECL_T:ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for FUN-FIXED-NARG                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5fun_fixed_narg(cl_object v1fun)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2narg;
   v2narg = ECL_NIL;
   T0 = ecl_function_dispatch(cl_env_copy,VV[52])(1, v1fun) /*  FUN-CLOSURE */;
   if ((T0)==(VV[4])) { goto L3; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[53])(1, v1fun) /*  FUN-MINARG */;
   v2narg = ecl_function_dispatch(cl_env_copy,VV[54])(1, v1fun) /*  FUN-MAXARG */;
   if (!(ecl_number_equalp(T0,v2narg))) { goto L3; }
   if (!(ecl_number_compare(v2narg,ecl_make_fixnum(63))<=0)) { goto L3; }
   value0 = v2narg;
   cl_env_copy->nvalues = 1;
   return value0;
L3:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for ADD-TO-FUN-REFERENCED-VARS            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6add_to_fun_referenced_vars(cl_object v1fun, cl_object v2var_list)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3new_vars;
   v3new_vars = ecl_function_dispatch(cl_env_copy,VV[56])(1, v1fun) /*  FUN-REFERENCED-VARS */;
   {
    cl_object v4locals;
    v4locals = ecl_function_dispatch(cl_env_copy,VV[57])(1, v1fun) /*  FUN-LOCAL-VARS */;
    {
     cl_object v5change;
     v5change = ECL_NIL;
     {
      cl_object v6v;
      cl_object v7;
      v6v = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v2var_list))) FEtype_error_list(v2var_list);
      v7 = v2var_list;
L7:;
      if (!(ecl_endp(v7))) { goto L9; }
      goto L8;
L9:;
      v6v = _ecl_car(v7);
      {
       cl_object v8;
       v8 = _ecl_cdr(v7);
       if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
       v7 = v8;
      }
      if ((si_memq(v6v,v4locals))!=ECL_NIL) { goto L17; }
      if ((si_memq(v6v,v3new_vars))!=ECL_NIL) { goto L17; }
      v5change = ECL_T;
      v3new_vars = CONS(v6v,v3new_vars);
L17:;
      goto L7;
L8:;
      if (Null(v5change)) { goto L24; }
      ecl_structure_set(v1fun,VV[6],22,v3new_vars);
      value0 = ECL_T;
      cl_env_copy->nvalues = 1;
      return value0;
L24:;
      value0 = ECL_NIL;
      cl_env_copy->nvalues = 1;
      return value0;
     }
    }
   }
  }
 }
}
/*	function definition for ADD-TO-FUN-REFERENCED-FUNS            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7add_to_fun_referenced_funs(cl_object v1fun, cl_object v2fun_list)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3new_funs;
   v3new_funs = ecl_function_dispatch(cl_env_copy,VV[59])(1, v1fun) /*  FUN-REFERENCED-FUNS */;
   {
    cl_object v4change;
    v4change = ECL_NIL;
    {
     cl_object v5f;
     cl_object v6;
     v5f = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v2fun_list))) FEtype_error_list(v2fun_list);
     v6 = v2fun_list;
L6:;
     if (!(ecl_endp(v6))) { goto L8; }
     goto L7;
L8:;
     v5f = _ecl_car(v6);
     {
      cl_object v7;
      v7 = _ecl_cdr(v6);
      if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
      v6 = v7;
     }
     if ((v1fun)==(v5f)) { goto L16; }
     if ((si_memq(v5f,v3new_funs))!=ECL_NIL) { goto L16; }
     if ((ecl_function_dispatch(cl_env_copy,VV[60])(2, v1fun, v5f) /*  CHILD-FUNCTION-P */)!=ECL_NIL) { goto L16; }
     v4change = ECL_T;
     v3new_funs = CONS(v5f,v3new_funs);
     {
      cl_object v7;
      T0 = ecl_function_dispatch(cl_env_copy,VV[61])(1, v5f) /*  FUN-REFERENCING-FUNS */;
      v7 = CONS(v1fun,T0);
      ecl_structure_set(v5f,VV[6],24,v7);
     }
L16:;
     goto L6;
L7:;
     if (Null(v4change)) { goto L26; }
     ecl_structure_set(v1fun,VV[6],23,v3new_funs);
     value0 = ECL_T;
     cl_env_copy->nvalues = 1;
     return value0;
L26:;
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
  }
 }
}
/*	function definition for C1COMPILE-FUNCTION                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8c1compile_function(cl_narg narg, cl_object v1lambda_list_and_body, ...)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2fun;
  cl_object v3name;
  cl_object v4cb_lb;
  ecl_va_list args; ecl_va_start(args,v1lambda_list_and_body,narg,1);
  {
   cl_object keyvars[6];
   cl_parse_key(args,3,L8c1compile_functionkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[3])) {
    v2fun = ecl_function_dispatch(cl_env_copy,VV[63])(0) /*  MAKE-FUN */;
   } else {
    v2fun = keyvars[0];
   }
   if (Null(keyvars[4])) {
    v3name = ecl_function_dispatch(cl_env_copy,VV[64])(1, v2fun) /*  FUN-NAME */;
   } else {
    v3name = keyvars[1];
   }
   if (Null(keyvars[5])) {
    v4cb_lb = VV[9];
   } else {
    v4cb_lb = keyvars[2];
   }
  }
  {
   cl_object v5lambda;
   if (Null(v3name)) { goto L6; }
   v5lambda = cl_listX(3, ECL_SYM("LAMBDA-BLOCK",1339), v3name, v1lambda_list_and_body);
   goto L5;
L6:;
   v5lambda = CONS(ECL_SYM("LAMBDA",452),v1lambda_list_and_body);
L5:;
   ecl_structure_set(v2fun,VV[6],0,v3name);
   ecl_structure_set(v2fun,VV[6],16,v5lambda);
   {
    cl_object v6;
    v6 = ecl_symbol_value(VV[10]);
    ecl_structure_set(v2fun,VV[6],20,v6);
   }
  }
  if (Null(ecl_symbol_value(VV[10]))) { goto L11; }
  {
   cl_object v5;
   cl_object v6;
   v5 = ecl_symbol_value(VV[10]);
   T0 = ecl_function_dispatch(cl_env_copy,VV[68])(1, v5) /*  FUN-CHILD-FUNS */;
   v6 = CONS(v2fun,T0);
   ecl_structure_set(v5,VV[6],25,v6);
  }
L11:;
  {
   cl_object v5setjmps;
   cl_object v6decl;
   cl_object v7global;
   cl_object v8no_entry;
   cl_object v9lambda_expr;
   cl_object v10cfun;
   cl_object v11exported;
   cl_object v12minarg;
   cl_object v13maxarg;
   ecl_bds_bind(cl_env_copy,VV[10],v2fun);        /*  *CURRENT-FUNCTION* */
   {
    cl_object v14;
    v14 = ecl_function_dispatch(cl_env_copy,VV[69])(1, v4cb_lb) /*  CMP-ENV-MARK */;
    T0 = ecl_structure_set(v2fun,VV[6],28,v14);
   }
   ecl_bds_bind(cl_env_copy,VV[11],T0);           /*  *CMP-ENV*       */
   v5setjmps = ecl_symbol_value(VV[12]);
   T0 = ecl_cdr(v1lambda_list_and_body);
   v6decl = si_process_declarations(1, T0);
   if (Null(ecl_assql(VV[13],v6decl))) { goto L22; }
   v7global = ecl_structure_set(v2fun,VV[6],8,ECL_T);
   goto L20;
L22:;
   v7global = ECL_NIL;
   goto L20;
L20:;
   v8no_entry = ecl_assql(VV[14],v6decl);
   T0 = si_function_block_name(v3name);
   v9lambda_expr = L11c1lambda_expr(2, v1lambda_list_and_body, T0);
   v10cfun = ECL_NIL;
   v11exported = ECL_NIL;
   v12minarg = ECL_NIL;
   v13maxarg = ECL_NIL;
   if (Null(v8no_entry)) { goto L30; }
   if (Null(ecl_function_dispatch(cl_env_copy,VV[70])(0) /*  POLICY-DEBUG-IHS-FRAME */)) { goto L30; }
   v8no_entry = ECL_NIL;
   ecl_function_dispatch(cl_env_copy,VV[71])(2, _ecl_static_1, v3name) /*  CMPNOTE */;
L30:;
   if (ecl_eql(v5setjmps,ecl_symbol_value(VV[12]))) { goto L35; }
   ecl_structure_set(v9lambda_expr,VV[15],3,ECL_T);
L35:;
   ecl_structure_set(v2fun,VV[6],15,v9lambda_expr);
   if (Null(v7global)) { goto L39; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[72])(1, v3name) /*  EXPORTED-FNAME */;
   v10cfun = value0;
   {
    const int v14 = cl_env_copy->nvalues;
    cl_object v15;
    v15 = (v14<=1)? ECL_NIL : cl_env_copy->values[1];
    v11exported = v15;
   }
   goto L38;
L39:;
   v10cfun = ecl_function_dispatch(cl_env_copy,VV[73])(2, _ecl_static_2, v3name) /*  NEXT-CFUN */;
   v11exported = ECL_NIL;
L38:;
   if (Null(v11exported)) { goto L46; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[74])(1, v3name) /*  GET-PROCLAIMED-NARG */;
   v12minarg = value0;
   {
    const int v14 = cl_env_copy->nvalues;
    cl_object v15;
    v15 = (v14<=1)? ECL_NIL : cl_env_copy->values[1];
    v13maxarg = v15;
   }
   cl_format(5, ECL_T, _ecl_static_3, v3name, v12minarg, v13maxarg);
   if ((v12minarg)!=ECL_NIL) { goto L45; }
   v12minarg = ecl_make_fixnum(0);
   v13maxarg = ecl_make_fixnum(65536);
   goto L45;
L46:;
   value0 = L12lambda_form_allowed_nargs(v9lambda_expr);
   v12minarg = value0;
   {
    const int v14 = cl_env_copy->nvalues;
    cl_object v15;
    v15 = (v14<=1)? ECL_NIL : cl_env_copy->values[1];
    v13maxarg = v15;
   }
L45:;
   ecl_structure_set(v2fun,VV[6],5,v10cfun);
   ecl_structure_set(v2fun,VV[6],9,v11exported);
   ecl_structure_set(v2fun,VV[6],12,ECL_NIL);
   ecl_structure_set(v2fun,VV[6],17,v12minarg);
   ecl_structure_set(v2fun,VV[6],18,v13maxarg);
   ecl_structure_set(v2fun,VV[6],14,v3name);
   ecl_structure_set(v2fun,VV[6],10,v8no_entry);
   {
    cl_object v14;
    cl_object v15child;
    cl_object v16;
    v14 = ecl_function_dispatch(cl_env_copy,VV[68])(1, v2fun) /*  FUN-CHILD-FUNS */;
    v15child = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
    v16 = v14;
L68:;
    if (!(ecl_endp(v16))) { goto L70; }
    goto L69;
L70:;
    v15child = _ecl_car(v16);
    {
     cl_object v17;
     v17 = _ecl_cdr(v16);
     if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
     v16 = v17;
    }
    T0 = ecl_function_dispatch(cl_env_copy,VV[56])(1, v15child) /*  FUN-REFERENCED-VARS */;
    L6add_to_fun_referenced_vars(v2fun, T0);
    T0 = ecl_function_dispatch(cl_env_copy,VV[59])(1, v15child) /*  FUN-REFERENCED-FUNS */;
    L7add_to_fun_referenced_funs(v2fun, T0);
    goto L68;
L69:;
   }
   {
    cl_object v14;
    cl_object v15f;
    cl_object v16;
    v14 = ecl_function_dispatch(cl_env_copy,VV[59])(1, v2fun) /*  FUN-REFERENCED-FUNS */;
    v15f = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
    v16 = v14;
L86:;
    if (!(ecl_endp(v16))) { goto L88; }
    goto L87;
L88:;
    v15f = _ecl_car(v16);
    {
     cl_object v17;
     v17 = _ecl_cdr(v16);
     if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
     v16 = v17;
    }
    T0 = ecl_function_dispatch(cl_env_copy,VV[56])(1, v15f) /*  FUN-REFERENCED-VARS */;
    L6add_to_fun_referenced_vars(v2fun, T0);
    goto L86;
L87:;
   }
   ecl_function_dispatch(cl_env_copy,VV[75])(1, v2fun) /*  UPDATE-FUN-CLOSURE-TYPE */;
   if (Null(v7global)) {
   ecl_bds_unwind1(cl_env_copy);
   ecl_bds_unwind1(cl_env_copy);
    goto L15;
   }
   if (Null(ecl_function_dispatch(cl_env_copy,VV[52])(1, v2fun) /*  FUN-CLOSURE */)) { goto L100; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[64])(1, v2fun) /*  FUN-NAME */;
   {
    cl_object v14;
    cl_object v15;
    cl_object v16;
    v14 = ecl_function_dispatch(cl_env_copy,VV[56])(1, v2fun) /*  FUN-REFERENCED-VARS */;
    v15 = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
    v16 = v14;
    {
     cl_object v17;
     cl_object v18;
     v17 = ecl_list1(ECL_NIL);
     v18 = v17;
L109:;
     if (!(ecl_endp(v16))) { goto L111; }
     goto L110;
L111:;
     v15 = _ecl_car(v16);
     {
      cl_object v19;
      v19 = _ecl_cdr(v16);
      if (ecl_unlikely(!ECL_LISTP(v19))) FEtype_error_list(v19);
      v16 = v19;
     }
     if (ecl_unlikely(ECL_ATOM(v18))) FEtype_error_cons(v18);
     T2 = v18;
     T3 = ecl_function_dispatch(cl_env_copy,VV[76])(1, v15) /*  VAR-NAME */;
     v18 = ecl_list1(T3);
     (ECL_CONS_CDR(T2)=v18,T2);
     goto L109;
L110:;
     T1 = ecl_cdr(v17);
     goto L102;
    }
   }
L102:;
   ecl_function_dispatch(cl_env_copy,VV[71])(3, _ecl_static_4, T0, T1) /*  CMPNOTE */;
   ecl_bds_unwind1(cl_env_copy);
   ecl_bds_unwind1(cl_env_copy);
   goto L15;
L100:;
   T0 = ecl_function_dispatch(cl_env_copy,VV[77])(1, v2fun) /*  FUN-NO-ENTRY */;
   ecl_function_dispatch(cl_env_copy,VV[78])(2, v2fun, T0) /*  NEW-DEFUN */;
   ecl_bds_unwind1(cl_env_copy);
   ecl_bds_unwind1(cl_env_copy);
  }
L15:;
  value0 = v2fun;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for CMP-PROCESS-LAMBDA-LIST               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L10cmp_process_lambda_list(cl_object volatile v1list)
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
  {
   volatile cl_object env1 = env0;
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(ECL_NIL,env1);
   {
    volatile cl_object env2 = env1;
    CLV1 = env2 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env2); /*  TAGBODY */
    if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV1))) {
    if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L1;
    ecl_internal_error("GO found an inexistent tag");
    }
    {cl_object v2;
     v2 = ECL_NIL;
     v2 = ecl_make_cclosure_va((cl_objectfn)LC9__g68,env2,Cblock);
     T0 = v2;
    }
    T1 = CONS(ECL_SYM("ERROR",337),T0);
    T2 = ecl_list1(T1);
    T3 = CONS(T2,ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5)));
    ecl_bds_bind(cl_env_copy,ECL_SYM("*HANDLER-CLUSTERS*",5),T3); /*  *HANDLER-CLUSTERS* */
    value0 = si_process_lambda_list(v1list, ECL_SYM("FUNCTION",396));
    ecl_frs_pop(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    return value0;
L1:;
    value0 = ecl_function_dispatch(cl_env_copy,VV[80])(2, _ecl_static_5, v1list) /*  CMPERR */;
    ecl_frs_pop(cl_env_copy);
    return value0;
   }
  }
 }
}
/*	closure G68                                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC9__g68(cl_narg narg, cl_object v1si__temp, ...)
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
/*	function definition for C1LAMBDA-EXPR                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L11c1lambda_expr(cl_narg narg, cl_object v1lambda_expr, ...)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2block_name;
  va_list args; va_start(args,v1lambda_expr);
  {
   int i = 1;
   if (i >= narg) {
    v2block_name = ECL_NIL;
   } else {
    i++;
    v2block_name = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v3doc;
   cl_object v4body;
   cl_object v5ss;
   cl_object v6is;
   cl_object v7ts;
   cl_object v8other_decls;
   cl_object v9type_checks;
   cl_object v10old_env;
   v3doc = ECL_NIL;
   v4body = ECL_NIL;
   v5ss = ECL_NIL;
   v6is = ECL_NIL;
   v7ts = ECL_NIL;
   v8other_decls = ECL_NIL;
   v9type_checks = ECL_NIL;
   ecl_bds_bind(cl_env_copy,VV[18],ECL_T);        /*  *PERMANENT-DATA* */
   v10old_env = ecl_symbol_value(VV[11]);
   T0 = ecl_function_dispatch(cl_env_copy,VV[81])(0) /*  CMP-ENV-COPY */;
   ecl_bds_bind(cl_env_copy,VV[11],T0);           /*  *CMP-ENV*       */
   if (!(ecl_endp(v1lambda_expr))) { goto L10; }
   T0 = CONS(ECL_SYM("LAMBDA",452),v1lambda_expr);
   ecl_function_dispatch(cl_env_copy,VV[80])(2, _ecl_static_6, T0) /*  CMPERR */;
L10:;
   T0 = ecl_cdr(v1lambda_expr);
   value0 = ecl_function_dispatch(cl_env_copy,VV[82])(2, T0, ECL_T) /*  C1BODY */;
   v4body = value0;
   {
    const int v11 = cl_env_copy->nvalues;
    cl_object v12;
    v12 = (v11<=1)? ECL_NIL : cl_env_copy->values[1];
    v5ss = v12;
    v12 = (v11<=2)? ECL_NIL : cl_env_copy->values[2];
    v7ts = v12;
    v12 = (v11<=3)? ECL_NIL : cl_env_copy->values[3];
    v6is = v12;
    v12 = (v11<=4)? ECL_NIL : cl_env_copy->values[4];
    v8other_decls = v12;
    v12 = (v11<=5)? ECL_NIL : cl_env_copy->values[5];
    v3doc = v12;
   }
   if (Null(v2block_name)) { goto L14; }
   T0 = cl_listX(3, ECL_SYM("BLOCK",137), v2block_name, v4body);
   v4body = ecl_list1(T0);
L14:;
   {
    cl_object v12;                                /*  REQUIREDS       */
    cl_object v13;                                /*  OPTIONALS       */
    cl_object v14;                                /*  REST            */
    cl_object v15;                                /*  KEY-FLAG        */
    cl_object v16;                                /*  KEYWORDS        */
    cl_object v17;                                /*  ALLOW-OTHER-KEYS */
    cl_object v18;                                /*  AUX-VARS        */
    T0 = ecl_car(v1lambda_expr);
    value0 = L10cmp_process_lambda_list(T0);
    v12 = value0;
    {
     const int v19 = cl_env_copy->nvalues;
     cl_object v20;
     v20 = (v19<=1)? ECL_NIL : cl_env_copy->values[1];
     v13 = v20;
     v20 = (v19<=2)? ECL_NIL : cl_env_copy->values[2];
     v14 = v20;
     v20 = (v19<=3)? ECL_NIL : cl_env_copy->values[3];
     v15 = v20;
     v20 = (v19<=4)? ECL_NIL : cl_env_copy->values[4];
     v16 = v20;
     v20 = (v19<=5)? ECL_NIL : cl_env_copy->values[5];
     v17 = v20;
     v20 = (v19<=6)? ECL_NIL : cl_env_copy->values[6];
     v18 = v20;
    }
    {
     cl_object v19specs;
     v12 = ecl_cdr(v12);
     v19specs = v12;
     goto L23;
L22:;
     {
      cl_object v20name;
      cl_object v21var;
      v20name = ecl_car(v19specs);
      v21var = ecl_function_dispatch(cl_env_copy,VV[83])(4, v20name, v5ss, v6is, v7ts) /*  C1MAKE-VAR */;
      v9type_checks = CONS(v21var,v9type_checks);
      if (ecl_unlikely(ECL_ATOM(v19specs))) FEtype_error_cons(v19specs);
      T0 = v19specs;
      (ECL_CONS_CAR(T0)=v21var,T0);
      ecl_function_dispatch(cl_env_copy,VV[84])(1, v21var) /*  PUSH-VARS */;
     }
     v19specs = ecl_cdr(v19specs);
L23:;
     if (ecl_endp(v19specs)) { goto L36; }
     goto L22;
L36:;
    }
    {
     cl_object v19specs;
     v13 = ecl_cdr(v13);
     v19specs = v13;
     goto L43;
L42:;
     {
      cl_object v20name;
      cl_object v21var;
      cl_object v22init;
      cl_object v23flag;
      v20name = ecl_car(v19specs);
      v21var = ecl_function_dispatch(cl_env_copy,VV[83])(4, v20name, v5ss, v6is, v7ts) /*  C1MAKE-VAR */;
      v22init = ecl_cadr(v19specs);
      v23flag = ecl_caddr(v19specs);
      if (Null(v22init)) { goto L52; }
      T0 = ecl_function_dispatch(cl_env_copy,VV[85])(1, v21var) /*  VAR-TYPE */;
      T1 = ecl_function_dispatch(cl_env_copy,VV[86])(1, v22init) /*  C1EXPR */;
      v22init = ecl_function_dispatch(cl_env_copy,VV[87])(6, T0, T1, v22init, VV[19], _ecl_static_7, v2block_name) /*  AND-FORM-TYPE */;
      goto L51;
L52:;
      v22init = ecl_function_dispatch(cl_env_copy,VV[88])(1, v21var) /*  DEFAULT-INIT */;
L51:;
      v9type_checks = CONS(v21var,v9type_checks);
      ecl_function_dispatch(cl_env_copy,VV[84])(1, v21var) /*  PUSH-VARS */;
      if (Null(v23flag)) { goto L57; }
      v23flag = ecl_function_dispatch(cl_env_copy,VV[83])(4, v23flag, v5ss, v6is, v7ts) /*  C1MAKE-VAR */;
      ecl_function_dispatch(cl_env_copy,VV[84])(1, v23flag) /*  PUSH-VARS */;
L57:;
      if (ecl_unlikely(ECL_ATOM(v19specs))) FEtype_error_cons(v19specs);
      T0 = v19specs;
      (ECL_CONS_CAR(T0)=v21var,T0);
      {
       cl_object v24;
       v24 = ecl_cdr(v19specs);
       if (ecl_unlikely(ECL_ATOM(v24))) FEtype_error_cons(v24);
       T0 = v24;
      }
      (ECL_CONS_CAR(T0)=v22init,T0);
      {
       cl_object v24;
       v24 = ecl_cddr(v19specs);
       if (ecl_unlikely(ECL_ATOM(v24))) FEtype_error_cons(v24);
       T0 = v24;
      }
      (ECL_CONS_CAR(T0)=v23flag,T0);
     }
     v19specs = ecl_cdddr(v19specs);
L43:;
     if (ecl_endp(v19specs)) { goto L75; }
     goto L42;
L75:;
    }
    if (Null(v14)) { goto L77; }
    v14 = ecl_function_dispatch(cl_env_copy,VV[83])(4, v14, v5ss, v6is, v7ts) /*  C1MAKE-VAR */;
    ecl_function_dispatch(cl_env_copy,VV[84])(1, v14) /*  PUSH-VARS   */;
L77:;
    {
     cl_object v19specs;
     v16 = ecl_cdr(v16);
     v19specs = v16;
     goto L85;
L84:;
     {
      cl_object v20name;
      cl_object v21var;
      cl_object v22init;
      cl_object v23flag;
      v20name = ecl_cadr(v19specs);
      v21var = ecl_function_dispatch(cl_env_copy,VV[83])(4, v20name, v5ss, v6is, v7ts) /*  C1MAKE-VAR */;
      v22init = ecl_caddr(v19specs);
      v23flag = ecl_cadddr(v19specs);
      if (Null(v22init)) { goto L94; }
      T0 = ecl_function_dispatch(cl_env_copy,VV[85])(1, v21var) /*  VAR-TYPE */;
      T1 = ecl_function_dispatch(cl_env_copy,VV[86])(1, v22init) /*  C1EXPR */;
      v22init = ecl_function_dispatch(cl_env_copy,VV[87])(6, T0, T1, v22init, VV[19], _ecl_static_7, v2block_name) /*  AND-FORM-TYPE */;
      goto L93;
L94:;
      v22init = ecl_function_dispatch(cl_env_copy,VV[88])(1, v21var) /*  DEFAULT-INIT */;
L93:;
      v9type_checks = CONS(v21var,v9type_checks);
      ecl_function_dispatch(cl_env_copy,VV[84])(1, v21var) /*  PUSH-VARS */;
      if (Null(v23flag)) { goto L99; }
      v23flag = ecl_function_dispatch(cl_env_copy,VV[83])(4, v23flag, v5ss, v6is, v7ts) /*  C1MAKE-VAR */;
      ecl_function_dispatch(cl_env_copy,VV[84])(1, v23flag) /*  PUSH-VARS */;
L99:;
      {
       cl_object v24;
       v24 = ecl_cdr(v19specs);
       if (ecl_unlikely(ECL_ATOM(v24))) FEtype_error_cons(v24);
       T0 = v24;
      }
      (ECL_CONS_CAR(T0)=v21var,T0);
      {
       cl_object v24;
       v24 = ecl_cddr(v19specs);
       if (ecl_unlikely(ECL_ATOM(v24))) FEtype_error_cons(v24);
       T0 = v24;
      }
      (ECL_CONS_CAR(T0)=v22init,T0);
      {
       cl_object v24;
       v24 = ecl_cdddr(v19specs);
       if (ecl_unlikely(ECL_ATOM(v24))) FEtype_error_cons(v24);
       T0 = v24;
      }
      (ECL_CONS_CAR(T0)=v23flag,T0);
     }
     v19specs = ecl_cddddr(v19specs);
L85:;
     if (ecl_endp(v19specs)) { goto L118; }
     goto L84;
L118:;
    }
    T0 = ecl_fdefinition(VV[89]);
    cl_set(VV[11],cl_reduce(4, T0, v8other_decls, VV[20], ecl_symbol_value(VV[11])));
    {
     cl_object v19declarations;
     cl_object v20type_checks;
     cl_object v21type_check_forms;
     cl_object v22let_vars;
     cl_object v23new_variables;
     cl_object v24already_declared_names;
     v19declarations = v8other_decls;
     v20type_checks = ecl_function_dispatch(cl_env_copy,VV[90])(6, v2block_name, v12, v13, v16, v7ts, v8other_decls) /*  EXTRACT-LAMBDA-TYPE-CHECKS */;
     v21type_check_forms = ecl_car(v20type_checks);
     {
      cl_object v25spec;
      T0 = ecl_cdr(v20type_checks);
      v25spec = ecl_nconc(T0,v18);
      {
       cl_object v26name;
       v26name = ECL_NIL;
       {
        cl_object v27init;
        v27init = ECL_NIL;
        {
         cl_object v28;
         cl_object v29;
         v28 = ecl_list1(ECL_NIL);
         v29 = v28;
L132:;
         if (!(ECL_ATOM(v25spec))) { goto L134; }
         goto L133;
L134:;
         v26name = ecl_car(v25spec);
         v27init = ecl_cadr(v25spec);
         if (ecl_unlikely(ECL_ATOM(v29))) FEtype_error_cons(v29);
         T0 = v29;
         T1 = cl_list(2, v26name, v27init);
         v29 = ecl_list1(T1);
         (ECL_CONS_CDR(T0)=v29,T0);
         v25spec = ecl_cddr(v25spec);
         goto L132;
L133:;
         v22let_vars = ecl_cdr(v28);
         goto L126;
        }
       }
      }
     }
L126:;
     v23new_variables = ecl_function_dispatch(cl_env_copy,VV[91])(2, ecl_symbol_value(VV[11]), v10old_env) /*  CMP-ENV-NEW-VARIABLES */;
     {
      cl_object v25;
      cl_object v26;
      v25 = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v23new_variables))) FEtype_error_list(v23new_variables);
      v26 = v23new_variables;
      {
       cl_object v27;
       cl_object v28;
       v27 = ecl_list1(ECL_NIL);
       v28 = v27;
L156:;
       if (!(ecl_endp(v26))) { goto L158; }
       goto L157;
L158:;
       v25 = _ecl_car(v26);
       {
        cl_object v29;
        v29 = _ecl_cdr(v26);
        if (ecl_unlikely(!ECL_LISTP(v29))) FEtype_error_list(v29);
        v26 = v29;
       }
       if (ecl_unlikely(ECL_ATOM(v28))) FEtype_error_cons(v28);
       T1 = v28;
       T2 = ecl_function_dispatch(cl_env_copy,VV[76])(1, v25) /*  VAR-NAME */;
       v28 = ecl_list1(T2);
       (ECL_CONS_CDR(T1)=v28,T1);
       goto L156;
L157:;
       T0 = ecl_cdr(v27);
       goto L150;
      }
     }
L150:;
     {
      cl_object v25;
      cl_object v26;
      v25 = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v22let_vars))) FEtype_error_list(v22let_vars);
      v26 = v22let_vars;
      {
       cl_object v27;
       cl_object v28;
       v27 = ecl_list1(ECL_NIL);
       v28 = v27;
L178:;
       if (!(ecl_endp(v26))) { goto L180; }
       goto L179;
L180:;
       v25 = _ecl_car(v26);
       {
        cl_object v29;
        v29 = _ecl_cdr(v26);
        if (ecl_unlikely(!ECL_LISTP(v29))) FEtype_error_list(v29);
        v26 = v29;
       }
       if (ecl_unlikely(ECL_ATOM(v28))) FEtype_error_cons(v28);
       T2 = v28;
       T3 = ecl_car(v25);
       v28 = ecl_list1(T3);
       (ECL_CONS_CDR(T2)=v28,T2);
       goto L178;
L179:;
       T1 = ecl_cdr(v27);
       goto L172;
      }
     }
L172:;
     v24already_declared_names = cl_set_difference(2, T0, T1);
     {
      cl_object v25specials;
      v25specials = cl_set_difference(2, v5ss, v24already_declared_names);
      if (Null(v25specials)) { goto L194; }
      T0 = CONS(ECL_SYM("SPECIAL",789),v25specials);
      v19declarations = CONS(T0,v19declarations);
     }
L194:;
     {
      cl_object v25ignorables;
      {
       cl_object v26var;
       cl_object v27expected_uses;
       cl_object v28;
       v26var = ECL_NIL;
       v27expected_uses = ECL_NIL;
       if (ecl_unlikely(!ECL_LISTP(v6is))) FEtype_error_list(v6is);
       v28 = v6is;
       {
        cl_object v29;
        cl_object v30;
        v29 = ecl_list1(ECL_NIL);
        v30 = v29;
L206:;
        if (!(ecl_endp(v28))) { goto L208; }
        goto L207;
L208:;
        {
         cl_object v31;
         v31 = _ecl_car(v28);
         v26var = ecl_car(v31);
         v31 = ecl_cdr(v31);
         v27expected_uses = v31;
        }
        {
         cl_object v31;
         v31 = _ecl_cdr(v28);
         if (ecl_unlikely(!ECL_LISTP(v31))) FEtype_error_list(v31);
         v28 = v31;
        }
        if ((ecl_memql(v26var,v24already_declared_names))!=ECL_NIL) { goto L221; }
        if (ecl_unlikely(ECL_ATOM(v30))) FEtype_error_cons(v30);
        T0 = v30;
        v30 = ecl_list1(v26var);
        (ECL_CONS_CDR(T0)=v30,T0);
L221:;
        goto L206;
L207:;
        v25ignorables = ecl_cdr(v29);
        goto L199;
       }
      }
L199:;
      if (Null(v25ignorables)) { goto L198; }
      T0 = CONS(ECL_SYM("IGNORABLE",427),v25ignorables);
      v19declarations = CONS(T0,v19declarations);
     }
L198:;
     {
      cl_object v25var;
      cl_object v26type;
      cl_object v27;
      v25var = ECL_NIL;
      v26type = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v7ts))) FEtype_error_list(v7ts);
      v27 = v7ts;
L235:;
      if (!(ecl_endp(v27))) { goto L237; }
      goto L236;
L237:;
      {
       cl_object v28;
       v28 = _ecl_car(v27);
       v25var = ecl_car(v28);
       v28 = ecl_cdr(v28);
       v26type = v28;
      }
      {
       cl_object v28;
       v28 = _ecl_cdr(v27);
       if (ecl_unlikely(!ECL_LISTP(v28))) FEtype_error_list(v28);
       v27 = v28;
      }
      if ((ecl_memql(v25var,v24already_declared_names))!=ECL_NIL) { goto L250; }
      T0 = cl_list(3, ECL_SYM("TYPE",869), v26type, v25var);
      v19declarations = CONS(T0,v19declarations);
L250:;
      goto L235;
L236:;
     }
     if ((v22let_vars)!=ECL_NIL) { goto L256; }
     if (Null(v19declarations)) { goto L254; }
     goto L255;
L256:;
L255:;
     T0 = CONS(ECL_SYM("DECLARE",274),v19declarations);
     T1 = cl_listX(4, ECL_SYM("LET*",478), v22let_vars, T0, v4body);
     v4body = ecl_list1(T1);
L254:;
     v4body = ecl_nconc(v21type_check_forms,v4body);
     T0 = ecl_function_dispatch(cl_env_copy,VV[81])(1, ecl_symbol_value(VV[11])) /*  CMP-ENV-COPY */;
     ecl_bds_bind(cl_env_copy,VV[11],T0);         /*  *CMP-ENV*       */
     v4body = ecl_function_dispatch(cl_env_copy,VV[92])(1, v4body) /*  C1PROGN */;
     ecl_bds_unwind1(cl_env_copy);
     {
      cl_object v25;
      v25 = v23new_variables;
      goto L267;
L266:;
      {
       cl_object v26var;
       v26var = ecl_car(v25);
       ecl_function_dispatch(cl_env_copy,VV[93])(1, v26var) /*  CHECK-VREF */;
      }
      v25 = ecl_cdr(v25);
L267:;
      if (Null(v25)) { goto L274; }
      goto L266;
L274:;
     }
     T0 = cl_list(6, v12, v13, v14, v15, v16, v17);
     value0 = ecl_function_dispatch(cl_env_copy,VV[94])(7, ECL_SYM("LAMBDA",452), VV[21], v23new_variables, VV[22], T0, v3doc, v4body) /*  MAKE-C1FORM* */;
     ecl_bds_unwind1(cl_env_copy);
     ecl_bds_unwind1(cl_env_copy);
     return value0;
    }
   }
  }
 }
}
/*	function definition for LAMBDA-FORM-ALLOWED-NARGS             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L12lambda_form_allowed_nargs(cl_object v1lambda)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2minarg;
   cl_object v3maxarg;
   v2minarg = ecl_make_fixnum(0);
   v3maxarg = ecl_make_fixnum(65536);
   {
    cl_object v4;
    cl_object v5;
    cl_object v6requireds;
    cl_object v7optionals;
    cl_object v8rest;
    cl_object v9key_flag;
    cl_object v10keywords;
    cl_object v11a_o_k;
    T0 = ecl_function_dispatch(cl_env_copy,VV[47])(1, v1lambda) /*  C1FORM-ARGS */;
    v4 = ecl_car(T0);
    v5 = v4;
    if (!(v5==ECL_NIL)) { goto L7; }
    si_dm_too_few_arguments(v4);
L7:;
    {
     cl_object v12;
     v12 = ecl_car(v5);
     v5 = ecl_cdr(v5);
     v6requireds = v12;
    }
    if (!(v5==ECL_NIL)) { goto L13; }
    si_dm_too_few_arguments(v4);
L13:;
    {
     cl_object v12;
     v12 = ecl_car(v5);
     v5 = ecl_cdr(v5);
     v7optionals = v12;
    }
    if (!(v5==ECL_NIL)) { goto L19; }
    si_dm_too_few_arguments(v4);
L19:;
    {
     cl_object v12;
     v12 = ecl_car(v5);
     v5 = ecl_cdr(v5);
     v8rest = v12;
    }
    if (!(v5==ECL_NIL)) { goto L25; }
    si_dm_too_few_arguments(v4);
L25:;
    {
     cl_object v12;
     v12 = ecl_car(v5);
     v5 = ecl_cdr(v5);
     v9key_flag = v12;
    }
    if (!(v5==ECL_NIL)) { goto L31; }
    si_dm_too_few_arguments(v4);
L31:;
    {
     cl_object v12;
     v12 = ecl_car(v5);
     v5 = ecl_cdr(v5);
     v10keywords = v12;
    }
    if (!(v5==ECL_NIL)) { goto L37; }
    si_dm_too_few_arguments(v4);
L37:;
    {
     cl_object v12;
     v12 = ecl_car(v5);
     v5 = ecl_cdr(v5);
     v11a_o_k = v12;
    }
    if (Null(v5)) { goto L42; }
    si_dm_too_many_arguments(v4);
L42:;
    if (!(v8rest==ECL_NIL)) { goto L3; }
    if ((v9key_flag)!=ECL_NIL) { goto L3; }
    if ((v11a_o_k)!=ECL_NIL) { goto L3; }
    v2minarg = ecl_make_fixnum(ecl_length(v6requireds));
    {
     cl_fixnum v12;
     v12 = ecl_length(v7optionals);
     T0 = ecl_divide(ecl_make_fixnum(v12),ecl_make_fixnum(3));
     v3maxarg = ecl_plus(v2minarg,T0);
    }
   }
L3:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v3maxarg;
   cl_env_copy->values[0] = v2minarg;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for C2LAMBDA-EXPR                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L16c2lambda_expr(cl_object v1lambda_list, cl_object v2body, cl_object v3cfun, cl_object v4fname, cl_object v5use_narg, cl_object v6required_lcls, cl_object v7closure_type)
{
 cl_object T0, T1, T2;
 volatile cl_object lex0[2];
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  lex0[0] = v6required_lcls;                      /*  REQUIRED-LCLS   */
  lex0[1] = v7closure_type;                       /*  CLOSURE-TYPE    */
TTL:
  {
   cl_object v8requireds;
   cl_object v9optionals;
   cl_object v10rest;
   cl_object v11rest_loc;
   cl_object v12keywords;
   cl_object v13allow_other_keys;
   cl_fixnum v14nreq;
   cl_object v15nopt;
   cl_fixnum v16nkey;
   cl_object v17varargs;
   cl_object v18fname_in_ihs_p;
   cl_object v19simple_varargs;
   v8requireds = ecl_car(v1lambda_list);
   v9optionals = ecl_cadr(v1lambda_list);
   v10rest = ecl_caddr(v1lambda_list);
   v11rest_loc = ECL_NIL;
   T0 = ecl_cddddr(v1lambda_list);
   v12keywords = ecl_car(T0);
   T0 = ecl_cddddr(v1lambda_list);
   v13allow_other_keys = ecl_cadr(T0);
   v14nreq = ecl_length(v8requireds);
   {
    cl_fixnum v20;
    v20 = ecl_length(v9optionals);
    v15nopt = ecl_divide(ecl_make_fixnum(v20),ecl_make_fixnum(3));
   }
   {
    cl_object v20;
    {
     cl_fixnum v21;
     v21 = ecl_length(v12keywords);
     v20 = ecl_divide(ecl_make_fixnum(v21),ecl_make_fixnum(4));
    }
    {
     bool v21;
     v21 = ECL_FIXNUMP(v20);
     if (ecl_unlikely(!(v21)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v20);
    }
    v16nkey = ecl_fixnum(v20);
   }
   value0 = v9optionals;
   if ((value0)!=ECL_NIL) { goto L14; }
   value0 = v10rest;
   if ((value0)!=ECL_NIL) { goto L14; }
   value0 = v12keywords;
   if ((value0)!=ECL_NIL) { goto L14; }
   v17varargs = v13allow_other_keys;
   goto L12;
L14:;
   v17varargs = value0;
   goto L12;
L12:;
   value0 = ecl_function_dispatch(cl_env_copy,VV[97])(0) /*  POLICY-DEBUG-VARIABLE-BINDINGS */;
   if ((value0)!=ECL_NIL) { goto L20; }
   if (Null(ecl_function_dispatch(cl_env_copy,VV[70])(0) /*  POLICY-DEBUG-IHS-FRAME */)) { goto L23; }
   v18fname_in_ihs_p = v4fname;
   goto L18;
L23:;
   v18fname_in_ihs_p = ECL_NIL;
   goto L18;
L20:;
   v18fname_in_ihs_p = value0;
   goto L18;
L18:;
   v19simple_varargs = ECL_NIL;
   ecl_bds_bind(cl_env_copy,VV[18],ECL_T);        /*  *PERMANENT-DATA* */
   ecl_bds_push(cl_env_copy,VV[24]);              /*  *UNWIND-EXIT*   */
   ecl_bds_push(cl_env_copy,VV[25]);              /*  *ENV*           */
   ecl_bds_bind(cl_env_copy,VV[26],ecl_make_fixnum(0)); /*  *INLINE-BLOCKS* */
   if (Null(v4fname)) { goto L27; }
   {
    cl_object v20;
    v20 = ecl_car(v1lambda_list);
    goto L34;
L33:;
    {
     cl_object v21var;
     {
      cl_object v22;
      v22 = ecl_car(v20);
      T0 = si_of_class_p(2, v22, VV[27]);
      if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[27],v22);
      v21var = v22;
     }
     if (Null(ecl_function_dispatch(cl_env_copy,VV[98])(1, v21var) /*  VAR-REF-CCB */)) { goto L40; }
     goto L27;
L40:;
    }
    v20 = ecl_cdr(v20);
L34:;
    if (Null(v20)) { goto L44; }
    goto L33;
L44:;
   }
   T0 = ecl_cadr(v1lambda_list);
   if (!(T0==ECL_NIL)) { goto L27; }
   T0 = ecl_caddr(v1lambda_list);
   if (!(T0==ECL_NIL)) { goto L27; }
   T0 = ecl_cadddr(v1lambda_list);
   if (!(T0==ECL_NIL)) { goto L27; }
   T0 = ecl_car(v1lambda_list);
   cl_set(VV[28],CONS(ecl_symbol_value(VV[28]),T0));
   goto L26;
L27:;
   cl_set(VV[28],ECL_NIL);
L26:;
   if (Null(ecl_function_dispatch(cl_env_copy,VV[99])(0) /*  POLICY-CHECK-NARGS */)) { goto L50; }
   if (Null(v5use_narg)) { goto L53; }
   if ((v17varargs)!=ECL_NIL) { goto L53; }
   ecl_function_dispatch(cl_env_copy,VV[100])(3, _ecl_static_8, ecl_make_fixnum(v14nreq), _ecl_static_9) /*  WT-NL */;
   goto L52;
L53:;
   if (Null(v17varargs)) { goto L52; }
   if (Null(v8requireds)) { goto L57; }
   ecl_function_dispatch(cl_env_copy,VV[100])(3, _ecl_static_10, ecl_make_fixnum(v14nreq), _ecl_static_9) /*  WT-NL */;
L57:;
   if ((v10rest)!=ECL_NIL) { goto L52; }
   if ((v12keywords)!=ECL_NIL) { goto L52; }
   if ((v13allow_other_keys)!=ECL_NIL) { goto L52; }
   T0 = ecl_plus(ecl_make_fixnum(v14nreq),v15nopt);
   ecl_function_dispatch(cl_env_copy,VV[100])(3, _ecl_static_11, T0, _ecl_static_9) /*  WT-NL */;
L52:;
   ecl_function_dispatch(cl_env_copy,VV[101])(0)  /*  OPEN-INLINE-BLOCK */;
L50:;
   if (!((v14nreq)>(63))) { goto L62; }
   T0 = ecl_minus(ecl_make_fixnum(v14nreq),ecl_make_fixnum(63));
   v15nopt = ecl_plus(v15nopt,T0);
   v14nreq = 63;
   {
    cl_object v20;
    cl_object v21var;
    cl_object v22;
    v20 = cl_subseq(2, v8requireds, ecl_make_fixnum(63));
    v21var = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
    v22 = v20;
    {
     cl_object v23;
     cl_object v24;
     v23 = ecl_list1(ECL_NIL);
     v24 = v23;
L77:;
     if (!(ecl_endp(v22))) { goto L79; }
     goto L78;
L79:;
     v21var = _ecl_car(v22);
     {
      cl_object v25;
      v25 = _ecl_cdr(v22);
      if (ecl_unlikely(!ECL_LISTP(v25))) FEtype_error_list(v25);
      v22 = v25;
     }
     {
      cl_object v25;
      v25 = cl_list(3, v21var, ecl_symbol_value(VV[29]), ECL_NIL);
      if (ecl_unlikely(ECL_ATOM(v24))) FEtype_error_cons(v24);
      T2 = v24;
      (ECL_CONS_CDR(T2)=v25,T2);
      T1 = v25;
     }
     v24 = ecl_cddr(T1);
     goto L77;
L78:;
     T0 = ecl_cdr(v23);
     goto L70;
    }
   }
L70:;
   v9optionals = ecl_nconc(T0,v9optionals);
   v8requireds = cl_subseq(3, v8requireds, ecl_make_fixnum(0), ecl_make_fixnum(63));
   v17varargs = ECL_T;
L62:;
   {
    cl_object v20var;
    cl_object v21;
    v20var = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v8requireds))) FEtype_error_list(v8requireds);
    v21 = v8requireds;
L104:;
    if (!(ecl_endp(v21))) { goto L106; }
    goto L105;
L106:;
    v20var = _ecl_car(v21);
    {
     cl_object v22;
     v22 = _ecl_cdr(v21);
     if (ecl_unlikely(!ECL_LISTP(v22))) FEtype_error_list(v22);
     v21 = v22;
    }
    if (Null(ecl_function_dispatch(cl_env_copy,VV[102])(1, v20var) /*  UNBOXED */)) { goto L114; }
    {
     cl_object v22;
     v22 = LC13wt_decl(v20var);
     ecl_structure_set(v20var,VV[27],10,v22);
    }
L114:;
    goto L104;
L105:;
   }
   if (Null(v10rest)) { goto L118; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[103])(1, v10rest) /*  VAR-REF */;
   if (!(ecl_number_compare(T0,ecl_make_fixnum(1))<0)) { goto L118; }
   v10rest = ECL_NIL;
   value0 = v9optionals;
   if ((value0)!=ECL_NIL) { goto L125; }
   value0 = v12keywords;
   if ((value0)!=ECL_NIL) { goto L125; }
   v17varargs = v13allow_other_keys;
   goto L123;
L125:;
   v17varargs = value0;
   goto L123;
L123:;
L118:;
   {
    cl_object v20opt;
    v20opt = v9optionals;
    goto L132;
L131:;
    T0 = ecl_car(v20opt);
    LC14do_decl(T0);
    if (Null(ecl_caddr(v20opt))) { goto L135; }
    T0 = ecl_caddr(v20opt);
    LC14do_decl(T0);
L135:;
    v20opt = ecl_cdddr(v20opt);
L132:;
    if (ecl_endp(v20opt)) { goto L139; }
    goto L131;
L139:;
   }
   if (Null(v10rest)) { goto L141; }
   v11rest_loc = LC13wt_decl(v10rest);
L141:;
   {
    cl_object v20key;
    v20key = v12keywords;
    goto L147;
L146:;
    T0 = ecl_cadr(v20key);
    LC14do_decl(T0);
    if (Null(ecl_cadddr(v20key))) { goto L150; }
    T0 = ecl_cadddr(v20key);
    LC14do_decl(T0);
L150:;
    v20key = ecl_cddddr(v20key);
L147:;
    if (ecl_endp(v20key)) { goto L154; }
    goto L146;
L154:;
   }
   if (Null(v17varargs)) { goto L156; }
   if ((v10rest)!=ECL_NIL) { goto L162; }
   if ((v12keywords)!=ECL_NIL) { goto L162; }
   if ((v13allow_other_keys)!=ECL_NIL) { goto L162; }
   T0 = ecl_plus(ecl_make_fixnum(v14nreq),v15nopt);
   v19simple_varargs = ecl_make_bool(ecl_number_compare(T0,ecl_make_fixnum(30))<0);
   goto L160;
L162:;
   v19simple_varargs = ECL_NIL;
   goto L160;
L160:;
   if (Null(v19simple_varargs)) { goto L158; }
   T0 = LC15last_variable(lex0);
   ecl_function_dispatch(cl_env_copy,VV[100])(3, _ecl_static_16, T0, _ecl_static_17) /*  WT-NL */;
   goto L156;
L158:;
   T0 = LC15last_variable(lex0);
   ecl_function_dispatch(cl_env_copy,VV[100])(5, _ecl_static_18, T0, _ecl_static_19, ecl_make_fixnum(v14nreq), _ecl_static_17) /*  WT-NL */;
L156:;
   {
    cl_object v20;
    cl_object v21;
    v20 = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(lex0[0]))) FEtype_error_list(lex0[0]);
    v21 = lex0[0];
    {
     cl_object v22;
     cl_object v23;
     v22 = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v8requireds))) FEtype_error_list(v8requireds);
     v23 = v8requireds;
L175:;
     if (!(ecl_endp(v21))) { goto L177; }
     goto L176;
L177:;
     v20 = _ecl_car(v21);
     {
      cl_object v24;
      v24 = _ecl_cdr(v21);
      if (ecl_unlikely(!ECL_LISTP(v24))) FEtype_error_list(v24);
      v21 = v24;
     }
     if (!(ecl_endp(v23))) { goto L185; }
     goto L176;
L185:;
     v22 = _ecl_car(v23);
     {
      cl_object v24;
      v24 = _ecl_cdr(v23);
      if (ecl_unlikely(!ECL_LISTP(v24))) FEtype_error_list(v24);
      v23 = v24;
     }
     ecl_function_dispatch(cl_env_copy,VV[104])(2, v20, v22) /*  BIND */;
     goto L175;
L176:;
     goto L168;
    }
   }
L168:;
   if (Null(v18fname_in_ihs_p)) { goto L196; }
   ecl_function_dispatch(cl_env_copy,VV[101])(0)  /*  OPEN-INLINE-BLOCK */;
   cl_set(VV[33],ECL_T);
   cl_set(VV[24],CONS(VV[34],ecl_symbol_value(VV[24])));
   if (Null(ecl_function_dispatch(cl_env_copy,VV[97])(0) /*  POLICY-DEBUG-VARIABLE-BINDINGS */)) { goto L203; }
   T0 = cl_reverse(v8requireds);
   ecl_function_dispatch(cl_env_copy,VV[105])(2, T0, ECL_T) /*  BUILD-DEBUG-LEXICAL-ENV */;
L203:;
   T0 = ecl_function_dispatch(cl_env_copy,VV[106])(1, v4fname) /*  ADD-SYMBOL */;
   ecl_function_dispatch(cl_env_copy,VV[100])(3, _ecl_static_20, T0, _ecl_static_21) /*  WT-NL */;
L196:;
   if (Null(v9optionals)) { goto L205; }
   {
    cl_object v20va_arg_loc;
    if (Null(v19simple_varargs)) { goto L208; }
    v20va_arg_loc = VV[35];
    goto L207;
L208:;
    v20va_arg_loc = VV[36];
L207:;
    ecl_function_dispatch(cl_env_copy,VV[107])(0) /*  WT-NL-OPEN-BRACE */;
    ecl_function_dispatch(cl_env_copy,VV[100])(3, _ecl_static_22, ecl_make_fixnum(v14nreq), _ecl_static_13) /*  WT-NL */;
    {
     cl_object v21opt;
     v21opt = v9optionals;
     goto L216;
L215:;
     ecl_function_dispatch(cl_env_copy,VV[100])(1, _ecl_static_23) /*  WT-NL */;
     T0 = ecl_one_plus(ecl_symbol_value(VV[37]));
     ecl_bds_bind(cl_env_copy,VV[37],T0);         /*  *OPENED-C-BRACES* */
     T0 = ecl_cadr(v21opt);
     T1 = ecl_car(v21opt);
     ecl_function_dispatch(cl_env_copy,VV[108])(2, T0, T1) /*  BIND-INIT */;
     if (Null(ecl_caddr(v21opt))) {
     ecl_bds_unwind1(cl_env_copy);
      goto L219;
     }
     T0 = ecl_caddr(v21opt);
     ecl_function_dispatch(cl_env_copy,VV[104])(2, ECL_NIL, T0) /*  BIND */;
     ecl_bds_unwind1(cl_env_copy);
L219:;
     ecl_function_dispatch(cl_env_copy,VV[100])(1, _ecl_static_24) /*  WT-NL */;
     {
      cl_object v22;
      cl_object v23;
      v22 = ecl_one_plus(ecl_symbol_value(VV[37]));
      v23 = ecl_symbol_value(VV[24]);
      ecl_bds_bind(cl_env_copy,VV[37],v22);       /*  *OPENED-C-BRACES* */
      ecl_bds_bind(cl_env_copy,VV[24],v23);       /*  *UNWIND-EXIT*   */
      ecl_function_dispatch(cl_env_copy,VV[100])(1, _ecl_static_25) /*  WT-NL */;
      T0 = ecl_car(v21opt);
      ecl_function_dispatch(cl_env_copy,VV[104])(2, v20va_arg_loc, T0) /*  BIND */;
      if (Null(ecl_caddr(v21opt))) {
      ecl_bds_unwind1(cl_env_copy);
      ecl_bds_unwind1(cl_env_copy);
       goto L223;
      }
      T0 = ecl_caddr(v21opt);
      ecl_function_dispatch(cl_env_copy,VV[104])(2, ECL_T, T0) /*  BIND */;
      ecl_bds_unwind1(cl_env_copy);
      ecl_bds_unwind1(cl_env_copy);
     }
L223:;
     ecl_function_dispatch(cl_env_copy,VV[100])(1, _ecl_static_26) /*  WT-NL */;
     v21opt = ecl_cdddr(v21opt);
L216:;
     if (ecl_endp(v21opt)) { goto L232; }
     goto L215;
L232:;
    }
    ecl_function_dispatch(cl_env_copy,VV[109])(0) /*  WT-NL-CLOSE-BRACE */;
   }
L205:;
   if ((v10rest)!=ECL_NIL) { goto L236; }
   if ((v12keywords)!=ECL_NIL) { goto L236; }
   if (Null(v13allow_other_keys)) { goto L234; }
   goto L235;
L236:;
L235:;
   if ((v12keywords)!=ECL_NIL) { goto L240; }
   if ((v13allow_other_keys)!=ECL_NIL) { goto L240; }
   ecl_function_dispatch(cl_env_copy,VV[100])(2, v11rest_loc, _ecl_static_27) /*  WT-NL */;
   goto L239;
L240:;
   if (Null(v12keywords)) { goto L244; }
   ecl_function_dispatch(cl_env_copy,VV[107])(0)  /*  WT-NL-OPEN-BRACE */;
   T0 = ecl_times(ecl_make_fixnum(2),ecl_make_fixnum(v16nkey));
   ecl_function_dispatch(cl_env_copy,VV[100])(3, _ecl_static_28, T0, _ecl_static_29) /*  WT-NL */;
   ecl_function_dispatch(cl_env_copy,VV[100])(5, _ecl_static_30, ecl_make_fixnum(v16nkey), _ecl_static_31, v3cfun, _ecl_static_32) /*  WT-NL */;
   goto L243;
L244:;
   ecl_function_dispatch(cl_env_copy,VV[100])(1, _ecl_static_33) /*  WT-NL */;
L243:;
   if (Null(v10rest)) { goto L249; }
   ecl_function_dispatch(cl_env_copy,VV[110])(2, _ecl_static_34, v11rest_loc) /*  WT */;
   goto L248;
L249:;
   ecl_function_dispatch(cl_env_copy,VV[110])(1, _ecl_static_35) /*  WT */;
L248:;
   if (Null(v13allow_other_keys)) { goto L252; }
   T0 = _ecl_static_36;
   goto L251;
L252:;
   T0 = _ecl_static_37;
L251:;
   ecl_function_dispatch(cl_env_copy,VV[110])(1, T0) /*  WT           */;
L239:;
   if (Null(v10rest)) { goto L234; }
   ecl_function_dispatch(cl_env_copy,VV[104])(2, v11rest_loc, v10rest) /*  BIND */;
L234:;
   if (Null(v17varargs)) { goto L255; }
   if (Null(v19simple_varargs)) { goto L258; }
   T0 = _ecl_static_38;
   goto L257;
L258:;
   T0 = _ecl_static_39;
L257:;
   ecl_function_dispatch(cl_env_copy,VV[100])(1, T0) /*  WT-NL        */;
L255:;
   {
    cl_object v20kwd;
    cl_object v21all_kwd;
    cl_fixnum v22i;
    v20kwd = v12keywords;
    v21all_kwd = ECL_NIL;
    v22i = 0;
    goto L266;
L265:;
    T0 = ecl_car(v20kwd);
    v21all_kwd = CONS(T0,v21all_kwd);
    {
     cl_object v23;
     cl_object v24;
     cl_object v25;
     cl_object v26;
     v23 = ecl_car(v20kwd);
     v24 = ecl_cadr(v20kwd);
     v25 = ecl_caddr(v20kwd);
     v26 = ecl_cadddr(v20kwd);
     T0 = ecl_function_dispatch(cl_env_copy,VV[111])(1, v25) /*  C1FORM-NAME */;
     if (!((T0)==(ECL_SYM("LOCATION",1763)))) { goto L276; }
     T0 = ecl_function_dispatch(cl_env_copy,VV[47])(1, v25) /*  C1FORM-ARGS */;
     T1 = ecl_car(T0);
     if (!(T1==ECL_NIL)) { goto L276; }
     {
      cl_object v27;
      v27 = ecl_cdr(VV[38]);
      if (ecl_unlikely(ECL_ATOM(v27))) FEtype_error_cons(v27);
      T0 = v27;
     }
     (ECL_CONS_CAR(T0)=ecl_make_fixnum(v22i),T0);
     ecl_function_dispatch(cl_env_copy,VV[104])(2, VV[38], v24) /*  BIND */;
     goto L275;
L276:;
     {
      cl_object v27;
      v27 = ecl_plus(ecl_make_fixnum(v16nkey),ecl_make_fixnum(v22i));
      {
       cl_object v28;
       v28 = ecl_cdr(VV[38]);
       if (ecl_unlikely(ECL_ATOM(v28))) FEtype_error_cons(v28);
       T0 = v28;
      }
      (ECL_CONS_CAR(T0)=v27,T0);
     }
     ecl_function_dispatch(cl_env_copy,VV[100])(1, _ecl_static_40) /*  WT-NL */;
     ecl_function_dispatch(cl_env_copy,VV[112])(1, VV[38]) /*  WT-LOC */;
     ecl_function_dispatch(cl_env_copy,VV[110])(1, _ecl_static_41) /*  WT */;
     {
      cl_object v27;
      cl_object v28;
      v27 = ecl_symbol_value(VV[24]);
      v28 = ecl_one_plus(ecl_symbol_value(VV[37]));
      ecl_bds_bind(cl_env_copy,VV[24],v27);       /*  *UNWIND-EXIT*   */
      ecl_bds_bind(cl_env_copy,VV[37],v28);       /*  *OPENED-C-BRACES* */
      ecl_function_dispatch(cl_env_copy,VV[108])(2, v25, v24) /*  BIND-INIT */;
      ecl_bds_unwind1(cl_env_copy);
      ecl_bds_unwind1(cl_env_copy);
     }
     ecl_function_dispatch(cl_env_copy,VV[100])(1, _ecl_static_24) /*  WT-NL */;
     T0 = ecl_one_plus(ecl_symbol_value(VV[37]));
     ecl_bds_bind(cl_env_copy,VV[37],T0);         /*  *OPENED-C-BRACES* */
     {
      cl_object v27;
      v27 = ecl_cdr(VV[38]);
      if (ecl_unlikely(ECL_ATOM(v27))) FEtype_error_cons(v27);
      T0 = v27;
     }
     (ECL_CONS_CAR(T0)=ecl_make_fixnum(v22i),T0);
     ecl_function_dispatch(cl_env_copy,VV[104])(2, VV[38], v24) /*  BIND */;
     ecl_bds_unwind1(cl_env_copy);
     ecl_function_dispatch(cl_env_copy,VV[100])(1, _ecl_static_26) /*  WT-NL */;
L275:;
     if (Null(v26)) { goto L270; }
     {
      cl_object v27;
      v27 = ecl_plus(ecl_make_fixnum(v16nkey),ecl_make_fixnum(v22i));
      {
       cl_object v28;
       v28 = ecl_cdr(VV[38]);
       if (ecl_unlikely(ECL_ATOM(v28))) FEtype_error_cons(v28);
       T0 = v28;
      }
      (ECL_CONS_CAR(T0)=v27,T0);
     }
     ecl_function_dispatch(cl_env_copy,VV[104])(2, VV[38], v26) /*  BIND */;
    }
L270:;
    v20kwd = ecl_cddddr(v20kwd);
    {
     cl_object v23;
     v23 = ecl_make_integer((v22i)+1);
     {
      bool v24;
      v24 = ECL_FIXNUMP(v23);
      if (ecl_unlikely(!(v24)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v23);
     }
     v22i = ecl_fixnum(v23);
    }
L266:;
    if (ecl_endp(v20kwd)) { goto L315; }
    goto L265;
L315:;
    if (Null(v21all_kwd)) { goto L260; }
    T0 = cl_nreverse(v21all_kwd);
    T1 = ecl_function_dispatch(cl_env_copy,VV[113])(1, T0) /*  ADD-KEYWORDS */;
    ecl_function_dispatch(cl_env_copy,VV[114])(5, _ecl_static_42, v3cfun, _ecl_static_43, T1, _ecl_static_44) /*  WT-NL-H */;
    ecl_function_dispatch(cl_env_copy,VV[109])(0) /*  WT-NL-CLOSE-BRACE */;
   }
L260:;
   if (Null(ecl_symbol_value(VV[28]))) { goto L319; }
   cl_set(VV[24],CONS(VV[39],ecl_symbol_value(VV[24])));
   ecl_function_dispatch(cl_env_copy,VV[115])(1, _ecl_static_45) /*  WT-NL1 */;
L319:;
   ecl_function_dispatch(cl_env_copy,VV[116])(1, v2body) /*  C2EXPR   */;
   value0 = ecl_function_dispatch(cl_env_copy,VV[117])(0) /*  CLOSE-INLINE-BLOCKS */;
   ecl_bds_unwind_n(cl_env_copy,4);
   return value0;
  }
 }
}
/*	local function DO-DECL                                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC14do_decl(cl_object v1var)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[118])(1, v1var) /*  LOCAL */)) { goto L1; }
  {
   cl_object v2;
   v2 = LC13wt_decl(v1var);
   value0 = ecl_structure_set(v1var,VV[27],10,v2);
   cl_env_copy->nvalues = 1;
   return value0;
  }
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function WT-DECL                                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC13wt_decl(cl_object v1var)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2lcl;
   T0 = ecl_function_dispatch(cl_env_copy,VV[76])(1, v1var) /*  VAR-NAME */;
   v2lcl = ecl_function_dispatch(cl_env_copy,VV[119])(1, T0) /*  NEXT-LCL */;
   ecl_function_dispatch(cl_env_copy,VV[100])(0)  /*  WT-NL           */;
   T0 = ecl_symbol_value(VV[30]);
   T1 = ecl_function_dispatch(cl_env_copy,VV[120])(1, v1var) /*  VAR-REP-TYPE */;
   T2 = ecl_function_dispatch(cl_env_copy,VV[121])(1, T1) /*  REP-TYPE-NAME */;
   ecl_function_dispatch(cl_env_copy,VV[110])(5, T0, T2, _ecl_static_12, v2lcl, _ecl_static_13) /*  WT */;
   value0 = v2lcl;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function LAST-VARIABLE                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC15last_variable(volatile cl_object *lex0)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(lex0[0])) { goto L1; }
  T0 = ecl_last(lex0[0],1);
  value0 = ecl_car(T0);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (!((lex0[1])==(VV[31]))) { goto L3; }
  T0 = ecl_one_minus(ecl_symbol_value(VV[32]));
  value0 = cl_format(3, ECL_NIL, _ecl_static_14, T0);
  return value0;
L3:;
  value0 = _ecl_static_15;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for OPTIMIZE-FUNCALL/APPLY-LAMBDA         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L17optimize_funcall_apply_lambda(cl_object v1lambda_form, cl_object v2arguments, cl_object v3apply_p)
{
 cl_object T0, T1, T2, T3, T4, T5;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4apply_list;
   cl_object v5apply_var;
   cl_object v6let_vars;
   cl_object v7extra_stmts;
   cl_object v8all_keys;
   v4apply_list = ECL_NIL;
   v5apply_var = ECL_NIL;
   v6let_vars = ECL_NIL;
   v7extra_stmts = ECL_NIL;
   v8all_keys = ECL_NIL;
   {
    cl_object v10;                                /*  REQUIREDS       */
    cl_object v11;                                /*  OPTIONALS       */
    cl_object v12;                                /*  REST            */
    cl_object v13;                                /*  KEY-FLAG        */
    cl_object v14;                                /*  KEYWORDS        */
    cl_object v15;                                /*  ALLOW-OTHER-KEYS */
    cl_object v16;                                /*  AUX-VARS        */
    T0 = ecl_car(v1lambda_form);
    value0 = L10cmp_process_lambda_list(T0);
    v10 = value0;
    {
     const int v17 = cl_env_copy->nvalues;
     cl_object v18;
     v18 = (v17<=1)? ECL_NIL : cl_env_copy->values[1];
     v11 = v18;
     v18 = (v17<=2)? ECL_NIL : cl_env_copy->values[2];
     v12 = v18;
     v18 = (v17<=3)? ECL_NIL : cl_env_copy->values[3];
     v13 = v18;
     v18 = (v17<=4)? ECL_NIL : cl_env_copy->values[4];
     v14 = v18;
     v18 = (v17<=5)? ECL_NIL : cl_env_copy->values[5];
     v15 = v18;
     v18 = (v17<=6)? ECL_NIL : cl_env_copy->values[6];
     v16 = v18;
    }
    if (Null(v3apply_p)) { goto L7; }
    T0 = ecl_last(v2arguments,1);
    v4apply_list = ecl_car(T0);
    v5apply_var = cl_gensym(0);
    v2arguments = ecl_butlast(v2arguments,1);
L7:;
    v2arguments = cl_copy_list(v2arguments);
    {
     cl_object v17scan;
     v17scan = v2arguments;
     goto L20;
L19:;
     {
      cl_object v18form;
      v18form = ecl_car(v17scan);
      if ((cl_constantp(1, v18form))!=ECL_NIL) { goto L22; }
      {
       cl_object v19aux_var;
       v19aux_var = cl_gensym(0);
       T0 = cl_list(2, v19aux_var, v18form);
       v6let_vars = CONS(T0,v6let_vars);
       if (ecl_unlikely(ECL_ATOM(v17scan))) FEtype_error_cons(v17scan);
       T0 = v17scan;
       (ECL_CONS_CAR(T0)=v19aux_var,T0);
      }
     }
L22:;
     v17scan = ecl_cdr(v17scan);
L20:;
     if (ecl_endp(v17scan)) { goto L33; }
     goto L19;
L33:;
    }
    if (Null(v5apply_var)) { goto L35; }
    T0 = cl_list(2, v5apply_var, v4apply_list);
    v6let_vars = CONS(T0,v6let_vars);
L35:;
    {
     cl_object v17;
     v17 = ecl_cdr(v10);
     goto L42;
L41:;
     {
      cl_object v18i;
      v18i = ecl_car(v17);
      if (Null(v2arguments)) { goto L49; }
      {
       cl_object v19;
       v19 = v2arguments;
       if (ecl_unlikely(!ECL_LISTP(v19))) FEtype_error_list(v19);
       if (Null(v19)) { goto L54; }
       {
        cl_object v20;
        v20 = ECL_CONS_CDR(v19);
        v2arguments = v20;
        v19 = ECL_CONS_CAR(v19);
       }
L54:;
       T0 = v19;
       goto L48;
      }
L49:;
      if (Null(v3apply_p)) { goto L60; }
      T1 = cl_list(2, ECL_SYM("POP",643), v5apply_var);
      T0 = cl_list(4, ECL_SYM("IF",946), v5apply_var, T1, VV[41]);
      goto L48;
L60:;
      T1 = CONS(ECL_SYM("LAMBDA",452),v1lambda_form);
      T0 = ecl_function_dispatch(cl_env_copy,VV[80])(2, _ecl_static_46, T1) /*  CMPERR */;
L48:;
      T1 = cl_list(2, v18i, T0);
      v6let_vars = CONS(T1,v6let_vars);
     }
     v17 = ecl_cdr(v17);
L42:;
     if (Null(v17)) { goto L64; }
     goto L41;
L64:;
    }
    {
     cl_object v17scan;
     v17scan = ecl_cdr(v11);
     goto L70;
L69:;
     {
      cl_object v18;
      cl_object v19;
      cl_object v20;
      v18 = ecl_car(v17scan);
      v19 = ecl_caddr(v17scan);
      v20 = ecl_cadr(v17scan);
      if (Null(v2arguments)) { goto L76; }
      {
       cl_object v21;
       v21 = v2arguments;
       if (ecl_unlikely(!ECL_LISTP(v21))) FEtype_error_list(v21);
       if (Null(v21)) { goto L83; }
       {
        cl_object v22;
        v22 = ECL_CONS_CDR(v21);
        v2arguments = v22;
        v21 = ECL_CONS_CAR(v21);
       }
L83:;
       T0 = v21;
      }
      T1 = cl_list(2, v18, T0);
      T2 = cl_list(2, v19, ECL_T);
      v6let_vars = cl_listX(3, T1, T2, v6let_vars);
      goto L72;
L76:;
      if (Null(v3apply_p)) { goto L89; }
      T0 = cl_list(2, ECL_SYM("POP",643), v5apply_var);
      T1 = cl_list(4, ECL_SYM("IF",946), v5apply_var, T0, v20);
      T2 = cl_list(2, v18, T1);
      T3 = cl_list(2, v19, v5apply_var);
      v6let_vars = cl_listX(3, T2, T3, v6let_vars);
      goto L72;
L89:;
      T0 = cl_list(2, v18, v20);
      T1 = cl_list(2, v19, ECL_NIL);
      v6let_vars = cl_listX(3, T0, T1, v6let_vars);
     }
L72:;
     v17scan = ecl_cdddr(v17scan);
L70:;
     if (ecl_endp(v17scan)) { goto L95; }
     goto L69;
L95:;
    }
    if ((v13)!=ECL_NIL) { goto L99; }
    if (Null(v15)) { goto L97; }
    goto L98;
L99:;
L98:;
    if ((v12)!=ECL_NIL) { goto L97; }
    v12 = cl_gensym(0);
L97:;
    if (Null(v12)) { goto L103; }
    if (Null(v2arguments)) { goto L107; }
    if (Null(v3apply_p)) { goto L109; }
    T1 = ecl_list1(v5apply_var);
    T2 = ecl_append(v2arguments,T1);
    T0 = CONS(ECL_SYM("LIST*",482),T2);
    goto L106;
L109:;
    T0 = CONS(ECL_SYM("LIST",481),v2arguments);
    goto L106;
L107:;
    if (Null(v3apply_p)) { goto L111; }
    T0 = v5apply_var;
    goto L106;
L111:;
    T0 = ECL_NIL;
L106:;
    T1 = cl_list(2, v12, T0);
    v6let_vars = CONS(T1,v6let_vars);
L103:;
L114:;
    if ((v16)!=ECL_NIL) { goto L116; }
    goto L115;
L116:;
    {
     cl_object v17;
     v17 = v16;
     if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
     if (Null(v17)) { goto L124; }
     {
      cl_object v18;
      v18 = ECL_CONS_CDR(v17);
      v16 = v18;
      v17 = ECL_CONS_CAR(v17);
     }
L124:;
     T0 = v17;
    }
    {
     cl_object v17;
     v17 = v16;
     if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
     if (Null(v17)) { goto L134; }
     {
      cl_object v18;
      v18 = ECL_CONS_CDR(v17);
      v16 = v18;
      v17 = ECL_CONS_CAR(v17);
     }
L134:;
     T1 = v17;
    }
    T2 = cl_list(2, T0, T1);
    v6let_vars = CONS(T2,v6let_vars);
    goto L114;
L115:;
    {
     cl_object v17scan;
     v17scan = ecl_cdr(v14);
     goto L145;
L144:;
     {
      cl_object v18;
      cl_object v19;
      cl_object v20;
      cl_object v21;
      v18 = ecl_car(v17scan);
      v19 = ecl_cadr(v17scan);
      v20 = ecl_caddr(v17scan);
      value0 = ecl_cadddr(v17scan);
      if ((value0)!=ECL_NIL) { goto L153; }
      v21 = cl_gensym(0);
      goto L151;
L153:;
      v21 = value0;
      goto L151;
L151:;
      v8all_keys = CONS(v18,v8all_keys);
      T0 = cl_list(3, ECL_SYM("EQ",333), v21, VV[42]);
      T1 = cl_list(4, ECL_SYM("IF",946), T0, v20, v21);
      T2 = cl_list(2, v19, T1);
      T3 = cl_list(3, VV[43], v12, v18);
      T4 = cl_list(2, v21, T3);
      v6let_vars = cl_listX(3, T2, T4, v6let_vars);
      if (Null(ecl_cadddr(v17scan))) { goto L147; }
      T0 = cl_list(3, ECL_SYM("EQ",333), v21, VV[42]);
      T1 = cl_list(2, ECL_SYM("NOT",584), T0);
      T2 = cl_list(3, ECL_SYM("SETF",750), v21, T1);
      v7extra_stmts = CONS(T2,v7extra_stmts);
     }
L147:;
     v17scan = ecl_cddddr(v17scan);
L145:;
     if (ecl_endp(v17scan)) { goto L163; }
     goto L144;
L163:;
    }
    if (Null(v13)) { goto L165; }
    if ((v15)!=ECL_NIL) { goto L165; }
    T0 = cl_list(2, ECL_SYM("QUOTE",679), v8all_keys);
    T1 = cl_list(3, VV[44], v12, T0);
    v7extra_stmts = CONS(T1,v7extra_stmts);
L165:;
    T0 = (ECL_SYM("FIRST",371)->symbol.gfdef);
    T1 = cl_delete_if_not(2, T0, v6let_vars);
    T2 = cl_nreverse(T1);
    if (Null(v5apply_var)) { goto L172; }
    T4 = cl_list(2, ECL_SYM("IGNORABLE",427), v5apply_var);
    T5 = cl_list(2, ECL_SYM("DECLARE",274), T4);
    T3 = ecl_list1(T5);
    goto L170;
L172:;
    T3 = ECL_NIL;
    goto L170;
L170:;
    {
     cl_object v18;                               /*  DECL            */
     cl_object v19;                               /*  BODY            */
     T5 = ecl_cdr(v1lambda_form);
     value0 = si_find_declarations(1, T5);
     v18 = value0;
     {
      const int v20 = cl_env_copy->nvalues;
      cl_object v21;
      v21 = (v20<=1)? ECL_NIL : cl_env_copy->values[1];
      v19 = v21;
     }
     T4 = cl_append(3, v18, v7extra_stmts, v19);
    }
    T5 = ecl_append(T3,T4);
    value0 = cl_listX(3, ECL_SYM("LET*",478), T2, T5);
    return value0;
   }
  }
 }
}

#include "cmp/cmplam.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclq5f2zk4hMNlk9_ZMqtVE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPLAM.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclq5f2zk4hMNlk9_ZMqtVE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[46]);                           /*  C1LAMBDA-DOC    */
 ecl_cmp_defun(VV[48]);                           /*  C1LAMBDA-BODY   */
 ecl_cmp_defun(VV[49]);                           /*  C1LAMBDA-LIST   */
 ecl_cmp_defun(VV[50]);                           /*  FUN-NEEDS-NARG  */
 ecl_cmp_defun(VV[51]);                           /*  FUN-FIXED-NARG  */
 ecl_cmp_defun(VV[55]);                           /*  ADD-TO-FUN-REFERENCED-VARS */
 ecl_cmp_defun(VV[58]);                           /*  ADD-TO-FUN-REFERENCED-FUNS */
 ecl_cmp_defun(VV[62]);                           /*  C1COMPILE-FUNCTION */
 ecl_cmp_defun(VV[79]);                           /*  CMP-PROCESS-LAMBDA-LIST */
 (void)0; /* No entry created for C1LAMBDA-EXPR */
 ecl_cmp_defun(VV[95]);                           /*  LAMBDA-FORM-ALLOWED-NARGS */
 ecl_cmp_defun(VV[96]);                           /*  C2LAMBDA-EXPR   */
 ecl_cmp_defun(VV[122]);                          /*  OPTIMIZE-FUNCALL/APPLY-LAMBDA */
}
