/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPC-WT.LSP                                   */
#include <ecl/ecl-cmp.h>
#include "cmp/cmpc-wt.eclh"
/*	function definition for WT1                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1wt1(cl_object v1form)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (ECL_STRINGP(v1form)) { goto L4; }
  if (ECL_FIXNUMP(v1form)||ECL_BIGNUMP(v1form)) { goto L4; }
  if (!(ECL_CHARACTERP(v1form))) { goto L2; }
  goto L3;
L4:;
L3:;
  ecl_princ(v1form,ecl_symbol_value(VV[0]));
  goto L1;
L2:;
  if (!(ECL_SINGLE_FLOAT_P(v1form))) { goto L7; }
  cl_format(3, ecl_symbol_value(VV[0]), _ecl_static_1, v1form);
  goto L1;
L7:;
  if (!(ECL_DOUBLE_FLOAT_P(v1form))) { goto L9; }
  cl_format(3, ecl_symbol_value(VV[0]), _ecl_static_2, v1form);
  goto L1;
L9:;
  if (!(ECL_LONG_FLOAT_P(v1form))) { goto L11; }
  cl_format(3, ecl_symbol_value(VV[0]), _ecl_static_3, v1form);
  goto L1;
L11:;
  if (Null(si_of_class_p(2, v1form, VV[1]))) { goto L13; }
  ecl_function_dispatch(cl_env_copy,VV[33])(1, v1form) /*  WT-VAR     */;
  goto L1;
