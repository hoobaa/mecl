/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPTYPE-ASSERT.LSP                            */
#include <ecl/ecl-cmp.h>
#include "cmp/cmptype-assert.eclh"
/*	function definition for C1COMPILER-TYPECASE                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1c1compiler_typecase(cl_object v1args)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2var_name;
   cl_object v3var;
   cl_object v4first_case;
   {
    cl_object v5;
    v5 = v1args;
    if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
    if (Null(v5)) { goto L5; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L5:;
    v2var_name = v5;
   }
   v3var = ecl_function_dispatch(cl_env_copy,VV[21])(1, v2var_name) /*  C1VREF */;
   v4first_case = ecl_car(v1args);
   T0 = ecl_function_dispatch(cl_env_copy,VV[22])(1, v3var) /*  VAR-TYPE */;
   T1 = ecl_car(v4first_case);
   if (Null(cl_subtypep(2, T0, T1))) { goto L13; }
   T0 = ecl_cdr(v4first_case);
   value0 = ecl_function_dispatch(cl_env_copy,VV[23])(1, T0) /*  C1PROGN */;
   return value0;
L13:;
   {
    cl_object v5types;
    cl_object v6expressions;
    v5types = ECL_NIL;
    {
     cl_object v7type;
     cl_object v8forms;
     cl_object v9;
     v7type = ECL_NIL;
     v8forms = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v1args))) FEtype_error_list(v1args);
     v9 = v1args;
     {
      cl_object v10c1form;
      v10c1form = ECL_NIL;
      {
       cl_object v11c1form_type;
       v11c1form_type = ECL_NIL;
       {
        cl_object v12;
        cl_object v13;
        v12 = ecl_list1(ECL_NIL);
        v13 = v12;
L25:;
        if (!(ecl_endp(v9))) { goto L27; }
        goto L26;
L27:;
        {
         cl_object v14;
         v14 = _ecl_car(v9);
         v7type = ecl_car(v14);
         v14 = ecl_cdr(v14);
         v8forms = v14;
        }
        {
         cl_object v14;
         v14 = _ecl_cdr(v9);
         if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
         v9 = v14;
        }
        v10c1form = ecl_function_dispatch(cl_env_copy,VV[23])(1, v8forms) /*  C1PROGN */;
        v11c1form_type = ecl_function_dispatch(cl_env_copy,VV[24])(1, v10c1form) /*  C1FORM-PRIMARY-TYPE */;
        v5types = CONS(v11c1form_type,v5types);
        if (ecl_unlikely(ECL_ATOM(v13))) FEtype_error_cons(v13);
        T0 = v13;
        T1 = cl_list(2, v7type, v10c1form);
        v13 = ecl_list1(T1);
        (ECL_CONS_CDR(T0)=v13,T0);
        goto L25;
L26:;
        v6expressions = ecl_cdr(v12);
        goto L16;
       }
      }
     }
    }
L16:;
    T0 = ecl_fdefinition(VV[25]);
    T1 = cl_reduce(2, T0, v5types);
    value0 = ecl_function_dispatch(cl_env_copy,VV[26])(6, ECL_SYM("COMPILER-TYPECASE",1780), ECL_SYM("TYPE",1318), T1, VV[0], v3var, v6expressions) /*  MAKE-C1FORM* */;
    return value0;
   }
  }
 }
}
/*	function definition for C2COMPILER-TYPECASE                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2c2compiler_typecase(cl_object v1c1form, cl_object v2var, cl_object v3expressions)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4var_type;
   v4var_type = ecl_function_dispatch(cl_env_copy,VV[22])(1, v2var) /*  VAR-TYPE */;
   {
    cl_object v5type;
    cl_object v6form;
    cl_object v7;
    v5type = ECL_NIL;
    v6form = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v3expressions))) FEtype_error_list(v3expressions);
    v7 = v3expressions;
L6:;
    if (!(ecl_endp(v7))) { goto L8; }
    goto L7;
L8:;
    {
     cl_object v8;
     v8 = _ecl_car(v7);
     v5type = ecl_car(v8);
     v8 = ecl_cdr(v8);
     v6form = ecl_car(v8);
    }
    {
     cl_object v8;
     v8 = _ecl_cdr(v7);
     if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
     v7 = v8;
    }
    if (!(ecl_eql(v5type,ECL_T))) { goto L27; }
    goto L23;
    goto L25;
L27:;
    goto L25;
L25:;
    if (!((v5type)==(ECL_SYM("OTHERWISE",615)))) { goto L30; }
    goto L23;
    goto L24;
L30:;
    goto L24;
L24:;
    if (Null(cl_subtypep(2, v4var_type, v5type))) { goto L21; }
    goto L22;
L23:;
L22:;
    value0 = ecl_function_dispatch(cl_env_copy,VV[28])(1, v6form) /*  C2EXPR */;
    return value0;
L21:;
    goto L6;
