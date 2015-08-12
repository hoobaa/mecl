/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPPROP.LSP                                   */
#include <ecl/ecl-cmp.h>
#include "cmp/cmpprop.eclh"
/*	function definition for P1PROPAGATE                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1p1propagate(cl_object v1form, cl_object v2assumptions)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((v1form)!=ECL_NIL) { goto L1; }
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = v2assumptions;
  cl_env_copy->values[0] = ECL_SYM("NULL",605);
  return cl_env_copy->values[0];
L1:;
  if (Null(ecl_function_dispatch(cl_env_copy,VV[53])(1, v1form) /*  C1FORM-P */)) { goto L3; }
  {
   cl_object v3name;
   cl_object v4propagator;
   T0 = ecl_function_dispatch(cl_env_copy,VV[54])(1, v1form) /*  C1FORM-ENV */;
   ecl_bds_bind(cl_env_copy,VV[0],T0);            /*  *CMP-ENV*       */
   v3name = ecl_function_dispatch(cl_env_copy,VV[55])(1, v1form) /*  C1FORM-NAME */;
   v4propagator = ecl_gethash_safe(v3name,ecl_symbol_value(VV[1]),ECL_NIL);
   if (Null(v4propagator)) {
   ecl_bds_unwind1(cl_env_copy);
    goto L3;
   }
   {
    cl_object v6;                                 /*  NEW-TYPE        */
    cl_object v7;                                 /*  ASSUMPTIONS     */
    T0 = ecl_function_dispatch(cl_env_copy,VV[56])(1, v1form) /*  C1FORM-ARGS */;
    value0 = cl_apply(4, v4propagator, v1form, v2assumptions, T0);
    v6 = value0;
    {
     const int v8 = cl_env_copy->nvalues;
     cl_object v9;
     v9 = (v8<=1)? ECL_NIL : cl_env_copy->values[1];
     v7 = v9;
    }
    if (Null(v7)) { goto L10; }
    ecl_function_dispatch(cl_env_copy,VV[57])(2, ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_1) /*  BABOON */;
L10:;
    {
     cl_object v8;
     T1 = ecl_function_dispatch(cl_env_copy,VV[58])(1, v1form) /*  C1FORM-TYPE */;
     v8 = ecl_function_dispatch(cl_env_copy,VV[59])(2, T1, v6) /*  VALUES-TYPE-AND */;
     T0 = ecl_structure_set(v1form,VV[2],1,v8);
    }
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = v7;
    cl_env_copy->values[0] = T0;
    ecl_bds_unwind1(cl_env_copy);
    return cl_env_copy->values[0];
   }
  }
L3:;
  ecl_function_dispatch(cl_env_copy,VV[60])(2, _ecl_static_2, v1form) /*  CMPNOTE */;
  T0 = ecl_function_dispatch(cl_env_copy,VV[58])(1, v1form) /*  C1FORM-TYPE */;
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = v2assumptions;
  cl_env_copy->values[0] = T0;
  return cl_env_copy->values[0];
 }
}
/*	function definition for P1TRIVIAL                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2p1trivial(cl_narg narg, cl_object v1form, cl_object v2assumptions, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  T0 = ecl_function_dispatch(cl_env_copy,VV[58])(1, v1form) /*  C1FORM-TYPE */;
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = v2assumptions;
  cl_env_copy->values[0] = T0;
  return cl_env_copy->values[0];
 }
}
/*	function definition for P1VAR                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3p1var(cl_object v1form, cl_object v2assumptions, cl_object v3var)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4record;
   cl_object v5var_type;
   cl_object v6type;
   if (Null(ecl_assql(v3var,v2assumptions))) { goto L3; }
   v4record = ecl_function_dispatch(cl_env_copy,VV[57])(2, ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_3) /*  BABOON */;
   goto L1;
L3:;
   v4record = ECL_NIL;
   goto L1;
L1:;
   if (Null(v4record)) { goto L6; }
   v5var_type = ecl_cdr(v4record);
   goto L5;
L6:;
   v5var_type = ecl_function_dispatch(cl_env_copy,VV[63])(1, v3var) /*  VAR-TYPE */;
L5:;
   T0 = ecl_function_dispatch(cl_env_copy,VV[64])(1, v1form) /*  C1FORM-PRIMARY-TYPE */;
   v6type = ecl_function_dispatch(cl_env_copy,VV[65])(2, v5var_type, T0) /*  TYPE-AND */;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v2assumptions;
   cl_env_copy->values[0] = v6type;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for P1VALUES                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4p1values(cl_object v1form, cl_object v2assumptions, cl_object v3values)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4v;
   cl_object v5;
   v4v = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v3values))) FEtype_error_list(v3values);
   v5 = v3values;
   {
    cl_object v6;
    cl_object v7;
    cl_object v8all_values;
    v6 = ecl_list1(ECL_NIL);
    v7 = v6;
    v8all_values = ECL_NIL;
L7:;
    if (!(ecl_endp(v5))) { goto L9; }
    goto L8;
L9:;
    v4v = _ecl_car(v5);
    {
     cl_object v9;
     v9 = _ecl_cdr(v5);
     if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
     v5 = v9;
    }
    if (ecl_unlikely(ECL_ATOM(v7))) FEtype_error_cons(v7);
    T0 = v7;
    {
     cl_object v10;                               /*  TYPE            */
     cl_object v11;                               /*  NEW-ASSUMPTIONS */
     value0 = L1p1propagate(v4v, v2assumptions);
     v10 = value0;
     {
      const int v12 = cl_env_copy->nvalues;
      cl_object v13;
      v13 = (v12<=1)? ECL_NIL : cl_env_copy->values[1];
      v11 = v13;
     }
     v2assumptions = v11;
     T1 = ecl_function_dispatch(cl_env_copy,VV[67])(1, v10) /*  VALUES-TYPE-PRIMARY-TYPE */;
    }
    v7 = ecl_list1(T1);
    (ECL_CONS_CDR(T0)=v7,T0);
    v8all_values = ecl_cdr(v6);
    goto L7;
L8:;
    T0 = CONS(ECL_SYM("VALUES",895),v8all_values);
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = v2assumptions;
    cl_env_copy->values[0] = T0;
    return cl_env_copy->values[0];
   }
  }
 }
}
/*	function definition for P1PROPAGATE-LIST                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5p1propagate_list(cl_object v1list, cl_object v2assumptions)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3final_type;
   v3final_type = ECL_T;
   {
    cl_object v4f;
    cl_object v5;
    v4f = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v1list))) FEtype_error_list(v1list);
    v5 = v1list;
L5:;
    if (!(ecl_endp(v5))) { goto L7; }
    goto L6;
L7:;
    v4f = _ecl_car(v5);
    {
     cl_object v6;
     v6 = _ecl_cdr(v5);
     if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
     v5 = v6;
    }
    value0 = L1p1propagate(v4f, v2assumptions);
    v3final_type = value0;
    {
     const int v6 = cl_env_copy->nvalues;
     cl_object v7;
     v7 = (v6<=1)? ECL_NIL : cl_env_copy->values[1];
     v2assumptions = v7;
    }
    goto L5;
L6:;
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = v2assumptions;
    cl_env_copy->values[0] = v3final_type;
    return cl_env_copy->values[0];
   }
  }
 }
}
/*	function definition for P1MERGE-BRANCHES                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6p1merge_branches(cl_object v1root, cl_object v2chains)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(v1root==ECL_NIL)) { goto L4; }
  T0 = (ECL_SYM("NULL",605)->symbol.gfdef);
  if ((cl_every(2, T0, v2chains))!=ECL_NIL) { goto L1; }
  goto L2;
L4:;
  goto L2;
L2:;
  value0 = ecl_function_dispatch(cl_env_copy,VV[57])(2, ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_4) /*  BABOON */;
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for REVISE-VAR-TYPE                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7revise_var_type(cl_object v1variable, cl_object v2assumptions, cl_object v3where_to_stop)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(v2assumptions==ECL_NIL)) { goto L4; }
  if (v3where_to_stop==ECL_NIL) { goto L1; }
  goto L2;
