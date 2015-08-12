/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CLOS;INSPECT.LSP                                  */
#include <ecl/ecl-cmp.h>
#include "clos/inspect.eclh"
/*	local function G64                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC1__g64(cl_object v1instance)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2class;
   cl_object v3local_slotds;
   cl_object v4class_slotds;
   v2class = si_instance_class(v1instance);
   v3local_slotds = L14class_local_slots(v2class);
   v4class_slotds = L15class_class_slots(v2class);
   if (Null(v3local_slotds)) { goto L5; }
   ecl_function_dispatch(cl_env_copy,VV[44])(0)   /*  INSPECT-INDENT  */;
   cl_format(2, ECL_T, _ecl_static_1);
   cl_set(VV[1],ecl_plus(ecl_symbol_value(VV[1]),ecl_make_fixnum(1)));
   {
    cl_object v5;
    v5 = v3local_slotds;
    goto L15;
L14:;
    {
     cl_object v6slotd;
     v6slotd = ecl_car(v5);
     ecl_function_dispatch(cl_env_copy,VV[45])(0) /*  INSPECT-INDENT-1 */;
     T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v6slotd) /*  SLOT-DEFINITION-NAME */;
     cl_format(3, ECL_T, _ecl_static_2, T0);
     T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v6slotd) /*  SLOT-DEFINITION-NAME */;
     if (Null(cl_slot_boundp(v1instance, T0))) { goto L22; }
     {
      cl_object v8;                               /*  UPDATE-FLAG     */
      cl_object v9;                               /*  NEW-VALUE       */
      T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v6slotd) /*  SLOT-DEFINITION-NAME */;
      T1 = cl_slot_value(v1instance, T0);
      value0 = ecl_function_dispatch(cl_env_copy,VV[46])(3, _ecl_static_3, T1, ECL_T) /*  READ-INSPECT-COMMAND */;
      v8 = value0;
      {
       const int v10 = cl_env_copy->nvalues;
       cl_object v11;
       v11 = (v10<=1)? ECL_NIL : cl_env_copy->values[1];
       v9 = v11;
      }
      if (Null(v8)) { goto L21; }
      {
       cl_object v10;
       v10 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v6slotd) /*  SLOT-DEFINITION-NAME */;
       (cl_env_copy->function=ECL_CONS_CAR(VV[47]))->cfun.entry(3, v9, v1instance, v10) /*  (SETF SLOT-VALUE) */;
       goto L21;
      }
     }
L22:;
     {
      cl_object v8;                               /*  UPDATE-FLAG     */
      cl_object v9;                               /*  NEW-VALUE       */
      value0 = ecl_function_dispatch(cl_env_copy,VV[46])(3, _ecl_static_4, ECL_NIL, ECL_NIL) /*  READ-INSPECT-COMMAND */;
      v8 = value0;
      {
       const int v10 = cl_env_copy->nvalues;
       cl_object v11;
       v11 = (v10<=1)? ECL_NIL : cl_env_copy->values[1];
       v9 = v11;
      }
      if (Null(v8)) { goto L21; }
      {
       cl_object v10;
       v10 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v6slotd) /*  SLOT-DEFINITION-NAME */;
       (cl_env_copy->function=ECL_CONS_CAR(VV[47]))->cfun.entry(3, v9, v1instance, v10) /*  (SETF SLOT-VALUE) */;
      }
     }
L21:;
    }
    v5 = ecl_cdr(v5);
L15:;
    if (Null(v5)) { goto L32; }
    goto L14;
L32:;
   }
   cl_set(VV[1],ecl_minus(ecl_symbol_value(VV[1]),ecl_make_fixnum(1)));
   goto L4;
L5:;
   ecl_function_dispatch(cl_env_copy,VV[44])(0)   /*  INSPECT-INDENT  */;
   cl_format(2, ECL_T, _ecl_static_5);
L4:;
   if (Null(v4class_slotds)) { goto L36; }
   ecl_function_dispatch(cl_env_copy,VV[44])(0)   /*  INSPECT-INDENT  */;
   cl_format(2, ECL_T, _ecl_static_6);
   cl_set(VV[1],ecl_plus(ecl_symbol_value(VV[1]),ecl_make_fixnum(1)));
   {
    cl_object v5;
    v5 = v4class_slotds;
    goto L46;
L45:;
    {
     cl_object v6slotd;
     v6slotd = ecl_car(v5);
     ecl_function_dispatch(cl_env_copy,VV[45])(0) /*  INSPECT-INDENT-1 */;
     T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v6slotd) /*  SLOT-DEFINITION-NAME */;
     cl_format(3, ECL_T, _ecl_static_2, T0);
     T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v6slotd) /*  SLOT-DEFINITION-NAME */;
     if (Null(cl_slot_boundp(v1instance, T0))) { goto L53; }
     {
      cl_object v8;                               /*  UPDATE-FLAG     */
      cl_object v9;                               /*  NEW-VALUE       */
      T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v6slotd) /*  SLOT-DEFINITION-NAME */;
      T1 = cl_slot_value(v1instance, T0);
      value0 = ecl_function_dispatch(cl_env_copy,VV[46])(3, _ecl_static_3, T1, ECL_T) /*  READ-INSPECT-COMMAND */;
      v8 = value0;
      {
       const int v10 = cl_env_copy->nvalues;
       cl_object v11;
       v11 = (v10<=1)? ECL_NIL : cl_env_copy->values[1];
       v9 = v11;
      }
      if (Null(v8)) { goto L52; }
      {
       cl_object v10;
       v10 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v6slotd) /*  SLOT-DEFINITION-NAME */;
       (cl_env_copy->function=ECL_CONS_CAR(VV[47]))->cfun.entry(3, v9, v1instance, v10) /*  (SETF SLOT-VALUE) */;
       goto L52;
      }
     }
L53:;
     {
      cl_object v8;                               /*  UPDATE-FLAG     */
      cl_object v9;                               /*  NEW-VALUE       */
      value0 = ecl_function_dispatch(cl_env_copy,VV[46])(3, _ecl_static_4, ECL_NIL, ECL_NIL) /*  READ-INSPECT-COMMAND */;
      v8 = value0;
      {
       const int v10 = cl_env_copy->nvalues;
       cl_object v11;
       v11 = (v10<=1)? ECL_NIL : cl_env_copy->values[1];
       v9 = v11;
      }
      if (Null(v8)) { goto L52; }
      {
       cl_object v10;
       v10 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v6slotd) /*  SLOT-DEFINITION-NAME */;
       (cl_env_copy->function=ECL_CONS_CAR(VV[47]))->cfun.entry(3, v9, v1instance, v10) /*  (SETF SLOT-VALUE) */;
      }
     }
L52:;
    }
    v5 = ecl_cdr(v5);
L46:;
    if (Null(v5)) { goto L63; }
    goto L45;
L63:;
   }
   cl_set(VV[1],ecl_minus(ecl_symbol_value(VV[1]),ecl_make_fixnum(1)));
   value0 = ecl_symbol_value(VV[1]);
   cl_env_copy->nvalues = 1;
   return value0;
