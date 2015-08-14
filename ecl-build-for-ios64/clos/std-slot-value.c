/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CLOS;STD-SLOT-VALUE.LSP                           */
#include <ecl/ecl-cmp.h>
#include "clos/std-slot-value.eclh"
/*	local function WITH-SLOTS                                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC1with_slots(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4slot_entries;
   cl_object v5instance_form;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4slot_entries = v6;
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
     v8scan = v4slot_entries;
     v9res = ECL_NIL;
     goto L20;
L19:;
     T0 = ecl_car(v8scan);
     if (!(ECL_SYMBOLP(T0))) { goto L23; }
     T0 = ecl_car(v8scan);
     T1 = ecl_car(v8scan);
     T2 = cl_list(2, ECL_SYM("QUOTE",679), T1);
     T3 = cl_list(3, ECL_SYM("SLOT-VALUE",971), v6temp, T2);
     T4 = cl_list(2, T0, T3);
     v9res = CONS(T4,v9res);
     goto L22;
L23:;
     T0 = ecl_caar(v8scan);
     T1 = ecl_cadar(v8scan);
     T2 = cl_list(2, ECL_SYM("QUOTE",679), T1);
     T3 = cl_list(3, ECL_SYM("SLOT-VALUE",971), v6temp, T2);
     T4 = cl_list(2, T0, T3);
     v9res = CONS(T4,v9res);
L22:;
     v8scan = ecl_cdr(v8scan);
L20:;
     if (v8scan==ECL_NIL) { goto L29; }
     goto L19;
L29:;
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
/*	function definition for STD-CREATE-SLOTS-TABLE                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2std_create_slots_table(cl_object v1class)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2size;
   cl_object v3table;
   T0 = cl_slot_value(v1class, VV[1]);
   {
    cl_fixnum v4;
    v4 = ecl_length(T0);
    T1 = ecl_times(ecl_make_fixnum(2),ecl_make_fixnum(v4));
    v2size = (ecl_number_compare(ecl_make_fixnum(32),T1)>=0?ecl_make_fixnum(32):T1);
   }
   v3table = cl_make_hash_table(2, ECL_SYM("SIZE",1308), v2size);
   {
    cl_object v4;
    v4 = cl_slot_value(v1class, VV[1]);
    goto L7;
L6:;
    {
     cl_object v5slotd;
     v5slotd = ecl_car(v4);
     T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v5slotd) /*  SLOT-DEFINITION-NAME */;
     si_hash_set(T0, v3table, v5slotd);
    }
    v4 = ecl_cdr(v4);
L7:;
    if (Null(v4)) { goto L14; }
    goto L6;
L14:;
   }
   {
    cl_object v4;
    cl_object v5locations;
    v4 = si_instance_class(v1class);
    v5locations = ECL_NIL;
    T0 = cl_find_class(1, ECL_SYM("STANDARD-CLASS",973));
    if ((v4)==(T0)) { goto L20; }
    T0 = cl_find_class(1, ECL_SYM("FUNCALLABLE-STANDARD-CLASS",1516));
    if ((v4)==(T0)) { goto L20; }
    T0 = cl_find_class(1, ECL_SYM("STRUCTURE-CLASS",977));
    if (!((v4)==(T0))) { goto L18; }
    goto L19;
L20:;
L19:;
    v5locations = cl_make_hash_table(2, ECL_SYM("SIZE",1308), v2size);
    {
     cl_object v6;
     v6 = cl_slot_value(v1class, VV[1]);
     goto L28;
L27:;
     {
      cl_object v7slotd;
      v7slotd = ecl_car(v6);
      T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v7slotd) /*  SLOT-DEFINITION-NAME */;
      T1 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-LOCATION",1547))(1, v7slotd) /*  SLOT-DEFINITION-LOCATION */;
      si_hash_set(T0, v5locations, T1);
     }
     v6 = ecl_cdr(v6);
L28:;
     if (Null(v6)) { goto L35; }
     goto L27;
L35:;
    }
