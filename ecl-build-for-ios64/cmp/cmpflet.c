/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPFLET.LSP                                   */
#include <ecl/ecl-cmp.h>
#include "cmp/cmpflet.eclh"
/*	function definition for C1LABELS                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1c1labels(cl_object v1args)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L3c1labels_flet(ECL_SYM("LABELS",451), v1args);
  return value0;
 }
}
/*	function definition for C1FLET                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2c1flet(cl_object v1args)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L3c1labels_flet(ECL_SYM("FLET",373), v1args);
  return value0;
 }
}
/*	function definition for C1LABELS/FLET                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3c1labels_flet(cl_object v1origin, cl_object v2args)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_function_dispatch(cl_env_copy,VV[38])(3, v1origin, v2args, ecl_make_fixnum(1)) /*  CHECK-ARGS-NUMBER */;
  {
   cl_object v3;
   cl_object v4defs;
   cl_object v5local_funs;
   cl_object v6fnames;
   cl_object v7body_c1form;
   v3 = ecl_function_dispatch(cl_env_copy,VV[39])(0) /*  CMP-ENV-COPY */;
   v4defs = ECL_NIL;
   v5local_funs = ECL_NIL;
   v6fnames = ECL_NIL;
   v7body_c1form = ECL_NIL;
   {
    cl_object v8;
    v8 = ecl_car(v2args);
    goto L11;
L10:;
    {
     cl_object v9def;
     v9def = ecl_car(v8);
     if (ecl_endp(v9def)) { goto L17; }
     T0 = ecl_car(v9def);
     if (Null(si_valid_function_name_p(T0))) { goto L17; }
     T0 = ecl_cdr(v9def);
     if (!(ecl_endp(T0))) { goto L15; }
     goto L16;
L17:;
L16:;
     ecl_function_dispatch(cl_env_copy,VV[40])(2, _ecl_static_1, v9def) /*  CMPERR */;
L15:;
     T0 = ecl_car(v9def);
     if (Null(ecl_memql(T0,v6fnames))) { goto L20; }
     T0 = ecl_car(v9def);
     ecl_function_dispatch(cl_env_copy,VV[40])(2, _ecl_static_2, T0) /*  CMPERR */;
L20:;
     T0 = ecl_car(v9def);
     v6fnames = CONS(T0,v6fnames);
     {
      cl_object v10name;
      cl_object v11var;
      cl_object v12fun;
      v10name = ecl_car(v9def);
      v11var = ecl_function_dispatch(cl_env_copy,VV[41])(4, ECL_SYM("NAME",1273), v10name, VV[2], ECL_SYM("OBJECT",1278)) /*  MAKE-VAR */;
      v12fun = ecl_function_dispatch(cl_env_copy,VV[42])(4, ECL_SYM("NAME",1273), v10name, VV[3], v11var) /*  MAKE-FUN */;
      ecl_function_dispatch(cl_env_copy,VV[43])(2, v12fun, v3) /*  CMP-ENV-REGISTER-FUNCTION */;
      T0 = ecl_cdr(v9def);
      T1 = CONS(v12fun,T0);
      v4defs = CONS(T1,v4defs);
     }
    }
    v8 = ecl_cdr(v8);
L11:;
    if (Null(v8)) { goto L32; }
    goto L10;
L32:;
   }
   if (!((v1origin)==(ECL_SYM("FLET",373)))) { goto L36; }
   T0 = ecl_symbol_value(VV[4]);
   goto L35;
L36:;
   T0 = v3;
L35:;
   T1 = ecl_function_dispatch(cl_env_copy,VV[39])(1, T0) /*  CMP-ENV-COPY */;
   ecl_bds_bind(cl_env_copy,VV[4],T1);            /*  *CMP-ENV*       */
   {
    cl_object v8;
    v8 = cl_nreverse(v4defs);
    goto L41;
L40:;
    {
     cl_object v9def;
     v9def = ecl_car(v8);
     {
      cl_object v10fun;
      v10fun = ecl_car(v9def);
      T0 = ecl_cdr(v9def);
      T1 = ecl_function_dispatch(cl_env_copy,VV[44])(5, T0, VV[5], v10fun, VV[6], VV[7]) /*  C1COMPILE-FUNCTION */;
      v5local_funs = CONS(T1,v5local_funs);
     }
    }
    v8 = ecl_cdr(v8);
L41:;
    if (Null(v8)) { goto L50; }
    goto L40;
L50:;
    ecl_bds_unwind1(cl_env_copy);
   }
   if (!((v1origin)==(ECL_SYM("LABELS",451)))) { goto L52; }
   {
    cl_object v8change;
    v8change = ECL_NIL;
L55:;
    v8change = ECL_NIL;
    {
     cl_object v9f1;
     cl_object v10;
     v9f1 = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v5local_funs))) FEtype_error_list(v5local_funs);
     v10 = v5local_funs;
     {
      cl_object v11vars;
      v11vars = ECL_NIL;
      {
       cl_object v12funs;
       v12funs = ECL_NIL;
L64:;
       if (!(ecl_endp(v10))) { goto L66; }
       goto L65;
L66:;
       v9f1 = _ecl_car(v10);
       {
        cl_object v13;
        v13 = _ecl_cdr(v10);
        if (ecl_unlikely(!ECL_LISTP(v13))) FEtype_error_list(v13);
        v10 = v13;
       }
       v11vars = ecl_function_dispatch(cl_env_copy,VV[45])(1, v9f1) /*  FUN-REFERENCED-VARS */;
       v12funs = ecl_function_dispatch(cl_env_copy,VV[46])(1, v9f1) /*  FUN-REFERENCED-FUNS */;
       {
        cl_object v13;
        cl_object v14f2;
        cl_object v15;
        v13 = ecl_function_dispatch(cl_env_copy,VV[47])(1, v9f1) /*  FUN-REFERENCING-FUNS */;
        v14f2 = ECL_NIL;
        if (ecl_unlikely(!ECL_LISTP(v13))) FEtype_error_list(v13);
        v15 = v13;
        {
         cl_object v16c1;
         v16c1 = ECL_NIL;
         {
          cl_object v17c2;
          v17c2 = ECL_NIL;
          {
          cl_object v18c3;
          v18c3 = ECL_NIL;
L86:;
          if (!(ecl_endp(v15))) { goto L88; }
          goto L87;
L88:;
          v14f2 = _ecl_car(v15);
          {
          cl_object v19;
          v19 = _ecl_cdr(v15);
          if (ecl_unlikely(!ECL_LISTP(v19))) FEtype_error_list(v19);
          v15 = v19;
          }
          v16c1 = ecl_function_dispatch(cl_env_copy,VV[48])(2, v14f2, v11vars) /*  ADD-TO-FUN-REFERENCED-VARS */;
          v17c2 = ecl_function_dispatch(cl_env_copy,VV[49])(2, v14f2, v12funs) /*  ADD-TO-FUN-REFERENCED-FUNS */;
          v18c3 = L8update_fun_closure_type(v14f2);
          if ((v16c1)!=ECL_NIL) { goto L104; }
          if ((v17c2)!=ECL_NIL) { goto L104; }
          if (Null(v18c3)) { goto L102; }
          goto L103;
L104:;
L103:;
          v8change = ECL_T;
L102:;
          goto L86;
L87:;
          }
         }
        }
       }
       goto L64;
L65:;
      }
     }
    }
    if ((v8change)!=ECL_NIL) { goto L110; }
    goto L52;
