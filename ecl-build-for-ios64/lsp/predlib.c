/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:LSP;PREDLIB.LSP                                   */
#include <ecl/ecl-cmp.h>
#include "lsp/predlib.eclh"
/*	function definition for CONSTANTLY-T                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1constantly_t(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for CONSTANTLY-NIL                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2constantly_nil(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for CONSTANTLY                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_constantly(cl_object v1n)
{
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1n,env0);                   /*  N               */
  if (!((ECL_CONS_CAR(CLV0))==(ECL_NIL))) { goto L1; }
  value0 = ecl_fdefinition(VV[1]);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (!(ecl_eql(ECL_CONS_CAR(CLV0),ECL_T))) { goto L4; }
  value0 = ecl_fdefinition(VV[0]);
  cl_env_copy->nvalues = 1;
  return value0;
L4:;
  {cl_object v2;
   v2 = ECL_NIL;
   v2 = ecl_make_cclosure_va((cl_objectfn)LC3__g3,env0,Cblock);
   value0 = v2;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	closure G3                                                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC3__g3(cl_narg narg, ...)
{
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  N               */
 { /* ... closure scanning finished */
 {
  value0 = ECL_CONS_CAR(CLV0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
 }
}
/*	function definition for SUBTYPEP-CLEAR-CACHE                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4subtypep_clear_cache()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  si_fill_array_with_elt(ecl_symbol_value(VV[4]), ECL_NIL, ecl_make_fixnum(0), ECL_NIL);
  value0 = si_fill_array_with_elt(ecl_symbol_value(VV[5]), ECL_NIL, ecl_make_fixnum(0), ECL_NIL);
  return value0;
 }
}
/*	function definition for CREATE-TYPE-NAME                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5create_type_name(cl_object v1name)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_memql(v1name,ecl_symbol_value(ECL_SYM("*ALIEN-DECLARATIONS*",1586))))) { goto L1; }
  value0 = cl_error(2, _ecl_static_1, v1name);
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for DO-DEFTYPE                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_do_deftype(cl_narg narg, cl_object v1name, cl_object v2form, cl_object v3function, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg!=3)) FEwrong_num_arguments_anonym();
 {
TTL:
  if (ECL_SYMBOLP(v1name)) { goto L1; }
  cl_error(2, _ecl_static_2, v1name);
L1:;
  L5create_type_name(v1name);
  si_put_sysprop(v1name, VV[8], v2form);
  if (Null(cl_functionp(v3function))) { goto L7; }
  T0 = v3function;
  goto L6;
L7:;
  T0 = cl_constantly(v3function);
L6:;
  si_put_sysprop(v1name, VV[9], T0);
  L4subtypep_clear_cache();
  value0 = v1name;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function DEFTYPE                                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC6deftype(cl_object v1, cl_object v2env)
{
 cl_object T0, T1, T2, T3, T4, T5, T6;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4name;
   cl_object v5lambda_list;
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
    v5lambda_list = v6;
   }
   {
    cl_object v7;                                 /*  BODY            */
    cl_object v8;                                 /*  DOC             */
    value0 = si_remove_documentation(1, v3);
    v7 = value0;
    {
     const int v9 = cl_env_copy->nvalues;
     cl_object v10;
     v10 = (v9<=1)? ECL_NIL : cl_env_copy->values[1];
     v8 = v10;
    }
    v5lambda_list = cl_copy_list(v5lambda_list);
    {
     cl_object v9;
     v9 = VV[10];
     goto L21;
L20:;
     {
      cl_object v10x;
      v10x = ecl_car(v9);
      {
       cl_object v11l;
       T0 = ecl_memql(v10x,v5lambda_list);
       v11l = ecl_cdr(T0);
       goto L30;
L29:;
       {
        cl_object v12variable;
        v12variable = ecl_car(v11l);
        if (!(ECL_SYMBOLP(v12variable))) { goto L32; }
        if ((ecl_memql(v12variable,VV[11]))!=ECL_NIL) { goto L32; }
        {
         cl_object v13;
         v13 = cl_list(2, v12variable, VV[12]);
         if (ecl_unlikely(ECL_ATOM(v11l))) FEtype_error_cons(v11l);
         T0 = v11l;
         (ECL_CONS_CAR(T0)=v13,T0);
        }
       }
L32:;
       v11l = ecl_cdr(v11l);
L30:;
       if (v11l==ECL_NIL) { goto L42; }
       goto L29;
L42:;
      }
     }
     v9 = ecl_cdr(v9);
L21:;
     if (Null(v9)) { goto L46; }
     goto L20;
L46:;
    }
    {
     cl_object v9function;
     T0 = cl_listX(4, ECL_SYM("LAMBDA-BLOCK",1339), v4name, v5lambda_list, v7);
     v9function = cl_list(2, ECL_SYM("FUNCTION",396), T0);
     if (!(v5lambda_list==ECL_NIL)) { goto L49; }
     if (!(ECL_CONSP(v7))) { goto L49; }
     T0 = ecl_cdr(v7);
     if (!(T0==ECL_NIL)) { goto L49; }
     {
      cl_object v10form;
      v10form = ecl_car(v7);
      if (Null(cl_constantp(2, v10form, v2env))) { goto L49; }
      v9function = v10form;
     }
L49:;
     T0 = si_expand_set_documentation(3, v4name, ECL_SYM("TYPE",869), v8);
     T1 = cl_list(2, ECL_SYM("QUOTE",679), v4name);
     T2 = cl_listX(4, ECL_SYM("DEFTYPE",288), v4name, v5lambda_list, v7);
     T3 = cl_list(2, ECL_SYM("QUOTE",679), T2);
     T4 = cl_list(4, ECL_SYM("DO-DEFTYPE",1584), T1, T3, v9function);
     T5 = ecl_list1(T4);
     T6 = ecl_append(T0,T5);
     value0 = cl_listX(3, ECL_SYM("EVAL-WHEN",340), VV[13], T6);
     return value0;
    }
   }
  }
 }
}
/*	local function REAL                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC7real(cl_narg narg, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v1start;
  cl_object v2start_p;
  cl_object v3end;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1start = ECL_SYM("*",18);
    v2start_p = ECL_NIL;
   } else {
    i++;
    v1start = va_arg(args,cl_object);
    v2start_p = ECL_T;
   }
   if (i >= narg) {
    v3end = ECL_SYM("*",18);
   } else {
    i++;
    v3end = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (Null(v2start_p)) { goto L3; }
  {
   cl_object v4rat_start;
   cl_object v5real_start;
   cl_object v6rat_end;
   cl_object v7real_end;
   v4rat_start = ECL_NIL;
   v5real_start = ECL_NIL;
   v6rat_end = ECL_NIL;
   v7real_end = ECL_NIL;
   if (!(ECL_CONSP(v1start))) { goto L10; }
   v1start = ecl_car(v1start);
   T0 = cl_rational(v1start);
   v4rat_start = ecl_list1(T0);
   T0 = cl_float(1, v1start);
   v5real_start = ecl_list1(T0);
   goto L9;
L10:;
   if (!(ecl_numberp(v1start))) { goto L17; }
   v4rat_start = cl_rational(v1start);
   v5real_start = cl_float(1, v1start);
   goto L9;
L17:;
   v4rat_start = v1start;
   v5real_start = v1start;
L9:;
   if (!(ECL_CONSP(v3end))) { goto L26; }
   v3end = ecl_car(v3end);
   T0 = cl_rational(v3end);
   v6rat_end = ecl_list1(T0);
   T0 = cl_float(1, v3end);
   v7real_end = ecl_list1(T0);
   goto L25;
L26:;
   if (!(ecl_numberp(v3end))) { goto L33; }
   v6rat_end = cl_rational(v3end);
   v7real_end = cl_float(1, v3end);
   goto L25;
L33:;
   v6rat_end = v3end;
   v7real_end = v3end;
L25:;
   T0 = cl_list(3, ECL_SYM("RATIONAL",687), v4rat_start, v6rat_end);
   T1 = cl_list(3, ECL_SYM("FLOAT",374), v5real_start, v7real_end);
   value0 = cl_list(3, ECL_SYM("OR",614), T0, T1);
   return value0;
  }
L3:;
  value0 = VV[16];
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function SHORT-FLOAT                                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC8short_float(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1args;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1args = cl_grab_rest_args(args);
  ecl_va_end(args);
  if (Null(v1args)) { goto L1; }
  value0 = CONS(ECL_SYM("SINGLE-FLOAT",778),v1args);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  value0 = ECL_SYM("SINGLE-FLOAT",778);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function LONG-FLOAT                                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC9long_float(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1args;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1args = cl_grab_rest_args(args);
  ecl_va_end(args);
  if (Null(v1args)) { goto L1; }
  value0 = CONS(ECL_SYM("DOUBLE-FLOAT",315),v1args);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  value0 = ECL_SYM("DOUBLE-FLOAT",315);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function MOD                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC10mod(cl_object v1n)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_one_minus(v1n);
  value0 = cl_list(3, ECL_SYM("INTEGER",437), ecl_make_fixnum(0), T0);
  return value0;
 }
}
/*	local function SIGNED-BYTE                                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC11signed_byte(cl_narg narg, ...)
{
 cl_object T0, T1, T2, T3, T4, T5;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1s;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1s = ECL_SYM("*",18);
   } else {
    i++;
    v1s = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (v1s==ECL_NIL) { goto L4; }
  if (!((v1s)==(ECL_SYM("*",18)))) { goto L2; }
  goto L3;
L4:;
L3:;
  value0 = VV[17];
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  T0 = ecl_one_minus(v1s);
  T1 = ecl_expt(ecl_make_fixnum(2),T0);
  T2 = ecl_negate(T1);
  T3 = ecl_one_minus(v1s);
  T4 = ecl_expt(ecl_make_fixnum(2),T3);
  T5 = ecl_one_minus(T4);
  value0 = cl_list(3, ECL_SYM("INTEGER",437), T2, T5);
  return value0;
 }
}
/*	local function UNSIGNED-BYTE                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC12unsigned_byte(cl_narg narg, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1s;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1s = ECL_SYM("*",18);
   } else {
    i++;
    v1s = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (v1s==ECL_NIL) { goto L4; }
  if (!((v1s)==(ECL_SYM("*",18)))) { goto L2; }
  goto L3;
L4:;
L3:;
  value0 = VV[18];
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  T0 = ecl_expt(ecl_make_fixnum(2),v1s);
  T1 = ecl_one_minus(T0);
  value0 = cl_list(3, ECL_SYM("INTEGER",437), ecl_make_fixnum(0), T1);
  return value0;
 }
}
/*	local function VECTOR                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC13vector(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v1element_type;
  cl_object v2size;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1element_type = ECL_SYM("*",18);
   } else {
    i++;
    v1element_type = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v2size = ECL_SYM("*",18);
   } else {
    i++;
    v2size = va_arg(args,cl_object);
   }
  }
  va_end(args);
  T0 = ecl_list1(v2size);
  value0 = cl_list(3, ECL_SYM("ARRAY",96), v1element_type, T0);
  return value0;
 }
}
/*	local function STRING                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC14string(cl_narg narg, ...)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1size;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1size = ECL_SYM("*",18);
   } else {
    i++;
    v1size = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (!((v1size)==(ECL_SYM("*",18)))) { goto L2; }
  value0 = VV[20];
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  T0 = ecl_list1(v1size);
  T1 = cl_list(3, ECL_SYM("ARRAY",96), ECL_SYM("BASE-CHAR",120), T0);
  T2 = ecl_list1(v1size);
  T3 = cl_list(3, ECL_SYM("ARRAY",96), ECL_SYM("CHARACTER",222), T2);
  value0 = cl_list(3, ECL_SYM("OR",614), T1, T3);
  return value0;
 }
}
/*	local function BASE-STRING                                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC15base_string(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1size;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1size = ECL_SYM("*",18);
   } else {
    i++;
    v1size = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (!((v1size)==(ECL_SYM("*",18)))) { goto L2; }
  value0 = VV[21];
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  T0 = ecl_list1(v1size);
  value0 = cl_list(3, ECL_SYM("ARRAY",96), ECL_SYM("BASE-CHAR",120), T0);
  return value0;
 }
}
/*	local function EXTENDED-STRING                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC16extended_string(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1size;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1size = ECL_SYM("*",18);
   } else {
    i++;
    v1size = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (!((v1size)==(ECL_SYM("*",18)))) { goto L2; }
  value0 = VV[22];
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  T0 = ecl_list1(v1size);
  value0 = cl_list(3, ECL_SYM("ARRAY",96), ECL_SYM("CHARACTER",222), T0);
  return value0;
 }
}
/*	local function BIT-VECTOR                                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC17bit_vector(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1size;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1size = ECL_SYM("*",18);
   } else {
    i++;
    v1size = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (!((v1size)==(ECL_SYM("*",18)))) { goto L2; }
  value0 = VV[23];
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  T0 = ecl_list1(v1size);
  value0 = cl_list(3, ECL_SYM("ARRAY",96), ECL_SYM("BIT",123), T0);
  return value0;
 }
}
/*	local function SIMPLE-VECTOR                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC18simple_vector(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1size;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1size = ECL_SYM("*",18);
   } else {
    i++;
    v1size = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (!((v1size)==(ECL_SYM("*",18)))) { goto L2; }
  value0 = VV[24];
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  T0 = ecl_list1(v1size);
  value0 = cl_list(3, ECL_SYM("SIMPLE-ARRAY",763), ECL_T, T0);
  return value0;
 }
}
/*	local function SIMPLE-STRING                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC19simple_string(cl_narg narg, ...)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1size;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1size = ECL_SYM("*",18);
   } else {
    i++;
    v1size = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (Null(v1size)) { goto L2; }
  T0 = ecl_list1(v1size);
  T1 = cl_list(3, ECL_SYM("SIMPLE-ARRAY",763), ECL_SYM("BASE-CHAR",120), T0);
  T2 = ecl_list1(v1size);
  T3 = cl_list(3, ECL_SYM("SIMPLE-ARRAY",763), ECL_SYM("CHARACTER",222), T2);
  value0 = cl_list(3, ECL_SYM("OR",614), T1, T3);
  return value0;
L2:;
  value0 = VV[25];
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function SIMPLE-BASE-STRING                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC20simple_base_string(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1size;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1size = ECL_SYM("*",18);
   } else {
    i++;
    v1size = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (Null(v1size)) { goto L2; }
  T0 = ecl_list1(v1size);
  value0 = cl_list(3, ECL_SYM("SIMPLE-ARRAY",763), ECL_SYM("BASE-CHAR",120), T0);
  return value0;
L2:;
  value0 = VV[26];
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function SIMPLE-BIT-VECTOR                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC21simple_bit_vector(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1size;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1size = ECL_SYM("*",18);
   } else {
    i++;
    v1size = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (Null(v1size)) { goto L2; }
  T0 = ecl_list1(v1size);
  value0 = cl_list(3, ECL_SYM("SIMPLE-ARRAY",763), ECL_SYM("BIT",123), T0);
  return value0;
L2:;
  value0 = VV[27];
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for SIMPLE-ARRAY-P                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L22simple_array_p(cl_object v1x)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_ARRAYP(v1x))) { goto L2; }
  if ((ECL_ARRAYP(v1x)? (void)0: FEtype_error_array(v1x),ECL_ADJUSTABLE_ARRAY_P(v1x))) { goto L2; }
  if ((ECL_ARRAYP(v1x)?(void)0:FEtype_error_array(v1x),ECL_ARRAY_HAS_FILL_POINTER_P(v1x))) { goto L2; }
  T0 = cl_array_displacement(v1x);
  value0 = Null(T0)?ECL_T:ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for COMPLEX-ARRAY-P                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L23complex_array_p(cl_object v1x)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_ARRAYP(v1x))) { goto L2; }
  value0 = ecl_make_bool((ECL_ARRAYP(v1x)? (void)0: FEtype_error_array(v1x),ECL_ADJUSTABLE_ARRAY_P(v1x)));
  if ((value0)!=ECL_NIL) { goto L5; }
  value0 = ecl_make_bool((ECL_ARRAYP(v1x)?(void)0:FEtype_error_array(v1x),ECL_ARRAY_HAS_FILL_POINTER_P(v1x)));
  if ((value0)!=ECL_NIL) { goto L5; }
  value0 = cl_array_displacement(v1x);
  return value0;
L5:;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for UPGRADED-ARRAY-ELEMENT-TYPE           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_upgraded_array_element_type(cl_narg narg, cl_object v1element_type, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2env;
  va_list args; va_start(args,v1element_type);
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
  {
   int8_t v3hash;
   cl_object v4record;
   {
    cl_object v5;
    T0 = si_hash_eql(1, v1element_type);
    v5 = ecl_boole(ECL_BOOLAND,(ecl_make_fixnum(127)),(T0));
    {
     cl_fixnum v6;
     v6 = 0;
     if (!(ECL_FIXNUMP(v5))) { goto L8; }
     v6 = ecl_fixnum(v5);
     if (!((v6)<=(127))) { goto L13; }
     T0 = ecl_make_bool((v6)>=(0));
     goto L5;
L13:;
     T0 = ECL_NIL;
     goto L5;
L8:;
     T0 = ECL_NIL;
     goto L5;
    }
L5:;
    if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[33],v5);
    v3hash = ecl_fixnum(v5);
   }
   {
    cl_object v5;
    v5 = ecl_symbol_value(VV[5]);
    {
     int8_t v6;
     if (ecl_unlikely(((cl_fixnum)(v3hash))>=(v5)->vector.dim))
           FEwrong_index(ECL_NIL,v5,-1,ecl_make_fixnum((cl_fixnum)(v3hash)),(v5)->vector.dim);
     v6 = v3hash;
     v4record = ecl_aref_unsafe(v5,(cl_fixnum)(v6));
    }
   }
   if (Null(v4record)) { goto L20; }
   T0 = ecl_car(v4record);
   if (!((T0)==(v1element_type))) { goto L20; }
   value0 = ecl_cdr(v4record);
   cl_env_copy->nvalues = 1;
   return value0;
L20:;
   {
    cl_object v5answer;
    if (Null(si_memq(v1element_type,VV[34]))) { goto L24; }
    v5answer = v1element_type;
    goto L23;
L24:;
    {
     cl_object v6;
     v6 = ecl_symbol_value(VV[32]);
     goto L29;
L28:;
     {
      cl_object v7v;
      v7v = ecl_car(v6);
      if (Null(cl_subtypep(2, v1element_type, v7v))) { goto L33; }
      v5answer = v7v;
      goto L23;
L33:;
     }
     v6 = ecl_cdr(v6);
L29:;
     if (Null(v6)) { goto L37; }
     goto L28;
L37:;
     v5answer = ECL_T;
    }
L23:;
    {
     cl_object v6;
     v6 = ecl_symbol_value(VV[5]);
     {
      int8_t v7;
      if (ecl_unlikely(((cl_fixnum)(v3hash))>=(v6)->vector.dim))
           FEwrong_index(ECL_NIL,v6,-1,ecl_make_fixnum((cl_fixnum)(v3hash)),(v6)->vector.dim);
      v7 = v3hash;
      T0 = CONS(v1element_type,v5answer);
      ecl_aset_unsafe(v6,(cl_fixnum)(v7),T0);
     }
    }
    value0 = v5answer;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for UPGRADED-COMPLEX-PART-TYPE            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_upgraded_complex_part_type(cl_narg narg, cl_object v1real_type, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2env;
  va_list args; va_start(args,v1real_type);
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
  if ((cl_subtypep(2, v1real_type, ECL_SYM("REAL",703)))!=ECL_NIL) { goto L2; }
  cl_error(2, _ecl_static_3, v1real_type);
L2:;
  value0 = ECL_SYM("REAL",703);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for IN-INTERVAL-P                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L24in_interval_p(cl_object v1x, cl_object v2interval)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3low;
   cl_object v4high;
   v3low = ECL_NIL;
   v4high = ECL_NIL;
   if (!(ecl_endp(v2interval))) { goto L4; }
   v3low = ECL_SYM("*",18);
   v4high = ECL_SYM("*",18);
   goto L3;
L4:;
   T0 = ecl_cdr(v2interval);
   if (!(ecl_endp(T0))) { goto L9; }
   v3low = ecl_car(v2interval);
   v4high = ECL_SYM("*",18);
   goto L3;
L9:;
   v3low = ecl_car(v2interval);
   v4high = ecl_cadr(v2interval);
L3:;
   {
    cl_object v5;
    v5 = ecl_make_bool((v3low)==(ECL_SYM("*",18)));
    if (Null(v5)) { goto L19; }
    goto L17;
L19:;
    if (!(ECL_CONSP(v3low))) { goto L21; }
    T0 = ecl_car(v3low);
    if (!(ecl_number_compare(v1x,T0)<=0)) { goto L17; }
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
L21:;
    {
     cl_object v6;
     if (!(ecl_number_compare(v1x,v3low)<0)) { goto L25; }
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 1;
     return value0;
L25:;
     v6 = ECL_NIL;
     if (Null(v6)) { goto L17; }
    }
   }
L17:;
   {
    cl_object v5;
    v5 = ecl_make_bool((v4high)==(ECL_SYM("*",18)));
    if (Null(v5)) { goto L30; }
    goto L28;
L30:;
    if (!(ECL_CONSP(v4high))) { goto L32; }
    T0 = ecl_car(v4high);
    if (!(ecl_number_compare(v1x,T0)>=0)) { goto L28; }
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
L32:;
    {
     cl_object v6;
     if (!(ecl_number_compare(v1x,v4high)>0)) { goto L36; }
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 1;
     return value0;
L36:;
     v6 = ECL_NIL;
     if (Null(v6)) { goto L28; }
    }
   }
L28:;
   value0 = ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for ERROR-TYPE-SPECIFIER                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L25error_type_specifier(cl_object v1type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_error(2, _ecl_static_4, v1type);
  return value0;
 }
}
/*	function definition for MATCH-DIMENSIONS                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L26match_dimensions(cl_object v1array, cl_object v2pat)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_make_bool((v2pat)==(ECL_SYM("*",18)));
  if ((value0)!=ECL_NIL) { goto L2; }
  {
   int8_t v3rank;
   v3rank = ecl_fixnum(cl_array_rank(v1array));
   if (!(ecl_numberp(v2pat))) { goto L5; }
   value0 = ecl_make_bool(ecl_number_equalp(ecl_make_int8_t(v3rank),v2pat));
   cl_env_copy->nvalues = 1;
   return value0;
L5:;
   if (!(ECL_LISTP(v2pat))) { goto L7; }
   {
    cl_object v4i;
    v4i = ecl_make_fixnum(0);
    goto L12;
L11:;
    if (!(ECL_CONSP(v2pat))) { goto L17; }
    T0 = ecl_car(v2pat);
    if ((T0)==(ECL_SYM("*",18))) { goto L14; }
    {
     cl_fixnum v5;
     v5 = ecl_array_dimension(v1array,ecl_to_size(v4i));
     T0 = ecl_car(v2pat);
     if ((ecl_make_fixnum(v5))==(T0)) { goto L14; }
     goto L15;
    }
L17:;
    goto L15;
L15:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
L14:;
    v2pat = ecl_cdr(v2pat);
    v4i = ecl_one_plus(v4i);
L12:;
    if (!(ecl_number_compare(v4i,ecl_make_int8_t(v3rank))<0)) { goto L24; }
    goto L11;
L24:;
    value0 = ecl_make_bool(v2pat==ECL_NIL);
    cl_env_copy->nvalues = 1;
    return value0;
   }
L7:;
   if (!(ECL_ATOM(v2pat))) { goto L26; }
   value0 = cl_error(2, _ecl_static_5, v2pat);
   return value0;
L26:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for TYPEP                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_typep(cl_narg narg, cl_object v1object, cl_object v2type, ...)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v3env;
  va_list args; va_start(args,v2type);
  {
   int i = 2;
   if (i >= narg) {
    v3env = ECL_NIL;
   } else {
    i++;
    v3env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v4tp;
   cl_object v5i;
   cl_object v6c;
   v4tp = ECL_NIL;
   v5i = ECL_NIL;
   v6c = ECL_NIL;
   if (!(ECL_SYMBOLP(v2type))) { goto L6; }
   {
    cl_object v7f;
    v7f = si_get_sysprop(v2type, VV[31]);
    if (Null(v7f)) { goto L9; }
    value0 = ecl_function_dispatch(cl_env_copy,v7f)(1, v1object);
    return value0;
L9:;
    T0 = cl_type_of(v1object);
    if (!((T0)==(v2type))) { goto L11; }
    value0 = ECL_T;
    cl_env_copy->nvalues = 1;
    return value0;
L11:;
    v4tp = v2type;
    v5i = ECL_NIL;
    goto L5;
   }
L6:;
   if (!(ECL_CONSP(v2type))) { goto L16; }
   v4tp = ecl_car(v2type);
   v5i = ecl_cdr(v2type);
   goto L5;
L16:;
   if (!(ECL_INSTANCEP(v2type))) { goto L21; }
   T0 = cl_class_of(v1object);
   value0 = si_subclassp(2, T0, v2type);
   return value0;
L21:;
   L25error_type_specifier(v2type);
L5:;
   if (!((v4tp)==(ECL_SYM("EQL",334)))) { goto L28; }
   goto L25;
   goto L26;
L28:;
   goto L26;
L26:;
   if (!((v4tp)==(ECL_SYM("MEMBER",552)))) { goto L23; }
   goto L24;
L25:;
L24:;
   if (Null(ecl_memql(v1object,v5i))) { goto L32; }
   value0 = ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
L32:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L23:;
   if (!((v4tp)==(ECL_SYM("NOT",584)))) { goto L34; }
   T0 = ecl_car(v5i);
   T1 = cl_typep(2, v1object, T0);
   value0 = Null(T1)?ECL_T:ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L34:;
   if (!((v4tp)==(ECL_SYM("OR",614)))) { goto L36; }
   {
    cl_object v7;
    v7 = v5i;
    goto L41;
L40:;
    {
     cl_object v8e;
     v8e = ecl_car(v7);
     if (Null(cl_typep(2, v1object, v8e))) { goto L45; }
     value0 = ECL_T;
     cl_env_copy->nvalues = 1;
     return value0;
L45:;
    }
    v7 = ecl_cdr(v7);
L41:;
    if (Null(v7)) { goto L49; }
    goto L40;
L49:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L36:;
   if (!((v4tp)==(ECL_SYM("AND",87)))) { goto L51; }
   {
    cl_object v8;
    v8 = v5i;
    goto L56;
L55:;
    {
     cl_object v9e;
     v9e = ecl_car(v8);
     if ((cl_typep(2, v1object, v9e))!=ECL_NIL) { goto L60; }
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 1;
     return value0;
L60:;
    }
    v8 = ecl_cdr(v8);
L56:;
    if (Null(v8)) { goto L64; }
    goto L55;
L64:;
    value0 = ECL_T;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L51:;
   if (!((v4tp)==(ECL_SYM("SATISFIES",735)))) { goto L66; }
   T0 = ecl_car(v5i);
   value0 = ecl_function_dispatch(cl_env_copy,T0)(1, v1object);
   return value0;
L66:;
   if (!(ecl_eql(v4tp,ECL_T))) { goto L69; }
   value0 = ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
L69:;
   if (!((v4tp)==(ECL_NIL))) { goto L72; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L72:;
   if (!((v4tp)==(ECL_SYM("BIGNUM",122)))) { goto L75; }
   if (!(ECL_FIXNUMP(v1object)||ECL_BIGNUMP(v1object))) { goto L78; }
   {
    bool v9;
    v9 = ECL_FIXNUMP(v1object);
    value0 = (v9)?ECL_NIL:ECL_T;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L78:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L75:;
   if (!((v4tp)==(ECL_SYM("RATIO",686)))) { goto L80; }
   T0 = cl_type_of(v1object);
   value0 = ecl_make_bool((T0)==(ECL_SYM("RATIO",686)));
   cl_env_copy->nvalues = 1;
   return value0;
L80:;
   if (!((v4tp)==(ECL_SYM("STANDARD-CHAR",794)))) { goto L82; }
   if (!(ECL_CHARACTERP(v1object))) { goto L85; }
   value0 = cl_standard_char_p(v1object);
   return value0;
L85:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L82:;
   if (!((v4tp)==(ECL_SYM("INTEGER",437)))) { goto L87; }
   if (!(ECL_FIXNUMP(v1object)||ECL_BIGNUMP(v1object))) { goto L90; }
   value0 = L24in_interval_p(v1object, v5i);
   return value0;
L90:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L87:;
   if (!((v4tp)==(ECL_SYM("RATIONAL",687)))) { goto L92; }
   if (Null(cl_rationalp(v1object))) { goto L95; }
   value0 = L24in_interval_p(v1object, v5i);
   return value0;
L95:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L92:;
   if (!((v4tp)==(ECL_SYM("FLOAT",374)))) { goto L97; }
   if (!(floatp(v1object))) { goto L100; }
   value0 = L24in_interval_p(v1object, v5i);
   return value0;
L100:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L97:;
   if (!((v4tp)==(ECL_SYM("REAL",703)))) { goto L102; }
   if ((cl_rationalp(v1object))!=ECL_NIL) { goto L107; }
   if (!(floatp(v1object))) { goto L105; }
   goto L106;
L107:;
L106:;
   value0 = L24in_interval_p(v1object, v5i);
   return value0;
L105:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L102:;
   if (!((v4tp)==(ECL_SYM("SINGLE-FLOAT",778)))) { goto L114; }
   goto L111;
   goto L112;
L114:;
   goto L112;
L112:;
   if (!((v4tp)==(ECL_SYM("SHORT-FLOAT",756)))) { goto L109; }
   goto L110;
L111:;
L110:;
   T0 = cl_type_of(v1object);
   if (!((T0)==(ECL_SYM("SINGLE-FLOAT",778)))) { goto L118; }
   value0 = L24in_interval_p(v1object, v5i);
   return value0;
L118:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L109:;
   if (!((v4tp)==(ECL_SYM("DOUBLE-FLOAT",315)))) { goto L125; }
   goto L122;
   goto L123;
L125:;
   goto L123;
L123:;
   if (!((v4tp)==(ECL_SYM("LONG-FLOAT",508)))) { goto L120; }
   goto L121;
L122:;
L121:;
   T0 = cl_type_of(v1object);
   if (!((T0)==(ECL_SYM("DOUBLE-FLOAT",315)))) { goto L129; }
   value0 = L24in_interval_p(v1object, v5i);
   return value0;
L129:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L120:;
   if (!((v4tp)==(ECL_SYM("COMPLEX",241)))) { goto L131; }
   if (Null(cl_complexp(v1object))) { goto L134; }
   value0 = ecl_make_bool(v5i==ECL_NIL);
   if ((value0)!=ECL_NIL) { goto L137; }
   T0 = cl_realpart(v1object);
   T1 = ecl_car(v5i);
   if (Null(cl_typep(2, T0, T1))) { goto L140; }
   T0 = cl_imagpart(v1object);
   T1 = ecl_car(v5i);
   value0 = cl_typep(2, T0, T1);
   return value0;
L140:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L137:;
   cl_env_copy->nvalues = 1;
   return value0;
L134:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L131:;
   if (!((v4tp)==(ECL_SYM("SEQUENCE",741)))) { goto L142; }
   value0 = ecl_make_bool(ECL_LISTP(v1object));
   if ((value0)!=ECL_NIL) { goto L145; }
   value0 = ecl_make_bool(ECL_VECTORP(v1object));
   cl_env_copy->nvalues = 1;
   return value0;
L145:;
   cl_env_copy->nvalues = 1;
   return value0;
L142:;
   if (!((v4tp)==(ECL_SYM("CONS",251)))) { goto L147; }
   if (!(ECL_CONSP(v1object))) { goto L150; }
   if (ecl_endp(v5i)) { goto L153; }
   {
    cl_object v10car_type;
    v10car_type = ecl_car(v5i);
    if ((v10car_type)==(ECL_SYM("*",18))) { goto L156; }
    T0 = ecl_car(v1object);
    if (Null(cl_typep(2, T0, v10car_type))) { goto L150; }
    goto L152;
L156:;
    goto L152;
   }
L153:;
L152:;
   T0 = ecl_cdr(v5i);
   value0 = ecl_make_bool(ecl_endp(T0));
   if ((value0)!=ECL_NIL) { goto L159; }
   {
    cl_object v10cdr_type;
    v10cdr_type = ecl_cadr(v5i);
    value0 = ecl_make_bool((v10cdr_type)==(ECL_SYM("*",18)));
    if ((value0)!=ECL_NIL) { goto L163; }
    T0 = ecl_cdr(v1object);
    value0 = cl_typep(2, T0, v10cdr_type);
    return value0;
L163:;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L159:;
   cl_env_copy->nvalues = 1;
   return value0;
L150:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L147:;
   if (!((v4tp)==(ECL_SYM("BASE-STRING",121)))) { goto L165; }
   if (Null(si_base_string_p(v1object))) { goto L168; }
   value0 = ecl_make_bool(v5i==ECL_NIL);
   if ((value0)!=ECL_NIL) { goto L171; }
   value0 = L26match_dimensions(v1object, v5i);
   return value0;
L171:;
   cl_env_copy->nvalues = 1;
   return value0;
L168:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L165:;
   if (!((v4tp)==(ECL_SYM("STRING",805)))) { goto L173; }
   if (!(ECL_STRINGP(v1object))) { goto L176; }
   value0 = ecl_make_bool(v5i==ECL_NIL);
   if ((value0)!=ECL_NIL) { goto L179; }
   value0 = L26match_dimensions(v1object, v5i);
   return value0;
L179:;
   cl_env_copy->nvalues = 1;
   return value0;
L176:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L173:;
   if (!((v4tp)==(ECL_SYM("BIT-VECTOR",134)))) { goto L181; }
   if (!(ECL_BIT_VECTOR_P(v1object))) { goto L184; }
   value0 = ecl_make_bool(v5i==ECL_NIL);
   if ((value0)!=ECL_NIL) { goto L187; }
   value0 = L26match_dimensions(v1object, v5i);
   return value0;
L187:;
   cl_env_copy->nvalues = 1;
   return value0;
L184:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L181:;
   if (!((v4tp)==(ECL_SYM("SIMPLE-BASE-STRING",764)))) { goto L189; }
   if (Null(si_base_string_p(v1object))) { goto L192; }
   if (Null(cl_simple_string_p(v1object))) { goto L192; }
   value0 = ecl_make_bool(v5i==ECL_NIL);
   if ((value0)!=ECL_NIL) { goto L196; }
   value0 = L26match_dimensions(v1object, v5i);
   return value0;
L196:;
   cl_env_copy->nvalues = 1;
   return value0;
L192:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L189:;
   if (!((v4tp)==(ECL_SYM("SIMPLE-STRING",771)))) { goto L198; }
   if (Null(cl_simple_string_p(v1object))) { goto L201; }
   value0 = ecl_make_bool(v5i==ECL_NIL);
   if ((value0)!=ECL_NIL) { goto L204; }
   value0 = L26match_dimensions(v1object, v5i);
   return value0;
L204:;
   cl_env_copy->nvalues = 1;
   return value0;
L201:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L198:;
   if (!((v4tp)==(ECL_SYM("SIMPLE-BIT-VECTOR",765)))) { goto L206; }
   if (Null(cl_simple_bit_vector_p(v1object))) { goto L209; }
   value0 = ecl_make_bool(v5i==ECL_NIL);
   if ((value0)!=ECL_NIL) { goto L212; }
   value0 = L26match_dimensions(v1object, v5i);
   return value0;
L212:;
   cl_env_copy->nvalues = 1;
   return value0;
L209:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L206:;
   if (!((v4tp)==(ECL_SYM("SIMPLE-VECTOR",774)))) { goto L214; }
   if (Null(cl_simple_vector_p(v1object))) { goto L217; }
   value0 = ecl_make_bool(v5i==ECL_NIL);
   if ((value0)!=ECL_NIL) { goto L220; }
   value0 = L26match_dimensions(v1object, v5i);
   return value0;
L220:;
   cl_env_copy->nvalues = 1;
   return value0;
L217:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L214:;
   if (!((v4tp)==(ECL_SYM("COMPLEX-ARRAY",1773)))) { goto L222; }
   if (Null(L23complex_array_p(v1object))) { goto L225; }
   if (ecl_endp(v5i)) { goto L228; }
   T0 = ecl_car(v5i);
   if ((T0)==(ECL_SYM("*",18))) { goto L228; }
   T0 = cl_array_element_type(v1object);
   T1 = ecl_car(v5i);
   T2 = cl_upgraded_array_element_type(1, T1);
   if (!((T0)==(T2))) { goto L225; }
   goto L227;
L228:;
L227:;
   T0 = ecl_cdr(v5i);
   value0 = ecl_make_bool(ecl_endp(T0));
   if ((value0)!=ECL_NIL) { goto L232; }
   T0 = ecl_cadr(v5i);
   value0 = L26match_dimensions(v1object, T0);
   return value0;
L232:;
   cl_env_copy->nvalues = 1;
   return value0;
L225:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L222:;
   if (!((v4tp)==(ECL_SYM("SIMPLE-ARRAY",763)))) { goto L234; }
   if (Null(L22simple_array_p(v1object))) { goto L237; }
   if (ecl_endp(v5i)) { goto L240; }
   T0 = ecl_car(v5i);
   if ((T0)==(ECL_SYM("*",18))) { goto L240; }
   T0 = cl_array_element_type(v1object);
   T1 = ecl_car(v5i);
   T2 = cl_upgraded_array_element_type(1, T1);
   if (!((T0)==(T2))) { goto L237; }
   goto L239;
L240:;
L239:;
   T0 = ecl_cdr(v5i);
   value0 = ecl_make_bool(ecl_endp(T0));
   if ((value0)!=ECL_NIL) { goto L244; }
   T0 = ecl_cadr(v5i);
   value0 = L26match_dimensions(v1object, T0);
   return value0;
L244:;
   cl_env_copy->nvalues = 1;
   return value0;
L237:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L234:;
   if (!((v4tp)==(ECL_SYM("ARRAY",96)))) { goto L246; }
   if (!(ECL_ARRAYP(v1object))) { goto L249; }
   if (ecl_endp(v5i)) { goto L252; }
   T0 = ecl_car(v5i);
   if ((T0)==(ECL_SYM("*",18))) { goto L252; }
   T0 = cl_array_element_type(v1object);
   T1 = ecl_car(v5i);
   T2 = cl_upgraded_array_element_type(1, T1);
   if (!((T0)==(T2))) { goto L249; }
   goto L251;
L252:;
L251:;
   T0 = ecl_cdr(v5i);
   value0 = ecl_make_bool(ecl_endp(T0));
   if ((value0)!=ECL_NIL) { goto L256; }
   T0 = ecl_cadr(v5i);
   value0 = L26match_dimensions(v1object, T0);
   return value0;
L256:;
   cl_env_copy->nvalues = 1;
   return value0;
L249:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L246:;
   if (Null(si_get_sysprop(v4tp, VV[9]))) { goto L258; }
   T0 = si_get_sysprop(v4tp, VV[9]);
   T1 = cl_apply(2, T0, v5i);
   value0 = cl_typep(2, v1object, T1);
   return value0;
L258:;
   if (!(ECL_CONSP(v5i))) { goto L260; }
   value0 = L25error_type_specifier(v2type);
   return value0;
L260:;
   v6c = cl_find_class(2, v2type, ECL_NIL);
   if (Null(v6c)) { goto L262; }
   T0 = cl_class_of(v1object);
   value0 = si_subclassp(2, T0, v6c);
   return value0;
L262:;
   value0 = L25error_type_specifier(v2type);
   return value0;
  }
 }
}
/*	function definition for SUBCLASSP                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_subclassp(cl_narg narg, cl_object v1low, cl_object v2high, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = ecl_make_bool((v1low)==(v2high));
  if ((value0)!=ECL_NIL) { goto L2; }
  T0 = ecl_instance_ref((v1low),(7));
  value0 = si_memq(v2high,T0);
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for OF-CLASS-P                            */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
cl_object si_of_class_p(cl_narg narg, cl_object v1object, cl_object v2class, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v3x_class;
  v3x_class = cl_class_of(v1object);
  if (!((v3x_class)==(v2class))) { goto L2; }
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  {
   cl_object v4x_cpl;
   v4x_cpl = (v3x_class)->instance.slots[7];
   if (!(ECL_INSTANCEP(v2class))) { goto L5; }
   value0 = si_memq(v2class,v4x_cpl);
   cl_env_copy->nvalues = 1;
   return value0;
L5:;
   {
    cl_object v5;
    v5 = v4x_cpl;
    goto L10;
L9:;
    {
     cl_object v6c;
     v6c = _ecl_car(v5);
     T0 = (v6c)->instance.slots[3];
     if (!((T0)==(v2class))) { goto L14; }
     value0 = ECL_T;
     cl_env_copy->nvalues = 1;
     return value0;
L14:;
    }
    v5 = _ecl_cdr(v5);
L10:;
    if (Null(v5)) { goto L18; }
    goto L9;
L18:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for NORMALIZE-TYPE                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L27normalize_type(cl_object v1type)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2tp;
   cl_object v3i;
   cl_object v4fd;
   v2tp = ECL_NIL;
   v3i = ECL_NIL;
   v4fd = ECL_NIL;
   if (!(ECL_SYMBOLP(v1type))) { goto L4; }
   v4fd = si_get_sysprop(v1type, VV[9]);
   if (Null(v4fd)) { goto L6; }
   v1type = ecl_function_dispatch(cl_env_copy,v4fd)(0);
   goto TTL;
L6:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = ECL_NIL;
   cl_env_copy->values[0] = v1type;
   return cl_env_copy->values[0];
L4:;
   if (Null(ecl_function_dispatch(cl_env_copy,VV[88])(1, v1type) /*  CLASSP */)) { goto L11; }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = ECL_NIL;
   cl_env_copy->values[0] = v1type;
   return cl_env_copy->values[0];
L11:;
   if (!(ECL_ATOM(v1type))) { goto L13; }
   value0 = L25error_type_specifier(v1type);
   return value0;
L13:;
   v2tp = ecl_car(v1type);
   v3i = ecl_cdr(v1type);
   v4fd = si_get_sysprop(v2tp, VV[9]);
   if (Null(v4fd)) { goto L15; }
   v1type = cl_apply(2, v4fd, v3i);
   goto TTL;
L15:;
   if (!((v2tp)==(ECL_SYM("INTEGER",437)))) { goto L24; }
   T0 = ecl_cadr(v3i);
   if (!(ECL_CONSP(T0))) { goto L24; }
   T0 = ecl_car(v3i);
   T1 = ecl_caadr(v3i);
   T2 = ecl_one_minus(T1);
   T3 = cl_list(2, T0, T2);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = T3;
   cl_env_copy->values[0] = v2tp;
   return cl_env_copy->values[0];
L24:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v3i;
   cl_env_copy->values[0] = v2tp;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for EXPAND-DEFTYPE                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L28expand_deftype(cl_object v1type)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_SYMBOLP(v1type))) { goto L1; }
  {
   cl_object v2fd;
   v2fd = si_get_sysprop(v1type, VV[9]);
   if (Null(v2fd)) { goto L4; }
   v1type = ecl_function_dispatch(cl_env_copy,v2fd)(0);
   goto TTL;
L4:;
   value0 = v1type;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L1:;
  if (!(ECL_CONSP(v1type))) { goto L8; }
  if (!(ECL_SYMBOLP(v1type))) { goto L8; }
  {
   cl_object v3fd;
   T0 = ecl_car(v1type);
   v3fd = si_get_sysprop(T0, VV[9]);
   if (Null(v3fd)) { goto L12; }
   T0 = ecl_cdr(v1type);
   v1type = ecl_function_dispatch(cl_env_copy,v3fd)(1, T0);
   goto TTL;
L12:;
   value0 = v1type;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L8:;
  value0 = v1type;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for ERROR-COERCE                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L29error_coerce(cl_object v1object, cl_object v2type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_error(3, _ecl_static_6, v1object, v2type);
  return value0;
 }
}
/*	function definition for COERCE                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_coerce(cl_object v1object, cl_object v2type)
{
 cl_object T0, T1, T2, T3, T4, T5;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3aux;
   v3aux = ECL_NIL;
   if (Null(cl_typep(2, v1object, v2type))) { goto L2; }
   value0 = v1object;
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
   {
    cl_object v4;
    v4 = L28expand_deftype(v2type);
    value0 = ecl_make_bool(ECL_SYMBOLP(v4));
    if ((value0)!=ECL_NIL) { goto L10; }
    value0 = si_of_class_p(2, v4, ECL_SYM("CLASS",933));
    if ((value0)!=ECL_NIL) { goto L10; }
    T0 = ecl_make_bool(ECL_LISTP(v4));
    goto L8;
L10:;
    T0 = value0;
    goto L8;
L8:;
    if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[44],v4);
    v2type = v4;
   }
   if (!(ECL_ATOM(v2type))) { goto L13; }
   if (!((v2type)==(ECL_T))) { goto L15; }
   value0 = v1object;
   cl_env_copy->nvalues = 1;
   return value0;
L15:;
   if (!((v2type)==(ECL_SYM("LIST",481)))) { goto L18; }
   {
    cl_object v4;
    cl_object v5io;
    cl_object v6l;
    v4 = si_make_seq_iterator(1, v1object);
    v5io = v4;
    v6l = ECL_NIL;
    goto L25;
L24:;
    {
     cl_object v7;
     v7 = si_seq_iterator_next(v1object, v5io);
     T0 = si_seq_iterator_ref(v1object, v5io);
     v6l = CONS(T0,v6l);
     v5io = v7;
    }
L25:;
    if (v5io==ECL_NIL) { goto L30; }
    goto L24;
L30:;
    value0 = v6l;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L18:;
   if (!((v2type)==(ECL_SYM("CHARACTER",222)))) { goto L37; }
   goto L34;
   goto L35;
L37:;
   goto L35;
L35:;
   if (!((v2type)==(ECL_SYM("BASE-CHAR",120)))) { goto L32; }
   goto L33;
L34:;
L33:;
   value0 = cl_character(v1object);
   return value0;
L32:;
   if (!((v2type)==(ECL_SYM("FLOAT",374)))) { goto L40; }
   value0 = cl_float(1, v1object);
   return value0;
L40:;
   if (!((v2type)==(ECL_SYM("SINGLE-FLOAT",778)))) { goto L42; }
   value0 = ecl_make_single_float(ecl_to_float(v1object));
   cl_env_copy->nvalues = 1;
   return value0;
L42:;
   if (!((v2type)==(ECL_SYM("SHORT-FLOAT",756)))) { goto L44; }
   value0 = ecl_make_single_float(ecl_to_float(v1object));
   cl_env_copy->nvalues = 1;
   return value0;
L44:;
   if (!((v2type)==(ECL_SYM("DOUBLE-FLOAT",315)))) { goto L46; }
   value0 = ecl_make_double_float(ecl_to_double(v1object));
   cl_env_copy->nvalues = 1;
   return value0;
L46:;
   if (!((v2type)==(ECL_SYM("LONG-FLOAT",508)))) { goto L48; }
   value0 = ecl_make_double_float(ecl_to_double(v1object));
   cl_env_copy->nvalues = 1;
   return value0;
L48:;
   if (!((v2type)==(ECL_SYM("COMPLEX",241)))) { goto L50; }
   T0 = cl_realpart(v1object);
   T1 = cl_imagpart(v1object);
   value0 = cl_complex(2, T0, T1);
   return value0;
L50:;
   if (!((v2type)==(ECL_SYM("FUNCTION",396)))) { goto L52; }
   value0 = si_coerce_to_function(v1object);
   return value0;
L52:;
   if (Null(ecl_memql(v2type,VV[47]))) { goto L54; }
   value0 = cl_concatenate(2, v2type, v1object);
   return value0;
L54:;
   if (ECL_LISTP(v1object)) { goto L58; }
   if (Null(cl_vector(1, v1object))) { goto L56; }
   goto L57;
L58:;
L57:;
   value0 = cl_concatenate(2, v2type, v1object);
   return value0;
L56:;
   value0 = L29error_coerce(v1object, v2type);
   return value0;
L13:;
   v3aux = ecl_car(v2type);
   if (!((v3aux)==(ECL_SYM("COMPLEX",241)))) { goto L60; }
   if (Null(v2type)) { goto L63; }
   T0 = cl_realpart(v1object);
   T1 = ecl_cadr(v2type);
   T2 = cl_coerce(T0, T1);
   T3 = cl_imagpart(v1object);
   T4 = ecl_cadr(v2type);
   T5 = cl_coerce(T3, T4);
   value0 = cl_complex(2, T2, T5);
   return value0;
L63:;
   T0 = cl_realpart(v1object);
   T1 = cl_imagpart(v1object);
   value0 = cl_complex(2, T0, T1);
   return value0;
L60:;
   if (Null(ecl_memql(v3aux,VV[48]))) { goto L65; }
   v3aux = cl_coerce(v1object, v3aux);
   if ((cl_typep(2, v3aux, v2type))!=ECL_NIL) { goto L69; }
   L29error_coerce(v1object, v2type);
L69:;
   value0 = v3aux;
   cl_env_copy->nvalues = 1;
   return value0;
L65:;
   if (!((v3aux)==(ECL_SYM("AND",87)))) { goto L71; }
   {
    cl_object v7;
    v7 = ecl_cdr(v2type);
    goto L77;
L76:;
    {
     cl_object v8type;
     v8type = ecl_car(v7);
     v3aux = cl_coerce(v3aux, v8type);
    }
    v7 = ecl_cdr(v7);
L77:;
    if (Null(v7)) { goto L85; }
    goto L76;
L85:;
   }
   if ((cl_typep(2, v3aux, v2type))!=ECL_NIL) { goto L87; }
   L29error_coerce(v1object, v2type);
L87:;
   value0 = v3aux;
   cl_env_copy->nvalues = 1;
   return value0;
L71:;
   if (ECL_LISTP(v1object)) { goto L91; }
   if (Null(cl_vector(1, v1object))) { goto L89; }
   goto L90;
L91:;
L90:;
   value0 = cl_concatenate(2, v2type, v1object);
   return value0;
L89:;
   value0 = L29error_coerce(v1object, v2type);
   return value0;
  }
 }
}
/*	function definition for NEW-TYPE-TAG                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L30new_type_tag()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v1;
   v1 = ecl_symbol_value(VV[50]);
   cl_set(VV[50],cl_ash(ecl_symbol_value(VV[50]), ecl_make_fixnum(1)));
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for FIND-REGISTERED-TAG                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L31find_registered_tag(cl_narg narg, cl_object v1type, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2test;
  va_list args; va_start(args,v1type);
  {
   int i = 1;
   if (i >= narg) {
    v2test = (ECL_SYM("EQUAL",335)->symbol.gfdef);
   } else {
    i++;
    v2test = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v3pos;
   {
    cl_object v4;
    v4 = ecl_symbol_value(VV[53]);
    goto L6;
L5:;
    {
     cl_object v5;
     cl_object v6;
     if (ecl_unlikely(ECL_ATOM(v4))) FEtype_error_cons(v4);
     v5 = v4;
     v6 = ECL_CONS_CAR(v5);
     if (Null(v6)) { goto L8; }
     {
      cl_object v7;
      if (ecl_unlikely(ECL_ATOM(v6))) FEtype_error_cons(v6);
      T0 = v6;
      v7 = ECL_CONS_CAR(T0);
      if (Null(ecl_function_dispatch(cl_env_copy,v2test)(2, v1type, v7))) { goto L8; }
      v3pos = v6;
      goto L2;
     }
    }
L8:;
    v4 = ECL_CONS_CDR(v4);
L6:;
    if (v4==ECL_NIL) { goto L19; }
    goto L5;
L19:;
    v3pos = ECL_NIL;
   }
L2:;
   if (Null(v3pos)) { goto L22; }
   value0 = ecl_cdr(v3pos);
   cl_env_copy->nvalues = 1;
   return value0;
L22:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for MAYBE-SAVE-TYPES                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L32maybe_save_types()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_symbol_value(VV[49]))) { goto L1; }
  cl_set(VV[49],ECL_NIL);
  cl_set(VV[53],cl_copy_tree(ecl_symbol_value(VV[53])));
  cl_set(VV[51],cl_copy_tree(ecl_symbol_value(VV[51])));
  value0 = ecl_symbol_value(VV[51]);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for UPDATE-TYPES                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L33update_types(cl_object v1type_mask, cl_object v2new_tag)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  L32maybe_save_types();
  {
   cl_object v3;
   v3 = ecl_symbol_value(VV[53]);
   goto L5;
L4:;
   {
    cl_object v4i;
    v4i = ecl_car(v3);
    T0 = ecl_cdr(v4i);
    T1 = ecl_boole(ECL_BOOLAND,(T0),(v1type_mask));
    if (ecl_zerop(T1)) { goto L9; }
    {
     cl_object v5;
     T0 = ecl_cdr(v4i);
     v5 = ecl_boole(ECL_BOOLIOR,(v2new_tag),(T0));
     (ECL_CONS_CDR(v4i)=v5,v4i);
    }
L9:;
   }
   v3 = ecl_cdr(v3);
L5:;
   if (Null(v3)) { goto L15; }
   goto L4;
L15:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for FIND-TYPE-BOUNDS                      */
/*	optimize speed 1, debug 1, space 1, safety 0                  */
static cl_object L34find_type_bounds(cl_object v1type, cl_object v2in_our_family_p, cl_object v3type___, cl_object v4minimize_super)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v5subtype_tag;
  cl_object v6disjoint_tag;
  cl_object v7supertype_tag;
  v5subtype_tag = ecl_make_fixnum(0);
  v6disjoint_tag = ecl_make_fixnum(0);
  if (Null(v4minimize_super)) { goto L4; }
  v7supertype_tag = ecl_make_fixnum(-1);
  goto L3;
L4:;
  v7supertype_tag = ecl_make_fixnum(0);
L3:;
  {
   cl_object v8;
   v8 = ECL_SYM_VAL(cl_env_copy,VV[53]);
   goto L10;
L9:;
   {
    cl_object v9i;
    v9i = _ecl_car(v8);
    {
     cl_object v10;
     cl_object v11;
     v10 = ECL_CONS_CAR(v9i);
     v11 = ECL_CONS_CDR(v9i);
     if (Null((cl_env_copy->function=v2in_our_family_p)->cfun.entry(1, v10))) { goto L14; }
     if (Null((cl_env_copy->function=v3type___)->cfun.entry(2, v1type, v10))) { goto L18; }
     if (Null(v4minimize_super)) { goto L20; }
     T0 = ecl_boole(ECL_BOOLANDC2,(v11),(v7supertype_tag));
     if (!(ecl_zerop(T0))) { goto L14; }
     v7supertype_tag = v11;
     goto L14;
L20:;
     v7supertype_tag = ecl_boole(ECL_BOOLIOR,(v11),(v7supertype_tag));
     goto L14;
L18:;
     if (Null((cl_env_copy->function=v3type___)->cfun.entry(2, v10, v1type))) { goto L25; }
     v5subtype_tag = ecl_boole(ECL_BOOLIOR,(v11),(v5subtype_tag));
     goto L14;
L25:;
     v6disjoint_tag = ecl_boole(ECL_BOOLIOR,(v6disjoint_tag),(v11));
    }
L14:;
   }
   v8 = _ecl_cdr(v8);
L10:;
   if (Null(v8)) { goto L31; }
   goto L9;
L31:;
  }
  if (!(ecl_number_equalp(v7supertype_tag,ecl_make_fixnum(-1)))) { goto L34; }
  T0 = ecl_make_fixnum(0);
  goto L33;
L34:;
  T1 = ecl_boole(ECL_BOOLIOR,(v6disjoint_tag),(v5subtype_tag));
  T0 = ecl_boole(ECL_BOOLANDC2,(v7supertype_tag),(T1));
L33:;
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = v5subtype_tag;
  cl_env_copy->values[0] = T0;
  return cl_env_copy->values[0];
 }
}
/*	function definition for REGISTER-TYPE                         */
/*	optimize speed 1, debug 1, space 1, safety 0                  */
static cl_object L35register_type(cl_object v1type, cl_object v2in_our_family_p, cl_object v3type___)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 value0 = L31find_registered_tag(1, v1type);
 if ((value0)!=ECL_NIL) { goto L2; }
 {
  cl_object v5;                                   /*  TAG-SUPER       */
  cl_object v6;                                   /*  TAG-SUB         */
  value0 = L34find_type_bounds(v1type, v2in_our_family_p, v3type___, ECL_NIL);
  v5 = value0;
  {
   const int v7 = cl_env_copy->nvalues;
   cl_object v8;
   v8 = (v7<=1)? ECL_NIL : cl_env_copy->values[1];
   v6 = v8;
  }
  {
   cl_object v7tag;
   v7tag = L30new_type_tag();
   T0 = ecl_boole(ECL_BOOLANDC2,(v5),(v6));
   L33update_types(T0, v7tag);
   v7tag = ecl_boole(ECL_BOOLIOR,(v7tag),(v6));
   value0 = L39push_type(v1type, v7tag);
   return value0;
  }
 }
