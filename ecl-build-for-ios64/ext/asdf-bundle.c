/*	Compiler: ECL 12.12.1                                         */
/*	Source: EXT:ASDF;ASDF-BUNDLE.LISP                             */
#include <ecl/ecl-cmp.h>
#include "ext/asdf-bundle.eclh"
/*	function definition for FASL-TYPE                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1fasl_type()
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = (cl_env_copy->function=(ECL_SYM("COMPILE-FILE-PATHNAME",235)->symbol.gfdef))->cfun.entry(1, _ecl_static_1) /*  COMPILE-FILE-PATHNAME */;
  T1 = cl_pathname_type(1, T0);
  value0 = cl_identity(T1);
  return value0;
 }
}
/*	function definition for BUNDLE-OP-MONOLITHIC-P                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2bundle_op_monolithic_p(cl_object v1op)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = si_of_class_p(2, v1op, VV[5]);
  return value0;
 }
}
/*	local function G38                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC3__g38(cl_narg narg, cl_object v1instance, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2name_suffix;
  cl_object v3name_suffix_p;
  ecl_va_list args; ecl_va_start(args,v1instance,narg,1);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,LC3__g38keys,keyvars,NULL,TRUE);
   ecl_va_end(args);
   v2name_suffix = keyvars[0];
   v3name_suffix_p = keyvars[1];
  }
  if ((v3name_suffix_p)!=ECL_NIL) { goto L1; }
  {
   cl_object v4;
   if (Null(L2bundle_op_monolithic_p(v1instance))) { goto L4; }
   v4 = _ecl_static_2;
   goto L3;
L4:;
   v4 = _ecl_static_3;
L3:;
   (cl_env_copy->function=ECL_CONS_CAR(VV[86]))->cfun.entry(3, v4, v1instance, VV[11]) /*  (SETF SLOT-VALUE) */;
  }
L1:;
  if (Null(si_of_class_p(2, v1instance, VV[5]))) { goto L6; }
  {
   cl_object v4;
   cl_object v5;
   cl_object v6lisp_files;
   cl_object v7;
   cl_object v8prologue_code;
   cl_object v9;
   cl_object v10epilogue_code;
   v4 = cl_slot_value(v1instance, VV[12]);
   v5 = si_search_keyword(2, v4, VV[13]);
   if (!((v5)==(ECL_SYM("MISSING-KEYWORD",1929)))) { goto L11; }
   v6lisp_files = ECL_NIL;
   goto L10;
L11:;
   v6lisp_files = v5;
L10:;
   v7 = si_search_keyword(2, v4, VV[14]);
   if (!((v7)==(ECL_SYM("MISSING-KEYWORD",1929)))) { goto L15; }
   v8prologue_code = ECL_NIL;
   goto L14;
L15:;
   v8prologue_code = v7;
L14:;
   v9 = si_search_keyword(2, v4, VV[15]);
   if (!((v9)==(ECL_SYM("MISSING-KEYWORD",1929)))) { goto L19; }
   v10epilogue_code = ECL_NIL;
   goto L18;
L19:;
   v10epilogue_code = v9;
L18:;
   si_check_keyword(3, v4, VV[16], ECL_T);
   {
    cl_object v11;
    v11 = ecl_function_dispatch(cl_env_copy,VV[87])(2, VV[17], v4) /*  REMOVE-KEYS */;
    (cl_env_copy->function=ECL_CONS_CAR(VV[86]))->cfun.entry(3, v11, v1instance, VV[12]) /*  (SETF SLOT-VALUE) */;
   }
   (cl_env_copy->function=ecl_fdefinition(VV[88]))->cfun.entry(2, v8prologue_code, v1instance) /*  (SETF MONOLITHIC-OP-PROLOGUE-CODE) */;
   (cl_env_copy->function=ecl_fdefinition(VV[89]))->cfun.entry(2, v10epilogue_code, v1instance) /*  (SETF MONOLITHIC-OP-EPILOGUE-CODE) */;
   (cl_env_copy->function=ecl_fdefinition(VV[90]))->cfun.entry(2, v6lisp_files, v1instance) /*  (SETF BUNDLE-OP-LISP-FILES) */;
  }
L6:;
  {
   cl_object v4;
   T0 = cl_slot_value(v1instance, VV[12]);
   v4 = ecl_function_dispatch(cl_env_copy,VV[87])(2, VV[18], T0) /*  REMOVE-KEYS */;
   value0 = (cl_env_copy->function=ecl_fdefinition(VV[91]))->cfun.entry(2, v4, v1instance) /*  (SETF BUNDLE-OP-BUILD-ARGS) */;
   return value0;
  }
 }
}
/*	local function G62                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC4__g62(cl_object v1op)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2args;
   if (Null(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)))) { goto L2; }
   T0 = ecl_car(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
   T1 = ecl_cdr(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
   v2args = ecl_function_dispatch(cl_env_copy,T0)(2, ecl_symbol_value(ECL_SYM(".COMBINED-METHOD-ARGS.",1473)), T1);
   goto L1;
L2:;
   v2args = cl_error(1, _ecl_static_4);
L1:;
   {
    cl_object v4;
    cl_object v5;                                 /*  FLAG            */
    value0 = si_rem_f(v2args, VV[20]);
    v4 = value0;
    v5 = cl_env_copy->values[1];
    v2args = v4;
   }
   value0 = v2args;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G65                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC5__g65(cl_object v1operation, cl_object v2c)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_symbol_value(VV[21]))) { goto L1; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (Null(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)))) { goto L3; }
  T0 = ecl_car(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
  T1 = ecl_cdr(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
  value0 = ecl_function_dispatch(cl_env_copy,T0)(2, ecl_symbol_value(ECL_SYM(".COMBINED-METHOD-ARGS.",1473)), T1);
  return value0;
L3:;
  value0 = cl_error(1, _ecl_static_4);
  return value0;
 }
}
/*	function definition for GATHER-COMPONENTS                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6gather_components(cl_narg narg, cl_object v1op_type, cl_object v2system, ...)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3filter_system;
  cl_object v4filter_type;
  cl_object v5include_self;
  ecl_va_list args; ecl_va_start(args,v2system,narg,2);
  {
   cl_object keyvars[6];
   cl_parse_key(args,3,L6gather_componentskeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3filter_system = keyvars[0];
   v4filter_type = keyvars[1];
   v5include_self = keyvars[2];
  }
  {
   cl_object v6operation;
   cl_object v7tree;
   v6operation = (cl_env_copy->function=(ECL_SYM("MAKE-INSTANCE",949)->symbol.gfdef))->cfun.entry(1, v1op_type) /*  MAKE-INSTANCE */;
   ecl_bds_bind(cl_env_copy,VV[21],ECL_T);        /*  *FORCE-LOAD-P*  */
   T0 = (cl_env_copy->function=(ECL_SYM("MAKE-INSTANCE",949)->symbol.gfdef))->cfun.entry(1, VV[23]) /*  MAKE-INSTANCE */;
   v7tree = ecl_function_dispatch(cl_env_copy,VV[96])(2, T0, v2system) /*  TRAVERSE */;
   {
    cl_object v8op;
    cl_object v9component;
    cl_object v10;
    v8op = ECL_NIL;
    v9component = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v7tree))) FEtype_error_list(v7tree);
    v10 = v7tree;
    {
     cl_object v11;
     cl_object v12;
     v11 = ecl_list1(ECL_NIL);
     v12 = v11;
L10:;
     if (!(ecl_endp(v10))) { goto L12; }
     goto L11;
L12:;
     {
      cl_object v13;
      v13 = _ecl_car(v10);
      v8op = ecl_car(v13);
      v13 = ecl_cdr(v13);
      v9component = v13;
     }
     {
      cl_object v13;
      v13 = _ecl_cdr(v10);
      if (ecl_unlikely(!ECL_LISTP(v13))) FEtype_error_list(v13);
      v10 = v13;
     }
     if (Null(si_of_class_p(2, v8op, VV[23]))) { goto L25; }
     if (Null(cl_typep(2, v9component, v4filter_type))) { goto L25; }
     if (Null(v3filter_system)) { goto L29; }
     T1 = ecl_function_dispatch(cl_env_copy,VV[97])(1, v9component) /*  COMPONENT-SYSTEM */;
     if (!((T1)==(v3filter_system))) { goto L25; }
     goto L26;
L29:;
L26:;
     if (ecl_unlikely(ECL_ATOM(v12))) FEtype_error_cons(v12);
     T1 = v12;
     if (!((v9component)==(v2system))) { goto L34; }
     v5include_self = ECL_NIL;
L34:;
     T2 = CONS(v6operation,v9component);
     v12 = ecl_list1(T2);
     (ECL_CONS_CDR(T1)=v12,T1);
L25:;
     goto L10;
L11:;
     T0 = ecl_cdr(v11);
     goto L3;
    }
   }