L4:;
  goto L2;
L2:;
  value0 = ecl_function_dispatch(cl_env_copy,VV[57])(2, ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_5) /*  BABOON */;
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for P1BLOCK                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8p1block(cl_object v1c1form, cl_object v2assumptions, cl_object v3blk, cl_object v4body)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_structure_set(v3blk,VV[10],8,ECL_NIL);
  {
   cl_object v6;                                  /*  NORMAL-TYPE     */
   cl_object v7;                                  /*  ASSUMPTIONS     */
   value0 = L1p1propagate(v4body, v2assumptions);
   v6 = value0;
   {
    const int v8 = cl_env_copy->nvalues;
    cl_object v9;
    v9 = (v8<=1)? ECL_NIL : cl_env_copy->values[1];
    v7 = v9;
   }
   {
    cl_object v8blk_type;
    v8blk_type = ecl_function_dispatch(cl_env_copy,VV[72])(1, v3blk) /*  BLK-TYPE */;
    if (Null(v8blk_type)) { goto L5; }
    T0 = ecl_function_dispatch(cl_env_copy,VV[73])(2, v8blk_type, v6) /*  VALUES-TYPE-OR */;
    goto L4;
L5:;
    T0 = v6;
L4:;
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = v7;
    cl_env_copy->values[0] = T0;
    return cl_env_copy->values[0];
   }
  }
 }
}
/*	function definition for P1RETURN-FROM                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L9p1return_from(cl_object v1c1form, cl_object v2assumptions, cl_object v3blk, cl_object v4return_type, cl_object v5value, cl_object v6variable_or_nil)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v7values_type;
   cl_object v8blk_type;
   v7values_type = L1p1propagate(v5value, v2assumptions);
   v8blk_type = ecl_function_dispatch(cl_env_copy,VV[72])(1, v3blk) /*  BLK-TYPE */;
   {
    cl_object v9;
    if (Null(v8blk_type)) { goto L5; }
    v9 = ecl_function_dispatch(cl_env_copy,VV[73])(2, v8blk_type, v7values_type) /*  VALUES-TYPE-OR */;
    goto L4;
L5:;
    v9 = v7values_type;
L4:;
    ecl_structure_set(v3blk,VV[10],8,v9);
   }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v2assumptions;
   cl_env_copy->values[0] = v7values_type;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for P1CALL-GLOBAL                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L10p1call_global(cl_object v1c1form, cl_object v2assumptions, cl_object v3fname, cl_object v4args)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v5v;
   cl_object v6;
   v5v = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v4args))) FEtype_error_list(v4args);
   v6 = v4args;
L4:;
   if (!(ecl_endp(v6))) { goto L6; }
   goto L5;
L6:;
   v5v = _ecl_car(v6);
   {
    cl_object v7;
    v7 = _ecl_cdr(v6);
    if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
    v6 = v7;
   }
   {
    cl_object v8;                                 /*  ARG-TYPE        */
    cl_object v9;                                 /*  LOCAL-ASS       */
    value0 = L1p1propagate(v5v, v2assumptions);
    v8 = value0;
    {
     const int v10 = cl_env_copy->nvalues;
     cl_object v11;
     v11 = (v10<=1)? ECL_NIL : cl_env_copy->values[1];
     v9 = v11;
    }
    v2assumptions = v9;
   }
   goto L4;
L5:;
   {
    cl_object v7type;
    v7type = ecl_function_dispatch(cl_env_copy,VV[76])(2, v3fname, v4args) /*  PROPAGATE-TYPES */;
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = v2assumptions;
    cl_env_copy->values[0] = v7type;
    return cl_env_copy->values[0];
   }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for P1CALL-LOCAL                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L11p1call_local(cl_object v1c1form, cl_object v2assumptions, cl_object v3fun, cl_object v4args)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v5v;
   cl_object v6;
   v5v = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v4args))) FEtype_error_list(v4args);
   v6 = v4args;
L4:;
   if (!(ecl_endp(v6))) { goto L6; }
   goto L5;
L6:;
   v5v = _ecl_car(v6);
   {
    cl_object v7;
    v7 = _ecl_cdr(v6);
    if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
    v6 = v7;
   }
   {
    cl_object v8;                                 /*  ARG-TYPE        */
    cl_object v9;                                 /*  LOCAL-ASS       */
    value0 = L1p1propagate(v5v, v2assumptions);
    v8 = value0;
    {
     const int v10 = cl_env_copy->nvalues;
     cl_object v11;
     v11 = (v10<=1)? ECL_NIL : cl_env_copy->values[1];
     v9 = v11;
    }
    v2assumptions = v9;
   }
   goto L4;
