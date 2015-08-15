/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CLOS;DEFCLASS.LSP                                 */
#include <ecl/ecl-cmp.h>
#include "clos/defclass.eclh"
/*	function definition for PARSE-DEFAULT-INITARGS                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1parse_default_initargs(cl_object v1default_initargs)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2output_list;
   cl_object v3scan;
   cl_object v4already_supplied;
   v2output_list = ECL_NIL;
   v3scan = v1default_initargs;
   v4already_supplied = ECL_NIL;
   goto L6;
L5:;
   T0 = ecl_cdr(v3scan);
   if (!(ecl_endp(T0))) { goto L8; }
   si_simple_program_error(1, _ecl_static_1);
L8:;
   {
    cl_object v5;
    cl_object v6;
    v5 = ecl_car(v3scan);
    v6 = ecl_cadr(v3scan);
    if (Null(ecl_memql(v5,v4already_supplied))) { goto L14; }
    si_simple_program_error(3, _ecl_static_2, v5, v1default_initargs);
    goto L13;
L14:;
    v4already_supplied = CONS(v5,v4already_supplied);
L13:;
    T0 = cl_list(2, ECL_SYM("QUOTE",679), v5);
    T1 = cl_list(2, ECL_SYM("QUOTE",679), v6);
    T2 = ecl_function_dispatch(cl_env_copy,VV[7])(1, v6) /*  MAKE-FUNCTION-INITFORM */;
    T3 = cl_list(4, ECL_SYM("LIST",481), T0, T1, T2);
    v2output_list = CONS(T3,v2output_list);
   }
   v3scan = ecl_cddr(v3scan);
L6:;
   if (ecl_endp(v3scan)) { goto L20; }
   goto L5;
L20:;
   T0 = cl_nreverse(v2output_list);
   value0 = CONS(ECL_SYM("LIST",481),T0);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function DEFCLASS                                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC2defclass(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4args;
   v3 = ecl_cdr(v1);
   v4args = v3;
   {
    cl_fixnum v5;
    v5 = ecl_length(v4args);
    if ((v5)>=(3)) { goto L3; }
   }
   si_simple_program_error(1, _ecl_static_3);
L3:;
   {
    cl_object v5name;
    cl_object v6superclasses;
    cl_object v7slots;
    {
     cl_object v8;
     v8 = v4args;
     if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
     if (Null(v8)) { goto L9; }
     {
      cl_object v9;
      v9 = ECL_CONS_CDR(v8);
      v4args = v9;
      v8 = ECL_CONS_CAR(v8);
     }
L9:;
     v5name = v8;
    }
    {
     cl_object v8;
     v8 = v4args;
     if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
     if (Null(v8)) { goto L19; }
     {
      cl_object v9;
      v9 = ECL_CONS_CDR(v8);
      v4args = v9;
      v8 = ECL_CONS_CAR(v8);
     }
L19:;
     v6superclasses = v8;
    }
    {
     cl_object v8;
     v8 = v4args;
     if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
     if (Null(v8)) { goto L29; }
     {
      cl_object v9;
      v9 = ECL_CONS_CDR(v8);
      v4args = v9;
      v8 = ECL_CONS_CAR(v8);
     }
L29:;
     v7slots = v8;
    }
    if (!(ECL_LISTP(v6superclasses))) { goto L38; }
    if (ECL_LISTP(v7slots)) { goto L35; }
    goto L36;
L38:;
    goto L36;
L36:;
    si_simple_program_error(1, _ecl_static_4);
L35:;
    if (!(ECL_SYMBOLP(v5name))) { goto L43; }
    T0 = (ECL_SYM("SYMBOLP",847)->symbol.gfdef);
    if ((cl_every(2, T0, v6superclasses))!=ECL_NIL) { goto L40; }
    goto L41;
L43:;
    goto L41;
L41:;
    si_simple_program_error(1, _ecl_static_5);
L40:;
    if (Null(ecl_symbol_value(ECL_SYM("*REGISTER-WITH-PDE-HOOK*",1181)))) { goto L47; }
    T1 = ecl_symbol_value(ECL_SYM("*REGISTER-WITH-PDE-HOOK*",1181));
    T2 = cl_copy_tree(ecl_symbol_value(ECL_SYM("*SOURCE-LOCATION*",1180)));
    T3 = cl_list(2, ECL_SYM("QUOTE",679), v5name);
    T4 = cl_list(2, ECL_SYM("QUOTE",679), v6superclasses);
    T5 = L3compress_slot_forms(v7slots);
    T6 = L5process_class_options(v4args);
    T7 = cl_list(5, ECL_SYM("LOAD-DEFCLASS",1578), T3, T4, T5, T6);
    T0 = ecl_function_dispatch(cl_env_copy,T1)(3, T2, v1, T7);
    goto L46;
L47:;
    T1 = cl_list(2, ECL_SYM("QUOTE",679), v5name);
    T2 = cl_list(2, ECL_SYM("QUOTE",679), v6superclasses);
    T3 = L3compress_slot_forms(v7slots);
    T4 = L5process_class_options(v4args);
    T0 = cl_list(5, ECL_SYM("LOAD-DEFCLASS",1578), T1, T2, T3, T4);
L46:;
    value0 = cl_list(3, ECL_SYM("EVAL-WHEN",340), VV[0], T0);
    return value0;
   }
  }
 }
}
/*	function definition for COMPRESS-SLOT-FORMS                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3compress_slot_forms(cl_object v1slot_definitions)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2const;
   cl_object v3output;
   cl_object v4non_const;
   v2const = ECL_NIL;
   v3output = ECL_NIL;
   v4non_const = ECL_NIL;
   {
    cl_object v5;
    v5 = ecl_function_dispatch(cl_env_copy,VV[9])(1, v1slot_definitions) /*  PARSE-SLOTS */;
    goto L8;