L18:;
    (cl_env_copy->function=ECL_CONS_CAR(VV[9]))->cfun.entry(3, v3table, v1class, ECL_SYM("SLOT-TABLE",1555)) /*  (SETF SLOT-VALUE) */;
    value0 = (cl_env_copy->function=ECL_CONS_CAR(VV[9]))->cfun.entry(3, v5locations, v1class, ECL_SYM("LOCATION-TABLE",1527)) /*  (SETF SLOT-VALUE) */;
    return value0;
   }
  }
 }
}
/*	function definition for FIND-SLOT-DEFINITION                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object clos_find_slot_definition(cl_narg narg, cl_object v1class, cl_object v2slot_name, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  T0 = si_instance_class(v1class);
  if ((T0)==(ecl_symbol_value(ECL_SYM("+THE-STANDARD-CLASS+",1480)))) { goto L3; }
  T0 = si_instance_class(v1class);
  if (!((T0)==(ecl_symbol_value(ECL_SYM("+THE-FUNCALLABLE-STANDARD-CLASS+",1481))))) { goto L1; }
  goto L2;
L3:;
L2:;
  T0 = cl_slot_value(v1class, ECL_SYM("SLOT-TABLE",1555));
  value0 = cl_gethash(3, v2slot_name, T0, ECL_NIL);
  return value0;
L1:;
  {
   cl_object v3;
   cl_object v4;
   v3 = cl_slot_value(v1class, VV[1]);
   v4 = si_make_seq_iterator(2, v3, ecl_make_fixnum(0));
L7:;
   if ((v4)!=ECL_NIL) { goto L9; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L9:;
   {
    cl_object v5;
    v5 = si_seq_iterator_ref(v3, v4);
    T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v5) /*  SLOT-DEFINITION-NAME */;
    if (!(ecl_eql(v2slot_name,T0))) { goto L11; }
    value0 = v5;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L11:;
   v4 = si_seq_iterator_next(v3, v4);
   goto L7;
  }
 }
}
/*	function definition for UPDATE-INSTANCE                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3update_instance(cl_object v1x)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = si_instance_sig_set(v1x);
  return value0;
 }
}
/*	function definition for STANDARD-INSTANCE-GET                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object clos_standard_instance_get(cl_object v1instance, cl_object v2location)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3s;
   v3s = si_instance_sig(v1instance);
   if (!((v3s)!=ECL_UNBOUND)) { goto L1; }
   T0 = ECL_CLASS_OF(v1instance);
   T1 = ecl_instance_ref((T0),(6));
   if ((v3s)==(T1)) { goto L1; }
   ecl_function_dispatch(cl_env_copy,VV[4])(1, v1instance) /*  UPDATE-INSTANCE */;
  }
L1:;
  if (!(ECL_FIXNUMP(v2location))) { goto L5; }
  value0 = ecl_instance_ref((v1instance),(ecl_to_fixnum(v2location)));
  cl_env_copy->nvalues = 1;
  return value0;
L5:;
  if (!(ECL_CONSP(v2location))) { goto L7; }
  value0 = ecl_car(v2location);
  cl_env_copy->nvalues = 1;
  return value0;
L7:;
  value0 = L4invalid_slot_location(v1instance, v2location);
  return value0;
 }
}
/*	function definition for STANDARD-INSTANCE-SET                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object clos_standard_instance_set(cl_object v1val, cl_object v2instance, cl_object v3location)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4s;
   v4s = si_instance_sig(v2instance);
   if (!((v4s)!=ECL_UNBOUND)) { goto L1; }
   T0 = ECL_CLASS_OF(v2instance);
   T1 = ecl_instance_ref((T0),(6));
   if ((v4s)==(T1)) { goto L1; }
   ecl_function_dispatch(cl_env_copy,VV[4])(1, v2instance) /*  UPDATE-INSTANCE */;
  }
L1:;
  if (!(ECL_FIXNUMP(v3location))) { goto L6; }
  si_instance_set(v2instance, v3location, v1val);
  goto L5;
L6:;
  if (!(ECL_CONSP(v3location))) { goto L8; }
  if (ecl_unlikely(ECL_ATOM(v3location))) FEtype_error_cons(v3location);
  T0 = v3location;
  (ECL_CONS_CAR(T0)=v1val,T0);
  goto L5;
L8:;
  L4invalid_slot_location(v2instance, v3location);
