/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPC-INLINER.LSP                              */
#include <ecl/ecl-cmp.h>
#include "cmp/cmpc-inliner.eclh"
/*	function definition for INLINED-ARG-LOC                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1inlined_arg_loc(cl_object v1arg)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_cadr(v1arg);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for INLINED-ARG-TYPE                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2inlined_arg_type(cl_object v1arg)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_car(v1arg);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for INLINED-ARG-REP-TYPE                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3inlined_arg_rep_type(cl_object v1arg)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_cadr(v1arg);
  value0 = ecl_function_dispatch(cl_env_copy,VV[29])(1, T0) /*  LOC-REPRESENTATION-TYPE */;
  return value0;
 }
}
/*	local function DEFINE-C-INLINER                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC4define_c_inliner(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4fname;
   cl_object v5lambda_list;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4fname = v6;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5lambda_list = v6;
   }
   T0 = cl_list(2, ECL_SYM("QUOTE",679), v4fname);
   T1 = cl_list(3, ECL_SYM("GETHASH",413), T0, VV[3]);
   T2 = cl_listX(3, ECL_SYM("BLOCK",137), ECL_NIL, v3);
   T3 = cl_list(3, ECL_SYM("LAMBDA",452), v5lambda_list, T2);
   T4 = cl_list(2, ECL_SYM("FUNCTION",396), T3);
   value0 = cl_list(3, ECL_SYM("SETF",750), T1, T4);
   return value0;
  }
 }
}
/*	function definition for APPLY-INLINER                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5apply_inliner(cl_object v1fname, cl_object v2return_type, cl_object v3inlined_args)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4fd;
   v4fd = ecl_gethash_safe(v1fname,ecl_symbol_value(VV[3]),ECL_NIL);
   if (Null(v4fd)) { goto L2; }
   value0 = cl_apply(3, v4fd, v2return_type, v3inlined_args);
   return value0;
L2:;
   value0 = L6default_c_inliner(v1fname, v2return_type, v3inlined_args);
   return value0;
  }
 }
}
/*	function definition for DEFAULT-C-INLINER                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6default_c_inliner(cl_object v1fname, cl_object v2return_type, cl_object v3inlined_args)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4arg_types;
   cl_object v5ii;
   {
    cl_object v6;
    cl_object v7;
    v6 = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v3inlined_args))) FEtype_error_list(v3inlined_args);
    v7 = v3inlined_args;
    {
     cl_object v8;
     cl_object v9;
     v8 = ecl_list1(ECL_NIL);
     v9 = v8;
L7:;
     if (!(ecl_endp(v7))) { goto L9; }
     goto L8;
L9:;
     v6 = _ecl_car(v7);
     {
      cl_object v10;
      v10 = _ecl_cdr(v7);
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      v7 = v10;
     }
     if (ecl_unlikely(ECL_ATOM(v9))) FEtype_error_cons(v9);
     T0 = v9;
     T1 = ecl_car(v6);
     v9 = ecl_list1(T1);
     (ECL_CONS_CDR(T0)=v9,T0);
     goto L7;
L8:;
     v4arg_types = ecl_cdr(v8);
     goto L1;
    }
   }
L1:;
   v5ii = L7inline_function(3, v1fname, v4arg_types, v2return_type);
   if (Null(v5ii)) { goto L25; }
   value0 = L8apply_inline_info(v5ii, v3inlined_args);
   return value0;
L25:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for INLINE-FUNCTION                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7inline_function(cl_narg narg, cl_object v1fname, cl_object v2arg_types, cl_object v3return_type, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>4)) FEwrong_num_arguments_anonym();
 {
  cl_object v4return_rep_type;
  va_list args; va_start(args,v3return_type);
  {
   int i = 3;
   if (i >= narg) {
    v4return_rep_type = VV[7];
   } else {
    i++;
    v4return_rep_type = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (Null(ecl_function_dispatch(cl_env_copy,VV[34])(1, v1fname) /*  INLINE-POSSIBLE */)) { goto L3; }
  if ((ecl_gethash_safe(v1fname,ecl_symbol_value(VV[8]),ECL_NIL))!=ECL_NIL) { goto L3; }
  {
   cl_object v5dest_rep_type;
   cl_object v6ii;
   v5dest_rep_type = ecl_function_dispatch(cl_env_copy,VV[29])(1, ecl_symbol_value(VV[9])) /*  LOC-REPRESENTATION-TYPE */;
   v6ii = L10get_inline_info(v1fname, v2arg_types, v3return_type, v4return_rep_type);
   value0 = v6ii;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L3:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for APPLY-INLINE-INFO                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8apply_inline_info(cl_object v1ii, cl_object v2inlined_locs)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3arg_types;
   cl_object v4out_rep_type;
   cl_object v5out_type;
   cl_object v6side_effects_p;
   cl_object v7fun;
   cl_object v8one_liner;
   v3arg_types = ecl_function_dispatch(cl_env_copy,VV[36])(1, v1ii) /*  INLINE-INFO-ARG-TYPES */;
   v4out_rep_type = ecl_function_dispatch(cl_env_copy,VV[37])(1, v1ii) /*  INLINE-INFO-RETURN-REP-TYPE */;
   v5out_type = ecl_function_dispatch(cl_env_copy,VV[38])(1, v1ii) /*  INLINE-INFO-RETURN-TYPE */;
   T0 = ecl_function_dispatch(cl_env_copy,VV[39])(1, v1ii) /*  INLINE-INFO-NAME */;
   v6side_effects_p = ecl_function_dispatch(cl_env_copy,VV[40])(1, T0) /*  FUNCTION-MAY-HAVE-SIDE-EFFECTS */;
   v7fun = ecl_function_dispatch(cl_env_copy,VV[41])(1, v1ii) /*  INLINE-INFO-EXPANSION */;
   v8one_liner = ecl_function_dispatch(cl_env_copy,VV[42])(1, v1ii) /*  INLINE-INFO-ONE-LINER */;
   T0 = ecl_list1(v4out_rep_type);
   value0 = ecl_function_dispatch(cl_env_copy,VV[43])(6, v2inlined_locs, v3arg_types, T0, v7fun, v6side_effects_p, v8one_liner) /*  PRODUCE-INLINE-LOC */;
   return value0;
  }
 }
}
/*	function definition for CHOOSE-INLINE-INFO                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L9choose_inline_info(cl_object v1ia, cl_object v2ib, cl_object v3return_type, cl_object v4return_rep_type)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((v4return_rep_type)==(VV[7])) { goto L1; }
  if ((v4return_rep_type)==(ECL_SYM("VOID",1381))) { goto L1; }
  {
   cl_object v5info_type;
   v5info_type = ecl_function_dispatch(cl_env_copy,VV[37])(1, v2ib) /*  INLINE-INFO-RETURN-REP-TYPE */;
   if ((v4return_rep_type)==(v5info_type)) { goto L1; }
   if ((v5info_type)==(VV[12])) { goto L1; }
  }
  value0 = v1ia;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (!(v1ia==ECL_NIL)) { goto L7; }
  value0 = v2ib;
  cl_env_copy->nvalues = 1;
  return value0;
