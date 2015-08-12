/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:LSP;DEFPACKAGE.LSP                                */
#include <ecl/ecl-cmp.h>
#include "lsp/defpackage.eclh"
/*	local function DEFPACKAGE                                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC4defpackage(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4name;
   v3 = ecl_cdr(v1);
   {
    cl_object v5;
    if (!(v3==ECL_NIL)) { goto L4; }
    si_dm_too_few_arguments(v1);
L4:;
    {
     cl_object v6;
     v6 = ecl_car(v3);
     v3 = ecl_cdr(v3);
     v5 = v6;
    }
    value0 = ecl_make_bool(ECL_SYMBOLP(v5));
    if ((value0)!=ECL_NIL) { goto L12; }
    value0 = ecl_make_bool(ECL_STRINGP(v5));
    if ((value0)!=ECL_NIL) { goto L12; }
    T0 = ecl_make_bool(ECL_CHARACTERP(v5));
    goto L10;
L12:;
    T0 = value0;
    goto L10;
L10:;
    if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[0],v5);
    v4name = v5;
   }
   {
    cl_object v5;
    v5 = v3;
    goto L19;
L18:;
    {
     cl_object v6option;
     v6option = ecl_car(v5);
     T0 = ecl_car(v6option);
     if ((si_memq(T0,VV[1]))!=ECL_NIL) { goto L23; }
     cl_cerror(3, _ecl_static_1, _ecl_static_2, v6option);
L23:;
    }
    v5 = ecl_cdr(v5);
L19:;
    if (Null(v5)) { goto L27; }
    goto L18;
L27:;
   }
   {
    cl_object v5;
    v5 = VV[2];
    goto L33;
L32:;
    {
     cl_object v6option;
     v6option = ecl_car(v5);
     T0 = (ECL_SYM("CAR",180)->symbol.gfdef);
     T1 = cl_count(4, v6option, v3, ECL_SYM("KEY",1262), T0);
     if (!((2)<=(ecl_to_fixnum(T1)))) { goto L37; }
     si_simple_program_error(2, _ecl_static_3, v6option);
L37:;
    }
    v5 = ecl_cdr(v5);
L33:;
    if (Null(v5)) { goto L42; }
    goto L32;
L42:;
   }
   v4name = cl_string(v4name);
   {
    cl_object v5nicknames;
    cl_object v6documentation;
    cl_object v7shadowed_symbol_names;
    cl_object v8interned_symbol_names;
    cl_object v9exported_symbol_names;
    cl_object v10shadowing_imported_from_symbol_names_list;
    cl_object v11imported_from_symbol_names_list;
    cl_object v12exported_from_package_names;
    v5nicknames = LC3option_values(ECL_SYM("NICKNAMES",1277), v3);
    v6documentation = LC3option_values(ECL_SYM("DOCUMENTATION",1222), v3);
    v7shadowed_symbol_names = LC3option_values(ECL_SYM("SHADOW",1306), v3);
    v8interned_symbol_names = LC3option_values(ECL_SYM("INTERN",1257), v3);
    v9exported_symbol_names = LC3option_values(ECL_SYM("EXPORT",1233), v3);
    v10shadowing_imported_from_symbol_names_list = LC2option_values_list(VV[3], v3);
    v11imported_from_symbol_names_list = LC2option_values_list(ECL_SYM("IMPORT-FROM",1248), v3);
    v12exported_from_package_names = LC3option_values(ECL_SYM("EXPORT-FROM",1234), v3);
    {
     cl_object v13;
     {
      cl_object v14list;
      cl_object v15;
      v14list = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v10shadowing_imported_from_symbol_names_list))) FEtype_error_list(v10shadowing_imported_from_symbol_names_list);
      v15 = v10shadowing_imported_from_symbol_names_list;
      {
       cl_object v16;
       cl_object v17;
       v16 = ecl_list1(ECL_NIL);
       v17 = v16;
L62:;
       if (!(ecl_endp(v15))) { goto L64; }
       goto L63;
L64:;
       v14list = _ecl_car(v15);
       {
        cl_object v18;
        v18 = _ecl_cdr(v15);
        if (ecl_unlikely(!ECL_LISTP(v18))) FEtype_error_list(v18);
        v15 = v18;
       }
       {
        cl_object v18;
        T1 = ecl_cdr(v14list);
        v18 = cl_copy_list(T1);
        if (ecl_unlikely(ECL_ATOM(v17))) FEtype_error_cons(v17);
        T1 = v17;
        (ECL_CONS_CDR(T1)=v18,T1);
        if (Null(v18)) { goto L72; }
       }
       T1 = ecl_cdr(v17);
       v17 = ecl_last(T1,1);
L72:;
       goto L62;
L63:;
       T0 = ecl_cdr(v16);
       goto L56;
      }
     }
L56:;
     {
      cl_object v14list;
      cl_object v15;
      v14list = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v11imported_from_symbol_names_list))) FEtype_error_list(v11imported_from_symbol_names_list);
      v15 = v11imported_from_symbol_names_list;
      {
       cl_object v16;
       cl_object v17;
       v16 = ecl_list1(ECL_NIL);
       v17 = v16;
L87:;
       if (!(ecl_endp(v15))) { goto L89; }
       goto L88;
L89:;
       v14list = _ecl_car(v15);
       {
        cl_object v18;
        v18 = _ecl_cdr(v15);
        if (ecl_unlikely(!ECL_LISTP(v18))) FEtype_error_list(v18);
        v15 = v18;
       }
       {
        cl_object v18;
        T2 = ecl_cdr(v14list);
        v18 = cl_copy_list(T2);
        if (ecl_unlikely(ECL_ATOM(v17))) FEtype_error_cons(v17);
        T2 = v17;
        (ECL_CONS_CDR(T2)=v18,T2);
        if (Null(v18)) { goto L97; }
       }
       T2 = ecl_cdr(v17);
       v17 = ecl_last(T2,1);
L97:;
       goto L87;
L88:;
       T1 = ecl_cdr(v16);
       goto L81;
      }
     }
L81:;
     v13 = L7find_duplicates(4, v7shadowed_symbol_names, v8interned_symbol_names, T0, T1);
     goto L108;
L107:;
     {
      cl_object v14duplicate;
      v14duplicate = ecl_car(v13);
      T0 = ecl_car(v14duplicate);
      {
       cl_object v15;
       cl_object v16num;
       cl_object v17;
       v15 = ecl_cdr(v14duplicate);
       v16num = ECL_NIL;
       if (ecl_unlikely(!ECL_LISTP(v15))) FEtype_error_list(v15);
       v17 = v15;
       {
        cl_object v18;
        cl_object v19;
        v18 = ecl_list1(ECL_NIL);
        v19 = v18;
L120:;
        if (!(ecl_endp(v17))) { goto L122; }
        goto L121;
L122:;
        v16num = _ecl_car(v17);
        {
         cl_object v20;
         v20 = _ecl_cdr(v17);
         if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
         v17 = v20;
        }
        if (ecl_unlikely(ECL_ATOM(v19))) FEtype_error_cons(v19);
        T2 = v19;
        if (!((v16num)==(ecl_make_fixnum(1)))) { goto L135; }
        T3 = ECL_SYM("SHADOW",1306);
        goto L134;
L135:;
        if (!((v16num)==(ecl_make_fixnum(2)))) { goto L137; }
        T3 = ECL_SYM("INTERN",1257);
        goto L134;
L137:;
        if (!((v16num)==(ecl_make_fixnum(3)))) { goto L139; }
        T3 = VV[3];
        goto L134;
L139:;
        if (!((v16num)==(ecl_make_fixnum(4)))) { goto L141; }
        T3 = ECL_SYM("IMPORT-FROM",1248);
        goto L134;
L141:;
        T3 = ECL_NIL;
L134:;
        v19 = ecl_list1(T3);
        (ECL_CONS_CDR(T2)=v19,T2);
        goto L120;
L121:;
        T1 = ecl_cdr(v18);
        goto L113;
       }
      }
L113:;
      si_simple_program_error(3, _ecl_static_4, T0, T1);
     }
     v13 = ecl_cdr(v13);
L108:;
     if (Null(v13)) { goto L147; }
     goto L107;
L147:;
    }
    {
     cl_object v13;
     v13 = L7find_duplicates(2, v9exported_symbol_names, v8interned_symbol_names);
     goto L153;
L152:;
     {
      cl_object v14duplicate;
      v14duplicate = ecl_car(v13);
      T0 = ecl_car(v14duplicate);
      {
       cl_object v15;
       cl_object v16num;
       cl_object v17;
       v15 = ecl_cdr(v14duplicate);
       v16num = ECL_NIL;
       if (ecl_unlikely(!ECL_LISTP(v15))) FEtype_error_list(v15);
       v17 = v15;
       {
        cl_object v18;
        cl_object v19;
        v18 = ecl_list1(ECL_NIL);
        v19 = v18;
L165:;
        if (!(ecl_endp(v17))) { goto L167; }
        goto L166;
L167:;
        v16num = _ecl_car(v17);
        {
         cl_object v20;
         v20 = _ecl_cdr(v17);
         if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
         v17 = v20;
        }
        if (ecl_unlikely(ECL_ATOM(v19))) FEtype_error_cons(v19);
        T2 = v19;
        if (!((v16num)==(ecl_make_fixnum(1)))) { goto L180; }
        T3 = ECL_SYM("EXPORT",1233);
        goto L179;
L180:;
        if (!((v16num)==(ecl_make_fixnum(2)))) { goto L182; }
        T3 = ECL_SYM("INTERN",1257);
        goto L179;
L182:;
        T3 = ECL_NIL;
L179:;
        v19 = ecl_list1(T3);
        (ECL_CONS_CDR(T2)=v19,T2);
        goto L165;
L166:;
        T1 = ecl_cdr(v18);
        goto L158;
       }
      }
L158:;
      si_simple_program_error(3, _ecl_static_4, T0, T1);
     }
     v13 = ecl_cdr(v13);
L153:;
     if (Null(v13)) { goto L188; }
     goto L152;
L188:;
    }
    T0 = cl_list(2, ECL_SYM("QUOTE",679), v5nicknames);
    T1 = ecl_car(v6documentation);
    if (Null(ecl_assql(ECL_SYM("USE",1323),v3))) { goto L191; }
    T2 = LC3option_values(ECL_SYM("USE",1323), v3);
    goto L190;
L191:;
    T2 = _ecl_static_5;
L190:;
    T3 = cl_list(2, ECL_SYM("QUOTE",679), T2);
    T4 = cl_list(2, ECL_SYM("QUOTE",679), v7shadowed_symbol_names);
    T5 = cl_list(2, ECL_SYM("QUOTE",679), v8interned_symbol_names);
    T6 = cl_list(2, ECL_SYM("QUOTE",679), v9exported_symbol_names);
    T7 = cl_list(2, ECL_SYM("QUOTE",679), v10shadowing_imported_from_symbol_names_list);
    T8 = cl_list(2, ECL_SYM("QUOTE",679), v11imported_from_symbol_names_list);
    T9 = cl_list(2, ECL_SYM("QUOTE",679), v12exported_from_package_names);
    T10 = cl_list(11, VV[5], v4name, T0, T1, T3, T4, T5, T6, T7, T8, T9);
    value0 = cl_list(3, ECL_SYM("EVAL-WHEN",340), VV[4], T10);
    return value0;
   }
  }
 }
}
/*	local function OPTION-VALUES                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC3option_values(cl_object v1option, cl_object v2options)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3output;
   v3output = ECL_NIL;
   {
    cl_object v4;
    v4 = v2options;
    goto L6;
L5:;
    {
     cl_object v5o;
     v5o = ecl_car(v4);
     {
      cl_object v6o_option;
      cl_object v7o_symbols;
      v6o_option = ecl_car(v5o);
      {
       cl_object v8;
       cl_object v9;
       cl_object v10;
       v8 = ecl_cdr(v5o);
       v9 = ECL_NIL;
       if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
       v10 = v8;
       {
        cl_object v11;
        cl_object v12;
        v11 = ecl_list1(ECL_NIL);
        v12 = v11;
L19:;
        if (!(ecl_endp(v10))) { goto L21; }
        goto L20;
L21:;
        v9 = _ecl_car(v10);
        {
         cl_object v13;
         v13 = _ecl_cdr(v10);
         if (ecl_unlikely(!ECL_LISTP(v13))) FEtype_error_list(v13);
         v10 = v13;
        }
        if (ecl_unlikely(ECL_ATOM(v12))) FEtype_error_cons(v12);
        T0 = v12;
        T1 = LC1to_string(v9);
        v12 = ecl_list1(T1);
        (ECL_CONS_CDR(T0)=v12,T0);
        goto L19;
L20:;
        v7o_symbols = ecl_cdr(v11);
        goto L12;
       }
      }
L12:;
      if (Null(cl_stringE(2, v6o_option, v1option))) { goto L10; }
      T0 = (ECL_SYM("EQUAL",335)->symbol.gfdef);
      v3output = cl_union(4, v7o_symbols, v3output, ECL_SYM("TEST",1316), T0);
     }
L10:;
    }
    v4 = ecl_cdr(v4);
L6:;
    if (Null(v4)) { goto L41; }
    goto L5;
L41:;
   }
   value0 = v3output;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function OPTION-VALUES-LIST                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC2option_values_list(cl_object v1option, cl_object v2options)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3output;
   v3output = ECL_NIL;
   {
    cl_object v4;
    v4 = v2options;
    goto L6;
L5:;
    {
     cl_object v5o;
     v5o = ecl_car(v4);
     {
      cl_object v6o_option;
      v6o_option = ecl_car(v5o);
      if (Null(cl_stringE(2, v6o_option, v1option))) { goto L10; }
      {
       cl_object v7o_package;
       cl_object v8former_symbols;
       cl_object v9o_symbols;
       T0 = ecl_cadr(v5o);
       v7o_package = cl_string(T0);
       v8former_symbols = ecl_assql(v7o_package,v3output);
       {
        cl_object v10;
        cl_object v11;
        cl_object v12;
        v10 = ecl_cddr(v5o);
        v11 = ECL_NIL;
        if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
        v12 = v10;
        {
         cl_object v13;
         cl_object v14;
         v13 = ecl_list1(ECL_NIL);
         v14 = v13;
L23:;
         if (!(ecl_endp(v12))) { goto L25; }
         goto L24;
L25:;
         v11 = _ecl_car(v12);
         {
          cl_object v15;
          v15 = _ecl_cdr(v12);
          if (ecl_unlikely(!ECL_LISTP(v15))) FEtype_error_list(v15);
          v12 = v15;
         }
         if (ecl_unlikely(ECL_ATOM(v14))) FEtype_error_cons(v14);
         T1 = v14;
         T2 = LC1to_string(v11);
         v14 = ecl_list1(T2);
         (ECL_CONS_CDR(T1)=v14,T1);
         goto L23;
L24:;
         T0 = ecl_cdr(v13);
         goto L16;
        }
       }
L16:;
       T1 = ecl_cdr(v8former_symbols);
       T2 = (ECL_SYM("EQUAL",335)->symbol.gfdef);
       v9o_symbols = cl_union(4, T0, T1, ECL_SYM("TEST",1316), T2);
       if (Null(v8former_symbols)) { goto L41; }
       if (ecl_unlikely(ECL_ATOM(v8former_symbols))) FEtype_error_cons(v8former_symbols);
       T0 = v8former_symbols;
       (ECL_CONS_CDR(T0)=v9o_symbols,T0);
       goto L10;
L41:;
       v3output = cl_acons(v7o_package, v9o_symbols, v3output);
      }
     }
L10:;
    }
    v4 = ecl_cdr(v4);
L6:;
    if (Null(v4)) { goto L49; }
    goto L5;
L49:;
   }
   value0 = v3output;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function TO-STRING                                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC1to_string(cl_object v1x)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ecl_numberp(v1x))) { goto L1; }
  value0 = v1x;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  value0 = cl_string(v1x);
  return value0;
 }
}
/*	function definition for DODEFPACKAGE                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5dodefpackage(cl_object v1name, cl_object v2nicknames, cl_object v3documentation, cl_object v4use, cl_object v5shadowed_symbol_names, cl_object v6interned_symbol_names, cl_object v7exported_symbol_names, cl_object v8shadowing_imported_from_symbol_names_list, cl_object v9imported_from_symbol_names_list, cl_object v10exported_from_package_names)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_find_package(v1name))) { goto L2; }
  if (Null(v2nicknames)) { goto L4; }
  cl_rename_package(3, v1name, v1name, v2nicknames);
L4:;
  if (Null(v4use)) { goto L1; }
  T0 = cl_find_package(v1name);
  T1 = cl_package_use_list(T0);
  cl_unuse_package(2, T1, v1name);
  goto L1;
L2:;
  cl_make_package(5, v1name, ECL_SYM("USE",1323), ECL_NIL, ECL_SYM("NICKNAMES",1277), v2nicknames);
L1:;
  T0 = cl_find_package(v1name);
  ecl_bds_bind(cl_env_copy,ECL_SYM("*PACKAGE*",43),T0); /*  *PACKAGE* */
  if (Null(v3documentation)) { goto L8; }
  {
   cl_object v11;
   v11 = ecl_symbol_value(ECL_SYM("*PACKAGE*",43));
   (cl_env_copy->function=ECL_CONS_CAR(VV[11]))->cfun.entry(3, v3documentation, v11, ECL_T) /*  (SETF DOCUMENTATION) */;
  }
