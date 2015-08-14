/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPSTRUCTURES.LSP                             */
#include <ecl/ecl-cmp.h>
#include "cmp/cmpstructures.eclh"
/*	function definition for GET-SLOT-TYPE                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1get_slot_type(cl_object v1name, cl_object v2index)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = si_get_sysprop(v1name, ECL_SYM("STRUCTURE-SLOT-DESCRIPTIONS",1155));
  T1 = ecl_nth(ecl_to_size(v2index),T0);
  value0 = ecl_caddr(T1);
  if ((value0)!=ECL_NIL) { goto L2; }
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for MAYBE-OPTIMIZE-STRUCTURE-ACCESS       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2maybe_optimize_structure_access(cl_object v1fname, cl_object v2args)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3slot_description;
   v3slot_description = si_get_sysprop(v1fname, VV[1]);
   if (Null(v3slot_description)) { goto L2; }
   if (Null(ecl_function_dispatch(cl_env_copy,VV[10])(1, v1fname) /*  INLINE-POSSIBLE */)) { goto L2; }
   if (Null(ecl_function_dispatch(cl_env_copy,VV[11])(0) /*  POLICY-INLINE-SLOT-ACCESS-P */)) { goto L2; }
   {
    cl_object v4structure_type;
    cl_object v5slot_index;
    v4structure_type = ECL_NIL;
    v5slot_index = ECL_NIL;
    if (!(ECL_CONSP(v3slot_description))) { goto L11; }
    v4structure_type = ecl_car(v3slot_description);
    v5slot_index = ecl_cdr(v3slot_description);
    if (Null(v5slot_index)) { goto L11; }
    if (ECL_FIXNUMP(v5slot_index)) { goto L8; }
    goto L9;
L11:;
    goto L9;
L9:;
    ecl_function_dispatch(cl_env_copy,VV[12])(3, _ecl_static_1, v1fname, v5slot_index) /*  CMPWARN */;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
L8:;
    {
     cl_fixnum v6;
     v6 = ecl_length(v2args);
     if ((v6)==(1)) { goto L18; }
    }
    ecl_function_dispatch(cl_env_copy,VV[12])(2, _ecl_static_2, v1fname) /*  CMPWARN */;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
L18:;
    v2args = ecl_car(v2args);
    if (!((v4structure_type)==(ECL_SYM("LIST",481)))) { goto L23; }
    value0 = cl_list(3, ECL_SYM("ELT",327), v2args, v5slot_index);
    return value0;
L23:;
    if (!((v4structure_type)==(ECL_SYM("VECTOR",898)))) { goto L25; }
    value0 = cl_list(3, ECL_SYM("SVREF",838), v2args, v5slot_index);
    return value0;
L25:;
    if (!(ECL_CONSP(v4structure_type))) { goto L27; }
    T0 = cl_list(3, ECL_SYM("THE",856), v4structure_type, v2args);
    value0 = cl_list(3, ECL_SYM("AREF",92), T0, v5slot_index);
    return value0;
L27:;
    T0 = cl_list(2, ECL_SYM("QUOTE",679), v4structure_type);
    value0 = cl_list(3, v2args, T0, v5slot_index);
    return value0;
   }
L2:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function STRUCTURE-REF                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC3si_structure_ref(cl_object v1, cl_object v2env)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4object;
   cl_object v5structure_name;
   cl_object v6index;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v7;
    v7 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4object = v7;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v7;
    v7 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5structure_name = v7;
   }
   if (!(v3==ECL_NIL)) { goto L15; }
   si_dm_too_few_arguments(v1);
L15:;
   {
    cl_object v7;
    v7 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v6index = v7;
   }
   if (Null(v3)) { goto L20; }
   si_dm_too_many_arguments(v1);