L5:;
   T0 = ecl_function_dispatch(cl_env_copy,VV[78])(1, v3fun) /*  FUN-RETURN-TYPE */;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v2assumptions;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for P1CATCH                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L12p1catch(cl_object v1c1form, cl_object v2assumptions, cl_object v3tag, cl_object v4body)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6;                                  /*  ASSUMPTIONS     */
   value0 = L1p1propagate(v3tag, v2assumptions);
   {
    const int v7 = cl_env_copy->nvalues;
    cl_object v8;
    v8 = (v7<=1)? ECL_NIL : cl_env_copy->values[1];
    v6 = v8;
   }
   L1p1propagate(v4body, v6);
  }
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = v2assumptions;
  cl_env_copy->values[0] = ECL_T;
  return cl_env_copy->values[0];
 }
}
/*	function definition for P1THROW                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L13p1throw(cl_object v1c1form, cl_object v2assumptions, cl_object v3catch_value, cl_object v4output_value)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6;                                  /*  NEW-ASSUMPTIONS */
   value0 = L1p1propagate(v3catch_value, v2assumptions);
   {
    const int v7 = cl_env_copy->nvalues;
    cl_object v8;
    v8 = (v7<=1)? ECL_NIL : cl_env_copy->values[1];
    v6 = v8;
   }
   L1p1propagate(v4output_value, v6);
  }
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = v2assumptions;
  cl_env_copy->values[0] = ECL_T;
  return cl_env_copy->values[0];
 }
}
/*	function definition for P1IF                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L14p1if(cl_object v1c1form, cl_object v2assumptions, cl_object v3fmla, cl_object v4true_branch, cl_object v5false_branch)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v7;                                  /*  BASE-ASSUMPTIONS */
   value0 = L1p1propagate(v3fmla, v2assumptions);
   {
    const int v8 = cl_env_copy->nvalues;
    cl_object v9;
    v9 = (v8<=1)? ECL_NIL : cl_env_copy->values[1];
    v7 = v9;
   }
   {
    cl_object v9;                                 /*  T1              */
    cl_object v10;                                /*  A1              */
    value0 = L1p1propagate(v4true_branch, v7);
    v9 = value0;
    {
     const int v11 = cl_env_copy->nvalues;
     cl_object v12;
     v12 = (v11<=1)? ECL_NIL : cl_env_copy->values[1];
     v10 = v12;
    }
    {
     cl_object v12;                               /*  T2              */
     cl_object v13;                               /*  A2              */
     value0 = L1p1propagate(v5false_branch, v7);
     v12 = value0;
     {
      const int v14 = cl_env_copy->nvalues;
      cl_object v15;
      v15 = (v14<=1)? ECL_NIL : cl_env_copy->values[1];
      v13 = v15;
     }
     T0 = ecl_function_dispatch(cl_env_copy,VV[73])(2, v9, v12) /*  VALUES-TYPE-OR */;
     T1 = cl_list(2, v10, v13);
     T2 = L6p1merge_branches(v7, T1);
     cl_env_copy->nvalues = 2;
     cl_env_copy->values[1] = T2;
     cl_env_copy->values[0] = T0;
     return cl_env_copy->values[0];
    }
   }
  }
 }
}
/*	function definition for P1FMLA-NOT                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L15p1fmla_not(cl_object v1c1form, cl_object v2assumptions, cl_object v3form)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v5;                                  /*  ASSUMPTIONS     */
   value0 = L1p1propagate(v3form, v2assumptions);
   {
    const int v6 = cl_env_copy->nvalues;
    cl_object v7;
    v7 = (v6<=1)? ECL_NIL : cl_env_copy->values[1];
    v5 = v7;
   }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5;
   cl_env_copy->values[0] = VV[18];
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for P1FMLA-AND                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L16p1fmla_and(cl_object v1c1form, cl_object v2orig_assumptions, cl_object v3butlast, cl_object v4last)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v5type;
   v5type = ECL_T;
   {
    cl_object v6assumptions;
    v6assumptions = v2orig_assumptions;
    {
     cl_object v7;
     cl_object v8form;
     cl_object v9;
     T0 = ecl_list1(v4last);
     v7 = ecl_append(v3butlast,T0);
     v8form = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
     v9 = v7;
     {
      cl_object v10;
      cl_object v11;
      cl_object v12assumptions_list;
      v10 = ecl_list1(ECL_NIL);
      v11 = v10;
      v12assumptions_list = ECL_NIL;
L10:;
      if (!(ecl_endp(v9))) { goto L12; }
      goto L11;
L12:;
      v8form = _ecl_car(v9);
      {
       cl_object v13;
       v13 = _ecl_cdr(v9);
       if (ecl_unlikely(!ECL_LISTP(v13))) FEtype_error_list(v13);
       v9 = v13;
      }
      if (ecl_unlikely(ECL_ATOM(v11))) FEtype_error_cons(v11);
      T0 = v11;
      value0 = L1p1propagate(v8form, v6assumptions);
      v5type = value0;
      {
       const int v13 = cl_env_copy->nvalues;
       cl_object v14;
       v14 = (v13<=1)? ECL_NIL : cl_env_copy->values[1];
       v6assumptions = v14;
      }
      v11 = ecl_list1(v6assumptions);
      (ECL_CONS_CDR(T0)=v11,T0);
      v12assumptions_list = ecl_cdr(v10);
      goto L10;
L11:;
      T0 = ecl_function_dispatch(cl_env_copy,VV[67])(1, v5type) /*  VALUES-TYPE-PRIMARY-TYPE */;
      T1 = ecl_function_dispatch(cl_env_copy,VV[84])(2, ECL_SYM("NULL",605), T0) /*  TYPE-OR */;
      T2 = L6p1merge_branches(v2orig_assumptions, v12assumptions_list);
      cl_env_copy->nvalues = 2;
      cl_env_copy->values[1] = T2;
      cl_env_copy->values[0] = T1;
      return cl_env_copy->values[0];
     }
    }
   }
  }
 }
}
/*	function definition for P1FMLA-OR                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L17p1fmla_or(cl_object v1c1form, cl_object v2orig_assumptions, cl_object v3butlast, cl_object v4last)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v5type;
   v5type = ECL_NIL;
   {
    cl_object v6output_type;
    v6output_type = ECL_T;
    {
     cl_object v7assumptions;
     v7assumptions = v2orig_assumptions;
     {
      cl_object v8;
      cl_object v9form;
      cl_object v10;
      T0 = ecl_list1(v4last);
      v8 = ecl_append(v3butlast,T0);
      v9form = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
      v10 = v8;
      {
       cl_object v11;
       cl_object v12;
       cl_object v13assumptions_list;
       v11 = ecl_list1(ECL_NIL);
       v12 = v11;
       v13assumptions_list = ECL_NIL;
L11:;
       if (!(ecl_endp(v10))) { goto L13; }
       goto L12;
L13:;
       v9form = _ecl_car(v10);
       {
        cl_object v14;
        v14 = _ecl_cdr(v10);
        if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
        v10 = v14;
       }
       if (ecl_unlikely(ECL_ATOM(v12))) FEtype_error_cons(v12);
       T0 = v12;
       value0 = L1p1propagate(v9form, v7assumptions);
       v5type = value0;
       {
        const int v14 = cl_env_copy->nvalues;
        cl_object v15;
        v15 = (v14<=1)? ECL_NIL : cl_env_copy->values[1];
        v7assumptions = v15;
       }
       T1 = ecl_function_dispatch(cl_env_copy,VV[67])(1, v5type) /*  VALUES-TYPE-PRIMARY-TYPE */;
       v6output_type = ecl_function_dispatch(cl_env_copy,VV[84])(2, T1, v6output_type) /*  TYPE-OR */;
       v12 = ecl_list1(v7assumptions);
       (ECL_CONS_CDR(T0)=v12,T0);
       v13assumptions_list = ecl_cdr(v11);
       goto L11;
