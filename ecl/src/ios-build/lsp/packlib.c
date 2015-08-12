/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:LSP;PACKLIB.LSP                                   */
#include <ecl/ecl-cmp.h>
#include "lsp/packlib.eclh"
/*	function definition for FIND-ALL-SYMBOLS                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_find_all_symbols(cl_object v1string_or_symbol)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2symbol_name;
   v2symbol_name = cl_string(v1string_or_symbol);
   {
    cl_object v3;
    cl_object v4;
    cl_object v5;
    v3 = cl_list_all_packages();
    v4 = ECL_NIL;
    v5 = v3;
    {
     cl_object v6;
     cl_object v7;
     v6 = ecl_list1(ECL_NIL);
     v7 = v6;
L7:;
     if (!(ecl_endp(v5))) { goto L9; }
     goto L8;
L9:;
     v4 = _ecl_car(v5);
     {
      cl_object v8;
      v8 = _ecl_cdr(v5);
      if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
      v5 = v8;
     }
     {
      cl_object v8;
      {
       cl_object v10;                             /*  S               */
       cl_object v11;                             /*  I               */
       value0 = cl_find_symbol(2, v2symbol_name, v4);
       v10 = value0;
       v11 = cl_env_copy->values[1];
       if ((v11)==(ECL_SYM("INTERNAL",1258))) { goto L23; }
       if (!((v11)==(ECL_SYM("EXTERNAL",1235)))) { goto L21; }
       goto L22;
L23:;
L22:;
       v8 = ecl_list1(v10);
       goto L19;
L21:;
       v8 = ECL_NIL;
      }
L19:;
      if (ecl_unlikely(ECL_ATOM(v7))) FEtype_error_cons(v7);
      T0 = v7;
      (ECL_CONS_CDR(T0)=v8,T0);
      if (Null(v8)) { goto L17; }
     }
     T0 = ecl_cdr(v7);
     v7 = ecl_last(T0,1);
L17:;
     goto L7;
L8:;
     value0 = ecl_cdr(v6);
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
  }
 }
}
/*	function definition for PACKAGES-ITERATOR                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_packages_iterator(cl_narg narg, cl_object v1packages, cl_object v2options, cl_object v3maybe_list, ...)
{
 cl_object T0, T1;
 cl_object env0;
 cl_object CLV0, CLV1, CLV2, CLV3, CLV4
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg!=3)) FEwrong_num_arguments_anonym();
 {
TTL:
  {
   cl_object env1 = env0;
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(ECL_NIL,env1);              /*  ALL-SYMBOLS     */
   if (ECL_ATOM(v1packages)) { goto L3; }
   if ((v3maybe_list)!=ECL_NIL) { goto L1; }
   goto L2;
L3:;
L2:;
   v1packages = ecl_list1(v1packages);
