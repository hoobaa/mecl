/*	Compiler: ECL 12.12.1                                         */
/*	Source: EXT:BYTECMP;BYTECMP.LSP                               */
#include <ecl/ecl-cmp.h>
#include "clos/bytecmp.eclh"
/*	function definition for BC-DISASSEMBLE                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1bc_disassemble(cl_object v1thing)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
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
   si_bc_disassemble(v1thing);
   goto L4;
L8:;
   if (!(ECL_CONSP(v1thing))) { goto L10; }
   {
    cl_object v3;
    v3 = ecl_car(v1thing);
    if (!((v3)==(ECL_SYM("LAMBDA",452)))) { goto L17; }
    goto L14;
    goto L15;
L17:;
    goto L15;
L15:;
    if (!(ecl_eql(v3,VV[1]))) { goto L10; }
    goto L11;
L14:;
   }
L11:;
   T0 = (cl_env_copy->function=(ECL_SYM("COMPILE",233)->symbol.gfdef))->cfun.entry(2, ECL_NIL, v1thing) /*  COMPILE */;
   (cl_env_copy->function=(ECL_SYM("DISASSEMBLE",305)->symbol.gfdef))->cfun.entry(1, T0) /*  DISASSEMBLE */;
   goto L4;
L10:;
   T0 = ecl_list1(v1thing);
   cl_error(9, ECL_SYM("SIMPLE-TYPE-ERROR",773), ECL_SYM("DATUM",1214), v1thing, ECL_SYM("EXPECTED-TYPE",1232), VV[3], ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_2, ECL_SYM("FORMAT-ARGUMENTS",1239), T0);
  }
