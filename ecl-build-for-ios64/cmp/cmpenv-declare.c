/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPENV-DECLARE.LSP                            */
#include <ecl/ecl-cmp.h>
#include "cmp/cmpenv-declare.eclh"
/*	function definition for VALID-FORM-P                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1valid_form_p(cl_narg narg, cl_object v1x, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2test;
  va_list args; va_start(args,v1x);
  {
   int i = 1;
   if (i >= narg) {
    v2test = ECL_NIL;
   } else {
    i++;
    v2test = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (Null(si_proper_list_p(v1x))) { goto L3; }
  value0 = ecl_make_bool(v2test==ECL_NIL);
  if ((value0)!=ECL_NIL) { goto L6; }
  value0 = cl_every(2, v2test, v1x);
  return value0;
L6:;
  cl_env_copy->nvalues = 1;
  return value0;
L3:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for TYPE-NAME-P                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2type_name_p(cl_object v1name)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = si_get_sysprop(v1name, VV[1]);
  if ((value0)!=ECL_NIL) { goto L2; }
  value0 = cl_find_class(2, v1name, ECL_NIL);
  if ((value0)!=ECL_NIL) { goto L2; }
  value0 = si_get_sysprop(v1name, VV[2]);
  return value0;
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for VALIDATE-ALIEN-DECLARATION            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3validate_alien_declaration(cl_object v1names_list, cl_object v2error)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = v1names_list;
   goto L4;
L3:;
   {
    cl_object v4new_declaration;
    v4new_declaration = ecl_car(v3);
    if (ECL_SYMBOLP(v4new_declaration)) { goto L8; }
    ecl_function_dispatch(cl_env_copy,VV[29])(2, _ecl_static_1, v4new_declaration) /*  CMPERR */;
L8:;
    if (Null(L2type_name_p(v4new_declaration))) { goto L10; }
    ecl_function_dispatch(cl_env_copy,VV[29])(2, _ecl_static_2, v4new_declaration) /*  CMPERR */;
L10:;
   }
   v3 = ecl_cdr(v3);
L4:;
   if (Null(v3)) { goto L14; }
   goto L3;
L14:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for ALIEN-DECLARATION-P                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4alien_declaration_p(cl_narg narg, cl_object v1name, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2env;
  va_list args; va_start(args,v1name);
  {
   int i = 1;
   if (i >= narg) {
    v2env = ecl_symbol_value(VV[5]);
   } else {
    i++;
    v2env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = ecl_memql(v1name,ecl_symbol_value(ECL_SYM("*ALIEN-DECLARATIONS*",1586)));
  if ((value0)!=ECL_NIL) { goto L3; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[31])(2, VV[6], v2env) /*  CMP-ENV-SEARCH-DECLARATION */;
  value0 = ecl_memql(v1name,T0);
  cl_env_copy->nvalues = 1;
  return value0;
L3:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for PARSE-IGNORE-DECLARATION              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5parse_ignore_declaration(cl_object v1decl_args, cl_object v2expected_ref_number, cl_object v3tail)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4name;
   cl_object v5;
   v4name = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v1decl_args))) FEtype_error_list(v1decl_args);
   v5 = v1decl_args;
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
   if (!(ECL_SYMBOLP(v4name))) { goto L16; }
   T0 = CONS(v4name,v2expected_ref_number);
   v3tail = CONS(T0,v3tail);
   goto L15;
L16:;
   if (!(ECL_CONSP(v4name))) { goto L21; }
   {
    cl_fixnum v6;
    v6 = ecl_length(v4name);
    if (!((v6)==(2))) { goto L21; }
   }
   T0 = ecl_car(v4name);
   if ((T0)==(ECL_SYM("FUNCTION",396))) { goto L15; }
   goto L19;
L21:;
   goto L19;
L19:;
   ecl_function_dispatch(cl_env_copy,VV[29])(2, _ecl_static_3, v4name) /*  CMPERR */;