L36:;
   ecl_function_dispatch(cl_env_copy,VV[44])(0)   /*  INSPECT-INDENT  */;
   value0 = cl_format(2, ECL_T, _ecl_static_7);
   return value0;
  }
 }
}
/*	function definition for SELECT-CLOS-N-INNER-CLASS             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2select_clos_n_inner_class(cl_object v1instance)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2class;
   cl_object v3local_slotds;
   v2class = si_instance_class(v1instance);
   v3local_slotds = L14class_local_slots(v2class);
   if (Null(v3local_slotds)) { goto L3; }
   ecl_function_dispatch(cl_env_copy,VV[44])(0)   /*  INSPECT-INDENT  */;
   cl_format(2, ECL_T, _ecl_static_8);
   cl_set(VV[1],ecl_plus(ecl_symbol_value(VV[1]),ecl_make_fixnum(1)));
   {
    cl_object v4;
    v4 = v3local_slotds;
    goto L13;
L12:;
    {
     cl_object v5slotd;
     v5slotd = ecl_car(v4);
     ecl_function_dispatch(cl_env_copy,VV[45])(0) /*  INSPECT-INDENT-1 */;
     T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v5slotd) /*  SLOT-DEFINITION-NAME */;
     cl_format(3, ECL_T, _ecl_static_2, T0);
     T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v5slotd) /*  SLOT-DEFINITION-NAME */;
     if (Null(cl_slot_boundp(v1instance, T0))) { goto L20; }
     T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v5slotd) /*  SLOT-DEFINITION-NAME */;
     T1 = cl_slot_value(v1instance, T0);
     if (Null(ecl_function_dispatch(cl_env_copy,VV[46])(3, _ecl_static_3, T1, ECL_T) /*  READ-INSPECT-COMMAND */)) { goto L19; }
     ecl_princ_str("Not updated.",ECL_NIL);
     ecl_terpri(ECL_NIL);
     goto L19;
L20:;
     if (Null(ecl_function_dispatch(cl_env_copy,VV[46])(3, _ecl_static_4, ECL_NIL, ECL_NIL) /*  READ-INSPECT-COMMAND */)) { goto L19; }
     ecl_princ_str("Not updated.",ECL_NIL);
     ecl_terpri(ECL_NIL);
L19:;
    }
    v4 = ecl_cdr(v4);
L13:;
    if (Null(v4)) { goto L30; }
    goto L12;
L30:;
   }
   cl_set(VV[1],ecl_minus(ecl_symbol_value(VV[1]),ecl_make_fixnum(1)));
   value0 = ecl_symbol_value(VV[1]);
   cl_env_copy->nvalues = 1;
   return value0;
L3:;
   ecl_function_dispatch(cl_env_copy,VV[44])(0)   /*  INSPECT-INDENT  */;
   value0 = cl_format(2, ECL_T, _ecl_static_10);
   return value0;
  }
 }
}
/*	local function G98                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC3__g98(cl_object v1instance)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L2select_clos_n_inner_class(v1instance);
  return value0;
 }
}
/*	local function G99                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC4__g99(cl_object v1instance)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L2select_clos_n_inner_class(v1instance);
  return value0;
 }
}
/*	local function G100                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC5__g100(cl_object v1instance)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2class;
   cl_object v3local_slotds;
   cl_object v4class_slotds;
   v2class = si_instance_class(v1instance);
   v3local_slotds = L14class_local_slots(v2class);
   v4class_slotds = L15class_class_slots(v2class);
   ecl_terpri(ECL_NIL);
   if (Null(v3local_slotds)) { goto L6; }
   cl_format(2, ECL_T, _ecl_static_11);
   {
    cl_object v5;
    v5 = v3local_slotds;
    goto L12;
L11:;
    {
     cl_object v6slotd;
     v6slotd = ecl_car(v5);
     T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v6slotd) /*  SLOT-DEFINITION-NAME */;
     cl_format(3, ECL_T, _ecl_static_12, T0);
    }
    v5 = ecl_cdr(v5);
L12:;
    if (Null(v5)) { goto L19; }
    goto L11;
L19:;
    goto L5;
   }
L6:;
   cl_format(2, ECL_T, _ecl_static_5);
L5:;
   ecl_terpri(ECL_NIL);
   if (Null(v4class_slotds)) { goto L23; }
   cl_format(2, ECL_T, _ecl_static_13);
   {
    cl_object v5;
    v5 = v4class_slotds;
    goto L29;
L28:;
    {
     cl_object v6slotd;
     v6slotd = ecl_car(v5);
     T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v6slotd) /*  SLOT-DEFINITION-NAME */;
     cl_format(3, ECL_T, _ecl_static_12, T0);
    }
    v5 = ecl_cdr(v5);
L29:;
    if (Null(v5)) { goto L36; }
    goto L28;
L36:;
    goto L22;
   }
L23:;
   cl_format(2, ECL_T, _ecl_static_7);
L22:;
   value0 = ecl_terpri(ECL_NIL);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for SELECT-CLOS-L-INNER-CLASS             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6select_clos_l_inner_class(cl_object v1instance)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2class;
   cl_object v3local_slotds;
   v2class = si_instance_class(v1instance);
   v3local_slotds = L14class_local_slots(v2class);
   ecl_terpri(ECL_NIL);
   if (Null(v3local_slotds)) { goto L5; }
   cl_format(2, ECL_T, _ecl_static_14);
   {
    cl_object v4;
    v4 = v3local_slotds;
    goto L11;
L10:;
    {
     cl_object v5slotd;
     v5slotd = ecl_car(v4);
     T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v5slotd) /*  SLOT-DEFINITION-NAME */;
     cl_format(3, ECL_T, _ecl_static_12, T0);
    }
    v4 = ecl_cdr(v4);
L11:;
    if (Null(v4)) { goto L18; }
    goto L10;
L18:;
    goto L4;
   }
L5:;
   cl_format(2, ECL_T, _ecl_static_10);
L4:;
   value0 = ecl_terpri(ECL_NIL);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G110                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC7__g110(cl_object v1instance)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L6select_clos_l_inner_class(v1instance);
  return value0;
 }
}
/*	local function G111                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC8__g111(cl_object v1instance)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L6select_clos_l_inner_class(v1instance);
  return value0;
 }
}
/*	local function G132                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC9__g132(cl_object v1instance)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2class;
   cl_object v3local_slotds;
   cl_object v4class_slotds;
   cl_object v5slotd;
   v2class = si_instance_class(v1instance);
   v3local_slotds = L14class_local_slots(v2class);
   v4class_slotds = L15class_class_slots(v2class);
   {
    cl_object v6;
    {
     cl_object v7;
     v7 = cl_read_preserving_whitespace(1, ecl_symbol_value(ECL_SYM("*QUERY-IO*",59)));
     ecl_function_dispatch(cl_env_copy,VV[50])(0) /*  INSPECT-READ-LINE */;
     v6 = v7;
    }
    {
     cl_object v7;
     v7 = ecl_append(v3local_slotds,v4class_slotds);
     goto L12;
L11:;
     {
      cl_object v8;
      cl_object v9;
      if (ecl_unlikely(ECL_ATOM(v7))) FEtype_error_cons(v7);
      v8 = v7;
      v9 = ECL_CONS_CAR(v8);
      T1 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v9) /*  SLOT-DEFINITION-NAME */;
      if (!((v6)==(T1))) { goto L14; }
      T0 = v8;
      goto L5;
     }