L5:;
  value0 = v1val;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for SLOT-VALUE                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_slot_value(cl_object v1self, cl_object v2slot_name)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3class;
   cl_object v4location_table;
   v3class = cl_class_of(v1self);
   v4location_table = ecl_instance_ref((v3class),(19));
   if (Null(v4location_table)) { goto L3; }
   {
    cl_object v5location;
    v5location = ecl_gethash_safe(v2slot_name,v4location_table,ECL_NIL);
    if (Null(v5location)) { goto L6; }
    {
     cl_object v6value;
     v6value = clos_standard_instance_get(v1self, v5location);
     if (!((v6value)!=ECL_UNBOUND)) { goto L9; }
     value0 = v6value;
     cl_env_copy->nvalues = 1;
     return value0;
L9:;
     value0 = (cl_env_copy->function=(ECL_SYM("SLOT-UNBOUND",970)->symbol.gfdef))->cfun.entry(3, v3class, v1self, v2slot_name) /*  SLOT-UNBOUND */;
     cl_env_copy->nvalues = 1;
     return value0;
    }
L6:;
    value0 = (cl_env_copy->function=(ECL_SYM("SLOT-MISSING",969)->symbol.gfdef))->cfun.entry(4, v3class, v1self, v2slot_name, ECL_SYM("SLOT-VALUE",971)) /*  SLOT-MISSING */;
    return value0;
   }
L3:;
   {
    cl_object v7slotd;
    {
     cl_object v8;
     cl_object v9;
     v8 = ecl_instance_ref((v3class),(6));
     v9 = si_make_seq_iterator(2, v8, ecl_make_fixnum(0));
L15:;
     if ((v9)!=ECL_NIL) { goto L17; }
     v7slotd = ECL_NIL;
     goto L12;
L17:;
     {
      cl_object v10;
      v10 = si_seq_iterator_ref(v8, v9);
      T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v10) /*  SLOT-DEFINITION-NAME */;
      if (!((v2slot_name)==(T0))) { goto L19; }
      v7slotd = v10;
      goto L12;
     }
L19:;
     v9 = si_seq_iterator_next(v8, v9);
     goto L15;
    }
L12:;
    if (Null(v7slotd)) { goto L24; }
    value0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-VALUE-USING-CLASS",1553))(3, v3class, v1self, v7slotd) /*  SLOT-VALUE-USING-CLASS */;
    return value0;
