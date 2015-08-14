/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPOPT-SEQUENCE.LSP                           */
#include <ecl/ecl-cmp.h>
#include "cmp/cmpopt-sequence.eclh"
/*	function definition for CONSTANT-FUNCTION-EXPRESSION          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1constant_function_expression(cl_object v1form)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_CONSP(v1form))) { goto L2; }
  {
   cl_object v2;
   v2 = ecl_car(v1form);
   if (!((v2)==(ECL_SYM("QUOTE",679)))) { goto L9; }
   value0 = VV[0];
   goto L7;
L9:;
   value0 = ECL_NIL;
   goto L7;
L7:;
   if ((value0)!=ECL_NIL) { goto L6; }
   if (!((v2)==(ECL_SYM("FUNCTION",396)))) { goto L13; }
   value0 = VV[1];
   goto L11;
L13:;
   value0 = ECL_NIL;
   goto L11;
L11:;
   if ((value0)!=ECL_NIL) { goto L6; }
   if (!((v2)==(ECL_SYM("LAMBDA",452)))) { goto L16; }
   value0 = VV[2];
   cl_env_copy->nvalues = 1;
   return value0;
L16:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L6:;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for SEQ-OPT-TEST-FUNCTION                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5seq_opt_test_function(cl_object v1test_flag, cl_object v2test)
{
 cl_object T0, T1, T2;
 cl_object env0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v2test,env0);                /*  TEST            */
  if (!(v1test_flag==ECL_NIL)) { goto L1; }
  T0 = L5seq_opt_test_function(ECL_SYM("TEST",1316), VV[4]);
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = ECL_NIL;
  cl_env_copy->values[0] = T0;
  return cl_env_copy->values[0];
L1:;
  if (!((v1test_flag)==(ECL_SYM("TEST-NOT",1317)))) { goto L3; }
  {
   cl_object v4;                                  /*  INIT            */
   volatile cl_object env1 = env0;
   value0 = L5seq_opt_test_function(ECL_SYM("TEST",1316), ECL_CONS_CAR(CLV0));
   CLV1 = env1 = CONS(value0,env1);               /*  FUNCTION        */
   {
    const int v5 = cl_env_copy->nvalues;
    cl_object v6;
    v6 = (v5<=1)? ECL_NIL : cl_env_copy->values[1];
    v4 = v6;
   }
   {cl_object v5;
    v5 = ECL_NIL;
    v5 = ecl_make_cclosure_va((cl_objectfn)LC2__g1,env1,Cblock);
    T0 = v5;
   }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v4;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
L3:;
  if (Null(L1constant_function_expression(ECL_CONS_CAR(CLV0)))) { goto L7; }
  {cl_object v3;
   v3 = ECL_NIL;
   v3 = ecl_make_cclosure_va((cl_objectfn)LC3__g2,env0,Cblock);
   T0 = v3;
  }
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = ECL_NIL;
  cl_env_copy->values[0] = T0;
  return cl_env_copy->values[0];
L7:;
  {
   cl_object env1 = env0;
   T0 = cl_gensym(1, _ecl_static_1);
   CLV1 = env1 = CONS(T0,env1);                   /*  TEST-FUNCTION   */
   {cl_object v3;
    v3 = ECL_NIL;
    v3 = ecl_make_cclosure_va((cl_objectfn)LC4__g3,env1,Cblock);
    T0 = v3;
   }
   T1 = cl_list(2, ECL_CONS_CAR(CLV1), ECL_CONS_CAR(CLV0));
   T2 = ecl_list1(T1);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = T2;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	closure G1                                                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC2__g1(cl_narg narg, cl_object v1v1, cl_object v2v2, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  FUNCTION        */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,ECL_CONS_CAR(CLV1))(2, v1v1, v2v2);
  value0 = cl_list(2, ECL_SYM("NOT",584), T0);
  return value0;
 }
 }
}
/*	closure G2                                                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC3__g2(cl_narg narg, cl_object v1v1, cl_object v2v2, ...)
{
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  TEST            */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = cl_list(4, ECL_SYM("FUNCALL",394), ECL_CONS_CAR(CLV0), v1v1, v2v2);
  return value0;
 }
 }
}
/*	closure G3                                                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC4__g3(cl_narg narg, cl_object v1v1, cl_object v2v2, ...)
{
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  TEST-FUNCTION   */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = cl_list(4, ECL_SYM("FUNCALL",394), ECL_CONS_CAR(CLV1), v1v1, v2v2);
  return value0;
 }
 }
}
/*	function definition for SEQ-OPT-KEY-FUNCTION                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8seq_opt_key_function(cl_object v1key)
{
 cl_object T0, T1, T2, T3;
 cl_object env0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1key,env0);                 /*  KEY             */
  if (!(ECL_CONS_CAR(CLV0)==ECL_NIL)) { goto L1; }
  T0 = (ECL_SYM("IDENTITY",426)->symbol.gfdef);
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = ECL_NIL;
  cl_env_copy->values[0] = T0;
  return cl_env_copy->values[0];
