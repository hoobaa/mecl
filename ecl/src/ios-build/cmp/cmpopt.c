/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPOPT.LSP                                    */
#include <ecl/ecl-cmp.h>
#include "cmp/cmpopt.eclh"
/*	function definition for EXPAND-IN-INTERVAL-P                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1expand_in_interval_p(cl_object v1var, cl_object v2interval)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3forms;
   v3forms = ECL_NIL;
   {
    cl_object v4;
    cl_object v5lower_limit;
    cl_object v6upper_limit;
    v4 = v2interval;
    if (Null(v4)) { goto L5; }
    {
     cl_object v7;
     v7 = ecl_car(v4);
     v4 = ecl_cdr(v4);
     v5lower_limit = v7;
     goto L4;
    }
L5:;
    v5lower_limit = ECL_SYM("*",18);
L4:;
    if (Null(v4)) { goto L11; }
    {
     cl_object v7;
     v7 = ecl_car(v4);
     v4 = ecl_cdr(v4);
     v6upper_limit = v7;
     goto L10;
    }
L11:;
    v6upper_limit = ECL_SYM("*",18);
L10:;
    if (Null(v4)) { goto L16; }
    si_dm_too_many_arguments(v2interval);
L16:;
    if ((v5lower_limit)==(ECL_SYM("*",18))) { goto L18; }
    if (!(ECL_CONSP(v5lower_limit))) { goto L22; }
    T1 = ecl_car(v5lower_limit);
    T0 = cl_list(3, ECL_SYM(">",75), v1var, T1);
    goto L21;
L22:;
    T0 = cl_list(3, ECL_SYM(">=",76), v1var, v5lower_limit);
L21:;
    v3forms = CONS(T0,v3forms);
L18:;
    if ((v6upper_limit)==(ECL_SYM("*",18))) { goto L2; }
    if (!(ECL_CONSP(v6upper_limit))) { goto L27; }
    T1 = ecl_car(v6upper_limit);
    T0 = cl_list(3, ECL_SYM("<",72), v1var, T1);
    goto L26;
L27:;
    T0 = cl_list(3, ECL_SYM("<=",73), v1var, v6upper_limit);
L26:;
    v3forms = CONS(T0,v3forms);
   }
L2:;
   value0 = v3forms;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for EXPAND-TYPEP                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2expand_typep(cl_object v1form, cl_object v2object, cl_object v3type, cl_object v4env)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v5aux;
   cl_object v6first;
   cl_object v7rest;
   cl_object v8function;
   v5aux = ECL_NIL;
   v6first = ECL_NIL;
   v7rest = ECL_NIL;
   v8function = ECL_NIL;
   if (Null(cl_constantp(1, v3type))) { goto L8; }
   v3type = ecl_function_dispatch(cl_env_copy,VV[29])(1, v3type) /*  CMP-EVAL */;
   if (Null(v3type)) { goto L8; }
   goto L5;
L8:;
   goto L6;
L6:;
   value0 = v1form;
   cl_env_copy->nvalues = 1;
   return value0;
L5:;
   if ((ecl_function_dispatch(cl_env_copy,VV[30])(1, v3type) /*  KNOWN-TYPE-P */)!=ECL_NIL) { goto L12; }
   value0 = v1form;
   cl_env_copy->nvalues = 1;
   return value0;
L12:;
   if (!(ECL_SYMBOLP(v2object))) { goto L14; }
   v5aux = ecl_function_dispatch(cl_env_copy,VV[31])(2, v2object, v4env) /*  CMP-ENV-SEARCH-VAR */;
   if (Null(v5aux)) { goto L14; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[32])(1, v5aux) /*  VAR-TYPE */;
   if (Null(cl_subtypep(2, T0, v3type))) { goto L14; }
   value0 = ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
L14:;
   if (Null(cl_subtypep(2, ECL_T, v3type))) { goto L19; }
   value0 = ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
