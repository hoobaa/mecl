/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPTYPE.LSP                                   */
#include <ecl/ecl-cmp.h>
#include "cmp/cmptype.eclh"
/*	function definition for AND-FORM-TYPE                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1and_form_type(cl_narg narg, cl_object v1type, cl_object v2form, cl_object v3original_form, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 {
  cl_object v4mode;
  cl_object v5format_string;
  cl_object v6format_args;
  ecl_va_list args; ecl_va_start(args,v3original_form,narg,3);
  {
   int i = 3;
   if (i >= narg) {
    v4mode = VV[0];
   } else {
    i++;
    v4mode = ecl_va_arg(args);
   }
   if (i >= narg) {
    v5format_string = _ecl_static_1;
   } else {
    i++;
    v5format_string = ecl_va_arg(args);
   }
  }
  v6format_args = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v7type2;
   cl_object v8type1;
   v7type2 = ecl_function_dispatch(cl_env_copy,VV[32])(1, v2form) /*  C1FORM-PRIMARY-TYPE */;
   v8type1 = ecl_function_dispatch(cl_env_copy,VV[33])(2, v1type, v7type2) /*  TYPE-AND */;
   if (Null(v8type1)) { goto L6; }
   ecl_structure_set(v2form,VV[1],1,v8type1);
   goto L5;
L6:;
   if (!((v4mode)==(VV[0]))) { goto L9; }
   T0 = ecl_fdefinition(VV[34]);
   goto L8;
L9:;
   T0 = ecl_fdefinition(VV[35]);
L8:;
   ecl_function_dispatch(cl_env_copy,T0)(6, _ecl_static_2, v5format_string, v6format_args, v3original_form, v7type2, v1type);
L5:;
   value0 = v2form;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for DEFAULT-INIT                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2default_init(cl_narg narg, cl_object v1var, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2warn;
  va_list args; va_start(args,v1var);
  {
   int i = 1;
   if (i >= narg) {
    v2warn = ECL_NIL;
   } else {
    i++;
    v2warn = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v3new_value;
   {
    cl_object v4;
    v4 = ecl_function_dispatch(cl_env_copy,VV[37])(1, v1var) /*  VAR-TYPE */;
    {
     cl_object v5;
     v5 = VV[3];
     goto L8;
L7:;
     {
      cl_object v6;
      cl_object v7;
      if (ecl_unlikely(ECL_ATOM(v5))) FEtype_error_cons(v5);
      v6 = v5;
      v7 = ECL_CONS_CAR(v6);
      if (Null(v7)) { goto L10; }
      {
       cl_object v8;
       if (ecl_unlikely(ECL_ATOM(v7))) FEtype_error_cons(v7);
       T1 = v7;
       v8 = ECL_CONS_CAR(T1);
       if (Null(cl_subtypep(2, v4, v8))) { goto L10; }
       T0 = v7;
       goto L3;
      }
     }
L10:;
     v5 = ECL_CONS_CDR(v5);
L8:;
     if (v5==ECL_NIL) { goto L21; }
     goto L7;
L21:;
     T0 = ECL_NIL;
    }
   }
L3:;
   v3new_value = ecl_cdr(T0);
   if (Null(v3new_value)) { goto L23; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[38])(3, v3new_value, VV[4], ECL_T) /*  C1CONSTANT-VALUE */;
   return value0;
L23:;
   value0 = ecl_function_dispatch(cl_env_copy,VV[39])(0) /*  C1NIL    */;
   return value0;
  }
 }
}
/*	function definition for EXPAND-DEFTYPE                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3expand_deftype(cl_object v1type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2base;
   cl_object v3args;
   v2base = ECL_NIL;
   v3args = ECL_NIL;
   if (!(ECL_ATOM(v1type))) { goto L4; }
   v2base = v1type;
   v3args = ECL_NIL;
   goto L3;
L4:;
   v2base = ecl_car(v1type);
   v3args = ecl_cdr(v1type);
L3:;
   {
    cl_object v4fn;
    v4fn = si_get_sysprop(v2base, VV[6]);
    if (Null(v4fn)) { goto L13; }
    v1type = cl_apply(2, v4fn, v3args);
    goto TTL;
L13:;
    value0 = v1type;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for LAMBDA-TYPE-CHECK-ASSOCIATE           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4lambda_type_check_associate(cl_object v1fname, cl_object v2requireds, cl_object v3optionals, cl_object v4keywords, cl_object v5global_fun_p)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v7;                                  /*  ARG-TYPES       */
   cl_object v8;                                  /*  FOUND           */
   if (Null(v5global_fun_p)) { goto L3; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[42])(3, v1fname, ecl_symbol_value(VV[8]), v5global_fun_p) /*  GET-ARG-TYPES */;
   goto L1;
