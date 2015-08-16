/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CLOS;METHOD.LSP                                   */
#include <ecl/ecl-cmp.h>
#include "clos/method.eclh"
/*	function definition for GENERIC-FUNCTION-METHOD-CLASS         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1generic_function_method_class(cl_object v1generic_function)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_symbol_value(VV[3]))) { goto L1; }
  value0 = cl_slot_value(v1generic_function, VV[4]);
  return value0;
L1:;
  value0 = cl_find_class(1, ECL_SYM("STANDARD-METHOD",975));
  return value0;
 }
}
/*	local function DEFMETHOD                                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC2defmethod(cl_object v1, cl_object v2env)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4name;
   cl_object v5args;
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
   v5args = v3;
   {
    cl_object v6qualifiers;
    cl_object v7specialized_lambda_list;
    ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-LENGTH*",50),ecl_make_fixnum(3)); /*  *PRINT-LENGTH* */
    {
     cl_object v8;
     cl_object v9;
     v8 = ecl_list1(ECL_NIL);
     v9 = v8;
L12:;
     if (Null(v5args)) { goto L17; }
     T0 = ecl_car(v5args);
     if (!(ECL_LISTP(T0))) { goto L14; }
     goto L15;
L17:;
     goto L15;
L15:;
     goto L13;
L14:;
     if (ecl_unlikely(ECL_ATOM(v9))) FEtype_error_cons(v9);
     T0 = v9;
     {
      cl_object v10;
      v10 = v5args;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L27; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v5args = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L27:;
      T1 = v10;
     }
     v9 = ecl_list1(T1);
     (ECL_CONS_CDR(T0)=v9,T0);
     goto L12;
L13:;
     v6qualifiers = ecl_cdr(v8);
     goto L9;
    }
L9:;
    if (Null(v5args)) { goto L36; }
    {
     cl_object v8;
     v8 = v5args;
     if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
     if (Null(v8)) { goto L41; }
     {
      cl_object v9;
      v9 = ECL_CONS_CDR(v8);
      v5args = v9;
      v8 = ECL_CONS_CAR(v8);
     }
L41:;
     v7specialized_lambda_list = v8;
     goto L35;
    }
L36:;
    v7specialized_lambda_list = cl_error(1, _ecl_static_1);
