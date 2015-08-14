/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPENV-FUN.LSP                                */
#include <ecl/ecl-cmp.h>
#include "cmp/cmpenv-fun.eclh"
/*	function definition for FUNCTION-ARG-TYPES                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1function_arg_types(cl_object v1arg_types)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2types;
   v2types = ECL_NIL;
   {
    cl_object v3al;
    value0 = ecl_make_bool(ECL_FIXNUMP(v1arg_types));
    if ((value0)!=ECL_NIL) { goto L7; }
    value0 = ecl_make_bool(ECL_CHARACTERP(v1arg_types));
    if ((value0)!=ECL_NIL) { goto L7; }
    T1 = ecl_make_bool(floatp(v1arg_types));
    goto L5;
L7:;
    T1 = value0;
    goto L5;
L5:;
    T0 = Null(T1)?ECL_T:ECL_NIL;
    if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("OBJECT",2014),v1arg_types);
    v3al = v1arg_types;
    goto L12;
L11:;
    T0 = ecl_car(v3al);
    v2types = CONS(T0,v2types);
    {
     cl_object v4;
     v4 = ecl_cdr(v3al);
     value0 = ecl_make_bool(ECL_FIXNUMP(v4));
     if ((value0)!=ECL_NIL) { goto L23; }
     value0 = ecl_make_bool(ECL_CHARACTERP(v4));
     if ((value0)!=ECL_NIL) { goto L23; }
     T1 = ecl_make_bool(floatp(v4));
     goto L21;
L23:;
     T1 = value0;
     goto L21;
L21:;
     T0 = Null(T1)?ECL_T:ECL_NIL;
     if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("OBJECT",2014),v4);
     v3al = v4;
    }
L12:;
    if (ecl_endp(v3al)) { goto L26; }
    {
     cl_object v4;
     v4 = ecl_car(v3al);
     if (!((v4)==(ECL_SYM("&OPTIONAL",11)))) { goto L32; }
     goto L26;
     goto L30;
L32:;
     goto L30;
L30:;
     if (!((v4)==(ECL_SYM("&REST",12)))) { goto L36; }
     goto L26;
     goto L34;
L36:;
     goto L34;
L34:;
     if (!((v4)==(ECL_SYM("&KEY",10)))) { goto L39; }
     goto L26;
     goto L27;
L39:;
     goto L27;
    }
L27:;
    goto L11;
L26:;
    value0 = cl_nreverse(v2types);
    return value0;
   }
  }
 }
}
/*	function definition for PROCLAIM-FUNCTION                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2proclaim_function(cl_object v1fname, cl_object v2decl)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(si_valid_function_name_p(v1fname))) { goto L1; }
  {
   cl_object v3arg_types;
   cl_object v4return_types;
   cl_object v5l;
   v3arg_types = ECL_SYM("*",18);
   v4return_types = ECL_SYM("*",18);
   v5l = v2decl;
   {
    cl_object v6;
    v6 = ecl_make_bool(v5l==ECL_NIL);
    if (Null(v6)) { goto L8; }
    goto L6;
L8:;
    if (!(ECL_CONSP(v5l))) { goto L10; }
    {
     cl_object v7;
     v7 = v5l;
     if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
     if (Null(v7)) { goto L16; }
     {
      cl_object v8;
      v8 = ECL_CONS_CDR(v7);
      v5l = v8;
      v7 = ECL_CONS_CAR(v7);
     }
L16:;
     v3arg_types = v7;
    }
    goto L6;
L10:;
    (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(3, _ecl_static_1, v1fname, v2decl) /*  WARN */;
   }
L6:;
   {
    cl_object v6;
    v6 = ecl_make_bool(v5l==ECL_NIL);
    if (Null(v6)) { goto L24; }
    goto L22;
L24:;
    if (ECL_ATOM(v5l)) { goto L28; }
    if (Null(ecl_cdr(v5l))) { goto L26; }
    goto L27;
L28:;
L27:;
    (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(3, _ecl_static_1, v1fname, v2decl) /*  WARN */;
    goto L22;
L26:;
    v4return_types = ecl_car(v5l);
   }
L22:;
   if (!((v3arg_types)==(ECL_NIL))) { goto L31; }
   v3arg_types = VV[4];
L31:;
   if (!((v3arg_types)==(ECL_SYM("*",18)))) { goto L35; }
   si_rem_sysprop(v1fname, VV[5]);
   goto L34;
L35:;
   si_put_sysprop(v1fname, VV[5], v3arg_types);
L34:;
   if (!(ecl_equalp(v4return_types,ECL_SYM("*",18)))) { goto L42; }
   goto L39;
   goto L40;
L42:;
   goto L40;
L40:;
   if (!(ecl_equalp(v4return_types,VV[7]))) { goto L37; }
   goto L38;
L39:;
L38:;
   value0 = si_rem_sysprop(v1fname, VV[9]);
   return value0;
L37:;
   value0 = si_put_sysprop(v1fname, VV[9], v4return_types);
   return value0;
  }