L110:;
    goto L55;
   }
L52:;
   ecl_bds_bind(cl_env_copy,VV[4],v3);            /*  *CMP-ENV*       */
   {
    cl_object v9;                                 /*  BODY            */
    cl_object v10;                                /*  SS              */
    cl_object v11;                                /*  TS              */
    cl_object v12;                                /*  IS              */
    cl_object v13;                                /*  OTHER-DECL      */
    T0 = ecl_cdr(v2args);
    value0 = ecl_function_dispatch(cl_env_copy,VV[50])(2, T0, ECL_T) /*  C1BODY */;
    v9 = value0;
    {
     const int v14 = cl_env_copy->nvalues;
     cl_object v15;
     v15 = (v14<=1)? ECL_NIL : cl_env_copy->values[1];
     v10 = v15;
     v15 = (v14<=2)? ECL_NIL : cl_env_copy->values[2];
     v11 = v15;
     v15 = (v14<=3)? ECL_NIL : cl_env_copy->values[3];
     v12 = v15;
     v15 = (v14<=4)? ECL_NIL : cl_env_copy->values[4];
     v13 = v15;
    }
    ecl_function_dispatch(cl_env_copy,VV[51])(1, v10) /*  C1DECLARE-SPECIALS */;
    ecl_function_dispatch(cl_env_copy,VV[52])(3, ECL_NIL, v11, v12) /*  CHECK-VDECL */;
    v7body_c1form = L10c1decl_body(v13, v9);
    ecl_bds_unwind1(cl_env_copy);
   }
   T0 = (ECL_SYM("PLUSP",642)->symbol.gfdef);
   T1 = ecl_fdefinition(VV[53]);
   v5local_funs = cl_remove_if_not(4, T0, v5local_funs, ECL_SYM("KEY",1262), T1);
L123:;
   {
    cl_object v8x;
    v8x = ECL_NIL;
    {
     cl_object v9f;
     cl_object v10;
     v9f = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v5local_funs))) FEtype_error_list(v5local_funs);
     v10 = v5local_funs;
L132:;
     if (!(ecl_endp(v10))) { goto L134; }
     goto L133;
