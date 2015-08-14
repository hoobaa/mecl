/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPMAIN.LSP                                   */
#include <ecl/ecl-cmp.h>
#include "cmp/cmpmain.eclh"
/*	function definition for SAFE-MKSTEMP                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1safe_mkstemp(cl_object v1template)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2base;
   v2base = si_mkstemp(v1template);
   if (Null(v2base)) { goto L2; }
   {
    cl_object v3output;
    T0 = cl_pathname_name(1, v2base);
    value0 = cl_pathname_type(1, v2base);
    if ((value0)!=ECL_NIL) { goto L7; }
    T1 = _ecl_static_2;
    goto L5;
L7:;
    T1 = value0;
    goto L5;
L5:;
    T2 = cl_concatenate(3, ECL_SYM("STRING",805), T0, T1);
    v3output = cl_make_pathname(6, ECL_SYM("NAME",1273), T2, ECL_SYM("TYPE",1318), _ecl_static_3, ECL_SYM("DEFAULTS",1216), v2base);
    if ((cl_probe_file(v3output))!=ECL_NIL) { goto L9; }
    if (Null(si_copy_file(v2base, v3output))) { goto L9; }
    T0 = cl_truename(v3output);
    T1 = cl_truename(v2base);
    v2base = cl_list(2, T0, T1);
    goto L2;
L9:;
    cl_delete_file(v2base);
    v2base = ECL_NIL;
   }
L2:;
   if ((v2base)!=ECL_NIL) { goto L15; }
   cl_error(2, _ecl_static_4, v1template);
L15:;
   value0 = v2base;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for COMPILE-FILE-PATHNAME                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2compile_file_pathname(cl_narg narg, cl_object v1name, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2output_file;
  cl_object v3type;
  cl_object v4type_supplied_p;
  cl_object v5verbose;
  cl_object v6print;
  cl_object v7c_file;
  cl_object v8h_file;
  cl_object v9data_file;
  cl_object v10system_p;
  cl_object v11load;
  cl_object v12external_format;
  cl_object v13source_truename;
  cl_object v14source_offset;
  ecl_va_list args; ecl_va_start(args,v1name,narg,1);
  {
   cl_object keyvars[24];
   cl_parse_key(args,12,L2compile_file_pathnamekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[12])) {
    v2output_file = ECL_T;
   } else {
    v2output_file = keyvars[0];
   }
   v3type = keyvars[1];
   v4type_supplied_p = keyvars[13];
   v5verbose = keyvars[2];
   v6print = keyvars[3];
   v7c_file = keyvars[4];
   v8h_file = keyvars[5];
   v9data_file = keyvars[6];
   v10system_p = keyvars[7];
   v11load = keyvars[8];
   v12external_format = keyvars[9];
   v13source_truename = keyvars[10];
   v14source_offset = keyvars[11];
  }
  {
   cl_object v15format;
   cl_object v16extension;
   v15format = ECL_NIL;
   v16extension = ECL_NIL;
   if ((v4type_supplied_p)!=ECL_NIL) { goto L4; }
   if (Null(v10system_p)) { goto L7; }
   v3type = ECL_SYM("OBJECT",1278);
   goto L6;
L7:;
   v3type = VV[1];
L6:;
L4:;
   if (!(ecl_eql(v3type,VV[2]))) { goto L15; }
   goto L12;
   goto L13;
L15:;
   goto L13;
L13:;
   if (!(ecl_eql(v3type,VV[4]))) { goto L10; }
   goto L11;
L12:;
L11:;
   v15format = ecl_symbol_value(VV[6]);
   goto L9;
L10:;
   if (!(ecl_eql(v3type,VV[7]))) { goto L24; }
   goto L21;
   goto L22;
L24:;
   goto L22;
L22:;
   if (!(ecl_eql(v3type,VV[9]))) { goto L28; }
   goto L21;
   goto L26;
L28:;
   goto L26;
L26:;
   if (!(ecl_eql(v3type,VV[11]))) { goto L19; }
   goto L20;
L21:;
L20:;
   v15format = ecl_symbol_value(VV[13]);
   goto L9;
L19:;
   if (!(ecl_eql(v3type,VV[14]))) { goto L32; }
   v16extension = _ecl_static_5;
   goto L9;
L32:;
   if (!(ecl_eql(v3type,VV[15]))) { goto L35; }
   v16extension = _ecl_static_6;
   goto L9;
L35:;
   if (!(ecl_eql(v3type,VV[16]))) { goto L38; }
   v16extension = _ecl_static_7;
   goto L9;
L38:;
   if (!(ecl_eql(v3type,VV[17]))) { goto L41; }
   v16extension = _ecl_static_8;
   goto L9;
L41:;
   if (!(ecl_eql(v3type,ECL_SYM("OBJECT",1278)))) { goto L44; }
   v16extension = ecl_symbol_value(VV[18]);
   goto L9;
L44:;
   if (!(ecl_eql(v3type,VV[19]))) { goto L47; }
   v15format = ecl_symbol_value(VV[20]);
   goto L9;
L47:;
   if (!(ecl_eql(v3type,VV[1]))) { goto L54; }
   goto L51;
   goto L52;
L54:;
   goto L52;
L52:;
   if (!(ecl_eql(v3type,VV[22]))) { goto L9; }
   goto L50;
L51:;
L50:;
   v16extension = _ecl_static_9;
L9:;
   if (!(ecl_eql(v2output_file,ECL_T))) { goto L62; }
   goto L58;
   goto L60;
L62:;
   goto L60;
L60:;
   if (!((v2output_file)==(ECL_NIL))) { goto L65; }
   goto L58;
   goto L59;
L65:;
   goto L59;
L59:;
   value0 = v2output_file;
   cl_env_copy->nvalues = 1;
   return value0;
L58:;
   if (Null(v15format)) { goto L67; }
   T0 = cl_pathname_name(1, v1name);
   T1 = cl_format(3, ECL_NIL, v15format, T0);
   value0 = cl_merge_pathnames(2, T1, v1name);
   return value0;
L67:;
   value0 = cl_make_pathname(4, ECL_SYM("TYPE",1318), v16extension, ECL_SYM("DEFAULTS",1216), v1name);
   return value0;
  }
 }
}
/*	function definition for CMP-DELETE-FILE                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3cmp_delete_file(cl_object v1file)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   v2 = ecl_make_bool(ecl_symbol_value(VV[27])==ECL_NIL);
   if (Null(v2)) { goto L2; }
   value0 = v2;
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
   {
    cl_object v3;
    v3 = si_getenv(_ecl_static_10);
    if (Null(v3)) { goto L5; }
    value0 = v3;
    cl_env_copy->nvalues = 1;
    return value0;
L5:;
    {
     cl_object v4;
     T0 = cl_probe_file(v1file);
     v4 = ecl_make_bool(T0==ECL_NIL);
     if (Null(v4)) { goto L8; }
     value0 = v4;
     cl_env_copy->nvalues = 1;
     return value0;
L8:;
     if (Null(ecl_symbol_value(VV[28]))) { goto L10; }
     ecl_function_dispatch(cl_env_copy,VV[169])(2, _ecl_static_11, v1file) /*  CMPPROGRESS */;
     cl_set(VV[29],CONS(v1file,ecl_symbol_value(VV[29])));
     value0 = ecl_symbol_value(VV[29]);
     cl_env_copy->nvalues = 1;
     return value0;
L10:;
     value0 = cl_delete_file(v1file);
     return value0;
    }
   }
  }
 }
}
/*	local function G22                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC4__g22()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v1;
   v1 = ecl_symbol_value(VV[29]);
   {
    cl_object v2;
    cl_object v3;
    v2 = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v1))) FEtype_error_list(v1);
    v3 = v1;
L5:;
    if (!(ecl_endp(v3))) { goto L7; }
    goto L6;
L7:;
    v2 = _ecl_car(v3);
    {
     cl_object v4;
     v4 = _ecl_cdr(v3);
     if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
     v3 = v4;
    }
    cl_delete_file(v2);
    goto L5;
L6:;
    value0 = v1;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	local function FIX-FOR-MINGW                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC5fix_for_mingw(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4directory_namestring;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4directory_namestring = v5;
   }
   if (Null(v3)) { goto L8; }
   si_dm_too_many_arguments(v1);
L8:;
   value0 = v4directory_namestring;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for LINKER-CC                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6linker_cc(cl_narg narg, cl_object v1o_pathname, cl_object v2object_files, ...)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3type;
  cl_object v4ld_flags;
  ecl_va_list args; ecl_va_start(args,v2object_files,narg,2);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L6linker_cckeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[2])) {
    v3type = VV[19];
   } else {
    v3type = keyvars[0];
   }
   if (Null(keyvars[3])) {
    v4ld_flags = ecl_function_dispatch(cl_env_copy,VV[172])(1, ecl_symbol_value(VV[32])) /*  SPLIT-PROGRAM-OPTIONS */;
   } else {
    v4ld_flags = keyvars[1];
   }
  }
  T0 = ecl_symbol_value(VV[33]);
  T1 = ecl_function_dispatch(cl_env_copy,VV[175])(1, v1o_pathname) /*  BRIEF-NAMESTRING */;
  T2 = L35ecl_library_directory();
  T3 = cl_concatenate(3, ECL_SYM("STRING",805), _ecl_static_13, T2);
  if (Null(ecl_symbol_value(VV[34]))) { goto L5; }
  T4 = ecl_list1(ecl_symbol_value(VV[34]));
  goto L3;
L5:;
  T4 = ECL_NIL;
  goto L3;
L3:;
  T5 = ecl_function_dispatch(cl_env_copy,VV[172])(1, ecl_symbol_value(VV[35])) /*  SPLIT-PROGRAM-OPTIONS */;
  T6 = cl_append(4, v2object_files, T4, T5, v4ld_flags);
  T7 = cl_listX(4, _ecl_static_12, T1, T3, T6);
  value0 = ecl_function_dispatch(cl_env_copy,VV[176])(2, T0, T7) /*  SAFE-RUN-PROGRAM */;
  return value0;
 }
}
/*	function definition for LINKER-AR                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7linker_ar(cl_object v1output_name, cl_object v2o_name, cl_object v3ld_flags)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_namestring(v1output_name);
  T1 = ecl_function_dispatch(cl_env_copy,VV[175])(1, v2o_name) /*  BRIEF-NAMESTRING */;
  T2 = CONS(T1,v3ld_flags);
  value0 = L8static_lib_ar(T0, T2);
  return value0;
 }
}
/*	function definition for STATIC-LIB-AR                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8static_lib_ar(cl_object v1lib, cl_object v2object_files)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3lib;
   v3lib = ecl_function_dispatch(cl_env_copy,VV[175])(1, v1lib) /*  BRIEF-NAMESTRING */;
   if (Null(cl_probe_file(v3lib))) { goto L2; }
   cl_delete_file(v3lib);
L2:;
   T0 = ecl_symbol_value(VV[38]);
   {
    cl_object v4;
    cl_object v5;
    v4 = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v2object_files))) FEtype_error_list(v2object_files);
    v5 = v2object_files;
    {
     cl_object v6;
     cl_object v7;
     v6 = ecl_list1(ECL_NIL);
     v7 = v6;
L11:;
     if (!(ecl_endp(v5))) { goto L13; }
     goto L12;
L13:;
     v4 = _ecl_car(v5);
     {
      cl_object v8;
      v8 = _ecl_cdr(v5);
      if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
      v5 = v8;
     }
     if (ecl_unlikely(ECL_ATOM(v7))) FEtype_error_cons(v7);
     T2 = v7;
     T3 = ecl_function_dispatch(cl_env_copy,VV[175])(1, v4) /*  BRIEF-NAMESTRING */;
     v7 = ecl_list1(T3);
     (ECL_CONS_CDR(T2)=v7,T2);
     goto L11;
L12:;
     T1 = ecl_cdr(v6);
     goto L5;
    }
   }