L3:;
   if (Null(v5include_self)) { goto L41; }
   T2 = CONS(v6operation,v2system);
   T1 = ecl_list1(T2);
   goto L39;
L41:;
   T1 = ECL_NIL;
   goto L39;
L39:;
   value0 = ecl_append(T0,T1);
   cl_env_copy->nvalues = 1;
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
 }
}
/*	local function G73                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC7__g73(cl_object v1o, cl_object v2c)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L6gather_components(6, VV[3], v2c, VV[27], VV[28], VV[29], ECL_T);
  return value0;
 }
}
/*	local function G74                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC8__g74(cl_object v1o, cl_object v2c)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((L2bundle_op_monolithic_p(v1o))!=ECL_NIL) { goto L3; }
  T0 = v2c;
  goto L1;
L3:;
  T0 = ECL_NIL;
  goto L1;
L1:;
  value0 = L6gather_components(6, VV[30], v2c, VV[31], T0, VV[27], VV[32]);
  return value0;
 }
}
/*	local function G75                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC9__g75(cl_object v1o, cl_object v2c)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L6gather_components(6, VV[30], v2c, VV[31], ECL_NIL, VV[27], VV[32]);
  return value0;
 }
}
/*	local function G76                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC10__g76(cl_object v1o, cl_object v2c)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = (cl_env_copy->function=(ECL_SYM("MAKE-INSTANCE",949)->symbol.gfdef))->cfun.entry(1, VV[3]) /*  MAKE-INSTANCE */;
  T1 = CONS(T0,v2c);
  value0 = ecl_list1(T1);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G77                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC11__g77(cl_object v1o, cl_object v2c)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = (cl_env_copy->function=(ECL_SYM("MAKE-INSTANCE",949)->symbol.gfdef))->cfun.entry(1, VV[3]) /*  MAKE-INSTANCE */;
  T1 = CONS(T0,v2c);
  value0 = ecl_list1(T1);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G84                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC12__g84(cl_object v1o, cl_object v2c)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4op;
   cl_object v5dep;
   cl_object v6;
   v3 = ecl_function_dispatch(cl_env_copy,VV[25])(2, v1o, v2c) /*  BUNDLE-SUB-OPERATIONS */;
   v4op = ECL_NIL;
   v5dep = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v3))) FEtype_error_list(v3);
   v6 = v3;
   {
    cl_object v7;
    cl_object v8;
    v7 = ecl_list1(ECL_NIL);
    v8 = v7;
L8:;
    if (!(ecl_endp(v6))) { goto L10; }
    goto L9;
L10:;
    {
     cl_object v9;
     v9 = _ecl_car(v6);
     v4op = ecl_car(v9);
     v9 = ecl_cdr(v9);
     v5dep = v9;
    }
    {
     cl_object v9;
     v9 = _ecl_cdr(v6);
     if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
     v6 = v9;
    }
    if (Null(si_of_class_p(2, v5dep, VV[28]))) { goto L23; }
    if (ecl_unlikely(ECL_ATOM(v8))) FEtype_error_cons(v8);
    T0 = v8;
    T1 = cl_class_of(v4op);
    T2 = (cl_env_copy->function=(ECL_SYM("CLASS-NAME",934)->symbol.gfdef))->cfun.entry(1, T1) /*  CLASS-NAME */;
    T3 = ecl_function_dispatch(cl_env_copy,VV[98])(1, v5dep) /*  COMPONENT-NAME */;
    T4 = cl_list(2, T2, T3);
    v8 = ecl_list1(T4);
    (ECL_CONS_CDR(T0)=v8,T0);
L23:;
    goto L8;
L9:;
    value0 = ecl_cdr(v7);
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	local function G91                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC13__g91(cl_object v1o, cl_object v2c)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[98])(1, v2c) /*  COMPONENT-NAME */;
  T1 = cl_list(2, VV[30], T0);
  value0 = ecl_list1(T1);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G92                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC14__g92(cl_object v1o, cl_object v2c)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G103                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC15__g103(cl_object v1o, cl_object v2c)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4sub_op;
   cl_object v5sub_c;
   cl_object v6;
   v3 = ecl_function_dispatch(cl_env_copy,VV[25])(2, v1o, v2c) /*  BUNDLE-SUB-OPERATIONS */;
   v4sub_op = ECL_NIL;
   v5sub_c = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v3))) FEtype_error_list(v3);
   v6 = v3;
   {
    cl_object v7;
    cl_object v8;
    v7 = ecl_list1(ECL_NIL);
    v8 = v7;
L8:;
    if (!(ecl_endp(v6))) { goto L10; }
    goto L9;
L10:;
    {
     cl_object v9;
     v9 = _ecl_car(v6);
     v4sub_op = ecl_car(v9);
     v9 = ecl_cdr(v9);
     v5sub_c = v9;
    }
    {
     cl_object v9;
     v9 = _ecl_cdr(v6);
     if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
     v6 = v9;
    }
    {
     cl_object v9;
     v9 = ecl_function_dispatch(cl_env_copy,VV[35])(2, v4sub_op, v5sub_c) /*  OUTPUT-FILES */;
     if (ecl_unlikely(ECL_ATOM(v8))) FEtype_error_cons(v8);
     T0 = v8;
     (ECL_CONS_CDR(T0)=v9,T0);
     if (Null(v9)) { goto L23; }
    }
    T0 = ecl_cdr(v8);
    v8 = ecl_last(T0,1);
L23:;
    goto L8;
L9:;
    value0 = ecl_cdr(v7);
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	local function G112                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC16__g112(cl_object v1o, cl_object v2c)
{
 cl_object T0, T1, T2, T3, T4, T5, T6;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[98])(1, v2c) /*  COMPONENT-NAME */;
  T1 = cl_slot_value(v1o, VV[11]);
  T2 = ecl_function_dispatch(cl_env_copy,VV[99])(2, T0, T1) /*  STRCAT */;
  T3 = ecl_function_dispatch(cl_env_copy,VV[100])(1, v2c) /*  SYSTEM-SOURCE-DIRECTORY */;
  T4 = cl_make_pathname(6, ECL_SYM("NAME",1273), T2, ECL_SYM("TYPE",1318), _ecl_static_5, ECL_SYM("DEFAULTS",1216), T3);
  T5 = ecl_function_dispatch(cl_env_copy,VV[101])(1, v1o) /*  BUNDLE-OP-TYPE */;
  T6 = (cl_env_copy->function=(ECL_SYM("COMPILE-FILE-PATHNAME",235)->symbol.gfdef))->cfun.entry(3, T4, ECL_SYM("TYPE",1318), T5) /*  COMPILE-FILE-PATHNAME */;
  value0 = ecl_list1(T6);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G113                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC17__g113(cl_object v1o, cl_object v2c)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G114                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC18__g114(cl_object v1o, cl_object v2c)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for SELECT-OPERATION                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L19select_operation(cl_object v1monolithic, cl_object v2type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ecl_eql(v2type,VV[37]))) { goto L1; }
  if (Null(v1monolithic)) { goto L4; }
  value0 = VV[39];
  cl_env_copy->nvalues = 1;
  return value0;
