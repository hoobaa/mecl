/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CLOS;CHANGE.LSP                                   */
#include <ecl/ecl-cmp.h>
#include "clos/change.eclh"
/*	local function G2                                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC1__g2(cl_narg narg, cl_object v1old_data, cl_object v2new_data, ...)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3initargs;
  ecl_va_list args; ecl_va_start(args,v2new_data,narg,2);
  v3initargs = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v4;
   cl_object v5;
   cl_object v6added_slots;
   v4 = si_instance_sig(v1old_data);
   T0 = si_instance_sig(v2new_data);
   T1 = (ECL_SYM("EQ",333)->symbol.gfdef);
   T2 = (ECL_SYM("SLOT-DEFINITION-ALLOCATION",1543)->symbol.gfdef);
   v5 = cl_remove(6, ECL_SYM("INSTANCE",1256), T0, ECL_SYM("TEST-NOT",1317), T1, ECL_SYM("KEY",1262), T2);
   v6added_slots = ECL_NIL;
   {
    cl_object v7;
    cl_object v8;
    v7 = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
    v8 = v5;
    {
     cl_object v9;
     cl_object v10;
     v9 = ecl_list1(ECL_NIL);
     v10 = v9;
L14:;
     if (!(ecl_endp(v8))) { goto L16; }
     goto L15;
L16:;
     v7 = _ecl_car(v8);
     {
      cl_object v11;
      v11 = _ecl_cdr(v8);
      if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
      v8 = v11;
     }
     if (ecl_unlikely(ECL_ATOM(v10))) FEtype_error_cons(v10);
     T1 = v10;
     T2 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v7) /*  SLOT-DEFINITION-NAME */;
     v10 = ecl_list1(T2);
     (ECL_CONS_CDR(T1)=v10,T1);
     goto L14;
L15:;
     T0 = ecl_cdr(v9);
     goto L8;
    }
   }
L8:;
   {
    cl_object v7;
    cl_object v8;
    v7 = ECL_NIL;
    v8 = v4;
    {
     cl_object v9;
     cl_object v10;
     v9 = ecl_list1(ECL_NIL);
     v10 = v9;
L35:;
     if (!(ecl_endp(v8))) { goto L37; }
     goto L36;
L37:;
     v7 = _ecl_car(v8);
     {
      cl_object v11;
      v11 = _ecl_cdr(v8);
      if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
      v8 = v11;
     }
     if (ecl_unlikely(ECL_ATOM(v10))) FEtype_error_cons(v10);
     T2 = v10;
     T3 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v7) /*  SLOT-DEFINITION-NAME */;
     v10 = ecl_list1(T3);
     (ECL_CONS_CDR(T2)=v10,T2);
     goto L35;
L36:;
     T1 = ecl_cdr(v9);
     goto L30;
    }
   }