L1:;
  if (Null(L1constant_function_expression(ECL_CONS_CAR(CLV0)))) { goto L4; }
  {cl_object v2;
   v2 = ECL_NIL;
   v2 = ecl_make_cclosure_va((cl_objectfn)LC6__g4,env0,Cblock);
   T0 = v2;
  }
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = ECL_NIL;
  cl_env_copy->values[0] = T0;
  return cl_env_copy->values[0];
L4:;
  {
   cl_object env1 = env0;
   T0 = cl_gensym(1, _ecl_static_2);
   CLV1 = env1 = CONS(T0,env1);                   /*  KEY-FUNCTION    */
   {cl_object v2;
    v2 = ECL_NIL;
    v2 = ecl_make_cclosure_va((cl_objectfn)LC7__g5,env1,Cblock);
    T0 = v2;
   }
   T1 = cl_list(3, ECL_SYM("OR",614), ECL_CONS_CAR(CLV0), VV[6]);
   T2 = cl_list(2, ECL_CONS_CAR(CLV1), T1);
   T3 = ecl_list1(T2);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = T3;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	closure G4                                                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC6__g4(cl_narg narg, cl_object v1elt, ...)
{
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  KEY             */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = cl_list(3, ECL_SYM("FUNCALL",394), ECL_CONS_CAR(CLV0), v1elt);
  return value0;
 }
 }
}
/*	closure G5                                                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC7__g5(cl_narg narg, cl_object v1elt, ...)
{
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  KEY-FUNCTION    */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = cl_list(3, ECL_SYM("FUNCALL",394), ECL_CONS_CAR(CLV1), v1elt);
  return value0;
 }
 }
}
/*	function definition for SEQ-OPT-PARSE-ARGS                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L9seq_opt_parse_args(cl_narg narg, cl_object v1function, cl_object v2args, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3start_end;
  ecl_va_list args; ecl_va_start(args,v2args,narg,2);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L9seq_opt_parse_argskeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[1])) {
    v3start_end = ECL_T;
   } else {
    v3start_end = keyvars[0];
   }
  }
  {
   cl_object v4key_flag;
   v4key_flag = ECL_NIL;
   {
    cl_object v5key;
    v5key = ECL_NIL;
    {
     cl_object v6test;
     v6test = VV[8];
     {
      cl_object v7test_flag;
      v7test_flag = ECL_NIL;
      {
       cl_object v8start;
       v8start = ecl_make_fixnum(0);
       {
        cl_object v9end;
        v9end = ECL_NIL;
        {
         cl_object v10keyword;
         v10keyword = ECL_NIL;
L9:;
         if ((v2args)!=ECL_NIL) { goto L11; }
         goto L10;
L11:;
         if (ECL_ATOM(v2args)) { goto L16; }
         T0 = ecl_cdr(v2args);
         if (T0==ECL_NIL) { goto L16; }
         if ((v10keyword)==(ECL_SYM("ALLOW-OTHER-KEYS",1197))) { goto L16; }
         {
          cl_object v11;
          v11 = v2args;
          if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
          if (Null(v11)) { goto L24; }
          {
          cl_object v12;
          v12 = ECL_CONS_CDR(v11);
          v2args = v12;
          v11 = ECL_CONS_CAR(v11);
          }
L24:;
          v10keyword = v11;
         }
         if ((cl_keywordp(v10keyword))!=ECL_NIL) { goto L14; }
         goto L15;
L16:;
L15:;
         value0 = ECL_NIL;
         cl_env_copy->nvalues = 1;
         return value0;
L14:;
         if (!((v10keyword)==(ECL_SYM("KEY",1262)))) { goto L30; }
         if ((v4key_flag)!=ECL_NIL) { goto L13; }
         {
          cl_object v11;
          v11 = v2args;
          if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
          if (Null(v11)) { goto L38; }
          {
          cl_object v12;
          v12 = ECL_CONS_CDR(v11);
          v2args = v12;
          v11 = ECL_CONS_CAR(v11);
          }
L38:;
          v5key = v11;
         }
         v4key_flag = ECL_T;
         goto L13;
L30:;
         if ((v10keyword)==(ECL_SYM("TEST",1316))) { goto L47; }
         if (!((v10keyword)==(ECL_SYM("TEST-NOT",1317)))) { goto L45; }
         goto L46;
L47:;
L46:;
         if (!(v7test_flag==ECL_NIL)) { goto L49; }
         {
          cl_object v11;
          v11 = v2args;
          if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
          if (Null(v11)) { goto L56; }
          {
          cl_object v12;
          v12 = ECL_CONS_CDR(v11);
          v2args = v12;
          v11 = ECL_CONS_CAR(v11);
          }
L56:;
          v6test = v11;
         }
         v7test_flag = v10keyword;
         goto L13;
L49:;
         if ((v7test_flag)==(v10keyword)) { goto L13; }
         ecl_function_dispatch(cl_env_copy,VV[50])(2, _ecl_static_3, v1function) /*  CMPWARN */;
         value0 = ECL_NIL;
         cl_env_copy->nvalues = 1;
         return value0;