L19:;
   if (!((v3type)==(ECL_NIL))) { goto L21; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L21:;
   if (Null(cl_subtypep(2, v3type, ECL_NIL))) { goto L23; }
   ecl_function_dispatch(cl_env_copy,VV[33])(2, _ecl_static_1, v3type) /*  CMPWARN */;
   value0 = v1form;
   cl_env_copy->nvalues = 1;
   return value0;
L23:;
   v8function = si_get_sysprop(v3type, VV[0]);
   if (Null(v8function)) { goto L26; }
   value0 = cl_list(2, v8function, v2object);
   return value0;
L26:;
   {
    cl_object v9;
    {
     cl_object v10;
     cl_object v11a_type;
     cl_object v12function_name;
     cl_object v13;
     v10 = ecl_symbol_value(VV[1]);
     v11a_type = ECL_NIL;
     v12function_name = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
     v13 = v10;
L35:;
     {
      cl_object v14;
      v14 = _ecl_car(v13);
      v11a_type = ecl_car(v14);
      v14 = ecl_cdr(v14);
      v12function_name = v14;
     }
     {
      cl_object v14;
      v14 = _ecl_cdr(v13);
      if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
      v13 = v14;
     }
     if (Null(ecl_function_dispatch(cl_env_copy,VV[34])(2, v3type, v11a_type) /*  TYPE= */)) { goto L48; }
     v9 = cl_list(2, v12function_name, v2object);
     goto L29;
L48:;
     if (!(ecl_endp(v13))) { goto L50; }
     goto L36;
L50:;
     goto L35;
L36:;
     v9 = ECL_NIL;
    }
L29:;
    if (Null(v9)) { goto L53; }
    value0 = v9;
    cl_env_copy->nvalues = 1;
    return value0;
L53:;
    v8function = ecl_assql(v3type,VV[2]);
    if (Null(v8function)) { goto L55; }
    T0 = ecl_cdr(v8function);
    value0 = cl_list(2, T0, v2object);
    return value0;
L55:;
    if (!(ECL_ATOM(v3type))) { goto L58; }
    v8function = si_get_sysprop(v3type, VV[3]);
    if (Null(v8function)) { goto L58; }
    T0 = ecl_function_dispatch(cl_env_copy,v8function)(0);
    v3type = cl_list(2, ECL_SYM("QUOTE",679), T0);
    goto TTL;
L58:;
    if ((ecl_function_dispatch(cl_env_copy,VV[35])(0) /*  POLICY-INLINE-TYPE-CHECKS */)!=ECL_NIL) { goto L68; }
    value0 = v1form;
    cl_env_copy->nvalues = 1;
    return value0;
L68:;
    if (!(ECL_CONSP(v3type))) { goto L70; }
    if (!((v6first)==(ECL_SYM("CONS",251)))) { goto L70; }
    value0 = v1form;
    cl_env_copy->nvalues = 1;
    return value0;
L70:;
    if (!(ECL_SYMBOLP(v3type))) { goto L73; }
    v5aux = cl_find_class(2, v3type, ECL_NIL);
    if (Null(v5aux)) { goto L73; }
    T0 = cl_list(2, ECL_SYM("QUOTE",679), v3type);
    value0 = cl_list(3, ECL_SYM("OF-CLASS-P",1179), v2object, T0);
    return value0;
L73:;
    if (!(ECL_ATOM(v3type))) { goto L77; }
    value0 = v1form;
    cl_env_copy->nvalues = 1;
    return value0;
L77:;
    v7rest = ecl_cdr(v3type);
    v6first = ecl_car(v3type);
    if (!((v6first)==(ECL_SYM("NOT",584)))) { goto L79; }
    T0 = ecl_car(v7rest);
    T1 = cl_list(2, ECL_SYM("QUOTE",679), T0);
    T2 = cl_list(3, ECL_SYM("TYPEP",875), v2object, T1);
    value0 = cl_list(2, ECL_SYM("NOT",584), T2);
    return value0;
L79:;
    if (!((v6first)==(ECL_SYM("OR",614)))) { goto L90; }
    goto L87;
    goto L88;
L90:;
    goto L88;
L88:;
    if (!((v6first)==(ECL_SYM("AND",87)))) { goto L85; }
    goto L86;
L87:;
L86:;
    {
     cl_object v10var;
     v10var = cl_gensym(0);
     T0 = cl_list(2, v10var, v2object);
     T1 = ecl_list1(T0);
     T2 = cl_list(2, VV[6], v10var);
     T3 = cl_list(2, ECL_SYM("DECLARE",274), T2);
     {
      cl_object v11type;
      cl_object v12;
      v11type = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v7rest))) FEtype_error_list(v7rest);
      v12 = v7rest;
      {
       cl_object v13;
       cl_object v14;
       v13 = ecl_list1(ECL_NIL);
       v14 = v13;
L100:;
       if (!(ecl_endp(v12))) { goto L102; }
       goto L101;
L102:;
       v11type = _ecl_car(v12);
       {
        cl_object v15;
        v15 = _ecl_cdr(v12);
        if (ecl_unlikely(!ECL_LISTP(v15))) FEtype_error_list(v15);
        v12 = v15;
       }
       if (ecl_unlikely(ECL_ATOM(v14))) FEtype_error_cons(v14);
       T5 = v14;
       T6 = cl_list(2, ECL_SYM("QUOTE",679), v11type);
       T7 = cl_list(3, ECL_SYM("TYPEP",875), v10var, T6);
       v14 = ecl_list1(T7);
       (ECL_CONS_CDR(T5)=v14,T5);
       goto L100;
L101:;
       T4 = ecl_cdr(v13);
       goto L94;
      }
     }