L14:;
     v7 = ECL_CONS_CDR(v7);
L12:;
     if (v7==ECL_NIL) { goto L21; }
     goto L11;
L21:;
     T0 = ECL_NIL;
    }
   }
L5:;
   v5slotd = ecl_car(T0);
   if (Null(v5slotd)) { goto L23; }
   cl_set(VV[1],ecl_plus(ecl_symbol_value(VV[1]),ecl_make_fixnum(1)));
   ecl_function_dispatch(cl_env_copy,VV[45])(0)   /*  INSPECT-INDENT-1 */;
   T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v5slotd) /*  SLOT-DEFINITION-NAME */;
   cl_format(3, ECL_T, _ecl_static_2, T0);
   T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v5slotd) /*  SLOT-DEFINITION-NAME */;
   if (Null(cl_slot_boundp(v1instance, T0))) { goto L30; }
   {
    cl_object v7;                                 /*  UPDATE-FLAG     */
    cl_object v8;                                 /*  NEW-VALUE       */
    T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v5slotd) /*  SLOT-DEFINITION-NAME */;
    T1 = cl_slot_value(v1instance, T0);
    value0 = ecl_function_dispatch(cl_env_copy,VV[46])(3, _ecl_static_3, T1, ECL_T) /*  READ-INSPECT-COMMAND */;
    v7 = value0;
    {
     const int v9 = cl_env_copy->nvalues;
     cl_object v10;
     v10 = (v9<=1)? ECL_NIL : cl_env_copy->values[1];
     v8 = v10;
    }
    if (Null(v7)) { goto L29; }
    {
     cl_object v9;
     v9 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v5slotd) /*  SLOT-DEFINITION-NAME */;
     (cl_env_copy->function=ECL_CONS_CAR(VV[47]))->cfun.entry(3, v8, v1instance, v9) /*  (SETF SLOT-VALUE) */;
     goto L29;
    }
   }
L30:;
   {
    cl_object v7;                                 /*  UPDATE-FLAG     */
    cl_object v8;                                 /*  NEW-VALUE       */
    value0 = ecl_function_dispatch(cl_env_copy,VV[46])(3, _ecl_static_4, ECL_NIL, ECL_NIL) /*  READ-INSPECT-COMMAND */;
    v7 = value0;
    {
     const int v9 = cl_env_copy->nvalues;
     cl_object v10;
     v10 = (v9<=1)? ECL_NIL : cl_env_copy->values[1];
     v8 = v10;
    }
    if (Null(v7)) { goto L29; }
    {
     cl_object v9;
     v9 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v5slotd) /*  SLOT-DEFINITION-NAME */;
     (cl_env_copy->function=ECL_CONS_CAR(VV[47]))->cfun.entry(3, v8, v1instance, v9) /*  (SETF SLOT-VALUE) */;
    }
   }
L29:;
   cl_set(VV[1],ecl_minus(ecl_symbol_value(VV[1]),ecl_make_fixnum(1)));
   value0 = ecl_symbol_value(VV[1]);
   cl_env_copy->nvalues = 1;
   return value0;
L23:;
   ecl_terpri(ECL_NIL);
   T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v5slotd) /*  SLOT-DEFINITION-NAME */;
   cl_format(3, ECL_T, _ecl_static_15, T0);
   ecl_terpri(ECL_NIL);
   value0 = ecl_terpri(ECL_NIL);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for SELECT-CLOS-J-INNER-CLASS             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L10select_clos_j_inner_class(cl_object v1instance)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2class;
   cl_object v3local_slotds;
   cl_object v4slotd;
   v2class = si_instance_class(v1instance);
   v3local_slotds = L14class_local_slots(v2class);
   {
    cl_object v5;
    {
     cl_object v6;
     v6 = cl_read_preserving_whitespace(1, ecl_symbol_value(ECL_SYM("*QUERY-IO*",59)));
     ecl_function_dispatch(cl_env_copy,VV[50])(0) /*  INSPECT-READ-LINE */;
     v5 = v6;
    }
    {
     cl_object v6;
     v6 = v3local_slotds;
     goto L11;
L10:;
     {
      cl_object v7;
      cl_object v8;
      if (ecl_unlikely(ECL_ATOM(v6))) FEtype_error_cons(v6);
      v7 = v6;
      v8 = ECL_CONS_CAR(v7);
      T1 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v8) /*  SLOT-DEFINITION-NAME */;
      if (!((v5)==(T1))) { goto L13; }
      T0 = v7;
      goto L4;
     }
L13:;
     v6 = ECL_CONS_CDR(v6);
L11:;
     if (v6==ECL_NIL) { goto L20; }
     goto L10;
L20:;
     T0 = ECL_NIL;
    }
   }
L4:;
   v4slotd = ecl_car(T0);
   if (Null(v4slotd)) { goto L22; }
   cl_set(VV[1],ecl_plus(ecl_symbol_value(VV[1]),ecl_make_fixnum(1)));
   ecl_function_dispatch(cl_env_copy,VV[45])(0)   /*  INSPECT-INDENT-1 */;
   T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v4slotd) /*  SLOT-DEFINITION-NAME */;
   cl_format(3, ECL_T, _ecl_static_2, T0);
   T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v4slotd) /*  SLOT-DEFINITION-NAME */;
   if (Null(cl_slot_boundp(v1instance, T0))) { goto L29; }
   T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v4slotd) /*  SLOT-DEFINITION-NAME */;
   T1 = cl_slot_value(v1instance, T0);
   if (Null(ecl_function_dispatch(cl_env_copy,VV[46])(3, _ecl_static_3, T1, ECL_T) /*  READ-INSPECT-COMMAND */)) { goto L28; }
   ecl_princ_str("Not updated.",ECL_NIL);
   ecl_terpri(ECL_NIL);
   goto L28;
L29:;
   if (Null(ecl_function_dispatch(cl_env_copy,VV[46])(3, _ecl_static_4, ECL_NIL, ECL_NIL) /*  READ-INSPECT-COMMAND */)) { goto L28; }
   ecl_princ_str("Not updated.",ECL_NIL);
   ecl_terpri(ECL_NIL);
L28:;
   cl_set(VV[1],ecl_minus(ecl_symbol_value(VV[1]),ecl_make_fixnum(1)));
   value0 = ecl_symbol_value(VV[1]);
   cl_env_copy->nvalues = 1;
   return value0;
