/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:LSP;DEFMACRO.LSP                                  */
#include <ecl/ecl-cmp.h>
#include "lsp/defmacro.eclh"
/*	function definition for SEARCH-KEYWORD                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_search_keyword(cl_narg narg, cl_object v1list, cl_object v2key, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  if (!(ECL_ATOM(v1list))) { goto L1; }
  value0 = ECL_SYM("MISSING-KEYWORD",1929);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  T0 = ecl_cdr(v1list);
  if (!(ECL_ATOM(T0))) { goto L3; }
  value0 = ECL_SYM("MISSING-KEYWORD",1929);
  cl_env_copy->nvalues = 1;
  return value0;
L3:;
  T0 = ecl_car(v1list);
  if (!((T0)==(v2key))) { goto L5; }
  value0 = ecl_cadr(v1list);
  cl_env_copy->nvalues = 1;
  return value0;
L5:;
  v1list = ecl_cddr(v1list);
  goto TTL;
 }
}
/*	function definition for CHECK-KEYWORD                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_check_keyword(cl_narg narg, cl_object v1tail, cl_object v2keywords, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v3allow_other_keys;
  cl_object v4aok_flag;
  va_list args; va_start(args,v2keywords);
  {
   int i = 2;
   if (i >= narg) {
    v3allow_other_keys = ECL_NIL;
    v4aok_flag = ECL_NIL;
   } else {
    i++;
    v3allow_other_keys = va_arg(args,cl_object);
    v4aok_flag = ECL_T;
   }
  }
  va_end(args);
  {
   cl_object v5head;
   cl_object v6arg;
   cl_object v7err;
   v5head = ECL_NIL;
   v6arg = ECL_NIL;
   v7err = ECL_NIL;
   goto L7;
L6:;
   if (!(ECL_ATOM(v1tail))) { goto L10; }
   cl_error(1, _ecl_static_1);
   goto L9;
L10:;
   v5head = ecl_car(v1tail);
   v1tail = ecl_cdr(v1tail);
L9:;
   if (!(ECL_ATOM(v1tail))) { goto L16; }
   cl_error(1, _ecl_static_1);
   goto L15;
L16:;
   v6arg = ecl_car(v1tail);
   v1tail = ecl_cdr(v1tail);
L15:;
   if (!((v5head)==(ECL_SYM("ALLOW-OTHER-KEYS",1197)))) { goto L22; }
   if ((v4aok_flag)!=ECL_NIL) { goto L21; }
   v3allow_other_keys = v1tail;
   v4aok_flag = ECL_T;
   goto L21;
L22:;
   if ((ecl_memql(v5head,v2keywords))!=ECL_NIL) { goto L21; }
   v7err = v5head;
L21:;
L7:;
   if (v1tail==ECL_NIL) { goto L30; }
   goto L6;
L30:;
   if (Null(v7err)) { goto L32; }
   if ((v3allow_other_keys)!=ECL_NIL) { goto L32; }
   value0 = cl_error(2, _ecl_static_2, v7err);
   return value0;
L32:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for DM-TOO-MANY-ARGUMENTS                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_dm_too_many_arguments(cl_object v1_current_form_)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  ecl_bds_bind(cl_env_copy,ECL_SYM("*CURRENT-FORM*",1612),v1_current_form_); /*  *CURRENT-FORM* */
TTL:
  value0 = cl_error(2, _ecl_static_3, ecl_symbol_value(ECL_SYM("*CURRENT-FORM*",1612)));
  ecl_bds_unwind1(cl_env_copy);
  return value0;
 }
}
/*	function definition for DM-TOO-FEW-ARGUMENTS                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_dm_too_few_arguments(cl_object v1form_or_nil)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1form_or_nil)) { goto L1; }
  ecl_bds_bind(cl_env_copy,ECL_SYM("*CURRENT-FORM*",1612),v1form_or_nil); /*  *CURRENT-FORM* */
  value0 = cl_error(2, _ecl_static_4, ecl_symbol_value(ECL_SYM("*CURRENT-FORM*",1612)));
  ecl_bds_unwind1(cl_env_copy);
  return value0;