L35:;
    {
     cl_object v9;                                /*  LAMBDA-LIST     */
     cl_object v10;                               /*  REQUIRED-PARAMETERS */
     cl_object v11;                               /*  SPECIALIZERS    */
     value0 = L16parse_specialized_lambda_list(v7specialized_lambda_list);
     v9 = value0;
     {
      const int v12 = cl_env_copy->nvalues;
      cl_object v13;
      v13 = (v12<=1)? ECL_NIL : cl_env_copy->values[1];
      v10 = v13;
      v13 = (v12<=2)? ECL_NIL : cl_env_copy->values[2];
      v11 = v13;
     }
     {
      cl_object v13;                              /*  LAMBDA-FORM     */
      cl_object v14;                              /*  DOCUMENTATION   */
      value0 = L6make_raw_lambda(v4name, v9, v10, v11, v5args, v2env);
      v13 = value0;
      {
       const int v15 = cl_env_copy->nvalues;
       cl_object v16;
       v16 = (v15<=2)? ECL_NIL : cl_env_copy->values[2];
       v14 = v16;
      }
      {
       cl_object v15generic_function;
       cl_object v16method_class;
       cl_object v17method;
       v15generic_function = (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(1, v4name) /*  ENSURE-GENERIC-FUNCTION */;
       v16method_class = L1generic_function_method_class(v15generic_function);
       v17method = ECL_NIL;
       if (Null(ecl_symbol_value(VV[3]))) { goto L52; }
       if (!(ECL_SYMBOLP(v16method_class))) { goto L54; }
       v16method_class = cl_find_class(2, v16method_class, ECL_NIL);
L54:;
       if (Null(v16method_class)) { goto L57; }
       v17method = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-PROTOTYPE",1493))(1, v16method_class) /*  CLASS-PROTOTYPE */;
       goto L52;
L57:;
       T0 = cl_type_of(v15generic_function);
       cl_error(2, _ecl_static_2, T0);
L52:;
       {
        cl_object v19;                            /*  FN-FORM         */
        cl_object v20;                            /*  OPTIONS         */
        value0 = ecl_function_dispatch(cl_env_copy,VV[14])(4, v15generic_function, v17method, v13, v2env) /*  MAKE-METHOD-LAMBDA */;
        v19 = value0;
        {
         const int v21 = cl_env_copy->nvalues;
         cl_object v22;
         v22 = (v21<=1)? ECL_NIL : cl_env_copy->values[1];
         v20 = v22;
        }
        if (Null(v14)) { goto L61; }
        v20 = cl_listX(3, ECL_SYM("DOCUMENTATION",1222), v14, v20);
L61:;
        {
         cl_object v22;                           /*  WRAPPED-LAMBDA  */
         cl_object v23;                           /*  WRAPPED-P       */
         value0 = L5simplify_lambda(v4name, v19);
         v22 = value0;
         {
          const int v24 = cl_env_copy->nvalues;
          cl_object v25;
          v25 = (v24<=1)? ECL_NIL : cl_env_copy->values[1];
          v23 = v25;
         }
         if ((v23)!=ECL_NIL) { goto L65; }
         cl_error(1, _ecl_static_3);
L65:;
         if (Null(ecl_symbol_value(ECL_SYM("*REGISTER-WITH-PDE-HOOK*",1181)))) { goto L67; }
         T0 = ecl_symbol_value(ECL_SYM("*REGISTER-WITH-PDE-HOOK*",1181));
         T1 = cl_copy_tree(ecl_symbol_value(ECL_SYM("*SOURCE-LOCATION*",1180)));
         T2 = cl_list(2, ECL_SYM("QUOTE",679), v4name);
         T3 = cl_list(2, ECL_SYM("QUOTE",679), v6qualifiers);
         T4 = L3specializers_expression(v11);
         T5 = cl_list(2, ECL_SYM("QUOTE",679), v9);
         T6 = L4maybe_remove_block(v22);
         {
          cl_object v24;
          cl_object v25;
          v24 = ECL_NIL;
          if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
          v25 = v20;
          {
          cl_object v26;
          cl_object v27;
          v26 = ecl_list1(ECL_NIL);
          v27 = v26;
L76:;
          if (!(ecl_endp(v25))) { goto L78; }
          goto L77;
L78:;
          v24 = _ecl_car(v25);
          {
          cl_object v28;
          v28 = _ecl_cdr(v25);
          if (ecl_unlikely(!ECL_LISTP(v28))) FEtype_error_list(v28);
          v25 = v28;
          }
          if (ecl_unlikely(ECL_ATOM(v27))) FEtype_error_cons(v27);
          T8 = v27;
          T9 = ecl_function_dispatch(cl_env_copy,ECL_SYM("MAYBE-QUOTE",1686))(1, v24) /*  MAYBE-QUOTE */;
          v27 = ecl_list1(T9);
          (ECL_CONS_CDR(T8)=v27,T8);
          goto L76;
L77:;
          T7 = ecl_cdr(v26);
          goto L70;
          }
         }
L70:;
         T8 = cl_listX(8, VV[6], T2, T3, T4, T5, T6, v23, T7);
         value0 = ecl_function_dispatch(cl_env_copy,T0)(3, T1, v1, T8);
         ecl_bds_unwind1(cl_env_copy);
         return value0;
L67:;
         T0 = cl_list(2, ECL_SYM("QUOTE",679), v4name);
         T1 = cl_list(2, ECL_SYM("QUOTE",679), v6qualifiers);
         T2 = L3specializers_expression(v11);
         T3 = cl_list(2, ECL_SYM("QUOTE",679), v9);
         T4 = L4maybe_remove_block(v22);
         {
          cl_object v24;
          cl_object v25;
          v24 = ECL_NIL;
          if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
          v25 = v20;
          {
          cl_object v26;
          cl_object v27;
          v26 = ecl_list1(ECL_NIL);
          v27 = v26;
L98:;
          if (!(ecl_endp(v25))) { goto L100; }
          goto L99;
L100:;
          v24 = _ecl_car(v25);
          {
          cl_object v28;
          v28 = _ecl_cdr(v25);
          if (ecl_unlikely(!ECL_LISTP(v28))) FEtype_error_list(v28);
          v25 = v28;
          }
          if (ecl_unlikely(ECL_ATOM(v27))) FEtype_error_cons(v27);
          T6 = v27;
          T7 = ecl_function_dispatch(cl_env_copy,ECL_SYM("MAYBE-QUOTE",1686))(1, v24) /*  MAYBE-QUOTE */;
          v27 = ecl_list1(T7);
          (ECL_CONS_CDR(T6)=v27,T6);
          goto L98;
L99:;
          T5 = ecl_cdr(v26);
          goto L92;
          }
         }
L92:;
         value0 = cl_listX(8, VV[6], T0, T1, T2, T3, T4, v23, T5);
         ecl_bds_unwind1(cl_env_copy);
         return value0;
        }
       }
      }
     }
    }
   }
  }
 }
}
/*	function definition for SPECIALIZERS-EXPRESSION               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3specializers_expression(cl_object v1specializers)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2spec;
   cl_object v3;
   v2spec = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v1specializers))) FEtype_error_list(v1specializers);
   v3 = v1specializers;
   {
    cl_object v4;
    cl_object v5;
    v4 = ecl_list1(ECL_NIL);
    v5 = v4;
L7:;
    if (!(ecl_endp(v3))) { goto L9; }
    goto L8;
L9:;
    v2spec = _ecl_car(v3);
    {
     cl_object v6;
     v6 = _ecl_cdr(v3);
     if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
     v3 = v6;
    }
    if (ecl_unlikely(ECL_ATOM(v5))) FEtype_error_cons(v5);
    T1 = v5;
    if (!(ECL_ATOM(v2spec))) { goto L22; }
    T2 = v2spec;
    goto L21;
L22:;
    {
     cl_object v6value;
     v6value = ecl_cadr(v2spec);
     if (Null(cl_constantp(1, v6value))) { goto L26; }
     T3 = cl_eval(v6value);
     goto L24;
L26:;
     T3 = cl_list(2, ECL_SYM("UNQUOTE",1035), v6value);
    }
L24:;
    T2 = cl_list(2, ECL_SYM("EQL",334), T3);
L21:;
    v5 = ecl_list1(T2);
    (ECL_CONS_CDR(T1)=v5,T1);
    goto L7;
L8:;
    T0 = ecl_cdr(v4);
    goto L1;
   }
  }
L1:;
  value0 = cl_list(2, ECL_SYM("QUASIQUOTE",1471), T0);
  return value0;
 }
}
/*	function definition for MAYBE-REMOVE-BLOCK                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4maybe_remove_block(cl_object v1method_lambda)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_car(v1method_lambda);
  if (!((T0)==(ECL_SYM("LAMBDA",452)))) { goto L1; }
  {
   cl_object v3;                                  /*  DECLARATIONS    */
   cl_object v4;                                  /*  BODY            */
   T0 = ecl_cddr(v1method_lambda);
   value0 = si_find_declarations(1, T0);
   v3 = value0;
   {
    const int v5 = cl_env_copy->nvalues;
    cl_object v6;
    v6 = (v5<=1)? ECL_NIL : cl_env_copy->values[1];
    v4 = v6;
   }
   {
    cl_object v5block;
    v5block = ECL_NIL;
    T0 = ecl_cdr(v4);
    if (!(T0==ECL_NIL)) { goto L1; }
    v5block = ecl_car(v4);
    if (!(ECL_LISTP(v5block))) { goto L1; }
    T0 = ecl_car(v5block);
    if (!((T0)==(ECL_SYM("BLOCK",137)))) { goto L1; }
    T0 = ecl_cadr(v5block);
    T1 = ecl_cadr(v1method_lambda);
    T2 = ecl_cddr(v5block);
    T3 = ecl_append(v3,T2);
    v1method_lambda = cl_listX(4, ECL_SYM("LAMBDA-BLOCK",1339), T0, T1, T3);
   }
  }