L7:;
    {
     cl_object v6slotd;
     v6slotd = ecl_car(v5);
     {
      cl_object v7initfun;
      cl_object v8copy;
      v7initfun = cl_getf(3, v6slotd, ECL_SYM("INITFUNCTION",997), ECL_NIL);
      v8copy = cl_copy_list(v6slotd);
      {
       cl_object v10;
       cl_object v11;                             /*  FLAG            */
       value0 = si_rem_f(v8copy, ECL_SYM("INITFUNCTION",997));
       v10 = value0;
       v11 = cl_env_copy->values[1];
       v8copy = v10;
      }
      if (!(ECL_ATOM(v7initfun))) { goto L19; }
      v2const = CONS(v8copy,v2const);
      T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("MAYBE-QUOTE",1686))(1, v8copy) /*  MAYBE-QUOTE */;
      v3output = CONS(T0,v3output);
      goto L12;
L19:;
      T0 = ecl_car(v7initfun);
      if (!((T0)==(ECL_SYM("CONSTANTLY",253)))) { goto L24; }
      v2const = CONS(v8copy,v2const);
      T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("MAYBE-QUOTE",1686))(1, v8copy) /*  MAYBE-QUOTE */;
      v3output = CONS(T0,v3output);
      goto L12;
L24:;
      T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("MAYBE-QUOTE",1686))(1, v8copy) /*  MAYBE-QUOTE */;
      T1 = cl_list(4, ECL_SYM("LIST*",482), ECL_SYM("INITFUNCTION",997), v7initfun, T0);
      v3output = CONS(T1,v3output);
      v4non_const = ECL_T;
     }
L12:;
    }
    v5 = ecl_cdr(v5);
L8:;
    if (Null(v5)) { goto L34; }
    goto L7;
L34:;
   }
   if (Null(v4non_const)) { goto L36; }
   T0 = cl_nreverse(v3output);
   value0 = CONS(ECL_SYM("LIST",481),T0);
   cl_env_copy->nvalues = 1;
   return value0;
L36:;
   T0 = cl_nreverse(v2const);
   value0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("MAYBE-QUOTE",1686))(1, T0) /*  MAYBE-QUOTE */;
   return value0;
  }
 }
}
/*	function definition for UNCOMPRESS-SLOT-FORMS                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4uncompress_slot_forms(cl_object v1slot_definitions)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2slotd;
   cl_object v3;
   v2slotd = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v1slot_definitions))) FEtype_error_list(v1slot_definitions);
   v3 = v1slot_definitions;
   {
    cl_object v4initform;
    v4initform = ECL_NIL;
    {
     cl_object v5;
     cl_object v6;
     v5 = ecl_list1(ECL_NIL);
     v6 = v5;
L7:;
     if (!(ecl_endp(v3))) { goto L9; }
     goto L8;
L9:;
     v2slotd = _ecl_car(v3);
     {
      cl_object v7;
      v7 = _ecl_cdr(v3);
      if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
      v3 = v7;
     }
     v4initform = cl_getf(3, v2slotd, ECL_SYM("INITFORM",996), v2slotd);
     if (ecl_unlikely(ECL_ATOM(v6))) FEtype_error_cons(v6);
     T0 = v6;
     if (!((v4initform)==(v2slotd))) { goto L24; }
     T1 = v2slotd;
     goto L23;
L24:;
     if (Null(cl_getf(2, v2slotd, ECL_SYM("INITFUNCTION",997)))) { goto L26; }
     T1 = v2slotd;
     goto L23;
L26:;
     T2 = cl_eval(v4initform);
     T3 = cl_constantly(T2);
     T1 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T3, v2slotd);
L23:;
     v6 = ecl_list1(T1);
     (ECL_CONS_CDR(T0)=v6,T0);
     goto L7;
L8:;
     value0 = ecl_cdr(v5);
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
  }
 }
}
/*	function definition for PROCESS-CLASS-OPTIONS                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5process_class_options(cl_object v1class_args)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2options;
   cl_object v3processed_options;
   v2options = ECL_NIL;
   v3processed_options = ECL_NIL;
   {
    cl_object v4;
    v4 = v1class_args;
    goto L7;
L6:;
    {
     cl_object v5option;
     v5option = ecl_car(v4);
     {
      cl_object v6;
      cl_object v7option_name;
      cl_object v8option_value;
      v6 = ecl_car(v5option);
      v7option_name = v6;
      v8option_value = ECL_NIL;
      if (Null(ecl_memql(v7option_name,v3processed_options))) { goto L16; }
      si_simple_program_error(2, _ecl_static_6, v7option_name);
      goto L15;
L16:;
      v3processed_options = CONS(v7option_name,v3processed_options);
L15:;
      {
       cl_object v9;
       v9 = v7option_name;
       if (!(ecl_eql(v9,ECL_SYM("METACLASS",1000)))) { goto L27; }
       goto L24;
       goto L25;
L27:;
       goto L25;
L25:;
       if (!(ecl_eql(v9,ECL_SYM("DOCUMENTATION",1222)))) { goto L22; }
       goto L23;
L24:;
L23:;
       T0 = ecl_cadr(v5option);
       v8option_value = ecl_function_dispatch(cl_env_copy,ECL_SYM("MAYBE-QUOTE",1686))(1, T0) /*  MAYBE-QUOTE */;
       goto L20;
