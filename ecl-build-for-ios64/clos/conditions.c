/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CLOS;CONDITIONS.LSP                               */
#include <ecl/ecl-cmp.h>
#include "clos/conditions.eclh"
/*	local function UNIQUE-ID                                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC1unique_id(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4obj;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4obj = v5;
   }
   if (Null(v3)) { goto L8; }
   si_dm_too_many_arguments(v1);
L8:;
   value0 = cl_list(2, ECL_SYM("POINTER",1117), v4obj);
   return value0;
  }
 }
}
/*	function definition for COMPUTE-RESTARTS                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2compute_restarts(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1condition;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1condition = ECL_NIL;
   } else {
    i++;
    v1condition = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v2assoc_restart;
   cl_object v3other;
   cl_object v4output;
   v2assoc_restart = ECL_NIL;
   v3other = ECL_NIL;
   v4output = ECL_NIL;
   if (Null(v1condition)) { goto L5; }
   {
    cl_object v5;
    v5 = ecl_symbol_value(VV[1]);
    goto L10;
L9:;
    {
     cl_object v6i;
     v6i = ecl_car(v5);
     T0 = ecl_car(v6i);
     if (!((T0)==(v1condition))) { goto L15; }
     T0 = ecl_cdr(v6i);
     v2assoc_restart = ecl_append(T0,v2assoc_restart);
     goto L14;
L15:;
     T0 = ecl_cdr(v6i);
     v3other = ecl_append(T0,v3other);
L14:;
    }
    v5 = ecl_cdr(v5);
L10:;
    if (Null(v5)) { goto L21; }
    goto L9;
L21:;
   }
L5:;
   {
    cl_object v5;
    v5 = ecl_symbol_value(ECL_SYM("*RESTART-CLUSTERS*",4));
    goto L27;
L26:;
    {
     cl_object v6restart_cluster;
     v6restart_cluster = ecl_car(v5);
     {
      cl_object v7;
      v7 = v6restart_cluster;
      goto L35;
L34:;
      {
       cl_object v8restart;
       v8restart = ecl_car(v7);
       if (Null(v1condition)) { goto L42; }
       if ((ecl_memql(v8restart,v2assoc_restart))!=ECL_NIL) { goto L42; }
       if ((ecl_memql(v8restart,v3other))!=ECL_NIL) { goto L39; }
       goto L41;
L42:;
L41:;
       T0 = ecl_function_dispatch(cl_env_copy,VV[55])(1, v8restart) /*  RESTART-TEST-FUNCTION */;
       if (Null(ecl_function_dispatch(cl_env_copy,T0)(1, v1condition))) { goto L39; }
       v4output = CONS(v8restart,v4output);
L39:;
      }
      v7 = ecl_cdr(v7);
L35:;
      if (Null(v7)) { goto L49; }
      goto L34;
L49:;
     }
    }
    v5 = ecl_cdr(v5);
L27:;
    if (Null(v5)) { goto L53; }
    goto L26;
L53:;
   }
   value0 = cl_nreverse(v4output);
   return value0;
  }
 }
}
/*	function definition for RESTART-PRINT                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3restart_print(cl_object v1restart, cl_object v2stream, cl_object v3depth)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_symbol_value(ECL_SYM("*PRINT-ESCAPE*",48)))) { goto L2; }
  T0 = cl_type_of(v1restart);
  T1 = si_pointer(v1restart);
  cl_format(4, v2stream, _ecl_static_1, T0, T1);
  goto L1;
L2:;
  L5restart_report(v1restart, v2stream);
L1:;
  value0 = v1restart;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for MAKE-RESTART                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4make_restart(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1;
  cl_object v2;
  cl_object v3;
  cl_object v4;
  cl_object v5;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  {
   cl_object keyvars[10];
   cl_parse_key(args,5,L4make_restartkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v1 = keyvars[0];
   v2 = keyvars[1];
   v3 = keyvars[2];
   v4 = keyvars[3];
   if (Null(keyvars[9])) {
    v5 = cl_constantly(ECL_T);
   } else {
    v5 = keyvars[4];
   }
  }
  value0 = si_make_structure(6, VV[6], v1, v2, v3, v4, v5);
  return value0;
 }
}
/*	function definition for RESTART-REPORT                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5restart_report(cl_object v1restart, cl_object v2stream)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3fn;
   v3fn = ecl_function_dispatch(cl_env_copy,VV[63])(1, v1restart) /*  RESTART-REPORT-FUNCTION */;
   if (Null(v3fn)) { goto L2; }
   value0 = ecl_function_dispatch(cl_env_copy,v3fn)(1, v2stream);
   return value0;
L2:;
   value0 = (cl_env_copy->function=(ECL_SYM("RESTART-NAME",723)->symbol.gfdef))->cfun.entry(1, v1restart) /*  RESTART-NAME */;
   if ((value0)!=ECL_NIL) { goto L6; }
   T0 = v1restart;
   goto L4;
L6:;
   T0 = value0;
   goto L4;
L4:;
   value0 = cl_format(3, v2stream, _ecl_static_3, T0);
   return value0;
  }
 }
}
/*	function definition for BIND-SIMPLE-RESTARTS                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_bind_simple_restarts(cl_object v1tag, cl_object v2names)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3i;
   v3i = ecl_make_fixnum(1);
   {
    cl_object v4;
    cl_object v5n;
    cl_object v6;
    if (!(ECL_ATOM(v2names))) { goto L4; }
    v4 = ecl_list1(v2names);
    goto L3;
L4:;
    v4 = v2names;
L3:;
    v5n = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
    v6 = v4;
    {
     cl_object v7f;
     v7f = ECL_NIL;
     {
      cl_object v8;
      cl_object v9;
      v8 = ecl_list1(ECL_NIL);
      v9 = v8;
L12:;
      if (!(ecl_endp(v6))) { goto L14; }
      goto L13;
L14:;
      v5n = _ecl_car(v6);
      {
       cl_object v10;
       v10 = _ecl_cdr(v6);
       if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
       v6 = v10;
      }
      v7f = LC7simple_restart_function(v1tag, v3i);
      if (ecl_unlikely(ECL_ATOM(v9))) FEtype_error_cons(v9);
      T1 = v9;
      T2 = L4make_restart(4, ECL_SYM("NAME",1273), v5n, ECL_SYM("FUNCTION",1241), v7f);
      v9 = ecl_list1(T2);
      (ECL_CONS_CDR(T1)=v9,T1);
      v3i = ecl_one_plus(v3i);
      goto L12;
L13:;
      T0 = ecl_cdr(v8);
      goto L1;
     }
    }
   }
  }
L1:;
  value0 = CONS(T0,ecl_symbol_value(ECL_SYM("*RESTART-CLUSTERS*",4)));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function SIMPLE-RESTART-FUNCTION                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC7simple_restart_function(cl_object v1tag, cl_object v2code)
{
 cl_object env0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1tag,env0);                 /*  TAG             */
  CLV1 = env0 = CONS(v2code,env0);                /*  CODE            */
  {cl_object v3;
   v3 = ECL_NIL;
   v3 = ecl_make_cclosure_va((cl_objectfn)LC6__g17,env0,Cblock);
   value0 = v3;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	closure G17                                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC6__g17(cl_narg narg, ...)
{
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  CODE            */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 {
  cl_object v1args;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1args = cl_grab_rest_args(args);
  ecl_va_end(args);
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = v1args;
  cl_env_copy->values[0] = ECL_CONS_CAR(CLV1);
  cl_throw(ECL_CONS_CAR(CLV0));
 }
 }
}
/*	function definition for BIND-SIMPLE-HANDLERS                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_bind_simple_handlers(cl_object v1tag, cl_object v2names)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3i;
   v3i = ecl_make_fixnum(1);
   {
    cl_object v4;
    cl_object v5n;
    cl_object v6;
    if (!(ECL_ATOM(v2names))) { goto L4; }
    v4 = ecl_list1(v2names);
    goto L3;
L4:;
    v4 = v2names;
L3:;
    v5n = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
    v6 = v4;
    {
     cl_object v7f;
     v7f = ECL_NIL;
     {
      cl_object v8;
      cl_object v9;
      v8 = ecl_list1(ECL_NIL);
      v9 = v8;
L12:;
      if (!(ecl_endp(v6))) { goto L14; }
      goto L13;
L14:;
      v5n = _ecl_car(v6);
      {
       cl_object v10;
       v10 = _ecl_cdr(v6);
       if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
       v6 = v10;
      }
      v7f = ecl_function_dispatch(cl_env_copy,VV[64])(2, v1tag, v3i) /*  SIMPLE-RESTART-FUNCTION */;
      if (ecl_unlikely(ECL_ATOM(v9))) FEtype_error_cons(v9);
      T1 = v9;
      T2 = CONS(ecl_symbol_value(VV[8]),v7f);
      v9 = ecl_list1(T2);
      (ECL_CONS_CDR(T1)=v9,T1);
      v3i = ecl_one_plus(v3i);
      goto L12;
L13:;
      T0 = ecl_cdr(v8);
      goto L1;
     }
    }
   }
  }
L1:;
  value0 = CONS(T0,ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5)));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function RESTART-BIND                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC10restart_bind(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4bindings;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4bindings = v5;
   }
   {
    cl_object v5;
    cl_object v6;
    v5 = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v4bindings))) FEtype_error_list(v4bindings);
    v6 = v4bindings;
    {
     cl_object v7;
     cl_object v8;
     v7 = ecl_list1(ECL_NIL);
     v8 = v7;
L14:;
     if (!(ecl_endp(v6))) { goto L16; }
     goto L15;
L16:;
     v5 = _ecl_car(v6);
     {
      cl_object v9;
      v9 = _ecl_cdr(v6);
      if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
      v6 = v9;
     }
     if (ecl_unlikely(ECL_ATOM(v8))) FEtype_error_cons(v8);
     T1 = v8;
     T3 = ecl_car(v5);
     T4 = cl_list(2, ECL_SYM("QUOTE",679), T3);
     T5 = ecl_cadr(v5);
     T6 = ecl_cddr(v5);
     T2 = cl_listX(6, VV[7], ECL_SYM("NAME",1273), T4, ECL_SYM("FUNCTION",1241), T5, T6);
     v8 = ecl_list1(T2);
     (ECL_CONS_CDR(T1)=v8,T1);
     goto L14;
L15:;
     T0 = ecl_cdr(v7);
     goto L8;
    }
   }
L8:;
   T1 = CONS(ECL_SYM("LIST",481),T0);
   T2 = cl_list(3, ECL_SYM("CONS",251), T1, ECL_SYM("*RESTART-CLUSTERS*",4));
   T3 = cl_list(2, ECL_SYM("*RESTART-CLUSTERS*",4), T2);
   T4 = ecl_list1(T3);
   value0 = cl_listX(3, ECL_SYM("LET",477), T4, v3);
   return value0;
  }
 }
}
/*	function definition for FIND-RESTART                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L11find_restart(cl_narg narg, cl_object v1name, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2condition;
  va_list args; va_start(args,v1name);
  {
   int i = 1;
   if (i >= narg) {
    v2condition = ECL_NIL;
   } else {
    i++;
    v2condition = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v3;
   v3 = L2compute_restarts(1, v2condition);
   goto L5;
L4:;
   {
    cl_object v4restart;
    v4restart = ecl_car(v3);
    if ((v4restart)==(v1name)) { goto L11; }
    T0 = (cl_env_copy->function=(ECL_SYM("RESTART-NAME",723)->symbol.gfdef))->cfun.entry(1, v4restart) /*  RESTART-NAME */;
    if (!((T0)==(v1name))) { goto L9; }
    goto L10;
L11:;
L10:;
    value0 = v4restart;
    cl_env_copy->nvalues = 1;
    return value0;
L9:;
   }
   v3 = ecl_cdr(v3);
L5:;
   if (Null(v3)) { goto L15; }
   goto L4;