L3:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   goto L1;
L1:;
   v7 = value0;
   {
    const int v9 = cl_env_copy->nvalues;
    cl_object v10;
    v10 = (v9<=1)? ECL_NIL : cl_env_copy->values[1];
    v8 = v10;
   }
   if (Null(v8)) { goto L5; }
   {
    cl_object v10;                                /*  REQ-TYPES       */
    cl_object v11;                                /*  OPT-TYPES       */
    cl_object v12;                                /*  KEY-TYPES       */
    value0 = si_process_lambda_list(v7, ECL_SYM("FTYPE",393));
    v10 = value0;
    {
     const int v13 = cl_env_copy->nvalues;
     cl_object v14;
     v14 = (v13<=1)? ECL_NIL : cl_env_copy->values[1];
     v11 = v14;
     v14 = (v13<=4)? ECL_NIL : cl_env_copy->values[4];
     v12 = v14;
    }
    {
     cl_object v13var;
     cl_object v14;
     v13var = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v2requireds))) FEtype_error_list(v2requireds);
     v14 = v2requireds;
     {
      cl_object v15;
      cl_object v16type;
      cl_object v17;
      v15 = ecl_cdr(v10);
      v16type = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v15))) FEtype_error_list(v15);
      v17 = v15;
      {
       cl_object v18;
       cl_object v19;
       v18 = ecl_list1(ECL_NIL);
       v19 = v18;
L18:;
       if (!(ecl_endp(v14))) { goto L20; }
       goto L19;
L20:;
       v13var = _ecl_car(v14);
       {
        cl_object v20;
        v20 = _ecl_cdr(v14);
        if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
        v14 = v20;
       }
       if (!(ecl_endp(v17))) { goto L28; }
       goto L19;
L28:;
       v16type = _ecl_car(v17);
       {
        cl_object v20;
        v20 = _ecl_cdr(v17);
        if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
        v17 = v20;
       }
       if (ecl_unlikely(ECL_ATOM(v19))) FEtype_error_cons(v19);
       T1 = v19;
       T2 = CONS(v13var,v16type);
       v19 = ecl_list1(T2);
       (ECL_CONS_CDR(T1)=v19,T1);
       goto L18;
L19:;
       T0 = ecl_cdr(v18);
       goto L8;
      }
     }
    }
L8:;
    {
     cl_object v13optional;
     cl_object v14;
     v13optional = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v3optionals))) FEtype_error_list(v3optionals);
     v14 = v3optionals;
     {
      cl_object v15;
      cl_object v16type;
      cl_object v17;
      v15 = ecl_cdr(v11);
      v16type = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v15))) FEtype_error_list(v15);
      v17 = v15;
      {
       cl_object v18;
       cl_object v19;
       v18 = ecl_list1(ECL_NIL);
       v19 = v18;
L52:;
       if (!(ecl_endp(v14))) { goto L54; }
       goto L53;
L54:;
       v13optional = _ecl_car(v14);
       {
        cl_object v20;
        v20 = ecl_cdddr(v14);
        if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
        v14 = v20;
       }
       if (!(ecl_endp(v17))) { goto L62; }
       goto L53;
L62:;
       v16type = _ecl_car(v17);
       {
        cl_object v20;
        v20 = ecl_cdddr(v17);
        if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
        v17 = v20;
       }
       if (ecl_unlikely(ECL_ATOM(v19))) FEtype_error_cons(v19);
       T2 = v19;
       T3 = CONS(v13optional,v16type);
       v19 = ecl_list1(T3);
       (ECL_CONS_CDR(T2)=v19,T2);
       goto L52;
L53:;
       T1 = ecl_cdr(v18);
       goto L42;
      }
     }
    }