L45:;
         if (!((v10keyword)==(ECL_SYM("START",1310)))) { goto L65; }
         if ((v3start_end)!=ECL_NIL) { goto L67; }
         ecl_function_dispatch(cl_env_copy,VV[50])(3, _ecl_static_4, v10keyword, v1function) /*  CMPWARN */;
         value0 = ECL_NIL;
         cl_env_copy->nvalues = 1;
         return value0;
L67:;
         {
          cl_object v11;
          v11 = v2args;
          if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
          if (Null(v11)) { goto L74; }
          {
          cl_object v12;
          v12 = ECL_CONS_CDR(v11);
          v2args = v12;
          v11 = ECL_CONS_CAR(v11);
          }
L74:;
          v8start = v11;
         }
         goto L13;
L65:;
         if (!((v10keyword)==(ECL_SYM("END",1225)))) { goto L80; }
         if ((v3start_end)!=ECL_NIL) { goto L82; }
         ecl_function_dispatch(cl_env_copy,VV[50])(3, _ecl_static_4, v10keyword, v1function) /*  CMPWARN */;
         value0 = ECL_NIL;
         cl_env_copy->nvalues = 1;
         return value0;
L82:;
         {
          cl_object v11;
          v11 = v2args;
          if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
          if (Null(v11)) { goto L89; }
          {
          cl_object v12;
          v12 = ECL_CONS_CDR(v11);
          v2args = v12;
          v11 = ECL_CONS_CAR(v11);
          }
L89:;
          v9end = v11;
         }
         goto L13;
L80:;
         if (!((v10keyword)==(VV[9]))) { goto L95; }
         {
          cl_object v11;
          v11 = v2args;
          if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
          if (Null(v11)) { goto L102; }
          {
          cl_object v12;
          v12 = ECL_CONS_CDR(v11);
          v2args = v12;
          v11 = ECL_CONS_CAR(v11);
          }
L102:;
          T0 = v11;
         }
         if (T0==ECL_NIL) { goto L13; }
         value0 = ECL_NIL;
         cl_env_copy->nvalues = 1;
         return value0;
L95:;
         value0 = ECL_NIL;
         cl_env_copy->nvalues = 1;
         return value0;
L13:;
         goto L9;
