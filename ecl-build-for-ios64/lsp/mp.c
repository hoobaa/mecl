/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:LSP;MP.LSP                                        */
#include <ecl/ecl-cmp.h>
#include "lsp/mp.eclh"
/*	local function WITHOUT-INTERRUPTS                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC1without_interrupts(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_cdr(v1);
   {
    cl_object v4outer_allow_with_interrupts;
    cl_object v5outer_interrupts_enabled;
    v4outer_allow_with_interrupts = cl_gensym(1, _ecl_static_1);
    v5outer_interrupts_enabled = cl_gensym(1, _ecl_static_2);
    T0 = cl_list(2, ECL_SYM("QUOTE",679), v4outer_allow_with_interrupts);
    T1 = cl_list(3, ECL_SYM("LIST",481), VV[2], T0);
    T2 = cl_list(2, ECL_SYM("LIST",481), T1);
    T3 = cl_list(4, ECL_SYM("LIST*",482), VV[1], T2, VV[3]);
    T4 = cl_list(3, ECL_SYM("ALLOW-WITH-INTERRUPTS",1736), VV[0], T3);
    T5 = cl_list(2, ECL_SYM("QUOTE",679), v5outer_interrupts_enabled);
    T6 = cl_list(3, ECL_SYM("LIST",481), VV[6], T5);
    T7 = cl_list(2, ECL_SYM("LIST",481), T6);
    T8 = cl_list(4, ECL_SYM("LIST*",482), VV[1], T7, VV[7]);
    T9 = cl_list(3, VV[4], VV[5], T8);
    T10 = cl_list(2, ECL_SYM("QUOTE",679), v4outer_allow_with_interrupts);
    T11 = cl_list(3, ECL_SYM("LIST",481), VV[2], T10);
    T12 = cl_list(2, ECL_SYM("QUOTE",679), v4outer_allow_with_interrupts);
    T13 = cl_list(3, ECL_SYM("LIST",481), VV[6], T12);
    T14 = cl_list(3, ECL_SYM("LIST",481), T11, T13);
    T15 = cl_list(2, ECL_SYM("QUOTE",679), v4outer_allow_with_interrupts);
    T16 = cl_list(4, ECL_SYM("LIST",481), VV[9], T15, VV[10]);
    T17 = cl_list(5, ECL_SYM("LIST",481), VV[8], T14, T16, VV[11]);
    T18 = cl_list(3, ECL_SYM("WITH-LOCAL-INTERRUPTS",1735), VV[5], T17);
    T19 = cl_list(3, T4, T9, T18);
    T20 = cl_list(2, v5outer_interrupts_enabled, ECL_SYM("*INTERRUPTS-ENABLED*",1023));
    T21 = cl_list(2, v4outer_allow_with_interrupts, ECL_SYM("*ALLOW-WITH-INTERRUPTS*",1730));
    T22 = cl_list(4, T20, VV[12], T21, VV[13]);
    T23 = cl_list(3, ECL_SYM("IGNORABLE",427), v4outer_allow_with_interrupts, v5outer_interrupts_enabled);
    T24 = cl_list(2, ECL_SYM("DECLARE",274), T23);
    T25 = cl_listX(4, ECL_SYM("LET*",478), T22, T24, v3);
    T26 = cl_list(3, ECL_SYM("MACROLET",521), T19, T25);
    value0 = cl_list(3, ECL_SYM("MULTIPLE-VALUE-PROG1",575), T26, VV[14]);
    return value0;
   }
  }
 }
}
/*	local function WITH-INTERRUPTS                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC2with_interrupts(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_cdr(v1);
   {
    cl_object v4allowp;
    cl_object v5enablep;
    v4allowp = cl_gensym(1, _ecl_static_3);
    v5enablep = cl_gensym(1, _ecl_static_4);
    T0 = cl_list(2, v4allowp, ECL_SYM("*ALLOW-WITH-INTERRUPTS*",1730));
    T1 = cl_list(2, v5enablep, ECL_SYM("*INTERRUPTS-ENABLED*",1023));
    T2 = cl_list(3, ECL_SYM("OR",614), v5enablep, v4allowp);
    T3 = cl_list(2, ECL_SYM("*INTERRUPTS-ENABLED*",1023), T2);
    T4 = cl_list(3, T0, T1, T3);
    T5 = cl_list(2, ECL_SYM("NOT",584), v5enablep);
    T6 = cl_list(3, ECL_SYM("AND",87), v4allowp, T5);
    T7 = cl_list(3, ECL_SYM("WHEN",905), T6, VV[16]);
    T8 = CONS(ECL_SYM("LOCALLY",490),v3);
    value0 = cl_list(4, ECL_SYM("LET*",478), T4, T7, T8);
    return value0;
   }
  }
 }
}
/*	local function WITH-LOCK                                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC3with_lock(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6lock_form;
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
    v6lock_form = v7;
   }
   {
    cl_object v7lock;
    cl_object v8owner;
    cl_object v9count;
    v7lock = cl_gensym(1, _ecl_static_5);
    v8owner = cl_gensym(1, _ecl_static_6);
    v9count = cl_gensym(1, _ecl_static_7);
    T0 = cl_list(2, v7lock, v6lock_form);
    T1 = cl_list(2, ECL_SYM("LOCK-OWNER",1415), v7lock);
    T2 = cl_list(2, v8owner, T1);
    T3 = cl_list(2, ECL_SYM("LOCK-COUNT",1416), v7lock);
    T4 = cl_list(2, v9count, T3);
    T5 = cl_list(3, T0, T2, T4);
    T6 = cl_list(2, ECL_SYM("GET-LOCK",1417), v7lock);
    T7 = CONS(ECL_SYM("LOCALLY",490),v3);
    T8 = cl_list(3, VV[4], T6, T7);
    T9 = cl_list(2, ECL_SYM("LOCK-OWNER",1415), v7lock);
    T10 = cl_list(3, ECL_SYM("EQ",333), ECL_SYM("*CURRENT-PROCESS*",1398), T9);
    T11 = cl_list(3, ECL_SYM("EQ",333), v8owner, ECL_SYM("*CURRENT-PROCESS*",1398));
    T12 = cl_list(2, ECL_SYM("NOT",584), T11);
    T13 = cl_list(2, ECL_SYM("LOCK-COUNT",1416), v7lock);
    T14 = cl_list(3, ECL_SYM(">",75), T13, v9count);
    T15 = cl_list(3, ECL_SYM("OR",614), T12, T14);
    T16 = cl_list(3, ECL_SYM("AND",87), T10, T15);
    T17 = cl_list(2, ECL_SYM("GIVEUP-LOCK",1418), v7lock);
    T18 = cl_list(3, ECL_SYM("WHEN",905), T16, T17);
    T19 = cl_list(3, ECL_SYM("UNWIND-PROTECT",888), T8, T18);
    T20 = cl_list(2, VV[15], T19);
    value0 = cl_list(3, ECL_SYM("LET*",478), T5, T20);
    return value0;
   }
  }
 }
}

#include "lsp/mp.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclJejZo6rSrTpp9_zMy9ZE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:LSP;MP.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclJejZo6rSrTpp9_zMy9ZE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defmacro(VV[19]);                        /*  WITHOUT-INTERRUPTS */
 ecl_cmp_defmacro(VV[20]);                        /*  WITH-INTERRUPTS */
 ecl_cmp_defmacro(VV[21]);                        /*  WITH-LOCK       */
}