L7:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for SIMPLE-TYPE-ASSERTION                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3simple_type_assertion(cl_object v1value, cl_object v2type, cl_object v3env)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4simple_form;
   T0 = ecl_assql(v2type,ecl_symbol_value(VV[5]));
   v4simple_form = ecl_cdr(T0);
   if (Null(v4simple_form)) { goto L3; }
   T0 = ecl_list1(v1value);
   value0 = cl_listX(6, ECL_SYM("C-INLINE",1973), T0, VV[6], ECL_SYM("VOID",1381), v4simple_form, VV[7]);
   return value0;
L3:;
   T0 = cl_list(2, ECL_SYM("QUOTE",679), v2type);
   T1 = cl_list(3, ECL_SYM("TYPEP",875), v1value, T0);
   T2 = cl_list(2, ECL_SYM("QUOTE",679), v2type);
   T3 = cl_list(3, T1, T2, v1value);
   value0 = cl_listX(3, ECL_SYM("C-INLINE",1973), T3, VV[8]);
   return value0;
  }
 }
}
/*	function definition for EXPAND-TYPE-ASSERTION                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4expand_type_assertion(cl_object v1value, cl_object v2type, cl_object v3env, cl_object v4compulsory)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_SYMBOLP(v1value))) { goto L3; }
  if ((ecl_function_dispatch(cl_env_copy,VV[31])(1, v1value) /*  SPECIAL-VARIABLE-P */)!=ECL_NIL) { goto L3; }
  if (Null(ecl_function_dispatch(cl_env_copy,VV[32])(1, v1value) /*  SYMBOL-MACRO-P */)) { goto L1; }
  goto L2;
L3:;
L2:;
  T0 = cl_list(2, VV[10], v1value);
  T1 = ecl_list1(T0);
  T2 = L4expand_type_assertion(VV[10], v2type, v3env, v4compulsory);
  value0 = cl_list(4, ECL_SYM("LET*",478), T1, VV[11], T2);
  return value0;
L1:;
  if (Null(v4compulsory)) { goto L6; }
  value0 = L3simple_type_assertion(v1value, v2type, v3env);
  return value0;
L6:;
  T0 = ecl_list1(v2type);
  T1 = L3simple_type_assertion(v1value, v2type, v3env);
  T2 = cl_list(2, ECL_T, T1);
  value0 = cl_list(4, ECL_SYM("COMPILER-TYPECASE",1780), v1value, T0, T2);
  return value0;
 }
}
/*	function definition for C1CHECKED-VALUE                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5c1checked_value(cl_object v1args)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2type;
   cl_object v3value;
   cl_object v4form;
   cl_object v5form_type;
   cl_object v6and_type;
   {
    cl_object v7;
    v7 = v1args;
    if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
    if (Null(v7)) { goto L5; }
    {
     cl_object v8;
     v8 = ECL_CONS_CDR(v7);
     v1args = v8;
     v7 = ECL_CONS_CAR(v7);
    }
L5:;
    v2type = v7;
   }
   {
    cl_object v7;
    v7 = v1args;
    if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
    if (Null(v7)) { goto L15; }
    {
     cl_object v8;
     v8 = ECL_CONS_CDR(v7);
     v1args = v8;
     v7 = ECL_CONS_CAR(v7);
    }
L15:;
    v3value = v7;
   }
   v4form = ECL_NIL;
   v5form_type = ECL_NIL;
   v6and_type = ECL_NIL;
   if ((ecl_function_dispatch(cl_env_copy,VV[34])(1, v1args) /*  TRIVIAL-TYPE-P */)!=ECL_NIL) { goto L26; }
   if ((ecl_function_dispatch(cl_env_copy,VV[35])(0) /*  POLICY-TYPE-ASSERTIONS */)!=ECL_NIL) { goto L24; }
   goto L25;
L26:;
L25:;
   value0 = v3value;
   cl_env_copy->nvalues = 1;
   return value0;
L24:;
   if (!(ECL_CONSP(v2type))) { goto L28; }
   T0 = ecl_car(v2type);
   if (!((T0)==(ECL_SYM("VALUES",895)))) { goto L28; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[36])(1, v2type) /*  VALUES-TYPE-PRIMARY-TYPE */;
   v1args = cl_list(2, T0, v3value);
   goto TTL;
L28:;
   if (Null(ecl_function_dispatch(cl_env_copy,VV[37])(0) /*  POLICY-EVALUATE-FORMS */)) { goto L33; }
   if (Null(cl_constantp(1, v3value))) { goto L33; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[38])(1, v3value) /*  CMP-EVAL */;
   if ((cl_typep(2, T0, v2type))!=ECL_NIL) { goto L36; }
   ecl_function_dispatch(cl_env_copy,VV[39])(3, _ecl_static_1, v3value, v2type) /*  CMPWARN */;
L36:;
   value0 = v3value;
   cl_env_copy->nvalues = 1;
   return value0;
