/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CLOS;STANDARD.LSP                                 */
#include <ecl/ecl-cmp.h>
#include "clos/standard.eclh"
/*	local function G0                                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC1__g0(cl_narg narg, cl_object v1instance, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2initargs;
  ecl_va_list args; ecl_va_start(args,v1instance,narg,1);
  v2initargs = cl_grab_rest_args(args);
  ecl_va_end(args);
  T0 = (ECL_SYM("SHARED-INITIALIZE",965)->symbol.gfdef);
  value0 = cl_apply(4, T0, v1instance, ECL_T, v2initargs);
  return value0;
 }
}
/*	local function G1                                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC2__g1(cl_narg narg, cl_object v1instance, ...)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2initargs;
  ecl_va_list args; ecl_va_start(args,v1instance,narg,1);
  v2initargs = cl_grab_rest_args(args);
  ecl_va_end(args);
  T0 = cl_class_of(v1instance);
  T1 = (ECL_SYM("REINITIALIZE-INSTANCE",963)->symbol.gfdef);
  T2 = ecl_list1(v1instance);
  T3 = (cl_env_copy->function=(ECL_SYM("COMPUTE-APPLICABLE-METHODS",936)->symbol.gfdef))->cfun.entry(2, T1, T2) /*  COMPUTE-APPLICABLE-METHODS */;
  T4 = (ECL_SYM("SHARED-INITIALIZE",965)->symbol.gfdef);
  T5 = cl_list(2, v1instance, ECL_T);
  T6 = (cl_env_copy->function=(ECL_SYM("COMPUTE-APPLICABLE-METHODS",936)->symbol.gfdef))->cfun.entry(2, T4, T5) /*  COMPUTE-APPLICABLE-METHODS */;
  T7 = L46valid_keywords_from_methods(2, T3, T6);
  L47check_initargs(3, T0, v2initargs, T7);
  T0 = (ECL_SYM("SHARED-INITIALIZE",965)->symbol.gfdef);
  value0 = cl_apply(4, T0, v1instance, ECL_NIL, v2initargs);
  return value0;
 }
}
/*	local function G42                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC3__g42(cl_narg narg, cl_object v1instance, cl_object v2slot_names, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3initargs;
  ecl_va_list args; ecl_va_start(args,v2slot_names,narg,2);
  v3initargs = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v4class;
   v4class = cl_class_of(v1instance);
   {
    cl_object v5;
    v5 = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-SLOTS",1494))(1, v4class) /*  CLASS-SLOTS */;
    goto L6;
L5:;
    {
     cl_object v6slotd;
     v6slotd = ecl_car(v5);
     {
      cl_object v7slot_initargs;
      cl_object v8slot_name;
      v7slot_initargs = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-INITARGS",1544))(1, v6slotd) /*  SLOT-DEFINITION-INITARGS */;
      v8slot_name = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v6slotd) /*  SLOT-DEFINITION-NAME */;
      {
       cl_object v9l;
       cl_object v10initarg;
       cl_object v11val;
       v9l = v3initargs;
       v10initarg = ECL_NIL;
       v11val = ECL_NIL;
       goto L21;
L20:;
       {
        cl_object v12;
        v12 = v9l;
        if (ecl_unlikely(!ECL_LISTP(v12))) FEtype_error_list(v12);
        if (Null(v12)) { goto L28; }
        {
         cl_object v13;
         v13 = ECL_CONS_CDR(v12);
         v9l = v13;
         v12 = ECL_CONS_CAR(v12);
        }
L28:;
        v10initarg = v12;
       }
       if (!(ecl_endp(v9l))) { goto L34; }
       si_simple_program_error(2, _ecl_static_1, v3initargs);
L34:;
       if (ECL_SYMBOLP(v10initarg)) { goto L36; }
       si_simple_program_error(2, _ecl_static_2, v10initarg);
L36:;
       {
        cl_object v12;
        v12 = v9l;
        if (ecl_unlikely(!ECL_LISTP(v12))) FEtype_error_list(v12);
        if (Null(v12)) { goto L43; }
        {
         cl_object v13;
         v13 = ECL_CONS_CDR(v12);
         v9l = v13;
         v12 = ECL_CONS_CAR(v12);
        }
L43:;
        v11val = v12;
       }
       if (Null(si_memq(v10initarg,v7slot_initargs))) { goto L49; }
       (cl_env_copy->function=ECL_CONS_CAR(VV[32]))->cfun.entry(3, v11val, v1instance, v8slot_name) /*  (SETF SLOT-VALUE) */;
       value0 = ECL_T;
       goto L15;
L49:;
L21:;
       if (v9l==ECL_NIL) { goto L52; }
       goto L20;
L52:;
       value0 = ECL_NIL;
      }
L15:;
      if ((value0)!=ECL_NIL) { goto L14; }
      if (Null(v2slot_names)) { goto L10; }
      if ((v2slot_names)==(ECL_T)) { goto L57; }
      if (Null(ecl_memql(v8slot_name,v2slot_names))) { goto L10; }
      goto L56;
L57:;
L56:;
      if ((cl_slot_boundp(v1instance, v8slot_name))!=ECL_NIL) { goto L10; }
      {
       cl_object v9initfun;
       v9initfun = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-INITFUNCTION",1546))(1, v6slotd) /*  SLOT-DEFINITION-INITFUNCTION */;
       if (Null(v9initfun)) { goto L10; }
       {
        cl_object v10;
        v10 = ecl_function_dispatch(cl_env_copy,v9initfun)(0);
        (cl_env_copy->function=ECL_CONS_CAR(VV[32]))->cfun.entry(3, v10, v1instance, v8slot_name) /*  (SETF SLOT-VALUE) */;
        goto L10;
       }
      }
L14:;
      goto L10;
     }
L10:;
    }
    v5 = ecl_cdr(v5);
L6:;
    if (Null(v5)) { goto L64; }
    goto L5;
L64:;
   }
  }
  value0 = v1instance;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for COMPUTE-INSTANCE-SIZE                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4compute_instance_size(cl_object v1slots)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2slotd;
   cl_object v3;
   v2slotd = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v1slots))) FEtype_error_list(v1slots);
   v3 = v1slots;
   {
    cl_object v4last_location;
    v4last_location = ecl_make_fixnum(0);
    {
     cl_object v5num_slots;
     v5num_slots = ecl_make_fixnum(0);
L6:;
     if (!(ecl_endp(v3))) { goto L8; }
     goto L7;
L8:;
     v2slotd = _ecl_car(v3);
     {
      cl_object v6;
      v6 = _ecl_cdr(v3);
      if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
      v3 = v6;
     }
     T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-ALLOCATION",1543))(1, v2slotd) /*  SLOT-DEFINITION-ALLOCATION */;
     if (!((T0)==(ECL_SYM("INSTANCE",1256)))) { goto L16; }
     {
      cl_object v6new_loc;
      v6new_loc = L33safe_slot_definition_location(1, v2slotd);
      v5num_slots = ecl_plus(v5num_slots,ecl_make_fixnum(1));
      if (Null(v6new_loc)) { goto L16; }
      if (!(ecl_number_compare(v6new_loc,v4last_location)>0)) { goto L16; }
      v4last_location = v6new_loc;
     }
L16:;
     goto L6;
L7:;
     T0 = ecl_one_plus(v4last_location);
     value0 = (ecl_number_compare(v5num_slots,T0)>=0?v5num_slots:T0);
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
  }
 }
}
/*	local function G69                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC5__g69(cl_narg narg, cl_object v1class, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  if ((ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-FINALIZED-P",1491))(1, v1class) /*  CLASS-FINALIZED-P */)!=ECL_NIL) { goto L1; }
  ecl_function_dispatch(cl_env_copy,ECL_SYM("FINALIZE-INHERITANCE",1513))(1, v1class) /*  FINALIZE-INHERITANCE */;
