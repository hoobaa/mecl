/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CLOS;STDMETHOD.LSP                                */
#include <ecl/ecl-cmp.h>
#include "clos/stdmethod.eclh"
/*	function definition for FUNCTION-KEYWORDS                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1function_keywords(cl_object v1method)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;                                  /*  KEY-FLAG        */
   cl_object v4;                                  /*  KEYWORDS        */
   T0 = cl_slot_value(v1method, VV[0]);
   value0 = si_process_lambda_list(T0, ECL_SYM("FUNCTION",396));
   {
    const int v5 = cl_env_copy->nvalues;
    cl_object v6;
    v6 = (v5<=3)? ECL_NIL : cl_env_copy->values[3];
    v3 = v6;
    v6 = (v5<=4)? ECL_NIL : cl_env_copy->values[4];
    v4 = v6;
   }
   if (Null(v3)) { goto L2; }
   {
    cl_object v5output;
    cl_object v6l;
    v5output = ECL_NIL;
    v6l = ecl_cdr(v4);
    goto L8;
L7:;
    T0 = ecl_car(v6l);
    v5output = CONS(T0,v5output);
    v6l = ecl_cddddr(v6l);
L8:;
    if (ecl_endp(v6l)) { goto L14; }
    goto L7;
L14:;
    value0 = v5output;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L2:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G11                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC2__g11(cl_narg narg, cl_object v1method, cl_object v2slot_names, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3specializers;
  cl_object v4spec_supplied_p;
  cl_object v5lambda_list;
  cl_object v6lambda_supplied_p;
  cl_object v7generic_function;
  ecl_va_list args; ecl_va_start(args,v2slot_names,narg,2);
  {
   cl_object keyvars[6];
   cl_parse_key(args,3,LC2__g11keys,keyvars,NULL,TRUE);
   ecl_va_end(args);
   v3specializers = keyvars[0];
   v4spec_supplied_p = keyvars[3];
   v5lambda_list = keyvars[1];
   v6lambda_supplied_p = keyvars[4];
   v7generic_function = keyvars[2];
  }
  if (Null(v2slot_names)) { goto L1; }
  if ((v4spec_supplied_p)!=ECL_NIL) { goto L3; }
  cl_error(1, _ecl_static_1);
L3:;
  if ((v6lambda_supplied_p)!=ECL_NIL) { goto L5; }
  cl_error(1, _ecl_static_2);
L5:;
  T0 = si_process_lambda_list(v5lambda_list, ECL_SYM("METHOD",954));
  T1 = ecl_car(T0);
  {
   cl_fixnum v8;
   v8 = ecl_length(v3specializers);
   if (ecl_number_equalp(T1,ecl_make_fixnum(v8))) { goto L1; }
  }
  cl_error(2, _ecl_static_3, v5lambda_list);
L1:;
  if (Null(v4spec_supplied_p)) { goto L8; }
  {
   cl_object v8s;
   cl_object v9;
   v8s = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v3specializers))) FEtype_error_list(v3specializers);
   v9 = v3specializers;
L13:;
   if (!(ecl_endp(v9))) { goto L15; }
   goto L14;
L15:;
   v8s = _ecl_car(v9);
   {
    cl_object v10;
    v10 = _ecl_cdr(v9);
    if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
    v9 = v10;
   }
   if ((si_of_class_p(2, v8s, ECL_SYM("SPECIALIZER",1556)))!=ECL_NIL) { goto L23; }
   cl_error(2, _ecl_static_4, v8s);
L23:;
   goto L13;
L14:;
  }
