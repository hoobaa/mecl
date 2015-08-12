/*	Compiler: ECL 12.12.1                                         */
/*	Source: EXT:DEFSYSTEM;DEFSYSTEM.LISP                          */
#include <ecl/ecl-cmp.h>
#include "ext/defsystem.eclh"
/*	function definition for HOME-SUBDIRECTORY                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1home_subdirectory(cl_object v1directory)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2homedir;
   v2homedir = cl_user_homedir_pathname(0);
   if (Null(v2homedir)) { goto L7; }
   value0 = cl_namestring(v2homedir);
   goto L5;
L7:;
   value0 = ECL_NIL;
   goto L5;
L5:;
   if ((value0)!=ECL_NIL) { goto L4; }
   T0 = _ecl_static_2;
   goto L1;
L4:;
   T0 = value0;
   goto L1;
  }
L1:;
  value0 = cl_concatenate(3, ECL_SYM("STRING",805), T0, v1directory);
  return value0;
 }
}
/*	function definition for ADD-REGISTRY-LOCATION                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2add_registry_location(cl_object v1pathname)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_symbol_value(VV[9]);
  T1 = (ECL_SYM("EQUAL",335)->symbol.gfdef);
  cl_set(VV[9],cl_adjoin(4, v1pathname, T0, ECL_SYM("TEST",1316), T1));
  value0 = ecl_symbol_value(VV[9]);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for REGISTRY-PATHNAME                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3registry_pathname(cl_object v1registry)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_STRINGP(v1registry))) { goto L1; }
  value0 = cl_pathname(v1registry);
  return value0;
L1:;
  if (Null(cl_pathnamep(v1registry))) { goto L3; }
  value0 = v1registry;
  cl_env_copy->nvalues = 1;
  return value0;
L3:;
  T0 = cl_eval(v1registry);
  value0 = cl_pathname(T0);
  return value0;
 }
}
/*	function definition for PRINT-CENTRAL-REGISTRY-DIRECTORIES    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4print_central_registry_directories(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1stream;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1stream = ecl_symbol_value(ECL_SYM("*STANDARD-OUTPUT*",67));
   } else {
    i++;
    v1stream = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v2;
   v2 = ecl_symbol_value(VV[9]);
   goto L5;
L4:;
   {
    cl_object v3registry;
    v3registry = ecl_car(v2);
    T0 = L3registry_pathname(v3registry);
    ecl_print(T0,v1stream);
   }
   v2 = ecl_cdr(v2);
L5:;
   if (Null(v2)) { goto L12; }
   goto L4;
L12:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for LIST-CENTRAL-REGISTRY-DIRECTORIES     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5list_central_registry_directories()
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v1;
   cl_object v2;
   cl_object v3;
   v1 = ecl_symbol_value(VV[9]);
   v2 = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v1))) FEtype_error_list(v1);
   v3 = v1;
   {
    cl_object v4;
    cl_object v5;
    v4 = ecl_list1(ECL_NIL);
    v5 = v4;
L7:;
    if (!(ecl_endp(v3))) { goto L9; }
    goto L8;
L9:;
    v2 = _ecl_car(v3);
    {
     cl_object v6;
     v6 = _ecl_cdr(v3);
     if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
     v3 = v6;
    }
    if (ecl_unlikely(ECL_ATOM(v5))) FEtype_error_cons(v5);
    T0 = v5;
    T1 = L3registry_pathname(v2);
    v5 = ecl_list1(T1);
    (ECL_CONS_CDR(T0)=v5,T0);
    goto L7;
L8:;
    value0 = ecl_cdr(v4);
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for NON-EMPTY-LISTP                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6non_empty_listp(cl_object v1list)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1list)) { goto L2; }
  value0 = ecl_make_bool(ECL_LISTP(v1list));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for COMPONENT-OPERATION                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7component_operation(cl_narg narg, cl_object v1name, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2operation;
  va_list args; va_start(args,v1name);
  {
   int i = 1;
   if (i >= narg) {
    v2operation = ECL_NIL;
   } else {
    i++;
    v2operation = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (Null(v2operation)) { goto L2; }
  value0 = si_hash_set(v1name, ecl_symbol_value(VV[37]), v2operation);
  return value0;
L2:;
  value0 = cl_gethash(2, v1name, ecl_symbol_value(VV[37]));
  return value0;
 }
}
/*	local function G21                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC8__g21(cl_object v1stream, cl_object v2char, cl_object v3arg)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_read(4, v1stream, ECL_T, ECL_NIL, ECL_T);
  value0 = cl_list(2, VV[39], T0);
  return value0;
 }
}
/*	function definition for OPERATING-SYSTEM-VERSION              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L9operating_system_version()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = (cl_env_copy->function=(ECL_SYM("SOFTWARE-TYPE",784)->symbol.gfdef))->cfun.entry(0) /*  SOFTWARE-TYPE */;
  return value0;
 }
}
/*	function definition for COMPILER-VERSION                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L10compiler_version()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = _ecl_static_10;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for AFS-BINARY-DIRECTORY                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L11afs_binary_directory(cl_object v1root_directory)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   cl_object v3;
   cl_object v4;
   T0 = (cl_env_copy->function=(ECL_SYM("MACHINE-TYPE",516)->symbol.gfdef))->cfun.entry(0) /*  MACHINE-TYPE */;
   v2 = L16machine_type_translation(1, T0);
   T0 = (cl_env_copy->function=(ECL_SYM("SOFTWARE-TYPE",784)->symbol.gfdef))->cfun.entry(0) /*  SOFTWARE-TYPE */;
   v3 = L17software_type_translation(1, T0);
   T0 = L10compiler_version();
   v4 = L18compiler_type_translation(1, T0);
   v1root_directory = cl_namestring(v1root_directory);
   v1root_directory = L14ensure_trailing_slash(v1root_directory);
   T0 = ecl_symbol_value(VV[14]);
   if (Null(ecl_symbol_value(VV[7]))) { goto L9; }
   T1 = L15afs_component(3, v2, v3, v4);
   goto L8;
L9:;
   T1 = L15afs_component(2, v2, v3);
L8:;
   value0 = cl_format(5, ECL_NIL, _ecl_static_11, v1root_directory, T0, T1);
   return value0;
  }
 }
}
/*	function definition for AFS-SOURCE-DIRECTORY                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L12afs_source_directory(cl_narg narg, cl_object v1root_directory, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2version_flag;
  va_list args; va_start(args,v1root_directory);
  {
   int i = 1;
   if (i >= narg) {
    v2version_flag = ECL_NIL;
   } else {
    i++;
    v2version_flag = va_arg(args,cl_object);
   }
  }
  va_end(args);
  v1root_directory = cl_namestring(v1root_directory);
  v1root_directory = L14ensure_trailing_slash(v1root_directory);
  if (Null(v2version_flag)) { goto L8; }
  T0 = L71translate_version(ecl_symbol_value(VV[36]));
  goto L6;
L8:;
  T0 = ECL_NIL;
  goto L6;
L6:;
  value0 = cl_format(4, ECL_NIL, _ecl_static_12, v1root_directory, T0);
  return value0;
 }
}
/*	function definition for NULL-STRING                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L13null_string(cl_object v1s)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_STRINGP(v1s))) { goto L1; }
  value0 = cl_string_equal(2, v1s, _ecl_static_13);
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for ENSURE-TRAILING-SLASH                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L14ensure_trailing_slash(cl_object v1dir)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1dir)) { goto L1; }
  if ((L13null_string(v1dir))!=ECL_NIL) { goto L1; }
  {
   cl_fixnum v2;
   v2 = ecl_length(v1dir);
   T0 = ecl_make_integer((v2)-1);
   T1 = cl_char(v1dir, T0);
   if ((ecl_char_code(T1))==((ecl_character)(47))) { goto L1; }
  }
  {
   cl_fixnum v2;
   v2 = ecl_length(v1dir);
   T0 = ecl_make_integer((v2)-1);
   T1 = cl_char(v1dir, T0);
   if ((ecl_char_code(T1))==((ecl_character)(92))) { goto L1; }
  }
  value0 = cl_concatenate(3, ECL_SYM("STRING",805), v1dir, _ecl_static_14);
  return value0;
L1:;
  value0 = v1dir;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for AFS-COMPONENT                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L15afs_component(cl_narg narg, cl_object v1machine, cl_object v2software, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v3lisp;
  va_list args; va_start(args,v2software);
  {
   int i = 2;
   if (i >= narg) {
    v3lisp = ECL_NIL;
   } else {
    i++;
    v3lisp = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = v2software;
  if ((value0)!=ECL_NIL) { goto L4; }
  T0 = _ecl_static_16;
  goto L2;
L4:;
  T0 = value0;
  goto L2;
L2:;
  value0 = cl_format(5, ECL_NIL, _ecl_static_15, v1machine, T0, v3lisp);
  return value0;
 }
}
/*	function definition for MACHINE-TYPE-TRANSLATION              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L16machine_type_translation(cl_narg narg, cl_object v1name, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2operation;
  va_list args; va_start(args,v1name);
  {
   int i = 1;
   if (i >= narg) {
    v2operation = ECL_NIL;
   } else {
    i++;
    v2operation = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (Null(v2operation)) { goto L2; }
  T0 = cl_string_upcase(1, v1name);
  value0 = si_hash_set(T0, ecl_symbol_value(VV[48]), v2operation);
  return value0;
L2:;
  T0 = cl_string_upcase(1, v1name);
  value0 = cl_gethash(2, T0, ecl_symbol_value(VV[48]));
  return value0;
 }
}
/*	function definition for SOFTWARE-TYPE-TRANSLATION             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L17software_type_translation(cl_narg narg, cl_object v1name, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2operation;
  va_list args; va_start(args,v1name);
  {
   int i = 1;
   if (i >= narg) {
    v2operation = ECL_NIL;
   } else {
    i++;
    v2operation = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (Null(v2operation)) { goto L2; }
  T0 = cl_string_upcase(1, v1name);
  value0 = si_hash_set(T0, ecl_symbol_value(VV[50]), v2operation);
  return value0;
L2:;
  T0 = cl_string_upcase(1, v1name);
  value0 = cl_gethash(2, T0, ecl_symbol_value(VV[50]));
  return value0;
 }
}
/*	function definition for COMPILER-TYPE-TRANSLATION             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L18compiler_type_translation(cl_narg narg, cl_object v1name, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2operation;
  va_list args; va_start(args,v1name);
  {
   int i = 1;
   if (i >= narg) {
    v2operation = ECL_NIL;
   } else {
    i++;
    v2operation = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (Null(v2operation)) { goto L2; }
  T0 = cl_string_upcase(1, v1name);
  value0 = si_hash_set(T0, ecl_symbol_value(VV[52]), v2operation);
  return value0;
L2:;
  T0 = cl_string_upcase(1, v1name);
  value0 = cl_gethash(2, T0, ecl_symbol_value(VV[52]));
  return value0;
 }
}
/*	function definition for CANONICALIZE-SYSTEM-NAME              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L19canonicalize_system_name(cl_object v1name)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_STRINGP(v1name))) { goto L1; }
  value0 = cl_string_upcase(1, v1name);
  return value0;
L1:;
  T0 = cl_string(v1name);
  value0 = cl_string_upcase(1, T0);
  return value0;
 }
}
/*	function definition for GET-SYSTEM                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L20get_system(cl_object v1name)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = L19canonicalize_system_name(v1name);
  value0 = cl_gethash(2, T0, ecl_symbol_value(VV[55]));
  return value0;
 }
}
/*	local function GET-SYSTEM                                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC21get_system(cl_object v1value, cl_object v2name)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, VV[54], v2name);
  T1 = cl_list(3, ECL_SYM("GETHASH",413), T0, VV[55]);
  value0 = cl_list(3, ECL_SYM("SETF",750), T1, v1value);
  return value0;
 }
}
/*	function definition for UNDEFSYSTEM                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L22undefsystem(cl_object v1name)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = L19canonicalize_system_name(v1name);
  value0 = cl_remhash(T0, ecl_symbol_value(VV[55]));
  return value0;
 }
}
/*	function definition for DEFINED-SYSTEMS                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L24defined_systems()
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object env1 = env0;
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(ECL_NIL,env1);              /*  RESULT          */
   {cl_object v1;
    v1 = ECL_NIL;
    v1 = ecl_make_cclosure_va((cl_objectfn)LC23__g34,env1,Cblock);
    T0 = v1;
   }
   cl_maphash(T0, ecl_symbol_value(VV[55]));
   value0 = ECL_CONS_CAR(CLV0);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	closure G34                                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC23__g34(cl_narg narg, cl_object v1key, cl_object v2value, ...)
{
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  RESULT          */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  ECL_CONS_CAR(CLV0) = CONS(v2value,ECL_CONS_CAR(CLV0));
  value0 = ECL_CONS_CAR(CLV0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
 }
}
/*	function definition for DEFINED-NAMES-AND-SYSTEMS             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L25defined_names_and_systems()
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v1;
   cl_object v2;
   cl_object v3sname;
   cl_object v4s;
   v1 = ecl_symbol_value(VV[55]);
   v2 = ECL_NIL;
   v3sname = ECL_NIL;
   v4s = ECL_NIL;
   {
    cl_object v5;
    v5 = si_hash_table_iterator(v1);
    {
     cl_object v6;
     cl_object v7;
     v6 = ecl_list1(ECL_NIL);
     v7 = v6;
L8:;
     {
      cl_object v9;
      cl_object v10;
      cl_object v11;
      value0 = ecl_function_dispatch(cl_env_copy,v5)(0);
      v9 = value0;
      {
       const int v12 = cl_env_copy->nvalues;
       cl_object v13;
       v13 = (v12<=1)? ECL_NIL : cl_env_copy->values[1];
       v10 = v13;
       v13 = (v12<=2)? ECL_NIL : cl_env_copy->values[2];
       v11 = v13;
      }
      if (Null(v9)) { goto L13; }
      v4s = v11;
      v3sname = v10;
L13:;
      v2 = v9;
      if ((v2)!=ECL_NIL) { goto L10; }
     }
     goto L9;
L10:;
     if (ecl_unlikely(ECL_ATOM(v7))) FEtype_error_cons(v7);
     T0 = v7;
     T1 = CONS(v3sname,v4s);
     v7 = ecl_list1(T1);
     (ECL_CONS_CDR(T0)=v7,T0);
     goto L8;
L9:;
     value0 = ecl_cdr(v6);
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
  }
 }
}
/*	function definition for NEW-APPEND-DIRECTORIES                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L27new_append_directories(cl_object volatile v1absolute_dir, cl_object volatile v2relative_dir)
{
 cl_object T0, T1, T2, T3;
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = v1absolute_dir;
  if ((value0)!=ECL_NIL) { goto L5; }
  v1absolute_dir = _ecl_static_13;
  goto L3;
L5:;
  v1absolute_dir = value0;
  goto L3;
L3:;
  value0 = v2relative_dir;
  if ((value0)!=ECL_NIL) { goto L9; }
  v2relative_dir = _ecl_static_13;
  goto L7;
L9:;
  v2relative_dir = value0;
  goto L7;
L7:;
  {
   volatile cl_object v3abs_dir;
   volatile cl_object v4rel_dir;
   volatile cl_object v5host;
   volatile cl_object v6device;
   volatile cl_object v7abs_directory;
   volatile cl_object v8abs_keyword;
   volatile cl_object v9abs_name;
   volatile cl_object v10rel_directory;
   volatile cl_object v11rel_keyword;
   volatile cl_object v12rel_file;
   volatile cl_object v13directory;
   v3abs_dir = cl_pathname(v1absolute_dir);
   v4rel_dir = cl_pathname(v2relative_dir);
   v5host = cl_pathname_host(1, v3abs_dir);
   if (Null(L13null_string(v1absolute_dir))) { goto L15; }
   v6device = cl_pathname_device(1, v4rel_dir);
   goto L14;
L15:;
   v6device = cl_pathname_device(1, v3abs_dir);
L14:;
   T0 = cl_pathname_directory(1, v3abs_dir);
   v7abs_directory = L28directory_to_list(T0);
   T0 = ecl_car(v7abs_directory);
   if (Null(cl_keywordp(T0))) { goto L19; }
   {
    cl_object v14;
    v14 = v7abs_directory;
    if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
    if (Null(v14)) { goto L24; }
    {
     cl_object v15;
     v15 = ECL_CONS_CDR(v14);
     v7abs_directory = v15;
     v14 = ECL_CONS_CAR(v14);
    }
L24:;
    v8abs_keyword = v14;
    goto L18;
   }
L19:;
   v8abs_keyword = ECL_NIL;
L18:;
   {
    volatile cl_object env1 = env0;
    env1 = ECL_NIL;
    CLV0 = env1 = CONS(ECL_NIL,env1);
    {
     volatile cl_object env2 = env1;
     CLV1 = env2 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env2); /*  TAGBODY */
     if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV1))) {
     if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L31;
     ecl_internal_error("GO found an inexistent tag");
     }
     {cl_object v14;
      v14 = ECL_NIL;
      v14 = ecl_make_cclosure_va((cl_objectfn)LC26__g58,env2,Cblock);
      T0 = v14;
     }
     T1 = CONS(ECL_SYM("ERROR",337),T0);
     T2 = ecl_list1(T1);
     T3 = CONS(T2,ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5)));
     ecl_bds_bind(cl_env_copy,ECL_SYM("*HANDLER-CLUSTERS*",5),T3); /*  *HANDLER-CLUSTERS* */
     value0 = cl_file_namestring(v3abs_dir);
     ecl_frs_pop(cl_env_copy);
     v9abs_name = value0;
     ecl_bds_unwind1(cl_env_copy);
     goto L30;
L31:;
     {
      cl_object v14condition;
      v14condition = ECL_CONS_CAR(CLV0);
      cl_env_copy->nvalues = 2;
      cl_env_copy->values[1] = v14condition;
      cl_env_copy->values[0] = ECL_NIL;
      value0 = cl_env_copy->values[0];
      ecl_frs_pop(cl_env_copy);
      v9abs_name = value0;
      goto L30;
     }
    }
   }
L30:;
   T0 = cl_pathname_directory(1, v4rel_dir);
   v10rel_directory = L28directory_to_list(T0);
   T0 = ecl_car(v10rel_directory);
   if (Null(cl_keywordp(T0))) { goto L38; }
   {
    cl_object v14;
    v14 = v10rel_directory;
    if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
    if (Null(v14)) { goto L43; }
    {
     cl_object v15;
     v15 = ECL_CONS_CDR(v14);
     v10rel_directory = v15;
     v14 = ECL_CONS_CAR(v14);
    }
L43:;
    v11rel_keyword = v14;
    goto L37;
   }
L38:;
   v11rel_keyword = ECL_NIL;
L37:;
   v12rel_file = cl_file_namestring(v4rel_dir);
   v13directory = ECL_NIL;
   if (Null(v9abs_name)) { goto L51; }
   if ((L13null_string(v9abs_name))!=ECL_NIL) { goto L51; }
   if (!(v7abs_directory==ECL_NIL)) { goto L54; }
   if (!(v8abs_keyword==ECL_NIL)) { goto L54; }
   v8abs_keyword = ECL_SYM("RELATIVE",1299);
   v7abs_directory = ecl_list1(v9abs_name);
   goto L51;
L54:;
   T0 = ecl_list1(v9abs_name);
   v7abs_directory = ecl_append(v7abs_directory,T0);
L51:;
   if (!(v7abs_directory==ECL_NIL)) { goto L61; }
   if (!(v8abs_keyword==ECL_NIL)) { goto L61; }
   if (Null(v11rel_keyword)) { goto L61; }
   v8abs_keyword = v11rel_keyword;
L61:;
   v13directory = ecl_append(v7abs_directory,v10rel_directory);
   if (Null(v8abs_keyword)) { goto L68; }
   v13directory = CONS(v8abs_keyword,v13directory);
L68:;
   T0 = cl_make_pathname(8, ECL_SYM("HOST",1243), v5host, ECL_SYM("DEVICE",1217), v6device, ECL_SYM("DIRECTORY",1219), v13directory, ECL_SYM("NAME",1273), v12rel_file);
   value0 = cl_namestring(T0);
   return value0;
  }
 }
}
/*	closure G58                                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC26__g58(cl_narg narg, cl_object v1si__temp, ...)
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
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  ECL_CONS_CAR(CLV0) = v1si__temp;
  cl_go(ECL_CONS_CAR(CLV1),ecl_make_fixnum(0));
 }
 }
}
/*	function definition for DIRECTORY-TO-LIST                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L28directory_to_list(cl_object v1directory)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_LISTP(v1directory))) { goto L1; }
  value0 = v1directory;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (!(ECL_STRINGP(v1directory))) { goto L3; }
  {
   cl_object v2;
   v2 = si_make_seq_iterator(2, v1directory, ecl_make_fixnum(0));
L8:;
   if ((v2)!=ECL_NIL) { goto L10; }
   goto L5;
L10:;
   {
    cl_object v3;
    v3 = si_seq_iterator_ref(v1directory, v2);
    if (!((ECL_CODE_CHAR((ecl_character)(59))==(v3)))) { goto L12; }
    if (Null(v3)) { goto L5; }
    goto L6;
   }
L12:;
   v2 = si_seq_iterator_next(v1directory, v2);
   goto L8;
  }
L6:;
  value0 = L87split_string(3, v1directory, VV[61], CODE_CHAR(59));
  return value0;
L5:;
  value0 = L87split_string(3, v1directory, VV[61], CODE_CHAR(47));
  return value0;
L3:;
  value0 = si_coerce_to_list(1, v1directory);
  return value0;
 }
}
/*	function definition for TEST-NEW-APPEND-DIRECTORIES           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L29test_new_append_directories(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1test_dirs;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1test_dirs = ecl_symbol_value(VV[63]);
   } else {
    i++;
    v1test_dirs = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v2dir_list;
   cl_object v3abs_dir;
   cl_object v4rel_dir;
   v2dir_list = v1test_dirs;
   v3abs_dir = ecl_car(v2dir_list);
   v4rel_dir = ecl_cadr(v2dir_list);
   goto L7;
L6:;
   T0 = L27new_append_directories(v3abs_dir, v4rel_dir);
   cl_format(5, ECL_T, _ecl_static_77, v3abs_dir, v4rel_dir, T0);
   v2dir_list = ecl_cddr(v2dir_list);
   v3abs_dir = ecl_car(v2dir_list);
   v4rel_dir = ecl_cadr(v2dir_list);
L7:;
   if (v2dir_list==ECL_NIL) { goto L16; }
   goto L6;
L16:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 0;
   return value0;
  }
 }
}
/*	function definition for APPEND-DIRECTORIES                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L30append_directories(cl_object v1absolute_directory, cl_object v2relative_directory)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((v1absolute_directory)!=ECL_NIL) { goto L3; }
  if (Null(v2relative_directory)) { goto L1; }
  goto L2;
L3:;
L2:;
  if (Null(L33namestring_probably_logical(v1absolute_directory))) { goto L5; }
  value0 = L34append_logical_pnames(v1absolute_directory, v2relative_directory);
  return value0;
L5:;
  value0 = L27new_append_directories(v1absolute_directory, v2relative_directory);
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for PATHNAME-LOGICAL-P                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L32pathname_logical_p(cl_object volatile v1thing)
{
 cl_object T0, T1, T2, T3;
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(si_logical_pathname_p(v1thing))) { goto L1; }
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (!(ECL_STRINGP(v1thing))) { goto L3; }
  T0 = cl_count(2, CODE_CHAR(58), v1thing);
  if (!((1)==(ecl_to_fixnum(T0)))) { goto L6; }
  {
   volatile cl_object env1 = env0;
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(ECL_NIL,env1);
   {
    volatile cl_object env2 = env1;
    CLV1 = env2 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env2); /*  TAGBODY */
    if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV1))) {
    if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L9;
    ecl_internal_error("GO found an inexistent tag");
    }
    {cl_object v2;
     v2 = ECL_NIL;
     v2 = ecl_make_cclosure_va((cl_objectfn)LC31__g81,env2,Cblock);
     T0 = v2;
    }
    T1 = CONS(ECL_SYM("ERROR",337),T0);
    T2 = ecl_list1(T1);
    T3 = CONS(T2,ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5)));
    ecl_bds_bind(cl_env_copy,ECL_SYM("*HANDLER-CLUSTERS*",5),T3); /*  *HANDLER-CLUSTERS* */
    if (Null(cl_translate_logical_pathname(1, v1thing))) {
    ecl_frs_pop(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
     goto L6;
    }
    value0 = cl_translate_logical_pathname(1, v1thing);
    ecl_frs_pop(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    goto L8;
L9:;
    {
     cl_object v2condition;
     v2condition = ECL_CONS_CAR(CLV0);
     cl_env_copy->nvalues = 2;
     cl_env_copy->values[1] = v2condition;
     cl_env_copy->values[0] = ECL_NIL;
     if (Null(cl_env_copy->values[0])) {
     ecl_frs_pop(cl_env_copy); goto L6; }
     value0 = cl_env_copy->values[0];
     ecl_frs_pop(cl_env_copy);
     goto L8;
    }
   }
  }