L1:;
  value0 = v1method_lambda;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for SIMPLIFY-LAMBDA                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5simplify_lambda(cl_object v1method_name, cl_object v2fn_form)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3aux;
   v3aux = v2fn_form;
   {
    cl_object v4;
    v4 = v3aux;
    if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
    if (Null(v4)) { goto L9; }
    {
     cl_object v5;
     v5 = ECL_CONS_CDR(v4);
     v3aux = v5;
     v4 = ECL_CONS_CAR(v4);
    }
L9:;
    T0 = v4;
   }
   if (!((T0)==(ECL_SYM("LAMBDA",452)))) { goto L2; }
   {
    cl_object v4;
    v4 = v3aux;
    if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
    if (Null(v4)) { goto L20; }
    {
     cl_object v5;
     v5 = ECL_CONS_CDR(v4);
     v3aux = v5;
     v4 = ECL_CONS_CAR(v4);
    }
L20:;
    T0 = v4;
   }
   if (!(ecl_equalp(T0,VV[9]))) { goto L2; }
   {
    cl_object v4;
    v4 = v3aux;
    if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
    if (Null(v4)) { goto L31; }
    {
     cl_object v5;
     v5 = ECL_CONS_CDR(v4);
     v3aux = v5;
     v4 = ECL_CONS_CAR(v4);
    }
L31:;
    T0 = v4;
   }
   if (!(ecl_equalp(T0,VV[10]))) { goto L2; }
   T0 = ecl_cdr(v3aux);
   if (!(T0==ECL_NIL)) { goto L2; }
   v3aux = ecl_car(v3aux);
   {
    cl_fixnum v4;
    v4 = ecl_length(v3aux);
    if (!((v4)==(3))) { goto L2; }
   }
   T0 = ecl_car(v3aux);
   if (!((T0)==(ECL_SYM("APPLY",89)))) { goto L2; }
   T0 = ecl_caddr(v3aux);
   if (!((T0)==(ECL_SYM(".COMBINED-METHOD-ARGS.",1473)))) { goto L2; }
   v3aux = ecl_cadr(v3aux);
   if (!(ECL_LISTP(v3aux))) { goto L2; }
   T0 = ecl_car(v3aux);
   if (!((T0)==(ECL_SYM("LAMBDA",452)))) { goto L2; }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = ECL_T;
   cl_env_copy->values[0] = v3aux;
   return cl_env_copy->values[0];
L2:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = ECL_NIL;
   cl_env_copy->values[0] = v2fn_form;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for MAKE-RAW-LAMBDA                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6make_raw_lambda(cl_object v1name, cl_object v2lambda_list, cl_object v3required_parameters, cl_object v4specializers, cl_object v5body, cl_object v6env)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v8;                                  /*  DECLARATIONS    */
   cl_object v9;                                  /*  REAL-BODY       */
   cl_object v10;                                 /*  DOCUMENTATION   */
   value0 = si_find_declarations(1, v5body);
   v8 = value0;
   {
    const int v11 = cl_env_copy->nvalues;
    cl_object v12;
    v12 = (v11<=1)? ECL_NIL : cl_env_copy->values[1];
    v9 = v12;
    v12 = (v11<=2)? ECL_NIL : cl_env_copy->values[2];
    v10 = v12;
   }
   if (Null(ecl_memql(ECL_SYM("&KEY",10),v2lambda_list))) { goto L2; }
   if ((ecl_memql(ECL_SYM("&ALLOW-OTHER-KEYS",6),v2lambda_list))!=ECL_NIL) { goto L2; }
   {
    cl_object v11x;
    v11x = cl_position(2, ECL_SYM("&AUX",7), v2lambda_list);
    T0 = cl_subseq(3, v2lambda_list, ecl_make_fixnum(0), v11x);
    if (Null(v11x)) { goto L9; }
    T1 = cl_subseq(2, v2lambda_list, v11x);
    goto L7;
L9:;
    T1 = ECL_NIL;
    goto L7;
L7:;
    v2lambda_list = cl_append(4, T0, VV[12], T1, ECL_NIL);
   }
L2:;
   {
    cl_object v11copied_variables;
    cl_object v12ignorable;
    cl_object v13class_declarations;
    cl_object v14block;
    cl_object v15method_lambda;
    v11copied_variables = ECL_NIL;
    T0 = CONS(ECL_SYM("IGNORABLE",427),v3required_parameters);
    v12ignorable = cl_list(2, ECL_SYM("DECLARE",274), T0);
    if (Null(ecl_symbol_value(VV[2]))) { goto L15; }
    {
     cl_object v16name;
     cl_object v17;
     v16name = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v3required_parameters))) FEtype_error_list(v3required_parameters);
     v17 = v3required_parameters;
     {
      cl_object v18type;
      cl_object v19;
      v18type = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v4specializers))) FEtype_error_list(v4specializers);
      v19 = v4specializers;
      {
       cl_object v20;
       cl_object v21;
       v20 = ecl_list1(ECL_NIL);
       v21 = v20;
L25:;
       if (!(ecl_endp(v17))) { goto L27; }
       goto L26;
L27:;
       v16name = _ecl_car(v17);
       {
        cl_object v22;
        v22 = _ecl_cdr(v17);
        if (ecl_unlikely(!ECL_LISTP(v22))) FEtype_error_list(v22);
        v17 = v22;
       }
       if (!(ecl_endp(v19))) { goto L35; }
       goto L26;
L35:;
       v18type = _ecl_car(v19);
       {
        cl_object v22;
        v22 = _ecl_cdr(v19);
        if (ecl_unlikely(!ECL_LISTP(v22))) FEtype_error_list(v22);
        v19 = v22;
       }
       if ((v18type)==(ECL_T)) { goto L43; }
       if (!(ECL_SYMBOLP(v18type))) { goto L43; }
       T1 = cl_list(2, v16name, v16name);
       v11copied_variables = CONS(T1,v11copied_variables);
       {
        cl_object v22;
        T2 = cl_list(3, ECL_SYM("TYPE",869), v18type, v16name);
        T3 = cl_list(2, VV[13], v16name);
        v22 = cl_list(2, T2, T3);
        if (ecl_unlikely(ECL_ATOM(v21))) FEtype_error_cons(v21);
        T2 = v21;
        (ECL_CONS_CDR(T2)=v22,T2);
        T1 = v22;
       }
       v21 = ecl_cdr(T1);
L43:;
       goto L25;
L26:;
       T0 = ecl_cdr(v20);
       goto L14;
      }
     }
    }
