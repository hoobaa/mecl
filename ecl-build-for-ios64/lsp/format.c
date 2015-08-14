/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:LSP;FORMAT.LSP                                    */
#include <ecl/ecl-cmp.h>
#include "lsp/format.eclh"
/*	function definition for FLONUM-TO-STRING                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1flonum_to_string(cl_narg narg, cl_object v1x, ...)
{
 cl_object T0, T1, T2, T3, T4, T5;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>5)) FEwrong_num_arguments_anonym();
 {
  cl_object v2width;
  cl_object v3fdigits;
  cl_object v4scale;
  cl_object v5fmin;
  va_list args; va_start(args,v1x);
  {
   int i = 1;
   if (i >= narg) {
    v2width = ECL_NIL;
   } else {
    i++;
    v2width = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v3fdigits = ECL_NIL;
   } else {
    i++;
    v3fdigits = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v4scale = ECL_NIL;
   } else {
    i++;
    v4scale = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v5fmin = ECL_NIL;
   } else {
    i++;
    v5fmin = va_arg(args,cl_object);
   }
  }
  va_end(args);
  v1x = cl_abs(v1x);
  if (!(ecl_zerop(v1x))) { goto L7; }
  if (Null(v3fdigits)) { goto L9; }
  {
   cl_object v6s;
   T0 = ecl_one_plus(v3fdigits);
   v6s = cl_make_string(3, T0, ECL_SYM("INITIAL-ELEMENT",1251), CODE_CHAR(48));
   ecl_char_set(v6s,0,(ecl_character)(46));
   {
    cl_fixnum v7;
    v7 = ecl_length(v6s);
    {
     bool v8;
     v8 = ecl_zerop(v3fdigits);
     cl_env_copy->nvalues = 5;
     cl_env_copy->values[4] = ecl_make_fixnum(0);
     cl_env_copy->values[3] = ecl_make_bool(v8);
     cl_env_copy->values[2] = ECL_T;
     cl_env_copy->values[1] = ecl_make_fixnum(v7);
     cl_env_copy->values[0] = v6s;
     return cl_env_copy->values[0];
    }
   }
  }
L9:;
  cl_env_copy->nvalues = 5;
  cl_env_copy->values[4] = ecl_make_fixnum(0);
  cl_env_copy->values[3] = ECL_T;
  cl_env_copy->values[2] = ECL_T;
  cl_env_copy->values[1] = ecl_make_fixnum(1);
  cl_env_copy->values[0] = _ecl_static_2;
  return cl_env_copy->values[0];
L7:;
  {
   cl_object v10;                                 /*  E               */
   cl_object v11;                                 /*  STRING          */
   if (Null(v3fdigits)) { goto L14; }
   value0 = v4scale;
   if ((value0)!=ECL_NIL) { goto L18; }
   T0 = ecl_make_fixnum(0);
   goto L16;
L18:;
   T0 = value0;
   goto L16;
L16:;
   T1 = ecl_plus(v3fdigits,T0);
   T2 = ecl_negate(T1);
   value0 = v5fmin;
   if ((value0)!=ECL_NIL) { goto L22; }
   T3 = ecl_make_fixnum(0);
   goto L20;
L22:;
   T3 = value0;
   goto L20;
L20:;
   T4 = ecl_negate(T3);
   T5 = (ecl_number_compare(T2,T4)<=0?T2:T4);
   value0 = si_float_to_digits(ECL_NIL, v1x, T5, ECL_NIL);
   goto L13;
L14:;
   if (Null(v2width)) { goto L24; }
   if (!(ecl_number_compare(v2width,ecl_make_fixnum(1))>0)) { goto L24; }
   {
    cl_object v12;
    cl_object v13;
    {
     struct ecl_stack_frame _ecl_inner_frame_aux;
     cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
     {
      cl_object v14;
      v14 = _ecl_inner_frame;
      T0 = ecl_one_minus(v2width);
      if (Null(v4scale)) { goto L33; }
      if (!(ecl_minusp(v4scale))) { goto L33; }
      T1 = v4scale;
      goto L32;
L33:;
      T1 = ecl_make_fixnum(0);
L32:;
      T2 = ecl_plus(T0,T1);
      T3 = (ecl_number_compare(ecl_make_fixnum(1),T2)>=0?ecl_make_fixnum(1):T2);
      cl_env_copy->values[0] = si_float_to_digits(ECL_NIL, v1x, T3, ECL_T);
      ecl_stack_frame_push_values(v14);cl_env_copy->values[0]=ecl_apply_from_stack_frame(v14,ECL_SYM("LIST",481));
      value0 = cl_env_copy->values[0];
     }
     ecl_stack_frame_close(_ecl_inner_frame);
    }
    v12 = value0;
    {
     struct ecl_stack_frame _ecl_inner_frame_aux;
     cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
     {
      cl_object v14;
      v14 = _ecl_inner_frame;
      value0 = v5fmin;
      if ((value0)!=ECL_NIL) { goto L43; }
      T0 = ecl_make_fixnum(0);
      goto L41;
L43:;
      T0 = value0;
      goto L41;
L41:;
      if (Null(v4scale)) { goto L46; }
      T1 = v4scale;
      goto L45;
L46:;
      T1 = ecl_make_fixnum(0);
L45:;
      T2 = ecl_plus(T0,T1);
      T3 = ecl_negate(T2);
      cl_env_copy->values[0] = si_float_to_digits(ECL_NIL, v1x, T3, ECL_NIL);
      ecl_stack_frame_push_values(v14);cl_env_copy->values[0]=ecl_apply_from_stack_frame(v14,ECL_SYM("LIST",481));
      value0 = cl_env_copy->values[0];
     }
     ecl_stack_frame_close(_ecl_inner_frame);
    }
    v13 = value0;
    T0 = ecl_cadr(v12);
    {
     cl_fixnum v14;
     v14 = ecl_length(T0);
     T1 = ecl_cadr(v13);
     {
      cl_fixnum v15;
      v15 = ecl_length(T1);
      if (!((v14)>=(v15))) { goto L48; }
     }
    }
    value0 = cl_values_list(v12);
    goto L13;
L48:;
    value0 = cl_values_list(v13);
    goto L13;
   }
L24:;
   value0 = si_float_to_digits(ECL_NIL, v1x, ECL_NIL, ECL_NIL);
L13:;
   v10 = value0;
   {
    const int v12 = cl_env_copy->nvalues;
    cl_object v13;
    v13 = (v12<=1)? ECL_NIL : cl_env_copy->values[1];
    v11 = v13;
   }
   {
    cl_object v12;
    cl_object v13;
    value0 = v4scale;
    if ((value0)!=ECL_NIL) { goto L53; }
    T0 = ecl_make_fixnum(0);
    goto L51;
L53:;
    T0 = value0;
    goto L51;
L51:;
    v12 = ecl_plus(v10,T0);
    v13 = cl_make_string_output_stream(0);
    if (!(ecl_plusp(v12))) { goto L57; }
    {
     cl_fixnum v14;
     v14 = ecl_length(v11);
     T0 = (ecl_number_compare(ecl_make_fixnum(v14),v12)<=0?ecl_make_fixnum(v14):v12);
     cl_write_string(4, v11, v13, ECL_SYM("END",1225), T0);
    }
    {
     cl_object v14;
     {
      cl_fixnum v15;
      v15 = ecl_length(v11);
      v14 = ecl_minus(v12,ecl_make_fixnum(v15));
     }
     {
      cl_object v15i;
      v15i = ecl_make_fixnum(0);
      goto L64;
L63:;
      cl_write_char(2, CODE_CHAR(48), v13);
      v15i = ecl_one_plus(v15i);
L64:;
      if (!(ecl_number_compare(v15i,v14)<0)) { goto L69; }
      goto L63;
L69:;
     }
    }
    cl_write_char(2, CODE_CHAR(46), v13);
    {
     cl_fixnum v14;
     v14 = ecl_length(v11);
     T0 = (ecl_number_compare(ecl_make_fixnum(v14),v12)<=0?ecl_make_fixnum(v14):v12);
     cl_write_string(4, v11, v13, ECL_SYM("START",1310), T0);
    }
    if (Null(v3fdigits)) { goto L56; }
    {
     cl_object v14;
     {
      cl_fixnum v15;
      v15 = ecl_length(v11);
      {
       cl_fixnum v16;
       v16 = ecl_length(v11);
       T0 = (ecl_number_compare(ecl_make_fixnum(v16),v12)<=0?ecl_make_fixnum(v16):v12);
       T1 = ecl_minus(ecl_make_fixnum(v15),T0);
       v14 = ecl_minus(v3fdigits,T1);
      }
     }
     {
      cl_object v15i;
      v15i = ecl_make_fixnum(0);
      goto L77;
L76:;
      cl_write_char(2, CODE_CHAR(48), v13);
      v15i = ecl_one_plus(v15i);
L77:;
      if (!(ecl_number_compare(v15i,v14)<0)) { goto L82; }
      goto L76;
L82:;
      goto L56;
     }
    }
L57:;
    cl_write_string(2, _ecl_static_2, v13);
    {
     cl_object v16;
     v16 = ecl_negate(v12);
     {
      cl_object v17i;
      v17i = ecl_make_fixnum(0);
      goto L89;
L88:;
      cl_write_char(2, CODE_CHAR(48), v13);
      v17i = ecl_one_plus(v17i);
L89:;
      if (!(ecl_number_compare(v17i,v16)<0)) { goto L94; }
      goto L88;
L94:;
     }
    }
    cl_write_string(2, v11, v13);
    if (Null(v3fdigits)) { goto L56; }
    {
     cl_object v16;
     T0 = ecl_plus(v3fdigits,v12);
     {
      cl_fixnum v17;
      v17 = ecl_length(v11);
      T1 = ecl_negate(ecl_make_fixnum(v17));
      v16 = ecl_plus(T0,T1);
     }
     {
      cl_object v17i;
      v17i = ecl_make_fixnum(0);
      goto L101;
L100:;
      cl_write_char(2, CODE_CHAR(48), v13);
      v17i = ecl_one_plus(v17i);
L101:;
      if (!(ecl_number_compare(v17i,v16)<0)) { goto L106; }
      goto L100;
L106:;
     }
    }
L56:;
    {
     cl_object v14string;
     v14string = cl_get_output_stream_string(v13);
     {
      cl_fixnum v15;
      v15 = ecl_length(v14string);
      {
       ecl_character v16;
       v16 = ecl_char(v14string,0);
       {
        bool v17;
        v17 = (v16)==((ecl_character)(46));
        {
         cl_fixnum v18;
         v18 = ecl_length(v14string);
         T0 = ecl_make_integer((v18)-1);
         T1 = cl_char(v14string, T0);
         {
          bool v19;
          v19 = (ecl_char_code(T1))==((ecl_character)(46));
          T2 = cl_position(2, CODE_CHAR(46), v14string);
          cl_env_copy->nvalues = 5;
          cl_env_copy->values[4] = T2;
          cl_env_copy->values[3] = ecl_make_bool(v19);
          cl_env_copy->values[2] = ecl_make_bool(v17);
          cl_env_copy->values[1] = ecl_make_fixnum(v15);
          cl_env_copy->values[0] = v14string;
          return cl_env_copy->values[0];
         }
        }
       }
      }
     }
    }
   }
  }
 }
}
/*	function definition for SCALE-EXPONENT                        */
/*	optimize speed 1, debug 0, space 1, safety 0                  */
static cl_object L2scale_exponent(cl_object v1original_x)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  double v2x;
  cl_fixnum v3delta;
  v2x = ecl_to_double(v1original_x);
  v3delta = 0;
  {
   cl_fixnum v5;                                  /*  EXPONENT        */
   value0 = cl_decode_float(ecl_make_double_float(v2x));
   v5 = ecl_fixnum(cl_env_copy->values[1]);
   if (!((v2x)==0)) { goto L4; }
   T0 = cl_float(2, cl_core.doublefloat_zero, v1original_x);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = ecl_make_fixnum(1);
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
L4:;
   if (!((v5)<0)) { goto L6; }
   {
    double v6;
    v6 = -DBL_MIN;
    {
     double v7;
     v7 = DBL_MIN;
     if (!(((v6)<(v2x) && (v2x)<(v7)))) { goto L6; }
    }
   }
   v2x = (v2x)*(10000000000000000.0    );
   v3delta = -16;
L6:;
   {
    cl_fixnum v6ex;
    {
     double v7;
     v7 = (v5)*(.3010299914836512    );
     v6ex = ecl_fixnum(ecl_round1(ecl_make_double_float(v7)));
    }
    if (!((v6ex)<0)) { goto L15; }
    {
     double v7y;
     v7y =     0.    ;
L18:;
     {
      cl_fixnum v8;
      v8 = -(v6ex);
      T0 = ecl_expt(_ecl_static_5,ecl_make_fixnum(v8));
      v7y = (v2x)*(ecl_double_float(T0));
     }
     if ((v7y)<=(   10.0e-2)) { goto L22; }
     goto L19;
L22:;
     v6ex = (v6ex)-(1);
     goto L18;
L19:;
     {
      cl_fixnum v8;
      v8 = (v3delta)+(v6ex);
      cl_env_copy->nvalues = 2;
      cl_env_copy->values[1] = ecl_make_fixnum(v8);
      cl_env_copy->values[0] = ecl_make_double_float(v7y);
      return cl_env_copy->values[0];
     }
    }
L15:;
    {
     double v8y;
     v8y =     0.    ;
L29:;
     T0 = ecl_expt(_ecl_static_5,ecl_make_fixnum(v6ex));
     v8y = (v2x)/(ecl_double_float(T0));
     if ((v8y)>(   1.0    )) { goto L33; }
     goto L30;
L33:;
     v6ex = (v6ex)+(1);
     goto L29;
L30:;
     {
      cl_fixnum v9;
      v9 = (v3delta)+(v6ex);
      cl_env_copy->nvalues = 2;
      cl_env_copy->values[1] = ecl_make_fixnum(v9);
      cl_env_copy->values[0] = ecl_make_double_float(v8y);
      return cl_env_copy->values[0];
     }
    }
   }
  }
 }
}
/*	function definition for MAKE-FORMAT-DIRECTIVE                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3make_format_directive(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1;
  cl_object v2;
  cl_object v3;
  cl_object v4;
  cl_object v5;
  cl_object v6;
  cl_object v7;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  {
   cl_object keyvars[14];
   cl_parse_key(args,7,L3make_format_directivekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[7])) {
    v1 = ECL_T;
   } else {
    v1 = keyvars[0];
   }
   if (Null(keyvars[8])) {
    v2 = ecl_make_fixnum(0);
   } else {
    v2 = keyvars[1];
   }
   if (Null(keyvars[9])) {
    v3 = ecl_make_fixnum(0);
   } else {
    v3 = keyvars[2];
   }
   if (Null(keyvars[10])) {
    v4 = CODE_CHAR(32);
   } else {
    v4 = keyvars[3];
   }
   v5 = keyvars[4];
   v6 = keyvars[5];
   v7 = keyvars[6];
  }
  T0 = cl_list(8, VV[4], v1, v2, v3, v4, v5, v6, v7);
  value0 = cl_make_array(5, VV[7], ECL_SYM("ELEMENT-TYPE",1224), ECL_T, ECL_SYM("INITIAL-CONTENTS",1252), T0);
  return value0;
 }
}
/*	function definition for TOKENIZE-CONTROL-STRING               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4tokenize_control_string(cl_object v1string)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v2;
   cl_object v3index;
   cl_object v4result;
   v2 = ecl_length(v1string);
   v3index = ecl_make_fixnum(0);
   v4result = ECL_NIL;
L5:;
   {
    cl_object v5next_directive;
    value0 = cl_position(4, CODE_CHAR(126), v1string, ECL_SYM("START",1310), v3index);
    if ((value0)!=ECL_NIL) { goto L9; }
    v5next_directive = ecl_make_fixnum(v2);
    goto L7;
L9:;
    v5next_directive = value0;
    goto L7;
L7:;
    if (!(ecl_number_compare(v5next_directive,v3index)>0)) { goto L11; }
    T0 = cl_subseq(3, v1string, v3index, v5next_directive);
    v4result = CONS(T0,v4result);
L11:;
    if (!(ecl_number_equalp(v5next_directive,ecl_make_fixnum(v2)))) { goto L14; }
    goto L4;
L14:;
    {
     cl_object v6directive;
     v6directive = L6parse_directive(v1string, v5next_directive);
     v4result = CONS(v6directive,v4result);
     v3index = ecl_function_dispatch(cl_env_copy,VV[243])(1, v6directive) /*  FORMAT-DIRECTIVE-END */;
    }
   }
   goto L5;
L4:;
   value0 = cl_nreverse(v4result);
   return value0;
  }
 }
}
/*	function definition for PARSE-DIRECTIVE                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6parse_directive(cl_object v1string, cl_object v2start)
{
 cl_object T0, T1, T2;
 volatile cl_object lex0[4];
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  lex0[0] = v1string;                             /*  STRING          */
  lex0[1] = v2start;                              /*  START           */
TTL:
  {
   cl_object v3;
   cl_fixnum v4;
   cl_object v5params;
   cl_object v6colonp;
   cl_object v7atsignp;
   v3 = ecl_one_plus(lex0[1]);
   v4 = ecl_length(lex0[0]);
   lex0[2] = v3;                                  /*  POSN            */
   v5params = ECL_NIL;
   v6colonp = ECL_NIL;
   v7atsignp = ECL_NIL;
   lex0[3] = ecl_make_fixnum(v4);                 /*  END             */
L7:;
   {
    cl_object v8char;
    v8char = LC5get_char(lex0);
    if ((cl_charLE(3, CODE_CHAR(48), v8char, CODE_CHAR(57)))!=ECL_NIL) { goto L13; }
    if (ecl_char_code(v8char)==ecl_char_code(CODE_CHAR(43))) { goto L13; }
    if (!(ecl_char_code(v8char)==ecl_char_code(CODE_CHAR(45)))) { goto L11; }
    goto L12;
L13:;
L12:;
    {
     cl_object v10;                               /*  PARAM           */
     cl_object v11;                               /*  NEW-POSN        */
     value0 = cl_parse_integer(5, lex0[0], ECL_SYM("START",1310), lex0[2], ECL_SYM("JUNK-ALLOWED",1261), ECL_T);
     v10 = value0;
     v11 = cl_env_copy->values[1];
     T0 = CONS(lex0[2],v10);
     v5params = CONS(T0,v5params);
     lex0[2] = v11;
     {
      cl_object v12;
      v12 = LC5get_char(lex0);
      if (((v12)==ECL_CODE_CHAR((ecl_character)(44)))) { goto L9; }
      if (!(((v12)==ECL_CODE_CHAR((ecl_character)(58))))) { goto L28; }
      goto L25;
      goto L26;
L28:;
      goto L26;
L26:;
      if (!(((v12)==ECL_CODE_CHAR((ecl_character)(64))))) { goto L23; }
      goto L24;
L25:;
L24:;
      lex0[2] = ecl_minus(lex0[2],ecl_make_fixnum(1));
      goto L9;
L23:;
      goto L6;
     }
    }
L11:;
    if (ecl_char_code(v8char)==ecl_char_code(CODE_CHAR(118))) { goto L34; }
    if (!(ecl_char_code(v8char)==ecl_char_code(CODE_CHAR(86)))) { goto L32; }
    goto L33;
L34:;
L33:;
    T0 = CONS(lex0[2],VV[17]);
    v5params = CONS(T0,v5params);
    lex0[2] = ecl_plus(lex0[2],ecl_make_fixnum(1));
    {
     cl_object v9;
     v9 = LC5get_char(lex0);
     if (((v9)==ECL_CODE_CHAR((ecl_character)(44)))) { goto L9; }
     if (!(((v9)==ECL_CODE_CHAR((ecl_character)(58))))) { goto L47; }
     goto L44;
     goto L45;
L47:;
     goto L45;
L45:;
     if (!(((v9)==ECL_CODE_CHAR((ecl_character)(64))))) { goto L42; }
     goto L43;
L44:;
L43:;
     lex0[2] = ecl_minus(lex0[2],ecl_make_fixnum(1));
     goto L9;
L42:;
     goto L6;
    }
L32:;
    if (!(ecl_char_code(v8char)==ecl_char_code(CODE_CHAR(35)))) { goto L51; }
    T0 = CONS(lex0[2],VV[18]);
    v5params = CONS(T0,v5params);
    lex0[2] = ecl_plus(lex0[2],ecl_make_fixnum(1));
    {
     cl_object v10;
     v10 = LC5get_char(lex0);
     if (((v10)==ECL_CODE_CHAR((ecl_character)(44)))) { goto L9; }
     if (!(((v10)==ECL_CODE_CHAR((ecl_character)(58))))) { goto L64; }
     goto L61;
     goto L62;
L64:;
     goto L62;
L62:;
     if (!(((v10)==ECL_CODE_CHAR((ecl_character)(64))))) { goto L59; }
     goto L60;
L61:;
L60:;
     lex0[2] = ecl_minus(lex0[2],ecl_make_fixnum(1));
     goto L9;
L59:;
     goto L6;
    }
L51:;
    if (!(ecl_char_code(v8char)==ecl_char_code(CODE_CHAR(39)))) { goto L68; }
    lex0[2] = ecl_plus(lex0[2],ecl_make_fixnum(1));
    T0 = LC5get_char(lex0);
    T1 = CONS(lex0[2],T0);
    v5params = CONS(T1,v5params);
    lex0[2] = ecl_plus(lex0[2],ecl_make_fixnum(1));
    {
     cl_object v11;
     v11 = LC5get_char(lex0);
     if (((v11)==ECL_CODE_CHAR((ecl_character)(44)))) { goto L9; }
     if (!(((v11)==ECL_CODE_CHAR((ecl_character)(58))))) { goto L84; }
     goto L81;
     goto L82;
L84:;
     goto L82;
L82:;
     if (!(((v11)==ECL_CODE_CHAR((ecl_character)(64))))) { goto L79; }
     goto L80;
L81:;
L80:;
     lex0[2] = ecl_minus(lex0[2],ecl_make_fixnum(1));
     goto L9;
L79:;
     goto L6;
    }
L68:;
    if (!(ecl_char_code(v8char)==ecl_char_code(CODE_CHAR(44)))) { goto L88; }
    T0 = CONS(lex0[2],ECL_NIL);
    v5params = CONS(T0,v5params);
    goto L9;
L88:;
    if (!(ecl_char_code(v8char)==ecl_char_code(CODE_CHAR(58)))) { goto L91; }
    if (Null(v6colonp)) { goto L93; }
    cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_10, ECL_SYM("CONTROL-STRING",1211), lex0[0], ECL_SYM("OFFSET",1279), lex0[2]);
    goto L9;
L93:;
    v6colonp = ECL_T;
    goto L9;
L91:;
    if (!(ecl_char_code(v8char)==ecl_char_code(CODE_CHAR(64)))) { goto L96; }
    if (Null(v7atsignp)) { goto L98; }
    cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_11, ECL_SYM("CONTROL-STRING",1211), lex0[0], ECL_SYM("OFFSET",1279), lex0[2]);
    goto L9;
L98:;
    v7atsignp = ECL_T;
    goto L9;
L96:;
    T0 = ecl_one_minus(lex0[2]);
    T1 = ecl_elt(lex0[0],ecl_to_size(T0));
    if (!((ecl_char_code(T1))==((ecl_character)(44)))) { goto L101; }
    T0 = ecl_one_minus(lex0[2]);
    T1 = CONS(T0,ECL_NIL);
    v5params = CONS(T1,v5params);
L101:;
    goto L6;
   }
L9:;
   lex0[2] = ecl_plus(lex0[2],ecl_make_fixnum(1));
   goto L7;
L6:;
   {
    cl_object v8char;
    v8char = LC5get_char(lex0);
    if (!(ecl_char_code(v8char)==ecl_char_code(CODE_CHAR(47)))) { goto L107; }
    {
     cl_object v9closing_slash;
     T0 = ecl_one_plus(lex0[2]);
     v9closing_slash = cl_position(4, CODE_CHAR(47), lex0[0], ECL_SYM("START",1310), T0);
     if (Null(v9closing_slash)) { goto L110; }
     lex0[2] = v9closing_slash;
     goto L107;
L110:;
     cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_12, ECL_SYM("CONTROL-STRING",1211), lex0[0], ECL_SYM("OFFSET",1279), lex0[2]);
    }
L107:;
    T0 = ecl_one_plus(lex0[2]);
    T1 = cl_char_upcase(v8char);
    T2 = cl_nreverse(v5params);
    value0 = L3make_format_directive(14, VV[19], lex0[0], ECL_SYM("START",1310), lex0[1], ECL_SYM("END",1225), T0, VV[20], T1, VV[21], v6colonp, VV[22], v7atsignp, VV[23], T2);
    return value0;
   }
  }
 }
}
/*	local function GET-CHAR                                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC5get_char(volatile cl_object *lex0)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ecl_number_equalp(lex0[2],lex0[3]))) { goto L1; }
  value0 = cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_9, ECL_SYM("CONTROL-STRING",1211), lex0[0], ECL_SYM("OFFSET",1279), lex0[1]);
  return value0;
L1:;
  value0 = ecl_elt(lex0[0],ecl_to_size(lex0[2]));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for FORMATTER-AUX                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7formatter_aux(volatile cl_narg narg, cl_object volatile v1stream, cl_object volatile v2string_or_fun, cl_object volatile v3orig_args, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>4)) FEwrong_num_arguments_anonym();
 {
  volatile cl_object v4args;
  va_list args; va_start(args,v3orig_args);
  {
   int i = 3;
   if (i >= narg) {
    v4args = v3orig_args;
   } else {
    i++;
    v4args = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (Null(cl_functionp(v2string_or_fun))) { goto L2; }
  value0 = cl_apply(3, v2string_or_fun, v1stream, v4args);
  return value0;
L2:;
  value0 = VV[31];
  if (ecl_frs_push(cl_env_copy,value0)) {         /*  BEGIN CATCH 4   */
   value0 = cl_env_copy->values[0];
  } else {
   {
    cl_object v5string;
    if (Null(cl_simple_string_p(v2string_or_fun))) { goto L9; }
    v5string = v2string_or_fun;
    goto L8;
L9:;
    if (!(ECL_STRINGP(v2string_or_fun))) { goto L11; }
    v5string = si_coerce_to_vector(v2string_or_fun, ECL_SYM("CHARACTER",222), ECL_SYM("*",18), ECL_T);
    goto L8;
L11:;
    v5string = si_etypecase_error(v2string_or_fun, VV[32]);
L8:;
    ecl_bds_bind(cl_env_copy,VV[13],ECL_NIL);     /*  *OUTPUT-LAYOUT-MODE* */
    ecl_bds_bind(cl_env_copy,VV[11],v5string);    /*  *DEFAULT-FORMAT-ERROR-CONTROL-STRING* */
    ecl_bds_bind(cl_env_copy,VV[25],ECL_NIL);     /*  *LOGICAL-BLOCK-POPPER* */
    T0 = L4tokenize_control_string(v5string);
    value0 = L8interpret_directive_list(v1stream, T0, v3orig_args, v4args);
    ecl_bds_unwind1(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
   }
  }
  ecl_frs_pop(cl_env_copy);                       /*  END CATCH 4     */
  return value0;
 }
}
/*	function definition for INTERPRET-DIRECTIVE-LIST              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8interpret_directive_list(cl_object v1stream, cl_object v2directives, cl_object v3orig_args, cl_object v4args)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v2directives)) { goto L1; }
  {
   cl_object v5directive;
   v5directive = ecl_car(v2directives);
   if (Null(cl_simple_string_p(v5directive))) { goto L4; }
   cl_write_string(2, v5directive, v1stream);
   v2directives = ecl_cdr(v2directives);
   goto TTL;
L4:;
   if (!(ECL_VECTORP(v5directive))) { goto L12; }
   {
    cl_object v7;                                 /*  NEW-DIRECTIVES  */
    cl_object v8;                                 /*  NEW-ARGS        */
    {
     cl_object v9;
     cl_object v10;
     T0 = ecl_symbol_value(VV[10]);
     T1 = ecl_function_dispatch(cl_env_copy,VV[245])(1, v5directive) /*  FORMAT-DIRECTIVE-CHARACTER */;
     T2 = cl_char_code(T1);
     v9 = ecl_aref1(T0,ecl_to_fixnum(T2));
     T0 = ecl_function_dispatch(cl_env_copy,VV[243])(1, v5directive) /*  FORMAT-DIRECTIVE-END */;
     v10 = ecl_one_minus(T0);
     ecl_bds_bind(cl_env_copy,VV[12],v10);        /*  *DEFAULT-FORMAT-ERROR-OFFSET* */
     if ((v9)!=ECL_NIL) { goto L17; }
     cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_13);
L17:;
     {
      cl_object v12;                              /*  NEW-DIRECTIVES  */
      cl_object v13;                              /*  NEW-ARGS        */
      T0 = ecl_cdr(v2directives);
      value0 = ecl_function_dispatch(cl_env_copy,v9)(5, v1stream, v5directive, T0, v3orig_args, v4args);
      v12 = value0;
      {
       const int v14 = cl_env_copy->nvalues;
       cl_object v15;
       v15 = (v14<=1)? ECL_NIL : cl_env_copy->values[1];
       v13 = v15;
      }
      cl_env_copy->nvalues = 2;
      cl_env_copy->values[1] = v13;
      cl_env_copy->values[0] = v12;
      value0 = cl_env_copy->values[0];
      ecl_bds_unwind1(cl_env_copy);
     }
    }
    v7 = value0;
    v8 = cl_env_copy->values[1];
    v2directives = v7;
    v4args = v8;
    goto TTL;
   }
L12:;
   value0 = si_etypecase_error(v5directive, VV[34]);
   return value0;
  }
L1:;
  value0 = v4args;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function FORMATTER                                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC9formatter(cl_object v1, cl_object v2)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4control_string;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4control_string = v5;
   }
   if (Null(v3)) { goto L8; }
   si_dm_too_many_arguments(v1);
L8:;
   T0 = L10_formatter(v4control_string);
   value0 = cl_list(2, ECL_SYM("FUNCTION",396), T0);
   return value0;
  }
 }
}
/*	function definition for %FORMATTER                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L10_formatter(cl_object volatile v1control_string)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = VV[36];
  if (ecl_frs_push(cl_env_copy,value0)==0) {      /*  BEGIN CATCH 2   */
   {
    cl_object v2guts;
    cl_object v3args;
    ecl_bds_bind(cl_env_copy,VV[30],ECL_NIL);     /*  *SIMPLE-ARGS*   */
    ecl_bds_bind(cl_env_copy,VV[28],ECL_T);       /*  *ONLY-SIMPLE-ARGS* */
    v2guts = L11expand_control_string(v1control_string);
    v3args = ECL_NIL;
    {
     cl_object v4;
     v4 = ecl_symbol_value(VV[30]);
     goto L11;
L10:;
     {
      cl_object v5arg;
      v5arg = ecl_car(v4);
      T0 = ecl_car(v5arg);
      T1 = ecl_cdr(v5arg);
      T2 = cl_list(8, ECL_SYM("ERROR",337), VV[37], VV[14], _ecl_static_14, ECL_SYM("CONTROL-STRING",1211), v1control_string, ECL_SYM("OFFSET",1279), T1);
      T3 = cl_list(2, T0, T2);
      v3args = CONS(T3,v3args);
     }
     v4 = ecl_cdr(v4);
L11:;
     if (Null(v4)) { goto L19; }
     goto L10;
L19:;
    }
    T0 = ecl_append(v3args,VV[38]);
    T1 = cl_listX(3, ECL_SYM("STREAM",799), ECL_SYM("&OPTIONAL",11), T0);
    value0 = cl_list(4, ECL_SYM("LAMBDA",452), T1, v2guts, VV[39]);
    ecl_frs_pop(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    return value0;
   }
  }
  ecl_frs_pop(cl_env_copy);                       /*  END CATCH 2     */
  ecl_bds_bind(cl_env_copy,VV[29],ECL_T);         /*  *ORIG-ARGS-AVAILABLE* */
  ecl_bds_bind(cl_env_copy,VV[28],ECL_NIL);       /*  *ONLY-SIMPLE-ARGS* */
  T0 = L11expand_control_string(v1control_string);
  T1 = cl_list(4, ECL_SYM("LET",477), VV[41], T0, VV[39]);
  value0 = cl_list(3, ECL_SYM("LAMBDA",452), VV[40], T1);
  ecl_bds_unwind1(cl_env_copy);
  ecl_bds_unwind1(cl_env_copy);
  return value0;
 }
}
/*	function definition for EXPAND-CONTROL-STRING                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L11expand_control_string(cl_object v1string)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2string;
   cl_object v3directives;
   if (Null(cl_simple_string_p(v1string))) { goto L2; }
   v2string = v1string;
   goto L1;
L2:;
   if (!(ECL_STRINGP(v1string))) { goto L4; }
   v2string = si_coerce_to_vector(v1string, ECL_SYM("CHARACTER",222), ECL_SYM("*",18), ECL_T);
   goto L1;
L4:;
   v2string = si_etypecase_error(v1string, VV[32]);
L1:;
   ecl_bds_bind(cl_env_copy,VV[13],ECL_NIL);      /*  *OUTPUT-LAYOUT-MODE* */
   ecl_bds_bind(cl_env_copy,VV[11],v2string);     /*  *DEFAULT-FORMAT-ERROR-CONTROL-STRING* */
   v3directives = L4tokenize_control_string(v2string);
   T0 = L12expand_directive_list(v3directives);
   value0 = cl_listX(3, ECL_SYM("BLOCK",137), ECL_NIL, T0);
   ecl_bds_unwind1(cl_env_copy);
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
 }
}
/*	function definition for EXPAND-DIRECTIVE-LIST                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L12expand_directive_list(cl_object v1directives)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2results;
   cl_object v3remaining_directives;
   v2results = ECL_NIL;
   v3remaining_directives = v1directives;
L4:;
   if ((v3remaining_directives)!=ECL_NIL) { goto L6; }
   goto L3;
L6:;
   {
    cl_object v5;                                 /*  FORM            */
    cl_object v6;                                 /*  NEW-DIRECTIVES  */
    T0 = ecl_car(v3remaining_directives);
    T1 = ecl_cdr(v3remaining_directives);
    value0 = L13expand_directive(T0, T1);
    v5 = value0;
    {
     const int v7 = cl_env_copy->nvalues;
     cl_object v8;
     v8 = (v7<=1)? ECL_NIL : cl_env_copy->values[1];
     v6 = v8;
    }
    v2results = CONS(v5,v2results);
    v3remaining_directives = v6;
   }
   goto L4;
L3:;
   value0 = cl_reverse(v2results);
   return value0;
  }
 }
}
/*	function definition for EXPAND-DIRECTIVE                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L13expand_directive(cl_object v1directive, cl_object v2more_directives)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_simple_string_p(v1directive))) { goto L1; }
  T0 = cl_list(3, ECL_SYM("WRITE-STRING",922), v1directive, ECL_SYM("STREAM",799));
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = v2more_directives;
  cl_env_copy->values[0] = T0;
  return cl_env_copy->values[0];
L1:;
  if (!(ECL_VECTORP(v1directive))) { goto L3; }
  {
   cl_object v3;
   cl_object v4;
   {
    cl_object v5;
    v5 = ecl_symbol_value(VV[9]);
    {
     cl_fixnum v6;
     {
      cl_fixnum v7;
      T0 = ecl_function_dispatch(cl_env_copy,VV[245])(1, v1directive) /*  FORMAT-DIRECTIVE-CHARACTER */;
      v7 = CHAR_CODE(T0);
      if (ecl_unlikely((v7)>=(v5)->vector.dim))
           FEwrong_index(ECL_NIL,v5,-1,ecl_make_fixnum(v7),(v5)->vector.dim);
      v6 = v7;
     }
     v3 = ecl_aref_unsafe(v5,v6);
    }
   }
   T0 = ecl_function_dispatch(cl_env_copy,VV[243])(1, v1directive) /*  FORMAT-DIRECTIVE-END */;
   v4 = ecl_one_minus(T0);
   ecl_bds_bind(cl_env_copy,VV[12],v4);           /*  *DEFAULT-FORMAT-ERROR-OFFSET* */
   if (Null(v3)) { goto L12; }
   value0 = ecl_function_dispatch(cl_env_copy,v3)(2, v1directive, v2more_directives);
   ecl_bds_unwind1(cl_env_copy);
   return value0;
L12:;
   value0 = cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_15);
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
L3:;
  value0 = si_etypecase_error(v1directive, VV[42]);
  return value0;
 }
}
/*	function definition for EXPAND-NEXT-ARG                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L14expand_next_arg(cl_narg narg, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1offset;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1offset = ECL_NIL;
   } else {
    i++;
    v1offset = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if ((ecl_symbol_value(VV[29]))!=ECL_NIL) { goto L4; }
  if ((ecl_symbol_value(VV[28]))!=ECL_NIL) { goto L2; }
  goto L3;
L4:;
L3:;
  value0 = v1offset;
  if ((value0)!=ECL_NIL) { goto L8; }
  T0 = ecl_symbol_value(VV[12]);
  goto L6;
L8:;
  T0 = value0;
  goto L6;
L6:;
  value0 = cl_list(3, ecl_symbol_value(VV[26]), ecl_symbol_value(VV[11]), T0);
  return value0;
L2:;
  {
   cl_object v2symbol;
   v2symbol = cl_gensym(1, _ecl_static_16);
   value0 = v1offset;
   if ((value0)!=ECL_NIL) { goto L15; }
   T0 = ecl_symbol_value(VV[12]);
   goto L13;
L15:;
   T0 = value0;
   goto L13;
L13:;
   T1 = CONS(v2symbol,T0);
   cl_set(VV[30],CONS(T1,ecl_symbol_value(VV[30])));
   value0 = v2symbol;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for NEED-HAIRY-ARGS                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L15need_hairy_args()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_symbol_value(VV[28]))) { goto L1; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function EXPANDER-NEXT-ARG                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC16expander_next_arg(cl_object v1, cl_object v2)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4string;
   cl_object v5offset;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4string = v6;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5offset = v6;
   }
   if (Null(v3)) { goto L14; }
   si_dm_too_many_arguments(v1);
L14:;
   T0 = cl_list(8, ECL_SYM("ERROR",337), VV[37], VV[14], _ecl_static_17, ECL_SYM("CONTROL-STRING",1211), v4string, ECL_SYM("OFFSET",1279), v5offset);
   value0 = cl_list(4, ECL_SYM("IF",946), VV[39], VV[43], T0);
   return value0;
  }
 }
}
/*	local function EXPANDER-PPRINT-NEXT-ARG                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC17expander_pprint_next_arg(cl_object v1, cl_object v2)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4string;
   cl_object v5offset;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4string = v6;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5offset = v6;
   }
   if (Null(v3)) { goto L14; }
   si_dm_too_many_arguments(v1);
L14:;
   T0 = cl_list(8, ECL_SYM("ERROR",337), VV[37], VV[14], _ecl_static_17, ECL_SYM("CONTROL-STRING",1211), v4string, ECL_SYM("OFFSET",1279), v5offset);
   T1 = cl_list(3, ECL_SYM("WHEN",905), VV[45], T0);
   value0 = cl_listX(3, ECL_SYM("PROGN",671), T1, VV[46]);
   return value0;
  }
 }
}
/*	function definition for %SET-FORMAT-DIRECTIVE-EXPANDER        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L18_set_format_directive_expander(cl_object v1char, cl_object v2fn)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_symbol_value(VV[9]);
   {
    cl_fixnum v4;
    {
     cl_fixnum v5;
     {
      ecl_character v6;
      v6 = ecl_char_upcase(CHAR_CODE(v1char));
      v5 = v6;
     }
     if (ecl_unlikely((v5)>=(v3)->vector.dim))
           FEwrong_index(ECL_NIL,v3,-1,ecl_make_fixnum(v5),(v3)->vector.dim);
     v4 = v5;
    }
    ecl_aset_unsafe(v3,v4,v2fn);
   }
  }
  value0 = v1char;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for %SET-FORMAT-DIRECTIVE-INTERPRETER     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L19_set_format_directive_interpreter(cl_object v1char, cl_object v2fn)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_symbol_value(VV[10]);
   {
    cl_fixnum v4;
    {
     cl_fixnum v5;
     {
      ecl_character v6;
      v6 = ecl_char_upcase(CHAR_CODE(v1char));
      v5 = v6;
     }
     if (ecl_unlikely((v5)>=(v3)->vector.dim))
           FEwrong_index(ECL_NIL,v3,-1,ecl_make_fixnum(v5),(v3)->vector.dim);
     v4 = v5;
    }
    ecl_aset_unsafe(v3,v4,v2fn);
   }
  }
  value0 = v1char;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for FIND-DIRECTIVE                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L21find_directive(cl_object v1directives, cl_object v2kind, cl_object v3stop_at_semi)
{
 cl_object T0, T1;
 volatile cl_object lex0[1];
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  lex0[0] = v1directives;                         /*  DIRECTIVES      */
TTL:
  if (Null(lex0[0])) { goto L1; }
  {
   cl_object v4next;
   v4next = ecl_car(lex0[0]);
   if (Null(ecl_function_dispatch(cl_env_copy,VV[6])(1, v4next) /*  FORMAT-DIRECTIVE-P */)) { goto L4; }
   {
    cl_object v5char;
    v5char = ecl_function_dispatch(cl_env_copy,VV[245])(1, v4next) /*  FORMAT-DIRECTIVE-CHARACTER */;
    if (ecl_char_code(v2kind)==ecl_char_code(v5char)) { goto L9; }
    if (Null(v3stop_at_semi)) { goto L7; }
    if (!(ecl_char_code(v5char)==ecl_char_code(CODE_CHAR(59)))) { goto L7; }
    goto L8;
L9:;
L8:;
    value0 = ecl_car(lex0[0]);
    cl_env_copy->nvalues = 1;
    return value0;
L7:;
    if (!(((v5char)==ECL_CODE_CHAR((ecl_character)(40))))) { goto L15; }
    T1 = LC20after(lex0, CODE_CHAR(41));
    goto L14;
L15:;
    if (!(((v5char)==ECL_CODE_CHAR((ecl_character)(60))))) { goto L17; }
    T1 = LC20after(lex0, CODE_CHAR(62));
    goto L14;
L17:;
    if (!(((v5char)==ECL_CODE_CHAR((ecl_character)(91))))) { goto L19; }
    T1 = LC20after(lex0, CODE_CHAR(93));
    goto L14;
L19:;
    if (!(((v5char)==ECL_CODE_CHAR((ecl_character)(123))))) { goto L21; }
    T1 = LC20after(lex0, CODE_CHAR(125));
    goto L14;
L21:;
    T1 = lex0[0];
L14:;
    T0 = ecl_cdr(T1);
    lex0[0] = T0;
    goto TTL;
   }
L4:;
   T1 = ecl_cdr(lex0[0]);
   lex0[0] = T1;
   goto TTL;
  }
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function AFTER                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC20after(volatile cl_object *lex0, cl_object v1char)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_cdr(lex0[0]);
  T1 = L21find_directive(T0, v1char, ECL_NIL);
  value0 = ecl_memql(T1,lex0[0]);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for FORMAT-WRITE-FIELD                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L22format_write_field(cl_object v1stream, cl_object v2string, cl_object v3mincol, cl_object v4colinc, cl_object v5minpad, cl_object v6padchar, cl_object v7padleft)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((v7padleft)!=ECL_NIL) { goto L1; }
  cl_write_string(2, v2string, v1stream);
L1:;
  v5minpad = (ecl_number_compare(v5minpad,ecl_make_fixnum(0))>=0?v5minpad:ecl_make_fixnum(0));
  {
   cl_object v8i;
   v8i = ecl_make_fixnum(0);
   goto L8;
L7:;
   cl_write_char(2, v6padchar, v1stream);
   v8i = ecl_one_plus(v8i);
L8:;
   if (!(ecl_number_compare(v8i,v5minpad)<0)) { goto L13; }
   goto L7;
L13:;
  }
  if (Null(v3mincol)) { goto L17; }
  if (Null(v5minpad)) { goto L17; }
  if (Null(v4colinc)) { goto L17; }
  {
   cl_object v8chars;
   {
    cl_fixnum v9;
    v9 = ecl_length(v2string);
    v8chars = ecl_plus(ecl_make_fixnum(v9),v5minpad);
   }
   goto L24;
L23:;
   {
    cl_object v9i;
    v9i = ecl_make_fixnum(0);
    goto L29;
L28:;
    cl_write_char(2, v6padchar, v1stream);
    v9i = ecl_one_plus(v9i);
L29:;
    if (!(ecl_number_compare(v9i,v4colinc)<0)) { goto L34; }
    goto L28;
L34:;
   }
   v8chars = ecl_plus(v8chars,v4colinc);
L24:;
   if (ecl_number_compare(v8chars,v3mincol)>=0) { goto L38; }
   goto L23;
L38:;
   goto L15;
  }
L17:;
  goto L15;
L15:;
  if (Null(v7padleft)) { goto L40; }
  value0 = cl_write_string(2, v2string, v1stream);
  return value0;
L40:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for FORMAT-PRINC                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_format_princ(cl_narg narg, cl_object v1stream, cl_object v2arg, cl_object v3colonp, cl_object v4atsignp, cl_object v5mincol, cl_object v6colinc, cl_object v7minpad, cl_object v8padchar, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg!=8)) FEwrong_num_arguments_anonym();
 {
TTL:
  if ((v2arg)!=ECL_NIL) { goto L4; }
  if ((v3colonp)!=ECL_NIL) { goto L2; }
  goto L3;
L4:;
L3:;
  T0 = cl_princ_to_string(v2arg);
  goto L1;
L2:;
  T0 = _ecl_static_18;
L1:;
  value0 = L22format_write_field(v1stream, T0, v5mincol, v6colinc, v7minpad, v8padchar, v4atsignp);
  return value0;
 }
}
/*	local function G275                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC23__g275(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   v3 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v1) /*  FORMAT-DIRECTIVE-COLONP */;
   v4 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v1) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v5 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v1) /*  FORMAT-DIRECTIVE-PARAMS */;
   if (Null(v5)) { goto L5; }
   {
    cl_object v6;
    v6 = v5;
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L13; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L13:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L21; }
     T2 = L14expand_next_arg(1, v8offset);
     T1 = cl_list(3, ECL_SYM("OR",614), T2, ecl_make_fixnum(0));
     goto L8;
L21:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L23; }
     cl_set(VV[28],ECL_NIL);
     T1 = VV[54];
     goto L8;
L23:;
     if (!((v9param)==(ECL_NIL))) { goto L27; }
     T1 = ecl_make_fixnum(0);
     goto L8;
L27:;
     T1 = v9param;
    }
L8:;
    T2 = cl_list(2, VV[50], T1);
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L35; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L35:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L43; }
     T4 = L14expand_next_arg(1, v8offset);
     T3 = cl_list(3, ECL_SYM("OR",614), T4, ecl_make_fixnum(1));
     goto L30;
L43:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L45; }
     cl_set(VV[28],ECL_NIL);
     T3 = VV[54];
     goto L30;
L45:;
     if (!((v9param)==(ECL_NIL))) { goto L49; }
     T3 = ecl_make_fixnum(1);
     goto L30;
L49:;
     T3 = v9param;
    }
L30:;
    T4 = cl_list(2, VV[51], T3);
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L57; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L57:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L65; }
     T6 = L14expand_next_arg(1, v8offset);
     T5 = cl_list(3, ECL_SYM("OR",614), T6, ecl_make_fixnum(0));
     goto L52;
L65:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L67; }
     cl_set(VV[28],ECL_NIL);
     T5 = VV[54];
     goto L52;
L67:;
     if (!((v9param)==(ECL_NIL))) { goto L71; }
     T5 = ecl_make_fixnum(0);
     goto L52;
L71:;
     T5 = v9param;
    }
L52:;
    T6 = cl_list(2, VV[52], T5);
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L79; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L79:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L87; }
     T8 = L14expand_next_arg(1, v8offset);
     T7 = cl_list(3, ECL_SYM("OR",614), T8, CODE_CHAR(32));
     goto L74;
L87:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L89; }
     cl_set(VV[28],ECL_NIL);
     T7 = VV[54];
     goto L74;
L89:;
     if (!((v9param)==(ECL_NIL))) { goto L93; }
     T7 = CODE_CHAR(32);
     goto L74;
L93:;
     T7 = v9param;
    }
L74:;
    T8 = cl_list(2, VV[53], T7);
    T9 = cl_list(4, T2, T4, T6, T8);
    if (Null(v6)) { goto L97; }
    T11 = ecl_list1(ecl_make_fixnum(4));
    T12 = ecl_caar(v6);
    T10 = cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T11, ECL_SYM("OFFSET",1279), T12);
    goto L96;
L97:;
    T10 = ECL_NIL;
L96:;
    T11 = L14expand_next_arg(0);
    T12 = cl_list(2, ECL_SYM("QUOTE",679), v3);
    T13 = cl_list(2, ECL_SYM("QUOTE",679), v4);
    T14 = cl_list(9, VV[49], ECL_SYM("STREAM",799), T11, T12, T13, VV[50], VV[51], VV[52], VV[53]);
    T15 = ecl_list1(T14);
    T16 = ecl_append(T10,T15);
    T0 = cl_listX(3, ECL_SYM("LET",477), T9, T16);
    goto L4;
   }
L5:;
   if (Null(v3)) { goto L100; }
   T2 = L14expand_next_arg(0);
   T1 = cl_list(3, ECL_SYM("OR",614), T2, _ecl_static_18);
   goto L99;
L100:;
   T1 = L14expand_next_arg(0);
L99:;
   T0 = cl_list(3, ECL_SYM("PRINC",660), T1, ECL_SYM("STREAM",799));
L4:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v2;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G310                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC24__g310(cl_object v1stream, cl_object v2, cl_object v3, cl_object v4orig_args, cl_object v5args)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6;
   cl_object v7;
   cl_object v8;
   v6 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v2) /*  FORMAT-DIRECTIVE-COLONP */;
   v7 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v2) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v8 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v2) /*  FORMAT-DIRECTIVE-PARAMS */;
   if (Null(v8)) { goto L5; }
   {
    cl_object v9;
    v9 = v8;
    {
     cl_object v10mincol;
     cl_object v11colinc;
     cl_object v12minpad;
     cl_object v13padchar;
     {
      cl_object v14param_and_offset;
      cl_object v15offset;
      cl_object v16param;
      {
       cl_object v17;
       v17 = v9;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L13; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v9 = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L13:;
       v14param_and_offset = v17;
      }
      v15offset = ecl_car(v14param_and_offset);
      v16param = ecl_cdr(v14param_and_offset);
      if (!(ecl_eql(v16param,VV[17]))) { goto L21; }
      if (!(v5args==ECL_NIL)) { goto L26; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v15offset);
L26:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L28; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L28:;
      {
       cl_object v17;
       v17 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L33; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v5args = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L33:;
       value0 = v17;
      }
      if ((value0)!=ECL_NIL) { goto L24; }
      v10mincol = ecl_make_fixnum(0);
      goto L8;
L24:;
      v10mincol = value0;
      goto L8;
L21:;
      if (!(ecl_eql(v16param,VV[18]))) { goto L39; }
      v10mincol = ecl_make_fixnum(ecl_length(v5args));
      goto L8;
L39:;
      if (!((v16param)==(ECL_NIL))) { goto L41; }
      v10mincol = ecl_make_fixnum(0);
      goto L8;
L41:;
      v10mincol = v16param;
     }
L8:;
     {
      cl_object v14param_and_offset;
      cl_object v15offset;
      cl_object v16param;
      {
       cl_object v17;
       v17 = v9;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L49; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v9 = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L49:;
       v14param_and_offset = v17;
      }
      v15offset = ecl_car(v14param_and_offset);
      v16param = ecl_cdr(v14param_and_offset);
      if (!(ecl_eql(v16param,VV[17]))) { goto L57; }
      if (!(v5args==ECL_NIL)) { goto L62; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v15offset);
L62:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L64; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L64:;
      {
       cl_object v17;
       v17 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L69; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v5args = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L69:;
       value0 = v17;
      }
      if ((value0)!=ECL_NIL) { goto L60; }
      v11colinc = ecl_make_fixnum(1);
      goto L44;
L60:;
      v11colinc = value0;
      goto L44;
L57:;
      if (!(ecl_eql(v16param,VV[18]))) { goto L75; }
      v11colinc = ecl_make_fixnum(ecl_length(v5args));
      goto L44;
L75:;
      if (!((v16param)==(ECL_NIL))) { goto L77; }
      v11colinc = ecl_make_fixnum(1);
      goto L44;
L77:;
      v11colinc = v16param;
     }
L44:;
     {
      cl_object v14param_and_offset;
      cl_object v15offset;
      cl_object v16param;
      {
       cl_object v17;
       v17 = v9;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L85; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v9 = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L85:;
       v14param_and_offset = v17;
      }
      v15offset = ecl_car(v14param_and_offset);
      v16param = ecl_cdr(v14param_and_offset);
      if (!(ecl_eql(v16param,VV[17]))) { goto L93; }
      if (!(v5args==ECL_NIL)) { goto L98; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v15offset);
L98:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L100; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L100:;
      {
       cl_object v17;
       v17 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L105; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v5args = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L105:;
       value0 = v17;
      }
      if ((value0)!=ECL_NIL) { goto L96; }
      v12minpad = ecl_make_fixnum(0);
      goto L80;
L96:;
      v12minpad = value0;
      goto L80;
L93:;
      if (!(ecl_eql(v16param,VV[18]))) { goto L111; }
      v12minpad = ecl_make_fixnum(ecl_length(v5args));
      goto L80;
L111:;
      if (!((v16param)==(ECL_NIL))) { goto L113; }
      v12minpad = ecl_make_fixnum(0);
      goto L80;
L113:;
      v12minpad = v16param;
     }
L80:;
     {
      cl_object v14param_and_offset;
      cl_object v15offset;
      cl_object v16param;
      {
       cl_object v17;
       v17 = v9;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L121; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v9 = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L121:;
       v14param_and_offset = v17;
      }
      v15offset = ecl_car(v14param_and_offset);
      v16param = ecl_cdr(v14param_and_offset);
      if (!(ecl_eql(v16param,VV[17]))) { goto L129; }
      if (!(v5args==ECL_NIL)) { goto L134; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v15offset);
L134:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L136; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L136:;
      {
       cl_object v17;
       v17 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L141; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v5args = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L141:;
       value0 = v17;
      }
      if ((value0)!=ECL_NIL) { goto L132; }
      v13padchar = CODE_CHAR(32);
      goto L116;
L132:;
      v13padchar = value0;
      goto L116;
L129:;
      if (!(ecl_eql(v16param,VV[18]))) { goto L147; }
      v13padchar = ecl_make_fixnum(ecl_length(v5args));
      goto L116;
L147:;
      if (!((v16param)==(ECL_NIL))) { goto L149; }
      v13padchar = CODE_CHAR(32);
      goto L116;
L149:;
      v13padchar = v16param;
     }
L116:;
     if (Null(v9)) { goto L152; }
     T0 = ecl_list1(ecl_make_fixnum(4));
     T1 = ecl_caar(v9);
     cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T0, ECL_SYM("OFFSET",1279), T1);
L152:;
     if (!(v5args==ECL_NIL)) { goto L154; }
     cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L154:;
     if (Null(ecl_symbol_value(VV[25]))) { goto L156; }
     ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L156:;
     {
      cl_object v14;
      v14 = v5args;
      if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
      if (Null(v14)) { goto L162; }
      {
       cl_object v15;
       v15 = ECL_CONS_CDR(v14);
       v5args = v15;
       v14 = ECL_CONS_CAR(v14);
      }
L162:;
      T0 = v14;
     }
     si_format_princ(8, v1stream, T0, v6, v7, v10mincol, v11colinc, v12minpad, v13padchar);
     goto L4;
    }
   }
L5:;
   if (Null(v6)) { goto L169; }
   if (!(v5args==ECL_NIL)) { goto L174; }
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L174:;
   if (Null(ecl_symbol_value(VV[25]))) { goto L176; }
   ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L176:;
   {
    cl_object v14;
    v14 = v5args;
    if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
    if (Null(v14)) { goto L181; }
    {
     cl_object v15;
     v15 = ECL_CONS_CDR(v14);
     v5args = v15;
     v14 = ECL_CONS_CAR(v14);
    }
L181:;
    value0 = v14;
   }
   if ((value0)!=ECL_NIL) { goto L172; }
   T0 = _ecl_static_18;
   goto L168;
L172:;
   T0 = value0;
   goto L168;
L169:;
   if (!(v5args==ECL_NIL)) { goto L187; }
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L187:;
   if (Null(ecl_symbol_value(VV[25]))) { goto L189; }
   ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L189:;
   {
    cl_object v14;
    v14 = v5args;
    if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
    if (Null(v14)) { goto L194; }
    {
     cl_object v15;
     v15 = ECL_CONS_CDR(v14);
     v5args = v15;
     v14 = ECL_CONS_CAR(v14);
    }
L194:;
    T0 = v14;
   }
L168:;
   ecl_princ(T0,v1stream);
L4:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5args;
   cl_env_copy->values[0] = v3;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for FORMAT-PRIN1                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_format_prin1(cl_narg narg, cl_object v1stream, cl_object v2arg, cl_object v3colonp, cl_object v4atsignp, cl_object v5mincol, cl_object v6colinc, cl_object v7minpad, cl_object v8padchar, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg!=8)) FEwrong_num_arguments_anonym();
 {
TTL:
  if ((v2arg)!=ECL_NIL) { goto L4; }
  if ((v3colonp)!=ECL_NIL) { goto L2; }
  goto L3;
L4:;
L3:;
  T0 = cl_prin1_to_string(v2arg);
  goto L1;
L2:;
  T0 = _ecl_static_18;
L1:;
  value0 = L22format_write_field(v1stream, T0, v5mincol, v6colinc, v7minpad, v8padchar, v4atsignp);
  return value0;
 }
}
/*	local function G347                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC25__g347(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   v3 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v1) /*  FORMAT-DIRECTIVE-COLONP */;
   v4 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v1) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v5 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v1) /*  FORMAT-DIRECTIVE-PARAMS */;
   if (Null(v5)) { goto L5; }
   {
    cl_object v6;
    v6 = v5;
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L13; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L13:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L21; }
     T2 = L14expand_next_arg(1, v8offset);
     T1 = cl_list(3, ECL_SYM("OR",614), T2, ecl_make_fixnum(0));
     goto L8;
L21:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L23; }
     cl_set(VV[28],ECL_NIL);
     T1 = VV[54];
     goto L8;
L23:;
     if (!((v9param)==(ECL_NIL))) { goto L27; }
     T1 = ecl_make_fixnum(0);
     goto L8;
L27:;
     T1 = v9param;
    }
L8:;
    T2 = cl_list(2, VV[58], T1);
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L35; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L35:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L43; }
     T4 = L14expand_next_arg(1, v8offset);
     T3 = cl_list(3, ECL_SYM("OR",614), T4, ecl_make_fixnum(1));
     goto L30;
L43:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L45; }
     cl_set(VV[28],ECL_NIL);
     T3 = VV[54];
     goto L30;
L45:;
     if (!((v9param)==(ECL_NIL))) { goto L49; }
     T3 = ecl_make_fixnum(1);
     goto L30;
L49:;
     T3 = v9param;
    }
L30:;
    T4 = cl_list(2, VV[59], T3);
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L57; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L57:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L65; }
     T6 = L14expand_next_arg(1, v8offset);
     T5 = cl_list(3, ECL_SYM("OR",614), T6, ecl_make_fixnum(0));
     goto L52;
L65:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L67; }
     cl_set(VV[28],ECL_NIL);
     T5 = VV[54];
     goto L52;
L67:;
     if (!((v9param)==(ECL_NIL))) { goto L71; }
     T5 = ecl_make_fixnum(0);
     goto L52;
L71:;
     T5 = v9param;
    }
L52:;
    T6 = cl_list(2, VV[60], T5);
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L79; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L79:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L87; }
     T8 = L14expand_next_arg(1, v8offset);
     T7 = cl_list(3, ECL_SYM("OR",614), T8, CODE_CHAR(32));
     goto L74;
L87:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L89; }
     cl_set(VV[28],ECL_NIL);
     T7 = VV[54];
     goto L74;
L89:;
     if (!((v9param)==(ECL_NIL))) { goto L93; }
     T7 = CODE_CHAR(32);
     goto L74;
L93:;
     T7 = v9param;
    }
L74:;
    T8 = cl_list(2, VV[61], T7);
    T9 = cl_list(4, T2, T4, T6, T8);
    if (Null(v6)) { goto L97; }
    T11 = ecl_list1(ecl_make_fixnum(4));
    T12 = ecl_caar(v6);
    T10 = cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T11, ECL_SYM("OFFSET",1279), T12);
    goto L96;
L97:;
    T10 = ECL_NIL;
L96:;
    T11 = L14expand_next_arg(0);
    T12 = cl_list(9, VV[57], ECL_SYM("STREAM",799), T11, v3, v4, VV[58], VV[59], VV[60], VV[61]);
    T13 = ecl_list1(T12);
    T14 = ecl_append(T10,T13);
    T0 = cl_listX(3, ECL_SYM("LET",477), T9, T14);
    goto L4;
   }
L5:;
   if (Null(v3)) { goto L99; }
   T1 = L14expand_next_arg(0);
   T2 = cl_list(2, VV[62], T1);
   T3 = ecl_list1(T2);
   T0 = cl_list(3, ECL_SYM("LET",477), T3, VV[63]);
   goto L4;
L99:;
   T1 = L14expand_next_arg(0);
   T0 = cl_list(3, ECL_SYM("PRIN1",658), T1, ECL_SYM("STREAM",799));
L4:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v2;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G382                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC26__g382(cl_object v1stream, cl_object v2, cl_object v3, cl_object v4orig_args, cl_object v5args)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6;
   cl_object v7;
   cl_object v8;
   v6 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v2) /*  FORMAT-DIRECTIVE-COLONP */;
   v7 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v2) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v8 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v2) /*  FORMAT-DIRECTIVE-PARAMS */;
   if (Null(v8)) { goto L5; }
   {
    cl_object v9;
    v9 = v8;
    {
     cl_object v10mincol;
     cl_object v11colinc;
     cl_object v12minpad;
     cl_object v13padchar;
     {
      cl_object v14param_and_offset;
      cl_object v15offset;
      cl_object v16param;
      {
       cl_object v17;
       v17 = v9;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L13; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v9 = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L13:;
       v14param_and_offset = v17;
      }
      v15offset = ecl_car(v14param_and_offset);
      v16param = ecl_cdr(v14param_and_offset);
      if (!(ecl_eql(v16param,VV[17]))) { goto L21; }
      if (!(v5args==ECL_NIL)) { goto L26; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v15offset);
L26:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L28; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L28:;
      {
       cl_object v17;
       v17 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L33; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v5args = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L33:;
       value0 = v17;
      }
      if ((value0)!=ECL_NIL) { goto L24; }
      v10mincol = ecl_make_fixnum(0);
      goto L8;
L24:;
      v10mincol = value0;
      goto L8;
L21:;
      if (!(ecl_eql(v16param,VV[18]))) { goto L39; }
      v10mincol = ecl_make_fixnum(ecl_length(v5args));
      goto L8;
L39:;
      if (!((v16param)==(ECL_NIL))) { goto L41; }
      v10mincol = ecl_make_fixnum(0);
      goto L8;
L41:;
      v10mincol = v16param;
     }
L8:;
     {
      cl_object v14param_and_offset;
      cl_object v15offset;
      cl_object v16param;
      {
       cl_object v17;
       v17 = v9;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L49; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v9 = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L49:;
       v14param_and_offset = v17;
      }
      v15offset = ecl_car(v14param_and_offset);
      v16param = ecl_cdr(v14param_and_offset);
      if (!(ecl_eql(v16param,VV[17]))) { goto L57; }
      if (!(v5args==ECL_NIL)) { goto L62; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v15offset);
L62:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L64; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L64:;
      {
       cl_object v17;
       v17 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L69; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v5args = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L69:;
       value0 = v17;
      }
      if ((value0)!=ECL_NIL) { goto L60; }
      v11colinc = ecl_make_fixnum(1);
      goto L44;
L60:;
      v11colinc = value0;
      goto L44;
L57:;
      if (!(ecl_eql(v16param,VV[18]))) { goto L75; }
      v11colinc = ecl_make_fixnum(ecl_length(v5args));
      goto L44;
L75:;
      if (!((v16param)==(ECL_NIL))) { goto L77; }
      v11colinc = ecl_make_fixnum(1);
      goto L44;
L77:;
      v11colinc = v16param;
     }
L44:;
     {
      cl_object v14param_and_offset;
      cl_object v15offset;
      cl_object v16param;
      {
       cl_object v17;
       v17 = v9;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L85; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v9 = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L85:;
       v14param_and_offset = v17;
      }
      v15offset = ecl_car(v14param_and_offset);
      v16param = ecl_cdr(v14param_and_offset);
      if (!(ecl_eql(v16param,VV[17]))) { goto L93; }
      if (!(v5args==ECL_NIL)) { goto L98; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v15offset);
L98:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L100; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L100:;
      {
       cl_object v17;
       v17 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L105; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v5args = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L105:;
       value0 = v17;
      }
      if ((value0)!=ECL_NIL) { goto L96; }
      v12minpad = ecl_make_fixnum(0);
      goto L80;
L96:;
      v12minpad = value0;
      goto L80;
L93:;
      if (!(ecl_eql(v16param,VV[18]))) { goto L111; }
      v12minpad = ecl_make_fixnum(ecl_length(v5args));
      goto L80;
L111:;
      if (!((v16param)==(ECL_NIL))) { goto L113; }
      v12minpad = ecl_make_fixnum(0);
      goto L80;
L113:;
      v12minpad = v16param;
     }
L80:;
     {
      cl_object v14param_and_offset;
      cl_object v15offset;
      cl_object v16param;
      {
       cl_object v17;
       v17 = v9;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L121; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v9 = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L121:;
       v14param_and_offset = v17;
      }
      v15offset = ecl_car(v14param_and_offset);
      v16param = ecl_cdr(v14param_and_offset);
      if (!(ecl_eql(v16param,VV[17]))) { goto L129; }
      if (!(v5args==ECL_NIL)) { goto L134; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v15offset);
L134:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L136; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L136:;
      {
       cl_object v17;
       v17 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L141; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v5args = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L141:;
       value0 = v17;
      }
      if ((value0)!=ECL_NIL) { goto L132; }
      v13padchar = CODE_CHAR(32);
      goto L116;
L132:;
      v13padchar = value0;
      goto L116;
L129:;
      if (!(ecl_eql(v16param,VV[18]))) { goto L147; }
      v13padchar = ecl_make_fixnum(ecl_length(v5args));
      goto L116;
L147:;
      if (!((v16param)==(ECL_NIL))) { goto L149; }
      v13padchar = CODE_CHAR(32);
      goto L116;
L149:;
      v13padchar = v16param;
     }
L116:;
     if (Null(v9)) { goto L152; }
     T0 = ecl_list1(ecl_make_fixnum(4));
     T1 = ecl_caar(v9);
     cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T0, ECL_SYM("OFFSET",1279), T1);
L152:;
     if (!(v5args==ECL_NIL)) { goto L154; }
     cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L154:;
     if (Null(ecl_symbol_value(VV[25]))) { goto L156; }
     ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L156:;
     {
      cl_object v14;
      v14 = v5args;
      if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
      if (Null(v14)) { goto L162; }
      {
       cl_object v15;
       v15 = ECL_CONS_CDR(v14);
       v5args = v15;
       v14 = ECL_CONS_CAR(v14);
      }
L162:;
      T0 = v14;
     }
     si_format_prin1(8, v1stream, T0, v6, v7, v10mincol, v11colinc, v12minpad, v13padchar);
     goto L4;
    }
   }
L5:;
   if (Null(v6)) { goto L168; }
   {
    cl_object v14arg;
    if (!(v5args==ECL_NIL)) { goto L171; }
    cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L171:;
    if (Null(ecl_symbol_value(VV[25]))) { goto L173; }
    ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L173:;
    {
     cl_object v15;
     v15 = v5args;
     if (ecl_unlikely(!ECL_LISTP(v15))) FEtype_error_list(v15);
     if (Null(v15)) { goto L178; }
     {
      cl_object v16;
      v16 = ECL_CONS_CDR(v15);
      v5args = v16;
      v15 = ECL_CONS_CAR(v15);
     }
L178:;
     v14arg = v15;
    }
    if (Null(v14arg)) { goto L184; }
    ecl_prin1(v14arg,v1stream);
    goto L4;
L184:;
    ecl_princ_str("()",v1stream);
    goto L4;
   }
L168:;
   if (!(v5args==ECL_NIL)) { goto L187; }
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L187:;
   if (Null(ecl_symbol_value(VV[25]))) { goto L189; }
   ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L189:;
   {
    cl_object v15;
    v15 = v5args;
    if (ecl_unlikely(!ECL_LISTP(v15))) FEtype_error_list(v15);
    if (Null(v15)) { goto L195; }
    {
     cl_object v16;
     v16 = ECL_CONS_CDR(v15);
     v5args = v16;
     v15 = ECL_CONS_CAR(v15);
    }
L195:;
    T0 = v15;
   }
   ecl_prin1(T0,v1stream);
L4:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5args;
   cl_env_copy->values[0] = v3;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G419                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC27__g419(cl_object v1, cl_object v2)
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
   cl_object v5;
   v3 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v1) /*  FORMAT-DIRECTIVE-COLONP */;
   v4 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v1) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v5 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v1) /*  FORMAT-DIRECTIVE-PARAMS */;
   if (Null(v5)) { goto L5; }
   T1 = ecl_caar(v5);
   cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_20, ECL_SYM("OFFSET",1279), T1);
L5:;
   if (Null(v3)) { goto L7; }
   T1 = L14expand_next_arg(0);
   T0 = cl_list(3, VV[64], T1, ECL_SYM("STREAM",799));
   goto L4;
L7:;
   if (Null(v4)) { goto L9; }
   T1 = L14expand_next_arg(0);
   T0 = cl_list(3, ECL_SYM("PRIN1",658), T1, ECL_SYM("STREAM",799));
   goto L4;
L9:;
   T1 = L14expand_next_arg(0);
   T0 = cl_list(3, ECL_SYM("WRITE-CHAR",919), T1, ECL_SYM("STREAM",799));
L4:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v2;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G426                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC28__g426(cl_object v1stream, cl_object v2, cl_object v3, cl_object v4orig_args, cl_object v5args)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6;
   cl_object v7;
   cl_object v8;
   v6 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v2) /*  FORMAT-DIRECTIVE-COLONP */;
   v7 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v2) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v8 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v2) /*  FORMAT-DIRECTIVE-PARAMS */;
   if (Null(v8)) { goto L5; }
   T0 = ecl_list1(ecl_make_fixnum(0));
   T1 = ecl_caar(v8);
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T0, ECL_SYM("OFFSET",1279), T1);
L5:;
   if (Null(v6)) { goto L7; }
   if (!(v5args==ECL_NIL)) { goto L9; }
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L9:;
   if (Null(ecl_symbol_value(VV[25]))) { goto L11; }
   ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L11:;
   {
    cl_object v9;
    v9 = v5args;
    if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
    if (Null(v9)) { goto L17; }
    {
     cl_object v10;
     v10 = ECL_CONS_CDR(v9);
     v5args = v10;
     v9 = ECL_CONS_CAR(v9);
    }
L17:;
    T0 = v9;
   }
   si_format_print_named_character(2, T0, v1stream);
   goto L4;
L7:;
   if (Null(v7)) { goto L23; }
   if (!(v5args==ECL_NIL)) { goto L25; }
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L25:;
   if (Null(ecl_symbol_value(VV[25]))) { goto L27; }
   ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L27:;
   {
    cl_object v9;
    v9 = v5args;
    if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
    if (Null(v9)) { goto L33; }
    {
     cl_object v10;
     v10 = ECL_CONS_CDR(v9);
     v5args = v10;
     v9 = ECL_CONS_CAR(v9);
    }
L33:;
    T0 = v9;
   }
   ecl_prin1(T0,v1stream);
   goto L4;
L23:;
   if (!(v5args==ECL_NIL)) { goto L39; }
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L39:;
   if (Null(ecl_symbol_value(VV[25]))) { goto L41; }
   ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L41:;
   {
    cl_object v9;
    v9 = v5args;
    if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
    if (Null(v9)) { goto L47; }
    {
     cl_object v10;
     v10 = ECL_CONS_CDR(v9);
     v5args = v10;
     v9 = ECL_CONS_CAR(v9);
    }
L47:;
    T0 = v9;
   }
   cl_write_char(2, T0, v1stream);
L4:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5args;
   cl_env_copy->values[0] = v3;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for CHAR-PRINTING-P                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L29char_printing_p(cl_object v1char)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (((v1char)==ECL_CODE_CHAR((ecl_character)(32)))) { goto L2; }
  value0 = cl_graphic_char_p(v1char);
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for FORMAT-PRINT-NAMED-CHARACTER          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_format_print_named_character(cl_narg narg, cl_object v1char, cl_object v2stream, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  if ((L29char_printing_p(v1char))!=ECL_NIL) { goto L1; }
  T0 = cl_char_name(v1char);
  value0 = cl_write_string(2, T0, v2stream);
  return value0;
L1:;
  value0 = cl_write_char(2, v1char, v2stream);
  return value0;
 }
}
/*	local function G439                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC30__g439(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   v3 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v1) /*  FORMAT-DIRECTIVE-COLONP */;
   v4 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v1) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v5 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v1) /*  FORMAT-DIRECTIVE-PARAMS */;
   L115check_output_layout_mode(ecl_make_fixnum(1));
   if (Null(v5)) { goto L6; }
   T1 = ecl_caar(v5);
   cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_20, ECL_SYM("OFFSET",1279), T1);
L6:;
   if ((v3)!=ECL_NIL) { goto L10; }
   if (Null(v4)) { goto L8; }
   goto L9;
L10:;
L9:;
   if (Null(v3)) { goto L13; }
   T1 = VV[66];
   goto L12;
L13:;
   T1 = ECL_NIL;
L12:;
   if (Null(v4)) { goto L16; }
   T2 = VV[67];
   goto L15;
L16:;
   T2 = ECL_NIL;
L15:;
   T3 = ecl_append(T1,T2);
   T4 = L14expand_next_arg(0);
   T5 = cl_list(3, ECL_SYM("WRITE-OBJECT",1165), T4, ECL_SYM("STREAM",799));
   T0 = cl_list(3, ECL_SYM("LET",477), T3, T5);
   goto L5;
L8:;
   T1 = L14expand_next_arg(0);
   T0 = cl_list(3, ECL_SYM("WRITE-OBJECT",1165), T1, ECL_SYM("STREAM",799));
L5:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v2;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G446                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC31__g446(cl_object v1stream, cl_object v2, cl_object v3, cl_object v4orig_args, cl_object v5args)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6;
   cl_object v7;
   cl_object v8;
   v6 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v2) /*  FORMAT-DIRECTIVE-COLONP */;
   v7 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v2) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v8 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v2) /*  FORMAT-DIRECTIVE-PARAMS */;
   L115check_output_layout_mode(ecl_make_fixnum(1));
   if (Null(v8)) { goto L6; }
   T0 = ecl_list1(ecl_make_fixnum(0));
   T1 = ecl_caar(v8);
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T0, ECL_SYM("OFFSET",1279), T1);
L6:;
   {
    cl_object v9;
    cl_object v10;
    cl_object v11;
    value0 = v6;
    if ((value0)!=ECL_NIL) { goto L10; }
    v9 = ecl_symbol_value(ECL_SYM("*PRINT-PRETTY*",55));
    goto L8;
L10:;
    v9 = value0;
    goto L8;
L8:;
    if (Null(v7)) { goto L14; }
    v10 = ecl_symbol_value(ECL_SYM("*PRINT-LEVEL*",51));
    goto L12;
L14:;
    v10 = ECL_NIL;
    goto L12;
L12:;
    if (Null(v7)) { goto L18; }
    v11 = ecl_symbol_value(ECL_SYM("*PRINT-LENGTH*",50));
    goto L16;
L18:;
    v11 = ECL_NIL;
    goto L16;
L16:;
    ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-PRETTY*",55),v9); /*  *PRINT-PRETTY* */
    ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-LEVEL*",51),v10); /*  *PRINT-LEVEL* */
    ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-LENGTH*",50),v11); /*  *PRINT-LENGTH* */
    if (!(v5args==ECL_NIL)) { goto L20; }
    cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L20:;
    if (Null(ecl_symbol_value(VV[25]))) { goto L22; }
    ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L22:;
    {
     cl_object v12;
     v12 = v5args;
     if (ecl_unlikely(!ECL_LISTP(v12))) FEtype_error_list(v12);
     if (Null(v12)) { goto L28; }
     {
      cl_object v13;
      v13 = ECL_CONS_CDR(v12);
      v5args = v13;
      v12 = ECL_CONS_CAR(v12);
     }
L28:;
     T0 = v12;
    }
    si_write_object(T0, v1stream);
    ecl_bds_unwind1(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
   }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5args;
   cl_env_copy->values[0] = v3;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for FORMAT-PRINT-INTEGER                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_format_print_integer(cl_narg narg, cl_object v1stream, cl_object v2number, cl_object v3print_commas_p, cl_object v4print_sign_p, cl_object v5radix, cl_object v6mincol, cl_object v7padchar, cl_object v8commachar, cl_object v9commainterval, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg!=9)) FEwrong_num_arguments_anonym();
 {
TTL:
  ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-BASE*",45),v5radix); /*  *PRINT-BASE* */
  ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-RADIX*",56),ECL_NIL); /*  *PRINT-RADIX* */
  if (!(ECL_FIXNUMP(v2number)||ECL_BIGNUMP(v2number))) { goto L1; }
  {
   cl_object v10text;
   cl_object v11commaed;
   cl_object v12signed;
   T0 = cl_abs(v2number);
   v10text = cl_princ_to_string(T0);
   if (Null(v3print_commas_p)) { goto L5; }
   v11commaed = L32format_add_commas(v10text, v8commachar, v9commainterval);
   goto L4;
L5:;
   v11commaed = v10text;
L4:;
   if (!(ecl_minusp(v2number))) { goto L8; }
   v12signed = cl_concatenate(3, ECL_SYM("STRING",805), _ecl_static_21, v11commaed);
   goto L7;
L8:;
   if (Null(v4print_sign_p)) { goto L10; }
   v12signed = cl_concatenate(3, ECL_SYM("STRING",805), _ecl_static_22, v11commaed);
   goto L7;
L10:;
   v12signed = v11commaed;
L7:;
   value0 = L22format_write_field(v1stream, v12signed, v6mincol, ecl_make_fixnum(1), ecl_make_fixnum(0), v7padchar, ECL_T);
   ecl_bds_unwind1(cl_env_copy);
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
L1:;
  value0 = ecl_princ(v2number,v1stream);
  cl_env_copy->nvalues = 1;
  ecl_bds_unwind1(cl_env_copy);
  ecl_bds_unwind1(cl_env_copy);
  return value0;
 }
}
/*	function definition for FORMAT-ADD-COMMAS                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L32format_add_commas(cl_object v1string, cl_object v2commachar, cl_object v3commainterval)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v4length;
   v4length = ecl_length(v1string);
   {
    cl_object v6;                                 /*  COMMAS          */
    cl_object v7;                                 /*  EXTRA           */
    T0 = ecl_make_integer((v4length)-1);
    value0 = ecl_truncate2(T0,v3commainterval);
    v6 = value0;
    v7 = cl_env_copy->values[1];
    {
     cl_object v8;
     cl_object v9;
     T0 = ecl_plus(ecl_make_fixnum(v4length),v6);
     v8 = cl_make_string(1, T0);
     v9 = ecl_one_plus(v7);
     cl_replace(6, v8, v1string, ECL_SYM("END1",1226), v9, ECL_SYM("END2",1227), v9);
     {
      cl_object v10src;
      cl_object v11dst;
      v10src = v9;
      v11dst = v9;
      goto L11;
L10:;
      ecl_elt_set(v8,ecl_to_size(v11dst),v2commachar);
      T0 = ecl_one_plus(v11dst);
      T1 = ecl_plus(v10src,v3commainterval);
      cl_replace(8, v8, v1string, ECL_SYM("START1",1311), T0, ECL_SYM("START2",1312), v10src, ECL_SYM("END2",1227), T1);
      v10src = ecl_plus(v10src,v3commainterval);
      T0 = ecl_plus(v11dst,v3commainterval);
      v11dst = ecl_plus(T0,ecl_make_fixnum(1));
L11:;
      if (ecl_number_equalp(v10src,ecl_make_fixnum(v4length))) { goto L18; }
      goto L10;
L18:;
     }
     value0 = v8;
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
  }
 }
}
/*	function definition for EXPAND-FORMAT-INTEGER                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L33expand_format_integer(cl_object v1base, cl_object v2colonp, cl_object v3atsignp, cl_object v4params)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((v2colonp)!=ECL_NIL) { goto L3; }
  if ((v3atsignp)!=ECL_NIL) { goto L3; }
  if (Null(v4params)) { goto L1; }
  goto L2;
L3:;
L2:;
  {
   cl_object v5;
   v5 = v4params;
   {
    cl_object v6param_and_offset;
    cl_object v7offset;
    cl_object v8param;
    {
     cl_object v9;
     v9 = v5;
     if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
     if (Null(v9)) { goto L12; }
     {
      cl_object v10;
      v10 = ECL_CONS_CDR(v9);
      v5 = v10;
      v9 = ECL_CONS_CAR(v9);
     }
L12:;
     v6param_and_offset = v9;
    }
    v7offset = ecl_car(v6param_and_offset);
    v8param = ecl_cdr(v6param_and_offset);
    if (!(ecl_eql(v8param,VV[17]))) { goto L20; }
    T1 = L14expand_next_arg(1, v7offset);
    T0 = cl_list(3, ECL_SYM("OR",614), T1, ecl_make_fixnum(0));
    goto L7;
L20:;
    if (!(ecl_eql(v8param,VV[18]))) { goto L22; }
    cl_set(VV[28],ECL_NIL);
    T0 = VV[54];
    goto L7;
L22:;
    if (!((v8param)==(ECL_NIL))) { goto L26; }
    T0 = ecl_make_fixnum(0);
    goto L7;
L26:;
    T0 = v8param;
   }
L7:;
   T1 = cl_list(2, VV[69], T0);
   {
    cl_object v6param_and_offset;
    cl_object v7offset;
    cl_object v8param;
    {
     cl_object v9;
     v9 = v5;
     if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
     if (Null(v9)) { goto L34; }
     {
      cl_object v10;
      v10 = ECL_CONS_CDR(v9);
      v5 = v10;
      v9 = ECL_CONS_CAR(v9);
     }
L34:;
     v6param_and_offset = v9;
    }
    v7offset = ecl_car(v6param_and_offset);
    v8param = ecl_cdr(v6param_and_offset);
    if (!(ecl_eql(v8param,VV[17]))) { goto L42; }
    T3 = L14expand_next_arg(1, v7offset);
    T2 = cl_list(3, ECL_SYM("OR",614), T3, CODE_CHAR(32));
    goto L29;
L42:;
    if (!(ecl_eql(v8param,VV[18]))) { goto L44; }
    cl_set(VV[28],ECL_NIL);
    T2 = VV[54];
    goto L29;
L44:;
    if (!((v8param)==(ECL_NIL))) { goto L48; }
    T2 = CODE_CHAR(32);
    goto L29;
L48:;
    T2 = v8param;
   }
L29:;
   T3 = cl_list(2, VV[70], T2);
   {
    cl_object v6param_and_offset;
    cl_object v7offset;
    cl_object v8param;
    {
     cl_object v9;
     v9 = v5;
     if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
     if (Null(v9)) { goto L56; }
     {
      cl_object v10;
      v10 = ECL_CONS_CDR(v9);
      v5 = v10;
      v9 = ECL_CONS_CAR(v9);
     }
L56:;
     v6param_and_offset = v9;
    }
    v7offset = ecl_car(v6param_and_offset);
    v8param = ecl_cdr(v6param_and_offset);
    if (!(ecl_eql(v8param,VV[17]))) { goto L64; }
    T5 = L14expand_next_arg(1, v7offset);
    T4 = cl_list(3, ECL_SYM("OR",614), T5, CODE_CHAR(44));
    goto L51;
L64:;
    if (!(ecl_eql(v8param,VV[18]))) { goto L66; }
    cl_set(VV[28],ECL_NIL);
    T4 = VV[54];
    goto L51;
L66:;
    if (!((v8param)==(ECL_NIL))) { goto L70; }
    T4 = CODE_CHAR(44);
    goto L51;
L70:;
    T4 = v8param;
   }
L51:;
   T5 = cl_list(2, VV[71], T4);
   {
    cl_object v6param_and_offset;
    cl_object v7offset;
    cl_object v8param;
    {
     cl_object v9;
     v9 = v5;
     if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
     if (Null(v9)) { goto L78; }
     {
      cl_object v10;
      v10 = ECL_CONS_CDR(v9);
      v5 = v10;
      v9 = ECL_CONS_CAR(v9);
     }
L78:;
     v6param_and_offset = v9;
    }
    v7offset = ecl_car(v6param_and_offset);
    v8param = ecl_cdr(v6param_and_offset);
    if (!(ecl_eql(v8param,VV[17]))) { goto L86; }
    T7 = L14expand_next_arg(1, v7offset);
    T6 = cl_list(3, ECL_SYM("OR",614), T7, ecl_make_fixnum(3));
    goto L73;
L86:;
    if (!(ecl_eql(v8param,VV[18]))) { goto L88; }
    cl_set(VV[28],ECL_NIL);
    T6 = VV[54];
    goto L73;
L88:;
    if (!((v8param)==(ECL_NIL))) { goto L92; }
    T6 = ecl_make_fixnum(3);
    goto L73;
L92:;
    T6 = v8param;
   }
L73:;
   T7 = cl_list(2, VV[72], T6);
   T8 = cl_list(4, T1, T3, T5, T7);
   if (Null(v5)) { goto L96; }
   T10 = ecl_list1(ecl_make_fixnum(4));
   T11 = ecl_caar(v5);
   T9 = cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T10, ECL_SYM("OFFSET",1279), T11);
   goto L95;
L96:;
   T9 = ECL_NIL;
L95:;
   T10 = L14expand_next_arg(0);
   T11 = cl_list(10, VV[68], ECL_SYM("STREAM",799), T10, v2colonp, v3atsignp, v1base, VV[69], VV[70], VV[71], VV[72]);
   T12 = ecl_list1(T11);
   T13 = ecl_append(T9,T12);
   value0 = cl_listX(3, ECL_SYM("LET",477), T8, T13);
   return value0;
  }
L1:;
  T0 = L14expand_next_arg(0);
  value0 = cl_listX(7, ECL_SYM("WRITE",917), T0, ECL_SYM("STREAM",1313), ECL_SYM("STREAM",799), ECL_SYM("BASE",1201), v1base, VV[73]);
  return value0;
 }
}
/*	local function G501                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC34__g501(cl_object v1, cl_object v2)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   v3 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v1) /*  FORMAT-DIRECTIVE-COLONP */;
   v4 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v1) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v5 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v1) /*  FORMAT-DIRECTIVE-PARAMS */;
   T0 = L33expand_format_integer(ecl_make_fixnum(10), v3, v4, v5);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v2;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G507                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC35__g507(cl_object v1stream, cl_object v2, cl_object v3, cl_object v4orig_args, cl_object v5args)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6;
   cl_object v7;
   cl_object v8;
   v6 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v2) /*  FORMAT-DIRECTIVE-COLONP */;
   v7 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v2) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v8 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v2) /*  FORMAT-DIRECTIVE-PARAMS */;
   if ((v6)!=ECL_NIL) { goto L7; }
   if ((v7)!=ECL_NIL) { goto L7; }
   if (Null(v8)) { goto L5; }
   goto L6;
L7:;
L6:;
   {
    cl_object v9;
    v9 = v8;
    {
     cl_object v10mincol;
     cl_object v11padchar;
     cl_object v12commachar;
     cl_object v13commainterval;
     {
      cl_object v14param_and_offset;
      cl_object v15offset;
      cl_object v16param;
      {
       cl_object v17;
       v17 = v9;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L16; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v9 = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L16:;
       v14param_and_offset = v17;
      }
      v15offset = ecl_car(v14param_and_offset);
      v16param = ecl_cdr(v14param_and_offset);
      if (!(ecl_eql(v16param,VV[17]))) { goto L24; }
      if (!(v5args==ECL_NIL)) { goto L29; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v15offset);
L29:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L31; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L31:;
      {
       cl_object v17;
       v17 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L36; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v5args = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L36:;
       value0 = v17;
      }
      if ((value0)!=ECL_NIL) { goto L27; }
      v10mincol = ecl_make_fixnum(0);
      goto L11;
L27:;
      v10mincol = value0;
      goto L11;
L24:;
      if (!(ecl_eql(v16param,VV[18]))) { goto L42; }
      v10mincol = ecl_make_fixnum(ecl_length(v5args));
      goto L11;
L42:;
      if (!((v16param)==(ECL_NIL))) { goto L44; }
      v10mincol = ecl_make_fixnum(0);
      goto L11;
L44:;
      v10mincol = v16param;
     }
L11:;
     {
      cl_object v14param_and_offset;
      cl_object v15offset;
      cl_object v16param;
      {
       cl_object v17;
       v17 = v9;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L52; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v9 = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L52:;
       v14param_and_offset = v17;
      }
      v15offset = ecl_car(v14param_and_offset);
      v16param = ecl_cdr(v14param_and_offset);
      if (!(ecl_eql(v16param,VV[17]))) { goto L60; }
      if (!(v5args==ECL_NIL)) { goto L65; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v15offset);
L65:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L67; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L67:;
      {
       cl_object v17;
       v17 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L72; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v5args = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L72:;
       value0 = v17;
      }
      if ((value0)!=ECL_NIL) { goto L63; }
      v11padchar = CODE_CHAR(32);
      goto L47;
L63:;
      v11padchar = value0;
      goto L47;
L60:;
      if (!(ecl_eql(v16param,VV[18]))) { goto L78; }
      v11padchar = ecl_make_fixnum(ecl_length(v5args));
      goto L47;
L78:;
      if (!((v16param)==(ECL_NIL))) { goto L80; }
      v11padchar = CODE_CHAR(32);
      goto L47;
L80:;
      v11padchar = v16param;
     }
L47:;
     {
      cl_object v14param_and_offset;
      cl_object v15offset;
      cl_object v16param;
      {
       cl_object v17;
       v17 = v9;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L88; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v9 = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L88:;
       v14param_and_offset = v17;
      }
      v15offset = ecl_car(v14param_and_offset);
      v16param = ecl_cdr(v14param_and_offset);
      if (!(ecl_eql(v16param,VV[17]))) { goto L96; }
      if (!(v5args==ECL_NIL)) { goto L101; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v15offset);
L101:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L103; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L103:;
      {
       cl_object v17;
       v17 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L108; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v5args = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L108:;
       value0 = v17;
      }
      if ((value0)!=ECL_NIL) { goto L99; }
      v12commachar = CODE_CHAR(44);
      goto L83;
L99:;
      v12commachar = value0;
      goto L83;
L96:;
      if (!(ecl_eql(v16param,VV[18]))) { goto L114; }
      v12commachar = ecl_make_fixnum(ecl_length(v5args));
      goto L83;
L114:;
      if (!((v16param)==(ECL_NIL))) { goto L116; }
      v12commachar = CODE_CHAR(44);
      goto L83;
L116:;
      v12commachar = v16param;
     }
L83:;
     {
      cl_object v14param_and_offset;
      cl_object v15offset;
      cl_object v16param;
      {
       cl_object v17;
       v17 = v9;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L124; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v9 = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L124:;
       v14param_and_offset = v17;
      }
      v15offset = ecl_car(v14param_and_offset);
      v16param = ecl_cdr(v14param_and_offset);
      if (!(ecl_eql(v16param,VV[17]))) { goto L132; }
      if (!(v5args==ECL_NIL)) { goto L137; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v15offset);
L137:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L139; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L139:;
      {
       cl_object v17;
       v17 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L144; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v5args = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L144:;
       value0 = v17;
      }
      if ((value0)!=ECL_NIL) { goto L135; }
      v13commainterval = ecl_make_fixnum(3);
      goto L119;
L135:;
      v13commainterval = value0;
      goto L119;
L132:;
      if (!(ecl_eql(v16param,VV[18]))) { goto L150; }
      v13commainterval = ecl_make_fixnum(ecl_length(v5args));
      goto L119;
L150:;
      if (!((v16param)==(ECL_NIL))) { goto L152; }
      v13commainterval = ecl_make_fixnum(3);
      goto L119;
L152:;
      v13commainterval = v16param;
     }
L119:;
     if (Null(v9)) { goto L155; }
     T0 = ecl_list1(ecl_make_fixnum(4));
     T1 = ecl_caar(v9);
     cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T0, ECL_SYM("OFFSET",1279), T1);
L155:;
     if (!(v5args==ECL_NIL)) { goto L157; }
     cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L157:;
     if (Null(ecl_symbol_value(VV[25]))) { goto L159; }
     ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L159:;
     {
      cl_object v14;
      v14 = v5args;
      if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
      if (Null(v14)) { goto L165; }
      {
       cl_object v15;
       v15 = ECL_CONS_CDR(v14);
       v5args = v15;
       v14 = ECL_CONS_CAR(v14);
      }
L165:;
      T0 = v14;
     }
     si_format_print_integer(9, v1stream, T0, v6, v7, ecl_make_fixnum(10), v10mincol, v11padchar, v12commachar, v13commainterval);
     goto L4;
    }
   }
L5:;
   if (!(v5args==ECL_NIL)) { goto L171; }
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L171:;
   if (Null(ecl_symbol_value(VV[25]))) { goto L173; }
   ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L173:;
   {
    cl_object v14;
    v14 = v5args;
    if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
    if (Null(v14)) { goto L179; }
    {
     cl_object v15;
     v15 = ECL_CONS_CDR(v14);
     v5args = v15;
     v14 = ECL_CONS_CAR(v14);
    }
L179:;
    T0 = v14;
   }
   cl_write(9, T0, ECL_SYM("STREAM",1313), v1stream, ECL_SYM("BASE",1201), ecl_make_fixnum(10), ECL_SYM("RADIX",1295), ECL_NIL, ECL_SYM("ESCAPE",1230), ECL_NIL);
L4:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5args;
   cl_env_copy->values[0] = v3;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G542                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC36__g542(cl_object v1, cl_object v2)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   v3 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v1) /*  FORMAT-DIRECTIVE-COLONP */;
   v4 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v1) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v5 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v1) /*  FORMAT-DIRECTIVE-PARAMS */;
   T0 = L33expand_format_integer(ecl_make_fixnum(2), v3, v4, v5);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v2;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G548                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC37__g548(cl_object v1stream, cl_object v2, cl_object v3, cl_object v4orig_args, cl_object v5args)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6;
   cl_object v7;
   cl_object v8;
   v6 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v2) /*  FORMAT-DIRECTIVE-COLONP */;
   v7 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v2) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v8 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v2) /*  FORMAT-DIRECTIVE-PARAMS */;
   if ((v6)!=ECL_NIL) { goto L7; }
   if ((v7)!=ECL_NIL) { goto L7; }
   if (Null(v8)) { goto L5; }
   goto L6;
L7:;
L6:;
   {
    cl_object v9;
    v9 = v8;
    {
     cl_object v10mincol;
     cl_object v11padchar;
     cl_object v12commachar;
     cl_object v13commainterval;
     {
      cl_object v14param_and_offset;
      cl_object v15offset;
      cl_object v16param;
      {
       cl_object v17;
       v17 = v9;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L16; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v9 = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L16:;
       v14param_and_offset = v17;
      }
      v15offset = ecl_car(v14param_and_offset);
      v16param = ecl_cdr(v14param_and_offset);
      if (!(ecl_eql(v16param,VV[17]))) { goto L24; }
      if (!(v5args==ECL_NIL)) { goto L29; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v15offset);
L29:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L31; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L31:;
      {
       cl_object v17;
       v17 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L36; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v5args = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L36:;
       value0 = v17;
      }
      if ((value0)!=ECL_NIL) { goto L27; }
      v10mincol = ecl_make_fixnum(0);
      goto L11;
L27:;
      v10mincol = value0;
      goto L11;
L24:;
      if (!(ecl_eql(v16param,VV[18]))) { goto L42; }
      v10mincol = ecl_make_fixnum(ecl_length(v5args));
      goto L11;
L42:;
      if (!((v16param)==(ECL_NIL))) { goto L44; }
      v10mincol = ecl_make_fixnum(0);
      goto L11;
L44:;
      v10mincol = v16param;
     }
L11:;
     {
      cl_object v14param_and_offset;
      cl_object v15offset;
      cl_object v16param;
      {
       cl_object v17;
       v17 = v9;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L52; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v9 = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L52:;
       v14param_and_offset = v17;
      }
      v15offset = ecl_car(v14param_and_offset);
      v16param = ecl_cdr(v14param_and_offset);
      if (!(ecl_eql(v16param,VV[17]))) { goto L60; }
      if (!(v5args==ECL_NIL)) { goto L65; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v15offset);
L65:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L67; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L67:;
      {
       cl_object v17;
       v17 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L72; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v5args = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L72:;
       value0 = v17;
      }
      if ((value0)!=ECL_NIL) { goto L63; }
      v11padchar = CODE_CHAR(32);
      goto L47;
L63:;
      v11padchar = value0;
      goto L47;
L60:;
      if (!(ecl_eql(v16param,VV[18]))) { goto L78; }
      v11padchar = ecl_make_fixnum(ecl_length(v5args));
      goto L47;
L78:;
      if (!((v16param)==(ECL_NIL))) { goto L80; }
      v11padchar = CODE_CHAR(32);
      goto L47;
L80:;
      v11padchar = v16param;
     }
L47:;
     {
      cl_object v14param_and_offset;
      cl_object v15offset;
      cl_object v16param;
      {
       cl_object v17;
       v17 = v9;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L88; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v9 = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L88:;
       v14param_and_offset = v17;
      }
      v15offset = ecl_car(v14param_and_offset);
      v16param = ecl_cdr(v14param_and_offset);
      if (!(ecl_eql(v16param,VV[17]))) { goto L96; }
      if (!(v5args==ECL_NIL)) { goto L101; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v15offset);
L101:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L103; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L103:;
      {
       cl_object v17;
       v17 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L108; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v5args = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L108:;
       value0 = v17;
      }
      if ((value0)!=ECL_NIL) { goto L99; }
      v12commachar = CODE_CHAR(44);
      goto L83;
L99:;
      v12commachar = value0;
      goto L83;
L96:;
      if (!(ecl_eql(v16param,VV[18]))) { goto L114; }
      v12commachar = ecl_make_fixnum(ecl_length(v5args));
      goto L83;
L114:;
      if (!((v16param)==(ECL_NIL))) { goto L116; }
      v12commachar = CODE_CHAR(44);
      goto L83;
L116:;
      v12commachar = v16param;
     }
L83:;
     {
      cl_object v14param_and_offset;
      cl_object v15offset;
      cl_object v16param;
      {
       cl_object v17;
       v17 = v9;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L124; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v9 = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L124:;
       v14param_and_offset = v17;
      }
      v15offset = ecl_car(v14param_and_offset);
      v16param = ecl_cdr(v14param_and_offset);
      if (!(ecl_eql(v16param,VV[17]))) { goto L132; }
      if (!(v5args==ECL_NIL)) { goto L137; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v15offset);
L137:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L139; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L139:;
      {
       cl_object v17;
       v17 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L144; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v5args = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L144:;
       value0 = v17;
      }
      if ((value0)!=ECL_NIL) { goto L135; }
      v13commainterval = ecl_make_fixnum(3);
      goto L119;
L135:;
      v13commainterval = value0;
      goto L119;
L132:;
      if (!(ecl_eql(v16param,VV[18]))) { goto L150; }
      v13commainterval = ecl_make_fixnum(ecl_length(v5args));
      goto L119;
L150:;
      if (!((v16param)==(ECL_NIL))) { goto L152; }
      v13commainterval = ecl_make_fixnum(3);
      goto L119;
L152:;
      v13commainterval = v16param;
     }
L119:;
     if (Null(v9)) { goto L155; }
     T0 = ecl_list1(ecl_make_fixnum(4));
     T1 = ecl_caar(v9);
     cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T0, ECL_SYM("OFFSET",1279), T1);
L155:;
     if (!(v5args==ECL_NIL)) { goto L157; }
     cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L157:;
     if (Null(ecl_symbol_value(VV[25]))) { goto L159; }
     ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L159:;
     {
      cl_object v14;
      v14 = v5args;
      if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
      if (Null(v14)) { goto L165; }
      {
       cl_object v15;
       v15 = ECL_CONS_CDR(v14);
       v5args = v15;
       v14 = ECL_CONS_CAR(v14);
      }
L165:;
      T0 = v14;
     }
     si_format_print_integer(9, v1stream, T0, v6, v7, ecl_make_fixnum(2), v10mincol, v11padchar, v12commachar, v13commainterval);
     goto L4;
    }
   }
L5:;
   if (!(v5args==ECL_NIL)) { goto L171; }
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L171:;
   if (Null(ecl_symbol_value(VV[25]))) { goto L173; }
   ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L173:;
   {
    cl_object v14;
    v14 = v5args;
    if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
    if (Null(v14)) { goto L179; }
    {
     cl_object v15;
     v15 = ECL_CONS_CDR(v14);
     v5args = v15;
     v14 = ECL_CONS_CAR(v14);
    }
L179:;
    T0 = v14;
   }
   cl_write(9, T0, ECL_SYM("STREAM",1313), v1stream, ECL_SYM("BASE",1201), ecl_make_fixnum(2), ECL_SYM("RADIX",1295), ECL_NIL, ECL_SYM("ESCAPE",1230), ECL_NIL);
L4:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5args;
   cl_env_copy->values[0] = v3;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G583                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC38__g583(cl_object v1, cl_object v2)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   v3 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v1) /*  FORMAT-DIRECTIVE-COLONP */;
   v4 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v1) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v5 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v1) /*  FORMAT-DIRECTIVE-PARAMS */;
   T0 = L33expand_format_integer(ecl_make_fixnum(8), v3, v4, v5);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v2;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G589                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC39__g589(cl_object v1stream, cl_object v2, cl_object v3, cl_object v4orig_args, cl_object v5args)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6;
   cl_object v7;
   cl_object v8;
   v6 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v2) /*  FORMAT-DIRECTIVE-COLONP */;
   v7 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v2) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v8 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v2) /*  FORMAT-DIRECTIVE-PARAMS */;
   if ((v6)!=ECL_NIL) { goto L7; }
   if ((v7)!=ECL_NIL) { goto L7; }
   if (Null(v8)) { goto L5; }
   goto L6;
L7:;
L6:;
   {
    cl_object v9;
    v9 = v8;
    {
     cl_object v10mincol;
     cl_object v11padchar;
     cl_object v12commachar;
     cl_object v13commainterval;
     {
      cl_object v14param_and_offset;
      cl_object v15offset;
      cl_object v16param;
      {
       cl_object v17;
       v17 = v9;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L16; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v9 = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L16:;
       v14param_and_offset = v17;
      }
      v15offset = ecl_car(v14param_and_offset);
      v16param = ecl_cdr(v14param_and_offset);
      if (!(ecl_eql(v16param,VV[17]))) { goto L24; }
      if (!(v5args==ECL_NIL)) { goto L29; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v15offset);
L29:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L31; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L31:;
      {
       cl_object v17;
       v17 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L36; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v5args = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L36:;
       value0 = v17;
      }
      if ((value0)!=ECL_NIL) { goto L27; }
      v10mincol = ecl_make_fixnum(0);
      goto L11;
L27:;
      v10mincol = value0;
      goto L11;
L24:;
      if (!(ecl_eql(v16param,VV[18]))) { goto L42; }
      v10mincol = ecl_make_fixnum(ecl_length(v5args));
      goto L11;
L42:;
      if (!((v16param)==(ECL_NIL))) { goto L44; }
      v10mincol = ecl_make_fixnum(0);
      goto L11;
L44:;
      v10mincol = v16param;
     }
L11:;
     {
      cl_object v14param_and_offset;
      cl_object v15offset;
      cl_object v16param;
      {
       cl_object v17;
       v17 = v9;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L52; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v9 = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L52:;
       v14param_and_offset = v17;
      }
      v15offset = ecl_car(v14param_and_offset);
      v16param = ecl_cdr(v14param_and_offset);
      if (!(ecl_eql(v16param,VV[17]))) { goto L60; }
      if (!(v5args==ECL_NIL)) { goto L65; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v15offset);
L65:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L67; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L67:;
      {
       cl_object v17;
       v17 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L72; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v5args = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L72:;
       value0 = v17;
      }
      if ((value0)!=ECL_NIL) { goto L63; }
      v11padchar = CODE_CHAR(32);
      goto L47;
L63:;
      v11padchar = value0;
      goto L47;
L60:;
      if (!(ecl_eql(v16param,VV[18]))) { goto L78; }
      v11padchar = ecl_make_fixnum(ecl_length(v5args));
      goto L47;
L78:;
      if (!((v16param)==(ECL_NIL))) { goto L80; }
      v11padchar = CODE_CHAR(32);
      goto L47;
L80:;
      v11padchar = v16param;
     }
L47:;
     {
      cl_object v14param_and_offset;
      cl_object v15offset;
      cl_object v16param;
      {
       cl_object v17;
       v17 = v9;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L88; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v9 = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L88:;
       v14param_and_offset = v17;
      }
      v15offset = ecl_car(v14param_and_offset);
      v16param = ecl_cdr(v14param_and_offset);
      if (!(ecl_eql(v16param,VV[17]))) { goto L96; }
      if (!(v5args==ECL_NIL)) { goto L101; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v15offset);
L101:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L103; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L103:;
      {
       cl_object v17;
       v17 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L108; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v5args = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L108:;
       value0 = v17;
      }
      if ((value0)!=ECL_NIL) { goto L99; }
      v12commachar = CODE_CHAR(44);
      goto L83;
L99:;
      v12commachar = value0;
      goto L83;
L96:;
      if (!(ecl_eql(v16param,VV[18]))) { goto L114; }
      v12commachar = ecl_make_fixnum(ecl_length(v5args));
      goto L83;
L114:;
      if (!((v16param)==(ECL_NIL))) { goto L116; }
      v12commachar = CODE_CHAR(44);
      goto L83;
L116:;
      v12commachar = v16param;
     }
L83:;
     {
      cl_object v14param_and_offset;
      cl_object v15offset;
      cl_object v16param;
      {
       cl_object v17;
       v17 = v9;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L124; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v9 = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L124:;
       v14param_and_offset = v17;
      }
      v15offset = ecl_car(v14param_and_offset);
      v16param = ecl_cdr(v14param_and_offset);
      if (!(ecl_eql(v16param,VV[17]))) { goto L132; }
      if (!(v5args==ECL_NIL)) { goto L137; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v15offset);
L137:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L139; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L139:;
      {
       cl_object v17;
       v17 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L144; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v5args = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L144:;
       value0 = v17;
      }
      if ((value0)!=ECL_NIL) { goto L135; }
      v13commainterval = ecl_make_fixnum(3);
      goto L119;
L135:;
      v13commainterval = value0;
      goto L119;
L132:;
      if (!(ecl_eql(v16param,VV[18]))) { goto L150; }
      v13commainterval = ecl_make_fixnum(ecl_length(v5args));
      goto L119;
L150:;
      if (!((v16param)==(ECL_NIL))) { goto L152; }
      v13commainterval = ecl_make_fixnum(3);
      goto L119;
L152:;
      v13commainterval = v16param;
     }
L119:;
     if (Null(v9)) { goto L155; }
     T0 = ecl_list1(ecl_make_fixnum(4));
     T1 = ecl_caar(v9);
     cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T0, ECL_SYM("OFFSET",1279), T1);
L155:;
     if (!(v5args==ECL_NIL)) { goto L157; }
     cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L157:;
     if (Null(ecl_symbol_value(VV[25]))) { goto L159; }
     ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L159:;
     {
      cl_object v14;
      v14 = v5args;
      if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
      if (Null(v14)) { goto L165; }
      {
       cl_object v15;
       v15 = ECL_CONS_CDR(v14);
       v5args = v15;
       v14 = ECL_CONS_CAR(v14);
      }
L165:;
      T0 = v14;
     }
     si_format_print_integer(9, v1stream, T0, v6, v7, ecl_make_fixnum(8), v10mincol, v11padchar, v12commachar, v13commainterval);
     goto L4;
    }
   }
L5:;
   if (!(v5args==ECL_NIL)) { goto L171; }
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L171:;
   if (Null(ecl_symbol_value(VV[25]))) { goto L173; }
   ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L173:;
   {
    cl_object v14;
    v14 = v5args;
    if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
    if (Null(v14)) { goto L179; }
    {
     cl_object v15;
     v15 = ECL_CONS_CDR(v14);
     v5args = v15;
     v14 = ECL_CONS_CAR(v14);
    }
L179:;
    T0 = v14;
   }
   cl_write(9, T0, ECL_SYM("STREAM",1313), v1stream, ECL_SYM("BASE",1201), ecl_make_fixnum(8), ECL_SYM("RADIX",1295), ECL_NIL, ECL_SYM("ESCAPE",1230), ECL_NIL);
L4:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5args;
   cl_env_copy->values[0] = v3;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G624                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC40__g624(cl_object v1, cl_object v2)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   v3 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v1) /*  FORMAT-DIRECTIVE-COLONP */;
   v4 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v1) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v5 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v1) /*  FORMAT-DIRECTIVE-PARAMS */;
   T0 = L33expand_format_integer(ecl_make_fixnum(16), v3, v4, v5);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v2;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G630                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC41__g630(cl_object v1stream, cl_object v2, cl_object v3, cl_object v4orig_args, cl_object v5args)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6;
   cl_object v7;
   cl_object v8;
   v6 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v2) /*  FORMAT-DIRECTIVE-COLONP */;
   v7 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v2) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v8 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v2) /*  FORMAT-DIRECTIVE-PARAMS */;
   if ((v6)!=ECL_NIL) { goto L7; }
   if ((v7)!=ECL_NIL) { goto L7; }
   if (Null(v8)) { goto L5; }
   goto L6;
L7:;
L6:;
   {
    cl_object v9;
    v9 = v8;
    {
     cl_object v10mincol;
     cl_object v11padchar;
     cl_object v12commachar;
     cl_object v13commainterval;
     {
      cl_object v14param_and_offset;
      cl_object v15offset;
      cl_object v16param;
      {
       cl_object v17;
       v17 = v9;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L16; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v9 = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L16:;
       v14param_and_offset = v17;
      }
      v15offset = ecl_car(v14param_and_offset);
      v16param = ecl_cdr(v14param_and_offset);
      if (!(ecl_eql(v16param,VV[17]))) { goto L24; }
      if (!(v5args==ECL_NIL)) { goto L29; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v15offset);
L29:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L31; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L31:;
      {
       cl_object v17;
       v17 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L36; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v5args = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L36:;
       value0 = v17;
      }
      if ((value0)!=ECL_NIL) { goto L27; }
      v10mincol = ecl_make_fixnum(0);
      goto L11;
L27:;
      v10mincol = value0;
      goto L11;
L24:;
      if (!(ecl_eql(v16param,VV[18]))) { goto L42; }
      v10mincol = ecl_make_fixnum(ecl_length(v5args));
      goto L11;
L42:;
      if (!((v16param)==(ECL_NIL))) { goto L44; }
      v10mincol = ecl_make_fixnum(0);
      goto L11;
L44:;
      v10mincol = v16param;
     }
L11:;
     {
      cl_object v14param_and_offset;
      cl_object v15offset;
      cl_object v16param;
      {
       cl_object v17;
       v17 = v9;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L52; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v9 = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L52:;
       v14param_and_offset = v17;
      }
      v15offset = ecl_car(v14param_and_offset);
      v16param = ecl_cdr(v14param_and_offset);
      if (!(ecl_eql(v16param,VV[17]))) { goto L60; }
      if (!(v5args==ECL_NIL)) { goto L65; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v15offset);
L65:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L67; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L67:;
      {
       cl_object v17;
       v17 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L72; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v5args = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L72:;
       value0 = v17;
      }
      if ((value0)!=ECL_NIL) { goto L63; }
      v11padchar = CODE_CHAR(32);
      goto L47;
L63:;
      v11padchar = value0;
      goto L47;
L60:;
      if (!(ecl_eql(v16param,VV[18]))) { goto L78; }
      v11padchar = ecl_make_fixnum(ecl_length(v5args));
      goto L47;
L78:;
      if (!((v16param)==(ECL_NIL))) { goto L80; }
      v11padchar = CODE_CHAR(32);
      goto L47;
L80:;
      v11padchar = v16param;
     }
L47:;
     {
      cl_object v14param_and_offset;
      cl_object v15offset;
      cl_object v16param;
      {
       cl_object v17;
       v17 = v9;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L88; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v9 = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L88:;
       v14param_and_offset = v17;
      }
      v15offset = ecl_car(v14param_and_offset);
      v16param = ecl_cdr(v14param_and_offset);
      if (!(ecl_eql(v16param,VV[17]))) { goto L96; }
      if (!(v5args==ECL_NIL)) { goto L101; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v15offset);
L101:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L103; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L103:;
      {
       cl_object v17;
       v17 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L108; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v5args = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L108:;
       value0 = v17;
      }
      if ((value0)!=ECL_NIL) { goto L99; }
      v12commachar = CODE_CHAR(44);
      goto L83;
L99:;
      v12commachar = value0;
      goto L83;
L96:;
      if (!(ecl_eql(v16param,VV[18]))) { goto L114; }
      v12commachar = ecl_make_fixnum(ecl_length(v5args));
      goto L83;
L114:;
      if (!((v16param)==(ECL_NIL))) { goto L116; }
      v12commachar = CODE_CHAR(44);
      goto L83;
L116:;
      v12commachar = v16param;
     }
L83:;
     {
      cl_object v14param_and_offset;
      cl_object v15offset;
      cl_object v16param;
      {
       cl_object v17;
       v17 = v9;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L124; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v9 = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L124:;
       v14param_and_offset = v17;
      }
      v15offset = ecl_car(v14param_and_offset);
      v16param = ecl_cdr(v14param_and_offset);
      if (!(ecl_eql(v16param,VV[17]))) { goto L132; }
      if (!(v5args==ECL_NIL)) { goto L137; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v15offset);
L137:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L139; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L139:;
      {
       cl_object v17;
       v17 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L144; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v5args = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L144:;
       value0 = v17;
      }
      if ((value0)!=ECL_NIL) { goto L135; }
      v13commainterval = ecl_make_fixnum(3);
      goto L119;
L135:;
      v13commainterval = value0;
      goto L119;
L132:;
      if (!(ecl_eql(v16param,VV[18]))) { goto L150; }
      v13commainterval = ecl_make_fixnum(ecl_length(v5args));
      goto L119;
L150:;
      if (!((v16param)==(ECL_NIL))) { goto L152; }
      v13commainterval = ecl_make_fixnum(3);
      goto L119;
L152:;
      v13commainterval = v16param;
     }
L119:;
     if (Null(v9)) { goto L155; }
     T0 = ecl_list1(ecl_make_fixnum(4));
     T1 = ecl_caar(v9);
     cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T0, ECL_SYM("OFFSET",1279), T1);
L155:;
     if (!(v5args==ECL_NIL)) { goto L157; }
     cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L157:;
     if (Null(ecl_symbol_value(VV[25]))) { goto L159; }
     ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L159:;
     {
      cl_object v14;
      v14 = v5args;
      if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
      if (Null(v14)) { goto L165; }
      {
       cl_object v15;
       v15 = ECL_CONS_CDR(v14);
       v5args = v15;
       v14 = ECL_CONS_CAR(v14);
      }
L165:;
      T0 = v14;
     }
     si_format_print_integer(9, v1stream, T0, v6, v7, ecl_make_fixnum(16), v10mincol, v11padchar, v12commachar, v13commainterval);
     goto L4;
    }
   }
L5:;
   if (!(v5args==ECL_NIL)) { goto L171; }
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L171:;
   if (Null(ecl_symbol_value(VV[25]))) { goto L173; }
   ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L173:;
   {
    cl_object v14;
    v14 = v5args;
    if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
    if (Null(v14)) { goto L179; }
    {
     cl_object v15;
     v15 = ECL_CONS_CDR(v14);
     v5args = v15;
     v14 = ECL_CONS_CAR(v14);
    }
L179:;
    T0 = v14;
   }
   cl_write(9, T0, ECL_SYM("STREAM",1313), v1stream, ECL_SYM("BASE",1201), ecl_make_fixnum(16), ECL_SYM("RADIX",1295), ECL_NIL, ECL_SYM("ESCAPE",1230), ECL_NIL);
L4:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5args;
   cl_env_copy->values[0] = v3;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G665                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC42__g665(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   v3 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v1) /*  FORMAT-DIRECTIVE-COLONP */;
   v4 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v1) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v5 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v1) /*  FORMAT-DIRECTIVE-PARAMS */;
   {
    cl_object v6;
    v6 = v5;
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L11; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L11:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L19; }
     T2 = L14expand_next_arg(1, v8offset);
     T1 = cl_list(3, ECL_SYM("OR",614), T2, ECL_NIL);
     goto L6;
L19:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L21; }
     cl_set(VV[28],ECL_NIL);
     T1 = VV[54];
     goto L6;
L21:;
     if (!((v9param)==(ECL_NIL))) { goto L25; }
     T1 = ECL_NIL;
     goto L6;
L25:;
     T1 = v9param;
    }
L6:;
    T2 = cl_list(2, VV[75], T1);
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L33; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L33:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L41; }
     T4 = L14expand_next_arg(1, v8offset);
     T3 = cl_list(3, ECL_SYM("OR",614), T4, ecl_make_fixnum(0));
     goto L28;
L41:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L43; }
     cl_set(VV[28],ECL_NIL);
     T3 = VV[54];
     goto L28;
L43:;
     if (!((v9param)==(ECL_NIL))) { goto L47; }
     T3 = ecl_make_fixnum(0);
     goto L28;
L47:;
     T3 = v9param;
    }
L28:;
    T4 = cl_list(2, VV[76], T3);
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L55; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L55:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L63; }
     T6 = L14expand_next_arg(1, v8offset);
     T5 = cl_list(3, ECL_SYM("OR",614), T6, CODE_CHAR(32));
     goto L50;
L63:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L65; }
     cl_set(VV[28],ECL_NIL);
     T5 = VV[54];
     goto L50;
L65:;
     if (!((v9param)==(ECL_NIL))) { goto L69; }
     T5 = CODE_CHAR(32);
     goto L50;
L69:;
     T5 = v9param;
    }
L50:;
    T6 = cl_list(2, VV[77], T5);
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L77; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L77:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L85; }
     T8 = L14expand_next_arg(1, v8offset);
     T7 = cl_list(3, ECL_SYM("OR",614), T8, CODE_CHAR(44));
     goto L72;
L85:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L87; }
     cl_set(VV[28],ECL_NIL);
     T7 = VV[54];
     goto L72;
L87:;
     if (!((v9param)==(ECL_NIL))) { goto L91; }
     T7 = CODE_CHAR(44);
     goto L72;
L91:;
     T7 = v9param;
    }
L72:;
    T8 = cl_list(2, VV[78], T7);
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L99; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L99:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L107; }
     T10 = L14expand_next_arg(1, v8offset);
     T9 = cl_list(3, ECL_SYM("OR",614), T10, ecl_make_fixnum(3));
     goto L94;
L107:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L109; }
     cl_set(VV[28],ECL_NIL);
     T9 = VV[54];
     goto L94;
L109:;
     if (!((v9param)==(ECL_NIL))) { goto L113; }
     T9 = ecl_make_fixnum(3);
     goto L94;
L113:;
     T9 = v9param;
    }
L94:;
    T10 = cl_list(2, VV[79], T9);
    T11 = cl_list(5, T2, T4, T6, T8, T10);
    if (Null(v6)) { goto L117; }
    T13 = ecl_list1(ecl_make_fixnum(5));
    T14 = ecl_caar(v6);
    T12 = cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T13, ECL_SYM("OFFSET",1279), T14);
    goto L116;
L117:;
    T12 = ECL_NIL;
L116:;
    {
     cl_object v7n_arg;
     v7n_arg = cl_gensym(0);
     T14 = L14expand_next_arg(0);
     T15 = cl_list(2, v7n_arg, T14);
     T16 = ecl_list1(T15);
     T17 = cl_list(10, VV[68], ECL_SYM("STREAM",799), v7n_arg, v3, v4, VV[75], VV[76], VV[77], VV[78], VV[79]);
     if (Null(v4)) { goto L122; }
     if (Null(v3)) { goto L124; }
     T18 = cl_list(3, VV[80], ECL_SYM("STREAM",799), v7n_arg);
     goto L121;
L124:;
     T18 = cl_list(3, VV[81], ECL_SYM("STREAM",799), v7n_arg);
     goto L121;
L122:;
     if (Null(v3)) { goto L126; }
     T18 = cl_list(3, VV[82], ECL_SYM("STREAM",799), v7n_arg);
     goto L121;
L126:;
     T18 = cl_list(3, VV[83], ECL_SYM("STREAM",799), v7n_arg);
L121:;
     T19 = cl_list(4, ECL_SYM("IF",946), VV[75], T17, T18);
     T13 = cl_list(3, ECL_SYM("LET",477), T16, T19);
    }
    T14 = ecl_list1(T13);
    T15 = ecl_append(T12,T14);
    T0 = cl_listX(3, ECL_SYM("LET",477), T11, T15);
   }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v2;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G707                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC43__g707(cl_object v1stream, cl_object v2, cl_object v3, cl_object v4orig_args, cl_object v5args)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6;
   cl_object v7;
   cl_object v8;
   v6 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v2) /*  FORMAT-DIRECTIVE-COLONP */;
   v7 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v2) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v8 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v2) /*  FORMAT-DIRECTIVE-PARAMS */;
   {
    cl_object v9;
    v9 = v8;
    {
     cl_object v10base;
     cl_object v11mincol;
     cl_object v12padchar;
     cl_object v13commachar;
     cl_object v14commainterval;
     {
      cl_object v15param_and_offset;
      cl_object v16offset;
      cl_object v17param;
      {
       cl_object v18;
       v18 = v9;
       if (ecl_unlikely(!ECL_LISTP(v18))) FEtype_error_list(v18);
       if (Null(v18)) { goto L11; }
       {
        cl_object v19;
        v19 = ECL_CONS_CDR(v18);
        v9 = v19;
        v18 = ECL_CONS_CAR(v18);
       }
L11:;
       v15param_and_offset = v18;
      }
      v16offset = ecl_car(v15param_and_offset);
      v17param = ecl_cdr(v15param_and_offset);
      if (!(ecl_eql(v17param,VV[17]))) { goto L19; }
      if (!(v5args==ECL_NIL)) { goto L24; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v16offset);
L24:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L26; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L26:;
      {
       cl_object v18;
       v18 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v18))) FEtype_error_list(v18);
       if (Null(v18)) { goto L31; }
       {
        cl_object v19;
        v19 = ECL_CONS_CDR(v18);
        v5args = v19;
        v18 = ECL_CONS_CAR(v18);
       }
L31:;
       value0 = v18;
      }
      if ((value0)!=ECL_NIL) { goto L22; }
      v10base = ECL_NIL;
      goto L6;
L22:;
      v10base = value0;
      goto L6;
L19:;
      if (!(ecl_eql(v17param,VV[18]))) { goto L37; }
      v10base = ecl_make_fixnum(ecl_length(v5args));
      goto L6;
L37:;
      if (!((v17param)==(ECL_NIL))) { goto L39; }
      v10base = ECL_NIL;
      goto L6;
L39:;
      v10base = v17param;
     }
L6:;
     {
      cl_object v15param_and_offset;
      cl_object v16offset;
      cl_object v17param;
      {
       cl_object v18;
       v18 = v9;
       if (ecl_unlikely(!ECL_LISTP(v18))) FEtype_error_list(v18);
       if (Null(v18)) { goto L47; }
       {
        cl_object v19;
        v19 = ECL_CONS_CDR(v18);
        v9 = v19;
        v18 = ECL_CONS_CAR(v18);
       }
L47:;
       v15param_and_offset = v18;
      }
      v16offset = ecl_car(v15param_and_offset);
      v17param = ecl_cdr(v15param_and_offset);
      if (!(ecl_eql(v17param,VV[17]))) { goto L55; }
      if (!(v5args==ECL_NIL)) { goto L60; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v16offset);
L60:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L62; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L62:;
      {
       cl_object v18;
       v18 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v18))) FEtype_error_list(v18);
       if (Null(v18)) { goto L67; }
       {
        cl_object v19;
        v19 = ECL_CONS_CDR(v18);
        v5args = v19;
        v18 = ECL_CONS_CAR(v18);
       }
L67:;
       value0 = v18;
      }
      if ((value0)!=ECL_NIL) { goto L58; }
      v11mincol = ecl_make_fixnum(0);
      goto L42;
L58:;
      v11mincol = value0;
      goto L42;
L55:;
      if (!(ecl_eql(v17param,VV[18]))) { goto L73; }
      v11mincol = ecl_make_fixnum(ecl_length(v5args));
      goto L42;
L73:;
      if (!((v17param)==(ECL_NIL))) { goto L75; }
      v11mincol = ecl_make_fixnum(0);
      goto L42;
L75:;
      v11mincol = v17param;
     }
L42:;
     {
      cl_object v15param_and_offset;
      cl_object v16offset;
      cl_object v17param;
      {
       cl_object v18;
       v18 = v9;
       if (ecl_unlikely(!ECL_LISTP(v18))) FEtype_error_list(v18);
       if (Null(v18)) { goto L83; }
       {
        cl_object v19;
        v19 = ECL_CONS_CDR(v18);
        v9 = v19;
        v18 = ECL_CONS_CAR(v18);
       }
L83:;
       v15param_and_offset = v18;
      }
      v16offset = ecl_car(v15param_and_offset);
      v17param = ecl_cdr(v15param_and_offset);
      if (!(ecl_eql(v17param,VV[17]))) { goto L91; }
      if (!(v5args==ECL_NIL)) { goto L96; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v16offset);
L96:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L98; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L98:;
      {
       cl_object v18;
       v18 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v18))) FEtype_error_list(v18);
       if (Null(v18)) { goto L103; }
       {
        cl_object v19;
        v19 = ECL_CONS_CDR(v18);
        v5args = v19;
        v18 = ECL_CONS_CAR(v18);
       }
L103:;
       value0 = v18;
      }
      if ((value0)!=ECL_NIL) { goto L94; }
      v12padchar = CODE_CHAR(32);
      goto L78;
L94:;
      v12padchar = value0;
      goto L78;
L91:;
      if (!(ecl_eql(v17param,VV[18]))) { goto L109; }
      v12padchar = ecl_make_fixnum(ecl_length(v5args));
      goto L78;
L109:;
      if (!((v17param)==(ECL_NIL))) { goto L111; }
      v12padchar = CODE_CHAR(32);
      goto L78;
L111:;
      v12padchar = v17param;
     }
L78:;
     {
      cl_object v15param_and_offset;
      cl_object v16offset;
      cl_object v17param;
      {
       cl_object v18;
       v18 = v9;
       if (ecl_unlikely(!ECL_LISTP(v18))) FEtype_error_list(v18);
       if (Null(v18)) { goto L119; }
       {
        cl_object v19;
        v19 = ECL_CONS_CDR(v18);
        v9 = v19;
        v18 = ECL_CONS_CAR(v18);
       }
L119:;
       v15param_and_offset = v18;
      }
      v16offset = ecl_car(v15param_and_offset);
      v17param = ecl_cdr(v15param_and_offset);
      if (!(ecl_eql(v17param,VV[17]))) { goto L127; }
      if (!(v5args==ECL_NIL)) { goto L132; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v16offset);
L132:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L134; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L134:;
      {
       cl_object v18;
       v18 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v18))) FEtype_error_list(v18);
       if (Null(v18)) { goto L139; }
       {
        cl_object v19;
        v19 = ECL_CONS_CDR(v18);
        v5args = v19;
        v18 = ECL_CONS_CAR(v18);
       }
L139:;
       value0 = v18;
      }
      if ((value0)!=ECL_NIL) { goto L130; }
      v13commachar = CODE_CHAR(44);
      goto L114;
L130:;
      v13commachar = value0;
      goto L114;
L127:;
      if (!(ecl_eql(v17param,VV[18]))) { goto L145; }
      v13commachar = ecl_make_fixnum(ecl_length(v5args));
      goto L114;
L145:;
      if (!((v17param)==(ECL_NIL))) { goto L147; }
      v13commachar = CODE_CHAR(44);
      goto L114;
L147:;
      v13commachar = v17param;
     }
L114:;
     {
      cl_object v15param_and_offset;
      cl_object v16offset;
      cl_object v17param;
      {
       cl_object v18;
       v18 = v9;
       if (ecl_unlikely(!ECL_LISTP(v18))) FEtype_error_list(v18);
       if (Null(v18)) { goto L155; }
       {
        cl_object v19;
        v19 = ECL_CONS_CDR(v18);
        v9 = v19;
        v18 = ECL_CONS_CAR(v18);
       }
L155:;
       v15param_and_offset = v18;
      }
      v16offset = ecl_car(v15param_and_offset);
      v17param = ecl_cdr(v15param_and_offset);
      if (!(ecl_eql(v17param,VV[17]))) { goto L163; }
      if (!(v5args==ECL_NIL)) { goto L168; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v16offset);
L168:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L170; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L170:;
      {
       cl_object v18;
       v18 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v18))) FEtype_error_list(v18);
       if (Null(v18)) { goto L175; }
       {
        cl_object v19;
        v19 = ECL_CONS_CDR(v18);
        v5args = v19;
        v18 = ECL_CONS_CAR(v18);
       }
L175:;
       value0 = v18;
      }
      if ((value0)!=ECL_NIL) { goto L166; }
      v14commainterval = ecl_make_fixnum(3);
      goto L150;
L166:;
      v14commainterval = value0;
      goto L150;
L163:;
      if (!(ecl_eql(v17param,VV[18]))) { goto L181; }
      v14commainterval = ecl_make_fixnum(ecl_length(v5args));
      goto L150;
L181:;
      if (!((v17param)==(ECL_NIL))) { goto L183; }
      v14commainterval = ecl_make_fixnum(3);
      goto L150;
L183:;
      v14commainterval = v17param;
     }
L150:;
     if (Null(v9)) { goto L186; }
     T0 = ecl_list1(ecl_make_fixnum(5));
     T1 = ecl_caar(v9);
     cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T0, ECL_SYM("OFFSET",1279), T1);
L186:;
     if (Null(v10base)) { goto L188; }
     if (!(v5args==ECL_NIL)) { goto L190; }
     cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L190:;
     if (Null(ecl_symbol_value(VV[25]))) { goto L192; }
     ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L192:;
     {
      cl_object v15;
      v15 = v5args;
      if (ecl_unlikely(!ECL_LISTP(v15))) FEtype_error_list(v15);
      if (Null(v15)) { goto L198; }
      {
       cl_object v16;
       v16 = ECL_CONS_CDR(v15);
       v5args = v16;
       v15 = ECL_CONS_CAR(v15);
      }
L198:;
      T0 = v15;
     }
     si_format_print_integer(9, v1stream, T0, v6, v7, v10base, v11mincol, v12padchar, v13commachar, v14commainterval);
     goto L4;
L188:;
     if (Null(v7)) { goto L204; }
     if (Null(v6)) { goto L206; }
     if (!(v5args==ECL_NIL)) { goto L208; }
     cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L208:;
     if (Null(ecl_symbol_value(VV[25]))) { goto L210; }
     ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L210:;
     {
      cl_object v15;
      v15 = v5args;
      if (ecl_unlikely(!ECL_LISTP(v15))) FEtype_error_list(v15);
      if (Null(v15)) { goto L216; }
      {
       cl_object v16;
       v16 = ECL_CONS_CDR(v15);
       v5args = v16;
       v15 = ECL_CONS_CAR(v15);
      }
L216:;
      T0 = v15;
     }
     si_format_print_old_roman(2, v1stream, T0);
     goto L4;
L206:;
     if (!(v5args==ECL_NIL)) { goto L222; }
     cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L222:;
     if (Null(ecl_symbol_value(VV[25]))) { goto L224; }
     ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L224:;
     {
      cl_object v15;
      v15 = v5args;
      if (ecl_unlikely(!ECL_LISTP(v15))) FEtype_error_list(v15);
      if (Null(v15)) { goto L230; }
      {
       cl_object v16;
       v16 = ECL_CONS_CDR(v15);
       v5args = v16;
       v15 = ECL_CONS_CAR(v15);
      }
L230:;
      T0 = v15;
     }
     si_format_print_roman(2, v1stream, T0);
     goto L4;
L204:;
     if (Null(v6)) { goto L236; }
     if (!(v5args==ECL_NIL)) { goto L238; }
     cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L238:;
     if (Null(ecl_symbol_value(VV[25]))) { goto L240; }
     ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L240:;
     {
      cl_object v15;
      v15 = v5args;
      if (ecl_unlikely(!ECL_LISTP(v15))) FEtype_error_list(v15);
      if (Null(v15)) { goto L246; }
      {
       cl_object v16;
       v16 = ECL_CONS_CDR(v15);
       v5args = v16;
       v15 = ECL_CONS_CAR(v15);
      }
L246:;
      T0 = v15;
     }
     si_format_print_ordinal(2, v1stream, T0);
     goto L4;
L236:;
     if (!(v5args==ECL_NIL)) { goto L252; }
     cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L252:;
     if (Null(ecl_symbol_value(VV[25]))) { goto L254; }
     ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L254:;
     {
      cl_object v15;
      v15 = v5args;
      if (ecl_unlikely(!ECL_LISTP(v15))) FEtype_error_list(v15);
      if (Null(v15)) { goto L260; }
      {
       cl_object v16;
       v16 = ECL_CONS_CDR(v15);
       v5args = v16;
       v15 = ECL_CONS_CAR(v15);
      }
L260:;
      T0 = v15;
     }
     si_format_print_cardinal(2, v1stream, T0);
    }
   }
L4:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5args;
   cl_env_copy->values[0] = v3;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for FORMAT-PRINT-SMALL-CARDINAL           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L44format_print_small_cardinal(cl_object v1stream, cl_object v2n)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4;                                  /*  HUNDREDS        */
   cl_object v5;                                  /*  REM             */
   value0 = ecl_truncate2(v2n,ecl_make_fixnum(100));
   v4 = value0;
   v5 = cl_env_copy->values[1];
   if (!(ecl_plusp(v4))) { goto L2; }
   T0 = ecl_aref1(ecl_symbol_value(VV[84]),ecl_to_size(v4));
   cl_write_string(2, T0, v1stream);
   cl_write_string(2, _ecl_static_23, v1stream);
   if (!(ecl_plusp(v5))) { goto L2; }
   cl_write_char(2, CODE_CHAR(32), v1stream);
L2:;
   if (!(ecl_plusp(v5))) { goto L7; }
   {
    cl_object v7;                                 /*  TENS            */
    cl_object v8;                                 /*  ONES            */
    value0 = ecl_truncate2(v5,ecl_make_fixnum(10));
    v7 = value0;
    v8 = cl_env_copy->values[1];
    if (!(ecl_number_compare(ecl_make_fixnum(1),v7)<0)) { goto L10; }
    T0 = ecl_aref1(ecl_symbol_value(VV[85]),ecl_to_size(v7));
    cl_write_string(2, T0, v1stream);
    if (!(ecl_plusp(v8))) { goto L13; }
    cl_write_char(2, CODE_CHAR(45), v1stream);
    T0 = ecl_aref1(ecl_symbol_value(VV[84]),ecl_to_size(v8));
    value0 = cl_write_string(2, T0, v1stream);
    return value0;
L13:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
L10:;
    if (!(ecl_number_equalp(v7,ecl_make_fixnum(1)))) { goto L16; }
    T0 = ecl_aref1(ecl_symbol_value(VV[86]),ecl_to_size(v8));
    value0 = cl_write_string(2, T0, v1stream);
    return value0;
L16:;
    if (!(ecl_plusp(v8))) { goto L18; }
    T0 = ecl_aref1(ecl_symbol_value(VV[84]),ecl_to_size(v8));
    value0 = cl_write_string(2, T0, v1stream);
    return value0;
L18:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L7:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for FORMAT-PRINT-CARDINAL                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_format_print_cardinal(cl_narg narg, cl_object v1stream, cl_object v2n, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  if (!(ecl_minusp(v2n))) { goto L1; }
  cl_write_string(2, _ecl_static_24, v1stream);
  T0 = ecl_negate(v2n);
  value0 = L45format_print_cardinal_aux(v1stream, T0, ecl_make_fixnum(0), v2n);
  return value0;
L1:;
  if (!(ecl_zerop(v2n))) { goto L4; }
  value0 = cl_write_string(2, _ecl_static_25, v1stream);
  return value0;
L4:;
  value0 = L45format_print_cardinal_aux(v1stream, v2n, ecl_make_fixnum(0), v2n);
  return value0;
 }
}
/*	function definition for FORMAT-PRINT-CARDINAL-AUX             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L45format_print_cardinal_aux(cl_object v1stream, cl_object v2n, cl_object v3period, cl_object v4err)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6;                                  /*  BEYOND          */
   cl_object v7;                                  /*  HERE            */
   value0 = ecl_truncate2(v2n,ecl_make_fixnum(1000));
   v6 = value0;
   v7 = cl_env_copy->values[1];
   if (ecl_number_compare(v3period,ecl_make_fixnum(20))<=0) { goto L2; }
   cl_error(2, _ecl_static_26, v4err);
L2:;
   if (ecl_zerop(v6)) { goto L4; }
   T0 = ecl_one_plus(v3period);
   L45format_print_cardinal_aux(v1stream, v6, T0, v4err);
L4:;
   if (ecl_zerop(v7)) { goto L6; }
   if (ecl_zerop(v6)) { goto L8; }
   cl_write_char(2, CODE_CHAR(32), v1stream);
L8:;
   L44format_print_small_cardinal(v1stream, v7);
   T0 = ecl_aref1(ecl_symbol_value(VV[87]),ecl_to_size(v3period));
   value0 = cl_write_string(2, T0, v1stream);
   return value0;
L6:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for FORMAT-PRINT-ORDINAL                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_format_print_ordinal(cl_narg narg, cl_object v1stream, cl_object v2n, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  if (!(ecl_minusp(v2n))) { goto L1; }
  cl_write_string(2, _ecl_static_24, v1stream);
L1:;
  {
   cl_object v3number;
   v3number = cl_abs(v2n);
   {
    cl_object v5;                                 /*  TOP             */
    cl_object v6;                                 /*  BOT             */
    value0 = ecl_truncate2(v3number,ecl_make_fixnum(100));
    v5 = value0;
    v6 = cl_env_copy->values[1];
    if (ecl_zerop(v5)) { goto L5; }
    T0 = ecl_minus(v3number,v6);
    si_format_print_cardinal(2, v1stream, T0);
L5:;
    if (!(ecl_plusp(v5))) { goto L7; }
    if (!(ecl_plusp(v6))) { goto L7; }
    cl_write_char(2, CODE_CHAR(32), v1stream);
L7:;
    {
     cl_object v8;                                /*  TENS            */
     cl_object v9;                                /*  ONES            */
     value0 = ecl_truncate2(v6,ecl_make_fixnum(10));
     v8 = value0;
     v9 = cl_env_copy->values[1];
     if (!(ecl_number_equalp(v6,ecl_make_fixnum(12)))) { goto L11; }
     value0 = cl_write_string(2, _ecl_static_27, v1stream);
     return value0;
L11:;
     if (!(ecl_number_equalp(v8,ecl_make_fixnum(1)))) { goto L13; }
     T0 = ecl_aref1(ecl_symbol_value(VV[86]),ecl_to_size(v9));
     cl_write_string(2, T0, v1stream);
     value0 = cl_write_string(2, _ecl_static_28, v1stream);
     return value0;
L13:;
     if (!(ecl_zerop(v8))) { goto L16; }
     if (!(ecl_plusp(v9))) { goto L16; }
     T0 = ecl_aref1(ecl_symbol_value(VV[88]),ecl_to_size(v9));
     value0 = cl_write_string(2, T0, v1stream);
     return value0;
L16:;
     if (!(ecl_zerop(v9))) { goto L19; }
     if (!(ecl_plusp(v8))) { goto L19; }
     T0 = ecl_aref1(ecl_symbol_value(VV[89]),ecl_to_size(v8));
     value0 = cl_write_string(2, T0, v1stream);
     return value0;
L19:;
     if (!(ecl_plusp(v6))) { goto L22; }
     T0 = ecl_aref1(ecl_symbol_value(VV[85]),ecl_to_size(v8));
     cl_write_string(2, T0, v1stream);
     cl_write_char(2, CODE_CHAR(45), v1stream);
     T0 = ecl_aref1(ecl_symbol_value(VV[88]),ecl_to_size(v9));
     value0 = cl_write_string(2, T0, v1stream);
     return value0;
L22:;
     if (!(ecl_plusp(v3number))) { goto L26; }
     value0 = cl_write_string(2, _ecl_static_28, v1stream);
     return value0;
L26:;
     value0 = cl_write_string(2, _ecl_static_29, v1stream);
     return value0;
    }
   }
  }
 }
}
/*	function definition for FORMAT-PRINT-OLD-ROMAN                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_format_print_old_roman(cl_narg narg, cl_object v1stream, cl_object v2n, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  if ((cl_L(3, ecl_make_fixnum(0), v2n, ecl_make_fixnum(5000)))!=ECL_NIL) { goto L1; }
  cl_error(2, _ecl_static_30, v2n);
L1:;
  {
   cl_object v3char_list;
   cl_object v4val_list;
   cl_object v5cur_char;
   cl_object v6cur_val;
   cl_object v7start;
   v3char_list = VV[92];
   v4val_list = VV[93];
   v5cur_char = CODE_CHAR(77);
   v6cur_val = ecl_make_fixnum(1000);
   v7start = v2n;
   goto L10;
L9:;
   {
    cl_object v8;
    v8 = ecl_cdr(v3char_list);
    {
     cl_object v9;
     v9 = ecl_cdr(v4val_list);
     {
      cl_object v10;
      v10 = ecl_car(v3char_list);
      {
       cl_object v11;
       v11 = ecl_car(v4val_list);
       {
        cl_object v12i;
        v12i = v7start;
        goto L21;
L20:;
        cl_write_char(2, v5cur_char, v1stream);
        v12i = ecl_minus(v12i,v6cur_val);
L21:;
        if (ecl_number_compare(v12i,v6cur_val)<0) { goto L26; }
        goto L20;
L26:;
        v7start = v12i;
       }
       v6cur_val = v11;
       v5cur_char = v10;
       v4val_list = v9;
       v3char_list = v8;
      }
     }
    }
   }
L10:;
   if (ecl_zerop(v7start)) { goto L28; }
   goto L9;
L28:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for FORMAT-PRINT-ROMAN                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_format_print_roman(cl_narg narg, cl_object v1stream, cl_object v2n, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  if ((cl_L(3, ecl_make_fixnum(0), v2n, ecl_make_fixnum(4000)))!=ECL_NIL) { goto L1; }
  cl_error(2, _ecl_static_31, v2n);
L1:;
  {
   cl_object v3char_list;
   cl_object v4val_list;
   cl_object v5sub_chars;
   cl_object v6sub_val;
   cl_object v7cur_char;
   cl_object v8cur_val;
   cl_object v9cur_sub_char;
   cl_object v10cur_sub_val;
   cl_object v11start;
   v3char_list = VV[92];
   v4val_list = VV[93];
   v5sub_chars = VV[95];
   v6sub_val = VV[96];
   v7cur_char = CODE_CHAR(77);
   v8cur_val = ecl_make_fixnum(1000);
   v9cur_sub_char = CODE_CHAR(67);
   v10cur_sub_val = ecl_make_fixnum(100);
   v11start = v2n;
   goto L14;
L13:;
   {
    cl_object v12;
    v12 = ecl_cdr(v3char_list);
    {
     cl_object v13;
     v13 = ecl_cdr(v4val_list);
     {
      cl_object v14;
      v14 = ecl_cdr(v5sub_chars);
      {
       cl_object v15;
       v15 = ecl_cdr(v6sub_val);
       {
        cl_object v16;
        v16 = ecl_car(v3char_list);
        {
         cl_object v17;
         v17 = ecl_car(v4val_list);
         {
          cl_object v18;
          v18 = ecl_car(v5sub_chars);
          {
          cl_object v19;
          v19 = ecl_car(v6sub_val);
          {
          cl_object v20i;
          v20i = v11start;
          goto L29;
L28:;
          cl_write_char(2, v7cur_char, v1stream);
          v20i = ecl_minus(v20i,v8cur_val);
L29:;
          if (ecl_number_compare(v20i,v8cur_val)<0) { goto L34; }
          goto L28;
L34:;
          T0 = ecl_minus(v8cur_val,v10cur_sub_val);
          if (!(ecl_number_compare(T0,v20i)<=0)) { goto L36; }
          cl_write_char(2, v9cur_sub_char, v1stream);
          cl_write_char(2, v7cur_char, v1stream);
          T0 = ecl_minus(v8cur_val,v10cur_sub_val);
          v11start = ecl_minus(v20i,T0);
          goto L25;
L36:;
          v11start = v20i;
          }
L25:;
          v10cur_sub_val = v19;
          v9cur_sub_char = v18;
          v8cur_val = v17;
          v7cur_char = v16;
          v6sub_val = v15;
          v5sub_chars = v14;
          v4val_list = v13;
          v3char_list = v12;
          }
         }
        }
       }
      }
     }
    }
   }
L14:;
   if (ecl_zerop(v11start)) { goto L40; }
   goto L13;
L40:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G776                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC46__g776(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6;
   v3 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v1) /*  FORMAT-DIRECTIVE-COLONP */;
   v4 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v1) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v5 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v1) /*  FORMAT-DIRECTIVE-PARAMS */;
   v6 = ecl_function_dispatch(cl_env_copy,VV[243])(1, v1) /*  FORMAT-DIRECTIVE-END */;
   if (Null(v5)) { goto L6; }
   T1 = ecl_caar(v5);
   cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_20, ECL_SYM("OFFSET",1279), T1);
L6:;
   {
    cl_object v7arg;
    if ((v3)!=ECL_NIL) { goto L9; }
    v7arg = L14expand_next_arg(0);
    goto L8;
L9:;
    if (Null(ecl_symbol_value(VV[29]))) { goto L11; }
    T1 = ecl_one_minus(v6);
    T2 = cl_list(6, ECL_SYM("ERROR",337), VV[37], VV[14], _ecl_static_32, ECL_SYM("OFFSET",1279), T1);
    v7arg = cl_list(4, ECL_SYM("IF",946), VV[98], T2, VV[99]);
    goto L8;
L11:;
    if (Null(ecl_symbol_value(VV[28]))) { goto L13; }
    if ((ecl_symbol_value(VV[30]))!=ECL_NIL) { goto L15; }
    cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_32);
L15:;
    v7arg = ecl_caar(ecl_symbol_value(VV[30]));
    goto L8;
L13:;
    cl_env_copy->values[0] = ECL_NIL;
    cl_env_copy->nvalues = 1;
    cl_throw(VV[36]);
L8:;
    if (Null(v4)) { goto L18; }
    T1 = cl_list(3, ECL_SYM("EQL",334), v7arg, ecl_make_fixnum(1));
    T2 = cl_listX(3, ECL_SYM("IF",946), T1, VV[100]);
    T0 = cl_list(3, ECL_SYM("WRITE-STRING",922), T2, ECL_SYM("STREAM",799));
    goto L5;
L18:;
    T1 = cl_list(3, ECL_SYM("EQL",334), v7arg, ecl_make_fixnum(1));
    T0 = cl_list(3, ECL_SYM("UNLESS",883), T1, VV[101]);
   }
L5:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v2;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G784                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC47__g784(cl_object v1stream, cl_object v2, cl_object v3, cl_object v4orig_args, cl_object v5args)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6;
   cl_object v7;
   cl_object v8;
   v6 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v2) /*  FORMAT-DIRECTIVE-COLONP */;
   v7 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v2) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v8 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v2) /*  FORMAT-DIRECTIVE-PARAMS */;
   if (Null(v8)) { goto L5; }
   T0 = ecl_list1(ecl_make_fixnum(0));
   T1 = ecl_caar(v8);
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T0, ECL_SYM("OFFSET",1279), T1);
L5:;
   {
    cl_object v9arg;
    if (Null(v6)) { goto L8; }
    if (!((v4orig_args)==(v5args))) { goto L10; }
    v9arg = cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_32);
    goto L7;
L10:;
    {
     cl_object v10arg_ptr;
     v10arg_ptr = v4orig_args;
     goto L15;
L14:;
     v10arg_ptr = ecl_cdr(v10arg_ptr);
L15:;
     T0 = ecl_cdr(v10arg_ptr);
     if ((T0)==(v5args)) { goto L19; }
     goto L14;
L19:;
     v9arg = ecl_car(v10arg_ptr);
     goto L7;
    }
L8:;
    if (!(v5args==ECL_NIL)) { goto L21; }
    cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L21:;
    if (Null(ecl_symbol_value(VV[25]))) { goto L23; }
    ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L23:;
    {
     cl_object v11;
     v11 = v5args;
     if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
     if (Null(v11)) { goto L28; }
     {
      cl_object v12;
      v12 = ECL_CONS_CDR(v11);
      v5args = v12;
      v11 = ECL_CONS_CAR(v11);
     }
L28:;
     v9arg = v11;
    }
L7:;
    if (Null(v7)) { goto L34; }
    if (!((v9arg)==(ecl_make_fixnum(1)))) { goto L37; }
    T0 = _ecl_static_33;
    goto L36;
L37:;
    T0 = _ecl_static_34;
L36:;
    cl_write_string(2, T0, v1stream);
    goto L4;
L34:;
    if ((v9arg)==(ecl_make_fixnum(1))) { goto L4; }
    cl_write_char(2, CODE_CHAR(115), v1stream);
   }
L4:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5args;
   cl_env_copy->values[0] = v3;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for DECIMAL-STRING                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L48decimal_string(cl_object v1n)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_write_to_string(7, v1n, ECL_SYM("BASE",1201), ecl_make_fixnum(10), ECL_SYM("RADIX",1295), ECL_NIL, ECL_SYM("ESCAPE",1230), ECL_NIL);
  return value0;
 }
}
/*	local function G795                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC49__g795(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   v3 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v1) /*  FORMAT-DIRECTIVE-COLONP */;
   v4 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v1) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v5 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v1) /*  FORMAT-DIRECTIVE-PARAMS */;
   if (Null(v3)) { goto L4; }
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_35);
L4:;
   {
    cl_object v6;
    v6 = v5;
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L13; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L13:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L21; }
     T2 = L14expand_next_arg(1, v8offset);
     T1 = cl_list(3, ECL_SYM("OR",614), T2, ECL_NIL);
     goto L8;
L21:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L23; }
     cl_set(VV[28],ECL_NIL);
     T1 = VV[54];
     goto L8;
L23:;
     if (!((v9param)==(ECL_NIL))) { goto L27; }
     T1 = ECL_NIL;
     goto L8;
L27:;
     T1 = v9param;
    }
L8:;
    T2 = cl_list(2, VV[102], T1);
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L35; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L35:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L43; }
     T4 = L14expand_next_arg(1, v8offset);
     T3 = cl_list(3, ECL_SYM("OR",614), T4, ECL_NIL);
     goto L30;
L43:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L45; }
     cl_set(VV[28],ECL_NIL);
     T3 = VV[54];
     goto L30;
L45:;
     if (!((v9param)==(ECL_NIL))) { goto L49; }
     T3 = ECL_NIL;
     goto L30;
L49:;
     T3 = v9param;
    }
L30:;
    T4 = cl_list(2, VV[103], T3);
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L57; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L57:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L65; }
     T6 = L14expand_next_arg(1, v8offset);
     T5 = cl_list(3, ECL_SYM("OR",614), T6, ECL_NIL);
     goto L52;
L65:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L67; }
     cl_set(VV[28],ECL_NIL);
     T5 = VV[54];
     goto L52;
L67:;
     if (!((v9param)==(ECL_NIL))) { goto L71; }
     T5 = ECL_NIL;
     goto L52;
L71:;
     T5 = v9param;
    }
L52:;
    T6 = cl_list(2, VV[104], T5);
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L79; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L79:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L87; }
     T8 = L14expand_next_arg(1, v8offset);
     T7 = cl_list(3, ECL_SYM("OR",614), T8, ECL_NIL);
     goto L74;
L87:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L89; }
     cl_set(VV[28],ECL_NIL);
     T7 = VV[54];
     goto L74;
L89:;
     if (!((v9param)==(ECL_NIL))) { goto L93; }
     T7 = ECL_NIL;
     goto L74;
L93:;
     T7 = v9param;
    }
L74:;
    T8 = cl_list(2, VV[105], T7);
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L101; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L101:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L109; }
     T10 = L14expand_next_arg(1, v8offset);
     T9 = cl_list(3, ECL_SYM("OR",614), T10, CODE_CHAR(32));
     goto L96;
L109:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L111; }
     cl_set(VV[28],ECL_NIL);
     T9 = VV[54];
     goto L96;
L111:;
     if (!((v9param)==(ECL_NIL))) { goto L115; }
     T9 = CODE_CHAR(32);
     goto L96;
L115:;
     T9 = v9param;
    }
L96:;
    T10 = cl_list(2, VV[106], T9);
    T11 = cl_list(5, T2, T4, T6, T8, T10);
    if (Null(v6)) { goto L119; }
    T13 = ecl_list1(ecl_make_fixnum(5));
    T14 = ecl_caar(v6);
    T12 = cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T13, ECL_SYM("OFFSET",1279), T14);
    goto L118;
L119:;
    T12 = ECL_NIL;
L118:;
    T13 = L14expand_next_arg(0);
    T14 = cl_list(9, VV[107], ECL_SYM("STREAM",799), T13, VV[102], VV[103], VV[104], VV[105], VV[106], v4);
    T15 = ecl_list1(T14);
    T16 = ecl_append(T12,T15);
    T0 = cl_listX(3, ECL_SYM("LET",477), T11, T16);
   }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v2;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G837                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC50__g837(cl_object v1stream, cl_object v2, cl_object v3, cl_object v4orig_args, cl_object v5args)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6;
   cl_object v7;
   cl_object v8;
   v6 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v2) /*  FORMAT-DIRECTIVE-COLONP */;
   v7 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v2) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v8 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v2) /*  FORMAT-DIRECTIVE-PARAMS */;
   if (Null(v6)) { goto L4; }
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_35);
L4:;
   {
    cl_object v9;
    v9 = v8;
    {
     cl_object v10w;
     cl_object v11d;
     cl_object v12k;
     cl_object v13ovf;
     cl_object v14pad;
     {
      cl_object v15param_and_offset;
      cl_object v16offset;
      cl_object v17param;
      {
       cl_object v18;
       v18 = v9;
       if (ecl_unlikely(!ECL_LISTP(v18))) FEtype_error_list(v18);
       if (Null(v18)) { goto L13; }
       {
        cl_object v19;
        v19 = ECL_CONS_CDR(v18);
        v9 = v19;
        v18 = ECL_CONS_CAR(v18);
       }
L13:;
       v15param_and_offset = v18;
      }
      v16offset = ecl_car(v15param_and_offset);
      v17param = ecl_cdr(v15param_and_offset);
      if (!(ecl_eql(v17param,VV[17]))) { goto L21; }
      if (!(v5args==ECL_NIL)) { goto L26; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v16offset);
L26:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L28; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L28:;
      {
       cl_object v18;
       v18 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v18))) FEtype_error_list(v18);
       if (Null(v18)) { goto L33; }
       {
        cl_object v19;
        v19 = ECL_CONS_CDR(v18);
        v5args = v19;
        v18 = ECL_CONS_CAR(v18);
       }
L33:;
       value0 = v18;
      }
      if ((value0)!=ECL_NIL) { goto L24; }
      v10w = ECL_NIL;
      goto L8;
L24:;
      v10w = value0;
      goto L8;
L21:;
      if (!(ecl_eql(v17param,VV[18]))) { goto L39; }
      v10w = ecl_make_fixnum(ecl_length(v5args));
      goto L8;
L39:;
      if (!((v17param)==(ECL_NIL))) { goto L41; }
      v10w = ECL_NIL;
      goto L8;
L41:;
      v10w = v17param;
     }
L8:;
     {
      cl_object v15param_and_offset;
      cl_object v16offset;
      cl_object v17param;
      {
       cl_object v18;
       v18 = v9;
       if (ecl_unlikely(!ECL_LISTP(v18))) FEtype_error_list(v18);
       if (Null(v18)) { goto L49; }
       {
        cl_object v19;
        v19 = ECL_CONS_CDR(v18);
        v9 = v19;
        v18 = ECL_CONS_CAR(v18);
       }
L49:;
       v15param_and_offset = v18;
      }
      v16offset = ecl_car(v15param_and_offset);
      v17param = ecl_cdr(v15param_and_offset);
      if (!(ecl_eql(v17param,VV[17]))) { goto L57; }
      if (!(v5args==ECL_NIL)) { goto L62; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v16offset);
L62:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L64; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L64:;
      {
       cl_object v18;
       v18 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v18))) FEtype_error_list(v18);
       if (Null(v18)) { goto L69; }
       {
        cl_object v19;
        v19 = ECL_CONS_CDR(v18);
        v5args = v19;
        v18 = ECL_CONS_CAR(v18);
       }
L69:;
       value0 = v18;
      }
      if ((value0)!=ECL_NIL) { goto L60; }
      v11d = ECL_NIL;
      goto L44;
L60:;
      v11d = value0;
      goto L44;
L57:;
      if (!(ecl_eql(v17param,VV[18]))) { goto L75; }
      v11d = ecl_make_fixnum(ecl_length(v5args));
      goto L44;
L75:;
      if (!((v17param)==(ECL_NIL))) { goto L77; }
      v11d = ECL_NIL;
      goto L44;
L77:;
      v11d = v17param;
     }
L44:;
     {
      cl_object v15param_and_offset;
      cl_object v16offset;
      cl_object v17param;
      {
       cl_object v18;
       v18 = v9;
       if (ecl_unlikely(!ECL_LISTP(v18))) FEtype_error_list(v18);
       if (Null(v18)) { goto L85; }
       {
        cl_object v19;
        v19 = ECL_CONS_CDR(v18);
        v9 = v19;
        v18 = ECL_CONS_CAR(v18);
       }
L85:;
       v15param_and_offset = v18;
      }
      v16offset = ecl_car(v15param_and_offset);
      v17param = ecl_cdr(v15param_and_offset);
      if (!(ecl_eql(v17param,VV[17]))) { goto L93; }
      if (!(v5args==ECL_NIL)) { goto L98; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v16offset);
L98:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L100; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L100:;
      {
       cl_object v18;
       v18 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v18))) FEtype_error_list(v18);
       if (Null(v18)) { goto L105; }
       {
        cl_object v19;
        v19 = ECL_CONS_CDR(v18);
        v5args = v19;
        v18 = ECL_CONS_CAR(v18);
       }
L105:;
       value0 = v18;
      }
      if ((value0)!=ECL_NIL) { goto L96; }
      v12k = ECL_NIL;
      goto L80;
L96:;
      v12k = value0;
      goto L80;
L93:;
      if (!(ecl_eql(v17param,VV[18]))) { goto L111; }
      v12k = ecl_make_fixnum(ecl_length(v5args));
      goto L80;
L111:;
      if (!((v17param)==(ECL_NIL))) { goto L113; }
      v12k = ECL_NIL;
      goto L80;
L113:;
      v12k = v17param;
     }
L80:;
     {
      cl_object v15param_and_offset;
      cl_object v16offset;
      cl_object v17param;
      {
       cl_object v18;
       v18 = v9;
       if (ecl_unlikely(!ECL_LISTP(v18))) FEtype_error_list(v18);
       if (Null(v18)) { goto L121; }
       {
        cl_object v19;
        v19 = ECL_CONS_CDR(v18);
        v9 = v19;
        v18 = ECL_CONS_CAR(v18);
       }
L121:;
       v15param_and_offset = v18;
      }
      v16offset = ecl_car(v15param_and_offset);
      v17param = ecl_cdr(v15param_and_offset);
      if (!(ecl_eql(v17param,VV[17]))) { goto L129; }
      if (!(v5args==ECL_NIL)) { goto L134; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v16offset);
L134:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L136; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L136:;
      {
       cl_object v18;
       v18 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v18))) FEtype_error_list(v18);
       if (Null(v18)) { goto L141; }
       {
        cl_object v19;
        v19 = ECL_CONS_CDR(v18);
        v5args = v19;
        v18 = ECL_CONS_CAR(v18);
       }
L141:;
       value0 = v18;
      }
      if ((value0)!=ECL_NIL) { goto L132; }
      v13ovf = ECL_NIL;
      goto L116;
L132:;
      v13ovf = value0;
      goto L116;
L129:;
      if (!(ecl_eql(v17param,VV[18]))) { goto L147; }
      v13ovf = ecl_make_fixnum(ecl_length(v5args));
      goto L116;
L147:;
      if (!((v17param)==(ECL_NIL))) { goto L149; }
      v13ovf = ECL_NIL;
      goto L116;
L149:;
      v13ovf = v17param;
     }
L116:;
     {
      cl_object v15param_and_offset;
      cl_object v16offset;
      cl_object v17param;
      {
       cl_object v18;
       v18 = v9;
       if (ecl_unlikely(!ECL_LISTP(v18))) FEtype_error_list(v18);
       if (Null(v18)) { goto L157; }
       {
        cl_object v19;
        v19 = ECL_CONS_CDR(v18);
        v9 = v19;
        v18 = ECL_CONS_CAR(v18);
       }
L157:;
       v15param_and_offset = v18;
      }
      v16offset = ecl_car(v15param_and_offset);
      v17param = ecl_cdr(v15param_and_offset);
      if (!(ecl_eql(v17param,VV[17]))) { goto L165; }
      if (!(v5args==ECL_NIL)) { goto L170; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v16offset);
L170:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L172; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L172:;
      {
       cl_object v18;
       v18 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v18))) FEtype_error_list(v18);
       if (Null(v18)) { goto L177; }
       {
        cl_object v19;
        v19 = ECL_CONS_CDR(v18);
        v5args = v19;
        v18 = ECL_CONS_CAR(v18);
       }
L177:;
       value0 = v18;
      }
      if ((value0)!=ECL_NIL) { goto L168; }
      v14pad = CODE_CHAR(32);
      goto L152;
L168:;
      v14pad = value0;
      goto L152;
L165:;
      if (!(ecl_eql(v17param,VV[18]))) { goto L183; }
      v14pad = ecl_make_fixnum(ecl_length(v5args));
      goto L152;
L183:;
      if (!((v17param)==(ECL_NIL))) { goto L185; }
      v14pad = CODE_CHAR(32);
      goto L152;
L185:;
      v14pad = v17param;
     }
L152:;
     if (Null(v9)) { goto L188; }
     T0 = ecl_list1(ecl_make_fixnum(5));
     T1 = ecl_caar(v9);
     cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T0, ECL_SYM("OFFSET",1279), T1);
L188:;
     if (!(v5args==ECL_NIL)) { goto L190; }
     cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L190:;
     if (Null(ecl_symbol_value(VV[25]))) { goto L192; }
     ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L192:;
     {
      cl_object v15;
      v15 = v5args;
      if (ecl_unlikely(!ECL_LISTP(v15))) FEtype_error_list(v15);
      if (Null(v15)) { goto L198; }
      {
       cl_object v16;
       v16 = ECL_CONS_CDR(v15);
       v5args = v16;
       v15 = ECL_CONS_CAR(v15);
      }
L198:;
      T0 = v15;
     }
     si_format_fixed(8, v1stream, T0, v10w, v11d, v12k, v13ovf, v14pad, v7);
    }
   }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5args;
   cl_env_copy->values[0] = v3;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for FORMAT-FIXED                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_format_fixed(cl_narg narg, cl_object v1stream, cl_object v2number, cl_object v3w, cl_object v4d, cl_object v5k, cl_object v6ovf, cl_object v7pad, cl_object v8atsign, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg!=8)) FEwrong_num_arguments_anonym();
 {
TTL:
  if (!(ecl_numberp(v2number))) { goto L1; }
  if (!(floatp(v2number))) { goto L3; }
  value0 = L51format_fixed_aux(v1stream, v2number, v3w, v4d, v5k, v6ovf, v7pad, v8atsign);
  return value0;
L3:;
  if (Null(cl_rationalp(v2number))) { goto L5; }
  {
   float v9;
   v9 = ecl_to_float(v2number);
   value0 = L51format_fixed_aux(v1stream, ecl_make_single_float(v9), v3w, v4d, v5k, v6ovf, v7pad, v8atsign);
   return value0;
  }
L5:;
  T0 = L48decimal_string(v2number);
  value0 = L22format_write_field(v1stream, T0, v3w, ecl_make_fixnum(1), ecl_make_fixnum(0), CODE_CHAR(32), ECL_T);
  return value0;
L1:;
  value0 = si_format_princ(8, v1stream, v2number, ECL_NIL, ECL_NIL, v3w, ecl_make_fixnum(1), ecl_make_fixnum(0), v7pad);
  return value0;
 }
}
/*	function definition for FORMAT-FIXED-AUX                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L51format_fixed_aux(cl_object v1stream, cl_object v2number, cl_object v3w, cl_object v4d, cl_object v5k, cl_object v6ovf, cl_object v7pad, cl_object v8atsign)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((v3w)!=ECL_NIL) { goto L1; }
  if ((v4d)!=ECL_NIL) { goto L1; }
  ecl_prin1(v2number,v1stream);
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  {
   cl_object v9spaceleft;
   v9spaceleft = v3w;
   if (Null(v3w)) { goto L6; }
   if ((v8atsign)!=ECL_NIL) { goto L9; }
   if (!(ecl_minusp(v2number))) { goto L6; }
   goto L7;
L9:;
L7:;
   v9spaceleft = ecl_minus(v9spaceleft,ecl_make_fixnum(1));
L6:;
   {
    cl_object v11;                                /*  STR             */
    cl_object v12;                                /*  LEN             */
    cl_object v13;                                /*  LPOINT          */
    cl_object v14;                                /*  TPOINT          */
    T0 = cl_abs(v2number);
    value0 = L1flonum_to_string(4, T0, v9spaceleft, v4d, v5k);
    v11 = value0;
    {
     const int v15 = cl_env_copy->nvalues;
     cl_object v16;
     v16 = (v15<=1)? ECL_NIL : cl_env_copy->values[1];
     v12 = v16;
     v16 = (v15<=2)? ECL_NIL : cl_env_copy->values[2];
     v13 = v16;
     v16 = (v15<=3)? ECL_NIL : cl_env_copy->values[3];
     v14 = v16;
    }
    if (Null(v4d)) { goto L13; }
    if (!(ecl_zerop(v4d))) { goto L13; }
    v14 = ECL_NIL;
L13:;
    if (Null(v3w)) { goto L17; }
    v9spaceleft = ecl_minus(v9spaceleft,v12);
    if (Null(v13)) { goto L21; }
    if (ecl_number_compare(v9spaceleft,ecl_make_fixnum(0))>0) { goto L25; }
    if (Null(v14)) { goto L23; }
    goto L24;
L25:;
L24:;
    v9spaceleft = ecl_minus(v9spaceleft,ecl_make_fixnum(1));
    goto L21;
L23:;
    v13 = ECL_NIL;
L21:;
    if (Null(v14)) { goto L17; }
    if (!(ecl_number_compare(v9spaceleft,ecl_make_fixnum(0))>0)) { goto L30; }
    v9spaceleft = ecl_minus(v9spaceleft,ecl_make_fixnum(1));
    goto L17;
L30:;
    v14 = ECL_NIL;
L17:;
    if (Null(v3w)) { goto L34; }
    if (!(ecl_number_compare(v9spaceleft,ecl_make_fixnum(0))<0)) { goto L34; }
    if (Null(v6ovf)) { goto L34; }
    {
     cl_object v15i;
     v15i = ecl_make_fixnum(0);
     goto L41;
L40:;
     cl_write_char(2, v6ovf, v1stream);
     v15i = ecl_one_plus(v15i);
L41:;
     if (!(ecl_number_compare(v15i,v3w)<0)) { goto L46; }
     goto L40;
L46:;
    }
    value0 = ECL_T;
    cl_env_copy->nvalues = 1;
    return value0;
L34:;
    if (Null(v3w)) { goto L48; }
    {
     cl_object v15i;
     v15i = ecl_make_fixnum(0);
     goto L52;
L51:;
     cl_write_char(2, v7pad, v1stream);
     v15i = ecl_one_plus(v15i);
L52:;
     if (!(ecl_number_compare(v15i,v9spaceleft)<0)) { goto L57; }
     goto L51;
L57:;
    }
L48:;
    if (!(ecl_minusp(v2number))) { goto L60; }
    cl_write_char(2, CODE_CHAR(45), v1stream);
    goto L59;
L60:;
    if (Null(v8atsign)) { goto L59; }
    cl_write_char(2, CODE_CHAR(43), v1stream);
L59:;
    if (Null(v13)) { goto L63; }
    cl_write_char(2, CODE_CHAR(48), v1stream);
L63:;
    cl_write_string(2, v11, v1stream);
    if (Null(v14)) { goto L66; }
    cl_write_char(2, CODE_CHAR(48), v1stream);
L66:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	local function G894                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC52__g894(cl_object v1, cl_object v2)
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
   v3 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v1) /*  FORMAT-DIRECTIVE-COLONP */;
   v4 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v1) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v5 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v1) /*  FORMAT-DIRECTIVE-PARAMS */;
   if (Null(v3)) { goto L4; }
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_35);
L4:;
   {
    cl_object v6;
    v6 = v5;
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L13; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L13:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L21; }
     T2 = L14expand_next_arg(1, v8offset);
     T1 = cl_list(3, ECL_SYM("OR",614), T2, ECL_NIL);
     goto L8;
L21:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L23; }
     cl_set(VV[28],ECL_NIL);
     T1 = VV[54];
     goto L8;
L23:;
     if (!((v9param)==(ECL_NIL))) { goto L27; }
     T1 = ECL_NIL;
     goto L8;
L27:;
     T1 = v9param;
    }
L8:;
    T2 = cl_list(2, VV[109], T1);
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L35; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L35:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L43; }
     T4 = L14expand_next_arg(1, v8offset);
     T3 = cl_list(3, ECL_SYM("OR",614), T4, ECL_NIL);
     goto L30;
L43:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L45; }
     cl_set(VV[28],ECL_NIL);
     T3 = VV[54];
     goto L30;
L45:;
     if (!((v9param)==(ECL_NIL))) { goto L49; }
     T3 = ECL_NIL;
     goto L30;
L49:;
     T3 = v9param;
    }
L30:;
    T4 = cl_list(2, VV[110], T3);
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L57; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L57:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L65; }
     T6 = L14expand_next_arg(1, v8offset);
     T5 = cl_list(3, ECL_SYM("OR",614), T6, ECL_NIL);
     goto L52;
L65:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L67; }
     cl_set(VV[28],ECL_NIL);
     T5 = VV[54];
     goto L52;
L67:;
     if (!((v9param)==(ECL_NIL))) { goto L71; }
     T5 = ECL_NIL;
     goto L52;
L71:;
     T5 = v9param;
    }
L52:;
    T6 = cl_list(2, VV[111], T5);
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L79; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L79:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L87; }
     T8 = L14expand_next_arg(1, v8offset);
     T7 = cl_list(3, ECL_SYM("OR",614), T8, ecl_make_fixnum(1));
     goto L74;
L87:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L89; }
     cl_set(VV[28],ECL_NIL);
     T7 = VV[54];
     goto L74;
L89:;
     if (!((v9param)==(ECL_NIL))) { goto L93; }
     T7 = ecl_make_fixnum(1);
     goto L74;
L93:;
     T7 = v9param;
    }
L74:;
    T8 = cl_list(2, VV[112], T7);
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L101; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L101:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L109; }
     T10 = L14expand_next_arg(1, v8offset);
     T9 = cl_list(3, ECL_SYM("OR",614), T10, ECL_NIL);
     goto L96;
L109:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L111; }
     cl_set(VV[28],ECL_NIL);
     T9 = VV[54];
     goto L96;
L111:;
     if (!((v9param)==(ECL_NIL))) { goto L115; }
     T9 = ECL_NIL;
     goto L96;
L115:;
     T9 = v9param;
    }
L96:;
    T10 = cl_list(2, VV[113], T9);
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L123; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L123:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L131; }
     T12 = L14expand_next_arg(1, v8offset);
     T11 = cl_list(3, ECL_SYM("OR",614), T12, CODE_CHAR(32));
     goto L118;
L131:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L133; }
     cl_set(VV[28],ECL_NIL);
     T11 = VV[54];
     goto L118;
L133:;
     if (!((v9param)==(ECL_NIL))) { goto L137; }
     T11 = CODE_CHAR(32);
     goto L118;
L137:;
     T11 = v9param;
    }
L118:;
    T12 = cl_list(2, VV[114], T11);
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L145; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L145:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L153; }
     T14 = L14expand_next_arg(1, v8offset);
     T13 = cl_list(3, ECL_SYM("OR",614), T14, ECL_NIL);
     goto L140;
L153:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L155; }
     cl_set(VV[28],ECL_NIL);
     T13 = VV[54];
     goto L140;
L155:;
     if (!((v9param)==(ECL_NIL))) { goto L159; }
     T13 = ECL_NIL;
     goto L140;
L159:;
     T13 = v9param;
    }
L140:;
    T14 = cl_list(2, VV[115], T13);
    T15 = cl_list(7, T2, T4, T6, T8, T10, T12, T14);
    if (Null(v6)) { goto L163; }
    T17 = ecl_list1(ecl_make_fixnum(7));
    T18 = ecl_caar(v6);
    T16 = cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T17, ECL_SYM("OFFSET",1279), T18);
    goto L162;
L163:;
    T16 = ECL_NIL;
L162:;
    T17 = L14expand_next_arg(0);
    T18 = cl_list(11, VV[116], ECL_SYM("STREAM",799), T17, VV[109], VV[110], VV[111], VV[112], VV[113], VV[114], VV[115], v4);
    T19 = ecl_list1(T18);
    T20 = ecl_append(T16,T19);
    T0 = cl_listX(3, ECL_SYM("LET",477), T15, T20);
   }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v2;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G950                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC53__g950(cl_object v1stream, cl_object v2, cl_object v3, cl_object v4orig_args, cl_object v5args)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6;
   cl_object v7;
   cl_object v8;
   v6 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v2) /*  FORMAT-DIRECTIVE-COLONP */;
   v7 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v2) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v8 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v2) /*  FORMAT-DIRECTIVE-PARAMS */;
   if (Null(v6)) { goto L4; }
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_35);
L4:;
   {
    cl_object v9;
    v9 = v8;
    {
     cl_object v10w;
     cl_object v11d;
     cl_object v12e;
     cl_object v13k;
     cl_object v14ovf;
     cl_object v15pad;
     cl_object v16mark;
     {
      cl_object v17param_and_offset;
      cl_object v18offset;
      cl_object v19param;
      {
       cl_object v20;
       v20 = v9;
       if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
       if (Null(v20)) { goto L13; }
       {
        cl_object v21;
        v21 = ECL_CONS_CDR(v20);
        v9 = v21;
        v20 = ECL_CONS_CAR(v20);
       }
L13:;
       v17param_and_offset = v20;
      }
      v18offset = ecl_car(v17param_and_offset);
      v19param = ecl_cdr(v17param_and_offset);
      if (!(ecl_eql(v19param,VV[17]))) { goto L21; }
      if (!(v5args==ECL_NIL)) { goto L26; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v18offset);
L26:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L28; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L28:;
      {
       cl_object v20;
       v20 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
       if (Null(v20)) { goto L33; }
       {
        cl_object v21;
        v21 = ECL_CONS_CDR(v20);
        v5args = v21;
        v20 = ECL_CONS_CAR(v20);
       }
L33:;
       value0 = v20;
      }
      if ((value0)!=ECL_NIL) { goto L24; }
      v10w = ECL_NIL;
      goto L8;
L24:;
      v10w = value0;
      goto L8;
L21:;
      if (!(ecl_eql(v19param,VV[18]))) { goto L39; }
      v10w = ecl_make_fixnum(ecl_length(v5args));
      goto L8;
L39:;
      if (!((v19param)==(ECL_NIL))) { goto L41; }
      v10w = ECL_NIL;
      goto L8;
L41:;
      v10w = v19param;
     }
L8:;
     {
      cl_object v17param_and_offset;
      cl_object v18offset;
      cl_object v19param;
      {
       cl_object v20;
       v20 = v9;
       if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
       if (Null(v20)) { goto L49; }
       {
        cl_object v21;
        v21 = ECL_CONS_CDR(v20);
        v9 = v21;
        v20 = ECL_CONS_CAR(v20);
       }
L49:;
       v17param_and_offset = v20;
      }
      v18offset = ecl_car(v17param_and_offset);
      v19param = ecl_cdr(v17param_and_offset);
      if (!(ecl_eql(v19param,VV[17]))) { goto L57; }
      if (!(v5args==ECL_NIL)) { goto L62; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v18offset);
L62:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L64; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L64:;
      {
       cl_object v20;
       v20 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
       if (Null(v20)) { goto L69; }
       {
        cl_object v21;
        v21 = ECL_CONS_CDR(v20);
        v5args = v21;
        v20 = ECL_CONS_CAR(v20);
       }
L69:;
       value0 = v20;
      }
      if ((value0)!=ECL_NIL) { goto L60; }
      v11d = ECL_NIL;
      goto L44;
L60:;
      v11d = value0;
      goto L44;
L57:;
      if (!(ecl_eql(v19param,VV[18]))) { goto L75; }
      v11d = ecl_make_fixnum(ecl_length(v5args));
      goto L44;
L75:;
      if (!((v19param)==(ECL_NIL))) { goto L77; }
      v11d = ECL_NIL;
      goto L44;
L77:;
      v11d = v19param;
     }
L44:;
     {
      cl_object v17param_and_offset;
      cl_object v18offset;
      cl_object v19param;
      {
       cl_object v20;
       v20 = v9;
       if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
       if (Null(v20)) { goto L85; }
       {
        cl_object v21;
        v21 = ECL_CONS_CDR(v20);
        v9 = v21;
        v20 = ECL_CONS_CAR(v20);
       }
L85:;
       v17param_and_offset = v20;
      }
      v18offset = ecl_car(v17param_and_offset);
      v19param = ecl_cdr(v17param_and_offset);
      if (!(ecl_eql(v19param,VV[17]))) { goto L93; }
      if (!(v5args==ECL_NIL)) { goto L98; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v18offset);
L98:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L100; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L100:;
      {
       cl_object v20;
       v20 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
       if (Null(v20)) { goto L105; }
       {
        cl_object v21;
        v21 = ECL_CONS_CDR(v20);
        v5args = v21;
        v20 = ECL_CONS_CAR(v20);
       }
L105:;
       value0 = v20;
      }
      if ((value0)!=ECL_NIL) { goto L96; }
      v12e = ECL_NIL;
      goto L80;
L96:;
      v12e = value0;
      goto L80;
L93:;
      if (!(ecl_eql(v19param,VV[18]))) { goto L111; }
      v12e = ecl_make_fixnum(ecl_length(v5args));
      goto L80;
L111:;
      if (!((v19param)==(ECL_NIL))) { goto L113; }
      v12e = ECL_NIL;
      goto L80;
L113:;
      v12e = v19param;
     }
L80:;
     {
      cl_object v17param_and_offset;
      cl_object v18offset;
      cl_object v19param;
      {
       cl_object v20;
       v20 = v9;
       if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
       if (Null(v20)) { goto L121; }
       {
        cl_object v21;
        v21 = ECL_CONS_CDR(v20);
        v9 = v21;
        v20 = ECL_CONS_CAR(v20);
       }
L121:;
       v17param_and_offset = v20;
      }
      v18offset = ecl_car(v17param_and_offset);
      v19param = ecl_cdr(v17param_and_offset);
      if (!(ecl_eql(v19param,VV[17]))) { goto L129; }
      if (!(v5args==ECL_NIL)) { goto L134; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v18offset);
L134:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L136; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L136:;
      {
       cl_object v20;
       v20 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
       if (Null(v20)) { goto L141; }
       {
        cl_object v21;
        v21 = ECL_CONS_CDR(v20);
        v5args = v21;
        v20 = ECL_CONS_CAR(v20);
       }
L141:;
       value0 = v20;
      }
      if ((value0)!=ECL_NIL) { goto L132; }
      v13k = ecl_make_fixnum(1);
      goto L116;
L132:;
      v13k = value0;
      goto L116;
L129:;
      if (!(ecl_eql(v19param,VV[18]))) { goto L147; }
      v13k = ecl_make_fixnum(ecl_length(v5args));
      goto L116;
L147:;
      if (!((v19param)==(ECL_NIL))) { goto L149; }
      v13k = ecl_make_fixnum(1);
      goto L116;
L149:;
      v13k = v19param;
     }
L116:;
     {
      cl_object v17param_and_offset;
      cl_object v18offset;
      cl_object v19param;
      {
       cl_object v20;
       v20 = v9;
       if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
       if (Null(v20)) { goto L157; }
       {
        cl_object v21;
        v21 = ECL_CONS_CDR(v20);
        v9 = v21;
        v20 = ECL_CONS_CAR(v20);
       }
L157:;
       v17param_and_offset = v20;
      }
      v18offset = ecl_car(v17param_and_offset);
      v19param = ecl_cdr(v17param_and_offset);
      if (!(ecl_eql(v19param,VV[17]))) { goto L165; }
      if (!(v5args==ECL_NIL)) { goto L170; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v18offset);
L170:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L172; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L172:;
      {
       cl_object v20;
       v20 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
       if (Null(v20)) { goto L177; }
       {
        cl_object v21;
        v21 = ECL_CONS_CDR(v20);
        v5args = v21;
        v20 = ECL_CONS_CAR(v20);
       }
L177:;
       value0 = v20;
      }
      if ((value0)!=ECL_NIL) { goto L168; }
      v14ovf = ECL_NIL;
      goto L152;
L168:;
      v14ovf = value0;
      goto L152;
L165:;
      if (!(ecl_eql(v19param,VV[18]))) { goto L183; }
      v14ovf = ecl_make_fixnum(ecl_length(v5args));
      goto L152;
L183:;
      if (!((v19param)==(ECL_NIL))) { goto L185; }
      v14ovf = ECL_NIL;
      goto L152;
L185:;
      v14ovf = v19param;
     }
L152:;
     {
      cl_object v17param_and_offset;
      cl_object v18offset;
      cl_object v19param;
      {
       cl_object v20;
       v20 = v9;
       if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
       if (Null(v20)) { goto L193; }
       {
        cl_object v21;
        v21 = ECL_CONS_CDR(v20);
        v9 = v21;
        v20 = ECL_CONS_CAR(v20);
       }
L193:;
       v17param_and_offset = v20;
      }
      v18offset = ecl_car(v17param_and_offset);
      v19param = ecl_cdr(v17param_and_offset);
      if (!(ecl_eql(v19param,VV[17]))) { goto L201; }
      if (!(v5args==ECL_NIL)) { goto L206; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v18offset);
L206:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L208; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L208:;
      {
       cl_object v20;
       v20 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
       if (Null(v20)) { goto L213; }
       {
        cl_object v21;
        v21 = ECL_CONS_CDR(v20);
        v5args = v21;
        v20 = ECL_CONS_CAR(v20);
       }
L213:;
       value0 = v20;
      }
      if ((value0)!=ECL_NIL) { goto L204; }
      v15pad = CODE_CHAR(32);
      goto L188;
L204:;
      v15pad = value0;
      goto L188;
L201:;
      if (!(ecl_eql(v19param,VV[18]))) { goto L219; }
      v15pad = ecl_make_fixnum(ecl_length(v5args));
      goto L188;
L219:;
      if (!((v19param)==(ECL_NIL))) { goto L221; }
      v15pad = CODE_CHAR(32);
      goto L188;
L221:;
      v15pad = v19param;
     }
L188:;
     {
      cl_object v17param_and_offset;
      cl_object v18offset;
      cl_object v19param;
      {
       cl_object v20;
       v20 = v9;
       if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
       if (Null(v20)) { goto L229; }
       {
        cl_object v21;
        v21 = ECL_CONS_CDR(v20);
        v9 = v21;
        v20 = ECL_CONS_CAR(v20);
       }
L229:;
       v17param_and_offset = v20;
      }
      v18offset = ecl_car(v17param_and_offset);
      v19param = ecl_cdr(v17param_and_offset);
      if (!(ecl_eql(v19param,VV[17]))) { goto L237; }
      if (!(v5args==ECL_NIL)) { goto L242; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v18offset);
L242:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L244; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L244:;
      {
       cl_object v20;
       v20 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
       if (Null(v20)) { goto L249; }
       {
        cl_object v21;
        v21 = ECL_CONS_CDR(v20);
        v5args = v21;
        v20 = ECL_CONS_CAR(v20);
       }
L249:;
       value0 = v20;
      }
      if ((value0)!=ECL_NIL) { goto L240; }
      v16mark = ECL_NIL;
      goto L224;
L240:;
      v16mark = value0;
      goto L224;
L237:;
      if (!(ecl_eql(v19param,VV[18]))) { goto L255; }
      v16mark = ecl_make_fixnum(ecl_length(v5args));
      goto L224;
L255:;
      if (!((v19param)==(ECL_NIL))) { goto L257; }
      v16mark = ECL_NIL;
      goto L224;
L257:;
      v16mark = v19param;
     }
L224:;
     if (Null(v9)) { goto L260; }
     T0 = ecl_list1(ecl_make_fixnum(7));
     T1 = ecl_caar(v9);
     cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T0, ECL_SYM("OFFSET",1279), T1);
L260:;
     if (!(v5args==ECL_NIL)) { goto L262; }
     cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L262:;
     if (Null(ecl_symbol_value(VV[25]))) { goto L264; }
     ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L264:;
     {
      cl_object v17;
      v17 = v5args;
      if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
      if (Null(v17)) { goto L270; }
      {
       cl_object v18;
       v18 = ECL_CONS_CDR(v17);
       v5args = v18;
       v17 = ECL_CONS_CAR(v17);
      }
L270:;
      T0 = v17;
     }
     si_format_exponential(10, v1stream, T0, v10w, v11d, v12e, v13k, v14ovf, v15pad, v16mark, v7);
    }
   }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5args;
   cl_env_copy->values[0] = v3;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for FORMAT-EXPONENTIAL                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_format_exponential(cl_narg narg, cl_object v1stream, cl_object v2number, cl_object v3w, cl_object v4d, cl_object v5e, cl_object v6k, cl_object v7ovf, cl_object v8pad, cl_object v9marker, cl_object v10atsign, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg!=10)) FEwrong_num_arguments_anonym();
 {
TTL:
  if (!(ecl_numberp(v2number))) { goto L1; }
  if (!(floatp(v2number))) { goto L3; }
  value0 = L55format_exp_aux(v1stream, v2number, v3w, v4d, v5e, v6k, v7ovf, v8pad, v9marker, v10atsign);
  return value0;
L3:;
  if (Null(cl_rationalp(v2number))) { goto L5; }
  {
   float v11;
   v11 = ecl_to_float(v2number);
   value0 = L55format_exp_aux(v1stream, ecl_make_single_float(v11), v3w, v4d, v5e, v6k, v7ovf, v8pad, v9marker, v10atsign);
   return value0;
  }
L5:;
  T0 = L48decimal_string(v2number);
  value0 = L22format_write_field(v1stream, T0, v3w, ecl_make_fixnum(1), ecl_make_fixnum(0), CODE_CHAR(32), ECL_T);
  return value0;
L1:;
  value0 = si_format_princ(8, v1stream, v2number, ECL_NIL, ECL_NIL, v3w, ecl_make_fixnum(1), ecl_make_fixnum(0), v8pad);
  return value0;
 }
}
/*	function definition for FORMAT-EXPONENT-MARKER                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L54format_exponent_marker(cl_object v1number)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_typep(2, v1number, ecl_symbol_value(ECL_SYM("*READ-DEFAULT-FLOAT-FORMAT*",62))))) { goto L1; }
  value0 = CODE_CHAR(101);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (!(ECL_SINGLE_FLOAT_P(v1number))) { goto L3; }
  value0 = CODE_CHAR(102);
  cl_env_copy->nvalues = 1;
  return value0;
L3:;
  if (!(ECL_DOUBLE_FLOAT_P(v1number))) { goto L5; }
  value0 = CODE_CHAR(100);
  cl_env_copy->nvalues = 1;
  return value0;
L5:;
  if (!(ECL_SINGLE_FLOAT_P(v1number))) { goto L7; }
  value0 = CODE_CHAR(115);
  cl_env_copy->nvalues = 1;
  return value0;
L7:;
  if (!(ECL_DOUBLE_FLOAT_P(v1number))) { goto L9; }
  value0 = CODE_CHAR(108);
  cl_env_copy->nvalues = 1;
  return value0;
L9:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for FORMAT-EXP-AUX                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L55format_exp_aux(cl_object v1stream, cl_object v2number, cl_object v3w, cl_object v4d, cl_object v5e, cl_object v6k, cl_object v7ovf, cl_object v8pad, cl_object v9marker, cl_object v10atsign)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v12;                                 /*  NUM             */
   cl_object v13;                                 /*  EXPT            */
   T0 = cl_abs(v2number);
   value0 = L2scale_exponent(T0);
   v12 = value0;
   {
    const int v14 = cl_env_copy->nvalues;
    cl_object v15;
    v15 = (v14<=1)? ECL_NIL : cl_env_copy->values[1];
    v13 = v15;
   }
   {
    cl_object v14expt;
    cl_object v15estr;
    cl_object v16elen;
    cl_object v17fdig;
    cl_object v18fmin;
    cl_object v19spaceleft;
    v14expt = ecl_minus(v13,v6k);
    T0 = cl_abs(v14expt);
    v15estr = L48decimal_string(T0);
    if (Null(v5e)) { goto L5; }
    {
     cl_fixnum v20;
     v20 = ecl_length(v15estr);
     v16elen = (ecl_number_compare(ecl_make_fixnum(v20),v5e)>=0?ecl_make_fixnum(v20):v5e);
     goto L4;
    }
L5:;
    v16elen = ecl_make_fixnum(ecl_length(v15estr));
L4:;
    if (Null(v4d)) { goto L8; }
    if (!(ecl_plusp(v6k))) { goto L10; }
    T0 = ecl_minus(v4d,v6k);
    v17fdig = ecl_one_plus(T0);
    goto L7;
L10:;
    v17fdig = v4d;
    goto L7;
L8:;
    v17fdig = ECL_NIL;
L7:;
    if (!(ecl_minusp(v6k))) { goto L13; }
    v18fmin = ecl_minus(ecl_make_fixnum(1),v6k);
    goto L12;
L13:;
    v18fmin = ECL_NIL;
L12:;
    if (Null(v3w)) { goto L16; }
    T0 = ecl_minus(v3w,ecl_make_fixnum(2));
    T1 = ecl_minus(T0,v16elen);
    {
     cl_fixnum v20;
     if ((v10atsign)!=ECL_NIL) { goto L21; }
     if (!(ecl_minusp(v2number))) { goto L19; }
     goto L20;
L21:;
L20:;
     v20 = 1;
     goto L18;
L19:;
     v20 = 0;
L18:;
     v19spaceleft = ecl_minus(T1,ecl_make_fixnum(v20));
     goto L15;
    }
L16:;
    v19spaceleft = ECL_NIL;
L15:;
    if (Null(v3w)) { goto L23; }
    if (Null(v7ovf)) { goto L23; }
    if (Null(v5e)) { goto L23; }
    if (!(ecl_number_compare(v16elen,v5e)>0)) { goto L23; }
    {
     cl_object v20i;
     v20i = ecl_make_fixnum(0);
     goto L30;
L29:;
     cl_write_char(2, v7ovf, v1stream);
     v20i = ecl_one_plus(v20i);
L30:;
     if (!(ecl_number_compare(v20i,v3w)<0)) { goto L35; }
     goto L29;
L35:;
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 1;
     return value0;
    }
L23:;
    {
     cl_object v22;                               /*  FSTR            */
     cl_object v23;                               /*  FLEN            */
     cl_object v24;                               /*  LPOINT          */
     value0 = L1flonum_to_string(5, v12, v19spaceleft, v17fdig, v6k, v18fmin);
     v22 = value0;
     {
      const int v25 = cl_env_copy->nvalues;
      cl_object v26;
      v26 = (v25<=1)? ECL_NIL : cl_env_copy->values[1];
      v23 = v26;
      v26 = (v25<=2)? ECL_NIL : cl_env_copy->values[2];
      v24 = v26;
     }
     if (Null(v3w)) { goto L38; }
     v19spaceleft = ecl_minus(v19spaceleft,v23);
     if (Null(v24)) { goto L38; }
     if (!(ecl_number_compare(v19spaceleft,ecl_make_fixnum(0))>0)) { goto L43; }
     v19spaceleft = ecl_minus(v19spaceleft,ecl_make_fixnum(1));
     goto L38;
L43:;
     v24 = ECL_NIL;
L38:;
     if (Null(v3w)) { goto L47; }
     if (!(ecl_number_compare(v19spaceleft,ecl_make_fixnum(0))<0)) { goto L47; }
     if (Null(v7ovf)) { goto L47; }
     {
      cl_object v25i;
      v25i = ecl_make_fixnum(0);
      goto L53;
L52:;
      cl_write_char(2, v7ovf, v1stream);
      v25i = ecl_one_plus(v25i);
L53:;
      if (!(ecl_number_compare(v25i,v3w)<0)) { goto L58; }
      goto L52;
L58:;
      value0 = ECL_NIL;
      cl_env_copy->nvalues = 1;
      return value0;
     }
L47:;
     if (Null(v3w)) { goto L60; }
     {
      cl_object v26i;
      v26i = ecl_make_fixnum(0);
      goto L64;
L63:;
      cl_write_char(2, v8pad, v1stream);
      v26i = ecl_one_plus(v26i);
L64:;
      if (!(ecl_number_compare(v26i,v19spaceleft)<0)) { goto L69; }
      goto L63;
L69:;
     }
L60:;
     if (!(ecl_minusp(v2number))) { goto L72; }
     cl_write_char(2, CODE_CHAR(45), v1stream);
     goto L71;
L72:;
     if (Null(v10atsign)) { goto L71; }
     cl_write_char(2, CODE_CHAR(43), v1stream);
L71:;
     if (Null(v24)) { goto L75; }
     cl_write_char(2, CODE_CHAR(48), v1stream);
L75:;
     cl_write_string(2, v22, v1stream);
     if (Null(v9marker)) { goto L80; }
     T0 = v9marker;
     goto L79;
L80:;
     T0 = L54format_exponent_marker(v2number);
L79:;
     cl_write_char(2, T0, v1stream);
     {
      ecl_character v26;
      if (!(ecl_minusp(v14expt))) { goto L84; }
      v26 = (ecl_character)(45);
      goto L83;
L84:;
      v26 = (ecl_character)(43);
L83:;
      cl_write_char(2, CODE_CHAR(v26), v1stream);
     }
     if (Null(v5e)) { goto L86; }
     {
      cl_object v26;
      {
       cl_fixnum v27;
       v27 = ecl_length(v15estr);
       v26 = ecl_minus(v5e,ecl_make_fixnum(v27));
      }
      {
       cl_object v27i;
       v27i = ecl_make_fixnum(0);
       goto L91;
L90:;
       cl_write_char(2, CODE_CHAR(48), v1stream);
       v27i = ecl_one_plus(v27i);
L91:;
       if (!(ecl_number_compare(v27i,v26)<0)) { goto L96; }
       goto L90;
L96:;
      }
     }
L86:;
     value0 = cl_write_string(2, v15estr, v1stream);
     return value0;
    }
   }
  }
 }
}
/*	local function G1026                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC56__g1026(cl_object v1, cl_object v2)
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
   v3 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v1) /*  FORMAT-DIRECTIVE-COLONP */;
   v4 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v1) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v5 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v1) /*  FORMAT-DIRECTIVE-PARAMS */;
   if (Null(v3)) { goto L4; }
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_35);
L4:;
   {
    cl_object v6;
    v6 = v5;
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L13; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L13:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L21; }
     T2 = L14expand_next_arg(1, v8offset);
     T1 = cl_list(3, ECL_SYM("OR",614), T2, ECL_NIL);
     goto L8;
L21:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L23; }
     cl_set(VV[28],ECL_NIL);
     T1 = VV[54];
     goto L8;
L23:;
     if (!((v9param)==(ECL_NIL))) { goto L27; }
     T1 = ECL_NIL;
     goto L8;
L27:;
     T1 = v9param;
    }
L8:;
    T2 = cl_list(2, VV[118], T1);
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L35; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L35:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L43; }
     T4 = L14expand_next_arg(1, v8offset);
     T3 = cl_list(3, ECL_SYM("OR",614), T4, ECL_NIL);
     goto L30;
L43:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L45; }
     cl_set(VV[28],ECL_NIL);
     T3 = VV[54];
     goto L30;
L45:;
     if (!((v9param)==(ECL_NIL))) { goto L49; }
     T3 = ECL_NIL;
     goto L30;
L49:;
     T3 = v9param;
    }
L30:;
    T4 = cl_list(2, VV[119], T3);
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L57; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L57:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L65; }
     T6 = L14expand_next_arg(1, v8offset);
     T5 = cl_list(3, ECL_SYM("OR",614), T6, ECL_NIL);
     goto L52;
L65:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L67; }
     cl_set(VV[28],ECL_NIL);
     T5 = VV[54];
     goto L52;
L67:;
     if (!((v9param)==(ECL_NIL))) { goto L71; }
     T5 = ECL_NIL;
     goto L52;
L71:;
     T5 = v9param;
    }
L52:;
    T6 = cl_list(2, VV[120], T5);
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L79; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L79:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L87; }
     T8 = L14expand_next_arg(1, v8offset);
     T7 = cl_list(3, ECL_SYM("OR",614), T8, ECL_NIL);
     goto L74;
L87:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L89; }
     cl_set(VV[28],ECL_NIL);
     T7 = VV[54];
     goto L74;
L89:;
     if (!((v9param)==(ECL_NIL))) { goto L93; }
     T7 = ECL_NIL;
     goto L74;
L93:;
     T7 = v9param;
    }
L74:;
    T8 = cl_list(2, VV[121], T7);
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L101; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L101:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L109; }
     T10 = L14expand_next_arg(1, v8offset);
     T9 = cl_list(3, ECL_SYM("OR",614), T10, ECL_NIL);
     goto L96;
L109:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L111; }
     cl_set(VV[28],ECL_NIL);
     T9 = VV[54];
     goto L96;
L111:;
     if (!((v9param)==(ECL_NIL))) { goto L115; }
     T9 = ECL_NIL;
     goto L96;
L115:;
     T9 = v9param;
    }
L96:;
    T10 = cl_list(2, VV[122], T9);
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L123; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L123:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L131; }
     T12 = L14expand_next_arg(1, v8offset);
     T11 = cl_list(3, ECL_SYM("OR",614), T12, CODE_CHAR(32));
     goto L118;
L131:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L133; }
     cl_set(VV[28],ECL_NIL);
     T11 = VV[54];
     goto L118;
L133:;
     if (!((v9param)==(ECL_NIL))) { goto L137; }
     T11 = CODE_CHAR(32);
     goto L118;
L137:;
     T11 = v9param;
    }
L118:;
    T12 = cl_list(2, VV[123], T11);
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L145; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L145:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L153; }
     T14 = L14expand_next_arg(1, v8offset);
     T13 = cl_list(3, ECL_SYM("OR",614), T14, ECL_NIL);
     goto L140;
L153:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L155; }
     cl_set(VV[28],ECL_NIL);
     T13 = VV[54];
     goto L140;
L155:;
     if (!((v9param)==(ECL_NIL))) { goto L159; }
     T13 = ECL_NIL;
     goto L140;
L159:;
     T13 = v9param;
    }
L140:;
    T14 = cl_list(2, VV[124], T13);
    T15 = cl_list(7, T2, T4, T6, T8, T10, T12, T14);
    if (Null(v6)) { goto L163; }
    T17 = ecl_list1(ecl_make_fixnum(7));
    T18 = ecl_caar(v6);
    T16 = cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T17, ECL_SYM("OFFSET",1279), T18);
    goto L162;
L163:;
    T16 = ECL_NIL;
L162:;
    T17 = L14expand_next_arg(0);
    T18 = cl_list(11, VV[125], ECL_SYM("STREAM",799), T17, VV[118], VV[119], VV[120], VV[121], VV[122], VV[123], VV[124], v4);
    T19 = ecl_list1(T18);
    T20 = ecl_append(T16,T19);
    T0 = cl_listX(3, ECL_SYM("LET",477), T15, T20);
   }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v2;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G1082                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC57__g1082(cl_object v1stream, cl_object v2, cl_object v3, cl_object v4orig_args, cl_object v5args)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6;
   cl_object v7;
   cl_object v8;
   v6 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v2) /*  FORMAT-DIRECTIVE-COLONP */;
   v7 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v2) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v8 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v2) /*  FORMAT-DIRECTIVE-PARAMS */;
   if (Null(v6)) { goto L4; }
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_35);
L4:;
   {
    cl_object v9;
    v9 = v8;
    {
     cl_object v10w;
     cl_object v11d;
     cl_object v12e;
     cl_object v13k;
     cl_object v14ovf;
     cl_object v15pad;
     cl_object v16mark;
     {
      cl_object v17param_and_offset;
      cl_object v18offset;
      cl_object v19param;
      {
       cl_object v20;
       v20 = v9;
       if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
       if (Null(v20)) { goto L13; }
       {
        cl_object v21;
        v21 = ECL_CONS_CDR(v20);
        v9 = v21;
        v20 = ECL_CONS_CAR(v20);
       }
L13:;
       v17param_and_offset = v20;
      }
      v18offset = ecl_car(v17param_and_offset);
      v19param = ecl_cdr(v17param_and_offset);
      if (!(ecl_eql(v19param,VV[17]))) { goto L21; }
      if (!(v5args==ECL_NIL)) { goto L26; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v18offset);
L26:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L28; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L28:;
      {
       cl_object v20;
       v20 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
       if (Null(v20)) { goto L33; }
       {
        cl_object v21;
        v21 = ECL_CONS_CDR(v20);
        v5args = v21;
        v20 = ECL_CONS_CAR(v20);
       }
L33:;
       value0 = v20;
      }
      if ((value0)!=ECL_NIL) { goto L24; }
      v10w = ECL_NIL;
      goto L8;
L24:;
      v10w = value0;
      goto L8;
L21:;
      if (!(ecl_eql(v19param,VV[18]))) { goto L39; }
      v10w = ecl_make_fixnum(ecl_length(v5args));
      goto L8;
L39:;
      if (!((v19param)==(ECL_NIL))) { goto L41; }
      v10w = ECL_NIL;
      goto L8;
L41:;
      v10w = v19param;
     }
L8:;
     {
      cl_object v17param_and_offset;
      cl_object v18offset;
      cl_object v19param;
      {
       cl_object v20;
       v20 = v9;
       if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
       if (Null(v20)) { goto L49; }
       {
        cl_object v21;
        v21 = ECL_CONS_CDR(v20);
        v9 = v21;
        v20 = ECL_CONS_CAR(v20);
       }
L49:;
       v17param_and_offset = v20;
      }
      v18offset = ecl_car(v17param_and_offset);
      v19param = ecl_cdr(v17param_and_offset);
      if (!(ecl_eql(v19param,VV[17]))) { goto L57; }
      if (!(v5args==ECL_NIL)) { goto L62; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v18offset);
L62:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L64; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L64:;
      {
       cl_object v20;
       v20 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
       if (Null(v20)) { goto L69; }
       {
        cl_object v21;
        v21 = ECL_CONS_CDR(v20);
        v5args = v21;
        v20 = ECL_CONS_CAR(v20);
       }
L69:;
       value0 = v20;
      }
      if ((value0)!=ECL_NIL) { goto L60; }
      v11d = ECL_NIL;
      goto L44;
L60:;
      v11d = value0;
      goto L44;
L57:;
      if (!(ecl_eql(v19param,VV[18]))) { goto L75; }
      v11d = ecl_make_fixnum(ecl_length(v5args));
      goto L44;
L75:;
      if (!((v19param)==(ECL_NIL))) { goto L77; }
      v11d = ECL_NIL;
      goto L44;
L77:;
      v11d = v19param;
     }
L44:;
     {
      cl_object v17param_and_offset;
      cl_object v18offset;
      cl_object v19param;
      {
       cl_object v20;
       v20 = v9;
       if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
       if (Null(v20)) { goto L85; }
       {
        cl_object v21;
        v21 = ECL_CONS_CDR(v20);
        v9 = v21;
        v20 = ECL_CONS_CAR(v20);
       }
L85:;
       v17param_and_offset = v20;
      }
      v18offset = ecl_car(v17param_and_offset);
      v19param = ecl_cdr(v17param_and_offset);
      if (!(ecl_eql(v19param,VV[17]))) { goto L93; }
      if (!(v5args==ECL_NIL)) { goto L98; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v18offset);
L98:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L100; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L100:;
      {
       cl_object v20;
       v20 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
       if (Null(v20)) { goto L105; }
       {
        cl_object v21;
        v21 = ECL_CONS_CDR(v20);
        v5args = v21;
        v20 = ECL_CONS_CAR(v20);
       }
L105:;
       value0 = v20;
      }
      if ((value0)!=ECL_NIL) { goto L96; }
      v12e = ECL_NIL;
      goto L80;
L96:;
      v12e = value0;
      goto L80;
L93:;
      if (!(ecl_eql(v19param,VV[18]))) { goto L111; }
      v12e = ecl_make_fixnum(ecl_length(v5args));
      goto L80;
L111:;
      if (!((v19param)==(ECL_NIL))) { goto L113; }
      v12e = ECL_NIL;
      goto L80;
L113:;
      v12e = v19param;
     }
L80:;
     {
      cl_object v17param_and_offset;
      cl_object v18offset;
      cl_object v19param;
      {
       cl_object v20;
       v20 = v9;
       if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
       if (Null(v20)) { goto L121; }
       {
        cl_object v21;
        v21 = ECL_CONS_CDR(v20);
        v9 = v21;
        v20 = ECL_CONS_CAR(v20);
       }
L121:;
       v17param_and_offset = v20;
      }
      v18offset = ecl_car(v17param_and_offset);
      v19param = ecl_cdr(v17param_and_offset);
      if (!(ecl_eql(v19param,VV[17]))) { goto L129; }
      if (!(v5args==ECL_NIL)) { goto L134; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v18offset);
L134:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L136; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L136:;
      {
       cl_object v20;
       v20 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
       if (Null(v20)) { goto L141; }
       {
        cl_object v21;
        v21 = ECL_CONS_CDR(v20);
        v5args = v21;
        v20 = ECL_CONS_CAR(v20);
       }
L141:;
       value0 = v20;
      }
      if ((value0)!=ECL_NIL) { goto L132; }
      v13k = ECL_NIL;
      goto L116;
L132:;
      v13k = value0;
      goto L116;
L129:;
      if (!(ecl_eql(v19param,VV[18]))) { goto L147; }
      v13k = ecl_make_fixnum(ecl_length(v5args));
      goto L116;
L147:;
      if (!((v19param)==(ECL_NIL))) { goto L149; }
      v13k = ECL_NIL;
      goto L116;
L149:;
      v13k = v19param;
     }
L116:;
     {
      cl_object v17param_and_offset;
      cl_object v18offset;
      cl_object v19param;
      {
       cl_object v20;
       v20 = v9;
       if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
       if (Null(v20)) { goto L157; }
       {
        cl_object v21;
        v21 = ECL_CONS_CDR(v20);
        v9 = v21;
        v20 = ECL_CONS_CAR(v20);
       }
L157:;
       v17param_and_offset = v20;
      }
      v18offset = ecl_car(v17param_and_offset);
      v19param = ecl_cdr(v17param_and_offset);
      if (!(ecl_eql(v19param,VV[17]))) { goto L165; }
      if (!(v5args==ECL_NIL)) { goto L170; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v18offset);
L170:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L172; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L172:;
      {
       cl_object v20;
       v20 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
       if (Null(v20)) { goto L177; }
       {
        cl_object v21;
        v21 = ECL_CONS_CDR(v20);
        v5args = v21;
        v20 = ECL_CONS_CAR(v20);
       }
L177:;
       value0 = v20;
      }
      if ((value0)!=ECL_NIL) { goto L168; }
      v14ovf = ECL_NIL;
      goto L152;
L168:;
      v14ovf = value0;
      goto L152;
L165:;
      if (!(ecl_eql(v19param,VV[18]))) { goto L183; }
      v14ovf = ecl_make_fixnum(ecl_length(v5args));
      goto L152;
L183:;
      if (!((v19param)==(ECL_NIL))) { goto L185; }
      v14ovf = ECL_NIL;
      goto L152;
L185:;
      v14ovf = v19param;
     }
L152:;
     {
      cl_object v17param_and_offset;
      cl_object v18offset;
      cl_object v19param;
      {
       cl_object v20;
       v20 = v9;
       if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
       if (Null(v20)) { goto L193; }
       {
        cl_object v21;
        v21 = ECL_CONS_CDR(v20);
        v9 = v21;
        v20 = ECL_CONS_CAR(v20);
       }
L193:;
       v17param_and_offset = v20;
      }
      v18offset = ecl_car(v17param_and_offset);
      v19param = ecl_cdr(v17param_and_offset);
      if (!(ecl_eql(v19param,VV[17]))) { goto L201; }
      if (!(v5args==ECL_NIL)) { goto L206; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v18offset);
L206:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L208; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L208:;
      {
       cl_object v20;
       v20 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
       if (Null(v20)) { goto L213; }
       {
        cl_object v21;
        v21 = ECL_CONS_CDR(v20);
        v5args = v21;
        v20 = ECL_CONS_CAR(v20);
       }
L213:;
       value0 = v20;
      }
      if ((value0)!=ECL_NIL) { goto L204; }
      v15pad = CODE_CHAR(32);
      goto L188;
L204:;
      v15pad = value0;
      goto L188;
L201:;
      if (!(ecl_eql(v19param,VV[18]))) { goto L219; }
      v15pad = ecl_make_fixnum(ecl_length(v5args));
      goto L188;
L219:;
      if (!((v19param)==(ECL_NIL))) { goto L221; }
      v15pad = CODE_CHAR(32);
      goto L188;
L221:;
      v15pad = v19param;
     }
L188:;
     {
      cl_object v17param_and_offset;
      cl_object v18offset;
      cl_object v19param;
      {
       cl_object v20;
       v20 = v9;
       if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
       if (Null(v20)) { goto L229; }
       {
        cl_object v21;
        v21 = ECL_CONS_CDR(v20);
        v9 = v21;
        v20 = ECL_CONS_CAR(v20);
       }
L229:;
       v17param_and_offset = v20;
      }
      v18offset = ecl_car(v17param_and_offset);
      v19param = ecl_cdr(v17param_and_offset);
      if (!(ecl_eql(v19param,VV[17]))) { goto L237; }
      if (!(v5args==ECL_NIL)) { goto L242; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v18offset);
L242:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L244; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L244:;
      {
       cl_object v20;
       v20 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
       if (Null(v20)) { goto L249; }
       {
        cl_object v21;
        v21 = ECL_CONS_CDR(v20);
        v5args = v21;
        v20 = ECL_CONS_CAR(v20);
       }
L249:;
       value0 = v20;
      }
      if ((value0)!=ECL_NIL) { goto L240; }
      v16mark = ECL_NIL;
      goto L224;
L240:;
      v16mark = value0;
      goto L224;
L237:;
      if (!(ecl_eql(v19param,VV[18]))) { goto L255; }
      v16mark = ecl_make_fixnum(ecl_length(v5args));
      goto L224;
L255:;
      if (!((v19param)==(ECL_NIL))) { goto L257; }
      v16mark = ECL_NIL;
      goto L224;
L257:;
      v16mark = v19param;
     }
L224:;
     if (Null(v9)) { goto L260; }
     T0 = ecl_list1(ecl_make_fixnum(7));
     T1 = ecl_caar(v9);
     cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T0, ECL_SYM("OFFSET",1279), T1);
L260:;
     if (!(v5args==ECL_NIL)) { goto L262; }
     cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L262:;
     if (Null(ecl_symbol_value(VV[25]))) { goto L264; }
     ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L264:;
     {
      cl_object v17;
      v17 = v5args;
      if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
      if (Null(v17)) { goto L270; }
      {
       cl_object v18;
       v18 = ECL_CONS_CDR(v17);
       v5args = v18;
       v17 = ECL_CONS_CAR(v17);
      }
L270:;
      T0 = v17;
     }
     si_format_general(10, v1stream, T0, v10w, v11d, v12e, v13k, v14ovf, v15pad, v16mark, v7);
    }
   }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5args;
   cl_env_copy->values[0] = v3;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for FORMAT-GENERAL                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_format_general(cl_narg narg, cl_object v1stream, cl_object v2number, cl_object v3w, cl_object v4d, cl_object v5e, cl_object v6k, cl_object v7ovf, cl_object v8pad, cl_object v9marker, cl_object v10atsign, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg!=10)) FEwrong_num_arguments_anonym();
 {
TTL:
  if (!(ecl_numberp(v2number))) { goto L1; }
  if (!(floatp(v2number))) { goto L3; }
  value0 = L58format_general_aux(v1stream, v2number, v3w, v4d, v5e, v6k, v7ovf, v8pad, v9marker, v10atsign);
  return value0;
L3:;
  if (Null(cl_rationalp(v2number))) { goto L5; }
  {
   float v11;
   v11 = ecl_to_float(v2number);
   value0 = L58format_general_aux(v1stream, ecl_make_single_float(v11), v3w, v4d, v5e, v6k, v7ovf, v8pad, v9marker, v10atsign);
   return value0;
  }
L5:;
  T0 = L48decimal_string(v2number);
  value0 = L22format_write_field(v1stream, T0, v3w, ecl_make_fixnum(1), ecl_make_fixnum(0), CODE_CHAR(32), ECL_T);
  return value0;
L1:;
  value0 = si_format_princ(8, v1stream, v2number, ECL_NIL, ECL_NIL, v3w, ecl_make_fixnum(1), ecl_make_fixnum(0), v8pad);
  return value0;
 }
}
/*	function definition for FORMAT-GENERAL-AUX                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L58format_general_aux(cl_object v1stream, cl_object v2number, cl_object v3w, cl_object v4d, cl_object v5e, cl_object v6k, cl_object v7ovf, cl_object v8pad, cl_object v9marker, cl_object v10atsign)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v12;                                 /*  N               */
   T0 = cl_abs(v2number);
   value0 = L2scale_exponent(T0);
   {
    const int v13 = cl_env_copy->nvalues;
    cl_object v14;
    v14 = (v13<=1)? ECL_NIL : cl_env_copy->values[1];
    v12 = v14;
   }
   if ((v4d)!=ECL_NIL) { goto L2; }
   {
    cl_object v14;                                /*  LEN             */
    T0 = cl_abs(v2number);
    value0 = L1flonum_to_string(1, T0);
    {
     const int v15 = cl_env_copy->nvalues;
     cl_object v16;
     v16 = (v15<=1)? ECL_NIL : cl_env_copy->values[1];
     v14 = v16;
    }
    {
     cl_object v15q;
     if (!(ecl_number_equalp(v14,ecl_make_fixnum(1)))) { goto L6; }
     v15q = ecl_make_fixnum(1);
     goto L5;
L6:;
     v15q = ecl_one_minus(v14);
L5:;
     T0 = (ecl_number_compare(v12,ecl_make_fixnum(7))<=0?v12:ecl_make_fixnum(7));
     v4d = (ecl_number_compare(v15q,T0)>=0?v15q:T0);
    }
   }
L2:;
   {
    cl_object v13ee;
    cl_object v14ww;
    cl_object v15dd;
    if (Null(v5e)) { goto L10; }
    v13ee = ecl_plus(v5e,ecl_make_fixnum(2));
    goto L9;
L10:;
    v13ee = ecl_make_fixnum(4);
L9:;
    if (Null(v3w)) { goto L13; }
    v14ww = ecl_minus(v3w,v13ee);
    goto L12;
L13:;
    v14ww = ECL_NIL;
L12:;
    v15dd = ecl_minus(v4d,v12);
    if (Null(cl_LE(3, ecl_make_fixnum(0), v15dd, v4d))) { goto L16; }
    {
     cl_object v16char;
     if (Null(L51format_fixed_aux(v1stream, v2number, v14ww, v15dd, ECL_NIL, v7ovf, v8pad, v10atsign))) { goto L19; }
     v16char = v7ovf;
     goto L18;
L19:;
     v16char = CODE_CHAR(32);
L18:;
     {
      cl_object v17i;
      v17i = ecl_make_fixnum(0);
      goto L23;
L22:;
      cl_write_char(2, v16char, v1stream);
      v17i = ecl_one_plus(v17i);
L23:;
      if (!(ecl_number_compare(v17i,v13ee)<0)) { goto L28; }
      goto L22;
L28:;
      value0 = ECL_NIL;
      cl_env_copy->nvalues = 1;
      return value0;
     }
    }
L16:;
    value0 = v6k;
    if ((value0)!=ECL_NIL) { goto L32; }
    T0 = ecl_make_fixnum(1);
    goto L30;
L32:;
    T0 = value0;
    goto L30;
L30:;
    value0 = L55format_exp_aux(v1stream, v2number, v3w, v4d, v5e, T0, v7ovf, v8pad, v9marker, v10atsign);
    return value0;
   }
  }
 }
}
/*	local function G1138                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC59__g1138(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   v3 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v1) /*  FORMAT-DIRECTIVE-COLONP */;
   v4 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v1) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v5 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v1) /*  FORMAT-DIRECTIVE-PARAMS */;
   {
    cl_object v6;
    v6 = v5;
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L11; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L11:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L19; }
     T2 = L14expand_next_arg(1, v8offset);
     T1 = cl_list(3, ECL_SYM("OR",614), T2, ecl_make_fixnum(2));
     goto L6;
L19:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L21; }
     cl_set(VV[28],ECL_NIL);
     T1 = VV[54];
     goto L6;
L21:;
     if (!((v9param)==(ECL_NIL))) { goto L25; }
     T1 = ecl_make_fixnum(2);
     goto L6;
L25:;
     T1 = v9param;
    }
L6:;
    T2 = cl_list(2, VV[127], T1);
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L33; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L33:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L41; }
     T4 = L14expand_next_arg(1, v8offset);
     T3 = cl_list(3, ECL_SYM("OR",614), T4, ecl_make_fixnum(1));
     goto L28;
L41:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L43; }
     cl_set(VV[28],ECL_NIL);
     T3 = VV[54];
     goto L28;
L43:;
     if (!((v9param)==(ECL_NIL))) { goto L47; }
     T3 = ecl_make_fixnum(1);
     goto L28;
L47:;
     T3 = v9param;
    }
L28:;
    T4 = cl_list(2, VV[128], T3);
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L55; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L55:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L63; }
     T6 = L14expand_next_arg(1, v8offset);
     T5 = cl_list(3, ECL_SYM("OR",614), T6, ecl_make_fixnum(0));
     goto L50;
L63:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L65; }
     cl_set(VV[28],ECL_NIL);
     T5 = VV[54];
     goto L50;
L65:;
     if (!((v9param)==(ECL_NIL))) { goto L69; }
     T5 = ecl_make_fixnum(0);
     goto L50;
L69:;
     T5 = v9param;
    }
L50:;
    T6 = cl_list(2, VV[129], T5);
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L77; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L77:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L85; }
     T8 = L14expand_next_arg(1, v8offset);
     T7 = cl_list(3, ECL_SYM("OR",614), T8, CODE_CHAR(32));
     goto L72;
L85:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L87; }
     cl_set(VV[28],ECL_NIL);
     T7 = VV[54];
     goto L72;
L87:;
     if (!((v9param)==(ECL_NIL))) { goto L91; }
     T7 = CODE_CHAR(32);
     goto L72;
L91:;
     T7 = v9param;
    }
L72:;
    T8 = cl_list(2, VV[130], T7);
    T9 = cl_list(4, T2, T4, T6, T8);
    if (Null(v6)) { goto L95; }
    T11 = ecl_list1(ecl_make_fixnum(4));
    T12 = ecl_caar(v6);
    T10 = cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T11, ECL_SYM("OFFSET",1279), T12);
    goto L94;
L95:;
    T10 = ECL_NIL;
L94:;
    T11 = L14expand_next_arg(0);
    T12 = cl_list(9, VV[131], ECL_SYM("STREAM",799), T11, VV[127], VV[128], VV[129], VV[130], v3, v4);
    T13 = ecl_list1(T12);
    T14 = ecl_append(T10,T13);
    T0 = cl_listX(3, ECL_SYM("LET",477), T9, T14);
   }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v2;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G1173                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC60__g1173(cl_object v1stream, cl_object v2, cl_object v3, cl_object v4orig_args, cl_object v5args)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6;
   cl_object v7;
   cl_object v8;
   v6 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v2) /*  FORMAT-DIRECTIVE-COLONP */;
   v7 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v2) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v8 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v2) /*  FORMAT-DIRECTIVE-PARAMS */;
   {
    cl_object v9;
    v9 = v8;
    {
     cl_object v10d;
     cl_object v11n;
     cl_object v12w;
     cl_object v13pad;
     {
      cl_object v14param_and_offset;
      cl_object v15offset;
      cl_object v16param;
      {
       cl_object v17;
       v17 = v9;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L11; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v9 = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L11:;
       v14param_and_offset = v17;
      }
      v15offset = ecl_car(v14param_and_offset);
      v16param = ecl_cdr(v14param_and_offset);
      if (!(ecl_eql(v16param,VV[17]))) { goto L19; }
      if (!(v5args==ECL_NIL)) { goto L24; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v15offset);
L24:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L26; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L26:;
      {
       cl_object v17;
       v17 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L31; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v5args = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L31:;
       value0 = v17;
      }
      if ((value0)!=ECL_NIL) { goto L22; }
      v10d = ecl_make_fixnum(2);
      goto L6;
L22:;
      v10d = value0;
      goto L6;
L19:;
      if (!(ecl_eql(v16param,VV[18]))) { goto L37; }
      v10d = ecl_make_fixnum(ecl_length(v5args));
      goto L6;
L37:;
      if (!((v16param)==(ECL_NIL))) { goto L39; }
      v10d = ecl_make_fixnum(2);
      goto L6;
L39:;
      v10d = v16param;
     }
L6:;
     {
      cl_object v14param_and_offset;
      cl_object v15offset;
      cl_object v16param;
      {
       cl_object v17;
       v17 = v9;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L47; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v9 = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L47:;
       v14param_and_offset = v17;
      }
      v15offset = ecl_car(v14param_and_offset);
      v16param = ecl_cdr(v14param_and_offset);
      if (!(ecl_eql(v16param,VV[17]))) { goto L55; }
      if (!(v5args==ECL_NIL)) { goto L60; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v15offset);
L60:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L62; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L62:;
      {
       cl_object v17;
       v17 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L67; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v5args = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L67:;
       value0 = v17;
      }
      if ((value0)!=ECL_NIL) { goto L58; }
      v11n = ecl_make_fixnum(1);
      goto L42;
L58:;
      v11n = value0;
      goto L42;
L55:;
      if (!(ecl_eql(v16param,VV[18]))) { goto L73; }
      v11n = ecl_make_fixnum(ecl_length(v5args));
      goto L42;
L73:;
      if (!((v16param)==(ECL_NIL))) { goto L75; }
      v11n = ecl_make_fixnum(1);
      goto L42;
L75:;
      v11n = v16param;
     }
L42:;
     {
      cl_object v14param_and_offset;
      cl_object v15offset;
      cl_object v16param;
      {
       cl_object v17;
       v17 = v9;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L83; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v9 = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L83:;
       v14param_and_offset = v17;
      }
      v15offset = ecl_car(v14param_and_offset);
      v16param = ecl_cdr(v14param_and_offset);
      if (!(ecl_eql(v16param,VV[17]))) { goto L91; }
      if (!(v5args==ECL_NIL)) { goto L96; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v15offset);
L96:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L98; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L98:;
      {
       cl_object v17;
       v17 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L103; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v5args = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L103:;
       value0 = v17;
      }
      if ((value0)!=ECL_NIL) { goto L94; }
      v12w = ecl_make_fixnum(0);
      goto L78;
L94:;
      v12w = value0;
      goto L78;
L91:;
      if (!(ecl_eql(v16param,VV[18]))) { goto L109; }
      v12w = ecl_make_fixnum(ecl_length(v5args));
      goto L78;
L109:;
      if (!((v16param)==(ECL_NIL))) { goto L111; }
      v12w = ecl_make_fixnum(0);
      goto L78;
L111:;
      v12w = v16param;
     }
L78:;
     {
      cl_object v14param_and_offset;
      cl_object v15offset;
      cl_object v16param;
      {
       cl_object v17;
       v17 = v9;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L119; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v9 = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L119:;
       v14param_and_offset = v17;
      }
      v15offset = ecl_car(v14param_and_offset);
      v16param = ecl_cdr(v14param_and_offset);
      if (!(ecl_eql(v16param,VV[17]))) { goto L127; }
      if (!(v5args==ECL_NIL)) { goto L132; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v15offset);
L132:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L134; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L134:;
      {
       cl_object v17;
       v17 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L139; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v5args = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L139:;
       value0 = v17;
      }
      if ((value0)!=ECL_NIL) { goto L130; }
      v13pad = CODE_CHAR(32);
      goto L114;
L130:;
      v13pad = value0;
      goto L114;
L127:;
      if (!(ecl_eql(v16param,VV[18]))) { goto L145; }
      v13pad = ecl_make_fixnum(ecl_length(v5args));
      goto L114;
L145:;
      if (!((v16param)==(ECL_NIL))) { goto L147; }
      v13pad = CODE_CHAR(32);
      goto L114;
L147:;
      v13pad = v16param;
     }
L114:;
     if (Null(v9)) { goto L150; }
     T0 = ecl_list1(ecl_make_fixnum(4));
     T1 = ecl_caar(v9);
     cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T0, ECL_SYM("OFFSET",1279), T1);
L150:;
     if (!(v5args==ECL_NIL)) { goto L152; }
     cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L152:;
     if (Null(ecl_symbol_value(VV[25]))) { goto L154; }
     ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L154:;
     {
      cl_object v14;
      v14 = v5args;
      if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
      if (Null(v14)) { goto L160; }
      {
       cl_object v15;
       v15 = ECL_CONS_CDR(v14);
       v5args = v15;
       v14 = ECL_CONS_CAR(v14);
      }
L160:;
      T0 = v14;
     }
     si_format_dollars(8, v1stream, T0, v10d, v11n, v12w, v13pad, v6, v7);
    }
   }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5args;
   cl_env_copy->values[0] = v3;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for FORMAT-DOLLARS                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_format_dollars(cl_narg narg, cl_object v1stream, cl_object v2number, cl_object v3d, cl_object v4n, cl_object v5w, cl_object v6pad, cl_object v7colon, cl_object v8atsign, ...)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg!=8)) FEwrong_num_arguments_anonym();
 {
TTL:
  if (Null(cl_rationalp(v2number))) { goto L1; }
  v2number = ecl_make_single_float(ecl_to_float(v2number));
L1:;
  if (!(floatp(v2number))) { goto L4; }
  {
   cl_object v9signstr;
   cl_fixnum v10signlen;
   if (!(ecl_minusp(v2number))) { goto L7; }
   v9signstr = _ecl_static_21;
   goto L6;
L7:;
   if (Null(v8atsign)) { goto L9; }
   v9signstr = _ecl_static_22;
   goto L6;
L9:;
   v9signstr = _ecl_static_36;
L6:;
   v10signlen = ecl_length(v9signstr);
   {
    cl_object v12;                                /*  STR             */
    cl_object v13;                                /*  STRLEN          */
    cl_object v14;                                /*  POINTPLACE      */
    value0 = L1flonum_to_string(4, v2number, ECL_NIL, v3d, ECL_NIL);
    v12 = value0;
    {
     const int v15 = cl_env_copy->nvalues;
     cl_object v16;
     v16 = (v15<=1)? ECL_NIL : cl_env_copy->values[1];
     v13 = v16;
     v16 = (v15<=4)? ECL_NIL : cl_env_copy->values[4];
     v14 = v16;
    }
    if (Null(v7colon)) { goto L13; }
    cl_write_string(2, v9signstr, v1stream);
L13:;
    {
     cl_object v15;
     T0 = ecl_minus(v5w,ecl_make_fixnum(v10signlen));
     T1 = ecl_minus(v4n,v14);
     T2 = (ecl_number_compare(ecl_make_fixnum(0),T1)>=0?ecl_make_fixnum(0):T1);
     T3 = ecl_minus(T0,T2);
     v15 = ecl_minus(T3,v13);
     {
      cl_object v16i;
      v16i = ecl_make_fixnum(0);
      goto L19;
L18:;
      cl_write_char(2, v6pad, v1stream);
      v16i = ecl_one_plus(v16i);
L19:;
      if (!(ecl_number_compare(v16i,v15)<0)) { goto L24; }
      goto L18;
L24:;
     }
    }
    if ((v7colon)!=ECL_NIL) { goto L26; }
    cl_write_string(2, v9signstr, v1stream);
L26:;
    {
     cl_object v15;
     v15 = ecl_minus(v4n,v14);
     {
      cl_object v16i;
      v16i = ecl_make_fixnum(0);
      goto L32;
L31:;
      cl_write_char(2, CODE_CHAR(48), v1stream);
      v16i = ecl_one_plus(v16i);
L32:;
      if (!(ecl_number_compare(v16i,v15)<0)) { goto L37; }
      goto L31;
L37:;
     }
    }
    value0 = cl_write_string(2, v12, v1stream);
    return value0;
   }
  }
L4:;
  T0 = L48decimal_string(v2number);
  value0 = L22format_write_field(v1stream, T0, v5w, ecl_make_fixnum(1), ecl_make_fixnum(0), CODE_CHAR(32), ECL_T);
  return value0;
 }
}
/*	local function G1216                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC61__g1216(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   v3 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v1) /*  FORMAT-DIRECTIVE-COLONP */;
   v4 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v1) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v5 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v1) /*  FORMAT-DIRECTIVE-PARAMS */;
   if ((v3)!=ECL_NIL) { goto L6; }
   if (Null(v4)) { goto L4; }
   goto L5;
L6:;
L5:;
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_37);
L4:;
   if (Null(v5)) { goto L9; }
   {
    cl_object v6;
    v6 = v5;
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L17; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L17:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L25; }
     T2 = L14expand_next_arg(1, v8offset);
     T1 = cl_list(3, ECL_SYM("OR",614), T2, ecl_make_fixnum(1));
     goto L12;
L25:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L27; }
     cl_set(VV[28],ECL_NIL);
     T1 = VV[54];
     goto L12;
L27:;
     if (!((v9param)==(ECL_NIL))) { goto L31; }
     T1 = ecl_make_fixnum(1);
     goto L12;
L31:;
     T1 = v9param;
    }
L12:;
    T2 = cl_list(2, VV[133], T1);
    T3 = ecl_list1(T2);
    if (Null(v6)) { goto L35; }
    T5 = ecl_list1(ecl_make_fixnum(1));
    T6 = ecl_caar(v6);
    T4 = cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T5, ECL_SYM("OFFSET",1279), T6);
    goto L34;
L35:;
    T4 = ECL_NIL;
L34:;
    T5 = cl_list(2, VV[134], VV[133]);
    T6 = cl_list(3, ECL_SYM("DOTIMES",314), T5, VV[135]);
    T7 = ecl_list1(T6);
    T8 = ecl_append(T4,T7);
    T0 = cl_listX(3, ECL_SYM("LET",477), T3, T8);
    goto L8;
   }
L9:;
   T0 = VV[135];
L8:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v2;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G1229                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC62__g1229(cl_object v1stream, cl_object v2, cl_object v3, cl_object v4orig_args, cl_object v5args)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6;
   cl_object v7;
   cl_object v8;
   v6 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v2) /*  FORMAT-DIRECTIVE-COLONP */;
   v7 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v2) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v8 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v2) /*  FORMAT-DIRECTIVE-PARAMS */;
   if ((v6)!=ECL_NIL) { goto L6; }
   if (Null(v7)) { goto L4; }
   goto L5;
L6:;
L5:;
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_37);
L4:;
   {
    cl_object v9;
    v9 = v8;
    {
     cl_object v10count;
     {
      cl_object v11param_and_offset;
      cl_object v12offset;
      cl_object v13param;
      {
       cl_object v14;
       v14 = v9;
       if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
       if (Null(v14)) { goto L15; }
       {
        cl_object v15;
        v15 = ECL_CONS_CDR(v14);
        v9 = v15;
        v14 = ECL_CONS_CAR(v14);
       }
L15:;
       v11param_and_offset = v14;
      }
      v12offset = ecl_car(v11param_and_offset);
      v13param = ecl_cdr(v11param_and_offset);
      if (!(ecl_eql(v13param,VV[17]))) { goto L23; }
      if (!(v5args==ECL_NIL)) { goto L28; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v12offset);
L28:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L30; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L30:;
      {
       cl_object v14;
       v14 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
       if (Null(v14)) { goto L35; }
       {
        cl_object v15;
        v15 = ECL_CONS_CDR(v14);
        v5args = v15;
        v14 = ECL_CONS_CAR(v14);
       }
L35:;
       value0 = v14;
      }
      if ((value0)!=ECL_NIL) { goto L26; }
      v10count = ecl_make_fixnum(1);
      goto L10;
L26:;
      v10count = value0;
      goto L10;
L23:;
      if (!(ecl_eql(v13param,VV[18]))) { goto L41; }
      v10count = ecl_make_fixnum(ecl_length(v5args));
      goto L10;
L41:;
      if (!((v13param)==(ECL_NIL))) { goto L43; }
      v10count = ecl_make_fixnum(1);
      goto L10;
L43:;
      v10count = v13param;
     }
L10:;
     if (Null(v9)) { goto L46; }
     T0 = ecl_list1(ecl_make_fixnum(1));
     T1 = ecl_caar(v9);
     cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T0, ECL_SYM("OFFSET",1279), T1);
L46:;
     {
      cl_object v11i;
      v11i = ecl_make_fixnum(0);
      goto L50;
L49:;
      ecl_terpri(v1stream);
      v11i = ecl_one_plus(v11i);
L50:;
      if (!(ecl_number_compare(v11i,v10count)<0)) { goto L55; }
      goto L49;
L55:;
     }
    }
   }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5args;
   cl_env_copy->values[0] = v3;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G1247                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC63__g1247(cl_object v1, cl_object v2)
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
   v3 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v1) /*  FORMAT-DIRECTIVE-COLONP */;
   v4 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v1) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v5 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v1) /*  FORMAT-DIRECTIVE-PARAMS */;
   if ((v3)!=ECL_NIL) { goto L6; }
   if (Null(v4)) { goto L4; }
   goto L5;
L6:;
L5:;
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_37);
L4:;
   if (Null(v5)) { goto L9; }
   {
    cl_object v6;
    v6 = v5;
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L17; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L17:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L25; }
     T2 = L14expand_next_arg(1, v8offset);
     T1 = cl_list(3, ECL_SYM("OR",614), T2, ecl_make_fixnum(1));
     goto L12;
L25:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L27; }
     cl_set(VV[28],ECL_NIL);
     T1 = VV[54];
     goto L12;
L27:;
     if (!((v9param)==(ECL_NIL))) { goto L31; }
     T1 = ecl_make_fixnum(1);
     goto L12;
L31:;
     T1 = v9param;
    }
L12:;
    T2 = cl_list(2, VV[136], T1);
    T3 = ecl_list1(T2);
    if (Null(v6)) { goto L35; }
    T5 = ecl_list1(ecl_make_fixnum(1));
    T6 = ecl_caar(v6);
    T4 = cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T5, ECL_SYM("OFFSET",1279), T6);
    goto L34;
L35:;
    T4 = ECL_NIL;
L34:;
    T5 = cl_list(2, ECL_SYM("1-",71), VV[136]);
    T6 = cl_list(2, VV[134], T5);
    T7 = cl_list(3, ECL_SYM("DOTIMES",314), T6, VV[135]);
    T8 = cl_list(3, ECL_SYM("PROGN",671), VV[137], T7);
    T9 = ecl_list1(T8);
    T10 = ecl_append(T4,T9);
    T0 = cl_listX(3, ECL_SYM("LET",477), T3, T10);
    goto L8;
   }
L9:;
   T0 = VV[137];
L8:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v2;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G1260                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC64__g1260(cl_object v1stream, cl_object v2, cl_object v3, cl_object v4orig_args, cl_object v5args)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6;
   cl_object v7;
   cl_object v8;
   v6 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v2) /*  FORMAT-DIRECTIVE-COLONP */;
   v7 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v2) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v8 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v2) /*  FORMAT-DIRECTIVE-PARAMS */;
   if ((v6)!=ECL_NIL) { goto L6; }
   if (Null(v7)) { goto L4; }
   goto L5;
L6:;
L5:;
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_37);
L4:;
   {
    cl_object v9;
    v9 = v8;
    {
     cl_object v10count;
     {
      cl_object v11param_and_offset;
      cl_object v12offset;
      cl_object v13param;
      {
       cl_object v14;
       v14 = v9;
       if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
       if (Null(v14)) { goto L15; }
       {
        cl_object v15;
        v15 = ECL_CONS_CDR(v14);
        v9 = v15;
        v14 = ECL_CONS_CAR(v14);
       }
L15:;
       v11param_and_offset = v14;
      }
      v12offset = ecl_car(v11param_and_offset);
      v13param = ecl_cdr(v11param_and_offset);
      if (!(ecl_eql(v13param,VV[17]))) { goto L23; }
      if (!(v5args==ECL_NIL)) { goto L28; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v12offset);
L28:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L30; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L30:;
      {
       cl_object v14;
       v14 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
       if (Null(v14)) { goto L35; }
       {
        cl_object v15;
        v15 = ECL_CONS_CDR(v14);
        v5args = v15;
        v14 = ECL_CONS_CAR(v14);
       }
L35:;
       value0 = v14;
      }
      if ((value0)!=ECL_NIL) { goto L26; }
      v10count = ecl_make_fixnum(1);
      goto L10;
L26:;
      v10count = value0;
      goto L10;
L23:;
      if (!(ecl_eql(v13param,VV[18]))) { goto L41; }
      v10count = ecl_make_fixnum(ecl_length(v5args));
      goto L10;
L41:;
      if (!((v13param)==(ECL_NIL))) { goto L43; }
      v10count = ecl_make_fixnum(1);
      goto L10;
L43:;
      v10count = v13param;
     }
L10:;
     if (Null(v9)) { goto L46; }
     T0 = ecl_list1(ecl_make_fixnum(1));
     T1 = ecl_caar(v9);
     cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T0, ECL_SYM("OFFSET",1279), T1);
L46:;
     cl_fresh_line(1, v1stream);
     {
      cl_object v11;
      v11 = ecl_one_minus(v10count);
      {
       cl_object v12i;
       v12i = ecl_make_fixnum(0);
       goto L52;
L51:;
       ecl_terpri(v1stream);
       v12i = ecl_one_plus(v12i);
L52:;
       if (!(ecl_number_compare(v12i,v11)<0)) { goto L57; }
       goto L51;
L57:;
      }
     }
    }
   }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5args;
   cl_env_copy->values[0] = v3;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G1278                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC65__g1278(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   v3 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v1) /*  FORMAT-DIRECTIVE-COLONP */;
   v4 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v1) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v5 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v1) /*  FORMAT-DIRECTIVE-PARAMS */;
   if ((v3)!=ECL_NIL) { goto L6; }
   if (Null(v4)) { goto L4; }
   goto L5;
L6:;
L5:;
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_37);
L4:;
   if (Null(v5)) { goto L9; }
   {
    cl_object v6;
    v6 = v5;
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L17; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L17:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L25; }
     T2 = L14expand_next_arg(1, v8offset);
     T1 = cl_list(3, ECL_SYM("OR",614), T2, ecl_make_fixnum(1));
     goto L12;
L25:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L27; }
     cl_set(VV[28],ECL_NIL);
     T1 = VV[54];
     goto L12;
L27:;
     if (!((v9param)==(ECL_NIL))) { goto L31; }
     T1 = ecl_make_fixnum(1);
     goto L12;
L31:;
     T1 = v9param;
    }
L12:;
    T2 = cl_list(2, VV[138], T1);
    T3 = ecl_list1(T2);
    if (Null(v6)) { goto L35; }
    T5 = ecl_list1(ecl_make_fixnum(1));
    T6 = ecl_caar(v6);
    T4 = cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T5, ECL_SYM("OFFSET",1279), T6);
    goto L34;
L35:;
    T4 = ECL_NIL;
L34:;
    T5 = cl_list(2, VV[134], VV[138]);
    T6 = cl_list(3, ECL_SYM("DOTIMES",314), T5, VV[139]);
    T7 = ecl_list1(T6);
    T8 = ecl_append(T4,T7);
    T0 = cl_listX(3, ECL_SYM("LET",477), T3, T8);
    goto L8;
   }
L9:;
   T0 = VV[139];
L8:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v2;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G1291                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC66__g1291(cl_object v1stream, cl_object v2, cl_object v3, cl_object v4orig_args, cl_object v5args)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6;
   cl_object v7;
   cl_object v8;
   v6 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v2) /*  FORMAT-DIRECTIVE-COLONP */;
   v7 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v2) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v8 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v2) /*  FORMAT-DIRECTIVE-PARAMS */;
   if ((v6)!=ECL_NIL) { goto L6; }
   if (Null(v7)) { goto L4; }
   goto L5;
L6:;
L5:;
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_37);
L4:;
   {
    cl_object v9;
    v9 = v8;
    {
     cl_object v10count;
     {
      cl_object v11param_and_offset;
      cl_object v12offset;
      cl_object v13param;
      {
       cl_object v14;
       v14 = v9;
       if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
       if (Null(v14)) { goto L15; }
       {
        cl_object v15;
        v15 = ECL_CONS_CDR(v14);
        v9 = v15;
        v14 = ECL_CONS_CAR(v14);
       }
L15:;
       v11param_and_offset = v14;
      }
      v12offset = ecl_car(v11param_and_offset);
      v13param = ecl_cdr(v11param_and_offset);
      if (!(ecl_eql(v13param,VV[17]))) { goto L23; }
      if (!(v5args==ECL_NIL)) { goto L28; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v12offset);
L28:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L30; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L30:;
      {
       cl_object v14;
       v14 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
       if (Null(v14)) { goto L35; }
       {
        cl_object v15;
        v15 = ECL_CONS_CDR(v14);
        v5args = v15;
        v14 = ECL_CONS_CAR(v14);
       }
L35:;
       value0 = v14;
      }
      if ((value0)!=ECL_NIL) { goto L26; }
      v10count = ecl_make_fixnum(1);
      goto L10;
L26:;
      v10count = value0;
      goto L10;
L23:;
      if (!(ecl_eql(v13param,VV[18]))) { goto L41; }
      v10count = ecl_make_fixnum(ecl_length(v5args));
      goto L10;
L41:;
      if (!((v13param)==(ECL_NIL))) { goto L43; }
      v10count = ecl_make_fixnum(1);
      goto L10;
L43:;
      v10count = v13param;
     }
L10:;
     if (Null(v9)) { goto L46; }
     T0 = ecl_list1(ecl_make_fixnum(1));
     T1 = ecl_caar(v9);
     cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T0, ECL_SYM("OFFSET",1279), T1);
L46:;
     {
      cl_object v11i;
      v11i = ecl_make_fixnum(0);
      goto L50;
L49:;
      cl_write_char(2, CODE_CHAR(12), v1stream);
      v11i = ecl_one_plus(v11i);
L50:;
      if (!(ecl_number_compare(v11i,v10count)<0)) { goto L55; }
      goto L49;
L55:;
     }
    }
   }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5args;
   cl_env_copy->values[0] = v3;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G1309                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC67__g1309(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   v3 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v1) /*  FORMAT-DIRECTIVE-COLONP */;
   v4 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v1) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v5 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v1) /*  FORMAT-DIRECTIVE-PARAMS */;
   if ((v3)!=ECL_NIL) { goto L6; }
   if (Null(v4)) { goto L4; }
   goto L5;
L6:;
L5:;
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_37);
L4:;
   if (Null(v5)) { goto L9; }
   {
    cl_object v6;
    v6 = v5;
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L17; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L17:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L25; }
     T2 = L14expand_next_arg(1, v8offset);
     T1 = cl_list(3, ECL_SYM("OR",614), T2, ecl_make_fixnum(1));
     goto L12;
L25:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L27; }
     cl_set(VV[28],ECL_NIL);
     T1 = VV[54];
     goto L12;
L27:;
     if (!((v9param)==(ECL_NIL))) { goto L31; }
     T1 = ecl_make_fixnum(1);
     goto L12;
L31:;
     T1 = v9param;
    }
L12:;
    T2 = cl_list(2, VV[140], T1);
    T3 = ecl_list1(T2);
    if (Null(v6)) { goto L35; }
    T5 = ecl_list1(ecl_make_fixnum(1));
    T6 = ecl_caar(v6);
    T4 = cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T5, ECL_SYM("OFFSET",1279), T6);
    goto L34;
L35:;
    T4 = ECL_NIL;
L34:;
    T5 = cl_list(2, VV[134], VV[140]);
    T6 = cl_list(3, ECL_SYM("DOTIMES",314), T5, VV[141]);
    T7 = ecl_list1(T6);
    T8 = ecl_append(T4,T7);
    T0 = cl_listX(3, ECL_SYM("LET",477), T3, T8);
    goto L8;
   }
L9:;
   T0 = VV[141];
L8:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v2;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G1322                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC68__g1322(cl_object v1stream, cl_object v2, cl_object v3, cl_object v4orig_args, cl_object v5args)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6;
   cl_object v7;
   cl_object v8;
   v6 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v2) /*  FORMAT-DIRECTIVE-COLONP */;
   v7 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v2) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v8 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v2) /*  FORMAT-DIRECTIVE-PARAMS */;
   if ((v6)!=ECL_NIL) { goto L6; }
   if (Null(v7)) { goto L4; }
   goto L5;
L6:;
L5:;
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_37);
L4:;
   {
    cl_object v9;
    v9 = v8;
    {
     cl_object v10count;
     {
      cl_object v11param_and_offset;
      cl_object v12offset;
      cl_object v13param;
      {
       cl_object v14;
       v14 = v9;
       if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
       if (Null(v14)) { goto L15; }
       {
        cl_object v15;
        v15 = ECL_CONS_CDR(v14);
        v9 = v15;
        v14 = ECL_CONS_CAR(v14);
       }
L15:;
       v11param_and_offset = v14;
      }
      v12offset = ecl_car(v11param_and_offset);
      v13param = ecl_cdr(v11param_and_offset);
      if (!(ecl_eql(v13param,VV[17]))) { goto L23; }
      if (!(v5args==ECL_NIL)) { goto L28; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v12offset);
L28:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L30; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L30:;
      {
       cl_object v14;
       v14 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
       if (Null(v14)) { goto L35; }
       {
        cl_object v15;
        v15 = ECL_CONS_CDR(v14);
        v5args = v15;
        v14 = ECL_CONS_CAR(v14);
       }
L35:;
       value0 = v14;
      }
      if ((value0)!=ECL_NIL) { goto L26; }
      v10count = ecl_make_fixnum(1);
      goto L10;
L26:;
      v10count = value0;
      goto L10;
L23:;
      if (!(ecl_eql(v13param,VV[18]))) { goto L41; }
      v10count = ecl_make_fixnum(ecl_length(v5args));
      goto L10;
L41:;
      if (!((v13param)==(ECL_NIL))) { goto L43; }
      v10count = ecl_make_fixnum(1);
      goto L10;
L43:;
      v10count = v13param;
     }
L10:;
     if (Null(v9)) { goto L46; }
     T0 = ecl_list1(ecl_make_fixnum(1));
     T1 = ecl_caar(v9);
     cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T0, ECL_SYM("OFFSET",1279), T1);
L46:;
     {
      cl_object v11i;
      v11i = ecl_make_fixnum(0);
      goto L50;
L49:;
      cl_write_char(2, CODE_CHAR(126), v1stream);
      v11i = ecl_one_plus(v11i);
L50:;
      if (!(ecl_number_compare(v11i,v10count)<0)) { goto L55; }
      goto L49;
L55:;
     }
    }
   }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5args;
   cl_env_copy->values[0] = v3;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G1339                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC69__g1339(cl_object v1, cl_object v2directives)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   v3 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v1) /*  FORMAT-DIRECTIVE-COLONP */;
   v4 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v1) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v5 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v1) /*  FORMAT-DIRECTIVE-PARAMS */;
   if (Null(v3)) { goto L4; }
   if (Null(v4)) { goto L4; }
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_38);
L4:;
   if (Null(v5)) { goto L8; }
   T1 = ecl_caar(v5);
   cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_20, ECL_SYM("OFFSET",1279), T1);
L8:;
   if (Null(v4)) { goto L10; }
   T0 = VV[142];
   goto L7;
L10:;
   T0 = ECL_NIL;
L7:;
   if ((v3)!=ECL_NIL) { goto L13; }
   if (Null(v2directives)) { goto L13; }
   T2 = ecl_car(v2directives);
   if (Null(cl_simple_string_p(T2))) { goto L13; }
   T2 = ecl_car(v2directives);
   T3 = cl_string_left_trim(VV[143], T2);
   T4 = ecl_cdr(v2directives);
   T1 = CONS(T3,T4);
   goto L12;
L13:;
   T1 = v2directives;
L12:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = T1;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G1345                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC70__g1345(cl_object v1stream, cl_object v2, cl_object v3directives, cl_object v4orig_args, cl_object v5args)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6;
   cl_object v7;
   cl_object v8;
   v6 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v2) /*  FORMAT-DIRECTIVE-COLONP */;
   v7 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v2) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v8 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v2) /*  FORMAT-DIRECTIVE-PARAMS */;
   if (Null(v6)) { goto L4; }
   if (Null(v7)) { goto L4; }
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_38);
L4:;
   if (Null(v8)) { goto L8; }
   T0 = ecl_list1(ecl_make_fixnum(0));
   T1 = ecl_caar(v8);
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T0, ECL_SYM("OFFSET",1279), T1);
L8:;
   if (Null(v7)) { goto L7; }
   cl_write_char(2, CODE_CHAR(10), v1stream);
L7:;
   if ((v6)!=ECL_NIL) { goto L12; }
   if (Null(v3directives)) { goto L12; }
   T1 = ecl_car(v3directives);
   if (Null(cl_simple_string_p(T1))) { goto L12; }
   T1 = ecl_car(v3directives);
   T2 = cl_string_left_trim(VV[143], T1);
   T3 = ecl_cdr(v3directives);
   T0 = CONS(T2,T3);
   goto L11;
L12:;
   T0 = v3directives;
L11:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5args;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G1351                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC71__g1351(cl_object v1, cl_object v2directives)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   v3 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v1) /*  FORMAT-DIRECTIVE-COLONP */;
   v4 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v1) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v5 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v1) /*  FORMAT-DIRECTIVE-PARAMS */;
   if (Null(v3)) { goto L4; }
   if (Null(v4)) { goto L4; }
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_38);
L4:;
   if (Null(v5)) { goto L8; }
   T1 = ecl_caar(v5);
   cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_20, ECL_SYM("OFFSET",1279), T1);
L8:;
   if (Null(v4)) { goto L10; }
   T0 = VV[142];
   goto L7;
L10:;
   T0 = ECL_NIL;
L7:;
   if ((v3)!=ECL_NIL) { goto L13; }
   if (Null(v2directives)) { goto L13; }
   T2 = ecl_car(v2directives);
   if (Null(cl_simple_string_p(T2))) { goto L13; }
   T2 = ecl_car(v2directives);
   T3 = cl_string_left_trim(VV[143], T2);
   T4 = ecl_cdr(v2directives);
   T1 = CONS(T3,T4);
   goto L12;
L13:;
   T1 = v2directives;
L12:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = T1;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G1357                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC72__g1357(cl_object v1stream, cl_object v2, cl_object v3directives, cl_object v4orig_args, cl_object v5args)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6;
   cl_object v7;
   cl_object v8;
   v6 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v2) /*  FORMAT-DIRECTIVE-COLONP */;
   v7 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v2) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v8 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v2) /*  FORMAT-DIRECTIVE-PARAMS */;
   if (Null(v6)) { goto L4; }
   if (Null(v7)) { goto L4; }
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_38);
L4:;
   if (Null(v8)) { goto L8; }
   T0 = ecl_list1(ecl_make_fixnum(0));
   T1 = ecl_caar(v8);
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T0, ECL_SYM("OFFSET",1279), T1);
L8:;
   if (Null(v7)) { goto L7; }
   cl_write_char(2, CODE_CHAR(10), v1stream);
L7:;
   if ((v6)!=ECL_NIL) { goto L12; }
   if (Null(v3directives)) { goto L12; }
   T1 = ecl_car(v3directives);
   if (Null(cl_simple_string_p(T1))) { goto L12; }
   T1 = ecl_car(v3directives);
   T2 = cl_string_left_trim(VV[143], T1);
   T3 = ecl_cdr(v3directives);
   T0 = CONS(T2,T3);
   goto L11;
L12:;
   T0 = v3directives;
L11:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5args;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G1364                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC73__g1364(cl_object v1, cl_object v2)
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
   v3 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v1) /*  FORMAT-DIRECTIVE-COLONP */;
   v4 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v1) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v5 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v1) /*  FORMAT-DIRECTIVE-PARAMS */;
   L115check_output_layout_mode(ecl_make_fixnum(1));
   if (Null(v3)) { goto L6; }
   {
    cl_object v6;
    v6 = v5;
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L14; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L14:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L22; }
     T2 = L14expand_next_arg(1, v8offset);
     T1 = cl_list(3, ECL_SYM("OR",614), T2, ecl_make_fixnum(1));
     goto L9;
L22:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L24; }
     cl_set(VV[28],ECL_NIL);
     T1 = VV[54];
     goto L9;
L24:;
     if (!((v9param)==(ECL_NIL))) { goto L28; }
     T1 = ecl_make_fixnum(1);
     goto L9;
L28:;
     T1 = v9param;
    }
L9:;
    T2 = cl_list(2, VV[144], T1);
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L36; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L36:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L44; }
     T4 = L14expand_next_arg(1, v8offset);
     T3 = cl_list(3, ECL_SYM("OR",614), T4, ecl_make_fixnum(1));
     goto L31;
L44:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L46; }
     cl_set(VV[28],ECL_NIL);
     T3 = VV[54];
     goto L31;
L46:;
     if (!((v9param)==(ECL_NIL))) { goto L50; }
     T3 = ecl_make_fixnum(1);
     goto L31;
L50:;
     T3 = v9param;
    }
L31:;
    T4 = cl_list(2, VV[145], T3);
    T5 = cl_list(2, T2, T4);
    if (Null(v6)) { goto L54; }
    T7 = ecl_list1(ecl_make_fixnum(2));
    T8 = ecl_caar(v6);
    T6 = cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T7, ECL_SYM("OFFSET",1279), T8);
    goto L53;
L54:;
    T6 = ECL_NIL;
L53:;
    if (Null(v4)) { goto L57; }
    T7 = VV[146];
    goto L56;
L57:;
    T7 = VV[147];
L56:;
    T8 = cl_list(5, ECL_SYM("PPRINT-TAB",656), T7, VV[144], VV[145], ECL_SYM("STREAM",799));
    T9 = ecl_list1(T8);
    T10 = ecl_append(T6,T9);
    T0 = cl_listX(3, ECL_SYM("LET",477), T5, T10);
    goto L5;
   }
L6:;
   if (Null(v4)) { goto L59; }
   {
    cl_object v7;
    v7 = v5;
    {
     cl_object v8param_and_offset;
     cl_object v9offset;
     cl_object v10param;
     {
      cl_object v11;
      v11 = v7;
      if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
      if (Null(v11)) { goto L67; }
      {
       cl_object v12;
       v12 = ECL_CONS_CDR(v11);
       v7 = v12;
       v11 = ECL_CONS_CAR(v11);
      }
L67:;
      v8param_and_offset = v11;
     }
     v9offset = ecl_car(v8param_and_offset);
     v10param = ecl_cdr(v8param_and_offset);
     if (!(ecl_eql(v10param,VV[17]))) { goto L75; }
     T2 = L14expand_next_arg(1, v9offset);
     T1 = cl_list(3, ECL_SYM("OR",614), T2, ecl_make_fixnum(1));
     goto L62;
L75:;
     if (!(ecl_eql(v10param,VV[18]))) { goto L77; }
     cl_set(VV[28],ECL_NIL);
     T1 = VV[54];
     goto L62;
L77:;
     if (!((v10param)==(ECL_NIL))) { goto L81; }
     T1 = ecl_make_fixnum(1);
     goto L62;
L81:;
     T1 = v10param;
    }
L62:;
    T2 = cl_list(2, VV[148], T1);
    {
     cl_object v8param_and_offset;
     cl_object v9offset;
     cl_object v10param;
     {
      cl_object v11;
      v11 = v7;
      if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
      if (Null(v11)) { goto L89; }
      {
       cl_object v12;
       v12 = ECL_CONS_CDR(v11);
       v7 = v12;
       v11 = ECL_CONS_CAR(v11);
      }
L89:;
      v8param_and_offset = v11;
     }
     v9offset = ecl_car(v8param_and_offset);
     v10param = ecl_cdr(v8param_and_offset);
     if (!(ecl_eql(v10param,VV[17]))) { goto L97; }
     T4 = L14expand_next_arg(1, v9offset);
     T3 = cl_list(3, ECL_SYM("OR",614), T4, ecl_make_fixnum(1));
     goto L84;
L97:;
     if (!(ecl_eql(v10param,VV[18]))) { goto L99; }
     cl_set(VV[28],ECL_NIL);
     T3 = VV[54];
     goto L84;
L99:;
     if (!((v10param)==(ECL_NIL))) { goto L103; }
     T3 = ecl_make_fixnum(1);
     goto L84;
L103:;
     T3 = v10param;
    }
L84:;
    T4 = cl_list(2, VV[149], T3);
    T5 = cl_list(2, T2, T4);
    if (Null(v7)) { goto L107; }
    T7 = ecl_list1(ecl_make_fixnum(2));
    T8 = ecl_caar(v7);
    T6 = cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T7, ECL_SYM("OFFSET",1279), T8);
    goto L106;
L107:;
    T6 = ECL_NIL;
L106:;
    T7 = cl_list(4, VV[150], ECL_SYM("STREAM",799), VV[148], VV[149]);
    T8 = ecl_list1(T7);
    T9 = ecl_append(T6,T8);
    T0 = cl_listX(3, ECL_SYM("LET",477), T5, T9);
    goto L5;
   }
L59:;
   {
    cl_object v8;
    v8 = v5;
    {
     cl_object v9param_and_offset;
     cl_object v10offset;
     cl_object v11param;
     {
      cl_object v12;
      v12 = v8;
      if (ecl_unlikely(!ECL_LISTP(v12))) FEtype_error_list(v12);
      if (Null(v12)) { goto L115; }
      {
       cl_object v13;
       v13 = ECL_CONS_CDR(v12);
       v8 = v13;
       v12 = ECL_CONS_CAR(v12);
      }
L115:;
      v9param_and_offset = v12;
     }
     v10offset = ecl_car(v9param_and_offset);
     v11param = ecl_cdr(v9param_and_offset);
     if (!(ecl_eql(v11param,VV[17]))) { goto L123; }
     T2 = L14expand_next_arg(1, v10offset);
     T1 = cl_list(3, ECL_SYM("OR",614), T2, ecl_make_fixnum(1));
     goto L110;
L123:;
     if (!(ecl_eql(v11param,VV[18]))) { goto L125; }
     cl_set(VV[28],ECL_NIL);
     T1 = VV[54];
     goto L110;
L125:;
     if (!((v11param)==(ECL_NIL))) { goto L129; }
     T1 = ecl_make_fixnum(1);
     goto L110;
L129:;
     T1 = v11param;
    }
L110:;
    T2 = cl_list(2, VV[151], T1);
    {
     cl_object v9param_and_offset;
     cl_object v10offset;
     cl_object v11param;
     {
      cl_object v12;
      v12 = v8;
      if (ecl_unlikely(!ECL_LISTP(v12))) FEtype_error_list(v12);
      if (Null(v12)) { goto L137; }
      {
       cl_object v13;
       v13 = ECL_CONS_CDR(v12);
       v8 = v13;
       v12 = ECL_CONS_CAR(v12);
      }
L137:;
      v9param_and_offset = v12;
     }
     v10offset = ecl_car(v9param_and_offset);
     v11param = ecl_cdr(v9param_and_offset);
     if (!(ecl_eql(v11param,VV[17]))) { goto L145; }
     T4 = L14expand_next_arg(1, v10offset);
     T3 = cl_list(3, ECL_SYM("OR",614), T4, ecl_make_fixnum(1));
     goto L132;
L145:;
     if (!(ecl_eql(v11param,VV[18]))) { goto L147; }
     cl_set(VV[28],ECL_NIL);
     T3 = VV[54];
     goto L132;
L147:;
     if (!((v11param)==(ECL_NIL))) { goto L151; }
     T3 = ecl_make_fixnum(1);
     goto L132;
L151:;
     T3 = v11param;
    }
L132:;
    T4 = cl_list(2, VV[152], T3);
    T5 = cl_list(2, T2, T4);
    if (Null(v8)) { goto L155; }
    T7 = ecl_list1(ecl_make_fixnum(2));
    T8 = ecl_caar(v8);
    T6 = cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T7, ECL_SYM("OFFSET",1279), T8);
    goto L154;
L155:;
    T6 = ECL_NIL;
L154:;
    T7 = cl_list(4, VV[153], ECL_SYM("STREAM",799), VV[151], VV[152]);
    T8 = ecl_list1(T7);
    T9 = ecl_append(T6,T8);
    T0 = cl_listX(3, ECL_SYM("LET",477), T5, T9);
   }
L5:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v2;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G1415                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC74__g1415(cl_object v1stream, cl_object v2, cl_object v3, cl_object v4orig_args, cl_object v5args)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6;
   cl_object v7;
   cl_object v8;
   v6 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v2) /*  FORMAT-DIRECTIVE-COLONP */;
   v7 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v2) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v8 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v2) /*  FORMAT-DIRECTIVE-PARAMS */;
   L115check_output_layout_mode(ecl_make_fixnum(1));
   if (Null(v6)) { goto L6; }
   {
    cl_object v9;
    v9 = v8;
    {
     cl_object v10n;
     cl_object v11m;
     {
      cl_object v12param_and_offset;
      cl_object v13offset;
      cl_object v14param;
      {
       cl_object v15;
       v15 = v9;
       if (ecl_unlikely(!ECL_LISTP(v15))) FEtype_error_list(v15);
       if (Null(v15)) { goto L14; }
       {
        cl_object v16;
        v16 = ECL_CONS_CDR(v15);
        v9 = v16;
        v15 = ECL_CONS_CAR(v15);
       }
L14:;
       v12param_and_offset = v15;
      }
      v13offset = ecl_car(v12param_and_offset);
      v14param = ecl_cdr(v12param_and_offset);
      if (!(ecl_eql(v14param,VV[17]))) { goto L22; }
      if (!(v5args==ECL_NIL)) { goto L27; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v13offset);
L27:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L29; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L29:;
      {
       cl_object v15;
       v15 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v15))) FEtype_error_list(v15);
       if (Null(v15)) { goto L34; }
       {
        cl_object v16;
        v16 = ECL_CONS_CDR(v15);
        v5args = v16;
        v15 = ECL_CONS_CAR(v15);
       }
L34:;
       value0 = v15;
      }
      if ((value0)!=ECL_NIL) { goto L25; }
      v10n = ecl_make_fixnum(1);
      goto L9;
L25:;
      v10n = value0;
      goto L9;
L22:;
      if (!(ecl_eql(v14param,VV[18]))) { goto L40; }
      v10n = ecl_make_fixnum(ecl_length(v5args));
      goto L9;
L40:;
      if (!((v14param)==(ECL_NIL))) { goto L42; }
      v10n = ecl_make_fixnum(1);
      goto L9;
L42:;
      v10n = v14param;
     }
L9:;
     {
      cl_object v12param_and_offset;
      cl_object v13offset;
      cl_object v14param;
      {
       cl_object v15;
       v15 = v9;
       if (ecl_unlikely(!ECL_LISTP(v15))) FEtype_error_list(v15);
       if (Null(v15)) { goto L50; }
       {
        cl_object v16;
        v16 = ECL_CONS_CDR(v15);
        v9 = v16;
        v15 = ECL_CONS_CAR(v15);
       }
L50:;
       v12param_and_offset = v15;
      }
      v13offset = ecl_car(v12param_and_offset);
      v14param = ecl_cdr(v12param_and_offset);
      if (!(ecl_eql(v14param,VV[17]))) { goto L58; }
      if (!(v5args==ECL_NIL)) { goto L63; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v13offset);
L63:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L65; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L65:;
      {
       cl_object v15;
       v15 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v15))) FEtype_error_list(v15);
       if (Null(v15)) { goto L70; }
       {
        cl_object v16;
        v16 = ECL_CONS_CDR(v15);
        v5args = v16;
        v15 = ECL_CONS_CAR(v15);
       }
L70:;
       value0 = v15;
      }
      if ((value0)!=ECL_NIL) { goto L61; }
      v11m = ecl_make_fixnum(1);
      goto L45;
L61:;
      v11m = value0;
      goto L45;
L58:;
      if (!(ecl_eql(v14param,VV[18]))) { goto L76; }
      v11m = ecl_make_fixnum(ecl_length(v5args));
      goto L45;
L76:;
      if (!((v14param)==(ECL_NIL))) { goto L78; }
      v11m = ecl_make_fixnum(1);
      goto L45;
L78:;
      v11m = v14param;
     }
L45:;
     if (Null(v9)) { goto L81; }
     T0 = ecl_list1(ecl_make_fixnum(2));
     T1 = ecl_caar(v9);
     cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T0, ECL_SYM("OFFSET",1279), T1);
L81:;
     if (Null(v7)) { goto L84; }
     T0 = VV[146];
     goto L83;
L84:;
     T0 = VV[147];
L83:;
     cl_pprint_tab(4, T0, v10n, v11m, v1stream);
     goto L5;
    }
   }
L6:;
   if (Null(v7)) { goto L86; }
   {
    cl_object v12;
    v12 = v8;
    {
     cl_object v13colrel;
     cl_object v14colinc;
     {
      cl_object v15param_and_offset;
      cl_object v16offset;
      cl_object v17param;
      {
       cl_object v18;
       v18 = v12;
       if (ecl_unlikely(!ECL_LISTP(v18))) FEtype_error_list(v18);
       if (Null(v18)) { goto L94; }
       {
        cl_object v19;
        v19 = ECL_CONS_CDR(v18);
        v12 = v19;
        v18 = ECL_CONS_CAR(v18);
       }
L94:;
       v15param_and_offset = v18;
      }
      v16offset = ecl_car(v15param_and_offset);
      v17param = ecl_cdr(v15param_and_offset);
      if (!(ecl_eql(v17param,VV[17]))) { goto L102; }
      if (!(v5args==ECL_NIL)) { goto L107; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v16offset);
L107:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L109; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L109:;
      {
       cl_object v18;
       v18 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v18))) FEtype_error_list(v18);
       if (Null(v18)) { goto L114; }
       {
        cl_object v19;
        v19 = ECL_CONS_CDR(v18);
        v5args = v19;
        v18 = ECL_CONS_CAR(v18);
       }
L114:;
       value0 = v18;
      }
      if ((value0)!=ECL_NIL) { goto L105; }
      v13colrel = ecl_make_fixnum(1);
      goto L89;
L105:;
      v13colrel = value0;
      goto L89;
L102:;
      if (!(ecl_eql(v17param,VV[18]))) { goto L120; }
      v13colrel = ecl_make_fixnum(ecl_length(v5args));
      goto L89;
L120:;
      if (!((v17param)==(ECL_NIL))) { goto L122; }
      v13colrel = ecl_make_fixnum(1);
      goto L89;
L122:;
      v13colrel = v17param;
     }
L89:;
     {
      cl_object v15param_and_offset;
      cl_object v16offset;
      cl_object v17param;
      {
       cl_object v18;
       v18 = v12;
       if (ecl_unlikely(!ECL_LISTP(v18))) FEtype_error_list(v18);
       if (Null(v18)) { goto L130; }
       {
        cl_object v19;
        v19 = ECL_CONS_CDR(v18);
        v12 = v19;
        v18 = ECL_CONS_CAR(v18);
       }
L130:;
       v15param_and_offset = v18;
      }
      v16offset = ecl_car(v15param_and_offset);
      v17param = ecl_cdr(v15param_and_offset);
      if (!(ecl_eql(v17param,VV[17]))) { goto L138; }
      if (!(v5args==ECL_NIL)) { goto L143; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v16offset);
L143:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L145; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L145:;
      {
       cl_object v18;
       v18 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v18))) FEtype_error_list(v18);
       if (Null(v18)) { goto L150; }
       {
        cl_object v19;
        v19 = ECL_CONS_CDR(v18);
        v5args = v19;
        v18 = ECL_CONS_CAR(v18);
       }
L150:;
       value0 = v18;
      }
      if ((value0)!=ECL_NIL) { goto L141; }
      v14colinc = ecl_make_fixnum(1);
      goto L125;
L141:;
      v14colinc = value0;
      goto L125;
L138:;
      if (!(ecl_eql(v17param,VV[18]))) { goto L156; }
      v14colinc = ecl_make_fixnum(ecl_length(v5args));
      goto L125;
L156:;
      if (!((v17param)==(ECL_NIL))) { goto L158; }
      v14colinc = ecl_make_fixnum(1);
      goto L125;
L158:;
      v14colinc = v17param;
     }
L125:;
     if (Null(v12)) { goto L161; }
     T0 = ecl_list1(ecl_make_fixnum(2));
     T1 = ecl_caar(v12);
     cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T0, ECL_SYM("OFFSET",1279), T1);
L161:;
     si_format_relative_tab(3, v1stream, v13colrel, v14colinc);
     goto L5;
    }
   }
L86:;
   {
    cl_object v15;
    v15 = v8;
    {
     cl_object v16colnum;
     cl_object v17colinc;
     {
      cl_object v18param_and_offset;
      cl_object v19offset;
      cl_object v20param;
      {
       cl_object v21;
       v21 = v15;
       if (ecl_unlikely(!ECL_LISTP(v21))) FEtype_error_list(v21);
       if (Null(v21)) { goto L169; }
       {
        cl_object v22;
        v22 = ECL_CONS_CDR(v21);
        v15 = v22;
        v21 = ECL_CONS_CAR(v21);
       }
L169:;
       v18param_and_offset = v21;
      }
      v19offset = ecl_car(v18param_and_offset);
      v20param = ecl_cdr(v18param_and_offset);
      if (!(ecl_eql(v20param,VV[17]))) { goto L177; }
      if (!(v5args==ECL_NIL)) { goto L182; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v19offset);
L182:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L184; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L184:;
      {
       cl_object v21;
       v21 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v21))) FEtype_error_list(v21);
       if (Null(v21)) { goto L189; }
       {
        cl_object v22;
        v22 = ECL_CONS_CDR(v21);
        v5args = v22;
        v21 = ECL_CONS_CAR(v21);
       }
L189:;
       value0 = v21;
      }
      if ((value0)!=ECL_NIL) { goto L180; }
      v16colnum = ecl_make_fixnum(1);
      goto L164;
L180:;
      v16colnum = value0;
      goto L164;
L177:;
      if (!(ecl_eql(v20param,VV[18]))) { goto L195; }
      v16colnum = ecl_make_fixnum(ecl_length(v5args));
      goto L164;
L195:;
      if (!((v20param)==(ECL_NIL))) { goto L197; }
      v16colnum = ecl_make_fixnum(1);
      goto L164;
L197:;
      v16colnum = v20param;
     }
L164:;
     {
      cl_object v18param_and_offset;
      cl_object v19offset;
      cl_object v20param;
      {
       cl_object v21;
       v21 = v15;
       if (ecl_unlikely(!ECL_LISTP(v21))) FEtype_error_list(v21);
       if (Null(v21)) { goto L205; }
       {
        cl_object v22;
        v22 = ECL_CONS_CDR(v21);
        v15 = v22;
        v21 = ECL_CONS_CAR(v21);
       }
L205:;
       v18param_and_offset = v21;
      }
      v19offset = ecl_car(v18param_and_offset);
      v20param = ecl_cdr(v18param_and_offset);
      if (!(ecl_eql(v20param,VV[17]))) { goto L213; }
      if (!(v5args==ECL_NIL)) { goto L218; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v19offset);
L218:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L220; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L220:;
      {
       cl_object v21;
       v21 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v21))) FEtype_error_list(v21);
       if (Null(v21)) { goto L225; }
       {
        cl_object v22;
        v22 = ECL_CONS_CDR(v21);
        v5args = v22;
        v21 = ECL_CONS_CAR(v21);
       }
L225:;
       value0 = v21;
      }
      if ((value0)!=ECL_NIL) { goto L216; }
      v17colinc = ecl_make_fixnum(1);
      goto L200;
L216:;
      v17colinc = value0;
      goto L200;
L213:;
      if (!(ecl_eql(v20param,VV[18]))) { goto L231; }
      v17colinc = ecl_make_fixnum(ecl_length(v5args));
      goto L200;
L231:;
      if (!((v20param)==(ECL_NIL))) { goto L233; }
      v17colinc = ecl_make_fixnum(1);
      goto L200;
L233:;
      v17colinc = v20param;
     }
L200:;
     if (Null(v15)) { goto L236; }
     T0 = ecl_list1(ecl_make_fixnum(2));
     T1 = ecl_caar(v15);
     cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T0, ECL_SYM("OFFSET",1279), T1);
L236:;
     si_format_absolute_tab(3, v1stream, v16colnum, v17colinc);
    }
   }
L5:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5args;
   cl_env_copy->values[0] = v3;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for OUTPUT-SPACES                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L75output_spaces(cl_object v1stream, cl_object v2n)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
L2:;
  {
   cl_fixnum v3;
   v3 = ecl_length(VV[154]);
   if (!(ecl_number_compare(v2n,ecl_make_fixnum(v3))<0)) { goto L4; }
  }
  goto L1;
L4:;
  cl_write_string(2, VV[154], v1stream);
  {
   cl_fixnum v3;
   v3 = ecl_length(VV[154]);
   v2n = ecl_minus(v2n,ecl_make_fixnum(v3));
  }
  goto L2;
L1:;
  value0 = cl_write_string(4, VV[154], v1stream, ECL_SYM("END",1225), v2n);
  return value0;
 }
}
/*	function definition for FORMAT-RELATIVE-TAB                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_format_relative_tab(cl_narg narg, cl_object v1stream, cl_object v2colrel, cl_object v3colinc, ...)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg!=3)) FEwrong_num_arguments_anonym();
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[267])(1, v1stream) /*  PRETTY-STREAM-P */)) { goto L1; }
  value0 = cl_pprint_tab(4, VV[155], v2colrel, v3colinc, v1stream);
  return value0;
L1:;
  {
   cl_object v4cur;
   cl_object v5spaces;
   v4cur = si_file_column(v1stream);
   if (Null(v4cur)) { goto L5; }
   if (!(ecl_plusp(v3colinc))) { goto L5; }
   T0 = ecl_plus(v4cur,v2colrel);
   T1 = ecl_ceiling2(T0,v3colinc);
   T2 = ecl_times(T1,v3colinc);
   v5spaces = ecl_minus(T2,v4cur);
   goto L4;
L5:;
   v5spaces = v2colrel;
L4:;
   value0 = L75output_spaces(v1stream, v5spaces);
   return value0;
  }
 }
}
/*	function definition for FORMAT-ABSOLUTE-TAB                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_format_absolute_tab(cl_narg narg, cl_object v1stream, cl_object v2colnum, cl_object v3colinc, ...)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg!=3)) FEwrong_num_arguments_anonym();
 {
TTL:
  if (Null(ecl_function_dispatch(cl_env_copy,VV[267])(1, v1stream) /*  PRETTY-STREAM-P */)) { goto L1; }
  value0 = cl_pprint_tab(4, ECL_SYM("LINE",1601), v2colnum, v3colinc, v1stream);
  return value0;
L1:;
  {
   cl_object v4cur;
   v4cur = si_file_column(v1stream);
   if (!(v4cur==ECL_NIL)) { goto L4; }
   value0 = cl_write_string(2, _ecl_static_39, v1stream);
   return value0;
L4:;
   if (!(ecl_number_compare(v4cur,v2colnum)<0)) { goto L6; }
   T0 = ecl_minus(v2colnum,v4cur);
   value0 = L75output_spaces(v1stream, T0);
   return value0;
L6:;
   if (ecl_zerop(v3colinc)) { goto L8; }
   T0 = ecl_minus(v4cur,v2colnum);
   T1 = (ecl_truncate2(T0,v3colinc),cl_env_copy->values[1]);
   T2 = ecl_minus(v3colinc,T1);
   value0 = L75output_spaces(v1stream, T2);
   return value0;
L8:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G1463                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC76__g1463(cl_object v1, cl_object v2)
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
   cl_object v5;
   v3 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v1) /*  FORMAT-DIRECTIVE-COLONP */;
   v4 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v1) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v5 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v1) /*  FORMAT-DIRECTIVE-PARAMS */;
   L115check_output_layout_mode(ecl_make_fixnum(1));
   if (Null(v5)) { goto L6; }
   T1 = ecl_caar(v5);
   cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_20, ECL_SYM("OFFSET",1279), T1);
L6:;
   if (Null(v3)) { goto L9; }
   if (Null(v4)) { goto L11; }
   T1 = VV[158];
   goto L8;
L11:;
   T1 = VV[159];
   goto L8;
L9:;
   if (Null(v4)) { goto L13; }
   T1 = VV[160];
   goto L8;
L13:;
   T1 = VV[161];
L8:;
   T0 = cl_list(3, ECL_SYM("PPRINT-NEWLINE",654), T1, ECL_SYM("STREAM",799));
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v2;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G1470                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC77__g1470(cl_object v1stream, cl_object v2, cl_object v3, cl_object v4orig_args, cl_object v5args)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6;
   cl_object v7;
   cl_object v8;
   v6 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v2) /*  FORMAT-DIRECTIVE-COLONP */;
   v7 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v2) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v8 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v2) /*  FORMAT-DIRECTIVE-PARAMS */;
   L115check_output_layout_mode(ecl_make_fixnum(1));
   if (Null(v8)) { goto L6; }
   T0 = ecl_list1(ecl_make_fixnum(0));
   T1 = ecl_caar(v8);
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T0, ECL_SYM("OFFSET",1279), T1);
L6:;
   if (Null(v6)) { goto L9; }
   if (Null(v7)) { goto L11; }
   T0 = VV[158];
   goto L8;
L11:;
   T0 = VV[159];
   goto L8;
L9:;
   if (Null(v7)) { goto L13; }
   T0 = VV[160];
   goto L8;
L13:;
   T0 = VV[161];
L8:;
   cl_pprint_newline(2, T0, v1stream);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5args;
   cl_env_copy->values[0] = v3;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G1477                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC78__g1477(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   v3 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v1) /*  FORMAT-DIRECTIVE-COLONP */;
   v4 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v1) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v5 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v1) /*  FORMAT-DIRECTIVE-PARAMS */;
   L115check_output_layout_mode(ecl_make_fixnum(1));
   if (Null(v4)) { goto L5; }
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_40);
L5:;
   {
    cl_object v6;
    v6 = v5;
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L14; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L14:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L22; }
     T2 = L14expand_next_arg(1, v8offset);
     T1 = cl_list(3, ECL_SYM("OR",614), T2, ecl_make_fixnum(0));
     goto L9;
L22:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L24; }
     cl_set(VV[28],ECL_NIL);
     T1 = VV[54];
     goto L9;
L24:;
     if (!((v9param)==(ECL_NIL))) { goto L28; }
     T1 = ecl_make_fixnum(0);
     goto L9;
L28:;
     T1 = v9param;
    }
L9:;
    T2 = cl_list(2, VV[162], T1);
    T3 = ecl_list1(T2);
    if (Null(v6)) { goto L32; }
    T5 = ecl_list1(ecl_make_fixnum(1));
    T6 = ecl_caar(v6);
    T4 = cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T5, ECL_SYM("OFFSET",1279), T6);
    goto L31;
L32:;
    T4 = ECL_NIL;
L31:;
    if (Null(v3)) { goto L35; }
    T5 = VV[163];
    goto L34;
L35:;
    T5 = ECL_SYM("BLOCK",1202);
L34:;
    T6 = cl_list(4, ECL_SYM("PPRINT-INDENT",651), T5, VV[162], ECL_SYM("STREAM",799));
    T7 = ecl_list1(T6);
    T8 = ecl_append(T4,T7);
    T0 = cl_listX(3, ECL_SYM("LET",477), T3, T8);
   }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v2;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G1490                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC79__g1490(cl_object v1stream, cl_object v2, cl_object v3, cl_object v4orig_args, cl_object v5args)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6;
   cl_object v7;
   cl_object v8;
   v6 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v2) /*  FORMAT-DIRECTIVE-COLONP */;
   v7 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v2) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v8 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v2) /*  FORMAT-DIRECTIVE-PARAMS */;
   L115check_output_layout_mode(ecl_make_fixnum(1));
   if (Null(v7)) { goto L5; }
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_40);
L5:;
   {
    cl_object v9;
    v9 = v8;
    {
     cl_object v10n;
     {
      cl_object v11param_and_offset;
      cl_object v12offset;
      cl_object v13param;
      {
       cl_object v14;
       v14 = v9;
       if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
       if (Null(v14)) { goto L14; }
       {
        cl_object v15;
        v15 = ECL_CONS_CDR(v14);
        v9 = v15;
        v14 = ECL_CONS_CAR(v14);
       }
L14:;
       v11param_and_offset = v14;
      }
      v12offset = ecl_car(v11param_and_offset);
      v13param = ecl_cdr(v11param_and_offset);
      if (!(ecl_eql(v13param,VV[17]))) { goto L22; }
      if (!(v5args==ECL_NIL)) { goto L27; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v12offset);
L27:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L29; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L29:;
      {
       cl_object v14;
       v14 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
       if (Null(v14)) { goto L34; }
       {
        cl_object v15;
        v15 = ECL_CONS_CDR(v14);
        v5args = v15;
        v14 = ECL_CONS_CAR(v14);
       }
L34:;
       value0 = v14;
      }
      if ((value0)!=ECL_NIL) { goto L25; }
      v10n = ecl_make_fixnum(0);
      goto L9;
L25:;
      v10n = value0;
      goto L9;
L22:;
      if (!(ecl_eql(v13param,VV[18]))) { goto L40; }
      v10n = ecl_make_fixnum(ecl_length(v5args));
      goto L9;
L40:;
      if (!((v13param)==(ECL_NIL))) { goto L42; }
      v10n = ecl_make_fixnum(0);
      goto L9;
L42:;
      v10n = v13param;
     }
L9:;
     if (Null(v9)) { goto L45; }
     T0 = ecl_list1(ecl_make_fixnum(1));
     T1 = ecl_caar(v9);
     cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T0, ECL_SYM("OFFSET",1279), T1);
L45:;
     if (Null(v6)) { goto L48; }
     T0 = VV[163];
     goto L47;
L48:;
     T0 = ECL_SYM("BLOCK",1202);
L47:;
     cl_pprint_indent(3, T0, v10n, v1stream);
    }
   }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5args;
   cl_env_copy->values[0] = v3;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G1503                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC80__g1503(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6;
   v3 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v1) /*  FORMAT-DIRECTIVE-COLONP */;
   v4 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v1) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v5 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v1) /*  FORMAT-DIRECTIVE-PARAMS */;
   v6 = ecl_function_dispatch(cl_env_copy,VV[243])(1, v1) /*  FORMAT-DIRECTIVE-END */;
   if (Null(v4)) { goto L6; }
   if (Null(v3)) { goto L8; }
   T0 = cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_41);
   goto L5;
L8:;
   {
    cl_object v7;
    v7 = v5;
    {
     cl_object v8param_and_offset;
     cl_object v9offset;
     cl_object v10param;
     {
      cl_object v11;
      v11 = v7;
      if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
      if (Null(v11)) { goto L16; }
      {
       cl_object v12;
       v12 = ECL_CONS_CDR(v11);
       v7 = v12;
       v11 = ECL_CONS_CAR(v11);
      }
L16:;
      v8param_and_offset = v11;
     }
     v9offset = ecl_car(v8param_and_offset);
     v10param = ecl_cdr(v8param_and_offset);
     if (!(ecl_eql(v10param,VV[17]))) { goto L24; }
     T2 = L14expand_next_arg(1, v9offset);
     T1 = cl_list(3, ECL_SYM("OR",614), T2, ecl_make_fixnum(0));
     goto L11;
L24:;
     if (!(ecl_eql(v10param,VV[18]))) { goto L26; }
     cl_set(VV[28],ECL_NIL);
     T1 = VV[54];
     goto L11;
L26:;
     if (!((v10param)==(ECL_NIL))) { goto L30; }
     T1 = ecl_make_fixnum(0);
     goto L11;
L30:;
     T1 = v10param;
    }
L11:;
    T2 = cl_list(2, VV[164], T1);
    T3 = ecl_list1(T2);
    if (Null(v7)) { goto L34; }
    T5 = ecl_list1(ecl_make_fixnum(1));
    T6 = ecl_caar(v7);
    T4 = cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T5, ECL_SYM("OFFSET",1279), T6);
    goto L33;
L34:;
    T4 = ECL_NIL;
L33:;
    if ((ecl_symbol_value(VV[29]))!=ECL_NIL) { goto L37; }
    cl_env_copy->values[0] = ECL_NIL;
    cl_env_copy->nvalues = 1;
    cl_throw(VV[36]);
L37:;
    T5 = ECL_NIL;
    T6 = cl_list(4, ECL_SYM("<=",73), ecl_make_fixnum(0), VV[164], VV[165]);
    T7 = cl_list(3, ECL_SYM("NTHCDR",604), VV[164], VV[166]);
    T8 = cl_list(3, ECL_SYM("SETF",750), VV[39], T7);
    T9 = cl_list(3, ECL_SYM("LIST",481), VV[164], VV[165]);
    T10 = ecl_one_minus(v6);
    T11 = cl_list(8, ECL_SYM("ERROR",337), VV[37], VV[14], _ecl_static_42, VV[56], T9, ECL_SYM("OFFSET",1279), T10);
    T12 = cl_list(4, ECL_SYM("IF",946), T6, T8, T11);
    T13 = cl_list(2, T5, T12);
    T14 = ecl_append(T4,T13);
    T0 = cl_listX(3, ECL_SYM("LET",477), T3, T14);
    goto L5;
   }
L6:;
   if (Null(v3)) { goto L40; }
   {
    cl_object v8;
    v8 = v5;
    {
     cl_object v9param_and_offset;
     cl_object v10offset;
     cl_object v11param;
     {
      cl_object v12;
      v12 = v8;
      if (ecl_unlikely(!ECL_LISTP(v12))) FEtype_error_list(v12);
      if (Null(v12)) { goto L48; }
      {
       cl_object v13;
       v13 = ECL_CONS_CDR(v12);
       v8 = v13;
       v12 = ECL_CONS_CAR(v12);
      }
L48:;
      v9param_and_offset = v12;
     }
     v10offset = ecl_car(v9param_and_offset);
     v11param = ecl_cdr(v9param_and_offset);
     if (!(ecl_eql(v11param,VV[17]))) { goto L56; }
     T2 = L14expand_next_arg(1, v10offset);
     T1 = cl_list(3, ECL_SYM("OR",614), T2, ecl_make_fixnum(1));
     goto L43;
L56:;
     if (!(ecl_eql(v11param,VV[18]))) { goto L58; }
     cl_set(VV[28],ECL_NIL);
     T1 = VV[54];
     goto L43;
L58:;
     if (!((v11param)==(ECL_NIL))) { goto L62; }
     T1 = ecl_make_fixnum(1);
     goto L43;
L62:;
     T1 = v11param;
    }
L43:;
    T2 = cl_list(2, VV[167], T1);
    T3 = ecl_list1(T2);
    if (Null(v8)) { goto L66; }
    T5 = ecl_list1(ecl_make_fixnum(1));
    T6 = ecl_caar(v8);
    T4 = cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T5, ECL_SYM("OFFSET",1279), T6);
    goto L65;
L66:;
    T4 = ECL_NIL;
L65:;
    if ((ecl_symbol_value(VV[29]))!=ECL_NIL) { goto L69; }
    cl_env_copy->values[0] = ECL_NIL;
    cl_env_copy->nvalues = 1;
    cl_throw(VV[36]);
L69:;
    T5 = ECL_NIL;
    T6 = cl_list(3, ECL_SYM("-",17), VV[171], VV[167]);
    T7 = cl_list(2, VV[170], T6);
    T8 = ecl_list1(T7);
    T9 = ecl_one_minus(v6);
    T10 = cl_list(8, ECL_SYM("ERROR",337), VV[37], VV[14], _ecl_static_43, VV[56], VV[174], ECL_SYM("OFFSET",1279), T9);
    T11 = cl_list(4, ECL_SYM("IF",946), VV[172], VV[173], T10);
    T12 = cl_list(3, ECL_SYM("LET",477), T8, T11);
    T13 = cl_list(2, VV[169], T12);
    T14 = cl_list(3, ECL_SYM("DO",307), VV[168], T13);
    T15 = cl_list(2, T5, T14);
    T16 = ecl_append(T4,T15);
    T0 = cl_listX(3, ECL_SYM("LET",477), T3, T16);
    goto L5;
   }
L40:;
   if (Null(v5)) { goto L72; }
   {
    cl_object v9;
    v9 = v5;
    {
     cl_object v10param_and_offset;
     cl_object v11offset;
     cl_object v12param;
     {
      cl_object v13;
      v13 = v9;
      if (ecl_unlikely(!ECL_LISTP(v13))) FEtype_error_list(v13);
      if (Null(v13)) { goto L80; }
      {
       cl_object v14;
       v14 = ECL_CONS_CDR(v13);
       v9 = v14;
       v13 = ECL_CONS_CAR(v13);
      }
L80:;
      v10param_and_offset = v13;
     }
     v11offset = ecl_car(v10param_and_offset);
     v12param = ecl_cdr(v10param_and_offset);
     if (!(ecl_eql(v12param,VV[17]))) { goto L88; }
     T2 = L14expand_next_arg(1, v11offset);
     T1 = cl_list(3, ECL_SYM("OR",614), T2, ecl_make_fixnum(1));
     goto L75;
L88:;
     if (!(ecl_eql(v12param,VV[18]))) { goto L90; }
     cl_set(VV[28],ECL_NIL);
     T1 = VV[54];
     goto L75;
L90:;
     if (!((v12param)==(ECL_NIL))) { goto L94; }
     T1 = ecl_make_fixnum(1);
     goto L75;
L94:;
     T1 = v12param;
    }
L75:;
    T2 = cl_list(2, VV[175], T1);
    T3 = ecl_list1(T2);
    if (Null(v9)) { goto L98; }
    T5 = ecl_list1(ecl_make_fixnum(1));
    T6 = ecl_caar(v9);
    T4 = cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T5, ECL_SYM("OFFSET",1279), T6);
    goto L97;
L98:;
    T4 = ECL_NIL;
L97:;
    cl_set(VV[28],ECL_NIL);
    T5 = cl_list(2, VV[134], VV[175]);
    T6 = L14expand_next_arg(0);
    T7 = cl_list(3, ECL_SYM("DOTIMES",314), T5, T6);
    T8 = cl_list(2, ECL_NIL, T7);
    T9 = ecl_append(T4,T8);
    T0 = cl_listX(3, ECL_SYM("LET",477), T3, T9);
    goto L5;
   }
L72:;
   T0 = L14expand_next_arg(0);
L5:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v2;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G1532                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC81__g1532(cl_object v1stream, cl_object v2, cl_object v3, cl_object v4orig_args, cl_object v5args)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6;
   cl_object v7;
   cl_object v8;
   v6 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v2) /*  FORMAT-DIRECTIVE-COLONP */;
   v7 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v2) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v8 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v2) /*  FORMAT-DIRECTIVE-PARAMS */;
   if (Null(v7)) { goto L5; }
   if (Null(v6)) { goto L7; }
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_41);
   goto L4;
L7:;
   {
    cl_object v9;
    v9 = v8;
    {
     cl_object v10posn;
     {
      cl_object v11param_and_offset;
      cl_object v12offset;
      cl_object v13param;
      {
       cl_object v14;
       v14 = v9;
       if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
       if (Null(v14)) { goto L15; }
       {
        cl_object v15;
        v15 = ECL_CONS_CDR(v14);
        v9 = v15;
        v14 = ECL_CONS_CAR(v14);
       }
L15:;
       v11param_and_offset = v14;
      }
      v12offset = ecl_car(v11param_and_offset);
      v13param = ecl_cdr(v11param_and_offset);
      if (!(ecl_eql(v13param,VV[17]))) { goto L23; }
      if (!(v5args==ECL_NIL)) { goto L28; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v12offset);
L28:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L30; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L30:;
      {
       cl_object v14;
       v14 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
       if (Null(v14)) { goto L35; }
       {
        cl_object v15;
        v15 = ECL_CONS_CDR(v14);
        v5args = v15;
        v14 = ECL_CONS_CAR(v14);
       }
L35:;
       value0 = v14;
      }
      if ((value0)!=ECL_NIL) { goto L26; }
      v10posn = ecl_make_fixnum(0);
      goto L10;
L26:;
      v10posn = value0;
      goto L10;
L23:;
      if (!(ecl_eql(v13param,VV[18]))) { goto L41; }
      v10posn = ecl_make_fixnum(ecl_length(v5args));
      goto L10;
L41:;
      if (!((v13param)==(ECL_NIL))) { goto L43; }
      v10posn = ecl_make_fixnum(0);
      goto L10;
L43:;
      v10posn = v13param;
     }
L10:;
     if (Null(v9)) { goto L46; }
     T0 = ecl_list1(ecl_make_fixnum(1));
     T1 = ecl_caar(v9);
     cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T0, ECL_SYM("OFFSET",1279), T1);
L46:;
     {
      cl_fixnum v11;
      v11 = ecl_length(v4orig_args);
      if (Null(cl_LE(3, ecl_make_fixnum(0), v10posn, ecl_make_fixnum(v11)))) { goto L48; }
     }
     v5args = ecl_nthcdr(ecl_to_size(v10posn),v4orig_args);
     goto L4;
L48:;
     {
      cl_fixnum v11;
      v11 = ecl_length(v4orig_args);
      T0 = cl_list(2, v10posn, ecl_make_fixnum(v11));
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_44, VV[56], T0);
      goto L4;
     }
    }
   }
L5:;
   if (Null(v6)) { goto L51; }
   {
    cl_object v12;
    v12 = v8;
    {
     cl_object v13n;
     {
      cl_object v14param_and_offset;
      cl_object v15offset;
      cl_object v16param;
      {
       cl_object v17;
       v17 = v12;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L59; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v12 = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L59:;
       v14param_and_offset = v17;
      }
      v15offset = ecl_car(v14param_and_offset);
      v16param = ecl_cdr(v14param_and_offset);
      if (!(ecl_eql(v16param,VV[17]))) { goto L67; }
      if (!(v5args==ECL_NIL)) { goto L72; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v15offset);
L72:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L74; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L74:;
      {
       cl_object v17;
       v17 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L79; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v5args = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L79:;
       value0 = v17;
      }
      if ((value0)!=ECL_NIL) { goto L70; }
      v13n = ecl_make_fixnum(1);
      goto L54;
L70:;
      v13n = value0;
      goto L54;
L67:;
      if (!(ecl_eql(v16param,VV[18]))) { goto L85; }
      v13n = ecl_make_fixnum(ecl_length(v5args));
      goto L54;
L85:;
      if (!((v16param)==(ECL_NIL))) { goto L87; }
      v13n = ecl_make_fixnum(1);
      goto L54;
L87:;
      v13n = v16param;
     }
L54:;
     if (Null(v12)) { goto L90; }
     T0 = ecl_list1(ecl_make_fixnum(1));
     T1 = ecl_caar(v12);
     cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T0, ECL_SYM("OFFSET",1279), T1);
L90:;
     {
      cl_object v14cur_posn;
      cl_object v15arg_ptr;
      v14cur_posn = ecl_make_fixnum(0);
      v15arg_ptr = v4orig_args;
      goto L96;
L95:;
      v14cur_posn = ecl_one_plus(v14cur_posn);
      v15arg_ptr = ecl_cdr(v15arg_ptr);
L96:;
      if ((v15arg_ptr)==(v5args)) { goto L101; }
      goto L95;
L101:;
      {
       cl_object v16new_posn;
       v16new_posn = ecl_minus(v14cur_posn,v13n);
       {
        cl_fixnum v17;
        v17 = ecl_length(v4orig_args);
        if (Null(cl_LE(3, ecl_make_fixnum(0), v16new_posn, ecl_make_fixnum(v17)))) { goto L104; }
       }
       v5args = ecl_nthcdr(ecl_to_size(v16new_posn),v4orig_args);
       goto L4;
L104:;
       {
        cl_fixnum v17;
        v17 = ecl_length(v4orig_args);
        T0 = cl_list(2, v16new_posn, ecl_make_fixnum(v17));
        cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_45, VV[56], T0);
        goto L4;
       }
      }
     }
    }
   }
L51:;
   {
    cl_object v18;
    v18 = v8;
    {
     cl_object v19n;
     {
      cl_object v20param_and_offset;
      cl_object v21offset;
      cl_object v22param;
      {
       cl_object v23;
       v23 = v18;
       if (ecl_unlikely(!ECL_LISTP(v23))) FEtype_error_list(v23);
       if (Null(v23)) { goto L113; }
       {
        cl_object v24;
        v24 = ECL_CONS_CDR(v23);
        v18 = v24;
        v23 = ECL_CONS_CAR(v23);
       }
L113:;
       v20param_and_offset = v23;
      }
      v21offset = ecl_car(v20param_and_offset);
      v22param = ecl_cdr(v20param_and_offset);
      if (!(ecl_eql(v22param,VV[17]))) { goto L121; }
      if (!(v5args==ECL_NIL)) { goto L126; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v21offset);
L126:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L128; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L128:;
      {
       cl_object v23;
       v23 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v23))) FEtype_error_list(v23);
       if (Null(v23)) { goto L133; }
       {
        cl_object v24;
        v24 = ECL_CONS_CDR(v23);
        v5args = v24;
        v23 = ECL_CONS_CAR(v23);
       }
L133:;
       value0 = v23;
      }
      if ((value0)!=ECL_NIL) { goto L124; }
      v19n = ecl_make_fixnum(1);
      goto L108;
L124:;
      v19n = value0;
      goto L108;
L121:;
      if (!(ecl_eql(v22param,VV[18]))) { goto L139; }
      v19n = ecl_make_fixnum(ecl_length(v5args));
      goto L108;
L139:;
      if (!((v22param)==(ECL_NIL))) { goto L141; }
      v19n = ecl_make_fixnum(1);
      goto L108;
L141:;
      v19n = v22param;
     }
L108:;
     if (Null(v18)) { goto L144; }
     T0 = ecl_list1(ecl_make_fixnum(1));
     T1 = ecl_caar(v18);
     cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T0, ECL_SYM("OFFSET",1279), T1);
L144:;
     {
      cl_object v20i;
      v20i = ecl_make_fixnum(0);
      goto L148;
L147:;
      if (!(v5args==ECL_NIL)) { goto L151; }
      cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L151:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L153; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L153:;
      {
       cl_object v21;
       v21 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v21))) FEtype_error_list(v21);
       if (Null(v21)) { goto L158; }
       {
        cl_object v22;
        v22 = ECL_CONS_CDR(v21);
        v5args = v22;
        v21 = ECL_CONS_CAR(v21);
       }
L158:;
      }
      v20i = ecl_one_plus(v20i);
L148:;
      if (!(ecl_number_compare(v20i,v19n)<0)) { goto L166; }
      goto L147;
L166:;
     }
    }
   }
L4:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5args;
   cl_env_copy->values[0] = v3;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G1574                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC82__g1574(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6;
   cl_object v7;
   v3 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v1) /*  FORMAT-DIRECTIVE-COLONP */;
   v4 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v1) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v5 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v1) /*  FORMAT-DIRECTIVE-PARAMS */;
   v6 = ecl_function_dispatch(cl_env_copy,VV[269])(1, v1) /*  FORMAT-DIRECTIVE-STRING */;
   v7 = ecl_function_dispatch(cl_env_copy,VV[243])(1, v1) /*  FORMAT-DIRECTIVE-END */;
   if (Null(v3)) { goto L6; }
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_46);
L6:;
   if (Null(v5)) { goto L9; }
   T1 = ecl_caar(v5);
   cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_20, ECL_SYM("OFFSET",1279), T1);
L9:;
   T1 = ecl_one_minus(v7);
   T2 = cl_list(12, ECL_SYM("ERROR",337), VV[37], VV[14], _ecl_static_47, VV[56], VV[177], VV[178], ECL_NIL, ECL_SYM("CONTROL-STRING",1211), v6, ECL_SYM("OFFSET",1279), T1);
   T3 = cl_list(3, ECL_SYM("LAMBDA",452), VV[176], T2);
   T4 = cl_list(2, ECL_SYM("FUNCTION",396), T3);
   T5 = cl_list(2, ECL_SYM("FORMAT-ERROR",1074), T4);
   T6 = ecl_list1(T5);
   if (Null(v4)) { goto L12; }
   if (Null(ecl_symbol_value(VV[29]))) { goto L14; }
   T8 = L14expand_next_arg(0);
   T9 = cl_listX(4, VV[33], ECL_SYM("STREAM",799), T8, VV[179]);
   T7 = cl_list(3, ECL_SYM("SETF",750), VV[39], T9);
   goto L11;
L14:;
   cl_env_copy->values[0] = ECL_NIL;
   cl_env_copy->nvalues = 1;
   cl_throw(VV[36]);
L12:;
   T8 = L14expand_next_arg(0);
   T9 = L14expand_next_arg(0);
   T7 = cl_list(4, VV[33], ECL_SYM("STREAM",799), T8, T9);
L11:;
   T0 = cl_list(3, ECL_SYM("HANDLER-BIND",417), T6, T7);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v2;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G1583                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC84__g1583(cl_object v1stream, cl_object v2, cl_object v3, cl_object v4orig_args, cl_object v5args)
{
 cl_object T0, T1, T2, T3;
 cl_object env0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6;
   cl_object v7;
   cl_object v8;
   cl_object v9;
   cl_object v10;
   cl_object env1 = env0;
   v6 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v2) /*  FORMAT-DIRECTIVE-COLONP */;
   v7 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v2) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v8 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v2) /*  FORMAT-DIRECTIVE-PARAMS */;
   v9 = ecl_function_dispatch(cl_env_copy,VV[269])(1, v2) /*  FORMAT-DIRECTIVE-STRING */;
   v10 = ecl_function_dispatch(cl_env_copy,VV[243])(1, v2) /*  FORMAT-DIRECTIVE-END */;
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(v9,env1);                   /*  STRING          */
   CLV1 = env1 = CONS(v10,env1);                  /*  END             */
   if (Null(v6)) { goto L6; }
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_46);
L6:;
   if (Null(v8)) { goto L9; }
   T0 = ecl_list1(ecl_make_fixnum(0));
   T1 = ecl_caar(v8);
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T0, ECL_SYM("OFFSET",1279), T1);
L9:;
   {cl_object v11;
    v11 = ECL_NIL;
    v11 = ecl_make_cclosure_va((cl_objectfn)LC83__g1590,env1,Cblock);
    T0 = v11;
   }
   T1 = CONS(ECL_SYM("FORMAT-ERROR",1074),T0);
   T2 = ecl_list1(T1);
   T3 = CONS(T2,ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5)));
   ecl_bds_bind(cl_env_copy,ECL_SYM("*HANDLER-CLUSTERS*",5),T3); /*  *HANDLER-CLUSTERS* */
   if (Null(v7)) { goto L12; }
   if (!(v5args==ECL_NIL)) { goto L15; }
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L15:;
   if (Null(ecl_symbol_value(VV[25]))) { goto L17; }
   ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L17:;
   {
    cl_object v11;
    v11 = v5args;
    if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
    if (Null(v11)) { goto L23; }
    {
     cl_object v12;
     v12 = ECL_CONS_CDR(v11);
     v5args = v12;
     v11 = ECL_CONS_CAR(v11);
    }
L23:;
    T0 = v11;
   }
   v5args = L7formatter_aux(4, v1stream, T0, v4orig_args, v5args);
   ecl_bds_unwind1(cl_env_copy);
   goto L8;
L12:;
   if (!(v5args==ECL_NIL)) { goto L29; }
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L29:;
   if (Null(ecl_symbol_value(VV[25]))) { goto L31; }
   ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L31:;
   {
    cl_object v11;
    v11 = v5args;
    if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
    if (Null(v11)) { goto L37; }
    {
     cl_object v12;
     v12 = ECL_CONS_CDR(v11);
     v5args = v12;
     v11 = ECL_CONS_CAR(v11);
    }
L37:;
    T0 = v11;
   }
   if (!(v5args==ECL_NIL)) { goto L43; }
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L43:;
   if (Null(ecl_symbol_value(VV[25]))) { goto L45; }
   ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L45:;
   {
    cl_object v11;
    v11 = v5args;
    if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
    if (Null(v11)) { goto L51; }
    {
     cl_object v12;
     v12 = ECL_CONS_CDR(v11);
     v5args = v12;
     v11 = ECL_CONS_CAR(v11);
    }
L51:;
    T1 = v11;
   }
   L7formatter_aux(3, v1stream, T0, T1);
   ecl_bds_unwind1(cl_env_copy);
L8:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5args;
   cl_env_copy->values[0] = v3;
   return cl_env_copy->values[0];
  }
 }
}
/*	closure G1590                                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC83__g1590(cl_narg narg, cl_object v1condition, ...)
{
 cl_object T0, T1;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  END             */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  T0 = ecl_list1(v1condition);
  T1 = ecl_one_minus(ECL_CONS_CAR(CLV1));
  value0 = cl_error(11, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_47, VV[56], T0, VV[178], ECL_NIL, ECL_SYM("CONTROL-STRING",1211), ECL_CONS_CAR(CLV0), ECL_SYM("OFFSET",1279), T1);
  return value0;
 }
 }
}
/*	function definition for NSTRING-CAPITALIZE-FIRST              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L85nstring_capitalize_first(cl_object v1s)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  cl_nstring_downcase(1, v1s);
  {
   cl_object v2where;
   T0 = (ECL_SYM("ALPHA-CHAR-P",85)->symbol.gfdef);
   v2where = cl_position_if(2, T0, v1s);
   if (Null(v2where)) { goto L4; }
   T0 = ecl_one_plus(v2where);
   cl_nstring_capitalize(5, v1s, ECL_SYM("START",1310), ecl_make_fixnum(0), ECL_SYM("END",1225), T0);
L4:;
   value0 = v1s;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G1599                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC86__g1599(cl_object v1, cl_object v2directives)
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
   cl_object v5;
   v3 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v1) /*  FORMAT-DIRECTIVE-COLONP */;
   v4 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v1) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v5 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v1) /*  FORMAT-DIRECTIVE-PARAMS */;
   {
    cl_object v6close;
    v6close = L21find_directive(v2directives, CODE_CHAR(41), ECL_NIL);
    if ((v6close)!=ECL_NIL) { goto L5; }
    cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_48);
L5:;
    {
     cl_object v7posn;
     cl_object v8before;
     cl_object v9after;
     v7posn = cl_position(2, v6close, v2directives);
     v8before = cl_subseq(3, v2directives, ecl_make_fixnum(0), v7posn);
     T0 = ecl_one_plus(v7posn);
     v9after = ecl_nthcdr(ecl_to_size(T0),v2directives);
     if (Null(v5)) { goto L11; }
     T1 = ecl_caar(v5);
     cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_20, ECL_SYM("OFFSET",1279), T1);
L11:;
     T1 = L12expand_directive_list(v8before);
     T2 = cl_listX(3, ECL_SYM("WITH-OUTPUT-TO-STRING",913), VV[182], T1);
     if (Null(v3)) { goto L14; }
     if (Null(v4)) { goto L16; }
     T3 = ECL_SYM("NSTRING-UPCASE",594);
     goto L13;
L16:;
     T3 = ECL_SYM("NSTRING-CAPITALIZE",592);
     goto L13;
L14:;
     if (Null(v4)) { goto L18; }
     T3 = VV[180];
     goto L13;
L18:;
     T3 = ECL_SYM("NSTRING-DOWNCASE",593);
L13:;
     T4 = cl_list(2, T3, ECL_SYM("STRING",805));
     T5 = cl_list(3, ECL_SYM("PRINC",660), T4, ECL_SYM("STREAM",799));
     T6 = cl_list(3, ECL_SYM("UNWIND-PROTECT",888), T2, T5);
     T0 = cl_list(3, ECL_SYM("LET",477), VV[181], T6);
     cl_env_copy->nvalues = 2;
     cl_env_copy->values[1] = v9after;
     cl_env_copy->values[0] = T0;
     return cl_env_copy->values[0];
    }
   }
  }
 }
}
/*	local function G1605                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC87__g1605(cl_object volatile v1stream, cl_object volatile v2, cl_object volatile v3directives, cl_object volatile v4orig_args, cl_object volatile v5args)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   volatile cl_object v6;
   volatile cl_object v7;
   volatile cl_object v8;
   v6 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v2) /*  FORMAT-DIRECTIVE-COLONP */;
   v7 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v2) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v8 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v2) /*  FORMAT-DIRECTIVE-PARAMS */;
   {
    volatile cl_object v9close;
    v9close = L21find_directive(v3directives, CODE_CHAR(41), ECL_NIL);
    if ((v9close)!=ECL_NIL) { goto L6; }
    cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_48);
L6:;
    if (Null(v8)) { goto L8; }
    T1 = ecl_list1(ecl_make_fixnum(0));
    T2 = ecl_caar(v8);
    cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T1, ECL_SYM("OFFSET",1279), T2);
L8:;
    {
     volatile cl_object v10posn;
     volatile cl_object v11before;
     volatile cl_object v12after;
     volatile cl_object v13string;
     v10posn = cl_position(2, v9close, v3directives);
     v11before = cl_subseq(3, v3directives, ecl_make_fixnum(0), v10posn);
     T1 = ecl_one_plus(v10posn);
     v12after = ecl_nthcdr(ecl_to_size(T1),v3directives);
     v13string = si_make_vector(ECL_SYM("CHARACTER",222), ecl_make_fixnum(10), ECL_T, ecl_make_fixnum(0), ECL_NIL, ecl_make_fixnum(0));
     {
      volatile bool unwinding = FALSE;
      cl_index v14=ECL_STACK_INDEX(cl_env_copy),v15;
      ecl_frame_ptr next_fr;
      if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
        unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
      } else {
      {
       cl_object v16stream;
       v16stream = si_make_string_output_stream_from_string(v13string);
       v5args = L8interpret_directive_list(v16stream, v11before, v4orig_args, v5args);
       cl_env_copy->values[0] = v5args;
       cl_env_copy->nvalues = 1;
      }
      }
      ecl_frs_pop(cl_env_copy);
      v15=ecl_stack_push_values(cl_env_copy);
      if (Null(v6)) { goto L21; }
      if (Null(v7)) { goto L23; }
      T2 = ECL_SYM("NSTRING-UPCASE",594);
      goto L20;
L23:;
      T2 = ECL_SYM("NSTRING-CAPITALIZE",592);
      goto L20;
L21:;
      if (Null(v7)) { goto L25; }
      T2 = VV[180];
      goto L20;
L25:;
      T2 = ECL_SYM("NSTRING-DOWNCASE",593);
L20:;
      T1 = ecl_function_dispatch(cl_env_copy,T2)(1, v13string);
      ecl_princ(T1,v1stream);
      ecl_stack_pop_values(cl_env_copy,v15);
      if (unwinding) ecl_unwind(cl_env_copy,next_fr);
      ECL_STACK_SET_INDEX(cl_env_copy,v14);
     }
     T0 = v12after;
    }
   }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5args;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G1614                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC88__g1614(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_49);
  return value0;
 }
}
/*	local function G1617                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC89__g1617(cl_object v1stream, cl_object v2, cl_object v3, cl_object v4orig_args, cl_object v5args)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_49);
  return value0;
 }
}
/*	function definition for PARSE-CONDITIONAL-DIRECTIVE           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L90parse_conditional_directive(cl_object v1directives)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2sublists;
   cl_object v3last_semi_with_colon_p;
   cl_object v4remaining;
   v2sublists = ECL_NIL;
   v3last_semi_with_colon_p = ECL_NIL;
   v4remaining = v1directives;
L5:;
   {
    cl_object v5close_or_semi;
    v5close_or_semi = L21find_directive(v4remaining, CODE_CHAR(93), ECL_T);
    if ((v5close_or_semi)!=ECL_NIL) { goto L8; }
    cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_50);
L8:;
    {
     cl_object v6posn;
     v6posn = cl_position(2, v5close_or_semi, v4remaining);
     T0 = cl_subseq(3, v4remaining, ecl_make_fixnum(0), v6posn);
     v2sublists = CONS(T0,v2sublists);
     T0 = ecl_one_plus(v6posn);
     v4remaining = ecl_nthcdr(ecl_to_size(T0),v4remaining);
     T0 = ecl_function_dispatch(cl_env_copy,VV[245])(1, v5close_or_semi) /*  FORMAT-DIRECTIVE-CHARACTER */;
     if (!(ecl_char_code(T0)==ecl_char_code(CODE_CHAR(93)))) { goto L15; }
     goto L4;
L15:;
     v3last_semi_with_colon_p = ecl_function_dispatch(cl_env_copy,VV[251])(1, v5close_or_semi) /*  FORMAT-DIRECTIVE-COLONP */;
    }
   }
   goto L5;
L4:;
   cl_env_copy->nvalues = 3;
   cl_env_copy->values[2] = v4remaining;
   cl_env_copy->values[1] = v3last_semi_with_colon_p;
   cl_env_copy->values[0] = v2sublists;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G1626                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC91__g1626(cl_object v1, cl_object v2directives)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   v3 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v1) /*  FORMAT-DIRECTIVE-COLONP */;
   v4 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v1) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v5 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v1) /*  FORMAT-DIRECTIVE-PARAMS */;
   {
    cl_object v7;                                 /*  SUBLISTS        */
    cl_object v8;                                 /*  LAST-SEMI-WITH-COLON-P */
    cl_object v9;                                 /*  REMAINING       */
    value0 = L90parse_conditional_directive(v2directives);
    v7 = value0;
    {
     const int v10 = cl_env_copy->nvalues;
     cl_object v11;
     v11 = (v10<=1)? ECL_NIL : cl_env_copy->values[1];
     v8 = v11;
     v11 = (v10<=2)? ECL_NIL : cl_env_copy->values[2];
     v9 = v11;
    }
    if (Null(v4)) { goto L6; }
    if (Null(v3)) { goto L8; }
    T0 = cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_51);
    goto L5;
L8:;
    if (Null(ecl_cdr(v7))) { goto L10; }
    T0 = cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_52);
    goto L5;
L10:;
    if (Null(v5)) { goto L12; }
    T1 = ecl_caar(v5);
    cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_20, ECL_SYM("OFFSET",1279), T1);
L12:;
    T1 = ecl_car(v7);
    T0 = L93expand_maybe_conditional(T1);
    goto L5;
L6:;
    if (Null(v3)) { goto L14; }
    {
     cl_fixnum v10;
     v10 = ecl_length(v7);
     if (!((v10)==(2))) { goto L16; }
    }
    if (Null(v5)) { goto L18; }
    T1 = ecl_caar(v5);
    cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_20, ECL_SYM("OFFSET",1279), T1);
L18:;
    T1 = ecl_car(v7);
    T2 = ecl_cadr(v7);
    T0 = L95expand_true_false_conditional(T1, T2);
    goto L5;
L16:;
    T0 = cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_53);
    goto L5;
L14:;
    {
     cl_object v10;
     v10 = v5;
     {
      cl_object v11param_and_offset;
      cl_object v12offset;
      cl_object v13param;
      {
       cl_object v14;
       v14 = v10;
       if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
       if (Null(v14)) { goto L26; }
       {
        cl_object v15;
        v15 = ECL_CONS_CDR(v14);
        v10 = v15;
        v14 = ECL_CONS_CAR(v14);
       }
L26:;
       v11param_and_offset = v14;
      }
      v12offset = ecl_car(v11param_and_offset);
      v13param = ecl_cdr(v11param_and_offset);
      if (!(ecl_eql(v13param,VV[17]))) { goto L34; }
      T2 = L14expand_next_arg(1, v12offset);
      T1 = cl_list(3, ECL_SYM("OR",614), T2, ECL_NIL);
      goto L21;
L34:;
      if (!(ecl_eql(v13param,VV[18]))) { goto L36; }
      cl_set(VV[28],ECL_NIL);
      T1 = VV[54];
      goto L21;
L36:;
      if (!((v13param)==(ECL_NIL))) { goto L40; }
      T1 = ECL_NIL;
      goto L21;
L40:;
      T1 = v13param;
     }
L21:;
     T2 = cl_list(2, VV[183], T1);
     T3 = ecl_list1(T2);
     if (Null(v10)) { goto L44; }
     T5 = ecl_list1(ecl_make_fixnum(1));
     T6 = ecl_caar(v10);
     T4 = cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T5, ECL_SYM("OFFSET",1279), T6);
     goto L43;
L44:;
     T4 = ECL_NIL;
L43:;
     cl_set(VV[28],ECL_NIL);
     {
      cl_object v11clauses;
      cl_object v12case;
      v11clauses = ECL_NIL;
      T6 = L14expand_next_arg(0);
      v12case = cl_list(3, ECL_SYM("OR",614), VV[183], T6);
      if (Null(v8)) { goto L50; }
      {
       cl_object v13;
       v13 = v7;
       if (ecl_unlikely(!ECL_LISTP(v13))) FEtype_error_list(v13);
       if (Null(v13)) { goto L57; }
       {
        cl_object v14;
        v14 = ECL_CONS_CDR(v13);
        v7 = v14;
        v13 = ECL_CONS_CAR(v13);
       }
L57:;
       T6 = v13;
      }
      T7 = L12expand_directive_list(T6);
      T8 = CONS(ECL_T,T7);
      v11clauses = CONS(T8,v11clauses);
L50:;
      {
       cl_object v13count;
       v13count = ecl_make_fixnum(ecl_length(v7));
       {
        cl_object v14;
        v14 = v7;
        goto L68;
L67:;
        {
         cl_object v15sublist;
         v15sublist = ecl_car(v14);
         v13count = ecl_minus(v13count,ecl_make_fixnum(1));
         T6 = v13count;
         T7 = L12expand_directive_list(v15sublist);
         T8 = CONS(T6,T7);
         v11clauses = CONS(T8,v11clauses);
        }
        v14 = ecl_cdr(v14);
L68:;
        if (Null(v14)) { goto L78; }
        goto L67;
L78:;
       }
      }
      T5 = cl_listX(3, ECL_SYM("CASE",181), v12case, v11clauses);
     }
     T6 = cl_list(2, ECL_NIL, T5);
     T7 = ecl_append(T4,T6);
     T0 = cl_listX(3, ECL_SYM("LET",477), T3, T7);
    }
L5:;
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = v9;
    cl_env_copy->values[0] = T0;
    return cl_env_copy->values[0];
   }
  }
 }
}
/*	function definition for EXPAND-MAYBE-CONDITIONAL              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L93expand_maybe_conditional(cl_object v1sublist)
{
 cl_object T0;
 volatile cl_object lex0[1];
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  lex0[0] = v1sublist;                            /*  SUBLIST         */
TTL:
  if (Null(ecl_symbol_value(VV[28]))) { goto L1; }
  {
   cl_object v3;                                  /*  GUTS            */
   cl_object v4;                                  /*  NEW-ARGS        */
   ecl_bds_push(cl_env_copy,VV[30]);              /*  *SIMPLE-ARGS*   */
   T0 = L12expand_directive_list(lex0[0]);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = ecl_symbol_value(VV[30]);
   cl_env_copy->values[0] = T0;
   value0 = cl_env_copy->values[0];
   ecl_bds_unwind1(cl_env_copy);
   v3 = value0;
   v4 = cl_env_copy->values[1];
   if (Null(v4)) { goto L4; }
   T0 = ecl_cdr(v4);
   if (!((ecl_symbol_value(VV[30]))==(T0))) { goto L4; }
   cl_set(VV[30],v4);
   T0 = ecl_caar(v4);
   value0 = cl_listX(3, ECL_SYM("WHEN",905), T0, v3);
   return value0;
L4:;
   cl_set(VV[28],ECL_NIL);
   value0 = LC92hairy(lex0);
   return value0;
  }
L1:;
  value0 = LC92hairy(lex0);
  return value0;
 }
}
/*	local function HAIRY                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC92hairy(volatile cl_object *lex0)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = L14expand_next_arg(0);
  T1 = cl_list(2, VV[62], T0);
  T2 = cl_list(2, VV[184], T1);
  T3 = L12expand_directive_list(lex0[0]);
  T4 = cl_listX(4, ECL_SYM("WHEN",905), VV[62], VV[185], T3);
  value0 = cl_list(3, ECL_SYM("LET",477), T2, T4);
  return value0;
 }
}
/*	function definition for EXPAND-TRUE-FALSE-CONDITIONAL         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L95expand_true_false_conditional(cl_object v1true, cl_object v2false)
{
 cl_object T0, T1, T2, T3, T4;
 volatile cl_object lex0[3];
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  lex0[0] = v1true;                               /*  TRUE            */
  lex0[1] = v2false;                              /*  FALSE           */
TTL:
  T0 = L14expand_next_arg(0);
  lex0[2] = T0;                                   /*  ARG             */
  if (Null(ecl_symbol_value(VV[28]))) { goto L1; }
  {
   cl_object v4;                                  /*  TRUE-GUTS       */
   cl_object v5;                                  /*  TRUE-ARGS       */
   cl_object v6;                                  /*  TRUE-SIMPLE     */
   {
    cl_object v7;
    v7 = ecl_symbol_value(VV[30]);
    ecl_bds_bind(cl_env_copy,VV[30],v7);          /*  *SIMPLE-ARGS*   */
    ecl_bds_bind(cl_env_copy,VV[28],ECL_T);       /*  *ONLY-SIMPLE-ARGS* */
    T0 = L12expand_directive_list(lex0[0]);
    cl_env_copy->nvalues = 3;
    cl_env_copy->values[2] = ecl_symbol_value(VV[28]);
    cl_env_copy->values[1] = ecl_symbol_value(VV[30]);
    cl_env_copy->values[0] = T0;
    value0 = cl_env_copy->values[0];
    ecl_bds_unwind1(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
   }
   v4 = value0;
   v5 = cl_env_copy->values[1];
   v6 = cl_env_copy->values[2];
   {
    cl_object v8;                                 /*  FALSE-GUTS      */
    cl_object v9;                                 /*  FALSE-ARGS      */
    cl_object v10;                                /*  FALSE-SIMPLE    */
    {
     cl_object v11;
     v11 = ecl_symbol_value(VV[30]);
     ecl_bds_bind(cl_env_copy,VV[30],v11);        /*  *SIMPLE-ARGS*   */
     ecl_bds_bind(cl_env_copy,VV[28],ECL_T);      /*  *ONLY-SIMPLE-ARGS* */
     T0 = L12expand_directive_list(lex0[1]);
     cl_env_copy->nvalues = 3;
     cl_env_copy->values[2] = ecl_symbol_value(VV[28]);
     cl_env_copy->values[1] = ecl_symbol_value(VV[30]);
     cl_env_copy->values[0] = T0;
     value0 = cl_env_copy->values[0];
     ecl_bds_unwind1(cl_env_copy);
     ecl_bds_unwind1(cl_env_copy);
    }
    v8 = value0;
    v9 = cl_env_copy->values[1];
    v10 = cl_env_copy->values[2];
    {
     cl_fixnum v11;
     v11 = ecl_length(v5);
     {
      cl_fixnum v12;
      v12 = ecl_length(v9);
      if (!((v11)==(v12))) { goto L7; }
     }
    }
    T0 = CONS(ECL_SYM("PROGN",671),v4);
    {
     cl_object v11false;
     cl_object v12true;
     cl_object v13bindings;
     v11false = v9;
     v12true = v5;
     v13bindings = ECL_NIL;
     goto L15;
L14:;
     {
      cl_object v14;
      v14 = ecl_cdr(v11false);
      {
       cl_object v15;
       v15 = ecl_cdr(v12true);
       T2 = ecl_caar(v11false);
       T3 = ecl_caar(v12true);
       T4 = cl_list(2, T2, T3);
       v13bindings = CONS(T4,v13bindings);
       v12true = v15;
       v11false = v14;
      }
     }
L15:;
     if ((v12true)==(ecl_symbol_value(VV[30]))) { goto L21; }
     goto L14;
L21:;
     cl_set(VV[30],v5);
     if (Null(v6)) { goto L28; }
     cl_set(VV[28],v10);
     goto L26;
L28:;
     cl_set(VV[28],ECL_NIL);
     goto L26;
L26:;
     if (Null(v13bindings)) { goto L30; }
     T1 = cl_listX(3, ECL_SYM("LET",477), v13bindings, v8);
     goto L9;
L30:;
     T1 = CONS(ECL_SYM("PROGN",671),v8);
    }
L9:;
    value0 = cl_list(4, ECL_SYM("IF",946), lex0[2], T0, T1);
    return value0;
L7:;
    cl_set(VV[28],ECL_NIL);
    value0 = LC94hairy(lex0);
    return value0;
   }
  }
L1:;
  value0 = LC94hairy(lex0);
  return value0;
 }
}
/*	local function HAIRY                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC94hairy(volatile cl_object *lex0)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = L12expand_directive_list(lex0[0]);
  T1 = CONS(ECL_SYM("PROGN",671),T0);
  T2 = L12expand_directive_list(lex0[1]);
  T3 = CONS(ECL_SYM("PROGN",671),T2);
  value0 = cl_list(4, ECL_SYM("IF",946), lex0[2], T1, T3);
  return value0;
 }
}
/*	local function G1664                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC96__g1664(cl_object v1stream, cl_object v2, cl_object v3directives, cl_object v4orig_args, cl_object v5args)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6;
   cl_object v7;
   cl_object v8;
   v6 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v2) /*  FORMAT-DIRECTIVE-COLONP */;
   v7 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v2) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v8 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v2) /*  FORMAT-DIRECTIVE-PARAMS */;
   {
    cl_object v10;                                /*  SUBLISTS        */
    cl_object v11;                                /*  LAST-SEMI-WITH-COLON-P */
    cl_object v12;                                /*  REMAINING       */
    value0 = L90parse_conditional_directive(v3directives);
    v10 = value0;
    {
     const int v13 = cl_env_copy->nvalues;
     cl_object v14;
     v14 = (v13<=1)? ECL_NIL : cl_env_copy->values[1];
     v11 = v14;
     v14 = (v13<=2)? ECL_NIL : cl_env_copy->values[2];
     v12 = v14;
    }
    if (Null(v7)) { goto L8; }
    if (Null(v6)) { goto L10; }
    v5args = cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_51);
    goto L7;
L10:;
    if (Null(ecl_cdr(v10))) { goto L12; }
    v5args = cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_52);
    goto L7;
L12:;
    if (Null(v8)) { goto L14; }
    T1 = ecl_list1(ecl_make_fixnum(0));
    T2 = ecl_caar(v8);
    cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T1, ECL_SYM("OFFSET",1279), T2);
L14:;
    {
     cl_object v13;
     cl_object v14;
     v13 = v5args;
     if (!(v5args==ECL_NIL)) { goto L18; }
     cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L18:;
     if (Null(ecl_symbol_value(VV[25]))) { goto L20; }
     ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L20:;
     {
      cl_object v15;
      v15 = v5args;
      if (ecl_unlikely(!ECL_LISTP(v15))) FEtype_error_list(v15);
      if (Null(v15)) { goto L25; }
      {
       cl_object v16;
       v16 = ECL_CONS_CDR(v15);
       v5args = v16;
       v15 = ECL_CONS_CAR(v15);
      }
L25:;
      v14 = v15;
     }
     if (Null(v14)) { goto L31; }
     T1 = ecl_car(v10);
     v5args = L8interpret_directive_list(v1stream, T1, v4orig_args, v13);
     goto L7;
L31:;
     goto L7;
    }
L8:;
    if (Null(v6)) { goto L33; }
    {
     cl_fixnum v15;
     v15 = ecl_length(v10);
     if (!((v15)==(2))) { goto L35; }
    }
    if (Null(v8)) { goto L37; }
    T1 = ecl_list1(ecl_make_fixnum(0));
    T2 = ecl_caar(v8);
    cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T1, ECL_SYM("OFFSET",1279), T2);
L37:;
    if (!(v5args==ECL_NIL)) { goto L41; }
    cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L41:;
    if (Null(ecl_symbol_value(VV[25]))) { goto L43; }
    ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L43:;
    {
     cl_object v15;
     v15 = v5args;
     if (ecl_unlikely(!ECL_LISTP(v15))) FEtype_error_list(v15);
     if (Null(v15)) { goto L48; }
     {
      cl_object v16;
      v16 = ECL_CONS_CDR(v15);
      v5args = v16;
      v15 = ECL_CONS_CAR(v15);
     }
L48:;
     if (Null(v15)) { goto L39; }
    }
    T1 = ecl_car(v10);
    v5args = L8interpret_directive_list(v1stream, T1, v4orig_args, v5args);
    goto L7;
L39:;
    T1 = ecl_cadr(v10);
    v5args = L8interpret_directive_list(v1stream, T1, v4orig_args, v5args);
    goto L7;
L35:;
    v5args = cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_53);
    goto L7;
L33:;
    {
     cl_object v15;
     v15 = v8;
     {
      cl_object v16index;
      {
       cl_object v17param_and_offset;
       cl_object v18offset;
       cl_object v19param;
       {
        cl_object v20;
        v20 = v15;
        if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
        if (Null(v20)) { goto L60; }
        {
         cl_object v21;
         v21 = ECL_CONS_CDR(v20);
         v15 = v21;
         v20 = ECL_CONS_CAR(v20);
        }
L60:;
        v17param_and_offset = v20;
       }
       v18offset = ecl_car(v17param_and_offset);
       v19param = ecl_cdr(v17param_and_offset);
       if (!(ecl_eql(v19param,VV[17]))) { goto L68; }
       if (!(v5args==ECL_NIL)) { goto L73; }
       cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v18offset);
L73:;
       if (Null(ecl_symbol_value(VV[25]))) { goto L75; }
       ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L75:;
       {
        cl_object v20;
        v20 = v5args;
        if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
        if (Null(v20)) { goto L80; }
        {
         cl_object v21;
         v21 = ECL_CONS_CDR(v20);
         v5args = v21;
         v20 = ECL_CONS_CAR(v20);
        }
L80:;
        value0 = v20;
       }
       if ((value0)!=ECL_NIL) { goto L71; }
       if (!(v5args==ECL_NIL)) { goto L86; }
       cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L86:;
       if (Null(ecl_symbol_value(VV[25]))) { goto L88; }
       ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L88:;
       {
        cl_object v20;
        v20 = v5args;
        if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
        if (Null(v20)) { goto L93; }
        {
         cl_object v21;
         v21 = ECL_CONS_CDR(v20);
         v5args = v21;
         v20 = ECL_CONS_CAR(v20);
        }
L93:;
        v16index = v20;
        goto L55;
       }
L71:;
       v16index = value0;
       goto L55;
L68:;
       if (!(ecl_eql(v19param,VV[18]))) { goto L99; }
       v16index = ecl_make_fixnum(ecl_length(v5args));
       goto L55;
L99:;
       if (!((v19param)==(ECL_NIL))) { goto L101; }
       if (!(v5args==ECL_NIL)) { goto L104; }
       cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L104:;
       if (Null(ecl_symbol_value(VV[25]))) { goto L106; }
       ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L106:;
       {
        cl_object v21;
        v21 = v5args;
        if (ecl_unlikely(!ECL_LISTP(v21))) FEtype_error_list(v21);
        if (Null(v21)) { goto L111; }
        {
         cl_object v22;
         v22 = ECL_CONS_CDR(v21);
         v5args = v22;
         v21 = ECL_CONS_CAR(v21);
        }
L111:;
        v16index = v21;
        goto L55;
       }
L101:;
       v16index = v19param;
      }
L55:;
      if (Null(v15)) { goto L117; }
      T1 = ecl_list1(ecl_make_fixnum(1));
      T2 = ecl_caar(v15);
      cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T1, ECL_SYM("OFFSET",1279), T2);
L117:;
      {
       cl_object v17default;
       cl_object v18last;
       cl_object v19sublist;
       if (Null(v11)) { goto L121; }
       {
        cl_object v20;
        v20 = v10;
        if (ecl_unlikely(!ECL_LISTP(v20))) FEtype_error_list(v20);
        if (Null(v20)) { goto L126; }
        {
         cl_object v21;
         v21 = ECL_CONS_CDR(v20);
         v10 = v21;
         v20 = ECL_CONS_CAR(v20);
        }
L126:;
        v17default = v20;
        goto L119;
       }
L121:;
       v17default = ECL_NIL;
       goto L119;
L119:;
       {
        cl_fixnum v20;
        v20 = ecl_length(v10);
        v18last = ecl_make_integer((v20)-1);
       }
       if (Null(cl_LE(3, ecl_make_fixnum(0), v16index, v18last))) { goto L134; }
       T1 = ecl_minus(v18last,v16index);
       v19sublist = ecl_nth(ecl_to_size(T1),v10);
       goto L133;
L134:;
       v19sublist = v17default;
L133:;
       v5args = L8interpret_directive_list(v1stream, v19sublist, v4orig_args, v5args);
      }
     }
    }
L7:;
    T0 = v12;
   }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5args;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G1692                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC97__g1692(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_54);
  return value0;
 }
}
/*	local function G1695                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC98__g1695(cl_object v1stream, cl_object v2, cl_object v3, cl_object v4orig_args, cl_object v5args)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_54);
  return value0;
 }
}
/*	local function G1698                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC99__g1698(cl_object v1stream, cl_object v2, cl_object v3, cl_object v4orig_args, cl_object v5args)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_55);
  return value0;
 }
}
/*	local function G1701                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC100__g1701(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_55);
  return value0;
 }
}
/*	local function G1704                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC101__g1704(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   v3 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v1) /*  FORMAT-DIRECTIVE-COLONP */;
   v4 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v1) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v5 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v1) /*  FORMAT-DIRECTIVE-PARAMS */;
   if (Null(v4)) { goto L4; }
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_56);
L4:;
   if (Null(v3)) { goto L6; }
   if ((ecl_symbol_value(VV[24]))!=ECL_NIL) { goto L6; }
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_57);
L6:;
   {
    cl_object v6;
    v6 = v5;
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L16; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L16:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L24; }
     T2 = L14expand_next_arg(1, v8offset);
     T1 = cl_list(3, ECL_SYM("OR",614), T2, ECL_NIL);
     goto L11;
L24:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L26; }
     cl_set(VV[28],ECL_NIL);
     T1 = VV[54];
     goto L11;
L26:;
     if (!((v9param)==(ECL_NIL))) { goto L30; }
     T1 = ECL_NIL;
     goto L11;
L30:;
     T1 = v9param;
    }
L11:;
    T2 = cl_list(2, VV[187], T1);
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L38; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L38:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L46; }
     T4 = L14expand_next_arg(1, v8offset);
     T3 = cl_list(3, ECL_SYM("OR",614), T4, ECL_NIL);
     goto L33;
L46:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L48; }
     cl_set(VV[28],ECL_NIL);
     T3 = VV[54];
     goto L33;
L48:;
     if (!((v9param)==(ECL_NIL))) { goto L52; }
     T3 = ECL_NIL;
     goto L33;
L52:;
     T3 = v9param;
    }
L33:;
    T4 = cl_list(2, VV[188], T3);
    {
     cl_object v7param_and_offset;
     cl_object v8offset;
     cl_object v9param;
     {
      cl_object v10;
      v10 = v6;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L60; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v6 = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L60:;
      v7param_and_offset = v10;
     }
     v8offset = ecl_car(v7param_and_offset);
     v9param = ecl_cdr(v7param_and_offset);
     if (!(ecl_eql(v9param,VV[17]))) { goto L68; }
     T6 = L14expand_next_arg(1, v8offset);
     T5 = cl_list(3, ECL_SYM("OR",614), T6, ECL_NIL);
     goto L55;
L68:;
     if (!(ecl_eql(v9param,VV[18]))) { goto L70; }
     cl_set(VV[28],ECL_NIL);
     T5 = VV[54];
     goto L55;
L70:;
     if (!((v9param)==(ECL_NIL))) { goto L74; }
     T5 = ECL_NIL;
     goto L55;
L74:;
     T5 = v9param;
    }
L55:;
    T6 = cl_list(2, VV[189], T5);
    T7 = cl_list(3, T2, T4, T6);
    if (Null(v6)) { goto L78; }
    T9 = ecl_list1(ecl_make_fixnum(3));
    T10 = ecl_caar(v6);
    T8 = cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T9, ECL_SYM("OFFSET",1279), T10);
    goto L77;
L78:;
    T8 = ECL_NIL;
L77:;
    T9 = cl_list(4, ECL_SYM("<=",73), VV[187], VV[188], VV[189]);
    T10 = cl_list(2, VV[189], T9);
    T11 = cl_list(3, ECL_SYM("EQL",334), VV[187], VV[188]);
    T12 = cl_list(2, VV[188], T11);
    T13 = cl_list(3, ECL_SYM("EQL",334), VV[187], ecl_make_fixnum(0));
    T14 = cl_list(2, VV[187], T13);
    if (Null(v3)) { goto L81; }
    T15 = VV[190];
    goto L80;
L81:;
    cl_set(VV[28],ECL_NIL);
    T15 = VV[45];
L80:;
    T16 = cl_list(2, ECL_T, T15);
    T17 = cl_list(5, ECL_SYM("COND",247), T10, T12, T14, T16);
    T18 = ecl_list1(T17);
    T19 = ecl_append(T8,T18);
    T0 = cl_listX(3, ECL_SYM("LET",477), T7, T19);
   }
   if (Null(v3)) { goto L86; }
   T1 = VV[191];
   goto L85;
L86:;
   T1 = VV[192];
L85:;
   T2 = cl_list(3, ECL_SYM("WHEN",905), T0, T1);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v2;
   cl_env_copy->values[0] = T2;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G1733                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC102__g1733(cl_object v1stream, cl_object v2, cl_object v3, cl_object v4orig_args, cl_object v5args)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6;
   cl_object v7;
   cl_object v8;
   v6 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v2) /*  FORMAT-DIRECTIVE-COLONP */;
   v7 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v2) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v8 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v2) /*  FORMAT-DIRECTIVE-PARAMS */;
   if (Null(v7)) { goto L4; }
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_58);
L4:;
   if (Null(v6)) { goto L6; }
   if ((ecl_symbol_value(VV[24]))!=ECL_NIL) { goto L6; }
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_57);
L6:;
   {
    cl_object v9;
    v9 = v8;
    {
     cl_object v10arg1;
     cl_object v11arg2;
     cl_object v12arg3;
     {
      cl_object v13param_and_offset;
      cl_object v14offset;
      cl_object v15param;
      {
       cl_object v16;
       v16 = v9;
       if (ecl_unlikely(!ECL_LISTP(v16))) FEtype_error_list(v16);
       if (Null(v16)) { goto L17; }
       {
        cl_object v17;
        v17 = ECL_CONS_CDR(v16);
        v9 = v17;
        v16 = ECL_CONS_CAR(v16);
       }
L17:;
       v13param_and_offset = v16;
      }
      v14offset = ecl_car(v13param_and_offset);
      v15param = ecl_cdr(v13param_and_offset);
      if (!(ecl_eql(v15param,VV[17]))) { goto L25; }
      if (!(v5args==ECL_NIL)) { goto L30; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v14offset);
L30:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L32; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L32:;
      {
       cl_object v16;
       v16 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v16))) FEtype_error_list(v16);
       if (Null(v16)) { goto L37; }
       {
        cl_object v17;
        v17 = ECL_CONS_CDR(v16);
        v5args = v17;
        v16 = ECL_CONS_CAR(v16);
       }
L37:;
       value0 = v16;
      }
      if ((value0)!=ECL_NIL) { goto L28; }
      v10arg1 = ECL_NIL;
      goto L12;
L28:;
      v10arg1 = value0;
      goto L12;
L25:;
      if (!(ecl_eql(v15param,VV[18]))) { goto L43; }
      v10arg1 = ecl_make_fixnum(ecl_length(v5args));
      goto L12;
L43:;
      if (!((v15param)==(ECL_NIL))) { goto L45; }
      v10arg1 = ECL_NIL;
      goto L12;
L45:;
      v10arg1 = v15param;
     }
L12:;
     {
      cl_object v13param_and_offset;
      cl_object v14offset;
      cl_object v15param;
      {
       cl_object v16;
       v16 = v9;
       if (ecl_unlikely(!ECL_LISTP(v16))) FEtype_error_list(v16);
       if (Null(v16)) { goto L53; }
       {
        cl_object v17;
        v17 = ECL_CONS_CDR(v16);
        v9 = v17;
        v16 = ECL_CONS_CAR(v16);
       }
L53:;
       v13param_and_offset = v16;
      }
      v14offset = ecl_car(v13param_and_offset);
      v15param = ecl_cdr(v13param_and_offset);
      if (!(ecl_eql(v15param,VV[17]))) { goto L61; }
      if (!(v5args==ECL_NIL)) { goto L66; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v14offset);
L66:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L68; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L68:;
      {
       cl_object v16;
       v16 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v16))) FEtype_error_list(v16);
       if (Null(v16)) { goto L73; }
       {
        cl_object v17;
        v17 = ECL_CONS_CDR(v16);
        v5args = v17;
        v16 = ECL_CONS_CAR(v16);
       }
L73:;
       value0 = v16;
      }
      if ((value0)!=ECL_NIL) { goto L64; }
      v11arg2 = ECL_NIL;
      goto L48;
L64:;
      v11arg2 = value0;
      goto L48;
L61:;
      if (!(ecl_eql(v15param,VV[18]))) { goto L79; }
      v11arg2 = ecl_make_fixnum(ecl_length(v5args));
      goto L48;
L79:;
      if (!((v15param)==(ECL_NIL))) { goto L81; }
      v11arg2 = ECL_NIL;
      goto L48;
L81:;
      v11arg2 = v15param;
     }
L48:;
     {
      cl_object v13param_and_offset;
      cl_object v14offset;
      cl_object v15param;
      {
       cl_object v16;
       v16 = v9;
       if (ecl_unlikely(!ECL_LISTP(v16))) FEtype_error_list(v16);
       if (Null(v16)) { goto L89; }
       {
        cl_object v17;
        v17 = ECL_CONS_CDR(v16);
        v9 = v17;
        v16 = ECL_CONS_CAR(v16);
       }
L89:;
       v13param_and_offset = v16;
      }
      v14offset = ecl_car(v13param_and_offset);
      v15param = ecl_cdr(v13param_and_offset);
      if (!(ecl_eql(v15param,VV[17]))) { goto L97; }
      if (!(v5args==ECL_NIL)) { goto L102; }
      cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v14offset);
L102:;
      if (Null(ecl_symbol_value(VV[25]))) { goto L104; }
      ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L104:;
      {
       cl_object v16;
       v16 = v5args;
       if (ecl_unlikely(!ECL_LISTP(v16))) FEtype_error_list(v16);
       if (Null(v16)) { goto L109; }
       {
        cl_object v17;
        v17 = ECL_CONS_CDR(v16);
        v5args = v17;
        v16 = ECL_CONS_CAR(v16);
       }
L109:;
       value0 = v16;
      }
      if ((value0)!=ECL_NIL) { goto L100; }
      v12arg3 = ECL_NIL;
      goto L84;
L100:;
      v12arg3 = value0;
      goto L84;
L97:;
      if (!(ecl_eql(v15param,VV[18]))) { goto L115; }
      v12arg3 = ecl_make_fixnum(ecl_length(v5args));
      goto L84;
L115:;
      if (!((v15param)==(ECL_NIL))) { goto L117; }
      v12arg3 = ECL_NIL;
      goto L84;
L117:;
      v12arg3 = v15param;
     }
L84:;
     if (Null(v9)) { goto L120; }
     T0 = ecl_list1(ecl_make_fixnum(3));
     T1 = ecl_caar(v9);
     cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T0, ECL_SYM("OFFSET",1279), T1);
L120:;
     if (Null(v12arg3)) { goto L122; }
     if (Null(cl_LE(3, v10arg1, v11arg2, v12arg3))) { goto L9; }
     goto L10;
L122:;
     if (Null(v11arg2)) { goto L124; }
     if (!(ecl_eql(v10arg1,v11arg2))) { goto L9; }
     goto L10;
L124:;
     if (Null(v10arg1)) { goto L126; }
     if (!((v10arg1)==(ecl_make_fixnum(0)))) { goto L9; }
     goto L10;
L126:;
     if (Null(v6)) { goto L128; }
     if (!(ecl_symbol_value(VV[186])==ECL_NIL)) { goto L9; }
     goto L10;
L128:;
     if (!(v5args==ECL_NIL)) { goto L9; }
    }
   }
L10:;
   if (Null(v6)) { goto L131; }
   T0 = VV[193];
   goto L130;
L131:;
   T0 = VV[31];
L130:;
   cl_env_copy->values[0] = v5args;
   cl_env_copy->nvalues = 1;
   cl_throw(T0);
L9:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5args;
   cl_env_copy->values[0] = v3;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G1757                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC107__g1757(cl_object v1, cl_object v2directives)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9;
 volatile cl_object lex0[7];
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  lex0[0] = v2directives;                         /*  DIRECTIVES      */
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6;
   cl_object v7;
   v3 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v1) /*  FORMAT-DIRECTIVE-COLONP */;
   v4 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v1) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v5 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v1) /*  FORMAT-DIRECTIVE-PARAMS */;
   v6 = ecl_function_dispatch(cl_env_copy,VV[269])(1, v1) /*  FORMAT-DIRECTIVE-STRING */;
   v7 = ecl_function_dispatch(cl_env_copy,VV[243])(1, v1) /*  FORMAT-DIRECTIVE-END */;
   lex0[1] = v3;                                  /*  COLONP          */
   lex0[2] = v4;                                  /*  ATSIGNP         */
   lex0[3] = v6;                                  /*  STRING          */
   lex0[4] = v7;                                  /*  END             */
   {
    cl_object v8close;
    v8close = L21find_directive(lex0[0], CODE_CHAR(125), ECL_NIL);
    if ((v8close)!=ECL_NIL) { goto L7; }
    cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_59);
L7:;
    T0 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v8close) /*  FORMAT-DIRECTIVE-COLONP */;
    lex0[5] = T0;                                 /*  CLOSED-WITH-COLON */
    T0 = cl_position(2, v8close, lex0[0]);
    lex0[6] = T0;                                 /*  POSN            */
    if (Null(v5)) { goto L10; }
    {
     cl_object v9;
     v9 = v5;
     {
      cl_object v10param_and_offset;
      cl_object v11offset;
      cl_object v12param;
      {
       cl_object v13;
       v13 = v9;
       if (ecl_unlikely(!ECL_LISTP(v13))) FEtype_error_list(v13);
       if (Null(v13)) { goto L18; }
       {
        cl_object v14;
        v14 = ECL_CONS_CDR(v13);
        v9 = v14;
        v13 = ECL_CONS_CAR(v13);
       }
L18:;
       v10param_and_offset = v13;
      }
      v11offset = ecl_car(v10param_and_offset);
      v12param = ecl_cdr(v10param_and_offset);
      if (!(ecl_eql(v12param,VV[17]))) { goto L26; }
      T2 = L14expand_next_arg(1, v11offset);
      T1 = cl_list(3, ECL_SYM("OR",614), T2, ECL_NIL);
      goto L13;
L26:;
      if (!(ecl_eql(v12param,VV[18]))) { goto L28; }
      cl_set(VV[28],ECL_NIL);
      T1 = VV[54];
      goto L13;
L28:;
      if (!((v12param)==(ECL_NIL))) { goto L32; }
      T1 = ECL_NIL;
      goto L13;
L32:;
      T1 = v12param;
     }
L13:;
     T2 = cl_list(2, VV[202], T1);
     T3 = ecl_list1(T2);
     if (Null(v9)) { goto L36; }
     T5 = ecl_list1(ecl_make_fixnum(1));
     T6 = ecl_caar(v9);
     T4 = cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T5, ECL_SYM("OFFSET",1279), T6);
     goto L35;
L36:;
     T4 = ECL_NIL;
L35:;
     if (!(ecl_zerop(lex0[6]))) { goto L39; }
     T6 = L14expand_next_arg(0);
     T7 = cl_list(2, VV[203], T6);
     T8 = ecl_list1(T7);
     T9 = LC106compute_bindings(lex0, VV[202]);
     T5 = cl_list(3, ECL_SYM("LET",477), T8, T9);
     goto L38;
L39:;
     T5 = LC106compute_bindings(lex0, VV[202]);
L38:;
     T6 = ecl_list1(T5);
     T7 = ecl_append(T4,T6);
     T0 = cl_listX(3, ECL_SYM("LET",477), T3, T7);
     goto L9;
    }
L10:;
    if (!(ecl_zerop(lex0[6]))) { goto L42; }
    T1 = L14expand_next_arg(0);
    T2 = cl_list(2, VV[203], T1);
    T3 = ecl_list1(T2);
    T4 = LC106compute_bindings(lex0, ECL_NIL);
    T0 = cl_list(3, ECL_SYM("LET",477), T3, T4);
    goto L9;
L42:;
    T0 = LC106compute_bindings(lex0, ECL_NIL);
L9:;
    T1 = ecl_one_plus(lex0[6]);
    T2 = ecl_nthcdr(ecl_to_size(T1),lex0[0]);
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = T2;
    cl_env_copy->values[0] = T0;
    return cl_env_copy->values[0];
   }
  }
 }
}
/*	local function COMPUTE-BINDINGS                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC106compute_bindings(volatile cl_object *lex0, cl_object v1count)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(lex0[2])) { goto L1; }
  value0 = LC105compute_block(lex0, v1count);
  return value0;
L1:;
  T0 = L14expand_next_arg(0);
  T1 = cl_list(2, VV[166], T0);
  T2 = cl_list(2, T1, VV[200]);
  ecl_bds_bind(cl_env_copy,VV[26],VV[27]);        /*  *EXPANDER-NEXT-ARG-MACRO* */
  ecl_bds_bind(cl_env_copy,VV[28],ECL_NIL);       /*  *ONLY-SIMPLE-ARGS* */
  ecl_bds_bind(cl_env_copy,VV[29],ECL_T);         /*  *ORIG-ARGS-AVAILABLE* */
  T3 = LC105compute_block(lex0, v1count);
  ecl_bds_unwind1(cl_env_copy);
  ecl_bds_unwind1(cl_env_copy);
  ecl_bds_unwind1(cl_env_copy);
  value0 = cl_list(4, ECL_SYM("LET*",478), T2, VV[201], T3);
  return value0;
 }
}
/*	local function COMPUTE-BLOCK                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC105compute_block(volatile cl_object *lex0, cl_object v1count)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(lex0[1])) { goto L1; }
  T0 = LC104compute_loop(lex0, v1count);
  value0 = cl_list(3, ECL_SYM("BLOCK",137), VV[199], T0);
  return value0;
L1:;
  value0 = LC104compute_loop(lex0, v1count);
  return value0;
 }
}
/*	local function COMPUTE-LOOP                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC104compute_loop(volatile cl_object *lex0, cl_object v1count)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(lex0[2])) { goto L1; }
  cl_set(VV[28],ECL_NIL);
L1:;
  if ((lex0[5])!=ECL_NIL) { goto L5; }
  T0 = VV[196];
  goto L4;
L5:;
  T0 = ECL_NIL;
L4:;
  if (Null(v1count)) { goto L8; }
  T2 = cl_list(2, ECL_SYM("DECF",271), v1count);
  T3 = cl_list(2, ECL_SYM("MINUSP",558), T2);
  T4 = cl_list(3, ECL_SYM("AND",87), v1count, T3);
  T5 = cl_list(3, ECL_SYM("WHEN",905), T4, VV[192]);
  T1 = ecl_list1(T5);
  goto L7;
L8:;
  T1 = ECL_NIL;
L7:;
  if (Null(lex0[1])) { goto L11; }
  ecl_bds_bind(cl_env_copy,VV[26],VV[27]);        /*  *EXPANDER-NEXT-ARG-MACRO* */
  ecl_bds_bind(cl_env_copy,VV[28],ECL_NIL);       /*  *ONLY-SIMPLE-ARGS* */
  ecl_bds_bind(cl_env_copy,VV[29],ECL_T);         /*  *ORIG-ARGS-AVAILABLE* */
  T3 = L14expand_next_arg(0);
  T4 = cl_list(2, VV[166], T3);
  T5 = CONS(T4,VV[197]);
  T6 = LC103compute_insides(lex0);
  T7 = cl_listX(3, ECL_SYM("BLOCK",137), ECL_NIL, T6);
  T8 = cl_list(4, ECL_SYM("LET*",478), T5, VV[198], T7);
  T9 = ecl_list1(T8);
  ecl_bds_unwind1(cl_env_copy);
  ecl_bds_unwind1(cl_env_copy);
  ecl_bds_unwind1(cl_env_copy);
  T2 = T9;
  goto L10;
L11:;
  T2 = LC103compute_insides(lex0);
L10:;
  if (Null(lex0[5])) { goto L15; }
  T3 = VV[196];
  goto L14;
L15:;
  T3 = ECL_NIL;
L14:;
  T4 = cl_append(4, T0, T1, T2, T3);
  value0 = CONS(ECL_SYM("LOOP",512),T4);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function COMPUTE-INSIDES                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC103compute_insides(volatile cl_object *lex0)
{
 cl_object T0, T1, T2, T3, T4, T5;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ecl_zerop(lex0[6]))) { goto L1; }
  if (Null(ecl_symbol_value(VV[29]))) { goto L3; }
  T0 = ecl_one_minus(lex0[4]);
  T1 = cl_list(12, ECL_SYM("ERROR",337), VV[37], VV[14], _ecl_static_47, VV[194], VV[177], VV[178], ECL_NIL, ECL_SYM("CONTROL-STRING",1211), lex0[3], ECL_SYM("OFFSET",1279), T0);
  T2 = cl_list(3, ECL_SYM("LAMBDA",452), VV[176], T1);
  T3 = cl_list(2, ECL_SYM("FORMAT-ERROR",1074), T2);
  T4 = ecl_list1(T3);
  T5 = cl_list(3, ECL_SYM("HANDLER-BIND",417), T4, VV[195]);
  value0 = ecl_list1(T5);
  cl_env_copy->nvalues = 1;
  return value0;
L3:;
  cl_env_copy->values[0] = ECL_NIL;
  cl_env_copy->nvalues = 1;
  cl_throw(VV[36]);
L1:;
  ecl_bds_bind(cl_env_copy,VV[24],lex0[1]);       /*  *UP-UP-AND-OUT-ALLOWED* */
  T0 = cl_subseq(3, lex0[0], ecl_make_fixnum(0), lex0[6]);
  value0 = L12expand_directive_list(T0);
  ecl_bds_unwind1(cl_env_copy);
  return value0;
 }
}
/*	local function G1778                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC112__g1778(cl_object volatile v1stream, cl_object volatile v2, cl_object volatile v3directives, cl_object volatile v4orig_args, cl_object volatile v5args)
{
 cl_object T0, T1, T2;
 cl_object volatile env0;
 volatile struct ecl_cclosure aux_closure;
 cl_object volatile CLV0, CLV1, CLV2, CLV3, CLV4, CLV5, CLV6, CLV7
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1stream,env0);              /*  STREAM          */
  {
   volatile cl_object v6;
   volatile cl_object v7;
   volatile cl_object v8;
   volatile cl_object v9;
   volatile cl_object v10;
   volatile cl_object env1 = env0;
   v6 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v2) /*  FORMAT-DIRECTIVE-COLONP */;
   v7 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v2) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v8 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v2) /*  FORMAT-DIRECTIVE-PARAMS */;
   v9 = ecl_function_dispatch(cl_env_copy,VV[269])(1, v2) /*  FORMAT-DIRECTIVE-STRING */;
   v10 = ecl_function_dispatch(cl_env_copy,VV[243])(1, v2) /*  FORMAT-DIRECTIVE-END */;
   CLV1 = env1 = CONS(v6,env1);                   /*  COLONP          */
   CLV2 = env1 = CONS(v9,env1);                   /*  STRING          */
   CLV3 = env1 = CONS(v10,env1);                  /*  END             */
   {
    volatile cl_object v11close;
    v11close = L21find_directive(v3directives, CODE_CHAR(125), ECL_NIL);
    if ((v11close)!=ECL_NIL) { goto L8; }
    cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_60);
L8:;
    {
     volatile cl_object v12;
     v12 = v8;
     {
      volatile cl_object env2 = env1;
      {
       cl_object v13param_and_offset;
       cl_object v14offset;
       cl_object v15param;
       {
        cl_object v16;
        v16 = v12;
        if (ecl_unlikely(!ECL_LISTP(v16))) FEtype_error_list(v16);
        if (Null(v16)) { goto L16; }
        {
         cl_object v17;
         v17 = ECL_CONS_CDR(v16);
         v12 = v17;
         v16 = ECL_CONS_CAR(v16);
        }
L16:;
        v13param_and_offset = v16;
       }
       v14offset = ecl_car(v13param_and_offset);
       v15param = ecl_cdr(v13param_and_offset);
       if (!(ecl_eql(v15param,VV[17]))) { goto L24; }
       if (!(v5args==ECL_NIL)) { goto L29; }
       cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v14offset);
L29:;
       if (Null(ecl_symbol_value(VV[25]))) { goto L31; }
       ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L31:;
       {
        cl_object v16;
        v16 = v5args;
        if (ecl_unlikely(!ECL_LISTP(v16))) FEtype_error_list(v16);
        if (Null(v16)) { goto L36; }
        {
         cl_object v17;
         v17 = ECL_CONS_CDR(v16);
         v5args = v17;
         v16 = ECL_CONS_CAR(v16);
        }
L36:;
        value0 = v16;
       }
       if ((value0)!=ECL_NIL) { goto L27; }
       T1 = ECL_NIL;
       goto L11;
L27:;
       T1 = value0;
       goto L11;
L24:;
       if (!(ecl_eql(v15param,VV[18]))) { goto L42; }
       T1 = ecl_make_fixnum(ecl_length(v5args));
       goto L11;
L42:;
       if (!((v15param)==(ECL_NIL))) { goto L44; }
       T1 = ECL_NIL;
       goto L11;
L44:;
       T1 = v15param;
      }
L11:;
      CLV4 = env2 = CONS(T1,env2);                /*  MAX-COUNT       */
      if (Null(v12)) { goto L47; }
      T1 = ecl_list1(ecl_make_fixnum(1));
      T2 = ecl_caar(v12);
      cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T1, ECL_SYM("OFFSET",1279), T2);
L47:;
      {
       volatile cl_object env3 = env2;
       T1 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v11close) /*  FORMAT-DIRECTIVE-COLONP */;
       CLV5 = env3 = CONS(T1,env3);               /*  CLOSED-WITH-COLON */
       T1 = cl_position(2, v11close, v3directives);
       CLV6 = env3 = CONS(T1,env3);               /*  POSN            */
       if (!(ecl_zerop(ECL_CONS_CAR(CLV6)))) { goto L50; }
       if (!(v5args==ECL_NIL)) { goto L52; }
       cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L52:;
       if (Null(ecl_symbol_value(VV[25]))) { goto L54; }
       ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L54:;
       {
        cl_object v13;
        v13 = v5args;
        if (ecl_unlikely(!ECL_LISTP(v13))) FEtype_error_list(v13);
        if (Null(v13)) { goto L59; }
        {
         cl_object v14;
         v14 = ECL_CONS_CDR(v13);
         v5args = v14;
         v13 = ECL_CONS_CAR(v13);
        }
L59:;
        T1 = v13;
        goto L49;
       }
L50:;
       T1 = cl_subseq(3, v3directives, ecl_make_fixnum(0), ECL_CONS_CAR(CLV6));
L49:;
       CLV7 = env3 = CONS(T1,env3);               /*  INSIDES         */
       ecl_bds_bind(cl_env_copy,VV[24],ECL_CONS_CAR(CLV1)); /*  *UP-UP-AND-OUT-ALLOWED* */
       if (Null(v7)) { goto L66; }
       v5args = (aux_closure.env=env3,cl_env_copy->function=(cl_object)&aux_closure,LC111do_loop(2, v4orig_args, v5args));
       goto L65;
L66:;
       {
        cl_object v13;
        if (!(v5args==ECL_NIL)) { goto L70; }
        cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L70:;
        if (Null(ecl_symbol_value(VV[25]))) { goto L72; }
        ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L72:;
        {
         cl_object v14;
         v14 = v5args;
         if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
         if (Null(v14)) { goto L77; }
         {
          cl_object v15;
          v15 = ECL_CONS_CDR(v14);
          v5args = v15;
          v14 = ECL_CONS_CAR(v14);
         }
L77:;
         v13 = v14;
        }
        ecl_bds_bind(cl_env_copy,VV[25],ECL_NIL); /*  *LOGICAL-BLOCK-POPPER* */
        (aux_closure.env=env3,cl_env_copy->function=(cl_object)&aux_closure,LC111do_loop(2, v13, v13));
        ecl_bds_unwind1(cl_env_copy);
       }
L65:;
       T1 = ecl_one_plus(ECL_CONS_CAR(CLV6));
       T2 = ecl_nthcdr(ecl_to_size(T1),v3directives);
       ecl_bds_unwind1(cl_env_copy);
       T0 = T2;
      }
     }
    }
   }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5args;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	closure DO-LOOP                                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC111do_loop(volatile cl_narg narg, cl_object volatile v1orig_args, cl_object volatile v2args, ...)
{
 cl_object T0, T1;
 volatile struct ecl_cclosure aux_closure;
 cl_object volatile CLV0, CLV1, CLV2, CLV3, CLV4, CLV5, CLV6, CLV7
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object volatile env0 = cl_env_copy->function->cclosure.env;
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV7 = env0;                                     /*  INSIDES         */
 CLV6 = _ecl_cdr(CLV7);
 CLV5 = _ecl_cdr(CLV6);
 CLV4 = _ecl_cdr(CLV5);
 CLV3 = _ecl_cdr(CLV4);
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  if (Null(ECL_CONS_CAR(CLV1))) { goto L3; }
  value0 = VV[193];
  goto L2;
L3:;
  value0 = VV[31];
L2:;
  if (ecl_frs_push(cl_env_copy,value0)) {         /*  BEGIN CATCH 1   */
   value0 = cl_env_copy->values[0];
  } else {
L8:;
   if ((ECL_CONS_CAR(CLV5))!=ECL_NIL) { goto L10; }
   if (!(v2args==ECL_NIL)) { goto L10; }
   goto L7;
L10:;
   if (Null(ECL_CONS_CAR(CLV4))) { goto L13; }
   T1 = ECL_CONS_CAR(CLV4);
   ECL_CONS_CAR(CLV4) = ecl_minus(T1,ecl_make_fixnum(1));
   T0 = ECL_CONS_CAR(CLV4);
   if (!(ecl_minusp(T0))) { goto L13; }
   goto L7;
L13:;
   v2args = (aux_closure.env=env0,cl_env_copy->function=(cl_object)&aux_closure,LC110bind_args(2, v1orig_args, v2args));
   if (Null(ECL_CONS_CAR(CLV5))) { goto L9; }
   if (!(v2args==ECL_NIL)) { goto L9; }
   goto L7;
L9:;
   goto L8;
L7:;
   value0 = v2args;
   cl_env_copy->nvalues = 1;
  }
  ecl_frs_pop(cl_env_copy);                       /*  END CATCH 1     */
  return value0;
 }
 }
}
/*	closure BIND-ARGS                                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC110bind_args(volatile cl_narg narg, cl_object volatile v1orig_args, cl_object volatile v2args, ...)
{
 volatile struct ecl_cclosure aux_closure;
 cl_object volatile CLV0, CLV1, CLV2, CLV3, CLV4, CLV5, CLV6, CLV7
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object volatile env0 = cl_env_copy->function->cclosure.env;
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV7 = env0;                                     /*  INSIDES         */
 CLV6 = _ecl_cdr(CLV7);
 CLV5 = _ecl_cdr(CLV6);
 CLV4 = _ecl_cdr(CLV5);
 CLV3 = _ecl_cdr(CLV4);
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  if (Null(ECL_CONS_CAR(CLV1))) { goto L1; }
  {
   volatile cl_object v3arg;
   if (!(v2args==ECL_NIL)) { goto L4; }
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L4:;
   if (Null(ecl_symbol_value(VV[25]))) { goto L6; }
   ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L6:;
   {
    cl_object v4;
    v4 = v2args;
    if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
    if (Null(v4)) { goto L11; }
    {
     cl_object v5;
     v5 = ECL_CONS_CDR(v4);
     v2args = v5;
     v4 = ECL_CONS_CAR(v4);
    }
L11:;
    v3arg = v4;
   }
   ecl_bds_bind(cl_env_copy,VV[25],ECL_NIL);      /*  *LOGICAL-BLOCK-POPPER* */
   ecl_bds_bind(cl_env_copy,VV[186],v2args);      /*  *OUTSIDE-ARGS*  */
   value0 = VV[31];
   if (ecl_frs_push(cl_env_copy,value0)==0) {     /*  BEGIN CATCH 18  */
    (aux_closure.env=env0,cl_env_copy->function=(cl_object)&aux_closure,LC109do_guts(2, v3arg, v3arg));
   }
   ecl_frs_pop(cl_env_copy);                      /*  END CATCH 18    */
   value0 = v2args;
   cl_env_copy->nvalues = 1;
   ecl_bds_unwind1(cl_env_copy);
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
L1:;
  value0 = (aux_closure.env=env0,cl_env_copy->function=(cl_object)&aux_closure,LC109do_guts(2, v1orig_args, v2args));
  return value0;
 }
 }
}
/*	closure DO-GUTS                                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC109do_guts(cl_narg narg, cl_object v1orig_args, cl_object v2args, ...)
{
 cl_object T0, T1, T2, T3;
 cl_object CLV0, CLV1, CLV2, CLV3, CLV4, CLV5, CLV6, CLV7
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV7 = env0;                                     /*  INSIDES         */
 CLV6 = _ecl_cdr(CLV7);
 CLV5 = _ecl_cdr(CLV6);
 CLV4 = _ecl_cdr(CLV5);
 CLV3 = _ecl_cdr(CLV4);
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  if (!(ecl_zerop(ECL_CONS_CAR(CLV6)))) { goto L1; }
  {cl_object v3;
   v3 = ECL_NIL;
   v3 = ecl_make_cclosure_va((cl_objectfn)LC108__g1793,env0,Cblock);
   T0 = v3;
  }
  T1 = CONS(ECL_SYM("FORMAT-ERROR",1074),T0);
  T2 = ecl_list1(T1);
  T3 = CONS(T2,ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5)));
  ecl_bds_bind(cl_env_copy,ECL_SYM("*HANDLER-CLUSTERS*",5),T3); /*  *HANDLER-CLUSTERS* */
  value0 = L7formatter_aux(4, ECL_CONS_CAR(CLV0), ECL_CONS_CAR(CLV7), v1orig_args, v2args);
  ecl_bds_unwind1(cl_env_copy);
  return value0;
L1:;
  value0 = L8interpret_directive_list(ECL_CONS_CAR(CLV0), ECL_CONS_CAR(CLV7), v1orig_args, v2args);
  return value0;
 }
 }
}
/*	closure G1793                                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC108__g1793(cl_narg narg, cl_object v1condition, ...)
{
 cl_object T0, T1;
 cl_object CLV0, CLV1, CLV2, CLV3, CLV4, CLV5, CLV6, CLV7
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV7 = env0;
 CLV6 = _ecl_cdr(CLV7);
 CLV5 = _ecl_cdr(CLV6);
 CLV4 = _ecl_cdr(CLV5);
 CLV3 = _ecl_cdr(CLV4);                           /*  END             */
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  T0 = ecl_list1(v1condition);
  T1 = ecl_one_minus(ECL_CONS_CAR(CLV3));
  value0 = cl_error(11, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_47, VV[56], T0, VV[178], ECL_NIL, ECL_SYM("CONTROL-STRING",1211), ECL_CONS_CAR(CLV2), ECL_SYM("OFFSET",1279), T1);
  return value0;
 }
 }
}
/*	local function G1807                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC113__g1807(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_61);
  return value0;
 }
}
/*	local function G1810                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC114__g1810(cl_object v1stream, cl_object v2, cl_object v3, cl_object v4orig_args, cl_object v5args)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_61);
  return value0;
 }
}
/*	function definition for CHECK-OUTPUT-LAYOUT-MODE              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L115check_output_layout_mode(cl_object v1mode)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_symbol_value(VV[13]))) { goto L1; }
  if (ecl_eql(ecl_symbol_value(VV[13]),v1mode)) { goto L1; }
  cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_62);
L1:;
  cl_set(VV[13],v1mode);
  value0 = ecl_symbol_value(VV[13]);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for ILLEGAL-INSIDE-JUSTIFICATION-P        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L116illegal_inside_justification_p(cl_object v1directive)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   v2 = ecl_symbol_value(VV[204]);
   goto L4;
L3:;
   {
    cl_object v3;
    cl_object v4;
    if (ecl_unlikely(ECL_ATOM(v2))) FEtype_error_cons(v2);
    v3 = v2;
    v4 = ECL_CONS_CAR(v3);
    if (Null(ecl_function_dispatch(cl_env_copy,VV[6])(1, v1directive) /*  FORMAT-DIRECTIVE-P */)) { goto L6; }
    if (Null(ecl_function_dispatch(cl_env_copy,VV[6])(1, v4) /*  FORMAT-DIRECTIVE-P */)) { goto L6; }
    T0 = ecl_function_dispatch(cl_env_copy,VV[245])(1, v1directive) /*  FORMAT-DIRECTIVE-CHARACTER */;
    T1 = ecl_function_dispatch(cl_env_copy,VV[245])(1, v4) /*  FORMAT-DIRECTIVE-CHARACTER */;
    if (!(ecl_eql(T0,T1))) { goto L6; }
    T0 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v1directive) /*  FORMAT-DIRECTIVE-COLONP */;
    T1 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v4) /*  FORMAT-DIRECTIVE-COLONP */;
    if (!(ecl_eql(T0,T1))) { goto L6; }
    T0 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v1directive) /*  FORMAT-DIRECTIVE-ATSIGNP */;
    T1 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v4) /*  FORMAT-DIRECTIVE-ATSIGNP */;
    if (!(ecl_eql(T0,T1))) { goto L6; }
    value0 = v3;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L6:;
   v2 = ECL_CONS_CDR(v2);
L4:;
   if (v2==ECL_NIL) { goto L17; }
   goto L3;
L17:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G1827                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC117__g1827(cl_object v1, cl_object v2directives)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6;
   cl_object v7;
   v3 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v1) /*  FORMAT-DIRECTIVE-COLONP */;
   v4 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v1) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v5 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v1) /*  FORMAT-DIRECTIVE-PARAMS */;
   v6 = ecl_function_dispatch(cl_env_copy,VV[269])(1, v1) /*  FORMAT-DIRECTIVE-STRING */;
   v7 = ecl_function_dispatch(cl_env_copy,VV[243])(1, v1) /*  FORMAT-DIRECTIVE-END */;
   {
    cl_object v9;                                 /*  SEGMENTS        */
    cl_object v10;                                /*  FIRST-SEMI      */
    cl_object v11;                                /*  CLOSE           */
    cl_object v12;                                /*  REMAINING       */
    value0 = L119parse_format_justification(v2directives);
    v9 = value0;
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
    if (Null(ecl_function_dispatch(cl_env_copy,VV[251])(1, v11) /*  FORMAT-DIRECTIVE-COLONP */)) { goto L8; }
    {
     cl_object v14;                               /*  PREFIX          */
     cl_object v15;                               /*  PER-LINE-P      */
     cl_object v16;                               /*  INSIDES         */
     cl_object v17;                               /*  SUFFIX          */
     value0 = L124parse_format_logical_block(v9, v3, v10, v11, v5, v6, v7);
     v14 = value0;
     {
      const int v18 = cl_env_copy->nvalues;
      cl_object v19;
      v19 = (v18<=1)? ECL_NIL : cl_env_copy->values[1];
      v15 = v19;
      v19 = (v18<=2)? ECL_NIL : cl_env_copy->values[2];
      v16 = v19;
      v19 = (v18<=3)? ECL_NIL : cl_env_copy->values[3];
      v17 = v19;
     }
     T0 = L127expand_format_logical_block(v14, v15, v16, v17, v4);
     goto L7;
    }
L8:;
    {
     cl_object v13count;
     T1 = (ECL_SYM("+",14)->symbol.gfdef);
     {
      cl_object v14;
      cl_object v15;
      v14 = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
      v15 = v9;
      {
       cl_object v16;
       cl_object v17;
       v16 = ecl_list1(ECL_NIL);
       v17 = v16;
L19:;
       if (!(ecl_endp(v15))) { goto L21; }
       goto L20;
L21:;
       v14 = _ecl_car(v15);
       {
        cl_object v18;
        v18 = _ecl_cdr(v15);
        if (ecl_unlikely(!ECL_LISTP(v18))) FEtype_error_list(v18);
        v15 = v18;
       }
       if (ecl_unlikely(ECL_ATOM(v17))) FEtype_error_cons(v17);
       T3 = v17;
       {
        cl_fixnum v18;
        T4 = (VV[205]->symbol.gfdef);
        v18 = ecl_fixnum(cl_count_if(2, T4, v14));
        v17 = ecl_list1(ecl_make_fixnum(v18));
       }
       (ECL_CONS_CDR(T3)=v17,T3);
       goto L19;
L20:;
       T2 = ecl_cdr(v16);
       goto L13;
      }
     }
L13:;
     v13count = cl_reduce(2, T1, T2);
     if (!(ecl_number_compare(v13count,ecl_make_fixnum(0))>0)) { goto L37; }
     T1 = ecl_list1(v13count);
     cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_63, VV[56], T1);
L37:;
     T0 = L120expand_format_justification(v9, v3, v4, v10, v5);
    }
L7:;
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = v12;
    cl_env_copy->values[0] = T0;
    return cl_env_copy->values[0];
   }
  }
 }
}
/*	local function G1841                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC118__g1841(cl_object v1stream, cl_object v2, cl_object v3directives, cl_object v4orig_args, cl_object v5args)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6;
   cl_object v7;
   cl_object v8;
   cl_object v9;
   cl_object v10;
   v6 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v2) /*  FORMAT-DIRECTIVE-COLONP */;
   v7 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v2) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v8 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v2) /*  FORMAT-DIRECTIVE-PARAMS */;
   v9 = ecl_function_dispatch(cl_env_copy,VV[269])(1, v2) /*  FORMAT-DIRECTIVE-STRING */;
   v10 = ecl_function_dispatch(cl_env_copy,VV[243])(1, v2) /*  FORMAT-DIRECTIVE-END */;
   {
    cl_object v12;                                /*  SEGMENTS        */
    cl_object v13;                                /*  FIRST-SEMI      */
    cl_object v14;                                /*  CLOSE           */
    cl_object v15;                                /*  REMAINING       */
    value0 = L119parse_format_justification(v3directives);
    v12 = value0;
    {
     const int v16 = cl_env_copy->nvalues;
     cl_object v17;
     v17 = (v16<=1)? ECL_NIL : cl_env_copy->values[1];
     v13 = v17;
     v17 = (v16<=2)? ECL_NIL : cl_env_copy->values[2];
     v14 = v17;
     v17 = (v16<=3)? ECL_NIL : cl_env_copy->values[3];
     v15 = v17;
    }
    if (Null(ecl_function_dispatch(cl_env_copy,VV[251])(1, v14) /*  FORMAT-DIRECTIVE-COLONP */)) { goto L10; }
    {
     cl_object v17;                               /*  PREFIX          */
     cl_object v18;                               /*  PER-LINE-P      */
     cl_object v19;                               /*  INSIDES         */
     cl_object v20;                               /*  SUFFIX          */
     value0 = L124parse_format_logical_block(v12, v6, v13, v14, v8, v9, v10);
     v17 = value0;
     {
      const int v21 = cl_env_copy->nvalues;
      cl_object v22;
      v22 = (v21<=1)? ECL_NIL : cl_env_copy->values[1];
      v18 = v22;
      v22 = (v21<=2)? ECL_NIL : cl_env_copy->values[2];
      v19 = v22;
      v22 = (v21<=3)? ECL_NIL : cl_env_copy->values[3];
      v20 = v22;
     }
     v5args = L132interpret_format_logical_block(v1stream, v4orig_args, v5args, v17, v18, v19, v20, v7);
     goto L9;
    }
L10:;
    {
     cl_object v16count;
     T1 = (ECL_SYM("+",14)->symbol.gfdef);
     {
      cl_object v17;
      cl_object v18;
      v17 = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v12))) FEtype_error_list(v12);
      v18 = v12;
      {
       cl_object v19;
       cl_object v20;
       v19 = ecl_list1(ECL_NIL);
       v20 = v19;
L21:;
       if (!(ecl_endp(v18))) { goto L23; }
       goto L22;
L23:;
       v17 = _ecl_car(v18);
       {
        cl_object v21;
        v21 = _ecl_cdr(v18);
        if (ecl_unlikely(!ECL_LISTP(v21))) FEtype_error_list(v21);
        v18 = v21;
       }
       if (ecl_unlikely(ECL_ATOM(v20))) FEtype_error_cons(v20);
       T3 = v20;
       {
        cl_fixnum v21;
        T4 = (VV[205]->symbol.gfdef);
        v21 = ecl_fixnum(cl_count_if(2, T4, v17));
        v20 = ecl_list1(ecl_make_fixnum(v21));
       }
       (ECL_CONS_CDR(T3)=v20,T3);
       goto L21;
L22:;
       T2 = ecl_cdr(v19);
       goto L15;
      }
     }
L15:;
     v16count = cl_reduce(2, T1, T2);
     if (!(ecl_number_compare(v16count,ecl_make_fixnum(0))>0)) { goto L39; }
     T1 = ecl_list1(v16count);
     cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_63, VV[56], T1);
L39:;
     v5args = L121interpret_format_justification(v1stream, v4orig_args, v5args, v12, v6, v7, v13, v8);
    }
L9:;
    T0 = v15;
   }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5args;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for PARSE-FORMAT-JUSTIFICATION            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L119parse_format_justification(cl_object v1directives)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2first_semi;
   cl_object v3close;
   cl_object v4remaining;
   v2first_semi = ECL_NIL;
   v3close = ECL_NIL;
   v4remaining = v1directives;
   {
    cl_object v5;
    cl_object v6;
    v5 = ECL_NIL;
    v6 = ECL_NIL;
L7:;
    {
     cl_object v7close_or_semi;
     v7close_or_semi = L21find_directive(v4remaining, CODE_CHAR(62), ECL_T);
     if ((v7close_or_semi)!=ECL_NIL) { goto L10; }
     cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_50);
L10:;
     {
      cl_object v8posn;
      v8posn = cl_position(2, v7close_or_semi, v4remaining);
      {
       cl_object v9;
       T0 = cl_subseq(3, v4remaining, ecl_make_fixnum(0), v8posn);
       v9 = CONS(T0,ECL_NIL);
       if (Null(v6)) { goto L17; }
       if (ecl_unlikely(ECL_ATOM(v6))) FEtype_error_cons(v6);
       T0 = v6;
       (ECL_CONS_CDR(T0)=v9,T0);
       v6 = v9;
       goto L15;
L17:;
       v6 = v9;
       v5 = v9;
      }
L15:;
      T0 = ecl_one_plus(v8posn);
      v4remaining = ecl_nthcdr(ecl_to_size(T0),v4remaining);
     }
     T0 = ecl_function_dispatch(cl_env_copy,VV[245])(1, v7close_or_semi) /*  FORMAT-DIRECTIVE-CHARACTER */;
     if (!(ecl_char_code(T0)==ecl_char_code(CODE_CHAR(62)))) { goto L28; }
     v3close = v7close_or_semi;
     goto L6;
L28:;
     if ((v2first_semi)!=ECL_NIL) { goto L8; }
     v2first_semi = v7close_or_semi;
    }
L8:;
    goto L7;
L6:;
    cl_env_copy->nvalues = 4;
    cl_env_copy->values[3] = v4remaining;
    cl_env_copy->values[2] = v3close;
    cl_env_copy->values[1] = v2first_semi;
    cl_env_copy->values[0] = v5;
    return cl_env_copy->values[0];
   }
  }
 }
}
/*	function definition for EXPAND-FORMAT-JUSTIFICATION           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L120expand_format_justification(cl_object v1segments, cl_object v2colonp, cl_object v3atsignp, cl_object v4first_semi, cl_object v5params)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24, T25, T26;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6newline_segment_p;
   if (Null(v4first_semi)) { goto L3; }
   v6newline_segment_p = ecl_function_dispatch(cl_env_copy,VV[251])(1, v4first_semi) /*  FORMAT-DIRECTIVE-COLONP */;
   goto L1;
L3:;
   v6newline_segment_p = ECL_NIL;
   goto L1;
L1:;
   if (Null(v6newline_segment_p)) { goto L5; }
   L115check_output_layout_mode(ecl_make_fixnum(2));
L5:;
   {
    cl_object v7;
    v7 = v5params;
    {
     cl_object v8param_and_offset;
     cl_object v9offset;
     cl_object v10param;
     {
      cl_object v11;
      v11 = v7;
      if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
      if (Null(v11)) { goto L13; }
      {
       cl_object v12;
       v12 = ECL_CONS_CDR(v11);
       v7 = v12;
       v11 = ECL_CONS_CAR(v11);
      }
L13:;
      v8param_and_offset = v11;
     }
     v9offset = ecl_car(v8param_and_offset);
     v10param = ecl_cdr(v8param_and_offset);
     if (!(ecl_eql(v10param,VV[17]))) { goto L21; }
     T1 = L14expand_next_arg(1, v9offset);
     T0 = cl_list(3, ECL_SYM("OR",614), T1, ecl_make_fixnum(0));
     goto L8;
L21:;
     if (!(ecl_eql(v10param,VV[18]))) { goto L23; }
     cl_set(VV[28],ECL_NIL);
     T0 = VV[54];
     goto L8;
L23:;
     if (!((v10param)==(ECL_NIL))) { goto L27; }
     T0 = ecl_make_fixnum(0);
     goto L8;
L27:;
     T0 = v10param;
    }
L8:;
    T1 = cl_list(2, VV[206], T0);
    {
     cl_object v8param_and_offset;
     cl_object v9offset;
     cl_object v10param;
     {
      cl_object v11;
      v11 = v7;
      if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
      if (Null(v11)) { goto L35; }
      {
       cl_object v12;
       v12 = ECL_CONS_CDR(v11);
       v7 = v12;
       v11 = ECL_CONS_CAR(v11);
      }
L35:;
      v8param_and_offset = v11;
     }
     v9offset = ecl_car(v8param_and_offset);
     v10param = ecl_cdr(v8param_and_offset);
     if (!(ecl_eql(v10param,VV[17]))) { goto L43; }
     T3 = L14expand_next_arg(1, v9offset);
     T2 = cl_list(3, ECL_SYM("OR",614), T3, ecl_make_fixnum(1));
     goto L30;
L43:;
     if (!(ecl_eql(v10param,VV[18]))) { goto L45; }
     cl_set(VV[28],ECL_NIL);
     T2 = VV[54];
     goto L30;
L45:;
     if (!((v10param)==(ECL_NIL))) { goto L49; }
     T2 = ecl_make_fixnum(1);
     goto L30;
L49:;
     T2 = v10param;
    }
L30:;
    T3 = cl_list(2, VV[207], T2);
    {
     cl_object v8param_and_offset;
     cl_object v9offset;
     cl_object v10param;
     {
      cl_object v11;
      v11 = v7;
      if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
      if (Null(v11)) { goto L57; }
      {
       cl_object v12;
       v12 = ECL_CONS_CDR(v11);
       v7 = v12;
       v11 = ECL_CONS_CAR(v11);
      }
L57:;
      v8param_and_offset = v11;
     }
     v9offset = ecl_car(v8param_and_offset);
     v10param = ecl_cdr(v8param_and_offset);
     if (!(ecl_eql(v10param,VV[17]))) { goto L65; }
     T5 = L14expand_next_arg(1, v9offset);
     T4 = cl_list(3, ECL_SYM("OR",614), T5, ecl_make_fixnum(0));
     goto L52;
L65:;
     if (!(ecl_eql(v10param,VV[18]))) { goto L67; }
     cl_set(VV[28],ECL_NIL);
     T4 = VV[54];
     goto L52;
L67:;
     if (!((v10param)==(ECL_NIL))) { goto L71; }
     T4 = ecl_make_fixnum(0);
     goto L52;
L71:;
     T4 = v10param;
    }
L52:;
    T5 = cl_list(2, VV[208], T4);
    {
     cl_object v8param_and_offset;
     cl_object v9offset;
     cl_object v10param;
     {
      cl_object v11;
      v11 = v7;
      if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
      if (Null(v11)) { goto L79; }
      {
       cl_object v12;
       v12 = ECL_CONS_CDR(v11);
       v7 = v12;
       v11 = ECL_CONS_CAR(v11);
      }
L79:;
      v8param_and_offset = v11;
     }
     v9offset = ecl_car(v8param_and_offset);
     v10param = ecl_cdr(v8param_and_offset);
     if (!(ecl_eql(v10param,VV[17]))) { goto L87; }
     T7 = L14expand_next_arg(1, v9offset);
     T6 = cl_list(3, ECL_SYM("OR",614), T7, CODE_CHAR(32));
     goto L74;
L87:;
     if (!(ecl_eql(v10param,VV[18]))) { goto L89; }
     cl_set(VV[28],ECL_NIL);
     T6 = VV[54];
     goto L74;
L89:;
     if (!((v10param)==(ECL_NIL))) { goto L93; }
     T6 = CODE_CHAR(32);
     goto L74;
L93:;
     T6 = v10param;
    }
L74:;
    T7 = cl_list(2, VV[209], T6);
    T8 = cl_list(4, T1, T3, T5, T7);
    if (Null(v7)) { goto L97; }
    T10 = ecl_list1(ecl_make_fixnum(4));
    T11 = ecl_caar(v7);
    T9 = cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T10, ECL_SYM("OFFSET",1279), T11);
    goto L96;
L97:;
    T9 = ECL_NIL;
L96:;
    if (Null(v6newline_segment_p)) { goto L100; }
    T10 = VV[211];
    goto L99;
L100:;
    T10 = ECL_NIL;
L99:;
    T11 = CONS(VV[210],T10);
    if (Null(v6newline_segment_p)) { goto L103; }
    {
     cl_object v8;
     v8 = v1segments;
     if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
     if (Null(v8)) { goto L109; }
     {
      cl_object v9;
      v9 = ECL_CONS_CDR(v8);
      v1segments = v9;
      v8 = ECL_CONS_CAR(v8);
     }
L109:;
     T13 = v8;
    }
    T14 = L12expand_directive_list(T13);
    T15 = cl_listX(3, ECL_SYM("WITH-OUTPUT-TO-STRING",913), VV[213], T14);
    T16 = cl_list(3, ECL_SYM("SETF",750), VV[212], T15);
    {
     cl_object v8;
     v8 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v4first_semi) /*  FORMAT-DIRECTIVE-PARAMS */;
     {
      cl_object v9param_and_offset;
      cl_object v10offset;
      cl_object v11param;
      {
       cl_object v12;
       v12 = v8;
       if (ecl_unlikely(!ECL_LISTP(v12))) FEtype_error_list(v12);
       if (Null(v12)) { goto L122; }
       {
        cl_object v13;
        v13 = ECL_CONS_CDR(v12);
        v8 = v13;
        v12 = ECL_CONS_CAR(v12);
       }
L122:;
       v9param_and_offset = v12;
      }
      v10offset = ecl_car(v9param_and_offset);
      v11param = ecl_cdr(v9param_and_offset);
      if (!(ecl_eql(v11param,VV[17]))) { goto L130; }
      T19 = L14expand_next_arg(1, v10offset);
      T18 = cl_list(3, ECL_SYM("OR",614), T19, ecl_make_fixnum(0));
      goto L117;
L130:;
      if (!(ecl_eql(v11param,VV[18]))) { goto L132; }
      cl_set(VV[28],ECL_NIL);
      T18 = VV[54];
      goto L117;
L132:;
      if (!((v11param)==(ECL_NIL))) { goto L136; }
      T18 = ecl_make_fixnum(0);
      goto L117;
L136:;
      T18 = v11param;
     }
L117:;
     T19 = cl_list(2, VV[214], T18);
     {
      cl_object v9param_and_offset;
      cl_object v10offset;
      cl_object v11param;
      {
       cl_object v12;
       v12 = v8;
       if (ecl_unlikely(!ECL_LISTP(v12))) FEtype_error_list(v12);
       if (Null(v12)) { goto L144; }
       {
        cl_object v13;
        v13 = ECL_CONS_CDR(v12);
        v8 = v13;
        v12 = ECL_CONS_CAR(v12);
       }
L144:;
       v9param_and_offset = v12;
      }
      v10offset = ecl_car(v9param_and_offset);
      v11param = ecl_cdr(v9param_and_offset);
      if (!(ecl_eql(v11param,VV[17]))) { goto L152; }
      T21 = L14expand_next_arg(1, v10offset);
      T20 = cl_list(3, ECL_SYM("OR",614), T21, VV[216]);
      goto L139;
L152:;
      if (!(ecl_eql(v11param,VV[18]))) { goto L154; }
      cl_set(VV[28],ECL_NIL);
      T20 = VV[54];
      goto L139;
L154:;
      if (!((v11param)==(ECL_NIL))) { goto L158; }
      T20 = VV[216];
      goto L139;
L158:;
      T20 = v11param;
     }
L139:;
     T21 = cl_list(2, VV[215], T20);
     T22 = cl_list(2, T19, T21);
     if (Null(v8)) { goto L162; }
     T24 = ecl_list1(ecl_make_fixnum(2));
     T25 = ecl_caar(v8);
     T23 = cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T24, ECL_SYM("OFFSET",1279), T25);
     goto L161;
L162:;
     T23 = ECL_NIL;
L161:;
     T24 = cl_list(5, ECL_SYM("SETF",750), VV[217], VV[214], VV[218], VV[215]);
     T25 = ecl_list1(T24);
     T26 = ecl_append(T23,T25);
     T17 = cl_listX(3, ECL_SYM("LET",477), T22, T26);
    }
    T12 = cl_list(2, T16, T17);
    goto L102;
L103:;
    T12 = ECL_NIL;
L102:;
    {
     cl_object v8;
     cl_object v9;
     v8 = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v1segments))) FEtype_error_list(v1segments);
     v9 = v1segments;
     {
      cl_object v10;
      cl_object v11;
      v10 = ecl_list1(ECL_NIL);
      v11 = v10;
L170:;
      if (!(ecl_endp(v9))) { goto L172; }
      goto L171;
L172:;
      v8 = _ecl_car(v9);
      {
       cl_object v12;
       v12 = _ecl_cdr(v9);
       if (ecl_unlikely(!ECL_LISTP(v12))) FEtype_error_list(v12);
       v9 = v12;
      }
      if (ecl_unlikely(ECL_ATOM(v11))) FEtype_error_cons(v11);
      T14 = v11;
      T16 = L12expand_directive_list(v8);
      T17 = cl_listX(3, ECL_SYM("WITH-OUTPUT-TO-STRING",913), VV[213], T16);
      T15 = cl_list(3, ECL_SYM("PUSH",677), T17, VV[219]);
      v11 = ecl_list1(T15);
      (ECL_CONS_CDR(T14)=v11,T14);
      goto L170;
L171:;
      T13 = ecl_cdr(v10);
      goto L164;
     }
    }
L164:;
    T14 = ecl_append(T12,T13);
    T15 = cl_listX(3, ECL_SYM("BLOCK",137), ECL_NIL, T14);
    if (Null(v6newline_segment_p)) { goto L188; }
    T16 = VV[221];
    goto L187;
L188:;
    T16 = VV[222];
L187:;
    T17 = cl_list(7, VV[219], v2colonp, v3atsignp, VV[206], VV[207], VV[208], VV[209]);
    T18 = ecl_append(T16,T17);
    T19 = cl_listX(3, VV[220], ECL_SYM("STREAM",799), T18);
    T20 = cl_list(4, ECL_SYM("LET",477), T11, T15, T19);
    T21 = ecl_list1(T20);
    T22 = ecl_append(T9,T21);
    value0 = cl_listX(3, ECL_SYM("LET",477), T8, T22);
    return value0;
   }
  }
 }
}
/*	function definition for INTERPRET-FORMAT-JUSTIFICATION        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L121interpret_format_justification(cl_object volatile v1stream, cl_object volatile v2orig_args, cl_object volatile v3args, cl_object volatile v4segments, cl_object volatile v5colonp, cl_object volatile v6atsignp, cl_object volatile v7first_semi, cl_object volatile v8params)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   volatile cl_object v9;
   v9 = v8params;
   {
    volatile cl_object v10mincol;
    volatile cl_object v11colinc;
    volatile cl_object v12minpad;
    volatile cl_object v13padchar;
    {
     cl_object v14param_and_offset;
     cl_object v15offset;
     cl_object v16param;
     {
      cl_object v17;
      v17 = v9;
      if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
      if (Null(v17)) { goto L8; }
      {
       cl_object v18;
       v18 = ECL_CONS_CDR(v17);
       v9 = v18;
       v17 = ECL_CONS_CAR(v17);
      }
L8:;
      v14param_and_offset = v17;
     }
     v15offset = ecl_car(v14param_and_offset);
     v16param = ecl_cdr(v14param_and_offset);
     if (!(ecl_eql(v16param,VV[17]))) { goto L16; }
     if (!(v3args==ECL_NIL)) { goto L21; }
     cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v15offset);
L21:;
     if (Null(ecl_symbol_value(VV[25]))) { goto L23; }
     ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L23:;
     {
      cl_object v17;
      v17 = v3args;
      if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
      if (Null(v17)) { goto L28; }
      {
       cl_object v18;
       v18 = ECL_CONS_CDR(v17);
       v3args = v18;
       v17 = ECL_CONS_CAR(v17);
      }
L28:;
      value0 = v17;
     }
     if ((value0)!=ECL_NIL) { goto L19; }
     v10mincol = ecl_make_fixnum(0);
     goto L3;
L19:;
     v10mincol = value0;
     goto L3;
L16:;
     if (!(ecl_eql(v16param,VV[18]))) { goto L34; }
     v10mincol = ecl_make_fixnum(ecl_length(v3args));
     goto L3;
L34:;
     if (!((v16param)==(ECL_NIL))) { goto L36; }
     v10mincol = ecl_make_fixnum(0);
     goto L3;
L36:;
     v10mincol = v16param;
    }
L3:;
    {
     cl_object v14param_and_offset;
     cl_object v15offset;
     cl_object v16param;
     {
      cl_object v17;
      v17 = v9;
      if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
      if (Null(v17)) { goto L44; }
      {
       cl_object v18;
       v18 = ECL_CONS_CDR(v17);
       v9 = v18;
       v17 = ECL_CONS_CAR(v17);
      }
L44:;
      v14param_and_offset = v17;
     }
     v15offset = ecl_car(v14param_and_offset);
     v16param = ecl_cdr(v14param_and_offset);
     if (!(ecl_eql(v16param,VV[17]))) { goto L52; }
     if (!(v3args==ECL_NIL)) { goto L57; }
     cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v15offset);
L57:;
     if (Null(ecl_symbol_value(VV[25]))) { goto L59; }
     ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L59:;
     {
      cl_object v17;
      v17 = v3args;
      if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
      if (Null(v17)) { goto L64; }
      {
       cl_object v18;
       v18 = ECL_CONS_CDR(v17);
       v3args = v18;
       v17 = ECL_CONS_CAR(v17);
      }
L64:;
      value0 = v17;
     }
     if ((value0)!=ECL_NIL) { goto L55; }
     v11colinc = ecl_make_fixnum(1);
     goto L39;
L55:;
     v11colinc = value0;
     goto L39;
L52:;
     if (!(ecl_eql(v16param,VV[18]))) { goto L70; }
     v11colinc = ecl_make_fixnum(ecl_length(v3args));
     goto L39;
L70:;
     if (!((v16param)==(ECL_NIL))) { goto L72; }
     v11colinc = ecl_make_fixnum(1);
     goto L39;
L72:;
     v11colinc = v16param;
    }
L39:;
    {
     cl_object v14param_and_offset;
     cl_object v15offset;
     cl_object v16param;
     {
      cl_object v17;
      v17 = v9;
      if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
      if (Null(v17)) { goto L80; }
      {
       cl_object v18;
       v18 = ECL_CONS_CDR(v17);
       v9 = v18;
       v17 = ECL_CONS_CAR(v17);
      }
L80:;
      v14param_and_offset = v17;
     }
     v15offset = ecl_car(v14param_and_offset);
     v16param = ecl_cdr(v14param_and_offset);
     if (!(ecl_eql(v16param,VV[17]))) { goto L88; }
     if (!(v3args==ECL_NIL)) { goto L93; }
     cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v15offset);
L93:;
     if (Null(ecl_symbol_value(VV[25]))) { goto L95; }
     ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L95:;
     {
      cl_object v17;
      v17 = v3args;
      if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
      if (Null(v17)) { goto L100; }
      {
       cl_object v18;
       v18 = ECL_CONS_CDR(v17);
       v3args = v18;
       v17 = ECL_CONS_CAR(v17);
      }
L100:;
      value0 = v17;
     }
     if ((value0)!=ECL_NIL) { goto L91; }
     v12minpad = ecl_make_fixnum(0);
     goto L75;
L91:;
     v12minpad = value0;
     goto L75;
L88:;
     if (!(ecl_eql(v16param,VV[18]))) { goto L106; }
     v12minpad = ecl_make_fixnum(ecl_length(v3args));
     goto L75;
L106:;
     if (!((v16param)==(ECL_NIL))) { goto L108; }
     v12minpad = ecl_make_fixnum(0);
     goto L75;
L108:;
     v12minpad = v16param;
    }
L75:;
    {
     cl_object v14param_and_offset;
     cl_object v15offset;
     cl_object v16param;
     {
      cl_object v17;
      v17 = v9;
      if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
      if (Null(v17)) { goto L116; }
      {
       cl_object v18;
       v18 = ECL_CONS_CDR(v17);
       v9 = v18;
       v17 = ECL_CONS_CAR(v17);
      }
L116:;
      v14param_and_offset = v17;
     }
     v15offset = ecl_car(v14param_and_offset);
     v16param = ecl_cdr(v14param_and_offset);
     if (!(ecl_eql(v16param,VV[17]))) { goto L124; }
     if (!(v3args==ECL_NIL)) { goto L129; }
     cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v15offset);
L129:;
     if (Null(ecl_symbol_value(VV[25]))) { goto L131; }
     ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L131:;
     {
      cl_object v17;
      v17 = v3args;
      if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
      if (Null(v17)) { goto L136; }
      {
       cl_object v18;
       v18 = ECL_CONS_CDR(v17);
       v3args = v18;
       v17 = ECL_CONS_CAR(v17);
      }
L136:;
      value0 = v17;
     }
     if ((value0)!=ECL_NIL) { goto L127; }
     v13padchar = CODE_CHAR(32);
     goto L111;
L127:;
     v13padchar = value0;
     goto L111;
L124:;
     if (!(ecl_eql(v16param,VV[18]))) { goto L142; }
     v13padchar = ecl_make_fixnum(ecl_length(v3args));
     goto L111;
L142:;
     if (!((v16param)==(ECL_NIL))) { goto L144; }
     v13padchar = CODE_CHAR(32);
     goto L111;
L144:;
     v13padchar = v16param;
    }
L111:;
    if (Null(v9)) { goto L147; }
    T0 = ecl_list1(ecl_make_fixnum(4));
    T1 = ecl_caar(v9);
    cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T0, ECL_SYM("OFFSET",1279), T1);
L147:;
    {
     volatile cl_object v14newline_string;
     volatile cl_object v15strings;
     volatile cl_object v16extra_space;
     volatile cl_object v17line_len;
     v14newline_string = ECL_NIL;
     v15strings = ECL_NIL;
     v16extra_space = ecl_make_fixnum(0);
     v17line_len = ecl_make_fixnum(0);
     value0 = VV[31];
     if (ecl_frs_push(cl_env_copy,value0)) {      /*  BEGIN CATCH 155 */
      value0 = cl_env_copy->values[0];
     } else {
      if (Null(v7first_semi)) { goto L159; }
      if (Null(ecl_function_dispatch(cl_env_copy,VV[251])(1, v7first_semi) /*  FORMAT-DIRECTIVE-COLONP */)) { goto L159; }
      L115check_output_layout_mode(ecl_make_fixnum(2));
      {
       cl_object v18;
       v18 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v7first_semi) /*  FORMAT-DIRECTIVE-PARAMS */;
       {
        cl_object v19extra;
        cl_object v20len;
        {
         cl_object v21param_and_offset;
         cl_object v22offset;
         cl_object v23param;
         {
          cl_object v24;
          v24 = v18;
          if (ecl_unlikely(!ECL_LISTP(v24))) FEtype_error_list(v24);
          if (Null(v24)) { goto L169; }
          {
          cl_object v25;
          v25 = ECL_CONS_CDR(v24);
          v18 = v25;
          v24 = ECL_CONS_CAR(v24);
          }
L169:;
          v21param_and_offset = v24;
         }
         v22offset = ecl_car(v21param_and_offset);
         v23param = ecl_cdr(v21param_and_offset);
         if (!(ecl_eql(v23param,VV[17]))) { goto L177; }
         if (!(v3args==ECL_NIL)) { goto L182; }
         cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v22offset);
L182:;
         if (Null(ecl_symbol_value(VV[25]))) { goto L184; }
         ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L184:;
         {
          cl_object v24;
          v24 = v3args;
          if (ecl_unlikely(!ECL_LISTP(v24))) FEtype_error_list(v24);
          if (Null(v24)) { goto L189; }
          {
          cl_object v25;
          v25 = ECL_CONS_CDR(v24);
          v3args = v25;
          v24 = ECL_CONS_CAR(v24);
          }
L189:;
          value0 = v24;
         }
         if ((value0)!=ECL_NIL) { goto L180; }
         v19extra = ecl_make_fixnum(0);
         goto L164;
L180:;
         v19extra = value0;
         goto L164;
L177:;
         if (!(ecl_eql(v23param,VV[18]))) { goto L195; }
         v19extra = ecl_make_fixnum(ecl_length(v3args));
         goto L164;
L195:;
         if (!((v23param)==(ECL_NIL))) { goto L197; }
         v19extra = ecl_make_fixnum(0);
         goto L164;
L197:;
         v19extra = v23param;
        }
L164:;
        {
         cl_object v21param_and_offset;
         cl_object v22offset;
         cl_object v23param;
         {
          cl_object v24;
          v24 = v18;
          if (ecl_unlikely(!ECL_LISTP(v24))) FEtype_error_list(v24);
          if (Null(v24)) { goto L205; }
          {
          cl_object v25;
          v25 = ECL_CONS_CDR(v24);
          v18 = v25;
          v24 = ECL_CONS_CAR(v24);
          }
L205:;
          v21param_and_offset = v24;
         }
         v22offset = ecl_car(v21param_and_offset);
         v23param = ecl_cdr(v21param_and_offset);
         if (!(ecl_eql(v23param,VV[17]))) { goto L213; }
         if (!(v3args==ECL_NIL)) { goto L218; }
         cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17, ECL_SYM("OFFSET",1279), v22offset);
L218:;
         if (Null(ecl_symbol_value(VV[25]))) { goto L220; }
         ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L220:;
         {
          cl_object v24;
          v24 = v3args;
          if (ecl_unlikely(!ECL_LISTP(v24))) FEtype_error_list(v24);
          if (Null(v24)) { goto L225; }
          {
          cl_object v25;
          v25 = ECL_CONS_CDR(v24);
          v3args = v25;
          v24 = ECL_CONS_CAR(v24);
          }
L225:;
          value0 = v24;
         }
         if ((value0)!=ECL_NIL) { goto L216; }
         v20len = ecl_make_fixnum(72);
         goto L200;
L216:;
         v20len = value0;
         goto L200;
L213:;
         if (!(ecl_eql(v23param,VV[18]))) { goto L231; }
         v20len = ecl_make_fixnum(ecl_length(v3args));
         goto L200;
L231:;
         if (!((v23param)==(ECL_NIL))) { goto L233; }
         v20len = ecl_make_fixnum(72);
         goto L200;
L233:;
         v20len = v23param;
        }
L200:;
        if (Null(v18)) { goto L236; }
        T0 = ecl_list1(ecl_make_fixnum(2));
        T1 = ecl_caar(v18);
        cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_19, VV[56], T0, ECL_SYM("OFFSET",1279), T1);
L236:;
        {
         cl_object v21stream;
         v21stream = cl_make_string_output_stream(0);
         {
          cl_object v22;
          v22 = v4segments;
          if (ecl_unlikely(!ECL_LISTP(v22))) FEtype_error_list(v22);
          if (Null(v22)) { goto L247; }
          {
          cl_object v23;
          v23 = ECL_CONS_CDR(v22);
          v4segments = v23;
          v22 = ECL_CONS_CAR(v22);
          }
L247:;
          T0 = v22;
         }
         v3args = L8interpret_directive_list(v21stream, T0, v2orig_args, v3args);
         v14newline_string = cl_get_output_stream_string(v21stream);
        }
        v16extra_space = v19extra;
        v17line_len = v20len;
       }
      }
L159:;
      {
       cl_object v18;
       v18 = v4segments;
       goto L260;
L259:;
       {
        cl_object v19segment;
        v19segment = ecl_car(v18);
        {
         cl_object v20stream;
         v20stream = cl_make_string_output_stream(0);
         v3args = L8interpret_directive_list(v20stream, v19segment, v2orig_args, v3args);
         T0 = cl_get_output_stream_string(v20stream);
        }
        v15strings = CONS(T0,v15strings);
       }
       v18 = ecl_cdr(v18);
L260:;
       if (Null(v18)) { goto L272; }
       goto L259;
L272:;
      }
      value0 = v3args;
      cl_env_copy->nvalues = 1;
     }
     ecl_frs_pop(cl_env_copy);                    /*  END CATCH 155   */
     v3args = value0;
     si_format_justification(11, v1stream, v14newline_string, v16extra_space, v17line_len, v15strings, v5colonp, v6atsignp, v10mincol, v11colinc, v12minpad, v13padchar);
    }
   }
  }
  value0 = v3args;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for FORMAT-JUSTIFICATION                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_format_justification(cl_narg narg, cl_object v1stream, cl_object v2newline_prefix, cl_object v3extra_space, cl_object v4line_len, cl_object v5strings, cl_object v6pad_left, cl_object v7pad_right, cl_object v8mincol, cl_object v9colinc, cl_object v10minpad, cl_object v11padchar, ...)
{
 cl_object T0, T1, T2;
 volatile cl_object lex0[5];
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg!=11)) FEwrong_num_arguments_anonym();
 {
  lex0[0] = v1stream;                             /*  STREAM          */
  lex0[1] = v10minpad;                            /*  MINPAD          */
  lex0[2] = v11padchar;                           /*  PADCHAR         */
TTL:
  v5strings = cl_reverse(v5strings);
  if ((v6pad_left)!=ECL_NIL) { goto L3; }
  if ((v7pad_right)!=ECL_NIL) { goto L3; }
  T0 = ecl_cdr(v5strings);
  if (!(T0==ECL_NIL)) { goto L3; }
  v6pad_left = ECL_T;
L3:;
  {
   cl_object v12chars;
   cl_object v13length;
   {
    cl_fixnum v14;
    v14 = ecl_length(v5strings);
    T0 = ecl_make_integer((v14)-1);
    lex0[3] = T0;                                 /*  NUM-GAPS        */
   }
   T0 = lex0[3];
   T1 = ecl_times(T0,lex0[1]);
   {
    cl_object v15string;
    cl_object v16;
    v15string = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v5strings))) FEtype_error_list(v5strings);
    v16 = v5strings;
    {
     cl_object v17;
     v17 = ecl_make_fixnum(0);
L14:;
     if (!(ecl_endp(v16))) { goto L16; }
     goto L15;
L16:;
     v15string = _ecl_car(v16);
     {
      cl_object v18;
      v18 = _ecl_cdr(v16);
      if (ecl_unlikely(!ECL_LISTP(v18))) FEtype_error_list(v18);
      v16 = v18;
     }
     {
      cl_fixnum v18;
      v18 = ecl_length(v15string);
      v17 = ecl_plus(v17,ecl_make_fixnum(v18));
     }
     goto L14;
L15:;
     T2 = v17;
     goto L9;
    }
   }
L9:;
   v12chars = ecl_plus(T1,T2);
   if (!(ecl_number_compare(v12chars,v8mincol)>0)) { goto L29; }
   T0 = ecl_minus(v12chars,v8mincol);
   T1 = ecl_ceiling2(T0,v9colinc);
   T2 = ecl_times(T1,v9colinc);
   v13length = ecl_plus(v8mincol,T2);
   goto L28;
L29:;
   v13length = v8mincol;
L28:;
   T0 = ecl_minus(v13length,v12chars);
   lex0[4] = T0;                                  /*  PADDING         */
   if (Null(v2newline_prefix)) { goto L31; }
   value0 = si_file_column(lex0[0]);
   if ((value0)!=ECL_NIL) { goto L36; }
   T0 = ecl_make_fixnum(0);
   goto L34;
L36:;
   T0 = value0;
   goto L34;
L34:;
   T1 = ecl_plus(T0,v13length);
   T2 = ecl_plus(T1,v3extra_space);
   if (!(ecl_number_compare(T2,v4line_len)>0)) { goto L31; }
   cl_write_string(2, v2newline_prefix, lex0[0]);
L31:;
   if (Null(v6pad_left)) { goto L38; }
   T0 = lex0[3];
   lex0[3] = ecl_plus(T0,ecl_make_fixnum(1));
L38:;
   if (Null(v7pad_right)) { goto L41; }
   T0 = lex0[3];
   lex0[3] = ecl_plus(T0,ecl_make_fixnum(1));
L41:;
   if (!(ecl_zerop(lex0[3]))) { goto L44; }
   T0 = lex0[3];
   lex0[3] = ecl_plus(T0,ecl_make_fixnum(1));
   v6pad_left = ECL_T;
L44:;
   if (Null(v6pad_left)) { goto L49; }
   LC122do_padding(lex0, ECL_T);
L49:;
   if (Null(v5strings)) { goto L51; }
   T0 = ecl_car(v5strings);
   cl_write_string(2, T0, lex0[0]);
   {
    cl_object v15;
    v15 = ecl_cdr(v5strings);
    goto L57;
L56:;
    {
     cl_object v16string;
     v16string = ecl_car(v15);
     LC122do_padding(lex0, ECL_NIL);
     cl_write_string(2, v16string, lex0[0]);
    }
    v15 = ecl_cdr(v15);
L57:;
    if (Null(v15)) { goto L65; }
    goto L56;
L65:;
   }
L51:;
   if (Null(v7pad_right)) { goto L67; }
   value0 = LC122do_padding(lex0, ECL_T);
   return value0;
L67:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function DO-PADDING                                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC122do_padding(volatile cl_object *lex0, cl_object v1border)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2pad_len;
   T0 = lex0[4];
   v2pad_len = ecl_truncate2(T0,lex0[3]);
   T0 = lex0[4];
   lex0[4] = ecl_minus(T0,v2pad_len);
   T0 = lex0[3];
   lex0[3] = ecl_minus(T0,ecl_make_fixnum(1));
   if ((v1border)!=ECL_NIL) { goto L6; }
   v2pad_len = ecl_plus(v2pad_len,lex0[1]);
L6:;
   {
    cl_object v3i;
    v3i = ecl_make_fixnum(0);
    goto L11;
L10:;
    cl_write_char(2, lex0[2], lex0[0]);
    v3i = ecl_one_plus(v3i);
L11:;
    if (!(ecl_number_compare(v3i,v2pad_len)<0)) { goto L16; }
    goto L10;
L16:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for PARSE-FORMAT-LOGICAL-BLOCK            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L124parse_format_logical_block(cl_object v1segments, cl_object v2colonp, cl_object v3first_semi, cl_object v4close, cl_object v5params, cl_object v6string, cl_object v7end)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  L115check_output_layout_mode(ecl_make_fixnum(1));
  if (Null(v5params)) { goto L2; }
  T0 = ecl_caar(v5params);
  cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_64, ECL_SYM("OFFSET",1279), T0);
L2:;
  {
   cl_object v9;                                  /*  PREFIX          */
   cl_object v10;                                 /*  INSIDES         */
   cl_object v11;                                 /*  SUFFIX          */
   {
    cl_object v13;                                /*  PREFIX-DEFAULT  */
    cl_object v14;                                /*  SUFFIX-DEFAULT  */
    if (Null(v2colonp)) { goto L6; }
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = _ecl_static_66;
    cl_env_copy->values[0] = _ecl_static_65;
    value0 = cl_env_copy->values[0];
    goto L5;
L6:;
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = _ecl_static_36;
    cl_env_copy->values[0] = _ecl_static_36;
    value0 = cl_env_copy->values[0];
L5:;
    v13 = value0;
    v14 = cl_env_copy->values[1];
    {
     cl_fixnum v15;
     v15 = ecl_length(v1segments);
     if (!((v15)==(0))) { goto L9; }
     cl_env_copy->nvalues = 3;
     cl_env_copy->values[2] = v14;
     cl_env_copy->values[1] = ECL_NIL;
     cl_env_copy->values[0] = v13;
     value0 = cl_env_copy->values[0];
     goto L4;
L9:;
     if (!((v15)==(1))) { goto L11; }
     T0 = ecl_car(v1segments);
     cl_env_copy->nvalues = 3;
     cl_env_copy->values[2] = v14;
     cl_env_copy->values[1] = T0;
     cl_env_copy->values[0] = v13;
     value0 = cl_env_copy->values[0];
     goto L4;
L11:;
     if (!((v15)==(2))) { goto L13; }
     T1 = ecl_car(v1segments);
     T0 = LC123extract_string(T1, ECL_T);
     T1 = ecl_cadr(v1segments);
     cl_env_copy->nvalues = 3;
     cl_env_copy->values[2] = v14;
     cl_env_copy->values[1] = T1;
     cl_env_copy->values[0] = T0;
     value0 = cl_env_copy->values[0];
     goto L4;
L13:;
     if (!((v15)==(3))) { goto L16; }
     T1 = ecl_car(v1segments);
     T0 = LC123extract_string(T1, ECL_T);
     T1 = ecl_cadr(v1segments);
     T3 = ecl_caddr(v1segments);
     T2 = LC123extract_string(T3, ECL_NIL);
     cl_env_copy->nvalues = 3;
     cl_env_copy->values[2] = T2;
     cl_env_copy->values[1] = T1;
     cl_env_copy->values[0] = T0;
     value0 = cl_env_copy->values[0];
     goto L4;
L16:;
     value0 = cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_68);
    }
   }
L4:;
   v9 = value0;
   {
    const int v12 = cl_env_copy->nvalues;
    cl_object v13;
    v13 = (v12<=1)? ECL_NIL : cl_env_copy->values[1];
    v10 = v13;
    v13 = (v12<=2)? ECL_NIL : cl_env_copy->values[2];
    v11 = v13;
   }
   if (Null(ecl_function_dispatch(cl_env_copy,VV[252])(1, v4close) /*  FORMAT-DIRECTIVE-ATSIGNP */)) { goto L20; }
   if (Null(v3first_semi)) { goto L24; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[243])(1, v3first_semi) /*  FORMAT-DIRECTIVE-END */;
   goto L23;
L24:;
   T0 = v7end;
L23:;
   v10 = L125add_fill_style_newlines(v10, v6string, T0);
L20:;
   if (Null(v3first_semi)) { goto L28; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v3first_semi) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   goto L26;
L28:;
   T0 = ECL_NIL;
   goto L26;
L26:;
   cl_env_copy->nvalues = 4;
   cl_env_copy->values[3] = v11;
   cl_env_copy->values[2] = v10;
   cl_env_copy->values[1] = T0;
   cl_env_copy->values[0] = v9;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function EXTRACT-STRING                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC123extract_string(cl_object v1list, cl_object v2prefix_p)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3directive;
   T0 = (VV[6]->symbol.gfdef);
   v3directive = cl_find_if(2, T0, v1list);
   if (Null(v3directive)) { goto L3; }
   T0 = ecl_list1(v2prefix_p);
   T1 = ecl_function_dispatch(cl_env_copy,VV[243])(1, v3directive) /*  FORMAT-DIRECTIVE-END */;
   T2 = ecl_one_minus(T1);
   value0 = cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_67, VV[56], T0, ECL_SYM("OFFSET",1279), T2);
   return value0;
L3:;
   T0 = (ECL_SYM("CONCATENATE",244)->symbol.gfdef);
   value0 = cl_apply(3, T0, ECL_SYM("STRING",805), v1list);
   return value0;
  }
 }
}
/*	function definition for ADD-FILL-STYLE-NEWLINES               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L125add_fill_style_newlines(cl_object v1list, cl_object v2string, cl_object v3offset)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1list)) { goto L1; }
  {
   cl_object v4directive;
   v4directive = ecl_car(v1list);
   if (Null(cl_simple_string_p(v4directive))) { goto L4; }
   T0 = L126add_fill_style_newlines_aux(v4directive, v2string, v3offset);
   T1 = ecl_cdr(v1list);
   {
    cl_fixnum v5;
    v5 = ecl_length(v4directive);
    T2 = ecl_plus(v3offset,ecl_make_fixnum(v5));
    T3 = L125add_fill_style_newlines(T1, v2string, T2);
    value0 = ecl_nconc(T0,T3);
    cl_env_copy->nvalues = 1;
    return value0;
   }
L4:;
   T0 = ecl_cdr(v1list);
   T1 = ecl_function_dispatch(cl_env_copy,VV[243])(1, v4directive) /*  FORMAT-DIRECTIVE-END */;
   T2 = L125add_fill_style_newlines(T0, v2string, T1);
   value0 = CONS(v4directive,T2);
   cl_env_copy->nvalues = 1;
   return value0;
  }
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for ADD-FILL-STYLE-NEWLINES-AUX           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L126add_fill_style_newlines_aux(cl_object v1literal, cl_object v2string, cl_object v3offset)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v4;
   cl_object v5posn;
   v4 = ecl_length(v1literal);
   v5posn = ecl_make_fixnum(0);
   {
    cl_object v6;
    cl_object v7;
    v6 = ECL_NIL;
    v7 = ECL_NIL;
L6:;
    {
     cl_object v8blank;
     v8blank = cl_position(4, CODE_CHAR(32), v1literal, ECL_SYM("START",1310), v5posn);
     if (!(v8blank==ECL_NIL)) { goto L9; }
     {
      cl_object v9;
      T0 = cl_subseq(2, v1literal, v5posn);
      v9 = CONS(T0,ECL_NIL);
      if (Null(v7)) { goto L14; }
      if (ecl_unlikely(ECL_ATOM(v7))) FEtype_error_cons(v7);
      T0 = v7;
      (ECL_CONS_CDR(T0)=v9,T0);
      v7 = v9;
      goto L12;
L14:;
      v7 = v9;
      v6 = v9;
     }
L12:;
     goto L5;
L9:;
     {
      cl_object v9non_blank;
      T0 = (ECL_SYM("CHAR/=",216)->symbol.gfdef);
      value0 = cl_position(6, CODE_CHAR(32), v1literal, ECL_SYM("START",1310), v8blank, ECL_SYM("TEST",1316), T0);
      if ((value0)!=ECL_NIL) { goto L27; }
      v9non_blank = ecl_make_fixnum(v4);
      goto L25;
L27:;
      v9non_blank = value0;
      goto L25;
L25:;
      {
       cl_object v10;
       T0 = cl_subseq(3, v1literal, v5posn, v9non_blank);
       v10 = CONS(T0,ECL_NIL);
       if (Null(v7)) { goto L33; }
       if (ecl_unlikely(ECL_ATOM(v7))) FEtype_error_cons(v7);
       T0 = v7;
       (ECL_CONS_CDR(T0)=v10,T0);
       v7 = v10;
       goto L31;
L33:;
       v7 = v10;
       v6 = v10;
      }
L31:;
      {
       cl_object v10;
       T0 = ecl_plus(v3offset,v9non_blank);
       T1 = ecl_plus(v3offset,v9non_blank);
       T2 = L3make_format_directive(14, VV[19], v2string, VV[20], CODE_CHAR(95), ECL_SYM("START",1310), T0, ECL_SYM("END",1225), T1, VV[21], ECL_T, VV[22], ECL_NIL, VV[23], ECL_NIL);
       v10 = CONS(T2,ECL_NIL);
       if (Null(v7)) { goto L46; }
       if (ecl_unlikely(ECL_ATOM(v7))) FEtype_error_cons(v7);
       T0 = v7;
       (ECL_CONS_CDR(T0)=v10,T0);
       v7 = v10;
       goto L44;
L46:;
       v7 = v10;
       v6 = v10;
      }
L44:;
      v5posn = v9non_blank;
     }
     if (!(ecl_number_equalp(v5posn,ecl_make_fixnum(v4)))) { goto L7; }
     goto L5;
    }
L7:;
    goto L6;
L5:;
    value0 = v6;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for EXPAND-FORMAT-LOGICAL-BLOCK           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L127expand_format_logical_block(cl_object v1prefix, cl_object v2per_line_p, cl_object v3insides, cl_object v4suffix, cl_object v5atsignp)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v5atsignp)) { goto L2; }
  T0 = VV[39];
  goto L1;
L2:;
  T0 = L14expand_next_arg(0);
L1:;
  T1 = cl_list(2, VV[62], T0);
  T2 = ecl_list1(T1);
  if (Null(v5atsignp)) { goto L5; }
  cl_set(VV[28],ECL_NIL);
  T3 = VV[224];
  goto L4;
L5:;
  T3 = ECL_NIL;
L4:;
  if (Null(v2per_line_p)) { goto L10; }
  T4 = VV[225];
  goto L9;
L10:;
  T4 = VV[226];
L9:;
  T5 = cl_list(6, ECL_SYM("STREAM",799), VV[62], T4, v1prefix, VV[227], v4suffix);
  if ((v5atsignp)!=ECL_NIL) { goto L13; }
  T6 = VV[229];
  goto L12;
L13:;
  T6 = ECL_NIL;
L12:;
  T7 = CONS(VV[228],T6);
  if ((v5atsignp)!=ECL_NIL) { goto L16; }
  T8 = VV[230];
  goto L15;
L16:;
  T8 = ECL_NIL;
L15:;
  T9 = cl_listX(3, ECL_SYM("IGNORABLE",427), VV[39], T8);
  T10 = cl_list(2, ECL_SYM("DECLARE",274), T9);
  ecl_bds_bind(cl_env_copy,VV[26],VV[47]);        /*  *EXPANDER-NEXT-ARG-MACRO* */
  ecl_bds_bind(cl_env_copy,VV[28],ECL_NIL);       /*  *ONLY-SIMPLE-ARGS* */
  ecl_bds_bind(cl_env_copy,VV[29],ECL_T);         /*  *ORIG-ARGS-AVAILABLE* */
  T11 = L12expand_directive_list(v3insides);
  ecl_bds_unwind1(cl_env_copy);
  ecl_bds_unwind1(cl_env_copy);
  ecl_bds_unwind1(cl_env_copy);
  T12 = cl_listX(3, ECL_SYM("BLOCK",137), ECL_NIL, T11);
  T13 = cl_list(4, ECL_SYM("LET",477), T7, T10, T12);
  T14 = cl_list(3, ECL_SYM("PPRINT-LOGICAL-BLOCK",653), T5, T13);
  T15 = ecl_list1(T14);
  T16 = ecl_append(T3,T15);
  value0 = cl_listX(3, ECL_SYM("LET",477), T2, T16);
  return value0;
 }
}
/*	function definition for INTERPRET-FORMAT-LOGICAL-BLOCK        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L132interpret_format_logical_block(cl_object volatile v1stream, cl_object volatile v2orig_args, cl_object volatile v3args, cl_object volatile v4prefix, cl_object volatile v5per_line_p, cl_object volatile v6insides, cl_object volatile v7suffix, cl_object volatile v8atsignp)
{
 cl_object T0;
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1, CLV2, CLV3
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v2orig_args,env0);           /*  ORIG-ARGS       */
  CLV1 = env0 = CONS(v6insides,env0);             /*  INSIDES         */
  CLV2 = env0 = CONS(v8atsignp,env0);             /*  ATSIGNP         */
  {
   volatile cl_object env1 = env0;
   if (Null(ECL_CONS_CAR(CLV2))) { goto L3; }
   T0 = v3args;
   goto L2;
L3:;
   if (!(v3args==ECL_NIL)) { goto L5; }
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L5:;
   if (Null(ecl_symbol_value(VV[25]))) { goto L7; }
   ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L7:;
   {
    cl_object v9;
    v9 = v3args;
    if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
    if (Null(v9)) { goto L12; }
    {
     cl_object v10;
     v10 = ECL_CONS_CDR(v9);
     v3args = v10;
     v9 = ECL_CONS_CAR(v9);
    }
L12:;
    T0 = v9;
   }
L2:;
   CLV3 = env1 = CONS(T0,env1);                   /*  ARG             */
   if (Null(v5per_line_p)) { goto L18; }
   {cl_object v9;
    v9 = ECL_NIL;
    v9 = ecl_make_cclosure_va((cl_objectfn)LC129__pprint_logical_block_2033,env1,Cblock);
    T0 = v9;
   }
   si_pprint_logical_block_helper(6, T0, ECL_CONS_CAR(CLV3), v1stream, v4prefix, ECL_T, v7suffix);
   goto L1;
L18:;
   {cl_object v9;
    v9 = ECL_NIL;
    v9 = ecl_make_cclosure_va((cl_objectfn)LC131__pprint_logical_block_2047,env1,Cblock);
    T0 = v9;
   }
   si_pprint_logical_block_helper(6, T0, ECL_CONS_CAR(CLV3), v1stream, v4prefix, ECL_NIL, v7suffix);
  }
L1:;
  if (Null(ECL_CONS_CAR(CLV2))) { goto L22; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L22:;
  value0 = v3args;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	closure PPRINT-LOGICAL-BLOCK-2033                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC129__pprint_logical_block_2033(volatile cl_narg narg, cl_object volatile v1, cl_object volatile v2stream, ...)
{
 cl_object T0;
 cl_object volatile CLV0, CLV1, CLV2, CLV3, CLV4, CLV5, CLV6, CLV7
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object volatile env0 = cl_env_copy->function->cclosure.env;
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV3 = env0;                                     /*  ARG             */
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
  CLV4 = env0 = CONS(v1,env0);
  CLV5 = env0 = CONS(v2stream,env0);              /*  STREAM          */
  {
   volatile cl_object env1 = env0;
   CLV6 = env1 = CONS(ecl_make_fixnum(0),env1);
   {
    CLV7 = env1 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env1);
    if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV7))!=0) {
    value0 = cl_env_copy->values[0];
    ecl_frs_pop(cl_env_copy);
    return value0;
    } else {
    {cl_object v3;
     v3 = ECL_NIL;
     v3 = ecl_make_cclosure_va((cl_objectfn)LC128__g2041,env1,Cblock);
     T0 = v3;
    }
    ecl_bds_bind(cl_env_copy,VV[25],T0);          /*  *LOGICAL-BLOCK-POPPER* */
    value0 = VV[31];
    if (ecl_frs_push(cl_env_copy,value0)) {       /*  BEGIN CATCH 2   */
     value0 = cl_env_copy->values[0];
    } else {
     if (Null(ECL_CONS_CAR(CLV2))) { goto L7; }
     T0 = ECL_CONS_CAR(CLV0);
     goto L6;
L7:;
     T0 = ECL_CONS_CAR(CLV3);
L6:;
     value0 = L8interpret_directive_list(ECL_CONS_CAR(CLV5), ECL_CONS_CAR(CLV1), T0, ECL_CONS_CAR(CLV3));
    }
    ecl_frs_pop(cl_env_copy);                     /*  END CATCH 2     */
    ecl_frs_pop(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    return value0;}
   }
  }
 }
 }
}
/*	closure PPRINT-LOGICAL-BLOCK-2047                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC131__pprint_logical_block_2047(volatile cl_narg narg, cl_object volatile v1, cl_object volatile v2stream, ...)
{
 cl_object T0;
 cl_object volatile CLV0, CLV1, CLV2, CLV3, CLV4, CLV5, CLV6, CLV7
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object volatile env0 = cl_env_copy->function->cclosure.env;
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV3 = env0;                                     /*  ARG             */
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
  CLV4 = env0 = CONS(v1,env0);
  CLV5 = env0 = CONS(v2stream,env0);              /*  STREAM          */
  {
   volatile cl_object env1 = env0;
   CLV6 = env1 = CONS(ecl_make_fixnum(0),env1);
   {
    CLV7 = env1 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env1);
    if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV7))!=0) {
    value0 = cl_env_copy->values[0];
    ecl_frs_pop(cl_env_copy);
    return value0;
    } else {
    {cl_object v3;
     v3 = ECL_NIL;
     v3 = ecl_make_cclosure_va((cl_objectfn)LC130__g2055,env1,Cblock);
     T0 = v3;
    }
    ecl_bds_bind(cl_env_copy,VV[25],T0);          /*  *LOGICAL-BLOCK-POPPER* */
    value0 = VV[31];
    if (ecl_frs_push(cl_env_copy,value0)) {       /*  BEGIN CATCH 2   */
     value0 = cl_env_copy->values[0];
    } else {
     if (Null(ECL_CONS_CAR(CLV2))) { goto L7; }
     T0 = ECL_CONS_CAR(CLV0);
     goto L6;
L7:;
     T0 = ECL_CONS_CAR(CLV3);
L6:;
     value0 = L8interpret_directive_list(ECL_CONS_CAR(CLV5), ECL_CONS_CAR(CLV1), T0, ECL_CONS_CAR(CLV3));
    }
    ecl_frs_pop(cl_env_copy);                     /*  END CATCH 2     */
    ecl_frs_pop(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    return value0;}
   }
  }
 }
 }
}
/*	closure G2041                                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC128__g2041(cl_narg narg, ...)
{
 cl_object T0, T1;
 cl_object CLV0, CLV1, CLV2, CLV3, CLV4, CLV5, CLV6, CLV7
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV7 = env0;
 CLV6 = _ecl_cdr(CLV7);
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
  T0 = ECL_CONS_CAR(CLV4);
  T1 = ECL_CONS_CAR(CLV6);
  if ((si_pprint_pop_helper(3, T0, T1, ECL_CONS_CAR(CLV5)))!=ECL_NIL) { goto L1; }
  cl_env_copy->values[0] = ECL_NIL;
  cl_env_copy->nvalues = 1;
  cl_return_from(ECL_CONS_CAR(CLV7),ECL_NIL);
L1:;
  T0 = ECL_CONS_CAR(CLV6);
  ECL_CONS_CAR(CLV6) = ecl_plus(T0,ecl_make_fixnum(1));
  {
   cl_object v1;
   v1 = ECL_CONS_CAR(CLV4);
   if (ecl_unlikely(!ECL_LISTP(v1))) FEtype_error_list(v1);
   if (Null(v1)) { goto L9; }
   {
    cl_object v2;
    v2 = ECL_CONS_CDR(v1);
    ECL_CONS_CAR(CLV4) = v2;
    v1 = ECL_CONS_CAR(v1);
   }
L9:;
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
 }
}
/*	closure G2055                                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC130__g2055(cl_narg narg, ...)
{
 cl_object T0, T1;
 cl_object CLV0, CLV1, CLV2, CLV3, CLV4, CLV5, CLV6, CLV7
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV7 = env0;
 CLV6 = _ecl_cdr(CLV7);
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
  T0 = ECL_CONS_CAR(CLV4);
  T1 = ECL_CONS_CAR(CLV6);
  if ((si_pprint_pop_helper(3, T0, T1, ECL_CONS_CAR(CLV5)))!=ECL_NIL) { goto L1; }
  cl_env_copy->values[0] = ECL_NIL;
  cl_env_copy->nvalues = 1;
  cl_return_from(ECL_CONS_CAR(CLV7),ECL_NIL);
L1:;
  T0 = ECL_CONS_CAR(CLV6);
  ECL_CONS_CAR(CLV6) = ecl_plus(T0,ecl_make_fixnum(1));
  {
   cl_object v1;
   v1 = ECL_CONS_CAR(CLV4);
   if (ecl_unlikely(!ECL_LISTP(v1))) FEtype_error_list(v1);
   if (Null(v1)) { goto L9; }
   {
    cl_object v2;
    v2 = ECL_CONS_CDR(v1);
    ECL_CONS_CAR(CLV4) = v2;
    v1 = ECL_CONS_CAR(v1);
   }
L9:;
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
 }
}
/*	local function G2062                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC133__g2062(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_55);
  return value0;
 }
}
/*	local function G2065                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC134__g2065(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6;
   cl_object v7;
   cl_object v8;
   v3 = ecl_function_dispatch(cl_env_copy,VV[269])(1, v1) /*  FORMAT-DIRECTIVE-STRING */;
   v4 = ecl_function_dispatch(cl_env_copy,VV[274])(1, v1) /*  FORMAT-DIRECTIVE-START */;
   v5 = ecl_function_dispatch(cl_env_copy,VV[243])(1, v1) /*  FORMAT-DIRECTIVE-END */;
   v6 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v1) /*  FORMAT-DIRECTIVE-COLONP */;
   v7 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v1) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v8 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v1) /*  FORMAT-DIRECTIVE-PARAMS */;
   {
    cl_object v9symbol;
    v9symbol = L136extract_user_function_name(v3, v4, v5);
    {
     cl_object v10;
     cl_object v11;
     cl_object v12;
     cl_object v13;
     v10 = ECL_NIL;
     v11 = ECL_NIL;
     v12 = ECL_NIL;
     v13 = ECL_NIL;
     {
      cl_object v14;
      v14 = v8;
      goto L17;
L16:;
      {
       cl_object v15param_and_offset;
       v15param_and_offset = ecl_car(v14);
       {
        cl_object v16param;
        v16param = ecl_cdr(v15param_and_offset);
        {
         cl_object v17param_name;
         v17param_name = cl_gensym(0);
         {
          cl_object v18;
          v18 = CONS(v17param_name,ECL_NIL);
          if (Null(v11)) { goto L27; }
          if (ecl_unlikely(ECL_ATOM(v11))) FEtype_error_cons(v11);
          T1 = v11;
          (ECL_CONS_CDR(T1)=v18,T1);
          v11 = v18;
          goto L25;
L27:;
          v11 = v18;
          v10 = v18;
         }
L25:;
         {
          cl_object v18;
          if (!(ecl_eql(v16param,VV[17]))) { goto L40; }
          T1 = L14expand_next_arg(0);
          goto L39;
L40:;
          if (!(ecl_eql(v16param,VV[18]))) { goto L42; }
          T1 = VV[54];
          goto L39;
L42:;
          T1 = v16param;
L39:;
          T2 = cl_list(2, v17param_name, T1);
          v18 = CONS(T2,ECL_NIL);
          if (Null(v13)) { goto L44; }
          if (ecl_unlikely(ECL_ATOM(v13))) FEtype_error_cons(v13);
          T1 = v13;
          (ECL_CONS_CDR(T1)=v18,T1);
          v13 = v18;
          goto L37;
L44:;
          v13 = v18;
          v12 = v18;
         }
L37:;
        }
       }
      }
      v14 = ecl_cdr(v14);
L17:;
      if (Null(v14)) { goto L56; }
      goto L16;
L56:;
     }
     T1 = L14expand_next_arg(0);
     T2 = cl_listX(6, v9symbol, ECL_SYM("STREAM",799), T1, v6, v7, v10);
     T0 = cl_list(3, ECL_SYM("LET",477), v12, T2);
    }
   }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v2;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G2096                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC135__g2096(cl_object v1stream, cl_object v2, cl_object v3, cl_object v4orig_args, cl_object v5args)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6;
   cl_object v7;
   cl_object v8;
   cl_object v9;
   cl_object v10;
   cl_object v11;
   v6 = ecl_function_dispatch(cl_env_copy,VV[269])(1, v2) /*  FORMAT-DIRECTIVE-STRING */;
   v7 = ecl_function_dispatch(cl_env_copy,VV[274])(1, v2) /*  FORMAT-DIRECTIVE-START */;
   v8 = ecl_function_dispatch(cl_env_copy,VV[243])(1, v2) /*  FORMAT-DIRECTIVE-END */;
   v9 = ecl_function_dispatch(cl_env_copy,VV[251])(1, v2) /*  FORMAT-DIRECTIVE-COLONP */;
   v10 = ecl_function_dispatch(cl_env_copy,VV[252])(1, v2) /*  FORMAT-DIRECTIVE-ATSIGNP */;
   v11 = ecl_function_dispatch(cl_env_copy,VV[253])(1, v2) /*  FORMAT-DIRECTIVE-PARAMS */;
   {
    cl_object v12symbol;
    v12symbol = L136extract_user_function_name(v6, v7, v8);
    {
     cl_object v13;
     cl_object v14;
     v13 = ECL_NIL;
     v14 = ECL_NIL;
     {
      cl_object v15;
      v15 = v11;
      goto L15;
L14:;
      {
       cl_object v16param_and_offset;
       v16param_and_offset = ecl_car(v15);
       {
        cl_object v17param;
        v17param = ecl_cdr(v16param_and_offset);
        if (!(ecl_eql(v17param,VV[17]))) { goto L21; }
        {
         cl_object v18x;
         if (!(v5args==ECL_NIL)) { goto L24; }
         cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L24:;
         if (Null(ecl_symbol_value(VV[25]))) { goto L26; }
         ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L26:;
         {
          cl_object v19;
          v19 = v5args;
          if (ecl_unlikely(!ECL_LISTP(v19))) FEtype_error_list(v19);
          if (Null(v19)) { goto L31; }
          {
          cl_object v20;
          v20 = ECL_CONS_CDR(v19);
          v5args = v20;
          v19 = ECL_CONS_CAR(v19);
          }
L31:;
          v18x = v19;
         }
         if (Null(v18x)) { goto L19; }
         {
          cl_object v19;
          v19 = CONS(v18x,ECL_NIL);
          if (Null(v14)) { goto L40; }
          if (ecl_unlikely(ECL_ATOM(v14))) FEtype_error_cons(v14);
          T0 = v14;
          (ECL_CONS_CDR(T0)=v19,T0);
          v14 = v19;
          goto L38;
L40:;
          v14 = v19;
          v13 = v19;
         }
L38:;
         goto L19;
        }
L21:;
        if (!(ecl_eql(v17param,VV[18]))) { goto L50; }
        {
         cl_object v19;
         {
          cl_fixnum v20;
          v20 = ecl_length(v5args);
          v19 = CONS(ecl_make_fixnum(v20),ECL_NIL);
         }
         if (Null(v14)) { goto L54; }
         if (ecl_unlikely(ECL_ATOM(v14))) FEtype_error_cons(v14);
         T0 = v14;
         (ECL_CONS_CDR(T0)=v19,T0);
         v14 = v19;
         goto L52;
L54:;
         v14 = v19;
         v13 = v19;
        }
L52:;
        goto L19;
L50:;
        {
         cl_object v19;
         v19 = CONS(v17param,ECL_NIL);
         if (Null(v14)) { goto L66; }
         if (ecl_unlikely(ECL_ATOM(v14))) FEtype_error_cons(v14);
         T0 = v14;
         (ECL_CONS_CDR(T0)=v19,T0);
         v14 = v19;
         goto L64;
L66:;
         v14 = v19;
         v13 = v19;
        }
L64:;
       }
L19:;
      }
      v15 = ecl_cdr(v15);
L15:;
      if (Null(v15)) { goto L78; }
      goto L14;
L78:;
     }
     T0 = cl_fdefinition(v12symbol);
     if (!(v5args==ECL_NIL)) { goto L80; }
     cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_17);
L80:;
     if (Null(ecl_symbol_value(VV[25]))) { goto L82; }
     ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[25]))(0);
L82:;
     {
      cl_object v15;
      v15 = v5args;
      if (ecl_unlikely(!ECL_LISTP(v15))) FEtype_error_list(v15);
      if (Null(v15)) { goto L88; }
      {
       cl_object v16;
       v16 = ECL_CONS_CDR(v15);
       v5args = v16;
       v15 = ECL_CONS_CAR(v15);
      }
L88:;
      T1 = v15;
     }
     cl_apply(6, T0, v1stream, T1, v9, v10, v13);
    }
   }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v5args;
   cl_env_copy->values[0] = v3;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for EXTRACT-USER-FUNCTION-NAME            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L136extract_user_function_name(cl_object v1string, cl_object v2start, cl_object v3end)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4slash;
   T0 = ecl_one_minus(v3end);
   v4slash = cl_position(8, CODE_CHAR(47), v1string, ECL_SYM("START",1310), v2start, ECL_SYM("END",1225), T0, VV[232], ECL_T);
   if ((v4slash)!=ECL_NIL) { goto L2; }
   cl_error(3, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_69);
L2:;
   {
    cl_object v5name;
    cl_object v6first_colon;
    cl_object v7second_colon;
    cl_object v8package_name;
    cl_object v9package;
    T1 = ecl_one_plus(v4slash);
    T2 = ecl_one_minus(v3end);
    T0 = cl_subseq(3, v1string, T1, T2);
    v5name = cl_string_upcase(1, T0);
    v6first_colon = cl_position(2, CODE_CHAR(58), v5name);
    if (Null(v6first_colon)) { goto L8; }
    T0 = ecl_one_plus(v6first_colon);
    v7second_colon = cl_position(4, CODE_CHAR(58), v5name, ECL_SYM("START",1310), T0);
    goto L7;
L8:;
    v7second_colon = ECL_NIL;
L7:;
    if (Null(v6first_colon)) { goto L11; }
    v8package_name = cl_subseq(3, v5name, ecl_make_fixnum(0), v6first_colon);
    goto L10;
L11:;
    v8package_name = _ecl_static_70;
L10:;
    v9package = cl_find_package(v8package_name);
    if ((v9package)!=ECL_NIL) { goto L14; }
    T0 = ecl_list1(v8package_name);
    cl_error(5, ECL_SYM("FORMAT-ERROR",1074), VV[14], _ecl_static_71, VV[56], T0);
L14:;
    if (Null(v7second_colon)) { goto L17; }
    T1 = ecl_one_plus(v6first_colon);
    if (!(ecl_number_equalp(v7second_colon,T1))) { goto L17; }
    T1 = ecl_one_plus(v7second_colon);
    T0 = cl_subseq(2, v5name, T1);
    goto L16;
L17:;
    if (Null(v6first_colon)) { goto L20; }
    T1 = ecl_one_plus(v6first_colon);
    T0 = cl_subseq(2, v5name, T1);
    goto L16;
L20:;
    T0 = v5name;
L16:;
    value0 = cl_intern(2, T0, v9package);
    return value0;
   }
  }
 }
}

#include "lsp/format.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclWWewOka7_jO7xWE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:LSP;FORMAT.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclWWewOka7_jO7xWE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 cl_set(ECL_SYM("*FEATURES*",34),CONS(VV[0],ecl_symbol_value(ECL_SYM("*FEATURES*",34))));
 si_Xmake_special(VV[1]);
 cl_set(VV[1],_ecl_static_1);
 ecl_cmp_defun(VV[233]);                          /*  FLONUM-TO-STRING */
 ecl_cmp_defun(VV[234]);                          /*  SCALE-EXPONENT  */
 si_define_structure(15, VV[4], _ecl_static_8, ECL_SYM("VECTOR",898), ECL_T, VVtemp[0], VVtemp[1], VV[5], ECL_NIL, ECL_NIL, ECL_NIL, VVtemp[2], ecl_make_fixnum(8), ecl_make_fixnum(0), ECL_NIL, VV[6]);
 ecl_cmp_defun(VV[235]);                          /*  MAKE-FORMAT-DIRECTIVE */
 si_do_deftype(3, VV[4], VVtemp[3], ECL_SYM("VECTOR",898));
 {
  cl_object T0;
 si_Xmake_special(VV[9]);
 T0 = si_make_vector(ECL_T, ecl_make_fixnum(1114112), ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
 cl_set(VV[9],si_fill_array_with_elt(T0, ECL_NIL, ecl_make_fixnum(0), ECL_NIL));
 }
 {
  cl_object T0;
 si_Xmake_special(VV[10]);
 T0 = si_make_vector(ECL_T, ecl_make_fixnum(1114112), ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
 cl_set(VV[10],si_fill_array_with_elt(T0, ECL_NIL, ecl_make_fixnum(0), ECL_NIL));
 }
 si_Xmake_special(VV[11]);
 cl_set(VV[11],ECL_NIL);
 si_Xmake_special(VV[12]);
 cl_set(VV[12],ECL_NIL);
 si_Xmake_special(VV[13]);
 cl_set(VV[13],ECL_NIL);
 (void)0; /* No entry created for TOKENIZE-CONTROL-STRING */
 (void)0; /* No entry created for PARSE-DIRECTIVE */
 si_Xmake_special(VV[24]);
 cl_set(VV[24],ECL_NIL);
 si_Xmake_special(VV[25]);
 cl_set(VV[25],ECL_NIL);
 si_Xmake_special(VV[26]);
 cl_set(VV[26],VV[27]);
 si_Xmake_special(VV[28]);
 si_Xmake_special(VV[29]);
 cl_set(VV[29],ECL_NIL);
 si_Xmake_special(VV[30]);
 ecl_cmp_defun(VV[244]);                          /*  FORMATTER-AUX   */
 (void)0; /* No entry created for INTERPRET-DIRECTIVE-LIST */
 ecl_cmp_defmacro(VV[246]);                       /*  FORMATTER       */
 (void)0; /* No entry created for %FORMATTER */
 (void)0; /* No entry created for EXPAND-CONTROL-STRING */
 (void)0; /* No entry created for EXPAND-DIRECTIVE-LIST */
 (void)0; /* No entry created for EXPAND-DIRECTIVE */
 (void)0; /* No entry created for EXPAND-NEXT-ARG */
 (void)0; /* No entry created for NEED-HAIRY-ARGS */
 ecl_cmp_defmacro(VV[247]);                       /*  EXPANDER-NEXT-ARG */
 ecl_cmp_defmacro(VV[248]);                       /*  EXPANDER-PPRINT-NEXT-ARG */
 ecl_cmp_defun(VV[249]);                          /*  %SET-FORMAT-DIRECTIVE-EXPANDER */
 (void)0; /* No entry created for %SET-FORMAT-DIRECTIVE-INTERPRETER */
 (void)0; /* No entry created for FIND-DIRECTIVE */
 (void)0; /* No entry created for FORMAT-WRITE-FIELD */
 ecl_cmp_defun(VV[250]);                          /*  FORMAT-PRINC    */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC23__g275,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 L18_set_format_directive_expander(CODE_CHAR(65), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC24__g310,ECL_NIL,Cblock,5);
  T0 = v1;
 }
 L19_set_format_directive_interpreter(CODE_CHAR(65), T0);
 }
 ecl_cmp_defun(VV[254]);                          /*  FORMAT-PRIN1    */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC25__g347,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 L18_set_format_directive_expander(CODE_CHAR(83), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC26__g382,ECL_NIL,Cblock,5);
  T0 = v1;
 }
 L19_set_format_directive_interpreter(CODE_CHAR(83), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC27__g419,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 L18_set_format_directive_expander(CODE_CHAR(67), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC28__g426,ECL_NIL,Cblock,5);
  T0 = v1;
 }
 L19_set_format_directive_interpreter(CODE_CHAR(67), T0);
 }
 (void)0; /* No entry created for CHAR-PRINTING-P */
 ecl_cmp_defun(VV[255]);                          /*  FORMAT-PRINT-NAMED-CHARACTER */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC30__g439,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 L18_set_format_directive_expander(CODE_CHAR(87), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC31__g446,ECL_NIL,Cblock,5);
  T0 = v1;
 }
 L19_set_format_directive_interpreter(CODE_CHAR(87), T0);
 }
 ecl_cmp_defun(VV[256]);                          /*  FORMAT-PRINT-INTEGER */
 (void)0; /* No entry created for FORMAT-ADD-COMMAS */
 ecl_cmp_defun(VV[257]);                          /*  EXPAND-FORMAT-INTEGER */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC34__g501,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 L18_set_format_directive_expander(CODE_CHAR(68), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC35__g507,ECL_NIL,Cblock,5);
  T0 = v1;
 }
 L19_set_format_directive_interpreter(CODE_CHAR(68), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC36__g542,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 L18_set_format_directive_expander(CODE_CHAR(66), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC37__g548,ECL_NIL,Cblock,5);
  T0 = v1;
 }
 L19_set_format_directive_interpreter(CODE_CHAR(66), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC38__g583,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 L18_set_format_directive_expander(CODE_CHAR(79), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC39__g589,ECL_NIL,Cblock,5);
  T0 = v1;
 }
 L19_set_format_directive_interpreter(CODE_CHAR(79), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC40__g624,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 L18_set_format_directive_expander(CODE_CHAR(88), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC41__g630,ECL_NIL,Cblock,5);
  T0 = v1;
 }
 L19_set_format_directive_interpreter(CODE_CHAR(88), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC42__g665,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 L18_set_format_directive_expander(CODE_CHAR(82), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC43__g707,ECL_NIL,Cblock,5);
  T0 = v1;
 }
 L19_set_format_directive_interpreter(CODE_CHAR(82), T0);
 }
 si_Xmake_constant(VV[84], VVtemp[4]);
 si_Xmake_constant(VV[85], VVtemp[5]);
 si_Xmake_constant(VV[86], VVtemp[6]);
 si_Xmake_constant(VV[87], VVtemp[7]);
 si_Xmake_constant(VV[88], VVtemp[8]);
 si_Xmake_constant(VV[89], VVtemp[9]);
 (void)0; /* No entry created for FORMAT-PRINT-SMALL-CARDINAL */
 ecl_cmp_defun(VV[258]);                          /*  FORMAT-PRINT-CARDINAL */
 (void)0; /* No entry created for FORMAT-PRINT-CARDINAL-AUX */
 ecl_cmp_defun(VV[259]);                          /*  FORMAT-PRINT-ORDINAL */
 ecl_cmp_defun(VV[260]);                          /*  FORMAT-PRINT-OLD-ROMAN */
 ecl_cmp_defun(VV[261]);                          /*  FORMAT-PRINT-ROMAN */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC46__g776,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 L18_set_format_directive_expander(CODE_CHAR(80), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC47__g784,ECL_NIL,Cblock,5);
  T0 = v1;
 }
 L19_set_format_directive_interpreter(CODE_CHAR(80), T0);
 }
 (void)0; /* No entry created for DECIMAL-STRING */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC49__g795,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 L18_set_format_directive_expander(CODE_CHAR(70), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC50__g837,ECL_NIL,Cblock,5);
  T0 = v1;
 }
 L19_set_format_directive_interpreter(CODE_CHAR(70), T0);
 }
 ecl_cmp_defun(VV[262]);                          /*  FORMAT-FIXED    */
 (void)0; /* No entry created for FORMAT-FIXED-AUX */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC52__g894,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 L18_set_format_directive_expander(CODE_CHAR(69), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC53__g950,ECL_NIL,Cblock,5);
  T0 = v1;
 }
 L19_set_format_directive_interpreter(CODE_CHAR(69), T0);
 }
 ecl_cmp_defun(VV[263]);                          /*  FORMAT-EXPONENTIAL */
 (void)0; /* No entry created for FORMAT-EXPONENT-MARKER */
 (void)0; /* No entry created for FORMAT-EXP-AUX */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC56__g1026,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 L18_set_format_directive_expander(CODE_CHAR(71), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC57__g1082,ECL_NIL,Cblock,5);
  T0 = v1;
 }
 L19_set_format_directive_interpreter(CODE_CHAR(71), T0);
 }
 ecl_cmp_defun(VV[264]);                          /*  FORMAT-GENERAL  */
 (void)0; /* No entry created for FORMAT-GENERAL-AUX */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC59__g1138,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 L18_set_format_directive_expander(CODE_CHAR(36), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC60__g1173,ECL_NIL,Cblock,5);
  T0 = v1;
 }
 L19_set_format_directive_interpreter(CODE_CHAR(36), T0);
 }
 ecl_cmp_defun(VV[265]);                          /*  FORMAT-DOLLARS  */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC61__g1216,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 L18_set_format_directive_expander(CODE_CHAR(37), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC62__g1229,ECL_NIL,Cblock,5);
  T0 = v1;
 }
 L19_set_format_directive_interpreter(CODE_CHAR(37), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC63__g1247,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 L18_set_format_directive_expander(CODE_CHAR(38), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC64__g1260,ECL_NIL,Cblock,5);
  T0 = v1;
 }
 L19_set_format_directive_interpreter(CODE_CHAR(38), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC65__g1278,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 L18_set_format_directive_expander(CODE_CHAR(124), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC66__g1291,ECL_NIL,Cblock,5);
  T0 = v1;
 }
 L19_set_format_directive_interpreter(CODE_CHAR(124), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC67__g1309,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 L18_set_format_directive_expander(CODE_CHAR(126), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC68__g1322,ECL_NIL,Cblock,5);
  T0 = v1;
 }
 L19_set_format_directive_interpreter(CODE_CHAR(126), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC69__g1339,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 L18_set_format_directive_expander(CODE_CHAR(10), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC70__g1345,ECL_NIL,Cblock,5);
  T0 = v1;
 }
 L19_set_format_directive_interpreter(CODE_CHAR(10), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC71__g1351,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 L18_set_format_directive_expander(CODE_CHAR(13), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC72__g1357,ECL_NIL,Cblock,5);
  T0 = v1;
 }
 L19_set_format_directive_interpreter(CODE_CHAR(13), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC73__g1364,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 L18_set_format_directive_expander(CODE_CHAR(84), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC74__g1415,ECL_NIL,Cblock,5);
  T0 = v1;
 }
 L19_set_format_directive_interpreter(CODE_CHAR(84), T0);
 }
 (void)0; /* No entry created for OUTPUT-SPACES */
 ecl_cmp_defun(VV[266]);                          /*  FORMAT-RELATIVE-TAB */
 ecl_cmp_defun(VV[268]);                          /*  FORMAT-ABSOLUTE-TAB */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC76__g1463,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 L18_set_format_directive_expander(CODE_CHAR(95), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC77__g1470,ECL_NIL,Cblock,5);
  T0 = v1;
 }
 L19_set_format_directive_interpreter(CODE_CHAR(95), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC78__g1477,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 L18_set_format_directive_expander(CODE_CHAR(73), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC79__g1490,ECL_NIL,Cblock,5);
  T0 = v1;
 }
 L19_set_format_directive_interpreter(CODE_CHAR(73), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC80__g1503,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 L18_set_format_directive_expander(CODE_CHAR(42), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC81__g1532,ECL_NIL,Cblock,5);
  T0 = v1;
 }
 L19_set_format_directive_interpreter(CODE_CHAR(42), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC82__g1574,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 L18_set_format_directive_expander(CODE_CHAR(63), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC84__g1583,ECL_NIL,Cblock,5);
  T0 = v1;
 }
 L19_set_format_directive_interpreter(CODE_CHAR(63), T0);
 }
 ecl_cmp_defun(VV[270]);                          /*  NSTRING-CAPITALIZE-FIRST */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC86__g1599,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 L18_set_format_directive_expander(CODE_CHAR(40), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC87__g1605,ECL_NIL,Cblock,5);
  T0 = v1;
 }
 L19_set_format_directive_interpreter(CODE_CHAR(40), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC88__g1614,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 L18_set_format_directive_expander(CODE_CHAR(41), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC89__g1617,ECL_NIL,Cblock,5);
  T0 = v1;
 }
 L19_set_format_directive_interpreter(CODE_CHAR(41), T0);
 }
 (void)0; /* No entry created for PARSE-CONDITIONAL-DIRECTIVE */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC91__g1626,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 L18_set_format_directive_expander(CODE_CHAR(91), T0);
 }
 (void)0; /* No entry created for EXPAND-MAYBE-CONDITIONAL */
 (void)0; /* No entry created for EXPAND-TRUE-FALSE-CONDITIONAL */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC96__g1664,ECL_NIL,Cblock,5);
  T0 = v1;
 }
 L19_set_format_directive_interpreter(CODE_CHAR(91), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC97__g1692,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 L18_set_format_directive_expander(CODE_CHAR(59), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC98__g1695,ECL_NIL,Cblock,5);
  T0 = v1;
 }
 L19_set_format_directive_interpreter(CODE_CHAR(59), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC99__g1698,ECL_NIL,Cblock,5);
  T0 = v1;
 }
 L19_set_format_directive_interpreter(CODE_CHAR(93), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC100__g1701,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 L18_set_format_directive_expander(CODE_CHAR(93), T0);
 }
 si_Xmake_special(VV[186]);
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC101__g1704,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 L18_set_format_directive_expander(CODE_CHAR(94), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC102__g1733,ECL_NIL,Cblock,5);
  T0 = v1;
 }
 L19_set_format_directive_interpreter(CODE_CHAR(94), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC107__g1757,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 L18_set_format_directive_expander(CODE_CHAR(123), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC112__g1778,ECL_NIL,Cblock,5);
  T0 = v1;
 }
 L19_set_format_directive_interpreter(CODE_CHAR(123), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC113__g1807,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 L18_set_format_directive_expander(CODE_CHAR(125), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC114__g1810,ECL_NIL,Cblock,5);
  T0 = v1;
 }
 L19_set_format_directive_interpreter(CODE_CHAR(125), T0);
 }
 {
  cl_object T0, T1;
 si_Xmake_special(VV[204]);
 {
  cl_object v1;
  cl_object v2;
  v1 = ECL_NIL;
  if (ecl_unlikely(!ECL_LISTP(VVtemp[10]))) FEtype_error_list(VVtemp[10]);
  v2 = VVtemp[10];
  {
   cl_object v3;
   cl_object v4;
   v3 = ecl_list1(ECL_NIL);
   v4 = v3;
L437:;
   v1 = _ecl_car(v2);
   {
    cl_object v5;
    v5 = _ecl_cdr(v2);
    if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
    v2 = v5;
   }
   if (ecl_unlikely(ECL_ATOM(v4))) FEtype_error_cons(v4);
   T0 = v4;
   T1 = L6parse_directive(v1, ecl_make_fixnum(0));
   v4 = ecl_list1(T1);
   (ECL_CONS_CDR(T0)=v4,T0);
   if (!(ecl_endp(v2))) { goto L450; }
   goto L438;
L450:;
   goto L437;
L438:;
   cl_set(VV[204],ecl_cdr(v3));
   goto L431;
  }
 }
L431:;
 }
 (void)0; /* No entry created for CHECK-OUTPUT-LAYOUT-MODE */
 ecl_cmp_defun(VV[271]);                          /*  ILLEGAL-INSIDE-JUSTIFICATION-P */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC117__g1827,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 L18_set_format_directive_expander(CODE_CHAR(60), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC118__g1841,ECL_NIL,Cblock,5);
  T0 = v1;
 }
 L19_set_format_directive_interpreter(CODE_CHAR(60), T0);
 }
 (void)0; /* No entry created for PARSE-FORMAT-JUSTIFICATION */
 (void)0; /* No entry created for EXPAND-FORMAT-JUSTIFICATION */
 (void)0; /* No entry created for INTERPRET-FORMAT-JUSTIFICATION */
 ecl_cmp_defun(VV[272]);                          /*  FORMAT-JUSTIFICATION */
 (void)0; /* No entry created for PARSE-FORMAT-LOGICAL-BLOCK */
 (void)0; /* No entry created for ADD-FILL-STYLE-NEWLINES */
 (void)0; /* No entry created for ADD-FILL-STYLE-NEWLINES-AUX */
 ecl_cmp_defun(VV[273]);                          /*  EXPAND-FORMAT-LOGICAL-BLOCK */
 (void)0; /* No entry created for INTERPRET-FORMAT-LOGICAL-BLOCK */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC133__g2062,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 L18_set_format_directive_expander(CODE_CHAR(62), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC134__g2065,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 L18_set_format_directive_expander(CODE_CHAR(47), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC135__g2096,ECL_NIL,Cblock,5);
  T0 = v1;
 }
 L19_set_format_directive_interpreter(CODE_CHAR(47), T0);
 }
 (void)0; /* No entry created for EXTRACT-USER-FUNCTION-NAME */
}
