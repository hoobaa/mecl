/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPTAG.LSP                                    */
#include <ecl/ecl-cmp.h>
#include "cmp/cmptag.eclh"
/*	function definition for ADD-LOOP-REGISTERS                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3add_loop_registers(cl_object v1tagbody)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2v;
   cl_object v3end;
   cl_object v4first;
   v2v = v1tagbody;
   v3end = ECL_NIL;
   v4first = ECL_NIL;
   goto L6;
L5:;
   T0 = ecl_car(v2v);
   if (Null(ecl_function_dispatch(cl_env_copy,VV[31])(1, T0) /*  TAG-P */)) { goto L8; }
   if ((v4first)!=ECL_NIL) { goto L10; }
   v4first = v2v;
L10:;
   {
    cl_object v5;
    cl_object v6;
    cl_object v7w;
    v5 = ecl_cdr(v2v);
    T0 = ecl_car(v2v);
    v6 = ecl_function_dispatch(cl_env_copy,VV[32])(1, T0) /*  TAG-NAME */;
    v7w = v5;
    goto L18;
L17:;
    T0 = ecl_car(v7w);
    if (Null(LC2jumps_to_p(T0, v6))) { goto L20; }
    v3end = v7w;
L20:;
    v7w = ecl_cdr(v7w);
L18:;
    if (v7w==ECL_NIL) { goto L25; }
    goto L17;
L25:;
   }
L8:;
   v2v = ecl_cdr(v2v);
L6:;
   if (v2v==ECL_NIL) { goto L29; }
   goto L5;
L29:;
   {
    cl_object v5ww;
    v5ww = v4first;
    goto L34;
L33:;
    T0 = ecl_car(v5ww);
    LC1add_reg1(T0);
    v5ww = ecl_cdr(v5ww);
L34:;
    if ((v5ww)==(v3end)) { goto L39; }
    goto L33;
L39:;
    T0 = ecl_car(v5ww);
    value0 = LC1add_reg1(T0);
    return value0;
   }
  }
 }
}
/*	local function JUMPS-TO-P                                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC2jumps_to_p(cl_object v1clause, cl_object v2tag_name)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[33])(1, v1clause) /*  C1FORM-P */)) { goto L1; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[34])(1, v1clause) /*  C1FORM-NAME */;
  if (!((T0)==(ECL_SYM("GO",414)))) { goto L4; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[35])(1, v1clause) /*  C1FORM-ARGS */;
  T1 = ecl_car(T0);
  T2 = ecl_function_dispatch(cl_env_copy,VV[32])(1, T1) /*  TAG-NAME  */;
  value0 = ecl_make_bool((T2)==(v2tag_name));
  cl_env_copy->nvalues = 1;
  return value0;
