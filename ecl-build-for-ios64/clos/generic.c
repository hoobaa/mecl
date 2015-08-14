/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CLOS;GENERIC.LSP                                  */
#include <ecl/ecl-cmp.h>
#include "clos/generic.eclh"
/*	local function DEFGENERIC                                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC1defgeneric(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_cdr(v1);
   {
    cl_object v5;                                 /*  FUNCTION-SPECIFIER */
    cl_object v6;                                 /*  LAMBDA-LIST     */
    cl_object v7;                                 /*  OPTIONS         */
    value0 = L2parse_defgeneric(v3);
    v5 = value0;
    {
     const int v8 = cl_env_copy->nvalues;
     cl_object v9;
     v9 = (v8<=1)? ECL_NIL : cl_env_copy->values[1];
     v6 = v9;
     v9 = (v8<=2)? ECL_NIL : cl_env_copy->values[2];
     v7 = v9;
    }
    L4parse_lambda_list(1, v6);
    {
     cl_object v9;                                /*  OPTION-LIST     */
     cl_object v10;                               /*  METHOD-LIST     */
     value0 = L3parse_generic_options(v7, v6);
     v9 = value0;
     {
      const int v11 = cl_env_copy->nvalues;
      cl_object v12;
      v12 = (v11<=1)? ECL_NIL : cl_env_copy->values[1];
      v10 = v12;
     }
     {
      cl_object v11output;
      T0 = cl_list(2, ECL_SYM("QUOTE",679), v5);
      v11output = cl_listX(5, ECL_SYM("ENSURE-GENERIC-FUNCTION",942), T0, VV[0], ECL_T, v9);
      if (Null(ecl_symbol_value(ECL_SYM("*REGISTER-WITH-PDE-HOOK*",1181)))) { goto L6; }
      T0 = cl_copy_tree(ecl_symbol_value(ECL_SYM("*SOURCE-LOCATION*",1180)));
      if (Null(v10)) { goto L9; }
      T2 = cl_list(2, ECL_SYM("QUOTE",679), v5);
      {
       cl_object v12m;
       cl_object v13;
       v12m = ECL_NIL;
       if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
       v13 = v10;
       {
        cl_object v14;
        cl_object v15;
        v14 = ecl_list1(ECL_NIL);
        v15 = v14;
L17:;
        if (!(ecl_endp(v13))) { goto L19; }
        goto L18;
L19:;
        v12m = _ecl_car(v13);
        {
         cl_object v16;
         v16 = _ecl_cdr(v13);
         if (ecl_unlikely(!ECL_LISTP(v16))) FEtype_error_list(v16);
         v13 = v16;
        }
        if (ecl_unlikely(ECL_ATOM(v15))) FEtype_error_cons(v15);
        T4 = v15;
        T5 = cl_listX(3, ECL_SYM("DEFMETHOD",940), v5, v12m);
        v15 = ecl_list1(T5);
        (ECL_CONS_CDR(T4)=v15,T4);
        goto L17;
L18:;
        T3 = ecl_cdr(v14);
        goto L11;
       }
      }
L11:;
      T4 = cl_listX(3, VV[1], T2, T3);
      T1 = cl_list(3, ECL_SYM("PROGN",671), v11output, T4);
      goto L8;
L9:;
      T1 = v11output;
L8:;
      value0 = ecl_function_dispatch(cl_env_copy,ecl_symbol_value(ECL_SYM("*REGISTER-WITH-PDE-HOOK*",1181)))(3, T0, v1, T1);
      return value0;
L6:;
      if (Null(v10)) { goto L33; }
      T0 = cl_list(2, ECL_SYM("QUOTE",679), v5);
      {
       cl_object v12m;
       cl_object v13;
       v12m = ECL_NIL;
       if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
       v13 = v10;
       {
        cl_object v14;
        cl_object v15;
        v14 = ecl_list1(ECL_NIL);
        v15 = v14;
L41:;
        if (!(ecl_endp(v13))) { goto L43; }
        goto L42;
L43:;
        v12m = _ecl_car(v13);
        {
         cl_object v16;
         v16 = _ecl_cdr(v13);
         if (ecl_unlikely(!ECL_LISTP(v16))) FEtype_error_list(v16);
         v13 = v16;
        }
        if (ecl_unlikely(ECL_ATOM(v15))) FEtype_error_cons(v15);
        T2 = v15;
        T3 = cl_listX(3, ECL_SYM("DEFMETHOD",940), v5, v12m);
        v15 = ecl_list1(T3);
        (ECL_CONS_CDR(T2)=v15,T2);
        goto L41;
L42:;
        T1 = ecl_cdr(v14);
        goto L35;
       }
      }
L35:;
      T2 = cl_listX(3, VV[1], T0, T1);
      value0 = cl_list(3, ECL_SYM("PROGN",671), v11output, T2);
      return value0;
L33:;
      value0 = v11output;
      cl_env_copy->nvalues = 1;
      return value0;
     }
    }
   }
  }
 }
}
/*	function definition for PARSE-DEFGENERIC                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2parse_defgeneric(cl_object v1args)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2function_specifier;
   v2function_specifier = ECL_NIL;
   if ((v1args)!=ECL_NIL) { goto L2; }
   si_simple_program_error(1, _ecl_static_1);
L2:;
   {
    cl_object v3;
    v3 = v1args;
    if (ecl_unlikely(!ECL_LISTP(v3))) FEtype_error_list(v3);
    if (Null(v3)) { goto L9; }
    {
     cl_object v4;
     v4 = ECL_CONS_CDR(v3);
     v1args = v4;
     v3 = ECL_CONS_CAR(v3);
    }
L9:;
    v2function_specifier = v3;
   }
   if ((v1args)!=ECL_NIL) { goto L15; }
   si_simple_program_error(1, _ecl_static_2);
L15:;
   T0 = ecl_car(v1args);
   T1 = ecl_cdr(v1args);
   cl_env_copy->nvalues = 3;
   cl_env_copy->values[2] = T1;
   cl_env_copy->values[1] = T0;
   cl_env_copy->values[0] = v2function_specifier;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for PARSE-GENERIC-OPTIONS                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3parse_generic_options(cl_object v1options, cl_object v2lambda_list)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3processed_options;
   cl_object v4method_list;
   cl_object v5declarations;
   cl_object v6arg_list;
   v3processed_options = ECL_NIL;
   v4method_list = ECL_NIL;
   v5declarations = ECL_NIL;
   v6arg_list = ECL_NIL;
   {
    cl_object v7;
    v7 = v1options;
    goto L9;
L8:;
    {
     cl_object v8option;
     v8option = ecl_car(v7);
     {
      cl_object v9;
      cl_object v10option_value;
      v9 = ecl_car(v8option);
      v10option_value = ECL_NIL;
      if (!((v9)==(ECL_SYM("METHOD",1001)))) { goto L16; }
      T0 = ecl_cdr(v8option);
      v4method_list = CONS(T0,v4method_list);
      goto L13;
L16:;
      if (!((v9)==(ECL_SYM("DECLARE",274)))) { goto L19; }
      T0 = ecl_cdr(v8option);
      v5declarations = ecl_append(T0,v5declarations);
      goto L13;
L19:;
      if (Null(ecl_memql(v9,v3processed_options))) { goto L22; }
      si_simple_program_error(2, _ecl_static_3, v9);
      goto L13;
L22:;
      v3processed_options = CONS(v9,v3processed_options);
      if (!(ecl_eql(v9,ECL_SYM("ARGUMENT-PRECEDENCE-ORDER",984)))) { goto L28; }
      v10option_value = ecl_cdr(v8option);
      goto L27;
L28:;
      if (!(ecl_eql(v9,ECL_SYM("METHOD-COMBINATION",1003)))) { goto L30; }
      v10option_value = ecl_cdr(v8option);
      goto L27;
L30:;
      if (!(ecl_eql(v9,ECL_SYM("DOCUMENTATION",1222)))) { goto L37; }
      goto L34;
      goto L35;
L37:;
      goto L35;
L35:;
      if (!(ecl_eql(v9,ECL_SYM("GENERIC-FUNCTION-CLASS",992)))) { goto L41; }
      goto L34;
      goto L39;
L41:;
      goto L39;
L39:;
      if (!(ecl_eql(v9,ECL_SYM("METHOD-CLASS",1002)))) { goto L32; }
      goto L33;
L34:;
L33:;
      T0 = ecl_cddr(v8option);
      if (ecl_endp(T0)) { goto L44; }
      si_simple_program_error(2, _ecl_static_4, v9);
L44:;
      v10option_value = ecl_cadr(v8option);
      goto L27;
L32:;
      v10option_value = si_simple_program_error(2, _ecl_static_5, v9);
L27:;
      T0 = cl_list(2, ECL_SYM("QUOTE",679), v9);
      T1 = cl_list(2, ECL_SYM("QUOTE",679), v10option_value);
      v6arg_list = cl_listX(3, T0, T1, v6arg_list);
     }
L13:;
    }
    v7 = ecl_cdr(v7);
L9:;
    if (Null(v7)) { goto L49; }
    goto L8;
L49:;
   }
   T0 = cl_list(2, ECL_SYM("QUOTE",679), v2lambda_list);
   if (Null(v5declarations)) { goto L52; }
   T2 = cl_list(2, ECL_SYM("QUOTE",679), v5declarations);
   T1 = cl_list(2, VV[6], T2);
   goto L51;
L52:;
   T1 = ECL_NIL;
L51:;
   T2 = ecl_append(v6arg_list,T1);
   T3 = cl_listX(3, ECL_SYM("LAMBDA-LIST",998), T0, T2);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v4method_list;
   cl_env_copy->values[0] = T3;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for PARSE-LAMBDA-LIST                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4parse_lambda_list(cl_narg narg, cl_object v1lambda_list, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2post_keyword;
  va_list args; va_start(args,v1lambda_list);
  {
   int i = 1;
   if (i >= narg) {
    v2post_keyword = ECL_NIL;
   } else {
    i++;
    v2post_keyword = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v3arg;
   v3arg = ecl_car(v1lambda_list);
   {
    cl_object v4;
    v4 = ecl_make_bool(v1lambda_list==ECL_NIL);
    if (Null(v4)) { goto L4; }
    value0 = v4;
    cl_env_copy->nvalues = 1;
    return value0;
L4:;
    if (!((v3arg)==(ECL_SYM("&AUX",7)))) { goto L6; }
    value0 = si_simple_program_error(1, _ecl_static_6);
    return value0;
L6:;
    if (Null(ecl_memql(v3arg,VV[7]))) { goto L8; }
    T0 = ecl_cdr(v1lambda_list);
    value0 = L4parse_lambda_list(2, T0, ECL_T);
    return value0;
L8:;
    if (Null(v2post_keyword)) { goto L10; }
    T0 = ecl_cdr(v1lambda_list);
    value0 = L4parse_lambda_list(2, T0, ECL_T);
    return value0;
L10:;
    if (!(ECL_LISTP(v3arg))) { goto L12; }
    value0 = si_simple_program_error(1, _ecl_static_7);
    return value0;
L12:;
    T0 = ecl_cdr(v1lambda_list);
    value0 = L4parse_lambda_list(1, T0);
    return value0;
   }
  }
 }
}
/*	function definition for VALID-DECLARATION-P                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5valid_declaration_p(cl_object v1decl)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_car(v1decl);
  if (!((T0)==(ECL_SYM("OPTIMIZE",613)))) { goto L2; }
  {
   cl_object v2item;
   cl_object v3;
   v2item = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v1decl))) FEtype_error_list(v1decl);
   v3 = v1decl;
L7:;
   if (!(ecl_endp(v3))) { goto L9; }
   goto L8;
L9:;
   v2item = _ecl_car(v3);
   {
    cl_object v4;
    v4 = _ecl_cdr(v3);
    if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
    v3 = v4;
   }
   if (ECL_ATOM(v2item)) { goto L17; }
   if (!(ECL_CONSP(v2item))) { goto L21; }
   T0 = ecl_car(v2item);
   if ((ecl_memql(T0,VV[8]))!=ECL_NIL) { goto L17; }
   goto L18;
L21:;
   goto L18;
L18:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L17:;
   goto L7;
L8:;
   value0 = ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for LAMBDA-LIST-REQUIRED-ARGUMENTS        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6lambda_list_required_arguments(cl_object v1lambda_list)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = si_process_lambda_list(v1lambda_list, ECL_T);
  value0 = ecl_cdr(T0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G64                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC8__g64(cl_narg narg, cl_object v1gfun, cl_object v2slot_names, ...)
{
 cl_object T0, T1, T2, T3;
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3name;
  cl_object v4l_l_p;
  cl_object v5argument_precedence_order;
  cl_object v6a_o_p;
  cl_object v7documentation;
  cl_object v8declarations;
  cl_object v9method_class;
  ecl_va_list args; ecl_va_start(args,v2slot_names,narg,2);
  {
   cl_object keyvars[12];
   cl_parse_key(args,6,LC8__g64keys,keyvars,NULL,TRUE);
   ecl_va_end(args);
   v3name = keyvars[0];
   env0 = ECL_NIL;
   CLV0 = env0 = CONS(keyvars[1],env0);           /*  LAMBDA-LIST     */
   v4l_l_p = keyvars[7];
   v5argument_precedence_order = keyvars[2];
   v6a_o_p = keyvars[8];
   v7documentation = keyvars[3];
   v8declarations = keyvars[4];
   if (Null(keyvars[11])) {
    v9method_class = cl_find_class(1, ECL_SYM("METHOD",954));
   } else {
    v9method_class = keyvars[5];
   }
  }
  {
   cl_object v10gfun_name;
   if (Null(cl_slot_boundp(v1gfun, ECL_SYM("NAME",1535)))) { goto L3; }
   v10gfun_name = cl_slot_value(v1gfun, ECL_SYM("NAME",1535));
   goto L2;
L3:;
   value0 = v3name;
   if ((value0)!=ECL_NIL) { goto L6; }
   v10gfun_name = VV[11];
   goto L2;
L6:;
   v10gfun_name = value0;
   goto L2;
L2:;
   if (Null(v6a_o_p)) { goto L8; }
   if ((v4l_l_p)!=ECL_NIL) { goto L10; }
   si_simple_program_error(2, _ecl_static_8, v10gfun_name);
L10:;
   {
    cl_object v11;
    v11 = L6lambda_list_required_arguments(ECL_CONS_CAR(CLV0));
    goto L15;
L14:;
    {
     cl_object v12l;
     v12l = ecl_car(v11);
     T0 = cl_count(2, v12l, v5argument_precedence_order);
     if ((ecl_to_fixnum(T0))==(1)) { goto L19; }
     si_simple_program_error(4, _ecl_static_9, v10gfun_name, v12l, v5argument_precedence_order);
L19:;
    }
    v11 = ecl_cdr(v11);
L15:;
    if (Null(v11)) { goto L23; }
    goto L14;
L23:;
   }
L8:;
   T0 = (VV[9]->symbol.gfdef);
   if ((cl_every(2, T0, v8declarations))!=ECL_NIL) { goto L25; }
   si_simple_program_error(3, _ecl_static_10, v10gfun_name, v8declarations);
L25:;
   if (v7documentation==ECL_NIL) { goto L28; }
   if (ECL_STRINGP(v7documentation)) { goto L28; }
   T0 = cl_list(2, v10gfun_name, v7documentation);
   cl_error(9, ECL_SYM("SIMPLE-TYPE-ERROR",773), ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_11, ECL_SYM("FORMAT-ARGUMENTS",1239), T0, ECL_SYM("DATUM",1214), v7documentation, ECL_SYM("EXPECTED-TYPE",1232), VV[12]);
L28:;
   T0 = cl_find_class(1, ECL_SYM("METHOD",954));
   if ((si_subclassp(2, v9method_class, T0))!=ECL_NIL) { goto L31; }
   T0 = cl_list(2, v10gfun_name, v9method_class);
   cl_error(9, ECL_SYM("SIMPLE-TYPE-ERROR",773), ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_12, ECL_SYM("FORMAT-ARGUMENTS",1239), T0, ECL_SYM("DATUM",1214), v9method_class, ECL_SYM("EXPECTED-TYPE",1232), ECL_SYM("METHOD",954));
L31:;
   if (Null(v4l_l_p)) { goto L33; }
   if (Null(cl_slot_boundp(v1gfun, VV[13]))) { goto L33; }
   {cl_object v11;
    v11 = ECL_NIL;
    v11 = ecl_make_cclosure_va((cl_objectfn)LC7__g68,env0,Cblock);
    T0 = v11;
   }
   {
    cl_object v11;
    cl_object v12;
    cl_object v13;
    v11 = ecl_function_dispatch(cl_env_copy,ECL_SYM("GENERIC-FUNCTION-METHODS",1524))(1, v1gfun) /*  GENERIC-FUNCTION-METHODS */;
    v12 = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
    v13 = v11;
    {
     cl_object v14;
     cl_object v15;
     v14 = ecl_list1(ECL_NIL);
     v15 = v14;
L45:;
     if (!(ecl_endp(v13))) { goto L47; }
     goto L46;
L47:;
     v12 = _ecl_car(v13);
     {
      cl_object v16;
      v16 = _ecl_cdr(v13);
      if (ecl_unlikely(!ECL_LISTP(v16))) FEtype_error_list(v16);
      v13 = v16;
     }
     if (ecl_unlikely(ECL_ATOM(v15))) FEtype_error_cons(v15);
     T2 = v15;
     T3 = ecl_function_dispatch(cl_env_copy,ECL_SYM("METHOD-LAMBDA-LIST",1533))(1, v12) /*  METHOD-LAMBDA-LIST */;
     v15 = ecl_list1(T3);
     (ECL_CONS_CDR(T2)=v15,T2);
     goto L45;
L46:;
     T1 = ecl_cdr(v14);
     goto L38;
    }
   }
L38:;
   if ((cl_every(2, T0, T1))!=ECL_NIL) { goto L33; }
   si_simple_program_error(3, _ecl_static_13, v1gfun, ECL_CONS_CAR(CLV0));
L33:;
   if (Null(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)))) { goto L62; }
   T0 = ecl_car(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
   T1 = ecl_cdr(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
   ecl_function_dispatch(cl_env_copy,T0)(2, ecl_symbol_value(ECL_SYM(".COMBINED-METHOD-ARGS.",1473)), T1);
   goto L61;
L62:;
   cl_error(1, _ecl_static_14);
L61:;
   {
    cl_object v11combination;
    v11combination = ecl_function_dispatch(cl_env_copy,ECL_SYM("GENERIC-FUNCTION-METHOD-COMBINATION",1523))(1, v1gfun) /*  GENERIC-FUNCTION-METHOD-COMBINATION */;
    if ((si_of_class_p(2, v11combination, ECL_SYM("METHOD-COMBINATION",956)))!=ECL_NIL) { goto L65; }
    {
     cl_object v12;
     T0 = ecl_car(v11combination);
     T1 = ecl_cdr(v11combination);
     v12 = ecl_function_dispatch(cl_env_copy,ECL_SYM("FIND-METHOD-COMBINATION",1514))(3, v1gfun, T0, T1) /*  FIND-METHOD-COMBINATION */;
     (cl_env_copy->function=ECL_CONS_CAR(VV[28]))->cfun.entry(2, v12, v1gfun) /*  (SETF GENERIC-FUNCTION-METHOD-COMBINATION) */;
    }
   }
L65:;
   if (Null(v4l_l_p)) { goto L69; }
   if ((v6a_o_p)!=ECL_NIL) { goto L69; }
   {
    cl_object v11;
    v11 = L6lambda_list_required_arguments(ECL_CONS_CAR(CLV0));
    (cl_env_copy->function=ECL_CONS_CAR(VV[29]))->cfun.entry(2, v11, v1gfun) /*  (SETF GENERIC-FUNCTION-ARGUMENT-PRECEDENCE-ORDER) */;
   }
L69:;
   ecl_function_dispatch(cl_env_copy,VV[30])(1, v1gfun) /*  SET-GENERIC-FUNCTION-DISPATCH */;
   value0 = v1gfun;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	closure G68                                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC7__g68(cl_narg narg, cl_object v1x, ...)
{
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  LAMBDA-LIST     */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[31])(2, ECL_CONS_CAR(CLV0), v1x) /*  CONGRUENT-LAMBDA-P */;
  return value0;
 }
 }
}
/*	local function G79                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC9__g79(cl_narg narg, cl_object v1gfun, cl_object v2slot_names, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3initargs;
  ecl_va_list args; ecl_va_start(args,v2slot_names,narg,2);
  v3initargs = cl_grab_rest_args(args);
  ecl_va_end(args);
  if (Null(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)))) { goto L2; }
  T0 = ecl_car(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
  T1 = ecl_cdr(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
  ecl_function_dispatch(cl_env_copy,T0)(2, ecl_symbol_value(ECL_SYM(".COMBINED-METHOD-ARGS.",1473)), T1);
  goto L1;
L2:;
  cl_error(1, _ecl_static_14);
L1:;
  if (Null(ecl_function_dispatch(cl_env_copy,ECL_SYM("GENERIC-FUNCTION-METHODS",1524))(1, v1gfun) /*  GENERIC-FUNCTION-METHODS */)) { goto L5; }
  ecl_function_dispatch(cl_env_copy,VV[32])(1, v1gfun) /*  COMPUTE-G-F-SPEC-LIST */;