L7:;
  T0 = ecl_function_dispatch(cl_env_copy,VV[36])(1, v1ia) /*  INLINE-INFO-ARG-TYPES */;
  T1 = ecl_function_dispatch(cl_env_copy,VV[36])(1, v2ib) /*  INLINE-INFO-ARG-TYPES */;
  if (!(ecl_equal(T0,T1))) { goto L9; }
  value0 = v1ia;
  cl_env_copy->nvalues = 1;
  return value0;
L9:;
  T0 = ecl_fdefinition(VV[45]);
  T1 = ecl_function_dispatch(cl_env_copy,VV[36])(1, v1ia) /*  INLINE-INFO-ARG-TYPES */;
  T2 = ecl_function_dispatch(cl_env_copy,VV[36])(1, v2ib) /*  INLINE-INFO-ARG-TYPES */;
  if (Null(cl_every(3, T0, T1, T2))) { goto L11; }
  value0 = v2ib;
  cl_env_copy->nvalues = 1;
  return value0;
L11:;
  value0 = v1ia;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for GET-INLINE-INFO                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L10get_inline_info(cl_object v1fname, cl_object v2types, cl_object v3return_type, cl_object v4return_rep_type)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v5output;
   v5output = ECL_NIL;
   if ((ecl_function_dispatch(cl_env_copy,VV[46])(0) /*  SAFE-COMPILE */)!=ECL_NIL) { goto L2; }
   {
    cl_object v6;
    v6 = si_get_sysprop(v1fname, VV[14]);
    goto L7;
L6:;
    {
     cl_object v7x;
     v7x = ecl_car(v6);
     {
      cl_object v8other;
      v8other = L13inline_type_matches(v7x, v2types, v3return_type);
      if (Null(v8other)) { goto L11; }
      v5output = L9choose_inline_info(v5output, v8other, v3return_type, v4return_rep_type);
     }
L11:;
    }
    v6 = ecl_cdr(v6);
L7:;
    if (Null(v6)) { goto L17; }
    goto L6;
L17:;
   }
