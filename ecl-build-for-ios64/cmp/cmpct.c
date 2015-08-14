/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPCT.LSP                                     */
#include <ecl/ecl-cmp.h>
#include "cmp/cmpct.eclh"
/*	function definition for C1CONSTANT-VALUE                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1c1constant_value(cl_narg narg, cl_object v1val, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2always;
  cl_object v3only_small_values;
  ecl_va_list args; ecl_va_start(args,v1val,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L1c1constant_valuekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v2always = keyvars[0];
   v3only_small_values = keyvars[1];
  }
  {
   cl_object v4;
   {
    cl_object v5x;
    v5x = ecl_assql(v1val,ecl_symbol_value(VV[0]));
    if (Null(v5x)) { goto L3; }
    cl_set(VV[1],cl_adjoin(2, _ecl_static_1, ecl_symbol_value(VV[1])));
    v5x = ecl_cdr(v5x);
    if (!(ECL_LISTP(v5x))) { goto L9; }
    v4 = ecl_function_dispatch(cl_env_copy,VV[12])(1, v5x) /*  C1EXPR */;
    goto L1;
L9:;
    v4 = v5x;
    goto L1;
L3:;
    v4 = ECL_NIL;
   }
L1:;
   if (Null(v4)) { goto L11; }
   value0 = v4;
   cl_env_copy->nvalues = 1;
   return value0;
L11:;
   if (!((v1val)==(ECL_NIL))) { goto L13; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[13])(0) /*  C1NIL    */;
   return value0;
L13:;
   if (!((v1val)==(ECL_T))) { goto L15; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[14])(0) /*  C1T      */;
   return value0;
L15:;
   if (!(ECL_FIXNUMP(v1val))) { goto L17; }
   T0 = cl_list(2, VV[3], v1val);
   value0 = ecl_function_dispatch(cl_env_copy,VV[15])(5, ECL_SYM("LOCATION",1763), ECL_SYM("TYPE",1318), ECL_SYM("FIXNUM",372), VV[2], T0) /*  MAKE-C1FORM* */;
   return value0;
L17:;
   if (!(ECL_CHARACTERP(v1val))) { goto L19; }
   T0 = cl_char_code(v1val);
   T1 = cl_list(2, VV[4], T0);
   value0 = ecl_function_dispatch(cl_env_copy,VV[15])(5, ECL_SYM("LOCATION",1763), ECL_SYM("TYPE",1318), ECL_SYM("CHARACTER",222), VV[2], T1) /*  MAKE-C1FORM* */;
   return value0;
L19:;
   if (!(ECL_DOUBLE_FLOAT_P(v1val))) { goto L21; }
   if (Null(si_float_nan_p(v1val))) { goto L23; }
   if ((v3only_small_values)!=ECL_NIL) { goto L23; }
   ecl_function_dispatch(cl_env_copy,VV[16])(2, _ecl_static_2, v1val) /*  CMPERR */;
L23:;
   T0 = ecl_function_dispatch(cl_env_copy,VV[17])(1, v1val) /*  ADD-OBJECT */;
   T1 = cl_list(3, VV[5], v1val, T0);
   value0 = ecl_function_dispatch(cl_env_copy,VV[15])(5, ECL_SYM("LOCATION",1763), ECL_SYM("TYPE",1318), ECL_SYM("DOUBLE-FLOAT",315), VV[2], T1) /*  MAKE-C1FORM* */;
   return value0;
L21:;
   if (!(ECL_SINGLE_FLOAT_P(v1val))) { goto L26; }
   if (Null(si_float_nan_p(v1val))) { goto L28; }
   if ((v3only_small_values)!=ECL_NIL) { goto L28; }
   ecl_function_dispatch(cl_env_copy,VV[16])(2, _ecl_static_2, v1val) /*  CMPERR */;