L15:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for FIND-RESTART-NEVER-FAIL               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L12find_restart_never_fail(cl_narg narg, cl_object v1restart, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2condition;
  va_list args; va_start(args,v1restart);
  {
   int i = 1;
   if (i >= narg) {
    v2condition = ECL_NIL;
   } else {
    i++;
    v2condition = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = L11find_restart(2, v1restart, v2condition);
  if ((value0)!=ECL_NIL) { goto L3; }
  T0 = ecl_list1(v1restart);
  value0 = si_signal_simple_error(4, ECL_SYM("CONTROL-ERROR",255), ECL_NIL, _ecl_static_4, T0);
  return value0;
L3:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for INVOKE-RESTART                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L13invoke_restart(cl_narg narg, cl_object v1restart, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2values;
  ecl_va_list args; ecl_va_start(args,v1restart,narg,1);
  v2values = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v3real_restart;
   v3real_restart = L12find_restart_never_fail(1, v1restart);
   T0 = ecl_function_dispatch(cl_env_copy,VV[68])(1, v3real_restart) /*  RESTART-FUNCTION */;
   value0 = cl_apply(2, T0, v2values);
   return value0;
  }
 }
}
/*	function definition for INVOKE-RESTART-INTERACTIVELY          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L14invoke_restart_interactively(cl_object v1restart)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2real_restart;
   v2real_restart = L12find_restart_never_fail(1, v1restart);
   T0 = ecl_function_dispatch(cl_env_copy,VV[68])(1, v2real_restart) /*  RESTART-FUNCTION */;
   {
    cl_object v3interactive_function;
    v3interactive_function = ecl_function_dispatch(cl_env_copy,VV[70])(1, v2real_restart) /*  RESTART-INTERACTIVE-FUNCTION */;
    if (Null(v3interactive_function)) { goto L4; }
    T1 = ecl_function_dispatch(cl_env_copy,v3interactive_function)(0);
    goto L2;
L4:;
    T1 = ECL_NIL;
   }
L2:;
   value0 = cl_apply(2, T0, T1);
   return value0;
  }
 }
}
/*	local function RESTART-CASE                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC16restart_case(cl_object v1, cl_object v2env)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4expression;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4expression = v5;
   }
   {cl_object v5;
    v5 = ECL_NIL;
    v5 = ecl_make_cfun_va((cl_objectfn)LC15transform_keywords,ECL_NIL,Cblock);
    {
     cl_object v6block_tag;
     cl_object v7temp_var;
     cl_object v8data;
     v6block_tag = cl_gensym(0);
     v7temp_var = cl_gensym(0);
     {
      cl_object v9;
      cl_object v10;
      v9 = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v3))) FEtype_error_list(v3);
      v10 = v3;
      {
       cl_object v11;
       cl_object v12;
       v11 = ecl_list1(ECL_NIL);
       v12 = v11;
L16:;
       if (!(ecl_endp(v10))) { goto L18; }
       goto L17;
L18:;
       v9 = _ecl_car(v10);
       {
        cl_object v13;
        v13 = _ecl_cdr(v10);
        if (ecl_unlikely(!ECL_LISTP(v13))) FEtype_error_list(v13);
        v10 = v13;
       }
       if (ecl_unlikely(ECL_ATOM(v12))) FEtype_error_cons(v12);
       T0 = v12;
       {
        cl_object v13;
        cl_object v14keywords;
        cl_object v15forms;
        v13 = ecl_cddr(v9);
        v14keywords = ECL_NIL;
        v15forms = v13;
        goto L37;
L36:;
        T2 = ecl_car(v15forms);
        if (Null(cl_keywordp(T2))) { goto L40; }
        T2 = ecl_car(v15forms);
        T3 = ecl_cadr(v15forms);
        v14keywords = cl_listX(3, T2, T3, v14keywords);
        v15forms = ecl_cddr(v15forms);
        goto L39;
L40:;
        goto L34;
L39:;
L37:;
        if (v15forms==ECL_NIL) { goto L45; }
        goto L36;
L45:;
L34:;
        T2 = ecl_car(v9);
        T3 = cl_gensym(0);
        T4 = cl_apply(2, v5, v14keywords);
        T5 = ecl_cadr(v9);
        T1 = cl_list(5, T2, T3, T4, T5, v15forms);
       }
       v12 = ecl_list1(T1);
       (ECL_CONS_CDR(T0)=v12,T0);
       goto L16;
L17:;
       v8data = ecl_cdr(v11);
       goto L10;
      }
     }
L10:;
     {
      cl_object v9expression2;
      v9expression2 = cl_macroexpand(2, v4expression, v2env);
      if (!(ECL_CONSP(v9expression2))) { goto L49; }
      {
       cl_object v10condition_form;
       cl_object v11condition_var;
       cl_object v12name;
       v10condition_form = ECL_NIL;
       v11condition_var = cl_gensym(0);
       v12name = ecl_car(v9expression2);
       if (!((v12name)==(ECL_SYM("SIGNAL",760)))) { goto L56; }
       v10condition_form = ecl_cadr(v9expression2);
       goto L55;
L56:;
       if (!((v12name)==(ECL_SYM("ERROR",337)))) { goto L59; }
       T0 = ecl_cadr(v9expression2);
       T1 = ecl_cddr(v9expression2);
       T2 = CONS(ECL_SYM("LIST",481),T1);
       v10condition_form = cl_listX(4, VV[17], T0, T2, VV[18]);
       goto L55;
L59:;
       if (!((v12name)==(ECL_SYM("CERROR",202)))) { goto L62; }
       T0 = ecl_caddr(v9expression2);
       T1 = ecl_cdddr(v9expression2);
       T2 = CONS(ECL_SYM("LIST",481),T1);
       v10condition_form = cl_listX(4, VV[17], T0, T2, VV[19]);
       goto L55;
L62:;
       if (!((v12name)==(ECL_SYM("WARN",903)))) { goto L55; }
       T0 = ecl_cadr(v9expression2);
       T1 = ecl_cddr(v9expression2);
       T2 = CONS(ECL_SYM("LIST",481),T1);
       v10condition_form = cl_listX(4, VV[17], T0, T2, VV[20]);
L55:;
       if (Null(v10condition_form)) { goto L49; }
       T0 = cl_list(2, v11condition_var, v10condition_form);
       T1 = ecl_list1(T0);
       if (!((v12name)==(ECL_SYM("CERROR",202)))) { goto L70; }
       T3 = ecl_cadr(v9expression2);
       T2 = cl_list(3, ECL_SYM("CERROR",202), T3, v11condition_var);
       goto L69;
L70:;
       T2 = cl_list(2, v12name, v11condition_var);
L69:;
       T3 = cl_list(4, ECL_SYM("WITH-CONDITION-RESTARTS",908), v11condition_var, VV[21], T2);
       v4expression = cl_list(3, ECL_SYM("LET",477), T1, T3);
      }
     }
L49:;
     T0 = cl_list(2, v7temp_var, ECL_NIL);
     T1 = ecl_list1(T0);
     {
      cl_object v9;
      cl_object v10;
      v9 = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v8data))) FEtype_error_list(v8data);
      v10 = v8data;
      {
       cl_object v11;
       cl_object v12;
       v11 = ecl_list1(ECL_NIL);
       v12 = v11;
L78:;
       if (!(ecl_endp(v10))) { goto L80; }
       goto L79;
L80:;
       v9 = _ecl_car(v10);
       {
        cl_object v13;
        v13 = _ecl_cdr(v10);
        if (ecl_unlikely(!ECL_LISTP(v13))) FEtype_error_list(v13);
        v10 = v13;
       }
       if (ecl_unlikely(ECL_ATOM(v12))) FEtype_error_cons(v12);
       T3 = v12;
       {
        cl_object v13name;
        cl_object v14tag;
        cl_object v15keys;
        v13name = ecl_car(v9);
        v14tag = ecl_cadr(v9);
        v15keys = ecl_caddr(v9);
        T5 = cl_list(3, ECL_SYM("SETQ",751), v7temp_var, VV[23]);
        T6 = cl_list(2, ECL_SYM("GO",414), v14tag);
        T7 = cl_list(4, ECL_SYM("LAMBDA",452), VV[22], T5, T6);
        T8 = cl_list(2, ECL_SYM("FUNCTION",396), T7);
        T4 = cl_listX(3, v13name, T8, v15keys);
       }
       v12 = ecl_list1(T4);
       (ECL_CONS_CDR(T3)=v12,T3);
       goto L78;
L79:;
       T2 = ecl_cdr(v11);
       goto L72;
      }
     }
L72:;
     T3 = cl_list(3, ECL_SYM("RETURN-FROM",725), v6block_tag, v4expression);
     T4 = cl_list(3, VV[9], T2, T3);
     {
      cl_object v9;
      cl_object v10;
      v9 = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v8data))) FEtype_error_list(v8data);
      v10 = v8data;
      {
       cl_object v11;
       cl_object v12;
       v11 = ecl_list1(ECL_NIL);
       v12 = v11;
L104:;
       if (!(ecl_endp(v10))) { goto L106; }
       goto L105;
L106:;
       v9 = _ecl_car(v10);
       {
        cl_object v13;
        v13 = _ecl_cdr(v10);
        if (ecl_unlikely(!ECL_LISTP(v13))) FEtype_error_list(v13);
        v10 = v13;
       }
       {
        cl_object v13;
        {
         cl_object v14tag;
         cl_object v15bvl;
         cl_object v16body;
         v14tag = ecl_cadr(v9);
         v15bvl = ecl_cadddr(v9);
         T6 = ecl_cddddr(v9);
         v16body = ecl_car(T6);
         T6 = cl_listX(3, ECL_SYM("LAMBDA",452), v15bvl, v16body);
         T7 = cl_list(2, ECL_SYM("FUNCTION",396), T6);
         T8 = cl_list(3, ECL_SYM("APPLY",89), T7, v7temp_var);
         T9 = cl_list(3, ECL_SYM("RETURN-FROM",725), v6block_tag, T8);
         v13 = cl_list(2, v14tag, T9);
        }
        if (ecl_unlikely(ECL_ATOM(v12))) FEtype_error_cons(v12);
        T6 = v12;
        (ECL_CONS_CDR(T6)=v13,T6);
        if (Null(v13)) { goto L114; }
       }
       T6 = ecl_cdr(v12);
       v12 = ecl_last(T6,1);
L114:;
       goto L104;
L105:;
       T5 = ecl_cdr(v11);
       goto L98;
      }
     }
L98:;
     T6 = cl_listX(3, ECL_SYM("TAGBODY",850), T4, T5);
     T7 = cl_list(3, ECL_SYM("LET",477), T1, T6);
     value0 = cl_list(3, ECL_SYM("BLOCK",137), v6block_tag, T7);
     return value0;
    }
   }
  }
 }
}
/*	local function TRANSFORM-KEYWORDS                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC15transform_keywords(cl_narg narg, ...)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1report;
  cl_object v2interactive;
  cl_object v3test;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  {
   cl_object keyvars[6];
   cl_parse_key(args,3,LC15transform_keywordskeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v1report = keyvars[0];
   v2interactive = keyvars[1];
   v3test = keyvars[2];
  }
  {
   cl_object v4keywords;
   v4keywords = ECL_NIL;
   if (Null(v3test)) { goto L2; }
   T0 = cl_list(2, ECL_SYM("FUNCTION",396), v3test);
   v4keywords = cl_list(2, VV[13], T0);
L2:;
   if (Null(v2interactive)) { goto L5; }
   T0 = cl_list(2, ECL_SYM("FUNCTION",396), v2interactive);
   v4keywords = cl_list(2, VV[14], T0);
L5:;
   if (Null(v1report)) { goto L8; }
   if (!(ECL_STRINGP(v1report))) { goto L12; }
   T1 = cl_list(3, ECL_SYM("WRITE-STRING",922), v1report, ECL_SYM("STREAM",799));
   T2 = cl_list(3, ECL_SYM("LAMBDA",452), VV[16], T1);
   T0 = cl_list(2, ECL_SYM("FUNCTION",396), T2);
   goto L11;
L12:;
   T0 = cl_list(2, ECL_SYM("FUNCTION",396), v1report);
L11:;
   v4keywords = cl_listX(3, VV[15], T0, v4keywords);
L8:;
   value0 = v4keywords;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function WITH-SIMPLE-RESTART                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC17with_simple_restart(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6restart_name;
   cl_object v7format_control;
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
    v6restart_name = v8;
   }
   if (!(v5==ECL_NIL)) { goto L16; }
   si_dm_too_few_arguments(v1);
L16:;
   {
    cl_object v8;
    v8 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v7format_control = v8;
   }
   T0 = CONS(ECL_SYM("PROGN",671),v3);
   T1 = cl_listX(4, ECL_SYM("FORMAT",387), ECL_SYM("STREAM",799), v7format_control, v5);
   T2 = cl_list(3, ECL_SYM("LAMBDA",452), VV[16], T1);
   T3 = cl_list(5, v6restart_name, ECL_NIL, ECL_SYM("REPORT",1302), T2, VV[25]);
   value0 = cl_list(3, VV[24], T0, T3);
   return value0;
  }
 }
}
/*	local function WITH-CONDITION-RESTARTS                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC18with_condition_restarts(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4condition;
   cl_object v5restarts;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4condition = v6;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5restarts = v6;
   }
   T0 = cl_list(3, ECL_SYM("CONS",251), v4condition, v5restarts);
   T1 = cl_list(3, ECL_SYM("CONS",251), T0, VV[1]);
   T2 = cl_list(2, VV[1], T1);
   T3 = ecl_list1(T2);
   value0 = cl_listX(3, ECL_SYM("LET",477), T3, v3);
   return value0;
  }
 }
}
/*	local function G99                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC19__g99(cl_object v1c, cl_object v2stream)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_symbol_value(ECL_SYM("*PRINT-ESCAPE*",48)))) { goto L1; }
  if (Null(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)))) { goto L3; }
  T0 = ecl_car(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
  T1 = ecl_cdr(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
  value0 = ecl_function_dispatch(cl_env_copy,T0)(2, ecl_symbol_value(ECL_SYM(".COMBINED-METHOD-ARGS.",1473)), T1);
  return value0;
L3:;
  value0 = cl_error(1, _ecl_static_5);
  return value0;
L1:;
  {
   cl_object v3reporter;
   v3reporter = cl_slot_value(v1c, ECL_SYM("REPORT-FUNCTION",1932));
   if (!(ECL_STRINGP(v3reporter))) { goto L7; }
   value0 = cl_write_string(2, v3reporter, v2stream);
   return value0;
L7:;
   if (!(v3reporter==ECL_NIL)) { goto L9; }
   if (Null(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)))) { goto L11; }
   T0 = ecl_car(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
   T1 = ecl_cdr(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
   value0 = ecl_function_dispatch(cl_env_copy,T0)(2, ecl_symbol_value(ECL_SYM(".COMBINED-METHOD-ARGS.",1473)), T1);
   return value0;
L11:;
   value0 = cl_error(1, _ecl_static_5);
   return value0;
L9:;
   value0 = ecl_function_dispatch(cl_env_copy,v3reporter)(2, v1c, v2stream);
   return value0;
  }
 }
}
/*	local function DEFINE-CONDITION                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC20define_condition(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4name;
   cl_object v5parent_list;
   cl_object v6slot_specs;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v7;
    v7 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4name = v7;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v7;
    v7 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5parent_list = v7;
   }
   if (!(v3==ECL_NIL)) { goto L15; }
   si_dm_too_few_arguments(v1);
L15:;
   {
    cl_object v7;
    v7 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v6slot_specs = v7;
   }
   {
    cl_object v7class_options;
    v7class_options = ECL_NIL;
    {
     cl_object v8;
     v8 = v3;
     goto L25;
L24:;
     {
      cl_object v9option;
      v9option = ecl_car(v8);
      {
       cl_object v10;
       v10 = ecl_car(v9option);
       if (!(ecl_eql(v10,ECL_SYM("DEFAULT-INITARGS",987)))) { goto L36; }
       goto L33;
       goto L34;
L36:;
       goto L34;
L34:;
       if (!(ecl_eql(v10,ECL_SYM("DOCUMENTATION",1222)))) { goto L31; }
       goto L32;
L33:;
L32:;
       v7class_options = CONS(v9option,v7class_options);
       goto L29;
L31:;
       if (!(ecl_eql(v10,ECL_SYM("REPORT",1302)))) { goto L40; }
       {
        cl_object v11report_function;
        v11report_function = ecl_cadr(v9option);
        if (!(ECL_SYMBOLP(v11report_function))) { goto L45; }
        T0 = cl_list(2, ECL_SYM("QUOTE",679), v11report_function);
        goto L44;
L45:;
        T0 = v11report_function;
L44:;
        T1 = cl_list(3, ECL_SYM("REPORT-FUNCTION",1932), ECL_SYM("INITFORM",996), T0);
        v6slot_specs = CONS(T1,v6slot_specs);
        goto L29;
       }
L40:;
       cl_cerror(3, _ecl_static_6, _ecl_static_7, v9option);
      }
L29:;
     }
     v8 = ecl_cdr(v8);
L25:;
     if (Null(v8)) { goto L49; }
     goto L24;
L49:;
    }
    value0 = v5parent_list;
    if ((value0)!=ECL_NIL) { goto L53; }
    T0 = VV[30];
    goto L51;
L53:;
    T0 = value0;
    goto L51;
L51:;
    T1 = cl_listX(5, ECL_SYM("DEFCLASS",937), v4name, T0, v6slot_specs, v7class_options);
    T2 = cl_list(2, ECL_SYM("QUOTE",679), v4name);
    value0 = cl_list(3, ECL_SYM("PROGN",671), T1, T2);
    return value0;
   }
  }
 }
}
/*	function definition for FIND-SUBCLASSES-OF-TYPE               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L21find_subclasses_of_type(cl_object v1type, cl_object v2class)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_subtypep(2, v2class, v1type))) { goto L1; }
  value0 = ecl_list1(v2class);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  {
   cl_object v3;
   cl_object v4c;
   cl_object v5;
   v3 = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-DIRECT-SUBCLASSES",1489))(1, v2class) /*  CLASS-DIRECT-SUBCLASSES */;
   v4c = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v3))) FEtype_error_list(v3);
   v5 = v3;
   {
    cl_object v6;
    cl_object v7;
    v6 = ecl_list1(ECL_NIL);
    v7 = v6;
L9:;
    if (!(ecl_endp(v5))) { goto L11; }
    goto L10;
L11:;
    v4c = _ecl_car(v5);
    {
     cl_object v8;
     v8 = _ecl_cdr(v5);
     if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
     v5 = v8;
    }
    {
     cl_object v8;
     v8 = L21find_subclasses_of_type(v1type, v4c);
     if (ecl_unlikely(ECL_ATOM(v7))) FEtype_error_cons(v7);
     T0 = v7;
     (ECL_CONS_CDR(T0)=v8,T0);
     if (Null(v8)) { goto L19; }
    }
    T0 = ecl_cdr(v7);
    v7 = ecl_last(T0,1);
L19:;
    goto L9;
L10:;
    value0 = ecl_cdr(v6);
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for MAKE-CONDITION                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L22make_condition(cl_narg narg, cl_object v1type, ...)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2slot_initializations;
  ecl_va_list args; ecl_va_start(args,v1type,narg,1);
  v2slot_initializations = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v3class;
   if (!(ECL_SYMBOLP(v1type))) { goto L6; }
   value0 = cl_find_class(2, v1type, ECL_NIL);
   goto L4;
L6:;
   value0 = ECL_NIL;
   goto L4;
L4:;
   if ((value0)!=ECL_NIL) { goto L3; }
   T0 = cl_find_class(1, ECL_SYM("CONDITION",248));
   T1 = L21find_subclasses_of_type(v1type, T0);
   T2 = (ECL_SYM("SUBCLASSP",1178)->symbol.gfdef);
   T3 = cl_sort(2, T1, T2);
   T4 = ecl_last(T3,1);
   v3class = ecl_car(T4);
   goto L1;
L3:;
   v3class = value0;
   goto L1;
L1:;
   if ((v3class)!=ECL_NIL) { goto L9; }
   T0 = ecl_list1(v1type);
   cl_error(9, ECL_SYM("SIMPLE-TYPE-ERROR",773), ECL_SYM("DATUM",1214), v1type, ECL_SYM("EXPECTED-TYPE",1232), ECL_SYM("CONDITION",248), ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_8, ECL_SYM("FORMAT-ARGUMENTS",1239), T0);
L9:;
   T0 = (ECL_SYM("MAKE-INSTANCE",949)->symbol.gfdef);
   value0 = cl_apply(3, T0, v3class, v2slot_initializations);
   return value0;
  }
 }
}
/*	local function HANDLER-BIND                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC24handler_bind(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4bindings;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4bindings = v5;
   }
   {cl_object v5;
    v5 = ECL_NIL;
    v5 = ecl_make_cfun((cl_objectfn_fixed)LC23__g146,ECL_NIL,Cblock,1);
    T0 = v5;
   }
   if ((cl_every(2, T0, v4bindings))!=ECL_NIL) { goto L8; }
   cl_error(1, _ecl_static_9);
L8:;
   {
    cl_object v5;
    cl_object v6;
    v5 = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v4bindings))) FEtype_error_list(v4bindings);
    v6 = v4bindings;
    {
     cl_object v7;
     cl_object v8;
     v7 = ecl_list1(ECL_NIL);
     v8 = v7;
L17:;
     if (!(ecl_endp(v6))) { goto L19; }
     goto L18;
L19:;
     v5 = _ecl_car(v6);
     {
      cl_object v9;
      v9 = _ecl_cdr(v6);
      if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
      v6 = v9;
     }
     if (ecl_unlikely(ECL_ATOM(v8))) FEtype_error_cons(v8);
     T1 = v8;
     T3 = ecl_car(v5);
     T4 = cl_list(2, ECL_SYM("QUOTE",679), T3);
     T5 = ecl_cadr(v5);
     T2 = cl_list(3, ECL_SYM("CONS",251), T4, T5);
     v8 = ecl_list1(T2);
     (ECL_CONS_CDR(T1)=v8,T1);
     goto L17;
L18:;
     T0 = ecl_cdr(v7);
     goto L11;
    }
   }
L11:;
   T1 = CONS(ECL_SYM("LIST",481),T0);
   T2 = cl_list(3, ECL_SYM("CONS",251), T1, ECL_SYM("*HANDLER-CLUSTERS*",5));
   T3 = cl_list(2, ECL_SYM("*HANDLER-CLUSTERS*",5), T2);
   T4 = ecl_list1(T3);
   value0 = cl_listX(3, ECL_SYM("LET",477), T4, v3);
   return value0;
  }
 }
}
/*	local function G146                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC23__g146(cl_object v1x)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_LISTP(v1x))) { goto L2; }
  {
   cl_fixnum v2;
   v2 = ecl_length(v1x);
   value0 = ecl_make_bool((v2)==(2));
   cl_env_copy->nvalues = 1;
   return value0;
  }
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for SIGNAL                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L25signal(cl_narg narg, cl_object v1datum, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2arguments;
  ecl_va_list args; ecl_va_start(args,v1datum,narg,1);
  v2arguments = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v3condition;
   v3condition = L26coerce_to_condition(v1datum, v2arguments, ECL_SYM("SIMPLE-CONDITION",767), ECL_SYM("SIGNAL",760));
   ecl_bds_push(cl_env_copy,ECL_SYM("*HANDLER-CLUSTERS*",5)); /*  *HANDLER-CLUSTERS* */
   if (Null(cl_typep(2, v3condition, ecl_symbol_value(ECL_SYM("*BREAK-ON-SIGNALS*",25))))) { goto L2; }
   L29break(2, _ecl_static_10, v3condition);