L94:;
     T5 = CONS(v6first,T4);
     value0 = cl_list(4, ECL_SYM("LET",477), T1, T3, T5);
     return value0;
    }
L85:;
    if (!((v6first)==(ECL_SYM("MEMBER",552)))) { goto L116; }
    T0 = cl_list(2, ECL_SYM("QUOTE",679), v7rest);
    value0 = cl_list(3, ECL_SYM("MEMBER",552), v2object, T0);
    return value0;
L116:;
    if (Null(ecl_memql(v6first,VV[7]))) { goto L118; }
    {
     cl_object v11;
     cl_object v12;
     v11 = cl_gensym(0);
     v12 = cl_gensym(0);
     if (!((v6first)==(ECL_SYM("INTEGER",437)))) { goto L122; }
     if (Null(cl_subtypep(2, v3type, ECL_SYM("FIXNUM",372)))) { goto L122; }
     v6first = ECL_SYM("FIXNUM",372);
L122:;
     T0 = cl_list(2, v11, v2object);
     T1 = cl_coerce(ecl_make_fixnum(0), v6first);
     T2 = cl_list(2, v12, T1);
     T3 = cl_list(2, T0, T2);
     T4 = cl_list(2, VV[6], v11);
     T5 = cl_list(3, ECL_SYM("TYPE",869), v6first, v12);
     T6 = cl_list(3, ECL_SYM("DECLARE",274), T4, T5);
     T7 = cl_list(2, ECL_SYM("QUOTE",679), v6first);
     T8 = cl_list(3, ECL_SYM("TYPEP",875), v11, T7);
     T9 = cl_list(3, ECL_SYM("TRULY-THE",1949), v6first, v11);
     T10 = cl_list(3, ECL_SYM("SETF",750), v12, T9);
     T11 = L1expand_in_interval_p(v12, v7rest);
     T12 = CONS(ECL_SYM("AND",87),T11);
     T13 = cl_list(4, ECL_SYM("LOCALLY",490), VV[8], T10, T12);
     T14 = cl_list(3, ECL_SYM("AND",87), T8, T13);
     value0 = cl_list(4, ECL_SYM("LET",477), T3, T6, T14);
     return value0;
    }
L118:;
    if (!((v6first)==(ECL_SYM("SATISFIES",735)))) { goto L126; }
    T0 = cl_list_length(v3type);
    if (!(ecl_number_equalp(T0,ecl_make_fixnum(2)))) { goto L126; }
    v8function = ecl_cadr(v3type);
    if (!(ECL_SYMBOLP(v8function))) { goto L126; }
    value0 = cl_list(2, v8function, v2object);
    return value0;
L126:;
    v8function = si_get_sysprop(v6first, VV[3]);
    if (Null(v8function)) { goto L131; }
    T0 = cl_apply(2, v8function, v7rest);
    v3type = cl_list(2, ECL_SYM("QUOTE",679), T0);
    goto TTL;
L131:;
    value0 = v1form;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	local function TYPEP                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC3typep(cl_object v1, cl_object v2env)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4object;
   cl_object v5type;
   cl_object v6e;
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
    v5type = v7;
   }
   if (Null(v3)) { goto L15; }
   {
    cl_object v7;
    v7 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v6e = v7;
    goto L14;
   }
L15:;
   v6e = ECL_NIL;
L14:;
   if (Null(v3)) { goto L20; }
   si_dm_too_many_arguments(v1);