L4:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for BC-COMPILE                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2bc_compile(cl_narg narg, cl_object v1name, ...)
{
 cl_object T0, T1, T2, T3, T4;
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
  {
   cl_object v4form;
   v4form = ECL_NIL;
   if (Null(v3supplied_p)) { goto L4; }
   if (Null(v2def)) { goto L4; }
   if (Null(cl_functionp(v2def))) { goto L7; }
   if ((cl_function_lambda_expression(v2def))!=ECL_NIL) { goto L9; }
   cl_env_copy->nvalues = 3;
   cl_env_copy->values[2] = ECL_NIL;
   cl_env_copy->values[1] = ECL_NIL;
   cl_env_copy->values[0] = v2def;
   return cl_env_copy->values[0];
L9:;
   v2def = cl_function_lambda_expression(v2def);
L7:;
   if (Null(v1name)) { goto L13; }
   T0 = cl_list(2, ECL_SYM("QUOTE",679), v1name);
   T1 = cl_list(2, ECL_SYM("SYMBOL-FUNCTION",841), T0);
   T2 = cl_list(2, ECL_SYM("FUNCTION",396), v2def);
   T3 = cl_list(3, ECL_SYM("SETF",750), T1, T2);
   T4 = cl_list(2, ECL_SYM("QUOTE",679), v1name);
   v4form = cl_list(3, ECL_SYM("PROGN",671), T3, T4);
   goto L12;
L13:;
   T0 = cl_list(2, ECL_SYM("FUNCTION",396), v2def);
   v4form = cl_list(3, ECL_SYM("SETQ",751), VV[5], T0);
L12:;
   goto L3;
L4:;
   if ((cl_fboundp(v1name))!=ECL_NIL) { goto L15; }
   cl_error(2, _ecl_static_3, v1name);
   goto L3;
L15:;
   v2def = cl_symbol_function(v1name);
   if (Null(si_of_class_p(2, v2def, ECL_SYM("STANDARD-GENERIC-FUNCTION",974)))) { goto L17; }
   (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(1, _ecl_static_4) /*  WARN */;
   cl_env_copy->nvalues = 3;
   cl_env_copy->values[2] = ECL_NIL;
   cl_env_copy->values[1] = ECL_T;
   cl_env_copy->values[0] = v2def;
   return cl_env_copy->values[0];
L17:;
   v4form = cl_function_lambda_expression(v2def);
   if (!(v4form==ECL_NIL)) { goto L21; }
   (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(2, _ecl_static_5, v1name) /*  WARN */;
   cl_env_copy->nvalues = 3;
   cl_env_copy->values[2] = ECL_NIL;
   cl_env_copy->values[1] = ECL_T;
   cl_env_copy->values[0] = v2def;
   return cl_env_copy->values[0];
L21:;
   T0 = cl_list(2, ECL_SYM("QUOTE",679), v1name);
   T1 = cl_list(2, ECL_SYM("SYMBOL-FUNCTION",841), T0);
   T2 = cl_list(2, ECL_SYM("FUNCTION",396), v4form);
   T3 = cl_list(3, ECL_SYM("SETF",750), T1, T2);
   T4 = cl_list(2, ECL_SYM("QUOTE",679), v1name);
   v4form = cl_list(3, ECL_SYM("PROGN",671), T3, T4);
L3:;
   T0 = cl_eval(v4form);
   cl_env_copy->nvalues = 3;
   cl_env_copy->values[2] = ECL_NIL;
   cl_env_copy->values[1] = ECL_NIL;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for BC-COMPILE-FILE-PATHNAME              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3bc_compile_file_pathname(cl_narg narg, cl_object v1name, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2output_file;
  cl_object v3type;
  cl_object v4verbose;
  cl_object v5print;
  cl_object v6c_file;
  cl_object v7h_file;
  cl_object v8data_file;
  cl_object v9shared_data_file;
  cl_object v10system_p;
  cl_object v11load;
  cl_object v12external_format;
  ecl_va_list args; ecl_va_start(args,v1name,narg,1);
  {
   cl_object keyvars[22];
   cl_parse_key(args,11,L3bc_compile_file_pathnamekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[11])) {
    v2output_file = v1name;
   } else {
    v2output_file = keyvars[0];
   }
   if (Null(keyvars[12])) {
    v3type = VV[7];
   } else {
    v3type = keyvars[1];
   }
   v4verbose = keyvars[2];
   v5print = keyvars[3];
   v6c_file = keyvars[4];
   v7h_file = keyvars[5];
   v8data_file = keyvars[6];
   v9shared_data_file = keyvars[7];
   v10system_p = keyvars[8];
   v11load = keyvars[9];
   v12external_format = keyvars[10];
  }
  {
   cl_object v13extension;
   v13extension = _ecl_static_6;
   if (!(ecl_eql(v3type,VV[7]))) { goto L10; }
   goto L7;
   goto L8;
L10:;
   goto L8;
L8:;
   if (!(ecl_eql(v3type,VV[9]))) { goto L5; }
   goto L6;
L7:;
L6:;
   v13extension = _ecl_static_6;
   goto L4;
L5:;
   cl_error(2, _ecl_static_7, v3type);
L4:;
   value0 = cl_make_pathname(4, ECL_SYM("TYPE",1318), v13extension, ECL_SYM("DEFAULTS",1216), v2output_file);
   return value0;
  }
 }
}
/*	function definition for BC-COMPILE-FILE                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4bc_compile_file(volatile cl_narg narg, cl_object volatile v1input, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  volatile cl_object v2load;
  volatile cl_object v3external_format;
  volatile cl_object v4output_file;
  volatile cl_object v5output_file_p;
  ecl_va_list args; ecl_va_start(args,v1input,narg,1);
  {
   cl_object keyvars[10];
   cl_parse_key(args,5,L4bc_compile_filekeys,keyvars,NULL,TRUE);
   ecl_va_end(args);
   if (Null(keyvars[5])) {
    ecl_bds_push(cl_env_copy,ECL_SYM("*COMPILE-VERBOSE*",29)); /*  *COMPILE-VERBOSE* */
   } else {
    ecl_bds_bind(cl_env_copy,ECL_SYM("*COMPILE-VERBOSE*",29),keyvars[0]); /*  *COMPILE-VERBOSE* */
   }
   if (Null(keyvars[6])) {
    ecl_bds_push(cl_env_copy,ECL_SYM("*COMPILE-PRINT*",28)); /*  *COMPILE-PRINT* */
   } else {
    ecl_bds_bind(cl_env_copy,ECL_SYM("*COMPILE-PRINT*",28),keyvars[1]); /*  *COMPILE-PRINT* */
   }
   v2load = keyvars[2];
   if (Null(keyvars[8])) {
    v3external_format = ECL_SYM("DEFAULT",1215);
   } else {
    v3external_format = keyvars[3];
   }
   v4output_file = keyvars[4];
   v5output_file_p = keyvars[9];
  }
  if (Null(v5output_file_p)) { goto L4; }
  v4output_file = cl_pathname(v4output_file);
  goto L3;
L4:;
  v4output_file = L3bc_compile_file_pathname(1, v1input);
L3:;
  if (Null(ecl_symbol_value(ECL_SYM("*COMPILE-VERBOSE*",29)))) { goto L6; }
  cl_format(3, ECL_T, _ecl_static_8, v1input);
