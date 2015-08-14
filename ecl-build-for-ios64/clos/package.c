/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CLOS;PACKAGE.LSP                                  */
#include <ecl/ecl-cmp.h>
#include "clos/package.eclh"

#include "clos/package.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclMmxSxIb7_jK8xWE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CLOS;PACKAGE.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclMmxSxIb7_jK8xWE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 ecl_function_dispatch(cl_env_copy,VV[0])(10, _ecl_static_0, ECL_NIL, ECL_NIL, VVtemp[0], ECL_NIL, ECL_NIL, ECL_NIL, ECL_NIL, VVtemp[1], ECL_NIL) /*  DODEFPACKAGE */;
}