L1:;
  {
   cl_object v2x;
   T0 = ecl_function_dispatch(cl_env_copy,VV[34])(1, v1class) /*  CLASS-SIZE */;
   v2x = si_allocate_raw_instance(ECL_NIL, v1class, T0);
   si_instance_sig_set(v2x);
   value0 = v2x;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G72                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC6__g72(cl_narg narg, cl_object v1class, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2initargs;
  ecl_va_list args; ecl_va_start(args,v1class,narg,1);
  v2initargs = cl_grab_rest_args(args);
  ecl_va_end(args);
  if ((ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-FINALIZED-P",1491))(1, v1class) /*  CLASS-FINALIZED-P */)!=ECL_NIL) { goto L1; }
  ecl_function_dispatch(cl_env_copy,ECL_SYM("FINALIZE-INHERITANCE",1513))(1, v1class) /*  FINALIZE-INHERITANCE */;
L1:;
  v2initargs = L8add_default_initargs(v1class, v2initargs);
  {
   cl_object v3keywords;
   if (Null(cl_slot_boundp(v1class, VV[1]))) { goto L7; }
   v3keywords = ecl_function_dispatch(cl_env_copy,VV[35])(1, v1class) /*  CLASS-VALID-INITARGS */;
   goto L6;
L7:;
   v3keywords = L19precompute_valid_initarg_keywords(v1class);
L6:;
   T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-SLOTS",1494))(1, v1class) /*  CLASS-SLOTS */;
   L47check_initargs(5, v1class, v2initargs, ECL_NIL, T0, v3keywords);
  }
  {
   cl_object v3instance;
   T0 = (ECL_SYM("ALLOCATE-INSTANCE",927)->symbol.gfdef);
   v3instance = cl_apply(3, T0, v1class, v2initargs);
   T0 = (ECL_SYM("INITIALIZE-INSTANCE",947)->symbol.gfdef);
   cl_apply(3, T0, v3instance, v2initargs);
   value0 = v3instance;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for DELETE-KEYWORD                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7delete_keyword(cl_object v1keyword, cl_object v2list)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
L2:;
  T0 = cl_getf(3, v2list, v1keyword, v2list);
  if (!((T0)==(v2list))) { goto L4; }
  goto L3;
L4:;
  {
   cl_object v4;
   cl_object v5;                                  /*  FLAG            */
   value0 = si_rem_f(v2list, v1keyword);
   v4 = value0;
   v5 = cl_env_copy->values[1];
   v2list = v4;
  }
  goto L2;
L3:;
  value0 = v2list;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for ADD-DEFAULT-INITARGS                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8add_default_initargs(cl_object v1class, cl_object v2initargs)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3output;
   v3output = ECL_NIL;
   {
    cl_object v4;
    v4 = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-DEFAULT-INITARGS",1486))(1, v1class) /*  CLASS-DEFAULT-INITARGS */;
    goto L6;
L5:;
    {
     cl_object v5scan;
     v5scan = ecl_car(v4);
     {
      cl_object v6initarg;
      cl_object v7value;
      cl_object v8supplied_value;
      v6initarg = ecl_car(v5scan);
      v7value = ecl_caddr(v5scan);
      v8supplied_value = si_search_keyword(2, v2initargs, v6initarg);
      if ((v8supplied_value)==(VV[3])) { goto L15; }
      if (!((v8supplied_value)==(ECL_SYM("MISSING-KEYWORD",1929)))) { goto L10; }
      goto L14;
L15:;
L14:;
      if (!((v8supplied_value)==(VV[3]))) { goto L17; }
      v2initargs = L7delete_keyword(v6initarg, v2initargs);
L17:;
      T0 = ecl_function_dispatch(cl_env_copy,v7value)(0);
      v3output = cl_listX(3, T0, v6initarg, v3output);
     }
L10:;
    }
    v4 = ecl_cdr(v4);
L6:;
    if (Null(v4)) { goto L24; }
    goto L5;
L24:;
   }
   if (Null(v3output)) { goto L26; }
   T0 = cl_nreverse(v3output);
   value0 = ecl_append(v2initargs,T0);
   cl_env_copy->nvalues = 1;
   return value0;
L26:;
   value0 = v2initargs;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G81                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC9__g81(cl_narg narg, cl_object v1class, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  value0 = cl_find_class(2, ECL_SYM("STANDARD-DIRECT-SLOT-DEFINITION",1560), ECL_NIL);
  return value0;
 }
}
/*	local function G82                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC10__g82(cl_narg narg, cl_object v1class, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  value0 = cl_find_class(2, ECL_SYM("STANDARD-EFFECTIVE-SLOT-DEFINITION",1561), ECL_NIL);
  return value0;
 }
}
/*	function definition for HAS-FORWARD-REFERENCED-PARENTS        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L11has_forward_referenced_parents(cl_object v1class)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L27forward_referenced_class_p(v1class);
  if ((value0)!=ECL_NIL) { goto L2; }
  if ((ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-FINALIZED-P",1491))(1, v1class) /*  CLASS-FINALIZED-P */)!=ECL_NIL) { goto L5; }
  T0 = (VV[4]->symbol.gfdef);
  T1 = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-DIRECT-SUPERCLASSES",1490))(1, v1class) /*  CLASS-DIRECT-SUPERCLASSES */;
  value0 = cl_some(2, T0, T1);
  return value0;
L5:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for FINALIZE-UNLESS-FORWARD               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L12finalize_unless_forward(cl_object v1class)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = (VV[4]->symbol.gfdef);
  T1 = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-DIRECT-SUPERCLASSES",1490))(1, v1class) /*  CLASS-DIRECT-SUPERCLASSES */;
  if ((cl_find_if(2, T0, T1))!=ECL_NIL) { goto L1; }
  value0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("FINALIZE-INHERITANCE",1513))(1, v1class) /*  FINALIZE-INHERITANCE */;
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G89                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC15__g89(cl_narg narg, cl_object v1class, ...)
{
 cl_object T0, T1, T2;
 cl_object env0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2initargs;
  cl_object v3direct_slots;
  ecl_va_list args; ecl_va_start(args,v1class,narg,1);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,LC15__g89keys,keyvars,(cl_object*)&v2initargs,TRUE);
   ecl_va_end(args);
   v3direct_slots = keyvars[0];
  }
  {
   cl_object env1 = env0;
   if (!(ECL_LISTP(ecl_symbol_value(ECL_SYM(".COMBINED-METHOD-ARGS.",1473))))) { goto L2; }
   T0 = ecl_symbol_value(ECL_SYM(".COMBINED-METHOD-ARGS.",1473));
   goto L1;
L2:;
   T1 = (ECL_SYM("LIST",481)->symbol.gfdef);
   T0 = cl_apply(2, T1, ecl_symbol_value(ECL_SYM(".COMBINED-METHOD-ARGS.",1473)));
L1:;
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(T0,env1);                   /*  .CLOSED-COMBINED-METHOD-ARGS. */
   CLV1 = env1 = CONS(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)),env1); /*  .NEXT-METHODS. */
   {cl_object v4;
    v4 = ECL_NIL;
    v4 = ecl_make_cclosure_va((cl_objectfn)LC13call_next_method,env1,Cblock);
    {
     cl_object v5s;
     cl_object v6;
     v5s = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v3direct_slots))) FEtype_error_list(v3direct_slots);
     v6 = v3direct_slots;
     {
      cl_object v7;
      cl_object v8;
      v7 = ecl_list1(ECL_NIL);
      v8 = v7;
L12:;
      if (!(ecl_endp(v6))) { goto L14; }
      goto L13;
L14:;
      v5s = _ecl_car(v6);
      {
       cl_object v9;
       v9 = _ecl_cdr(v6);
       if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
       v6 = v9;
      }
      if (ecl_unlikely(ECL_ATOM(v8))) FEtype_error_cons(v8);
      T1 = v8;
      T2 = ecl_function_dispatch(cl_env_copy,VV[40])(2, v1class, v5s) /*  CANONICAL-SLOT-TO-DIRECT-SLOT */;
      v8 = ecl_list1(T2);
      (ECL_CONS_CDR(T1)=v8,T1);
      goto L12;
L13:;
      T0 = ecl_cdr(v7);
      goto L6;
     }
    }
L6:;
    cl_apply(5, v4, v1class, ECL_SYM("DIRECT-SLOTS",990), T0, v2initargs);
    L12finalize_unless_forward(v1class);
    value0 = v1class;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	closure CALL-NEXT-METHOD                                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC13call_next_method(cl_narg narg, ...)
{
 cl_object T0, T1, T2;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  .NEXT-METHODS.  */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 {
  cl_object v1args;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1args = cl_grab_rest_args(args);
  ecl_va_end(args);
  if ((ECL_CONS_CAR(CLV1))!=ECL_NIL) { goto L1; }
  cl_error(1, _ecl_static_3);
L1:;
  T0 = ecl_car(ECL_CONS_CAR(CLV1));
  value0 = v1args;
  if ((value0)!=ECL_NIL) { goto L6; }
  T1 = ECL_CONS_CAR(CLV0);
  goto L4;
L6:;
  T1 = value0;
  goto L4;
L4:;
  T2 = ecl_cdr(ECL_CONS_CAR(CLV1));
  value0 = ecl_function_dispatch(cl_env_copy,T0)(2, T1, T2);
  return value0;
 }
 }
}
/*	local function G103                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC18__g103(cl_narg narg, cl_object v1class, cl_object v2slot_names, ...)
{
 cl_object T0, T1;
 cl_object env0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3initargs;
  cl_object v4direct_superclasses;
  ecl_va_list args; ecl_va_start(args,v2slot_names,narg,2);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,LC18__g103keys,keyvars,(cl_object*)&v3initargs,TRUE);
   ecl_va_end(args);
   v4direct_superclasses = keyvars[0];
  }
  {
   cl_object env1 = env0;
   if (!(ECL_LISTP(ecl_symbol_value(ECL_SYM(".COMBINED-METHOD-ARGS.",1473))))) { goto L2; }
   T0 = ecl_symbol_value(ECL_SYM(".COMBINED-METHOD-ARGS.",1473));
   goto L1;
L2:;
   T1 = (ECL_SYM("LIST",481)->symbol.gfdef);
   T0 = cl_apply(2, T1, ecl_symbol_value(ECL_SYM(".COMBINED-METHOD-ARGS.",1473)));
L1:;
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(T0,env1);                   /*  .CLOSED-COMBINED-METHOD-ARGS. */
   CLV1 = env1 = CONS(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)),env1); /*  .NEXT-METHODS. */
   {cl_object v5;
    v5 = ECL_NIL;
    v5 = ecl_make_cclosure_va((cl_objectfn)LC16call_next_method,env1,Cblock);
    {
     cl_object v6class;
     cl_object v7direct_superclasses;
     if (Null(cl_slot_boundp(v1class, VV[6]))) { goto L7; }
     T0 = cl_slot_value(v1class, VV[6]);
     goto L6;
L7:;
     T0 = ECL_NIL;
L6:;
     v6class = cl_apply(6, v5, v1class, v2slot_names, ECL_SYM("DIRECT-SUPERCLASSES",991), T0, v3initargs);
     v7direct_superclasses = L25check_direct_superclasses(v6class, v4direct_superclasses);
     {
      cl_object v8;
      cl_object v9c;
      cl_object v10;
      v8 = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-DIRECT-SUPERCLASSES",1490))(1, v6class) /*  CLASS-DIRECT-SUPERCLASSES */;
      v9c = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
      v10 = v8;
L15:;
      if (!(ecl_endp(v10))) { goto L17; }
      goto L16;
L17:;
      v9c = _ecl_car(v10);
      {
       cl_object v11;
       v11 = _ecl_cdr(v10);
       if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
       v10 = v11;
      }
      if ((si_memq(v9c,v7direct_superclasses))!=ECL_NIL) { goto L25; }
      ecl_function_dispatch(cl_env_copy,ECL_SYM("REMOVE-DIRECT-SUBCLASS",1539))(2, v9c, v6class) /*  REMOVE-DIRECT-SUBCLASS */;
L25:;
      goto L15;
L16:;
     }
     (cl_env_copy->function=ECL_CONS_CAR(VV[42]))->cfun.entry(2, v7direct_superclasses, v6class) /*  (SETF CLASS-DIRECT-SUPERCLASSES) */;
     {
      cl_object v8c;
      cl_object v9;
      v8c = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v7direct_superclasses))) FEtype_error_list(v7direct_superclasses);
      v9 = v7direct_superclasses;
L33:;
      if (!(ecl_endp(v9))) { goto L35; }
      goto L34;
L35:;
      v8c = _ecl_car(v9);
      {
       cl_object v10;
       v10 = _ecl_cdr(v9);
       if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
       v9 = v10;
      }
      ecl_function_dispatch(cl_env_copy,ECL_SYM("ADD-DIRECT-SUBCLASS",1485))(2, v8c, v6class) /*  ADD-DIRECT-SUBCLASS */;
      goto L33;
L34:;
     }
     value0 = v6class;
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
  }
 }
}
/*	closure CALL-NEXT-METHOD                                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC16call_next_method(cl_narg narg, ...)
{
 cl_object T0, T1, T2;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  .NEXT-METHODS.  */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 {
  cl_object v1args;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1args = cl_grab_rest_args(args);
  ecl_va_end(args);
  if ((ECL_CONS_CAR(CLV1))!=ECL_NIL) { goto L1; }
  cl_error(1, _ecl_static_3);
L1:;
  T0 = ecl_car(ECL_CONS_CAR(CLV1));
  value0 = v1args;
  if ((value0)!=ECL_NIL) { goto L6; }
  T1 = ECL_CONS_CAR(CLV0);
  goto L4;
L6:;
  T1 = value0;
  goto L4;
L4:;
  T2 = ecl_cdr(ECL_CONS_CAR(CLV1));
  value0 = ecl_function_dispatch(cl_env_copy,T0)(2, T1, T2);
  return value0;
 }
 }
}
/*	function definition for PRECOMPUTE-VALID-INITARG-KEYWORDS     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L19precompute_valid_initarg_keywords(cl_object v1class)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   {
    cl_object v3methods;
    T0 = (ECL_SYM("ALLOCATE-INSTANCE",927)->symbol.gfdef);
    T1 = ecl_list1(v1class);
    T2 = (cl_env_copy->function=(ECL_SYM("COMPUTE-APPLICABLE-METHODS",936)->symbol.gfdef))->cfun.entry(2, T0, T1) /*  COMPUTE-APPLICABLE-METHODS */;
    T3 = (ECL_SYM("INITIALIZE-INSTANCE",947)->symbol.gfdef);
    T4 = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-PROTOTYPE",1493))(1, v1class) /*  CLASS-PROTOTYPE */;
    T5 = ecl_list1(T4);
    T6 = (cl_env_copy->function=(ECL_SYM("COMPUTE-APPLICABLE-METHODS",936)->symbol.gfdef))->cfun.entry(2, T3, T5) /*  COMPUTE-APPLICABLE-METHODS */;
    T7 = (ECL_SYM("SHARED-INITIALIZE",965)->symbol.gfdef);
    T8 = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-PROTOTYPE",1493))(1, v1class) /*  CLASS-PROTOTYPE */;
    T9 = cl_list(2, T8, ECL_T);
    T10 = (cl_env_copy->function=(ECL_SYM("COMPUTE-APPLICABLE-METHODS",936)->symbol.gfdef))->cfun.entry(2, T7, T9) /*  COMPUTE-APPLICABLE-METHODS */;
    v3methods = cl_nconc(3, T2, T6, T10);
    {
     cl_object v4m;
     cl_object v5;
     v4m = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v3methods))) FEtype_error_list(v3methods);
     v5 = v3methods;
     {
      cl_object v6k;
      v6k = ECL_NIL;
      {
       cl_object v7;
       cl_object v8;
       v7 = ecl_list1(ECL_NIL);
       v8 = v7;
L12:;
       if (!(ecl_endp(v5))) { goto L14; }
       goto L13;
L14:;
       v4m = _ecl_car(v5);
       {
        cl_object v9;
        v9 = _ecl_cdr(v5);
        if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
        v5 = v9;
       }
       v6k = ecl_function_dispatch(cl_env_copy,VV[44])(1, v4m) /*  METHOD-KEYWORDS */;
       if (!((v6k)==(ECL_T))) { goto L24; }
       v2 = ECL_T;
       goto L1;
L24:;
       {
        cl_object v9;
        v9 = cl_copy_list(v6k);
        if (ecl_unlikely(ECL_ATOM(v8))) FEtype_error_cons(v8);
        T0 = v8;
        (ECL_CONS_CDR(T0)=v9,T0);
        if (Null(v9)) { goto L26; }
       }
       T0 = ecl_cdr(v8);
       v8 = ecl_last(T0,1);
L26:;
       goto L12;
L13:;
       v2 = ecl_cdr(v7);
       goto L1;
      }
     }
    }
   }