L12:;
       T0 = L6p1merge_branches(v2orig_assumptions, v13assumptions_list);
       cl_env_copy->nvalues = 2;
       cl_env_copy->values[1] = T0;
       cl_env_copy->values[0] = v6output_type;
       return cl_env_copy->values[0];
      }
     }
    }
   }
  }
 }
}
/*	function definition for P1LAMBDA                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L18p1lambda(cl_narg narg, cl_object v1c1form, cl_object v2assumptions, cl_object v3lambda_list, cl_object v4doc, cl_object v5body, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<5)) FEwrong_num_arguments_anonym();
 {
  {
   cl_object v6type;
   v6type = L1p1propagate(v5body, v2assumptions);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v2assumptions;
   cl_env_copy->values[0] = v6type;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for P1PROPAGATE-FUNCTION                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L19p1propagate_function(cl_object v1fun, cl_object v2assumptions)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4;                                  /*  OUTPUT-TYPE     */
   cl_object v5;                                  /*  ASSUMPTIONS     */
   T0 = ecl_function_dispatch(cl_env_copy,VV[88])(1, v1fun) /*  FUN-LAMBDA */;
   value0 = L1p1propagate(T0, v2assumptions);
   v4 = value0;
   {
    const int v6 = cl_env_copy->nvalues;
    cl_object v7;
    v7 = (v6<=1)? ECL_NIL : cl_env_copy->values[1];
    v5 = v7;
   }
   T0 = ecl_structure_set(v1fun,VV[23],19,v4);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for P1LET*                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L20p1let_(cl_object v1c1form, cl_object v2base_assumptions, cl_object v3vars, cl_object v4forms, cl_object v5body)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6assumptions;
   v6assumptions = v2base_assumptions;
   {
    cl_object v7type;
    v7type = ECL_NIL;
    {
     cl_object v8v;
     cl_object v9;
     v8v = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v3vars))) FEtype_error_list(v3vars);
     v9 = v3vars;
     {
      cl_object v10f;
      cl_object v11;
      v10f = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v4forms))) FEtype_error_list(v4forms);
      v11 = v4forms;
L10:;
      if (!(ecl_endp(v9))) { goto L12; }
      goto L11;
L12:;
      v8v = _ecl_car(v9);
      {
       cl_object v12;
       v12 = _ecl_cdr(v9);
       if (ecl_unlikely(!ECL_LISTP(v12))) FEtype_error_list(v12);
       v9 = v12;
      }
      if (!(ecl_endp(v11))) { goto L20; }
      goto L11;
L20:;
      v10f = _ecl_car(v11);
      {
       cl_object v12;
       v12 = _ecl_cdr(v11);
       if (ecl_unlikely(!ECL_LISTP(v12))) FEtype_error_list(v12);
       v11 = v12;
      }
      if ((ecl_function_dispatch(cl_env_copy,VV[90])(1, v8v) /*  GLOBAL-VAR-P */)!=ECL_NIL) { goto L28; }
      if ((ecl_function_dispatch(cl_env_copy,VV[91])(1, v8v) /*  VAR-SET-NODES */)!=ECL_NIL) { goto L28; }
      value0 = L1p1propagate(v10f, v6assumptions);
      v7type = value0;
      {
       const int v12 = cl_env_copy->nvalues;
       cl_object v13;
       v13 = (v12<=1)? ECL_NIL : cl_env_copy->values[1];
       v6assumptions = v13;
      }
      {
       cl_object v12;
       T0 = ecl_function_dispatch(cl_env_copy,VV[67])(1, v7type) /*  VALUES-TYPE-PRIMARY-TYPE */;
       T1 = ecl_function_dispatch(cl_env_copy,VV[63])(1, v8v) /*  VAR-TYPE */;
       v12 = ecl_function_dispatch(cl_env_copy,VV[65])(2, T0, T1) /*  TYPE-AND */;
       ecl_structure_set(v8v,VV[25],11,v12);
      }
L28:;
      goto L10;
L11:;
     }
    }
   }
   {
    cl_object v8;                                 /*  TYPE            */
    cl_object v9;                                 /*  ASSUMPTIONS     */
    value0 = L1p1propagate(v5body, v6assumptions);
    v8 = value0;
    {
     const int v10 = cl_env_copy->nvalues;
     cl_object v11;
     v11 = (v10<=1)? ECL_NIL : cl_env_copy->values[1];
     v9 = v11;
    }
    {
     cl_object v10v;
     cl_object v11;
     v10v = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v3vars))) FEtype_error_list(v3vars);
     v11 = v3vars;
L41:;
     if (!(ecl_endp(v11))) { goto L43; }
     goto L42;
L43:;
     v10v = _ecl_car(v11);
     {
      cl_object v12;
      v12 = _ecl_cdr(v11);
      if (ecl_unlikely(!ECL_LISTP(v12))) FEtype_error_list(v12);
      v11 = v12;
     }
     L7revise_var_type(v10v, v9, v2base_assumptions);
     goto L41;
