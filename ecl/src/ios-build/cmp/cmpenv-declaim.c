/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPENV-DECLAIM.LSP                            */
#include <ecl/ecl-cmp.h>
#include "cmp/cmpenv-declaim.eclh"
/*	function definition for PROCESS-DECLAIM-ARGS                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2process_declaim_args(cl_object v1args)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;                                  /*  SPECIALS        */
   cl_object v4;                                  /*  TYPES           */
   cl_object v5;                                  /*  IGNORED         */
   cl_object v6;                                  /*  OTHERS          */
   T0 = CONS(ECL_SYM("DECLARE",274),v1args);
   T1 = ecl_list1(T0);
   value0 = ecl_function_dispatch(cl_env_copy,VV[13])(2, T1, ECL_NIL) /*  C1BODY */;
   {
    const int v7 = cl_env_copy->nvalues;
    cl_object v8;
    v8 = (v7<=1)? ECL_NIL : cl_env_copy->values[1];
    v3 = v8;
    v8 = (v7<=2)? ECL_NIL : cl_env_copy->values[2];
    v4 = v8;
    v8 = (v7<=3)? ECL_NIL : cl_env_copy->values[3];
    v5 = v8;
    v8 = (v7<=4)? ECL_NIL : cl_env_copy->values[4];
    v6 = v8;
   }
   if (Null(v5)) { goto L2; }
   ecl_function_dispatch(cl_env_copy,VV[14])(1, _ecl_static_1) /*  CMPWARN-STYLE */;
L2:;
   T0 = ecl_fdefinition(VV[15]);
   T1 = LC1add_variables(ecl_symbol_value(VV[3]), v4, v3);
   cl_reduce(4, T0, v6, VV[2], T1);
   T0 = ecl_fdefinition(VV[15]);
   T1 = LC1add_variables(ecl_symbol_value(VV[4]), v4, v3);
   value0 = cl_reduce(4, T0, v6, VV[2], T1);
   return value0;
  }
 }
}
/*	local function ADD-VARIABLES                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC1add_variables(cl_object v1env, cl_object v2types, cl_object v3specials)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4name;
   cl_object v5;
   v4name = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v3specials))) FEtype_error_list(v3specials);
   v5 = v3specials;
L5:;
   if (!(ecl_endp(v5))) { goto L7; }
   goto L6;
L7:;
   v4name = _ecl_car(v5);
   {
    cl_object v6;
    v6 = _ecl_cdr(v5);
    if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
    v5 = v6;
   }
   if ((ecl_assql(v4name,v2types))!=ECL_NIL) { goto L15; }
   {
    cl_object v6v;
    v6v = ecl_function_dispatch(cl_env_copy,VV[16])(3, v4name, VV[0], ECL_SYM("SPECIAL",789)) /*  C1MAKE-GLOBAL-VARIABLE */;
    v1env = ecl_function_dispatch(cl_env_copy,VV[17])(3, v6v, v1env, ECL_NIL) /*  CMP-ENV-REGISTER-VAR */;
   }
L15:;
   goto L5;
L6:;
  }
  {
   cl_object v4name;
   cl_object v5type;
   cl_object v6;
   v4name = ECL_NIL;
   v5type = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v2types))) FEtype_error_list(v2types);
   v6 = v2types;
   {
    cl_object v7specialp;
    v7specialp = ECL_NIL;
    {
     cl_object v8kind;
     v8kind = ECL_NIL;
     {
      cl_object v9v;
      v9v = ECL_NIL;
L28:;
      if (!(ecl_endp(v6))) { goto L30; }
      goto L29;
L30:;
      {
       cl_object v10;
       v10 = _ecl_car(v6);
       v4name = ecl_car(v10);
       v10 = ecl_cdr(v10);
       v5type = v10;
      }
      {
       cl_object v10;
       v10 = _ecl_cdr(v6);
       if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
       v6 = v10;
      }
      value0 = si_specialp(v4name);
      if ((value0)!=ECL_NIL) { goto L46; }
      v7specialp = ecl_memql(v4name,v3specials);
      goto L44;
L46:;
      v7specialp = value0;
      goto L44;
L44:;
      if (Null(v7specialp)) { goto L50; }
      v8kind = ECL_SYM("SPECIAL",789);
      goto L49;
L50:;
      v8kind = VV[1];
L49:;
      v9v = ecl_function_dispatch(cl_env_copy,VV[16])(5, v4name, ECL_SYM("TYPE",1318), v5type, VV[0], v8kind) /*  C1MAKE-GLOBAL-VARIABLE */;
      v1env = ecl_function_dispatch(cl_env_copy,VV[17])(3, v9v, v1env, ECL_NIL) /*  CMP-ENV-REGISTER-VAR */;
      goto L28;
L29:;
     }
    }
   }
  }
  value0 = v1env;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function DECLAIM                                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC3declaim(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_cdr(v1);
   T0 = cl_list(2, ECL_SYM("QUOTE",679), v3);
   T1 = cl_list(2, VV[5], T0);
   T2 = cl_list(3, ECL_SYM("EVAL-WHEN",340), VV[7], T1);
   T3 = cl_list(2, ECL_SYM("QUOTE",679), v3);
   T4 = cl_list(3, ECL_SYM("MAPC",543), VV[8], T3);
   T5 = cl_list(3, ECL_SYM("EVAL-WHEN",340), VV[7], T4);
   T6 = cl_list(5, ECL_SYM("WITH-BACKEND",1768), ECL_SYM("C/C++",1770), T2, ECL_SYM("BYTECODES",1769), T5);
   T7 = cl_list(2, ECL_SYM("QUOTE",679), v3);
   T8 = cl_list(3, ECL_SYM("MAPC",543), VV[8], T7);
   T9 = cl_list(3, ECL_SYM("EVAL-WHEN",340), VV[9], T8);
   value0 = cl_list(4, ECL_SYM("LOCALLY",490), VV[6], T6, T9);
   return value0;
  }
 }
}
/*	local function C-DECLAIM                                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC4ext__c_declaim(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_cdr(v1);
   T0 = cl_list(2, ECL_SYM("QUOTE",679), v3);
   T1 = cl_list(2, VV[5], T0);
   T2 = cl_list(3, ECL_SYM("EVAL-WHEN",340), VV[7], T1);
   value0 = cl_list(3, ECL_SYM("WITH-BACKEND",1768), ECL_SYM("C/C++",1770), T2);
   return value0;
  }
 }
}

#include "cmp/cmpenv-declaim.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclrVc1hzg3m0Ul9_XyxTOE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPENV-DECLAIM.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclrVc1hzg3m0Ul9_XyxTOE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[12]);                           /*  PROCESS-DECLAIM-ARGS */
 ecl_cmp_defmacro(VV[18]);                        /*  DECLAIM         */
 ecl_cmp_defmacro(VV[19]);                        /*  C-DECLAIM       */
}
