/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:LSP;FFI.LSP                                       */
#include <ecl/ecl-cmp.h>
#include "lsp/ffi.eclh"
/*	local function DEF-CONSTANT                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC1def_constant(cl_object v1, cl_object v2)
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
   cl_object v5value;
   cl_object v6;
   cl_object v7export;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v8;
    v8 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4name = v8;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v8;
    v8 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5value = v8;
   }
   v6 = si_search_keyword(2, v3, ECL_SYM("EXPORT",1233));
   if (!((v6)==(ECL_SYM("MISSING-KEYWORD",1929)))) { goto L16; }
   v7export = ECL_NIL;
   goto L15;
L16:;
   v7export = v6;
L15:;
   si_check_keyword(2, v3, VV[0]);
   T0 = cl_list(3, ECL_SYM("DEFCONSTANT",277), v4name, v5value);
   if (Null(v7export)) { goto L20; }
   T2 = cl_list(2, ECL_SYM("QUOTE",679), v4name);
   T1 = cl_list(2, ECL_SYM("EXPORT",344), T2);
   goto L19;
L20:;
   T1 = ECL_NIL;
L19:;
   T2 = cl_list(2, ECL_SYM("QUOTE",679), v4name);
   value0 = cl_list(5, ECL_SYM("EVAL-WHEN",340), VV[1], T0, T1, T2);
   return value0;
  }
 }
}
/*	local function DEF-FOREIGN-TYPE                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC2def_foreign_type(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4name;
   cl_object v5definition;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4name = v6;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5definition = v6;
   }
   if (Null(v3)) { goto L14; }
   si_dm_too_many_arguments(v1);
L14:;
   T0 = cl_list(2, ECL_SYM("QUOTE",679), v4name);
   T1 = cl_list(3, ECL_SYM("GETHASH",413), T0, VV[3]);
   T2 = cl_list(2, ECL_SYM("QUOTE",679), v5definition);
   T3 = cl_list(3, ECL_SYM("SETF",750), T1, T2);
   value0 = cl_list(3, ECL_SYM("EVAL-WHEN",340), VV[1], T3);
   return value0;
  }
 }
}
/*	local function DEF-TYPE                                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC3def_type(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4name;
   cl_object v5definition;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4name = v6;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5definition = v6;
   }
   if (Null(v3)) { goto L14; }
   si_dm_too_many_arguments(v1);
L14:;
   value0 = cl_listX(3, ECL_SYM("DEFTYPE",288), v4name, VV[5]);
   return value0;
  }
 }
}
/*	function definition for %CONVERT-TO-FFI-TYPE                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4_convert_to_ffi_type(cl_narg narg, cl_object v1type, ...)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2context;
  va_list args; va_start(args,v1type);
  {
   int i = 1;
   if (i >= narg) {
    v2context = ECL_NIL;
   } else {
    i++;
    v2context = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (!(ECL_ATOM(v1type))) { goto L2; }
  if (Null(ecl_memql(v1type,v2context))) { goto L4; }
  value0 = v1type;
  cl_env_copy->nvalues = 1;
  return value0;
L4:;
  {
   cl_object v4;                                  /*  VALUE           */
   cl_object v5;                                  /*  PRESENT-P       */
   value0 = cl_gethash(3, v1type, ecl_symbol_value(VV[3]), v1type);
   v4 = value0;
   v5 = cl_env_copy->values[1];
   if (Null(v5)) { goto L7; }
   T0 = CONS(v1type,v2context);
   value0 = L4_convert_to_ffi_type(2, v4, T0);
   return value0;
L7:;
   value0 = v4;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L2:;
  T0 = ecl_car(v1type);
  T1 = L4_convert_to_ffi_type(2, T0, v2context);
  T2 = ecl_cdr(v1type);
  T3 = L4_convert_to_ffi_type(2, T2, v2context);
  value0 = CONS(T1,T3);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function %ALIGN-DATA                                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC5_align_data(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4data;
   cl_object v5align;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4data = v6;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5align = v6;
   }
   if (Null(v3)) { goto L14; }
   si_dm_too_many_arguments(v1);
L14:;
   T0 = cl_list(3, ECL_SYM("/",21), v4data, v5align);
   T1 = cl_list(2, ECL_SYM("CEILING",199), T0);
   T2 = cl_list(3, ECL_SYM("*",18), T1, v5align);
   value0 = cl_list(3, ECL_SYM("SETF",750), v4data, T2);
   return value0;
  }
 }
}
/*	function definition for SIZE-OF-FOREIGN-TYPE                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6size_of_foreign_type(cl_object v1name)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2size;
   cl_object v3align;
   cl_object v4type;
   v2size = ecl_make_fixnum(0);
   v3align = ECL_NIL;
   v4type = L4_convert_to_ffi_type(1, v1name);
   if ((v4type)!=ECL_NIL) { goto L4; }
   cl_error(2, _ecl_static_1, v1name);
L4:;
   if (!(ECL_SYMBOLP(v4type))) { goto L7; }
   v2size = si_size_of_foreign_elt_type(v4type);
   v3align = si_alignment_of_foreign_elt_type(v4type);
   goto L6;
L7:;
   if (!(ECL_ATOM(v4type))) { goto L12; }
   cl_error(2, _ecl_static_2, v1name);
   goto L6;
L12:;
   v1name = ecl_car(v4type);
   if (!((v1name)==(ECL_SYM("STRUCT",1379)))) { goto L14; }
   v2size = L11slot_position(v4type, ECL_NIL);
   T0 = (ECL_SYM("MAX",551)->symbol.gfdef);
   {
    cl_object v5;
    cl_object v6;
    cl_object v7;
    v5 = ecl_cdr(v4type);
    v6 = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
    v7 = v5;
    {
     cl_object v8;
     cl_object v9;
     v8 = ecl_list1(ECL_NIL);
     v9 = v8;
L29:;
     if (!(ecl_endp(v7))) { goto L31; }
     goto L30;
L31:;
     v6 = _ecl_car(v7);
     {
      cl_object v10;
      v10 = _ecl_cdr(v7);
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      v7 = v10;
     }
     if (ecl_unlikely(ECL_ATOM(v9))) FEtype_error_cons(v9);
     T2 = v9;
     {
      cl_object v11;                              /*  FIELD-SIZE      */
      cl_object v12;                              /*  FIELD-ALIGN     */
      T4 = ecl_cadr(v6);
      value0 = L6size_of_foreign_type(T4);
      v11 = value0;
      {
       const int v13 = cl_env_copy->nvalues;
       cl_object v14;
       v14 = (v13<=1)? ECL_NIL : cl_env_copy->values[1];
       v12 = v14;
      }
      T3 = v12;
     }
     v9 = ecl_list1(T3);
     (ECL_CONS_CDR(T2)=v9,T2);
     goto L29;
L30:;
     T1 = ecl_cdr(v8);
     goto L22;
    }
   }
L22:;
   v3align = cl_apply(2, T0, T1);
   T0 = ecl_divide(v2size,v3align);
   T1 = ecl_ceiling1(T0);
   v2size = ecl_times(T1,v3align);
   goto L6;
L14:;
   if (!((v1name)==(ECL_SYM("ARRAY",1199)))) { goto L48; }
   v2size = ecl_caddr(v4type);
   if (Null(v2size)) { goto L53; }
   if ((cl_realp(v2size))!=ECL_NIL) { goto L50; }
   goto L51;
L53:;
   goto L51;
L51:;
   cl_error(2, _ecl_static_3, v4type);
L50:;
   {
    cl_object v6;                                 /*  ELT-SIZE        */
    cl_object v7;                                 /*  ELT-ALIGN       */
    T0 = ecl_cadr(v4type);
    value0 = L6size_of_foreign_type(T0);
    v6 = value0;
    {
     const int v8 = cl_env_copy->nvalues;
     cl_object v9;
     v9 = (v8<=1)? ECL_NIL : cl_env_copy->values[1];
     v7 = v9;
    }
    v2size = ecl_times(v2size,v6);
    v3align = v7;
    goto L6;
   }
L48:;
   if (!((v1name)==(ECL_SYM("UNION",1380)))) { goto L60; }
   {
    cl_object v5;
    v5 = ecl_cdr(v4type);
    goto L65;
L64:;
    {
     cl_object v6field;
     v6field = ecl_car(v5);
     {
      cl_object v8;                               /*  FIELD-SIZE      */
      cl_object v9;                               /*  FIELD-ALIGN     */
      T0 = ecl_cadr(v6field);
      value0 = L6size_of_foreign_type(T0);
      v8 = value0;
      {
       const int v10 = cl_env_copy->nvalues;
       cl_object v11;
       v11 = (v10<=1)? ECL_NIL : cl_env_copy->values[1];
       v9 = v11;
      }
      if (!(ecl_number_compare(v8,v2size)>0)) { goto L71; }
      v2size = v8;
L71:;
      if (v3align==ECL_NIL) { goto L75; }
      if (!(ecl_number_compare(v9,v3align)>0)) { goto L69; }
      goto L74;
L75:;
L74:;
      v3align = v9;
     }
L69:;
    }
    v5 = ecl_cdr(v5);
L65:;
    if (Null(v5)) { goto L80; }
    goto L64;
L80:;
    goto L6;
   }
L60:;
   if (!((v1name)==(ECL_SYM("*",18)))) { goto L82; }
   v2size = si_size_of_foreign_elt_type(ECL_SYM("POINTER-VOID",1377));
   v3align = si_alignment_of_foreign_elt_type(ECL_SYM("POINTER-VOID",1377));
   goto L6;
L82:;
   if (!((v1name)==(ECL_SYM("QUOTE",679)))) { goto L87; }
   v1name = ecl_cadr(v4type);
   goto TTL;
L87:;
   cl_error(2, _ecl_static_4, v1name);
L6:;
   value0 = v3align;
   if ((value0)!=ECL_NIL) { goto L93; }
   T0 = ecl_make_fixnum(0);
   goto L91;
L93:;
   T0 = value0;
   goto L91;