L4:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (!(ECL_ATOM(v1clause))) { goto L6; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L6:;
  T0 = ecl_car(v1clause);
  value0 = LC2jumps_to_p(T0, v2tag_name);
  if ((value0)!=ECL_NIL) { goto L9; }
  v1clause = ecl_cdr(v1clause);
  goto TTL;
L9:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function ADD-REG1                                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC1add_reg1(cl_object v1form)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[33])(1, v1form) /*  C1FORM-P */)) { goto L1; }
  {
   cl_object v2;
   v2 = ecl_function_dispatch(cl_env_copy,VV[35])(1, v1form) /*  C1FORM-ARGS */;
   goto L6;
L5:;
   {
    cl_object v3v;
    v3v = ecl_car(v2);
    LC1add_reg1(v3v);
   }
   v2 = ecl_cdr(v2);
L6:;
   if (Null(v2)) { goto L13; }
   goto L5;
L13:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L1:;
  if (!(ECL_CONSP(v1form))) { goto L15; }
  {
   cl_object v3;
   v3 = v1form;
   goto L20;
L19:;
   {
    cl_object v4v;
    v4v = ecl_car(v3);
    LC1add_reg1(v4v);
   }
   v3 = ecl_cdr(v3);
L20:;
   if (Null(v3)) { goto L27; }
   goto L19;
L27:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L15:;
  if (Null(ecl_function_dispatch(cl_env_copy,VV[36])(1, v1form) /*  VAR-P */)) { goto L29; }
  value0 = ecl_structure_set(v1form,VV[1],1,ecl_make_fixnum(2305843009213693951));
  cl_env_copy->nvalues = 1;
  return value0;
L29:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for C1TAGBODY                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4c1tagbody(cl_object v1orig_body)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2tag_var;
   cl_object v3tag_index;
   cl_object v4body;
   T0 = ecl_function_dispatch(cl_env_copy,VV[38])(0) /*  CMP-ENV-COPY */;
   ecl_bds_bind(cl_env_copy,VV[3],T0);            /*  *CMP-ENV*       */
   v2tag_var = ecl_function_dispatch(cl_env_copy,VV[39])(4, ECL_SYM("NAME",1273), ECL_SYM("TAGBODY",850), VV[4], ECL_NIL) /*  MAKE-VAR */;
   v3tag_index = ecl_make_fixnum(0);
   v4body = ECL_NIL;
   {
    cl_object v5x;
    cl_object v6;
    v5x = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v1orig_body))) FEtype_error_list(v1orig_body);
    v6 = v1orig_body;
    {
     cl_object v7;
     cl_object v8;
     v7 = ecl_list1(ECL_NIL);
     v8 = v7;
L11:;
     if (!(ecl_endp(v6))) { goto L13; }
     goto L12;
L13:;
     v5x = _ecl_car(v6);
     {
      cl_object v9;
      v9 = _ecl_cdr(v6);
      if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
      v6 = v9;
     }
     if (ecl_unlikely(ECL_ATOM(v8))) FEtype_error_cons(v8);
     T0 = v8;
     if (!(ECL_CONSP(v5x))) { goto L26; }
     T1 = v5x;
     goto L25;
L26:;
     {
      cl_object v9tag;
      v9tag = ecl_function_dispatch(cl_env_copy,VV[40])(6, ECL_SYM("NAME",1273), v5x, VV[5], v2tag_var, VV[6], v3tag_index) /*  MAKE-TAG */;
      T2 = ecl_function_dispatch(cl_env_copy,VV[32])(1, v9tag) /*  TAG-NAME */;
      ecl_function_dispatch(cl_env_copy,VV[41])(2, T2, v9tag) /*  CMP-ENV-REGISTER-TAG */;
      v3tag_index = ecl_plus(v3tag_index,ecl_make_fixnum(1));
      T1 = v9tag;
     }
L25:;
     v8 = ecl_list1(T1);
     (ECL_CONS_CDR(T0)=v8,T0);
     goto L11;
L12:;
     v4body = ecl_cdr(v7);
     goto L5;
    }
   }
L5:;
   {
    cl_object v5;
    cl_object v6form;
    cl_object v7;
    v5 = v4body;
    v6form = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
    v7 = v5;
    {
     cl_object v8output;
     v8output = ECL_NIL;
     {
      cl_object v9tag_body;
      v9tag_body = ECL_NIL;
      {
       cl_object v10this_tag;
       v10this_tag = ecl_function_dispatch(cl_env_copy,VV[39])(4, ECL_SYM("NAME",1273), VV[7], VV[4], ECL_NIL) /*  MAKE-VAR */;
L42:;
       if (!(ecl_endp(v7))) { goto L44; }
       goto L43;
L44:;
       v6form = _ecl_car(v7);
       {
        cl_object v11;
        v11 = _ecl_cdr(v7);
        if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
        v7 = v11;
       }
       if (Null(ecl_function_dispatch(cl_env_copy,VV[31])(1, v6form) /*  TAG-P */)) { goto L53; }
       if (Null(v9tag_body)) { goto L55; }
       T0 = cl_nreconc(v9tag_body, VV[8]);
       T1 = ecl_function_dispatch(cl_env_copy,VV[42])(1, T0) /*  C1PROGN */;
       v8output = CONS(T1,v8output);
       v9tag_body = ECL_NIL;
L55:;
       v8output = CONS(v6form,v8output);
       goto L52;
L53:;
       v9tag_body = CONS(v6form,v9tag_body);
L52:;
       goto L42;
L43:;
       if (Null(v9tag_body)) { goto L65; }
       T0 = cl_nreconc(v9tag_body, VV[8]);
       T1 = ecl_function_dispatch(cl_env_copy,VV[42])(1, T0) /*  C1PROGN */;
       v4body = CONS(T1,v8output);
       goto L64;
L65:;
       v4body = v8output;
L64:;
      }
     }
    }
   }
   {
    cl_object v5;
    cl_object v6form;
    cl_object v7;
    v5 = v4body;
    v6form = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
    v7 = v5;
    {
     cl_object v8output;
     v8output = ECL_NIL;
L73:;
     if (!(ecl_endp(v7))) { goto L75; }
     goto L74;
L75:;
     v6form = _ecl_car(v7);
     {
      cl_object v9;
      v9 = _ecl_cdr(v7);
      if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
      v7 = v9;
     }
     if (Null(ecl_function_dispatch(cl_env_copy,VV[31])(1, v6form) /*  TAG-P */)) { goto L85; }
     T0 = ecl_function_dispatch(cl_env_copy,VV[43])(1, v6form) /*  TAG-REF */;
     if (!(ecl_plusp(T0))) { goto L83; }
     goto L84;
L85:;
L84:;
     v8output = CONS(v6form,v8output);
L83:;
     goto L73;
L74:;
     v4body = v8output;
    }
   }
   if (!(v4body==ECL_NIL)) { goto L91; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[42])(1, ECL_NIL) /*  C1PROGN */;
   ecl_bds_unwind1(cl_env_copy);
   return value0;
