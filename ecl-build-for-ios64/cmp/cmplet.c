/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPLET.LSP                                    */
#include <ecl/ecl-cmp.h>
#include "cmp/cmplet.eclh"
/*	function definition for C1LET                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1c1let(cl_object v1args)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_function_dispatch(cl_env_copy,VV[46])(3, ECL_SYM("LET",477), v1args, ecl_make_fixnum(1)) /*  CHECK-ARGS-NUMBER */;
  {
   cl_object v2bindings;
   {
    cl_object v3;
    v3 = v1args;
    if (ecl_unlikely(!ECL_LISTP(v3))) FEtype_error_list(v3);
    if (Null(v3)) { goto L6; }
    {
     cl_object v4;
     v4 = ECL_CONS_CDR(v3);
     v1args = v4;
     v3 = ECL_CONS_CAR(v3);
    }
L6:;
    v2bindings = v3;
   }
   if (!(v2bindings==ECL_NIL)) { goto L12; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[47])(1, v1args) /*  C1LOCALLY */;
   return value0;
L12:;
   if (!(ECL_ATOM(v2bindings))) { goto L14; }
   value0 = L4invalid_let_bindings(ECL_SYM("LET",477), v2bindings);
   return value0;
L14:;
   T0 = ecl_cdr(v2bindings);
   if (!(T0==ECL_NIL)) { goto L16; }
   value0 = L3c1let_let_(ECL_SYM("LET*",478), v2bindings, v1args);
   return value0;
L16:;
   {
    cl_object v3temp;
    v3temp = ECL_NIL;
    {
     cl_object v4b;
     cl_object v5;
     v4b = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v2bindings))) FEtype_error_list(v2bindings);
     v5 = v2bindings;
     {
      cl_object v6;
      cl_object v7;
      cl_object v8real_bindings;
      v6 = ecl_list1(ECL_NIL);
      v7 = v6;
      v8real_bindings = ECL_NIL;
      {
       cl_object v9;
       cl_object v10;
       cl_object v11temp_names;
       v9 = ecl_list1(ECL_NIL);
       v10 = v9;
       v11temp_names = ECL_NIL;
       {
        cl_object v12;
        cl_object v13;
        cl_object v14temp_bindings;
        v12 = ecl_list1(ECL_NIL);
        v13 = v12;
        v14temp_bindings = ECL_NIL;
L31:;
        if (!(ecl_endp(v5))) { goto L33; }
        goto L32;
L33:;
        v4b = _ecl_car(v5);
        {
         cl_object v15;
         v15 = _ecl_cdr(v5);
         if (ecl_unlikely(!ECL_LISTP(v15))) FEtype_error_list(v15);
         v5 = v15;
        }
        if (!(ECL_ATOM(v4b))) { goto L42; }
        if (ecl_unlikely(ECL_ATOM(v7))) FEtype_error_cons(v7);
        T0 = v7;
        v7 = ecl_list1(v4b);
        (ECL_CONS_CDR(T0)=v7,T0);
        v8real_bindings = ecl_cdr(v6);
        goto L41;
L42:;
        if (ecl_unlikely(ECL_ATOM(v10))) FEtype_error_cons(v10);
        T0 = v10;
        v3temp = cl_gensym(1, _ecl_static_1);
        v10 = ecl_list1(v3temp);
        (ECL_CONS_CDR(T0)=v10,T0);
        v11temp_names = ecl_cdr(v9);
        if (ecl_unlikely(ECL_ATOM(v13))) FEtype_error_cons(v13);
        T0 = v13;
        T1 = ecl_cdr(v4b);
        T2 = CONS(v3temp,T1);
        v13 = ecl_list1(T2);
        (ECL_CONS_CDR(T0)=v13,T0);
        v14temp_bindings = ecl_cdr(v12);
        if (ecl_unlikely(ECL_ATOM(v7))) FEtype_error_cons(v7);
        T0 = v7;
        T1 = ecl_car(v4b);
        T2 = cl_list(2, T1, v3temp);
        v7 = ecl_list1(T2);
        (ECL_CONS_CDR(T0)=v7,T0);
        v8real_bindings = ecl_cdr(v6);
L41:;
        goto L31;
L32:;
        T0 = ecl_nconc(v14temp_bindings,v8real_bindings);
        T1 = CONS(ECL_SYM("IGNORABLE",427),v11temp_names);
        T2 = CONS(VV[0],v11temp_names);
        T3 = cl_list(3, ECL_SYM("DECLARE",274), T1, T2);
        T4 = CONS(T3,v1args);
        value0 = L3c1let_let_(ECL_SYM("LET*",478), T0, T4);
        return value0;
       }
      }
     }
    }
   }
  }
 }
}
/*	function definition for C1LET*                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2c1let_(cl_object v1args)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_function_dispatch(cl_env_copy,VV[46])(3, ECL_SYM("LET*",478), v1args, ecl_make_fixnum(1)) /*  CHECK-ARGS-NUMBER */;
  {
   cl_object v2bindings;
   {
    cl_object v3;
    v3 = v1args;
    if (ecl_unlikely(!ECL_LISTP(v3))) FEtype_error_list(v3);
    if (Null(v3)) { goto L6; }
    {
     cl_object v4;
     v4 = ECL_CONS_CDR(v3);
     v1args = v4;
     v3 = ECL_CONS_CAR(v3);
    }
L6:;
    v2bindings = v3;
   }
   if (!(v2bindings==ECL_NIL)) { goto L12; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[47])(1, v1args) /*  C1LOCALLY */;
   return value0;
L12:;
   if (!(ECL_ATOM(v2bindings))) { goto L14; }
   value0 = L4invalid_let_bindings(ECL_SYM("LET*",478), v2bindings);
   return value0;
L14:;
   value0 = L3c1let_let_(ECL_SYM("LET*",478), v2bindings, v1args);
   return value0;
  }
 }
}
/*	function definition for C1LET/LET*                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3c1let_let_(cl_object v1let_let_, cl_object v2bindings, cl_object v3body)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4setjmps;
   v4setjmps = ecl_symbol_value(VV[3]);
   T0 = ecl_function_dispatch(cl_env_copy,VV[50])(0) /*  CMP-ENV-COPY */;
   ecl_bds_bind(cl_env_copy,VV[4],T0);            /*  *CMP-ENV*       */
   {
    cl_object v6;                                 /*  VARS            */
    cl_object v7;                                 /*  FORMS           */
    cl_object v8;                                 /*  BODY            */
    value0 = L5process_let_bindings(v1let_let_, v2bindings, v3body);
    v6 = value0;
    {
     const int v9 = cl_env_copy->nvalues;
     cl_object v10;
     v10 = (v9<=1)? ECL_NIL : cl_env_copy->values[1];
     v7 = v10;
     v10 = (v9<=2)? ECL_NIL : cl_env_copy->values[2];
     v8 = v10;
    }
    value0 = L6c1let_optimize_read_only_vars(v6, v7, v8);
    v6 = value0;
    {
     const int v9 = cl_env_copy->nvalues;
     cl_object v10;
     v10 = (v9<=1)? ECL_NIL : cl_env_copy->values[1];
     v7 = v10;
    }
    {
     cl_object v9;
     cl_object v10;
     v9 = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
     v10 = v6;
L9:;
     if (!(ecl_endp(v10))) { goto L11; }
     goto L10;
L11:;
     v9 = _ecl_car(v10);
     {
      cl_object v11;
      v11 = _ecl_cdr(v10);
      if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
      v10 = v11;
     }
     ecl_function_dispatch(cl_env_copy,VV[51])(1, v9) /*  CHECK-VREF  */;
     goto L9;
L10:;
     goto L5;
    }
L5:;
    {
     cl_object v9sp_change;
     T0 = ecl_fdefinition(VV[52]);
     v9sp_change = cl_some(2, T0, v6);
     T0 = ecl_function_dispatch(cl_env_copy,VV[53])(1, v8) /*  C1FORM-TYPE */;
     {
      bool v10;
      v10 = ecl_eql(v4setjmps,ecl_symbol_value(VV[3]));
      T1 = (v10)?ECL_NIL:ECL_T;
     }
     value0 = ecl_function_dispatch(cl_env_copy,VV[54])(11, v1let_let_, ECL_SYM("TYPE",1318), T0, VV[5], T1, VV[6], v6, VV[7], v6, v7, v8) /*  MAKE-C1FORM* */;
     ecl_bds_unwind1(cl_env_copy);
     return value0;
    }
   }
  }
 }
}
/*	function definition for INVALID-LET-BINDINGS                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4invalid_let_bindings(cl_object v1let_let_, cl_object v2bindings)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[56])(3, _ecl_static_2, v1let_let_, v2bindings) /*  CMPERR */;
  return value0;
 }
}
/*	function definition for PROCESS-LET-BINDINGS                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5process_let_bindings(cl_object v1let_let_, cl_object v2bindings, cl_object v3body)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v5;                                  /*  BODY            */
   cl_object v6;                                  /*  SPECIALS        */
   cl_object v7;                                  /*  TYPES           */
   cl_object v8;                                  /*  IGNOREDS        */
   cl_object v9;                                  /*  OTHER-DECLS     */
   value0 = ecl_function_dispatch(cl_env_copy,VV[58])(2, v3body, ECL_NIL) /*  C1BODY */;
   v5 = value0;
   {
    const int v10 = cl_env_copy->nvalues;
    cl_object v11;
    v11 = (v10<=1)? ECL_NIL : cl_env_copy->values[1];
    v6 = v11;
    v11 = (v10<=2)? ECL_NIL : cl_env_copy->values[2];
    v7 = v11;
    v11 = (v10<=3)? ECL_NIL : cl_env_copy->values[3];
    v8 = v11;
    v11 = (v10<=4)? ECL_NIL : cl_env_copy->values[4];
    v9 = v11;
   }
   {
    cl_object v10vars;
    cl_object v11forms;
    v10vars = ECL_NIL;
    v11forms = ECL_NIL;
    {
     cl_object v12b;
     cl_object v13name;
     cl_object v14form;
     v12b = v2bindings;
     v13name = ECL_NIL;
     v14form = ECL_NIL;
     goto L10;
L9:;
     {
      cl_object v15;
      v15 = v12b;
      if (ecl_unlikely(!ECL_LISTP(v15))) FEtype_error_list(v15);
      if (Null(v15)) { goto L19; }
      {
       cl_object v16;
       v16 = ECL_CONS_CDR(v15);
       v12b = v16;
       v15 = ECL_CONS_CAR(v15);
      }
L19:;
      v14form = v15;
     }
     if (!(ECL_SYMBOLP(v14form))) { goto L13; }
     v13name = v14form;
     v14form = ECL_NIL;
     goto L12;
L13:;
     ecl_function_dispatch(cl_env_copy,VV[46])(4, _ecl_static_3, v14form, ecl_make_fixnum(1), ecl_make_fixnum(2)) /*  CHECK-ARGS-NUMBER */;
     v13name = ecl_car(v14form);
     v14form = ecl_cdr(v14form);
L12:;
     {
      cl_object v15var;
      cl_object v16type;
      cl_object v17init;
      v15var = ecl_function_dispatch(cl_env_copy,VV[59])(4, v13name, v6, v8, v7) /*  C1MAKE-VAR */;
      v16type = ecl_function_dispatch(cl_env_copy,VV[60])(1, v15var) /*  VAR-TYPE */;
      if (!(v14form==ECL_NIL)) { goto L36; }
      v17init = ecl_function_dispatch(cl_env_copy,VV[61])(1, v15var) /*  DEFAULT-INIT */;
      goto L35;
L36:;
      if (Null(ecl_function_dispatch(cl_env_copy,VV[62])(1, v16type) /*  TRIVIAL-TYPE-P */)) { goto L38; }
      T0 = ecl_car(v14form);
      v17init = ecl_function_dispatch(cl_env_copy,VV[63])(1, T0) /*  C1EXPR */;
      goto L35;
L38:;
      T0 = ecl_car(v14form);
      T1 = cl_list(3, ECL_SYM("CHECKED-VALUE",1950), v16type, T0);
      v17init = ecl_function_dispatch(cl_env_copy,VV[63])(1, T1) /*  C1EXPR */;
L35:;
      if (Null(L14read_only_variable_p(v13name, v9))) { goto L40; }
      if (Null(ecl_function_dispatch(cl_env_copy,VV[52])(1, v15var) /*  GLOBAL-VAR-P */)) { goto L42; }
      ecl_function_dispatch(cl_env_copy,VV[64])(2, _ecl_static_4, v13name) /*  CMPWARN */;
      goto L40;
L42:;
      {
       cl_object v18;
       v18 = ecl_function_dispatch(cl_env_copy,VV[65])(1, v17init) /*  C1FORM-PRIMARY-TYPE */;
       ecl_structure_set(v15var,VV[10],11,v18);
      }
L40:;
      v10vars = CONS(v15var,v10vars);
      v11forms = CONS(v17init,v11forms);
      if (!((v1let_let_)==(ECL_SYM("LET*",478)))) { goto L32; }
      ecl_function_dispatch(cl_env_copy,VV[66])(1, v15var) /*  PUSH-VARS */;
     }
L32:;
L10:;
     if (ECL_ATOM(v12b)) { goto L50; }
     goto L9;
L50:;
     if (v12b==ECL_NIL) { goto L4; }
     L4invalid_let_bindings(v1let_let_, v2bindings);
    }
L4:;
    v10vars = cl_nreverse(v10vars);
    v11forms = cl_nreverse(v11forms);
    if (!((v1let_let_)==(ECL_SYM("LET",477)))) { goto L57; }
    {
     cl_object v12;
     cl_object v13;
     v12 = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v10vars))) FEtype_error_list(v10vars);
     v13 = v10vars;