L2:;
 cl_env_copy->nvalues = 1;
 return value0;
}
/*	function definition for REGISTER-MEMBER-TYPE                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L36register_member_type(cl_object v1object)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2pos;
   v2pos = ecl_assql(v1object,ecl_symbol_value(VV[51]));
   {
    cl_object v3;
    if (Null(v2pos)) { goto L4; }
    v3 = ecl_cdr(v2pos);
    goto L2;
L4:;
    v3 = ECL_NIL;
    goto L2;
L2:;
    if (Null(v3)) { goto L6; }
    value0 = v3;
    cl_env_copy->nvalues = 1;
    return value0;
L6:;
    if ((cl_realp(v1object))!=ECL_NIL) { goto L8; }
    value0 = L37simple_member_type(v1object);
    return value0;
L8:;
    if (!(floatp(v1object))) { goto L10; }
    if (!(ecl_zerop(v1object))) { goto L10; }
    T0 = cl_float_sign(1, v1object);
    if (!(ecl_minusp(T0))) { goto L13; }
    value0 = L37simple_member_type(v1object);
    return value0;
L13:;
    T0 = L38number_member_type(v1object);
    T1 = ecl_negate(v1object);
    T2 = L36register_member_type(T1);
    value0 = ecl_boole(ECL_BOOLANDC2,(T0),(T2));
    cl_env_copy->nvalues = 1;
    return value0;
L10:;
    value0 = L38number_member_type(v1object);
    return value0;
   }
  }
 }
}
/*	function definition for SIMPLE-MEMBER-TYPE                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L37simple_member_type(cl_object v1object)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2tag;
   v2tag = L30new_type_tag();
   L32maybe_save_types();
   cl_set(VV[51],cl_acons(v1object, v2tag, ecl_symbol_value(VV[51])));
   {
    cl_object v3;
    v3 = ecl_symbol_value(VV[53]);
    goto L9;
L8:;
    {
     cl_object v4i;
     v4i = ecl_car(v3);
     {
      cl_object v5type;
      v5type = ecl_car(v4i);
      if (Null(cl_typep(2, v1object, v5type))) { goto L13; }
      {
       cl_object v6;
       T0 = ecl_cdr(v4i);
       v6 = ecl_boole(ECL_BOOLIOR,(v2tag),(T0));
       (ECL_CONS_CDR(v4i)=v6,v4i);
      }
     }
L13:;
    }
    v3 = ecl_cdr(v3);
L9:;
    if (Null(v3)) { goto L20; }
    goto L8;
L20:;
   }
   value0 = v2tag;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for NUMBER-MEMBER-TYPE                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L38number_member_type(cl_object v1object)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2base_type;
   cl_object v3type;
   if (!(ECL_FIXNUMP(v1object)||ECL_BIGNUMP(v1object))) { goto L2; }
   v2base_type = ECL_SYM("INTEGER",437);
   goto L1;
L2:;
   v2base_type = cl_type_of(v1object);
L1:;
   v3type = cl_list(3, v2base_type, v1object, v1object);
   value0 = L31find_registered_tag(1, v3type);
   if ((value0)!=ECL_NIL) { goto L6; }
   value0 = L52register_interval_type(v3type);
   return value0;
L6:;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for PUSH-TYPE                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L39push_type(cl_object v1type, cl_object v2tag)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_symbol_value(VV[51]);
   goto L5;
L4:;
   {
    cl_object v4i;
    v4i = ecl_car(v3);
    T0 = ecl_car(v4i);
    if (Null(cl_typep(2, T0, v1type))) { goto L9; }
    T0 = ecl_cdr(v4i);
    v2tag = ecl_boole(ECL_BOOLIOR,(v2tag),(T0));
L9:;
   }
   v3 = ecl_cdr(v3);
L5:;
   if (Null(v3)) { goto L14; }
   goto L4;
L14:;
  }
  T0 = CONS(v1type,v2tag);
  cl_set(VV[53],CONS(T0,ecl_symbol_value(VV[53])));
  value0 = v2tag;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for REGISTER-SATISFIES-TYPE               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L40register_satisfies_type(cl_object v1type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  cl_env_copy->values[0] = ECL_SYM("SATISFIES",735);
  cl_env_copy->nvalues = 1;
  cl_throw(VV[57]);
 }
}
/*	function definition for REGISTER-CLASS                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L43register_class(cl_object v1class)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L31find_registered_tag(1, v1class);
  if ((value0)!=ECL_NIL) { goto L2; }
  {
   cl_object v2name;
   v2name = (cl_env_copy->function=(ECL_SYM("CLASS-NAME",934)->symbol.gfdef))->cfun.entry(1, v1class) /*  CLASS-NAME */;
   if (Null(v2name)) { goto L7; }
   T0 = cl_find_class(2, v2name, ECL_NIL);
   if (!((v1class)==(T0))) { goto L7; }
   value0 = L31find_registered_tag(1, v2name);
   if ((value0)!=ECL_NIL) { goto L11; }
   value0 = L57find_built_in_tag(v2name);
   goto L4;