L42:;
    }
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = v9;
    cl_env_copy->values[0] = v8;
    return cl_env_copy->values[0];
   }
  }
 }
}
/*	function definition for P1LOCALS                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L21p1locals(cl_object v1c1form, cl_object v2assumptions, cl_object v3funs, cl_object v4body, cl_object v5labels)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6f;
   cl_object v7;
   v6f = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v3funs))) FEtype_error_list(v3funs);
   v7 = v3funs;
L5:;
   if (!(ecl_endp(v7))) { goto L7; }
   goto L6;
L7:;
   v6f = _ecl_car(v7);
   {
    cl_object v8;
    v8 = _ecl_cdr(v7);
    if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
    v7 = v8;
   }
   L19p1propagate_function(v6f, v2assumptions);
   goto L5;
L6:;
  }
  value0 = L1p1propagate(v4body, v2assumptions);
  return value0;
 }
}
/*	function definition for P1MULTIPLE-VALUE-BIND                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L22p1multiple_value_bind(cl_object v1c1form, cl_object v2assumptions, cl_object v3vars_list, cl_object v4init_c1form, cl_object v5body)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v7;                                  /*  INIT-FORM-TYPE  */
   cl_object v8;                                  /*  ASSUMPTIONS     */
   value0 = L1p1propagate(v4init_c1form, v2assumptions);
   v7 = value0;
   {
    const int v9 = cl_env_copy->nvalues;
    cl_object v10;
    v10 = (v9<=1)? ECL_NIL : cl_env_copy->values[1];
    v8 = v10;
   }
   {
    cl_object v9v;
    cl_object v10;
    v9v = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v3vars_list))) FEtype_error_list(v3vars_list);
    v10 = v3vars_list;
    {
     cl_object v11;
     cl_object v12type;
     cl_object v13;
     {
      cl_fixnum v14;
      v14 = ecl_length(v3vars_list);
      v11 = ecl_function_dispatch(cl_env_copy,VV[94])(2, v7, ecl_make_fixnum(v14)) /*  VALUES-TYPE-TO-N-TYPES */;
     }
     v12type = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
     v13 = v11;
L10:;
     if (!(ecl_endp(v10))) { goto L12; }
     goto L11;
L12:;
     v9v = _ecl_car(v10);
     {
      cl_object v14;
      v14 = _ecl_cdr(v10);
      if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
      v10 = v14;
     }
     if (!(ecl_endp(v13))) { goto L20; }
     goto L11;
L20:;
     v12type = _ecl_car(v13);
     {
      cl_object v14;
      v14 = _ecl_cdr(v13);
      if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
      v13 = v14;
     }
     if ((ecl_function_dispatch(cl_env_copy,VV[90])(1, v9v) /*  GLOBAL-VAR-P */)!=ECL_NIL) { goto L28; }
     if ((ecl_function_dispatch(cl_env_copy,VV[91])(1, v9v) /*  VAR-SET-NODES */)!=ECL_NIL) { goto L28; }
     {
      cl_object v14;
      T0 = ecl_function_dispatch(cl_env_copy,VV[63])(1, v9v) /*  VAR-TYPE */;
      v14 = ecl_function_dispatch(cl_env_copy,VV[65])(2, T0, v12type) /*  TYPE-AND */;
      ecl_structure_set(v9v,VV[25],11,v14);
     }
L28:;
     goto L10;
L11:;
    }
   }
   value0 = L1p1propagate(v5body, v8);
   return value0;
  }
 }
}
/*	function definition for P1MULTIPLE-VALUE-SETQ                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L23p1multiple_value_setq(cl_object v1c1form, cl_object v2assumptions, cl_object v3vars_list, cl_object v4value_c1form)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6;                                  /*  INIT-FORM-TYPE  */
   cl_object v7;                                  /*  ASSUMPTIONS     */
   value0 = L1p1propagate(v4value_c1form, v2assumptions);
   v6 = value0;
   {
    const int v8 = cl_env_copy->nvalues;
    cl_object v9;
    v9 = (v8<=1)? ECL_NIL : cl_env_copy->values[1];
    v7 = v9;
   }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v7;
   cl_env_copy->values[0] = v6;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for P1PROGN                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L24p1progn(cl_object v1c1form, cl_object v2assumptions, cl_object v3forms)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L5p1propagate_list(v3forms, v2assumptions);
  return value0;
 }
}
/*	function definition for P1COMPILER-TYPECASE                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L25p1compiler_typecase(cl_object v1c1form, cl_object v2assumptions, cl_object v3variable, cl_object v4expressions)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v5var_type;
   v5var_type = ecl_function_dispatch(cl_env_copy,VV[63])(1, v3variable) /*  VAR-TYPE */;
   {
    cl_object v6output_type;
    v6output_type = ECL_T;
    {
     cl_object v7a_type;
     cl_object v8c1form;
     cl_object v9;
     v7a_type = ECL_NIL;
     v8c1form = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v4expressions))) FEtype_error_list(v4expressions);
     v9 = v4expressions;
     {
      cl_object v10c1form_type;
      v10c1form_type = ECL_NIL;
L8:;
      if (!(ecl_endp(v9))) { goto L10; }
      goto L9;
L10:;
      {
       cl_object v11;
       v11 = _ecl_car(v9);
       v7a_type = ecl_car(v11);
       v11 = ecl_cdr(v11);
       v8c1form = ecl_car(v11);
      }
      {
       cl_object v11;
       v11 = _ecl_cdr(v9);
       if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
       v9 = v11;
      }
      v10c1form_type = L1p1propagate(v8c1form, v2assumptions);
      if (!(ecl_eql(v7a_type,ECL_T))) { goto L31; }
      goto L27;
      goto L29;
L31:;
      goto L29;
L29:;
      if (!((v7a_type)==(ECL_SYM("OTHERWISE",615)))) { goto L34; }
      goto L27;
      goto L28;
L34:;
      goto L28;
L28:;
      if (Null(cl_subtypep(2, v5var_type, v7a_type))) { goto L25; }
      goto L26;
L27:;
L26:;
      v6output_type = v10c1form_type;
L25:;
      goto L8;
L9:;
      cl_env_copy->nvalues = 2;
      cl_env_copy->values[1] = v2assumptions;
      cl_env_copy->values[0] = v6output_type;
      return cl_env_copy->values[0];
     }
    }
   }
  }
 }
}
/*	function definition for P1CHECKED-VALUE                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L26p1checked_value(cl_object v1c1form, cl_object v2assumptions, cl_object v3type, cl_object v4value, cl_object v5let_form)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6value_type;
   cl_object v7alt_type;
   v6value_type = L1p1propagate(v4value, v2assumptions);
   v7alt_type = L1p1propagate(v5let_form, v2assumptions);
   if (Null(cl_subtypep(2, v6value_type, v3type))) { goto L3; }
   value0 = v6value_type;
   cl_env_copy->nvalues = 1;
   return value0;
L3:;
   value0 = v3type;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for P1PROGV                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L27p1progv(cl_object v1c1form, cl_object v2assumptions, cl_object v3variables, cl_object v4values, cl_object v5body)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6type;
   v6type = ECL_NIL;
   value0 = L1p1propagate(v3variables, v2assumptions);
   v6type = value0;
   {
    const int v7 = cl_env_copy->nvalues;
    cl_object v8;
    v8 = (v7<=1)? ECL_NIL : cl_env_copy->values[1];
    v2assumptions = v8;
   }
   value0 = L1p1propagate(v4values, v2assumptions);
   v6type = value0;
   {
    const int v7 = cl_env_copy->nvalues;
    cl_object v8;
    v8 = (v7<=1)? ECL_NIL : cl_env_copy->values[1];
    v2assumptions = v8;
   }
   value0 = L1p1propagate(v5body, v2assumptions);
   return value0;
  }
 }
}
/*	function definition for P1SETQ                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L28p1setq(cl_object v1c1form, cl_object v2assumptions, cl_object v3var, cl_object v4c1form)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6;                                  /*  VALUE-TYPE      */
   cl_object v7;                                  /*  ASSUMPTIONS     */
   value0 = L1p1propagate(v4c1form, v2assumptions);
   v6 = value0;
   {
    const int v8 = cl_env_copy->nvalues;
    cl_object v9;
    v9 = (v8<=1)? ECL_NIL : cl_env_copy->values[1];
    v7 = v9;
   }
   T0 = ecl_function_dispatch(cl_env_copy,VV[63])(1, v3var) /*  VAR-TYPE */;
   T1 = ecl_function_dispatch(cl_env_copy,VV[67])(1, v6) /*  VALUES-TYPE-PRIMARY-TYPE */;
   T2 = ecl_function_dispatch(cl_env_copy,VV[65])(2, T0, T1) /*  TYPE-AND */;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v7;
   cl_env_copy->values[0] = T2;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for P1PSETQ                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L29p1psetq(cl_object v1c1form, cl_object v2assumptions, cl_object v3vars, cl_object v4c1forms)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v5form;
   cl_object v6;
   v5form = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v4c1forms))) FEtype_error_list(v4c1forms);
   v6 = v4c1forms;
