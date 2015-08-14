/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CLOS;PRINT.LSP                                    */
#include <ecl/ecl-cmp.h>
#include "clos/print.eclh"
/*	function definition for MAKE-LOAD-FORM-SAVING-SLOTS           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1make_load_form_saving_slots(cl_narg narg, cl_object v1object, ...)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2slot_names;
  cl_object v3environment;
  ecl_va_list args; ecl_va_start(args,v1object,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L1make_load_form_saving_slotskeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v2slot_names = keyvars[0];
   v3environment = keyvars[1];
  }
  {
   cl_object v4class;
   cl_object v5initialization;
   cl_object v6slots;
   v4class = cl_class_of(v1object);
   v5initialization = ecl_list1(ECL_SYM("PROGN",671));
   v6slots = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-SLOTS",1494))(1, v4class) /*  CLASS-SLOTS */;
   goto L6;
L5:;
   {
    cl_object v7slot;
    cl_object v8slot_name;
    v7slot = ecl_car(v6slots);
    v8slot_name = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v7slot) /*  SLOT-DEFINITION-NAME */;
    if (!(v2slot_names==ECL_NIL)) { goto L15; }
    T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-ALLOCATION",1543))(1, v7slot) /*  SLOT-DEFINITION-ALLOCATION */;
    if ((T0)==(ECL_SYM("INSTANCE",1256))) { goto L12; }
    goto L13;
L15:;
    goto L13;
L13:;
    if (Null(ecl_memql(v8slot_name,v2slot_names))) { goto L8; }
    goto L11;
L12:;
L11:;
    if (Null(cl_slot_boundp(v1object, v8slot_name))) { goto L19; }
    T1 = cl_list(2, ECL_SYM("QUOTE",679), v8slot_name);
    T2 = cl_list(3, ECL_SYM("SLOT-VALUE",971), v1object, T1);
    T3 = cl_slot_value(v1object, v8slot_name);
    T4 = cl_list(2, ECL_SYM("QUOTE",679), T3);
    T0 = cl_list(3, ECL_SYM("SETF",750), T2, T4);
    goto L18;
L19:;
    T1 = cl_list(2, ECL_SYM("QUOTE",679), v8slot_name);
    T0 = cl_list(3, ECL_SYM("SLOT-MAKUNBOUND",968), v1object, T1);
L18:;
    v5initialization = CONS(T0,v5initialization);
   }
L8:;
   v6slots = ecl_cdr(v6slots);
L6:;
   if (ecl_endp(v6slots)) { goto L23; }
   goto L5;