L62:;
     if (!(ecl_endp(v13))) { goto L64; }
     goto L63;
L64:;
     v12 = _ecl_car(v13);
     {
      cl_object v14;
      v14 = _ecl_cdr(v13);
      if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
      v13 = v14;
     }
     ecl_function_dispatch(cl_env_copy,VV[66])(1, v12) /*  PUSH-VARS  */;
     goto L62;
L63:;
     goto L57;
    }
L57:;
    {
     cl_object v12;
     cl_object v13;
     v12 = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v10vars))) FEtype_error_list(v10vars);
     v13 = v10vars;
     {
      cl_object v14;
      cl_object v15;
      v14 = ecl_list1(ECL_NIL);
      v15 = v14;
L82:;
      if (!(ecl_endp(v13))) { goto L84; }
      goto L83;
L84:;
      v12 = _ecl_car(v13);
      {
       cl_object v16;
       v16 = _ecl_cdr(v13);
       if (ecl_unlikely(!ECL_LISTP(v16))) FEtype_error_list(v16);
       v13 = v16;
      }
      if (ecl_unlikely(ECL_ATOM(v15))) FEtype_error_cons(v15);
      T1 = v15;
      T2 = ecl_function_dispatch(cl_env_copy,VV[67])(1, v12) /*  VAR-NAME */;
      v15 = ecl_list1(T2);
      (ECL_CONS_CDR(T1)=v15,T1);
      goto L82;
L83:;
      T0 = ecl_cdr(v14);
      goto L76;
     }
    }
