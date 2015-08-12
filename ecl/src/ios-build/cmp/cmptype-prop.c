/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPTYPE-PROP.LSP                              */
#include <ecl/ecl-cmp.h>
#include "cmp/cmptype-prop.eclh"
/*	function definition for INFER-ARG-AND-RETURN-TYPES            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1infer_arg_and_return_types(cl_narg narg, cl_object v1fname, cl_object v2forms, ...)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v3env;
  va_list args; va_start(args,v2forms);
  {
   int i = 2;
   if (i >= narg) {
    v3env = ecl_symbol_value(VV[0]);
   } else {
    i++;
    v3env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v4;
   cl_object v5found;
   cl_object v6arg_types;
   cl_object v7return_type;
   v4 = ecl_gethash_safe(v1fname,ecl_symbol_value(VV[1]),ECL_NIL);
   v5found = v4;
   v6arg_types = ECL_NIL;
   v7return_type = VV[2];
   if (Null(v5found)) { goto L7; }
   {
    cl_object v8;
    cl_object v9;
    v8 = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v2forms))) FEtype_error_list(v2forms);
    v9 = v2forms;
    {
     cl_object v10;
     cl_object v11;
     v10 = ecl_list1(ECL_NIL);
     v11 = v10;
L16:;
     if (!(ecl_endp(v9))) { goto L18; }
     goto L17;
L18:;
     v8 = _ecl_car(v9);
     {
      cl_object v12;
      v12 = _ecl_cdr(v9);
      if (ecl_unlikely(!ECL_LISTP(v12))) FEtype_error_list(v12);
      v9 = v12;
     }
     if (ecl_unlikely(ECL_ATOM(v11))) FEtype_error_cons(v11);
     T1 = v11;
     T2 = ecl_function_dispatch(cl_env_copy,VV[14])(1, v8) /*  LOCATION-PRIMARY-TYPE */;
     v11 = ecl_list1(T2);
     (ECL_CONS_CDR(T1)=v11,T1);
     goto L16;
L17:;
     T0 = ecl_cdr(v10);
     goto L10;
    }
   }
L10:;
   value0 = cl_apply(3, v5found, v1fname, T0);
   v6arg_types = value0;
   {
    const int v8 = cl_env_copy->nvalues;
    cl_object v9;
    v9 = (v8<=1)? ECL_NIL : cl_env_copy->values[1];
    v7return_type = v9;
   }
   goto L6;
L7:;
   value0 = ecl_function_dispatch(cl_env_copy,VV[15])(2, v1fname, v3env) /*  GET-ARG-TYPES */;
   v6arg_types = value0;
   {
    const int v8 = cl_env_copy->nvalues;
    cl_object v9;
    v9 = (v8<=1)? ECL_NIL : cl_env_copy->values[1];
    v5found = v9;
   }
   if (Null(value0)) { goto L6; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[16])(1, v1fname) /*  GET-RETURN-TYPE */;
   if ((value0)!=ECL_NIL) { goto L36; }
   goto L34;
L36:;
   v7return_type = value0;
   goto L34;
L34:;
L6:;
   cl_env_copy->nvalues = 3;
   cl_env_copy->values[2] = v5found;
   cl_env_copy->values[1] = v7return_type;
   cl_env_copy->values[0] = v6arg_types;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for ENFORCE-TYPES                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2enforce_types(cl_object v1fname, cl_object v2arg_types, cl_object v3arguments)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4types;
   cl_object v5args;
   cl_object v6i;
   cl_object v7in_optionals;
   v4types = v2arg_types;
   v5args = v3arguments;
   v6i = ecl_make_fixnum(1);
   v7in_optionals = ECL_NIL;
   goto L7;
L6:;
   {
    cl_object v8expected_type;
    v8expected_type = ecl_car(v4types);
    if (!((v8expected_type)==(ECL_SYM("*",18)))) { goto L16; }
    goto L13;
    goto L14;
L16:;
    goto L14;
L14:;
    if (!((v8expected_type)==(ECL_SYM("&REST",12)))) { goto L20; }
    goto L13;
    goto L18;
L20:;
    goto L18;
L18:;
    if (!((v8expected_type)==(ECL_SYM("&KEY",10)))) { goto L24; }
    goto L13;
    goto L22;
L24:;
    goto L22;
L22:;
    if (!((v8expected_type)==(ECL_SYM("&ALLOW-OTHER-KEYS",6)))) { goto L11; }
    goto L12;
L13:;
L12:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
L11:;
    if (!((v8expected_type)==(ECL_SYM("&OPTIONAL",11)))) { goto L27; }
    if (Null(v7in_optionals)) { goto L29; }
    ecl_function_dispatch(cl_env_copy,VV[18])(3, _ecl_static_1, v1fname, v2arg_types) /*  CMPWARN */;
L29:;
    v7in_optionals = ECL_T;
    v4types = ecl_cdr(v4types);
    goto L9;
L27:;
    if (!(ecl_endp(v5args))) { goto L34; }
    if ((v7in_optionals)!=ECL_NIL) { goto L36; }
    ecl_function_dispatch(cl_env_copy,VV[18])(2, _ecl_static_2, v1fname) /*  CMPWARN */;
L36:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
L34:;
    {
     cl_object v9value;
     cl_object v10actual_type;
     cl_object v11intersection;
     v9value = ecl_car(v5args);
     v10actual_type = ecl_function_dispatch(cl_env_copy,VV[14])(1, v9value) /*  LOCATION-PRIMARY-TYPE */;
     v11intersection = ecl_function_dispatch(cl_env_copy,VV[19])(2, v10actual_type, v8expected_type) /*  TYPE-AND */;
     if ((v11intersection)!=ECL_NIL) { goto L41; }
     ecl_function_dispatch(cl_env_copy,VV[20])(5, _ecl_static_3, v6i, v1fname, v10actual_type, v8expected_type) /*  CMPWARN-STYLE */;
L41:;
     T0 = ecl_function_dispatch(cl_env_copy,VV[21])(1, ECL_SYM("SAFETY",734)) /*  CMP-ENV-OPTIMIZATION */;
     if (!(ecl_zerop(T0))) { goto L9; }
     ecl_structure_set(v9value,VV[8],1,v11intersection);
    }
   }