L28:;
   T0 = ecl_function_dispatch(cl_env_copy,VV[17])(1, v1val) /*  ADD-OBJECT */;
   T1 = cl_list(3, VV[6], v1val, T0);
   value0 = ecl_function_dispatch(cl_env_copy,VV[15])(5, ECL_SYM("LOCATION",1763), ECL_SYM("TYPE",1318), ECL_SYM("SINGLE-FLOAT",778), VV[2], T1) /*  MAKE-C1FORM* */;
   return value0;
L26:;
   if (!(ECL_LONG_FLOAT_P(v1val))) { goto L31; }
   if (Null(si_float_nan_p(v1val))) { goto L33; }
   if ((v3only_small_values)!=ECL_NIL) { goto L33; }
   ecl_function_dispatch(cl_env_copy,VV[16])(2, _ecl_static_2, v1val) /*  CMPERR */;
L33:;
   T0 = ecl_function_dispatch(cl_env_copy,VV[17])(1, v1val) /*  ADD-OBJECT */;
   T1 = cl_list(3, VV[7], v1val, T0);
   value0 = ecl_function_dispatch(cl_env_copy,VV[15])(5, ECL_SYM("LOCATION",1763), ECL_SYM("TYPE",1318), ECL_SYM("LONG-FLOAT",508), VV[2], T1) /*  MAKE-C1FORM* */;
   return value0;
L31:;
   if (Null(v3only_small_values)) { goto L36; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L36:;
   if (Null(v2always)) { goto L38; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[18])(1, v1val) /*  OBJECT-TYPE */;
   T1 = ecl_function_dispatch(cl_env_copy,VV[17])(1, v1val) /*  ADD-OBJECT */;
   value0 = ecl_function_dispatch(cl_env_copy,VV[15])(5, ECL_SYM("LOCATION",1763), ECL_SYM("TYPE",1318), T0, VV[2], T1) /*  MAKE-C1FORM* */;
   return value0;
L38:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}

#include "cmp/cmpct.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclvzC9oYb3LT2j9_HErtVE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPCT.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclvzC9oYb3LT2j9_HErtVE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 si_Xmake_special(VV[0]);
 cl_set(VV[0],ECL_NIL);
 ecl_cmp_defun(VV[9]);                            /*  C1CONSTANT-VALUE */
 {
  cl_object T0, T1, T2, T3;
 VVtemp[22]= CONS(cl_core.lisp_package,ECL_NIL);
 if (ecl_unlikely(ECL_ATOM(VVtemp[22]))) FEtype_error_cons(VVtemp[22]);
 T0 = VVtemp[22];
 (ECL_CONS_CDR(T0)=VVtemp[23],T0);
 VVtemp[24]= CONS(cl_core.user_package,ECL_NIL);
 if (ecl_unlikely(ECL_ATOM(VVtemp[24]))) FEtype_error_cons(VVtemp[24]);
 T0 = VVtemp[24];
 (ECL_CONS_CDR(T0)=VVtemp[25],T0);
 VVtemp[26]= CONS(cl_core.keyword_package,ECL_NIL);
 if (ecl_unlikely(ECL_ATOM(VVtemp[26]))) FEtype_error_cons(VVtemp[26]);
 T0 = VVtemp[26];
 (ECL_CONS_CDR(T0)=VVtemp[27],T0);
 VVtemp[28]= CONS(cl_core.clos_package,ECL_NIL);
 if (ecl_unlikely(ECL_ATOM(VVtemp[28]))) FEtype_error_cons(VVtemp[28]);
 T0 = VVtemp[28];
 (ECL_CONS_CDR(T0)=VVtemp[29],T0);
 VVtemp[30]= CONS(cl_core.mp_package,ECL_NIL);
 if (ecl_unlikely(ECL_ATOM(VVtemp[30]))) FEtype_error_cons(VVtemp[30]);
 T0 = VVtemp[30];
 (ECL_CONS_CDR(T0)=VVtemp[31],T0);
 {
  cl_object v1;
  T0 = cl_listX(28, VVtemp[0], VVtemp[1], VVtemp[2], VVtemp[3], VVtemp[4], VVtemp[5], VVtemp[6], VVtemp[7], VVtemp[8], VVtemp[9], VVtemp[10], VVtemp[11], VVtemp[12], VVtemp[13], VVtemp[14], VVtemp[15], VVtemp[16], VVtemp[17], VVtemp[18], VVtemp[19], VVtemp[20], VVtemp[21], VVtemp[22], VVtemp[24], VVtemp[26], VVtemp[28], VVtemp[30], VVtemp[32]);
  v1 = cl_reverse(T0);
  {
   cl_object v2;
   cl_object v3;
   v2 = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v1))) FEtype_error_list(v1);
   v3 = v1;