L76:;
    ecl_function_dispatch(cl_env_copy,VV[68])(3, T0, v7, v8) /*  CHECK-VDECL */;
    ecl_function_dispatch(cl_env_copy,VV[69])(1, v6) /*  C1DECLARE-SPECIALS */;
    T0 = ecl_function_dispatch(cl_env_copy,VV[70])(2, v9, v5) /*  C1DECL-BODY */;
    cl_env_copy->nvalues = 3;
    cl_env_copy->values[2] = T0;
    cl_env_copy->values[1] = v11forms;
    cl_env_copy->values[0] = v10vars;
    return cl_env_copy->values[0];
   }
  }
 }
}
/*	function definition for C1LET-OPTIMIZE-READ-ONLY-VARS         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6c1let_optimize_read_only_vars(cl_object v1all_vars, cl_object v2all_forms, cl_object v3body)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4vars;
   v4vars = v1all_vars;
   {
    cl_object v5forms;
    T0 = ecl_list1(v3body);
    v5forms = ecl_nconc(v2all_forms,T0);
    {
     cl_object v6var;
     v6var = ECL_NIL;
     {
      cl_object v7form;
      v7form = ECL_NIL;
      {
       cl_object v8rest_vars;
       v8rest_vars = ECL_NIL;
       {
        cl_object v9rest_forms;
        v9rest_forms = ECL_NIL;
        {
         cl_object v10read_only_p;
         v10read_only_p = ECL_NIL;
         {
          cl_object v11;
          cl_object v12;
          cl_object v13used_vars;
          v11 = ecl_list1(ECL_NIL);
          v12 = v11;
          v13used_vars = ECL_NIL;
          {
          cl_object v14;
          cl_object v15;
          cl_object v16used_forms;
          v14 = ecl_list1(ECL_NIL);
          v15 = v14;
          v16used_forms = ECL_NIL;
          if (!(ECL_ATOM(v4vars))) { goto L16; }
          goto L15;
L16:;
L14:;
          if (!(ECL_ATOM(v5forms))) { goto L18; }
          goto L15;
L18:;
          v6var = ecl_car(v4vars);
          v7form = ecl_car(v5forms);
          v8rest_vars = ecl_cdr(v4vars);
          v9rest_forms = ecl_cdr(v5forms);
          T0 = ecl_function_dispatch(cl_env_copy,VV[72])(1, v6var) /*  VAR-SET-NODES */;
          if (!(T0==ECL_NIL)) { goto L31; }
          T0 = ecl_function_dispatch(cl_env_copy,VV[73])(1, v6var) /*  VAR-FUNCTIONS-READING */;
          if (!(T0==ECL_NIL)) { goto L31; }
          T0 = ecl_function_dispatch(cl_env_copy,VV[74])(1, v6var) /*  VAR-FUNCTIONS-SETTING */;
          if (!(T0==ECL_NIL)) { goto L31; }
          T0 = ecl_function_dispatch(cl_env_copy,VV[52])(1, v6var) /*  GLOBAL-VAR-P */;
          v10read_only_p = Null(T0)?ECL_T:ECL_NIL;
          goto L29;
L31:;
          v10read_only_p = ECL_NIL;
          goto L29;
L29:;
          if (Null(v10read_only_p)) { goto L35; }
          L7fix_read_only_variable_type(v6var, v7form, v9rest_forms);