L30:;
   v6added_slots = cl_set_difference(2, T0, T1);
   T0 = cl_class_of(v2new_data);
   T1 = (ECL_SYM("UPDATE-INSTANCE-FOR-DIFFERENT-CLASS",979)->symbol.gfdef);
   T2 = cl_list(2, v1old_data, v2new_data);
   T3 = (cl_env_copy->function=(ECL_SYM("COMPUTE-APPLICABLE-METHODS",936)->symbol.gfdef))->cfun.entry(2, T1, T2) /*  COMPUTE-APPLICABLE-METHODS */;
   T4 = (ECL_SYM("SHARED-INITIALIZE",965)->symbol.gfdef);
   T5 = cl_list(2, v2new_data, v6added_slots);
   T6 = (cl_env_copy->function=(ECL_SYM("COMPUTE-APPLICABLE-METHODS",936)->symbol.gfdef))->cfun.entry(2, T4, T5) /*  COMPUTE-APPLICABLE-METHODS */;
   T7 = ecl_function_dispatch(cl_env_copy,VV[5])(2, T3, T6) /*  VALID-KEYWORDS-FROM-METHODS */;
   ecl_function_dispatch(cl_env_copy,VV[6])(3, T0, v3initargs, T7) /*  CHECK-INITARGS */;
   T0 = (ECL_SYM("SHARED-INITIALIZE",965)->symbol.gfdef);
   value0 = cl_apply(4, T0, v2new_data, v6added_slots, v3initargs);
   return value0;
  }
 }
}
/*	local function G30                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC2__g30(cl_narg narg, cl_object v1instance, cl_object v2new_class, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3initargs;
  ecl_va_list args; ecl_va_start(args,v2new_class,narg,2);
  v3initargs = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v4old_instance;
   cl_object v5new_size;
   cl_object v6instance;
   v4old_instance = si_copy_instance(v1instance);
   v5new_size = ecl_function_dispatch(cl_env_copy,VV[7])(1, v2new_class) /*  CLASS-SIZE */;
   v6instance = si_allocate_raw_instance(v1instance, v2new_class, v5new_size);
   si_instance_sig_set(v6instance);
   {
    cl_object v7new_local_slotds;
    T0 = cl_class_of(v6instance);
    v7new_local_slotds = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-SLOTS",1494))(1, T0) /*  CLASS-SLOTS */;
    {
     cl_object v8;
     v8 = v7new_local_slotds;
     goto L10;
L9:;
     {
      cl_object v9new_slot;
      v9new_slot = ecl_car(v8);
      T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-ALLOCATION",1543))(1, v9new_slot) /*  SLOT-DEFINITION-ALLOCATION */;
      if (!((T0)==(ECL_SYM("INSTANCE",1256)))) { goto L14; }
      {
       cl_object v10name;
       v10name = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v9new_slot) /*  SLOT-DEFINITION-NAME */;
       if (Null(cl_slot_exists_p(v4old_instance, v10name))) { goto L17; }
       if (Null(cl_slot_boundp(v4old_instance, v10name))) { goto L17; }
       {
        cl_object v11;
        v11 = cl_slot_value(v4old_instance, v10name);
        (cl_env_copy->function=ECL_CONS_CAR(VV[8]))->cfun.entry(3, v11, v6instance, v10name) /*  (SETF SLOT-VALUE) */;
        goto L14;
       }
L17:;
       cl_slot_makunbound(v6instance, v10name);
      }
L14:;
     }
     v8 = ecl_cdr(v8);
L10:;
     if (Null(v8)) { goto L23; }
     goto L9;
L23:;
    }
   }
   T0 = (ECL_SYM("UPDATE-INSTANCE-FOR-DIFFERENT-CLASS",979)->symbol.gfdef);
   cl_apply(4, T0, v4old_instance, v6instance, v3initargs);
   value0 = v6instance;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G37                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC3__g37(cl_narg narg, cl_object v1instance, cl_object v2new_class, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  if (Null(ecl_function_dispatch(cl_env_copy,VV[9])(1, v1instance) /*  FORWARD-REFERENCED-CLASS-P */)) { goto L1; }
  if (Null(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)))) { goto L3; }
  T0 = ecl_car(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
  T1 = ecl_cdr(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
  value0 = ecl_function_dispatch(cl_env_copy,T0)(2, ecl_symbol_value(ECL_SYM(".COMBINED-METHOD-ARGS.",1473)), T1);
  return value0;
L3:;
  value0 = cl_error(1, _ecl_static_1);
  return value0;
L1:;
  value0 = cl_error(1, _ecl_static_2);
  return value0;
 }
}
/*	local function G38                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC4__g38(cl_narg narg, cl_object v1instance, cl_object v2added_slots, cl_object v3discarded_slots, cl_object v4property_list, ...)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<4)) FEwrong_num_arguments_anonym();
 {
  cl_object v5initargs;
  ecl_va_list args; ecl_va_start(args,v4property_list,narg,4);
  v5initargs = cl_grab_rest_args(args);
  ecl_va_end(args);
  T0 = cl_class_of(v1instance);
  T1 = (ECL_SYM("UPDATE-INSTANCE-FOR-REDEFINED-CLASS",980)->symbol.gfdef);
  T2 = cl_list(4, v1instance, v2added_slots, v3discarded_slots, v4property_list);
  T3 = (cl_env_copy->function=(ECL_SYM("COMPUTE-APPLICABLE-METHODS",936)->symbol.gfdef))->cfun.entry(2, T1, T2) /*  COMPUTE-APPLICABLE-METHODS */;
  T4 = (ECL_SYM("SHARED-INITIALIZE",965)->symbol.gfdef);
  T5 = cl_list(2, v1instance, v2added_slots);
  T6 = (cl_env_copy->function=(ECL_SYM("COMPUTE-APPLICABLE-METHODS",936)->symbol.gfdef))->cfun.entry(2, T4, T5) /*  COMPUTE-APPLICABLE-METHODS */;
  T7 = ecl_function_dispatch(cl_env_copy,VV[5])(2, T3, T6) /*  VALID-KEYWORDS-FROM-METHODS */;
  ecl_function_dispatch(cl_env_copy,VV[6])(3, T0, v5initargs, T7) /*  CHECK-INITARGS */;
  T0 = (ECL_SYM("SHARED-INITIALIZE",965)->symbol.gfdef);
  value0 = cl_apply(4, T0, v1instance, v2added_slots, v5initargs);
  return value0;
 }
}
/*	function definition for UPDATE-INSTANCE                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5update_instance(cl_object v1instance)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2class;
   cl_object v3old_slotds;
   cl_object v4new_slotds;
   cl_object v5old_instance;
   cl_object v6discarded_slots;
   cl_object v7added_slots;
   cl_object v8property_list;
   v2class = cl_class_of(v1instance);
   v3old_slotds = si_instance_sig(v1instance);
   v4new_slotds = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-SLOTS",1494))(1, v2class) /*  CLASS-SLOTS */;
   v5old_instance = si_copy_instance(v1instance);
   v6discarded_slots = ECL_NIL;
   v7added_slots = ECL_NIL;
   v8property_list = ECL_NIL;
   T0 = ecl_function_dispatch(cl_env_copy,VV[7])(1, v2class) /*  CLASS-SIZE */;
   v1instance = si_allocate_raw_instance(v1instance, v2class, T0);
   si_instance_sig_set(v1instance);
   {
    cl_fixnum v9new_i;
    cl_object v10old_local_slotds;
    cl_object v11new_local_slotds;
    v9new_i = 0;
    T0 = (ECL_SYM("EQ",333)->symbol.gfdef);
    T1 = (ECL_SYM("SLOT-DEFINITION-ALLOCATION",1543)->symbol.gfdef);
    v10old_local_slotds = cl_remove(6, ECL_SYM("INSTANCE",1256), v3old_slotds, ECL_SYM("TEST-NOT",1317), T0, ECL_SYM("KEY",1262), T1);
    T0 = (ECL_SYM("EQ",333)->symbol.gfdef);
    T1 = (ECL_SYM("SLOT-DEFINITION-ALLOCATION",1543)->symbol.gfdef);
    v11new_local_slotds = cl_remove(6, ECL_SYM("INSTANCE",1256), v4new_slotds, ECL_SYM("TEST-NOT",1317), T0, ECL_SYM("KEY",1262), T1);
    {
     cl_object v12;
     cl_object v13;
     v12 = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v10old_local_slotds))) FEtype_error_list(v10old_local_slotds);
     v13 = v10old_local_slotds;
     {
      cl_object v14;
      cl_object v15;
      v14 = ecl_list1(ECL_NIL);
      v15 = v14;
L27:;
      if (!(ecl_endp(v13))) { goto L29; }
      goto L28;
L29:;
      v12 = _ecl_car(v13);
      {
       cl_object v16;
       v16 = _ecl_cdr(v13);
       if (ecl_unlikely(!ECL_LISTP(v16))) FEtype_error_list(v16);
       v13 = v16;
      }
      if (ecl_unlikely(ECL_ATOM(v15))) FEtype_error_cons(v15);
      T1 = v15;
      T2 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v12) /*  SLOT-DEFINITION-NAME */;
      v15 = ecl_list1(T2);
      (ECL_CONS_CDR(T1)=v15,T1);
      goto L27;