L11:;
   goto L4;
L7:;
   value0 = ECL_NIL;
   goto L4;
  }
L4:;
  if ((value0)!=ECL_NIL) { goto L2; }
  if ((ecl_function_dispatch(cl_env_copy,ECL_SYM("CLASS-FINALIZED-P",1491))(1, v1class) /*  CLASS-FINALIZED-P */)!=ECL_NIL) { goto L15; }
  cl_env_copy->values[0] = ECL_NIL;
  cl_env_copy->nvalues = 1;
  cl_throw(VV[57]);
L15:;
  value0 = ECL_NIL;
  goto L13;
L13:;
  if ((value0)!=ECL_NIL) { goto L2; }
  {cl_object v2;
   v2 = ECL_NIL;
   v2 = ecl_make_cfun((cl_objectfn_fixed)LC41__g191,ECL_NIL,Cblock,1);
   T0 = v2;
  }
  {cl_object v2;
   v2 = ECL_NIL;
   v2 = ecl_make_cfun((cl_objectfn_fixed)LC42__g192,ECL_NIL,Cblock,2);
   T1 = v2;
  }
  value0 = L35register_type(v1class, T0, T1);
  return value0;
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G191                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC41__g191(cl_object v1c)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_make_bool(ECL_INSTANCEP(v1c));
  if ((value0)!=ECL_NIL) { goto L2; }
  value0 = ecl_make_bool(ECL_SYMBOLP(v1c));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G192                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC42__g192(cl_object v1c1, cl_object v2c2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_SYMBOLP(v1c1))) { goto L1; }
  v1c1 = cl_find_class(2, v1c1, ECL_NIL);
