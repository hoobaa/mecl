/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:LSP;HELPFILE.LSP                                  */
#include <ecl/ecl-cmp.h>
#include "lsp/helpfile.eclh"
/*	function definition for NEW-DOCUMENTATION-POOL                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1new_documentation_pool(cl_narg narg, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1size;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1size = ecl_make_fixnum(1024);
   } else {
    i++;
    v1size = va_arg(args,cl_object);
   }
  }
  va_end(args);
  T0 = (ECL_SYM("EQL",334)->symbol.gfdef);
  T1 = cl_make_hash_table(4, ECL_SYM("TEST",1316), T0, ECL_SYM("SIZE",1308), v1size);
  cl_set(ECL_SYM("*DOCUMENTATION-POOL*",1756),CONS(T1,ecl_symbol_value(ECL_SYM("*DOCUMENTATION-POOL*",1756))));
  value0 = ecl_symbol_value(ECL_SYM("*DOCUMENTATION-POOL*",1756));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for RECORD-CONS                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2record_cons(cl_object v1record, cl_object v2key, cl_object v3sub_key)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4cons;
   v4cons = CONS(v2key,v3sub_key);
   {
    cl_object v5;
    v5 = v1record;
    goto L5;
L4:;
    {
     cl_object v6i;
     v6i = ecl_car(v5);
     T0 = ecl_car(v6i);
     if (!(ecl_equalp(T0,v4cons))) { goto L9; }
     value0 = v6i;
     cl_env_copy->nvalues = 1;
     return value0;
L9:;
    }
    v5 = ecl_cdr(v5);
L5:;
    if (Null(v5)) { goto L13; }
    goto L4;
L13:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for RECORD-FIELD                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3record_field(cl_object v1record, cl_object v2key, cl_object v3sub_key)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = L2record_cons(v1record, v2key, v3sub_key);
  value0 = ecl_cdr(T0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for SET-RECORD-FIELD                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4set_record_field(cl_object v1record, cl_object v2key, cl_object v3sub_key, cl_object v4value)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v5field;
   v5field = L2record_cons(v1record, v2key, v3sub_key);
   if (Null(v5field)) { goto L3; }
   if (ecl_unlikely(ECL_ATOM(v5field))) FEtype_error_cons(v5field);
   T0 = v5field;
   (ECL_CONS_CDR(T0)=v4value,T0);
   goto L2;
L3:;
   T0 = CONS(v2key,v3sub_key);
   T1 = CONS(T0,v4value);
   v1record = CONS(T1,v1record);
L2:;
   value0 = v1record;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for REM-RECORD-FIELD                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5rem_record_field(cl_object v1record, cl_object v2key, cl_object v3sub_key)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4x;
   v4x = L2record_cons(v1record, v2key, v3sub_key);
   if (Null(v4x)) { goto L2; }
   {
    cl_object v5output;
    v5output = ECL_NIL;
    {
     cl_object v6;
     v6 = v1record;
     goto L8;
L7:;
     {
      cl_object v7i;
      v7i = ecl_car(v6);
      if ((v7i)==(v4x)) { goto L12; }
      v5output = CONS(v7i,v5output);
L12:;
     }
     v6 = ecl_cdr(v6);
L8:;
     if (Null(v6)) { goto L17; }
     goto L7;
L17:;
     value0 = v5output;
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
L2:;
   value0 = v1record;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for ANNOTATE                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6annotate(cl_object v1object, cl_object v2key, cl_object v3sub_key, cl_object v4value)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v5dict;
   v5dict = ecl_car(ecl_symbol_value(ECL_SYM("*DOCUMENTATION-POOL*",1756)));
   if (Null(cl_hash_table_p(v5dict))) { goto L2; }
   {
    cl_object v6record;
    T0 = ecl_gethash_safe(v1object,v5dict,ECL_NIL);
    v6record = L4set_record_field(T0, v2key, v3sub_key, v4value);
    value0 = si_hash_set(v1object, v5dict, v6record);
    return value0;
   }
L2:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for REMOVE-ANNOTATION                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7remove_annotation(cl_object v1object, cl_object v2key, cl_object v3sub_key)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4dict;
   v4dict = ecl_car(ecl_symbol_value(ECL_SYM("*DOCUMENTATION-POOL*",1756)));
   if (Null(cl_hash_table_p(v4dict))) { goto L2; }
   {
    cl_object v5record;
    T0 = ecl_gethash_safe(v1object,v4dict,ECL_NIL);
    v5record = L5rem_record_field(T0, v2key, v3sub_key);
    if (Null(v5record)) { goto L5; }
    value0 = si_hash_set(v1object, v4dict, v5record);
    return value0;
L5:;
    value0 = cl_remhash(v1object, v4dict);
    return value0;
   }
L2:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for GET-ANNOTATION                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8get_annotation(cl_narg narg, cl_object v1object, cl_object v2key, ...)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v3sub_key;
  va_list args; va_start(args,v2key);
  {
   int i = 2;
   if (i >= narg) {
    v3sub_key = VV[8];
   } else {
    i++;
    v3sub_key = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v4output;
   v4output = ECL_NIL;
   {
    cl_object v5;
    v5 = ecl_symbol_value(ECL_SYM("*DOCUMENTATION-POOL*",1756));
    goto L6;
L5:;
    {
     cl_object v6dict;
     v6dict = ecl_car(v5);
     {
      cl_object v7record;
      if (Null(cl_hash_table_p(v6dict))) { goto L12; }
      v7record = ecl_gethash_safe(v1object,v6dict,ECL_NIL);
      goto L11;
L12:;
      if (!(ECL_STRINGP(v6dict))) { goto L14; }
      v7record = ecl_function_dispatch(cl_env_copy,VV[30])(2, v1object, v6dict) /*  SEARCH-HELP-FILE */;
      goto L11;