L28:;
      T0 = ecl_cdr(v14);
      goto L21;
     }
    }
L21:;
    {
     cl_object v12;
     cl_object v13;
     v12 = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v11new_local_slotds))) FEtype_error_list(v11new_local_slotds);
     v13 = v11new_local_slotds;
     {
      cl_object v14;
      cl_object v15;
      v14 = ecl_list1(ECL_NIL);
      v15 = v14;
L49:;
      if (!(ecl_endp(v13))) { goto L51; }
      goto L50;
L51:;
      v12 = _ecl_car(v13);
      {
       cl_object v16;
       v16 = _ecl_cdr(v13);
       if (ecl_unlikely(!ECL_LISTP(v16))) FEtype_error_list(v16);
       v13 = v16;
      }
      if (ecl_unlikely(ECL_ATOM(v15))) FEtype_error_cons(v15);
      T2 = v15;
      T3 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v12) /*  SLOT-DEFINITION-NAME */;
      v15 = ecl_list1(T3);
      (ECL_CONS_CDR(T2)=v15,T2);
      goto L49;
L50:;
      T1 = ecl_cdr(v14);
      goto L43;
     }
    }
L43:;
    v6discarded_slots = cl_set_difference(2, T0, T1);
    {
     cl_object v12;
     v12 = v6discarded_slots;
     goto L69;
L68:;
     {
      cl_object v13slot_name;
      v13slot_name = ecl_car(v12);
      {
       cl_object v14ndx;
       T0 = (ECL_SYM("SLOT-DEFINITION-NAME",1548)->symbol.gfdef);
       v14ndx = cl_position(4, v13slot_name, v10old_local_slotds, ECL_SYM("KEY",1262), T0);
       T0 = si_instance_ref(v5old_instance, v14ndx);
       T1 = CONS(v13slot_name,T0);
       v8property_list = CONS(T1,v8property_list);
      }
     }
     v12 = ecl_cdr(v12);
L69:;
     if (Null(v12)) { goto L79; }
     goto L68;
L79:;
    }
    {
     cl_object v12;
     v12 = v11new_local_slotds;
     goto L84;
L83:;
     {
      cl_object v13new_slot;
      v13new_slot = ecl_car(v12);
      {
       cl_object v14name;
       cl_object v15old_i;
       v14name = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v13new_slot) /*  SLOT-DEFINITION-NAME */;
       T0 = (ECL_SYM("SLOT-DEFINITION-NAME",1548)->symbol.gfdef);
       v15old_i = cl_position(4, v14name, v10old_local_slotds, ECL_SYM("KEY",1262), T0);
       if (Null(v15old_i)) { goto L93; }
       T0 = si_instance_ref(v5old_instance, v15old_i);
       si_instance_set(v1instance, ecl_make_fixnum(v9new_i), T0);
       goto L92;
L93:;
       v7added_slots = CONS(v14name,v7added_slots);
L92:;
       {
        cl_object v16;
        v16 = ecl_plus(ecl_make_fixnum(v9new_i),ecl_make_fixnum(1));
        {
         bool v17;
         v17 = ECL_FIXNUMP(v16);
         if (ecl_unlikely(!(v17)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v16);
        }
        v9new_i = ecl_fixnum(v16);
       }
      }
     }
     v12 = ecl_cdr(v12);
L84:;
     if (Null(v12)) { goto L101; }
     goto L83;
L101:;
    }
   }
   value0 = (cl_env_copy->function=(ECL_SYM("UPDATE-INSTANCE-FOR-REDEFINED-CLASS",980)->symbol.gfdef))->cfun.entry(4, v1instance, v7added_slots, v6discarded_slots, v8property_list) /*  UPDATE-INSTANCE-FOR-REDEFINED-CLASS */;
   return value0;
  }
 }
}
/*	local function G86                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC6__g86(cl_narg narg, cl_object v1class, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2direct_superclasses;
  cl_object v3direct_superclasses_p;
  cl_object v4direct_slots;
  cl_object v5direct_slots_p;
  ecl_va_list args; ecl_va_start(args,v1class,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,LC6__g86keys,keyvars,NULL,TRUE);
   ecl_va_end(args);
   v2direct_superclasses = keyvars[0];
   v3direct_superclasses_p = keyvars[2];
   v4direct_slots = keyvars[1];
   v5direct_slots_p = keyvars[3];
  }
  {
   cl_object v6name;
   v6name = (cl_env_copy->function=(ECL_SYM("CLASS-NAME",934)->symbol.gfdef))->cfun.entry(1, v1class) /*  CLASS-NAME */;
   if (!((v6name)==(ECL_SYM("CLASS",933)))) { goto L7; }
   goto L4;
   goto L5;