L20:;
   value0 = L2expand_typep(v1, v4object, v5type, v2env);
   return value0;
  }
 }
}
/*	local function DOLIST                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC4dolist(cl_object v1, cl_object v2env)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6var;
   cl_object v7expression;
   cl_object v8output_form;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v9;
    v9 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4 = v9;
   }
   v5 = v4;
   if (!(v5==ECL_NIL)) { goto L10; }
   si_dm_too_few_arguments(v1);
L10:;
   {
    cl_object v9;
    v9 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v6var = v9;
   }
   if (!(v5==ECL_NIL)) { goto L16; }
   si_dm_too_few_arguments(v1);
L16:;
   {
    cl_object v9;
    v9 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v7expression = v9;
   }
   if (Null(v5)) { goto L22; }
   {
    cl_object v9;
    v9 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v8output_form = v9;
    goto L21;
   }
L22:;
   v8output_form = ECL_NIL;
L21:;
   if (Null(v5)) { goto L27; }
   si_dm_too_many_arguments(v1);
L27:;
   {
    cl_object v10;                                /*  DECLARATIONS    */
    cl_object v11;                                /*  BODY            */
    value0 = si_process_declarations(2, v3, ECL_NIL);
    v10 = value0;
    {
     const int v12 = cl_env_copy->nvalues;
     cl_object v13;
     v13 = (v12<=1)? ECL_NIL : cl_env_copy->values[1];
     v11 = v13;
    }
    {
     cl_object v12list_var;
     cl_object v13typed_var;
     v12list_var = cl_gensym(0);
     if (Null(ecl_function_dispatch(cl_env_copy,VV[36])(1, v2env) /*  POLICY-ASSUME-NO-ERRORS */)) { goto L32; }
     v13typed_var = v12list_var;
     goto L31;
L32:;
     v13typed_var = cl_list(3, ECL_SYM("TRULY-THE",1949), ECL_SYM("CONS",251), v12list_var);
L31:;
     T0 = cl_list(2, v12list_var, v7expression);
     T1 = ecl_list1(T0);
     T2 = cl_list(2, ECL_SYM("FIRST",371), v13typed_var);
     T3 = cl_list(2, v6var, T2);
     T4 = ecl_list1(T3);
     T5 = CONS(ECL_SYM("DECLARE",274),v10);
     T6 = CONS(ECL_SYM("TAGBODY",850),v11);
     T7 = cl_list(4, ECL_SYM("LET",477), T4, T5, T6);
     T8 = cl_list(2, ECL_SYM("REST",719), v13typed_var);
     T9 = cl_list(3, ECL_SYM("SETQ",751), v12list_var, T8);
     T10 = cl_list(4, ECL_SYM("WHILE",1469), v12list_var, T7, T9);
     if (Null(v8output_form)) { goto L35; }
     T12 = cl_list(2, v6var, ECL_NIL);
     T13 = ecl_list1(T12);
     T14 = CONS(ECL_SYM("DECLARE",274),v10);
     T11 = cl_list(4, ECL_SYM("LET",477), T13, T14, v8output_form);
     goto L34;
L35:;
     T11 = ECL_NIL;
L34:;
     T12 = cl_list(4, ECL_SYM("LET*",478), T1, T10, T11);
     value0 = cl_list(3, ECL_SYM("BLOCK",137), ECL_NIL, T12);
     return value0;
    }
   }
  }
 }
}
/*	function definition for EXPAND-COERCE                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5expand_coerce(cl_object v1form, cl_object v2value, cl_object v3type, cl_object v4env)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v5first;
   cl_object v6rest;
   v5first = ECL_NIL;
   v6rest = ECL_NIL;
   if (Null(cl_constantp(1, v3type))) { goto L6; }
   v3type = ecl_function_dispatch(cl_env_copy,VV[29])(1, v3type) /*  CMP-EVAL */;
   if ((v3type)!=ECL_NIL) { goto L3; }
   goto L4;
L6:;
   goto L4;
L4:;
   value0 = v1form;
   cl_env_copy->nvalues = 1;
   return value0;
L3:;
   if (Null(cl_subtypep(2, ECL_T, v3type))) { goto L9; }
   value0 = v2value;
   cl_env_copy->nvalues = 1;
   return value0;
L9:;
   if (Null(cl_subtypep(2, v3type, ECL_NIL))) { goto L11; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[37])(1, _ecl_static_2) /*  CMPERROR */;
   return value0;
L11:;
   if ((ecl_function_dispatch(cl_env_copy,VV[35])(0) /*  POLICY-INLINE-TYPE-CHECKS */)!=ECL_NIL) { goto L13; }
   value0 = v1form;
   cl_env_copy->nvalues = 1;
   return value0;