L23:;
   T0 = cl_list(2, ECL_SYM("ALLOCATE-INSTANCE",927), v4class);
   T1 = cl_nreverse(v5initialization);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = T1;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for NEED-TO-MAKE-LOAD-FORM-P              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object clos_need_to_make_load_form_p(cl_object volatile v1object, cl_object volatile v2env)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_bds_bind(cl_env_copy,VV[1],ECL_NIL);        /*  *LOAD-FORM-CACHE* */
  value0 = VV[3];
  if (ecl_frs_push(cl_env_copy,value0)) {         /*  BEGIN CATCH 1   */
   value0 = cl_env_copy->values[0];
  } else {
   LC2recursive_test(v1object);
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
  }
  ecl_frs_pop(cl_env_copy);                       /*  END CATCH 1     */
  ecl_bds_unwind1(cl_env_copy);
  return value0;
 }
}
/*	local function RECURSIVE-TEST                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC2recursive_test(cl_object v1object)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
L1:;
  if (ECL_CHARACTERP(v1object)) { goto L5; }
  if (ecl_numberp(v1object)) { goto L5; }
  if (ECL_SYMBOLP(v1object)) { goto L5; }
  if ((cl_pathnamep(v1object))!=ECL_NIL) { goto L5; }
  if (ECL_STRINGP(v1object)) { goto L5; }
  if (!(ECL_BIT_VECTOR_P(v1object))) { goto L3; }
  goto L4;
L5:;
L4:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L3:;
  if ((ecl_symbol_value(VV[1]))!=ECL_NIL) { goto L11; }
  T0 = (ECL_SYM("EQ",333)->symbol.gfdef);
  cl_set(VV[1],cl_make_hash_table(4, ECL_SYM("SIZE",1308), ecl_make_fixnum(128), ECL_SYM("TEST",1316), T0));
L11:;
  if (Null(ecl_gethash_safe(v1object,ecl_symbol_value(VV[1]),ECL_NIL))) { goto L15; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L15:;
  si_hash_set(v1object, ecl_symbol_value(VV[1]), ECL_T);
  if (!(ECL_ARRAYP(v1object))) { goto L18; }
  T0 = cl_array_element_type(v1object);
  if ((cl_subtypep(2, T0, VV[2]))!=ECL_NIL) { goto L20; }
  {
   cl_fixnum v2;
   v2 = ecl_fixnum(cl_array_total_size(v1object));
   {
    cl_fixnum v3i;
    v3i = 0;
    goto L25;
L24:;
    T0 = ecl_aref(v1object,v3i);
    LC2recursive_test(T0);
    v3i = (v3i)+1;
L25:;
    if (!((v3i)<(v2))) { goto L30; }
    goto L24;
L30:;
   }
  }
L20:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L18:;
  if (!(ECL_CONSP(v1object))) { goto L32; }
  T0 = ecl_car(v1object);
  LC2recursive_test(T0);
  v1object = ecl_cdr(v1object);
  goto L2;
L32:;
  if (Null(cl_compiled_function_p(v1object))) { goto L36; }
  {
   cl_object v3;                                  /*  LEX             */
   cl_object v4;                                  /*  CODE            */
   cl_object v5;                                  /*  DATA            */
   cl_object v6;                                  /*  NAME            */
   value0 = si_bc_split(v1object);
   v3 = value0;
   {
    const int v7 = cl_env_copy->nvalues;
    cl_object v8;
    v8 = (v7<=1)? ECL_NIL : cl_env_copy->values[1];
    v4 = v8;
    v8 = (v7<=2)? ECL_NIL : cl_env_copy->values[2];
    v5 = v8;
    v8 = (v7<=3)? ECL_NIL : cl_env_copy->values[3];
    v6 = v8;
   }
   if (v5==ECL_NIL) { goto L41; }
   if (v4==ECL_NIL) { goto L41; }
   if ((LC2recursive_test(v3))!=ECL_NIL) { goto L41; }
   if ((LC2recursive_test(v4))!=ECL_NIL) { goto L41; }
   if (Null(LC2recursive_test(v6))) { goto L39; }
   goto L40;
L41:;
L40:;
   cl_env_copy->values[0] = ECL_T;
   cl_env_copy->nvalues = 1;
   cl_throw(VV[3]);
L39:;
   v1object = v5;
   goto L2;
  }
L36:;
  cl_env_copy->values[0] = ECL_T;
  cl_env_copy->nvalues = 1;
  cl_throw(VV[3]);
L2:;
  goto L1;
 }
}
/*	local function G30                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC4__g30(cl_narg narg, cl_object v1object, ...)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2env;
  va_list args; va_start(args,v1object);
  {
   int i = 1;
   if (i >= narg) {
    v2env = ECL_NIL;
   } else {
    i++;
    v2env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if ((clos_need_to_make_load_form_p(v1object, v2env))!=ECL_NIL) { goto L2; }
  value0 = LC3maybe_quote(v1object);
  return value0;
L2:;
  if (Null(cl_compiled_function_p(v1object))) { goto L4; }
  {
   cl_object v4;                                  /*  LEX             */
   cl_object v5;                                  /*  CODE            */
   cl_object v6;                                  /*  DATA            */
   cl_object v7;                                  /*  NAME            */
   value0 = si_bc_split(v1object);
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
   if ((v5)!=ECL_NIL) { goto L7; }
   cl_error(2, _ecl_static_1, v1object);
L7:;
   T0 = (cl_env_copy->function=(ECL_SYM("MAKE-LOAD-FORM",951)->symbol.gfdef))->cfun.entry(2, v4, v2env) /*  MAKE-LOAD-FORM */;
   T1 = cl_list(2, ECL_SYM("QUOTE",679), v5);
   T2 = (cl_env_copy->function=(ECL_SYM("MAKE-LOAD-FORM",951)->symbol.gfdef))->cfun.entry(2, v6, v2env) /*  MAKE-LOAD-FORM */;
   T3 = (cl_env_copy->function=(ECL_SYM("MAKE-LOAD-FORM",951)->symbol.gfdef))->cfun.entry(2, v7, v2env) /*  MAKE-LOAD-FORM */;
   value0 = cl_list(5, ECL_SYM("BC-JOIN",1046), T0, T1, T2, T3);
   return value0;
  }
