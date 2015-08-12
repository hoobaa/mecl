/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:LSP;LISTLIB.LSP                                   */
#include <ecl/ecl-cmp.h>
#include "lsp/listlib.eclh"
/*	function definition for UNION                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_union(cl_narg narg, cl_object v1list1, cl_object v2list2, ...)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3test;
  cl_object v4test_not;
  cl_object v5key;
  ecl_va_list args; ecl_va_start(args,v2list2,narg,2);
  {
   cl_object keyvars[6];
   cl_parse_key(args,3,cl_unionkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3test = keyvars[0];
   v4test_not = keyvars[1];
   v5key = keyvars[2];
  }
  {
   cl_object v6x;
   cl_object v7first;
   cl_object v8last;
   v6x = v1list1;
   v7first = ECL_NIL;
   v8last = ECL_NIL;
   goto L6;
L5:;
   T0 = ecl_car(v6x);
   if ((si_member1(T0, v2list2, v3test, v4test_not, v5key))!=ECL_NIL) { goto L8; }
   if (Null(v8last)) { goto L10; }
   if (ecl_unlikely(ECL_ATOM(v8last))) FEtype_error_cons(v8last);
   T0 = v8last;
   T1 = ecl_car(v6x);
   T2 = CONS(T1,ECL_NIL);
   (ECL_CONS_CDR(T0)=T2,T0);
   v8last = ecl_cdr(v8last);
   goto L8;
L10:;
   T0 = ecl_car(v6x);
   v7first = CONS(T0,ECL_NIL);
   v8last = v7first;
L8:;
   v6x = ecl_cdr(v6x);
L6:;
   if (v6x==ECL_NIL) { goto L21; }
   goto L5;
L21:;
   if (Null(v8last)) { goto L23; }
   if (ecl_unlikely(ECL_ATOM(v8last))) FEtype_error_cons(v8last);
   T0 = v8last;
   (ECL_CONS_CDR(T0)=v2list2,T0);
L23:;
   value0 = v7first;
   if ((value0)!=ECL_NIL) { goto L28; }
   value0 = v2list2;
   cl_env_copy->nvalues = 1;
   return value0;
L28:;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for NUNION                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_nunion(cl_narg narg, cl_object v1list1, cl_object v2list2, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3test;
  cl_object v4test_not;
  cl_object v5key;
  ecl_va_list args; ecl_va_start(args,v2list2,narg,2);
  {
   cl_object keyvars[6];
   cl_parse_key(args,3,cl_nunionkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3test = keyvars[0];
   v4test_not = keyvars[1];
   v5key = keyvars[2];
  }
  {
   cl_object v6x;
   cl_object v7first;
   cl_object v8last;
   v6x = v1list1;
   v7first = ECL_NIL;
   v8last = ECL_NIL;
   goto L6;
L5:;
   T0 = ecl_car(v6x);
   if ((si_member1(T0, v2list2, v3test, v4test_not, v5key))!=ECL_NIL) { goto L8; }
   if (Null(v8last)) { goto L11; }
   if (ecl_unlikely(ECL_ATOM(v8last))) FEtype_error_cons(v8last);
   T0 = v8last;
   (ECL_CONS_CDR(T0)=v6x,T0);
   goto L10;
L11:;
   v7first = v6x;
L10:;
   v8last = v6x;
L8:;
   v6x = ecl_cdr(v6x);
L6:;
   if (v6x==ECL_NIL) { goto L19; }
   goto L5;
L19:;
   if (Null(v8last)) { goto L21; }
   if (ecl_unlikely(ECL_ATOM(v8last))) FEtype_error_cons(v8last);
   T0 = v8last;
   (ECL_CONS_CDR(T0)=v2list2,T0);
L21:;
   value0 = v7first;
   if ((value0)!=ECL_NIL) { goto L26; }
   value0 = v2list2;
   cl_env_copy->nvalues = 1;
   return value0;
L26:;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for INTERSECTION                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_intersection(cl_narg narg, cl_object v1list1, cl_object v2list2, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3test;
  cl_object v4test_not;
  cl_object v5key;
  ecl_va_list args; ecl_va_start(args,v2list2,narg,2);
  {
   cl_object keyvars[6];
   cl_parse_key(args,3,cl_intersectionkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3test = keyvars[0];
   v4test_not = keyvars[1];
   v5key = keyvars[2];
  }
  {
   cl_object v6x;
   cl_object v7ans;
   v6x = v1list1;
   v7ans = ECL_NIL;
   goto L5;
L4:;
   T0 = ecl_car(v6x);
   if (Null(si_member1(T0, v2list2, v3test, v4test_not, v5key))) { goto L7; }
   T0 = ecl_car(v6x);
   v7ans = CONS(T0,v7ans);
L7:;
   v6x = ecl_cdr(v6x);
L5:;
   if (v6x==ECL_NIL) { goto L12; }
   goto L4;
L12:;
   value0 = cl_nreverse(v7ans);
   return value0;
  }
 }
}
/*	function definition for NINTERSECTION                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_nintersection(cl_narg narg, cl_object v1list1, cl_object v2list2, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3test;
  cl_object v4test_not;
  cl_object v5key;
  ecl_va_list args; ecl_va_start(args,v2list2,narg,2);
  {
   cl_object keyvars[6];
   cl_parse_key(args,3,cl_nintersectionkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3test = keyvars[0];
   v4test_not = keyvars[1];
   v5key = keyvars[2];
  }
  {
   cl_object v6x;
   cl_object v7first;
   cl_object v8last;
   v6x = v1list1;
   v7first = ECL_NIL;
   v8last = ECL_NIL;
   goto L6;
L5:;
   T0 = ecl_car(v6x);
   if (Null(si_member1(T0, v2list2, v3test, v4test_not, v5key))) { goto L8; }
   if (Null(v8last)) { goto L11; }
   if (ecl_unlikely(ECL_ATOM(v8last))) FEtype_error_cons(v8last);
   T0 = v8last;
   (ECL_CONS_CDR(T0)=v6x,T0);
   goto L10;
L11:;
   v7first = v6x;
L10:;
   v8last = v6x;
L8:;
   v6x = ecl_cdr(v6x);
L6:;
   if (v6x==ECL_NIL) { goto L19; }
   goto L5;
L19:;
   if (Null(v8last)) { goto L21; }
   if (ecl_unlikely(ECL_ATOM(v8last))) FEtype_error_cons(v8last);
   T0 = v8last;
   (ECL_CONS_CDR(T0)=ECL_NIL,T0);
L21:;
   value0 = v7first;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for SET-DIFFERENCE                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_set_difference(cl_narg narg, cl_object v1list1, cl_object v2list2, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3test;
  cl_object v4test_not;
  cl_object v5key;
  ecl_va_list args; ecl_va_start(args,v2list2,narg,2);
  {
   cl_object keyvars[6];
   cl_parse_key(args,3,cl_set_differencekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3test = keyvars[0];
   v4test_not = keyvars[1];
   v5key = keyvars[2];
  }
  {
   cl_object v6x;
   cl_object v7ans;
   v6x = v1list1;
   v7ans = ECL_NIL;
   goto L5;
L4:;
   T0 = ecl_car(v6x);
   if ((si_member1(T0, v2list2, v3test, v4test_not, v5key))!=ECL_NIL) { goto L7; }
   T0 = ecl_car(v6x);
   v7ans = CONS(T0,v7ans);
L7:;
   v6x = ecl_cdr(v6x);
L5:;
   if (v6x==ECL_NIL) { goto L12; }
   goto L4;
L12:;
   value0 = cl_nreverse(v7ans);
   return value0;
  }
 }
}
/*	function definition for NSET-DIFFERENCE                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_nset_difference(cl_narg narg, cl_object v1list1, cl_object v2list2, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3test;
  cl_object v4test_not;
  cl_object v5key;
  ecl_va_list args; ecl_va_start(args,v2list2,narg,2);
  {
   cl_object keyvars[6];
   cl_parse_key(args,3,cl_nset_differencekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3test = keyvars[0];
   v4test_not = keyvars[1];
   v5key = keyvars[2];
  }
  {
   cl_object v6x;
   cl_object v7first;
   cl_object v8last;
   v6x = v1list1;
   v7first = ECL_NIL;
   v8last = ECL_NIL;
   goto L6;
L5:;
   T0 = ecl_car(v6x);
   if ((si_member1(T0, v2list2, v3test, v4test_not, v5key))!=ECL_NIL) { goto L8; }
   if (Null(v8last)) { goto L11; }
   if (ecl_unlikely(ECL_ATOM(v8last))) FEtype_error_cons(v8last);
   T0 = v8last;
   (ECL_CONS_CDR(T0)=v6x,T0);
   goto L10;
L11:;
   v7first = v6x;
L10:;
   v8last = v6x;
L8:;
   v6x = ecl_cdr(v6x);
L6:;
   if (v6x==ECL_NIL) { goto L19; }
   goto L5;
L19:;
   if (Null(v8last)) { goto L21; }
   if (ecl_unlikely(ECL_ATOM(v8last))) FEtype_error_cons(v8last);
   T0 = v8last;
   (ECL_CONS_CDR(T0)=ECL_NIL,T0);
L21:;
   value0 = v7first;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for SWAP-ARGS                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2swap_args(cl_object v1f)
{
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1f,env0);                   /*  F               */
  if (Null(ECL_CONS_CAR(CLV0))) { goto L2; }
  {cl_object v2;
   v2 = ECL_NIL;
   v2 = ecl_make_cclosure_va((cl_objectfn)LC1__g30,env0,Cblock);
   value0 = v2;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	closure G30                                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC1__g30(cl_narg narg, cl_object v1x, cl_object v2y, ...)
{
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  F               */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,ECL_CONS_CAR(CLV0))(2, v2y, v1x);
  return value0;
 }
 }
}
/*	function definition for SET-EXCLUSIVE-OR                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_set_exclusive_or(cl_narg narg, cl_object v1list1, cl_object v2list2, ...)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3test;
  cl_object v4test_not;
  cl_object v5key;
  ecl_va_list args; ecl_va_start(args,v2list2,narg,2);
  {
   cl_object keyvars[6];
   cl_parse_key(args,3,cl_set_exclusive_orkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3test = keyvars[0];
   v4test_not = keyvars[1];
   v5key = keyvars[2];
  }
  T0 = cl_set_difference(8, v1list1, v2list2, ECL_SYM("TEST",1316), v3test, ECL_SYM("TEST-NOT",1317), v4test_not, ECL_SYM("KEY",1262), v5key);
  T1 = L2swap_args(v3test);
  T2 = L2swap_args(v4test_not);
  T3 = cl_set_difference(8, v2list2, v1list1, ECL_SYM("TEST",1316), T1, ECL_SYM("TEST-NOT",1317), T2, ECL_SYM("KEY",1262), v5key);
  value0 = ecl_nconc(T0,T3);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for NSET-EXCLUSIVE-OR                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_nset_exclusive_or(cl_narg narg, cl_object v1list1, cl_object v2list2, ...)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3test;
  cl_object v4test_not;
  cl_object v5key;
  ecl_va_list args; ecl_va_start(args,v2list2,narg,2);
  {
   cl_object keyvars[6];
   cl_parse_key(args,3,cl_nset_exclusive_orkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3test = keyvars[0];
   v4test_not = keyvars[1];
   v5key = keyvars[2];
  }
  T0 = cl_set_difference(8, v1list1, v2list2, ECL_SYM("TEST",1316), v3test, ECL_SYM("TEST-NOT",1317), v4test_not, ECL_SYM("KEY",1262), v5key);
  T1 = L2swap_args(v3test);
  T2 = L2swap_args(v4test_not);
  T3 = cl_nset_difference(8, v2list2, v1list1, ECL_SYM("TEST",1316), T1, ECL_SYM("TEST-NOT",1317), T2, ECL_SYM("KEY",1262), v5key);
  value0 = ecl_nconc(T0,T3);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for SUBSETP                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_subsetp(cl_narg narg, cl_object v1list1, cl_object v2list2, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3test;
  cl_object v4test_not;
  cl_object v5key;
  ecl_va_list args; ecl_va_start(args,v2list2,narg,2);
  {
   cl_object keyvars[6];
   cl_parse_key(args,3,cl_subsetpkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3test = keyvars[0];
   v4test_not = keyvars[1];
   v5key = keyvars[2];
  }
  {
   cl_object v6l;
   v6l = v1list1;
   goto L4;
L3:;
   T0 = ecl_car(v6l);
   if ((si_member1(T0, v2list2, v3test, v4test_not, v5key))!=ECL_NIL) { goto L6; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L6:;
   v6l = ecl_cdr(v6l);
L4:;
   if (v6l==ECL_NIL) { goto L10; }
   goto L3;
L10:;
   value0 = ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for RASSOC-IF                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_rassoc_if(cl_narg narg, cl_object v1test, cl_object v2alist, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3key;
  ecl_va_list args; ecl_va_start(args,v2alist,narg,2);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,cl_rassoc_ifkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3key = keyvars[0];
  }
  T0 = (ECL_SYM("FUNCALL",394)->symbol.gfdef);
  value0 = cl_rassoc(6, v1test, v2alist, ECL_SYM("TEST",1316), T0, ECL_SYM("KEY",1262), v3key);
  return value0;
 }
}
/*	function definition for RASSOC-IF-NOT                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_rassoc_if_not(cl_narg narg, cl_object v1test, cl_object v2alist, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3key;
  ecl_va_list args; ecl_va_start(args,v2alist,narg,2);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,cl_rassoc_if_notkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3key = keyvars[0];
  }
  T0 = (ECL_SYM("FUNCALL",394)->symbol.gfdef);
  value0 = cl_rassoc(6, v1test, v2alist, ECL_SYM("TEST-NOT",1317), T0, ECL_SYM("KEY",1262), v3key);
  return value0;
 }
}
/*	function definition for ASSOC-IF                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_assoc_if(cl_narg narg, cl_object v1test, cl_object v2alist, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3key;
  ecl_va_list args; ecl_va_start(args,v2alist,narg,2);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,cl_assoc_ifkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3key = keyvars[0];
  }
  {
   cl_object v4;
   value0 = v3key;
   if ((value0)!=ECL_NIL) { goto L3; }
   v4 = (ECL_SYM("IDENTITY",426)->symbol.gfdef);
   goto L1;
L3:;
   v4 = value0;
   goto L1;
L1:;
   {
    cl_object v5;
    v5 = v2alist;
    goto L8;
L7:;
    {
     cl_object v6;
     cl_object v7;
     if (ecl_unlikely(ECL_ATOM(v5))) FEtype_error_cons(v5);
     v6 = v5;
     v7 = ECL_CONS_CAR(v6);
     if (Null(v7)) { goto L10; }
     {
      cl_object v8;
      if (ecl_unlikely(ECL_ATOM(v7))) FEtype_error_cons(v7);
      T0 = v7;
      v8 = ECL_CONS_CAR(T0);
      T0 = ecl_function_dispatch(cl_env_copy,v4)(1, v8);
      if (Null(cl_funcall(2, v1test, T0))) { goto L10; }
      value0 = v7;
      cl_env_copy->nvalues = 1;
      return value0;
     }
    }
L10:;
    v5 = ECL_CONS_CDR(v5);
L8:;
    if (v5==ECL_NIL) { goto L22; }
    goto L7;
L22:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for ASSOC-IF-NOT                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_assoc_if_not(cl_narg narg, cl_object v1test, cl_object v2alist, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3key;
  ecl_va_list args; ecl_va_start(args,v2alist,narg,2);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,cl_assoc_if_notkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3key = keyvars[0];
  }
  {
   cl_object v4;
   value0 = v3key;
   if ((value0)!=ECL_NIL) { goto L3; }
   v4 = (ECL_SYM("IDENTITY",426)->symbol.gfdef);
   goto L1;
L3:;
   v4 = value0;
   goto L1;
L1:;
   {
    cl_object v5;
    v5 = v2alist;
    goto L8;
L7:;
    {
     cl_object v6;
     cl_object v7;
     if (ecl_unlikely(ECL_ATOM(v5))) FEtype_error_cons(v5);
     v6 = v5;
     v7 = ECL_CONS_CAR(v6);
     if (Null(v7)) { goto L10; }
     {
      cl_object v8;
      if (ecl_unlikely(ECL_ATOM(v7))) FEtype_error_cons(v7);
      T0 = v7;
      v8 = ECL_CONS_CAR(T0);
      T0 = ecl_function_dispatch(cl_env_copy,v4)(1, v8);
      if ((cl_funcall(2, v1test, T0))!=ECL_NIL) { goto L10; }
      value0 = v7;
      cl_env_copy->nvalues = 1;
      return value0;
     }
    }
L10:;
    v5 = ECL_CONS_CDR(v5);
L8:;
    if (v5==ECL_NIL) { goto L22; }
    goto L7;
L22:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for MEMBER-IF                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_member_if(cl_narg narg, cl_object v1test, cl_object v2list, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3key;
  ecl_va_list args; ecl_va_start(args,v2list,narg,2);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,cl_member_ifkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3key = keyvars[0];
  }
  {
   cl_object v4;
   value0 = v3key;
   if ((value0)!=ECL_NIL) { goto L3; }
   v4 = (ECL_SYM("IDENTITY",426)->symbol.gfdef);
   goto L1;
L3:;
   v4 = value0;
   goto L1;
L1:;
   {
    cl_object v5;
    v5 = v2list;
    goto L8;
L7:;
    {
     cl_object v6;
     cl_object v7;
     if (ecl_unlikely(ECL_ATOM(v5))) FEtype_error_cons(v5);
     v6 = v5;
     v7 = ECL_CONS_CAR(v6);
     T0 = ecl_function_dispatch(cl_env_copy,v4)(1, v7);
     if (Null(cl_funcall(2, v1test, T0))) { goto L10; }
     value0 = v6;
     cl_env_copy->nvalues = 1;
     return value0;
    }
L10:;
    v5 = ECL_CONS_CDR(v5);
L8:;
    if (v5==ECL_NIL) { goto L18; }
    goto L7;
L18:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for MEMBER-IF-NOT                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_member_if_not(cl_narg narg, cl_object v1test, cl_object v2list, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3key;
  ecl_va_list args; ecl_va_start(args,v2list,narg,2);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,cl_member_if_notkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3key = keyvars[0];
  }
  {
   cl_object v4;
   value0 = v3key;
   if ((value0)!=ECL_NIL) { goto L3; }
   v4 = (ECL_SYM("IDENTITY",426)->symbol.gfdef);
   goto L1;
L3:;
   v4 = value0;
   goto L1;
L1:;
   {
    cl_object v5;
    v5 = v2list;
    goto L8;
L7:;
    {
     cl_object v6;
     cl_object v7;
     if (ecl_unlikely(ECL_ATOM(v5))) FEtype_error_cons(v5);
     v6 = v5;
     v7 = ECL_CONS_CAR(v6);
     T0 = ecl_function_dispatch(cl_env_copy,v4)(1, v7);
     if ((cl_funcall(2, v1test, T0))!=ECL_NIL) { goto L10; }
     value0 = v6;
     cl_env_copy->nvalues = 1;
     return value0;
    }
L10:;
    v5 = ECL_CONS_CDR(v5);
L8:;
    if (v5==ECL_NIL) { goto L18; }
    goto L7;
L18:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for SUBST-IF                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_subst_if(cl_narg narg, cl_object v1new, cl_object v2test, cl_object v3tree, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 {
  cl_object v4key;
  ecl_va_list args; ecl_va_start(args,v3tree,narg,3);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,cl_subst_ifkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v4key = keyvars[0];
  }
  T0 = (ECL_SYM("FUNCALL",394)->symbol.gfdef);
  value0 = cl_subst(7, v1new, v2test, v3tree, ECL_SYM("TEST",1316), T0, ECL_SYM("KEY",1262), v4key);
  return value0;
 }
}
/*	function definition for SUBST-IF-NOT                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_subst_if_not(cl_narg narg, cl_object v1new, cl_object v2test, cl_object v3tree, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 {
  cl_object v4key;
  ecl_va_list args; ecl_va_start(args,v3tree,narg,3);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,cl_subst_if_notkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v4key = keyvars[0];
  }
  T0 = (ECL_SYM("FUNCALL",394)->symbol.gfdef);
  value0 = cl_subst(7, v1new, v2test, v3tree, ECL_SYM("TEST-NOT",1317), T0, ECL_SYM("KEY",1262), v4key);
  return value0;
 }
}
/*	function definition for NSUBST-IF                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_nsubst_if(cl_narg narg, cl_object v1new, cl_object v2test, cl_object v3tree, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 {
  cl_object v4key;
  ecl_va_list args; ecl_va_start(args,v3tree,narg,3);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,cl_nsubst_ifkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v4key = keyvars[0];
  }
  T0 = (ECL_SYM("FUNCALL",394)->symbol.gfdef);
  value0 = cl_nsubst(7, v1new, v2test, v3tree, ECL_SYM("TEST",1316), T0, ECL_SYM("KEY",1262), v4key);
  return value0;
 }
}
/*	function definition for NSUBST-IF-NOT                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_nsubst_if_not(cl_narg narg, cl_object v1new, cl_object v2test, cl_object v3tree, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 {
  cl_object v4key;
  ecl_va_list args; ecl_va_start(args,v3tree,narg,3);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,cl_nsubst_if_notkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v4key = keyvars[0];
  }
  T0 = (ECL_SYM("FUNCALL",394)->symbol.gfdef);
  value0 = cl_nsubst(7, v1new, v2test, v3tree, ECL_SYM("TEST-NOT",1317), T0, ECL_SYM("KEY",1262), v4key);
  return value0;
 }
}

#include "lsp/listlib.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclSa39XwDgm5oh9_rmqTOE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:LSP;LISTLIB.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclSa39XwDgm5oh9_rmqTOE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 (void)0; /* No entry created for UNION */
 (void)0; /* No entry created for NUNION */
 (void)0; /* No entry created for INTERSECTION */
 (void)0; /* No entry created for NINTERSECTION */
 (void)0; /* No entry created for SET-DIFFERENCE */
 (void)0; /* No entry created for NSET-DIFFERENCE */
 (void)0; /* No entry created for SWAP-ARGS */
 (void)0; /* No entry created for SET-EXCLUSIVE-OR */
 (void)0; /* No entry created for NSET-EXCLUSIVE-OR */
 (void)0; /* No entry created for SUBSETP */
 (void)0; /* No entry created for RASSOC-IF */
 (void)0; /* No entry created for RASSOC-IF-NOT */
 (void)0; /* No entry created for ASSOC-IF */
 (void)0; /* No entry created for ASSOC-IF-NOT */
 (void)0; /* No entry created for MEMBER-IF */
 (void)0; /* No entry created for MEMBER-IF-NOT */
 (void)0; /* No entry created for SUBST-IF */
 (void)0; /* No entry created for SUBST-IF-NOT */
 (void)0; /* No entry created for NSUBST-IF */
 (void)0; /* No entry created for NSUBST-IF-NOT */
}
