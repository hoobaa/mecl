/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:LSP;DEFSTRUCT.LSP                                 */
#include <ecl/ecl-cmp.h>
#include "lsp/defstruct.eclh"
/*	function definition for STRUCTURE-TYPE-ERROR                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_structure_type_error(cl_narg narg, cl_object v1value, cl_object v2slot_type, cl_object v3struct_name, cl_object v4slot_name, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg!=4)) FEwrong_num_arguments_anonym();
 {
TTL:
  T0 = cl_list(3, v4slot_name, v3struct_name, v2slot_type);
  value0 = cl_error(9, ECL_SYM("SIMPLE-TYPE-ERROR",773), ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_1, ECL_SYM("FORMAT-ARGUMENTS",1239), T0, ECL_SYM("DATUM",1214), v1value, ECL_SYM("EXPECTED-TYPE",1232), v2slot_type);
  return value0;
 }
}
/*	function definition for MAKE-ACCESS-FUNCTION                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5make_access_function(cl_object v1name, cl_object v2conc_name, cl_object v3type, cl_object v4named, cl_object v5slot_descr)
{
 cl_object T0, T1;
 cl_object env0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1name,env0);                /*  NAME            */
  {
   cl_object v6slot_name;
   cl_object v7read_only;
   cl_object v8access_function;
   cl_object env1 = env0;
   v6slot_name = ecl_car(v5slot_descr);
   v7read_only = ecl_cadddr(v5slot_descr);
   T0 = ecl_cddddr(v5slot_descr);
   T1 = ecl_car(T0);
   CLV1 = env1 = CONS(T1,env1);                   /*  OFFSET          */
   if (Null(v2conc_name)) { goto L4; }
   T0 = si_base_string_concatenate(2, v2conc_name, v6slot_name);
   v8access_function = cl_intern(1, T0);
   goto L3;
L4:;
   v8access_function = v6slot_name;
L3:;
   T0 = ecl_cddddr(v5slot_descr);
   T1 = ecl_cadr(T0);
   if (!(ecl_eql(v8access_function,T1))) { goto L7; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L7:;
   {
    cl_object v9;
    T1 = ecl_cddddr(v5slot_descr);
    v9 = ecl_cdr(T1);
    if (ecl_unlikely(ECL_ATOM(v9))) FEtype_error_cons(v9);
    T0 = v9;
   }
   (ECL_CONS_CAR(T0)=v8access_function,T0);
   if (!(v3type==ECL_NIL)) { goto L14; }
   {cl_object v9;
    v9 = ECL_NIL;
    v9 = ecl_make_cclosure_va((cl_objectfn)LC2__g3,env1,Cblock);
    T0 = v9;
   }
   si_fset(4, v8access_function, T0, ECL_NIL, ECL_NIL);
   goto L13;
L14:;
   if (Null(cl_subtypep(2, v3type, VV[1]))) { goto L17; }
   {cl_object v9;
    v9 = ECL_NIL;
    v9 = ecl_make_cclosure_va((cl_objectfn)LC4__g5,env1,Cblock);
    T0 = v9;
   }
   si_fset(4, v8access_function, T0, ECL_NIL, ECL_NIL);
   goto L13;
L17:;
   cl_error(2, _ecl_static_2, v3type);
L13:;
   if (Null(v7read_only)) { goto L20; }
   T0 = cl_list(2, ECL_SYM("SETF",750), v8access_function);
   cl_fmakunbound(T0);
   value0 = si_set_documentation(3, v8access_function, ECL_SYM("SETF",750), ECL_NIL);
   return value0;
L20:;
   value0 = v3type;
   if ((value0)!=ECL_NIL) { goto L25; }
   T0 = ECL_CONS_CAR(CLV0);
   goto L23;
L25:;
   T0 = value0;
   goto L23;
L23:;
   value0 = L9do_setf_structure_method(v8access_function, T0, ECL_CONS_CAR(CLV1));
   return value0;
  }
 }
}
/*	closure G3                                                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC2__g3(cl_narg narg, cl_object v1x, ...)
{
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  OFFSET          */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = si_structure_ref(v1x, ECL_CONS_CAR(CLV0), ECL_CONS_CAR(CLV1));
  return value0;
 }
 }
}
/*	closure G5                                                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC4__g5(cl_narg narg, cl_object v1x, ...)
{
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  OFFSET          */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = ecl_elt(v1x,ecl_fixnum(ECL_CONS_CAR(CLV1)));
  cl_env_copy->nvalues = 1;
  return value0;
 }
 }
}
/*	function definition for DO-SETF-STRUCTURE-METHOD              */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object L9do_setf_structure_method(cl_object v1access_function, cl_object v2type, cl_object v3index)
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 env0 = ECL_NIL;
 CLV0 = env0 = CONS(v2type,env0);                 /*  TYPE            */
 CLV1 = env0 = CONS(v3index,env0);                /*  INDEX           */
 T0 = CONS(ECL_CONS_CAR(CLV0),ECL_CONS_CAR(CLV1));
 si_put_sysprop(v1access_function, VV[2], T0);
 if ((ECL_CONS_CAR(CLV0))==(ECL_SYM("LIST",481))) { goto L5; }
 if (!((ECL_CONS_CAR(CLV0))==(ECL_SYM("VECTOR",898)))) { goto L3; }
 goto L4;
L5:;
L4:;
 {cl_object v4;
  v4 = ECL_NIL;
  v4 = ecl_make_cclosure_va((cl_objectfn)LC6__g6,env0,Cblock);
  T0 = v4;
  goto L2;
 }
L3:;
 if (!(ECL_CONSP(ECL_CONS_CAR(CLV0)))) { goto L7; }
 {cl_object v5;
  v5 = ECL_NIL;
  v5 = ecl_make_cclosure_va((cl_objectfn)LC7__g7,env0,Cblock);
  T0 = v5;
  goto L2;
 }
L7:;
 {cl_object v6;
  v6 = ECL_NIL;
  v6 = ecl_make_cclosure_va((cl_objectfn)LC8__g8,env0,Cblock);
  T0 = v6;
 }