L4:;
  if (!(ECL_ARRAYP(v1object))) { goto L9; }
  {
   cl_object v3init_forms;
   v3init_forms = ECL_NIL;
   T0 = cl_array_dimensions(v1object);
   T1 = cl_list(2, ECL_SYM("QUOTE",679), T0);
   T2 = cl_array_element_type(v1object);
   T3 = cl_list(2, ECL_SYM("QUOTE",679), T2);
   {
    bool v4;
    v4 = (ECL_ARRAYP(v1object)? (void)0: FEtype_error_array(v1object),ECL_ADJUSTABLE_ARRAY_P(v1object));
    T4 = cl_list(2, ECL_SYM("QUOTE",679), ecl_make_bool(v4));
    {
     cl_fixnum v5;
     cl_object v6i;
     v5 = ecl_fixnum(cl_array_total_size(v1object));
     v6i = ecl_make_fixnum(0);
     {
      cl_object v7;
      cl_object v8;
      v7 = ecl_list1(ECL_NIL);
      v8 = v7;
L17:;
      if (!(ecl_number_compare(v6i,ecl_make_fixnum(v5))>=0)) { goto L19; }
      goto L18;
L19:;
      if (ecl_unlikely(ECL_ATOM(v8))) FEtype_error_cons(v8);
      T6 = v8;
      {
       cl_object v9x;
       v9x = ecl_aref(v1object,ecl_to_size(v6i));
       if (Null(clos_need_to_make_load_form_p(v9x, v2env))) { goto L27; }
       T8 = cl_list(3, ECL_SYM("ROW-MAJOR-AREF",731), v1object, v6i);
       T9 = cl_list(2, ECL_SYM("QUOTE",679), v9x);
       T10 = cl_list(3, ECL_SYM("SETF",750), T8, T9);
       v3init_forms = CONS(T10,v3init_forms);
       T7 = ecl_make_fixnum(0);
       goto L25;
L27:;
       T7 = v9x;
      }
L25:;
      v8 = ecl_list1(T7);
      (ECL_CONS_CDR(T6)=v8,T6);
      v6i = ecl_one_plus(v6i);
      goto L17;
L18:;
      T5 = ecl_cdr(v7);
      goto L12;
     }
    }
L12:;
    T6 = cl_list(2, ECL_SYM("QUOTE",679), T5);
    T7 = cl_list(8, ECL_SYM("MAKE-ARRAY",522), T1, ECL_SYM("ELEMENT-TYPE",1224), T3, ECL_SYM("ADJUSTABLE",1194), T4, ECL_SYM("INITIAL-CONTENTS",1252), T6);
    if (Null(v3init_forms)) { goto L37; }
    T8 = CONS(ECL_SYM("PROGN",671),v3init_forms);
    goto L35;
L37:;
    T8 = ECL_NIL;
    goto L35;
L35:;
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = T8;
    cl_env_copy->values[0] = T7;
    return cl_env_copy->values[0];
   }
  }
L9:;
  if (!(ECL_CONSP(v1object))) { goto L39; }
  T1 = ecl_car(v1object);
  T0 = LC3maybe_quote(T1);
  T1 = cl_list(3, ECL_SYM("CONS",251), T0, ECL_NIL);
  if (Null(ecl_cdr(v1object))) { goto L44; }
  T3 = LC3maybe_quote(v1object);
  T5 = ecl_cdr(v1object);
  T4 = LC3maybe_quote(T5);
  T2 = cl_list(3, ECL_SYM("RPLACD",733), T3, T4);
  goto L42;
L44:;
  T2 = ECL_NIL;
  goto L42;
L42:;
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = T2;
  cl_env_copy->values[0] = T1;
  return cl_env_copy->values[0];