L22:;
   ecl_terpri(ECL_NIL);
   T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v4slotd) /*  SLOT-DEFINITION-NAME */;
   cl_format(3, ECL_T, _ecl_static_15, T0);
   ecl_terpri(ECL_NIL);
   value0 = ecl_terpri(ECL_NIL);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G159                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC11__g159(cl_object v1instance)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L10select_clos_j_inner_class(v1instance);
  return value0;
 }
}
/*	local function G160                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC12__g160(cl_object v1instance)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L10select_clos_j_inner_class(v1instance);
  return value0;
 }
}
/*	function definition for SELECT-CLOS-?                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L13select_clos__()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_terpri(ECL_NIL);
  value0 = cl_format(2, ECL_T, _ecl_static_16);
  return value0;
 }
}
/*	function definition for CLASS-LOCAL-SLOTS                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L14class_local_slots(cl_object v1class)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-SLOTS",1494))(1, v1class) /*  CLASS-SLOTS */;
  T1 = (ECL_SYM("SLOT-DEFINITION-ALLOCATION",1543)->symbol.gfdef);
  value0 = cl_remove(4, VV[7], T0, ECL_SYM("KEY",1262), T1);
  return value0;
 }
}
/*	function definition for CLASS-CLASS-SLOTS                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L15class_class_slots(cl_object v1class)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-SLOTS",1494))(1, v1class) /*  CLASS-SLOTS */;
  T1 = (ECL_SYM("SLOT-DEFINITION-ALLOCATION",1543)->symbol.gfdef);
  value0 = cl_remove(4, ECL_SYM("INSTANCE",1256), T0, ECL_SYM("KEY",1262), T1);
  return value0;
 }
}
/*	local function G179                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC16__g179(cl_object v1instance)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2metaclass;
   T0 = si_instance_class(v1instance);
   v2metaclass = ECL_CLASS_OF(T0);
   T0 = cl_find_class(1, ECL_SYM("STANDARD-CLASS",973));
   if ((v2metaclass)==(T0)) { goto L1; }
   T0 = cl_find_class(1, ECL_SYM("FUNCALLABLE-STANDARD-CLASS",1516));
   if ((v2metaclass)==(T0)) { goto L1; }
  }
  ecl_terpri(ECL_NIL);
  cl_format(2, ECL_T, _ecl_static_17);
  T0 = si_instance_class(v1instance);
  cl_format(3, ECL_T, _ecl_static_18, T0);
  cl_env_copy->values[0] = ECL_NIL;
  cl_env_copy->nvalues = 1;
  cl_throw(VV[11]);
L1:;
  cl_set(VV[1],ecl_minus(ecl_symbol_value(VV[1]),ecl_make_fixnum(1)));
  {
   cl_object v2class;
   cl_object v3local_slotds;
   cl_object v4class_slotds;
   v2class = si_instance_class(v1instance);
   v3local_slotds = L14class_local_slots(v2class);
   v4class_slotds = L15class_class_slots(v2class);
L15:;
   cl_format(3, ECL_T, _ecl_static_19, v1instance);
   cl_set(VV[1],ecl_plus(ecl_symbol_value(VV[1]),ecl_make_fixnum(1)));
   ecl_function_dispatch(cl_env_copy,VV[44])(0)   /*  INSPECT-INDENT  */;
   T0 = (cl_env_copy->function=(ECL_SYM("CLASS-NAME",934)->symbol.gfdef))->cfun.entry(1, v2class) /*  CLASS-NAME */;
   cl_format(3, ECL_T, _ecl_static_20, T0);
   ecl_function_dispatch(cl_env_copy,VV[44])(0)   /*  INSPECT-INDENT  */;
   {
    cl_fixnum v5;
    v5 = ecl_length(v3local_slotds);
    {
     cl_fixnum v6;
     v6 = ecl_length(v4class_slotds);
     cl_format(4, ECL_T, _ecl_static_21, ecl_make_fixnum(v5), ecl_make_fixnum(v6));
    }
   }
   cl_force_output(0);
   {
    cl_object v5;
    {
     cl_object v6char;
     v6char = cl_read_char(1, ecl_symbol_value(ECL_SYM("*QUERY-IO*",59)));
     goto L30;
L29:;
     v6char = cl_read_char(1, ecl_symbol_value(ECL_SYM("*QUERY-IO*",59)));
L30:;
     if (!(ecl_char_code(v6char)!=ecl_char_code(CODE_CHAR(32)))) { goto L37; }
     if ((cl_charNE(1, CODE_CHAR(9)))!=ECL_NIL) { goto L34; }
     goto L35;
L37:;
     goto L35;
L35:;
     goto L29;
L34:;
     v5 = v6char;
    }
    if (!(((v5)==ECL_CODE_CHAR((ecl_character)(10))))) { goto L44; }
    goto L41;
    goto L42;
L44:;
    goto L42;
L42:;
    if (!(((v5)==ECL_CODE_CHAR((ecl_character)(13))))) { goto L39; }
    goto L40;
L41:;
L40:;
    ecl_function_dispatch(cl_env_copy,VV[0])(1, v1instance) /*  SELECT-CLOS-N */;
    goto L11;
L39:;
    if (!(((v5)==ECL_CODE_CHAR((ecl_character)(110))))) { goto L53; }
    goto L50;
    goto L51;
L53:;
    goto L51;
L51:;
    if (!(((v5)==ECL_CODE_CHAR((ecl_character)(78))))) { goto L48; }
    goto L49;
L50:;
L49:;
    ecl_function_dispatch(cl_env_copy,VV[50])(0)  /*  INSPECT-READ-LINE */;
    ecl_function_dispatch(cl_env_copy,VV[0])(1, v1instance) /*  SELECT-CLOS-N */;
    goto L11;
L48:;
    if (!(((v5)==ECL_CODE_CHAR((ecl_character)(115))))) { goto L63; }
    goto L60;
    goto L61;
L63:;
    goto L61;
L61:;
    if (!(((v5)==ECL_CODE_CHAR((ecl_character)(83))))) { goto L58; }
    goto L59;
L60:;
L59:;
    ecl_function_dispatch(cl_env_copy,VV[50])(0)  /*  INSPECT-READ-LINE */;
    goto L11;
L58:;
    if (!(((v5)==ECL_CODE_CHAR((ecl_character)(112))))) { goto L72; }
    goto L69;
    goto L70;
L72:;
    goto L70;
L70:;
    if (!(((v5)==ECL_CODE_CHAR((ecl_character)(80))))) { goto L67; }
    goto L68;
L69:;
L68:;
    ecl_function_dispatch(cl_env_copy,VV[50])(0)  /*  INSPECT-READ-LINE */;
    ecl_function_dispatch(cl_env_copy,VV[54])(1, v1instance) /*  SELECT-P */;
    goto L25;
L67:;
    if (!(((v5)==ECL_CODE_CHAR((ecl_character)(97))))) { goto L81; }
    goto L78;
    goto L79;
L81:;
    goto L79;
L79:;
    if (!(((v5)==ECL_CODE_CHAR((ecl_character)(65))))) { goto L76; }
    goto L77;
L78:;
L77:;
    ecl_function_dispatch(cl_env_copy,VV[50])(0)  /*  INSPECT-READ-LINE */;
    cl_env_copy->values[0] = ECL_NIL;
    cl_env_copy->nvalues = 1;
    cl_throw(VV[11]);
L76:;
    if (!(((v5)==ECL_CODE_CHAR((ecl_character)(101))))) { goto L91; }
    goto L88;
    goto L89;
L91:;
    goto L89;
L89:;
    if (!(((v5)==ECL_CODE_CHAR((ecl_character)(69))))) { goto L86; }
    goto L87;
L88:;
L87:;
    ecl_function_dispatch(cl_env_copy,VV[55])(0)  /*  SELECT-E        */;
    goto L25;
L86:;
    if (!(((v5)==ECL_CODE_CHAR((ecl_character)(113))))) { goto L99; }
    goto L96;
    goto L97;
L99:;
    goto L97;
L97:;
    if (!(((v5)==ECL_CODE_CHAR((ecl_character)(81))))) { goto L94; }
    goto L95;
L96:;
L95:;
    ecl_function_dispatch(cl_env_copy,VV[50])(0)  /*  INSPECT-READ-LINE */;
    cl_env_copy->values[0] = ECL_NIL;
    cl_env_copy->nvalues = 1;
    cl_throw(VV[26]);
L94:;
    if (!(((v5)==ECL_CODE_CHAR((ecl_character)(108))))) { goto L109; }
    goto L106;
    goto L107;
L109:;
    goto L107;
L107:;
    if (!(((v5)==ECL_CODE_CHAR((ecl_character)(76))))) { goto L104; }
    goto L105;
L106:;
L105:;
    ecl_function_dispatch(cl_env_copy,VV[50])(0)  /*  INSPECT-READ-LINE */;
    ecl_function_dispatch(cl_env_copy,VV[3])(1, v1instance) /*  SELECT-CLOS-L */;
    goto L25;
L104:;
    if (!(((v5)==ECL_CODE_CHAR((ecl_character)(106))))) { goto L118; }
    goto L115;
    goto L116;
L118:;
    goto L116;
L116:;
    if (!(((v5)==ECL_CODE_CHAR((ecl_character)(74))))) { goto L113; }
    goto L114;
L115:;
L114:;
    ecl_function_dispatch(cl_env_copy,VV[5])(1, v1instance) /*  SELECT-CLOS-J */;
    goto L25;
L113:;
    if (!(((v5)==ECL_CODE_CHAR((ecl_character)(63))))) { goto L121; }
    ecl_function_dispatch(cl_env_copy,VV[50])(0)  /*  INSPECT-READ-LINE */;
    L13select_clos__();
    goto L25;
L121:;
    ecl_function_dispatch(cl_env_copy,VV[50])(0)  /*  INSPECT-READ-LINE */;
   }
