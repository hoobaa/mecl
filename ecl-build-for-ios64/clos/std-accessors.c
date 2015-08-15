/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CLOS;STD-ACCESSORS.LSP                            */
#include <ecl/ecl-cmp.h>
#include "clos/std-accessors.eclh"
/*	function definition for SAFE-SLOT-DEFINITION-LOCATION         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1safe_slot_definition_location(cl_narg narg, cl_object v1slotd, ...)
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
  if (!(ECL_LISTP(v1slotd))) { goto L2; }
  value0 = cl_error(1, _ecl_static_1);
  return value0;
L2:;
  value0 = cl_slot_value(v1slotd, ECL_SYM("LOCATION",1763));
  return value0;
 }
}
/*	function definition for STD-CLASS-SEALED-ACCESSORS            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4std_class_sealed_accessors(cl_object v1index)
{
 cl_object T0, T1;
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1index,env0);               /*  INDEX           */
  {cl_object v2;
   v2 = ECL_NIL;
   v2 = ecl_make_cclosure_va((cl_objectfn)LC2__g0,env0,Cblock);
   T0 = v2;
  }
  {cl_object v2;
   v2 = ECL_NIL;
   v2 = ecl_make_cclosure_va((cl_objectfn)LC3__g55,env0,Cblock);
   T1 = v2;
  }
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = T1;
  cl_env_copy->values[0] = T0;
  return cl_env_copy->values[0];
 }
}
/*	closure G0                                                    */
/*	optimize speed 3, debug 0, space 1, safety 0                  */
static cl_object LC2__g0(cl_narg narg, cl_object v1self, ...)
{
 cl_object T0, T1;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  INDEX           */
 { /* ... closure scanning finished */
TTL:
 {
  cl_object v2s;
  v2s = (v1self)->instance.sig;
  if (!((v2s)!=ECL_UNBOUND)) { goto L1; }
  T0 = ECL_CLASS_OF(v1self);
  T1 = (T0)->instance.slots[6];
  if ((v2s)==(T1)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,ECL_SYM("UPDATE-INSTANCE",1573))(1, v1self) /*  UPDATE-INSTANCE */;
 }
L1:;
 value0 = clos_safe_instance_ref(v1self, ECL_CONS_CAR(CLV0));
 return value0;
 }
}
/*	closure G55                                                   */
/*	optimize speed 3, debug 0, space 1, safety 0                  */
static cl_object LC3__g55(cl_narg narg, cl_object v1value, cl_object v2self, ...)
{
 cl_object T0, T1;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  INDEX           */
 { /* ... closure scanning finished */
TTL:
 {
  cl_object v3s;
  v3s = (v2self)->instance.sig;
  if (!((v3s)!=ECL_UNBOUND)) { goto L1; }
  T0 = ECL_CLASS_OF(v2self);
  T1 = (T0)->instance.slots[6];
  if ((v3s)==(T1)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,ECL_SYM("UPDATE-INSTANCE",1573))(1, v2self) /*  UPDATE-INSTANCE */;
 }
L1:;
 value0 = (v2self)->instance.slots[ecl_fixnum(ECL_CONS_CAR(CLV0))]=(v1value);
 cl_env_copy->nvalues = 1;
 return value0;
 }
}
/*	function definition for STD-CLASS-ACCESSORS                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7std_class_accessors(cl_object v1slot_name)
{
 cl_object T0, T1;
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1slot_name,env0);           /*  SLOT-NAME       */
  {cl_object v2;
   v2 = ECL_NIL;
   v2 = ecl_make_cclosure_va((cl_objectfn)LC5__g110,env0,Cblock);
   T0 = v2;
  }
  {cl_object v2;
   v2 = ECL_NIL;
   v2 = ecl_make_cclosure_va((cl_objectfn)LC6__g111,env0,Cblock);
   T1 = v2;
  }
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = T1;
  cl_env_copy->values[0] = T0;
  return cl_env_copy->values[0];
 }
}
/*	closure G110                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC5__g110(cl_narg narg, cl_object v1self, ...)
{
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  SLOT-NAME       */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = cl_slot_value(v1self, ECL_CONS_CAR(CLV0));
  return value0;
 }
 }
}
/*	closure G111                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC6__g111(cl_narg narg, cl_object v1value, cl_object v2self, ...)
{
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  SLOT-NAME       */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = (cl_env_copy->function=ECL_CONS_CAR(VV[25]))->cfun.entry(3, v1value, v2self, ECL_CONS_CAR(CLV0)) /*  (SETF SLOT-VALUE) */;
  return value0;
 }
 }
}
/*	function definition for SAFE-ADD-METHOD                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8safe_add_method(cl_object v1name, cl_object v2method)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((ecl_symbol_value(VV[1]))!=ECL_NIL) { goto L3; }
  if (Null(cl_fboundp(v1name))) { goto L3; }
  T0 = cl_fdefinition(v1name);
  if (!(ECL_INSTANCEP(T0))) { goto L1; }
  goto L2;
L3:;
L2:;
  T0 = (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(1, v1name) /*  ENSURE-GENERIC-FUNCTION */;
  value0 = (cl_env_copy->function=(ECL_SYM("ADD-METHOD",928)->symbol.gfdef))->cfun.entry(2, T0, v2method) /*  ADD-METHOD */;
  return value0;