L1:;
  value0 = cl_error(1, _ecl_static_5);
  return value0;
 }
}
/*	function definition for DESTRUCTURE                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3destructure(cl_object v1vl, cl_object v2macro)
{
 cl_object T0, T1;
 volatile cl_object lex0[1];
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_gensym(0);
  lex0[0] = T0;                                   /*  BASIS-FORM      */
  ecl_bds_bind(cl_env_copy,VV[4],ECL_NIL);        /*  *DL*            */
  ecl_bds_bind(cl_env_copy,VV[5],ECL_NIL);        /*  *ARG-CHECK*     */
  if (!(ECL_LISTP(v1vl))) { goto L2; }
  T0 = ecl_car(v1vl);
  if (!((T0)==(ECL_SYM("&WHOLE",13)))) { goto L1; }
  {
   cl_object v3named_whole;
   v3named_whole = ecl_cadr(v1vl);
   v1vl = ecl_cddr(v1vl);
   if (!(ECL_LISTP(v3named_whole))) { goto L8; }
   LC1dm_vl(lex0, v3named_whole, lex0[0], ECL_NIL);
   goto L1;
L8:;
   T0 = cl_list(2, v3named_whole, lex0[0]);
   cl_set(VV[4],ecl_list1(T0));
   goto L1;
  }
L2:;
  if (!(ECL_SYMBOLP(v1vl))) { goto L11; }
  v1vl = cl_list(2, ECL_SYM("&REST",12), v1vl);
  goto L1;
L11:;
  cl_error(2, _ecl_static_7, v1vl);
L1:;
  T0 = LC1dm_vl(lex0, v1vl, lex0[0], v2macro);
  T1 = cl_nreverse(ecl_symbol_value(VV[4]));
  cl_env_copy->nvalues = 4;
  cl_env_copy->values[3] = ecl_symbol_value(VV[5]);
  cl_env_copy->values[2] = T1;
  cl_env_copy->values[1] = lex0[0];
  cl_env_copy->values[0] = T0;
  ecl_bds_unwind1(cl_env_copy);
  ecl_bds_unwind1(cl_env_copy);
  return cl_env_copy->values[0];
 }
}
/*	local function DM-V                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC2dm_v(volatile cl_object *lex0, cl_object v1v, cl_object v2init)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1v)) { goto L1; }
  if (!(ECL_SYMBOLP(v1v))) { goto L1; }
  if (Null(v2init)) { goto L6; }
  T0 = cl_list(2, v1v, v2init);
  goto L5;
L6:;
  T0 = v1v;
L5:;
  cl_set(VV[4],CONS(T0,ecl_symbol_value(VV[4])));
  value0 = ecl_symbol_value(VV[4]);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (Null(v1v)) { goto L8; }
  if (!(ECL_ATOM(v1v))) { goto L8; }
  value0 = cl_error(2, _ecl_static_6, v1v);
  return value0;
L8:;
  T0 = ecl_car(v1v);
  if (!((T0)==(ECL_SYM("&WHOLE",13)))) { goto L11; }
  {
   cl_object v3whole_var;
   v3whole_var = ecl_cadr(v1v);
   if (!(ECL_LISTP(v3whole_var))) { goto L15; }
   {
    cl_object v4new_whole;
    v4new_whole = cl_gensym(0);
    LC2dm_v(lex0, v4new_whole, v2init);
    LC1dm_vl(lex0, v3whole_var, v4new_whole, ECL_NIL);
    v3whole_var = v4new_whole;
    goto L14;
   }
L15:;
   LC2dm_v(lex0, v3whole_var, v2init);
L14:;
   T0 = ecl_cddr(v1v);
   value0 = LC1dm_vl(lex0, T0, v3whole_var, ECL_NIL);
   return value0;
  }
L11:;
  {
   cl_object v4temp;
   v4temp = cl_gensym(0);
   if (Null(v2init)) { goto L25; }
   T0 = cl_list(2, v4temp, v2init);
   goto L24;
L25:;
   T0 = v4temp;
L24:;
   cl_set(VV[4],CONS(T0,ecl_symbol_value(VV[4])));
   value0 = LC1dm_vl(lex0, v1v, v4temp, ECL_NIL);
   return value0;
  }
 }
}
/*	local function DM-VL                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC1dm_vl(volatile cl_object *lex0, cl_object v1vl, cl_object v2whole, cl_object v3macro)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v5;                                  /*  REQS            */
   cl_object v6;                                  /*  OPTS            */
   cl_object v7;                                  /*  REST            */
   cl_object v8;                                  /*  KEY-FLAG        */
   cl_object v9;                                  /*  KEYS            */
   cl_object v10;                                 /*  ALLOW-OTHER-KEYS */
   cl_object v11;                                 /*  AUXS            */
   if (Null(v3macro)) { goto L3; }
   T0 = ECL_SYM("MACRO",1101);
   goto L2;