L13:;
  ecl_function_dispatch(cl_env_copy,VV[34])(1, v1form) /*  WT-LOC     */;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for WT-H1                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2wt_h1(cl_object v1form)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_bds_bind(cl_env_copy,VV[0],ecl_symbol_value(VV[3])); /*  *COMPILER-OUTPUT1* */
  value0 = L1wt1(v1form);
  ecl_bds_unwind1(cl_env_copy);
  return value0;
 }
}
/*	function definition for WT                                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3wt(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1forms;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1forms = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v2;
   cl_object v3;
   v2 = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v1forms))) FEtype_error_list(v1forms);
   v3 = v1forms;
L4:;
   if (!(ecl_endp(v3))) { goto L6; }
   goto L5;
L6:;
   v2 = _ecl_car(v3);
   {
    cl_object v4;
    v4 = _ecl_cdr(v3);
    if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
    v3 = v4;
   }
   L1wt1(v2);
   goto L4;
L5:;
   value0 = v1forms;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for WT-H                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4wt_h(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1forms;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1forms = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v2;
   cl_object v3;
   v2 = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v1forms))) FEtype_error_list(v1forms);
   v3 = v1forms;
L4:;
   if (!(ecl_endp(v3))) { goto L6; }
   goto L5;
L6:;
   v2 = _ecl_car(v3);
   {
    cl_object v4;
    v4 = _ecl_cdr(v3);
    if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
    v3 = v4;
   }
   L2wt_h1(v2);
   goto L4;
L5:;
   value0 = v1forms;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for WT-NL-H                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5wt_nl_h(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1forms;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1forms = cl_grab_rest_args(args);
  ecl_va_end(args);
  ecl_terpri(ecl_symbol_value(VV[3]));
  {
   cl_object v2;
   cl_object v3;
   v2 = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v1forms))) FEtype_error_list(v1forms);
   v3 = v1forms;
L5:;
   if (!(ecl_endp(v3))) { goto L7; }
   goto L6;
L7:;
   v2 = _ecl_car(v3);
   {
    cl_object v4;
    v4 = _ecl_cdr(v3);
    if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
    v3 = v4;
   }
   L2wt_h1(v2);
   goto L5;
L6:;
   value0 = v1forms;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for PRINC-H                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6princ_h(cl_object v1form)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_princ(v1form,ecl_symbol_value(VV[3]));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for WT-NL                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7wt_nl(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1forms;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1forms = cl_grab_rest_args(args);
  ecl_va_end(args);
  L9wt_nl_indent();
  {
   cl_object v2;
   cl_object v3;
   v2 = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v1forms))) FEtype_error_list(v1forms);
   v3 = v1forms;
L5:;
   if (!(ecl_endp(v3))) { goto L7; }
   goto L6;
L7:;
   v2 = _ecl_car(v3);
   {
    cl_object v4;
    v4 = _ecl_cdr(v3);
    if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
    v3 = v4;
   }
   L1wt1(v2);
   goto L5;
L6:;
   value0 = v1forms;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for WT-NL1                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8wt_nl1(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1forms;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1forms = cl_grab_rest_args(args);
  ecl_va_end(args);
  L1wt1(CODE_CHAR(10));
  {
   cl_object v2;
   cl_object v3;
   v2 = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v1forms))) FEtype_error_list(v1forms);
   v3 = v1forms;
L5:;
   if (!(ecl_endp(v3))) { goto L7; }
   goto L6;
L7:;
   v2 = _ecl_car(v3);
   {
    cl_object v4;
    v4 = _ecl_cdr(v3);
    if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
    v3 = v4;
   }
   L1wt1(v2);
   goto L5;
L6:;
   value0 = v1forms;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for WT-NL-INDENT                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L9wt_nl_indent()
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v1;
   v1 = ecl_symbol_value(VV[12]);
   {
    cl_fixnum v2;
    {
     cl_object v3;
     v3 = (ecl_number_compare(ECL_SYM_VAL(cl_env_copy,VV[13]),ECL_SYM_VAL(cl_env_copy,VV[11]))<=0?ECL_SYM_VAL(cl_env_copy,VV[13]):ECL_SYM_VAL(cl_env_copy,VV[11]));
     if (ecl_unlikely((ecl_fixnum(v3))>=(v1)->vector.dim))
           FEwrong_index(ECL_NIL,v1,-1,ecl_make_fixnum(ecl_fixnum(v3)),(v1)->vector.dim);
     v2 = ecl_fixnum(v3);
    }
    T0 = ecl_aref_unsafe(v1,v2);
   }
  }
  value0 = L1wt1(T0);
  return value0;
 }
}
/*	function definition for WT-OPEN-BRACE                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L10wt_open_brace()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  L1wt1(CODE_CHAR(123));
  cl_set(VV[13],ecl_plus(ecl_symbol_value(VV[13]),ecl_make_fixnum(1)));
  value0 = ecl_symbol_value(VV[13]);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for WT-NL-OPEN-BRACE                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L11wt_nl_open_brace()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  L9wt_nl_indent();
  value0 = L10wt_open_brace();
  return value0;
 }
}
/*	function definition for WT-NL-CLOSE-MANY-BRACES               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L12wt_nl_close_many_braces(cl_object v1final_value)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2diff;
   v2diff = ecl_minus(ecl_symbol_value(VV[13]),v1final_value);
   if (!(ecl_minusp(v2diff))) { goto L2; }
   ecl_function_dispatch(cl_env_copy,VV[46])(2, ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_4) /*  BABOON */;
L2:;
   {
    cl_object v3i;
    cl_object v4;
    v3i = ecl_make_fixnum(0);
    T0 = cl_realp(v2diff);
    if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("REAL",703),v2diff);
    v4 = v2diff;
L7:;
    if (!(ecl_number_compare(v3i,v4)>=0)) { goto L9; }
    goto L8;
L9:;
    L13wt_nl_close_brace();
    v3i = ecl_one_plus(v3i);
    goto L7;
L8:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for WT-NL-CLOSE-BRACE                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L13wt_nl_close_brace()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ecl_plusp(ecl_symbol_value(VV[13])))) { goto L1; }
  cl_set(VV[13],ecl_minus(ecl_symbol_value(VV[13]),ecl_make_fixnum(1)));
  L9wt_nl_indent();
  value0 = L1wt1(CODE_CHAR(125));
  return value0;