L1:;
   value0 = (cl_env_copy->function=ECL_CONS_CAR(VV[45]))->cfun.entry(2, v2, v1class) /*  (SETF CLASS-VALID-INITARGS) */;
   return value0;
  }
 }
}
/*	function definition for UPDATE-DEPENDENTS                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L21update_dependents(cl_object v1object, cl_object v2initargs)
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1object,env0);              /*  OBJECT          */
  CLV1 = env0 = CONS(v2initargs,env0);            /*  INITARGS        */
  if (Null(ecl_symbol_value(VV[8]))) { goto L1; }
  {cl_object v3;
   v3 = ECL_NIL;
   v3 = ecl_make_cclosure_va((cl_objectfn)LC20__g121,env0,Cblock);
   T0 = v3;
  }
  value0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("MAP-DEPENDENTS",1529))(2, ECL_CONS_CAR(CLV0), T0) /*  MAP-DEPENDENTS */;
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	closure G121                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC20__g121(cl_narg narg, cl_object v1dep, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  INITARGS        */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  T0 = (ECL_SYM("UPDATE-DEPENDENT",1572)->symbol.gfdef);
  value0 = cl_apply(4, T0, ECL_CONS_CAR(CLV0), v1dep, ECL_CONS_CAR(CLV1));
  return value0;
 }
 }
}
/*	local function G136                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC22__g136(cl_narg narg, cl_object v1class, cl_object v2slot_names, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3initargs;
  cl_object v4optimize_slot_access;
  cl_object v5sealedp;
  ecl_va_list args; ecl_va_start(args,v2slot_names,narg,2);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,LC22__g136keys,keyvars,(cl_object*)&v3initargs,TRUE);
   ecl_va_end(args);
   if (Null(keyvars[2])) {
    v4optimize_slot_access = ecl_list1(ecl_symbol_value(ECL_SYM("*OPTIMIZE-SLOT-ACCESS*",1476)));
   } else {
    v4optimize_slot_access = keyvars[0];
   }
   v5sealedp = keyvars[1];
  }
  {
   cl_object v6;
   v6 = ecl_car(v4optimize_slot_access);
   (cl_env_copy->function=ECL_CONS_CAR(VV[32]))->cfun.entry(3, v6, v1class, VV[10]) /*  (SETF SLOT-VALUE) */;
  }
  {
   cl_object v6;
   if (Null(v5sealedp)) { goto L7; }
   v6 = ECL_T;
   goto L5;
L7:;
   v6 = ECL_NIL;
   goto L5;
L5:;
   (cl_env_copy->function=ECL_CONS_CAR(VV[32]))->cfun.entry(3, v6, v1class, VV[11]) /*  (SETF SLOT-VALUE) */;
  }
  if (Null(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)))) { goto L11; }
  T0 = ecl_car(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
  T1 = ecl_cdr(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
  v1class = ecl_function_dispatch(cl_env_copy,T0)(2, ecl_symbol_value(ECL_SYM(".COMBINED-METHOD-ARGS.",1473)), T1);
  goto L10;
L11:;
  v1class = cl_error(1, _ecl_static_4);
L10:;
  L21update_dependents(v1class, v3initargs);
  value0 = v1class;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G150                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC23__g150(cl_object v1parent, cl_object v2child)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-DIRECT-SUBCLASSES",1489))(1, v1parent) /*  CLASS-DIRECT-SUBCLASSES */;
   v3 = cl_adjoin(2, v2child, T0);
   value0 = (cl_env_copy->function=ECL_CONS_CAR(VV[49]))->cfun.entry(2, v3, v1parent) /*  (SETF CLASS-DIRECT-SUBCLASSES) */;
   return value0;
  }
 }
}
/*	local function G158                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC24__g158(cl_object v1parent, cl_object v2child)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-DIRECT-SUBCLASSES",1489))(1, v1parent) /*  CLASS-DIRECT-SUBCLASSES */;
   v3 = cl_remove(2, v2child, T0);
   value0 = (cl_env_copy->function=ECL_CONS_CAR(VV[49]))->cfun.entry(2, v3, v1parent) /*  (SETF CLASS-DIRECT-SUBCLASSES) */;
   return value0;
  }
 }
}
/*	function definition for CHECK-DIRECT-SUPERCLASSES             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L25check_direct_superclasses(cl_object v1class, cl_object v2supplied_superclasses)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v2supplied_superclasses)) { goto L2; }
  {
   cl_object v3superclass;
   cl_object v4;
   v3superclass = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v2supplied_superclasses))) FEtype_error_list(v2supplied_superclasses);
   v4 = v2supplied_superclasses;
L7:;
   if (!(ecl_endp(v4))) { goto L9; }
   goto L8;
L9:;
   v3superclass = _ecl_car(v4);
   {
    cl_object v5;
    v5 = _ecl_cdr(v4);
    if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
    v4 = v5;
   }
   if ((ecl_function_dispatch(cl_env_copy,ECL_SYM("VALIDATE-SUPERCLASS",1574))(2, v1class, v3superclass) /*  VALIDATE-SUPERCLASS */)!=ECL_NIL) { goto L17; }
   if (!((ecl_symbol_value(VV[8]))==(ECL_T))) { goto L17; }
   cl_error(3, _ecl_static_5, v3superclass, v1class);
L17:;
   goto L7;
L8:;
   goto L1;
  }
L2:;
  if (Null(si_of_class_p(2, v1class, ECL_SYM("STANDARD-CLASS",973)))) { goto L23; }
  T0 = ECL_SYM("STANDARD-OBJECT",976);
  goto L22;
L23:;
  if (Null(si_of_class_p(2, v1class, ECL_SYM("STRUCTURE-CLASS",977)))) { goto L25; }
  T0 = ECL_SYM("STRUCTURE-OBJECT",978);
  goto L22;
L25:;
  if (Null(si_of_class_p(2, v1class, ECL_SYM("FUNCALLABLE-STANDARD-CLASS",1516)))) { goto L27; }
  T0 = ECL_SYM("FUNCALLABLE-STANDARD-OBJECT",1518);
  goto L22;
L27:;
  T1 = cl_class_of(v1class);
  T0 = cl_error(2, _ecl_static_6, T1);
L22:;
  T1 = cl_find_class(1, T0);
  v2supplied_superclasses = ecl_list1(T1);
L1:;
  value0 = v2supplied_superclasses;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G166                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC26__g166(cl_object v1class, cl_object v2superclass)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_make_bool((v2superclass)==(ecl_symbol_value(ECL_SYM("+THE-T-CLASS+",1477))));
  if ((value0)!=ECL_NIL) { goto L2; }
  {
   cl_object v3;
   cl_object v4;
   v3 = cl_class_of(v1class);
   v4 = cl_class_of(v2superclass);
   value0 = ecl_make_bool((v3)==(v4));
   if ((value0)!=ECL_NIL) { goto L8; }
   if (!((v3)==(ecl_symbol_value(ECL_SYM("+THE-STANDARD-CLASS+",1480))))) { goto L12; }
   value0 = ecl_make_bool((v4)==(ecl_symbol_value(ECL_SYM("+THE-FUNCALLABLE-STANDARD-CLASS+",1481))));
   goto L10;
L12:;
   value0 = ECL_NIL;
   goto L10;
L10:;
   if ((value0)!=ECL_NIL) { goto L8; }
   if (!((v4)==(ecl_symbol_value(ECL_SYM("+THE-STANDARD-CLASS+",1480))))) { goto L15; }
   value0 = ecl_make_bool((v3)==(ecl_symbol_value(ECL_SYM("+THE-FUNCALLABLE-STANDARD-CLASS+",1481))));
   goto L4;
L15:;
   value0 = ECL_NIL;
   goto L4;
L8:;
   goto L4;
  }
L4:;
  if ((value0)!=ECL_NIL) { goto L2; }
  value0 = L27forward_referenced_class_p(v2superclass);
  return value0;
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for FORWARD-REFERENCED-CLASS-P            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L27forward_referenced_class_p(cl_object v1x)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2y;
   v2y = cl_find_class(2, ECL_SYM("FORWARD-REFERENCED-CLASS",1515), ECL_NIL);
   if (Null(v2y)) { goto L3; }
   T0 = cl_class_of(v1x);
   value0 = si_subclassp(2, T0, v2y);
   return value0;
L3:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G200                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC28__g200(cl_object v1class)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2cpl;
   v2cpl = ecl_function_dispatch(cl_env_copy,ECL_SYM("COMPUTE-CLASS-PRECEDENCE-LIST",1496))(1, v1class) /*  COMPUTE-CLASS-PRECEDENCE-LIST */;
   {
    cl_object v3x;
    T0 = (VV[13]->symbol.gfdef);
    T1 = ecl_cdr(v2cpl);
    v3x = cl_find_if(2, T0, T1);
    if (Null(v3x)) { goto L3; }
    T0 = (cl_env_copy->function=(ECL_SYM("CLASS-NAME",934)->symbol.gfdef))->cfun.entry(1, v1class) /*  CLASS-NAME */;
    T1 = (cl_env_copy->function=(ECL_SYM("CLASS-NAME",934)->symbol.gfdef))->cfun.entry(1, v3x) /*  CLASS-NAME */;
    cl_error(3, _ecl_static_7, T0, T1);
   }
L3:;
   {
    cl_object v3x;
    T0 = (ECL_SYM("CLASS-FINALIZED-P",1491)->symbol.gfdef);
    v3x = cl_find_if_not(4, T0, v2cpl, VV[14], ECL_T);
    if (v3x==ECL_NIL) { goto L7; }
    if ((v3x)==(v1class)) { goto L7; }
    value0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("FINALIZE-INHERITANCE",1513))(1, v3x) /*  FINALIZE-INHERITANCE */;
    return value0;
   }