L8:;
  cl_shadow(1, v5shadowed_symbol_names);
  {
   cl_object v11;
   v11 = v8shadowing_imported_from_symbol_names_list;
   goto L16;
L15:;
   {
    cl_object v12item;
    v12item = ecl_car(v11);
    {
     cl_object v13package;
     T0 = ecl_car(v12item);
     v13package = cl_find_package(T0);
     {
      cl_object v14;
      v14 = ecl_cdr(v12item);
      goto L25;
L24:;
      {
       cl_object v15name;
       v15name = ecl_car(v14);
       T0 = L6find_or_make_symbol(v15name, v13package);
       cl_shadowing_import(1, T0);
      }
      v14 = ecl_cdr(v14);
L25:;
      if (Null(v14)) { goto L32; }
      goto L24;
L32:;
     }
    }
   }
   v11 = ecl_cdr(v11);
L16:;
   if (Null(v11)) { goto L36; }
   goto L15;
L36:;
  }
  cl_use_package(1, v4use);
  {
   cl_object v11;
   v11 = v9imported_from_symbol_names_list;
   goto L43;
L42:;
   {
    cl_object v12item;
    v12item = ecl_car(v11);
    {
     cl_object v13package;
     T0 = ecl_car(v12item);
     v13package = cl_find_package(T0);
     {
      cl_object v14;
      v14 = ecl_cdr(v12item);
      goto L52;
L51:;
      {
       cl_object v15name;
       v15name = ecl_car(v14);
       value0 = L6find_or_make_symbol(v15name, v13package);
       if ((value0)!=ECL_NIL) { goto L59; }
       T0 = ecl_list1(ECL_NIL);
       goto L57;
L59:;
       T0 = value0;
       goto L57;
L57:;
       cl_import(1, T0);
      }
      v14 = ecl_cdr(v14);
L52:;
      if (Null(v14)) { goto L63; }
      goto L51;
L63:;
     }
    }
   }
   v11 = ecl_cdr(v11);
L43:;
   if (Null(v11)) { goto L67; }
   goto L42;
L67:;
  }
  {
   cl_object v11;
   cl_object v12;
   v11 = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v6interned_symbol_names))) FEtype_error_list(v6interned_symbol_names);
   v12 = v6interned_symbol_names;