L42:;
    {
     cl_object v13key_list;
     v13key_list = v4keywords;
     {
      cl_object v14keyword;
      v14keyword = ECL_NIL;
      {
       cl_object v15key_var;
       v15key_var = ECL_NIL;
       {
        cl_object v16type;
        v16type = ECL_NIL;
        {
         cl_object v17;
         cl_object v18;
         v17 = ecl_list1(ECL_NIL);
         v18 = v17;
L83:;
         if (!(ECL_ATOM(v13key_list))) { goto L85; }
         goto L84;
L85:;
         v14keyword = ecl_car(v13key_list);
         v15key_var = ecl_cadr(v13key_list);
         {
          cl_object v19key_list;
          v19key_list = ecl_cdr(v12);
L94:;
          if (!(ECL_ATOM(v19key_list))) { goto L96; }
          goto L95;
L96:;
          T3 = ecl_car(v19key_list);
          if (!((v14keyword)==(T3))) { goto L98; }
          v16type = ecl_cadr(v19key_list);
          goto L92;
L98:;
          v19key_list = ecl_cddr(v19key_list);
          goto L94;
L95:;
          v16type = ECL_T;
          goto L92;
         }
L92:;
         if (ecl_unlikely(ECL_ATOM(v18))) FEtype_error_cons(v18);
         T3 = v18;
         T4 = CONS(v15key_var,v16type);
         v18 = ecl_list1(T4);
         (ECL_CONS_CDR(T3)=v18,T3);
         v13key_list = ecl_cddddr(v13key_list);
         goto L83;
L84:;
         T2 = ecl_cdr(v17);
         goto L76;
        }
       }
      }
     }
    }
L76:;
    value0 = cl_nconc(3, T0, T1, T2);
    return value0;
   }
L5:;
   {
    cl_object v9var;
    cl_object v10;
    v9var = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v2requireds))) FEtype_error_list(v2requireds);
    v10 = v2requireds;
    {
     cl_object v11;
     cl_object v12;
     v11 = ecl_list1(ECL_NIL);
     v12 = v11;
L118:;
     if (!(ecl_endp(v10))) { goto L120; }
     goto L119;
L120:;
     v9var = _ecl_car(v10);
     {
      cl_object v13;
      v13 = _ecl_cdr(v10);
      if (ecl_unlikely(!ECL_LISTP(v13))) FEtype_error_list(v13);
      v10 = v13;
     }
     if (ecl_unlikely(ECL_ATOM(v12))) FEtype_error_cons(v12);
     T1 = v12;
     T2 = CONS(v9var,ECL_T);
     v12 = ecl_list1(T2);
     (ECL_CONS_CDR(T1)=v12,T1);
     goto L118;
L119:;
     T0 = ecl_cdr(v11);
     goto L112;
    }
   }
L112:;
   {
    cl_object v9optional;
    cl_object v10;
    v9optional = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v3optionals))) FEtype_error_list(v3optionals);
    v10 = v3optionals;
    {
     cl_object v11;
     cl_object v12;
     v11 = ecl_list1(ECL_NIL);
     v12 = v11;
L140:;
     if (!(ecl_endp(v10))) { goto L142; }
     goto L141;
L142:;
     v9optional = _ecl_car(v10);
     {
      cl_object v13;
      v13 = ecl_cdddr(v10);
      if (ecl_unlikely(!ECL_LISTP(v13))) FEtype_error_list(v13);
      v10 = v13;
     }
     if (ecl_unlikely(ECL_ATOM(v12))) FEtype_error_cons(v12);
     T2 = v12;
     T3 = CONS(v9optional,ECL_T);
     v12 = ecl_list1(T3);
     (ECL_CONS_CDR(T2)=v12,T2);
     goto L140;
L141:;
     T1 = ecl_cdr(v11);
     goto L134;
    }
   }
L134:;
   {
    cl_object v9key_list;
    v9key_list = v4keywords;
    {
     cl_object v10key_var;
     v10key_var = ECL_NIL;
     {
      cl_object v11;
      cl_object v12;
      v11 = ecl_list1(ECL_NIL);
      v12 = v11;
L161:;
      if (!(ECL_ATOM(v9key_list))) { goto L163; }
      goto L162;
L163:;
      v10key_var = ecl_cadr(v9key_list);
      if (ecl_unlikely(ECL_ATOM(v12))) FEtype_error_cons(v12);
      T3 = v12;
      T4 = CONS(v10key_var,ECL_T);
      v12 = ecl_list1(T4);
      (ECL_CONS_CDR(T3)=v12,T3);
      v9key_list = ecl_cddddr(v9key_list);
      goto L161;
L162:;
      T2 = ecl_cdr(v11);
      goto L156;
     }
    }
   }