L8:;
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
L6:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L3:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	closure G81                                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC31__g81(cl_narg narg, cl_object v1si__temp, ...)
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
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  ECL_CONS_CAR(CLV0) = v1si__temp;
  cl_go(ECL_CONS_CAR(CLV1),ecl_make_fixnum(0));
 }
 }
}
/*	function definition for NAMESTRING-PROBABLY-LOGICAL           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L33namestring_probably_logical(cl_object v1namestring)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_STRINGP(v1namestring))) { goto L2; }
  {
   cl_object v2;
   v2 = si_make_seq_iterator(2, v1namestring, ecl_make_fixnum(0));
L5:;
   if ((v2)!=ECL_NIL) { goto L7; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L7:;
   {
    cl_object v3;
    v3 = si_seq_iterator_ref(v1namestring, v2);
    if (!((ECL_CODE_CHAR((ecl_character)(59))==(v3)))) { goto L9; }
    value0 = v3;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L9:;
   v2 = si_seq_iterator_next(v1namestring, v2);
   goto L5;
  }
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for APPEND-LOGICAL-PNAMES                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L34append_logical_pnames(cl_object v1absolute, cl_object v2relative)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   if (Null(v1absolute)) { goto L2; }
   v3 = cl_pathname(v1absolute);
   goto L1;
L2:;
   T0 = ecl_list1(ECL_SYM("ABSOLUTE",1196));
   v3 = cl_make_pathname(6, ECL_SYM("DIRECTORY",1219), T0, ECL_SYM("NAME",1273), ECL_NIL, ECL_SYM("TYPE",1318), ECL_NIL);
L1:;
   if (Null(v2relative)) { goto L5; }
   v4 = cl_pathname(v2relative);
   goto L4;
L5:;
   T0 = ecl_list1(ECL_SYM("RELATIVE",1299));
   v4 = cl_make_pathname(6, ECL_SYM("DIRECTORY",1219), T0, ECL_SYM("NAME",1273), ECL_NIL, ECL_SYM("TYPE",1318), ECL_NIL);
L4:;
   if (Null(si_logical_pathname_p(v3))) { goto L7; }
   if (Null(si_logical_pathname_p(v4))) { goto L9; }
   T0 = cl_merge_pathnames(2, v4, v3);
   value0 = cl_namestring(T0);
   return value0;
L9:;
   if (Null(cl_pathnamep(v4))) { goto L11; }
   T0 = cl_translate_logical_pathname(1, v3);
   T1 = cl_merge_pathnames(2, v4, T0);
   value0 = cl_namestring(T1);
   return value0;
L11:;
   value0 = si_etypecase_error(v4, VV[68]);
   return value0;
L7:;
   if (Null(cl_pathnamep(v3))) { goto L13; }
   T0 = cl_merge_pathnames(2, v4, v3);
   value0 = cl_namestring(T0);
   return value0;
L13:;
   value0 = si_etypecase_error(v3, VV[68]);
   return value0;
  }
 }
}
/*	function definition for NEW-FILE-TYPE                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L35new_file_type(cl_object v1pathname, cl_object v2type)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_pathname_host(1, v1pathname);
  T1 = cl_pathname_device(1, v1pathname);
  T2 = cl_pathname_directory(1, v1pathname);
  T3 = cl_pathname_name(1, v1pathname);
  T4 = cl_pathname_version(v1pathname);
  value0 = cl_make_pathname(12, ECL_SYM("HOST",1243), T0, ECL_SYM("DEVICE",1217), T1, ECL_SYM("DIRECTORY",1219), T2, ECL_SYM("NAME",1273), T3, ECL_SYM("TYPE",1318), v2type, ECL_SYM("VERSION",1326), T4);
  return value0;
 }
}
/*	function definition for MAKE-TOPOLOGICAL-SORT-NODE            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L36make_topological_sort_node(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L36make_topological_sort_nodekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[1])) {
    v1 = VV[77];
   } else {
    v1 = keyvars[0];
   }
  }
  if (!(ecl_eql(v1,VV[78]))) { goto L6; }
  goto L2;
  goto L4;
L6:;
  goto L4;
L4:;
  if (!(ecl_eql(v1,VV[80]))) { goto L10; }
  goto L2;
  goto L8;
L10:;
  goto L8;
L8:;
  if (!(ecl_eql(v1,VV[77]))) { goto L13; }
  goto L2;
  goto L3;
L13:;
  goto L3;
L3:;
  si_structure_type_error(4, v1, VV[83], VV[73], VV[84]);
L2:;
  value0 = si_make_structure(2, VV[85], v1);
  return value0;
 }
}
/*	function definition for MAKE-COMPONENT                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L41make_component(cl_narg narg, ...)
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
  cl_object v6;
  cl_object v7;
  cl_object v8;
  cl_object v9;
  cl_object v10;
  cl_object v11;
  cl_object v12;
  cl_object v13;
  cl_object v14;
  cl_object v15;
  cl_object v16;
  cl_object v17;
  cl_object v18;
  cl_object v19;
  cl_object v20;
  cl_object v21;
  cl_object v22;
  cl_object v23;
  cl_object v24;
  cl_object v25;
  cl_object v26;
  cl_object v27;
  cl_object v28;
  cl_object v29;
  cl_object v30;
  cl_object v31;
  cl_object v32;
  cl_object v33;
  cl_object v34;
  cl_object v35;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  {
   cl_object keyvars[70];
   cl_parse_key(args,35,L41make_componentkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[35])) {
    v1 = VV[77];
   } else {
    v1 = keyvars[0];
   }
   if (Null(keyvars[36])) {
    v2 = ECL_SYM("FILE",1237);
   } else {
    v2 = keyvars[1];
   }
   v3 = keyvars[2];
   if (Null(keyvars[38])) {
    v4 = ecl_make_fixnum(0);
   } else {
    v4 = keyvars[3];
   }
   v5 = keyvars[4];
   v6 = keyvars[5];
   v7 = keyvars[6];
   if (Null(keyvars[42])) {
    v8 = ecl_symbol_value(VV[71]);
   } else {
    v8 = keyvars[7];
   }
   v9 = keyvars[8];
   if (Null(keyvars[44])) {
    v10 = ecl_symbol_value(VV[72]);
   } else {
    v10 = keyvars[9];
   }
   v11 = keyvars[10];
   v12 = keyvars[11];
   v13 = keyvars[12];
   v14 = keyvars[13];
   v15 = keyvars[14];
   v16 = keyvars[15];
   v17 = keyvars[16];
   v18 = keyvars[17];
   v19 = keyvars[18];
   v20 = keyvars[19];
   if (Null(keyvars[55])) {
    {cl_object v36;
     v36 = ECL_NIL;
     v36 = ecl_make_cfun((cl_objectfn_fixed)LC37__g95,ECL_NIL,Cblock,0);
     v21 = v36;
    }
   } else {
    v21 = keyvars[20];
   }
   if (Null(keyvars[56])) {
    {cl_object v36;
     v36 = ECL_NIL;
     v36 = ecl_make_cfun((cl_objectfn_fixed)LC38__g96,ECL_NIL,Cblock,0);
     v22 = v36;
    }
   } else {
    v22 = keyvars[21];
   }
   if (Null(keyvars[57])) {
    {cl_object v36;
     v36 = ECL_NIL;
     v36 = ecl_make_cfun((cl_objectfn_fixed)LC39__g97,ECL_NIL,Cblock,0);
     v23 = v36;
    }
   } else {
    v23 = keyvars[22];
   }
   if (Null(keyvars[58])) {
    {cl_object v36;
     v36 = ECL_NIL;
     v36 = ecl_make_cfun((cl_objectfn_fixed)LC40__g98,ECL_NIL,Cblock,0);
     v24 = v36;
    }
   } else {
    v24 = keyvars[23];
   }
   v25 = keyvars[24];
   v26 = keyvars[25];
   v27 = keyvars[26];
   v28 = keyvars[27];
   v29 = keyvars[28];
   v30 = keyvars[29];
   v31 = keyvars[30];
   v32 = keyvars[31];
   v33 = keyvars[32];
   v34 = keyvars[33];
   v35 = keyvars[34];
  }
  if (!((v35)==(ECL_NIL))) { goto L14; }
  goto L10;
  goto L12;
L14:;
  goto L12;
L12:;
  if (!(ecl_eql(v35,ECL_T))) { goto L17; }
  goto L10;
  goto L11;
L17:;
  goto L11;
L11:;
  si_structure_type_error(4, v35, ECL_SYM("BOOLEAN",155), VV[89], VV[95]);
L10:;
  if (v34==ECL_NIL) { goto L19; }
  if (ECL_STRINGP(v34)) { goto L19; }
  si_structure_type_error(4, v34, VV[96], VV[89], VV[97]);
L19:;
  if (v33==ECL_NIL) { goto L22; }
  if (ECL_STRINGP(v33)) { goto L22; }
  si_structure_type_error(4, v33, VV[96], VV[89], VV[98]);
L22:;
  if (v32==ECL_NIL) { goto L25; }
  if (ECL_STRINGP(v32)) { goto L25; }
  si_structure_type_error(4, v32, VV[96], VV[89], VV[99]);
L25:;
  if (v31==ECL_NIL) { goto L28; }
  if (ECL_STRINGP(v31)) { goto L28; }
  si_structure_type_error(4, v31, VV[96], VV[89], VV[100]);
L28:;
  if (v30==ECL_NIL) { goto L31; }
  if (ECL_STRINGP(v30)) { goto L31; }
  si_structure_type_error(4, v30, VV[96], VV[89], VV[101]);
L31:;
  if (v29==ECL_NIL) { goto L34; }
  if (ECL_STRINGP(v29)) { goto L34; }
  si_structure_type_error(4, v29, VV[96], VV[89], ECL_SYM("DOCUMENTATION",312));
L34:;
  if (v28==ECL_NIL) { goto L37; }
  if (ECL_STRINGP(v28)) { goto L37; }
  si_structure_type_error(4, v28, VV[96], VV[89], VV[102]);
L37:;
  if (ECL_LISTP(v19)) { goto L40; }
  si_structure_type_error(4, v19, ECL_SYM("LIST",481), VV[89], VV[103]);
L40:;
  if (ECL_LISTP(v18)) { goto L42; }
  si_structure_type_error(4, v18, ECL_SYM("LIST",481), VV[89], VV[104]);
L42:;
  if (ECL_LISTP(v17)) { goto L44; }
  si_structure_type_error(4, v17, ECL_SYM("LIST",481), VV[89], VV[105]);
L44:;
  if (v16==ECL_NIL) { goto L46; }
  if (ECL_SYMBOLP(v16)) { goto L46; }
  if ((cl_functionp(v16))!=ECL_NIL) { goto L46; }
  si_structure_type_error(4, v16, VV[106], VV[89], VV[107]);
L46:;
  if (v15==ECL_NIL) { goto L50; }
  if (ECL_SYMBOLP(v15)) { goto L50; }
  if ((cl_functionp(v15))!=ECL_NIL) { goto L50; }
  si_structure_type_error(4, v15, VV[106], VV[89], VV[108]);
L50:;
  if (ECL_SYMBOLP(v14)) { goto L54; }
  si_structure_type_error(4, v14, VV[109], VV[89], VV[110]);
L54:;
  {
   cl_fixnum v36;
   v36 = 0;
   if (!(ECL_FIXNUMP(v4))) { goto L60; }
   v36 = ecl_fixnum(v4);
   if (!((v36)<=(1023))) { goto L65; }
   if ((v36)>=(0)) { goto L56; }
   goto L57;
L65:;
   goto L57;
L60:;
   goto L57;
  }
L57:;
  si_structure_type_error(4, v4, VV[111], VV[89], VV[112]);
L56:;
  if (ECL_SYMBOLP(v3)) { goto L67; }
  if (ECL_STRINGP(v3)) { goto L67; }
  si_structure_type_error(4, v3, VV[113], VV[89], VV[114]);
L67:;
  if ((ecl_memql(v2,VV[115]))!=ECL_NIL) { goto L70; }
  si_structure_type_error(4, v2, VV[116], VV[89], ECL_SYM("TYPE",869));
L70:;
  if (!(ecl_eql(v1,VV[78]))) { goto L76; }
  goto L72;
  goto L74;
L76:;
  goto L74;
L74:;
  if (!(ecl_eql(v1,VV[80]))) { goto L80; }
  goto L72;
  goto L78;
L80:;
  goto L78;
L78:;
  if (!(ecl_eql(v1,VV[77]))) { goto L83; }
  goto L72;
  goto L73;
L83:;
  goto L73;
L73:;
  si_structure_type_error(4, v1, VV[83], VV[89], VV[84]);
L72:;
  value0 = si_make_structure(36, VV[117], v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35);
  return value0;
 }
}
/*	local function G95                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC37__g95()
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
/*	local function G96                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC38__g96()
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
/*	local function G97                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC39__g97()
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
/*	local function G98                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC40__g98()
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
/*	function definition for MAKE-FOREIGN-SYSTEM                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L46make_foreign_system(cl_narg narg, ...)
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
  cl_object v6;
  cl_object v7;
  cl_object v8;
  cl_object v9;
  cl_object v10;
  cl_object v11;
  cl_object v12;
  cl_object v13;
  cl_object v14;
  cl_object v15;
  cl_object v16;
  cl_object v17;
  cl_object v18;
  cl_object v19;
  cl_object v20;
  cl_object v21;
  cl_object v22;
  cl_object v23;
  cl_object v24;
  cl_object v25;
  cl_object v26;
  cl_object v27;
  cl_object v28;
  cl_object v29;
  cl_object v30;
  cl_object v31;
  cl_object v32;
  cl_object v33;
  cl_object v34;
  cl_object v35;
  cl_object v36;
  cl_object v37;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  {
   cl_object keyvars[74];
   cl_parse_key(args,37,L46make_foreign_systemkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[37])) {
    v1 = VV[77];
   } else {
    v1 = keyvars[0];
   }
   if (Null(keyvars[38])) {
    v2 = VV[122];
   } else {
    v2 = keyvars[1];
   }
   v3 = keyvars[2];
   if (Null(keyvars[40])) {
    v4 = ecl_make_fixnum(0);
   } else {
    v4 = keyvars[3];
   }
   v5 = keyvars[4];
   v6 = keyvars[5];
   v7 = keyvars[6];
   if (Null(keyvars[44])) {
    v8 = ecl_symbol_value(VV[71]);
   } else {
    v8 = keyvars[7];
   }
   v9 = keyvars[8];
   if (Null(keyvars[46])) {
    v10 = ecl_symbol_value(VV[72]);
   } else {
    v10 = keyvars[9];
   }
   v11 = keyvars[10];
   v12 = keyvars[11];
   v13 = keyvars[12];
   v14 = keyvars[13];
   v15 = keyvars[14];
   v16 = keyvars[15];
   v17 = keyvars[16];
   v18 = keyvars[17];
   v19 = keyvars[18];
   v20 = keyvars[19];
   if (Null(keyvars[57])) {
    {cl_object v38;
     v38 = ECL_NIL;
     v38 = ecl_make_cfun((cl_objectfn_fixed)LC42__g116,ECL_NIL,Cblock,0);
     v21 = v38;
    }
   } else {
    v21 = keyvars[20];
   }
   if (Null(keyvars[58])) {
    {cl_object v38;
     v38 = ECL_NIL;
     v38 = ecl_make_cfun((cl_objectfn_fixed)LC43__g117,ECL_NIL,Cblock,0);
     v22 = v38;
    }
   } else {
    v22 = keyvars[21];
   }
   if (Null(keyvars[59])) {
    {cl_object v38;
     v38 = ECL_NIL;
     v38 = ecl_make_cfun((cl_objectfn_fixed)LC44__g118,ECL_NIL,Cblock,0);
     v23 = v38;
    }
   } else {
    v23 = keyvars[22];
   }
   if (Null(keyvars[60])) {
    {cl_object v38;
     v38 = ECL_NIL;
     v38 = ecl_make_cfun((cl_objectfn_fixed)LC45__g119,ECL_NIL,Cblock,0);
     v24 = v38;
    }
   } else {
    v24 = keyvars[23];
   }
   v25 = keyvars[24];
   v26 = keyvars[25];
   v27 = keyvars[26];
   v28 = keyvars[27];
   v29 = keyvars[28];
   v30 = keyvars[29];
   v31 = keyvars[30];
   v32 = keyvars[31];
   v33 = keyvars[32];
   v34 = keyvars[33];
   v35 = keyvars[34];
   v36 = keyvars[35];
   v37 = keyvars[36];
  }
  if (!((v35)==(ECL_NIL))) { goto L14; }
  goto L10;
  goto L12;
L14:;
  goto L12;
L12:;
  if (!(ecl_eql(v35,ECL_T))) { goto L17; }
  goto L10;
  goto L11;
L17:;
  goto L11;
L11:;
  si_structure_type_error(4, v35, ECL_SYM("BOOLEAN",155), VV[119], VV[95]);
L10:;
  if (v34==ECL_NIL) { goto L19; }
  if (ECL_STRINGP(v34)) { goto L19; }
  si_structure_type_error(4, v34, VV[96], VV[119], VV[97]);
L19:;
  if (v33==ECL_NIL) { goto L22; }
  if (ECL_STRINGP(v33)) { goto L22; }
  si_structure_type_error(4, v33, VV[96], VV[119], VV[98]);
L22:;
  if (v32==ECL_NIL) { goto L25; }
  if (ECL_STRINGP(v32)) { goto L25; }
  si_structure_type_error(4, v32, VV[96], VV[119], VV[99]);
L25:;
  if (v31==ECL_NIL) { goto L28; }
  if (ECL_STRINGP(v31)) { goto L28; }
  si_structure_type_error(4, v31, VV[96], VV[119], VV[100]);
L28:;
  if (v30==ECL_NIL) { goto L31; }
  if (ECL_STRINGP(v30)) { goto L31; }
  si_structure_type_error(4, v30, VV[96], VV[119], VV[101]);
L31:;
  if (v29==ECL_NIL) { goto L34; }
  if (ECL_STRINGP(v29)) { goto L34; }
  si_structure_type_error(4, v29, VV[96], VV[119], ECL_SYM("DOCUMENTATION",312));
L34:;
  if (v28==ECL_NIL) { goto L37; }
  if (ECL_STRINGP(v28)) { goto L37; }
  si_structure_type_error(4, v28, VV[96], VV[119], VV[102]);
L37:;
  if (ECL_LISTP(v19)) { goto L40; }
  si_structure_type_error(4, v19, ECL_SYM("LIST",481), VV[119], VV[103]);
L40:;
  if (ECL_LISTP(v18)) { goto L42; }
  si_structure_type_error(4, v18, ECL_SYM("LIST",481), VV[119], VV[104]);
L42:;
  if (ECL_LISTP(v17)) { goto L44; }
  si_structure_type_error(4, v17, ECL_SYM("LIST",481), VV[119], VV[105]);
L44:;
  if (v16==ECL_NIL) { goto L46; }
  if (ECL_SYMBOLP(v16)) { goto L46; }
  if ((cl_functionp(v16))!=ECL_NIL) { goto L46; }
  si_structure_type_error(4, v16, VV[106], VV[119], VV[107]);
L46:;
  if (v15==ECL_NIL) { goto L50; }
  if (ECL_SYMBOLP(v15)) { goto L50; }
  if ((cl_functionp(v15))!=ECL_NIL) { goto L50; }
  si_structure_type_error(4, v15, VV[106], VV[119], VV[108]);
L50:;
  if (ECL_SYMBOLP(v14)) { goto L54; }
  si_structure_type_error(4, v14, VV[109], VV[119], VV[110]);
L54:;
  {
   cl_fixnum v38;
   v38 = 0;
   if (!(ECL_FIXNUMP(v4))) { goto L60; }
   v38 = ecl_fixnum(v4);
   if (!((v38)<=(1023))) { goto L65; }
   if ((v38)>=(0)) { goto L56; }
   goto L57;
L65:;
   goto L57;
L60:;
   goto L57;
  }
L57:;
  si_structure_type_error(4, v4, VV[111], VV[119], VV[112]);
L56:;
  if (ECL_SYMBOLP(v3)) { goto L67; }
  if (ECL_STRINGP(v3)) { goto L67; }
  si_structure_type_error(4, v3, VV[113], VV[119], VV[114]);
L67:;
  if (!(ecl_eql(v1,VV[78]))) { goto L74; }
  goto L70;
  goto L72;
L74:;
  goto L72;
L72:;
  if (!(ecl_eql(v1,VV[80]))) { goto L78; }
  goto L70;
  goto L76;
L78:;
  goto L76;
L76:;
  if (!(ecl_eql(v1,VV[77]))) { goto L81; }
  goto L70;
  goto L71;
L81:;
  goto L71;
L71:;
  si_structure_type_error(4, v1, VV[83], VV[119], VV[84]);
L70:;
  value0 = si_make_structure(38, VV[123], v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37);
  return value0;
 }
}
/*	local function G116                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC42__g116()
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
/*	local function G117                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC43__g117()
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
/*	local function G118                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC44__g118()
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
/*	local function G119                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC45__g119()
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
/*	function definition for REGISTER-FOREIGN-SYSTEM               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L47register_foreign_system(cl_narg narg, cl_object v1name, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2representation;
  cl_object v3kind;
  ecl_va_list args; ecl_va_start(args,v1name,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L47register_foreign_systemkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v2representation = keyvars[0];
   v3kind = keyvars[1];
  }
  {
   cl_object v4fs;
   v4fs = L46make_foreign_system(6, ECL_SYM("NAME",1273), v1name, VV[125], v3kind, ECL_SYM("OBJECT",1278), v2representation);
   T0 = L19canonicalize_system_name(v1name);
   value0 = si_hash_set(T0, ecl_symbol_value(VV[55]), v4fs);
   return value0;
  }
 }
}
/*	local function G142                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC49__g142()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {cl_object v1;
   v1 = ECL_NIL;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC48__g143,ECL_NIL,Cblock,2);
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G143                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC48__g143(cl_object v1mmc, cl_object v2stream)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[463])(1, v1mmc) /*  MISSING-COMPONENT-NAME */;
  T1 = ecl_function_dispatch(cl_env_copy,VV[464])(1, v1mmc) /*  MISSING-COMPONENT-COMPONENT */;
  value0 = cl_format(4, v2stream, _ecl_static_80, T0, T1);
  return value0;
 }
}
/*	local function G144                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC51__g144()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {cl_object v1;
   v1 = ECL_NIL;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC50__g145,ECL_NIL,Cblock,2);
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G145                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC50__g145(cl_object v1mmc, cl_object v2stream)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[463])(1, v1mmc) /*  MISSING-COMPONENT-NAME */;
  T1 = ecl_function_dispatch(cl_env_copy,VV[464])(1, v1mmc) /*  MISSING-COMPONENT-COMPONENT */;
  value0 = cl_format(4, v2stream, _ecl_static_81, T0, T1);
  return value0;
 }
}
/*	local function G146                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC53__g146()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {cl_object v1;
   v1 = ECL_NIL;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC52__g147,ECL_NIL,Cblock,2);
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G147                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC52__g147(cl_object v1msc, cl_object v2stream)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[463])(1, v1msc) /*  MISSING-COMPONENT-NAME */;
  T1 = ecl_function_dispatch(cl_env_copy,VV[464])(1, v1msc) /*  MISSING-COMPONENT-COMPONENT */;
  value0 = cl_format(4, v2stream, _ecl_static_82, T0, T1);
  return value0;
 }
}
/*	function definition for COMPONENT-LOAD-TIME                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L54component_load_time(cl_object v1component)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1component)) { goto L1; }
  if (!(ECL_STRINGP(v1component))) { goto L3; }
  value0 = cl_gethash(2, v1component, ecl_symbol_value(VV[131]));
  return value0;
L3:;
  if (Null(cl_pathnamep(v1component))) { goto L5; }
  T0 = cl_namestring(v1component);
  value0 = cl_gethash(2, T0, ecl_symbol_value(VV[131]));
  return value0;
L5:;
  if (Null(si_of_class_p(2, v1component, VV[89]))) { goto L7; }
  {
   cl_object v2;
   v2 = ecl_function_dispatch(cl_env_copy,VV[141])(1, v1component) /*  COMPONENT-TYPE */;
   if (!(ecl_eql(v2,VV[132]))) { goto L10; }
   {
    cl_object v3name;
    cl_object v4path;
    v3name = ecl_function_dispatch(cl_env_copy,VV[142])(1, v1component) /*  COMPONENT-NAME */;
    {
     cl_object v5;
     if (Null(v3name)) { goto L15; }
     v5 = L56compute_system_path(v3name, ECL_NIL);
     goto L14;
L15:;
     v5 = ECL_NIL;
L14:;
     value0 = ecl_make_bool(ECL_STRINGP(v5));
     if ((value0)!=ECL_NIL) { goto L20; }
     value0 = cl_pathnamep(v5);
     if ((value0)!=ECL_NIL) { goto L20; }
     T0 = ecl_make_bool(v5==ECL_NIL);
     goto L18;
L20:;
     T0 = value0;
     goto L18;
L18:;
     if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[133],v5);
     v4path = v5;
    }
    if (Null(v4path)) { goto L23; }
    T0 = cl_namestring(v4path);
    value0 = cl_gethash(2, T0, ecl_symbol_value(VV[131]));
    return value0;
L23:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L10:;
   if (!(ecl_eql(v2,ECL_SYM("FILE",1237)))) { goto L30; }
   goto L27;
   goto L28;
L30:;
   goto L28;
L28:;
   if (!(ecl_eql(v2,VV[135]))) { goto L25; }
   goto L26;
L27:;
L26:;
   {
    cl_object v5path;
    v5path = L69component_full_pathname(2, v1component, VV[137]);
    if (Null(v5path)) { goto L34; }
    value0 = cl_gethash(2, v5path, ecl_symbol_value(VV[131]));
    return value0;
L34:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L25:;
   value0 = si_ecase_error(v2, VV[138]);
   return value0;
  }
L7:;
  value0 = si_etypecase_error(v1component, VV[139]);
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function COMPONENT-LOAD-TIME                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC55component_load_time(cl_object v1value, cl_object v2component)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(3, ECL_SYM("GETHASH",413), v2component, VV[131]);
  T1 = cl_list(3, ECL_SYM("SETF",750), T0, v1value);
  T2 = cl_list(2, ECL_SYM("STRING",805), T1);
  T3 = cl_list(3, ECL_SYM("THE",856), ECL_SYM("PATHNAME",630), v2component);
  T4 = cl_list(2, ECL_SYM("NAMESTRING",579), T3);
  T5 = cl_list(3, ECL_SYM("GETHASH",413), T4, VV[131]);
  T6 = cl_list(3, ECL_SYM("SETF",750), T5, v1value);
  T7 = cl_list(2, ECL_SYM("PATHNAME",630), T6);
  T8 = cl_list(2, VV[141], v2component);
  T9 = cl_list(2, VV[142], v2component);
  T10 = cl_list(2, VV[114], T9);
  T11 = cl_list(2, T10, VV[143]);
  T12 = cl_list(3, ECL_SYM("SETF",750), VV[146], v1value);
  T13 = cl_list(3, ECL_SYM("WHEN",905), VV[145], T12);
  T14 = cl_list(4, ECL_SYM("LET*",478), T11, VV[144], T13);
  T15 = cl_list(2, VV[132], T14);
  T16 = cl_list(3, VV[147], v2component, VV[137]);
  T17 = cl_list(2, VV[145], T16);
  T18 = ecl_list1(T17);
  T19 = cl_list(3, ECL_SYM("SETF",750), VV[148], v1value);
  T20 = cl_list(3, ECL_SYM("WHEN",905), VV[145], T19);
  T21 = cl_list(3, ECL_SYM("LET",477), T18, T20);
  T22 = cl_list(2, VV[134], T21);
  T23 = cl_list(4, ECL_SYM("ECASE",321), T8, T15, T22);
  T24 = cl_list(2, VV[89], T23);
  T25 = cl_list(5, ECL_SYM("ETYPECASE",338), v2component, T2, T7, T24);
  value0 = cl_list(4, ECL_SYM("WHEN",905), v2component, T25, v1value);
  return value0;
 }
}
/*	function definition for COMPUTE-SYSTEM-PATH                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L56compute_system_path(cl_object v1module_name, cl_object v2definition_pname)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3module_string_name;
   cl_object v4file_pathname;
   cl_object v5lib_file_pathname;
   if (!(ECL_SYMBOLP(v1module_name))) { goto L2; }
   T0 = cl_string(v1module_name);
   v3module_string_name = cl_string_downcase(1, T0);
   goto L1;
L2:;
   if (!(ECL_STRINGP(v1module_name))) { goto L4; }
   v3module_string_name = v1module_name;
   goto L1;
L4:;
   v3module_string_name = si_etypecase_error(v1module_name, VV[149]);
L1:;
   v4file_pathname = cl_make_pathname(4, ECL_SYM("NAME",1273), v3module_string_name, ECL_SYM("TYPE",1318), ecl_symbol_value(VV[31]));
   T0 = cl_list(2, ECL_SYM("RELATIVE",1299), v3module_string_name);
   v5lib_file_pathname = cl_make_pathname(6, ECL_SYM("DIRECTORY",1219), T0, ECL_SYM("NAME",1273), v3module_string_name, ECL_SYM("TYPE",1318), ecl_symbol_value(VV[31]));
   if (Null(v2definition_pname)) { goto L11; }
   value0 = cl_probe_file(v2definition_pname);
   goto L10;
L11:;
   value0 = ECL_NIL;
L10:;
   if ((value0)!=ECL_NIL) { goto L9; }
   if (Null(ecl_symbol_value(VV[9]))) { goto L13; }
   if (!(ECL_LISTP(ecl_symbol_value(VV[9])))) { goto L15; }
   {
    cl_object v6;
    v6 = ecl_symbol_value(VV[9]);
    goto L20;
L19:;
    {
     cl_object v7registry;
     v7registry = ecl_car(v6);
     {
      cl_object v8reg_path;
      cl_object v9file;
      v8reg_path = L3registry_pathname(v7registry);
      T0 = L30append_directories(v8reg_path, v4file_pathname);
      value0 = cl_probe_file(T0);
      if ((value0)!=ECL_NIL) { goto L28; }
      T0 = L30append_directories(v8reg_path, v5lib_file_pathname);
      v9file = cl_probe_file(T0);
      goto L26;
L28:;
      v9file = value0;
      goto L26;
L26:;
      if (Null(v9file)) { goto L24; }
      value0 = v9file;
      cl_env_copy->nvalues = 1;
      return value0;
     }
L24:;
    }
    v6 = ecl_cdr(v6);
L20:;
    if (Null(v6)) { goto L33; }
    goto L19;
L33:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L15:;
   T0 = L30append_directories(ecl_symbol_value(VV[9]), v4file_pathname);
   value0 = cl_probe_file(T0);
   if ((value0)!=ECL_NIL) { goto L36; }
   T0 = L30append_directories(ecl_symbol_value(VV[9]), v5lib_file_pathname);
   value0 = cl_probe_file(T0);
   return value0;
L36:;
   cl_env_copy->nvalues = 1;
   return value0;
L13:;
   value0 = cl_probe_file(v4file_pathname);
   if ((value0)!=ECL_NIL) { goto L39; }
   value0 = cl_probe_file(v5lib_file_pathname);
   return value0;
L39:;
   cl_env_copy->nvalues = 1;
   return value0;
L9:;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for SYSTEM-DEFINITION-PATHNAME            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L58system_definition_pathname(cl_object volatile v1system_name)
{
 cl_object T0, T1, T2, T3;
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   volatile cl_object v2system;
   {
    volatile cl_object env1 = env0;
    env1 = ECL_NIL;
    CLV0 = env1 = CONS(ECL_NIL,env1);
    {
     volatile cl_object env2 = env1;
     CLV1 = env2 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env2); /*  TAGBODY */
     if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV1))) {
     if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L2;
     ecl_internal_error("GO found an inexistent tag");
     }
     {cl_object v3;
      v3 = ECL_NIL;
      v3 = ecl_make_cclosure_va((cl_objectfn)LC57__g160,env2,Cblock);
      T0 = v3;
     }
     T1 = CONS(ECL_SYM("ERROR",337),T0);
     T2 = ecl_list1(T1);
     T3 = CONS(T2,ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5)));
     ecl_bds_bind(cl_env_copy,ECL_SYM("*HANDLER-CLUSTERS*",5),T3); /*  *HANDLER-CLUSTERS* */
     value0 = L59find_system(2, v1system_name, ECL_SYM("ERROR",1229));
     ecl_frs_pop(cl_env_copy);
     v2system = value0;
     ecl_bds_unwind1(cl_env_copy);
     goto L1;
L2:;
     {
      cl_object v3condition;
      v3condition = ECL_CONS_CAR(CLV0);
      cl_env_copy->nvalues = 2;
      cl_env_copy->values[1] = v3condition;
      cl_env_copy->values[0] = ECL_NIL;
      value0 = cl_env_copy->values[0];
      ecl_frs_pop(cl_env_copy);
      v2system = value0;
      goto L1;
     }
    }
   }
L1:;
   if (Null(v2system)) { goto L7; }
   {
    cl_object v3system_def_pathname;
    T0 = L69component_full_pathname(2, v2system, VV[137]);
    T1 = cl_pathname(T0);
    v3system_def_pathname = cl_make_pathname(4, ECL_SYM("TYPE",1318), _ecl_static_8, ECL_SYM("DEFAULTS",1216), T1);
    T0 = cl_probe_file(v3system_def_pathname);
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = T0;
    cl_env_copy->values[0] = v3system_def_pathname;
    return cl_env_copy->values[0];
   }
L7:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = ECL_NIL;
   cl_env_copy->values[0] = ECL_NIL;
   return cl_env_copy->values[0];
  }
 }
}
/*	closure G160                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC57__g160(cl_narg narg, cl_object v1si__temp, ...)
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
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  ECL_CONS_CAR(CLV0) = v1si__temp;
  cl_go(ECL_CONS_CAR(CLV1),ecl_make_fixnum(0));
 }
 }
}
/*	function definition for FIND-SYSTEM                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L59find_system(cl_narg narg, cl_object v1system_name, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v2mode;
  cl_object v3definition_pname;
  va_list args; va_start(args,v1system_name);
  {
   int i = 1;
   if (i >= narg) {
    v2mode = VV[153];
   } else {
    i++;
    v2mode = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v3definition_pname = ECL_NIL;
   } else {
    i++;
    v3definition_pname = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (!(ecl_eql(v2mode,VV[153]))) { goto L3; }
  value0 = L20get_system(v1system_name);
  if ((value0)!=ECL_NIL) { goto L6; }
  if (Null(L98y_or_n_p_wait(4, CODE_CHAR(121), ecl_make_fixnum(20), _ecl_static_83, v1system_name))) { goto L8; }
  value0 = L59find_system(3, v1system_name, VV[154], v3definition_pname);
  return value0;
L8:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L6:;
  cl_env_copy->nvalues = 1;
  return value0;
L3:;
  if (!(ecl_eql(v2mode,ECL_SYM("ERROR",1229)))) { goto L10; }
  value0 = L20get_system(v1system_name);
  if ((value0)!=ECL_NIL) { goto L13; }
  value0 = cl_error(3, VV[130], ECL_SYM("NAME",1273), v1system_name);
  return value0;
L13:;
  cl_env_copy->nvalues = 1;
  return value0;
L10:;
  if (!(ecl_eql(v2mode,VV[155]))) { goto L15; }
  {
   cl_object v4system;
   v4system = L20get_system(v1system_name);
   if ((ecl_symbol_value(VV[152]))!=ECL_NIL) { goto L21; }
   value0 = v4system;
   goto L20;
L21:;
   value0 = ECL_NIL;
L20:;
   if ((value0)!=ECL_NIL) { goto L19; }
   if (Null(ecl_function_dispatch(cl_env_copy,VV[121])(1, v4system) /*  FOREIGN-SYSTEM-P */)) { goto L24; }
   (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(2, _ecl_static_84, v4system) /*  WARN */;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L24:;
   value0 = ECL_NIL;
   if ((value0)!=ECL_NIL) { goto L19; }
   {
    cl_object v5path;
    v5path = L56compute_system_path(v1system_name, v3definition_pname);
    if (Null(v5path)) { goto L29; }
    if (v4system==ECL_NIL) { goto L32; }
    T0 = L54component_load_time(v5path);
    if (T0==ECL_NIL) { goto L32; }
    T0 = L54component_load_time(v5path);
    T1 = cl_file_write_date(v5path);
    if (!(ecl_number_compare(T0,T1)<0)) { goto L29; }
    goto L30;
L32:;
L30:;
    T0 = cl_format(4, ECL_NIL, _ecl_static_85, v1system_name, v5path);
    L95tell_user_generic(T0);
    cl_load(1, v5path);
    v4system = L20get_system(v1system_name);
    if (Null(v4system)) { goto L29; }
    {
     cl_object v6;
     v6 = cl_file_write_date(v5path);
     if (Null(v5path)) { goto L29; }
     if (!(ECL_STRINGP(v5path))) { goto L43; }
     si_hash_set(v5path, ecl_symbol_value(VV[131]), v6);
     goto L42;
L43:;
     if (Null(cl_pathnamep(v5path))) { goto L45; }
     T1 = cl_pathnamep(v5path);
     if (ecl_unlikely(!((T1)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("PATHNAME",630),v5path);
     T0 = v5path;
     T1 = cl_namestring(T0);
     si_hash_set(T1, ecl_symbol_value(VV[131]), v6);
     goto L42;
L45:;
     if (Null(si_of_class_p(2, v5path, VV[89]))) { goto L49; }
     {
      cl_object v7;
      v7 = ecl_function_dispatch(cl_env_copy,VV[141])(1, v5path) /*  COMPONENT-TYPE */;
      if (!(ecl_eql(v7,VV[132]))) { goto L52; }
      {
       cl_object v8name;
       cl_object v9path;
       v8name = ecl_function_dispatch(cl_env_copy,VV[142])(1, v5path) /*  COMPONENT-NAME */;
       {
        cl_object v10;
        if (Null(v8name)) { goto L57; }
        v10 = L56compute_system_path(v8name, ECL_NIL);
        goto L56;
L57:;
        v10 = ECL_NIL;
L56:;
        value0 = ecl_make_bool(ECL_STRINGP(v10));
        if ((value0)!=ECL_NIL) { goto L62; }
        value0 = cl_pathnamep(v10);
        if ((value0)!=ECL_NIL) { goto L62; }
        T0 = ecl_make_bool(v10==ECL_NIL);
        goto L60;
L62:;
        T0 = value0;
        goto L60;
L60:;
        if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[133],v10);
        v9path = v10;
       }
       if (Null(v9path)) { goto L42; }
       T0 = cl_namestring(v9path);
       si_hash_set(T0, ecl_symbol_value(VV[131]), v6);
       goto L42;
      }
L52:;
      if (!(ecl_eql(v7,ECL_SYM("FILE",1237)))) { goto L71; }
      goto L68;
      goto L69;
L71:;
      goto L69;
L69:;
      if (!(ecl_eql(v7,VV[135]))) { goto L66; }
      goto L67;
L68:;
L67:;
      {
       cl_object v10path;
       v10path = L69component_full_pathname(2, v5path, VV[137]);
       if (Null(v10path)) { goto L42; }
       si_hash_set(v10path, ecl_symbol_value(VV[131]), v6);
       goto L42;
      }
L66:;
      si_ecase_error(v7, VV[138]);
      goto L42;
     }
L49:;
     si_etypecase_error(v5path, VV[139]);
L42:;
    }
L29:;
    value0 = v4system;
   }
   if ((value0)!=ECL_NIL) { goto L19; }
   value0 = v4system;
   cl_env_copy->nvalues = 1;
   return value0;
L19:;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L15:;
  if (!(ecl_eql(v2mode,VV[154]))) { goto L76; }
  if ((ecl_symbol_value(VV[152]))!=ECL_NIL) { goto L81; }
  value0 = L20get_system(v1system_name);
  goto L80;
L81:;
  value0 = ECL_NIL;
L80:;
  if ((value0)!=ECL_NIL) { goto L79; }
  T0 = L20get_system(v1system_name);
  if (Null(ecl_function_dispatch(cl_env_copy,VV[121])(1, T0) /*  FOREIGN-SYSTEM-P */)) { goto L84; }
  T0 = L20get_system(v1system_name);
  (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(2, _ecl_static_84, T0) /*  WARN */;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L84:;
  value0 = ECL_NIL;
  if ((value0)!=ECL_NIL) { goto L79; }
  value0 = L59find_system(3, v1system_name, VV[155], v3definition_pname);
  if ((value0)!=ECL_NIL) { goto L88; }
  value0 = cl_error(2, _ecl_static_86, v1system_name);
  return value0;
L88:;
  cl_env_copy->nvalues = 1;
  return value0;
L79:;
  cl_env_copy->nvalues = 1;
  return value0;
L76:;
  value0 = si_ecase_error(v2mode, VV[156]);
  return value0;
 }
}
/*	function definition for PRINT-COMPONENT                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L60print_component(cl_object v1component, cl_object v2stream, cl_object v3depth)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[141])(1, v1component) /*  COMPONENT-TYPE */;
  T1 = ecl_function_dispatch(cl_env_copy,VV[142])(1, v1component) /*  COMPONENT-NAME */;
  value0 = cl_format(4, v2stream, _ecl_static_87, T0, T1);
  return value0;
 }
}
/*	function definition for DESCRIBE-SYSTEM                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L61describe_system(cl_narg narg, cl_object v1name, ...)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2stream;
  va_list args; va_start(args,v1name);
  {
   int i = 1;
   if (i >= narg) {
    v2stream = ecl_symbol_value(ECL_SYM("*STANDARD-OUTPUT*",67));
   } else {
    i++;
    v2stream = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v3system;
   if (Null(si_of_class_p(2, v1name, VV[89]))) { goto L3; }
   v3system = v1name;
   goto L2;
L3:;
   v3system = L59find_system(2, v1name, VV[154]);
L2:;
   T0 = ecl_function_dispatch(cl_env_copy,VV[141])(1, v3system) /*  COMPONENT-TYPE */;
   T1 = ecl_function_dispatch(cl_env_copy,VV[142])(1, v3system) /*  COMPONENT-NAME */;
   T2 = ecl_function_dispatch(cl_env_copy,VV[471])(1, v3system) /*  COMPONENT-HOST */;
   T3 = ecl_function_dispatch(cl_env_copy,VV[472])(1, v3system) /*  COMPONENT-DEVICE */;
   T4 = ecl_function_dispatch(cl_env_copy,VV[473])(1, v3system) /*  COMPONENT-PACKAGE */;
   T5 = L66component_root_dir(v3system, VV[137]);
   T6 = L63component_pathname(v3system, VV[137]);
   T7 = L72component_extension(2, v3system, VV[137]);
   T8 = L66component_root_dir(v3system, VV[159]);
   T9 = L63component_pathname(v3system, VV[159]);
   T10 = L72component_extension(2, v3system, VV[159]);
   T11 = ecl_function_dispatch(cl_env_copy,VV[474])(1, v3system) /*  COMPONENT-DEPENDS-ON */;
   T12 = ecl_function_dispatch(cl_env_copy,VV[475])(1, v3system) /*  COMPONENT-COMPONENTS */;
   cl_format(15, v2stream, _ecl_static_88, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12);
   value0 = v3system;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for CANONICALIZE-COMPONENT-NAME           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L62canonicalize_component_name(cl_object v1component)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[142])(1, v1component) /*  COMPONENT-NAME */;
  if (!(ECL_STRINGP(T0))) { goto L1; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[142])(1, v1component) /*  COMPONENT-NAME */;
  return value0;
L1:;
  {
   cl_object v2;
   T0 = ecl_function_dispatch(cl_env_copy,VV[142])(1, v1component) /*  COMPONENT-NAME */;
   T1 = cl_string(T0);
   v2 = cl_string_downcase(1, T1);
   value0 = ecl_structure_set(v1component,VV[89],2,v2);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for COMPONENT-PATHNAME                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L63component_pathname(cl_object v1component, cl_object v2type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1component)) { goto L1; }
  if (!(ecl_eql(v2type,VV[137]))) { goto L3; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[165])(1, v1component) /*  COMPONENT-SOURCE-PATHNAME */;
  return value0;
L3:;
  if (!(ecl_eql(v2type,VV[159]))) { goto L5; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[166])(1, v1component) /*  COMPONENT-BINARY-PATHNAME */;
  return value0;
L5:;
  if (!(ecl_eql(v2type,ECL_SYM("ERROR",1229)))) { goto L7; }
  value0 = L64component_error_pathname(v1component);
  return value0;
L7:;
  value0 = si_ecase_error(v2type, VV[162]);
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for COMPONENT-ERROR-PATHNAME              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L64component_error_pathname(cl_object v1component)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2binary;
   v2binary = L63component_pathname(v1component, VV[159]);
   value0 = L35new_file_type(v2binary, ecl_symbol_value(VV[26]));
   return value0;
  }
 }
}
/*	local function COMPONENT-PATHNAME                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC65component_pathname(cl_object v1value, cl_object v2component, cl_object v3type)
{
 cl_object T0, T1, T2, T3, T4, T5, T6;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, VV[165], v2component);
  T1 = cl_list(3, ECL_SYM("SETF",750), T0, v1value);
  T2 = cl_list(2, VV[137], T1);
  T3 = cl_list(2, VV[166], v2component);
  T4 = cl_list(3, ECL_SYM("SETF",750), T3, v1value);
  T5 = cl_list(2, VV[159], T4);
  T6 = cl_list(4, ECL_SYM("ECASE",321), v3type, T2, T5);
  value0 = cl_list(3, ECL_SYM("WHEN",905), v2component, T6);
  return value0;
 }
}
/*	function definition for COMPONENT-ROOT-DIR                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L66component_root_dir(cl_object v1component, cl_object v2type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1component)) { goto L1; }
  if (!(ecl_eql(v2type,VV[137]))) { goto L3; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[171])(1, v1component) /*  COMPONENT-SOURCE-ROOT-DIR */;
  return value0;
L3:;
  if (!(ecl_eql(v2type,VV[159]))) { goto L10; }
  goto L7;
  goto L8;
L10:;
  goto L8;
L8:;
  if (!(ecl_eql(v2type,ECL_SYM("ERROR",1229)))) { goto L5; }
  goto L6;
L7:;
L6:;
  value0 = ecl_function_dispatch(cl_env_copy,VV[172])(1, v1component) /*  COMPONENT-BINARY-ROOT-DIR */;
  return value0;
