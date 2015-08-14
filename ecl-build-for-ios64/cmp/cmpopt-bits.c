/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPOPT-BITS.LSP                               */
#include <ecl/ecl-cmp.h>
#include "cmp/cmpopt-bits.eclh"
/*	local function LDB                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC1ldb(cl_object v1, cl_object v2)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_cdr(v1);
   {
    cl_object v4;
    cl_fixnum v5;
    cl_object v6size;
    cl_object v7pos;
    v4 = ecl_car(v3);
    v5 = (cl_fixnum)(ecl_integer_length(ecl_make_fixnum(2305843009213693951)));
    v6size = ECL_NIL;
    v7pos = ECL_NIL;
    if (!(ECL_CONSP(v4))) { goto L6; }
    T0 = ecl_car(v4);
    if (!((ECL_SYM("BYTE",162))==(T0))) { goto L6; }
    v6size = ecl_cadr(v4);
    if (!(ECL_FIXNUMP(v6size)||ECL_BIGNUMP(v6size))) { goto L6; }
    v7pos = ecl_caddr(v4);
    if (!(ECL_FIXNUMP(v7pos)||ECL_BIGNUMP(v7pos))) { goto L6; }
    T0 = ecl_plus(v6size,v7pos);
    if (!(ecl_number_compare(T0,ecl_make_fixnum(v5))<=0)) { goto L6; }
    T0 = ecl_cadr(v3);
    T1 = ecl_function_dispatch(cl_env_copy,VV[7])(1, T0) /*  RESULT-TYPE */;
    if (Null(cl_subtypep(2, T1, ECL_SYM("FIXNUM",372)))) { goto L6; }
    T0 = ecl_cadr(v3);
    T1 = cl_list(4, VV[0], v6size, v7pos, T0);
    value0 = cl_list(3, ECL_SYM("TRULY-THE",1949), ECL_SYM("FIXNUM",372), T1);
    return value0;
L6:;
    value0 = v1;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	local function ASH                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC2ash(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4argument;
   cl_object v5shift;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4argument = v6;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5shift = v6;
   }
   if (Null(v3)) { goto L14; }
   si_dm_too_many_arguments(v1);
L14:;
   if (Null(ecl_function_dispatch(cl_env_copy,VV[8])(0) /*  POLICY-ASSUME-RIGHT-TYPE */)) { goto L16; }
   if (!(ECL_FIXNUMP(v5shift)||ECL_BIGNUMP(v5shift))) { goto L16; }
   if (!(ecl_zerop(v5shift))) { goto L19; }
   value0 = v4argument;
   cl_env_copy->nvalues = 1;
   return value0;
L19:;
   value0 = cl_list(3, VV[1], v4argument, v5shift);
   return value0;