L134:;
     v9f = _ecl_car(v10);
     {
      cl_object v11;
      v11 = _ecl_cdr(v10);
      if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
      v10 = v11;
     }
     if (Null(L8update_fun_closure_type(v9f))) { goto L142; }
     v8x = ECL_T;
L142:;
     goto L132;
L133:;
    }
    if ((v8x)!=ECL_NIL) { goto L125; }
   }
   goto L124;
L125:;
   goto L123;
L124:;
   if (Null(v5local_funs)) { goto L147; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[54])(1, v7body_c1form) /*  C1FORM-TYPE */;
   {
    bool v8;
    v8 = (v1origin)==(ECL_SYM("LABELS",451));
    value0 = ecl_function_dispatch(cl_env_copy,VV[55])(7, VV[8], ECL_SYM("TYPE",1318), T0, VV[9], v5local_funs, v7body_c1form, ecl_make_bool(v8)) /*  MAKE-C1FORM* */;
    return value0;
   }
L147:;
   value0 = v7body_c1form;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for CHILD-FUNCTION-P                      */
/*	optimize speed 3, debug 1, space 1, safety 2                  */
static cl_object L4child_function_p(cl_object v1presumed_parent, cl_object v2fun)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3real_parent;
   v3real_parent = ECL_NIL;
L2:;
   v3real_parent = ecl_function_dispatch(cl_env_copy,VV[57])(1, v2fun) /*  FUN-PARENT */;
   if ((v3real_parent)!=ECL_NIL) { goto L6; }
   goto L3;
L6:;
   if (!((v3real_parent)==(v1presumed_parent))) { goto L9; }
   value0 = ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
L9:;
   v2fun = v3real_parent;
   goto L2;
L3:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for COMPUTE-CLOSURE-TYPE                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5compute_closure_type(cl_object v1fun)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2lexical_closure_p;
   v2lexical_closure_p = ECL_NIL;
   {
    cl_object v3;
    v3 = ecl_function_dispatch(cl_env_copy,VV[45])(1, v1fun) /*  FUN-REFERENCED-VARS */;
    goto L6;
L5:;
    {
     cl_object v4var;
     v4var = ecl_car(v3);
     {
      cl_object v5;
      v5 = ecl_function_dispatch(cl_env_copy,VV[58])(1, v4var) /*  GLOBAL-VAR-P */;
      if (Null(v5)) { goto L12; }
      goto L10;
L12:;
      if (Null(ecl_function_dispatch(cl_env_copy,VV[59])(1, v4var) /*  REF-REF-CCB */)) { goto L14; }
      value0 = VV[12];
      cl_env_copy->nvalues = 1;
      return value0;
L14:;
      v2lexical_closure_p = ECL_T;
     }
L10:;
    }
    v3 = ecl_cdr(v3);
L6:;
    if (Null(v3)) { goto L19; }
    goto L5;
L19:;
   }
   {
    cl_object v3;
    v3 = ecl_function_dispatch(cl_env_copy,VV[46])(1, v1fun) /*  FUN-REFERENCED-FUNS */;
    goto L25;
L24:;
    {
     cl_object v4f;
     v4f = ecl_car(v3);
     if ((L4child_function_p(v1fun, v4f))!=ECL_NIL) { goto L29; }
     {
      cl_object v5;
      v5 = ecl_function_dispatch(cl_env_copy,VV[60])(1, v4f) /*  FUN-CLOSURE */;
      if (!((v5)==(VV[12]))) { goto L32; }
      value0 = VV[12];
      cl_env_copy->nvalues = 1;
      return value0;
L32:;
      if (!((v5)==(VV[13]))) { goto L29; }
      v2lexical_closure_p = ECL_T;
     }
L29:;
    }
    v3 = ecl_cdr(v3);
L25:;
    if (Null(v3)) { goto L38; }
    goto L24;
L38:;
   }
   if (Null(v2lexical_closure_p)) { goto L40; }
   if ((ecl_function_dispatch(cl_env_copy,VV[61])(1, v1fun) /*  FUN-REF-CCB */)!=ECL_NIL) { goto L44; }
   if (Null(ecl_function_dispatch(cl_env_copy,VV[62])(1, v1fun) /*  FUN-VAR */)) { goto L42; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[62])(1, v1fun) /*  FUN-VAR */;
   T1 = ecl_function_dispatch(cl_env_copy,VV[63])(1, T0) /*  VAR-REF  */;
   if (!(ecl_plusp(T1))) { goto L42; }
   goto L43;
L44:;
L43:;
   value0 = VV[12];
   cl_env_copy->nvalues = 1;
   return value0;
L42:;
   value0 = VV[13];
   cl_env_copy->nvalues = 1;
   return value0;