L5:;
  ecl_function_dispatch(cl_env_copy,VV[33])(2, v1gfun, v3initargs) /*  UPDATE-DEPENDENTS */;
  value0 = v1gfun;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for ASSOCIATE-METHODS-TO-GFUN             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object clos_associate_methods_to_gfun(cl_narg narg, cl_object v1name, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2methods;
  ecl_va_list args; ecl_va_start(args,v1name,narg,1);
  v2methods = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v3gfun;
   v3gfun = cl_fdefinition(v1name);
   {
    cl_object v4;
    v4 = v2methods;
    goto L6;
L5:;
    {
     cl_object v5method;
     v5method = ecl_car(v4);
     {
      cl_object v6;
      T0 = ecl_function_dispatch(cl_env_copy,VV[35])(1, v5method) /*  METHOD-PLIST */;
      v6 = si_put_f(T0, ECL_T, VV[14]);
      (cl_env_copy->function=ECL_CONS_CAR(VV[36]))->cfun.entry(2, v6, v5method) /*  (SETF METHOD-PLIST) */;
     }
    }
    v4 = ecl_cdr(v4);
L6:;
    if (Null(v4)) { goto L15; }
    goto L5;
L15:;
   }
   value0 = v3gfun;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G110                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC10__g110(cl_narg narg, cl_object v1gfun, cl_object v2name, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3args;
  cl_object v4method_class;
  cl_object v5method_class_p;
  cl_object v6generic_function_class;
  cl_object v7delete_methods;
  ecl_va_list args; ecl_va_start(args,v2name,narg,2);
  {
   cl_object keyvars[6];
   cl_parse_key(args,3,LC10__g110keys,keyvars,(cl_object*)&v3args,TRUE);
   ecl_va_end(args);
   if (Null(keyvars[3])) {
    v4method_class = ECL_SYM("STANDARD-METHOD",975);
   } else {
    v4method_class = keyvars[0];
   }
   v5method_class_p = keyvars[3];
   if (Null(keyvars[4])) {
    v6generic_function_class = cl_class_of(v1gfun);
   } else {
    v6generic_function_class = keyvars[1];
   }
   v7delete_methods = keyvars[2];
  }
  v3args = cl_copy_list(v3args);
  {
   cl_object v9;
   cl_object v10;                                 /*  FLAG            */
   value0 = si_rem_f(v3args, ECL_SYM("GENERIC-FUNCTION-CLASS",992));
   v9 = value0;
   v10 = cl_env_copy->values[1];
   v3args = v9;
  }
  {
   cl_object v9;
   cl_object v10;                                 /*  FLAG            */
   value0 = si_rem_f(v3args, ECL_SYM("DECLARE",986));
   v9 = value0;
   v10 = cl_env_copy->values[1];
   v3args = v9;
  }
  {
   cl_object v9;
   cl_object v10;                                 /*  FLAG            */
   value0 = si_rem_f(v3args, VV[16]);
   v9 = value0;
   v10 = cl_env_copy->values[1];
   v3args = v9;
  }
  {
   cl_object v9;
   cl_object v10;                                 /*  FLAG            */
   value0 = si_rem_f(v3args, VV[0]);
   v9 = value0;
   v10 = cl_env_copy->values[1];
   v3args = v9;
  }
  if (!(ECL_SYMBOLP(v6generic_function_class))) { goto L21; }
  v6generic_function_class = cl_find_class(1, v6generic_function_class);
L21:;
  T0 = cl_find_class(1, ECL_SYM("GENERIC-FUNCTION",945));
  if ((si_subclassp(2, v6generic_function_class, T0))!=ECL_NIL) { goto L24; }
  cl_error(2, _ecl_static_15, v6generic_function_class);
L24:;
  if (Null(v5method_class_p)) { goto L26; }
  if (!(ECL_SYMBOLP(v4method_class))) { goto L26; }
  T0 = cl_find_class(1, v4method_class);
  v3args = cl_listX(3, ECL_SYM("METHOD-CLASS",1002), T0, v3args);
L26:;
  if (Null(v7delete_methods)) { goto L30; }
  {
   cl_object v8;
   T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("GENERIC-FUNCTION-METHODS",1524))(1, v1gfun) /*  GENERIC-FUNCTION-METHODS */;
   v8 = cl_copy_list(T0);
   goto L35;
L34:;
   {
    cl_object v9m;
    v9m = ecl_car(v8);
    T0 = ecl_function_dispatch(cl_env_copy,VV[35])(1, v9m) /*  METHOD-PLIST */;
    if (Null(cl_getf(2, T0, VV[14]))) { goto L39; }
    (cl_env_copy->function=(ECL_SYM("REMOVE-METHOD",964)->symbol.gfdef))->cfun.entry(2, v1gfun, v9m) /*  REMOVE-METHOD */;
L39:;
   }
   v8 = ecl_cdr(v8);
L35:;
   if (Null(v8)) { goto L43; }
   goto L34;
L43:;
  }
L30:;
  T0 = cl_class_of(v1gfun);
  if (!((T0)==(v6generic_function_class))) { goto L45; }
  T0 = (ECL_SYM("REINITIALIZE-INSTANCE",963)->symbol.gfdef);
  value0 = cl_apply(5, T0, v1gfun, ECL_SYM("NAME",1273), v2name, v3args);
  return value0;
L45:;
  T0 = (ECL_SYM("CHANGE-CLASS",932)->symbol.gfdef);
  value0 = cl_apply(6, T0, v1gfun, v6generic_function_class, ECL_SYM("NAME",1273), v2name, v3args);
  return value0;
 }
}
/*	local function G145                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC11__g145(cl_narg narg, cl_object v1gfun, cl_object v2name, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3args;
  cl_object v4method_class;
  cl_object v5method_class_p;
  cl_object v6generic_function_class;
  cl_object v7delete_methods;
  ecl_va_list args; ecl_va_start(args,v2name,narg,2);
  {
   cl_object keyvars[6];
   cl_parse_key(args,3,LC11__g145keys,keyvars,(cl_object*)&v3args,TRUE);
   ecl_va_end(args);
   if (Null(keyvars[3])) {
    v4method_class = ECL_SYM("STANDARD-METHOD",975);
   } else {
    v4method_class = keyvars[0];
   }
   v5method_class_p = keyvars[3];
   if (Null(keyvars[4])) {
    v6generic_function_class = ECL_SYM("STANDARD-GENERIC-FUNCTION",974);
   } else {
    v6generic_function_class = keyvars[1];
   }
   v7delete_methods = keyvars[2];
  }
  v3args = cl_copy_list(v3args);
  {
   cl_object v9;
   cl_object v10;                                 /*  FLAG            */
   value0 = si_rem_f(v3args, ECL_SYM("GENERIC-FUNCTION-CLASS",992));
   v9 = value0;
   v10 = cl_env_copy->values[1];
   v3args = v9;
  }
  {
   cl_object v9;
   cl_object v10;                                 /*  FLAG            */
   value0 = si_rem_f(v3args, ECL_SYM("DECLARE",986));
   v9 = value0;
   v10 = cl_env_copy->values[1];
   v3args = v9;
  }
  {
   cl_object v9;
   cl_object v10;                                 /*  FLAG            */
   value0 = si_rem_f(v3args, VV[16]);
   v9 = value0;
   v10 = cl_env_copy->values[1];
   v3args = v9;
  }
  {
   cl_object v9;
   cl_object v10;                                 /*  FLAG            */
   value0 = si_rem_f(v3args, VV[0]);
   v9 = value0;
   v10 = cl_env_copy->values[1];
   v3args = v9;
  }
  if (Null(v5method_class_p)) { goto L21; }
  if (!(ECL_SYMBOLP(v6generic_function_class))) { goto L21; }
  T0 = cl_find_class(1, v4method_class);
  v3args = cl_listX(3, ECL_SYM("METHOD-CLASS",1002), T0, v3args);