L5:;
   if (!(ecl_endp(v6))) { goto L7; }
   goto L6;
L7:;
   v5form = _ecl_car(v6);
   {
    cl_object v7;
    v7 = _ecl_cdr(v6);
    if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
    v6 = v7;
   }
   {
    cl_object v8;                                 /*  NEW-TYPE        */
    cl_object v9;                                 /*  ASSUMPTIONS     */
    value0 = L1p1propagate(v5form, v2assumptions);
    v8 = value0;
    {
     const int v10 = cl_env_copy->nvalues;
     cl_object v11;
     v11 = (v10<=1)? ECL_NIL : cl_env_copy->values[1];
     v9 = v11;
    }
   }
   goto L5;
L6:;
  }
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = v2assumptions;
  cl_env_copy->values[0] = ECL_SYM("NULL",605);
  return cl_env_copy->values[0];
 }
}
/*	function definition for P1WITH-STACK                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L30p1with_stack(cl_object v1c1form, cl_object v2assumptions, cl_object v3body)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L1p1propagate(v3body, v2assumptions);
  return value0;
 }
}
/*	function definition for P1STACK-PUSH-VALUES                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L31p1stack_push_values(cl_object v1c1form, cl_object v2assumptions, cl_object v3form, cl_object v4inline)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6;                                  /*  ASSUMPTIONS     */
   value0 = L1p1propagate(v3form, v2assumptions);
   {
    const int v7 = cl_env_copy->nvalues;
    cl_object v8;
    v8 = (v7<=1)? ECL_NIL : cl_env_copy->values[1];
    v6 = v8;
   }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v6;
   cl_env_copy->values[0] = ECL_NIL;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for P1GO                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L32p1go(cl_object v1c1form, cl_object v2assumptions, cl_object v3tag_var, cl_object v4return_type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = v2assumptions;
  cl_env_copy->values[0] = ECL_T;
  return cl_env_copy->values[0];
 }
}
/*	function definition for FILTER-ONLY-DECLARATIONS              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L33filter_only_declarations(cl_object v1assumptions)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1assumptions)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[57])(2, ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_6) /*  BABOON */;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for P1TAGBODY                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L34p1tagbody(cl_object v1c1form, cl_object v2orig_assumptions, cl_object v3tag_loc, cl_object v4body)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v5assumptions;
   cl_object v6ass_list;
   v5assumptions = L33filter_only_declarations(v2orig_assumptions);
   v6ass_list = L35p1tagbody_one_pass(v1c1form, v5assumptions, v3tag_loc, v4body);
   T0 = L6p1merge_branches(ECL_NIL, v6ass_list);
   T1 = ecl_append(T0,v2orig_assumptions);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = T1;
   cl_env_copy->values[0] = ECL_SYM("NULL",605);
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for P1TAGBODY-ONE-PASS                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L35p1tagbody_one_pass(cl_object v1c1form, cl_object v2assumptions, cl_object v3tag_loc, cl_object v4body)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v5local_ass;
   v5local_ass = v2assumptions;
   {
    cl_object v6ass_list;
    v6ass_list = ECL_NIL;
    {
     cl_object v7aux;
     v7aux = ECL_NIL;
     {
      cl_object v8f;
      cl_object v9;
      v8f = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v4body))) FEtype_error_list(v4body);
      v9 = v4body;
L7:;
      if (!(ecl_endp(v9))) { goto L9; }
      goto L8;
L9:;
      v8f = _ecl_car(v9);
      {
       cl_object v10;
       v10 = _ecl_cdr(v9);
       if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
       v9 = v10;
      }
      if (Null(ecl_function_dispatch(cl_env_copy,VV[108])(1, v8f) /*  TAG-P */)) { goto L18; }
      {
       cl_object v10diff;
       v10diff = cl_ldiff(v5local_ass, v2assumptions);
       if (Null(v10diff)) { goto L21; }
       v6ass_list = CONS(v10diff,v6ass_list);
L21:;
       v5local_ass = v2assumptions;
       goto L17;
      }
L18:;
      value0 = L1p1propagate(v8f, v5local_ass);
      v7aux = value0;
      {
       const int v11 = cl_env_copy->nvalues;
       cl_object v12;
       v12 = (v11<=1)? ECL_NIL : cl_env_copy->values[1];
       v5local_ass = v12;
      }
L17:;
      goto L7;