L2:;
 value0 = si_do_defsetf(v1access_function, T0);
 return value0;
}
/*	closure G6                                                    */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object LC6__g6(cl_narg narg, cl_object v1newvalue, cl_object v2struct, ...)
{
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  INDEX           */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
TTL:
 value0 = cl_list(4, ECL_SYM("ELT-SET",1066), v2struct, ECL_CONS_CAR(CLV1), v1newvalue);
 return value0;
 }
}
/*	closure G7                                                    */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object LC7__g7(cl_narg narg, cl_object v1newvalue, cl_object v2struct, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  INDEX           */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
TTL:
 T0 = cl_list(3, ECL_SYM("THE",856), ECL_CONS_CAR(CLV0), v2struct);
 value0 = cl_list(4, ECL_SYM("ASET",1041), T0, ECL_CONS_CAR(CLV1), v1newvalue);
 return value0;
 }
}
/*	closure G8                                                    */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object LC8__g8(cl_narg narg, cl_object v1newvalue, cl_object v2struct, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  INDEX           */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
TTL:
 T0 = cl_list(2, ECL_SYM("QUOTE",679), ECL_CONS_CAR(CLV0));
 value0 = cl_list(5, ECL_SYM("STRUCTURE-SET",1154), v2struct, T0, ECL_CONS_CAR(CLV1), v1newvalue);
 return value0;
 }
}
/*	function definition for PROCESS-BOA-LAMBDA-LIST               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L10process_boa_lambda_list(cl_object v1slot_names, cl_object v2slot_descriptions, cl_object v3boa_list, cl_object v4assertions)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v5mentioned_slots;
   cl_object v6aux;
   v5mentioned_slots = ECL_NIL;
   v6aux = ECL_NIL;
   v3boa_list = cl_copy_list(v3boa_list);
   si_process_lambda_list(v3boa_list, ECL_SYM("FUNCTION",396));
   {
    cl_object v7i;
    cl_object v8slot;
    cl_object v9modify;
    v7i = v3boa_list;
    v8slot = ecl_car(v7i);
    v9modify = ECL_NIL;
    goto L11;
L10:;
    if ((v8slot)==(ECL_SYM("&OPTIONAL",11))) { goto L16; }
    if (!((v8slot)==(ECL_SYM("&KEY",10)))) { goto L14; }
    goto L15;
L16:;
L15:;
    v9modify = ECL_T;
    goto L13;
L14:;
    if (!((v8slot)==(ECL_SYM("&REST",12)))) { goto L19; }
    v9modify = ECL_NIL;
    goto L13;
L19:;
    if (!((v8slot)==(ECL_SYM("&AUX",7)))) { goto L22; }
    v6aux = ECL_T;
    v9modify = ECL_NIL;
    goto L13;
L22:;
    {
     cl_object v10;
     v10 = ecl_make_bool((v8slot)==(ECL_SYM("&ALLOW-OTHER-KEYS",6)));
     if (Null(v10)) { goto L28; }
     goto L13;
L28:;
     if (!(ECL_ATOM(v8slot))) { goto L30; }
     v5mentioned_slots = CONS(v8slot,v5mentioned_slots);
     if (Null(v9modify)) { goto L34; }
     {
      cl_object v11;
      T0 = ecl_assql(v8slot,v2slot_descriptions);
      T1 = ecl_cadr(T0);
      v11 = cl_list(2, v8slot, T1);
      if (ecl_unlikely(ECL_ATOM(v7i))) FEtype_error_cons(v7i);
      T0 = v7i;
      (ECL_CONS_CAR(T0)=v11,T0);
     }
L34:;
     if (Null(v6aux)) { goto L13; }
     v4assertions = cl_delete(4, v8slot, v4assertions, ECL_SYM("KEY",1262), ECL_SYM("CADADR",173));
     goto L13;
L30:;
     {
      cl_object v11slot_name;
      v11slot_name = ecl_car(v8slot);
      if (!(ECL_CONSP(v11slot_name))) { goto L44; }
      v11slot_name = ecl_cadr(v11slot_name);
L44:;
      v5mentioned_slots = CONS(v11slot_name,v5mentioned_slots);
      T0 = ecl_cdr(v8slot);
      if (!(ecl_endp(T0))) { goto L13; }
      if (Null(v9modify)) { goto L50; }
      {
       cl_object v12;
       T0 = ecl_assql(v11slot_name,v2slot_descriptions);
       T1 = ecl_cadr(T0);
       v12 = ecl_list1(T1);
       if (ecl_unlikely(ECL_ATOM(v8slot))) FEtype_error_cons(v8slot);
       T0 = v8slot;
       (ECL_CONS_CDR(T0)=v12,T0);
      }
L50:;
      if (Null(v6aux)) { goto L13; }
      v4assertions = cl_delete(4, v8slot, v4assertions, ECL_SYM("KEY",1262), ECL_SYM("CADADR",173));
     }
    }
L13:;
    v7i = ecl_cdr(v7i);
    v8slot = ecl_car(v7i);
L11:;
    if (ecl_endp(v7i)) { goto L63; }
    goto L10;
L63:;
   }
   {
    cl_object v7other_slots;
    T0 = (ECL_SYM("CONSP",252)->symbol.gfdef);
    T1 = cl_copy_list(v1slot_names);
    T2 = cl_delete_if(2, T0, T1);
    v7other_slots = cl_nset_difference(2, T2, v5mentioned_slots);
    {
     cl_object v8l;
     v8l = v7other_slots;
     goto L71;
L70:;
     {
      cl_object v9slot;
      cl_object v10slot_init;
      T0 = ecl_car(v8l);
      v9slot = ecl_assql(T0,v2slot_descriptions);
      v10slot_init = ecl_cadr(v9slot);
      if (Null(v10slot_init)) { goto L73; }
      {
       cl_object v11;
       T0 = ecl_car(v8l);
       v11 = cl_list(2, T0, v10slot_init);
       if (ecl_unlikely(ECL_ATOM(v8l))) FEtype_error_cons(v8l);
       T0 = v8l;
       (ECL_CONS_CAR(T0)=v11,T0);
      }
     }
L73:;
     v8l = ecl_cdr(v8l);
L71:;
     if (ecl_endp(v8l)) { goto L83; }
     goto L70;
L83:;
    }
    if (Null(v7other_slots)) { goto L85; }
    if ((v6aux)!=ECL_NIL) { goto L87; }
    v7other_slots = CONS(ECL_SYM("&AUX",7),v7other_slots);
L87:;
    v3boa_list = ecl_nconc(v3boa_list,v7other_slots);
L85:;
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = v4assertions;
    cl_env_copy->values[0] = v3boa_list;
    return cl_env_copy->values[0];
   }
  }
 }
}
/*	function definition for MAKE-CONSTRUCTOR                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L11make_constructor(cl_object v1name, cl_object v2constructor, cl_object v3type, cl_object v4named, cl_object v5slot_descriptions)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6boa_constructor_p;
   cl_object v7keys;
   cl_object v8constructor_name;
   cl_object v9slot_names;
   cl_object v10assertions;
   v6boa_constructor_p = ecl_make_bool(ECL_CONSP(v2constructor));
   if ((v6boa_constructor_p)!=ECL_NIL) { goto L3; }
   v7keys = ecl_list1(ECL_SYM("&KEY",10));
   goto L2;
L3:;
   v7keys = ECL_NIL;
L2:;
   if (Null(v6boa_constructor_p)) { goto L6; }
   v8constructor_name = ecl_car(v2constructor);
   goto L5;
L6:;
   v8constructor_name = v2constructor;
L5:;
   v9slot_names = ECL_NIL;
   v10assertions = ECL_NIL;
   {
    cl_object v11;
    v11 = v5slot_descriptions;
    goto L14;
L13:;
    {
     cl_object v12slot;
     v12slot = ecl_car(v11);
     if (!(v12slot==ECL_NIL)) { goto L21; }
     T0 = ECL_NIL;
     goto L20;
L21:;
     T1 = ecl_car(v12slot);
     if (!((T1)==(VV[3]))) { goto L23; }
     T1 = ecl_cadr(v12slot);
     T0 = cl_list(2, ECL_SYM("QUOTE",679), T1);
     goto L20;
L23:;
     {
      cl_object v13slot_name;
      cl_object v14slot_type;
      cl_object v15init_form;
      cl_object v16var_name;
      v13slot_name = ecl_car(v12slot);
      v14slot_type = ecl_caddr(v12slot);
      v15init_form = ecl_cadr(v12slot);
      v16var_name = v13slot_name;
      if ((v6boa_constructor_p)!=ECL_NIL) { goto L29; }
      v16var_name = cl_copy_symbol(1, v13slot_name);
      if (Null(v15init_form)) { goto L35; }
      T1 = cl_list(2, v16var_name, v15init_form);
      goto L34;
L35:;
      T1 = v16var_name;
L34:;
      v7keys = CONS(T1,v7keys);
L29:;
      if ((ECL_T)==(v14slot_type)) { goto L37; }
      T1 = cl_list(2, ECL_SYM("QUOTE",679), v14slot_type);
      T2 = cl_list(3, ECL_SYM("TYPEP",875), v16var_name, T1);
      T3 = cl_list(2, ECL_SYM("QUOTE",679), v14slot_type);
      T4 = cl_list(2, ECL_SYM("QUOTE",679), v1name);
      T5 = cl_list(2, ECL_SYM("QUOTE",679), v13slot_name);
      T6 = cl_list(5, VV[0], v16var_name, T3, T4, T5);
      T7 = cl_list(3, ECL_SYM("UNLESS",883), T2, T6);
      v10assertions = CONS(T7,v10assertions);
L37:;
      T0 = v16var_name;
     }
L20:;
     v9slot_names = CONS(T0,v9slot_names);
    }
    v11 = ecl_cdr(v11);
L14:;
    if (Null(v11)) { goto L42; }
    goto L13;
L42:;
    v9slot_names = cl_nreverse(v9slot_names);
    v7keys = cl_nreverse(v7keys);
   }
   if (Null(v6boa_constructor_p)) { goto L47; }
   {
    cl_object v12;
    cl_object v13;
    T0 = ecl_cadr(v2constructor);
    value0 = L10process_boa_lambda_list(v9slot_names, v5slot_descriptions, T0, v10assertions);
    v12 = value0;
    {
     const int v14 = cl_env_copy->nvalues;
     cl_object v15;
     v15 = (v14<=1)? ECL_NIL : cl_env_copy->values[1];
     v13 = v15;
    }
    v7keys = v12;
    v10assertions = v13;
   }
L47:;
   if (!(v3type==ECL_NIL)) { goto L54; }
   T0 = cl_listX(3, ECL_SYM("MAKE-STRUCTURE",1105), VV[4], v9slot_names);
   T1 = ecl_list1(T0);
   T2 = ecl_append(v10assertions,T1);
   value0 = cl_listX(4, ECL_SYM("DEFUN",289), v8constructor_name, v7keys, T2);
   return value0;
L54:;
   if (Null(cl_subtypep(2, v3type, VV[5]))) { goto L56; }
   T0 = CONS(ECL_SYM("VECTOR",898),v9slot_names);
   value0 = cl_list(4, ECL_SYM("DEFUN",289), v8constructor_name, v7keys, T0);
   return value0;
L56:;
   if (Null(cl_subtypep(2, v3type, ECL_SYM("VECTOR",898)))) { goto L58; }
   {
    cl_fixnum v11;
    v11 = ecl_length(v9slot_names);
    T0 = ecl_list1(ecl_make_fixnum(v11));
    T1 = cl_list(2, ECL_SYM("QUOTE",679), T0);
    T2 = ecl_function_dispatch(cl_env_copy,VV[30])(1, v3type) /*  CLOSEST-SEQUENCE-TYPE */;
    T3 = cl_list(2, ECL_SYM("QUOTE",679), T2);
    T4 = CONS(ECL_SYM("LIST",481),v9slot_names);
    T5 = cl_list(6, ECL_SYM("MAKE-ARRAY",522), T1, ECL_SYM("ELEMENT-TYPE",1224), T3, ECL_SYM("INITIAL-CONTENTS",1252), T4);
    value0 = cl_list(4, ECL_SYM("DEFUN",289), v8constructor_name, v7keys, T5);
    return value0;
   }