L21:;
  T0 = (ECL_SYM("MAKE-INSTANCE",949)->symbol.gfdef);
  value0 = cl_apply(5, T0, v6generic_function_class, ECL_SYM("NAME",1273), v2name, v3args);
  return value0;
 }
}
/*	function definition for ENSURE-GENERIC-FUNCTION               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L12ensure_generic_function(cl_narg narg, cl_object v1name, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2args;
  ecl_va_list args; ecl_va_start(args,v1name,narg,1);
  cl_parse_key(args,0,NULL,NULL,(cl_object*)&v2args,TRUE);
  ecl_va_end(args);
  {
   cl_object v3gfun;
   v3gfun = si_traced_old_definition(v1name);
   if ((ecl_function_dispatch(cl_env_copy,VV[41])(1, v1name) /*  LEGAL-GENERIC-FUNCTION-NAME-P */)!=ECL_NIL) { goto L2; }
   value0 = si_simple_program_error(2, _ecl_static_16, v1name);
   return value0;
L2:;
   if ((cl_fboundp(v1name))!=ECL_NIL) { goto L4; }
   T0 = (ECL_SYM("ENSURE-GENERIC-FUNCTION-USING-CLASS",1508)->symbol.gfdef);
   T1 = cl_apply(4, T0, v3gfun, v1name, v2args);
   value0 = si_fset(4, v1name, T1, ECL_NIL, ECL_NIL);
   return value0;