L40:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for UPDATE-FUN-CLOSURE-TYPE-MANY          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6update_fun_closure_type_many(cl_object v1function_list)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2finish;
   cl_object v3recompute;
   v2finish = ECL_NIL;
   v3recompute = ECL_NIL;
   goto L5;
L4:;
   {
    cl_object v4;
    v4 = v1function_list;
    goto L11;
L10:;
    {
     cl_object v5f;
     v5f = ecl_car(v4);
     if (Null(L8update_fun_closure_type(v5f))) { goto L15; }
     v3recompute = ECL_T;
     v2finish = ECL_NIL;
L15:;
    }
    v4 = ecl_cdr(v4);
L11:;
    if (Null(v4)) { goto L22; }
    goto L10;
L22:;
   }
   v2finish = ECL_T;
L5:;
   if ((v2finish)!=ECL_NIL) { goto L26; }
   goto L4;
L26:;
   value0 = v3recompute;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for PREPEND-NEW                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7prepend_new(cl_object v1l1, cl_object v2l2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3f;
   cl_object v4;
   v3f = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v1l1))) FEtype_error_list(v1l1);
   v4 = v1l1;
L5:;
   if (!(ecl_endp(v4))) { goto L7; }
   goto L6;
L7:;
   v3f = _ecl_car(v4);
   {
    cl_object v5;
    v5 = _ecl_cdr(v4);
    if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
    v4 = v5;
   }
   v2l2 = cl_adjoin(2, v3f, v2l2);
   goto L5;