L2:;
L5:;
   if ((ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5)))!=ECL_NIL) { goto L7; }
   goto L4;
L7:;
   {
    cl_object v4cluster;
    {
     cl_object v5;
     v5 = ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5));
     if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
     if (Null(v5)) { goto L13; }
     {
      cl_object v6;
      v6 = ECL_CONS_CDR(v5);
      cl_set(ECL_SYM("*HANDLER-CLUSTERS*",5),v6);
      v5 = ECL_CONS_CAR(v5);
     }
L13:;
     v4cluster = v5;
    }
    {
     cl_object v5;
     v5 = v4cluster;
     goto L22;
L21:;
     {
      cl_object v6handler;
      v6handler = ecl_car(v5);
      T0 = ecl_car(v6handler);
      if (Null(cl_typep(2, v3condition, T0))) { goto L26; }
      T0 = ecl_cdr(v6handler);
      ecl_function_dispatch(cl_env_copy,T0)(1, v3condition);
L26:;
     }
     v5 = ecl_cdr(v5);
L22:;
     if (Null(v5)) { goto L31; }
     goto L21;
L31:;
    }
   }
   goto L5;
L4:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
 }
}
/*	function definition for COERCE-TO-CONDITION                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L26coerce_to_condition(cl_object v1datum, cl_object v2arguments, cl_object v3default_type, cl_object v4function_name)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(si_of_class_p(2, v1datum, ECL_SYM("CONDITION",248)))) { goto L1; }
  if (Null(v2arguments)) { goto L3; }
  T0 = cl_list(2, v1datum, v4function_name);
  cl_cerror(10, _ecl_static_11, ECL_SYM("SIMPLE-TYPE-ERROR",773), ECL_SYM("DATUM",1214), v2arguments, ECL_SYM("EXPECTED-TYPE",1232), ECL_SYM("NULL",605), ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_12, ECL_SYM("FORMAT-ARGUMENTS",1239), T0);
L3:;
  value0 = v1datum;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (!(ECL_SYMBOLP(v1datum))) { goto L5; }
  T0 = (VV[32]->symbol.gfdef);
  value0 = cl_apply(3, T0, v1datum, v2arguments);
  return value0;
L5:;
  if (ECL_STRINGP(v1datum)) { goto L10; }
  if (Null(cl_functionp(v1datum))) { goto L8; }
  goto L9;
L10:;
L9:;
  value0 = L22make_condition(5, v3default_type, ECL_SYM("FORMAT-CONTROL",1240), v1datum, ECL_SYM("FORMAT-ARGUMENTS",1239), v2arguments);
  return value0;
L8:;
  T0 = cl_list(2, v4function_name, v1datum);
  value0 = cl_error(9, ECL_SYM("SIMPLE-TYPE-ERROR",773), ECL_SYM("DATUM",1214), v1datum, ECL_SYM("EXPECTED-TYPE",1232), VV[35], ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_13, ECL_SYM("FORMAT-ARGUMENTS",1239), T0);
  return value0;
 }
}
/*	function definition for BREAK                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L29break(volatile cl_narg narg, ...)
{
 cl_object T0, T1, T2, T3, T4;
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  volatile cl_object v1format_control;
  volatile cl_object v2format_arguments;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  {
   int i = 0;
   if (i >= narg) {
    v1format_control = _ecl_static_14;
   } else {
    i++;
    v1format_control = ecl_va_arg(args);
   }
  }
  v2format_arguments = cl_grab_rest_args(args);
  ecl_va_end(args);
  ecl_bds_bind(cl_env_copy,ECL_SYM("*DEBUGGER-HOOK*",31),ECL_NIL); /*  *DEBUGGER-HOOK* */
  {
   volatile cl_object env1 = env0;
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(ECL_NIL,env1);
   {
    volatile cl_object env2 = env1;
    CLV1 = env2 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env2); /*  TAGBODY */
    if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV1))) {
    if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L3;
    ecl_internal_error("GO found an inexistent tag");
    }
    {cl_object v3;
     v3 = ECL_NIL;
     v3 = ecl_make_cclosure_va((cl_objectfn)LC27__g164,env2,Cblock);
     T0 = v3;
    }
    {cl_object v3;
     v3 = ECL_NIL;
     v3 = ecl_make_cfun((cl_objectfn_fixed)LC28__g165,ECL_NIL,Cblock,1);
     T1 = v3;
    }
    T2 = L4make_restart(6, ECL_SYM("NAME",1273), ECL_SYM("CONTINUE",250), ECL_SYM("FUNCTION",1241), T0, VV[15], T1);
    T3 = ecl_list1(T2);
    T4 = CONS(T3,ecl_symbol_value(ECL_SYM("*RESTART-CLUSTERS*",4)));
    ecl_bds_bind(cl_env_copy,ECL_SYM("*RESTART-CLUSTERS*",4),T4); /*  *RESTART-CLUSTERS* */
    T0 = L22make_condition(5, ECL_SYM("SIMPLE-CONDITION",767), ECL_SYM("FORMAT-CONTROL",1240), v1format_control, ECL_SYM("FORMAT-ARGUMENTS",1239), v2format_arguments);
    (cl_env_copy->function=(ECL_SYM("INVOKE-DEBUGGER",445)->symbol.gfdef))->cfun.entry(1, T0) /*  INVOKE-DEBUGGER */;
    ecl_frs_pop(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    goto L2;
L3:;
    ecl_frs_pop(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    goto L2;
   }
  }
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	closure G164                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC27__g164(cl_narg narg, ...)
{
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  TAGBODY         */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 {
  cl_object v1temp;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1temp = cl_grab_rest_args(args);
  ecl_va_end(args);
  ECL_CONS_CAR(CLV0) = v1temp;
  cl_go(ECL_CONS_CAR(CLV1),ecl_make_fixnum(0));
 }
 }
}
/*	local function G165                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC28__g165(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_format(2, v1stream, _ecl_static_15);
  return value0;
 }
}
/*	function definition for WARN                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L32warn(volatile cl_narg narg, cl_object volatile v1datum, ...)
{
 cl_object T0, T1, T2, T3, T4;
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  volatile cl_object v2arguments;
  ecl_va_list args; ecl_va_start(args,v1datum,narg,1);
  v2arguments = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   volatile cl_object v3condition;
   v3condition = L26coerce_to_condition(v1datum, v2arguments, ECL_SYM("SIMPLE-WARNING",776), ECL_SYM("WARN",903));
   {
    cl_object v4;
    v4 = v3condition;
    if ((si_of_class_p(2, v4, ECL_SYM("WARNING",904)))!=ECL_NIL) { goto L4; }
    v3condition = si_do_check_type(v4, ECL_SYM("WARNING",904), _ecl_static_16, ECL_SYM("CONDITION",248));
L4:;
   }
   {
    volatile cl_object env1 = env0;
    env1 = ECL_NIL;
    CLV0 = env1 = CONS(ECL_NIL,env1);
    {
     volatile cl_object env2 = env1;
     CLV1 = env2 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env2); /*  TAGBODY */
     if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV1))) {
     if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L8;
     ecl_internal_error("GO found an inexistent tag");
     }
     {cl_object v4;
      v4 = ECL_NIL;
      v4 = ecl_make_cclosure_va((cl_objectfn)LC30__g173,env2,Cblock);
      T0 = v4;
     }
     {cl_object v4;
      v4 = ECL_NIL;
      v4 = ecl_make_cfun((cl_objectfn_fixed)LC31__g174,ECL_NIL,Cblock,1);
      T1 = v4;
     }
     T2 = L4make_restart(6, ECL_SYM("NAME",1273), ECL_SYM("MUFFLE-WARNING",571), ECL_SYM("FUNCTION",1241), T0, VV[15], T1);
     T3 = ecl_list1(T2);
     T4 = CONS(T3,ecl_symbol_value(ECL_SYM("*RESTART-CLUSTERS*",4)));
     ecl_bds_bind(cl_env_copy,ECL_SYM("*RESTART-CLUSTERS*",4),T4); /*  *RESTART-CLUSTERS* */
     T0 = ecl_car(ecl_symbol_value(ECL_SYM("*RESTART-CLUSTERS*",4)));
     T1 = CONS(v3condition,T0);
     T2 = CONS(T1,ecl_symbol_value(VV[1]));
     ecl_bds_bind(cl_env_copy,VV[1],T2);          /*  *CONDITION-RESTARTS* */
     L25signal(1, v3condition);
     ecl_frs_pop(cl_env_copy);
     ecl_bds_unwind1(cl_env_copy);
     ecl_bds_unwind1(cl_env_copy);
     goto L7;
