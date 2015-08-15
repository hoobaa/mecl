/*	Compiler: ECL 12.12.1                                         */
/*	Source: EXT:RT;RT.LISP                                        */
#include <ecl/ecl-cmp.h>
#include "ext/rt.eclh"
/*	function definition for MAKE-ENTRY                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1make_entry(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1;
  cl_object v2;
  cl_object v3;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  {
   cl_object keyvars[6];
   cl_parse_key(args,3,L1make_entrykeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v1 = keyvars[0];
   v2 = keyvars[1];
   v3 = keyvars[2];
  }
  value0 = cl_list(3, v1, v2, v3);
  return value0;
 }
}
/*	local function VALS                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC2vals(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4entry;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4entry = v5;
   }
   if (Null(v3)) { goto L8; }
   si_dm_too_many_arguments(v1);
L8:;
   value0 = cl_list(2, ECL_SYM("CDDDR",196), v4entry);
   return value0;
  }
 }
}
/*	local function DEFN                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC3defn(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4entry;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4entry = v5;
   }
   if (Null(v3)) { goto L8; }
   si_dm_too_many_arguments(v1);
L8:;
   value0 = cl_list(2, ECL_SYM("CDR",198), v4entry);
   return value0;
  }
 }
}
/*	function definition for PENDING-TESTS                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4pending_tests()
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v1;
   cl_object v2l;
   cl_object v3r;
   v1 = ecl_cdr(ecl_symbol_value(VV[2]));
   v2l = v1;
   v3r = ECL_NIL;
   goto L6;
L5:;
   T0 = ecl_car(v2l);
   if (Null(ecl_function_dispatch(cl_env_copy,VV[39])(1, T0) /*  PEND */)) { goto L8; }
   T0 = ecl_car(v2l);
   T1 = ecl_function_dispatch(cl_env_copy,VV[40])(1, T0) /*  NAME     */;
   v3r = CONS(T1,v3r);
L8:;
   v2l = ecl_cdr(v2l);
L6:;
   if (v2l==ECL_NIL) { goto L13; }
   goto L5;
L13:;
   value0 = cl_nreverse(v3r);
   return value0;
  }
 }
}
/*	function definition for REM-ALL-TESTS                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5rem_all_tests()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  cl_set(VV[2],ecl_list1(ECL_NIL));
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for REM-TEST                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6rem_test(cl_narg narg, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1name;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1name = ecl_symbol_value(VV[0]);
   } else {
    i++;
    v1name = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v2l;
   v2l = ecl_symbol_value(VV[2]);
   goto L5;
L4:;
   T0 = ecl_cadr(v2l);
   T1 = ecl_function_dispatch(cl_env_copy,VV[40])(1, T0) /*  NAME     */;
   if (!(ecl_equal(T1,v1name))) { goto L7; }
   {
    cl_object v3;
    v3 = ecl_cddr(v2l);
    if (ecl_unlikely(ECL_ATOM(v2l))) FEtype_error_cons(v2l);
    T0 = v2l;
    (ECL_CONS_CDR(T0)=v3,T0);
   }
   value0 = v1name;
   cl_env_copy->nvalues = 1;
   return value0;
L7:;
   v2l = ecl_cdr(v2l);
L5:;
   T0 = ecl_cdr(v2l);
   if (T0==ECL_NIL) { goto L16; }
   goto L4;