L91:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = T0;
   cl_env_copy->values[0] = v2size;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for ALLOCATE-FOREIGN-OBJECT               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7allocate_foreign_object(cl_narg narg, cl_object v1type, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2size;
  cl_object v3size_flag;
  va_list args; va_start(args,v1type);
  {
   int i = 1;
   if (i >= narg) {
    v2size = ecl_make_fixnum(0);
    v3size_flag = ECL_NIL;
   } else {
    i++;
    v2size = va_arg(args,cl_object);
    v3size_flag = ECL_T;
   }
  }
  va_end(args);
  {
   cl_object v4type_size;
   v4type_size = L6size_of_foreign_type(v1type);
   if (!(v3size_flag==ECL_NIL)) { goto L3; }
   value0 = si_allocate_foreign_data(v1type, v4type_size);
   return value0;
L3:;
   if (!(ECL_FIXNUMP(v2size))) { goto L5; }
   if (!(ecl_number_compare(v2size,ecl_make_fixnum(0))>=0)) { goto L5; }
   {
    cl_object v5bytes;
    v5bytes = ecl_times(v2size,v4type_size);
    T0 = cl_list(3, ECL_SYM("ARRAY",1199), v1type, v2size);
    value0 = si_allocate_foreign_data(T0, v5bytes);
    return value0;
   }
L5:;
   value0 = cl_error(2, _ecl_static_5, v2size);
   return value0;
  }
 }
}
/*	function definition for FREE-FOREIGN-OBJECT                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8free_foreign_object(cl_object v1ptr)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = si_free_foreign_data(v1ptr);
  return value0;
 }
}
/*	local function DEF-ENUM                                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC9def_enum(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4name;
   cl_object v5values_list;
   cl_object v6;
   cl_object v7separator_string;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v8;
    v8 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4name = v8;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v8;
    v8 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5values_list = v8;
   }
   v6 = si_search_keyword(2, v3, VV[12]);
   if (!((v6)==(ECL_SYM("MISSING-KEYWORD",1929)))) { goto L16; }
   v7separator_string = _ecl_static_6;
   goto L15;
L16:;
   v7separator_string = v6;
L15:;
   si_check_keyword(2, v3, VV[13]);
   {
    cl_object v8value;
    cl_object v9field;
    cl_object v10forms;
    v8value = ecl_make_fixnum(-1);
    v9field = ECL_NIL;
    v10forms = ECL_NIL;
    v7separator_string = cl_string(v7separator_string);
    {
     cl_object v11;
     v11 = v5values_list;
     goto L28;
L27:;
     {
      cl_object v12item;
      v12item = ecl_car(v11);
      if (!(ECL_SYMBOLP(v12item))) { goto L33; }
      v9field = v12item;
      v8value = ecl_plus(v8value,ecl_make_fixnum(1));
      goto L32;
L33:;
      {
       cl_object v13;
       if (!(ECL_CONSP(v12item))) { goto L40; }
       v9field = ecl_car(v12item);
       if (!(ECL_SYMBOLP(v9field))) { goto L40; }
       v8value = ecl_cadr(v12item);
       if (!(ECL_FIXNUMP(v8value)||ECL_BIGNUMP(v8value))) { goto L40; }
       T0 = ecl_cddr(v12item);
       v13 = ecl_make_bool(ecl_endp(T0));
       goto L38;
L40:;
       v13 = ECL_NIL;
       goto L38;
L38:;
       if (Null(v13)) { goto L46; }
       goto L32;
L46:;
       cl_error(2, _ecl_static_7, v5values_list);
      }
L32:;
      T0 = ecl_symbol_name(v4name);
      T1 = cl_string(v9field);
      v9field = cl_concatenate(4, ECL_SYM("STRING",805), T0, v7separator_string, T1);
      T0 = cl_symbol_package(v4name);
      T1 = cl_intern(2, v9field, T0);
      T2 = cl_list(2, ECL_SYM("QUOTE",679), v8value);
      T3 = cl_list(3, ECL_SYM("DEFCONSTANT",277), T1, T2);
      v10forms = CONS(T3,v10forms);
     }
     v11 = ecl_cdr(v11);
L28:;
     if (Null(v11)) { goto L54; }
     goto L27;
L54:;
    }
    T0 = cl_list(3, VV[4], v4name, ECL_SYM("INT",1369));
    value0 = cl_listX(3, ECL_SYM("PROGN",671), T0, v10forms);
    return value0;
   }
  }
 }
}
/*	local function DEF-STRUCT                                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC10def_struct(cl_object v1, cl_object v2)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4name;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4name = v5;
   }
   {
    cl_object v5;
    cl_object v6struct_type;
    cl_object v7field;
    cl_object v8type;
    v5 = ecl_list1(ECL_SYM("STRUCT",1379));
    v6struct_type = v5;
    v7field = ECL_NIL;
    v8type = ECL_NIL;
    {
     cl_object v9;
     T0 = cl_list(2, ECL_SYM("*",18), v4name);
     v9 = cl_subst(3, T0, ECL_SYM("POINTER-SELF",1376), v3);
     goto L16;
L15:;
     {
      cl_object v10item;
      v10item = ecl_car(v9);
      if (!(ECL_CONSP(v10item))) { goto L21; }
      {
       cl_fixnum v11;
       v11 = ecl_length(v10item);
       if (!((v11)==(2))) { goto L21; }
      }
      v7field = ecl_car(v10item);
      if (!(ECL_SYMBOLP(v7field))) { goto L21; }
      v8type = ecl_cadr(v10item);
      goto L20;
L21:;
      cl_error(2, _ecl_static_8, v10item);
L20:;
      T0 = cl_list(2, v7field, v8type);
      v6struct_type = CONS(T0,v6struct_type);
     }
     v9 = ecl_cdr(v9);
L16:;
     if (Null(v9)) { goto L31; }
     goto L15;
L31:;
    }
    T0 = cl_nreverse(v6struct_type);
    value0 = cl_list(3, VV[4], v4name, T0);
    return value0;
   }
  }
 }
}
/*	function definition for SLOT-POSITION                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L11slot_position(cl_object v1type, cl_object v2field)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  v1type = L4_convert_to_ffi_type(1, v1type);
  {
   cl_object v3ndx;
   cl_object v4is_union;
   v3ndx = ecl_make_fixnum(0);
   v4is_union = ECL_NIL;
   if (!(ECL_ATOM(v1type))) { goto L6; }
   cl_error(2, _ecl_static_9, v1type);
   goto L5;
L6:;
   {
    cl_object v5;
    T0 = ecl_car(v1type);
    v5 = ecl_make_bool((T0)==(ECL_SYM("STRUCT",1379)));
    if (Null(v5)) { goto L9; }
    goto L5;
L9:;
    T0 = ecl_car(v1type);
    if (!((T0)==(ECL_SYM("UNION",1380)))) { goto L11; }
    v4is_union = ECL_T;
    goto L5;
L11:;
    cl_error(2, _ecl_static_9, v1type);
   }
L5:;
   {
    cl_object v5;
    v5 = ecl_cdr(v1type);
    goto L18;
L17:;
    {
     cl_object v6slot;
     v6slot = ecl_car(v5);
     {
      cl_object v7slot_name;
      cl_object v8slot_type;
      v7slot_name = ecl_car(v6slot);
      v8slot_type = ecl_cadr(v6slot);
      {
       cl_object v10;                             /*  SLOT-SIZE       */
       cl_object v11;                             /*  SLOT-ALIGN      */
       value0 = L6size_of_foreign_type(v8slot_type);
       v10 = value0;
       {
        const int v12 = cl_env_copy->nvalues;
        cl_object v13;
        v13 = (v12<=1)? ECL_NIL : cl_env_copy->values[1];
        v11 = v13;
       }
       T0 = ecl_divide(v3ndx,v11);
       T1 = ecl_ceiling1(T0);
       v3ndx = ecl_times(T1,v11);
       if (!((v7slot_name)==(v2field))) { goto L28; }
       cl_env_copy->nvalues = 3;
       cl_env_copy->values[2] = v10;
       cl_env_copy->values[1] = v8slot_type;
       cl_env_copy->values[0] = v3ndx;
       return cl_env_copy->values[0];
L28:;
       if ((v4is_union)!=ECL_NIL) { goto L22; }
       v3ndx = ecl_plus(v3ndx,v10);
      }
     }
L22:;
    }
    v5 = ecl_cdr(v5);
L18:;
    if (Null(v5)) { goto L34; }
    goto L17;
L34:;
   }
   cl_env_copy->nvalues = 3;
   cl_env_copy->values[2] = ECL_NIL;
   cl_env_copy->values[1] = ECL_NIL;
   cl_env_copy->values[0] = v3ndx;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for GET-SLOT-VALUE                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L12get_slot_value(cl_object v1object, cl_object v2struct_type, cl_object v3field)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v5;                                  /*  SLOT-NDX        */
   cl_object v6;                                  /*  SLOT-TYPE       */
   cl_object v7;                                  /*  SLOT-SIZE       */
   value0 = L11slot_position(v2struct_type, v3field);
   v5 = value0;
   {
    const int v8 = cl_env_copy->nvalues;
    cl_object v9;
    v9 = (v8<=1)? ECL_NIL : cl_env_copy->values[1];
    v6 = v9;
    v9 = (v8<=2)? ECL_NIL : cl_env_copy->values[2];
    v7 = v9;
   }
   if ((v7)!=ECL_NIL) { goto L2; }
   cl_error(3, _ecl_static_10, v3field, v2struct_type);
L2:;
   value0 = L19_foreign_data_ref(4, v1object, v5, v6, v7);
   return value0;
  }
 }
}
/*	function definition for (SETF GET-SLOT-VALUE)                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L13_setf_get_slot_value_(cl_object v1value, cl_object v2object, cl_object v3struct_type, cl_object v4field)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6;                                  /*  SLOT-NDX        */
   cl_object v7;                                  /*  SLOT-TYPE       */
   cl_object v8;                                  /*  SLOT-SIZE       */
   value0 = L11slot_position(v3struct_type, v4field);
   v6 = value0;
   {
    const int v9 = cl_env_copy->nvalues;
    cl_object v10;
    v10 = (v9<=1)? ECL_NIL : cl_env_copy->values[1];
    v7 = v10;
    v10 = (v9<=2)? ECL_NIL : cl_env_copy->values[2];
    v8 = v10;
   }
   if ((v8)!=ECL_NIL) { goto L2; }
   cl_error(3, _ecl_static_10, v4field, v3struct_type);
L2:;
   value0 = L18_foreign_data_set(v2object, v6, v7, v1value);
   return value0;
  }
 }
}
/*	function definition for GET-SLOT-POINTER                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L14get_slot_pointer(cl_object v1object, cl_object v2struct_type, cl_object v3field)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v5;                                  /*  SLOT-NDX        */
   cl_object v6;                                  /*  SLOT-TYPE       */
   cl_object v7;                                  /*  SLOT-SIZE       */
   value0 = L11slot_position(v2struct_type, v3field);
   v5 = value0;
   {
    const int v8 = cl_env_copy->nvalues;
    cl_object v9;
    v9 = (v8<=1)? ECL_NIL : cl_env_copy->values[1];
    v6 = v9;
    v9 = (v8<=2)? ECL_NIL : cl_env_copy->values[2];
    v7 = v9;
   }
   if ((v7)!=ECL_NIL) { goto L2; }
   cl_error(3, _ecl_static_10, v3field, v2struct_type);