L1:;
  {
   cl_object v3gf;
   v3gf = (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(1, VV[2]) /*  ENSURE-GENERIC-FUNCTION */;
   (cl_env_copy->function=(ECL_SYM("ADD-METHOD",928)->symbol.gfdef))->cfun.entry(2, v3gf, v2method) /*  ADD-METHOD */;
   (cl_env_copy->function=ECL_CONS_CAR(VV[27]))->cfun.entry(2, v1name, v3gf) /*  (SETF GENERIC-FUNCTION-NAME) */;
   si_fset(4, v1name, v3gf, ECL_NIL, ECL_NIL);
   value0 = cl_fmakunbound(VV[2]);
   return value0;
  }
 }
}
/*	function definition for STD-CLASS-GENERATE-ACCESSORS          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L9std_class_generate_accessors(cl_narg narg, cl_object v1standard_class, ...)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2optimizable;
  va_list args; va_start(args,v1standard_class);
  {
   int i = 1;
   if (i >= narg) {
    v2optimizable = ECL_T;
   } else {
    i++;
    v2optimizable = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v3;
   v3 = cl_slot_value(v1standard_class, VV[4]);
   goto L5;
L4:;
   {
    cl_object v4slotd;
    v4slotd = ecl_car(v3);
    {
     cl_object v5;
     v5 = cl_slot_value(v1standard_class, ECL_SYM("NAME",1535));
     if (!((v5)==(ECL_SYM("STANDARD-CLASS",973)))) { goto L15; }
     goto L10;
     goto L13;
L15:;
     goto L13;
L13:;
     if (!((v5)==(ECL_SYM("FUNCALLABLE-STANDARD-CLASS",1516)))) { goto L19; }
     goto L10;
     goto L17;
L19:;
     goto L17;
L17:;
     if (!((v5)==(ECL_SYM("STRUCTURE-CLASS",977)))) { goto L22; }
     goto L10;
     goto L11;
L22:;
     goto L11;
    }
L11:;
    v2optimizable = ECL_NIL;
L10:;
    {
     cl_object v6;                                /*  READER          */
     cl_object v7;                                /*  WRITER          */
     if (Null(v2optimizable)) { goto L26; }
     T0 = cl_slot_value(v4slotd, VV[8]);
     if (!((T0)==(ECL_SYM("INSTANCE",1256)))) { goto L26; }
     T0 = cl_slot_value(v4slotd, ECL_SYM("LOCATION",1763));
     if (!(ECL_FIXNUMP(T0))) { goto L26; }
     T0 = cl_slot_value(v4slotd, ECL_SYM("LOCATION",1763));
     value0 = L4std_class_sealed_accessors(T0);
     goto L25;
L26:;
     T0 = cl_slot_value(v4slotd, ECL_SYM("NAME",1535));
     value0 = L7std_class_accessors(T0);