L35:;
          if (Null(v10read_only_p)) { goto L40; }
          if ((L8c1let_unused_variable_p(v6var, v7form))!=ECL_NIL) { goto L37; }
          if ((L9c1let_constant_value_p(v6var, v7form, v8rest_vars, v9rest_forms))!=ECL_NIL) { goto L37; }
          if ((L10c1let_constant_variable_p(v6var, v7form, v8rest_vars, v9rest_forms))!=ECL_NIL) { goto L37; }
          goto L38;
L40:;
          goto L38;
L38:;
          if (ecl_unlikely(ECL_ATOM(v12))) FEtype_error_cons(v12);
          T0 = v12;
          v12 = ecl_list1(v6var);
          (ECL_CONS_CDR(T0)=v12,T0);
          v13used_vars = ecl_cdr(v11);
          if (ecl_unlikely(ECL_ATOM(v15))) FEtype_error_cons(v15);
          T0 = v15;
          v15 = ecl_list1(v7form);
          (ECL_CONS_CDR(T0)=v15,T0);
          v16used_forms = ecl_cdr(v14);
L37:;
          v4vars = _ecl_cdr(v4vars);
          if (!(ECL_ATOM(v4vars))) { goto L57; }
          goto L15;
L57:;
          v5forms = _ecl_cdr(v5forms);
          goto L14;
L15:;
          cl_env_copy->nvalues = 2;
          cl_env_copy->values[1] = v16used_forms;
          cl_env_copy->values[0] = v13used_vars;
          return cl_env_copy->values[0];
          }
         }
        }
       }
      }
     }
    }
   }
  }
 }
}
/*	function definition for FIX-READ-ONLY-VARIABLE-TYPE           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7fix_read_only_variable_type(cl_object v1var, cl_object v2form, cl_object v3rest_forms)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[60])(1, v1var) /*  VAR-TYPE */;
  T1 = ecl_function_dispatch(cl_env_copy,VV[67])(1, v1var) /*  VAR-NAME */;
  ecl_function_dispatch(cl_env_copy,VV[76])(5, T0, v2form, T1, VV[13], _ecl_static_5) /*  AND-FORM-TYPE */;
  {
   cl_object v4form_type;
   v4form_type = ecl_function_dispatch(cl_env_copy,VV[65])(1, v2form) /*  C1FORM-PRIMARY-TYPE */;
   ecl_structure_set(v1var,VV[10],11,v4form_type);
   value0 = ecl_function_dispatch(cl_env_copy,VV[77])(2, v1var, v4form_type) /*  UPDATE-VARIABLE-TYPE */;
   return value0;
  }
 }
}
/*	function definition for C1LET-UNUSED-VARIABLE-P               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8c1let_unused_variable_p(cl_object v1var, cl_object v2form)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[79])(1, v1var) /*  VAR-REF */;
  if (!(ecl_number_equalp(ecl_make_fixnum(0),T0))) { goto L1; }
  {
   cl_object v3;
   v3 = ecl_function_dispatch(cl_env_copy,VV[80])(1, v1var) /*  VAR-KIND */;
   if (!((v3)==(ECL_SYM("SPECIAL",789)))) { goto L8; }
   goto L1;
   goto L6;
L8:;
   goto L6;
L6:;
   if (!((v3)==(VV[16]))) { goto L11; }
   goto L1;
   goto L4;
L11:;
   goto L4;
  }
L4:;
  if ((ecl_function_dispatch(cl_env_copy,VV[81])(1, v2form) /*  FORM-CAUSES-SIDE-EFFECT */)!=ECL_NIL) { goto L1; }
  if ((ecl_function_dispatch(cl_env_copy,VV[82])(1, v1var) /*  VAR-IGNORABLE */)!=ECL_NIL) { goto L13; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[67])(1, v1var) /*  VAR-NAME */;
  ecl_function_dispatch(cl_env_copy,VV[83])(2, _ecl_static_6, T0) /*  CMPDEBUG */;
L13:;
  ecl_function_dispatch(cl_env_copy,VV[84])(1, v2form) /*  DELETE-C1FORMS */;
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for C1LET-CONSTANT-VALUE-P                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L9c1let_constant_value_p(cl_object v1var, cl_object v2form, cl_object v3rest_vars, cl_object v4rest_forms)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[86])(1, v2form) /*  C1FORM-NAME */;
  if (!((T0)==(ECL_SYM("LOCATION",1763)))) { goto L1; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[87])(1, v2form) /*  C1FORM-ARGS */;
  T1 = ecl_car(T0);
  if (Null(ecl_function_dispatch(cl_env_copy,VV[88])(1, T1) /*  LOC-IN-C1FORM-MOVABLE-P */)) { goto L1; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[67])(1, v1var) /*  VAR-NAME */;
  ecl_function_dispatch(cl_env_copy,VV[83])(3, _ecl_static_7, T0, v2form) /*  CMPDEBUG */;
  L21nsubst_var(v1var, v2form);
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for C1LET-CONSTANT-VARIABLE-P             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L10c1let_constant_variable_p(cl_object v1var, cl_object v2form, cl_object v3rest_vars, cl_object v4rest_forms)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[86])(1, v2form) /*  C1FORM-NAME */;
  if (!((T0)==(VV[10]))) { goto L1; }
  {
   cl_object v5other_var;
   T0 = ecl_function_dispatch(cl_env_copy,VV[87])(1, v2form) /*  C1FORM-ARGS */;
   v5other_var = ecl_car(T0);
   if ((ecl_function_dispatch(cl_env_copy,VV[52])(1, v5other_var) /*  GLOBAL-VAR-P */)!=ECL_NIL) { goto L4; }
   if ((ecl_memql(v5other_var,v3rest_vars))!=ECL_NIL) { goto L4; }
   if ((ecl_function_dispatch(cl_env_copy,VV[90])(2, v5other_var, v4rest_forms) /*  VAR-CHANGED-IN-FORM-LIST */)!=ECL_NIL) { goto L4; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[67])(1, v1var) /*  VAR-NAME */;
   ecl_function_dispatch(cl_env_copy,VV[83])(3, _ecl_static_7, T0, v2form) /*  CMPDEBUG */;
   L21nsubst_var(v1var, v2form);
   value0 = ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
L4:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for C2LET-REPLACEABLE-VAR-REF-P           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L11c2let_replaceable_var_ref_p(cl_object v1var, cl_object v2form, cl_object v3rest_forms)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[86])(1, v2form) /*  C1FORM-NAME */;
  if (!((T0)==(VV[10]))) { goto L1; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[72])(1, v1var) /*  VAR-SET-NODES */;
  if (!(T0==ECL_NIL)) { goto L1; }
  if (Null(ecl_function_dispatch(cl_env_copy,VV[92])(1, v1var) /*  LOCAL */)) { goto L1; }
  {
   cl_object v4var1;
   {
    cl_object v5;
    T0 = ecl_function_dispatch(cl_env_copy,VV[87])(1, v2form) /*  C1FORM-ARGS */;
    v5 = ecl_car(T0);
    T0 = si_of_class_p(2, v5, VV[10]);
    if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[10],v5);
    v4var1 = v5;
   }
   if (Null(ecl_function_dispatch(cl_env_copy,VV[92])(1, v4var1) /*  LOCAL */)) { goto L8; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[93])(1, v1var) /*  UNBOXED */;
   T1 = ecl_function_dispatch(cl_env_copy,VV[93])(1, v4var1) /*  UNBOXED */;
   if (!((T0)==(T1))) { goto L8; }
   if ((ecl_function_dispatch(cl_env_copy,VV[90])(2, v4var1, v3rest_forms) /*  VAR-CHANGED-IN-FORM-LIST */)!=ECL_NIL) { goto L8; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[67])(1, v1var) /*  VAR-NAME */;
   ecl_function_dispatch(cl_env_copy,VV[83])(2, _ecl_static_8, T0) /*  CMPDEBUG */;
   L21nsubst_var(v1var, v2form);
   value0 = ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