L15:;
   goto L5;
L6:;
  }
  value0 = v3tail;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for COLLECT-DECLARED                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6collect_declared(cl_object v1type, cl_object v2var_list, cl_object v3tail)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = (ECL_SYM("SYMBOLP",847)->symbol.gfdef);
  if ((L1valid_form_p(2, v2var_list, T0))!=ECL_NIL) { goto L1; }
  T0 = cl_list(3, ECL_SYM("TYPE",869), v1type, v2var_list);
  ecl_function_dispatch(cl_env_copy,VV[29])(2, _ecl_static_4, T0) /*  CMPERR */;
L1:;
  {
   cl_object v4var_name;
   cl_object v5;
   v4var_name = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v2var_list))) FEtype_error_list(v2var_list);
   v5 = v2var_list;
L8:;
   if (!(ecl_endp(v5))) { goto L10; }
   goto L9;
L10:;
   v4var_name = _ecl_car(v5);
   {
    cl_object v6;
    v6 = _ecl_cdr(v5);
    if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
    v5 = v6;
   }
   T0 = CONS(v4var_name,v1type);
   v3tail = CONS(T0,v3tail);
   goto L8;
L9:;
  }
  value0 = v3tail;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for C1BODY                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7c1body(cl_object v1body, cl_object v2doc_p)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4;                                  /*  ALL-DECLARATIONS */
   cl_object v5;                                  /*  BODY            */
   cl_object v6;                                  /*  DOC             */
   cl_object v7;                                  /*  SPECIALS        */
   value0 = si_process_declarations(2, v1body, v2doc_p);
   v4 = value0;
   {
    const int v8 = cl_env_copy->nvalues;
    cl_object v9;
    v9 = (v8<=1)? ECL_NIL : cl_env_copy->values[1];
    v5 = v9;
    v9 = (v8<=2)? ECL_NIL : cl_env_copy->values[2];
    v6 = v9;
    v9 = (v8<=3)? ECL_NIL : cl_env_copy->values[3];
    v7 = v9;
   }
   {
    cl_object v8others;
    v8others = ECL_NIL;
    {
     cl_object v9types;
     v9types = ECL_NIL;
     {
      cl_object v10ignored;
      v10ignored = ECL_NIL;
      {
       cl_object v11decl;
       cl_object v12;
       v11decl = ECL_NIL;
       if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
       v12 = v4;
       {
        cl_object v13decl_name;
        v13decl_name = ECL_NIL;
        {
         cl_object v14decl_args;
         v14decl_args = ECL_NIL;
L10:;
         if (!(ecl_endp(v12))) { goto L12; }
         goto L11;
L12:;
         v11decl = _ecl_car(v12);
         {
          cl_object v15;
          v15 = _ecl_cdr(v12);
          if (ecl_unlikely(!ECL_LISTP(v15))) FEtype_error_list(v15);
          v12 = v15;
         }
         v13decl_name = ecl_car(v11decl);
         v14decl_args = ecl_cdr(v11decl);
         if (Null(L1valid_form_p(1, v14decl_args))) { goto L27; }
         if (ECL_SYMBOLP(v13decl_name)) { goto L24; }
         goto L25;
L27:;
         goto L25;
L25:;
         ecl_function_dispatch(cl_env_copy,VV[29])(2, _ecl_static_4, v11decl) /*  CMPERR */;
L24:;
         if ((v13decl_name)==(ECL_SYM("SPECIAL",789))) { goto L29; }
         if (!((v13decl_name)==(ECL_SYM("IGNORE",428)))) { goto L31; }
         if ((L1valid_form_p(1, v14decl_args))!=ECL_NIL) { goto L33; }
         ecl_function_dispatch(cl_env_copy,VV[29])(2, _ecl_static_4, v11decl) /*  CMPERR */;
L33:;
         v10ignored = L5parse_ignore_declaration(v14decl_args, ecl_make_fixnum(-1), v10ignored);
         goto L29;
L31:;
         if (!((v13decl_name)==(ECL_SYM("IGNORABLE",427)))) { goto L36; }
         if ((L1valid_form_p(1, v14decl_args))!=ECL_NIL) { goto L38; }
         ecl_function_dispatch(cl_env_copy,VV[29])(2, _ecl_static_4, v11decl) /*  CMPERR */;
L38:;
         v10ignored = L5parse_ignore_declaration(v14decl_args, ecl_make_fixnum(0), v10ignored);
         goto L29;
L36:;
         if (!((v13decl_name)==(ECL_SYM("TYPE",869)))) { goto L41; }
         if (!(ECL_CONSP(v14decl_args))) { goto L46; }
         T0 = ecl_cdr(v14decl_args);
         T1 = (ECL_SYM("SYMBOLP",847)->symbol.gfdef);
         if ((L1valid_form_p(2, T0, T1))!=ECL_NIL) { goto L43; }
         goto L44;
L46:;
         goto L44;
L44:;
         ecl_function_dispatch(cl_env_copy,VV[29])(2, _ecl_static_4, v11decl) /*  CMPERR */;
L43:;
         T0 = ecl_car(v14decl_args);
         T1 = ecl_cdr(v14decl_args);
         v9types = L6collect_declared(T0, T1, v9types);
         goto L29;
L41:;
         if (!((v13decl_name)==(ECL_SYM("OBJECT",2014)))) { goto L50; }
         T0 = (ECL_SYM("SYMBOLP",847)->symbol.gfdef);
         if ((L1valid_form_p(2, v14decl_args, T0))!=ECL_NIL) { goto L52; }
         ecl_function_dispatch(cl_env_copy,VV[29])(2, _ecl_static_4, v11decl) /*  CMPERR */;
L52:;
         v9types = L6collect_declared(ECL_SYM("OBJECT",2014), v14decl_args, v9types);
         goto L29;
L50:;
         if (Null(ecl_memql(v13decl_name,VV[8]))) { goto L56; }
         v8others = CONS(v11decl,v8others);
         goto L29;
L56:;
         if ((L4alien_declaration_p(1, v13decl_name))!=ECL_NIL) { goto L61; }
         if (Null(ecl_function_dispatch(cl_env_copy,VV[33])(1, v13decl_name) /*  POLICY-DECLARATION-NAME-P */)) { goto L59; }
         goto L60;
L61:;
L60:;
         v8others = CONS(v11decl,v8others);
         goto L29;
L59:;
         {
          cl_object v16;                          /*  OK              */
          cl_object v17;                          /*  TYPE            */
          value0 = ecl_function_dispatch(cl_env_copy,VV[34])(1, v13decl_name) /*  VALID-TYPE-SPECIFIER */;
          v16 = value0;
          {
          const int v18 = cl_env_copy->nvalues;
          cl_object v19;
          v19 = (v18<=1)? ECL_NIL : cl_env_copy->values[1];
          v17 = v19;
          }
          if ((v16)!=ECL_NIL) { goto L65; }
          ecl_function_dispatch(cl_env_copy,VV[29])(2, _ecl_static_5, v13decl_name) /*  CMPERR */;
L65:;
          v9types = L6collect_declared(v17, v14decl_args, v9types);
         }
L29:;
         goto L10;
L11:;
         T0 = cl_nreverse(v8others);
         cl_env_copy->nvalues = 7;
         cl_env_copy->values[6] = v4;
         cl_env_copy->values[5] = v6;
         cl_env_copy->values[4] = T0;
         cl_env_copy->values[3] = v10ignored;
         cl_env_copy->values[2] = v9types;
         cl_env_copy->values[1] = v7;
         cl_env_copy->values[0] = v5;
         return cl_env_copy->values[0];
        }
       }
      }
     }
    }
   }
  }
 }
}
/*	function definition for ADD-ONE-DECLARATION                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8add_one_declaration(cl_object v1env, cl_object v2decl)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_car(v2decl);
   if (!((v3)==(ECL_SYM("OPTIMIZE",613)))) { goto L2; }
   T0 = ecl_cdr(v2decl);
   value0 = ecl_function_dispatch(cl_env_copy,VV[36])(2, T0, v1env) /*  CMP-ENV-ADD-OPTIMIZATIONS */;
   return value0;