L33:;
   v4form = ecl_function_dispatch(cl_env_copy,VV[40])(1, v3value) /*  C1EXPR */;
   v5form_type = ecl_function_dispatch(cl_env_copy,VV[24])(1, v4form) /*  C1FORM-PRIMARY-TYPE */;
   v6and_type = ecl_function_dispatch(cl_env_copy,VV[41])(2, v5form_type, v2type) /*  TYPE-AND */;
   if (!((v6and_type)==(v5form_type))) { goto L38; }
   value0 = v4form;
   cl_env_copy->nvalues = 1;
   return value0;
L38:;
   if (!(v6and_type==ECL_NIL)) { goto L46; }
   ecl_function_dispatch(cl_env_copy,VV[39])(3, _ecl_static_2, v3value, v2type) /*  CMPWARN */;
   value0 = v4form;
   cl_env_copy->nvalues = 1;
   return value0;
L46:;
   ecl_function_dispatch(cl_env_copy,VV[42])(3, _ecl_static_3, v3value, v2type) /*  CMPNOTE */;
   {
    cl_object v7full_check;
    T0 = cl_list(2, VV[13], v3value);
    T1 = ecl_list1(T0);
    T2 = L4expand_type_assertion(VV[13], v2type, ecl_symbol_value(VV[15]), ECL_NIL);
    T3 = cl_list(3, ECL_SYM("TRULY-THE",1949), v2type, VV[13]);
    v7full_check = cl_list(5, ECL_SYM("LET*",478), T1, VV[14], T2, T3);
    T0 = ecl_function_dispatch(cl_env_copy,VV[40])(1, v7full_check) /*  C1EXPR */;
    value0 = ecl_function_dispatch(cl_env_copy,VV[26])(7, ECL_SYM("CHECKED-VALUE",1950), ECL_SYM("TYPE",1318), v2type, VV[0], v2type, v4form, T0) /*  MAKE-C1FORM* */;
    return value0;
   }
  }
 }
}
/*	function definition for C2CHECKED-VALUE                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6c2checked_value(cl_object v1c1form, cl_object v2type, cl_object v3value, cl_object v4let_form)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T1 = ecl_function_dispatch(cl_env_copy,VV[24])(1, v3value) /*  C1FORM-PRIMARY-TYPE */;
  if (Null(cl_subtypep(2, T1, v2type))) { goto L2; }
  T0 = v3value;
  goto L1;
L2:;
  T0 = v4let_form;
L1:;
  value0 = ecl_function_dispatch(cl_env_copy,VV[28])(1, T0) /*  C2EXPR */;
  return value0;
 }
}
/*	local function OPTIONAL-TYPE-ASSERTION                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC7optional_type_assertion(cl_object v1, cl_object v2env)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4value;
   cl_object v5type;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4value = v6;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5type = v6;
   }
   if (Null(v3)) { goto L14; }
   si_dm_too_many_arguments(v1);
L14:;
   if (Null(ecl_function_dispatch(cl_env_copy,VV[35])(1, v2env) /*  POLICY-TYPE-ASSERTIONS */)) { goto L16; }
   if ((ecl_function_dispatch(cl_env_copy,VV[34])(1, v5type) /*  TRIVIAL-TYPE-P */)!=ECL_NIL) { goto L16; }
   ecl_function_dispatch(cl_env_copy,VV[42])(3, _ecl_static_4, v4value, v5type) /*  CMPNOTE */;
   value0 = cl_list(3, ECL_SYM("CHECKED-VALUE",1950), v5type, v4value);
   return value0;
L16:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function TYPE-ASSERTION                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC8type_assertion(cl_object v1, cl_object v2env)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4value;
   cl_object v5type;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4value = v6;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5type = v6;
   }
   if (Null(v3)) { goto L14; }
   si_dm_too_many_arguments(v1);
L14:;
   ecl_function_dispatch(cl_env_copy,VV[42])(3, _ecl_static_4, v4value, v5type) /*  CMPNOTE */;
   if ((ecl_function_dispatch(cl_env_copy,VV[34])(1, v5type) /*  TRIVIAL-TYPE-P */)!=ECL_NIL) { goto L17; }
   value0 = L4expand_type_assertion(v4value, v5type, v2env, ECL_T);
   return value0;
L17:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}

#include "cmp/cmptype-assert.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclZhgT5jTjpnrn9_KLptVE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPTYPE-ASSERT.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclZhgT5jTjpnrn9_KLptVE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[20]);                           /*  C1COMPILER-TYPECASE */
 ecl_cmp_defun(VV[27]);                           /*  C2COMPILER-TYPECASE */
 si_Xmake_constant(VV[5], VVtemp[0]);
 ecl_cmp_defun(VV[29]);                           /*  SIMPLE-TYPE-ASSERTION */
 ecl_cmp_defun(VV[30]);                           /*  EXPAND-TYPE-ASSERTION */
 ecl_cmp_defun(VV[33]);                           /*  C1CHECKED-VALUE */
 ecl_cmp_defun(VV[43]);                           /*  C2CHECKED-VALUE */
 ecl_cmp_defmacro(VV[44]);                        /*  OPTIONAL-TYPE-ASSERTION */
 ecl_cmp_defmacro(VV[45]);                        /*  TYPE-ASSERTION  */
}