L4:;
  value0 = VV[40];
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (!(ecl_eql(v2type,VV[41]))) { goto L11; }
  goto L8;
  goto L9;
L11:;
  goto L9;
L9:;
  if (!(ecl_eql(v2type,VV[43]))) { goto L6; }
  goto L7;
L8:;
L7:;
  if (Null(v1monolithic)) { goto L14; }
  value0 = VV[9];
  cl_env_copy->nvalues = 1;
  return value0;
L14:;
  value0 = VV[4];
  cl_env_copy->nvalues = 1;
  return value0;
L6:;
  if (!(ecl_eql(v2type,VV[45]))) { goto L21; }
  goto L18;
  goto L19;
L21:;
  goto L19;
L19:;
  if (!(ecl_eql(v2type,VV[47]))) { goto L16; }
  goto L17;
L18:;
L17:;
  if (Null(v1monolithic)) { goto L24; }
  value0 = VV[8];
  cl_env_copy->nvalues = 1;
  return value0;
L24:;
  value0 = VV[3];
  cl_env_copy->nvalues = 1;
  return value0;
L16:;
  if (!(ecl_eql(v2type,VV[49]))) { goto L26; }
  if (Null(v1monolithic)) { goto L29; }
  value0 = VV[7];
  cl_env_copy->nvalues = 1;
  return value0;
L29:;
  value0 = VV[2];
  cl_env_copy->nvalues = 1;
  return value0;
L26:;
  if (!(ecl_eql(v2type,VV[51]))) { goto L31; }
  value0 = VV[10];
  cl_env_copy->nvalues = 1;
  return value0;
L31:;
  value0 = si_ecase_error(v2type, VV[53]);
  return value0;
 }
}
/*	function definition for MAKE-BUILD                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L20make_build(cl_narg narg, cl_object v1system, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2args;
  cl_object v3monolithic;
  cl_object v4type;
  cl_object v5move_here;
  cl_object v6move_here_p;
  ecl_va_list args; ecl_va_start(args,v1system,narg,1);
  {
   cl_object keyvars[6];
   cl_parse_key(args,3,L20make_buildkeys,keyvars,(cl_object*)&v2args,TRUE);
   ecl_va_end(args);
   v3monolithic = keyvars[0];
   if (Null(keyvars[4])) {
    v4type = VV[49];
   } else {
    v4type = keyvars[1];
   }
   v5move_here = keyvars[2];
   v6move_here_p = keyvars[5];
  }
  {
   cl_object v7operation_name;
   cl_object v8move_here_path;
   cl_object v9operation;
   cl_object v10system;
   cl_object v11files;
   v7operation_name = L19select_operation(v3monolithic, v4type);
   if (Null(v5move_here)) { goto L4; }
   if ((cl_pathnamep(v5move_here))!=ECL_NIL) { goto L7; }
   if (!(ECL_STRINGP(v5move_here))) { goto L4; }
   goto L5;
L7:;
L5:;
   v8move_here_path = cl_pathname(v5move_here);
   goto L3;
L4:;
   v8move_here_path = cl_merge_pathnames(1, _ecl_static_6);
L3:;
   T0 = ecl_fdefinition(VV[107]);
   T1 = ecl_function_dispatch(cl_env_copy,VV[87])(2, VV[55], v2args) /*  REMOVE-KEYS */;
   v9operation = cl_apply(4, T0, v7operation_name, v1system, T1);
   v10system = ecl_function_dispatch(cl_env_copy,VV[108])(1, v1system) /*  FIND-SYSTEM */;
   if (Null(v10system)) { goto L14; }
   v11files = ecl_function_dispatch(cl_env_copy,VV[35])(2, v9operation, v10system) /*  OUTPUT-FILES */;
   goto L12;
L14:;
   v11files = ECL_NIL;
   goto L12;
L12:;
   if ((v5move_here)!=ECL_NIL) { goto L18; }
   if (!(v6move_here_p==ECL_NIL)) { goto L16; }
   if (!(ecl_eql(v7operation_name,VV[51]))) { goto L24; }
   goto L21;
   goto L22;
L24:;
   goto L22;
L22:;
   if (!(ecl_eql(v7operation_name,VV[37]))) { goto L16; }
   goto L17;
L21:;
   goto L17;
L18:;
L17:;
   {
    cl_object v12dest_path;
    T0 = cl_ensure_directories_exist(1, v8move_here_path);
    v12dest_path = cl_truename(T0);
    {
     cl_object v13f;
     cl_object v14;
     v13f = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v11files))) FEtype_error_list(v11files);
     v14 = v11files;
     {
      cl_object v15new_f;
      v15new_f = ECL_NIL;
      {
       cl_object v16;
       cl_object v17;
       v16 = ecl_list1(ECL_NIL);
       v17 = v16;
L34:;
       if (!(ecl_endp(v14))) { goto L36; }
       goto L35;
L36:;
       v13f = _ecl_car(v14);
       {
        cl_object v18;
        v18 = _ecl_cdr(v14);
        if (ecl_unlikely(!ECL_LISTP(v18))) FEtype_error_list(v18);
        v14 = v18;
       }
       T0 = cl_pathname_name(1, v13f);
       T1 = cl_pathname_type(1, v13f);
       v15new_f = cl_make_pathname(6, ECL_SYM("NAME",1273), T0, ECL_SYM("TYPE",1318), T1, ECL_SYM("DEFAULTS",1216), v12dest_path);
       if (Null(cl_probe_file(v15new_f))) { goto L47; }
       cl_delete_file(v15new_f);
L47:;
       cl_rename_file(2, v13f, v15new_f);
       if (ecl_unlikely(ECL_ATOM(v17))) FEtype_error_cons(v17);
       T0 = v17;
       v17 = ecl_list1(v15new_f);
       (ECL_CONS_CDR(T0)=v17,T0);
       goto L34;
L35:;
       value0 = ecl_cdr(v16);
       cl_env_copy->nvalues = 1;
       return value0;
      }
     }
    }
   }