L2:;
   if (!((v3)==(VV[10]))) { goto L4; }
   {
    cl_object v4flag;
    value0 = ecl_cdr(v2decl);
    if ((value0)!=ECL_NIL) { goto L8; }
    v4flag = VV[11];
    goto L6;
L8:;
    v4flag = value0;
    goto L6;
L6:;
    if (Null(ecl_symbol_value(VV[12]))) { goto L10; }
    T0 = ecl_function_dispatch(cl_env_copy,VV[37])(1, ecl_symbol_value(VV[12])) /*  FUN-CMP-ENV */;
    ecl_function_dispatch(cl_env_copy,VV[38])(3, VV[10], v4flag, T0) /*  CMP-ENV-ADD-DECLARATION */;
    value0 = v1env;
    cl_env_copy->nvalues = 1;
    return value0;
L10:;
    value0 = ecl_function_dispatch(cl_env_copy,VV[38])(3, VV[10], v4flag, v1env) /*  CMP-ENV-ADD-DECLARATION */;
    return value0;
   }
L4:;
   if (!((v3)==(ECL_SYM("FTYPE",393)))) { goto L13; }
   T0 = ecl_cdr(v2decl);
   if (!(ECL_ATOM(T0))) { goto L16; }
   ecl_function_dispatch(cl_env_copy,VV[39])(2, _ecl_static_6, v2decl) /*  CMPWARN */;
   goto L15;