L58:;
   if (!((v3type)==(ECL_SYM("LIST",481)))) { goto L60; }
   T0 = CONS(ECL_SYM("LIST",481),v9slot_names);
   value0 = cl_list(4, ECL_SYM("DEFUN",289), v8constructor_name, v7keys, T0);
   return value0;
L60:;
   {
    cl_object v12;
    v12 = cl_error(2, _ecl_static_3, v3type);
    if (Null(v12)) { goto L63; }
    value0 = v12;
    cl_env_copy->nvalues = 1;
    return value0;
L63:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for MAKE-PREDICATE                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L16make_predicate(cl_object v1name, cl_object v2type, cl_object v3named, cl_object v4name_offset)
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1name,env0);                /*  NAME            */
  CLV1 = env0 = CONS(v4name_offset,env0);         /*  NAME-OFFSET     */
  if (!(v2type==ECL_NIL)) { goto L1; }
  {cl_object v5;
   v5 = ECL_NIL;
   v5 = ecl_make_cclosure_va((cl_objectfn)LC12__g38,env0,Cblock);
   value0 = v5;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L1:;
  if ((v2type)==(ECL_SYM("VECTOR",898))) { goto L5; }
  if (!(ECL_CONSP(v2type))) { goto L3; }
  T0 = ecl_car(v2type);
  if (!((T0)==(ECL_SYM("VECTOR",898)))) { goto L3; }
  goto L4;
L5:;
L4:;
  if ((v3named)!=ECL_NIL) { goto L8; }
  cl_error(1, _ecl_static_4);
L8:;
  {cl_object v6;
   v6 = ECL_NIL;
   v6 = ecl_make_cclosure_va((cl_objectfn)LC13__g39,env0,Cblock);
   value0 = v6;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L3:;
  if (!((v2type)==(ECL_SYM("LIST",481)))) { goto L10; }
  if ((v3named)!=ECL_NIL) { goto L12; }
  cl_error(1, _ecl_static_4);
L12:;
  if (!(ecl_number_equalp(ECL_CONS_CAR(CLV1),ecl_make_fixnum(0)))) { goto L14; }
  {cl_object v7;
   v7 = ECL_NIL;
   v7 = ecl_make_cclosure_va((cl_objectfn)LC14__g40,env0,Cblock);
   value0 = v7;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L14:;
  {cl_object v8;
   v8 = ECL_NIL;
   v8 = ecl_make_cclosure_va((cl_objectfn)LC15__g41,env0,Cblock);
   value0 = v8;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L10:;
  {
   cl_object v9;
   v9 = cl_error(1, _ecl_static_2);
   if (Null(v9)) { goto L17; }
   value0 = v9;
   cl_env_copy->nvalues = 1;
   return value0;
L17:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	closure G38                                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC12__g38(cl_narg narg, cl_object v1x, ...)
{
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;
 CLV0 = _ecl_cdr(CLV1);                           /*  NAME            */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = si_structure_subtype_p(v1x, ECL_CONS_CAR(CLV0));
  return value0;
 }
 }
}
/*	closure G39                                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC13__g39(cl_narg narg, cl_object v1x, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  NAME-OFFSET     */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  if (!(ECL_VECTORP(v1x))) { goto L2; }
  {
   cl_fixnum v2;
   v2 = ecl_length(v1x);
   if (!(ecl_number_compare(ecl_make_fixnum(v2),ECL_CONS_CAR(CLV1))>0)) { goto L2; }
  }
  T0 = ecl_elt(v1x,ecl_fixnum(ECL_CONS_CAR(CLV1)));
  value0 = ecl_make_bool((T0)==(ECL_CONS_CAR(CLV0)));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
 }
}
/*	closure G40                                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC14__g40(cl_narg narg, cl_object v1x, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;
 CLV0 = _ecl_cdr(CLV1);                           /*  NAME            */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  if (!(ECL_CONSP(v1x))) { goto L2; }
  T0 = ecl_car(v1x);
  value0 = ecl_make_bool((T0)==(ECL_CONS_CAR(CLV0)));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
 }
}
/*	closure G41                                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC15__g41(cl_narg narg, cl_object v1x, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  NAME-OFFSET     */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  {
   cl_fixnum v2i;
   cl_object v3y;
   {
    bool v4;
    v4 = ECL_FIXNUMP(ECL_CONS_CAR(CLV1));
    if (ecl_unlikely(!(v4)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),ECL_CONS_CAR(CLV1));
   }
   v2i = ecl_fixnum(ECL_CONS_CAR(CLV1));
   v3y = v1x;
   goto L6;
L5:;
   if (ECL_CONSP(v3y)) { goto L8; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L8:;
   {
    cl_object v4;
    v4 = ecl_make_integer((v2i)-1);
    {
     bool v5;
     v5 = ECL_FIXNUMP(v4);
     if (ecl_unlikely(!(v5)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v4);
    }
    v2i = ecl_fixnum(v4);
   }
   v3y = ecl_cdr(v3y);
L6:;
   if ((v2i)==(0)) { goto L15; }
   goto L5;
L15:;
   if (!(ECL_CONSP(v3y))) { goto L18; }
   T0 = ecl_car(v3y);
   value0 = ecl_make_bool((T0)==(ECL_CONS_CAR(CLV0)));
   cl_env_copy->nvalues = 1;
   return value0;
L18:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
 }
}
/*	function definition for PARSE-SLOT-DESCRIPTION                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L17parse_slot_description(cl_narg narg, cl_object v1slot_description, cl_object v2offset, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v3read_only;
  va_list args; va_start(args,v2offset);
  {
   int i = 2;
   if (i >= narg) {
    v3read_only = ECL_NIL;
   } else {
    i++;
    v3read_only = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v4slot_type;
   cl_object v5slot_name;
   cl_object v6default_init;
   v4slot_type = ECL_T;
   v5slot_name = ECL_NIL;
   v6default_init = ECL_NIL;
   if (!(ECL_ATOM(v1slot_description))) { goto L6; }
   v5slot_name = v1slot_description;
   goto L5;
L6:;
   T0 = ecl_cdr(v1slot_description);
   if (!(ecl_endp(T0))) { goto L9; }
   v5slot_name = ecl_car(v1slot_description);
   goto L5;
L9:;
   v5slot_name = ecl_car(v1slot_description);
   v6default_init = ecl_cadr(v1slot_description);
   {
    cl_object v7;
    cl_object v8os;
    cl_object v9o;
    cl_object v10v;
    v7 = ecl_cddr(v1slot_description);
    v8os = v7;
    v9o = ECL_NIL;
    v10v = ECL_NIL;
    goto L22;
L21:;
    v9o = ecl_car(v8os);
    T0 = ecl_cdr(v8os);
    if (!(ecl_endp(T0))) { goto L26; }
    cl_error(2, _ecl_static_5, v8os);
L26:;
    v10v = ecl_cadr(v8os);
    if (!(ecl_eql(v9o,ECL_SYM("TYPE",1318)))) { goto L31; }
    v4slot_type = v10v;
    goto L30;
L31:;
    if (!(ecl_eql(v9o,VV[6]))) { goto L34; }
    v3read_only = v10v;
    goto L30;
L34:;
    cl_error(2, _ecl_static_5, v8os);
L30:;
    v8os = ecl_cddr(v8os);
L22:;
    if (ecl_endp(v8os)) { goto L39; }
    goto L21;
L39:;
   }
L5:;
   value0 = cl_list(6, v5slot_name, v6default_init, v4slot_type, v3read_only, v2offset, ECL_NIL);
   return value0;
  }
 }
}
/*	function definition for OVERWRITE-SLOT-DESCRIPTIONS           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L18overwrite_slot_descriptions(cl_object v1new_slots, cl_object v2old_slots)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3output;
   cl_object v4old_slots;
   v3output = ECL_NIL;
   v4old_slots = v2old_slots;
   goto L5;
L4:;
   {
    cl_object v5old_slot;
    cl_object v6slot_name;
    cl_object v7new_slot;
    v5old_slot = ecl_car(v4old_slots);
    v6slot_name = ecl_car(v5old_slot);
    {
     cl_object v8;
     v8 = v1new_slots;
     goto L15;
L14:;
     {
      cl_object v9;
      cl_object v10;
      if (ecl_unlikely(ECL_ATOM(v8))) FEtype_error_cons(v8);
      v9 = v8;
      v10 = ECL_CONS_CAR(v9);
      T1 = ecl_car(v10);
      if (!(ecl_eql(v6slot_name,T1))) { goto L17; }
      T0 = v9;
      goto L11;
     }
L17:;
     v8 = ECL_CONS_CDR(v8);
L15:;
     if (v8==ECL_NIL) { goto L24; }
     goto L14;
L24:;
     T0 = ECL_NIL;
    }
L11:;
    v7new_slot = ecl_car(T0);
    if (!(v7new_slot==ECL_NIL)) { goto L27; }
    v7new_slot = v5old_slot;
    goto L26;
L27:;
    {
     cl_object v8old_read_only;
     cl_object v9new_read_only;
     v8old_read_only = ecl_cadddr(v5old_slot);
     v9new_read_only = ecl_cadddr(v7new_slot);
     if (!(v9new_read_only==ECL_NIL)) { goto L33; }
     if (Null(v8old_read_only)) { goto L33; }
     cl_error(2, _ecl_static_6, v6slot_name);
     goto L32;
L33:;
     if (!((v9new_read_only)==(VV[7]))) { goto L32; }
     v9new_read_only = v8old_read_only;
L32:;
     v7new_slot = cl_copy_list(v7new_slot);
     {
      cl_object v10;
      v10 = ecl_cdddr(v7new_slot);
      if (ecl_unlikely(ECL_ATOM(v10))) FEtype_error_cons(v10);
      T0 = v10;
     }
     (ECL_CONS_CAR(T0)=v9new_read_only,T0);
     {
      cl_object v10;
      T0 = ecl_cddddr(v5old_slot);
      v10 = ecl_car(T0);
      {
       cl_object v11;
       v11 = ecl_cddddr(v7new_slot);
       if (ecl_unlikely(ECL_ATOM(v11))) FEtype_error_cons(v11);
       T0 = v11;
      }
      (ECL_CONS_CAR(T0)=v10,T0);
     }
     {
      cl_object v10;
      T0 = ecl_cddddr(v5old_slot);
      v10 = ecl_cadr(T0);
      {
       cl_object v11;
       T1 = ecl_cddddr(v7new_slot);
       v11 = ecl_cdr(T1);
       if (ecl_unlikely(ECL_ATOM(v11))) FEtype_error_cons(v11);
       T0 = v11;
      }
      (ECL_CONS_CAR(T0)=v10,T0);
     }
    }
L26:;
    v3output = CONS(v7new_slot,v3output);
   }
   v4old_slots = ecl_cdr(v4old_slots);
L5:;
   if (v4old_slots==ECL_NIL) { goto L59; }
   goto L4;
L59:;
   value0 = cl_nreverse(v3output);
   return value0;
  }
 }
}
/*	function definition for DEFINE-STRUCTURE                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_define_structure(cl_narg narg, cl_object v1name, cl_object v2conc_name, cl_object v3type, cl_object v4named, cl_object v5slots, cl_object v6slot_descriptions, cl_object v7copier, cl_object v8include, cl_object v9print_function, cl_object v10print_object, cl_object v11constructors, cl_object v12offset, cl_object v13name_offset, cl_object v14documentation, cl_object v15predicate, ...)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg!=15)) FEwrong_num_arguments_anonym();
 {
TTL:
  ecl_function_dispatch(cl_env_copy,ECL_SYM("CREATE-TYPE-NAME",1585))(1, v1name) /*  CREATE-TYPE-NAME */;
  v6slot_descriptions = cl_copy_tree(v6slot_descriptions);
  if ((v3type)!=ECL_NIL) { goto L4; }
  if (Null(v8include)) { goto L8; }
  T0 = ecl_list1(v8include);
  goto L6;
L8:;
  T0 = ECL_NIL;
  goto L6;
L6:;
  {
   cl_object v16;
   cl_object v17;
   v16 = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v6slot_descriptions))) FEtype_error_list(v6slot_descriptions);
   v17 = v6slot_descriptions;
   {
    cl_object v18;
    cl_object v19;
    v18 = ecl_list1(ECL_NIL);
    v19 = v18;
L16:;
    if (!(ecl_endp(v17))) { goto L18; }
    goto L17;
L18:;
    v16 = _ecl_car(v17);
    {
     cl_object v20;
     v20 = _ecl_cdr(v17);
     if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
     v17 = v20;
    }
    if (ecl_unlikely(ECL_ATOM(v19))) FEtype_error_cons(v19);
    T2 = v19;
    if (Null(v16)) { goto L31; }
    T4 = ecl_car(v16);
    T5 = ecl_cadr(v16);
    T6 = ecl_car(v16);
    T7 = ecl_symbol_name(T6);
    T8 = cl_find_package(ECL_SYM("KEYWORD",449));
    T9 = cl_intern(2, T7, T8);
    if (Null(ecl_caddr(v16))) { goto L34; }
    T11 = ecl_caddr(v16);
    T10 = cl_list(2, ECL_SYM("TYPE",1318), T11);
    goto L33;
L34:;
    T10 = ECL_NIL;
L33:;
    T3 = cl_listX(6, T4, ECL_SYM("INITFORM",996), T5, ECL_SYM("INITARG",994), T9, T10);
    goto L30;
L31:;
    T3 = ECL_NIL;
L30:;
    v19 = ecl_list1(T3);
    (ECL_CONS_CDR(T2)=v19,T2);
    goto L16;
L17:;
    T1 = ecl_cdr(v18);
    goto L10;
   }
  }