L5:;
   T2 = cl_listX(3, _ecl_static_14, v3lib, T1);
   ecl_function_dispatch(cl_env_copy,VV[176])(2, T0, T2) /*  SAFE-RUN-PROGRAM */;
   T0 = ecl_list1(v3lib);
   value0 = ecl_function_dispatch(cl_env_copy,VV[176])(2, ecl_symbol_value(VV[39]), T0) /*  SAFE-RUN-PROGRAM */;
   return value0;
  }
 }
}
/*	function definition for GUESS-KIND                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L9guess_kind(cl_object v1pathname)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2record;
   {
    cl_object v3;
    v3 = cl_pathname_type(1, v1pathname);
    {
     cl_object v4;
     v4 = VV[45];
     goto L6;
L5:;
     {
      cl_object v5;
      cl_object v6;
      if (ecl_unlikely(ECL_ATOM(v4))) FEtype_error_cons(v4);
      v5 = v4;
      v6 = ECL_CONS_CAR(v5);
      if (Null(v6)) { goto L8; }
      {
       cl_object v7;
       if (ecl_unlikely(ECL_ATOM(v6))) FEtype_error_cons(v6);
       T0 = v6;
       v7 = ECL_CONS_CAR(T0);
       if (Null(cl_string_equal(2, v3, v7))) { goto L8; }
       v2record = v6;
       goto L1;
      }
     }
L8:;
     v4 = ECL_CONS_CDR(v4);
L6:;
     if (v4==ECL_NIL) { goto L19; }
     goto L5;
L19:;
     v2record = ECL_NIL;
    }
   }
L1:;
   if (Null(v2record)) { goto L21; }
   value0 = ecl_cadr(v2record);
   cl_env_copy->nvalues = 1;
   return value0;
L21:;
   (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(2, _ecl_static_19, v1pathname) /*  WARN */;
   value0 = ECL_SYM("OBJECT",1278);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for GUESS-LD-FLAGS                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L10guess_ld_flags(cl_narg narg, cl_object v1pathname, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2kind;
  ecl_va_list args; ecl_va_start(args,v1pathname,narg,1);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L10guess_ld_flagskeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[1])) {
    v2kind = L9guess_kind(v1pathname);
   } else {
    v2kind = keyvars[0];
   }
  }
  if (!(ecl_eql(v2kind,ECL_SYM("OBJECT",1278)))) { goto L7; }
  goto L4;
  goto L5;
L7:;
  goto L5;
L5:;
  if (!(ecl_eql(v2kind,VV[16]))) { goto L2; }
  goto L3;
L4:;
L3:;
  value0 = ecl_function_dispatch(cl_env_copy,VV[175])(1, v1pathname) /*  BRIEF-NAMESTRING */;
  return value0;
L2:;
  if (!(ecl_eql(v2kind,VV[1]))) { goto L15; }
  goto L12;
  goto L13;
L15:;
  goto L13;
L13:;
  if (!(ecl_eql(v2kind,VV[22]))) { goto L10; }
  goto L11;
L12:;
L11:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L10:;
  if (!(ecl_eql(v2kind,VV[7]))) { goto L23; }
  goto L20;
  goto L21;
L23:;
  goto L21;
L21:;
  if (!(ecl_eql(v2kind,VV[11]))) { goto L27; }
  goto L20;
  goto L25;
L27:;
  goto L25;
L25:;
  if (!(ecl_eql(v2kind,VV[51]))) { goto L31; }
  goto L20;
  goto L29;
L31:;
  goto L29;
L29:;
  if (!(ecl_eql(v2kind,VV[53]))) { goto L18; }
  goto L19;
L20:;
L19:;
  value0 = ecl_function_dispatch(cl_env_copy,VV[175])(1, v1pathname) /*  BRIEF-NAMESTRING */;
  return value0;
L18:;
  if (!(ecl_eql(v2kind,VV[2]))) { goto L39; }
  goto L36;
  goto L37;
L39:;
  goto L37;
L37:;
  if (!(ecl_eql(v2kind,VV[4]))) { goto L43; }
  goto L36;
  goto L41;
L43:;
  goto L41;
L41:;
  if (!(ecl_eql(v2kind,VV[57]))) { goto L47; }
  goto L36;
  goto L45;
L47:;
  goto L45;
L45:;
  if (!(ecl_eql(v2kind,VV[59]))) { goto L34; }
  goto L35;
L36:;
L35:;
  value0 = ecl_function_dispatch(cl_env_copy,VV[175])(1, v1pathname) /*  BRIEF-NAMESTRING */;
  return value0;
L34:;
  if (!(ecl_eql(v2kind,VV[19]))) { goto L50; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L50:;
  value0 = cl_error(2, _ecl_static_20, v2kind);
  return value0;
 }
}
/*	function definition for SYSTEM-LD-FLAG                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L17system_ld_flag(cl_object v1library)
{
 volatile cl_object lex0[2];
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  lex0[0] = v1library;                            /*  LIBRARY         */
TTL:
  {
   cl_object v2system;
   lex0[1] = ECL_NIL;                             /*  ASDF            */
   v2system = ECL_NIL;
   if (Null(lex0[1])) { goto L6; }
   v2system = LC12asdfcall(3, lex0, VV[65], lex0[0], ECL_NIL);
   if (Null(v2system)) { goto L6; }
   value0 = LC15find_archive(lex0, v2system);
   goto L4;
L6:;
   value0 = ECL_NIL;
   goto L4;
L4:;
   if ((value0)!=ECL_NIL) { goto L3; }
   value0 = LC16fallback(lex0);
   return value0;
L3:;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function FALLBACK                                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC16fallback(volatile cl_object *lex0)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_string_downcase(1, lex0[0]);
  T1 = L2compile_file_pathname(3, T0, ECL_SYM("TYPE",1318), VV[9]);
  T2 = cl_merge_pathnames(2, _ecl_static_21, T1);
  value0 = cl_translate_logical_pathname(1, T2);
  return value0;
 }
}
/*	local function FIND-ARCHIVE                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC15find_archive(volatile cl_object *lex0, cl_object v1system)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = LC14existing_system_output(lex0, v1system, VV[9]);
  if ((value0)!=ECL_NIL) { goto L2; }
  value0 = LC14existing_system_output(lex0, v1system, VV[2]);
  return value0;
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function EXISTING-SYSTEM-OUTPUT                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC14existing_system_output(volatile cl_object *lex0, cl_object v1system, cl_object v2type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3o;
   v3o = LC13system_output(lex0, v1system, v2type);
   if (Null(v3o)) { goto L3; }
   v3o = cl_probe_file(v3o);
   if (Null(v3o)) { goto L3; }
   value0 = cl_namestring(v3o);
   return value0;
L3:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function SYSTEM-OUTPUT                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC13system_output(volatile cl_object *lex0, cl_object v1system, cl_object v2type)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3build;
   T0 = LC11asdfsym(lex0, VV[63]);
   v3build = (cl_env_copy->function=(ECL_SYM("MAKE-INSTANCE",949)->symbol.gfdef))->cfun.entry(3, T0, ECL_SYM("TYPE",1318), v2type) /*  MAKE-INSTANCE */;
   T0 = LC12asdfcall(3, lex0, VV[64], v3build, v1system);
   value0 = ecl_car(T0);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function ASDFCALL                                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC12asdfcall(cl_narg narg, volatile cl_object *lex0, cl_object v1fun, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2rest;
  ecl_va_list args; ecl_va_start(args,v1fun,narg,1);
  v2rest = cl_grab_rest_args(args);
  ecl_va_end(args);
  T0 = LC11asdfsym(lex0, v1fun);
  value0 = cl_apply(2, T0, v2rest);
  return value0;
 }
}
/*	local function ASDFSYM                                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC11asdfsym(volatile cl_object *lex0, cl_object v1x)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_string(v1x);
  value0 = cl_find_symbol(2, T0, lex0[1]);
  return value0;
 }
}
/*	function definition for BUILDER                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L18builder(cl_narg narg, cl_object v1target, cl_object v2output_name, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3lisp_files;
  cl_object v4ld_flags;
  cl_object v5init_name;
  cl_object v6main_name;
  cl_object v7prologue_code;
  cl_object v8epilogue_code;
  ecl_va_list args; ecl_va_start(args,v2output_name,narg,2);
  {
   cl_object keyvars[12];
   cl_parse_key(args,6,L18builderkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3lisp_files = keyvars[0];
   v4ld_flags = keyvars[1];
   v5init_name = keyvars[2];
   v6main_name = keyvars[3];
   if (Null(keyvars[10])) {
    v7prologue_code = _ecl_static_2;
   } else {
    v7prologue_code = keyvars[4];
   }
   if (Null(keyvars[11])) {
    if (!((v1target)==(VV[19]))) { goto L3; }
    v8epilogue_code = VV[67];
    goto L2;
L3:;
    v8epilogue_code = ECL_NIL;
L2:;
   } else {
    v8epilogue_code = keyvars[5];
   }
  }
  value0 = ecl_symbol_value(VV[68]);
  if ((value0)!=ECL_NIL) { goto L7; }
  T0 = Null(ecl_symbol_value(ECL_SYM("*COMPILE-VERBOSE*",29)))?ECL_T:ECL_NIL;
  goto L5;
L7:;
  T0 = value0;
  goto L5;
L5:;
  ecl_bds_bind(cl_env_copy,VV[68],T0);            /*  *SUPPRESS-COMPILER-MESSAGES* */
  if (Null(ecl_symbol_value(VV[69]))) { goto L9; }
  cl_set(VV[68],cl_list(3, ECL_SYM("OR",614), ecl_symbol_value(VV[68]), VV[70]));
L9:;
  if (Null(ecl_symbol_value(VV[71]))) { goto L12; }
  cl_set(VV[68],cl_list(3, ECL_SYM("OR",614), ecl_symbol_value(VV[68]), VV[72]));
L12:;
  if (!(v8epilogue_code==ECL_NIL)) { goto L16; }
  v8epilogue_code = _ecl_static_2;
  goto L15;
L16:;
  {
   cl_object v9;
   v9 = ecl_make_bool(ECL_STRINGP(v8epilogue_code));
   if (Null(v9)) { goto L20; }
   goto L15;
L20:;
   {
    cl_object v10;
    v10 = ecl_symbol_value(ECL_SYM("+IO-SYNTAX-PROGV-LIST+",1720));
    {
     cl_object v12, v13; cl_index v11;
     v12 = _ecl_car(v10);
     v13 = _ecl_cdr(v10);
     v11 = ecl_progv(cl_env_copy, v12, v13);
     {
      cl_object v14stream;
      v14stream = cl_make_string_output_stream(0);
      ecl_princ_str("{ const char *lisp_code = ",v14stream);
      T0 = cl_write_to_string(1, v8epilogue_code);
      ecl_function_dispatch(cl_env_copy,VV[189])(2, T0, v14stream) /*  WT-FILTERED-DATA */;
      ecl_princ(_ecl_static_23,v14stream);
      v8epilogue_code = cl_get_output_stream_string(v14stream);
     }
     ecl_bds_unwind(cl_env_copy,v11);
    }
   }
  }
L15:;
  if (!(v7prologue_code==ECL_NIL)) { goto L32; }
  v7prologue_code = _ecl_static_2;
  goto L31;
L32:;
  {
   cl_object v9;
   v9 = ecl_make_bool(ECL_STRINGP(v7prologue_code));
   if (Null(v9)) { goto L36; }
   goto L31;
L36:;
   {
    cl_object v10;
    v10 = ecl_symbol_value(ECL_SYM("+IO-SYNTAX-PROGV-LIST+",1720));
    {
     cl_object v12, v13; cl_index v11;
     v12 = _ecl_car(v10);
     v13 = _ecl_cdr(v10);
     v11 = ecl_progv(cl_env_copy, v12, v13);
     {
      cl_object v14stream;
      v14stream = cl_make_string_output_stream(0);
      ecl_princ_str("{ const char *lisp_code = ",v14stream);
      T0 = cl_write_to_string(1, v7prologue_code);
      ecl_function_dispatch(cl_env_copy,VV[189])(2, T0, v14stream) /*  WT-FILTERED-DATA */;
      ecl_princ(_ecl_static_23,v14stream);
      v7prologue_code = cl_get_output_stream_string(v14stream);
     }
     ecl_bds_unwind(cl_env_copy,v11);
    }
   }
  }