L6:;
  }
  value0 = v2l2;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for UPDATE-FUN-CLOSURE-TYPE               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8update_fun_closure_type(cl_object v1fun)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2old_type;
   v2old_type = ecl_function_dispatch(cl_env_copy,VV[60])(1, v1fun) /*  FUN-CLOSURE */;
   if (!((v2old_type)==(VV[12]))) { goto L2; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
   {
    cl_object v3;
    cl_object v4;
    cl_object v5to_be_updated;
    v3 = L5compute_closure_type(v1fun);
    v4 = ecl_function_dispatch(cl_env_copy,VV[67])(1, v1fun) /*  FUN-CHILD-FUNS */;
    v5to_be_updated = v4;
    if (!((v3)==(v2old_type))) { goto L7; }
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
L7:;
    if (Null(ecl_function_dispatch(cl_env_copy,VV[68])(1, v1fun) /*  FUN-GLOBAL */)) { goto L9; }
    T0 = ecl_function_dispatch(cl_env_copy,VV[69])(1, v1fun) /*  FUN-NAME */;
    {
     cl_object v6;
     cl_object v7;
     cl_object v8;
     v6 = ecl_function_dispatch(cl_env_copy,VV[45])(1, v1fun) /*  FUN-REFERENCED-VARS */;
     v7 = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
     v8 = v6;
     {
      cl_object v9;
      cl_object v10;
      v9 = ecl_list1(ECL_NIL);
      v10 = v9;
L18:;
      if (!(ecl_endp(v8))) { goto L20; }
      goto L19;
L20:;
      v7 = _ecl_car(v8);
      {
       cl_object v11;
       v11 = _ecl_cdr(v8);
       if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
       v8 = v11;
      }
      if (ecl_unlikely(ECL_ATOM(v10))) FEtype_error_cons(v10);
      T2 = v10;
      T3 = ecl_function_dispatch(cl_env_copy,VV[70])(1, v7) /*  VAR-NAME */;
      v10 = ecl_list1(T3);
      (ECL_CONS_CDR(T2)=v10,T2);
      goto L18;
L19:;
      T1 = ecl_cdr(v9);
      goto L11;
     }
    }
L11:;
    ecl_function_dispatch(cl_env_copy,VV[71])(3, _ecl_static_3, T0, T1) /*  CMPNOTE */;
L9:;
    ecl_structure_set(v1fun,VV[16],12,v3);
    if (!((v3)==(VV[12]))) { goto L35; }
    {
     cl_object v6;
     v6 = ecl_function_dispatch(cl_env_copy,VV[45])(1, v1fun) /*  FUN-REFERENCED-VARS */;
     goto L41;
L40:;
     {
      cl_object v7var;
      v7var = ecl_car(v6);
      if ((ecl_function_dispatch(cl_env_copy,VV[58])(1, v7var) /*  GLOBAL-VAR-P */)!=ECL_NIL) { goto L45; }
      T0 = ecl_function_dispatch(cl_env_copy,VV[72])(1, v7var) /*  VAR-KIND */;
      if ((T0)==(v3)) { goto L45; }
      ecl_structure_set(v7var,VV[17],3,ECL_NIL);
      ecl_structure_set(v7var,VV[17],2,ECL_T);
      ecl_structure_set(v7var,VV[17],6,VV[12]);
      ecl_structure_set(v7var,VV[17],10,ECL_SYM("OBJECT",2014));
      T0 = ecl_function_dispatch(cl_env_copy,VV[73])(1, v7var) /*  VAR-FUNCTIONS-READING */;
      T1 = ecl_function_dispatch(cl_env_copy,VV[74])(1, v7var) /*  VAR-FUNCTIONS-SETTING */;
      T2 = L7prepend_new(T1, v5to_be_updated);
      v5to_be_updated = L7prepend_new(T0, T2);
L45:;
     }
     v6 = ecl_cdr(v6);
L41:;
     if (Null(v6)) { goto L55; }
     goto L40;
L55:;
    }
    {
     cl_object v6;
     v6 = ecl_function_dispatch(cl_env_copy,VV[46])(1, v1fun) /*  FUN-REFERENCED-FUNS */;
     goto L60;
L59:;
     {
      cl_object v7f;
      v7f = ecl_car(v6);
      ecl_structure_set(v7f,VV[16],2,ECL_T);
     }
     v6 = ecl_cdr(v6);
L60:;
     if (Null(v6)) { goto L67; }
     goto L59;
L67:;
    }
L35:;
    if (Null(L6update_fun_closure_type_many(v5to_be_updated))) { goto L69; }
    L8update_fun_closure_type(v1fun);
L69:;
    value0 = ECL_T;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for C2LOCALS                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L9c2locals(cl_object v1c1form, cl_object v2funs, cl_object v3body, cl_object v4labels)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v5env_grows;
   ecl_bds_push(cl_env_copy,VV[19]);              /*  *ENV*           */
   ecl_bds_bind(cl_env_copy,VV[20],ecl_make_fixnum(0)); /*  *INLINE-BLOCKS* */
   ecl_bds_push(cl_env_copy,VV[21]);              /*  *ENV-LVL*       */
   v5env_grows = ECL_NIL;
   {
    cl_object v6;
    v6 = v2funs;
    goto L6;
L5:;
    {
     cl_object v7fun;
     v7fun = ecl_car(v6);
     {
      cl_object v8var;
      v8var = ecl_function_dispatch(cl_env_copy,VV[62])(1, v7fun) /*  FUN-VAR */;
      T0 = ecl_function_dispatch(cl_env_copy,VV[63])(1, v8var) /*  VAR-REF */;
      if (!(ecl_plusp(T0))) { goto L10; }
      {
       cl_object v9;
       v9 = ecl_function_dispatch(cl_env_copy,VV[72])(1, v8var) /*  VAR-KIND */;
       if (!((v9)==(VV[13]))) { goto L18; }
       goto L13;
       goto L16;
L18:;
       goto L16;
L16:;
       if (!((v9)==(VV[12]))) { goto L21; }
       goto L13;
       goto L14;
L21:;
       goto L14;
      }
L14:;
      {
       cl_object v9;
       v9 = ecl_function_dispatch(cl_env_copy,VV[76])(0) /*  NEXT-LCL */;
       ecl_structure_set(v8var,VV[17],10,v9);
      }
      ecl_function_dispatch(cl_env_copy,VV[77])(0) /*  MAYBE-OPEN-INLINE-BLOCK */;
      ecl_function_dispatch(cl_env_copy,VV[78])(3, _ecl_static_4, v8var, _ecl_static_5) /*  WT */;
L13:;
      if ((v5env_grows)!=ECL_NIL) { goto L10; }
      v5env_grows = ecl_function_dispatch(cl_env_copy,VV[79])(1, v8var) /*  VAR-REF-CCB */;
     }
L10:;
    }
    v6 = ecl_cdr(v6);
L6:;
    if (Null(v6)) { goto L30; }
    goto L5;
L30:;
   }
   if (Null(ecl_function_dispatch(cl_env_copy,VV[80])(1, v5env_grows) /*  ENV-GROWS */)) { goto L32; }
   ecl_function_dispatch(cl_env_copy,VV[77])(0)   /*  MAYBE-OPEN-INLINE-BLOCK */;
   {
    cl_object v6env_lvl;
    v6env_lvl = ecl_symbol_value(VV[21]);
    cl_set(VV[21],ecl_plus(ecl_symbol_value(VV[21]),ecl_make_fixnum(1)));
    T0 = ecl_symbol_value(VV[21]);
    ecl_function_dispatch(cl_env_copy,VV[78])(5, _ecl_static_6, T0, _ecl_static_7, v6env_lvl, _ecl_static_5) /*  WT */;
   }
L32:;
   {
    cl_object v6;
    v6 = v2funs;
    goto L42;
L41:;
    {
     cl_object v7fun;
     v7fun = ecl_car(v6);
     {
      cl_object v8var;
      v8var = ecl_function_dispatch(cl_env_copy,VV[62])(1, v7fun) /*  FUN-VAR */;
      T0 = ecl_function_dispatch(cl_env_copy,VV[63])(1, v8var) /*  VAR-REF */;
      if (!(ecl_plusp(T0))) { goto L46; }
      ecl_function_dispatch(cl_env_copy,VV[81])(2, ECL_NIL, v8var) /*  BIND */;
     }
L46:;
    }
    v6 = ecl_cdr(v6);
L42:;
    if (Null(v6)) { goto L51; }
    goto L41;
L51:;
   }
   {
    cl_object v6;
    cl_object v7;
    v6 = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v2funs))) FEtype_error_list(v2funs);
    v7 = v2funs;