L15:;
    T0 = ECL_NIL;
L14:;
    T1 = ecl_cdar(v8);
    v13class_declarations = ecl_nconc(T0,T1);
    T0 = si_function_block_name(v1name);
    v14block = cl_listX(3, ECL_SYM("BLOCK",137), T0, v9);
    if (Null(v13class_declarations)) { goto L60; }
    T1 = CONS(ECL_SYM("DECLARE",274),v13class_declarations);
    T0 = ecl_list1(T1);
    goto L58;
L60:;
    T0 = ECL_NIL;
    goto L58;
L58:;
    if (Null(v11copied_variables)) { goto L63; }
    T1 = cl_list(4, ECL_SYM("LET*",478), v11copied_variables, v12ignorable, v14block);
    goto L62;
L63:;
    T1 = v14block;
L62:;
    T2 = cl_list(2, v12ignorable, T1);
    T3 = ecl_append(T0,T2);
    v15method_lambda = cl_listX(3, ECL_SYM("LAMBDA",452), v2lambda_list, T3);
    cl_env_copy->nvalues = 3;
    cl_env_copy->values[2] = v10;
    cl_env_copy->values[1] = v8;
    cl_env_copy->values[0] = v15method_lambda;
    return cl_env_copy->values[0];
   }
  }
 }
}
/*	function definition for MAKE-METHOD-LAMBDA                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7make_method_lambda(cl_object v1gf, cl_object v2method, cl_object v3method_lambda, cl_object v4env)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6;                                  /*  IN-CLOSURE-P    */
   value0 = L11walk_method_lambda(v3method_lambda, v4env);
   {
    const int v7 = cl_env_copy->nvalues;
    cl_object v8;
    v8 = (v7<=2)? ECL_NIL : cl_env_copy->values[2];
    v6 = v8;
   }
   if (Null(v6)) { goto L3; }
   T0 = L8add_call_next_method_closure(v3method_lambda);
   goto L2;
L3:;
   T0 = v3method_lambda;