L10:;
         {
          cl_object v12;                          /*  KEY-FUNCTION    */
          cl_object v13;                          /*  KEY-INIT        */
          value0 = L8seq_opt_key_function(v5key);
          v12 = value0;
          {
          const int v14 = cl_env_copy->nvalues;
          cl_object v15;
          v15 = (v14<=1)? ECL_NIL : cl_env_copy->values[1];
          v13 = v15;
          }
          {
          cl_object v15;                          /*  TEST-FUNCTION   */
          cl_object v16;                          /*  TEST-INIT       */
          value0 = L5seq_opt_test_function(v7test_flag, v6test);
          v15 = value0;
          {
          const int v17 = cl_env_copy->nvalues;
          cl_object v18;
          v18 = (v17<=1)? ECL_NIL : cl_env_copy->values[1];
          v16 = v18;
          }
          T0 = ecl_nconc(v13,v16);
          cl_env_copy->nvalues = 6;
          cl_env_copy->values[5] = v6test;
          cl_env_copy->values[4] = v7test_flag;
          cl_env_copy->values[3] = v4key_flag;
          cl_env_copy->values[2] = T0;
          cl_env_copy->values[1] = v15;
          cl_env_copy->values[0] = v12;
          return cl_env_copy->values[0];
          }
         }
         value0 = ECL_NIL;
         cl_env_copy->nvalues = 1;
         return value0;
        }
       }
      }
     }
    }
   }
  }
 }
}
/*	local function DO-IN-SEQ                                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC10do_in_seq(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6_elt;
   cl_object v7sequence;
   cl_object v8;
   cl_object v9start;
   cl_object v10;
   cl_object v11end;
   cl_object v12;
   cl_object v13output;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v14;
    v14 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4 = v14;
   }
   v5 = v4;
   if (!(v5==ECL_NIL)) { goto L10; }
   si_dm_too_few_arguments(v1);
L10:;
   {
    cl_object v14;
    v14 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v6_elt = v14;
   }
   if (!(v5==ECL_NIL)) { goto L16; }
   si_dm_too_few_arguments(v1);
L16:;
   {
    cl_object v14;
    v14 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v7sequence = v14;
   }
   v8 = si_search_keyword(2, v5, ECL_SYM("START",1310));
   if (!((v8)==(ECL_SYM("MISSING-KEYWORD",1929)))) { goto L23; }
   v9start = ecl_make_fixnum(0);
   goto L22;
L23:;
   v9start = v8;
L22:;
   v10 = si_search_keyword(2, v5, ECL_SYM("END",1225));
   if (!((v10)==(ECL_SYM("MISSING-KEYWORD",1929)))) { goto L27; }
   v11end = ECL_NIL;
   goto L26;
L27:;
   v11end = v10;
L26:;
   v12 = si_search_keyword(2, v5, ECL_SYM("OUTPUT",1282));
   if (!((v12)==(ECL_SYM("MISSING-KEYWORD",1929)))) { goto L31; }
   v13output = ECL_NIL;
   goto L30;
L31:;
   v13output = v12;
L30:;
   si_check_keyword(2, v5, VV[11]);
   {
    cl_object v14_start;
    cl_object v15_iterator;
    cl_object v16_counter;
    cl_object v17_sequence;
    v14_start = cl_gensym(1, _ecl_static_5);
    v15_iterator = cl_gensym(1, _ecl_static_6);
    v16_counter = cl_gensym(1, _ecl_static_7);
    v17_sequence = cl_gensym(1, _ecl_static_8);
    {
     cl_object v18counter;
     cl_object v19test;
     if (Null(v11end)) { goto L39; }
     T0 = cl_list(3, ECL_SYM("OR",614), v11end, ECL_SYM("MOST-POSITIVE-FIXNUM",567));
     v18counter = cl_list(3, ECL_SYM("-",17), T0, v14_start);
     goto L38;
L39:;
     v18counter = ecl_make_fixnum(0);
L38:;
     if (Null(v11end)) { goto L42; }
     T0 = cl_list(2, ECL_SYM("PLUSP",642), v16_counter);
     v19test = cl_list(3, ECL_SYM("AND",87), v15_iterator, T0);
     goto L41;
L42:;
     v19test = v15_iterator;
L41:;
     T0 = cl_list(2, v17_sequence, v7sequence);
     T1 = cl_list(2, v14_start, v9start);
     T2 = cl_list(3, VV[12], v17_sequence, v14_start);
     T3 = cl_list(2, v15_iterator, T2);
     T4 = cl_list(2, v16_counter, v18counter);
     T5 = cl_list(4, T0, T1, T3, T4);
     T6 = cl_list(4, VV[13], v17_sequence, v14_start, v16_counter);
     T7 = cl_list(2, ECL_SYM("IGNORABLE",427), v16_counter);
     T8 = cl_list(2, ECL_SYM("FIXNUM",372), v16_counter);
     T9 = cl_list(4, ECL_SYM("DECLARE",274), T6, T7, T8);
     T10 = cl_list(2, ECL_SYM("RETURN",724), v13output);
     T11 = cl_list(3, ECL_SYM("UNLESS",883), v19test, T10);
     T12 = cl_list(3, VV[14], v17_sequence, v15_iterator);
     T13 = cl_list(2, v6_elt, T12);
     T14 = ecl_list1(T13);
     T15 = cl_listX(3, ECL_SYM("LET",477), T14, v3);
     T16 = cl_list(3, VV[15], v17_sequence, v15_iterator);
     T17 = cl_list(3, ECL_SYM("SETF",750), v15_iterator, T16);
     T18 = cl_list(4, ECL_SYM("LOOP",512), T11, T15, T17);
     value0 = cl_list(4, ECL_SYM("LET*",478), T5, T9, T18);
     return value0;
    }
   }
  }
 }
}
/*	local function DO-IN-LIST                                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC11do_in_list(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6_elt;
   cl_object v7_sublist;
   cl_object v8list;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v9;
    v9 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4 = v9;
   }
   v5 = v4;
   if (!(v5==ECL_NIL)) { goto L10; }
   si_dm_too_few_arguments(v1);
L10:;
   {
    cl_object v9;
    v9 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v6_elt = v9;
   }
   if (!(v5==ECL_NIL)) { goto L16; }
   si_dm_too_few_arguments(v1);
L16:;
   {
    cl_object v9;
    v9 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v7_sublist = v9;
   }
   if (!(v5==ECL_NIL)) { goto L22; }
   si_dm_too_few_arguments(v1);
L22:;
   {
    cl_object v9;
    v9 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v8list = v9;
   }
   T0 = cl_list(2, VV[17], v7_sublist);
   T1 = cl_list(3, v7_sublist, v8list, T0);
   T2 = ecl_list1(T1);
   T3 = cl_list(2, ECL_SYM("NULL",605), v7_sublist);
   T4 = CONS(T3,v5);
   T5 = cl_list(3, VV[18], v7_sublist, ECL_SYM("CONS",251));
   T6 = cl_list(2, v7_sublist, T5);
   T7 = cl_list(2, VV[19], v7_sublist);
   T8 = cl_list(2, v6_elt, T7);
   T9 = cl_list(2, T6, T8);
   T10 = cl_listX(3, ECL_SYM("LET*",478), T9, v3);
   value0 = cl_list(4, ECL_SYM("DO*",308), T2, T4, T10);
   return value0;
  }
 }
}
/*	function definition for EXPAND-MEMBER                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L12expand_member(cl_narg narg, cl_object v1value, cl_object v2list, ...)
{
 cl_object T0, T1, T2, T3, T4, T5, T6;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3sequence_args;
  ecl_va_list args; ecl_va_start(args,v2list,narg,2);
  v3sequence_args = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v5;                                  /*  KEY-FUNCTION    */
   cl_object v6;                                  /*  TEST-FUNCTION   */
   cl_object v7;                                  /*  INIT            */
   cl_object v8;                                  /*  KEY-FLAG        */
   cl_object v9;                                  /*  TEST-FLAG       */
   cl_object v10;                                 /*  TEST            */
   value0 = L9seq_opt_parse_args(4, ECL_SYM("MEMBER",552), v3sequence_args, VV[21], ECL_NIL);
   v5 = value0;
   {
    const int v11 = cl_env_copy->nvalues;
    cl_object v12;
    v12 = (v11<=1)? ECL_NIL : cl_env_copy->values[1];
    v6 = v12;
    v12 = (v11<=2)? ECL_NIL : cl_env_copy->values[2];
    v7 = v12;
    v12 = (v11<=3)? ECL_NIL : cl_env_copy->values[3];
    v8 = v12;
    v12 = (v11<=4)? ECL_NIL : cl_env_copy->values[4];
    v9 = v12;
    v12 = (v11<=5)? ECL_NIL : cl_env_copy->values[5];
    v10 = v12;
   }
   if (!(v5==ECL_NIL)) { goto L2; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
   if ((v8)!=ECL_NIL) { goto L4; }
   if (v10==ECL_NIL) { goto L9; }
   if (Null(L1constant_function_expression(v10))) { goto L6; }
   goto L8;
L9:;
L8:;
   if (Null(ecl_function_dispatch(cl_env_copy,VV[54])(1, v2list) /*  CONSTANT-EXPRESSION-P */)) { goto L6; }
   v2list = ecl_function_dispatch(cl_env_copy,VV[55])(1, v2list) /*  CMP-EVAL */;
   {
    cl_fixnum v11;
    v11 = ecl_length(v2list);
    if (!((v11)<=(4))) { goto L11; }
   }
   {
    cl_object v11_value;
    v11_value = cl_gensym(1, _ecl_static_9);
    T0 = cl_list(2, v11_value, v1value);
    T1 = ecl_list1(T0);
    {
     cl_object v12l;
     v12l = v2list;
     {
      cl_object v13elt;
      v13elt = ECL_NIL;
      {
       cl_object v14;
       cl_object v15;
       v14 = ecl_list1(ECL_NIL);
       v15 = v14;
L20:;
       if (!(ECL_ATOM(v12l))) { goto L22; }
       goto L21;
L22:;
       v13elt = ecl_car(v12l);
       if (ecl_unlikely(ECL_ATOM(v15))) FEtype_error_cons(v15);
       T3 = v15;
       T5 = cl_list(2, ECL_SYM("QUOTE",679), v13elt);
       T4 = ecl_function_dispatch(cl_env_copy,v6)(2, v11_value, T5);
       T5 = cl_list(2, ECL_SYM("QUOTE",679), v12l);
       T6 = cl_list(3, ECL_SYM("AND",87), T4, T5);
       v15 = ecl_list1(T6);
       (ECL_CONS_CDR(T3)=v15,T3);
       v12l = _ecl_cdr(v12l);
       goto L20;
L21:;
       T2 = ecl_cdr(v14);
       goto L15;
      }
     }
    }
L15:;
    T3 = CONS(ECL_SYM("OR",614),T2);
    value0 = cl_list(3, ECL_SYM("LET",477), T1, T3);
    return value0;
   }
L11:;
   if (ECL_CONSP(v2list)) { goto L36; }
   if (Null((cl_env_copy->function=ecl_fdefinition(ECL_SYM("SYMBOL",840)))->cfun.entry(1, v2list) /*  SYMBOL */)) { goto L6; }
   goto L35;
L36:;
L35:;
   v2list = cl_list(2, ECL_SYM("QUOTE",679), v2list);
L6:;
   if (v9==ECL_NIL) { goto L40; }
   if (!((v9)==(ECL_SYM("TEST",1316)))) { goto L4; }
   goto L39;
L40:;
L39:;
   if (!(ecl_equal(v10,VV[22]))) { goto L47; }
   goto L44;
   goto L45;
L47:;
   goto L45;
L45:;
   if (!(ecl_equal(v10,VV[24]))) { goto L42; }
   goto L43;
L44:;
L43:;
   T0 = cl_list(2, v1value, v2list);
   value0 = cl_listX(3, ECL_SYM("C-INLINE",1973), T0, VV[26]);
   return value0;
L42:;
   if (!(ecl_equal(v10,VV[8]))) { goto L55; }
   goto L52;
   goto L53;
L55:;
   goto L53;
L53:;
   if (!(ecl_equal(v10,VV[4]))) { goto L50; }
   goto L51;
L52:;
L51:;
   T0 = cl_list(2, v1value, v2list);
   value0 = cl_listX(3, ECL_SYM("C-INLINE",1973), T0, VV[29]);
   return value0;
L50:;
   if (!(ecl_equal(v10,VV[30]))) { goto L62; }
   goto L59;
   goto L60;
L62:;
   goto L60;
L60:;
   if (!(ecl_equal(v10,VV[32]))) { goto L4; }
   goto L58;
L59:;
L58:;
   T0 = cl_list(2, v1value, v2list);
   value0 = cl_listX(3, ECL_SYM("C-INLINE",1973), T0, VV[34]);
   return value0;
L4:;
   {
    cl_object v11_value;
    cl_object v12_sublist;
    cl_object v13_elt;
    v11_value = cl_gensym(1, _ecl_static_9);
    v12_sublist = cl_gensym(1, _ecl_static_10);
    v13_elt = cl_gensym(1, _ecl_static_11);
    T0 = cl_list(2, v11_value, v1value);
    T1 = CONS(T0,v7);
    T2 = cl_list(3, v13_elt, v12_sublist, v2list);
    T4 = ecl_function_dispatch(cl_env_copy,v5)(1, v13_elt);
    T3 = ecl_function_dispatch(cl_env_copy,v6)(2, v11_value, T4);
    T4 = cl_list(2, ECL_SYM("RETURN",724), v12_sublist);
    T5 = cl_list(3, ECL_SYM("WHEN",905), T3, T4);
    T6 = cl_list(3, VV[20], T2, T5);
    value0 = cl_list(3, ECL_SYM("LET",477), T1, T6);
    return value0;
   }
  }
 }
}
/*	local function MEMBER                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC13member(cl_object v1, cl_object v2)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4value;
   cl_object v5list;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4value = v6;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5list = v6;
   }
   if (Null(ecl_function_dispatch(cl_env_copy,VV[56])(0) /*  POLICY-INLINE-SEQUENCE-FUNCTIONS */)) { goto L14; }
   T0 = ecl_fdefinition(VV[35]);
   T1 = ecl_cdr(v1);
   value0 = cl_apply(2, T0, T1);
   if ((value0)!=ECL_NIL) { goto L17; }
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
L17:;
   cl_env_copy->nvalues = 1;
   return value0;