L57:;
    if (!(ecl_endp(v7))) { goto L59; }
    goto L58;
L59:;
    v6 = _ecl_car(v7);
    {
     cl_object v8;
     v8 = _ecl_cdr(v7);
     if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
     v7 = v8;
    }
    ecl_function_dispatch(cl_env_copy,VV[82])(1, v6) /*  NEW-LOCAL    */;
    goto L57;
L58:;
    goto L53;
   }
L53:;
   {
    cl_object v6;
    v6 = v2funs;
    goto L74;
L73:;
    {
     cl_object v7fun;
     v7fun = ecl_car(v6);
     {
      cl_object v8var;
      v8var = ecl_function_dispatch(cl_env_copy,VV[62])(1, v7fun) /*  FUN-VAR */;
      T0 = ecl_function_dispatch(cl_env_copy,VV[63])(1, v8var) /*  VAR-REF */;
      if (!(ecl_plusp(T0))) { goto L78; }
      T0 = cl_list(2, VV[24], v7fun);
      ecl_function_dispatch(cl_env_copy,VV[83])(2, T0, v8var) /*  SET-VAR */;
     }
L78:;
    }
    v6 = ecl_cdr(v6);
L74:;
    if (Null(v6)) { goto L83; }
    goto L73;
L83:;
   }
   ecl_function_dispatch(cl_env_copy,VV[84])(1, v3body) /*  C2EXPR    */;
   value0 = ecl_function_dispatch(cl_env_copy,VV[85])(0) /*  CLOSE-INLINE-BLOCKS */;
   ecl_bds_unwind1(cl_env_copy);
   ecl_bds_unwind1(cl_env_copy);
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
 }
}
/*	function definition for C1DECL-BODY                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L10c1decl_body(cl_object v1decls, cl_object v2body)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(v1decls==ECL_NIL)) { goto L1; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[87])(1, v2body) /*  C1PROGN */;
  return value0;
L1:;
  T0 = ecl_fdefinition(VV[88]);
  T1 = ecl_function_dispatch(cl_env_copy,VV[39])(1, ecl_symbol_value(VV[4])) /*  CMP-ENV-COPY */;
  T2 = cl_reduce(4, T0, v1decls, VV[26], T1);
  ecl_bds_bind(cl_env_copy,VV[4],T2);             /*  *CMP-ENV*       */
  value0 = ecl_function_dispatch(cl_env_copy,VV[87])(1, v2body) /*  C1PROGN */;
  ecl_bds_unwind1(cl_env_copy);
  return value0;
 }
}
/*	function definition for C1LOCALLY                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L11c1locally(cl_object v1args)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;                                  /*  BODY            */
   cl_object v4;                                  /*  SS              */
   cl_object v5;                                  /*  TS              */
   cl_object v6;                                  /*  IS              */
   cl_object v7;                                  /*  OTHER-DECL      */
   value0 = ecl_function_dispatch(cl_env_copy,VV[50])(2, v1args, ECL_T) /*  C1BODY */;
   v3 = value0;
   {
    const int v8 = cl_env_copy->nvalues;
    cl_object v9;
    v9 = (v8<=1)? ECL_NIL : cl_env_copy->values[1];
    v4 = v9;
    v9 = (v8<=2)? ECL_NIL : cl_env_copy->values[2];
    v5 = v9;
    v9 = (v8<=3)? ECL_NIL : cl_env_copy->values[3];
    v6 = v9;
    v9 = (v8<=4)? ECL_NIL : cl_env_copy->values[4];
    v7 = v9;
   }
   if ((v4)!=ECL_NIL) { goto L4; }
   if ((v5)!=ECL_NIL) { goto L4; }
   if ((v6)!=ECL_NIL) { goto L4; }
   if (Null(v7)) { goto L2; }
   goto L3;
L4:;
L3:;
   T0 = ecl_function_dispatch(cl_env_copy,VV[39])(0) /*  CMP-ENV-COPY */;
   ecl_bds_bind(cl_env_copy,VV[4],T0);            /*  *CMP-ENV*       */
   ecl_function_dispatch(cl_env_copy,VV[51])(1, v4) /*  C1DECLARE-SPECIALS */;
   ecl_function_dispatch(cl_env_copy,VV[52])(3, ECL_NIL, v5, v6) /*  CHECK-VDECL */;
   value0 = L10c1decl_body(v7, v3);
   ecl_bds_unwind1(cl_env_copy);
   return value0;