L8:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for C1LET-CAN-MOVE-VARIABLE-VALUE-P       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L13c1let_can_move_variable_value_p(cl_object v1var, cl_object v2form, cl_object v3rest_vars, cl_object v4rest_forms)
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v2form,env0);                /*  FORM            */
  T0 = ecl_function_dispatch(cl_env_copy,VV[79])(1, v1var) /*  VAR-REF */;
  if (!(ecl_number_equalp(ecl_make_fixnum(1),T0))) { goto L1; }
  if ((ecl_function_dispatch(cl_env_copy,VV[81])(1, ECL_CONS_CAR(CLV0)) /*  FORM-CAUSES-SIDE-EFFECT */)!=ECL_NIL) { goto L1; }
  {cl_object v5;
   v5 = ECL_NIL;
   v5 = ecl_make_cclosure_va((cl_objectfn)LC12__g57,env0,Cblock);
   T0 = v5;
  }
  if (Null(cl_notany(2, T0, v3rest_vars))) { goto L1; }
  if (Null(L17replaceable(v1var, v4rest_forms))) { goto L1; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[67])(1, v1var) /*  VAR-NAME */;
  ecl_function_dispatch(cl_env_copy,VV[83])(3, _ecl_static_7, T0, ECL_CONS_CAR(CLV0)) /*  CMPDEBUG */;
  L21nsubst_var(v1var, ECL_CONS_CAR(CLV0));
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	closure G57                                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC12__g57(cl_narg narg, cl_object v1v, ...)
{
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  FORM            */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[95])(2, v1v, ECL_CONS_CAR(CLV0)) /*  VAR-REFERENCED-IN-FORM */;
  return value0;
 }
 }
}
/*	function definition for READ-ONLY-VARIABLE-P                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L14read_only_variable_p(cl_object v1v, cl_object v2other_decls)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = v2other_decls;
   goto L4;
L3:;
   {
    cl_object v4i;
    v4i = ecl_car(v3);
    T0 = ecl_car(v4i);
    if (!((T0)==(VV[0]))) { goto L8; }
    T0 = ecl_cdr(v4i);
    if (Null(ecl_memql(v1v,T0))) { goto L8; }
    value0 = ECL_T;
    cl_env_copy->nvalues = 1;
    return value0;
L8:;
   }
   v3 = ecl_cdr(v3);
L4:;
   if (Null(v3)) { goto L13; }
   goto L3;
L13:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for ENV-GROWS                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L15env_grows(cl_object v1possibily)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1possibily)) { goto L2; }
  if (!(ecl_plusp(ecl_symbol_value(VV[24])))) { goto L2; }
  {
   cl_object v2;
   v2 = ecl_symbol_value(VV[25]);
   goto L8;
L7:;
   {
    cl_object v3exit;
    v3exit = ecl_car(v2);
    if (!((v3exit)==(ECL_SYM("RETURN",724)))) { goto L13; }
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
L13:;
    if ((v3exit)==(VV[26])) { goto L12; }
    value0 = ECL_T;
    cl_env_copy->nvalues = 1;
    return value0;
L12:;
   }
   v2 = ecl_cdr(v2);
L8:;
   if (Null(v2)) { goto L18; }
   goto L7;
L18:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for REPLACEABLE                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L17replaceable(cl_object volatile v1var, cl_object volatile v2form)
{
 cl_object T0, T1;
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1var,env0);                 /*  VAR             */
  {
   CLV1 = env0 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env0); /*  REPLACEABLE */
   if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV1))!=0) {
   value0 = cl_env_copy->values[0];
   ecl_frs_pop(cl_env_copy);
   return value0;
   } else {
   {cl_object v3;
    v3 = ECL_NIL;
    v3 = ecl_make_cclosure_va((cl_objectfn)LC16abort_on_side_effects,env0,Cblock);
    ecl_function_dispatch(cl_env_copy,VV[99])(2, v2form, v3) /*  TRAVERSE-C1FORM-TREE */;
    T0 = ecl_function_dispatch(cl_env_copy,VV[67])(1, ECL_CONS_CAR(CLV0)) /*  VAR-NAME */;
    T1 = cl_list(2, T0, ecl_symbol_value(VV[28]));
    value0 = ecl_function_dispatch(cl_env_copy,VV[100])(4, ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_9, ECL_SYM("FORMAT-ARGUMENTS",1239), T1) /*  BABOON */;
    ecl_frs_pop(cl_env_copy);
    return value0;
   }}
  }
 }
}
/*	closure ABORT-ON-SIDE-EFFECTS                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC16abort_on_side_effects(cl_narg narg, cl_object v1form, ...)
{
 cl_object T0, T1;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  REPLACEABLE     */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[86])(1, v1form) /*  C1FORM-NAME */;
  if (!((T0)==(VV[10]))) { goto L1; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[87])(1, v1form) /*  C1FORM-ARGS */;
  T1 = ecl_car(T0);
  if (!((ECL_CONS_CAR(CLV0))==(T1))) { goto L3; }
  cl_env_copy->values[0] = ECL_T;
  cl_env_copy->nvalues = 1;
  cl_return_from(ECL_CONS_CAR(CLV1),ECL_NIL);