L5:;
  value0 = si_ecase_error(v2type, VV[169]);
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function COMPONENT-ROOT-DIR                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC67component_root_dir(cl_object v1value, cl_object v2component, cl_object v3type)
{
 cl_object T0, T1, T2, T3, T4, T5, T6;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, VV[171], v2component);
  T1 = cl_list(3, ECL_SYM("SETF",750), T0, v1value);
  T2 = cl_list(2, VV[137], T1);
  T3 = cl_list(2, VV[172], v2component);
  T4 = cl_list(3, ECL_SYM("SETF",750), T3, v1value);
  T5 = cl_list(2, VV[159], T4);
  T6 = cl_list(4, ECL_SYM("ECASE",321), v3type, T2, T5);
  value0 = cl_list(3, ECL_SYM("WHEN",905), v2component, T6);
  return value0;
 }
}
/*	function definition for CLEAR-FULL-PATHNAME-TABLES            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L68clear_full_pathname_tables()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  cl_clrhash(ecl_symbol_value(VV[173]));
  value0 = cl_clrhash(ecl_symbol_value(VV[174]));
  return value0;
 }
}
/*	function definition for COMPONENT-FULL-PATHNAME               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L69component_full_pathname(cl_narg narg, cl_object v1component, cl_object v2type, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v3version;
  va_list args; va_start(args,v2type);
  {
   int i = 2;
   if (i >= narg) {
    v3version = ecl_symbol_value(VV[36]);
   } else {
    i++;
    v3version = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (Null(v1component)) { goto L2; }
  if (!(ecl_eql(v2type,VV[137]))) { goto L4; }
  {
   cl_object v4old;
   v4old = ecl_gethash_safe(v1component,ecl_symbol_value(VV[173]),ECL_NIL);
   value0 = v4old;
   if ((value0)!=ECL_NIL) { goto L8; }
   {
    cl_object v5new;
    v5new = L70component_full_pathname_i(3, v1component, v2type, v3version);
    si_hash_set(v1component, ecl_symbol_value(VV[173]), v5new);
    value0 = v5new;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L8:;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L4:;
  if (!(ecl_eql(v2type,VV[159]))) { goto L12; }
  {
   cl_object v6old;
   v6old = ecl_gethash_safe(v1component,ecl_symbol_value(VV[174]),ECL_NIL);
   value0 = v6old;
   if ((value0)!=ECL_NIL) { goto L16; }
   {
    cl_object v7new;
    v7new = L70component_full_pathname_i(3, v1component, v2type, v3version);
    si_hash_set(v1component, ecl_symbol_value(VV[174]), v7new);
    value0 = v7new;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L16:;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L12:;
  value0 = L70component_full_pathname_i(3, v1component, v2type, v3version);
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for COMPONENT-FULL-PATHNAME-I             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L70component_full_pathname_i(cl_narg narg, cl_object v1component, cl_object v2type, ...)
{
 cl_object T0, T1, T2, T3, T4, T5;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v3version;
  va_list args; va_start(args,v2type);
  {
   int i = 2;
   if (i >= narg) {
    v3version = ecl_symbol_value(VV[36]);
   } else {
    i++;
    v3version = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v4version_dir;
   cl_object v5version_replace;
   v4version_dir = ECL_NIL;
   v5version_replace = ECL_NIL;
   if (Null(v3version)) { goto L5; }
   value0 = L71translate_version(v3version);
   v4version_dir = value0;
   {
    const int v6 = cl_env_copy->nvalues;
    cl_object v7;
    v7 = (v6<=1)? ECL_NIL : cl_env_copy->values[1];
    v5version_replace = v7;
   }
   goto L4;
L5:;
   v4version_dir = ecl_symbol_value(VV[34]);
   v5version_replace = ecl_symbol_value(VV[35]);
L4:;
   {
    cl_object v6pathname;
    if (Null(v5version_replace)) { goto L13; }
    T0 = v4version_dir;
    goto L12;
L13:;
    T1 = L66component_root_dir(v1component, v2type);
    T0 = L30append_directories(T1, v4version_dir);
L12:;
    T1 = L63component_pathname(v1component, v2type);
    v6pathname = L30append_directories(T0, T1);
    if (Null(L32pathname_logical_p(v6pathname))) { goto L15; }
    T0 = ecl_function_dispatch(cl_env_copy,VV[142])(1, v1component) /*  COMPONENT-NAME */;
    T1 = L72component_extension(2, v1component, v2type);
    T2 = cl_make_pathname(4, ECL_SYM("NAME",1273), T0, ECL_SYM("TYPE",1318), T1);
    v6pathname = cl_merge_pathnames(2, v6pathname, T2);
    T0 = cl_translate_logical_pathname(1, v6pathname);
    value0 = cl_namestring(T0);
    return value0;
L15:;
    value0 = ecl_function_dispatch(cl_env_copy,VV[471])(1, v1component) /*  COMPONENT-HOST */;
    if ((value0)!=ECL_NIL) { goto L21; }
    T0 = cl_pathname_host(1, v6pathname);
    goto L19;
L21:;
    T0 = value0;
    goto L19;
L19:;
    T1 = cl_pathname_directory(1, v6pathname);
    value0 = cl_pathname_name(1, v6pathname);
    if ((value0)!=ECL_NIL) { goto L25; }
    T2 = ecl_function_dispatch(cl_env_copy,VV[142])(1, v1component) /*  COMPONENT-NAME */;
    goto L23;
L25:;
    T2 = value0;
    goto L23;
L23:;
    T3 = L72component_extension(2, v1component, v2type);
    value0 = ecl_function_dispatch(cl_env_copy,VV[472])(1, v1component) /*  COMPONENT-DEVICE */;
    if ((value0)!=ECL_NIL) { goto L29; }
    T4 = cl_pathname_device(1, v6pathname);
    goto L27;
L29:;
    T4 = value0;
    goto L27;
L27:;
    T5 = cl_make_pathname(10, ECL_SYM("HOST",1243), T0, ECL_SYM("DIRECTORY",1219), T1, ECL_SYM("NAME",1273), T2, ECL_SYM("TYPE",1318), T3, ECL_SYM("DEVICE",1217), T4);
    value0 = cl_namestring(T5);
    return value0;
   }
  }
 }
}
/*	function definition for TRANSLATE-VERSION                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L71translate_version(cl_object v1version)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(v1version==ECL_NIL)) { goto L1; }
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = ECL_NIL;
  cl_env_copy->values[0] = _ecl_static_13;
  return cl_env_copy->values[0];
L1:;
  if (!(ECL_SYMBOLP(v1version))) { goto L3; }
  {
   cl_object v2sversion;
   v2sversion = cl_string(v1version);
   T1 = (ECL_SYM("LOWER-CASE-P",514)->symbol.gfdef);
   if (Null(cl_find_if(2, T1, v2sversion))) { goto L7; }
   T0 = v2sversion;
   goto L5;
L7:;
   T0 = cl_string_downcase(1, v2sversion);
  }
L5:;
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = ECL_NIL;
  cl_env_copy->values[0] = T0;
  return cl_env_copy->values[0];
L3:;
  if (!(ECL_STRINGP(v1version))) { goto L10; }
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = ECL_T;
  cl_env_copy->values[0] = v1version;
  return cl_env_copy->values[0];
L10:;
  value0 = cl_error(2, _ecl_static_89, v1version);
  return value0;
 }
}
/*	function definition for COMPONENT-EXTENSION                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L72component_extension(cl_narg narg, cl_object v1component, cl_object v2type, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3local;
  ecl_va_list args; ecl_va_start(args,v2type,narg,2);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L72component_extensionkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3local = keyvars[0];
  }
  if (!(ecl_eql(v2type,VV[137]))) { goto L1; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[181])(1, v1component) /*  COMPONENT-SOURCE-EXTENSION */;
  if ((value0)!=ECL_NIL) { goto L4; }
  if ((v3local)!=ECL_NIL) { goto L6; }
  value0 = L120default_source_extension(v1component);
  return value0;
L6:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L4:;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (!(ecl_eql(v2type,VV[159]))) { goto L8; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[182])(1, v1component) /*  COMPONENT-BINARY-EXTENSION */;
  if ((value0)!=ECL_NIL) { goto L11; }
  if ((v3local)!=ECL_NIL) { goto L13; }
  value0 = L121default_binary_extension(v1component);
  return value0;
L13:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L11:;
  cl_env_copy->nvalues = 1;
  return value0;
L8:;
  if (!(ecl_eql(v2type,ECL_SYM("ERROR",1229)))) { goto L15; }
  value0 = ecl_symbol_value(VV[26]);
  cl_env_copy->nvalues = 1;
  return value0;
L15:;
  value0 = si_ecase_error(v2type, VV[162]);
  return value0;
 }
}
/*	local function COMPONENT-EXTENSION                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC73component_extension(cl_object v1value, cl_object v2component, cl_object v3type)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, VV[181], v2component);
  T1 = cl_list(3, ECL_SYM("SETF",750), T0, v1value);
  T2 = cl_list(2, VV[137], T1);
  T3 = cl_list(2, VV[182], v2component);
  T4 = cl_list(3, ECL_SYM("SETF",750), T3, v1value);
  T5 = cl_list(2, VV[159], T4);
  T6 = cl_list(3, ECL_SYM("SETF",750), VV[26], v1value);
  T7 = cl_list(2, ECL_SYM("ERROR",1229), T6);
  value0 = cl_list(5, ECL_SYM("ECASE",321), v3type, T2, T5, T7);
  return value0;
 }
}
/*	function definition for CREATE-COMPONENT                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L74create_component(cl_narg narg, cl_object v1type, cl_object v2name, cl_object v3definition_body, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>5)) FEwrong_num_arguments_anonym();
 {
  cl_object v4parent;
  cl_object v5indent;
  va_list args; va_start(args,v3definition_body);
  {
   int i = 3;
   if (i >= narg) {
    v4parent = ECL_NIL;
   } else {
    i++;
    v4parent = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v5indent = ecl_make_fixnum(0);
   } else {
    i++;
    v5indent = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v6component;
   T0 = ecl_fdefinition(VV[118]);
   v6component = cl_apply(8, T0, ECL_SYM("TYPE",1318), v1type, ECL_SYM("NAME",1273), v2name, VV[183], v5indent, v3definition_body);
   {
    cl_object v7;
    v7 = si_make_seq_iterator(2, v3definition_body, ecl_make_fixnum(0));
L8:;
    if ((v7)!=ECL_NIL) { goto L10; }
    goto L6;
L10:;
    {
     cl_object v8;
     v8 = si_seq_iterator_ref(v3definition_body, v7);
     if (!(ecl_eql(VV[184],v8))) { goto L12; }
     if ((v8)!=ECL_NIL) { goto L5; }
     goto L6;
    }
L12:;
    v7 = si_seq_iterator_next(v3definition_body, v7);
    goto L8;
   }
L6:;
   {
    cl_object v7;
    if (Null(v4parent)) { goto L18; }
    v7 = ecl_function_dispatch(cl_env_copy,VV[487])(1, v4parent) /*  COMPONENT-LOAD-ONLY */;
    goto L17;
L18:;
    v7 = ECL_NIL;
L17:;
    ecl_structure_set(v6component,VV[89],24,v7);
   }
L5:;
   {
    cl_object v7;
    v7 = si_make_seq_iterator(2, v3definition_body, ecl_make_fixnum(0));
L23:;
    if ((v7)!=ECL_NIL) { goto L25; }
    goto L21;
L25:;
    {
     cl_object v8;
     v8 = si_seq_iterator_ref(v3definition_body, v7);
     if (!(ecl_eql(VV[185],v8))) { goto L27; }
     if ((v8)!=ECL_NIL) { goto L20; }
     goto L21;
    }
L27:;
    v7 = si_seq_iterator_next(v3definition_body, v7);
    goto L23;
   }
L21:;
   {
    cl_object v7;
    if (Null(v4parent)) { goto L33; }
    v7 = ecl_function_dispatch(cl_env_copy,VV[488])(1, v4parent) /*  COMPONENT-COMPILE-ONLY */;
    goto L32;
L33:;
    v7 = ECL_NIL;
L32:;
    ecl_structure_set(v6component,VV[89],25,v7);
   }
L20:;
   {
    cl_object v7;
    v7 = si_make_seq_iterator(2, v3definition_body, ecl_make_fixnum(0));
L38:;
    if ((v7)!=ECL_NIL) { goto L40; }
    goto L36;
L40:;
    {
     cl_object v8;
     v8 = si_seq_iterator_ref(v3definition_body, v7);
     if (!(ecl_eql(VV[186],v8))) { goto L42; }
     if ((v8)!=ECL_NIL) { goto L35; }
     goto L36;
    }
L42:;
    v7 = si_seq_iterator_next(v3definition_body, v7);
    goto L38;
   }
L36:;
   {
    cl_object v7;
    if (Null(v4parent)) { goto L48; }
    v7 = ecl_function_dispatch(cl_env_copy,VV[489])(1, v4parent) /*  COMPONENT-COMPILER-OPTIONS */;
    goto L47;
L48:;
    v7 = ECL_NIL;
L47:;
    ecl_structure_set(v6component,VV[89],16,v7);
   }
L35:;
   {
    cl_object v7;
    v7 = si_make_seq_iterator(2, v3definition_body, ecl_make_fixnum(0));
L53:;
    if ((v7)!=ECL_NIL) { goto L55; }
    goto L51;
L55:;
    {
     cl_object v8;
     v8 = si_seq_iterator_ref(v3definition_body, v7);
     if (!(ecl_eql(VV[187],v8))) { goto L57; }
     if ((v8)!=ECL_NIL) { goto L50; }
     goto L51;
    }
L57:;
    v7 = si_seq_iterator_next(v3definition_body, v7);
    goto L53;
   }
L51:;
   {
    cl_object v7;
    if (Null(v4parent)) { goto L63; }
    v7 = ecl_function_dispatch(cl_env_copy,VV[490])(1, v4parent) /*  COMPONENT-LOAD-ALWAYS */;
    goto L62;
L63:;
    v7 = ECL_NIL;
L62:;
    ecl_structure_set(v6component,VV[89],26,v7);
   }
L50:;
   L62canonicalize_component_name(v6component);
   {
    cl_object v7;
    value0 = ecl_function_dispatch(cl_env_copy,VV[473])(1, v6component) /*  COMPONENT-PACKAGE */;
    if ((value0)!=ECL_NIL) { goto L69; }
    if (Null(v4parent)) { goto L71; }
    v7 = ecl_function_dispatch(cl_env_copy,VV[473])(1, v4parent) /*  COMPONENT-PACKAGE */;
    goto L67;
L71:;
    v7 = ECL_NIL;
    goto L67;
L69:;
    v7 = value0;
    goto L67;
L67:;
    ecl_structure_set(v6component,VV[89],12,v7);
   }
   if ((v1type)==(VV[132])) { goto L75; }
   if ((v1type)==(VV[122])) { goto L75; }
   if (!((v1type)==(VV[188]))) { goto L73; }
   goto L74;
L75:;
L74:;
   T0 = L19canonicalize_system_name(v2name);
   si_hash_set(T0, ecl_symbol_value(VV[55]), v6component);
L73:;
   L77create_component_pathnames(v6component, v4parent);
   T0 = ecl_plus(v5indent,ecl_make_fixnum(2));
   L79expand_component_components(2, v6component, T0);
   T0 = ecl_function_dispatch(cl_env_copy,VV[475])(1, v6component) /*  COMPONENT-COMPONENTS */;
   L84link_component_depends_on(T0);
   {
    cl_object v7;
    T0 = ecl_function_dispatch(cl_env_copy,VV[475])(1, v6component) /*  COMPONENT-COMPONENTS */;
    v7 = L86topological_sort(T0);
    ecl_structure_set(v6component,VV[89],17,v7);
   }
   value0 = v6component;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for PREPROCESS-COMPONENT-DEFINITION       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L75preprocess_component_definition(cl_object v1definition_body)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   cl_object v3slot;
   cl_object v4;
   v2 = ecl_symbol_value(VV[87]);
   v3slot = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v2))) FEtype_error_list(v2);
   v4 = v2;
   {
    cl_object v5value;
    v5value = ECL_NIL;
    {
     cl_object v6;
     cl_object v7;
     v6 = ecl_list1(ECL_NIL);
     v7 = v6;
L9:;
     if (!(ecl_endp(v4))) { goto L11; }
     goto L10;
L11:;
     v3slot = _ecl_car(v4);
     {
      cl_object v8;
      v8 = _ecl_cdr(v4);
      if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
      v4 = v8;
     }
     v5value = cl_getf(2, v1definition_body, v3slot);
     if (Null(v5value)) { goto L21; }
     {
      cl_object v9;
      cl_object v10;                              /*  FLAG            */
      value0 = si_rem_f(v1definition_body, v3slot);
      v9 = value0;
      v10 = cl_env_copy->values[1];
      v1definition_body = v9;
     }
     {
      cl_object v8;
      v8 = cl_list(2, v3slot, v5value);
      if (ecl_unlikely(ECL_ATOM(v7))) FEtype_error_cons(v7);
      T2 = v7;
      (ECL_CONS_CDR(T2)=v8,T2);
      T1 = v8;
     }
     v7 = ecl_cdr(T1);
L21:;
     goto L9;
L10:;
     T0 = ecl_cdr(v6);
     goto L1;
    }
   }
  }
L1:;
  {
   cl_object v2;
   cl_object v3slot;
   cl_object v4;
   v2 = ecl_symbol_value(VV[88]);
   v3slot = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v2))) FEtype_error_list(v2);
   v4 = v2;
   {
    cl_object v5;
    cl_object v6;
    v5 = ecl_list1(ECL_NIL);
    v6 = v5;
L42:;
    if (!(ecl_endp(v4))) { goto L44; }
    goto L43;
L44:;
    v3slot = _ecl_car(v4);
    {
     cl_object v7;
     v7 = _ecl_cdr(v4);
     if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
     v4 = v7;
    }
    {
     cl_object v8;
     cl_object v9;                                /*  FLAG            */
     value0 = si_rem_f(v1definition_body, v3slot);
     v8 = value0;
     v9 = cl_env_copy->values[1];
     v1definition_body = v8;
    }
    {
     cl_object v7;
     T3 = cl_getf(2, v1definition_body, v3slot);
     T4 = cl_list(3, ECL_SYM("LAMBDA",452), ECL_NIL, T3);
     v7 = cl_list(2, v3slot, T4);
     if (ecl_unlikely(ECL_ATOM(v6))) FEtype_error_cons(v6);
     T3 = v6;
     (ECL_CONS_CDR(T3)=v7,T3);
     T2 = v7;
    }
    v6 = ecl_cdr(T2);
    goto L42;
L43:;
    T1 = ecl_cdr(v5);
    goto L35;
   }
  }
L35:;
  T2 = cl_list(2, ECL_SYM("QUOTE",679), v1definition_body);
  T3 = ecl_list1(T2);
  T4 = cl_append(3, T0, T1, T3);
  value0 = CONS(ECL_SYM("LIST*",482),T4);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function DEFSYSTEM                                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC76defsystem(cl_object v1, cl_object v2)
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
   cl_object v5definition_body;
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
   v5definition_body = v3;
   {
    cl_object v6;
    v6 = si_make_seq_iterator(2, v5definition_body, ecl_make_fixnum(0));
L12:;
    if ((v6)!=ECL_NIL) { goto L14; }
    goto L10;
L14:;
    {
     cl_object v7;
     v7 = si_seq_iterator_ref(v5definition_body, v6);
     if (!(ecl_eql(VV[191],v7))) { goto L16; }
     if ((v7)!=ECL_NIL) { goto L9; }
     goto L10;
    }
L16:;
    v6 = si_seq_iterator_next(v5definition_body, v6);
    goto L12;
   }
L10:;
   v5definition_body = cl_listX(3, VV[191], VV[192], v5definition_body);
L9:;
   T0 = cl_list(2, ECL_SYM("QUOTE",679), v4name);
   T1 = L75preprocess_component_definition(v5definition_body);
   value0 = cl_listX(5, VV[189], VV[132], T0, T1, VV[193]);
   return value0;
  }
 }
}
/*	function definition for CREATE-COMPONENT-PATHNAMES            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L77create_component_pathnames(cl_object v1component, cl_object v2parent)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   value0 = ecl_function_dispatch(cl_env_copy,VV[494])(1, v1component) /*  COMPONENT-LANGUAGE */;
   if ((value0)!=ECL_NIL) { goto L4; }
   if (Null(v2parent)) { goto L6; }
   v3 = ecl_function_dispatch(cl_env_copy,VV[494])(1, v2parent) /*  COMPONENT-LANGUAGE */;
   goto L2;
L6:;
   v3 = ECL_NIL;
   goto L2;
L4:;
   v3 = value0;
   goto L2;
L2:;
   ecl_structure_set(v1component,VV[89],13,v3);
  }
  {
   cl_object v3;
   value0 = ecl_function_dispatch(cl_env_copy,VV[495])(1, v1component) /*  COMPONENT-COMPILER */;
   if ((value0)!=ECL_NIL) { goto L11; }
   if (Null(v2parent)) { goto L13; }
   v3 = ecl_function_dispatch(cl_env_copy,VV[495])(1, v2parent) /*  COMPONENT-COMPILER */;
   goto L9;
L13:;
   v3 = ECL_NIL;
   goto L9;
L11:;
   v3 = value0;
   goto L9;
L9:;
   ecl_structure_set(v1component,VV[89],14,v3);
  }
  {
   cl_object v3;
   value0 = ecl_function_dispatch(cl_env_copy,VV[496])(1, v1component) /*  COMPONENT-LOADER */;
   if ((value0)!=ECL_NIL) { goto L18; }
   if (Null(v2parent)) { goto L20; }
   v3 = ecl_function_dispatch(cl_env_copy,VV[496])(1, v2parent) /*  COMPONENT-LOADER */;
   goto L16;
L20:;
   v3 = ECL_NIL;
   goto L16;
L18:;
   v3 = value0;
   goto L16;
L16:;
   ecl_structure_set(v1component,VV[89],15,v3);
  }
  {
   cl_object v3;
   T0 = L66component_root_dir(v1component, VV[137]);
   v3 = cl_eval(T0);
   if (Null(v1component)) { goto L22; }
   if (!(ecl_eql(VV[137],VV[137]))) { goto L25; }
   ecl_structure_set(v1component,VV[89],6,v3);
   goto L22;
L25:;
   if (!(ecl_eql(VV[137],VV[159]))) { goto L27; }
   ecl_structure_set(v1component,VV[89],10,v3);
   goto L22;
L27:;
   si_ecase_error(VV[137], VV[195]);
  }
L22:;
  {
   cl_object v3;
   T0 = L66component_root_dir(v1component, VV[159]);
   v3 = cl_eval(T0);
   if (Null(v1component)) { goto L29; }
   if (!(ecl_eql(VV[159],VV[137]))) { goto L32; }
   ecl_structure_set(v1component,VV[89],6,v3);
   goto L29;
L32:;
   if (!(ecl_eql(VV[159],VV[159]))) { goto L34; }
   ecl_structure_set(v1component,VV[89],10,v3);
   goto L29;
L34:;
   si_ecase_error(VV[159], VV[195]);
  }
L29:;
  {
   cl_object v3;
   T0 = L63component_pathname(v1component, VV[137]);
   v3 = cl_eval(T0);
   if (Null(v1component)) { goto L36; }
   if (!(ecl_eql(VV[137],VV[137]))) { goto L39; }
   ecl_structure_set(v1component,VV[89],7,v3);
   goto L36;
L39:;
   if (!(ecl_eql(VV[137],VV[159]))) { goto L41; }
   ecl_structure_set(v1component,VV[89],9,v3);
   goto L36;
L41:;
   si_ecase_error(VV[137], VV[195]);
  }
L36:;
  {
   cl_object v3;
   T0 = L63component_pathname(v1component, VV[159]);
   v3 = cl_eval(T0);
   if (Null(v1component)) { goto L43; }
   if (!(ecl_eql(VV[159],VV[137]))) { goto L46; }
   ecl_structure_set(v1component,VV[89],7,v3);
   goto L43;
L46:;
   if (!(ecl_eql(VV[159],VV[159]))) { goto L48; }
   ecl_structure_set(v1component,VV[89],9,v3);
   goto L43;
L48:;
   si_ecase_error(VV[159], VV[195]);
  }
L43:;
  {
   cl_object v3;
   value0 = ecl_function_dispatch(cl_env_copy,VV[471])(1, v1component) /*  COMPONENT-HOST */;
   if ((value0)!=ECL_NIL) { goto L53; }
   if (Null(v2parent)) { goto L56; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[471])(1, v2parent) /*  COMPONENT-HOST */;
   goto L55;
L56:;
   value0 = ECL_NIL;
L55:;
   if ((value0)!=ECL_NIL) { goto L53; }
   v3 = cl_pathname_host(1, ecl_symbol_value(ECL_SYM("*DEFAULT-PATHNAME-DEFAULTS*",32)));
   goto L51;
L53:;
   v3 = value0;
   goto L51;
L51:;
   ecl_structure_set(v1component,VV[89],4,v3);
  }
  {
   cl_object v3;
   value0 = ecl_function_dispatch(cl_env_copy,VV[472])(1, v1component) /*  COMPONENT-DEVICE */;
   if ((value0)!=ECL_NIL) { goto L61; }
   if (Null(v2parent)) { goto L63; }
   v3 = ecl_function_dispatch(cl_env_copy,VV[472])(1, v2parent) /*  COMPONENT-DEVICE */;
   goto L59;
L63:;
   v3 = ECL_NIL;
   goto L59;
L61:;
   v3 = value0;
   goto L59;
L59:;
   ecl_structure_set(v1component,VV[89],5,v3);
  }
  {
   cl_object v3;
   value0 = L72component_extension(4, v1component, VV[137], ECL_SYM("LOCAL",1268), ECL_T);
   if ((value0)!=ECL_NIL) { goto L68; }
   if (Null(ecl_function_dispatch(cl_env_copy,VV[494])(1, v1component) /*  COMPONENT-LANGUAGE */)) { goto L71; }
   value0 = L120default_source_extension(v1component);
   goto L70;
L71:;
   value0 = ECL_NIL;
L70:;
   if ((value0)!=ECL_NIL) { goto L68; }
   if (Null(v2parent)) { goto L73; }
   v3 = L72component_extension(2, v2parent, VV[137]);
   goto L66;
L73:;
   v3 = ECL_NIL;
   goto L66;
L68:;
   v3 = value0;
   goto L66;
L66:;
   if (!(ecl_eql(VV[137],VV[137]))) { goto L75; }
   ecl_structure_set(v1component,VV[89],8,v3);
   goto L65;
L75:;
   if (!(ecl_eql(VV[137],VV[159]))) { goto L77; }
   ecl_structure_set(v1component,VV[89],11,v3);
   goto L65;
L77:;
   if (!(ecl_eql(VV[137],ECL_SYM("ERROR",1229)))) { goto L79; }
   cl_set(VV[26],v3);
   goto L65;
L79:;
   si_ecase_error(VV[137], VV[162]);
  }
L65:;
  {
   cl_object v3;
   value0 = L72component_extension(4, v1component, VV[159], ECL_SYM("LOCAL",1268), ECL_T);
   if ((value0)!=ECL_NIL) { goto L85; }
   if (Null(ecl_function_dispatch(cl_env_copy,VV[494])(1, v1component) /*  COMPONENT-LANGUAGE */)) { goto L88; }
   value0 = L121default_binary_extension(v1component);
   goto L87;
L88:;
   value0 = ECL_NIL;
L87:;
   if ((value0)!=ECL_NIL) { goto L85; }
   if (Null(v2parent)) { goto L90; }
   v3 = L72component_extension(2, v2parent, VV[159]);
   goto L83;
L90:;
   v3 = ECL_NIL;
   goto L83;
L85:;
   v3 = value0;
   goto L83;
L83:;
   if (!(ecl_eql(VV[159],VV[137]))) { goto L92; }
   ecl_structure_set(v1component,VV[89],8,v3);
   goto L82;
L92:;
   if (!(ecl_eql(VV[159],VV[159]))) { goto L94; }
   ecl_structure_set(v1component,VV[89],11,v3);
   goto L82;
L94:;
   if (!(ecl_eql(VV[159],ECL_SYM("ERROR",1229)))) { goto L96; }
   cl_set(VV[26],v3);
   goto L82;
L96:;
   si_ecase_error(VV[159], VV[162]);
  }
L82:;
  L78generate_component_pathname(v1component, v2parent, VV[137]);
  value0 = L78generate_component_pathname(v1component, v2parent, VV[159]);
  return value0;
 }
}
/*	function definition for GENERATE-COMPONENT-PATHNAME           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L78generate_component_pathname(cl_object v1component, cl_object v2parent, cl_object v3pathname_type)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4;
   v4 = ecl_function_dispatch(cl_env_copy,VV[141])(1, v1component) /*  COMPONENT-TYPE */;
   if (!(ecl_eql(v4,VV[132]))) { goto L7; }
   goto L4;
   goto L5;
L7:;
   goto L5;
L5:;
   if (!(ecl_eql(v4,VV[122]))) { goto L2; }
   goto L3;
L4:;
L3:;
   {
    cl_object v5;
    value0 = L63component_pathname(v1component, v3pathname_type);
    if ((value0)!=ECL_NIL) { goto L13; }
    if (!((v3pathname_type)==(VV[159]))) { goto L15; }
    v5 = L66component_root_dir(v1component, VV[137]);
    goto L11;
L15:;
    v5 = ECL_NIL;
    goto L11;
L13:;
    v5 = value0;
    goto L11;
L11:;
    if (Null(v1component)) { goto L10; }
    if (!(ecl_eql(v3pathname_type,VV[137]))) { goto L18; }
    ecl_structure_set(v1component,VV[89],6,v5);
    goto L10;
L18:;
    if (!(ecl_eql(v3pathname_type,VV[159]))) { goto L20; }
    ecl_structure_set(v1component,VV[89],10,v5);
    goto L10;
L20:;
    si_ecase_error(v3pathname_type, VV[195]);
   }
L10:;
   if (Null(v1component)) { goto L22; }
   if (!(ecl_eql(v3pathname_type,VV[137]))) { goto L24; }
   value0 = ecl_structure_set(v1component,VV[89],7,ECL_NIL);
   cl_env_copy->nvalues = 1;
   return value0;
L24:;
   if (!(ecl_eql(v3pathname_type,VV[159]))) { goto L26; }
   value0 = ecl_structure_set(v1component,VV[89],9,ECL_NIL);
   cl_env_copy->nvalues = 1;
   return value0;
L26:;
   value0 = si_ecase_error(v3pathname_type, VV[195]);
   return value0;
L22:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
   if (!(ecl_eql(v4,VV[135]))) { goto L28; }
   if (Null(v1component)) { goto L30; }
   if (!(ecl_eql(v3pathname_type,VV[137]))) { goto L32; }
   ecl_structure_set(v1component,VV[89],6,_ecl_static_13);
   goto L30;
L32:;
   if (!(ecl_eql(v3pathname_type,VV[159]))) { goto L34; }
   ecl_structure_set(v1component,VV[89],10,_ecl_static_13);
   goto L30;
L34:;
   si_ecase_error(v3pathname_type, VV[195]);
L30:;
   T0 = L63component_pathname(v1component, v3pathname_type);
   if (Null(L13null_string(T0))) { goto L36; }
   if (Null(v1component)) { goto L36; }
   if (!(ecl_eql(v3pathname_type,VV[137]))) { goto L39; }
   ecl_structure_set(v1component,VV[89],7,ECL_NIL);
   goto L36;
L39:;
   if (!(ecl_eql(v3pathname_type,VV[159]))) { goto L41; }
   ecl_structure_set(v1component,VV[89],9,ECL_NIL);
   goto L36;
L41:;
   si_ecase_error(v3pathname_type, VV[195]);