L73:;
   if (!(ecl_endp(v12))) { goto L75; }
   goto L74;
L75:;
   v11 = _ecl_car(v12);
   {
    cl_object v13;
    v13 = _ecl_cdr(v12);
    if (ecl_unlikely(!ECL_LISTP(v13))) FEtype_error_list(v13);
    v12 = v13;
   }
   cl_intern(1, v11);
   goto L73;
L74:;
   goto L69;
  }
L69:;
  {
   cl_object v11;
   cl_object v12;
   v11 = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v7exported_symbol_names))) FEtype_error_list(v7exported_symbol_names);
   v12 = v7exported_symbol_names;
   {
    cl_object v13;
    cl_object v14;
    v13 = ecl_list1(ECL_NIL);
    v14 = v13;
L93:;
    if (!(ecl_endp(v12))) { goto L95; }
    goto L94;
L95:;
    v11 = _ecl_car(v12);
    {
     cl_object v15;
     v15 = _ecl_cdr(v12);
     if (ecl_unlikely(!ECL_LISTP(v15))) FEtype_error_list(v15);
     v12 = v15;
    }
    if (ecl_unlikely(ECL_ATOM(v14))) FEtype_error_cons(v14);
    T1 = v14;
    T2 = cl_intern(1, v11);
    v14 = ecl_list1(T2);
    (ECL_CONS_CDR(T1)=v14,T1);
    goto L93;
L94:;
    T0 = ecl_cdr(v13);
    goto L87;
   }
  }