L2:;
   {
    cl_object v6;
    v6 = si_get_sysprop(v1fname, VV[15]);
    goto L23;
L22:;
    {
     cl_object v7x;
     v7x = ecl_car(v6);
     {
      cl_object v8other;
      v8other = L13inline_type_matches(v7x, v2types, v3return_type);
      if (Null(v8other)) { goto L27; }
      v5output = L9choose_inline_info(v5output, v8other, v3return_type, v4return_rep_type);
     }
L27:;
    }
    v6 = ecl_cdr(v6);
L23:;
    if (Null(v6)) { goto L33; }
    goto L22;
L33:;
   }
   {
    cl_object v6;
    v6 = si_get_sysprop(v1fname, VV[16]);
    goto L39;
L38:;
    {
     cl_object v7x;
     v7x = ecl_car(v6);
     {
      cl_object v8other;
      v8other = L13inline_type_matches(v7x, v2types, v3return_type);
      if (Null(v8other)) { goto L43; }
      v5output = L9choose_inline_info(v5output, v8other, v3return_type, v4return_rep_type);
     }
L43:;
    }
    v6 = ecl_cdr(v6);
L39:;
    if (Null(v6)) { goto L49; }
    goto L38;
L49:;
   }
   if (!(v5output==ECL_NIL)) { goto L51; }
   if (Null(si_get_sysprop(v1fname, VV[17]))) { goto L51; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[47])(1, ECL_SYM("SPEED",791)) /*  CMP-ENV-OPTIMIZATION */;
   if (!(ecl_number_compare(T0,ecl_make_fixnum(1))>=0)) { goto L51; }
   ecl_function_dispatch(cl_env_copy,VV[48])(3, _ecl_static_1, v1fname, v2types) /*  CMPWARN-STYLE */;