L7:;
   (cl_env_copy->function=ECL_CONS_CAR(VV[52]))->cfun.entry(2, v2cpl, v1class) /*  (SETF CLASS-PRECEDENCE-LIST) */;
   {
    cl_object v3slots;
    v3slots = ecl_function_dispatch(cl_env_copy,ECL_SYM("COMPUTE-SLOTS",1501))(1, v1class) /*  COMPUTE-SLOTS */;
    (cl_env_copy->function=ECL_CONS_CAR(VV[53]))->cfun.entry(2, v3slots, v1class) /*  (SETF CLASS-SLOTS) */;
    {
     cl_object v4;
     v4 = L4compute_instance_size(v3slots);
     (cl_env_copy->function=ECL_CONS_CAR(VV[54]))->cfun.entry(2, v4, v1class) /*  (SETF CLASS-SIZE) */;
    }
    {
     cl_object v4;
     v4 = ecl_function_dispatch(cl_env_copy,ECL_SYM("COMPUTE-DEFAULT-INITARGS",1497))(1, v1class) /*  COMPUTE-DEFAULT-INITARGS */;
     (cl_env_copy->function=ECL_CONS_CAR(VV[55]))->cfun.entry(2, v4, v1class) /*  (SETF CLASS-DEFAULT-INITARGS) */;
    }
    (cl_env_copy->function=ECL_CONS_CAR(VV[56]))->cfun.entry(2, ECL_T, v1class) /*  (SETF CLASS-FINALIZED-P) */;
   }
   if (Null(ecl_function_dispatch(cl_env_copy,VV[57])(1, v1class) /*  CLASS-SEALEDP */)) { goto L20; }
   {
    cl_object v3free_slots;
    cl_object v4all_slots;
    {
     cl_object v5;
     cl_object v6;
     cl_object v7;
     v5 = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-SLOTS",1494))(1, v1class) /*  CLASS-SLOTS */;
     v6 = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
     v7 = v5;
     {
      cl_object v8;
      cl_object v9;
      v8 = ecl_list1(ECL_NIL);
      v9 = v8;
L30:;
      if (!(ecl_endp(v7))) { goto L32; }
      goto L31;
L32:;
      v6 = _ecl_car(v7);
      {
       cl_object v10;
       v10 = _ecl_cdr(v7);
       if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
       v7 = v10;
      }
      if (ecl_unlikely(ECL_ATOM(v9))) FEtype_error_cons(v9);
      T1 = v9;
      T2 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v6) /*  SLOT-DEFINITION-NAME */;
      v9 = ecl_list1(T2);
      (ECL_CONS_CDR(T1)=v9,T1);
      goto L30;
L31:;
      T0 = ecl_cdr(v8);
      goto L23;
     }
    }
L23:;
    v3free_slots = cl_delete_duplicates(1, T0);
    v4all_slots = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-SLOTS",1494))(1, v1class) /*  CLASS-SLOTS */;
    {
     cl_object v5c;
     cl_object v6;
     v5c = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v2cpl))) FEtype_error_list(v2cpl);
     v6 = v2cpl;
L51:;
     if (!(ecl_endp(v6))) { goto L53; }
     goto L52;
L53:;
     v5c = _ecl_car(v6);
     {
      cl_object v7;
      v7 = _ecl_cdr(v6);
      if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
      v6 = v7;
     }
     {
      cl_object v7;
      cl_object v8slotd;
      cl_object v9;
      v7 = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-DIRECT-SLOTS",1488))(1, v5c) /*  CLASS-DIRECT-SLOTS */;
      v8slotd = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
      v9 = v7;
L66:;
      if (!(ecl_endp(v9))) { goto L68; }
      goto L67;
L68:;
      v8slotd = _ecl_car(v9);
      {
       cl_object v10;
       v10 = _ecl_cdr(v9);
       if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
       v9 = v10;
      }
      if (Null(L33safe_slot_definition_location(1, v8slotd))) { goto L76; }
      T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v8slotd) /*  SLOT-DEFINITION-NAME */;
      v3free_slots = cl_delete(2, T0, v3free_slots);
L76:;
      goto L66;
L67:;
     }
     goto L51;
L52:;
    }
    {
     cl_object v5;
     cl_object v6slotd;
     cl_object v7;
     v5 = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-DIRECT-SLOTS",1488))(1, v1class) /*  CLASS-DIRECT-SLOTS */;
     v6slotd = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
     v7 = v5;
L86:;
     if (!(ecl_endp(v7))) { goto L88; }
     goto L87;
L88:;
     v6slotd = _ecl_car(v7);
     {
      cl_object v8;
      v8 = _ecl_cdr(v7);
      if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
      v7 = v8;
     }
     {
      cl_object v8name;
      cl_object v9other_slotd;
      v8name = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v6slotd) /*  SLOT-DEFINITION-NAME */;
      {
       cl_object v10;
       v10 = si_make_seq_iterator(2, v4all_slots, ecl_make_fixnum(0));
L100:;
       if ((v10)!=ECL_NIL) { goto L102; }
       v9other_slotd = ECL_NIL;
       goto L98;
L102:;
       {
        cl_object v11;
        v11 = si_seq_iterator_ref(v4all_slots, v10);
        T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v11) /*  SLOT-DEFINITION-NAME */;
        if (!(ecl_eql(v8name,T0))) { goto L104; }
        v9other_slotd = v11;
        goto L98;
       }
L104:;
       v10 = si_seq_iterator_next(v4all_slots, v10);
       goto L100;
      }
L98:;
      {
       cl_object v10;
       v10 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-LOCATION",1547))(1, v9other_slotd) /*  SLOT-DEFINITION-LOCATION */;
       (cl_env_copy->function=ECL_CONS_CAR(VV[58]))->cfun.entry(2, v10, v6slotd) /*  (SETF SLOT-DEFINITION-LOCATION) */;
      }
      v3free_slots = cl_delete(2, v8name, v3free_slots);
     }
     goto L86;
L87:;
    }
    {
     cl_object v5name;
     cl_object v6;
     v5name = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v3free_slots))) FEtype_error_list(v3free_slots);
     v6 = v3free_slots;
     {
      cl_object v7direct_slots;
      v7direct_slots = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-DIRECT-SLOTS",1488))(1, v1class) /*  CLASS-DIRECT-SLOTS */;
L117:;
      if (!(ecl_endp(v6))) { goto L119; }
      goto L118;
L119:;
      v5name = _ecl_car(v6);
      {
       cl_object v8;
       v8 = _ecl_cdr(v6);
       if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
       v6 = v8;
      }
      {
       cl_object v8effective_slotd;
       cl_object v9def;
       {
        cl_object v10;
        v10 = si_make_seq_iterator(2, v4all_slots, ecl_make_fixnum(0));
L130:;
        if ((v10)!=ECL_NIL) { goto L132; }
        v8effective_slotd = ECL_NIL;
        goto L128;
L132:;
        {
         cl_object v11;
         v11 = si_seq_iterator_ref(v4all_slots, v10);
         T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v11) /*  SLOT-DEFINITION-NAME */;
         if (!(ecl_eql(v5name,T0))) { goto L134; }
         v8effective_slotd = v11;
         goto L128;
        }
L134:;
        v10 = si_seq_iterator_next(v4all_slots, v10);
        goto L130;
       }
L128:;
       v9def = ecl_function_dispatch(cl_env_copy,VV[59])(1, v8effective_slotd) /*  DIRECT-SLOT-TO-CANONICAL-SLOT */;
       T0 = (ECL_SYM("MAKE-INSTANCE",949)->symbol.gfdef);
       T1 = ecl_function_dispatch(cl_env_copy,ECL_SYM("DIRECT-SLOT-DEFINITION-CLASS",1503))(2, v1class, v9def) /*  DIRECT-SLOT-DEFINITION-CLASS */;
       T2 = cl_apply(3, T0, T1, v9def);
       v7direct_slots = CONS(T2,v7direct_slots);
      }
      goto L117;
L118:;
      (cl_env_copy->function=ECL_CONS_CAR(VV[60]))->cfun.entry(2, v7direct_slots, v1class) /*  (SETF CLASS-DIRECT-SLOTS) */;
     }
    }
   }
L20:;
   ecl_function_dispatch(cl_env_copy,VV[61])(0)   /*  SUBTYPEP-CLEAR-CACHE */;
  }
  {
   cl_object v2;
   T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-DIRECT-SUBCLASSES",1489))(1, v1class) /*  CLASS-DIRECT-SUBCLASSES */;
   v2 = cl_reverse(T0);
   goto L148;
L147:;
   {
    cl_object v3subclass;
    v3subclass = ecl_car(v2);
    L12finalize_unless_forward(v3subclass);
   }
   v2 = ecl_cdr(v2);
L148:;
   if (Null(v2)) { goto L155; }
   goto L147;
L155:;
  }
  value0 = ecl_function_dispatch(cl_env_copy,VV[62])(1, v1class) /*  STD-CREATE-SLOTS-TABLE */;
  return value0;
 }
}
/*	local function G255                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC29__g255(cl_object v1class)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)))) { goto L2; }
  T0 = ecl_car(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
  T1 = ecl_cdr(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
  ecl_function_dispatch(cl_env_copy,T0)(2, ecl_symbol_value(ECL_SYM(".COMBINED-METHOD-ARGS.",1473)), T1);
  goto L1;
L2:;
  cl_error(1, _ecl_static_4);
L1:;
  value0 = ecl_function_dispatch(cl_env_copy,VV[63])(1, v1class) /*  STD-CLASS-GENERATE-ACCESSORS */;
  return value0;
 }
}
/*	local function G256                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC30__g256(cl_object v1class)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-DIRECT-SUPERCLASSES",1490))(1, v1class) /*  CLASS-DIRECT-SUPERCLASSES */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[64])(2, v1class, T0) /*  COMPUTE-CLOS-CLASS-PRECEDENCE-LIST */;
  return value0;
 }
}
/*	local function G264                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC31__g264(cl_object v1class)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2all_slots;
   cl_object v3all_names;
   cl_object v4output;
   cl_object v5scan;
   T0 = (ECL_SYM("APPEND",88)->symbol.gfdef);
   {
    cl_object v6;
    cl_object v7;
    cl_object v8;
    T2 = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-PRECEDENCE-LIST",1492))(1, v1class) /*  CLASS-PRECEDENCE-LIST */;
    v6 = cl_reverse(T2);
    v7 = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
    v8 = v6;
    {
     cl_object v9;
     cl_object v10;
     v9 = ecl_list1(ECL_NIL);
     v10 = v9;
L10:;
     if (!(ecl_endp(v8))) { goto L12; }
     goto L11;
L12:;
     v7 = _ecl_car(v8);
     {
      cl_object v11;
      v11 = _ecl_cdr(v8);
      if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
      v8 = v11;
     }
     if (ecl_unlikely(ECL_ATOM(v10))) FEtype_error_cons(v10);
     T2 = v10;
     T3 = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-DIRECT-SLOTS",1488))(1, v7) /*  CLASS-DIRECT-SLOTS */;
     v10 = ecl_list1(T3);
     (ECL_CONS_CDR(T2)=v10,T2);
     goto L10;
L11:;
     T1 = ecl_cdr(v9);
     goto L3;
    }
   }
L3:;
   v2all_slots = cl_reduce(2, T0, T1);
   {
    cl_object v6;
    cl_object v7;
    v6 = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v2all_slots))) FEtype_error_list(v2all_slots);
    v7 = v2all_slots;
    {
     cl_object v8;
     cl_object v9;
     v8 = ecl_list1(ECL_NIL);
     v9 = v8;
L33:;
     if (!(ecl_endp(v7))) { goto L35; }
     goto L34;
L35:;
     v6 = _ecl_car(v7);
     {
      cl_object v10;
      v10 = _ecl_cdr(v7);
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      v7 = v10;
     }
     if (ecl_unlikely(ECL_ATOM(v9))) FEtype_error_cons(v9);
     T1 = v9;
     T2 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v6) /*  SLOT-DEFINITION-NAME */;
     v9 = ecl_list1(T2);
     (ECL_CONS_CDR(T1)=v9,T1);
     goto L33;
