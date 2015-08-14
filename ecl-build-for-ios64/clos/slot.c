/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CLOS;SLOT.LSP                                     */
#include <ecl/ecl-cmp.h>
#include "clos/slot.eclh"
/*	function definition for MAKE-SIMPLE-SLOTD                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1make_simple_slotd(cl_narg narg, cl_object v1class, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2name;
  cl_object v3initform;
  cl_object v4initfunction;
  cl_object v5type;
  cl_object v6allocation;
  cl_object v7initargs;
  cl_object v8readers;
  cl_object v9writers;
  cl_object v10documentation;
  cl_object v11location;
  ecl_va_list args; ecl_va_start(args,v1class,narg,1);
  {
   cl_object keyvars[20];
   cl_parse_key(args,10,L1make_simple_slotdkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v2name = keyvars[0];
   if (Null(keyvars[11])) {
    v3initform = ecl_symbol_value(VV[0]);
   } else {
    v3initform = keyvars[1];
   }
   v4initfunction = keyvars[2];
   if (Null(keyvars[13])) {
    v5type = ECL_T;
   } else {
    v5type = keyvars[3];
   }
   if (Null(keyvars[14])) {
    v6allocation = ECL_SYM("INSTANCE",1256);
   } else {
    v6allocation = keyvars[4];
   }
   v7initargs = keyvars[5];
   v8readers = keyvars[6];
   v9writers = keyvars[7];
   v10documentation = keyvars[8];
   v11location = keyvars[9];
  }
  if (!((v6allocation)==(VV[1]))) { goto L4; }
  if (Null(cl_functionp(v4initfunction))) { goto L4; }
  T0 = ecl_function_dispatch(cl_env_copy,v4initfunction)(0);
  v4initfunction = cl_constantly(T0);
L4:;
  {
   cl_object v12slotd;
   v12slotd = si_allocate_raw_instance(ECL_NIL, v1class, ecl_make_fixnum(10));
   si_instance_set(v12slotd, ecl_make_fixnum(0), v2name);
   si_instance_set(v12slotd, ecl_make_fixnum(1), v3initform);
   if (!(ECL_LISTP(v4initfunction))) { goto L14; }
   T0 = cl_eval(v4initfunction);
   goto L13;
L14:;
   T0 = v4initfunction;
L13:;
   si_instance_set(v12slotd, ecl_make_fixnum(2), T0);
   si_instance_set(v12slotd, ecl_make_fixnum(3), v5type);
   si_instance_set(v12slotd, ecl_make_fixnum(4), v6allocation);
   si_instance_set(v12slotd, ecl_make_fixnum(5), v7initargs);
   si_instance_set(v12slotd, ecl_make_fixnum(6), v8readers);
   si_instance_set(v12slotd, ecl_make_fixnum(7), v9writers);
   si_instance_set(v12slotd, ecl_make_fixnum(8), v10documentation);
   si_instance_set(v12slotd, ecl_make_fixnum(9), v11location);
   if (Null(v1class)) { goto L23; }
   si_instance_sig_set(v12slotd);
L23:;
   value0 = v12slotd;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for FREEZE-CLASS-SLOT-INITFUNCTION        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2freeze_class_slot_initfunction(cl_object v1slotd)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_getf(2, v1slotd, ECL_SYM("ALLOCATION",985));
  if (!((T0)==(VV[1]))) { goto L1; }
  {
   cl_object v2initfunc;
   v2initfunc = cl_getf(2, v1slotd, ECL_SYM("INITFUNCTION",997));
   if (Null(v2initfunc)) { goto L1; }
   {
    cl_object v3;
    T0 = ecl_function_dispatch(cl_env_copy,v2initfunc)(0);
    v3 = cl_constantly(T0);
    {
     cl_object v4;
     v4 = si_put_f(v1slotd, v3, ECL_SYM("INITFUNCTION",997));
     v1slotd = v4;
    }
   }
  }
L1:;
  value0 = v1slotd;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for CANONICAL-SLOT-TO-DIRECT-SLOT         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3canonical_slot_to_direct_slot(cl_object v1class, cl_object v2slotd)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  v2slotd = L2freeze_class_slot_initfunction(v2slotd);
  if (Null(cl_find_class(2, ECL_SYM("SLOT-DEFINITION",1542), ECL_NIL))) { goto L3; }
  T0 = (ECL_SYM("MAKE-INSTANCE",949)->symbol.gfdef);
  T1 = (ECL_SYM("DIRECT-SLOT-DEFINITION-CLASS",1503)->symbol.gfdef);
  T2 = L2freeze_class_slot_initfunction(v2slotd);
  T3 = cl_apply(3, T1, v1class, T2);
  value0 = cl_apply(3, T0, T3, v2slotd);
  return value0;
L3:;
  T0 = (VV[2]->symbol.gfdef);
  value0 = cl_apply(3, T0, v1class, v2slotd);
  return value0;
 }
}
/*	function definition for DIRECT-SLOT-TO-CANONICAL-SLOT         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4direct_slot_to_canonical_slot(cl_object v1slotd)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v1slotd) /*  SLOT-DEFINITION-NAME */;
  T1 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-INITFORM",1545))(1, v1slotd) /*  SLOT-DEFINITION-INITFORM */;
  T2 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-INITFUNCTION",1546))(1, v1slotd) /*  SLOT-DEFINITION-INITFUNCTION */;
  T3 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-TYPE",1550))(1, v1slotd) /*  SLOT-DEFINITION-TYPE */;
  T4 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-ALLOCATION",1543))(1, v1slotd) /*  SLOT-DEFINITION-ALLOCATION */;
  T5 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-INITARGS",1544))(1, v1slotd) /*  SLOT-DEFINITION-INITARGS */;
  T6 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-READERS",1549))(1, v1slotd) /*  SLOT-DEFINITION-READERS */;
  T7 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-WRITERS",1551))(1, v1slotd) /*  SLOT-DEFINITION-WRITERS */;
  T8 = ecl_function_dispatch(cl_env_copy,VV[26])(1, v1slotd) /*  SLOT-DEFINITION-DOCUMENTATION */;
  T9 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-LOCATION",1547))(1, v1slotd) /*  SLOT-DEFINITION-LOCATION */;
  value0 = cl_list(20, ECL_SYM("NAME",1273), T0, ECL_SYM("INITFORM",996), T1, ECL_SYM("INITFUNCTION",997), T2, ECL_SYM("TYPE",1318), T3, ECL_SYM("ALLOCATION",985), T4, ECL_SYM("INITARGS",995), T5, ECL_SYM("READERS",1007), T6, ECL_SYM("WRITERS",1010), T7, ECL_SYM("DOCUMENTATION",1222), T8, ECL_SYM("LOCATION",999), T9);
  return value0;
 }
}
/*	function definition for MAKE-FUNCTION-INITFORM                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5make_function_initform(cl_object v1form)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_constantp(1, v1form))) { goto L1; }
  value0 = cl_list(2, ECL_SYM("CONSTANTLY",253), v1form);
  return value0;
L1:;
  T0 = cl_list(3, ECL_SYM("LAMBDA",452), ECL_NIL, v1form);
  value0 = cl_list(2, ECL_SYM("FUNCTION",396), T0);
  return value0;
 }
}
/*	function definition for PARSE-SLOT                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6parse_slot(cl_narg narg, cl_object v1slot, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2full;
  va_list args; va_start(args,v1slot);
  {
   int i = 1;
   if (i >= narg) {
    v2full = ECL_NIL;
   } else {
    i++;
    v2full = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (!(ECL_SYMBOLP(v1slot))) { goto L2; }
  if (Null(v2full)) { goto L5; }
  T0 = cl_list(16, ECL_SYM("INITFORM",996), VV[0], ECL_SYM("INITFUNCTION",997), ECL_NIL, ECL_SYM("INITARGS",995), ECL_NIL, ECL_SYM("READERS",1007), ECL_NIL, ECL_SYM("WRITERS",1010), ECL_NIL, ECL_SYM("ALLOCATION",985), ECL_SYM("INSTANCE",1256), ECL_SYM("DOCUMENTATION",1222), ECL_NIL, ECL_SYM("TYPE",1318), ECL_T);
  goto L4;
L5:;
  T0 = ECL_NIL;
L4:;
  value0 = cl_listX(3, ECL_SYM("NAME",1273), v1slot, T0);
  return value0;
L2:;
  {
   cl_object v3output;
   cl_object v4options;
   cl_object v5extra;
   T0 = ecl_car(v1slot);
   v3output = L6parse_slot(2, T0, v2full);
   v4options = ecl_cdr(v1slot);
   v5extra = ECL_NIL;
   goto L12;
L11:;
   {
    cl_object v6option;
    {
     cl_object v7;
     v7 = v4options;
     if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
     if (Null(v7)) { goto L19; }
     {
      cl_object v8;
      v8 = ECL_CONS_CDR(v7);
      v4options = v8;
      v7 = ECL_CONS_CAR(v7);
     }
L19:;
     v6option = v7;
    }
    if (!(ecl_endp(v4options))) { goto L25; }
    si_simple_program_error(3, _ecl_static_1, v1slot, v6option);
L25:;
    {
     cl_object v7value;
     {
      cl_object v8;
      v8 = v4options;
      if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
      if (Null(v8)) { goto L31; }
      {
       cl_object v9;
       v9 = ECL_CONS_CDR(v8);
       v4options = v9;
       v8 = ECL_CONS_CAR(v8);
      }
L31:;
      v7value = v8;
     }
     if (!(ecl_eql(v6option,ECL_SYM("ALLOCATION",985)))) { goto L43; }
     goto L40;
     goto L41;
L43:;
     goto L41;
L41:;
     if (!(ecl_eql(v6option,ECL_SYM("INITFORM",996)))) { goto L47; }
     goto L40;
     goto L45;
L47:;
     goto L45;
L45:;
     if (!(ecl_eql(v6option,ECL_SYM("TYPE",1318)))) { goto L51; }
     goto L40;
     goto L49;
L51:;
     goto L49;
L49:;
     if (!(ecl_eql(v6option,ECL_SYM("DOCUMENTATION",1222)))) { goto L37; }
     goto L39;
L40:;
L39:;
     if (Null(cl_getf(2, v4options, v6option))) { goto L37; }
     si_simple_program_error(3, _ecl_static_2, v1slot, v6option);
L37:;
     if (!(ecl_eql(v6option,ECL_SYM("INITARG",994)))) { goto L54; }
     {
      cl_object v8;
      T0 = cl_getf(3, v3output, ECL_SYM("INITARGS",995), ECL_NIL);
      v8 = CONS(v7value,T0);
      {
       cl_object v9;
       v9 = si_put_f(v3output, v8, ECL_SYM("INITARGS",995));
       v3output = v9;
       goto L14;
      }
     }
L54:;
     if (!(ecl_eql(v6option,ECL_SYM("INITFORM",996)))) { goto L60; }
     {
      cl_object v10;
      v10 = si_put_f(v3output, v7value, ECL_SYM("INITFORM",996));
      v3output = v10;
     }
     {
      cl_object v10;
      v10 = L5make_function_initform(v7value);
      {
       cl_object v11;
       v11 = si_put_f(v3output, v10, ECL_SYM("INITFUNCTION",997));
       v3output = v11;
       goto L14;
      }
     }
L60:;
     if (!(ecl_eql(v6option,ECL_SYM("ACCESSOR",983)))) { goto L70; }
     {
      cl_object v12;
      T0 = cl_getf(3, v3output, ECL_SYM("READERS",1007), ECL_NIL);
      v12 = CONS(v7value,T0);
      {
       cl_object v13;
       v13 = si_put_f(v3output, v12, ECL_SYM("READERS",1007));
       v3output = v13;
      }
     }
     {
      cl_object v12;
      cl_object v13;
      v12 = cl_list(2, ECL_SYM("SETF",750), v7value);
      T0 = cl_getf(3, v3output, ECL_SYM("WRITERS",1010), ECL_NIL);
      v13 = CONS(v12,T0);
      {
       cl_object v14;
       v14 = si_put_f(v3output, v13, ECL_SYM("WRITERS",1010));
       v3output = v14;
       goto L14;
      }
     }
L70:;
     if (!(ecl_eql(v6option,ECL_SYM("READER",1006)))) { goto L82; }
     {
      cl_object v15;
      T0 = cl_getf(3, v3output, ECL_SYM("READERS",1007), ECL_NIL);
      v15 = CONS(v7value,T0);
      {
       cl_object v16;
       v16 = si_put_f(v3output, v15, ECL_SYM("READERS",1007));
       v3output = v16;
       goto L14;
      }
     }
L82:;
     if (!(ecl_eql(v6option,ECL_SYM("WRITER",1009)))) { goto L88; }
     {
      cl_object v17;
      T0 = cl_getf(3, v3output, ECL_SYM("WRITERS",1010), ECL_NIL);
      v17 = CONS(v7value,T0);
      {
       cl_object v18;
       v18 = si_put_f(v3output, v17, ECL_SYM("WRITERS",1010));
       v3output = v18;
       goto L14;
      }
     }
L88:;
     if (!(ecl_eql(v6option,ECL_SYM("ALLOCATION",985)))) { goto L94; }
     {
      cl_object v19;
      v19 = si_put_f(v3output, v7value, ECL_SYM("ALLOCATION",985));
      v3output = v19;
      goto L14;
     }
L94:;
     if (!(ecl_eql(v6option,ECL_SYM("TYPE",1318)))) { goto L99; }
     {
      cl_object v20;
      v20 = si_put_f(v3output, v7value, ECL_SYM("TYPE",1318));
      v3output = v20;
      goto L14;
     }
L99:;
     if (!(ecl_eql(v6option,ECL_SYM("DOCUMENTATION",1222)))) { goto L104; }
     {
      cl_object v21;
      T0 = cl_getf(3, v3output, ECL_SYM("DOCUMENTATION",1222), ECL_NIL);
      v21 = CONS(v7value,T0);
      {
       cl_object v22;
       v22 = si_put_f(v3output, v21, ECL_SYM("DOCUMENTATION",1222));
       v3output = v22;
       goto L14;
      }
     }
L104:;
     if ((cl_getf(2, v5extra, v6option))!=ECL_NIL) { goto L112; }
     if (Null(cl_getf(2, v4options, v6option))) { goto L110; }
     goto L111;
L112:;
L111:;
     {
      cl_object v23;
      T0 = cl_getf(3, v5extra, v6option, ECL_NIL);
      v23 = CONS(v7value,T0);
      {
       cl_object v24;
       v24 = si_put_f(v5extra, v23, v6option);
       v5extra = v24;
       goto L14;
      }
     }
L110:;
     {
      cl_object v25;
      v25 = si_put_f(v5extra, v7value, v6option);
      v5extra = v25;
     }
    }
   }
L14:;
L12:;
   if (v4options==ECL_NIL) { goto L121; }
   goto L11;
L121:;
   value0 = ecl_nconc(v3output,v5extra);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for PARSE-SLOTS                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7parse_slots(cl_object v1slots)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2scan;
   cl_object v3collect;
   v2scan = v1slots;
   v3collect = ECL_NIL;
   goto L5;
L4:;
   {
    cl_object v4slotd;
    cl_object v5name;
    T0 = ecl_car(v2scan);
    v4slotd = L6parse_slot(1, T0);
    v5name = cl_getf(2, v4slotd, ECL_SYM("NAME",1273));
    {
     cl_object v6;
     v6 = v3collect;
     goto L14;
L13:;
     {
      cl_object v7other_slotd;
      v7other_slotd = ecl_car(v6);
      T0 = cl_getf(2, v7other_slotd, ECL_SYM("NAME",1273));
      if (!((v5name)==(T0))) { goto L18; }
      si_simple_program_error(2, _ecl_static_3, v5name);
L18:;
     }
     v6 = ecl_cdr(v6);
L14:;
     if (Null(v6)) { goto L22; }
     goto L13;
L22:;
    }
    v3collect = CONS(v4slotd,v3collect);
   }
   v2scan = ecl_cdr(v2scan);
L5:;
   if (v2scan==ECL_NIL) { goto L27; }
   goto L4;
L27:;
   value0 = cl_nreverse(v3collect);
   return value0;
  }
 }
}

#include "clos/slot.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclVvInhbb7_tg8xWE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CLOS;SLOT.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclVvInhbb7_tg8xWE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 si_Xmake_constant(VV[0], VV[0]);
 ecl_cmp_defun(VV[12]);                           /*  MAKE-SIMPLE-SLOTD */
 ecl_cmp_defun(VV[23]);                           /*  FREEZE-CLASS-SLOT-INITFUNCTION */
 ecl_cmp_defun(VV[24]);                           /*  CANONICAL-SLOT-TO-DIRECT-SLOT */
 ecl_cmp_defun(VV[25]);                           /*  DIRECT-SLOT-TO-CANONICAL-SLOT */
 ecl_cmp_defun(VV[27]);                           /*  MAKE-FUNCTION-INITFORM */
 (void)0; /* No entry created for PARSE-SLOT */
 ecl_cmp_defun(VV[28]);                           /*  PARSE-SLOTS     */
}