L36:;
   {
    cl_object v5;
    if (!((v3pathname_type)==(VV[159]))) { goto L47; }
    T0 = L63component_pathname(v1component, VV[159]);
    if (!(T0==ECL_NIL)) { goto L47; }
    value0 = L63component_pathname(v1component, VV[137]);
    goto L46;
L47:;
    value0 = ECL_NIL;
L46:;
    if ((value0)!=ECL_NIL) { goto L45; }
    if (Null(L63component_pathname(v1component, v3pathname_type))) { goto L53; }
    value0 = L63component_pathname(v1component, v3pathname_type);
    goto L52;
L53:;
    value0 = ECL_NIL;
L52:;
    if ((value0)!=ECL_NIL) { goto L51; }
    v5 = ecl_function_dispatch(cl_env_copy,VV[142])(1, v1component) /*  COMPONENT-NAME */;
    goto L43;
L51:;
    v5 = value0;
    goto L43;
L45:;
    v5 = value0;
    goto L43;
L43:;
    if (Null(v1component)) { goto L55; }
    if (!(ecl_eql(v3pathname_type,VV[137]))) { goto L57; }
    value0 = ecl_structure_set(v1component,VV[89],7,v5);
    cl_env_copy->nvalues = 1;
    return value0;
L57:;
    if (!(ecl_eql(v3pathname_type,VV[159]))) { goto L59; }
    value0 = ecl_structure_set(v1component,VV[89],9,v5);
    cl_env_copy->nvalues = 1;
    return value0;
L59:;
    value0 = si_ecase_error(v3pathname_type, VV[195]);
    return value0;
L55:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L28:;
   if (!(ecl_eql(v4,VV[199]))) { goto L66; }
   goto L63;
   goto L64;
L66:;
   goto L64;
L64:;
   if (!(ecl_eql(v4,VV[188]))) { goto L61; }
   goto L62;
L63:;
L62:;
   {
    cl_object v6;
    v6 = L66component_root_dir(v2parent, v3pathname_type);
    if (Null(v1component)) { goto L69; }
    if (!(ecl_eql(v3pathname_type,VV[137]))) { goto L72; }
    ecl_structure_set(v1component,VV[89],6,v6);
    goto L69;
L72:;
    if (!(ecl_eql(v3pathname_type,VV[159]))) { goto L74; }
    ecl_structure_set(v1component,VV[89],10,v6);
    goto L69;
L74:;
    si_ecase_error(v3pathname_type, VV[195]);
   }
L69:;
   {
    cl_object v6;
    if (!((v3pathname_type)==(VV[159]))) { goto L80; }
    T0 = L63component_pathname(v1component, VV[159]);
    if (!(T0==ECL_NIL)) { goto L80; }
    value0 = L63component_pathname(v1component, VV[137]);
    goto L79;
L80:;
    value0 = ECL_NIL;
L79:;
    if ((value0)!=ECL_NIL) { goto L78; }
    T0 = L63component_pathname(v2parent, v3pathname_type);
    value0 = L63component_pathname(v1component, v3pathname_type);
    if ((value0)!=ECL_NIL) { goto L85; }
    T1 = ecl_function_dispatch(cl_env_copy,VV[142])(1, v1component) /*  COMPONENT-NAME */;
    goto L83;
L85:;
    T1 = value0;
    goto L83;
L83:;
    v6 = L30append_directories(T0, T1);
    goto L76;
L78:;
    v6 = value0;
    goto L76;
L76:;
    if (Null(v1component)) { goto L87; }
    if (!(ecl_eql(v3pathname_type,VV[137]))) { goto L89; }
    value0 = ecl_structure_set(v1component,VV[89],7,v6);
    cl_env_copy->nvalues = 1;
    return value0;
L89:;
    if (!(ecl_eql(v3pathname_type,VV[159]))) { goto L91; }
    value0 = ecl_structure_set(v1component,VV[89],9,v6);
    cl_env_copy->nvalues = 1;
    return value0;
L91:;
    value0 = si_ecase_error(v3pathname_type, VV[195]);
    return value0;
L87:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L61:;
   if (!(ecl_eql(v4,ECL_SYM("FILE",1237)))) { goto L93; }
   {
    cl_object v7;
    v7 = L66component_root_dir(v2parent, v3pathname_type);
    if (Null(v1component)) { goto L95; }
    if (!(ecl_eql(v3pathname_type,VV[137]))) { goto L98; }
    ecl_structure_set(v1component,VV[89],6,v7);
    goto L95;
L98:;
    if (!(ecl_eql(v3pathname_type,VV[159]))) { goto L100; }
    ecl_structure_set(v1component,VV[89],10,v7);
    goto L95;
L100:;
    si_ecase_error(v3pathname_type, VV[195]);
   }
L95:;
   T0 = L63component_pathname(v1component, v3pathname_type);
   if (Null(L13null_string(T0))) { goto L102; }
   if (Null(v1component)) { goto L102; }
   if (!(ecl_eql(v3pathname_type,VV[137]))) { goto L105; }
   ecl_structure_set(v1component,VV[89],7,ECL_NIL);
   goto L102;
L105:;
   if (!(ecl_eql(v3pathname_type,VV[159]))) { goto L107; }
   ecl_structure_set(v1component,VV[89],9,ECL_NIL);
   goto L102;
L107:;
   si_ecase_error(v3pathname_type, VV[195]);
L102:;
   {
    cl_object v7;
    T0 = L63component_pathname(v2parent, v3pathname_type);
    value0 = L63component_pathname(v1component, v3pathname_type);
    if ((value0)!=ECL_NIL) { goto L112; }
    value0 = ecl_function_dispatch(cl_env_copy,VV[142])(1, v1component) /*  COMPONENT-NAME */;
    if ((value0)!=ECL_NIL) { goto L112; }
    if (!((v3pathname_type)==(VV[159]))) { goto L115; }
    T1 = L63component_pathname(v1component, VV[137]);
    goto L110;
L115:;
    T1 = ECL_NIL;
    goto L110;
L112:;
    T1 = value0;
    goto L110;
L110:;
    v7 = L30append_directories(T0, T1);
    if (Null(v1component)) { goto L117; }
    if (!(ecl_eql(v3pathname_type,VV[137]))) { goto L119; }
    value0 = ecl_structure_set(v1component,VV[89],7,v7);
    cl_env_copy->nvalues = 1;
    return value0;
L119:;
    if (!(ecl_eql(v3pathname_type,VV[159]))) { goto L121; }
    value0 = ecl_structure_set(v1component,VV[89],9,v7);
    cl_env_copy->nvalues = 1;
    return value0;
L121:;
    value0 = si_ecase_error(v3pathname_type, VV[195]);
    return value0;
L117:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L93:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for EXPAND-COMPONENT-COMPONENTS           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L79expand_component_components(cl_narg narg, cl_object v1component, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2indent;
  va_list args; va_start(args,v1component);
  {
   int i = 1;
   if (i >= narg) {
    v2indent = ecl_make_fixnum(0);
   } else {
    i++;
    v2indent = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v3definitions;
   v3definitions = ecl_function_dispatch(cl_env_copy,VV[475])(1, v1component) /*  COMPONENT-COMPONENTS */;
   T0 = ecl_car(v3definitions);
   if (!((T0)==(VV[203]))) { goto L3; }
   {
    cl_object v4;
    T0 = ecl_cdr(v3definitions);
    v4 = L81expand_serial_component_chain(3, T0, v1component, v2indent);
    value0 = ecl_structure_set(v1component,VV[89],17,v4);
    cl_env_copy->nvalues = 1;
    return value0;
   }
L3:;
   {
    cl_object v5;
    v5 = L80expand_component_definitions(3, v3definitions, v1component, v2indent);
    value0 = ecl_structure_set(v1component,VV[89],17,v5);
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for EXPAND-COMPONENT-DEFINITIONS          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L80expand_component_definitions(cl_narg narg, cl_object v1definitions, cl_object v2parent, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v3indent;
  va_list args; va_start(args,v2parent);
  {
   int i = 2;
   if (i >= narg) {
    v3indent = ecl_make_fixnum(0);
   } else {
    i++;
    v3indent = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v4components;
   v4components = ECL_NIL;
   {
    cl_object v5;
    v5 = v1definitions;
    goto L7;
L6:;
    {
     cl_object v6definition;
     v6definition = ecl_car(v5);
     {
      cl_object v7new;
      v7new = L83expand_component_definition(3, v6definition, v2parent, v3indent);
      if (Null(v7new)) { goto L11; }
      v4components = CONS(v7new,v4components);
     }
L11:;
    }
    v5 = ecl_cdr(v5);
L7:;
    if (Null(v5)) { goto L17; }
    goto L6;
L17:;
   }
   value0 = cl_nreverse(v4components);
   return value0;
  }
 }
}
/*	function definition for EXPAND-SERIAL-COMPONENT-CHAIN         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L81expand_serial_component_chain(cl_narg narg, cl_object v1definitions, cl_object v2parent, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v3indent;
  va_list args; va_start(args,v2parent);
  {
   int i = 2;
   if (i >= narg) {
    v3indent = ecl_make_fixnum(0);
   } else {
    i++;
    v3indent = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v4previous;
   cl_object v5components;
   v4previous = ECL_NIL;
   v5components = ECL_NIL;
   {
    cl_object v6;
    v6 = v1definitions;
    goto L8;
L7:;
    {
     cl_object v7definition;
     v7definition = ecl_car(v6);
     {
      cl_object v8new;
      v8new = L83expand_component_definition(3, v7definition, v2parent, v3indent);
      if (Null(v8new)) { goto L12; }
      if (Null(v4previous)) { goto L15; }
      {
       cl_object v9;
       T0 = ecl_function_dispatch(cl_env_copy,VV[474])(1, v8new) /*  COMPONENT-DEPENDS-ON */;
       v9 = cl_adjoin(2, v4previous, T0);
       ecl_structure_set(v8new,VV[89],18,v9);
      }
L15:;
      v4previous = ecl_function_dispatch(cl_env_copy,VV[142])(1, v8new) /*  COMPONENT-NAME */;
      v5components = CONS(v8new,v5components);
     }
L12:;
    }
    v6 = ecl_cdr(v6);
L8:;
    if (Null(v6)) { goto L23; }
    goto L7;
L23:;
   }
   value0 = cl_nreverse(v5components);
   return value0;
  }
 }
}
/*	function definition for ABSOLUTE-FILE-NAMESTRING-P            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L82absolute_file_namestring_p(cl_object v1string)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   v2 = si_make_seq_iterator(2, v1string, ecl_make_fixnum(0));
L5:;
   if ((v2)!=ECL_NIL) { goto L7; }
   value0 = ECL_NIL;
   goto L3;
L7:;
   {
    cl_object v3;
    v3 = si_seq_iterator_ref(v1string, v2);
    if (!(ecl_char_code(CODE_CHAR(58))==ecl_char_code(v3))) { goto L9; }
    value0 = v3;
    goto L3;
   }
L9:;
   v2 = si_seq_iterator_next(v1string, v2);
   goto L5;
  }
L3:;
  if ((value0)!=ECL_NIL) { goto L2; }
  if ((L13null_string(v1string))!=ECL_NIL) { goto L15; }
  {
   ecl_character v2;
   v2 = ecl_char(v1string,0);
   value0 = ecl_make_bool((v2)==((ecl_character)(47)));
   cl_env_copy->nvalues = 1;
   return value0;
  }
L15:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for EXPAND-COMPONENT-DEFINITION           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L83expand_component_definition(cl_narg narg, cl_object v1definition, cl_object v2parent, ...)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v3indent;
  va_list args; va_start(args,v2parent);
  {
   int i = 2;
   if (i >= narg) {
    v3indent = ecl_make_fixnum(0);
   } else {
    i++;
    v3indent = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (!(v1definition==ECL_NIL)) { goto L2; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  if (!(ECL_STRINGP(v1definition))) { goto L4; }
  if (Null(ecl_symbol_value(VV[207]))) { goto L6; }
  if (Null(L82absolute_file_namestring_p(v1definition))) { goto L6; }
  value0 = L74create_component(5, VV[135], v1definition, ECL_NIL, v2parent, v3indent);
  return value0;
L6:;
  value0 = L74create_component(5, ECL_SYM("FILE",1237), v1definition, ECL_NIL, v2parent, v3indent);
  return value0;
L4:;
  if (!(ECL_LISTP(v1definition))) { goto L9; }
  T0 = ecl_car(v1definition);
  if ((ecl_memql(T0,VV[115]))!=ECL_NIL) { goto L9; }
  T0 = ecl_car(v1definition);
  T1 = ecl_cdr(v1definition);
  value0 = L74create_component(5, ECL_SYM("FILE",1237), T0, T1, v2parent, v3indent);
  return value0;
L9:;
  if (!(ECL_LISTP(v1definition))) { goto L12; }
  T0 = ecl_car(v1definition);
  T1 = ecl_cadr(v1definition);
  T2 = ecl_cddr(v1definition);
  value0 = L74create_component(5, T0, T1, T2, v2parent, v3indent);
  return value0;
L12:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for LINK-COMPONENT-DEPENDS-ON             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L84link_component_depends_on(cl_object v1components)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   v2 = v1components;
   goto L4;
L3:;
   {
    cl_object v3component;
    v3component = ecl_car(v2);
    if (Null(ecl_symbol_value(VV[32]))) { goto L11; }
    T0 = ecl_function_dispatch(cl_env_copy,VV[141])(1, v3component) /*  COMPONENT-TYPE */;
    if ((T0)==(VV[132])) { goto L8; }
    goto L9;
L11:;
    goto L9;
L9:;
    {
     cl_object v4;
     {
      cl_object v5;
      cl_object v6;
      cl_object v7;
      v5 = ecl_function_dispatch(cl_env_copy,VV[474])(1, v3component) /*  COMPONENT-DEPENDS-ON */;
      v6 = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
      v7 = v5;
      {
       cl_object v8;
       cl_object v9;
       v8 = ecl_list1(ECL_NIL);
       v9 = v8;
L20:;
       if (!(ecl_endp(v7))) { goto L22; }
       goto L21;
L22:;
       v6 = _ecl_car(v7);
       {
        cl_object v10;
        v10 = _ecl_cdr(v7);
        if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
        v7 = v10;
       }
       if (ecl_unlikely(ECL_ATOM(v9))) FEtype_error_cons(v9);
       T0 = v9;
       {
        cl_object v10parent;
        {
         cl_object v11;
         v11 = cl_string(v6);
         {
          cl_object v12;
          v12 = si_make_seq_iterator(2, v1components, ecl_make_fixnum(0));
L38:;
          if ((v12)!=ECL_NIL) { goto L40; }
          v10parent = ECL_NIL;
          goto L35;
L40:;
          {
          cl_object v13;
          v13 = si_seq_iterator_ref(v1components, v12);
          T2 = ecl_function_dispatch(cl_env_copy,VV[142])(1, v13) /*  COMPONENT-NAME */;
          if (Null(cl_string_equal(2, v11, T2))) { goto L42; }
          v10parent = v13;
          goto L35;
          }
L42:;
          v12 = si_seq_iterator_next(v1components, v12);
          goto L38;
         }
        }
L35:;
        if (Null(v10parent)) { goto L47; }
        T1 = v10parent;
        goto L34;
L47:;
        T1 = (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(3, _ecl_static_90, v6, v3component) /*  WARN */;
       }
L34:;
       v9 = ecl_list1(T1);
       (ECL_CONS_CDR(T0)=v9,T0);
       goto L20;
L21:;
       v4 = ecl_cdr(v8);
       goto L13;
      }
     }
L13:;
     ecl_structure_set(v3component,VV[89],18,v4);
    }
L8:;
   }
   v2 = ecl_cdr(v2);
L4:;
   if (Null(v2)) { goto L53; }
   goto L3;
L53:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for TOPOLOGICAL-SORT                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L86topological_sort(cl_object v1list)
{
 cl_object T0;
 volatile cl_object lex0[1];
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  lex0[0] = ECL_NIL;                              /*  SORTED-LIST     */
  {
   cl_object v2;
   v2 = v1list;
   goto L5;
L4:;
   {
    cl_object v3znode;
    v3znode = ecl_car(v2);
    ecl_structure_set(v3znode,VV[73],0,VV[77]);
   }
   v2 = ecl_cdr(v2);
L5:;
   if (Null(v2)) { goto L12; }
   goto L4;
L12:;
  }
  {
   cl_object v2;
   v2 = v1list;
   goto L18;
L17:;
   {
    cl_object v3znode;
    v3znode = ecl_car(v2);
    T0 = ecl_function_dispatch(cl_env_copy,VV[505])(1, v3znode) /*  TOPSORT-COLOR */;
    if (!((T0)==(VV[77]))) { goto L22; }
    LC85dfs_visit(lex0, v3znode);
L22:;
   }
   v2 = ecl_cdr(v2);
L18:;
   if (Null(v2)) { goto L26; }
   goto L17;
L26:;
  }
  value0 = cl_nreverse(lex0[0]);
  return value0;
 }
}
/*	local function DFS-VISIT                                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC85dfs_visit(volatile cl_object *lex0, cl_object v1znode)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_structure_set(v1znode,VV[73],0,VV[78]);
  if (Null(ecl_symbol_value(VV[32]))) { goto L5; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[141])(1, v1znode) /*  COMPONENT-TYPE */;
  if ((T0)==(VV[122])) { goto L2; }
  goto L3;
L5:;
  goto L3;
L3:;
  {
   cl_object v2;
   v2 = ecl_function_dispatch(cl_env_copy,VV[474])(1, v1znode) /*  COMPONENT-DEPENDS-ON */;
   goto L10;
L9:;
   {
    cl_object v3child;
    v3child = ecl_car(v2);
    T0 = ecl_function_dispatch(cl_env_copy,VV[505])(1, v3child) /*  TOPSORT-COLOR */;
    if (!((T0)==(VV[77]))) { goto L15; }
    LC85dfs_visit(lex0, v3child);
    goto L14;
L15:;
    T0 = ecl_function_dispatch(cl_env_copy,VV[505])(1, v3child) /*  TOPSORT-COLOR */;
    if (!((T0)==(VV[78]))) { goto L14; }
    cl_format(3, ECL_T, _ecl_static_91, v3child);
L14:;
   }
   v2 = ecl_cdr(v2);
L10:;
   if (Null(v2)) { goto L20; }
   goto L9;
L20:;
  }
L2:;
  ecl_structure_set(v1znode,VV[73],0,VV[80]);
  lex0[0] = CONS(v1znode,lex0[0]);
  value0 = lex0[0];
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for SPLIT-STRING                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L87split_string(cl_narg narg, cl_object v1string, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2item;
  cl_object v3test;
  ecl_va_list args; ecl_va_start(args,v1string,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L87split_stringkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[2])) {
    v2item = CODE_CHAR(32);
   } else {
    v2item = keyvars[0];
   }
   if (Null(keyvars[3])) {
    v3test = (ECL_SYM("CHAR=",219)->symbol.gfdef);
   } else {
    v3test = keyvars[1];
   }
  }
  {
   cl_fixnum v4;
   cl_object v5index;
   cl_object v6result;
   v4 = ecl_length(v1string);
   v5index = ecl_make_fixnum(0);
   v6result = ECL_NIL;
   {
    cl_object v7i;
    v7i = ecl_make_fixnum(0);
    goto L9;
L8:;
    T0 = cl_char(v1string, v7i);
    if (Null(ecl_function_dispatch(cl_env_copy,v3test)(2, T0, v2item))) { goto L11; }
    if (ecl_number_equalp(v5index,v7i)) { goto L13; }
    T0 = cl_subseq(3, v1string, v5index, v7i);
    v6result = CONS(T0,v6result);
L13:;
    v5index = ecl_one_plus(v7i);
L11:;
    v7i = ecl_one_plus(v7i);
L9:;
    if (!(ecl_number_compare(v7i,ecl_make_fixnum(v4))<0)) { goto L19; }
    goto L8;
L19:;
    if (ecl_number_equalp(v5index,ecl_make_fixnum(v4))) { goto L21; }
    T0 = cl_subseq(2, v1string, v5index);
    v6result = CONS(T0,v6result);
L21:;
    value0 = cl_reverse(v6result);
    return value0;
   }
  }
 }
}
/*	function definition for PROMPT-STRING                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L88prompt_string(cl_object v1component)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_symbol_value(VV[17]);
  T1 = ecl_function_dispatch(cl_env_copy,VV[510])(1, v1component) /*  COMPONENT-INDENT */;
  value0 = cl_format(4, ECL_NIL, _ecl_static_92, T0, T1);
  return value0;
 }
}
/*	function definition for FORMAT-JUSTIFIED-STRING               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L89format_justified_string(cl_narg narg, cl_object v1prompt, cl_object v2contents, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>4)) FEwrong_num_arguments_anonym();
 {
  cl_object v3width;
  cl_object v4stream;
  va_list args; va_start(args,v2contents);
  {
   int i = 2;
   if (i >= narg) {
    v3width = ecl_make_fixnum(80);
   } else {
    i++;
    v3width = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v4stream = ecl_symbol_value(ECL_SYM("*STANDARD-OUTPUT*",67));
   } else {
    i++;
    v4stream = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v5prompt_length;
   {
    cl_fixnum v6;
    v6 = ecl_length(v1prompt);
    v5prompt_length = ecl_plus(ecl_make_fixnum(2),ecl_make_fixnum(v6));
   }
   {
    cl_fixnum v6;
    v6 = ecl_length(v2contents);
    T0 = ecl_plus(v5prompt_length,ecl_make_fixnum(v6));
    if (!(ecl_number_compare(T0,v3width)<0)) { goto L5; }
   }
   cl_format(4, v4stream, _ecl_static_93, v1prompt, v2contents);
   goto L3;
L5:;
   cl_format(3, v4stream, _ecl_static_94, v1prompt);
   {
    cl_object v6cursor;
    cl_object v7contents;
    cl_object v8content;
    cl_object v9content_length;
    v6cursor = v5prompt_length;
    v7contents = L87split_string(1, v2contents);
    v8content = ecl_car(v7contents);
    {
     cl_fixnum v10;
     v10 = ecl_length(v8content);
     v9content_length = ecl_make_integer((v10)+1);
    }
    goto L14;
L13:;
    T0 = ecl_plus(v6cursor,v9content_length);
    if (!(ecl_number_compare(T0,v3width)<0)) { goto L17; }
    v6cursor = ecl_plus(v6cursor,v9content_length);
    cl_format(3, v4stream, _ecl_static_95, v8content);
    goto L16;
L17:;
    v6cursor = ecl_plus(v5prompt_length,v9content_length);
    cl_format(4, v4stream, _ecl_static_96, v1prompt, v8content);
L16:;
    v7contents = ecl_cdr(v7contents);
    v8content = ecl_car(v7contents);
    {
     cl_fixnum v10;
     v10 = ecl_length(v8content);
     v9content_length = ecl_make_integer((v10)+1);
    }
L14:;
    if (v7contents==ECL_NIL) { goto L29; }
    goto L13;
L29:;
   }
  }
L3:;
  value0 = cl_finish_output(1, v4stream);
  return value0;
 }
}
/*	function definition for TELL-USER                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L90tell_user(cl_narg narg, cl_object v1what, cl_object v2component, ...)
{
 cl_object T0, T1, T2, T3, T4, T5;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>5)) FEwrong_num_arguments_anonym();
 {
  cl_object v3type;
  cl_object v4no_dots;
  cl_object v5force;
  va_list args; va_start(args,v2component);
  {
   int i = 2;
   if (i >= narg) {
    v3type = ECL_NIL;
   } else {
    i++;
    v3type = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v4no_dots = ECL_NIL;
   } else {
    i++;
    v4no_dots = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v5force = ECL_NIL;
   } else {
    i++;
    v5force = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if ((ecl_symbol_value(VV[16]))!=ECL_NIL) { goto L6; }
  if (Null(v5force)) { goto L4; }
  goto L5;
L6:;
L5:;
  T0 = L88prompt_string(v2component);
  if (!((v1what)==(ECL_SYM("COMPILE",233)))) { goto L14; }
  goto L11;
  goto L12;
L14:;
  goto L12;
L12:;
  if (!(ecl_eql(v1what,VV[216]))) { goto L9; }
  goto L10;
L11:;
L10:;
  if (Null(ecl_function_dispatch(cl_env_copy,VV[487])(1, v2component) /*  COMPONENT-LOAD-ONLY */)) { goto L17; }
  T1 = _ecl_static_98;
  goto L8;
L17:;
  T1 = _ecl_static_99;
  goto L8;
L9:;
  if (!((v1what)==(ECL_SYM("LOAD",487)))) { goto L24; }
  goto L21;
  goto L22;
L24:;
  goto L22;
L22:;
  if (!(ecl_eql(v1what,VV[154]))) { goto L19; }
  goto L20;
L21:;
L20:;
  T1 = _ecl_static_98;
  goto L8;
L19:;
  T1 = v1what;
L8:;
  T2 = ecl_function_dispatch(cl_env_copy,VV[141])(1, v2component) /*  COMPONENT-TYPE */;
  if (Null(v3type)) { goto L31; }
  value0 = L69component_full_pathname(2, v2component, v3type);
  goto L30;
L31:;
  value0 = ECL_NIL;
L30:;
  if ((value0)!=ECL_NIL) { goto L29; }
  T3 = ecl_function_dispatch(cl_env_copy,VV[142])(1, v2component) /*  COMPONENT-NAME */;
  goto L27;
L29:;
  T3 = value0;
  goto L27;
L27:;
  if (Null(ecl_symbol_value(VV[15]))) { goto L35; }
  T4 = Null(v4no_dots)?ECL_T:ECL_NIL;
  goto L33;
L35:;
  T4 = ECL_NIL;
  goto L33;
L33:;
  T5 = cl_format(6, ECL_NIL, _ecl_static_97, T1, T2, T3, T4);
  value0 = L89format_justified_string(2, T0, T5);
  return value0;
L4:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for TELL-USER-DONE                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L91tell_user_done(cl_narg narg, cl_object v1component, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v2force;
  cl_object v3no_dots;
  va_list args; va_start(args,v1component);
  {
   int i = 1;
   if (i >= narg) {
    v2force = ECL_NIL;
   } else {
    i++;
    v2force = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v3no_dots = ECL_NIL;
   } else {
    i++;
    v3no_dots = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (Null(ecl_symbol_value(VV[15]))) { goto L3; }
  if ((ecl_symbol_value(VV[16]))!=ECL_NIL) { goto L6; }
  if (Null(v2force)) { goto L3; }
  goto L4;
L6:;
L4:;
  T0 = L88prompt_string(v1component);
  T1 = Null(v3no_dots)?ECL_T:ECL_NIL;
  cl_format(4, ECL_T, _ecl_static_100, T0, T1);
  value0 = cl_finish_output(1, ecl_symbol_value(ECL_SYM("*STANDARD-OUTPUT*",67)));
  return value0;
L3:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function WITH-TELL-USER                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC92with_tell_user(cl_object v1, cl_object v2)
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
   cl_object v6what;
   cl_object v7component;
   cl_object v8type;
   cl_object v9no_dots;
   cl_object v10force;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v11;
    v11 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4 = v11;
   }
   v5 = v4;
   if (!(v5==ECL_NIL)) { goto L10; }
   si_dm_too_few_arguments(v1);
L10:;
   {
    cl_object v11;
    v11 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v6what = v11;
   }
   if (!(v5==ECL_NIL)) { goto L16; }
   si_dm_too_few_arguments(v1);
L16:;
   {
    cl_object v11;
    v11 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v7component = v11;
   }
   if (Null(v5)) { goto L22; }
   {
    cl_object v11;
    v11 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v8type = v11;
    goto L21;
   }
L22:;
   v8type = ECL_NIL;
L21:;
   if (Null(v5)) { goto L28; }
   {
    cl_object v11;
    v11 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v9no_dots = v11;
    goto L27;
   }
L28:;
   v9no_dots = ECL_NIL;
L27:;
   if (Null(v5)) { goto L34; }
   {
    cl_object v11;
    v11 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v10force = v11;
    goto L33;
   }
L34:;
   v10force = ECL_NIL;
L33:;
   if (Null(v5)) { goto L39; }
   si_dm_too_many_arguments(v1);
L39:;
   T0 = cl_list(6, VV[220], v6what, v7component, v8type, v9no_dots, v10force);
   T1 = cl_list(4, VV[221], v7component, v10force, v9no_dots);
   T2 = ecl_list1(T1);
   T3 = ecl_append(v3,T2);
   value0 = cl_listX(3, ECL_SYM("PROGN",671), T0, T3);
   return value0;
  }
 }
}
/*	function definition for TELL-USER-NO-FILES                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L93tell_user_no_files(cl_narg narg, cl_object v1component, ...)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2force;
  va_list args; va_start(args,v1component);
  {
   int i = 1;
   if (i >= narg) {
    v2force = ECL_NIL;
   } else {
    i++;
    v2force = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if ((ecl_symbol_value(VV[16]))!=ECL_NIL) { goto L4; }
  if (Null(v2force)) { goto L2; }
  goto L3;
L4:;
L3:;
  T0 = L88prompt_string(v1component);
  T1 = L69component_full_pathname(2, v1component, VV[137]);
  value0 = ecl_symbol_value(VV[18]);
  if ((value0)!=ECL_NIL) { goto L8; }
  T2 = ecl_symbol_value(VV[20]);
  goto L6;
L8:;
  T2 = value0;
  goto L6;
L6:;
  T3 = L69component_full_pathname(2, v1component, VV[159]);
  T4 = cl_format(5, ECL_NIL, _ecl_static_101, T1, T2, T3);
  value0 = L89format_justified_string(2, T0, T4);
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for TELL-USER-REQUIRE-SYSTEM              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L94tell_user_require_system(cl_object v1name, cl_object v2parent)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_symbol_value(VV[16]))) { goto L1; }
  T0 = ecl_symbol_value(VV[17]);
  T1 = ecl_function_dispatch(cl_env_copy,VV[142])(1, v2parent) /*  COMPONENT-NAME */;
  cl_format(5, ECL_T, _ecl_static_102, T0, T1, v1name);
  value0 = cl_finish_output(1, ecl_symbol_value(ECL_SYM("*STANDARD-OUTPUT*",67)));
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for TELL-USER-GENERIC                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L95tell_user_generic(cl_object v1string)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_symbol_value(VV[16]))) { goto L1; }
  cl_format(4, ECL_T, _ecl_static_103, ecl_symbol_value(VV[17]), v1string);
  value0 = cl_finish_output(1, ecl_symbol_value(ECL_SYM("*STANDARD-OUTPUT*",67)));
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for INTERNAL-REAL-TIME-IN-SECONDS         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L96internal_real_time_in_seconds()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_get_universal_time();
  return value0;
 }
}
/*	function definition for READ-CHAR-WAIT                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L97read_char_wait(cl_narg narg, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>4)) FEwrong_num_arguments_anonym();
 {
  cl_object v1timeout;
  cl_object v2input_stream;
  cl_object v3eof_error_p;
  cl_object v4eof_value;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1timeout = ecl_make_fixnum(20);
   } else {
    i++;
    v1timeout = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v2input_stream = ECL_NIL;
   } else {
    i++;
    v2input_stream = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v3eof_error_p = ECL_T;
   } else {
    i++;
    v3eof_error_p = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v4eof_value = ECL_NIL;
   } else {
    i++;
    v4eof_value = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v5peek;
   v5peek = ECL_NIL;
   {
    cl_object v6start;
    v6start = L96internal_real_time_in_seconds();
    goto L9;
L8:;
    if (ecl_zerop(ecl_symbol_value(VV[228]))) { goto L11; }
    cl_sleep(ecl_symbol_value(VV[228]));
L11:;
L9:;
    v5peek = cl_listen(1, v2input_stream);
    if ((v5peek)!=ECL_NIL) { goto L13; }
    T0 = ecl_plus(v6start,v1timeout);
    T1 = L96internal_real_time_in_seconds();
    if (ecl_number_compare(T0,T1)<0) { goto L13; }
    goto L8;
L13:;
    if (Null(v5peek)) { goto L17; }
    value0 = cl_read_char(3, v2input_stream, v3eof_error_p, v4eof_value);
    return value0;
L17:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for Y-OR-N-P-WAIT                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L98y_or_n_p_wait(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1default;
  cl_object v2timeout;
  cl_object v3format_string;
  cl_object v4args;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  {
   int i = 0;
   if (i >= narg) {
    v1default = CODE_CHAR(121);
   } else {
    i++;
    v1default = ecl_va_arg(args);
   }
   if (i >= narg) {
    v2timeout = ecl_make_fixnum(20);
   } else {
    i++;
    v2timeout = ecl_va_arg(args);
   }
   if (i >= narg) {
    v3format_string = ECL_NIL;
   } else {
    i++;
    v3format_string = ecl_va_arg(args);
   }
  }
  v4args = cl_grab_rest_args(args);
  ecl_va_end(args);
  if (Null(ecl_symbol_value(VV[227]))) { goto L4; }
  cl_clear_input(1, ecl_symbol_value(ECL_SYM("*QUERY-IO*",59)));
L4:;
  if (Null(v3format_string)) { goto L6; }
  cl_fresh_line(1, ecl_symbol_value(ECL_SYM("*QUERY-IO*",59)));
  T0 = (ECL_SYM("FORMAT",387)->symbol.gfdef);
  cl_apply(4, T0, ecl_symbol_value(ECL_SYM("*QUERY-IO*",59)), v3format_string, v4args);
  cl_finish_output(1, ecl_symbol_value(ECL_SYM("*QUERY-IO*",59)));
L6:;
L11:;
  {
   cl_object v5read_char;
   cl_object v6char;
   if (Null(ecl_symbol_value(VV[226]))) { goto L14; }
   v5read_char = L97read_char_wait(4, v2timeout, ecl_symbol_value(ECL_SYM("*QUERY-IO*",59)), ECL_NIL, ECL_NIL);
   goto L13;
L14:;
   v5read_char = cl_read_char(1, ecl_symbol_value(ECL_SYM("*QUERY-IO*",59)));
L13:;
   value0 = v5read_char;
   if ((value0)!=ECL_NIL) { goto L18; }
   v6char = v1default;
   goto L16;
L18:;
   v6char = value0;
   goto L16;
L16:;
   {
    cl_object v7;
    v7 = si_make_seq_iterator(2, VV[231], ecl_make_fixnum(0));
L22:;
    if ((v7)!=ECL_NIL) { goto L24; }
    goto L20;
L24:;
    {
     cl_object v8;
     v8 = si_seq_iterator_ref(VV[231], v7);
     if (!(ecl_eql(v6char,v8))) { goto L26; }
     if ((v8)!=ECL_NIL) { goto L12; }
     goto L20;
    }
L26:;
    v7 = si_seq_iterator_next(VV[231], v7);
    goto L22;
   }
L20:;
   if (!(v5read_char==ECL_NIL)) { goto L31; }
   cl_format(3, ecl_symbol_value(ECL_SYM("*QUERY-IO*",59)), _ecl_static_105, v1default);
   cl_finish_output(1, ecl_symbol_value(ECL_SYM("*QUERY-IO*",59)));
L31:;
   if (!(v6char==ECL_NIL)) { goto L34; }
   value0 = ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
L34:;
   {
    cl_object v7;
    v7 = si_make_seq_iterator(2, VV[232], ecl_make_fixnum(0));
L39:;
    if ((v7)!=ECL_NIL) { goto L41; }
    goto L36;
L41:;
    {
     cl_object v8;
     v8 = si_seq_iterator_ref(VV[232], v7);
     if (!(ecl_char_code(v6char)==ecl_char_code(v8))) { goto L43; }
     if (Null(v8)) { goto L36; }
     goto L37;
    }
L43:;
    v7 = si_seq_iterator_next(VV[232], v7);
    goto L39;
   }
L37:;
   value0 = ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
L36:;
   {
    cl_object v7;
    v7 = si_make_seq_iterator(2, VV[233], ecl_make_fixnum(0));
L51:;
    if ((v7)!=ECL_NIL) { goto L53; }
    goto L48;
L53:;
    {
     cl_object v8;
     v8 = si_seq_iterator_ref(VV[233], v7);
     if (!(ecl_char_code(v6char)==ecl_char_code(v8))) { goto L55; }
     if (Null(v8)) { goto L48; }
     goto L49;
    }
L55:;
    v7 = si_seq_iterator_next(VV[233], v7);
    goto L51;
   }
L49:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L48:;
   if (Null(ecl_symbol_value(VV[227]))) { goto L60; }
   cl_clear_input(1, ecl_symbol_value(ECL_SYM("*QUERY-IO*",59)));
L60:;
   cl_format(2, ecl_symbol_value(ECL_SYM("*QUERY-IO*",59)), _ecl_static_106);
   if (Null(v3format_string)) { goto L63; }
   cl_fresh_line(1, ecl_symbol_value(ECL_SYM("*QUERY-IO*",59)));
   T0 = (ECL_SYM("FORMAT",387)->symbol.gfdef);
   cl_apply(4, T0, ecl_symbol_value(ECL_SYM("*QUERY-IO*",59)), v3format_string, v4args);
L63:;
   cl_finish_output(1, ecl_symbol_value(ECL_SYM("*QUERY-IO*",59)));
  }
L12:;
  goto L11;
 }
}
/*	local function WITH-SPECIAL-COMPONENT-VARS                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC99with_special_component_vars(cl_object v1, cl_object v2)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6c;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v7;
    v7 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4 = v7;
   }
   v5 = v4;
   if (!(v5==ECL_NIL)) { goto L10; }
   si_dm_too_few_arguments(v1);
L10:;
   {
    cl_object v7;
    v7 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v6c = v7;
   }
   if (Null(v5)) { goto L15; }
   si_dm_too_many_arguments(v1);
L15:;
   T0 = cl_list(2, VV[235], v6c);
   T1 = ecl_list1(T0);
   value0 = cl_listX(4, ECL_SYM("LET",477), T1, VV[236], v3);
   return value0;
  }
 }
}
/*	function definition for OPERATE-ON-SYSTEM                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L100operate_on_system(volatile cl_narg narg, cl_object volatile v1name, cl_object volatile v2operation, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  volatile cl_object v3force;
  volatile cl_object v4version;
  volatile cl_object v5test;
  volatile cl_object v6verbose;
  volatile cl_object v7load_source_instead_of_binary;
  volatile cl_object v8load_source_if_no_binary;
  volatile cl_object v9bother_user_if_no_binary;
  volatile cl_object v10compile_during_load;
  volatile cl_object v11dribble;
  volatile cl_object v12minimal_load;
  volatile cl_object v13override_compilation_unit;
  ecl_va_list args; ecl_va_start(args,v2operation,narg,2);
  {
   cl_object keyvars[22];
   cl_parse_key(args,11,L100operate_on_systemkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3force = keyvars[0];
   if (Null(keyvars[12])) {
    v4version = ecl_symbol_value(VV[36]);
   } else {
    v4version = keyvars[1];
   }
   if (Null(keyvars[13])) {
    v5test = ecl_symbol_value(VV[17]);
   } else {
    v5test = keyvars[2];
   }
   if (Null(keyvars[14])) {
    v6verbose = ecl_symbol_value(VV[16]);
   } else {
    v6verbose = keyvars[3];
   }
   if (Null(keyvars[15])) {
    v7load_source_instead_of_binary = ecl_symbol_value(VV[20]);
   } else {
    v7load_source_instead_of_binary = keyvars[4];
   }
   if (Null(keyvars[16])) {
    v8load_source_if_no_binary = ecl_symbol_value(VV[18]);
   } else {
    v8load_source_if_no_binary = keyvars[5];
   }
   if (Null(keyvars[17])) {
    v9bother_user_if_no_binary = ecl_symbol_value(VV[19]);
   } else {
    v9bother_user_if_no_binary = keyvars[6];
   }
   if (Null(keyvars[18])) {
    v10compile_during_load = ecl_symbol_value(VV[21]);
   } else {
    v10compile_during_load = keyvars[7];
   }
   v11dribble = keyvars[8];
   if (Null(keyvars[20])) {
    v12minimal_load = ecl_symbol_value(VV[23]);
   } else {
    v12minimal_load = keyvars[9];
   }
   if (Null(keyvars[21])) {
    v13override_compilation_unit = ECL_T;
   } else {
    v13override_compilation_unit = keyvars[10];
   }
  }
  {
   volatile bool unwinding = FALSE;
   cl_index v14=ECL_STACK_INDEX(cl_env_copy),v15;
   ecl_frame_ptr next_fr;
   if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
     unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
   } else {
   if (Null(ecl_symbol_value(VV[175]))) { goto L11; }
   L68clear_full_pathname_tables();
L11:;
   if (Null(v11dribble)) { goto L13; }
   (cl_env_copy->function=(ECL_SYM("DRIBBLE",319)->symbol.gfdef))->cfun.entry(1, v11dribble) /*  DRIBBLE */;
