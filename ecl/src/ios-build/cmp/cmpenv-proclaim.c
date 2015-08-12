/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPENV-PROCLAIM.LSP                           */
#include <ecl/ecl-cmp.h>
#include "cmp/cmpenv-proclaim.eclh"
/*	function definition for PROCLAIM                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1proclaim(cl_object v1decl)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2decl_name;
   v2decl_name = ECL_NIL;
   if (ECL_LISTP(v1decl)) { goto L2; }
   cl_error(2, _ecl_static_1, v1decl);
L2:;
   {
    cl_object v3;
    v2decl_name = ecl_car(v1decl);
    v3 = v2decl_name;
    if (!((v3)==(ECL_SYM("SPECIAL",789)))) { goto L6; }
    {
     cl_object v4;
     v4 = ecl_cdr(v1decl);
     goto L11;
L10:;
     {
      cl_object v5var;
      v5var = ecl_car(v4);
      if (!(ECL_SYMBOLP(v5var))) { goto L16; }
      si_Xmake_special(v5var);
      goto L15;
L16:;
      cl_error(2, _ecl_static_2, v1decl);
L15:;
     }
     v4 = ecl_cdr(v4);
L11:;
     if (Null(v4)) { goto L20; }
     goto L10;
L20:;
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 1;
     return value0;
    }
L6:;
    if (!((v3)==(ECL_SYM("OPTIMIZE",613)))) { goto L22; }
    {
     cl_object v5;
     v5 = ecl_cdr(v1decl);
     goto L27;
L26:;
     {
      cl_object v6x;
      v6x = ecl_car(v5);
      if (!(ECL_SYMBOLP(v6x))) { goto L31; }
      v6x = cl_list(2, v6x, ecl_make_fixnum(3));
L31:;
      if (!(ECL_CONSP(v6x))) { goto L37; }
      T0 = ecl_cdr(v6x);
      if (!(ECL_CONSP(T0))) { goto L37; }
      T0 = ecl_cadr(v6x);
      if (!(ecl_numberp(T0))) { goto L37; }
      T0 = ecl_cadr(v6x);
      if ((cl_LE(3, ecl_make_fixnum(0), T0, ecl_make_fixnum(3)))!=ECL_NIL) { goto L35; }
      goto L36;
L37:;
L36:;
      (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(2, _ecl_static_3, v6x) /*  WARN */;
      goto L34;
L35:;
      {
       cl_object v7;
       v7 = ecl_car(v6x);
       if (!((v7)==(ECL_SYM("DEBUG",270)))) { goto L42; }
       cl_set(VV[0],ecl_cadr(v6x));
       goto L34;
L42:;
       if (!((v7)==(ECL_SYM("SAFETY",734)))) { goto L45; }
       cl_set(VV[1],ecl_cadr(v6x));
       goto L34;
L45:;
       if (!((v7)==(ECL_SYM("SPACE",788)))) { goto L48; }
       cl_set(VV[2],ecl_cadr(v6x));
       goto L34;
L48:;
       if (!((v7)==(ECL_SYM("SPEED",791)))) { goto L51; }
       cl_set(VV[3],ecl_cadr(v6x));
       goto L34;
L51:;
       if (!((v7)==(ECL_SYM("COMPILATION-SPEED",232)))) { goto L54; }
       T0 = ecl_cadr(v6x);
       cl_set(VV[3],ecl_minus(ecl_make_fixnum(3),T0));
       goto L34;
L54:;
       T0 = ecl_car(v6x);
       (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(2, _ecl_static_4, T0) /*  WARN */;
      }
L34:;
     }
     v5 = ecl_cdr(v5);
L27:;
     if (Null(v5)) { goto L59; }
     goto L26;
L59:;
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 1;
     return value0;
    }
