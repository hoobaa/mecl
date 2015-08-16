/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CLOS;SLOTVALUE.LSP                                */
#include <ecl/ecl-cmp.h>
#include "clos/slotvalue.eclh"
/*	local function G6                                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC1__g6(cl_object v1class)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((cl_slot_boundp(v1class, VV[0]))!=ECL_NIL) { goto L1; }
  {
   cl_object v2;
   v2 = (cl_env_copy->function=(ECL_SYM("ALLOCATE-INSTANCE",927)->symbol.gfdef))->cfun.entry(1, v1class) /*  ALLOCATE-INSTANCE */;
   (cl_env_copy->function=ECL_CONS_CAR(VV[2]))->cfun.entry(3, v2, v1class, VV[0]) /*  (SETF SLOT-VALUE) */;
  }
L1:;
  value0 = cl_slot_value(v1class, VV[0]);
  return value0;
 }
}
/*	function definition for SLOT-MAKUNBOUND                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_slot_makunbound(cl_object v1self, cl_object v2slot_name)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3class;
   cl_object v4slotd;
   v3class = cl_class_of(v1self);
   v4slotd = clos_find_slot_definition(2, v3class, v2slot_name);
   if (Null(v4slotd)) { goto L4; }
   ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-MAKUNBOUND-USING-CLASS",1552))(3, v3class, v1self, v4slotd) /*  SLOT-MAKUNBOUND-USING-CLASS */;
   goto L3;
L4:;
   (cl_env_copy->function=(ECL_SYM("SLOT-MISSING",969)->symbol.gfdef))->cfun.entry(4, v3class, v1self, v2slot_name, ECL_SYM("SLOT-MAKUNBOUND",968)) /*  SLOT-MISSING */;
L3:;
   value0 = v1self;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G10                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC2__g10(cl_object v1class, cl_object v2self, cl_object v3slotd)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4location;
   cl_object v5value;
   v4location = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-LOCATION",1547))(1, v3slotd) /*  SLOT-DEFINITION-LOCATION */;
   v5value = clos_standard_instance_get(v2self, v4location);
   if (!((v5value)!=ECL_UNBOUND)) { goto L3; }
   value0 = v5value;
   cl_env_copy->nvalues = 1;
   return value0;
L3:;
   T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v3slotd) /*  SLOT-DEFINITION-NAME */;
   value0 = (cl_env_copy->function=(ECL_SYM("SLOT-UNBOUND",970)->symbol.gfdef))->cfun.entry(3, v1class, v2self, T0) /*  SLOT-UNBOUND */;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G11                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC3__g11(cl_object v1class, cl_object v2self, cl_object v3slotd)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-LOCATION",1547))(1, v3slotd) /*  SLOT-DEFINITION-LOCATION */;
  T1 = clos_standard_instance_get(v2self, T0);
  value0 = ecl_make_bool((T1)!=ECL_UNBOUND);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G12                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC4__g12(cl_object v1val, cl_object v2class, cl_object v3self, cl_object v4slotd)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-LOCATION",1547))(1, v4slotd) /*  SLOT-DEFINITION-LOCATION */;
  value0 = clos_standard_instance_set(v1val, v3self, T0);
  return value0;
 }
}
/*	local function G13                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC5__g13(cl_object v1class, cl_object v2instance, cl_object v3slotd)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ECL_UNBOUND;
  T1 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-LOCATION",1547))(1, v3slotd) /*  SLOT-DEFINITION-LOCATION */;
  value0 = clos_standard_instance_set(T0, v2instance, T1);
  return value0;
 }
}
/*	local function G14                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC6__g14(cl_narg narg, cl_object v1class, cl_object v2object, cl_object v3slot_name, cl_object v4operation, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<4)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>5)) FEwrong_num_arguments_anonym();
 {
  cl_object v5new_value;
  va_list args; va_start(args,v4operation);
  {
   int i = 4;
   if (i >= narg) {
    v5new_value = ECL_NIL;
   } else {
    i++;
    v5new_value = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = cl_error(3, _ecl_static_1, v3slot_name, v2object);
  return value0;
 }
}
/*	local function G15                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC7__g15(cl_object v1class, cl_object v2object, cl_object v3slot_name)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_error(5, ECL_SYM("UNBOUND-SLOT",876), ECL_SYM("INSTANCE",1256), v2object, ECL_SYM("NAME",1273), v3slot_name);
  return value0;
 }
}
/*	local function G16                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC8__g16(cl_object v1class, cl_object v2object, cl_object v3slot_index)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4class;
   cl_object v5slotd;
   v4class = cl_class_of(v2object);
   {
    cl_object v6;
    cl_object v7;
    v6 = cl_slot_value(v4class, VV[1]);
    v7 = si_make_seq_iterator(2, v6, ecl_make_fixnum(0));
L5:;
    if ((v7)!=ECL_NIL) { goto L7; }
    v5slotd = ECL_NIL;
    goto L2;
L7:;
    {
     cl_object v8;
     v8 = si_seq_iterator_ref(v6, v7);
     T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-LOCATION",1547))(1, v8) /*  SLOT-DEFINITION-LOCATION */;
     if (!(ecl_eql(v3slot_index,T0))) { goto L9; }
     v5slotd = v8;
     goto L2;
    }