L7:;
   goto L5;
L5:;
   if (!((v6name)==(ECL_SYM("BUILT-IN-CLASS",929)))) { goto L1; }
   goto L3;
L4:;
L3:;
   cl_error(2, _ecl_static_3, v6name);
  }
L1:;
  if (Null(ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-FINALIZED-P",1491))(1, v1class) /*  CLASS-FINALIZED-P */)) { goto L10; }
  L8remove_optional_slot_accessors(v1class);
L10:;
  if (Null(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)))) { goto L13; }
  T0 = ecl_car(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
  T1 = ecl_cdr(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
  ecl_function_dispatch(cl_env_copy,T0)(2, ecl_symbol_value(ECL_SYM(".COMBINED-METHOD-ARGS.",1473)), T1);
  goto L12;
L13:;
  cl_error(1, _ecl_static_1);
L12:;
  if (Null(v5direct_slots_p)) { goto L16; }
  {
   cl_object v6;
   {
    cl_object v7s;
    cl_object v8;
    v7s = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v4direct_slots))) FEtype_error_list(v4direct_slots);
    v8 = v4direct_slots;
    {
     cl_object v9;
     cl_object v10;
     v9 = ecl_list1(ECL_NIL);
     v10 = v9;
L24:;
     if (!(ecl_endp(v8))) { goto L26; }
     goto L25;
L26:;
     v7s = _ecl_car(v8);
     {
      cl_object v11;
      v11 = _ecl_cdr(v8);
      if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
      v8 = v11;
     }
     if (ecl_unlikely(ECL_ATOM(v10))) FEtype_error_cons(v10);
     T0 = v10;
     T1 = ecl_function_dispatch(cl_env_copy,VV[13])(2, v1class, v7s) /*  CANONICAL-SLOT-TO-DIRECT-SLOT */;
     v10 = ecl_list1(T1);
     (ECL_CONS_CDR(T0)=v10,T0);
     goto L24;
L25:;
     v6 = ecl_cdr(v9);
     goto L18;
    }
   }