L1:;
  if (!(ECL_SYMBOLP(v2c2))) { goto L4; }
  v2c2 = cl_find_class(2, v2c2, ECL_NIL);
L4:;
  if (Null(v1c1)) { goto L8; }
  if (Null(v2c2)) { goto L8; }
  value0 = si_subclassp(2, v1c1, v2c2);
  return value0;
L8:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for REGISTER-ARRAY-TYPE                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L44register_array_type(cl_object v1type)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;                                  /*  ARRAY-CLASS     */
   cl_object v4;                                  /*  ELT-TYPE        */
   cl_object v5;                                  /*  DIMENSIONS      */
   value0 = L46parse_array_type(v1type);
   v3 = value0;
   {
    const int v6 = cl_env_copy->nvalues;
    cl_object v7;
    v7 = (v6<=1)? ECL_NIL : cl_env_copy->values[1];
    v4 = v7;
    v7 = (v6<=2)? ECL_NIL : cl_env_copy->values[2];
    v5 = v7;
   }
   if (!((v4)==(ECL_SYM("*",18)))) { goto L2; }
   {
    cl_object v6;
    cl_object v7;
    cl_object v8;
    v6 = ecl_symbol_value(VV[32]);
    v7 = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
    v8 = v6;
    {
     cl_object v9;
     cl_object v10;
     v9 = ecl_list1(ECL_NIL);
     v10 = v9;
L11:;
     v7 = _ecl_car(v8);
     {
      cl_object v11;
      v11 = _ecl_cdr(v8);
      if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
      v8 = v11;
     }
     if (ecl_unlikely(ECL_ATOM(v10))) FEtype_error_cons(v10);
     T1 = v10;
     T2 = cl_list(3, v3, v7, v5);
     v10 = ecl_list1(T2);
     (ECL_CONS_CDR(T1)=v10,T1);
     if (!(ecl_endp(v8))) { goto L24; }
     goto L12;
L24:;
     goto L11;
L12:;
     T0 = ecl_cdr(v9);
     goto L4;
    }
   }