L16:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for GET-TEST                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7get_test(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1name;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1name = ecl_symbol_value(VV[0]);
   } else {
    i++;
    v1name = va_arg(args,cl_object);
   }
  }
  va_end(args);
  T0 = L8get_entry(v1name);
  value0 = ecl_cdr(T0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for GET-ENTRY                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8get_entry(cl_object v1name)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2entry;
   {
    cl_object v3;
    cl_object v4;
    v3 = ecl_cdr(ecl_symbol_value(VV[2]));
    v4 = si_make_seq_iterator(2, v3, ecl_make_fixnum(0));
L4:;
    if ((v4)!=ECL_NIL) { goto L6; }
    v2entry = ECL_NIL;
    goto L1;
L6:;
    {
     cl_object v5;
     v5 = si_seq_iterator_ref(v3, v4);
     T0 = ecl_function_dispatch(cl_env_copy,VV[40])(1, v5) /*  NAME   */;
     if (!(ecl_equal(v1name,T0))) { goto L8; }
     v2entry = v5;
     goto L1;
    }
L8:;
    v4 = si_seq_iterator_next(v3, v4);
    goto L4;
   }
L1:;
   if (!(v2entry==ECL_NIL)) { goto L13; }
   L11report_error(3, ECL_T, _ecl_static_2, v1name);
L13:;
   value0 = v2entry;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function DEFTEST                                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC9deftest(cl_object v1, cl_object v2)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4name;
   cl_object v5form;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4name = v6;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5form = v6;
   }
   T0 = cl_listX(4, ECL_T, v4name, v5form, v3);
   T1 = cl_list(2, ECL_SYM("QUOTE",679), T0);
   value0 = cl_list(2, VV[20], T1);
   return value0;
  }
 }
}
/*	function definition for ADD-ENTRY                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L10add_entry(cl_object v1entry)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  v1entry = cl_copy_list(v1entry);
  {
   cl_object v2l;
   v2l = ecl_symbol_value(VV[2]);
   goto L7;
L6:;
   T0 = ecl_cdr(v2l);
   if (!(T0==ECL_NIL)) { goto L9; }
   {
    cl_object v3;
    v3 = ecl_list1(v1entry);
    if (ecl_unlikely(ECL_ATOM(v2l))) FEtype_error_cons(v2l);
    T0 = v2l;
    (ECL_CONS_CDR(T0)=v3,T0);
   }
   goto L3;
L9:;
   T0 = ecl_cadr(v2l);
   T1 = ecl_function_dispatch(cl_env_copy,VV[40])(1, T0) /*  NAME     */;
   T2 = ecl_function_dispatch(cl_env_copy,VV[40])(1, v1entry) /*  NAME */;
   if (!(ecl_equal(T1,T2))) { goto L16; }
   {
    cl_object v3;
    v3 = ecl_cdr(v2l);
    if (ecl_unlikely(ECL_ATOM(v3))) FEtype_error_cons(v3);
    T0 = v3;
   }
   (ECL_CONS_CAR(T0)=v1entry,T0);
   T0 = ecl_function_dispatch(cl_env_copy,VV[40])(1, v1entry) /*  NAME */;
   L11report_error(3, ECL_NIL, _ecl_static_3, T0);
   goto L3;
L16:;
   v2l = ecl_cdr(v2l);
L7:;
   goto L6;
  }
L3:;
  if (Null(ecl_symbol_value(VV[1]))) { goto L27; }
  L16do_entry(1, v1entry);