L13:;
   if (Null(v5test)) { goto L15; }
   v6verbose = ECL_T;
L15:;
   if (!(v3force==ECL_NIL)) { goto L18; }
   if (!((v2operation)==(ECL_SYM("LOAD",487)))) { goto L25; }
   goto L22;
   goto L23;
L25:;
   goto L23;
L23:;
   if (!(ecl_eql(v2operation,VV[154]))) { goto L20; }
   goto L21;
L22:;
L21:;
   v3force = VV[238];
   goto L18;
L20:;
   if (!((v2operation)==(ECL_SYM("COMPILE",233)))) { goto L34; }
   goto L31;
   goto L32;
L34:;
   goto L32;
L32:;
   if (!(ecl_eql(v2operation,VV[216]))) { goto L29; }
   goto L30;
L31:;
L30:;
   v3force = VV[239];
   goto L18;
L29:;
   v3force = VV[238];
L18:;
   value0 = L71translate_version(v4version);
   ecl_bds_bind(cl_env_copy,VV[34],value0);       /*  *VERSION-DIR*   */
   {
    const int v17 = cl_env_copy->nvalues;
    cl_object v18;
    v18 = (v17<=1)? ECL_NIL : cl_env_copy->values[1];
    ecl_bds_bind(cl_env_copy,VV[35],v18);         /*  *VERSION-REPLACE* */
   }
   {
    cl_object v17;
    if (Null(ecl_function_dispatch(cl_env_copy,VV[92])(1, v1name) /*  COMPONENT-P */)) { goto L41; }
    {
     cl_object v18;
     v18 = ecl_function_dispatch(cl_env_copy,VV[141])(1, v1name) /*  COMPONENT-TYPE */;
     if (!(ecl_eql(v18,VV[122]))) { goto L48; }
     goto L45;
     goto L46;
L48:;
     goto L46;
L46:;
     if (!(ecl_eql(v18,VV[132]))) { goto L52; }
     goto L45;
     goto L50;
L52:;
     goto L50;
L50:;
     if (!(ecl_eql(v18,VV[188]))) { goto L41; }
     goto L42;
L45:;
    }
L42:;
    v17 = v1name;
    goto L40;
L41:;
    v17 = L59find_system(2, v1name, VV[154]);
L40:;
    ecl_bds_bind(cl_env_copy,ECL_SYM("*LOAD-VERBOSE*",39),ECL_T); /*  *LOAD-VERBOSE* */
    ecl_bds_bind(cl_env_copy,ECL_SYM("*COMPILE-VERBOSE*",29),ECL_T); /*  *COMPILE-VERBOSE* */
    ecl_bds_bind(cl_env_copy,VV[36],v4version);   /*  *VERSION*       */
    ecl_bds_bind(cl_env_copy,VV[16],v6verbose);   /*  *OOS-VERBOSE*   */
    ecl_bds_bind(cl_env_copy,VV[17],v5test);      /*  *OOS-TEST*      */
    ecl_bds_bind(cl_env_copy,VV[18],v8load_source_if_no_binary); /*  *LOAD-SOURCE-IF-NO-BINARY* */
    ecl_bds_bind(cl_env_copy,VV[21],v10compile_during_load); /*  *COMPILE-DURING-LOAD* */
    ecl_bds_bind(cl_env_copy,VV[19],v9bother_user_if_no_binary); /*  *BOTHER-USER-IF-NO-BINARY* */
    ecl_bds_bind(cl_env_copy,VV[20],v7load_source_instead_of_binary); /*  *LOAD-SOURCE-INSTEAD-OF-BINARY* */
    ecl_bds_bind(cl_env_copy,VV[23],v12minimal_load); /*  *MINIMAL-LOAD* */
    if ((L7component_operation(1, v2operation))!=ECL_NIL) { goto L55; }
    cl_error(2, _ecl_static_107, v2operation);
L55:;
    cl_env_copy->values[0] = L107operate_on_component(v17, v2operation, v3force);
    ecl_bds_unwind_n(cl_env_copy,12);
   }
   }
   ecl_frs_pop(cl_env_copy);
   v15=ecl_stack_push_values(cl_env_copy);
   if (Null(v11dribble)) { goto L57; }
   (cl_env_copy->function=(ECL_SYM("DRIBBLE",319)->symbol.gfdef))->cfun.entry(0) /*  DRIBBLE */;
L57:;
   ecl_stack_pop_values(cl_env_copy,v15);
   if (unwinding) ecl_unwind(cl_env_copy,next_fr);
   ECL_STACK_SET_INDEX(cl_env_copy,v14);
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for COMPILE-SYSTEM                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L101compile_system(cl_narg narg, cl_object v1name, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2force;
  cl_object v3version;
  cl_object v4test;
  cl_object v5verbose;
  cl_object v6load_source_instead_of_binary;
  cl_object v7load_source_if_no_binary;
  cl_object v8bother_user_if_no_binary;
  cl_object v9compile_during_load;
  cl_object v10dribble;
  cl_object v11minimal_load;
  ecl_va_list args; ecl_va_start(args,v1name,narg,1);
  {
   cl_object keyvars[20];
   cl_parse_key(args,10,L101compile_systemkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v2force = keyvars[0];
   if (Null(keyvars[11])) {
    v3version = ecl_symbol_value(VV[36]);
   } else {
    v3version = keyvars[1];
   }
   if (Null(keyvars[12])) {
    v4test = ecl_symbol_value(VV[17]);
   } else {
    v4test = keyvars[2];
   }
   if (Null(keyvars[13])) {
    v5verbose = ecl_symbol_value(VV[16]);
   } else {
    v5verbose = keyvars[3];
   }
   if (Null(keyvars[14])) {
    v6load_source_instead_of_binary = ecl_symbol_value(VV[20]);
   } else {
    v6load_source_instead_of_binary = keyvars[4];
   }
   if (Null(keyvars[15])) {
    v7load_source_if_no_binary = ecl_symbol_value(VV[18]);
   } else {
    v7load_source_if_no_binary = keyvars[5];
   }
   if (Null(keyvars[16])) {
    v8bother_user_if_no_binary = ecl_symbol_value(VV[19]);
   } else {
    v8bother_user_if_no_binary = keyvars[6];
   }
   if (Null(keyvars[17])) {
    v9compile_during_load = ecl_symbol_value(VV[21]);
   } else {
    v9compile_during_load = keyvars[7];
   }
   v10dribble = keyvars[8];
   if (Null(keyvars[19])) {
    v11minimal_load = ecl_symbol_value(VV[23]);
   } else {
    v11minimal_load = keyvars[9];
   }
  }
  value0 = L100operate_on_system(22, v1name, VV[216], VV[244], v2force, ECL_SYM("VERSION",1326), v3version, ECL_SYM("TEST",1316), v4test, ECL_SYM("VERBOSE",1325), v5verbose, VV[245], v6load_source_instead_of_binary, VV[246], v7load_source_if_no_binary, VV[247], v8bother_user_if_no_binary, VV[248], v9compile_during_load, VV[249], v10dribble, VV[250], v11minimal_load);
  return value0;
 }
}
/*	function definition for LOAD-SYSTEM                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L102load_system(cl_narg narg, cl_object v1name, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2force;
  cl_object v3version;
  cl_object v4test;
  cl_object v5verbose;
  cl_object v6load_source_instead_of_binary;
  cl_object v7load_source_if_no_binary;
  cl_object v8bother_user_if_no_binary;
  cl_object v9compile_during_load;
  cl_object v10dribble;
  cl_object v11minimal_load;
  ecl_va_list args; ecl_va_start(args,v1name,narg,1);
  {
   cl_object keyvars[20];
   cl_parse_key(args,10,L102load_systemkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v2force = keyvars[0];
   if (Null(keyvars[11])) {
    v3version = ecl_symbol_value(VV[36]);
   } else {
    v3version = keyvars[1];
   }
   if (Null(keyvars[12])) {
    v4test = ecl_symbol_value(VV[17]);
   } else {
    v4test = keyvars[2];
   }
   if (Null(keyvars[13])) {
    v5verbose = ecl_symbol_value(VV[16]);
   } else {
    v5verbose = keyvars[3];
   }
   if (Null(keyvars[14])) {
    v6load_source_instead_of_binary = ecl_symbol_value(VV[20]);
   } else {
    v6load_source_instead_of_binary = keyvars[4];
   }
   if (Null(keyvars[15])) {
    v7load_source_if_no_binary = ecl_symbol_value(VV[18]);
   } else {
    v7load_source_if_no_binary = keyvars[5];
   }
   if (Null(keyvars[16])) {
    v8bother_user_if_no_binary = ecl_symbol_value(VV[19]);
   } else {
    v8bother_user_if_no_binary = keyvars[6];
   }
   if (Null(keyvars[17])) {
    v9compile_during_load = ecl_symbol_value(VV[21]);
   } else {
    v9compile_during_load = keyvars[7];
   }
   v10dribble = keyvars[8];
   if (Null(keyvars[19])) {
    v11minimal_load = ecl_symbol_value(VV[23]);
   } else {
    v11minimal_load = keyvars[9];
   }
  }
  value0 = L100operate_on_system(22, v1name, VV[154], VV[244], v2force, ECL_SYM("VERSION",1326), v3version, ECL_SYM("TEST",1316), v4test, ECL_SYM("VERBOSE",1325), v5verbose, VV[245], v6load_source_instead_of_binary, VV[246], v7load_source_if_no_binary, VV[247], v8bother_user_if_no_binary, VV[248], v9compile_during_load, VV[249], v10dribble, VV[250], v11minimal_load);
  return value0;
 }
}
/*	function definition for CLEAN-SYSTEM                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L103clean_system(cl_narg narg, cl_object v1name, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2force;
  cl_object v3version;
  cl_object v4test;
  cl_object v5verbose;
  cl_object v6dribble;
  ecl_va_list args; ecl_va_start(args,v1name,narg,1);
  {
   cl_object keyvars[10];
   cl_parse_key(args,5,L103clean_systemkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[5])) {
    v2force = VV[238];
   } else {
    v2force = keyvars[0];
   }
   if (Null(keyvars[6])) {
    v3version = ecl_symbol_value(VV[36]);
   } else {
    v3version = keyvars[1];
   }
   if (Null(keyvars[7])) {
    v4test = ecl_symbol_value(VV[17]);
   } else {
    v4test = keyvars[2];
   }
   if (Null(keyvars[8])) {
    v5verbose = ecl_symbol_value(VV[16]);
   } else {
    v5verbose = keyvars[3];
   }
   v6dribble = keyvars[4];
  }
  value0 = L100operate_on_system(12, v1name, VV[253], VV[244], v2force, ECL_SYM("VERSION",1326), v3version, ECL_SYM("TEST",1316), v4test, ECL_SYM("VERBOSE",1325), v5verbose, VV[249], v6dribble);
  return value0;
 }
}
/*	function definition for EDIT-SYSTEM                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L104edit_system(cl_narg narg, cl_object v1name, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2force;
  cl_object v3version;
  cl_object v4test;
  cl_object v5verbose;
  cl_object v6dribble;
  ecl_va_list args; ecl_va_start(args,v1name,narg,1);
  {
   cl_object keyvars[10];
   cl_parse_key(args,5,L104edit_systemkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v2force = keyvars[0];
   if (Null(keyvars[6])) {
    v3version = ecl_symbol_value(VV[36]);
   } else {
    v3version = keyvars[1];
   }
   if (Null(keyvars[7])) {
    v4test = ecl_symbol_value(VV[17]);
   } else {
    v4test = keyvars[2];
   }
   if (Null(keyvars[8])) {
    v5verbose = ecl_symbol_value(VV[16]);
   } else {
    v5verbose = keyvars[3];
   }
   v6dribble = keyvars[4];
  }
  value0 = L100operate_on_system(12, v1name, VV[255], VV[244], v2force, ECL_SYM("VERSION",1326), v3version, ECL_SYM("TEST",1316), v4test, ECL_SYM("VERBOSE",1325), v5verbose, VV[249], v6dribble);
  return value0;
 }
}
/*	function definition for HARDCOPY-SYSTEM                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L105hardcopy_system(cl_narg narg, cl_object v1name, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2force;
  cl_object v3version;
  cl_object v4test;
  cl_object v5verbose;
  cl_object v6dribble;
  ecl_va_list args; ecl_va_start(args,v1name,narg,1);
  {
   cl_object keyvars[10];
   cl_parse_key(args,5,L105hardcopy_systemkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v2force = keyvars[0];
   if (Null(keyvars[6])) {
    v3version = ecl_symbol_value(VV[36]);
   } else {
    v3version = keyvars[1];
   }
   if (Null(keyvars[7])) {
    v4test = ecl_symbol_value(VV[17]);
   } else {
    v4test = keyvars[2];
   }
   if (Null(keyvars[8])) {
    v5verbose = ecl_symbol_value(VV[16]);
   } else {
    v5verbose = keyvars[3];
   }
   v6dribble = keyvars[4];
  }
  value0 = L100operate_on_system(12, v1name, VV[257], VV[244], v2force, ECL_SYM("VERSION",1326), v3version, ECL_SYM("TEST",1316), v4test, ECL_SYM("VERBOSE",1325), v5verbose, VV[249], v6dribble);
  return value0;
 }
}
/*	function definition for ENSURE-EXTERNAL-SYSTEM-DEF-LOADED     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L106ensure_external_system_def_loaded(cl_object v1component)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  goto L3;
L2:;
  si_assert_failure(1, VV[259]);
L3:;
  {
   cl_object v2;
   v2 = ecl_function_dispatch(cl_env_copy,VV[141])(1, v1component) /*  COMPONENT-TYPE */;
   if (!(ecl_eql(v2,VV[188]))) { goto L11; }
   goto L6;
   goto L9;
L11:;
   goto L9;
L9:;
   if (!(ecl_eql(v2,VV[122]))) { goto L14; }
   goto L6;
   goto L7;
L14:;
   goto L7;
  }
L7:;
  goto L2;
L6:;
  T0 = ecl_function_dispatch(cl_env_copy,VV[475])(1, v1component) /*  COMPONENT-COMPONENTS */;
  if (!(T0==ECL_NIL)) { goto L16; }
  {
   cl_object v2cname;
   v2cname = ecl_function_dispatch(cl_env_copy,VV[142])(1, v1component) /*  COMPONENT-NAME */;
   L22undefsystem(v2cname);
   {
    cl_object v3system_component;
    ecl_bds_bind(cl_env_copy,VV[152],ECL_T);      /*  *RELOAD-SYSTEMS-FROM-DISK* */
    T0 = ecl_function_dispatch(cl_env_copy,VV[142])(1, v1component) /*  COMPONENT-NAME */;
    v3system_component = L59find_system(2, T0, VV[154]);
    {
     cl_object v4;
     v4 = ecl_list1(v3system_component);
     value0 = ecl_structure_set(v1component,VV[89],17,v4);
     cl_env_copy->nvalues = 1;
     ecl_bds_unwind1(cl_env_copy);
     return value0;
    }
   }
  }
L16:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for OPERATE-ON-COMPONENT                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L107operate_on_component(cl_object volatile v1component, cl_object volatile v2operation, cl_object volatile v3force)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   volatile cl_object v4changed;
   v4changed = ECL_NIL;
   {
    volatile cl_object v5;
    volatile cl_object v6;
    v5 = ecl_function_dispatch(cl_env_copy,VV[141])(1, v1component) /*  COMPONENT-TYPE */;
    v6 = cl_package_name(ecl_symbol_value(ECL_SYM("*PACKAGE*",43)));
    {
     volatile bool unwinding = FALSE;
     cl_index v7=ECL_STACK_INDEX(cl_env_copy),v8;
     ecl_frame_ptr next_fr;
     if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
       unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
     } else {
     if (Null(ecl_function_dispatch(cl_env_copy,VV[473])(1, v1component) /*  COMPONENT-PACKAGE */)) { goto L7; }
     T0 = ecl_function_dispatch(cl_env_copy,VV[473])(1, v1component) /*  COMPONENT-PACKAGE */;
     T1 = cl_format(3, ECL_NIL, _ecl_static_108, T0);
     L95tell_user_generic(T1);
     if ((ecl_symbol_value(VV[17]))!=ECL_NIL) { goto L7; }
     T0 = ecl_function_dispatch(cl_env_copy,VV[473])(1, v1component) /*  COMPONENT-PACKAGE */;
     if ((cl_find_package(T0))!=ECL_NIL) { goto L11; }
     T0 = ecl_function_dispatch(cl_env_copy,VV[473])(1, v1component) /*  COMPONENT-PACKAGE */;
     T1 = cl_string(T0);
     T2 = ecl_function_dispatch(cl_env_copy,VV[142])(1, v1component) /*  COMPONENT-NAME */;
     if (Null(cl_string_equal(2, T1, T2))) { goto L13; }
     T0 = ecl_function_dispatch(cl_env_copy,VV[142])(1, v1component) /*  COMPONENT-NAME */;
     cl_format(3, ECL_T, _ecl_static_109, T0);
     T0 = ecl_function_dispatch(cl_env_copy,VV[473])(1, v1component) /*  COMPONENT-PACKAGE */;
     cl_error(2, _ecl_static_110, T0);
L13:;
     T0 = ecl_function_dispatch(cl_env_copy,VV[473])(1, v1component) /*  COMPONENT-PACKAGE */;
     L113new_require(1, T0);
L11:;
     {
      cl_object v9package;
      T0 = ecl_function_dispatch(cl_env_copy,VV[473])(1, v1component) /*  COMPONENT-PACKAGE */;
      v9package = cl_find_package(T0);
      if (Null(v9package)) { goto L7; }
      cl_set(ECL_SYM("*PACKAGE*",43),v9package);
     }
L7:;
     if ((v5)==(VV[122])) { goto L21; }
     if (!((v5)==(VV[188]))) { goto L19; }
     goto L20;
L21:;
L20:;
     L106ensure_external_system_def_loaded(v1component);
L19:;
     if ((v5)==(VV[132])) { goto L25; }
     if (!((v5)==(VV[122]))) { goto L23; }
     goto L24;
L25:;
L24:;
     L108operate_on_system_dependencies(3, v1component, v2operation, v3force);
L23:;
     if (Null(ecl_function_dispatch(cl_env_copy,VV[546])(1, v1component) /*  COMPONENT-PROCLAMATIONS */)) { goto L27; }
     T0 = ecl_function_dispatch(cl_env_copy,VV[142])(1, v1component) /*  COMPONENT-NAME */;
     T1 = cl_format(3, ECL_NIL, _ecl_static_111, T0);
     L95tell_user_generic(T1);
     if ((ecl_symbol_value(VV[17]))!=ECL_NIL) { goto L27; }
     T0 = ecl_function_dispatch(cl_env_copy,VV[546])(1, v1component) /*  COMPONENT-PROCLAMATIONS */;
     (cl_env_copy->function=(ECL_SYM("PROCLAIM",666)->symbol.gfdef))->cfun.entry(1, T0) /*  PROCLAIM */;
L27:;
     if (Null(ecl_function_dispatch(cl_env_copy,VV[547])(1, v1component) /*  COMPONENT-INITIALLY-DO */)) { goto L31; }
     T0 = ecl_function_dispatch(cl_env_copy,VV[142])(1, v1component) /*  COMPONENT-NAME */;
     T1 = cl_format(3, ECL_NIL, _ecl_static_112, T0);
     L95tell_user_generic(T1);
     if ((ecl_symbol_value(VV[17]))!=ECL_NIL) { goto L31; }
     ecl_bds_bind(cl_env_copy,VV[235],v1component); /*  %%COMPONENT%% */
     {
      cl_object v9initially_do;
      v9initially_do = ecl_function_dispatch(cl_env_copy,VV[547])(1, v1component) /*  COMPONENT-INITIALLY-DO */;
      if (Null(cl_functionp(v9initially_do))) { goto L36; }
      ecl_function_dispatch(cl_env_copy,v9initially_do)(0);
      ecl_bds_unwind1(cl_env_copy);
      goto L31;
L36:;
      cl_eval(v9initially_do);
      ecl_bds_unwind1(cl_env_copy);
     }
L31:;
     if (!(ecl_eql(v5,ECL_SYM("FILE",1237)))) { goto L45; }
     goto L42;
     goto L43;
L45:;
     goto L43;
L43:;
     if (!(ecl_eql(v5,VV[135]))) { goto L40; }
     goto L41;
L42:;
L41:;
     T0 = L7component_operation(1, v2operation);
     v4changed = ecl_function_dispatch(cl_env_copy,T0)(2, v1component, v3force);
     goto L39;
L40:;
     if (!(ecl_eql(v5,VV[199]))) { goto L54; }
     goto L51;
     goto L52;
L54:;
     goto L52;
L52:;
     if (!(ecl_eql(v5,VV[122]))) { goto L58; }
     goto L51;
     goto L56;
L58:;
     goto L56;
L56:;
     if (!(ecl_eql(v5,VV[188]))) { goto L62; }
     goto L51;
     goto L60;
L62:;
     goto L60;
L60:;
     if (!(ecl_eql(v5,VV[132]))) { goto L49; }
     goto L50;
L51:;
L50:;
     v4changed = L110operate_on_components(v1component, v2operation, v3force, v4changed);
     goto L39;
L49:;
     v4changed = ECL_NIL;
L39:;
     if (Null(ecl_function_dispatch(cl_env_copy,VV[548])(1, v1component) /*  COMPONENT-FINALLY-DO */)) { goto L65; }
     T0 = ecl_function_dispatch(cl_env_copy,VV[142])(1, v1component) /*  COMPONENT-NAME */;
     T1 = cl_format(3, ECL_NIL, _ecl_static_113, T0);
     L95tell_user_generic(T1);
     if ((ecl_symbol_value(VV[17]))!=ECL_NIL) { goto L68; }
     ecl_bds_bind(cl_env_copy,VV[235],v1component); /*  %%COMPONENT%% */
     {
      cl_object v9finally_do;
      v9finally_do = ecl_function_dispatch(cl_env_copy,VV[548])(1, v1component) /*  COMPONENT-FINALLY-DO */;
      if (Null(cl_functionp(v9finally_do))) { goto L71; }
      cl_env_copy->values[0] = ecl_function_dispatch(cl_env_copy,v9finally_do)(0);
      ecl_bds_unwind1(cl_env_copy);
      goto L6;
L71:;
      cl_env_copy->values[0] = cl_eval(v9finally_do);
      ecl_bds_unwind1(cl_env_copy);
      goto L6;
     }
L68:;
     cl_env_copy->values[0] = ECL_NIL;
     cl_env_copy->nvalues = 1;
     goto L6;
L65:;
     cl_env_copy->values[0] = ECL_NIL;
     cl_env_copy->nvalues = 1;
L6:;
     }
     ecl_frs_pop(cl_env_copy);
     v8=ecl_stack_push_values(cl_env_copy);
     cl_set(ECL_SYM("*PACKAGE*",43),cl_find_package(v6));
     ecl_stack_pop_values(cl_env_copy,v8);
     if (unwinding) ecl_unwind(cl_env_copy,next_fr);
     ECL_STACK_SET_INDEX(cl_env_copy,v7);
    }
    if ((v5)==(VV[132])) { goto L76; }
    if ((v5)==(VV[122])) { goto L76; }
    if (!((v5)==(VV[188]))) { goto L2; }
    goto L75;
L76:;
L75:;
    T0 = ecl_function_dispatch(cl_env_copy,VV[142])(1, v1component) /*  COMPONENT-NAME */;
    T1 = cl_format(3, ECL_NIL, _ecl_static_114, T0);
    L95tell_user_generic(T1);
    value0 = ecl_symbol_value(VV[17]);
    if ((value0)!=ECL_NIL) { goto L81; }
    T0 = ecl_function_dispatch(cl_env_copy,VV[142])(1, v1component) /*  COMPONENT-NAME */;
    T1 = L19canonicalize_system_name(T0);
    cl_provide(T1);
    goto L2;
L81:;
    goto L2;
   }
L2:;
   value0 = v4changed;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for OPERATE-ON-SYSTEM-DEPENDENCIES        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L108operate_on_system_dependencies(cl_narg narg, cl_object v1component, cl_object v2operation, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v3force;
  va_list args; va_start(args,v2operation);
  {
   int i = 2;
   if (i >= narg) {
    v3force = ECL_NIL;
   } else {
    i++;
    v3force = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (Null(ecl_symbol_value(VV[32]))) { goto L2; }
  ecl_bds_bind(cl_env_copy,VV[267],v3force);      /*  *FORCE*         */
  {
   cl_object v4;
   v4 = ecl_function_dispatch(cl_env_copy,VV[474])(1, v1component) /*  COMPONENT-DEPENDS-ON */;
   goto L7;
L6:;
   {
    cl_object v5system;
    v5system = ecl_car(v4);
    if (Null(ecl_symbol_value(VV[25]))) { goto L12; }
    if (ECL_LISTP(v5system)) { goto L12; }
    if (ECL_STRINGP(v5system)) { goto L17; }
    if (!(ECL_SYMBOLP(v5system))) { goto L12; }
    goto L16;
L17:;
L16:;
    if (Null(L59find_system(2, v5system, VV[155]))) { goto L12; }
    if (Null(ecl_symbol_value(VV[268]))) { goto L21; }
    {
     cl_object v6;
     v6 = si_make_seq_iterator(2, VV[218], ecl_make_fixnum(0));
L25:;
     if ((v6)!=ECL_NIL) { goto L27; }
     goto L21;
L27:;
     {
      cl_object v7;
      v7 = si_seq_iterator_ref(VV[218], v6);
      if (!(ecl_eql(v2operation,v7))) { goto L29; }
      if (Null(v7)) { goto L21; }
      goto L23;
     }
L29:;
     v6 = si_seq_iterator_next(VV[218], v6);
     goto L25;
    }
L23:;
    {
     cl_object v6;
     v6 = L19canonicalize_system_name(v5system);
     {
      cl_object v7;
      cl_object v8;
      v7 = ecl_symbol_value(ECL_SYM("*MODULES*",41));
      v8 = si_make_seq_iterator(2, v7, ecl_make_fixnum(0));
L37:;
      if ((v8)!=ECL_NIL) { goto L39; }
      goto L19;
L39:;
      {
       cl_object v9;
       v9 = si_seq_iterator_ref(v7, v8);
       if (Null(cl_string_equal(2, v6, v9))) { goto L41; }
       if ((v9)!=ECL_NIL) { goto L11; }
       goto L19;
      }
L41:;
      v8 = si_seq_iterator_next(v7, v8);
      goto L37;
     }
    }
L21:;
    goto L19;
L19:;
    L100operate_on_system(4, v5system, v2operation, VV[244], v3force);
    goto L11;
L12:;
    if (!(ECL_LISTP(v5system))) { goto L46; }
    {
     cl_object v6;
     cl_object v7system_name;
     cl_object v8definition_pathname;
     cl_object v9action;
     cl_object v10version;
     v6 = v5system;
     if (!(v6==ECL_NIL)) { goto L50; }
     si_dm_too_few_arguments(v5system);
L50:;
     {
      cl_object v11;
      v11 = ecl_car(v6);
      v6 = ecl_cdr(v6);
      v7system_name = v11;
     }
     if (!(v6==ECL_NIL)) { goto L56; }
     si_dm_too_few_arguments(v5system);
L56:;
     {
      cl_object v11;
      v11 = ecl_car(v6);
      v6 = ecl_cdr(v6);
      v8definition_pathname = v11;
     }
     if (!(v6==ECL_NIL)) { goto L62; }
     si_dm_too_few_arguments(v5system);
L62:;
     {
      cl_object v11;
      v11 = ecl_car(v6);
      v6 = ecl_cdr(v6);
      v9action = v11;
     }
     if (Null(v6)) { goto L68; }
     {
      cl_object v11;
      v11 = ecl_car(v6);
      v6 = ecl_cdr(v6);
      v10version = v11;
      goto L67;
     }
L68:;
     v10version = ECL_NIL;
L67:;
     if (Null(v6)) { goto L73; }
     si_dm_too_many_arguments(v5system);
L73:;
     if (!(v7system_name==ECL_NIL)) { goto L77; }
     if (!(v8definition_pathname==ECL_NIL)) { goto L77; }
     T0 = v9action;
     goto L76;
L77:;
     T0 = v5system;
L76:;
     L94tell_user_require_system(T0, v1component);
     value0 = ecl_symbol_value(VV[17]);
     if ((value0)!=ECL_NIL) { goto L81; }
     T0 = cl_eval(v8definition_pathname);
     value0 = v10version;
     if ((value0)!=ECL_NIL) { goto L85; }
     T1 = ecl_symbol_value(VV[36]);
     goto L83;
L85:;
     T1 = value0;
     goto L83;
L83:;
     L113new_require(5, v7system_name, ECL_NIL, T0, v9action, T1);
     goto L11;
L81:;
     goto L11;
    }
L46:;
    {
     cl_object v11;
     if (Null(ecl_function_dispatch(cl_env_copy,VV[92])(1, v5system) /*  COMPONENT-P */)) { goto L89; }
     {
      cl_object v12;
      v12 = ecl_function_dispatch(cl_env_copy,VV[141])(1, v5system) /*  COMPONENT-TYPE */;
      if (!(ecl_eql(v12,VV[132]))) { goto L97; }
      value0 = VV[269];
      goto L95;
L97:;
      value0 = ECL_NIL;
      goto L95;
L95:;
      if ((value0)!=ECL_NIL) { goto L94; }
      if (!(ecl_eql(v12,VV[188]))) { goto L101; }
      value0 = VV[260];
      goto L99;
L101:;
      value0 = ECL_NIL;
      goto L99;
L99:;
      if ((value0)!=ECL_NIL) { goto L94; }
      if (!(ecl_eql(v12,VV[122]))) { goto L104; }
      T0 = VV[198];
      goto L91;
L104:;
      T0 = ECL_NIL;
      goto L91;
L94:;
      T0 = value0;
      goto L91;
     }
L91:;
     v11 = Null(T0)?ECL_T:ECL_NIL;
     goto L87;
L89:;
     v11 = ECL_NIL;
     goto L87;
L87:;
     if (Null(v11)) { goto L106; }
     goto L11;
L106:;
     L94tell_user_require_system(v5system, v1component);
     value0 = ecl_symbol_value(VV[17]);
     if ((value0)!=ECL_NIL) { goto L110; }
     L113new_require(1, v5system);
     goto L11;
L110:;
     goto L11;
    }
L11:;
   }
   v4 = ecl_cdr(v4);
L7:;
   if (Null(v4)) { goto L114; }
   goto L6;
L114:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for MODULE-DEPENDS-ON-CHANGED             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L109module_depends_on_changed(cl_object v1module, cl_object v2changed)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_function_dispatch(cl_env_copy,VV[474])(1, v1module) /*  COMPONENT-DEPENDS-ON */;
   goto L4;
L3:;
   {
    cl_object v4dependent;
    v4dependent = ecl_car(v3);
    if (Null(ecl_memql(v4dependent,v2changed))) { goto L8; }
    value0 = ECL_T;
    cl_env_copy->nvalues = 1;
    return value0;
L8:;
   }
   v3 = ecl_cdr(v3);
L4:;
   if (Null(v3)) { goto L12; }
   goto L3;
L12:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for OPERATE-ON-COMPONENTS                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L110operate_on_components(cl_object v1component, cl_object v2operation, cl_object v3force, cl_object v4changed)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  L90tell_user(5, v2operation, v1component, ECL_NIL, ECL_NIL, ECL_NIL);
  if (Null(ecl_function_dispatch(cl_env_copy,VV[475])(1, v1component) /*  COMPONENT-COMPONENTS */)) { goto L4; }
  {
   cl_object v5;
   v5 = ecl_function_dispatch(cl_env_copy,VV[475])(1, v1component) /*  COMPONENT-COMPONENTS */;
   goto L9;
L8:;
   {
    cl_object v6module;
    v6module = ecl_car(v5);
    if (Null(L109module_depends_on_changed(v6module, v4changed))) { goto L16; }
    if ((L6non_empty_listp(v3force))!=ECL_NIL) { goto L19; }
    if (!((v3force)==(VV[239]))) { goto L16; }
    goto L17;
L19:;
L17:;
    if (!((v3force)==(VV[239]))) { goto L21; }
    T0 = VV[272];
    goto L15;
L21:;
    T0 = VV[238];
    goto L15;
L16:;
    if (Null(L6non_empty_listp(v3force))) { goto L23; }
    {
     cl_object v7;
     v7 = ecl_function_dispatch(cl_env_copy,VV[142])(1, v6module) /*  COMPONENT-NAME */;
     {
      cl_object v8;
      v8 = v3force;
      goto L30;
L29:;
      {
       cl_object v9;
       cl_object v10;
       if (ecl_unlikely(ECL_ATOM(v8))) FEtype_error_cons(v8);
       v9 = v8;
       v10 = ECL_CONS_CAR(v9);
       T1 = cl_string(v10);
       if (Null(cl_string_equal(2, v7, T1))) { goto L32; }
       if (Null(v9)) { goto L23; }
       goto L24;
      }
L32:;
      v8 = ECL_CONS_CDR(v8);
L30:;
      if (v8==ECL_NIL) { goto L39; }
      goto L29;
L39:;
      goto L23;
     }
    }
L24:;
    T0 = VV[238];
    goto L15;
L23:;
    T0 = v3force;
L15:;
    if (Null(L107operate_on_component(v6module, v2operation, T0))) { goto L13; }
    v4changed = CONS(v6module,v4changed);
L13:;
   }
   v5 = ecl_cdr(v5);
L9:;
   if (Null(v5)) { goto L44; }
   goto L8;
L44:;
   goto L3;
  }
L4:;
  if (!((v2operation)==(ECL_SYM("COMPILE",233)))) { goto L51; }
  goto L48;
  goto L49;
L51:;
  goto L49;
L49:;
  if (!(ecl_eql(v2operation,VV[216]))) { goto L46; }
  goto L47;
L48:;
L47:;
  ecl_bds_bind(cl_env_copy,VV[235],v1component);  /*  %%COMPONENT%%   */
  {
   cl_object v6compile_form;
   v6compile_form = ecl_function_dispatch(cl_env_copy,VV[552])(1, v1component) /*  COMPONENT-COMPILE-FORM */;
   if (Null(cl_functionp(v6compile_form))) { goto L55; }
   ecl_function_dispatch(cl_env_copy,v6compile_form)(0);
   ecl_bds_unwind1(cl_env_copy);
   goto L3;
L55:;
   cl_eval(v6compile_form);
   ecl_bds_unwind1(cl_env_copy);
   goto L3;
  }
L46:;
  if (!((v2operation)==(ECL_SYM("LOAD",487)))) { goto L61; }
  goto L58;
  goto L59;
L61:;
  goto L59;
L59:;
  if (!(ecl_eql(v2operation,VV[154]))) { goto L3; }
  goto L57;
L58:;
L57:;
  ecl_bds_bind(cl_env_copy,VV[235],v1component);  /*  %%COMPONENT%%   */
  {
   cl_object v7load_form;
   v7load_form = ecl_function_dispatch(cl_env_copy,VV[553])(1, v1component) /*  COMPONENT-LOAD-FORM */;
   if (Null(cl_functionp(v7load_form))) { goto L65; }
   ecl_function_dispatch(cl_env_copy,v7load_form)(0);
   ecl_bds_unwind1(cl_env_copy);
   goto L3;
L65:;
   cl_eval(v7load_form);
   ecl_bds_unwind1(cl_env_copy);
  }
L3:;
  L91tell_user_done(3, v1component, ECL_NIL, ECL_NIL);
  value0 = v4changed;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for NEW-REQUIRE                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L113new_require(volatile cl_narg narg, cl_object volatile v1module_name, ...)
{
 cl_object T0, T1, T2, T3, T4, T5;
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>5)) FEwrong_num_arguments_anonym();
 {
  volatile cl_object v2pathname;
  volatile cl_object v3definition_pname;
  volatile cl_object v4default_action;
  volatile cl_object v5version;
  va_list args; va_start(args,v1module_name);
  {
   int i = 1;
   if (i >= narg) {
    v2pathname = ECL_NIL;
   } else {
    i++;
    v2pathname = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v3definition_pname = ECL_NIL;
   } else {
    i++;
    v3definition_pname = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v4default_action = ECL_NIL;
   } else {
    i++;
    v4default_action = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v5version = ecl_symbol_value(VV[36]);
   } else {
    i++;
    v5version = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (Null(v1module_name)) { goto L8; }
  {
   cl_object v6;
   v6 = cl_string(v1module_name);
   {
    cl_object v7;
    cl_object v8;
    v7 = ecl_symbol_value(ECL_SYM("*MODULES*",41));
    v8 = si_make_seq_iterator(2, v7, ecl_make_fixnum(0));
L13:;
    if ((v8)!=ECL_NIL) { goto L15; }
    goto L6;
L15:;
    {
     cl_object v9;
     v9 = si_seq_iterator_ref(v7, v8);
     if (Null(cl_stringE(2, v6, v9))) { goto L17; }
     if ((v9)!=ECL_NIL) { goto L5; }
     goto L6;
    }
L17:;
    v8 = si_seq_iterator_next(v7, v8);
    goto L13;
   }
  }
L8:;
  goto L6;
L6:;
  {
   volatile cl_object env1 = env0;
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(ECL_NIL,env1);
   {
    volatile cl_object env2 = env1;
    CLV1 = env2 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env2); /*  TAGBODY */
    if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV1))) {
    if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L22;
    if (cl_env_copy->values[0]==ecl_make_fixnum(1))goto L23;
    ecl_internal_error("GO found an inexistent tag");
    }
    {cl_object v6;
     v6 = ECL_NIL;
     v6 = ecl_make_cclosure_va((cl_objectfn)LC111__g658,env2,Cblock);
     T0 = v6;
    }
    T1 = CONS(VV[129],T0);
    {cl_object v6;
     v6 = ECL_NIL;
     v6 = ecl_make_cclosure_va((cl_objectfn)LC112__g659,env2,Cblock);
     T2 = v6;
    }
    T3 = CONS(ECL_SYM("ERROR",337),T2);
    T4 = cl_list(2, T1, T3);
    T5 = CONS(T4,ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5)));
    ecl_bds_bind(cl_env_copy,ECL_SYM("*HANDLER-CLUSTERS*",5),T5); /*  *HANDLER-CLUSTERS* */
    if (Null(v2pathname)) { goto L27; }
    value0 = ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[274]))(2, v1module_name, v2pathname);
    ecl_frs_pop(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    return value0;
L27:;
    if (Null(L59find_system(3, v1module_name, VV[155], v3definition_pname))) { goto L29; }
    value0 = L100operate_on_system(20, v1module_name, VV[154], VV[244], ecl_symbol_value(VV[267]), ECL_SYM("VERSION",1326), v5version, ECL_SYM("TEST",1316), ecl_symbol_value(VV[17]), ECL_SYM("VERBOSE",1325), ecl_symbol_value(VV[16]), VV[246], ecl_symbol_value(VV[18]), VV[247], ecl_symbol_value(VV[19]), VV[248], ecl_symbol_value(VV[21]), VV[245], ecl_symbol_value(VV[20]), VV[250], ecl_symbol_value(VV[23]));
    ecl_frs_pop(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    return value0;
L29:;
    {
     cl_object v6;
     if (Null(v4default_action)) { goto L33; }
     v6 = cl_eval(v4default_action);
     goto L31;
L33:;
     v6 = ECL_NIL;
     goto L31;
L31:;
     if (Null(v6)) { goto L35; }
     value0 = v6;
     cl_env_copy->nvalues = 1;
     ecl_frs_pop(cl_env_copy);
     ecl_bds_unwind1(cl_env_copy);
     return value0;
L35:;
     {
      cl_object v7;
      v7 = ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[274]))(1, v1module_name);
      if (Null(v7)) { goto L38; }
      value0 = v7;
      cl_env_copy->nvalues = 1;
      ecl_frs_pop(cl_env_copy);
      ecl_bds_unwind1(cl_env_copy);
      return value0;
L38:;
      value0 = cl_error(3, VV[130], ECL_SYM("NAME",1273), v1module_name);
      ecl_frs_pop(cl_env_copy);
      ecl_bds_unwind1(cl_env_copy);
      return value0;
     }
    }