L39:;
  if (Null(cl_hash_table_p(v1object))) { goto L48; }
  {
   cl_object v5content;
   cl_object v6make_form;
   v5content = si_hash_table_content(v1object);
   T0 = cl_hash_table_size(v1object);
   T1 = cl_hash_table_rehash_size(v1object);
   T2 = cl_hash_table_rehash_threshold(v1object);
   T3 = cl_hash_table_test(v1object);
   T4 = cl_list(2, ECL_SYM("QUOTE",679), T3);
   v6make_form = cl_list(9, ECL_SYM("MAKE-HASH-TABLE",528), ECL_SYM("SIZE",1308), T0, ECL_SYM("REHASH-SIZE",1297), T1, ECL_SYM("REHASH-THRESHOLD",1298), T2, ECL_SYM("TEST",1316), T4);
   if (Null(clos_need_to_make_load_form_p(v5content, v2env))) { goto L52; }
   {
    cl_object v7;
    cl_object v8key;
    cl_object v9obj;
    v7 = ECL_NIL;
    v8key = ECL_NIL;
    v9obj = ECL_NIL;
    {
     cl_object v10;
     v10 = si_hash_table_iterator(v1object);
     {
      cl_object v11;
      cl_object v12;
      v11 = ecl_list1(ECL_NIL);
      v12 = v11;
L61:;
      {
       cl_object v14;
       cl_object v15;
       cl_object v16;
       value0 = ecl_function_dispatch(cl_env_copy,v10)(0);
       v14 = value0;
       {
        const int v17 = cl_env_copy->nvalues;
        cl_object v18;
        v18 = (v17<=1)? ECL_NIL : cl_env_copy->values[1];
        v15 = v18;
        v18 = (v17<=2)? ECL_NIL : cl_env_copy->values[2];
        v16 = v18;
       }
       if (Null(v14)) { goto L66; }
       v9obj = v16;
       v8key = v15;
L66:;
       v7 = v14;
       if ((v7)!=ECL_NIL) { goto L63; }
      }
      goto L62;
L63:;
      if (ecl_unlikely(ECL_ATOM(v12))) FEtype_error_cons(v12);
      T1 = v12;
      T2 = CONS(v8key,v9obj);
      v12 = ecl_list1(T2);
      (ECL_CONS_CDR(T1)=v12,T1);
      goto L61;
L62:;
      T0 = ecl_cdr(v11);
      goto L54;
     }
    }
   }
L54:;
   T1 = cl_list(2, ECL_SYM("QUOTE",679), T0);
   T2 = cl_list(2, VV[4], T1);
   T3 = cl_list(3, ECL_SYM("GETHASH",413), VV[5], v1object);
   T4 = cl_list(3, ECL_SYM("SETF",750), T3, VV[6]);
   T5 = cl_list(3, ECL_SYM("DOLIST",313), T2, T4);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = T5;
   cl_env_copy->values[0] = v6make_form;
   return cl_env_copy->values[0];
L52:;
   T0 = cl_list(2, ECL_SYM("QUOTE",679), v5content);
   T1 = cl_list(3, ECL_SYM("HASH-TABLE-FILL",1931), v6make_form, T0);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = ECL_NIL;
   cl_env_copy->values[0] = T1;
   return cl_env_copy->values[0];
  }