L156:;
   value0 = cl_nconc(3, T0, T1, T2);
   return value0;
  }
 }
}
/*	function definition for LAMBDA-TYPE-CHECK-PRECISE             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5lambda_type_check_precise(cl_object v1assoc_list, cl_object v2ts)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3record;
   cl_object v4;
   v3record = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v1assoc_list))) FEtype_error_list(v1assoc_list);
   v4 = v1assoc_list;
   {
    cl_object v5var;
    v5var = ECL_NIL;
    {
     cl_object v6type;
     v6type = ECL_NIL;
L7:;
     if (!(ecl_endp(v4))) { goto L9; }
     goto L8;
L9:;
     v3record = _ecl_car(v4);
     {
      cl_object v7;
      v7 = _ecl_cdr(v4);
      if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
      v4 = v7;
     }
     v5var = ecl_car(v3record);
     T0 = ecl_function_dispatch(cl_env_copy,VV[44])(1, v5var) /*  VAR-NAME */;
     v6type = ecl_assql(T0,v2ts);
     if (Null(v6type)) { goto L21; }
     if (ecl_unlikely(ECL_ATOM(v3record))) FEtype_error_cons(v3record);
     T0 = v3record;
     T1 = ecl_cdr(v6type);
     (ECL_CONS_CDR(T0)=T1,T0);
L21:;
     goto L7;