L8:;
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 1;
     ecl_frs_pop(cl_env_copy);
     return value0;
    }
   }
L7:;
   cl_format(3, ecl_symbol_value(ECL_SYM("*ERROR-OUTPUT*",33)), _ecl_static_18, v3condition);
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	closure G173                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC30__g173(cl_narg narg, ...)
{
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  TAGBODY         */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 {
  cl_object v1temp;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1temp = cl_grab_rest_args(args);
  ecl_va_end(args);
  ECL_CONS_CAR(CLV0) = v1temp;
  cl_go(ECL_CONS_CAR(CLV1),ecl_make_fixnum(0));
 }
 }
}
/*	local function G174                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC31__g174(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_write_string(2, _ecl_static_17, v1stream);
  return value0;
 }
}
/*	local function G176                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC34__g176()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {cl_object v1;
   v1 = ECL_NIL;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC33__g177,ECL_NIL,Cblock,2);
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G177                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC33__g177(cl_object v1condition, cl_object v2stream)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = (cl_env_copy->function=(ECL_SYM("SIMPLE-CONDITION-FORMAT-CONTROL",768)->symbol.gfdef))->cfun.entry(1, v1condition) /*  SIMPLE-CONDITION-FORMAT-CONTROL */;
  T1 = (cl_env_copy->function=(ECL_SYM("SIMPLE-CONDITION-FORMAT-ARGUMENTS",769)->symbol.gfdef))->cfun.entry(1, v1condition) /*  SIMPLE-CONDITION-FORMAT-ARGUMENTS */;
  value0 = cl_format(4, v2stream, _ecl_static_19, T0, T1);
  return value0;
 }
}
/*	local function G178                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC36__g178()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {cl_object v1;
   v1 = ECL_NIL;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC35__g179,ECL_NIL,Cblock,2);
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G179                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC35__g179(cl_object v1condition, cl_object v2stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3type;
   cl_object v4size;
   v3type = ecl_function_dispatch(cl_env_copy,ECL_SYM("STACK-OVERFLOW-TYPE",1667))(1, v1condition) /*  STACK-OVERFLOW-TYPE */;
   v4size = ecl_function_dispatch(cl_env_copy,ECL_SYM("STACK-OVERFLOW-SIZE",1666))(1, v1condition) /*  STACK-OVERFLOW-SIZE */;
   if (Null(v4size)) { goto L3; }
   value0 = cl_format(4, v2stream, _ecl_static_20, v3type, v4size);
   return value0;