L27:;
  cl_set(VV[0],ecl_function_dispatch(cl_env_copy,VV[40])(1, v1entry) /*  NAME */);
  value0 = ecl_symbol_value(VV[0]);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for REPORT-ERROR                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L11report_error(cl_narg narg, cl_object v1error_, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2args;
  ecl_va_list args; ecl_va_start(args,v1error_,narg,1);
  v2args = cl_grab_rest_args(args);
  ecl_va_end(args);
  if (Null(ecl_symbol_value(VV[4]))) { goto L1; }
  T0 = (ECL_SYM("FORMAT",387)->symbol.gfdef);
  cl_apply(3, T0, ECL_T, v2args);
  if (Null(v1error_)) { goto L5; }
  cl_env_copy->values[0] = ECL_NIL;
  cl_env_copy->nvalues = 1;
  cl_throw(VV[4]);
L5:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (Null(v1error_)) { goto L8; }
  T0 = (ECL_SYM("ERROR",337)->symbol.gfdef);
  value0 = cl_apply(2, T0, v2args);
  return value0;
L8:;
  T0 = (ECL_SYM("WARN",903)->symbol.gfdef);
  value0 = cl_apply(2, T0, v2args);
  return value0;
 }
}
/*	function definition for DO-TEST                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L12do_test(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1name;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1name = ecl_symbol_value(VV[0]);
   } else {
    i++;
    v1name = va_arg(args,cl_object);
   }
  }
  va_end(args);
  T0 = L8get_entry(v1name);
  value0 = L16do_entry(1, T0);
  return value0;
 }
}
/*	function definition for EQUALP-WITH-CASE                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L13equalp_with_case(cl_object v1x, cl_object v2y)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!((v1x)==(v2y))) { goto L1; }
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (!(ECL_CONSP(v1x))) { goto L3; }
  if (!(ECL_CONSP(v2y))) { goto L6; }
  T0 = ecl_car(v1x);
  T1 = ecl_car(v2y);
  if (Null(L13equalp_with_case(T0, T1))) { goto L6; }
  v1x = ecl_cdr(v1x);
  v2y = ecl_cdr(v2y);
  goto TTL;
L6:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L3:;
  if (!(ECL_ARRAYP(v1x))) { goto L12; }
  T0 = cl_array_rank(v1x);
  if (!((ecl_to_fixnum(T0))==(0))) { goto L12; }
  if (ecl_unlikely((v1x)->array.rank != (0)))
            FEwrong_dimensions(v1x,0);
  v1x = ecl_aref_unsafe(v1x,0);
  if (ecl_unlikely((v2y)->array.rank != (0)))
            FEwrong_dimensions(v2y,0);
  v2y = ecl_aref_unsafe(v2y,0);
  goto TTL;
L12:;
  if (!(ECL_VECTORP(v1x))) { goto L22; }
  if (!(ECL_VECTORP(v2y))) { goto L25; }
  {
   cl_fixnum v3;
   cl_fixnum v4;
   v3 = ecl_length(v1x);
   v4 = ecl_length(v2y);
   if (!((v3)==(v4))) { goto L30; }
   {
    cl_object v5e1;
    cl_object v6;
    cl_fixnum v7;
    cl_fixnum v8;
    v5e1 = ECL_NIL;
    if (ecl_unlikely(!ECL_VECTORP(v1x))) FEtype_error_vector(v1x);
    v6 = v1x;
    v7 = 0;
    v8 = 0;
    {
     cl_object v9e2;
     cl_object v10;
     cl_fixnum v11;
     cl_fixnum v12;
     v9e2 = ECL_NIL;
     if (ecl_unlikely(!ECL_VECTORP(v2y))) FEtype_error_vector(v2y);
     v10 = v2y;
     v11 = 0;
     v12 = 0;
     v8 = ecl_length(v6);
     v12 = ecl_length(v10);
L42:;
     if (!((v7)>=(v8))) { goto L48; }
     goto L43;
L48:;
     {
      cl_fixnum v13;
      if (ecl_unlikely((v7)>=(v6)->vector.dim))
           FEwrong_index(ECL_NIL,v6,-1,ecl_make_fixnum(v7),(v6)->vector.dim);
      v13 = v7;
      v5e1 = ecl_aref_unsafe(v6,v13);
     }
     {
      cl_object v13;
      v13 = ecl_make_integer((v7)+1);
      {
       bool v14;
       v14 = ECL_FIXNUMP(v13);
       if (ecl_unlikely(!(v14)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v13);
      }
      v7 = ecl_fixnum(v13);
     }
     if (!((v11)>=(v12))) { goto L59; }
     goto L43;
L59:;
     {
      cl_fixnum v13;
      if (ecl_unlikely((v11)>=(v10)->vector.dim))
           FEwrong_index(ECL_NIL,v10,-1,ecl_make_fixnum(v11),(v10)->vector.dim);
      v13 = v11;
      v9e2 = ecl_aref_unsafe(v10,v13);
     }
     {
      cl_object v13;
      v13 = ecl_make_integer((v11)+1);
      {
       bool v14;
       v14 = ECL_FIXNUMP(v13);
       if (ecl_unlikely(!(v14)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v13);
      }
      v11 = ecl_fixnum(v13);
     }
     if ((L13equalp_with_case(v5e1, v9e2))!=ECL_NIL) { goto L70; }
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 1;
     return value0;
L70:;
     goto L42;
L43:;
     value0 = ECL_T;
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
L30:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L25:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L22:;
  if (!(ECL_ARRAYP(v1x))) { goto L74; }
  if (!(ECL_ARRAYP(v2y))) { goto L74; }
  T0 = cl_array_dimensions(v1x);
  T1 = cl_array_dimensions(v2y);
  if (ecl_equal(T0,T1)) { goto L74; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L74:;
  if (!(ECL_ARRAYP(v1x))) { goto L78; }
  if (!(ECL_ARRAYP(v2y))) { goto L81; }
  {
   cl_fixnum v13size;
   v13size = ecl_fixnum(cl_array_total_size(v1x));
   {
    cl_object v14i;
    cl_object v15;
    v14i = ecl_make_fixnum(0);
    v15 = ecl_make_fixnum(v13size);
L86:;
    if (!(ecl_number_compare(v14i,v15)>=0)) { goto L88; }
    goto L87;
L88:;
    T0 = ecl_aref(v1x,ecl_to_size(v14i));
    T1 = ecl_aref(v2y,ecl_to_size(v14i));
    if ((L13equalp_with_case(T0, T1))!=ECL_NIL) { goto L90; }
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
L90:;
    v14i = ecl_one_plus(v14i);
    goto L86;
L87:;
    value0 = ECL_T;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
L81:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L78:;
  value0 = ecl_make_bool(ecl_eql(v1x,v2y));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for DO-ENTRY                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L16do_entry(volatile cl_narg narg, cl_object volatile v1entry, ...)
{
 cl_object T0, T1, T2, T3, T4, T5;
 volatile cl_object lex0[1];
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1, CLV2
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  volatile cl_object v2s;
  va_list args; va_start(args,v1entry);
  lex0[0] = v1entry;                              /*  ENTRY           */
  {
   int i = 1;
   if (i >= narg) {
    v2s = ecl_symbol_value(ECL_SYM("*STANDARD-OUTPUT*",67));
   } else {
    i++;
    v2s = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = VV[3];
  if (ecl_frs_push(cl_env_copy,value0)==0) {      /*  BEGIN CATCH 3   */
   cl_set(VV[0],ecl_function_dispatch(cl_env_copy,VV[40])(1, lex0[0]) /*  NAME */);
   ecl_elt_set(lex0[0],0,ECL_T);
   {
    volatile cl_object env1 = env0;
    ecl_bds_bind(cl_env_copy,VV[3],ECL_T);        /*  *IN-TEST*       */
    env1 = ECL_NIL;
    CLV0 = env1 = CONS(ECL_NIL,env1);             /*  ABORTED         */
    CLV1 = env1 = CONS(ECL_NIL,env1);             /*  R               */
    {
     CLV2 = env1 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env1); /*  ABORTED */
     if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV2))!=0) {
     ecl_frs_pop(cl_env_copy);
     } else {
     if (Null(ecl_symbol_value(VV[5]))) { goto L11; }
     T0 = (ECL_SYM("MUFFLE-WARNING",571)->symbol.gfdef);
     T1 = CONS(ECL_SYM("STYLE-WARNING",827),T0);
     {cl_object v3;
      v3 = ECL_NIL;
      v3 = ecl_make_cclosure_va((cl_objectfn)LC15__g71,env1,Cblock);
      T2 = v3;
     }
     T3 = CONS(ECL_SYM("ERROR",337),T2);
     T4 = cl_list(2, T1, T3);
     T5 = CONS(T4,ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5)));
     ecl_bds_bind(cl_env_copy,ECL_SYM("*HANDLER-CLUSTERS*",5),T5); /*  *HANDLER-CLUSTERS* */
     ECL_CONS_CAR(CLV1) = LC14_do(lex0);
     ecl_bds_unwind1(cl_env_copy);
     goto L10;