L3:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (Null(ecl_function_dispatch(cl_env_copy,VV[101])(1, v1form) /*  C1FORM-SIDE-EFFECTS */)) { goto L6; }
  cl_env_copy->values[0] = ECL_NIL;
  cl_env_copy->nvalues = 1;
  cl_return_from(ECL_CONS_CAR(CLV1),ECL_NIL);
L6:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
 }
}
/*	function definition for C2LET*                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L18c2let_(cl_object v1c1form, cl_object v2vars, cl_object v3forms, cl_object v4body)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[103])(1, v1c1form) /*  C1FORM-VOLATILE* */;
  ecl_bds_bind(cl_env_copy,VV[30],T0);            /*  *VOLATILE*      */
  ecl_bds_push(cl_env_copy,VV[25]);               /*  *UNWIND-EXIT*   */
  ecl_bds_push(cl_env_copy,VV[24]);               /*  *ENV*           */
  ecl_bds_push(cl_env_copy,VV[31]);               /*  *ENV-LVL*       */
  ecl_bds_bind(cl_env_copy,VV[32],ecl_make_fixnum(0)); /*  *INLINE-BLOCKS* */
  {
   cl_object v5;
   cl_object v6var;
   cl_object v7;
   v5 = v2vars;
   v6var = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
   v7 = v5;
   {
    cl_object v8rest_forms;
    T0 = ecl_list1(v4body);
    v8rest_forms = ecl_append(v3forms,T0);
    {
     cl_object v9form;
     v9form = ECL_NIL;
     {
      cl_object v10;
      cl_object v11;
      cl_object v12used_vars;
      v10 = ecl_list1(ECL_NIL);
      v11 = v10;
      v12used_vars = ECL_NIL;
      {
       cl_object v13;
       cl_object v14;
       cl_object v15used_forms;
       v13 = ecl_list1(ECL_NIL);
       v14 = v13;
       v15used_forms = ECL_NIL;
       if (!(ecl_endp(v7))) { goto L16; }
       goto L15;
L16:;
       v6var = _ecl_car(v7);
       {
        cl_object v16;
        v16 = _ecl_cdr(v7);
        if (ecl_unlikely(!ECL_LISTP(v16))) FEtype_error_list(v16);
        v7 = v16;
       }
L14:;
       if (!(ECL_ATOM(v8rest_forms))) { goto L24; }
       goto L15;
L24:;
       v9form = ecl_car(v8rest_forms);
       if ((L11c2let_replaceable_var_ref_p(v6var, v9form, v8rest_forms))!=ECL_NIL) { goto L28; }
       if (ecl_unlikely(ECL_ATOM(v11))) FEtype_error_cons(v11);
       T0 = v11;
       v11 = ecl_list1(v6var);
       (ECL_CONS_CDR(T0)=v11,T0);
       v12used_vars = ecl_cdr(v10);
       if (ecl_unlikely(ECL_ATOM(v14))) FEtype_error_cons(v14);
       T0 = v14;
       v14 = ecl_list1(v9form);
       (ECL_CONS_CDR(T0)=v14,T0);
       v15used_forms = ecl_cdr(v13);
L28:;
       if (!(ecl_endp(v7))) { goto L41; }
       goto L15;
L41:;
       v6var = _ecl_car(v7);
       {
        cl_object v16;
        v16 = _ecl_cdr(v7);
        if (ecl_unlikely(!ECL_LISTP(v16))) FEtype_error_list(v16);
        v7 = v16;
       }
       v8rest_forms = _ecl_cdr(v8rest_forms);
       goto L14;
L15:;
       v2vars = v12used_vars;
       v3forms = v15used_forms;
      }
     }
    }
   }
  }
  {
   cl_object v5var;
   cl_object v6;
   v5var = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v2vars))) FEtype_error_list(v2vars);
   v6 = v2vars;
   {
    cl_object v7kind;
    v7kind = ECL_NIL;
L61:;
    if (!(ecl_endp(v6))) { goto L63; }
    goto L62;
L63:;
    v5var = _ecl_car(v6);
    {
     cl_object v8;
     v8 = _ecl_cdr(v6);
     if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
     v6 = v8;
    }
    v7kind = ecl_function_dispatch(cl_env_copy,VV[92])(1, v5var) /*  LOCAL */;
    if (Null(v7kind)) { goto L73; }
    ecl_function_dispatch(cl_env_copy,VV[104])(0) /*  MAYBE-OPEN-INLINE-BLOCK */;
    T0 = ecl_function_dispatch(cl_env_copy,VV[67])(1, v5var) /*  VAR-NAME */;
    T1 = ecl_function_dispatch(cl_env_copy,VV[105])(1, T0) /*  NEXT-LCL */;
    ecl_function_dispatch(cl_env_copy,VV[106])(2, T1, v5var) /*  BIND */;
    T0 = ecl_symbol_value(VV[30]);
    T1 = ecl_function_dispatch(cl_env_copy,VV[107])(1, v7kind) /*  REP-TYPE-NAME */;
    ecl_function_dispatch(cl_env_copy,VV[108])(5, T0, T1, _ecl_static_10, v5var, _ecl_static_11) /*  WT-NL */;
L73:;
    goto L61;
L62:;
   }
  }
  T0 = ecl_fdefinition(VV[109]);
  if (Null(cl_some(2, T0, v2vars))) { goto L78; }
  ecl_function_dispatch(cl_env_copy,VV[104])(0)   /*  MAYBE-OPEN-INLINE-BLOCK */;
  {
   cl_object v5env_lvl;
   v5env_lvl = ecl_symbol_value(VV[31]);
   cl_set(VV[31],ecl_plus(ecl_symbol_value(VV[31]),ecl_make_fixnum(1)));
   T0 = ecl_symbol_value(VV[31]);
   ecl_function_dispatch(cl_env_copy,VV[108])(6, ecl_symbol_value(VV[30]), _ecl_static_12, T0, _ecl_static_13, v5env_lvl, _ecl_static_11) /*  WT-NL */;
  }