L1:;
   {
    cl_object v4;
    v4 = v1packages;
    goto L10;
L9:;
    {
     cl_object v5p;
     v5p = ecl_car(v4);
     {
      cl_object v6package;
      v6package = si_coerce_to_package(v5p);
      {
       cl_object v8;                              /*  HASH-EXT        */
       cl_object v9;                              /*  HASH-INT        */
       cl_object v10;                             /*  PACKAGES-USED   */
       value0 = si_package_hash_tables(v6package);
       v8 = value0;
       v9 = cl_env_copy->values[1];
       v10 = cl_env_copy->values[2];
       if (Null(ecl_memql(ECL_SYM("EXTERNAL",1235),v2options))) { goto L17; }
       T0 = cl_list(3, v6package, ECL_SYM("EXTERNAL",1235), v8);
       ECL_CONS_CAR(CLV0) = CONS(T0,ECL_CONS_CAR(CLV0));
L17:;
       if (Null(ecl_memql(ECL_SYM("INTERNAL",1258),v2options))) { goto L20; }
       T0 = cl_list(3, v6package, ECL_SYM("INTERNAL",1258), v9);
       ECL_CONS_CAR(CLV0) = CONS(T0,ECL_CONS_CAR(CLV0));
L20:;
       if (Null(ecl_memql(ECL_SYM("INHERITED",1250),v2options))) { goto L14; }
       {
        cl_object v11;
        v11 = v10;
        goto L27;
L26:;
        {
         cl_object v12p;
         v12p = ecl_car(v11);
         T0 = si_package_hash_tables(v12p);
         T1 = cl_list(3, v6package, ECL_SYM("INHERITED",1250), T0);
         ECL_CONS_CAR(CLV0) = CONS(T1,ECL_CONS_CAR(CLV0));
        }
        v11 = ecl_cdr(v11);
L27:;
        if (Null(v11)) { goto L35; }
        goto L26;
L35:;
       }
      }
     }
L14:;
    }
    v4 = ecl_cdr(v4);
L10:;
    if (Null(v4)) { goto L39; }
    goto L9;
L39:;
   }
   if ((ECL_CONS_CAR(CLV0))!=ECL_NIL) { goto L41; }
   {cl_object v4;
    v4 = ECL_NIL;
    v4 = ecl_make_cfun((cl_objectfn_fixed)LC1__g18,ECL_NIL,Cblock,0);
    value0 = v4;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L41:;
   {
    cl_object env2 = env1;
    {
     cl_object v4;
     v4 = ECL_CONS_CAR(CLV0);
     if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
     if (Null(v4)) { goto L47; }
     {
      cl_object v5;
      v5 = ECL_CONS_CDR(v4);
      ECL_CONS_CAR(CLV0) = v5;
      v4 = ECL_CONS_CAR(v4);
     }
L47:;
     T0 = v4;
    }
    CLV1 = env2 = CONS(T0,env2);                  /*  CURRENT         */
    T0 = ecl_car(ECL_CONS_CAR(CLV1));
    CLV2 = env2 = CONS(T0,env2);                  /*  PACKAGE         */
    T0 = ecl_cadr(ECL_CONS_CAR(CLV1));
    CLV3 = env2 = CONS(T0,env2);                  /*  TYPE            */
    T0 = ecl_caddr(ECL_CONS_CAR(CLV1));
    T1 = si_hash_table_iterator(T0);
    CLV4 = env2 = CONS(T1,env2);                  /*  ITERATOR        */
    {cl_object v4;
     v4 = ECL_NIL;
     v4 = ecl_make_cclosure_va((cl_objectfn)LC2iterate,env2,Cblock);
     value0 = v4;
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
  }
 }
}
/*	local function G18                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC1__g18()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  cl_env_copy->nvalues = 4;
  cl_env_copy->values[3] = ECL_NIL;
  cl_env_copy->values[2] = ECL_NIL;
  cl_env_copy->values[1] = ECL_NIL;
  cl_env_copy->values[0] = ECL_NIL;
  return cl_env_copy->values[0];
 }
}
/*	closure ITERATE                                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC2iterate(cl_narg narg, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1, CLV2, CLV3, CLV4
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV4 = env0;                                     /*  ITERATOR        */
 CLV3 = _ecl_cdr(CLV4);
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=0)) FEwrong_num_arguments_anonym();
 {
TTL:
L1:;
  {
   cl_object v2;                                  /*  FOUND           */
   cl_object v3;                                  /*  KEY             */
   cl_object v4;                                  /*  VALUE           */
   value0 = ecl_function_dispatch(cl_env_copy,ECL_CONS_CAR(CLV4))(0);
   v2 = value0;
   {
    const int v5 = cl_env_copy->nvalues;
    cl_object v6;
    v6 = (v5<=1)? ECL_NIL : cl_env_copy->values[1];
    v3 = v6;
    v6 = (v5<=2)? ECL_NIL : cl_env_copy->values[2];
    v4 = v6;
   }
   if (Null(v2)) { goto L4; }
   T0 = ECL_CONS_CAR(CLV3);
   if (!((T0)==(ECL_SYM("INHERITED",1250)))) { goto L6; }
   {
    cl_object v6;                                 /*  S               */
    cl_object v7;                                 /*  ACCESS          */
    T0 = ecl_symbol_name(v4);
    value0 = cl_find_symbol(2, T0, ECL_CONS_CAR(CLV2));
    v6 = value0;
    v7 = cl_env_copy->values[1];
    if (!((v6)==(v4))) { goto L11; }
    if ((v7)==(ECL_CONS_CAR(CLV3))) { goto L6; }
    goto L9;
L11:;
    goto L9;
L9:;
    goto L1;
   }
L6:;
   T0 = ECL_CONS_CAR(CLV3);
   cl_env_copy->nvalues = 4;
   cl_env_copy->values[3] = ECL_CONS_CAR(CLV2);
   cl_env_copy->values[2] = T0;
   cl_env_copy->values[1] = v4;
   cl_env_copy->values[0] = ECL_T;
   return cl_env_copy->values[0];
L4:;
   if (!(ECL_CONS_CAR(CLV0)==ECL_NIL)) { goto L13; }
   cl_env_copy->nvalues = 4;
   cl_env_copy->values[3] = ECL_NIL;
   cl_env_copy->values[2] = ECL_NIL;
   cl_env_copy->values[1] = ECL_NIL;
   cl_env_copy->values[0] = ECL_NIL;
   return cl_env_copy->values[0];
L13:;
   {
    cl_object v5;
    v5 = ECL_CONS_CAR(CLV0);
    if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
    if (Null(v5)) { goto L20; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     ECL_CONS_CAR(CLV0) = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L20:;
    ECL_CONS_CAR(CLV1) = v5;
   }
   ECL_CONS_CAR(CLV2) = ecl_car(ECL_CONS_CAR(CLV1));
   ECL_CONS_CAR(CLV3) = ecl_cadr(ECL_CONS_CAR(CLV1));
   T0 = ecl_caddr(ECL_CONS_CAR(CLV1));
   ECL_CONS_CAR(CLV4) = si_hash_table_iterator(T0);
  }
  goto L1;
 }
 }
}
/*	local function WITH-PACKAGE-ITERATOR                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC3with_package_iterator(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6iterator;
   cl_object v7package_list;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v8;
    v8 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4 = v8;
   }
   v5 = v4;
   if (!(v5==ECL_NIL)) { goto L10; }
   si_dm_too_few_arguments(v1);
L10:;
   {
    cl_object v8;
    v8 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v6iterator = v8;
   }
   if (!(v5==ECL_NIL)) { goto L16; }
   si_dm_too_few_arguments(v1);
L16:;
   {
    cl_object v8;
    v8 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v7package_list = v8;
   }
   if (Null(v5)) { goto L22; }
   {
    cl_object v8aux;
    v8aux = cl_set_difference(2, v5, VV[1]);
    if (Null(v8aux)) { goto L21; }
    T0 = ecl_list1(v8aux);
    si_signal_simple_error(4, ECL_SYM("PROGRAM-ERROR",672), ECL_NIL, _ecl_static_1, T0);
    goto L21;
   }
L22:;
   si_signal_simple_error(4, ECL_SYM("PROGRAM-ERROR",672), ECL_NIL, _ecl_static_2, ECL_NIL);
L21:;
   T0 = cl_list(2, ECL_SYM("QUOTE",679), v5);
   T1 = cl_list(4, VV[0], v7package_list, T0, ECL_T);
   T2 = cl_list(2, v6iterator, T1);
   T3 = ecl_list1(T2);
   T4 = cl_list(2, ECL_SYM("QUOTE",679), v6iterator);
   T5 = cl_list(3, ECL_SYM("LIST",481), VV[2], T4);
   T6 = cl_list(3, v6iterator, ECL_NIL, T5);
   T7 = ecl_list1(T6);
   T8 = cl_listX(3, ECL_SYM("MACROLET",521), T7, v3);
   value0 = cl_list(3, ECL_SYM("LET",477), T3, T8);
   return value0;
  }
 }
}
/*	function definition for EXPAND-DO-SYMBOLS                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4expand_do_symbols(cl_object v1var, cl_object v2package, cl_object v3result_form, cl_object v4body, cl_object v5options)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6i;
   cl_object v7found;
   cl_object v8declaration;
   cl_object v9doc;
   v6i = cl_gensym(0);
   v7found = cl_gensym(0);
   v8declaration = ECL_NIL;
   v9doc = ECL_NIL;
   value0 = si_find_declarations(2, v4body, ECL_NIL);
   v8declaration = value0;
   {
    const int v10 = cl_env_copy->nvalues;
    cl_object v11;
    v11 = (v10<=1)? ECL_NIL : cl_env_copy->values[1];
    v4body = v11;
    v11 = (v10<=2)? ECL_NIL : cl_env_copy->values[2];
    v9doc = v11;
   }
   T0 = cl_list(2, ECL_SYM("QUOTE",679), v5options);
   T1 = cl_list(4, VV[0], v2package, T0, ECL_T);
   T2 = cl_list(2, v6i, T1);
   T3 = cl_list(3, T2, v7found, v1var);
   T4 = cl_list(2, v7found, v1var);
   T5 = cl_list(2, ECL_SYM("FUNCALL",394), v6i);
   T6 = cl_list(3, ECL_SYM("MULTIPLE-VALUE-SETQ",576), T4, T5);
   T7 = cl_list(2, ECL_SYM("RETURN",724), v3result_form);
   T8 = cl_list(3, ECL_SYM("UNLESS",883), v7found, T7);
   T9 = cl_listX(3, T6, T8, v4body);
   T10 = ecl_append(v8declaration,T9);
   value0 = cl_listX(4, ECL_SYM("DO*",308), T3, VV[4], T10);
   return value0;
  }
 }
}
/*	local function DO-SYMBOLS                                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC5do_symbols(cl_object v1, cl_object v2)
{
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
   cl_object v7package;
   cl_object v8result_form;
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
   if (Null(v5)) { goto L16; }
   {
    cl_object v9;
    v9 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v7package = v9;
    goto L15;
   }
L16:;
   v7package = ECL_SYM("*PACKAGE*",43);
L15:;
   if (Null(v5)) { goto L22; }
   {
    cl_object v9;
    v9 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v8result_form = v9;
    goto L21;
   }
L22:;
   v8result_form = ECL_NIL;
L21:;
   if (Null(v5)) { goto L27; }
   si_dm_too_many_arguments(v1);
L27:;
   value0 = L4expand_do_symbols(v6var, v7package, v8result_form, v3, VV[5]);
   return value0;
  }
 }
}
/*	local function DO-EXTERNAL-SYMBOLS                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC6do_external_symbols(cl_object v1, cl_object v2)
{
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
   cl_object v7package;
   cl_object v8result_form;
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
   if (Null(v5)) { goto L16; }
   {
    cl_object v9;
    v9 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v7package = v9;
    goto L15;
   }
L16:;
   v7package = ECL_SYM("*PACKAGE*",43);
L15:;
   if (Null(v5)) { goto L22; }
   {
    cl_object v9;
    v9 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v8result_form = v9;
    goto L21;
   }
L22:;
   v8result_form = ECL_NIL;
L21:;
   if (Null(v5)) { goto L27; }
   si_dm_too_many_arguments(v1);
L27:;
   value0 = L4expand_do_symbols(v6var, v7package, v8result_form, v3, VV[7]);
   return value0;
  }
 }
}
/*	local function DO-ALL-SYMBOLS                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC7do_all_symbols(cl_object v1, cl_object v2)
{
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
   cl_object v7result_form;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v8;
    v8 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4 = v8;
   }
   v5 = v4;
   if (!(v5==ECL_NIL)) { goto L10; }
   si_dm_too_few_arguments(v1);
L10:;
   {
    cl_object v8;
    v8 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v6var = v8;
   }
   if (Null(v5)) { goto L16; }
   {
    cl_object v8;
    v8 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v7result_form = v8;
    goto L15;
   }
L16:;
   v7result_form = ECL_NIL;
L15:;
   if (Null(v5)) { goto L21; }
   si_dm_too_many_arguments(v1);
L21:;
   value0 = L4expand_do_symbols(v6var, VV[9], v7result_form, v3, VV[10]);
   return value0;
  }
 }
}
/*	function definition for PRINT-SYMBOL-APROPOS                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8print_symbol_apropos(cl_object v1symbol)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_prin1(v1symbol,ECL_NIL);
  if (Null(cl_fboundp(v1symbol))) { goto L2; }
  if (Null(cl_special_operator_p(v1symbol))) { goto L4; }
  ecl_princ_str("  Special form",ECL_NIL);
  goto L2;
L4:;
  if (Null(cl_macro_function(1, v1symbol))) { goto L7; }
  ecl_princ_str("  Macro",ECL_NIL);
  goto L2;
L7:;
  ecl_princ_str("  Function",ECL_NIL);
L2:;
  if (!(ecl_boundp(cl_env_copy,v1symbol))) { goto L11; }
  if (Null(cl_constantp(1, v1symbol))) { goto L14; }
  ecl_princ_str("  Constant: ",ECL_NIL);
  goto L13;
L14:;
  ecl_princ_str("  has value: ",ECL_NIL);
L13:;
  T0 = cl_symbol_value(v1symbol);
  ecl_prin1(T0,ECL_NIL);
L11:;
  value0 = ecl_terpri(ECL_NIL);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for APROPOS                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_apropos(cl_narg narg, cl_object v1string, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2package;
  va_list args; va_start(args,v1string);
  {
   int i = 1;
   if (i >= narg) {
    v2package = ECL_NIL;
   } else {
    i++;
    v2package = va_arg(args,cl_object);
   }
  }
  va_end(args);
  v1string = cl_string(v1string);
  {
   cl_object v3;
   v3 = cl_apropos_list(2, v1string, v2package);
   {
    cl_object v4;
    cl_object v5;
    v4 = ECL_NIL;
    v5 = v3;
L8:;
    if (!(ecl_endp(v5))) { goto L10; }
    goto L9;
L10:;
    v4 = _ecl_car(v5);
    {
     cl_object v6;
     v6 = _ecl_cdr(v5);
     if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
     v5 = v6;
    }
    L8print_symbol_apropos(v4);
    goto L8;
L9:;
    goto L4;
   }
  }
L4:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  return value0;
 }
}
/*	function definition for APROPOS-LIST                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_apropos_list(cl_narg narg, cl_object v1string, ...)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2package;
  va_list args; va_start(args,v1string);
  {
   int i = 1;
   if (i >= narg) {
    v2package = ECL_NIL;
   } else {
    i++;
    v2package = va_arg(args,cl_object);
   }
  }
  va_end(args);
  T0 = L10apropos_list_inner(v1string, v2package);
  T1 = cl_delete_duplicates(1, T0);
  {cl_object v3;
   v3 = ECL_NIL;
   v3 = ecl_make_cfun((cl_objectfn_fixed)LC9__g82,ECL_NIL,Cblock,2);
   T2 = v3;
  }
  value0 = cl_sort(2, T1, T2);
  return value0;
 }
}
/*	local function G82                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC9__g82(cl_object v1s1, cl_object v2s2)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_prin1_to_string(v1s1);
  T1 = cl_prin1_to_string(v2s2);
  value0 = cl_string_lessp(2, T0, T1);
  return value0;
 }
}
/*	function definition for APROPOS-LIST-INNER                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L10apropos_list_inner(cl_object v1string, cl_object v2package)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3list;
   cl_object v4string;
   v3list = ECL_NIL;
   v4string = cl_string(v1string);
   if (Null(v2package)) { goto L4; }
   {
    cl_object v5;
    v5 = cl_package_use_list(v2package);
    goto L10;
L9:;
    {
     cl_object v6p;
     v6p = ecl_car(v5);
     T0 = L10apropos_list_inner(v4string, v6p);
     v3list = ecl_nconc(T0,v3list);
    }
    v5 = ecl_cdr(v5);
L10:;
    if (Null(v5)) { goto L18; }
    goto L9;
L18:;
   }
   {
    cl_object v5;
    cl_object v6;
    cl_object v7symbol;
    v5 = si_packages_iterator(3, v2package, VV[5], ECL_T);
    v6 = ECL_NIL;
    v7symbol = ECL_NIL;
    goto L25;
L24:;
    value0 = ecl_function_dispatch(cl_env_copy,v5)(0);
    v6 = value0;
    {
     const int v8 = cl_env_copy->nvalues;
     cl_object v9;
     v9 = (v8<=1)? ECL_NIL : cl_env_copy->values[1];
     v7symbol = v9;
    }
    if ((v6)!=ECL_NIL) { goto L29; }
    goto L3;
L29:;
    T0 = cl_string(v7symbol);
    T1 = (ECL_SYM("CHAR-EQUAL",207)->symbol.gfdef);
    if (Null(cl_search(4, v4string, T0, ECL_SYM("TEST",1316), T1))) { goto L31; }
    v3list = CONS(v7symbol,v3list);
L31:;
L25:;
    goto L24;
    goto L3;
   }
L4:;
   {
    cl_object v8;
    cl_object v9;
    cl_object v10symbol;
    T0 = cl_list_all_packages();
    v8 = si_packages_iterator(3, T0, VV[10], ECL_T);
    v9 = ECL_NIL;
    v10symbol = ECL_NIL;
    goto L41;
L40:;
    value0 = ecl_function_dispatch(cl_env_copy,v8)(0);
    v9 = value0;
    {
     const int v11 = cl_env_copy->nvalues;
     cl_object v12;
     v12 = (v11<=1)? ECL_NIL : cl_env_copy->values[1];
     v10symbol = v12;
    }
    if ((v9)!=ECL_NIL) { goto L45; }
    goto L3;
L45:;
    T0 = cl_string(v10symbol);
    T1 = (ECL_SYM("CHAR-EQUAL",207)->symbol.gfdef);
    if (Null(cl_search(4, v4string, T0, ECL_SYM("TEST",1316), T1))) { goto L47; }
    v3list = CONS(v10symbol,v3list);
L47:;
L41:;
    goto L40;
   }
L3:;
   value0 = v3list;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for FIND-RELATIVE-PACKAGE                 */