L10:;
  T2 = cl_list(5, ECL_SYM("DEFCLASS",937), v1name, T0, T1, VV[8]);
  cl_eval(T2);
L4:;
  if (Null(v9print_function)) { goto L38; }
  T0 = cl_list(2, VV[9], v1name);
  T1 = cl_list(2, T0, ECL_SYM("STREAM",799));
  T2 = CONS(v9print_function,VV[10]);
  T3 = cl_list(5, ECL_SYM("DEFMETHOD",940), ECL_SYM("PRINT-OBJECT",961), T1, T2, VV[9]);
  cl_eval(T3);
L38:;
  if (Null(v10print_object)) { goto L40; }
  T0 = cl_list(2, VV[9], v1name);
  T1 = cl_list(2, T0, ECL_SYM("STREAM",799));
  T2 = CONS(v10print_object,VV[11]);
  T3 = cl_list(5, ECL_SYM("DEFMETHOD",940), ECL_SYM("PRINT-OBJECT",961), T1, T2, VV[9]);
  cl_eval(T3);
L40:;
  if (Null(v15predicate)) { goto L42; }
  T0 = L16make_predicate(v1name, v3type, v4named, v13name_offset);
  si_fset(4, v15predicate, T0, ECL_NIL, ECL_NIL);
L42:;
  T0 = cl_listX(3, ECL_SYM("DEFSTRUCT",287), v1name, v5slots);
  si_put_sysprop(v1name, VV[12], T0);
  si_put_sysprop(v1name, VV[13], ECL_T);
  si_put_sysprop(v1name, ECL_SYM("STRUCTURE-SLOT-DESCRIPTIONS",1155), v6slot_descriptions);
  si_put_sysprop(v1name, VV[14], v8include);
  si_put_sysprop(v1name, ECL_SYM("STRUCTURE-PRINT-FUNCTION",1152), v9print_function);
  si_put_sysprop(v1name, VV[15], v3type);
  si_put_sysprop(v1name, VV[16], v4named);
  si_put_sysprop(v1name, VV[17], v12offset);
  si_put_sysprop(v1name, VV[18], v11constructors);
  if (Null(ecl_symbol_value(VV[19]))) { goto L53; }
  si_set_documentation(3, v1name, ECL_SYM("STRUCTURE",826), v14documentation);