L8:;
      {
       cl_object v10diff;
       v10diff = cl_ldiff(v5local_ass, v2assumptions);
       if (Null(v10diff)) { goto L30; }
       value0 = CONS(v10diff,v6ass_list);
       cl_env_copy->nvalues = 1;
       return value0;
L30:;
       value0 = v6ass_list;
       cl_env_copy->nvalues = 1;
       return value0;
      }
     }
    }
   }
  }
 }
}
/*	function definition for P1UNWIND-PROTECT                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L36p1unwind_protect(cl_object v1c1form, cl_object v2assumptions, cl_object v3form, cl_object v4body)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6;                                  /*  OUTPUT-TYPE     */
   cl_object v7;                                  /*  ASSUMPTIONS     */
   value0 = L1p1propagate(v3form, v2assumptions);
   v6 = value0;
   {
    const int v8 = cl_env_copy->nvalues;
    cl_object v9;
    v9 = (v8<=1)? ECL_NIL : cl_env_copy->values[1];
    v7 = v9;
   }
   L1p1propagate(v4body, v7);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v7;
   cl_env_copy->values[0] = v6;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for TYPE-FROM-ARRAY-ELT                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L37type_from_array_elt(cl_object v1array)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2name;
   v2name = ECL_NIL;
   if (!((v1array)==(ECL_SYM("STRING",805)))) { goto L3; }
   T0 = ECL_SYM("CHARACTER",222);
   goto L2;
L3:;
   if (!((v1array)==(ECL_SYM("BASE-STRING",121)))) { goto L5; }
   T0 = ECL_SYM("BASE-CHAR",120);
   goto L2;
L5:;
   {
    cl_object v3;
    v1array = ecl_function_dispatch(cl_env_copy,VV[111])(1, v1array) /*  EXPAND-DEFTYPE */;
    v3 = v1array;
    if (!((v3)==(ECL_SYM("ARRAY",96)))) { goto L14; }
    goto L11;
    goto L12;
L14:;
    goto L12;
L12:;
    if (!((v3)==(ECL_SYM("VECTOR",898)))) { goto L18; }
    goto L11;
    goto L16;
L18:;
    goto L16;
L16:;
    if (!((v3)==(ECL_SYM("SIMPLE-ARRAY",763)))) { goto L7; }
    goto L8;
L11:;
   }
L8:;
   T0 = ECL_T;
   goto L2;
L7:;
   if (!(ECL_ATOM(v1array))) { goto L21; }
   v1array = ECL_SYM("ARRAY",96);
   T0 = ECL_T;
   goto L2;
L21:;
   v2name = ecl_car(v1array);
   if (!((v2name)==(ECL_SYM("OR",614)))) { goto L25; }
   {
    cl_object v3;
    cl_object v4;
    cl_object v5;
    v3 = ecl_cdr(v1array);
    v4 = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v3))) FEtype_error_list(v3);
    v5 = v3;
    {
     cl_object v6;
     cl_object v7;
     v6 = ecl_list1(ECL_NIL);
     v7 = v6;
L35:;
     if (!(ecl_endp(v5))) { goto L37; }
     goto L36;
L37:;
     v4 = _ecl_car(v5);
     {
      cl_object v8;
      v8 = _ecl_cdr(v5);
      if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
      v5 = v8;
     }
     if (ecl_unlikely(ECL_ATOM(v7))) FEtype_error_cons(v7);
     T2 = v7;
     T3 = L37type_from_array_elt(v4);
     v7 = ecl_list1(T3);
     (ECL_CONS_CDR(T2)=v7,T2);
     goto L35;
L36:;
     T1 = ecl_cdr(v6);
     goto L28;
    }
   }
L28:;
   T0 = CONS(ECL_SYM("OR",614),T1);
   goto L2;
L25:;
   v2name = ecl_car(v1array);
   if (!((v2name)==(ECL_SYM("AND",87)))) { goto L51; }
   {
    cl_object v3;
    cl_object v4;
    cl_object v5;
    v3 = ecl_cdr(v1array);
    v4 = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v3))) FEtype_error_list(v3);
    v5 = v3;
    {
     cl_object v6;
     cl_object v7;
     v6 = ecl_list1(ECL_NIL);
     v7 = v6;
L61:;
     if (!(ecl_endp(v5))) { goto L63; }
     goto L62;
L63:;
     v4 = _ecl_car(v5);
     {
      cl_object v8;
      v8 = _ecl_cdr(v5);
      if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
      v5 = v8;
     }
     if (ecl_unlikely(ECL_ATOM(v7))) FEtype_error_cons(v7);
     T2 = v7;
     T3 = L37type_from_array_elt(v4);
     v7 = ecl_list1(T3);
     (ECL_CONS_CDR(T2)=v7,T2);
     goto L61;
L62:;
     T1 = ecl_cdr(v6);
     goto L54;
    }
   }
L54:;
   T0 = CONS(ECL_SYM("AND",87),T1);
   goto L2;
L51:;
   {
    cl_object v3;
    v3 = ecl_car(v1array);
    if (!((v3)==(ECL_SYM("ARRAY",96)))) { goto L82; }
    goto L77;
    goto L80;
L82:;
    goto L80;
L80:;
    if (!((v3)==(ECL_SYM("VECTOR",898)))) { goto L86; }
    goto L77;
    goto L84;
L86:;
    goto L84;
L84:;
    if (!((v3)==(ECL_SYM("SIMPLE-ARRAY",763)))) { goto L89; }
    goto L77;
    goto L78;
L89:;
    goto L78;
   }
L78:;
   v1array = ECL_SYM("ARRAY",96);
   T0 = ECL_T;
   goto L2;
L77:;
   T1 = ecl_cdr(v1array);
   if (!(T1==ECL_NIL)) { goto L93; }
   T0 = ECL_T;
   goto L2;
L93:;
   {
    cl_object v3x;
    v3x = ecl_cadr(v1array);
    if (!((v3x)==(ECL_SYM("*",18)))) { goto L96; }
    T0 = ECL_T;
    goto L2;
L96:;
    T0 = v3x;
   }