/*	optimize speed 3, debug 1, space 1, safety 2                  */
cl_object si_find_relative_package(cl_narg narg, cl_object v1name, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  if (!(ECL_STRINGP(v1name))) { goto L1; }
  {
   cl_fixnum v2;
   v2 = ecl_length(v1name);
   if (!((v2)>0)) { goto L1; }
  }
  {
   ecl_character v2;
   v2 = ecl_char(v1name,0);
   if (!(((ecl_character)(46))==(v2))) { goto L1; }
  }
  {
   cl_object v2last_dot_position;
   cl_object v3name;
   value0 = LC12find_non_dot(v1name);
   if ((value0)!=ECL_NIL) { goto L7; }
   v2last_dot_position = ecl_make_fixnum(ecl_length(v1name));
   goto L5;
L7:;
   v2last_dot_position = value0;
   goto L5;
L5:;
   v3name = cl_subseq(2, v1name, v2last_dot_position);
   {
    cl_object v4p;
    v4p = ecl_symbol_value(ECL_SYM("*PACKAGE*",43));
    {
     cl_object v5;
     v5 = ecl_make_integer((ecl_to_fixnum(v2last_dot_position))-1);
     {
      cl_fixnum v6i;
      v6i = 0;
      goto L15;
L14:;
      {
       cl_object v7tmp;
       v7tmp = si_package_parent(1, v4p);
       if ((v7tmp)!=ECL_NIL) { goto L19; }
       cl_error(2, _ecl_static_9, v4p);
L19:;
       v4p = v7tmp;
      }
      {
       cl_object v7;
       v7 = ecl_make_integer((v6i)+1);
       {
        bool v8;
        v8 = ECL_FIXNUMP(v7);
        if (ecl_unlikely(!(v8)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v7);
       }
       v6i = ecl_fixnum(v7);
      }
L15:;
      if (!(ecl_number_compare(ecl_make_fixnum(v6i),v5)<0)) { goto L26; }
      goto L14;
L26:;
     }
    }
    value0 = LC11relative_to(v4p, v3name);
    return value0;
   }
  }
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function FIND-NON-DOT                                   */
/*	optimize speed 3, debug 1, space 1, safety 2                  */
static cl_object LC12find_non_dot(cl_object v1name)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v2len;
   cl_fixnum v3i;
   v2len = ecl_length(v1name);
   v3i = 0;
   goto L5;
L4:;
   {
    ecl_character v4;
    v4 = ecl_char(v1name,v3i);
    if (!(((ecl_character)(46))!=(v4))) { goto L7; }
   }
   value0 = ecl_make_fixnum(v3i);
   cl_env_copy->nvalues = 1;
   return value0;
L7:;
   {
    cl_object v4;
    v4 = ecl_make_integer((v3i)+1);
    {
     bool v5;
     v5 = ECL_FIXNUMP(v4);
     if (ecl_unlikely(!(v5)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v4);
    }
    v3i = ecl_fixnum(v4);
   }
L5:;
   if ((v3i)==(v2len)) { goto L13; }
   goto L4;
L13:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function RELATIVE-TO                                    */
/*	optimize speed 3, debug 1, space 1, safety 2                  */
static cl_object LC11relative_to(cl_object v1package, cl_object v2name)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v3;
   v3 = ecl_length(v2name);
   if (!((v3)==0)) { goto L1; }
  }
  value0 = v1package;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  T0 = cl_package_name(v1package);
  T1 = cl_concatenate(4, ECL_SYM("SIMPLE-STRING",771), T0, _ecl_static_8, v2name);
  value0 = cl_find_package(T1);
  return value0;
 }
}
/*	function definition for PACKAGE-PARENT                        */
/*	optimize speed 3, debug 1, space 1, safety 2                  */
cl_object si_package_parent(cl_narg narg, cl_object v1package_specifier, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  {
   cl_object v2child;
   cl_object v3dot_position;
   if (Null(cl_packagep(v1package_specifier))) { goto L2; }
   v2child = cl_package_name(v1package_specifier);
   goto L1;
L2:;
   if (!(ECL_SYMBOLP(v1package_specifier))) { goto L4; }
   v2child = ecl_symbol_name(v1package_specifier);
   goto L1;
L4:;
   if (!(ECL_STRINGP(v1package_specifier))) { goto L6; }
   v2child = v1package_specifier;
   goto L1;
L6:;
   v2child = cl_error(2, _ecl_static_10, v1package_specifier);
L1:;
   v3dot_position = LC13find_last_dot(v2child);
   if (Null(v3dot_position)) { goto L9; }
   {
    cl_object v4parent;
    v4parent = cl_subseq(3, v2child, ecl_make_fixnum(0), v3dot_position);
    value0 = cl_find_package(v4parent);
    if ((value0)!=ECL_NIL) { goto L13; }
    cl_error(2, _ecl_static_9, v2child);
    goto L9;
L13:;
    goto L9;
   }
L9:;
   value0 = cl_error(2, _ecl_static_11, v2child);
   return value0;
  }
 }
}
/*	local function FIND-LAST-DOT                                  */
/*	optimize speed 3, debug 1, space 1, safety 2                  */
static cl_object LC13find_last_dot(cl_object v1name)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v2len;
   cl_fixnum v3i;
   {
    cl_object v4;
    {
     cl_fixnum v5;
     v5 = ecl_length(v1name);
     v4 = ecl_make_integer((v5)-1);
    }
    {
     bool v5;
     v5 = ECL_FIXNUMP(v4);
     if (ecl_unlikely(!(v5)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v4);
    }
    v2len = ecl_fixnum(v4);
   }
   v3i = v2len;
   goto L7;
L6:;
   {
    ecl_character v4;
    v4 = ecl_char(v1name,v3i);
    if (!(((ecl_character)(46))==(v4))) { goto L9; }
   }
   value0 = ecl_make_fixnum(v3i);
   cl_env_copy->nvalues = 1;
   return value0;
L9:;
   {
    cl_object v4;
    v4 = ecl_make_integer((v3i)-1);
    {
     bool v5;
     v5 = ECL_FIXNUMP(v4);
     if (ecl_unlikely(!(v5)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v4);
    }
    v3i = ecl_fixnum(v4);
   }
L7:;
   if ((v3i)==(-1)) { goto L15; }
   goto L6;
L15:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for PACKAGE-CHILDREN                      */
/*	optimize speed 3, debug 1, space 1, safety 2                  */
cl_object si_package_children(cl_narg narg, cl_object v1package_specifier, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2recurse;
  ecl_va_list args; ecl_va_start(args,v1package_specifier,narg,1);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,si_package_childrenkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[1])) {
    v2recurse = ECL_T;
   } else {
    v2recurse = keyvars[0];
   }
  }
  {
   cl_object v3res;
   cl_object v4parent;
   cl_object v5parent_prefix;
   v3res = ECL_NIL;
   if (Null(cl_packagep(v1package_specifier))) { goto L4; }
   v4parent = cl_package_name(v1package_specifier);
   goto L3;
L4:;
   if (!(ECL_SYMBOLP(v1package_specifier))) { goto L6; }
   v4parent = ecl_symbol_name(v1package_specifier);
   goto L3;
L6:;
   if (!(ECL_STRINGP(v1package_specifier))) { goto L8; }
   v4parent = v1package_specifier;
   goto L3;
L8:;
   v4parent = cl_error(2, _ecl_static_10, v1package_specifier);
L3:;
   v5parent_prefix = cl_concatenate(3, ECL_SYM("SIMPLE-STRING",771), v4parent, _ecl_static_8);
   {
    cl_object v6;
    v6 = cl_list_all_packages();
    goto L14;
L13:;
    {
     cl_object v7package;
     v7package = ecl_car(v6);
     {
      cl_object v8package_name;
      cl_object v9prefix;
      v8package_name = cl_package_name(v7package);
      v9prefix = LC14string_prefix_p(v5parent_prefix, v8package_name);
      if (Null(v9prefix)) { goto L18; }
      if ((v2recurse)!=ECL_NIL) { goto L23; }
      {
       cl_object v10;
       v10 = si_make_seq_iterator(2, v8package_name, ecl_make_fixnum(0));
L26:;
       if ((v10)!=ECL_NIL) { goto L28; }
       goto L21;
L28:;
       {
        cl_object v11;
        v11 = si_seq_iterator_ref(v8package_name, v10);
        if (!((ECL_CODE_CHAR((ecl_character)(46))==(v11)))) { goto L30; }
        if ((v11)!=ECL_NIL) { goto L18; }
        goto L21;
       }
L30:;
       v10 = si_seq_iterator_next(v8package_name, v10);
       goto L26;
      }
L23:;
L21:;
      v3res = cl_adjoin(2, v7package, v3res);
     }
L18:;
    }
    v6 = ecl_cdr(v6);
L14:;
    if (Null(v6)) { goto L38; }
    goto L13;
L38:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	local function STRING-PREFIX-P                                */
/*	optimize speed 3, debug 1, space 1, safety 2                  */
static cl_object LC14string_prefix_p(cl_object v1prefix, cl_object v2string)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v3;
   cl_fixnum v4;
   v3 = ecl_length(v1prefix);
   v4 = ecl_length(v2string);
   if (!((v3)>=(v4))) { goto L3; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L3:;
   {
    cl_fixnum v5i;
    v5i = 0;
    goto L8;
L7:;
    {
     ecl_character v6;
     v6 = ecl_char(v1prefix,v5i);
     {
      ecl_character v7;
      v7 = ecl_char(v2string,v5i);
      if ((v6)==(v7)) { goto L10; }
     }
    }
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
L10:;
    {
     cl_object v6;
     v6 = ecl_make_integer((v5i)+1);
     {
      bool v7;
      v7 = ECL_FIXNUMP(v6);
      if (ecl_unlikely(!(v7)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v6);
     }
     v5i = ecl_fixnum(v6);
    }
L8:;
    if ((v5i)==(v3)) { goto L16; }
    goto L7;
L16:;
    value0 = ecl_make_fixnum(v3);
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}

#include "lsp/packlib.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclYut87CEiaxyl9_5jqTOE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:LSP;PACKLIB.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclYut87CEiaxyl9_5jqTOE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 (void)0; /* No entry created for FIND-ALL-SYMBOLS */
 ecl_cmp_defun(VV[13]);                           /*  PACKAGES-ITERATOR */
 ecl_cmp_defmacro(VV[14]);                        /*  WITH-PACKAGE-ITERATOR */
 (void)0; /* No entry created for EXPAND-DO-SYMBOLS */
 ecl_cmp_defmacro(VV[15]);                        /*  DO-SYMBOLS      */
 ecl_cmp_defmacro(VV[16]);                        /*  DO-EXTERNAL-SYMBOLS */
 ecl_cmp_defmacro(VV[17]);                        /*  DO-ALL-SYMBOLS  */
 ecl_cmp_defun(VV[18]);                           /*  PRINT-SYMBOL-APROPOS */
 (void)0; /* No entry created for APROPOS */
 (void)0; /* No entry created for APROPOS-LIST */
 (void)0; /* No entry created for APROPOS-LIST-INNER */
 (void)0; /* No entry created for FIND-RELATIVE-PACKAGE */
 (void)0; /* No entry created for PACKAGE-PARENT */
 (void)0; /* No entry created for PACKAGE-CHILDREN */
}