L2:;
   value0 = si_foreign_data_pointer(v1object, v5, v7, v6);
   return value0;
  }
 }
}
/*	local function DEF-ARRAY-POINTER                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC15def_array_pointer(cl_object v1, cl_object v2)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4name;
   cl_object v5element_type;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4name = v6;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5element_type = v6;
   }
   if (Null(v3)) { goto L14; }
   si_dm_too_many_arguments(v1);
L14:;
   T0 = cl_list(2, ECL_SYM("*",18), v5element_type);
   value0 = cl_list(3, VV[4], v4name, T0);
   return value0;
  }
 }
}
/*	function definition for DEREF-ARRAY                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L16deref_array(cl_object v1array, cl_object v2array_type, cl_object v3position)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  v2array_type = L4_convert_to_ffi_type(1, v2array_type);
  {
   cl_object v4element_type;
   cl_object v5element_size;
   cl_object v6ndx;
   cl_object v7length;
   v4element_type = ecl_cadr(v2array_type);
   v5element_size = L6size_of_foreign_type(v4element_type);
   v6ndx = ecl_times(v3position,v5element_size);
   value0 = ecl_caddr(v2array_type);
   if ((value0)!=ECL_NIL) { goto L8; }
   v7length = ECL_SYM("*",18);
   goto L6;
L8:;
   v7length = value0;
   goto L6;
L6:;
   if ((v7length)==(ECL_SYM("*",18))) { goto L10; }
   if ((cl_G(3, v7length, v3position, ecl_make_fixnum(-1)))!=ECL_NIL) { goto L10; }
   cl_error(2, _ecl_static_11, v1array);
L10:;
   T0 = ecl_plus(v6ndx,v5element_size);
   T1 = si_foreign_data_recast(v1array, T0, v2array_type);
   value0 = L19_foreign_data_ref(4, T1, v6ndx, v4element_type, v5element_size);
   return value0;
  }
 }
}
/*	function definition for (SETF DEREF-ARRAY)                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L17_setf_deref_array_(cl_object v1value, cl_object v2array, cl_object v3array_type, cl_object v4position)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  v3array_type = L4_convert_to_ffi_type(1, v3array_type);
  {
   cl_object v5element_type;
   cl_object v6element_size;
   cl_object v7ndx;
   cl_object v8length;
   v5element_type = ecl_cadr(v3array_type);
   v6element_size = L6size_of_foreign_type(v5element_type);
   v7ndx = ecl_times(v4position,v6element_size);
   value0 = ecl_caddr(v3array_type);
   if ((value0)!=ECL_NIL) { goto L8; }
   v8length = ECL_SYM("*",18);
   goto L6;
L8:;
   v8length = value0;
   goto L6;
L6:;
   if ((v8length)==(ECL_SYM("*",18))) { goto L10; }
   if ((cl_G(3, v8length, v4position, ecl_make_fixnum(-1)))!=ECL_NIL) { goto L10; }
   cl_error(2, _ecl_static_11, v2array);
L10:;
   T0 = ecl_plus(v7ndx,v6element_size);
   T1 = si_foreign_data_recast(v2array, T0, v3array_type);
   value0 = L18_foreign_data_set(T1, v7ndx, v5element_type, v1value);
   return value0;
  }
 }
}
/*	function definition for %FOREIGN-DATA-SET                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L18_foreign_data_set(cl_object v1obj, cl_object v2ndx, cl_object v3type, cl_object v4value)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(si_foreign_elt_type_p(v3type))) { goto L1; }
  value0 = si_foreign_data_set_elt(v1obj, v2ndx, v3type, v4value);
  return value0;
L1:;
  if (!(ECL_ATOM(v3type))) { goto L3; }
  value0 = cl_error(2, _ecl_static_12, v3type);
  return value0;
L3:;
  T0 = ecl_car(v3type);
  if (!((T0)==(ECL_SYM("*",18)))) { goto L5; }
  value0 = si_foreign_data_set_elt(v1obj, v2ndx, ECL_SYM("POINTER-VOID",1377), v4value);
  return value0;
L5:;
  value0 = si_foreign_data_set(v1obj, v2ndx, v4value);
  return value0;
 }
}
/*	function definition for %FOREIGN-DATA-REF                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L19_foreign_data_ref(cl_narg narg, cl_object v1obj, cl_object v2ndx, cl_object v3type, ...)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>4)) FEwrong_num_arguments_anonym();
 {
  cl_object v4size;
  cl_object v5size_p;
  va_list args; va_start(args,v3type);
  {
   int i = 3;
   if (i >= narg) {
    v4size = ecl_make_fixnum(0);
    v5size_p = ECL_NIL;
   } else {
    i++;
    v4size = va_arg(args,cl_object);
    v5size_p = ECL_T;
   }
  }
  va_end(args);
  if (Null(si_foreign_elt_type_p(v3type))) { goto L2; }
  value0 = si_foreign_data_ref_elt(v1obj, v2ndx, v3type);
  return value0;
L2:;
  if (!(ECL_ATOM(v3type))) { goto L4; }
  value0 = cl_error(2, _ecl_static_12, v3type);
  return value0;
L4:;
  T0 = ecl_car(v3type);
  if (!((T0)==(ECL_SYM("*",18)))) { goto L6; }
  T0 = si_foreign_data_ref_elt(v1obj, v2ndx, ECL_SYM("POINTER-VOID",1377));
  T1 = ecl_cadr(v3type);
  T2 = L6size_of_foreign_type(T1);
  value0 = si_foreign_data_recast(T0, T2, v3type);
  return value0;
L6:;
  if (Null(v5size_p)) { goto L9; }
  T0 = v4size;
  goto L8;
L9:;
  T0 = L6size_of_foreign_type(v3type);
L8:;
  value0 = si_foreign_data_ref(v1obj, v2ndx, T0, v3type);
  return value0;
 }
}
/*	local function DEF-UNION                                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC20def_union(cl_object v1, cl_object v2)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4name;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4name = v5;
   }
   {
    cl_object v5;
    cl_object v6struct_type;
    cl_object v7field;
    cl_object v8type;
    v5 = ecl_list1(ECL_SYM("UNION",1380));
    v6struct_type = v5;
    v7field = ECL_NIL;
    v8type = ECL_NIL;
    {
     cl_object v9;
     T0 = cl_list(2, ECL_SYM("*",18), v6struct_type);
     v9 = cl_subst(3, T0, ECL_SYM("POINTER-SELF",1376), v3);
     goto L16;
L15:;
     {
      cl_object v10item;
      v10item = ecl_car(v9);
      if (!(ECL_CONSP(v10item))) { goto L23; }
      {
       cl_fixnum v11;
       v11 = ecl_length(v10item);
       if (!((v11)==(2))) { goto L23; }
      }
      v7field = ecl_car(v10item);
      if (ECL_SYMBOLP(v7field)) { goto L20; }
      goto L21;
L23:;
      goto L21;
L21:;
      cl_error(2, _ecl_static_13, v10item);
L20:;
      v8type = ecl_cadr(v10item);
      T0 = cl_list(2, v7field, v8type);
      v6struct_type = CONS(T0,v6struct_type);
     }
     v9 = ecl_cdr(v9);
L16:;
     if (Null(v9)) { goto L33; }
     goto L15;
L33:;
    }
    T0 = cl_nreverse(v6struct_type);
    value0 = cl_list(3, VV[4], v4name, T0);
    return value0;
   }
  }
 }
}
/*	function definition for POINTER-ADDRESS                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L21pointer_address(cl_object v1ptr)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = si_foreign_data_address(v1ptr);
  return value0;
 }
}
/*	function definition for DEREF-POINTER                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L22deref_pointer(cl_object v1ptr, cl_object v2type)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  v2type = L4_convert_to_ffi_type(1, v2type);
  if (Null(si_foreign_elt_type_p(v2type))) { goto L3; }
  value0 = si_foreign_data_ref_elt(v1ptr, ecl_make_fixnum(0), v2type);
  return value0;
L3:;
  if (!(ECL_ATOM(v2type))) { goto L5; }
  value0 = cl_error(2, _ecl_static_12, v2type);
  return value0;
L5:;
  T0 = ecl_car(v2type);
  if (!((T0)==(ECL_SYM("*",18)))) { goto L7; }
  T0 = si_foreign_data_ref_elt(v1ptr, ecl_make_fixnum(0), ECL_SYM("POINTER-VOID",1377));
  T1 = ecl_cadr(v2type);
  T2 = L6size_of_foreign_type(T1);
  T3 = ecl_cadr(v2type);
  value0 = si_foreign_data_recast(T0, T2, T3);
  return value0;
L7:;
  value0 = cl_error(2, _ecl_static_14, v1ptr);
  return value0;
 }
}
/*	function definition for (SETF DEREF-POINTER)                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L23_setf_deref_pointer_(cl_object v1value, cl_object v2ptr, cl_object v3type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  v3type = L4_convert_to_ffi_type(1, v3type);
  if (Null(si_foreign_elt_type_p(v3type))) { goto L3; }
  value0 = si_foreign_data_set_elt(v2ptr, ecl_make_fixnum(0), v3type, v1value);
  return value0;
L3:;
  value0 = si_foreign_data_set(v2ptr, ecl_make_fixnum(0), v1value);
  return value0;
 }
}
/*	function definition for MAKE-NULL-POINTER                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L24make_null_pointer(cl_object v1type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = si_allocate_foreign_data(v1type, ecl_make_fixnum(0));
  return value0;
 }
}
/*	function definition for MAKE-POINTER                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L25make_pointer(cl_object v1addr, cl_object v2type)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = L6size_of_foreign_type(v2type);
  value0 = ecl_make_foreign_data(v2type, ecl_to_ulong(T0), (void*)ecl_to_ulong(v1addr));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for NULL-CHAR-P                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L26null_char_p(cl_object v1char)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_make_bool((v1char)==(CODE_CHAR(0)));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for ENSURE-CHAR-CHARACTER                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L27ensure_char_character(cl_object v1char)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_CHARACTERP(v1char))) { goto L1; }
  value0 = v1char;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (!(ECL_FIXNUMP(v1char)||ECL_BIGNUMP(v1char))) { goto L3; }
  value0 = cl_code_char(v1char);
  return value0;
L3:;
  value0 = cl_error(2, _ecl_static_15, v1char);
  return value0;
 }
}
/*	function definition for ENSURE-CHAR-INTEGER                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L28ensure_char_integer(cl_object v1char)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_CHARACTERP(v1char))) { goto L1; }
  value0 = cl_char_code(v1char);
  return value0;
L1:;
  if (!(ECL_FIXNUMP(v1char)||ECL_BIGNUMP(v1char))) { goto L3; }
  value0 = v1char;
  cl_env_copy->nvalues = 1;
  return value0;
L3:;
  value0 = cl_error(2, _ecl_static_16, v1char);
  return value0;
 }
}
/*	function definition for ENSURE-CHAR-STORABLE                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L29ensure_char_storable(cl_object v1char)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = v1char;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for CHAR-ARRAY-TO-POINTER                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L30char_array_to_pointer(cl_object v1obj)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = si_foreign_data_pointer(v1obj, ecl_make_fixnum(0), ecl_make_fixnum(1), VV[35]);
  return value0;
 }
}
/*	local function CONVERT-FROM-CSTRING                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC31convert_from_cstring(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4object;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4object = v5;
   }
   if (Null(v3)) { goto L8; }
   si_dm_too_many_arguments(v1);
L8:;
   value0 = v4object;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function CONVERT-TO-CSTRING                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC32convert_to_cstring(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4object;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4object = v5;
   }
   if (Null(v3)) { goto L8; }
   si_dm_too_many_arguments(v1);
L8:;
   value0 = cl_list(2, ECL_SYM("COPY-TO-SIMPLE-BASE-STRING",1060), v4object);
   return value0;
  }
 }
}
/*	local function FREE-CSTRING                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC33free_cstring(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4object;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4object = v5;
   }
   if (Null(v3)) { goto L8; }
   si_dm_too_many_arguments(v1);
L8:;
   value0 = v4object;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function WITH-CSTRING                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC34with_cstring(cl_object v1, cl_object v2)
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
   cl_object v6cstring;
   cl_object v7string;
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
    v6cstring = v8;
   }
   if (!(v5==ECL_NIL)) { goto L16; }
   si_dm_too_few_arguments(v1);
L16:;
   {
    cl_object v8;
    v8 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v7string = v8;
   }
   if (Null(v5)) { goto L21; }
   si_dm_too_many_arguments(v1);
L21:;
   T0 = cl_list(2, VV[38], v7string);
   T1 = cl_list(2, v6cstring, T0);
   T2 = ecl_list1(T1);
   value0 = cl_listX(3, ECL_SYM("LET",477), T2, v3);
   return value0;
  }
 }
}
/*	local function WITH-CSTRINGS                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC35with_cstrings(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2;
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
   if (Null(v4bindings)) { goto L8; }
   T0 = ecl_car(v4bindings);
   T1 = ecl_cdr(v4bindings);
   T2 = cl_listX(3, ECL_SYM("WITH-CSTRINGS",2020), T1, v3);
   value0 = cl_list(3, VV[40], T0, T2);
   return value0;
L8:;
   value0 = CONS(ECL_SYM("PROGN",671),v3);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for FOREIGN-STRING-LENGTH                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L36foreign_string_length(cl_object v1foreign_string)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_make_int(strlen((v1foreign_string)->foreign.data));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for CONVERT-FROM-FOREIGN-STRING           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L37convert_from_foreign_string(cl_narg narg, cl_object v1foreign_string, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2length;
  cl_object v3null_terminated_p;
  ecl_va_list args; ecl_va_start(args,v1foreign_string,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L37convert_from_foreign_stringkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v2length = keyvars[0];
   if (Null(keyvars[3])) {
    v3null_terminated_p = ECL_T;
   } else {
    v3null_terminated_p = keyvars[1];
   }
  }
  if ((v2length)!=ECL_NIL) { goto L3; }
  if (Null(v3null_terminated_p)) { goto L3; }
  v2length = L36foreign_string_length(v1foreign_string);
  goto L2;
L3:;
  if (ECL_FIXNUMP(v2length)||ECL_BIGNUMP(v2length)) { goto L2; }
  cl_error(2, _ecl_static_17, v2length);
L2:;
  {
   cl_object v4;
   {
	cl_index length = ecl_to_fixnum(v2length);
	cl_object output = ecl_alloc_simple_base_string(length);
	memcpy(output->base_string.self, (v1foreign_string)->foreign.data, length);
	v4= output;
	}
   value0 = v4;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for CONVERT-TO-FOREIGN-STRING             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L38convert_to_foreign_string(cl_object v1string_designator)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2lisp_string;
   v2lisp_string = cl_string(v1string_designator);
   {
    cl_object v3;
    {
	cl_object lisp_string = v2lisp_string;
	cl_index size = lisp_string->base_string.fillp;
	cl_object output = ecl_allocate_foreign_data(VV[139], size+1);
	memcpy(output->foreign.data, lisp_string->base_string.self, size);
	output->foreign.data[size] = '\0';
	v3= output;
	}
    value0 = v3;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for ALLOCATE-FOREIGN-STRING               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L39allocate_foreign_string(cl_narg narg, cl_object v1size, ...)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2unsigned;
  ecl_va_list args; ecl_va_start(args,v1size,narg,1);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L39allocate_foreign_stringkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v2unsigned = keyvars[0];
  }
  if (Null(v2unsigned)) { goto L2; }
  T0 = ECL_SYM("UNSIGNED-CHAR",1387);
  goto L1;
L2:;
  T0 = ECL_SYM("CHAR",1364);
L1:;
  T1 = cl_list(2, ECL_SYM("*",18), T0);
  T2 = ecl_one_plus(v1size);
  value0 = si_allocate_foreign_data(T1, T2);
  return value0;
 }
}
/*	local function WITH-FOREIGN-STRING                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC40with_foreign_string(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6foreign_string;
   cl_object v7lisp_string;
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
    v6foreign_string = v8;
   }
   if (!(v5==ECL_NIL)) { goto L16; }
   si_dm_too_few_arguments(v1);
L16:;
   {
    cl_object v8;
    v8 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v7lisp_string = v8;
   }
   if (Null(v5)) { goto L21; }
   si_dm_too_many_arguments(v1);
L21:;
   {
    cl_object v8result;
    v8result = cl_gensym(0);
    T0 = cl_list(2, VV[44], v7lisp_string);
    T1 = cl_list(2, v6foreign_string, T0);
    T2 = CONS(ECL_SYM("PROGN",671),v3);
    T3 = cl_list(2, v8result, T2);
    T4 = cl_list(2, T1, T3);
    T5 = cl_list(2, VV[11], v6foreign_string);
    value0 = cl_list(4, ECL_SYM("LET*",478), T4, T5, v8result);
    return value0;
   }
  }
 }
}
/*	local function WITH-FOREIGN-STRINGS                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC41with_foreign_strings(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2;
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
   if (Null(v4bindings)) { goto L8; }
   T0 = ecl_car(v4bindings);
   T1 = ecl_cdr(v4bindings);
   T2 = cl_listX(3, ECL_SYM("WITH-FOREIGN-STRINGS",2024), T1, v3);
   value0 = cl_list(3, VV[46], T0, T2);
   return value0;
L8:;
   value0 = CONS(ECL_SYM("PROGN",671),v3);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function WITH-FOREIGN-OBJECT                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC42with_foreign_object(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5;
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
   cl_object v7type;
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
   if (!(v5==ECL_NIL)) { goto L16; }
   si_dm_too_few_arguments(v1);
L16:;
   {
    cl_object v8;
    v8 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v7type = v8;
   }
   if (Null(v5)) { goto L21; }
   si_dm_too_many_arguments(v1);
L21:;
   T0 = cl_list(2, VV[10], v7type);
   T1 = cl_list(2, v6var, T0);
   T2 = ecl_list1(T1);
   T3 = CONS(ECL_SYM("PROGN",671),v3);
   T4 = cl_list(2, VV[11], v6var);
   T5 = cl_list(3, ECL_SYM("UNWIND-PROTECT",888), T3, T4);
   value0 = cl_list(3, ECL_SYM("LET",477), T2, T5);
   return value0;
  }
 }
}
/*	local function WITH-FOREIGN-OBJECTS                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC43with_foreign_objects(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2;
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
   if (Null(v4bindings)) { goto L8; }
   T0 = ecl_car(v4bindings);
   T1 = ecl_cdr(v4bindings);
   T2 = cl_listX(3, ECL_SYM("WITH-FOREIGN-OBJECTS",2022), T1, v3);
   value0 = cl_list(3, VV[48], T0, T2);
   return value0;
L8:;
   value0 = CONS(ECL_SYM("PROGN",671),v3);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function WITH-CAST-POINTER                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC44with_cast_pointer(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4bind;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4bind = v5;
   }
   {
    cl_object v5binding_name;
    cl_object v6ptr;
    cl_object v7type;
    v5binding_name = ECL_NIL;
    v6ptr = ECL_NIL;
    v7type = ECL_NIL;
    {
     cl_fixnum v8;
     v8 = ecl_length(v4bind);
     if (!((v8)==(2))) { goto L13; }
     v5binding_name = ecl_car(v4bind);
     v6ptr = v5binding_name;
     v7type = ecl_cadr(v4bind);
     goto L11;
L13:;
     if (!((v8)==(3))) { goto L20; }
     v5binding_name = ecl_car(v4bind);
     v6ptr = ecl_cadr(v4bind);
     v7type = ecl_caddr(v4bind);
     goto L11;
L20:;
     cl_error(1, _ecl_static_18);
    }
L11:;
    T0 = cl_list(2, ECL_SYM("QUOTE",679), v7type);
    T1 = cl_list(2, VV[9], T0);
    T2 = cl_list(4, ECL_SYM("FOREIGN-DATA-RECAST",1350), v6ptr, T1, ECL_SYM("VOID",1381));
    T3 = cl_list(2, ECL_SYM("QUOTE",679), v7type);
    T4 = cl_list(2, VV[9], T3);
    T5 = cl_list(2, ECL_SYM("QUOTE",679), v7type);
    T6 = cl_list(5, ECL_SYM("FOREIGN-DATA-POINTER",1349), T2, ecl_make_fixnum(0), T4, T5);
    T7 = cl_list(2, v5binding_name, T6);
    T8 = ecl_list1(T7);
    value0 = cl_listX(3, ECL_SYM("LET",477), T8, v3);
    return value0;
   }
  }
 }
}
/*	function definition for LISP-TO-C-NAME                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L45lisp_to_c_name(cl_object v1name)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (ECL_STRINGP(v1name)) { goto L3; }
  if (!(ECL_SYMBOLP(v1name))) { goto L1; }
  goto L2;
L3:;
L2:;
  T0 = cl_string(v1name);
  T1 = cl_substitute(3, CODE_CHAR(45), CODE_CHAR(95), T0);
  T2 = cl_string_upcase(1, T1);
  T3 = cl_intern(1, T2);
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = T3;
  cl_env_copy->values[0] = v1name;
  return cl_env_copy->values[0];
L1:;
  if (!(ECL_CONSP(v1name))) { goto L5; }
  {
   cl_fixnum v2;
   v2 = ecl_length(v1name);
   if (!((v2)==(2))) { goto L5; }
  }
  T0 = ecl_car(v1name);
  T1 = ecl_cadr(v1name);
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = T1;
  cl_env_copy->values[0] = T0;
  return cl_env_copy->values[0];
L5:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for %CONVERT-TO-ARG-TYPE                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L46_convert_to_arg_type(cl_object v1type)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2type;
   v2type = L4_convert_to_ffi_type(1, v1type);
   if (!(ECL_ATOM(v2type))) { goto L2; }
   value0 = v2type;
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
   T0 = ecl_car(v2type);
   if (!((T0)==(ECL_SYM("*",18)))) { goto L4; }
   value0 = ECL_SYM("POINTER-VOID",1377);
   cl_env_copy->nvalues = 1;
   return value0;
L4:;
   T0 = ecl_car(v2type);
   if (!((T0)==(ECL_SYM("ARRAY",1199)))) { goto L6; }
   value0 = ECL_SYM("POINTER-VOID",1377);
   cl_env_copy->nvalues = 1;
   return value0;
L6:;
   value0 = cl_error(2, _ecl_static_19, v2type);
   return value0;
  }
 }
}
/*	function definition for %CONVERT-TO-RETURN-TYPE               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L47_convert_to_return_type(cl_object v1type)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2type;
   v2type = L4_convert_to_ffi_type(1, v1type);
   if (!(ECL_ATOM(v2type))) { goto L2; }
   value0 = v2type;
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
   T0 = ecl_car(v2type);
   if (!((T0)==(ECL_SYM("*",18)))) { goto L4; }
   value0 = ecl_cadr(v2type);
   cl_env_copy->nvalues = 1;
   return value0;
L4:;
   value0 = v2type;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for PRODUCE-FUNCTION-CALL                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L48produce_function_call(cl_object v1c_name, cl_object v2nargs)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_times(v2nargs,ecl_make_fixnum(3));
  T1 = ecl_one_minus(T0);
  T2 = (ecl_number_compare(ecl_make_fixnum(0),T1)>=0?ecl_make_fixnum(0):T1);
  T3 = cl_subseq(3, _ecl_static_21, ecl_make_fixnum(0), T2);
  value0 = cl_format(4, ECL_NIL, _ecl_static_20, v1c_name, T3);
  return value0;
 }
}
/*	local function DEF-LIB-FUNCTION                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC49def_lib_function(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4name;
   cl_object v5args;
   cl_object v6;
   cl_object v7returning;
   cl_object v8;
   cl_object v9module;
   cl_object v10;
   cl_object v11call;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v12;
    v12 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4name = v12;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v12;
    v12 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5args = v12;
   }
   v6 = si_search_keyword(2, v3, VV[54]);
   if (!((v6)==(ECL_SYM("MISSING-KEYWORD",1929)))) { goto L16; }
   v7returning = ECL_NIL;
   goto L15;
L16:;
   v7returning = v6;
L15:;
   v8 = si_search_keyword(2, v3, VV[55]);
   if (!((v8)==(ECL_SYM("MISSING-KEYWORD",1929)))) { goto L20; }
   v9module = ECL_NIL;
   goto L19;
L20:;
   v9module = v8;
L19:;
   v10 = si_search_keyword(2, v3, VV[56]);
   if (!((v10)==(ECL_SYM("MISSING-KEYWORD",1929)))) { goto L24; }
   v11call = ECL_SYM("CDECL",1593);
   goto L23;
L24:;
   v11call = v10;
L23:;
   si_check_keyword(2, v3, VV[57]);
   {
    cl_object v13;                                /*  C-NAME          */
    cl_object v14;                                /*  LISP-NAME       */
    value0 = L45lisp_to_c_name(v4name);
    v13 = value0;
    {
     const int v15 = cl_env_copy->nvalues;
     cl_object v16;
     v16 = (v15<=1)? ECL_NIL : cl_env_copy->values[1];
     v14 = v16;
    }
    {
     cl_object v15return_type;
     cl_object v16argtypes;
     v15return_type = L47_convert_to_return_type(v7returning);
     {
      cl_object v17;
      cl_object v18;
      v17 = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v5args))) FEtype_error_list(v5args);
      v18 = v5args;
      {
       cl_object v19;
       cl_object v20;
       v19 = ecl_list1(ECL_NIL);
       v20 = v19;
L35:;
       if (!(ecl_endp(v18))) { goto L37; }
       goto L36;
L37:;
       v17 = _ecl_car(v18);
       {
        cl_object v21;
        v21 = _ecl_cdr(v18);
        if (ecl_unlikely(!ECL_LISTP(v21))) FEtype_error_list(v21);
        v18 = v21;
       }
       if (ecl_unlikely(ECL_ATOM(v20))) FEtype_error_cons(v20);
       T0 = v20;
       T2 = ecl_cadr(v17);
       T1 = L46_convert_to_arg_type(T2);
       v20 = ecl_list1(T1);
       (ECL_CONS_CDR(T0)=v20,T0);
       goto L35;
L36:;
       v16argtypes = ecl_cdr(v19);
       goto L29;
      }
     }