L16:;
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G13                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC3__g13(cl_object v1return_type, cl_object v2argument, cl_object v3orig_shift)
{
 cl_object T0, T1, T2, T3, T4, T5;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4arg_type;
   cl_object v5arg_c_type;
   cl_object v6return_c_type;
   cl_object v7shift;
   v4arg_type = ecl_function_dispatch(cl_env_copy,VV[9])(1, v2argument) /*  INLINED-ARG-TYPE */;
   v5arg_c_type = ecl_function_dispatch(cl_env_copy,VV[10])(1, v4arg_type) /*  LISP-TYPE->REP-TYPE */;
   v6return_c_type = ecl_function_dispatch(cl_env_copy,VV[10])(1, v1return_type) /*  LISP-TYPE->REP-TYPE */;
   T0 = ecl_function_dispatch(cl_env_copy,VV[11])(1, v3orig_shift) /*  INLINED-ARG-LOC */;
   v7shift = ecl_function_dispatch(cl_env_copy,VV[12])(1, T0) /*  LOC-IMMEDIATE-VALUE */;
   if (Null(ecl_function_dispatch(cl_env_copy,VV[13])(1, v5arg_c_type) /*  C-INTEGER-REP-TYPE-P */)) { goto L7; }
   if ((ecl_function_dispatch(cl_env_copy,VV[13])(1, v6return_c_type) /*  C-INTEGER-REP-TYPE-P */)!=ECL_NIL) { goto L5; }
   goto L6;
L7:;
L6:;
   T0 = cl_list(2, v2argument, v3orig_shift);
   value0 = ecl_function_dispatch(cl_env_copy,VV[14])(6, T0, VV[3], VV[4], _ecl_static_1, ECL_NIL, ECL_T) /*  PRODUCE-INLINE-LOC */;
   return value0;
L5:;
   {
    cl_object v8arg_bits;
    cl_object v9return_bits;
    cl_object v10max_type;
    v8arg_bits = ecl_function_dispatch(cl_env_copy,VV[15])(1, v5arg_c_type) /*  C-INTEGER-REP-TYPE-BITS */;
    v9return_bits = ecl_function_dispatch(cl_env_copy,VV[15])(1, v6return_c_type) /*  C-INTEGER-REP-TYPE-BITS */;
    if (!(ecl_plusp(v7shift))) { goto L12; }
    if (!(ecl_number_compare(v8arg_bits,v9return_bits)<0)) { goto L12; }
    v10max_type = v6return_c_type;
    goto L11;
L12:;
    v10max_type = v5arg_c_type;
L11:;
    T0 = ecl_list1(v2argument);
    T1 = ecl_list1(v10max_type);
    T2 = ecl_list1(v1return_type);
    if (!(ecl_minusp(v7shift))) { goto L16; }
    T3 = _ecl_static_2;
    goto L15;
L16:;
    T3 = _ecl_static_3;
L15:;
    T4 = cl_abs(v7shift);
    T5 = cl_format(3, ECL_NIL, T3, T4);
    value0 = ecl_function_dispatch(cl_env_copy,VV[14])(6, T0, T1, T2, T5, ECL_NIL, ECL_T) /*  PRODUCE-INLINE-LOC */;
    return value0;
   }
  }
 }
}
/*	local function G17                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC4__g17(cl_narg narg, cl_object v1fname, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2args;
  ecl_va_list args; ecl_va_start(args,v1fname,narg,1);
  v2args = cl_grab_rest_args(args);
  ecl_va_end(args);
  if (Null(v2args)) { goto L2; }
  {
   cl_object v3;
   v3 = VV[6];
   goto L7;
L6:;
   {
    cl_object v4int_type;
    v4int_type = ecl_car(v3);
    {
     cl_object v5value;
     cl_object v6;
     v5value = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v2args))) FEtype_error_list(v2args);
     v6 = v2args;
L16:;
     if (!(ecl_endp(v6))) { goto L18; }
     goto L17;
L18:;
     v5value = _ecl_car(v6);
     {
      cl_object v7;
      v7 = _ecl_cdr(v6);
      if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
      v6 = v7;
     }
     if ((cl_subtypep(2, v5value, v4int_type))!=ECL_NIL) { goto L26; }
     goto L11;
L26:;
     goto L16;
L17:;
     goto L12;
    }
L12:;
    T0 = v4int_type;
    goto L1;
L11:;
   }
   v3 = ecl_cdr(v3);
L7:;
   if (Null(v3)) { goto L32; }
   goto L6;
L32:;
   T0 = ECL_SYM("INTEGER",437);
   goto L1;
  }
L2:;
  T0 = ECL_SYM("FIXNUM",372);
L1:;
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = T0;
  cl_env_copy->values[0] = v2args;
  return cl_env_copy->values[0];
 }
}

#include "cmp/cmpopt-bits.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecl5Mxoo0jRgBXp9_xfrtVE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPOPT-BITS.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_ecl5Mxoo0jRgBXp9_xfrtVE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC1ldb,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("LDB",457), ECL_SYM("COMPILER-MACRO",238), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC2ash,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("ASH",110), ECL_SYM("COMPILER-MACRO",238), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC3__g13,ECL_NIL,Cblock,3);
  T0 = v1;
 }
 si_hash_set(VV[1], ecl_symbol_value(VV[2]), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC4__g17,ECL_NIL,Cblock);
  T0 = v1;
 }
 si_hash_set(ECL_SYM("LOGAND",492), ecl_symbol_value(VV[5]), T0);
 }
}