L14:;
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for EXPAND-ASSOC                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L14expand_assoc(cl_narg narg, cl_object v1value, cl_object v2list, ...)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3sequence_args;
  ecl_va_list args; ecl_va_start(args,v2list,narg,2);
  v3sequence_args = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v5;                                  /*  KEY-FUNCTION    */
   cl_object v6;                                  /*  TEST-FUNCTION   */
   cl_object v7;                                  /*  INIT            */
   cl_object v8;                                  /*  KEY-FLAG        */
   cl_object v9;                                  /*  TEST-FLAG       */
   cl_object v10;                                 /*  TEST            */
   value0 = L9seq_opt_parse_args(4, ECL_SYM("ASSOC",114), v3sequence_args, VV[21], ECL_NIL);
   v5 = value0;
   {
    const int v11 = cl_env_copy->nvalues;
    cl_object v12;
    v12 = (v11<=1)? ECL_NIL : cl_env_copy->values[1];
    v6 = v12;
    v12 = (v11<=2)? ECL_NIL : cl_env_copy->values[2];
    v7 = v12;
    v12 = (v11<=3)? ECL_NIL : cl_env_copy->values[3];
    v8 = v12;
    v12 = (v11<=4)? ECL_NIL : cl_env_copy->values[4];
    v9 = v12;
    v12 = (v11<=5)? ECL_NIL : cl_env_copy->values[5];
    v10 = v12;
   }
   if ((v8)!=ECL_NIL) { goto L2; }
   if (v9==ECL_NIL) { goto L5; }
   if (!((v9)==(ECL_SYM("TEST",1316)))) { goto L2; }
   goto L4;
