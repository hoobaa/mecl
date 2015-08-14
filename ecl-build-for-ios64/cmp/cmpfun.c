/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPFUN.LSP                                    */
#include <ecl/ecl-cmp.h>
#include "cmp/cmpfun.eclh"
/*	function definition for C1APPLY                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1c1apply(cl_object v1args)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_function_dispatch(cl_env_copy,VV[7])(3, ECL_SYM("APPLY",89), v1args, ecl_make_fixnum(2)) /*  CHECK-ARGS-NUMBER */;
  {
   cl_object v2fun;
   cl_object v3arguments;
   v2fun = ecl_car(v1args);
   v3arguments = ecl_cdr(v1args);
   if (!(ECL_CONSP(v2fun))) { goto L4; }
   T0 = ecl_car(v2fun);
   if (!((T0)==(ECL_SYM("LAMBDA",452)))) { goto L4; }
   T0 = ecl_cdr(v2fun);
   value0 = ecl_function_dispatch(cl_env_copy,VV[8])(3, T0, v3arguments, ECL_T) /*  OPTIMIZE-FUNCALL/APPLY-LAMBDA */;
   return value0;
L4:;
   if (!(ECL_CONSP(v2fun))) { goto L7; }
   T0 = ecl_car(v2fun);
   if (!((T0)==(ECL_SYM("LAMBDA-BLOCK",1339)))) { goto L7; }
   v2fun = cl_macroexpand_1(1, v2fun);
   T0 = ecl_cdr(v2fun);
   value0 = ecl_function_dispatch(cl_env_copy,VV[8])(3, T0, v3arguments, ECL_T) /*  OPTIMIZE-FUNCALL/APPLY-LAMBDA */;
   return value0;
L7:;
   if (!(ECL_CONSP(v2fun))) { goto L12; }
   T0 = ecl_car(v2fun);
   if (!((T0)==(ECL_SYM("FUNCTION",396)))) { goto L12; }
   T0 = ecl_cadr(v2fun);
   if (!(ECL_CONSP(T0))) { goto L12; }
   {
    cl_object v4;
    v4 = ecl_caadr(v2fun);
    if (!((v4)==(ECL_SYM("LAMBDA",452)))) { goto L21; }
    goto L18;
    goto L19;
L21:;
    goto L19;
L19:;
    if (!((v4)==(ECL_SYM("LAMBDA-BLOCK",1339)))) { goto L12; }
    goto L13;
L18:;
   }
L13:;
   T0 = ecl_cadr(v2fun);
   v1args = CONS(T0,v3arguments);
   goto TTL;
L12:;
   {
    cl_object v4form;
    T0 = CONS(VV[2],v1args);
    v4form = ecl_function_dispatch(cl_env_copy,VV[9])(1, T0) /*  C1FUNCALL */;
    if (!(ECL_CONSP(v2fun))) { goto L27; }
    T0 = ecl_car(v2fun);
    if (!((T0)==(ECL_SYM("FUNCTION",396)))) { goto L27; }
    {
     cl_object v5fname;
     cl_object v6type;
     v5fname = ecl_cadr(v2fun);
     v6type = ecl_function_dispatch(cl_env_copy,VV[10])(1, v5fname) /*  GET-RETURN-TYPE */;
     if (Null(v6type)) { goto L27; }
     ecl_structure_set(v4form,VV[3],1,v6type);
    }
L27:;
    value0 = v4form;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	local function BOOLE                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC2boole(cl_object v1, cl_object v2)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4op_code;
   cl_object v5op1;
   cl_object v6op2;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v7;
    v7 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4op_code = v7;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v7;
    v7 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5op1 = v7;
   }
   if (!(v3==ECL_NIL)) { goto L15; }
   si_dm_too_few_arguments(v1);
L15:;
   {
    cl_object v7;
    v7 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v6op2 = v7;
   }
   if (Null(v3)) { goto L20; }
   si_dm_too_many_arguments(v1);
L20:;
   if (Null(cl_constantp(1, v4op_code))) { goto L26; }
   {
    cl_object v7;
    v7 = cl_eval(v4op_code);
    if (!((v7)==(ecl_make_fixnum(0)))) { goto L29; }
    value0 = cl_list(4, ECL_SYM("PROGN",671), v5op1, v6op2, ecl_make_fixnum(0));
    goto L24;
L29:;
    if (!((v7)==(ecl_make_fixnum(15)))) { goto L31; }
    value0 = cl_list(4, ECL_SYM("PROGN",671), v5op1, v6op2, ecl_make_fixnum(-1));
    goto L24;
L31:;
    if (!((v7)==(ecl_make_fixnum(3)))) { goto L33; }
    value0 = cl_list(3, ECL_SYM("PROG1",669), v5op1, v6op2);
    goto L24;
L33:;
    if (!((v7)==(ecl_make_fixnum(5)))) { goto L35; }
    value0 = cl_list(3, ECL_SYM("PROGN",671), v5op1, v6op2);
    goto L24;
L35:;
    if (!((v7)==(ecl_make_fixnum(12)))) { goto L37; }
    T0 = cl_list(2, ECL_SYM("LOGNOT",503), v5op1);
    value0 = cl_list(3, ECL_SYM("PROG1",669), T0, v6op2);
    goto L24;
L37:;
    if (!((v7)==(ecl_make_fixnum(10)))) { goto L39; }
    T0 = cl_list(2, ECL_SYM("LOGNOT",503), v6op2);
    value0 = cl_list(3, ECL_SYM("PROGN",671), v5op1, T0);
    goto L24;
L39:;
    if (!((v7)==(ecl_make_fixnum(1)))) { goto L41; }
    value0 = cl_list(3, ECL_SYM("LOGAND",492), v5op1, v6op2);
    goto L24;
L41:;
    if (!((v7)==(ecl_make_fixnum(7)))) { goto L43; }
    value0 = cl_list(3, ECL_SYM("LOGIOR",500), v5op1, v6op2);
    goto L24;
L43:;
    if (!((v7)==(ecl_make_fixnum(6)))) { goto L45; }
    value0 = cl_list(3, ECL_SYM("LOGXOR",507), v5op1, v6op2);
    goto L24;
L45:;
    if (!((v7)==(ecl_make_fixnum(9)))) { goto L47; }
    value0 = cl_list(3, ECL_SYM("LOGEQV",497), v5op1, v6op2);
    goto L24;
L47:;
    if (!((v7)==(ecl_make_fixnum(14)))) { goto L49; }
    value0 = cl_list(3, ECL_SYM("LOGNAND",501), v5op1, v6op2);
    goto L24;
L49:;
    if (!((v7)==(ecl_make_fixnum(8)))) { goto L51; }
    value0 = cl_list(3, ECL_SYM("LOGNOR",502), v5op1, v6op2);
    goto L24;
L51:;
    if (!((v7)==(ecl_make_fixnum(4)))) { goto L53; }
    value0 = cl_list(3, ECL_SYM("LOGANDC1",493), v5op1, v6op2);
    goto L24;
L53:;
    if (!((v7)==(ecl_make_fixnum(2)))) { goto L55; }
    value0 = cl_list(3, ECL_SYM("LOGANDC2",494), v5op1, v6op2);
    goto L24;
L55:;
    if (!((v7)==(ecl_make_fixnum(13)))) { goto L57; }
    value0 = cl_list(3, ECL_SYM("LOGORC1",504), v5op1, v6op2);
    goto L24;
L57:;
    if (!((v7)==(ecl_make_fixnum(11)))) { goto L59; }
    value0 = cl_list(3, ECL_SYM("LOGORC2",505), v5op1, v6op2);
    goto L24;
L59:;
    value0 = ECL_NIL;
    goto L24;
   }
L26:;
   value0 = ECL_NIL;
   goto L24;
L24:;
   if ((value0)!=ECL_NIL) { goto L23; }
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
L23:;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for RESULT-TYPE                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3result_type(cl_object v1x)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_SYMBOLP(v1x))) { goto L1; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[12])(1, v1x) /*  C1EXPR   */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[13])(1, T0) /*  C1FORM-PRIMARY-TYPE */;
  return value0;
L1:;
  if (Null(cl_constantp(1, v1x))) { goto L3; }
  value0 = cl_type_of(v1x);
  return value0;
L3:;
  if (!(ECL_CONSP(v1x))) { goto L5; }
  T0 = ecl_car(v1x);
  if (!((T0)==(ECL_SYM("THE",856)))) { goto L5; }
  value0 = ecl_cadr(v1x);
  cl_env_copy->nvalues = 1;
  return value0;
L5:;
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}

#include "cmp/cmpfun.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclrllw5SGHSV7k9_VvptVE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPFUN.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclrllw5SGHSV7k9_VvptVE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[6]);                            /*  C1APPLY         */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC2boole,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("BOOLE",138), ECL_SYM("COMPILER-MACRO",238), T0);
 }
 ecl_cmp_defun(VV[11]);                           /*  RESULT-TYPE     */
}