L8:;
  if (Null(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)))) { goto L29; }
  T0 = ecl_car(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
  T1 = ecl_cdr(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
  v1method = ecl_function_dispatch(cl_env_copy,T0)(2, ecl_symbol_value(ECL_SYM(".COMBINED-METHOD-ARGS.",1473)), T1);
  goto L28;
L29:;
  v1method = cl_error(1, _ecl_static_5);
L28:;
  {
   cl_object v8;
   T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("METHOD-LAMBDA-LIST",1533))(1, v1method) /*  METHOD-LAMBDA-LIST */;
   v8 = ecl_function_dispatch(cl_env_copy,VV[9])(1, T0) /*  COMPUTE-METHOD-KEYWORDS */;
   (cl_env_copy->function=ECL_CONS_CAR(VV[10]))->cfun.entry(2, v8, v1method) /*  (SETF METHOD-KEYWORDS) */;
  }
  value0 = v1method;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for INTERN-EQL-SPECIALIZER                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3intern_eql_specializer(cl_object volatile v1object)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   volatile cl_object v2table;
   v2table = ecl_symbol_value(VV[3]);
   {
    volatile cl_object v3;
    volatile cl_object v4;
    volatile cl_object v5;
    v3 = ecl_symbol_value(VV[2]);
    v4 = mp_lock_owner(v3);
    v5 = mp_lock_count(v3);
    {
     struct ecl_stack_frame _ecl_inner_frame_aux;
     volatile cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
     {
      volatile cl_object v6;
      v6 = _ecl_inner_frame;
      {
       volatile cl_object v7;
       v7 = ecl_symbol_value(ECL_SYM("*INTERRUPTS-ENABLED*",1023));
       ecl_bds_bind(cl_env_copy,ECL_SYM("*INTERRUPTS-ENABLED*",1023),ECL_NIL); /*  *INTERRUPTS-ENABLED* */
       ecl_bds_bind(cl_env_copy,ECL_SYM("*ALLOW-WITH-INTERRUPTS*",1730),ECL_NIL); /*  *ALLOW-WITH-INTERRUPTS* */
       {
        volatile bool unwinding = FALSE;
        cl_index v8=ECL_STACK_INDEX(cl_env_copy),v9;
        ecl_frame_ptr next_fr;
        if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
          unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
        } else {
        ecl_bds_bind(cl_env_copy,ECL_SYM("*INTERRUPTS-ENABLED*",1023),v7); /*  *INTERRUPTS-ENABLED* */
        mp_get_lock(1, v3);
        value0 = ecl_gethash_safe(v1object,v2table,ECL_NIL);
        if ((value0)!=ECL_NIL) { goto L13; }
        T0 = (cl_env_copy->function=(ECL_SYM("MAKE-INSTANCE",949)->symbol.gfdef))->cfun.entry(3, ECL_SYM("EQL-SPECIALIZER",1509), ECL_SYM("OBJECT",1278), v1object) /*  MAKE-INSTANCE */;
        cl_env_copy->values[0] = si_hash_set(v1object, v2table, T0);
        ecl_bds_unwind1(cl_env_copy);
        goto L10;
L13:;
        cl_env_copy->values[0] = value0;
        cl_env_copy->nvalues = 1;
        ecl_bds_unwind1(cl_env_copy);
        goto L10;
L10:;
        }
        ecl_frs_pop(cl_env_copy);
        v9=ecl_stack_push_values(cl_env_copy);
        T0 = ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398));
        T1 = mp_lock_owner(v3);
        if (!((T0)==(T1))) { goto L15; }
        if (!((v4)==(ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398))))) { goto L18; }
        T0 = mp_lock_count(v3);
        if (!(ecl_number_compare(T0,v5)>0)) { goto L15; }
        goto L16;
L18:;
L16:;
        mp_giveup_lock(v3);
L15:;
        ecl_stack_pop_values(cl_env_copy,v9);
        if (unwinding) ecl_unwind(cl_env_copy,next_fr);
        ECL_STACK_SET_INDEX(cl_env_copy,v8);
        ecl_bds_unwind1(cl_env_copy);
        ecl_bds_unwind1(cl_env_copy);
       }
      }
      ecl_stack_frame_push_values(v6);
      if (Null(ecl_symbol_value(ECL_SYM("*INTERRUPTS-ENABLED*",1023)))) { goto L20; }
      si_check_pending_interrupts();