L31:;
  {
   cl_object v9tmp_names;
   cl_object v10tmp_name;
   cl_object v11c_name;
   cl_object v12o_name;
   cl_object v13submodules;
   cl_object v14submodules_data;
   cl_object v15c_file;
   v9tmp_names = L1safe_mkstemp(VV[73]);
   v10tmp_name = ecl_car(v9tmp_names);
   T0 = L2compile_file_pathname(3, v10tmp_name, ECL_SYM("TYPE",1318), VV[16]);
   v11c_name = si_coerce_to_filename(T0);
   T0 = L2compile_file_pathname(3, v10tmp_name, ECL_SYM("TYPE",1318), ECL_SYM("OBJECT",1278));
   v12o_name = si_coerce_to_filename(T0);
   v13submodules = ECL_NIL;
   v14submodules_data = ECL_NIL;
   v15c_file = ECL_NIL;
   {
    cl_object v16;
    v16 = cl_reverse(v3lisp_files);
    goto L58;
L57:;
    {
     cl_object v17item;
     v17item = ecl_car(v16);
     {
      cl_object v18path;
      cl_object v19kind;
      if (!(ECL_SYMBOLP(v17item))) { goto L64; }
      v18path = L17system_ld_flag(v17item);
      goto L63;
L64:;
      if (Null(cl_pathnamep(v17item))) { goto L66; }
      v18path = v17item;
      goto L63;
L66:;
      if (!(ECL_STRINGP(v17item))) { goto L68; }
      v18path = cl_parse_namestring(1, v17item);
      goto L63;
L68:;
      v18path = si_etypecase_error(v17item, VV[74]);
L63:;
      v19kind = L9guess_kind(v18path);
      if ((ecl_memql(v19kind,VV[75]))!=ECL_NIL) { goto L71; }
      cl_error(3, _ecl_static_24, v17item, v19kind);
L71:;
      {
       cl_object v20init_fn;
       cl_object v21flags;
       T0 = L9guess_kind(v18path);
       v20init_fn = ecl_function_dispatch(cl_env_copy,VV[190])(2, v18path, T0) /*  GUESS-INIT-NAME */;
       v21flags = L10guess_ld_flags(1, v18path);
       if (Null(v21flags)) { goto L75; }
       v4ld_flags = CONS(v21flags,v4ld_flags);
L75:;
       {
        cl_object v23;                            /*  MAP             */
        cl_object v24;                            /*  ARRAY           */
        value0 = si_get_cdata(v18path);
        v23 = value0;
        {
         const int v25 = cl_env_copy->nvalues;
         cl_object v26;
         v26 = (v25<=1)? ECL_NIL : cl_env_copy->values[1];
         v24 = v26;
        }
        T0 = ecl_copy_seq(v24);
        v14submodules_data = CONS(T0,v14submodules_data);
        {
         cl_fixnum v25;
         v25 = ecl_length(v24);
         T0 = cl_list(3, ecl_make_fixnum(v25), v20init_fn, v18path);
         v13submodules = CONS(T0,v13submodules);
        }
        si_munmap(v23);
       }
      }
     }
    }
    v16 = ecl_cdr(v16);
L58:;
    if (Null(v16)) { goto L85; }
    goto L57;
L85:;
   }
   T0 = (ECL_SYM("CONCATENATE",244)->symbol.gfdef);
   v14submodules_data = cl_apply(3, T0, VV[76], v14submodules_data);
   v15c_file = cl_open(5, v11c_name, ECL_SYM("DIRECTION",1218), ECL_SYM("OUTPUT",1282), ECL_SYM("EXTERNAL-FORMAT",1236), ECL_SYM("DEFAULT",1215));
   cl_format(3, v15c_file, ecl_symbol_value(VV[41]), v13submodules);
   if (ECL_SYMBOLP(v2output_name)) { goto L95; }
   if (!(ECL_STRINGP(v2output_name))) { goto L93; }
   goto L94;
L95:;
L94:;
   v2output_name = L2compile_file_pathname(3, v2output_name, ECL_SYM("TYPE",1318), v1target);
L93:;
   if ((v5init_name)!=ECL_NIL) { goto L98; }
   v5init_name = ecl_function_dispatch(cl_env_copy,VV[191])(3, v2output_name, VV[77], v1target) /*  COMPUTE-INIT-NAME */;
L98:;
   if ((v6main_name)!=ECL_NIL) { goto L101; }
   v6main_name = ecl_function_dispatch(cl_env_copy,VV[192])(3, v2output_name, VV[77], v1target) /*  COMPUTE-MAIN-NAME */;
L101:;
   if ((v1target)==(VV[1])) { goto L104; }
   {
    cl_object v16files_with_binary_data;
    {
     cl_object v17size;
     cl_object v18name;
     cl_object v19path;
     cl_object v20;
     v17size = ECL_NIL;
     v18name = ECL_NIL;
     v19path = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v13submodules))) FEtype_error_list(v13submodules);
     v20 = v13submodules;
     {
      cl_object v21;
      cl_object v22;
      v21 = ecl_list1(ECL_NIL);
      v22 = v21;
L114:;
      if (!(ecl_endp(v20))) { goto L116; }
      goto L115;
L116:;
      {
       cl_object v23;
       v23 = _ecl_car(v20);
       v17size = ecl_car(v23);
       v23 = ecl_cdr(v23);
       v18name = ecl_car(v23);
       v23 = ecl_cdr(v23);
       v19path = ecl_car(v23);
      }
      {
       cl_object v23;
       v23 = _ecl_cdr(v20);
       if (ecl_unlikely(!ECL_LISTP(v23))) FEtype_error_list(v23);
       v20 = v23;
      }
      if (!(ecl_plusp(v17size))) { goto L133; }
      if (ecl_unlikely(ECL_ATOM(v22))) FEtype_error_cons(v22);
      T0 = v22;
      v22 = ecl_list1(v19path);
      (ECL_CONS_CDR(T0)=v22,T0);
L133:;
      goto L114;
L115:;
      v16files_with_binary_data = ecl_cdr(v21);
      goto L106;
     }
    }
L106:;
    if (Null(v16files_with_binary_data)) { goto L104; }
    cl_error(3, _ecl_static_25, v2output_name, v16files_with_binary_data);
   }
L104:;
   if (!(ecl_eql(v1target,VV[19]))) { goto L142; }
   cl_format(6, v15c_file, ecl_symbol_value(VV[42]), v5init_name, _ecl_static_2, v13submodules, _ecl_static_2);
   cl_format(5, v15c_file, ecl_symbol_value(VV[43]), v7prologue_code, v5init_name, v8epilogue_code);
   cl_close(1, v15c_file);
   L36compiler_cc(v11c_name, v12o_name);
   T0 = cl_namestring(v12o_name);
   T1 = CONS(T0,v4ld_flags);
   L6linker_cc(2, v2output_name, T1);
   goto L141;
L142:;
   if (!(ecl_eql(v1target,VV[9]))) { goto L153; }
   goto L150;
   goto L151;
L153:;
   goto L151;
L151:;
   if (!(ecl_eql(v1target,VV[7]))) { goto L157; }
   goto L150;
   goto L155;
L157:;
   goto L155;
L155:;
   if (!(ecl_eql(v1target,VV[11]))) { goto L148; }
   goto L149;
L150:;
L149:;
   cl_format(6, v15c_file, ecl_symbol_value(VV[42]), v5init_name, v7prologue_code, v13submodules, v8epilogue_code);
   ecl_function_dispatch(cl_env_copy,VV[193])(2, _ecl_static_26, v6main_name) /*  CMPNOTE */;
   cl_format(6, v15c_file, ecl_symbol_value(VV[44]), v6main_name, v7prologue_code, v5init_name, v8epilogue_code);
   cl_close(1, v15c_file);
   L36compiler_cc(v11c_name, v12o_name);
   if (Null(cl_probe_file(v2output_name))) { goto L165; }
   cl_delete_file(v2output_name);
L165:;
   L7linker_ar(v2output_name, v12o_name, v4ld_flags);
   goto L141;
L148:;
   si_ecase_error(v1target, VV[80]);
L141:;
   ecl_function_dispatch(cl_env_copy,VV[194])(2, v2output_name, v14submodules_data) /*  DATA-BINARY-DUMP */;
   {
    cl_object v16;
    cl_object v17;
    v16 = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v9tmp_names))) FEtype_error_list(v9tmp_names);
    v17 = v9tmp_names;
L172:;
    if (!(ecl_endp(v17))) { goto L174; }
    goto L173;
L174:;
    v16 = _ecl_car(v17);
    {
     cl_object v18;
     v18 = _ecl_cdr(v17);
     if (ecl_unlikely(!ECL_LISTP(v18))) FEtype_error_list(v18);
     v17 = v18;
    }
    ecl_function_dispatch(cl_env_copy,VV[30])(1, v16);
    goto L172;
L173:;
    goto L168;
   }