L48:;
  value0 = L8no_make_load_form(v1object);
  return value0;
 }
}
/*	local function MAYBE-QUOTE                                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC3maybe_quote(cl_object v1object)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (ECL_CONSP(v1object)) { goto L3; }
  if (!(ECL_SYMBOLP(v1object))) { goto L1; }
  goto L2;
L3:;
L2:;
  value0 = cl_list(2, ECL_SYM("QUOTE",679), v1object);
  return value0;
L1:;
  value0 = v1object;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G53                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC5__g53(cl_narg narg, cl_object v1object, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2environment;
  va_list args; va_start(args,v1object);
  {
   int i = 1;
   if (i >= narg) {
    v2environment = ECL_NIL;
   } else {
    i++;
    v2environment = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = L8no_make_load_form(v1object);
  return value0;
 }
}
/*	local function G54                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC6__g54(cl_narg narg, cl_object v1object, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2environment;
  va_list args; va_start(args,v1object);
  {
   int i = 1;
   if (i >= narg) {
    v2environment = ECL_NIL;
   } else {
    i++;
    v2environment = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = L8no_make_load_form(v1object);
  return value0;
 }
}
/*	local function G55                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC7__g55(cl_narg narg, cl_object v1object, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2environment;
  va_list args; va_start(args,v1object);
  {
   int i = 1;
   if (i >= narg) {
    v2environment = ECL_NIL;
   } else {
    i++;
    v2environment = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = L8no_make_load_form(v1object);
  return value0;
 }
}
/*	function definition for NO-MAKE-LOAD-FORM                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8no_make_load_form(cl_object v1object)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_type_of(v1object);
  value0 = cl_error(2, _ecl_static_2, T0);
  return value0;
 }
}
/*	local function G56                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC9__g56(cl_narg narg, cl_object v1class, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2environment;
  va_list args; va_start(args,v1class);
  {
   int i = 1;
   if (i >= narg) {
    v2environment = ECL_NIL;
   } else {
    i++;
    v2environment = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v3name;
   v3name = (cl_env_copy->function=(ECL_SYM("CLASS-NAME",934)->symbol.gfdef))->cfun.entry(1, v1class) /*  CLASS-NAME */;
   if (Null(v3name)) { goto L3; }
   T0 = cl_find_class(1, v3name);
   if (!((T0)==(v1class))) { goto L3; }
   T0 = cl_list(2, ECL_SYM("QUOTE",679), v3name);
   value0 = cl_list(2, ECL_SYM("FIND-CLASS",943), T0);
   return value0;