L16:;
   value0 = v11files;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G129                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC21__g129(cl_object v1o, cl_object v2c)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((L26trivial_system_p(v2c))!=ECL_NIL) { goto L1; }
  T0 = (cl_env_copy->function=(ECL_SYM("MAKE-INSTANCE",949)->symbol.gfdef))->cfun.entry(1, VV[23]) /*  MAKE-INSTANCE */;
  T1 = ecl_function_dispatch(cl_env_copy,VV[33])(2, T0, v2c) /*  COMPONENT-DEPENDS-ON */;
  T2 = cl_subst(3, VV[2], VV[30], T1);
  value0 = cl_subst(3, VV[58], VV[23], T2);
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G130                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC22__g130(cl_object v1o, cl_object v2c)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((L26trivial_system_p(v2c))!=ECL_NIL) { goto L1; }
  T0 = (cl_env_copy->function=(ECL_SYM("MAKE-INSTANCE",949)->symbol.gfdef))->cfun.entry(1, VV[2]) /*  MAKE-INSTANCE */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[35])(2, T0, v2c) /*  OUTPUT-FILES */;
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G131                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC23__g131(cl_object v1o, cl_object v2c)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G146                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC24__g146(cl_object v1o, cl_object v2c)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3l;
   v3l = ecl_function_dispatch(cl_env_copy,VV[34])(2, v1o, v2c) /*  INPUT-FILES */;
   if (Null(v3l)) { goto L3; }
   T0 = ecl_car(v3l);
   if (Null(cl_load(1, T0))) { goto L3; }
   {
    cl_object v4;
    cl_object v5i;
    cl_object v6;
    v4 = ecl_function_dispatch(cl_env_copy,VV[109])(1, v2c) /*  MODULE-COMPONENTS */;
    v5i = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
    v6 = v4;
L10:;
    if (!(ecl_endp(v6))) { goto L12; }
    goto L11;
L12:;
    v5i = _ecl_car(v6);
    {
     cl_object v7;
     v7 = _ecl_cdr(v6);
     if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
     v6 = v7;
    }
    T0 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v5i) /*  COMPONENT-OPERATION-TIMES */;
    T1 = cl_get_universal_time();
    si_hash_set(VV[23], T0, T1);
    goto L10;
L11:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L3:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for TRIVIAL-SYSTEM-P                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L26trivial_system_p(cl_object v1c)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {cl_object v2;
   v2 = ECL_NIL;
   v2 = ecl_make_cfun((cl_objectfn_fixed)LC25__g153,ECL_NIL,Cblock,1);
   T0 = v2;
  }
  T1 = ecl_function_dispatch(cl_env_copy,VV[109])(1, v1c) /*  MODULE-COMPONENTS */;
  value0 = cl_every(2, T0, T1);
  return value0;
 }
}
/*	local function G153                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC25__g153(cl_object v1c)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = si_of_class_p(2, v1c, VV[59]);
  return value0;
 }
}
/*	local function G154                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC27__g154(cl_object v1component)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_slot_value(v1component, VV[62]);
  if ((value0)!=ECL_NIL) { goto L3; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[98])(1, v1component) /*  COMPONENT-NAME */;
  goto L1;
L3:;
  T0 = value0;
  goto L1;
L1:;
  T1 = L1fasl_type();
  T2 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1component) /*  COMPONENT-PARENT-PATHNAME */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[113])(5, T0, ECL_SYM("TYPE",1318), T1, ECL_SYM("DEFAULTS",1216), T2) /*  COERCE-PATHNAME */;
  return value0;
 }
}
/*	local function G155                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC28__g155(cl_object v1o, cl_object v2c)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G156                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC29__g156(cl_object v1o, cl_object v2c)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G157                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC30__g157(cl_object v1o, cl_object v2c)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[114])(1, v2c) /*  COMPONENT-PATHNAME */;
  value0 = cl_load(1, T0);
  return value0;
 }
}
/*	local function G158                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC31__g158(cl_object v1o, cl_object v2c)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[114])(1, v2c) /*  COMPONENT-PATHNAME */;
  value0 = cl_load(1, T0);
  return value0;
 }
}
/*	local function G159                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC32__g159(cl_object v1o, cl_object v2c)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G160                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC33__g160(cl_object v1o, cl_object v2c)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[115])(1, v2c) /*  PREBUILT-SYSTEM-STATIC-LIBRARY */;
  T1 = ecl_list1(T0);
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = ECL_T;
  cl_env_copy->values[0] = T1;
  return cl_env_copy->values[0];
 }
}
/*	local function G161                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC34__g161(cl_object v1o, cl_object v2c)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[35])(2, v1o, v2c) /*  OUTPUT-FILES */;
  value0 = ecl_car(T0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G162                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC35__g162(cl_object v1o, cl_object v2c)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G163                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC36__g163(cl_object v1o, cl_object v2c)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G164                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC37__g164(cl_object v1o, cl_object v2c)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_error(2, _ecl_static_7, v2c);
  return value0;
 }
}
/*	local function G165                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC38__g165(cl_object v1o, cl_object v2c)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for BINARY-OP-DEPENDENCIES                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L39binary_op_dependencies(cl_object v1o, cl_object v2s)
{
 cl_object T0, T1, T2, T3, T4, T5;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4;                                  /*  LIB-OP          */
   cl_object v5;                                  /*  FASL-OP         */
   if (Null(L2bundle_op_monolithic_p(v1o))) { goto L2; }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = VV[7];
   cl_env_copy->values[0] = VV[8];
   value0 = cl_env_copy->values[0];
   goto L1;
L2:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = VV[2];
   cl_env_copy->values[0] = VV[3];
   value0 = cl_env_copy->values[0];
L1:;
   v4 = value0;
   v5 = cl_env_copy->values[1];
   T0 = ecl_function_dispatch(cl_env_copy,VV[19])(1, v1o) /*  BUNDLE-OP-BUILD-ARGS */;
   T1 = (cl_env_copy->function=(ECL_SYM("MAKE-INSTANCE",949)->symbol.gfdef))->cfun.entry(3, v4, VV[64], T0) /*  MAKE-INSTANCE */;
   T2 = cl_list(2, T1, v2s);
   T3 = ecl_function_dispatch(cl_env_copy,VV[19])(1, v1o) /*  BUNDLE-OP-BUILD-ARGS */;
   T4 = (cl_env_copy->function=(ECL_SYM("MAKE-INSTANCE",949)->symbol.gfdef))->cfun.entry(3, v5, VV[64], T3) /*  MAKE-INSTANCE */;
   T5 = cl_list(2, T4, v2s);
   value0 = cl_list(2, T2, T5);
   return value0;
  }
 }
}
/*	local function G176                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC40__g176(cl_object v1o, cl_object v2s)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4dep;
   cl_object v5;
   v3 = L39binary_op_dependencies(v1o, v2s);
   v4dep = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v3))) FEtype_error_list(v3);
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
    v4dep = _ecl_car(v5);
    {
     cl_object v8;
     v8 = _ecl_cdr(v5);
     if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
     v5 = v8;
    }
    {
     cl_object v8;
     T0 = ecl_fdefinition(VV[33]);
     T1 = cl_apply(2, T0, v4dep);
     v8 = cl_copy_list(T1);
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
/*	local function G194                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC41__g194(cl_object v1o, cl_object v2s)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4dep;
   cl_object v5;
   v3 = L39binary_op_dependencies(v1o, v2s);
   v4dep = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v3))) FEtype_error_list(v3);
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
    v4dep = _ecl_car(v5);
    {
     cl_object v8;
     v8 = _ecl_cdr(v5);
     if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
     v5 = v8;
    }
    {
     cl_object v8;
     T0 = ecl_fdefinition(VV[34]);
     T1 = cl_apply(2, T0, v4dep);
     v8 = cl_copy_list(T1);
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
/*	local function G212                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC42__g212(cl_object v1o, cl_object v2s)
{
 cl_object T0, T1, T2, T3, T4, T5, T6;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[98])(1, v2s) /*  COMPONENT-NAME */;
  T1 = cl_make_pathname(4, ECL_SYM("NAME",1273), T0, ECL_SYM("TYPE",1318), _ecl_static_8);
  T2 = ecl_function_dispatch(cl_env_copy,VV[61])(1, v2s) /*  COMPONENT-RELATIVE-PATHNAME */;
  T3 = ecl_function_dispatch(cl_env_copy,VV[117])(2, T1, T2) /*  MERGE-PATHNAMES* */;
  {
   cl_object v3;
   cl_object v4dep;
   cl_object v5;
   v3 = L39binary_op_dependencies(v1o, v2s);
   v4dep = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v3))) FEtype_error_list(v3);
   v5 = v3;
   {
    cl_object v6;
    cl_object v7;
    v6 = ecl_list1(ECL_NIL);
    v7 = v6;
L8:;
    if (!(ecl_endp(v5))) { goto L10; }
    goto L9;
L10:;
    v4dep = _ecl_car(v5);
    {
     cl_object v8;
     v8 = _ecl_cdr(v5);
     if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
     v5 = v8;
    }
    {
     cl_object v8;
     T5 = ecl_fdefinition(VV[35]);
     T6 = cl_apply(2, T5, v4dep);
     v8 = cl_copy_list(T6);
     if (ecl_unlikely(ECL_ATOM(v7))) FEtype_error_cons(v7);
     T5 = v7;
     (ECL_CONS_CDR(T5)=v8,T5);
     if (Null(v8)) { goto L18; }
    }
    T5 = ecl_cdr(v7);
    v7 = ecl_last(T5,1);
L18:;
    goto L8;
L9:;
    T4 = ecl_cdr(v6);
    goto L1;
   }
  }