L4:;
   T1 = CONS(ECL_SYM("OR",614),T0);
   value0 = L59canonical_type(T1);
   return value0;
L2:;
   {
    cl_object v6;
    v1type = cl_list(3, v3, v4, v5);
    v6 = L31find_registered_tag(1, v1type);
    if (Null(v6)) { goto L30; }
    value0 = v6;
    cl_env_copy->nvalues = 1;
    return value0;
L30:;
    T0 = (VV[62]->symbol.gfdef);
    T1 = (VV[59]->symbol.gfdef);
    value0 = L35register_type(v1type, T0, T1);
    return value0;
   }
  }
 }
}
/*	function definition for FAST-UPGRADED-ARRAY-ELEMENT-TYPE      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L45fast_upgraded_array_element_type(cl_object v1type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!((v1type)==(ECL_SYM("*",18)))) { goto L1; }
  value0 = ECL_SYM("*",18);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (Null(si_memq(v1type,VV[34]))) { goto L3; }
  value0 = v1type;
  cl_env_copy->nvalues = 1;
  return value0;
L3:;
  {
   cl_object v2;
   v2 = ecl_symbol_value(VV[32]);
   goto L8;
L7:;
   {
    cl_object v3other_type;
    v3other_type = ecl_car(v2);
    if (Null(L61fast_subtypep(v1type, v3other_type))) { goto L12; }
    value0 = v3other_type;
    cl_env_copy->nvalues = 1;
    return value0;
L12:;
   }
   v2 = ecl_cdr(v2);
L8:;
   if (Null(v2)) { goto L16; }
   goto L7;
L16:;
   value0 = ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for PARSE-ARRAY-TYPE                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L46parse_array_type(cl_object v1input)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2type;
   cl_object v3name;
   cl_object v4elt_type;
   cl_object v5dims;
   v2type = v1input;
   {
    cl_object v6;
    v6 = v2type;
    if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
    if (Null(v6)) { goto L6; }
    {
     cl_object v7;
     v7 = ECL_CONS_CDR(v6);
     v2type = v7;
     v6 = ECL_CONS_CAR(v6);
    }
L6:;
    v3name = v6;
   }
   if (Null(v2type)) { goto L14; }
   {
    cl_object v6;
    v6 = v2type;
    if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
    if (Null(v6)) { goto L19; }
    {
     cl_object v7;
     v7 = ECL_CONS_CDR(v6);
     v2type = v7;
     v6 = ECL_CONS_CAR(v6);
    }
L19:;
    T0 = v6;
    goto L13;
   }
L14:;
   T0 = ECL_SYM("*",18);
L13:;
   v4elt_type = L45fast_upgraded_array_element_type(T0);
   if (Null(v2type)) { goto L26; }
   {
    cl_object v6;
    v6 = v2type;
    if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
    if (Null(v6)) { goto L31; }
    {
     cl_object v7;
     v7 = ECL_CONS_CDR(v6);
     v2type = v7;
     v6 = ECL_CONS_CAR(v6);
    }
L31:;
    v5dims = v6;
    goto L25;
   }
L26:;
   v5dims = ECL_SYM("*",18);
L25:;
   if (Null(v2type)) { goto L37; }
   cl_error(2, _ecl_static_7, v1input);
L37:;
   if (!(ecl_numberp(v5dims))) { goto L40; }
   if ((cl_L(3, ecl_make_fixnum(-1), v5dims, ecl_make_fixnum(64)))!=ECL_NIL) { goto L42; }
   cl_error(2, _ecl_static_8, v1input);
L42:;
   T0 = ecl_minus(ecl_make_fixnum(64),v5dims);
   v5dims = ecl_nthcdr(ecl_to_size(T0),VV[58]);
   goto L39;
L40:;
   if (!(ECL_CONSP(v5dims))) { goto L39; }
   {
    cl_object v6;
    v6 = v5dims;
    goto L49;
L48:;
    {
     cl_object v7i;
     v7i = ecl_car(v6);
     if ((v7i)==(ECL_SYM("*",18))) { goto L53; }
     if (!(ECL_FIXNUMP(v7i)||ECL_BIGNUMP(v7i))) { goto L57; }
     if ((cl_L(3, ecl_make_fixnum(-1), v7i, ecl_make_fixnum(536870911)))!=ECL_NIL) { goto L53; }
     goto L54;
L57:;
     goto L54;
L54:;
     cl_error(2, _ecl_static_9, v1input);
L53:;
    }
    v6 = ecl_cdr(v6);
L49:;
    if (Null(v6)) { goto L61; }
    goto L48;
L61:;
   }
L39:;
   cl_env_copy->nvalues = 3;
   cl_env_copy->values[2] = v5dims;
   cl_env_copy->values[1] = v4elt_type;
   cl_env_copy->values[0] = v3name;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for ARRAY-TYPE-<=                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L47array_type___(cl_object v1t1, cl_object v2t2)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_car(v1t1);
  T1 = ecl_car(v2t2);
  if (!((T0)==(T1))) { goto L4; }
  T0 = ecl_cadr(v1t1);
  T1 = ecl_cadr(v2t2);
  if ((T0)==(T1)) { goto L1; }
  goto L2;
L4:;
  goto L2;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  {
   cl_object v3;
   cl_object v4;
   v3 = ecl_caddr(v1t1);
   v4 = ecl_caddr(v2t2);
   if (!((v4)==(ECL_SYM("*",18)))) { goto L8; }
   value0 = ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
L8:;
   if (!((v3)==(ECL_SYM("*",18)))) { goto L10; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L10:;
   {
    cl_object v5a;
    cl_object v6b;
    v5a = v3;
    v6b = v4;
    goto L16;
L15:;
    v5a = ecl_cdr(v5a);
    v6b = ecl_cdr(v6b);
L16:;
    if (ecl_endp(v5a)) { goto L21; }
    if (ecl_endp(v6b)) { goto L21; }
    T0 = ecl_car(v6b);
    if ((T0)==(ECL_SYM("*",18))) { goto L25; }
    T0 = ecl_car(v6b);
    T1 = ecl_car(v5a);
    if (!(ecl_eql(T0,T1))) { goto L21; }
    goto L22;
L25:;
L22:;
    goto L15;
L21:;
    if (!(v5a==ECL_NIL)) { goto L28; }
    value0 = ecl_make_bool(v6b==ECL_NIL);
    cl_env_copy->nvalues = 1;
    return value0;
L28:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for ARRAY-TYPE-P                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L48array_type_p(cl_object v1type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_CONSP(v1type))) { goto L2; }
  {
   cl_object v2;
   v2 = ecl_car(v1type);
   if (!((v2)==(ECL_SYM("COMPLEX-ARRAY",1773)))) { goto L9; }
   value0 = VV[60];
   goto L7;
L9:;
   value0 = ECL_NIL;
   goto L7;
L7:;
   if ((value0)!=ECL_NIL) { goto L6; }
   if (!((v2)==(ECL_SYM("SIMPLE-ARRAY",763)))) { goto L12; }
   value0 = VV[61];
   cl_env_copy->nvalues = 1;
   return value0;
L12:;
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
/*	function definition for REGISTER-ELEMENTARY-INTERVAL          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L51register_elementary_interval(cl_object v1type, cl_object v2b)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  v1type = cl_list(2, v1type, v2b);
  T0 = (ECL_SYM("EQUALP",336)->symbol.gfdef);
  value0 = L31find_registered_tag(2, v1type, T0);
  if ((value0)!=ECL_NIL) { goto L4; }
  {
   cl_object v4;                                  /*  TAG-SUPER       */
   cl_object v5;                                  /*  TAG-SUB         */
   {cl_object v6;
    v6 = ECL_NIL;
    v6 = ecl_make_cfun((cl_objectfn_fixed)LC49__g220,ECL_NIL,Cblock,1);
    T0 = v6;
   }
   {cl_object v6;
    v6 = ECL_NIL;
    v6 = ecl_make_cfun((cl_objectfn_fixed)LC50__g221,ECL_NIL,Cblock,2);
    T1 = v6;
   }
   value0 = L34find_type_bounds(v1type, T0, T1, ECL_T);
   v4 = value0;
   {
    const int v6 = cl_env_copy->nvalues;
    cl_object v7;
    v7 = (v6<=1)? ECL_NIL : cl_env_copy->values[1];
    v5 = v7;
   }
   {
    cl_object v6tag;
    v6tag = L30new_type_tag();
    T0 = ecl_boole(ECL_BOOLANDC2,(v4),(v5));
    L33update_types(T0, v6tag);
    v6tag = ecl_boole(ECL_BOOLIOR,(v6tag),(v5));
    value0 = L39push_type(v1type, v6tag);
    return value0;
   }
  }