L2:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v1array;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G97                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC38__g97(cl_narg narg, cl_object v1fname, cl_object v2array_type, ...)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3indices_and_object;
  ecl_va_list args; ecl_va_start(args,v2array_type,narg,2);
  v3indices_and_object = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v5;                                  /*  ELT-TYPE        */
   cl_object v6;                                  /*  ARRAY-TYPE      */
   value0 = L37type_from_array_elt(v2array_type);
   v5 = value0;
   {
    const int v7 = cl_env_copy->nvalues;
    cl_object v8;
    v8 = (v7<=1)? ECL_NIL : cl_env_copy->values[1];
    v6 = v8;
   }
   {
    cl_fixnum v7;
    v7 = ecl_length(v3indices_and_object);
    T0 = ecl_make_integer((v7)-1);
    T1 = cl_make_list(3, T0, ECL_SYM("INITIAL-ELEMENT",1251), VV[51]);
    T2 = ecl_list1(v5);
    T3 = ecl_nconc(T1,T2);
    T4 = CONS(v6,T3);
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = v5;
    cl_env_copy->values[0] = T4;
    return cl_env_copy->values[0];
   }
  }
 }
}
/*	local function G101                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC39__g101(cl_narg narg, cl_object v1fname, cl_object v2array_type, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3indices;
  ecl_va_list args; ecl_va_start(args,v2array_type,narg,2);
  v3indices = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v5;                                  /*  ELT-TYPE        */
   cl_object v6;                                  /*  ARRAY-TYPE      */
   value0 = L37type_from_array_elt(v2array_type);
   v5 = value0;
   {
    const int v7 = cl_env_copy->nvalues;
    cl_object v8;
    v8 = (v7<=1)? ECL_NIL : cl_env_copy->values[1];
    v6 = v8;
   }
   {
    cl_fixnum v7;
    v7 = ecl_length(v3indices);
    T0 = cl_make_list(3, ecl_make_fixnum(v7), ECL_SYM("INITIAL-ELEMENT",1251), VV[51]);
    T1 = CONS(v6,T0);
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = v5;
    cl_env_copy->values[0] = T1;
    return cl_env_copy->values[0];
   }
  }
 }
}
/*	local function G106                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC40__g106(cl_narg narg, cl_object v1fname, cl_object v2array_type, cl_object v3index, cl_object v4obj, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<4)) FEwrong_num_arguments_anonym();
 {
  {
   cl_object v6;                                  /*  ELT-TYPE        */
   cl_object v7;                                  /*  ARRAY-TYPE      */
   value0 = L37type_from_array_elt(v2array_type);
   v6 = value0;
   {
    const int v8 = cl_env_copy->nvalues;
    cl_object v9;
    v9 = (v8<=1)? ECL_NIL : cl_env_copy->values[1];
    v7 = v9;
   }
   T0 = cl_list(3, v7, VV[51], v6);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v6;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G111                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC41__g111(cl_narg narg, cl_object v1fname, cl_object v2array_type, cl_object v3index, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 {
  {
   cl_object v5;                                  /*  ELT-TYPE        */
   cl_object v6;                                  /*  ARRAY-TYPE      */
   value0 = L37type_from_array_elt(v2array_type);
   v5 = value0;
   {
    const int v7 = cl_env_copy->nvalues;
    cl_object v8;
    v8 = (v7<=1)? ECL_NIL : cl_env_copy->values[1];
    v6 = v8;
   }
   T0 = cl_list(2, v6, VV[51]);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}

#include "cmp/cmpprop.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecl2dRfhTzWw35r9_YW0UOE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPPROP.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_ecl2dRfhTzWw35r9_YW0UOE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[52]);                           /*  P1PROPAGATE     */
 ecl_cmp_defun(VV[61]);                           /*  P1TRIVIAL       */
 ecl_cmp_defun(VV[62]);                           /*  P1VAR           */
 ecl_cmp_defun(VV[66]);                           /*  P1VALUES        */
 ecl_cmp_defun(VV[68]);                           /*  P1PROPAGATE-LIST */
 ecl_cmp_defun(VV[69]);                           /*  P1MERGE-BRANCHES */
 ecl_cmp_defun(VV[70]);                           /*  REVISE-VAR-TYPE */
 ecl_cmp_defun(VV[71]);                           /*  P1BLOCK         */
 ecl_cmp_defun(VV[74]);                           /*  P1RETURN-FROM   */
 ecl_cmp_defun(VV[75]);                           /*  P1CALL-GLOBAL   */
 ecl_cmp_defun(VV[77]);                           /*  P1CALL-LOCAL    */
 ecl_cmp_defun(VV[79]);                           /*  P1CATCH         */
 ecl_cmp_defun(VV[80]);                           /*  P1THROW         */
 ecl_cmp_defun(VV[81]);                           /*  P1IF            */
 ecl_cmp_defun(VV[82]);                           /*  P1FMLA-NOT      */
 ecl_cmp_defun(VV[83]);                           /*  P1FMLA-AND      */
 ecl_cmp_defun(VV[85]);                           /*  P1FMLA-OR       */
 ecl_cmp_defun(VV[86]);                           /*  P1LAMBDA        */
 ecl_cmp_defun(VV[87]);                           /*  P1PROPAGATE-FUNCTION */
 ecl_cmp_defun(VV[89]);                           /*  P1LET*          */
 ecl_cmp_defun(VV[92]);                           /*  P1LOCALS        */
 ecl_cmp_defun(VV[93]);                           /*  P1MULTIPLE-VALUE-BIND */
 ecl_cmp_defun(VV[95]);                           /*  P1MULTIPLE-VALUE-SETQ */
 ecl_cmp_defun(VV[96]);                           /*  P1PROGN         */
 ecl_cmp_defun(VV[97]);                           /*  P1COMPILER-TYPECASE */
 ecl_cmp_defun(VV[98]);                           /*  P1CHECKED-VALUE */
 ecl_cmp_defun(VV[99]);                           /*  P1PROGV         */
 ecl_cmp_defun(VV[100]);                          /*  P1SETQ          */
 ecl_cmp_defun(VV[101]);                          /*  P1PSETQ         */
 ecl_cmp_defun(VV[102]);                          /*  P1WITH-STACK    */
 ecl_cmp_defun(VV[103]);                          /*  P1STACK-PUSH-VALUES */
 si_Xmake_special(VV[40]);
 if (ecl_boundp(cl_env_copy,VV[40])) { goto L128; }
 cl_set(VV[40],ecl_make_fixnum(-1));
L128:;
 ecl_cmp_defun(VV[104]);                          /*  P1GO            */
 ecl_cmp_defun(VV[105]);                          /*  FILTER-ONLY-DECLARATIONS */
 ecl_cmp_defun(VV[106]);                          /*  P1TAGBODY       */
 ecl_cmp_defun(VV[107]);                          /*  P1TAGBODY-ONE-PASS */
 ecl_cmp_defun(VV[109]);                          /*  P1UNWIND-PROTECT */
 ecl_cmp_defun(VV[110]);                          /*  TYPE-FROM-ARRAY-ELT */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC38__g97,ECL_NIL,Cblock);
  T0 = v1;
 }
 si_hash_set(ECL_SYM("ASET",1041), ecl_symbol_value(VV[50]), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC39__g101,ECL_NIL,Cblock);
  T0 = v1;
 }
 si_hash_set(ECL_SYM("AREF",92), ecl_symbol_value(VV[50]), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC40__g106,ECL_NIL,Cblock);
  T0 = v1;
 }
 si_hash_set(ECL_SYM("ROW-MAJOR-ASET",1130), ecl_symbol_value(VV[50]), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC41__g111,ECL_NIL,Cblock);
  T0 = v1;
 }
 si_hash_set(ECL_SYM("ROW-MAJOR-AREF",731), ecl_symbol_value(VV[50]), T0);
 }
}