L2:;
   T1 = cl_list(3, ECL_SYM("APPLY",89), T0, ECL_SYM(".COMBINED-METHOD-ARGS.",1473));
   T2 = cl_list(4, ECL_SYM("LAMBDA",452), VV[9], VV[10], T1);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = ECL_NIL;
   cl_env_copy->values[0] = T2;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for ADD-CALL-NEXT-METHOD-CLOSURE          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8add_call_next_method_closure(cl_object v1method_lambda)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;                                  /*  REAL-BODY       */
   T0 = ecl_cddr(v1method_lambda);
   value0 = si_find_declarations(1, T0);
   {
    const int v4 = cl_env_copy->nvalues;
    cl_object v5;
    v5 = (v4<=1)? ECL_NIL : cl_env_copy->values[1];
    v3 = v5;
   }
   T0 = ecl_cadr(v1method_lambda);
   T1 = cl_listX(3, ECL_SYM("FLET",373), VV[16], v3);
   T2 = cl_list(3, ECL_SYM("LET*",478), VV[15], T1);
   value0 = cl_list(3, ECL_SYM("LAMBDA",452), T0, T2);
   return value0;
  }
 }
}
/*	function definition for ENVIRONMENT-CONTAINS-CLOSURE          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L9environment_contains_closure(cl_object v1env)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v2counter;
   v2counter = 0;
   {
    cl_object v3;
    v3 = ecl_car(v1env);
    goto L5;
L4:;
    {
     cl_object v4item;
     v4item = ecl_car(v3);
     if (!(ECL_CONSP(v4item))) { goto L9; }
     if (ecl_unlikely(ECL_ATOM(v4item))) FEtype_error_cons(v4item);
     T0 = v4item;
     T1 = ecl_car(T0);
     if (!((T1)==(ECL_SYM("FUNCTION-BOUNDARY",1833)))) { goto L9; }
     {
      cl_fixnum v5;
      {
       cl_object v6;
       v6 = ecl_plus(ecl_make_fixnum(v2counter),ecl_make_fixnum(1));
       {
        bool v7;
        v7 = ECL_FIXNUMP(v6);
        if (ecl_unlikely(!(v7)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v6);
       }
       v2counter = ecl_fixnum(v6);
      }
      v5 = v2counter;
      if (!((v5)>(1))) { goto L9; }
     }
     value0 = ECL_T;
     cl_env_copy->nvalues = 1;
     return value0;
L9:;
    }
    v3 = ecl_cdr(v3);
L5:;
    if (Null(v3)) { goto L21; }
    goto L4;
L21:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for WALK-METHOD-LAMBDA                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L11walk_method_lambda(cl_object v1method_lambda, cl_object v2env)
{
 cl_object T0, T1;
 cl_object env0;
 cl_object CLV0, CLV1, CLV2
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object env1 = env0;
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(ECL_NIL,env1);              /*  CALL-NEXT-METHOD-P */
   CLV1 = env1 = CONS(ECL_NIL,env1);              /*  NEXT-METHOD-P-P */
   CLV2 = env1 = CONS(ECL_NIL,env1);              /*  IN-CLOSURE-P    */
   {cl_object v3;
    v3 = ECL_NIL;
    v3 = ecl_make_cclosure_va((cl_objectfn)LC10code_walker,env1,Cblock);
    ecl_bds_bind(cl_env_copy,ECL_SYM("*CODE-WALKER*",1588),v3); /*  *CODE-WALKER* */
    si_eval_with_env(5, v1method_lambda, v2env, ECL_NIL, ECL_T, ECL_T);
    ecl_bds_unwind1(cl_env_copy);
   }
   T0 = ECL_CONS_CAR(CLV0);
   T1 = ECL_CONS_CAR(CLV1);
   cl_env_copy->nvalues = 3;
   cl_env_copy->values[2] = ECL_CONS_CAR(CLV2);
   cl_env_copy->values[1] = T1;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	closure CODE-WALKER                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC10code_walker(cl_narg narg, cl_object v1form, cl_object v2env, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1, CLV2
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV2 = env0;                                     /*  IN-CLOSURE-P    */
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  if (ECL_ATOM(v1form)) { goto L1; }
  {
   cl_object v3name;
   v3name = ecl_car(v1form);
   if (!((v3name)==(ECL_SYM("CALL-NEXT-METHOD",931)))) { goto L4; }
   value0 = ECL_CONS_CAR(CLV0);
   if ((value0)!=ECL_NIL) { goto L9; }
   ECL_CONS_CAR(CLV0) = ECL_T;
   goto L7;
L9:;
   ECL_CONS_CAR(CLV0) = value0;
   goto L7;
L7:;
   value0 = ECL_CONS_CAR(CLV2);
   if ((value0)!=ECL_NIL) { goto L13; }
   ECL_CONS_CAR(CLV2) = L9environment_contains_closure(v2env);
   goto L11;
L13:;
   ECL_CONS_CAR(CLV2) = value0;
   goto L11;
L11:;
   goto L1;
L4:;
   if (!((v3name)==(ECL_SYM("NEXT-METHOD-P",958)))) { goto L15; }
   ECL_CONS_CAR(CLV1) = ECL_T;
   value0 = ECL_CONS_CAR(CLV2);
   if ((value0)!=ECL_NIL) { goto L21; }
   ECL_CONS_CAR(CLV2) = L9environment_contains_closure(v2env);
   goto L19;
L21:;
   ECL_CONS_CAR(CLV2) = value0;
   goto L19;
L19:;
   goto L1;
L15:;
   if (!((v3name)==(ECL_SYM("FUNCTION",396)))) { goto L1; }
   T0 = ecl_cadr(v1form);
   if (!((T0)==(ECL_SYM("CALL-NEXT-METHOD",931)))) { goto L24; }
   ECL_CONS_CAR(CLV2) = ECL_T;
   ECL_CONS_CAR(CLV0) = ECL_SYM("FUNCTION",396);
L24:;
   T0 = ecl_cadr(v1form);
   if (!((T0)==(ECL_SYM("NEXT-METHOD-P",958)))) { goto L1; }
   ECL_CONS_CAR(CLV1) = ECL_SYM("FUNCTION",396);
   ECL_CONS_CAR(CLV2) = ECL_T;
  }
L1:;
  value0 = v1form;
  cl_env_copy->nvalues = 1;
  return value0;
 }
 }
}
/*	function definition for LEGAL-GENERIC-FUNCTION-NAME-P         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L12legal_generic_function_name_p(cl_object v1name)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = si_valid_function_name_p(v1name);
  return value0;
 }
}
/*	function definition for PARSE-DEFMETHOD                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L13parse_defmethod(cl_object v1args)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2name;
   v2name = ECL_NIL;
   if ((v1args)!=ECL_NIL) { goto L2; }
   cl_error(1, _ecl_static_4);
L2:;
   {
    cl_object v3;
    v3 = v1args;
    if (ecl_unlikely(!ECL_LISTP(v3))) FEtype_error_list(v3);
    if (Null(v3)) { goto L9; }
    {
     cl_object v4;
     v4 = ECL_CONS_CDR(v3);
     v1args = v4;
     v3 = ECL_CONS_CAR(v3);
    }
L9:;
    v2name = v3;
   }
   if ((L12legal_generic_function_name_p(v2name))!=ECL_NIL) { goto L15; }
   cl_error(2, _ecl_static_5, v2name);
L15:;
   {
    cl_object v3qualifiers;
    v3qualifiers = ECL_NIL;
    goto L20;
L19:;
    {
     cl_object v4;
     v4 = v1args;
     if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
     if (Null(v4)) { goto L28; }
     {
      cl_object v5;
      v5 = ECL_CONS_CDR(v4);
      v1args = v5;
      v4 = ECL_CONS_CAR(v4);
     }
L28:;
     T0 = v4;
    }
    v3qualifiers = CONS(T0,v3qualifiers);
L20:;
    if (!(ecl_endp(v1args))) { goto L36; }
    cl_error(1, _ecl_static_6);
L36:;
    T0 = ecl_car(v1args);
    if (ECL_LISTP(T0)) { goto L34; }
    goto L19;
L34:;
    T0 = cl_nreverse(v3qualifiers);
    T1 = ecl_car(v1args);
    T2 = ecl_cdr(v1args);
    cl_env_copy->nvalues = 4;
    cl_env_copy->values[3] = T2;
    cl_env_copy->values[2] = T1;
    cl_env_copy->values[1] = T0;
    cl_env_copy->values[0] = v2name;
    return cl_env_copy->values[0];
   }
  }
 }
}
/*	function definition for EXTRACT-LAMBDA-LIST                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L14extract_lambda_list(cl_object v1specialized_lambda_list)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L16parse_specialized_lambda_list(v1specialized_lambda_list);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for EXTRACT-SPECIALIZER-NAMES             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L15extract_specializer_names(cl_object v1specialized_lambda_list)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   struct ecl_stack_frame _ecl_inner_frame_aux;
   cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
   {
    cl_object v2;
    v2 = _ecl_inner_frame;
    cl_env_copy->values[0] = L16parse_specialized_lambda_list(v1specialized_lambda_list);
    ecl_stack_frame_push_values(v2);cl_env_copy->values[0]=ecl_apply_from_stack_frame(v2,ECL_SYM("LIST",481));
    value0 = cl_env_copy->values[0];
   }
   ecl_stack_frame_close(_ecl_inner_frame);
  }
  T0 = value0;
  value0 = ecl_caddr(T0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for PARSE-SPECIALIZED-LAMBDA-LIST         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L16parse_specialized_lambda_list(cl_object v1specialized_lambda_list)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2arglist;
   cl_object v3lambda_list;
   cl_object v4ll;
   cl_object v5required_parameters;
   cl_object v6specializers;
   cl_object v7arg;
   cl_object v8variable;
   cl_object v9specializer;
   T0 = si_process_lambda_list(v1specialized_lambda_list, ECL_SYM("METHOD",954));
   v2arglist = ecl_cdr(T0);
   v3lambda_list = cl_copy_list(v1specialized_lambda_list);
   v4ll = v3lambda_list;
   v5required_parameters = ECL_NIL;
   v6specializers = ECL_NIL;
   v7arg = ECL_NIL;
   v8variable = ECL_NIL;
   v9specializer = ECL_NIL;
   goto L11;
L10:;
   v7arg = ecl_car(v2arglist);
   if (!(ECL_ATOM(v7arg))) { goto L16; }
   v8variable = v7arg;
   v9specializer = ECL_T;
   goto L15;
L16:;
   T0 = ecl_cddr(v7arg);
   if (ecl_endp(T0)) { goto L21; }
   si_simple_program_error(2, _ecl_static_7, v7arg);
   goto L15;
L21:;
   v8variable = ecl_car(v7arg);
   v9specializer = ecl_cadr(v7arg);
   if (!(v9specializer==ECL_NIL)) { goto L23; }
   si_simple_program_error(1, _ecl_static_8);
   goto L15;
L23:;
   {
    cl_object v10;
    v10 = ecl_make_bool(ECL_ATOM(v9specializer));
    if (Null(v10)) { goto L29; }
    goto L15;
L29:;
    {
     cl_object v11;
     T0 = ecl_car(v9specializer);
     if (!((T0)==(ECL_SYM("EQL",334)))) { goto L33; }
     if (Null(ecl_cdr(v9specializer))) { goto L33; }
     T0 = ecl_cddr(v9specializer);
     v11 = ecl_make_bool(ecl_endp(T0));
     goto L31;
L33:;
     v11 = ECL_NIL;
     goto L31;
L31:;
     if (Null(v11)) { goto L36; }
     goto L15;
L36:;
     si_simple_program_error(2, _ecl_static_7, v7arg);
    }
   }
L15:;
   if (ecl_unlikely(ECL_ATOM(v4ll))) FEtype_error_cons(v4ll);
   T0 = v4ll;
   (ECL_CONS_CAR(T0)=v8variable,T0);
   v5required_parameters = CONS(v8variable,v5required_parameters);
   v6specializers = CONS(v9specializer,v6specializers);
   v2arglist = ecl_cdr(v2arglist);
   v4ll = ecl_cdr(v4ll);
L11:;
   if (v2arglist==ECL_NIL) { goto L50; }
   goto L10;
L50:;
   T0 = cl_nreverse(v5required_parameters);
   T1 = cl_nreverse(v6specializers);
   cl_env_copy->nvalues = 3;
   cl_env_copy->values[2] = T1;
   cl_env_copy->values[1] = T0;
   cl_env_copy->values[0] = v3lambda_list;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for DECLARATION-SPECIALIZERS              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L17declaration_specializers(cl_object v1arglist, cl_object v2declarations)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4argscan;
   cl_object v5declist;
   if (Null(v2declarations)) { goto L2; }
   v3 = ecl_cdr(v2declarations);
   goto L1;
L2:;
   v3 = ECL_NIL;
L1:;
   v4argscan = v1arglist;
   v5declist = v3;
   goto L8;
L7:;
   T0 = ecl_car(v4argscan);
   if (!(ECL_LISTP(T0))) { goto L10; }
   T0 = ecl_cadar(v4argscan);
   T1 = ecl_caar(v4argscan);
   T2 = cl_list(3, ECL_SYM("TYPE",869), T0, T1);
   v5declist = CONS(T2,v5declist);
L10:;
   v4argscan = ecl_cdr(v4argscan);
L8:;
   if (v4argscan==ECL_NIL) { goto L15; }
   T0 = ecl_car(v4argscan);
   if ((ecl_memql(T0,VV[22]))!=ECL_NIL) { goto L15; }
   goto L7;
L15:;
   value0 = CONS(ECL_SYM("DECLARE",274),v5declist);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for COMPUTE-METHOD-KEYWORDS               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L18compute_method_keywords(cl_object v1lambda_list)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;                                  /*  KEYWORDS        */
   cl_object v4;                                  /*  ALLOW-OTHER-KEYS */
   value0 = si_process_lambda_list(v1lambda_list, ECL_T);
   {
    const int v5 = cl_env_copy->nvalues;
    cl_object v6;
    v6 = (v5<=4)? ECL_NIL : cl_env_copy->values[4];
    v3 = v6;
    v6 = (v5<=5)? ECL_NIL : cl_env_copy->values[5];
    v4 = v6;
   }
   if (Null(v4)) { goto L2; }
   value0 = ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
   {
    cl_object v5;
    cl_object v6k;
    cl_object v7;
    v5 = ecl_cdr(v3);
    v6k = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
    v7 = v5;
    {
     cl_object v8;
     cl_object v9;
     v8 = ecl_list1(ECL_NIL);
     v9 = v8;
L10:;
     if (!(ecl_endp(v7))) { goto L12; }
     goto L11;
L12:;
     v6k = _ecl_car(v7);
     {
      cl_object v10;
      v10 = ecl_cddddr(v7);
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      v7 = v10;
     }
     if (ecl_unlikely(ECL_ATOM(v9))) FEtype_error_cons(v9);
     T0 = v9;
     v9 = ecl_list1(v6k);
     (ECL_CONS_CDR(T0)=v9,T0);
     goto L10;
L11:;
     value0 = ecl_cdr(v8);
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
  }
 }
}
/*	function definition for MAKE-METHOD                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L19make_method(cl_object v1method_class, cl_object v2qualifiers, cl_object v3specializers, cl_object v4lambda_list, cl_object v5fun, cl_object v6options)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v7_class;
   cl_object v8method;
   if (!(ECL_INSTANCEP(v1method_class))) { goto L2; }
   v7_class = v1method_class;
   goto L1;
L2:;
   v7_class = cl_find_class(1, v1method_class);
L1:;
   v8method = si_allocate_raw_instance(ECL_NIL, v7_class, ecl_make_fixnum(9));
   si_instance_set(v8method, ecl_make_fixnum(0), ECL_NIL);
   si_instance_set(v8method, ecl_make_fixnum(1), v4lambda_list);
   si_instance_set(v8method, ecl_make_fixnum(2), v3specializers);
   si_instance_set(v8method, ecl_make_fixnum(3), v2qualifiers);
   si_instance_set(v8method, ecl_make_fixnum(4), v5fun);
   si_instance_set(v8method, ecl_make_fixnum(5), ECL_NIL);
   si_instance_set(v8method, ecl_make_fixnum(6), ECL_NIL);
   si_instance_set(v8method, ecl_make_fixnum(7), ECL_NIL);
   si_instance_set(v8method, ecl_make_fixnum(8), ECL_NIL);
   if (Null(v7_class)) { goto L14; }
   si_instance_sig_set(v8method);
L14:;
   value0 = v8method;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for METHOD-P                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L20method_p(cl_object v1x)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_make_bool(ECL_INSTANCEP(v1x));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for ADD-METHOD                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L21add_method(cl_object v1gf, cl_object v2method)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3name;
   cl_object v4method_entry;
   v3name = cl_slot_value(v1gf, ECL_SYM("NAME",1535));
   v4method_entry = ecl_assql(v3name,ecl_symbol_value(VV[1]));
   if ((v4method_entry)!=ECL_NIL) { goto L3; }
   v4method_entry = ecl_list1(v3name);
   cl_set(VV[1],CONS(v4method_entry,ecl_symbol_value(VV[1])));
L3:;
   {
    cl_object v5;
    T0 = ecl_cdr(v4method_entry);
    v5 = CONS(v2method,T0);
    if (ecl_unlikely(ECL_ATOM(v4method_entry))) FEtype_error_cons(v4method_entry);
    T0 = v4method_entry;
    (ECL_CONS_CDR(T0)=v5,T0);
   }
   {
    cl_object v5;
    T0 = ecl_instance_ref((v1gf),(7));
    v5 = CONS(v2method,T0);
    si_instance_set(v1gf, ecl_make_fixnum(7), v5);
   }
   si_instance_set(v2method, ecl_make_fixnum(0), v1gf);
   T0 = ecl_instance_ref((v1gf),(3));
   if ((T0)!=ECL_UNBOUND) { goto L16; }
   {
    cl_object v5;
    v5 = ecl_instance_ref((v2method),(1));
    si_instance_set(v1gf, ecl_make_fixnum(3), v5);
   }
   {
    cl_object v5;
    T0 = ecl_instance_ref((v2method),(1));
    T1 = si_process_lambda_list(T0, ECL_T);
    v5 = ecl_cdr(T1);
    si_instance_set(v1gf, ecl_make_fixnum(4), v5);
   }
L16:;
   ecl_function_dispatch(cl_env_copy,VV[44])(1, v1gf) /*  COMPUTE-G-F-SPEC-LIST */;
   ecl_function_dispatch(cl_env_copy,VV[45])(1, v1gf) /*  SET-GENERIC-FUNCTION-DISPATCH */;
   value0 = v2method;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for FIND-METHOD                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L24find_method(cl_narg narg, cl_object v1gf, cl_object v2qualifiers, cl_object v3specializers, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>4)) FEwrong_num_arguments_anonym();
 {
  cl_object v4errorp;
  va_list args; va_start(args,v3specializers);
  {
   int i = 3;
   if (i >= narg) {
    v4errorp = ECL_T;
   } else {
    i++;
    v4errorp = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {cl_object v5;
   v5 = ECL_NIL;
   v5 = ecl_make_cfun((cl_objectfn_fixed)LC23specializer_,ECL_NIL,Cblock,2);
   {
    cl_fixnum v6;
    v6 = ecl_length(v3specializers);
    T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("GENERIC-FUNCTION-ARGUMENT-PRECEDENCE-ORDER",1519))(1, v1gf) /*  GENERIC-FUNCTION-ARGUMENT-PRECEDENCE-ORDER */;
    {
     cl_fixnum v7;
     v7 = ecl_length(T0);
     if (!((v6)!=(v7))) { goto L3; }
    }
   }
   T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("GENERIC-FUNCTION-NAME",1525))(1, v1gf) /*  GENERIC-FUNCTION-NAME */;
   cl_error(3, _ecl_static_10, v3specializers, T0);
L3:;
   {
    cl_object v6specializers;
    {
     cl_object v7;
     cl_object v8;
     v7 = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v3specializers))) FEtype_error_list(v3specializers);
     v8 = v3specializers;
     {
      cl_object v9;
      cl_object v10;
      v9 = ecl_list1(ECL_NIL);
      v10 = v9;
L12:;
      if (!(ecl_endp(v8))) { goto L14; }
      goto L13;
L14:;
      v7 = _ecl_car(v8);
      {
       cl_object v11;
       v11 = _ecl_cdr(v8);
       if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
       v8 = v11;
      }
      if (ecl_unlikely(ECL_ATOM(v10))) FEtype_error_cons(v10);
      T0 = v10;
      T1 = LC22filter_specializer(v7);
      v10 = ecl_list1(T1);
      (ECL_CONS_CDR(T0)=v10,T0);
      goto L12;
L13:;
      v6specializers = ecl_cdr(v9);
      goto L6;
     }
    }