L25:;
   cl_set(VV[1],ecl_minus(ecl_symbol_value(VV[1]),ecl_make_fixnum(1)));
   ecl_function_dispatch(cl_env_copy,VV[44])(0)   /*  INSPECT-INDENT  */;
   goto L15;
  }
L11:;
  cl_set(VV[1],ecl_plus(ecl_symbol_value(VV[1]),ecl_make_fixnum(1)));
  value0 = ecl_symbol_value(VV[1]);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for INSPECT-OBJ-INNER-CLASS               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L17inspect_obj_inner_class(cl_object v1instance)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  cl_set(VV[1],ecl_minus(ecl_symbol_value(VV[1]),ecl_make_fixnum(1)));
  {
   cl_object v2class;
   cl_object v3local_slotds;
   v2class = si_instance_class(v1instance);
   v3local_slotds = L14class_local_slots(v2class);
L6:;
   cl_format(3, ECL_T, _ecl_static_19, v1instance);
   cl_set(VV[1],ecl_plus(ecl_symbol_value(VV[1]),ecl_make_fixnum(1)));
   ecl_function_dispatch(cl_env_copy,VV[44])(0)   /*  INSPECT-INDENT  */;
   T0 = (cl_env_copy->function=(ECL_SYM("CLASS-NAME",934)->symbol.gfdef))->cfun.entry(1, v2class) /*  CLASS-NAME */;
   cl_format(3, ECL_T, _ecl_static_20, T0);
   ecl_function_dispatch(cl_env_copy,VV[44])(0)   /*  INSPECT-INDENT  */;
   {
    cl_fixnum v4;
    v4 = ecl_length(v3local_slotds);
    cl_format(3, ECL_T, _ecl_static_22, ecl_make_fixnum(v4));
   }
   cl_force_output(0);
   {
    cl_object v4;
    {
     cl_object v5char;
     v5char = cl_read_char(1, ecl_symbol_value(ECL_SYM("*QUERY-IO*",59)));
     goto L21;
L20:;
     v5char = cl_read_char(1, ecl_symbol_value(ECL_SYM("*QUERY-IO*",59)));
L21:;
     if (!(ecl_char_code(v5char)!=ecl_char_code(CODE_CHAR(32)))) { goto L28; }
     if ((cl_charNE(1, CODE_CHAR(9)))!=ECL_NIL) { goto L25; }
     goto L26;
L28:;
     goto L26;
L26:;
     goto L20;
L25:;
     v4 = v5char;
    }
    if (!(((v4)==ECL_CODE_CHAR((ecl_character)(10))))) { goto L35; }
    goto L32;
    goto L33;
L35:;
    goto L33;
L33:;
    if (!(((v4)==ECL_CODE_CHAR((ecl_character)(13))))) { goto L30; }
    goto L31;
L32:;
L31:;
    ecl_function_dispatch(cl_env_copy,VV[0])(1, v1instance) /*  SELECT-CLOS-N */;
    goto L3;
L30:;
    if (!(((v4)==ECL_CODE_CHAR((ecl_character)(110))))) { goto L44; }
    goto L41;
    goto L42;
L44:;
    goto L42;
L42:;
    if (!(((v4)==ECL_CODE_CHAR((ecl_character)(78))))) { goto L39; }
    goto L40;
L41:;
L40:;
    ecl_function_dispatch(cl_env_copy,VV[50])(0)  /*  INSPECT-READ-LINE */;
    ecl_function_dispatch(cl_env_copy,VV[0])(1, v1instance) /*  SELECT-CLOS-N */;
    goto L3;
L39:;
    if (!(((v4)==ECL_CODE_CHAR((ecl_character)(115))))) { goto L54; }
    goto L51;
    goto L52;
L54:;
    goto L52;
L52:;
    if (!(((v4)==ECL_CODE_CHAR((ecl_character)(83))))) { goto L49; }
    goto L50;
L51:;
L50:;
    ecl_function_dispatch(cl_env_copy,VV[50])(0)  /*  INSPECT-READ-LINE */;
    goto L3;
L49:;
    if (!(((v4)==ECL_CODE_CHAR((ecl_character)(112))))) { goto L63; }
    goto L60;
    goto L61;
L63:;
    goto L61;
L61:;
    if (!(((v4)==ECL_CODE_CHAR((ecl_character)(80))))) { goto L58; }
    goto L59;
L60:;
L59:;
    ecl_function_dispatch(cl_env_copy,VV[50])(0)  /*  INSPECT-READ-LINE */;
    ecl_function_dispatch(cl_env_copy,VV[54])(1, v1instance) /*  SELECT-P */;
    goto L16;
L58:;
    if (!(((v4)==ECL_CODE_CHAR((ecl_character)(97))))) { goto L72; }
    goto L69;
    goto L70;
L72:;
    goto L70;
L70:;
    if (!(((v4)==ECL_CODE_CHAR((ecl_character)(65))))) { goto L67; }
    goto L68;
L69:;
L68:;
    ecl_function_dispatch(cl_env_copy,VV[50])(0)  /*  INSPECT-READ-LINE */;
    cl_env_copy->values[0] = ECL_NIL;
    cl_env_copy->nvalues = 1;
    cl_throw(VV[11]);
L67:;
    if (!(((v4)==ECL_CODE_CHAR((ecl_character)(101))))) { goto L82; }
    goto L79;
    goto L80;
L82:;
    goto L80;
L80:;
    if (!(((v4)==ECL_CODE_CHAR((ecl_character)(69))))) { goto L77; }
    goto L78;
L79:;
L78:;
    ecl_function_dispatch(cl_env_copy,VV[55])(0)  /*  SELECT-E        */;
    goto L16;
L77:;
    if (!(((v4)==ECL_CODE_CHAR((ecl_character)(113))))) { goto L90; }
    goto L87;
    goto L88;
L90:;
    goto L88;
L88:;
    if (!(((v4)==ECL_CODE_CHAR((ecl_character)(81))))) { goto L85; }
    goto L86;
L87:;
L86:;
    ecl_function_dispatch(cl_env_copy,VV[50])(0)  /*  INSPECT-READ-LINE */;
    cl_env_copy->values[0] = ECL_NIL;
    cl_env_copy->nvalues = 1;
    cl_throw(VV[26]);
L85:;
    if (!(((v4)==ECL_CODE_CHAR((ecl_character)(108))))) { goto L100; }
    goto L97;
    goto L98;
L100:;
    goto L98;
L98:;
    if (!(((v4)==ECL_CODE_CHAR((ecl_character)(76))))) { goto L95; }
    goto L96;
L97:;
L96:;
    ecl_function_dispatch(cl_env_copy,VV[50])(0)  /*  INSPECT-READ-LINE */;
    ecl_function_dispatch(cl_env_copy,VV[3])(1, v1instance) /*  SELECT-CLOS-L */;
    goto L16;
L95:;
    if (!(((v4)==ECL_CODE_CHAR((ecl_character)(106))))) { goto L109; }
    goto L106;
    goto L107;
L109:;
    goto L107;
L107:;
    if (!(((v4)==ECL_CODE_CHAR((ecl_character)(74))))) { goto L104; }
    goto L105;
L106:;
L105:;
    ecl_function_dispatch(cl_env_copy,VV[5])(1, v1instance) /*  SELECT-CLOS-J */;
    goto L16;
L104:;
    if (!(((v4)==ECL_CODE_CHAR((ecl_character)(63))))) { goto L112; }
    ecl_function_dispatch(cl_env_copy,VV[50])(0)  /*  INSPECT-READ-LINE */;
    L13select_clos__();
    goto L16;
L112:;
    ecl_function_dispatch(cl_env_copy,VV[50])(0)  /*  INSPECT-READ-LINE */;
   }
L16:;
   cl_set(VV[1],ecl_minus(ecl_symbol_value(VV[1]),ecl_make_fixnum(1)));
   ecl_function_dispatch(cl_env_copy,VV[44])(0)   /*  INSPECT-INDENT  */;
   goto L6;
  }
