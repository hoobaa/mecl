/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPOPT-CONSTANT.LSP                           */
#include <ecl/ecl-cmp.h>
#include "cmp/cmpopt-constant.eclh"
/*	function definition for CONSTANT-EXPRESSION-P                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1constant_expression_p(cl_object v1form)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_constantp(1, v1form);
  if ((value0)!=ECL_NIL) { goto L2; }
  if (!(ECL_CONSP(v1form))) { goto L5; }
  T0 = ecl_fdefinition(VV[2]);
  T1 = ecl_cdr(v1form);
  if (Null(cl_every(2, T0, T1))) { goto L5; }
  {
   cl_object v2head;
   v2head = ecl_car(v1form);
   value0 = ecl_memql(v2head,VV[0]);
   if ((value0)!=ECL_NIL) { goto L11; }
   if (Null(si_get_sysprop(v2head, VV[1]))) { goto L14; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[6])(1, v2head) /*  INLINE-POSSIBLE */;
   return value0;
L14:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L11:;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L5:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for EXTRACT-CONSTANT-VALUE                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3extract_constant_value(volatile cl_narg narg, cl_object volatile v1form, ...)
{
 cl_object T0, T1, T2, T3;
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  volatile cl_object v2failure;
  va_list args; va_start(args,v1form);
  {
   int i = 1;
   if (i >= narg) {
    v2failure = ECL_NIL;
   } else {
    i++;
    v2failure = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (Null(L1constant_expression_p(v1form))) { goto L2; }
  {
   volatile cl_object env1 = env0;
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(ECL_NIL,env1);
   {
    volatile cl_object env2 = env1;
    CLV1 = env2 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env2); /*  TAGBODY */
    if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV1))) {
    if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L4;
    ecl_internal_error("GO found an inexistent tag");
    }
    {cl_object v3;
     v3 = ECL_NIL;
     v3 = ecl_make_cclosure_va((cl_objectfn)LC2__g3,env2,Cblock);
     T0 = v3;
    }
    T1 = CONS(ECL_SYM("ERROR",337),T0);
    T2 = ecl_list1(T1);
    T3 = CONS(T2,ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5)));
    ecl_bds_bind(cl_env_copy,ECL_SYM("*HANDLER-CLUSTERS*",5),T3); /*  *HANDLER-CLUSTERS* */
    value0 = ecl_function_dispatch(cl_env_copy,VV[8])(1, v1form) /*  CMP-EVAL */;
    ecl_frs_pop(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    return value0;
L4:;
    value0 = v2failure;
    cl_env_copy->nvalues = 1;
    ecl_frs_pop(cl_env_copy);
    return value0;
   }
  }
L2:;
  value0 = v2failure;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	closure G3                                                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC2__g3(cl_narg narg, cl_object v1si__temp, ...)
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
/*	function definition for CONSTANT-VALUE-P                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5constant_value_p(volatile cl_narg narg, cl_object volatile v1form, ...)
{
 cl_object T0, T1, T2, T3;
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  volatile cl_object v2env;
  va_list args; va_start(args,v1form);
  {
   int i = 1;
   if (i >= narg) {
    v2env = ECL_NIL;
   } else {
    i++;
    v2env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (Null(L1constant_expression_p(v1form))) { goto L2; }
  {
   volatile cl_object env1 = env0;
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(ECL_NIL,env1);
   {
    volatile cl_object env2 = env1;
    CLV1 = env2 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env2); /*  TAGBODY */
    if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV1))) {
    if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L4;
    ecl_internal_error("GO found an inexistent tag");
    }
    {cl_object v3;
     v3 = ECL_NIL;
     v3 = ecl_make_cclosure_va((cl_objectfn)LC4__g7,env2,Cblock);
     T0 = v3;
    }
    T1 = CONS(ECL_SYM("ERROR",337),T0);
    T2 = ecl_list1(T1);
    T3 = CONS(T2,ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5)));
    ecl_bds_bind(cl_env_copy,ECL_SYM("*HANDLER-CLUSTERS*",5),T3); /*  *HANDLER-CLUSTERS* */
    T0 = ecl_function_dispatch(cl_env_copy,VV[8])(1, v1form) /*  CMP-EVAL */;
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = T0;
    cl_env_copy->values[0] = ECL_T;
    value0 = cl_env_copy->values[0];
    ecl_frs_pop(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    return value0;
L4:;
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = v1form;
    cl_env_copy->values[0] = ECL_NIL;
    value0 = cl_env_copy->values[0];
    ecl_frs_pop(cl_env_copy);
    return value0;
   }
  }
L2:;
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = v1form;
  cl_env_copy->values[0] = ECL_NIL;
  return cl_env_copy->values[0];
 }
}
/*	closure G7                                                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC4__g7(cl_narg narg, cl_object v1si__temp, ...)
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

#include "cmp/cmpopt-constant.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclTgDLuNtTY7pp9_yozTOE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPOPT-CONSTANT.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclTgDLuNtTY7pp9_yozTOE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[5]);                            /*  CONSTANT-EXPRESSION-P */
 ecl_cmp_defun(VV[7]);                            /*  EXTRACT-CONSTANT-VALUE */
 ecl_cmp_defun(VV[9]);                            /*  CONSTANT-VALUE-P */
}