L20:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v6);
      value0 = cl_env_copy->values[0];
     }
     ecl_stack_frame_close(_ecl_inner_frame);
    }
    return value0;
   }
  }
 }
}
/*	local function G48                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC4__g48(cl_object v1spec, cl_object v2method)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SPECIALIZER-DIRECT-METHODS",1558))(1, v1spec) /*  SPECIALIZER-DIRECT-METHODS */;
   v3 = cl_adjoin(2, v2method, T0);
   (cl_env_copy->function=ECL_CONS_CAR(VV[13]))->cfun.entry(2, v3, v1spec) /*  (SETF SPECIALIZER-DIRECT-METHODS) */;
  }
  {
   cl_object v3gf;
   v3gf = ecl_function_dispatch(cl_env_copy,ECL_SYM("METHOD-GENERIC-FUNCTION",1532))(1, v2method) /*  METHOD-GENERIC-FUNCTION */;
   {
    cl_object v4;
    T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SPECIALIZER-DIRECT-GENERIC-FUNCTIONS",1557))(1, v1spec) /*  SPECIALIZER-DIRECT-GENERIC-FUNCTIONS */;
    v4 = cl_adjoin(2, v3gf, T0);
    (cl_env_copy->function=ECL_CONS_CAR(VV[14]))->cfun.entry(2, v4, v1spec) /*  (SETF SPECIALIZER-DIRECT-GENERIC-FUNCTIONS) */;
   }
  }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  return value0;
 }
}
/*	local function G63                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC5__g63(cl_object v1spec, cl_object v2method)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3gf;
   cl_object v4methods;
   v3gf = ecl_function_dispatch(cl_env_copy,ECL_SYM("METHOD-GENERIC-FUNCTION",1532))(1, v2method) /*  METHOD-GENERIC-FUNCTION */;
   T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SPECIALIZER-DIRECT-METHODS",1558))(1, v1spec) /*  SPECIALIZER-DIRECT-METHODS */;
   v4methods = cl_delete(2, v2method, T0);
   (cl_env_copy->function=ECL_CONS_CAR(VV[13]))->cfun.entry(2, v4methods, v1spec) /*  (SETF SPECIALIZER-DIRECT-METHODS) */;
   {
    cl_object v5;
    v5 = si_make_seq_iterator(2, v4methods, ecl_make_fixnum(0));
L7:;
    if ((v5)!=ECL_NIL) { goto L9; }
    goto L5;
L9:;
    {
     cl_object v6;
     v6 = si_seq_iterator_ref(v4methods, v5);
     T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("METHOD-GENERIC-FUNCTION",1532))(1, v6) /*  METHOD-GENERIC-FUNCTION */;
     if (!(ecl_eql(v3gf,T0))) { goto L11; }
     if ((v6)!=ECL_NIL) { goto L4; }
     goto L5;
    }
L11:;
    v5 = si_seq_iterator_next(v4methods, v5);
    goto L7;
   }
L5:;
   {
    cl_object v5;
    T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SPECIALIZER-DIRECT-GENERIC-FUNCTIONS",1557))(1, v1spec) /*  SPECIALIZER-DIRECT-GENERIC-FUNCTIONS */;
    v5 = cl_delete(2, v3gf, T0);
    (cl_env_copy->function=ECL_CONS_CAR(VV[14]))->cfun.entry(2, v5, v1spec) /*  (SETF SPECIALIZER-DIRECT-GENERIC-FUNCTIONS) */;
   }