L3:;
   value0 = cl_format(3, v2stream, _ecl_static_21, v3type);
   return value0;
  }
 }
}
/*	local function G180                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC38__g180()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {cl_object v1;
   v1 = ECL_NIL;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC37__g181,ECL_NIL,Cblock,2);
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G181                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC37__g181(cl_object v1condition, cl_object v2stream)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("UNIX-SIGNAL-RECEIVED-CODE",1801))(1, v1condition) /*  UNIX-SIGNAL-RECEIVED-CODE */;
  value0 = cl_format(3, v2stream, _ecl_static_22, T0);
  return value0;
 }
}
/*	local function G182                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC40__g182()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {cl_object v1;
   v1 = ECL_NIL;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC39__g183,ECL_NIL,Cblock,2);
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G183                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC39__g183(cl_object v1condition, cl_object v2stream)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = (cl_env_copy->function=(ECL_SYM("TYPE-ERROR-DATUM",871)->symbol.gfdef))->cfun.entry(1, v1condition) /*  TYPE-ERROR-DATUM */;
  T1 = (cl_env_copy->function=(ECL_SYM("TYPE-ERROR-EXPECTED-TYPE",872)->symbol.gfdef))->cfun.entry(1, v1condition) /*  TYPE-ERROR-EXPECTED-TYPE */;
  value0 = cl_format(4, v2stream, _ecl_static_23, T0, T1);
  return value0;
 }
}
/*	local function G184                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC42__g184()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {cl_object v1;
   v1 = ECL_NIL;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC41__g185,ECL_NIL,Cblock,2);
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G185                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC41__g185(cl_object v1condition, cl_object v2stream)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = (cl_env_copy->function=(ECL_SYM("TYPE-ERROR-DATUM",871)->symbol.gfdef))->cfun.entry(1, v1condition) /*  TYPE-ERROR-DATUM */;
  T1 = ecl_function_dispatch(cl_env_copy,VV[84])(1, v1condition) /*  CASE-FAILURE-NAME */;
  T2 = ecl_function_dispatch(cl_env_copy,VV[85])(1, v1condition) /*  CASE-FAILURE-POSSIBILITIES */;
  value0 = cl_format(5, v2stream, _ecl_static_24, T0, T1, T2);
  return value0;
 }
}
/*	local function G186                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC44__g186()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {cl_object v1;
   v1 = ECL_NIL;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC43__g187,ECL_NIL,Cblock,2);
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G187                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC43__g187(cl_object v1condition, cl_object v2stream)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = (cl_env_copy->function=(ECL_SYM("STREAM-ERROR-STREAM",802)->symbol.gfdef))->cfun.entry(1, v1condition) /*  STREAM-ERROR-STREAM */;
  value0 = cl_format(3, v2stream, _ecl_static_25, T0);
  return value0;
 }
}
/*	local function G188                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC46__g188()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {cl_object v1;
   v1 = ECL_NIL;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC45__g189,ECL_NIL,Cblock,2);
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G189                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC45__g189(cl_object v1condition, cl_object v2stream)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = (cl_env_copy->function=(ECL_SYM("FILE-ERROR-PATHNAME",354)->symbol.gfdef))->cfun.entry(1, v1condition) /*  FILE-ERROR-PATHNAME */;
  value0 = cl_format(3, v2stream, _ecl_static_26, T0);
  return value0;
 }
}
/*	local function G190                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC48__g190()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {cl_object v1;
   v1 = ECL_NIL;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC47__g191,ECL_NIL,Cblock,2);
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G191                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC47__g191(cl_object v1condition, cl_object v2stream)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = (cl_env_copy->function=(ECL_SYM("CELL-ERROR-NAME",201)->symbol.gfdef))->cfun.entry(1, v1condition) /*  CELL-ERROR-NAME */;
  value0 = cl_format(3, v2stream, _ecl_static_27, T0);
  return value0;
 }
}
/*	local function G192                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC50__g192()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {cl_object v1;
   v1 = ECL_NIL;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC49__g193,ECL_NIL,Cblock,2);
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G193                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC49__g193(cl_object v1condition, cl_object v2stream)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = (cl_env_copy->function=(ECL_SYM("CELL-ERROR-NAME",201)->symbol.gfdef))->cfun.entry(1, v1condition) /*  CELL-ERROR-NAME */;
  T1 = (cl_env_copy->function=(ECL_SYM("UNBOUND-SLOT-INSTANCE",877)->symbol.gfdef))->cfun.entry(1, v1condition) /*  UNBOUND-SLOT-INSTANCE */;
  value0 = cl_format(4, v2stream, _ecl_static_28, T0, T1);
  return value0;
 }
}
/*	local function G194                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC52__g194()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {cl_object v1;
   v1 = ECL_NIL;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC51__g195,ECL_NIL,Cblock,2);
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G195                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC51__g195(cl_object v1condition, cl_object v2stream)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = (cl_env_copy->function=(ECL_SYM("CELL-ERROR-NAME",201)->symbol.gfdef))->cfun.entry(1, v1condition) /*  CELL-ERROR-NAME */;
  value0 = cl_format(3, v2stream, _ecl_static_29, T0);
  return value0;
 }
}
/*	local function G196                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC54__g196()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {cl_object v1;
   v1 = ECL_NIL;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC53__g197,ECL_NIL,Cblock,2);
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G197                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC53__g197(cl_object v1condition, cl_object v2stream)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = (cl_env_copy->function=(ECL_SYM("PRINT-NOT-READABLE-OBJECT",664)->symbol.gfdef))->cfun.entry(1, v1condition) /*  PRINT-NOT-READABLE-OBJECT */;
  value0 = cl_format(3, v2stream, _ecl_static_30, T0);
  return value0;
 }
}
/*	local function G198                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC56__g198()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {cl_object v1;
   v1 = ECL_NIL;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC55__g199,ECL_NIL,Cblock,2);
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G200                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC57__g200()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_symbol_value(VV[42]);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G201                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC58__g201()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_symbol_value(VV[43]);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G199                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC55__g199(cl_object v1condition, cl_object v2stream)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[86])(1, v1condition) /*  FORMAT-ERROR-PRINT-BANNER */;
  T1 = (cl_env_copy->function=(ECL_SYM("SIMPLE-CONDITION-FORMAT-CONTROL",768)->symbol.gfdef))->cfun.entry(1, v1condition) /*  SIMPLE-CONDITION-FORMAT-CONTROL */;
  T2 = (cl_env_copy->function=(ECL_SYM("SIMPLE-CONDITION-FORMAT-ARGUMENTS",769)->symbol.gfdef))->cfun.entry(1, v1condition) /*  SIMPLE-CONDITION-FORMAT-ARGUMENTS */;
  T3 = ecl_function_dispatch(cl_env_copy,VV[87])(1, v1condition) /*  FORMAT-ERROR-CONTROL-STRING */;
  T4 = ecl_function_dispatch(cl_env_copy,VV[88])(1, v1condition) /*  FORMAT-ERROR-OFFSET */;
  value0 = cl_format(7, v2stream, _ecl_static_31, T0, T1, T2, T3, T4);
  return value0;
 }
}
/*	function definition for SIGNAL-SIMPLE-ERROR                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_signal_simple_error(cl_narg narg, cl_object v1base_condition, cl_object v2continue_message, cl_object v3format_control, cl_object v4format_args, ...)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<4)) FEwrong_num_arguments_anonym();
 {
  cl_object v5args;
  ecl_va_list args; ecl_va_start(args,v4format_args,narg,4);
  v5args = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v6simple_error_name;
   T0 = cl_string(v1base_condition);
   T1 = cl_concatenate(3, ECL_SYM("STRING",805), _ecl_static_32, T0);
   T2 = cl_find_package(_ecl_static_33);
   v6simple_error_name = cl_intern(2, T1, T2);
   if ((cl_find_class(2, v6simple_error_name, ECL_NIL))!=ECL_NIL) { goto L2; }
   T0 = cl_list(2, ECL_SYM("SIMPLE-ERROR",770), v1base_condition);
   T1 = cl_list(4, ECL_SYM("DEFCLASS",937), v6simple_error_name, T0, ECL_NIL);
   cl_eval(T1);
L2:;
   if (Null(v2continue_message)) { goto L4; }
   T0 = (ECL_SYM("CERROR",202)->symbol.gfdef);
   value0 = cl_apply(8, T0, v2continue_message, v6simple_error_name, ECL_SYM("FORMAT-CONTROL",1240), v3format_control, ECL_SYM("FORMAT-ARGUMENTS",1239), v4format_args, v5args);
   return value0;
L4:;
   T0 = (ECL_SYM("ERROR",337)->symbol.gfdef);
   value0 = cl_apply(7, T0, v6simple_error_name, ECL_SYM("FORMAT-CONTROL",1240), v3format_control, ECL_SYM("FORMAT-ARGUMENTS",1239), v4format_args, v5args);
   return value0;
  }
 }
}
/*	local function HANDLER-CASE                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC59handler_case(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4form;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4form = v5;
   }
   {
    cl_object v5no_error_clause;
    v5no_error_clause = ecl_assql(VV[44],v3);
    if (Null(v5no_error_clause)) { goto L9; }
    {
     cl_object v6normal_return;
     cl_object v7error_return;
     v6normal_return = cl_make_symbol(_ecl_static_34);
     v7error_return = cl_make_symbol(_ecl_static_35);
     T0 = ecl_cdr(v5no_error_clause);
     T1 = CONS(ECL_SYM("LAMBDA",452),T0);
     T2 = cl_list(2, ECL_SYM("FUNCTION",396), T1);
     T3 = cl_list(3, ECL_SYM("RETURN-FROM",725), v6normal_return, v4form);
     T4 = cl_remove(2, v5no_error_clause, v3);
     T5 = cl_listX(3, ECL_SYM("HANDLER-CASE",416), T3, T4);
     T6 = cl_list(3, ECL_SYM("RETURN-FROM",725), v7error_return, T5);
     T7 = cl_list(3, ECL_SYM("BLOCK",137), v6normal_return, T6);
     T8 = cl_list(3, ECL_SYM("MULTIPLE-VALUE-CALL",573), T2, T7);
     value0 = cl_list(3, ECL_SYM("BLOCK",137), v7error_return, T8);
     return value0;
    }
L9:;
    {
     cl_object v8tag;
     cl_object v9var;
     cl_object v10annotated_cases;
     v8tag = cl_gensym(0);
     v9var = cl_gensym(0);
     {
      cl_object v11;
      cl_object v12;
      v11 = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v3))) FEtype_error_list(v3);
      v12 = v3;
      {
       cl_object v13;
       cl_object v14;
       v13 = ecl_list1(ECL_NIL);
       v14 = v13;
L21:;
       if (!(ecl_endp(v12))) { goto L23; }
       goto L22;
L23:;
       v11 = _ecl_car(v12);
       {
        cl_object v15;
        v15 = _ecl_cdr(v12);
        if (ecl_unlikely(!ECL_LISTP(v15))) FEtype_error_list(v15);
        v12 = v15;
       }
       if (ecl_unlikely(ECL_ATOM(v14))) FEtype_error_cons(v14);
       T0 = v14;
       T2 = cl_gensym(0);
       T1 = CONS(T2,v11);
       v14 = ecl_list1(T1);
       (ECL_CONS_CDR(T0)=v14,T0);
       goto L21;
L22:;
       v10annotated_cases = ecl_cdr(v13);
       goto L15;
      }
     }
L15:;
     T0 = cl_list(2, v9var, ECL_NIL);
     T1 = ecl_list1(T0);
     T2 = cl_list(2, ECL_SYM("IGNORABLE",427), v9var);
     T3 = cl_list(2, ECL_SYM("DECLARE",274), T2);
     {
      cl_object v11;
      cl_object v12;
      v11 = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v10annotated_cases))) FEtype_error_list(v10annotated_cases);
      v12 = v10annotated_cases;
      {
       cl_object v13;
       cl_object v14;
       v13 = ecl_list1(ECL_NIL);
       v14 = v13;
L44:;
       if (!(ecl_endp(v12))) { goto L46; }
       goto L45;
L46:;
       v11 = _ecl_car(v12);
       {
        cl_object v15;
        v15 = _ecl_cdr(v12);
        if (ecl_unlikely(!ECL_LISTP(v15))) FEtype_error_list(v15);
        v12 = v15;
       }
       if (ecl_unlikely(ECL_ATOM(v14))) FEtype_error_cons(v14);
       T5 = v14;
       T7 = ecl_cadr(v11);
       if (Null(ecl_caddr(v11))) { goto L60; }
       T9 = cl_list(3, ECL_SYM("SETQ",751), v9var, VV[23]);
       T8 = ecl_list1(T9);
       goto L59;
L60:;
       T8 = ECL_NIL;
L59:;
       T9 = ecl_car(v11);
       T10 = cl_list(2, ECL_SYM("GO",414), T9);
       T11 = ecl_list1(T10);
       T12 = ecl_append(T8,T11);
       T13 = cl_listX(4, ECL_SYM("LAMBDA",452), VV[45], VV[46], T12);
       T14 = cl_list(2, ECL_SYM("FUNCTION",396), T13);
       T6 = cl_list(2, T7, T14);
       v14 = ecl_list1(T6);
       (ECL_CONS_CDR(T5)=v14,T5);
       goto L44;
L45:;
       T4 = ecl_cdr(v13);
       goto L38;
      }
     }
L38:;
     T5 = cl_list(3, ECL_SYM("RETURN-FROM",725), v8tag, v4form);
     T6 = cl_list(3, VV[33], T4, T5);
     {
      cl_object v11;
      cl_object v12;
      v11 = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v10annotated_cases))) FEtype_error_list(v10annotated_cases);
      v12 = v10annotated_cases;
      {
       cl_object v13;
       cl_object v14;
       v13 = ecl_list1(ECL_NIL);
       v14 = v13;
L70:;
       if (!(ecl_endp(v12))) { goto L72; }
       goto L71;
L72:;
       v11 = _ecl_car(v12);
       {
        cl_object v15;
        v15 = _ecl_cdr(v12);
        if (ecl_unlikely(!ECL_LISTP(v15))) FEtype_error_list(v15);
        v12 = v15;
       }
       {
        cl_object v15;
        T8 = ecl_car(v11);
        {
         cl_object v16body;
         v16body = ecl_cdddr(v11);
         if (Null(ecl_caddr(v11))) { goto L86; }
         T11 = ecl_caaddr(v11);
         T12 = cl_list(2, T11, v9var);
         T13 = ecl_list1(T12);
         T10 = cl_listX(3, ECL_SYM("LET",477), T13, v16body);
         goto L85;
L86:;
         T10 = CONS(ECL_SYM("LOCALLY",490),v16body);
L85:;
         T9 = cl_list(3, ECL_SYM("RETURN-FROM",725), v8tag, T10);
        }
        v15 = cl_list(2, T8, T9);
        if (ecl_unlikely(ECL_ATOM(v14))) FEtype_error_cons(v14);
        T8 = v14;
        (ECL_CONS_CDR(T8)=v15,T8);
        if (Null(v15)) { goto L80; }
       }
       T8 = ecl_cdr(v14);
       v14 = ecl_last(T8,1);
L80:;
       goto L70;
L71:;
       T7 = ecl_cdr(v13);
       goto L64;
      }
     }
L64:;
     T8 = cl_listX(3, ECL_SYM("TAGBODY",850), T6, T7);
     T9 = cl_list(4, ECL_SYM("LET",477), T1, T3, T8);
     value0 = cl_list(3, ECL_SYM("BLOCK",137), v8tag, T9);
     return value0;
    }
   }
  }
 }
}
/*	local function IGNORE-ERRORS                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC60ignore_errors(cl_object v1, cl_object v2)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_cdr(v1);
   T0 = CONS(ECL_SYM("PROGN",671),v3);
   value0 = cl_list(3, VV[47], T0, VV[48]);
   return value0;
  }
 }
}
/*	function definition for ABORT                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_abort(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1c;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1c = ECL_NIL;
   } else {
    i++;
    v1c = va_arg(args,cl_object);
   }
  }
  va_end(args);
  T0 = L12find_restart_never_fail(2, ECL_SYM("ABORT",77), v1c);
  L13invoke_restart(1, T0);
  value0 = cl_error(1, VV[41]);
  return value0;
 }
}
/*	function definition for CONTINUE                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_continue(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1c;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1c = ECL_NIL;
   } else {
    i++;
    v1c = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v2restart;
   v2restart = L11find_restart(2, ECL_SYM("CONTINUE",250), v1c);
   if (Null(v2restart)) { goto L4; }
   value0 = L13invoke_restart(1, v2restart);
   return value0;
L4:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for MUFFLE-WARNING                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_muffle_warning(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1c;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1c = ECL_NIL;
   } else {
    i++;
    v1c = va_arg(args,cl_object);
   }
  }
  va_end(args);
  T0 = L12find_restart_never_fail(2, ECL_SYM("MUFFLE-WARNING",571), v1c);
  value0 = L13invoke_restart(1, T0);
  return value0;
 }
}
/*	function definition for STORE-VALUE                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_store_value(cl_narg narg, cl_object v1value, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2c;
  va_list args; va_start(args,v1value);
  {
   int i = 1;
   if (i >= narg) {
    v2c = ECL_NIL;
   } else {
    i++;
    v2c = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v3restart;
   v3restart = L11find_restart(2, ECL_SYM("STORE-VALUE",798), v2c);
   if (Null(v3restart)) { goto L4; }
   value0 = L13invoke_restart(2, v3restart, v1value);
   return value0;
L4:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for USE-VALUE                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_use_value(cl_narg narg, cl_object v1value, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2c;
  va_list args; va_start(args,v1value);
  {
   int i = 1;
   if (i >= narg) {
    v2c = ECL_NIL;
   } else {
    i++;
    v2c = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v3restart;
   v3restart = L11find_restart(2, ECL_SYM("USE-VALUE",893), v2c);
   if (Null(v3restart)) { goto L4; }
   value0 = L13invoke_restart(2, v3restart, v1value);
   return value0;
L4:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for ASSERT-REPORT                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L61assert_report(cl_object v1names, cl_object v2stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  cl_format(2, v2stream, _ecl_static_36);
  if (Null(v1names)) { goto L2; }
  {
   cl_fixnum v3;
   v3 = ecl_length(v1names);
   value0 = cl_format(4, v2stream, _ecl_static_37, ecl_make_fixnum(v3), v1names);
   return value0;
  }
L2:;
  value0 = cl_format(2, v2stream, _ecl_static_38);
  return value0;
 }
}
/*	function definition for ASSERT-PROMPT                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L63assert_prompt(cl_object v1name, cl_object v2value)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_y_or_n_p(3, _ecl_static_39, v1name, v2value))) { goto L1; }
  cl_format(2, ecl_symbol_value(ECL_SYM("*QUERY-IO*",59)), _ecl_static_40);
  if (!(ECL_SYMBOLP(v1name))) { goto L4; }
  {
   cl_object v4, v5; cl_index v3;
   v4 = ecl_list1(v1name);
   v5 = ecl_list1(v2value);
   v3 = ecl_progv(cl_env_copy, v4, v5);
   value0 = LC62read_it();
   ecl_bds_unwind(cl_env_copy,v3);
   return value0;
  }
L4:;
  value0 = LC62read_it();
  return value0;
L1:;
  value0 = v2value;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function READ-IT                                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC62read_it()
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_read(1, ecl_symbol_value(ECL_SYM("*QUERY-IO*",59)));
  value0 = cl_eval(T0);
  return value0;
 }
}
/*	function definition for ASSERT-FAILURE                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_assert_failure(volatile cl_narg narg, cl_object volatile v1test_form, ...)
{
 cl_object T0, T1, T2, T3, T4;
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1, CLV2
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  volatile cl_object v2values;
  volatile cl_object v3arguments;
  ecl_va_list args; ecl_va_start(args,v1test_form,narg,1);
  {
   int i = 1;
   if (i >= narg) {
    env0 = ECL_NIL;
    CLV0 = env0 = CONS(ECL_NIL,env0);             /*  PLACE-NAMES     */
   } else {
    i++;
    env0 = ECL_NIL;
    CLV0 = env0 = CONS(ecl_va_arg(args),env0);    /*  PLACE-NAMES     */
   }
   if (i >= narg) {
    v2values = ECL_NIL;
   } else {
    i++;
    v2values = ecl_va_arg(args);
   }
  }
  v3arguments = cl_grab_rest_args(args);
  ecl_va_end(args);
  if ((v3arguments)!=ECL_NIL) { goto L2; }
  T0 = ecl_list1(v1test_form);
  v3arguments = cl_list(9, ECL_SYM("SIMPLE-TYPE-ERROR",773), ECL_SYM("DATUM",1214), v1test_form, ECL_SYM("EXPECTED-TYPE",1232), ECL_NIL, ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_41, ECL_SYM("FORMAT-ARGUMENTS",1239), T0);