L5:;
L4:;
   if (!(ecl_equal(v10,VV[22]))) { goto L12; }
   goto L9;
   goto L10;
L12:;
   goto L10;
L10:;
   if (!(ecl_equal(v10,VV[24]))) { goto L7; }
   goto L8;
L9:;
L8:;
   T0 = cl_list(2, v1value, v2list);
   value0 = cl_listX(3, ECL_SYM("C-INLINE",1973), T0, VV[36]);
   return value0;
L7:;
   if (!(ecl_equal(v10,VV[8]))) { goto L20; }
   goto L17;
   goto L18;
L20:;
   goto L18;
L18:;
   if (!(ecl_equal(v10,VV[4]))) { goto L15; }
   goto L16;
L17:;
L16:;
   T0 = cl_list(2, v1value, v2list);
   value0 = cl_listX(3, ECL_SYM("C-INLINE",1973), T0, VV[37]);
   return value0;
L15:;
   if (!(ecl_equal(v10,VV[30]))) { goto L28; }
   goto L25;
   goto L26;
L28:;
   goto L26;
L26:;
   if (!(ecl_equal(v10,VV[32]))) { goto L23; }
   goto L24;
L25:;
L24:;
   T0 = cl_list(2, v1value, v2list);
   value0 = cl_listX(3, ECL_SYM("C-INLINE",1973), T0, VV[38]);
   return value0;