L4:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 0;
   return value0;
  }
 }
}
/*	local function G104                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC6__g104(cl_object volatile v1spec, cl_object volatile v2method)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   volatile cl_object v3;
   volatile cl_object v4;
   volatile cl_object v5;
   v3 = ecl_symbol_value(VV[2]);
   v4 = mp_lock_owner(v3);
   v5 = mp_lock_count(v3);
   {
    struct ecl_stack_frame _ecl_inner_frame_aux;
    volatile cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
    {
     volatile cl_object v6;
     v6 = _ecl_inner_frame;
     {
      volatile cl_object v7;
      v7 = ecl_symbol_value(ECL_SYM("*INTERRUPTS-ENABLED*",1023));
      ecl_bds_bind(cl_env_copy,ECL_SYM("*INTERRUPTS-ENABLED*",1023),ECL_NIL); /*  *INTERRUPTS-ENABLED* */
      ecl_bds_bind(cl_env_copy,ECL_SYM("*ALLOW-WITH-INTERRUPTS*",1730),ECL_NIL); /*  *ALLOW-WITH-INTERRUPTS* */
      {
       volatile bool unwinding = FALSE;
       cl_index v8=ECL_STACK_INDEX(cl_env_copy),v9;
       ecl_frame_ptr next_fr;
       if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
         unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
       } else {
       ecl_bds_bind(cl_env_copy,ECL_SYM("*INTERRUPTS-ENABLED*",1023),v7); /*  *INTERRUPTS-ENABLED* */
       mp_get_lock(1, v3);
       if (Null(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)))) { goto L13; }
       T0 = ecl_car(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
       T1 = ecl_cdr(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
       ecl_function_dispatch(cl_env_copy,T0)(2, ecl_symbol_value(ECL_SYM(".COMBINED-METHOD-ARGS.",1473)), T1);
       goto L12;
L13:;
       cl_error(1, _ecl_static_5);
L12:;
       if ((ecl_function_dispatch(cl_env_copy,ECL_SYM("SPECIALIZER-DIRECT-METHODS",1558))(1, v1spec) /*  SPECIALIZER-DIRECT-METHODS */)!=ECL_NIL) { goto L16; }
       cl_env_copy->values[0] = cl_remhash(v1spec, ecl_symbol_value(VV[3]));
       ecl_bds_unwind1(cl_env_copy);
       goto L10;
L16:;
       cl_env_copy->values[0] = ECL_NIL;
       cl_env_copy->nvalues = 1;
       ecl_bds_unwind1(cl_env_copy);
L10:;
       }
       ecl_frs_pop(cl_env_copy);
       v9=ecl_stack_push_values(cl_env_copy);
       T0 = ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398));
       T1 = mp_lock_owner(v3);
       if (!((T0)==(T1))) { goto L18; }
       if (!((v4)==(ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398))))) { goto L21; }
       T0 = mp_lock_count(v3);
       if (!(ecl_number_compare(T0,v5)>0)) { goto L18; }
       goto L19;
L21:;
L19:;
       mp_giveup_lock(v3);
L18:;
       ecl_stack_pop_values(cl_env_copy,v9);
       if (unwinding) ecl_unwind(cl_env_copy,next_fr);
       ECL_STACK_SET_INDEX(cl_env_copy,v8);
       ecl_bds_unwind1(cl_env_copy);
       ecl_bds_unwind1(cl_env_copy);
      }
     }
     ecl_stack_frame_push_values(v6);
     if (Null(ecl_symbol_value(ECL_SYM("*INTERRUPTS-ENABLED*",1023)))) { goto L23; }
     si_check_pending_interrupts();
L23:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v6);
    }
    ecl_stack_frame_close(_ecl_inner_frame);
   }
  }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  return value0;
 }
}

#include "clos/stdmethod.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecl7X8g8ORGax1i9_4DEcYE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CLOS;STDMETHOD.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_ecl7X8g8ORGax1i9_4DEcYE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[5]);                            /*  FUNCTION-KEYWORDS */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC2__g11,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("SHARED-INITIALIZE",965), ECL_NIL, VVtemp[0], VVtemp[1], T0, ECL_T);
 }
 si_Xmake_special(VV[2]);
 cl_set(VV[2],mp_make_lock(2, ECL_SYM("NAME",1273), ECL_SYM("EQL-SPECIALIZER",1509)));
 {
  cl_object T0;
 si_Xmake_special(VV[3]);
 T0 = (ECL_SYM("EQL",334)->symbol.gfdef);
 cl_set(VV[3],cl_make_hash_table(4, ECL_SYM("SIZE",1308), ecl_make_fixnum(128), ECL_SYM("TEST",1316), T0));
 }
 ecl_cmp_defun(VV[12]);                           /*  INTERN-EQL-SPECIALIZER */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC4__g48,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("ADD-DIRECT-METHOD",1484), ECL_NIL, VVtemp[2], VVtemp[3], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC5__g63,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("REMOVE-DIRECT-METHOD",1538), ECL_NIL, VVtemp[2], VVtemp[3], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC6__g104,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("REMOVE-DIRECT-METHOD",1538), ECL_NIL, VVtemp[4], VVtemp[3], T0, ECL_T);
 }
}