L87:;
  cl_export(1, T0);
  {
   cl_object v11;
   v11 = v10exported_from_package_names;
   goto L112;
L111:;
   {
    cl_object v12package;
    v12package = ecl_car(v11);
    {
     cl_object v13;
     cl_object v14;
     cl_object v15symbol;
     T0 = cl_find_package(v12package);
     v13 = si_packages_iterator(3, T0, VV[7], ECL_T);
     v14 = ECL_NIL;
     v15symbol = ECL_NIL;
     goto L122;
L121:;
     value0 = ecl_function_dispatch(cl_env_copy,v13)(0);
     v14 = value0;
     {
      const int v16 = cl_env_copy->nvalues;
      cl_object v17;
      v17 = (v16<=1)? ECL_NIL : cl_env_copy->values[1];
      v15symbol = v17;
     }
     if ((v14)!=ECL_NIL) { goto L126; }
     goto L116;
L126:;
     {
      struct ecl_stack_frame _ecl_inner_frame_aux;
      cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
      {
       cl_object v16;
       v16 = _ecl_inner_frame;
       T1 = cl_string(v15symbol);
       cl_env_copy->values[0] = cl_find_symbol(1, T1);
       ecl_stack_frame_push_values(v16);cl_env_copy->values[0]=ecl_apply_from_stack_frame(v16,ECL_SYM("LIST",481));
       value0 = cl_env_copy->values[0];
      }
      ecl_stack_frame_close(_ecl_inner_frame);
     }
     T0 = value0;
     if (Null(ecl_cadr(T0))) { goto L128; }
     T0 = cl_string(v15symbol);
     T1 = cl_intern(1, T0);
     T2 = ecl_list1(T1);
     cl_export(1, T2);
L128:;
L122:;
     goto L121;
    }
L116:;
   }
   v11 = ecl_cdr(v11);
L112:;
   if (Null(v11)) { goto L138; }
   goto L111;
L138:;
   ecl_bds_unwind1(cl_env_copy);
  }
  value0 = cl_find_package(v1name);
  return value0;
 }
}
/*	function definition for FIND-OR-MAKE-SYMBOL                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6find_or_make_symbol(cl_object v1name, cl_object v2package)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4;                                  /*  SYMBOL          */
   cl_object v5;                                  /*  FOUND           */
   value0 = cl_find_symbol(2, v1name, v2package);
   v4 = value0;
   v5 = cl_env_copy->values[1];
   if ((v5)!=ECL_NIL) { goto L2; }
   T0 = cl_list(2, v1name, v2package);
   si_signal_simple_error(6, ECL_SYM("PACKAGE-ERROR",618), _ecl_static_6, _ecl_static_7, T0, ECL_SYM("PACKAGE",1284), v2package);
   v4 = cl_intern(2, v1name, v2package);