L22:;
       if (!(ecl_eql(v9,ECL_SYM("DEFAULT-INITARGS",987)))) { goto L30; }
       v7option_name = ECL_SYM("DIRECT-DEFAULT-INITARGS",989);
       T0 = ecl_cdr(v5option);
       v8option_value = L1parse_default_initargs(T0);
       goto L20;
L30:;
       T0 = ecl_cdr(v5option);
       v8option_value = ecl_function_dispatch(cl_env_copy,ECL_SYM("MAYBE-QUOTE",1686))(1, T0) /*  MAYBE-QUOTE */;
      }
L20:;
      T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("MAYBE-QUOTE",1686))(1, v7option_name) /*  MAYBE-QUOTE */;
      v2options = cl_listX(3, T0, v8option_value, v2options);
     }
    }
    v4 = ecl_cdr(v4);
L7:;
    if (Null(v4)) { goto L37; }
    goto L6;
L37:;
   }
   if (Null(v2options)) { goto L40; }
   value0 = CONS(ECL_SYM("LIST",481),v2options);
   cl_env_copy->nvalues = 1;
   return value0;
L40:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for LOAD-DEFCLASS                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object clos_load_defclass(cl_object v1name, cl_object v2superclasses, cl_object v3slot_definitions, cl_object v4options)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = (VV[6]->symbol.gfdef);
  T1 = L4uncompress_slot_forms(v3slot_definitions);
  value0 = cl_apply(7, T0, v1name, ECL_SYM("DIRECT-SUPERCLASSES",991), v2superclasses, ECL_SYM("DIRECT-SLOTS",990), T1, v4options);
  return value0;
 }
}
/*	function definition for ENSURE-CLASS                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object clos_ensure_class(cl_narg narg, cl_object v1name, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2initargs;
  ecl_va_list args; ecl_va_start(args,v1name,narg,1);
  v2initargs = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v3old_class;
   cl_object v4new_class;
   v3old_class = ECL_NIL;
   v4new_class = ECL_NIL;
   if (Null(v1name)) { goto L3; }
   v3old_class = cl_find_class(2, v1name, ECL_NIL);
   if (Null(v3old_class)) { goto L3; }
   T0 = (cl_env_copy->function=(ECL_SYM("CLASS-NAME",934)->symbol.gfdef))->cfun.entry(1, v3old_class) /*  CLASS-NAME */;
   if ((T0)==(v1name)) { goto L3; }
   v3old_class = ECL_NIL;
L3:;
   T0 = (ECL_SYM("ENSURE-CLASS-USING-CLASS",1507)->symbol.gfdef);
   v4new_class = cl_apply(4, T0, v3old_class, v1name, v2initargs);
   value0 = v4new_class;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}

#include "clos/defclass.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclJC5RLTufnqen9_3sskfE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CLOS;DEFCLASS.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclJC5RLTufnqen9_3sskfE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 (void)0; /* No entry created for PARSE-DEFAULT-INITARGS */
 ecl_cmp_defmacro(VV[8]);                         /*  DEFCLASS        */
 (void)0; /* No entry created for COMPRESS-SLOT-FORMS */
 ecl_cmp_defun(VV[10]);                           /*  UNCOMPRESS-SLOT-FORMS */
 ecl_cmp_defun(VV[11]);                           /*  PROCESS-CLASS-OPTIONS */
 (void)0; /* No entry created for LOAD-DEFCLASS */
 ecl_cmp_defun(VV[12]);                           /*  ENSURE-CLASS    */
}