L168:;
   L3cmp_delete_file(v11c_name);
   L3cmp_delete_file(v12o_name);
   value0 = v2output_name;
   cl_env_copy->nvalues = 1;
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
 }
}
/*	function definition for BUILD-FASL                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L19build_fasl(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1args;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1args = cl_grab_rest_args(args);
  ecl_va_end(args);
  T0 = ecl_fdefinition(VV[81]);
  value0 = cl_apply(3, T0, VV[1], v1args);
  return value0;
 }
}
/*	function definition for BUILD-PROGRAM                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L20build_program(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1args;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1args = cl_grab_rest_args(args);
  ecl_va_end(args);
  T0 = ecl_fdefinition(VV[81]);
  value0 = cl_apply(3, T0, VV[19], v1args);
  return value0;
 }
}
/*	function definition for BUILD-STATIC-LIBRARY                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L21build_static_library(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1args;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1args = cl_grab_rest_args(args);
  ecl_va_end(args);
  T0 = ecl_fdefinition(VV[81]);
  value0 = cl_apply(3, T0, VV[7], v1args);
  return value0;
 }
}
/*	function definition for BUILD-SHARED-LIBRARY                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L22build_shared_library(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  value0 = cl_error(1, _ecl_static_27);
  return value0;
 }
}
/*	function definition for COMPILE-FILE                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L25compile_file(volatile cl_narg narg, cl_object volatile v1input_pathname, ...)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11;
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1, CLV2, CLV3, CLV4, CLV5, CLV6, CLV7, CLV8, CLV9, CLV10, CLV11, CLV12, CLV13, CLV14, CLV15
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  volatile cl_object v2args;
  volatile cl_object v3c_file;
  volatile cl_object v4h_file;
  volatile cl_object v5data_file;
  volatile cl_object v6output_file;
  ecl_va_list args; ecl_va_start(args,v1input_pathname,narg,1);
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1input_pathname,env0);      /*  INPUT-PATHNAME  */
  {
   cl_object keyvars[22];
   cl_parse_key(args,11,L25compile_filekeys,keyvars,(cl_object*)&v2args,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[11])) {
    ecl_bds_push(cl_env_copy,ECL_SYM("*COMPILE-VERBOSE*",29)); /*  *COMPILE-VERBOSE* */
   } else {
    ecl_bds_bind(cl_env_copy,ECL_SYM("*COMPILE-VERBOSE*",29),keyvars[0]); /*  *COMPILE-VERBOSE* */
   }
   if (Null(keyvars[12])) {
    ecl_bds_push(cl_env_copy,ECL_SYM("*COMPILE-PRINT*",28)); /*  *COMPILE-PRINT* */
   } else {
    ecl_bds_bind(cl_env_copy,ECL_SYM("*COMPILE-PRINT*",28),keyvars[1]); /*  *COMPILE-PRINT* */
   }
   CLV1 = env0 = CONS(keyvars[2],env0);           /*  SOURCE-TRUENAME */
   if (Null(keyvars[14])) {
    CLV2 = env0 = CONS(ecl_make_fixnum(0),env0);  /*  SOURCE-OFFSET   */
   } else {
    CLV2 = env0 = CONS(keyvars[3],env0);          /*  SOURCE-OFFSET   */
   }
   v3c_file = keyvars[4];
   v4h_file = keyvars[5];
   v5data_file = keyvars[6];
   CLV3 = env0 = CONS(keyvars[7],env0);           /*  SYSTEM-P        */
   CLV4 = env0 = CONS(keyvars[8],env0);           /*  LOAD            */
   if (Null(keyvars[20])) {
    CLV5 = env0 = CONS(ECL_SYM("DEFAULT",1215),env0); /*  EXTERNAL-FORMAT */
   } else {
    CLV5 = env0 = CONS(keyvars[9],env0);          /*  EXTERNAL-FORMAT */
   }
   v6output_file = keyvars[10];
  }
  {
   volatile cl_object v7input_file;
   volatile cl_object env1 = env0;
   ecl_bds_push(cl_env_copy,ECL_SYM("*STANDARD-OUTPUT*",67)); /*  *STANDARD-OUTPUT* */
   ecl_bds_push(cl_env_copy,ECL_SYM("*ERROR-OUTPUT*",33)); /*  *ERROR-OUTPUT* */
   ecl_bds_push(cl_env_copy,VV[86]);              /*  *COMPILER-IN-USE* */
   ecl_bds_push(cl_env_copy,ECL_SYM("*PACKAGE*",43)); /*  *PACKAGE*   */
   ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-PRETTY*",55),ECL_NIL); /*  *PRINT-PRETTY* */
   ecl_bds_bind(cl_env_copy,ECL_SYM("*COMPILE-FILE-PATHNAME*",26),ECL_NIL); /*  *COMPILE-FILE-PATHNAME* */
   ecl_bds_bind(cl_env_copy,ECL_SYM("*COMPILE-FILE-TRUENAME*",27),ECL_NIL); /*  *COMPILE-FILE-TRUENAME* */
   T0 = CONS(ECL_CONS_CAR(CLV1),ecl_make_fixnum(0));
   ecl_bds_bind(cl_env_copy,ECL_SYM("*SOURCE-LOCATION*",1180),T0); /*  *SOURCE-LOCATION* */
   value0 = ecl_symbol_value(VV[68]);
   if ((value0)!=ECL_NIL) { goto L3; }
   T0 = Null(ecl_symbol_value(ECL_SYM("*COMPILE-VERBOSE*",29)))?ECL_T:ECL_NIL;
   goto L1;
L3:;
   T0 = value0;
   goto L1;
L1:;
   ecl_bds_bind(cl_env_copy,VV[68],T0);           /*  *SUPPRESS-COMPILER-MESSAGES* */
   v7input_file = ECL_NIL;
   CLV6 = env1 = CONS(ECL_NIL,env1);              /*  INIT-NAME       */
   if (Null(ecl_symbol_value(VV[69]))) { goto L6; }
   cl_set(VV[68],cl_list(3, ECL_SYM("OR",614), ecl_symbol_value(VV[68]), VV[70]));
L6:;
   if (Null(ecl_symbol_value(VV[71]))) { goto L9; }
   cl_set(VV[68],cl_list(3, ECL_SYM("OR",614), ecl_symbol_value(VV[68]), VV[72]));
L9:;
   if ((ECL_CONS_CAR(CLV3))!=ECL_NIL) { goto L12; }
   cl_format(2, ECL_T, _ecl_static_28);
L12:;
   T0 = cl_merge_pathnames(1, ECL_CONS_CAR(CLV0));
   cl_set(ECL_SYM("*COMPILE-FILE-PATHNAME*",26),cl_pathname(T0));
   if ((cl_probe_file(ecl_symbol_value(ECL_SYM("*COMPILE-FILE-PATHNAME*",26))))!=ECL_NIL) { goto L16; }
   if (Null(cl_pathname_type(1, ECL_CONS_CAR(CLV0)))) { goto L18; }
   cl_error(3, ECL_SYM("FILE-ERROR",353), ECL_SYM("PATHNAME",1285), ECL_CONS_CAR(CLV0));
   goto L16;
L18:;
   {
    cl_object v8;
    v8 = VV[87];
    goto L23;
L22:;
    {
     cl_object v9ext;
     v9ext = ecl_car(v8);
     cl_set(ECL_SYM("*COMPILE-FILE-PATHNAME*",26),cl_make_pathname(4, ECL_SYM("TYPE",1318), v9ext, ECL_SYM("DEFAULTS",1216), ECL_CONS_CAR(CLV0)));
     if (Null(cl_probe_file(ecl_symbol_value(ECL_SYM("*COMPILE-FILE-PATHNAME*",26))))) { goto L29; }
     goto L16;
L29:;
    }
    v8 = ecl_cdr(v8);
L23:;
    if (Null(v8)) { goto L33; }
    goto L22;
L33:;
    cl_error(3, ECL_SYM("FILE-ERROR",353), ECL_SYM("PATHNAME",1285), ECL_CONS_CAR(CLV0));
   }
L16:;
   v7input_file = cl_truename(ecl_symbol_value(ECL_SYM("*COMPILE-FILE-PATHNAME*",26)));
   cl_set(ECL_SYM("*COMPILE-FILE-TRUENAME*",27),v7input_file);
   if (Null(ECL_CONS_CAR(CLV3))) { goto L39; }
   if (Null(ECL_CONS_CAR(CLV4))) { goto L39; }
   cl_error(1, _ecl_static_29);
L39:;
   T0 = cl_namestring(ECL_CONS_CAR(CLV0));
   ecl_function_dispatch(cl_env_copy,VV[169])(2, _ecl_static_30, T0) /*  CMPPROGRESS */;
   {
    volatile cl_object v8compiler_conditions;
    volatile cl_object env2 = env1;
    CLV7 = env2 = CONS(VV[25],env2);              /*  EOF             */
    ecl_bds_push(cl_env_copy,VV[86]);             /*  *COMPILER-IN-USE* */
    ecl_bds_bind(cl_env_copy,VV[88],ECL_NIL);     /*  *LOAD-TIME-VALUES* */
    T0 = (VV[26]->symbol.gfdef);
    T1 = cl_apply(3, T0, v7input_file, v2args);
    CLV8 = env2 = CONS(T1,env2);                  /*  OUTPUT-FILE     */
    CLV9 = env2 = CONS(ECL_NIL,env2);             /*  TRUE-OUTPUT-FILE */
    T0 = (VV[26]->symbol.gfdef);
    T1 = cl_apply(7, T0, ECL_CONS_CAR(CLV8), VV[89], v3c_file, ECL_SYM("TYPE",1318), VV[16], v2args);
    CLV10 = env2 = CONS(T1,env2);                 /*  C-PATHNAME      */
    T0 = (VV[26]->symbol.gfdef);
    T1 = cl_apply(7, T0, ECL_CONS_CAR(CLV8), VV[89], v4h_file, ECL_SYM("TYPE",1318), VV[17], v2args);
    CLV11 = env2 = CONS(T1,env2);                 /*  H-PATHNAME      */
    T0 = (VV[26]->symbol.gfdef);
    T1 = cl_apply(7, T0, ECL_CONS_CAR(CLV8), VV[89], v5data_file, ECL_SYM("TYPE",1318), VV[14], v2args);
    CLV12 = env2 = CONS(T1,env2);                 /*  DATA-PATHNAME   */
    v8compiler_conditions = ECL_NIL;
    if ((v3c_file)!=ECL_NIL) { goto L49; }
    T0 = ecl_list1(ECL_CONS_CAR(CLV10));
    goto L48;
L49:;
    T0 = ECL_NIL;
L48:;
    if ((v4h_file)!=ECL_NIL) { goto L52; }
    T1 = ecl_list1(ECL_CONS_CAR(CLV11));
    goto L51;
L52:;
    T1 = ECL_NIL;
L51:;
    if ((v5data_file)!=ECL_NIL) { goto L55; }
    T2 = ecl_list1(ECL_CONS_CAR(CLV12));
    goto L54;
L55:;
    T2 = ECL_NIL;
L54:;
    T3 = cl_nconc(3, T0, T1, T2);
    CLV13 = env2 = CONS(T3,env2);                 /*  TO-DELETE       */
    ecl_bds_bind(cl_env_copy,VV[90],ECL_NIL);     /*  *COMPILER-CONDITIONS* */
    {
     volatile cl_object env3 = env2;
     CLV14 = env3 = CONS(ECL_NIL,env3);
     {
      volatile cl_object env4 = env3;
      CLV15 = env4 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env4); /*  TAGBODY */
      if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV15))) {
      if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L59;
      ecl_internal_error("GO found an inexistent tag");
      }
      {cl_object v9;
       v9 = ECL_NIL;
       v9 = ecl_make_cclosure_va((cl_objectfn)LC23__g97,env4,Cblock);
       T0 = v9;
      }
      T1 = ecl_function_dispatch(cl_env_copy,VV[211])(4, ECL_SYM("NAME",1273), ECL_SYM("ABORT",77), ECL_SYM("FUNCTION",1241), T0) /*  MAKE-RESTART */;
      T2 = ecl_list1(T1);
      T3 = CONS(T2,ecl_symbol_value(ECL_SYM("*RESTART-CLUSTERS*",4)));
      ecl_bds_bind(cl_env_copy,ECL_SYM("*RESTART-CLUSTERS*",4),T3); /*  *RESTART-CLUSTERS* */
      T0 = ecl_fdefinition(VV[212]);
      T1 = CONS(VV[70],T0);
      T2 = ecl_fdefinition(VV[213]);
      T3 = CONS(ECL_SYM("WARNING",904),T2);
      T4 = ecl_fdefinition(VV[214]);
      T5 = CONS(VV[91],T4);
      T6 = ecl_fdefinition(VV[215]);
      T7 = CONS(VV[92],T6);
      T8 = ecl_fdefinition(VV[215]);
      T9 = CONS(ECL_SYM("SERIOUS-CONDITION",742),T8);
      T10 = cl_list(5, T1, T3, T5, T7, T9);
      T11 = CONS(T10,ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5)));
      ecl_bds_bind(cl_env_copy,ECL_SYM("*HANDLER-CLUSTERS*",5),T11); /*  *HANDLER-CLUSTERS* */
      {
       volatile cl_object v9;
       volatile cl_object v10;
       volatile cl_object v11;
       v9 = ecl_symbol_value(ECL_SYM("+LOAD-COMPILE-LOCK+",1426));
       v10 = mp_lock_owner(v9);
       v11 = mp_lock_count(v9);
       {
        struct ecl_stack_frame _ecl_inner_frame_aux;
        volatile cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
        {
         volatile cl_object v12;
         v12 = _ecl_inner_frame;
         {
          volatile cl_object v13;
          v13 = ecl_symbol_value(ECL_SYM("*INTERRUPTS-ENABLED*",1023));
          ecl_bds_bind(cl_env_copy,ECL_SYM("*INTERRUPTS-ENABLED*",1023),ECL_NIL); /*  *INTERRUPTS-ENABLED* */
          ecl_bds_bind(cl_env_copy,ECL_SYM("*ALLOW-WITH-INTERRUPTS*",1730),ECL_NIL); /*  *ALLOW-WITH-INTERRUPTS* */
          {
          volatile bool unwinding = FALSE;
          cl_index v14=ECL_STACK_INDEX(cl_env_copy),v15;
          ecl_frame_ptr next_fr;
          if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
            unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
          } else {
          ecl_bds_bind(cl_env_copy,ECL_SYM("*INTERRUPTS-ENABLED*",1023),v13); /*  *INTERRUPTS-ENABLED* */
          mp_get_lock(1, v9);
          {
          volatile cl_object v16;
          volatile cl_object v17;
          v16 = cl_copy_tree(ecl_symbol_value(VV[94]));
          T0 = (ECL_SYM("EQUAL",335)->symbol.gfdef);
          v17 = cl_make_hash_table(4, ECL_SYM("SIZE",1308), ecl_make_fixnum(128), ECL_SYM("TEST",1316), T0);
          ecl_bds_bind(cl_env_copy,ECL_SYM("*GENSYM-COUNTER*",35),ecl_make_fixnum(0)); /*  *GENSYM-COUNTER* */
          ecl_bds_bind(cl_env_copy,VV[86],ECL_T); /*  *COMPILER-IN-USE* */
          ecl_bds_bind(cl_env_copy,VV[96],VV[93]); /*  *COMPILER-PHASE* */
          ecl_bds_bind(cl_env_copy,VV[97],ECL_NIL); /*  *CALLBACKS*   */
          ecl_bds_bind(cl_env_copy,VV[94],v16);   /*  *CMP-ENV-ROOT*  */
          ecl_bds_bind(cl_env_copy,VV[98],ECL_NIL); /*  *CMP-ENV*     */
          ecl_bds_bind(cl_env_copy,VV[99],ecl_make_fixnum(0)); /*  *MAX-TEMP* */
          ecl_bds_bind(cl_env_copy,VV[100],ecl_make_fixnum(0)); /*  *TEMP* */
          ecl_bds_bind(cl_env_copy,VV[101],ecl_make_fixnum(0)); /*  *NEXT-CMACRO* */
          ecl_bds_bind(cl_env_copy,VV[102],ecl_make_fixnum(0)); /*  *NEXT-CFUN* */
          ecl_bds_bind(cl_env_copy,VV[103],ecl_make_fixnum(0)); /*  *LAST-LABEL* */
          ecl_bds_bind(cl_env_copy,VV[104],v17);  /*  *LOAD-OBJECTS*  */
          ecl_bds_bind(cl_env_copy,VV[105],ECL_NIL); /*  *SETF-DEFINITIONS* */
          ecl_bds_bind(cl_env_copy,VV[106],ECL_NIL); /*  *MAKE-FORMS* */
          ecl_bds_bind(cl_env_copy,VV[107],ECL_NIL); /*  *STATIC-CONSTANTS* */
          ecl_bds_bind(cl_env_copy,VV[108],ECL_NIL); /*  *PERMANENT-OBJECTS* */
          ecl_bds_bind(cl_env_copy,VV[109],ECL_NIL); /*  *TEMPORARY-OBJECTS* */
          ecl_bds_bind(cl_env_copy,VV[110],ECL_NIL); /*  *LOCAL-FUNS* */
          ecl_bds_bind(cl_env_copy,VV[111],ECL_NIL); /*  *GLOBAL-VARS* */
          ecl_bds_bind(cl_env_copy,VV[112],ECL_NIL); /*  *GLOBAL-FUNS* */
          ecl_bds_bind(cl_env_copy,VV[113],ECL_NIL); /*  *GLOBAL-CFUNS-ARRAY* */
          ecl_bds_bind(cl_env_copy,VV[114],ECL_NIL); /*  *LINKING-CALLS* */
          ecl_bds_bind(cl_env_copy,VV[115],ECL_NIL); /*  *GLOBAL-ENTRIES* */
          ecl_bds_bind(cl_env_copy,VV[116],ECL_NIL); /*  *UNDEFINED-VARS* */
          ecl_bds_bind(cl_env_copy,VV[117],ECL_NIL); /*  *TOP-LEVEL-FORMS* */
          ecl_bds_bind(cl_env_copy,VV[118],ECL_NIL); /*  *COMPILE-TIME-TOO* */
          ecl_bds_bind(cl_env_copy,VV[119],ECL_NIL); /*  *CLINES-STRING-LIST* */
          ecl_bds_bind(cl_env_copy,VV[120],ecl_make_fixnum(0)); /*  *INLINE-BLOCKS* */
          ecl_bds_bind(cl_env_copy,VV[121],VV[95]); /*  *DEFUN-INLINE-HOOK* */
          {cl_object v18;
          v18 = ECL_NIL;
          v18 = ecl_make_cclosure_va((cl_objectfn)LC24__g143,env4,Cblock);
          T0 = v18;
          }
          cl_env_copy->values[0] = ecl_function_dispatch(cl_env_copy,VV[216])(1, T0) /*  DO-COMPILATION-UNIT */;
          ecl_bds_unwind_n(cl_env_copy,30);
          }
          }
          ecl_frs_pop(cl_env_copy);
          v15=ecl_stack_push_values(cl_env_copy);
          T0 = ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398));
          T1 = mp_lock_owner(v9);
          if (!((T0)==(T1))) { goto L81; }
          if (!((v10)==(ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398))))) { goto L84; }
          T0 = mp_lock_count(v9);
          if (!(ecl_number_compare(T0,v11)>0)) { goto L81; }
          goto L82;