L2:;
   value0 = ecl_function_dispatch(cl_env_copy,VV[87])(1, v3) /*  C1PROGN */;
   return value0;
  }
 }
}
/*	function definition for C1MACROLET                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L12c1macrolet(cl_object v1args)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_function_dispatch(cl_env_copy,VV[38])(3, ECL_SYM("MACROLET",521), v1args, ecl_make_fixnum(1)) /*  CHECK-ARGS-NUMBER */;
  T0 = ecl_car(v1args);
  T1 = ecl_function_dispatch(cl_env_copy,VV[39])(0) /*  CMP-ENV-COPY  */;
  T2 = ecl_function_dispatch(cl_env_copy,ECL_SYM("CMP-ENV-REGISTER-MACROLET",1603))(2, T0, T1) /*  CMP-ENV-REGISTER-MACROLET */;
  ecl_bds_bind(cl_env_copy,VV[4],T2);             /*  *CMP-ENV*       */
  T0 = ecl_cdr(v1args);
  value0 = L11c1locally(T0);
  ecl_bds_unwind1(cl_env_copy);
  return value0;
 }
}
/*	function definition for C1SYMBOL-MACROLET                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L13c1symbol_macrolet(cl_object v1args)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_function_dispatch(cl_env_copy,VV[38])(3, ECL_SYM("SYMBOL-MACROLET",842), v1args, ecl_make_fixnum(1)) /*  CHECK-ARGS-NUMBER */;
  T0 = ecl_function_dispatch(cl_env_copy,VV[39])(0) /*  CMP-ENV-COPY  */;
  ecl_bds_bind(cl_env_copy,VV[4],T0);             /*  *CMP-ENV*       */
  {
   cl_object v2;
   v2 = ecl_car(v1args);
   goto L6;
L5:;
   {
    cl_object v3def;
    v3def = ecl_car(v2);
    {
     cl_object v4name;
     v4name = ecl_car(v3def);
     if (ecl_endp(v3def)) { goto L14; }
     if (!(ECL_SYMBOLP(v4name))) { goto L14; }
     T0 = ecl_cdr(v3def);
     if (!(ecl_endp(T0))) { goto L12; }
     goto L13;
L14:;
L13:;
     ecl_function_dispatch(cl_env_copy,VV[40])(2, _ecl_static_8, v3def) /*  CMPERR */;
L12:;
     T0 = ecl_cadr(v3def);
     ecl_function_dispatch(cl_env_copy,VV[92])(2, v4name, T0) /*  CMP-ENV-REGISTER-SYMBOL-MACRO */;
    }
   }
   v2 = ecl_cdr(v2);
L6:;
   if (Null(v2)) { goto L19; }
   goto L5;
L19:;
  }
  T0 = ecl_cdr(v1args);
  value0 = L11c1locally(T0);
  ecl_bds_unwind1(cl_env_copy);
  return value0;
 }
}
/*	function definition for LOCAL-FUNCTION-REF                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L14local_function_ref(cl_narg narg, cl_object v1fname, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2build_object;
  va_list args; va_start(args,v1fname);
  {
   int i = 1;
   if (i >= narg) {
    v2build_object = ECL_NIL;
   } else {
    i++;
    v2build_object = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v4;                                  /*  FUN             */
   cl_object v5;                                  /*  CCB             */
   cl_object v6;                                  /*  CLB             */
   value0 = ecl_function_dispatch(cl_env_copy,VV[94])(1, v1fname) /*  CMP-ENV-SEARCH-FUNCTION */;
   v4 = value0;
   {
    const int v7 = cl_env_copy->nvalues;
    cl_object v8;
    v8 = (v7<=1)? ECL_NIL : cl_env_copy->values[1];
    v5 = v8;
    v8 = (v7<=2)? ECL_NIL : cl_env_copy->values[2];
    v6 = v8;
   }
   if (Null(v4)) { goto L3; }
   if (Null(cl_functionp(v4))) { goto L5; }
   if (Null(v2build_object)) { goto L7; }
   ecl_function_dispatch(cl_env_copy,VV[40])(2, _ecl_static_9, v1fname) /*  CMPERR */;
L7:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L5:;
   {
    cl_object v7;
    T0 = ecl_function_dispatch(cl_env_copy,VV[53])(1, v4) /*  FUN-REF */;
    v7 = ecl_plus(T0,ecl_make_fixnum(1));
    ecl_structure_set(v4,VV[16],1,v7);
   }
   if (Null(v2build_object)) { goto L12; }
   ecl_structure_set(v4,VV[16],2,ECL_T);
   goto L11;
