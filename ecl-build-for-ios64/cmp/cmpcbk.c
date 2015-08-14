/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPCBK.LSP                                    */
#include <ecl/ecl-cmp.h>
#include "cmp/cmpcbk.eclh"
/*	function definition for C1-DEFCALLBACK                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1c1_defcallback(cl_object v1args)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   cl_object v3name;
   cl_object v4return_type;
   cl_object v5arg_list;
   v2 = v1args;
   if (!(v2==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1args);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v2);
    v2 = ecl_cdr(v2);
    v3name = v6;
   }
   if (!(v2==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1args);
L9:;
   {
    cl_object v6;
    v6 = ecl_car(v2);
    v2 = ecl_cdr(v2);
    v4return_type = v6;
   }
   if (!(v2==ECL_NIL)) { goto L15; }
   si_dm_too_few_arguments(v1args);
L15:;
   {
    cl_object v6;
    v6 = ecl_car(v2);
    v2 = ecl_cdr(v2);
    v5arg_list = v6;
   }
   {
    cl_object v6;
    cl_object v7;
    cl_object v8;
    cl_object v9arg_types;
    cl_object v10arg_type_constants;
    cl_object v11arg_variables;
    {
     cl_fixnum v12;
     v12 = ecl_length(ecl_symbol_value(VV[0]));
     v6 = cl_format(3, ECL_NIL, _ecl_static_1, ecl_make_fixnum(v12));
    }
    if (!(ECL_CONSP(v3name))) { goto L22; }
    v7 = ecl_car(v3name);
    goto L21;
L22:;
    v7 = v3name;
L21:;
    if (!(ECL_CONSP(v3name))) { goto L25; }
    v8 = ecl_cadr(v3name);
    goto L24;
L25:;
    v8 = ECL_SYM("CDECL",1593);
L24:;
    v9arg_types = ECL_NIL;
    v10arg_type_constants = ECL_NIL;
    v11arg_variables = ECL_NIL;
    {
     cl_object v12;
     v12 = v5arg_list;
     goto L34;
L33:;
     {
      cl_object v13i;
      v13i = ecl_car(v12);
      if (ECL_CONSP(v13i)) { goto L38; }
      ecl_function_dispatch(cl_env_copy,VV[11])(2, _ecl_static_2, v13i) /*  CMPERR */;
L38:;
      T0 = ecl_car(v13i);
      v11arg_variables = CONS(T0,v11arg_variables);
      {
       cl_object v14type;
       v14type = ecl_cadr(v13i);
       T0 = ecl_cadr(v13i);
       v9arg_types = CONS(T0,v9arg_types);
       if (Null(si_foreign_elt_type_p(v14type))) { goto L48; }
       T0 = L2foreign_elt_type_code(v14type);
       goto L47;
L48:;
       T0 = ecl_function_dispatch(cl_env_copy,VV[12])(1, v14type) /*  ADD-OBJECT */;
L47:;
       v10arg_type_constants = CONS(T0,v10arg_type_constants);
      }
     }
     v12 = ecl_cdr(v12);
L34:;
     if (Null(v12)) { goto L52; }
     goto L33;
L52:;
    }
    T0 = ecl_function_dispatch(cl_env_copy,VV[12])(1, v7) /*  ADD-OBJECT */;
    T1 = cl_reverse(v9arg_types);
    T2 = cl_reverse(v10arg_type_constants);
    T3 = cl_list(7, v7, v6, T0, v4return_type, T1, T2, v8);
    cl_set(VV[0],CONS(T3,ecl_symbol_value(VV[0])));
    T0 = cl_reverse(v11arg_variables);
    T1 = cl_listX(4, ECL_SYM("DEFUN",289), v7, T0, v2);
    T2 = cl_list(2, ECL_SYM("QUOTE",679), v7);
    T3 = cl_format(3, ECL_NIL, _ecl_static_3, v6);
    T4 = cl_listX(6, ECL_SYM("C-INLINE",1973), ECL_NIL, ECL_NIL, ECL_SYM("OBJECT",1278), T3, VV[1]);
    T5 = cl_list(2, ECL_SYM("LIST",481), T4);
    T6 = cl_list(4, ECL_SYM("PUT-SYSPROP",1124), T2, ECL_SYM("CALLBACK",1590), T5);
    T7 = cl_list(3, ECL_SYM("PROGN",671), T1, T6);
    value0 = ecl_function_dispatch(cl_env_copy,VV[13])(1, T7) /*  C1EXPR */;
    return value0;
   }
  }
 }
}
/*	function definition for FOREIGN-ELT-TYPE-CODE                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2foreign_elt_type_code(cl_object v1type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2x;
   v2x = ecl_assql(v1type,ecl_symbol_value(VV[3]));
   if ((v2x)!=ECL_NIL) { goto L2; }
   ecl_function_dispatch(cl_env_copy,VV[11])(2, _ecl_static_4, v1type) /*  CMPERR */;
