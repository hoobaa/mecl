/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CLOS;BUILTIN.LSP                                  */
#include <ecl/ecl-cmp.h>
#include "clos/builtin.eclh"
/*	local function G0                                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC1__g0(cl_narg narg, cl_object v1class, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  value0 = cl_error(2, _ecl_static_1, v1class);
  return value0;
 }
}
/*	local function G7                                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC2__g7(cl_narg narg, cl_object v1class, cl_object v2name, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3rest;
  ecl_va_list args; ecl_va_start(args,v2name,narg,2);
  v3rest = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v5;                                  /*  METACLASS       */
   cl_object v6;                                  /*  OPTIONS         */
   T0 = (VV[2]->symbol.gfdef);
   value0 = cl_apply(2, T0, v3rest);
   v5 = value0;
   {
    const int v7 = cl_env_copy->nvalues;
    cl_object v8;
    v8 = (v7<=2)? ECL_NIL : cl_env_copy->values[2];
    v6 = v8;
   }
   T0 = (ECL_SYM("MAKE-INSTANCE",949)->symbol.gfdef);
   v1class = cl_apply(5, T0, v5, ECL_SYM("NAME",1273), v2name, v6);
   if (Null(v2name)) { goto L6; }
   ecl_function_dispatch(cl_env_copy,ECL_SYM("CREATE-TYPE-NAME",1585))(1, v2name) /*  CREATE-TYPE-NAME */;
   value0 = ecl_function_dispatch(cl_env_copy,VV[3])(2, v1class, v2name) /*  SETF-FIND-CLASS */;
   return value0;
L6:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G11                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC3__g11(cl_narg narg, cl_object v1instance, cl_object v2new_class, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3initargs;
  ecl_va_list args; ecl_va_start(args,v2new_class,narg,2);
  v3initargs = cl_grab_rest_args(args);
  ecl_va_end(args);
  T0 = (ECL_SYM("CHANGE-CLASS",932)->symbol.gfdef);
  T1 = cl_find_class(1, v2new_class);
  value0 = cl_apply(4, T0, v1instance, T1, v3initargs);
  return value0;
 }
}
/*	local function G12                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC4__g12(cl_object v1class)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_find_class(1, v1class);
  (cl_env_copy->function=(ECL_SYM("MAKE-INSTANCES-OBSOLETE",950)->symbol.gfdef))->cfun.entry(1, T0) /*  MAKE-INSTANCES-OBSOLETE */;
  value0 = v1class;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G13                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC5__g13(cl_narg narg, cl_object v1class_name, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2initargs;
  ecl_va_list args; ecl_va_start(args,v1class_name,narg,1);
  v2initargs = cl_grab_rest_args(args);
  ecl_va_end(args);
  T0 = (ECL_SYM("MAKE-INSTANCE",949)->symbol.gfdef);
  T1 = cl_find_class(1, v1class_name);
  value0 = cl_apply(3, T0, T1, v2initargs);
  return value0;
 }
}
/*	local function G14                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC6__g14(cl_object v1class, cl_object v2self, cl_object v3slotd)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_error(1, _ecl_static_2);
  return value0;
 }
}
/*	local function G15                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC7__g15(cl_object v1class, cl_object v2self, cl_object v3slotd)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_error(1, _ecl_static_3);
  return value0;
 }
}
/*	local function G16                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC8__g16(cl_object v1class, cl_object v2self, cl_object v3slotd)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_error(1, _ecl_static_4);
  return value0;
 }
}
/*	local function G17                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC9__g17(cl_object v1val, cl_object v2class, cl_object v3self, cl_object v4slotd)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_error(1, _ecl_static_4);
  return value0;
 }
}
/*	local function G18                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC10__g18(cl_object v1class, cl_object v2self, cl_object v3slotd)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G19                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC11__g19(cl_narg narg, cl_object v1class, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  value0 = cl_error(2, _ecl_static_5, v1class);
  return value0;
 }
}
/*	local function G20                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC12__g20(cl_object v1class)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)))) { goto L2; }
  T0 = ecl_car(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
  T1 = ecl_cdr(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
  ecl_function_dispatch(cl_env_copy,T0)(2, ecl_symbol_value(ECL_SYM(".COMBINED-METHOD-ARGS.",1473)), T1);
  goto L1;
L2:;
  cl_error(1, _ecl_static_6);
L1:;
  {
   cl_object v2;
   v2 = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-SLOTS",1494))(1, v1class) /*  CLASS-SLOTS */;
   goto L8;
L7:;
   {
    cl_object v3slot;
    v3slot = ecl_car(v2);
    T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-ALLOCATION",1543))(1, v3slot) /*  SLOT-DEFINITION-ALLOCATION */;
    if ((ECL_SYM("INSTANCE",1256))==(T0)) { goto L12; }
    T0 = (cl_env_copy->function=(ECL_SYM("CLASS-NAME",934)->symbol.gfdef))->cfun.entry(1, v1class) /*  CLASS-NAME */;
    cl_error(2, _ecl_static_7, T0);
L12:;
   }
   v2 = ecl_cdr(v2);
L8:;
   if (Null(v2)) { goto L16; }
   goto L7;