L3:;
  cl_set(VV[1],ecl_plus(ecl_symbol_value(VV[1]),ecl_make_fixnum(1)));
  value0 = ecl_symbol_value(VV[1]);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G224                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC18__g224(cl_object v1instance)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L17inspect_obj_inner_class(v1instance);
  return value0;
 }
}
/*	local function G225                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC19__g225(cl_object v1instance)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L17inspect_obj_inner_class(v1instance);
  return value0;
 }
}
/*	local function G226                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC20__g226(cl_object v1object, cl_object v2doc_type)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_memql(v2doc_type,VV[35]))) { goto L1; }
  if (!((v2doc_type)==(ECL_SYM("TYPE",869)))) { goto L3; }
  {
   cl_object v3c;
   v3c = cl_find_class(2, v1object, ECL_NIL);
   if (Null(v3c)) { goto L6; }
   value0 = (cl_env_copy->function=(ECL_SYM("DOCUMENTATION",312)->symbol.gfdef))->cfun.entry(2, v3c, ECL_T) /*  DOCUMENTATION */;
   return value0;
L6:;
   value0 = si_get_documentation(2, v1object, v2doc_type);
   return value0;
  }
L3:;
  if (!((v2doc_type)==(ECL_SYM("FUNCTION",396)))) { goto L8; }
  value0 = si_get_documentation(2, v1object, v2doc_type);
  if ((value0)!=ECL_NIL) { goto L11; }
  if (Null(cl_fboundp(v1object))) { goto L14; }
  value0 = cl_macro_function(1, v1object);
  if ((value0)!=ECL_NIL) { goto L18; }
  T0 = cl_fdefinition(v1object);
  goto L16;
L18:;
  T0 = value0;
  goto L16;
L16:;
  value0 = (cl_env_copy->function=(ECL_SYM("DOCUMENTATION",312)->symbol.gfdef))->cfun.entry(2, T0, v2doc_type) /*  DOCUMENTATION */;
  return value0;
L14:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L11:;
  cl_env_copy->nvalues = 1;
  return value0;
L8:;
  value0 = si_get_documentation(2, v1object, v2doc_type);
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G240                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC21__g240(cl_object v1new_value, cl_object v2object, cl_object v3doc_type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_memql(v3doc_type,VV[35]))) { goto L1; }
  if (!((v3doc_type)==(ECL_SYM("TYPE",869)))) { goto L3; }
  {
   cl_object v4c;
   v4c = cl_find_class(2, v2object, ECL_NIL);
   if (Null(v4c)) { goto L6; }
   si_set_documentation(3, v2object, ECL_SYM("TYPE",869), ECL_NIL);
   si_set_documentation(3, v2object, ECL_SYM("STRUCTURE",826), ECL_NIL);
   (cl_env_copy->function=ECL_CONS_CAR(VV[57]))->cfun.entry(3, v1new_value, v4c, ECL_T) /*  (SETF DOCUMENTATION) */;
   goto L1;
L6:;
   si_set_documentation(3, v2object, v3doc_type, v1new_value);
   goto L1;
  }
L3:;
  if (!((v3doc_type)==(ECL_SYM("FUNCTION",396)))) { goto L10; }
  if (Null(cl_fboundp(v2object))) { goto L12; }
  {
   cl_object v5c;
   value0 = cl_macro_function(1, v2object);
   if ((value0)!=ECL_NIL) { goto L16; }
   v5c = cl_fdefinition(v2object);
   goto L14;
L16:;
   v5c = value0;
   goto L14;
L14:;
   si_set_documentation(3, v5c, ECL_SYM("FUNCTION",396), ECL_NIL);
   (cl_env_copy->function=ECL_CONS_CAR(VV[57]))->cfun.entry(3, v1new_value, v5c, ECL_SYM("FUNCTION",396)) /*  (SETF DOCUMENTATION) */;
   goto L1;
  }