L1:;
  value0 = CONS(T3,T4);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G220                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC43__g220(cl_object volatile v1o, cl_object volatile v2s)
{
 cl_object T0, T1, T2, T3, T4, T5, T6;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   volatile cl_object v3dependencies;
   volatile cl_object v4library;
   volatile cl_object v5fasl;
   volatile cl_object v6filename;
   volatile cl_object v7name;
   volatile cl_object v8name_keyword;
   v3dependencies = L39binary_op_dependencies(v1o, v2s);
   T0 = ecl_fdefinition(VV[35]);
   T1 = ecl_car(v3dependencies);
   T2 = cl_apply(2, T0, T1);
   v4library = ecl_car(T2);
   T0 = ecl_fdefinition(VV[35]);
   T1 = ecl_cadr(v3dependencies);
   T2 = cl_apply(2, T0, T1);
   v5fasl = ecl_car(T2);
   T0 = ecl_function_dispatch(cl_env_copy,VV[35])(2, v1o, v2s) /*  OUTPUT-FILES */;
   v6filename = ecl_car(T0);
   v7name = ecl_function_dispatch(cl_env_copy,VV[98])(1, v2s) /*  COMPONENT-NAME */;
   T0 = cl_string(v7name);
   T1 = cl_find_package(VV[66]);
   v8name_keyword = cl_intern(2, T0, T1);
   {
    cl_object v9;
    v9 = v3dependencies;
    goto L13;
L12:;
    {
     cl_object v10dep;
     v10dep = ecl_car(v9);
     T0 = ecl_fdefinition(VV[36]);
     cl_apply(2, T0, v10dep);
    }
    v9 = ecl_cdr(v9);
L13:;
    if (Null(v9)) { goto L21; }
    goto L12;
L21:;
   }
   {
    volatile cl_object v9s;
    v9s = cl_open(7, v6filename, ECL_SYM("DIRECTION",1218), ECL_SYM("OUTPUT",1282), ECL_SYM("IF-EXISTS",1245), ECL_SYM("SUPERSEDE",1314), ECL_SYM("IF-DOES-NOT-EXIST",1244), ECL_SYM("CREATE",1213));
    {
     volatile bool unwinding = FALSE;
     cl_index v10=ECL_STACK_INDEX(cl_env_copy),v11;
     ecl_frame_ptr next_fr;
     if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
       unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
     } else {
     {
      struct ecl_stack_frame _ecl_inner_frame_aux;
      volatile cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
      {
       cl_object v12;
       v12 = _ecl_inner_frame;
       cl_format(3, v9s, _ecl_static_9, v7name);
       T0 = (cl_env_copy->function=(ECL_SYM("LISP-IMPLEMENTATION-TYPE",479)->symbol.gfdef))->cfun.entry(0) /*  LISP-IMPLEMENTATION-TYPE */;
       T1 = (cl_env_copy->function=(ECL_SYM("LISP-IMPLEMENTATION-VERSION",480)->symbol.gfdef))->cfun.entry(0) /*  LISP-IMPLEMENTATION-VERSION */;
       T2 = (cl_env_copy->function=(ECL_SYM("SOFTWARE-TYPE",784)->symbol.gfdef))->cfun.entry(0) /*  SOFTWARE-TYPE */;
       T3 = (cl_env_copy->function=(ECL_SYM("MACHINE-TYPE",516)->symbol.gfdef))->cfun.entry(0) /*  MACHINE-TYPE */;
       T4 = (cl_env_copy->function=(ECL_SYM("SOFTWARE-VERSION",785)->symbol.gfdef))->cfun.entry(0) /*  SOFTWARE-VERSION */;
       cl_format(7, v9s, _ecl_static_10, T0, T1, T2, T3, T4);
       T0 = cl_find_package(VV[66]);
       ecl_bds_bind(cl_env_copy,ECL_SYM("*PACKAGE*",43),T0); /*  *PACKAGE* */
       T0 = cl_pathname_name(1, v5fasl);
       T1 = cl_list(2, VV[70], T0);
       T2 = ecl_list1(T1);
       T3 = cl_pathname_name(1, v4library);
       T4 = cl_pathname_type(1, v4library);
       T5 = cl_make_pathname(4, ECL_SYM("NAME",1273), T3, ECL_SYM("TYPE",1318), T4);
       T6 = cl_list(8, VV[67], v8name_keyword, VV[68], VV[63], VV[69], T2, VV[45], T5);
       cl_env_copy->values[0] = cl_pprint(2, T6, v9s);
       ecl_bds_unwind1(cl_env_copy);
       ecl_stack_frame_push_values(v12);
       if (Null(v9s)) { goto L31; }
       cl_close(1, v9s);
L31:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v12);
      }
      ecl_stack_frame_close(_ecl_inner_frame);
     }
     }
     ecl_frs_pop(cl_env_copy);
     v11=ecl_stack_push_values(cl_env_copy);
     if (Null(v9s)) { goto L33; }
     cl_close(3, v9s, ECL_SYM("ABORT",1195), ECL_T);
L33:;
     ecl_stack_pop_values(cl_env_copy,v11);
     if (unwinding) ecl_unwind(cl_env_copy,next_fr);
     ECL_STACK_SET_INDEX(cl_env_copy,v10);
     return cl_env_copy->values[0];
    }
   }
  }
 }
}
/*	function definition for COPY-STREAM-TO-STREAM                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L44copy_stream_to_stream(volatile cl_narg narg, cl_object volatile v1input, cl_object volatile v2output, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  volatile cl_object v3element_type;
  volatile cl_object v4buffer_size;
  ecl_va_list args; ecl_va_start(args,v2output,narg,2);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L44copy_stream_to_streamkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[2])) {
    v3element_type = ECL_SYM("CHARACTER",222);
   } else {
    v3element_type = keyvars[0];
   }
   if (Null(keyvars[3])) {
    v4buffer_size = ecl_make_fixnum(8192);
   } else {
    v4buffer_size = keyvars[1];
   }
  }
  {
   volatile bool unwinding = FALSE;
   cl_index v5=ECL_STACK_INDEX(cl_env_copy),v6;
   ecl_frame_ptr next_fr;
   if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
     unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
   } else {
   {
    cl_object v7buffer;
    v7buffer = ECL_NIL;
    {
     cl_object v8end;
     v8end = ECL_NIL;
L6:;
     T0 = ecl_list1(v4buffer_size);
     v7buffer = si_make_pure_array(v3element_type, T0, ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
     v8end = cl_read_sequence(2, v7buffer, v1input);
     if (!(ecl_zerop(v8end))) { goto L12; }
     goto L7;
L12:;
     cl_write_sequence(4, v7buffer, v2output, ECL_SYM("END",1225), v8end);
     if (!(ecl_number_compare(v8end,v4buffer_size)<0)) { goto L14; }
     cl_env_copy->values[0] = ECL_NIL;
     cl_env_copy->nvalues = 1;
     goto L3;
L14:;
     goto L6;
L7:;
     cl_env_copy->values[0] = ECL_NIL;
     cl_env_copy->nvalues = 1;
    }
   }
L3:;
   }
   ecl_frs_pop(cl_env_copy);
   v6=ecl_stack_push_values(cl_env_copy);
   cl_close(1, v1input);
   ecl_stack_pop_values(cl_env_copy,v6);
   if (unwinding) ecl_unwind(cl_env_copy,next_fr);
   ECL_STACK_SET_INDEX(cl_env_copy,v5);
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for CONCATENATE-FILES                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L45concatenate_files(cl_object volatile v1inputs, cl_object volatile v2output)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   volatile cl_object v3o;
   v3o = cl_open(7, v2output, ECL_SYM("ELEMENT-TYPE",1224), VV[72], ECL_SYM("DIRECTION",1218), ECL_SYM("OUTPUT",1282), ECL_SYM("IF-EXISTS",1245), ECL_SYM("RENAME-AND-DELETE",1301));
   {
    volatile bool unwinding = FALSE;
    cl_index v4=ECL_STACK_INDEX(cl_env_copy),v5;
    ecl_frame_ptr next_fr;
    if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
      unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
    } else {
    {
     struct ecl_stack_frame _ecl_inner_frame_aux;
     volatile cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
     {
      volatile cl_object v6;
      v6 = _ecl_inner_frame;
      {
       volatile cl_object v7;
       v7 = v1inputs;
       goto L10;
L9:;
       {
        volatile cl_object v8input;
        v8input = ecl_car(v7);
        {
         volatile cl_object v9i;
         v9i = cl_open(7, v8input, ECL_SYM("ELEMENT-TYPE",1224), VV[72], ECL_SYM("DIRECTION",1218), ECL_SYM("INPUT",1254), ECL_SYM("IF-DOES-NOT-EXIST",1244), ECL_SYM("ERROR",1229));
         {
          volatile bool unwinding = FALSE;
          cl_index v10=ECL_STACK_INDEX(cl_env_copy),v11;
          ecl_frame_ptr next_fr;
          if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
            unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
          } else {
          {
          struct ecl_stack_frame _ecl_inner_frame_aux;
          volatile cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
          {
          cl_object v12;
          v12 = _ecl_inner_frame;
          cl_env_copy->values[0] = L44copy_stream_to_stream(4, v9i, v3o, ECL_SYM("ELEMENT-TYPE",1224), VV[72]);
          ecl_stack_frame_push_values(v12);
          if (Null(v9i)) { goto L21; }
          cl_close(1, v9i);
L21:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v12);
          }
          ecl_stack_frame_close(_ecl_inner_frame);
          }
          }
          ecl_frs_pop(cl_env_copy);
          v11=ecl_stack_push_values(cl_env_copy);
          if (Null(v9i)) { goto L23; }
          cl_close(3, v9i, ECL_SYM("ABORT",1195), ECL_T);
L23:;
          ecl_stack_pop_values(cl_env_copy,v11);
          if (unwinding) ecl_unwind(cl_env_copy,next_fr);
          ECL_STACK_SET_INDEX(cl_env_copy,v10);
         }
        }
       }
       v7 = ecl_cdr(v7);
L10:;
       if (Null(v7)) { goto L27; }
       goto L9;
L27:;
       cl_env_copy->values[0] = ECL_NIL;
       cl_env_copy->nvalues = 1;
      }
      ecl_stack_frame_push_values(v6);
      if (Null(v3o)) { goto L29; }
      cl_close(1, v3o);
L29:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v6);
     }
     ecl_stack_frame_close(_ecl_inner_frame);
    }
    }
    ecl_frs_pop(cl_env_copy);
    v5=ecl_stack_push_values(cl_env_copy);
    if (Null(v3o)) { goto L31; }
    cl_close(3, v3o, ECL_SYM("ABORT",1195), ECL_T);
L31:;
    ecl_stack_pop_values(cl_env_copy,v5);
    if (unwinding) ecl_unwind(cl_env_copy,next_fr);
    ECL_STACK_SET_INDEX(cl_env_copy,v4);
    return cl_env_copy->values[0];
   }
  }
 }
}
/*	function definition for ADD-PATHNAME-SUFFIX                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L46add_pathname_suffix(cl_object v1pathname, cl_object v2suffix)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_pathname_name(1, v1pathname);
  T1 = ecl_function_dispatch(cl_env_copy,VV[99])(2, T0, v2suffix) /*  STRCAT */;
  value0 = cl_make_pathname(4, ECL_SYM("NAME",1273), T1, ECL_SYM("DEFAULTS",1216), v1pathname);
  return value0;
 }
}
/*	function definition for COMBINE-FASLS                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L47combine_fasls(cl_object v1inputs, cl_object v2output)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[124])(0) /*  IMPLEMENTATION-TYPE */;
  value0 = cl_error(3, _ecl_static_11, VV[76], T0);
  return value0;
 }
}
/*	function definition for CALL-WITH-STAGING-PATHNAME            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L48call_with_staging_pathname(cl_object volatile v1pathname, cl_object volatile v2fun)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   volatile cl_object v3pathname;
   volatile cl_object v4staging;
   v3pathname = cl_pathname(v1pathname);
   v4staging = ecl_function_dispatch(cl_env_copy,VV[74])(2, v3pathname, _ecl_static_12) /*  ADD-PATHNAME-SUFFIX */;
   {
    volatile bool unwinding = FALSE;
    cl_index v5=ECL_STACK_INDEX(cl_env_copy),v6;
    ecl_frame_ptr next_fr;
    if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
      unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
    } else {
    {
     struct ecl_stack_frame _ecl_inner_frame_aux;
     volatile cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
     {
      cl_object v7;
      v7 = _ecl_inner_frame;
      cl_env_copy->values[0] = ecl_function_dispatch(cl_env_copy,v2fun)(1, v4staging);
      ecl_stack_frame_push_values(v7);
      cl_rename_file(2, v4staging, v3pathname);cl_env_copy->values[0]=ecl_stack_frame_pop_values(v7);
     }
     ecl_stack_frame_close(_ecl_inner_frame);
    }
    }
    ecl_frs_pop(cl_env_copy);
    v6=ecl_stack_push_values(cl_env_copy);
    if (Null(ecl_function_dispatch(cl_env_copy,VV[126])(1, v4staging) /*  PROBE-FILE* */)) { goto L9; }
    cl_delete_file(v4staging);