L53:;
  {
   cl_object v16;
   v16 = v6slot_descriptions;
   goto L59;
L58:;
   {
    cl_object v17x;
    v17x = ecl_car(v16);
    if (Null(v17x)) { goto L65; }
    T0 = ecl_car(v17x);
    if ((T0)==(VV[3])) { goto L65; }
    L5make_access_function(v1name, v2conc_name, v3type, v4named, v17x);
    goto L63;
L65:;
    goto L63;
L63:;
   }
   v16 = ecl_cdr(v16);
L59:;
   if (Null(v16)) { goto L70; }
   goto L58;
L70:;
  }
  if (Null(v7copier)) { goto L72; }
  T0 = (ECL_SYM("COPY-STRUCTURE",261)->symbol.gfdef);
  si_fset(4, v7copier, T0, ECL_NIL, ECL_NIL);
L72:;
  if ((v3type)!=ECL_NIL) { goto L75; }
  value0 = cl_find_class(1, v1name);
  return value0;
L75:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function DEFSTRUCT                                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC19defstruct(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4name_opts;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4name_opts = v5;
   }
   {
    cl_object v5slot_descriptions;
    cl_object v6name;
    cl_object v7options;
    cl_object v8conc_name;
    cl_object v9default_constructor;
    cl_object v10copier;
    cl_object v11predicate;
    cl_object v12constructors;
    cl_object v13no_constructor;
    cl_object v14predicate_specified;
    cl_object v15include;
    cl_object v16print_function;
    cl_object v17print_object;
    cl_object v18type;
    cl_object v19named;
    cl_object v20initial_offset;
    cl_object v21offset;
    cl_object v22name_offset;
    cl_object v23documentation;
    v5slot_descriptions = v3;
    if (!(ECL_CONSP(v4name_opts))) { goto L10; }
    v6name = ecl_car(v4name_opts);
    goto L9;
L10:;
    v6name = v4name_opts;
L9:;
    if (!(ECL_CONSP(v4name_opts))) { goto L13; }
    v7options = ecl_cdr(v4name_opts);
    goto L12;
L13:;
    v7options = ECL_NIL;
L12:;
    v8conc_name = si_base_string_concatenate(2, v6name, _ecl_static_7);
    T0 = si_base_string_concatenate(2, _ecl_static_8, v6name);
    v9default_constructor = cl_intern(1, T0);
    T0 = si_base_string_concatenate(2, _ecl_static_9, v6name);
    v10copier = cl_intern(1, T0);
    T0 = si_base_string_concatenate(2, v6name, _ecl_static_10);
    v11predicate = cl_intern(1, T0);
    v12constructors = ECL_NIL;
    v13no_constructor = ECL_NIL;
    v14predicate_specified = ECL_NIL;
    v15include = ECL_NIL;
    v16print_function = ECL_NIL;
    v17print_object = ECL_NIL;
    v18type = ECL_NIL;
    v19named = ECL_NIL;
    v20initial_offset = ECL_NIL;
    v21offset = ECL_NIL;
    v22name_offset = ECL_NIL;
    v23documentation = ECL_NIL;
    {
     cl_object v24os;
     cl_object v25o;
     cl_object v26v;
     v24os = v7options;
     v25o = ECL_NIL;
     v26v = ECL_NIL;
     goto L37;
L36:;
     T0 = ecl_car(v24os);
     if (!(ECL_CONSP(T0))) { goto L40; }
     T0 = ecl_cdar(v24os);
     if (ecl_endp(T0)) { goto L40; }
     v25o = ecl_caar(v24os);
     v26v = ecl_cadar(v24os);
     if (!(ecl_eql(v25o,ECL_SYM("CONC-NAME",1209)))) { goto L47; }
     if (!(v26v==ECL_NIL)) { goto L49; }
     v8conc_name = ECL_NIL;
     goto L39;
L49:;
     v8conc_name = v26v;
     goto L39;
L47:;
     if (!(ecl_eql(v25o,ECL_SYM("CONSTRUCTOR",1210)))) { goto L53; }
     if (!(v26v==ECL_NIL)) { goto L55; }
     v13no_constructor = ECL_T;
     goto L39;
L55:;
     T0 = ecl_cddar(v24os);
     if (!(ecl_endp(T0))) { goto L58; }
     v12constructors = CONS(v26v,v12constructors);
     goto L39;
L58:;
     T0 = ecl_cdar(v24os);
     v12constructors = CONS(T0,v12constructors);
     goto L39;
L53:;
     if (!(ecl_eql(v25o,ECL_SYM("COPIER",1212)))) { goto L62; }
     v10copier = v26v;
     goto L39;
L62:;
     if (!(ecl_eql(v25o,ECL_SYM("PREDICATE",1287)))) { goto L65; }
     v11predicate = v26v;
     v14predicate_specified = ECL_T;
     goto L39;
L65:;
     if (!(ecl_eql(v25o,ECL_SYM("INCLUDE",1249)))) { goto L70; }
     v15include = ecl_cdar(v24os);
     if ((si_get_sysprop(v26v, VV[13]))!=ECL_NIL) { goto L39; }
     cl_error(2, _ecl_static_11, v26v);
     goto L39;
L70:;
     if (!(ecl_eql(v25o,ECL_SYM("PRINT-FUNCTION",1291)))) { goto L75; }
     v16print_function = v26v;
     goto L39;
L75:;
     if (!(ecl_eql(v25o,ECL_SYM("PRINT-OBJECT",1292)))) { goto L78; }
     v17print_object = v26v;
     goto L39;
L78:;
     if (!(ecl_eql(v25o,ECL_SYM("TYPE",1318)))) { goto L81; }
     v18type = v26v;
     goto L39;
L81:;
     if (!(ecl_eql(v25o,ECL_SYM("INITIAL-OFFSET",1253)))) { goto L84; }
     v20initial_offset = v26v;
     goto L39;
L84:;
     cl_error(2, _ecl_static_12, v25o);
     goto L39;
L40:;
     T0 = ecl_car(v24os);
     if (!(ECL_CONSP(T0))) { goto L88; }
     v25o = ecl_caar(v24os);
     goto L87;
L88:;
     v25o = ecl_car(v24os);
L87:;
     if (!(ecl_eql(v25o,ECL_SYM("CONSTRUCTOR",1210)))) { goto L92; }
     v12constructors = CONS(v9default_constructor,v12constructors);
     goto L39;
L92:;
     if (!(ecl_eql(v25o,ECL_SYM("CONC-NAME",1209)))) { goto L95; }
     v8conc_name = ECL_NIL;
     goto L39;
L95:;
     if (!(ecl_eql(v25o,ECL_SYM("COPIER",1212)))) { goto L101; }
     goto L39;
     goto L99;
L101:;
     goto L99;
L99:;
     if (!(ecl_eql(v25o,ECL_SYM("PREDICATE",1287)))) { goto L105; }
     goto L39;
     goto L103;
L105:;
     goto L103;
L103:;
     if (!(ecl_eql(v25o,ECL_SYM("PRINT-FUNCTION",1291)))) { goto L109; }
     goto L39;
     goto L107;
L109:;
     goto L107;
L107:;
     if (!(ecl_eql(v25o,ECL_SYM("PRINT-OBJECT",1292)))) { goto L112; }
     goto L39;
     goto L98;
L112:;
     goto L98;
L98:;
     if (!(ecl_eql(v25o,ECL_SYM("NAMED",1274)))) { goto L114; }
     v19named = ECL_T;
     goto L39;
L114:;
     cl_error(2, _ecl_static_12, v25o);
L39:;
     v24os = ecl_cdr(v24os);
L37:;
     if (ecl_endp(v24os)) { goto L119; }
     goto L36;
L119:;
    }
    if (ecl_endp(v5slot_descriptions)) { goto L121; }
    T0 = ecl_car(v5slot_descriptions);
    if (!(ECL_STRINGP(T0))) { goto L121; }
    v23documentation = ecl_car(v5slot_descriptions);
    v5slot_descriptions = ecl_cdr(v5slot_descriptions);
L121:;
    if (Null(v15include)) { goto L127; }
    T0 = ecl_car(v15include);
    T1 = si_get_sysprop(T0, VV[15]);
    if (ecl_equal(v18type,T1)) { goto L127; }
    T0 = ecl_car(v15include);
    cl_error(2, _ecl_static_13, T0);
L127:;
    if (Null(v15include)) { goto L132; }
    T0 = ecl_car(v15include);
    v21offset = si_get_sysprop(T0, VV[17]);
    goto L131;
L132:;
    v21offset = ecl_make_fixnum(0);
L131:;
    if (Null(v18type)) { goto L134; }
    if (Null(v20initial_offset)) { goto L134; }
    v21offset = ecl_plus(v21offset,v20initial_offset);
L134:;
    if (Null(v18type)) { goto L138; }
    if (Null(v19named)) { goto L138; }
    if ((cl_subtypep(2, VV[25], v18type))!=ECL_NIL) { goto L141; }
    if ((cl_subtypep(2, v18type, ECL_SYM("LIST",481)))!=ECL_NIL) { goto L141; }
    cl_error(2, _ecl_static_14, v18type);
L141:;
    v22name_offset = v21offset;
    v21offset = ecl_one_plus(v21offset);
L138:;
    {
     cl_object v24;
     cl_object v25ds;
     cl_object v26sds;
     v24 = v5slot_descriptions;
     v25ds = v24;
     v26sds = ECL_NIL;
     goto L153;
L152:;
     T0 = ecl_car(v25ds);
     T1 = L17parse_slot_description(2, T0, v21offset);
     v26sds = CONS(T1,v26sds);
     v21offset = ecl_one_plus(v21offset);
     v25ds = ecl_cdr(v25ds);
L153:;
     if (ecl_endp(v25ds)) { goto L161; }
     goto L152;
L161:;
     v5slot_descriptions = cl_nreverse(v26sds);
    }
    if (Null(v18type)) { goto L164; }
    if (Null(v19named)) { goto L164; }
    T0 = cl_list(2, VV[3], v6name);
    v5slot_descriptions = CONS(T0,v5slot_descriptions);
L164:;
    if (Null(v18type)) { goto L168; }
    if (Null(v20initial_offset)) { goto L168; }
    T0 = cl_make_list(1, v20initial_offset);
    v5slot_descriptions = ecl_append(T0,v5slot_descriptions);
L168:;
    {
     cl_object v24;
     v24 = ecl_make_bool(v15include==ECL_NIL);
     if (Null(v24)) { goto L174; }
     goto L172;
L174:;
     T0 = ecl_cdr(v15include);
     if (!(ecl_endp(T0))) { goto L176; }
     T0 = ecl_car(v15include);
     T1 = si_get_sysprop(T0, ECL_SYM("STRUCTURE-SLOT-DESCRIPTIONS",1155));
     v5slot_descriptions = ecl_append(T1,v5slot_descriptions);
     goto L172;
L176:;
     {
      cl_object v25;
      cl_object v26;
      cl_object v27;
      v25 = ecl_cdr(v15include);
      v26 = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v25))) FEtype_error_list(v25);
      v27 = v25;
      {
       cl_object v28;
       cl_object v29;
       v28 = ecl_list1(ECL_NIL);
       v29 = v28;
L187:;
       if (!(ecl_endp(v27))) { goto L189; }
       goto L188;
L189:;
       v26 = _ecl_car(v27);
       {
        cl_object v30;
        v30 = _ecl_cdr(v27);
        if (ecl_unlikely(!ECL_LISTP(v30))) FEtype_error_list(v30);
        v27 = v30;
       }
       if (ecl_unlikely(ECL_ATOM(v29))) FEtype_error_cons(v29);
       T1 = v29;
       T2 = L17parse_slot_description(3, v26, ecl_make_fixnum(0), VV[7]);
       v29 = ecl_list1(T2);
       (ECL_CONS_CDR(T1)=v29,T1);
       goto L187;
L188:;
       T0 = ecl_cdr(v28);
       goto L180;
      }
     }