L16:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G24                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC13__g24(cl_narg narg, cl_object v1object, ...)
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
  value0 = (cl_env_copy->function=(ECL_SYM("MAKE-LOAD-FORM-SAVING-SLOTS",952)->symbol.gfdef))->cfun.entry(3, v1object, ECL_SYM("KEY",1262), v2environment) /*  MAKE-LOAD-FORM-SAVING-SLOTS */;
  return value0;
 }
}
/*	local function G25                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC14__g25(cl_object v1obj, cl_object v2stream)
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
   if (Null(v4slotds)) { goto L3; }
   if ((ecl_symbol_value(ECL_SYM("*PRINT-READABLY*",57)))!=ECL_NIL) { goto L3; }
   if (Null(ecl_symbol_value(ECL_SYM("*PRINT-LEVEL*",51)))) { goto L3; }
   if (!(ecl_zerop(ecl_symbol_value(ECL_SYM("*PRINT-LEVEL*",51))))) { goto L3; }
   cl_write_string(2, _ecl_static_8, v2stream);
   value0 = v1obj;
   cl_env_copy->nvalues = 1;
   return value0;
L3:;
   cl_write_string(2, _ecl_static_9, v2stream);
   T0 = (cl_env_copy->function=(ECL_SYM("CLASS-NAME",934)->symbol.gfdef))->cfun.entry(1, v3class) /*  CLASS-NAME */;
   ecl_prin1(T0,v2stream);
   {
    cl_object v5;
    cl_object v6scan;
    cl_fixnum v7i;
    cl_object v8sv;
    value0 = ecl_symbol_value(ECL_SYM("*PRINT-LENGTH*",50));
    if ((value0)!=ECL_NIL) { goto L14; }
    v5 = ecl_make_fixnum(2305843009213693951);
    goto L12;
L14:;
    v5 = value0;
    goto L12;
L12:;
    v6scan = v4slotds;
    v7i = 0;
    v8sv = ECL_NIL;
    goto L21;
L20:;
    if (!(ecl_number_compare(ecl_make_fixnum(v7i),v5)>=0)) { goto L23; }
    cl_write_string(2, _ecl_static_10, v2stream);
    goto L11;
L23:;
    v8sv = ecl_instance_ref((v1obj),(v7i));
    cl_write_string(2, _ecl_static_11, v2stream);
    T0 = ecl_car(v6scan);
    T1 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, T0) /*  SLOT-DEFINITION-NAME */;
    ecl_prin1(T1,v2stream);
    cl_write_string(2, _ecl_static_12, v2stream);
    ecl_prin1(v8sv,v2stream);
    v6scan = ecl_cdr(v6scan);
    {
     cl_object v9;
     v9 = ecl_make_integer((v7i)+1);
     {
      bool v10;
      v10 = ECL_FIXNUMP(v9);
      if (ecl_unlikely(!(v10)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v9);
     }
     v7i = ecl_fixnum(v9);
    }
L21:;
    if (v6scan==ECL_NIL) { goto L37; }
    goto L20;
L37:;
   }
L11:;
   cl_write_string(2, _ecl_static_13, v2stream);
   value0 = v1obj;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}

#include "clos/builtin.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclENZkQW83YBXs9_QRz9ZE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CLOS;BUILTIN.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclENZkQW83YBXs9_QRz9ZE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC1__g0,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("MAKE-INSTANCE",949), ECL_NIL, VVtemp[0], VVtemp[1], T0, ECL_T);
 }
 si_Xmake_constant(ECL_SYM("+BUILTIN-CLASSES+",1474), ecl_symbol_value(VV[0]));
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC2__g7,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("ENSURE-CLASS-USING-CLASS",1507), ECL_NIL, VVtemp[2], VVtemp[3], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC3__g11,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("CHANGE-CLASS",932), ECL_NIL, VVtemp[4], VVtemp[5], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC4__g12,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("MAKE-INSTANCES-OBSOLETE",950), ECL_NIL, VVtemp[6], VVtemp[7], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC5__g13,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("MAKE-INSTANCE",949), ECL_NIL, VVtemp[6], VVtemp[8], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC6__g14,ECL_NIL,Cblock,3);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("SLOT-MAKUNBOUND-USING-CLASS",1552), ECL_NIL, VVtemp[9], VVtemp[10], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC7__g15,ECL_NIL,Cblock,3);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("SLOT-BOUNDP-USING-CLASS",1541), ECL_NIL, VVtemp[9], VVtemp[10], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC8__g16,ECL_NIL,Cblock,3);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("SLOT-VALUE-USING-CLASS",1553), ECL_NIL, VVtemp[9], VVtemp[10], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC9__g17,ECL_NIL,Cblock,4);
  T0 = v1;
 }
 clos_install_method(6, VVtemp[11], ECL_NIL, VVtemp[12], VVtemp[13], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC10__g18,ECL_NIL,Cblock,3);
  T0 = v1;
 }
 clos_install_method(6, VV[1], ECL_NIL, VVtemp[9], VVtemp[10], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC11__g19,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("MAKE-INSTANCE",949), ECL_NIL, VVtemp[14], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC12__g20,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("FINALIZE-INHERITANCE",1513), ECL_NIL, VVtemp[14], VVtemp[7], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC13__g24,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("MAKE-LOAD-FORM",951), ECL_NIL, VVtemp[15], VVtemp[16], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC14__g25,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("PRINT-OBJECT",961), ECL_NIL, VVtemp[17], VVtemp[18], T0, ECL_T);
 }
}
