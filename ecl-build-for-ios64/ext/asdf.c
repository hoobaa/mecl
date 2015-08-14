/*	Compiler: ECL 12.12.1                                         */
/*	Source: EXT:ASDF;ASDF.LISP                                    */
#include <ecl/ecl-cmp.h>
#include "ext/asdf.eclh"
/*	function definition for USE-ECL-BYTE-COMPILER-P               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1use_ecl_byte_compiler_p()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_memql(VV[2],ecl_symbol_value(ECL_SYM("*FEATURES*",34))))) { goto L2; }
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for FIND-SYMBOL*                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2find_symbol_(cl_object v1s, cl_object v2p)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_string(v1s);
  value0 = cl_find_symbol(2, T0, v2p);
  return value0;
 }
}
/*	function definition for STRCAT                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3strcat(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1strings;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1strings = cl_grab_rest_args(args);
  ecl_va_end(args);
  value0 = cl_apply(3, ECL_SYM("CONCATENATE",244), ECL_SYM("STRING",805), v1strings);
  return value0;
 }
}
/*	local function COMPATFMT                                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC4compatfmt(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4format;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4format = v5;
   }
   if (Null(v3)) { goto L8; }
   si_dm_too_many_arguments(v1);
L8:;
   value0 = v4format;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function ENSURE-PACKAGE                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC16ensure_package(cl_narg narg, volatile cl_object *lex0, cl_object v1name, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2nicknames;
  cl_object v3use;
  cl_object v4unintern;
  cl_object v5shadow;
  cl_object v6export;
  cl_object v7redefined_functions;
  ecl_va_list args; ecl_va_start(args,v1name,narg,1);
  {
   cl_object keyvars[12];
   cl_parse_key(args,6,LC16ensure_packagekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v2nicknames = keyvars[0];
   v3use = keyvars[1];
   v4unintern = keyvars[2];
   v5shadow = keyvars[3];
   v6export = keyvars[4];
   v7redefined_functions = keyvars[5];
  }
  {
   cl_object v8p;
   v8p = LC8ensure_exists(lex0, v1name, v2nicknames, v3use);
   LC11ensure_unintern(v8p, v4unintern);
   LC12ensure_shadow(v8p, v5shadow);
   LC15ensure_export(v8p, v6export);
   LC14ensure_fmakunbound(v8p, v7redefined_functions);
   value0 = v8p;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function ENSURE-EXPORT                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC15ensure_export(cl_object v1package, cl_object v2export)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3formerly_exported_symbols;
   cl_object v4bothly_exported_symbols;
   cl_object v5newly_exported_symbols;
   v3formerly_exported_symbols = ECL_NIL;
   v4bothly_exported_symbols = ECL_NIL;
   v5newly_exported_symbols = ECL_NIL;
   {
    cl_object v6;
    cl_object v7;
    cl_object v8sym;
    v6 = si_packages_iterator(3, v1package, VV[13], ECL_T);
    v7 = ECL_NIL;
    v8sym = ECL_NIL;
    goto L10;
L9:;
    value0 = ecl_function_dispatch(cl_env_copy,v6)(0);
    v7 = value0;
    {
     const int v9 = cl_env_copy->nvalues;
     cl_object v10;
     v10 = (v9<=1)? ECL_NIL : cl_env_copy->values[1];
     v8sym = v10;
    }
    if ((v7)!=ECL_NIL) { goto L14; }
    goto L4;
L14:;
    {
     cl_object v9;
     v9 = v2export;
     goto L22;
L21:;
     {
      cl_object v10;
      cl_object v11;
      if (ecl_unlikely(ECL_ATOM(v9))) FEtype_error_cons(v9);
      v10 = v9;
      v11 = ECL_CONS_CAR(v10);
      if (Null(ecl_function_dispatch(cl_env_copy,ECL_SYM("STRING-EQUAL",808))(2, v8sym, v11))) { goto L24; }
      if (Null(v10)) { goto L17; }
      goto L18;
     }
L24:;
     v9 = ECL_CONS_CDR(v9);
L22:;
     if (v9==ECL_NIL) { goto L31; }
     goto L21;
L31:;
     goto L17;
    }
L18:;
    v4bothly_exported_symbols = CONS(v8sym,v4bothly_exported_symbols);
    goto L16;
L17:;
    v3formerly_exported_symbols = CONS(v8sym,v3formerly_exported_symbols);
L16:;
L10:;
    goto L9;
   }
L4:;
   {
    cl_object v6sym;
    cl_object v7;
    v6sym = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v2export))) FEtype_error_list(v2export);
    v7 = v2export;
L40:;
    if (!(ecl_endp(v7))) { goto L42; }
    goto L41;
L42:;
    v6sym = _ecl_car(v7);
    {
     cl_object v8;
     v8 = _ecl_cdr(v7);
     if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
     v7 = v8;
    }
    if ((ecl_member(v6sym,v4bothly_exported_symbols))!=ECL_NIL) { goto L50; }
    v5newly_exported_symbols = CONS(v6sym,v5newly_exported_symbols);
L50:;
    goto L40;
L41:;
   }
   {
    cl_object v6;
    cl_object v7user;
    cl_object v8;
    v6 = cl_package_used_by_list(v1package);
    v7user = ECL_NIL;
    v8 = v6;
    {
     cl_object v9shadowing;
     v9shadowing = ECL_NIL;
L59:;
     if (!(ecl_endp(v8))) { goto L61; }
     goto L60;
L61:;
     v7user = _ecl_car(v8);
     {
      cl_object v10;
      v10 = _ecl_cdr(v8);
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      v8 = v10;
     }
     v9shadowing = cl_package_shadowing_symbols(v7user);
     {
      cl_object v10new;
      cl_object v11;
      v10new = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v5newly_exported_symbols))) FEtype_error_list(v5newly_exported_symbols);
      v11 = v5newly_exported_symbols;
      {
       cl_object v12old;
       v12old = ECL_NIL;
L76:;
       if (!(ecl_endp(v11))) { goto L78; }
       goto L77;
L78:;
       v10new = _ecl_car(v11);
       {
        cl_object v13;
        v13 = _ecl_cdr(v11);
        if (ecl_unlikely(!ECL_LISTP(v13))) FEtype_error_list(v13);
        v11 = v13;
       }
       v12old = L2find_symbol_(v10new, v7user);
       if (Null(v12old)) { goto L88; }
       if ((ecl_memql(v12old,v9shadowing))!=ECL_NIL) { goto L88; }
       cl_unintern(2, v12old, v7user);
L88:;
       goto L76;
L77:;
      }
     }
     goto L59;
L60:;
    }
   }
   {
    cl_object v6x;
    cl_object v7;
    v6x = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v5newly_exported_symbols))) FEtype_error_list(v5newly_exported_symbols);
    v7 = v5newly_exported_symbols;
L96:;
    if (!(ecl_endp(v7))) { goto L98; }
    goto L97;
L98:;
    v6x = _ecl_car(v7);
    {
     cl_object v8;
     v8 = _ecl_cdr(v7);
     if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
     v7 = v8;
    }
    T0 = LC9intern_(v6x, v1package);
    cl_export(1, T0);
    goto L96;
L97:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	local function ENSURE-FMAKUNBOUND                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC14ensure_fmakunbound(cl_object v1package, cl_object v2symbols)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3name;
   cl_object v4;
   v3name = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v2symbols))) FEtype_error_list(v2symbols);
   v4 = v2symbols;
   {
    cl_object v5sym;
    v5sym = ECL_NIL;
L5:;
    if (!(ecl_endp(v4))) { goto L7; }
    goto L6;
L7:;
    v3name = _ecl_car(v4);
    {
     cl_object v6;
     v6 = _ecl_cdr(v4);
     if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
     v4 = v6;
    }
    v5sym = L2find_symbol_(v3name, v1package);
    if (Null(v5sym)) { goto L17; }
    cl_fmakunbound(v5sym);
L17:;
    goto L5;
L6:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	local function ENSURE-USE                                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC13ensure_use(cl_object v1package, cl_object v2use)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = cl_package_use_list(v1package);
   goto L5;
L4:;
   {
    cl_object v4used;
    v4used = ecl_car(v3);
    {
     cl_object v5;
     v5 = cl_package_name(v4used);
     {
      cl_object v6;
      v6 = v2use;
      goto L15;
L14:;
      {
       cl_object v7;
       cl_object v8;
       if (ecl_unlikely(ECL_ATOM(v6))) FEtype_error_cons(v6);
       v7 = v6;
       v8 = ECL_CONS_CAR(v7);
       if (Null(ecl_function_dispatch(cl_env_copy,ECL_SYM("STRING=",822))(2, v5, v8))) { goto L17; }
       if ((v7)!=ECL_NIL) { goto L9; }
       goto L10;
      }
L17:;
      v6 = ECL_CONS_CDR(v6);
L15:;
      if (v6==ECL_NIL) { goto L24; }
      goto L14;
L24:;
     }
    }
L10:;
    cl_unuse_package(1, v4used);
    {
     cl_object v5;
     cl_object v6;
     cl_object v7sym;
     v5 = si_packages_iterator(3, v4used, VV[13], ECL_T);
     v6 = ECL_NIL;
     v7sym = ECL_NIL;
     goto L32;
L31:;
     value0 = ecl_function_dispatch(cl_env_copy,v5)(0);
     v6 = value0;
     {
      const int v8 = cl_env_copy->nvalues;
      cl_object v9;
      v9 = (v8<=1)? ECL_NIL : cl_env_copy->values[1];
      v7sym = v9;
     }
     if ((v6)!=ECL_NIL) { goto L36; }
     goto L9;
L36:;
     T0 = L2find_symbol_(v7sym, v1package);
     if (!((v7sym)==(T0))) { goto L38; }
     LC10remove_symbol(v7sym, v1package);
L38:;
L32:;
     goto L31;
    }
L9:;
   }
   v3 = ecl_cdr(v3);
L5:;
   if (Null(v3)) { goto L43; }
   goto L4;
L43:;
  }
  {
   cl_object v3;
   v3 = cl_reverse(v2use);
   goto L48;
L47:;
   {
    cl_object v4used;
    v4used = ecl_car(v3);
    {
     cl_object v5;
     cl_object v6;
     cl_object v7sym;
     v5 = si_packages_iterator(3, v4used, VV[13], ECL_T);
     v6 = ECL_NIL;
     v7sym = ECL_NIL;
     goto L58;
L57:;
     value0 = ecl_function_dispatch(cl_env_copy,v5)(0);
     v6 = value0;
     {
      const int v8 = cl_env_copy->nvalues;
      cl_object v9;
      v9 = (v8<=1)? ECL_NIL : cl_env_copy->values[1];
      v7sym = v9;
     }
     if ((v6)!=ECL_NIL) { goto L62; }
     goto L52;
L62:;
     T0 = L2find_symbol_(v7sym, v1package);
     if ((v7sym)==(T0)) { goto L64; }
     LC10remove_symbol(v7sym, v1package);
L64:;
L58:;
     goto L57;
    }
L52:;
    cl_use_package(2, v4used, v1package);
   }
   v3 = ecl_cdr(v3);
L48:;
   if (Null(v3)) { goto L70; }
   goto L47;
L70:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function ENSURE-SHADOW                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC12ensure_shadow(cl_object v1package, cl_object v2symbols)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_shadow(2, v2symbols, v1package);
  return value0;
 }
}
/*	local function ENSURE-UNINTERN                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC11ensure_unintern(cl_object v1package, cl_object v2symbols)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3packages;
   v3packages = cl_list_all_packages();
   {
    cl_object v4sym;
    cl_object v5;
    v4sym = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v2symbols))) FEtype_error_list(v2symbols);
    v5 = v2symbols;
    {
     cl_object v6removed;
     v6removed = ECL_NIL;
L6:;
     if (!(ecl_endp(v5))) { goto L8; }
     goto L7;
L8:;
     v4sym = _ecl_car(v5);
     {
      cl_object v7;
      v7 = _ecl_cdr(v5);
      if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
      v5 = v7;
     }
     v6removed = LC10remove_symbol(v4sym, v1package);
     if (Null(v6removed)) { goto L18; }
     {
      cl_object v7p;
      cl_object v8;
      v7p = ECL_NIL;
      v8 = v3packages;
L22:;
      if (!(ecl_endp(v8))) { goto L24; }
      goto L23;
L24:;
      v7p = _ecl_car(v8);
      {
       cl_object v9;
       v9 = _ecl_cdr(v8);
       if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
       v8 = v9;
      }
      T0 = L2find_symbol_(v4sym, v7p);
      if (!((v6removed)==(T0))) { goto L32; }
      cl_unintern(2, v6removed, v7p);
L32:;
      goto L22;
L23:;
     }
L18:;
     goto L6;
L7:;
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
  }
 }
}
/*	local function REMOVE-SYMBOL                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC10remove_symbol(cl_object v1symbol, cl_object v2package)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3sym;
   v3sym = L2find_symbol_(v1symbol, v2package);
   if (Null(v3sym)) { goto L2; }
   cl_unexport(2, v3sym, v2package);
   cl_unintern(2, v3sym, v2package);
   value0 = v3sym;
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function INTERN*                                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC9intern_(cl_object v1symbol, cl_object v2package)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_string(v1symbol);
  value0 = cl_intern(2, T0, v2package);
  return value0;
 }
}
/*	local function ENSURE-EXISTS                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC8ensure_exists(volatile cl_object *lex0, cl_object v1name, cl_object v2nicknames, cl_object v3use)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4previous;
   {
    cl_object v5;
    cl_object v6;
    cl_object v7;
    v5 = CONS(v1name,v2nicknames);
    v6 = ECL_NIL;
    v7 = v5;
    {
     cl_object v8;
     cl_object v9;
     v8 = ecl_list1(ECL_NIL);
     v9 = v8;
L8:;
     if (!(ecl_endp(v7))) { goto L10; }
     goto L9;
L10:;
     v6 = _ecl_car(v7);
     {
      cl_object v10;
      v10 = _ecl_cdr(v7);
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      v7 = v10;
     }
     if (ecl_unlikely(ECL_ATOM(v9))) FEtype_error_cons(v9);
     T1 = v9;
     T2 = cl_find_package(v6);
     v9 = ecl_list1(T2);
     (ECL_CONS_CDR(T1)=v9,T1);
     goto L8;
L9:;
     T0 = ecl_cdr(v8);
     goto L2;
    }
   }
L2:;
   v4previous = cl_remove_duplicates(3, T0, VV[15], ECL_T);
   T0 = ecl_cdr(v4previous);
   cl_map(3, ECL_NIL, lex0[0], T0);
   {
    cl_object v5p;
    v5p = ecl_car(v4previous);
    if (Null(v5p)) { goto L26; }
    cl_rename_package(3, v5p, v1name, v2nicknames);
    LC13ensure_use(v5p, v3use);
    value0 = v5p;
    cl_env_copy->nvalues = 1;
    return value0;
L26:;
    value0 = cl_make_package(5, v1name, ECL_SYM("NICKNAMES",1277), v2nicknames, ECL_SYM("USE",1323), v3use);
    return value0;
   }
  }
 }
}
/*	local function UNLINK-PACKAGE                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC7unlink_package(cl_object v1package)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2u;
   v2u = cl_find_package(v1package);
   if (Null(v2u)) { goto L2; }
   T0 = LC6present_symbols(v2u);
   LC11ensure_unintern(v2u, T0);
   {
    cl_object v3;
    cl_object v4p;
    cl_object v5;
    v3 = cl_package_used_by_list(v2u);
    v4p = ECL_NIL;
    v5 = v3;
L10:;
    if (!(ecl_endp(v5))) { goto L12; }
    goto L11;
L12:;
    v4p = _ecl_car(v5);
    {
     cl_object v6;
     v6 = _ecl_cdr(v5);
     if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
     v5 = v6;
    }
    cl_unuse_package(2, v2u, v4p);
    goto L10;
L11:;
   }
   value0 = cl_delete_package(v2u);
   return value0;
L2:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function PRESENT-SYMBOLS                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC6present_symbols(cl_object v1package)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2l;
   v2l = ECL_NIL;
   {
    cl_object v3;
    cl_object v4;
    cl_object v5s;
    v3 = si_packages_iterator(3, v1package, VV[14], ECL_T);
    v4 = ECL_NIL;
    v5s = ECL_NIL;
    goto L8;
L7:;
    value0 = ecl_function_dispatch(cl_env_copy,v3)(0);
    v4 = value0;
    {
     const int v6 = cl_env_copy->nvalues;
     cl_object v7;
     v7 = (v6<=1)? ECL_NIL : cl_env_copy->values[1];
     v5s = v7;
    }
    if ((v4)!=ECL_NIL) { goto L12; }
    goto L2;
L12:;
    if (Null(LC5present_symbol_p(v5s, v1package))) { goto L14; }
    v2l = CONS(v5s,v2l);
L14:;
L8:;
    goto L7;
   }
L2:;
   value0 = cl_reverse(v2l);
   return value0;
  }
 }
}
/*	local function PRESENT-SYMBOL-P                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC5present_symbol_p(cl_object v1symbol, cl_object v2package)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   {
    struct ecl_stack_frame _ecl_inner_frame_aux;
    cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
    {
     cl_object v4;
     v4 = _ecl_inner_frame;
     cl_env_copy->values[0] = L2find_symbol_(v1symbol, v2package);
     ecl_stack_frame_push_values(v4);cl_env_copy->values[0]=ecl_apply_from_stack_frame(v4,ECL_SYM("LIST",481));
     value0 = cl_env_copy->values[0];
    }
    ecl_stack_frame_close(_ecl_inner_frame);
   }
   T0 = value0;
   v3 = ecl_cadr(T0);
   if (!(ecl_eql(v3,ECL_SYM("INTERNAL",1258)))) { goto L11; }
   value0 = VV[12];
   goto L9;
L11:;
   value0 = ECL_NIL;
   goto L9;
L9:;
   if ((value0)!=ECL_NIL) { goto L8; }
   if (!(ecl_eql(v3,ECL_SYM("EXTERNAL",1235)))) { goto L14; }
   value0 = VV[13];
   cl_env_copy->nvalues = 1;
   return value0;
L14:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L8:;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function DEFGENERIC*                                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC17defgeneric_(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4name;
   cl_object v5formals;
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
    v5formals = v6;
   }
   T0 = cl_list(2, ECL_SYM("QUOTE",679), v4name);
   T1 = cl_list(2, ECL_SYM("FMAKUNBOUND",385), T0);
   if (!(ECL_SYMBOLP(v4name))) { goto L15; }
   T3 = cl_list(2, ECL_SYM("NOTINLINE",587), v4name);
   T2 = cl_list(2, ECL_SYM("DECLAIM",272), T3);
   goto L14;
L15:;
   T2 = ECL_NIL;
L14:;
   T3 = cl_listX(4, ECL_SYM("DEFGENERIC",938), v4name, v5formals, v3);
   value0 = cl_list(4, ECL_SYM("PROGN",671), T1, T2, T3);
   return value0;
  }
 }
}
/*	local function DEFUN*                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC18defun_(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4name;
   cl_object v5formals;
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
    v5formals = v6;
   }
   T0 = cl_list(2, ECL_SYM("QUOTE",679), v4name);
   T1 = cl_list(2, ECL_SYM("FMAKUNBOUND",385), T0);
   if (!(ECL_SYMBOLP(v4name))) { goto L15; }
   T3 = cl_list(2, ECL_SYM("NOTINLINE",587), v4name);
   T2 = cl_list(2, ECL_SYM("DECLAIM",272), T3);
   goto L14;
L15:;
   T2 = ECL_NIL;
L14:;
   T3 = cl_listX(4, ECL_SYM("DEFUN",289), v4name, v5formals, v3);
   value0 = cl_list(4, ECL_SYM("PROGN",671), T1, T2, T3);
   return value0;
  }
 }
}
/*	local function WHILE-COLLECTING                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC19while_collecting(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4 = v5;
   }
   {
    cl_object v5;
    cl_object v6;
    {
     cl_object v7;
     cl_object v8;
     v7 = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
     v8 = v4;
     {
      cl_object v9;
      cl_object v10;
      v9 = ecl_list1(ECL_NIL);
      v10 = v9;
L14:;
      if (!(ecl_endp(v8))) { goto L16; }
      goto L15;
L16:;
      v7 = _ecl_car(v8);
      {
       cl_object v11;
       v11 = _ecl_cdr(v8);
       if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
       v8 = v11;
      }
      if (ecl_unlikely(ECL_ATOM(v10))) FEtype_error_cons(v10);
      T0 = v10;
      T2 = ecl_symbol_name(v7);
      T1 = cl_gensym(1, T2);
      v10 = ecl_list1(T1);
      (ECL_CONS_CDR(T0)=v10,T0);
      goto L14;
L15:;
      v5 = ecl_cdr(v9);
      goto L8;
     }
    }
L8:;
    {
     cl_object v7;
     cl_object v8;
     v7 = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
     v8 = v4;
     {
      cl_object v9;
      cl_object v10;
      v9 = ecl_list1(ECL_NIL);
      v10 = v9;
L37:;
      if (!(ecl_endp(v8))) { goto L39; }
      goto L38;
L39:;
      v7 = _ecl_car(v8);
      {
       cl_object v11;
       v11 = _ecl_cdr(v8);
       if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
       v8 = v11;
      }
      if (ecl_unlikely(ECL_ATOM(v10))) FEtype_error_cons(v10);
      T0 = v10;
      T2 = cl_constantly(ECL_NIL);
      T1 = ecl_function_dispatch(cl_env_copy,T2)(1, v7);
      v10 = ecl_list1(T1);
      (ECL_CONS_CDR(T0)=v10,T0);
      goto L37;
L38:;
      v6 = ecl_cdr(v9);
      goto L31;
     }
    }
L31:;
    {
     cl_object v7;
     cl_object v8;
     v7 = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
     v8 = v5;
     {
      cl_object v9;
      cl_object v10;
      v9 = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
      v10 = v6;
      {
       cl_object v11;
       cl_object v12;
       v11 = ecl_list1(ECL_NIL);
       v12 = v11;
L64:;
       if (!(ecl_endp(v8))) { goto L66; }
       goto L65;
L66:;
       v7 = _ecl_car(v8);
       {
        cl_object v13;
        v13 = _ecl_cdr(v8);
        if (ecl_unlikely(!ECL_LISTP(v13))) FEtype_error_list(v13);
        v8 = v13;
       }
       if (!(ecl_endp(v10))) { goto L74; }
       goto L65;
L74:;
       v9 = _ecl_car(v10);
       {
        cl_object v13;
        v13 = _ecl_cdr(v10);
        if (ecl_unlikely(!ECL_LISTP(v13))) FEtype_error_list(v13);
        v10 = v13;
       }
       if (ecl_unlikely(ECL_ATOM(v12))) FEtype_error_cons(v12);
       T1 = v12;
       T2 = cl_list(2, v7, v9);
       v12 = ecl_list1(T2);
       (ECL_CONS_CDR(T1)=v12,T1);
       goto L64;
L65:;
       T0 = ecl_cdr(v11);
       goto L55;
      }
     }
    }
L55:;
    {
     cl_object v7;
     cl_object v8;
     v7 = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
     v8 = v4;
     {
      cl_object v9;
      cl_object v10;
      v9 = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
      v10 = v5;
      {
       cl_object v11;
       cl_object v12;
       v11 = ecl_list1(ECL_NIL);
       v12 = v11;
L97:;
       if (!(ecl_endp(v8))) { goto L99; }
       goto L98;
L99:;
       v7 = _ecl_car(v8);
       {
        cl_object v13;
        v13 = _ecl_cdr(v8);
        if (ecl_unlikely(!ECL_LISTP(v13))) FEtype_error_list(v13);
        v8 = v13;
       }
       if (!(ecl_endp(v10))) { goto L107; }
       goto L98;
L107:;
       v9 = _ecl_car(v10);
       {
        cl_object v13;
        v13 = _ecl_cdr(v10);
        if (ecl_unlikely(!ECL_LISTP(v13))) FEtype_error_list(v13);
        v10 = v13;
       }
       if (ecl_unlikely(ECL_ATOM(v12))) FEtype_error_cons(v12);
       T2 = v12;
       T4 = cl_list(3, ECL_SYM("PUSH",677), VV[31], v9);
       T3 = cl_list(4, v7, VV[30], T4, VV[32]);
       v12 = ecl_list1(T3);
       (ECL_CONS_CDR(T2)=v12,T2);
       goto L97;
L98:;
       T1 = ecl_cdr(v11);
       goto L88;
      }
     }
    }
L88:;
    {
     cl_object v7;
     cl_object v8;
     v7 = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
     v8 = v5;
     {
      cl_object v9;
      cl_object v10;
      v9 = ecl_list1(ECL_NIL);
      v10 = v9;
L128:;
      if (!(ecl_endp(v8))) { goto L130; }
      goto L129;
L130:;
      v7 = _ecl_car(v8);
      {
       cl_object v11;
       v11 = _ecl_cdr(v8);
       if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
       v8 = v11;
      }
      if (ecl_unlikely(ECL_ATOM(v10))) FEtype_error_cons(v10);
      T3 = v10;
      T4 = cl_list(2, ECL_SYM("REVERSE",727), v7);
      v10 = ecl_list1(T4);
      (ECL_CONS_CDR(T3)=v10,T3);
      goto L128;
L129:;
      T2 = ecl_cdr(v9);
      goto L122;
     }
    }
L122:;
    T3 = CONS(ECL_SYM("VALUES",895),T2);
    T4 = ecl_list1(T3);
    T5 = ecl_append(v3,T4);
    T6 = cl_listX(3, ECL_SYM("FLET",373), T1, T5);
    value0 = cl_list(3, ECL_SYM("LET",477), T0, T6);
    return value0;
   }
  }
 }
}
/*	local function AIF                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC20aif(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4test;
   cl_object v5then;
   cl_object v6else;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v7;
    v7 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4test = v7;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v7;
    v7 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5then = v7;
   }
   if (Null(v3)) { goto L15; }
   {
    cl_object v7;
    v7 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v6else = v7;
    goto L14;
   }
L15:;
   v6else = ECL_NIL;
L14:;
   if (Null(v3)) { goto L20; }
   si_dm_too_many_arguments(v1);
L20:;
   T0 = cl_list(2, VV[34], v4test);
   T1 = ecl_list1(T0);
   T2 = cl_list(4, ECL_SYM("IF",946), VV[34], v5then, v6else);
   value0 = cl_list(3, ECL_SYM("LET",477), T1, T2);
   return value0;
  }
 }
}
/*	function definition for PATHNAME-DIRECTORY-PATHNAME           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L21pathname_directory_pathname(cl_object v1pathname)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1pathname)) { goto L1; }
  value0 = cl_make_pathname(8, ECL_SYM("NAME",1273), ECL_NIL, ECL_SYM("TYPE",1318), ECL_NIL, ECL_SYM("VERSION",1326), ECL_NIL, ECL_SYM("DEFAULTS",1216), v1pathname);
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for NORMALIZE-PATHNAME-DIRECTORY-COMPONENT */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L22normalize_pathname_directory_component(cl_object v1directory)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_STRINGP(v1directory))) { goto L1; }
  cl_list(2, ECL_SYM("ABSOLUTE",1196), v1directory);
  value0 = v1directory;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (v1directory==ECL_NIL) { goto L6; }
  if (!(ECL_CONSP(v1directory))) { goto L4; }
  {
   cl_object v2;
   v2 = ecl_car(v1directory);
   if (!(ecl_eql(v2,ECL_SYM("ABSOLUTE",1196)))) { goto L13; }
   goto L10;
   goto L11;
L13:;
   goto L11;
L11:;
   if (!(ecl_eql(v2,ECL_SYM("RELATIVE",1299)))) { goto L4; }
   goto L5;
L10:;
   goto L5;
  }
L6:;
L5:;
  value0 = v1directory;
  cl_env_copy->nvalues = 1;
  return value0;
L4:;
  value0 = cl_error(2, _ecl_static_4, v1directory);
  return value0;
 }
}
/*	function definition for MERGE-PATHNAME-DIRECTORY-COMPONENTS   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L23merge_pathname_directory_components(cl_object v1specified, cl_object v2defaults)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3directory;
   v3directory = ecl_function_dispatch(cl_env_copy,VV[38])(1, v1specified) /*  NORMALIZE-PATHNAME-DIRECTORY-COMPONENT */;
   {
    cl_object v4;
    v4 = ecl_car(v3directory);
    if (!((v4)==(ECL_NIL))) { goto L3; }
    value0 = v2defaults;
    cl_env_copy->nvalues = 1;
    return value0;
L3:;
    if (!(ecl_eql(v4,ECL_SYM("ABSOLUTE",1196)))) { goto L6; }
    value0 = v1specified;
    cl_env_copy->nvalues = 1;
    return value0;
L6:;
    if (!(ecl_eql(v4,ECL_SYM("RELATIVE",1299)))) { goto L8; }
    {
     cl_object v5;
     cl_object v6;
     cl_object v7reldir;
     v5 = ecl_function_dispatch(cl_env_copy,VV[38])(1, v2defaults) /*  NORMALIZE-PATHNAME-DIRECTORY-COMPONENT */;
     v6 = ecl_cdr(v3directory);
     v7reldir = v6;
     if (!(v5==ECL_NIL)) { goto L13; }
     value0 = v3directory;
     cl_env_copy->nvalues = 1;
     return value0;
L13:;
     T0 = ecl_car(v7reldir);
     if ((ECL_SYM("BACK",1200))==(T0)) { goto L15; }
     value0 = ecl_append(v5,v7reldir);
     cl_env_copy->nvalues = 1;
     return value0;
L15:;
     {
      cl_object v8defabs;
      v8defabs = ecl_car(v5);
      {
       cl_object v9defrev;
       T0 = ecl_cdr(v5);
       v9defrev = cl_reverse(T0);
L19:;
       T0 = ecl_car(v7reldir);
       if (!((ECL_SYM("BACK",1200))==(T0))) { goto L24; }
       if (!((ECL_SYM("ABSOLUTE",1196))==(v8defabs))) { goto L28; }
       if (v9defrev==ECL_NIL) { goto L21; }
       goto L26;
L28:;
       goto L26;
L26:;
       T0 = ecl_car(v9defrev);
       if (ECL_STRINGP(T0)) { goto L21; }
       goto L22;
L24:;
       goto L22;
L22:;
       goto L20;
L21:;
       {
        cl_object v10;
        v10 = v7reldir;
        if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
        if (Null(v10)) { goto L35; }
        {
         cl_object v11;
         v11 = ECL_CONS_CDR(v10);
         v7reldir = v11;
         v10 = ECL_CONS_CAR(v10);
        }
L35:;
       }
       {
        cl_object v10;
        v10 = v9defrev;
        if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
        if (Null(v10)) { goto L44; }
        {
         cl_object v11;
         v11 = ECL_CONS_CDR(v10);
         v9defrev = v11;
         v10 = ECL_CONS_CAR(v10);
        }
L44:;
       }
       goto L19;
L20:;
       T0 = cl_reverse(v9defrev);
       T1 = ecl_append(T0,v7reldir);
       value0 = CONS(v8defabs,T1);
       cl_env_copy->nvalues = 1;
       return value0;
      }
     }
    }
L8:;
    value0 = si_ecase_error(v4, VV[44]);
    return value0;
   }
  }
 }
}
/*	function definition for MAKE-PATHNAME-COMPONENT-LOGICAL       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L24make_pathname_component_logical(cl_object v1x)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_typep(2, v1x, VV[47]))) { goto L1; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  value0 = v1x;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for MAKE-PATHNAME-LOGICAL                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L25make_pathname_logical(cl_object v1pathname, cl_object v2host)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_pathname_directory(1, v1pathname);
  T1 = ecl_function_dispatch(cl_env_copy,VV[46])(1, T0) /*  MAKE-PATHNAME-COMPONENT-LOGICAL */;
  T2 = cl_pathname_name(1, v1pathname);
  T3 = ecl_function_dispatch(cl_env_copy,VV[46])(1, T2) /*  MAKE-PATHNAME-COMPONENT-LOGICAL */;
  T4 = cl_pathname_type(1, v1pathname);
  T5 = ecl_function_dispatch(cl_env_copy,VV[46])(1, T4) /*  MAKE-PATHNAME-COMPONENT-LOGICAL */;
  T6 = cl_pathname_version(v1pathname);
  T7 = ecl_function_dispatch(cl_env_copy,VV[46])(1, T6) /*  MAKE-PATHNAME-COMPONENT-LOGICAL */;
  value0 = cl_make_pathname(10, ECL_SYM("HOST",1243), v2host, ECL_SYM("DIRECTORY",1219), T1, ECL_SYM("NAME",1273), T3, ECL_SYM("TYPE",1318), T5, ECL_SYM("VERSION",1326), T7);
  return value0;
 }
}
/*	function definition for MERGE-PATHNAMES*                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L27merge_pathnames_(cl_narg narg, cl_object v1specified, ...)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2defaults;
  va_list args; va_start(args,v1specified);
  {
   int i = 1;
   if (i >= narg) {
    v2defaults = ecl_symbol_value(ECL_SYM("*DEFAULT-PATHNAME-DEFAULTS*",32));
   } else {
    i++;
    v2defaults = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (!(v1specified==ECL_NIL)) { goto L2; }
  value0 = v2defaults;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  if (!(v2defaults==ECL_NIL)) { goto L4; }
  value0 = v1specified;
  cl_env_copy->nvalues = 1;
  return value0;
L4:;
  {
   cl_object v3specified;
   cl_object v4defaults;
   cl_object v5directory;
   cl_object v6name;
   cl_object v7type;
   cl_object v8version;
   v3specified = cl_pathname(v1specified);
   v4defaults = cl_pathname(v2defaults);
   T0 = cl_pathname_directory(1, v3specified);
   v5directory = ecl_function_dispatch(cl_env_copy,VV[38])(1, T0) /*  NORMALIZE-PATHNAME-DIRECTORY-COMPONENT */;
   value0 = cl_pathname_name(1, v3specified);
   if ((value0)!=ECL_NIL) { goto L11; }
   v6name = cl_pathname_name(1, v4defaults);
   goto L9;
L11:;
   v6name = value0;
   goto L9;
L9:;
   value0 = cl_pathname_type(1, v3specified);
   if ((value0)!=ECL_NIL) { goto L15; }
   v7type = cl_pathname_type(1, v4defaults);
   goto L13;
L15:;
   v7type = value0;
   goto L13;
L13:;
   value0 = cl_pathname_version(v3specified);
   if ((value0)!=ECL_NIL) { goto L19; }
   v8version = cl_pathname_version(v4defaults);
   goto L17;
L19:;
   v8version = value0;
   goto L17;
L17:;
   {
    cl_object v10;                                /*  HOST            */
    cl_object v11;                                /*  DEVICE          */
    cl_object v12;                                /*  DIRECTORY       */
    cl_object v13;                                /*  UNSPECIFIC-HANDLER */
    {
     cl_object v14;
     v14 = ecl_car(v5directory);
     if (!(ecl_eql(v14,ECL_SYM("ABSOLUTE",1196)))) { goto L23; }
     T0 = cl_pathname_host(1, v3specified);
     T1 = cl_pathname_device(1, v3specified);
     T2 = LC26unspecific_handler(v3specified);
     cl_env_copy->nvalues = 4;
     cl_env_copy->values[3] = T2;
     cl_env_copy->values[2] = v5directory;
     cl_env_copy->values[1] = T1;
     cl_env_copy->values[0] = T0;
     value0 = cl_env_copy->values[0];
     goto L21;
L23:;
     if (!((v14)==(ECL_NIL))) { goto L32; }
     goto L29;
     goto L30;
L32:;
     goto L30;
L30:;
     if (!(ecl_eql(v14,ECL_SYM("RELATIVE",1299)))) { goto L27; }
     goto L28;
L29:;
L28:;
     T0 = cl_pathname_host(1, v4defaults);
     T1 = cl_pathname_device(1, v4defaults);
     T2 = cl_pathname_directory(1, v4defaults);
     T3 = ecl_function_dispatch(cl_env_copy,VV[42])(2, v5directory, T2) /*  MERGE-PATHNAME-DIRECTORY-COMPONENTS */;
     T4 = LC26unspecific_handler(v4defaults);
     cl_env_copy->nvalues = 4;
     cl_env_copy->values[3] = T4;
     cl_env_copy->values[2] = T3;
     cl_env_copy->values[1] = T1;
     cl_env_copy->values[0] = T0;
     value0 = cl_env_copy->values[0];
     goto L21;
L27:;
     value0 = si_ecase_error(v14, VV[54]);
    }
L21:;
    v10 = value0;
    {
     const int v14 = cl_env_copy->nvalues;
     cl_object v15;
     v15 = (v14<=1)? ECL_NIL : cl_env_copy->values[1];
     v11 = v15;
     v15 = (v14<=2)? ECL_NIL : cl_env_copy->values[2];
     v12 = v15;
     v15 = (v14<=3)? ECL_NIL : cl_env_copy->values[3];
     v13 = v15;
    }
    T0 = ecl_function_dispatch(cl_env_copy,v13)(1, v6name);
    T1 = ecl_function_dispatch(cl_env_copy,v13)(1, v7type);
    T2 = ecl_function_dispatch(cl_env_copy,v13)(1, v8version);
    value0 = cl_make_pathname(12, ECL_SYM("HOST",1243), v10, ECL_SYM("DEVICE",1217), v11, ECL_SYM("DIRECTORY",1219), v12, ECL_SYM("NAME",1273), T0, ECL_SYM("TYPE",1318), T1, ECL_SYM("VERSION",1326), T2);
    return value0;
   }
  }
 }
}
/*	local function UNSPECIFIC-HANDLER                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC26unspecific_handler(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(si_logical_pathname_p(v1p))) { goto L1; }
  value0 = ecl_fdefinition(VV[46]);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  value0 = (ECL_SYM("IDENTITY",426)->symbol.gfdef);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for PATHNAME-PARENT-DIRECTORY-PATHNAME    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L28pathname_parent_directory_pathname(cl_object v1pathname)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1pathname)) { goto L1; }
  T0 = cl_pathname_directory(1, v1pathname);
  T1 = ecl_function_dispatch(cl_env_copy,VV[42])(2, VV[57], T0) /*  MERGE-PATHNAME-DIRECTORY-COMPONENTS */;
  value0 = cl_make_pathname(10, ECL_SYM("NAME",1273), ECL_NIL, ECL_SYM("TYPE",1318), ECL_NIL, ECL_SYM("VERSION",1326), ECL_NIL, ECL_SYM("DIRECTORY",1219), T1, ECL_SYM("DEFAULTS",1216), v1pathname);
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function APPENDF                                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC30appendf(cl_object v1, cl_object v2si__env)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4si___reference;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4si___reference = v5;
   }
   {
    cl_object v6;                                 /*  VARS            */
    cl_object v7;                                 /*  VALS            */
    cl_object v8;                                 /*  STORES          */
    cl_object v9;                                 /*  SETTER          */
    cl_object v10;                                /*  GETTER          */
    value0 = (cl_env_copy->function=(ECL_SYM("GET-SETF-EXPANSION",410)->symbol.gfdef))->cfun.entry(2, v4si___reference, v2si__env) /*  GET-SETF-EXPANSION */;
    v6 = value0;
    v7 = cl_env_copy->values[1];
    v8 = cl_env_copy->values[2];
    v9 = cl_env_copy->values[3];
    v10 = cl_env_copy->values[4];
    {
     cl_object v11si__all_vars;
     {cl_object v12;
      v12 = ECL_NIL;
      v12 = ecl_make_cfun((cl_objectfn_fixed)LC29__g259,ECL_NIL,Cblock,1);
      T0 = v12;
     }
     T1 = v3;
     v11si__all_vars = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T0, T1) /*  MAPCAR */;
     if (!(ECL_SYMBOLP(v10))) { goto L11; }
     T0 = (ECL_SYM("CAR",180)->symbol.gfdef);
     T1 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T0, v11si__all_vars) /*  MAPCAR */;
     T2 = cl_listX(3, ECL_SYM("APPEND",88), v10, T1);
     T3 = ecl_car(v8);
     T4 = (ECL_SYM("FIRST",371)->symbol.gfdef);
     T5 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T4, v11si__all_vars) /*  MAPCAR */;
     T6 = CONS(VV[59],T5);
     T7 = cl_list(2, ECL_SYM("DECLARE",274), T6);
     T8 = cl_list(4, ECL_SYM("LET*",478), v11si__all_vars, T7, v9);
     value0 = cl_subst(3, T2, T3, T8);
     return value0;
L11:;
     {
      cl_object v12si__d;
      cl_object v13si__v;
      cl_object v14si__let_list;
      v12si__d = v6;
      v13si__v = v7;
      v14si__let_list = ECL_NIL;
      goto L20;
L19:;
      {
       cl_object v15;
       v15 = ecl_cdr(v12si__d);
       {
        cl_object v16;
        v16 = ecl_cdr(v13si__v);
        T0 = ecl_car(v12si__d);
        T1 = ecl_car(v13si__v);
        T2 = cl_list(2, T0, T1);
        v14si__let_list = CONS(T2,v14si__let_list);
        v13si__v = v16;
        v12si__d = v15;
       }
      }
L20:;
      if (v12si__d==ECL_NIL) { goto L26; }
      goto L19;
L26:;
      T0 = ecl_car(v8);
      if (!(ECL_LISTP(v4si___reference))) { goto L31; }
      T2 = ecl_car(v4si___reference);
      if (!((T2)==(ECL_SYM("THE",856)))) { goto L31; }
      T2 = ecl_cadr(v4si___reference);
      T3 = cl_listX(3, ECL_SYM("APPEND",88), v10, v3);
      T1 = cl_list(3, ECL_SYM("THE",856), T2, T3);
      goto L30;
L31:;
      T2 = (ECL_SYM("CAR",180)->symbol.gfdef);
      T3 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T2, v11si__all_vars) /*  MAPCAR */;
      T1 = cl_listX(3, ECL_SYM("APPEND",88), v10, T3);
L30:;
      T2 = cl_list(2, T0, T1);
      T3 = ecl_append(v11si__all_vars,v14si__let_list);
      v14si__let_list = CONS(T2,T3);
      T0 = cl_nreverse(v14si__let_list);
      T1 = (ECL_SYM("FIRST",371)->symbol.gfdef);
      T2 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T1, v11si__all_vars) /*  MAPCAR */;
      T3 = ecl_append(T2,v6);
      T4 = CONS(VV[59],T3);
      T5 = cl_list(2, ECL_SYM("DECLARE",274), T4);
      value0 = cl_list(4, ECL_SYM("LET*",478), T0, T5, v9);
      return value0;
     }
    }
   }
  }
 }
}
/*	local function G259                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC29__g259(cl_object v1si__v)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_gensym(0);
  value0 = cl_list(2, T0, v1si__v);
  return value0;
 }
}
/*	local function ORF                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC32orf(cl_object v1, cl_object v2si__env)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4si___reference;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4si___reference = v5;
   }
   {
    cl_object v6;                                 /*  VARS            */
    cl_object v7;                                 /*  VALS            */
    cl_object v8;                                 /*  STORES          */
    cl_object v9;                                 /*  SETTER          */
    cl_object v10;                                /*  GETTER          */
    value0 = (cl_env_copy->function=(ECL_SYM("GET-SETF-EXPANSION",410)->symbol.gfdef))->cfun.entry(2, v4si___reference, v2si__env) /*  GET-SETF-EXPANSION */;
    v6 = value0;
    v7 = cl_env_copy->values[1];
    v8 = cl_env_copy->values[2];
    v9 = cl_env_copy->values[3];
    v10 = cl_env_copy->values[4];
    {
     cl_object v11si__all_vars;
     {cl_object v12;
      v12 = ECL_NIL;
      v12 = ecl_make_cfun((cl_objectfn_fixed)LC31__g270,ECL_NIL,Cblock,1);
      T0 = v12;
     }
     T1 = v3;
     v11si__all_vars = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T0, T1) /*  MAPCAR */;
     if (!(ECL_SYMBOLP(v10))) { goto L11; }
     T0 = (ECL_SYM("CAR",180)->symbol.gfdef);
     T1 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T0, v11si__all_vars) /*  MAPCAR */;
     T2 = cl_listX(3, ECL_SYM("OR",614), v10, T1);
     T3 = ecl_car(v8);
     T4 = (ECL_SYM("FIRST",371)->symbol.gfdef);
     T5 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T4, v11si__all_vars) /*  MAPCAR */;
     T6 = CONS(VV[59],T5);
     T7 = cl_list(2, ECL_SYM("DECLARE",274), T6);
     T8 = cl_list(4, ECL_SYM("LET*",478), v11si__all_vars, T7, v9);
     value0 = cl_subst(3, T2, T3, T8);
     return value0;
L11:;
     {
      cl_object v12si__d;
      cl_object v13si__v;
      cl_object v14si__let_list;
      v12si__d = v6;
      v13si__v = v7;
      v14si__let_list = ECL_NIL;
      goto L20;
L19:;
      {
       cl_object v15;
       v15 = ecl_cdr(v12si__d);
       {
        cl_object v16;
        v16 = ecl_cdr(v13si__v);
        T0 = ecl_car(v12si__d);
        T1 = ecl_car(v13si__v);
        T2 = cl_list(2, T0, T1);
        v14si__let_list = CONS(T2,v14si__let_list);
        v13si__v = v16;
        v12si__d = v15;
       }
      }
L20:;
      if (v12si__d==ECL_NIL) { goto L26; }
      goto L19;
L26:;
      T0 = ecl_car(v8);
      if (!(ECL_LISTP(v4si___reference))) { goto L31; }
      T2 = ecl_car(v4si___reference);
      if (!((T2)==(ECL_SYM("THE",856)))) { goto L31; }
      T2 = ecl_cadr(v4si___reference);
      T3 = cl_listX(3, ECL_SYM("OR",614), v10, v3);
      T1 = cl_list(3, ECL_SYM("THE",856), T2, T3);
      goto L30;
L31:;
      T2 = (ECL_SYM("CAR",180)->symbol.gfdef);
      T3 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T2, v11si__all_vars) /*  MAPCAR */;
      T1 = cl_listX(3, ECL_SYM("OR",614), v10, T3);
L30:;
      T2 = cl_list(2, T0, T1);
      T3 = ecl_append(v11si__all_vars,v14si__let_list);
      v14si__let_list = CONS(T2,T3);
      T0 = cl_nreverse(v14si__let_list);
      T1 = (ECL_SYM("FIRST",371)->symbol.gfdef);
      T2 = (cl_env_copy->function=(ECL_SYM("MAPCAR",545)->symbol.gfdef))->cfun.entry(2, T1, v11si__all_vars) /*  MAPCAR */;
      T3 = ecl_append(T2,v6);
      T4 = CONS(VV[59],T3);
      T5 = cl_list(2, ECL_SYM("DECLARE",274), T4);
      value0 = cl_list(4, ECL_SYM("LET*",478), T0, T5, v9);
      return value0;
     }
    }
   }
  }
 }
}
/*	local function G270                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC31__g270(cl_object v1si__v)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_gensym(0);
  value0 = cl_list(2, T0, v1si__v);
  return value0;
 }
}
/*	function definition for FIRST-CHAR                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L33first_char(cl_object v1s)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_STRINGP(v1s))) { goto L2; }
  {
   cl_fixnum v2;
   v2 = ecl_length(v1s);
   if (!((v2)>0)) { goto L2; }
  }
  value0 = CODE_CHAR(ecl_char(v1s,0));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for LAST-CHAR                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L34last_char(cl_object v1s)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_STRINGP(v1s))) { goto L2; }
  {
   cl_fixnum v2;
   v2 = ecl_length(v1s);
   if (!((v2)>0)) { goto L2; }
  }
  {
   cl_fixnum v2;
   v2 = ecl_length(v1s);
   T0 = ecl_make_integer((v2)-1);
   value0 = cl_char(v1s, T0);
   return value0;
  }
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for ASDF-MESSAGE                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L35asdf_message(cl_narg narg, cl_object v1format_string, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2format_args;
  ecl_va_list args; ecl_va_start(args,v1format_string,narg,1);
  v2format_args = cl_grab_rest_args(args);
  ecl_va_end(args);
  value0 = cl_apply(4, ECL_SYM("FORMAT",387), ecl_symbol_value(VV[22]), v1format_string, v2format_args);
  return value0;
 }
}
/*	function definition for SPLIT-STRING                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L38split_string(volatile cl_narg narg, cl_object volatile v1string, ...)
{
 cl_object T0, T1;
 volatile cl_object lex0[3];
 cl_object volatile env0;
 cl_object volatile CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  volatile cl_object v2max;
  ecl_va_list args; ecl_va_start(args,v1string,narg,1);
  lex0[0] = v1string;                             /*  STRING          */
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L38split_stringkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v2max = keyvars[0];
   if (Null(keyvars[3])) {
    env0 = ECL_NIL;
    CLV0 = env0 = CONS(VV[69],env0);              /*  SEPARATOR       */
   } else {
    env0 = ECL_NIL;
    CLV0 = env0 = CONS(keyvars[1],env0);          /*  SEPARATOR       */
   }
  }
  value0 = ECL_NIL;
  if (ecl_frs_push(cl_env_copy,value0)) {         /*  BEGIN CATCH 1   */
   value0 = cl_env_copy->values[0];
  } else {
   {
    cl_fixnum v3;
    cl_object v4words;
    v3 = ecl_length(lex0[0]);
    lex0[1] = ECL_NIL;                            /*  LIST            */
    v4words = ecl_make_fixnum(0);
    lex0[2] = ecl_make_fixnum(v3);                /*  END             */
    {cl_object v5;
     v5 = ECL_NIL;
     v5 = ecl_make_cclosure_va((cl_objectfn)LC36separatorp,env0,Cblock);
     {
      cl_object v6start;
      v6start = ECL_NIL;
L8:;
      if (Null(v2max)) { goto L11; }
      T0 = ecl_one_minus(v2max);
      if (!(ecl_number_compare(v4words,T0)>=0)) { goto L11; }
      v6start = LC37done(lex0);
      goto L10;
L11:;
      v6start = cl_position_if(6, v5, lex0[0], ECL_SYM("END",1225), lex0[2], VV[15], ECL_T);
L10:;
      if (!(v6start==ECL_NIL)) { goto L15; }
      LC37done(lex0);
L15:;
      T0 = ecl_one_plus(v6start);
      T1 = cl_subseq(3, lex0[0], T0, lex0[2]);
      lex0[1] = CONS(T1,lex0[1]);
      v4words = ecl_plus(v4words,ecl_make_fixnum(1));
      lex0[2] = v6start;
      goto L8;
     }
    }
   }
  }
  ecl_frs_pop(cl_env_copy);                       /*  END CATCH 1     */
  return value0;
 }
}
/*	local function DONE                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC37done(volatile cl_object *lex0)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_subseq(3, lex0[0], ecl_make_fixnum(0), lex0[2]);
  cl_env_copy->values[0] = CONS(T0,lex0[1]);
  cl_env_copy->nvalues = 1;
  cl_throw(ECL_NIL);
 }
}
/*	closure SEPARATORP                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC36separatorp(cl_narg narg, cl_object v1char, ...)
{
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  SEPARATOR       */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  {
   cl_object v2;
   v2 = si_make_seq_iterator(2, ECL_CONS_CAR(CLV0), ecl_make_fixnum(0));
L2:;
   if ((v2)!=ECL_NIL) { goto L4; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L4:;
   {
    cl_object v3;
    v3 = si_seq_iterator_ref(ECL_CONS_CAR(CLV0), v2);
    if (!(ecl_eql(v1char,v3))) { goto L6; }
    value0 = v3;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L6:;
   v2 = si_seq_iterator_next(ECL_CONS_CAR(CLV0), v2);
   goto L2;
  }
 }
 }
}
/*	function definition for SPLIT-NAME-TYPE                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L39split_name_type(cl_object v1filename)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   cl_object v3;
   cl_object v4name;
   cl_object v5type;
   v2 = ecl_function_dispatch(cl_env_copy,VV[68])(5, v1filename, VV[72], ecl_make_fixnum(2), VV[73], _ecl_static_5) /*  SPLIT-STRING */;
   v3 = v2;
   if (!(v3==ECL_NIL)) { goto L4; }
   si_dm_too_few_arguments(v2);
L4:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4name = v6;
   }
   if (Null(v3)) { goto L10; }
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5type = v6;
    goto L9;
   }
L10:;
   v5type = ECL_NIL;
L9:;
   if (Null(v3)) { goto L15; }
   si_dm_too_many_arguments(v2);
L15:;
   if (!(ecl_equal(v4name,_ecl_static_6))) { goto L17; }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = ECL_NIL;
   cl_env_copy->values[0] = v1filename;
   return cl_env_copy->values[0];
L17:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5type;
   cl_env_copy->values[0] = v4name;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for COMPONENT-NAME-TO-PATHNAME-COMPONENTS */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L41component_name_to_pathname_components(cl_narg narg, cl_object v1s, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2force_directory;
  cl_object v3force_relative;
  ecl_va_list args; ecl_va_start(args,v1s,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L41component_name_to_pathname_componentskeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v2force_directory = keyvars[0];
   v3force_relative = keyvars[1];
  }
  {
   cl_object v4;
   v4 = v1s;
   if (ECL_STRINGP(v4)) { goto L3; }
   v1s = si_do_check_type(v4, ECL_SYM("STRING",805), ECL_NIL, VV[76]);
L3:;
  }
  {
   cl_object v4;
   v4 = si_make_seq_iterator(2, v1s, ecl_make_fixnum(0));
L9:;
   if ((v4)!=ECL_NIL) { goto L11; }
   goto L6;
L11:;
   {
    cl_object v5;
    v5 = si_seq_iterator_ref(v1s, v4);
    if (!((ECL_CODE_CHAR((ecl_character)(58))==(v5)))) { goto L13; }
    if (Null(v5)) { goto L6; }
    goto L7;
   }
L13:;
   v4 = si_seq_iterator_next(v1s, v4);
   goto L9;
  }
L7:;
  cl_error(2, _ecl_static_7, v1s);
L6:;
  {
   cl_object v4components;
   cl_object v5last_comp;
   v4components = ecl_function_dispatch(cl_env_copy,VV[68])(3, v1s, VV[73], _ecl_static_8) /*  SPLIT-STRING */;
   T0 = ecl_last(v4components,1);
   v5last_comp = ecl_car(T0);
   {
    cl_object v7;                                 /*  RELATIVE        */
    cl_object v8;                                 /*  COMPONENTS      */
    T0 = ecl_car(v4components);
    if (!(ecl_equal(T0,_ecl_static_6))) { goto L21; }
    T0 = ecl_function_dispatch(cl_env_copy,VV[62])(1, v1s) /*  FIRST-CHAR */;
    if (!(ecl_equal(T0,CODE_CHAR(47)))) { goto L23; }
    if (Null(v3force_relative)) { goto L25; }
    cl_error(2, _ecl_static_9, v1s);
L25:;
    T0 = ecl_cdr(v4components);
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = T0;
    cl_env_copy->values[0] = ECL_SYM("ABSOLUTE",1196);
    value0 = cl_env_copy->values[0];
    goto L20;
L23:;
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = ECL_NIL;
    cl_env_copy->values[0] = ECL_SYM("RELATIVE",1299);
    value0 = cl_env_copy->values[0];
    goto L20;
L21:;
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = v4components;
    cl_env_copy->values[0] = ECL_SYM("RELATIVE",1299);
    value0 = cl_env_copy->values[0];
L20:;
    v7 = value0;
    v8 = cl_env_copy->values[1];
    {cl_object v9;
     v9 = ECL_NIL;
     v9 = ecl_make_cfun((cl_objectfn_fixed)LC40__g306,ECL_NIL,Cblock,1);
     T0 = v9;
    }
    v8 = cl_remove_if(2, T0, v8);
    T0 = (ECL_SYM("EQUAL",335)->symbol.gfdef);
    v8 = cl_substitute(5, ECL_SYM("BACK",1200), _ecl_static_10, v8, ECL_SYM("TEST",1316), T0);
    if (!(ecl_equal(v5last_comp,_ecl_static_6))) { goto L33; }
    cl_env_copy->nvalues = 3;
    cl_env_copy->values[2] = ECL_NIL;
    cl_env_copy->values[1] = v8;
    cl_env_copy->values[0] = v7;
    return cl_env_copy->values[0];
L33:;
    if (Null(v2force_directory)) { goto L35; }
    cl_env_copy->nvalues = 3;
    cl_env_copy->values[2] = ECL_NIL;
    cl_env_copy->values[1] = v8;
    cl_env_copy->values[0] = v7;
    return cl_env_copy->values[0];
L35:;
    T0 = ecl_butlast(v8,1);
    cl_env_copy->nvalues = 3;
    cl_env_copy->values[2] = v5last_comp;
    cl_env_copy->values[1] = T0;
    cl_env_copy->values[0] = v7;
    return cl_env_copy->values[0];
   }
  }
 }
}
/*	local function G306                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC40__g306(cl_object v1x)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ecl_equal(v1x,_ecl_static_6))) { goto L5; }
  value0 = VV[77];
  goto L3;
L5:;
  value0 = ECL_NIL;
  goto L3;
L3:;
  if ((value0)!=ECL_NIL) { goto L2; }
  if (!(ecl_equal(v1x,_ecl_static_5))) { goto L8; }
  value0 = VV[78];
  cl_env_copy->nvalues = 1;
  return value0;
L8:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for REMOVE-KEYS                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L42remove_keys(cl_object v1key_names, cl_object v2args)
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
   cl_object v5val;
   if (ecl_unlikely(!ECL_LISTP(v2args))) FEtype_error_list(v2args);
   v3 = v2args;
   v4name = ECL_NIL;
   v5val = ECL_NIL;
   {
    cl_object v6;
    cl_object v7;
    v6 = ecl_list1(ECL_NIL);
    v7 = v6;
L7:;
    if (!(ECL_ATOM(v3))) { goto L9; }
    goto L8;
L9:;
    {
     cl_object v8;
     v8 = v3;
     v4name = ecl_car(v8);
     v8 = ecl_cdr(v8);
     v5val = ecl_car(v8);
    }
    {
     cl_object v8;
     v8 = ecl_cddr(v3);
     if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
     v3 = v8;
    }
    {
     cl_object v8;
     v8 = ecl_symbol_name(v4name);
     {
      cl_object v9;
      v9 = v1key_names;
      goto L28;
L27:;
      {
       cl_object v10;
       cl_object v11;
       if (ecl_unlikely(ECL_ATOM(v9))) FEtype_error_cons(v9);
       v10 = v9;
       v11 = ECL_CONS_CAR(v10);
       T0 = ecl_symbol_name(v11);
       if (Null(ecl_function_dispatch(cl_env_copy,ECL_SYM("EQUAL",335))(2, v8, T0))) { goto L30; }
       if ((v10)!=ECL_NIL) { goto L22; }
       goto L23;
      }
L30:;
      v9 = ECL_CONS_CDR(v9);
L28:;
      if (v9==ECL_NIL) { goto L37; }
      goto L27;
L37:;
     }
    }
L23:;
    {
     cl_object v8;
     v8 = cl_list(2, v4name, v5val);
     if (ecl_unlikely(ECL_ATOM(v7))) FEtype_error_cons(v7);
     T1 = v7;
     (ECL_CONS_CDR(T1)=v8,T1);
     T0 = v8;
    }
    v7 = ecl_cdr(T0);
L22:;
    goto L7;
L8:;
    value0 = ecl_cdr(v6);
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for REMOVE-KEYWORD                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L43remove_keyword(cl_object v1key, cl_object v2args)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4k;
   cl_object v5v;
   if (ecl_unlikely(!ECL_LISTP(v2args))) FEtype_error_list(v2args);
   v3 = v2args;
   v4k = ECL_NIL;
   v5v = ECL_NIL;
   {
    cl_object v6;
    cl_object v7;
    v6 = ecl_list1(ECL_NIL);
    v7 = v6;
L7:;
    if (!(ECL_ATOM(v3))) { goto L9; }
    goto L8;
L9:;
    {
     cl_object v8;
     v8 = v3;
     v4k = ecl_car(v8);
     v8 = ecl_cdr(v8);
     v5v = ecl_car(v8);
    }
    {
     cl_object v8;
     v8 = ecl_cddr(v3);
     if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
     v3 = v8;
    }
    if ((v4k)==(v1key)) { goto L22; }
    {
     cl_object v8;
     v8 = cl_list(2, v4k, v5v);
     if (ecl_unlikely(ECL_ATOM(v7))) FEtype_error_cons(v7);
     T1 = v7;
     (ECL_CONS_CDR(T1)=v8,T1);
     T0 = v8;
    }
    v7 = ecl_cdr(T0);
L22:;
    goto L7;
L8:;
    value0 = ecl_cdr(v6);
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for GETENV                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L44getenv(cl_object v1x)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = si_getenv(v1x);
  return value0;
 }
}
/*	function definition for DIRECTORY-PATHNAME-P                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L46directory_pathname_p(cl_object v1pathname)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1pathname)) { goto L1; }
  {
   cl_object v2pathname;
   v2pathname = cl_pathname(v1pathname);
   if ((cl_wild_pathname_p(1, v2pathname))!=ECL_NIL) { goto L5; }
   T0 = cl_pathname_name(1, v2pathname);
   if (Null(LC45check_one(T0))) { goto L5; }
   T0 = cl_pathname_type(1, v2pathname);
   if (Null(LC45check_one(T0))) { goto L5; }
   value0 = ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
L5:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function CHECK-ONE                                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC45check_one(cl_object v1x)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,ECL_SYM("EQUAL",335))(2, v1x, ECL_NIL))) { goto L5; }
  value0 = VV[87];
  goto L3;
L5:;
  value0 = ECL_NIL;
  goto L3;
L3:;
  if ((value0)!=ECL_NIL) { goto L2; }
  if (Null(ecl_function_dispatch(cl_env_copy,ECL_SYM("EQUAL",335))(2, v1x, ECL_SYM("UNSPECIFIC",1319)))) { goto L9; }
  value0 = VV[88];
  goto L7;
L9:;
  value0 = ECL_NIL;
  goto L7;
L7:;
  if ((value0)!=ECL_NIL) { goto L2; }
  if (Null(ecl_function_dispatch(cl_env_copy,ECL_SYM("EQUAL",335))(2, v1x, _ecl_static_6))) { goto L12; }
  value0 = VV[89];
  cl_env_copy->nvalues = 1;
  return value0;
L12:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for ENSURE-DIRECTORY-PATHNAME             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L47ensure_directory_pathname(cl_object v1pathspec)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_STRINGP(v1pathspec))) { goto L1; }
  v1pathspec = cl_pathname(v1pathspec);
  goto TTL;
L1:;
  if ((cl_pathnamep(v1pathspec))!=ECL_NIL) { goto L5; }
  value0 = cl_error(2, _ecl_static_11, v1pathspec);
  return value0;
L5:;
  if (Null(cl_wild_pathname_p(1, v1pathspec))) { goto L7; }
  value0 = cl_error(2, _ecl_static_12, v1pathspec);
  return value0;
L7:;
  if (Null(ecl_function_dispatch(cl_env_copy,VV[86])(1, v1pathspec) /*  DIRECTORY-PATHNAME-P */)) { goto L9; }
  value0 = v1pathspec;
  cl_env_copy->nvalues = 1;
  return value0;
L9:;
  value0 = cl_pathname_directory(1, v1pathspec);
  if ((value0)!=ECL_NIL) { goto L13; }
  T0 = ecl_list1(ECL_SYM("RELATIVE",1299));
  goto L11;
L13:;
  T0 = value0;
  goto L11;
L11:;
  T1 = cl_file_namestring(v1pathspec);
  T2 = ecl_list1(T1);
  T3 = ecl_append(T0,T2);
  value0 = cl_make_pathname(10, ECL_SYM("DIRECTORY",1219), T3, ECL_SYM("NAME",1273), ECL_NIL, ECL_SYM("TYPE",1318), ECL_NIL, ECL_SYM("VERSION",1326), ECL_NIL, ECL_SYM("DEFAULTS",1216), v1pathspec);
  return value0;
 }
}
/*	function definition for ABSOLUTE-PATHNAME-P                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L48absolute_pathname_p(cl_object v1pathspec)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((cl_pathnamep(v1pathspec))!=ECL_NIL) { goto L4; }
  if (!(ECL_STRINGP(v1pathspec))) { goto L2; }
  goto L3;
L4:;
L3:;
  T0 = cl_pathname(v1pathspec);
  T1 = cl_pathname_directory(1, T0);
  T2 = ecl_car(T1);
  value0 = ecl_make_bool((ECL_SYM("ABSOLUTE",1196))==(T2));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for COERCE-PATHNAME                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L49coerce_pathname(cl_narg narg, cl_object v1name, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2type;
  cl_object v3defaults;
  ecl_va_list args; ecl_va_start(args,v1name,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L49coerce_pathnamekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v2type = keyvars[0];
   v3defaults = keyvars[1];
  }
  if (v1name==ECL_NIL) { goto L3; }
  if (Null(cl_pathnamep(v1name))) { goto L1; }
  goto L2;
L3:;
L2:;
  value0 = v1name;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (!(ECL_SYMBOLP(v1name))) { goto L5; }
  T0 = cl_string_downcase(1, v1name);
  value0 = L49coerce_pathname(5, T0, ECL_SYM("TYPE",1318), v2type, ECL_SYM("DEFAULTS",1216), v3defaults);
  return value0;
L5:;
  if (!(ECL_STRINGP(v1name))) { goto L7; }
  {
   cl_object v5;                                  /*  RELATIVE        */
   cl_object v6;                                  /*  PATH            */
   cl_object v7;                                  /*  FILENAME        */
   {
    bool v8;
    v8 = (v2type)==(ECL_SYM("DIRECTORY",1219));
    value0 = ecl_function_dispatch(cl_env_copy,VV[75])(5, v1name, VV[96], ecl_make_bool(v8), VV[97], ECL_T) /*  COMPONENT-NAME-TO-PATHNAME-COMPONENTS */;
   }
   v5 = value0;
   {
    const int v8 = cl_env_copy->nvalues;
    cl_object v9;
    v9 = (v8<=1)? ECL_NIL : cl_env_copy->values[1];
    v6 = v9;
    v9 = (v8<=2)? ECL_NIL : cl_env_copy->values[2];
    v7 = v9;
   }
   {
    cl_object v9;                                 /*  NAME            */
    cl_object v10;                                /*  TYPE            */
    if ((v2type)==(ECL_SYM("DIRECTORY",1219))) { goto L13; }
    if (!(v7==ECL_NIL)) { goto L11; }
    goto L12;
L13:;
L12:;
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = ECL_NIL;
    cl_env_copy->values[0] = ECL_NIL;
    value0 = cl_env_copy->values[0];
    goto L10;
L11:;
    if (Null(v2type)) { goto L15; }
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = v2type;
    cl_env_copy->values[0] = v7;
    value0 = cl_env_copy->values[0];
    goto L10;
L15:;
    value0 = ecl_function_dispatch(cl_env_copy,VV[71])(1, v7) /*  SPLIT-NAME-TYPE */;
L10:;
    v9 = value0;
    {
     const int v11 = cl_env_copy->nvalues;
     cl_object v12;
     v12 = (v11<=1)? ECL_NIL : cl_env_copy->values[1];
     v10 = v12;
    }
    T0 = CONS(v5,v6);
    if (Null(v3defaults)) { goto L18; }
    T1 = cl_list(2, ECL_SYM("DEFAULTS",1216), v3defaults);
    goto L17;
L18:;
    T1 = ECL_NIL;
L17:;
    value0 = cl_apply(8, ECL_SYM("MAKE-PATHNAME",531), ECL_SYM("DIRECTORY",1219), T0, ECL_SYM("NAME",1273), v9, ECL_SYM("TYPE",1318), v10, T1);
    return value0;
   }
  }
L7:;
  value0 = si_etypecase_error(v1name, VV[98]);
  return value0;
 }
}
/*	function definition for MERGE-COMPONENT-NAME-TYPE             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L50merge_component_name_type(cl_narg narg, cl_object v1name, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2type;
  cl_object v3defaults;
  ecl_va_list args; ecl_va_start(args,v1name,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L50merge_component_name_typekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v2type = keyvars[0];
   v3defaults = keyvars[1];
  }
  (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(1, _ecl_static_13) /*  WARN */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[95])(5, v1name, ECL_SYM("TYPE",1318), v2type, ECL_SYM("DEFAULTS",1216), v3defaults) /*  COERCE-PATHNAME */;
  return value0;
 }
}
/*	function definition for SUBPATHNAME                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L51subpathname(cl_narg narg, cl_object v1pathname, cl_object v2subpath, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3type;
  ecl_va_list args; ecl_va_start(args,v2subpath,narg,2);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L51subpathnamekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3type = keyvars[0];
  }
  if (Null(v1pathname)) { goto L2; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[95])(3, v2subpath, ECL_SYM("TYPE",1318), v3type) /*  COERCE-PATHNAME */;
  T1 = ecl_function_dispatch(cl_env_copy,VV[36])(1, v1pathname) /*  PATHNAME-DIRECTORY-PATHNAME */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[51])(2, T0, T1) /*  MERGE-PATHNAMES* */;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for SUBPATHNAME*                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L52subpathname_(cl_narg narg, cl_object v1pathname, cl_object v2subpath, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3type;
  ecl_va_list args; ecl_va_start(args,v2subpath,narg,2);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L52subpathname_keys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3type = keyvars[0];
  }
  if (Null(v1pathname)) { goto L2; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[91])(1, v1pathname) /*  ENSURE-DIRECTORY-PATHNAME */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[102])(4, T0, v2subpath, ECL_SYM("TYPE",1318), v3type) /*  SUBPATHNAME */;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for LENGTH=N-P                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L53length_n_p(cl_object v1x, cl_object v2n)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = v2n;
   {
    cl_object v4;
    v4 = ecl_make_fixnum(0);
    if (!(ECL_FIXNUMP(v3)||ECL_BIGNUMP(v3))) { goto L7; }
    v4 = v3;
    if (ecl_number_compare(v4,ecl_make_fixnum(0))>=0) { goto L3; }
    goto L4;
L7:;
    goto L4;
   }
L4:;
   v2n = si_do_check_type(v3, VV[106], ECL_NIL, VV[107]);
L3:;
  }
  {
   cl_object v3l;
   v3l = ECL_NIL;
   {
    cl_object v4i;
    T0 = cl_realp(v2n);
    if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("REAL",703),v2n);
    v4i = v2n;
    v3l = v1x;
L15:;
    if (!(ecl_zerop(v4i))) { goto L19; }
    value0 = ecl_make_bool(v3l==ECL_NIL);
    cl_env_copy->nvalues = 1;
    return value0;
L19:;
    if (ECL_CONSP(v3l)) { goto L18; }
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
L18:;
    v3l = ecl_cdr(v3l);
    v4i = ecl_one_minus(v4i);
    goto L15;
   }
  }
 }
}
/*	function definition for STRING-SUFFIX-P                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L54string_suffix_p(cl_object v1s, cl_object v2suffix)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = v1s;
   if (ECL_STRINGP(v3)) { goto L3; }
   v1s = si_do_check_type(v3, ECL_SYM("STRING",805), ECL_NIL, VV[76]);
L3:;
  }
  {
   cl_object v3;
   v3 = v2suffix;
   if (ECL_STRINGP(v3)) { goto L8; }
   v2suffix = si_do_check_type(v3, ECL_SYM("STRING",805), ECL_NIL, VV[110]);
L8:;
  }
  {
   cl_object v3start;
   {
    cl_fixnum v4;
    v4 = ecl_length(v1s);
    {
     cl_fixnum v5;
     v5 = ecl_length(v2suffix);
     v3start = ecl_minus(ecl_make_fixnum(v4),ecl_make_fixnum(v5));
    }
   }
   if (!(ecl_number_compare(ecl_make_fixnum(0),v3start)<=0)) { goto L13; }
   value0 = cl_string_equal(4, v1s, v2suffix, ECL_SYM("START1",1311), v3start);
   return value0;
L13:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for READ-FILE-FORMS                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L55read_file_forms(cl_object volatile v1file)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   volatile cl_object v2in;
   v2in = cl_open(1, v1file);
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
      {
       cl_object v6eof;
       v6eof = ecl_list1(ECL_NIL);
       {
        cl_object v7form;
        v7form = ECL_NIL;
        {
         cl_object v8;
         cl_object v9;
         v8 = ecl_list1(ECL_NIL);
         v9 = v8;
L11:;
         v7form = cl_read(3, v2in, ECL_NIL, v6eof);
         if (!((v7form)==(v6eof))) { goto L15; }
         goto L12;
L15:;
         if (ecl_unlikely(ECL_ATOM(v9))) FEtype_error_cons(v9);
         T0 = v9;
         v9 = ecl_list1(v7form);
         (ECL_CONS_CDR(T0)=v9,T0);
         goto L11;
L12:;
         cl_env_copy->values[0] = ecl_cdr(v8);
         cl_env_copy->nvalues = 1;
         goto L6;
        }
       }
      }
L6:;
      ecl_stack_frame_push_values(v5);
      if (Null(v2in)) { goto L23; }
      cl_close(1, v2in);
L23:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v5);
     }
     ecl_stack_frame_close(_ecl_inner_frame);
    }
    }
    ecl_frs_pop(cl_env_copy);
    v4=ecl_stack_push_values(cl_env_copy);
    if (Null(v2in)) { goto L25; }
    cl_close(3, v2in, ECL_SYM("ABORT",1195), ECL_T);
L25:;
    ecl_stack_pop_values(cl_env_copy,v4);
    if (unwinding) ecl_unwind(cl_env_copy,next_fr);
    ECL_STACK_SET_INDEX(cl_env_copy,v3);
    return cl_env_copy->values[0];
   }
  }
 }
}
/*	function definition for PATHNAME-ROOT                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L56pathname_root(cl_object v1pathname)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_make_pathname(10, ECL_SYM("DIRECTORY",1219), VV[52], ECL_SYM("NAME",1273), ECL_NIL, ECL_SYM("TYPE",1318), ECL_NIL, ECL_SYM("VERSION",1326), ECL_NIL, ECL_SYM("DEFAULTS",1216), v1pathname);
  return value0;
 }
}
/*	function definition for PROBE-FILE*                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L57probe_file_(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(v1p==ECL_NIL)) { goto L1; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (!(ECL_STRINGP(v1p))) { goto L3; }
  v1p = cl_parse_namestring(1, v1p);
  goto TTL;
L3:;
  if (Null(cl_pathnamep(v1p))) { goto L7; }
  if ((cl_wild_pathname_p(1, v1p))!=ECL_NIL) { goto L9; }
  value0 = cl_probe_file(v1p);
  return value0;
L9:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L7:;
  value0 = si_etypecase_error(v1p, VV[117]);
  return value0;
 }
}
/*	function definition for TRUENAMIZE                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L60truenamize(volatile cl_narg narg, cl_object volatile v1pathname, ...)
{
 cl_object T0, T1, T2, T3;
 volatile cl_object lex0[2];
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  volatile cl_object v2defaults;
  va_list args; va_start(args,v1pathname);
  {
   int i = 1;
   if (i >= narg) {
    v2defaults = ecl_symbol_value(ECL_SYM("*DEFAULT-PATHNAME-DEFAULTS*",32));
   } else {
    i++;
    v2defaults = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (v1pathname==ECL_NIL) { goto L4; }
  if (Null(si_logical_pathname_p(v1pathname))) { goto L2; }
  goto L3;
L4:;
L3:;
  value0 = v1pathname;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  T0 = ecl_function_dispatch(cl_env_copy,VV[51])(2, v1pathname, v2defaults) /*  MERGE-PATHNAMES* */;
  lex0[0] = T0;                                   /*  P               */
  if (Null(si_logical_pathname_p(lex0[0]))) { goto L6; }
  value0 = lex0[0];
  cl_env_copy->nvalues = 1;
  return value0;
L6:;
  {
   cl_object v3found;
   v3found = ecl_function_dispatch(cl_env_copy,VV[116])(1, lex0[0]) /*  PROBE-FILE* */;
   if (Null(v3found)) { goto L8; }
   value0 = v3found;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L8:;
  if ((ecl_function_dispatch(cl_env_copy,VV[93])(1, lex0[0]) /*  ABSOLUTE-PATHNAME-P */)!=ECL_NIL) { goto L11; }
  {
   volatile cl_object v3true_defaults;
   {
    volatile cl_object env1 = env0;
    env1 = ECL_NIL;
    CLV0 = env1 = CONS(ECL_NIL,env1);
    {
     volatile cl_object env2 = env1;
     CLV1 = env2 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env2); /*  TAGBODY */
     if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV1))) {
     if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L14;
     ecl_internal_error("GO found an inexistent tag");
     }
     {cl_object v4;
      v4 = ECL_NIL;
      v4 = ecl_make_cclosure_va((cl_objectfn)LC58__g353,env2,Cblock);
      T0 = v4;
     }
     T1 = CONS(ECL_SYM("ERROR",337),T0);
     T2 = ecl_list1(T1);
     T3 = CONS(T2,ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5)));
     ecl_bds_bind(cl_env_copy,ECL_SYM("*HANDLER-CLUSTERS*",5),T3); /*  *HANDLER-CLUSTERS* */
     value0 = cl_truename(v2defaults);
     ecl_frs_pop(cl_env_copy);
     v3true_defaults = value0;
     ecl_bds_unwind1(cl_env_copy);
     goto L13;
L14:;
     {
      cl_object v4condition;
      v4condition = ECL_CONS_CAR(CLV0);
      cl_env_copy->nvalues = 2;
      cl_env_copy->values[1] = v4condition;
      cl_env_copy->values[0] = ECL_NIL;
      value0 = cl_env_copy->values[0];
      ecl_frs_pop(cl_env_copy);
      v3true_defaults = value0;
      goto L13;
     }
    }
   }
L13:;
   if (Null(v3true_defaults)) { goto L11; }
   lex0[0] = cl_merge_pathnames(2, v1pathname, v3true_defaults);
  }
L11:;
  if ((ecl_function_dispatch(cl_env_copy,VV[93])(1, lex0[0]) /*  ABSOLUTE-PATHNAME-P */)!=ECL_NIL) { goto L21; }
  value0 = lex0[0];
  cl_env_copy->nvalues = 1;
  return value0;
L21:;
  T0 = ecl_function_dispatch(cl_env_copy,VV[114])(1, lex0[0]) /*  PATHNAME-ROOT */;
  T1 = ecl_function_dispatch(cl_env_copy,VV[116])(1, T0) /*  PROBE-FILE* */;
  lex0[1] = T1;                                   /*  SOFAR           */
  if ((lex0[1])!=ECL_NIL) { goto L23; }
  value0 = lex0[0];
  cl_env_copy->nvalues = 1;
  return value0;
L23:;
  {
   cl_object v3directory;
   T0 = cl_pathname_directory(1, lex0[0]);
   v3directory = ecl_function_dispatch(cl_env_copy,VV[38])(1, T0) /*  NORMALIZE-PATHNAME-DIRECTORY-COMPONENT */;
   {
    cl_object v4;
    cl_object v5component;
    cl_object v6;
    v4 = ecl_cdr(v3directory);
    v5component = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
    v6 = v4;
    {
     cl_object v7rest;
     v7rest = ecl_cdr(v3directory);
     {
      cl_object v8more;
      v8more = ECL_NIL;
      if (!(ecl_endp(v6))) { goto L34; }
      goto L33;
L34:;
      v5component = _ecl_car(v6);
      {
       cl_object v9;
       v9 = _ecl_cdr(v6);
       if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
       v6 = v9;
      }
L32:;
      if (!(ECL_ATOM(v7rest))) { goto L42; }
      goto L33;
L42:;
      T0 = cl_list(2, ECL_SYM("RELATIVE",1299), v5component);
      T1 = cl_make_pathname(2, ECL_SYM("DIRECTORY",1219), T0);
      T2 = ecl_function_dispatch(cl_env_copy,VV[51])(2, T1, lex0[1]) /*  MERGE-PATHNAMES* */;
      v8more = ecl_function_dispatch(cl_env_copy,VV[116])(1, T2) /*  PROBE-FILE* */;
      if (Null(v8more)) { goto L47; }
      lex0[1] = v8more;
      goto L46;
L47:;
      value0 = LC59solution(lex0, v7rest);
      return value0;
L46:;
      if (!(ecl_endp(v6))) { goto L50; }
      goto L33;
L50:;
      v5component = _ecl_car(v6);
      {
       cl_object v9;
       v9 = _ecl_cdr(v6);
       if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
       v6 = v9;
      }
      v7rest = _ecl_cdr(v7rest);
      goto L32;
L33:;
      value0 = LC59solution(lex0, ECL_NIL);
      return value0;
     }
    }
   }
  }
 }
}
/*	closure G353                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC58__g353(cl_narg narg, cl_object v1si__temp, ...)
{
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  TAGBODY         */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  ECL_CONS_CAR(CLV0) = v1si__temp;
  cl_go(ECL_CONS_CAR(CLV1),ecl_make_fixnum(0));
 }
 }
}
/*	local function SOLUTION                                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC59solution(volatile cl_object *lex0, cl_object v1directories)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = CONS(ECL_SYM("RELATIVE",1299),v1directories);
  T1 = cl_pathname_name(1, lex0[0]);
  T2 = cl_pathname_type(1, lex0[0]);
  T3 = cl_pathname_version(lex0[0]);
  T4 = cl_make_pathname(12, ECL_SYM("HOST",1243), ECL_NIL, ECL_SYM("DEVICE",1217), ECL_NIL, ECL_SYM("DIRECTORY",1219), T0, ECL_SYM("NAME",1273), T1, ECL_SYM("TYPE",1318), T2, ECL_SYM("VERSION",1326), T3);
  value0 = ecl_function_dispatch(cl_env_copy,VV[51])(2, T4, lex0[1]) /*  MERGE-PATHNAMES* */;
  return value0;
 }
}
/*	function definition for RESOLVE-SYMLINKS                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L61resolve_symlinks(cl_object v1path)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[119])(1, v1path) /*  TRUENAMIZE */;
  return value0;
 }
}
/*	function definition for RESOLVE-SYMLINKS*                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L62resolve_symlinks_(cl_object v1path)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_symbol_value(VV[18]))) { goto L1; }
  if (Null(v1path)) { goto L4; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[121])(1, v1path) /*  RESOLVE-SYMLINKS */;
  return value0;
L4:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  value0 = v1path;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for ENSURE-PATHNAME-ABSOLUTE              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L63ensure_pathname_absolute(cl_object v1path)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[93])(1, v1path) /*  ABSOLUTE-PATHNAME-P */)) { goto L1; }
  value0 = v1path;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (!(ECL_STRINGP(v1path))) { goto L3; }
  v1path = cl_pathname(v1path);
  goto TTL;
L3:;
  if ((cl_pathnamep(v1path))!=ECL_NIL) { goto L7; }
  value0 = cl_error(2, _ecl_static_14, v1path);
  return value0;
L7:;
  {
   cl_object v2resolved;
   v2resolved = ecl_function_dispatch(cl_env_copy,VV[121])(1, v1path) /*  RESOLVE-SYMLINKS */;
   goto L12;
L11:;
   si_assert_failure(1, VV[126]);
L12:;
   if ((ecl_function_dispatch(cl_env_copy,VV[93])(1, v2resolved) /*  ABSOLUTE-PATHNAME-P */)!=ECL_NIL) { goto L15; }
   goto L11;
L15:;
   value0 = v2resolved;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for DEFAULT-DIRECTORY                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L64default_directory()
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[36])(1, ecl_symbol_value(ECL_SYM("*DEFAULT-PATHNAME-DEFAULTS*",32))) /*  PATHNAME-DIRECTORY-PATHNAME */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[119])(1, T0) /*  TRUENAMIZE */;
  return value0;
 }
}
/*	function definition for LISPIZE-PATHNAME                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L65lispize_pathname(cl_object v1input_file)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_make_pathname(4, ECL_SYM("TYPE",1318), _ecl_static_15, ECL_SYM("DEFAULTS",1216), v1input_file);
  return value0;
 }
}
/*	function definition for WILDEN                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L66wilden(cl_object v1path)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[51])(2, ecl_symbol_value(VV[136]), v1path) /*  MERGE-PATHNAMES* */;
  return value0;
 }
}
/*	function definition for DIRECTORY-SEPARATOR-FOR-HOST          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L67directory_separator_for_host(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1pathname;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1pathname = ecl_symbol_value(ECL_SYM("*DEFAULT-PATHNAME-DEFAULTS*",32));
   } else {
    i++;
    v1pathname = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v2foo;
   v2foo = cl_make_pathname(4, ECL_SYM("DIRECTORY",1219), VV[140], ECL_SYM("DEFAULTS",1216), v1pathname);
   T0 = cl_namestring(v2foo);
   value0 = ecl_function_dispatch(cl_env_copy,VV[64])(1, T0) /*  LAST-CHAR */;
   return value0;
  }
 }
}
/*	function definition for DIRECTORIZE-PATHNAME-HOST-DEVICE      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L69directorize_pathname_host_device(cl_object v1pathname)
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2root;
   cl_object v3wild_root;
   cl_object v4absolute_pathname;
   cl_object v5root_namestring;
   cl_object v6root_string;
   cl_object env1 = env0;
   v2root = ecl_function_dispatch(cl_env_copy,VV[114])(1, v1pathname) /*  PATHNAME-ROOT */;
   v3wild_root = ecl_function_dispatch(cl_env_copy,VV[137])(1, v2root) /*  WILDEN */;
   v4absolute_pathname = ecl_function_dispatch(cl_env_copy,VV[51])(2, v1pathname, v2root) /*  MERGE-PATHNAMES* */;
   T0 = ecl_function_dispatch(cl_env_copy,VV[139])(1, v2root) /*  DIRECTORY-SEPARATOR-FOR-HOST */;
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(T0,env1);                   /*  SEPARATOR       */
   v5root_namestring = cl_namestring(v2root);
   {cl_object v7;
    v7 = ECL_NIL;
    v7 = ecl_make_cclosure_va((cl_objectfn)LC68__g361,env1,Cblock);
    T0 = v7;
   }
   v6root_string = cl_substitute_if(3, CODE_CHAR(47), T0, v5root_namestring);
   {
    cl_object v8;                                 /*  PATH            */
    value0 = ecl_function_dispatch(cl_env_copy,VV[75])(3, v6root_string, VV[96], ECL_T) /*  COMPONENT-NAME-TO-PATHNAME-COMPONENTS */;
    {
     const int v9 = cl_env_copy->nvalues;
     cl_object v10;
     v10 = (v9<=1)? ECL_NIL : cl_env_copy->values[1];
     v8 = v10;
    }
    {
     cl_object v9new_base;
     T0 = CONS(ECL_SYM("ABSOLUTE",1196),v8);
     v9new_base = cl_make_pathname(4, ECL_SYM("DEFAULTS",1216), v2root, ECL_SYM("DIRECTORY",1219), T0);
     T0 = ecl_function_dispatch(cl_env_copy,VV[137])(1, v9new_base) /*  WILDEN */;
     value0 = cl_translate_pathname(3, v4absolute_pathname, v3wild_root, T0);
     return value0;
    }
   }
  }
 }
}
/*	closure G361                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC68__g361(cl_narg narg, cl_object v1x, ...)
{
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  SEPARATOR       */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = ecl_make_bool(((v1x)==ECL_CODE_CHAR((ecl_character)(58))));
  if ((value0)!=ECL_NIL) { goto L2; }
  value0 = ecl_make_bool(ecl_eql(v1x,ECL_CONS_CAR(CLV0)));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
 }
}
/*	local function G362                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC71__g362()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {cl_object v1;
   v1 = ECL_NIL;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC70__g363,ECL_NIL,Cblock,2);
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G363                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC70__g363(cl_object v1c, cl_object v2s)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[799])(1, v1c) /*  FORMAT-CONTROL */;
  T1 = ecl_function_dispatch(cl_env_copy,VV[800])(1, v1c) /*  FORMAT-ARGUMENTS */;
  value0 = cl_apply(4, ECL_SYM("FORMAT",387), v2s, T0, T1);
  return value0;
 }
}
/*	local function G364                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC73__g364()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {cl_object v1;
   v1 = ECL_NIL;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC72__g365,ECL_NIL,Cblock,2);
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G365                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC72__g365(cl_object v1c, cl_object v2s)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[801])(1, v1c) /*  ERROR-NAME */;
  T1 = ecl_function_dispatch(cl_env_copy,VV[802])(1, v1c) /*  ERROR-PATHNAME */;
  T2 = ecl_function_dispatch(cl_env_copy,VV[803])(1, v1c) /*  ERROR-CONDITION */;
  value0 = cl_format(5, v2s, _ecl_static_27, T0, T1, T2);
  return value0;
 }
}
/*	local function G366                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC75__g366()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {cl_object v1;
   v1 = ECL_NIL;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC74__g367,ECL_NIL,Cblock,2);
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G367                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC74__g367(cl_object v1c, cl_object v2s)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[804])(1, v1c) /*  CIRCULAR-DEPENDENCY-COMPONENTS */;
  value0 = cl_format(3, v2s, _ecl_static_28, T0);
  return value0;
 }
}
/*	local function G368                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC77__g368()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {cl_object v1;
   v1 = ECL_NIL;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC76__g369,ECL_NIL,Cblock,2);
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G369                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC76__g369(cl_object v1c, cl_object v2s)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[805])(1, v1c) /*  DUPLICATE-NAMES-NAME */;
  value0 = cl_format(3, v2s, _ecl_static_29, T0);
  return value0;
 }
}
/*	local function G370                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC79__g370()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {cl_object v1;
   v1 = ECL_NIL;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC78__g371,ECL_NIL,Cblock,2);
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G371                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC78__g371(cl_object v1c, cl_object v2s)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_type_of(v1c);
  T1 = ecl_function_dispatch(cl_env_copy,VV[806])(1, v1c) /*  ERROR-OPERATION */;
  T2 = ecl_function_dispatch(cl_env_copy,VV[807])(1, v1c) /*  ERROR-COMPONENT */;
  value0 = cl_format(5, v2s, _ecl_static_30, T0, T1, T2);
  return value0;
 }
}
/*	local function G372                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC81__g372()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {cl_object v1;
   v1 = ECL_NIL;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC80__g373,ECL_NIL,Cblock,2);
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G373                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC80__g373(cl_object v1c, cl_object v2s)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[808])(1, v1c) /*  CONDITION-FORMAT */;
  T1 = ecl_function_dispatch(cl_env_copy,VV[809])(1, v1c) /*  CONDITION-FORM */;
  T2 = ecl_function_dispatch(cl_env_copy,VV[810])(1, v1c) /*  CONDITION-LOCATION */;
  T3 = ecl_function_dispatch(cl_env_copy,VV[811])(1, v1c) /*  CONDITION-ARGUMENTS */;
  T4 = cl_listX(3, T1, T2, T3);
  value0 = cl_format(4, v2s, _ecl_static_31, T0, T4);
  return value0;
 }
}
/*	local function G374                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC82__g374()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = _ecl_static_32;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G375                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC83__g375()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = _ecl_static_33;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G376                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC84__g376()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_make_hash_table(0);
  return value0;
 }
}
/*	function definition for COMPONENT-FIND-PATH                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L85component_find_path(cl_object v1component)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2c;
   v2c = ECL_NIL;
   {
    cl_object v3;
    cl_object v4;
    v3 = ecl_list1(ECL_NIL);
    v4 = v3;
    v2c = v1component;
L5:;
    if ((v2c)!=ECL_NIL) { goto L9; }
    goto L6;
L9:;
    if (ecl_unlikely(ECL_ATOM(v4))) FEtype_error_cons(v4);
    T1 = v4;
    T2 = ecl_function_dispatch(cl_env_copy,VV[813])(1, v2c) /*  COMPONENT-NAME */;
    v4 = ecl_list1(T2);
    (ECL_CONS_CDR(T1)=v4,T1);
    v2c = ecl_function_dispatch(cl_env_copy,VV[814])(1, v2c) /*  COMPONENT-PARENT */;
    goto L5;
L6:;
    T0 = ecl_cdr(v3);
    goto L1;
   }
  }
L1:;
  value0 = cl_reverse(T0);
  return value0;
 }
}
/*	local function G379                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC87__g379(cl_object v1c, cl_object v2stream)
{
 cl_object env0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1c,env0);                   /*  C               */
  CLV1 = env0 = CONS(v2stream,env0);              /*  STREAM          */
  {cl_object v3;
   v3 = ECL_NIL;
   v3 = ecl_make_cclosure_va((cl_objectfn)LC86si___print_unreadable_object_body_,env0,Cblock);
   value0 = si_print_unreadable_object_function(ECL_CONS_CAR(CLV0), ECL_CONS_CAR(CLV1), ECL_T, ECL_NIL, v3);
   return value0;
  }
 }
}
/*	closure .PRINT-UNREADABLE-OBJECT-BODY.                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC86si___print_unreadable_object_body_(cl_narg narg, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  STREAM          */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=0)) FEwrong_num_arguments_anonym();
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[189])(1, ECL_CONS_CAR(CLV0)) /*  COMPONENT-FIND-PATH */;
  value0 = cl_format(3, ECL_CONS_CAR(CLV1), _ecl_static_34, T0);
  return value0;
 }
 }
}
/*	local function G380                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC88__g380(cl_object v1c, cl_object v2s)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)))) { goto L2; }
  T1 = ecl_car(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
  T2 = cl_list(2, v1c, ECL_NIL);
  T3 = ecl_cdr(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
  T0 = ecl_function_dispatch(cl_env_copy,T1)(2, T2, T3);
  goto L1;
L2:;
  T0 = cl_error(1, _ecl_static_36);
L1:;
  T1 = ecl_function_dispatch(cl_env_copy,VV[815])(1, v1c) /*  MISSING-REQUIRED-BY */;
  value0 = cl_format(4, v2s, _ecl_static_35, T0, T1);
  return value0;
 }
}
/*	function definition for SYSDEF-ERROR                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L89sysdef_error(cl_narg narg, cl_object v1format, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2arguments;
  ecl_va_list args; ecl_va_start(args,v1format,narg,1);
  v2arguments = cl_grab_rest_args(args);
  ecl_va_end(args);
  value0 = cl_error(5, VV[174], ECL_SYM("FORMAT-CONTROL",1240), v1format, ECL_SYM("FORMAT-ARGUMENTS",1239), v2arguments);
  return value0;
 }
}
/*	local function G381                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC90__g381(cl_object v1c, cl_object v2s)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[817])(1, v1c) /*  MISSING-REQUIRES */;
  if (Null(ecl_function_dispatch(cl_env_copy,VV[818])(1, v1c) /*  MISSING-PARENT */)) { goto L2; }
  T2 = ecl_function_dispatch(cl_env_copy,VV[818])(1, v1c) /*  MISSING-PARENT */;
  T1 = L115coerce_name(T2);
  goto L1;
L2:;
  T1 = ECL_NIL;
L1:;
  value0 = cl_format(4, v2s, _ecl_static_37, T0, T1);
  return value0;
 }
}
/*	local function G382                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC91__g382(cl_object v1c, cl_object v2s)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[817])(1, v1c) /*  MISSING-REQUIRES */;
  T1 = ecl_function_dispatch(cl_env_copy,VV[819])(1, v1c) /*  MISSING-VERSION */;
  if (Null(ecl_function_dispatch(cl_env_copy,VV[818])(1, v1c) /*  MISSING-PARENT */)) { goto L2; }
  T3 = ecl_function_dispatch(cl_env_copy,VV[818])(1, v1c) /*  MISSING-PARENT */;
  T2 = L115coerce_name(T3);
  goto L1;
L2:;
  T2 = ECL_NIL;
L1:;
  value0 = cl_format(5, v2s, _ecl_static_38, T0, T1, T2);
  return value0;
 }
}
/*	local function G383                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC92__g383(cl_object v1component)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2it;
   v2it = ecl_function_dispatch(cl_env_copy,VV[814])(1, v1component) /*  COMPONENT-PARENT */;
   if (Null(v2it)) { goto L2; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[156])(1, v2it) /*  COMPONENT-SYSTEM */;
   return value0;
L2:;
   value0 = v1component;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for COMPUTE-MODULE-COMPONENTS-BY-NAME     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L93compute_module_components_by_name(cl_object v1module)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2hash;
   v2hash = cl_make_hash_table(2, ECL_SYM("TEST",1316), ECL_SYM("EQUAL",335));
   (cl_env_copy->function=ecl_fdefinition(VV[821]))->cfun.entry(2, v2hash, v1module) /*  (SETF MODULE-COMPONENTS-BY-NAME) */;
   {
    cl_object v3;
    cl_object v4c;
    cl_object v5;
    v3 = ecl_function_dispatch(cl_env_copy,VV[822])(1, v1module) /*  MODULE-COMPONENTS */;
    v4c = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v3))) FEtype_error_list(v3);
    v5 = v3;
    {
     cl_object v6name;
     v6name = ECL_NIL;
     {
      cl_object v7previous;
      v7previous = ECL_NIL;
L10:;
      if (!(ecl_endp(v5))) { goto L12; }
      goto L11;
L12:;
      v4c = _ecl_car(v5);
      {
       cl_object v8;
       v8 = _ecl_cdr(v5);
       if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
       v5 = v8;
      }
      v6name = ecl_function_dispatch(cl_env_copy,VV[813])(1, v4c) /*  COMPONENT-NAME */;
      T0 = ecl_function_dispatch(cl_env_copy,VV[823])(1, v1module) /*  MODULE-COMPONENTS-BY-NAME */;
      v7previous = ecl_gethash_safe(v6name,T0,ECL_NIL);
      if (Null(v7previous)) { goto L24; }
      cl_error(3, VV[177], ECL_SYM("NAME",1273), v6name);
L24:;
      T0 = ecl_function_dispatch(cl_env_copy,VV[823])(1, v1module) /*  MODULE-COMPONENTS-BY-NAME */;
      si_hash_set(v6name, T0, v4c);
      goto L10;
L11:;
     }
    }
   }
   value0 = v2hash;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for COMPONENT-PARENT-PATHNAME             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L94component_parent_pathname(cl_object v1component)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2parent;
   v2parent = ecl_function_dispatch(cl_env_copy,VV[814])(1, v1component) /*  COMPONENT-PARENT */;
   if (Null(v2parent)) { goto L2; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[157])(1, v2parent) /*  COMPONENT-PATHNAME */;
   return value0;
L2:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G398                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC95__g398(cl_object v1component)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_slot_boundp(v1component, VV[199]))) { goto L1; }
  value0 = cl_slot_value(v1component, VV[199]);
  return value0;
L1:;
  {
   cl_object v2pathname;
   T0 = ecl_function_dispatch(cl_env_copy,VV[158])(1, v1component) /*  COMPONENT-RELATIVE-PATHNAME */;
   T1 = ecl_function_dispatch(cl_env_copy,VV[197])(1, v1component) /*  COMPONENT-PARENT-PATHNAME */;
   T2 = ecl_function_dispatch(cl_env_copy,VV[36])(1, T1) /*  PATHNAME-DIRECTORY-PATHNAME */;
   v2pathname = ecl_function_dispatch(cl_env_copy,VV[51])(2, T0, T2) /*  MERGE-PATHNAMES* */;
   if (v2pathname==ECL_NIL) { goto L4; }
   if ((ecl_function_dispatch(cl_env_copy,VV[93])(1, v2pathname) /*  ABSOLUTE-PATHNAME-P */)!=ECL_NIL) { goto L4; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[189])(1, v1component) /*  COMPONENT-FIND-PATH */;
   cl_error(3, _ecl_static_39, v2pathname, T0);
L4:;
   (cl_env_copy->function=ECL_CONS_CAR(VV[825]))->cfun.entry(3, v2pathname, v1component, VV[199]) /*  (SETF SLOT-VALUE) */;
   value0 = v2pathname;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G402                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC96__g402(cl_object v1c, cl_object v2property)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T1 = cl_slot_value(v1c, VV[200]);
  T0 = ecl_assoc(v2property,T1);
  value0 = ecl_cdr(T0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G413                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC97__g413(cl_object v1new_value, cl_object v2c, cl_object v3property)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4a;
   T0 = cl_slot_value(v2c, VV[200]);
   v4a = ecl_assoc(v3property,T0);
   if (Null(v4a)) { goto L3; }
   if (ecl_unlikely(ECL_ATOM(v4a))) FEtype_error_cons(v4a);
   T0 = v4a;
   (ECL_CONS_CDR(T0)=v1new_value,T0);
   goto L1;
L3:;
   {
    cl_object v5;
    T0 = cl_slot_value(v2c, VV[200]);
    v5 = cl_acons(v3property, v1new_value, T0);
    (cl_env_copy->function=ECL_CONS_CAR(VV[825]))->cfun.entry(3, v5, v2c, VV[200]) /*  (SETF SLOT-VALUE) */;
   }
  }
L1:;
  value0 = v1new_value;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for ALWAYS-DEFAULT-ENCODING               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L98always_default_encoding(cl_object v1pathname)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_symbol_value(VV[201]);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for DETECT-ENCODING                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L99detect_encoding(cl_object v1pathname)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[205]))(1, v1pathname);
  return value0;
 }
}
/*	local function G421                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC100__g421(cl_object v1c)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2x;
   v2x = ECL_NIL;
   {
    cl_object v3;
    v3 = ECL_NIL;
    v2x = v1c;
L6:;
    if ((v2x)!=ECL_NIL) { goto L10; }
    goto L7;
L10:;
    v3 = ecl_function_dispatch(cl_env_copy,VV[828])(1, v2x) /*  %COMPONENT-ENCODING */;
    if (Null(v3)) { goto L12; }
    value0 = v3;
    goto L3;
L12:;
    v2x = ecl_function_dispatch(cl_env_copy,VV[814])(1, v2x) /*  COMPONENT-PARENT */;
    goto L6;
L7:;
    value0 = ECL_NIL;
   }
  }
L3:;
  if ((value0)!=ECL_NIL) { goto L2; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[157])(1, v1c) /*  COMPONENT-PATHNAME */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[206])(1, T0) /*  DETECT-ENCODING */;
  return value0;
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for DEFAULT-ENCODING-EXTERNAL-FORMAT      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L101default_encoding_external_format(cl_object v1encoding)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ecl_eql(v1encoding,ECL_SYM("DEFAULT",1215)))) { goto L1; }
  value0 = ECL_SYM("DEFAULT",1215);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (!(ecl_eql(v1encoding,ECL_SYM("UTF-8",1681)))) { goto L3; }
  value0 = ecl_symbol_value(VV[202]);
  cl_env_copy->nvalues = 1;
  return value0;
L3:;
  cl_cerror(3, _ecl_static_40, _ecl_static_41, v1encoding);
  value0 = ECL_SYM("DEFAULT",1215);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for ENCODING-EXTERNAL-FORMAT              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L102encoding_external_format(cl_object v1encoding)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[210]))(1, v1encoding);
  return value0;
 }
}
/*	local function G424                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC103__g424(cl_object v1c)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[161])(1, v1c) /*  COMPONENT-ENCODING */;
  value0 = L102encoding_external_format(T0);
  return value0;
 }
}
/*	local function G425                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC104__g425(cl_object v1c, cl_object v2version)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v2version)) { goto L4; }
  if ((cl_slot_boundp(v1c, VV[214]))!=ECL_NIL) { goto L1; }
  goto L2;
L4:;
  goto L2;
L2:;
  if (Null(v2version)) { goto L6; }
  (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(3, _ecl_static_42, v2version, v1c) /*  WARN */;
L6:;
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  T0 = ecl_function_dispatch(cl_env_copy,VV[831])(1, v1c) /*  COMPONENT-VERSION */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[162])(2, T0, v2version) /*  VERSION-SATISFIES */;
  return value0;
 }
}
/*	function definition for ASDF-VERSION                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L105asdf_version()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_symbol_value(VV[5]);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for PARSE-VERSION                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L106parse_version(cl_narg narg, cl_object v1string, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2on_error;
  va_list args; va_start(args,v1string);
  {
   int i = 1;
   if (i >= narg) {
    v2on_error = ECL_NIL;
   } else {
    i++;
    v2on_error = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (ECL_STRINGP(v1string)) { goto L5; }
  if (Null(v2on_error)) { goto L8; }
  if ((ecl_function_dispatch(cl_env_copy,v2on_error)(3, _ecl_static_43, VV[217], v1string))!=ECL_NIL) { goto L5; }
  goto L7;
L8:;
L7:;
  goto L3;
L5:;
  {
   cl_object v3prev;
   v3prev = ECL_NIL;
   {
    cl_object v4c;
    cl_object v5;
    cl_fixnum v6;
    cl_fixnum v7;
    v4c = ECL_NIL;
    if (ecl_unlikely(!ECL_VECTORP(v1string))) FEtype_error_vector(v1string);
    v5 = v1string;
    v6 = 0;
    v7 = 0;
    v7 = ecl_length(v5);
    v3prev = ECL_NIL;
L19:;
    if (!((v6)>=(v7))) { goto L25; }
    goto L20;
L25:;
    {
     cl_fixnum v8;
     if (ecl_unlikely((v6)>=(v5)->vector.dim))
           FEwrong_index(ECL_NIL,v5,-1,ecl_make_fixnum(v6),(v5)->vector.dim);
     v8 = v6;
     v4c = ecl_aref_unsafe(v5,v8);
    }
    {
     cl_object v8;
     v8 = ecl_make_integer((v6)+1);
     {
      bool v9;
      v9 = ECL_FIXNUMP(v8);
      if (ecl_unlikely(!(v9)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v8);
     }
     v6 = ecl_fixnum(v8);
    }
    if ((cl_digit_char_p(1, v4c))!=ECL_NIL) { goto L36; }
    if (!(((v4c)==ECL_CODE_CHAR((ecl_character)(46))))) { goto L40; }
    if (Null(v3prev)) { goto L40; }
    if (!(((v3prev)==ECL_CODE_CHAR((ecl_character)(46))))) { goto L36; }
    goto L37;
L40:;
    goto L37;
L37:;
    goto L12;
L36:;
    v3prev = v4c;
    goto L19;
L20:;
    if (Null(v4c)) { goto L48; }
    if ((cl_digit_char_p(1, v4c))!=ECL_NIL) { goto L11; }
    goto L12;
L48:;
    goto L12;
   }
  }
L12:;
  if (Null(v2on_error)) { goto L51; }
  if ((ecl_function_dispatch(cl_env_copy,v2on_error)(3, _ecl_static_44, VV[217], v1string))!=ECL_NIL) { goto L11; }
  goto L50;
L51:;
L50:;
  goto L3;
L11:;
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   v3 = ecl_function_dispatch(cl_env_copy,VV[68])(3, v1string, VV[73], _ecl_static_5) /*  SPLIT-STRING */;
   v4 = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v3))) FEtype_error_list(v3);
   v5 = v3;
   {
    cl_object v6;
    cl_object v7;
    v6 = ecl_list1(ECL_NIL);
    v7 = v6;
L59:;
    if (!(ecl_endp(v5))) { goto L61; }
    goto L60;
L61:;
    v4 = _ecl_car(v5);
    {
     cl_object v8;
     v8 = _ecl_cdr(v5);
     if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
     v5 = v8;
    }
    if (ecl_unlikely(ECL_ATOM(v7))) FEtype_error_cons(v7);
    T0 = v7;
    T1 = cl_parse_integer(1, v4);
    v7 = ecl_list1(T1);
    (ECL_CONS_CDR(T0)=v7,T0);
    goto L59;
L60:;
    value0 = ecl_cdr(v6);
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
L3:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G439                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC108__g439(cl_object v1cver, cl_object v2version)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   v3 = ecl_function_dispatch(cl_env_copy,VV[217])(2, v1cver, ECL_SYM("WARN",903)) /*  PARSE-VERSION */;
   v4 = ecl_function_dispatch(cl_env_copy,VV[217])(2, v2version, ECL_SYM("WARN",903)) /*  PARSE-VERSION */;
   if (Null(v3)) { goto L4; }
   if (Null(v4)) { goto L4; }
   T0 = ecl_car(v3);
   T1 = ecl_car(v4);
   if (!(ecl_number_equalp(T0,T1))) { goto L4; }
   T0 = ecl_cdr(v4);
   value0 = Null(T0)?ECL_T:ECL_NIL;
   if ((value0)!=ECL_NIL) { goto L9; }
   T0 = ecl_cdr(v3);
   T1 = ecl_cdr(v4);
   value0 = LC107bigger(T0, T1);
   return value0;
L9:;
   cl_env_copy->nvalues = 1;
   return value0;
L4:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function BIGGER                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC107bigger(cl_object v1x, cl_object v2y)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((v2y)!=ECL_NIL) { goto L1; }
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if ((v1x)!=ECL_NIL) { goto L3; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L3:;
  T0 = ecl_car(v1x);
  T1 = ecl_car(v2y);
  if (!(ecl_number_compare(T0,T1)>0)) { goto L5; }
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
L5:;
  T0 = ecl_car(v1x);
  T1 = ecl_car(v2y);
  if (!(ecl_number_equalp(T0,T1))) { goto L7; }
  v1x = ecl_cdr(v1x);
  v2y = ecl_cdr(v2y);
  goto TTL;
L7:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for READ-NULL-TERMINATED-STRING           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L109read_null_terminated_string(cl_object v1s)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2out;
   v2out = cl_make_string_output_stream(0);
   {
    cl_object v3code;
    v3code = ECL_NIL;
L4:;
    v3code = cl_read_byte(1, v1s);
    if (!(ecl_zerop(v3code))) { goto L8; }
    goto L5;
L8:;
    T0 = cl_code_char(v3code);
    cl_write_char(2, T0, v2out);
    goto L4;
L5:;
   }
   value0 = cl_get_output_stream_string(v2out);
   return value0;
  }
 }
}
/*	function definition for READ-LITTLE-ENDIAN                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L110read_little_endian(cl_narg narg, cl_object v1s, ...)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2bytes;
  va_list args; va_start(args,v1s);
  {
   int i = 1;
   if (i >= narg) {
    v2bytes = ecl_make_fixnum(4);
   } else {
    i++;
    v2bytes = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v3i;
   cl_object v4;
   v3i = ecl_make_fixnum(0);
   T0 = cl_realp(v2bytes);
   if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("REAL",703),v2bytes);
   v4 = v2bytes;
   {
    cl_object v5;
    v5 = ecl_make_fixnum(0);
L6:;
    if (!(ecl_number_compare(v3i,v4)>=0)) { goto L8; }
    goto L7;
L8:;
    T0 = cl_read_byte(1, v1s);
    T1 = ecl_times(ecl_make_fixnum(8),v3i);
    T2 = cl_ash(T0, T1);
    v5 = ecl_plus(v5,T2);
    v3i = ecl_one_plus(v3i);
    goto L6;
L7:;
    value0 = v5;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for PARSE-FILE-LOCATION-INFO              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L111parse_file_location_info(cl_object v1s)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6;
   cl_object v7;
   cl_object v8;
   cl_object v9;
   v2 = cl_file_position(1, v1s);
   v3 = L110read_little_endian(1, v1s);
   v4 = L110read_little_endian(1, v1s);
   v5 = L110read_little_endian(1, v1s);
   v6 = L110read_little_endian(1, v1s);
   v7 = L110read_little_endian(1, v1s);
   v8 = L110read_little_endian(1, v1s);
   v9 = L110read_little_endian(1, v1s);
   if (ecl_zerop(v5)) { goto L9; }
   if (Null(cl_logbitp(ecl_make_fixnum(0), v5))) { goto L12; }
   T0 = ecl_plus(v2,v7);
   cl_file_position(2, v1s, T0);
   goto L11;
L12:;
   if (Null(cl_logbitp(ecl_make_fixnum(1), v5))) { goto L11; }
   T0 = ecl_plus(v2,v8);
   T1 = ecl_plus(T0,ecl_make_fixnum(20));
   cl_file_position(2, v1s, T1);
L11:;
   T0 = L109read_null_terminated_string(v1s);
   T1 = ecl_plus(v2,v9);
   cl_file_position(2, v1s, T1);
   T1 = L109read_null_terminated_string(v1s);
   value0 = L3strcat(2, T0, T1);
   return value0;
L9:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for PARSE-WINDOWS-SHORTCUT                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L113parse_windows_shortcut(cl_object volatile v1pathname)
{
 cl_object T0, T1, T2, T3;
 cl_object volatile env0;
 cl_object volatile CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   volatile cl_object v2s;
   v2s = cl_open(3, v1pathname, ECL_SYM("ELEMENT-TYPE",1224), VV[228]);
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
      volatile cl_object v5;
      v5 = _ecl_inner_frame;
      env0 = ECL_NIL;
      CLV0 = env0 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env0); /*  TAGBODY */
      if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV0))) {
      if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L7;
      ecl_internal_error("GO found an inexistent tag");
      }
      {cl_object v6;
       v6 = ECL_NIL;
       v6 = ecl_make_cclosure_va((cl_objectfn)LC112__g458,env0,Cblock);
       T0 = v6;
      }
      T1 = CONS(ECL_SYM("END-OF-FILE",329),T0);
      T2 = ecl_list1(T1);
      T3 = CONS(T2,ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5)));
      ecl_bds_bind(cl_env_copy,ECL_SYM("*HANDLER-CLUSTERS*",5),T3); /*  *HANDLER-CLUSTERS* */
      T0 = L110read_little_endian(1, v2s);
      if (!(ecl_number_equalp(T0,ecl_symbol_value(VV[219])))) { goto L10; }
      {
       cl_object v6header;
       {
        cl_fixnum v7;
        v7 = ecl_length(ecl_symbol_value(VV[220]));
        v6header = si_make_pure_array(ECL_T, ecl_make_fixnum(v7), ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
       }
       cl_read_sequence(2, v6header, v2s);
       if (!(ecl_equalp(v6header,ecl_symbol_value(VV[220])))) { goto L10; }
      }
      {
       cl_object v6flags;
       v6flags = L110read_little_endian(1, v2s);
       cl_file_position(2, v2s, ecl_make_fixnum(76));
       if (Null(cl_logbitp(ecl_make_fixnum(0), v6flags))) { goto L17; }
       {
        cl_object v7length;
        v7length = L110read_little_endian(2, v2s, ecl_make_fixnum(2));
        T0 = cl_file_position(1, v2s);
        T1 = ecl_plus(v7length,T0);
        cl_file_position(2, v2s, T1);
       }
L17:;
       if (Null(cl_logbitp(ecl_make_fixnum(1), v6flags))) { goto L20; }
       cl_env_copy->values[0] = L111parse_file_location_info(v2s);
       ecl_frs_pop(cl_env_copy);
       ecl_bds_unwind1(cl_env_copy);
       goto L6;
L20:;
       if (Null(cl_logbitp(ecl_make_fixnum(2), v6flags))) { goto L22; }
       {
        cl_object v7length;
        v7length = L110read_little_endian(2, v2s, ecl_make_fixnum(2));
        T0 = cl_file_position(1, v2s);
        T1 = ecl_plus(v7length,T0);
        cl_file_position(2, v2s, T1);
       }
L22:;
       if (Null(cl_logbitp(ecl_make_fixnum(3), v6flags))) { goto L25; }
       {
        cl_object v7length;
        cl_object v8buffer;
        v7length = L110read_little_endian(2, v2s, ecl_make_fixnum(2));
        v8buffer = si_make_pure_array(ECL_T, v7length, ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
        cl_read_sequence(2, v8buffer, v2s);
        T0 = (ECL_SYM("CODE-CHAR",230)->symbol.gfdef);
        cl_env_copy->values[0] = cl_map(3, ECL_SYM("STRING",805), T0, v8buffer);
        ecl_frs_pop(cl_env_copy);
        ecl_bds_unwind1(cl_env_copy);
        goto L6;
       }
L25:;
       cl_env_copy->values[0] = ECL_NIL;
       cl_env_copy->nvalues = 1;
       ecl_frs_pop(cl_env_copy);
       ecl_bds_unwind1(cl_env_copy);
       goto L6;
      }
L10:;
      cl_env_copy->values[0] = ECL_NIL;
      cl_env_copy->nvalues = 1;
      ecl_frs_pop(cl_env_copy);
      ecl_bds_unwind1(cl_env_copy);
      goto L6;
L7:;
      cl_env_copy->values[0] = ECL_NIL;
      cl_env_copy->nvalues = 1;
      ecl_frs_pop(cl_env_copy);
      goto L6;
L6:;
      ecl_stack_frame_push_values(v5);
      if (Null(v2s)) { goto L32; }
      cl_close(1, v2s);
L32:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v5);
     }
     ecl_stack_frame_close(_ecl_inner_frame);
    }
    }
    ecl_frs_pop(cl_env_copy);
    v4=ecl_stack_push_values(cl_env_copy);
    if (Null(v2s)) { goto L34; }
    cl_close(3, v2s, ECL_SYM("ABORT",1195), ECL_T);
L34:;
    ecl_stack_pop_values(cl_env_copy,v4);
    if (unwinding) ecl_unwind(cl_env_copy,next_fr);
    ECL_STACK_SET_INDEX(cl_env_copy,v3);
    return cl_env_copy->values[0];
   }
  }
 }
}
/*	closure G458                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC112__g458(cl_narg narg, cl_object v1si__temp, ...)
{
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  TAGBODY         */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  cl_go(ECL_CONS_CAR(CLV0),ecl_make_fixnum(0));
 }
 }
}
/*	function definition for MAKE-DEFINED-SYSTEMS-TABLE            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L114make_defined_systems_table()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_make_hash_table(2, ECL_SYM("TEST",1316), ECL_SYM("EQUAL",335));
  return value0;
 }
}
/*	function definition for COERCE-NAME                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L115coerce_name(cl_object v1name)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(si_of_class_p(2, v1name, VV[11]))) { goto L1; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[813])(1, v1name) /*  COMPONENT-NAME */;
  return value0;
L1:;
  if (!(ECL_SYMBOLP(v1name))) { goto L3; }
  T0 = ecl_symbol_name(v1name);
  value0 = cl_string_downcase(1, T0);
  return value0;
L3:;
  if (!(ECL_STRINGP(v1name))) { goto L5; }
  value0 = v1name;
  cl_env_copy->nvalues = 1;
  return value0;
L5:;
  value0 = ecl_function_dispatch(cl_env_copy,VV[191])(2, _ecl_static_45, v1name) /*  SYSDEF-ERROR */;
  return value0;
 }
}
/*	function definition for SYSTEM-REGISTERED-P                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L116system_registered_p(cl_object v1name)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[233])(1, v1name) /*  COERCE-NAME */;
  value0 = cl_gethash(2, T0, ecl_symbol_value(VV[232]));
  return value0;
 }
}
/*	function definition for REGISTERED-SYSTEMS                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L117registered_systems()
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v1;
   cl_object v2;
   cl_object v3;
   cl_object v4system;
   cl_object v5;
   v1 = ecl_symbol_value(VV[232]);
   v2 = ECL_NIL;
   v3 = ECL_NIL;
   v4system = ECL_NIL;
   v5 = ECL_NIL;
   {
    cl_object v6;
    v6 = si_hash_table_iterator(v1);
    {
     cl_object v7;
     cl_object v8;
     v7 = ecl_list1(ECL_NIL);
     v8 = v7;
L9:;
     {
      cl_object v10;
      cl_object v11;
      cl_object v12;
      value0 = ecl_function_dispatch(cl_env_copy,v6)(0);
      v10 = value0;
      {
       const int v13 = cl_env_copy->nvalues;
       cl_object v14;
       v14 = (v13<=1)? ECL_NIL : cl_env_copy->values[1];
       v11 = v14;
       v14 = (v13<=2)? ECL_NIL : cl_env_copy->values[2];
       v12 = v14;
      }
      if (Null(v10)) { goto L14; }
      v3 = v12;
      v5 = v11;
L14:;
      v2 = v10;
      if ((v2)!=ECL_NIL) { goto L11; }
     }
     goto L10;
L11:;
     {
      cl_object v9;
      v9 = v3;
      v9 = ecl_cdr(v9);
      v4system = v9;
     }
     if (ecl_unlikely(ECL_ATOM(v8))) FEtype_error_cons(v8);
     T0 = v8;
     T1 = ecl_function_dispatch(cl_env_copy,VV[233])(1, v4system) /*  COERCE-NAME */;
     v8 = ecl_list1(T1);
     (ECL_CONS_CDR(T0)=v8,T0);
     goto L9;
L10:;
     value0 = ecl_cdr(v7);
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
  }
 }
}
/*	function definition for REGISTER-SYSTEM                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L118register_system(cl_object v1system)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   v2 = v1system;
   if ((si_of_class_p(2, v2, VV[213]))!=ECL_NIL) { goto L3; }
   v1system = si_do_check_type(v2, VV[213], ECL_NIL, VV[213]);
L3:;
  }
  {
   cl_object v2name;
   v2name = ecl_function_dispatch(cl_env_copy,VV[813])(1, v1system) /*  COMPONENT-NAME */;
   {
    cl_object v3;
    v3 = v2name;
    if (ECL_STRINGP(v3)) { goto L9; }
    v2name = si_do_check_type(v3, ECL_SYM("STRING",805), ECL_NIL, VV[240]);
L9:;
   }
   ecl_function_dispatch(cl_env_copy,VV[66])(2, _ecl_static_46, v1system) /*  ASDF-MESSAGE */;
   T0 = ecl_gethash_safe(v2name,ecl_symbol_value(VV[232]),ECL_NIL);
   T1 = ecl_cdr(T0);
   if ((v1system)==(T1)) { goto L13; }
   T0 = cl_get_universal_time();
   T1 = CONS(T0,v1system);
   value0 = si_hash_set(v2name, ecl_symbol_value(VV[232]), T1);
   return value0;
L13:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for CLEAR-SYSTEM                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L119clear_system(cl_object v1name)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[233])(1, v1name) /*  COERCE-NAME */;
  value0 = cl_remhash(T0, ecl_symbol_value(VV[232]));
  return value0;
 }
}
/*	function definition for MAP-SYSTEMS                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L120map_systems(cl_object v1fn)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   cl_object v3;
   cl_object v4;
   cl_object v5system;
   cl_object v6;
   v2 = ecl_symbol_value(VV[232]);
   v3 = ECL_NIL;
   v4 = ECL_NIL;
   v5system = ECL_NIL;
   v6 = ECL_NIL;
   {
    cl_object v7;
    v7 = si_hash_table_iterator(v2);
L7:;
    {
     cl_object v9;
     cl_object v10;
     cl_object v11;
     value0 = ecl_function_dispatch(cl_env_copy,v7)(0);
     v9 = value0;
     {
      const int v12 = cl_env_copy->nvalues;
      cl_object v13;
      v13 = (v12<=1)? ECL_NIL : cl_env_copy->values[1];
      v10 = v13;
      v13 = (v12<=2)? ECL_NIL : cl_env_copy->values[2];
      v11 = v13;
     }
     if (Null(v9)) { goto L12; }
     v4 = v11;
     v6 = v10;
L12:;
     v3 = v9;
     if ((v3)!=ECL_NIL) { goto L9; }
    }
    goto L8;
L9:;
    {
     cl_object v8;
     v8 = v4;
     v8 = ecl_cdr(v8);
     v5system = v8;
    }
    ecl_function_dispatch(cl_env_copy,v1fn)(1, v5system);
    goto L7;
L8:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	local function G502                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC121__g502(cl_object v1x)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_memql(v1x,ecl_symbol_value(VV[246]));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for SEARCH-FOR-SYSTEM-DEFINITION          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L123search_for_system_definition(cl_object v1system)
{
 cl_object T0, T1;
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object env1 = env0;
   T1 = ecl_function_dispatch(cl_env_copy,VV[233])(1, v1system) /*  COERCE-NAME */;
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(T1,env1);                   /*  NAME            */
   {cl_object v2;
    v2 = ECL_NIL;
    v2 = ecl_make_cclosure_va((cl_objectfn)LC122__g503,env1,Cblock);
    T0 = v2;
   }
  }
  T1 = CONS(VV[249],ecl_symbol_value(VV[246]));
  value0 = cl_some(2, T0, T1);
  return value0;
 }
}
/*	closure G503                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC122__g503(cl_narg narg, cl_object v1x, ...)
{
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  NAME            */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,v1x)(1, ECL_CONS_CAR(CLV0));
  return value0;
 }
 }
}
/*	function definition for FEATUREP                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L126featurep(cl_narg narg, cl_object v1x, ...)
{
 cl_object T0, T1;
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  va_list args; va_start(args,v1x);
  {
   int i = 1;
   if (i >= narg) {
    env0 = ECL_NIL;
    CLV0 = env0 = CONS(ecl_symbol_value(ECL_SYM("*FEATURES*",34)),env0); /*  FEATURES */
   } else {
    i++;
    env0 = ECL_NIL;
    CLV0 = env0 = CONS(va_arg(args,cl_object),env0); /*  FEATURES     */
   }
  }
  va_end(args);
  if (!(ECL_ATOM(v1x))) { goto L1; }
  if (Null(ecl_memql(v1x,ECL_CONS_CAR(CLV0)))) { goto L4; }
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
L4:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  T0 = ecl_car(v1x);
  if (!((VV[253])==(T0))) { goto L6; }
  goto L10;
L9:;
  si_assert_failure(1, VV[254]);
L10:;
  T0 = ecl_cddr(v1x);
  if (T0==ECL_NIL) { goto L13; }
  goto L9;
L13:;
  T0 = ecl_cadr(v1x);
  T1 = L126featurep(2, T0, ECL_CONS_CAR(CLV0));
  value0 = Null(T1)?ECL_T:ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L6:;
  T0 = ecl_car(v1x);
  if (!((VV[255])==(T0))) { goto L15; }
  {cl_object v2;
   v2 = ECL_NIL;
   v2 = ecl_make_cclosure_va((cl_objectfn)LC124__g506,env0,Cblock);
   T0 = v2;
  }
  T1 = ecl_cdr(v1x);
  value0 = cl_some(2, T0, T1);
  return value0;
L15:;
  T0 = ecl_car(v1x);
  if (!((VV[256])==(T0))) { goto L18; }
  {cl_object v2;
   v2 = ECL_NIL;
   v2 = ecl_make_cclosure_va((cl_objectfn)LC125__g507,env0,Cblock);
   T0 = v2;
  }
  T1 = ecl_cdr(v1x);
  value0 = cl_every(2, T0, T1);
  return value0;
L18:;
  value0 = cl_error(2, _ecl_static_47, v1x);
  return value0;
 }
}
/*	closure G506                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC124__g506(cl_narg narg, cl_object v1x, ...)
{
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  FEATURES        */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = L126featurep(2, v1x, ECL_CONS_CAR(CLV0));
  return value0;
 }
 }
}
/*	closure G507                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC125__g507(cl_narg narg, cl_object v1x, ...)
{
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  FEATURES        */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = L126featurep(2, v1x, ECL_CONS_CAR(CLV0));
  return value0;
 }
 }
}
/*	function definition for OS-UNIX-P                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L127os_unix_p()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[252])(1, VV[259]) /*  FEATUREP */;
  return value0;
 }
}
/*	function definition for OS-WINDOWS-P                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L128os_windows_p()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((ecl_function_dispatch(cl_env_copy,VV[258])(0) /*  OS-UNIX-P    */)!=ECL_NIL) { goto L2; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[252])(1, VV[262]) /*  FEATUREP */;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for PROBE-ASD                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L129probe_asd(cl_object v1name, cl_object v2defaults)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[86])(1, v2defaults) /*  DIRECTORY-PATHNAME-P */)) { goto L1; }
  {
   cl_object v3file;
   T0 = L3strcat(2, v1name, _ecl_static_48);
   T1 = ecl_function_dispatch(cl_env_copy,VV[102])(2, v2defaults, T0) /*  SUBPATHNAME */;
   v3file = ecl_function_dispatch(cl_env_copy,VV[116])(1, T1) /*  PROBE-FILE* */;
   if (Null(v3file)) { goto L3; }
   value0 = v3file;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L3:;
  if (Null(ecl_function_dispatch(cl_env_copy,VV[261])(0) /*  OS-WINDOWS-P */)) { goto L6; }
  {
   cl_object v3shortcut;
   T0 = L3strcat(2, v1name, _ecl_static_48);
   v3shortcut = cl_make_pathname(10, ECL_SYM("DEFAULTS",1216), v2defaults, ECL_SYM("VERSION",1326), ECL_SYM("NEWEST",1276), ECL_SYM("CASE",1205), ECL_SYM("LOCAL",1268), ECL_SYM("NAME",1273), T0, ECL_SYM("TYPE",1318), _ecl_static_49);
   if (Null(ecl_function_dispatch(cl_env_copy,VV[116])(1, v3shortcut) /*  PROBE-FILE* */)) { goto L9; }
   {
    cl_object v4target;
    v4target = ecl_function_dispatch(cl_env_copy,VV[227])(1, v3shortcut) /*  PARSE-WINDOWS-SHORTCUT */;
    if (Null(v4target)) { goto L12; }
    value0 = cl_pathname(v4target);
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
L6:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for SYSDEF-CENTRAL-REGISTRY-SEARCH        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L134sysdef_central_registry_search(cl_object volatile v1system)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7;
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1, CLV2, CLV3
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   volatile cl_object v2;
   volatile cl_object v3to_remove;
   volatile cl_object v4to_replace;
   v2 = ecl_function_dispatch(cl_env_copy,VV[233])(1, v1system) /*  COERCE-NAME */;
   v3to_remove = ECL_NIL;
   v4to_replace = ECL_NIL;
   {
    volatile bool unwinding = FALSE;
    cl_index v5=ECL_STACK_INDEX(cl_env_copy),v6;
    ecl_frame_ptr next_fr;
    if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
      unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
    } else {
    {
     volatile cl_object v7;
     v7 = ecl_symbol_value(VV[251]);
     goto L8;
L7:;
     {
      volatile cl_object env1 = env0;
      T0 = ecl_car(v7);
      env1 = ECL_NIL;
      CLV0 = env1 = CONS(T0,env1);                /*  DIR             */
      {
       volatile cl_object env2 = env1;
       T0 = cl_eval(ECL_CONS_CAR(CLV0));
       CLV1 = env2 = CONS(T0,env2);               /*  DEFAULTS        */
       if (Null(ECL_CONS_CAR(CLV1))) { goto L11; }
       if (Null(ecl_function_dispatch(cl_env_copy,VV[86])(1, ECL_CONS_CAR(CLV1)) /*  DIRECTORY-PATHNAME-P */)) { goto L13; }
       {
        cl_object v8file;
        v8file = ecl_function_dispatch(cl_env_copy,VV[264])(2, v2, ECL_CONS_CAR(CLV1)) /*  PROBE-ASD */;
        if (Null(v8file)) { goto L11; }
        cl_env_copy->values[0] = v8file;
        cl_env_copy->nvalues = 1;
        goto L4;
       }
L13:;
       {
        volatile cl_object env3 = env2;
        CLV2 = env3 = CONS(ECL_NIL,env3);
        {
         volatile cl_object env4 = env3;
         CLV3 = env4 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env4); /*  TAGBODY */
         if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV3))) {
         if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L17;
         if (cl_env_copy->values[0]==ecl_make_fixnum(1))goto L18;
         ecl_internal_error("GO found an inexistent tag");
         }
         {cl_object v9;
          v9 = ECL_NIL;
          v9 = ecl_make_cclosure_va((cl_objectfn)LC130__g519,env4,Cblock);
          T0 = v9;
         }
         {cl_object v9;
          v9 = ECL_NIL;
          v9 = ecl_make_cfun((cl_objectfn_fixed)LC131__g520,ECL_NIL,Cblock,1);
          T1 = v9;
         }
         T2 = ecl_function_dispatch(cl_env_copy,VV[851])(6, ECL_SYM("NAME",1273), VV[267], ECL_SYM("FUNCTION",1241), T0, VV[268], T1) /*  MAKE-RESTART */;
         {cl_object v9;
          v9 = ECL_NIL;
          v9 = ecl_make_cclosure_va((cl_objectfn)LC132__g521,env4,Cblock);
          T3 = v9;
         }
         {cl_object v9;
          v9 = ECL_NIL;
          v9 = ecl_make_cclosure_va((cl_objectfn)LC133__g522,env4,Cblock);
          T4 = v9;
         }
         T5 = ecl_function_dispatch(cl_env_copy,VV[851])(6, ECL_SYM("NAME",1273), VV[269], ECL_SYM("FUNCTION",1241), T3, VV[268], T4) /*  MAKE-RESTART */;
         T6 = cl_list(2, T2, T5);
         T7 = CONS(T6,ecl_symbol_value(ECL_SYM("*RESTART-CLUSTERS*",4)));
         ecl_bds_bind(cl_env_copy,ECL_SYM("*RESTART-CLUSTERS*",4),T7); /*  *RESTART-CLUSTERS* */
         {
          cl_object v9message;
          ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-CIRCLE*",47),ECL_NIL); /*  *PRINT-CIRCLE* */
          v9message = cl_format(5, ECL_NIL, _ecl_static_52, v1system, ECL_CONS_CAR(CLV0), ECL_CONS_CAR(CLV1));
          cl_error(1, v9message);
          ecl_frs_pop(cl_env_copy);
          ecl_bds_unwind1(cl_env_copy);
          ecl_bds_unwind1(cl_env_copy);
          goto L11;
         }
L17:;
         v3to_remove = CONS(ECL_CONS_CAR(CLV0),v3to_remove);
         ecl_frs_pop(cl_env_copy);
         goto L11;
L18:;
         T0 = ecl_function_dispatch(cl_env_copy,VV[91])(1, ECL_CONS_CAR(CLV1)) /*  ENSURE-DIRECTORY-PATHNAME */;
         T1 = CONS(ECL_CONS_CAR(CLV0),T0);
         v4to_replace = CONS(T1,v4to_replace);
         ecl_frs_pop(cl_env_copy);
         goto L11;
        }
       }
      }
L11:;
     }
     v7 = ecl_cdr(v7);
L8:;
     if (Null(v7)) { goto L31; }
     goto L7;
L31:;
     cl_env_copy->values[0] = ECL_NIL;
     cl_env_copy->nvalues = 1;
    }
L4:;
    }
    ecl_frs_pop(cl_env_copy);
    v6=ecl_stack_push_values(cl_env_copy);
    {
     cl_object v7;
     v7 = v3to_remove;
     goto L38;
L37:;
     {
      cl_object v8dir;
      v8dir = ecl_car(v7);
      cl_set(VV[251],cl_remove(2, v8dir, ecl_symbol_value(VV[251])));
     }
     v7 = ecl_cdr(v7);
L38:;
     if (Null(v7)) { goto L46; }
     goto L37;
L46:;
    }
    {
     cl_object v7;
     v7 = v4to_replace;
     goto L51;
L50:;
     {
      cl_object v8pair;
      v8pair = ecl_car(v7);
      {
       cl_object v9current;
       cl_object v10new;
       cl_object v11position;
       v9current = ecl_car(v8pair);
       v10new = ecl_cdr(v8pair);
       v11position = cl_position(2, v9current, ecl_symbol_value(VV[251]));
       T0 = cl_subseq(3, ecl_symbol_value(VV[251]), ecl_make_fixnum(0), v11position);
       T1 = ecl_list1(v10new);
       T2 = ecl_one_plus(v11position);
       T3 = cl_subseq(2, ecl_symbol_value(VV[251]), T2);
       cl_set(VV[251],cl_append(3, T0, T1, T3));
      }
     }
     v7 = ecl_cdr(v7);
L51:;
     if (Null(v7)) { goto L62; }
     goto L50;
L62:;
    }
    ecl_stack_pop_values(cl_env_copy,v6);
    if (unwinding) ecl_unwind(cl_env_copy,next_fr);
    ECL_STACK_SET_INDEX(cl_env_copy,v5);
    return cl_env_copy->values[0];
   }
  }
 }
}
/*	closure G519                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC130__g519(cl_narg narg, ...)
{
 cl_object CLV0, CLV1, CLV2, CLV3
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV3 = env0;                                     /*  TAGBODY         */
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 {
  cl_object v1si__temp;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1si__temp = cl_grab_rest_args(args);
  ecl_va_end(args);
  ECL_CONS_CAR(CLV2) = v1si__temp;
  cl_go(ECL_CONS_CAR(CLV3),ecl_make_fixnum(0));
 }
 }
}
/*	local function G520                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC131__g520(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_write_string(2, _ecl_static_50, v1stream);
  return value0;
 }
}
/*	closure G521                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC132__g521(cl_narg narg, ...)
{
 cl_object CLV0, CLV1, CLV2, CLV3
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV3 = env0;                                     /*  TAGBODY         */
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 {
  cl_object v1si__temp;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1si__temp = cl_grab_rest_args(args);
  ecl_va_end(args);
  ECL_CONS_CAR(CLV2) = v1si__temp;
  cl_go(ECL_CONS_CAR(CLV3),ecl_make_fixnum(1));
 }
 }
}
/*	closure G522                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC133__g522(cl_narg narg, cl_object v1s, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1, CLV2, CLV3
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV3 = env0;
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);                           /*  DEFAULTS        */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[91])(1, ECL_CONS_CAR(CLV1)) /*  ENSURE-DIRECTORY-PATHNAME */;
  value0 = cl_format(4, v1s, _ecl_static_51, T0, ECL_CONS_CAR(CLV0));
  return value0;
 }
 }
}
/*	function definition for MAKE-TEMPORARY-PACKAGE                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L137make_temporary_package()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v1counter;
   cl_object v2package;
   v1counter = ecl_make_fixnum(0);
   v2package = LC136try(v1counter);
   goto L5;
L4:;
   v1counter = ecl_plus(v1counter,ecl_make_fixnum(1));
   v2package = LC136try(v1counter);
L5:;
   if ((v2package)!=ECL_NIL) { goto L11; }
   goto L4;
L11:;
   value0 = v2package;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function TRY                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC136try(cl_object volatile v1counter)
{
 cl_object T0, T1, T2, T3;
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   volatile cl_object env1 = env0;
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(ECL_NIL,env1);
   {
    volatile cl_object env2 = env1;
    CLV1 = env2 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env2); /*  TAGBODY */
    if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV1))) {
    if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L1;
    ecl_internal_error("GO found an inexistent tag");
    }
    {cl_object v2;
     v2 = ECL_NIL;
     v2 = ecl_make_cclosure_va((cl_objectfn)LC135__g538,env2,Cblock);
     T0 = v2;
    }
    T1 = CONS(ECL_SYM("ERROR",337),T0);
    T2 = ecl_list1(T1);
    T3 = CONS(T2,ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5)));
    ecl_bds_bind(cl_env_copy,ECL_SYM("*HANDLER-CLUSTERS*",5),T3); /*  *HANDLER-CLUSTERS* */
    T0 = cl_format(4, ECL_NIL, _ecl_static_53, VV[1], v1counter);
    value0 = cl_make_package(3, T0, ECL_SYM("USE",1323), VV[272]);
    ecl_frs_pop(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    return value0;
L1:;
    {
     cl_object v2condition;
     v2condition = ECL_CONS_CAR(CLV0);
     cl_env_copy->nvalues = 2;
     cl_env_copy->values[1] = v2condition;
     cl_env_copy->values[0] = ECL_NIL;
     value0 = cl_env_copy->values[0];
     ecl_frs_pop(cl_env_copy);
     return value0;
    }
   }
  }
 }
}
/*	closure G538                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC135__g538(cl_narg narg, cl_object v1si__temp, ...)
{
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  TAGBODY         */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  ECL_CONS_CAR(CLV0) = v1si__temp;
  cl_go(ECL_CONS_CAR(CLV1),ecl_make_fixnum(0));
 }
 }
}
/*	function definition for SAFE-FILE-WRITE-DATE                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L139safe_file_write_date(cl_object volatile v1pathname)
{
 cl_object T0, T1, T2, T3;
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1pathname)) { goto L5; }
  if (Null(ecl_function_dispatch(cl_env_copy,VV[116])(1, v1pathname) /*  PROBE-FILE* */)) { goto L5; }
  {
   volatile cl_object env1 = env0;
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(ECL_NIL,env1);
   {
    volatile cl_object env2 = env1;
    CLV1 = env2 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env2); /*  TAGBODY */
    if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV1))) {
    if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L8;
    ecl_internal_error("GO found an inexistent tag");
    }
    {cl_object v2;
     v2 = ECL_NIL;
     v2 = ecl_make_cclosure_va((cl_objectfn)LC138__g544,env2,Cblock);
     T0 = v2;
    }
    T1 = CONS(ECL_SYM("ERROR",337),T0);
    T2 = ecl_list1(T1);
    T3 = CONS(T2,ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5)));
    ecl_bds_bind(cl_env_copy,ECL_SYM("*HANDLER-CLUSTERS*",5),T3); /*  *HANDLER-CLUSTERS* */
    value0 = cl_file_write_date(v1pathname);
    ecl_frs_pop(cl_env_copy);
    value0 = value0;
    ecl_bds_unwind1(cl_env_copy);
    goto L3;
L8:;
    {
     cl_object v2condition;
     v2condition = ECL_CONS_CAR(CLV0);
     cl_env_copy->nvalues = 2;
     cl_env_copy->values[1] = v2condition;
     cl_env_copy->values[0] = ECL_NIL;
     value0 = cl_env_copy->values[0];
     ecl_frs_pop(cl_env_copy);
     value0 = value0;
     goto L3;
    }
   }
  }
L5:;
  value0 = ECL_NIL;
  goto L3;
L3:;
  if ((value0)!=ECL_NIL) { goto L2; }
  if (Null(v1pathname)) { goto L13; }
  if (Null(ecl_symbol_value(VV[7]))) { goto L13; }
  (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(2, _ecl_static_54, v1pathname) /*  WARN */;
L13:;
  value0 = ecl_make_fixnum(0);
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	closure G544                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC138__g544(cl_narg narg, cl_object v1si__temp, ...)
{
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  TAGBODY         */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  ECL_CONS_CAR(CLV0) = v1si__temp;
  cl_go(ECL_CONS_CAR(CLV1),ecl_make_fixnum(0));
 }
 }
}
/*	local function G545                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC140__g545(cl_narg narg, cl_object v1name, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2error_p;
  va_list args; va_start(args,v1name);
  {
   int i = 1;
   if (i >= narg) {
    v2error_p = ECL_T;
   } else {
    i++;
    v2error_p = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (Null(v2error_p)) { goto L2; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[191])(1, _ecl_static_55) /*  SYSDEF-ERROR */;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G546                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC141__g546(cl_narg narg, cl_object v1name, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2error_p;
  va_list args; va_start(args,v1name);
  {
   int i = 1;
   if (i >= narg) {
    v2error_p = ECL_T;
   } else {
    i++;
    v2error_p = va_arg(args,cl_object);
   }
  }
  va_end(args);
  T0 = ecl_function_dispatch(cl_env_copy,VV[233])(1, v1name) /*  COERCE-NAME */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[144])(2, T0, v2error_p) /*  FIND-SYSTEM */;
  return value0;
 }
}
/*	function definition for FIND-SYSTEM-IF-BEING-DEFINED          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L142find_system_if_being_defined(cl_object v1name)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_symbol_value(VV[276]))) { goto L1; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[233])(1, v1name) /*  COERCE-NAME */;
  value0 = cl_gethash(2, T0, ecl_symbol_value(VV[276]));
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for CALL-WITH-SYSTEM-DEFINITIONS          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L143call_with_system_definitions(cl_object v1thunk)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_symbol_value(VV[276]))) { goto L1; }
  value0 = ecl_function_dispatch(cl_env_copy,v1thunk)(0);
  return value0;
L1:;
  T0 = cl_make_hash_table(2, ECL_SYM("TEST",1316), ECL_SYM("EQUAL",335));
  ecl_bds_bind(cl_env_copy,VV[276],T0);           /*  *SYSTEMS-BEING-DEFINED* */
  value0 = ecl_function_dispatch(cl_env_copy,v1thunk)(0);
  ecl_bds_unwind1(cl_env_copy);
  return value0;
 }
}
/*	local function WITH-SYSTEM-DEFINITIONS                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC144with_system_definitions(cl_object v1, cl_object v2)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4 = v5;
   }
   if (Null(v4)) { goto L8; }
   si_dm_too_many_arguments(v1);
L8:;
   T0 = cl_listX(3, ECL_SYM("LAMBDA",452), ECL_NIL, v3);
   T1 = cl_list(2, ECL_SYM("FUNCTION",396), T0);
   value0 = cl_list(2, VV[279], T1);
   return value0;
  }
 }
}
/*	function definition for LOAD-SYSDEF                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L147load_sysdef(cl_object volatile v1name, cl_object volatile v2pathname)
{
 cl_object T0;
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1name,env0);                /*  NAME            */
  CLV1 = env0 = CONS(v2pathname,env0);            /*  PATHNAME        */
  {cl_object v3;
   v3 = ECL_NIL;
   v3 = ecl_make_cclosure_va((cl_objectfn)LC146__g558,env0,Cblock);
   T0 = v3;
  }
  value0 = ecl_function_dispatch(cl_env_copy,VV[279])(1, T0) /*  CALL-WITH-SYSTEM-DEFINITIONS */;
  return value0;
 }
}
/*	closure G558                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC146__g558(volatile cl_narg narg, ...)
{
 cl_object T0, T1, T2, T3;
 cl_object volatile CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object volatile env0 = cl_env_copy->function->cclosure.env;
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  PATHNAME        */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=0)) FEwrong_num_arguments_anonym();
 {
TTL:
  {
   volatile cl_object v1package;
   v1package = ecl_function_dispatch(cl_env_copy,VV[271])(0) /*  MAKE-TEMPORARY-PACKAGE */;
   {
    volatile bool unwinding = FALSE;
    cl_index v2=ECL_STACK_INDEX(cl_env_copy),v3;
    ecl_frame_ptr next_fr;
    if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
      unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
    } else {
    {cl_object v4;
     v4 = ECL_NIL;
     v4 = ecl_make_cclosure_va((cl_objectfn)LC145__g559,env0,Cblock);
     T0 = v4;
    }
    T1 = CONS(ECL_SYM("ERROR",337),T0);
    T2 = ecl_list1(T1);
    T3 = CONS(T2,ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5)));
    ecl_bds_bind(cl_env_copy,ECL_SYM("*HANDLER-CLUSTERS*",5),T3); /*  *HANDLER-CLUSTERS* */
    {
     cl_object v4;
     cl_object v5;
     T0 = cl_translate_logical_pathname(1, ECL_CONS_CAR(CLV1));
     v4 = ecl_function_dispatch(cl_env_copy,VV[36])(1, T0) /*  PATHNAME-DIRECTORY-PATHNAME */;
     T0 = ecl_function_dispatch(cl_env_copy,VV[206])(1, ECL_CONS_CAR(CLV1)) /*  DETECT-ENCODING */;
     v5 = L102encoding_external_format(T0);
     ecl_bds_bind(cl_env_copy,ECL_SYM("*PACKAGE*",43),v1package); /*  *PACKAGE* */
     ecl_bds_bind(cl_env_copy,ECL_SYM("*DEFAULT-PATHNAME-DEFAULTS*",32),v4); /*  *DEFAULT-PATHNAME-DEFAULTS* */
     ecl_function_dispatch(cl_env_copy,VV[66])(3, _ecl_static_56, ECL_CONS_CAR(CLV1), v1package) /*  ASDF-MESSAGE */;
     cl_env_copy->values[0] = cl_load(3, ECL_CONS_CAR(CLV1), ECL_SYM("EXTERNAL-FORMAT",1236), v5);
     ecl_bds_unwind1(cl_env_copy);
     ecl_bds_unwind1(cl_env_copy);
     ecl_bds_unwind1(cl_env_copy);
    }
    }
    ecl_frs_pop(cl_env_copy);
    v3=ecl_stack_push_values(cl_env_copy);
    cl_delete_package(v1package);
    ecl_stack_pop_values(cl_env_copy,v3);
    if (unwinding) ecl_unwind(cl_env_copy,next_fr);
    ECL_STACK_SET_INDEX(cl_env_copy,v2);
    return cl_env_copy->values[0];
   }
  }
 }
 }
}
/*	closure G559                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC145__g559(cl_narg narg, cl_object v1condition, ...)
{
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  PATHNAME        */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = cl_error(7, VV[175], ECL_SYM("NAME",1273), ECL_CONS_CAR(CLV0), ECL_SYM("PATHNAME",1285), ECL_CONS_CAR(CLV1), VV[283], v1condition);
  return value0;
 }
 }
}
/*	function definition for LOCATE-SYSTEM                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L148locate_system(cl_object v1name)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2name;
   cl_object v3in_memory;
   cl_object v4previous;
   cl_object v5previous;
   cl_object v6previous_time;
   cl_object v7found;
   cl_object v8found_system;
   cl_object v9pathname;
   cl_object v10foundp;
   v2name = ecl_function_dispatch(cl_env_copy,VV[233])(1, v1name) /*  COERCE-NAME */;
   v3in_memory = ecl_function_dispatch(cl_env_copy,VV[235])(1, v2name) /*  SYSTEM-REGISTERED-P */;
   v4previous = ecl_cdr(v3in_memory);
   if (Null(si_of_class_p(2, v4previous, VV[213]))) { goto L6; }
   v5previous = v4previous;
   goto L4;
L6:;
   v5previous = ECL_NIL;
   goto L4;
L4:;
   v6previous_time = ecl_car(v3in_memory);
   v7found = ecl_function_dispatch(cl_env_copy,VV[248])(1, v2name) /*  SEARCH-FOR-SYSTEM-DEFINITION */;
   if (Null(si_of_class_p(2, v7found, VV[213]))) { goto L12; }
   v8found_system = v7found;
   goto L10;
L12:;
   v8found_system = ECL_NIL;
   goto L10;
L10:;
   if ((cl_pathnamep(v7found))!=ECL_NIL) { goto L21; }
   if (!(ECL_STRINGP(v7found))) { goto L19; }
   goto L20;
L21:;
L20:;
   value0 = cl_pathname(v7found);
   goto L17;
L19:;
   value0 = ECL_NIL;
   goto L17;
L17:;
   if ((value0)!=ECL_NIL) { goto L16; }
   if (Null(v8found_system)) { goto L25; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[155])(1, v8found_system) /*  SYSTEM-SOURCE-FILE */;
   goto L23;
L25:;
   value0 = ECL_NIL;
   goto L23;
L23:;
   if ((value0)!=ECL_NIL) { goto L16; }
   if (Null(v5previous)) { goto L28; }
   v9pathname = ecl_function_dispatch(cl_env_copy,VV[155])(1, v5previous) /*  SYSTEM-SOURCE-FILE */;
   goto L14;
L28:;
   v9pathname = ECL_NIL;
   goto L14;
L16:;
   v9pathname = value0;
   goto L14;
L14:;
   if ((v8found_system)!=ECL_NIL) { goto L34; }
   if ((v9pathname)!=ECL_NIL) { goto L34; }
   if (Null(v5previous)) { goto L32; }
   goto L33;
L34:;
L33:;
   v10foundp = ECL_T;
   goto L30;
L32:;
   v10foundp = ECL_NIL;
   goto L30;
L30:;
   {
    cl_object v11;
    v11 = v7found;
    if (v11==ECL_NIL) { goto L39; }
    if ((cl_pathnamep(v11))!=ECL_NIL) { goto L39; }
    if ((si_of_class_p(2, v11, VV[213]))!=ECL_NIL) { goto L39; }
    v7found = si_do_check_type(v11, VV[286], ECL_NIL, VV[287]);
L39:;
   }
   if (Null(v10foundp)) { goto L44; }
   v9pathname = ecl_function_dispatch(cl_env_copy,VV[123])(1, v9pathname) /*  RESOLVE-SYMLINKS* */;
   if (Null(v9pathname)) { goto L48; }
   if ((ecl_function_dispatch(cl_env_copy,VV[93])(1, v9pathname) /*  ABSOLUTE-PATHNAME-P */)!=ECL_NIL) { goto L48; }
   v9pathname = ecl_function_dispatch(cl_env_copy,VV[125])(1, v9pathname) /*  ENSURE-PATHNAME-ABSOLUTE */;
   if (Null(v8found_system)) { goto L48; }
   ecl_function_dispatch(cl_env_copy,VV[859])(2, v9pathname, v8found_system) /*  %SET-SYSTEM-SOURCE-FILE */;
L48:;
   if (Null(v5previous)) { goto L54; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[155])(1, v5previous) /*  SYSTEM-SOURCE-FILE */;
   if (ecl_equal(T0,v9pathname)) { goto L54; }
   ecl_function_dispatch(cl_env_copy,VV[859])(2, v9pathname, v5previous) /*  %SET-SYSTEM-SOURCE-FILE */;
   v6previous_time = ECL_NIL;
L54:;
   cl_env_copy->nvalues = 5;
   cl_env_copy->values[4] = v6previous_time;
   cl_env_copy->values[3] = v5previous;
   cl_env_copy->values[2] = v9pathname;
   cl_env_copy->values[1] = v8found_system;
   cl_env_copy->values[0] = v10foundp;
   return cl_env_copy->values[0];
L44:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G584                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC152__g584(volatile cl_narg narg, cl_object volatile v1name, ...)
{
 cl_object T0;
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  va_list args; va_start(args,v1name);
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1name,env0);                /*  NAME            */
  {
   int i = 1;
   if (i >= narg) {
    CLV1 = env0 = CONS(ECL_T,env0);               /*  ERROR-P         */
   } else {
    i++;
    CLV1 = env0 = CONS(va_arg(args,cl_object),env0); /*  ERROR-P      */
   }
  }
  va_end(args);
  {cl_object v2;
   v2 = ECL_NIL;
   v2 = ecl_make_cclosure_va((cl_objectfn)LC151__g585,env0,Cblock);
   T0 = v2;
  }
  value0 = ecl_function_dispatch(cl_env_copy,VV[279])(1, T0) /*  CALL-WITH-SYSTEM-DEFINITIONS */;
  return value0;
 }
}
/*	closure G585                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC151__g585(volatile cl_narg narg, ...)
{
 cl_object T0, T1, T2, T3, T4;
 cl_object volatile CLV0, CLV1, CLV2, CLV3
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object volatile env0 = cl_env_copy->function->cclosure.env;
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  ERROR-P         */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=0)) FEwrong_num_arguments_anonym();
 {
TTL:
L1:;
  {
   volatile cl_object env1 = env0;
   CLV2 = env1 = CONS(ECL_NIL,env1);
   {
    volatile cl_object env2 = env1;
    CLV3 = env2 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env2); /*  TAGBODY */
    if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV3))) {
    if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L3;
    ecl_internal_error("GO found an inexistent tag");
    }
    {cl_object v1;
     v1 = ECL_NIL;
     v1 = ecl_make_cclosure_va((cl_objectfn)LC149__g591,env2,Cblock);
     T0 = v1;
    }
    {cl_object v1;
     v1 = ECL_NIL;
     v1 = ecl_make_cclosure_va((cl_objectfn)LC150__g592,env2,Cblock);
     T1 = v1;
    }
    T2 = ecl_function_dispatch(cl_env_copy,VV[851])(6, ECL_SYM("NAME",1273), VV[289], ECL_SYM("FUNCTION",1241), T0, VV[268], T1) /*  MAKE-RESTART */;
    T3 = ecl_list1(T2);
    T4 = CONS(T3,ecl_symbol_value(ECL_SYM("*RESTART-CLUSTERS*",4)));
    ecl_bds_bind(cl_env_copy,ECL_SYM("*RESTART-CLUSTERS*",4),T4); /*  *RESTART-CLUSTERS* */
    {
     cl_object v2;                                /*  FOUNDP          */
     cl_object v3;                                /*  FOUND-SYSTEM    */
     cl_object v4;                                /*  PATHNAME        */
     cl_object v5;                                /*  PREVIOUS        */
     cl_object v6;                                /*  PREVIOUS-TIME   */
     value0 = ecl_function_dispatch(cl_env_copy,VV[285])(1, ECL_CONS_CAR(CLV0)) /*  LOCATE-SYSTEM */;
     v2 = value0;
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
     if (Null(v3)) { goto L8; }
     if ((v5)!=ECL_NIL) { goto L8; }
     ecl_function_dispatch(cl_env_copy,VV[239])(1, v3) /*  REGISTER-SYSTEM */;
L8:;
     if (Null(v4)) { goto L11; }
     if (Null(v6)) { goto L14; }
     T0 = ecl_function_dispatch(cl_env_copy,VV[274])(1, v4) /*  SAFE-FILE-WRITE-DATE */;
     T1 = cl_get_universal_time();
     if (Null(cl_L(3, v6, T0, T1))) { goto L11; }
     goto L12;
L14:;
L12:;
     ecl_function_dispatch(cl_env_copy,VV[282])(2, ECL_CONS_CAR(CLV0), v4) /*  LOAD-SYSDEF */;
L11:;
     {
      cl_object v7in_memory;
      v7in_memory = ecl_function_dispatch(cl_env_copy,VV[235])(1, ECL_CONS_CAR(CLV0)) /*  SYSTEM-REGISTERED-P */;
      if (Null(v7in_memory)) { goto L17; }
      if (Null(v4)) { goto L19; }
      {
       cl_object v8;
       v8 = ecl_function_dispatch(cl_env_copy,VV[274])(1, v4) /*  SAFE-FILE-WRITE-DATE */;
       if (ecl_unlikely(ECL_ATOM(v7in_memory))) FEtype_error_cons(v7in_memory);
       T0 = v7in_memory;
       (ECL_CONS_CAR(T0)=v8,T0);
      }
L19:;
      value0 = ecl_cdr(v7in_memory);
      cl_env_copy->nvalues = 1;
      ecl_frs_pop(cl_env_copy);
      ecl_bds_unwind1(cl_env_copy);
      return value0;
L17:;
      if (Null(ECL_CONS_CAR(CLV1))) { goto L25; }
      value0 = cl_error(3, VV[178], VV[290], ECL_CONS_CAR(CLV0));
      ecl_frs_pop(cl_env_copy);
      ecl_bds_unwind1(cl_env_copy);
      return value0;
L25:;
      value0 = ECL_NIL;
      cl_env_copy->nvalues = 1;
      ecl_frs_pop(cl_env_copy);
      ecl_bds_unwind1(cl_env_copy);
      return value0;
     }
    }
L3:;
    L420initialize_source_registry(0);
    ecl_frs_pop(cl_env_copy);
    goto L2;
   }
  }
L2:;
  goto L1;
 }
 }
}
/*	closure G591                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC149__g591(cl_narg narg, ...)
{
 cl_object CLV0, CLV1, CLV2, CLV3
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV3 = env0;                                     /*  TAGBODY         */
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 {
  cl_object v1si__temp;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1si__temp = cl_grab_rest_args(args);
  ecl_va_end(args);
  ECL_CONS_CAR(CLV2) = v1si__temp;
  cl_go(ECL_CONS_CAR(CLV3),ecl_make_fixnum(0));
 }
 }
}
/*	closure G592                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC150__g592(cl_narg narg, cl_object v1s, ...)
{
 cl_object CLV0, CLV1, CLV2, CLV3
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV3 = env0;
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);                           /*  NAME            */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = cl_format(3, v1s, _ecl_static_57, ECL_CONS_CAR(CLV0));
  return value0;
 }
 }
}
/*	function definition for FIND-SYSTEM-FALLBACK                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L153find_system_fallback(cl_narg narg, cl_object v1requested, cl_object v2fallback, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3keys;
  cl_object v4source_file;
  ecl_va_list args; ecl_va_start(args,v2fallback,narg,2);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L153find_system_fallbackkeys,keyvars,(cl_object*)&v3keys,TRUE);
   ecl_va_end(args);
   v4source_file = keyvars[0];
  }
  v2fallback = ecl_function_dispatch(cl_env_copy,VV[233])(1, v2fallback) /*  COERCE-NAME */;
  v1requested = ecl_function_dispatch(cl_env_copy,VV[233])(1, v1requested) /*  COERCE-NAME */;
  if (!(ecl_equal(v1requested,v2fallback))) { goto L5; }
  {
   cl_object v5registered;
   T0 = ecl_gethash_safe(v2fallback,ecl_symbol_value(VV[232]),ECL_NIL);
   v5registered = ecl_cdr(T0);
   value0 = v5registered;
   if ((value0)!=ECL_NIL) { goto L9; }
   value0 = cl_apply(7, ECL_SYM("MAKE-INSTANCE",949), VV[213], ECL_SYM("NAME",1273), v2fallback, VV[292], v4source_file, v3keys);
   return value0;
L9:;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L5:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for SYSDEF-FIND-ASDF                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L154sysdef_find_asdf(cl_object v1name)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[291])(4, v1name, _ecl_static_58, ECL_SYM("VERSION",1326), ecl_symbol_value(VV[5])) /*  FIND-SYSTEM-FALLBACK */;
  return value0;
 }
}
/*	local function G598                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC155__g598(cl_object v1base, cl_object v2path)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3s;
   v3s = ecl_function_dispatch(cl_env_copy,VV[144])(2, v1base, ECL_NIL) /*  FIND-SYSTEM */;
   if (Null(v3s)) { goto L3; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[163])(2, v3s, v2path) /*  FIND-COMPONENT */;
   return value0;
L3:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G599                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC156__g599(cl_object v1base, cl_object v2path)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1base)) { goto L1; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[233])(1, v1base) /*  COERCE-NAME */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[163])(2, T0, v2path) /*  FIND-COMPONENT */;
  return value0;
L1:;
  if (Null(v2path)) { goto L3; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[163])(2, v2path, ECL_NIL) /*  FIND-COMPONENT */;
  return value0;
L3:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G600                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC157__g600(cl_object v1base, cl_object v2path)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_car(v1base);
  T1 = ecl_cdr(v1base);
  T2 = CONS(T1,v2path);
  value0 = ecl_function_dispatch(cl_env_copy,VV[163])(2, T0, T2) /*  FIND-COMPONENT */;
  return value0;
 }
}
/*	local function G601                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC158__g601(cl_object v1module, cl_object v2name)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((cl_slot_boundp(v1module, VV[296]))!=ECL_NIL) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[195])(1, v1module) /*  COMPUTE-MODULE-COMPONENTS-BY-NAME */;
L1:;
  T0 = ecl_function_dispatch(cl_env_copy,VV[823])(1, v1module) /*  MODULE-COMPONENTS-BY-NAME */;
  value0 = ecl_gethash_safe(v2name,T0,ECL_NIL);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G602                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC159__g602(cl_object v1component, cl_object v2name)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v2name)) { goto L1; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[233])(1, v2name) /*  COERCE-NAME */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[163])(2, v1component, T0) /*  FIND-COMPONENT */;
  return value0;
L1:;
  value0 = v1component;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G603                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC160__g603(cl_object v1module, cl_object v2name)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_car(v2name);
  T1 = ecl_function_dispatch(cl_env_copy,VV[163])(2, v1module, T0) /*  FIND-COMPONENT */;
  T2 = ecl_cdr(v2name);
  value0 = ecl_function_dispatch(cl_env_copy,VV[163])(2, T1, T2) /*  FIND-COMPONENT */;
  return value0;
 }
}
/*	local function G604                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC161__g604(cl_object v1component, cl_object v2s)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ECL_SYM("DIRECTORY",1219);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G605                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC162__g605(cl_object v1component, cl_object v2s)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[862])(1, v1component) /*  SOURCE-FILE-EXPLICIT-TYPE */;
  return value0;
 }
}
/*	local function G606                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC163__g606(cl_object v1component)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_slot_value(v1component, VV[305]);
  if ((value0)!=ECL_NIL) { goto L3; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[813])(1, v1component) /*  COMPONENT-NAME */;
  goto L1;
L3:;
  T0 = value0;
  goto L1;
L1:;
  T1 = ecl_function_dispatch(cl_env_copy,VV[156])(1, v1component) /*  COMPONENT-SYSTEM */;
  T2 = ecl_function_dispatch(cl_env_copy,VV[164])(2, v1component, T1) /*  SOURCE-FILE-TYPE */;
  T3 = ecl_function_dispatch(cl_env_copy,VV[197])(1, v1component) /*  COMPONENT-PARENT-PATHNAME */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[95])(5, T0, ECL_SYM("TYPE",1318), T2, ECL_SYM("DEFAULTS",1216), T3) /*  COERCE-PATHNAME */;
  return value0;
 }
}
/*	local function G607                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC164__g607()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_make_hash_table(2, ECL_SYM("TEST",1316), ECL_SYM("EQUAL",335));
  return value0;
 }
}
/*	local function G608                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC165__g608()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_make_hash_table(2, ECL_SYM("TEST",1316), ECL_SYM("EQUAL",335));
  return value0;
 }
}
/*	local function G621                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC168__g621(cl_object volatile v1o, cl_object volatile v2stream)
{
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1o,env0);                   /*  O               */
  CLV1 = env0 = CONS(v2stream,env0);              /*  STREAM          */
  {cl_object v3;
   v3 = ECL_NIL;
   v3 = ecl_make_cclosure_va((cl_objectfn)LC167si___print_unreadable_object_body_,env0,Cblock);
   value0 = si_print_unreadable_object_function(ECL_CONS_CAR(CLV0), ECL_CONS_CAR(CLV1), ECL_T, ECL_T, v3);
   return value0;
  }
 }
}
/*	closure .PRINT-UNREADABLE-OBJECT-BODY.                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC167si___print_unreadable_object_body_(volatile cl_narg narg, ...)
{
 cl_object T0, T1, T2, T3;
 cl_object volatile CLV0, CLV1, CLV2, CLV3
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object volatile env0 = cl_env_copy->function->cclosure.env;
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  STREAM          */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=0)) FEwrong_num_arguments_anonym();
 {
TTL:
  {
   volatile cl_object env1 = env0;
   CLV2 = env1 = CONS(ECL_NIL,env1);
   {
    volatile cl_object env2 = env1;
    CLV3 = env2 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env2); /*  TAGBODY */
    if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV3))) {
    if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L1;
    ecl_internal_error("GO found an inexistent tag");
    }
    {cl_object v1;
     v1 = ECL_NIL;
     v1 = ecl_make_cclosure_va((cl_objectfn)LC166__g625,env2,Cblock);
     T0 = v1;
    }
    T1 = CONS(ECL_SYM("ERROR",337),T0);
    T2 = ecl_list1(T1);
    T3 = CONS(T2,ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5)));
    ecl_bds_bind(cl_env_copy,ECL_SYM("*HANDLER-CLUSTERS*",5),T3); /*  *HANDLER-CLUSTERS* */
    T0 = ecl_function_dispatch(cl_env_copy,VV[863])(1, ECL_CONS_CAR(CLV0)) /*  OPERATION-ORIGINAL-INITARGS */;
    value0 = ecl_prin1(T0,ECL_CONS_CAR(CLV1));
    cl_env_copy->nvalues = 1;
    ecl_frs_pop(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    return value0;
L1:;
    {
     cl_object v1condition;
     v1condition = ECL_CONS_CAR(CLV2);
     cl_env_copy->nvalues = 2;
     cl_env_copy->values[1] = v1condition;
     cl_env_copy->values[0] = ECL_NIL;
     value0 = cl_env_copy->values[0];
     ecl_frs_pop(cl_env_copy);
     return value0;
    }
   }
  }
 }
 }
}
/*	closure G625                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC166__g625(cl_narg narg, cl_object v1si__temp, ...)
{
 cl_object CLV0, CLV1, CLV2, CLV3
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV3 = env0;                                     /*  TAGBODY         */
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  ECL_CONS_CAR(CLV2) = v1si__temp;
  cl_go(ECL_CONS_CAR(CLV3),ecl_make_fixnum(0));
 }
 }
}
/*	local function G644                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC169__g644(cl_narg narg, cl_object v1operation, cl_object v2slot_names, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3force;
  cl_object v4force_not;
  ecl_va_list args; ecl_va_start(args,v2slot_names,narg,2);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,LC169__g644keys,keyvars,NULL,TRUE);
   ecl_va_end(args);
   v3force = keyvars[0];
   v4force_not = keyvars[1];
  }
  T0 = cl_slot_value(v1operation, VV[307]);
  if (!(ECL_CONSP(T0))) { goto L2; }
  {
   cl_object v5;
   {
    cl_object v6;
    cl_object v7;
    cl_object v8;
    v6 = cl_slot_value(v1operation, VV[307]);
    v7 = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
    v8 = v6;
    {
     cl_object v9;
     cl_object v10;
     v9 = ecl_list1(ECL_NIL);
     v10 = v9;
L11:;
     if (!(ecl_endp(v8))) { goto L13; }
     goto L12;
L13:;
     v7 = _ecl_car(v8);
     {
      cl_object v11;
      v11 = _ecl_cdr(v8);
      if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
      v8 = v11;
     }
     if (ecl_unlikely(ECL_ATOM(v10))) FEtype_error_cons(v10);
     T0 = v10;
     T1 = ecl_function_dispatch(cl_env_copy,VV[233])(1, v7) /*  COERCE-NAME */;
     v10 = ecl_list1(T1);
     (ECL_CONS_CDR(T0)=v10,T0);
     goto L11;
L12:;
     v5 = ecl_cdr(v9);
     goto L4;
    }
   }
L4:;
   (cl_env_copy->function=ECL_CONS_CAR(VV[825]))->cfun.entry(3, v5, v1operation, VV[307]) /*  (SETF SLOT-VALUE) */;
  }
L2:;
  T0 = cl_slot_value(v1operation, VV[308]);
  if (!(ECL_CONSP(T0))) { goto L1; }
  {
   cl_object v5;
   {
    cl_object v6;
    cl_object v7;
    cl_object v8;
    v6 = cl_slot_value(v1operation, VV[308]);
    v7 = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
    v8 = v6;
    {
     cl_object v9;
     cl_object v10;
     v9 = ecl_list1(ECL_NIL);
     v10 = v9;
L35:;
     if (!(ecl_endp(v8))) { goto L37; }
     goto L36;
L37:;
     v7 = _ecl_car(v8);
     {
      cl_object v11;
      v11 = _ecl_cdr(v8);
      if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
      v8 = v11;
     }
     if (ecl_unlikely(ECL_ATOM(v10))) FEtype_error_cons(v10);
     T0 = v10;
     T1 = ecl_function_dispatch(cl_env_copy,VV[233])(1, v7) /*  COERCE-NAME */;
     v10 = ecl_list1(T1);
     (ECL_CONS_CDR(T0)=v10,T0);
     goto L35;
L36:;
     v5 = ecl_cdr(v9);
     goto L28;
    }
   }
L28:;
   (cl_env_copy->function=ECL_CONS_CAR(VV[825]))->cfun.entry(3, v5, v1operation, VV[308]) /*  (SETF SLOT-VALUE) */;
  }
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  return value0;
 }
}
/*	function definition for NODE-FOR                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L170node_for(cl_object v1o, cl_object v2c)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_class_of(v1o);
  T1 = (cl_env_copy->function=(ECL_SYM("CLASS-NAME",934)->symbol.gfdef))->cfun.entry(1, T0) /*  CLASS-NAME */;
  value0 = CONS(T1,v2c);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G666                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC171__g666(cl_object v1operation)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2it;
   v2it = ecl_function_dispatch(cl_env_copy,VV[867])(1, v1operation) /*  OPERATION-PARENT */;
   if (Null(v2it)) { goto L2; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[165])(1, v2it) /*  OPERATION-ANCESTOR */;
   return value0;
L2:;
   value0 = v1operation;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for MAKE-SUB-OPERATION                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L172make_sub_operation(cl_object v1c, cl_object v2o, cl_object v3dep_c, cl_object v4dep_o)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v5args;
   cl_object v6force_p;
   T0 = ecl_function_dispatch(cl_env_copy,VV[863])(1, v2o) /*  OPERATION-ORIGINAL-INITARGS */;
   v5args = cl_copy_list(T0);
   v6force_p = cl_getf(2, v5args, VV[312]);
   T0 = ecl_function_dispatch(cl_env_copy,VV[814])(1, v1c) /*  COMPONENT-PARENT */;
   if (!(T0==ECL_NIL)) { goto L3; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[814])(1, v3dep_c) /*  COMPONENT-PARENT */;
   if (!(T0==ECL_NIL)) { goto L3; }
   if (ecl_eql(v1c,v3dep_c)) { goto L3; }
   if (!(ecl_eql(v6force_p,ECL_T))) { goto L7; }
   {
    cl_object v7;
    v7 = si_put_f(v5args, ECL_NIL, VV[312]);
    v5args = v7;
   }
L7:;
   value0 = cl_apply(7, ECL_SYM("MAKE-INSTANCE",949), v4dep_o, VV[313], v2o, VV[314], v5args, v5args);
   return value0;
L3:;
   T0 = cl_type_of(v2o);
   if (Null(cl_subtypep(2, T0, v4dep_o))) { goto L12; }
   value0 = v2o;
   cl_env_copy->nvalues = 1;
   return value0;
L12:;
   value0 = cl_apply(7, ECL_SYM("MAKE-INSTANCE",949), v4dep_o, VV[313], v2o, VV[314], v5args, v5args);
   return value0;
  }
 }
}
/*	local function G677                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC173__g677(cl_object v1o, cl_object v2c, cl_object v3data)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((ecl_function_dispatch(cl_env_copy,VV[166])(2, v1o, v2c) /*  COMPONENT-VISITED-P */)!=ECL_NIL) { goto L1; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[309])(2, v1o, v2c) /*  NODE-FOR */;
  T1 = ecl_function_dispatch(cl_env_copy,VV[165])(1, v1o) /*  OPERATION-ANCESTOR */;
  T2 = ecl_function_dispatch(cl_env_copy,VV[869])(1, T1) /*  OPERATION-VISITED-NODES */;
  T3 = CONS(ECL_T,v3data);
  value0 = si_hash_set(T0, T2, T3);
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G681                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC174__g681(cl_object v1o, cl_object v2c)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[309])(2, v1o, v2c) /*  NODE-FOR */;
  T1 = ecl_function_dispatch(cl_env_copy,VV[165])(1, v1o) /*  OPERATION-ANCESTOR */;
  T2 = ecl_function_dispatch(cl_env_copy,VV[869])(1, T1) /*  OPERATION-VISITED-NODES */;
  value0 = cl_gethash(2, T0, T2);
  return value0;
 }
}
/*	local function G682                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC175__g682(cl_object v1new_value, cl_object v2operation, cl_object v3component)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = v1new_value;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G689                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC176__g689(cl_object v1new_value, cl_object v2o, cl_object v3c)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4;
   cl_object v5;
   v4 = ecl_function_dispatch(cl_env_copy,VV[309])(2, v2o, v3c) /*  NODE-FOR */;
   v5 = ecl_function_dispatch(cl_env_copy,VV[165])(1, v2o) /*  OPERATION-ANCESTOR */;
   if (Null(v1new_value)) { goto L4; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[870])(1, v5) /*  OPERATION-VISITING-NODES */;
   si_hash_set(v4, T0, ECL_T);
   goto L3;
L4:;
   T0 = ecl_function_dispatch(cl_env_copy,VV[870])(1, v5) /*  OPERATION-VISITING-NODES */;
   cl_remhash(v4, T0);
L3:;
   value0 = v1new_value;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G695                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC177__g695(cl_object v1o, cl_object v2c)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3node;
   v3node = ecl_function_dispatch(cl_env_copy,VV[309])(2, v1o, v2c) /*  NODE-FOR */;
   T0 = ecl_function_dispatch(cl_env_copy,VV[165])(1, v1o) /*  OPERATION-ANCESTOR */;
   T1 = ecl_function_dispatch(cl_env_copy,VV[870])(1, T0) /*  OPERATION-VISITING-NODES */;
   value0 = cl_gethash(2, v3node, T1);
   return value0;
  }
 }
}
/*	local function G696                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC178__g696(cl_object v1op_spec, cl_object v2c)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = (cl_env_copy->function=(ECL_SYM("MAKE-INSTANCE",949)->symbol.gfdef))->cfun.entry(1, v1op_spec) /*  MAKE-INSTANCE */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[169])(2, T0, v2c) /*  COMPONENT-DEPENDS-ON */;
  return value0;
 }
}
/*	local function G697                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC179__g697(cl_object v1o, cl_object v2c)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T1 = cl_type_of(v1o);
  T2 = ecl_function_dispatch(cl_env_copy,VV[871])(1, v2c) /*  COMPONENT-IN-ORDER-TO */;
  T0 = ecl_assql(T1,T2);
  value0 = ecl_cdr(T0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G698                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC181__g698(cl_object v1o, cl_object v2c)
{
 cl_object T0, T1;
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v2c,env0);                   /*  C               */
  {cl_object v3;
   v3 = ECL_NIL;
   v3 = ecl_make_cclosure_va((cl_objectfn)LC180__g699,env0,Cblock);
   T0 = v3;
  }
  T1 = ecl_function_dispatch(cl_env_copy,VV[169])(2, v1o, ECL_CONS_CAR(CLV0)) /*  COMPONENT-DEPENDS-ON */;
  value0 = cl_remove_if_not(2, T0, T1);
  return value0;
 }
}
/*	closure G699                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC180__g699(cl_narg narg, cl_object v1x, ...)
{
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  C               */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  {
   cl_object v2;
   v2 = ecl_function_dispatch(cl_env_copy,VV[813])(1, ECL_CONS_CAR(CLV0)) /*  COMPONENT-NAME */;
   {
    cl_object v3;
    v3 = ecl_cdr(v1x);
    goto L5;
L4:;
    {
     cl_object v4;
     cl_object v5;
     if (ecl_unlikely(ECL_ATOM(v3))) FEtype_error_cons(v3);
     v4 = v3;
     v5 = ECL_CONS_CAR(v4);
     if (Null(cl_stringE(2, v2, v5))) { goto L7; }
     value0 = v4;
     cl_env_copy->nvalues = 1;
     return value0;
    }
L7:;
    v3 = ECL_CONS_CDR(v3);
L5:;
    if (v3==ECL_NIL) { goto L14; }
    goto L4;
L14:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
 }
}
/*	local function G709                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC182__g709(cl_object v1operation, cl_object v2c)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   v3 = ecl_function_dispatch(cl_env_copy,VV[814])(1, v2c) /*  COMPONENT-PARENT */;
   v4 = ecl_function_dispatch(cl_env_copy,VV[170])(2, v1operation, v2c) /*  COMPONENT-SELF-DEPENDENCIES */;
   if (Null(v4)) { goto L3; }
   {
    cl_object v5;
    cl_object v6;
    v5 = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
    v6 = v4;
    {
     cl_object v7;
     cl_object v8;
     v7 = ecl_list1(ECL_NIL);
     v8 = v7;
L10:;
     if (!(ecl_endp(v6))) { goto L12; }
     goto L11;
L12:;
     v5 = _ecl_car(v6);
     {
      cl_object v9;
      v9 = _ecl_cdr(v6);
      if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
      v6 = v9;
     }
     {
      cl_object v9;
      {
       cl_object v10;
       cl_object v11op;
       cl_object v12name;
       v10 = v5;
       if (!(v10==ECL_NIL)) { goto L25; }
       si_dm_too_few_arguments(v5);
L25:;
       {
        cl_object v13;
        v13 = ecl_car(v10);
        v10 = ecl_cdr(v10);
        v11op = v13;
       }
       if (!(v10==ECL_NIL)) { goto L31; }
       si_dm_too_few_arguments(v5);
L31:;
       {
        cl_object v13;
        v13 = ecl_car(v10);
        v10 = ecl_cdr(v10);
        v12name = v13;
       }
       if (Null(v10)) { goto L36; }
       si_dm_too_many_arguments(v5);
L36:;
       T0 = (cl_env_copy->function=(ECL_SYM("MAKE-INSTANCE",949)->symbol.gfdef))->cfun.entry(1, v11op) /*  MAKE-INSTANCE */;
       T1 = ecl_function_dispatch(cl_env_copy,VV[163])(2, v3, v12name) /*  FIND-COMPONENT */;
       v9 = ecl_function_dispatch(cl_env_copy,VV[151])(2, T0, T1) /*  OUTPUT-FILES */;
      }
      if (ecl_unlikely(ECL_ATOM(v8))) FEtype_error_cons(v8);
      T0 = v8;
      (ECL_CONS_CDR(T0)=v9,T0);
      if (Null(v9)) { goto L20; }
     }
     T0 = ecl_cdr(v8);
     v8 = ecl_last(T0,1);
L20:;
     goto L10;
L11:;
     value0 = ecl_cdr(v7);
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
L3:;
   T0 = ecl_function_dispatch(cl_env_copy,VV[157])(1, v2c) /*  COMPONENT-PATHNAME */;
   value0 = ecl_list1(T0);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G725                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC183__g725(cl_object v1operation, cl_object v2c)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G726                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC184__g726(cl_object v1o, cl_object v2c)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_type_of(v1o);
  T1 = ecl_function_dispatch(cl_env_copy,VV[872])(1, v2c) /*  COMPONENT-OPERATION-TIMES */;
  value0 = cl_gethash(2, T0, T1);
  return value0;
 }
}
/*	local function G727                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC187__g727(cl_object v1o, cl_object v2c)
{
 cl_object T0, T1;
 volatile cl_object lex0[2];
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   v3 = ecl_function_dispatch(cl_env_copy,VV[151])(2, v1o, v2c) /*  OUTPUT-FILES */;
   v4 = ecl_function_dispatch(cl_env_copy,VV[152])(2, v1o, v2c) /*  INPUT-FILES */;
   v5 = ecl_function_dispatch(cl_env_copy,VV[153])(2, v1o, v2c) /*  COMPONENT-OPERATION-TIME */;
   lex0[0] = v3;                                  /*  OUT-FILES       */
   lex0[1] = v4;                                  /*  IN-FILES        */
   if ((lex0[1])!=ECL_NIL) { goto L4; }
   if ((lex0[0])!=ECL_NIL) { goto L4; }
   value0 = ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
L4:;
   if ((lex0[0])!=ECL_NIL) { goto L7; }
   if (Null(v5)) { goto L10; }
   T0 = LC186latest_in(lex0);
   value0 = ecl_make_bool(ecl_number_compare(v5,T0)>=0);
   cl_env_copy->nvalues = 1;
   return value0;
L10:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L7:;
   if ((lex0[1])!=ECL_NIL) { goto L13; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L13:;
   T0 = ecl_fdefinition(VV[116]);
   if (Null(cl_every(2, T0, lex0[1]))) { goto L16; }
   T0 = ecl_fdefinition(VV[116]);
   if (Null(cl_every(2, T0, lex0[0]))) { goto L16; }
   T0 = LC185earliest_out(lex0);
   T1 = LC186latest_in(lex0);
   value0 = ecl_make_bool(ecl_number_compare(T0,T1)>=0);
   cl_env_copy->nvalues = 1;
   return value0;
L16:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function LATEST-IN                                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC186latest_in(volatile cl_object *lex0)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = (ECL_SYM("MAX",551)->symbol.gfdef);
  {
   cl_object v1;
   cl_object v2;
   v1 = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(lex0[1]))) FEtype_error_list(lex0[1]);
   v2 = lex0[1];
   {
    cl_object v3;
    cl_object v4;
    v3 = ecl_list1(ECL_NIL);
    v4 = v3;
L8:;
    if (!(ecl_endp(v2))) { goto L10; }
    goto L9;
L10:;
    v1 = _ecl_car(v2);
    {
     cl_object v5;
     v5 = _ecl_cdr(v2);
     if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
     v2 = v5;
    }
    if (ecl_unlikely(ECL_ATOM(v4))) FEtype_error_cons(v4);
    T2 = v4;
    T3 = ecl_function_dispatch(cl_env_copy,VV[274])(1, v1) /*  SAFE-FILE-WRITE-DATE */;
    v4 = ecl_list1(T3);
    (ECL_CONS_CDR(T2)=v4,T2);
    goto L8;
L9:;
    T1 = ecl_cdr(v3);
    goto L2;
   }
  }
L2:;
  value0 = cl_reduce(2, T0, T1);
  return value0;
 }
}
/*	local function EARLIEST-OUT                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC185earliest_out(volatile cl_object *lex0)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = (ECL_SYM("MIN",557)->symbol.gfdef);
  {
   cl_object v1;
   cl_object v2;
   v1 = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(lex0[0]))) FEtype_error_list(lex0[0]);
   v2 = lex0[0];
   {
    cl_object v3;
    cl_object v4;
    v3 = ecl_list1(ECL_NIL);
    v4 = v3;
L8:;
    if (!(ecl_endp(v2))) { goto L10; }
    goto L9;
L10:;
    v1 = _ecl_car(v2);
    {
     cl_object v5;
     v5 = _ecl_cdr(v2);
     if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
     v2 = v5;
    }
    if (ecl_unlikely(ECL_ATOM(v4))) FEtype_error_cons(v4);
    T2 = v4;
    T3 = ecl_function_dispatch(cl_env_copy,VV[274])(1, v1) /*  SAFE-FILE-WRITE-DATE */;
    v4 = ecl_list1(T3);
    (ECL_CONS_CDR(T2)=v4,T2);
    goto L8;
L9:;
    T1 = ecl_cdr(v3);
    goto L2;
   }
  }
L2:;
  value0 = cl_reduce(2, T0, T1);
  return value0;
 }
}
/*	function definition for RESOLVE-DEPENDENCY-NAME               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L191resolve_dependency_name(volatile cl_narg narg, cl_object volatile v1component, cl_object volatile v2name, ...)
{
 cl_object T0, T1, T2, T3, T4, T5;
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1, CLV2, CLV3
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  volatile cl_object v3version;
  va_list args; va_start(args,v2name);
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1component,env0);           /*  COMPONENT       */
  CLV1 = env0 = CONS(v2name,env0);                /*  NAME            */
  {
   int i = 2;
   if (i >= narg) {
    v3version = ECL_NIL;
   } else {
    i++;
    v3version = va_arg(args,cl_object);
   }
  }
  va_end(args);
L2:;
  {
   volatile cl_object env1 = env0;
   CLV2 = env1 = CONS(ECL_NIL,env1);
   {
    volatile cl_object env2 = env1;
    CLV3 = env2 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env2); /*  TAGBODY */
    if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV3))) {
    if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L4;
    ecl_internal_error("GO found an inexistent tag");
    }
    {cl_object v4;
     v4 = ECL_NIL;
     v4 = ecl_make_cclosure_va((cl_objectfn)LC188__g748,env2,Cblock);
     T0 = v4;
    }
    {cl_object v4;
     v4 = ECL_NIL;
     v4 = ecl_make_cclosure_va((cl_objectfn)LC189__g749,env2,Cblock);
     T1 = v4;
    }
    {cl_object v4;
     v4 = ECL_NIL;
     v4 = ecl_make_cclosure_va((cl_objectfn)LC190__g750,env2,Cblock);
     T2 = v4;
    }
    T3 = ecl_function_dispatch(cl_env_copy,VV[851])(8, ECL_SYM("NAME",1273), VV[319], ECL_SYM("FUNCTION",1241), T0, VV[268], T1, VV[320], T2) /*  MAKE-RESTART */;
    T4 = ecl_list1(T3);
    T5 = CONS(T4,ecl_symbol_value(ECL_SYM("*RESTART-CLUSTERS*",4)));
    ecl_bds_bind(cl_env_copy,ECL_SYM("*RESTART-CLUSTERS*",4),T5); /*  *RESTART-CLUSTERS* */
    {
     cl_object v4comp;
     T0 = ecl_function_dispatch(cl_env_copy,VV[814])(1, ECL_CONS_CAR(CLV0)) /*  COMPONENT-PARENT */;
     v4comp = ecl_function_dispatch(cl_env_copy,VV[163])(2, T0, ECL_CONS_CAR(CLV1)) /*  FIND-COMPONENT */;
     if ((v4comp)!=ECL_NIL) { goto L10; }
     cl_error(5, VV[180], VV[321], ECL_CONS_CAR(CLV0), VV[290], ECL_CONS_CAR(CLV1));
L10:;
     if (Null(v3version)) { goto L12; }
     if ((ecl_function_dispatch(cl_env_copy,VV[162])(2, v4comp, v3version) /*  VERSION-SATISFIES */)!=ECL_NIL) { goto L12; }
     cl_error(7, VV[181], VV[321], ECL_CONS_CAR(CLV0), ECL_SYM("VERSION",1326), v3version, VV[290], ECL_CONS_CAR(CLV1));
L12:;
     value0 = v4comp;
     cl_env_copy->nvalues = 1;
     ecl_frs_pop(cl_env_copy);
     ecl_bds_unwind1(cl_env_copy);
     return value0;
    }
L4:;
    ecl_frs_pop(cl_env_copy);
    goto L3;
   }
  }
L3:;
  goto L2;
 }
}
/*	closure G748                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC188__g748(cl_narg narg, ...)
{
 cl_object CLV0, CLV1, CLV2, CLV3
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV3 = env0;                                     /*  TAGBODY         */
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 {
  cl_object v1si__temp;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1si__temp = cl_grab_rest_args(args);
  ecl_va_end(args);
  ECL_CONS_CAR(CLV2) = v1si__temp;
  cl_go(ECL_CONS_CAR(CLV3),ecl_make_fixnum(0));
 }
 }
}
/*	closure G749                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC189__g749(cl_narg narg, cl_object v1s, ...)
{
 cl_object CLV0, CLV1, CLV2, CLV3
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV3 = env0;
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);                           /*  NAME            */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = cl_format(3, v1s, _ecl_static_59, ECL_CONS_CAR(CLV1));
  return value0;
 }
 }
}
/*	closure G750                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC190__g750(cl_narg narg, cl_object v1c, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1, CLV2, CLV3
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV3 = env0;
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);                           /*  NAME            */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = ecl_make_bool(v1c==ECL_NIL);
  if ((value0)!=ECL_NIL) { goto L2; }
  if (Null(si_of_class_p(2, v1c, VV[180]))) { goto L5; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[815])(1, v1c) /*  MISSING-REQUIRED-BY */;
  if (!((T0)==(ECL_CONS_CAR(CLV0)))) { goto L5; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[817])(1, v1c) /*  MISSING-REQUIRES */;
  value0 = ecl_make_bool(ecl_equal(T0,ECL_CONS_CAR(CLV1)));
  cl_env_copy->nvalues = 1;
  return value0;
L5:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
 }
}
/*	function definition for RESOLVE-DEPENDENCY-SPEC               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L192resolve_dependency_spec(cl_object v1component, cl_object v2dep_spec)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_ATOM(v2dep_spec))) { goto L1; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[318])(2, v1component, v2dep_spec) /*  RESOLVE-DEPENDENCY-NAME */;
  return value0;
L1:;
  T0 = ecl_car(v2dep_spec);
  if (!((ECL_SYM("VERSION",1326))==(T0))) { goto L3; }
  T0 = ecl_cadr(v2dep_spec);
  T1 = ecl_caddr(v2dep_spec);
  value0 = ecl_function_dispatch(cl_env_copy,VV[318])(3, v1component, T0, T1) /*  RESOLVE-DEPENDENCY-NAME */;
  return value0;
L3:;
  T0 = ecl_car(v2dep_spec);
  if (!((VV[324])==(T0))) { goto L5; }
  cl_cerror(2, _ecl_static_60, _ecl_static_61);
  {
   cl_object v3;
   v3 = ecl_cadr(v2dep_spec);
   {
    cl_object v4;
    cl_object v5;
    v4 = ecl_symbol_value(ECL_SYM("*FEATURES*",34));
    v5 = si_make_seq_iterator(2, v4, ecl_make_fixnum(0));
L13:;
    if ((v5)!=ECL_NIL) { goto L15; }
    goto L8;
L15:;
    {
     cl_object v6;
     v6 = si_seq_iterator_ref(v4, v5);
     if (Null(ecl_function_dispatch(cl_env_copy,ECL_SYM("STRING-EQUAL",808))(2, v3, v6))) { goto L17; }
     if (Null(v6)) { goto L8; }
     goto L9;
    }
L17:;
    v5 = si_seq_iterator_next(v4, v5);
    goto L13;
   }
  }
L9:;
  T0 = ecl_caddr(v2dep_spec);
  value0 = ecl_function_dispatch(cl_env_copy,VV[318])(2, v1component, T0) /*  RESOLVE-DEPENDENCY-NAME */;
  return value0;
L8:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L5:;
  value0 = cl_error(2, _ecl_static_62, v2dep_spec);
  return value0;
 }
}
/*	function definition for DO-ONE-DEP                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L193do_one_dep(cl_object v1op, cl_object v2c, cl_object v3collect, cl_object v4dep_op, cl_object v5dep_c)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[311])(4, v2c, v1op, v5dep_c, v4dep_op) /*  MAKE-SUB-OPERATION */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[317])(3, T0, v5dep_c, v3collect) /*  DO-TRAVERSE */;
  return value0;
 }
}
/*	function definition for DO-DEP                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L194do_dep(cl_object v1op, cl_object v2c, cl_object v3collect, cl_object v4dep_op_spec, cl_object v5dep_c_specs)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!((v4dep_op_spec)==(VV[329]))) { goto L1; }
  T0 = ecl_car(v5dep_c_specs);
  if (Null(ecl_memql(T0,ecl_symbol_value(ECL_SYM("*FEATURES*",34))))) { goto L3; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L3:;
  T0 = ecl_car(v5dep_c_specs);
  T1 = cl_list(2, VV[324], T0);
  value0 = cl_error(5, VV[180], VV[321], v2c, VV[290], T1);
  return value0;
L1:;
  {
   cl_object v6flag;
   v6flag = ECL_NIL;
   {
    cl_object v7;
    v7 = v5dep_c_specs;
    goto L10;
L9:;
    {
     cl_object v8d;
     v8d = ecl_car(v7);
     T0 = ecl_function_dispatch(cl_env_copy,VV[323])(2, v2c, v8d) /*  RESOLVE-DEPENDENCY-SPEC */;
     if (Null(ecl_function_dispatch(cl_env_copy,VV[326])(5, v1op, v2c, v3collect, v4dep_op_spec, T0) /*  DO-ONE-DEP */)) { goto L14; }
     v6flag = ECL_T;
L14:;
    }
    v7 = ecl_cdr(v7);
L10:;
    if (Null(v7)) { goto L19; }
    goto L9;
L19:;
   }
   value0 = v6flag;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for DO-COLLECT                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L195do_collect(cl_object v1collect, cl_object v2x)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,v1collect)(1, v2x);
  return value0;
 }
}
/*	local function G792                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC202__g792(cl_object volatile v1operation, cl_object volatile v2c, cl_object volatile v3collect)
{
 cl_object T0, T1, T2, T3;
 volatile cl_object lex0[4];
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1, CLV2, CLV3
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  lex0[0] = v1operation;                          /*  OPERATION       */
  lex0[1] = v2c;                                  /*  C               */
  lex0[2] = v3collect;                            /*  COLLECT         */
TTL:
  {
   volatile cl_object v4;
   v4 = ecl_symbol_value(VV[316]);
   ecl_bds_bind(cl_env_copy,VV[316],v4);          /*  *FORCING*       */
   lex0[3] = ECL_NIL;                             /*  FLAG            */
   {
    cl_object v5it;
    v5it = ecl_function_dispatch(cl_env_copy,VV[166])(2, lex0[0], lex0[1]) /*  COMPONENT-VISITED-P */;
    if (Null(v5it)) { goto L3; }
    T0 = ecl_cdr(v5it);
    LC196update_flag(lex0, T0);
    value0 = lex0[3];
    cl_env_copy->nvalues = 1;
    ecl_bds_unwind1(cl_env_copy);
    return value0;
   }
L3:;
   if (Null(ecl_function_dispatch(cl_env_copy,VV[168])(2, lex0[0], lex0[1]) /*  COMPONENT-VISITING-P */)) { goto L7; }
   T0 = ecl_list1(lex0[1]);
   cl_error(3, VV[176], VV[334], T0);
L7:;
   (cl_env_copy->function=ecl_fdefinition(VV[878]))->cfun.entry(3, ECL_T, lex0[0], lex0[1]) /*  (SETF VISITING-COMPONENT) */;
   {
    volatile bool unwinding = FALSE;
    cl_index v5=ECL_STACK_INDEX(cl_env_copy),v6;
    ecl_frame_ptr next_fr;
    if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
      unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
    } else {
    if (Null(si_of_class_p(2, lex0[1], VV[213]))) { goto L11; }
    {
     cl_object v7ancestor;
     v7ancestor = ecl_function_dispatch(cl_env_copy,VV[165])(1, lex0[0]) /*  OPERATION-ANCESTOR */;
     T0 = ecl_function_dispatch(cl_env_copy,VV[879])(1, v7ancestor) /*  OPERATION-FORCED */;
     if (Null(LC198match_(lex0, T0))) { goto L14; }
     cl_set(VV[316],ECL_T);
     goto L11;
L14:;
     T0 = ecl_function_dispatch(cl_env_copy,VV[880])(1, v7ancestor) /*  OPERATION-FORCED-NOT */;
     if (Null(LC198match_(lex0, T0))) { goto L11; }
     cl_env_copy->values[0] = ECL_NIL;
     cl_env_copy->nvalues = 1;
     goto L10;
    }
L11:;
    ecl_bds_bind(cl_env_copy,VV[316],ECL_NIL);    /*  *FORCING*       */
    {
     cl_object v7;
     cl_object v8required_op;
     cl_object v9deps;
     cl_object v10;
     v7 = ecl_function_dispatch(cl_env_copy,VV[169])(2, lex0[0], lex0[1]) /*  COMPONENT-DEPENDS-ON */;
     v8required_op = ECL_NIL;
     v9deps = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
     v10 = v7;
L24:;
     if (!(ecl_endp(v10))) { goto L26; }
     goto L25;
L26:;
     {
      cl_object v11;
      v11 = _ecl_car(v10);
      v8required_op = ecl_car(v11);
      v11 = ecl_cdr(v11);
      v9deps = v11;
     }
     {
      cl_object v11;
      v11 = _ecl_cdr(v10);
      if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
      v10 = v11;
     }
     LC197dep(lex0, v8required_op, v9deps);
     goto L24;
L25:;
     ecl_bds_unwind1(cl_env_copy);
    }
    {
     volatile cl_object v7module_ops;
     if (Null(si_of_class_p(2, lex0[1], VV[172]))) { goto L42; }
     {
      volatile cl_object v8;
      volatile cl_object v9error;
      volatile cl_object env1 = env0;
      value0 = ecl_symbol_value(VV[316]);
      if ((value0)!=ECL_NIL) { goto L46; }
      if (Null(lex0[3])) { goto L49; }
      T0 = si_of_class_p(2, lex0[1], VV[213]);
      v8 = Null(T0)?ECL_T:ECL_NIL;
      goto L44;
L49:;
      v8 = ECL_NIL;
      goto L44;
L46:;
      v8 = value0;
      goto L44;
L44:;
      env1 = ECL_NIL;
      CLV0 = env1 = CONS(ECL_NIL,env1);           /*  AT-LEAST-ONE    */
      ecl_bds_bind(cl_env_copy,VV[316],v8);       /*  *FORCING*       */
      v9error = ECL_NIL;
      {
       volatile cl_object env2 = env1;
       CLV1 = env2 = CONS(ECL_NIL,env2);
       {cl_object v10;
        v10 = ECL_NIL;
        v10 = ecl_make_cclosure_va((cl_objectfn)LC199internal_collect,env2,Cblock);
        {
         volatile cl_object v11;
         v11 = ecl_function_dispatch(cl_env_copy,VV[822])(1, lex0[1]) /*  MODULE-COMPONENTS */;
         goto L56;
L55:;
         {
          volatile cl_object v12kid;
          v12kid = ecl_car(v11);
          {
          struct ecl_stack_frame _ecl_inner_frame_aux;
          volatile cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
          {
          volatile cl_object v13;
          v13 = _ecl_inner_frame;
          {
          volatile cl_object v14;
          {cl_object v15;
          v15 = ECL_NIL;
          v15 = ecl_make_cclosure_va((cl_objectfn)LC200__g815,env2,Cblock);
          v14 = v15;
          }
          {
          volatile cl_object env3 = env2;
          CLV2 = env3 = CONS(ECL_NIL,env3);
          {
          volatile cl_object env4 = env3;
          CLV3 = env4 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env4); /*  TAGBODY */
          if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV3))) {
          if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L66;
          ecl_internal_error("GO found an inexistent tag");
          }
          {cl_object v15;
          v15 = ECL_NIL;
          v15 = ecl_make_cclosure_va((cl_objectfn)LC201__g820,env4,Cblock);
          T0 = v15;
          }
          T1 = CONS(VV[180],T0);
          T2 = ecl_list1(T1);
          T3 = CONS(T2,ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5)));
          ecl_bds_bind(cl_env_copy,ECL_SYM("*HANDLER-CLUSTERS*",5),T3); /*  *HANDLER-CLUSTERS* */
          T0 = ecl_function_dispatch(cl_env_copy,VV[317])(3, lex0[0], v12kid, v10) /*  DO-TRAVERSE */;
          cl_env_copy->values[0] = LC196update_flag(lex0, T0);
          ecl_frs_pop(cl_env_copy);
          ecl_bds_unwind1(cl_env_copy);
          goto L65;
L66:;
          {
          cl_object v15condition;
          v15condition = ECL_CONS_CAR(CLV2);
          T0 = ecl_function_dispatch(cl_env_copy,VV[881])(1, lex0[1]) /*  MODULE-IF-COMPONENT-DEP-FAILS */;
          if (!((T0)==(VV[335]))) { goto L71; }
          cl_error(1, v15condition);
L71:;
          v9error = v15condition;
          ecl_frs_pop(cl_env_copy);
          ecl_stack_frame_close(_ecl_inner_frame);
          goto L60;
          }
          }
          }
L65:;
          ecl_stack_frame_push_values(v13);cl_env_copy->values[0]=ecl_apply_from_stack_frame(v13,v14);
          }
          }
          ecl_stack_frame_close(_ecl_inner_frame);
          }
L60:;
         }
         v11 = ecl_cdr(v11);
L56:;
         if (Null(v11)) { goto L76; }
         goto L55;
L76:;
        }
        T0 = ecl_function_dispatch(cl_env_copy,VV[881])(1, lex0[1]) /*  MODULE-IF-COMPONENT-DEP-FAILS */;
        if (!((T0)==(VV[336]))) { goto L78; }
        if ((ECL_CONS_CAR(CLV0))!=ECL_NIL) { goto L78; }
        cl_error(1, v9error);
L78:;
        v7module_ops = cl_reverse(ECL_CONS_CAR(CLV1));
        ecl_bds_unwind1(cl_env_copy);
        goto L41;
       }
      }
     }
L42:;
     v7module_ops = ECL_NIL;
L41:;
     value0 = ecl_symbol_value(VV[316]);
     if ((value0)!=ECL_NIL) { goto L84; }
     T1 = ecl_function_dispatch(cl_env_copy,VV[148])(2, lex0[0], lex0[1]) /*  OPERATION-DONE-P */;
     T0 = Null(T1)?ECL_T:ECL_NIL;
     goto L82;
L84:;
     T0 = value0;
     goto L82;
L82:;
     LC196update_flag(lex0, T0);
     if (Null(lex0[3])) { goto L86; }
     {
      cl_object v8do_first;
      T1 = cl_class_of(lex0[0]);
      T2 = (cl_env_copy->function=(ECL_SYM("CLASS-NAME",934)->symbol.gfdef))->cfun.entry(1, T1) /*  CLASS-NAME */;
      T3 = ecl_function_dispatch(cl_env_copy,VV[882])(1, lex0[1]) /*  COMPONENT-DO-FIRST */;
      T0 = ecl_assql(T2,T3);
      v8do_first = ecl_cdr(T0);
      {
       cl_object v9required_op;
       cl_object v10deps;
       cl_object v11;
       v9required_op = ECL_NIL;
       v10deps = ECL_NIL;
       if (ecl_unlikely(!ECL_LISTP(v8do_first))) FEtype_error_list(v8do_first);
       v11 = v8do_first;
L95:;
       if (!(ecl_endp(v11))) { goto L97; }
       goto L96;
L97:;
       {
        cl_object v12;
        v12 = _ecl_car(v11);
        v9required_op = ecl_car(v12);
        v12 = ecl_cdr(v12);
        v10deps = v12;
       }
       {
        cl_object v12;
        v12 = _ecl_cdr(v11);
        if (ecl_unlikely(!ECL_LISTP(v12))) FEtype_error_list(v12);
        v11 = v12;
       }
       ecl_function_dispatch(cl_env_copy,VV[328])(5, lex0[0], lex0[1], lex0[2], v9required_op, v10deps) /*  DO-DEP */;
       goto L95;
L96:;
      }
     }
     T0 = cl_vector(1, v7module_ops);
     ecl_function_dispatch(cl_env_copy,VV[332])(2, lex0[2], T0) /*  DO-COLLECT */;
     T0 = CONS(lex0[0],lex0[1]);
     cl_env_copy->values[0] = ecl_function_dispatch(cl_env_copy,VV[332])(2, lex0[2], T0) /*  DO-COLLECT */;
     goto L10;
L86:;
     cl_env_copy->values[0] = ECL_NIL;
     cl_env_copy->nvalues = 1;
    }
L10:;
    }
    ecl_frs_pop(cl_env_copy);
    v6=ecl_stack_push_values(cl_env_copy);
    (cl_env_copy->function=ecl_fdefinition(VV[878]))->cfun.entry(3, ECL_NIL, lex0[0], lex0[1]) /*  (SETF VISITING-COMPONENT) */;
    ecl_stack_pop_values(cl_env_copy,v6);
    if (unwinding) ecl_unwind(cl_env_copy,next_fr);
    ECL_STACK_SET_INDEX(cl_env_copy,v5);
   }
   if (Null(lex0[3])) { goto L116; }
   cl_set(VV[331],ecl_plus(ecl_symbol_value(VV[331]),ecl_make_fixnum(1)));
   T0 = ecl_symbol_value(VV[331]);
   goto L115;
L116:;
   T0 = ECL_NIL;
L115:;
   ecl_function_dispatch(cl_env_copy,VV[167])(3, lex0[0], lex0[1], T0) /*  VISIT-COMPONENT */;
   value0 = lex0[3];
   cl_env_copy->nvalues = 1;
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
 }
}
/*	local function DEP                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC197dep(volatile cl_object *lex0, cl_object v1op, cl_object v2comp)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[328])(5, lex0[0], lex0[1], lex0[2], v1op, v2comp) /*  DO-DEP */;
  value0 = LC196update_flag(lex0, T0);
  return value0;
 }
}
/*	local function UPDATE-FLAG                                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC196update_flag(volatile cl_object *lex0, cl_object v1x)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = lex0[3];
  if ((value0)!=ECL_NIL) { goto L3; }
  lex0[3] = v1x;
  goto L1;
L3:;
  lex0[3] = value0;
  goto L1;
L1:;
  value0 = lex0[3];
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function MATCH?                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC198match_(volatile cl_object *lex0, cl_object v1f)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1f)) { goto L2; }
  {
   bool v2;
   v2 = ECL_CONSP(v1f);
   value0 = (v2)?ECL_NIL:ECL_T;
  }
  if ((value0)!=ECL_NIL) { goto L5; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[813])(1, lex0[1]) /*  COMPONENT-NAME */;
  value0 = ecl_member(T0,v1f);
  cl_env_copy->nvalues = 1;
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
/*	closure INTERNAL-COLLECT                                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC199internal_collect(cl_narg narg, cl_object v1x, ...)
{
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  ECL_CONS_CAR(CLV1) = CONS(v1x,ECL_CONS_CAR(CLV1));
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  return value0;
 }
 }
}
/*	closure G815                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC200__g815(cl_narg narg, cl_object v1c, ...)
{
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;
 CLV0 = _ecl_cdr(CLV1);                           /*  AT-LEAST-ONE    */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  ECL_CONS_CAR(CLV0) = ECL_T;
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
 }
 }
}
/*	closure G820                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC201__g820(cl_narg narg, cl_object v1si__temp, ...)
{
 cl_object CLV0, CLV1, CLV2, CLV3
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV3 = env0;                                     /*  TAGBODY         */
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  ECL_CONS_CAR(CLV2) = v1si__temp;
  cl_go(ECL_CONS_CAR(CLV3),ecl_make_fixnum(0));
 }
 }
}
/*	function definition for FLATTEN-TREE                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L206flatten_tree(cl_object v1l)
{
 cl_object env0;
 volatile struct ecl_cclosure aux_closure;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object env1 = env0;
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(ECL_NIL,env1);
   {volatile cl_object env2 = env1;
    CLV1 = env2 = CONS(ECL_NIL,env2);             /*  R               */
    ECL_CONS_CAR(CLV1) = ecl_make_cclosure_va((cl_objectfn)LC204r,env2,Cblock);
    (aux_closure.env=env2,cl_env_copy->function=(cl_object)&aux_closure,LC205r_(1, v1l));
   }
   value0 = cl_reverse(ECL_CONS_CAR(CLV0));
   return value0;
  }
 }
}
/*	closure C                                                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC203c(cl_narg narg, cl_object v1x, ...)
{
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  ECL_CONS_CAR(CLV0) = CONS(v1x,ECL_CONS_CAR(CLV0));
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  return value0;
 }
 }
}
/*	closure R*                                                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC205r_(cl_narg narg, cl_object v1l, ...)
{
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  R               */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = cl_map(3, ECL_NIL, ECL_CONS_CAR(CLV1), v1l);
  return value0;
 }
 }
}
/*	closure R                                                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC204r(cl_narg narg, cl_object v1x, ...)
{
 cl_object T0;
 volatile struct ecl_cclosure aux_closure;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  R               */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  if (Null(cl_typep(2, v1x, VV[338]))) { goto L1; }
  T0 = ecl_aref1(v1x,0);
  value0 = (aux_closure.env=env0,cl_env_copy->function=(cl_object)&aux_closure,LC205r_(1, T0));
  return value0;
L1:;
  value0 = (aux_closure.env=ecl_nthcdr(1,env0),cl_env_copy->function=(cl_object)&aux_closure,LC203c(1, v1x));
  return value0;
 }
 }
}
/*	local function G839                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC208__g839(cl_object v1operation, cl_object v2c)
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object env1 = env0;
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(ECL_NIL,env1);
   {cl_object v3;
    v3 = ECL_NIL;
    v3 = ecl_make_cclosure_va((cl_objectfn)LC207collect,env1,Cblock);
    ecl_bds_bind(cl_env_copy,VV[331],ecl_make_fixnum(0)); /*  *VISIT-COUNT* */
    ecl_function_dispatch(cl_env_copy,VV[317])(3, v1operation, v2c, v3) /*  DO-TRAVERSE */;
    ecl_bds_unwind1(cl_env_copy);
    T0 = cl_reverse(ECL_CONS_CAR(CLV0));
   }
  }
  value0 = ecl_function_dispatch(cl_env_copy,VV[337])(1, T0) /*  FLATTEN-TREE */;
  return value0;
 }
}
/*	closure COLLECT                                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC207collect(cl_narg narg, cl_object v1x, ...)
{
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  ECL_CONS_CAR(CLV0) = CONS(v1x,ECL_CONS_CAR(CLV0));
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  return value0;
 }
 }
}
/*	local function G842                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC209__g842(cl_object v1operation, cl_object v2c)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_class_of(v1operation);
  T1 = cl_class_of(v2c);
  value0 = ecl_function_dispatch(cl_env_copy,VV[191])(3, _ecl_static_63, T0, T1) /*  SYSDEF-ERROR */;
  return value0;
 }
}
/*	local function G843                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC210__g843(cl_object v1operation, cl_object v2c)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G850                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC211__g850(cl_object v1operation, cl_object v2c)
{
 cl_object T0, T1, T2, T3, T4, T5, T6;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_type_of(v1operation);
  T1 = ecl_function_dispatch(cl_env_copy,VV[872])(1, v2c) /*  COMPONENT-OPERATION-TIMES */;
  T2 = (ECL_SYM("MAX",551)->symbol.gfdef);
  T3 = cl_get_universal_time();
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   v3 = ecl_function_dispatch(cl_env_copy,VV[152])(2, v1operation, v2c) /*  INPUT-FILES */;
   v4 = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v3))) FEtype_error_list(v3);
   v5 = v3;
   {
    cl_object v6;
    cl_object v7;
    v6 = ecl_list1(ECL_NIL);
    v7 = v6;
L9:;
    if (!(ecl_endp(v5))) { goto L11; }
    goto L10;
L11:;
    v4 = _ecl_car(v5);
    {
     cl_object v8;
     v8 = _ecl_cdr(v5);
     if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
     v5 = v8;
    }
    if (ecl_unlikely(ECL_ATOM(v7))) FEtype_error_cons(v7);
    T5 = v7;
    T6 = ecl_function_dispatch(cl_env_copy,VV[274])(1, v4) /*  SAFE-FILE-WRITE-DATE */;
    v7 = ecl_list1(T6);
    (ECL_CONS_CDR(T5)=v7,T5);
    goto L9;
L10:;
    T4 = ecl_cdr(v6);
    goto L2;
   }
  }
L2:;
  T5 = CONS(T3,T4);
  T6 = cl_reduce(2, T2, T5);
  value0 = si_hash_set(T0, T1, T6);
  return value0;
 }
}
/*	local function G860                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC212__g860(cl_object v1operation, cl_object v2component)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[147])(2, v1operation, v2component) /*  PERFORM */;
  return value0;
 }
}
/*	local function G873                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC217__g873(cl_object volatile v1operation, cl_object volatile v2component)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7;
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1, CLV2, CLV3
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1operation,env0);           /*  OPERATION       */
  CLV1 = env0 = CONS(v2component,env0);           /*  COMPONENT       */
L1:;
  {
   volatile cl_object env1 = env0;
   CLV2 = env1 = CONS(ECL_NIL,env1);
   {
    volatile cl_object env2 = env1;
    CLV3 = env2 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env2); /*  TAGBODY */
    if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV3))) {
    if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L3;
    if (cl_env_copy->values[0]==ecl_make_fixnum(1))goto L4;
    ecl_internal_error("GO found an inexistent tag");
    }
    {cl_object v3;
     v3 = ECL_NIL;
     v3 = ecl_make_cclosure_va((cl_objectfn)LC213__g880,env2,Cblock);
     T0 = v3;
    }
    {cl_object v3;
     v3 = ECL_NIL;
     v3 = ecl_make_cclosure_va((cl_objectfn)LC214__g881,env2,Cblock);
     T1 = v3;
    }
    T2 = ecl_function_dispatch(cl_env_copy,VV[851])(6, ECL_SYM("NAME",1273), VV[319], ECL_SYM("FUNCTION",1241), T0, VV[268], T1) /*  MAKE-RESTART */;
    {cl_object v3;
     v3 = ECL_NIL;
     v3 = ecl_make_cclosure_va((cl_objectfn)LC215__g882,env2,Cblock);
     T3 = v3;
    }
    {cl_object v3;
     v3 = ECL_NIL;
     v3 = ecl_make_cclosure_va((cl_objectfn)LC216__g883,env2,Cblock);
     T4 = v3;
    }
    T5 = ecl_function_dispatch(cl_env_copy,VV[851])(6, ECL_SYM("NAME",1273), VV[340], ECL_SYM("FUNCTION",1241), T3, VV[268], T4) /*  MAKE-RESTART */;
    T6 = cl_list(2, T2, T5);
    T7 = CONS(T6,ecl_symbol_value(ECL_SYM("*RESTART-CLUSTERS*",4)));
    ecl_bds_bind(cl_env_copy,ECL_SYM("*RESTART-CLUSTERS*",4),T7); /*  *RESTART-CLUSTERS* */
    if (Null(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)))) { goto L10; }
    T0 = ecl_car(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
    T1 = ecl_cdr(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
    value0 = ecl_function_dispatch(cl_env_copy,T0)(2, ecl_symbol_value(ECL_SYM(".COMBINED-METHOD-ARGS.",1473)), T1);
    ecl_frs_pop(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    return value0;
L10:;
    value0 = cl_error(1, _ecl_static_36);
    ecl_frs_pop(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    return value0;
L3:;
    ecl_frs_pop(cl_env_copy);
    goto L2;
L4:;
    ecl_function_dispatch(cl_env_copy,VV[149])(2, ECL_CONS_CAR(CLV0), ECL_CONS_CAR(CLV1)) /*  MARK-OPERATION-DONE */;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    ecl_frs_pop(cl_env_copy);
    return value0;
   }
  }
L2:;
  goto L1;
 }
}
/*	closure G880                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC213__g880(cl_narg narg, ...)
{
 cl_object CLV0, CLV1, CLV2, CLV3
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV3 = env0;                                     /*  TAGBODY         */
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 {
  cl_object v1si__temp;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1si__temp = cl_grab_rest_args(args);
  ecl_va_end(args);
  ECL_CONS_CAR(CLV2) = v1si__temp;
  cl_go(ECL_CONS_CAR(CLV3),ecl_make_fixnum(0));
 }
 }
}
/*	closure G881                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC214__g881(cl_narg narg, cl_object v1s, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1, CLV2, CLV3
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV3 = env0;
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);                           /*  COMPONENT       */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[154])(2, ECL_CONS_CAR(CLV0), ECL_CONS_CAR(CLV1)) /*  OPERATION-DESCRIPTION */;
  value0 = cl_format(3, v1s, _ecl_static_64, T0);
  return value0;
 }
 }
}
/*	closure G882                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC215__g882(cl_narg narg, ...)
{
 cl_object CLV0, CLV1, CLV2, CLV3
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV3 = env0;                                     /*  TAGBODY         */
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 {
  cl_object v1si__temp;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1si__temp = cl_grab_rest_args(args);
  ecl_va_end(args);
  ECL_CONS_CAR(CLV2) = v1si__temp;
  cl_go(ECL_CONS_CAR(CLV3),ecl_make_fixnum(1));
 }
 }
}
/*	closure G883                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC216__g883(cl_narg narg, cl_object v1s, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1, CLV2, CLV3
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV3 = env0;
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);                           /*  COMPONENT       */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[154])(2, ECL_CONS_CAR(CLV0), ECL_CONS_CAR(CLV1)) /*  OPERATION-DESCRIPTION */;
  value0 = cl_format(3, v1s, _ecl_static_65, T0);
  return value0;
 }
 }
}
/*	local function G886                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC218__g886(cl_object v1operation, cl_object v2component)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[154])(2, v1operation, v2component) /*  OPERATION-DESCRIPTION */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[66])(2, _ecl_static_66, T0) /*  ASDF-MESSAGE */;
  return value0;
 }
}
/*	local function G887                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC219__g887(cl_object v1operation, cl_object v2component)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_class_of(v1operation);
  value0 = cl_format(4, ECL_NIL, _ecl_static_67, T0, v2component);
  return value0;
 }
}
/*	local function G888                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC220__g888()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_symbol_value(VV[19]);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G889                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC221__g889()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_symbol_value(VV[21]);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for OUTPUT-FILE                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L222output_file(cl_object v1operation, cl_object v2component)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3files;
   v3files = ecl_function_dispatch(cl_env_copy,VV[151])(2, v1operation, v2component) /*  OUTPUT-FILES */;
   goto L4;
L3:;
   si_assert_failure(1, VV[343]);
L4:;
   if ((ecl_function_dispatch(cl_env_copy,VV[105])(2, v3files, ecl_make_fixnum(1)) /*  LENGTH=N-P */)!=ECL_NIL) { goto L7; }
   goto L3;
L7:;
   value0 = ecl_car(v3files);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for ENSURE-ALL-DIRECTORIES-EXIST          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L223ensure_all_directories_exist(cl_object v1pathnames)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   v2 = v1pathnames;
   goto L4;
L3:;
   {
    cl_object v3pathname;
    v3pathname = ecl_car(v2);
    T0 = cl_translate_logical_pathname(1, v3pathname);
    cl_ensure_directories_exist(1, T0);
   }
   v2 = ecl_cdr(v2);
L4:;
   if (Null(v2)) { goto L11; }
   goto L3;
L11:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G895                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC224__g895(cl_object v1operation, cl_object v2c)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[151])(2, v1operation, v2c) /*  OUTPUT-FILES */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[345])(1, T0) /*  ENSURE-ALL-DIRECTORIES-EXIST */;
  return value0;
 }
}
/*	local function G896                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC225__g896(cl_object v1operation, cl_object v2c)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[149])(2, v1operation, v2c) /*  MARK-OPERATION-DONE */;
  return value0;
 }
}
/*	local function G897                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC226__g897(cl_object v1c)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_slot_boundp(v1c, VV[349]))) { goto L1; }
  value0 = cl_slot_value(v1c, VV[349]);
  return value0;
L1:;
  if (Null(ecl_function_dispatch(cl_env_copy,VV[814])(1, v1c) /*  COMPONENT-PARENT */)) { goto L3; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[814])(1, v1c) /*  COMPONENT-PARENT */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[347])(1, T0) /*  AROUND-COMPILE-HOOK */;
  return value0;
L3:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for ENSURE-FUNCTION                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L227ensure_function(cl_narg narg, cl_object v1fun, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2package;
  ecl_va_list args; ecl_va_start(args,v1fun,narg,1);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L227ensure_functionkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[1])) {
    v2package = VV[1];
   } else {
    v2package = keyvars[0];
   }
  }
  if (ECL_SYMBOLP(v1fun)) { goto L4; }
  if (Null(cl_functionp(v1fun))) { goto L2; }
  goto L3;
L4:;
L3:;
  value0 = v1fun;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  if (!(ECL_CONSP(v1fun))) { goto L6; }
  T0 = cl_list(2, ECL_SYM("FUNCTION",396), v1fun);
  value0 = cl_eval(T0);
  return value0;
L6:;
  if (!(ECL_STRINGP(v1fun))) { goto L8; }
  {
   cl_object v3;
   v3 = ecl_symbol_value(ECL_SYM("+IO-SYNTAX-PROGV-LIST+",1720));
   {
    cl_object v5, v6; cl_index v4;
    v5 = _ecl_car(v3);
    v6 = _ecl_cdr(v3);
    v4 = ecl_progv(cl_env_copy, v5, v6);
    T1 = cl_find_package(v2package);
    ecl_bds_bind(cl_env_copy,ECL_SYM("*PACKAGE*",43),T1); /*  *PACKAGE* */
    T0 = cl_read_from_string(1, v1fun);
    ecl_bds_unwind(cl_env_copy,v4);
   }
  }
  T1 = cl_list(2, ECL_SYM("FUNCTION",396), T0);
  value0 = cl_eval(T1);
  return value0;
L8:;
  value0 = si_etypecase_error(v1fun, VV[350]);
  return value0;
 }
}
/*	function definition for CALL-AROUND-HOOK                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L228call_around_hook(cl_object v1hook, cl_object v2function)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = L227ensure_function(1, v1hook);
   if (Null(v3)) { goto L3; }
   T0 = v3;
   goto L1;
L3:;
   T0 = ECL_SYM("FUNCALL",394);
  }
L1:;
  value0 = ecl_function_dispatch(cl_env_copy,T0)(1, v2function);
  return value0;
 }
}
/*	local function G901                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC229__g901(cl_object v1c, cl_object v2function)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[347])(1, v1c) /*  AROUND-COMPILE-HOOK */;
  value0 = L228call_around_hook(T0, v2function);
  return value0;
 }
}
/*	local function G902                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC231__g902(cl_object v1operation, cl_object v2c)
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0, CLV1, CLV2, CLV3
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1operation,env0);           /*  OPERATION       */
  CLV1 = env0 = CONS(v2c,env0);                   /*  C               */
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6;
   cl_object env1 = env0;
   v3 = ecl_function_dispatch(cl_env_copy,VV[157])(1, ECL_CONS_CAR(CLV1)) /*  COMPONENT-PATHNAME */;
   T0 = ecl_function_dispatch(cl_env_copy,VV[151])(2, ECL_CONS_CAR(CLV0), ECL_CONS_CAR(CLV1)) /*  OUTPUT-FILES */;
   v4 = ecl_car(T0);
   v5 = ecl_function_dispatch(cl_env_copy,VV[889])(1, ECL_CONS_CAR(CLV0)) /*  OPERATION-ON-WARNINGS */;
   v6 = ecl_function_dispatch(cl_env_copy,VV[890])(1, ECL_CONS_CAR(CLV0)) /*  OPERATION-ON-FAILURE */;
   CLV2 = env1 = CONS(v3,env1);                   /*  SOURCE-FILE     */
   CLV3 = env1 = CONS(v4,env1);                   /*  OUTPUT-FILE     */
   ecl_bds_bind(cl_env_copy,VV[19],v5);           /*  *COMPILE-FILE-WARNINGS-BEHAVIOUR* */
   ecl_bds_bind(cl_env_copy,VV[21],v6);           /*  *COMPILE-FILE-FAILURE-BEHAVIOUR* */
   {
    cl_object v8;                                 /*  OUTPUT          */
    cl_object v9;                                 /*  WARNINGS-P      */
    cl_object v10;                                /*  FAILURE-P       */
    {cl_object v11;
     v11 = ECL_NIL;
     v11 = ecl_make_cclosure_va((cl_objectfn)LC230__g907,env1,Cblock);
     T0 = v11;
    }
    value0 = ecl_function_dispatch(cl_env_copy,VV[348])(2, ECL_CONS_CAR(CLV1), T0) /*  CALL-WITH-AROUND-COMPILE-HOOK */;
    v8 = value0;
    {
     const int v11 = cl_env_copy->nvalues;
     cl_object v12;
     v12 = (v11<=1)? ECL_NIL : cl_env_copy->values[1];
     v9 = v12;
     v12 = (v11<=2)? ECL_NIL : cl_env_copy->values[2];
     v10 = v12;
    }
    if ((v8)!=ECL_NIL) { goto L7; }
    cl_error(5, VV[183], VV[354], ECL_CONS_CAR(CLV1), ECL_SYM("OPERATION",1280), ECL_CONS_CAR(CLV0));
L7:;
    if (Null(v10)) { goto L9; }
    {
     cl_object v11;
     v11 = ecl_function_dispatch(cl_env_copy,VV[890])(1, ECL_CONS_CAR(CLV0)) /*  OPERATION-ON-FAILURE */;
     if (!(ecl_eql(v11,VV[20]))) { goto L12; }
     (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(3, _ecl_static_68, ECL_CONS_CAR(CLV0), ECL_CONS_CAR(CLV1)) /*  WARN */;
     goto L9;
L12:;
     if (!(ecl_eql(v11,ECL_SYM("ERROR",1229)))) { goto L14; }
     cl_error(5, VV[184], VV[354], ECL_CONS_CAR(CLV1), ECL_SYM("OPERATION",1280), ECL_CONS_CAR(CLV0));
     goto L9;
L14:;
     if (!(ecl_eql(v11,ECL_SYM("IGNORE",1247)))) { goto L9; }
    }
L9:;
    if (Null(v9)) { goto L17; }
    {
     cl_object v11;
     v11 = ecl_function_dispatch(cl_env_copy,VV[889])(1, ECL_CONS_CAR(CLV0)) /*  OPERATION-ON-WARNINGS */;
     if (!(ecl_eql(v11,VV[20]))) { goto L20; }
     value0 = (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(3, _ecl_static_69, ECL_CONS_CAR(CLV0), ECL_CONS_CAR(CLV1)) /*  WARN */;
     ecl_bds_unwind1(cl_env_copy);
     ecl_bds_unwind1(cl_env_copy);
     return value0;
L20:;
     if (!(ecl_eql(v11,ECL_SYM("ERROR",1229)))) { goto L22; }
     value0 = cl_error(5, VV[185], VV[354], ECL_CONS_CAR(CLV1), ECL_SYM("OPERATION",1280), ECL_CONS_CAR(CLV0));
     ecl_bds_unwind1(cl_env_copy);
     ecl_bds_unwind1(cl_env_copy);
     return value0;
L22:;
     if (!(ecl_eql(v11,ECL_SYM("IGNORE",1247)))) { goto L24; }
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 1;
     ecl_bds_unwind1(cl_env_copy);
     ecl_bds_unwind1(cl_env_copy);
     return value0;
L24:;
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 1;
     ecl_bds_unwind1(cl_env_copy);
     ecl_bds_unwind1(cl_env_copy);
     return value0;
    }
L17:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    ecl_bds_unwind1(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    return value0;
   }
  }
 }
}
/*	closure G907                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC230__g907(cl_narg narg, ...)
{
 cl_object T0, T1, T2, T3;
 cl_object CLV0, CLV1, CLV2, CLV3
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV3 = env0;                                     /*  OUTPUT-FILE     */
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 {
  cl_object v1flags;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1flags = cl_grab_rest_args(args);
  ecl_va_end(args);
  T0 = ecl_symbol_value(VV[26]);
  T1 = ecl_function_dispatch(cl_env_copy,VV[160])(1, ECL_CONS_CAR(CLV1)) /*  COMPONENT-EXTERNAL-FORMAT */;
  T2 = ecl_function_dispatch(cl_env_copy,VV[891])(1, ECL_CONS_CAR(CLV0)) /*  COMPILE-OP-FLAGS */;
  T3 = ecl_append(v1flags,T2);
  value0 = cl_apply(7, T0, ECL_CONS_CAR(CLV2), VV[353], ECL_CONS_CAR(CLV3), ECL_SYM("EXTERNAL-FORMAT",1236), T1, T3);
  return value0;
 }
 }
}
/*	local function G910                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC232__g910(cl_object v1operation, cl_object v2c)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3p;
   cl_object v4f;
   T0 = ecl_function_dispatch(cl_env_copy,VV[157])(1, v2c) /*  COMPONENT-PATHNAME */;
   v3p = ecl_function_dispatch(cl_env_copy,VV[130])(1, T0) /*  LISPIZE-PATHNAME */;
   v4f = (cl_env_copy->function=(ECL_SYM("COMPILE-FILE-PATHNAME",235)->symbol.gfdef))->cfun.entry(3, v3p, ECL_SYM("TYPE",1318), VV[355]) /*  COMPILE-FILE-PATHNAME */;
   if (Null(L1use_ecl_byte_compiler_p())) { goto L3; }
   value0 = ecl_list1(v4f);
   cl_env_copy->nvalues = 1;
   return value0;
L3:;
   T0 = (cl_env_copy->function=(ECL_SYM("COMPILE-FILE-PATHNAME",235)->symbol.gfdef))->cfun.entry(3, v3p, ECL_SYM("TYPE",1318), ECL_SYM("OBJECT",1278)) /*  COMPILE-FILE-PATHNAME */;
   value0 = cl_list(2, T0, v4f);
   return value0;
  }
 }
}
/*	local function G911                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC233__g911(cl_object v1operation, cl_object v2c)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G912                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC234__g912(cl_object v1operation, cl_object v2c)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G913                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC235__g913(cl_object v1operation, cl_object v2c)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G914                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC236__g914(cl_object v1operation, cl_object v2component)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_format(3, ECL_NIL, _ecl_static_70, v2component);
  return value0;
 }
}
/*	local function G915                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC237__g915(cl_object v1operation, cl_object v2component)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_format(3, ECL_NIL, _ecl_static_71, v2component);
  return value0;
 }
}
/*	local function G926                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC240__g926(cl_object volatile v1o, cl_object volatile v2c)
{
 cl_object T0, T1, T2, T3, T4;
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1, CLV2
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v2c,env0);                   /*  C               */
L1:;
  {
   volatile cl_object env1 = env0;
   CLV1 = env1 = CONS(ECL_NIL,env1);
   {
    volatile cl_object env2 = env1;
    CLV2 = env2 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env2); /*  TAGBODY */
    if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV2))) {
    if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L3;
    ecl_internal_error("GO found an inexistent tag");
    }
    {cl_object v3;
     v3 = ECL_NIL;
     v3 = ecl_make_cclosure_va((cl_objectfn)LC238__g932,env2,Cblock);
     T0 = v3;
    }
    {cl_object v3;
     v3 = ECL_NIL;
     v3 = ecl_make_cclosure_va((cl_objectfn)LC239__g933,env2,Cblock);
     T1 = v3;
    }
    T2 = ecl_function_dispatch(cl_env_copy,VV[851])(6, ECL_SYM("NAME",1273), VV[357], ECL_SYM("FUNCTION",1241), T0, VV[268], T1) /*  MAKE-RESTART */;
    T3 = ecl_list1(T2);
    T4 = CONS(T3,ecl_symbol_value(ECL_SYM("*RESTART-CLUSTERS*",4)));
    ecl_bds_bind(cl_env_copy,ECL_SYM("*RESTART-CLUSTERS*",4),T4); /*  *RESTART-CLUSTERS* */
    if (Null(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)))) { goto L7; }
    T0 = ecl_car(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
    T1 = ecl_cdr(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
    value0 = ecl_function_dispatch(cl_env_copy,T0)(2, ecl_symbol_value(ECL_SYM(".COMBINED-METHOD-ARGS.",1473)), T1);
    ecl_frs_pop(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    return value0;
L7:;
    value0 = cl_error(1, _ecl_static_36);
    ecl_frs_pop(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    return value0;
L3:;
    T0 = ecl_function_dispatch(cl_env_copy,VV[311])(4, ECL_CONS_CAR(CLV0), v1o, ECL_CONS_CAR(CLV0), VV[341]) /*  MAKE-SUB-OPERATION */;
    ecl_function_dispatch(cl_env_copy,VV[147])(2, T0, ECL_CONS_CAR(CLV0)) /*  PERFORM */;
    ecl_frs_pop(cl_env_copy);
    goto L2;
   }
  }
L2:;
  goto L1;
 }
}
/*	closure G932                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC238__g932(cl_narg narg, ...)
{
 cl_object CLV0, CLV1, CLV2
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV2 = env0;                                     /*  TAGBODY         */
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 {
  cl_object v1si__temp;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1si__temp = cl_grab_rest_args(args);
  ecl_va_end(args);
  ECL_CONS_CAR(CLV1) = v1si__temp;
  cl_go(ECL_CONS_CAR(CLV2),ecl_make_fixnum(0));
 }
 }
}
/*	closure G933                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC239__g933(cl_narg narg, cl_object v1s, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1, CLV2
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV2 = env0;
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);                           /*  C               */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[813])(1, ECL_CONS_CAR(CLV0)) /*  COMPONENT-NAME */;
  value0 = cl_format(3, v1s, _ecl_static_72, T0);
  return value0;
 }
 }
}
/*	local function G941                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC241__g941(cl_object v1o, cl_object v2c)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = (ECL_SYM("LOAD",487)->symbol.gfdef);
  {
   cl_object v3;
   cl_object v4i;
   cl_object v5;
   v3 = ecl_function_dispatch(cl_env_copy,VV[152])(2, v1o, v2c) /*  INPUT-FILES */;
   v4i = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v3))) FEtype_error_list(v3);
   v5 = v3;
   {
    cl_object v6;
    cl_object v7;
    v6 = ecl_list1(ECL_NIL);
    v7 = v6;
L9:;
    if (!(ecl_endp(v5))) { goto L11; }
    goto L10;
L11:;
    v4i = _ecl_car(v5);
    {
     cl_object v8;
     v8 = _ecl_cdr(v5);
     if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
     v5 = v8;
    }
    T2 = cl_pathname_type(1, v4i);
    if ((cl_stringE(2, T2, _ecl_static_73))!=ECL_NIL) { goto L19; }
    if (ecl_unlikely(ECL_ATOM(v7))) FEtype_error_cons(v7);
    T2 = v7;
    T3 = ecl_function_dispatch(cl_env_copy,VV[130])(1, v4i) /*  LISPIZE-PATHNAME */;
    T4 = (cl_env_copy->function=(ECL_SYM("COMPILE-FILE-PATHNAME",235)->symbol.gfdef))->cfun.entry(1, T3) /*  COMPILE-FILE-PATHNAME */;
    v7 = ecl_list1(T4);
    (ECL_CONS_CDR(T2)=v7,T2);
L19:;
    goto L9;
L10:;
    T1 = ecl_cdr(v6);
    goto L2;
   }
  }
L2:;
  value0 = cl_map(3, ECL_NIL, T0, T1);
  return value0;
 }
}
/*	local function G947                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC242__g947(cl_object v1operation, cl_object v2c)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G948                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC243__g948(cl_object v1operation, cl_object v2c)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G949                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC244__g949(cl_object v1operation, cl_object v2c)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G950                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC245__g950(cl_object v1operation, cl_object v2c)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[813])(1, v2c) /*  COMPONENT-NAME */;
  T1 = cl_list(2, VV[341], T0);
  if (Null(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)))) { goto L2; }
  T3 = ecl_car(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
  T4 = ecl_cdr(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
  T2 = ecl_function_dispatch(cl_env_copy,T3)(2, ecl_symbol_value(ECL_SYM(".COMBINED-METHOD-ARGS.",1473)), T4);
  goto L1;
L2:;
  T2 = cl_error(1, _ecl_static_36);
L1:;
  value0 = CONS(T1,T2);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G951                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC246__g951(cl_object v1operation, cl_object v2component)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_format(3, ECL_NIL, _ecl_static_74, v2component);
  return value0;
 }
}
/*	local function G952                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC247__g952(cl_object v1operation, cl_object v2component)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_format(3, ECL_NIL, _ecl_static_75, v2component);
  return value0;
 }
}
/*	local function G953                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC248__g953(cl_object v1operation, cl_object v2component)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_format(3, ECL_NIL, _ecl_static_76, v2component);
  return value0;
 }
}
/*	local function G960                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC250__g960(cl_object v1o, cl_object v2c)
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v2c,env0);                   /*  C               */
  {
   cl_object env1 = env0;
   T0 = ecl_function_dispatch(cl_env_copy,VV[157])(1, ECL_CONS_CAR(CLV0)) /*  COMPONENT-PATHNAME */;
   CLV1 = env1 = CONS(T0,env1);                   /*  SOURCE          */
   {
    cl_object v3;
    {cl_object v4;
     v4 = ECL_NIL;
     v4 = ecl_make_cclosure_va((cl_objectfn)LC249__g964,env1,Cblock);
     T0 = v4;
    }
    if (Null(ecl_function_dispatch(cl_env_copy,VV[348])(2, ECL_CONS_CAR(CLV0), T0) /*  CALL-WITH-AROUND-COMPILE-HOOK */)) { goto L3; }
    v3 = cl_get_universal_time();
    goto L1;
L3:;
    v3 = ECL_NIL;
    goto L1;
L1:;
    value0 = (cl_env_copy->function=ecl_fdefinition(VV[892]))->cfun.entry(3, v3, ECL_CONS_CAR(CLV0), VV[359]) /*  (SETF COMPONENT-PROPERTY) */;
    return value0;
   }
  }
 }
}
/*	closure G964                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC249__g964(cl_narg narg, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  SOURCE          */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=0)) FEwrong_num_arguments_anonym();
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[160])(1, ECL_CONS_CAR(CLV0)) /*  COMPONENT-EXTERNAL-FORMAT */;
  value0 = cl_load(3, ECL_CONS_CAR(CLV1), ECL_SYM("EXTERNAL-FORMAT",1236), T0);
  return value0;
 }
 }
}
/*	local function G965                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC251__g965(cl_object v1operation, cl_object v2c)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G966                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC252__g966(cl_object v1operation, cl_object v2c)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G973                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC253__g973(cl_object v1o, cl_object v2c)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3what_would_load_op_do;
   v3what_would_load_op_do = ecl_function_dispatch(cl_env_copy,VV[169])(2, VV[25], v2c) /*  COMPONENT-DEPENDS-ON */;
   {
    cl_object v4op;
    cl_object v5co;
    cl_object v6;
    v4op = ECL_NIL;
    v5co = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v3what_would_load_op_do))) FEtype_error_list(v3what_would_load_op_do);
    v6 = v3what_would_load_op_do;
    {
     cl_object v7;
     cl_object v8;
     v7 = ecl_list1(ECL_NIL);
     v8 = v7;
L8:;
     if (!(ecl_endp(v6))) { goto L10; }
     goto L9;
L10:;
     {
      cl_object v9;
      v9 = _ecl_car(v6);
      v4op = ecl_car(v9);
      v9 = ecl_cdr(v9);
      v5co = v9;
     }
     {
      cl_object v9;
      v9 = _ecl_cdr(v6);
      if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
      v6 = v9;
     }
     if (!((v4op)==(VV[25]))) { goto L23; }
     if (ecl_unlikely(ECL_ATOM(v8))) FEtype_error_cons(v8);
     T0 = v8;
     T1 = CONS(VV[358],v5co);
     v8 = ecl_list1(T1);
     (ECL_CONS_CDR(T0)=v8,T0);
L23:;
     goto L8;
L9:;
     value0 = ecl_cdr(v7);
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
  }
 }
}
/*	local function G980                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC254__g980(cl_object v1o, cl_object v2c)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[159])(2, v2c, VV[359]) /*  COMPONENT-PROPERTY */)) { goto L2; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[157])(1, v2c) /*  COMPONENT-PATHNAME */;
  T1 = ecl_function_dispatch(cl_env_copy,VV[274])(1, T0) /*  SAFE-FILE-WRITE-DATE */;
  T2 = ecl_function_dispatch(cl_env_copy,VV[159])(2, v2c, VV[359]) /*  COMPONENT-PROPERTY */;
  value0 = ecl_make_bool(ecl_number_compare(T1,T2)<=0);
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G981                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC255__g981(cl_object v1operation, cl_object v2component)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_format(3, ECL_NIL, _ecl_static_77, v2component);
  return value0;
 }
}
/*	local function G982                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC256__g982(cl_object v1operation, cl_object v2component)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_format(3, ECL_NIL, _ecl_static_78, v2component);
  return value0;
 }
}
/*	local function G983                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC257__g983(cl_object v1operation, cl_object v2c)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G984                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC258__g984(cl_object v1operation, cl_object v2c)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G985                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC259__g985(cl_object v1o, cl_object v2c)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[813])(1, v2c) /*  COMPONENT-NAME */;
  T1 = cl_list(2, VV[25], T0);
  if (Null(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)))) { goto L2; }
  T3 = ecl_car(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
  T4 = ecl_cdr(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
  T2 = ecl_function_dispatch(cl_env_copy,T3)(2, ecl_symbol_value(ECL_SYM(".COMBINED-METHOD-ARGS.",1473)), T4);
  goto L1;
L2:;
  T2 = cl_error(1, _ecl_static_36);
L1:;
  value0 = CONS(T1,T2);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for CLEANUP-UPGRADED-ASDF                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L260cleanup_upgraded_asdf(cl_object v1old_version)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2new_version;
   v2new_version = ecl_function_dispatch(cl_env_copy,VV[215])(0) /*  ASDF-VERSION */;
   if (ecl_equal(v1old_version,v2new_version)) { goto L2; }
   if (Null(ecl_function_dispatch(cl_env_copy,VV[162])(2, v2new_version, v1old_version) /*  VERSION-SATISFIES */)) { goto L5; }
   ecl_function_dispatch(cl_env_copy,VV[66])(3, _ecl_static_80, v1old_version, v2new_version) /*  ASDF-MESSAGE */;
   goto L4;
L5:;
   if (Null(ecl_function_dispatch(cl_env_copy,VV[162])(2, v1old_version, v2new_version) /*  VERSION-SATISFIES */)) { goto L7; }
   (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(3, _ecl_static_81, v1old_version, v2new_version) /*  WARN */;
   goto L4;
L7:;
   ecl_function_dispatch(cl_env_copy,VV[66])(3, _ecl_static_82, v1old_version, v2new_version) /*  ASDF-MESSAGE */;
L4:;
   {
    cl_object v3asdf;
    T0 = L2find_symbol_(VV[144], VV[1]);
    v3asdf = ecl_function_dispatch(cl_env_copy,T0)(1, VV[1]);
    cl_set(VV[232],ecl_function_dispatch(cl_env_copy,VV[230])(0) /*  MAKE-DEFINED-SYSTEMS-TABLE */);
    ecl_function_dispatch(cl_env_copy,VV[239])(1, v3asdf) /*  REGISTER-SYSTEM */;
    if (Null(ecl_symbol_value(VV[276]))) { goto L14; }
    {
     cl_object v4l;
     {
      cl_object v5;
      cl_object v6;
      cl_object v7name;
      cl_object v8;
      v5 = ecl_symbol_value(VV[276]);
      v6 = ECL_NIL;
      v7name = ECL_NIL;
      v8 = ECL_NIL;
      {
       cl_object v9;
       v9 = si_hash_table_iterator(v5);
       {
        cl_object v10;
        cl_object v11;
        v10 = ecl_list1(ECL_NIL);
        v11 = v10;
L24:;
        {
         cl_object v13;
         cl_object v14;
         cl_object v15;
         value0 = ecl_function_dispatch(cl_env_copy,v9)(0);
         v13 = value0;
         {
          const int v16 = cl_env_copy->nvalues;
          cl_object v17;
          v17 = (v16<=1)? ECL_NIL : cl_env_copy->values[1];
          v14 = v17;
          v17 = (v16<=2)? ECL_NIL : cl_env_copy->values[2];
          v15 = v17;
         }
         if (Null(v13)) { goto L29; }
         v8 = v15;
         v7name = v14;
L29:;
         v6 = v13;
         if ((v6)!=ECL_NIL) { goto L26; }
        }
        goto L25;
L26:;
        if (ecl_unlikely(ECL_ATOM(v11))) FEtype_error_cons(v11);
        T0 = v11;
        v11 = ecl_list1(v7name);
        (ECL_CONS_CDR(T0)=v11,T0);
        goto L24;
L25:;
        v4l = ecl_cdr(v10);
        goto L16;
       }
      }
     }
L16:;
     cl_clrhash(ecl_symbol_value(VV[276]));
     {
      cl_object v5;
      v5 = v4l;
      goto L45;
L44:;
      {
       cl_object v6s;
       v6s = ecl_car(v5);
       ecl_function_dispatch(cl_env_copy,VV[144])(2, v6s, ECL_NIL) /*  FIND-SYSTEM */;
      }
      v5 = ecl_cdr(v5);
L45:;
      if (Null(v5)) { goto L52; }
      goto L44;
L52:;
     }
    }
L14:;
    value0 = ECL_T;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L2:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for UPGRADE-ASDF                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L261upgrade_asdf()
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v1version;
   v1version = ecl_function_dispatch(cl_env_copy,VV[215])(0) /*  ASDF-VERSION */;
   T0 = (ECL_SYM("MUFFLE-WARNING",571)->symbol.gfdef);
   T1 = CONS(VV[367],T0);
   T2 = ecl_list1(T1);
   T3 = CONS(T2,ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5)));
   ecl_bds_bind(cl_env_copy,ECL_SYM("*HANDLER-CLUSTERS*",5),T3); /*  *HANDLER-CLUSTERS* */
   ecl_function_dispatch(cl_env_copy,VV[361])(4, VV[25], VV[1], ECL_SYM("VERBOSE",1325), ECL_NIL) /*  OPERATE */;
   ecl_bds_unwind1(cl_env_copy);
   value0 = ecl_function_dispatch(cl_env_copy,VV[364])(1, v1version) /*  CLEANUP-UPGRADED-ASDF */;
   return value0;
  }
 }
}
/*	local function G1006                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC262__g1006(cl_object v1plan, cl_object v2component_path)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   {
    cl_object v5;
    cl_object v6;
    v5 = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v1plan))) FEtype_error_list(v1plan);
    v6 = v1plan;
    {
     cl_object v7;
     cl_object v8;
     v7 = ecl_list1(ECL_NIL);
     v8 = v7;
L7:;
     if (!(ecl_endp(v6))) { goto L9; }
     goto L8;
L9:;
     v5 = _ecl_car(v6);
     {
      cl_object v9;
      v9 = _ecl_cdr(v6);
      if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
      v6 = v9;
     }
     if (ecl_unlikely(ECL_ATOM(v8))) FEtype_error_cons(v8);
     T0 = v8;
     T1 = ecl_function_dispatch(cl_env_copy,ECL_SYM("CDR",198))(1, v5);
     v8 = ecl_list1(T1);
     (ECL_CONS_CDR(T0)=v8,T0);
     goto L7;
L8:;
     v3 = ecl_cdr(v7);
     goto L1;
    }
   }
L1:;
   v4 = si_make_seq_iterator(2, v3, ecl_make_fixnum(0));
L25:;
   if ((v4)!=ECL_NIL) { goto L27; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L27:;
   {
    cl_object v5;
    v5 = si_seq_iterator_ref(v3, v4);
    T0 = ecl_function_dispatch(cl_env_copy,VV[189])(1, v5);
    if (Null(ecl_function_dispatch(cl_env_copy,ECL_SYM("EQUAL",335))(2, v2component_path, T0))) { goto L29; }
    value0 = v5;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L29:;
   v4 = si_seq_iterator_next(v3, v4);
   goto L25;
  }
 }
}
/*	local function G1023                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC263__g1023(cl_narg narg, cl_object v1steps, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  ecl_va_list args; ecl_va_start(args,v1steps,narg,1);
  cl_parse_key(args,0,NULL,NULL,NULL,TRUE);
  ecl_va_end(args);
  {
   cl_object v2;
   cl_object v3;
   v2 = ecl_symbol_value(ECL_SYM("*PACKAGE*",43));
   v3 = ecl_symbol_value(ECL_SYM("*READTABLE*",65));
   ecl_bds_bind(cl_env_copy,ECL_SYM("*PACKAGE*",43),v2); /*  *PACKAGE* */
   ecl_bds_bind(cl_env_copy,ECL_SYM("*READTABLE*",65),v3); /*  *READTABLE* */
   {
    cl_object v4op;
    cl_object v5component;
    cl_object v6;
    v4op = ECL_NIL;
    v5component = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v1steps))) FEtype_error_list(v1steps);
    v6 = v1steps;
L7:;
    if (!(ecl_endp(v6))) { goto L9; }
    goto L8;
L9:;
    {
     cl_object v7;
     v7 = _ecl_car(v6);
     v4op = ecl_car(v7);
     v7 = ecl_cdr(v7);
     v5component = v7;
    }
    {
     cl_object v7;
     v7 = _ecl_cdr(v6);
     if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
     v6 = v7;
    }
    ecl_function_dispatch(cl_env_copy,VV[146])(2, v4op, v5component) /*  PERFORM-WITH-RESTARTS */;
    goto L7;
L8:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    ecl_bds_unwind1(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    return value0;
   }
  }
 }
}
/*	local function G1036                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC266__g1036(volatile cl_narg narg, cl_object volatile v1operation_class, cl_object volatile v2system, ...)
{
 cl_object T0;
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1, CLV2, CLV3, CLV4, CLV5
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  volatile cl_object v3args;
  volatile cl_object v4force;
  volatile cl_object v5force_not;
  ecl_va_list args; ecl_va_start(args,v2system,narg,2);
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1operation_class,env0);     /*  OPERATION-CLASS */
  CLV1 = env0 = CONS(v2system,env0);              /*  SYSTEM          */
  {
   cl_object keyvars[8];
   cl_parse_key(args,4,LC266__g1036keys,keyvars,(cl_object*)&v3args,TRUE);
   CLV2 = env0 = CONS(v3args,env0);               /*  ARGS            */
   ecl_va_end(args);
   v4force = keyvars[0];
   v5force_not = keyvars[1];
   CLV3 = env0 = CONS(keyvars[2],env0);           /*  VERBOSE         */
   CLV4 = env0 = CONS(keyvars[3],env0);           /*  VERSION         */
  }
  {
   CLV5 = env0 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env0); /*  OPERATE */
   if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV5))!=0) {
   value0 = cl_env_copy->values[0];
   ecl_frs_pop(cl_env_copy);
   return value0;
   } else {
   {cl_object v6;
    v6 = ECL_NIL;
    v6 = ecl_make_cclosure_va((cl_objectfn)LC265__g1037,env0,Cblock);
    T0 = v6;
   }
   value0 = ecl_function_dispatch(cl_env_copy,VV[279])(1, T0) /*  CALL-WITH-SYSTEM-DEFINITIONS */;
   ecl_frs_pop(cl_env_copy);
   return value0;}
  }
 }
}
/*	closure G1037                                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC265__g1037(cl_narg narg, ...)
{
 cl_object T0;
 volatile struct ecl_cclosure aux_closure;
 cl_object CLV0, CLV1, CLV2, CLV3, CLV4, CLV5, CLV6
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV5 = env0;                                     /*  OPERATE         */
 CLV4 = _ecl_cdr(CLV5);
 CLV3 = _ecl_cdr(CLV4);
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=0)) FEwrong_num_arguments_anonym();
 {
TTL:
  {
   cl_object v1op;
   cl_object v2systems_being_operated;
   cl_object env1 = env0;
   ecl_bds_bind(cl_env_copy,VV[7],ECL_CONS_CAR(CLV3)); /*  *ASDF-VERBOSE* */
   if (Null(ECL_CONS_CAR(CLV3))) { goto L2; }
   T0 = ecl_symbol_value(ECL_SYM("*STANDARD-OUTPUT*",67));
   goto L1;
L2:;
   T0 = cl_make_broadcast_stream(0);
L1:;
   ecl_bds_bind(cl_env_copy,VV[22],T0);           /*  *VERBOSE-OUT*   */
   v1op = cl_apply(5, ECL_SYM("MAKE-INSTANCE",949), ECL_CONS_CAR(CLV0), VV[314], ECL_CONS_CAR(CLV2), ECL_CONS_CAR(CLV2));
   if (Null(si_of_class_p(2, ECL_CONS_CAR(CLV1), VV[213]))) { goto L6; }
   T0 = ECL_CONS_CAR(CLV1);
   goto L5;
L6:;
   if (ECL_STRINGP(ECL_CONS_CAR(CLV1))) { goto L10; }
   if (!(ECL_SYMBOLP(ECL_CONS_CAR(CLV1)))) { goto L8; }
   goto L9;
L10:;
L9:;
   T0 = ecl_function_dispatch(cl_env_copy,VV[144])(1, ECL_CONS_CAR(CLV1)) /*  FIND-SYSTEM */;
   goto L5;
L8:;
   T0 = si_etypecase_error(ECL_CONS_CAR(CLV1), VV[369]);
L5:;
   CLV6 = env1 = CONS(T0,env1);                   /*  SYSTEM          */
   v2systems_being_operated = ecl_symbol_value(VV[277]);
   value0 = v2systems_being_operated;
   if ((value0)!=ECL_NIL) { goto L15; }
   T0 = cl_make_hash_table(2, ECL_SYM("TEST",1316), ECL_SYM("EQUAL",335));
   goto L13;
L15:;
   T0 = value0;
   goto L13;
L13:;
   ecl_bds_bind(cl_env_copy,VV[277],T0);          /*  *SYSTEMS-BEING-OPERATED* */
   {
    cl_object v3;
    v3 = ECL_CONS_CAR(CLV6);
    if ((si_of_class_p(2, v3, VV[213]))!=ECL_NIL) { goto L19; }
    ECL_CONS_CAR(CLV6) = si_do_check_type(v3, VV[213], ECL_NIL, VV[213]);
L19:;
   }
   T0 = ecl_function_dispatch(cl_env_copy,VV[233])(1, ECL_CONS_CAR(CLV6)) /*  COERCE-NAME */;
   si_hash_set(T0, ecl_symbol_value(VV[277]), ECL_CONS_CAR(CLV6));
   if (Null(v2systems_being_operated)) { goto L23; }
   (aux_closure.env=env1,cl_env_copy->function=(cl_object)&aux_closure,LC264upgrade(0));
L23:;
   if ((ecl_function_dispatch(cl_env_copy,VV[162])(2, ECL_CONS_CAR(CLV6), ECL_CONS_CAR(CLV4)) /*  VERSION-SATISFIES */)!=ECL_NIL) { goto L25; }
   cl_error(5, VV[179], VV[290], ECL_CONS_CAR(CLV6), ECL_SYM("VERSION",1326), ECL_CONS_CAR(CLV4));
L25:;
   {
    cl_object v3plan;
    v3plan = ecl_function_dispatch(cl_env_copy,VV[171])(2, v1op, ECL_CONS_CAR(CLV6)) /*  TRAVERSE */;
    if (Null(ecl_function_dispatch(cl_env_copy,VV[363])(2, v3plan, VV[370]) /*  PLAN-OPERATES-ON-P */)) { goto L28; }
    (aux_closure.env=env1,cl_env_copy->function=(cl_object)&aux_closure,LC264upgrade(0));
L28:;
    ecl_function_dispatch(cl_env_copy,VV[362])(1, v3plan) /*  PERFORM-PLAN */;
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = v3plan;
    cl_env_copy->values[0] = v1op;
    ecl_bds_unwind1(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    return cl_env_copy->values[0];
   }
  }
 }
 }
}
/*	closure UPGRADE                                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC264upgrade(cl_narg narg, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1, CLV2, CLV3, CLV4, CLV5, CLV6
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV6 = env0;                                     /*  SYSTEM          */
 CLV5 = _ecl_cdr(CLV6);
 CLV4 = _ecl_cdr(CLV5);
 CLV3 = _ecl_cdr(CLV4);
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=0)) FEwrong_num_arguments_anonym();
 {
TTL:
  if ((ecl_gethash_safe(_ecl_static_58,ecl_symbol_value(VV[277]),ECL_NIL))!=ECL_NIL) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[366])(0)   /*  UPGRADE-ASDF    */;
  T0 = L2find_symbol_(VV[361], VV[1]);
  cl_env_copy->values[0] = cl_apply(4, T0, ECL_CONS_CAR(CLV0), ECL_CONS_CAR(CLV6), ECL_CONS_CAR(CLV2));
  cl_return_from(ECL_CONS_CAR(CLV5),ECL_NIL);
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
 }
}
/*	function definition for OOS                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L267oos(cl_narg narg, cl_object v1operation_class, cl_object v2system, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3args;
  cl_object v4force;
  cl_object v5force_not;
  cl_object v6verbose;
  cl_object v7version;
  ecl_va_list args; ecl_va_start(args,v2system,narg,2);
  {
   cl_object keyvars[8];
   cl_parse_key(args,4,L267ooskeys,keyvars,(cl_object*)&v3args,TRUE);
   ecl_va_end(args);
   v4force = keyvars[0];
   v5force_not = keyvars[1];
   v6verbose = keyvars[2];
   v7version = keyvars[3];
  }
  value0 = cl_apply(4, VV[361], v1operation_class, v2system, v3args);
  return value0;
 }
}
/*	function definition for LOAD-SYSTEM                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L268load_system(cl_narg narg, cl_object v1system, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2keys;
  cl_object v3force;
  cl_object v4verbose;
  cl_object v5version;
  ecl_va_list args; ecl_va_start(args,v1system,narg,1);
  {
   cl_object keyvars[6];
   cl_parse_key(args,3,L268load_systemkeys,keyvars,(cl_object*)&v2keys,TRUE);
   ecl_va_end(args);
   v3force = keyvars[0];
   v4verbose = keyvars[1];
   v5version = keyvars[2];
  }
  cl_apply(4, VV[361], ecl_symbol_value(VV[24]), v1system, v2keys);
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for LOAD-SYSTEMS                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L269load_systems(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1systems;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1systems = cl_grab_rest_args(args);
  ecl_va_end(args);
  value0 = cl_map(3, ECL_NIL, VV[373], v1systems);
  return value0;
 }
}
/*	function definition for COMPONENT-LOADED-P                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L270component_loaded_p(cl_object v1c)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[163])(2, v1c, ECL_NIL) /*  FIND-COMPONENT */;
  T1 = ecl_function_dispatch(cl_env_copy,VV[872])(1, T0) /*  COMPONENT-OPERATION-TIMES */;
  if (Null(ecl_gethash_safe(VV[25],T1,ECL_NIL))) { goto L2; }
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for LOADED-SYSTEMS                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L271loaded_systems()
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[237])(0) /*  REGISTERED-SYSTEMS */;
  value0 = cl_remove_if_not(2, VV[377], T0);
  return value0;
 }
}
/*	function definition for REQUIRE-SYSTEM                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L272require_system(cl_narg narg, cl_object v1s, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2keys;
  ecl_va_list args; ecl_va_start(args,v1s,narg,1);
  cl_parse_key(args,0,NULL,NULL,(cl_object*)&v2keys,TRUE);
  ecl_va_end(args);
  T0 = L271loaded_systems();
  value0 = cl_apply(5, VV[373], v1s, VV[379], T0, v2keys);
  return value0;
 }
}
/*	function definition for COMPILE-SYSTEM                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L273compile_system(cl_narg narg, cl_object v1system, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2args;
  cl_object v3force;
  cl_object v4verbose;
  cl_object v5version;
  ecl_va_list args; ecl_va_start(args,v1system,narg,1);
  {
   cl_object keyvars[6];
   cl_parse_key(args,3,L273compile_systemkeys,keyvars,(cl_object*)&v2args,TRUE);
   ecl_va_end(args);
   v3force = keyvars[0];
   v4verbose = keyvars[1];
   v5version = keyvars[2];
  }
  cl_apply(4, VV[361], VV[341], v1system, v2args);
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for TEST-SYSTEM                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L274test_system(cl_narg narg, cl_object v1system, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2args;
  cl_object v3force;
  cl_object v4verbose;
  cl_object v5version;
  ecl_va_list args; ecl_va_start(args,v1system,narg,1);
  {
   cl_object keyvars[6];
   cl_parse_key(args,3,L274test_systemkeys,keyvars,(cl_object*)&v2args,TRUE);
   ecl_va_end(args);
   v3force = keyvars[0];
   v4verbose = keyvars[1];
   v5version = keyvars[2];
  }
  cl_apply(4, VV[361], VV[360], v1system, v2args);
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for LOAD-PATHNAME                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L275load_pathname()
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_symbol_value(ECL_SYM("*LOAD-PATHNAME*",36));
  if ((value0)!=ECL_NIL) { goto L3; }
  T0 = ecl_symbol_value(ECL_SYM("*COMPILE-FILE-PATHNAME*",26));
  goto L1;
L3:;
  T0 = value0;
  goto L1;
L1:;
  value0 = ecl_function_dispatch(cl_env_copy,VV[123])(1, T0) /*  RESOLVE-SYMLINKS* */;
  return value0;
 }
}
/*	function definition for DETERMINE-SYSTEM-PATHNAME             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L276determine_system_pathname(cl_object v1pathname)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2file_pathname;
   cl_object v3directory_pathname;
   v2file_pathname = ecl_function_dispatch(cl_env_copy,VV[385])(0) /*  LOAD-PATHNAME */;
   if (Null(v2file_pathname)) { goto L4; }
   v3directory_pathname = ecl_function_dispatch(cl_env_copy,VV[36])(1, v2file_pathname) /*  PATHNAME-DIRECTORY-PATHNAME */;
   goto L2;
L4:;
   v3directory_pathname = ECL_NIL;
   goto L2;
L2:;
   if (Null(v1pathname)) { goto L10; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[102])(4, v3directory_pathname, v1pathname, ECL_SYM("TYPE",1318), ECL_SYM("DIRECTORY",1219)) /*  SUBPATHNAME */;
   goto L8;
L10:;
   value0 = ECL_NIL;
   goto L8;
L8:;
   if ((value0)!=ECL_NIL) { goto L7; }
   value0 = v3directory_pathname;
   if ((value0)!=ECL_NIL) { goto L7; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[128])(0) /*  DEFAULT-DIRECTORY */;
   return value0;
L7:;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for FIND-CLASS*                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L277find_class_(cl_narg narg, cl_object v1x, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v2errorp;
  cl_object v3environment;
  va_list args; va_start(args,v1x);
  {
   int i = 1;
   if (i >= narg) {
    v2errorp = ECL_T;
   } else {
    i++;
    v2errorp = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v3environment = ECL_NIL;
   } else {
    i++;
    v3environment = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if ((si_of_class_p(2, v1x, ECL_SYM("STANDARD-CLASS",973)))!=ECL_NIL) { goto L5; }
  if (Null(si_of_class_p(2, v1x, ECL_SYM("BUILT-IN-CLASS",929)))) { goto L3; }
  goto L4;
L5:;
L4:;
  value0 = v1x;
  cl_env_copy->nvalues = 1;
  return value0;
L3:;
  if (!(ECL_SYMBOLP(v1x))) { goto L7; }
  value0 = cl_find_class(3, v1x, v2errorp, v3environment);
  return value0;
L7:;
  value0 = si_etypecase_error(v1x, VV[390]);
  return value0;
 }
}
/*	function definition for CLASS-FOR-TYPE                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L278class_for_type(cl_object v1parent, cl_object v2type)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4symbol;
   cl_object v5;
   T0 = L2find_symbol_(v2type, ecl_symbol_value(ECL_SYM("*PACKAGE*",43)));
   T1 = L2find_symbol_(v2type, VV[1]);
   v3 = cl_list(3, v2type, T0, T1);
   v4symbol = ECL_NIL;
   v5 = v3;
   {
    cl_object v6class;
    v6class = ECL_NIL;
L8:;
    if (!(ecl_endp(v5))) { goto L10; }
    goto L9;
L10:;
    v4symbol = _ecl_car(v5);
    {
     cl_object v7;
     v7 = _ecl_cdr(v5);
     if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
     v5 = v7;
    }
    if (Null(v4symbol)) { goto L21; }
    v6class = cl_find_class(2, v4symbol, ECL_NIL);
    goto L19;
L21:;
    v6class = ECL_NIL;
    goto L19;
L19:;
    if (Null(v6class)) { goto L23; }
    T0 = cl_find_class(1, VV[11]);
    if (Null(cl_subtypep(2, v6class, T0))) { goto L23; }
    value0 = v6class;
    goto L3;
L23:;
    goto L8;
L9:;
    value0 = ECL_NIL;
   }
  }
L3:;
  if ((value0)!=ECL_NIL) { goto L2; }
  if (!((v2type)==(ECL_SYM("FILE",1237)))) { goto L29; }
  {
   cl_object v3module;
   v3module = ECL_NIL;
   {
    cl_object v4;
    v4 = ECL_NIL;
    v3module = v1parent;
L37:;
    if ((v3module)!=ECL_NIL) { goto L41; }
    goto L38;
L41:;
    v4 = ecl_function_dispatch(cl_env_copy,VV[915])(1, v3module) /*  MODULE-DEFAULT-COMPONENT-CLASS */;
    if (Null(v4)) { goto L43; }
    value0 = v4;
    goto L34;
L43:;
    v3module = ecl_function_dispatch(cl_env_copy,VV[814])(1, v3module) /*  COMPONENT-PARENT */;
    goto L37;
L38:;
    value0 = ECL_NIL;
   }
  }
L34:;
  if ((value0)!=ECL_NIL) { goto L33; }
  T0 = ecl_symbol_value(VV[193]);
  goto L31;
L33:;
  T0 = value0;
  goto L31;
L31:;
  value0 = ecl_function_dispatch(cl_env_copy,VV[389])(2, T0, ECL_NIL) /*  FIND-CLASS* */;
  goto L27;
L29:;
  value0 = ECL_NIL;
  goto L27;
L27:;
  if ((value0)!=ECL_NIL) { goto L2; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[191])(2, _ecl_static_85, v2type) /*  SYSDEF-ERROR */;
  return value0;
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for MAYBE-ADD-TREE                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L279maybe_add_tree(cl_object v1tree, cl_object v2op1, cl_object v3op2, cl_object v4c)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v5first_op_tree;
   v5first_op_tree = ecl_assql(v2op1,v1tree);
   if (Null(v5first_op_tree)) { goto L2; }
   {
    cl_object v6it;
    T0 = ecl_cdr(v5first_op_tree);
    v6it = ecl_assql(v3op2,T0);
    if (Null(v6it)) { goto L6; }
    {
     cl_object v7;
     cl_object v8;
     v7 = ecl_cdr(v6it);
     v8 = si_make_seq_iterator(2, v7, ecl_make_fixnum(0));
L11:;
     if ((v8)!=ECL_NIL) { goto L13; }
     goto L8;
L13:;
     {
      cl_object v9;
      v9 = si_seq_iterator_ref(v7, v8);
      if (!(ecl_equal(v4c,v9))) { goto L15; }
      if ((v9)!=ECL_NIL) { goto L4; }
      goto L8;
     }
L15:;
     v8 = si_seq_iterator_next(v7, v8);
     goto L11;
    }
L8:;
    {
     cl_object v7;
     T0 = ecl_cdr(v6it);
     v7 = CONS(v4c,T0);
     if (ecl_unlikely(ECL_ATOM(v6it))) FEtype_error_cons(v6it);
     T0 = v6it;
     (ECL_CONS_CDR(T0)=v7,T0);
     goto L4;
    }
L6:;
    {
     cl_object v8;
     T0 = ecl_list1(v4c);
     T1 = ecl_cdr(v5first_op_tree);
     v8 = cl_acons(v3op2, T0, T1);
     if (ecl_unlikely(ECL_ATOM(v5first_op_tree))) FEtype_error_cons(v5first_op_tree);
     T0 = v5first_op_tree;
     (ECL_CONS_CDR(T0)=v8,T0);
    }
   }
L4:;
   value0 = v1tree;
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
   T0 = cl_list(2, v3op2, v4c);
   T1 = ecl_list1(T0);
   value0 = cl_acons(v2op1, T1, v1tree);
   return value0;
  }
 }
}
/*	function definition for UNION-OF-DEPENDENCIES                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L280union_of_dependencies(cl_narg narg, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1deps;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1deps = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v2new_tree;
   v2new_tree = ECL_NIL;
   {
    cl_object v3;
    v3 = v1deps;
    goto L6;
L5:;
    {
     cl_object v4dep;
     v4dep = ecl_car(v3);
     {
      cl_object v5;
      v5 = v4dep;
      goto L14;
L13:;
      {
       cl_object v6op_tree;
       v6op_tree = ecl_car(v5);
       {
        cl_object v7;
        v7 = ecl_cdr(v6op_tree);
        goto L22;
L21:;
        {
         cl_object v8op;
         v8op = ecl_car(v7);
         {
          cl_object v9;
          v9 = ecl_cdr(v8op);
          goto L30;
L29:;
          {
          cl_object v10c;
          v10c = ecl_car(v9);
          T0 = ecl_car(v6op_tree);
          T1 = ecl_car(v8op);
          v2new_tree = ecl_function_dispatch(cl_env_copy,VV[394])(4, v2new_tree, T0, T1, v10c) /*  MAYBE-ADD-TREE */;
          }
          v9 = ecl_cdr(v9);
L30:;
          if (Null(v9)) { goto L38; }
          goto L29;
L38:;
         }
        }
        v7 = ecl_cdr(v7);
L22:;
        if (Null(v7)) { goto L42; }
        goto L21;
L42:;
       }
      }
      v5 = ecl_cdr(v5);
L14:;
      if (Null(v5)) { goto L46; }
      goto L13;
L46:;
     }
    }
    v3 = ecl_cdr(v3);
L6:;
    if (Null(v3)) { goto L50; }
    goto L5;
L50:;
   }
   value0 = v2new_tree;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for SYSDEF-ERROR-COMPONENT                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L281sysdef_error_component(cl_object v1msg, cl_object v2type, cl_object v3name, cl_object v4value)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = L3strcat(2, v1msg, _ecl_static_86);
  value0 = ecl_function_dispatch(cl_env_copy,VV[191])(4, T0, v2type, v3name, v4value) /*  SYSDEF-ERROR */;
  return value0;
 }
}
/*	function definition for CHECK-COMPONENT-INPUT                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L282check_component_input(cl_object v1type, cl_object v2name, cl_object v3weakly_depends_on, cl_object v4depends_on, cl_object v5components, cl_object v6in_order_to)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (ECL_LISTP(v4depends_on)) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[399])(4, _ecl_static_87, v1type, v2name, v4depends_on) /*  SYSDEF-ERROR-COMPONENT */;
L1:;
  if (ECL_LISTP(v3weakly_depends_on)) { goto L3; }
  ecl_function_dispatch(cl_env_copy,VV[399])(4, _ecl_static_88, v1type, v2name, v3weakly_depends_on) /*  SYSDEF-ERROR-COMPONENT */;
L3:;
  if (ECL_LISTP(v5components)) { goto L5; }
  ecl_function_dispatch(cl_env_copy,VV[399])(4, _ecl_static_89, v1type, v2name, v5components) /*  SYSDEF-ERROR-COMPONENT */;
L5:;
  if (!(ECL_LISTP(v6in_order_to))) { goto L10; }
  T0 = ecl_car(v6in_order_to);
  if (ECL_LISTP(T0)) { goto L7; }
  goto L8;
L10:;
  goto L8;
L8:;
  value0 = ecl_function_dispatch(cl_env_copy,VV[399])(4, _ecl_static_90, v1type, v2name, v6in_order_to) /*  SYSDEF-ERROR-COMPONENT */;
  return value0;
L7:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for %REMOVE-COMPONENT-INLINE-METHODS      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L284_remove_component_inline_methods(cl_object v1component)
{
 cl_object T0, T1;
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   v2 = ecl_symbol_value(VV[23]);
   goto L5;
L4:;
   {
    cl_object env1 = env0;
    T0 = ecl_car(v2);
    env1 = ECL_NIL;
    CLV0 = env1 = CONS(T0,env1);                  /*  NAME            */
    {cl_object v3;
     v3 = ECL_NIL;
     v3 = ecl_make_cclosure_va((cl_objectfn)LC283__g1085,env1,Cblock);
     T0 = v3;
    }
    T1 = ecl_function_dispatch(cl_env_copy,VV[921])(1, v1component) /*  COMPONENT-INLINE-METHODS */;
    cl_map(3, ECL_NIL, T0, T1);
   }
   v2 = ecl_cdr(v2);
L5:;
   if (Null(v2)) { goto L12; }
   goto L4;
L12:;
  }
  value0 = (cl_env_copy->function=ecl_fdefinition(VV[922]))->cfun.entry(2, ECL_NIL, v1component) /*  (SETF COMPONENT-INLINE-METHODS) */;
  return value0;
 }
}
/*	closure G1085                                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC283__g1085(cl_narg narg, cl_object v1m, ...)
{
 cl_object T0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  NAME            */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  T0 = cl_symbol_function(ECL_CONS_CAR(CLV0));
  value0 = (cl_env_copy->function=(ECL_SYM("REMOVE-METHOD",964)->symbol.gfdef))->cfun.entry(2, T0, v1m) /*  REMOVE-METHOD */;
  return value0;
 }
 }
}
/*	function definition for %DEFINE-COMPONENT-INLINE-METHODS      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L285_define_component_inline_methods(cl_object v1ret, cl_object v2rest)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_symbol_value(VV[23]);
   goto L4;
L3:;
   {
    cl_object v4name;
    v4name = ecl_car(v3);
    {
     cl_object v5keyword;
     T0 = ecl_symbol_name(v4name);
     v5keyword = cl_intern(2, T0, VV[406]);
     {
      cl_object v6data;
      v6data = ECL_NIL;
      {
       cl_object v7key;
       v7key = ECL_NIL;
       {
        cl_object v8value;
        v8value = ECL_NIL;
        v6data = v2rest;
L13:;
        v7key = ecl_car(v6data);
        v8value = ecl_cadr(v6data);
        if ((v6data)!=ECL_NIL) { goto L21; }
        goto L14;
L21:;
        if (!((v7key)==(v5keyword))) { goto L23; }
        {
         cl_object v9;
         cl_object v10op;
         cl_object v11qual;
         cl_object v12;
         cl_object v13;
         cl_object v14o;
         cl_object v15c;
         v9 = v8value;
         if (!(v9==ECL_NIL)) { goto L27; }
         si_dm_too_few_arguments(v8value);
L27:;
         {
          cl_object v16;
          v16 = ecl_car(v9);
          v9 = ecl_cdr(v9);
          v10op = v16;
         }
         if (!(v9==ECL_NIL)) { goto L33; }
         si_dm_too_few_arguments(v8value);
L33:;
         {
          cl_object v16;
          v16 = ecl_car(v9);
          v9 = ecl_cdr(v9);
          v11qual = v16;
         }
         if (!(v9==ECL_NIL)) { goto L39; }
         si_dm_too_few_arguments(v8value);
L39:;
         {
          cl_object v16;
          v16 = ecl_car(v9);
          v9 = ecl_cdr(v9);
          v12 = v16;
         }
         v13 = v12;
         if (!(v13==ECL_NIL)) { goto L46; }
         si_dm_too_few_arguments(v8value);
L46:;
         {
          cl_object v16;
          v16 = ecl_car(v13);
          v13 = ecl_cdr(v13);
          v14o = v16;
         }
         if (!(v13==ECL_NIL)) { goto L52; }
         si_dm_too_few_arguments(v8value);
L52:;
         {
          cl_object v16;
          v16 = ecl_car(v13);
          v13 = ecl_cdr(v13);
          v15c = v16;
         }
         if (Null(v13)) { goto L57; }
         si_dm_too_many_arguments(v8value);
L57:;
         {
          cl_object v16;
          cl_object v17;
          T0 = cl_list(2, v14o, v10op);
          T1 = cl_list(2, ECL_SYM("EQL",334), v1ret);
          T2 = cl_list(2, v15c, T1);
          T3 = cl_list(2, T0, T2);
          T4 = cl_listX(5, ECL_SYM("DEFMETHOD",940), v4name, v11qual, T3, v9);
          v16 = cl_eval(T4);
          T0 = ecl_function_dispatch(cl_env_copy,VV[921])(1, v1ret) /*  COMPONENT-INLINE-METHODS */;
          v17 = cl_adjoin(2, v16, T0);
          (cl_env_copy->function=ecl_fdefinition(VV[922]))->cfun.entry(2, v17, v1ret) /*  (SETF COMPONENT-INLINE-METHODS) */;
         }
        }
L23:;
        v6data = ecl_cddr(v6data);
        goto L13;
L14:;
       }
      }
     }
    }
   }
   v3 = ecl_cdr(v3);
L4:;
   if (Null(v3)) { goto L66; }
   goto L3;
L66:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for %REFRESH-COMPONENT-INLINE-METHODS     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L286_refresh_component_inline_methods(cl_object v1component, cl_object v2rest)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_function_dispatch(cl_env_copy,VV[403])(1, v1component) /*  %REMOVE-COMPONENT-INLINE-METHODS */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[405])(2, v1component, v2rest) /*  %DEFINE-COMPONENT-INLINE-METHODS */;
  return value0;
 }
}
/*	function definition for PARSE-COMPONENT-FORM                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L288parse_component_form(cl_object v1parent, cl_object v2options)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4type;
   cl_object v5name;
   cl_object v6;
   cl_object v7components;
   cl_object v8;
   cl_object v9pathname;
   cl_object v10;
   cl_object v11;
   cl_object v12;
   cl_object v13;
   cl_object v14;
   cl_object v15weakly_depends_on;
   cl_object v16;
   cl_object v17depends_on;
   cl_object v18;
   cl_object v19serial;
   cl_object v20;
   cl_object v21in_order_to;
   cl_object v22;
   cl_object v23do_first;
   cl_object v24;
   cl_object v25version;
   cl_object v26versionp;
   v3 = v2options;
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v2options);
L3:;
   {
    cl_object v27;
    v27 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4type = v27;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v2options);
L9:;
   {
    cl_object v27;
    v27 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5name = v27;
   }
   v6 = si_search_keyword(2, v3, VV[334]);
   if (!((v6)==(ECL_SYM("MISSING-KEYWORD",1929)))) { goto L16; }
   v7components = ECL_NIL;
   goto L15;
L16:;
   v7components = v6;
L15:;
   v8 = si_search_keyword(2, v3, ECL_SYM("PATHNAME",1285));
   if (!((v8)==(ECL_SYM("MISSING-KEYWORD",1929)))) { goto L20; }
   v9pathname = ECL_NIL;
   goto L19;
L20:;
   v9pathname = v8;
L19:;
   v10 = si_search_keyword(2, v3, VV[411]);
   v11 = si_search_keyword(2, v3, VV[412]);
   v12 = si_search_keyword(2, v3, VV[413]);
   v13 = si_search_keyword(2, v3, VV[414]);
   v14 = si_search_keyword(2, v3, VV[415]);
   if (!((v14)==(ECL_SYM("MISSING-KEYWORD",1929)))) { goto L28; }
   v15weakly_depends_on = ECL_NIL;
   goto L27;
L28:;
   v15weakly_depends_on = v14;
L27:;
   v16 = si_search_keyword(2, v3, VV[416]);
   if (!((v16)==(ECL_SYM("MISSING-KEYWORD",1929)))) { goto L32; }
   v17depends_on = ECL_NIL;
   goto L31;
L32:;
   v17depends_on = v16;
L31:;
   v18 = si_search_keyword(2, v3, VV[417]);
   if (!((v18)==(ECL_SYM("MISSING-KEYWORD",1929)))) { goto L36; }
   v19serial = ECL_NIL;
   goto L35;
L36:;
   v19serial = v18;
L35:;
   v20 = si_search_keyword(2, v3, VV[418]);
   if (!((v20)==(ECL_SYM("MISSING-KEYWORD",1929)))) { goto L40; }
   v21in_order_to = ECL_NIL;
   goto L39;
L40:;
   v21in_order_to = v20;
L39:;
   v22 = si_search_keyword(2, v3, VV[419]);
   if (!((v22)==(ECL_SYM("MISSING-KEYWORD",1929)))) { goto L44; }
   v23do_first = ECL_NIL;
   goto L43;
L44:;
   v23do_first = v22;
L43:;
   v24 = si_search_keyword(2, v3, ECL_SYM("VERSION",1326));
   if (!((v24)==(ECL_SYM("MISSING-KEYWORD",1929)))) { goto L48; }
   v25version = ECL_NIL;
   goto L47;
L48:;
   v25version = v24;
L47:;
   {
    bool v27;
    v27 = (v24)==(ECL_SYM("MISSING-KEYWORD",1929));
    v26versionp = (v27)?ECL_NIL:ECL_T;
   }
   si_check_keyword(3, v3, VV[420], ECL_T);
   ecl_function_dispatch(cl_env_copy,VV[401])(6, v4type, v5name, v15weakly_depends_on, v17depends_on, v7components, v21in_order_to) /*  CHECK-COMPONENT-INPUT */;
   if (Null(v1parent)) { goto L53; }
   if (Null(ecl_function_dispatch(cl_env_copy,VV[163])(2, v1parent, v5name) /*  FIND-COMPONENT */)) { goto L53; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[163])(2, v1parent, v5name) /*  FIND-COMPONENT */;
   T1 = ecl_function_dispatch(cl_env_copy,VV[392])(2, v1parent, v4type) /*  CLASS-FOR-TYPE */;
   if ((cl_typep(2, T0, T1))!=ECL_NIL) { goto L53; }
   cl_error(3, VV[177], ECL_SYM("NAME",1273), v5name);
L53:;
   if (Null(v26versionp)) { goto L57; }
   if ((ecl_function_dispatch(cl_env_copy,VV[217])(2, v25version, ECL_NIL) /*  PARSE-VERSION */)!=ECL_NIL) { goto L57; }
   (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(4, _ecl_static_91, v25version, v5name, v1parent) /*  WARN */;
L57:;
   {
    cl_object v27args;
    cl_object v28ret;
    T0 = ecl_function_dispatch(cl_env_copy,VV[233])(1, v5name) /*  COERCE-NAME */;
    T1 = ecl_function_dispatch(cl_env_copy,VV[80])(2, VV[421], v3) /*  REMOVE-KEYS */;
    v27args = cl_listX(7, ECL_SYM("NAME",1273), T0, ECL_SYM("PATHNAME",1285), v9pathname, VV[313], v1parent, T1);
    v28ret = ecl_function_dispatch(cl_env_copy,VV[163])(2, v1parent, v5name) /*  FIND-COMPONENT */;
    if (Null(v15weakly_depends_on)) { goto L62; }
    {
     cl_object v29;
     {cl_object v30;
      v30 = ECL_NIL;
      v30 = ecl_make_cfun((cl_objectfn_fixed)LC287__g1121,ECL_NIL,Cblock,1);
      T0 = v30;
     }
     T1 = (cl_env_copy->function=(ECL_SYM("COMPLEMENT",240)->symbol.gfdef))->cfun.entry(1, T0) /*  COMPLEMENT */;
     v29 = cl_remove_if(2, T1, v15weakly_depends_on);
     v17depends_on = ecl_append(v17depends_on,v29);
    }
L62:;
    if (Null(ecl_symbol_value(VV[398]))) { goto L67; }
    v17depends_on = CONS(ecl_symbol_value(VV[398]),v17depends_on);
L67:;
    if (Null(v28ret)) { goto L71; }
    cl_apply(3, ECL_SYM("REINITIALIZE-INSTANCE",963), v28ret, v27args);
    goto L70;
L71:;
    T0 = ecl_function_dispatch(cl_env_copy,VV[392])(2, v1parent, v4type) /*  CLASS-FOR-TYPE */;
    v28ret = cl_apply(3, ECL_SYM("MAKE-INSTANCE",949), T0, v27args);
L70:;
    ecl_function_dispatch(cl_env_copy,VV[157])(1, v28ret) /*  COMPONENT-PATHNAME */;
    if (Null(si_of_class_p(2, v28ret, VV[172]))) { goto L75; }
    ecl_bds_bind(cl_env_copy,VV[398],ECL_NIL);    /*  *SERIAL-DEPENDS-ON* */
    {
     cl_object v29;
     {
      cl_object v30c_form;
      cl_object v31;
      v30c_form = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v7components))) FEtype_error_list(v7components);
      v31 = v7components;
      {
       cl_object v32c;
       v32c = ECL_NIL;
       {
        cl_object v33name;
        v33name = ECL_NIL;
        {
         cl_object v34;
         cl_object v35;
         v34 = ecl_list1(ECL_NIL);
         v35 = v34;
L86:;
         if (!(ecl_endp(v31))) { goto L88; }
         goto L87;
L88:;
         v30c_form = _ecl_car(v31);
         {
          cl_object v36;
          v36 = _ecl_cdr(v31);
          if (ecl_unlikely(!ECL_LISTP(v36))) FEtype_error_list(v36);
          v31 = v36;
         }
         v32c = L288parse_component_form(v28ret, v30c_form);
         v33name = ecl_function_dispatch(cl_env_copy,VV[813])(1, v32c) /*  COMPONENT-NAME */;
         if (ecl_unlikely(ECL_ATOM(v35))) FEtype_error_cons(v35);
         T0 = v35;
         v35 = ecl_list1(v32c);
         (ECL_CONS_CDR(T0)=v35,T0);
         if (Null(v19serial)) { goto L104; }
         cl_set(VV[398],v33name);
L104:;
         goto L86;
L87:;
         v29 = ecl_cdr(v34);
         goto L78;
        }
       }
      }
     }
L78:;
     (cl_env_copy->function=ecl_fdefinition(VV[926]))->cfun.entry(2, v29, v28ret) /*  (SETF MODULE-COMPONENTS) */;
     ecl_bds_unwind1(cl_env_copy);
    }
    ecl_function_dispatch(cl_env_copy,VV[195])(1, v28ret) /*  COMPUTE-MODULE-COMPONENTS-BY-NAME */;
L75:;
    (cl_env_copy->function=ecl_fdefinition(VV[927]))->cfun.entry(2, v17depends_on, v28ret) /*  (SETF COMPONENT-LOAD-DEPENDENCIES) */;
    {
     cl_object v29;
     T0 = CONS(VV[341],v17depends_on);
     T1 = cl_list(2, VV[341], T0);
     T2 = CONS(VV[25],v17depends_on);
     T3 = cl_list(2, VV[25], T2);
     T4 = cl_list(2, T1, T3);
     v29 = ecl_function_dispatch(cl_env_copy,VV[396])(2, v21in_order_to, T4) /*  UNION-OF-DEPENDENCIES */;
     (cl_env_copy->function=ecl_fdefinition(VV[928]))->cfun.entry(2, v29, v28ret) /*  (SETF COMPONENT-IN-ORDER-TO) */;
    }
    {
     cl_object v29;
     T0 = CONS(VV[25],v17depends_on);
     T1 = cl_list(2, VV[341], T0);
     T2 = ecl_list1(T1);
     v29 = ecl_function_dispatch(cl_env_copy,VV[396])(2, v23do_first, T2) /*  UNION-OF-DEPENDENCIES */;
     (cl_env_copy->function=ecl_fdefinition(VV[929]))->cfun.entry(2, v29, v28ret) /*  (SETF COMPONENT-DO-FIRST) */;
    }
    ecl_function_dispatch(cl_env_copy,VV[408])(2, v28ret, v3) /*  %REFRESH-COMPONENT-INLINE-METHODS */;
    value0 = v28ret;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	local function G1121                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC287__g1121(cl_object v1x)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[144])(2, v1x, ECL_NIL) /*  FIND-SYSTEM */;
  return value0;
 }
}
/*	function definition for RESET-SYSTEM                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L289reset_system(cl_narg narg, cl_object v1system, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2keys;
  ecl_va_list args; ecl_va_start(args,v1system,narg,1);
  cl_parse_key(args,0,NULL,NULL,(cl_object*)&v2keys,TRUE);
  ecl_va_end(args);
  T0 = (cl_env_copy->function=(ECL_SYM("CHANGE-CLASS",932)->symbol.gfdef))->cfun.entry(2, v1system, VV[212]) /*  CHANGE-CLASS */;
  (cl_env_copy->function=(ECL_SYM("CHANGE-CLASS",932)->symbol.gfdef))->cfun.entry(2, T0, VV[213]) /*  CHANGE-CLASS */;
  value0 = cl_apply(3, ECL_SYM("REINITIALIZE-INSTANCE",963), v1system, v2keys);
  return value0;
 }
}
/*	function definition for DO-DEFSYSTEM                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L291do_defsystem(cl_narg narg, cl_object v1name, ...)
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0, CLV1, CLV2, CLV3, CLV4
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2options;
  ecl_va_list args; ecl_va_start(args,v1name,narg,1);
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1name,env0);                /*  NAME            */
  {
   cl_object keyvars[6];
   cl_parse_key(args,3,L291do_defsystemkeys,keyvars,(cl_object*)&v2options,TRUE);
   CLV1 = env0 = CONS(v2options,env0);            /*  OPTIONS         */
   ecl_va_end(args);
   CLV2 = env0 = CONS(keyvars[0],env0);           /*  PATHNAME        */
   if (Null(keyvars[4])) {
    CLV3 = env0 = CONS(VV[213],env0);             /*  CLASS           */
   } else {
    CLV3 = env0 = CONS(keyvars[1],env0);          /*  CLASS           */
   }
   CLV4 = env0 = CONS(keyvars[2],env0);           /*  DEFSYSTEM-DEPENDS-ON */
  }
  {cl_object v3;
   v3 = ECL_NIL;
   v3 = ecl_make_cclosure_va((cl_objectfn)LC290__g1138,env0,Cblock);
   T0 = v3;
  }
  value0 = ecl_function_dispatch(cl_env_copy,VV[279])(1, T0) /*  CALL-WITH-SYSTEM-DEFINITIONS */;
  return value0;
 }
}
/*	closure G1138                                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC290__g1138(cl_narg narg, ...)
{
 cl_object T0, T1;
 cl_object CLV0, CLV1, CLV2, CLV3, CLV4
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV4 = env0;                                     /*  DEFSYSTEM-DEPENDS-ON */
 CLV3 = _ecl_cdr(CLV4);
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=0)) FEwrong_num_arguments_anonym();
 {
TTL:
  {
   cl_object v1name;
   cl_object v2registered;
   cl_object v3registered_;
   cl_object v4system;
   cl_object v5component_options;
   v1name = ecl_function_dispatch(cl_env_copy,VV[233])(1, ECL_CONS_CAR(CLV0)) /*  COERCE-NAME */;
   v2registered = ecl_function_dispatch(cl_env_copy,VV[235])(1, v1name) /*  SYSTEM-REGISTERED-P */;
   if (Null(v2registered)) { goto L4; }
   if (ecl_unlikely(ECL_ATOM(v2registered))) FEtype_error_cons(v2registered);
   T0 = v2registered;
   T1 = cl_get_universal_time();
   v3registered_ = (ECL_CONS_CAR(T0)=T1,T0);
   goto L3;
L4:;
   T0 = (cl_env_copy->function=(ECL_SYM("MAKE-INSTANCE",949)->symbol.gfdef))->cfun.entry(3, VV[213], ECL_SYM("NAME",1273), v1name) /*  MAKE-INSTANCE */;
   v3registered_ = ecl_function_dispatch(cl_env_copy,VV[239])(1, T0) /*  REGISTER-SYSTEM */;
L3:;
   T0 = ecl_cdr(v3registered_);
   T1 = ecl_function_dispatch(cl_env_copy,VV[385])(0) /*  LOAD-PATHNAME */;
   v4system = ecl_function_dispatch(cl_env_copy,VV[423])(5, T0, ECL_SYM("NAME",1273), v1name, VV[292], T1) /*  RESET-SYSTEM */;
   v5component_options = ecl_function_dispatch(cl_env_copy,VV[80])(2, VV[426], ECL_CONS_CAR(CLV1)) /*  REMOVE-KEYS */;
   si_hash_set(v1name, ecl_symbol_value(VV[276]), v4system);
   cl_apply(2, VV[375], ECL_CONS_CAR(CLV4));
   {
    cl_object v6class;
    v6class = ecl_function_dispatch(cl_env_copy,VV[392])(2, ECL_NIL, ECL_CONS_CAR(CLV3)) /*  CLASS-FOR-TYPE */;
    T0 = cl_type_of(v4system);
    if ((T0)==(v6class)) { goto L12; }
    (cl_env_copy->function=(ECL_SYM("CHANGE-CLASS",932)->symbol.gfdef))->cfun.entry(2, v4system, v6class) /*  CHANGE-CLASS */;
   }
L12:;
   T0 = ecl_function_dispatch(cl_env_copy,VV[387])(1, ECL_CONS_CAR(CLV2)) /*  DETERMINE-SYSTEM-PATHNAME */;
   T1 = cl_listX(5, VV[427], v1name, ECL_SYM("PATHNAME",1285), T0, v5component_options);
   value0 = ecl_function_dispatch(cl_env_copy,VV[410])(2, ECL_NIL, T1) /*  PARSE-COMPONENT-FORM */;
   return value0;
  }
 }
 }
}
/*	local function DEFSYSTEM                                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC292defsystem(cl_object v1, cl_object v2)
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
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4name = v5;
   }
   T0 = cl_list(2, ECL_SYM("QUOTE",679), v4name);
   T1 = cl_list(2, ECL_SYM("QUOTE",679), v3);
   value0 = cl_list(4, ECL_SYM("APPLY",89), VV[429], T0, T1);
   return value0;
  }
 }
}
/*	function definition for RUN-SHELL-COMMAND                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L293run_shell_command(cl_narg narg, cl_object v1control_string, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2args;
  ecl_va_list args; ecl_va_start(args,v1control_string,narg,1);
  v2args = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v3command;
   v3command = cl_apply(4, ECL_SYM("FORMAT",387), ECL_NIL, v1control_string, v2args);
   ecl_function_dispatch(cl_env_copy,VV[66])(2, _ecl_static_92, v3command) /*  ASDF-MESSAGE */;
   value0 = si_system(v3command);
   return value0;
  }
 }
}
/*	function definition for SYSTEM-DEFINITION-PATHNAME            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L294system_definition_pathname(cl_object v1x)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[155])(1, v1x) /*  SYSTEM-SOURCE-FILE */;
  return value0;
 }
}
/*	local function G1149                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC295__g1149(cl_object v1system)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((cl_slot_boundp(v1system, VV[297]))!=ECL_NIL) { goto L1; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[813])(1, v1system) /*  COMPONENT-NAME */;
  T1 = ecl_function_dispatch(cl_env_copy,VV[157])(1, v1system) /*  COMPONENT-PATHNAME */;
  T2 = ecl_function_dispatch(cl_env_copy,VV[264])(2, T0, T1) /*  PROBE-ASD */;
  ecl_function_dispatch(cl_env_copy,VV[859])(2, T2, v1system) /*  %SET-SYSTEM-SOURCE-FILE */;
L1:;
  value0 = cl_slot_value(v1system, VV[297]);
  return value0;
 }
}
/*	local function G1150                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC296__g1150(cl_object v1system_name)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[144])(1, v1system_name) /*  FIND-SYSTEM */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[155])(1, T0) /*  SYSTEM-SOURCE-FILE */;
  return value0;
 }
}
/*	local function G1151                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC297__g1151(cl_object v1system_name)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[144])(1, v1system_name) /*  FIND-SYSTEM */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[155])(1, T0) /*  SYSTEM-SOURCE-FILE */;
  return value0;
 }
}
/*	function definition for SYSTEM-SOURCE-DIRECTORY               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L298system_source_directory(cl_object v1system_designator)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[155])(1, v1system_designator) /*  SYSTEM-SOURCE-FILE */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[36])(1, T0) /*  PATHNAME-DIRECTORY-PATHNAME */;
  return value0;
 }
}
/*	function definition for RELATIVIZE-DIRECTORY                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L299relativize_directory(cl_object v1directory)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_STRINGP(v1directory))) { goto L1; }
  value0 = cl_list(2, ECL_SYM("RELATIVE",1299), v1directory);
  return value0;
L1:;
  T0 = ecl_car(v1directory);
  if (!((T0)==(ECL_SYM("ABSOLUTE",1196)))) { goto L3; }
  T0 = ecl_cdr(v1directory);
  value0 = CONS(ECL_SYM("RELATIVE",1299),T0);
  cl_env_copy->nvalues = 1;
  return value0;
L3:;
  value0 = v1directory;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for RELATIVIZE-PATHNAME-DIRECTORY         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L300relativize_pathname_directory(cl_object v1pathspec)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2p;
   v2p = cl_pathname(v1pathspec);
   T0 = cl_pathname_directory(1, v2p);
   T1 = ecl_function_dispatch(cl_env_copy,VV[437])(1, T0) /*  RELATIVIZE-DIRECTORY */;
   value0 = cl_make_pathname(4, ECL_SYM("DIRECTORY",1219), T1, ECL_SYM("DEFAULTS",1216), v2p);
   return value0;
  }
 }
}
/*	function definition for SYSTEM-RELATIVE-PATHNAME              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L301system_relative_pathname(cl_narg narg, cl_object v1system, cl_object v2name, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3type;
  ecl_va_list args; ecl_va_start(args,v2name,narg,2);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L301system_relative_pathnamekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3type = keyvars[0];
  }
  T0 = ecl_function_dispatch(cl_env_copy,VV[435])(1, v1system) /*  SYSTEM-SOURCE-DIRECTORY */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[102])(4, T0, v2name, ECL_SYM("TYPE",1318), v3type) /*  SUBPATHNAME */;
  return value0;
 }
}
/*	function definition for FIRST-FEATURE                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L302first_feature(cl_object v1features)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   v2 = v1features;
   goto L4;
L3:;
   {
    cl_object v3x;
    v3x = ecl_car(v2);
    {
     cl_object v5;                                /*  VAL             */
     cl_object v6;                                /*  FEATURE         */
     if (!(ECL_CONSP(v3x))) { goto L10; }
     T0 = ecl_car(v3x);
     T1 = ecl_cdr(v3x);
     T2 = CONS(VV[255],T1);
     cl_env_copy->nvalues = 2;
     cl_env_copy->values[1] = T2;
     cl_env_copy->values[0] = T0;
     value0 = cl_env_copy->values[0];
     goto L9;
L10:;
     cl_env_copy->nvalues = 2;
     cl_env_copy->values[1] = v3x;
     cl_env_copy->values[0] = v3x;
     value0 = cl_env_copy->values[0];
L9:;
     v5 = value0;
     v6 = cl_env_copy->values[1];
     if (Null(ecl_function_dispatch(cl_env_copy,VV[252])(1, v6) /*  FEATUREP */)) { goto L8; }
     value0 = v5;
     cl_env_copy->nvalues = 1;
     return value0;
    }
L8:;
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
/*	function definition for IMPLEMENTATION-TYPE                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L303implementation_type()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[443])(1, VV[445]) /*  FIRST-FEATURE */;
  return value0;
 }
}
/*	function definition for OPERATING-SYSTEM                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L304operating_system()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[443])(1, VV[447]) /*  FIRST-FEATURE */;
  return value0;
 }
}
/*	function definition for ARCHITECTURE                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L305architecture()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[443])(1, VV[449]) /*  FIRST-FEATURE */;
  return value0;
 }
}
/*	function definition for LISP-VERSION-STRING                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L306lisp_version_string()
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v1s;
   v1s = (cl_env_copy->function=(ECL_SYM("LISP-IMPLEMENTATION-VERSION",480)->symbol.gfdef))->cfun.entry(0) /*  LISP-IMPLEMENTATION-VERSION */;
   {
    cl_object v2vcs_id;
    v2vcs_id = ecl_function_dispatch(cl_env_copy,ECL_SYM("LISP-IMPLEMENTATION-VCS-ID",1764))(0) /*  LISP-IMPLEMENTATION-VCS-ID */;
    {
     cl_fixnum v3;
     v3 = ecl_length(v2vcs_id);
     {
      cl_fixnum v4;
      v4 = (v3)<=(8)?v3:8;
      T0 = cl_subseq(3, v2vcs_id, ecl_make_fixnum(0), ecl_make_fixnum(v4));
     }
    }
   }
   T1 = cl_format(4, ECL_NIL, _ecl_static_93, v1s, T0);
   T2 = cl_list(2, T1, v1s);
   value0 = ecl_car(T2);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for IMPLEMENTATION-IDENTIFIER             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L308implementation_identifier()
{
 cl_object T0, T1, T2, T3, T4, T5;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {cl_object v1;
   v1 = ECL_NIL;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC307__g1155,ECL_NIL,Cblock,1);
   T0 = v1;
  }
  value0 = L303implementation_type();
  if ((value0)!=ECL_NIL) { goto L4; }
  T1 = (cl_env_copy->function=(ECL_SYM("LISP-IMPLEMENTATION-TYPE",479)->symbol.gfdef))->cfun.entry(0) /*  LISP-IMPLEMENTATION-TYPE */;
  goto L2;
L4:;
  T1 = value0;
  goto L2;
L2:;
  value0 = L306lisp_version_string();
  if ((value0)!=ECL_NIL) { goto L8; }
  T2 = (cl_env_copy->function=(ECL_SYM("LISP-IMPLEMENTATION-VERSION",480)->symbol.gfdef))->cfun.entry(0) /*  LISP-IMPLEMENTATION-VERSION */;
  goto L6;
L8:;
  T2 = value0;
  goto L6;
L6:;
  value0 = L304operating_system();
  if ((value0)!=ECL_NIL) { goto L12; }
  T3 = (cl_env_copy->function=(ECL_SYM("SOFTWARE-TYPE",784)->symbol.gfdef))->cfun.entry(0) /*  SOFTWARE-TYPE */;
  goto L10;
L12:;
  T3 = value0;
  goto L10;
L10:;
  value0 = L305architecture();
  if ((value0)!=ECL_NIL) { goto L16; }
  T4 = (cl_env_copy->function=(ECL_SYM("MACHINE-TYPE",516)->symbol.gfdef))->cfun.entry(0) /*  MACHINE-TYPE */;
  goto L14;
L16:;
  T4 = value0;
  goto L14;
L14:;
  T5 = cl_format(6, ECL_NIL, _ecl_static_95, T1, T2, T3, T4);
  value0 = cl_substitute_if(3, CODE_CHAR(95), T0, T5);
  return value0;
 }
}
/*	local function G1155                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC307__g1155(cl_object v1x)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   v2 = si_make_seq_iterator(2, _ecl_static_94, ecl_make_fixnum(0));
L2:;
   if ((v2)!=ECL_NIL) { goto L4; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L4:;
   {
    cl_object v3;
    v3 = si_seq_iterator_ref(_ecl_static_94, v2);
    if (!(ecl_eql(v1x,v3))) { goto L6; }
    value0 = v3;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L6:;
   v2 = si_seq_iterator_next(_ecl_static_94, v2);
   goto L2;
  }
 }
}
/*	function definition for HOSTNAME                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L309hostname()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = (cl_env_copy->function=(ECL_SYM("MACHINE-INSTANCE",515)->symbol.gfdef))->cfun.entry(0) /*  MACHINE-INSTANCE */;
  return value0;
 }
}
/*	function definition for INTER-DIRECTORY-SEPARATOR             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L310inter_directory_separator()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[258])(0) /*  OS-UNIX-P */)) { goto L1; }
  value0 = CODE_CHAR(58);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  value0 = CODE_CHAR(59);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for USER-HOMEDIR                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L311user_homedir()
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_user_homedir_pathname(0);
  T1 = ecl_function_dispatch(cl_env_copy,VV[36])(1, T0) /*  PATHNAME-DIRECTORY-PATHNAME */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[119])(1, T1) /*  TRUENAMIZE */;
  return value0;
 }
}
/*	function definition for ENSURE-PATHNAME*                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L312ensure_pathname_(cl_narg narg, cl_object v1x, cl_object v2want_absolute, cl_object v3want_directory, cl_object v4fmt, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<4)) FEwrong_num_arguments_anonym();
 {
  cl_object v5args;
  ecl_va_list args; ecl_va_start(args,v4fmt,narg,4);
  v5args = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_fixnum v6;
   v6 = ecl_length(v1x);
   if (!((v6)>0)) { goto L1; }
  }
  {
   cl_object v6p;
   if (Null(v3want_directory)) { goto L4; }
   v6p = ecl_function_dispatch(cl_env_copy,VV[91])(1, v1x) /*  ENSURE-DIRECTORY-PATHNAME */;
   goto L3;
L4:;
   v6p = cl_pathname(v1x);
L3:;
   if (Null(v2want_absolute)) { goto L6; }
   if ((ecl_function_dispatch(cl_env_copy,VV[93])(1, v6p) /*  ABSOLUTE-PATHNAME-P */)!=ECL_NIL) { goto L6; }
   cl_cerror(5, _ecl_static_96, _ecl_static_97, v1x, v4fmt, v5args);
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L6:;
   value0 = v6p;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for SPLIT-PATHNAMES*                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L313split_pathnames_(cl_narg narg, cl_object v1x, cl_object v2want_absolute, cl_object v3want_directory, cl_object v4fmt, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<4)) FEwrong_num_arguments_anonym();
 {
  cl_object v5args;
  ecl_va_list args; ecl_va_start(args,v4fmt,narg,4);
  v5args = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v6;
   cl_object v7dir;
   cl_object v8;
   T0 = L310inter_directory_separator();
   T1 = cl_string(T0);
   v6 = ecl_function_dispatch(cl_env_copy,VV[68])(3, v1x, VV[73], T1) /*  SPLIT-STRING */;
   v7dir = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
   v8 = v6;
   {
    cl_object v9;
    cl_object v10;
    v9 = ecl_list1(ECL_NIL);
    v10 = v9;
L7:;
    if (!(ecl_endp(v8))) { goto L9; }
    goto L8;
L9:;
    v7dir = _ecl_car(v8);
    {
     cl_object v11;
     v11 = _ecl_cdr(v8);
     if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
     v8 = v11;
    }
    if (ecl_unlikely(ECL_ATOM(v10))) FEtype_error_cons(v10);
    T0 = v10;
    T1 = cl_apply(6, VV[459], v7dir, v2want_absolute, v3want_directory, v4fmt, v5args);
    v10 = ecl_list1(T1);
    (ECL_CONS_CDR(T0)=v10,T0);
    goto L7;
L8:;
    value0 = ecl_cdr(v9);
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for GETENV-PATHNAME                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L314getenv_pathname(cl_narg narg, cl_object v1x, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2want_absolute;
  cl_object v3want_directory;
  ecl_va_list args; ecl_va_start(args,v1x,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L314getenv_pathnamekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v2want_absolute = keyvars[0];
   v3want_directory = keyvars[1];
  }
  {
   cl_object v4s;
   v4s = ecl_function_dispatch(cl_env_copy,VV[84])(1, v1x) /*  GETENV */;
   value0 = ecl_function_dispatch(cl_env_copy,VV[459])(5, v4s, v2want_absolute, v3want_directory, _ecl_static_98, v1x) /*  ENSURE-PATHNAME* */;
   return value0;
  }
 }
}
/*	function definition for GETENV-PATHNAMES                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L315getenv_pathnames(cl_narg narg, cl_object v1x, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2want_absolute;
  cl_object v3want_directory;
  ecl_va_list args; ecl_va_start(args,v1x,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L315getenv_pathnameskeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v2want_absolute = keyvars[0];
   v3want_directory = keyvars[1];
  }
  {
   cl_object v4s;
   v4s = ecl_function_dispatch(cl_env_copy,VV[84])(1, v1x) /*  GETENV */;
   {
    cl_fixnum v5;
    v5 = ecl_length(v4s);
    if (!((v5)>0)) { goto L3; }
   }
   value0 = ecl_function_dispatch(cl_env_copy,VV[461])(6, v4s, v2want_absolute, v3want_directory, _ecl_static_99, v1x, v4s) /*  SPLIT-PATHNAMES* */;
   return value0;
L3:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for GETENV-ABSOLUTE-DIRECTORY             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L316getenv_absolute_directory(cl_object v1x)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[463])(5, v1x, VV[468], ECL_T, VV[469], ECL_T) /*  GETENV-PATHNAME */;
  return value0;
 }
}
/*	function definition for GETENV-ABSOLUTE-DIRECTORIES           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L317getenv_absolute_directories(cl_object v1x)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[465])(5, v1x, VV[468], ECL_T, VV[469], ECL_T) /*  GETENV-PATHNAMES */;
  return value0;
 }
}
/*	function definition for GET-FOLDER-PATH                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L318get_folder_path(cl_object v1folder)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ecl_eql(v1folder,VV[474]))) { goto L1; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[467])(1, _ecl_static_100) /*  GETENV-ABSOLUTE-DIRECTORY */;
  return value0;
L1:;
  if (!(ecl_eql(v1folder,VV[475]))) { goto L3; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[467])(1, _ecl_static_101) /*  GETENV-ABSOLUTE-DIRECTORY */;
  return value0;
L3:;
  if (!(ecl_eql(v1folder,VV[476]))) { goto L5; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[467])(1, _ecl_static_102) /*  GETENV-ABSOLUTE-DIRECTORY */;
  if ((value0)!=ECL_NIL) { goto L8; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[467])(1, _ecl_static_103) /*  GETENV-ABSOLUTE-DIRECTORY */;
  value0 = L52subpathname_(2, T0, _ecl_static_104);
  return value0;
L8:;
  cl_env_copy->nvalues = 1;
  return value0;
L5:;
  value0 = si_ecase_error(v1folder, VV[477]);
  return value0;
 }
}
/*	function definition for USER-CONFIGURATION-DIRECTORIES        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L319user_configuration_directories()
{
 cl_object T0, T1, T2, T3, T4, T5;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v1dirs;
   if (Null(ecl_function_dispatch(cl_env_copy,VV[258])(0) /*  OS-UNIX-P */)) { goto L3; }
   T1 = ecl_function_dispatch(cl_env_copy,VV[467])(1, _ecl_static_105) /*  GETENV-ABSOLUTE-DIRECTORY */;
   T2 = L52subpathname_(2, T1, _ecl_static_106);
   {
    cl_object v2;
    cl_object v3dir;
    cl_object v4;
    v2 = ecl_function_dispatch(cl_env_copy,VV[471])(1, _ecl_static_107) /*  GETENV-ABSOLUTE-DIRECTORIES */;
    v3dir = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v2))) FEtype_error_list(v2);
    v4 = v2;
    {
     cl_object v5;
     cl_object v6;
     v5 = ecl_list1(ECL_NIL);
     v6 = v5;
L12:;
     if (!(ecl_endp(v4))) { goto L14; }
     goto L13;
L14:;
     v3dir = _ecl_car(v4);
     {
      cl_object v7;
      v7 = _ecl_cdr(v4);
      if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
      v4 = v7;
     }
     if (ecl_unlikely(ECL_ATOM(v6))) FEtype_error_cons(v6);
     T4 = v6;
     T5 = L52subpathname_(2, v3dir, _ecl_static_106);
     v6 = ecl_list1(T5);
     (ECL_CONS_CDR(T4)=v6,T4);
     goto L12;
L13:;
     T3 = ecl_cdr(v5);
     goto L5;
    }
   }
L5:;
   T0 = CONS(T2,T3);
   goto L2;
L3:;
   T0 = ECL_NIL;
L2:;
   if (Null(ecl_function_dispatch(cl_env_copy,VV[261])(0) /*  OS-WINDOWS-P */)) { goto L29; }
   T2 = ecl_function_dispatch(cl_env_copy,VV[473])(1, VV[474]) /*  GET-FOLDER-PATH */;
   T3 = L52subpathname_(2, T2, _ecl_static_108);
   T4 = ecl_function_dispatch(cl_env_copy,VV[473])(1, VV[475]) /*  GET-FOLDER-PATH */;
   T5 = L52subpathname_(2, T4, _ecl_static_108);
   T1 = cl_list(2, T3, T5);
   goto L28;
L29:;
   T1 = ECL_NIL;
L28:;
   T2 = ecl_function_dispatch(cl_env_copy,VV[457])(0) /*  USER-HOMEDIR */;
   T3 = ecl_function_dispatch(cl_env_copy,VV[102])(2, T2, _ecl_static_109) /*  SUBPATHNAME */;
   T4 = ecl_list1(T3);
   v1dirs = cl_append(3, T0, T1, T4);
   T0 = ecl_fdefinition(VV[93]);
   T1 = cl_remove_if_not(2, T0, v1dirs);
   value0 = cl_remove_duplicates(5, T1, VV[15], ECL_T, ECL_SYM("TEST",1316), ECL_SYM("EQUAL",335));
   return value0;
  }
 }
}
/*	function definition for SYSTEM-CONFIGURATION-DIRECTORIES      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L320system_configuration_directories()
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[258])(0) /*  OS-UNIX-P */)) { goto L1; }
  value0 = VV[482];
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (Null(ecl_function_dispatch(cl_env_copy,VV[261])(0) /*  OS-WINDOWS-P */)) { goto L3; }
  {
   cl_object v1it;
   T0 = ecl_function_dispatch(cl_env_copy,VV[473])(1, VV[476]) /*  GET-FOLDER-PATH */;
   v1it = L52subpathname_(2, T0, _ecl_static_108);
   if (Null(v1it)) { goto L6; }
   value0 = ecl_list1(v1it);
   cl_env_copy->nvalues = 1;
   return value0;
L6:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L3:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for IN-FIRST-DIRECTORY                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L321in_first_directory(cl_narg narg, cl_object v1dirs, cl_object v2x, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3direction;
  ecl_va_list args; ecl_va_start(args,v2x,narg,2);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L321in_first_directorykeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[1])) {
    v3direction = ECL_SYM("INPUT",1254);
   } else {
    v3direction = keyvars[0];
   }
  }
  {
   cl_object v4fun;
   if (!((v3direction)==(ECL_NIL))) { goto L8; }
   goto L5;
   goto L6;
L8:;
   goto L6;
L6:;
   if (!(ecl_eql(v3direction,ECL_SYM("INPUT",1254)))) { goto L12; }
   goto L5;
   goto L10;
L12:;
   goto L10;
L10:;
   if (!(ecl_eql(v3direction,ECL_SYM("PROBE",1293)))) { goto L3; }
   goto L4;
L5:;
L4:;
   v4fun = VV[116];
   goto L2;
L3:;
   if (!(ecl_eql(v3direction,ECL_SYM("OUTPUT",1282)))) { goto L20; }
   goto L17;
   goto L18;
L20:;
   goto L18;
L18:;
   if (!(ecl_eql(v3direction,ECL_SYM("IO",1260)))) { goto L15; }
   goto L16;
L17:;
L16:;
   v4fun = ECL_SYM("IDENTITY",426);
   goto L2;
L15:;
   v4fun = si_ecase_error(v3direction, VV[490]);
L2:;
   {
    cl_object v5dir;
    cl_object v6;
    v5dir = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v1dirs))) FEtype_error_list(v1dirs);
    v6 = v1dirs;
    {
     cl_object v7;
     v7 = ECL_NIL;
L27:;
     if (!(ecl_endp(v6))) { goto L29; }
     goto L28;
L29:;
     v5dir = _ecl_car(v6);
     {
      cl_object v8;
      v8 = _ecl_cdr(v6);
      if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
      v6 = v8;
     }
     if (Null(v5dir)) { goto L41; }
     T0 = ecl_function_dispatch(cl_env_copy,VV[91])(1, v5dir) /*  ENSURE-DIRECTORY-PATHNAME */;
     T1 = ecl_function_dispatch(cl_env_copy,VV[51])(2, v2x, T0) /*  MERGE-PATHNAMES* */;
     v7 = ecl_function_dispatch(cl_env_copy,v4fun)(1, T1);
     goto L39;
L41:;
     v7 = ECL_NIL;
     goto L39;
L39:;
     if (Null(v7)) { goto L37; }
     value0 = v7;
     cl_env_copy->nvalues = 1;
     return value0;
L37:;
     goto L27;
L28:;
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
  }
 }
}
/*	function definition for IN-USER-CONFIGURATION-DIRECTORY       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L322in_user_configuration_directory(cl_narg narg, cl_object v1x, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2direction;
  ecl_va_list args; ecl_va_start(args,v1x,narg,1);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L322in_user_configuration_directorykeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[1])) {
    v2direction = ECL_SYM("INPUT",1254);
   } else {
    v2direction = keyvars[0];
   }
  }
  T0 = ecl_function_dispatch(cl_env_copy,VV[479])(0) /*  USER-CONFIGURATION-DIRECTORIES */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[484])(4, T0, v1x, ECL_SYM("DIRECTION",1218), v2direction) /*  IN-FIRST-DIRECTORY */;
  return value0;
 }
}
/*	function definition for IN-SYSTEM-CONFIGURATION-DIRECTORY     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L323in_system_configuration_directory(cl_narg narg, cl_object v1x, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2direction;
  ecl_va_list args; ecl_va_start(args,v1x,narg,1);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L323in_system_configuration_directorykeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[1])) {
    v2direction = ECL_SYM("INPUT",1254);
   } else {
    v2direction = keyvars[0];
   }
  }
  T0 = ecl_function_dispatch(cl_env_copy,VV[481])(0) /*  SYSTEM-CONFIGURATION-DIRECTORIES */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[484])(4, T0, v1x, ECL_SYM("DIRECTION",1218), v2direction) /*  IN-FIRST-DIRECTORY */;
  return value0;
 }
}
/*	function definition for CONFIGURATION-INHERITANCE-DIRECTIVE-P */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L324configuration_inheritance_directive_p(cl_object v1x)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_memql(v1x,VV[497]);
  if ((value0)!=ECL_NIL) { goto L2; }
  if (Null(ecl_function_dispatch(cl_env_copy,VV[105])(2, v1x, ecl_make_fixnum(1)) /*  LENGTH=N-P */)) { goto L5; }
  T0 = ecl_car(v1x);
  value0 = ecl_memql(T0,VV[497]);
  cl_env_copy->nvalues = 1;
  return value0;
L5:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for REPORT-INVALID-FORM                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L325report_invalid_form(cl_narg narg, cl_object v1reporter, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2args;
  ecl_va_list args; ecl_va_start(args,v1reporter,narg,1);
  v2args = cl_grab_rest_args(args);
  ecl_va_end(args);
  if (!(v1reporter==ECL_NIL)) { goto L1; }
  value0 = cl_apply(3, ECL_SYM("ERROR",337), VV[186], v2args);
  return value0;
L1:;
  if (Null(cl_functionp(v1reporter))) { goto L3; }
  value0 = cl_apply(2, v1reporter, v2args);
  return value0;
L3:;
  if (ECL_SYMBOLP(v1reporter)) { goto L7; }
  if (!(ECL_STRINGP(v1reporter))) { goto L5; }
  goto L6;
L7:;
L6:;
  value0 = cl_apply(3, ECL_SYM("ERROR",337), v1reporter, v2args);
  return value0;
L5:;
  if (!(ECL_CONSP(v1reporter))) { goto L9; }
  T0 = ecl_append(v1reporter,v2args);
  value0 = cl_apply(2, ECL_SYM("APPLY",89), T0);
  return value0;
L9:;
  value0 = si_etypecase_error(v1reporter, VV[500]);
  return value0;
 }
}
/*	function definition for VALIDATE-CONFIGURATION-FORM           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L326validate_configuration_form(cl_narg narg, cl_object v1form, cl_object v2tag, cl_object v3directive_validator, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 {
  cl_object v4location;
  cl_object v5invalid_form_reporter;
  ecl_va_list args; ecl_va_start(args,v3directive_validator,narg,3);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L326validate_configuration_formkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v4location = keyvars[0];
   v5invalid_form_reporter = keyvars[1];
  }
  if (!(ECL_CONSP(v1form))) { goto L4; }
  T0 = ecl_car(v1form);
  if ((T0)==(v2tag)) { goto L1; }
  goto L2;
L4:;
  goto L2;
L2:;
  cl_set(VV[502],ECL_T);
  ecl_function_dispatch(cl_env_copy,VV[499])(5, v5invalid_form_reporter, VV[504], v1form, ECL_SYM("LOCATION",999), v4location) /*  REPORT-INVALID-FORM */;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  {
   cl_object v6inherit;
   v6inherit = ecl_make_fixnum(0);
   {
    cl_object v7ignore_invalid_p;
    v7ignore_invalid_p = ECL_NIL;
    {
     cl_object v8x;
     v8x = ecl_list1(v2tag);
     {
      cl_object v9;
      cl_object v10directive;
      cl_object v11;
      v9 = ecl_cdr(v1form);
      v10directive = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
      v11 = v9;
L16:;
      if (!(ecl_endp(v11))) { goto L18; }
      goto L17;
L18:;
      v10directive = _ecl_car(v11);
      {
       cl_object v12;
       v12 = _ecl_cdr(v11);
       if (ecl_unlikely(!ECL_LISTP(v12))) FEtype_error_list(v12);
       v11 = v12;
      }
      if (Null(ecl_function_dispatch(cl_env_copy,VV[496])(1, v10directive) /*  CONFIGURATION-INHERITANCE-DIRECTIVE-P */)) { goto L28; }
      v6inherit = ecl_plus(v6inherit,ecl_make_fixnum(1));
      goto L27;
L28:;
      if (!((v10directive)==(VV[505]))) { goto L32; }
      v7ignore_invalid_p = ECL_T;
      goto L27;
L32:;
      if (Null(ecl_function_dispatch(cl_env_copy,v3directive_validator)(1, v10directive))) { goto L36; }
      goto L27;
L36:;
      if (Null(v7ignore_invalid_p)) { goto L38; }
      goto L26;
L38:;
      cl_set(VV[502],ECL_T);
      ecl_function_dispatch(cl_env_copy,VV[499])(5, v5invalid_form_reporter, VV[504], v10directive, ECL_SYM("LOCATION",999), v4location) /*  REPORT-INVALID-FORM */;
      goto L26;
L27:;
      v8x = CONS(v10directive,v8x);
L26:;
      goto L16;
L17:;
      if (ecl_number_equalp(v6inherit,ecl_make_fixnum(1))) { goto L46; }
      T0 = cl_list(3, _ecl_static_110, VV[507], VV[508]);
      ecl_function_dispatch(cl_env_copy,VV[499])(3, v5invalid_form_reporter, VV[506], T0) /*  REPORT-INVALID-FORM */;
L46:;
      value0 = cl_nreverse(v8x);
      return value0;
      value0 = ECL_NIL;
      cl_env_copy->nvalues = 1;
      return value0;
     }
    }
   }
  }
 }
}
/*	function definition for VALIDATE-CONFIGURATION-FILE           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L327validate_configuration_file(cl_narg narg, cl_object v1file, cl_object v2validator, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3description;
  ecl_va_list args; ecl_va_start(args,v2validator,narg,2);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L327validate_configuration_filekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3description = keyvars[0];
  }
  {
   cl_object v4forms;
   v4forms = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1file) /*  READ-FILE-FORMS */;
   if ((ecl_function_dispatch(cl_env_copy,VV[105])(2, v4forms, ecl_make_fixnum(1)) /*  LENGTH=N-P */)!=ECL_NIL) { goto L2; }
   cl_error(3, _ecl_static_111, v3description, v4forms);
L2:;
   T0 = ecl_car(v4forms);
   value0 = ecl_function_dispatch(cl_env_copy,v2validator)(3, T0, ECL_SYM("LOCATION",999), v1file);
   return value0;
  }
 }
}
/*	function definition for HIDDEN-FILE-P                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L328hidden_file_p(cl_object v1pathname)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_pathname_name(1, v1pathname);
  T1 = ecl_function_dispatch(cl_env_copy,VV[62])(1, T0) /*  FIRST-CHAR */;
  value0 = ecl_make_bool(ecl_equal(T1,CODE_CHAR(46)));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for DIRECTORY*                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L329directory_(cl_narg narg, cl_object v1pathname_spec, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2keys;
  ecl_va_list args; ecl_va_start(args,v1pathname_spec,narg,1);
  cl_parse_key(args,0,NULL,NULL,(cl_object*)&v2keys,TRUE);
  ecl_va_end(args);
  T0 = ecl_append(v2keys,ECL_NIL);
  value0 = cl_apply(3, ECL_SYM("DIRECTORY",303), v1pathname_spec, T0);
  return value0;
 }
}
/*	function definition for VALIDATE-CONFIGURATION-DIRECTORY      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L331validate_configuration_directory(volatile cl_narg narg, cl_object volatile v1directory, cl_object volatile v2tag, cl_object volatile v3validator, ...)
{
 cl_object T0, T1, T2, T3, T4;
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 {
  volatile cl_object v4invalid_form_reporter;
  ecl_va_list args; ecl_va_start(args,v3validator,narg,3);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L331validate_configuration_directorykeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v4invalid_form_reporter = keyvars[0];
  }
  {
   volatile cl_object v5files;
   {
    volatile cl_object env1 = env0;
    env1 = ECL_NIL;
    CLV0 = env1 = CONS(ECL_NIL,env1);
    {
     volatile cl_object env2 = env1;
     CLV1 = env2 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env2); /*  TAGBODY */
     if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV1))) {
     if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L3;
     ecl_internal_error("GO found an inexistent tag");
     }
     {cl_object v6;
      v6 = ECL_NIL;
      v6 = ecl_make_cclosure_va((cl_objectfn)LC330__g1198,env2,Cblock);
      T1 = v6;
     }
     T2 = CONS(ECL_SYM("ERROR",337),T1);
     T3 = ecl_list1(T2);
     T4 = CONS(T3,ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5)));
     ecl_bds_bind(cl_env_copy,ECL_SYM("*HANDLER-CLUSTERS*",5),T4); /*  *HANDLER-CLUSTERS* */
     T1 = cl_make_pathname(6, ECL_SYM("NAME",1273), ECL_SYM("WILD",1327), ECL_SYM("TYPE",1318), _ecl_static_112, ECL_SYM("DEFAULTS",1216), v1directory);
     T2 = ecl_function_dispatch(cl_env_copy,VV[514])(1, T1) /*  DIRECTORY* */;
     value0 = cl_remove_if(2, VV[512], T2);
     ecl_frs_pop(cl_env_copy);
     T0 = value0;
     ecl_bds_unwind1(cl_env_copy);
     goto L2;
L3:;
     {
      cl_object v6condition;
      v6condition = ECL_CONS_CAR(CLV0);
      cl_env_copy->nvalues = 2;
      cl_env_copy->values[1] = v6condition;
      cl_env_copy->values[0] = ECL_NIL;
      value0 = cl_env_copy->values[0];
      ecl_frs_pop(cl_env_copy);
      T0 = value0;
      goto L2;
     }
    }
   }
L2:;
   T1 = (ECL_SYM("STRING<",820)->symbol.gfdef);
   T2 = (ECL_SYM("NAMESTRING",579)->symbol.gfdef);
   v5files = cl_sort(4, T0, T1, ECL_SYM("KEY",1262), T2);
   {
    cl_object v6file;
    cl_object v7;
    v6file = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v5files))) FEtype_error_list(v5files);
    v7 = v5files;
    {
     cl_object v8;
     cl_object v9;
     v8 = ecl_list1(ECL_NIL);
     v9 = v8;
L16:;
     if (!(ecl_endp(v7))) { goto L18; }
     goto L17;
L18:;
     v6file = _ecl_car(v7);
     {
      cl_object v10;
      v10 = _ecl_cdr(v7);
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      v7 = v10;
     }
     {
      cl_object v10;
      {
       cl_object v11ignore_invalid_p;
       v11ignore_invalid_p = ECL_NIL;
       {
        cl_object v12;
        cl_object v13form;
        cl_object v14;
        v12 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v6file) /*  READ-FILE-FORMS */;
        v13form = ECL_NIL;
        if (ecl_unlikely(!ECL_LISTP(v12))) FEtype_error_list(v12);
        v14 = v12;
        {
         cl_object v15;
         cl_object v16;
         v15 = ecl_list1(ECL_NIL);
         v16 = v15;
L37:;
         if (!(ecl_endp(v14))) { goto L39; }
         goto L38;
L39:;
         v13form = _ecl_car(v14);
         {
          cl_object v17;
          v17 = _ecl_cdr(v14);
          if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
          v14 = v17;
         }
         if (!((v13form)==(VV[505]))) { goto L48; }
         v11ignore_invalid_p = ECL_T;
         goto L47;
L48:;
         if (Null(ecl_function_dispatch(cl_env_copy,v3validator)(1, v13form))) { goto L51; }
         if (ecl_unlikely(ECL_ATOM(v16))) FEtype_error_cons(v16);
         T2 = v16;
         v16 = ecl_list1(v13form);
         (ECL_CONS_CDR(T2)=v16,T2);
         goto L47;
L51:;
         if (Null(v11ignore_invalid_p)) { goto L56; }
         cl_set(VV[502],ECL_T);
         goto L47;
L56:;
         ecl_function_dispatch(cl_env_copy,VV[499])(5, v4invalid_form_reporter, VV[504], v13form, ECL_SYM("LOCATION",999), v6file) /*  REPORT-INVALID-FORM */;
L47:;
         goto L37;
L38:;
         T1 = ecl_cdr(v15);
         goto L29;
        }
       }
      }
L29:;
      v10 = cl_copy_list(T1);
      if (ecl_unlikely(ECL_ATOM(v9))) FEtype_error_cons(v9);
      T1 = v9;
      (ECL_CONS_CDR(T1)=v10,T1);
      if (Null(v10)) { goto L26; }
     }
     T1 = ecl_cdr(v9);
     v9 = ecl_last(T1,1);
L26:;
     goto L16;
L17:;
     T0 = ecl_cdr(v8);
     goto L10;
    }
   }
L10:;
   T1 = ecl_append(T0,VV[517]);
   value0 = CONS(v2tag,T1);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	closure G1198                                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC330__g1198(cl_narg narg, cl_object v1si__temp, ...)
{
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  TAGBODY         */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  ECL_CONS_CAR(CLV0) = v1si__temp;
  cl_go(ECL_CONS_CAR(CLV1),ecl_make_fixnum(0));
 }
 }
}
/*	local function TRY                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC332try(cl_narg narg, cl_object v1x, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2sub;
  ecl_va_list args; ecl_va_start(args,v1x,narg,1);
  v2sub = cl_grab_rest_args(args);
  ecl_va_end(args);
  if (Null(v1x)) { goto L2; }
  value0 = CONS(v1x,v2sub);
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for OUTPUT-TRANSLATIONS                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L333output_translations()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_car(ecl_symbol_value(VV[519]));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for (SETF OUTPUT-TRANSLATIONS)            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L335_setf_output_translations_(cl_object v1new_value)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_copy_list(v1new_value);
  T1 = (ECL_SYM(">",75)->symbol.gfdef);
  {cl_object v2;
   v2 = ECL_NIL;
   v2 = ecl_make_cfun((cl_objectfn_fixed)LC334__g1214,ECL_NIL,Cblock,1);
   T2 = v2;
  }
  T3 = cl_stable_sort(4, T0, T1, ECL_SYM("KEY",1262), T2);
  cl_set(VV[519],ecl_list1(T3));
  value0 = v1new_value;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G1214                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC334__g1214(cl_object v1x)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   v2 = ecl_car(v1x);
   if (Null(cl_typep(2, v2, VV[524]))) { goto L2; }
   value0 = ecl_make_fixnum(-1);
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
   if (Null(cl_pathnamep(v2))) { goto L4; }
   {
    cl_object v3directory;
    T0 = ecl_car(v1x);
    v3directory = cl_pathname_directory(1, T0);
    if (!(ECL_LISTP(v3directory))) { goto L7; }
    value0 = ecl_make_fixnum(ecl_length(v3directory));
    cl_env_copy->nvalues = 1;
    return value0;
L7:;
    value0 = ecl_make_fixnum(0);
    cl_env_copy->nvalues = 1;
    return value0;
   }
L4:;
   value0 = si_etypecase_error(v2, VV[525]);
   return value0;
  }
 }
}
/*	function definition for OUTPUT-TRANSLATIONS-INITIALIZED-P     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L336output_translations_initialized_p()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_symbol_value(VV[519]))) { goto L2; }
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for CLEAR-OUTPUT-TRANSLATIONS             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L337clear_output_translations()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  cl_set(VV[519],ECL_NIL);
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  return value0;
 }
}
/*	function definition for RESOLVE-RELATIVE-LOCATION-COMPONENT   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L338resolve_relative_location_component(cl_narg narg, cl_object v1x, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2directory;
  cl_object v3wilden;
  ecl_va_list args; ecl_va_start(args,v1x,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L338resolve_relative_location_componentkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v2directory = keyvars[0];
   v3wilden = keyvars[1];
  }
  {
   cl_object v4r;
   if (Null(cl_pathnamep(v1x))) { goto L2; }
   v4r = v1x;
   goto L1;
L2:;
   if (!(ECL_STRINGP(v1x))) { goto L4; }
   if (Null(v2directory)) { goto L7; }
   T0 = ECL_SYM("DIRECTORY",1219);
   goto L6;
L7:;
   T0 = ECL_NIL;
L6:;
   v4r = ecl_function_dispatch(cl_env_copy,VV[95])(3, v1x, ECL_SYM("TYPE",1318), T0) /*  COERCE-PATHNAME */;
   goto L1;
L4:;
   if (!(ECL_CONSP(v1x))) { goto L9; }
   T0 = ecl_cdr(v1x);
   if (!(T0==ECL_NIL)) { goto L11; }
   T0 = ecl_car(v1x);
   v4r = L338resolve_relative_location_component(5, T0, ECL_SYM("DIRECTORY",1219), v2directory, VV[532], v3wilden);
   goto L1;
L11:;
   {
    cl_object v5car;
    T0 = ecl_car(v1x);
    v5car = L338resolve_relative_location_component(5, T0, ECL_SYM("DIRECTORY",1219), ECL_T, VV[532], ECL_NIL);
    T0 = ecl_cdr(v1x);
    T1 = L338resolve_relative_location_component(5, T0, ECL_SYM("DIRECTORY",1219), v2directory, VV[532], v3wilden);
    v4r = ecl_function_dispatch(cl_env_copy,VV[51])(2, T1, v5car) /*  MERGE-PATHNAMES* */;
    goto L1;
   }
L9:;
   if (Null(cl_typep(2, v1x, VV[533]))) { goto L14; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[128])(0) /*  DEFAULT-DIRECTORY */;
   v4r = ecl_function_dispatch(cl_env_copy,VV[439])(1, T0) /*  RELATIVIZE-PATHNAME-DIRECTORY */;
   goto L1;
L14:;
   if (Null(cl_typep(2, v1x, VV[534]))) { goto L16; }
   v4r = ecl_symbol_value(VV[134]);
   goto L1;
L16:;
   if (Null(cl_typep(2, v1x, VV[535]))) { goto L18; }
   v4r = ecl_symbol_value(VV[135]);
   goto L1;
L18:;
   if (Null(cl_typep(2, v1x, VV[536]))) { goto L20; }
   v4r = ecl_symbol_value(VV[133]);
   goto L1;
L20:;
   if (Null(cl_typep(2, v1x, VV[537]))) { goto L22; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[452])(0) /*  IMPLEMENTATION-IDENTIFIER */;
   v4r = ecl_function_dispatch(cl_env_copy,VV[95])(3, T0, ECL_SYM("TYPE",1318), ECL_SYM("DIRECTORY",1219)) /*  COERCE-PATHNAME */;
   goto L1;
L22:;
   if (Null(cl_typep(2, v1x, VV[538]))) { goto L24; }
   T0 = L303implementation_type();
   T1 = cl_string_downcase(1, T0);
   v4r = ecl_function_dispatch(cl_env_copy,VV[95])(3, T1, ECL_SYM("TYPE",1318), ECL_SYM("DIRECTORY",1219)) /*  COERCE-PATHNAME */;
   goto L1;
L24:;
   if (Null(cl_typep(2, v1x, VV[539]))) { goto L26; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[454])(0) /*  HOSTNAME    */;
   v4r = ecl_function_dispatch(cl_env_copy,VV[95])(3, T0, ECL_SYM("TYPE",1318), ECL_SYM("DIRECTORY",1219)) /*  COERCE-PATHNAME */;
   goto L1;
L26:;
   v4r = si_etypecase_error(v1x, VV[540]);
L1:;
   if (Null(ecl_function_dispatch(cl_env_copy,VV[93])(1, v4r) /*  ABSOLUTE-PATHNAME-P */)) { goto L28; }
   cl_error(2, _ecl_static_116, v1x);
L28:;
   if ((cl_pathnamep(v1x))!=ECL_NIL) { goto L32; }
   if ((v3wilden)!=ECL_NIL) { goto L30; }
   goto L31;
L32:;
L31:;
   value0 = v4r;
   cl_env_copy->nvalues = 1;
   return value0;
L30:;
   value0 = ecl_function_dispatch(cl_env_copy,VV[137])(1, v4r) /*  WILDEN */;
   return value0;
  }
 }
}
/*	function definition for RESOLVE-ABSOLUTE-LOCATION-COMPONENT   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L339resolve_absolute_location_component(cl_narg narg, cl_object v1x, ...)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2directory;
  cl_object v3wilden;
  ecl_va_list args; ecl_va_start(args,v1x,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L339resolve_absolute_location_componentkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v2directory = keyvars[0];
   v3wilden = keyvars[1];
  }
  {
   cl_object v4r;
   cl_object v5s;
   if (Null(cl_pathnamep(v1x))) { goto L2; }
   v4r = v1x;
   goto L1;
L2:;
   if (!(ECL_STRINGP(v1x))) { goto L4; }
   {
    cl_object v6p;
    v6p = cl_parse_namestring(1, v1x);
    if (Null(v2directory)) { goto L7; }
    v4r = ecl_function_dispatch(cl_env_copy,VV[91])(1, v6p) /*  ENSURE-DIRECTORY-PATHNAME */;
    goto L1;
L7:;
    v4r = v6p;
    goto L1;
   }
L4:;
   if (!(ECL_CONSP(v1x))) { goto L9; }
   T0 = ecl_cdr(v1x);
   if (!(T0==ECL_NIL)) { goto L11; }
   T0 = ecl_car(v1x);
   value0 = L339resolve_absolute_location_component(5, T0, ECL_SYM("DIRECTORY",1219), v2directory, VV[532], v3wilden);
   return value0;
L11:;
   T0 = ecl_cdr(v1x);
   T1 = ecl_function_dispatch(cl_env_copy,VV[531])(5, T0, ECL_SYM("DIRECTORY",1219), v2directory, VV[532], v3wilden) /*  RESOLVE-RELATIVE-LOCATION-COMPONENT */;
   T2 = ecl_car(v1x);
   T3 = L339resolve_absolute_location_component(5, T2, ECL_SYM("DIRECTORY",1219), ECL_T, VV[532], ECL_NIL);
   value0 = ecl_function_dispatch(cl_env_copy,VV[51])(2, T1, T3) /*  MERGE-PATHNAMES* */;
   return value0;
L9:;
   if (Null(cl_typep(2, v1x, VV[544]))) { goto L13; }
   {
    cl_object v7p;
    v7p = cl_make_pathname(2, ECL_SYM("DIRECTORY",1219), VV[40]);
    if (Null(v3wilden)) { goto L16; }
    value0 = ecl_function_dispatch(cl_env_copy,VV[137])(1, v7p) /*  WILDEN */;
    return value0;
L16:;
    value0 = v7p;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L13:;
   if (Null(cl_typep(2, v1x, VV[545]))) { goto L18; }
   v4r = ecl_function_dispatch(cl_env_copy,VV[457])(0) /*  USER-HOMEDIR */;
   goto L1;
L18:;
   if (Null(cl_typep(2, v1x, VV[546]))) { goto L20; }
   value0 = ecl_symbol_value(VV[542]);
   if ((value0)!=ECL_NIL) { goto L24; }
   T0 = VV[547];
   goto L22;
L24:;
   T0 = value0;
   goto L22;
L22:;
   v4r = L340resolve_location(5, T0, ECL_SYM("DIRECTORY",1219), ECL_T, VV[532], ECL_NIL);
   goto L1;
L20:;
   if (Null(cl_typep(2, v1x, VV[548]))) { goto L26; }
   v4r = L340resolve_location(5, ecl_symbol_value(VV[520]), ECL_SYM("DIRECTORY",1219), ECL_T, VV[532], ECL_NIL);
   goto L1;
L26:;
   if (Null(cl_typep(2, v1x, VV[549]))) { goto L28; }
   v4r = cl_error(1, _ecl_static_117);
   goto L1;
L28:;
   if (Null(cl_typep(2, v1x, VV[533]))) { goto L30; }
   v4r = ecl_function_dispatch(cl_env_copy,VV[128])(0) /*  DEFAULT-DIRECTORY */;
   goto L1;
L30:;
   v4r = si_etypecase_error(v1x, VV[550]);
L1:;
   if (Null(v3wilden)) { goto L33; }
   if ((cl_pathnamep(v1x))!=ECL_NIL) { goto L33; }
   v5s = ecl_function_dispatch(cl_env_copy,VV[137])(1, v4r) /*  WILDEN */;
   goto L32;
L33:;
   v5s = v4r;
L32:;
   if ((ecl_function_dispatch(cl_env_copy,VV[93])(1, v5s) /*  ABSOLUTE-PATHNAME-P */)!=ECL_NIL) { goto L36; }
   cl_error(2, _ecl_static_118, v1x);
L36:;
   value0 = v5s;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for RESOLVE-LOCATION                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L340resolve_location(cl_narg narg, cl_object v1x, ...)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2directory;
  cl_object v3wilden;
  ecl_va_list args; ecl_va_start(args,v1x,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L340resolve_locationkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v2directory = keyvars[0];
   v3wilden = keyvars[1];
  }
  if (!(ECL_ATOM(v1x))) { goto L1; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[543])(5, v1x, ECL_SYM("DIRECTORY",1219), v2directory, VV[532], v3wilden) /*  RESOLVE-ABSOLUTE-LOCATION-COMPONENT */;
  return value0;
L1:;
  {
   cl_object v4path;
   T0 = ecl_car(v1x);
   if ((v2directory)!=ECL_NIL) { goto L8; }
   if (Null(ecl_cdr(v1x))) { goto L6; }
   goto L7;
L8:;
L7:;
   T1 = ECL_T;
   goto L4;
L6:;
   T1 = ECL_NIL;
   goto L4;
L4:;
   if (Null(v3wilden)) { goto L12; }
   T3 = ecl_cdr(v1x);
   T2 = ecl_make_bool(T3==ECL_NIL);
   goto L10;
L12:;
   T2 = ECL_NIL;
   goto L10;
L10:;
   v4path = ecl_function_dispatch(cl_env_copy,VV[543])(5, T0, ECL_SYM("DIRECTORY",1219), T1, VV[532], T2) /*  RESOLVE-ABSOLUTE-LOCATION-COMPONENT */;
   {
    cl_object v5;
    cl_object v6;
    cl_object v7component;
    cl_object v8morep;
    v5 = ecl_cdr(v1x);
    if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
    v6 = v5;
    v7component = ECL_NIL;
    v8morep = ECL_NIL;
    {
     cl_object v9dir;
     v9dir = ECL_NIL;
     {
      cl_object v10wild;
      v10wild = ECL_NIL;
L21:;
      if (!(ECL_ATOM(v6))) { goto L23; }
      goto L22;
L23:;
      {
       cl_object v11;
       v11 = v6;
       v7component = ecl_car(v11);
       v11 = ecl_cdr(v11);
       v8morep = v11;
      }
      {
       cl_object v11;
       v11 = _ecl_cdr(v6);
       if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
       v6 = v11;
      }
      if ((v8morep)!=ECL_NIL) { goto L41; }
      if (Null(v2directory)) { goto L39; }
      goto L40;
L41:;
L40:;
      v9dir = ECL_T;
      goto L37;
L39:;
      v9dir = ECL_NIL;
      goto L37;
L37:;
      if (Null(v3wilden)) { goto L46; }
      v10wild = Null(v8morep)?ECL_T:ECL_NIL;
      goto L44;
L46:;
      v10wild = ECL_NIL;
      goto L44;
L44:;
      T0 = ecl_function_dispatch(cl_env_copy,VV[531])(5, v7component, ECL_SYM("DIRECTORY",1219), v9dir, VV[532], v10wild) /*  RESOLVE-RELATIVE-LOCATION-COMPONENT */;
      v4path = ecl_function_dispatch(cl_env_copy,VV[51])(2, T0, v4path) /*  MERGE-PATHNAMES* */;
      goto L21;
L22:;
      value0 = v4path;
      cl_env_copy->nvalues = 1;
      return value0;
     }
    }
   }
  }
 }
}
/*	function definition for LOCATION-DESIGNATOR-P                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L343location_designator_p(cl_object v1x)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {cl_object v2;
   v2 = ECL_NIL;
   v2 = ecl_make_cfun((cl_objectfn_fixed)LC342relative_component_p,ECL_NIL,Cblock,1);
   if (!((v1x)==(ECL_NIL))) { goto L8; }
   value0 = VV[557];
   goto L6;
L8:;
   value0 = ECL_NIL;
   goto L6;
L6:;
   if ((value0)!=ECL_NIL) { goto L5; }
   if (!(ecl_eql(v1x,ECL_T))) { goto L11; }
   value0 = VV[558];
   goto L3;
L11:;
   value0 = ECL_NIL;
   goto L3;
L5:;
   goto L3;
L3:;
   if ((value0)!=ECL_NIL) { goto L2; }
   value0 = LC341absolute_component_p(v1x);
   if ((value0)!=ECL_NIL) { goto L2; }
   if (!(ECL_CONSP(v1x))) { goto L15; }
   T0 = ecl_car(v1x);
   if (Null(LC341absolute_component_p(T0))) { goto L15; }
   T0 = ecl_cdr(v1x);
   value0 = cl_every(2, v2, T0);
   return value0;
L15:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function RELATIVE-COMPONENT-P                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC342relative_component_p(cl_object v1c)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_make_bool(ECL_STRINGP(v1c));
  if ((value0)!=ECL_NIL) { goto L2; }
  value0 = cl_pathnamep(v1c);
  if ((value0)!=ECL_NIL) { goto L2; }
  value0 = ecl_memql(v1c,VV[556]);
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function ABSOLUTE-COMPONENT-P                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC341absolute_component_p(cl_object v1c)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_make_bool(ECL_STRINGP(v1c));
  if ((value0)!=ECL_NIL) { goto L2; }
  value0 = cl_pathnamep(v1c);
  if ((value0)!=ECL_NIL) { goto L2; }
  value0 = ecl_memql(v1c,VV[555]);
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for LOCATION-FUNCTION-P                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L344location_function_p(cl_object v1x)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[105])(2, v1x, ecl_make_fixnum(2)) /*  LENGTH=N-P */)) { goto L2; }
  T0 = ecl_car(v1x);
  if (!((T0)==(ECL_SYM("FUNCTION",1241)))) { goto L2; }
  T0 = ecl_cadr(v1x);
  value0 = ecl_make_bool(ECL_SYMBOLP(T0));
  if ((value0)!=ECL_NIL) { goto L6; }
  T0 = ecl_cadr(v1x);
  if (!(ECL_CONSP(T0))) { goto L9; }
  T0 = ecl_caadr(v1x);
  if (!((T0)==(ECL_SYM("LAMBDA",452)))) { goto L9; }
  T0 = ecl_cadadr(v1x);
  value0 = ecl_function_dispatch(cl_env_copy,VV[105])(2, T0, ecl_make_fixnum(2)) /*  LENGTH=N-P */;
  return value0;
L9:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L6:;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for VALIDATE-OUTPUT-TRANSLATIONS-DIRECTIVE */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L345validate_output_translations_directive(cl_object v1directive)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ecl_eql(v1directive,VV[563]))) { goto L8; }
  value0 = VV[564];
  goto L6;
L8:;
  value0 = ECL_NIL;
  goto L6;
L6:;
  if ((value0)!=ECL_NIL) { goto L5; }
  if (!(ecl_eql(v1directive,VV[565]))) { goto L12; }
  value0 = VV[566];
  goto L10;
L12:;
  value0 = ECL_NIL;
  goto L10;
L10:;
  if ((value0)!=ECL_NIL) { goto L5; }
  if (!((v1directive)==(ECL_NIL))) { goto L15; }
  value0 = VV[43];
  goto L3;
L15:;
  value0 = ECL_NIL;
  goto L3;
L5:;
  goto L3;
L3:;
  if ((value0)!=ECL_NIL) { goto L2; }
  if (!(ECL_CONSP(v1directive))) { goto L18; }
  if (Null(ecl_function_dispatch(cl_env_copy,VV[105])(2, v1directive, ecl_make_fixnum(2)) /*  LENGTH=N-P */)) { goto L24; }
  T0 = ecl_car(v1directive);
  if (!((T0)==(ECL_SYM("INCLUDE",1249)))) { goto L30; }
  {
   cl_object v2;
   v2 = ecl_cadr(v1directive);
   value0 = ecl_make_bool(ECL_STRINGP(v2));
   if ((value0)!=ECL_NIL) { goto L34; }
   value0 = cl_pathnamep(v2);
   if ((value0)!=ECL_NIL) { goto L34; }
   value0 = ecl_make_bool(v2==ECL_NIL);
   goto L28;
L34:;
   goto L28;
  }
L30:;
  value0 = ECL_NIL;
  goto L28;
L28:;
  if ((value0)!=ECL_NIL) { goto L27; }
  T0 = ecl_car(v1directive);
  if (Null(ecl_function_dispatch(cl_env_copy,VV[554])(1, T0) /*  LOCATION-DESIGNATOR-P */)) { goto L38; }
  T0 = ecl_cadr(v1directive);
  value0 = ecl_function_dispatch(cl_env_copy,VV[554])(1, T0) /*  LOCATION-DESIGNATOR-P */;
  if ((value0)!=ECL_NIL) { goto L41; }
  T0 = ecl_cadr(v1directive);
  value0 = ecl_function_dispatch(cl_env_copy,VV[560])(1, T0) /*  LOCATION-FUNCTION-P */;
  goto L22;
L41:;
  goto L22;
L38:;
  value0 = ECL_NIL;
  goto L22;
L27:;
  goto L22;
L24:;
  value0 = ECL_NIL;
  goto L22;
L22:;
  if ((value0)!=ECL_NIL) { goto L21; }
  if (Null(ecl_function_dispatch(cl_env_copy,VV[105])(2, v1directive, ecl_make_fixnum(1)) /*  LENGTH=N-P */)) { goto L44; }
  T0 = ecl_car(v1directive);
  value0 = ecl_function_dispatch(cl_env_copy,VV[554])(1, T0) /*  LOCATION-DESIGNATOR-P */;
  return value0;
L44:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L21:;
  cl_env_copy->nvalues = 1;
  return value0;
L18:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for VALIDATE-OUTPUT-TRANSLATIONS-FORM     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L346validate_output_translations_form(cl_narg narg, cl_object v1form, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2location;
  ecl_va_list args; ecl_va_start(args,v1form,narg,1);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L346validate_output_translations_formkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v2location = keyvars[0];
  }
  value0 = ecl_function_dispatch(cl_env_copy,VV[503])(7, v1form, VV[569], VV[562], ECL_SYM("LOCATION",999), v2location, VV[570], VV[188]) /*  VALIDATE-CONFIGURATION-FORM */;
  return value0;
 }
}
/*	function definition for VALIDATE-OUTPUT-TRANSLATIONS-FILE     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L347validate_output_translations_file(cl_object v1file)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[510])(4, v1file, VV[568], ECL_SYM("DESCRIPTION",988), _ecl_static_119) /*  VALIDATE-CONFIGURATION-FILE */;
  return value0;
 }
}
/*	function definition for VALIDATE-OUTPUT-TRANSLATIONS-DIRECTORY */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L348validate_output_translations_directory(cl_object v1directory)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[516])(5, v1directory, VV[569], VV[562], VV[570], VV[188]) /*  VALIDATE-CONFIGURATION-DIRECTORY */;
  return value0;
 }
}
/*	function definition for PARSE-OUTPUT-TRANSLATIONS-STRING      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L349parse_output_translations_string(cl_narg narg, cl_object v1string, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2location;
  ecl_va_list args; ecl_va_start(args,v1string,narg,1);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L349parse_output_translations_stringkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v2location = keyvars[0];
  }
  if (v1string==ECL_NIL) { goto L3; }
  if (!(ecl_equal(v1string,_ecl_static_6))) { goto L1; }
  goto L2;
L3:;
L2:;
  value0 = VV[577];
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (ECL_STRINGP(v1string)) { goto L5; }
  value0 = cl_error(2, _ecl_static_120, v1string);
  return value0;
L5:;
  {
   ecl_character v3;
   v3 = ecl_char(v1string,0);
   if (!((v3)==((ecl_character)(34)))) { goto L7; }
  }
  T0 = cl_read_from_string(1, v1string);
  value0 = L349parse_output_translations_string(3, T0, ECL_SYM("LOCATION",999), v2location);
  return value0;
L7:;
  {
   ecl_character v3;
   v3 = ecl_char(v1string,0);
   if (!((v3)==((ecl_character)(40)))) { goto L9; }
  }
  T0 = cl_read_from_string(1, v1string);
  value0 = ecl_function_dispatch(cl_env_copy,VV[568])(3, T0, ECL_SYM("LOCATION",999), v2location) /*  VALIDATE-OUTPUT-TRANSLATIONS-FORM */;
  return value0;
L9:;
  {
   cl_object v3inherit;
   v3inherit = ECL_NIL;
   {
    cl_object v4directives;
    v4directives = ECL_NIL;
    {
     cl_object v5start;
     v5start = ecl_make_fixnum(0);
     {
      cl_fixnum v6end;
      v6end = ecl_length(v1string);
      {
       cl_object v7source;
       v7source = ECL_NIL;
       {
        cl_object v8separator;
        v8separator = L310inter_directory_separator();
        {
         cl_object v9i;
         v9i = ECL_NIL;
L18:;
         value0 = cl_position(4, v8separator, v1string, ECL_SYM("START",1310), v5start);
         if ((value0)!=ECL_NIL) { goto L22; }
         v9i = ecl_make_fixnum(v6end);
         goto L20;
L22:;
         v9i = value0;
         goto L20;
L20:;
         {
          cl_object v10s;
          v10s = cl_subseq(3, v1string, v5start, v9i);
          if (Null(v7source)) { goto L27; }
          if (!(ecl_equal(_ecl_static_6,v10s))) { goto L32; }
          T0 = ECL_NIL;
          goto L31;
L32:;
          T0 = v10s;
L31:;
          T1 = cl_list(2, v7source, T0);
          v4directives = CONS(T1,v4directives);
          v7source = ECL_NIL;
          goto L26;
L27:;
          if (!(ecl_equal(_ecl_static_6,v10s))) { goto L35; }
          if (Null(v3inherit)) { goto L37; }
          cl_error(2, _ecl_static_121, v1string);
L37:;
          v3inherit = ECL_T;
          v4directives = CONS(VV[507],v4directives);
          goto L26;
L35:;
          v7source = v10s;
L26:;
          v5start = ecl_one_plus(v9i);
          if (!(ecl_number_compare(v5start,ecl_make_fixnum(v6end))>0)) { goto L24; }
          if (Null(v7source)) { goto L46; }
          cl_error(2, _ecl_static_122, v1string);
L46:;
          if ((v3inherit)!=ECL_NIL) { goto L48; }
          v4directives = CONS(VV[508],v4directives);
L48:;
          T0 = cl_nreverse(v4directives);
          value0 = CONS(VV[569],T0);
          cl_env_copy->nvalues = 1;
          return value0;
         }
L24:;
         goto L18;
        }
       }
      }
     }
    }
   }
  }
 }
}
/*	function definition for WRAPPING-OUTPUT-TRANSLATIONS          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L350wrapping_output_translations()
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_translate_logical_pathname(1, _ecl_static_123);
  T1 = cl_list(2, T0, ECL_NIL);
  value0 = cl_listX(3, VV[569], T1, VV[581]);
  return value0;
 }
}
/*	function definition for USER-OUTPUT-TRANSLATIONS-PATHNAME     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L351user_output_translations_pathname(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1direction;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L351user_output_translations_pathnamekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[1])) {
    v1direction = ECL_SYM("INPUT",1254);
   } else {
    v1direction = keyvars[0];
   }
  }
  value0 = ecl_function_dispatch(cl_env_copy,VV[492])(3, ecl_symbol_value(VV[583]), ECL_SYM("DIRECTION",1218), v1direction) /*  IN-USER-CONFIGURATION-DIRECTORY */;
  return value0;
 }
}
/*	function definition for SYSTEM-OUTPUT-TRANSLATIONS-PATHNAME   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L352system_output_translations_pathname(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1direction;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L352system_output_translations_pathnamekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[1])) {
    v1direction = ECL_SYM("INPUT",1254);
   } else {
    v1direction = keyvars[0];
   }
  }
  value0 = ecl_function_dispatch(cl_env_copy,VV[494])(3, ecl_symbol_value(VV[583]), ECL_SYM("DIRECTION",1218), v1direction) /*  IN-SYSTEM-CONFIGURATION-DIRECTORY */;
  return value0;
 }
}
/*	function definition for USER-OUTPUT-TRANSLATIONS-DIRECTORY-PATHNAME */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L353user_output_translations_directory_pathname(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1direction;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L353user_output_translations_directory_pathnamekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[1])) {
    v1direction = ECL_SYM("INPUT",1254);
   } else {
    v1direction = keyvars[0];
   }
  }
  value0 = ecl_function_dispatch(cl_env_copy,VV[492])(3, ecl_symbol_value(VV[584]), ECL_SYM("DIRECTION",1218), v1direction) /*  IN-USER-CONFIGURATION-DIRECTORY */;
  return value0;
 }
}
/*	function definition for SYSTEM-OUTPUT-TRANSLATIONS-DIRECTORY-PATHNAME */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L354system_output_translations_directory_pathname(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1direction;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L354system_output_translations_directory_pathnamekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[1])) {
    v1direction = ECL_SYM("INPUT",1254);
   } else {
    v1direction = keyvars[0];
   }
  }
  value0 = ecl_function_dispatch(cl_env_copy,VV[494])(3, ecl_symbol_value(VV[584]), ECL_SYM("DIRECTION",1218), v1direction) /*  IN-SYSTEM-CONFIGURATION-DIRECTORY */;
  return value0;
 }
}
/*	function definition for ENVIRONMENT-OUTPUT-TRANSLATIONS       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L355environment_output_translations()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[84])(1, _ecl_static_126) /*  GETENV */;
  return value0;
 }
}
/*	local function G1236                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC356__g1236(cl_narg narg, cl_object v1x, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2inherit;
  cl_object v3collect;
  ecl_va_list args; ecl_va_start(args,v1x,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,LC356__g1236keys,keyvars,NULL,TRUE);
   ecl_va_end(args);
   if (Null(keyvars[2])) {
    v2inherit = ecl_symbol_value(VV[579]);
   } else {
    v2inherit = keyvars[0];
   }
   v3collect = keyvars[1];
  }
  T0 = ecl_function_dispatch(cl_env_copy,v1x)(0);
  value0 = ecl_function_dispatch(cl_env_copy,VV[595])(5, T0, VV[596], v2inherit, VV[597], v3collect) /*  PROCESS-OUTPUT-TRANSLATIONS */;
  return value0;
 }
}
/*	local function G1237                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC357__g1237(cl_narg narg, cl_object v1pathname, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2inherit;
  cl_object v3collect;
  ecl_va_list args; ecl_va_start(args,v1pathname,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,LC357__g1237keys,keyvars,NULL,TRUE);
   ecl_va_end(args);
   v2inherit = keyvars[0];
   v3collect = keyvars[1];
  }
  if (Null(ecl_function_dispatch(cl_env_copy,VV[86])(1, v1pathname) /*  DIRECTORY-PATHNAME-P */)) { goto L1; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[574])(1, v1pathname) /*  VALIDATE-OUTPUT-TRANSLATIONS-DIRECTORY */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[595])(5, T0, VV[596], v2inherit, VV[597], v3collect) /*  PROCESS-OUTPUT-TRANSLATIONS */;
  return value0;
L1:;
  if (Null(ecl_function_dispatch(cl_env_copy,VV[116])(1, v1pathname) /*  PROBE-FILE* */)) { goto L3; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[572])(1, v1pathname) /*  VALIDATE-OUTPUT-TRANSLATIONS-FILE */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[595])(5, T0, VV[596], v2inherit, VV[597], v3collect) /*  PROCESS-OUTPUT-TRANSLATIONS */;
  return value0;
L3:;
  value0 = L361inherit_output_translations(3, v2inherit, VV[597], v3collect);
  return value0;
 }
}
/*	local function G1238                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC358__g1238(cl_narg narg, cl_object v1string, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2inherit;
  cl_object v3collect;
  ecl_va_list args; ecl_va_start(args,v1string,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,LC358__g1238keys,keyvars,NULL,TRUE);
   ecl_va_end(args);
   v2inherit = keyvars[0];
   v3collect = keyvars[1];
  }
  T0 = ecl_function_dispatch(cl_env_copy,VV[576])(1, v1string) /*  PARSE-OUTPUT-TRANSLATIONS-STRING */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[595])(5, T0, VV[596], v2inherit, VV[597], v3collect) /*  PROCESS-OUTPUT-TRANSLATIONS */;
  return value0;
 }
}
/*	local function G1239                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC359__g1239(cl_narg narg, cl_object v1x, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2inherit;
  cl_object v3collect;
  ecl_va_list args; ecl_va_start(args,v1x,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,LC359__g1239keys,keyvars,NULL,TRUE);
   ecl_va_end(args);
   v2inherit = keyvars[0];
   v3collect = keyvars[1];
  }
  value0 = L361inherit_output_translations(3, v2inherit, VV[597], v3collect);
  return value0;
 }
}
/*	local function G1240                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC360__g1240(cl_narg narg, cl_object v1form, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2inherit;
  cl_object v3collect;
  ecl_va_list args; ecl_va_start(args,v1form,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,LC360__g1240keys,keyvars,NULL,TRUE);
   ecl_va_end(args);
   v2inherit = keyvars[0];
   v3collect = keyvars[1];
  }
  {
   cl_object v4;
   T0 = ecl_function_dispatch(cl_env_copy,VV[568])(1, v1form) /*  VALIDATE-OUTPUT-TRANSLATIONS-FORM */;
   v4 = ecl_cdr(T0);
   goto L4;
L3:;
   {
    cl_object v5directive;
    v5directive = ecl_car(v4);
    L362process_output_translations_directive(5, v5directive, VV[596], v2inherit, VV[597], v3collect);
   }
   v4 = ecl_cdr(v4);
L4:;
   if (Null(v4)) { goto L11; }
   goto L3;
L11:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for INHERIT-OUTPUT-TRANSLATIONS           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L361inherit_output_translations(cl_narg narg, cl_object v1inherit, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2collect;
  ecl_va_list args; ecl_va_start(args,v1inherit,narg,1);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L361inherit_output_translationskeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v2collect = keyvars[0];
  }
  if (Null(v1inherit)) { goto L1; }
  T0 = ecl_car(v1inherit);
  T1 = ecl_cdr(v1inherit);
  value0 = ecl_function_dispatch(cl_env_copy,VV[595])(5, T0, VV[597], v2collect, VV[596], T1) /*  PROCESS-OUTPUT-TRANSLATIONS */;
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for PROCESS-OUTPUT-TRANSLATIONS-DIRECTIVE */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L362process_output_translations_directive(cl_narg narg, cl_object v1directive, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2inherit;
  cl_object v3collect;
  ecl_va_list args; ecl_va_start(args,v1directive,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L362process_output_translations_directivekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v2inherit = keyvars[0];
   v3collect = keyvars[1];
  }
  if (!(ECL_ATOM(v1directive))) { goto L1; }
  if (!(ecl_eql(v1directive,VV[563]))) { goto L3; }
  value0 = L362process_output_translations_directive(3, VV[602], VV[597], v3collect);
  return value0;
L3:;
  if (!(ecl_eql(v1directive,VV[565]))) { goto L6; }
  value0 = L362process_output_translations_directive(3, VV[604], VV[597], v3collect);
  return value0;
L6:;
  if (!(ecl_eql(v1directive,VV[507]))) { goto L9; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[598])(3, v2inherit, VV[597], v3collect) /*  INHERIT-OUTPUT-TRANSLATIONS */;
  return value0;
L9:;
  if (!(ecl_eql(v1directive,VV[508]))) { goto L17; }
  goto L14;
  goto L15;
L17:;
  goto L15;
L15:;
  if (!(ecl_eql(v1directive,VV[505]))) { goto L21; }
  goto L14;
  goto L19;
L21:;
  goto L19;
L19:;
  if (!((v1directive)==(ECL_NIL))) { goto L12; }
  goto L13;
L14:;
L13:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L12:;
  value0 = si_ecase_error(v1directive, VV[607]);
  return value0;
L1:;
  {
   cl_object v4;
   cl_object v5;
   v4 = ecl_car(v1directive);
   v5 = ecl_cadr(v1directive);
   if (!((v4)==(ECL_SYM("INCLUDE",1249)))) { goto L26; }
   if (Null(v5)) { goto L28; }
   T0 = cl_pathname(v5);
   value0 = ecl_function_dispatch(cl_env_copy,VV[595])(5, T0, VV[596], ECL_NIL, VV[597], v3collect) /*  PROCESS-OUTPUT-TRANSLATIONS */;
   return value0;
L28:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L26:;
   if (Null(v4)) { goto L30; }
   {
    cl_object v6trusrc;
    value0 = ecl_make_bool(ecl_eql(v4,ECL_T));
    if ((value0)!=ECL_NIL) { goto L34; }
    {
     cl_object v7loc;
     v7loc = ecl_function_dispatch(cl_env_copy,VV[552])(5, v4, ECL_SYM("DIRECTORY",1219), ECL_T, VV[532], ECL_T) /*  RESOLVE-LOCATION */;
     if (Null(ecl_function_dispatch(cl_env_copy,VV[93])(1, v7loc) /*  ABSOLUTE-PATHNAME-P */)) { goto L37; }
     v6trusrc = ecl_function_dispatch(cl_env_copy,VV[119])(1, v7loc) /*  TRUENAMIZE */;
     goto L32;
L37:;
     v6trusrc = v7loc;
     goto L32;
    }
L34:;
    v6trusrc = value0;
    goto L32;
L32:;
    if (Null(ecl_function_dispatch(cl_env_copy,VV[560])(1, v5) /*  LOCATION-FUNCTION-P */)) { goto L39; }
    T1 = ecl_cadr(v5);
    if (!(ECL_SYMBOLP(T1))) { goto L42; }
    T1 = ecl_cadr(v5);
    T0 = cl_fdefinition(T1);
    goto L41;
L42:;
    T1 = ecl_cadr(v5);
    T0 = cl_eval(T1);
L41:;
    T1 = cl_list(2, v6trusrc, T0);
    value0 = ecl_function_dispatch(cl_env_copy,v3collect)(1, T1);
    return value0;
L39:;
    if (!((v5)==(ECL_T))) { goto L44; }
    T0 = cl_list(2, v6trusrc, ECL_T);
    value0 = ecl_function_dispatch(cl_env_copy,v3collect)(1, T0);
    return value0;
L44:;
    {
     cl_object v7trudst;
     cl_object v8wilddst;
     if (Null(v5)) { goto L47; }
     v7trudst = ecl_function_dispatch(cl_env_copy,VV[552])(5, v5, ECL_SYM("DIRECTORY",1219), ECL_T, VV[532], ECL_T) /*  RESOLVE-LOCATION */;
     goto L46;
L47:;
     v7trudst = v6trusrc;
L46:;
     v8wilddst = ecl_function_dispatch(cl_env_copy,VV[51])(2, ecl_symbol_value(VV[133]), v7trudst) /*  MERGE-PATHNAMES* */;
     T0 = cl_list(2, v8wilddst, ECL_T);
     ecl_function_dispatch(cl_env_copy,v3collect)(1, T0);
     T0 = cl_list(2, v6trusrc, v7trudst);
     value0 = ecl_function_dispatch(cl_env_copy,v3collect)(1, T0);
     return value0;
    }
   }
L30:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for COMPUTE-OUTPUT-TRANSLATIONS           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L364compute_output_translations(cl_narg narg, ...)
{
 cl_object T0, T1;
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1parameter;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1parameter = ECL_NIL;
   } else {
    i++;
    v1parameter = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object env1 = env0;
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(ECL_NIL,env1);
   {cl_object v2;
    v2 = ECL_NIL;
    v2 = ecl_make_cclosure_va((cl_objectfn)LC363c,env1,Cblock);
    T1 = cl_listX(3, VV[580], v1parameter, ecl_symbol_value(VV[579]));
    ecl_function_dispatch(cl_env_copy,VV[598])(3, T1, VV[597], v2) /*  INHERIT-OUTPUT-TRANSLATIONS */;
    T0 = cl_reverse(ECL_CONS_CAR(CLV0));
   }
  }
  value0 = cl_remove_duplicates(5, T0, ECL_SYM("TEST",1316), ECL_SYM("EQUAL",335), VV[15], ECL_T);
  return value0;
 }
}
/*	closure C                                                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC363c(cl_narg narg, cl_object v1x, ...)
{
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  ECL_CONS_CAR(CLV0) = CONS(v1x,ECL_CONS_CAR(CLV0));
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  return value0;
 }
 }
}
/*	function definition for INITIALIZE-OUTPUT-TRANSLATIONS        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L365initialize_output_translations(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1parameter;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1parameter = ecl_symbol_value(VV[611]);
   } else {
    i++;
    v1parameter = va_arg(args,cl_object);
   }
  }
  va_end(args);
  cl_set(VV[611],v1parameter);
  {
   cl_object v2;
   v2 = ecl_function_dispatch(cl_env_copy,VV[609])(1, v1parameter) /*  COMPUTE-OUTPUT-TRANSLATIONS */;
   value0 = L335_setf_output_translations_(v2);
   return value0;
  }
 }
}
/*	function definition for DISABLE-OUTPUT-TRANSLATIONS           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L366disable_output_translations()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[612])(1, VV[615]) /*  INITIALIZE-OUTPUT-TRANSLATIONS */;
  return value0;
 }
}
/*	function definition for ENSURE-OUTPUT-TRANSLATIONS            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L367ensure_output_translations()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[527])(0) /*  OUTPUT-TRANSLATIONS-INITIALIZED-P */)) { goto L1; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[522])(0) /*  OUTPUT-TRANSLATIONS */;
  return value0;
L1:;
  value0 = ecl_function_dispatch(cl_env_copy,VV[612])(0) /*  INITIALIZE-OUTPUT-TRANSLATIONS */;
  return value0;
 }
}
/*	function definition for TRANSLATE-PATHNAME*                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L368translate_pathname_(cl_narg narg, cl_object v1path, cl_object v2absolute_source, cl_object v3destination, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>5)) FEwrong_num_arguments_anonym();
 {
  cl_object v4root;
  cl_object v5source;
  va_list args; va_start(args,v3destination);
  {
   int i = 3;
   if (i >= narg) {
    v4root = ECL_NIL;
   } else {
    i++;
    v4root = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v5source = ECL_NIL;
   } else {
    i++;
    v5source = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (Null(cl_functionp(v3destination))) { goto L3; }
  value0 = ecl_function_dispatch(cl_env_copy,v3destination)(2, v1path, v2absolute_source);
  return value0;
L3:;
  if (!((v3destination)==(ECL_T))) { goto L5; }
  value0 = v1path;
  cl_env_copy->nvalues = 1;
  return value0;
L5:;
  if ((cl_pathnamep(v3destination))!=ECL_NIL) { goto L7; }
  value0 = cl_error(1, _ecl_static_127);
  return value0;
L7:;
  if ((ecl_function_dispatch(cl_env_copy,VV[93])(1, v3destination) /*  ABSOLUTE-PATHNAME-P */)!=ECL_NIL) { goto L9; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[51])(2, v3destination, v4root) /*  MERGE-PATHNAMES* */;
  value0 = cl_translate_pathname(3, v1path, v2absolute_source, T0);
  return value0;
L9:;
  if (Null(v4root)) { goto L11; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[142])(1, v1path) /*  DIRECTORIZE-PATHNAME-HOST-DEVICE */;
  value0 = cl_translate_pathname(3, T0, v2absolute_source, v3destination);
  return value0;
L11:;
  value0 = cl_translate_pathname(3, v1path, v2absolute_source, v3destination);
  return value0;
 }
}
/*	function definition for APPLY-OUTPUT-TRANSLATIONS             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L369apply_output_translations(cl_object v1path)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(si_logical_pathname_p(v1path))) { goto L1; }
  value0 = v1path;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if ((cl_pathnamep(v1path))!=ECL_NIL) { goto L5; }
  if (!(ECL_STRINGP(v1path))) { goto L3; }
  goto L4;
L5:;
L4:;
  ecl_function_dispatch(cl_env_copy,VV[617])(0)   /*  ENSURE-OUTPUT-TRANSLATIONS */;
  {
   cl_object v2p;
   v2p = ecl_function_dispatch(cl_env_copy,VV[119])(1, v1path) /*  TRUENAMIZE */;
   {
    cl_object v3;
    cl_object v4source;
    cl_object v5destination;
    cl_object v6;
    v3 = ecl_car(ecl_symbol_value(VV[519]));
    v4source = ECL_NIL;
    v5destination = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v3))) FEtype_error_list(v3);
    v6 = v3;
    {
     cl_object v7root;
     v7root = ECL_NIL;
     {
      cl_object v8absolute_source;
      v8absolute_source = ECL_NIL;
L16:;
      if (!(ecl_endp(v6))) { goto L18; }
      goto L17;
L18:;
      {
       cl_object v9;
       v9 = _ecl_car(v6);
       v4source = ecl_car(v9);
       v9 = ecl_cdr(v9);
       v5destination = ecl_car(v9);
      }
      {
       cl_object v9;
       v9 = _ecl_cdr(v6);
       if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
       v6 = v9;
      }
      if ((v4source)==(ECL_T)) { goto L35; }
      if (Null(cl_pathnamep(v4source))) { goto L33; }
      if ((ecl_function_dispatch(cl_env_copy,VV[93])(1, v4source) /*  ABSOLUTE-PATHNAME-P */)!=ECL_NIL) { goto L33; }
      goto L34;
L35:;
L34:;
      v7root = ecl_function_dispatch(cl_env_copy,VV[114])(1, v2p) /*  PATHNAME-ROOT */;
      goto L32;
L33:;
      v7root = ECL_NIL;
L32:;
      if (!((v4source)==(ECL_T))) { goto L40; }
      v8absolute_source = ecl_function_dispatch(cl_env_copy,VV[137])(1, v7root) /*  WILDEN */;
      goto L39;
L40:;
      if (Null(v7root)) { goto L42; }
      v8absolute_source = ecl_function_dispatch(cl_env_copy,VV[51])(2, v4source, v7root) /*  MERGE-PATHNAMES* */;
      goto L39;
L42:;
      v8absolute_source = v4source;
L39:;
      if ((v4source)==(ECL_T)) { goto L46; }
      if (Null(cl_pathname_match_p(v2p, v8absolute_source))) { goto L44; }
      goto L45;
L46:;
L45:;
      value0 = ecl_function_dispatch(cl_env_copy,VV[619])(5, v2p, v8absolute_source, v5destination, v7root, v4source) /*  TRANSLATE-PATHNAME* */;
      return value0;
L44:;
      goto L16;
L17:;
      value0 = v2p;
      cl_env_copy->nvalues = 1;
      return value0;
     }
    }
   }
  }
L3:;
  value0 = si_etypecase_error(v1path, VV[622]);
  return value0;
 }
}
/*	local function G1262                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC370__g1262(cl_object v1operation, cl_object v2component)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4;                                  /*  FILES           */
   cl_object v5;                                  /*  FIXEDP          */
   if (Null(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)))) { goto L5; }
   T1 = ecl_car(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
   T2 = ecl_cdr(ecl_symbol_value(ECL_SYM("*NEXT-METHODS*",1475)));
   value0 = ecl_function_dispatch(cl_env_copy,T1)(2, ecl_symbol_value(ECL_SYM(".COMBINED-METHOD-ARGS.",1473)), T2);
   goto L4;
L5:;
   value0 = cl_error(1, _ecl_static_36);
L4:;
   v4 = value0;
   {
    const int v6 = cl_env_copy->nvalues;
    cl_object v7;
    v7 = (v6<=1)? ECL_NIL : cl_env_copy->values[1];
    v5 = v7;
   }
   if (Null(v5)) { goto L8; }
   T0 = v4;
   goto L3;
L8:;
   {
    cl_object v6;
    cl_object v7;
    v6 = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
    v7 = v4;
    {
     cl_object v8;
     cl_object v9;
     v8 = ecl_list1(ECL_NIL);
     v9 = v8;
L15:;
     if (!(ecl_endp(v7))) { goto L17; }
     goto L16;
L17:;
     v6 = _ecl_car(v7);
     {
      cl_object v10;
      v10 = _ecl_cdr(v7);
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      v7 = v10;
     }
     if (ecl_unlikely(ECL_ATOM(v9))) FEtype_error_cons(v9);
     T1 = v9;
     T2 = ecl_function_dispatch(cl_env_copy,VV[621])(1, v6) /*  APPLY-OUTPUT-TRANSLATIONS */;
     v9 = ecl_list1(T2);
     (ECL_CONS_CDR(T1)=v9,T1);
     goto L15;
L16:;
     T0 = ecl_cdr(v8);
     goto L3;
    }
   }
  }
L3:;
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = ECL_T;
  cl_env_copy->values[0] = T0;
  return cl_env_copy->values[0];
 }
}
/*	function definition for COMPILE-FILE-PATHNAME*                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L371compile_file_pathname_(cl_narg narg, cl_object v1input_file, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2keys;
  cl_object v3output_file;
  ecl_va_list args; ecl_va_start(args,v1input_file,narg,1);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L371compile_file_pathname_keys,keyvars,(cl_object*)&v2keys,TRUE);
   ecl_va_end(args);
   v3output_file = keyvars[0];
  }
  if (Null(ecl_function_dispatch(cl_env_copy,VV[93])(1, v3output_file) /*  ABSOLUTE-PATHNAME-P */)) { goto L1; }
  {
   cl_object v4type;
   cl_object v5defaults;
   T0 = cl_apply(3, ECL_SYM("COMPILE-FILE-PATHNAME",235), _ecl_static_129, v2keys);
   v4type = cl_pathname_type(1, T0);
   T0 = ecl_function_dispatch(cl_env_copy,VV[51])(1, v1input_file) /*  MERGE-PATHNAMES* */;
   v5defaults = cl_make_pathname(4, ECL_SYM("TYPE",1318), v4type, ECL_SYM("DEFAULTS",1216), T0);
   value0 = ecl_function_dispatch(cl_env_copy,VV[51])(2, v3output_file, v5defaults) /*  MERGE-PATHNAMES* */;
   return value0;
  }
L1:;
  if (Null(v3output_file)) { goto L6; }
  T0 = v2keys;
  goto L5;
L6:;
  T0 = ecl_function_dispatch(cl_env_copy,VV[82])(2, VV[353], v2keys) /*  REMOVE-KEYWORD */;
L5:;
  T1 = cl_apply(3, ECL_SYM("COMPILE-FILE-PATHNAME",235), v1input_file, T0);
  value0 = ecl_function_dispatch(cl_env_copy,VV[621])(1, T1) /*  APPLY-OUTPUT-TRANSLATIONS */;
  return value0;
 }
}
/*	function definition for TMPIZE-PATHNAME                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L372tmpize_pathname(cl_object v1x)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_pathname_name(1, v1x);
  T1 = L3strcat(2, _ecl_static_130, T0);
  value0 = cl_make_pathname(4, ECL_SYM("NAME",1273), T1, ECL_SYM("DEFAULTS",1216), v1x);
  return value0;
 }
}
/*	function definition for DELETE-FILE-IF-EXISTS                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L373delete_file_if_exists(cl_object v1x)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1x)) { goto L1; }
  if (Null(ecl_function_dispatch(cl_env_copy,VV[116])(1, v1x) /*  PROBE-FILE* */)) { goto L1; }
  value0 = cl_delete_file(v1x);
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for COMPILE-FILE*                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L374compile_file_(cl_narg narg, cl_object v1input_file, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2keys;
  cl_object v3compile_check;
  cl_object v4output_file;
  ecl_va_list args; ecl_va_start(args,v1input_file,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L374compile_file_keys,keyvars,(cl_object*)&v2keys,TRUE);
   ecl_va_end(args);
   v3compile_check = keyvars[0];
   v4output_file = keyvars[1];
  }
  {
   cl_object v5keywords;
   cl_object v6output_file;
   cl_object v7tmp_file;
   cl_object v8status;
   v5keywords = ecl_function_dispatch(cl_env_copy,VV[82])(2, VV[630], v2keys) /*  REMOVE-KEYWORD */;
   v6output_file = cl_apply(5, VV[624], v1input_file, VV[353], v4output_file, v5keywords);
   v7tmp_file = ecl_function_dispatch(cl_env_copy,VV[626])(1, v6output_file) /*  TMPIZE-PATHNAME */;
   v8status = ECL_SYM("ERROR",1229);
   {
    cl_object v10;                                /*  OUTPUT-TRUENAME */
    cl_object v11;                                /*  WARNINGS-P      */
    cl_object v12;                                /*  FAILURE-P       */
    value0 = cl_apply(5, ECL_SYM("COMPILE-FILE",234), v1input_file, VV[353], v7tmp_file, v5keywords);
    v10 = value0;
    {
     const int v13 = cl_env_copy->nvalues;
     cl_object v14;
     v14 = (v13<=1)? ECL_NIL : cl_env_copy->values[1];
     v11 = v14;
     v14 = (v13<=2)? ECL_NIL : cl_env_copy->values[2];
     v12 = v14;
    }
    if (Null(v12)) { goto L7; }
    v8status = ecl_symbol_value(VV[21]);
    goto L6;
L7:;
    if (Null(v11)) { goto L10; }
    v8status = ecl_symbol_value(VV[19]);
    goto L6;
L10:;
    v8status = VV[631];
L6:;
    if (!(ecl_eql(v8status,VV[631]))) { goto L23; }
    goto L20;
    goto L21;
L23:;
    goto L21;
L21:;
    if (!(ecl_eql(v8status,VV[20]))) { goto L27; }
    goto L20;
    goto L25;
L27:;
    goto L25;
L25:;
    if (!(ecl_eql(v8status,ECL_SYM("IGNORE",1247)))) { goto L18; }
    goto L19;
L20:;
L19:;
    goto L17;
L18:;
    if (!(ecl_eql(v8status,ECL_SYM("ERROR",1229)))) { goto L35; }
    goto L32;
    goto L33;
L35:;
    goto L33;
L33:;
    if (!((v8status)==(ECL_NIL))) { goto L30; }
    goto L31;
L32:;
L31:;
    goto L15;
L30:;
    if (Null(si_ecase_error(v8status, VV[636]))) { goto L15; }
L17:;
    if (Null(v3compile_check)) { goto L38; }
    if (Null(cl_apply(5, v3compile_check, v1input_file, VV[353], v7tmp_file, v5keywords))) { goto L15; }
    goto L16;
L38:;
L16:;
    ecl_function_dispatch(cl_env_copy,VV[628])(1, v6output_file) /*  DELETE-FILE-IF-EXISTS */;
    if (Null(v10)) { goto L14; }
    cl_rename_file(2, v10, v6output_file);
    v10 = v6output_file;
    goto L14;
L15:;
    ecl_function_dispatch(cl_env_copy,VV[628])(1, v10) /*  DELETE-FILE-IF-EXISTS */;
    v10 = ECL_NIL;
    v12 = ECL_T;
L14:;
    cl_env_copy->nvalues = 3;
    cl_env_copy->values[2] = v12;
    cl_env_copy->values[1] = v11;
    cl_env_copy->values[0] = v10;
    return cl_env_copy->values[0];
   }
  }
 }
}
/*	local function G1279                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC375__g1279(cl_narg narg, cl_object v1operation_class, cl_object v2system, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  ecl_va_list args; ecl_va_start(args,v2system,narg,2);
  cl_parse_key(args,0,NULL,NULL,NULL,TRUE);
  ecl_va_end(args);
  if (Null(L2find_symbol_(VV[638], VV[1]))) { goto L1; }
  value0 = cl_error(1, _ecl_static_131);
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for ENABLE-ASDF-BINARY-LOCATIONS-COMPATIBILITY */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L376enable_asdf_binary_locations_compatibility(cl_narg narg, ...)
{
 cl_object T0, T1, T2, T3, T4, T5, T6;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1centralize_lisp_binaries;
  cl_object v2default_toplevel_directory;
  cl_object v3include_per_user_information;
  cl_object v4map_all_source_files;
  cl_object v5source_to_target_mappings;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  {
   cl_object keyvars[10];
   cl_parse_key(args,5,L376enable_asdf_binary_locations_compatibilitykeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v1centralize_lisp_binaries = keyvars[0];
   if (Null(keyvars[6])) {
    T0 = ecl_function_dispatch(cl_env_copy,VV[457])(0) /*  USER-HOMEDIR */;
    v2default_toplevel_directory = ecl_function_dispatch(cl_env_copy,VV[102])(2, T0, _ecl_static_132) /*  SUBPATHNAME */;
   } else {
    v2default_toplevel_directory = keyvars[1];
   }
   v3include_per_user_information = keyvars[2];
   if (Null(keyvars[8])) {
    value0 = ECL_T;
    if ((value0)!=ECL_NIL) { goto L4; }
    v4map_all_source_files = ECL_NIL;
    goto L2;
L4:;
    v4map_all_source_files = value0;
    goto L2;
L2:;
   } else {
    v4map_all_source_files = keyvars[3];
   }
   v5source_to_target_mappings = keyvars[4];
  }
  if (!(v4map_all_source_files==ECL_NIL)) { goto L6; }
  cl_error(1, _ecl_static_133);
L6:;
  {
   cl_object v6fasl_type;
   cl_object v7mapped_files;
   cl_object v8destination_directory;
   T0 = (cl_env_copy->function=(ECL_SYM("COMPILE-FILE-PATHNAME",235)->symbol.gfdef))->cfun.entry(1, _ecl_static_134) /*  COMPILE-FILE-PATHNAME */;
   v6fasl_type = cl_pathname_type(1, T0);
   if (Null(v4map_all_source_files)) { goto L10; }
   v7mapped_files = ecl_symbol_value(VV[133]);
   goto L9;
L10:;
   v7mapped_files = cl_make_pathname(4, ECL_SYM("TYPE",1318), v6fasl_type, ECL_SYM("DEFAULTS",1216), ecl_symbol_value(VV[133]));
L9:;
   if (Null(v1centralize_lisp_binaries)) { goto L13; }
   if (Null(v3include_per_user_information)) { goto L16; }
   T1 = ecl_function_dispatch(cl_env_copy,VV[457])(0) /*  USER-HOMEDIR */;
   T2 = cl_pathname_directory(1, T1);
   T0 = ecl_cdr(T2);
   goto L15;
L16:;
   T0 = ECL_NIL;
L15:;
   T1 = cl_list(2, VV[521], ecl_symbol_value(VV[135]));
   T2 = ecl_append(T0,T1);
   v8destination_directory = CONS(v2default_toplevel_directory,T2);
   goto L12;
L13:;
   v8destination_directory = cl_list(3, VV[640], ecl_symbol_value(VV[135]), VV[521]);
L12:;
   T0 = cl_list(3, VV[640], ecl_symbol_value(VV[135]), v7mapped_files);
   T1 = ecl_list1(v7mapped_files);
   T2 = ecl_append(v8destination_directory,T1);
   T3 = cl_list(2, T0, T2);
   T4 = CONS(T3,VV[641]);
   T5 = ecl_append(v5source_to_target_mappings,T4);
   T6 = CONS(VV[569],T5);
   value0 = ecl_function_dispatch(cl_env_copy,VV[612])(1, T6) /*  INITIALIZE-OUTPUT-TRANSLATIONS */;
   return value0;
  }
 }
}
/*	function definition for SOURCE-REGISTRY-INITIALIZED-P         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L377source_registry_initialized_p()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_hash_table_p(ecl_symbol_value(VV[645]));
  return value0;
 }
}
/*	function definition for CLEAR-SOURCE-REGISTRY                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L378clear_source_registry()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  cl_set(VV[645],ECL_NIL);
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  return value0;
 }
}
/*	function definition for FILTER-LOGICAL-DIRECTORY-RESULTS      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L381filter_logical_directory_results(cl_object volatile v1directory, cl_object volatile v2entries, cl_object volatile v3merger)
{
 cl_object T0, T1, T2, T3, T4;
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(si_logical_pathname_p(v1directory))) { goto L1; }
  {
   volatile cl_object v4f;
   volatile cl_object v5;
   v4f = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v2entries))) FEtype_error_list(v2entries);
   v5 = v2entries;
   {
    volatile cl_object v6p;
    v6p = ECL_NIL;
    {
     volatile cl_object v7;
     volatile cl_object v8;
     v7 = ecl_list1(ECL_NIL);
     v8 = v7;
L9:;
     if (!(ecl_endp(v5))) { goto L11; }
     goto L10;
L11:;
     v4f = _ecl_car(v5);
     {
      cl_object v9;
      v9 = _ecl_cdr(v5);
      if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
      v5 = v9;
     }
     if (Null(si_logical_pathname_p(v4f))) { goto L25; }
     value0 = v4f;
     goto L23;
L25:;
     value0 = ECL_NIL;
     goto L23;
L23:;
     if ((value0)!=ECL_NIL) { goto L22; }
     {
      volatile cl_object v9u;
      {
       volatile cl_object env1 = env0;
       env1 = ECL_NIL;
       CLV0 = env1 = CONS(ECL_NIL,env1);
       {
        volatile cl_object env2 = env1;
        CLV1 = env2 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env2); /*  TAGBODY */
        if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV1))) {
        if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L28;
        ecl_internal_error("GO found an inexistent tag");
        }
        {cl_object v10;
         v10 = ECL_NIL;
         v10 = ecl_make_cclosure_va((cl_objectfn)LC379__g1289,env2,Cblock);
         T0 = v10;
        }
        T1 = CONS(ECL_SYM("ERROR",337),T0);
        T2 = ecl_list1(T1);
        T3 = CONS(T2,ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5)));
        ecl_bds_bind(cl_env_copy,ECL_SYM("*HANDLER-CLUSTERS*",5),T3); /*  *HANDLER-CLUSTERS* */
        value0 = ecl_function_dispatch(cl_env_copy,v3merger)(1, v4f);
        ecl_frs_pop(cl_env_copy);
        v9u = value0;
        ecl_bds_unwind1(cl_env_copy);
        goto L27;
L28:;
        {
         cl_object v10condition;
         v10condition = ECL_CONS_CAR(CLV0);
         cl_env_copy->nvalues = 2;
         cl_env_copy->values[1] = v10condition;
         cl_env_copy->values[0] = ECL_NIL;
         value0 = cl_env_copy->values[0];
         ecl_frs_pop(cl_env_copy);
         v9u = value0;
         goto L27;
        }
       }
      }
L27:;
      if (Null(v9u)) { goto L34; }
      {
       volatile cl_object env1 = env0;
       env1 = ECL_NIL;
       CLV0 = env1 = CONS(ECL_NIL,env1);
       {
        volatile cl_object env2 = env1;
        CLV1 = env2 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env2); /*  TAGBODY */
        if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV1))) {
        if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L38;
        ecl_internal_error("GO found an inexistent tag");
        }
        {cl_object v10;
         v10 = ECL_NIL;
         v10 = ecl_make_cclosure_va((cl_objectfn)LC380__g1293,env2,Cblock);
         T1 = v10;
        }
        T2 = CONS(ECL_SYM("ERROR",337),T1);
        T3 = ecl_list1(T2);
        T4 = CONS(T3,ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5)));
        ecl_bds_bind(cl_env_copy,ECL_SYM("*HANDLER-CLUSTERS*",5),T4); /*  *HANDLER-CLUSTERS* */
        value0 = cl_truename(v9u);
        ecl_frs_pop(cl_env_copy);
        T0 = value0;
        ecl_bds_unwind1(cl_env_copy);
        goto L37;
L38:;
        {
         cl_object v10condition;
         v10condition = ECL_CONS_CAR(CLV0);
         cl_env_copy->nvalues = 2;
         cl_env_copy->values[1] = v10condition;
         cl_env_copy->values[0] = ECL_NIL;
         value0 = cl_env_copy->values[0];
         ecl_frs_pop(cl_env_copy);
         T0 = value0;
         goto L37;
        }
       }
      }
L37:;
      T1 = cl_truename(v4f);
      if (!(ecl_equal(T0,T1))) { goto L34; }
      v6p = v9u;
      goto L20;
L34:;
      v6p = ECL_NIL;
      goto L20;
     }
L22:;
     v6p = value0;
     goto L20;
L20:;
     if (Null(v6p)) { goto L43; }
     if (ecl_unlikely(ECL_ATOM(v8))) FEtype_error_cons(v8);
     T0 = v8;
     v8 = ecl_list1(v6p);
     (ECL_CONS_CDR(T0)=v8,T0);
L43:;
     goto L9;
L10:;
     value0 = ecl_cdr(v7);
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
  }
L1:;
  value0 = v2entries;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	closure G1289                                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC379__g1289(cl_narg narg, cl_object v1si__temp, ...)
{
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  TAGBODY         */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  ECL_CONS_CAR(CLV0) = v1si__temp;
  cl_go(ECL_CONS_CAR(CLV1),ecl_make_fixnum(0));
 }
 }
}
/*	closure G1293                                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC380__g1293(cl_narg narg, cl_object v1si__temp, ...)
{
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  TAGBODY         */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  ECL_CONS_CAR(CLV0) = v1si__temp;
  cl_go(ECL_CONS_CAR(CLV1),ecl_make_fixnum(0));
 }
 }
}
/*	function definition for DIRECTORY-FILES                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L384directory_files(volatile cl_narg narg, cl_object volatile v1directory, ...)
{
 cl_object T0, T1, T2, T3;
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1, CLV2
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  volatile cl_object v2pattern;
  va_list args; va_start(args,v1directory);
  {
   int i = 1;
   if (i >= narg) {
    v2pattern = ecl_symbol_value(VV[133]);
   } else {
    i++;
    v2pattern = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   volatile cl_object env1 = env0;
   T0 = cl_pathname(v1directory);
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(T0,env1);                   /*  DIR             */
   if (Null(si_logical_pathname_p(ECL_CONS_CAR(CLV0)))) { goto L2; }
   if (Null(cl_wild_pathname_p(1, ECL_CONS_CAR(CLV0)))) { goto L4; }
   cl_error(2, _ecl_static_136, v1directory);
L4:;
   {
    cl_object v3;
    v3 = cl_pathname_directory(1, v2pattern);
    if (Null(ecl_function_dispatch(cl_env_copy,ECL_SYM("EQUAL",335))(2, v3, ECL_NIL))) { goto L11; }
    goto L6;
    goto L9;
L11:;
    goto L9;
L9:;
    if (Null(ecl_function_dispatch(cl_env_copy,ECL_SYM("EQUAL",335))(2, v3, VV[40]))) { goto L14; }
    goto L6;
    goto L7;
L14:;
    goto L7;
   }
L7:;
   cl_error(3, _ecl_static_137, v2pattern, v1directory);
L6:;
   T0 = cl_pathname_host(1, ECL_CONS_CAR(CLV0));
   v2pattern = ecl_function_dispatch(cl_env_copy,VV[49])(2, v2pattern, T0) /*  MAKE-PATHNAME-LOGICAL */;
L2:;
   {
    volatile cl_object v3entries;
    {
     volatile cl_object env2 = env1;
     CLV1 = env2 = CONS(ECL_NIL,env2);
     {
      volatile cl_object env3 = env2;
      CLV2 = env3 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env3); /*  TAGBODY */
      if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV2))) {
      if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L18;
      ecl_internal_error("GO found an inexistent tag");
      }
      {cl_object v4;
       v4 = ECL_NIL;
       v4 = ecl_make_cclosure_va((cl_objectfn)LC382__g1299,env3,Cblock);
       T0 = v4;
      }
      T1 = CONS(ECL_SYM("ERROR",337),T0);
      T2 = ecl_list1(T1);
      T3 = CONS(T2,ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5)));
      ecl_bds_bind(cl_env_copy,ECL_SYM("*HANDLER-CLUSTERS*",5),T3); /*  *HANDLER-CLUSTERS* */
      T0 = ecl_function_dispatch(cl_env_copy,VV[51])(2, v2pattern, ECL_CONS_CAR(CLV0)) /*  MERGE-PATHNAMES* */;
      value0 = ecl_function_dispatch(cl_env_copy,VV[514])(1, T0) /*  DIRECTORY* */;
      ecl_frs_pop(cl_env_copy);
      v3entries = value0;
      ecl_bds_unwind1(cl_env_copy);
      goto L17;
L18:;
      {
       cl_object v4condition;
       v4condition = ECL_CONS_CAR(CLV1);
       cl_env_copy->nvalues = 2;
       cl_env_copy->values[1] = v4condition;
       cl_env_copy->values[0] = ECL_NIL;
       value0 = cl_env_copy->values[0];
       ecl_frs_pop(cl_env_copy);
       v3entries = value0;
       goto L17;
      }
     }
    }
L17:;
    {cl_object v4;
     v4 = ECL_NIL;
     v4 = ecl_make_cclosure_va((cl_objectfn)LC383__g1300,env1,Cblock);
     T0 = v4;
    }
    value0 = ecl_function_dispatch(cl_env_copy,VV[651])(3, v1directory, v3entries, T0) /*  FILTER-LOGICAL-DIRECTORY-RESULTS */;
    return value0;
   }
  }
 }
}
/*	closure G1299                                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC382__g1299(cl_narg narg, cl_object v1si__temp, ...)
{
 cl_object CLV0, CLV1, CLV2
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV2 = env0;                                     /*  TAGBODY         */
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  ECL_CONS_CAR(CLV1) = v1si__temp;
  cl_go(ECL_CONS_CAR(CLV2),ecl_make_fixnum(0));
 }
 }
}
/*	closure G1300                                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC383__g1300(cl_narg narg, cl_object v1f, ...)
{
 cl_object T0, T1, T2, T3, T4, T5;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  DIR             */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  T0 = cl_pathname_name(1, v1f);
  T1 = ecl_function_dispatch(cl_env_copy,VV[46])(1, T0) /*  MAKE-PATHNAME-COMPONENT-LOGICAL */;
  T2 = cl_pathname_type(1, v1f);
  T3 = ecl_function_dispatch(cl_env_copy,VV[46])(1, T2) /*  MAKE-PATHNAME-COMPONENT-LOGICAL */;
  T4 = cl_pathname_version(v1f);
  T5 = ecl_function_dispatch(cl_env_copy,VV[46])(1, T4) /*  MAKE-PATHNAME-COMPONENT-LOGICAL */;
  value0 = cl_make_pathname(8, ECL_SYM("DEFAULTS",1216), ECL_CONS_CAR(CLV0), ECL_SYM("NAME",1273), T1, ECL_SYM("TYPE",1318), T3, ECL_SYM("VERSION",1326), T5);
  return value0;
 }
 }
}
/*	function definition for DIRECTORY-ASD-FILES                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L385directory_asd_files(cl_object v1directory)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[653])(2, v1directory, ecl_symbol_value(VV[650])) /*  DIRECTORY-FILES */;
  return value0;
 }
}
/*	function definition for SUBDIRECTORIES                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L388subdirectories(cl_object volatile v1directory)
{
 cl_object T0, T1, T2, T3;
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1, CLV2
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   volatile cl_object v2wild;
   volatile cl_object v3dirs;
   volatile cl_object env1 = env0;
   T0 = ecl_function_dispatch(cl_env_copy,VV[91])(1, v1directory) /*  ENSURE-DIRECTORY-PATHNAME */;
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(T0,env1);                   /*  DIRECTORY       */
   v2wild = ecl_function_dispatch(cl_env_copy,VV[51])(2, ecl_symbol_value(VV[134]), ECL_CONS_CAR(CLV0)) /*  MERGE-PATHNAMES* */;
   {
    volatile cl_object env2 = env1;
    CLV1 = env2 = CONS(ECL_NIL,env2);
    {
     volatile cl_object env3 = env2;
     CLV2 = env3 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env3); /*  TAGBODY */
     if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV2))) {
     if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L3;
     ecl_internal_error("GO found an inexistent tag");
     }
     {cl_object v4;
      v4 = ECL_NIL;
      v4 = ecl_make_cclosure_va((cl_objectfn)LC386__g1304,env3,Cblock);
      T0 = v4;
     }
     T1 = CONS(ECL_SYM("ERROR",337),T0);
     T2 = ecl_list1(T1);
     T3 = CONS(T2,ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5)));
     ecl_bds_bind(cl_env_copy,ECL_SYM("*HANDLER-CLUSTERS*",5),T3); /*  *HANDLER-CLUSTERS* */
     value0 = ecl_function_dispatch(cl_env_copy,VV[514])(1, v2wild) /*  DIRECTORY* */;
     ecl_frs_pop(cl_env_copy);
     v3dirs = value0;
     ecl_bds_unwind1(cl_env_copy);
     goto L2;
L3:;
     {
      cl_object v4condition;
      v4condition = ECL_CONS_CAR(CLV1);
      cl_env_copy->nvalues = 2;
      cl_env_copy->values[1] = v4condition;
      cl_env_copy->values[0] = ECL_NIL;
      value0 = cl_env_copy->values[0];
      ecl_frs_pop(cl_env_copy);
      v3dirs = value0;
      goto L2;
     }
    }
   }
L2:;
   {
    cl_object env2 = env1;
    T2 = cl_pathname_directory(1, ECL_CONS_CAR(CLV0));
    value0 = ecl_function_dispatch(cl_env_copy,VV[38])(1, T2) /*  NORMALIZE-PATHNAME-DIRECTORY-COMPONENT */;
    if ((value0)!=ECL_NIL) { goto L11; }
    T1 = VV[52];
    goto L9;
L11:;
    T1 = value0;
    goto L9;
L9:;
    CLV1 = env2 = CONS(T1,env2);                  /*  PREFIX          */
    {cl_object v4;
     v4 = ECL_NIL;
     v4 = ecl_make_cclosure_va((cl_objectfn)LC387__g1305,env2,Cblock);
     T0 = v4;
    }
   }
   value0 = ecl_function_dispatch(cl_env_copy,VV[651])(3, ECL_CONS_CAR(CLV0), v3dirs, T0) /*  FILTER-LOGICAL-DIRECTORY-RESULTS */;
   return value0;
  }
 }
}
/*	closure G1304                                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC386__g1304(cl_narg narg, cl_object v1si__temp, ...)
{
 cl_object CLV0, CLV1, CLV2
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV2 = env0;                                     /*  TAGBODY         */
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  ECL_CONS_CAR(CLV1) = v1si__temp;
  cl_go(ECL_CONS_CAR(CLV2),ecl_make_fixnum(0));
 }
 }
}
/*	closure G1305                                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC387__g1305(cl_narg narg, cl_object v1d, ...)
{
 cl_object T0, T1, T2;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  PREFIX          */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  {
   cl_object v2dir;
   T0 = cl_pathname_directory(1, v1d);
   v2dir = ecl_function_dispatch(cl_env_copy,VV[38])(1, T0) /*  NORMALIZE-PATHNAME-DIRECTORY-COMPONENT */;
   if (!(ECL_CONSP(v2dir))) { goto L3; }
   T0 = ecl_cdr(v2dir);
   if (!(ECL_CONSP(T0))) { goto L3; }
   T0 = ecl_last(v2dir,1);
   T1 = ecl_function_dispatch(cl_env_copy,VV[46])(1, T0) /*  MAKE-PATHNAME-COMPONENT-LOGICAL */;
   T2 = ecl_append(ECL_CONS_CAR(CLV1),T1);
   value0 = cl_make_pathname(10, ECL_SYM("DEFAULTS",1216), ECL_CONS_CAR(CLV0), ECL_SYM("NAME",1273), ECL_NIL, ECL_SYM("TYPE",1318), ECL_NIL, ECL_SYM("VERSION",1326), ECL_NIL, ECL_SYM("DIRECTORY",1219), T2);
   return value0;
L3:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
 }
}
/*	function definition for COLLECT-ASDS-IN-DIRECTORY             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L389collect_asds_in_directory(cl_object v1directory, cl_object v2collect)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[657])(1, v1directory) /*  DIRECTORY-ASD-FILES */;
  value0 = cl_map(3, ECL_NIL, v2collect, T0);
  return value0;
 }
}
/*	function definition for COLLECT-SUB*DIRECTORIES               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L390collect_sub_directories(cl_object v1directory, cl_object v2collectp, cl_object v3recursep, cl_object v4collector)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,v2collectp)(1, v1directory))) { goto L1; }
  ecl_function_dispatch(cl_env_copy,v4collector)(1, v1directory);
L1:;
  {
   cl_object v5;
   v5 = ecl_function_dispatch(cl_env_copy,VV[659])(1, v1directory) /*  SUBDIRECTORIES */;
   goto L6;
L5:;
   {
    cl_object v6subdir;
    v6subdir = ecl_car(v5);
    if (Null(ecl_function_dispatch(cl_env_copy,v3recursep)(1, v6subdir))) { goto L10; }
    L390collect_sub_directories(v6subdir, v2collectp, v3recursep, v4collector);
L10:;
   }
   v5 = ecl_cdr(v5);
L6:;
   if (Null(v5)) { goto L14; }
   goto L5;
L14:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for COLLECT-SUB*DIRECTORIES-ASD-FILES     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L393collect_sub_directories_asd_files(cl_narg narg, cl_object v1directory, ...)
{
 cl_object T0, T1, T2;
 cl_object env0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  ecl_va_list args; ecl_va_start(args,v1directory,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L393collect_sub_directories_asd_fileskeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[2])) {
    env0 = ECL_NIL;
    CLV0 = env0 = CONS(ecl_symbol_value(VV[643]),env0); /*  EXCLUDE   */
   } else {
    env0 = ECL_NIL;
    CLV0 = env0 = CONS(keyvars[0],env0);          /*  EXCLUDE         */
   }
   CLV1 = env0 = CONS(keyvars[1],env0);           /*  COLLECT         */
  }
  T0 = cl_constantly(ECL_T);
  {cl_object v2;
   v2 = ECL_NIL;
   v2 = ecl_make_cclosure_va((cl_objectfn)LC391__g1309,env0,Cblock);
   T1 = v2;
  }
  {cl_object v2;
   v2 = ECL_NIL;
   v2 = ecl_make_cclosure_va((cl_objectfn)LC392__g1310,env0,Cblock);
   T2 = v2;
  }
  value0 = ecl_function_dispatch(cl_env_copy,VV[663])(4, v1directory, T0, T1, T2) /*  COLLECT-SUB*DIRECTORIES */;
  return value0;
 }
}
/*	closure G1309                                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC391__g1309(cl_narg narg, cl_object v1x, ...)
{
 cl_object T0, T1, T2, T3;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;
 CLV0 = _ecl_cdr(CLV1);                           /*  EXCLUDE         */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  T1 = cl_pathname_directory(1, v1x);
  T2 = ecl_last(T1,1);
  T3 = ecl_car(T2);
  T0 = ecl_member(T3,ECL_CONS_CAR(CLV0));
  value0 = Null(T0)?ECL_T:ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
 }
}
/*	closure G1310                                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC392__g1310(cl_narg narg, cl_object v1dir, ...)
{
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  COLLECT         */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[661])(2, v1dir, ECL_CONS_CAR(CLV1)) /*  COLLECT-ASDS-IN-DIRECTORY */;
  return value0;
 }
 }
}
/*	function definition for VALIDATE-SOURCE-REGISTRY-DIRECTIVE    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L394validate_source_registry_directive(cl_object v1directive)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ecl_eql(v1directive,VV[668]))) { goto L5; }
  value0 = VV[669];
  goto L3;
L5:;
  value0 = ECL_NIL;
  goto L3;
L3:;
  if ((value0)!=ECL_NIL) { goto L2; }
  if (!(ECL_CONSP(v1directive))) { goto L8; }
  {
   cl_object v2rest;
   v2rest = ecl_cdr(v1directive);
   {
    cl_object v3;
    v3 = ecl_car(v1directive);
    if (!(ecl_eql(v3,ECL_SYM("INCLUDE",1249)))) { goto L17; }
    goto L14;
    goto L15;
L17:;
    goto L15;
L15:;
    if (!(ecl_eql(v3,ECL_SYM("DIRECTORY",1219)))) { goto L21; }
    goto L14;
    goto L19;
L21:;
    goto L19;
L19:;
    if (!(ecl_eql(v3,VV[672]))) { goto L12; }
    goto L13;
L14:;
L13:;
    if (Null(ecl_function_dispatch(cl_env_copy,VV[105])(2, v2rest, ecl_make_fixnum(1)) /*  LENGTH=N-P */)) { goto L25; }
    T0 = ecl_car(v2rest);
    value0 = ecl_function_dispatch(cl_env_copy,VV[554])(1, T0) /*  LOCATION-DESIGNATOR-P */;
    return value0;
L25:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
L12:;
    if (!(ecl_eql(v3,VV[674]))) { goto L32; }
    goto L29;
    goto L30;
L32:;
    goto L30;
L30:;
    if (!(ecl_eql(v3,VV[676]))) { goto L27; }
    goto L28;
L29:;
L28:;
    T0 = (ECL_SYM("STRINGP",825)->symbol.gfdef);
    value0 = cl_every(2, T0, v2rest);
    return value0;
L27:;
    if (!(ecl_eql(v3,VV[668]))) { goto L36; }
    value0 = ecl_make_bool(v2rest==ECL_NIL);
    cl_env_copy->nvalues = 1;
    return value0;
L36:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
L8:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for VALIDATE-SOURCE-REGISTRY-FORM         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L395validate_source_registry_form(cl_narg narg, cl_object v1form, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2location;
  ecl_va_list args; ecl_va_start(args,v1form,narg,1);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L395validate_source_registry_formkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v2location = keyvars[0];
  }
  value0 = ecl_function_dispatch(cl_env_copy,VV[503])(7, v1form, VV[680], VV[667], ECL_SYM("LOCATION",999), v2location, VV[570], VV[187]) /*  VALIDATE-CONFIGURATION-FORM */;
  return value0;
 }
}
/*	function definition for VALIDATE-SOURCE-REGISTRY-FILE         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L396validate_source_registry_file(cl_object v1file)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[510])(4, v1file, VV[679], ECL_SYM("DESCRIPTION",988), _ecl_static_138) /*  VALIDATE-CONFIGURATION-FILE */;
  return value0;
 }
}
/*	function definition for VALIDATE-SOURCE-REGISTRY-DIRECTORY    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L397validate_source_registry_directory(cl_object v1directory)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[516])(5, v1directory, VV[680], VV[667], VV[570], VV[187]) /*  VALIDATE-CONFIGURATION-DIRECTORY */;
  return value0;
 }
}
/*	function definition for PARSE-SOURCE-REGISTRY-STRING          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L399parse_source_registry_string(cl_narg narg, cl_object v1string, ...)
{
 cl_object T0, T1, T2;
 volatile cl_object lex0[1];
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2location;
  ecl_va_list args; ecl_va_start(args,v1string,narg,1);
  lex0[0] = v1string;                             /*  STRING          */
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L399parse_source_registry_stringkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v2location = keyvars[0];
  }
  if (lex0[0]==ECL_NIL) { goto L3; }
  if (!(ecl_equal(lex0[0],_ecl_static_6))) { goto L1; }
  goto L2;
L3:;
L2:;
  value0 = VV[687];
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (ECL_STRINGP(lex0[0])) { goto L5; }
  value0 = cl_error(2, _ecl_static_120, lex0[0]);
  return value0;
L5:;
  {
   ecl_character v3;
   v3 = ecl_char(lex0[0],0);
   {
    cl_object v4;
    v4 = si_make_seq_iterator(2, _ecl_static_139, ecl_make_fixnum(0));
L11:;
    if ((v4)!=ECL_NIL) { goto L13; }
    goto L7;
L13:;
    {
     cl_object v5;
     v5 = si_seq_iterator_ref(_ecl_static_139, v4);
     if (!((ECL_CODE_CHAR(v3)==(v5)))) { goto L15; }
     if (Null(v5)) { goto L7; }
     goto L8;
    }
L15:;
    v4 = si_seq_iterator_next(_ecl_static_139, v4);
    goto L11;
   }
  }
L8:;
  T0 = cl_read_from_string(1, lex0[0]);
  value0 = ecl_function_dispatch(cl_env_copy,VV[679])(3, T0, ECL_SYM("LOCATION",999), v2location) /*  VALIDATE-SOURCE-REGISTRY-FORM */;
  return value0;
L7:;
  {
   cl_object v3inherit;
   v3inherit = ECL_NIL;
   {
    cl_object v4directives;
    v4directives = ECL_NIL;
    {
     cl_object v5start;
     v5start = ecl_make_fixnum(0);
     {
      cl_fixnum v6end;
      v6end = ecl_length(lex0[0]);
      {
       cl_object v7separator;
       v7separator = L310inter_directory_separator();
       {
        cl_object v8pos;
        v8pos = ECL_NIL;
L26:;
        v8pos = cl_position(4, v7separator, lex0[0], ECL_SYM("START",1310), v5start);
        {
         cl_object v9s;
         value0 = v8pos;
         if ((value0)!=ECL_NIL) { goto L33; }
         T0 = ecl_make_fixnum(v6end);
         goto L31;
L33:;
         T0 = value0;
         goto L31;
L31:;
         v9s = cl_subseq(3, lex0[0], v5start, T0);
         if (!(ecl_equal(_ecl_static_6,v9s))) { goto L36; }
         if (Null(v3inherit)) { goto L38; }
         cl_error(2, _ecl_static_121, lex0[0]);
L38:;
         v3inherit = ECL_T;
         v4directives = CONS(VV[507],v4directives);
         goto L35;
L36:;
         if (Null(ecl_function_dispatch(cl_env_copy,VV[109])(2, v9s, _ecl_static_141) /*  STRING-SUFFIX-P */)) { goto L43; }
         {
          cl_fixnum v10;
          v10 = ecl_length(v9s);
          T1 = ecl_minus(ecl_make_fixnum(v10),ecl_make_fixnum(2));
          T2 = cl_subseq(3, v9s, ecl_make_fixnum(0), T1);
          T0 = LC398check(lex0, T2);
         }
         T1 = cl_list(2, VV[672], T0);
         v4directives = CONS(T1,v4directives);
         goto L35;
L43:;
         T0 = LC398check(lex0, v9s);
         T1 = cl_list(2, ECL_SYM("DIRECTORY",1219), T0);
         v4directives = CONS(T1,v4directives);
L35:;
         if (Null(v8pos)) { goto L49; }
         v5start = ecl_one_plus(v8pos);
         goto L29;
L49:;
         if ((v3inherit)!=ECL_NIL) { goto L52; }
         v4directives = CONS(VV[688],v4directives);
L52:;
         T0 = cl_nreverse(v4directives);
         value0 = CONS(VV[680],T0);
         cl_env_copy->nvalues = 1;
         return value0;
        }
L29:;
        goto L26;
       }
      }
     }
    }
   }
  }
 }
}
/*	local function CHECK                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC398check(volatile cl_object *lex0, cl_object v1dir)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((ecl_function_dispatch(cl_env_copy,VV[93])(1, v1dir) /*  ABSOLUTE-PATHNAME-P */)!=ECL_NIL) { goto L1; }
  cl_error(2, _ecl_static_140, lex0[0]);
L1:;
  value0 = v1dir;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for REGISTER-ASD-DIRECTORY                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L400register_asd_directory(cl_narg narg, cl_object v1directory, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2recurse;
  cl_object v3exclude;
  cl_object v4collect;
  ecl_va_list args; ecl_va_start(args,v1directory,narg,1);
  {
   cl_object keyvars[6];
   cl_parse_key(args,3,L400register_asd_directorykeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v2recurse = keyvars[0];
   v3exclude = keyvars[1];
   v4collect = keyvars[2];
  }
  if ((v2recurse)!=ECL_NIL) { goto L1; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[661])(2, v1directory, v4collect) /*  COLLECT-ASDS-IN-DIRECTORY */;
  return value0;
L1:;
  value0 = ecl_function_dispatch(cl_env_copy,VV[665])(5, v1directory, VV[674], v3exclude, VV[597], v4collect) /*  COLLECT-SUB*DIRECTORIES-ASD-FILES */;
  return value0;
 }
}
/*	function definition for WRAPPING-SOURCE-REGISTRY              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L401wrapping_source_registry()
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_translate_logical_pathname(1, _ecl_static_144);
  T1 = cl_list(2, VV[672], T0);
  value0 = cl_list(3, VV[680], T1, VV[507]);
  return value0;
 }
}
/*	function definition for DEFAULT-SOURCE-REGISTRY               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L402default_source_registry()
{
 cl_object T0, T1, T2, T3, T4, T5, T6;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[128])(0) /*  DEFAULT-DIRECTORY */;
  T1 = cl_list(2, ECL_SYM("DIRECTORY",1219), T0);
  {
   cl_object v1;
   cl_object v2dir;
   cl_object v3;
   if (Null(ecl_function_dispatch(cl_env_copy,VV[258])(0) /*  OS-UNIX-P */)) { goto L4; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[467])(1, _ecl_static_145) /*  GETENV-ABSOLUTE-DIRECTORY */;
   if ((value0)!=ECL_NIL) { goto L8; }
   T5 = ecl_function_dispatch(cl_env_copy,VV[457])(0) /*  USER-HOMEDIR */;
   T4 = ecl_function_dispatch(cl_env_copy,VV[102])(2, T5, _ecl_static_146) /*  SUBPATHNAME */;
   goto L6;
L8:;
   T4 = value0;
   goto L6;
L6:;
   value0 = ecl_function_dispatch(cl_env_copy,VV[471])(1, _ecl_static_147) /*  GETENV-ABSOLUTE-DIRECTORIES */;
   if ((value0)!=ECL_NIL) { goto L12; }
   T5 = VV[698];
   goto L10;
L12:;
   T5 = value0;
   goto L10;
L10:;
   T3 = CONS(T4,T5);
   goto L3;
L4:;
   T3 = ECL_NIL;
L3:;
   if (Null(ecl_function_dispatch(cl_env_copy,VV[261])(0) /*  OS-WINDOWS-P */)) { goto L15; }
   {
    cl_object v4;
    cl_object v5;
    v4 = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(VV[477]))) FEtype_error_list(VV[477]);
    v5 = VV[477];
    {
     cl_object v6;
     cl_object v7;
     v6 = ecl_list1(ECL_NIL);
     v7 = v6;
L22:;
     v4 = _ecl_car(v5);
     {
      cl_object v8;
      v8 = _ecl_cdr(v5);
      if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
      v5 = v8;
     }
     if (ecl_unlikely(ECL_ATOM(v7))) FEtype_error_cons(v7);
     T5 = v7;
     T6 = ecl_function_dispatch(cl_env_copy,VV[473])(1, v4);
     v7 = ecl_list1(T6);
     (ECL_CONS_CDR(T5)=v7,T5);
     if (!(ecl_endp(v5))) { goto L35; }
     goto L23;
L35:;
     goto L22;
L23:;
     T4 = ecl_cdr(v6);
     goto L14;
    }
   }
L15:;
   T4 = ECL_NIL;
L14:;
   v1 = ecl_append(T3,T4);
   v2dir = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v1))) FEtype_error_list(v1);
   v3 = v1;
   {
    cl_object v4;
    cl_object v5;
    v4 = ecl_list1(ECL_NIL);
    v5 = v4;
L44:;
    if (!(ecl_endp(v3))) { goto L46; }
    goto L45;
L46:;
    v2dir = _ecl_car(v3);
    {
     cl_object v6;
     v6 = _ecl_cdr(v3);
     if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
     v3 = v6;
    }
    if (ecl_unlikely(ECL_ATOM(v5))) FEtype_error_cons(v5);
    T3 = v5;
    T4 = L52subpathname_(2, v2dir, _ecl_static_148);
    T5 = cl_list(2, ECL_SYM("DIRECTORY",1219), T4);
    v5 = ecl_list1(T5);
    (ECL_CONS_CDR(T3)=v5,T3);
    if (ecl_unlikely(ECL_ATOM(v5))) FEtype_error_cons(v5);
    T3 = v5;
    T4 = L52subpathname_(2, v2dir, _ecl_static_149);
    T5 = cl_list(2, VV[672], T4);
    v5 = ecl_list1(T5);
    (ECL_CONS_CDR(T3)=v5,T3);
    goto L44;
L45:;
    T2 = ecl_cdr(v4);
    goto L1;
   }
  }
L1:;
  T3 = ecl_append(T2,VV[517]);
  value0 = cl_listX(3, VV[680], T1, T3);
  return value0;
 }
}
/*	function definition for USER-SOURCE-REGISTRY                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L403user_source_registry(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1direction;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L403user_source_registrykeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[1])) {
    v1direction = ECL_SYM("INPUT",1254);
   } else {
    v1direction = keyvars[0];
   }
  }
  value0 = ecl_function_dispatch(cl_env_copy,VV[492])(3, ecl_symbol_value(VV[693]), ECL_SYM("DIRECTION",1218), v1direction) /*  IN-USER-CONFIGURATION-DIRECTORY */;
  return value0;
 }
}
/*	function definition for SYSTEM-SOURCE-REGISTRY                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L404system_source_registry(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1direction;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L404system_source_registrykeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[1])) {
    v1direction = ECL_SYM("INPUT",1254);
   } else {
    v1direction = keyvars[0];
   }
  }
  value0 = ecl_function_dispatch(cl_env_copy,VV[494])(3, ecl_symbol_value(VV[693]), ECL_SYM("DIRECTION",1218), v1direction) /*  IN-SYSTEM-CONFIGURATION-DIRECTORY */;
  return value0;
 }
}
/*	function definition for USER-SOURCE-REGISTRY-DIRECTORY        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L405user_source_registry_directory(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1direction;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L405user_source_registry_directorykeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[1])) {
    v1direction = ECL_SYM("INPUT",1254);
   } else {
    v1direction = keyvars[0];
   }
  }
  value0 = ecl_function_dispatch(cl_env_copy,VV[492])(3, ecl_symbol_value(VV[694]), ECL_SYM("DIRECTION",1218), v1direction) /*  IN-USER-CONFIGURATION-DIRECTORY */;
  return value0;
 }
}
/*	function definition for SYSTEM-SOURCE-REGISTRY-DIRECTORY      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L406system_source_registry_directory(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1direction;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L406system_source_registry_directorykeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[1])) {
    v1direction = ECL_SYM("INPUT",1254);
   } else {
    v1direction = keyvars[0];
   }
  }
  value0 = ecl_function_dispatch(cl_env_copy,VV[494])(3, ecl_symbol_value(VV[694]), ECL_SYM("DIRECTION",1218), v1direction) /*  IN-SYSTEM-CONFIGURATION-DIRECTORY */;
  return value0;
 }
}
/*	function definition for ENVIRONMENT-SOURCE-REGISTRY           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L407environment_source_registry()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[84])(1, _ecl_static_150) /*  GETENV */;
  return value0;
 }
}
/*	local function G1341                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC408__g1341(cl_narg narg, cl_object v1x, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2inherit;
  cl_object v3register;
  ecl_va_list args; ecl_va_start(args,v1x,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,LC408__g1341keys,keyvars,NULL,TRUE);
   ecl_va_end(args);
   v2inherit = keyvars[0];
   v3register = keyvars[1];
  }
  T0 = ecl_function_dispatch(cl_env_copy,v1x)(0);
  value0 = ecl_function_dispatch(cl_env_copy,VV[710])(5, T0, VV[596], v2inherit, VV[711], v3register) /*  PROCESS-SOURCE-REGISTRY */;
  return value0;
 }
}
/*	local function G1342                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC409__g1342(cl_narg narg, cl_object v1pathname, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2inherit;
  cl_object v3register;
  ecl_va_list args; ecl_va_start(args,v1pathname,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,LC409__g1342keys,keyvars,NULL,TRUE);
   ecl_va_end(args);
   v2inherit = keyvars[0];
   v3register = keyvars[1];
  }
  if (Null(ecl_function_dispatch(cl_env_copy,VV[86])(1, v1pathname) /*  DIRECTORY-PATHNAME-P */)) { goto L1; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[119])(1, v1pathname) /*  TRUENAMIZE */;
  ecl_bds_bind(cl_env_copy,VV[542],T0);           /*  *HERE-DIRECTORY* */
  T0 = ecl_function_dispatch(cl_env_copy,VV[684])(1, v1pathname) /*  VALIDATE-SOURCE-REGISTRY-DIRECTORY */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[710])(5, T0, VV[596], v2inherit, VV[711], v3register) /*  PROCESS-SOURCE-REGISTRY */;
  ecl_bds_unwind1(cl_env_copy);
  return value0;
L1:;
  if (Null(ecl_function_dispatch(cl_env_copy,VV[116])(1, v1pathname) /*  PROBE-FILE* */)) { goto L3; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[36])(1, v1pathname) /*  PATHNAME-DIRECTORY-PATHNAME */;
  ecl_bds_bind(cl_env_copy,VV[542],T0);           /*  *HERE-DIRECTORY* */
  T0 = ecl_function_dispatch(cl_env_copy,VV[682])(1, v1pathname) /*  VALIDATE-SOURCE-REGISTRY-FILE */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[710])(5, T0, VV[596], v2inherit, VV[711], v3register) /*  PROCESS-SOURCE-REGISTRY */;
  ecl_bds_unwind1(cl_env_copy);
  return value0;
L3:;
  value0 = L413inherit_source_registry(3, v2inherit, VV[711], v3register);
  return value0;
 }
}
/*	local function G1343                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC410__g1343(cl_narg narg, cl_object v1string, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2inherit;
  cl_object v3register;
  ecl_va_list args; ecl_va_start(args,v1string,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,LC410__g1343keys,keyvars,NULL,TRUE);
   ecl_va_end(args);
   v2inherit = keyvars[0];
   v3register = keyvars[1];
  }
  T0 = ecl_function_dispatch(cl_env_copy,VV[686])(1, v1string) /*  PARSE-SOURCE-REGISTRY-STRING */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[710])(5, T0, VV[596], v2inherit, VV[711], v3register) /*  PROCESS-SOURCE-REGISTRY */;
  return value0;
 }
}
/*	local function G1344                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC411__g1344(cl_narg narg, cl_object v1x, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2inherit;
  cl_object v3register;
  ecl_va_list args; ecl_va_start(args,v1x,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,LC411__g1344keys,keyvars,NULL,TRUE);
   ecl_va_end(args);
   v2inherit = keyvars[0];
   v3register = keyvars[1];
  }
  value0 = L413inherit_source_registry(3, v2inherit, VV[711], v3register);
  return value0;
 }
}
/*	local function G1345                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC412__g1345(cl_narg narg, cl_object v1form, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2inherit;
  cl_object v3register;
  ecl_va_list args; ecl_va_start(args,v1form,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,LC412__g1345keys,keyvars,NULL,TRUE);
   ecl_va_end(args);
   v2inherit = keyvars[0];
   v3register = keyvars[1];
  }
  ecl_bds_bind(cl_env_copy,VV[644],ecl_symbol_value(VV[643])); /*  *SOURCE-REGISTRY-EXCLUSIONS* */
  {
   cl_object v4;
   T0 = ecl_function_dispatch(cl_env_copy,VV[679])(1, v1form) /*  VALIDATE-SOURCE-REGISTRY-FORM */;
   v4 = ecl_cdr(T0);
   goto L4;
L3:;
   {
    cl_object v5directive;
    v5directive = ecl_car(v4);
    L414process_source_registry_directive(5, v5directive, VV[596], v2inherit, VV[711], v3register);
   }
   v4 = ecl_cdr(v4);
L4:;
   if (Null(v4)) { goto L11; }
   goto L3;
L11:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
 }
}
/*	function definition for INHERIT-SOURCE-REGISTRY               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L413inherit_source_registry(cl_narg narg, cl_object v1inherit, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2register;
  ecl_va_list args; ecl_va_start(args,v1inherit,narg,1);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L413inherit_source_registrykeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v2register = keyvars[0];
  }
  if (Null(v1inherit)) { goto L1; }
  T0 = ecl_car(v1inherit);
  T1 = ecl_cdr(v1inherit);
  value0 = ecl_function_dispatch(cl_env_copy,VV[710])(5, T0, VV[711], v2register, VV[596], T1) /*  PROCESS-SOURCE-REGISTRY */;
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for PROCESS-SOURCE-REGISTRY-DIRECTIVE     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L414process_source_registry_directive(cl_narg narg, cl_object v1directive, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2inherit;
  cl_object v3register;
  ecl_va_list args; ecl_va_start(args,v1directive,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L414process_source_registry_directivekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v2inherit = keyvars[0];
   v3register = keyvars[1];
  }
  {
   cl_object v4;
   cl_object v5;
   cl_object v6kw;
   if (!(ECL_CONSP(v1directive))) { goto L3; }
   v4 = v1directive;
   goto L2;
L3:;
   v4 = ecl_list1(v1directive);
L2:;
   v5 = v4;
   if (!(v5==ECL_NIL)) { goto L7; }
   si_dm_too_few_arguments(v4);
L7:;
   {
    cl_object v7;
    v7 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v6kw = v7;
   }
   if (!(ecl_eql(v6kw,ECL_SYM("INCLUDE",1249)))) { goto L12; }
   {
    cl_object v7;
    cl_object v8pathname;
    v7 = v5;
    if (!(v7==ECL_NIL)) { goto L17; }
    si_dm_too_few_arguments(v5);
L17:;
    {
     cl_object v9;
     v9 = ecl_car(v7);
     v7 = ecl_cdr(v7);
     v8pathname = v9;
    }
    if (Null(v7)) { goto L22; }
    si_dm_too_many_arguments(v5);
L22:;
    T0 = ecl_function_dispatch(cl_env_copy,VV[552])(1, v8pathname) /*  RESOLVE-LOCATION */;
    ecl_function_dispatch(cl_env_copy,VV[710])(5, T0, VV[596], ECL_NIL, VV[711], v3register) /*  PROCESS-SOURCE-REGISTRY */;
    goto L1;
   }
L12:;
   if (!(ecl_eql(v6kw,ECL_SYM("DIRECTORY",1219)))) { goto L24; }
   {
    cl_object v9;
    cl_object v10pathname;
    v9 = v5;
    if (!(v9==ECL_NIL)) { goto L29; }
    si_dm_too_few_arguments(v5);
L29:;
    {
     cl_object v11;
     v11 = ecl_car(v9);
     v9 = ecl_cdr(v9);
     v10pathname = v11;
    }
    if (Null(v9)) { goto L34; }
    si_dm_too_many_arguments(v5);
L34:;
    if (Null(v10pathname)) { goto L1; }
    T0 = ecl_function_dispatch(cl_env_copy,VV[552])(3, v10pathname, ECL_SYM("DIRECTORY",1219), ECL_T) /*  RESOLVE-LOCATION */;
    ecl_function_dispatch(cl_env_copy,v3register)(1, T0);
    goto L1;
   }
L24:;
   if (!(ecl_eql(v6kw,VV[672]))) { goto L37; }
   {
    cl_object v11;
    cl_object v12pathname;
    v11 = v5;
    if (!(v11==ECL_NIL)) { goto L42; }
    si_dm_too_few_arguments(v5);
L42:;
    {
     cl_object v13;
     v13 = ecl_car(v11);
     v11 = ecl_cdr(v11);
     v12pathname = v13;
    }
    if (Null(v11)) { goto L47; }
    si_dm_too_many_arguments(v5);
L47:;
    if (Null(v12pathname)) { goto L1; }
    T0 = ecl_function_dispatch(cl_env_copy,VV[552])(3, v12pathname, ECL_SYM("DIRECTORY",1219), ECL_T) /*  RESOLVE-LOCATION */;
    ecl_function_dispatch(cl_env_copy,v3register)(5, T0, VV[717], ECL_T, VV[674], ecl_symbol_value(VV[644]));
    goto L1;
   }
L37:;
   if (!(ecl_eql(v6kw,VV[674]))) { goto L50; }
   cl_set(VV[644],v5);
   goto L1;
L50:;
   if (!(ecl_eql(v6kw,VV[676]))) { goto L54; }
   cl_set(VV[644],ecl_append(ecl_symbol_value(VV[644]),v5));
   goto L1;
L54:;
   if (!(ecl_eql(v6kw,VV[668]))) { goto L58; }
   ecl_function_dispatch(cl_env_copy,VV[712])(3, VV[719], VV[711], v3register) /*  INHERIT-SOURCE-REGISTRY */;
   goto L1;
L58:;
   if (!(ecl_eql(v6kw,VV[507]))) { goto L61; }
   ecl_function_dispatch(cl_env_copy,VV[712])(3, v2inherit, VV[711], v3register) /*  INHERIT-SOURCE-REGISTRY */;
   goto L1;
L61:;
   if (!(ecl_eql(v6kw,VV[508]))) { goto L66; }
   goto L1;
   goto L64;
L66:;
   goto L64;
L64:;
   si_ecase_error(v6kw, VV[720]);
  }
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for FLATTEN-SOURCE-REGISTRY               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L417flatten_source_registry(cl_narg narg, ...)
{
 cl_object T0, T1, T2;
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1parameter;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1parameter = ECL_NIL;
   } else {
    i++;
    v1parameter = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object env1 = env0;
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(ECL_NIL,env1);
   T1 = ecl_function_dispatch(cl_env_copy,VV[128])(0) /*  DEFAULT-DIRECTORY */;
   ecl_bds_bind(cl_env_copy,ECL_SYM("*DEFAULT-PATHNAME-DEFAULTS*",32),T1); /*  *DEFAULT-PATHNAME-DEFAULTS* */
   T1 = cl_listX(3, VV[695], v1parameter, ecl_symbol_value(VV[692]));
   {cl_object v2;
    v2 = ECL_NIL;
    v2 = ecl_make_cclosure_va((cl_objectfn)LC416__g1376,env1,Cblock);
    T2 = v2;
   }
   ecl_function_dispatch(cl_env_copy,VV[712])(3, T1, VV[711], T2) /*  INHERIT-SOURCE-REGISTRY */;
   ecl_bds_unwind1(cl_env_copy);
   T0 = cl_reverse(ECL_CONS_CAR(CLV0));
  }
  value0 = cl_remove_duplicates(5, T0, ECL_SYM("TEST",1316), ECL_SYM("EQUAL",335), VV[15], ECL_T);
  return value0;
 }
}
/*	closure COLLECT                                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC415collect(cl_narg narg, cl_object v1x, ...)
{
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  ECL_CONS_CAR(CLV0) = CONS(v1x,ECL_CONS_CAR(CLV0));
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  return value0;
 }
 }
}
/*	closure G1376                                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC416__g1376(cl_narg narg, cl_object v1directory, ...)
{
 cl_object T0;
 volatile struct ecl_cclosure aux_closure;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2recurse;
  cl_object v3exclude;
  ecl_va_list args; ecl_va_start(args,v1directory,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,LC416__g1376keys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v2recurse = keyvars[0];
   v3exclude = keyvars[1];
  }
  T0 = cl_list(5, v1directory, VV[717], v2recurse, VV[674], v3exclude);
  value0 = (aux_closure.env=env0,cl_env_copy->function=(cl_object)&aux_closure,LC415collect(1, T0));
  return value0;
 }
 }
}
/*	function definition for COMPUTE-SOURCE-REGISTRY               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L419compute_source_registry(cl_narg narg, ...)
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0, CLV1, CLV2, CLV3
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v1parameter;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1parameter = ECL_NIL;
   } else {
    i++;
    v1parameter = va_arg(args,cl_object);
   }
   if (i >= narg) {
    env0 = ECL_NIL;
    CLV0 = env0 = CONS(ecl_symbol_value(VV[645]),env0); /*  REGISTRY  */
   } else {
    i++;
    env0 = ECL_NIL;
    CLV0 = env0 = CONS(va_arg(args,cl_object),env0); /*  REGISTRY     */
   }
  }
  va_end(args);
  {
   cl_object v2;
   v2 = ecl_function_dispatch(cl_env_copy,VV[722])(1, v1parameter) /*  FLATTEN-SOURCE-REGISTRY */;
   goto L6;
L5:;
   {
    cl_object v3entry;
    v3entry = ecl_car(v2);
    {
     cl_object v4;
     cl_object v5;
     cl_object v6;
     cl_object v7exclude;
     cl_object env1 = env0;
     v4 = v3entry;
     if (!(v4==ECL_NIL)) { goto L12; }
     si_dm_too_few_arguments(v3entry);
L12:;
     {
      cl_object v8;
      v8 = ecl_car(v4);
      v4 = ecl_cdr(v4);
      T0 = v8;
     }
     CLV1 = env1 = CONS(T0,env1);                 /*  DIRECTORY       */
     v5 = si_search_keyword(2, v4, VV[717]);
     if (!((v5)==(ECL_SYM("MISSING-KEYWORD",1929)))) { goto L20; }
     T0 = ECL_NIL;
     goto L19;
L20:;
     T0 = v5;
L19:;
     CLV2 = env1 = CONS(T0,env1);                 /*  RECURSE         */
     v6 = si_search_keyword(2, v4, VV[674]);
     if (!((v6)==(ECL_SYM("MISSING-KEYWORD",1929)))) { goto L24; }
     v7exclude = ECL_NIL;
     goto L23;
L24:;
     v7exclude = v6;
L23:;
     si_check_keyword(2, v4, VV[725]);
     {
      cl_object env2 = env1;
      T0 = cl_make_hash_table(2, ECL_SYM("TEST",1316), ECL_SYM("EQUAL",335));
      CLV3 = env2 = CONS(T0,env2);                /*  H               */
      {cl_object v8;
       v8 = ECL_NIL;
       v8 = ecl_make_cclosure_va((cl_objectfn)LC418__g1385,env2,Cblock);
       T0 = v8;
      }
      ecl_function_dispatch(cl_env_copy,VV[690])(7, ECL_CONS_CAR(CLV1), VV[717], ECL_CONS_CAR(CLV2), VV[674], v7exclude, VV[597], T0) /*  REGISTER-ASD-DIRECTORY */;
     }
    }
   }
   v2 = ecl_cdr(v2);
L6:;
   if (Null(v2)) { goto L31; }
   goto L5;
L31:;
  }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  return value0;
 }
}
/*	closure G1385                                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC418__g1385(cl_narg narg, cl_object v1asd, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1, CLV2, CLV3
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV3 = env0;                                     /*  H               */
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  {
   cl_object v2name;
   cl_object v3name;
   v2name = cl_pathname_name(1, v1asd);
   if (Null(si_logical_pathname_p(v1asd))) { goto L3; }
   v3name = cl_string_downcase(1, v2name);
   goto L2;
L3:;
   v3name = v2name;
L2:;
   if (Null(ecl_gethash_safe(v3name,ECL_CONS_CAR(CLV0),ECL_NIL))) { goto L5; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L5:;
   if (Null(ecl_gethash_safe(v3name,ECL_CONS_CAR(CLV3),ECL_NIL))) { goto L7; }
   if (Null(ecl_symbol_value(VV[7]))) { goto L9; }
   T0 = cl_gethash(2, v3name, ECL_CONS_CAR(CLV3));
   value0 = (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(6, _ecl_static_151, ECL_CONS_CAR(CLV1), ECL_CONS_CAR(CLV2), v3name, T0, v1asd) /*  WARN */;
   return value0;
L9:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L7:;
   si_hash_set(v3name, ECL_CONS_CAR(CLV0), v1asd);
   value0 = si_hash_set(v3name, ECL_CONS_CAR(CLV3), v1asd);
   return value0;
  }
 }
 }
}
/*	function definition for INITIALIZE-SOURCE-REGISTRY            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L420initialize_source_registry(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1parameter;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1parameter = ecl_symbol_value(VV[727]);
   } else {
    i++;
    v1parameter = va_arg(args,cl_object);
   }
  }
  va_end(args);
  cl_set(VV[727],v1parameter);
  cl_set(VV[645],cl_make_hash_table(2, ECL_SYM("TEST",1316), ECL_SYM("EQUAL",335)));
  value0 = ecl_function_dispatch(cl_env_copy,VV[724])(1, v1parameter) /*  COMPUTE-SOURCE-REGISTRY */;
  return value0;
 }
}
/*	function definition for ENSURE-SOURCE-REGISTRY                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L421ensure_source_registry(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1parameter;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1parameter = ECL_NIL;
   } else {
    i++;
    v1parameter = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if ((ecl_function_dispatch(cl_env_copy,VV[646])(0) /*  SOURCE-REGISTRY-INITIALIZED-P */)!=ECL_NIL) { goto L2; }
  ecl_function_dispatch(cl_env_copy,VV[728])(1, v1parameter) /*  INITIALIZE-SOURCE-REGISTRY */;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  return value0;
 }
}
/*	function definition for SYSDEF-SOURCE-REGISTRY-SEARCH         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L422sysdef_source_registry_search(cl_object v1system)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_function_dispatch(cl_env_copy,VV[730])(0)   /*  ENSURE-SOURCE-REGISTRY */;
  T0 = ecl_function_dispatch(cl_env_copy,VV[233])(1, v1system) /*  COERCE-NAME */;
  value0 = ecl_gethash_safe(T0,ecl_symbol_value(VV[645]),ECL_NIL);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for CLEAR-CONFIGURATION                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L423clear_configuration()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_function_dispatch(cl_env_copy,VV[648])(0)   /*  CLEAR-SOURCE-REGISTRY */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[529])(0) /*  CLEAR-OUTPUT-TRANSLATIONS */;
  return value0;
 }
}
/*	function definition for REGISTER-PRE-BUILT-SYSTEM             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L424register_pre_built_system(cl_object v1name)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[233])(1, v1name) /*  COERCE-NAME */;
  T1 = (cl_env_copy->function=(ECL_SYM("MAKE-INSTANCE",949)->symbol.gfdef))->cfun.entry(5, VV[213], ECL_SYM("NAME",1273), T0, VV[292], ECL_NIL) /*  MAKE-INSTANCE */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[239])(1, T1) /*  REGISTER-SYSTEM */;
  return value0;
 }
}
/*	closure G1400                                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC425__g1400(cl_narg narg, cl_object v1name, ...)
{
 cl_object T0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  F               */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  {
   cl_object v2l;
   {
    struct ecl_stack_frame _ecl_inner_frame_aux;
    cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
    {
     cl_object v3;
     v3 = _ecl_inner_frame;
     cl_env_copy->values[0] = ecl_function_dispatch(cl_env_copy,ECL_CONS_CAR(CLV0))(1, v1name);
     ecl_stack_frame_push_values(v3);cl_env_copy->values[0]=ecl_apply_from_stack_frame(v3,ECL_SYM("LIST",481));
     value0 = cl_env_copy->values[0];
    }
    ecl_stack_frame_close(_ecl_inner_frame);
   }
   v2l = value0;
   if (Null(ecl_car(v2l))) { goto L8; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[233])(1, v1name) /*  COERCE-NAME */;
   L424register_pre_built_system(T0);
   goto L6;
L8:;
   goto L6;
L6:;
   value0 = cl_values_list(v2l);
   return value0;
  }
 }
 }
}
/*	function definition for COMPILE-FILE-KEEPING-OBJECT           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L426compile_file_keeping_object(cl_narg narg, cl_object v1input_file, ...)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2keys;
  ecl_va_list args; ecl_va_start(args,v1input_file,narg,1);
  cl_parse_key(args,0,NULL,NULL,(cl_object*)&v2keys,TRUE);
  ecl_va_end(args);
  if (Null(L1use_ecl_byte_compiler_p())) { goto L1; }
  value0 = cl_apply(3, VV[27], v1input_file, v2keys);
  return value0;
L1:;
  {
   cl_object v4;                                  /*  OBJECT-FILE     */
   cl_object v5;                                  /*  FLAGS1          */
   cl_object v6;                                  /*  FLAGS2          */
   value0 = cl_apply(5, VV[27], v1input_file, VV[739], ECL_T, v2keys);
   v4 = value0;
   {
    const int v7 = cl_env_copy->nvalues;
    cl_object v8;
    v8 = (v7<=1)? ECL_NIL : cl_env_copy->values[1];
    v5 = v8;
    v8 = (v7<=2)? ECL_NIL : cl_env_copy->values[2];
    v6 = v8;
   }
   if (Null(v4)) { goto L6; }
   T1 = (cl_env_copy->function=(ECL_SYM("COMPILE-FILE-PATHNAME",235)->symbol.gfdef))->cfun.entry(3, v4, ECL_SYM("TYPE",1318), VV[355]) /*  COMPILE-FILE-PATHNAME */;
   T2 = ecl_list1(v4);
   if (Null(ecl_function_dispatch(cl_env_copy,VV[1055])(3, T1, VV[740], T2) /*  BUILD-FASL */)) { goto L6; }
   T0 = v4;
   goto L4;
L6:;
   T0 = ECL_NIL;
   goto L4;
L4:;
   cl_env_copy->nvalues = 3;
   cl_env_copy->values[2] = v6;
   cl_env_copy->values[1] = v5;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for MODULE-PROVIDE-ASDF                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L428module_provide_asdf(cl_object v1name)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7;
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1name,env0);                /*  NAME            */
  T0 = (ECL_SYM("MUFFLE-WARNING",571)->symbol.gfdef);
  T1 = CONS(ECL_SYM("STYLE-WARNING",827),T0);
  T2 = cl_constantly(ECL_NIL);
  T3 = CONS(VV[178],T2);
  {cl_object v2;
   v2 = ECL_NIL;
   v2 = ecl_make_cclosure_va((cl_objectfn)LC427__g1404,env0,Cblock);
   T4 = v2;
  }
  T5 = CONS(ECL_SYM("ERROR",337),T4);
  T6 = cl_list(3, T1, T3, T5);
  T7 = CONS(T6,ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5)));
  ecl_bds_bind(cl_env_copy,ECL_SYM("*HANDLER-CLUSTERS*",5),T7); /*  *HANDLER-CLUSTERS* */
  {
   cl_object v2;
   cl_object v3;
   v2 = cl_make_broadcast_stream(0);
   T0 = cl_string_downcase(1, ECL_CONS_CAR(CLV0));
   v3 = ecl_function_dispatch(cl_env_copy,VV[144])(2, T0, ECL_NIL) /*  FIND-SYSTEM */;
   ecl_bds_bind(cl_env_copy,VV[22],v2);           /*  *VERBOSE-OUT*   */
   if (Null(v3)) { goto L5; }
   L272require_system(3, v3, ECL_SYM("VERBOSE",1325), ECL_NIL);
   value0 = ECL_T;
   cl_env_copy->nvalues = 1;
   ecl_bds_unwind1(cl_env_copy);
   ecl_bds_unwind1(cl_env_copy);
   return value0;
L5:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   ecl_bds_unwind1(cl_env_copy);
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
 }
}
/*	closure G1404                                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC427__g1404(cl_narg narg, cl_object v1e, ...)
{
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  NAME            */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = cl_format(4, ecl_symbol_value(ECL_SYM("*ERROR-OUTPUT*",33)), _ecl_static_152, ECL_CONS_CAR(CLV0), v1e);
  return value0;
 }
 }
}

#include "ext/asdf.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclLoWkIob7_01ExWE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("EXT:ASDF;ASDF.LISP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclLoWkIob7_01ExWE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 cl_set(ECL_SYM("*FEATURES*",34),cl_adjoin(2, VV[0], ecl_symbol_value(ECL_SYM("*FEATURES*",34))));
 if ((cl_find_package(VV[1]))!=ECL_NIL) { goto L4; }
 cl_make_package(3, VV[1], ECL_SYM("USE",1323), VVtemp[0]);
L4:;
 si_select_package(_ecl_static_1);
 {
  volatile cl_object lex0[1];
 ecl_cmp_defun(VV[744]);                          /*  USE-ECL-BYTE-COMPILER-P */
 if ((L1use_ecl_byte_compiler_p())!=ECL_NIL) { goto L11; }
 cl_require(1, VV[4]);
L11:;
 si_Xmake_special(VV[5]);
 if (ecl_boundp(cl_env_copy,VV[5])) { goto L14; }
 cl_set(VV[5],ECL_NIL);
L14:;
 si_Xmake_special(VV[6]);
 if (ecl_boundp(cl_env_copy,VV[6])) { goto L21; }
 cl_set(VV[6],ECL_NIL);
L21:;
 si_Xmake_special(VV[7]);
 if (ecl_boundp(cl_env_copy,VV[7])) { goto L28; }
 cl_set(VV[7],ECL_NIL);
L28:;
 ecl_cmp_defun(VV[745]);                          /*  FIND-SYMBOL*    */
 ecl_cmp_defun(VV[746]);                          /*  STRCAT          */
 ecl_cmp_defmacro(VV[747]);                       /*  COMPATFMT       */
 {
  cl_object v1existing_asdf;
  cl_object v2existing_version;
  cl_object v3already_there;
  v1existing_asdf = cl_find_class(2, VV[11], ECL_NIL);
  v2existing_version = ecl_symbol_value(VV[5]);
  v3already_there = ecl_make_bool(ecl_equal(_ecl_static_2,v2existing_version));
  if (Null(v1existing_asdf)) { goto L50; }
  if ((v3already_there)!=ECL_NIL) { goto L44; }
  goto L48;
L50:;
  goto L48;
L48:;
  if (Null(v1existing_asdf)) { goto L52; }
  if (Null(ecl_symbol_value(VV[7]))) { goto L52; }
  cl_format(4, ecl_symbol_value(ECL_SYM("*TRACE-OUTPUT*",69)), _ecl_static_3, v2existing_version, _ecl_static_2);
L52:;
  lex0[0] = ECL_NIL;                              /*  UNLINK-PACKAGE  */
  lex0[0] = ecl_make_cfun((cl_objectfn_fixed)LC7unlink_package,ECL_NIL,Cblock,1);
  LC16ensure_package(13, lex0, VV[1], ECL_SYM("NICKNAMES",1277), ECL_NIL, ECL_SYM("USE",1323), VVtemp[0], ECL_SYM("EXPORT",1233), VVtemp[1], ECL_SYM("SHADOW",1306), ECL_NIL, VV[16], VVtemp[2], VV[17], VVtemp[3]);
  cl_set(VV[5],_ecl_static_2);
  if (Null(v2existing_version)) { goto L59; }
  cl_set(VV[6],CONS(v2existing_version,ecl_symbol_value(VV[6])));
  goto L58;
L59:;
  cl_set(VV[6],ecl_symbol_value(VV[6]));
L58:;
 }
L44:;
 }
 si_Xmake_special(VV[18]);
 if (ecl_boundp(cl_env_copy,VV[18])) { goto L62; }
 cl_set(VV[18],ECL_T);
L62:;
 si_Xmake_special(VV[19]);
 if (ecl_boundp(cl_env_copy,VV[19])) { goto L69; }
 cl_set(VV[19],VV[20]);
L69:;
 si_Xmake_special(VV[21]);
 if (ecl_boundp(cl_env_copy,VV[21])) { goto L76; }
 cl_set(VV[21],VV[20]);
L76:;
 si_Xmake_special(VV[22]);
 if (ecl_boundp(cl_env_copy,VV[22])) { goto L83; }
 cl_set(VV[22],ECL_NIL);
L83:;
 si_Xmake_special(VV[23]);
 cl_set(VV[23],VVtemp[4]);
 si_Xmake_special(VV[24]);
 if (ecl_boundp(cl_env_copy,VV[24])) { goto L96; }
 cl_set(VV[24],VV[25]);
L96:;
 si_Xmake_special(VV[26]);
 if (ecl_boundp(cl_env_copy,VV[26])) { goto L103; }
 cl_set(VV[26],VV[27]);
L103:;
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[5]) /*  MAPC */;
 ecl_cmp_defmacro(VV[754]);                       /*  DEFGENERIC*     */
 ecl_cmp_defmacro(VV[755]);                       /*  DEFUN*          */
 ecl_cmp_defmacro(VV[756]);                       /*  WHILE-COLLECTING */
 ecl_cmp_defmacro(VV[757]);                       /*  AIF             */
 cl_fmakunbound(VV[36]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[6]) /*  MAPC */;
 ecl_cmp_defun(VV[758]);                          /*  PATHNAME-DIRECTORY-PATHNAME */
 cl_fmakunbound(VV[38]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[7]) /*  MAPC */;
 ecl_cmp_defun(VV[759]);                          /*  NORMALIZE-PATHNAME-DIRECTORY-COMPONENT */
 cl_fmakunbound(VV[42]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[8]) /*  MAPC */;
 ecl_cmp_defun(VV[760]);                          /*  MERGE-PATHNAME-DIRECTORY-COMPONENTS */
 cl_fmakunbound(VV[46]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[9]) /*  MAPC */;
 ecl_cmp_defun(VV[761]);                          /*  MAKE-PATHNAME-COMPONENT-LOGICAL */
 cl_fmakunbound(VV[49]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[10]) /*  MAPC */;
 ecl_cmp_defun(VV[762]);                          /*  MAKE-PATHNAME-LOGICAL */
 cl_fmakunbound(VV[51]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[11]) /*  MAPC */;
 ecl_cmp_defun(VV[763]);                          /*  MERGE-PATHNAMES* */
 cl_fmakunbound(VV[56]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[12]) /*  MAPC */;
 ecl_cmp_defun(VV[764]);                          /*  PATHNAME-PARENT-DIRECTORY-PATHNAME */
 ecl_cmp_defmacro(VV[765]);                       /*  APPENDF         */
 ecl_cmp_defmacro(VV[766]);                       /*  ORF             */
 cl_fmakunbound(VV[62]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[13]) /*  MAPC */;
 ecl_cmp_defun(VV[767]);                          /*  FIRST-CHAR      */
 cl_fmakunbound(VV[64]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[14]) /*  MAPC */;
 ecl_cmp_defun(VV[768]);                          /*  LAST-CHAR       */
 cl_fmakunbound(VV[66]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[15]) /*  MAPC */;
 ecl_cmp_defun(VV[769]);                          /*  ASDF-MESSAGE    */
 cl_fmakunbound(VV[68]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[16]) /*  MAPC */;
 ecl_cmp_defun(VV[770]);                          /*  SPLIT-STRING    */
 cl_fmakunbound(VV[71]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[17]) /*  MAPC */;
 ecl_cmp_defun(VV[771]);                          /*  SPLIT-NAME-TYPE */
 cl_fmakunbound(VV[75]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[18]) /*  MAPC */;
 ecl_cmp_defun(VV[772]);                          /*  COMPONENT-NAME-TO-PATHNAME-COMPONENTS */
 cl_fmakunbound(VV[80]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[19]) /*  MAPC */;
 ecl_cmp_defun(VV[773]);                          /*  REMOVE-KEYS     */
 cl_fmakunbound(VV[82]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[20]) /*  MAPC */;
 ecl_cmp_defun(VV[774]);                          /*  REMOVE-KEYWORD  */
 cl_fmakunbound(VV[84]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[21]) /*  MAPC */;
 ecl_cmp_defun(VV[775]);                          /*  GETENV          */
 cl_fmakunbound(VV[86]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[22]) /*  MAPC */;
 ecl_cmp_defun(VV[776]);                          /*  DIRECTORY-PATHNAME-P */
 cl_fmakunbound(VV[91]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[23]) /*  MAPC */;
 ecl_cmp_defun(VV[777]);                          /*  ENSURE-DIRECTORY-PATHNAME */
 cl_fmakunbound(VV[93]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[24]) /*  MAPC */;
 ecl_cmp_defun(VV[778]);                          /*  ABSOLUTE-PATHNAME-P */
 cl_fmakunbound(VV[95]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[25]) /*  MAPC */;
 ecl_cmp_defun(VV[779]);                          /*  COERCE-PATHNAME */
 cl_fmakunbound(VV[100]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[26]) /*  MAPC */;
 ecl_cmp_defun(VV[782]);                          /*  MERGE-COMPONENT-NAME-TYPE */
 cl_fmakunbound(VV[102]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[27]) /*  MAPC */;
 ecl_cmp_defun(VV[783]);                          /*  SUBPATHNAME     */
 ecl_cmp_defun(VV[784]);                          /*  SUBPATHNAME*    */
 cl_fmakunbound(VV[105]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[28]) /*  MAPC */;
 ecl_cmp_defun(VV[785]);                          /*  LENGTH=N-P      */
 cl_fmakunbound(VV[109]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[29]) /*  MAPC */;
 ecl_cmp_defun(VV[786]);                          /*  STRING-SUFFIX-P */
 cl_fmakunbound(VV[112]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[30]) /*  MAPC */;
 ecl_cmp_defun(VV[787]);                          /*  READ-FILE-FORMS */
 cl_fmakunbound(VV[114]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[31]) /*  MAPC */;
 ecl_cmp_defun(VV[788]);                          /*  PATHNAME-ROOT   */
 cl_fmakunbound(VV[116]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[32]) /*  MAPC */;
 ecl_cmp_defun(VV[789]);                          /*  PROBE-FILE*     */
 cl_fmakunbound(VV[119]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[33]) /*  MAPC */;
 ecl_cmp_defun(VV[790]);                          /*  TRUENAMIZE      */
 cl_fmakunbound(VV[121]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[34]) /*  MAPC */;
 ecl_cmp_defun(VV[791]);                          /*  RESOLVE-SYMLINKS */
 cl_fmakunbound(VV[123]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[35]) /*  MAPC */;
 ecl_cmp_defun(VV[792]);                          /*  RESOLVE-SYMLINKS* */
 cl_fmakunbound(VV[125]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[36]) /*  MAPC */;
 ecl_cmp_defun(VV[793]);                          /*  ENSURE-PATHNAME-ABSOLUTE */
 cl_fmakunbound(VV[128]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[37]) /*  MAPC */;
 ecl_cmp_defun(VV[794]);                          /*  DEFAULT-DIRECTORY */
 cl_fmakunbound(VV[130]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[38]) /*  MAPC */;
 ecl_cmp_defun(VV[795]);                          /*  LISPIZE-PATHNAME */
 si_Xmake_special(VV[132]);
 cl_set(VV[132],ECL_SYM("WILD",1327));
 si_Xmake_special(VV[133]);
 cl_set(VV[133],cl_make_pathname(8, ECL_SYM("NAME",1273), ecl_symbol_value(VV[132]), ECL_SYM("TYPE",1318), ecl_symbol_value(VV[132]), ECL_SYM("VERSION",1326), ecl_symbol_value(VV[132]), ECL_SYM("DIRECTORY",1219), ECL_NIL));
 {
  cl_object T0;
 si_Xmake_special(VV[134]);
 T0 = cl_list(2, ECL_SYM("RELATIVE",1299), ecl_symbol_value(VV[132]));
 cl_set(VV[134],cl_make_pathname(8, ECL_SYM("DIRECTORY",1219), T0, ECL_SYM("NAME",1273), ECL_NIL, ECL_SYM("TYPE",1318), ECL_NIL, ECL_SYM("VERSION",1326), ECL_NIL));
 }
 si_Xmake_special(VV[135]);
 cl_set(VV[135],cl_make_pathname(8, ECL_SYM("DIRECTORY",1219), VVtemp[39], ECL_SYM("NAME",1273), ECL_NIL, ECL_SYM("TYPE",1318), ECL_NIL, ECL_SYM("VERSION",1326), ECL_NIL));
 si_Xmake_special(VV[136]);
 cl_set(VV[136],cl_merge_pathnames(2, ecl_symbol_value(VV[133]), ecl_symbol_value(VV[135])));
 cl_fmakunbound(VV[137]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[40]) /*  MAPC */;
 ecl_cmp_defun(VV[796]);                          /*  WILDEN          */
 cl_fmakunbound(VV[139]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[41]) /*  MAPC */;
 ecl_cmp_defun(VV[797]);                          /*  DIRECTORY-SEPARATOR-FOR-HOST */
 cl_fmakunbound(VV[142]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[42]) /*  MAPC */;
 ecl_cmp_defun(VV[798]);                          /*  DIRECTORIZE-PATHNAME-HOST-DEVICE */
 cl_fmakunbound(VV[144]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[43]) /*  MAPC */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(5, VV[144], VV[145], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[44]) /*  ENSURE-GENERIC-FUNCTION */;
 cl_fmakunbound(VV[146]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[45]) /*  MAPC */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(5, VV[146], VV[145], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[46]) /*  ENSURE-GENERIC-FUNCTION */;
 cl_fmakunbound(VV[147]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[47]) /*  MAPC */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(5, VV[147], VV[145], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[46]) /*  ENSURE-GENERIC-FUNCTION */;
 cl_fmakunbound(VV[148]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[48]) /*  MAPC */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(5, VV[148], VV[145], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[46]) /*  ENSURE-GENERIC-FUNCTION */;
 cl_fmakunbound(VV[149]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[49]) /*  MAPC */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(5, VV[149], VV[145], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[46]) /*  ENSURE-GENERIC-FUNCTION */;
 cl_fmakunbound(VV[150]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[50]) /*  MAPC */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(5, VV[150], VV[145], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[46]) /*  ENSURE-GENERIC-FUNCTION */;
 cl_fmakunbound(VV[151]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[51]) /*  MAPC */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(5, VV[151], VV[145], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[46]) /*  ENSURE-GENERIC-FUNCTION */;
 cl_fmakunbound(VV[152]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[52]) /*  MAPC */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(5, VV[152], VV[145], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[46]) /*  ENSURE-GENERIC-FUNCTION */;
 cl_fmakunbound(VV[153]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[53]) /*  MAPC */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(5, VV[153], VV[145], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[46]) /*  ENSURE-GENERIC-FUNCTION */;
 cl_fmakunbound(VV[154]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[54]) /*  MAPC */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, VV[154], VV[145], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[46], ECL_SYM("DOCUMENTATION",1222), _ecl_static_16) /*  ENSURE-GENERIC-FUNCTION */;
 cl_fmakunbound(VV[155]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[55]) /*  MAPC */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, VV[155], VV[145], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[56], ECL_SYM("DOCUMENTATION",1222), _ecl_static_17) /*  ENSURE-GENERIC-FUNCTION */;
 cl_fmakunbound(VV[156]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[57]) /*  MAPC */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, VV[156], VV[145], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[58], ECL_SYM("DOCUMENTATION",1222), _ecl_static_18) /*  ENSURE-GENERIC-FUNCTION */;
 cl_fmakunbound(VV[157]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[59]) /*  MAPC */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, VV[157], VV[145], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[58], ECL_SYM("DOCUMENTATION",1222), _ecl_static_19) /*  ENSURE-GENERIC-FUNCTION */;
 cl_fmakunbound(VV[158]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[60]) /*  MAPC */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, VV[158], VV[145], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[58], ECL_SYM("DOCUMENTATION",1222), _ecl_static_20) /*  ENSURE-GENERIC-FUNCTION */;
 cl_fmakunbound(VV[159]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[61]) /*  MAPC */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(5, VV[159], VV[145], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[62]) /*  ENSURE-GENERIC-FUNCTION */;
 cl_fmakunbound(VVtemp[63]);
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(5, VVtemp[63], VV[145], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[64]) /*  ENSURE-GENERIC-FUNCTION */;
 cl_fmakunbound(VV[160]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[65]) /*  MAPC */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(5, VV[160], VV[145], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[58]) /*  ENSURE-GENERIC-FUNCTION */;
 cl_fmakunbound(VV[161]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[66]) /*  MAPC */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(5, VV[161], VV[145], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[58]) /*  ENSURE-GENERIC-FUNCTION */;
 cl_fmakunbound(VVtemp[67]);
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(5, VVtemp[67], VV[145], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[68]) /*  ENSURE-GENERIC-FUNCTION */;
 cl_fmakunbound(VV[162]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[69]) /*  MAPC */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(5, VV[162], VV[145], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[70]) /*  ENSURE-GENERIC-FUNCTION */;
 cl_fmakunbound(VV[163]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[71]) /*  MAPC */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, VV[163], VV[145], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[72], ECL_SYM("DOCUMENTATION",1222), _ecl_static_21) /*  ENSURE-GENERIC-FUNCTION */;
 cl_fmakunbound(VV[164]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[73]) /*  MAPC */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(5, VV[164], VV[145], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[74]) /*  ENSURE-GENERIC-FUNCTION */;
 cl_fmakunbound(VV[165]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[75]) /*  MAPC */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, VV[165], VV[145], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[76], ECL_SYM("DOCUMENTATION",1222), _ecl_static_22) /*  ENSURE-GENERIC-FUNCTION */;
 cl_fmakunbound(VV[166]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[77]) /*  MAPC */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, VV[166], VV[145], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[46], ECL_SYM("DOCUMENTATION",1222), _ecl_static_23) /*  ENSURE-GENERIC-FUNCTION */;
 cl_fmakunbound(VV[167]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[78]) /*  MAPC */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, VV[167], VV[145], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[79], ECL_SYM("DOCUMENTATION",1222), _ecl_static_24) /*  ENSURE-GENERIC-FUNCTION */;
 cl_fmakunbound(VVtemp[80]);
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(5, VVtemp[80], VV[145], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[81]) /*  ENSURE-GENERIC-FUNCTION */;
 cl_fmakunbound(VV[168]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[82]) /*  MAPC */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(5, VV[168], VV[145], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[46]) /*  ENSURE-GENERIC-FUNCTION */;
 cl_fmakunbound(VV[169]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[83]) /*  MAPC */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, VV[169], VV[145], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[46], ECL_SYM("DOCUMENTATION",1222), _ecl_static_25) /*  ENSURE-GENERIC-FUNCTION */;
 cl_fmakunbound(VV[170]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[84]) /*  MAPC */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(5, VV[170], VV[145], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[46]) /*  ENSURE-GENERIC-FUNCTION */;
 cl_fmakunbound(VV[171]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[85]) /*  MAPC */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, VV[171], VV[145], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[46], ECL_SYM("DOCUMENTATION",1222), _ecl_static_26) /*  ENSURE-GENERIC-FUNCTION */;
 if (Null(ecl_symbol_value(VV[6]))) { goto L526; }
 if (Null(cl_find_class(2, VV[172], ECL_NIL))) { goto L526; }
 cl_eval(VVtemp[86]);
L526:;
 clos_load_defclass(VV[173], VVtemp[87], ECL_NIL, ECL_NIL);
 {
  cl_object T0, T1, T2;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC71__g362,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 T1 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T0, VVtemp[89]);
 T2 = cl_list(3, T1, VVtemp[90], VVtemp[91]);
 clos_load_defclass(VV[174], VVtemp[88], T2, ECL_NIL);
 }
 {
  cl_object T0, T1, T2;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC73__g364,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 T1 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T0, VVtemp[92]);
 T2 = cl_list(4, T1, VVtemp[93], VVtemp[94], VVtemp[95]);
 clos_load_defclass(VV[175], VVtemp[88], T2, ECL_NIL);
 }
 {
  cl_object T0, T1, T2;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC75__g366,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 T1 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T0, VVtemp[96]);
 T2 = cl_list(2, T1, VVtemp[97]);
 clos_load_defclass(VV[176], VVtemp[88], T2, ECL_NIL);
 }
 {
  cl_object T0, T1, T2;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC77__g368,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 T1 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T0, VVtemp[98]);
 T2 = cl_list(2, T1, VVtemp[99]);
 clos_load_defclass(VV[177], VVtemp[88], T2, ECL_NIL);
 }
 clos_load_defclass(VV[178], VVtemp[88], VVtemp[100], ECL_NIL);
 clos_load_defclass(VV[179], VVtemp[101], VVtemp[102], ECL_NIL);
 clos_load_defclass(VV[180], VVtemp[101], VVtemp[103], ECL_NIL);
 clos_load_defclass(VV[181], VVtemp[104], ECL_NIL, ECL_NIL);
 {
  cl_object T0, T1, T2;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC79__g370,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 T1 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T0, VVtemp[105]);
 T2 = cl_list(3, T1, VVtemp[106], VVtemp[107]);
 clos_load_defclass(VV[182], VVtemp[87], T2, ECL_NIL);
 }
 clos_load_defclass(VV[183], VVtemp[108], ECL_NIL, ECL_NIL);
 clos_load_defclass(VV[184], VVtemp[109], ECL_NIL, ECL_NIL);
 clos_load_defclass(VV[185], VVtemp[109], ECL_NIL, ECL_NIL);
 {
  cl_object T0, T1, T2;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC81__g372,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 T1 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T0, VVtemp[111]);
 T2 = cl_list(5, T1, VVtemp[112], VVtemp[113], VVtemp[114], VVtemp[115]);
 clos_load_defclass(VV[186], VVtemp[110], T2, ECL_NIL);
 }
 {
  cl_object T0, T1, T2;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC82__g374,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 T1 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T0, VVtemp[117]);
 T2 = ecl_list1(T1);
 clos_load_defclass(VV[187], VVtemp[116], T2, ECL_NIL);
 }
 {
  cl_object T0, T1, T2;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC83__g375,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 T1 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T0, VVtemp[118]);
 T2 = ecl_list1(T1);
 clos_load_defclass(VV[188], VVtemp[116], T2, ECL_NIL);
 }
 {
  cl_object T0, T1, T2;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC84__g376,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 T1 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T0, VVtemp[130]);
 T2 = cl_list(15, VVtemp[119], VVtemp[120], VVtemp[121], VVtemp[122], VVtemp[123], VVtemp[124], VVtemp[125], VVtemp[126], VVtemp[127], VVtemp[128], VVtemp[129], T1, VVtemp[131], VVtemp[132], VVtemp[133]);
 clos_load_defclass(VV[11], ECL_NIL, T2, ECL_NIL);
 }
 cl_fmakunbound(VV[189]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[134]) /*  MAPC */;
 ecl_cmp_defun(VV[812]);                          /*  COMPONENT-FIND-PATH */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC87__g379,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("PRINT-OBJECT",961), ECL_NIL, VVtemp[135], VVtemp[136], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC88__g380,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("PRINT-OBJECT",961), ECL_NIL, VVtemp[137], VVtemp[138], T0, ECL_T);
 }
 cl_fmakunbound(VV[191]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[139]) /*  MAPC */;
 ecl_cmp_defun(VV[816]);                          /*  SYSDEF-ERROR    */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC90__g381,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("PRINT-OBJECT",961), ECL_NIL, VVtemp[140], VVtemp[138], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC91__g382,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("PRINT-OBJECT",961), ECL_NIL, VVtemp[141], VVtemp[138], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC92__g383,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, VV[156], ECL_NIL, VVtemp[58], VVtemp[58], T0, ECL_T);
 }
 si_Xmake_special(VV[193]);
 if (ecl_boundp(cl_env_copy,VV[193])) { goto L596; }
 cl_set(VV[193],VV[194]);
L596:;
 cl_fmakunbound(VV[195]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[142]) /*  MAPC */;
 ecl_cmp_defun(VV[820]);                          /*  COMPUTE-MODULE-COMPONENTS-BY-NAME */
 clos_load_defclass(VV[172], VVtemp[58], VVtemp[143], ECL_NIL);
 cl_fmakunbound(VV[197]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[144]) /*  MAPC */;
 ecl_cmp_defun(VV[824]);                          /*  COMPONENT-PARENT-PATHNAME */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC95__g398,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, VV[157], ECL_NIL, VVtemp[58], VVtemp[58], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC96__g402,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[159], ECL_NIL, VVtemp[135], VVtemp[145], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC97__g413,ECL_NIL,Cblock,3);
  T0 = v1;
 }
 clos_install_method(6, VVtemp[63], ECL_NIL, VVtemp[146], VVtemp[147], T0, ECL_T);
 }
 si_Xmake_special(VV[201]);
 if (ecl_boundp(cl_env_copy,VV[201])) { goto L624; }
 cl_set(VV[201],ECL_SYM("DEFAULT",1215));
L624:;
 si_Xmake_special(VV[202]);
 cl_set(VV[202],ECL_SYM("UTF-8",1681));
 cl_fmakunbound(VV[203]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[148]) /*  MAPC */;
 ecl_cmp_defun(VV[826]);                          /*  ALWAYS-DEFAULT-ENCODING */
 si_Xmake_special(VV[205]);
 if (ecl_boundp(cl_env_copy,VV[205])) { goto L644; }
 cl_set(VV[205],ecl_fdefinition(VV[203]));
L644:;
 cl_fmakunbound(VV[206]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[149]) /*  MAPC */;
 ecl_cmp_defun(VV[827]);                          /*  DETECT-ENCODING */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC100__g421,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, VV[161], ECL_NIL, VVtemp[58], VVtemp[150], T0, ECL_T);
 }
 cl_fmakunbound(VV[208]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[151]) /*  MAPC */;
 ecl_cmp_defun(VV[829]);                          /*  DEFAULT-ENCODING-EXTERNAL-FORMAT */
 si_Xmake_special(VV[210]);
 if (ecl_boundp(cl_env_copy,VV[210])) { goto L667; }
 cl_set(VV[210],ecl_fdefinition(VV[208]));
L667:;
 ecl_cmp_defun(VV[830]);                          /*  ENCODING-EXTERNAL-FORMAT */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC103__g424,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, VV[160], ECL_NIL, VVtemp[58], VVtemp[150], T0, ECL_T);
 }
 clos_load_defclass(VV[212], ECL_NIL, VVtemp[152], ECL_NIL);
 clos_load_defclass(VV[213], VVtemp[153], VVtemp[154], ECL_NIL);
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC104__g425,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[162], ECL_NIL, VVtemp[135], VVtemp[155], T0, ECL_T);
 }
 cl_fmakunbound(VV[215]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[156]) /*  MAPC */;
 ecl_cmp_defun(VV[832]);                          /*  ASDF-VERSION    */
 cl_fmakunbound(VV[217]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[157]) /*  MAPC */;
 ecl_cmp_defun(VV[833]);                          /*  PARSE-VERSION   */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC108__g439,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[162], ECL_NIL, VVtemp[158], VVtemp[159], T0, ECL_T);
 }
 si_Xmake_special(VV[219]);
 cl_set(VV[219],ecl_make_fixnum(76));
 si_Xmake_special(VV[220]);
 cl_set(VV[220],VVtemp[160]);
 cl_fmakunbound(VV[221]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[161]) /*  MAPC */;
 ecl_cmp_defun(VV[834]);                          /*  READ-NULL-TERMINATED-STRING */
 cl_fmakunbound(VV[223]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[162]) /*  MAPC */;
 ecl_cmp_defun(VV[835]);                          /*  READ-LITTLE-ENDIAN */
 cl_fmakunbound(VV[225]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[163]) /*  MAPC */;
 ecl_cmp_defun(VV[836]);                          /*  PARSE-FILE-LOCATION-INFO */
 cl_fmakunbound(VV[227]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[164]) /*  MAPC */;
 ecl_cmp_defun(VV[837]);                          /*  PARSE-WINDOWS-SHORTCUT */
 cl_fmakunbound(VV[230]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[165]) /*  MAPC */;
 ecl_cmp_defun(VV[838]);                          /*  MAKE-DEFINED-SYSTEMS-TABLE */
 si_Xmake_special(VV[232]);
 if (ecl_boundp(cl_env_copy,VV[232])) { goto L747; }
 cl_set(VV[232],ecl_function_dispatch(cl_env_copy,VV[230])(0) /*  MAKE-DEFINED-SYSTEMS-TABLE */);
L747:;
 cl_fmakunbound(VV[233]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[166]) /*  MAPC */;
 ecl_cmp_defun(VV[839]);                          /*  COERCE-NAME     */
 cl_fmakunbound(VV[235]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[167]) /*  MAPC */;
 ecl_cmp_defun(VV[840]);                          /*  SYSTEM-REGISTERED-P */
 cl_fmakunbound(VV[237]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[168]) /*  MAPC */;
 ecl_cmp_defun(VV[841]);                          /*  REGISTERED-SYSTEMS */
 cl_fmakunbound(VV[239]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[169]) /*  MAPC */;
 ecl_cmp_defun(VV[842]);                          /*  REGISTER-SYSTEM */
 cl_fmakunbound(VV[242]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[170]) /*  MAPC */;
 ecl_cmp_defun(VV[843]);                          /*  CLEAR-SYSTEM    */
 cl_fmakunbound(VV[244]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[171]) /*  MAPC */;
 ecl_cmp_defun(VV[844]);                          /*  MAP-SYSTEMS     */
 si_Xmake_special(VV[246]);
 if (ecl_boundp(cl_env_copy,VV[246])) { goto L796; }
 cl_set(VV[246],ECL_NIL);
L796:;
 {
  cl_object T0, T1, T2;
 T0 = cl_remove(2, VV[247], ecl_symbol_value(VV[246]));
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC121__g502,ECL_NIL,Cblock,1);
  T1 = v1;
 }
 T2 = cl_remove_if(2, T1, VVtemp[172]);
 cl_set(VV[246],ecl_append(T0,T2));
 }
 cl_fmakunbound(VV[248]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[173]) /*  MAPC */;
 ecl_cmp_defun(VV[845]);                          /*  SEARCH-FOR-SYSTEM-DEFINITION */
 si_Xmake_special(VV[251]);
 if (ecl_boundp(cl_env_copy,VV[251])) { goto L813; }
 cl_set(VV[251],ECL_NIL);
L813:;
 cl_fmakunbound(VV[252]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[174]) /*  MAPC */;
 ecl_cmp_defun(VV[846]);                          /*  FEATUREP        */
 cl_fmakunbound(VV[258]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[175]) /*  MAPC */;
 ecl_cmp_defun(VV[847]);                          /*  OS-UNIX-P       */
 cl_fmakunbound(VV[261]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[176]) /*  MAPC */;
 ecl_cmp_defun(VV[848]);                          /*  OS-WINDOWS-P    */
 cl_fmakunbound(VV[264]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[177]) /*  MAPC */;
 ecl_cmp_defun(VV[849]);                          /*  PROBE-ASD       */
 cl_fmakunbound(VV[266]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[178]) /*  MAPC */;
 ecl_cmp_defun(VV[850]);                          /*  SYSDEF-CENTRAL-REGISTRY-SEARCH */
 cl_fmakunbound(VV[271]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[179]) /*  MAPC */;
 ecl_cmp_defun(VV[852]);                          /*  MAKE-TEMPORARY-PACKAGE */
 cl_fmakunbound(VV[274]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[180]) /*  MAPC */;
 ecl_cmp_defun(VV[853]);                          /*  SAFE-FILE-WRITE-DATE */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC140__g545,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, VV[144], ECL_NIL, VVtemp[181], VVtemp[182], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC141__g546,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, VV[144], ECL_NIL, VVtemp[183], VVtemp[182], T0, ECL_T);
 }
 si_Xmake_special(VV[276]);
 if (ecl_boundp(cl_env_copy,VV[276])) { goto L873; }
 cl_set(VV[276],ECL_NIL);
L873:;
 si_Xmake_special(VV[277]);
 if (ecl_boundp(cl_env_copy,VV[277])) { goto L880; }
 cl_set(VV[277],ECL_NIL);
L880:;
 cl_fmakunbound(VV[249]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[184]) /*  MAPC */;
 ecl_cmp_defun(VV[854]);                          /*  FIND-SYSTEM-IF-BEING-DEFINED */
 cl_fmakunbound(VV[279]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[185]) /*  MAPC */;
 ecl_cmp_defun(VV[855]);                          /*  CALL-WITH-SYSTEM-DEFINITIONS */
 ecl_cmp_defmacro(VV[856]);                       /*  WITH-SYSTEM-DEFINITIONS */
 cl_fmakunbound(VV[282]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[186]) /*  MAPC */;
 ecl_cmp_defun(VV[857]);                          /*  LOAD-SYSDEF     */
 cl_fmakunbound(VV[285]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[187]) /*  MAPC */;
 ecl_cmp_defun(VV[858]);                          /*  LOCATE-SYSTEM   */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC152__g584,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, VV[144], ECL_NIL, VVtemp[188], VVtemp[182], T0, ECL_T);
 }
 cl_fmakunbound(VV[291]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[189]) /*  MAPC */;
 ecl_cmp_defun(VV[860]);                          /*  FIND-SYSTEM-FALLBACK */
 cl_fmakunbound(VV[294]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[190]) /*  MAPC */;
 ecl_cmp_defun(VV[861]);                          /*  SYSDEF-FIND-ASDF */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC155__g598,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[163], ECL_NIL, VVtemp[158], VVtemp[72], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC156__g599,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[163], ECL_NIL, VVtemp[191], VVtemp[72], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC157__g600,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[163], ECL_NIL, VVtemp[192], VVtemp[72], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC158__g601,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[163], ECL_NIL, VVtemp[193], VVtemp[194], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC159__g602,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[163], ECL_NIL, VVtemp[195], VVtemp[196], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC160__g603,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[163], ECL_NIL, VVtemp[197], VVtemp[194], T0, ECL_T);
 }
 clos_load_defclass(VV[297], VVtemp[58], VVtemp[198], ECL_NIL);
 clos_load_defclass(VV[194], VVtemp[199], VVtemp[200], ECL_NIL);
 clos_load_defclass(VV[298], VVtemp[201], VVtemp[202], ECL_NIL);
 clos_load_defclass(VV[299], VVtemp[201], VVtemp[203], ECL_NIL);
 clos_load_defclass(VV[300], VVtemp[199], VVtemp[204], ECL_NIL);
 clos_load_defclass(VV[301], VVtemp[199], VVtemp[205], ECL_NIL);
 clos_load_defclass(VV[302], VVtemp[199], ECL_NIL, ECL_NIL);
 clos_load_defclass(VV[303], VVtemp[206], ECL_NIL, ECL_NIL);
 clos_load_defclass(VV[304], VVtemp[207], VVtemp[208], ECL_NIL);
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC161__g604,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[164], ECL_NIL, VVtemp[209], VVtemp[210], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC162__g605,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[164], ECL_NIL, VVtemp[211], VVtemp[210], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC163__g606,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, VV[158], ECL_NIL, VVtemp[58], VVtemp[58], T0, ECL_T);
 }
 {
  cl_object T0, T1, T2, T3, T4;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC164__g607,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 T1 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T0, VVtemp[215]);
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC165__g608,ECL_NIL,Cblock,0);
  T2 = v1;
 }
 T3 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T2, VVtemp[216]);
 T4 = cl_list(6, VVtemp[212], VVtemp[213], VVtemp[214], T1, T3, VVtemp[217]);
 clos_load_defclass(VV[306], ECL_NIL, T4, ECL_NIL);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC168__g621,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("PRINT-OBJECT",961), ECL_NIL, VVtemp[218], VVtemp[219], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC169__g644,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("SHARED-INITIALIZE",965), VVtemp[220], VVtemp[218], VVtemp[221], T0, ECL_T);
 }
 cl_fmakunbound(VV[309]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[222]) /*  MAPC */;
 ecl_cmp_defun(VV[866]);                          /*  NODE-FOR        */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC171__g666,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, VV[165], ECL_NIL, VVtemp[76], VVtemp[76], T0, ECL_T);
 }
 cl_fmakunbound(VV[311]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[223]) /*  MAPC */;
 ecl_cmp_defun(VV[868]);                          /*  MAKE-SUB-OPERATION */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC173__g677,ECL_NIL,Cblock,3);
  T0 = v1;
 }
 clos_install_method(6, VV[167], ECL_NIL, VVtemp[224], VVtemp[225], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC174__g681,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[166], ECL_NIL, VVtemp[46], VVtemp[226], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC175__g682,ECL_NIL,Cblock,3);
  T0 = v1;
 }
 clos_install_method(6, VVtemp[80], ECL_NIL, VVtemp[227], VVtemp[81], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC176__g689,ECL_NIL,Cblock,3);
  T0 = v1;
 }
 clos_install_method(6, VVtemp[80], ECL_NIL, VVtemp[228], VVtemp[229], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC177__g695,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[168], ECL_NIL, VVtemp[46], VVtemp[226], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC178__g696,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[169], ECL_NIL, VVtemp[230], VVtemp[231], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC179__g697,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[169], ECL_NIL, VVtemp[46], VVtemp[226], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC181__g698,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[170], ECL_NIL, VVtemp[46], VVtemp[226], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC182__g709,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[152], ECL_NIL, VVtemp[46], VVtemp[232], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC183__g725,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[152], ECL_NIL, VVtemp[233], VVtemp[232], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC184__g726,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[153], ECL_NIL, VVtemp[234], VVtemp[226], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC187__g727,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[148], ECL_NIL, VVtemp[46], VVtemp[226], T0, ECL_T);
 }
 si_Xmake_special(VV[316]);
 if (ecl_boundp(cl_env_copy,VV[316])) { goto L1007; }
 cl_set(VV[316],ECL_NIL);
L1007:;
 cl_fmakunbound(VV[317]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[235]) /*  MAPC */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(5, VV[317], VV[145], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[236]) /*  ENSURE-GENERIC-FUNCTION */;
 cl_fmakunbound(VV[318]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[237]) /*  MAPC */;
 ecl_cmp_defun(VV[873]);                          /*  RESOLVE-DEPENDENCY-NAME */
 cl_fmakunbound(VV[323]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[238]) /*  MAPC */;
 ecl_cmp_defun(VV[874]);                          /*  RESOLVE-DEPENDENCY-SPEC */
 cl_fmakunbound(VV[326]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[239]) /*  MAPC */;
 ecl_cmp_defun(VV[875]);                          /*  DO-ONE-DEP      */
 cl_fmakunbound(VV[328]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[240]) /*  MAPC */;
 ecl_cmp_defun(VV[876]);                          /*  DO-DEP          */
 si_Xmake_special(VV[331]);
 if (ecl_boundp(cl_env_copy,VV[331])) { goto L1046; }
 cl_set(VV[331],ecl_make_fixnum(0));
L1046:;
 cl_fmakunbound(VV[332]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[241]) /*  MAPC */;
 ecl_cmp_defun(VV[877]);                          /*  DO-COLLECT      */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC202__g792,ECL_NIL,Cblock,3);
  T0 = v1;
 }
 clos_install_method(6, VV[317], ECL_NIL, VVtemp[224], VVtemp[242], T0, ECL_T);
 }
 cl_fmakunbound(VV[337]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[243]) /*  MAPC */;
 ecl_cmp_defun(VV[883]);                          /*  FLATTEN-TREE    */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC208__g839,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[171], ECL_NIL, VVtemp[46], VVtemp[232], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC209__g842,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[147], ECL_NIL, VVtemp[244], VVtemp[232], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC210__g843,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[147], ECL_NIL, VVtemp[233], VVtemp[232], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC211__g850,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[149], ECL_NIL, VVtemp[46], VVtemp[232], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC212__g860,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[146], ECL_NIL, VVtemp[234], VVtemp[46], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC217__g873,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[146], VVtemp[245], VVtemp[234], VVtemp[46], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC218__g886,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[150], ECL_NIL, VVtemp[46], VVtemp[46], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC219__g887,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[154], ECL_NIL, VVtemp[234], VVtemp[46], T0, ECL_T);
 }
 {
  cl_object T0, T1, T2, T3, T4;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC220__g888,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 T1 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T0, VVtemp[247]);
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC221__g889,ECL_NIL,Cblock,0);
  T2 = v1;
 }
 T3 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T2, VVtemp[248]);
 T4 = cl_list(4, VVtemp[246], T1, T3, VVtemp[249]);
 clos_load_defclass(VV[341], VVtemp[76], T4, ECL_NIL);
 }
 cl_fmakunbound(VV[342]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[250]) /*  MAPC */;
 ecl_cmp_defun(VV[884]);                          /*  OUTPUT-FILE     */
 cl_fmakunbound(VV[345]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[251]) /*  MAPC */;
 ecl_cmp_defun(VV[885]);                          /*  ENSURE-ALL-DIRECTORIES-EXIST */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC224__g895,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[147], VVtemp[252], VVtemp[253], VVtemp[232], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC225__g896,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[147], VVtemp[220], VVtemp[46], VVtemp[232], T0, ECL_T);
 }
 cl_fmakunbound(VV[347]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[254]) /*  MAPC */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(5, VV[347], VV[145], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[58]) /*  ENSURE-GENERIC-FUNCTION */;
 cl_fmakunbound(VV[348]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[255]) /*  MAPC */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(5, VV[348], VV[145], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[256]) /*  ENSURE-GENERIC-FUNCTION */;
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC226__g897,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, VV[347], ECL_NIL, VVtemp[58], VVtemp[150], T0, ECL_T);
 }
 ecl_cmp_defun(VV[886]);                          /*  ENSURE-FUNCTION */
 ecl_cmp_defun(VV[888]);                          /*  CALL-AROUND-HOOK */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC229__g901,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[348], ECL_NIL, VVtemp[135], VVtemp[257], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC231__g902,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[147], ECL_NIL, VVtemp[258], VVtemp[232], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC232__g910,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[151], ECL_NIL, VVtemp[258], VVtemp[232], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC233__g911,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[147], ECL_NIL, VVtemp[259], VVtemp[232], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC234__g912,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[151], ECL_NIL, VVtemp[259], VVtemp[232], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC235__g913,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[152], ECL_NIL, VVtemp[259], VVtemp[232], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC236__g914,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[154], ECL_NIL, VVtemp[260], VVtemp[46], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC237__g915,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[154], ECL_NIL, VVtemp[261], VVtemp[46], T0, ECL_T);
 }
 clos_load_defclass(VV[356], VVtemp[76], ECL_NIL, ECL_NIL);
 clos_load_defclass(VV[25], VVtemp[262], ECL_NIL, ECL_NIL);
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC240__g926,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[146], ECL_NIL, VVtemp[263], VVtemp[226], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC241__g941,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[147], ECL_NIL, VVtemp[263], VVtemp[226], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC242__g947,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[147], ECL_NIL, VVtemp[264], VVtemp[232], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC243__g948,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[148], ECL_NIL, VVtemp[264], VVtemp[232], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC244__g949,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[151], ECL_NIL, VVtemp[46], VVtemp[232], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC245__g950,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[169], ECL_NIL, VVtemp[265], VVtemp[232], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC246__g951,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[154], ECL_NIL, VVtemp[266], VVtemp[46], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC247__g952,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[154], ECL_NIL, VVtemp[263], VVtemp[46], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC248__g953,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[154], ECL_NIL, VVtemp[267], VVtemp[46], T0, ECL_T);
 }
 clos_load_defclass(VV[358], VVtemp[262], ECL_NIL, ECL_NIL);
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC250__g960,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[147], ECL_NIL, VVtemp[268], VVtemp[226], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC251__g965,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[147], ECL_NIL, VVtemp[269], VVtemp[232], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC252__g966,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[151], ECL_NIL, VVtemp[270], VVtemp[232], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC253__g973,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[169], ECL_NIL, VVtemp[270], VVtemp[226], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC254__g980,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[148], ECL_NIL, VVtemp[271], VVtemp[226], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC255__g981,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[154], ECL_NIL, VVtemp[272], VVtemp[46], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC256__g982,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[154], ECL_NIL, VVtemp[273], VVtemp[46], T0, ECL_T);
 }
 clos_load_defclass(VV[360], VVtemp[76], ECL_NIL, ECL_NIL);
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC257__g983,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[147], ECL_NIL, VVtemp[274], VVtemp[232], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC258__g984,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(8, VV[148], ECL_NIL, VVtemp[275], VVtemp[232], T0, ECL_T, ECL_SYM("DOCUMENTATION",1222), _ecl_static_79);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC259__g985,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[169], VVtemp[245], VVtemp[275], VVtemp[226], T0, ECL_T);
 }
 cl_fmakunbound(VV[361]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[276]) /*  MAPC */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(5, VV[361], VV[145], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[277]) /*  ENSURE-GENERIC-FUNCTION */;
 cl_fmakunbound(VV[362]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[278]) /*  MAPC */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(5, VV[362], VV[145], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[279]) /*  ENSURE-GENERIC-FUNCTION */;
 cl_fmakunbound(VV[363]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[280]) /*  MAPC */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(5, VV[363], VV[145], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[281]) /*  ENSURE-GENERIC-FUNCTION */;
 cl_fmakunbound(VV[364]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[282]) /*  MAPC */;
 ecl_cmp_defun(VV[893]);                          /*  CLEANUP-UPGRADED-ASDF */
 cl_fmakunbound(VV[366]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[283]) /*  MAPC */;
 ecl_cmp_defun(VV[894]);                          /*  UPGRADE-ASDF    */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC262__g1006,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[363], ECL_NIL, VVtemp[284], VVtemp[285], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC263__g1023,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, VV[362], ECL_NIL, VVtemp[286], VVtemp[287], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC266__g1036,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, VV[361], ECL_NIL, VVtemp[234], VVtemp[288], T0, ECL_T);
 }
 cl_fmakunbound(VV[371]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[289]) /*  MAPC */;
 ecl_cmp_defun(VV[899]);                          /*  OOS             */
 {
  cl_object v1;
  v1 = cl_format(3, ECL_NIL, _ecl_static_84, _ecl_static_83);
  (cl_env_copy->function=ECL_CONS_CAR(VV[900]))->cfun.entry(3, v1, VV[371], ECL_SYM("FUNCTION",396)) /*  (SETF DOCUMENTATION) */;
 }
 (cl_env_copy->function=ECL_CONS_CAR(VV[900]))->cfun.entry(3, _ecl_static_83, VV[361], ECL_SYM("FUNCTION",396)) /*  (SETF DOCUMENTATION) */;
 cl_fmakunbound(VV[373]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[290]) /*  MAPC */;
 ecl_cmp_defun(VV[901]);                          /*  LOAD-SYSTEM     */
 cl_fmakunbound(VV[375]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[291]) /*  MAPC */;
 ecl_cmp_defun(VV[905]);                          /*  LOAD-SYSTEMS    */
 ecl_cmp_defun(VV[906]);                          /*  COMPONENT-LOADED-P */
 ecl_cmp_defun(VV[907]);                          /*  LOADED-SYSTEMS  */
 ecl_cmp_defun(VV[908]);                          /*  REQUIRE-SYSTEM  */
 cl_fmakunbound(VV[381]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[292]) /*  MAPC */;
 ecl_cmp_defun(VV[909]);                          /*  COMPILE-SYSTEM  */
 cl_fmakunbound(VV[383]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[293]) /*  MAPC */;
 ecl_cmp_defun(VV[910]);                          /*  TEST-SYSTEM     */
 cl_fmakunbound(VV[385]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[294]) /*  MAPC */;
 ecl_cmp_defun(VV[911]);                          /*  LOAD-PATHNAME   */
 cl_fmakunbound(VV[387]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[295]) /*  MAPC */;
 ecl_cmp_defun(VV[912]);                          /*  DETERMINE-SYSTEM-PATHNAME */
 cl_fmakunbound(VV[389]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[296]) /*  MAPC */;
 ecl_cmp_defun(VV[913]);                          /*  FIND-CLASS*     */
 cl_fmakunbound(VV[392]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[297]) /*  MAPC */;
 ecl_cmp_defun(VV[914]);                          /*  CLASS-FOR-TYPE  */
 cl_fmakunbound(VV[394]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[298]) /*  MAPC */;
 ecl_cmp_defun(VV[916]);                          /*  MAYBE-ADD-TREE  */
 cl_fmakunbound(VV[396]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[299]) /*  MAPC */;
 ecl_cmp_defun(VV[917]);                          /*  UNION-OF-DEPENDENCIES */
 si_Xmake_special(VV[398]);
 if (ecl_boundp(cl_env_copy,VV[398])) { goto L1306; }
 cl_set(VV[398],ECL_NIL);
L1306:;
 cl_fmakunbound(VV[399]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[300]) /*  MAPC */;
 ecl_cmp_defun(VV[918]);                          /*  SYSDEF-ERROR-COMPONENT */
 cl_fmakunbound(VV[401]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[301]) /*  MAPC */;
 ecl_cmp_defun(VV[919]);                          /*  CHECK-COMPONENT-INPUT */
 cl_fmakunbound(VV[403]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[302]) /*  MAPC */;
 ecl_cmp_defun(VV[920]);                          /*  %REMOVE-COMPONENT-INLINE-METHODS */
 cl_fmakunbound(VV[405]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[303]) /*  MAPC */;
 ecl_cmp_defun(VV[923]);                          /*  %DEFINE-COMPONENT-INLINE-METHODS */
 cl_fmakunbound(VV[408]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[304]) /*  MAPC */;
 ecl_cmp_defun(VV[924]);                          /*  %REFRESH-COMPONENT-INLINE-METHODS */
 cl_fmakunbound(VV[410]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[305]) /*  MAPC */;
 ecl_cmp_defun(VV[925]);                          /*  PARSE-COMPONENT-FORM */
 cl_fmakunbound(VV[423]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[306]) /*  MAPC */;
 ecl_cmp_defun(VV[930]);                          /*  RESET-SYSTEM    */
 cl_fmakunbound(VV[425]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[307]) /*  MAPC */;
 ecl_cmp_defun(VV[931]);                          /*  DO-DEFSYSTEM    */
 ecl_cmp_defmacro(VV[935]);                       /*  DEFSYSTEM       */
 cl_fmakunbound(VV[431]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[308]) /*  MAPC */;
 ecl_cmp_defun(VV[936]);                          /*  RUN-SHELL-COMMAND */
 cl_fmakunbound(VV[433]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[309]) /*  MAPC */;
 ecl_cmp_defun(VV[937]);                          /*  SYSTEM-DEFINITION-PATHNAME */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC295__g1149,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, VV[155], ECL_NIL, VVtemp[56], VVtemp[56], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC296__g1150,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, VV[155], ECL_NIL, VVtemp[188], VVtemp[310], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC297__g1151,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, VV[155], ECL_NIL, VVtemp[311], VVtemp[310], T0, ECL_T);
 }
 cl_fmakunbound(VV[435]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[312]) /*  MAPC */;
 ecl_cmp_defun(VV[938]);                          /*  SYSTEM-SOURCE-DIRECTORY */
 cl_fmakunbound(VV[437]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[313]) /*  MAPC */;
 ecl_cmp_defun(VV[939]);                          /*  RELATIVIZE-DIRECTORY */
 cl_fmakunbound(VV[439]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[314]) /*  MAPC */;
 ecl_cmp_defun(VV[940]);                          /*  RELATIVIZE-PATHNAME-DIRECTORY */
 cl_fmakunbound(VV[441]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[315]) /*  MAPC */;
 ecl_cmp_defun(VV[941]);                          /*  SYSTEM-RELATIVE-PATHNAME */
 cl_fmakunbound(VV[443]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[316]) /*  MAPC */;
 ecl_cmp_defun(VV[942]);                          /*  FIRST-FEATURE   */
 ecl_cmp_defun(VV[943]);                          /*  IMPLEMENTATION-TYPE */
 ecl_cmp_defun(VV[944]);                          /*  OPERATING-SYSTEM */
 ecl_cmp_defun(VV[945]);                          /*  ARCHITECTURE    */
 ecl_cmp_defun(VV[946]);                          /*  LISP-VERSION-STRING */
 cl_fmakunbound(VV[452]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[317]) /*  MAPC */;
 ecl_cmp_defun(VV[947]);                          /*  IMPLEMENTATION-IDENTIFIER */
 cl_fmakunbound(VV[454]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[318]) /*  MAPC */;
 ecl_cmp_defun(VV[948]);                          /*  HOSTNAME        */
 ecl_cmp_defun(VV[949]);                          /*  INTER-DIRECTORY-SEPARATOR */
 cl_fmakunbound(VV[457]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[319]) /*  MAPC */;
 ecl_cmp_defun(VV[950]);                          /*  USER-HOMEDIR    */
 cl_fmakunbound(VV[459]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[320]) /*  MAPC */;
 ecl_cmp_defun(VV[951]);                          /*  ENSURE-PATHNAME* */
 cl_fmakunbound(VV[461]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[321]) /*  MAPC */;
 ecl_cmp_defun(VV[952]);                          /*  SPLIT-PATHNAMES* */
 cl_fmakunbound(VV[463]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[322]) /*  MAPC */;
 ecl_cmp_defun(VV[953]);                          /*  GETENV-PATHNAME */
 cl_fmakunbound(VV[465]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[323]) /*  MAPC */;
 ecl_cmp_defun(VV[954]);                          /*  GETENV-PATHNAMES */
 cl_fmakunbound(VV[467]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[324]) /*  MAPC */;
 ecl_cmp_defun(VV[955]);                          /*  GETENV-ABSOLUTE-DIRECTORY */
 cl_fmakunbound(VV[471]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[325]) /*  MAPC */;
 ecl_cmp_defun(VV[956]);                          /*  GETENV-ABSOLUTE-DIRECTORIES */
 cl_fmakunbound(VV[473]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[326]) /*  MAPC */;
 ecl_cmp_defun(VV[957]);                          /*  GET-FOLDER-PATH */
 cl_fmakunbound(VV[479]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[327]) /*  MAPC */;
 ecl_cmp_defun(VV[958]);                          /*  USER-CONFIGURATION-DIRECTORIES */
 cl_fmakunbound(VV[481]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[328]) /*  MAPC */;
 ecl_cmp_defun(VV[959]);                          /*  SYSTEM-CONFIGURATION-DIRECTORIES */
 cl_fmakunbound(VV[484]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[329]) /*  MAPC */;
 ecl_cmp_defun(VV[960]);                          /*  IN-FIRST-DIRECTORY */
 cl_fmakunbound(VV[492]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[330]) /*  MAPC */;
 ecl_cmp_defun(VV[962]);                          /*  IN-USER-CONFIGURATION-DIRECTORY */
 cl_fmakunbound(VV[494]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[331]) /*  MAPC */;
 ecl_cmp_defun(VV[963]);                          /*  IN-SYSTEM-CONFIGURATION-DIRECTORY */
 cl_fmakunbound(VV[496]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[332]) /*  MAPC */;
 ecl_cmp_defun(VV[964]);                          /*  CONFIGURATION-INHERITANCE-DIRECTIVE-P */
 cl_fmakunbound(VV[499]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[333]) /*  MAPC */;
 ecl_cmp_defun(VV[965]);                          /*  REPORT-INVALID-FORM */
 si_Xmake_special(VV[502]);
 if (ecl_boundp(cl_env_copy,VV[502])) { goto L1565; }
 cl_set(VV[502],ECL_NIL);
L1565:;
 cl_fmakunbound(VV[503]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[334]) /*  MAPC */;
 ecl_cmp_defun(VV[966]);                          /*  VALIDATE-CONFIGURATION-FORM */
 cl_fmakunbound(VV[510]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[335]) /*  MAPC */;
 ecl_cmp_defun(VV[969]);                          /*  VALIDATE-CONFIGURATION-FILE */
 cl_fmakunbound(VV[512]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[336]) /*  MAPC */;
 ecl_cmp_defun(VV[971]);                          /*  HIDDEN-FILE-P   */
 cl_fmakunbound(VV[514]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[337]) /*  MAPC */;
 ecl_cmp_defun(VV[972]);                          /*  DIRECTORY*      */
 cl_fmakunbound(VV[516]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[338]) /*  MAPC */;
 ecl_cmp_defun(VV[973]);                          /*  VALIDATE-CONFIGURATION-DIRECTORY */
 si_Xmake_special(VV[519]);
 if (ecl_boundp(cl_env_copy,VV[519])) { goto L1607; }
 cl_set(VV[519],ECL_NIL);
L1607:;
 {
  cl_object T0;
 si_Xmake_special(VV[520]);
 if (ecl_boundp(cl_env_copy,VV[520])) { goto L1614; }
 T0 = ecl_function_dispatch(cl_env_copy,VV[467])(1, _ecl_static_113) /*  GETENV-ABSOLUTE-DIRECTORY */;
 value0 = LC332try(3, T0, _ecl_static_114, VV[521]);
 if ((value0)!=ECL_NIL) { goto L1618; }
 if (Null(ecl_function_dispatch(cl_env_copy,VV[261])(0) /*  OS-WINDOWS-P */)) { goto L1621; }
 value0 = ecl_function_dispatch(cl_env_copy,VV[473])(1, VV[474]) /*  GET-FOLDER-PATH */;
 if ((value0)!=ECL_NIL) { goto L1625; }
 T0 = ecl_function_dispatch(cl_env_copy,VV[473])(1, VV[475]) /*  GET-FOLDER-PATH */;
 goto L1623;
L1625:;
 T0 = value0;
 goto L1623;
L1623:;
 value0 = LC332try(4, T0, _ecl_static_114, _ecl_static_115, VV[521]);
 goto L1620;
L1621:;
 value0 = ECL_NIL;
L1620:;
 if ((value0)!=ECL_NIL) { goto L1618; }
 cl_set(VV[520],VVtemp[339]);
 goto L1616;
L1618:;
 cl_set(VV[520],value0);
 goto L1616;
L1616:;
L1614:;
 }
 cl_fmakunbound(VV[522]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[340]) /*  MAPC */;
 ecl_cmp_defun(VV[974]);                          /*  OUTPUT-TRANSLATIONS */
 cl_fmakunbound(VVtemp[341]);
 ecl_cmp_defun(VV[975]);                          /*  (SETF OUTPUT-TRANSLATIONS) */
 cl_fmakunbound(VV[527]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[342]) /*  MAPC */;
 ecl_cmp_defun(VV[976]);                          /*  OUTPUT-TRANSLATIONS-INITIALIZED-P */
 cl_fmakunbound(VV[529]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[343]) /*  MAPC */;
 ecl_cmp_defun(VV[977]);                          /*  CLEAR-OUTPUT-TRANSLATIONS */
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[344]) /*  MAPC */;
 cl_fmakunbound(VV[531]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[345]) /*  MAPC */;
 ecl_cmp_defun(VV[978]);                          /*  RESOLVE-RELATIVE-LOCATION-COMPONENT */
 si_Xmake_special(VV[542]);
 if (ecl_boundp(cl_env_copy,VV[542])) { goto L1667; }
 cl_set(VV[542],ECL_NIL);
L1667:;
 cl_fmakunbound(VV[543]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[346]) /*  MAPC */;
 ecl_cmp_defun(VV[981]);                          /*  RESOLVE-ABSOLUTE-LOCATION-COMPONENT */
 cl_fmakunbound(VV[552]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[347]) /*  MAPC */;
 ecl_cmp_defun(VV[982]);                          /*  RESOLVE-LOCATION */
 cl_fmakunbound(VV[554]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[348]) /*  MAPC */;
 ecl_cmp_defun(VV[983]);                          /*  LOCATION-DESIGNATOR-P */
 cl_fmakunbound(VV[560]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[349]) /*  MAPC */;
 ecl_cmp_defun(VV[984]);                          /*  LOCATION-FUNCTION-P */
 cl_fmakunbound(VV[562]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[350]) /*  MAPC */;
 ecl_cmp_defun(VV[985]);                          /*  VALIDATE-OUTPUT-TRANSLATIONS-DIRECTIVE */
 cl_fmakunbound(VV[568]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[351]) /*  MAPC */;
 ecl_cmp_defun(VV[986]);                          /*  VALIDATE-OUTPUT-TRANSLATIONS-FORM */
 cl_fmakunbound(VV[572]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[352]) /*  MAPC */;
 ecl_cmp_defun(VV[987]);                          /*  VALIDATE-OUTPUT-TRANSLATIONS-FILE */
 cl_fmakunbound(VV[574]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[353]) /*  MAPC */;
 ecl_cmp_defun(VV[988]);                          /*  VALIDATE-OUTPUT-TRANSLATIONS-DIRECTORY */
 cl_fmakunbound(VV[576]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[354]) /*  MAPC */;
 ecl_cmp_defun(VV[989]);                          /*  PARSE-OUTPUT-TRANSLATIONS-STRING */
 si_Xmake_special(VV[579]);
 cl_set(VV[579],VVtemp[355]);
 cl_fmakunbound(VV[580]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[356]) /*  MAPC */;
 ecl_cmp_defun(VV[990]);                          /*  WRAPPING-OUTPUT-TRANSLATIONS */
 si_Xmake_special(VV[583]);
 cl_set(VV[583],ecl_function_dispatch(cl_env_copy,VV[95])(1, _ecl_static_124) /*  COERCE-PATHNAME */);
 si_Xmake_special(VV[584]);
 cl_set(VV[584],ecl_function_dispatch(cl_env_copy,VV[95])(1, _ecl_static_125) /*  COERCE-PATHNAME */);
 cl_fmakunbound(VV[585]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[357]) /*  MAPC */;
 ecl_cmp_defun(VV[991]);                          /*  USER-OUTPUT-TRANSLATIONS-PATHNAME */
 cl_fmakunbound(VV[587]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[358]) /*  MAPC */;
 ecl_cmp_defun(VV[992]);                          /*  SYSTEM-OUTPUT-TRANSLATIONS-PATHNAME */
 cl_fmakunbound(VV[589]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[359]) /*  MAPC */;
 ecl_cmp_defun(VV[993]);                          /*  USER-OUTPUT-TRANSLATIONS-DIRECTORY-PATHNAME */
 cl_fmakunbound(VV[591]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[360]) /*  MAPC */;
 ecl_cmp_defun(VV[994]);                          /*  SYSTEM-OUTPUT-TRANSLATIONS-DIRECTORY-PATHNAME */
 cl_fmakunbound(VV[593]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[361]) /*  MAPC */;
 ecl_cmp_defun(VV[995]);                          /*  ENVIRONMENT-OUTPUT-TRANSLATIONS */
 cl_fmakunbound(VV[595]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[362]) /*  MAPC */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(5, VV[595], VV[145], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[363]) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[364]) /*  MAPC */;
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[365]) /*  MAPC */;
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC356__g1236,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, VV[595], ECL_NIL, VVtemp[311], VVtemp[366], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC357__g1237,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, VV[595], ECL_NIL, VVtemp[367], VVtemp[368], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC358__g1238,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, VV[595], ECL_NIL, VVtemp[188], VVtemp[369], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC359__g1239,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, VV[595], ECL_NIL, VVtemp[181], VVtemp[370], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC360__g1240,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, VV[595], ECL_NIL, VVtemp[371], VVtemp[372], T0, ECL_T);
 }
 cl_fmakunbound(VV[598]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[373]) /*  MAPC */;
 ecl_cmp_defun(VV[996]);                          /*  INHERIT-OUTPUT-TRANSLATIONS */
 cl_fmakunbound(VV[600]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[374]) /*  MAPC */;
 ecl_cmp_defun(VV[997]);                          /*  PROCESS-OUTPUT-TRANSLATIONS-DIRECTIVE */
 cl_fmakunbound(VV[609]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[375]) /*  MAPC */;
 ecl_cmp_defun(VV[998]);                          /*  COMPUTE-OUTPUT-TRANSLATIONS */
 si_Xmake_special(VV[611]);
 if (ecl_boundp(cl_env_copy,VV[611])) { goto L1836; }
 cl_set(VV[611],ECL_NIL);
L1836:;
 cl_fmakunbound(VV[612]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[376]) /*  MAPC */;
 ecl_cmp_defun(VV[999]);                          /*  INITIALIZE-OUTPUT-TRANSLATIONS */
 cl_fmakunbound(VV[614]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[377]) /*  MAPC */;
 ecl_cmp_defun(VV[1000]);                         /*  DISABLE-OUTPUT-TRANSLATIONS */
 cl_fmakunbound(VV[617]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[378]) /*  MAPC */;
 ecl_cmp_defun(VV[1001]);                         /*  ENSURE-OUTPUT-TRANSLATIONS */
 cl_fmakunbound(VV[619]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[379]) /*  MAPC */;
 ecl_cmp_defun(VV[1002]);                         /*  TRANSLATE-PATHNAME* */
 cl_fmakunbound(VV[621]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[380]) /*  MAPC */;
 ecl_cmp_defun(VV[1003]);                         /*  APPLY-OUTPUT-TRANSLATIONS */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC370__g1262,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(8, VV[151], VVtemp[245], VV[604], VVtemp[46], T0, ECL_T, ECL_SYM("DOCUMENTATION",1222), _ecl_static_128);
 }
 cl_fmakunbound(VV[624]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[381]) /*  MAPC */;
 ecl_cmp_defun(VV[1004]);                         /*  COMPILE-FILE-PATHNAME* */
 cl_fmakunbound(VV[626]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[382]) /*  MAPC */;
 ecl_cmp_defun(VV[1005]);                         /*  TMPIZE-PATHNAME */
 cl_fmakunbound(VV[628]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[383]) /*  MAPC */;
 ecl_cmp_defun(VV[1006]);                         /*  DELETE-FILE-IF-EXISTS */
 cl_fmakunbound(VV[27]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[384]) /*  MAPC */;
 ecl_cmp_defun(VV[1007]);                         /*  COMPILE-FILE*   */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC375__g1279,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, VV[361], VVtemp[252], VV[604], VVtemp[385], T0, ECL_T);
 }
 cl_fmakunbound(VV[639]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[386]) /*  MAPC */;
 ecl_cmp_defun(VV[1010]);                         /*  ENABLE-ASDF-BINARY-LOCATIONS-COMPATIBILITY */
 si_Xmake_special(VV[643]);
 if (ecl_boundp(cl_env_copy,VV[643])) { goto L1917; }
 cl_set(VV[643],VVtemp[387]);
L1917:;
 si_Xmake_special(VV[644]);
 if (ecl_boundp(cl_env_copy,VV[644])) { goto L1924; }
 cl_set(VV[644],ecl_symbol_value(VV[643]));
L1924:;
 si_Xmake_special(VV[645]);
 if (ecl_boundp(cl_env_copy,VV[645])) { goto L1931; }
 cl_set(VV[645],ECL_NIL);
L1931:;
 cl_fmakunbound(VV[646]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[388]) /*  MAPC */;
 ecl_cmp_defun(VV[1016]);                         /*  SOURCE-REGISTRY-INITIALIZED-P */
 cl_fmakunbound(VV[648]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[389]) /*  MAPC */;
 ecl_cmp_defun(VV[1017]);                         /*  CLEAR-SOURCE-REGISTRY */
 si_Xmake_special(VV[650]);
 cl_set(VV[650],cl_make_pathname(8, ECL_SYM("DIRECTORY",1219), ECL_NIL, ECL_SYM("NAME",1273), ecl_symbol_value(VV[132]), ECL_SYM("TYPE",1318), _ecl_static_135, ECL_SYM("VERSION",1326), ECL_SYM("NEWEST",1276)));
 cl_fmakunbound(VV[651]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[390]) /*  MAPC */;
 ecl_cmp_defun(VV[1018]);                         /*  FILTER-LOGICAL-DIRECTORY-RESULTS */
 cl_fmakunbound(VV[653]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[391]) /*  MAPC */;
 ecl_cmp_defun(VV[1019]);                         /*  DIRECTORY-FILES */
 cl_fmakunbound(VV[657]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[392]) /*  MAPC */;
 ecl_cmp_defun(VV[1020]);                         /*  DIRECTORY-ASD-FILES */
 cl_fmakunbound(VV[659]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[393]) /*  MAPC */;
 ecl_cmp_defun(VV[1021]);                         /*  SUBDIRECTORIES  */
 cl_fmakunbound(VV[661]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[394]) /*  MAPC */;
 ecl_cmp_defun(VV[1022]);                         /*  COLLECT-ASDS-IN-DIRECTORY */
 cl_fmakunbound(VV[663]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[395]) /*  MAPC */;
 ecl_cmp_defun(VV[1023]);                         /*  COLLECT-SUB*DIRECTORIES */
 cl_fmakunbound(VV[665]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[396]) /*  MAPC */;
 ecl_cmp_defun(VV[1024]);                         /*  COLLECT-SUB*DIRECTORIES-ASD-FILES */
 cl_fmakunbound(VV[667]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[397]) /*  MAPC */;
 ecl_cmp_defun(VV[1027]);                         /*  VALIDATE-SOURCE-REGISTRY-DIRECTIVE */
 cl_fmakunbound(VV[679]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[398]) /*  MAPC */;
 ecl_cmp_defun(VV[1028]);                         /*  VALIDATE-SOURCE-REGISTRY-FORM */
 cl_fmakunbound(VV[682]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[399]) /*  MAPC */;
 ecl_cmp_defun(VV[1029]);                         /*  VALIDATE-SOURCE-REGISTRY-FILE */
 cl_fmakunbound(VV[684]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[400]) /*  MAPC */;
 ecl_cmp_defun(VV[1030]);                         /*  VALIDATE-SOURCE-REGISTRY-DIRECTORY */
 cl_fmakunbound(VV[686]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[401]) /*  MAPC */;
 ecl_cmp_defun(VV[1031]);                         /*  PARSE-SOURCE-REGISTRY-STRING */
 cl_fmakunbound(VV[690]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[402]) /*  MAPC */;
 ecl_cmp_defun(VV[1032]);                         /*  REGISTER-ASD-DIRECTORY */
 si_Xmake_special(VV[692]);
 cl_set(VV[692],VVtemp[403]);
 si_Xmake_special(VV[693]);
 cl_set(VV[693],ecl_function_dispatch(cl_env_copy,VV[95])(1, _ecl_static_142) /*  COERCE-PATHNAME */);
 si_Xmake_special(VV[694]);
 cl_set(VV[694],ecl_function_dispatch(cl_env_copy,VV[95])(1, _ecl_static_143) /*  COERCE-PATHNAME */);
 cl_fmakunbound(VV[695]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[404]) /*  MAPC */;
 ecl_cmp_defun(VV[1036]);                         /*  WRAPPING-SOURCE-REGISTRY */
 cl_fmakunbound(VV[697]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[405]) /*  MAPC */;
 ecl_cmp_defun(VV[1037]);                         /*  DEFAULT-SOURCE-REGISTRY */
 cl_fmakunbound(VV[700]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[406]) /*  MAPC */;
 ecl_cmp_defun(VV[1038]);                         /*  USER-SOURCE-REGISTRY */
 cl_fmakunbound(VV[702]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[407]) /*  MAPC */;
 ecl_cmp_defun(VV[1039]);                         /*  SYSTEM-SOURCE-REGISTRY */
 cl_fmakunbound(VV[704]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[408]) /*  MAPC */;
 ecl_cmp_defun(VV[1040]);                         /*  USER-SOURCE-REGISTRY-DIRECTORY */
 cl_fmakunbound(VV[706]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[409]) /*  MAPC */;
 ecl_cmp_defun(VV[1041]);                         /*  SYSTEM-SOURCE-REGISTRY-DIRECTORY */
 cl_fmakunbound(VV[708]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[410]) /*  MAPC */;
 ecl_cmp_defun(VV[1042]);                         /*  ENVIRONMENT-SOURCE-REGISTRY */
 cl_fmakunbound(VV[710]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[411]) /*  MAPC */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(5, VV[710], VV[145], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[412]) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[413]) /*  MAPC */;
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[414]) /*  MAPC */;
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC408__g1341,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, VV[710], ECL_NIL, VVtemp[311], VVtemp[415], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC409__g1342,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, VV[710], ECL_NIL, VVtemp[367], VVtemp[416], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC410__g1343,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, VV[710], ECL_NIL, VVtemp[188], VVtemp[417], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC411__g1344,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, VV[710], ECL_NIL, VVtemp[181], VVtemp[415], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC412__g1345,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, VV[710], ECL_NIL, VVtemp[371], VVtemp[418], T0, ECL_T);
 }
 cl_fmakunbound(VV[712]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[419]) /*  MAPC */;
 ecl_cmp_defun(VV[1045]);                         /*  INHERIT-SOURCE-REGISTRY */
 cl_fmakunbound(VV[714]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[420]) /*  MAPC */;
 ecl_cmp_defun(VV[1046]);                         /*  PROCESS-SOURCE-REGISTRY-DIRECTIVE */
 cl_fmakunbound(VV[722]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[421]) /*  MAPC */;
 ecl_cmp_defun(VV[1047]);                         /*  FLATTEN-SOURCE-REGISTRY */
 cl_fmakunbound(VV[724]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[422]) /*  MAPC */;
 ecl_cmp_defun(VV[1048]);                         /*  COMPUTE-SOURCE-REGISTRY */
 si_Xmake_special(VV[727]);
 if (ecl_boundp(cl_env_copy,VV[727])) { goto L2162; }
 cl_set(VV[727],ECL_NIL);
L2162:;
 cl_fmakunbound(VV[728]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[423]) /*  MAPC */;
 ecl_cmp_defun(VV[1049]);                         /*  INITIALIZE-SOURCE-REGISTRY */
 cl_fmakunbound(VV[730]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[424]) /*  MAPC */;
 ecl_cmp_defun(VV[1050]);                         /*  ENSURE-SOURCE-REGISTRY */
 cl_fmakunbound(VV[732]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[425]) /*  MAPC */;
 ecl_cmp_defun(VV[1051]);                         /*  SYSDEF-SOURCE-REGISTRY-SEARCH */
 cl_fmakunbound(VV[734]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[426]) /*  MAPC */;
 ecl_cmp_defun(VV[1052]);                         /*  CLEAR-CONFIGURATION */
 {
  cl_object T0, T1;
  cl_object  volatile env0;
  cl_object  volatile CLV0
  ;
 ecl_cmp_defun(VV[1053]);                         /*  REGISTER-PRE-BUILT-SYSTEM */
 {
  cl_object v1;
  cl_object v2;
  cl_object env1 = env0;
  v1 = ecl_symbol_value(ECL_SYM("*MODULE-PROVIDER-FUNCTIONS*",42));
  env1 = ECL_NIL;
  CLV0 = env1 = CONS(ECL_NIL,env1);               /*  F               */
  if (ecl_unlikely(!ECL_LISTP(v1))) FEtype_error_list(v1);
  v2 = v1;
  {
   cl_object v3;
   cl_object v4;
   v3 = ecl_list1(ECL_NIL);
   v4 = v3;
L2207:;
   if (!(ecl_endp(v2))) { goto L2209; }
   goto L2208;
L2209:;
   ECL_CONS_CAR(CLV0) = _ecl_car(v2);
   {
    cl_object v5;
    v5 = _ecl_cdr(v2);
    if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
    v2 = v5;
   }
   if ((ECL_CONS_CAR(CLV0))==(VV[737])) { goto L2217; }
   if (ecl_unlikely(ECL_ATOM(v4))) FEtype_error_cons(v4);
   T0 = v4;
   {cl_object v5;
    v5 = ECL_NIL;
    v5 = ecl_make_cclosure_va((cl_objectfn)LC425__g1400,env1,Cblock);
    T1 = v5;
   }
   v4 = ecl_list1(T1);
   (ECL_CONS_CDR(T0)=v4,T0);
L2217:;
   goto L2207;
L2208:;
   cl_set(ECL_SYM("*MODULE-PROVIDER-FUNCTIONS*",42),ecl_cdr(v3));
   goto L2201;
  }
 }
L2201:;
 cl_set(VV[26],VV[738]);
 ecl_cmp_defun(VV[1054]);                         /*  COMPILE-FILE-KEEPING-OBJECT */
 }
 cl_fmakunbound(VV[737]);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[427]) /*  MAPC */;
 ecl_cmp_defun(VV[1056]);                         /*  MODULE-PROVIDE-ASDF */
 cl_eval(VVtemp[428]);
 if (Null(ecl_symbol_value(VV[502]))) { goto L2240; }
 ecl_function_dispatch(cl_env_copy,VV[734])(0)    /*  CLEAR-CONFIGURATION */;
 cl_set(VV[502],ECL_NIL);
L2240:;
 {
  cl_object T0;
 if (Null(ecl_symbol_value(ECL_SYM("*LOAD-VERBOSE*",39)))) { goto L2244; }
 T0 = ecl_function_dispatch(cl_env_copy,VV[215])(0) /*  ASDF-VERSION  */;
 ecl_function_dispatch(cl_env_copy,VV[66])(2, _ecl_static_153, T0) /*  ASDF-MESSAGE */;
L2244:;
 }
 cl_set(ECL_SYM("*FEATURES*",34),cl_adjoin(2, VV[1], ecl_symbol_value(ECL_SYM("*FEATURES*",34))));
 cl_set(ECL_SYM("*FEATURES*",34),cl_adjoin(2, VV[743], ecl_symbol_value(ECL_SYM("*FEATURES*",34))));
 cl_provide(VV[1]);
}