L18:;
   (cl_env_copy->function=ECL_CONS_CAR(VV[14]))->cfun.entry(2, v6, v1class) /*  (SETF CLASS-DIRECT-SLOTS) */;
  }
L16:;
  if (Null(v3direct_superclasses_p)) { goto L40; }
  v2direct_superclasses = ecl_function_dispatch(cl_env_copy,VV[15])(2, v1class, v2direct_superclasses) /*  CHECK-DIRECT-SUPERCLASSES */;
  {
   cl_object v6;
   v6 = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-DIRECT-SUPERCLASSES",1490))(1, v1class) /*  CLASS-DIRECT-SUPERCLASSES */;
   goto L48;
L47:;
   {
    cl_object v7l;
    v7l = ecl_car(v6);
    if ((ecl_memql(v7l,v2direct_superclasses))!=ECL_NIL) { goto L52; }
    ecl_function_dispatch(cl_env_copy,ECL_SYM("REMOVE-DIRECT-SUBCLASS",1539))(2, v7l, v1class) /*  REMOVE-DIRECT-SUBCLASS */;
L52:;
   }
   v6 = ecl_cdr(v6);
L48:;
   if (Null(v6)) { goto L56; }
   goto L47;
L56:;
  }
  {
   cl_object v6;
   v6 = (cl_env_copy->function=ECL_CONS_CAR(VV[16]))->cfun.entry(2, v2direct_superclasses, v1class) /*  (SETF CLASS-DIRECT-SUPERCLASSES) */;
   goto L61;
L60:;
   {
    cl_object v7l;
    v7l = ecl_car(v6);
    ecl_function_dispatch(cl_env_copy,ECL_SYM("ADD-DIRECT-SUBCLASS",1485))(2, v7l, v1class) /*  ADD-DIRECT-SUBCLASS */;
   }
   v6 = ecl_cdr(v6);
L61:;
   if (Null(v6)) { goto L68; }
   goto L60;
L68:;
  }