L13:;
   {
    cl_object v7;
    {
     cl_object v8;
     cl_object v9a_type;
     cl_object v10template;
     cl_object v11;
     v8 = ecl_symbol_value(VV[10]);
     v9a_type = ECL_NIL;
     v10template = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
     v11 = v8;
L21:;
     if (!(ecl_endp(v11))) { goto L23; }
     goto L22;
L23:;
     {
      cl_object v12;
      v12 = _ecl_car(v11);
      v9a_type = ecl_car(v12);
      v12 = ecl_cdr(v12);
      v10template = v12;
     }
     {
      cl_object v12;
      v12 = _ecl_cdr(v11);
      if (ecl_unlikely(!ECL_LISTP(v12))) FEtype_error_list(v12);
      v11 = v12;
     }
     if (!((v3type)==(v9a_type))) { goto L36; }
     v7 = cl_subst(3, v2value, VV[11], v10template);
     goto L15;
L36:;
     goto L21;
L22:;
     v7 = ECL_NIL;
    }
L15:;
    if (Null(v7)) { goto L39; }
    value0 = v7;
    cl_env_copy->nvalues = 1;
    return value0;
L39:;
    if (!((v3type)==(ECL_SYM("COMPLEX",241)))) { goto L41; }
    T0 = cl_list(2, VV[12], v2value);
    T1 = ecl_list1(T0);
    value0 = cl_listX(3, ECL_SYM("LET",477), T1, VV[13]);
    return value0;
L41:;
    if (!(ECL_ATOM(v3type))) { goto L43; }
    v5first = si_get_sysprop(v3type, VV[3]);
    if (Null(v5first)) { goto L43; }
    T0 = ecl_function_dispatch(cl_env_copy,v5first)(0);
    v3type = cl_list(2, ECL_SYM("QUOTE",679), T0);
    goto TTL;
L43:;
    if (!(ECL_CONSP(v3type))) { goto L53; }
    T0 = ecl_car(v3type);
    if (!((T0)==(ECL_SYM("CONS",251)))) { goto L53; }
    value0 = v1form;
    cl_env_copy->nvalues = 1;
    return value0;
L53:;
    {
     cl_object v8;
     {
      cl_object v9;
      cl_object v10a_type;
      cl_object v11template;
      cl_object v12;
      v9 = ecl_symbol_value(VV[10]);
      v10a_type = ECL_NIL;
      v11template = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
      v12 = v9;
L62:;
      if (!(ecl_endp(v12))) { goto L64; }
      goto L63;
L64:;
      {
       cl_object v13;
       v13 = _ecl_car(v12);
       v10a_type = ecl_car(v13);
       v13 = ecl_cdr(v13);
       v11template = v13;
      }
      {
       cl_object v13;
       v13 = _ecl_cdr(v12);
       if (ecl_unlikely(!ECL_LISTP(v13))) FEtype_error_list(v13);
       v12 = v13;
      }
      if (Null(ecl_function_dispatch(cl_env_copy,VV[34])(2, v3type, v10a_type) /*  TYPE= */)) { goto L77; }
      v8 = cl_subst(3, v2value, VV[11], v11template);
      goto L56;
L77:;
      goto L62;
L63:;
      v8 = ECL_NIL;
     }
L56:;
     if (Null(v8)) { goto L80; }
     value0 = v8;
     cl_env_copy->nvalues = 1;
     return value0;
L80:;
     if (Null(cl_subtypep(2, v3type, ECL_SYM("SEQUENCE",741)))) { goto L82; }
     {
      cl_object v10;                              /*  ELT-TYPE        */
      cl_object v11;                              /*  LENGTH          */
      value0 = ecl_function_dispatch(cl_env_copy,VV[38])(1, v3type) /*  CLOSEST-SEQUENCE-TYPE */;
      v10 = value0;
      {
       const int v12 = cl_env_copy->nvalues;
       cl_object v13;
       v13 = (v12<=1)? ECL_NIL : cl_env_copy->values[1];
       v11 = v13;
      }
      if (!((v10)==(ECL_SYM("LIST",481)))) { goto L85; }
      value0 = cl_list(2, VV[14], v2value);
      return value0;
L85:;
      T0 = cl_list(2, ECL_SYM("QUOTE",679), v10);
      T1 = cl_list(2, ECL_SYM("QUOTE",679), v11);
      if (Null(cl_subtypep(2, v3type, ECL_SYM("SIMPLE-ARRAY",763)))) { goto L89; }
      T2 = ECL_T;
      goto L87;
L89:;
      T2 = ECL_NIL;
      goto L87;
L87:;
      value0 = cl_list(5, VV[15], v2value, T0, T1, T2);
      return value0;
     }
L82:;
     if (!(ECL_ATOM(v3type))) { goto L91; }
     value0 = v1form;
     cl_env_copy->nvalues = 1;
     return value0;
L91:;
     v6rest = ecl_cdr(v3type);
     v5first = ecl_car(v3type);
     if (!((v5first)==(ECL_SYM("AND",87)))) { goto L93; }
     T0 = cl_list(2, VV[11], v2value);
     T1 = ecl_list1(T0);
     {
      cl_object v9i;
      cl_object v10;
      v9i = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v6rest))) FEtype_error_list(v6rest);
      v10 = v6rest;
      {
       cl_object v11;
       cl_object v12;
       v11 = ecl_list1(ECL_NIL);
       v12 = v11;
L105:;
       if (!(ecl_endp(v10))) { goto L107; }
       goto L106;
L107:;
       v9i = _ecl_car(v10);
       {
        cl_object v13;
        v13 = _ecl_cdr(v10);
        if (ecl_unlikely(!ECL_LISTP(v13))) FEtype_error_list(v13);
        v10 = v13;
       }
       if (ecl_unlikely(ECL_ATOM(v12))) FEtype_error_cons(v12);
       T3 = v12;
       T4 = cl_list(2, ECL_SYM("QUOTE",679), v9i);
       T5 = cl_list(3, ECL_SYM("COERCE",231), VV[11], T4);
       T6 = cl_list(3, ECL_SYM("SETF",750), VV[11], T5);
       v12 = ecl_list1(T6);
       (ECL_CONS_CDR(T3)=v12,T3);
       goto L105;
L106:;
       T2 = ecl_cdr(v11);
       goto L99;
      }
     }
