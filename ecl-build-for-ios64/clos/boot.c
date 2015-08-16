/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CLOS;BOOT.LSP                                     */
#include <ecl/ecl-cmp.h>
#include "clos/boot.eclh"
/*	function definition for MAKE-EMPTY-STANDARD-CLASS             */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object L1make_empty_standard_class(cl_narg narg, cl_object v1name, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 cl_object v2metaclass;
 cl_object v3direct_superclasses;
 cl_object v4direct_slots;
 cl_object v5index;
 ecl_va_list args; ecl_va_start(args,v1name,narg,1);
 {
  cl_object keyvars[8];
  cl_parse_key(args,4,L1make_empty_standard_classkeys,keyvars,NULL,FALSE);
  ecl_va_end(args);
  if (Null(keyvars[4])) {
   v2metaclass = ECL_SYM("STANDARD-CLASS",973);
  } else {
   v2metaclass = keyvars[0];
  }
  v3direct_superclasses = keyvars[1];
  v4direct_slots = keyvars[2];
  v5index = keyvars[3];
 }
 {
  cl_object v6the_metaclass;
  cl_object v7class;
  if (Null(v2metaclass)) { goto L4; }
  v6the_metaclass = ecl_gethash_safe(v2metaclass,ECL_SYM_VAL(cl_env_copy,ECL_SYM("*CLASS-NAME-HASH-TABLE*",1016)),ECL_NIL);
  goto L2;
L4:;
  v6the_metaclass = ECL_NIL;
  goto L2;
L2:;
  value0 = ecl_gethash_safe(v1name,ECL_SYM_VAL(cl_env_copy,ECL_SYM("*CLASS-NAME-HASH-TABLE*",1016)),ECL_NIL);
  if ((value0)!=ECL_NIL) { goto L8; }
  v7class = si_allocate_raw_instance(ECL_NIL, v6the_metaclass, ecl_make_fixnum(22));
  goto L6;
L8:;
  v7class = value0;
  goto L6;
L6:;
  if (!((v1name)==(ECL_SYM("STANDARD-CLASS",973)))) { goto L10; }
  si_Xmake_constant(ECL_SYM("+THE-STANDARD-CLASS+",1480), v7class);
  si_instance_class_set(v7class, v7class);
L10:;
  ecl_instance_set((v7class),(3),(v1name));
  ecl_instance_set((v7class),(5),(ECL_NIL));
  ecl_instance_set((v7class),(9),(ECL_NIL));
  ecl_instance_set((v7class),(10),(ECL_NIL));
  ecl_instance_set((v7class),(11),(ECL_T));
  ecl_instance_set((v7class),(0),(ECL_NIL));
  ecl_instance_set((v7class),(1),(ECL_NIL));
  ecl_instance_set((v7class),(2),(ECL_NIL));
  si_hash_set(v1name, ECL_SYM_VAL(cl_env_copy,ECL_SYM("*CLASS-NAME-HASH-TABLE*",1016)), v7class);
  ecl_instance_set((v7class),(14),(ECL_NIL));
  ecl_instance_set((v7class),(16),(ECL_NIL));
  ecl_instance_set((v7class),(17),(ECL_NIL));
  L3add_slots(v7class, v4direct_slots);
  {
   cl_object v8superclasses;
   {
    cl_object v9name;
    cl_object v10;
    v9name = ECL_NIL;
    v10 = v3direct_superclasses;
    {
     cl_object v11parent;
     v11parent = ECL_NIL;
     {
      cl_object v12;
      cl_object v13;
      v12 = ecl_list1(ECL_NIL);
      v13 = v12;
L36:;
      if (!(v10==ECL_NIL)) { goto L38; }
      goto L37;
L38:;
      v9name = ECL_CONS_CAR(v10);
      v10 = ECL_CONS_CDR(v10);
      v11parent = cl_find_class(1, v9name);
      {
       cl_object v14;
       T0 = ecl_instance_ref((v11parent),(5));
       v14 = CONS(v7class,T0);
       ecl_instance_set((v11parent),(5),(v14));
      }
      T0 = v13;
      v13 = ecl_list1(v11parent);
      (ECL_CONS_CDR(T0)=v13,T0);
      goto L36;
L37:;
      v8superclasses = _ecl_cdr(v12);
      goto L30;
     }
    }
   }
L30:;
   ecl_instance_set((v7class),(4),(v8superclasses));
   {
    cl_object v9;
    v9 = ecl_function_dispatch(cl_env_copy,VV[10])(2, v7class, v8superclasses) /*  COMPUTE-CLOS-CLASS-PRECEDENCE-LIST */;
    ecl_instance_set((v7class),(7),(v9));
   }
  }
  if (Null(v5index)) { goto L54; }
  {
   cl_object v8;
   v8 = ECL_SYM_VAL(cl_env_copy,VV[0]);
   ecl_aset_unsafe(v8,ecl_fixnum(v5index),v7class);
  }
L54:;
  value0 = v7class;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for REMOVE-ACCESSORS                      */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object L2remove_accessors(cl_object v1slotds)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v2i;
  cl_object v3;
  v2i = ECL_NIL;
  v3 = v1slotds;
  {
   cl_object v4j;
   v4j = ECL_NIL;
   {
    cl_object v5;
    cl_object v6;
    v5 = ecl_list1(ECL_NIL);
    v6 = v5;
L6:;
    if (!(v3==ECL_NIL)) { goto L8; }
    goto L7;
L8:;
    v2i = ECL_CONS_CAR(v3);
    v3 = ECL_CONS_CDR(v3);
    v4j = cl_copy_list(v2i);
    {
     cl_object v8;
     cl_object v9;                                /*  FLAG            */
     T0 = _ecl_cdr(v4j);
     value0 = si_rem_f(T0, ECL_SYM("ACCESSOR",983));
     v8 = value0;
     v9 = cl_env_copy->values[1];
     (ECL_CONS_CDR(v4j)=v8,v4j);
    }
    T0 = v6;
    v6 = ecl_list1(v4j);
    (ECL_CONS_CDR(T0)=v6,T0);
    goto L6;
L7:;
    value0 = _ecl_cdr(v5);
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for ADD-SLOTS                             */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object L3add_slots(cl_object v1class, cl_object v2slots)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v3table;
  cl_object v4location_table;
  cl_object v5slots;
  cl_object v6direct_slots;
  cl_object v7effective_slots;
  {
   cl_fixnum v8;
   if (Null(v2slots)) { goto L3; }
   v8 = 24;
   goto L2;
L3:;
   v8 = 0;
L2:;
   v3table = cl_make_hash_table(2, ECL_SYM("SIZE",1308), ecl_make_fixnum(v8));
  }
  {
   cl_fixnum v8;
   if (Null(v2slots)) { goto L7; }
   v8 = 24;
   goto L6;
L7:;
   v8 = 0;
L6:;
   v4location_table = cl_make_hash_table(2, ECL_SYM("SIZE",1308), ecl_make_fixnum(v8));
  }
  v5slots = ecl_function_dispatch(cl_env_copy,VV[12])(1, v2slots) /*  PARSE-SLOTS */;
  {
   cl_object v8slotd;
   cl_object v9;
   v8slotd = ECL_NIL;
   v9 = v5slots;
   {
    cl_object v10;
    cl_object v11;
    v10 = ecl_list1(ECL_NIL);
    v11 = v10;
L15:;
    if (!(v9==ECL_NIL)) { goto L17; }
    goto L16;
L17:;
    v8slotd = ECL_CONS_CAR(v9);
    v9 = ECL_CONS_CDR(v9);
    T0 = v11;
    T1 = (VV[13]->symbol.gfdef);
    T2 = cl_find_class(1, ECL_SYM("STANDARD-DIRECT-SLOT-DEFINITION",1560));
    T3 = cl_apply(3, T1, T2, v8slotd);
    v11 = ecl_list1(T3);
    (ECL_CONS_CDR(T0)=v11,T0);
    goto L15;
L16:;
    v6direct_slots = _ecl_cdr(v10);
    goto L10;
   }
  }
L10:;
  {
   cl_object v8i;
   v8i = ecl_make_fixnum(0);
   {
    cl_object v9slotd;
    cl_object v10;
    v9slotd = ECL_NIL;
    v10 = v5slots;
    {
     cl_object v11name;
     v11name = ECL_NIL;
     {
      cl_object v12s;
      v12s = ECL_NIL;
      {
       cl_object v13;
       cl_object v14;
       v13 = ecl_list1(ECL_NIL);
       v14 = v13;
L36:;
       if (!(v10==ECL_NIL)) { goto L38; }
       goto L37;
L38:;
       v9slotd = ECL_CONS_CAR(v10);
       v10 = ECL_CONS_CDR(v10);
       v11name = cl_getf(2, v9slotd, ECL_SYM("NAME",1273));
       T0 = (VV[13]->symbol.gfdef);
       T1 = cl_find_class(1, ECL_SYM("STANDARD-EFFECTIVE-SLOT-DEFINITION",1561));
       v12s = cl_apply(3, T0, T1, v9slotd);
       ecl_instance_set((v12s),(9),(v8i));
       si_hash_set(v11name, v4location_table, v8i);
       si_hash_set(v11name, v3table, v12s);
       T0 = v14;
       v14 = ecl_list1(v12s);
       (ECL_CONS_CDR(T0)=v14,T0);
       v8i = ecl_one_plus(v8i);
       goto L36;
L37:;
       v7effective_slots = _ecl_cdr(v13);
       goto L28;
      }
     }
    }
   }
  }
L28:;
  ecl_instance_set((v1class),(6),(v7effective_slots));
  ecl_instance_set((v1class),(8),(v6direct_slots));
  {
   cl_fixnum v8;
   v8 = ecl_length(v5slots);
   ecl_instance_set((v1class),(13),(ecl_make_fixnum(v8)));
  }
  ecl_instance_set((v1class),(18),(v3table));
  value0 = ecl_instance_set((v1class),(19),(v4location_table));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}

#include "clos/boot.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecl2IiCj6S8Bemj9_yVP5hE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CLOS;BOOT.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_ecl2IiCj6S8Bemj9_yVP5hE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 {
  cl_object T0;
 T0 = si_make_vector(ECL_T, ecl_make_fixnum(48), ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
 si_Xmake_constant(VV[0], T0);
 }
 ecl_cmp_defun(VV[5]);                            /*  MAKE-EMPTY-STANDARD-CLASS */
 ecl_cmp_defun(VV[11]);                           /*  REMOVE-ACCESSORS */
 (void)0; /* No entry created for ADD-SLOTS */
 {
  cl_object T0, T1;
 {
  cl_object v1all_classes;
  {
   cl_object v2c;
   cl_object v3;
   v2c = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(VVtemp[0]))) FEtype_error_list(VVtemp[0]);
   v3 = VVtemp[0];
   {
    cl_object v4class;
    v4class = ECL_NIL;
    {
     cl_object v5;
     cl_object v6;
     v5 = ecl_list1(ECL_NIL);
     v6 = v5;
L26:;
     if (!(ecl_endp(v3))) { goto L28; }
     goto L27;
L28:;
     v2c = _ecl_car(v3);
     {
      cl_object v7;
      v7 = _ecl_cdr(v3);
      if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
      v3 = v7;
     }
     T0 = (VV[1]->symbol.gfdef);
     v4class = cl_apply(2, T0, v2c);
     if (ecl_unlikely(ECL_ATOM(v6))) FEtype_error_cons(v6);
     T0 = v6;
     v6 = ecl_list1(v4class);
     (ECL_CONS_CDR(T0)=v6,T0);
     goto L26;
L27:;
     v1all_classes = ecl_cdr(v5);
     goto L19;
    }
   }
  }
L19:;
  T0 = cl_find_class(2, ECL_T, ECL_NIL);
  si_Xmake_constant(ECL_SYM("+THE-T-CLASS+",1477), T0);
  T0 = cl_find_class(2, ECL_SYM("CLASS",933), ECL_NIL);
  si_Xmake_constant(ECL_SYM("+THE-CLASS+",1478), T0);
  T0 = cl_find_class(2, VV[3], ECL_NIL);
  si_Xmake_constant(ECL_SYM("+THE-STD-CLASS+",1479), T0);
  T0 = cl_find_class(2, ECL_SYM("FUNCALLABLE-STANDARD-CLASS",1516), ECL_NIL);
  si_Xmake_constant(ECL_SYM("+THE-FUNCALLABLE-STANDARD-CLASS+",1481), T0);
  T0 = cl_find_class(1, ECL_T);
  T1 = cl_find_class(1, ECL_SYM("BUILT-IN-CLASS",929));
  si_instance_class_set(T0, T1);
  {
   cl_object v2;
   cl_object v3;
   v2 = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v1all_classes))) FEtype_error_list(v1all_classes);
   v3 = v1all_classes;
L66:;
   if (!(ecl_endp(v3))) { goto L68; }
   goto L67;
L68:;
   v2 = _ecl_car(v3);
   {
    cl_object v4;
    v4 = _ecl_cdr(v3);
    if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
    v3 = v4;
   }
   si_instance_sig_set(v2);
   goto L66;
L67:;
   goto L62;
  }