L34:;
     T0 = ecl_cdr(v8);
     goto L27;
    }
   }
L27:;
   v3all_names = cl_nreverse(T0);
   v4output = ECL_NIL;
   v5scan = v3all_names;
   goto L53;
L52:;
   {
    cl_object v6name;
    v6name = ecl_car(v5scan);
    {
     cl_object v7;
     cl_object v8;
     v7 = ecl_cdr(v5scan);
     v8 = si_make_seq_iterator(2, v7, ecl_make_fixnum(0));
L60:;
     if ((v8)!=ECL_NIL) { goto L62; }
     goto L57;
L62:;
     {
      cl_object v9;
      v9 = si_seq_iterator_ref(v7, v8);
      if (!(ecl_eql(v6name,v9))) { goto L64; }
      if ((v9)!=ECL_NIL) { goto L55; }
      goto L57;
     }
L64:;
     v8 = si_seq_iterator_next(v7, v8);
     goto L60;
    }
L57:;
    T0 = cl_reverse(v2all_slots);
    T1 = (ECL_SYM("SLOT-DEFINITION-NAME",1548)->symbol.gfdef);
    T2 = (ECL_SYM("EQ",333)->symbol.gfdef);
    T3 = cl_delete(6, v6name, T0, ECL_SYM("KEY",1262), T1, ECL_SYM("TEST-NOT",1317), T2);
    T4 = ecl_function_dispatch(cl_env_copy,ECL_SYM("COMPUTE-EFFECTIVE-SLOT-DEFINITION",1500))(3, v1class, v6name, T3) /*  COMPUTE-EFFECTIVE-SLOT-DEFINITION */;
    v4output = CONS(T4,v4output);
   }
L55:;
   v5scan = ecl_cdr(v5scan);
L53:;
   if (ecl_endp(v5scan)) { goto L74; }
   goto L52;
L74:;
   value0 = v4output;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for SLOT-DEFINITION-TO-PLIST              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L32slot_definition_to_plist(cl_object v1slotd)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v1slotd) /*  SLOT-DEFINITION-NAME */;
  T1 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-INITFORM",1545))(1, v1slotd) /*  SLOT-DEFINITION-INITFORM */;
  T2 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-INITFUNCTION",1546))(1, v1slotd) /*  SLOT-DEFINITION-INITFUNCTION */;
  T3 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-TYPE",1550))(1, v1slotd) /*  SLOT-DEFINITION-TYPE */;
  T4 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-ALLOCATION",1543))(1, v1slotd) /*  SLOT-DEFINITION-ALLOCATION */;
  T5 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-INITARGS",1544))(1, v1slotd) /*  SLOT-DEFINITION-INITARGS */;
  T6 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-READERS",1549))(1, v1slotd) /*  SLOT-DEFINITION-READERS */;
  T7 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-WRITERS",1551))(1, v1slotd) /*  SLOT-DEFINITION-WRITERS */;
  T8 = ecl_function_dispatch(cl_env_copy,VV[66])(1, v1slotd) /*  SLOT-DEFINITION-DOCUMENTATION */;
  T9 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-LOCATION",1547))(1, v1slotd) /*  SLOT-DEFINITION-LOCATION */;
  value0 = cl_list(20, ECL_SYM("NAME",1273), T0, ECL_SYM("INITFORM",996), T1, ECL_SYM("INITFUNCTION",997), T2, ECL_SYM("TYPE",1318), T3, ECL_SYM("ALLOCATION",985), T4, ECL_SYM("INITARGS",995), T5, ECL_SYM("READERS",1007), T6, ECL_SYM("WRITERS",1010), T7, ECL_SYM("DOCUMENTATION",1222), T8, ECL_SYM("LOCATION",999), T9);
  return value0;
 }
}
/*	function definition for SAFE-SLOT-DEFINITION-LOCATION         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L33safe_slot_definition_location(cl_narg narg, cl_object v1slotd, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2default;
  va_list args; va_start(args,v1slotd);
  {
   int i = 1;
   if (i >= narg) {
    v2default = ECL_NIL;
   } else {
    i++;
    v2default = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (ECL_LISTP(v1slotd)) { goto L4; }
  if (Null(cl_slot_boundp(v1slotd, ECL_SYM("LOCATION",1763)))) { goto L2; }
  goto L3;
L4:;
L3:;
  value0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-LOCATION",1547))(1, v1slotd) /*  SLOT-DEFINITION-LOCATION */;
  return value0;
L2:;
  value0 = v2default;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G344                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC36__g344(cl_object v1class, cl_object v2name, cl_object v3direct_slots)
{
 cl_object T0, T1, T2;
 volatile cl_object lex0[1];
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  lex0[0] = v1class;                              /*  CLASS           */
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v2name,env0);                /*  NAME            */
  {cl_object v4;
   v4 = ECL_NIL;
   v4 = ecl_make_cclosure_va((cl_objectfn)LC35combine_slotds,env0,Cblock);
   T0 = ecl_cdr(v3direct_slots);
   T2 = ecl_car(v3direct_slots);
   T1 = LC34direct_to_effective(lex0, T2);
   value0 = cl_reduce(4, v4, T0, VV[17], T1);
   return value0;
  }
 }
}
/*	closure COMBINE-SLOTDS                                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC35combine_slotds(cl_narg narg, cl_object v1new_slotd, cl_object v2old_slotd, ...)
{
 cl_object T0, T1;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  NAME            */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  {
   cl_object v3new_type;
   cl_object v4old_type;
   cl_object v5loc1;
   cl_object v6loc2;
   v3new_type = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-TYPE",1550))(1, v1new_slotd) /*  SLOT-DEFINITION-TYPE */;
   v4old_type = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-TYPE",1550))(1, v2old_slotd) /*  SLOT-DEFINITION-TYPE */;
   v5loc1 = L33safe_slot_definition_location(1, v1new_slotd);
   v6loc2 = L33safe_slot_definition_location(1, v2old_slotd);
   if (Null(v6loc2)) { goto L5; }
   if (Null(v5loc1)) { goto L7; }
   if (ecl_eql(v5loc1,v6loc2)) { goto L5; }
   T0 = cl_list(3, v5loc1, v6loc2, ECL_CONS_CAR(CLV0));
   cl_error(5, ECL_SYM("SIMPLE-ERROR",770), ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_8, ECL_SYM("FORMAT-ARGUMENTS",1239), T0);
   goto L5;
L7:;
   (cl_env_copy->function=ECL_CONS_CAR(VV[58]))->cfun.entry(2, v6loc2, v1new_slotd) /*  (SETF SLOT-DEFINITION-LOCATION) */;
L5:;
   {
    cl_object v7;
    T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-INITARGS",1544))(1, v1new_slotd) /*  SLOT-DEFINITION-INITARGS */;
    T1 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-INITARGS",1544))(1, v2old_slotd) /*  SLOT-DEFINITION-INITARGS */;
    v7 = cl_union(2, T0, T1);
    (cl_env_copy->function=ECL_CONS_CAR(VV[68]))->cfun.entry(2, v7, v1new_slotd) /*  (SETF SLOT-DEFINITION-INITARGS) */;
   }
   if ((ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-INITFUNCTION",1546))(1, v1new_slotd) /*  SLOT-DEFINITION-INITFUNCTION */)!=ECL_NIL) { goto L12; }
   {
    cl_object v7;
    v7 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-INITFORM",1545))(1, v2old_slotd) /*  SLOT-DEFINITION-INITFORM */;
    (cl_env_copy->function=ECL_CONS_CAR(VV[69]))->cfun.entry(2, v7, v1new_slotd) /*  (SETF SLOT-DEFINITION-INITFORM) */;
   }
   {
    cl_object v7;
    v7 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-INITFUNCTION",1546))(1, v2old_slotd) /*  SLOT-DEFINITION-INITFUNCTION */;
    (cl_env_copy->function=ECL_CONS_CAR(VV[70]))->cfun.entry(2, v7, v1new_slotd) /*  (SETF SLOT-DEFINITION-INITFUNCTION) */;
   }
L12:;
   {
    cl_object v7;
    T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-READERS",1549))(1, v1new_slotd) /*  SLOT-DEFINITION-READERS */;
    T1 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-READERS",1549))(1, v2old_slotd) /*  SLOT-DEFINITION-READERS */;
    v7 = cl_union(2, T0, T1);
    (cl_env_copy->function=ECL_CONS_CAR(VV[71]))->cfun.entry(2, v7, v1new_slotd) /*  (SETF SLOT-DEFINITION-READERS) */;
   }
   {
    cl_object v7;
    T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-WRITERS",1551))(1, v1new_slotd) /*  SLOT-DEFINITION-WRITERS */;
    T1 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-WRITERS",1551))(1, v2old_slotd) /*  SLOT-DEFINITION-WRITERS */;
    v7 = cl_union(2, T0, T1);
    (cl_env_copy->function=ECL_CONS_CAR(VV[72]))->cfun.entry(2, v7, v1new_slotd) /*  (SETF SLOT-DEFINITION-WRITERS) */;
   }
   {
    cl_object v7;
    if (Null(cl_subtypep(2, v3new_type, v4old_type))) { goto L23; }
    v7 = v3new_type;
    goto L22;
L23:;
    if (Null(cl_subtypep(2, v4old_type, v3new_type))) { goto L25; }
    v7 = v4old_type;
    goto L22;
L25:;
    v7 = cl_list(3, ECL_SYM("AND",87), v3new_type, v4old_type);
L22:;
    (cl_env_copy->function=ECL_CONS_CAR(VV[73]))->cfun.entry(2, v7, v1new_slotd) /*  (SETF SLOT-DEFINITION-TYPE) */;
   }
   value0 = v1new_slotd;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
 }
}
/*	local function DIRECT-TO-EFFECTIVE                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC34direct_to_effective(volatile cl_object *lex0, cl_object v1old_slot)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_CONSP(v1old_slot))) { goto L1; }
  value0 = cl_copy_list(v1old_slot);
  return value0;
L1:;
  {
   cl_object v2initargs;
   v2initargs = L32slot_definition_to_plist(v1old_slot);
   T0 = (ECL_SYM("MAKE-INSTANCE",949)->symbol.gfdef);
   T1 = (ECL_SYM("EFFECTIVE-SLOT-DEFINITION-CLASS",1505)->symbol.gfdef);
   T2 = cl_apply(3, T1, lex0[0], v2initargs);
   value0 = cl_apply(3, T0, T2, v2initargs);
   return value0;
  }
 }
}
/*	local function G359                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC37__g359(cl_object v1class)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2all_initargs;
   T0 = (ECL_SYM("APPEND",88)->symbol.gfdef);
   {
    cl_object v3;
    cl_object v4;
    cl_object v5;
    v3 = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-PRECEDENCE-LIST",1492))(1, v1class) /*  CLASS-PRECEDENCE-LIST */;
    v4 = ECL_NIL;
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
     v4 = _ecl_car(v5);
     {
      cl_object v8;
      v8 = _ecl_cdr(v5);
      if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
      v5 = v8;
     }
     if (ecl_unlikely(ECL_ATOM(v7))) FEtype_error_cons(v7);
     T2 = v7;
     T3 = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-DIRECT-DEFAULT-INITARGS",1487))(1, v4) /*  CLASS-DIRECT-DEFAULT-INITARGS */;
     v7 = ecl_list1(T3);
     (ECL_CONS_CDR(T2)=v7,T2);
     goto L10;
L11:;
     T1 = ecl_cdr(v6);
     goto L3;
    }
   }