L11:;
     ECL_CONS_CAR(CLV1) = LC14_do(lex0);
L10:;
     ecl_frs_pop(cl_env_copy);}
    }
    {
     cl_object v3;
     value0 = ECL_CONS_CAR(CLV0);
     if ((value0)!=ECL_NIL) { goto L18; }
     T0 = ECL_CONS_CAR(CLV1);
     T1 = ecl_cdddr(lex0[0]);
     T2 = L13equalp_with_case(T0, T1);
     v3 = Null(T2)?ECL_T:ECL_NIL;
     goto L16;
L18:;
     v3 = value0;
     goto L16;
L16:;
     ecl_elt_set(lex0[0],0,v3);
    }
    if (Null(ecl_function_dispatch(cl_env_copy,VV[39])(1, lex0[0]) /*  PEND */)) {
    ecl_bds_unwind1(cl_env_copy);
     goto L5;
    }
    ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-CIRCLE*",47),ecl_symbol_value(VV[6])); /*  *PRINT-CIRCLE* */
    T0 = ecl_symbol_value(VV[0]);
    T1 = ecl_function_dispatch(cl_env_copy,VV[51])(1, lex0[0]) /*  FORM */;
    T2 = ecl_cdddr(lex0[0]);
    {
     cl_fixnum v3;
     v3 = ecl_length(T2);
     T3 = ecl_cdddr(lex0[0]);
     cl_format(6, v2s, _ecl_static_4, T0, T1, ecl_make_fixnum(v3), T3);
    }
    {
     cl_fixnum v3;
     v3 = ecl_length(ECL_CONS_CAR(CLV1));
     cl_format(4, v2s, _ecl_static_5, ecl_make_fixnum(v3), ECL_CONS_CAR(CLV1));
    }
    {
     cl_object v3x;
     v3x = ecl_car(ECL_CONS_CAR(CLV1));
     if (Null(si_of_class_p(2, v3x, ECL_SYM("CONDITION",248)))) {
     ecl_bds_unwind1(cl_env_copy);
     ecl_bds_unwind1(cl_env_copy);
      goto L5;
     }
     cl_format(3, v2s, _ecl_static_6, v3x);
     ecl_bds_unwind1(cl_env_copy);
     ecl_bds_unwind1(cl_env_copy);
    }
   }