L84:;
L82:;
          mp_giveup_lock(v9);
L81:;
          ecl_stack_pop_values(cl_env_copy,v15);
          if (unwinding) ecl_unwind(cl_env_copy,next_fr);
          ECL_STACK_SET_INDEX(cl_env_copy,v14);
          ecl_bds_unwind1(cl_env_copy);
          ecl_bds_unwind1(cl_env_copy);
          }
         }
         ecl_stack_frame_push_values(v12);
         if (Null(ecl_symbol_value(ECL_SYM("*INTERRUPTS-ENABLED*",1023)))) { goto L86; }
         si_check_pending_interrupts();
L86:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v12);
        }
        ecl_stack_frame_close(_ecl_inner_frame);
       }
       ecl_frs_pop(cl_env_copy);
       ecl_bds_unwind1(cl_env_copy);
       ecl_bds_unwind1(cl_env_copy);
       goto L58;
      }
L59:;
      ecl_frs_pop(cl_env_copy);
      goto L58;
     }
    }
L58:;
    v8compiler_conditions = ecl_symbol_value(VV[90]);
    ecl_bds_unwind1(cl_env_copy);
    T0 = ECL_CONS_CAR(CLV9);
    value0 = L26compiler_output_values(T0, v8compiler_conditions);
    ecl_bds_unwind_n(cl_env_copy,13);
    return value0;
   }
  }
 }
}
/*	closure G97                                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC23__g97(cl_narg narg, ...)
{
 cl_object CLV0, CLV1, CLV2, CLV3, CLV4, CLV5, CLV6, CLV7, CLV8, CLV9, CLV10, CLV11, CLV12, CLV13, CLV14, CLV15
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV15 = env0;                                    /*  TAGBODY         */
 CLV14 = _ecl_cdr(CLV15);
 CLV13 = _ecl_cdr(CLV14);
 CLV12 = _ecl_cdr(CLV13);
 CLV11 = _ecl_cdr(CLV12);
 CLV10 = _ecl_cdr(CLV11);
 CLV9 = _ecl_cdr(CLV10);
 CLV8 = _ecl_cdr(CLV9);
 CLV7 = _ecl_cdr(CLV8);
 CLV6 = _ecl_cdr(CLV7);
 CLV5 = _ecl_cdr(CLV6);
 CLV4 = _ecl_cdr(CLV5);
 CLV3 = _ecl_cdr(CLV4);
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 {
  cl_object v1si__temp;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1si__temp = cl_grab_rest_args(args);
  ecl_va_end(args);
  ECL_CONS_CAR(CLV14) = v1si__temp;
  cl_go(ECL_CONS_CAR(CLV15),ecl_make_fixnum(0));
 }
 }
}
/*	closure G143                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC24__g143(volatile cl_narg narg, ...)
{
 cl_object T0, T1;
 cl_object volatile CLV0, CLV1, CLV2, CLV3, CLV4, CLV5, CLV6, CLV7, CLV8, CLV9, CLV10, CLV11, CLV12, CLV13, CLV14, CLV15
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object volatile env0 = cl_env_copy->function->cclosure.env;
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV15 = env0;
 CLV14 = _ecl_cdr(CLV15);
 CLV13 = _ecl_cdr(CLV14);                         /*  TO-DELETE       */
 CLV12 = _ecl_cdr(CLV13);
 CLV11 = _ecl_cdr(CLV12);
 CLV10 = _ecl_cdr(CLV11);
 CLV9 = _ecl_cdr(CLV10);
 CLV8 = _ecl_cdr(CLV9);
 CLV7 = _ecl_cdr(CLV8);
 CLV6 = _ecl_cdr(CLV7);
 CLV5 = _ecl_cdr(CLV6);
 CLV4 = _ecl_cdr(CLV5);
 CLV3 = _ecl_cdr(CLV4);
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=0)) FEwrong_num_arguments_anonym();
 {
TTL:
  L37print_compiler_info();
  if (Null(cl_probe_file(_ecl_static_31))) { goto L2; }
  cl_load(3, _ecl_static_31, ECL_SYM("VERBOSE",1325), ecl_symbol_value(ECL_SYM("*COMPILE-VERBOSE*",29)));
L2:;
  ecl_function_dispatch(cl_env_copy,VV[217])(0)   /*  DATA-INIT       */;
  T0 = cl_open(3, ecl_symbol_value(ECL_SYM("*COMPILE-FILE-PATHNAME*",26)), ECL_SYM("EXTERNAL-FORMAT",1236), ECL_CONS_CAR(CLV5));
  ecl_bds_bind(cl_env_copy,VV[122],T0);           /*  *COMPILER-INPUT* */
  {
   volatile bool unwinding = FALSE;
   cl_index v1=ECL_STACK_INDEX(cl_env_copy),v2;
   ecl_frame_ptr next_fr;
   if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
     unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
   } else {
   {
    struct ecl_stack_frame _ecl_inner_frame_aux;
    volatile cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
    {
     cl_object v3;
     v3 = _ecl_inner_frame;
     if ((ECL_CONS_CAR(CLV1))!=ECL_NIL) { goto L11; }
     {
      cl_object v4;
      v4 = ecl_symbol_value(ECL_SYM("*SOURCE-LOCATION*",1180));
      {
       cl_object v5;
       v5 = ecl_symbol_value(ECL_SYM("*COMPILE-FILE-PATHNAME*",26));
       if (ecl_unlikely(ECL_ATOM(v4))) FEtype_error_cons(v4);
       T0 = v4;
       (ECL_CONS_CAR(T0)=v5,T0);
      }
     }
L11:;
     {
      cl_object v4form;
      ecl_bds_bind(cl_env_copy,VV[123],ecl_make_fixnum(0)); /*  *COMPILE-FILE-POSITION* */
      v4form = si_read_object_or_ignore(ecl_symbol_value(VV[122]), ECL_CONS_CAR(CLV7));
      goto L21;
L20:;
      if (Null(v4form)) { goto L23; }
      {
       cl_object v5;
       v5 = ecl_symbol_value(ECL_SYM("*SOURCE-LOCATION*",1180));
       {
        cl_object v6;
        v6 = ecl_plus(ECL_CONS_CAR(CLV2),ecl_symbol_value(VV[123]));
        if (ecl_unlikely(ECL_ATOM(v5))) FEtype_error_cons(v5);
        T0 = v5;
        (ECL_CONS_CDR(T0)=v6,T0);
       }
      }
      ecl_function_dispatch(cl_env_copy,VV[218])(1, v4form) /*  T1EXPR */;
L23:;
      cl_set(VV[123],cl_file_position(1, ecl_symbol_value(VV[122])));
      v4form = si_read_object_or_ignore(ecl_symbol_value(VV[122]), ECL_CONS_CAR(CLV7));
L21:;
      if ((v4form)==(ECL_CONS_CAR(CLV7))) { goto L35; }
      goto L20;
L35:;
      cl_env_copy->values[0] = ECL_NIL;
      cl_env_copy->nvalues = 1;
      ecl_bds_unwind1(cl_env_copy);
     }
     ecl_stack_frame_push_values(v3);
     if (Null(ecl_symbol_value(VV[122]))) { goto L37; }
     cl_close(1, ecl_symbol_value(VV[122]));
L37:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v3);
    }
    ecl_stack_frame_close(_ecl_inner_frame);
   }
   }
   ecl_frs_pop(cl_env_copy);
   v2=ecl_stack_push_values(cl_env_copy);
   if (Null(ecl_symbol_value(VV[122]))) { goto L39; }
   cl_close(3, ecl_symbol_value(VV[122]), ECL_SYM("ABORT",1195), ECL_T);
L39:;
   ecl_stack_pop_values(cl_env_copy,v2);
   if (unwinding) ecl_unwind(cl_env_copy,next_fr);
   ECL_STACK_SET_INDEX(cl_env_copy,v1);
   ecl_bds_unwind1(cl_env_copy);
  }
  ecl_function_dispatch(cl_env_copy,VV[169])(1, _ecl_static_32) /*  CMPPROGRESS */;
  if (Null(ECL_CONS_CAR(CLV3))) { goto L45; }
  T0 = ECL_SYM("OBJECT",1278);
  goto L44;
L45:;
  T0 = VV[1];
L44:;
  ECL_CONS_CAR(CLV6) = ecl_function_dispatch(cl_env_copy,VV[191])(3, ECL_CONS_CAR(CLV8), VV[77], T0) /*  COMPUTE-INIT-NAME */;
  T0 = ECL_CONS_CAR(CLV6);
  T1 = cl_namestring(ECL_CONS_CAR(CLV0));
  L33compiler_pass2(6, ECL_CONS_CAR(CLV10), ECL_CONS_CAR(CLV11), ECL_CONS_CAR(CLV12), T0, VV[124], T1);
  ecl_function_dispatch(cl_env_copy,VV[219])(1, ECL_CONS_CAR(CLV12)) /*  DATA-C-DUMP */;
  {
   cl_object v1o_pathname;
   if (Null(ECL_CONS_CAR(CLV3))) { goto L51; }
   v1o_pathname = ECL_CONS_CAR(CLV8);
   goto L50;
L51:;
   v1o_pathname = L2compile_file_pathname(3, ECL_CONS_CAR(CLV8), ECL_SYM("TYPE",1318), ECL_SYM("OBJECT",1278));
L50:;
   ecl_function_dispatch(cl_env_copy,VV[144])(2, ECL_CONS_CAR(CLV10), v1o_pathname) /*  COMPILER-CC */;
   ecl_function_dispatch(cl_env_copy,VV[194])(1, v1o_pathname) /*  DATA-BINARY-DUMP */;
  }
  ECL_CONS_CAR(CLV9) = cl_probe_file(ECL_CONS_CAR(CLV8));
  if (Null(ECL_CONS_CAR(CLV9))) { goto L55; }
  T0 = cl_namestring(ECL_CONS_CAR(CLV0));
  ecl_function_dispatch(cl_env_copy,VV[169])(2, _ecl_static_33, T0) /*  CMPPROGRESS */;
  goto L54;