L3:;
   v2all_initargs = cl_reduce(2, T0, T1);
   T0 = cl_reverse(v2all_initargs);
   T1 = (ECL_SYM("FIRST",371)->symbol.gfdef);
   T2 = cl_remove_duplicates(3, T0, ECL_SYM("KEY",1262), T1);
   value0 = cl_nreverse(T2);
   return value0;
  }
 }
}
/*	local function G372                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC38__g372(cl_narg narg, cl_object v1class, cl_object v2name, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3rest;
  cl_object v4direct_slots;
  cl_object v5direct_default_initargs;
  ecl_va_list args; ecl_va_start(args,v2name,narg,2);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,LC38__g372keys,keyvars,(cl_object*)&v3rest,TRUE);
   ecl_va_end(args);
   v4direct_slots = keyvars[0];
   v5direct_default_initargs = keyvars[1];
  }
  {
   cl_object v7;                                  /*  METACLASS       */
   cl_object v8;                                  /*  OPTIONS         */
   T0 = (VV[20]->symbol.gfdef);
   value0 = cl_apply(2, T0, v3rest);
   v7 = value0;
   {
    const int v9 = cl_env_copy->nvalues;
    cl_object v10;
    v10 = (v9<=2)? ECL_NIL : cl_env_copy->values[2];
    v8 = v10;
   }
   if (Null(L27forward_referenced_class_p(v1class))) { goto L4; }
   (cl_env_copy->function=(ECL_SYM("CHANGE-CLASS",932)->symbol.gfdef))->cfun.entry(2, v1class, v7) /*  CHANGE-CLASS */;
   goto L3;
L4:;
   T0 = cl_class_of(v1class);
   if ((T0)==(v7)) { goto L3; }
   cl_error(1, _ecl_static_9);
L3:;
   T0 = (ECL_SYM("REINITIALIZE-INSTANCE",963)->symbol.gfdef);
   v1class = cl_apply(5, T0, v1class, ECL_SYM("NAME",1273), v2name, v8);
   if (Null(v2name)) { goto L10; }
   ecl_function_dispatch(cl_env_copy,ECL_SYM("CREATE-TYPE-NAME",1585))(1, v2name) /*  CREATE-TYPE-NAME */;
   ecl_function_dispatch(cl_env_copy,VV[76])(2, v1class, v2name) /*  SETF-FIND-CLASS */;
L10:;
   value0 = v1class;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for COERCE-TO-CLASS                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L39coerce_to_class(cl_narg narg, cl_object v1class_or_symbol, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2fail;
  va_list args; va_start(args,v1class_or_symbol);
  {
   int i = 1;
   if (i >= narg) {
    v2fail = ECL_NIL;
   } else {
    i++;
    v2fail = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (!(ECL_INSTANCEP(v1class_or_symbol))) { goto L2; }
  value0 = v1class_or_symbol;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  if (ECL_SYMBOLP(v1class_or_symbol)) { goto L4; }
  value0 = cl_error(2, _ecl_static_10, v1class_or_symbol);
  return value0;
L4:;
  {
   cl_object v3;
   v3 = cl_find_class(2, v1class_or_symbol, v2fail);
   if (Null(v3)) { goto L7; }
   value0 = v3;
   cl_env_copy->nvalues = 1;
   return value0;
L7:;
   T0 = ecl_list1(v1class_or_symbol);
   (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(5, VV[18], ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_11, ECL_SYM("FORMAT-ARGUMENTS",1239), T0) /*  WARN */;
   T0 = cl_find_class(1, ECL_SYM("STANDARD-OBJECT",976));
   T1 = ecl_list1(T0);
   value0 = clos_ensure_class(7, v1class_or_symbol, ECL_SYM("METACLASS",1000), ECL_SYM("FORWARD-REFERENCED-CLASS",1515), ECL_SYM("DIRECT-SUPERCLASSES",991), T1, ECL_SYM("DIRECT-SLOTS",990), ECL_NIL);
   return value0;
  }
 }
}
/*	function definition for HELP-ENSURE-CLASS                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L40help_ensure_class(cl_narg narg, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1options;
  cl_object v2metaclass;
  cl_object v3direct_superclasses;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L40help_ensure_classkeys,keyvars,(cl_object*)&v1options,TRUE);
   ecl_va_end(args);
   if (Null(keyvars[2])) {
    v2metaclass = ECL_SYM("STANDARD-CLASS",973);
   } else {
    v2metaclass = keyvars[0];
   }
   v3direct_superclasses = keyvars[1];
  }
  {
   cl_object v5;
   cl_object v6;                                  /*  FLAG            */
   value0 = si_rem_f(v1options, ECL_SYM("METACLASS",1000));
   v5 = value0;
   v6 = cl_env_copy->values[1];
   v1options = v5;
  }
  {
   cl_object v5;
   cl_object v6;                                  /*  FLAG            */
   value0 = si_rem_f(v1options, ECL_SYM("DIRECT-SUPERCLASSES",991));
   v5 = value0;
   v6 = cl_env_copy->values[1];
   v1options = v5;
  }
  v2metaclass = L39coerce_to_class(2, v2metaclass, ECL_T);
  {
   cl_object v4;
   cl_object v5;
   v4 = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v3direct_superclasses))) FEtype_error_list(v3direct_superclasses);
   v5 = v3direct_superclasses;
   {
    cl_object v6;
    cl_object v7;
    v6 = ecl_list1(ECL_NIL);
    v7 = v6;
L19:;
    if (!(ecl_endp(v5))) { goto L21; }
    goto L20;
L21:;
    v4 = _ecl_car(v5);
    {
     cl_object v8;
     v8 = _ecl_cdr(v5);
     if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
     v5 = v8;
    }
    if (ecl_unlikely(ECL_ATOM(v7))) FEtype_error_cons(v7);
    T0 = v7;
    T1 = L39coerce_to_class(1, v4);
    v7 = ecl_list1(T1);
    (ECL_CONS_CDR(T0)=v7,T0);
    goto L19;
L20:;
    v3direct_superclasses = ecl_cdr(v6);
    goto L13;
   }
  }
L13:;
  T0 = cl_listX(3, ECL_SYM("DIRECT-SUPERCLASSES",991), v3direct_superclasses, v1options);
  cl_env_copy->nvalues = 3;
  cl_env_copy->values[2] = T0;
  cl_env_copy->values[1] = v3direct_superclasses;
  cl_env_copy->values[0] = v2metaclass;
  return cl_env_copy->values[0];
 }
}
/*	function definition for CLASS-COMPUTE-SLOTS                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L41class_compute_slots(cl_object v1class, cl_object v2slots)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3size;
   cl_object v4instance_slots;
   cl_object v5numbered_slots;
   cl_object v6other_slots;
   cl_object v7aux;
   v3size = L4compute_instance_size(v2slots);
   T0 = (ECL_SYM("SLOT-DEFINITION-ALLOCATION",1543)->symbol.gfdef);
   T1 = (ECL_SYM("EQ",333)->symbol.gfdef);
   v4instance_slots = cl_remove(6, ECL_SYM("INSTANCE",1256), v2slots, ECL_SYM("KEY",1262), T0, ECL_SYM("TEST-NOT",1317), T1);
   T0 = (VV[16]->symbol.gfdef);
   v5numbered_slots = cl_remove_if_not(2, T0, v4instance_slots);
   T0 = (VV[16]->symbol.gfdef);
   v6other_slots = cl_remove_if(2, T0, v4instance_slots);
   T0 = si_make_pure_array(ECL_T, v3size, ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
   v7aux = si_fill_array_with_elt(T0, ECL_NIL, ecl_make_fixnum(0), ECL_NIL);
   {
    cl_object v8i;
    cl_object v9;
    v8i = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v5numbered_slots))) FEtype_error_list(v5numbered_slots);
    v9 = v5numbered_slots;
L14:;
    if (!(ecl_endp(v9))) { goto L16; }
    goto L15;
L16:;
    v8i = _ecl_car(v9);
    {
     cl_object v10;
     v10 = _ecl_cdr(v9);
     if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
     v9 = v10;
    }
    {
     cl_object v10loc;
     v10loc = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-LOCATION",1547))(1, v8i) /*  SLOT-DEFINITION-LOCATION */;
     {
      cl_fixnum v11;
      if (ecl_unlikely((ecl_fixnum(v10loc))>=(v7aux)->vector.dim))
           FEwrong_index(ECL_NIL,v7aux,-1,ecl_make_fixnum(ecl_fixnum(v10loc)),(v7aux)->vector.dim);
      v11 = ecl_fixnum(v10loc);
      if (Null(ecl_aref_unsafe(v7aux,v11))) { goto L26; }
     }
     {
      cl_fixnum v11;
      if (ecl_unlikely((ecl_fixnum(v10loc))>=(v7aux)->vector.dim))
           FEwrong_index(ECL_NIL,v7aux,-1,ecl_make_fixnum(ecl_fixnum(v10loc)),(v7aux)->vector.dim);
      v11 = ecl_fixnum(v10loc);
      T0 = ecl_aref_unsafe(v7aux,v11);
     }
     T1 = cl_list(3, T0, v8i, v1class);
     cl_error(5, ECL_SYM("SIMPLE-ERROR",770), ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_12, VV[21], T1);
L26:;
     {
      cl_fixnum v11;
      if (ecl_unlikely((ecl_fixnum(v10loc))>=(v7aux)->vector.dim))
           FEwrong_index(ECL_NIL,v7aux,-1,ecl_make_fixnum(ecl_fixnum(v10loc)),(v7aux)->vector.dim);
      v11 = ecl_fixnum(v10loc);
      (v7aux)->vector.self.t[v11]= v8i;
     }
    }
    goto L14;