L4:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G220                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC49__g220(cl_object v1other_type)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_CONSP(v1other_type))) { goto L2; }
  T0 = ecl_cddr(v1other_type);
  value0 = ecl_make_bool(T0==ECL_NIL);
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G221                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC50__g221(cl_object v1i1, cl_object v2i2)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_car(v1i1);
  T1 = ecl_car(v2i2);
  if (!((T0)==(T1))) { goto L2; }
  T0 = ecl_cadr(v2i2);
  T1 = ecl_cadr(v1i1);
  value0 = L53bounds___(T0, T1);
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for REGISTER-INTERVAL-TYPE                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L52register_interval_type(cl_object v1interval)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2i;
   cl_object v3type;
   cl_object v4low;
   cl_object v5high;
   cl_object v6tag_high;
   cl_object v7tag_low;
   cl_object v8tag;
   v2i = v1interval;
   {
    cl_object v9;
    v9 = v2i;
    if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
    if (Null(v9)) { goto L6; }
    {
     cl_object v10;
     v10 = ECL_CONS_CDR(v9);
     v2i = v10;
     v9 = ECL_CONS_CAR(v9);
    }
L6:;
    v3type = v9;
   }
   if (Null(v2i)) { goto L13; }
   {
    cl_object v9;
    v9 = v2i;
    if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
    if (Null(v9)) { goto L18; }
    {
     cl_object v10;
     v10 = ECL_CONS_CDR(v9);
     v2i = v10;
     v9 = ECL_CONS_CAR(v9);
    }
L18:;
    v4low = v9;
    goto L12;
   }
L13:;
   v4low = ECL_SYM("*",18);
L12:;
   if (Null(v2i)) { goto L25; }
   {
    cl_object v9;
    v9 = v2i;
    if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
    if (Null(v9)) { goto L30; }
    {
     cl_object v10;
     v10 = ECL_CONS_CDR(v9);
     v2i = v10;
     v9 = ECL_CONS_CAR(v9);
    }
L30:;
    v5high = v9;
    goto L24;
   }
L25:;
   v5high = ECL_SYM("*",18);
L24:;
   if (!((v5high)==(ECL_SYM("*",18)))) { goto L37; }
   v6tag_high = ecl_make_fixnum(0);
   goto L36;
L37:;
   if (!((v3type)==(ECL_SYM("INTEGER",437)))) { goto L39; }
   if (!(ECL_CONSP(v5high))) { goto L43; }
   T0 = ecl_car(v5high);
   v5high = ecl_ceiling1(T0);
   goto L42;
L43:;
   T0 = ecl_one_plus(v5high);
   v5high = ecl_floor1(T0);
L42:;
   v6tag_high = L51register_elementary_interval(v3type, v5high);
   goto L36;
L39:;
   if (!(ECL_CONSP(v5high))) { goto L45; }
   T0 = ecl_car(v5high);
   v6tag_high = L51register_elementary_interval(v3type, T0);
   goto L36;
L45:;
   T0 = ecl_list1(v5high);
   v6tag_high = L51register_elementary_interval(v3type, T0);
L36:;
   if ((ECL_SYM("*",18))==(v4low)) { goto L51; }
   if (!((v3type)==(ECL_SYM("INTEGER",437)))) { goto L51; }
   if (!(ECL_FIXNUMP(v4low)||ECL_BIGNUMP(v4low))) { goto L49; }
   goto L50;
L51:;
L50:;
   T0 = v4low;
   goto L48;
L49:;
   if (!(ECL_CONSP(v4low))) { goto L54; }
   T1 = ecl_car(v4low);
   T2 = ecl_one_plus(T1);
   T0 = ecl_floor1(T2);
   goto L48;
L54:;
   T0 = ecl_ceiling1(v4low);
L48:;
   v7tag_low = L51register_elementary_interval(v3type, T0);
   v8tag = ecl_boole(ECL_BOOLANDC2,(v7tag_low),(v6tag_high));
   if ((v5high)==(ECL_SYM("*",18))) { goto L57; }
   L39push_type(v1interval, v8tag);