L91:;
   T0 = ecl_last(v4body,1);
   T1 = ecl_car(T0);
   if (Null(ecl_function_dispatch(cl_env_copy,VV[31])(1, T1) /*  TAG-P */)) { goto L93; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[44])(1, ECL_NIL) /*  C1EXPR */;
   T1 = ecl_list1(T0);
   v4body = ecl_nconc(v4body,T1);
L93:;
   T0 = ecl_function_dispatch(cl_env_copy,VV[45])(1, v2tag_var) /*  VAR-REF */;
   if (!(ecl_zerop(T0))) { goto L96; }
   T0 = ecl_fdefinition(VV[31]);
   T1 = cl_delete_if(2, T0, v4body);
   value0 = ecl_function_dispatch(cl_env_copy,VV[46])(3, ECL_SYM("PROGN",671), VV[9], T1) /*  MAKE-C1FORM* */;
   ecl_bds_unwind1(cl_env_copy);
   return value0;
L96:;
   if (Null(ecl_function_dispatch(cl_env_copy,VV[47])(1, v2tag_var) /*  VAR-REF-CCB */)) { goto L99; }
   cl_set(VV[10],ecl_plus(ecl_symbol_value(VV[10]),ecl_make_fixnum(1)));
L99:;
   L3add_loop_registers(v4body);
   T0 = ecl_list1(v2tag_var);
   value0 = ecl_function_dispatch(cl_env_copy,VV[46])(6, ECL_SYM("TAGBODY",850), VV[11], T0, VV[9], v2tag_var, v4body) /*  MAKE-C1FORM* */;
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
 }
}
/*	function definition for C2TAGBODY                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5c2tagbody(cl_object v1c1form, cl_object v2tag_loc, cl_object v3body)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[49])(1, v2tag_loc) /*  VAR-KIND */;
  if (!(T0==ECL_NIL)) { goto L1; }
  {
   cl_object v4;
   v4 = v3body;
   goto L6;
L5:;
   {
    cl_object v5x;
    v5x = ecl_car(v4);
    if (Null(ecl_function_dispatch(cl_env_copy,VV[31])(1, v5x) /*  TAG-P */)) { goto L10; }
    T0 = ecl_function_dispatch(cl_env_copy,VV[43])(1, v5x) /*  TAG-REF */;
    if (!(ecl_plusp(T0))) { goto L10; }
    {
     cl_object v6;
     v6 = ecl_function_dispatch(cl_env_copy,VV[50])(0) /*  NEXT-LABEL* */;
     ecl_structure_set(v5x,VV[13],5,v6);
    }
    {
     cl_object v6;
     v6 = ecl_symbol_value(VV[14]);
     ecl_structure_set(v5x,VV[13],6,v6);
    }
L10:;
   }
   v4 = ecl_cdr(v4);
L6:;
   if (Null(v4)) { goto L18; }
   goto L5;
L18:;
   value0 = L6c2tagbody_body(v3body);
   return value0;
  }