L5:;
  }
  ecl_frs_pop(cl_env_copy);                       /*  END CATCH 3     */
  if ((ecl_function_dispatch(cl_env_copy,VV[39])(1, lex0[0]) /*  PEND */)!=ECL_NIL) { goto L25; }
  value0 = ecl_symbol_value(VV[0]);
  cl_env_copy->nvalues = 1;
  return value0;
L25:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function %DO                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC14_do(volatile cl_object *lex0)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_symbol_value(VV[7]))) { goto L1; }
  {
   struct ecl_stack_frame _ecl_inner_frame_aux;
   cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
   {
    cl_object v1;
    v1 = _ecl_inner_frame;
    T1 = CONS(ECL_SYM("OPTIMIZE",613),ecl_symbol_value(VV[8]));
    T2 = cl_list(2, ECL_SYM("DECLARE",274), T1);
    T3 = ecl_function_dispatch(cl_env_copy,VV[51])(1, lex0[0]) /*  FORM */;
    T4 = cl_list(4, ECL_SYM("LAMBDA",452), ECL_NIL, T2, T3);
    T0 = (cl_env_copy->function=(ECL_SYM("COMPILE",233)->symbol.gfdef))->cfun.entry(2, ECL_NIL, T4) /*  COMPILE */;
    cl_env_copy->values[0] = ecl_function_dispatch(cl_env_copy,T0)(0);
    ecl_stack_frame_push_values(v1);cl_env_copy->values[0]=ecl_apply_from_stack_frame(v1,ECL_SYM("LIST",481));
    value0 = cl_env_copy->values[0];
   }
   ecl_stack_frame_close(_ecl_inner_frame);
  }
  return value0;