L3:;
   value0 = cl_error(2, _ecl_static_3, v1class);
   return value0;
  }
 }
}
/*	local function G57                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC10__g57(cl_narg narg, cl_object v1package, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2environment;
  va_list args; va_start(args,v1package);
  {
   int i = 1;
   if (i >= narg) {
    v2environment = ECL_NIL;
   } else {
    i++;
    v2environment = va_arg(args,cl_object);
   }
  }
  va_end(args);
  T0 = cl_package_name(v1package);
  value0 = cl_list(2, ECL_SYM("FIND-PACKAGE",367), T0);
  return value0;
 }
}
/*	local function G58                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC12__g58(cl_object v1instance, cl_object v2stream)
{
 cl_object env0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1instance,env0);            /*  INSTANCE        */
  CLV1 = env0 = CONS(v2stream,env0);              /*  STREAM          */
  {cl_object v3;
   v3 = ECL_NIL;
   v3 = ecl_make_cclosure_va((cl_objectfn)LC11si___print_unreadable_object_body_,env0,Cblock);
   si_print_unreadable_object_function(ECL_CONS_CAR(CLV0), ECL_CONS_CAR(CLV1), ECL_NIL, ECL_NIL, v3);
  }
  value0 = ECL_CONS_CAR(CLV0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	closure .PRINT-UNREADABLE-OBJECT-BODY.                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC11si___print_unreadable_object_body_(cl_narg narg, ...)
{
 cl_object T0, T1;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  STREAM          */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=0)) FEwrong_num_arguments_anonym();
 {
TTL:
  T0 = cl_find_package(_ecl_static_4);
  ecl_bds_bind(cl_env_copy,ECL_SYM("*PACKAGE*",43),T0); /*  *PACKAGE* */
  T0 = si_instance_class(ECL_CONS_CAR(CLV0));
  T1 = (cl_env_copy->function=(ECL_SYM("CLASS-NAME",934)->symbol.gfdef))->cfun.entry(1, T0) /*  CLASS-NAME */;
  value0 = cl_format(3, ECL_CONS_CAR(CLV1), _ecl_static_5, T1);
  ecl_bds_unwind1(cl_env_copy);
  return value0;
 }
 }
}
/*	local function G59                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC14__g59(cl_object v1class, cl_object v2stream)
{
 cl_object env0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1class,env0);               /*  CLASS           */
  CLV1 = env0 = CONS(v2stream,env0);              /*  STREAM          */
  {cl_object v3;
   v3 = ECL_NIL;
   v3 = ecl_make_cclosure_va((cl_objectfn)LC13si___print_unreadable_object_body_,env0,Cblock);
   si_print_unreadable_object_function(ECL_CONS_CAR(CLV0), ECL_CONS_CAR(CLV1), ECL_NIL, ECL_NIL, v3);
  }
  value0 = ECL_CONS_CAR(CLV0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	closure .PRINT-UNREADABLE-OBJECT-BODY.                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC13si___print_unreadable_object_body_(cl_narg narg, ...)
{
 cl_object T0, T1, T2;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  STREAM          */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=0)) FEwrong_num_arguments_anonym();
 {
TTL:
  T0 = cl_find_package(_ecl_static_4);
  ecl_bds_bind(cl_env_copy,ECL_SYM("*PACKAGE*",43),T0); /*  *PACKAGE* */
  T0 = si_instance_class(ECL_CONS_CAR(CLV0));
  T1 = (cl_env_copy->function=(ECL_SYM("CLASS-NAME",934)->symbol.gfdef))->cfun.entry(1, T0) /*  CLASS-NAME */;
  T2 = (cl_env_copy->function=(ECL_SYM("CLASS-NAME",934)->symbol.gfdef))->cfun.entry(1, ECL_CONS_CAR(CLV0)) /*  CLASS-NAME */;
  value0 = cl_format(4, ECL_CONS_CAR(CLV1), _ecl_static_6, T1, T2);
  ecl_bds_unwind1(cl_env_copy);
  return value0;
 }
 }
}
/*	local function G60                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC16__g60(cl_object v1gf, cl_object v2stream)
{
 cl_object env0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1gf,env0);                  /*  GF              */
  CLV1 = env0 = CONS(v2stream,env0);              /*  STREAM          */
  {cl_object v3;
   v3 = ECL_NIL;
   v3 = ecl_make_cclosure_va((cl_objectfn)LC15si___print_unreadable_object_body_,env0,Cblock);
   si_print_unreadable_object_function(ECL_CONS_CAR(CLV0), ECL_CONS_CAR(CLV1), ECL_T, ECL_NIL, v3);
  }
  value0 = ECL_CONS_CAR(CLV0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	closure .PRINT-UNREADABLE-OBJECT-BODY.                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC15si___print_unreadable_object_body_(cl_narg narg, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  STREAM          */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=0)) FEwrong_num_arguments_anonym();
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("GENERIC-FUNCTION-NAME",1525))(1, ECL_CONS_CAR(CLV0)) /*  GENERIC-FUNCTION-NAME */;
  value0 = ecl_prin1(T0,ECL_CONS_CAR(CLV1));
  cl_env_copy->nvalues = 1;
  return value0;
 }
 }
}
/*	local function G61                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC18__g61(cl_object v1m, cl_object v2stream)
{
 cl_object env0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1m,env0);                   /*  M               */
  CLV1 = env0 = CONS(v2stream,env0);              /*  STREAM          */
  {cl_object v3;
   v3 = ECL_NIL;
   v3 = ecl_make_cclosure_va((cl_objectfn)LC17si___print_unreadable_object_body_,env0,Cblock);
   si_print_unreadable_object_function(ECL_CONS_CAR(CLV0), ECL_CONS_CAR(CLV1), ECL_T, ECL_NIL, v3);
  }
  value0 = ECL_CONS_CAR(CLV0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	closure .PRINT-UNREADABLE-OBJECT-BODY.                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC17si___print_unreadable_object_body_(cl_narg narg, ...)
{
 cl_object T0, T1;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  STREAM          */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=0)) FEwrong_num_arguments_anonym();
 {
TTL:
  {
   cl_object v1gf;
   v1gf = ecl_function_dispatch(cl_env_copy,ECL_SYM("METHOD-GENERIC-FUNCTION",1532))(1, ECL_CONS_CAR(CLV0)) /*  METHOD-GENERIC-FUNCTION */;
   if (Null(v1gf)) { goto L3; }
   T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("GENERIC-FUNCTION-NAME",1525))(1, v1gf) /*  GENERIC-FUNCTION-NAME */;
   goto L1;
L3:;
   T0 = VV[7];
  }