L29:;
     T0 = cl_list(2, ECL_SYM("QUOTE",679), v13);
     T1 = cl_listX(4, ECL_SYM("FIND-FOREIGN-SYMBOL",1344), T0, v9module, VV[59]);
     T2 = cl_list(2, VV[58], T1);
     T3 = ecl_list1(T2);
     {
      cl_object v17;
      cl_object v18;
      v17 = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v5args))) FEtype_error_list(v5args);
      v18 = v5args;
      {
       cl_object v19;
       cl_object v20;
       v19 = ecl_list1(ECL_NIL);
       v20 = v19;
L58:;
       if (!(ecl_endp(v18))) { goto L60; }
       goto L59;
L60:;
       v17 = _ecl_car(v18);
       {
        cl_object v21;
        v21 = _ecl_cdr(v18);
        if (ecl_unlikely(!ECL_LISTP(v21))) FEtype_error_list(v21);
        v18 = v21;
       }
       if (ecl_unlikely(ECL_ATOM(v20))) FEtype_error_cons(v20);
       T5 = v20;
       T6 = ecl_car(v17);
       v20 = ecl_list1(T6);
       (ECL_CONS_CDR(T5)=v20,T5);
       goto L58;
L59:;
       T4 = ecl_cdr(v19);
       goto L52;
      }
     }