L24:;
    value0 = (cl_env_copy->function=(ECL_SYM("SLOT-MISSING",969)->symbol.gfdef))->cfun.entry(4, v3class, v1self, v2slot_name, ECL_SYM("SLOT-VALUE",971)) /*  SLOT-MISSING */;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for SLOT-EXISTS-P                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_slot_exists_p(cl_object v1self, cl_object v2slot_name)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_class_of(v1self);
  if (Null(clos_find_slot_definition(2, T0, v2slot_name))) { goto L2; }
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for SLOT-BOUNDP                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_slot_boundp(cl_object v1self, cl_object v2slot_name)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3class;
   cl_object v4location_table;
   v3class = cl_class_of(v1self);
   v4location_table = ecl_instance_ref((v3class),(19));
   if (Null(v4location_table)) { goto L3; }
   {
    cl_object v5location;
    v5location = ecl_gethash_safe(v2slot_name,v4location_table,ECL_NIL);
    if (Null(v5location)) { goto L6; }
    T0 = clos_standard_instance_get(v1self, v5location);
    value0 = ecl_make_bool((T0)!=ECL_UNBOUND);
    cl_env_copy->nvalues = 1;
    return value0;
L6:;
    value0 = (cl_env_copy->function=(ECL_SYM("SLOT-MISSING",969)->symbol.gfdef))->cfun.entry(4, v3class, v1self, v2slot_name, ECL_SYM("SLOT-BOUNDP",966)) /*  SLOT-MISSING */;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L3:;
   {
    cl_object v6slotd;
    {
     cl_object v7;
     cl_object v8;
     v7 = ecl_instance_ref((v3class),(6));
     v8 = si_make_seq_iterator(2, v7, ecl_make_fixnum(0));
L12:;
     if ((v8)!=ECL_NIL) { goto L14; }
     v6slotd = ECL_NIL;
     goto L9;
L14:;
     {
      cl_object v9;
      v9 = si_seq_iterator_ref(v7, v8);
      T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v9) /*  SLOT-DEFINITION-NAME */;
      if (!((v2slot_name)==(T0))) { goto L16; }
      v6slotd = v9;
      goto L9;
     }
L16:;
     v8 = si_seq_iterator_next(v7, v8);
     goto L12;
    }
L9:;
    if (Null(v6slotd)) { goto L21; }
    value0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-BOUNDP-USING-CLASS",1541))(3, v3class, v1self, v6slotd) /*  SLOT-BOUNDP-USING-CLASS */;
    return value0;
L21:;
    value0 = (cl_env_copy->function=(ECL_SYM("SLOT-MISSING",969)->symbol.gfdef))->cfun.entry(4, v3class, v1self, v2slot_name, ECL_SYM("SLOT-BOUNDP",966)) /*  SLOT-MISSING */;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for SLOT-VALUE-SET                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object clos_slot_value_set(cl_object v1value, cl_object v2self, cl_object v3slot_name)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4class;
   cl_object v5location_table;
   v4class = cl_class_of(v2self);
   v5location_table = ecl_instance_ref((v4class),(19));
   if (Null(v5location_table)) { goto L4; }
   {
    cl_object v6location;
    v6location = ecl_gethash_safe(v3slot_name,v5location_table,ECL_NIL);
    if (Null(v6location)) { goto L7; }
    clos_standard_instance_set(v1value, v2self, v6location);
    goto L1;
L7:;
    (cl_env_copy->function=(ECL_SYM("SLOT-MISSING",969)->symbol.gfdef))->cfun.entry(5, v4class, v2self, v3slot_name, ECL_SYM("SETF",750), v1value) /*  SLOT-MISSING */;
    goto L1;
   }
L4:;
   {
    cl_object v7slotd;
    {
     cl_object v8;
     cl_object v9;
     v8 = ecl_instance_ref((v4class),(6));
     v9 = si_make_seq_iterator(2, v8, ecl_make_fixnum(0));
L12:;
     if ((v9)!=ECL_NIL) { goto L14; }
     v7slotd = ECL_NIL;
     goto L9;
L14:;
     {
      cl_object v10;
      v10 = si_seq_iterator_ref(v8, v9);
      T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v10) /*  SLOT-DEFINITION-NAME */;
      if (!((v3slot_name)==(T0))) { goto L16; }
      v7slotd = v10;
      goto L9;
     }
L16:;
     v9 = si_seq_iterator_next(v8, v9);
     goto L12;
    }
L9:;
    if (Null(v7slotd)) { goto L21; }
    (cl_env_copy->function=ECL_CONS_CAR(VV[14]))->cfun.entry(4, v1value, v4class, v2self, v7slotd) /*  (SETF SLOT-VALUE-USING-CLASS) */;
    goto L1;
L21:;
    (cl_env_copy->function=(ECL_SYM("SLOT-MISSING",969)->symbol.gfdef))->cfun.entry(5, v4class, v2self, v3slot_name, ECL_SYM("SETF",750), v1value) /*  SLOT-MISSING */;
   }
  }
L1:;
  value0 = v1value;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for INVALID-SLOT-LOCATION                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4invalid_slot_location(cl_object v1instance, cl_object v2location)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_class_of(v2location);
  value0 = cl_error(3, _ecl_static_1, v2location, T0);
  return value0;
 }
}

#include "clos/std-slot-value.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclVbD23ia7_Oe8xWE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CLOS;STD-SLOT-VALUE.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclVbD23ia7_Oe8xWE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defmacro(VV[7]);                         /*  WITH-SLOTS      */
 ecl_cmp_defun(VV[8]);                            /*  STD-CREATE-SLOTS-TABLE */
 ecl_cmp_defun(VV[10]);                           /*  FIND-SLOT-DEFINITION */
 ecl_cmp_defun(VV[11]);                           /*  UPDATE-INSTANCE */
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[0]) /*  MAPC */;
 ecl_cmp_defun(VV[12]);                           /*  STANDARD-INSTANCE-GET */
 ecl_cmp_defun(VV[13]);                           /*  STANDARD-INSTANCE-SET */
 (void)0; /* No entry created for SLOT-VALUE */
 (void)0; /* No entry created for SLOT-EXISTS-P */
 (void)0; /* No entry created for SLOT-BOUNDP */
 (void)0; /* No entry created for SLOT-VALUE-SET */
 {
  cl_object T0;
 T0 = (ECL_SYM("SLOT-VALUE-SET",1554)->symbol.gfdef);
 si_fset(4, VVtemp[1], T0, ECL_NIL, ECL_NIL);
 }
 (void)0; /* No entry created for INVALID-SLOT-LOCATION */
}