L1:;
  value0 = ecl_function_dispatch(cl_env_copy,VV[46])(2, ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_4) /*  BABOON */;
  return value0;
 }
}
/*	local function WITH-INDENTATION                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC14with_indentation(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_cdr(v1);
   value0 = cl_listX(3, ECL_SYM("LET",477), VV[19], v3);
   return value0;
  }
 }
}
/*	function definition for WT-GO                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L15wt_go(cl_object v1label)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (ecl_unlikely(ECL_ATOM(v1label))) FEtype_error_cons(v1label);
  T0 = v1label;
  (ECL_CONS_CDR(T0)=ECL_T,T0);
  v1label = ecl_car(v1label);
  value0 = L3wt(3, _ecl_static_5, v1label, _ecl_static_6);
  return value0;
 }
}
/*	function definition for WT-LABEL                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L16wt_label(cl_object v1label)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_cdr(v1label))) { goto L1; }
  T0 = ecl_car(v1label);
  value0 = L8wt_nl1(3, _ecl_static_7, T0, _ecl_static_8);
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for WT-FILTERED-COMMENT                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L17wt_filtered_comment(cl_object v1text, cl_object v2stream, cl_object v3single_line)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v3single_line)) { goto L2; }
  cl_fresh_line(1, v2stream);
  ecl_princ_str("/*\t",v2stream);
  goto L1;
L2:;
  cl_format(2, v2stream, _ecl_static_10);
L1:;
  {
   cl_fixnum v4l;
   {
    cl_object v5;
    {
     cl_fixnum v6;
     v6 = ecl_length(v1text);
     v5 = ecl_make_integer((v6)-1);
    }
    {
     bool v6;
     v6 = ECL_FIXNUMP(v5);
     if (ecl_unlikely(!(v6)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v5);
    }
    v4l = ecl_fixnum(v5);
   }
   {
    cl_fixnum v5n;
    v5n = 0;
    goto L13;
L12:;
    {
     ecl_character v6c;
     cl_fixnum v7code;
     v6c = ecl_char(v1text,v5n);
     v7code = v6c;
     if ((CODE_CHAR(v6c))==(CODE_CHAR(10))) { goto L20; }
     if (!((CODE_CHAR(v6c))==(CODE_CHAR(9)))) { goto L18; }
     goto L19;
L20:;
L19:;
     ecl_princ(CODE_CHAR(v6c),v2stream);
     goto L15;
L18:;
     if ((v7code)<(32)) { goto L24; }
     if (!((v7code)>(127))) { goto L22; }
     goto L23;
L24:;
L23:;
     cl_format(3, v2stream, _ecl_static_11, ecl_make_fixnum(v7code));
     goto L15;
L22:;
     if (!((v6c)==((ecl_character)(42)))) { goto L26; }
     T0 = ecl_make_integer((v5n)+1);
     T1 = ecl_elt(v1text,ecl_to_size(T0));
     if (!((ecl_char_code(T1))==((ecl_character)(47)))) { goto L26; }
     ecl_princ_char((ecl_character)(92),v2stream);
     goto L15;
L26:;
     ecl_princ(CODE_CHAR(v6c),v2stream);
    }
L15:;
    v5n = (v5n)+1;
L13:;
    if (!((v5n)<(v4l))) { goto L31; }
    goto L12;
L31:;
   }
   {
    ecl_character v5;
    v5 = ecl_char(v1text,v4l);
    ecl_princ(CODE_CHAR(v5),v2stream);
   }
  }
  value0 = cl_format(2, v2stream, _ecl_static_12);
  return value0;
 }
}
/*	function definition for DO-WT-COMMENT                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L18do_wt_comment(cl_object v1message_or_format, cl_object v2args, cl_object v3single_line_p)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_SYMBOLP(v1message_or_format))) { goto L4; }
  if (Null(cl_symbol_package(v1message_or_format))) { goto L1; }
  goto L2;
L4:;
  goto L2;
L2:;
  if (!(ECL_STRINGP(v1message_or_format))) { goto L7; }
  if (Null(v2args)) { goto L9; }
  T1 = (ECL_SYM("FORMAT",387)->symbol.gfdef);
  T0 = cl_apply(4, T1, ECL_NIL, v1message_or_format, v2args);
  goto L6;
L9:;
  T0 = v1message_or_format;
  goto L6;
L7:;
  T0 = cl_princ_to_string(v1message_or_format);
L6:;
  value0 = L17wt_filtered_comment(T0, ecl_symbol_value(VV[0]), v3single_line_p);
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for WT-COMMENT                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L19wt_comment(cl_narg narg, cl_object v1message, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2extra;
  ecl_va_list args; ecl_va_start(args,v1message,narg,1);
  v2extra = cl_grab_rest_args(args);
  ecl_va_end(args);
  value0 = L18do_wt_comment(v1message, v2extra, ECL_NIL);
  return value0;
 }
}
/*	function definition for WT-COMMENT-NL                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L20wt_comment_nl(cl_narg narg, cl_object v1message, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2extra;
  ecl_va_list args; ecl_va_start(args,v1message,narg,1);
  v2extra = cl_grab_rest_args(args);
  ecl_va_end(args);
  value0 = L18do_wt_comment(v1message, v2extra, ECL_T);
  return value0;
 }
}
/*	function definition for ENCODE-STRING                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L21encode_string(cl_object v1string, cl_object v2format)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3output;
   cl_object v4stream;
   {
    cl_fixnum v5;
    v5 = ecl_length(v1string);
    T0 = ecl_times(_ecl_static_13,ecl_make_fixnum(v5));
    T1 = ecl_round1(T0);
    v3output = si_make_pure_array(ECL_SYM("BASE-CHAR",120), T1, ECL_T, ecl_make_fixnum(0), ECL_NIL, ecl_make_fixnum(0));
   }
   v4stream = si_make_sequence_output_stream(3, v3output, ECL_SYM("EXTERNAL-FORMAT",1236), v2format);
   cl_write_string(2, v1string, v4stream);
   value0 = v3output;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for WT-FILTERED-DATA                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L22wt_filtered_data(cl_narg narg, cl_object v1string, cl_object v2stream, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3one_liner;
  cl_object v4external_format;
  ecl_va_list args; ecl_va_start(args,v2stream,narg,2);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L22wt_filtered_datakeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3one_liner = keyvars[0];
   if (Null(keyvars[3])) {
    v4external_format = ECL_SYM("UTF-8",1681);
   } else {
    v4external_format = keyvars[1];
   }
  }
  v1string = L21encode_string(v1string, v4external_format);
  {
   cl_fixnum v5;
   cl_object v6wt_data_column;
   v5 = ecl_length(v1string);
   v6wt_data_column = ecl_make_fixnum(80);
   {
    cl_object v7;
    v7 = ecl_make_integer((v5)+1);
    cl_set(VV[27],ecl_plus(ecl_symbol_value(VV[27]),v7));
   }
   if (Null(v3one_liner)) { goto L11; }
   T0 = _ecl_static_14;
   goto L10;
L11:;
   T0 = _ecl_static_15;
L10:;
   cl_format(2, v2stream, T0);
   {
    cl_object v7i;
    v7i = ecl_make_fixnum(0);
    goto L16;
L15:;
    v6wt_data_column = ecl_minus(v6wt_data_column,ecl_make_fixnum(1));
    if (!(ecl_number_compare(v6wt_data_column,ecl_make_fixnum(0))<0)) { goto L20; }
    cl_format(2, v2stream, _ecl_static_16);
    v6wt_data_column = ecl_make_fixnum(79);
L20:;
    {
     cl_object v8x;
     {
      cl_fixnum v9;
      if (ecl_unlikely((ecl_fixnum(v7i))>=(v1string)->vector.dim))
           FEwrong_index(ECL_NIL,v1string,-1,ecl_make_fixnum(ecl_fixnum(v7i)),(v1string)->vector.dim);
      v9 = ecl_fixnum(v7i);
      v8x = ecl_aref_unsafe(v1string,v9);
     }
     T0 = cl_char_code(v8x);
     if ((ecl_to_fixnum(T0))<(32)) { goto L31; }
     T0 = cl_char_code(v8x);
     if (!((ecl_to_fixnum(T0))>(127))) { goto L29; }
     goto L30;
L31:;
L30:;
     if (!(((v8x)==ECL_CODE_CHAR((ecl_character)(10))))) { goto L33; }
     ecl_princ_str("\\n",v2stream);
     goto L24;
L33:;
     if (!(((v8x)==ECL_CODE_CHAR((ecl_character)(9))))) { goto L36; }
     ecl_princ_str("\\t",v2stream);
     goto L24;
L36:;
     T0 = cl_char_code(v8x);
     cl_format(3, v2stream, _ecl_static_19, T0);
     goto L24;
L29:;
     if (!(ecl_char_code(v8x)==ecl_char_code(CODE_CHAR(92)))) { goto L39; }
     ecl_princ_str("\\\\",v2stream);
     goto L24;
L39:;
     if (!(ecl_char_code(v8x)==ecl_char_code(CODE_CHAR(34)))) { goto L42; }
     ecl_princ_str("\\\"",v2stream);
     goto L24;
L42:;
     ecl_princ(v8x,v2stream);
    }
L24:;
    v7i = ecl_one_plus(v7i);
L16:;
    if (!(ecl_number_compare(v7i,ecl_make_fixnum(v5))<0)) { goto L47; }
    goto L15;
L47:;
   }
   if (Null(v3one_liner)) { goto L51; }
   T0 = _ecl_static_14;
   goto L50;
L51:;
   T0 = _ecl_static_22;
L50:;
   ecl_princ(T0,v2stream);
   value0 = v1string;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for C-FILTERED-STRING                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L23c_filtered_string(cl_narg narg, cl_object v1string, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2args;
  ecl_va_list args; ecl_va_start(args,v1string,narg,1);
  v2args = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v3aux_stream;
   v3aux_stream = cl_make_string_output_stream(0);
   T0 = ecl_fdefinition(VV[29]);
   cl_apply(6, T0, v1string, v3aux_stream, VV[30], ECL_T, v2args);
   value0 = cl_get_output_stream_string(v3aux_stream);
   return value0;
  }
 }
}

#include "cmp/cmpc-wt.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclJ2QtS0vr7c0n9_f8ptVE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPC-WT.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclJ2QtS0vr7c0n9_f8ptVE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[32]);                           /*  WT1             */
 ecl_cmp_defun(VV[35]);                           /*  WT-H1           */
 ecl_cmp_defun(VV[36]);                           /*  WT              */
 ecl_cmp_defun(VV[37]);                           /*  WT-H            */
 ecl_cmp_defun(VV[38]);                           /*  WT-NL-H         */
 ecl_cmp_defun(VV[39]);                           /*  PRINC-H         */
 ecl_cmp_defun(VV[40]);                           /*  WT-NL           */
 ecl_cmp_defun(VV[41]);                           /*  WT-NL1          */
 si_Xmake_special(VV[11]);
 if (ecl_boundp(cl_env_copy,VV[11])) { goto L35; }
 cl_set(VV[11],ecl_make_fixnum(10));