L4:;
   value0 = v3gfun;
   if ((value0)!=ECL_NIL) { goto L11; }
   v3gfun = cl_fdefinition(v1name);
   T0 = v3gfun;
   goto L9;
L11:;
   T0 = value0;
   goto L9;
L9:;
   if (!(ECL_INSTANCEP(T0))) { goto L7; }
   T0 = (ECL_SYM("ENSURE-GENERIC-FUNCTION-USING-CLASS",1508)->symbol.gfdef);
   value0 = cl_apply(4, T0, v3gfun, v1name, v2args);
   return value0;
L7:;
   if (Null(cl_special_operator_p(v1name))) { goto L15; }
   value0 = si_simple_program_error(2, _ecl_static_17, v1name);
   return value0;
L15:;
   if (Null(cl_macro_function(1, v1name))) { goto L17; }
   value0 = si_simple_program_error(2, _ecl_static_18, v1name);
   return value0;
L17:;
   if ((ecl_symbol_value(VV[17]))!=ECL_NIL) { goto L19; }
   T0 = (ECL_SYM("ENSURE-GENERIC-FUNCTION-USING-CLASS",1508)->symbol.gfdef);
   T1 = cl_apply(4, T0, ECL_NIL, v1name, v2args);
   si_fset(4, v1name, T1, ECL_NIL, ECL_NIL);
   value0 = cl_fdefinition(v1name);
   return value0;