L16:;
   {
    cl_object v6;                                 /*  TYPE-NAME       */
    cl_object v7;                                 /*  ARGS            */
    T0 = ecl_cadr(v2decl);
    value0 = ecl_function_dispatch(cl_env_copy,VV[40])(1, T0) /*  NORMALIZE-TYPE */;
    v6 = value0;
    {
     const int v8 = cl_env_copy->nvalues;
     cl_object v9;
     v9 = (v8<=1)? ECL_NIL : cl_env_copy->values[1];
     v7 = v9;
    }
    if (!((v6)==(ECL_SYM("FUNCTION",396)))) { goto L19; }
    {
     cl_object v8;
     v8 = ecl_cddr(v2decl);
     goto L24;
L23:;
     {
      cl_object v9v;
      v9v = ecl_car(v8);
      v1env = ecl_function_dispatch(cl_env_copy,VV[41])(3, v9v, v7, v1env) /*  ADD-FUNCTION-DECLARATION */;
     }
     v8 = ecl_cdr(v8);
L24:;
     if (Null(v8)) { goto L32; }
     goto L23;
L32:;
     goto L15;
    }
L19:;
    T0 = ecl_cadr(v2decl);
    ecl_function_dispatch(cl_env_copy,VV[39])(2, _ecl_static_7, T0) /*  CMPWARN */;
   }
L15:;
   value0 = v1env;
   cl_env_copy->nvalues = 1;
   return value0;
L13:;
   if (!((v3)==(ECL_SYM("INLINE",434)))) { goto L34; }
   {
    cl_object v5;
    cl_object v6name;
    cl_object v7;
    v5 = ecl_cdr(v2decl);
    v6name = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
    v7 = v5;
L41:;
    if (!(ecl_endp(v7))) { goto L43; }
    goto L42;
L43:;
    v6name = _ecl_car(v7);
    {
     cl_object v8;
     v8 = _ecl_cdr(v7);
     if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
     v7 = v8;
    }
    v1env = ecl_function_dispatch(cl_env_copy,VV[42])(2, v6name, v1env) /*  DECLARE-INLINE */;
    goto L41;
L42:;
   }
   value0 = v1env;
   cl_env_copy->nvalues = 1;
   return value0;