L2:;
  {
   volatile cl_object env1 = env0;
   CLV1 = env1 = CONS(ECL_NIL,env1);
   CLV2 = env1 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env1); /*  TAGBODY */
   if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV2))) {
   if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L5;
   ecl_internal_error("GO found an inexistent tag");
   }
   {cl_object v4;
    v4 = ECL_NIL;
    v4 = ecl_make_cclosure_va((cl_objectfn)LC64__g243,env1,Cblock);
    T0 = v4;
   }
   {cl_object v4;
    v4 = ECL_NIL;
    v4 = ecl_make_cclosure_va((cl_objectfn)LC65__g244,env1,Cblock);
    T1 = v4;
   }
   T2 = L4make_restart(6, ECL_SYM("NAME",1273), ECL_SYM("CONTINUE",250), ECL_SYM("FUNCTION",1241), T0, VV[15], T1);
   T3 = ecl_list1(T2);
   T4 = CONS(T3,ecl_symbol_value(ECL_SYM("*RESTART-CLUSTERS*",4)));
   ecl_bds_bind(cl_env_copy,ECL_SYM("*RESTART-CLUSTERS*",4),T4); /*  *RESTART-CLUSTERS* */
   {
    cl_object v4;
    T0 = ecl_car(v3arguments);
    T1 = ecl_cdr(v3arguments);
    T2 = L26coerce_to_condition(T0, T1, ECL_SYM("SIMPLE-ERROR",770), ECL_SYM("ASSERT",113));
    T3 = ECL_NIL;
    v4 = L26coerce_to_condition(T2, T3, ECL_SYM("SIMPLE-ERROR",770), ECL_SYM("ERROR",337));
    T0 = ecl_car(ecl_symbol_value(ECL_SYM("*RESTART-CLUSTERS*",4)));
    T1 = CONS(v4,T0);
    T2 = CONS(T1,ecl_symbol_value(VV[1]));
    ecl_bds_bind(cl_env_copy,VV[1],T2);           /*  *CONDITION-RESTARTS* */
    value0 = cl_error(1, v4);
    ecl_frs_pop(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    return value0;
   }
L5:;
   {
    cl_object v4place_name;
    cl_object v5;
    v4place_name = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(ECL_CONS_CAR(CLV0)))) FEtype_error_list(ECL_CONS_CAR(CLV0));
    v5 = ECL_CONS_CAR(CLV0);
    {
     cl_object v6value;
     cl_object v7;
     v6value = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v2values))) FEtype_error_list(v2values);
     v7 = v2values;
     {
      cl_object v8;
      cl_object v9;
      v8 = ecl_list1(ECL_NIL);
      v9 = v8;
L20:;
      if (!(ecl_endp(v5))) { goto L22; }
      goto L21;
L22:;
      v4place_name = _ecl_car(v5);
      {
       cl_object v10;
       v10 = _ecl_cdr(v5);
       if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
       v5 = v10;
      }
      if (!(ecl_endp(v7))) { goto L30; }
      goto L21;
L30:;
      v6value = _ecl_car(v7);
      {
       cl_object v10;
       v10 = _ecl_cdr(v7);
       if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
       v7 = v10;
      }
      if (ecl_unlikely(ECL_ATOM(v9))) FEtype_error_cons(v9);
      T1 = v9;
      T2 = L63assert_prompt(v4place_name, v6value);
      v9 = ecl_list1(T2);
      (ECL_CONS_CDR(T1)=v9,T1);
      goto L20;
L21:;
      T0 = ecl_cdr(v8);
      goto L11;
     }
    }
   }
L11:;
   value0 = cl_values_list(T0);
   ecl_frs_pop(cl_env_copy);
   return value0;
  }
 }
}
/*	closure G243                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC64__g243(cl_narg narg, ...)
{
 cl_object CLV0, CLV1, CLV2
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV2 = env0;                                     /*  TAGBODY         */
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 {
  cl_object v1temp;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1temp = cl_grab_rest_args(args);
  ecl_va_end(args);
  ECL_CONS_CAR(CLV1) = v1temp;
  cl_go(ECL_CONS_CAR(CLV2),ecl_make_fixnum(0));
 }
 }
}
/*	closure G244                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC65__g244(cl_narg narg, cl_object v1stream, ...)
{
 cl_object CLV0, CLV1, CLV2
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV2 = env0;
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);                           /*  PLACE-NAMES     */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = L61assert_report(ECL_CONS_CAR(CLV0), v1stream);
  return value0;
 }
 }
}
/*	function definition for UNIVERSAL-ERROR-HANDLER               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L76universal_error_handler(cl_object volatile v1continue_string, cl_object volatile v2datum, cl_object volatile v3args)
{
 cl_object T0, T1, T2, T3, T4;
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1, CLV2, CLV3, CLV4, CLV5, CLV6, CLV7
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1continue_string,env0);     /*  CONTINUE-STRING */
  CLV1 = env0 = CONS(v3args,env0);                /*  ARGS            */
  {
   volatile cl_object v4condition;
   v4condition = L26coerce_to_condition(v2datum, ECL_CONS_CAR(CLV1), ECL_SYM("SIMPLE-ERROR",770), ECL_SYM("ERROR",337));
   if (!((ECL_T)==(ECL_CONS_CAR(CLV0)))) { goto L2; }
   {
    volatile cl_object env1 = env0;
    CLV2 = env1 = CONS(ECL_NIL,env1);
    {
     volatile cl_object env2 = env1;
     CLV3 = env2 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env2); /*  TAGBODY */
     if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV3))) {
     if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L4;
     ecl_internal_error("GO found an inexistent tag");
     }
     {cl_object v5;
      v5 = ECL_NIL;
      v5 = ecl_make_cclosure_va((cl_objectfn)LC66__g258,env2,Cblock);
      T0 = v5;
     }
     {cl_object v5;
      v5 = ECL_NIL;
      v5 = ecl_make_cfun((cl_objectfn_fixed)LC67__g259,ECL_NIL,Cblock,1);
      T1 = v5;
     }
     T2 = L4make_restart(6, ECL_SYM("NAME",1273), ECL_SYM("IGNORE",428), ECL_SYM("FUNCTION",1241), T0, VV[15], T1);
     T3 = ecl_list1(T2);
     T4 = CONS(T3,ecl_symbol_value(ECL_SYM("*RESTART-CLUSTERS*",4)));
     ecl_bds_bind(cl_env_copy,ECL_SYM("*RESTART-CLUSTERS*",4),T4); /*  *RESTART-CLUSTERS* */
     L25signal(1, v4condition);
     value0 = (cl_env_copy->function=(ECL_SYM("INVOKE-DEBUGGER",445)->symbol.gfdef))->cfun.entry(1, v4condition) /*  INVOKE-DEBUGGER */;
     ecl_frs_pop(cl_env_copy);
     ecl_bds_unwind1(cl_env_copy);
     return value0;
L4:;
     cl_env_copy->nvalues = 2;
     cl_env_copy->values[1] = ECL_T;
     cl_env_copy->values[0] = ECL_NIL;
     value0 = cl_env_copy->values[0];
     ecl_frs_pop(cl_env_copy);
     return value0;
    }
   }