L8:;
    }
   }
  }
  value0 = v1assoc_list;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for EXTRACT-LAMBDA-TYPE-CHECKS            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6extract_lambda_type_checks(cl_object v1fname, cl_object v2requireds, cl_object v3optionals, cl_object v4keywords, cl_object v5ts, cl_object v6other_decls)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v7policy_check_type;
   v7policy_check_type = ecl_function_dispatch(cl_env_copy,VV[46])(0) /*  POLICY-CHECK-ARGUMENTS-TYPE */;
   {
    cl_object v8checks;
    v8checks = ECL_NIL;
    {
     cl_object v9new_auxs;
     v9new_auxs = ECL_NIL;
     {
      cl_object v10global_fun_p;
      v10global_fun_p = ecl_member(VV[11],v6other_decls);
      {
       cl_object v11type_checks;
       T0 = L4lambda_type_check_associate(v1fname, v2requireds, v3optionals, v4keywords, v10global_fun_p);
       v11type_checks = L5lambda_type_check_precise(T0, v5ts);
       {
        cl_object v12var;
        cl_object v13type;
        cl_object v14;
        v12var = ECL_NIL;
        v13type = ECL_NIL;
        if (ecl_unlikely(!ECL_LISTP(v11type_checks))) FEtype_error_list(v11type_checks);
        v14 = v11type_checks;
        {
         cl_object v15name;
         v15name = ECL_NIL;
L11:;
         if (!(ecl_endp(v14))) { goto L13; }
         goto L12;
L13:;
         {
          cl_object v16;
          v16 = _ecl_car(v14);
          v12var = ecl_car(v16);
          v16 = ecl_cdr(v16);
          v13type = v16;
         }
         {
          cl_object v16;
          v16 = _ecl_cdr(v14);
          if (ecl_unlikely(!ECL_LISTP(v16))) FEtype_error_list(v16);
          v14 = v16;
         }
         v15name = ecl_function_dispatch(cl_env_copy,VV[44])(1, v12var) /*  VAR-NAME */;
         if ((v13type)==(ECL_T)) { goto L28; }
         if (Null(v7policy_check_type)) { goto L30; }
         {
          cl_object v16decl;
          cl_object v17;
          v16decl = ECL_NIL;
          if (ecl_unlikely(!ECL_LISTP(v6other_decls))) FEtype_error_list(v6other_decls);
          v17 = v6other_decls;
L36:;
          if (!(ecl_endp(v17))) { goto L38; }
          goto L37;
L38:;
          v16decl = _ecl_car(v17);
          {
          cl_object v18;
          v18 = _ecl_cdr(v17);
          if (ecl_unlikely(!ECL_LISTP(v18))) FEtype_error_list(v18);
          v17 = v18;
          }
          if (!(ECL_CONSP(v16decl))) { goto L46; }
          T0 = ecl_car(v16decl);
          if (!((T0)==(VV[12]))) { goto L46; }
          T0 = ecl_cdr(v16decl);
          if (Null(ecl_memql(v15name,T0))) { goto L46; }
          goto L30;
L46:;
          goto L36;
L37:;
          goto L31;
         }
L31:;
         ecl_structure_set(v12var,VV[13],11,ECL_T);
         T0 = cl_list(3, VV[14], v15name, v13type);
         v8checks = CONS(T0,v8checks);
         T0 = cl_list(3, ECL_SYM("TRULY-THE",1949), v13type, v15name);
         v9new_auxs = cl_listX(3, T0, v15name, v9new_auxs);
         goto L28;
L30:;
         {
          cl_object v16;
          T0 = ecl_function_dispatch(cl_env_copy,VV[37])(1, v12var) /*  VAR-TYPE */;
          v16 = ecl_function_dispatch(cl_env_copy,VV[33])(2, T0, v13type) /*  TYPE-AND */;
          ecl_structure_set(v12var,VV[13],11,v16);
         }
L28:;
         goto L11;
L12:;
         if (Null(v8checks)) { goto L59; }
         T0 = ecl_function_dispatch(cl_env_copy,VV[47])(1, ecl_symbol_value(VV[15])) /*  FUN-NAME */;
         {
          cl_object v16;
          cl_object v17;
          v16 = ECL_NIL;
          if (ecl_unlikely(!ECL_LISTP(v8checks))) FEtype_error_list(v8checks);
          v17 = v8checks;
          {
          cl_object v18;
          cl_object v19;
          v18 = ecl_list1(ECL_NIL);
          v19 = v18;
L67:;
          if (!(ecl_endp(v17))) { goto L69; }
          goto L68;
L69:;
          v16 = _ecl_car(v17);
          {
          cl_object v20;
          v20 = _ecl_cdr(v17);
          if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
          v17 = v20;
          }
          if (ecl_unlikely(ECL_ATOM(v19))) FEtype_error_cons(v19);
          T2 = v19;
          T3 = ecl_cadr(v16);
          v19 = ecl_list1(T3);
          (ECL_CONS_CDR(T2)=v19,T2);
          goto L67;
L68:;
          T1 = ecl_cdr(v18);
          goto L61;
          }
         }
L61:;
         ecl_function_dispatch(cl_env_copy,VV[48])(3, _ecl_static_3, T0, T1) /*  CMPNOTE */;
L59:;
         T0 = cl_nreverse(v8checks);
         T1 = cl_nreverse(v9new_auxs);
         value0 = CONS(T0,T1);
         cl_env_copy->nvalues = 1;
         return value0;
         value0 = ECL_NIL;
         cl_env_copy->nvalues = 1;
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
/*	function definition for TYPE-ERROR-CHECK                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7type_error_check(cl_object v1value, cl_object v2type)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!((v2type)==(ECL_SYM("CONS",251)))) { goto L1; }
  T0 = ecl_list1(v1value);
  value0 = cl_listX(3, ECL_SYM("C-INLINE",1973), T0, VV[17]);
  return value0;
L1:;
  if (!((v2type)==(ECL_SYM("ARRAY",96)))) { goto L3; }
  T0 = ecl_list1(v1value);
  value0 = cl_listX(3, ECL_SYM("C-INLINE",1973), T0, VV[18]);
  return value0;
L3:;
  if (!((v2type)==(ECL_SYM("LIST",481)))) { goto L5; }
  T0 = ecl_list1(v1value);
  value0 = cl_listX(3, ECL_SYM("C-INLINE",1973), T0, VV[19]);
  return value0;
L5:;
  if (!((v2type)==(ECL_SYM("SEQUENCE",741)))) { goto L7; }
  T0 = ecl_list1(v1value);
  value0 = cl_listX(3, ECL_SYM("C-INLINE",1973), T0, VV[20]);
  return value0;
L7:;
  T0 = cl_list(2, ECL_SYM("QUOTE",679), v2type);
  T1 = cl_list(3, ECL_SYM("TYPEP",875), v1value, T0);
  T2 = cl_list(2, ECL_SYM("QUOTE",679), v2type);
  T3 = cl_list(3, T1, T2, v1value);
  value0 = cl_listX(3, ECL_SYM("C-INLINE",1973), T3, VV[21]);
  return value0;
 }
}
/*	local function ASSERT-TYPE-IF-KNOWN                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC8assert_type_if_known(cl_object v1, cl_object v2env)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4value;
   cl_object v5type;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4value = v6;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5type = v6;
   }
   if (Null(v3)) { goto L14; }
   si_dm_too_many_arguments(v1);
L14:;
   {
    cl_object v7;                                 /*  TRIVIAL         */
    cl_object v8;                                 /*  VALID           */
    value0 = cl_subtypep(2, ECL_T, v5type);
    v7 = value0;
    v8 = cl_env_copy->values[1];
    if (Null(v7)) { goto L17; }
    if (Null(v8)) { goto L17; }
    value0 = v4value;
    cl_env_copy->nvalues = 1;
    return value0;
L17:;
    T0 = cl_list(2, VV[23], v4value);
    T1 = ecl_list1(T0);
    T2 = L9replace_invalid_types(v5type);
    T3 = L7type_error_check(VV[23], T2);
    T4 = cl_list(3, ECL_SYM("TRULY-THE",1949), v5type, VV[23]);
    value0 = cl_list(4, ECL_SYM("LET*",478), T1, T3, T4);
    return value0;
   }
  }
 }
}
/*	function definition for REPLACE-INVALID-TYPES                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L9replace_invalid_types(cl_object v1type)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_ATOM(v1type))) { goto L1; }
  value0 = v1type;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  {
   cl_object v2name;
   v2name = ecl_car(v1type);
   if (!((v2name)==(ECL_SYM("FUNCTION",396)))) { goto L4; }
   value0 = ECL_SYM("FUNCTION",396);
   cl_env_copy->nvalues = 1;
   return value0;
L4:;
   if (!((v2name)==(ECL_SYM("OR",614)))) { goto L11; }
   goto L8;
   goto L9;
L11:;
   goto L9;
L9:;
   if (!((v2name)==(ECL_SYM("AND",87)))) { goto L15; }
   goto L8;
   goto L13;
L15:;
   goto L13;
L13:;
   if (!((v2name)==(ECL_SYM("NOT",584)))) { goto L19; }
   goto L8;
   goto L17;
L19:;
   goto L17;
L17:;
   if (!((v2name)==(ECL_SYM("CONS",251)))) { goto L6; }
   goto L7;
L8:;
L7:;
   {
    cl_object v3;
    cl_object v4;
    cl_object v5;
    v3 = ecl_cdr(v1type);
    v4 = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v3))) FEtype_error_list(v3);
    v5 = v3;
    {
     cl_object v6;
     cl_object v7;
     v6 = ecl_list1(ECL_NIL);
     v7 = v6;
L29:;
     if (!(ecl_endp(v5))) { goto L31; }
     goto L30;
L31:;
     v4 = _ecl_car(v5);
     {
      cl_object v8;
      v8 = _ecl_cdr(v5);
      if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
      v5 = v8;
     }
     if (ecl_unlikely(ECL_ATOM(v7))) FEtype_error_cons(v7);
     T1 = v7;
     T2 = L9replace_invalid_types(v4);
     v7 = ecl_list1(T2);
     (ECL_CONS_CDR(T1)=v7,T1);
     goto L29;
L30:;
     T0 = ecl_cdr(v6);
     goto L22;
    }
   }
L22:;
   value0 = CONS(v2name,T0);
   cl_env_copy->nvalues = 1;
   return value0;
L6:;
   value0 = v1type;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function OPTIONAL-TYPE-CHECK                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC10optional_type_check(cl_object v1, cl_object v2env)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4value;
   cl_object v5type;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4value = v6;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5type = v6;
   }
   if (Null(v3)) { goto L14; }
   si_dm_too_many_arguments(v1);
L14:;
   if (Null(ecl_function_dispatch(cl_env_copy,VV[53])(0) /*  POLICY-ASSUME-RIGHT-TYPE */)) { goto L16; }
   value0 = v4value;
   cl_env_copy->nvalues = 1;
   return value0;