L9:;
   v4types = ecl_cdr(v4types);
   v5args = ecl_cdr(v5args);
   v6i = ecl_one_plus(v6i);
L7:;
   if (ecl_endp(v4types)) { goto L50; }
   goto L6;
L50:;
   if (Null(v4types)) { goto L52; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[18])(2, _ecl_static_4, v1fname) /*  CMPWARN */;
   return value0;
L52:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for PROPAGATE-TYPES                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3propagate_types(cl_object v1fname, cl_object v2forms)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4;                                  /*  ARG-TYPES       */
   cl_object v5;                                  /*  RETURN-TYPE     */
   cl_object v6;                                  /*  FOUND           */
   value0 = L1infer_arg_and_return_types(2, v1fname, v2forms);
   v4 = value0;
   {
    const int v7 = cl_env_copy->nvalues;
    cl_object v8;
    v8 = (v7<=1)? ECL_NIL : cl_env_copy->values[1];
    v5 = v8;
    v8 = (v7<=2)? ECL_NIL : cl_env_copy->values[2];
    v6 = v8;
   }
   if (Null(v6)) { goto L2; }
   L2enforce_types(v1fname, v4, v2forms);
L2:;
   value0 = v5;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function DEF-TYPE-PROPAGATOR                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC4def_type_propagator(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4fname;
   cl_object v5lambda_list;
   cl_object v6body;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v7;
    v7 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4fname = v7;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v7;
    v7 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5lambda_list = v7;
   }
   v6body = v3;
   if ((ecl_memql(ECL_SYM("&REST",12),v5lambda_list))!=ECL_NIL) { goto L15; }
   {
    cl_object v7var;
    v7var = cl_gensym(0);
    T0 = cl_list(2, ECL_SYM("&REST",12), v7var);
    v5lambda_list = ecl_append(v5lambda_list,T0);
    T0 = cl_list(2, ECL_SYM("IGNORABLE",427), v7var);
    T1 = cl_list(2, ECL_SYM("DECLARE",274), T0);
    v6body = CONS(T1,v6body);
   }
L15:;
   T0 = cl_list(2, ECL_SYM("QUOTE",679), v4fname);
   T1 = cl_list(3, ECL_SYM("GETHASH",413), T0, VV[1]);
   T2 = ecl_car(v5lambda_list);
   T3 = cl_list(2, ECL_SYM("IGNORABLE",427), T2);
   T4 = cl_list(2, ECL_SYM("DECLARE",274), T3);
   T5 = cl_listX(4, ECL_SYM("LAMBDA",452), v5lambda_list, T4, v6body);
   T6 = cl_list(2, ECL_SYM("FUNCTION",396), T5);
   value0 = cl_list(3, ECL_SYM("SETF",750), T1, T6);
   return value0;
  }
 }
}
/*	function definition for COPY-TYPE-PROPAGATOR                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5copy_type_propagator(cl_object v1orig, cl_object v2dest_list)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3function;
   v3function = ecl_gethash_safe(v1orig,ecl_symbol_value(VV[1]),ECL_NIL);
   {
    cl_object v4name;
    cl_object v5;
    v4name = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v2dest_list))) FEtype_error_list(v2dest_list);
    v5 = v2dest_list;
L5:;
    if (!(ecl_endp(v5))) { goto L7; }
    goto L6;
L7:;
    v4name = _ecl_car(v5);
    {
     cl_object v6;
     v6 = _ecl_cdr(v5);
     if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
     v5 = v6;
    }
    if (Null(v3function)) { goto L15; }
    si_hash_set(v4name, ecl_symbol_value(VV[1]), v3function);
L15:;
    goto L5;
L6:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}

#include "cmp/cmptype-prop.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclQV7Nhk42G83l9_9ExTOE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPTYPE-PROP.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclQV7Nhk42G83l9_9ExTOE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[13]);                           /*  INFER-ARG-AND-RETURN-TYPES */
 ecl_cmp_defun(VV[17]);                           /*  ENFORCE-TYPES   */
 ecl_cmp_defun(VV[22]);                           /*  PROPAGATE-TYPES */
 ecl_cmp_defmacro(VV[23]);                        /*  DEF-TYPE-PROPAGATOR */
 ecl_cmp_defun(VV[24]);                           /*  COPY-TYPE-PROPAGATOR */
}