L51:;
   value0 = v5output;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for TO-FIXNUM-FLOAT-TYPE                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L11to_fixnum_float_type(cl_object v1type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   v2 = VV[18];
   goto L4;
L3:;
   {
    cl_object v3i;
    v3i = ecl_car(v2);
    if (Null(ecl_function_dispatch(cl_env_copy,VV[45])(2, v3i, v1type) /*  TYPE>= */)) { goto L8; }
    value0 = v3i;
    cl_env_copy->nvalues = 1;
    return value0;
L8:;
   }
   v2 = ecl_cdr(v2);
L4:;
   if (Null(v2)) { goto L12; }
   goto L3;
L12:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for MAXIMUM-FLOAT-TYPE                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L12maximum_float_type(cl_object v1t1, cl_object v2t2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(v1t1==ECL_NIL)) { goto L1; }
  value0 = v2t2;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if ((v1t1)==(ECL_SYM("LONG-FLOAT",508))) { goto L5; }
  if (!((v2t2)==(ECL_SYM("LONG-FLOAT",508)))) { goto L3; }
  goto L4;
L5:;
L4:;
  value0 = ECL_SYM("LONG-FLOAT",508);
  cl_env_copy->nvalues = 1;
  return value0;
L3:;
  if ((v1t1)==(ECL_SYM("DOUBLE-FLOAT",315))) { goto L9; }
  if (!((v2t2)==(ECL_SYM("DOUBLE-FLOAT",315)))) { goto L7; }
  goto L8;
L9:;
L8:;
  value0 = ECL_SYM("DOUBLE-FLOAT",315);
  cl_env_copy->nvalues = 1;
  return value0;
L7:;
  if ((v1t1)==(ECL_SYM("SINGLE-FLOAT",778))) { goto L13; }
  if (!((v2t2)==(ECL_SYM("SINGLE-FLOAT",778)))) { goto L11; }
  goto L12;
L13:;
L12:;
  value0 = ECL_SYM("SINGLE-FLOAT",778);
  cl_env_copy->nvalues = 1;
  return value0;
L11:;
  value0 = ECL_SYM("FIXNUM",372);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for INLINE-TYPE-MATCHES                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L13inline_type_matches(cl_object v1inline_info, cl_object v2arg_types, cl_object v3return_type)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((ecl_function_dispatch(cl_env_copy,VV[52])(1, v1inline_info) /*  INLINE-INFO-MULTIPLE-VALUES */)!=ECL_NIL) { goto L1; }
  {
   cl_object v4;
   v4 = ecl_symbol_value(VV[9]);
   if (!((v4)==(ECL_SYM("VALUES",895)))) { goto L8; }
   goto L5;
   goto L6;
L8:;
   goto L6;
L6:;
   if (!((v4)==(ECL_SYM("RETURN",724)))) { goto L1; }
   goto L2;
L5:;
  }
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  {
   cl_object v4rts;
   cl_object v5number_max;
   v4rts = ECL_NIL;
   v5number_max = ECL_NIL;
   {
    cl_object v6arg_types;
    cl_object v7types;
    v6arg_types = v2arg_types;
    v7types = ecl_function_dispatch(cl_env_copy,VV[36])(1, v1inline_info) /*  INLINE-INFO-ARG-TYPES */;
    goto L18;
L17:;
    {
     cl_object v8arg_type;
     cl_object v9type;
     v8arg_type = ecl_car(v6arg_types);
     v9type = ecl_car(v7types);
     if (!((v9type)==(VV[23]))) { goto L23; }
     {
      cl_object v10new_type;
      v10new_type = L11to_fixnum_float_type(v8arg_type);
      if ((v10new_type)!=ECL_NIL) { goto L26; }
      value0 = ECL_NIL;
      cl_env_copy->nvalues = 1;
      return value0;
L26:;
      v4rts = CONS(v10new_type,v4rts);
      v5number_max = L12maximum_float_type(v5number_max, v10new_type);
      goto L20;
     }
L23:;
     if (Null(ecl_function_dispatch(cl_env_copy,VV[45])(2, v9type, v8arg_type) /*  TYPE>= */)) { goto L31; }
     v4rts = CONS(v9type,v4rts);
     goto L20;
L31:;
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 1;
     return value0;
    }
L20:;
    v6arg_types = ecl_cdr(v6arg_types);
    v7types = ecl_cdr(v7types);
L18:;
    if (ecl_endp(v6arg_types)) { goto L38; }
    if (ecl_endp(v7types)) { goto L38; }
    goto L17;
L38:;
    if ((v6arg_types)!=ECL_NIL) { goto L42; }
    if (Null(v7types)) { goto L13; }
    goto L41;
L42:;
L41:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L13:;
   T0 = ecl_function_dispatch(cl_env_copy,VV[37])(1, v1inline_info) /*  INLINE-INFO-RETURN-REP-TYPE */;
   if ((T0)==(VV[12])) { goto L46; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[53])(1, v1inline_info) /*  INLINE-INFO-EXACT-RETURN-TYPE */;
   if (T0==ECL_NIL) { goto L46; }
   if (Null(ecl_function_dispatch(cl_env_copy,VV[54])(0) /*  POLICY-ASSUME-RIGHT-TYPE */)) { goto L44; }
   {
    cl_object v6inline_return_type;
    v6inline_return_type = ecl_function_dispatch(cl_env_copy,VV[38])(1, v1inline_info) /*  INLINE-INFO-RETURN-TYPE */;
    if (Null(v5number_max)) { goto L51; }
    if (!((v5number_max)==(ECL_SYM("FIXNUM",372)))) { goto L55; }
    v5number_max = ECL_SYM("INTEGER",437);
    goto L54;
L55:;
L54:;
    if (Null(v5number_max)) { goto L44; }
    if (Null(ecl_function_dispatch(cl_env_copy,VV[45])(2, v6inline_return_type, v5number_max) /*  TYPE>= */)) { goto L44; }
    if (Null(ecl_function_dispatch(cl_env_copy,VV[45])(2, v5number_max, v3return_type) /*  TYPE>= */)) { goto L44; }
    goto L45;
L51:;
    if (Null(ecl_function_dispatch(cl_env_copy,VV[45])(2, v6inline_return_type, v3return_type) /*  TYPE>= */)) { goto L44; }
    goto L45;
   }
L46:;
L45:;
   {
    cl_object v6inline_info;
    v6inline_info = cl_copy_structure(v1inline_info);
    {
     cl_object v7;
     v7 = cl_nreverse(v4rts);
     ecl_structure_set(v6inline_info,VV[24],3,v7);
    }
    value0 = v6inline_info;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L44:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}

#include "cmp/cmpc-inliner.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclnWL9Qg2BrwKr9_UmxTOE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPC-INLINER.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclnWL9Qg2BrwKr9_UmxTOE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[26]);                           /*  INLINED-ARG-LOC */
 ecl_cmp_defun(VV[27]);                           /*  INLINED-ARG-TYPE */
 ecl_cmp_defun(VV[28]);                           /*  INLINED-ARG-REP-TYPE */
 ecl_cmp_defmacro(VV[30]);                        /*  DEFINE-C-INLINER */
 ecl_cmp_defun(VV[31]);                           /*  APPLY-INLINER   */
 ecl_cmp_defun(VV[32]);                           /*  DEFAULT-C-INLINER */
 ecl_cmp_defun(VV[33]);                           /*  INLINE-FUNCTION */
 ecl_cmp_defun(VV[35]);                           /*  APPLY-INLINE-INFO */
 ecl_cmp_defun(VV[44]);                           /*  CHOOSE-INLINE-INFO */
 (void)0; /* No entry created for GET-INLINE-INFO */
 ecl_cmp_defun(VV[49]);                           /*  TO-FIXNUM-FLOAT-TYPE */
 ecl_cmp_defun(VV[50]);                           /*  MAXIMUM-FLOAT-TYPE */
 ecl_cmp_defun(VV[51]);                           /*  INLINE-TYPE-MATCHES */
}