L22:;
    if (!((v3)==(ECL_SYM("TYPE",869)))) { goto L61; }
    T0 = ecl_cdr(v1decl);
    if (!(ECL_CONSP(T0))) { goto L63; }
    T0 = ecl_cadr(v1decl);
    T1 = ecl_cddr(v1decl);
    value0 = L2proclaim_var(T0, T1);
    return value0;
L63:;
    value0 = cl_error(2, _ecl_static_2, v1decl);
    return value0;
L61:;
    if (!((v3)==(ECL_SYM("FTYPE",393)))) { goto L65; }
    T0 = ecl_cdr(v1decl);
    if (!(ECL_ATOM(T0))) { goto L67; }
    value0 = cl_error(2, _ecl_static_5, v1decl);
    return value0;
L67:;
    {
     cl_object v7;                                /*  TYPE-NAME       */
     cl_object v8;                                /*  ARGS            */
     T0 = ecl_cadr(v1decl);
     value0 = ecl_function_dispatch(cl_env_copy,VV[17])(1, T0) /*  NORMALIZE-TYPE */;
     v7 = value0;
     {
      const int v9 = cl_env_copy->nvalues;
      cl_object v10;
      v10 = (v9<=1)? ECL_NIL : cl_env_copy->values[1];
      v8 = v10;
     }
     if (!((v7)==(ECL_SYM("FUNCTION",396)))) { goto L70; }
     {
      cl_object v9;
      v9 = ecl_cddr(v1decl);
      goto L75;
L74:;
      {
       cl_object v10v;
       v10v = ecl_car(v9);
       ecl_function_dispatch(cl_env_copy,VV[18])(2, v10v, v8) /*  PROCLAIM-FUNCTION */;
      }
      v9 = ecl_cdr(v9);
L75:;
      if (Null(v9)) { goto L82; }
      goto L74;
L82:;
      value0 = ECL_NIL;
      cl_env_copy->nvalues = 1;
      return value0;
     }
L70:;
     T0 = ecl_cadr(v1decl);
     value0 = cl_error(2, _ecl_static_6, T0);
     return value0;
    }
L65:;
    if (!((v3)==(ECL_SYM("INLINE",434)))) { goto L84; }
    T0 = ecl_cdr(v1decl);
    value0 = ecl_function_dispatch(cl_env_copy,VV[19])(1, T0) /*  PROCLAIM-INLINE */;
    return value0;
L84:;
    if (!((v3)==(ECL_SYM("NOTINLINE",587)))) { goto L86; }
    T0 = ecl_cdr(v1decl);
    value0 = ecl_function_dispatch(cl_env_copy,VV[20])(1, T0) /*  PROCLAIM-NOTINLINE */;
    return value0;
L86:;
    if (!((v3)==(ECL_SYM("OBJECT",2014)))) { goto L93; }
    goto L90;
    goto L91;
L93:;
    goto L91;
L91:;
    if (!((v3)==(ECL_SYM("IGNORE",428)))) { goto L97; }
    goto L90;
    goto L95;
L97:;
    goto L95;
L95:;
    if (!((v3)==(ECL_SYM("DYNAMIC-EXTENT",320)))) { goto L101; }
    goto L90;
    goto L99;
L101:;
    goto L99;
L99:;
    if (!((v3)==(ECL_SYM("IGNORABLE",427)))) { goto L88; }
    goto L89;
L90:;
L89:;
    {
     cl_object v6;
     v6 = ecl_cdr(v1decl);
     goto L107;
L106:;
     {
      cl_object v7var;
      v7var = ecl_car(v6);
      if ((si_valid_function_name_p(v7var))!=ECL_NIL) { goto L111; }
      cl_error(3, _ecl_static_7, v7var, v2decl_name);
L111:;
     }
     v6 = ecl_cdr(v6);
L107:;
     if (Null(v6)) { goto L115; }
     goto L106;
L115:;
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 1;
     return value0;
    }