L55:;
  ecl_function_dispatch(cl_env_copy,VV[220])(1, _ecl_static_34) /*  CMPERR */;
L54:;
  {
   cl_object v1;
   cl_object v2;
   v1 = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(ECL_CONS_CAR(CLV13)))) FEtype_error_list(ECL_CONS_CAR(CLV13));
   v2 = ECL_CONS_CAR(CLV13);
L62:;
   if (!(ecl_endp(v2))) { goto L64; }
   goto L63;
L64:;
   v1 = _ecl_car(v2);
   {
    cl_object v3;
    v3 = _ecl_cdr(v2);
    if (ecl_unlikely(!ECL_LISTP(v3))) FEtype_error_list(v3);
    v2 = v3;
   }
   L3cmp_delete_file(v1);
   goto L62;
L63:;
   goto L58;
  }
L58:;
  if (Null(ECL_CONS_CAR(CLV4))) { goto L75; }
  if (Null(ECL_CONS_CAR(CLV9))) { goto L75; }
  if ((ECL_CONS_CAR(CLV3))!=ECL_NIL) { goto L75; }
  T0 = ECL_CONS_CAR(CLV9);
  value0 = cl_load(3, T0, ECL_SYM("VERBOSE",1325), ecl_symbol_value(ECL_SYM("*COMPILE-VERBOSE*",29)));
  return value0;
L75:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
 }
}
/*	function definition for COMPILER-OUTPUT-VALUES                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L26compiler_output_values(cl_object v1main_value, cl_object v2conditions)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3i;
   cl_object v4;
   v3i = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v2conditions))) FEtype_error_list(v2conditions);
   v4 = v2conditions;
   {
    cl_object v5warning_p;
    v5warning_p = ECL_NIL;
    {
     cl_object v6failure_p;
     v6failure_p = ECL_NIL;
L6:;
     if (!(ecl_endp(v4))) { goto L8; }
     goto L7;
L8:;
     v3i = _ecl_car(v4);
     {
      cl_object v7;
      v7 = _ecl_cdr(v4);
      if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
      v4 = v7;
     }
     if (Null(si_of_class_p(2, v3i, ECL_SYM("STYLE-WARNING",827)))) { goto L17; }
     v5warning_p = ECL_T;
     goto L16;
L17:;
     if ((si_of_class_p(2, v3i, VV[91]))!=ECL_NIL) { goto L21; }
     if (Null(si_of_class_p(2, v3i, ECL_SYM("WARNING",904)))) { goto L16; }
     goto L20;
L21:;
L20:;
     v5warning_p = ECL_T;
     v6failure_p = ECL_T;
L16:;
     goto L6;
L7:;
     cl_env_copy->nvalues = 3;
     cl_env_copy->values[2] = v6failure_p;
     cl_env_copy->values[1] = v5warning_p;
     cl_env_copy->values[0] = v1main_value;
     return cl_env_copy->values[0];
    }
   }
  }
 }
}
/*	function definition for COMPILE                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L27compile(cl_narg narg, cl_object v1name, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2def;
  cl_object v3supplied_p;
  va_list args; va_start(args,v1name);
  {
   int i = 1;
   if (i >= narg) {
    v2def = ECL_NIL;
    v3supplied_p = ECL_NIL;
   } else {
    i++;
    v2def = va_arg(args,cl_object);
    v3supplied_p = ECL_T;
   }
  }
  va_end(args);
  value0 = cl_format(2, ECL_T, _ecl_static_35);
  return value0;
 }
}
/*	function definition for DISASSEMBLE                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L32disassemble(volatile cl_narg narg, cl_object volatile v1thing, ...)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11;
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1, CLV2, CLV3, CLV4, CLV5
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  ecl_va_list args; ecl_va_start(args,v1thing,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L32disassemblekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   env0 = ECL_NIL;
   CLV0 = env0 = CONS(keyvars[0],env0);           /*  H-FILE          */
   CLV1 = env0 = CONS(keyvars[1],env0);           /*  DATA-FILE       */
  }
  {
   volatile cl_object env1 = env0;
   CLV2 = env1 = CONS(ECL_NIL,env1);              /*  DISASSEMBLED-FORM */
   ecl_bds_push(cl_env_copy,VV[86]);              /*  *COMPILER-IN-USE* */
   ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-PRETTY*",55),ECL_NIL); /*  *PRINT-PRETTY* */
   if (Null(si_valid_function_name_p(v1thing))) { goto L1; }
   v1thing = cl_fdefinition(v1thing);
L1:;
   {
    cl_object v2;
    v2 = ecl_make_bool(v1thing==ECL_NIL);
    if (Null(v2)) { goto L6; }
    goto L4;
L6:;
    if (Null(cl_functionp(v1thing))) { goto L8; }
    if ((si_bc_disassemble(v1thing))!=ECL_NIL) { goto L4; }
    (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(2, _ecl_static_36, v1thing) /*  WARN */;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    ecl_bds_unwind1(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    return value0;
L8:;
    if (!(ECL_ATOM(v1thing))) { goto L12; }
    T0 = ecl_list1(v1thing);
    cl_error(9, ECL_SYM("SIMPLE-TYPE-ERROR",773), ECL_SYM("DATUM",1214), v1thing, ECL_SYM("EXPECTED-TYPE",1232), VV[128], ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_37, ECL_SYM("FORMAT-ARGUMENTS",1239), T0);
    goto L4;
L12:;
    T0 = ecl_car(v1thing);
    if (!((T0)==(ECL_SYM("LAMBDA",452)))) { goto L14; }
    T0 = ecl_cdr(v1thing);
    ECL_CONS_CAR(CLV2) = cl_listX(3, ECL_SYM("DEFUN",289), VV[129], T0);
    goto L4;
L14:;
    T0 = ecl_car(v1thing);
    if (!((T0)==(ECL_SYM("LAMBDA-BLOCK",1339)))) { goto L17; }
    T0 = ecl_cdr(v1thing);
    ECL_CONS_CAR(CLV2) = CONS(ECL_SYM("DEFUN",289),T0);
    goto L4;
L17:;
    T0 = ecl_list1(v1thing);
    cl_error(9, ECL_SYM("SIMPLE-TYPE-ERROR",773), ECL_SYM("DATUM",1214), v1thing, ECL_SYM("EXPECTED-TYPE",1232), VV[128], ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_37, ECL_SYM("FORMAT-ARGUMENTS",1239), T0);
   }
L4:;
   {
    volatile cl_object v2null_stream;
    volatile cl_object v3compiler_conditions;
    volatile cl_object env2 = env1;
    v2null_stream = cl_make_broadcast_stream(0);
    ecl_bds_bind(cl_env_copy,VV[130],v2null_stream); /*  *COMPILER-OUTPUT1* */
    if (Null(ECL_CONS_CAR(CLV0))) { goto L23; }
    T0 = cl_open(5, ECL_CONS_CAR(CLV0), ECL_SYM("DIRECTION",1218), ECL_SYM("OUTPUT",1282), ECL_SYM("EXTERNAL-FORMAT",1236), ECL_SYM("DEFAULT",1215));
    goto L22;
L23:;
    T0 = v2null_stream;
L22:;
    ecl_bds_bind(cl_env_copy,VV[131],T0);         /*  *COMPILER-OUTPUT2* */
    T0 = cl_symbol_function(VV[132]);
    CLV3 = env2 = CONS(T0,env2);                  /*  T3LOCAL-FUN     */
    v3compiler_conditions = ECL_NIL;
    ecl_bds_bind(cl_env_copy,VV[90],ECL_NIL);     /*  *COMPILER-CONDITIONS* */
    {
     volatile cl_object env3 = env2;
     CLV4 = env3 = CONS(ECL_NIL,env3);
     {
      volatile cl_object env4 = env3;
      CLV5 = env4 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env4); /*  TAGBODY */
      if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV5))) {
      if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L27;
      ecl_internal_error("GO found an inexistent tag");
      }
      {cl_object v4;
       v4 = ECL_NIL;
       v4 = ecl_make_cclosure_va((cl_objectfn)LC28__g172,env4,Cblock);
       T0 = v4;
      }
      T1 = ecl_function_dispatch(cl_env_copy,VV[211])(4, ECL_SYM("NAME",1273), ECL_SYM("ABORT",77), ECL_SYM("FUNCTION",1241), T0) /*  MAKE-RESTART */;
      T2 = ecl_list1(T1);
      T3 = CONS(T2,ecl_symbol_value(ECL_SYM("*RESTART-CLUSTERS*",4)));
      ecl_bds_bind(cl_env_copy,ECL_SYM("*RESTART-CLUSTERS*",4),T3); /*  *RESTART-CLUSTERS* */
      T0 = ecl_fdefinition(VV[212]);
      T1 = CONS(VV[70],T0);
      T2 = ecl_fdefinition(VV[213]);
      T3 = CONS(ECL_SYM("WARNING",904),T2);
      T4 = ecl_fdefinition(VV[214]);
      T5 = CONS(VV[91],T4);
      T6 = ecl_fdefinition(VV[215]);
      T7 = CONS(VV[92],T6);
      T8 = ecl_fdefinition(VV[215]);
      T9 = CONS(ECL_SYM("SERIOUS-CONDITION",742),T8);
      T10 = cl_list(5, T1, T3, T5, T7, T9);
      T11 = CONS(T10,ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5)));
      ecl_bds_bind(cl_env_copy,ECL_SYM("*HANDLER-CLUSTERS*",5),T11); /*  *HANDLER-CLUSTERS* */
      {
       volatile cl_object v4;
       volatile cl_object v5;
       volatile cl_object v6;
       v4 = ecl_symbol_value(ECL_SYM("+LOAD-COMPILE-LOCK+",1426));
       v5 = mp_lock_owner(v4);
       v6 = mp_lock_count(v4);
       {
        struct ecl_stack_frame _ecl_inner_frame_aux;
        volatile cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
        {
         volatile cl_object v7;
         v7 = _ecl_inner_frame;
         {
          volatile cl_object v8;
          v8 = ecl_symbol_value(ECL_SYM("*INTERRUPTS-ENABLED*",1023));
          ecl_bds_bind(cl_env_copy,ECL_SYM("*INTERRUPTS-ENABLED*",1023),ECL_NIL); /*  *INTERRUPTS-ENABLED* */
          ecl_bds_bind(cl_env_copy,ECL_SYM("*ALLOW-WITH-INTERRUPTS*",1730),ECL_NIL); /*  *ALLOW-WITH-INTERRUPTS* */
          {
          volatile bool unwinding = FALSE;
          cl_index v9=ECL_STACK_INDEX(cl_env_copy),v10;
          ecl_frame_ptr next_fr;
          if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
            unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
          } else {
          ecl_bds_bind(cl_env_copy,ECL_SYM("*INTERRUPTS-ENABLED*",1023),v8); /*  *INTERRUPTS-ENABLED* */
          mp_get_lock(1, v4);
          {
          volatile cl_object v11;
          volatile cl_object v12;
          v11 = cl_copy_tree(ecl_symbol_value(VV[94]));
          T0 = (ECL_SYM("EQUAL",335)->symbol.gfdef);
          v12 = cl_make_hash_table(4, ECL_SYM("SIZE",1308), ecl_make_fixnum(128), ECL_SYM("TEST",1316), T0);
          ecl_bds_bind(cl_env_copy,ECL_SYM("*GENSYM-COUNTER*",35),ecl_make_fixnum(0)); /*  *GENSYM-COUNTER* */
          ecl_bds_bind(cl_env_copy,VV[86],ECL_T); /*  *COMPILER-IN-USE* */
          ecl_bds_bind(cl_env_copy,VV[96],VV[93]); /*  *COMPILER-PHASE* */
          ecl_bds_bind(cl_env_copy,VV[97],ECL_NIL); /*  *CALLBACKS*   */
          ecl_bds_bind(cl_env_copy,VV[94],v11);   /*  *CMP-ENV-ROOT*  */
          ecl_bds_bind(cl_env_copy,VV[98],ECL_NIL); /*  *CMP-ENV*     */
          ecl_bds_bind(cl_env_copy,VV[99],ecl_make_fixnum(0)); /*  *MAX-TEMP* */
          ecl_bds_bind(cl_env_copy,VV[100],ecl_make_fixnum(0)); /*  *TEMP* */
          ecl_bds_bind(cl_env_copy,VV[101],ecl_make_fixnum(0)); /*  *NEXT-CMACRO* */
          ecl_bds_bind(cl_env_copy,VV[102],ecl_make_fixnum(0)); /*  *NEXT-CFUN* */
          ecl_bds_bind(cl_env_copy,VV[103],ecl_make_fixnum(0)); /*  *LAST-LABEL* */
          ecl_bds_bind(cl_env_copy,VV[104],v12);  /*  *LOAD-OBJECTS*  */
          ecl_bds_bind(cl_env_copy,VV[105],ECL_NIL); /*  *SETF-DEFINITIONS* */
          ecl_bds_bind(cl_env_copy,VV[106],ECL_NIL); /*  *MAKE-FORMS* */
          ecl_bds_bind(cl_env_copy,VV[107],ECL_NIL); /*  *STATIC-CONSTANTS* */
          ecl_bds_bind(cl_env_copy,VV[108],ECL_NIL); /*  *PERMANENT-OBJECTS* */
          ecl_bds_bind(cl_env_copy,VV[109],ECL_NIL); /*  *TEMPORARY-OBJECTS* */
          ecl_bds_bind(cl_env_copy,VV[110],ECL_NIL); /*  *LOCAL-FUNS* */
          ecl_bds_bind(cl_env_copy,VV[111],ECL_NIL); /*  *GLOBAL-VARS* */
          ecl_bds_bind(cl_env_copy,VV[112],ECL_NIL); /*  *GLOBAL-FUNS* */
          ecl_bds_bind(cl_env_copy,VV[113],ECL_NIL); /*  *GLOBAL-CFUNS-ARRAY* */
          ecl_bds_bind(cl_env_copy,VV[114],ECL_NIL); /*  *LINKING-CALLS* */
          ecl_bds_bind(cl_env_copy,VV[115],ECL_NIL); /*  *GLOBAL-ENTRIES* */
          ecl_bds_bind(cl_env_copy,VV[116],ECL_NIL); /*  *UNDEFINED-VARS* */
          ecl_bds_bind(cl_env_copy,VV[117],ECL_NIL); /*  *TOP-LEVEL-FORMS* */
          ecl_bds_bind(cl_env_copy,VV[118],ECL_NIL); /*  *COMPILE-TIME-TOO* */
          ecl_bds_bind(cl_env_copy,VV[119],ECL_NIL); /*  *CLINES-STRING-LIST* */
          ecl_bds_bind(cl_env_copy,VV[120],ecl_make_fixnum(0)); /*  *INLINE-BLOCKS* */
          ecl_bds_bind(cl_env_copy,VV[121],VV[95]); /*  *DEFUN-INLINE-HOOK* */
          {cl_object v13;
          v13 = ECL_NIL;
          v13 = ecl_make_cclosure_va((cl_objectfn)LC31__g218,env4,Cblock);
          T0 = v13;
          }
          cl_env_copy->values[0] = ecl_function_dispatch(cl_env_copy,VV[216])(1, T0) /*  DO-COMPILATION-UNIT */;
          ecl_bds_unwind_n(cl_env_copy,30);
          }
          }
          ecl_frs_pop(cl_env_copy);
          v10=ecl_stack_push_values(cl_env_copy);
          T0 = ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398));
          T1 = mp_lock_owner(v4);
          if (!((T0)==(T1))) { goto L49; }
          if (!((v5)==(ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398))))) { goto L52; }
          T0 = mp_lock_count(v4);
          if (!(ecl_number_compare(T0,v6)>0)) { goto L49; }
          goto L50;