L6:;
    {
     cl_object v7;
     cl_object v8method;
     cl_object v9;
     v7 = ecl_function_dispatch(cl_env_copy,ECL_SYM("GENERIC-FUNCTION-METHODS",1524))(1, v1gf) /*  GENERIC-FUNCTION-METHODS */;
     v8method = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
     v9 = v7;
L33:;
     if (!(ecl_endp(v9))) { goto L35; }
     goto L34;
L35:;
     v8method = _ecl_car(v9);
     {
      cl_object v10;
      v10 = _ecl_cdr(v9);
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      v9 = v10;
     }
     T0 = (cl_env_copy->function=(ECL_SYM("METHOD-QUALIFIERS",957)->symbol.gfdef))->cfun.entry(1, v8method) /*  METHOD-QUALIFIERS */;
     if (!(ecl_equal(v2qualifiers,T0))) { goto L43; }
     T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("METHOD-SPECIALIZERS",1534))(1, v8method) /*  METHOD-SPECIALIZERS */;
     if (Null(cl_every(3, v5, v6specializers, T0))) { goto L43; }
     value0 = v8method;
     cl_env_copy->nvalues = 1;
     return value0;
L43:;
     goto L33;
L34:;
    }
   }
   if (Null(v4errorp)) { goto L2; }
   T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("GENERIC-FUNCTION-NAME",1525))(1, v1gf) /*  GENERIC-FUNCTION-NAME */;
   cl_error(4, _ecl_static_11, T0, v2qualifiers, v3specializers);
  }
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function SPECIALIZER=                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC23specializer_(cl_object v1cons_or_class, cl_object v2specializer)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_CONSP(v1cons_or_class))) { goto L1; }
  if (Null(ecl_function_dispatch(cl_env_copy,VV[47])(1, v2specializer) /*  EQL-SPECIALIZER-FLAG */)) { goto L4; }
  T0 = ecl_car(v1cons_or_class);
  T1 = ecl_function_dispatch(cl_env_copy,ECL_SYM("EQL-SPECIALIZER-OBJECT",1510))(1, v2specializer) /*  EQL-SPECIALIZER-OBJECT */;
  value0 = ecl_make_bool(ecl_eql(T0,T1));
  cl_env_copy->nvalues = 1;
  return value0;