L52:;
     T5 = cl_list(2, ECL_SYM("QUOTE",679), v15return_type);
     T6 = cl_list(2, ECL_SYM("QUOTE",679), v16argtypes);
     {
      cl_object v17;
      cl_object v18;
      v17 = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v5args))) FEtype_error_list(v5args);
      v18 = v5args;
      {
       cl_object v19;
       cl_object v20;
       v19 = ecl_list1(ECL_NIL);
       v20 = v19;
L80:;
       if (!(ecl_endp(v18))) { goto L82; }
       goto L81;
L82:;
       v17 = _ecl_car(v18);
       {
        cl_object v21;
        v21 = _ecl_cdr(v18);
        if (ecl_unlikely(!ECL_LISTP(v21))) FEtype_error_list(v21);
        v18 = v21;
       }
       if (ecl_unlikely(ECL_ATOM(v20))) FEtype_error_cons(v20);
       T8 = v20;
       T9 = ecl_car(v17);
       v20 = ecl_list1(T9);
       (ECL_CONS_CDR(T8)=v20,T8);
       goto L80;
L81:;
       T7 = ecl_cdr(v19);
       goto L74;
      }
     }
L74:;
     T8 = CONS(ECL_SYM("LIST",481),T7);
     T9 = cl_list(6, ECL_SYM("CALL-CFUN",1589), VV[58], T5, T6, T8, v11call);
     T10 = cl_list(4, ECL_SYM("DEFUN",289), v14, T4, T9);
     value0 = cl_list(3, ECL_SYM("LET",477), T3, T10);
     return value0;
    }
   }
  }
 }
}
/*	local function DEF-FUNCTION                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC50def_function(cl_object v1, cl_object v2)
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
   cl_object v5args;
   cl_object v6;
   cl_object v7module;
   cl_object v8;
   cl_object v9returning;
   cl_object v10;
   cl_object v11call;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v12;
    v12 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4name = v12;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v12;
    v12 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5args = v12;
   }
   v6 = si_search_keyword(2, v3, VV[55]);
   if (!((v6)==(ECL_SYM("MISSING-KEYWORD",1929)))) { goto L16; }
   v7module = ECL_NIL;
   goto L15;
L16:;
   v7module = v6;
L15:;
   v8 = si_search_keyword(2, v3, VV[54]);
   if (!((v8)==(ECL_SYM("MISSING-KEYWORD",1929)))) { goto L20; }
   v9returning = ECL_SYM("VOID",1381);
   goto L19;
L20:;
   v9returning = v8;
L19:;
   v10 = si_search_keyword(2, v3, VV[56]);
   if (!((v10)==(ECL_SYM("MISSING-KEYWORD",1929)))) { goto L24; }
   v11call = ECL_SYM("CDECL",1593);
   goto L23;
L24:;
   v11call = v10;
L23:;
   si_check_keyword(2, v3, VV[61]);
   if (Null(v7module)) { goto L27; }
   if (Null(ecl_symbol_value(ECL_SYM("*USE-DFFI*",1969)))) { goto L27; }
   value0 = cl_list(9, VV[60], v4name, v5args, VV[54], v9returning, VV[55], v7module, VV[56], v11call);
   return value0;
L27:;
   {
    cl_object v13;                                /*  C-NAME          */
    cl_object v14;                                /*  LISP-NAME       */
    value0 = L45lisp_to_c_name(v4name);
    v13 = value0;
    {
     const int v15 = cl_env_copy->nvalues;
     cl_object v16;
     v16 = (v15<=1)? ECL_NIL : cl_env_copy->values[1];
     v14 = v16;
    }
    {
     cl_object v15arguments;
     cl_object v16arg_types;
     cl_object v17return_type;
     cl_fixnum v18nargs;
     cl_object v19c_string;
     cl_object v20casting_required;
     cl_object v21inline_form;
     {
      cl_object v22;
      cl_object v23;
      v22 = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v5args))) FEtype_error_list(v5args);
      v23 = v5args;
      {
       cl_object v24;
       cl_object v25;
       v24 = ecl_list1(ECL_NIL);
       v25 = v24;
L37:;
       if (!(ecl_endp(v23))) { goto L39; }
       goto L38;
L39:;
       v22 = _ecl_car(v23);
       {
        cl_object v26;
        v26 = _ecl_cdr(v23);
        if (ecl_unlikely(!ECL_LISTP(v26))) FEtype_error_list(v26);
        v23 = v26;
       }
       if (ecl_unlikely(ECL_ATOM(v25))) FEtype_error_cons(v25);
       T0 = v25;
       T1 = ecl_car(v22);
       v25 = ecl_list1(T1);
       (ECL_CONS_CDR(T0)=v25,T0);
       goto L37;
L38:;
       v15arguments = ecl_cdr(v24);
       goto L31;
      }
     }
L31:;
     {
      cl_object v22;
      cl_object v23;
      v22 = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v5args))) FEtype_error_list(v5args);
      v23 = v5args;
      {
       cl_object v24;
       cl_object v25;
       v24 = ecl_list1(ECL_NIL);
       v25 = v24;
L59:;
       if (!(ecl_endp(v23))) { goto L61; }
       goto L60;
L61:;
       v22 = _ecl_car(v23);
       {
        cl_object v26;
        v26 = _ecl_cdr(v23);
        if (ecl_unlikely(!ECL_LISTP(v26))) FEtype_error_list(v26);
        v23 = v26;
       }
       if (ecl_unlikely(ECL_ATOM(v25))) FEtype_error_cons(v25);
       T0 = v25;
       T2 = ecl_cadr(v22);
       T1 = L46_convert_to_arg_type(T2);
       v25 = ecl_list1(T1);
       (ECL_CONS_CDR(T0)=v25,T0);
       goto L59;
L60:;
       v16arg_types = ecl_cdr(v24);
       goto L53;
      }
     }
L53:;
     v17return_type = L47_convert_to_return_type(v9returning);
     v18nargs = ecl_length(v15arguments);
     v19c_string = L48produce_function_call(v13, ecl_make_fixnum(v18nargs));
     if (!(ecl_eql(v17return_type,ECL_SYM("VOID",1381)))) { goto L88; }
     value0 = VV[62];
     goto L86;