L6:;
  if ((cl_streamp(v1input))!=ECL_NIL) { goto L9; }
  T0 = cl_truename(v1input);
  T1 = CONS(T0,ecl_make_fixnum(0));
  ecl_bds_bind(cl_env_copy,ECL_SYM("*SOURCE-LOCATION*",1180),T1); /*  *SOURCE-LOCATION* */
  T0 = cl_merge_pathnames(1, v1input);
  T1 = cl_pathname(T0);
  ecl_bds_bind(cl_env_copy,ECL_SYM("*COMPILE-FILE-PATHNAME*",26),T1); /*  *COMPILE-FILE-PATHNAME* */
  T0 = cl_truename(v1input);
  ecl_bds_bind(cl_env_copy,ECL_SYM("*COMPILE-FILE-TRUENAME*",27),T0); /*  *COMPILE-FILE-TRUENAME* */
  {
   volatile cl_object v6sin;
   v6sin = cl_open(3, v1input, ECL_SYM("DIRECTION",1218), ECL_SYM("INPUT",1254));
   {
    volatile bool unwinding = FALSE;
    cl_index v7=ECL_STACK_INDEX(cl_env_copy),v8;
    ecl_frame_ptr next_fr;
    if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
      unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
    } else {
    {
     struct ecl_stack_frame _ecl_inner_frame_aux;
     volatile cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
     {
      cl_object v9;
      v9 = _ecl_inner_frame;
      cl_env_copy->values[0] = L4bc_compile_file(3, v6sin, VV[12], v4output_file);
      ecl_stack_frame_push_values(v9);
      if (Null(v6sin)) { goto L17; }
      cl_close(1, v6sin);
L17:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v9);
     }
     ecl_stack_frame_close(_ecl_inner_frame);
    }
    }
    ecl_frs_pop(cl_env_copy);
    v8=ecl_stack_push_values(cl_env_copy);
    if (Null(v6sin)) { goto L19; }
    cl_close(3, v6sin, ECL_SYM("ABORT",1195), ECL_T);
L19:;
    ecl_stack_pop_values(cl_env_copy,v8);
    if (unwinding) ecl_unwind(cl_env_copy,next_fr);
    ECL_STACK_SET_INDEX(cl_env_copy,v7);
    ecl_bds_unwind1(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    goto L8;
   }
  }
L9:;
  if ((v5output_file_p)!=ECL_NIL) { goto L21; }
  cl_error(1, _ecl_static_9);
  goto L8;
L21:;
  {
   volatile cl_object v9sout;
   v9sout = cl_open(9, v4output_file, ECL_SYM("DIRECTION",1218), ECL_SYM("OUTPUT",1282), ECL_SYM("IF-EXISTS",1245), ECL_SYM("SUPERSEDE",1314), ECL_SYM("IF-DOES-NOT-EXIST",1244), ECL_SYM("CREATE",1213), ECL_SYM("EXTERNAL-FORMAT",1236), v3external_format);
   {
    volatile bool unwinding = FALSE;
    cl_index v10=ECL_STACK_INDEX(cl_env_copy),v11;
    ecl_frame_ptr next_fr;
    if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
      unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
    } else {
    {
     struct ecl_stack_frame _ecl_inner_frame_aux;
     volatile cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
     {
      cl_object v12;
      v12 = _ecl_inner_frame;
      {
       cl_object v13binary;
       ecl_bds_push(cl_env_copy,ECL_SYM("*PACKAGE*",43)); /*  *PACKAGE* */
       ecl_bds_bind(cl_env_copy,ECL_SYM("*BYTECODES-COMPILER*",1705),ECL_T); /*  *BYTECODES-COMPILER* */
       {
        cl_object v14position;
        v14position = ECL_NIL;
        {
         cl_object v15form;
         v15form = ECL_NIL;
         {
          cl_object v16;
          cl_object v17;
          v16 = ecl_list1(ECL_NIL);
          v17 = v16;
L34:;
          v14position = cl_file_position(1, v1input);
          v15form = cl_read(3, v1input, ECL_NIL, ECL_SYM("EOF",1228));
          if (!((v15form)==(ECL_SYM("EOF",1228)))) { goto L40; }
          goto L35;
L40:;
          if (Null(ecl_symbol_value(ECL_SYM("*SOURCE-LOCATION*",1180)))) { goto L42; }
          {
          cl_object v18;
          v18 = ecl_symbol_value(ECL_SYM("*SOURCE-LOCATION*",1180));
          if (ecl_unlikely(ECL_ATOM(v18))) FEtype_error_cons(v18);
          T0 = v18;
          }
          (ECL_CONS_CDR(T0)=v14position,T0);
L42:;
          if (ecl_unlikely(ECL_ATOM(v17))) FEtype_error_cons(v17);
          T0 = v17;
          T1 = si_eval_with_env(5, v15form, ECL_NIL, ECL_NIL, ECL_NIL, ECL_NIL);
          v17 = ecl_list1(T1);
          (ECL_CONS_CDR(T0)=v17,T0);
          goto L34;
L35:;
          T0 = ecl_cdr(v16);
          ecl_bds_unwind1(cl_env_copy);
          ecl_bds_unwind1(cl_env_copy);
          v13binary = T0;
          goto L29;
         }
        }
       }
L29:;
       {
        cl_object v14;
        v14 = ecl_symbol_value(ECL_SYM("+ECL-SYNTAX-PROGV-LIST+",1721));
        {
         cl_object v16, v17; cl_index v15;
         v16 = _ecl_car(v14);
         v17 = _ecl_cdr(v14);
         v15 = ecl_progv(cl_env_copy, v16, v17);
         cl_write(11, v13binary, ECL_SYM("STREAM",1313), v9sout, ECL_SYM("CIRCLE",1206), ECL_T, ECL_SYM("ESCAPE",1230), ECL_T, ECL_SYM("READABLY",1296), ECL_T, ECL_SYM("PRETTY",1289), ECL_NIL);
         ecl_bds_unwind(cl_env_copy,v15);
        }
       }
       cl_env_copy->values[0] = ecl_terpri(v9sout);
       cl_env_copy->nvalues = 1;
      }
      ecl_stack_frame_push_values(v12);
      if (Null(v9sout)) { goto L57; }
      cl_close(1, v9sout);
L57:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v12);
     }
     ecl_stack_frame_close(_ecl_inner_frame);
    }
    }
    ecl_frs_pop(cl_env_copy);
    v11=ecl_stack_push_values(cl_env_copy);
    if (Null(v9sout)) { goto L59; }
    cl_close(3, v9sout, ECL_SYM("ABORT",1195), ECL_T);