L62:;
  {
   cl_object v2;
   v2 = cl_find_class(1, ECL_SYM("METHOD-COMBINATION",956));
   (cl_env_copy->function=ECL_CONS_CAR(VV[14]))->cfun.entry(3, ECL_T, v2, VV[4]) /*  (SETF SLOT-VALUE) */;
  }
  {
   cl_object v2c;
   cl_object v3;
   v2c = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v1all_classes))) FEtype_error_list(v1all_classes);
   v3 = v1all_classes;
L84:;
   if (!(ecl_endp(v3))) { goto L86; }
   goto L85;
L86:;
   v2c = _ecl_car(v3);
   {
    cl_object v4;
    v4 = _ecl_cdr(v3);
    if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
    v3 = v4;
   }
   {
    cl_object v4;
    cl_object v5s;
    cl_object v6;
    v4 = ecl_instance_ref((v2c),(8));
    v5s = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
    v6 = v4;
L99:;
    if (!(ecl_endp(v6))) { goto L101; }
    goto L100;
L101:;
    v5s = _ecl_car(v6);
    {
     cl_object v7;
     v7 = _ecl_cdr(v6);
     if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
     v6 = v7;
    }
    si_instance_sig_set(v5s);
    goto L99;
L100:;
   }
   {
    cl_object v4;
    cl_object v5s;
    cl_object v6;
    v4 = ecl_instance_ref((v2c),(6));
    v5s = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
    v6 = v4;
L116:;
    if (!(ecl_endp(v6))) { goto L118; }
    goto L117;
L118:;
    v5s = _ecl_car(v6);
    {
     cl_object v7;
     v7 = _ecl_cdr(v6);
     if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
     v6 = v7;
    }
    si_instance_sig_set(v5s);
    goto L116;
L117:;
   }
   goto L84;
L85:;
  }
 }
 }
}