L88:;
     value0 = ECL_NIL;
     goto L86;
L86:;
     if ((value0)!=ECL_NIL) { goto L85; }
     if (!(ecl_eql(v17return_type,ECL_SYM("CSTRING",1365)))) { goto L91; }
     value0 = VV[63];
     goto L83;
L91:;
     value0 = ECL_NIL;
     goto L83;
L85:;
     goto L83;
L83:;
     if ((value0)!=ECL_NIL) { goto L82; }
     T0 = si_foreign_elt_type_p(v17return_type);
     goto L80;
L82:;
     T0 = value0;
     goto L80;
L80:;
     v20casting_required = Null(T0)?ECL_T:ECL_NIL;
     if (Null(v20casting_required)) { goto L95; }
     T0 = ECL_SYM("POINTER-VOID",1377);
     goto L94;
L95:;
     T0 = v17return_type;
L94:;
     v21inline_form = cl_listX(6, ECL_SYM("C-INLINE",1973), v15arguments, v16arg_types, T0, v19c_string, VV[64]);
     if (Null(v20casting_required)) { goto L97; }
     T0 = cl_list(2, ECL_SYM("QUOTE",679), v17return_type);
     T1 = cl_list(2, VV[9], T0);
     T2 = cl_list(2, ECL_SYM("QUOTE",679), v17return_type);
     v21inline_form = cl_list(4, ECL_SYM("FOREIGN-DATA-RECAST",1350), v21inline_form, T1, T2);
L97:;
     if (!((v18nargs)>(36))) { goto L100; }
     cl_error(1, _ecl_static_22);
L100:;
     value0 = cl_list(4, ECL_SYM("DEFUN",289), v14, v15arguments, v21inline_form);
     return value0;
    }
   }
  }
 }
}
/*	local function DEF-FOREIGN-VAR                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC51def_foreign_var(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4name;
   cl_object v5type;
   cl_object v6module;
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
    v5type = v7;
   }
   if (!(v3==ECL_NIL)) { goto L15; }
   si_dm_too_few_arguments(v1);
L15:;
   {
    cl_object v7;
    v7 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v6module = v7;
   }
   if (Null(v3)) { goto L20; }
   si_dm_too_many_arguments(v1);
L20:;
   {
    cl_object v8;                                 /*  C-NAME          */
    cl_object v9;                                 /*  LISP-NAME       */
    value0 = L45lisp_to_c_name(v4name);
    v8 = value0;
    {
     const int v10 = cl_env_copy->nvalues;
     cl_object v11;
     v11 = (v10<=1)? ECL_NIL : cl_env_copy->values[1];
     v9 = v11;
    }
    {
     cl_object v10ffi_type;
     cl_object v11can_deref;
     cl_object v12inline_form;
     v10ffi_type = L4_convert_to_ffi_type(1, v5type);
     value0 = si_foreign_elt_type_p(v10ffi_type);
     if ((value0)!=ECL_NIL) { goto L26; }
     if (!(ECL_CONSP(v10ffi_type))) { goto L29; }
     {
      cl_object v13;
      v13 = ecl_car(v10ffi_type);
      if (!((v13)==(ECL_SYM("*",18)))) { goto L36; }
      value0 = VV[66];
      goto L34;
L36:;
      value0 = ECL_NIL;
      goto L34;
L34:;
      if ((value0)!=ECL_NIL) { goto L33; }
      if (!(ecl_eql(v13,ECL_SYM("ARRAY",1199)))) { goto L39; }
      v11can_deref = VV[67];
      goto L24;
L39:;
      v11can_deref = ECL_NIL;
      goto L24;
L33:;
      v11can_deref = value0;
      goto L24;
     }
L29:;
     v11can_deref = ECL_NIL;
     goto L24;
L26:;
     v11can_deref = value0;
     goto L24;
L24:;
     if (Null(v6module)) { goto L42; }
     if (Null(ecl_symbol_value(ECL_SYM("*USE-DFFI*",1969)))) { goto L42; }
     T0 = cl_list(2, ECL_SYM("QUOTE",679), v5type);
     T1 = L6size_of_foreign_type(v5type);
     v12inline_form = cl_list(5, ECL_SYM("FIND-FOREIGN-SYMBOL",1344), v8, v6module, T0, T1);
     goto L41;
L42:;
     T0 = L6size_of_foreign_type(v5type);
     T1 = cl_format(5, ECL_NIL, _ecl_static_23, v5type, T0, v8);
     v12inline_form = cl_listX(6, ECL_SYM("C-INLINE",1973), ECL_NIL, ECL_NIL, ECL_SYM("OBJECT",1278), T1, VV[68]);
L41:;
     if (Null(v11can_deref)) { goto L45; }
     T0 = cl_list(2, ECL_SYM("QUOTE",679), v9);
     T1 = cl_list(4, ECL_SYM("PUT-SYSPROP",1124), T0, VV[69], v12inline_form);
     T2 = cl_list(2, ECL_SYM("QUOTE",679), v9);
     T3 = cl_list(3, ECL_SYM("GET-SYSPROP",1083), T2, VV[69]);
     T4 = cl_list(2, ECL_SYM("QUOTE",679), v5type);
     T5 = cl_list(3, VV[27], T3, T4);
     T6 = cl_list(3, ECL_SYM("DEFINE-SYMBOL-MACRO",282), v9, T5);
     T7 = cl_list(3, ECL_SYM("EVAL-WHEN",340), VV[1], T6);
     value0 = cl_list(3, ECL_SYM("PROGN",671), T1, T7);
     return value0;
L45:;
     value0 = cl_list(3, ECL_SYM("DEFPARAMETER",285), v9, v12inline_form);
     return value0;
    }
   }
  }
 }
}
/*	function definition for FIND-FOREIGN-LIBRARY                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L52find_foreign_library(cl_narg narg, cl_object v1names, cl_object v2directories, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3drive_letters;
  cl_object v4types;
  ecl_va_list args; ecl_va_start(args,v2directories,narg,2);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L52find_foreign_librarykeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3drive_letters = keyvars[0];
   v4types = keyvars[1];
  }
  if (ECL_LISTP(v1names)) { goto L1; }
  v1names = ecl_list1(v1names);
L1:;
  if (ECL_LISTP(v2directories)) { goto L4; }
  v2directories = ecl_list1(v2directories);
L4:;
  if ((v4types)!=ECL_NIL) { goto L7; }
  v4types = VV[71];
L7:;
  if (ECL_LISTP(v4types)) { goto L10; }
  v4types = ecl_list1(v4types);
L10:;
  if (ECL_LISTP(v3drive_letters)) { goto L13; }
  v3drive_letters = ecl_list1(v3drive_letters);
L13:;
  v3drive_letters = VV[72];
  {
   cl_object v5;
   v5 = v3drive_letters;
   goto L22;
L21:;
   {
    cl_object v6d;
    v6d = ecl_car(v5);
    {
     cl_object v7;
     v7 = v2directories;
     goto L30;
L29:;
     {
      cl_object v8p;
      v8p = ecl_car(v7);
      {
       cl_object v9;
       v9 = v1names;
       goto L38;
L37:;
       {
        cl_object v10n;
        v10n = ecl_car(v9);
        {
         cl_object v11;
         v11 = v4types;
         goto L46;
L45:;
         {
          cl_object v12e;
          v12e = ecl_car(v11);
          {
          cl_object v13full_path;
          if (Null(cl_pathnamep(v8p))) { goto L53; }
          T0 = cl_pathname_directory(1, v8p);
          goto L52;
L53:;
          if (!(ECL_STRINGP(v8p))) { goto L55; }
          T1 = cl_parse_namestring(1, v8p);
          T0 = cl_pathname_directory(1, T1);
          goto L52;
L55:;
          if (!(ECL_LISTP(v8p))) { goto L57; }
          T0 = v8p;
          goto L52;
L57:;
          T0 = si_etypecase_error(v8p, VV[73]);
L52:;
          T1 = cl_make_pathname(8, ECL_SYM("DEVICE",1217), v6d, ECL_SYM("DIRECTORY",1219), T0, ECL_SYM("NAME",1273), v10n, ECL_SYM("TYPE",1318), v12e);
          v13full_path = cl_probe_file(T1);
          if (Null(v13full_path)) { goto L50; }
          value0 = v13full_path;
          cl_env_copy->nvalues = 1;
          return value0;
          }
L50:;
         }
         v11 = ecl_cdr(v11);
L46:;
         if (Null(v11)) { goto L62; }
         goto L45;
L62:;
        }
       }
       v9 = ecl_cdr(v9);
L38:;
       if (Null(v9)) { goto L66; }
       goto L37;
L66:;
      }
     }
     v7 = ecl_cdr(v7);
L30:;
     if (Null(v7)) { goto L70; }
     goto L29;
L70:;
    }
   }
   v5 = ecl_cdr(v5);
L22:;
   if (Null(v5)) { goto L74; }
   goto L21;
L74:;
  }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for DO-LOAD-FOREIGN-LIBRARY               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L53do_load_foreign_library(cl_narg narg, cl_object v1tmp, ...)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2system_library;
  va_list args; va_start(args,v1tmp);
  {
   int i = 1;
   if (i >= narg) {
    v2system_library = ECL_NIL;
   } else {
    i++;
    v2system_library = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v3path;
   cl_object v4filename;
   cl_object v5pack;
   cl_object v6flag;
   if (Null(cl_pathnamep(v1tmp))) { goto L3; }
   v3path = v1tmp;
   goto L2;
L3:;
   v1tmp = cl_string(v1tmp);
   if (Null(cl_probe_file(v1tmp))) { goto L5; }
   v3path = v1tmp;
   goto L2;
L5:;
   v3path = (cl_env_copy->function=(ECL_SYM("COMPILE-FILE-PATHNAME",235)->symbol.gfdef))->cfun.entry(3, v1tmp, ECL_SYM("TYPE",1318), VV[76]) /*  COMPILE-FILE-PATHNAME */;
L2:;
   v4filename = cl_namestring(v3path);
   v5pack = cl_find_package(_ecl_static_24);
   if (Null(v2system_library)) { goto L11; }
   v6flag = cl_concatenate(3, ECL_SYM("STRING",805), _ecl_static_25, v1tmp);
   goto L10;
L11:;
   v6flag = v4filename;
L10:;
   {
    cl_object v7;
    cl_object v8;
    v7 = ecl_symbol_value(VV[75]);
    v8 = si_make_seq_iterator(2, v7, ecl_make_fixnum(0));
L17:;
    if ((v8)!=ECL_NIL) { goto L19; }
    goto L14;
L19:;
    {
     cl_object v9;
     v9 = si_seq_iterator_ref(v7, v8);
     if (Null(cl_string_equal(2, v4filename, v9))) { goto L21; }
     if ((v9)!=ECL_NIL) { goto L13; }
     goto L14;
    }
L21:;
    v8 = si_seq_iterator_next(v7, v8);
    goto L17;
   }