L2:;
   value0 = ecl_cdr(v2x);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for T3-DEFCALLBACK                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3t3_defcallback(cl_object v1lisp_name, cl_object v2c_name, cl_object v3c_name_constant, cl_object v4return_type, cl_object v5arg_types, cl_object v6arg_type_constants, cl_object v7call_type)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v8return_p;
   v8return_p = ECL_T;
   if (!((v4return_type)==(ECL_NIL))) { goto L8; }
   goto L5;
   goto L6;
L8:;
   goto L6;
L6:;
   if (!(ecl_eql(v4return_type,ECL_SYM("VOID",1381)))) { goto L3; }
   goto L4;
L5:;
L4:;
   v8return_p = ECL_NIL;
   goto L2;
L3:;
   {
    cl_object v9;
    v9 = si_foreign_elt_type_p(v4return_type);
    if (Null(v9)) { goto L13; }
    goto L2;
L13:;
    if (!(ECL_CONSP(v4return_type))) { goto L15; }
    {
     cl_object v10;
     v10 = ecl_car(v4return_type);
     if (!((v10)==(ECL_SYM("*",18)))) { goto L22; }
     goto L19;
     goto L20;
L22:;
     goto L20;
L20:;
     if (!((v10)==(ECL_SYM("ARRAY",96)))) { goto L15; }
     goto L16;
L19:;
    }
L16:;
    v4return_type = ECL_SYM("POINTER-VOID",1377);
    goto L2;
L15:;
    ecl_function_dispatch(cl_env_copy,VV[11])(2, _ecl_static_5, v4return_type) /*  CMPERR */;
   }
L2:;
   {
    cl_object v9;
    cl_object v10;
    T0 = ecl_function_dispatch(cl_env_copy,VV[16])(1, v4return_type) /*  %CONVERT-TO-ARG-TYPE */;
    v9 = ecl_function_dispatch(cl_env_copy,VV[17])(1, T0) /*  REP-TYPE-NAME */;
    if (!(ecl_eql(v7call_type,ECL_SYM("CDECL",1593)))) { goto L28; }
    v10 = _ecl_static_6;
    goto L27;
L28:;
    if (!(ecl_eql(v7call_type,ECL_SYM("STDCALL",1594)))) { goto L30; }
    v10 = _ecl_static_7;
    goto L27;
L30:;
    v10 = ecl_function_dispatch(cl_env_copy,VV[11])(2, _ecl_static_8, v7call_type) /*  CMPERR */;
L27:;
    ecl_function_dispatch(cl_env_copy,VV[18])(6, _ecl_static_9, v9, _ecl_static_10, v10, v2c_name, _ecl_static_11) /*  WT-NL-H */;
    ecl_function_dispatch(cl_env_copy,VV[19])(6, _ecl_static_9, v9, _ecl_static_10, v10, v2c_name, _ecl_static_11) /*  WT-NL1 */;
    {
     cl_object v11n;
     cl_object v12type;
     cl_object v13;
     v11n = ecl_make_fixnum(0);
     v12type = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v5arg_types))) FEtype_error_list(v5arg_types);
     v13 = v5arg_types;
     {
      cl_object v14comma;
      v14comma = _ecl_static_6;
      if (!(ecl_endp(v13))) { goto L42; }
      goto L41;
L42:;
      v12type = _ecl_car(v13);
L40:;
      {
       cl_object v15;
       v15 = _ecl_cdr(v13);
       if (ecl_unlikely(!ECL_LISTP(v15))) FEtype_error_list(v15);
       v13 = v15;
      }
      T0 = ecl_function_dispatch(cl_env_copy,VV[16])(1, v12type) /*  %CONVERT-TO-ARG-TYPE */;
      T1 = ecl_function_dispatch(cl_env_copy,VV[17])(1, T0) /*  REP-TYPE-NAME */;
      ecl_function_dispatch(cl_env_copy,VV[20])(4, v14comma, T1, _ecl_static_12, v11n) /*  WT-H */;
      T0 = ecl_function_dispatch(cl_env_copy,VV[16])(1, v12type) /*  %CONVERT-TO-ARG-TYPE */;
      T1 = ecl_function_dispatch(cl_env_copy,VV[17])(1, T0) /*  REP-TYPE-NAME */;
      ecl_function_dispatch(cl_env_copy,VV[21])(4, v14comma, T1, _ecl_static_12, v11n) /*  WT */;
      v14comma = _ecl_static_13;
      if (!(ecl_endp(v13))) { goto L54; }
      goto L41;
L54:;
      {
       cl_object v15;
       {
        cl_object v16;
        v16 = ecl_one_plus(v11n);
        v12type = _ecl_car(v13);
        v15 = v16;
       }
       T0 = cl_realp(v15);
       if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("REAL",703),v15);
       v11n = v15;
      }
      goto L40;