L20:;
   if (Null(ecl_function_dispatch(cl_env_copy,VV[13])(1, v2env) /*  POLICY-INLINE-SLOT-ACCESS */)) { goto L22; }
   if (Null(cl_constantp(2, v5structure_name, v2env))) { goto L22; }
   if (Null(cl_constantp(2, v6index, v2env))) { goto L22; }
   {
    cl_object v7index;
    cl_object v8aux;
    cl_object v9form;
    v7index = ecl_function_dispatch(cl_env_copy,VV[14])(2, v6index, v2env) /*  CMP-EVAL */;
    v8aux = cl_gensym(0);
    T0 = cl_list(2, v8aux, v7index);
    v9form = cl_listX(3, ECL_SYM("C-INLINE",1973), T0, VV[3]);
    if ((ecl_function_dispatch(cl_env_copy,VV[15])(1, v2env) /*  POLICY-ASSUME-NO-ERRORS */)!=ECL_NIL) { goto L29; }
    {
     cl_object v10structure_name;
     v10structure_name = ecl_function_dispatch(cl_env_copy,VV[14])(2, v5structure_name, v2env) /*  CMP-EVAL */;
     T0 = cl_list(2, v10structure_name, v9form);
     T1 = cl_list(3, v8aux, v10structure_name, v7index);
     T2 = cl_listX(3, ECL_SYM("C-INLINE",1973), T1, VV[4]);
     T3 = cl_list(2, ECL_T, T2);
     v9form = cl_list(4, ECL_SYM("COMPILER-TYPECASE",1780), v8aux, T0, T3);
    }
L29:;
    T0 = cl_list(2, v8aux, v4object);
    T1 = ecl_list1(T0);
    T2 = cl_list(2, VV[5], v8aux);
    T3 = cl_list(2, ECL_SYM("DECLARE",274), T2);
    value0 = cl_list(4, ECL_SYM("LET",477), T1, T3, v9form);
    return value0;
   }
L22:;
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function STRUCTURE-SET                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC4si_structure_set(cl_object v1, cl_object v2env)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4object;
   cl_object v5structure_name;
   cl_object v6index;
   cl_object v7value;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v8;
    v8 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4object = v8;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v8;
    v8 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5structure_name = v8;
   }
   if (!(v3==ECL_NIL)) { goto L15; }
   si_dm_too_few_arguments(v1);
L15:;
   {
    cl_object v8;
    v8 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v6index = v8;
   }
   if (!(v3==ECL_NIL)) { goto L21; }
   si_dm_too_few_arguments(v1);
L21:;
   {
    cl_object v8;
    v8 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v7value = v8;
   }
   if (Null(v3)) { goto L26; }
   si_dm_too_many_arguments(v1);
L26:;
   if (Null(ecl_function_dispatch(cl_env_copy,VV[13])(1, v2env) /*  POLICY-INLINE-SLOT-ACCESS */)) { goto L28; }
   if (Null(cl_constantp(2, v5structure_name, v2env))) { goto L28; }
   if (Null(cl_constantp(2, v6index, v2env))) { goto L28; }
   {
    cl_object v8index;
    cl_object v9aux;
    cl_object v10form;
    v8index = ecl_function_dispatch(cl_env_copy,VV[14])(2, v6index, v2env) /*  CMP-EVAL */;
    v9aux = cl_gensym(0);
    T0 = cl_list(3, v9aux, v8index, v7value);
    v10form = cl_listX(3, ECL_SYM("C-INLINE",1973), T0, VV[6]);
    if ((ecl_function_dispatch(cl_env_copy,VV[15])(1, v2env) /*  POLICY-ASSUME-NO-ERRORS */)!=ECL_NIL) { goto L35; }
    {
     cl_object v11structure_name;
     v11structure_name = ecl_function_dispatch(cl_env_copy,VV[14])(2, v5structure_name, v2env) /*  CMP-EVAL */;
     T0 = cl_list(2, v11structure_name, v10form);
     T1 = cl_list(2, ECL_SYM("QUOTE",679), v11structure_name);
     T2 = cl_list(4, v9aux, T1, v8index, v7value);
     T3 = cl_listX(3, ECL_SYM("C-INLINE",1973), T2, VV[7]);
     T4 = cl_list(2, ECL_T, T3);
     v10form = cl_list(4, ECL_SYM("COMPILER-TYPECASE",1780), v9aux, T0, T4);
    }
L35:;
    T0 = cl_list(2, v9aux, v4object);
    T1 = ecl_list1(T0);
    T2 = cl_list(2, VV[5], v9aux);
    T3 = cl_list(2, ECL_SYM("DECLARE",274), T2);
    value0 = cl_list(4, ECL_SYM("LET",477), T1, T3, v10form);
    return value0;
   }
L28:;
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}

#include "cmp/cmpstructures.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclrdsc1m2bDUor9_IDstVE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPSTRUCTURES.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclrdsc1m2bDUor9_IDstVE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[8]);                            /*  GET-SLOT-TYPE   */
 ecl_cmp_defun(VV[9]);                            /*  MAYBE-OPTIMIZE-STRUCTURE-ACCESS */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC3si_structure_ref,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("STRUCTURE-REF",1153), ECL_SYM("COMPILER-MACRO",238), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC4si_structure_set,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("STRUCTURE-SET",1154), ECL_SYM("COMPILER-MACRO",238), T0);
 }
}