L12:;
   {
    cl_object v7caller;
    v7caller = ecl_symbol_value(VV[31]);
    if (Null(v7caller)) { goto L11; }
    T0 = ecl_function_dispatch(cl_env_copy,VV[46])(1, v7caller) /*  FUN-REFERENCED-FUNS */;
    if ((si_memq(v4,T0))!=ECL_NIL) { goto L11; }
    {
     cl_object v8;
     T0 = ecl_function_dispatch(cl_env_copy,VV[46])(1, v7caller) /*  FUN-REFERENCED-FUNS */;
     v8 = CONS(v4,T0);
     ecl_structure_set(v7caller,VV[16],23,v8);
    }
    {
     cl_object v8;
     T0 = ecl_function_dispatch(cl_env_copy,VV[47])(1, v4) /*  FUN-REFERENCING-FUNS */;
     v8 = CONS(v7caller,T0);
     ecl_structure_set(v4,VV[16],24,v8);
    }
   }
L11:;
   {
    cl_object v7var;
    v7var = ecl_function_dispatch(cl_env_copy,VV[62])(1, v4) /*  FUN-VAR */;
    if (Null(v5)) { goto L21; }
    if (Null(v2build_object)) { goto L23; }
    ecl_structure_set(v7var,VV[17],2,ECL_T);
    ecl_structure_set(v7var,VV[17],6,VV[12]);
L23:;
    ecl_structure_set(v4,VV[16],2,ECL_T);
    goto L3;
L21:;
    if (Null(v6)) { goto L3; }
    if (Null(v2build_object)) { goto L3; }
    ecl_structure_set(v7var,VV[17],3,ECL_T);
    ecl_structure_set(v7var,VV[17],6,VV[13]);
   }
L3:;
   value0 = v4;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for C2CALL-LOCAL                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L15c2call_local(cl_object v1c1form, cl_object v2fun, cl_object v3args)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((ecl_function_dispatch(cl_env_copy,VV[96])(2, v2fun, v3args) /*  C2TRY-TAIL-RECURSIVE-CALL */)!=ECL_NIL) { goto L1; }
  {
   cl_object v4;
   v4 = ecl_symbol_value(VV[33]);
   ecl_bds_bind(cl_env_copy,VV[20],ecl_make_fixnum(0)); /*  *INLINE-BLOCKS* */
   ecl_bds_bind(cl_env_copy,VV[33],v4);           /*  *TEMP*          */
   T0 = ecl_function_dispatch(cl_env_copy,VV[69])(1, v2fun) /*  FUN-NAME */;
   T1 = ecl_function_dispatch(cl_env_copy,VV[97])(1, v3args) /*  INLINE-ARGS */;
   T2 = ecl_function_dispatch(cl_env_copy,VV[98])(1, v1c1form) /*  C1FORM-PRIMARY-TYPE */;
   T3 = ecl_function_dispatch(cl_env_copy,VV[99])(4, T0, v2fun, T1, T2) /*  CALL-LOC */;
   ecl_function_dispatch(cl_env_copy,VV[100])(1, T3) /*  UNWIND-EXIT  */;
   value0 = ecl_function_dispatch(cl_env_copy,VV[85])(0) /*  CLOSE-INLINE-BLOCKS */;
   ecl_bds_unwind1(cl_env_copy);
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}

#include "cmp/cmpflet.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecllPiDvXNvcGIk9_v8qtVE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPFLET.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_ecllPiDvXNvcGIk9_v8qtVE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[35]);                           /*  C1LABELS        */
 ecl_cmp_defun(VV[36]);                           /*  C1FLET          */
 ecl_cmp_defun(VV[37]);                           /*  C1LABELS/FLET   */
 ecl_cmp_defun(VV[56]);                           /*  CHILD-FUNCTION-P */
 (void)0; /* No entry created for COMPUTE-CLOSURE-TYPE */
 ecl_cmp_defun(VV[64]);                           /*  UPDATE-FUN-CLOSURE-TYPE-MANY */
 ecl_cmp_defun(VV[65]);                           /*  PREPEND-NEW     */
 ecl_cmp_defun(VV[66]);                           /*  UPDATE-FUN-CLOSURE-TYPE */
 ecl_cmp_defun(VV[75]);                           /*  C2LOCALS        */
 ecl_cmp_defun(VV[86]);                           /*  C1DECL-BODY     */
 ecl_cmp_defun(VV[89]);                           /*  C1LOCALLY       */
 ecl_cmp_defun(VV[90]);                           /*  C1MACROLET      */
 ecl_cmp_defun(VV[91]);                           /*  C1SYMBOL-MACROLET */
 ecl_cmp_defun(VV[93]);                           /*  LOCAL-FUNCTION-REF */
 ecl_cmp_defun(VV[95]);                           /*  C2CALL-LOCAL    */
}