L52:;
L50:;
          mp_giveup_lock(v4);
L49:;
          ecl_stack_pop_values(cl_env_copy,v10);
          if (unwinding) ecl_unwind(cl_env_copy,next_fr);
          ECL_STACK_SET_INDEX(cl_env_copy,v9);
          ecl_bds_unwind1(cl_env_copy);
          ecl_bds_unwind1(cl_env_copy);
          }
         }
         ecl_stack_frame_push_values(v7);
         if (Null(ecl_symbol_value(ECL_SYM("*INTERRUPTS-ENABLED*",1023)))) { goto L54; }
         si_check_pending_interrupts();
L54:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v7);
        }
        ecl_stack_frame_close(_ecl_inner_frame);
       }
       ecl_frs_pop(cl_env_copy);
       ecl_bds_unwind1(cl_env_copy);
       ecl_bds_unwind1(cl_env_copy);
       goto L26;
      }
L27:;
      ecl_frs_pop(cl_env_copy);
      goto L26;
     }
    }
L26:;
    v3compiler_conditions = ecl_symbol_value(VV[90]);
    ecl_bds_unwind1(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
   }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   ecl_bds_unwind1(cl_env_copy);
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
 }
}
/*	closure G172                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC28__g172(cl_narg narg, ...)
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
  cl_object v1si__temp;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1si__temp = cl_grab_rest_args(args);
  ecl_va_end(args);
  ECL_CONS_CAR(CLV4) = v1si__temp;
  cl_go(ECL_CONS_CAR(CLV5),ecl_make_fixnum(0));
 }
 }
}
/*	closure G218                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC31__g218(volatile cl_narg narg, ...)
{
 cl_object T0, T1, T2;
 cl_object volatile CLV0, CLV1, CLV2, CLV3, CLV4, CLV5
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object volatile env0 = cl_env_copy->function->cclosure.env;
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV5 = env0;
 CLV4 = _ecl_cdr(CLV5);
 CLV3 = _ecl_cdr(CLV4);                           /*  T3LOCAL-FUN     */
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=0)) FEwrong_num_arguments_anonym();
 {
TTL:
  {
   volatile bool unwinding = FALSE;
   cl_index v1=ECL_STACK_INDEX(cl_env_copy),v2;
   ecl_frame_ptr next_fr;
   if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
     unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
   } else {
   {cl_object v3;
    v3 = ECL_NIL;
    v3 = ecl_make_cclosure_va((cl_objectfn)LC30__g222,env0,Cblock);
    T0 = v3;
   }
   si_fset(4, VV[132], T0, ECL_NIL, ECL_NIL);
   ecl_function_dispatch(cl_env_copy,VV[217])(0)  /*  DATA-INIT       */;
   ecl_function_dispatch(cl_env_copy,VV[218])(1, ECL_CONS_CAR(CLV2)) /*  T1EXPR */;
   T0 = ecl_function_dispatch(cl_env_copy,VV[191])(3, _ecl_static_38, VV[77], VV[1]) /*  COMPUTE-INIT-NAME */;
   if (Null(ECL_CONS_CAR(CLV0))) { goto L8; }
   T1 = ECL_CONS_CAR(CLV0);
   goto L7;
L8:;
   T1 = _ecl_static_2;
L7:;
   if (Null(ECL_CONS_CAR(CLV1))) { goto L11; }
   T2 = ECL_CONS_CAR(CLV1);
   goto L10;
L11:;
   T2 = _ecl_static_2;
L10:;
   ecl_function_dispatch(cl_env_copy,VV[224])(3, T0, T1, T2) /*  CTOP-WRITE */;
   if (Null(ECL_CONS_CAR(CLV1))) { goto L13; }
   cl_env_copy->values[0] = ecl_function_dispatch(cl_env_copy,VV[219])(1, ECL_CONS_CAR(CLV1)) /*  DATA-C-DUMP */;
   goto L1;
L13:;
   cl_env_copy->values[0] = ECL_NIL;
   cl_env_copy->nvalues = 1;
L1:;
   }
   ecl_frs_pop(cl_env_copy);
   v2=ecl_stack_push_values(cl_env_copy);
   si_fset(4, VV[132], ECL_CONS_CAR(CLV3), ECL_NIL, ECL_NIL);
   if (Null(ECL_CONS_CAR(CLV0))) { goto L15; }
   cl_close(1, ecl_symbol_value(VV[131]));
L15:;
   ecl_stack_pop_values(cl_env_copy,v2);
   if (unwinding) ecl_unwind(cl_env_copy,next_fr);
   ECL_STACK_SET_INDEX(cl_env_copy,v1);
   return cl_env_copy->values[0];
  }
 }
 }
}
/*	closure G222                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC30__g222(cl_narg narg, ...)
{
 cl_object CLV0, CLV1, CLV2, CLV3, CLV4, CLV5
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV5 = env0;
 CLV4 = _ecl_cdr(CLV5);
 CLV3 = _ecl_cdr(CLV4);                           /*  T3LOCAL-FUN     */
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 {
  cl_object v1args;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1args = cl_grab_rest_args(args);
  ecl_va_end(args);
  ecl_bds_bind(cl_env_copy,VV[130],ecl_symbol_value(ECL_SYM("*STANDARD-OUTPUT*",67))); /*  *COMPILER-OUTPUT1* */
  value0 = cl_apply(2, ECL_CONS_CAR(CLV3), v1args);
  ecl_bds_unwind1(cl_env_copy);
  return value0;
 }
 }
}
/*	function definition for COMPILER-PASS2                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L33compiler_pass2(volatile cl_narg narg, cl_object volatile v1c_pathname, cl_object volatile v2h_pathname, cl_object volatile v3data_pathname, cl_object volatile v4init_name, ...)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<4)) FEwrong_num_arguments_anonym();
 {
  volatile cl_object v5input_designator;
  ecl_va_list args; ecl_va_start(args,v4init_name,narg,4);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L33compiler_pass2keys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v5input_designator = keyvars[0];
  }
  T0 = cl_open(7, v1c_pathname, ECL_SYM("DIRECTION",1218), ECL_SYM("OUTPUT",1282), ECL_SYM("IF-DOES-NOT-EXIST",1244), ECL_SYM("CREATE",1213), ECL_SYM("IF-EXISTS",1245), ECL_SYM("SUPERSEDE",1314));
  ecl_bds_bind(cl_env_copy,VV[130],T0);           /*  *COMPILER-OUTPUT1* */
  {
   volatile bool unwinding = FALSE;
   cl_index v6=ECL_STACK_INDEX(cl_env_copy),v7;
   ecl_frame_ptr next_fr;
   if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
     unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
   } else {
   {
    struct ecl_stack_frame _ecl_inner_frame_aux;
    volatile cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
    {
     volatile cl_object v8;
     v8 = _ecl_inner_frame;
     T0 = (cl_env_copy->function=(ECL_SYM("LISP-IMPLEMENTATION-TYPE",479)->symbol.gfdef))->cfun.entry(0) /*  LISP-IMPLEMENTATION-TYPE */;
     T1 = (cl_env_copy->function=(ECL_SYM("LISP-IMPLEMENTATION-VERSION",480)->symbol.gfdef))->cfun.entry(0) /*  LISP-IMPLEMENTATION-VERSION */;
     ecl_function_dispatch(cl_env_copy,VV[226])(3, _ecl_static_39, T0, T1) /*  WT-COMMENT-NL */;
     {
      volatile cl_object v10;                     /*  MINUTE          */
      volatile cl_object v11;                     /*  HOUR            */
      volatile cl_object v12;                     /*  DAY             */
      volatile cl_object v13;                     /*  MONTH           */
      volatile cl_object v14;                     /*  YEAR            */
      value0 = cl_get_decoded_time();
      v10 = cl_env_copy->values[1];
      v11 = cl_env_copy->values[2];
      v12 = cl_env_copy->values[3];
      v13 = cl_env_copy->values[4];
      v14 = cl_env_copy->values[5];
      ecl_function_dispatch(cl_env_copy,VV[226])(6, _ecl_static_40, v14, v13, v12, v11, v10) /*  WT-COMMENT-NL */;
      T0 = (cl_env_copy->function=(ECL_SYM("SOFTWARE-TYPE",784)->symbol.gfdef))->cfun.entry(0) /*  SOFTWARE-TYPE */;
      T1 = (cl_env_copy->function=(ECL_SYM("SOFTWARE-VERSION",785)->symbol.gfdef))->cfun.entry(0) /*  SOFTWARE-VERSION */;
      T2 = (cl_env_copy->function=(ECL_SYM("MACHINE-TYPE",516)->symbol.gfdef))->cfun.entry(0) /*  MACHINE-TYPE */;
      ecl_function_dispatch(cl_env_copy,VV[226])(4, _ecl_static_41, T0, T1, T2) /*  WT-COMMENT-NL */;
     }
     ecl_function_dispatch(cl_env_copy,VV[226])(2, _ecl_static_42, v5input_designator) /*  WT-COMMENT-NL */;
     T0 = cl_open(7, v2h_pathname, ECL_SYM("DIRECTION",1218), ECL_SYM("OUTPUT",1282), ECL_SYM("IF-DOES-NOT-EXIST",1244), ECL_SYM("CREATE",1213), ECL_SYM("IF-EXISTS",1245), ECL_SYM("SUPERSEDE",1314));
     ecl_bds_bind(cl_env_copy,VV[131],T0);        /*  *COMPILER-OUTPUT2* */
     {
      volatile bool unwinding = FALSE;
      cl_index v9=ECL_STACK_INDEX(cl_env_copy),v10;
      ecl_frame_ptr next_fr;
      if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
        unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
      } else {
      {
       struct ecl_stack_frame _ecl_inner_frame_aux;
       volatile cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
       {
        cl_object v11;
        v11 = _ecl_inner_frame;
        ecl_function_dispatch(cl_env_copy,VV[227])(2, _ecl_static_43, ecl_symbol_value(VV[134])) /*  WT-NL1 */;
        ecl_function_dispatch(cl_env_copy,VV[224])(3, v4init_name, v2h_pathname, v3data_pathname) /*  CTOP-WRITE */;
        ecl_terpri(ecl_symbol_value(VV[130]));
        cl_env_copy->values[0] = ecl_terpri(ecl_symbol_value(VV[131]));
        cl_env_copy->nvalues = 1;
        ecl_stack_frame_push_values(v11);
        if (Null(ecl_symbol_value(VV[131]))) { goto L19; }
        cl_close(1, ecl_symbol_value(VV[131]));
L19:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v11);
       }
       ecl_stack_frame_close(_ecl_inner_frame);
      }
      }
      ecl_frs_pop(cl_env_copy);
      v10=ecl_stack_push_values(cl_env_copy);
      if (Null(ecl_symbol_value(VV[131]))) { goto L21; }
      cl_close(3, ecl_symbol_value(VV[131]), ECL_SYM("ABORT",1195), ECL_T);
L21:;
      ecl_stack_pop_values(cl_env_copy,v10);
      if (unwinding) ecl_unwind(cl_env_copy,next_fr);
      ECL_STACK_SET_INDEX(cl_env_copy,v9);
      ecl_bds_unwind1(cl_env_copy);
     }
     ecl_stack_frame_push_values(v8);
     if (Null(ecl_symbol_value(VV[130]))) { goto L23; }
     cl_close(1, ecl_symbol_value(VV[130]));
L23:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v8);
    }
    ecl_stack_frame_close(_ecl_inner_frame);
   }
   }
   ecl_frs_pop(cl_env_copy);
   v7=ecl_stack_push_values(cl_env_copy);
   if (Null(ecl_symbol_value(VV[130]))) { goto L25; }
   cl_close(3, ecl_symbol_value(VV[130]), ECL_SYM("ABORT",1195), ECL_T);