L15:;
   }
   {
    cl_object v8i;
    cl_object v9;
    v8i = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v6other_slots))) FEtype_error_list(v6other_slots);
    v9 = v6other_slots;
    {
     cl_object v10index;
     v10index = ecl_make_fixnum(0);
L44:;
     if (!(ecl_endp(v9))) { goto L46; }
     goto L45;
L46:;
     v8i = _ecl_car(v9);
     {
      cl_object v11;
      v11 = _ecl_cdr(v9);
      if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
      v9 = v11;
     }
L55:;
     {
      cl_fixnum v11;
      if (ecl_unlikely((ecl_fixnum(v10index))>=(v7aux)->vector.dim))
           FEwrong_index(ECL_NIL,v7aux,-1,ecl_make_fixnum(ecl_fixnum(v10index)),(v7aux)->vector.dim);
      v11 = ecl_fixnum(v10index);
      if ((ecl_aref_unsafe(v7aux,v11))!=ECL_NIL) { goto L57; }
     }
     goto L56;
L57:;
     v10index = ecl_plus(v10index,ecl_make_fixnum(1));
     goto L55;
L56:;
     {
      cl_fixnum v11;
      if (ecl_unlikely((ecl_fixnum(v10index))>=(v7aux)->vector.dim))
           FEwrong_index(ECL_NIL,v7aux,-1,ecl_make_fixnum(ecl_fixnum(v10index)),(v7aux)->vector.dim);
      v11 = ecl_fixnum(v10index);
      (v7aux)->vector.self.t[v11]= v8i;
     }
     (cl_env_copy->function=ECL_CONS_CAR(VV[58]))->cfun.entry(2, v10index, v8i) /*  (SETF SLOT-DEFINITION-LOCATION) */;
     goto L44;
L45:;
    }
   }
   value0 = v2slots;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G407                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC42__g407(cl_object v1class)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)))) { goto L2; }
  T1 = ecl_car(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
  T2 = ecl_cdr(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
  T0 = ecl_function_dispatch(cl_env_copy,T1)(2, ecl_symbol_value(ECL_SYM(".COMBINED-METHOD-ARGS.",1473)), T2);
  goto L1;
L2:;
  T0 = cl_error(1, _ecl_static_4);
L1:;
  value0 = L41class_compute_slots(v1class, T0);
  return value0;
 }
}
/*	function definition for STD-CLASS-COMPUTE-SLOTS               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L43std_class_compute_slots(cl_object v1class, cl_object v2slots)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3direct_slots;
   v3direct_slots = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-DIRECT-SLOTS",1488))(1, v1class) /*  CLASS-DIRECT-SLOTS */;
   {
    cl_object v4;
    v4 = v2slots;
    goto L6;
L5:;
    {
     cl_object v5slotd;
     v5slotd = ecl_car(v4);
     {
      cl_object v6name;
      cl_object v7allocation;
      v6name = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v5slotd) /*  SLOT-DEFINITION-NAME */;
      v7allocation = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-ALLOCATION",1543))(1, v5slotd) /*  SLOT-DEFINITION-ALLOCATION */;
      {
       cl_object v8;
       T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-ALLOCATION",1543))(1, v5slotd) /*  SLOT-DEFINITION-ALLOCATION */;
       {
        bool v9;
        v9 = (T0)==(VV[23]);
        v8 = (v9)?ECL_NIL:ECL_T;
       }
       if (Null(v8)) { goto L14; }
       goto L10;
L14:;
       {
        cl_object v9;
        v9 = si_make_seq_iterator(2, v3direct_slots, ecl_make_fixnum(0));
L19:;
        if ((v9)!=ECL_NIL) { goto L21; }
        goto L16;
L21:;
        {
         cl_object v10;
         v10 = si_seq_iterator_ref(v3direct_slots, v9);
         T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v10) /*  SLOT-DEFINITION-NAME */;
         if (!(ecl_eql(v6name,T0))) { goto L23; }
         if (Null(v10)) { goto L16; }
         goto L17;
        }
L23:;
        v9 = si_seq_iterator_next(v3direct_slots, v9);
        goto L19;
       }
L17:;
       {
        cl_object v9initfunc;
        cl_object v10value;
        v9initfunc = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-INITFUNCTION",1546))(1, v5slotd) /*  SLOT-DEFINITION-INITFUNCTION */;
        if (Null(v9initfunc)) { goto L30; }
        v10value = ecl_function_dispatch(cl_env_copy,v9initfunc)(0);
        goto L29;
L30:;
        v10value = ECL_UNBOUND;
L29:;
        {
         cl_object v11;
         v11 = ecl_list1(v10value);
         (cl_env_copy->function=ECL_CONS_CAR(VV[58]))->cfun.entry(2, v11, v5slotd) /*  (SETF SLOT-DEFINITION-LOCATION) */;
         goto L10;
        }
       }
L16:;
       {
        cl_object v12;
        v12 = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-PRECEDENCE-LIST",1492))(1, v1class) /*  CLASS-PRECEDENCE-LIST */;
        goto L36;
L35:;
        {
         cl_object v13c;
         v13c = ecl_car(v12);
         if (ecl_eql(v13c,v1class)) { goto L40; }
         {
          cl_object v14other;
          {
          cl_object v15;
          v15 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v5slotd) /*  SLOT-DEFINITION-NAME */;
          {
          cl_object v16;
          cl_object v17;
          v16 = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-SLOTS",1494))(1, v13c) /*  CLASS-SLOTS */;
          v17 = si_make_seq_iterator(2, v16, ecl_make_fixnum(0));
L46:;
          if ((v17)!=ECL_NIL) { goto L48; }
          v14other = ECL_NIL;
          goto L42;
L48:;
          {
          cl_object v18;
          v18 = si_seq_iterator_ref(v16, v17);
          T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v18) /*  SLOT-DEFINITION-NAME */;
          if (!(ecl_eql(v15,T0))) { goto L50; }
          v14other = v18;
          goto L42;
          }
L50:;
          v17 = si_seq_iterator_next(v16, v17);
          goto L46;
          }
          }
L42:;
          if (Null(v14other)) { goto L40; }
          T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-ALLOCATION",1543))(1, v14other) /*  SLOT-DEFINITION-ALLOCATION */;
          if (!((T0)==(v7allocation))) { goto L40; }
          {
          cl_object v15;
          v15 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-LOCATION",1547))(1, v14other) /*  SLOT-DEFINITION-LOCATION */;
          if (Null((cl_env_copy->function=ECL_CONS_CAR(VV[58]))->cfun.entry(2, v15, v5slotd) /*  (SETF SLOT-DEFINITION-LOCATION) */)) { goto L40; }
          }
          goto L10;
         }
L40:;
        }
        v12 = ecl_cdr(v12);
L36:;
        if (Null(v12)) { goto L61; }
        goto L35;
L61:;
       }
      }
     }
L10:;
    }
    v4 = ecl_cdr(v4);
L6:;
    if (Null(v4)) { goto L65; }
    goto L5;
L65:;
   }
   value0 = v2slots;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G435                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC44__g435(cl_object v1class)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)))) { goto L2; }
  T1 = ecl_car(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
  T2 = ecl_cdr(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
  T0 = ecl_function_dispatch(cl_env_copy,T1)(2, ecl_symbol_value(ECL_SYM(".COMBINED-METHOD-ARGS.",1473)), T2);
  goto L1;
L2:;
  T0 = cl_error(1, _ecl_static_4);
L1:;
  value0 = L43std_class_compute_slots(v1class, T0);
  return value0;
 }
}
/*	local function G436                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC45__g436(cl_object v1obj, cl_object v2stream)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3class;
   cl_object v4slotds;
   cl_object v5slotname;
   cl_object v6has_shared_slots;
   v3class = si_instance_class(v1obj);
   v4slotds = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-SLOTS",1494))(1, v3class) /*  CLASS-SLOTS */;
   v5slotname = ECL_NIL;
   v6has_shared_slots = ECL_NIL;
   T0 = (cl_env_copy->function=(ECL_SYM("CLASS-NAME",934)->symbol.gfdef))->cfun.entry(1, v3class) /*  CLASS-NAME */;
   cl_format(4, v2stream, _ecl_static_13, v1obj, T0);
   if (Null(v4slotds)) { goto L1; }
   cl_format(2, v2stream, _ecl_static_14);
   {
    cl_object v7;
    v7 = v4slotds;
    goto L13;
L12:;
    {
     cl_object v8slot;
     v8slot = ecl_car(v7);
     v5slotname = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v8slot) /*  SLOT-DEFINITION-NAME */;
     {
      cl_object v9;
      v9 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-ALLOCATION",1543))(1, v8slot) /*  SLOT-DEFINITION-ALLOCATION */;
      if (!(ecl_eql(v9,ECL_SYM("INSTANCE",1256)))) { goto L21; }
      if (Null(cl_slot_boundp(v1obj, v5slotname))) { goto L24; }
      T0 = cl_slot_value(v1obj, v5slotname);
      goto L23;
L24:;
      T0 = _ecl_static_16;
L23:;
      cl_format(4, v2stream, _ecl_static_15, v5slotname, T0);
      goto L19;
L21:;
      v6has_shared_slots = ECL_T;
     }
L19:;
    }
    v7 = ecl_cdr(v7);
L13:;
    if (Null(v7)) { goto L29; }
    goto L12;
L29:;
   }
   if (Null(v6has_shared_slots)) { goto L1; }
   cl_format(2, v2stream, _ecl_static_17);
   {
    cl_object v7;
    v7 = v4slotds;
    goto L36;
L35:;
    {
     cl_object v8slot;
     v8slot = ecl_car(v7);
     v5slotname = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, v8slot) /*  SLOT-DEFINITION-NAME */;
     T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-ALLOCATION",1543))(1, v8slot) /*  SLOT-DEFINITION-ALLOCATION */;
     if ((T0)==(ECL_SYM("INSTANCE",1256))) { goto L42; }
     if (Null(cl_slot_boundp(v1obj, v5slotname))) { goto L45; }
     T0 = cl_slot_value(v1obj, v5slotname);
     goto L44;
L45:;
     T0 = _ecl_static_16;
L44:;
     cl_format(4, v2stream, _ecl_static_15, v5slotname, T0);
L42:;
    }
    v7 = ecl_cdr(v7);
L36:;
    if (Null(v7)) { goto L49; }
    goto L35;
L49:;
   }
  }