L1:;
  {
   cl_object v5;
   cl_object v6;
   cl_object v7;
   cl_object v8;
   cl_object v9;
   cl_object v10;
   cl_object v11env_grows;
   v5 = CONS(VV[15],ecl_symbol_value(VV[14]));
   v6 = ecl_symbol_value(VV[16]);
   v7 = ecl_symbol_value(VV[17]);
   v8 = ecl_symbol_value(VV[18]);
   v9 = ecl_symbol_value(VV[19]);
   T0 = ecl_function_dispatch(cl_env_copy,VV[47])(1, v2tag_loc) /*  VAR-REF-CCB */;
   v10 = ecl_function_dispatch(cl_env_copy,VV[51])(1, T0) /*  ENV-GROWS */;
   ecl_bds_bind(cl_env_copy,VV[14],v5);           /*  *UNWIND-EXIT*   */
   ecl_bds_bind(cl_env_copy,VV[16],v6);           /*  *ENV*           */
   ecl_bds_bind(cl_env_copy,VV[17],v7);           /*  *ENV-LVL*       */
   ecl_bds_bind(cl_env_copy,VV[18],v8);           /*  *LEX*           */
   ecl_bds_bind(cl_env_copy,VV[19],v9);           /*  *LCL*           */
   ecl_bds_bind(cl_env_copy,VV[20],ecl_make_fixnum(0)); /*  *INLINE-BLOCKS* */
   v11env_grows = v10;
   if (Null(v11env_grows)) { goto L27; }
   {
    cl_object v12env_lvl;
    v12env_lvl = ecl_symbol_value(VV[17]);
    ecl_function_dispatch(cl_env_copy,VV[52])(0)  /*  MAYBE-OPEN-INLINE-BLOCK */;
    cl_set(VV[17],ecl_plus(ecl_symbol_value(VV[17]),ecl_make_fixnum(1)));
    T0 = ecl_symbol_value(VV[17]);
    ecl_function_dispatch(cl_env_copy,VV[53])(5, _ecl_static_1, T0, _ecl_static_2, v12env_lvl, _ecl_static_3) /*  WT-NL */;
   }
L27:;
   T0 = ecl_function_dispatch(cl_env_copy,VV[49])(1, v2tag_loc) /*  VAR-KIND */;
   if (!((ECL_SYM("OBJECT",1278))==(T0))) { goto L33; }
   {
    cl_object v12;
    v12 = ecl_function_dispatch(cl_env_copy,VV[54])(0) /*  NEXT-LCL   */;
    ecl_structure_set(v2tag_loc,VV[1],10,v12);
   }
   ecl_function_dispatch(cl_env_copy,VV[52])(0)   /*  MAYBE-OPEN-INLINE-BLOCK */;
   ecl_function_dispatch(cl_env_copy,VV[53])(3, _ecl_static_4, v2tag_loc, _ecl_static_3) /*  WT-NL */;
   v11env_grows = ECL_T;
L33:;
   ecl_function_dispatch(cl_env_copy,VV[55])(2, _ecl_static_5, v2tag_loc) /*  BIND */;
   ecl_function_dispatch(cl_env_copy,VV[53])(3, _ecl_static_6, v2tag_loc, _ecl_static_7) /*  WT-NL */;
   {
    cl_object v12;
    v12 = v3body;
    goto L46;
L45:;
    {
     cl_object v13tag;
     v13tag = ecl_car(v12);
     if (Null(ecl_function_dispatch(cl_env_copy,VV[31])(1, v13tag) /*  TAG-P */)) { goto L50; }
     T0 = ecl_function_dispatch(cl_env_copy,VV[43])(1, v13tag) /*  TAG-REF */;
     if (!(ecl_plusp(T0))) { goto L50; }
     {
      cl_object v14;
      v14 = ecl_function_dispatch(cl_env_copy,VV[56])(0) /*  NEXT-LABEL */;
      ecl_structure_set(v13tag,VV[13],5,v14);
     }
     {
      cl_object v14;
      v14 = ecl_symbol_value(VV[14]);
      ecl_structure_set(v13tag,VV[13],6,v14);
     }
     T0 = ecl_function_dispatch(cl_env_copy,VV[57])(1, v13tag) /*  TAG-INDEX */;
     ecl_function_dispatch(cl_env_copy,VV[53])(3, _ecl_static_8, T0, _ecl_static_9) /*  WT-NL */;
     T0 = ecl_function_dispatch(cl_env_copy,VV[58])(1, v13tag) /*  TAG-LABEL */;
     ecl_function_dispatch(cl_env_copy,VV[59])(1, T0) /*  WT-GO       */;
L50:;
    }
    v12 = ecl_cdr(v12);
L46:;
    if (Null(v12)) { goto L60; }
    goto L45;
L60:;
   }
   if (Null(ecl_function_dispatch(cl_env_copy,VV[47])(1, v2tag_loc) /*  VAR-REF-CCB */)) { goto L62; }
   ecl_function_dispatch(cl_env_copy,VV[53])(1, _ecl_static_10) /*  WT-NL */;
L62:;
   ecl_function_dispatch(cl_env_copy,VV[53])(1, _ecl_static_11) /*  WT-NL */;
   L6c2tagbody_body(v3body);
   value0 = ecl_function_dispatch(cl_env_copy,VV[60])(0) /*  CLOSE-INLINE-BLOCKS */;
   ecl_bds_unwind_n(cl_env_copy,6);
   return value0;
  }
 }
}
/*	function definition for C2TAGBODY-BODY                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6c2tagbody_body(cl_object v1body)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2l;
   v2l = v1body;
   goto L4;
L3:;
   {
    cl_object v3this_form;
    v3this_form = ecl_car(v2l);
    if (Null(ecl_function_dispatch(cl_env_copy,VV[31])(1, v3this_form) /*  TAG-P */)) { goto L8; }
    T0 = ecl_function_dispatch(cl_env_copy,VV[58])(1, v3this_form) /*  TAG-LABEL */;
    ecl_function_dispatch(cl_env_copy,VV[62])(1, T0) /*  WT-LABEL     */;
    goto L6;