L14:;
      v7record = ECL_NIL;
L11:;
      if (Null(v7record)) { goto L10; }
      if (!((v3sub_key)==(VV[8]))) { goto L17; }
      {
       cl_object v8;
       v8 = v7record;
       goto L22;
L21:;
       {
        cl_object v9i;
        v9i = ecl_car(v8);
        {
         cl_object v10key_sub_key;
         v10key_sub_key = ecl_car(v9i);
         T0 = ecl_car(v10key_sub_key);
         if (!(ecl_equal(T0,v2key))) { goto L26; }
         T0 = ecl_cdr(v10key_sub_key);
         T1 = ecl_cdr(v9i);
         T2 = CONS(T0,T1);
         v4output = CONS(T2,v4output);
        }
L26:;
       }
       v8 = ecl_cdr(v8);
L22:;
       if (Null(v8)) { goto L32; }
       goto L21;
L32:;
       goto L10;
      }
L17:;
      v4output = L3record_field(v7record, v2key, v3sub_key);
      if (Null(v4output)) { goto L10; }
      value0 = v4output;
      cl_env_copy->nvalues = 1;
      return value0;
     }
L10:;
    }
    v5 = ecl_cdr(v5);
L6:;
    if (Null(v5)) { goto L38; }
    goto L5;