L37:;
   if (!(ecl_endp(v3))) { goto L39; }
   goto L38;
L39:;
   v2 = _ecl_car(v3);
   {
    cl_object v4;
    v4 = _ecl_cdr(v3);
    if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
    v3 = v4;
   }
   {
    cl_object v4name;
    cl_object v5c_value;
    v4name = ecl_car(v2);
    v5c_value = ecl_cadr(v2);
    if (!(ECL_SYMBOLP(v4name))) { goto L52; }
    {
     cl_object v6value;
     cl_object v7type;
     v6value = cl_symbol_value(v4name);
     T1 = cl_type_of(v6value);
     v7type = ecl_function_dispatch(cl_env_copy,VV[19])(1, T1) /*  LISP-TYPE->REP-TYPE */;
     T1 = cl_listX(6, ECL_SYM("C-INLINE",1973), ECL_NIL, ECL_NIL, v7type, v5c_value, VVtemp[33]);
     T0 = CONS(v6value,T1);
     goto L51;
    }
L52:;
    if (!(floatp(v4name))) { goto L56; }
    {
     cl_object v8type;
     cl_object v9loc_type;
     cl_object v10location;
     v8type = cl_type_of(v4name);
     if (!((v8type)==(ECL_SYM("SINGLE-FLOAT",778)))) { goto L60; }
     v9loc_type = VV[6];
     goto L59;
L60:;
     if (!((v8type)==(ECL_SYM("DOUBLE-FLOAT",315)))) { goto L62; }
     v9loc_type = VV[5];
     goto L59;
L62:;
     if (!((v8type)==(ECL_SYM("LONG-FLOAT",508)))) { goto L64; }
     v9loc_type = VV[7];
     goto L59;
L64:;
     v9loc_type = ECL_NIL;
L59:;
     v10location = ecl_function_dispatch(cl_env_copy,VV[20])(4, ECL_SYM("LOCATION",999), v5c_value, ECL_SYM("VALUE",1945), v4name) /*  MAKE-VV */;
     T1 = cl_list(3, v9loc_type, v4name, v10location);
     T2 = ecl_function_dispatch(cl_env_copy,VV[15])(5, ECL_SYM("LOCATION",1763), ECL_SYM("TYPE",1318), v8type, VV[2], T1) /*  MAKE-C1FORM* */;
     T0 = CONS(v4name,T2);
     goto L51;
    }
L56:;
    T1 = cl_type_of(v4name);
    T2 = ecl_function_dispatch(cl_env_copy,VV[20])(4, ECL_SYM("LOCATION",999), v5c_value, ECL_SYM("VALUE",1945), v4name) /*  MAKE-VV */;
    T3 = ecl_function_dispatch(cl_env_copy,VV[15])(5, ECL_SYM("LOCATION",1763), ECL_SYM("TYPE",1318), T1, VV[2], T2) /*  MAKE-C1FORM* */;
    T0 = CONS(v4name,T3);
L51:;
    cl_set(VV[0],CONS(T0,ecl_symbol_value(VV[0])));
   }
   goto L37;
L38:;
   goto L32;
  }
 }
L32:;
 }
}