L57:;
   value0 = v8tag;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for BOUNDS-<=                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L53bounds___(cl_object v1b1, cl_object v2b2)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!((v1b1)==(ECL_SYM("*",18)))) { goto L1; }
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (!((v2b2)==(ECL_SYM("*",18)))) { goto L3; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L3:;
  if (!(ECL_CONSP(v1b1))) { goto L5; }
  if (!(ECL_CONSP(v2b2))) { goto L7; }
  T0 = ecl_car(v1b1);
  T1 = ecl_car(v2b2);
  value0 = ecl_make_bool(ecl_number_compare(T0,T1)<=0);
  cl_env_copy->nvalues = 1;
  return value0;
L7:;
  T0 = ecl_car(v1b1);
  value0 = ecl_make_bool(ecl_number_compare(T0,v2b2)<0);
  cl_env_copy->nvalues = 1;
  return value0;
L5:;
  if (!(ECL_CONSP(v2b2))) { goto L9; }
  T0 = ecl_car(v2b2);
  value0 = ecl_make_bool(ecl_number_compare(v1b1,T0)<=0);
  cl_env_copy->nvalues = 1;
  return value0;
L9:;
  value0 = ecl_make_bool(ecl_number_compare(v1b1,v2b2)<=0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for BOUNDS-<                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L54bounds__(cl_object v1b1, cl_object v2b2)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!((v1b1)==(ECL_SYM("*",18)))) { goto L1; }
  {
   bool v3;
   v3 = (v2b2)==(ECL_SYM("*",18));
   value0 = (v3)?ECL_NIL:ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L1:;
  if (!((v2b2)==(ECL_SYM("*",18)))) { goto L3; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L3:;
  if (!(ECL_CONSP(v1b1))) { goto L5; }
  if (!(ECL_CONSP(v2b2))) { goto L7; }
  T0 = ecl_car(v1b1);
  T1 = ecl_car(v2b2);
  value0 = ecl_make_bool(ecl_number_compare(T0,T1)<0);
  cl_env_copy->nvalues = 1;
  return value0;
L7:;
  T0 = ecl_car(v1b1);
  value0 = ecl_make_bool(ecl_number_compare(T0,v2b2)<0);
  cl_env_copy->nvalues = 1;
  return value0;
L5:;
  if (!(ECL_CONSP(v2b2))) { goto L9; }
  T0 = ecl_car(v2b2);
  value0 = ecl_make_bool(ecl_number_compare(v1b1,T0)<=0);
  cl_env_copy->nvalues = 1;
  return value0;
L9:;
  value0 = ecl_make_bool(ecl_number_compare(v1b1,v2b2)<0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for CANONICAL-COMPLEX-TYPE                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L55canonical_complex_type(cl_object v1real_type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((v1real_type)==(ECL_SYM("*",18))) { goto L1; }
  cl_upgraded_complex_part_type(1, v1real_type);
L1:;
  value0 = L31find_registered_tag(1, VV[65]);
  if ((value0)!=ECL_NIL) { goto L4; }
  {
   cl_object v2tag;
   v2tag = L30new_type_tag();
   value0 = L39push_type(VV[65], v2tag);
   return value0;
  }
L4:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for REGISTER-CONS-TYPE                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L56register_cons_type(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v1car_type;
  cl_object v2cdr_type;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1car_type = ECL_SYM("*",18);
   } else {
    i++;
    v1car_type = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v2cdr_type = ECL_SYM("*",18);
   } else {
    i++;
    v2cdr_type = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v3;
   cl_object v4;
   if (!((v1car_type)==(ECL_SYM("*",18)))) { goto L4; }
   v3 = ecl_make_fixnum(-1);
   goto L3;
L4:;
   v3 = L59canonical_type(v1car_type);
L3:;
   if (!((v2cdr_type)==(ECL_SYM("*",18)))) { goto L7; }
   v4 = ecl_make_fixnum(-1);
   goto L6;
L7:;
   v4 = L59canonical_type(v2cdr_type);
L6:;
   if (ecl_zerop(v3)) { goto L11; }
   if (!(ecl_zerop(v4))) { goto L9; }
   goto L10;
L11:;
L10:;
   value0 = ecl_make_fixnum(0);
   cl_env_copy->nvalues = 1;
   return value0;
L9:;
   if (!(ecl_number_equalp(v3,ecl_make_fixnum(-1)))) { goto L13; }
   if (!(ecl_number_equalp(v4,ecl_make_fixnum(-1)))) { goto L13; }
   value0 = L59canonical_type(ECL_SYM("CONS",251));
   return value0;
L13:;
   cl_env_copy->values[0] = ECL_SYM("CONS",251);
   cl_env_copy->nvalues = 1;
   cl_throw(VV[57]);
  }
 }
}
/*	function definition for FIND-BUILT-IN-TAG                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L57find_built_in_tag(cl_object v1name)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2record;
   v2record = ECL_NIL;
   if (!((v1name)==(ECL_T))) { goto L2; }
   value0 = ecl_make_fixnum(-1);
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
   v2record = ecl_gethash_safe(v1name,ecl_symbol_value(VV[67]),v1name);
   if (!((v2record)==(v1name))) { goto L4; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L4:;
   {
    cl_object v3alias;
    cl_object v4tag;
    {
     cl_object v5;
     v5 = v2record;
     if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
     if (Null(v5)) { goto L11; }
     {
      cl_object v6;
      v6 = ECL_CONS_CDR(v5);
      v2record = v6;
      v5 = ECL_CONS_CAR(v5);
     }
L11:;
     v3alias = v5;
    }
    v4tag = ECL_NIL;
    if (Null(v3alias)) { goto L19; }
    v4tag = L59canonical_type(v3alias);
    goto L18;
L19:;
    {
     cl_object v5strict_supertype;
     cl_object v6strict_supertype_tag;
     value0 = ecl_car(v2record);
     if ((value0)!=ECL_NIL) { goto L24; }
     v5strict_supertype = ECL_T;
     goto L22;
L24:;
     v5strict_supertype = value0;
     goto L22;
L22:;
     v6strict_supertype_tag = L59canonical_type(v5strict_supertype);
     v4tag = L30new_type_tag();
     if ((v5strict_supertype)==(ECL_T)) { goto L18; }
     L58extend_type_tag(v4tag, v6strict_supertype_tag);
    }
L18:;
    value0 = L39push_type(v1name, v4tag);
    return value0;
   }
  }
 }
}
/*	function definition for EXTEND-TYPE-TAG                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L58extend_type_tag(cl_object v1tag, cl_object v2minimal_supertype_tag)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_symbol_value(VV[53]);
   goto L4;
L3:;
   {
    cl_object v4type;
    v4type = ecl_car(v3);
    {
     cl_object v5other_tag;
     v5other_tag = ecl_cdr(v4type);
     T0 = ecl_boole(ECL_BOOLANDC2,(v2minimal_supertype_tag),(v5other_tag));
     if (!(ecl_zerop(T0))) { goto L8; }
     {
      cl_object v6;
      v6 = ecl_boole(ECL_BOOLIOR,(v1tag),(v5other_tag));
      (ECL_CONS_CDR(v4type)=v6,v4type);
     }
    }
L8:;
   }
   v3 = ecl_cdr(v3);
L4:;
   if (Null(v3)) { goto L15; }
   goto L3;
L15:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for CANONICAL-TYPE                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L59canonical_type(cl_object v1type)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   v2 = L31find_registered_tag(1, v1type);
   if (Null(v2)) { goto L2; }
   value0 = v2;
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
   if (!((v1type)==(ECL_T))) { goto L4; }
   value0 = ecl_make_fixnum(-1);
   cl_env_copy->nvalues = 1;
   return value0;
L4:;
   if (!((v1type)==(ECL_NIL))) { goto L6; }
   value0 = ecl_make_fixnum(0);
   cl_env_copy->nvalues = 1;
   return value0;
L6:;
   if (!(ECL_SYMBOLP(v1type))) { goto L8; }
   {
    cl_object v3expander;
    v3expander = si_get_sysprop(v1type, VV[9]);
    if (Null(v3expander)) { goto L11; }
    v1type = ecl_function_dispatch(cl_env_copy,v3expander)(0);
    goto TTL;
L11:;
    {
     cl_object v4;
     v4 = L57find_built_in_tag(v1type);
     if (Null(v4)) { goto L16; }
     value0 = v4;
     cl_env_copy->nvalues = 1;
     return value0;
L16:;
     {
      cl_object v5class;
      v5class = cl_find_class(2, v1type, ECL_NIL);
      if (Null(v5class)) { goto L19; }
      value0 = L43register_class(v5class);
      return value0;
L19:;
      cl_env_copy->values[0] = ECL_NIL;
      cl_env_copy->nvalues = 1;
      cl_throw(VV[57]);
     }
    }
   }
L8:;
   if (!(ECL_CONSP(v1type))) { goto L22; }
   {
    cl_object v6;
    v6 = ecl_car(v1type);
    if (!((v6)==(ECL_SYM("AND",87)))) { goto L25; }
    T0 = (ECL_SYM("LOGAND",492)->symbol.gfdef);
    {
     cl_object v7;
     cl_object v8;
     cl_object v9;
     v7 = ecl_cdr(v1type);
     v8 = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
     v9 = v7;
     {
      cl_object v10;
      cl_object v11;
      v10 = ecl_list1(ECL_NIL);
      v11 = v10;
L35:;
      if (!(ecl_endp(v9))) { goto L37; }
      goto L36;
L37:;
      v8 = _ecl_car(v9);
      {
       cl_object v12;
       v12 = _ecl_cdr(v9);
       if (ecl_unlikely(!ECL_LISTP(v12))) FEtype_error_list(v12);
       v9 = v12;
      }
      if (ecl_unlikely(ECL_ATOM(v11))) FEtype_error_cons(v11);
      T2 = v11;
      T3 = L59canonical_type(v8);
      v11 = ecl_list1(T3);
      (ECL_CONS_CDR(T2)=v11,T2);
      goto L35;
L36:;
      T1 = ecl_cdr(v10);
      goto L28;
     }
    }
L28:;
    value0 = cl_apply(2, T0, T1);
    return value0;
L25:;
    if (!((v6)==(ECL_SYM("OR",614)))) { goto L51; }
    T0 = (ECL_SYM("LOGIOR",500)->symbol.gfdef);
    {
     cl_object v7;
     cl_object v8;
     cl_object v9;
     v7 = ecl_cdr(v1type);
     v8 = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
     v9 = v7;
     {
      cl_object v10;
      cl_object v11;
      v10 = ecl_list1(ECL_NIL);
      v11 = v10;
L61:;
      if (!(ecl_endp(v9))) { goto L63; }
      goto L62;
L63:;
      v8 = _ecl_car(v9);
      {
       cl_object v12;
       v12 = _ecl_cdr(v9);
       if (ecl_unlikely(!ECL_LISTP(v12))) FEtype_error_list(v12);
       v9 = v12;
      }
      if (ecl_unlikely(ECL_ATOM(v11))) FEtype_error_cons(v11);
      T2 = v11;
      T3 = L59canonical_type(v8);
      v11 = ecl_list1(T3);
      (ECL_CONS_CDR(T2)=v11,T2);
      goto L61;
L62:;
      T1 = ecl_cdr(v10);
      goto L54;
     }
    }
L54:;
    value0 = cl_apply(2, T0, T1);
    return value0;
L51:;
    if (!((v6)==(ECL_SYM("NOT",584)))) { goto L77; }
    T0 = ecl_cadr(v1type);
    T1 = L59canonical_type(T0);
    value0 = ecl_boole(ECL_BOOLXOR,(T1),ecl_make_fixnum(-1));
    cl_env_copy->nvalues = 1;
    return value0;
L77:;
    if (!((v6)==(ECL_SYM("EQL",334)))) { goto L84; }
    goto L81;
    goto L82;
L84:;
    goto L82;
L82:;
    if (!((v6)==(ECL_SYM("MEMBER",552)))) { goto L79; }
    goto L80;
L81:;
L80:;
    T0 = (ECL_SYM("LOGIOR",500)->symbol.gfdef);
    {
     cl_object v7;
     cl_object v8;
     cl_object v9;
     v7 = ecl_cdr(v1type);
     v8 = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
     v9 = v7;
     {
      cl_object v10;
      cl_object v11;
      v10 = ecl_list1(ECL_NIL);
      v11 = v10;
L95:;
      if (!(ecl_endp(v9))) { goto L97; }
      goto L96;
L97:;
      v8 = _ecl_car(v9);
      {
       cl_object v12;
       v12 = _ecl_cdr(v9);
       if (ecl_unlikely(!ECL_LISTP(v12))) FEtype_error_list(v12);
       v9 = v12;
      }
      if (ecl_unlikely(ECL_ATOM(v11))) FEtype_error_cons(v11);
      T2 = v11;
      T3 = L36register_member_type(v8);
      v11 = ecl_list1(T3);
      (ECL_CONS_CDR(T2)=v11,T2);
      goto L95;
L96:;
      T1 = ecl_cdr(v10);
      goto L88;
     }
    }
L88:;
    value0 = cl_apply(2, T0, T1);
    return value0;
L79:;
    if (!((v6)==(ECL_SYM("SATISFIES",735)))) { goto L111; }
    value0 = L40register_satisfies_type(v1type);
    return value0;
L111:;
    if (!((v6)==(ECL_SYM("INTEGER",437)))) { goto L118; }
    goto L115;
    goto L116;
L118:;
    goto L116;
L116:;
    if (!((v6)==(ECL_SYM("SINGLE-FLOAT",778)))) { goto L122; }
    goto L115;
    goto L120;
L122:;
    goto L120;
L120:;
    if (!((v6)==(ECL_SYM("DOUBLE-FLOAT",315)))) { goto L126; }
    goto L115;
    goto L124;
L126:;
    goto L124;
L124:;
    if (!((v6)==(ECL_SYM("RATIO",686)))) { goto L113; }
    goto L114;
L115:;
L114:;
    value0 = L52register_interval_type(v1type);
    return value0;
L113:;
    if (!((v6)==(ECL_SYM("FLOAT",374)))) { goto L129; }
    T0 = ecl_cdr(v1type);
    T1 = CONS(ECL_SYM("SINGLE-FLOAT",778),T0);
    T2 = ecl_cdr(v1type);
    T3 = CONS(ECL_SYM("DOUBLE-FLOAT",315),T2);
    v1type = cl_list(3, ECL_SYM("OR",614), T1, T3);
    goto TTL;
L129:;
    if (!((v6)==(ECL_SYM("REAL",703)))) { goto L134; }
    T0 = ecl_cdr(v1type);
    T1 = CONS(ECL_SYM("INTEGER",437),T0);
    T2 = ecl_cdr(v1type);
    T3 = CONS(ECL_SYM("RATIO",686),T2);
    T4 = ecl_cdr(v1type);
    T5 = CONS(ECL_SYM("SINGLE-FLOAT",778),T4);
    T6 = ecl_cdr(v1type);
    T7 = CONS(ECL_SYM("DOUBLE-FLOAT",315),T6);
    v1type = cl_list(5, ECL_SYM("OR",614), T1, T3, T5, T7);
    goto TTL;
L134:;
    if (!((v6)==(ECL_SYM("RATIONAL",687)))) { goto L139; }
    T0 = ecl_cdr(v1type);
    T1 = CONS(ECL_SYM("INTEGER",437),T0);
    T2 = ecl_cdr(v1type);
    T3 = CONS(ECL_SYM("RATIO",686),T2);
    v1type = cl_list(3, ECL_SYM("OR",614), T1, T3);
    goto TTL;
L139:;
    if (!((v6)==(ECL_SYM("COMPLEX",241)))) { goto L144; }
    value0 = L57find_built_in_tag(v1type);
    if ((value0)!=ECL_NIL) { goto L147; }
    T0 = ecl_cadr(v1type);
    value0 = L55canonical_complex_type(T0);
    return value0;
L147:;
    cl_env_copy->nvalues = 1;
    return value0;
L144:;
    if (!((v6)==(ECL_SYM("CONS",251)))) { goto L149; }
    T0 = (VV[66]->symbol.gfdef);
    T1 = ecl_cdr(v1type);
    value0 = cl_apply(2, T0, T1);
    return value0;
L149:;
    if (!((v6)==(ECL_SYM("ARRAY",96)))) { goto L152; }
    T0 = ecl_cdr(v1type);
    T1 = CONS(ECL_SYM("COMPLEX-ARRAY",1773),T0);
    T2 = L44register_array_type(T1);
    T3 = ecl_cdr(v1type);
    T4 = CONS(ECL_SYM("SIMPLE-ARRAY",763),T3);
    T5 = L44register_array_type(T4);
    value0 = ecl_boole(ECL_BOOLIOR,(T2),(T5));
    cl_env_copy->nvalues = 1;
    return value0;
L152:;
    if (!((v6)==(ECL_SYM("COMPLEX-ARRAY",1773)))) { goto L159; }
    goto L156;
    goto L157;
L159:;
    goto L157;
L157:;
    if (!((v6)==(ECL_SYM("SIMPLE-ARRAY",763)))) { goto L154; }
    goto L155;
L156:;
L155:;
    value0 = L44register_array_type(v1type);
    return value0;
L154:;
    if (!((v6)==(ECL_SYM("FUNCTION",396)))) { goto L162; }
    v1type = ECL_SYM("FUNCTION",396);
    goto TTL;
L162:;
    {
     cl_object v7expander;
     T0 = ecl_car(v1type);
     v7expander = si_get_sysprop(T0, VV[9]);
     if (Null(v7expander)) { goto L167; }
     T0 = ecl_cdr(v1type);
     v1type = cl_apply(2, v7expander, T0);
     goto TTL;
L167:;
     T0 = ecl_car(v1type);
     if ((ecl_assql(T0,ecl_symbol_value(VV[53])))!=ECL_NIL) { goto L171; }
     cl_env_copy->values[0] = ECL_NIL;
     cl_env_copy->nvalues = 1;
     cl_throw(VV[57]);
L171:;
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
L22:;
   if (Null(ecl_function_dispatch(cl_env_copy,VV[88])(1, v1type) /*  CLASSP */)) { goto L174; }
   value0 = L43register_class(v1type);
   return value0;
L174:;
   if (Null(cl_fboundp(VV[75]))) { goto L176; }
   if (Null(ecl_function_dispatch(cl_env_copy,VV[75])(1, v1type) /*  FUNCTION-TYPE-P */)) { goto L176; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[100])(1, v1type) /*  REGISTER-FUNCTION-TYPE */;
   return value0;
L176:;
   if (Null(cl_fboundp(VV[76]))) { goto L179; }
   if (Null(ecl_function_dispatch(cl_env_copy,VV[76])(1, v1type) /*  VALUES-TYPE-P */)) { goto L179; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[101])(1, v1type) /*  REGISTER-VALUES-TYPE */;
   return value0;
L179:;
   value0 = L25error_type_specifier(v1type);
   return value0;
  }
 }
}
/*	function definition for SAFE-CANONICAL-TYPE                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L60safe_canonical_type(cl_object volatile v1type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = VV[57];
  if (ecl_frs_push(cl_env_copy,value0)) {         /*  BEGIN CATCH 1   */
   value0 = cl_env_copy->values[0];
  } else {
   value0 = L59canonical_type(v1type);
  }
  ecl_frs_pop(cl_env_copy);                       /*  END CATCH 1     */
  return value0;
 }
}
/*	function definition for FAST-SUBTYPEP                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L61fast_subtypep(cl_object v1t1, cl_object v2t2)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!((v1t1)==(v2t2))) { goto L1; }
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = ECL_T;
  cl_env_copy->values[0] = ECL_T;
  return cl_env_copy->values[0];
L1:;
  {
   cl_object v3tag1;
   cl_object v4tag2;
   v3tag1 = L60safe_canonical_type(v1t1);
   v4tag2 = L60safe_canonical_type(v2t2);
   if (!(ecl_numberp(v3tag1))) { goto L5; }
   if (!(ecl_numberp(v4tag2))) { goto L5; }
   T0 = L60safe_canonical_type(v1t1);
   T1 = L60safe_canonical_type(v2t2);
   T2 = ecl_boole(ECL_BOOLANDC2,(T0),(T1));
   {
    bool v5;
    v5 = ecl_zerop(T2);
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = ECL_T;
    cl_env_copy->values[0] = ecl_make_bool(v5);
    return cl_env_copy->values[0];
   }
L5:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = ECL_NIL;
   cl_env_copy->values[0] = ECL_NIL;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for SUBTYPEP                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_subtypep(cl_narg narg, cl_object v1t1, cl_object v2t2, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v3env;
  va_list args; va_start(args,v2t2);
  {
   int i = 2;
   if (i >= narg) {
    v3env = ECL_NIL;
   } else {
    i++;
    v3env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (!((v1t1)==(v2t2))) { goto L2; }
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = ECL_T;
  cl_env_copy->values[0] = ECL_T;
  return cl_env_copy->values[0];
L2:;
  if (!(ECL_INSTANCEP(v1t1))) { goto L4; }
  if (!(ECL_INSTANCEP(v2t2))) { goto L4; }
  if (Null(ecl_function_dispatch(cl_env_copy,VV[88])(1, v1t1) /*  CLASSP */)) { goto L4; }
  if (Null(ecl_function_dispatch(cl_env_copy,VV[88])(1, v2t2) /*  CLASSP */)) { goto L4; }
  T0 = si_subclassp(2, v1t1, v2t2);
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = ECL_T;
  cl_env_copy->values[0] = T0;
  return cl_env_copy->values[0];