L2:;
   value0 = v4;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for FIND-DUPLICATES                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7find_duplicates(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1lists;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1lists = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v2results;
   v2results = ECL_NIL;
   {
    cl_object v3list;
    cl_object v4;
    v3list = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v1lists))) FEtype_error_list(v1lists);
    v4 = v1lists;
    {
     cl_object v5more;
     v5more = ecl_cdr(v1lists);
     {
      cl_object v6i;
      v6i = ecl_make_fixnum(1);
      if (!(ecl_endp(v4))) { goto L10; }
      goto L9;
L10:;
      v3list = _ecl_car(v4);
      {
       cl_object v7;
       v7 = _ecl_cdr(v4);
       if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
       v4 = v7;
      }
      if (!(ECL_ATOM(v5more))) { goto L18; }
      goto L9;
L18:;
L8:;
      {
       cl_object v7elt;
       cl_object v8;
       v7elt = ECL_NIL;
       if (ecl_unlikely(!ECL_LISTP(v3list))) FEtype_error_list(v3list);
       v8 = v3list;
       {
        cl_object v9entry;
        v9entry = ECL_NIL;
L25:;
        if (!(ecl_endp(v8))) { goto L27; }
        goto L26;
L27:;
        v7elt = _ecl_car(v8);
        {
         cl_object v10;
         v10 = _ecl_cdr(v8);
         if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
         v8 = v10;
        }
        {
         cl_object v10;
         v10 = si_make_seq_iterator(2, v2results, ecl_make_fixnum(0));
L38:;
         if ((v10)!=ECL_NIL) { goto L40; }
         v9entry = ECL_NIL;
         goto L36;
L40:;
         {
          cl_object v11;
          v11 = si_seq_iterator_ref(v2results, v10);
          T0 = ecl_car(v11);
          if (Null(cl_stringE(2, v7elt, T0))) { goto L42; }
          v9entry = v11;
          goto L36;
         }
L42:;
         v10 = si_seq_iterator_next(v2results, v10);
         goto L38;
        }
L36:;
        if ((ecl_memql(v6i,v9entry))!=ECL_NIL) { goto L47; }
        {
         cl_object v10l2;
         cl_object v11;
         v10l2 = ECL_NIL;
         if (ecl_unlikely(!ECL_LISTP(v5more))) FEtype_error_list(v5more);
         v11 = v5more;
         {
          cl_object v12j;
          {
          cl_object v13;
          v13 = ecl_one_plus(v6i);
          T0 = cl_realp(v13);
          if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("REAL",703),v13);
          v12j = v13;
          }
          if (!(ecl_endp(v11))) { goto L57; }
          goto L56;
L57:;
          v10l2 = _ecl_car(v11);
          {
          cl_object v13;
          v13 = _ecl_cdr(v11);
          if (ecl_unlikely(!ECL_LISTP(v13))) FEtype_error_list(v13);
          v11 = v13;
          }
L55:;
          {
          cl_object v13;
          v13 = v10l2;
          goto L70;
L69:;
          {
          cl_object v14;
          cl_object v15;
          if (ecl_unlikely(ECL_ATOM(v13))) FEtype_error_cons(v13);
          v14 = v13;
          v15 = ECL_CONS_CAR(v14);
          if (Null(cl_stringE(2, v7elt, v15))) { goto L72; }
          if (Null(v14)) { goto L65; }
          goto L66;
          }
L72:;
          v13 = ECL_CONS_CDR(v13);
L70:;
          if (v13==ECL_NIL) { goto L79; }
          goto L69;
L79:;
          goto L65;
          }
L66:;
          if (Null(v9entry)) { goto L81; }
          T0 = ecl_list1(v12j);
          ecl_nconc(v9entry,T0);
          goto L65;
L81:;
          T0 = cl_list(3, v7elt, v6i, v12j);
          v2results = CONS(T0,v2results);
          v9entry = ecl_car(v2results);
L65:;
          if (!(ecl_endp(v11))) { goto L85; }
          goto L56;
L85:;
          v10l2 = _ecl_car(v11);
          {
          cl_object v13;
          v13 = _ecl_cdr(v11);
          if (ecl_unlikely(!ECL_LISTP(v13))) FEtype_error_list(v13);
          v11 = v13;
          }
          v12j = ecl_one_plus(v12j);
          goto L55;
L56:;
         }
        }
L47:;
        goto L25;
L26:;
       }
      }
      if (!(ecl_endp(v4))) { goto L97; }
      goto L9;
L97:;
      v3list = _ecl_car(v4);
      {
       cl_object v7;
       v7 = _ecl_cdr(v4);
       if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
       v4 = v7;
      }
      v5more = _ecl_cdr(v5more);
      if (!(ECL_ATOM(v5more))) { goto L107; }
      goto L9;
L107:;
      v6i = ecl_one_plus(v6i);
      goto L8;
L9:;
     }
    }
   }
   value0 = v2results;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}

#include "lsp/defpackage.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclEusiUetpENzr9_dIsTOE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:LSP;DEFPACKAGE.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclEusiUetpENzr9_dIsTOE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defmacro(VV[9]);                         /*  DEFPACKAGE      */
 ecl_cmp_defun(VV[10]);                           /*  DODEFPACKAGE    */
 (void)0; /* No entry created for FIND-OR-MAKE-SYMBOL */
 (void)0; /* No entry created for FIND-DUPLICATES */
}