L22:;
    {
     cl_object v6mmc;
     v6mmc = ECL_CONS_CAR(CLV0);
     value0 = (cl_env_copy->function=(ECL_SYM("SIGNAL",760)->symbol.gfdef))->cfun.entry(1, v6mmc) /*  SIGNAL */;
     ecl_frs_pop(cl_env_copy);
     return value0;
    }
L23:;
    value0 = cl_error(3, VV[130], ECL_SYM("NAME",1273), v1module_name);
    ecl_frs_pop(cl_env_copy);
    return value0;
   }
  }
L5:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	closure G658                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC111__g658(cl_narg narg, cl_object v1si__temp, ...)
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
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  ECL_CONS_CAR(CLV0) = v1si__temp;
  cl_go(ECL_CONS_CAR(CLV1),ecl_make_fixnum(0));
 }
 }
}
/*	closure G659                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC112__g659(cl_narg narg, cl_object v1si__temp, ...)
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
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  ECL_CONS_CAR(CLV0) = v1si__temp;
  cl_go(ECL_CONS_CAR(CLV1),ecl_make_fixnum(1));
 }
 }
}
/*	function definition for CMUCL-MK-DEFSYSTEM-MODULE-PROVIDER    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L114cmucl_mk_defsystem_module_provider(cl_object v1name)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2module_name;
   T0 = cl_string(v1name);
   v2module_name = cl_string_downcase(1, T0);
   if (Null(L59find_system(2, v2module_name, VV[155]))) { goto L2; }
   value0 = L102load_system(5, v2module_name, VV[248], ECL_T, ECL_SYM("VERBOSE",1325), ECL_NIL);
   return value0;
L2:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for FIND-LANGUAGE                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L115find_language(cl_object v1name)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_gethash(2, v1name, ecl_symbol_value(VV[277]));
  return value0;
 }
}
/*	function definition for MAKE-LANGUAGE                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L116make_language(cl_narg narg, ...)
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
   cl_parse_key(args,5,L116make_languagekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v1 = keyvars[0];
   v2 = keyvars[1];
   v3 = keyvars[2];
   v4 = keyvars[3];
   v5 = keyvars[4];
  }
  value0 = si_make_structure(6, VV[282], v1, v2, v3, v4, v5);
  return value0;
 }
}
/*	function definition for PRINT-LANGUAGE                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L117print_language(cl_object v1language, cl_object v2stream, cl_object v3depth)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[564])(1, v1language) /*  LANGUAGE-NAME */;
  T1 = ecl_function_dispatch(cl_env_copy,VV[565])(1, v1language) /*  LANGUAGE-SOURCE-EXTENSION */;
  T2 = ecl_function_dispatch(cl_env_copy,VV[566])(1, v1language) /*  LANGUAGE-BINARY-EXTENSION */;
  value0 = cl_format(5, v2stream, _ecl_static_117, T0, T1, T2);
  return value0;
 }
}
/*	function definition for COMPILE-FUNCTION                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L118compile_function(cl_object v1component)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[495])(1, v1component) /*  COMPONENT-COMPILER */;
  if ((value0)!=ECL_NIL) { goto L2; }
  {
   cl_object v2language;
   value0 = ecl_function_dispatch(cl_env_copy,VV[494])(1, v1component) /*  COMPONENT-LANGUAGE */;
   if ((value0)!=ECL_NIL) { goto L8; }
   T0 = VV[285];
   goto L6;
L8:;
   T0 = value0;
   goto L6;
L6:;
   v2language = L115find_language(T0);
   if (Null(v2language)) { goto L10; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[568])(1, v2language) /*  LANGUAGE-COMPILER */;
   goto L4;
L10:;
   value0 = ECL_NIL;
  }
L4:;
  if ((value0)!=ECL_NIL) { goto L2; }
  value0 = (ECL_SYM("COMPILE-FILE",234)->symbol.gfdef);
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for LOAD-FUNCTION                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L119load_function(cl_object v1component)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[496])(1, v1component) /*  COMPONENT-LOADER */;
  if ((value0)!=ECL_NIL) { goto L2; }
  {
   cl_object v2language;
   value0 = ecl_function_dispatch(cl_env_copy,VV[494])(1, v1component) /*  COMPONENT-LANGUAGE */;
   if ((value0)!=ECL_NIL) { goto L8; }
   T0 = VV[285];
   goto L6;
L8:;
   T0 = value0;
   goto L6;
L6:;
   v2language = L115find_language(T0);
   if (Null(v2language)) { goto L10; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[570])(1, v2language) /*  LANGUAGE-LOADER */;
   goto L4;
L10:;
   value0 = ECL_NIL;
  }
L4:;
  if ((value0)!=ECL_NIL) { goto L2; }
  value0 = (ECL_SYM("LOAD",487)->symbol.gfdef);
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for DEFAULT-SOURCE-EXTENSION              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L120default_source_extension(cl_object v1component)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2language;
   value0 = ecl_function_dispatch(cl_env_copy,VV[494])(1, v1component) /*  COMPONENT-LANGUAGE */;
   if ((value0)!=ECL_NIL) { goto L4; }
   T0 = VV[285];
   goto L2;
L4:;
   T0 = value0;
   goto L2;
L2:;
   v2language = L115find_language(T0);
   if (Null(v2language)) { goto L9; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[565])(1, v2language) /*  LANGUAGE-SOURCE-EXTENSION */;
   goto L8;
L9:;
   value0 = ECL_NIL;
L8:;
   if ((value0)!=ECL_NIL) { goto L7; }
   value0 = ecl_car(ecl_symbol_value(VV[30]));
   cl_env_copy->nvalues = 1;
   return value0;
L7:;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for DEFAULT-BINARY-EXTENSION              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L121default_binary_extension(cl_object v1component)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2language;
   value0 = ecl_function_dispatch(cl_env_copy,VV[494])(1, v1component) /*  COMPONENT-LANGUAGE */;
   if ((value0)!=ECL_NIL) { goto L4; }
   T0 = VV[285];
   goto L2;
L4:;
   T0 = value0;
   goto L2;
L2:;
   v2language = L115find_language(T0);
   if (Null(v2language)) { goto L9; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[566])(1, v2language) /*  LANGUAGE-BINARY-EXTENSION */;
   goto L8;
L9:;
   value0 = ECL_NIL;
L8:;
   if ((value0)!=ECL_NIL) { goto L7; }
   value0 = ecl_cdr(ecl_symbol_value(VV[30]));
   cl_env_copy->nvalues = 1;
   return value0;
L7:;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function DEFINE-LANGUAGE                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC122define_language(cl_object v1, cl_object v2)
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
   cl_object v5;
   cl_object v6compiler;
   cl_object v7;
   cl_object v8loader;
   cl_object v9;
   cl_object v10source_extension;
   cl_object v11;
   cl_object v12binary_extension;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v13;
    v13 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4name = v13;
   }
   v5 = si_search_keyword(2, v3, VV[290]);
   if (!((v5)==(ECL_SYM("MISSING-KEYWORD",1929)))) { goto L10; }
   v6compiler = ECL_NIL;
   goto L9;
L10:;
   v6compiler = v5;
L9:;
   v7 = si_search_keyword(2, v3, VV[291]);
   if (!((v7)==(ECL_SYM("MISSING-KEYWORD",1929)))) { goto L14; }
   v8loader = ECL_NIL;
   goto L13;
L14:;
   v8loader = v7;
L13:;
   v9 = si_search_keyword(2, v3, VV[292]);
   if (!((v9)==(ECL_SYM("MISSING-KEYWORD",1929)))) { goto L18; }
   v10source_extension = ECL_NIL;
   goto L17;
L18:;
   v10source_extension = v9;
L17:;
   v11 = si_search_keyword(2, v3, VV[293]);
   if (!((v11)==(ECL_SYM("MISSING-KEYWORD",1929)))) { goto L22; }
   v12binary_extension = ECL_NIL;
   goto L21;
L22:;
   v12binary_extension = v11;
L21:;
   si_check_keyword(2, v3, VV[294]);
   {
    cl_object v13language;
    v13language = cl_gensym(1, _ecl_static_118);
    T0 = cl_list(11, VV[283], ECL_SYM("NAME",1273), v4name, VV[290], v6compiler, VV[291], v8loader, VV[292], v10source_extension, VV[293], v12binary_extension);
    T1 = cl_list(2, v13language, T0);
    T2 = ecl_list1(T1);
    T3 = cl_list(3, ECL_SYM("GETHASH",413), v4name, VV[277]);
    T4 = cl_list(3, ECL_SYM("SETF",750), T3, v13language);
    value0 = cl_list(4, ECL_SYM("LET",477), T2, T4, v4name);
    return value0;
   }
  }
 }
}
/*	function definition for SCHEME-COMPILE-FILE                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L123scheme_compile_file(cl_narg narg, cl_object v1filename, ...)
{
 cl_object T0, T1, T2, T3, T4, T5, T6;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2args;
  ecl_va_list args; ecl_va_start(args,v1filename,narg,1);
  v2args = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v3scheme_package;
   v3scheme_package = cl_find_package(VV[296]);
   T0 = ecl_symbol_name(ECL_SYM("COMPILE-FILE",234));
   T1 = cl_find_symbol(2, T0, v3scheme_package);
   T2 = cl_symbol_function(T1);
   T5 = ecl_symbol_name(VV[297]);
   T6 = cl_find_symbol(2, T5, v3scheme_package);
   T4 = cl_symbol_function(T6);
   T3 = ecl_function_dispatch(cl_env_copy,T4)(0);
   value0 = cl_apply(4, T2, v1filename, T3, v2args);
   return value0;
  }
 }
}
/*	function definition for RUN-UNIX-PROGRAM                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L124run_unix_program(cl_object v1program, cl_object v2arguments)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_format(4, ECL_NIL, _ecl_static_122, v1program, v2arguments);
  value0 = ecl_function_dispatch(cl_env_copy,VV[576])(1, T0) /*  SYSTEM */;
  return value0;
 }
}
/*	function definition for RUN-SHELL-COMMAND                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L125run_shell_command(cl_narg narg, cl_object v1command_control_string, cl_object v2arguments, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3output;
  cl_object v4shell;
  ecl_va_list args; ecl_va_start(args,v2arguments,narg,2);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L125run_shell_commandkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[2])) {
    v3output = ecl_symbol_value(ECL_SYM("*TRACE-OUTPUT*",69));
   } else {
    v3output = keyvars[0];
   }
   if (Null(keyvars[3])) {
    v4shell = ecl_symbol_value(VV[302]);
   } else {
    v4shell = keyvars[1];
   }
  }
  {
   cl_object v5command;
   T0 = (ECL_SYM("FORMAT",387)->symbol.gfdef);
   v5command = cl_apply(4, T0, ECL_NIL, v1command_control_string, v2arguments);
   value0 = cl_error(1, _ecl_static_124);
   return value0;
  }
 }
}
/*	function definition for DEFAULT-OUTPUT-PATHNAME               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L126default_output_pathname(cl_object v1path1, cl_object v2path2, cl_object v3type)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!((v1path1)==(ECL_T))) { goto L1; }
  T0 = cl_make_pathname(2, ECL_SYM("TYPE",1318), v3type);
  T1 = cl_pathname(v2path2);
  T2 = cl_merge_pathnames(2, T0, T1);
  value0 = cl_translate_logical_pathname(1, T2);
  return value0;
L1:;
  T0 = cl_pathname(v1path1);
  value0 = cl_translate_logical_pathname(1, T0);
  return value0;
 }
}
/*	function definition for RUN-COMPILER                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L128run_compiler(cl_object volatile v1program, cl_object volatile v2arguments, cl_object volatile v3output_file, cl_object volatile v4error_file, cl_object volatile v5error_output, cl_object volatile v6verbose)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   volatile cl_object v7;
   volatile cl_object v8verbose_stream;
   volatile cl_object v9fatal_error;
   volatile cl_object v10output_file_written;
   v7 = cl_file_write_date(v3output_file);
   v8verbose_stream = ECL_NIL;
   v9fatal_error = ECL_NIL;
   v10output_file_written = ECL_NIL;
   {
    volatile bool unwinding = FALSE;
    cl_index v11=ECL_STACK_INDEX(cl_env_copy),v12;
    ecl_frame_ptr next_fr;
    if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
      unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
    } else {
    if (Null(v6verbose)) { goto L10; }
    T0 = ecl_symbol_value(ECL_SYM("*TRACE-OUTPUT*",69));
    goto L8;
L10:;
    T0 = ECL_NIL;
    goto L8;
L8:;
    v8verbose_stream = LC127make_useable_stream(1, T0);
    cl_format(4, v8verbose_stream, _ecl_static_125, v1program, v2arguments);
    if (Null(L124run_unix_program(v1program, v2arguments))) { goto L16; }
    v9fatal_error = ECL_NIL;
    goto L14;
L16:;
    v9fatal_error = ECL_NIL;
    goto L14;
L14:;
    if (Null(cl_probe_file(v3output_file))) { goto L21; }
    T0 = cl_file_write_date(v3output_file);
    {
     bool v13;
     v13 = ecl_eql(v7,T0);
     v10output_file_written = (v13)?ECL_NIL:ECL_T;
     goto L19;
    }
L21:;
    v10output_file_written = ECL_NIL;
    goto L19;
L19:;
    if (Null(v10output_file_written)) { goto L23; }
    cl_format(3, v8verbose_stream, _ecl_static_126, v3output_file);
L23:;
    cl_format(3, v8verbose_stream, _ecl_static_127, v1program);
    if (Null(v10output_file_written)) { goto L28; }
    T0 = v3output_file;
    goto L26;
L28:;
    T0 = ECL_NIL;
    goto L26;
L26:;
    cl_env_copy->nvalues = 3;
    cl_env_copy->values[2] = v9fatal_error;
    cl_env_copy->values[1] = v9fatal_error;
    cl_env_copy->values[0] = T0;
    }
    ecl_frs_pop(cl_env_copy);
    v12=ecl_stack_push_values(cl_env_copy);
    if (Null(v10output_file_written)) { goto L33; }
    goto L31;
L33:;
    goto L31;
L31:;
    ecl_stack_pop_values(cl_env_copy,v12);
    if (unwinding) ecl_unwind(cl_env_copy,next_fr);
    ECL_STACK_SET_INDEX(cl_env_copy,v11);
    return cl_env_copy->values[0];
   }
  }
 }
}
/*	local function MAKE-USEABLE-STREAM                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC127make_useable_stream(cl_narg narg, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1streams;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1streams = cl_grab_rest_args(args);
  ecl_va_end(args);
  T0 = (ECL_SYM("MAKE-BROADCAST-STREAM",523)->symbol.gfdef);
  T1 = cl_delete(2, ECL_NIL, v1streams);
  value0 = cl_apply(2, T0, T1);
  return value0;
 }
}
/*	function definition for C-COMPILE-FILE                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L131c_compile_file(cl_narg narg, cl_object v1filename, ...)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2output_file;
  cl_object v3error_file;
  cl_object v4error_output;
  cl_object v5verbose;
  cl_object v6debug;
  cl_object v7link;
  cl_object v8optimize;
  cl_object v9cflags;
  cl_object v10definitions;
  cl_object v11include_paths;
  cl_object v12library_paths;
  cl_object v13libraries;
  cl_object v14error;
  ecl_va_list args; ecl_va_start(args,v1filename,narg,1);
  {
   cl_object keyvars[26];
   cl_parse_key(args,13,L131c_compile_filekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[13])) {
    v2output_file = ECL_T;
   } else {
    v2output_file = keyvars[0];
   }
   if (Null(keyvars[14])) {
    v3error_file = ECL_T;
   } else {
    v3error_file = keyvars[1];
   }
   if (Null(keyvars[15])) {
    v4error_output = ECL_T;
   } else {
    v4error_output = keyvars[2];
   }
   if (Null(keyvars[16])) {
    v5verbose = ecl_symbol_value(ECL_SYM("*COMPILE-VERBOSE*",29));
   } else {
    v5verbose = keyvars[3];
   }
   v6debug = keyvars[4];
   v7link = keyvars[5];
   v8optimize = keyvars[6];
   v9cflags = keyvars[7];
   v10definitions = keyvars[8];
   v11include_paths = keyvars[9];
   v12library_paths = keyvars[10];
   v13libraries = keyvars[11];
   if (Null(keyvars[25])) {
    v14error = ECL_T;
   } else {
    v14error = keyvars[12];
   }
  }
  {
   cl_object v15output_file;
   cl_object v16arguments;
   v15output_file = L126default_output_pathname(v2output_file, v1filename, _ecl_static_129);
   if ((v7link)!=ECL_NIL) { goto L9; }
   T0 = VV[306];
   goto L8;
L9:;
   T0 = ECL_NIL;
L8:;
   if (Null(v6debug)) { goto L12; }
   T1 = VV[307];
   goto L11;
L12:;
   T1 = ECL_NIL;
L11:;
   if (Null(v8optimize)) { goto L15; }
   T3 = cl_format(3, ECL_NIL, _ecl_static_130, v8optimize);
   T2 = ecl_list1(T3);
   goto L14;
L15:;
   T2 = ECL_NIL;
L14:;
   {cl_object v17;
    v17 = ECL_NIL;
    v17 = ecl_make_cfun((cl_objectfn_fixed)LC130__g701,ECL_NIL,Cblock,1);
    T4 = v17;
   }
   T3 = LC129map_options(3, _ecl_static_131, v10definitions, T4);
   T5 = (ECL_SYM("TRUENAME",864)->symbol.gfdef);
   T4 = LC129map_options(3, _ecl_static_133, v11include_paths, T5);
   T5 = cl_truename(v1filename);
   T6 = cl_namestring(T5);
   T7 = cl_translate_logical_pathname(1, v15output_file);
   T8 = cl_namestring(T7);
   T10 = (ECL_SYM("TRUENAME",864)->symbol.gfdef);
   T9 = LC129map_options(3, _ecl_static_135, v12library_paths, T10);
   T10 = LC129map_options(2, _ecl_static_136, v13libraries);
   T11 = ecl_append(T9,T10);
   T12 = cl_listX(4, T6, _ecl_static_134, T8, T11);
   v16arguments = cl_append(7, T0, T1, T2, v9cflags, T3, T4, T12);
   {
    cl_object v18;                                /*  OUTPUT-FILE     */
    cl_object v19;                                /*  WARNINGS        */
    cl_object v20;                                /*  FATAL-ERRORS    */
    value0 = L128run_compiler(ecl_symbol_value(VV[300]), v16arguments, v15output_file, v3error_file, v4error_output, v5verbose);
    v18 = value0;
    {
     const int v21 = cl_env_copy->nvalues;
     cl_object v22;
     v22 = (v21<=1)? ECL_NIL : cl_env_copy->values[1];
     v19 = v22;
     v22 = (v21<=2)? ECL_NIL : cl_env_copy->values[2];
     v20 = v22;
    }
    if (Null(v14error)) { goto L25; }
    if (Null(v18)) { goto L28; }
    if (Null(v20)) { goto L25; }
    goto L26;
L28:;
L26:;
    value0 = cl_error(1, _ecl_static_137);
    return value0;
L25:;
    cl_env_copy->nvalues = 3;
    cl_env_copy->values[2] = v20;
    cl_env_copy->values[1] = v19;
    cl_env_copy->values[0] = v18;
    return cl_env_copy->values[0];
   }
  }
 }
}
/*	local function MAP-OPTIONS                                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC129map_options(cl_narg narg, cl_object v1flag, cl_object v2options, ...)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v3func;
  va_list args; va_start(args,v2options);
  {
   int i = 2;
   if (i >= narg) {
    v3func = (ECL_SYM("IDENTITY",426)->symbol.gfdef);
   } else {
    i++;
    v3func = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v4;
   cl_object v5;
   v4 = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v2options))) FEtype_error_list(v2options);
   v5 = v2options;
   {
    cl_object v6;
    cl_object v7;
    v6 = ecl_list1(ECL_NIL);
    v7 = v6;
L7:;
    if (!(ecl_endp(v5))) { goto L9; }
    goto L8;
L9:;
    v4 = _ecl_car(v5);
    {
     cl_object v8;
     v8 = _ecl_cdr(v5);
     if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
     v5 = v8;
    }
    if (ecl_unlikely(ECL_ATOM(v7))) FEtype_error_cons(v7);
    T0 = v7;
    T2 = ecl_function_dispatch(cl_env_copy,v3func)(1, v4);
    T1 = cl_format(4, ECL_NIL, _ecl_static_128, v1flag, T2);
    v7 = ecl_list1(T1);
    (ECL_CONS_CDR(T0)=v7,T0);
    goto L7;
L8:;
    value0 = ecl_cdr(v6);
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	local function G701                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC130__g701(cl_object v1definition)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_ATOM(v1definition))) { goto L1; }
  value0 = v1definition;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  T0 = (ECL_SYM("FORMAT",387)->symbol.gfdef);
  value0 = cl_apply(4, T0, ECL_NIL, _ecl_static_132, v1definition);
  return value0;
 }
}
/*	function definition for FORTRAN-COMPILE-FILE                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L132fortran_compile_file(cl_narg narg, cl_object v1filename, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2output_file;
  cl_object v3error_file;
  ecl_va_list args; ecl_va_start(args,v1filename,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L132fortran_compile_filekeys,keyvars,NULL,TRUE);
   ecl_va_end(args);
   v2output_file = keyvars[0];
   v3error_file = keyvars[1];
  }
  {
   cl_object v4arg_list;
   if (Null(v2output_file)) { goto L3; }
   T0 = cl_list(2, _ecl_static_134, v2output_file);
   goto L2;
L3:;
   T0 = ECL_NIL;
L2:;
   T1 = cl_listX(3, _ecl_static_140, v1filename, T0);
   v4arg_list = ecl_append(ecl_symbol_value(VV[311]),T1);
   value0 = L124run_unix_program(ecl_symbol_value(VV[310]), v4arg_list);
   return value0;
  }
 }
}
/*	function definition for BUILD-LIB                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L133build_lib(cl_object v1libname, cl_object v2directory)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3args;
   T0 = cl_truename(v1libname);
   v3args = cl_list(2, _ecl_static_143, T0);
   cl_format(3, ECL_T, _ecl_static_144, v1libname);
   T0 = ecl_symbol_value(VV[314]);
   {
    cl_object v4;
    cl_object v5;
    cl_object v6;
    v4 = cl_directory(1, v2directory);
    v5 = ECL_NIL;
    v6 = v4;
    {
     cl_object v7;
     cl_object v8;
     v7 = ecl_list1(ECL_NIL);
     v8 = v7;
L9:;
     if (!(ecl_endp(v6))) { goto L11; }
     goto L10;
L11:;
     v5 = _ecl_car(v6);
     {
      cl_object v9;
      v9 = _ecl_cdr(v6);
      if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
      v6 = v9;
     }
     if (ecl_unlikely(ECL_ATOM(v8))) FEtype_error_cons(v8);
     T2 = v8;
     T3 = cl_truename(v5);
     v8 = ecl_list1(T3);
     (ECL_CONS_CDR(T2)=v8,T2);
     goto L9;
L10:;
     T1 = ecl_cdr(v7);
     goto L3;
    }
   }
L3:;
   T2 = ecl_append(v3args,T1);
   value0 = L124run_unix_program(T0, T2);
   return value0;
  }
 }
}
/*	function definition for COMPILE-AND-LOAD-OPERATION            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L134compile_and_load_operation(cl_object v1component, cl_object v2force)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3changed;
   v3changed = L136compile_file_operation(v1component, v2force);
   if (Null(v3changed)) { goto L2; }
   if (Null(ecl_function_dispatch(cl_env_copy,VV[488])(1, v1component) /*  COMPONENT-COMPILE-ONLY */)) { goto L2; }
   value0 = v3changed;
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
   if (Null(L140load_file_operation(v1component, v2force))) { goto L6; }
   value0 = v3changed;
   cl_env_copy->nvalues = 1;
   return value0;
L6:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for UNMUNGE-LUCID                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L135unmunge_lucid(cl_object v1namestring)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(L13null_string(v1namestring))) { goto L1; }
  value0 = v1namestring;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  {
   ecl_character v2;
   v2 = ecl_char(v1namestring,0);
   if (!((v2)==((ecl_character)(47)))) { goto L3; }
  }
  value0 = v1namestring;
  cl_env_copy->nvalues = 1;
  return value0;
L3:;
  value0 = cl_concatenate(3, ECL_SYM("STRING",805), _ecl_static_145, v1namestring);
  return value0;
 }
}
/*	function definition for COMPILE-FILE-OPERATION                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L136compile_file_operation(cl_object v1component, cl_object v2force)
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
   T0 = ecl_function_dispatch(cl_env_copy,VV[487])(1, v1component) /*  COMPONENT-LOAD-ONLY */;
   if (!(T0==ECL_NIL)) { goto L3; }
   {
    cl_object v5;
    v5 = si_make_seq_iterator(2, VV[320], ecl_make_fixnum(0));
L9:;
    if ((v5)!=ECL_NIL) { goto L11; }
    value0 = ECL_NIL;
    goto L7;
L11:;
    {
     cl_object v6;
     v6 = si_seq_iterator_ref(VV[320], v5);
     if (!((v2force)==(v6))) { goto L13; }
     value0 = v6;
     goto L7;
    }
L13:;
    v5 = si_seq_iterator_next(VV[320], v5);
    goto L9;
   }
L7:;
   if ((value0)!=ECL_NIL) { goto L6; }
   {
    cl_object v5;
    v5 = si_make_seq_iterator(2, VV[321], ecl_make_fixnum(0));
L22:;
    if ((v5)!=ECL_NIL) { goto L24; }
    goto L19;
L24:;
    {
     cl_object v6;
     v6 = si_seq_iterator_ref(VV[321], v5);
     if (!((v2force)==(v6))) { goto L26; }
     if (Null(v6)) { goto L19; }
     goto L20;
    }
L26:;
    v5 = si_seq_iterator_next(VV[321], v5);
    goto L22;
   }
L20:;
   v3 = L138needs_compilation(v1component, ECL_NIL);
   goto L1;
L19:;
   v3 = ECL_NIL;
   goto L1;
L6:;
   v3 = value0;
   goto L1;
L3:;
   v3 = ECL_NIL;
   goto L1;
L1:;
   v4 = L69component_full_pathname(2, v1component, VV[137]);
   if (Null(v3)) { goto L32; }
   if (Null(cl_probe_file(v4))) { goto L32; }
   L90tell_user(5, _ecl_static_146, v1component, VV[137], ECL_NIL, ECL_NIL);
   {
    cl_object v5output_file;
    v5output_file = L69component_full_pathname(2, v1component, VV[159]);
    T0 = cl_pathname_host(1, v5output_file);
    T1 = cl_pathname_directory(1, v5output_file);
    T2 = cl_make_pathname(4, ECL_SYM("HOST",1243), T0, ECL_SYM("DIRECTORY",1219), T1);
    cl_ensure_directories_exist(1, T2);
    value0 = ecl_symbol_value(VV[17]);
    if ((value0)!=ECL_NIL) { goto L41; }
    T0 = L118compile_function(v1component);
    T1 = ecl_function_dispatch(cl_env_copy,VV[489])(1, v1component) /*  COMPONENT-COMPILER-OPTIONS */;
    cl_apply(5, T0, v4, VV[322], v5output_file, T1);
    goto L37;
L41:;
    goto L37;
   }
L37:;
   L91tell_user_done(3, v1component, ECL_NIL, ECL_NIL);
   value0 = v3;
   cl_env_copy->nvalues = 1;
   return value0;
L32:;
   if (Null(v3)) { goto L43; }
   L90tell_user(5, _ecl_static_147, v1component, VV[137], VV[323], VV[244]);
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L43:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for COMPILED-FILE-P                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L137compiled_file_p(cl_object v1file_name)
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
/*	function definition for NEEDS-COMPILATION                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L138needs_compilation(cl_object v1component, cl_object v2force)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   v3 = L69component_full_pathname(2, v1component, VV[137]);
   v4 = L69component_full_pathname(2, v1component, VV[159]);
   if (Null(cl_probe_file(v3))) { goto L4; }
   T0 = cl_probe_file(v4);
   value0 = ecl_make_bool(T0==ECL_NIL);
   if ((value0)!=ECL_NIL) { goto L7; }
   T0 = cl_file_write_date(v4);
   T1 = cl_file_write_date(v3);
   value0 = ecl_make_bool(ecl_number_compare(T0,T1)<0);
   if ((value0)!=ECL_NIL) { goto L7; }
   T0 = L137compiled_file_p(v4);
   value0 = Null(T0)?ECL_T:ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L7:;
   cl_env_copy->nvalues = 1;
   return value0;
L4:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for NEEDS-LOADING                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L139needs_loading(cl_narg narg, cl_object v1component, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v2check_source;
  cl_object v3check_binary;
  va_list args; va_start(args,v1component);
  {
   int i = 1;
   if (i >= narg) {
    v2check_source = ECL_T;
   } else {
    i++;
    v2check_source = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v3check_binary = ECL_T;
   } else {
    i++;
    v3check_binary = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v4;
   cl_object v5;
   cl_object v6;
   v4 = L54component_load_time(v1component);
   v5 = L69component_full_pathname(2, v1component, VV[137]);
   v6 = L69component_full_pathname(2, v1component, VV[159]);
   value0 = ecl_function_dispatch(cl_env_copy,VV[490])(1, v1component) /*  COMPONENT-LOAD-ALWAYS */;
   if ((value0)!=ECL_NIL) { goto L7; }
   value0 = ecl_make_bool(v4==ECL_NIL);
   if ((value0)!=ECL_NIL) { goto L7; }
   if (Null(v3check_binary)) { goto L11; }
   if (Null(cl_probe_file(v6))) { goto L11; }
   T0 = cl_file_write_date(v6);
   value0 = ecl_make_bool(ecl_number_compare(v4,T0)<0);
   goto L10;
L11:;
   value0 = ECL_NIL;
L10:;
   if ((value0)!=ECL_NIL) { goto L7; }
   if (Null(v2check_source)) { goto L14; }
   if (Null(cl_probe_file(v5))) { goto L14; }
   T0 = cl_file_write_date(v5);
   value0 = ecl_make_bool(ecl_number_compare(v4,T0)<0);
   cl_env_copy->nvalues = 1;
   return value0;
