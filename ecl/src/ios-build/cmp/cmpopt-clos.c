/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPOPT-CLOS.LSP                               */
#include <ecl/ecl-cmp.h>
#include "cmp/cmpopt-clos.eclh"
/*	function definition for CLOS-COMPILER-MACRO-EXPAND            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1clos_compiler_macro_expand(cl_object v1fname, cl_object v2args)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(si_valid_function_name_p(v1fname))) { goto L1; }
  if (Null(cl_fboundp(v1fname))) { goto L1; }
  {
   cl_object v3function;
   v3function = cl_fdefinition(v1fname);
   if (Null(si_of_class_p(2, v3function, ECL_SYM("GENERIC-FUNCTION",945)))) { goto L5; }
   T0 = CONS(v1fname,v2args);
   value0 = ecl_function_dispatch(cl_env_copy,VV[1])(2, v3function, T0) /*  GENERIC-FUNCTION-MACRO-EXPAND */;
   return value0;
L5:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G0                                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC2__g0(cl_object v1g, cl_object v2whole)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3output;
   cl_object v4success;
   v3output = L5optimizable_slot_accessor(v1g, v2whole);
   if (Null(v3output)) { goto L4; }
   v4success = ECL_T;
   goto L2;
L4:;
   v4success = ECL_NIL;
   goto L2;
L2:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v4success;
   cl_env_copy->values[0] = v3output;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for OPTIMIZABLE-SLOT-READER               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3optimizable_slot_reader(cl_object v1method, cl_object v2whole)
{
 cl_object T0, T1, T2, T3, T4, T5, T6;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(si_of_class_p(2, v1method, ECL_SYM("STANDARD-READER-METHOD",1563)))) { goto L1; }
  {
   cl_object v3class;
   T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("METHOD-SPECIALIZERS",1534))(1, v1method) /*  METHOD-SPECIALIZERS */;
   v3class = ecl_car(T0);
   if (Null(ecl_function_dispatch(cl_env_copy,VV[9])(1, v3class) /*  CLASS-SEALEDP */)) { goto L4; }
   {
    cl_object v4slotd;
    cl_object v5location;
    v4slotd = ecl_function_dispatch(cl_env_copy,ECL_SYM("ACCESSOR-METHOD-SLOT-DEFINITION",1482))(1, v1method) /*  ACCESSOR-METHOD-SLOT-DEFINITION */;
    v5location = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-LOCATION",1547))(1, v4slotd) /*  SLOT-DEFINITION-LOCATION */;
    {
     cl_object v6object;
     v6object = cl_gentemp(0);
     T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v4slotd) /*  SLOT-DEFINITION-NAME */;
     T1 = (cl_env_copy->function=(ECL_SYM("CLASS-NAME",934)->symbol.gfdef))->cfun.entry(1, v3class) /*  CLASS-NAME */;
     ecl_function_dispatch(cl_env_copy,VV[10])(3, _ecl_static_1, T0, T1) /*  CMPNOTE */;
     T0 = ecl_cadr(v2whole);
     T1 = cl_list(2, v6object, T0);
     T2 = ecl_list1(T1);
     T3 = cl_list(2, ECL_SYM("QUOTE",679), v3class);
     T4 = cl_list(3, VV[2], v6object, T3);
     T5 = cl_list(3, ECL_SYM("INSTANCE-REF",1169), v6object, v5location);
     T6 = cl_list(3, ECL_SYM("LOCALLY",490), VV[3], T5);
     value0 = cl_list(4, ECL_SYM("LET",477), T2, T4, T6);
     return value0;
    }
   }
L4:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for OPTIMIZABLE-SLOT-WRITER               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4optimizable_slot_writer(cl_object v1method, cl_object v2whole)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(si_of_class_p(2, v1method, ECL_SYM("STANDARD-WRITER-METHOD",1565)))) { goto L1; }
  {
   cl_object v3class;
   T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("METHOD-SPECIALIZERS",1534))(1, v1method) /*  METHOD-SPECIALIZERS */;
   v3class = ecl_cadr(T0);
   if (Null(ecl_function_dispatch(cl_env_copy,VV[9])(1, v3class) /*  CLASS-SEALEDP */)) { goto L4; }
   {
    cl_object v4slotd;
    cl_object v5location;
    v4slotd = ecl_function_dispatch(cl_env_copy,ECL_SYM("ACCESSOR-METHOD-SLOT-DEFINITION",1482))(1, v1method) /*  ACCESSOR-METHOD-SLOT-DEFINITION */;
    v5location = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-LOCATION",1547))(1, v4slotd) /*  SLOT-DEFINITION-LOCATION */;
    {
     cl_object v6object;
     cl_object v7value;
     v6object = cl_gentemp(0);
     v7value = cl_gentemp(0);
     T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v4slotd) /*  SLOT-DEFINITION-NAME */;
     T1 = (cl_env_copy->function=(ECL_SYM("CLASS-NAME",934)->symbol.gfdef))->cfun.entry(1, v3class) /*  CLASS-NAME */;
     ecl_function_dispatch(cl_env_copy,VV[10])(3, _ecl_static_2, T0, T1) /*  CMPNOTE */;
     T0 = ecl_cadr(v2whole);
     T1 = cl_list(2, v7value, T0);
     T2 = ecl_caddr(v2whole);
     T3 = cl_list(2, v6object, T2);
     T4 = cl_list(2, T1, T3);
     T5 = cl_list(2, ECL_SYM("QUOTE",679), v3class);
     T6 = cl_list(3, VV[2], v6object, T5);
     T7 = cl_list(4, ECL_SYM("INSTANCE-SET",1170), v6object, v5location, v7value);
     T8 = cl_list(3, ECL_SYM("LOCALLY",490), VV[3], T7);
     value0 = cl_list(4, ECL_SYM("LET",477), T4, T6, T8);
     return value0;
    }
   }
L4:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for OPTIMIZABLE-SLOT-ACCESSOR             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5optimizable_slot_accessor(cl_object v1g, cl_object v2whole)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[13])(0) /*  POLICY-INLINE-SLOT-ACCESS */)) { goto L2; }
  {
   cl_object v3methods;
   v3methods = ecl_function_dispatch(cl_env_copy,ECL_SYM("GENERIC-FUNCTION-METHODS",1524))(1, v1g) /*  GENERIC-FUNCTION-METHODS */;
   if (Null(v3methods)) { goto L6; }
   T0 = ecl_cdr(v3methods);
   if (!(T0==ECL_NIL)) { goto L6; }
   {
    cl_object v4principal;
    v4principal = ecl_car(v3methods);
    value0 = L3optimizable_slot_reader(v4principal, v2whole);
    if ((value0)!=ECL_NIL) { goto L11; }
    value0 = L4optimizable_slot_writer(v4principal, v2whole);
    return value0;
L11:;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L6:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}

#include "cmp/cmpopt-clos.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecl1iWnMcWIL1Si9_jnzTOE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPOPT-CLOS.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_ecl1iWnMcWIL1Si9_jnzTOE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[7]);                            /*  CLOS-COMPILER-MACRO-EXPAND */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC2__g0,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[1], ECL_NIL, VVtemp[0], VVtemp[1], T0, ECL_T);
 }
 ecl_cmp_defun(VV[8]);                            /*  OPTIMIZABLE-SLOT-READER */
 ecl_cmp_defun(VV[11]);                           /*  OPTIMIZABLE-SLOT-WRITER */
 ecl_cmp_defun(VV[12]);                           /*  OPTIMIZABLE-SLOT-ACCESSOR */
}
