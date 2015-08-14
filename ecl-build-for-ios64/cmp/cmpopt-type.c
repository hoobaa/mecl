/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPOPT-TYPE.LSP                               */
#include <ecl/ecl-cmp.h>
#include "cmp/cmpopt-type.eclh"
/*	local function DOTIMES                                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC1dotimes(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26, T27, T28, T29;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6variable;
   cl_object v7limit;
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
    v6variable = v8;
   }
   if (!(v5==ECL_NIL)) { goto L16; }
   si_dm_too_few_arguments(v1);
L16:;
   {
    cl_object v8;
    v8 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v7limit = v8;
   }
   {
    cl_object v9;                                 /*  DECLARATIONS    */
    cl_object v10;                                /*  BODY            */
    value0 = si_process_declarations(2, v3, ECL_NIL);
    v9 = value0;
    {
     const int v11 = cl_env_copy->nvalues;
     cl_object v12;
     v12 = (v11<=1)? ECL_NIL : cl_env_copy->values[1];
     v10 = v12;
    }
    {
     cl_object v11_limit;
     v11_limit = cl_gensym(1, _ecl_static_1);
     T0 = cl_list(2, v11_limit, v7limit);
     T1 = ecl_list1(T0);
     T2 = cl_list(2, VV[0], v11_limit);
     T3 = cl_list(2, ECL_SYM("DECLARE",274), T2);
     T4 = cl_list(2, v6variable, ecl_make_fixnum(0));
     T5 = ecl_list1(T4);
     T6 = cl_list(2, ECL_SYM("FIXNUM",372), v6variable);
     T7 = cl_listX(3, ECL_SYM("DECLARE",274), T6, v9);
     T8 = cl_list(3, ECL_SYM("<",72), v6variable, v11_limit);
     T9 = cl_list(2, ECL_SYM("1+",70), v6variable);
     T10 = cl_list(3, ECL_SYM("SETQ",751), v6variable, T9);
     T11 = cl_list(2, VV[1], T10);
     T12 = ecl_list1(T11);
     T13 = ecl_append(v10,T12);
     T14 = cl_listX(3, ECL_SYM("WHILE",1469), T8, T13);
     T15 = cl_listX(5, ECL_SYM("LET",477), T5, T7, T14, v5);
     T16 = cl_list(2, ECL_SYM("FIXNUM",372), T15);
     T17 = cl_list(2, v6variable, ecl_make_fixnum(0));
     T18 = ecl_list1(T17);
     T19 = CONS(ECL_SYM("DECLARE",274),v9);
     T20 = cl_list(3, ECL_SYM("<",72), v6variable, v11_limit);
     T21 = cl_list(2, ECL_SYM("1+",70), v6variable);
     T22 = cl_list(3, ECL_SYM("SETQ",751), v6variable, T21);
     T23 = ecl_list1(T22);
     T24 = ecl_append(v10,T23);
     T25 = cl_listX(3, ECL_SYM("WHILE",1469), T20, T24);
     T26 = cl_listX(5, ECL_SYM("LET",477), T18, T19, T25, v5);
     T27 = cl_list(2, ECL_T, T26);
     T28 = cl_list(4, ECL_SYM("COMPILER-TYPECASE",1780), v11_limit, T16, T27);
     T29 = cl_list(4, ECL_SYM("LET",477), T1, T3, T28);
     value0 = cl_list(3, ECL_SYM("BLOCK",137), ECL_NIL, T29);
     return value0;
    }
   }
  }
 }
}

#include "cmp/cmpopt-type.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecldQDYqh99Sxum9_4urtVE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPOPT-TYPE.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_ecldQDYqh99Sxum9_4urtVE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC1dotimes,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("DOTIMES",314), ECL_SYM("COMPILER-MACRO",238), T0);
 }
}