L78:;
  {
   cl_object v5form;
   cl_object v6;
   v5form = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v3forms))) FEtype_error_list(v3forms);
   v6 = v3forms;
   {
    cl_object v7var;
    cl_object v8;
    v7var = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v2vars))) FEtype_error_list(v2vars);
    v8 = v2vars;
L92:;
    if (!(ecl_endp(v6))) { goto L94; }
    goto L93;
L94:;
    v5form = _ecl_car(v6);
    {
     cl_object v9;
     v9 = _ecl_cdr(v6);
     if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
     v6 = v9;
    }
    if (!(ecl_endp(v8))) { goto L102; }
    goto L93;
L102:;
    v7var = _ecl_car(v8);
    {
     cl_object v9;
     v9 = _ecl_cdr(v8);
     if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
     v8 = v9;
    }
    {
     cl_object v9;
     v9 = ecl_function_dispatch(cl_env_copy,VV[80])(1, v7var) /*  VAR-KIND */;
     if (!((v9)==(VV[33]))) { goto L117; }
     goto L114;
     goto L115;
L117:;
     goto L115;
L115:;
     if (!((v9)==(VV[35]))) { goto L121; }
     goto L114;
     goto L119;
L121:;
     goto L119;
L119:;
     if (!((v9)==(ECL_SYM("SPECIAL",789)))) { goto L125; }
     goto L114;
     goto L123;
L125:;
     goto L123;
L123:;
     if (!((v9)==(VV[16]))) { goto L112; }
     goto L113;
L114:;
L113:;
     {
      cl_object v10;
      v10 = ecl_function_dispatch(cl_env_copy,VV[86])(1, v5form) /*  C1FORM-NAME */;
      if (!((v10)==(ECL_SYM("LOCATION",1763)))) { goto L129; }
      T0 = ecl_function_dispatch(cl_env_copy,VV[87])(1, v5form) /*  C1FORM-ARGS */;
      T1 = ecl_car(T0);
      ecl_function_dispatch(cl_env_copy,VV[106])(2, T1, v7var) /*  BIND */;
      goto L110;
L129:;
      if (!((v10)==(VV[10]))) { goto L131; }
      T0 = ecl_function_dispatch(cl_env_copy,VV[87])(1, v5form) /*  C1FORM-ARGS */;
      T1 = ecl_car(T0);
      ecl_function_dispatch(cl_env_copy,VV[106])(2, T1, v7var) /*  BIND */;
      goto L110;
L131:;
      ecl_function_dispatch(cl_env_copy,VV[110])(2, v5form, v7var) /*  BIND-INIT */;
      goto L110;
     }
L112:;
     ecl_bds_bind(cl_env_copy,VV[37],v7var);      /*  *DESTINATION*   */
     ecl_function_dispatch(cl_env_copy,VV[111])(1, v5form) /*  C2EXPR* */;
     ecl_bds_unwind1(cl_env_copy);
    }
L110:;
    goto L92;
L93:;
   }
  }
  if (Null(ecl_function_dispatch(cl_env_copy,VV[112])(0) /*  POLICY-DEBUG-VARIABLE-BINDINGS */)) { goto L135; }
  ecl_bds_push(cl_env_copy,VV[25]);               /*  *UNWIND-EXIT*   */
  ecl_function_dispatch(cl_env_copy,VV[113])(0)   /*  WT-NL-OPEN-BRACE */;
  {
   cl_object v5env;
   v5env = ecl_function_dispatch(cl_env_copy,VV[114])(1, v2vars) /*  BUILD-DEBUG-LEXICAL-ENV */;
   if (Null(v5env)) { goto L139; }
   cl_set(VV[25],CONS(VV[38],ecl_symbol_value(VV[25])));
L139:;
   ecl_function_dispatch(cl_env_copy,VV[115])(1, v4body) /*  C2EXPR   */;
   ecl_function_dispatch(cl_env_copy,VV[116])(0)  /*  WT-NL-CLOSE-BRACE */;
   if (Null(v5env)) {
   ecl_bds_unwind1(cl_env_copy);
    goto L134;
   }
   ecl_function_dispatch(cl_env_copy,VV[117])(0)  /*  POP-DEBUG-LEXICAL-ENV */;
   ecl_bds_unwind1(cl_env_copy);
   goto L134;
  }
L135:;
  ecl_function_dispatch(cl_env_copy,VV[115])(1, v4body) /*  C2EXPR    */;
L134:;
  value0 = ecl_function_dispatch(cl_env_copy,VV[118])(1, ECL_SYM("LINE",1601)) /*  CLOSE-INLINE-BLOCKS */;
  ecl_bds_unwind_n(cl_env_copy,5);
  return value0;
 }
}
/*	function definition for DISCARDED                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L20discarded(cl_object v1var, cl_object v2form, cl_object v3body)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((ecl_function_dispatch(cl_env_copy,VV[81])(1, v2form) /*  FORM-CAUSES-SIDE-EFFECT */)!=ECL_NIL) { goto L2; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[79])(1, v1var) /*  VAR-REF */;
  value0 = ecl_make_bool(ecl_number_compare(T0,ecl_make_fixnum(1))<0);
  if ((value0)!=ECL_NIL) { goto L5; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[79])(1, v1var) /*  VAR-REF */;
  if (!(ecl_number_equalp(T0,ecl_make_fixnum(1)))) { goto L8; }
  T0 = LC19last_form(v3body);
  if (!((v1var)==(T0))) { goto L8; }
  value0 = ecl_make_bool((VV[41])==(ecl_symbol_value(VV[37])));
  cl_env_copy->nvalues = 1;
  return value0;