L23:;
   if (!(ecl_equal(v10,VV[39]))) { goto L35; }
   goto L32;
   goto L33;
L35:;
   goto L33;
L33:;
   if (!(ecl_equal(v10,VV[41]))) { goto L2; }
   goto L31;
L32:;
L31:;
   T0 = cl_list(2, v1value, v2list);
   value0 = cl_listX(3, ECL_SYM("C-INLINE",1973), T0, VV[43]);
   return value0;
L2:;
   if (Null(v6)) { goto L38; }
   {
    cl_object v11_value;
    cl_object v12_sublist;
    cl_object v13_elt;
    cl_object v14_car;
    v11_value = cl_gensym(1, _ecl_static_9);
    v12_sublist = cl_gensym(1, _ecl_static_10);
    v13_elt = cl_gensym(1, _ecl_static_11);
    v14_car = cl_gensym(1, _ecl_static_12);
    T0 = cl_list(2, v11_value, v1value);
    T1 = CONS(T0,v7);
    T2 = cl_list(3, v13_elt, v12_sublist, v2list);
    T3 = cl_list(3, VV[18], v13_elt, ECL_SYM("CONS",251));
    T4 = cl_list(2, VV[19], T3);
    T5 = cl_list(2, v14_car, T4);
    T6 = ecl_list1(T5);
    T8 = ecl_function_dispatch(cl_env_copy,v5)(1, v14_car);
    T7 = ecl_function_dispatch(cl_env_copy,v6)(2, v11_value, T8);
    T8 = cl_list(2, ECL_SYM("RETURN",724), v13_elt);
    T9 = cl_list(3, ECL_SYM("WHEN",905), T7, T8);
    T10 = cl_list(3, ECL_SYM("LET",477), T6, T9);
    T11 = cl_list(3, ECL_SYM("WHEN",905), v13_elt, T10);
    T12 = cl_list(3, VV[20], T2, T11);
    value0 = cl_list(3, ECL_SYM("LET",477), T1, T12);
    return value0;
   }