L9:;
    v7 = si_seq_iterator_next(v6, v7);
    goto L5;
   }
L2:;
   T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v5slotd) /*  SLOT-DEFINITION-NAME */;
   value0 = (cl_env_copy->function=(ECL_SYM("SLOT-UNBOUND",970)->symbol.gfdef))->cfun.entry(3, v4class, v2object, T0) /*  SLOT-UNBOUND */;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G25                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC9__g25(cl_object v1class)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[3])(1, v1class) /*  CLASS-ID */;
  return value0;
 }
}
/*	local function G26                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC10__g26(cl_object v1new_value, cl_object v2class)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  (cl_env_copy->function=(ECL_SYM("REINITIALIZE-INSTANCE",963)->symbol.gfdef))->cfun.entry(3, v2class, ECL_SYM("NAME",1273), v1new_value) /*  REINITIALIZE-INSTANCE */;
  value0 = v1new_value;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}

#include "clos/slotvalue.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecl96jATW7JtXNj9_e1Q5hE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CLOS;SLOTVALUE.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_ecl96jATW7JtXNj9_e1Q5hE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC1__g6,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("CLASS-PROTOTYPE",1493), ECL_NIL, VVtemp[0], VVtemp[0], T0, ECL_T);
 }
 (void)0; /* No entry created for SLOT-MAKUNBOUND */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC2__g10,ECL_NIL,Cblock,3);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("SLOT-VALUE-USING-CLASS",1553), ECL_NIL, VVtemp[1], VVtemp[2], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC3__g11,ECL_NIL,Cblock,3);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("SLOT-BOUNDP-USING-CLASS",1541), ECL_NIL, VVtemp[1], VVtemp[2], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC4__g12,ECL_NIL,Cblock,4);
  T0 = v1;
 }
 clos_install_method(6, VVtemp[3], ECL_NIL, VVtemp[4], VVtemp[5], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC5__g13,ECL_NIL,Cblock,3);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("SLOT-MAKUNBOUND-USING-CLASS",1552), ECL_NIL, VVtemp[1], VVtemp[6], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC6__g14,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("SLOT-MISSING",969), ECL_NIL, VVtemp[7], VVtemp[8], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC7__g15,ECL_NIL,Cblock,3);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("SLOT-UNBOUND",970), ECL_NIL, VVtemp[9], VVtemp[10], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC8__g16,ECL_NIL,Cblock,3);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("SLOT-UNBOUND",970), ECL_NIL, VVtemp[11], VVtemp[12], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC9__g25,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("CLASS-NAME",934), ECL_NIL, VVtemp[0], VVtemp[0], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC10__g26,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VVtemp[13], ECL_NIL, VVtemp[14], VVtemp[15], T0, ECL_T);
 }
}