L1:;
  {
   struct ecl_stack_frame _ecl_inner_frame_aux;
   cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
   {
    cl_object v1;
    v1 = _ecl_inner_frame;
    T0 = ecl_function_dispatch(cl_env_copy,VV[51])(1, lex0[0]) /*  FORM */;
    cl_env_copy->values[0] = cl_eval(T0);
    ecl_stack_frame_push_values(v1);cl_env_copy->values[0]=ecl_apply_from_stack_frame(v1,ECL_SYM("LIST",481));
    value0 = cl_env_copy->values[0];
   }
   ecl_stack_frame_close(_ecl_inner_frame);
  }
  return value0;
 }
}
/*	closure G71                                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC15__g71(cl_narg narg, cl_object v1c, ...)
{
 cl_object CLV0, CLV1, CLV2
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV2 = env0;                                     /*  ABORTED         */
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  ECL_CONS_CAR(CLV0) = ECL_T;
  ECL_CONS_CAR(CLV1) = ecl_list1(v1c);
  cl_env_copy->values[0] = ECL_NIL;
  cl_env_copy->nvalues = 1;
  cl_return_from(ECL_CONS_CAR(CLV2),ECL_NIL);
 }
 }
}
/*	function definition for CONTINUE-TESTING                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L17continue_testing()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_symbol_value(VV[3]))) { goto L1; }
  cl_env_copy->values[0] = ECL_NIL;
  cl_env_copy->nvalues = 1;
  cl_throw(VV[3]);
L1:;
  value0 = L19do_entries(ecl_symbol_value(ECL_SYM("*STANDARD-OUTPUT*",67)));
  return value0;
 }
}
/*	function definition for DO-TESTS                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L18do_tests(volatile cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  volatile cl_object v1out;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1out = ecl_symbol_value(ECL_SYM("*STANDARD-OUTPUT*",67));
   } else {
    i++;
    v1out = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v2;
   v2 = ecl_cdr(ecl_symbol_value(VV[2]));
   goto L6;
L5:;
   {
    cl_object v3entry;
    v3entry = ecl_car(v2);
    ecl_elt_set(v3entry,0,ECL_T);
   }
   v2 = ecl_cdr(v2);
L6:;
   if (Null(v2)) { goto L13; }
   goto L5;
L13:;
  }
  if (Null(cl_streamp(v1out))) { goto L15; }
  value0 = L19do_entries(v1out);
  return value0;
L15:;
  {
   volatile cl_object v2stream;
   v2stream = cl_open(3, v1out, ECL_SYM("DIRECTION",1218), ECL_SYM("OUTPUT",1282));
   {
    volatile bool unwinding = FALSE;
    cl_index v3=ECL_STACK_INDEX(cl_env_copy),v4;
    ecl_frame_ptr next_fr;
    if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
      unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
    } else {
    {
     struct ecl_stack_frame _ecl_inner_frame_aux;
     volatile cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
     {
      cl_object v5;
      v5 = _ecl_inner_frame;
      cl_env_copy->values[0] = L19do_entries(v2stream);
      ecl_stack_frame_push_values(v5);
      if (Null(v2stream)) { goto L23; }
      cl_close(1, v2stream);
L23:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v5);
     }
     ecl_stack_frame_close(_ecl_inner_frame);
    }
    }
    ecl_frs_pop(cl_env_copy);
    v4=ecl_stack_push_values(cl_env_copy);
    if (Null(v2stream)) { goto L25; }
    cl_close(3, v2stream, ECL_SYM("ABORT",1195), ECL_T);
L25:;
    ecl_stack_pop_values(cl_env_copy,v4);
    if (unwinding) ecl_unwind(cl_env_copy,next_fr);
    ECL_STACK_SET_INDEX(cl_env_copy,v3);
    return cl_env_copy->values[0];
   }
  }
 }
}
/*	function definition for DO-ENTRIES                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L19do_entries(cl_object v1s)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_cdr(ecl_symbol_value(VV[2]));
  T1 = ecl_fdefinition(VV[39]);
  T2 = cl_count(4, ECL_T, T0, ECL_SYM("KEY",1262), T1);
  T3 = ecl_cdr(ecl_symbol_value(VV[2]));
  {
   cl_fixnum v2;
   v2 = ecl_length(T3);
   cl_format(4, v1s, _ecl_static_7, T2, ecl_make_fixnum(v2));
  }
  {
   cl_object v2;
   v2 = ecl_cdr(ecl_symbol_value(VV[2]));
   goto L7;
L6:;
   {
    cl_object v3entry;
    v3entry = ecl_car(v2);
    if (Null(ecl_function_dispatch(cl_env_copy,VV[39])(1, v3entry) /*  PEND */)) { goto L11; }
    T0 = L16do_entry(2, v3entry, v1s);
    cl_format(3, v1s, _ecl_static_8, T0);