L12:;
  si_set_documentation(3, v2object, v3doc_type, v1new_value);
  goto L1;
L10:;
  si_set_documentation(3, v2object, v3doc_type, v1new_value);
L1:;
  value0 = v1new_value;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G248                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC22__g248(cl_object v1object, cl_object v2doc_type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ecl_eql(v2doc_type,ECL_T))) { goto L6; }
  goto L3;
  goto L4;
L6:;
  goto L4;
L4:;
  if (!((v2doc_type)==(ECL_SYM("PACKAGE",617)))) { goto L1; }
  goto L2;
L3:;
L2:;
  value0 = si_get_documentation(2, v1object, ECL_SYM("PACKAGE",617));
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G250                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC23__g250(cl_object v1new_value, cl_object v2object, cl_object v3doc_type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ecl_eql(v3doc_type,ECL_T))) { goto L6; }
  goto L3;
  goto L4;
L6:;
  goto L4;
L4:;
  if (!((v3doc_type)==(ECL_SYM("PACKAGE",617)))) { goto L1; }
  goto L2;
L3:;
L2:;
  value0 = si_set_documentation(3, v2object, ECL_SYM("PACKAGE",617), v1new_value);
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G252                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC24__g252(cl_object v1object, cl_object v2doc_type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ecl_eql(v2doc_type,ECL_T))) { goto L7; }
  goto L4;
  goto L5;
L7:;
  goto L5;
L5:;
  if (!((v2doc_type)==(ECL_SYM("TYPE",869)))) { goto L1; }
  goto L3;
L4:;
L3:;
  if (Null(cl_slot_boundp(v1object, ECL_SYM("DOCSTRING",1579)))) { goto L1; }
  value0 = cl_slot_value(v1object, ECL_SYM("DOCSTRING",1579));
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G260                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC25__g260(cl_object v1new_value, cl_object v2object, cl_object v3doc_type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ecl_eql(v3doc_type,ECL_T))) { goto L6; }
  goto L3;
  goto L4;
L6:;
  goto L4;
L4:;
  if (!((v3doc_type)==(ECL_SYM("TYPE",869)))) { goto L1; }
  goto L2;
L3:;
L2:;
  value0 = (cl_env_copy->function=ECL_CONS_CAR(VV[47]))->cfun.entry(3, v1new_value, v2object, ECL_SYM("DOCSTRING",1579)) /*  (SETF SLOT-VALUE) */;
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G265                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC26__g265(cl_object v1object, cl_object v2doc_type)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ecl_eql(v2doc_type,ECL_T))) { goto L6; }
  goto L3;
  goto L4;
L6:;
  goto L4;
L4:;
  if (!((v2doc_type)==(ECL_SYM("TYPE",869)))) { goto L1; }
  goto L2;
L3:;
L2:;
  T0 = (cl_env_copy->function=(ECL_SYM("CLASS-NAME",934)->symbol.gfdef))->cfun.entry(1, v1object) /*  CLASS-NAME */;
  value0 = si_get_documentation(2, T0, ECL_SYM("STRUCTURE",826));
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G273                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC27__g273(cl_object v1new_value, cl_object v2object, cl_object v3doc_type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ecl_eql(v3doc_type,ECL_T))) { goto L6; }
  goto L3;
  goto L4;
L6:;
  goto L4;
L4:;
  if (!((v3doc_type)==(ECL_SYM("TYPE",869)))) { goto L1; }
  goto L2;
L3:;
L2:;
  {
   cl_object v4;
   v4 = (cl_env_copy->function=(ECL_SYM("CLASS-NAME",934)->symbol.gfdef))->cfun.entry(1, v2object) /*  CLASS-NAME */;
   value0 = (cl_env_copy->function=ECL_CONS_CAR(VV[57]))->cfun.entry(3, v1new_value, v4, ECL_SYM("STRUCTURE",826)) /*  (SETF DOCUMENTATION) */;
   return value0;
  }
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G278                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC28__g278(cl_object v1object, cl_object v2doc_type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!((v2doc_type)==(ECL_SYM("FUNCTION",396)))) { goto L6; }
  goto L3;
  goto L4;
L6:;
  goto L4;
L4:;
  if (!((v2doc_type)==(ECL_SYM("COMPILER-MACRO",238)))) { goto L1; }
  goto L2;
L3:;
L2:;
  value0 = si_get_documentation(2, v1object, v2doc_type);
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G280                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC29__g280(cl_object v1new_value, cl_object v2object, cl_object v3doc_type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!((v3doc_type)==(ECL_SYM("FUNCTION",396)))) { goto L6; }
  goto L3;
  goto L4;
L6:;
  goto L4;
L4:;
  if (!((v3doc_type)==(ECL_SYM("COMPILER-MACRO",238)))) { goto L1; }
  goto L2;
L3:;
L2:;
  value0 = si_set_documentation(3, v2object, v3doc_type, v1new_value);
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G282                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC30__g282(cl_object v1object, cl_object v2doc_type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ecl_eql(v2doc_type,ECL_T))) { goto L6; }
  goto L3;
  goto L4;
L6:;
  goto L4;
L4:;
  if (!((v2doc_type)==(ECL_SYM("FUNCTION",396)))) { goto L1; }
  goto L2;
L3:;
L2:;
  value0 = cl_slot_value(v1object, ECL_SYM("DOCSTRING",1579));
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G290                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC31__g290(cl_object v1new_value, cl_object v2object, cl_object v3doc_type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ecl_eql(v3doc_type,ECL_T))) { goto L6; }
  goto L3;
  goto L4;
L6:;
  goto L4;
L4:;
  if (!((v3doc_type)==(ECL_SYM("FUNCTION",396)))) { goto L1; }
  goto L2;
L3:;
L2:;
  value0 = (cl_env_copy->function=ECL_CONS_CAR(VV[47]))->cfun.entry(3, v1new_value, v2object, ECL_SYM("DOCSTRING",1579)) /*  (SETF SLOT-VALUE) */;
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G295                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC32__g295(cl_object v1object, cl_object v2doc_type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ecl_eql(v2doc_type,ECL_T))) { goto L6; }
  goto L3;
  goto L4;
L6:;
  goto L4;
L4:;
  if (!((v2doc_type)==(ECL_SYM("FUNCTION",396)))) { goto L1; }
  goto L2;
L3:;
L2:;
  value0 = cl_slot_value(v1object, ECL_SYM("DOCSTRING",1579));
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G303                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC33__g303(cl_object v1new_value, cl_object v2object, cl_object v3doc_type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ecl_eql(v3doc_type,ECL_T))) { goto L6; }
  goto L3;
  goto L4;
L6:;
  goto L4;
L4:;
  if (!((v3doc_type)==(ECL_SYM("FUNCTION",396)))) { goto L1; }
  goto L2;
L3:;
L2:;
  value0 = (cl_env_copy->function=ECL_CONS_CAR(VV[47]))->cfun.entry(3, v1new_value, v2object, ECL_SYM("DOCSTRING",1579)) /*  (SETF SLOT-VALUE) */;
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G308                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC34__g308(cl_object v1object, cl_object v2doc_type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ecl_eql(v2doc_type,ECL_T))) { goto L6; }
  goto L3;
  goto L4;