L59:;
    ecl_stack_pop_values(cl_env_copy,v11);
    if (unwinding) ecl_unwind(cl_env_copy,next_fr);
    ECL_STACK_SET_INDEX(cl_env_copy,v10);
   }
  }
L8:;
  if (Null(v2load)) { goto L61; }
  cl_load(3, v4output_file, ECL_SYM("VERBOSE",1325), ecl_symbol_value(ECL_SYM("*COMPILE-VERBOSE*",29)));
L61:;
  cl_env_copy->nvalues = 3;
  cl_env_copy->values[2] = ECL_NIL;
  cl_env_copy->values[1] = ECL_NIL;
  cl_env_copy->values[0] = v4output_file;
  ecl_bds_unwind1(cl_env_copy);
  ecl_bds_unwind1(cl_env_copy);
  return cl_env_copy->values[0];
 }
}
/*	function definition for INSTALL-BYTECODES-COMPILER            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5install_bytecodes_compiler()
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_find_package(VV[14]);
  si_package_lock(T0, ECL_NIL);
  cl_set(ECL_SYM("*FEATURES*",34),cl_adjoin(2, VV[15], ecl_symbol_value(ECL_SYM("*FEATURES*",34))));
  T0 = ecl_fdefinition(VV[4]);
  si_fset(4, ECL_SYM("DISASSEMBLE",305), T0, ECL_NIL, ECL_NIL);
  T0 = ecl_fdefinition(VV[6]);
  si_fset(4, ECL_SYM("COMPILE",233), T0, ECL_NIL, ECL_NIL);
  T0 = ecl_fdefinition(VV[13]);
  si_fset(4, ECL_SYM("COMPILE-FILE",234), T0, ECL_NIL, ECL_NIL);
  T0 = ecl_fdefinition(VV[11]);
  si_fset(4, ECL_SYM("COMPILE-FILE-PATHNAME",235), T0, ECL_NIL, ECL_NIL);
  T0 = cl_find_package(VV[14]);
  value0 = si_package_lock(T0, ECL_T);
  return value0;
 }
}
/*	function definition for INSTALL-C-COMPILER                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6install_c_compiler()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  cl_require(1, VV[17]);
  value0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("INSTALL-C-COMPILER",1952))(0);
  return value0;
 }
}

#include "clos/bytecmp.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclFhbSrAvTKYBm9_QyS5hE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("EXT:BYTECMP;BYTECMP.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclFhbSrAvTKYBm9_QyS5hE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_function_dispatch(cl_env_copy,VV[20])(10, _ecl_static_1, ECL_NIL, ECL_NIL, VVtemp[0], ECL_NIL, ECL_NIL, VVtemp[1], ECL_NIL, ECL_NIL, ECL_NIL) /*  DODEFPACKAGE */;
 ecl_cmp_defun(VV[21]);                           /*  BC-DISASSEMBLE  */
 ecl_cmp_defun(VV[22]);                           /*  BC-COMPILE      */
 ecl_cmp_defun(VV[23]);                           /*  BC-COMPILE-FILE-PATHNAME */
 ecl_cmp_defun(VV[35]);                           /*  BC-COMPILE-FILE */
 ecl_cmp_defun(VV[41]);                           /*  INSTALL-BYTECODES-COMPILER */
 ecl_cmp_defun(VV[42]);                           /*  INSTALL-C-COMPILER */
 L5install_bytecodes_compiler();
 cl_provide(VV[19]);
 si_package_lock(_ecl_static_10, ECL_T);
}