L35:;
 si_Xmake_special(VV[12]);
 if (ecl_boundp(cl_env_copy,VV[12])) { goto L42; }
 cl_set(VV[12],VVtemp[0]);
L42:;
 ecl_cmp_defun(VV[42]);                           /*  WT-NL-INDENT    */
 ecl_cmp_defun(VV[43]);                           /*  WT-OPEN-BRACE   */
 ecl_cmp_defun(VV[44]);                           /*  WT-NL-OPEN-BRACE */
 ecl_cmp_defun(VV[45]);                           /*  WT-NL-CLOSE-MANY-BRACES */
 ecl_cmp_defun(VV[47]);                           /*  WT-NL-CLOSE-BRACE */
 ecl_cmp_defmacro(VV[48]);                        /*  WITH-INDENTATION */
 ecl_cmp_defun(VV[49]);                           /*  WT-GO           */
 ecl_cmp_defun(VV[50]);                           /*  WT-LABEL        */
 ecl_cmp_defun(VV[51]);                           /*  WT-FILTERED-COMMENT */
 ecl_cmp_defun(VV[52]);                           /*  DO-WT-COMMENT   */
 ecl_cmp_defun(VV[53]);                           /*  WT-COMMENT      */
 ecl_cmp_defun(VV[54]);                           /*  WT-COMMENT-NL   */
 si_Xmake_special(VV[27]);
 if (ecl_boundp(cl_env_copy,VV[27])) { goto L95; }
 cl_set(VV[27],ecl_make_fixnum(0));
L95:;
 ecl_cmp_defun(VV[55]);                           /*  ENCODE-STRING   */
 ecl_cmp_defun(VV[56]);                           /*  WT-FILTERED-DATA */
 ecl_cmp_defun(VV[59]);                           /*  C-FILTERED-STRING */
}