L16:;
   value0 = cl_list(3, VV[24], v4value, v5type);
   return value0;
  }
 }
}

#include "cmp/cmptype.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclx94MDemStPEk9_eaxTOE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPTYPE.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclx94MDemStPEk9_eaxTOE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[31]);                           /*  AND-FORM-TYPE   */
 ecl_cmp_defun(VV[36]);                           /*  DEFAULT-INIT    */
 ecl_cmp_defun(VV[40]);                           /*  EXPAND-DEFTYPE  */
 ecl_cmp_defun(VV[41]);                           /*  LAMBDA-TYPE-CHECK-ASSOCIATE */
 ecl_cmp_defun(VV[43]);                           /*  LAMBDA-TYPE-CHECK-PRECISE */
 ecl_cmp_defun(VV[45]);                           /*  EXTRACT-LAMBDA-TYPE-CHECKS */
 ecl_cmp_defun(VV[49]);                           /*  TYPE-ERROR-CHECK */
 ecl_cmp_defmacro(VV[50]);                        /*  ASSERT-TYPE-IF-KNOWN */
 ecl_cmp_defun(VV[51]);                           /*  REPLACE-INVALID-TYPES */
 ecl_cmp_defmacro(VV[52]);                        /*  OPTIONAL-TYPE-CHECK */
}