L34:;
   if (!((v3)==(ECL_SYM("NOTINLINE",587)))) { goto L54; }
   {
    cl_object v5;
    cl_object v6name;
    cl_object v7;
    v5 = ecl_cdr(v2decl);
    v6name = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
    v7 = v5;
L61:;
    if (!(ecl_endp(v7))) { goto L63; }
    goto L62;
L63:;
    v6name = _ecl_car(v7);
    {
     cl_object v8;
     v8 = _ecl_cdr(v7);
     if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
     v7 = v8;
    }
    v1env = ecl_function_dispatch(cl_env_copy,VV[43])(2, v6name, v1env) /*  DECLARE-NOTINLINE */;
    goto L61;
L62:;
   }
   value0 = v1env;
   cl_env_copy->nvalues = 1;
   return value0;
L54:;
   if (!((v3)==(ECL_SYM("DECLARATION",273)))) { goto L74; }
   T0 = ecl_cdr(v2decl);
   T1 = ecl_fdefinition(VV[29]);
   L3validate_alien_declaration(T0, T1);
   T0 = ecl_cdr(v2decl);
   value0 = ecl_function_dispatch(cl_env_copy,VV[44])(3, VV[6], T0, v1env) /*  CMP-ENV-EXTEND-DECLARATION */;
   return value0;
L74:;
   if (!((v3)==(VV[13]))) { goto L83; }
   goto L80;
   goto L81;
L83:;
   goto L81;
L81:;
   if (!((v3)==(VV[15]))) { goto L87; }
   goto L80;
   goto L85;
L87:;
   goto L85;
L85:;
   if (!((v3)==(VV[17]))) { goto L91; }
   goto L80;
   goto L89;
L91:;
   goto L89;
L89:;
   if (!(ecl_eql(v3,VV[19]))) { goto L78; }
   goto L79;
L80:;
L79:;
   value0 = v1env;
   cl_env_copy->nvalues = 1;
   return value0;
L78:;
   if (!((v3)==(ECL_SYM("DYNAMIC-EXTENT",320)))) { goto L99; }
   goto L96;
   goto L97;
L99:;
   goto L97;
L97:;
   if (!((v3)==(ECL_SYM("IGNORABLE",427)))) { goto L94; }
   goto L95;
L96:;
L95:;
   value0 = v1env;
   cl_env_copy->nvalues = 1;
   return value0;
L94:;
   T0 = ecl_car(v2decl);
   if (Null(L4alien_declaration_p(2, T0, v1env))) { goto L102; }
   value0 = v1env;
   cl_env_copy->nvalues = 1;
   return value0;
L102:;
   {
    cl_object v5;
    v5 = ecl_function_dispatch(cl_env_copy,VV[45])(2, v2decl, v1env) /*  MAYBE-ADD-POLICY */;
    if (Null(v5)) { goto L105; }
    value0 = v5;
    cl_env_copy->nvalues = 1;
    return value0;
L105:;
    T0 = ecl_car(v2decl);
    ecl_function_dispatch(cl_env_copy,VV[39])(2, _ecl_static_5, T0) /*  CMPWARN */;
    value0 = v1env;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for SYMBOL-MACRO-DECLARATION-P            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L9symbol_macro_declaration_p(cl_object v1name, cl_object v2type)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3record;
   v3record = ecl_function_dispatch(cl_env_copy,VV[47])(1, v1name) /*  CMP-ENV-SEARCH-SYMBOL-MACRO */;
   if (Null(v3record)) { goto L2; }
   if (Null(cl_functionp(v3record))) { goto L2; }
   {
    cl_object v4expression;
    v4expression = ecl_function_dispatch(cl_env_copy,v3record)(2, v1name, ECL_NIL);
    T0 = cl_list(3, ECL_SYM("THE",856), v2type, v4expression);
    ecl_function_dispatch(cl_env_copy,VV[48])(2, v1name, T0) /*  CMP-ENV-REGISTER-SYMBOL-MACRO */;
   }
   value0 = ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for CHECK-VDECL                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L10check_vdecl(cl_object v1vnames, cl_object v2ts, cl_object v3is)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4name;
   cl_object v5type;
   cl_object v6;
   v4name = ECL_NIL;
   v5type = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v2ts))) FEtype_error_list(v2ts);
   v6 = v2ts;