L8:;
    T0 = ecl_cdr(v2l);
    if (!(ecl_endp(T0))) { goto L10; }
    ecl_function_dispatch(cl_env_copy,VV[63])(1, v3this_form) /*  C2EXPR */;
    goto L6;
L10:;
    {
     cl_object v4next_form;
     v4next_form = ecl_cadr(v2l);
     if (Null(ecl_function_dispatch(cl_env_copy,VV[31])(1, v4next_form) /*  TAG-P */)) { goto L14; }
     T0 = ecl_function_dispatch(cl_env_copy,VV[58])(1, v4next_form) /*  TAG-LABEL */;
     goto L13;
L14:;
     T0 = ecl_function_dispatch(cl_env_copy,VV[56])(0) /*  NEXT-LABEL */;
L13:;
     ecl_bds_bind(cl_env_copy,VV[22],T0);         /*  *EXIT*          */
     T0 = CONS(ecl_symbol_value(VV[22]),ecl_symbol_value(VV[14]));
     ecl_bds_bind(cl_env_copy,VV[14],T0);         /*  *UNWIND-EXIT*   */
     ecl_bds_bind(cl_env_copy,VV[23],VV[24]);     /*  *DESTINATION*   */
     ecl_function_dispatch(cl_env_copy,VV[63])(1, v3this_form) /*  C2EXPR */;
     if ((ecl_function_dispatch(cl_env_copy,VV[31])(1, v4next_form) /*  TAG-P */)!=ECL_NIL) {
     ecl_bds_unwind1(cl_env_copy);
     ecl_bds_unwind1(cl_env_copy);
     ecl_bds_unwind1(cl_env_copy);
      goto L6;
     }
     ecl_function_dispatch(cl_env_copy,VV[62])(1, ecl_symbol_value(VV[22])) /*  WT-LABEL */;
     ecl_bds_unwind1(cl_env_copy);
     ecl_bds_unwind1(cl_env_copy);
     ecl_bds_unwind1(cl_env_copy);
    }
   }
L6:;
   v2l = ecl_cdr(v2l);
L4:;
   if (v2l==ECL_NIL) { goto L20; }
   goto L3;