L180:;
     T1 = ecl_car(v15include);
     T2 = si_get_sysprop(T1, ECL_SYM("STRUCTURE-SLOT-DESCRIPTIONS",1155));
     T3 = L18overwrite_slot_descriptions(T0, T2);
     v5slot_descriptions = ecl_append(T3,v5slot_descriptions);
    }
L172:;
    if (Null(v13no_constructor)) { goto L205; }
    if (Null(v12constructors)) { goto L204; }
    cl_error(1, _ecl_static_15);
    goto L204;
L205:;
    if (!(v12constructors==ECL_NIL)) { goto L204; }
    v12constructors = ecl_list1(v9default_constructor);
L204:;
    if (Null(v18type)) { goto L210; }
    if ((v19named)!=ECL_NIL) { goto L210; }
    if (Null(v14predicate_specified)) { goto L213; }
    cl_error(2, _ecl_static_16, v11predicate);
L213:;
    v11predicate = ECL_NIL;
L210:;
    if (Null(v15include)) { goto L216; }
    v15include = ecl_car(v15include);
L216:;
    if (Null(v16print_function)) { goto L219; }
    if (Null(v18type)) { goto L219; }
    cl_error(1, _ecl_static_17);
L219:;
    {
     cl_object v24;
     cl_object v25;
     T0 = cl_list(2, ECL_SYM("QUOTE",679), v6name);
     T1 = cl_list(2, ECL_SYM("QUOTE",679), v8conc_name);
     T2 = cl_list(2, ECL_SYM("QUOTE",679), v18type);
     T3 = cl_list(2, ECL_SYM("QUOTE",679), v19named);
     T4 = cl_list(2, ECL_SYM("QUOTE",679), v3);
     T5 = cl_list(2, ECL_SYM("QUOTE",679), v5slot_descriptions);
     T6 = cl_list(2, ECL_SYM("QUOTE",679), v10copier);
     T7 = cl_list(2, ECL_SYM("QUOTE",679), v15include);
     T8 = cl_list(2, ECL_SYM("QUOTE",679), v16print_function);
     T9 = cl_list(2, ECL_SYM("QUOTE",679), v17print_object);
     T10 = cl_list(2, ECL_SYM("QUOTE",679), v12constructors);
     T11 = cl_list(2, ECL_SYM("QUOTE",679), v21offset);
     T12 = cl_list(2, ECL_SYM("QUOTE",679), v22name_offset);
     T13 = cl_list(2, ECL_SYM("QUOTE",679), v23documentation);
     T14 = cl_list(2, ECL_SYM("QUOTE",679), v11predicate);
     v24 = cl_list(16, VV[20], T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14);
     {
      cl_object v26;
      cl_object v27;
      v26 = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v12constructors))) FEtype_error_list(v12constructors);
      v27 = v12constructors;
      {
       cl_object v28;
       cl_object v29;
       v28 = ecl_list1(ECL_NIL);
       v29 = v28;
L229:;
       if (!(ecl_endp(v27))) { goto L231; }
       goto L230;
L231:;
       v26 = _ecl_car(v27);
       {
        cl_object v30;
        v30 = _ecl_cdr(v27);
        if (ecl_unlikely(!ECL_LISTP(v30))) FEtype_error_list(v30);
        v27 = v30;
       }
       if (ecl_unlikely(ECL_ATOM(v29))) FEtype_error_cons(v29);
       T0 = v29;
       T1 = L11make_constructor(v6name, v26, v18type, v19named, v5slot_descriptions);
       v29 = ecl_list1(T1);
       (ECL_CONS_CDR(T0)=v29,T0);
       goto L229;
L230:;
       v25 = ecl_cdr(v28);
       goto L223;
      }
     }