L1:;
  T1 = ecl_function_dispatch(cl_env_copy,ECL_SYM("METHOD-SPECIALIZERS",1534))(1, ECL_CONS_CAR(CLV0)) /*  METHOD-SPECIALIZERS */;
  value0 = cl_format(4, ECL_CONS_CAR(CLV1), _ecl_static_7, T0, T1);
  return value0;
 }
 }
}
/*	function definition for FLOAT-NAN-STRING                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L19float_nan_string(cl_object v1x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_symbol_value(ECL_SYM("*PRINT-READABLY*",57)))) { goto L1; }
  cl_error(3, ECL_SYM("PRINT-NOT-READABLE",663), ECL_SYM("OBJECT",1278), v1x);
L1:;
  T1 = cl_type_of(v1x);
  T0 = ecl_assql(T1,VV[8]);
  value0 = ecl_cdr(T0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for FLOAT-INFINITY-STRING                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L20float_infinity_string(cl_object v1x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_symbol_value(ECL_SYM("*PRINT-READABLY*",57)))) { goto L1; }
  if (!(ecl_symbol_value(ECL_SYM("*READ-EVAL*",63))==ECL_NIL)) { goto L1; }
  cl_error(3, ECL_SYM("PRINT-NOT-READABLE",663), ECL_SYM("OBJECT",1278), v1x);
L1:;
  {
   cl_object v2record;
   T0 = cl_type_of(v1x);
   if (!(ecl_plusp(v1x))) { goto L6; }
   T1 = VV[11];
   goto L5;
L6:;
   T1 = VV[10];
L5:;
   v2record = ecl_assql(T0,T1);
   if ((v2record)!=ECL_NIL) { goto L8; }
   cl_error(1, _ecl_static_8);
L8:;
   value0 = ecl_cdr(v2record);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G62                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC21__g62(cl_object v1obj, cl_object v2stream)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3class;
   cl_object v4slotds;
   v3class = cl_class_of(v1obj);
   v4slotds = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-SLOTS",1494))(1, v3class) /*  CLASS-SLOTS */;
   T0 = (cl_env_copy->function=(ECL_SYM("CLASS-NAME",934)->symbol.gfdef))->cfun.entry(1, v3class) /*  CLASS-NAME */;
   cl_format(4, v2stream, _ecl_static_9, v1obj, T0);
   {
    cl_object v5scan;
    cl_fixnum v6i;
    cl_object v7sv;
    v5scan = v4slotds;
    v6i = 0;
    v7sv = ECL_NIL;
    goto L10;
L9:;
    v7sv = ecl_instance_ref((v1obj),(v6i));
    T0 = ecl_car(v5scan);
    T1 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, T0) /*  SLOT-DEFINITION-NAME */;
    ecl_print(T1,v2stream);
    ecl_princ_str(":\t",v2stream);
    if (!((v7sv)!=ECL_UNBOUND)) { goto L18; }
    ecl_prin1(v7sv,v2stream);
    goto L17;
L18:;
    ecl_prin1(_ecl_static_11,v2stream);
L17:;
    v5scan = ecl_cdr(v5scan);
    {
     cl_object v8;
     v8 = ecl_make_integer((v6i)+1);
     {
      bool v9;
      v9 = ECL_FIXNUMP(v8);
      if (ecl_unlikely(!(v9)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v8);
     }
     v6i = ecl_fixnum(v8);
    }
L10:;
    if (v5scan==ECL_NIL) { goto L25; }
    goto L9;
L25:;
   }
  }
  value0 = v1obj;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G68                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC22__g68(cl_object v1obj, cl_object v2stream)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3class;
   cl_object v4slotds;
   v3class = si_instance_class(v1obj);
   v4slotds = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-SLOTS",1494))(1, v3class) /*  CLASS-SLOTS */;
   T0 = (cl_env_copy->function=(ECL_SYM("CLASS-NAME",934)->symbol.gfdef))->cfun.entry(1, v3class) /*  CLASS-NAME */;
   cl_format(4, v2stream, _ecl_static_9, v1obj, T0);
   {
    cl_object v5scan;
    cl_fixnum v6i;
    cl_object v7sv;
    v5scan = v4slotds;
    v6i = 0;
    v7sv = ECL_NIL;
    goto L10;
L9:;
    T0 = ecl_car(v5scan);
    T1 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, T0) /*  SLOT-DEFINITION-NAME */;
    ecl_print(T1,v2stream);
    ecl_princ_str(":\t",v2stream);
    {
     cl_object v8;
     T0 = ecl_car(v5scan);
     v8 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, T0) /*  SLOT-DEFINITION-NAME */;
     if (!((v8)==(VV[13]))) { goto L22; }
     goto L19;
     goto L20;