L6:;
   if (!(ecl_endp(v6))) { goto L8; }
   goto L7;
L8:;
   {
    cl_object v7;
    v7 = _ecl_car(v6);
    v4name = ecl_car(v7);
    v7 = ecl_cdr(v7);
    v5type = v7;
   }
   {
    cl_object v7;
    v7 = _ecl_cdr(v6);
    if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
    v6 = v7;
   }
   if ((si_memq(v4name,v1vnames))!=ECL_NIL) { goto L21; }
   if ((L9symbol_macro_declaration_p(v4name, v5type))!=ECL_NIL) { goto L21; }
   ecl_function_dispatch(cl_env_copy,VV[39])(3, _ecl_static_8, v5type, v4name) /*  CMPWARN */;
L21:;
   goto L6;
L7:;
  }
  {
   cl_object v4name;
   cl_object v5expected_uses;
   cl_object v6;
   v4name = ECL_NIL;
   v5expected_uses = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v3is))) FEtype_error_list(v3is);
   v6 = v3is;
L29:;
   if (!(ecl_endp(v6))) { goto L31; }
   goto L30;
L31:;
   {
    cl_object v7;
    v7 = _ecl_car(v6);
    v4name = ecl_car(v7);
    v7 = ecl_cdr(v7);
    v5expected_uses = v7;
   }
   {
    cl_object v7;
    v7 = _ecl_cdr(v6);
    if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
    v6 = v7;
   }
   if ((si_memq(v4name,v1vnames))!=ECL_NIL) { goto L44; }
   if ((ecl_function_dispatch(cl_env_copy,VV[47])(1, v4name) /*  CMP-ENV-SEARCH-SYMBOL-MACRO */)!=ECL_NIL) { goto L44; }
   if ((ecl_function_dispatch(cl_env_copy,VV[50])(1, v4name) /*  CMP-ENV-SEARCH-MACRO */)!=ECL_NIL) { goto L44; }
   if (!(ecl_minusp(v5expected_uses))) { goto L49; }
   T0 = _ecl_static_9;
   goto L48;
L49:;
   T0 = _ecl_static_10;
L48:;
   ecl_function_dispatch(cl_env_copy,VV[39])(2, T0, v4name) /*  CMPWARN */;
L44:;
   goto L29;
L30:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}

#include "cmp/cmpenv-declare.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecl4cTjszxEy6ko9_vmptVE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPENV-DECLARE.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_ecl4cTjszxEy6ko9_vmptVE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[26]);                           /*  VALID-FORM-P    */
 ecl_cmp_defun(VV[27]);                           /*  TYPE-NAME-P     */
 ecl_cmp_defun(VV[28]);                           /*  VALIDATE-ALIEN-DECLARATION */
 ecl_cmp_defun(VV[30]);                           /*  ALIEN-DECLARATION-P */
 (void)0; /* No entry created for PARSE-IGNORE-DECLARATION */
 (void)0; /* No entry created for COLLECT-DECLARED */
 ecl_cmp_defun(VV[32]);                           /*  C1BODY          */
 ecl_cmp_defun(VV[35]);                           /*  ADD-ONE-DECLARATION */
 ecl_cmp_defun(VV[46]);                           /*  SYMBOL-MACRO-DECLARATION-P */
 ecl_cmp_defun(VV[49]);                           /*  CHECK-VDECL     */
}