L14:;
   T0 = cl_intern(2, _ecl_static_26, v5pack);
   T1 = cl_intern(2, _ecl_static_26, v5pack);
   T2 = cl_symbol_value(T1);
   T3 = cl_concatenate(4, ECL_SYM("STRING",805), T2, _ecl_static_27, v6flag);
   cl_set(T0, T3);
   T0 = cl_intern(2, _ecl_static_28, v5pack);
   T1 = cl_intern(2, _ecl_static_28, v5pack);
   T2 = cl_symbol_value(T1);
   T3 = cl_concatenate(4, ECL_SYM("STRING",805), T2, _ecl_static_27, v6flag);
   cl_set(T0, T3);
   T0 = cl_intern(2, _ecl_static_29, v5pack);
   T1 = cl_intern(2, _ecl_static_29, v5pack);
   T2 = cl_symbol_value(T1);
   T3 = cl_concatenate(4, ECL_SYM("STRING",805), T2, _ecl_static_27, v6flag);
   cl_set(T0, T3);
   cl_set(VV[75],CONS(v4filename,ecl_symbol_value(VV[75])));
L13:;
   value0 = ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function LOAD-FOREIGN-LIBRARY                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC54load_foreign_library(cl_object v1, cl_object v2)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4filename;
   cl_object v5;
   cl_object v6;
   cl_object v7;
   cl_object v8;
   cl_object v9system_library;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v10;
    v10 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4filename = v10;
   }
   v5 = si_search_keyword(2, v3, VV[55]);
   v6 = si_search_keyword(2, v3, VV[78]);
   v7 = si_search_keyword(2, v3, VV[79]);
   v8 = si_search_keyword(2, v3, VV[80]);
   if (!((v8)==(ECL_SYM("MISSING-KEYWORD",1929)))) { goto L13; }
   v9system_library = ECL_NIL;
   goto L12;
L13:;
   v9system_library = v8;
L12:;
   si_check_keyword(2, v3, VV[81]);
   {
    cl_object v10;
    cl_object v11;
    if (Null(cl_constantp(1, v4filename))) { goto L18; }
    T0 = cl_list(3, VV[77], v4filename, v9system_library);
    T1 = cl_list(3, ECL_SYM("EVAL-WHEN",340), VV[82], T0);
    v10 = ecl_list1(T1);
    goto L16;
L18:;
    v10 = ECL_NIL;
    goto L16;
L16:;
    if ((v9system_library)!=ECL_NIL) { goto L21; }
    if (Null(ecl_symbol_value(ECL_SYM("*USE-DFFI*",1969)))) { goto L21; }
    T0 = cl_list(2, ECL_SYM("LOAD-FOREIGN-MODULE",1359), v4filename);
    v11 = ecl_list1(T0);
    goto L20;
L21:;
    v11 = ECL_NIL;
L20:;
    T0 = ecl_append(v10,v11);
    value0 = CONS(ECL_SYM("PROGN",671),T0);
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	local function DEFCALLBACK                                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC55defcallback(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4name;
   cl_object v5ret_type;
   cl_object v6arg_desc;
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
    v5ret_type = v7;
   }
   if (!(v3==ECL_NIL)) { goto L15; }
   si_dm_too_few_arguments(v1);
L15:;
   {
    cl_object v7;
    v7 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v6arg_desc = v7;
   }
   if (Null(ecl_symbol_value(ECL_SYM("*USE-DFFI*",1969)))) { goto L20; }
   {
    cl_object v8;                                 /*  NAME            */
    cl_object v9;                                 /*  CALL-TYPE       */
    if (!(ECL_CONSP(v4name))) { goto L23; }
    value0 = cl_values_list(v4name);
    goto L22;
L23:;
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = ECL_SYM("CDECL",1593);
    cl_env_copy->values[0] = v4name;
    value0 = cl_env_copy->values[0];
L22:;
    v8 = value0;
    {
     const int v10 = cl_env_copy->nvalues;
     cl_object v11;
     v11 = (v10<=1)? ECL_NIL : cl_env_copy->values[1];
     v9 = v11;
    }
    {
     cl_object v10;
     cl_object v11;
     {
      cl_object v12;
      cl_object v13;
      v12 = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v6arg_desc))) FEtype_error_list(v6arg_desc);
      v13 = v6arg_desc;
      {
       cl_object v14;
       cl_object v15;
       v14 = ecl_list1(ECL_NIL);
       v15 = v14;
L31:;
       if (!(ecl_endp(v13))) { goto L33; }
       goto L32;
L33:;
       v12 = _ecl_car(v13);
       {
        cl_object v16;
        v16 = _ecl_cdr(v13);
        if (ecl_unlikely(!ECL_LISTP(v16))) FEtype_error_list(v16);
        v13 = v16;
       }
       if (ecl_unlikely(ECL_ATOM(v15))) FEtype_error_cons(v15);
       T0 = v15;
       T1 = ecl_cadr(v12);
       v15 = ecl_list1(T1);
       (ECL_CONS_CDR(T0)=v15,T0);
       goto L31;
L32:;
       v10 = ecl_cdr(v14);
       goto L25;
      }
     }
L25:;
     {
      cl_object v12;
      cl_object v13;
      v12 = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v6arg_desc))) FEtype_error_list(v6arg_desc);
      v13 = v6arg_desc;
      {
       cl_object v14;
       cl_object v15;
       v14 = ecl_list1(ECL_NIL);
       v15 = v14;
L53:;
       if (!(ecl_endp(v13))) { goto L55; }
       goto L54;
L55:;
       v12 = _ecl_car(v13);
       {
        cl_object v16;
        v16 = _ecl_cdr(v13);
        if (ecl_unlikely(!ECL_LISTP(v16))) FEtype_error_list(v16);
        v13 = v16;
       }
       if (ecl_unlikely(ECL_ATOM(v15))) FEtype_error_cons(v15);
       T0 = v15;
       T1 = ecl_car(v12);
       v15 = ecl_list1(T1);
       (ECL_CONS_CDR(T0)=v15,T0);
       goto L53;
L54:;
       v11 = ecl_cdr(v14);
       goto L47;
      }
     }
L47:;
     T0 = cl_listX(4, ECL_SYM("LAMBDA-BLOCK",1339), v8, v11, v3);
     T1 = cl_list(2, ECL_SYM("FUNCTION",396), T0);
     T2 = cl_list(2, ECL_SYM("QUOTE",679), v8);
     T3 = cl_list(2, ECL_SYM("QUOTE",679), v5ret_type);
     T4 = cl_list(2, ECL_SYM("QUOTE",679), v10);
     value0 = cl_list(6, ECL_SYM("MAKE-DYNAMIC-CALLBACK",1591), T1, T2, T3, T4, v9);
     return value0;
    }
   }