L38:;
    value0 = v4output;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for DUMP-DOCUMENTATION                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L9dump_documentation(cl_narg narg, cl_object v1file, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2merge;
  va_list args; va_start(args,v1file);
  {
   int i = 1;
   if (i >= narg) {
    v2merge = ECL_NIL;
   } else {
    i++;
    v2merge = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v3dict;
   v3dict = ecl_car(ecl_symbol_value(ECL_SYM("*DOCUMENTATION-POOL*",1756)));
   if (Null(cl_hash_table_p(v3dict))) { goto L3; }
   ecl_function_dispatch(cl_env_copy,VV[32])(3, v3dict, v1file, v2merge) /*  DUMP-HELP-FILE */;
   {
    cl_object v4;
    v4 = ecl_symbol_value(ECL_SYM("*DOCUMENTATION-POOL*",1756));
    if (ecl_unlikely(ECL_ATOM(v4))) FEtype_error_cons(v4);
    T0 = v4;
   }
   value0 = (ECL_CONS_CAR(T0)=v1file,T0);
   cl_env_copy->nvalues = 1;
   return value0;
L3:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for GET-DOCUMENTATION                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_get_documentation(cl_narg narg, cl_object v1object, cl_object v2doc_type, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  if (Null(cl_functionp(v1object))) { goto L1; }
  v1object = si_compiled_function_name(v1object);
  if (!(v1object==ECL_NIL)) { goto L1; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (Null(v1object)) { goto L5; }
  if (!(ECL_LISTP(v1object))) { goto L5; }
  if (Null(si_valid_function_name_p(v1object))) { goto L5; }
  T0 = ecl_cadr(v1object);
  value0 = L8get_annotation(3, T0, VV[11], v2doc_type);
  return value0;
L5:;
  value0 = L8get_annotation(3, v1object, ECL_SYM("DOCUMENTATION",312), v2doc_type);
  return value0;
 }
}
/*	function definition for SET-DOCUMENTATION                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_set_documentation(cl_narg narg, cl_object v1object, cl_object v2doc_type, cl_object v3string, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg!=3)) FEwrong_num_arguments_anonym();
 {
TTL:
  if (ECL_STRINGP(v3string)) { goto L1; }
  if (v3string==ECL_NIL) { goto L1; }
  cl_error(2, _ecl_static_2, v3string);
L1:;
  {
   cl_object v4key;
   v4key = ECL_SYM("DOCUMENTATION",312);
   if (Null(v1object)) { goto L6; }
   if (!(ECL_LISTP(v1object))) { goto L6; }
   if (Null(si_valid_function_name_p(v1object))) { goto L6; }
   v1object = ecl_cadr(v1object);
   v4key = VV[11];
L6:;
   if (Null(v3string)) { goto L13; }
   L6annotate(v1object, v4key, v2doc_type, v3string);
   goto L4;
L13:;
   L7remove_annotation(v1object, v4key, v2doc_type);
  }
L4:;
  value0 = v3string;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for EXPAND-SET-DOCUMENTATION              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_expand_set_documentation(cl_narg narg, cl_object v1symbol, cl_object v2doc_type, cl_object v3string, ...)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg!=3)) FEwrong_num_arguments_anonym();
 {
TTL:
  if (Null(ecl_symbol_value(VV[0]))) { goto L1; }
  if (Null(v3string)) { goto L1; }
  if (ECL_STRINGP(v3string)) { goto L4; }
  cl_error(2, _ecl_static_2, v3string);
L4:;
  T0 = cl_list(2, ECL_SYM("QUOTE",679), v1symbol);
  T1 = cl_list(2, ECL_SYM("QUOTE",679), v2doc_type);
  T2 = cl_list(4, VV[13], T0, T1, v3string);
  value0 = ecl_list1(T2);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for MAKE-DSPEC                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L10make_dspec(cl_object v1definition)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_CONSP(v1definition))) { goto L1; }
  {
   cl_object v2kind;
   cl_object v3name;
   cl_object v4extra;
   v2kind = ecl_car(v1definition);
   v3name = ecl_cadr(v1definition);
   v4extra = ECL_NIL;
   if (!((v2kind)==(ECL_SYM("DEFMETHOD",940)))) { goto L6; }
   {
    cl_object v5list;
    v5list = ecl_caddr(v1definition);
    if (!(ECL_SYMBOLP(v5list))) { goto L10; }
    T0 = ecl_cadddr(v1definition);
    v4extra = CONS(v5list,T0);
    goto L9;
L10:;
    v4extra = v5list;
L9:;
   }
L6:;
   value0 = cl_listX(3, v2kind, v3name, v4extra);
   return value0;
  }
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function OPTIONAL-ANNOTATION                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC11optional_annotation(cl_object v1whole, cl_object v2env)
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
/*	function definition for DEFAULT-ANNOTATION-LOGIC              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L12default_annotation_logic(cl_narg narg, cl_object v1source_location, cl_object v2definition, cl_object v3output_form, ...)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>4)) FEwrong_num_arguments_anonym();
 {
  cl_object v4dspec;
  va_list args; va_start(args,v3output_form);
  {
   int i = 3;
   if (i >= narg) {
    v4dspec = L10make_dspec(v2definition);
   } else {
    i++;
    v4dspec = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v5kind;
   cl_object v6name;
   v5kind = ecl_car(v2definition);
   v6name = ecl_cadr(v2definition);
   T0 = cl_list(2, ECL_SYM("QUOTE",679), v6name);
   T1 = cl_list(2, ECL_SYM("QUOTE",679), v4dspec);
   T2 = cl_list(2, ECL_SYM("QUOTE",679), v1source_location);
   T3 = cl_list(5, VV[16], T0, VV[17], T1, T2);
   if (!((v5kind)==(ECL_SYM("DEFUN",289)))) { goto L10; }
   goto L7;
   goto L8;
L10:;
   goto L8;
L8:;
   if (!((v5kind)==(ECL_SYM("DEFMACRO",283)))) { goto L14; }
   goto L7;
   goto L12;
L14:;
   goto L12;
L12:;
   if (!((v5kind)==(ECL_SYM("DEFGENERIC",938)))) { goto L5; }
   goto L6;
L7:;
L6:;
   T5 = cl_list(2, ECL_SYM("QUOTE",679), v6name);
   T6 = ecl_caddr(v2definition);
   T7 = cl_list(2, ECL_SYM("QUOTE",679), T6);
   T4 = cl_list(5, VV[16], T5, ECL_SYM("LAMBDA-LIST",998), ECL_NIL, T7);
   goto L4;
L5:;
   T4 = ECL_NIL;
L4:;
   value0 = cl_list(4, ECL_SYM("PROGN",671), T3, T4, v3output_form);
   return value0;
  }
 }
}

#include "lsp/helpfile.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclu7TSfLvwaxIm9_iTv9ZE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:LSP;HELPFILE.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclu7TSfLvwaxIm9_iTv9ZE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 {
  cl_object T0, T1;
 T0 = (ECL_SYM("EQUAL",335)->symbol.gfdef);
 T1 = cl_make_hash_table(4, ECL_SYM("TEST",1316), T0, ECL_SYM("SIZE",1308), ecl_make_fixnum(128));
 cl_set(ECL_SYM("*DOCUMENTATION-POOL*",1756),cl_list(2, T1, _ecl_static_1));
 si_Xmake_special(VV[0]);
 cl_set(VV[0],ECL_T);
 }
 ecl_cmp_defun(VV[22]);                           /*  NEW-DOCUMENTATION-POOL */
 ecl_cmp_defun(VV[23]);                           /*  RECORD-CONS     */
 ecl_cmp_defun(VV[24]);                           /*  RECORD-FIELD    */
 ecl_cmp_defun(VV[25]);                           /*  SET-RECORD-FIELD */
 ecl_cmp_defun(VV[26]);                           /*  REM-RECORD-FIELD */
 ecl_cmp_defun(VV[27]);                           /*  ANNOTATE        */
 ecl_cmp_defun(VV[28]);                           /*  REMOVE-ANNOTATION */
 ecl_cmp_defun(VV[29]);                           /*  GET-ANNOTATION  */
 ecl_cmp_defun(VV[31]);                           /*  DUMP-DOCUMENTATION */
 ecl_cmp_defun(VV[33]);                           /*  GET-DOCUMENTATION */
 ecl_cmp_defun(VV[34]);                           /*  SET-DOCUMENTATION */
 ecl_cmp_defun(VV[35]);                           /*  EXPAND-SET-DOCUMENTATION */
 ecl_cmp_defun(VV[36]);                           /*  MAKE-DSPEC      */
 ecl_cmp_defmacro(VV[37]);                        /*  OPTIONAL-ANNOTATION */
 ecl_cmp_defun(VV[38]);                           /*  DEFAULT-ANNOTATION-LOGIC */
}