L22:;
     goto L20;
L20:;
     if (!((v8)==(VV[15]))) { goto L17; }
     goto L18;
L19:;
L18:;
     ecl_princ_char((ecl_character)(40),v2stream);
     {
      cl_object v9scan;
      cl_object v10e;
      v9scan = ecl_instance_ref((v1obj),(v6i));
      v10e = ecl_car(v9scan);
      goto L31;
L30:;
      T0 = (cl_env_copy->function=(ECL_SYM("CLASS-NAME",934)->symbol.gfdef))->cfun.entry(1, v10e) /*  CLASS-NAME */;
      ecl_prin1(T0,v2stream);
      if (Null(ecl_cdr(v9scan))) { goto L34; }
      ecl_princ_char((ecl_character)(32),v2stream);
L34:;
      v9scan = ecl_cdr(v9scan);
      v10e = ecl_car(v9scan);
L31:;
      if (v9scan==ECL_NIL) { goto L40; }
      goto L30;
L40:;
     }
     ecl_princ_char((ecl_character)(41),v2stream);
     goto L15;
L17:;
     v7sv = ecl_instance_ref((v1obj),(v6i));
     if (!((v7sv)!=ECL_UNBOUND)) { goto L44; }
     ecl_prin1(v7sv,v2stream);
     goto L15;
L44:;
     ecl_prin1(_ecl_static_11,v2stream);
    }
L15:;
    v5scan = ecl_cdr(v5scan);
    {
     cl_object v8;
     v8 = ecl_make_integer((v6i)+1);
     {
      bool v9;
      v9 = ECL_FIXNUMP(v8);
      if (ecl_unlikely(!(v9)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v8);
     }
     v6i = ecl_fixnum(v8);
    }
L10:;
    if (v5scan==ECL_NIL) { goto L51; }
    goto L9;
L51:;
   }
  }
  value0 = v1obj;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}

#include "clos/print.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclPYi82pfe0Mxk9_rPmtVE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CLOS;PRINT.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclPYi82pfe0Mxk9_rPmtVE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[17]);                           /*  MAKE-LOAD-FORM-SAVING-SLOTS */
 (void)0; /* No entry created for NEED-TO-MAKE-LOAD-FORM-P */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC4__g30,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("MAKE-LOAD-FORM",951), ECL_NIL, VVtemp[0], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC5__g53,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("MAKE-LOAD-FORM",951), ECL_NIL, VVtemp[2], VVtemp[3], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC6__g54,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("MAKE-LOAD-FORM",951), ECL_NIL, VVtemp[4], VVtemp[3], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC7__g55,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("MAKE-LOAD-FORM",951), ECL_NIL, VVtemp[5], VVtemp[3], T0, ECL_T);
 }
 (void)0; /* No entry created for NO-MAKE-LOAD-FORM */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC9__g56,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("MAKE-LOAD-FORM",951), ECL_NIL, VVtemp[6], VVtemp[7], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC10__g57,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("MAKE-LOAD-FORM",951), ECL_NIL, VVtemp[8], VVtemp[9], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC12__g58,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("PRINT-OBJECT",961), ECL_NIL, VVtemp[10], VVtemp[11], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC14__g59,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("PRINT-OBJECT",961), ECL_NIL, VVtemp[12], VVtemp[13], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC16__g60,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("PRINT-OBJECT",961), ECL_NIL, VVtemp[14], VVtemp[15], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC18__g61,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("PRINT-OBJECT",961), ECL_NIL, VVtemp[16], VVtemp[17], T0, ECL_T);
 }
 ecl_cmp_defun(VV[20]);                           /*  FLOAT-NAN-STRING */
 ecl_cmp_defun(VV[21]);                           /*  FLOAT-INFINITY-STRING */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC21__g62,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("DESCRIBE-OBJECT",941), ECL_NIL, VVtemp[10], VVtemp[18], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC22__g68,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("DESCRIBE-OBJECT",941), ECL_NIL, VVtemp[12], VVtemp[18], T0, ECL_T);
 }
}