L1:;
  value0 = (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(3, _ecl_static_1, v1fname, v2decl) /*  WARN */;
  return value0;
 }
}
/*	function definition for ADD-FUNCTION-DECLARATION              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3add_function_declaration(cl_narg narg, cl_object v1fname, cl_object v2ftype, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v3env;
  va_list args; va_start(args,v2ftype);
  {
   int i = 2;
   if (i >= narg) {
    v3env = ecl_symbol_value(VV[11]);
   } else {
    i++;
    v3env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (Null(si_valid_function_name_p(v1fname))) { goto L3; }
  {
   cl_object v4fun;
   v4fun = ecl_function_dispatch(cl_env_copy,VV[37])(1, v1fname) /*  CMP-ENV-SEARCH-FUNCTION */;
   if (Null(cl_functionp(v4fun))) { goto L6; }
   (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(2, _ecl_static_2, v1fname) /*  WARN */;
   goto L2;
L6:;
   ecl_function_dispatch(cl_env_copy,VV[38])(3, v1fname, v2ftype, v3env) /*  CMP-ENV-REGISTER-FTYPE */;
   goto L2;
  }
L3:;
  (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(2, _ecl_static_3, v1fname) /*  WARN */;
L2:;
  value0 = v3env;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for GET-ARG-TYPES                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4get_arg_types(cl_narg narg, cl_object v1fname, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v2env;
  cl_object v3may_be_global;
  va_list args; va_start(args,v1fname);
  {
   int i = 1;
   if (i >= narg) {
    v2env = ecl_symbol_value(VV[11]);
   } else {
    i++;
    v2env = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v3may_be_global = ECL_T;
   } else {
    i++;
    v3may_be_global = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v4x;
   v4x = ecl_function_dispatch(cl_env_copy,VV[40])(2, v1fname, v2env) /*  CMP-ENV-SEARCH-FTYPE */;
   if (Null(v4x)) { goto L4; }
   {
    cl_object v5arg_types;
    v5arg_types = ecl_car(v4x);
    if ((v5arg_types)==(ECL_SYM("*",18))) { goto L7; }
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = ECL_T;
    cl_env_copy->values[0] = v5arg_types;
    return cl_env_copy->values[0];
L7:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L4:;
   if (Null(v3may_be_global)) { goto L9; }
   {
    cl_object v6fun;
    v6fun = ecl_function_dispatch(cl_env_copy,VV[37])(2, v1fname, v2env) /*  CMP-ENV-SEARCH-FUNCTION */;
    if (v6fun==ECL_NIL) { goto L14; }
    if (Null(ecl_function_dispatch(cl_env_copy,VV[41])(1, v6fun) /*  FUN-P */)) { goto L12; }
    if (Null(ecl_function_dispatch(cl_env_copy,VV[42])(1, v6fun) /*  FUN-GLOBAL */)) { goto L12; }
    goto L13;
L14:;
L13:;
    value0 = si_get_sysprop(v1fname, VV[5]);
    return value0;
L12:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L9:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for GET-RETURN-TYPE                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5get_return_type(cl_narg narg, cl_object v1fname, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2env;
  va_list args; va_start(args,v1fname);
  {
   int i = 1;
   if (i >= narg) {
    v2env = ecl_symbol_value(VV[11]);
   } else {
    i++;
    v2env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v3x;
   v3x = ecl_function_dispatch(cl_env_copy,VV[40])(2, v1fname, v2env) /*  CMP-ENV-SEARCH-FTYPE */;
   if (Null(v3x)) { goto L3; }
   {
    cl_object v4return_types;
    v4return_types = ecl_cadr(v3x);
    if ((v4return_types)==(ECL_SYM("*",18))) { goto L6; }
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = ECL_T;
    cl_env_copy->values[0] = v4return_types;
    return cl_env_copy->values[0];
L6:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L3:;
   {
    cl_object v5fun;
    v5fun = ecl_function_dispatch(cl_env_copy,VV[37])(2, v1fname, v2env) /*  CMP-ENV-SEARCH-FUNCTION */;
    if (v5fun==ECL_NIL) { goto L11; }
    if (Null(ecl_function_dispatch(cl_env_copy,VV[41])(1, v5fun) /*  FUN-P */)) { goto L9; }
    if (Null(ecl_function_dispatch(cl_env_copy,VV[42])(1, v5fun) /*  FUN-GLOBAL */)) { goto L9; }
    goto L10;
L11:;
L10:;
    value0 = si_get_sysprop(v1fname, VV[9]);
    return value0;
L9:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for GET-LOCAL-ARG-TYPES                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6get_local_arg_types(cl_narg narg, cl_object v1fun, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2env;
  va_list args; va_start(args,v1fun);
  {
   int i = 1;
   if (i >= narg) {
    v2env = ecl_symbol_value(VV[11]);
   } else {
    i++;
    v2env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v3x;
   T0 = ecl_function_dispatch(cl_env_copy,VV[45])(1, v1fun) /*  FUN-NAME */;
   v3x = ecl_function_dispatch(cl_env_copy,VV[40])(2, T0, v2env) /*  CMP-ENV-SEARCH-FTYPE */;
   if (Null(v3x)) { goto L3; }
   T0 = ecl_car(v3x);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = ECL_T;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
L3:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = ECL_NIL;
   cl_env_copy->values[0] = ECL_NIL;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for GET-LOCAL-RETURN-TYPE                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7get_local_return_type(cl_narg narg, cl_object v1fun, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2env;
  va_list args; va_start(args,v1fun);
  {
   int i = 1;
   if (i >= narg) {
    v2env = ecl_symbol_value(VV[11]);
   } else {
    i++;
    v2env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v3x;
   T0 = ecl_function_dispatch(cl_env_copy,VV[45])(1, v1fun) /*  FUN-NAME */;
   v3x = ecl_function_dispatch(cl_env_copy,VV[40])(1, T0) /*  CMP-ENV-SEARCH-FTYPE */;
   if (Null(v3x)) { goto L3; }
   T0 = ecl_cadr(v3x);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = ECL_T;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
L3:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = ECL_NIL;
   cl_env_copy->values[0] = ECL_NIL;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for GET-PROCLAIMED-NARG                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8get_proclaimed_narg(cl_narg narg, cl_object v1fun, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2env;
  va_list args; va_start(args,v1fun);
  {
   int i = 1;
   if (i >= narg) {
    v2env = ecl_symbol_value(VV[11]);
   } else {
    i++;
    v2env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v4;                                  /*  ARG-LIST        */
   cl_object v5;                                  /*  FOUND           */
   value0 = L4get_arg_types(2, v1fun, v2env);
   v4 = value0;
   {
    const int v6 = cl_env_copy->nvalues;
    cl_object v7;
    v7 = (v6<=1)? ECL_NIL : cl_env_copy->values[1];
    v5 = v7;
   }
   if (Null(v5)) { goto L3; }
   {
    cl_object v6type;
    cl_object v7;
    v6type = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
    v7 = v4;
    {
     cl_object v8minarg;
     cl_object v9maxarg;
     cl_object v10in_optionals;
     v8minarg = ecl_make_fixnum(0);
     v9maxarg = ecl_make_fixnum(0);
     v10in_optionals = ECL_NIL;
L11:;
     if (!(ecl_endp(v7))) { goto L13; }
     goto L12;
L13:;
     v6type = _ecl_car(v7);
     {
      cl_object v11;
      v11 = _ecl_cdr(v7);
      if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
      v7 = v11;
     }
     if (!((v6type)==(ECL_SYM("*",18)))) { goto L27; }
     goto L24;
     goto L25;
L27:;
     goto L25;
L25:;
     if (!((v6type)==(ECL_SYM("&REST",12)))) { goto L31; }
     goto L24;
     goto L29;
L31:;
     goto L29;
L29:;
     if (!((v6type)==(ECL_SYM("&KEY",10)))) { goto L35; }
     goto L24;
     goto L33;
L35:;
     goto L33;
L33:;
     if (!((v6type)==(ECL_SYM("&ALLOW-OTHER-KEYS",6)))) { goto L22; }
     goto L23;
L24:;
L23:;
     cl_env_copy->nvalues = 2;
     cl_env_copy->values[1] = ecl_make_fixnum(65536);
     cl_env_copy->values[0] = v8minarg;
     return cl_env_copy->values[0];
L22:;
     if (!((v6type)==(ECL_SYM("&OPTIONAL",11)))) { goto L38; }
     v10in_optionals = ECL_T;
     v9maxarg = v8minarg;
     goto L21;
L38:;
     if (Null(v10in_optionals)) { goto L43; }
     v9maxarg = ecl_plus(v9maxarg,ecl_make_fixnum(1));
     goto L21;
L43:;
     v8minarg = ecl_plus(v8minarg,ecl_make_fixnum(1));
     v9maxarg = ecl_plus(v9maxarg,ecl_make_fixnum(1));
L21:;
     goto L11;
L12:;
     cl_env_copy->nvalues = 3;
     cl_env_copy->values[2] = v5;
     cl_env_copy->values[1] = v9maxarg;
     cl_env_copy->values[0] = v8minarg;
     return cl_env_copy->values[0];
    }
   }
L3:;
   cl_env_copy->nvalues = 3;
   cl_env_copy->values[2] = v5;
   cl_env_copy->values[1] = ecl_make_fixnum(65536);
   cl_env_copy->values[0] = ecl_make_fixnum(0);
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for DECLARE-INLINE                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L9declare_inline(cl_narg narg, cl_object v1fname, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v2env;
  cl_object v3definition;
  va_list args; va_start(args,v1fname);
  {
   int i = 1;
   if (i >= narg) {
    v2env = ecl_symbol_value(VV[11]);
   } else {
    i++;
    v2env = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v3definition = ECL_T;
   } else {
    i++;
    v3definition = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if ((si_valid_function_name_p(v1fname))!=ECL_NIL) { goto L3; }
  ecl_function_dispatch(cl_env_copy,VV[49])(2, _ecl_static_4, v1fname) /*  CMPERR */;
L3:;
  T0 = CONS(v1fname,v3definition);
  T1 = ecl_list1(T0);
  value0 = ecl_function_dispatch(cl_env_copy,VV[50])(3, ECL_SYM("INLINE",434), T1, v2env) /*  CMP-ENV-EXTEND-DECLARATION */;
  return value0;
 }
}
/*	function definition for DECLARE-NOTINLINE                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L10declare_notinline(cl_narg narg, cl_object v1fname, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2env;
  va_list args; va_start(args,v1fname);
  {
   int i = 1;
   if (i >= narg) {
    v2env = ecl_symbol_value(VV[11]);
   } else {
    i++;
    v2env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = L9declare_inline(3, v1fname, v2env, ECL_NIL);
  return value0;
 }
}
/*	function definition for PROCLAIM-INLINE                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L11proclaim_inline(cl_object v1fname_list)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   v2 = v1fname_list;
   goto L4;
L3:;
   {
    cl_object v3fun;
    v3fun = ecl_car(v2);
    if ((si_valid_function_name_p(v3fun))!=ECL_NIL) { goto L8; }
    cl_error(2, _ecl_static_5, v3fun);
L8:;
    if ((si_get_sysprop(v3fun, ECL_SYM("INLINE",434)))!=ECL_NIL) { goto L10; }
    si_put_sysprop(v3fun, ECL_SYM("INLINE",434), ECL_T);
    si_rem_sysprop(v3fun, ECL_SYM("NOTINLINE",587));
L10:;
   }
   v2 = ecl_cdr(v2);
L4:;
   if (Null(v2)) { goto L15; }
   goto L3;
L15:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for PROCLAIM-NOTINLINE                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L12proclaim_notinline(cl_object v1fname_list)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   v2 = v1fname_list;
   goto L4;
L3:;
   {
    cl_object v3fun;
    v3fun = ecl_car(v2);
    if ((si_valid_function_name_p(v3fun))!=ECL_NIL) { goto L8; }
    cl_error(2, _ecl_static_6, v3fun);
L8:;
    si_rem_sysprop(v3fun, ECL_SYM("INLINE",434));
    si_put_sysprop(v3fun, ECL_SYM("NOTINLINE",587), ECL_T);
   }
   v2 = ecl_cdr(v2);
L4:;
   if (Null(v2)) { goto L14; }
   goto L3;
L14:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for DECLARED-INLINE-P                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L13declared_inline_p(cl_narg narg, cl_object v1fname, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2env;
  va_list args; va_start(args,v1fname);
  {
   int i = 1;
   if (i >= narg) {
    v2env = ecl_symbol_value(VV[11]);
   } else {
    i++;
    v2env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v3x;
   cl_object v4flag;
   v3x = ecl_function_dispatch(cl_env_copy,VV[55])(2, ECL_SYM("INLINE",434), v2env) /*  CMP-ENV-SEARCH-DECLARATION */;
   {
    cl_object v5;
    v5 = v3x;
    goto L7;
L6:;
    {
     cl_object v6;
     cl_object v7;
     if (ecl_unlikely(ECL_ATOM(v5))) FEtype_error_cons(v5);
     v6 = v5;
     v7 = ECL_CONS_CAR(v6);
     if (Null(v7)) { goto L9; }
     {
      cl_object v8;
      if (ecl_unlikely(ECL_ATOM(v7))) FEtype_error_cons(v7);
      T0 = v7;
      v8 = ECL_CONS_CAR(T0);
      if (Null(ecl_function_dispatch(cl_env_copy,VV[56])(2, v1fname, v8) /*  SAME-FNAME-P */)) { goto L9; }
      v4flag = v7;
      goto L3;
     }
    }
L9:;
    v5 = ECL_CONS_CDR(v5);
L7:;
    if (v5==ECL_NIL) { goto L20; }
    goto L6;
L20:;
    v4flag = ECL_NIL;
   }
L3:;
   if (Null(v4flag)) { goto L22; }
   value0 = ecl_cdr(v4flag);
   cl_env_copy->nvalues = 1;
   return value0;
L22:;
   value0 = si_get_sysprop(v1fname, ECL_SYM("INLINE",434));
   return value0;
  }
 }
}
/*	function definition for DECLARED-NOTINLINE-P                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L14declared_notinline_p(cl_narg narg, cl_object v1fname, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2env;
  va_list args; va_start(args,v1fname);
  {
   int i = 1;
   if (i >= narg) {
    v2env = ecl_symbol_value(VV[11]);
   } else {
    i++;
    v2env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v3x;
   cl_object v4flag;
   v3x = ecl_function_dispatch(cl_env_copy,VV[55])(2, ECL_SYM("INLINE",434), v2env) /*  CMP-ENV-SEARCH-DECLARATION */;
   {
    cl_object v5;
    v5 = v3x;
    goto L7;
L6:;
    {
     cl_object v6;
     cl_object v7;
     if (ecl_unlikely(ECL_ATOM(v5))) FEtype_error_cons(v5);
     v6 = v5;
     v7 = ECL_CONS_CAR(v6);
     if (Null(v7)) { goto L9; }
     {
      cl_object v8;
      if (ecl_unlikely(ECL_ATOM(v7))) FEtype_error_cons(v7);
      T0 = v7;
      v8 = ECL_CONS_CAR(T0);
      if (Null(ecl_function_dispatch(cl_env_copy,VV[56])(2, v1fname, v8) /*  SAME-FNAME-P */)) { goto L9; }
      v4flag = v7;
      goto L3;
     }
    }
L9:;
    v5 = ECL_CONS_CDR(v5);
L7:;
    if (v5==ECL_NIL) { goto L20; }
    goto L6;
L20:;
    v4flag = ECL_NIL;
   }
L3:;
   if (Null(v4flag)) { goto L22; }
   T0 = ecl_cdr(v4flag);
   value0 = ecl_make_bool(T0==ECL_NIL);
   cl_env_copy->nvalues = 1;
   return value0;
L22:;
   value0 = si_get_sysprop(v1fname, ECL_SYM("NOTINLINE",587));
   return value0;
  }
 }
}
/*	function definition for INLINE-POSSIBLE                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L15inline_possible(cl_narg narg, cl_object v1fname, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2env;
  va_list args; va_start(args,v1fname);
  {
   int i = 1;
   if (i >= narg) {
    v2env = ecl_symbol_value(VV[11]);
   } else {
    i++;
    v2env = va_arg(args,cl_object);
   }
  }
  va_end(args);
  T0 = L14declared_notinline_p(2, v1fname, v2env);
  value0 = Null(T0)?ECL_T:ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for MAYBE-INSTALL-INLINE-FUNCTION         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L16maybe_install_inline_function(cl_object v1fname, cl_object v2form, cl_object v3env)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4x;
   cl_object v5flag;
   cl_object v6declared;
   cl_object v7proclaimed;
   v4x = ecl_function_dispatch(cl_env_copy,VV[55])(2, ECL_SYM("INLINE",434), v3env) /*  CMP-ENV-SEARCH-DECLARATION */;
   {
    cl_object v8;
    v8 = v4x;
    goto L6;
L5:;
    {
     cl_object v9;
     cl_object v10;
     if (ecl_unlikely(ECL_ATOM(v8))) FEtype_error_cons(v8);
     v9 = v8;
     v10 = ECL_CONS_CAR(v9);
     if (Null(v10)) { goto L8; }
     {
      cl_object v11;
      if (ecl_unlikely(ECL_ATOM(v10))) FEtype_error_cons(v10);
      T0 = v10;
      v11 = ECL_CONS_CAR(T0);
      if (Null(ecl_function_dispatch(cl_env_copy,VV[56])(2, v1fname, v11) /*  SAME-FNAME-P */)) { goto L8; }
      v5flag = v10;
      goto L2;
     }
    }
L8:;
    v8 = ECL_CONS_CDR(v8);
L6:;
    if (v8==ECL_NIL) { goto L19; }
    goto L5;
L19:;
    v5flag = ECL_NIL;
   }
L2:;
   if (Null(v5flag)) { goto L23; }
   v6declared = ecl_cdr(v5flag);
   goto L21;
L23:;
   v6declared = ECL_NIL;
   goto L21;
L21:;
   v7proclaimed = si_get_sysprop(v1fname, ECL_SYM("INLINE",434));
   if (Null(v6declared)) { goto L27; }
   T1 = cl_list(2, ECL_SYM("QUOTE",679), v1fname);
   T2 = cl_list(2, ECL_SYM("QUOTE",679), v2form);
   T3 = cl_list(4, VV[22], T1, VV[30], T2);
   T0 = cl_list(3, ECL_SYM("EVAL-WHEN",340), VV[29], T3);
   goto L26;
L27:;
   T0 = ECL_NIL;
L26:;
   if (Null(v7proclaimed)) { goto L30; }
   T2 = cl_list(2, ECL_SYM("QUOTE",679), v1fname);
   T3 = cl_list(2, ECL_SYM("QUOTE",679), v2form);
   T4 = cl_list(4, ECL_SYM("PUT-SYSPROP",1124), T2, VV[32], T3);
   T1 = cl_list(3, ECL_SYM("EVAL-WHEN",340), VV[31], T4);
   goto L29;
L30:;
   T1 = ECL_NIL;
L29:;
   value0 = cl_list(3, ECL_SYM("PROGN",671), T0, T1);
   return value0;
  }
 }
}

#include "cmp/cmpenv-fun.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecl5shPkhxZsTcr9_3jptVE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPENV-FUN.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_ecl5shPkhxZsTcr9_3jptVE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[34]);                           /*  FUNCTION-ARG-TYPES */
 ecl_cmp_defun(VV[35]);                           /*  PROCLAIM-FUNCTION */
 ecl_cmp_defun(VV[36]);                           /*  ADD-FUNCTION-DECLARATION */
 ecl_cmp_defun(VV[39]);                           /*  GET-ARG-TYPES   */
 ecl_cmp_defun(VV[43]);                           /*  GET-RETURN-TYPE */
 ecl_cmp_defun(VV[44]);                           /*  GET-LOCAL-ARG-TYPES */
 ecl_cmp_defun(VV[46]);                           /*  GET-LOCAL-RETURN-TYPE */
 ecl_cmp_defun(VV[47]);                           /*  GET-PROCLAIMED-NARG */
 ecl_cmp_defun(VV[48]);                           /*  DECLARE-INLINE  */
 ecl_cmp_defun(VV[51]);                           /*  DECLARE-NOTINLINE */
 ecl_cmp_defun(VV[52]);                           /*  PROCLAIM-INLINE */
 ecl_cmp_defun(VV[53]);                           /*  PROCLAIM-NOTINLINE */
 ecl_cmp_defun(VV[54]);                           /*  DECLARED-INLINE-P */
 ecl_cmp_defun(VV[57]);                           /*  DECLARED-NOTINLINE-P */
 ecl_cmp_defun(VV[58]);                           /*  INLINE-POSSIBLE */
 ecl_cmp_defun(VV[59]);                           /*  MAYBE-INSTALL-INLINE-FUNCTION */
}