L4:;
  {
   cl_object v4cache;
   uint8_t v5hash;
   cl_object v6elt;
   v4cache = ecl_symbol_value(VV[4]);
   T0 = si_hash_eql(2, v1t1, v2t2);
   v5hash = ecl_to_uint8_t(ecl_boole(ECL_BOOLAND,(T0),(ecl_make_fixnum(255))));
   {
    cl_fixnum v7;
    if (ecl_unlikely(((cl_fixnum)(v5hash))>=(v4cache)->vector.dim))
           FEwrong_index(ECL_NIL,v4cache,-1,ecl_make_fixnum((cl_fixnum)(v5hash)),(v4cache)->vector.dim);
    v7 = (cl_fixnum)(v5hash);
    v6elt = ecl_aref_unsafe(v4cache,v7);
   }
   if (Null(v6elt)) { goto L15; }
   T0 = ecl_caar(v6elt);
   if (!((T0)==(v1t1))) { goto L15; }
   T0 = ecl_cdar(v6elt);
   if (!((T0)==(v2t2))) { goto L15; }
   v6elt = ecl_cdr(v6elt);
   T0 = ecl_car(v6elt);
   T1 = ecl_cdr(v6elt);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = T1;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
L15:;
   ecl_bds_push(cl_env_copy,VV[50]);              /*  *HIGHEST-TYPE-TAG* */
   ecl_bds_bind(cl_env_copy,VV[49],ECL_T);        /*  *SAVE-TYPES-DATABASE* */
   ecl_bds_push(cl_env_copy,VV[51]);              /*  *MEMBER-TYPES*  */
   ecl_bds_push(cl_env_copy,VV[53]);              /*  *ELEMENTARY-TYPES* */
   {
    cl_object v8;                                 /*  TEST            */
    cl_object v9;                                 /*  CONFIDENT       */
    value0 = L61fast_subtypep(v1t1, v2t2);
    v8 = value0;
    {
     const int v10 = cl_env_copy->nvalues;
     cl_object v11;
     v11 = (v10<=1)? ECL_NIL : cl_env_copy->values[1];
     v9 = v11;
    }
    {
     uint8_t v10;
     if (ecl_unlikely(((cl_fixnum)(v5hash))>=(v4cache)->vector.dim))
           FEwrong_index(ECL_NIL,v4cache,-1,ecl_make_fixnum((cl_fixnum)(v5hash)),(v4cache)->vector.dim);
     v10 = v5hash;
     T0 = CONS(v1t1,v2t2);
     T1 = cl_listX(3, T0, v8, v9);
     ecl_aset_unsafe(v4cache,(cl_fixnum)(v10),T1);
    }
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = v9;
    cl_env_copy->values[0] = v8;
    ecl_bds_unwind_n(cl_env_copy,4);
    return cl_env_copy->values[0];
   }
  }
 }
}
/*	function definition for FAST-TYPE=                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L62fast_type_(cl_object v1t1, cl_object v2t2)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!((v1t1)==(v2t2))) { goto L1; }
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = ECL_T;
  cl_env_copy->values[0] = ECL_T;
  return cl_env_copy->values[0];
L1:;
  {
   cl_object v3tag1;
   cl_object v4tag2;
   v3tag1 = L60safe_canonical_type(v1t1);
   v4tag2 = L60safe_canonical_type(v2t2);
   if (!(ecl_numberp(v3tag1))) { goto L5; }
   if (!(ecl_numberp(v4tag2))) { goto L5; }
   T0 = L60safe_canonical_type(v1t1);
   T1 = L60safe_canonical_type(v2t2);
   {
    bool v5;
    v5 = ecl_number_equalp(T0,T1);
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = ECL_T;
    cl_env_copy->values[0] = ecl_make_bool(v5);
    return cl_env_copy->values[0];
   }
L5:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = ECL_NIL;
   cl_env_copy->values[0] = ECL_NIL;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for TYPE=                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L63type_(cl_object v1t1, cl_object v2t2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   v3 = ecl_symbol_value(VV[50]);
   v4 = ecl_symbol_value(VV[51]);
   v5 = ecl_symbol_value(VV[53]);
   ecl_bds_bind(cl_env_copy,VV[50],v3);           /*  *HIGHEST-TYPE-TAG* */
   ecl_bds_bind(cl_env_copy,VV[49],ECL_T);        /*  *SAVE-TYPES-DATABASE* */
   ecl_bds_bind(cl_env_copy,VV[51],v4);           /*  *MEMBER-TYPES*  */
   ecl_bds_bind(cl_env_copy,VV[53],v5);           /*  *ELEMENTARY-TYPES* */
   value0 = L62fast_type_(v1t1, v2t2);
   ecl_bds_unwind_n(cl_env_copy,4);
   return value0;
  }
 }
}

#include "lsp/predlib.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclyAfyXkZ7_AC5xWE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:LSP;PREDLIB.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclyAfyXkZ7_AC5xWE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[80]);                           /*  CONSTANTLY-T    */
 ecl_cmp_defun(VV[81]);                           /*  CONSTANTLY-NIL  */
 (void)0; /* No entry created for CONSTANTLY */
 si_Xmake_special(VV[4]);
 cl_set(VV[4],si_make_vector(ECL_T, ecl_make_fixnum(256), ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0)));
 si_Xmake_special(VV[5]);
 cl_set(VV[5],si_make_vector(ECL_T, ecl_make_fixnum(128), ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0)));
 ecl_cmp_defun(VV[82]);                           /*  SUBTYPEP-CLEAR-CACHE */
 ecl_cmp_defun(VV[83]);                           /*  CREATE-TYPE-NAME */
 (void)0; /* No entry created for DO-DEFTYPE */
 ecl_cmp_defmacro(VV[84]);                        /*  DEFTYPE         */
 si_do_deftype(3, ECL_SYM("BOOLEAN",155), VVtemp[0], VVtemp[1]);
 si_do_deftype(3, VV[15], VVtemp[2], VVtemp[3]);
 si_do_deftype(3, ECL_SYM("FIXNUM",372), VVtemp[4], VVtemp[5]);
 si_do_deftype(3, ECL_SYM("BIGNUM",122), VVtemp[6], VVtemp[7]);
 si_do_deftype(3, ECL_SYM("BYTE8",1330), VVtemp[8], VVtemp[9]);
 si_do_deftype(3, ECL_SYM("INTEGER8",1335), VVtemp[10], VVtemp[11]);
 si_do_deftype(3, ECL_SYM("BYTE16",1331), VVtemp[12], VVtemp[13]);
 si_do_deftype(3, ECL_SYM("INTEGER16",1336), VVtemp[14], VVtemp[15]);
 si_do_deftype(3, ECL_SYM("BYTE32",1332), VVtemp[16], VVtemp[17]);
 si_do_deftype(3, ECL_SYM("INTEGER32",1337), VVtemp[18], VVtemp[19]);
 si_do_deftype(3, ECL_SYM("BYTE64",1333), VVtemp[20], VVtemp[21]);
 si_do_deftype(3, ECL_SYM("INTEGER64",1338), VVtemp[22], VVtemp[23]);
 si_do_deftype(3, ECL_SYM("CL-FIXNUM",1582), VVtemp[24], VVtemp[25]);
 si_do_deftype(3, ECL_SYM("CL-INDEX",1583), VVtemp[26], VVtemp[27]);
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC7real,ECL_NIL,Cblock);
  T0 = v1;
 }
 si_do_deftype(3, ECL_SYM("REAL",703), VVtemp[28], T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC8short_float,ECL_NIL,Cblock);
  T0 = v1;
 }
 si_do_deftype(3, ECL_SYM("SHORT-FLOAT",756), VVtemp[29], T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC9long_float,ECL_NIL,Cblock);
  T0 = v1;
 }
 si_do_deftype(3, ECL_SYM("LONG-FLOAT",508), VVtemp[30], T0);
 }
 si_do_deftype(3, ECL_SYM("BIT",123), VVtemp[31], VVtemp[32]);
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC10mod,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 si_do_deftype(3, ECL_SYM("MOD",560), VVtemp[33], T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC11signed_byte,ECL_NIL,Cblock);
  T0 = v1;
 }
 si_do_deftype(3, ECL_SYM("SIGNED-BYTE",761), VVtemp[34], T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC12unsigned_byte,ECL_NIL,Cblock);
  T0 = v1;
 }
 si_do_deftype(3, ECL_SYM("UNSIGNED-BYTE",885), VVtemp[35], T0);
 }
 si_do_deftype(3, ECL_SYM("NULL",605), VVtemp[36], VVtemp[37]);
 si_do_deftype(3, ECL_SYM("SEQUENCE",741), VVtemp[38], VVtemp[39]);
 si_do_deftype(3, ECL_SYM("LIST",481), VVtemp[40], VVtemp[41]);
 si_do_deftype(3, VV[19], VVtemp[42], VVtemp[43]);
 si_do_deftype(3, ECL_SYM("PROPERTY-LIST",1658), VVtemp[44], VVtemp[45]);
 si_do_deftype(3, ECL_SYM("ATOM",119), VVtemp[46], VVtemp[47]);
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC13vector,ECL_NIL,Cblock);
  T0 = v1;
 }
 si_do_deftype(3, ECL_SYM("VECTOR",898), VVtemp[48], T0);
 }
 si_do_deftype(3, ECL_SYM("EXTENDED-CHAR",346), VVtemp[49], VVtemp[50]);
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC14string,ECL_NIL,Cblock);
  T0 = v1;
 }
 si_do_deftype(3, ECL_SYM("STRING",805), VVtemp[51], T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC15base_string,ECL_NIL,Cblock);
  T0 = v1;
 }
 si_do_deftype(3, ECL_SYM("BASE-STRING",121), VVtemp[52], T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC16extended_string,ECL_NIL,Cblock);
  T0 = v1;
 }
 si_do_deftype(3, ECL_SYM("EXTENDED-STRING",1677), VVtemp[53], T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC17bit_vector,ECL_NIL,Cblock);
  T0 = v1;
 }
 si_do_deftype(3, ECL_SYM("BIT-VECTOR",134), VVtemp[54], T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC18simple_vector,ECL_NIL,Cblock);
  T0 = v1;
 }
 si_do_deftype(3, ECL_SYM("SIMPLE-VECTOR",774), VVtemp[55], T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC19simple_string,ECL_NIL,Cblock);
  T0 = v1;
 }
 si_do_deftype(3, ECL_SYM("SIMPLE-STRING",771), VVtemp[56], T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC20simple_base_string,ECL_NIL,Cblock);
  T0 = v1;
 }
 si_do_deftype(3, ECL_SYM("SIMPLE-BASE-STRING",764), VVtemp[57], T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC21simple_bit_vector,ECL_NIL,Cblock);
  T0 = v1;
 }
 si_do_deftype(3, ECL_SYM("SIMPLE-BIT-VECTOR",765), VVtemp[58], T0);
 }
 si_do_deftype(3, ECL_SYM("ARRAY-INDEX",1771), VVtemp[59], VVtemp[60]);
 ecl_cmp_defun(VV[85]);                           /*  SIMPLE-ARRAY-P  */
 ecl_cmp_defun(VV[86]);                           /*  COMPLEX-ARRAY-P */
 si_Xmake_constant(VV[30], VVtemp[61]);
 {
  cl_object T0, T1;
 {
  cl_object v1;
  v1 = ecl_symbol_value(VV[30]);
  goto L109;
L108:;
  {
   cl_object v2l;
   v2l = ecl_car(v1);
   T0 = ecl_car(v2l);
   T1 = ecl_cdr(v2l);
   si_put_sysprop(T0, VV[31], T1);
  }
  v1 = ecl_cdr(v1);
L109:;
  if (Null(v1)) { goto L116; }
  goto L108;
L116:;
 }
 }
 si_Xmake_constant(VV[32], VVtemp[62]);
 (void)0; /* No entry created for UPGRADED-ARRAY-ELEMENT-TYPE */
 (void)0; /* No entry created for UPGRADED-COMPLEX-PART-TYPE */
 (void)0; /* No entry created for IN-INTERVAL-P */
 (void)0; /* No entry created for ERROR-TYPE-SPECIFIER */
 (void)0; /* No entry created for MATCH-DIMENSIONS */
 (void)0; /* No entry created for TYPEP */
 (void)0; /* No entry created for SUBCLASSP */
 (void)0; /* No entry created for OF-CLASS-P */
 ecl_cmp_defun(VV[87]);                           /*  NORMALIZE-TYPE  */
 ecl_cmp_defun(VV[89]);                           /*  EXPAND-DEFTYPE  */
 ecl_cmp_defun(VV[90]);                           /*  ERROR-COERCE    */
 (void)0; /* No entry created for COERCE */
 si_Xmake_special(VV[49]);
 cl_set(VV[49],ECL_NIL);
 si_Xmake_special(VV[50]);
 cl_set(VV[50],ecl_make_fixnum(1));
 si_Xmake_special(VV[51]);
 cl_set(VV[51],ECL_NIL);
 si_Xmake_special(VV[52]);
 cl_set(VV[52],ecl_make_fixnum(1));
 si_Xmake_special(VV[53]);
 cl_set(VV[53],ECL_NIL);
 (void)0; /* No entry created for NEW-TYPE-TAG */
 (void)0; /* No entry created for FIND-REGISTERED-TAG */
 (void)0; /* No entry created for MAYBE-SAVE-TYPES */
 ecl_cmp_defun(VV[91]);                           /*  UPDATE-TYPES    */
 (void)0; /* No entry created for FIND-TYPE-BOUNDS */
 (void)0; /* No entry created for REGISTER-TYPE */
 ecl_cmp_defun(VV[92]);                           /*  REGISTER-MEMBER-TYPE */
 (void)0; /* No entry created for SIMPLE-MEMBER-TYPE */
 ecl_cmp_defun(VV[93]);                           /*  NUMBER-MEMBER-TYPE */
 (void)0; /* No entry created for PUSH-TYPE */
 (void)0; /* No entry created for REGISTER-SATISFIES-TYPE */
 (void)0; /* No entry created for REGISTER-CLASS */
 (void)0; /* No entry created for REGISTER-ARRAY-TYPE */
 (void)0; /* No entry created for FAST-UPGRADED-ARRAY-ELEMENT-TYPE */
 (void)0; /* No entry created for PARSE-ARRAY-TYPE */
 ecl_cmp_defun(VV[94]);                           /*  ARRAY-TYPE-<=   */
 ecl_cmp_defun(VV[95]);                           /*  ARRAY-TYPE-P    */
 (void)0; /* No entry created for REGISTER-ELEMENTARY-INTERVAL */
 (void)0; /* No entry created for REGISTER-INTERVAL-TYPE */
 ecl_cmp_defun(VV[96]);                           /*  BOUNDS-<=       */
 ecl_cmp_defun(VV[97]);                           /*  BOUNDS-<        */
 (void)0; /* No entry created for CANONICAL-COMPLEX-TYPE */
 ecl_cmp_defun(VV[98]);                           /*  REGISTER-CONS-TYPE */
 {
  cl_object T0, T1;
 T0 = cl_make_hash_table(4, ECL_SYM("TEST",1316), ECL_SYM("EQ",333), ECL_SYM("SIZE",1308), ecl_make_fixnum(128));
 T1 = si_hash_table_fill(T0, VVtemp[63]);
 si_Xmake_constant(VV[67], T1);
 }
 (void)0; /* No entry created for FIND-BUILT-IN-TAG */
 (void)0; /* No entry created for EXTEND-TYPE-TAG */
 ecl_cmp_defun(VV[99]);                           /*  CANONICAL-TYPE  */
 ecl_cmp_defun(VV[102]);                          /*  SAFE-CANONICAL-TYPE */
 (void)0; /* No entry created for FAST-SUBTYPEP */
 (void)0; /* No entry created for SUBTYPEP */
 (void)0; /* No entry created for FAST-TYPE= */
 ecl_cmp_defun(VV[103]);                          /*  TYPE=           */
}