L20:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for C1GO                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7c1go(cl_object v1args)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_function_dispatch(cl_env_copy,VV[65])(4, ECL_SYM("GO",414), v1args, ecl_make_fixnum(1), ecl_make_fixnum(1)) /*  CHECK-ARGS-NUMBER */;
  {
   cl_object v2name;
   v2name = ecl_car(v1args);
   if (ECL_SYMBOLP(v2name)) { goto L3; }
   if (ECL_FIXNUMP(v2name)||ECL_BIGNUMP(v2name)) { goto L3; }
   ecl_function_dispatch(cl_env_copy,VV[66])(2, _ecl_static_12, v2name) /*  CMPERR */;
L3:;
   {
    cl_object v4;                                 /*  TAG             */
    cl_object v5;                                 /*  CCB             */
    cl_object v6;                                 /*  CLB             */
    cl_object v7;                                 /*  UNW             */
    value0 = ecl_function_dispatch(cl_env_copy,VV[67])(1, v2name) /*  CMP-ENV-SEARCH-TAG */;
    v4 = value0;
    {
     const int v8 = cl_env_copy->nvalues;
     cl_object v9;
     v9 = (v8<=1)? ECL_NIL : cl_env_copy->values[1];
     v5 = v9;
     v9 = (v8<=2)? ECL_NIL : cl_env_copy->values[2];
     v6 = v9;
     v9 = (v8<=3)? ECL_NIL : cl_env_copy->values[3];
     v7 = v9;
    }
    if ((v4)!=ECL_NIL) { goto L7; }
    ecl_function_dispatch(cl_env_copy,VV[66])(2, _ecl_static_13, v2name) /*  CMPERR */;
L7:;
    {
     cl_object v8var;
     v8var = ecl_function_dispatch(cl_env_copy,VV[68])(1, v4) /*  TAG-VAR */;
     if (Null(v5)) { goto L11; }
     ecl_structure_set(v4,VV[13],2,ECL_T);
     ecl_structure_set(v8var,VV[1],2,ECL_T);
     ecl_structure_set(v8var,VV[1],6,VV[26]);
     goto L10;
L11:;
     if (Null(v6)) { goto L15; }
     ecl_structure_set(v4,VV[13],3,ECL_T);
     ecl_structure_set(v8var,VV[1],3,ECL_T);
     ecl_structure_set(v8var,VV[1],6,VV[27]);
     goto L10;
L15:;
     if (Null(v7)) { goto L10; }
     if ((ecl_function_dispatch(cl_env_copy,VV[49])(1, v8var) /*  VAR-KIND */)!=ECL_NIL) { goto L10; }
     ecl_structure_set(v8var,VV[1],6,ECL_SYM("OBJECT",1278));
L10:;
     {
      cl_object v9;
      T0 = ecl_function_dispatch(cl_env_copy,VV[43])(1, v4) /*  TAG-REF */;
      v9 = ecl_plus(T0,ecl_make_fixnum(1));
      ecl_structure_set(v4,VV[13],1,v9);
     }
     value0 = v5;
     if ((value0)!=ECL_NIL) { goto L25; }
     value0 = v6;
     if ((value0)!=ECL_NIL) { goto L25; }
     T0 = v7;
     goto L23;
L25:;
     T0 = value0;
     goto L23;
L23:;
     T1 = ecl_function_dispatch(cl_env_copy,VV[46])(4, ECL_SYM("GO",414), VV[9], v4, T0) /*  MAKE-C1FORM* */;
     value0 = ecl_function_dispatch(cl_env_copy,VV[69])(2, v8var, T1) /*  ADD-TO-READ-NODES */;
     return value0;
    }
   }
  }
 }
}
/*	function definition for C2GO                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8c2go(cl_object v1c1form, cl_object v2tag, cl_object v3nonlocal)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v3nonlocal)) { goto L1; }
  {
   cl_object v4var;
   v4var = ecl_function_dispatch(cl_env_copy,VV[68])(1, v2tag) /*  TAG-VAR */;
   T0 = ecl_function_dispatch(cl_env_copy,VV[57])(1, v2tag) /*  TAG-INDEX */;
   value0 = ecl_function_dispatch(cl_env_copy,VV[53])(5, _ecl_static_14, v4var, _ecl_static_15, T0, _ecl_static_16) /*  WT-NL */;
   return value0;
  }
L1:;
  T0 = ecl_function_dispatch(cl_env_copy,VV[71])(1, v2tag) /*  TAG-UNWIND-EXIT */;
  ecl_function_dispatch(cl_env_copy,VV[72])(1, T0) /*  UNWIND-NO-EXIT-UNTIL */;
  ecl_function_dispatch(cl_env_copy,VV[53])(0)    /*  WT-NL           */;
  T0 = ecl_function_dispatch(cl_env_copy,VV[58])(1, v2tag) /*  TAG-LABEL */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[59])(1, T0) /*  WT-GO */;
  return value0;
 }
}

#include "cmp/cmptag.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecl829MryKD13Co9_aCzTOE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPTAG.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_ecl829MryKD13Co9_aCzTOE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 si_Xmake_special(VV[0]);
 if (ecl_boundp(cl_env_copy,VV[0])) { goto L3; }
 cl_set(VV[0],ecl_make_fixnum(60));
L3:;
 ecl_cmp_defun(VV[30]);                           /*  ADD-LOOP-REGISTERS */
 ecl_cmp_defun(VV[37]);                           /*  C1TAGBODY       */
 ecl_cmp_defun(VV[48]);                           /*  C2TAGBODY       */
 ecl_cmp_defun(VV[61]);                           /*  C2TAGBODY-BODY  */
 ecl_cmp_defun(VV[64]);                           /*  C1GO            */
 ecl_cmp_defun(VV[70]);                           /*  C2GO            */
}