L25:;
     v6 = value0;
     {
      const int v8 = cl_env_copy->nvalues;
      cl_object v9;
      v9 = (v8<=1)? ECL_NIL : cl_env_copy->values[1];
      v7 = v9;
     }
     {
      cl_object v8options;
      cl_object v9reader_args;
      cl_object v10reader_class;
      cl_object v11writer_args;
      cl_object v12writer_class;
      v8options = cl_list(2, VV[9], v4slotd);
      T0 = ecl_list1(v1standard_class);
      v9reader_args = cl_listX(11, ECL_SYM("FUNCTION",1241), v6, VV[10], ECL_NIL, VV[11], ECL_NIL, ECL_SYM("LAMBDA-LIST",998), VV[12], VV[13], T0, v8options);
      if (!(ecl_boundp(cl_env_copy,VV[14]))) { goto L33; }
      v10reader_class = ECL_SYM("STANDARD-READER-METHOD",1563);
      goto L32;
L33:;
      T0 = (ECL_SYM("READER-METHOD-CLASS",1536)->symbol.gfdef);
      v10reader_class = cl_apply(4, T0, v1standard_class, v4slotd, v9reader_args);
L32:;
      T0 = cl_find_class(1, ECL_T);
      T1 = cl_list(2, T0, v1standard_class);
      v11writer_args = cl_listX(11, ECL_SYM("FUNCTION",1241), v7, VV[10], ECL_NIL, VV[11], ECL_NIL, ECL_SYM("LAMBDA-LIST",998), VV[15], VV[13], T1, v8options);
      if (!(ecl_boundp(cl_env_copy,VV[14]))) { goto L38; }
      v12writer_class = ECL_SYM("STANDARD-WRITER-METHOD",1565);
      goto L37;
L38:;
      T0 = (ECL_SYM("WRITER-METHOD-CLASS",1575)->symbol.gfdef);
      v12writer_class = cl_apply(4, T0, v1standard_class, v4slotd, v11writer_args);
L37:;
      {
       cl_object v13;
       v13 = cl_slot_value(v4slotd, VV[16]);
       goto L45;
L44:;
       {
        cl_object v14fname;
        v14fname = ecl_car(v13);
        {
         cl_object v15method;
         T0 = ecl_list1(v1standard_class);
         T1 = ecl_function_dispatch(cl_env_copy,VV[29])(1, v6) /*  WRAPPED-METHOD-FUNCTION */;
         v15method = (cl_env_copy->function=(ECL_SYM("MAKE-METHOD",953)->symbol.gfdef))->cfun.entry(6, v10reader_class, ECL_NIL, T0, VV[17], T1, v8options) /*  MAKE-METHOD */;
         L8safe_add_method(v14fname, v15method);
         if ((ecl_symbol_value(VV[1]))!=ECL_NIL) { goto L49; }
         (cl_env_copy->function=ECL_CONS_CAR(VV[25]))->cfun.entry(3, v4slotd, v15method, ECL_SYM("SLOT-DEFINITION",1542)) /*  (SETF SLOT-VALUE) */;
        }
L49:;
       }
       v13 = ecl_cdr(v13);
L45:;
       if (Null(v13)) { goto L55; }
       goto L44;
L55:;
      }
      {
       cl_object v13;
       v13 = cl_slot_value(v4slotd, VV[18]);
       goto L60;
L59:;
       {
        cl_object v14fname;
        v14fname = ecl_car(v13);
        {
         cl_object v15method;
         T0 = cl_find_class(1, ECL_T);
         T1 = cl_list(2, T0, v1standard_class);
         T2 = ecl_function_dispatch(cl_env_copy,VV[29])(1, v7) /*  WRAPPED-METHOD-FUNCTION */;
         v15method = (cl_env_copy->function=(ECL_SYM("MAKE-METHOD",953)->symbol.gfdef))->cfun.entry(6, v12writer_class, ECL_NIL, T1, VV[19], T2, v8options) /*  MAKE-METHOD */;
         L8safe_add_method(v14fname, v15method);
         if ((ecl_symbol_value(VV[1]))!=ECL_NIL) { goto L64; }
         (cl_env_copy->function=ECL_CONS_CAR(VV[25]))->cfun.entry(3, v4slotd, v15method, ECL_SYM("SLOT-DEFINITION",1542)) /*  (SETF SLOT-VALUE) */;
        }
L64:;
       }
       v13 = ecl_cdr(v13);
L60:;
       if (Null(v13)) { goto L70; }
       goto L59;
L70:;
      }
     }
    }
   }
   v3 = ecl_cdr(v3);
L5:;
   if (Null(v3)) { goto L74; }
   goto L4;