L14:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L7:;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for LOAD-FILE-OPERATION                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L140load_file_operation(cl_object v1component, cl_object v2force)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3binary_pname;
   cl_object v4source_pname;
   cl_object v5binary_exists;
   cl_object v6source_exists;
   cl_object v7source_needs_loading;
   cl_object v8binary_needs_loading;
   cl_object v9needs_compilation;
   cl_object v10check_for_new_source;
   cl_object v11load_binary;
   cl_object v12load_source;
   cl_object v13compile_and_load;
   v3binary_pname = L69component_full_pathname(2, v1component, VV[159]);
   v4source_pname = L69component_full_pathname(2, v1component, VV[137]);
   v5binary_exists = cl_probe_file(v3binary_pname);
   v6source_exists = cl_probe_file(v4source_pname);
   v7source_needs_loading = L139needs_loading(3, v1component, ECL_T, ECL_NIL);
   v8binary_needs_loading = L139needs_loading(3, v1component, ECL_NIL, ECL_T);
   if (Null(ecl_function_dispatch(cl_env_copy,VV[487])(1, v1component) /*  COMPONENT-LOAD-ONLY */)) { goto L8; }
   v9needs_compilation = v7source_needs_loading;
   goto L7;
L8:;
   v9needs_compilation = L138needs_compilation(v1component, v2force);
L7:;
   {
    cl_object v14;
    v14 = si_make_seq_iterator(2, VV[329], ecl_make_fixnum(0));
L12:;
    if ((v14)!=ECL_NIL) { goto L14; }
    v10check_for_new_source = ECL_NIL;
    goto L10;
L14:;
    {
     cl_object v15;
     v15 = si_seq_iterator_ref(VV[329], v14);
     if (!((v2force)==(v15))) { goto L16; }
     v10check_for_new_source = v15;
     goto L10;
    }
L16:;
    v14 = si_seq_iterator_next(VV[329], v14);
    goto L12;
   }
L10:;
   {
    cl_object v14;
    v14 = si_make_seq_iterator(2, VV[320], ecl_make_fixnum(0));
L26:;
    if ((v14)!=ECL_NIL) { goto L28; }
    value0 = ECL_NIL;
    goto L24;
L28:;
    {
     cl_object v15;
     v15 = si_seq_iterator_ref(VV[320], v14);
     if (!((v2force)==(v15))) { goto L30; }
     value0 = v15;
     goto L24;
    }
L30:;
    v14 = si_seq_iterator_next(VV[320], v14);
    goto L26;
   }
L24:;
   if ((value0)!=ECL_NIL) { goto L23; }
   v11load_binary = v8binary_needs_loading;
   goto L21;
L23:;
   v11load_binary = value0;
   goto L21;
L21:;
   value0 = ecl_symbol_value(VV[20]);
   if ((value0)!=ECL_NIL) { goto L37; }
   if (Null(v11load_binary)) { goto L41; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[487])(1, v1component) /*  COMPONENT-LOAD-ONLY */;
   goto L39;
L41:;
   value0 = ECL_NIL;
   goto L39;
L39:;
   if ((value0)!=ECL_NIL) { goto L37; }
   if (Null(v10check_for_new_source)) { goto L44; }
   v12load_source = v9needs_compilation;
   goto L35;
L44:;
   v12load_source = ECL_NIL;
   goto L35;
L37:;
   v12load_source = value0;
   goto L35;
L35:;
   if (Null(v9needs_compilation)) { goto L48; }
   if ((v11load_binary)!=ECL_NIL) { goto L51; }
   if (Null(v10check_for_new_source)) { goto L48; }
   goto L50;
L51:;
L50:;
   v13compile_and_load = L143compile_and_load_source_if_no_binary(v1component);
   goto L46;
L48:;
   v13compile_and_load = ECL_NIL;
   goto L46;
L46:;
   if (Null(ecl_symbol_value(VV[23]))) { goto L53; }
   {
    cl_object v14;
    v14 = si_make_seq_iterator(2, VV[330], ecl_make_fixnum(0));
L57:;
    if ((v14)!=ECL_NIL) { goto L59; }
    goto L54;
L59:;
    {
     cl_object v15;
     v15 = si_seq_iterator_ref(VV[330], v14);
     if (!((v2force)==(v15))) { goto L61; }
     if ((v15)!=ECL_NIL) { goto L53; }
     goto L54;
    }
L61:;
    v14 = si_seq_iterator_next(VV[330], v14);
    goto L57;
   }
L54:;
   if (Null(v12load_source)) { goto L66; }
   v12load_source = v7source_needs_loading;
L66:;
   if (Null(v11load_binary)) { goto L53; }
   v11load_binary = v8binary_needs_loading;
L53:;
   if ((v12load_source)!=ECL_NIL) { goto L73; }
   if ((v11load_binary)!=ECL_NIL) { goto L73; }
   if (Null(v13compile_and_load)) { goto L71; }
   goto L72;
L73:;
L72:;
   if (Null(v13compile_and_load)) { goto L76; }
   L136compile_file_operation(v1component, ECL_T);
   L90tell_user(5, _ecl_static_150, v1component, VV[159], ECL_NIL, ECL_NIL);
   value0 = ecl_symbol_value(VV[17]);
   if ((value0)!=ECL_NIL) { goto L83; }
   T0 = L119load_function(v1component);
   ecl_function_dispatch(cl_env_copy,T0)(1, v3binary_pname);
   {
    cl_object v14;
    v14 = cl_file_write_date(v3binary_pname);
    if (Null(v1component)) { goto L81; }
    if (!(ECL_STRINGP(v1component))) { goto L90; }
    si_hash_set(v1component, ecl_symbol_value(VV[131]), v14);
    goto L89;
L90:;
    if (Null(cl_pathnamep(v1component))) { goto L92; }
    T1 = cl_pathnamep(v1component);
    if (ecl_unlikely(!((T1)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("PATHNAME",630),v1component);
    T0 = v1component;
    T1 = cl_namestring(T0);
    si_hash_set(T1, ecl_symbol_value(VV[131]), v14);
    goto L89;
L92:;
    if (Null(si_of_class_p(2, v1component, VV[89]))) { goto L96; }
    {
     cl_object v15;
     v15 = ecl_function_dispatch(cl_env_copy,VV[141])(1, v1component) /*  COMPONENT-TYPE */;
     if (!(ecl_eql(v15,VV[132]))) { goto L99; }
     {
      cl_object v16name;
      cl_object v17path;
      v16name = ecl_function_dispatch(cl_env_copy,VV[142])(1, v1component) /*  COMPONENT-NAME */;
      {
       cl_object v18;
       if (Null(v16name)) { goto L104; }
       v18 = L56compute_system_path(v16name, ECL_NIL);
       goto L103;
L104:;
       v18 = ECL_NIL;
L103:;
       value0 = ecl_make_bool(ECL_STRINGP(v18));
       if ((value0)!=ECL_NIL) { goto L109; }
       value0 = cl_pathnamep(v18);
       if ((value0)!=ECL_NIL) { goto L109; }
       T0 = ecl_make_bool(v18==ECL_NIL);
       goto L107;
L109:;
       T0 = value0;
       goto L107;
L107:;
       if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[133],v18);
       v17path = v18;
      }
      if (Null(v17path)) { goto L89; }
      T0 = cl_namestring(v17path);
      si_hash_set(T0, ecl_symbol_value(VV[131]), v14);
      goto L89;
     }
L99:;
     if (!(ecl_eql(v15,ECL_SYM("FILE",1237)))) { goto L118; }
     goto L115;
     goto L116;
L118:;
     goto L116;
L116:;
     if (!(ecl_eql(v15,VV[135]))) { goto L113; }
     goto L114;
L115:;
L114:;
     {
      cl_object v18path;
      v18path = L69component_full_pathname(2, v1component, VV[137]);
      if (Null(v18path)) { goto L89; }
      si_hash_set(v18path, ecl_symbol_value(VV[131]), v14);
      goto L89;
     }
L113:;
     si_ecase_error(v15, VV[138]);
     goto L89;
    }
L96:;
    si_etypecase_error(v1component, VV[139]);
L89:;
    goto L81;
   }
L83:;
   goto L81;
L81:;
   L91tell_user_done(3, v1component, ECL_NIL, ECL_NIL);
   value0 = ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
L76:;
   if (Null(v6source_exists)) { goto L123; }
   if (Null(v12load_source)) { goto L129; }
   if ((ecl_symbol_value(VV[20]))!=ECL_NIL) { goto L126; }
   if ((ecl_function_dispatch(cl_env_copy,VV[487])(1, v1component) /*  COMPONENT-LOAD-ONLY */)!=ECL_NIL) { goto L126; }
   if (Null(ecl_symbol_value(VV[21]))) { goto L126; }
   goto L127;
L129:;
   goto L127;
L127:;
   if (Null(v11load_binary)) { goto L123; }
   if ((v5binary_exists)!=ECL_NIL) { goto L123; }
   if (Null(L144load_source_if_no_binary(v1component))) { goto L123; }
   goto L124;
L126:;
L124:;
   L90tell_user(5, _ecl_static_151, v1component, VV[137], ECL_NIL, ECL_NIL);
   value0 = ecl_symbol_value(VV[17]);
   if ((value0)!=ECL_NIL) { goto L139; }
   T0 = L119load_function(v1component);
   ecl_function_dispatch(cl_env_copy,T0)(1, v4source_pname);
   {
    cl_object v14;
    v14 = cl_file_write_date(v4source_pname);
    if (Null(v1component)) { goto L137; }
    if (!(ECL_STRINGP(v1component))) { goto L146; }
    si_hash_set(v1component, ecl_symbol_value(VV[131]), v14);
    goto L145;
L146:;
    if (Null(cl_pathnamep(v1component))) { goto L148; }
    T1 = cl_pathnamep(v1component);
    if (ecl_unlikely(!((T1)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("PATHNAME",630),v1component);
    T0 = v1component;
    T1 = cl_namestring(T0);
    si_hash_set(T1, ecl_symbol_value(VV[131]), v14);
    goto L145;
L148:;
    if (Null(si_of_class_p(2, v1component, VV[89]))) { goto L152; }
    {
     cl_object v15;
     v15 = ecl_function_dispatch(cl_env_copy,VV[141])(1, v1component) /*  COMPONENT-TYPE */;
     if (!(ecl_eql(v15,VV[132]))) { goto L155; }
     {
      cl_object v16name;
      cl_object v17path;
      v16name = ecl_function_dispatch(cl_env_copy,VV[142])(1, v1component) /*  COMPONENT-NAME */;
      {
       cl_object v18;
       if (Null(v16name)) { goto L160; }
       v18 = L56compute_system_path(v16name, ECL_NIL);
       goto L159;
L160:;
       v18 = ECL_NIL;
L159:;
       value0 = ecl_make_bool(ECL_STRINGP(v18));
       if ((value0)!=ECL_NIL) { goto L165; }
       value0 = cl_pathnamep(v18);
       if ((value0)!=ECL_NIL) { goto L165; }
       T0 = ecl_make_bool(v18==ECL_NIL);
       goto L163;
L165:;
       T0 = value0;
       goto L163;
L163:;
       if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[133],v18);
       v17path = v18;
      }
      if (Null(v17path)) { goto L145; }
      T0 = cl_namestring(v17path);
      si_hash_set(T0, ecl_symbol_value(VV[131]), v14);
      goto L145;
     }
L155:;
     if (!(ecl_eql(v15,ECL_SYM("FILE",1237)))) { goto L174; }
     goto L171;
     goto L172;
L174:;
     goto L172;
L172:;
     if (!(ecl_eql(v15,VV[135]))) { goto L169; }
     goto L170;
L171:;
L170:;
     {
      cl_object v18path;
      v18path = L69component_full_pathname(2, v1component, VV[137]);
      if (Null(v18path)) { goto L145; }
      si_hash_set(v18path, ecl_symbol_value(VV[131]), v14);
      goto L145;
     }
L169:;
     si_ecase_error(v15, VV[138]);
     goto L145;
    }
L152:;
    si_etypecase_error(v1component, VV[139]);
L145:;
    goto L137;
   }
L139:;
   goto L137;
L137:;
   L91tell_user_done(3, v1component, ECL_NIL, ECL_NIL);
   value0 = ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
L123:;
   if (Null(v5binary_exists)) { goto L179; }
   if (Null(v11load_binary)) { goto L179; }
   L90tell_user(5, _ecl_static_150, v1component, VV[159], ECL_NIL, ECL_NIL);
   value0 = ecl_symbol_value(VV[17]);
   if ((value0)!=ECL_NIL) { goto L186; }
   T0 = L119load_function(v1component);
   ecl_function_dispatch(cl_env_copy,T0)(1, v3binary_pname);
   {
    cl_object v14;
    v14 = cl_file_write_date(v3binary_pname);
    if (Null(v1component)) { goto L184; }
    if (!(ECL_STRINGP(v1component))) { goto L193; }
    si_hash_set(v1component, ecl_symbol_value(VV[131]), v14);
    goto L192;
L193:;
    if (Null(cl_pathnamep(v1component))) { goto L195; }
    T1 = cl_pathnamep(v1component);
    if (ecl_unlikely(!((T1)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("PATHNAME",630),v1component);
    T0 = v1component;
    T1 = cl_namestring(T0);
    si_hash_set(T1, ecl_symbol_value(VV[131]), v14);
    goto L192;
L195:;
    if (Null(si_of_class_p(2, v1component, VV[89]))) { goto L199; }
    {
     cl_object v15;
     v15 = ecl_function_dispatch(cl_env_copy,VV[141])(1, v1component) /*  COMPONENT-TYPE */;
     if (!(ecl_eql(v15,VV[132]))) { goto L202; }
     {
      cl_object v16name;
      cl_object v17path;
      v16name = ecl_function_dispatch(cl_env_copy,VV[142])(1, v1component) /*  COMPONENT-NAME */;
      {
       cl_object v18;
       if (Null(v16name)) { goto L207; }
       v18 = L56compute_system_path(v16name, ECL_NIL);
       goto L206;
L207:;
       v18 = ECL_NIL;
L206:;
       value0 = ecl_make_bool(ECL_STRINGP(v18));
       if ((value0)!=ECL_NIL) { goto L212; }
       value0 = cl_pathnamep(v18);
       if ((value0)!=ECL_NIL) { goto L212; }
       T0 = ecl_make_bool(v18==ECL_NIL);
       goto L210;
L212:;
       T0 = value0;
       goto L210;
L210:;
       if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[133],v18);
       v17path = v18;
      }
      if (Null(v17path)) { goto L192; }
      T0 = cl_namestring(v17path);
      si_hash_set(T0, ecl_symbol_value(VV[131]), v14);
      goto L192;
     }
L202:;
     if (!(ecl_eql(v15,ECL_SYM("FILE",1237)))) { goto L221; }
     goto L218;
     goto L219;
L221:;
     goto L219;
L219:;
     if (!(ecl_eql(v15,VV[135]))) { goto L216; }
     goto L217;
L218:;
L217:;
     {
      cl_object v18path;
      v18path = L69component_full_pathname(2, v1component, VV[137]);
      if (Null(v18path)) { goto L192; }
      si_hash_set(v18path, ecl_symbol_value(VV[131]), v14);
      goto L192;
     }
L216:;
     si_ecase_error(v15, VV[138]);
     goto L192;
    }
L199:;
    si_etypecase_error(v1component, VV[139]);
L192:;
    goto L184;
   }
L186:;
   goto L184;
L184:;
   L91tell_user_done(3, v1component, ECL_NIL, ECL_NIL);
   value0 = ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
L179:;
   if ((v5binary_exists)!=ECL_NIL) { goto L226; }
   if ((v6source_exists)!=ECL_NIL) { goto L226; }
   L93tell_user_no_files(2, v1component, VV[244]);
   if (Null(ecl_symbol_value(VV[24]))) { goto L230; }
   value0 = ecl_symbol_value(VV[18]);
   if ((value0)!=ECL_NIL) { goto L234; }
   T0 = ecl_symbol_value(VV[20]);
   goto L232;
L234:;
   T0 = value0;
   goto L232;
L232:;
   cl_cerror(5, _ecl_static_152, _ecl_static_153, v4source_pname, T0, v3binary_pname);
L230:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L226:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L71:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for DELETE-BINARIES-OPERATION             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L141delete_binaries_operation(cl_object v1component, cl_object v2force)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((v2force)==(VV[238])) { goto L3; }
  if ((v2force)==(ECL_T)) { goto L3; }
  {
   cl_object v3;
   v3 = si_make_seq_iterator(2, VV[329], ecl_make_fixnum(0));
L8:;
   if ((v3)!=ECL_NIL) { goto L10; }
   goto L1;
L10:;
   {
    cl_object v4;
    v4 = si_seq_iterator_ref(VV[329], v3);
    if (!((v2force)==(v4))) { goto L12; }
    if (Null(v4)) { goto L1; }
    goto L6;
   }
L12:;
   v3 = si_seq_iterator_next(VV[329], v3);
   goto L8;
  }
L6:;
  if (Null(L138needs_compilation(v1component, ECL_NIL))) { goto L1; }
  goto L2;
L3:;
L2:;
  {
   cl_object v3binary_pname;
   v3binary_pname = L69component_full_pathname(2, v1component, VV[159]);
   if (Null(cl_probe_file(v3binary_pname))) { goto L18; }
   L90tell_user(5, _ecl_static_154, v1component, VV[159], ECL_NIL, ECL_NIL);
   value0 = ecl_symbol_value(VV[17]);
   if ((value0)!=ECL_NIL) { goto L23; }
   cl_delete_file(v3binary_pname);
   goto L21;
L23:;
   goto L21;
L21:;
   value0 = L91tell_user_done(3, v1component, ECL_NIL, ECL_NIL);
   return value0;
L18:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for BINARY-EXISTS                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L142binary_exists(cl_object v1component)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = L69component_full_pathname(2, v1component, VV[159]);
  value0 = cl_probe_file(T0);
  return value0;
 }
}
/*	function definition for COMPILE-AND-LOAD-SOURCE-IF-NO-BINARY  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L143compile_and_load_source_if_no_binary(cl_object v1component)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((ecl_symbol_value(VV[20]))!=ECL_NIL) { goto L1; }
  if (Null(ecl_symbol_value(VV[18]))) { goto L5; }
  if (Null(L142binary_exists(v1component))) { goto L1; }
  goto L2;
L5:;
  goto L2;
L2:;
  if (Null(ecl_function_dispatch(cl_env_copy,VV[487])(1, v1component) /*  COMPONENT-LOAD-ONLY */)) { goto L7; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L7:;
  if (!((ecl_symbol_value(VV[21]))==(VV[22]))) { goto L9; }
  {
   cl_object v2prompt;
   cl_object v3compile_source;
   v2prompt = L88prompt_string(v1component);
   T0 = L69component_full_pathname(2, v1component, VV[159]);
   T1 = L69component_full_pathname(2, v1component, VV[137]);
   v3compile_source = L98y_or_n_p_wait(7, CODE_CHAR(121), ecl_make_fixnum(30), _ecl_static_155, v2prompt, T0, v2prompt, T1);
   if ((L98y_or_n_p_wait(4, CODE_CHAR(121), ecl_make_fixnum(30), _ecl_static_156, v2prompt))!=ECL_NIL) { goto L13; }
   cl_set(VV[21],L98y_or_n_p_wait(4, CODE_CHAR(121), ecl_make_fixnum(30), _ecl_static_157, v2prompt));
L13:;
   value0 = v3compile_source;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L9:;
  {
   cl_object v4;
   v4 = ecl_symbol_value(VV[21]);
   if (Null(v4)) { goto L17; }
   value0 = v4;
   cl_env_copy->nvalues = 1;
   return value0;
L17:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for LOAD-SOURCE-IF-NO-BINARY              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L144load_source_if_no_binary(cl_object v1component)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((ecl_symbol_value(VV[20]))!=ECL_NIL) { goto L2; }
  if (Null(ecl_symbol_value(VV[18]))) { goto L8; }
  T0 = L142binary_exists(v1component);
  value0 = Null(T0)?ECL_T:ECL_NIL;
  goto L6;
L8:;
  value0 = ECL_NIL;
  goto L6;
L6:;
  if ((value0)!=ECL_NIL) { goto L5; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[487])(1, v1component) /*  COMPONENT-LOAD-ONLY */;
  if ((value0)!=ECL_NIL) { goto L5; }
  if (Null(ecl_symbol_value(VV[19]))) { goto L11; }
  {
   cl_object v2prompt;
   cl_object v3load_source;
   v2prompt = L88prompt_string(v1component);
   T0 = L69component_full_pathname(2, v1component, VV[159]);
   T1 = L69component_full_pathname(2, v1component, VV[137]);
   v3load_source = L98y_or_n_p_wait(7, CODE_CHAR(121), ecl_make_fixnum(30), _ecl_static_158, v2prompt, T0, v2prompt, T1);
   cl_set(VV[19],L98y_or_n_p_wait(4, CODE_CHAR(110), ecl_make_fixnum(30), _ecl_static_156, v2prompt));
   if ((ecl_symbol_value(VV[19]))!=ECL_NIL) { goto L17; }
   cl_set(VV[18],v3load_source);
L17:;
   value0 = v3load_source;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L11:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L5:;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for FILES-WHICH-NEED-COMPILATION          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L145files_which_need_compilation(cl_object v1system)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   cl_object v3;
   cl_object v4;
   T0 = L59find_system(2, v1system, VV[154]);
   T1 = L150file_components_in_component(2, T0, VV[340]);
   v2 = cl_remove(2, ECL_NIL, T1);
   v3 = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v2))) FEtype_error_list(v2);
   v4 = v2;
   {
    cl_object v5;
    cl_object v6;
    v5 = ecl_list1(ECL_NIL);
    v6 = v5;
L7:;
    if (!(ecl_endp(v4))) { goto L9; }
    goto L8;
L9:;
    v3 = _ecl_car(v4);
    {
     cl_object v7;
     v7 = _ecl_cdr(v4);
     if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
     v4 = v7;
    }
    if (ecl_unlikely(ECL_ATOM(v6))) FEtype_error_cons(v6);
    T0 = v6;
    T1 = L69component_full_pathname(2, v3, VV[137]);
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
/*	function definition for FILES-IN-SYSTEM-AND-DEPENDENTS        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L146files_in_system_and_dependents(cl_narg narg, cl_object v1name, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>4)) FEwrong_num_arguments_anonym();
 {
  cl_object v2force;
  cl_object v3type;
  cl_object v4version;
  va_list args; va_start(args,v1name);
  {
   int i = 1;
   if (i >= narg) {
    v2force = VV[238];
   } else {
    i++;
    v2force = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v3type = VV[137];
   } else {
    i++;
    v3type = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v4version = ECL_NIL;
   } else {
    i++;
    v4version = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v5system;
   v5system = L59find_system(2, v1name, VV[154]);
   value0 = L71translate_version(v4version);
   ecl_bds_bind(cl_env_copy,VV[34],value0);       /*  *VERSION-DIR*   */
   {
    const int v7 = cl_env_copy->nvalues;
    cl_object v8;
    v8 = (v7<=1)? ECL_NIL : cl_env_copy->values[1];
    ecl_bds_bind(cl_env_copy,VV[35],v8);          /*  *VERSION-REPLACE* */
   }
   ecl_bds_bind(cl_env_copy,VV[36],v4version);    /*  *VERSION*       */
   {
    cl_object v7result;
    v7result = L148file_pathnames_in_component(3, v5system, v3type, v2force);
    {
     cl_object v8;
     T0 = ecl_function_dispatch(cl_env_copy,VV[474])(1, v5system) /*  COMPONENT-DEPENDS-ON */;
     v8 = cl_reverse(T0);
     goto L11;
L10:;
     {
      cl_object v9dependent;
      v9dependent = ecl_car(v8);
      T0 = L146files_in_system_and_dependents(4, v9dependent, v2force, v3type, v4version);
      v7result = ecl_append(T0,v7result);
     }
     v8 = ecl_cdr(v8);
L11:;
     if (Null(v8)) { goto L19; }
     goto L10;
L19:;
    }
    value0 = v7result;
    cl_env_copy->nvalues = 1;
    ecl_bds_unwind1(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    return value0;
   }
  }
 }
}
/*	function definition for FILES-IN-SYSTEM                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L147files_in_system(cl_narg narg, cl_object v1name, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>4)) FEwrong_num_arguments_anonym();
 {
  cl_object v2force;
  cl_object v3type;
  cl_object v4version;
  va_list args; va_start(args,v1name);
  {
   int i = 1;
   if (i >= narg) {
    v2force = VV[238];
   } else {
    i++;
    v2force = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v3type = VV[137];
   } else {
    i++;
    v3type = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v4version = ECL_NIL;
   } else {
    i++;
    v4version = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v5system;
   if (Null(ecl_function_dispatch(cl_env_copy,VV[92])(1, v1name) /*  COMPONENT-P */)) { goto L5; }
   {
    cl_object v6;
    v6 = ecl_function_dispatch(cl_env_copy,VV[141])(1, v1name) /*  COMPONENT-TYPE */;
    if (!(ecl_eql(v6,VV[132]))) { goto L12; }
    goto L9;
    goto L10;
L12:;
    goto L10;
L10:;
    if (!(ecl_eql(v6,VV[122]))) { goto L16; }
    goto L9;
    goto L14;
L16:;
    goto L14;
L14:;
    if (!(ecl_eql(v6,VV[188]))) { goto L5; }
    goto L6;
L9:;
   }
L6:;
   v5system = v1name;
   goto L4;
L5:;
   v5system = L59find_system(2, v1name, VV[154]);
L4:;
   value0 = L71translate_version(v4version);
   ecl_bds_bind(cl_env_copy,VV[34],value0);       /*  *VERSION-DIR*   */
   {
    const int v7 = cl_env_copy->nvalues;
    cl_object v8;
    v8 = (v7<=1)? ECL_NIL : cl_env_copy->values[1];
    ecl_bds_bind(cl_env_copy,VV[35],v8);          /*  *VERSION-REPLACE* */
   }
   ecl_bds_bind(cl_env_copy,VV[36],v4version);    /*  *VERSION*       */
   value0 = L148file_pathnames_in_component(3, v5system, v3type, v2force);
   ecl_bds_unwind1(cl_env_copy);
   ecl_bds_unwind1(cl_env_copy);
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
 }
}
/*	function definition for FILE-PATHNAMES-IN-COMPONENT           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L148file_pathnames_in_component(cl_narg narg, cl_object v1component, cl_object v2type, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v3force;
  va_list args; va_start(args,v2type);
  {
   int i = 2;
   if (i >= narg) {
    v3force = VV[238];
   } else {
    i++;
    v3force = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v4;
   cl_object v5;
   cl_object v6;
   v4 = L150file_components_in_component(2, v1component, v3force);
   v5 = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
   v6 = v4;
   {
    cl_object v7;
    cl_object v8;
    v7 = ecl_list1(ECL_NIL);
    v8 = v7;
L8:;
    if (!(ecl_endp(v6))) { goto L10; }
    goto L9;
L10:;
    v5 = _ecl_car(v6);
    {
     cl_object v9;
     v9 = _ecl_cdr(v6);
     if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
     v6 = v9;
    }
    if (ecl_unlikely(ECL_ATOM(v8))) FEtype_error_cons(v8);
    T0 = v8;
    T1 = L69component_full_pathname(2, v5, v2type);
    v8 = ecl_list1(T1);
    (ECL_CONS_CDR(T0)=v8,T0);
    goto L8;
L9:;
    value0 = ecl_cdr(v7);
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for FILE-COMPONENTS-IN-COMPONENT          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L150file_components_in_component(cl_narg narg, cl_object v1component, ...)
{
 cl_object T0, T1, T2;
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2force;
  va_list args; va_start(args,v1component);
  {
   int i = 1;
   if (i >= narg) {
    v2force = VV[238];
   } else {
    i++;
    v2force = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v3result;
   cl_object env1 = env0;
   v3result = ECL_NIL;
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(ECL_NIL,env1);              /*  CHANGED         */
   {
    cl_object v4;
    v4 = ecl_function_dispatch(cl_env_copy,VV[141])(1, v1component) /*  COMPONENT-TYPE */;
    if (!(ecl_eql(v4,ECL_SYM("FILE",1237)))) { goto L10; }
    goto L7;
    goto L8;
L10:;
    goto L8;
L8:;
    if (!(ecl_eql(v4,VV[135]))) { goto L5; }
    goto L6;
L7:;
L6:;
    {
     cl_object v5;
     v5 = si_make_seq_iterator(2, VV[347], ecl_make_fixnum(0));
L19:;
     if ((v5)!=ECL_NIL) { goto L21; }
     value0 = ECL_NIL;
     goto L17;
L21:;
     {
      cl_object v6;
      v6 = si_seq_iterator_ref(VV[347], v5);
      if (!((v2force)==(v6))) { goto L23; }
      value0 = v6;
      goto L17;
     }
L23:;
     v5 = si_seq_iterator_next(VV[347], v5);
     goto L19;
    }
L17:;
    if ((value0)!=ECL_NIL) { goto L16; }
    if ((L6non_empty_listp(v2force))!=ECL_NIL) { goto L29; }
    ECL_CONS_CAR(CLV0) = L138needs_compilation(v1component, ECL_NIL);
    goto L14;
L29:;
    ECL_CONS_CAR(CLV0) = ECL_NIL;
    goto L14;
L16:;
    ECL_CONS_CAR(CLV0) = value0;
    goto L14;
L14:;
    if (Null(ECL_CONS_CAR(CLV0))) { goto L3; }
    v3result = ecl_list1(v1component);
    goto L3;
L5:;
    if (!(ecl_eql(v4,VV[199]))) { goto L36; }
    goto L33;
    goto L34;
L36:;
    goto L34;
L34:;
    if (!(ecl_eql(v4,VV[122]))) { goto L40; }
    goto L33;
    goto L38;
L40:;
    goto L38;
L38:;
    if (!(ecl_eql(v4,VV[188]))) { goto L44; }
    goto L33;
    goto L42;
L44:;
    goto L42;
L42:;
    if (!(ecl_eql(v4,VV[132]))) { goto L3; }
    goto L32;
L33:;
L32:;
    {
     cl_object v5;
     v5 = ecl_function_dispatch(cl_env_copy,VV[475])(1, v1component) /*  COMPONENT-COMPONENTS */;
     goto L50;
L49:;
     {
      cl_object v6module;
      v6module = ecl_car(v5);
      {
       cl_object v8;                              /*  R               */
       cl_object v9;                              /*  C               */
       {cl_object v10;
        v10 = ECL_NIL;
        v10 = ecl_make_cclosure_va((cl_objectfn)LC149__g861,env1,Cblock);
        T1 = v10;
       }
       T2 = ecl_function_dispatch(cl_env_copy,VV[474])(1, v6module) /*  COMPONENT-DEPENDS-ON */;
       if (Null(cl_some(2, T1, T2))) { goto L57; }
       if ((L6non_empty_listp(v2force))!=ECL_NIL) { goto L61; }
       if (!((v2force)==(VV[239]))) { goto L57; }
       goto L58;
L61:;
L58:;
       T0 = VV[238];
       goto L56;
L57:;
       if (Null(L6non_empty_listp(v2force))) { goto L63; }
       {
        cl_object v10;
        v10 = ecl_function_dispatch(cl_env_copy,VV[142])(1, v6module) /*  COMPONENT-NAME */;
        {
         cl_object v11;
         v11 = v2force;
         goto L70;
L69:;
         {
          cl_object v12;
          cl_object v13;
          if (ecl_unlikely(ECL_ATOM(v11))) FEtype_error_cons(v11);
          v12 = v11;
          v13 = ECL_CONS_CAR(v12);
          T1 = cl_string(v13);
          if (Null(cl_string_equal(2, v10, T1))) { goto L72; }
          if (Null(v12)) { goto L63; }
          goto L64;
         }
L72:;
         v11 = ECL_CONS_CDR(v11);
L70:;
         if (v11==ECL_NIL) { goto L79; }
         goto L69;
L79:;
         goto L63;
        }
       }
L64:;
       T0 = VV[238];
       goto L56;
L63:;
       T0 = v2force;
L56:;
       value0 = L150file_components_in_component(2, v6module, T0);
       v8 = value0;
       {
        const int v10 = cl_env_copy->nvalues;
        cl_object v11;
        v11 = (v10<=1)? ECL_NIL : cl_env_copy->values[1];
        v9 = v11;
       }
       if (Null(v9)) { goto L54; }
       ECL_CONS_CAR(CLV0) = CONS(v6module,ECL_CONS_CAR(CLV0));
       v3result = ecl_append(v3result,v8);
      }
L54:;
     }
     v5 = ecl_cdr(v5);
L50:;
     if (Null(v5)) { goto L87; }
     goto L49;
L87:;
    }
   }
L3:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = ECL_CONS_CAR(CLV0);
   cl_env_copy->values[0] = v3result;
   return cl_env_copy->values[0];
  }
 }
}
/*	closure G861                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC149__g861(cl_narg narg, cl_object v1dependent, ...)
{
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  CHANGED         */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = ecl_memql(v1dependent,ECL_CONS_CAR(CLV0));
  cl_env_copy->nvalues = 1;
  return value0;
 }
 }
}
/*	function definition for SYSTEM-SOURCE-SIZE                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L151system_source_size(cl_narg narg, cl_object v1system_name, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2force;
  va_list args; va_start(args,v1system_name);
  {
   int i = 1;
   if (i >= narg) {
    v2force = VV[238];
   } else {
    i++;
    v2force = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v3file_list;
   cl_object v4total_size;
   v3file_list = L147files_in_system(3, v1system_name, v2force, VV[137]);
   v4total_size = L152file_list_size(v3file_list);
   {
    cl_fixnum v5;
    v5 = ecl_length(v3file_list);
    T0 = ecl_round2(v4total_size,ecl_make_fixnum(1024));
    cl_format(7, ECL_T, _ecl_static_160, v1system_name, v2force, ecl_make_fixnum(v5), v4total_size, T0);
   }
   value0 = v4total_size;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for FILE-LIST-SIZE                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L152file_list_size(cl_object volatile v1file_list)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   volatile cl_object v2total_size;
   v2total_size = ecl_make_fixnum(0);
   {
    volatile cl_object v3;
    v3 = v1file_list;
    goto L6;
L5:;
    {
     volatile cl_object v4file;
     v4file = ecl_car(v3);
     {
      volatile cl_object v5stream;
      v5stream = cl_open(1, v4file);
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
         cl_object v8;
         v8 = _ecl_inner_frame;
         {
          cl_object v9;
          v9 = cl_file_length(v5stream);
          v2total_size = ecl_plus(v2total_size,v9);
          cl_env_copy->values[0] = v2total_size;
          cl_env_copy->nvalues = 1;
         }
         ecl_stack_frame_push_values(v8);
         if (Null(v5stream)) { goto L19; }
         cl_close(1, v5stream);
L19:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v8);
        }
        ecl_stack_frame_close(_ecl_inner_frame);
       }
       }
       ecl_frs_pop(cl_env_copy);
       v7=ecl_stack_push_values(cl_env_copy);
       if (Null(v5stream)) { goto L21; }
       cl_close(3, v5stream, ECL_SYM("ABORT",1195), ECL_T);
L21:;
       ecl_stack_pop_values(cl_env_copy,v7);
       if (unwinding) ecl_unwind(cl_env_copy,next_fr);
       ECL_STACK_SET_INDEX(cl_env_copy,v6);
      }
     }
    }
    v3 = ecl_cdr(v3);
L6:;
    if (Null(v3)) { goto L25; }
    goto L5;
L25:;
   }
   value0 = v2total_size;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}

#include "ext/defsystem.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclv423LXchcSyq9_z42UOE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("EXT:DEFSYSTEM;DEFSYSTEM.LISP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclv423LXchcSyq9_z42UOE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 ecl_function_dispatch(cl_env_copy,VV[353])(10, _ecl_static_0, VVtemp[0], ECL_NIL, VVtemp[1], ECL_NIL, ECL_NIL, ECL_NIL, ECL_NIL, ECL_NIL, ECL_NIL) /*  DODEFPACKAGE */;
 si_select_package(_ecl_static_0);
 cl_provide(VV[0]);
 cl_set(ECL_SYM("*FEATURES*",34),cl_adjoin(2, VV[1], ecl_symbol_value(ECL_SYM("*FEATURES*",34))));
 si_Xmake_special(VV[2]);
 if (ecl_boundp(cl_env_copy,VV[2])) { goto L8; }
 cl_set(VV[2],ECL_NIL);