L11:;
   }
   v2 = ecl_cdr(v2);
L7:;
   if (Null(v2)) { goto L15; }
   goto L6;
L15:;
  }
  {
   cl_object v2;
   cl_object v3;
   v2 = L4pending_tests();
   T0 = (ECL_SYM("EQUAL",335)->symbol.gfdef);
   v3 = cl_make_hash_table(2, ECL_SYM("TEST",1316), T0);
   {
    cl_object v4;
    v4 = ecl_symbol_value(VV[9]);
    goto L24;
L23:;
    {
     cl_object v5ex;
     v5ex = ecl_car(v4);
     si_hash_set(v5ex, v3, ECL_T);
    }
    v4 = ecl_cdr(v4);
L24:;
    if (Null(v4)) { goto L31; }
    goto L23;
L31:;
   }
   {
    cl_object v4new_failures;
    {
     cl_object v5pend;
     cl_object v6;
     v5pend = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v2))) FEtype_error_list(v2);
     v6 = v2;
     {
      cl_object v7;
      cl_object v8;
      v7 = ecl_list1(ECL_NIL);
      v8 = v7;
L39:;
      if (!(ecl_endp(v6))) { goto L41; }
      goto L40;
L41:;
      v5pend = _ecl_car(v6);
      {
       cl_object v9;
       v9 = _ecl_cdr(v6);
       if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
       v6 = v9;
      }
      if ((ecl_gethash_safe(v5pend,v3,ECL_NIL))!=ECL_NIL) { goto L49; }
      if (ecl_unlikely(ECL_ATOM(v8))) FEtype_error_cons(v8);
      T0 = v8;
      v8 = ecl_list1(v5pend);
      (ECL_CONS_CDR(T0)=v8,T0);
L49:;
      goto L39;
L40:;
      v4new_failures = ecl_cdr(v7);
      goto L33;
     }
    }
L33:;
    if (!(v2==ECL_NIL)) { goto L57; }
    cl_format(2, v1s, _ecl_static_9);
    goto L56;
L57:;
    {
     cl_fixnum v5;
     v5 = ecl_length(v2);
     T0 = ecl_cdr(ecl_symbol_value(VV[2]));
     {
      cl_fixnum v6;
      v6 = ecl_length(T0);
      cl_format(5, v1s, _ecl_static_10, ecl_make_fixnum(v5), ecl_make_fixnum(v6), v2);
     }
    }
    if (!(v4new_failures==ECL_NIL)) { goto L60; }
    cl_format(2, v1s, _ecl_static_11);
    goto L56;
L60:;
    if (Null(ecl_symbol_value(VV[9]))) { goto L56; }
    {
     cl_fixnum v5;
     v5 = ecl_length(v4new_failures);
     cl_format(4, v1s, _ecl_static_12, ecl_make_fixnum(v5), v4new_failures);
    }
L56:;
    cl_finish_output(1, v1s);
    value0 = ecl_make_bool(v2==ECL_NIL);
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}