L223:;
     if (Null(ecl_symbol_value(ECL_SYM("*REGISTER-WITH-PDE-HOOK*",1181)))) { goto L247; }
     T1 = cl_copy_tree(ecl_symbol_value(ECL_SYM("*SOURCE-LOCATION*",1180)));
     T0 = ecl_function_dispatch(cl_env_copy,ecl_symbol_value(ECL_SYM("*REGISTER-WITH-PDE-HOOK*",1181)))(3, T1, v1, ECL_NIL);
     goto L246;
L247:;
     T0 = ECL_NIL;
L246:;
     T1 = cl_list(2, ECL_SYM("QUOTE",679), v6name);
     T2 = cl_list(2, ECL_SYM("FIND-CLASS",943), T1);
     T3 = cl_list(2, ECL_SYM("LOAD-TIME-VALUE",489), T2);
     T4 = cl_subst(3, T3, VV[4], v25);
     T5 = cl_listX(5, ECL_SYM("EVAL-WHEN",340), VV[26], v24, T0, T4);
     T6 = cl_list(2, VV[4], v24);
     T7 = ecl_list1(T6);
     T8 = cl_listX(3, ECL_SYM("LET",477), T7, v25);
     T9 = cl_list(3, ECL_SYM("EVAL-WHEN",340), VV[27], T8);
     T10 = cl_list(2, ECL_SYM("QUOTE",679), v6name);
     value0 = cl_list(4, ECL_SYM("PROGN",671), T5, T9, T10);
     return value0;
    }
   }
  }
 }
}

#include "lsp/defstruct.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclYQHp5HAKwmnr9_3yv9ZE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:LSP;DEFSTRUCT.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclYQHp5HAKwmnr9_3yv9ZE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[29]);                           /*  STRUCTURE-TYPE-ERROR */
 (void)0; /* No entry created for MAKE-ACCESS-FUNCTION */
 (void)0; /* No entry created for DO-SETF-STRUCTURE-METHOD */
 (void)0; /* No entry created for PROCESS-BOA-LAMBDA-LIST */
 (void)0; /* No entry created for MAKE-CONSTRUCTOR */
 (void)0; /* No entry created for MAKE-PREDICATE */
 (void)0; /* No entry created for PARSE-SLOT-DESCRIPTION */
 (void)0; /* No entry created for OVERWRITE-SLOT-DESCRIPTIONS */
 ecl_cmp_defun(VV[31]);                           /*  DEFINE-STRUCTURE */
 ecl_cmp_defmacro(VV[32]);                        /*  DEFSTRUCT       */
}