L74:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for READER-CLOSURE                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L11reader_closure(cl_object v1index)
{
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1index,env0);               /*  INDEX           */
  {cl_object v2;
   v2 = ECL_NIL;
   v2 = ecl_make_cclosure_va((cl_objectfn)LC10__g137,env0,Cblock);
   value0 = v2;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	closure G137                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC10__g137(cl_narg narg, cl_object v1object, ...)
{
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  INDEX           */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = si_instance_ref(v1object, ECL_CONS_CAR(CLV0));
  return value0;
 }
 }
}
/*	function definition for WRITER-CLOSURE                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L13writer_closure(cl_object v1index)
{
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1index,env0);               /*  INDEX           */
  {cl_object v2;
   v2 = ECL_NIL;
   v2 = ecl_make_cclosure_va((cl_objectfn)LC12__g138,env0,Cblock);
   value0 = v2;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	closure G138                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC12__g138(cl_narg narg, cl_object v1value, cl_object v2object, ...)
{
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  INDEX           */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = si_instance_set(v2object, ECL_CONS_CAR(CLV0), v1value);
  return value0;
 }
 }
}
/*	local function GENERATE-ACCESSORS                             */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object LC14generate_accessors(cl_object v1class)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 if (Null(si_of_class_p(2, v1class, VV[21]))) { goto L2; }
 L9std_class_generate_accessors(2, v1class, ECL_T);
 goto L1;
L2:;
 {
  cl_object v2;
  cl_object v3slotd;
  cl_object v4;
  v2 = cl_slot_value(v1class, VV[22]);
  v3slotd = ECL_NIL;
  v4 = v2;
  {
   cl_object v5index;
   v5index = ECL_NIL;
L8:;
   if (!(v4==ECL_NIL)) { goto L10; }
   goto L9;
L10:;
   v3slotd = ECL_CONS_CAR(v4);
   v4 = ECL_CONS_CDR(v4);
   v5index = cl_slot_value(v3slotd, ECL_SYM("LOCATION",1763));
   {
    cl_object v6;
    cl_object v7reader;
    cl_object v8;
    v6 = cl_slot_value(v3slotd, VV[16]);
    v7reader = ECL_NIL;
    v8 = v6;
L22:;
    if (!(v8==ECL_NIL)) { goto L24; }
    goto L23;
L24:;
    v7reader = ECL_CONS_CAR(v8);
    v8 = ECL_CONS_CDR(v8);
    T0 = L11reader_closure(v5index);
    si_fset(4, v7reader, T0, ECL_NIL, ECL_NIL);
    goto L22;
L23:;
   }
   {
    cl_object v6;
    cl_object v7writer;
    cl_object v8;
    v6 = cl_slot_value(v3slotd, VV[18]);
    v7writer = ECL_NIL;
    v8 = v6;
L36:;
    if (!(v8==ECL_NIL)) { goto L38; }
    goto L37;
L38:;
    v7writer = ECL_CONS_CAR(v8);
    v8 = ECL_CONS_CDR(v8);
    T0 = L13writer_closure(v5index);
    si_fset(4, v7writer, T0, ECL_NIL, ECL_NIL);
    goto L36;
L37:;
   }
   goto L8;
L9:;
  }
 }
L1:;
 {
  cl_object v2;
  v2 = cl_slot_value(v1class, VV[23]);
  {
   cl_object v3;
   cl_object v4;
   v3 = ECL_NIL;
   v4 = v2;
L50:;
   if (!(v4==ECL_NIL)) { goto L52; }
   goto L51;
L52:;
   v3 = ECL_CONS_CAR(v4);
   v4 = ECL_CONS_CDR(v4);
   LC14generate_accessors(v3);
   goto L50;
L51:;
   value0 = v2;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}

#include "clos/std-accessors.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclZAU8gYUoabIs9_dpskfE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CLOS;STD-ACCESSORS.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclZAU8gYUoabIs9_dpskfE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[24]);                           /*  SAFE-SLOT-DEFINITION-LOCATION */
 (void)0; /* No entry created for STD-CLASS-SEALED-ACCESSORS */
 (void)0; /* No entry created for STD-CLASS-ACCESSORS */
 ecl_cmp_defun(VV[26]);                           /*  SAFE-ADD-METHOD */
 ecl_cmp_defun(VV[28]);                           /*  STD-CLASS-GENERATE-ACCESSORS */
 (void)0; /* No entry created for READER-CLOSURE */
 (void)0; /* No entry created for WRITER-CLOSURE */
 LC14generate_accessors(ecl_symbol_value(ECL_SYM("+THE-T-CLASS+",1477)));
}