L2:;
   if (!(ECL_STRINGP(ECL_CONS_CAR(CLV0)))) { goto L10; }
   {
    volatile cl_object env1 = env0;
    CLV2 = env1 = CONS(ECL_NIL,env1);
    {
     volatile cl_object env2 = env1;
     CLV3 = env2 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env2); /*  TAGBODY */
     if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV3))) {
     if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L12;
     ecl_internal_error("GO found an inexistent tag");
     }
     {cl_object v5;
      v5 = ECL_NIL;
      v5 = ecl_make_cclosure_va((cl_objectfn)LC68__g265,env2,Cblock);
      T0 = v5;
     }
     {cl_object v5;
      v5 = ECL_NIL;
      v5 = ecl_make_cclosure_va((cl_objectfn)LC69__g266,env2,Cblock);
      T1 = v5;
     }
     T2 = L4make_restart(6, ECL_SYM("NAME",1273), ECL_SYM("CONTINUE",250), ECL_SYM("FUNCTION",1241), T0, VV[15], T1);
     T3 = ecl_list1(T2);
     T4 = CONS(T3,ecl_symbol_value(ECL_SYM("*RESTART-CLUSTERS*",4)));
     ecl_bds_bind(cl_env_copy,ECL_SYM("*RESTART-CLUSTERS*",4),T4); /*  *RESTART-CLUSTERS* */
     L25signal(1, v4condition);
     value0 = (cl_env_copy->function=(ECL_SYM("INVOKE-DEBUGGER",445)->symbol.gfdef))->cfun.entry(1, v4condition) /*  INVOKE-DEBUGGER */;
     ecl_frs_pop(cl_env_copy);
     ecl_bds_unwind1(cl_env_copy);
     return value0;
L12:;
     cl_env_copy->nvalues = 2;
     cl_env_copy->values[1] = ECL_T;
     cl_env_copy->values[0] = ECL_NIL;
     value0 = cl_env_copy->values[0];
     ecl_frs_pop(cl_env_copy);
     return value0;
    }
   }
L10:;
   if (Null(ECL_CONS_CAR(CLV0))) { goto L18; }
   if (!(ECL_SYMBOLP(ECL_CONS_CAR(CLV0)))) { goto L18; }
   {
    volatile cl_object env1 = env0;
    CLV2 = env1 = CONS(ECL_NIL,env1);
    {
     volatile cl_object env2 = env1;
     CLV3 = env2 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env2); /*  TAGBODY */
     if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV3))) {
     if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L21;
     ecl_internal_error("GO found an inexistent tag");
     }
     {cl_object v5;
      v5 = ECL_NIL;
      v5 = ecl_make_cclosure_va((cl_objectfn)LC70__g272,env2,Cblock);
      T0 = v5;
     }
     {cl_object v5;
      v5 = ECL_NIL;
      v5 = ecl_make_cfun((cl_objectfn_fixed)LC71__g273,ECL_NIL,Cblock,1);
      T1 = v5;
     }
     T2 = L4make_restart(6, ECL_SYM("NAME",1273), VV[50], ECL_SYM("FUNCTION",1241), T0, VV[15], T1);
     T3 = ecl_list1(T2);
     T4 = CONS(T3,ecl_symbol_value(ECL_SYM("*RESTART-CLUSTERS*",4)));
     ecl_bds_bind(cl_env_copy,ECL_SYM("*RESTART-CLUSTERS*",4),T4); /*  *RESTART-CLUSTERS* */
     {
      volatile cl_object v6;                      /*  RV              */
      volatile cl_object v7;                      /*  USED-RESTART    */
      {
       volatile cl_object env3 = env2;
       CLV4 = env3 = CONS(ECL_NIL,env3);
       {
        volatile cl_object env4 = env3;
        CLV5 = env4 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env4); /*  TAGBODY */
        if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV5))) {
        if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L26;
        ecl_internal_error("GO found an inexistent tag");
        }
        {cl_object v8;
         v8 = ECL_NIL;
         v8 = ecl_make_cclosure_va((cl_objectfn)LC72__g278,env4,Cblock);
         T0 = v8;
        }
        {cl_object v8;
         v8 = ECL_NIL;
         v8 = ecl_make_cfun((cl_objectfn_fixed)LC73__g279,ECL_NIL,Cblock,1);
         T1 = v8;
        }
        T2 = L4make_restart(6, ECL_SYM("NAME",1273), ECL_SYM("IGNORE",428), ECL_SYM("FUNCTION",1241), T0, VV[15], T1);
        T3 = ecl_list1(T2);
        T4 = CONS(T3,ecl_symbol_value(ECL_SYM("*RESTART-CLUSTERS*",4)));
        ecl_bds_bind(cl_env_copy,ECL_SYM("*RESTART-CLUSTERS*",4),T4); /*  *RESTART-CLUSTERS* */
        {
         volatile cl_object v9;                   /*  RV              */
         volatile cl_object v10;                  /*  USED-RESTART    */
         {
          volatile cl_object env5 = env4;
          CLV6 = env5 = CONS(ECL_NIL,env5);
          {
          volatile cl_object env6 = env5;
          CLV7 = env6 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env6); /*  TAGBODY */
          if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV7))) {
          if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L31;
          ecl_internal_error("GO found an inexistent tag");
          }
          {cl_object v11;
          v11 = ECL_NIL;
          v11 = ecl_make_cclosure_va((cl_objectfn)LC74__g284,env6,Cblock);
          T0 = v11;
          }
          {cl_object v11;
          v11 = ECL_NIL;
          v11 = ecl_make_cclosure_va((cl_objectfn)LC75__g285,env6,Cblock);
          T1 = v11;
          }
          T2 = L4make_restart(6, ECL_SYM("NAME",1273), ECL_SYM("CONTINUE",250), ECL_SYM("FUNCTION",1241), T0, VV[15], T1);
          T3 = ecl_list1(T2);
          T4 = CONS(T3,ecl_symbol_value(ECL_SYM("*RESTART-CLUSTERS*",4)));
          ecl_bds_bind(cl_env_copy,ECL_SYM("*RESTART-CLUSTERS*",4),T4); /*  *RESTART-CLUSTERS* */
          L25signal(1, v4condition);
          value0 = (cl_env_copy->function=(ECL_SYM("INVOKE-DEBUGGER",445)->symbol.gfdef))->cfun.entry(1, v4condition) /*  INVOKE-DEBUGGER */;
          ecl_frs_pop(cl_env_copy);
          ecl_bds_unwind1(cl_env_copy);
          goto L30;
L31:;
          cl_env_copy->nvalues = 2;
          cl_env_copy->values[1] = ECL_T;
          cl_env_copy->values[0] = ECL_NIL;
          value0 = cl_env_copy->values[0];
          ecl_frs_pop(cl_env_copy);
          goto L30;
          }
         }
L30:;
         v9 = value0;
         {
          const int v11 = cl_env_copy->nvalues;
          cl_object v12;
          v12 = (v11<=1)? ECL_NIL : cl_env_copy->values[1];
          v10 = v12;
         }
         if (Null(v10)) { goto L37; }
         value0 = ECL_CONS_CAR(CLV0);
         cl_env_copy->nvalues = 1;
         ecl_frs_pop(cl_env_copy);
         ecl_bds_unwind1(cl_env_copy);
         goto L25;
L37:;
         value0 = v9;
         cl_env_copy->nvalues = 1;
         ecl_frs_pop(cl_env_copy);
         ecl_bds_unwind1(cl_env_copy);
         goto L25;
        }
L26:;
        cl_env_copy->nvalues = 2;
        cl_env_copy->values[1] = ECL_T;
        cl_env_copy->values[0] = ECL_NIL;
        value0 = cl_env_copy->values[0];
        ecl_frs_pop(cl_env_copy);
        goto L25;
       }
      }
L25:;
      v6 = value0;
      {
       const int v8 = cl_env_copy->nvalues;
       cl_object v9;
       v9 = (v8<=1)? ECL_NIL : cl_env_copy->values[1];
       v7 = v9;
      }
      if (Null(v7)) { goto L40; }
      value0 = ECL_T;
      cl_env_copy->nvalues = 1;
      ecl_frs_pop(cl_env_copy);
      ecl_bds_unwind1(cl_env_copy);
      return value0;
L40:;
      value0 = v6;
      cl_env_copy->nvalues = 1;
      ecl_frs_pop(cl_env_copy);
      ecl_bds_unwind1(cl_env_copy);
      return value0;
     }
L21:;
     cl_env_copy->nvalues = 2;
     cl_env_copy->values[1] = ECL_T;
     cl_env_copy->values[0] = ECL_NIL;
     value0 = cl_env_copy->values[0];
     ecl_frs_pop(cl_env_copy);
     return value0;
    }
   }