L9:;
    ecl_stack_pop_values(cl_env_copy,v6);
    if (unwinding) ecl_unwind(cl_env_copy,next_fr);
    ECL_STACK_SET_INDEX(cl_env_copy,v5);
    return cl_env_copy->values[0];
   }
  }
 }
}
/*	local function WITH-STAGING-PATHNAME                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC49with_staging_pathname(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6pathname_var;
   cl_object v7pathname_value;
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
    v6pathname_var = v8;
   }
   if (Null(v5)) { goto L16; }
   {
    cl_object v8;
    v8 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v7pathname_value = v8;
    goto L15;
   }
L16:;
   v7pathname_value = v6pathname_var;
L15:;
   if (Null(v5)) { goto L21; }
   si_dm_too_many_arguments(v1);
L21:;
   T0 = ecl_list1(v6pathname_var);
   T1 = cl_listX(3, ECL_SYM("LAMBDA",452), T0, v3);
   T2 = cl_list(2, ECL_SYM("FUNCTION",396), T1);
   value0 = cl_list(3, VV[78], v7pathname_value, T2);
   return value0;
  }
 }
}
/*	local function G244                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC50__g244(cl_object v1o, cl_object v2c)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G245                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC51__g245(cl_object v1o, cl_object v2c)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G248                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC52__g248(cl_object v1system)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2f;
   cl_object v3p;
   v2f = ecl_function_dispatch(cl_env_copy,VV[128])(1, v1system) /*  %SYSTEM-FASL */;
   if ((cl_pathnamep(v2f))!=ECL_NIL) { goto L5; }
   if (!(ECL_STRINGP(v2f))) { goto L3; }
   goto L4;