L41:;
     }
    }
    ecl_function_dispatch(cl_env_copy,VV[21])(1, _ecl_static_14) /*  WT */;
    ecl_function_dispatch(cl_env_copy,VV[20])(1, _ecl_static_15) /*  WT-H */;
    ecl_function_dispatch(cl_env_copy,VV[22])(0)  /*  WT-NL-OPEN-BRACE */;
    if (Null(v8return_p)) { goto L67; }
    ecl_function_dispatch(cl_env_copy,VV[23])(2, v9, _ecl_static_16) /*  WT-NL */;
L67:;
    ecl_function_dispatch(cl_env_copy,VV[23])(1, _ecl_static_17) /*  WT-NL */;
    ecl_function_dispatch(cl_env_copy,VV[23])(1, _ecl_static_18) /*  WT-NL */;
    ecl_function_dispatch(cl_env_copy,VV[23])(1, _ecl_static_19) /*  WT-NL */;
    {
     cl_object v11n;
     cl_object v12type;
     cl_object v13;
     cl_object v14ct;
     cl_object v15;
     v11n = ecl_make_fixnum(0);
     v12type = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v5arg_types))) FEtype_error_list(v5arg_types);
     v13 = v5arg_types;
     v14ct = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v6arg_type_constants))) FEtype_error_list(v6arg_type_constants);
     v15 = v6arg_type_constants;
     if (ecl_endp(v13)) { goto L84; }
     if (!(ecl_endp(v15))) { goto L82; }
     goto L83;
L84:;
L83:;
     goto L81;
L82:;
     {
      cl_object v16;
      v16 = _ecl_car(v13);
      v14ct = _ecl_car(v15);
      v12type = v16;
     }
L80:;
     {
      cl_object v16;
      v16 = _ecl_cdr(v13);
      if (ecl_unlikely(!ECL_LISTP(v16))) FEtype_error_list(v16);
      v13 = v16;
     }
     {
      cl_object v16;
      v16 = _ecl_cdr(v15);
      if (ecl_unlikely(!ECL_LISTP(v16))) FEtype_error_list(v16);
      v15 = v16;
     }
     if (!(ECL_STRINGP(v14ct))) { goto L100; }
     ecl_function_dispatch(cl_env_copy,VV[23])(5, _ecl_static_20, v11n, _ecl_static_13, v14ct, _ecl_static_21) /*  WT-NL */;
     goto L99;
L100:;
     T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SIZE-OF-FOREIGN-TYPE",2016))(1, v12type) /*  SIZE-OF-FOREIGN-TYPE */;
     ecl_function_dispatch(cl_env_copy,VV[23])(7, _ecl_static_22, v11n, _ecl_static_13, v14ct, _ecl_static_13, T0, _ecl_static_21) /*  WT-NL */;
L99:;
     if (ecl_endp(v13)) { goto L104; }
     if (!(ecl_endp(v15))) { goto L102; }
     goto L103;
L104:;
L103:;
     goto L81;
L102:;
     {
      cl_object v16;
      {
       cl_object v17;
       v17 = ecl_one_plus(v11n);
       {
        cl_object v18;
        v18 = _ecl_car(v13);
        v14ct = _ecl_car(v15);
        v12type = v18;
       }
       v16 = v17;
      }
      T0 = cl_realp(v16);
      if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("REAL",703),v16);
      v11n = v16;
     }
     goto L80;
L81:;
    }
    ecl_function_dispatch(cl_env_copy,VV[23])(4, _ecl_static_23, _ecl_static_24, v3c_name_constant, _ecl_static_21) /*  WT-NL */;
    ecl_function_dispatch(cl_env_copy,VV[23])(1, _ecl_static_25) /*  WT-NL */;
    if (Null(v8return_p)) { goto L119; }
    T0 = L2foreign_elt_type_code(v4return_type);
    ecl_function_dispatch(cl_env_copy,VV[23])(3, _ecl_static_26, T0, _ecl_static_27) /*  WT-NL */;
    ecl_function_dispatch(cl_env_copy,VV[23])(1, _ecl_static_28) /*  WT-NL */;
L119:;
    value0 = ecl_function_dispatch(cl_env_copy,VV[24])(0) /*  WT-NL-CLOSE-BRACE */;
    return value0;
   }
  }
 }
}

#include "cmp/cmpcbk.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclSqpHT5SXPXJj9_BSrtVE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPCBK.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclSqpHT5SXPXJj9_BSrtVE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[10]);                           /*  C1-DEFCALLBACK  */
 si_Xmake_constant(VV[3], VVtemp[0]);
 ecl_cmp_defun(VV[14]);                           /*  FOREIGN-ELT-TYPE-CODE */
 ecl_cmp_defun(VV[15]);                           /*  T3-DEFCALLBACK  */
}