L1:;
  value0 = v1obj;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for VALID-KEYWORDS-FROM-METHODS           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L46valid_keywords_from_methods(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1method_lists;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1method_lists = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v2methods;
   cl_object v3;
   v2methods = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v1method_lists))) FEtype_error_list(v1method_lists);
   v3 = v1method_lists;
   {
    cl_object v4;
    cl_object v5;
    v4 = ecl_list1(ECL_NIL);
    v5 = v4;
L6:;
    if (!(ecl_endp(v3))) { goto L8; }
    goto L7;
L8:;
    v2methods = _ecl_car(v3);
    {
     cl_object v6;
     v6 = _ecl_cdr(v3);
     if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
     v3 = v6;
    }
    {
     cl_object v6;
     v6 = v2methods;
     goto L21;
L20:;
     {
      cl_object v7;
      cl_object v8;
      if (ecl_unlikely(ECL_ATOM(v6))) FEtype_error_cons(v6);
      v7 = v6;
      v8 = ECL_CONS_CAR(v7);
      T0 = ecl_function_dispatch(cl_env_copy,VV[44])(1, v8) /*  METHOD-KEYWORDS */;
      if (!(ecl_eql(ECL_T,T0))) { goto L23; }
      if (Null(v7)) { goto L16; }
      goto L17;
     }
L23:;
     v6 = ECL_CONS_CDR(v6);
L21:;
     if (v6==ECL_NIL) { goto L30; }
     goto L20;
L30:;
     goto L16;
    }
L17:;
    value0 = ECL_T;
    cl_env_copy->nvalues = 1;
    return value0;
L16:;
    if (ecl_unlikely(ECL_ATOM(v5))) FEtype_error_cons(v5);
    T0 = v5;
    (ECL_CONS_CDR(T0)=v2methods,T0);
    if (Null(v2methods)) { goto L32; }
    T0 = ecl_cdr(v5);
    v5 = ecl_last(T0,1);
L32:;
    goto L6;
L7:;
    value0 = ecl_cdr(v4);
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for CHECK-INITARGS                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L47check_initargs(cl_narg narg, cl_object v1class, cl_object v2initargs, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>5)) FEwrong_num_arguments_anonym();
 {
  cl_object v3methods;
  cl_object v4slots;
  cl_object v5cached_keywords;
  va_list args; va_start(args,v2initargs);
  {
   int i = 2;
   if (i >= narg) {
    v3methods = ECL_NIL;
   } else {
    i++;
    v3methods = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v4slots = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-SLOTS",1494))(1, v1class) /*  CLASS-SLOTS */;
   } else {
    i++;
    v4slots = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v5cached_keywords = ECL_NIL;
   } else {
    i++;
    v5cached_keywords = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if ((v3methods)==(ECL_T)) { goto L4; }
  if ((v5cached_keywords)==(ECL_T)) { goto L4; }
  {
   cl_object v6name_loc;
   cl_object v7allow_other_keys;
   cl_object v8allow_other_keys_found;
   cl_object v9unknown_key;
   v6name_loc = v2initargs;
   v7allow_other_keys = ECL_NIL;
   v8allow_other_keys_found = ECL_NIL;
   v9unknown_key = ECL_NIL;
   goto L13;
L12:;
   {
    cl_object v10name;
    v10name = ecl_car(v6name_loc);
    T0 = ecl_cdr(v6name_loc);
    if (!(T0==ECL_NIL)) { goto L17; }
    si_simple_program_error(2, _ecl_static_18, v10name);
    goto L15;
L17:;
    if (!(ecl_eql(v10name,ECL_SYM("ALLOW-OTHER-KEYS",1197)))) { goto L19; }
    if ((v8allow_other_keys_found)!=ECL_NIL) { goto L19; }
    v7allow_other_keys = ecl_cadr(v6name_loc);
    v8allow_other_keys_found = ECL_T;
    goto L15;
L19:;
    {
     cl_object v11;
     {
      cl_object v12;
      v12 = v4slots;
      goto L29;
L28:;
      {
       cl_object v13;
       cl_object v14;
       if (ecl_unlikely(ECL_ATOM(v12))) FEtype_error_cons(v12);
       v13 = v12;
       v14 = ECL_CONS_CAR(v13);
       T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-INITARGS",1544))(1, v14) /*  SLOT-DEFINITION-INITARGS */;
       if (Null(ecl_memql(v10name,T0))) { goto L31; }
       v11 = v13;
       goto L25;
      }
L31:;
      v12 = ECL_CONS_CDR(v12);
L29:;
      if (v12==ECL_NIL) { goto L38; }
      goto L28;
L38:;
      v11 = ECL_NIL;
     }
L25:;
     if (Null(v11)) { goto L40; }
     goto L15;
L40:;
     {
      cl_object v12;
      v12 = ecl_memql(v10name,v5cached_keywords);
      if (Null(v12)) { goto L43; }
      goto L15;
L43:;
      {
       cl_object v13;
       if (Null(v3methods)) { goto L47; }
       {
        cl_object v14;
        v14 = v3methods;
        goto L52;
L51:;
        {
         cl_object v15;
         cl_object v16;
         if (ecl_unlikely(ECL_ATOM(v14))) FEtype_error_cons(v14);
         v15 = v14;
         v16 = ECL_CONS_CAR(v15);
         T0 = ecl_function_dispatch(cl_env_copy,VV[44])(1, v16) /*  METHOD-KEYWORDS */;
         if (Null(ecl_memql(v10name,T0))) { goto L54; }
         v13 = v15;
         goto L45;
        }
L54:;
        v14 = ECL_CONS_CDR(v14);
L52:;
        if (v14==ECL_NIL) { goto L61; }
        goto L51;
L61:;
        v13 = ECL_NIL;
        goto L45;
       }
L47:;
       v13 = ECL_NIL;
       goto L45;
L45:;
       if (Null(v13)) { goto L63; }
       goto L15;
L63:;
       v9unknown_key = v10name;
      }
     }
    }
   }
L15:;
   v6name_loc = ecl_cddr(v6name_loc);
L13:;
   if (v6name_loc==ECL_NIL) { goto L68; }
   goto L12;
L68:;
   if ((v7allow_other_keys)!=ECL_NIL) { goto L70; }
   if (Null(v9unknown_key)) { goto L70; }
   value0 = si_simple_program_error(3, _ecl_static_19, v9unknown_key, v1class);
   return value0;
L70:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L4:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G474                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC48__g474(cl_object v1obj, cl_object v2stream)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3slotds;
   T0 = si_instance_class(v1obj);
   v3slotds = ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-SLOTS",1494))(1, T0) /*  CLASS-SLOTS */;
   T0 = si_instance_class(v1obj);
   T1 = (cl_env_copy->function=(ECL_SYM("CLASS-NAME",934)->symbol.gfdef))->cfun.entry(1, T0) /*  CLASS-NAME */;
   cl_format(4, v2stream, _ecl_static_20, v1obj, T1);
   {
    cl_object v4scan;
    cl_fixnum v5i;
    v4scan = v3slotds;
    v5i = 0;
    goto L8;
L7:;
    T0 = ecl_car(v4scan);
    T1 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, T0) /*  SLOT-DEFINITION-NAME */;
    ecl_print(T1,v2stream);
    ecl_princ_str(":\t",v2stream);
    {
     cl_object v6;
     T0 = ecl_car(v4scan);
     v6 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SLOT-DEFINITION-NAME",1548))(1, T0) /*  SLOT-DEFINITION-NAME */;
     if (!((v6)==(VV[26]))) { goto L20; }
     goto L17;
     goto L18;
L20:;
     goto L18;
L18:;
     if (!((v6)==(VV[28]))) { goto L24; }
     goto L17;
     goto L22;
L24:;
     goto L22;
L22:;
     if (!((v6)==(VV[30]))) { goto L15; }
     goto L16;
L17:;
L16:;
     ecl_princ_char((ecl_character)(40),v2stream);
     {
      cl_object v7scan;
      cl_object v8e;
      v7scan = ecl_instance_ref((v1obj),(v5i));
      v8e = ecl_car(v7scan);
      goto L33;
L32:;
      T0 = (cl_env_copy->function=(ECL_SYM("CLASS-NAME",934)->symbol.gfdef))->cfun.entry(1, v8e) /*  CLASS-NAME */;
      ecl_prin1(T0,v2stream);
      if (Null(ecl_cdr(v7scan))) { goto L36; }
      ecl_princ_char((ecl_character)(32),v2stream);
L36:;
      v7scan = ecl_cdr(v7scan);
      v8e = ecl_car(v7scan);
L33:;
      if (v7scan==ECL_NIL) { goto L42; }
      goto L32;
L42:;
     }
     ecl_princ_char((ecl_character)(41),ECL_NIL);
     goto L13;
L15:;
     T0 = ecl_instance_ref((v1obj),(v5i));
     ecl_prin1(T0,v2stream);
    }
L13:;
    v4scan = ecl_cdr(v4scan);
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
    if (v4scan==ECL_NIL) { goto L49; }
    goto L7;
L49:;
   }
  }
  value0 = v1obj;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}

#include "clos/standard.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclNj3poIb7_g89xWE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CLOS;STANDARD.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclNj3poIb7_g89xWE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC1__g0,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("INITIALIZE-INSTANCE",947), ECL_NIL, VVtemp[0], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC2__g1,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("REINITIALIZE-INSTANCE",963), ECL_NIL, VVtemp[0], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC3__g42,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("SHARED-INITIALIZE",965), ECL_NIL, VVtemp[2], VVtemp[3], T0, ECL_T);
 }
 ecl_cmp_defun(VV[33]);                           /*  COMPUTE-INSTANCE-SIZE */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC5__g69,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("ALLOCATE-INSTANCE",927), ECL_NIL, VVtemp[4], VVtemp[5], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC6__g72,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("MAKE-INSTANCE",949), ECL_NIL, VVtemp[4], VVtemp[5], T0, ECL_T);
 }
 ecl_cmp_defun(VV[36]);                           /*  DELETE-KEYWORD  */
 (void)0; /* No entry created for ADD-DEFAULT-INITARGS */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC9__g81,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("DIRECT-SLOT-DEFINITION-CLASS",1503), ECL_NIL, VVtemp[0], VVtemp[6], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC10__g82,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("EFFECTIVE-SLOT-DEFINITION-CLASS",1505), ECL_NIL, VVtemp[0], VVtemp[6], T0, ECL_T);
 }
 ecl_cmp_defun(VV[37]);                           /*  HAS-FORWARD-REFERENCED-PARENTS */
 ecl_cmp_defun(VV[38]);                           /*  FINALIZE-UNLESS-FORWARD */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC15__g89,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("INITIALIZE-INSTANCE",947), ECL_NIL, VVtemp[4], VVtemp[7], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC18__g103,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("SHARED-INITIALIZE",965), ECL_NIL, VVtemp[8], VVtemp[9], T0, ECL_T);
 }
 ecl_cmp_defun(VV[43]);                           /*  PRECOMPUTE-VALID-INITARG-KEYWORDS */
 ecl_cmp_defun(VV[46]);                           /*  UPDATE-DEPENDENTS */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC22__g136,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("SHARED-INITIALIZE",965), ECL_NIL, VVtemp[10], VVtemp[11], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC23__g150,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("ADD-DIRECT-SUBCLASS",1485), ECL_NIL, VVtemp[8], VVtemp[12], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC24__g158,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("REMOVE-DIRECT-SUBCLASS",1539), ECL_NIL, VVtemp[8], VVtemp[12], T0, ECL_T);
 }
 ecl_cmp_defun(VV[50]);                           /*  CHECK-DIRECT-SUPERCLASSES */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC26__g166,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("VALIDATE-SUPERCLASS",1574), ECL_NIL, VVtemp[13], VVtemp[14], T0, ECL_T);
 }
 ecl_cmp_defun(VV[51]);                           /*  FORWARD-REFERENCED-CLASS-P */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC28__g200,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("FINALIZE-INHERITANCE",1513), ECL_NIL, VVtemp[4], VVtemp[4], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC29__g255,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("FINALIZE-INHERITANCE",1513), ECL_NIL, VVtemp[15], VVtemp[4], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC30__g256,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("COMPUTE-CLASS-PRECEDENCE-LIST",1496), ECL_NIL, VVtemp[4], VVtemp[4], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC31__g264,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("COMPUTE-SLOTS",1501), ECL_NIL, VVtemp[4], VVtemp[4], T0, ECL_T);
 }
 ecl_cmp_defun(VV[65]);                           /*  SLOT-DEFINITION-TO-PLIST */
 ecl_cmp_defun(VV[67]);                           /*  SAFE-SLOT-DEFINITION-LOCATION */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC36__g344,ECL_NIL,Cblock,3);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("COMPUTE-EFFECTIVE-SLOT-DEFINITION",1500), ECL_NIL, VVtemp[16], VVtemp[17], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC37__g359,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("COMPUTE-DEFAULT-INITARGS",1497), ECL_NIL, VVtemp[4], VVtemp[4], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC38__g372,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("ENSURE-CLASS-USING-CLASS",1507), ECL_NIL, VVtemp[8], VVtemp[18], T0, ECL_T);
 }
 ecl_cmp_defun(VV[77]);                           /*  COERCE-TO-CLASS */
 ecl_cmp_defun(VV[78]);                           /*  HELP-ENSURE-CLASS */
 ecl_cmp_defun(VV[81]);                           /*  CLASS-COMPUTE-SLOTS */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC42__g407,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("COMPUTE-SLOTS",1501), VVtemp[19], VVtemp[4], VVtemp[4], T0, ECL_T);
 }
 (void)0; /* No entry created for STD-CLASS-COMPUTE-SLOTS */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC44__g435,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("COMPUTE-SLOTS",1501), VVtemp[19], VVtemp[15], VVtemp[4], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC45__g436,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("DESCRIBE-OBJECT",941), ECL_NIL, VVtemp[20], VVtemp[21], T0, ECL_T);
 }
 ecl_cmp_defun(VV[82]);                           /*  VALID-KEYWORDS-FROM-METHODS */
 ecl_cmp_defun(VV[83]);                           /*  CHECK-INITARGS  */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC48__g474,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("DESCRIBE-OBJECT",941), ECL_NIL, VVtemp[10], VVtemp[21], T0, ECL_T);
 }
}