L5:;
L4:;
   v3p = v2f;
   goto L2;
L3:;
   if (Null(cl_functionp(v2f))) { goto L7; }
   v3p = ecl_function_dispatch(cl_env_copy,v2f)(0);
   goto L2;
L7:;
   if (!(ECL_CONSP(v2f))) { goto L9; }
   v3p = cl_eval(v2f);
   goto L2;
L9:;
   v3p = si_etypecase_error(v2f, VV[82]);
L2:;
   value0 = cl_pathname(v3p);
   return value0;
  }
 }
}
/*	local function G251                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC53__g251(cl_object v1o, cl_object v2s)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[81])(1, v2s) /*  SYSTEM-FASL */;
  value0 = ecl_list1(T0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G252                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC54__g252(cl_object v1o, cl_object v2s)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[81])(1, v2s) /*  SYSTEM-FASL */;
  value0 = cl_load(1, T0);
  return value0;
 }
}
/*	local function G253                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC55__g253(cl_object v1o, cl_object v2s)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = (cl_env_copy->function=(ECL_SYM("MAKE-INSTANCE",949)->symbol.gfdef))->cfun.entry(1, VV[23]) /*  MAKE-INSTANCE */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[34])(2, T0, v2s) /*  INPUT-FILES */;
  return value0;
 }
}
/*	local function G254                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC56__g254(cl_object v1o, cl_object v2s)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = (cl_env_copy->function=(ECL_SYM("MAKE-INSTANCE",949)->symbol.gfdef))->cfun.entry(1, VV[23]) /*  MAKE-INSTANCE */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[36])(2, T0, v2s) /*  PERFORM */;
  return value0;
 }
}
/*	local function G261                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC57__g261(cl_object v1o, cl_object v2c)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4file;
   cl_object v5;
   if (Null(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)))) { goto L2; }
   T0 = ecl_car(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
   T1 = ecl_cdr(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
   v3 = ecl_function_dispatch(cl_env_copy,T0)(2, ecl_symbol_value(ECL_SYM(".COMBINED-METHOD-ARGS.",1473)), T1);
   goto L1;
L2:;
   v3 = cl_error(1, _ecl_static_4);
L1:;
   v4file = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v3))) FEtype_error_list(v3);
   v5 = v3;
   {
    cl_object v6;
    cl_object v7;
    v6 = ecl_list1(ECL_NIL);
    v7 = v6;
L10:;
    if (!(ecl_endp(v5))) { goto L12; }
    goto L11;
L12:;
    v4file = _ecl_car(v5);
    {
     cl_object v8;
     v8 = _ecl_cdr(v5);
     if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
     v5 = v8;
    }
    if (ecl_unlikely(ECL_ATOM(v7))) FEtype_error_cons(v7);
    T0 = v7;
    T1 = cl_make_pathname(4, ECL_SYM("TYPE",1318), _ecl_static_13, ECL_SYM("DEFAULTS",1216), v4file);
    v7 = ecl_list1(T1);
    (ECL_CONS_CDR(T0)=v7,T0);
    goto L10;
L11:;
    value0 = ecl_cdr(v6);
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	local function G267                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC58__g267(cl_object v1o, cl_object v2c)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3object_files;
   cl_object v4output;
   T0 = ecl_function_dispatch(cl_env_copy,VV[34])(2, v1o, v2c) /*  INPUT-FILES */;
   T1 = (ECL_SYM("PATHNAME-TYPE",636)->symbol.gfdef);
   T2 = (ECL_SYM("STRING=",822)->symbol.gfdef);
   v3object_files = cl_remove(6, _ecl_static_14, T0, ECL_SYM("KEY",1262), T1, ECL_SYM("TEST",1316), T2);
   v4output = ecl_function_dispatch(cl_env_copy,VV[35])(2, v1o, v2c) /*  OUTPUT-FILES */;
   T0 = ecl_car(v4output);
   cl_ensure_directories_exist(1, T0);
   T0 = ecl_fdefinition(VV[129]);
   T1 = ecl_function_dispatch(cl_env_copy,VV[101])(1, v1o) /*  BUNDLE-OP-TYPE */;
   T2 = ecl_car(v4output);
   T3 = ecl_function_dispatch(cl_env_copy,VV[130])(1, v1o) /*  BUNDLE-OP-LISP-FILES */;
   T4 = ecl_append(v3object_files,T3);
   T5 = ecl_function_dispatch(cl_env_copy,VV[19])(1, v1o) /*  BUNDLE-OP-BUILD-ARGS */;
   if (Null(si_of_class_p(2, v1o, VV[5]))) { goto L8; }
   if (Null(ecl_function_dispatch(cl_env_copy,VV[131])(1, v1o) /*  MONOLITHIC-OP-PROLOGUE-CODE */)) { goto L8; }
   T7 = ecl_function_dispatch(cl_env_copy,VV[131])(1, v1o) /*  MONOLITHIC-OP-PROLOGUE-CODE */;
   T6 = cl_list(2, VV[14], T7);
   goto L7;
L8:;
   T6 = ECL_NIL;
L7:;
   if (Null(si_of_class_p(2, v1o, VV[5]))) { goto L12; }
   if (Null(ecl_function_dispatch(cl_env_copy,VV[132])(1, v1o) /*  MONOLITHIC-OP-EPILOGUE-CODE */)) { goto L12; }
   T8 = ecl_function_dispatch(cl_env_copy,VV[132])(1, v1o) /*  MONOLITHIC-OP-EPILOGUE-CODE */;
   T7 = cl_list(2, VV[15], T8);
   goto L11;
L12:;
   T7 = ECL_NIL;
L11:;
   T8 = cl_append(3, T5, T6, T7);
   value0 = cl_apply(6, T0, T1, T2, VV[13], T4, T8);
   return value0;
  }
 }
}