L8:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L5:;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function LAST-FORM                                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC19last_form(cl_object v1x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2args;
   v2args = ecl_function_dispatch(cl_env_copy,VV[87])(1, v1x) /*  C1FORM-ARGS */;
   {
    cl_object v3;
    v3 = ecl_function_dispatch(cl_env_copy,VV[86])(1, v1x) /*  C1FORM-NAME */;
    if (!((v3)==(ECL_SYM("PROGN",671)))) { goto L3; }
    T0 = ecl_car(v2args);
    T1 = ecl_last(T0,1);
    v1x = ecl_car(T1);
    goto TTL;
L3:;
    if (Null(ecl_memql(v3,VV[40]))) { goto L7; }
    T0 = ecl_last(v2args,1);
    v1x = ecl_car(T0);
    goto TTL;
L7:;
    if (!((v3)==(VV[10]))) { goto L11; }
    T0 = ecl_function_dispatch(cl_env_copy,VV[87])(1, v1x) /*  C1FORM-ARGS */;
    value0 = ecl_car(T0);
    cl_env_copy->nvalues = 1;
    return value0;
L11:;
    value0 = v1x;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for NSUBST-VAR                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L21nsubst_var(cl_object v1var, cl_object v2form)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[72])(1, v1var) /*  VAR-SET-NODES */)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[100])(2, ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_14) /*  BABOON */;
L1:;
  if (Null(ecl_function_dispatch(cl_env_copy,VV[73])(1, v1var) /*  VAR-FUNCTIONS-READING */)) { goto L3; }
  ecl_function_dispatch(cl_env_copy,VV[100])(2, ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_15) /*  BABOON */;
L3:;
  {
   cl_object v3;
   v3 = ecl_function_dispatch(cl_env_copy,VV[121])(1, v1var) /*  VAR-READ-FORMS */;
   goto L9;
L8:;
   {
    cl_object v4where;
    v4where = ecl_car(v3);
    T0 = ecl_function_dispatch(cl_env_copy,VV[86])(1, v4where) /*  C1FORM-NAME */;
    if (!((T0)==(VV[10]))) { goto L16; }
    T0 = ecl_function_dispatch(cl_env_copy,VV[87])(1, v4where) /*  C1FORM-ARGS */;
    T1 = ecl_car(T0);
    if (ecl_eql(T1,v1var)) { goto L13; }
    goto L14;
L16:;
    goto L14;
L14:;
    ecl_function_dispatch(cl_env_copy,VV[100])(2, ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_16) /*  BABOON */;
L13:;
    ecl_function_dispatch(cl_env_copy,VV[122])(2, v1var, v4where) /*  DELETE-FROM-READ-NODES */;
    ecl_function_dispatch(cl_env_copy,VV[123])(2, v4where, v2form) /*  C1FORM-REPLACE-WITH */;
   }
   v3 = ecl_cdr(v3);
L9:;
   if (Null(v3)) { goto L22; }
   goto L8;
L22:;
  }
  value0 = ecl_structure_set(v1var,VV[10],13,ecl_make_fixnum(0));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for MEMBER-VAR                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L22member_var(cl_object v1var, cl_object v2list)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3kind;
   v3kind = ecl_function_dispatch(cl_env_copy,VV[80])(1, v1var) /*  VAR-KIND */;
   if (!((v3kind)==(ECL_SYM("SPECIAL",789)))) { goto L7; }
   goto L4;
   goto L5;
L7:;
   goto L5;
L5:;
   if (!((v3kind)==(VV[16]))) { goto L2; }
   goto L3;
L4:;
L3:;
   {
    cl_object v4;
    v4 = v2list;
    goto L13;
L12:;
    {
     cl_object v5;
     cl_object v6;
     if (ecl_unlikely(ECL_ATOM(v4))) FEtype_error_cons(v4);
     v5 = v4;
     v6 = ECL_CONS_CAR(v5);
     {
      cl_object v7;
      v7 = ecl_function_dispatch(cl_env_copy,VV[80])(1, v6) /*  VAR-KIND */;
      if (!((v7)==(ECL_SYM("SPECIAL",789)))) { goto L25; }
      goto L22;
      goto L23;
L25:;
      goto L23;
L23:;
      if (!((v7)==(VV[16]))) { goto L15; }
      goto L20;
L22:;
     }
L20:;
     T0 = ecl_function_dispatch(cl_env_copy,VV[67])(1, v1var) /*  VAR-NAME */;
     T1 = ecl_function_dispatch(cl_env_copy,VV[67])(1, v6) /*  VAR-NAME */;
     if (!(ecl_eql(T0,T1))) { goto L15; }
     value0 = v5;
     cl_env_copy->nvalues = 1;
     return value0;
    }
L15:;
    v4 = ECL_CONS_CDR(v4);
L13:;
    if (v4==ECL_NIL) { goto L30; }
    goto L12;
L30:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L2:;
   value0 = ecl_memql(v1var,v2list);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}

#include "cmp/cmplet.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecl4mG57ty8njrm9_oVqtVE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPLET.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_ecl4mG57ty8njrm9_oVqtVE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[45]);                           /*  C1LET           */
 ecl_cmp_defun(VV[48]);                           /*  C1LET*          */
 ecl_cmp_defun(VV[49]);                           /*  C1LET/LET*      */
 ecl_cmp_defun(VV[55]);                           /*  INVALID-LET-BINDINGS */
 ecl_cmp_defun(VV[57]);                           /*  PROCESS-LET-BINDINGS */
 ecl_cmp_defun(VV[71]);                           /*  C1LET-OPTIMIZE-READ-ONLY-VARS */
 ecl_cmp_defun(VV[75]);                           /*  FIX-READ-ONLY-VARIABLE-TYPE */
 ecl_cmp_defun(VV[78]);                           /*  C1LET-UNUSED-VARIABLE-P */
 ecl_cmp_defun(VV[85]);                           /*  C1LET-CONSTANT-VALUE-P */
 ecl_cmp_defun(VV[89]);                           /*  C1LET-CONSTANT-VARIABLE-P */
 ecl_cmp_defun(VV[91]);                           /*  C2LET-REPLACEABLE-VAR-REF-P */
 ecl_cmp_defun(VV[94]);                           /*  C1LET-CAN-MOVE-VARIABLE-VALUE-P */
 ecl_cmp_defun(VV[96]);                           /*  READ-ONLY-VARIABLE-P */
 ecl_cmp_defun(VV[97]);                           /*  ENV-GROWS       */
 ecl_cmp_defun(VV[98]);                           /*  REPLACEABLE     */
 ecl_cmp_defun(VV[102]);                          /*  C2LET*          */
 ecl_cmp_defun(VV[119]);                          /*  DISCARDED       */
 ecl_cmp_defun(VV[120]);                          /*  NSUBST-VAR      */
 ecl_cmp_defun(VV[124]);                          /*  MEMBER-VAR      */
}