L3:;
   T0 = ECL_SYM("DESTRUCTURING-BIND",300);
L2:;
   value0 = si_process_lambda_list(v1vl, T0);
   v5 = value0;
   {
    const int v12 = cl_env_copy->nvalues;
    cl_object v13;
    v13 = (v12<=1)? ECL_NIL : cl_env_copy->values[1];
    v6 = v13;
    v13 = (v12<=2)? ECL_NIL : cl_env_copy->values[2];
    v7 = v13;
    v13 = (v12<=3)? ECL_NIL : cl_env_copy->values[3];
    v8 = v13;
    v13 = (v12<=4)? ECL_NIL : cl_env_copy->values[4];
    v9 = v13;
    v13 = (v12<=5)? ECL_NIL : cl_env_copy->values[5];
    v10 = v13;
    v13 = (v12<=6)? ECL_NIL : cl_env_copy->values[6];
    v11 = v13;
   }
   {
    cl_object v12pointer;
    cl_object v13cons_pointer;
    cl_object v14unsafe_car;
    cl_object v15unsafe_cdr;
    cl_object v16unsafe_pop;
    cl_object v17no_check;
    cl_object v18ppn;
    cl_object v19all_keywords;
    v12pointer = cl_gensym(0);
    v13cons_pointer = cl_list(3, ECL_SYM("TRULY-THE",1949), ECL_SYM("CONS",251), v12pointer);
    v14unsafe_car = cl_list(2, ECL_SYM("CAR",180), v13cons_pointer);
    v15unsafe_cdr = cl_list(2, ECL_SYM("CDR",198), v13cons_pointer);
    v16unsafe_pop = cl_list(3, ECL_SYM("SETQ",751), v12pointer, v15unsafe_cdr);
    v17no_check = ECL_NIL;
    {
     cl_fixnum v20;
     v20 = ecl_length(v5);
     T0 = ecl_car(v6);
     v18ppn = ecl_plus(ecl_make_fixnum(v20),T0);
    }
    v19all_keywords = ECL_NIL;
    if (Null(v3macro)) { goto L15; }
    T1 = cl_list(3, ECL_SYM("TRULY-THE",1949), ECL_SYM("CONS",251), v2whole);
    T0 = cl_list(2, ECL_SYM("CDR",198), T1);
    goto L14;
L15:;
    T0 = v2whole;
L14:;
    LC2dm_v(lex0, v12pointer, T0);
    {
     cl_object v20;
     v20 = ecl_cdr(v5);
     goto L21;
L20:;
     {
      cl_object v21v;
      v21v = ecl_car(v20);
      T0 = cl_list(2, ECL_SYM("NULL",605), v12pointer);
      T1 = cl_list(2, VV[3], lex0[0]);
      T2 = cl_list(3, ECL_SYM("IF",946), T0, T1);
      T3 = cl_list(3, ECL_SYM("PROG1",669), v14unsafe_car, v16unsafe_pop);
      T4 = cl_list(3, ECL_SYM("PROGN",671), T2, T3);
      LC2dm_v(lex0, v21v, T4);
     }
     v20 = ecl_cdr(v20);
L21:;
     if (Null(v20)) { goto L28; }
     goto L20;
L28:;
    }
    {
     cl_object v20;
     {
      cl_object v21;
      v21 = v6;
      if (ecl_unlikely(!ECL_LISTP(v21))) FEtype_error_list(v21);
      if (Null(v21)) { goto L35; }
      {
       cl_object v22;
       v22 = ECL_CONS_CDR(v21);
       v6 = v22;
       v21 = ECL_CONS_CAR(v21);
      }
L35:;
      v20 = v21;
     }
     {
      cl_object v21i;
      v21i = ecl_make_fixnum(0);
      goto L43;
L42:;
      {
       cl_object v22x;
       cl_object v23init;
       cl_object v24sv;
       v22x = ecl_car(v6);
       v23init = ecl_cadr(v6);
       v24sv = ecl_caddr(v6);
       v6 = ecl_cdddr(v6);
       if (Null(v24sv)) { goto L51; }
       T0 = cl_list(4, ECL_SYM("IF",946), v12pointer, v14unsafe_car, v23init);
       LC2dm_v(lex0, v22x, T0);
       T0 = cl_list(3, ECL_SYM("PROGN",671), v16unsafe_pop, ECL_T);
       T1 = cl_list(3, ECL_SYM("AND",87), v12pointer, T0);
       LC2dm_v(lex0, v24sv, T1);
       goto L45;
L51:;
       T0 = cl_list(3, ECL_SYM("PROG1",669), v14unsafe_car, v16unsafe_pop);
       T1 = cl_list(4, ECL_SYM("IF",946), v12pointer, T0, v23init);
       LC2dm_v(lex0, v22x, T1);
      }
L45:;
      v21i = ecl_one_plus(v21i);
L43:;
      if (!(ecl_number_compare(v21i,v20)<0)) { goto L56; }
      goto L42;
L56:;
     }
    }
    if (Null(v7)) { goto L58; }
    LC2dm_v(lex0, v7, v12pointer);
    v17no_check = ECL_T;
L58:;
    {
     cl_object v20;
     {
      cl_object v21;
      v21 = v9;
      if (ecl_unlikely(!ECL_LISTP(v21))) FEtype_error_list(v21);
      if (Null(v21)) { goto L67; }
      {
       cl_object v22;
       v22 = ECL_CONS_CDR(v21);
       v9 = v22;
       v21 = ECL_CONS_CAR(v21);
      }
L67:;
      v20 = v21;
     }
     {
      cl_object v21i;
      v21i = ecl_make_fixnum(0);
      goto L75;
L74:;
      {
       cl_object v22temp;
       cl_object v23k;
       cl_object v24v;
       cl_object v25init;
       cl_object v26sv;
       v22temp = cl_gensym(0);
       v23k = ecl_car(v9);
       v24v = ecl_cadr(v9);
       v25init = ecl_caddr(v9);
       v26sv = ecl_cadddr(v9);
       v17no_check = ECL_T;
       v9 = ecl_cddddr(v9);
       T0 = cl_list(2, ECL_SYM("QUOTE",679), v23k);
       T1 = cl_list(3, VV[0], v12pointer, T0);
       LC2dm_v(lex0, v22temp, T1);
       T0 = cl_list(3, ECL_SYM("EQ",333), v22temp, VV[6]);
       T1 = cl_list(4, ECL_SYM("IF",946), T0, v25init, v22temp);
       LC2dm_v(lex0, v24v, T1);
       if (Null(v26sv)) { goto L89; }
       T0 = cl_list(3, ECL_SYM("EQ",333), v22temp, VV[6]);
       T1 = cl_list(2, ECL_SYM("NOT",584), T0);
       LC2dm_v(lex0, v26sv, T1);
L89:;
       v19all_keywords = CONS(v23k,v19all_keywords);
      }
      v21i = ecl_one_plus(v21i);
L75:;
      if (!(ecl_number_compare(v21i,v20)<0)) { goto L94; }
      goto L74;
L94:;
     }
    }
    {
     cl_object v20l;
     v20l = v11;
     goto L100;
L99:;
     {
      cl_object v21v;
      cl_object v22init;
      v21v = ecl_car(v20l);
      v22init = ecl_cadr(v20l);
      LC2dm_v(lex0, v21v, v22init);
     }
     v20l = ecl_cddr(v20l);
L100:;
     if (ecl_endp(v20l)) { goto L107; }
     goto L99;
L107:;
    }
    if (Null(v8)) { goto L110; }
    T0 = cl_list(2, ECL_SYM("QUOTE",679), v19all_keywords);
    if (Null(v10)) { goto L114; }
    T1 = VV[7];
    goto L113;
L114:;
    T1 = ECL_NIL;
L113:;
    T2 = cl_listX(4, VV[1], v12pointer, T0, T1);
    cl_set(VV[5],CONS(T2,ecl_symbol_value(VV[5])));
    goto L109;
L110:;
    if ((v17no_check)!=ECL_NIL) { goto L109; }
    T0 = cl_list(2, VV[2], lex0[0]);
    T1 = cl_list(3, ECL_SYM("IF",946), v12pointer, T0);
    cl_set(VV[5],CONS(T1,ecl_symbol_value(VV[5])));
L109:;
    value0 = v18ppn;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for FIND-DOCUMENTATION                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_find_documentation(cl_narg narg, cl_object v1body, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  {
   struct ecl_stack_frame _ecl_inner_frame_aux;
   cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
   {
    cl_object v2;
    v2 = _ecl_inner_frame;
    cl_env_copy->values[0] = si_process_declarations(2, v1body, ECL_T);
    ecl_stack_frame_push_values(v2);cl_env_copy->values[0]=ecl_apply_from_stack_frame(v2,ECL_SYM("LIST",481));
    value0 = cl_env_copy->values[0];
   }
   ecl_stack_frame_close(_ecl_inner_frame);
  }
  T0 = value0;
  value0 = ecl_cadddr(T0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for REMOVE-DOCUMENTATION                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_remove_documentation(cl_narg narg, cl_object v1body, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  {
   cl_object v3;                                  /*  DECLS           */
   cl_object v4;                                  /*  BODY            */
   cl_object v5;                                  /*  DOC             */
   value0 = si_process_declarations(2, v1body, ECL_T);
   v3 = value0;
   {
    const int v6 = cl_env_copy->nvalues;
    cl_object v7;
    v7 = (v6<=1)? ECL_NIL : cl_env_copy->values[1];
    v4 = v7;
    v7 = (v6<=2)? ECL_NIL : cl_env_copy->values[2];
    v5 = v7;
   }
   if (Null(v3)) { goto L2; }
   T0 = CONS(ECL_SYM("DECLARE",274),v3);
   v4 = CONS(T0,v4);
L2:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5;
   cl_env_copy->values[0] = v4;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for FIND-DECLARATIONS                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_find_declarations(cl_narg narg, cl_object v1body, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2doc;
  va_list args; va_start(args,v1body);
  {
   int i = 1;
   if (i >= narg) {
    v2doc = ECL_T;
   } else {
    i++;
    v2doc = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v4;                                  /*  DECLS           */
   cl_object v5;                                  /*  BODY            */
   cl_object v6;                                  /*  DOC             */
   value0 = si_process_declarations(2, v1body, v2doc);
   v4 = value0;
   {
    const int v7 = cl_env_copy->nvalues;
    cl_object v8;
    v8 = (v7<=1)? ECL_NIL : cl_env_copy->values[1];
    v5 = v8;
    v8 = (v7<=2)? ECL_NIL : cl_env_copy->values[2];
    v6 = v8;
   }
   if (Null(v4)) { goto L4; }
   T1 = CONS(ECL_SYM("DECLARE",274),v4);
   T0 = ecl_list1(T1);
   goto L3;
L4:;
   T0 = ECL_NIL;
L3:;
   cl_env_copy->nvalues = 3;
   cl_env_copy->values[2] = v6;
   cl_env_copy->values[1] = v5;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for EXPAND-DEFMACRO                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4expand_defmacro(cl_object v1name, cl_object v2vl, cl_object v3body)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v5;                                  /*  DECLS           */
   cl_object v6;                                  /*  BODY            */
   cl_object v7;                                  /*  DOC             */
   value0 = si_find_declarations(1, v3body);
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
    cl_object v8cell;
    v8cell = ecl_last(v2vl,1);
    if (Null(ecl_cdr(v8cell))) { goto L2; }
    T0 = cl_butlast(2, v2vl, ecl_make_fixnum(0));
    T1 = ecl_cdr(v8cell);
    T2 = cl_list(2, ECL_SYM("&REST",12), T1);
    v2vl = ecl_nconc(T0,T2);
   }
L2:;
   {
    cl_object v8env;
    v8env = si_memq(ECL_SYM("&ENVIRONMENT",9),v2vl);
    if (Null(v8env)) { goto L8; }
    T0 = cl_ldiff(v2vl, v8env);
    T1 = ecl_cddr(v8env);
    v2vl = ecl_nconc(T0,T1);
    v8env = ecl_cadr(v8env);
    goto L7;
L8:;
    v8env = cl_gensym(0);
    T0 = cl_list(2, ECL_SYM("IGNORE",428), v8env);
    T1 = cl_list(2, ECL_SYM("DECLARE",274), T0);
    v5 = CONS(T1,v5);
L7:;
    {
     cl_object v10;                               /*  PPN             */
     cl_object v11;                               /*  WHOLE           */
     cl_object v12;                               /*  DL              */
     cl_object v13;                               /*  ARG-CHECK       */
     value0 = L3destructure(v2vl, ECL_T);
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
     T0 = cl_listX(4, v11, v8env, ECL_SYM("&AUX",7), v12);
     T1 = cl_append(3, v5, v13, v6);
     T2 = cl_listX(4, ECL_SYM("LAMBDA-BLOCK",1339), v1name, T0, T1);
     cl_env_copy->nvalues = 3;
     cl_env_copy->values[2] = v7;
     cl_env_copy->values[1] = v10;
     cl_env_copy->values[0] = T2;
     return cl_env_copy->values[0];
    }
   }
  }
 }
}
/*	local function DESTRUCTURING-BIND                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC5destructuring_bind(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4vl;
   cl_object v5list;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4vl = v6;
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
   {
    cl_object v7;                                 /*  DECLS           */
    cl_object v8;                                 /*  BODY            */
    value0 = si_find_declarations(1, v3);
    v7 = value0;
    {
     const int v9 = cl_env_copy->nvalues;
     cl_object v10;
     v10 = (v9<=1)? ECL_NIL : cl_env_copy->values[1];
     v8 = v10;
    }
    {
     cl_object v10;                               /*  WHOLE           */
     cl_object v11;                               /*  DL              */
     cl_object v12;                               /*  ARG-CHECK       */
     value0 = L3destructure(v4vl, ECL_NIL);
     {
      const int v13 = cl_env_copy->nvalues;
      cl_object v14;
      v14 = (v13<=1)? ECL_NIL : cl_env_copy->values[1];
      v10 = v14;
      v14 = (v13<=2)? ECL_NIL : cl_env_copy->values[2];
      v11 = v14;
      v14 = (v13<=3)? ECL_NIL : cl_env_copy->values[3];
      v12 = v14;
     }
     T0 = cl_list(2, v10, v5list);
     T1 = CONS(T0,v11);
     T2 = cl_append(3, v7, v12, v8);
     value0 = cl_listX(3, ECL_SYM("LET*",478), T1, T2);
     return value0;
    }
   }
  }
 }
}
/*	function definition for CMP-ENV-FOR-BYTECODES                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L10cmp_env_for_bytecodes(cl_object v1old_env)
{
 cl_object T0, T1, T2, T3, T4, T5;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   cl_object v3env;
   cl_object v4variables;
   v2 = ecl_car(v1old_env);
   v3env = v2;
   v4variables = ECL_NIL;
   goto L7;
L6:;
   {
    cl_object v5i;
    v5i = ecl_car(v3env);
    if (!(ECL_CONSP(v5i))) { goto L9; }
    {
     cl_object v6name;
     v6name = ecl_car(v5i);
     if ((cl_keywordp(v6name))!=ECL_NIL) { goto L9; }
     if (Null(ecl_cadr(v5i))) { goto L16; }
     T1 = v5i;
     goto L15;
L16:;
     T2 = LC7local_var_error_function(v6name);
     T1 = cl_list(3, v6name, ECL_SYM("SYMBOL-MACRO",1159), T2);
L15:;
     v4variables = CONS(T1,v4variables);
    }
   }
L9:;
   v3env = ecl_cdr(v3env);
L7:;
   if (ecl_endp(v3env)) { goto L21; }
   goto L6;
L21:;
   T0 = cl_nreverse(v4variables);
  }
  {
   cl_object v2;
   cl_object v3env;
   cl_object v4macros;
   v2 = ecl_cdr(v1old_env);
   v3env = v2;
   v4macros = ECL_NIL;
   goto L29;
L28:;
   {
    cl_object v5i;
    v5i = ecl_car(v3env);
    if (!(ECL_CONSP(v5i))) { goto L31; }
    T3 = ecl_cadr(v5i);
    if (!((T3)==(ECL_SYM("MACRO",1101)))) { goto L36; }
    T2 = v5i;
    goto L35;
L36:;
    T3 = ecl_car(v5i);
    T5 = ecl_car(v5i);
    T4 = LC9local_fun_error_function(T5);
    T2 = cl_list(3, T3, ECL_SYM("MACRO",1101), T4);
L35:;
    v4macros = CONS(T2,v4macros);
   }
L31:;
   v3env = ecl_cdr(v3env);
L29:;
   if (ecl_endp(v3env)) { goto L41; }
   goto L28;
L41:;
   T1 = cl_nreverse(v4macros);
  }
  value0 = CONS(T0,T1);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function LOCAL-FUN-ERROR-FUNCTION                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC9local_fun_error_function(cl_object v1name)
{
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1name,env0);                /*  NAME            */
  {cl_object v2;
   v2 = ECL_NIL;
   v2 = ecl_make_cclosure_va((cl_objectfn)LC8__g42,env0,Cblock);
   value0 = v2;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function LOCAL-VAR-ERROR-FUNCTION                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC7local_var_error_function(cl_object v1name)
{
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1name,env0);                /*  NAME            */
  {cl_object v2;
   v2 = ECL_NIL;
   v2 = ecl_make_cclosure_va((cl_objectfn)LC6__g41,env0,Cblock);
   value0 = v2;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	closure G42                                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC8__g42(cl_narg narg, cl_object v1whole, cl_object v2env, ...)
{
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  NAME            */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = cl_error(2, _ecl_static_9, ECL_CONS_CAR(CLV0));
  return value0;
 }
 }
}
/*	closure G41                                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC6__g41(cl_narg narg, cl_object v1whole, cl_object v2env, ...)
{
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  NAME            */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = cl_error(2, _ecl_static_8, ECL_CONS_CAR(CLV0));
  return value0;
 }
 }
}
/*	function definition for MACROLET-FUNCTIONS                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L11macrolet_functions(cl_object v1definitions, cl_object v2old_env)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3env;
   v3env = L10cmp_env_for_bytecodes(v2old_env);
   {
    cl_object v4;
    cl_object v5;
    v4 = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v1definitions))) FEtype_error_list(v1definitions);
    v5 = v1definitions;
    {
     cl_object v6;
     cl_object v7;
     v6 = ecl_list1(ECL_NIL);
     v7 = v6;
L8:;
     if (!(ecl_endp(v5))) { goto L10; }
     goto L9;
L10:;
     v4 = _ecl_car(v5);
     {
      cl_object v8;
      v8 = _ecl_cdr(v5);
      if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
      v5 = v8;
     }
     if (ecl_unlikely(ECL_ATOM(v7))) FEtype_error_cons(v7);
     T1 = v7;
     {
      cl_object v8name;
      cl_object v9llist;
      cl_object v10def;
      v8name = ecl_car(v4);
      v9llist = ecl_cadr(v4);
      v10def = ecl_cddr(v4);
      T3 = cl_list(2, ECL_SYM("QUOTE",679), v8name);
      T4 = L4expand_defmacro(v8name, v9llist, v10def);
      T2 = cl_list(3, ECL_SYM("LIST",481), T3, T4);
     }
     v7 = ecl_list1(T2);
     (ECL_CONS_CDR(T1)=v7,T1);
     goto L8;
L9:;
     T0 = ecl_cdr(v6);
     goto L2;
    }
   }
L2:;
   T1 = CONS(ECL_SYM("LIST",481),T0);
   value0 = si_eval_with_env(4, T1, v3env, ECL_NIL, ECL_T);
   return value0;
  }
 }
}
/*	function definition for CMP-ENV-REGISTER-MACROLET             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L12cmp_env_register_macrolet(cl_object v1definitions, cl_object v2old_env)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3macros;
   v3macros = ecl_cdr(v2old_env);
   {
    cl_object v4;
    v4 = L11macrolet_functions(v1definitions, v2old_env);
    goto L6;
L5:;
    {
     cl_object v5record;
     v5record = ecl_car(v4);
     T0 = ecl_car(v5record);
     T1 = ecl_cadr(v5record);
     T2 = cl_list(3, T0, ECL_SYM("MACRO",1101), T1);
     v3macros = CONS(T2,v3macros);
    }
    v4 = ecl_cdr(v4);
L6:;
    if (Null(v4)) { goto L14; }
    goto L5;
L14:;
   }
   value0 = (ECL_CONS_CDR(v2old_env)=v3macros,v2old_env);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}

#include "lsp/defmacro.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecl1E5Ab5Y4R0bi9_7X9cYE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:LSP;DEFMACRO.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_ecl1E5Ab5Y4R0bi9_7X9cYE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[14]);                           /*  SEARCH-KEYWORD  */
 ecl_cmp_defun(VV[15]);                           /*  CHECK-KEYWORD   */
 ecl_cmp_defun(VV[16]);                           /*  DM-TOO-MANY-ARGUMENTS */
 ecl_cmp_defun(VV[17]);                           /*  DM-TOO-FEW-ARGUMENTS */
 (void)0; /* No entry created for DESTRUCTURE */
 ecl_cmp_defun(VV[18]);                           /*  FIND-DOCUMENTATION */
 ecl_cmp_defun(VV[19]);                           /*  REMOVE-DOCUMENTATION */
 ecl_cmp_defun(VV[20]);                           /*  FIND-DECLARATIONS */
 ecl_cmp_defun(VV[21]);                           /*  EXPAND-DEFMACRO */
 ecl_cmp_defmacro(VV[22]);                        /*  DESTRUCTURING-BIND */
 (void)0; /* No entry created for CMP-ENV-FOR-BYTECODES */
 (void)0; /* No entry created for MACROLET-FUNCTIONS */
 ecl_cmp_defun(VV[23]);                           /*  CMP-ENV-REGISTER-MACROLET */
}