L38:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function ASSOC                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC15assoc(cl_object v1, cl_object v2)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4value;
   cl_object v5list;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4value = v6;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5list = v6;
   }
   if (Null(ecl_function_dispatch(cl_env_copy,VV[56])(0) /*  POLICY-INLINE-SEQUENCE-FUNCTIONS */)) { goto L14; }
   T0 = ecl_fdefinition(VV[44]);
   T1 = ecl_cdr(v1);
   value0 = cl_apply(2, T0, T1);
   if ((value0)!=ECL_NIL) { goto L17; }
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
L17:;
   cl_env_copy->nvalues = 1;
   return value0;
L14:;
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for EXPAND-FIND                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L16expand_find(cl_narg narg, cl_object v1value, cl_object v2sequence, ...)
{
 cl_object T0, T1, T2, T3, T4, T5, T6;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3sequence_args;
  ecl_va_list args; ecl_va_start(args,v2sequence,narg,2);
  v3sequence_args = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v5;                                  /*  KEY-FUNCTION    */
   cl_object v6;                                  /*  TEST-FUNCTION   */
   cl_object v7;                                  /*  INIT            */
   value0 = L9seq_opt_parse_args(2, ECL_SYM("FIND",363), v3sequence_args);
   v5 = value0;
   {
    const int v8 = cl_env_copy->nvalues;
    cl_object v9;
    v9 = (v8<=1)? ECL_NIL : cl_env_copy->values[1];
    v6 = v9;
    v9 = (v8<=2)? ECL_NIL : cl_env_copy->values[2];
    v7 = v9;
   }
   if (Null(v6)) { goto L2; }
   {
    cl_object v8_value;
    cl_object v9_elt;
    v8_value = cl_gensym(1, _ecl_static_9);
    v9_elt = cl_gensym(1, _ecl_static_11);
    T0 = cl_list(2, v8_value, v1value);
    T1 = CONS(T0,v7);
    T2 = cl_list(2, v9_elt, v2sequence);
    T4 = ecl_function_dispatch(cl_env_copy,v5)(1, v9_elt);
    T3 = ecl_function_dispatch(cl_env_copy,v6)(2, v8_value, T4);
    T4 = cl_list(2, ECL_SYM("RETURN",724), v9_elt);
    T5 = cl_list(3, ECL_SYM("WHEN",905), T3, T4);
    T6 = cl_list(3, VV[16], T2, T5);
    value0 = cl_list(3, ECL_SYM("LET",477), T1, T6);
    return value0;
   }
L2:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function FIND                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC17find(cl_object v1, cl_object v2)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4value;
   cl_object v5sequence;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4value = v6;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5sequence = v6;
   }
   if (Null(ecl_function_dispatch(cl_env_copy,VV[56])(0) /*  POLICY-INLINE-SEQUENCE-FUNCTIONS */)) { goto L14; }
   T0 = ecl_fdefinition(VV[45]);
   T1 = ecl_cdr(v1);
   value0 = cl_apply(2, T0, T1);
   if ((value0)!=ECL_NIL) { goto L17; }
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
L17:;
   cl_env_copy->nvalues = 1;
   return value0;
L14:;
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}

#include "cmp/cmpopt-sequence.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclKHE50dZOlSHj9_iqrtVE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPOPT-SEQUENCE.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclKHE50dZOlSHj9_iqrtVE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[46]);                           /*  CONSTANT-FUNCTION-EXPRESSION */
 ecl_cmp_defun(VV[47]);                           /*  SEQ-OPT-TEST-FUNCTION */
 ecl_cmp_defun(VV[48]);                           /*  SEQ-OPT-KEY-FUNCTION */
 ecl_cmp_defun(VV[49]);                           /*  SEQ-OPT-PARSE-ARGS */
 ecl_cmp_defmacro(VV[51]);                        /*  DO-IN-SEQ       */
 ecl_cmp_defmacro(VV[52]);                        /*  DO-IN-LIST      */
 ecl_cmp_defun(VV[53]);                           /*  EXPAND-MEMBER   */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC13member,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("MEMBER",552), ECL_SYM("COMPILER-MACRO",238), T0);
 }
 ecl_cmp_defun(VV[57]);                           /*  EXPAND-ASSOC    */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC15assoc,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("ASSOC",114), ECL_SYM("COMPILER-MACRO",238), T0);
 }
 ecl_cmp_defun(VV[58]);                           /*  EXPAND-FIND     */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC17find,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("FIND",363), ECL_SYM("COMPILER-MACRO",238), T0);
 }
}