L20:;
   value0 = cl_error(1, _ecl_static_30);
   return value0;
  }
 }
}
/*	function definition for CALLBACK                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L56callback(cl_object v1name)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2x;
   v2x = si_get_sysprop(v1name, ECL_SYM("CALLBACK",1590));
   if ((v2x)!=ECL_NIL) { goto L2; }
   cl_error(2, _ecl_static_31, v1name);
L2:;
   value0 = ecl_car(v2x);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for CLINES                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L57clines(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1args;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1args = cl_grab_rest_args(args);
  ecl_va_end(args);
  value0 = cl_error(2, _ecl_static_32, v1args);
  return value0;
 }
}
/*	local function C-INLINE                                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC58c_inline(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4args;
   cl_object v5arg_types;
   cl_object v6ret_type;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v7;
    v7 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4args = v7;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v7;
    v7 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5arg_types = v7;
   }
   if (!(v3==ECL_NIL)) { goto L15; }
   si_dm_too_few_arguments(v1);
L15:;
   {
    cl_object v7;
    v7 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v6ret_type = v7;
   }
   T0 = CONS(ECL_SYM("LIST",481),v4args);
   T1 = cl_list(2, ECL_SYM("QUOTE",679), v5arg_types);
   T2 = cl_list(2, ECL_SYM("QUOTE",679), v6ret_type);
   T3 = cl_listX(5, ECL_SYM("LIST",481), T0, T1, T2, v3);
   value0 = cl_list(3, ECL_SYM("ERROR",337), _ecl_static_33, T3);
   return value0;
  }
 }
}
/*	local function DEFINLINE                                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC59definline(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4fun;
   cl_object v5arg_types;
   cl_object v6type;
   cl_object v7code;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v8;
    v8 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4fun = v8;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v8;
    v8 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5arg_types = v8;
   }
   if (!(v3==ECL_NIL)) { goto L15; }
   si_dm_too_few_arguments(v1);
L15:;
   {
    cl_object v8;
    v8 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v6type = v8;
   }
   if (!(v3==ECL_NIL)) { goto L21; }
   si_dm_too_few_arguments(v1);
L21:;
   {
    cl_object v8;
    v8 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v7code = v8;
   }
   if (Null(v3)) { goto L26; }
   si_dm_too_many_arguments(v1);
L26:;
   T0 = cl_list(5, ECL_SYM("DEFCBODY",1993), v4fun, v5arg_types, v6type, v7code);
   T1 = cl_list(3, ECL_SYM("FUNCTION",396), v5arg_types, v6type);
   T2 = cl_list(3, ECL_SYM("FTYPE",393), T1, v4fun);
   T3 = cl_list(2, ECL_SYM("DECLAIM",272), T2);
   T4 = cl_list(6, VV[88], v4fun, VV[89], v5arg_types, v6type, v7code);
   value0 = cl_list(5, ECL_SYM("EVAL-WHEN",340), VV[1], T0, T3, T4);
   return value0;
  }
 }
}
/*	local function DEFLA                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC60defla(cl_object v1, cl_object v2)
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
   T0 = CONS(ECL_SYM("DEFUN",289),v3);
   value0 = cl_list(3, ECL_SYM("EVAL-WHEN",340), VV[91], T0);
   return value0;
  }
 }
}
/*	local function DEFCBODY                                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC61defcbody(cl_object v1, cl_object v2)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4name;
   cl_object v5arg_types;
   cl_object v6result_type;
   cl_object v7c_expr;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v8;
    v8 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4name = v8;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v8;
    v8 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5arg_types = v8;
   }
   if (!(v3==ECL_NIL)) { goto L15; }
   si_dm_too_few_arguments(v1);
L15:;
   {
    cl_object v8;
    v8 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v6result_type = v8;
   }
   if (!(v3==ECL_NIL)) { goto L21; }
   si_dm_too_few_arguments(v1);
L21:;
   {
    cl_object v8;
    v8 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v7c_expr = v8;
   }
   if (Null(v3)) { goto L26; }
   si_dm_too_many_arguments(v1);
L26:;
   {
    cl_object v8args;
    {
     cl_object v9;
     cl_object v10;
     v9 = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v5arg_types))) FEtype_error_list(v5arg_types);
     v10 = v5arg_types;
     {
      cl_object v11;
      cl_object v12;
      v11 = ecl_list1(ECL_NIL);
      v12 = v11;
L35:;
      if (!(ecl_endp(v10))) { goto L37; }
      goto L36;
L37:;
      v9 = _ecl_car(v10);
      {
       cl_object v13;
       v13 = _ecl_cdr(v10);
       if (ecl_unlikely(!ECL_LISTP(v13))) FEtype_error_list(v13);
       v10 = v13;
      }
      if (ecl_unlikely(ECL_ATOM(v12))) FEtype_error_cons(v12);
      T0 = v12;
      T1 = cl_gensym(0);
      v12 = ecl_list1(T1);
      (ECL_CONS_CDR(T0)=v12,T0);
      goto L35;
L36:;
      v8args = ecl_cdr(v11);
      goto L29;
     }
    }
L29:;
    T0 = cl_listX(6, VV[87], v8args, v5arg_types, v6result_type, v7c_expr, VV[93]);
    value0 = cl_list(4, ECL_SYM("DEFUN",289), v4name, v8args, T0);
    return value0;
   }
  }
 }
}
/*	local function DEFENTRY                                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC62defentry(cl_object v1, cl_object v2)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4name;
   cl_object v5arg_types;
   cl_object v6c_name;
   cl_object v7;
   cl_object v8no_interrupts;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v9;
    v9 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4name = v9;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v9;
    v9 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5arg_types = v9;
   }
   if (!(v3==ECL_NIL)) { goto L15; }
   si_dm_too_few_arguments(v1);
L15:;
   {
    cl_object v9;
    v9 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v6c_name = v9;
   }
   v7 = si_search_keyword(2, v3, VV[95]);
   if (!((v7)==(ECL_SYM("MISSING-KEYWORD",1929)))) { goto L22; }
   v8no_interrupts = ECL_NIL;
   goto L21;
L22:;
   v8no_interrupts = v7;
L21:;
   si_check_keyword(2, v3, VV[96]);
   {
    cl_object v9;
    cl_object v10output_type;
    {
     cl_object v11;
     cl_object v12;
     v11 = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v5arg_types))) FEtype_error_list(v5arg_types);
     v12 = v5arg_types;
     {
      cl_object v13;
      cl_object v14;
      v13 = ecl_list1(ECL_NIL);
      v14 = v13;
L31:;
      if (!(ecl_endp(v12))) { goto L33; }
      goto L32;
L33:;
      v11 = _ecl_car(v12);
      {
       cl_object v15;
       v15 = _ecl_cdr(v12);
       if (ecl_unlikely(!ECL_LISTP(v15))) FEtype_error_list(v15);
       v12 = v15;
      }
      if (ecl_unlikely(ECL_ATOM(v14))) FEtype_error_cons(v14);
      T0 = v14;
      T1 = cl_gensym(0);
      v14 = ecl_list1(T1);
      (ECL_CONS_CDR(T0)=v14,T0);
      goto L31;
L32:;
      v9 = ecl_cdr(v13);
      goto L25;
     }
    }
L25:;
    v10output_type = ECL_SYM("OBJECT",1278);
    if (!(ECL_CONSP(v6c_name))) { goto L49; }
    v10output_type = ecl_car(v6c_name);
    v6c_name = ecl_cadr(v6c_name);
L49:;
    {
     cl_object v11call;
     cl_object v12full_text;
     T0 = cl_string(v6c_name);
     {
      cl_fixnum v13;
      v13 = ecl_length(v5arg_types);
      v11call = L48produce_function_call(T0, ecl_make_fixnum(v13));
     }
     if (Null(v8no_interrupts)) { goto L56; }
     v12full_text = cl_concatenate(4, ECL_SYM("STRING",805), _ecl_static_36, v11call, _ecl_static_37);
     goto L55;
L56:;
     v12full_text = v11call;
L55:;
     T0 = Null(v8no_interrupts)?ECL_T:ECL_NIL;
     T1 = cl_list(7, VV[87], v9, v5arg_types, v10output_type, v12full_text, VV[97], T0);
     value0 = cl_list(4, ECL_SYM("DEFUN",289), v4name, v9, T1);
     return value0;
    }
   }
  }
 }
}

#include "lsp/ffi.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecl5MX3foVtPdEo9_3zO5hE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:LSP;FFI.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_ecl5MX3foVtPdEo9_3zO5hE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 cl_import(1, ECL_SYM("NULL-POINTER-P",1360));
 cl_export(1, ECL_SYM("NULL-POINTER-P",1360));
 ecl_cmp_defmacro(VV[99]);                        /*  DEF-CONSTANT    */
 si_Xmake_special(VV[3]);
 cl_set(VV[3],cl_make_hash_table(2, ECL_SYM("SIZE",1308), ecl_make_fixnum(128)));
 si_Xmake_special(ECL_SYM("*USE-DFFI*",1969));
 cl_set(ECL_SYM("*USE-DFFI*",1969),ECL_T);
 ecl_cmp_defmacro(VV[100]);                       /*  DEF-FOREIGN-TYPE */
 ecl_cmp_defmacro(VV[101]);                       /*  DEF-TYPE        */
 ecl_cmp_defun(VV[102]);                          /*  %CONVERT-TO-FFI-TYPE */
 ecl_cmp_defmacro(VV[103]);                       /*  %ALIGN-DATA     */
 ecl_cmp_defun(VV[104]);                          /*  SIZE-OF-FOREIGN-TYPE */
 ecl_cmp_defun(VV[105]);                          /*  ALLOCATE-FOREIGN-OBJECT */
 ecl_cmp_defun(VV[106]);                          /*  FREE-FOREIGN-OBJECT */
 ecl_cmp_defmacro(VV[107]);                       /*  DEF-ENUM        */
 ecl_cmp_defmacro(VV[108]);                       /*  DEF-STRUCT      */
 ecl_cmp_defun(VV[109]);                          /*  SLOT-POSITION   */
 ecl_cmp_defun(VV[110]);                          /*  GET-SLOT-VALUE  */
 ecl_cmp_defun(VV[111]);                          /*  (SETF GET-SLOT-VALUE) */
 ecl_cmp_defun(VV[112]);                          /*  GET-SLOT-POINTER */
 ecl_cmp_defmacro(VV[113]);                       /*  DEF-ARRAY-POINTER */
 ecl_cmp_defun(VV[114]);                          /*  DEREF-ARRAY     */
 ecl_cmp_defun(VV[115]);                          /*  (SETF DEREF-ARRAY) */
 ecl_cmp_defun(VV[116]);                          /*  %FOREIGN-DATA-SET */
 ecl_cmp_defun(VV[117]);                          /*  %FOREIGN-DATA-REF */
 ecl_cmp_defmacro(VV[118]);                       /*  DEF-UNION       */
 si_Xmake_special(ECL_SYM("+NULL-CSTRING-POINTER+",1970));
 cl_set(ECL_SYM("+NULL-CSTRING-POINTER+",1970),si_allocate_foreign_data(ECL_SYM("POINTER-VOID",1377), ecl_make_fixnum(0)));
 ecl_cmp_defun(VV[119]);                          /*  POINTER-ADDRESS */
 ecl_cmp_defun(VV[120]);                          /*  DEREF-POINTER   */
 ecl_cmp_defun(VV[121]);                          /*  (SETF DEREF-POINTER) */
 ecl_cmp_defun(VV[122]);                          /*  MAKE-NULL-POINTER */
 ecl_cmp_defun(VV[123]);                          /*  MAKE-POINTER    */
 ecl_cmp_defun(VV[124]);                          /*  NULL-CHAR-P     */
 ecl_cmp_defun(VV[125]);                          /*  ENSURE-CHAR-CHARACTER */
 ecl_cmp_defun(VV[126]);                          /*  ENSURE-CHAR-INTEGER */
 ecl_cmp_defun(VV[127]);                          /*  ENSURE-CHAR-STORABLE */
 ecl_cmp_defun(VV[128]);                          /*  CHAR-ARRAY-TO-POINTER */
 ecl_cmp_defmacro(VV[129]);                       /*  CONVERT-FROM-CSTRING */
 ecl_cmp_defmacro(VV[130]);                       /*  CONVERT-TO-CSTRING */
 ecl_cmp_defmacro(VV[131]);                       /*  FREE-CSTRING    */
 ecl_cmp_defmacro(VV[132]);                       /*  WITH-CSTRING    */
 ecl_cmp_defmacro(VV[133]);                       /*  WITH-CSTRINGS   */
 ecl_cmp_defun(VV[134]);                          /*  FOREIGN-STRING-LENGTH */
 ecl_cmp_defun(VV[135]);                          /*  CONVERT-FROM-FOREIGN-STRING */
 ecl_cmp_defun(VV[138]);                          /*  CONVERT-TO-FOREIGN-STRING */
 ecl_cmp_defun(VV[140]);                          /*  ALLOCATE-FOREIGN-STRING */
 ecl_cmp_defmacro(VV[142]);                       /*  WITH-FOREIGN-STRING */
 ecl_cmp_defmacro(VV[143]);                       /*  WITH-FOREIGN-STRINGS */
 ecl_cmp_defmacro(VV[144]);                       /*  WITH-FOREIGN-OBJECT */
 ecl_cmp_defmacro(VV[145]);                       /*  WITH-FOREIGN-OBJECTS */
 ecl_cmp_defmacro(VV[146]);                       /*  WITH-CAST-POINTER */
 ecl_cmp_defun(VV[147]);                          /*  LISP-TO-C-NAME  */
 ecl_cmp_defun(VV[148]);                          /*  %CONVERT-TO-ARG-TYPE */
 ecl_cmp_defun(VV[149]);                          /*  %CONVERT-TO-RETURN-TYPE */
 (void)0; /* No entry created for PRODUCE-FUNCTION-CALL */
 ecl_cmp_defmacro(VV[150]);                       /*  DEF-LIB-FUNCTION */
 ecl_cmp_defmacro(VV[151]);                       /*  DEF-FUNCTION    */
 ecl_cmp_defmacro(VV[152]);                       /*  DEF-FOREIGN-VAR */
 ecl_cmp_defun(VV[153]);                          /*  FIND-FOREIGN-LIBRARY */
 si_Xmake_special(VV[75]);
 cl_set(VV[75],ECL_NIL);
 ecl_cmp_defun(VV[156]);                          /*  DO-LOAD-FOREIGN-LIBRARY */
 ecl_cmp_defmacro(VV[157]);                       /*  LOAD-FOREIGN-LIBRARY */
 ecl_cmp_defmacro(VV[158]);                       /*  DEFCALLBACK     */
 ecl_cmp_defun(VV[159]);                          /*  CALLBACK        */
 ecl_cmp_defun(VV[160]);                          /*  CLINES          */
 ecl_cmp_defmacro(VV[161]);                       /*  C-INLINE        */
 ecl_cmp_defmacro(VV[162]);                       /*  DEFINLINE       */
 ecl_cmp_defmacro(VV[163]);                       /*  DEFLA           */
 ecl_cmp_defmacro(VV[164]);                       /*  DEFCBODY        */
 ecl_cmp_defmacro(VV[165]);                       /*  DEFENTRY        */
}