L99:;
     T3 = ecl_append(T2,VV[16]);
     value0 = cl_listX(3, ECL_SYM("LET",477), T1, T3);
     return value0;
L93:;
     if (!((v5first)==(ECL_SYM("COMPLEX",241)))) { goto L121; }
     {
      cl_fixnum v9;
      v9 = ecl_length(v6rest);
      if (!((v9)==(1))) { goto L121; }
     }
     T0 = cl_list(2, VV[12], v2value);
     T1 = ecl_list1(T0);
     T2 = ecl_car(v6rest);
     T3 = cl_list(2, ECL_SYM("QUOTE",679), T2);
     T4 = cl_list(3, ECL_SYM("COERCE",231), VV[18], T3);
     T5 = ecl_car(v6rest);
     T6 = cl_list(2, ECL_SYM("QUOTE",679), T5);
     T7 = cl_list(3, ECL_SYM("COERCE",231), VV[19], T6);
     T8 = cl_list(3, ECL_SYM("COMPLEX",241), T4, T7);
     value0 = cl_list(4, ECL_SYM("LET",477), T1, VV[17], T8);
     return value0;
L121:;
     if (Null(ecl_memql(v5first,VV[7]))) { goto L124; }
     {
      cl_object v9unchecked;
      T0 = cl_list(2, ECL_SYM("QUOTE",679), v5first);
      v9unchecked = L5expand_coerce(v1form, v2value, T0, v4env);
      if (Null(ecl_function_dispatch(cl_env_copy,VV[36])(0) /*  POLICY-ASSUME-NO-ERRORS */)) { goto L127; }
      value0 = v9unchecked;
      cl_env_copy->nvalues = 1;
      return value0;
L127:;
      T0 = cl_list(2, VV[11], v9unchecked);
      T1 = ecl_list1(T0);
      T2 = cl_list(2, v5first, VV[11]);
      T3 = cl_list(2, ECL_SYM("DECLARE",274), T2);
      T4 = ecl_cdr(v3type);
      T5 = L1expand_in_interval_p(VV[11], T4);
      T6 = CONS(ECL_SYM("AND",87),T5);
      T7 = cl_list(2, ECL_SYM("QUOTE",679), v3type);
      T8 = cl_listX(4, ECL_SYM("DO-CHECK-TYPE",1786), VV[11], T7, VV[20]);
      T9 = cl_list(3, ECL_SYM("UNLESS",883), T6, T8);
      value0 = cl_list(5, ECL_SYM("LET",477), T1, T3, T9, VV[11]);
      return value0;
     }