L25:;
   ecl_stack_pop_values(cl_env_copy,v7);
   if (unwinding) ecl_unwind(cl_env_copy,next_fr);
   ECL_STACK_SET_INDEX(cl_env_copy,v6);
   ecl_bds_unwind1(cl_env_copy);
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for ECL-INCLUDE-DIRECTORY                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L34ecl_include_directory()
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_symbol_value(VV[136]))) { goto L1; }
  T0 = cl_merge_pathnames(2, _ecl_static_44, ecl_symbol_value(VV[136]));
  if (Null(cl_probe_file(T0))) { goto L1; }
  value0 = ecl_symbol_value(VV[136]);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (Null(cl_probe_file(_ecl_static_45))) { goto L4; }
  T0 = cl_translate_logical_pathname(1, _ecl_static_21);
  cl_set(VV[136],cl_namestring(T0));
  value0 = ecl_symbol_value(VV[136]);
  cl_env_copy->nvalues = 1;
  return value0;
L4:;
  {
   cl_object v1;
   v1 = cl_error(1, _ecl_static_46);
   if (Null(v1)) { goto L8; }
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
L8:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for ECL-LIBRARY-DIRECTORY                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L35ecl_library_directory()
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_symbol_value(VV[138]))) { goto L1; }
  T0 = L2compile_file_pathname(3, _ecl_static_47, ECL_SYM("TYPE",1318), VV[7]);
  T1 = cl_merge_pathnames(2, T0, ecl_symbol_value(VV[138]));
  if (Null(cl_probe_file(T1))) { goto L1; }
  value0 = ecl_symbol_value(VV[138]);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (Null(cl_probe_file(_ecl_static_48))) { goto L4; }
  T0 = cl_translate_logical_pathname(1, _ecl_static_21);
  cl_set(VV[138],cl_namestring(T0));
  value0 = ecl_symbol_value(VV[138]);
  cl_env_copy->nvalues = 1;
  return value0;
L4:;
  {
   cl_object v1;
   v1 = cl_error(1, _ecl_static_49);
   if (Null(v1)) { goto L8; }
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
L8:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for COMPILER-CC                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L36compiler_cc(cl_object v1c_pathname, cl_object v2o_pathname)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_symbol_value(VV[140]);
  T1 = L34ecl_include_directory();
  T2 = cl_concatenate(3, ECL_SYM("STRING",805), _ecl_static_51, T1);
  T3 = ecl_function_dispatch(cl_env_copy,VV[172])(1, ecl_symbol_value(VV[141])) /*  SPLIT-PROGRAM-OPTIONS */;
  T5 = ecl_function_dispatch(cl_env_copy,VV[231])(1, ECL_SYM("SPEED",791)) /*  CMP-ENV-OPTIMIZATION */;
  if (!(ecl_number_compare(T5,ecl_make_fixnum(2))>=0)) { goto L3; }
  T4 = ecl_function_dispatch(cl_env_copy,VV[172])(1, ecl_symbol_value(VV[142])) /*  SPLIT-PROGRAM-OPTIONS */;
  goto L1;
L3:;
  T4 = ECL_NIL;
  goto L1;
L1:;
  T5 = ecl_function_dispatch(cl_env_copy,VV[175])(1, v1c_pathname) /*  BRIEF-NAMESTRING */;
  T6 = ecl_function_dispatch(cl_env_copy,VV[175])(1, v2o_pathname) /*  BRIEF-NAMESTRING */;
  T7 = cl_list(2, _ecl_static_12, T6);
  T8 = ecl_function_dispatch(cl_env_copy,VV[172])(1, ecl_symbol_value(VV[143])) /*  SPLIT-PROGRAM-OPTIONS */;
  T9 = ecl_append(T7,T8);
  T10 = cl_listX(4, _ecl_static_52, _ecl_static_53, T5, T9);
  T11 = cl_append(3, T3, T4, T10);
  T12 = cl_listX(3, _ecl_static_50, T2, T11);
  value0 = ecl_function_dispatch(cl_env_copy,VV[176])(2, T0, T12) /*  SAFE-RUN-PROGRAM */;
  return value0;
 }
}
/*	function definition for PRINT-COMPILER-INFO                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L37print_compiler_info()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[169])(5, _ecl_static_54, ecl_symbol_value(VV[145]), ecl_symbol_value(VV[146]), ecl_symbol_value(VV[147]), ecl_symbol_value(VV[148])) /*  CMPPROGRESS */;
  return value0;
 }
}
/*	local function WITH-COMPILATION-UNIT                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC38with_compilation_unit(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4options;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4options = v5;
   }
   value0 = CONS(ECL_SYM("PROGN",671),v3);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for INSTALL-C-COMPILER                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L40install_c_compiler(cl_narg narg, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  DISASSEMBLE     */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=0)) FEwrong_num_arguments_anonym();
 {
TTL:
  T0 = cl_find_package(VV[152]);
  si_package_lock(T0, ECL_NIL);
  cl_set(ECL_SYM("*FEATURES*",34),cl_delete(2, VV[151], ecl_symbol_value(ECL_SYM("*FEATURES*",34))));
  si_fset(4, VV[133], ECL_CONS_CAR(CLV1), ECL_NIL, ECL_NIL);
  si_fset(4, VV[127], ECL_CONS_CAR(CLV0), ECL_NIL, ECL_NIL);
  T0 = (VV[125]->symbol.gfdef);
  si_fset(4, VV[125], T0, ECL_NIL, ECL_NIL);
  T0 = (VV[26]->symbol.gfdef);
  si_fset(4, VV[26], T0, ECL_NIL, ECL_NIL);
  T0 = cl_find_package(VV[152]);
  value0 = si_package_lock(T0, ECL_T);
  return value0;
 }
 }
}

#include "cmp/cmpmain.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclIeaWmFmPMfph9_gGstVE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPMAIN.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclIeaWmFmPMfph9_gGstVE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_package_lock(_ecl_static_0, ECL_NIL);
 si_select_package(_ecl_static_1);
 ecl_cmp_defun(VV[154]);                          /*  SAFE-MKSTEMP    */
 ecl_cmp_defun(VV[155]);                          /*  COMPILE-FILE-PATHNAME */
 ecl_cmp_defun(VV[168]);                          /*  CMP-DELETE-FILE */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC4__g22,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 cl_set(ECL_SYM("*EXIT-HOOKS*",1472),CONS(T0,ecl_symbol_value(ECL_SYM("*EXIT-HOOKS*",1472))));
 }
 ecl_cmp_defmacro(VV[170]);                       /*  FIX-FOR-MINGW   */
 ecl_cmp_defun(VV[171]);                          /*  LINKER-CC       */
 ecl_cmp_defun(VV[177]);                          /*  LINKER-AR       */
 ecl_cmp_defun(VV[178]);                          /*  STATIC-LIB-AR   */
 si_Xmake_constant(VV[41], _ecl_static_15);
 si_Xmake_constant(VV[42], _ecl_static_16);
 si_Xmake_constant(VV[43], _ecl_static_17);
 si_Xmake_constant(VV[44], _ecl_static_18);
 ecl_cmp_defun(VV[179]);                          /*  GUESS-KIND      */
 ecl_cmp_defun(VV[180]);                          /*  GUESS-LD-FLAGS  */
 ecl_cmp_defun(VV[181]);                          /*  SYSTEM-LD-FLAG  */
 ecl_cmp_defun(VV[182]);                          /*  BUILDER         */
 ecl_cmp_defun(VV[195]);                          /*  BUILD-FASL      */
 ecl_cmp_defun(VV[196]);                          /*  BUILD-PROGRAM   */
 ecl_cmp_defun(VV[197]);                          /*  BUILD-STATIC-LIBRARY */
 ecl_cmp_defun(VV[198]);                          /*  BUILD-SHARED-LIBRARY */
 ecl_cmp_defun(VV[199]);                          /*  COMPILE-FILE    */
 ecl_cmp_defun(VV[221]);                          /*  COMPILER-OUTPUT-VALUES */
 ecl_cmp_defun(VV[222]);                          /*  COMPILE         */
 ecl_cmp_defun(VV[223]);                          /*  DISASSEMBLE     */
 ecl_cmp_defun(VV[225]);                          /*  COMPILER-PASS2  */
 ecl_cmp_defun(VV[228]);                          /*  ECL-INCLUDE-DIRECTORY */
 ecl_cmp_defun(VV[229]);                          /*  ECL-LIBRARY-DIRECTORY */
 ecl_cmp_defun(VV[230]);                          /*  COMPILER-CC     */
 ecl_cmp_defun(VV[232]);                          /*  PRINT-COMPILER-INFO */
 ecl_cmp_defmacro(VV[233]);                       /*  WITH-COMPILATION-UNIT */
 si_package_lock(_ecl_static_0, ECL_T);
 cl_set(ECL_SYM("*FEATURES*",34),cl_delete(2, VV[151], ecl_symbol_value(ECL_SYM("*FEATURES*",34))));
 {
  cl_object T0;
  cl_object  volatile env0;
  cl_object  volatile CLV0, CLV1
  ;
 {
  cl_object v1compile_file;
  cl_object v2compile_file_pathname;
  cl_object env1 = env0;
  T0 = (VV[127]->symbol.gfdef);
  env1 = ECL_NIL;
  CLV0 = env1 = CONS(T0,env1);                    /*  COMPILE         */
  T0 = (VV[133]->symbol.gfdef);
  CLV1 = env1 = CONS(T0,env1);                    /*  DISASSEMBLE     */
  v1compile_file = (VV[125]->symbol.gfdef);
  v2compile_file_pathname = (VV[26]->symbol.gfdef);
  {cl_object v3;
   v3 = ECL_NIL;
   v3 = ecl_make_cclosure_va((cl_objectfn)L40install_c_compiler,env1,Cblock);
   T0 = v3;
  }
  si_fset(4, ECL_SYM("INSTALL-C-COMPILER",1952), T0, ECL_NIL, ECL_NIL);
 }
 }
 cl_provide(VV[153]);
}