L40:;
  (cl_env_copy->function=ECL_CONS_CAR(VV[17]))->cfun.entry(2, ECL_NIL, v1class) /*  (SETF CLASS-FINALIZED-P) */;
  ecl_function_dispatch(cl_env_copy,VV[18])(1, v1class) /*  FINALIZE-UNLESS-FORWARD */;
  value0 = v1class;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G110                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC7__g110(cl_object v1class)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-SLOTS",1494))(1, v1class) /*  CLASS-SLOTS */;
   v2 = cl_copy_list(T0);
   (cl_env_copy->function=ECL_CONS_CAR(VV[19]))->cfun.entry(2, v2, v1class) /*  (SETF CLASS-SLOTS) */;
  }
  value0 = v1class;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for REMOVE-OPTIONAL-SLOT-ACCESSORS        */
/*	optimize speed 1, debug 1, space 1, safety 0                  */
static cl_object L8remove_optional_slot_accessors(cl_object v1class)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v2class_name;
  v2class_name = (cl_env_copy->function=(ECL_SYM("CLASS-NAME",934)->symbol.gfdef))->cfun.entry(1, v1class) /*  CLASS-NAME */;
  {
   cl_object v3;
   v3 = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-SLOTS",1494))(1, v1class) /*  CLASS-SLOTS */;
   goto L5;
L4:;
   {
    cl_object v4slotd;
    v4slotd = _ecl_car(v3);
    {
     cl_object v5;
     v5 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-READERS",1549))(1, v4slotd) /*  SLOT-DEFINITION-READERS */;
     goto L13;
L12:;
     {
      cl_object v6reader;
      v6reader = _ecl_car(v5);
      {
       cl_object v7gf_object;
       cl_object v8found;
       v7gf_object = cl_fdefinition(v6reader);
       v8found = ECL_NIL;
       T0 = ecl_list1(v2class_name);
       v8found = (cl_env_copy->function=(ECL_SYM("FIND-METHOD",944)->symbol.gfdef))->cfun.entry(4, v7gf_object, ECL_NIL, T0, ECL_NIL) /*  FIND-METHOD */;
       if (Null(v8found)) { goto L20; }
       (cl_env_copy->function=(ECL_SYM("REMOVE-METHOD",964)->symbol.gfdef))->cfun.entry(2, v7gf_object, v8found) /*  REMOVE-METHOD */;
L20:;
       T0 = ecl_list1(v2class_name);
       v8found = (cl_env_copy->function=(ECL_SYM("FIND-METHOD",944)->symbol.gfdef))->cfun.entry(4, v7gf_object, VV[3], T0, ECL_NIL) /*  FIND-METHOD */;
       if (Null(v8found)) { goto L23; }
       (cl_env_copy->function=(ECL_SYM("REMOVE-METHOD",964)->symbol.gfdef))->cfun.entry(2, v7gf_object, v8found) /*  REMOVE-METHOD */;
L23:;
       T0 = ecl_list1(v2class_name);
       v8found = (cl_env_copy->function=(ECL_SYM("FIND-METHOD",944)->symbol.gfdef))->cfun.entry(4, v7gf_object, VV[4], T0, ECL_NIL) /*  FIND-METHOD */;
       if (Null(v8found)) { goto L26; }
       (cl_env_copy->function=(ECL_SYM("REMOVE-METHOD",964)->symbol.gfdef))->cfun.entry(2, v7gf_object, v8found) /*  REMOVE-METHOD */;
L26:;
       T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("GENERIC-FUNCTION-METHODS",1524))(1, v7gf_object) /*  GENERIC-FUNCTION-METHODS */;
       if (!(T0==ECL_NIL)) { goto L17; }
       cl_fmakunbound(v6reader);
      }
L17:;
     }
     v5 = _ecl_cdr(v5);
L13:;
     if (Null(v5)) { goto L32; }
     goto L12;
L32:;
    }
    {
     cl_object v5;
     v5 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-WRITERS",1551))(1, v4slotd) /*  SLOT-DEFINITION-WRITERS */;
     goto L38;
L37:;
     {
      cl_object v6writer;
      v6writer = _ecl_car(v5);
      {
       cl_object v7gf_object;
       cl_object v8found;
       v7gf_object = cl_fdefinition(v6writer);
       v8found = ECL_NIL;
       T0 = cl_list(2, ECL_T, v2class_name);
       v8found = (cl_env_copy->function=(ECL_SYM("FIND-METHOD",944)->symbol.gfdef))->cfun.entry(4, v7gf_object, ECL_NIL, T0, ECL_NIL) /*  FIND-METHOD */;
       if (Null(v8found)) { goto L45; }
       (cl_env_copy->function=(ECL_SYM("REMOVE-METHOD",964)->symbol.gfdef))->cfun.entry(2, v7gf_object, v8found) /*  REMOVE-METHOD */;
L45:;
       T0 = cl_list(2, ECL_T, v2class_name);
       v8found = (cl_env_copy->function=(ECL_SYM("FIND-METHOD",944)->symbol.gfdef))->cfun.entry(4, v7gf_object, VV[3], T0, ECL_NIL) /*  FIND-METHOD */;
       if (Null(v8found)) { goto L48; }
       (cl_env_copy->function=(ECL_SYM("REMOVE-METHOD",964)->symbol.gfdef))->cfun.entry(2, v7gf_object, v8found) /*  REMOVE-METHOD */;
L48:;
       T0 = cl_list(2, ECL_T, v2class_name);
       v8found = (cl_env_copy->function=(ECL_SYM("FIND-METHOD",944)->symbol.gfdef))->cfun.entry(4, v7gf_object, VV[4], T0, ECL_NIL) /*  FIND-METHOD */;
       if (Null(v8found)) { goto L51; }
       (cl_env_copy->function=(ECL_SYM("REMOVE-METHOD",964)->symbol.gfdef))->cfun.entry(2, v7gf_object, v8found) /*  REMOVE-METHOD */;
L51:;
       T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("GENERIC-FUNCTION-METHODS",1524))(1, v7gf_object) /*  GENERIC-FUNCTION-METHODS */;
       if (!(T0==ECL_NIL)) { goto L42; }
       cl_fmakunbound(v6writer);
      }
L42:;
     }
     v5 = _ecl_cdr(v5);
L38:;
     if (Null(v5)) { goto L57; }
     goto L37;
L57:;
    }
   }
   v3 = _ecl_cdr(v3);