L124:;
     value0 = v1form;
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
  }
 }
}
/*	local function COERCE                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC6coerce(cl_object v1, cl_object v2env)
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
   value0 = L5expand_coerce(v1, v4value, v5type, v2env);
   return value0;
  }
 }
}
/*	local function FLOAT                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC7float(cl_object v1, cl_object v2env)
{
 cl_object T0, T1, T2, T3, T4, T5, T6;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4value;
   cl_object v5float;
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
   if (Null(v3)) { goto L9; }
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5float = v6;
    goto L8;
   }
L9:;
   v5float = ECL_NIL;
L8:;
   if (Null(v3)) { goto L14; }
   si_dm_too_many_arguments(v1);
L14:;
   if (Null(v5float)) { goto L20; }
   if (Null(ecl_function_dispatch(cl_env_copy,VV[35])(1, v2env) /*  POLICY-INLINE-TYPE-CHECKS */)) { goto L20; }
   {
    cl_object v7;                                 /*  CONSTANT-P      */
    cl_object v8;                                 /*  FLOAT           */
    value0 = ecl_function_dispatch(cl_env_copy,VV[39])(2, v5float, v2env) /*  CONSTANT-VALUE-P */;
    v7 = value0;
    {
     const int v9 = cl_env_copy->nvalues;
     cl_object v10;
     v10 = (v9<=1)? ECL_NIL : cl_env_copy->values[1];
     v8 = v10;
    }
    if (Null(v7)) { goto L24; }
    if (!(floatp(v8))) { goto L24; }
    {
     cl_object v9aux;
     cl_object v10float;
     cl_object v11c_type;
     v9aux = cl_gentemp(0);
     v10float = cl_type_of(v8);
     v11c_type = ecl_function_dispatch(cl_env_copy,VV[40])(1, v10float) /*  LISP-TYPE->REP-TYPE */;
     T0 = cl_list(2, VV[21], v4value);
     T1 = ecl_list1(T0);
     T2 = cl_list(2, v10float, VV[21]);
     if (!(ecl_eql(v11c_type,ECL_SYM("DOUBLE",1366)))) { goto L31; }
     T3 = _ecl_static_3;
     goto L30;
L31:;
     if (!(ecl_eql(v11c_type,ECL_SYM("FLOAT",1368)))) { goto L33; }
     T3 = _ecl_static_4;
     goto L30;
L33:;
     if (!(ecl_eql(v11c_type,VV[25]))) { goto L35; }
     T3 = _ecl_static_5;
     goto L30;
L35:;
     T3 = si_ecase_error(v11c_type, VV[26]);
L30:;
     T4 = cl_listX(6, ECL_SYM("C-INLINE",1973), VV[23], VV[24], v11c_type, T3, VV[27]);
     T5 = cl_list(2, ECL_T, T4);
     T6 = cl_list(4, ECL_SYM("COMPILER-TYPECASE",1780), VV[21], T2, T5);
     value0 = cl_list(4, ECL_SYM("LET",477), T1, VV[22], T6);
     goto L18;
    }
L24:;
    value0 = ECL_NIL;
    goto L18;
   }
L20:;
   value0 = ECL_NIL;
   goto L18;
L18:;
   if ((value0)!=ECL_NIL) { goto L17; }
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
L17:;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}

#include "cmp/cmpopt.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecldTaYBbKzxmFo9_kzzTOE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPOPT.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_ecldTaYBbKzxmFo9_kzzTOE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 (void)0; /* No entry created for EXPAND-IN-INTERVAL-P */
 ecl_cmp_defun(VV[28]);                           /*  EXPAND-TYPEP    */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC3typep,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("TYPEP",875), ECL_SYM("COMPILER-MACRO",238), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC4dolist,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("DOLIST",313), ECL_SYM("COMPILER-MACRO",238), T0);
 }
 si_Xmake_special(VV[10]);
 cl_set(VV[10],VVtemp[0]);
 (void)0; /* No entry created for EXPAND-COERCE */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC6coerce,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("COERCE",231), ECL_SYM("COMPILER-MACRO",238), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC7float,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("FLOAT",374), ECL_SYM("COMPILER-MACRO",238), T0);
 }
}