L19:;
   value0 = si_simple_program_error(2, _ecl_static_19, v1name);
   return value0;
  }
 }
}

#include "clos/generic.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclXvY0gHUUtTin9_oGEcYE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CLOS;GENERIC.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclXvY0gHUUtTin9_oGEcYE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defmacro(VV[19]);                        /*  DEFGENERIC      */
 (void)0; /* No entry created for PARSE-DEFGENERIC */
 (void)0; /* No entry created for PARSE-GENERIC-OPTIONS */
 (void)0; /* No entry created for PARSE-LAMBDA-LIST */
 ecl_cmp_defun(VV[20]);                           /*  VALID-DECLARATION-P */
 ecl_cmp_defun(VV[21]);                           /*  LAMBDA-LIST-REQUIRED-ARGUMENTS */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC8__g64,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("SHARED-INITIALIZE",965), ECL_NIL, VVtemp[0], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC9__g79,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("SHARED-INITIALIZE",965), ECL_NIL, VVtemp[2], VVtemp[3], T0, ECL_T);
 }
 ecl_cmp_defun(VV[34]);                           /*  ASSOCIATE-METHODS-TO-GFUN */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC10__g110,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("ENSURE-GENERIC-FUNCTION-USING-CLASS",1508), ECL_NIL, VVtemp[0], VVtemp[4], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC11__g145,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("ENSURE-GENERIC-FUNCTION-USING-CLASS",1508), ECL_NIL, VVtemp[5], VVtemp[6], T0, ECL_T);
 }
 ecl_cmp_defun(VV[40]);                           /*  ENSURE-GENERIC-FUNCTION */
}