L8:;
 si_Xmake_special(VV[3]);
 if (ecl_boundp(cl_env_copy,VV[3])) { goto L15; }
 cl_set(VV[3],ECL_NIL);
L15:;
 si_Xmake_special(VV[4]);
 if (ecl_boundp(cl_env_copy,VV[4])) { goto L22; }
 cl_set(VV[4],ECL_NIL);
L22:;
 cl_set(VV[3],VVtemp[2]);
 cl_export(1, VVtemp[2]);
 cl_set(VV[2],ECL_NIL);
 cl_export(1, ECL_NIL);
 cl_set(VV[4],VVtemp[3]);
 cl_export(1, VVtemp[3]);
 si_Xmake_special(VV[5]);
 cl_set(VV[5],_ecl_static_1);
 si_Xmake_special(VV[6]);
 if (ecl_boundp(cl_env_copy,VV[6])) { goto L41; }
 cl_set(VV[6],ECL_NIL);
L41:;
 si_Xmake_special(VV[7]);
 if (ecl_boundp(cl_env_copy,VV[7])) { goto L48; }
 cl_set(VV[7],ECL_T);
L48:;
 ecl_cmp_defun(VV[354]);                          /*  HOME-SUBDIRECTORY */
 si_Xmake_special(VV[9]);
 if (ecl_boundp(cl_env_copy,VV[9])) { goto L59; }
 cl_set(VV[9],VVtemp[4]);
L59:;
 ecl_cmp_defun(VV[355]);                          /*  ADD-REGISTRY-LOCATION */
 ecl_cmp_defun(VV[356]);                          /*  REGISTRY-PATHNAME */
 ecl_cmp_defun(VV[357]);                          /*  PRINT-CENTRAL-REGISTRY-DIRECTORIES */
 ecl_cmp_defun(VV[358]);                          /*  LIST-CENTRAL-REGISTRY-DIRECTORIES */
 si_Xmake_special(VV[14]);
 if (ecl_boundp(cl_env_copy,VV[14])) { goto L82; }
 cl_set(VV[14],_ecl_static_3);
L82:;
 si_Xmake_special(VV[15]);
 if (ecl_boundp(cl_env_copy,VV[15])) { goto L89; }
 cl_set(VV[15],ECL_NIL);
L89:;
 si_Xmake_special(VV[16]);
 if (ecl_boundp(cl_env_copy,VV[16])) { goto L96; }
 cl_set(VV[16],ECL_NIL);
L96:;
 si_Xmake_special(VV[17]);
 if (ecl_boundp(cl_env_copy,VV[17])) { goto L103; }
 cl_set(VV[17],ECL_NIL);
L103:;
 si_Xmake_special(VV[18]);
 if (ecl_boundp(cl_env_copy,VV[18])) { goto L110; }
 cl_set(VV[18],ECL_NIL);
L110:;
 si_Xmake_special(VV[19]);
 if (ecl_boundp(cl_env_copy,VV[19])) { goto L117; }
 cl_set(VV[19],ECL_T);
L117:;
 si_Xmake_special(VV[20]);
 if (ecl_boundp(cl_env_copy,VV[20])) { goto L124; }
 cl_set(VV[20],ECL_NIL);
L124:;
 si_Xmake_special(VV[21]);
 if (ecl_boundp(cl_env_copy,VV[21])) { goto L131; }
 cl_set(VV[21],VV[22]);
L131:;
 si_Xmake_special(VV[23]);
 if (ecl_boundp(cl_env_copy,VV[23])) { goto L138; }
 cl_set(VV[23],ECL_NIL);
L138:;
 si_Xmake_special(VV[24]);
 if (ecl_boundp(cl_env_copy,VV[24])) { goto L145; }
 cl_set(VV[24],ECL_T);
L145:;
 si_Xmake_special(VV[25]);
 if (ecl_boundp(cl_env_copy,VV[25])) { goto L152; }
 cl_set(VV[25],ECL_T);
L152:;
 si_Xmake_special(VV[26]);
 if (ecl_boundp(cl_env_copy,VV[26])) { goto L159; }
 cl_set(VV[26],_ecl_static_4);
L159:;
 si_Xmake_special(VV[27]);
 if (ecl_boundp(cl_env_copy,VV[27])) { goto L166; }
 cl_set(VV[27],ECL_T);
L166:;
 si_Xmake_special(VV[28]);
 if (ecl_boundp(cl_env_copy,VV[28])) { goto L173; }
 cl_set(VV[28],ECL_T);
L173:;
 {
  cl_object T0;
 {
  cl_object v1;
  v1 = ecl_symbol_value(ECL_SYM("*FEATURES*",34));
  goto L183;
L182:;
  {
   cl_object v2feature;
   v2feature = ecl_car(v1);
   if (!(ECL_SYMBOLP(v2feature))) { goto L187; }
   T0 = ecl_symbol_name(v2feature);
   if (!(ecl_equal(T0,_ecl_static_5))) { goto L187; }
   cl_set(ECL_SYM("*FEATURES*",34),cl_adjoin(2, VV[29], ecl_symbol_value(ECL_SYM("*FEATURES*",34))));
L187:;
  }
  v1 = ecl_cdr(v1);
L183:;
  if (Null(v1)) { goto L193; }
  goto L182;
L193:;
 }
 }
 {
  cl_object T0, T1, T2, T3;
 si_Xmake_special(VV[30]);
 if (ecl_boundp(cl_env_copy,VV[30])) { goto L196; }
 T0 = (cl_env_copy->function=(ECL_SYM("COMPILE-FILE-PATHNAME",235)->symbol.gfdef))->cfun.entry(1, _ecl_static_7) /*  COMPILE-FILE-PATHNAME */;
 T1 = cl_pathname_type(1, T0);
 T2 = CONS(_ecl_static_6,T1);
 T3 = cl_list(2, VVtemp[5], T2);
 cl_set(VV[30],ecl_car(T3));
L196:;
 }
 si_Xmake_special(VV[31]);
 if (ecl_boundp(cl_env_copy,VV[31])) { goto L203; }
 cl_set(VV[31],_ecl_static_8);
L203:;
 si_Xmake_special(VV[32]);
 if (ecl_boundp(cl_env_copy,VV[32])) { goto L210; }
 cl_set(VV[32],ECL_T);
L210:;
 ecl_cmp_defun(VV[359]);                          /*  NON-EMPTY-LISTP */
 si_Xmake_special(VV[34]);
 if (ecl_boundp(cl_env_copy,VV[34])) { goto L221; }
 cl_set(VV[34],ECL_NIL);
L221:;
 si_Xmake_special(VV[35]);
 if (ecl_boundp(cl_env_copy,VV[35])) { goto L228; }
 cl_set(VV[35],ECL_NIL);
L228:;
 si_Xmake_special(VV[36]);
 if (ecl_boundp(cl_env_copy,VV[36])) { goto L235; }
 cl_set(VV[36],ECL_NIL);
L235:;
 {
  cl_object T0;
 si_Xmake_special(VV[37]);
 if (ecl_boundp(cl_env_copy,VV[37])) { goto L242; }
 T0 = (ECL_SYM("EQUAL",335)->symbol.gfdef);
 cl_set(VV[37],cl_make_hash_table(2, ECL_SYM("TEST",1316), T0));
L242:;
 }
 ecl_cmp_defun(VV[360]);                          /*  COMPONENT-OPERATION */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC8__g21,ECL_NIL,Cblock,3);
  T0 = v1;
 }
 cl_set_dispatch_macro_character(3, CODE_CHAR(35), CODE_CHAR(64), T0);
 }
 si_Xmake_special(VV[40]);
 if (ecl_boundp(cl_env_copy,VV[40])) { goto L256; }
 cl_set(VV[40],_ecl_static_9);
L256:;
 ecl_cmp_defun(VV[361]);                          /*  OPERATING-SYSTEM-VERSION */
 ecl_cmp_defun(VV[362]);                          /*  COMPILER-VERSION */
 ecl_cmp_defun(VV[363]);                          /*  AFS-BINARY-DIRECTORY */
 ecl_cmp_defun(VV[364]);                          /*  AFS-SOURCE-DIRECTORY */
 ecl_cmp_defun(VV[365]);                          /*  NULL-STRING     */
 ecl_cmp_defun(VV[366]);                          /*  ENSURE-TRAILING-SLASH */
 ecl_cmp_defun(VV[367]);                          /*  AFS-COMPONENT   */
 {
  cl_object T0;
 si_Xmake_special(VV[48]);
 if (ecl_boundp(cl_env_copy,VV[48])) { goto L291; }
 T0 = (ECL_SYM("EQUAL",335)->symbol.gfdef);
 cl_set(VV[48],cl_make_hash_table(2, ECL_SYM("TEST",1316), T0));
L291:;
 }
 ecl_cmp_defun(VV[368]);                          /*  MACHINE-TYPE-TRANSLATION */
 L16machine_type_translation(2, _ecl_static_17, _ecl_static_18);
 L16machine_type_translation(2, _ecl_static_19, _ecl_static_20);
 L16machine_type_translation(2, _ecl_static_21, _ecl_static_22);
 L16machine_type_translation(2, _ecl_static_23, _ecl_static_20);
 L16machine_type_translation(2, _ecl_static_24, _ecl_static_25);
 L16machine_type_translation(2, _ecl_static_26, _ecl_static_27);
 L16machine_type_translation(2, _ecl_static_28, _ecl_static_29);
 L16machine_type_translation(2, _ecl_static_30, _ecl_static_31);
 L16machine_type_translation(2, _ecl_static_32, _ecl_static_31);
 L16machine_type_translation(2, _ecl_static_33, _ecl_static_31);
 L16machine_type_translation(2, _ecl_static_34, _ecl_static_31);
 L16machine_type_translation(2, _ecl_static_35, _ecl_static_31);
 L16machine_type_translation(2, _ecl_static_36, _ecl_static_31);
 L16machine_type_translation(2, _ecl_static_37, _ecl_static_31);
 L16machine_type_translation(2, _ecl_static_38, _ecl_static_31);
 L16machine_type_translation(2, _ecl_static_39, _ecl_static_31);
 L16machine_type_translation(2, _ecl_static_40, _ecl_static_31);
 L16machine_type_translation(2, _ecl_static_41, _ecl_static_41);
 L16machine_type_translation(2, _ecl_static_42, _ecl_static_41);
 L16machine_type_translation(2, _ecl_static_43, _ecl_static_41);
 L16machine_type_translation(2, _ecl_static_44, _ecl_static_41);
 {
  cl_object T0;
 si_Xmake_special(VV[50]);
 if (ecl_boundp(cl_env_copy,VV[50])) { goto L324; }
 T0 = (ECL_SYM("EQUAL",335)->symbol.gfdef);
 cl_set(VV[50],cl_make_hash_table(2, ECL_SYM("TEST",1316), T0));
L324:;
 }
 ecl_cmp_defun(VV[369]);                          /*  SOFTWARE-TYPE-TRANSLATION */
 L17software_type_translation(2, _ecl_static_45, _ecl_static_16);
 L17software_type_translation(2, _ecl_static_46, _ecl_static_16);
 L17software_type_translation(2, _ecl_static_47, _ecl_static_47);
 L17software_type_translation(2, _ecl_static_48, _ecl_static_16);
 L17software_type_translation(2, _ecl_static_49, _ecl_static_50);
 L17software_type_translation(2, _ecl_static_51, _ecl_static_52);
 L17software_type_translation(2, _ecl_static_53, _ecl_static_52);
 L17software_type_translation(2, _ecl_static_54, _ecl_static_52);
 L17software_type_translation(2, _ecl_static_55, _ecl_static_52);
 L17software_type_translation(2, _ecl_static_56, _ecl_static_52);
 L17software_type_translation(2, _ecl_static_57, _ecl_static_58);
 L17software_type_translation(2, _ecl_static_59, _ecl_static_58);
 L17software_type_translation(2, _ecl_static_60, _ecl_static_61);
 L17software_type_translation(2, _ecl_static_62, _ecl_static_61);
 L17software_type_translation(2, _ecl_static_63, _ecl_static_64);
 L17software_type_translation(2, _ecl_static_65, _ecl_static_64);
 L17software_type_translation(2, ECL_NIL, _ecl_static_13);
 {
  cl_object T0;
 si_Xmake_special(VV[52]);
 if (ecl_boundp(cl_env_copy,VV[52])) { goto L353; }
 T0 = (ECL_SYM("EQUAL",335)->symbol.gfdef);
 cl_set(VV[52],cl_make_hash_table(2, ECL_SYM("TEST",1316), T0));
L353:;
 }
 ecl_cmp_defun(VV[370]);                          /*  COMPILER-TYPE-TRANSLATION */
 L18compiler_type_translation(2, _ecl_static_66, _ecl_static_67);
 L18compiler_type_translation(2, _ecl_static_68, _ecl_static_67);
 L18compiler_type_translation(2, _ecl_static_69, _ecl_static_67);
 L18compiler_type_translation(2, _ecl_static_70, _ecl_static_71);
 L18compiler_type_translation(2, _ecl_static_72, _ecl_static_71);
 L18compiler_type_translation(2, _ecl_static_73, _ecl_static_74);
 L18compiler_type_translation(2, _ecl_static_75, _ecl_static_74);
 L18compiler_type_translation(2, _ecl_static_76, _ecl_static_74);
 ecl_cmp_defun(VV[371]);                          /*  CANONICALIZE-SYSTEM-NAME */
 {
  cl_object T0;
 si_Xmake_special(VV[55]);
 if (ecl_boundp(cl_env_copy,VV[55])) { goto L377; }
 T0 = (ECL_SYM("EQUAL",335)->symbol.gfdef);
 cl_set(VV[55],cl_make_hash_table(2, ECL_SYM("TEST",1316), T0));
L377:;
 }
 ecl_cmp_defun(VV[372]);                          /*  GET-SYSTEM      */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC21get_system,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(VV[56], T0);
 }
 ecl_cmp_defun(VV[373]);                          /*  UNDEFSYSTEM     */
 ecl_cmp_defun(VV[374]);                          /*  DEFINED-SYSTEMS */
 ecl_cmp_defun(VV[375]);                          /*  DEFINED-NAMES-AND-SYSTEMS */
 ecl_cmp_defun(VV[376]);                          /*  NEW-APPEND-DIRECTORIES */
 ecl_cmp_defun(VV[377]);                          /*  DIRECTORY-TO-LIST */
 si_Xmake_special(VV[63]);
 cl_set(VV[63],VVtemp[6]);
 ecl_cmp_defun(VV[378]);                          /*  TEST-NEW-APPEND-DIRECTORIES */
 ecl_cmp_defun(VV[379]);                          /*  APPEND-DIRECTORIES */
 ecl_cmp_defun(VV[380]);                          /*  PATHNAME-LOGICAL-P */
 ecl_cmp_defun(VV[381]);                          /*  NAMESTRING-PROBABLY-LOGICAL */
 ecl_cmp_defun(VV[382]);                          /*  APPEND-LOGICAL-PNAMES */
 ecl_cmp_defun(VV[383]);                          /*  NEW-FILE-TYPE   */
 si_Xmake_special(VV[71]);
 if (ecl_boundp(cl_env_copy,VV[71])) { goto L442; }
 cl_set(VV[71],ECL_NIL);
L442:;
 si_Xmake_special(VV[72]);
 if (ecl_boundp(cl_env_copy,VV[72])) { goto L449; }
 cl_set(VV[72],ECL_NIL);
L449:;
 si_define_structure(15, VV[73], VV[74], ECL_NIL, ECL_NIL, VVtemp[7], VVtemp[8], VV[75], ECL_NIL, ECL_NIL, ECL_NIL, VVtemp[9], ecl_make_fixnum(1), ECL_NIL, ECL_NIL, VV[76]);
 VV[85]= cl_find_class(1, VV[73]);
 ecl_cmp_defun(VV[384]);                          /*  MAKE-TOPOLOGICAL-SORT-NODE */
 si_Xmake_special(VV[87]);
 cl_set(VV[87],VVtemp[10]);
 si_Xmake_special(VV[88]);
 cl_set(VV[88],VVtemp[11]);
 si_define_structure(15, VV[89], _ecl_static_78, ECL_NIL, ECL_NIL, VVtemp[12], VVtemp[13], VV[90], VV[73], VV[91], ECL_NIL, VVtemp[14], ecl_make_fixnum(35), ECL_NIL, ECL_NIL, VV[92]);
 VV[117]= cl_find_class(1, VV[89]);
 ecl_cmp_defun(VV[386]);                          /*  MAKE-COMPONENT  */
 si_define_structure(15, VV[119], _ecl_static_79, ECL_NIL, ECL_NIL, VVtemp[15], VVtemp[16], VV[120], VV[89], ECL_NIL, ECL_NIL, VVtemp[17], ecl_make_fixnum(37), ECL_NIL, ECL_NIL, VV[121]);
 VV[123]= cl_find_class(1, VV[119]);
 ecl_cmp_defun(VV[422]);                          /*  MAKE-FOREIGN-SYSTEM */
 ecl_cmp_defun(VV[460]);                          /*  REGISTER-FOREIGN-SYSTEM */
 {
  cl_object T0, T1, T2, T3, T4, T5, T6;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC49__g142,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 T1 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T0, VVtemp[19]);
 T2 = cl_list(3, T1, VVtemp[20], VVtemp[21]);
 T3 = cl_constantly(ECL_NIL);
 T4 = cl_list(3, VV[128], ECL_NIL, T3);
 T5 = ecl_list1(T4);
 T6 = cl_list(2, ECL_SYM("DIRECT-DEFAULT-INITARGS",989), T5);
 clos_load_defclass(VV[127], VVtemp[18], T2, T6);
 }
 {
  cl_object T0, T1, T2;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC51__g144,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 T1 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T0, VVtemp[23]);
 T2 = ecl_list1(T1);
 clos_load_defclass(VV[129], VVtemp[22], T2, ECL_NIL);
 }
 {
  cl_object T0, T1, T2;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC53__g146,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 T1 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T0, VVtemp[25]);
 T2 = ecl_list1(T1);
 clos_load_defclass(VV[130], VVtemp[24], T2, ECL_NIL);
 }
 {
  cl_object T0;
 si_Xmake_special(VV[131]);
 if (ecl_boundp(cl_env_copy,VV[131])) { goto L508; }
 T0 = (ECL_SYM("EQUAL",335)->symbol.gfdef);
 cl_set(VV[131],cl_make_hash_table(2, ECL_SYM("TEST",1316), T0));
L508:;
 }
 ecl_cmp_defun(VV[465]);                          /*  COMPONENT-LOAD-TIME */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC55component_load_time,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_do_defsetf(VV[140], T0);
 }
 ecl_cmp_defun(VV[466]);                          /*  COMPUTE-SYSTEM-PATH */
 ecl_cmp_defun(VV[467]);                          /*  SYSTEM-DEFINITION-PATHNAME */
 si_Xmake_special(VV[152]);
 if (ecl_boundp(cl_env_copy,VV[152])) { goto L531; }
 cl_set(VV[152],ECL_T);
L531:;
 ecl_cmp_defun(VV[468]);                          /*  FIND-SYSTEM     */
 ecl_cmp_defun(VV[469]);                          /*  PRINT-COMPONENT */
 ecl_cmp_defun(VV[470]);                          /*  DESCRIBE-SYSTEM */
 ecl_cmp_defun(VV[476]);                          /*  CANONICALIZE-COMPONENT-NAME */
 ecl_cmp_defun(VV[477]);                          /*  COMPONENT-PATHNAME */
 ecl_cmp_defun(VV[478]);                          /*  COMPONENT-ERROR-PATHNAME */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC65component_pathname,ECL_NIL,Cblock,3);
  T0 = v1;
 }
 si_do_defsetf(VV[163], T0);
 }
 ecl_cmp_defun(VV[479]);                          /*  COMPONENT-ROOT-DIR */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC67component_root_dir,ECL_NIL,Cblock,3);
  T0 = v1;
 }
 si_do_defsetf(VV[170], T0);
 }
 {
  cl_object T0;
 si_Xmake_special(VV[173]);
 if (ecl_boundp(cl_env_copy,VV[173])) { goto L572; }
 T0 = (ECL_SYM("EQUAL",335)->symbol.gfdef);
 cl_set(VV[173],cl_make_hash_table(2, ECL_SYM("TEST",1316), T0));
L572:;
 }
 {
  cl_object T0;
 si_Xmake_special(VV[174]);
 if (ecl_boundp(cl_env_copy,VV[174])) { goto L580; }
 T0 = (ECL_SYM("EQUAL",335)->symbol.gfdef);
 cl_set(VV[174],cl_make_hash_table(2, ECL_SYM("TEST",1316), T0));
L580:;
 }
 si_Xmake_special(VV[175]);
 cl_set(VV[175],ECL_T);
 ecl_cmp_defun(VV[480]);                          /*  CLEAR-FULL-PATHNAME-TABLES */
 ecl_cmp_defun(VV[481]);                          /*  COMPONENT-FULL-PATHNAME */
 ecl_cmp_defun(VV[482]);                          /*  COMPONENT-FULL-PATHNAME-I */
 ecl_cmp_defun(VV[483]);                          /*  TRANSLATE-VERSION */
 ecl_cmp_defun(VV[484]);                          /*  COMPONENT-EXTENSION */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC73component_extension,ECL_NIL,Cblock,3);
  T0 = v1;
 }
 si_do_defsetf(VV[180], T0);
 }
 ecl_cmp_defun(VV[486]);                          /*  CREATE-COMPONENT */
 ecl_cmp_defun(VV[491]);                          /*  PREPROCESS-COMPONENT-DEFINITION */
 ecl_cmp_defmacro(VV[492]);                       /*  DEFSYSTEM       */
 ecl_cmp_defun(VV[493]);                          /*  CREATE-COMPONENT-PATHNAMES */
 ecl_cmp_defun(VV[497]);                          /*  GENERATE-COMPONENT-PATHNAME */
 ecl_cmp_defun(VV[498]);                          /*  EXPAND-COMPONENT-COMPONENTS */
 ecl_cmp_defun(VV[499]);                          /*  EXPAND-COMPONENT-DEFINITIONS */
 ecl_cmp_defun(VV[500]);                          /*  EXPAND-SERIAL-COMPONENT-CHAIN */
 si_Xmake_special(VV[207]);
 cl_set(VV[207],ECL_NIL);
 ecl_cmp_defun(VV[501]);                          /*  ABSOLUTE-FILE-NAMESTRING-P */
 ecl_cmp_defun(VV[502]);                          /*  EXPAND-COMPONENT-DEFINITION */
 ecl_cmp_defun(VV[503]);                          /*  LINK-COMPONENT-DEPENDS-ON */
 ecl_cmp_defun(VV[504]);                          /*  TOPOLOGICAL-SORT */
 ecl_cmp_defun(VV[506]);                          /*  SPLIT-STRING    */
 ecl_cmp_defun(VV[509]);                          /*  PROMPT-STRING   */
 ecl_cmp_defun(VV[511]);                          /*  FORMAT-JUSTIFIED-STRING */
 ecl_cmp_defun(VV[512]);                          /*  TELL-USER       */
 ecl_cmp_defun(VV[513]);                          /*  TELL-USER-DONE  */
 ecl_cmp_defmacro(VV[514]);                       /*  WITH-TELL-USER  */
 ecl_cmp_defun(VV[515]);                          /*  TELL-USER-NO-FILES */
 ecl_cmp_defun(VV[516]);                          /*  TELL-USER-REQUIRE-SYSTEM */
 ecl_cmp_defun(VV[517]);                          /*  TELL-USER-GENERIC */
 si_Xmake_special(VV[226]);
 cl_set(VV[226],ECL_T);
 si_Xmake_special(VV[227]);
 cl_set(VV[227],ECL_T);
 si_Xmake_special(VV[228]);
 cl_set(VV[228],_ecl_static_104);
 ecl_cmp_defun(VV[518]);                          /*  INTERNAL-REAL-TIME-IN-SECONDS */
 ecl_cmp_defun(VV[519]);                          /*  READ-CHAR-WAIT  */
 ecl_cmp_defun(VV[520]);                          /*  Y-OR-N-P-WAIT   */
 si_Xmake_special(VV[235]);
 if (ecl_boundp(cl_env_copy,VV[235])) { goto L733; }
 cl_set(VV[235],ECL_NIL);
L733:;
 cl_export(1, VVtemp[26]);
 ecl_cmp_defmacro(VV[521]);                       /*  WITH-SPECIAL-COMPONENT-VARS */
 ecl_cmp_defun(VV[522]);                          /*  OPERATE-ON-SYSTEM */
 ecl_cmp_defun(VV[534]);                          /*  COMPILE-SYSTEM  */
 ecl_cmp_defun(VV[535]);                          /*  LOAD-SYSTEM     */
 ecl_cmp_defun(VV[536]);                          /*  CLEAN-SYSTEM    */
 ecl_cmp_defun(VV[542]);                          /*  EDIT-SYSTEM     */
 ecl_cmp_defun(VV[543]);                          /*  HARDCOPY-SYSTEM */
 ecl_cmp_defun(VV[544]);                          /*  ENSURE-EXTERNAL-SYSTEM-DEF-LOADED */
 ecl_cmp_defun(VV[545]);                          /*  OPERATE-ON-COMPONENT */
 si_Xmake_special(VV[267]);
 if (ecl_boundp(cl_env_copy,VV[267])) { goto L775; }
 cl_set(VV[267],ECL_NIL);
L775:;
 si_Xmake_special(VV[268]);
 if (ecl_boundp(cl_env_copy,VV[268])) { goto L782; }
 cl_set(VV[268],ECL_T);
L782:;
 ecl_cmp_defun(VV[549]);                          /*  OPERATE-ON-SYSTEM-DEPENDENCIES */
 ecl_cmp_defun(VV[550]);                          /*  MODULE-DEPENDS-ON-CHANGED */
 ecl_cmp_defun(VV[551]);                          /*  OPERATE-ON-COMPONENTS */
 si_Xmake_special(VV[274]);
 if (ecl_boundp(cl_env_copy,VV[274])) { goto L801; }
 cl_set(VV[274],ECL_NIL);
L801:;
 ecl_cmp_defun(VV[554]);                          /*  NEW-REQUIRE     */
 {
  cl_object T0;
 if ((ecl_symbol_value(VV[274]))!=ECL_NIL) { goto L811; }
 cl_set(VV[274],cl_symbol_function(ECL_SYM("REQUIRE",718)));
 if ((ecl_symbol_value(VV[6]))!=ECL_NIL) { goto L811; }
 si_package_lock(_ecl_static_115, ECL_NIL);
 T0 = cl_symbol_function(VV[275]);
 si_fset(4, ECL_SYM("REQUIRE",718), T0, ECL_NIL, ECL_NIL);
 si_package_lock(_ecl_static_115, ECL_T);
L811:;
 }
 ecl_cmp_defun(VV[555]);                          /*  CMUCL-MK-DEFSYSTEM-MODULE-PROVIDER */
 cl_set(ECL_SYM("*MODULE-PROVIDER-FUNCTIONS*",42),cl_adjoin(2, VV[276], ecl_symbol_value(ECL_SYM("*MODULE-PROVIDER-FUNCTIONS*",42))));
 {
  cl_object T0;
 si_Xmake_special(VV[277]);
 if (ecl_boundp(cl_env_copy,VV[277])) { goto L825; }
 T0 = (ECL_SYM("EQUAL",335)->symbol.gfdef);
 cl_set(VV[277],cl_make_hash_table(2, ECL_SYM("TEST",1316), T0));
L825:;
 }
 ecl_cmp_defun(VV[556]);                          /*  FIND-LANGUAGE   */
 si_define_structure(15, VV[110], _ecl_static_116, ECL_NIL, ECL_NIL, VVtemp[27], VVtemp[28], VV[279], ECL_NIL, VV[280], ECL_NIL, VVtemp[29], ecl_make_fixnum(5), ECL_NIL, ECL_NIL, VV[281]);
 VV[282]= cl_find_class(1, VV[110]);
 ecl_cmp_defun(VV[557]);                          /*  MAKE-LANGUAGE   */
 ecl_cmp_defun(VV[563]);                          /*  PRINT-LANGUAGE  */
 ecl_cmp_defun(VV[567]);                          /*  COMPILE-FUNCTION */
 ecl_cmp_defun(VV[569]);                          /*  LOAD-FUNCTION   */
 ecl_cmp_defun(VV[571]);                          /*  DEFAULT-SOURCE-EXTENSION */
 ecl_cmp_defun(VV[572]);                          /*  DEFAULT-BINARY-EXTENSION */
 ecl_cmp_defmacro(VV[573]);                       /*  DEFINE-LANGUAGE */
 {
  cl_object T0, T1, T2, T3;
 {
  cl_object v1;
  T0 = (ECL_SYM("COMPILE-FILE",234)->symbol.gfdef);
  T1 = (ECL_SYM("LOAD",487)->symbol.gfdef);
  T2 = ecl_car(ecl_symbol_value(VV[30]));
  T3 = ecl_cdr(ecl_symbol_value(VV[30]));
  v1 = L116make_language(10, ECL_SYM("NAME",1273), VV[285], VV[290], T0, VV[291], T1, VV[292], T2, VV[293], T3);
  si_hash_set(VV[285], ecl_symbol_value(VV[277]), v1);
 }
 }
 ecl_cmp_defun(VV[574]);                          /*  SCHEME-COMPILE-FILE */
 {
  cl_object T0, T1;
 {
  cl_object v1;
  T0 = ecl_fdefinition(VV[298]);
  T1 = (ECL_SYM("LOAD",487)->symbol.gfdef);
  v1 = L116make_language(10, ECL_SYM("NAME",1273), VV[299], VV[290], T0, VV[291], T1, VV[292], _ecl_static_119, VV[293], _ecl_static_120);
  si_hash_set(VV[299], ecl_symbol_value(VV[277]), v1);
 }
 }
 si_Xmake_special(VV[300]);
 cl_set(VV[300],_ecl_static_121);
 ecl_cmp_defun(VV[575]);                          /*  RUN-UNIX-PROGRAM */
 si_Xmake_special(VV[302]);
 if (ecl_boundp(cl_env_copy,VV[302])) { goto L892; }
 cl_set(VV[302],_ecl_static_123);
L892:;
 ecl_cmp_defun(VV[577]);                          /*  RUN-SHELL-COMMAND */
 ecl_cmp_defun(VV[580]);                          /*  DEFAULT-OUTPUT-PATHNAME */
 ecl_cmp_defun(VV[581]);                          /*  RUN-COMPILER    */
 ecl_cmp_defun(VV[582]);                          /*  C-COMPILE-FILE  */
 {
  cl_object T0, T1;
 {
  cl_object v1;
  T0 = ecl_fdefinition(VV[308]);
  T1 = (ECL_SYM("LOAD",487)->symbol.gfdef);
  v1 = L116make_language(10, ECL_SYM("NAME",1273), VV[309], VV[290], T0, VV[291], T1, VV[292], _ecl_static_138, VV[293], _ecl_static_129);
  si_hash_set(VV[309], ecl_symbol_value(VV[277]), v1);
 }
 }
 cl_export(1, VVtemp[30]);
 si_Xmake_special(VV[310]);
 cl_set(VV[310],_ecl_static_139);
 si_Xmake_special(VV[311]);
 cl_set(VV[311],VVtemp[31]);
 ecl_cmp_defun(VV[596]);                          /*  FORTRAN-COMPILE-FILE */
 {
  cl_object T0, T1;
 {
  cl_object v1;
  T0 = ecl_fdefinition(VV[312]);
  T1 = (ECL_SYM("IDENTITY",426)->symbol.gfdef);
  v1 = L116make_language(10, ECL_SYM("NAME",1273), VV[313], VV[290], T0, VV[291], T1, VV[292], _ecl_static_141, VV[293], _ecl_static_129);
  si_hash_set(VV[313], ecl_symbol_value(VV[277]), v1);
 }
 }
 cl_export(1, VVtemp[32]);
 si_Xmake_special(VV[314]);
 cl_set(VV[314],_ecl_static_142);
 ecl_cmp_defun(VV[597]);                          /*  BUILD-LIB       */
 L7component_operation(2, VV[216], VV[316]);
 L7component_operation(2, ECL_SYM("COMPILE",233), VV[316]);
 L7component_operation(2, VV[154], VV[317]);
 L7component_operation(2, ECL_SYM("LOAD",487), VV[317]);
 ecl_cmp_defun(VV[598]);                          /*  COMPILE-AND-LOAD-OPERATION */
 ecl_cmp_defun(VV[599]);                          /*  UNMUNGE-LUCID   */
 ecl_cmp_defun(VV[600]);                          /*  COMPILE-FILE-OPERATION */
 {
  cl_object T0;
 if (Null(cl_find_package(_ecl_static_148))) { goto L968; }
 T0 = cl_find_symbol(2, _ecl_static_149, _ecl_static_148);
 cl_import(1, T0);
L968:;
 }
 if ((cl_fboundp(VV[325]))!=ECL_NIL) { goto L970; }
 ecl_cmp_defun(VV[601]);                          /*  COMPILED-FILE-P */
L970:;
 ecl_cmp_defun(VV[602]);                          /*  NEEDS-COMPILATION */
 ecl_cmp_defun(VV[603]);                          /*  NEEDS-LOADING   */
 ecl_cmp_defun(VV[604]);                          /*  LOAD-FILE-OPERATION */
 L7component_operation(2, VV[332], VV[333]);
 L7component_operation(2, VV[334], VV[333]);
 L7component_operation(2, VV[253], VV[333]);
 L7component_operation(2, VV[335], VV[333]);
 ecl_cmp_defun(VV[605]);                          /*  DELETE-BINARIES-OPERATION */
 ecl_cmp_defun(VV[606]);                          /*  BINARY-EXISTS   */
 ecl_cmp_defun(VV[607]);                          /*  COMPILE-AND-LOAD-SOURCE-IF-NO-BINARY */
 ecl_cmp_defun(VV[608]);                          /*  LOAD-SOURCE-IF-NO-BINARY */
 ecl_cmp_defun(VV[609]);                          /*  FILES-WHICH-NEED-COMPILATION */
 ecl_cmp_defun(VV[610]);                          /*  FILES-IN-SYSTEM-AND-DEPENDENTS */
 ecl_cmp_defun(VV[611]);                          /*  FILES-IN-SYSTEM */
 ecl_cmp_defun(VV[612]);                          /*  FILE-PATHNAMES-IN-COMPONENT */
 ecl_cmp_defun(VV[613]);                          /*  FILE-COMPONENTS-IN-COMPONENT */
 {
  cl_object T0;
 T0 = cl_symbol_function(VV[243]);
 si_fset(4, VV[349], T0, ECL_NIL, ECL_NIL);
 }
 si_Xmake_special(VV[350]);
 cl_set(VV[350],_ecl_static_159);
 ecl_cmp_defun(VV[614]);                          /*  SYSTEM-SOURCE-SIZE */
 ecl_cmp_defun(VV[615]);                          /*  FILE-LIST-SIZE  */
}