L6:;
  goto L4;
L4:;
  if (!((v2doc_type)==(ECL_SYM("FUNCTION",396)))) { goto L1; }
  goto L2;
L3:;
L2:;
  value0 = si_get_documentation(2, v1object, v2doc_type);
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G310                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC35__g310(cl_object v1new_value, cl_object v2object, cl_object v3doc_type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ecl_eql(v3doc_type,ECL_T))) { goto L6; }
  goto L3;
  goto L4;
L6:;
  goto L4;
L4:;
  if (!((v3doc_type)==(ECL_SYM("FUNCTION",396)))) { goto L1; }
  goto L2;
L3:;
L2:;
  value0 = si_set_documentation(3, v2object, v3doc_type, v1new_value);
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G312                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC36__g312(cl_object v1object, cl_object v2doc_type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ecl_eql(v2doc_type,ECL_T))) { goto L6; }
  goto L3;
  goto L4;
L6:;
  goto L4;
L4:;
  if (!((v2doc_type)==(ECL_SYM("FUNCTION",396)))) { goto L1; }
  goto L2;
L3:;
L2:;
  value0 = cl_slot_value(v1object, ECL_SYM("DOCSTRING",1579));
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G320                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC37__g320(cl_object v1new_value, cl_object v2object, cl_object v3doc_type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ecl_eql(v3doc_type,ECL_T))) { goto L6; }
  goto L3;
  goto L4;
L6:;
  goto L4;
L4:;
  if (!((v3doc_type)==(ECL_SYM("FUNCTION",396)))) { goto L1; }
  goto L2;
L3:;
L2:;
  value0 = (cl_env_copy->function=ECL_CONS_CAR(VV[47]))->cfun.entry(3, v1new_value, v2object, ECL_SYM("DOCSTRING",1579)) /*  (SETF SLOT-VALUE) */;
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}

#include "clos/inspect.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecl0zu8S2MY4lIi9_bdvTOE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CLOS;INSPECT.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_ecl0zu8S2MY4lIi9_bdvTOE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC1__g64,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, VV[0], ECL_NIL, VVtemp[0], VVtemp[1], T0, ECL_T);
 }
 ecl_cmp_defun(VV[48]);                           /*  SELECT-CLOS-N-INNER-CLASS */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC3__g98,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, VV[0], ECL_NIL, VVtemp[2], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC4__g99,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, VV[0], ECL_NIL, VVtemp[3], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC5__g100,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, VV[3], ECL_NIL, VVtemp[0], VVtemp[1], T0, ECL_T);
 }
 ecl_cmp_defun(VV[49]);                           /*  SELECT-CLOS-L-INNER-CLASS */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC7__g110,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, VV[3], ECL_NIL, VVtemp[2], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC8__g111,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, VV[3], ECL_NIL, VVtemp[3], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC9__g132,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, VV[5], ECL_NIL, VVtemp[0], VVtemp[1], T0, ECL_T);
 }
 ecl_cmp_defun(VV[51]);                           /*  SELECT-CLOS-J-INNER-CLASS */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC11__g159,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, VV[5], ECL_NIL, VVtemp[2], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC12__g160,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, VV[5], ECL_NIL, VVtemp[3], VVtemp[1], T0, ECL_T);
 }
 (void)0; /* No entry created for SELECT-CLOS-? */
 ecl_cmp_defun(VV[52]);                           /*  CLASS-LOCAL-SLOTS */
 ecl_cmp_defun(VV[53]);                           /*  CLASS-CLASS-SLOTS */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC16__g179,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, VV[10], ECL_NIL, VVtemp[0], VVtemp[1], T0, ECL_T);
 }
 ecl_cmp_defun(VV[56]);                           /*  INSPECT-OBJ-INNER-CLASS */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC18__g224,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, VV[10], ECL_NIL, VVtemp[2], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC19__g225,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, VV[10], ECL_NIL, VVtemp[3], VVtemp[1], T0, ECL_T);
 }
 si_Xmake_constant(VV[33], VVtemp[4]);
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(5, ECL_SYM("DOCUMENTATION",312), VV[34], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[5]) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(5, VVtemp[6], VV[34], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[7]) /*  ENSURE-GENERIC-FUNCTION */;
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC20__g226,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("DOCUMENTATION",312), ECL_NIL, VVtemp[8], VVtemp[5], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC21__g240,ECL_NIL,Cblock,3);
  T0 = v1;
 }
 clos_install_method(6, VVtemp[6], ECL_NIL, VVtemp[9], VVtemp[7], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC22__g248,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("DOCUMENTATION",312), ECL_NIL, VVtemp[10], VVtemp[5], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC23__g250,ECL_NIL,Cblock,3);
  T0 = v1;
 }
 clos_install_method(6, VVtemp[6], ECL_NIL, VVtemp[11], VVtemp[7], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC24__g252,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("DOCUMENTATION",312), ECL_NIL, VVtemp[12], VVtemp[5], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC25__g260,ECL_NIL,Cblock,3);
  T0 = v1;
 }
 clos_install_method(6, VVtemp[6], ECL_NIL, VVtemp[13], VVtemp[7], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC26__g265,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("DOCUMENTATION",312), ECL_NIL, VVtemp[14], VVtemp[5], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC27__g273,ECL_NIL,Cblock,3);
  T0 = v1;
 }
 clos_install_method(6, VVtemp[6], ECL_NIL, VVtemp[15], VVtemp[7], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC28__g278,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("DOCUMENTATION",312), ECL_NIL, VVtemp[16], VVtemp[5], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC29__g280,ECL_NIL,Cblock,3);
  T0 = v1;
 }
 clos_install_method(6, VVtemp[6], ECL_NIL, VVtemp[17], VVtemp[7], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC30__g282,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("DOCUMENTATION",312), ECL_NIL, VVtemp[18], VVtemp[5], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC31__g290,ECL_NIL,Cblock,3);
  T0 = v1;
 }
 clos_install_method(6, VVtemp[6], ECL_NIL, VVtemp[19], VVtemp[7], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC32__g295,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("DOCUMENTATION",312), ECL_NIL, VVtemp[20], VVtemp[5], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC33__g303,ECL_NIL,Cblock,3);
  T0 = v1;
 }
 clos_install_method(6, VVtemp[6], ECL_NIL, VVtemp[21], VVtemp[7], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC34__g308,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("DOCUMENTATION",312), ECL_NIL, VVtemp[22], VVtemp[5], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC35__g310,ECL_NIL,Cblock,3);
  T0 = v1;
 }
 clos_install_method(6, VVtemp[6], ECL_NIL, VVtemp[23], VVtemp[7], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC36__g312,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("DOCUMENTATION",312), ECL_NIL, VVtemp[24], VVtemp[5], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC37__g320,ECL_NIL,Cblock,3);
  T0 = v1;
 }
 clos_install_method(6, VVtemp[6], ECL_NIL, VVtemp[25], VVtemp[7], T0, ECL_T);
 }
}