L18:;
   L25signal(1, v4condition);
   value0 = (cl_env_copy->function=(ECL_SYM("INVOKE-DEBUGGER",445)->symbol.gfdef))->cfun.entry(1, v4condition) /*  INVOKE-DEBUGGER */;
   return value0;
  }
 }
}
/*	closure G258                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC66__g258(cl_narg narg, ...)
{
 cl_object CLV0, CLV1, CLV2, CLV3
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV3 = env0;                                     /*  TAGBODY         */
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 {
  cl_object v1temp;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1temp = cl_grab_rest_args(args);
  ecl_va_end(args);
  ECL_CONS_CAR(CLV2) = v1temp;
  cl_go(ECL_CONS_CAR(CLV3),ecl_make_fixnum(0));
 }
 }
}
/*	local function G259                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC67__g259(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_format(2, v1stream, _ecl_static_42);
  return value0;
 }
}
/*	closure G265                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC68__g265(cl_narg narg, ...)
{
 cl_object CLV0, CLV1, CLV2, CLV3
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV3 = env0;                                     /*  TAGBODY         */
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 {
  cl_object v1temp;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1temp = cl_grab_rest_args(args);
  ecl_va_end(args);
  ECL_CONS_CAR(CLV2) = v1temp;
  cl_go(ECL_CONS_CAR(CLV3),ecl_make_fixnum(0));
 }
 }
}
/*	closure G266                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC69__g266(cl_narg narg, cl_object v1stream, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1, CLV2, CLV3
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV3 = env0;
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);                           /*  ARGS            */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  T0 = cl_format(4, ECL_NIL, _ecl_static_19, ECL_CONS_CAR(CLV0), ECL_CONS_CAR(CLV1));
  value0 = cl_format(3, v1stream, _ecl_static_43, T0);
  return value0;
 }
 }
}
/*	closure G272                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC70__g272(cl_narg narg, ...)
{
 cl_object CLV0, CLV1, CLV2, CLV3
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV3 = env0;                                     /*  TAGBODY         */
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 {
  cl_object v1temp;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1temp = cl_grab_rest_args(args);
  ecl_va_end(args);
  ECL_CONS_CAR(CLV2) = v1temp;
  cl_go(ECL_CONS_CAR(CLV3),ecl_make_fixnum(0));
 }
 }
}
/*	local function G273                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC71__g273(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_format(2, v1stream, _ecl_static_44);
  return value0;
 }
}
/*	closure G278                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC72__g278(cl_narg narg, ...)
{
 cl_object CLV0, CLV1, CLV2, CLV3, CLV4, CLV5
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV5 = env0;                                     /*  TAGBODY         */
 CLV4 = _ecl_cdr(CLV5);
 CLV3 = _ecl_cdr(CLV4);
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 {
  cl_object v1temp;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1temp = cl_grab_rest_args(args);
  ecl_va_end(args);
  ECL_CONS_CAR(CLV4) = v1temp;
  cl_go(ECL_CONS_CAR(CLV5),ecl_make_fixnum(0));
 }
 }
}
/*	local function G279                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC73__g279(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_format(2, v1stream, _ecl_static_42);
  return value0;
 }
}
/*	closure G284                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC74__g284(cl_narg narg, ...)
{
 cl_object CLV0, CLV1, CLV2, CLV3, CLV4, CLV5, CLV6, CLV7
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV7 = env0;                                     /*  TAGBODY         */
 CLV6 = _ecl_cdr(CLV7);
 CLV5 = _ecl_cdr(CLV6);
 CLV4 = _ecl_cdr(CLV5);
 CLV3 = _ecl_cdr(CLV4);
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 {
  cl_object v1temp;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1temp = cl_grab_rest_args(args);
  ecl_va_end(args);
  ECL_CONS_CAR(CLV6) = v1temp;
  cl_go(ECL_CONS_CAR(CLV7),ecl_make_fixnum(0));
 }
 }
}
/*	closure G285                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC75__g285(cl_narg narg, cl_object v1stream, ...)
{
 cl_object CLV0, CLV1, CLV2, CLV3, CLV4, CLV5, CLV6, CLV7
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV7 = env0;
 CLV6 = _ecl_cdr(CLV7);
 CLV5 = _ecl_cdr(CLV6);
 CLV4 = _ecl_cdr(CLV5);
 CLV3 = _ecl_cdr(CLV4);
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);                           /*  CONTINUE-STRING */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = cl_format(3, v1stream, _ecl_static_45, ECL_CONS_CAR(CLV0));
  return value0;
 }
 }
}
/*	function definition for TPL-CONTINUE-COMMAND                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L77tpl_continue_command(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1any;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1any = cl_grab_rest_args(args);
  ecl_va_end(args);
  T0 = (VV[11]->symbol.gfdef);
  value0 = cl_apply(3, T0, ECL_SYM("CONTINUE",250), v1any);
  return value0;
 }
}

#include "clos/conditions.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclYy2GIjZ7_w0AxWE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CLOS;CONDITIONS.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclYy2GIjZ7_w0AxWE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defmacro(VV[53]);                        /*  UNIQUE-ID       */
 si_Xmake_special(ECL_SYM("*RESTART-CLUSTERS*",4));
 cl_set(ECL_SYM("*RESTART-CLUSTERS*",4),ECL_NIL);
 si_Xmake_special(VV[1]);
 cl_set(VV[1],ECL_NIL);
 ecl_cmp_defun(VV[54]);                           /*  COMPUTE-RESTARTS */
 ecl_cmp_defun(VV[56]);                           /*  RESTART-PRINT   */
 si_define_structure(15, ECL_SYM("RESTART",720), _ecl_static_2, ECL_NIL, ECL_NIL, VVtemp[0], VVtemp[1], VV[4], ECL_NIL, VV[3], ECL_NIL, VVtemp[2], ecl_make_fixnum(5), ECL_NIL, ECL_NIL, VV[5]);
 VV[6]= cl_find_class(1, ECL_SYM("RESTART",720));
 ecl_cmp_defun(VV[57]);                           /*  MAKE-RESTART    */
 (void)0; /* No entry created for RESTART-REPORT */
 (void)0; /* No entry created for BIND-SIMPLE-RESTARTS */
 (void)0; /* No entry created for BIND-SIMPLE-HANDLERS */
 ecl_cmp_defmacro(VV[65]);                        /*  RESTART-BIND    */
 ecl_cmp_defun(VV[66]);                           /*  FIND-RESTART    */
 (void)0; /* No entry created for FIND-RESTART-NEVER-FAIL */
 ecl_cmp_defun(VV[67]);                           /*  INVOKE-RESTART  */
 ecl_cmp_defun(VV[69]);                           /*  INVOKE-RESTART-INTERACTIVELY */
 ecl_cmp_defmacro(VV[71]);                        /*  RESTART-CASE    */
 ecl_cmp_defmacro(VV[75]);                        /*  WITH-SIMPLE-RESTART */
 ecl_cmp_defmacro(VV[76]);                        /*  WITH-CONDITION-RESTARTS */
 clos_load_defclass(ECL_SYM("CONDITION",248), ECL_NIL, VVtemp[3], ECL_NIL);
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC19__g99,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("PRINT-OBJECT",961), ECL_NIL, VVtemp[4], VVtemp[5], T0, ECL_T);
 }
 ecl_cmp_defmacro(VV[77]);                        /*  DEFINE-CONDITION */
 (void)0; /* No entry created for FIND-SUBCLASSES-OF-TYPE */
 ecl_cmp_defun(VV[78]);                           /*  MAKE-CONDITION  */
 si_Xmake_special(ECL_SYM("*HANDLER-CLUSTERS*",5));
 cl_set(ECL_SYM("*HANDLER-CLUSTERS*",5),ECL_NIL);
 ecl_cmp_defmacro(VV[79]);                        /*  HANDLER-BIND    */
 ecl_cmp_defun(VV[80]);                           /*  SIGNAL          */
 ecl_cmp_defun(VV[81]);                           /*  COERCE-TO-CONDITION */
 ecl_cmp_defun(VV[82]);                           /*  BREAK           */
 ecl_cmp_defun(VV[83]);                           /*  WARN            */
 clos_load_defclass(ECL_SYM("WARNING",904), VV[30], ECL_NIL, ECL_NIL);
 clos_load_defclass(ECL_SYM("SERIOUS-CONDITION",742), VV[30], ECL_NIL, ECL_NIL);
 clos_load_defclass(ECL_SYM("ERROR",337), VVtemp[6], ECL_NIL, ECL_NIL);
 {
  cl_object T0, T1, T2;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC34__g176,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 T1 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T0, VVtemp[7]);
 T2 = cl_list(3, T1, VVtemp[8], VVtemp[9]);
 clos_load_defclass(ECL_SYM("SIMPLE-CONDITION",767), VV[30], T2, ECL_NIL);
 }
 clos_load_defclass(ECL_SYM("SIMPLE-WARNING",776), VVtemp[10], ECL_NIL, ECL_NIL);
 clos_load_defclass(ECL_SYM("STYLE-WARNING",827), VVtemp[11], ECL_NIL, ECL_NIL);
 clos_load_defclass(VV[39], VVtemp[12], ECL_NIL, ECL_NIL);
 clos_load_defclass(ECL_SYM("SIMPLE-ERROR",770), VVtemp[13], ECL_NIL, ECL_NIL);
 clos_load_defclass(ECL_SYM("STORAGE-CONDITION",797), VVtemp[6], ECL_NIL, ECL_NIL);
 clos_load_defclass(ECL_SYM("SEGMENTATION-VIOLATION",1676), VVtemp[14], VVtemp[15], ECL_NIL);
 {
  cl_object T0, T1, T2;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC36__g178,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 T1 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T0, VVtemp[16]);
 T2 = cl_list(3, T1, VVtemp[17], VVtemp[18]);
 clos_load_defclass(ECL_SYM("STACK-OVERFLOW",1665), VVtemp[14], T2, ECL_NIL);
 }
 clos_load_defclass(ECL_SYM("STORAGE-EXHAUSTED",1664), VVtemp[14], VVtemp[19], ECL_NIL);
 clos_load_defclass(ECL_SYM("ILLEGAL-INSTRUCTION",1673), VVtemp[6], VVtemp[20], ECL_NIL);
 {
  cl_object T0, T1, T2;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC38__g180,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 T1 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T0, VVtemp[21]);
 T2 = cl_list(2, T1, VVtemp[22]);
 clos_load_defclass(ECL_SYM("UNIX-SIGNAL-RECEIVED",1800), VV[30], T2, ECL_NIL);
 }
 {
  cl_object T0, T1, T2;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC40__g182,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 T1 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T0, VVtemp[24]);
 T2 = cl_list(3, T1, VVtemp[25], VVtemp[26]);
 clos_load_defclass(ECL_SYM("TYPE-ERROR",870), VVtemp[23], T2, ECL_NIL);
 }
 clos_load_defclass(ECL_SYM("SIMPLE-TYPE-ERROR",773), VVtemp[27], ECL_NIL, ECL_NIL);
 {
  cl_object T0, T1, T2;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC42__g184,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 T1 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T0, VVtemp[29]);
 T2 = cl_list(3, T1, VVtemp[30], VVtemp[31]);
 clos_load_defclass(VV[40], VVtemp[28], T2, ECL_NIL);
 }
 clos_load_defclass(ECL_SYM("PROGRAM-ERROR",672), VVtemp[23], ECL_NIL, ECL_NIL);
 clos_load_defclass(ECL_SYM("CONTROL-ERROR",255), VVtemp[23], ECL_NIL, ECL_NIL);
 clos_load_defclass(ECL_SYM("STREAM-ERROR",801), VVtemp[23], VVtemp[32], ECL_NIL);
 {
  cl_object T0, T1, T2;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC44__g186,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 T1 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T0, VVtemp[34]);
 T2 = ecl_list1(T1);
 clos_load_defclass(ECL_SYM("END-OF-FILE",329), VVtemp[33], T2, ECL_NIL);
 }
 {
  cl_object T0, T1, T2;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC46__g188,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 T1 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T0, VVtemp[35]);
 T2 = cl_list(2, T1, VVtemp[36]);
 clos_load_defclass(ECL_SYM("FILE-ERROR",353), VVtemp[23], T2, ECL_NIL);
 }
 clos_load_defclass(ECL_SYM("PACKAGE-ERROR",618), VVtemp[23], VVtemp[37], ECL_NIL);
 clos_load_defclass(ECL_SYM("CELL-ERROR",200), VVtemp[23], VVtemp[38], ECL_NIL);
 {
  cl_object T0, T1, T2;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC48__g190,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 T1 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T0, VVtemp[40]);
 T2 = ecl_list1(T1);
 clos_load_defclass(ECL_SYM("UNBOUND-VARIABLE",878), VVtemp[39], T2, ECL_NIL);
 }
 {
  cl_object T0, T1, T2;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC50__g192,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 T1 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T0, VVtemp[41]);
 T2 = cl_list(2, T1, VVtemp[42]);
 clos_load_defclass(ECL_SYM("UNBOUND-SLOT",876), VVtemp[39], T2, ECL_NIL);
 }
 {
  cl_object T0, T1, T2;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC52__g194,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 T1 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T0, VVtemp[43]);
 T2 = ecl_list1(T1);
 clos_load_defclass(ECL_SYM("UNDEFINED-FUNCTION",879), VVtemp[39], T2, ECL_NIL);
 }
 clos_load_defclass(ECL_SYM("ARITHMETIC-ERROR",93), VVtemp[23], VVtemp[44], ECL_NIL);
 clos_load_defclass(ECL_SYM("DIVISION-BY-ZERO",306), VVtemp[45], ECL_NIL, ECL_NIL);
 clos_load_defclass(ECL_SYM("FLOATING-POINT-OVERFLOW",381), VVtemp[45], ECL_NIL, ECL_NIL);
 clos_load_defclass(ECL_SYM("FLOATING-POINT-UNDERFLOW",382), VVtemp[45], ECL_NIL, ECL_NIL);
 clos_load_defclass(ECL_SYM("FLOATING-POINT-INEXACT",379), VVtemp[45], ECL_NIL, ECL_NIL);
 clos_load_defclass(ECL_SYM("FLOATING-POINT-INVALID-OPERATION",380), VVtemp[45], ECL_NIL, ECL_NIL);
 clos_load_defclass(VV[41], VVtemp[46], VVtemp[47], ECL_NIL);
 {
  cl_object T0, T1, T2;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC54__g196,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 T1 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T0, VVtemp[48]);
 T2 = cl_list(2, T1, VVtemp[49]);
 clos_load_defclass(ECL_SYM("PRINT-NOT-READABLE",663), VVtemp[23], T2, ECL_NIL);
 }
 clos_load_defclass(ECL_SYM("PARSE-ERROR",627), VVtemp[23], ECL_NIL, ECL_NIL);
 clos_load_defclass(ECL_SYM("READER-ERROR",699), VVtemp[50], ECL_NIL, ECL_NIL);
 {
  cl_object T0, T1, T2, T3, T4, T5, T6;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC56__g198,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 T1 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T0, VVtemp[52]);
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC57__g200,ECL_NIL,Cblock,0);
  T2 = v1;
 }
 T3 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T2, VVtemp[55]);
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC58__g201,ECL_NIL,Cblock,0);
  T4 = v1;
 }
 T5 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T4, VVtemp[56]);
 T6 = cl_list(6, T1, VVtemp[53], VVtemp[54], T3, T5, VVtemp[57]);
 clos_load_defclass(ECL_SYM("FORMAT-ERROR",1074), VVtemp[51], T6, ECL_NIL);
 }
 clos_load_defclass(ECL_SYM("INTERACTIVE-INTERRUPT",1663), VVtemp[6], VVtemp[58], ECL_NIL);
 (void)0; /* No entry created for SIGNAL-SIMPLE-ERROR */
 ecl_cmp_defmacro(VV[89]);                        /*  HANDLER-CASE    */
 ecl_cmp_defmacro(VV[90]);                        /*  IGNORE-ERRORS   */
 (void)0; /* No entry created for ABORT */
 (void)0; /* No entry created for CONTINUE */
 (void)0; /* No entry created for MUFFLE-WARNING */
 (void)0; /* No entry created for STORE-VALUE */
 (void)0; /* No entry created for USE-VALUE */
 (void)0; /* No entry created for ASSERT-REPORT */
 (void)0; /* No entry created for ASSERT-PROMPT */
 (void)0; /* No entry created for ASSERT-FAILURE */
 ecl_cmp_defun(VV[91]);                           /*  UNIVERSAL-ERROR-HANDLER */
 ecl_cmp_defun(VV[92]);                           /*  TPL-CONTINUE-COMMAND */
}