L88:;
    if (!((v3)==(ECL_SYM("DECLARATION",273)))) { goto L117; }
    T0 = ecl_cdr(v1decl);
    T1 = (ECL_SYM("ERROR",337)->symbol.gfdef);
    ecl_function_dispatch(cl_env_copy,VV[21])(2, T0, T1) /*  VALIDATE-ALIEN-DECLARATION */;
    T0 = ecl_cdr(v1decl);
    cl_set(ECL_SYM("*ALIEN-DECLARATIONS*",1586),ecl_append(T0,ecl_symbol_value(ECL_SYM("*ALIEN-DECLARATIONS*",1586))));
    value0 = ecl_symbol_value(ECL_SYM("*ALIEN-DECLARATIONS*",1586));
    cl_env_copy->nvalues = 1;
    return value0;
L117:;
    if (!((v3)==(VV[8]))) { goto L122; }
    {
     cl_object v7;
     v7 = ecl_cdr(v1decl);
     goto L127;
L126:;
     {
      cl_object v8x;
      v8x = ecl_car(v7);
      if (!(ECL_SYMBOLP(v8x))) { goto L132; }
      {
       cl_object v10;                             /*  FOUND           */
       cl_object v11;                             /*  C-NAME          */
       value0 = si_mangle_name(2, v8x, ECL_T);
       v10 = value0;
       {
        const int v12 = cl_env_copy->nvalues;
        cl_object v13;
        v13 = (v12<=1)? ECL_NIL : cl_env_copy->values[1];
        v11 = v13;
       }
       if (Null(v10)) { goto L135; }
       (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(2, _ecl_static_8, v8x) /*  WARN */;
       goto L131;
L135:;
       si_put_sysprop(v8x, VV[9], v11);
       goto L131;
      }
L132:;
      if (!(ECL_CONSP(v8x))) { goto L137; }
      {
       cl_object v9;
       cl_object v10c_name;
       cl_object v11lisp_name;
       v9 = v8x;
       if (!(v9==ECL_NIL)) { goto L141; }
       si_dm_too_few_arguments(v8x);
L141:;
       {
        cl_object v12;
        v12 = ecl_car(v9);
        v9 = ecl_cdr(v9);
        v10c_name = v12;
       }
       if (!(v9==ECL_NIL)) { goto L147; }
       si_dm_too_few_arguments(v8x);
L147:;
       {
        cl_object v12;
        v12 = ecl_car(v9);
        v9 = ecl_cdr(v9);
        v11lisp_name = v12;
       }
       if (Null(v9)) { goto L152; }
       si_dm_too_many_arguments(v8x);
L152:;
       if (Null(si_mangle_name(1, v11lisp_name))) { goto L154; }
       (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(2, _ecl_static_9, v11lisp_name) /*  WARN */;
       goto L131;
L154:;
       si_put_sysprop(v11lisp_name, VV[9], v10c_name);
       goto L131;
      }
L137:;
      cl_error(2, _ecl_static_2, v1decl);
L131:;
     }
     v7 = ecl_cdr(v7);
L127:;
     if (Null(v7)) { goto L158; }
     goto L126;
L158:;
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 1;
     return value0;
    }
L122:;
    if (Null(ecl_memql(v3,VV[10]))) { goto L160; }
    T0 = ecl_cdr(v1decl);
    value0 = L2proclaim_var(v2decl_name, T0);
    return value0;
L160:;
    {
     cl_object v8;
     T0 = ecl_car(v1decl);
     v8 = ecl_memql(T0,ecl_symbol_value(ECL_SYM("*ALIEN-DECLARATIONS*",1586)));
     if (Null(v8)) { goto L163; }
     value0 = v8;
     cl_env_copy->nvalues = 1;
     return value0;
L163:;
     {
      cl_object v9;
      {
       cl_object v11;                             /*  OK              */
       cl_object v12;                             /*  TYPE            */
       value0 = ecl_function_dispatch(cl_env_copy,VV[22])(1, v2decl_name) /*  VALID-TYPE-SPECIFIER */;
       v11 = value0;
       {
        const int v13 = cl_env_copy->nvalues;
        cl_object v14;
        v14 = (v13<=1)? ECL_NIL : cl_env_copy->values[1];
        v12 = v14;
       }
       if (Null(v11)) { goto L167; }
       T0 = ecl_cdr(v1decl);
       L2proclaim_var(v12, T0);
       v9 = ECL_T;
       goto L165;
L167:;
       v9 = ECL_NIL;
      }
L165:;
      if (Null(v9)) { goto L170; }
      value0 = v9;
      cl_env_copy->nvalues = 1;
      return value0;
L170:;
      {
       cl_object v10;
       v10 = ecl_function_dispatch(cl_env_copy,VV[23])(2, v1decl, ecl_symbol_value(VV[11])) /*  MAYBE-ADD-POLICY */;
       if (Null(v10)) { goto L173; }
       value0 = v10;
       cl_env_copy->nvalues = 1;
       return value0;
L173:;
       {
        cl_object v11;
        {
         cl_object v12proclaimer;
         T0 = ecl_car(v1decl);
         v12proclaimer = si_get_sysprop(T0, VV[12]);
         if (Null(cl_functionp(v12proclaimer))) { goto L177; }
         {
          cl_object v13;
          v13 = ecl_cdr(v1decl);
          {
          cl_object v14;
          cl_object v15;
          v14 = ECL_NIL;
          if (ecl_unlikely(!ECL_LISTP(v13))) FEtype_error_list(v13);
          v15 = v13;
L184:;
          if (!(ecl_endp(v15))) { goto L186; }
          goto L185;
L186:;
          v14 = _ecl_car(v15);
          {
          cl_object v16;
          v16 = _ecl_cdr(v15);
          if (ecl_unlikely(!ECL_LISTP(v16))) FEtype_error_list(v16);
          v15 = v16;
          }
          ecl_function_dispatch(cl_env_copy,v12proclaimer)(1, v14);
          goto L184;
L185:;
          goto L179;
          }
         }
L179:;
         v11 = ECL_T;
         goto L175;
L177:;
         v11 = ECL_NIL;
        }
L175:;
        if (Null(v11)) { goto L197; }
        value0 = v11;
        cl_env_copy->nvalues = 1;
        return value0;
L197:;
        value0 = (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(2, _ecl_static_10, v2decl_name) /*  WARN */;
        return value0;
       }
      }
     }
    }
   }
  }
 }
}
/*	function definition for PROCLAIM-VAR                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2proclaim_var(cl_object v1type, cl_object v2vl)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = v2vl;
   goto L4;
L3:;
   {
    cl_object v4var;
    v4var = ecl_car(v3);
    if (!(ECL_SYMBOLP(v4var))) { goto L9; }
    {
     cl_object v5type1;
     v5type1 = si_get_sysprop(v4var, VV[14]);
     if (Null(v5type1)) { goto L14; }
     v5type1 = ecl_function_dispatch(cl_env_copy,VV[25])(2, v5type1, v1type) /*  TYPE-AND */;
     goto L13;
L14:;
     v5type1 = v1type;
L13:;
     if ((v5type1)!=ECL_NIL) { goto L16; }
     (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(2, _ecl_static_11, v4var) /*  WARN */;
     v5type1 = ECL_T;
L16:;
     si_put_sysprop(v4var, VV[14], v5type1);
     goto L8;
    }
L9:;
    (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(2, _ecl_static_12, v4var) /*  WARN */;
L8:;
   }
   v3 = ecl_cdr(v3);
L4:;
   if (Null(v3)) { goto L22; }
   goto L3;
L22:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}

#include "cmp/cmpenv-proclaim.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclGE8ba8GOQxEn9_JwxTOE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPENV-PROCLAIM.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclGE8ba8GOQxEn9_JwxTOE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[16]);                           /*  PROCLAIM        */
 ecl_cmp_defun(VV[24]);                           /*  PROCLAIM-VAR    */
}