L5:;
   if (Null(v3)) { goto L61; }
   goto L4;
L61:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}

#include "clos/change.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclG9LfcF2entYm9_GFtkfE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CLOS;CHANGE.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclG9LfcF2entYm9_GFtkfE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC1__g2,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("UPDATE-INSTANCE-FOR-DIFFERENT-CLASS",979), ECL_NIL, VVtemp[0], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC2__g30,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("CHANGE-CLASS",932), ECL_NIL, VVtemp[2], VVtemp[3], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC3__g37,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("CHANGE-CLASS",932), ECL_NIL, VVtemp[4], VVtemp[3], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC4__g38,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("UPDATE-INSTANCE-FOR-REDEFINED-CLASS",980), ECL_NIL, VVtemp[5], VVtemp[6], T0, ECL_T);
 }
 ecl_cmp_defun(VV[10]);                           /*  UPDATE-INSTANCE */
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(3, ECL_SYM("REINITIALIZE-INSTANCE",963), ECL_SYM("LAMBDA-LIST",998), VVtemp[7]) /*  ENSURE-GENERIC-FUNCTION */;
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC6__g86,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("REINITIALIZE-INSTANCE",963), ECL_NIL, VVtemp[8], VVtemp[9], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC7__g110,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("MAKE-INSTANCES-OBSOLETE",950), ECL_NIL, VVtemp[8], VVtemp[8], T0, ECL_T);
 }
 (void)0; /* No entry created for REMOVE-OPTIONAL-SLOT-ACCESSORS */
}
