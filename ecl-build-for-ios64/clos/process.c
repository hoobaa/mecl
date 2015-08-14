/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:LSP;PROCESS.LSP                                   */
#include <ecl/ecl-cmp.h>
#include "clos/process.eclh"
/*	function definition for MAKE-EXTERNAL-PROCESS                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1make_external_process()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = si_make_structure(6, VV[2], ECL_NIL, ECL_NIL, ECL_NIL, ECL_SYM("RUNNING",1749), ECL_NIL);
  return value0;
 }
}
/*	function definition for EXTERNAL-PROCESS-STATUS               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2external_process_status(cl_object v1external_process)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2status;
   v2status = ecl_function_dispatch(cl_env_copy,VV[7])(1, v1external_process) /*  EXTERNAL-PROCESS-%STATUS */;
   if (!((v2status)==(ECL_SYM("RUNNING",1749)))) { goto L2; }
   value0 = si_external_process_wait(2, v1external_process, ECL_NIL);
   return value0;
L2:;
   T0 = ecl_function_dispatch(cl_env_copy,VV[8])(1, v1external_process) /*  EXTERNAL-PROCESS-%CODE */;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = T0;
   cl_env_copy->values[0] = v2status;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for SYSTEM                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_system(cl_object v1cmd_string)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   v2 = si_getenv(_ecl_static_2);
   {
    struct ecl_stack_frame _ecl_inner_frame_aux;
    cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
    {
     cl_object v3;
     v3 = _ecl_inner_frame;
     T1 = cl_list(2, _ecl_static_3, v1cmd_string);
     cl_env_copy->values[0] = si_run_program(10, v2, T1, ECL_SYM("WAIT",1329), ECL_T, ECL_SYM("OUTPUT",1282), ECL_T, ECL_SYM("INPUT",1254), ECL_T, ECL_SYM("ERROR",1229), ECL_T);
     ecl_stack_frame_push_values(v3);cl_env_copy->values[0]=ecl_apply_from_stack_frame(v3,ECL_SYM("LIST",481));
     value0 = cl_env_copy->values[0];
    }
    ecl_stack_frame_close(_ecl_inner_frame);
   }
   T0 = value0;
   value0 = ecl_cadr(T0);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}

#include "clos/process.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclHyXK6vLliCBi9_73otVE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:LSP;PROCESS.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclHyXK6vLliCBi9_73otVE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 si_define_structure(15, ECL_SYM("EXTERNAL-PROCESS",1744), _ecl_static_1, ECL_NIL, ECL_NIL, VVtemp[0], VVtemp[1], VV[0], ECL_NIL, ECL_NIL, ECL_NIL, VVtemp[2], ecl_make_fixnum(5), ECL_NIL, ECL_NIL, VV[1]);
 VV[2]= cl_find_class(1, ECL_SYM("EXTERNAL-PROCESS",1744));
 ecl_cmp_defun(VV[5]);                            /*  MAKE-EXTERNAL-PROCESS */
 ecl_cmp_defun(VV[6]);                            /*  EXTERNAL-PROCESS-STATUS */
 (void)0; /* No entry created for SYSTEM */
}