#include "ext/asdf-bundle.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecl1NAweO4H8yhr9_ze4AZE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("EXT:ASDF;ASDF-BUNDLE.LISP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_ecl1NAweO4H8yhr9_ze4AZE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[83]);                           /*  FASL-TYPE       */
 clos_load_defclass(VV[1], VVtemp[0], VVtemp[1], ECL_NIL);
 clos_load_defclass(VV[2], VVtemp[2], VVtemp[3], ECL_NIL);
 clos_load_defclass(VV[3], VVtemp[2], VVtemp[4], ECL_NIL);
 clos_load_defclass(VV[4], VVtemp[2], VVtemp[5], ECL_NIL);
 clos_load_defclass(VV[5], VVtemp[2], VVtemp[6], ECL_NIL);
 ecl_cmp_defun(VV[84]);                           /*  BUNDLE-OP-MONOLITHIC-P */
 clos_load_defclass(VV[7], VVtemp[7], ECL_NIL, ECL_NIL);
 clos_load_defclass(VV[8], VVtemp[8], VVtemp[4], ECL_NIL);
 clos_load_defclass(VV[9], VVtemp[9], VVtemp[5], ECL_NIL);
 clos_load_defclass(VV[10], VVtemp[10], VVtemp[11], ECL_NIL);
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC3__g38,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("INITIALIZE-INSTANCE",947), VVtemp[12], VVtemp[2], VVtemp[13], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC4__g62,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, VV[19], VVtemp[14], VVtemp[15], VVtemp[16], T0, ECL_T);
 }
 si_Xmake_special(VV[21]);
 if (ecl_boundp(cl_env_copy,VV[21])) { goto L24; }
 cl_set(VV[21],ECL_NIL);
L24:;
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC5__g65,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[22], VVtemp[14], VVtemp[17], VVtemp[18], T0, ECL_T);
 }
 ecl_cmp_defun(VV[92]);                           /*  GATHER-COMPONENTS */
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(5, VV[25], VV[26], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[19]) /*  ENSURE-GENERIC-FUNCTION */;
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC7__g73,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[25], ECL_NIL, VVtemp[20], VVtemp[21], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC8__g74,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[25], ECL_NIL, VVtemp[22], VVtemp[21], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC9__g75,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[25], ECL_NIL, VVtemp[23], VVtemp[21], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC10__g76,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[25], ECL_NIL, VVtemp[24], VVtemp[21], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC11__g77,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[25], ECL_NIL, VVtemp[25], VVtemp[21], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC12__g84,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[33], ECL_NIL, VVtemp[26], VVtemp[21], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC13__g91,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[33], ECL_NIL, VVtemp[27], VVtemp[21], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC14__g92,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[33], ECL_NIL, VVtemp[28], VVtemp[21], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC15__g103,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[34], ECL_NIL, VVtemp[26], VVtemp[21], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC16__g112,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[35], ECL_NIL, VVtemp[26], VVtemp[21], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC17__g113,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[36], ECL_NIL, VVtemp[28], VVtemp[21], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC18__g114,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[22], ECL_NIL, VVtemp[29], VVtemp[21], T0, ECL_T);
 }
 ecl_cmp_defun(VV[102]);                          /*  SELECT-OPERATION */
 ecl_cmp_defun(VV[103]);                          /*  MAKE-BUILD      */
 clos_load_defclass(VV[58], VVtemp[0], ECL_NIL, ECL_NIL);
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC21__g129,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[33], ECL_NIL, VVtemp[30], VVtemp[21], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC22__g130,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[34], ECL_NIL, VVtemp[30], VVtemp[21], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC23__g131,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[36], ECL_NIL, VVtemp[31], VVtemp[21], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC24__g146,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[36], ECL_NIL, VVtemp[30], VVtemp[21], T0, ECL_T);
 }
 clos_load_defclass(VV[59], VVtemp[32], VVtemp[33], ECL_NIL);
 ecl_cmp_defun(VV[111]);                          /*  TRIVIAL-SYSTEM-P */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC27__g154,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, VV[61], ECL_NIL, VVtemp[34], VVtemp[32], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC28__g155,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[35], ECL_NIL, VVtemp[35], VVtemp[21], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC29__g156,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[34], ECL_NIL, VVtemp[35], VVtemp[21], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC30__g157,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[36], ECL_NIL, VVtemp[36], VVtemp[21], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC31__g158,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[36], ECL_NIL, VVtemp[37], VVtemp[21], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC32__g159,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[36], ECL_NIL, VVtemp[35], VVtemp[21], T0, ECL_T);
 }
 clos_load_defclass(VV[63], VVtemp[38], VVtemp[39], ECL_NIL);
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC33__g160,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[35], ECL_NIL, VVtemp[40], VVtemp[21], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC34__g161,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[36], ECL_NIL, VVtemp[40], VVtemp[21], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC35__g162,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[33], ECL_NIL, VVtemp[40], VVtemp[21], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC36__g163,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[25], ECL_NIL, VVtemp[40], VVtemp[21], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC37__g164,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[25], ECL_NIL, VVtemp[41], VVtemp[21], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC38__g165,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[25], ECL_NIL, VVtemp[42], VVtemp[21], T0, ECL_T);
 }
 clos_load_defclass(VV[40], VVtemp[2], ECL_NIL, ECL_NIL);
 clos_load_defclass(VV[39], VVtemp[43], ECL_NIL, ECL_NIL);
 ecl_cmp_defun(VV[116]);                          /*  BINARY-OP-DEPENDENCIES */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC40__g176,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[33], ECL_NIL, VVtemp[44], VVtemp[45], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC41__g194,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[34], ECL_NIL, VVtemp[44], VVtemp[45], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC42__g212,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[35], ECL_NIL, VVtemp[44], VVtemp[45], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC43__g220,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[36], ECL_NIL, VVtemp[44], VVtemp[45], T0, ECL_T);
 }
 ecl_cmp_defun(VV[118]);                          /*  COPY-STREAM-TO-STREAM */
 ecl_cmp_defun(VV[121]);                          /*  CONCATENATE-FILES */
 cl_fmakunbound(VV[74]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[46]) /*  MAPC */;
 ecl_cmp_defun(VV[122]);                          /*  ADD-PATHNAME-SUFFIX */
 ecl_cmp_defun(VV[123]);                          /*  COMBINE-FASLS   */
 ecl_cmp_defun(VV[125]);                          /*  CALL-WITH-STAGING-PATHNAME */
 ecl_cmp_defmacro(VV[127]);                       /*  WITH-STAGING-PATHNAME */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC50__g244,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[35], ECL_NIL, VVtemp[47], VVtemp[21], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC51__g245,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[34], ECL_NIL, VVtemp[47], VVtemp[21], T0, ECL_T);
 }
 clos_load_defclass(VV[80], VVtemp[38], VVtemp[48], ECL_NIL);
 {
  cl_object T0, T1;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(5, VV[81], VV[26], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[38]) /*  ENSURE-GENERIC-FUNCTION */;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC52__g248,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 T1 = clos_install_method(6, VV[81], ECL_NIL, VVtemp[49], VVtemp[38], T0, ECL_T);
 clos_associate_methods_to_gfun(2, VV[81], T1);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC53__g251,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[34], ECL_NIL, VVtemp[50], VVtemp[45], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC54__g252,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[36], ECL_NIL, VVtemp[50], VVtemp[45], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC55__g253,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[34], ECL_NIL, VVtemp[51], VVtemp[45], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC56__g254,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[36], ECL_NIL, VVtemp[51], VVtemp[45], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC57__g261,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[35], ECL_NIL, VVtemp[52], VVtemp[21], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC58__g267,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[36], ECL_NIL, VVtemp[26], VVtemp[21], T0, ECL_T);
 }
 cl_export(1, VVtemp[53]);
 cl_set(ECL_SYM("*LOAD-HOOKS*",1025),cl_adjoin(6, VVtemp[54], ecl_symbol_value(ECL_SYM("*LOAD-HOOKS*",1025)), ECL_SYM("TEST",1316), ECL_SYM("EQUAL",335), ECL_SYM("KEY",1262), ECL_SYM("CAR",180)));
}