#include "ext/rt.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclneS7gSXbpRZo9_Vi0lfE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("EXT:RT;RT.LISP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclneS7gSXbpRZo9_Vi0lfE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 ecl_function_dispatch(cl_env_copy,VV[31])(10, _ecl_static_0, VVtemp[0], _ecl_static_1, VVtemp[1], ECL_NIL, ECL_NIL, VVtemp[2], ECL_NIL, ECL_NIL, ECL_NIL) /*  DODEFPACKAGE */;
 si_select_package(_ecl_static_0);
 si_Xmake_special(VV[0]);
 if (ecl_boundp(cl_env_copy,VV[0])) { goto L4; }
 cl_set(VV[0],ECL_NIL);
L4:;
 si_Xmake_special(VV[1]);
 if (ecl_boundp(cl_env_copy,VV[1])) { goto L11; }
 cl_set(VV[1],ECL_NIL);
L11:;
 si_Xmake_special(VV[2]);
 if (ecl_boundp(cl_env_copy,VV[2])) { goto L18; }
 cl_set(VV[2],VVtemp[3]);
L18:;
 si_Xmake_special(VV[3]);
 if (ecl_boundp(cl_env_copy,VV[3])) { goto L25; }
 cl_set(VV[3],ECL_NIL);
L25:;
 si_Xmake_special(VV[4]);
 if (ecl_boundp(cl_env_copy,VV[4])) { goto L32; }
 cl_set(VV[4],ECL_NIL);
L32:;
 si_Xmake_special(VV[5]);
 if (ecl_boundp(cl_env_copy,VV[5])) { goto L39; }
 cl_set(VV[5],ECL_T);
L39:;
 si_Xmake_special(VV[6]);
 if (ecl_boundp(cl_env_copy,VV[6])) { goto L46; }
 cl_set(VV[6],ECL_NIL);
L46:;
 si_Xmake_special(VV[7]);
 if (ecl_boundp(cl_env_copy,VV[7])) { goto L53; }
 cl_set(VV[7],ECL_NIL);
L53:;
 si_Xmake_special(VV[8]);
 if (ecl_boundp(cl_env_copy,VV[8])) { goto L60; }
 cl_set(VV[8],VVtemp[4]);
L60:;
 si_Xmake_special(VV[9]);
 if (ecl_boundp(cl_env_copy,VV[9])) { goto L67; }
 cl_set(VV[9],ECL_NIL);
L67:;
 si_define_structure(15, VV[10], ECL_NIL, ECL_SYM("LIST",481), ECL_NIL, VVtemp[5], VVtemp[6], VV[11], ECL_NIL, ECL_NIL, ECL_NIL, VVtemp[7], ecl_make_fixnum(3), ECL_NIL, ECL_NIL, ECL_NIL);
 ecl_cmp_defun(VV[32]);                           /*  MAKE-ENTRY      */
 ecl_cmp_defmacro(VV[36]);                        /*  VALS            */
 ecl_cmp_defmacro(VV[37]);                        /*  DEFN            */
 ecl_cmp_defun(VV[38]);                           /*  PENDING-TESTS   */
 ecl_cmp_defun(VV[41]);                           /*  REM-ALL-TESTS   */
 ecl_cmp_defun(VV[42]);                           /*  REM-TEST        */
 ecl_cmp_defun(VV[43]);                           /*  GET-TEST        */
 ecl_cmp_defun(VV[44]);                           /*  GET-ENTRY       */
 ecl_cmp_defmacro(VV[45]);                        /*  DEFTEST         */
 ecl_cmp_defun(VV[46]);                           /*  ADD-ENTRY       */
 ecl_cmp_defun(VV[47]);                           /*  REPORT-ERROR    */
 ecl_cmp_defun(VV[48]);                           /*  DO-TEST         */
 ecl_cmp_defun(VV[49]);                           /*  EQUALP-WITH-CASE */
 ecl_cmp_defun(VV[50]);                           /*  DO-ENTRY        */
 ecl_cmp_defun(VV[52]);                           /*  CONTINUE-TESTING */
 ecl_cmp_defun(VV[53]);                           /*  DO-TESTS        */
 ecl_cmp_defun(VV[54]);                           /*  DO-ENTRIES      */
 cl_provide(VV[30]);
}