L4:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  value0 = ecl_make_bool((v1cons_or_class)==(v2specializer));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function FILTER-SPECIALIZER                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC22filter_specializer(cl_object v1name)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(si_of_class_p(2, v1name, ECL_SYM("SPECIALIZER",1556)))) { goto L1; }
  value0 = v1name;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (!(ECL_ATOM(v1name))) { goto L3; }
  {
   cl_object v2class;
   v2class = cl_find_class(2, v1name, ECL_NIL);
   if ((v2class)!=ECL_NIL) { goto L6; }
   cl_error(2, _ecl_static_9, v1name);
L6:;
   value0 = v2class;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L3:;
  T0 = ecl_car(v1name);
  if (!((T0)==(ECL_SYM("EQL",334)))) { goto L8; }
  T0 = ecl_cddr(v1name);
  if (!(T0==ECL_NIL)) { goto L8; }
  value0 = ecl_cdr(v1name);
  cl_env_copy->nvalues = 1;
  return value0;
L8:;
  value0 = cl_error(2, _ecl_static_9, v1name);
  return value0;
 }
}
/*	local function WITH-ACCESSORS                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC25with_accessors(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4slot_accessor_pairs;
   cl_object v5instance_form;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4slot_accessor_pairs = v6;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5instance_form = v6;
   }
   {
    cl_object v6temp;
    cl_object v7accessors;
    v6temp = cl_gensym(0);
    {
     cl_object v8scan;
     cl_object v9res;
     v8scan = v4slot_accessor_pairs;
     v9res = ECL_NIL;
     goto L20;
L19:;
     T0 = ecl_caar(v8scan);
     T1 = ecl_cadar(v8scan);
     T2 = cl_list(2, T1, v6temp);
     T3 = cl_list(2, T0, T2);
     v9res = CONS(T3,v9res);
     v8scan = ecl_cdr(v8scan);
L20:;
     if (v8scan==ECL_NIL) { goto L26; }
     goto L19;
L26:;
     v7accessors = cl_nreverse(v9res);
    }
    T0 = cl_list(2, v6temp, v5instance_form);
    T1 = ecl_list1(T0);
    T2 = cl_listX(3, ECL_SYM("SYMBOL-MACROLET",842), v7accessors, v3);
    value0 = cl_list(3, ECL_SYM("LET",477), T1, T2);
    return value0;
   }
  }
 }
}

#include "clos/method.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclVFOqlpdj6TSk9_J3Q5hE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CLOS;METHOD.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclVFOqlpdj6TSk9_J3Q5hE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 si_Xmake_special(VV[0]);
 cl_set(VV[0],ecl_make_fixnum(32));
 si_Xmake_special(VV[1]);
 cl_set(VV[1],ECL_NIL);
 si_Xmake_special(ECL_SYM("*NEXT-METHODS*",1475));
 cl_set(ECL_SYM("*NEXT-METHODS*",1475),ECL_NIL);
 si_Xmake_special(VV[2]);
 cl_set(VV[2],ECL_NIL);
 ecl_cmp_defun(VV[30]);                           /*  GENERIC-FUNCTION-METHOD-CLASS */
 ecl_cmp_defmacro(VV[31]);                        /*  DEFMETHOD       */
 (void)0; /* No entry created for SPECIALIZERS-EXPRESSION */
 ecl_cmp_defun(VV[32]);                           /*  MAYBE-REMOVE-BLOCK */
 ecl_cmp_defun(VV[33]);                           /*  SIMPLIFY-LAMBDA */
 (void)0; /* No entry created for MAKE-RAW-LAMBDA */
 ecl_cmp_defun(VV[34]);                           /*  MAKE-METHOD-LAMBDA */
 ecl_cmp_defun(VV[35]);                           /*  ADD-CALL-NEXT-METHOD-CLOSURE */
 ecl_cmp_defun(VV[36]);                           /*  ENVIRONMENT-CONTAINS-CLOSURE */
 (void)0; /* No entry created for WALK-METHOD-LAMBDA */
 ecl_cmp_defun(VV[37]);                           /*  LEGAL-GENERIC-FUNCTION-NAME-P */
 (void)0; /* No entry created for PARSE-DEFMETHOD */
 ecl_cmp_defun(VV[38]);                           /*  EXTRACT-LAMBDA-LIST */
 ecl_cmp_defun(VV[39]);                           /*  EXTRACT-SPECIALIZER-NAMES */
 (void)0; /* No entry created for PARSE-SPECIALIZED-LAMBDA-LIST */
 (void)0; /* No entry created for DECLARATION-SPECIALIZERS */
 ecl_cmp_defun(VV[40]);                           /*  COMPUTE-METHOD-KEYWORDS */
 ecl_cmp_defun(VV[41]);                           /*  MAKE-METHOD     */
 ecl_cmp_defun(VV[42]);                           /*  METHOD-P        */
 ecl_cmp_defun(VV[43]);                           /*  ADD-METHOD      */
 ecl_cmp_defun(VV[46]);                           /*  FIND-METHOD     */
 ecl_cmp_defmacro(VV[48]);                        /*  WITH-ACCESSORS  */
 {
  cl_object T0;
 T0 = cl_symbol_function(ECL_SYM("GETHASH",413));
 si_fset(4, VV[29], T0, ECL_NIL, ECL_NIL);
 }
}
