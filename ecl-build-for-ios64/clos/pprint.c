/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:LSP;PPRINT.LSP                                    */
#include <ecl/ecl-cmp.h>
#include "clos/pprint.eclh"
/*	local function G0                                             */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC1__g0()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 value0 = ECL_SYM_VAL(cl_env_copy,ECL_SYM("*PRINT-RIGHT-MARGIN*",58));
 if ((value0)!=ECL_NIL) { goto L2; }
 value0 = ecl_make_fixnum(80);
 cl_env_copy->nvalues = 1;
 return value0;
L2:;
 cl_env_copy->nvalues = 1;
 return value0;
}
/*	local function G1                                             */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC2__g1()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 value0 = cl_make_string(1, ecl_make_fixnum(128));
 return value0;
}
/*	local function G2                                             */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC3__g2()
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 T0 = L17make_logical_block(0);
 value0 = ecl_list1(T0);
 cl_env_copy->nvalues = 1;
 return value0;
}
/*	local function G3                                             */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC4__g3()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 value0 = cl_make_string(1, ecl_make_fixnum(128));
 return value0;
}
/*	local function G4                                             */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC5__g4()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 value0 = cl_make_string(1, ecl_make_fixnum(128));
 return value0;
}
/*	function definition for PRETTY-STREAM-P                       */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L6pretty_stream_p(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 value0 = si_of_class_p(2, v1stream, VV[4]);
 return value0;
}
/*	function definition for MAKE-PRETTY-STREAM                    */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L7make_pretty_stream(cl_object v1target)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 value0 = si_file_column(v1target);
 if ((value0)!=ECL_NIL) { goto L3; }
 T0 = ecl_make_fixnum(0);
 goto L1;
L3:;
 T0 = value0;
 goto L1;
L1:;
 value0 = (cl_env_copy->function=(ECL_SYM("MAKE-INSTANCE",949)->symbol.gfdef))->cfun.entry(5, VV[4], VV[7], v1target, VV[8], T0) /*  MAKE-INSTANCE */;
 return value0;
}
/*	local function G5                                             */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC8__g5(cl_object v1pretty_stream, cl_object v2stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 value0 = si_print_unreadable_object_function(v1pretty_stream, v2stream, ECL_T, ECL_T, ECL_NIL);
 return value0;
}
/*	function definition for INDEX-POSN                            */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L9index_posn(cl_object v1index, cl_object v2stream)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 cl_fixnum v3index;
 v3index = ecl_fixnum(v1index);
TTL:
 T0 = (v2stream)->instance.slots[5];
 value0 = ecl_plus(ecl_make_fixnum(v3index),T0);
 cl_env_copy->nvalues = 1;
 return value0;
}
/*	function definition for POSN-INDEX                            */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L10posn_index(cl_object v1posn, cl_object v2stream)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 cl_fixnum v3posn;
 v3posn = ecl_fixnum(v1posn);
TTL:
 T0 = (v2stream)->instance.slots[5];
 value0 = ecl_minus(ecl_make_fixnum(v3posn),T0);
 cl_env_copy->nvalues = 1;
 return value0;
}
/*	function definition for POSN-COLUMN                           */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L11posn_column(cl_object v1posn, cl_object v2stream)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 cl_fixnum v3posn;
 v3posn = ecl_fixnum(v1posn);
TTL:
 T1 = (v2stream)->instance.slots[5];
 T0 = ecl_minus(ecl_make_fixnum(v3posn),T1);
 value0 = L34index_column(T0, v2stream);
 return value0;
}
/*	local function G8                                             */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC12__g8(cl_object v1stream, cl_object v2char)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 value0 = L15pretty_out(v1stream, v2char);
 return value0;
}
/*	local function G9                                             */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC13__g9(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 value0 = ECL_NIL;
 cl_env_copy->nvalues = 1;
 return value0;
}
/*	local function G10                                            */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC14__g10(cl_object v1stream)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 T0 = (v1stream)->instance.slots[1];
 value0 = cl_clear_output(1, T0);
 return value0;
}
/*	function definition for PRETTY-OUT                            */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L15pretty_out(cl_object v1stream, cl_object v2char)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_character v3char;
 v3char = CHAR_CODE(v2char);
TTL:
 if (!((v3char)==((ecl_character)(10)))) { goto L1; }
 value0 = L24enqueue_newline(v1stream, VV[13]);
 return value0;
L1:;
 L36assure_space_in_buffer(v1stream, ecl_make_fixnum(1));
 {
  cl_object v4fill_pointer;
  v4fill_pointer = (v1stream)->instance.slots[4];
  T0 = (v1stream)->instance.slots[3];
  ecl_char_set(T0,ecl_fixnum(v4fill_pointer),v3char);
  {
   cl_object v5;
   v5 = ecl_one_plus(v4fill_pointer);
   value0 = (v1stream)->instance.slots[4]=(v5);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for PRETTY-SOUT                           */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L16pretty_sout(cl_object v1stream, cl_object v2string, cl_object v3start, cl_object v4end)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 cl_fixnum v5start;
 v5start = ecl_fixnum(v3start);
TTL:
 {
  cl_object v6end;
  value0 = v4end;
  if ((value0)!=ECL_NIL) { goto L3; }
  v6end = ecl_make_fixnum((v2string)->vector.fillp);
  goto L1;
L3:;
  v6end = value0;
  goto L1;
L1:;
  if (ecl_number_equalp(ecl_make_fixnum(v5start),v6end)) { goto L5; }
  {
   cl_object v7newline;
   v7newline = cl_position(6, CODE_CHAR(10), v2string, ECL_SYM("START",1310), ecl_make_fixnum(v5start), ECL_SYM("END",1225), v6end);
   if (Null(v7newline)) { goto L8; }
   L16pretty_sout(v1stream, v2string, ecl_make_fixnum(v5start), v7newline);
   L24enqueue_newline(v1stream, VV[13]);
   v5start = (ecl_fixnum(v7newline))+1;
   v4end = v6end;
   goto TTL;
L8:;
   {
    cl_object v8chars;
    v8chars = ecl_minus(v6end,ecl_make_fixnum(v5start));
L18:;
    {
     cl_object v9available;
     cl_object v10count;
     cl_object v11fill_pointer;
     cl_object v12new_fill_ptr;
     v9available = L36assure_space_in_buffer(v1stream, v8chars);
     v10count = (ecl_number_compare(v9available,v8chars)<=0?v9available:v8chars);
     v11fill_pointer = (v1stream)->instance.slots[4];
     v12new_fill_ptr = ecl_plus(v11fill_pointer,v10count);
     T0 = (v1stream)->instance.slots[3];
     cl_replace(8, T0, v2string, ECL_SYM("START1",1311), v11fill_pointer, ECL_SYM("END1",1226), v12new_fill_ptr, ECL_SYM("START2",1312), ecl_make_fixnum(v5start));
     (v1stream)->instance.slots[4]=(v12new_fill_ptr);
     v8chars = ecl_minus(v8chars,v10count);
     if (!(ecl_zerop(v10count))) { goto L32; }
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 1;
     return value0;
L32:;
     v5start = ecl_fixnum(ecl_plus(ecl_make_fixnum(v5start),v10count));
    }
    goto L18;
   }
  }
L5:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for MAKE-LOGICAL-BLOCK                    */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L17make_logical_block(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 cl_object v1;
 cl_object v2;
 cl_object v3;
 cl_object v4;
 cl_object v5;
 cl_object v6;
 ecl_va_list args; ecl_va_start(args,narg,narg,0);
 {
  cl_object keyvars[12];
  cl_parse_key(args,6,L17make_logical_blockkeys,keyvars,NULL,FALSE);
  ecl_va_end(args);
  if (Null(keyvars[6])) {
   v1 = ecl_make_fixnum(0);
  } else {
   v1 = keyvars[0];
  }
  if (Null(keyvars[7])) {
   v2 = ecl_make_fixnum(0);
  } else {
   v2 = keyvars[1];
  }
  if (Null(keyvars[8])) {
   v3 = ecl_make_fixnum(0);
  } else {
   v3 = keyvars[2];
  }
  if (Null(keyvars[9])) {
   v4 = ecl_make_fixnum(0);
  } else {
   v4 = keyvars[3];
  }
  if (Null(keyvars[10])) {
   v5 = ecl_make_fixnum(0);
  } else {
   v5 = keyvars[4];
  }
  if (Null(keyvars[11])) {
   v6 = ecl_make_fixnum(0);
  } else {
   v6 = keyvars[5];
  }
 }
 {
  cl_fixnum v7;
  v7 = 0;
  if (!(ECL_FIXNUMP(v6))) { goto L11; }
  v7 = ecl_fixnum(v6);
  if (!((v7)<=(2305843009213693951))) { goto L16; }
  if ((v7)>=(0)) { goto L7; }
  goto L8;
L16:;
  goto L8;
L11:;
  goto L8;
 }
L8:;
 si_structure_type_error(4, v6, VV[17], VV[14], VV[18]);
L7:;
 {
  cl_fixnum v7;
  v7 = 0;
  if (!(ECL_FIXNUMP(v5))) { goto L22; }
  v7 = ecl_fixnum(v5);
  if (!((v7)<=(2305843009213693951))) { goto L27; }
  if ((v7)>=(0)) { goto L18; }
  goto L19;
L27:;
  goto L19;
L22:;
  goto L19;
 }
L19:;
 si_structure_type_error(4, v5, VV[17], VV[14], VV[19]);
L18:;
 {
  cl_fixnum v7;
  v7 = 0;
  if (!(ECL_FIXNUMP(v4))) { goto L33; }
  v7 = ecl_fixnum(v4);
  if (!((v7)<=(2305843009213693951))) { goto L38; }
  if ((v7)>=(0)) { goto L29; }
  goto L30;
L38:;
  goto L30;
L33:;
  goto L30;
 }
L30:;
 si_structure_type_error(4, v4, VV[17], VV[14], VV[20]);
L29:;
 {
  cl_fixnum v7;
  v7 = 0;
  if (!(ECL_FIXNUMP(v3))) { goto L44; }
  v7 = ecl_fixnum(v3);
  if (!((v7)<=(2305843009213693951))) { goto L49; }
  if ((v7)>=(0)) { goto L40; }
  goto L41;
L49:;
  goto L41;
L44:;
  goto L41;
 }
L41:;
 si_structure_type_error(4, v3, VV[17], VV[14], VV[21]);
L40:;
 if (!(ECL_FIXNUMP(v2))) { goto L54; }
 {
  cl_object v7;
  v7 = ecl_make_fixnum(0);
  if (!(ECL_FIXNUMP(v2)||ECL_BIGNUMP(v2))) { goto L58; }
  v7 = v2;
  if (ecl_number_compare(v7,ecl_make_fixnum(0))>=0) { goto L51; }
  goto L52;
L58:;
  goto L52;
 }
L54:;
 goto L52;
L52:;
 si_structure_type_error(4, v2, VV[0], VV[14], VV[22]);
L51:;
 if (!(ECL_FIXNUMP(v1))) { goto L65; }
 {
  cl_object v7;
  v7 = ecl_make_fixnum(0);
  if (!(ECL_FIXNUMP(v1)||ECL_BIGNUMP(v1))) { goto L69; }
  v7 = v1;
  if (ecl_number_compare(v7,ecl_make_fixnum(0))>=0) { goto L62; }
  goto L63;
L69:;
  goto L63;
 }
L65:;
 goto L63;
L63:;
 si_structure_type_error(4, v1, VV[0], VV[14], VV[23]);
L62:;
 value0 = si_make_structure(7, VV[24], v1, v2, v3, v4, v5, v6);
 return value0;
}
/*	function definition for REALLY-START-LOGICAL-BLOCK            */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L18really_start_logical_block(cl_object v1stream, cl_object v2column, cl_object v3prefix, cl_object v4suffix)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v5blocks;
  cl_object v6prev_block;
  cl_object v7per_line_end;
  cl_object v8prefix_length;
  cl_object v9suffix_length;
  cl_object v10block;
  v5blocks = (v1stream)->instance.slots[8];
  v6prev_block = _ecl_car(v5blocks);
  v7per_line_end = ecl_function_dispatch(cl_env_copy,VV[192])(1, v6prev_block) /*  LOGICAL-BLOCK-PER-LINE-PREFIX-END */;
  v8prefix_length = ecl_function_dispatch(cl_env_copy,VV[193])(1, v6prev_block) /*  LOGICAL-BLOCK-PREFIX-LENGTH */;
  v9suffix_length = ecl_function_dispatch(cl_env_copy,VV[194])(1, v6prev_block) /*  LOGICAL-BLOCK-SUFFIX-LENGTH */;
  T0 = (v1stream)->instance.slots[7];
  v10block = L17make_logical_block(12, VV[26], v2column, VV[27], v2column, VV[28], v7per_line_end, VV[29], v8prefix_length, VV[30], v9suffix_length, VV[31], T0);
  {
   cl_object v11;
   v11 = CONS(v10block,v5blocks);
   (v1stream)->instance.slots[8]=(v11);
  }
  L19set_indentation(v1stream, v2column);
  if (Null(v3prefix)) { goto L15; }
  (v10block)->instance.slots[2]=v2column;
  T0 = (v1stream)->instance.slots[9];
  {
   cl_fixnum v11;
   v11 = ecl_length(v3prefix);
   T1 = ecl_minus(v2column,ecl_make_fixnum(v11));
   cl_replace(6, T0, v3prefix, ECL_SYM("START1",1311), T1, ECL_SYM("END1",1226), v2column);
  }
L15:;
  if (Null(v4suffix)) { goto L1; }
  {
   cl_object v11total_suffix;
   cl_object v12total_suffix_len;
   cl_fixnum v13additional;
   cl_object v14new_suffix_len;
   v11total_suffix = (v1stream)->instance.slots[10];
   v12total_suffix_len = ecl_make_fixnum(ecl_length(v11total_suffix));
   v13additional = ecl_length(v4suffix);
   v14new_suffix_len = ecl_plus(v9suffix_length,ecl_make_fixnum(v13additional));
   if (!(ecl_number_compare(v14new_suffix_len,v12total_suffix_len)>0)) { goto L26; }
   {
    cl_object v15new_total_suffix_len;
    T0 = ecl_times(v12total_suffix_len,ecl_make_fixnum(2));
    T1 = ecl_times(ecl_make_fixnum(v13additional),ecl_make_fixnum(5));
    T2 = ecl_floor2(T1,ecl_make_fixnum(4));
    T3 = ecl_plus(v9suffix_length,T2);
    v15new_total_suffix_len = (ecl_number_compare(T0,T3)>=0?T0:T3);
    T0 = cl_make_string(1, v15new_total_suffix_len);
    T1 = ecl_minus(v15new_total_suffix_len,v9suffix_length);
    T2 = ecl_minus(v12total_suffix_len,v9suffix_length);
    v11total_suffix = cl_replace(6, T0, v11total_suffix, ECL_SYM("START1",1311), T1, ECL_SYM("START2",1312), T2);
    v12total_suffix_len = v15new_total_suffix_len;
    (v1stream)->instance.slots[10]=(v11total_suffix);
   }
L26:;
   T0 = ecl_minus(v12total_suffix_len,v14new_suffix_len);
   T1 = ecl_minus(v12total_suffix_len,v9suffix_length);
   cl_replace(6, v11total_suffix, v4suffix, ECL_SYM("START1",1311), T0, ECL_SYM("END1",1226), T1);
   (v10block)->instance.slots[4]=v14new_suffix_len;
  }
 }
L1:;
 value0 = ECL_NIL;
 cl_env_copy->nvalues = 1;
 return value0;
}
/*	function definition for SET-INDENTATION                       */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L19set_indentation(cl_object v1stream, cl_object v2column)
{
 cl_object T0, T1, T2, T3, T4, T5, T6;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v3prefix;
  cl_fixnum v4prefix_len;
  cl_object v5block;
  cl_object v6current;
  cl_object v7minimum;
  cl_object v8column;
  v3prefix = (v1stream)->instance.slots[9];
  v4prefix_len = ecl_length(v3prefix);
  T0 = (v1stream)->instance.slots[8];
  v5block = _ecl_car(T0);
  v6current = ecl_function_dispatch(cl_env_copy,VV[193])(1, v5block) /*  LOGICAL-BLOCK-PREFIX-LENGTH */;
  v7minimum = ecl_function_dispatch(cl_env_copy,VV[192])(1, v5block) /*  LOGICAL-BLOCK-PER-LINE-PREFIX-END */;
  v8column = (ecl_number_compare(v7minimum,v2column)>=0?v7minimum:v2column);
  if (!(ecl_number_compare(v8column,ecl_make_fixnum(v4prefix_len))>0)) { goto L10; }
  T0 = ecl_times(ecl_make_fixnum(v4prefix_len),ecl_make_fixnum(2));
  T1 = ecl_minus(v8column,ecl_make_fixnum(v4prefix_len));
  T2 = ecl_times(T1,ecl_make_fixnum(5));
  T3 = ecl_floor2(T2,ecl_make_fixnum(4));
  T4 = ecl_plus(ecl_make_fixnum(v4prefix_len),T3);
  T5 = (ecl_number_compare(T0,T4)>=0?T0:T4);
  T6 = cl_make_string(1, T5);
  v3prefix = cl_replace(4, T6, v3prefix, ECL_SYM("END1",1226), v6current);
  (v1stream)->instance.slots[9]=(v3prefix);
L10:;
  if (!(ecl_number_compare(v8column,v6current)>0)) { goto L15; }
  cl_fill(6, v3prefix, CODE_CHAR(32), ECL_SYM("START",1310), v6current, ECL_SYM("END",1225), v8column);
L15:;
  value0 = (v5block)->instance.slots[3]=v8column;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for REALLY-END-LOGICAL-BLOCK              */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L20really_end_logical_block(cl_object v1stream)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v2old;
  cl_object v3old_indent;
  cl_object v4new;
  cl_object v5new_indent;
  {
   cl_object v6;
   v6 = (v1stream)->instance.slots[8];
   if (Null(v6)) { goto L6; }
   {
    cl_object v7;
    v7 = ECL_CONS_CDR(v6);
    (v1stream)->instance.slots[8]=(v7);
    v6 = ECL_CONS_CAR(v6);
   }
L6:;
   v2old = v6;
  }
  v3old_indent = ecl_function_dispatch(cl_env_copy,VV[193])(1, v2old) /*  LOGICAL-BLOCK-PREFIX-LENGTH */;
  T0 = (v1stream)->instance.slots[8];
  v4new = _ecl_car(T0);
  v5new_indent = ecl_function_dispatch(cl_env_copy,VV[193])(1, v4new) /*  LOGICAL-BLOCK-PREFIX-LENGTH */;
  if (!(ecl_number_compare(v5new_indent,v3old_indent)>0)) { goto L1; }
  T0 = (v1stream)->instance.slots[9];
  cl_fill(6, T0, CODE_CHAR(32), ECL_SYM("START",1310), v3old_indent, ECL_SYM("END",1225), v5new_indent);
 }
L1:;
 value0 = ECL_NIL;
 cl_env_copy->nvalues = 1;
 return value0;
}
/*	function definition for MAKE-QUEUED-OP                        */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L21make_queued_op(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 cl_object v1;
 ecl_va_list args; ecl_va_start(args,narg,narg,0);
 {
  cl_object keyvars[2];
  cl_parse_key(args,1,L21make_queued_opkeys,keyvars,NULL,FALSE);
  ecl_va_end(args);
  if (Null(keyvars[1])) {
   v1 = ecl_make_fixnum(0);
  } else {
   v1 = keyvars[0];
  }
 }
 if (ECL_FIXNUMP(v1)) { goto L2; }
 si_structure_type_error(4, v1, VV[1], VV[32], VV[1]);
L2:;
 value0 = si_make_structure(2, VV[35], v1);
 return value0;
}
/*	function definition for MAKE-SECTION-START                    */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L22make_section_start(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 cl_object v1;
 cl_object v2;
 cl_object v3;
 ecl_va_list args; ecl_va_start(args,narg,narg,0);
 {
  cl_object keyvars[6];
  cl_parse_key(args,3,L22make_section_startkeys,keyvars,NULL,FALSE);
  ecl_va_end(args);
  if (Null(keyvars[3])) {
   v1 = ecl_make_fixnum(0);
  } else {
   v1 = keyvars[0];
  }
  if (Null(keyvars[4])) {
   v2 = ecl_make_fixnum(0);
  } else {
   v2 = keyvars[1];
  }
  v3 = keyvars[2];
 }
 if (v3==ECL_NIL) { goto L3; }
 if ((si_of_class_p(2, v3, VV[40]))!=ECL_NIL) { goto L3; }
 if ((si_of_class_p(2, v3, VV[41]))!=ECL_NIL) { goto L3; }
 si_structure_type_error(4, v3, VV[42], VV[37], VV[43]);
L3:;
 {
  cl_fixnum v4;
  v4 = 0;
  if (!(ECL_FIXNUMP(v2))) { goto L11; }
  v4 = ecl_fixnum(v2);
  if (!((v4)<=(2305843009213693951))) { goto L16; }
  if ((v4)>=(0)) { goto L7; }
  goto L8;
L16:;
  goto L8;
L11:;
  goto L8;
 }
L8:;
 si_structure_type_error(4, v2, VV[17], VV[37], VV[44]);
L7:;
 if (ECL_FIXNUMP(v1)) { goto L18; }
 si_structure_type_error(4, v1, VV[1], VV[37], VV[1]);
L18:;
 value0 = si_make_structure(4, VV[45], v1, v2, v3);
 return value0;
}
/*	function definition for MAKE-NEWLINE                          */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L23make_newline(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 cl_object v1;
 cl_object v2;
 cl_object v3;
 cl_object v4;
 ecl_va_list args; ecl_va_start(args,narg,narg,0);
 {
  cl_object keyvars[8];
  cl_parse_key(args,4,L23make_newlinekeys,keyvars,NULL,FALSE);
  ecl_va_end(args);
  if (Null(keyvars[4])) {
   v1 = ecl_make_fixnum(0);
  } else {
   v1 = keyvars[0];
  }
  if (Null(keyvars[5])) {
   v2 = ecl_make_fixnum(0);
  } else {
   v2 = keyvars[1];
  }
  v3 = keyvars[2];
  if (Null(keyvars[7])) {
   v4 = ecl_function_dispatch(cl_env_copy,VV[201])(0) /*  REQUIRED-ARGUMENT */;
  } else {
   v4 = keyvars[3];
  }
 }
 if ((ecl_memql(v4,VV[49]))!=ECL_NIL) { goto L4; }
 si_structure_type_error(4, v4, VV[50], VV[40], VV[51]);
L4:;
 if (v3==ECL_NIL) { goto L6; }
 if ((si_of_class_p(2, v3, VV[40]))!=ECL_NIL) { goto L6; }
 if ((si_of_class_p(2, v3, VV[41]))!=ECL_NIL) { goto L6; }
 si_structure_type_error(4, v3, VV[42], VV[40], VV[43]);
L6:;
 {
  cl_fixnum v5;
  v5 = 0;
  if (!(ECL_FIXNUMP(v2))) { goto L14; }
  v5 = ecl_fixnum(v2);
  if (!((v5)<=(2305843009213693951))) { goto L19; }
  if ((v5)>=(0)) { goto L10; }
  goto L11;
L19:;
  goto L11;
L14:;
  goto L11;
 }
L11:;
 si_structure_type_error(4, v2, VV[17], VV[40], VV[44]);
L10:;
 if (ECL_FIXNUMP(v1)) { goto L21; }
 si_structure_type_error(4, v1, VV[1], VV[40], VV[1]);
L21:;
 value0 = si_make_structure(5, VV[52], v1, v2, v3, v4);
 return value0;
}
/*	function definition for ENQUEUE-NEWLINE                       */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L24enqueue_newline(cl_object v1stream, cl_object v2kind)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_fixnum v3depth;
  cl_object v4newline;
  T0 = (v1stream)->instance.slots[13];
  v3depth = ecl_length(T0);
  {
   cl_object v5;
   {
    cl_object v6;
    v6 = (v1stream)->instance.slots[4];
    T1 = (v1stream)->instance.slots[5];
    T0 = ecl_plus(v6,T1);
   }
   v5 = L23make_newline(6, VV[54], T0, VV[55], v2kind, VV[56], ecl_make_fixnum(v3depth));
   {
    cl_object v6;
    v6 = ecl_list1(v5);
    {
     cl_object v7;
     v7 = (v1stream)->instance.slots[12];
     if (Null(v7)) { goto L16; }
     (ECL_CONS_CDR(v7)=v6,v7);
     goto L15;
L16:;
     (v1stream)->instance.slots[11]=(v6);
L15:;
     (v1stream)->instance.slots[12]=(v6);
     v4newline = v5;
    }
   }
  }
  {
   cl_object v5;
   v5 = (v1stream)->instance.slots[11];
   goto L26;
L25:;
   {
    cl_object v6entry;
    v6entry = _ecl_car(v5);
    if ((v4newline)==(v6entry)) { goto L30; }
    if (Null(ecl_function_dispatch(cl_env_copy,VV[39])(1, v6entry) /*  SECTION-START-P */)) { goto L30; }
    T0 = ecl_function_dispatch(cl_env_copy,VV[206])(1, v6entry) /*  SECTION-START-SECTION-END */;
    if (!(T0==ECL_NIL)) { goto L30; }
    T0 = ecl_function_dispatch(cl_env_copy,VV[207])(1, v6entry) /*  SECTION-START-DEPTH */;
    if (!(ecl_number_compare(ecl_make_fixnum(v3depth),T0)<=0)) { goto L30; }
    (v6entry)->instance.slots[2]=v4newline;
L30:;
   }
   v5 = _ecl_cdr(v5);
L26:;
   if (Null(v5)) { goto L37; }
   goto L25;
L37:;
  }
 }
 value0 = ecl_make_bool((v2kind)==(VV[13]));
 if ((value0)!=ECL_NIL) { goto L41; }
 T0 = ecl_make_bool((v2kind)==(VV[57]));
 goto L39;
L41:;
 T0 = value0;
 goto L39;
L39:;
 value0 = L37maybe_output(v1stream, T0);
 return value0;
}
/*	function definition for MAKE-INDENTATION                      */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L25make_indentation(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 cl_object v1;
 cl_object v2;
 cl_object v3;
 ecl_va_list args; ecl_va_start(args,narg,narg,0);
 {
  cl_object keyvars[6];
  cl_parse_key(args,3,L25make_indentationkeys,keyvars,NULL,FALSE);
  ecl_va_end(args);
  if (Null(keyvars[3])) {
   v1 = ecl_make_fixnum(0);
  } else {
   v1 = keyvars[0];
  }
  if (Null(keyvars[4])) {
   v2 = ecl_function_dispatch(cl_env_copy,VV[201])(0) /*  REQUIRED-ARGUMENT */;
  } else {
   v2 = keyvars[1];
  }
  if (Null(keyvars[5])) {
   v3 = ecl_make_fixnum(0);
  } else {
   v3 = keyvars[2];
  }
 }
 if (ECL_FIXNUMP(v3)) { goto L4; }
 si_structure_type_error(4, v3, ECL_SYM("FIXNUM",372), VV[58], VV[61]);
L4:;
 if (!(ecl_eql(v2,ECL_SYM("BLOCK",1202)))) { goto L10; }
 goto L6;
 goto L8;
L10:;
 goto L8;
L8:;
 if (!(ecl_eql(v2,VV[63]))) { goto L13; }
 goto L6;
 goto L7;
L13:;
 goto L7;
L7:;
 si_structure_type_error(4, v2, VV[65], VV[58], VV[51]);
L6:;
 if (ECL_FIXNUMP(v1)) { goto L15; }
 si_structure_type_error(4, v1, VV[1], VV[58], VV[1]);
L15:;
 value0 = si_make_structure(4, VV[66], v1, v2, v3);
 return value0;
}
/*	function definition for ENQUEUE-INDENT                        */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L26enqueue_indent(cl_object v1stream, cl_object v2kind, cl_object v3amount)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v4;
  {
   cl_object v5;
   v5 = (v1stream)->instance.slots[4];
   T1 = (v1stream)->instance.slots[5];
   T0 = ecl_plus(v5,T1);
  }
  v4 = L25make_indentation(6, VV[54], T0, VV[55], v2kind, VV[68], v3amount);
  {
   cl_object v5;
   v5 = ecl_list1(v4);
   {
    cl_object v6;
    v6 = (v1stream)->instance.slots[12];
    if (Null(v6)) { goto L11; }
    (ECL_CONS_CDR(v6)=v5,v6);
    goto L10;
L11:;
    (v1stream)->instance.slots[11]=(v5);
L10:;
    (v1stream)->instance.slots[12]=(v5);
    value0 = v4;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for MAKE-BLOCK-START                      */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L27make_block_start(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 cl_object v1;
 cl_object v2;
 cl_object v3;
 cl_object v4;
 cl_object v5;
 cl_object v6;
 ecl_va_list args; ecl_va_start(args,narg,narg,0);
 {
  cl_object keyvars[12];
  cl_parse_key(args,6,L27make_block_startkeys,keyvars,NULL,FALSE);
  ecl_va_end(args);
  if (Null(keyvars[6])) {
   v1 = ecl_make_fixnum(0);
  } else {
   v1 = keyvars[0];
  }
  if (Null(keyvars[7])) {
   v2 = ecl_make_fixnum(0);
  } else {
   v2 = keyvars[1];
  }
  v3 = keyvars[2];
  v4 = keyvars[3];
  v5 = keyvars[4];
  v6 = keyvars[5];
 }
 if (v6==ECL_NIL) { goto L3; }
 if (ECL_STRINGP(v6)) { goto L3; }
 si_structure_type_error(4, v6, VV[72], VV[69], VV[73]);
L3:;
 if (v5==ECL_NIL) { goto L6; }
 if (ECL_STRINGP(v5)) { goto L6; }
 si_structure_type_error(4, v5, VV[72], VV[69], VV[74]);
L6:;
 if (v4==ECL_NIL) { goto L9; }
 if ((si_of_class_p(2, v4, VV[41]))!=ECL_NIL) { goto L9; }
 si_structure_type_error(4, v4, VV[75], VV[69], VV[41]);
L9:;
 if (v3==ECL_NIL) { goto L12; }
 if ((si_of_class_p(2, v3, VV[40]))!=ECL_NIL) { goto L12; }
 if ((si_of_class_p(2, v3, VV[41]))!=ECL_NIL) { goto L12; }
 si_structure_type_error(4, v3, VV[42], VV[69], VV[43]);
L12:;
 {
  cl_fixnum v7;
  v7 = 0;
  if (!(ECL_FIXNUMP(v2))) { goto L20; }
  v7 = ecl_fixnum(v2);
  if (!((v7)<=(2305843009213693951))) { goto L25; }
  if ((v7)>=(0)) { goto L16; }
  goto L17;
L25:;
  goto L17;
L20:;
  goto L17;
 }
L17:;
 si_structure_type_error(4, v2, VV[17], VV[69], VV[44]);
L16:;
 if (ECL_FIXNUMP(v1)) { goto L27; }
 si_structure_type_error(4, v1, VV[1], VV[69], VV[1]);
L27:;
 value0 = si_make_structure(7, VV[76], v1, v2, v3, v4, v5, v6);
 return value0;
}
/*	function definition for START-LOGICAL-BLOCK                   */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L28start_logical_block(cl_object v1stream, cl_object v2prefix, cl_object v3per_line_p, cl_object v4suffix)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
TTL:
  T0 = si_of_class_p(2, v1stream, VV[4]);
  if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[4],v1stream);
  {
   bool v5;
   v5 = ECL_STRINGP(v2prefix);
   if (ecl_unlikely(!(v5)))
         FEwrong_type_argument(ECL_SYM("STRING",805),v2prefix);
  }
  {
   bool v5;
   v5 = ECL_STRINGP(v4suffix);
   if (ecl_unlikely(!(v5)))
         FEwrong_type_argument(ECL_SYM("STRING",805),v4suffix);
  }
  {
   cl_fixnum v5prefix_len;
   v5prefix_len = (v2prefix)->vector.fillp;
   if (!((v5prefix_len)>0)) { goto L5; }
   L16pretty_sout(v1stream, v2prefix, ecl_make_fixnum(0), ecl_make_fixnum(v5prefix_len));
L5:;
   {
    cl_object v6pending_blocks;
    cl_object v7start;
    v6pending_blocks = (v1stream)->instance.slots[13];
    {
     cl_object v8;
     {
      cl_object v9;
      v9 = (v1stream)->instance.slots[4];
      T1 = (v1stream)->instance.slots[5];
      T0 = ecl_plus(v9,T1);
     }
     if (!((v5prefix_len)>0)) { goto L18; }
     if (Null(v3per_line_p)) { goto L18; }
     T1 = v2prefix;
     goto L16;
L18:;
     T1 = ECL_NIL;
     goto L16;
L16:;
     {
      cl_fixnum v9;
      v9 = (v4suffix)->vector.fillp;
      if (!((v9)>0)) { goto L23; }
     }
     T2 = v4suffix;
     goto L21;
L23:;
     T2 = ECL_NIL;
     goto L21;
L21:;
     {
      cl_fixnum v9;
      v9 = ecl_length(v6pending_blocks);
      v8 = L27make_block_start(8, VV[54], T0, VV[78], T1, VV[79], T2, VV[56], ecl_make_fixnum(v9));
     }
     {
      cl_object v9;
      v9 = ecl_list1(v8);
      {
       cl_object v10;
       v10 = (v1stream)->instance.slots[12];
       if (Null(v10)) { goto L29; }
       (ECL_CONS_CDR(v10)=v9,v10);
       goto L28;
L29:;
       (v1stream)->instance.slots[11]=(v9);
L28:;
       (v1stream)->instance.slots[12]=(v9);
       v7start = v8;
      }
     }
    }
    {
     cl_object v8;
     v8 = CONS(v7start,v6pending_blocks);
     value0 = (v1stream)->instance.slots[13]=(v8);
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
  }
 }
}
/*	function definition for MAKE-BLOCK-END                        */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L29make_block_end(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 cl_object v1;
 cl_object v2;
 ecl_va_list args; ecl_va_start(args,narg,narg,0);
 {
  cl_object keyvars[4];
  cl_parse_key(args,2,L29make_block_endkeys,keyvars,NULL,FALSE);
  ecl_va_end(args);
  if (Null(keyvars[2])) {
   v1 = ecl_make_fixnum(0);
  } else {
   v1 = keyvars[0];
  }
  v2 = keyvars[1];
 }
 if (v2==ECL_NIL) { goto L2; }
 if (ECL_STRINGP(v2)) { goto L2; }
 si_structure_type_error(4, v2, VV[72], VV[41], VV[73]);
L2:;
 if (ECL_FIXNUMP(v1)) { goto L5; }
 si_structure_type_error(4, v1, VV[1], VV[41], VV[1]);
L5:;
 value0 = si_make_structure(3, VV[82], v1, v2);
 return value0;
}
/*	function definition for END-LOGICAL-BLOCK                     */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L30end_logical_block(cl_object v1stream)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v2start;
  cl_object v3suffix;
  cl_object v4end;
  {
   cl_object v5;
   v5 = (v1stream)->instance.slots[13];
   if (Null(v5)) { goto L5; }
   {
    cl_object v6;
    v6 = ECL_CONS_CDR(v5);
    (v1stream)->instance.slots[13]=(v6);
    v5 = ECL_CONS_CAR(v5);
   }
L5:;
   v2start = v5;
  }
  v3suffix = ecl_function_dispatch(cl_env_copy,VV[222])(1, v2start) /*  BLOCK-START-SUFFIX */;
  {
   cl_object v5;
   {
    cl_object v6;
    v6 = (v1stream)->instance.slots[4];
    T1 = (v1stream)->instance.slots[5];
    T0 = ecl_plus(v6,T1);
   }
   v5 = L29make_block_end(4, VV[54], T0, VV[79], v3suffix);
   {
    cl_object v6;
    v6 = ecl_list1(v5);
    {
     cl_object v7;
     v7 = (v1stream)->instance.slots[12];
     if (Null(v7)) { goto L23; }
     (ECL_CONS_CDR(v7)=v6,v7);
     goto L22;
L23:;
     (v1stream)->instance.slots[11]=(v6);
L22:;
     (v1stream)->instance.slots[12]=(v6);
     v4end = v5;
    }
   }
  }
  if (Null(v3suffix)) { goto L29; }
  {
   cl_fixnum v5;
   v5 = ecl_length(v3suffix);
   L16pretty_sout(v1stream, v3suffix, ecl_make_fixnum(0), ecl_make_fixnum(v5));
  }
L29:;
  value0 = (v2start)->instance.slots[3]=v4end;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for MAKE-TAB                              */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L31make_tab(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 cl_object v1;
 cl_object v2;
 cl_object v3;
 cl_object v4;
 cl_object v5;
 ecl_va_list args; ecl_va_start(args,narg,narg,0);
 {
  cl_object keyvars[10];
  cl_parse_key(args,5,L31make_tabkeys,keyvars,NULL,FALSE);
  ecl_va_end(args);
  if (Null(keyvars[5])) {
   v1 = ecl_make_fixnum(0);
  } else {
   v1 = keyvars[0];
  }
  v2 = keyvars[1];
  v3 = keyvars[2];
  if (Null(keyvars[8])) {
   v4 = ecl_make_fixnum(0);
  } else {
   v4 = keyvars[3];
  }
  if (Null(keyvars[9])) {
   v5 = ecl_make_fixnum(0);
  } else {
   v5 = keyvars[4];
  }
 }
 if (!(ECL_FIXNUMP(v5))) { goto L7; }
 {
  cl_object v6;
  v6 = ecl_make_fixnum(0);
  if (!(ECL_FIXNUMP(v5)||ECL_BIGNUMP(v5))) { goto L11; }
  v6 = v5;
  if (ecl_number_compare(v6,ecl_make_fixnum(0))>=0) { goto L4; }
  goto L5;
L11:;
  goto L5;
 }
L7:;
 goto L5;
L5:;
 si_structure_type_error(4, v5, VV[0], VV[84], VV[87]);
L4:;
 if (!(ECL_FIXNUMP(v4))) { goto L18; }
 {
  cl_object v6;
  v6 = ecl_make_fixnum(0);
  if (!(ECL_FIXNUMP(v4)||ECL_BIGNUMP(v4))) { goto L22; }
  v6 = v4;
  if (ecl_number_compare(v6,ecl_make_fixnum(0))>=0) { goto L15; }
  goto L16;
L22:;
  goto L16;
 }
L18:;
 goto L16;
L16:;
 si_structure_type_error(4, v4, VV[0], VV[84], VV[88]);
L15:;
 if (!(ecl_eql(v3,ECL_T))) { goto L30; }
 goto L26;
 goto L28;
L30:;
 goto L28;
L28:;
 if (!((v3)==(ECL_NIL))) { goto L33; }
 goto L26;
 goto L27;
L33:;
 goto L27;
L27:;
 si_structure_type_error(4, v3, VV[91], VV[84], VV[92]);
L26:;
 if (!(ecl_eql(v2,ECL_T))) { goto L39; }
 goto L35;
 goto L37;
L39:;
 goto L37;
L37:;
 if (!((v2)==(ECL_NIL))) { goto L42; }
 goto L35;
 goto L36;
L42:;
 goto L36;
L36:;
 si_structure_type_error(4, v2, VV[91], VV[84], VV[93]);
L35:;
 if (ECL_FIXNUMP(v1)) { goto L44; }
 si_structure_type_error(4, v1, VV[1], VV[84], VV[1]);
L44:;
 value0 = si_make_structure(6, VV[94], v1, v2, v3, v4, v5);
 return value0;
}
/*	function definition for ENQUEUE-TAB                           */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L32enqueue_tab(cl_object v1stream, cl_object v2kind, cl_object v3colnum, cl_object v4colinc)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v6;                                   /*  SECTIONP        */
  cl_object v7;                                   /*  RELATIVEP       */
  if (!(ecl_eql(v2kind,ECL_SYM("LINE",1601)))) { goto L2; }
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = ECL_NIL;
  cl_env_copy->values[0] = ECL_NIL;
  value0 = cl_env_copy->values[0];
  goto L1;
L2:;
  if (!(ecl_eql(v2kind,VV[96]))) { goto L4; }
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = ECL_T;
  cl_env_copy->values[0] = ECL_NIL;
  value0 = cl_env_copy->values[0];
  goto L1;
L4:;
  if (!(ecl_eql(v2kind,VV[97]))) { goto L6; }
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = ECL_NIL;
  cl_env_copy->values[0] = ECL_T;
  value0 = cl_env_copy->values[0];
  goto L1;
L6:;
  if (!(ecl_eql(v2kind,VV[98]))) { goto L8; }
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = ECL_T;
  cl_env_copy->values[0] = ECL_T;
  value0 = cl_env_copy->values[0];
  goto L1;
L8:;
  value0 = si_ecase_error(v2kind, VV[99]);
L1:;
  v6 = value0;
  {
   const int v8 = cl_env_copy->nvalues;
   cl_object v9;
   v9 = (v8<=1)? ECL_NIL : cl_env_copy->values[1];
   v7 = v9;
  }
  {
   cl_object v8;
   {
    cl_object v9;
    v9 = (v1stream)->instance.slots[4];
    T1 = (v1stream)->instance.slots[5];
    T0 = ecl_plus(v9,T1);
   }
   v8 = L31make_tab(10, VV[54], T0, VV[100], v6, VV[101], v7, VV[102], v3colnum, VV[103], v4colinc);
   {
    cl_object v9;
    v9 = ecl_list1(v8);
    {
     cl_object v10;
     v10 = (v1stream)->instance.slots[12];
     if (Null(v10)) { goto L20; }
     (ECL_CONS_CDR(v10)=v9,v10);
     goto L19;
L20:;
     (v1stream)->instance.slots[11]=(v9);
L19:;
     (v1stream)->instance.slots[12]=(v9);
     value0 = v8;
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
  }
 }
}
/*	function definition for COMPUTE-TAB-SIZE                      */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L33compute_tab_size(cl_object v1tab, cl_object v2section_start, cl_object v3column)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v4;
  cl_object v5;
  cl_object v6colnum;
  v4 = ecl_function_dispatch(cl_env_copy,VV[229])(1, v1tab) /*  TAB-COLNUM */;
  v5 = ecl_function_dispatch(cl_env_copy,VV[230])(1, v1tab) /*  TAB-COLINC */;
  v6colnum = v4;
  if (Null(ecl_function_dispatch(cl_env_copy,VV[231])(1, v1tab) /*  TAB-SECTIONP */)) { goto L4; }
  v3column = ecl_minus(v3column,v2section_start);
L4:;
  if (Null(ecl_function_dispatch(cl_env_copy,VV[232])(1, v1tab) /*  TAB-RELATIVEP */)) { goto L7; }
  if (ecl_number_compare(v5,ecl_make_fixnum(1))<=0) { goto L9; }
  {
   cl_object v7newposn;
   v7newposn = ecl_plus(v3column,v6colnum);
   {
    cl_object v8rem;
    v8rem = (ecl_truncate2(v7newposn,v5),cl_env_copy->values[1]);
    if (ecl_zerop(v8rem)) { goto L9; }
    {
     cl_object v9;
     v9 = ecl_minus(v5,v8rem);
     v6colnum = ecl_plus(v6colnum,v9);
    }
   }
  }
L9:;
  value0 = v6colnum;
  cl_env_copy->nvalues = 1;
  return value0;
L7:;
  if (!(ecl_number_compare(v3column,v6colnum)<0)) { goto L16; }
  value0 = ecl_minus(v6colnum,v3column);
  cl_env_copy->nvalues = 1;
  return value0;
L16:;
  if (!(ecl_number_equalp(v3column,v6colnum))) { goto L18; }
  value0 = v5;
  cl_env_copy->nvalues = 1;
  return value0;
L18:;
  if (!(ecl_plusp(v5))) { goto L20; }
  T0 = ecl_minus(v3column,v6colnum);
  T1 = (ecl_truncate2(T0,v5),cl_env_copy->values[1]);
  value0 = ecl_minus(v5,T1);
  cl_env_copy->nvalues = 1;
  return value0;
L20:;
  value0 = ecl_make_fixnum(0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for INDEX-COLUMN                          */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L34index_column(cl_object v1index, cl_object v2stream)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v3;
  cl_object v4;
  cl_object v5;
  cl_object v6column;
  cl_object v7section_start;
  v3 = (v2stream)->instance.slots[6];
  T0 = (v2stream)->instance.slots[8];
  T1 = _ecl_car(T0);
  v4 = ecl_function_dispatch(cl_env_copy,VV[233])(1, T1) /*  LOGICAL-BLOCK-SECTION-COLUMN */;
  T0 = (v2stream)->instance.slots[5];
  v5 = ecl_plus(v1index,T0);
  v6column = v3;
  v7section_start = v4;
  {
   cl_object v8;
   v8 = (v2stream)->instance.slots[11];
   goto L16;
L15:;
   {
    cl_object v9op;
    v9op = _ecl_car(v8);
    T0 = ecl_function_dispatch(cl_env_copy,VV[234])(1, v9op) /*  QUEUED-OP-POSN */;
    if (!(ecl_number_compare(T0,v5)>=0)) { goto L20; }
    goto L11;
L20:;
    if (Null(si_of_class_p(2, v9op, VV[84]))) { goto L23; }
    {
     cl_object v10;
     {
      cl_object v11;
      v11 = ecl_function_dispatch(cl_env_copy,VV[235])(1, v9op) /*  TAB-POSN */;
      T1 = (v2stream)->instance.slots[5];
      T0 = ecl_minus(v11,T1);
     }
     T1 = ecl_plus(v6column,T0);
     v10 = L33compute_tab_size(v9op, v7section_start, T1);
     v6column = ecl_plus(v6column,v10);
     goto L22;
    }
L23:;
    if ((si_of_class_p(2, v9op, VV[40]))!=ECL_NIL) { goto L32; }
    if (Null(si_of_class_p(2, v9op, VV[69]))) { goto L22; }
    goto L31;
L32:;
L31:;
    {
     cl_object v11;
     v11 = ecl_function_dispatch(cl_env_copy,VV[234])(1, v9op) /*  QUEUED-OP-POSN */;
     T1 = (v2stream)->instance.slots[5];
     T0 = ecl_minus(v11,T1);
    }
    v7section_start = ecl_plus(v6column,T0);
L22:;
   }
   v8 = _ecl_cdr(v8);
L16:;
   if (Null(v8)) { goto L41; }
   goto L15;
L41:;
  }
L11:;
  value0 = ecl_plus(v6column,v1index);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for EXPAND-TABS                           */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L35expand_tabs(cl_object v1stream, cl_object v2through)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v3;
  cl_object v4;
  cl_object v5insertions;
  cl_object v6additional;
  cl_object v7column;
  cl_object v8section_start;
  v3 = (v1stream)->instance.slots[6];
  T0 = (v1stream)->instance.slots[8];
  T1 = _ecl_car(T0);
  v4 = ecl_function_dispatch(cl_env_copy,VV[233])(1, T1) /*  LOGICAL-BLOCK-SECTION-COLUMN */;
  v5insertions = ECL_NIL;
  v6additional = ecl_make_fixnum(0);
  v7column = v3;
  v8section_start = v4;
  {
   cl_object v9;
   v9 = (v1stream)->instance.slots[11];
   goto L15;
L14:;
   {
    cl_object v10op;
    v10op = _ecl_car(v9);
    if (Null(si_of_class_p(2, v10op, VV[84]))) { goto L20; }
    {
     cl_object v11index;
     cl_object v12tabsize;
     {
      cl_object v13;
      v13 = ecl_function_dispatch(cl_env_copy,VV[235])(1, v10op) /*  TAB-POSN */;
      T0 = (v1stream)->instance.slots[5];
      v11index = ecl_minus(v13,T0);
     }
     T0 = ecl_plus(v7column,v11index);
     v12tabsize = L33compute_tab_size(v10op, v8section_start, T0);
     if (ecl_zerop(v12tabsize)) { goto L19; }
     T0 = CONS(v11index,v12tabsize);
     v5insertions = CONS(T0,v5insertions);
     v6additional = ecl_plus(v6additional,v12tabsize);
     v7column = ecl_plus(v7column,v12tabsize);
     goto L19;
    }
L20:;
    if ((si_of_class_p(2, v10op, VV[40]))!=ECL_NIL) { goto L34; }
    if (Null(si_of_class_p(2, v10op, VV[69]))) { goto L19; }
    goto L33;
L34:;
L33:;
    {
     cl_object v13;
     v13 = ecl_function_dispatch(cl_env_copy,VV[234])(1, v10op) /*  QUEUED-OP-POSN */;
     T1 = (v1stream)->instance.slots[5];
     T0 = ecl_minus(v13,T1);
    }
    v8section_start = ecl_plus(v7column,T0);
L19:;
    if (!((v10op)==(v2through))) { goto L41; }
    goto L10;
L41:;
   }
   v9 = _ecl_cdr(v9);
L15:;
   if (Null(v9)) { goto L45; }
   goto L14;
L45:;
  }
L10:;
  if (Null(v5insertions)) { goto L47; }
  {
   cl_object v9fill_ptr;
   cl_object v10new_fill_ptr;
   cl_object v11buffer;
   cl_object v12new_buffer;
   cl_fixnum v13length;
   cl_object v14end;
   v9fill_ptr = (v1stream)->instance.slots[4];
   v10new_fill_ptr = ecl_plus(v9fill_ptr,v6additional);
   v11buffer = (v1stream)->instance.slots[3];
   v12new_buffer = v11buffer;
   v13length = ecl_length(v11buffer);
   v14end = v9fill_ptr;
   if (!(ecl_number_compare(v10new_fill_ptr,ecl_make_fixnum(v13length))>0)) { goto L57; }
   {
    cl_object v15new_length;
    T0 = ecl_times(ecl_make_fixnum(v13length),ecl_make_fixnum(2));
    T1 = ecl_times(v6additional,ecl_make_fixnum(5));
    T2 = ecl_floor2(T1,ecl_make_fixnum(4));
    T3 = ecl_plus(v9fill_ptr,T2);
    v15new_length = (ecl_number_compare(T0,T3)>=0?T0:T3);
    v12new_buffer = cl_make_string(1, v15new_length);
    (v1stream)->instance.slots[3]=(v12new_buffer);
   }
L57:;
   (v1stream)->instance.slots[4]=(v10new_fill_ptr);
   {
    cl_object v15;
    T0 = (v1stream)->instance.slots[5];
    v15 = ecl_minus(T0,v6additional);
    (v1stream)->instance.slots[5]=(v15);
   }
   {
    cl_object v15;
    v15 = v5insertions;
    goto L74;
L73:;
    {
     cl_object v16insertion;
     v16insertion = _ecl_car(v15);
     {
      cl_object v17srcpos;
      cl_object v18amount;
      cl_object v19dstpos;
      v17srcpos = _ecl_car(v16insertion);
      v18amount = _ecl_cdr(v16insertion);
      v19dstpos = ecl_plus(v17srcpos,v6additional);
      cl_replace(8, v12new_buffer, v11buffer, ECL_SYM("START1",1311), v19dstpos, ECL_SYM("START2",1312), v17srcpos, ECL_SYM("END2",1227), v14end);
      T0 = ecl_minus(v19dstpos,v18amount);
      cl_fill(6, v12new_buffer, CODE_CHAR(32), ECL_SYM("START",1310), T0, ECL_SYM("END",1225), v19dstpos);
      v6additional = ecl_minus(v6additional,v18amount);
      v14end = v17srcpos;
     }
    }
    v15 = _ecl_cdr(v15);
L74:;
    if (Null(v15)) { goto L89; }
    goto L73;
L89:;
   }
   if ((v12new_buffer)==(v11buffer)) { goto L91; }
   value0 = cl_replace(6, v12new_buffer, v11buffer, ECL_SYM("END1",1226), v14end, ECL_SYM("END2",1227), v14end);
   return value0;
L91:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L47:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for ASSURE-SPACE-IN-BUFFER                */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L36assure_space_in_buffer(cl_object v1stream, cl_object v2want)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 cl_fixnum v3want;
 v3want = ecl_fixnum(v2want);
TTL:
 {
  cl_object v4buffer;
  cl_fixnum v5length;
  cl_object v6fill_ptr;
  cl_object v7available;
  v4buffer = (v1stream)->instance.slots[3];
  v5length = ecl_length(v4buffer);
  v6fill_ptr = (v1stream)->instance.slots[4];
  v7available = ecl_minus(ecl_make_fixnum(v5length),v6fill_ptr);
  if (!(ecl_plusp(v7available))) { goto L7; }
  value0 = v7available;
  cl_env_copy->nvalues = 1;
  return value0;
L7:;
  T0 = (v1stream)->instance.slots[2];
  if (!(ecl_number_compare(v6fill_ptr,T0)>0)) { goto L9; }
  if ((L37maybe_output(v1stream, ECL_NIL))!=ECL_NIL) { goto L13; }
  L41output_partial_line(v1stream);
L13:;
  goto TTL;
L9:;
  {
   cl_object v8new_length;
   cl_object v9new_buffer;
   T0 = ecl_times(ecl_make_fixnum(v5length),ecl_make_fixnum(2));
   T1 = ecl_times(ecl_make_fixnum(v3want),ecl_make_fixnum(5));
   T2 = ecl_floor2(T1,ecl_make_fixnum(4));
   T3 = ecl_plus(ecl_make_fixnum(v5length),T2);
   v8new_length = (ecl_number_compare(T0,T3)>=0?T0:T3);
   v9new_buffer = cl_make_string(1, v8new_length);
   (v1stream)->instance.slots[3]=(v9new_buffer);
   cl_replace(4, v9new_buffer, v4buffer, ECL_SYM("END1",1226), v6fill_ptr);
   value0 = ecl_minus(v8new_length,v6fill_ptr);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for MAYBE-OUTPUT                          */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L37maybe_output(cl_object v1stream, cl_object v2force_newlines_p)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v3;
  cl_object v4tail;
  cl_object v5output_anything;
  v3 = (v1stream)->instance.slots[11];
  v4tail = v3;
  v5output_anything = ECL_NIL;
L6:;
  if ((v4tail)!=ECL_NIL) { goto L8; }
  (v1stream)->instance.slots[12]=(ECL_NIL);
  goto L5;
L8:;
  {
   cl_object v6next;
   {
    cl_object v7;
    v7 = v4tail;
    if (Null(v7)) { goto L16; }
    {
     cl_object v8;
     v8 = ECL_CONS_CDR(v7);
     v4tail = v8;
     v7 = ECL_CONS_CAR(v7);
    }
L16:;
    v6next = v7;
   }
   if (Null(si_of_class_p(2, v6next, VV[40]))) { goto L22; }
   {
    cl_object v7;
    v7 = ecl_function_dispatch(cl_env_copy,VV[236])(1, v6next) /*  NEWLINE-KIND */;
    if (!(ecl_eql(v7,VV[13]))) { goto L31; }
    goto L28;
    goto L29;
L31:;
    goto L29;
L29:;
    if (!(ecl_eql(v7,VV[57]))) { goto L35; }
    goto L28;
    goto L33;
L35:;
    goto L33;
L33:;
    if (!(ecl_eql(v7,VV[106]))) { goto L26; }
    goto L27;
L28:;
L27:;
    goto L24;
L26:;
    if (!(ecl_eql(v7,VV[108]))) { goto L38; }
    if (Null(L38misering_p(v1stream))) { goto L12; }
    goto L24;
L38:;
    if (!(ecl_eql(v7,VV[109]))) { goto L40; }
    if ((L38misering_p(v1stream))!=ECL_NIL) { goto L42; }
    T0 = (v1stream)->instance.slots[7];
    T1 = (v1stream)->instance.slots[8];
    T2 = _ecl_car(T1);
    T3 = ecl_function_dispatch(cl_env_copy,VV[237])(1, T2) /*  LOGICAL-BLOCK-SECTION-START-LINE */;
    if (ecl_number_compare(T0,T3)>0) { goto L42; }
    {
     cl_object v8;
     T0 = ecl_function_dispatch(cl_env_copy,VV[238])(1, v6next) /*  NEWLINE-SECTION-END */;
     v8 = L39fits_on_line_p(v1stream, T0, v2force_newlines_p);
     if (!(ecl_eql(v8,ECL_T))) { goto L50; }
     goto L12;
L50:;
     if (!((v8)==(ECL_NIL))) { goto L53; }
     goto L24;
L53:;
     if (!(ecl_eql(v8,VV[111]))) { goto L56; }
     goto L5;
L56:;
     if (Null(si_ecase_error(v8, VV[112]))) { goto L12; }
     goto L24;
    }
L42:;
    goto L24;
L40:;
    if (Null(si_ecase_error(v7, VV[113]))) { goto L12; }
   }
L24:;
   v5output_anything = ECL_T;
   L40output_line(v1stream, v6next);
   goto L12;
L22:;
   if (Null(si_of_class_p(2, v6next, VV[58]))) { goto L60; }
   if ((L38misering_p(v1stream))!=ECL_NIL) { goto L12; }
   {
    cl_object v7;
    v7 = ecl_function_dispatch(cl_env_copy,VV[239])(1, v6next) /*  INDENTATION-KIND */;
    if (!(ecl_eql(v7,ECL_SYM("BLOCK",1202)))) { goto L65; }
    T1 = (v1stream)->instance.slots[8];
    T2 = _ecl_car(T1);
    T0 = ecl_function_dispatch(cl_env_copy,VV[240])(1, T2) /*  LOGICAL-BLOCK-START-COLUMN */;
    goto L63;
L65:;
    if (!(ecl_eql(v7,VV[63]))) { goto L69; }
    {
     cl_object v8;
     v8 = ecl_function_dispatch(cl_env_copy,VV[241])(1, v6next) /*  INDENTATION-POSN */;
     T2 = (v1stream)->instance.slots[5];
     T1 = ecl_minus(v8,T2);
     T0 = L34index_column(T1, v1stream);
     goto L63;
    }
L69:;
    T0 = si_ecase_error(v7, VV[62]);
   }
L63:;
   T1 = ecl_function_dispatch(cl_env_copy,VV[242])(1, v6next) /*  INDENTATION-AMOUNT */;
   T2 = ecl_plus(T0,T1);
   L19set_indentation(v1stream, T2);
   goto L12;
L60:;
   if (Null(si_of_class_p(2, v6next, VV[69]))) { goto L75; }
   {
    cl_object v7;
    T0 = ecl_function_dispatch(cl_env_copy,VV[243])(1, v6next) /*  BLOCK-START-SECTION-END */;
    v7 = L39fits_on_line_p(v1stream, T0, v2force_newlines_p);
    if (!(ecl_eql(v7,ECL_T))) { goto L78; }
    {
     cl_object v8end;
     v8end = ecl_function_dispatch(cl_env_copy,VV[244])(1, v6next) /*  BLOCK-START-BLOCK-END */;
     L35expand_tabs(v1stream, v8end);
     T0 = ecl_memql(v8end,v4tail);
     v4tail = _ecl_cdr(T0);
     goto L12;
    }
L78:;
    if (!((v7)==(ECL_NIL))) { goto L85; }
    {
     cl_object v9;
     v9 = ecl_function_dispatch(cl_env_copy,VV[245])(1, v6next) /*  BLOCK-START-POSN */;
     T2 = (v1stream)->instance.slots[5];
     T1 = ecl_minus(v9,T2);
     T0 = L34index_column(T1, v1stream);
    }
    T1 = ecl_function_dispatch(cl_env_copy,VV[246])(1, v6next) /*  BLOCK-START-PREFIX */;
    T2 = ecl_function_dispatch(cl_env_copy,VV[222])(1, v6next) /*  BLOCK-START-SUFFIX */;
    L18really_start_logical_block(v1stream, T0, T1, T2);
    goto L12;
L85:;
    if (!(ecl_eql(v7,VV[111]))) { goto L93; }
    goto L5;
L93:;
    si_ecase_error(v7, VV[112]);
    goto L12;
   }
L75:;
   if (Null(si_of_class_p(2, v6next, VV[41]))) { goto L95; }
   L20really_end_logical_block(v1stream);
   goto L12;
L95:;
   if (Null(si_of_class_p(2, v6next, VV[84]))) { goto L97; }
   L35expand_tabs(v1stream, v6next);
   goto L12;
L97:;
   si_etypecase_error(v6next, VV[114]);
  }
L12:;
  (v1stream)->instance.slots[11]=(v4tail);
  goto L6;
L5:;
  value0 = v5output_anything;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for MISERING-P                            */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L38misering_p(cl_object v1stream)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 if (Null(ECL_SYM_VAL(cl_env_copy,ECL_SYM("*PRINT-MISER-WIDTH*",53)))) { goto L2; }
 T0 = (v1stream)->instance.slots[2];
 T1 = (v1stream)->instance.slots[8];
 T2 = _ecl_car(T1);
 T3 = ecl_function_dispatch(cl_env_copy,VV[240])(1, T2) /*  LOGICAL-BLOCK-START-COLUMN */;
 T4 = ecl_minus(T0,T3);
 value0 = ecl_make_bool(ecl_number_compare(T4,ECL_SYM_VAL(cl_env_copy,ECL_SYM("*PRINT-MISER-WIDTH*",53)))<=0);
 cl_env_copy->nvalues = 1;
 return value0;
L2:;
 value0 = ECL_NIL;
 cl_env_copy->nvalues = 1;
 return value0;
}
/*	function definition for FITS-ON-LINE-P                        */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L39fits_on_line_p(cl_object v1stream, cl_object v2until, cl_object v3force_newlines_p)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v4available;
  v4available = (v1stream)->instance.slots[2];
  if ((ECL_SYM_VAL(cl_env_copy,ECL_SYM("*PRINT-READABLY*",57)))!=ECL_NIL) { goto L3; }
  if (Null(ECL_SYM_VAL(cl_env_copy,ECL_SYM("*PRINT-LINES*",52)))) { goto L3; }
  T0 = (v1stream)->instance.slots[7];
  if (!(ecl_number_equalp(ECL_SYM_VAL(cl_env_copy,ECL_SYM("*PRINT-LINES*",52)),T0))) { goto L3; }
  v4available = ecl_minus(v4available,ecl_make_fixnum(3));
  {
   cl_object v5;
   T0 = (v1stream)->instance.slots[8];
   T1 = _ecl_car(T0);
   v5 = ecl_function_dispatch(cl_env_copy,VV[194])(1, T1) /*  LOGICAL-BLOCK-SUFFIX-LENGTH */;
   v4available = ecl_minus(v4available,v5);
  }
L3:;
  if (Null(v2until)) { goto L15; }
  {
   cl_object v5;
   v5 = ecl_function_dispatch(cl_env_copy,VV[234])(1, v2until) /*  QUEUED-OP-POSN */;
   T2 = (v1stream)->instance.slots[5];
   T1 = ecl_minus(v5,T2);
   T0 = L34index_column(T1, v1stream);
  }
  value0 = ecl_make_bool(ecl_number_compare(T0,v4available)<=0);
  cl_env_copy->nvalues = 1;
  return value0;
L15:;
  if (Null(v3force_newlines_p)) { goto L22; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L22:;
  T0 = (v1stream)->instance.slots[4];
  T1 = L34index_column(T0, v1stream);
  if (!(ecl_number_compare(T1,v4available)>0)) { goto L24; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L24:;
  value0 = VV[111];
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for OUTPUT-LINE                           */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L40output_line(cl_object v1stream, cl_object v2until)
{
 cl_object T0, T1, T2, T3, T4, T5;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v3target;
  cl_object v4buffer;
  cl_object v5kind;
  cl_object v6literal_p;
  cl_object v7amount_to_consume;
  cl_object v8amount_to_print;
  v3target = (v1stream)->instance.slots[1];
  v4buffer = (v1stream)->instance.slots[3];
  v5kind = ecl_function_dispatch(cl_env_copy,VV[236])(1, v2until) /*  NEWLINE-KIND */;
  v6literal_p = ecl_make_bool((v5kind)==(VV[13]));
  {
   cl_object v9;
   v9 = ecl_function_dispatch(cl_env_copy,VV[247])(1, v2until) /*  NEWLINE-POSN */;
   T0 = (v1stream)->instance.slots[5];
   v7amount_to_consume = ecl_minus(v9,T0);
  }
  if (Null(v6literal_p)) { goto L12; }
  v8amount_to_print = v7amount_to_consume;
  goto L11;
L12:;
  {
   cl_object v9last_non_blank;
   T0 = (ECL_SYM("CHAR/=",216)->symbol.gfdef);
   v9last_non_blank = cl_position(8, CODE_CHAR(32), v4buffer, ECL_SYM("END",1225), v7amount_to_consume, VV[115], ECL_T, ECL_SYM("TEST",1316), T0);
   if (Null(v9last_non_blank)) { goto L16; }
   v8amount_to_print = ecl_make_integer((ecl_fixnum(v9last_non_blank))+1);
   goto L11;
L16:;
   v8amount_to_print = ecl_make_fixnum(0);
  }
L11:;
  cl_write_string(4, v4buffer, v3target, ECL_SYM("END",1225), v8amount_to_print);
  {
   cl_object v9line_number;
   v9line_number = (v1stream)->instance.slots[7];
   v9line_number = ecl_plus(v9line_number,ecl_make_fixnum(1));
   if ((ECL_SYM_VAL(cl_env_copy,ECL_SYM("*PRINT-READABLY*",57)))!=ECL_NIL) { goto L23; }
   if (Null(ECL_SYM_VAL(cl_env_copy,ECL_SYM("*PRINT-LINES*",52)))) { goto L23; }
   if (!(ecl_number_compare(v9line_number,ECL_SYM_VAL(cl_env_copy,ECL_SYM("*PRINT-LINES*",52)))>=0)) { goto L23; }
   cl_write_string(2, _ecl_static_9, v3target);
   {
    cl_object v10suffix_length;
    T0 = (v1stream)->instance.slots[8];
    T1 = _ecl_car(T0);
    v10suffix_length = ecl_function_dispatch(cl_env_copy,VV[194])(1, T1) /*  LOGICAL-BLOCK-SUFFIX-LENGTH */;
    if (ecl_zerop(v10suffix_length)) { goto L28; }
    {
     cl_object v11suffix;
     cl_fixnum v12len;
     v11suffix = (v1stream)->instance.slots[10];
     v12len = ecl_length(v11suffix);
     T0 = ecl_minus(ecl_make_fixnum(v12len),v10suffix_length);
     cl_write_string(6, v11suffix, v3target, ECL_SYM("START",1310), T0, ECL_SYM("END",1225), ecl_make_fixnum(v12len));
    }
   }
L28:;
   cl_env_copy->values[0] = ECL_T;
   cl_env_copy->nvalues = 1;
   cl_throw(VV[116]);
L23:;
   (v1stream)->instance.slots[7]=(v9line_number);
   cl_write_char(2, CODE_CHAR(10), v3target);
   (v1stream)->instance.slots[6]=(ecl_make_fixnum(0));
   {
    cl_object v10fill_ptr;
    cl_object v11block;
    cl_object v12prefix_len;
    cl_object v13shift;
    cl_object v14new_fill_ptr;
    cl_object v15new_buffer;
    cl_fixnum v16buffer_length;
    v10fill_ptr = (v1stream)->instance.slots[4];
    T0 = (v1stream)->instance.slots[8];
    v11block = _ecl_car(T0);
    if (Null(v6literal_p)) { goto L48; }
    v12prefix_len = ecl_function_dispatch(cl_env_copy,VV[192])(1, v11block) /*  LOGICAL-BLOCK-PER-LINE-PREFIX-END */;
    goto L47;
L48:;
    v12prefix_len = ecl_function_dispatch(cl_env_copy,VV[193])(1, v11block) /*  LOGICAL-BLOCK-PREFIX-LENGTH */;
L47:;
    v13shift = ecl_minus(v7amount_to_consume,v12prefix_len);
    v14new_fill_ptr = ecl_minus(v10fill_ptr,v13shift);
    v15new_buffer = v4buffer;
    v16buffer_length = ecl_length(v4buffer);
    if (!(ecl_number_compare(v14new_fill_ptr,ecl_make_fixnum(v16buffer_length))>0)) { goto L54; }
    T0 = ecl_times(ecl_make_fixnum(v16buffer_length),ecl_make_fixnum(2));
    T1 = ecl_minus(v14new_fill_ptr,ecl_make_fixnum(v16buffer_length));
    T2 = ecl_times(T1,ecl_make_fixnum(5));
    T3 = ecl_floor2(T2,ecl_make_fixnum(4));
    T4 = ecl_plus(ecl_make_fixnum(v16buffer_length),T3);
    T5 = (ecl_number_compare(T0,T4)>=0?T0:T4);
    v15new_buffer = cl_make_string(1, T5);
    (v1stream)->instance.slots[3]=(v15new_buffer);
L54:;
    cl_replace(8, v15new_buffer, v4buffer, ECL_SYM("START1",1311), v12prefix_len, ECL_SYM("START2",1312), v7amount_to_consume, ECL_SYM("END2",1227), v10fill_ptr);
    T0 = (v1stream)->instance.slots[9];
    cl_replace(4, v15new_buffer, T0, ECL_SYM("END1",1226), v12prefix_len);
    (v1stream)->instance.slots[4]=(v14new_fill_ptr);
    {
     cl_object v17;
     T0 = (v1stream)->instance.slots[5];
     v17 = ecl_plus(T0,v13shift);
     (v1stream)->instance.slots[5]=(v17);
    }
    if ((v6literal_p)!=ECL_NIL) { goto L70; }
    (v11block)->instance.slots[1]=v12prefix_len;
    value0 = (v11block)->instance.slots[5]=v9line_number;
    cl_env_copy->nvalues = 1;
    return value0;
L70:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for OUTPUT-PARTIAL-LINE                   */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L41output_partial_line(cl_object v1stream)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v2fill_ptr;
  cl_object v3tail;
  cl_object v4count;
  cl_object v5new_fill_ptr;
  cl_object v6buffer;
  v2fill_ptr = (v1stream)->instance.slots[4];
  v3tail = (v1stream)->instance.slots[11];
  if (Null(v3tail)) { goto L6; }
  {
   cl_object v7;
   T0 = _ecl_car(v3tail);
   v7 = ecl_function_dispatch(cl_env_copy,VV[234])(1, T0) /*  QUEUED-OP-POSN */;
   T0 = (v1stream)->instance.slots[5];
   v4count = ecl_minus(v7,T0);
   goto L5;
  }
L6:;
  v4count = v2fill_ptr;
L5:;
  v5new_fill_ptr = ecl_minus(v2fill_ptr,v4count);
  v6buffer = (v1stream)->instance.slots[3];
  if (!(ecl_zerop(v4count))) { goto L14; }
  cl_error(1, _ecl_static_10);
L14:;
  T0 = (v1stream)->instance.slots[1];
  cl_write_string(6, v6buffer, T0, ECL_SYM("START",1310), ecl_make_fixnum(0), ECL_SYM("END",1225), v4count);
  {
   cl_object v7;
   T0 = (v1stream)->instance.slots[6];
   v7 = ecl_plus(T0,v4count);
   (v1stream)->instance.slots[6]=(v7);
  }
  cl_replace(8, v6buffer, v6buffer, ECL_SYM("END1",1226), v5new_fill_ptr, ECL_SYM("START2",1312), v4count, ECL_SYM("END2",1227), v2fill_ptr);
  (v1stream)->instance.slots[4]=(v5new_fill_ptr);
  {
   cl_object v7;
   T0 = (v1stream)->instance.slots[5];
   v7 = ecl_plus(T0,v4count);
   value0 = (v1stream)->instance.slots[5]=(v7);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for FORCE-PRETTY-OUTPUT                   */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L42force_pretty_output(cl_object v1stream)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 L37maybe_output(v1stream, ECL_NIL);
 L35expand_tabs(v1stream, ECL_NIL);
 T0 = (v1stream)->instance.slots[3];
 T1 = (v1stream)->instance.slots[1];
 T2 = (v1stream)->instance.slots[4];
 value0 = cl_write_string(4, T0, T1, ECL_SYM("END",1225), T2);
 return value0;
}
/*	function definition for PPRINT-POP-HELPER                     */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
cl_object si_pprint_pop_helper(cl_narg narg, cl_object v1object, cl_object v2count, cl_object v3stream, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v4code;
  v4code = ECL_NIL;
  if (ECL_LISTP(v1object)) { goto L2; }
  cl_write_string(2, _ecl_static_11, v3stream);
  si_write_object(v1object, v3stream);
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  if ((ECL_SYM_VAL(cl_env_copy,ECL_SYM("*PRINT-READABLY*",57)))!=ECL_NIL) { goto L6; }
  if (!(ecl_eql(v2count,ECL_SYM_VAL(cl_env_copy,ECL_SYM("*PRINT-LENGTH*",50))))) { goto L6; }
  cl_write_string(2, _ecl_static_12, v3stream);
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L6:;
  if (v1object==ECL_NIL) { goto L12; }
  if (ecl_zerop(v2count)) { goto L12; }
  if (ECL_FIXNUMP(v1object)) { goto L12; }
  if (ECL_CHARACTERP(v1object)) { goto L12; }
  if (!(ECL_SYMBOLP(v1object))) { goto L19; }
  if ((cl_symbol_package(v1object))!=ECL_NIL) { goto L12; }
  goto L17;
L19:;
  goto L17;
L17:;
  if (!(ECL_SYM_VAL(cl_env_copy,ECL_SYM("*CIRCLE-COUNTER*",1014))==ECL_NIL)) { goto L10; }
  goto L11;
L12:;
L11:;
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
L10:;
  v4code = ecl_gethash_safe(v1object,ECL_SYM_VAL(cl_env_copy,ECL_SYM("*CIRCLE-STACK*",1015)),ECL_SYM("NULL",605));
  if (!((ECL_SYM("NULL",605))==(v4code))) { goto L21; }
  L44search_print_circle(v1object);
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
L21:;
  if (!(v4code==ECL_NIL)) { goto L25; }
  if (!(ECL_FIXNUMP(ECL_SYM_VAL(cl_env_copy,ECL_SYM("*CIRCLE-COUNTER*",1014)))||ECL_BIGNUMP(ECL_SYM_VAL(cl_env_copy,ECL_SYM("*CIRCLE-COUNTER*",1014))))) { goto L25; }
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
L25:;
  cl_write_string(2, _ecl_static_11, v3stream);
  si_write_object(v1object, v3stream);
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for CHECK-PRINT-LEVEL                     */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L43check_print_level()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 if ((ECL_SYM_VAL(cl_env_copy,ECL_SYM("*PRINT-READABLY*",57)))!=ECL_NIL) { goto L3; }
 if (!(ECL_SYM_VAL(cl_env_copy,ECL_SYM("*PRINT-LEVEL*",51))==ECL_NIL)) { goto L1; }
 goto L2;
L3:;
L2:;
 value0 = ECL_T;
 cl_env_copy->nvalues = 1;
 return value0;
L1:;
 if (!(ecl_zerop(ECL_SYM_VAL(cl_env_copy,ECL_SYM("*PRINT-LEVEL*",51))))) { goto L5; }
 value0 = ECL_NIL;
 cl_env_copy->nvalues = 1;
 return value0;
L5:;
 ECL_SETQ(cl_env_copy,ECL_SYM("*PRINT-LEVEL*",51),ecl_one_minus(ECL_SYM_VAL(cl_env_copy,ECL_SYM("*PRINT-LEVEL*",51))));
 value0 = ECL_SYM_VAL(cl_env_copy,ECL_SYM("*PRINT-LEVEL*",51));
 cl_env_copy->nvalues = 1;
 return value0;
}
/*	function definition for SEARCH-PRINT-CIRCLE                   */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L44search_print_circle(cl_object v1object)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v2code;
  v2code = ecl_gethash_safe(v1object,ECL_SYM_VAL(cl_env_copy,ECL_SYM("*CIRCLE-STACK*",1015)),ecl_make_fixnum(-1));
  if (!(ECL_FIXNUMP(ECL_SYM_VAL(cl_env_copy,ECL_SYM("*CIRCLE-COUNTER*",1014))))) { goto L2; }
  if ((v2code)==(ecl_make_fixnum(-1))) { goto L6; }
  if (!(v2code==ECL_NIL)) { goto L4; }
  goto L5;
L6:;
L5:;
  value0 = ecl_make_fixnum(0);
  cl_env_copy->nvalues = 1;
  return value0;
L4:;
  if (!(ecl_eql(v2code,ECL_T))) { goto L8; }
  ECL_SETQ(cl_env_copy,ECL_SYM("*CIRCLE-COUNTER*",1014),ecl_one_plus(ECL_SYM_VAL(cl_env_copy,ECL_SYM("*CIRCLE-COUNTER*",1014))));
  si_hash_set(v1object, ECL_SYM_VAL(cl_env_copy,ECL_SYM("*CIRCLE-STACK*",1015)), ECL_SYM_VAL(cl_env_copy,ECL_SYM("*CIRCLE-COUNTER*",1014)));
  value0 = ecl_negate(ECL_SYM_VAL(cl_env_copy,ECL_SYM("*CIRCLE-COUNTER*",1014)));
  cl_env_copy->nvalues = 1;
  return value0;
L8:;
  value0 = v2code;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  if (!((v2code)==(ecl_make_fixnum(-1)))) { goto L12; }
  si_hash_set(v1object, ECL_SYM_VAL(cl_env_copy,ECL_SYM("*CIRCLE-STACK*",1015)), ECL_NIL);
  value0 = ecl_make_fixnum(0);
  cl_env_copy->nvalues = 1;
  return value0;
L12:;
  if (!(v2code==ECL_NIL)) { goto L15; }
  si_hash_set(v1object, ECL_SYM_VAL(cl_env_copy,ECL_SYM("*CIRCLE-STACK*",1015)), ECL_T);
  value0 = ecl_make_fixnum(1);
  cl_env_copy->nvalues = 1;
  return value0;
L15:;
  value0 = ecl_make_fixnum(2);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for DO-PPRINT-LOGICAL-BLOCK               */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L45do_pprint_logical_block(cl_object v1function, cl_object v2object, cl_object v3stream, cl_object v4prefix, cl_object v5per_line_prefix_p, cl_object v6suffix)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 if (ECL_LISTP(v2object)) { goto L1; }
 si_write_object(v2object, v3stream);
 value0 = ECL_NIL;
 cl_env_copy->nvalues = 1;
 return value0;
L1:;
 if ((ECL_SYM_VAL(cl_env_copy,ECL_SYM("*PRINT-READABLY*",57)))!=ECL_NIL) { goto L4; }
 if (!((ECL_SYM_VAL(cl_env_copy,ECL_SYM("*PRINT-LEVEL*",51)))==(ecl_make_fixnum(0)))) { goto L4; }
 cl_write_char(2, CODE_CHAR(35), v3stream);
 value0 = ECL_NIL;
 cl_env_copy->nvalues = 1;
 return value0;
L4:;
 if (Null(ECL_SYM_VAL(cl_env_copy,ECL_SYM("*PRINT-CIRCLE*",47)))) { goto L8; }
 if (ECL_FIXNUMP(v2object)) { goto L8; }
 if (ECL_CHARACTERP(v2object)) { goto L8; }
 if (!(ECL_SYMBOLP(v2object))) { goto L14; }
 if ((cl_symbol_package(v2object))!=ECL_NIL) { goto L8; }
 goto L9;
L14:;
 goto L9;
L9:;
 {
  cl_object v7code;
  v7code = ECL_NIL;
  if ((ECL_SYM_VAL(cl_env_copy,ECL_SYM("*CIRCLE-COUNTER*",1014)))!=ECL_NIL) { goto L17; }
  {
   cl_object v8hash;
   v8hash = cl_make_hash_table(8, ECL_SYM("TEST",1316), ECL_SYM("EQ",333), ECL_SYM("SIZE",1308), ecl_make_fixnum(1024), ECL_SYM("REHASH-SIZE",1297), _ecl_static_13, ECL_SYM("REHASH-THRESHOLD",1298), _ecl_static_14);
   ecl_bds_bind(cl_env_copy,ECL_SYM("*CIRCLE-COUNTER*",1014),ECL_T); /*  *CIRCLE-COUNTER* */
   ecl_bds_bind(cl_env_copy,ECL_SYM("*CIRCLE-STACK*",1015),v8hash); /*  *CIRCLE-STACK* */
   T0 = cl_make_broadcast_stream(0);
   T1 = L7make_pretty_stream(T0);
   L45do_pprint_logical_block(v1function, v2object, T1, v4prefix, v5per_line_prefix_p, v6suffix);
   ECL_SETQ(cl_env_copy,ECL_SYM("*CIRCLE-COUNTER*",1014),ecl_make_fixnum(0));
   L45do_pprint_logical_block(v1function, v2object, v3stream, v4prefix, v5per_line_prefix_p, v6suffix);
   ecl_bds_unwind1(cl_env_copy);
   ecl_bds_unwind1(cl_env_copy);
  }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L17:;
  {
   cl_object v8;
   v7code = L44search_print_circle(v2object);
   v8 = ecl_make_bool(ecl_zerop(v7code));
   if (Null(v8)) { goto L26; }
   goto L8;
L26:;
   if (!(ecl_minusp(v7code))) { goto L28; }
   cl_write_string(2, _ecl_static_15, v3stream);
   ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-RADIX*",56),ECL_NIL); /*  *PRINT-RADIX* */
   ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-BASE*",45),ecl_make_fixnum(10)); /*  *PRINT-BASE* */
   T0 = ecl_negate(v7code);
   si_write_ugly_object(T0, v3stream);
   ecl_bds_unwind1(cl_env_copy);
   ecl_bds_unwind1(cl_env_copy);
   cl_write_string(2, _ecl_static_16, v3stream);
   goto L8;
L28:;
   cl_write_string(2, _ecl_static_15, v3stream);
   ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-RADIX*",56),ECL_NIL); /*  *PRINT-RADIX* */
   ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-BASE*",45),ecl_make_fixnum(10)); /*  *PRINT-BASE* */
   si_write_ugly_object(v7code, v3stream);
   ecl_bds_unwind1(cl_env_copy);
   ecl_bds_unwind1(cl_env_copy);
   cl_write_string(2, _ecl_static_15, v3stream);
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
L8:;
 if ((ECL_SYM_VAL(cl_env_copy,ECL_SYM("*PRINT-READABLY*",57)))!=ECL_NIL) { goto L38; }
 if (Null(ECL_SYM_VAL(cl_env_copy,ECL_SYM("*PRINT-LEVEL*",51)))) { goto L38; }
 T0 = ecl_one_minus(ECL_SYM_VAL(cl_env_copy,ECL_SYM("*PRINT-LEVEL*",51)));
 goto L36;
L38:;
 T0 = ECL_NIL;
 goto L36;
L36:;
 ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-LEVEL*",51),T0); /*  *PRINT-LEVEL* */
 L28start_logical_block(v3stream, v4prefix, v5per_line_prefix_p, v6suffix);
 ecl_function_dispatch(cl_env_copy,v1function)(2, v2object, v3stream);
 L30end_logical_block(v3stream);
 ecl_bds_unwind1(cl_env_copy);
 value0 = ECL_NIL;
 cl_env_copy->nvalues = 1;
 return value0;
}
/*	function definition for PPRINT-LOGICAL-BLOCK-HELPER           */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
cl_object si_pprint_logical_block_helper(volatile cl_narg narg, cl_object volatile v1function, cl_object volatile v2object, cl_object volatile v3stream, cl_object volatile v4prefix, cl_object volatile v5per_line_prefix_p, cl_object volatile v6suffix, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
TTL:
 if (!((v3stream)==(ECL_NIL))) { goto L3; }
 v3stream = ECL_SYM_VAL(cl_env_copy,ECL_SYM("*STANDARD-OUTPUT*",67));
 goto L2;
L3:;
 if (!(ecl_eql(v3stream,ECL_T))) { goto L6; }
 v3stream = ECL_SYM_VAL(cl_env_copy,ECL_SYM("*TERMINAL-IO*",68));
 goto L2;
L6:;
L2:;
 if (Null(L6pretty_stream_p(v3stream))) { goto L9; }
 value0 = L45do_pprint_logical_block(v1function, v2object, v3stream, v4prefix, v5per_line_prefix_p, v6suffix);
 return value0;
L9:;
 {
  volatile cl_object v7stream;
  v7stream = L7make_pretty_stream(v3stream);
  value0 = VV[116];
  if (ecl_frs_push(cl_env_copy,value0)==0) {      /*  BEGIN CATCH 13  */
   L45do_pprint_logical_block(v1function, v2object, v7stream, v4prefix, v5per_line_prefix_p, v6suffix);
   L42force_pretty_output(v7stream);
  }
  ecl_frs_pop(cl_env_copy);                       /*  END CATCH 13    */
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function PPRINT-LOGICAL-BLOCK                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC46pprint_logical_block(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6stream_symbol;
   cl_object v7object;
   cl_object v8;
   cl_object v9prefix;
   cl_object v10prefix_p;
   cl_object v11;
   cl_object v12per_line_prefix;
   cl_object v13per_line_prefix_p;
   cl_object v14;
   cl_object v15suffix;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v16;
    v16 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4 = v16;
   }
   v5 = v4;
   if (!(v5==ECL_NIL)) { goto L10; }
   si_dm_too_few_arguments(v1);
L10:;
   {
    cl_object v16;
    v16 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v6stream_symbol = v16;
   }
   if (!(v5==ECL_NIL)) { goto L16; }
   si_dm_too_few_arguments(v1);
L16:;
   {
    cl_object v16;
    v16 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v7object = v16;
   }
   v8 = si_search_keyword(2, v5, VV[78]);
   if (!((v8)==(ECL_SYM("MISSING-KEYWORD",1929)))) { goto L23; }
   v9prefix = _ecl_static_17;
   goto L22;
L23:;
   v9prefix = v8;
L22:;
   {
    bool v16;
    v16 = (v8)==(ECL_SYM("MISSING-KEYWORD",1929));
    v10prefix_p = (v16)?ECL_NIL:ECL_T;
   }
   v11 = si_search_keyword(2, v5, VV[119]);
   if (!((v11)==(ECL_SYM("MISSING-KEYWORD",1929)))) { goto L28; }
   v12per_line_prefix = _ecl_static_17;
   goto L27;
L28:;
   v12per_line_prefix = v11;
L27:;
   {
    bool v16;
    v16 = (v11)==(ECL_SYM("MISSING-KEYWORD",1929));
    v13per_line_prefix_p = (v16)?ECL_NIL:ECL_T;
   }
   v14 = si_search_keyword(2, v5, VV[79]);
   if (!((v14)==(ECL_SYM("MISSING-KEYWORD",1929)))) { goto L33; }
   v15suffix = _ecl_static_17;
   goto L32;
L33:;
   v15suffix = v14;
L32:;
   si_check_keyword(2, v5, VV[120]);
   if (Null(v13per_line_prefix_p)) { goto L36; }
   if (Null(v10prefix_p)) { goto L38; }
   cl_error(1, _ecl_static_18);
L38:;
   v9prefix = v12per_line_prefix;
L36:;
   {
    cl_object v16object_var;
    cl_object v17block_name;
    cl_object v18count_name;
    cl_object v19stream_var;
    cl_object v20function;
    v16object_var = cl_gensym(0);
    v17block_name = cl_gensym(1, _ecl_static_19);
    v18count_name = cl_gensym(1, _ecl_static_20);
    if (!((v6stream_symbol)==(ECL_NIL))) { goto L45; }
    v19stream_var = ECL_SYM("*STANDARD-OUTPUT*",67);
    goto L44;
L45:;
    if (!(ecl_eql(v6stream_symbol,ECL_T))) { goto L48; }
    v19stream_var = ECL_SYM("*TERMINAL-IO*",68);
    goto L44;
L48:;
    v19stream_var = v6stream_symbol;
L44:;
    T0 = cl_list(2, v18count_name, ecl_make_fixnum(0));
    T1 = cl_list(4, v16object_var, v19stream_var, ECL_SYM("&AUX",7), T0);
    T2 = cl_list(4, ECL_SYM("IGNORABLE",427), v16object_var, v19stream_var, v18count_name);
    T3 = cl_list(2, ECL_SYM("DECLARE",274), T2);
    T4 = cl_list(4, VV[117], v16object_var, v18count_name, v19stream_var);
    T5 = cl_list(3, ECL_SYM("RETURN-FROM",725), v17block_name, ECL_NIL);
    T6 = cl_list(3, ECL_SYM("UNLESS",883), T4, T5);
    T7 = cl_list(2, ECL_SYM("INCF",433), v18count_name);
    if (Null(v7object)) { goto L53; }
    T8 = cl_list(2, ECL_SYM("POP",643), v16object_var);
    goto L52;
L53:;
    T8 = ECL_NIL;
L52:;
    T9 = cl_list(4, ECL_SYM("PROGN",671), T6, T7, T8);
    T10 = cl_list(2, ECL_SYM("QUOTE",679), T9);
    T11 = cl_list(3, ECL_SYM("PPRINT-POP",655), ECL_NIL, T10);
    if (Null(v7object)) { goto L56; }
    T13 = cl_list(2, ECL_SYM("NULL",605), v16object_var);
    T14 = cl_list(3, ECL_SYM("RETURN-FROM",725), v17block_name, ECL_NIL);
    T15 = cl_list(3, ECL_SYM("WHEN",905), T13, T14);
    T12 = cl_list(2, ECL_SYM("QUOTE",679), T15);
    goto L55;
L56:;
    T13 = cl_list(3, ECL_SYM("RETURN-FROM",725), v17block_name, ECL_NIL);
    T12 = cl_list(2, ECL_SYM("QUOTE",679), T13);
L55:;
    T13 = cl_list(3, ECL_SYM("PPRINT-EXIT-IF-LIST-EXHAUSTED",649), ECL_NIL, T12);
    T14 = cl_list(2, T11, T13);
    T15 = cl_listX(3, ECL_SYM("MACROLET",521), T14, v3);
    v20function = cl_list(5, ECL_SYM("LAMBDA-BLOCK",1339), v17block_name, T1, T3, T15);
    T0 = cl_list(2, ECL_SYM("FUNCTION",396), v20function);
    value0 = cl_list(7, VV[118], T0, v7object, v6stream_symbol, v9prefix, v13per_line_prefix_p, v15suffix);
    return value0;
   }
  }
 }
}
/*	local function PPRINT-EXIT-IF-LIST-EXHAUSTED                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC47pprint_exit_if_list_exhausted(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_cdr(v1);
   if (Null(v3)) { goto L2; }
   si_dm_too_many_arguments(v1);
L2:;
   value0 = cl_error(1, _ecl_static_21);
   return value0;
  }
 }
}
/*	local function PPRINT-POP                                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC48pprint_pop(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_cdr(v1);
   if (Null(v3)) { goto L2; }
   si_dm_too_many_arguments(v1);
L2:;
   value0 = cl_error(1, _ecl_static_22);
   return value0;
  }
 }
}
/*	function definition for PPRINT-NEWLINE                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_pprint_newline(cl_narg narg, cl_object v1kind, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2stream;
  va_list args; va_start(args,v1kind);
  {
   int i = 1;
   if (i >= narg) {
    v2stream = ECL_NIL;
   } else {
    i++;
    v2stream = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (!(ecl_eql(v1kind,VV[106]))) { goto L8; }
  value0 = VV[124];
  goto L6;
L8:;
  value0 = ECL_NIL;
  goto L6;
L6:;
  if ((value0)!=ECL_NIL) { goto L5; }
  if (!(ecl_eql(v1kind,VV[108]))) { goto L12; }
  value0 = VV[125];
  goto L10;
L12:;
  value0 = ECL_NIL;
  goto L10;
L10:;
  if ((value0)!=ECL_NIL) { goto L5; }
  if (!(ecl_eql(v1kind,VV[109]))) { goto L16; }
  value0 = VV[126];
  goto L14;
L16:;
  value0 = ECL_NIL;
  goto L14;
L14:;
  if ((value0)!=ECL_NIL) { goto L5; }
  if (!(ecl_eql(v1kind,VV[57]))) { goto L19; }
  T0 = VV[127];
  goto L3;
L19:;
  T0 = ECL_NIL;
  goto L3;
L5:;
  T0 = value0;
  goto L3;
L3:;
  if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[128],v1kind);
  value0 = cl_streamp(v2stream);
  if ((value0)!=ECL_NIL) { goto L24; }
  if (!(ecl_eql(v2stream,ECL_T))) { goto L30; }
  value0 = VV[89];
  goto L28;
L30:;
  value0 = ECL_NIL;
  goto L28;
L28:;
  if ((value0)!=ECL_NIL) { goto L27; }
  if (!((v2stream)==(ECL_NIL))) { goto L33; }
  T0 = VV[90];
  goto L22;
L33:;
  T0 = ECL_NIL;
  goto L22;
L27:;
  T0 = value0;
  goto L22;
L24:;
  T0 = value0;
  goto L22;
L22:;
  if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[129],v2stream);
  {
   cl_object v3stream;
   if (!((v2stream)==(ECL_T))) { goto L37; }
   v3stream = ecl_symbol_value(ECL_SYM("*TERMINAL-IO*",68));
   goto L36;
L37:;
   if (!((v2stream)==(ECL_NIL))) { goto L40; }
   v3stream = ecl_symbol_value(ECL_SYM("*STANDARD-OUTPUT*",67));
   goto L36;
L40:;
   v3stream = v2stream;
L36:;
   if (Null(L6pretty_stream_p(v3stream))) { goto L35; }
   if (Null(ecl_symbol_value(ECL_SYM("*PRINT-PRETTY*",55)))) { goto L35; }
   L24enqueue_newline(v3stream, v1kind);
  }
L35:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for PPRINT-INDENT                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_pprint_indent(cl_narg narg, cl_object v1relative_to, cl_object v2n, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v3stream;
  va_list args; va_start(args,v2n);
  {
   int i = 2;
   if (i >= narg) {
    v3stream = ECL_NIL;
   } else {
    i++;
    v3stream = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (!(ecl_eql(v1relative_to,ECL_SYM("BLOCK",1202)))) { goto L8; }
  value0 = VV[62];
  goto L6;
L8:;
  value0 = ECL_NIL;
  goto L6;
L6:;
  if ((value0)!=ECL_NIL) { goto L5; }
  if (!(ecl_eql(v1relative_to,VV[63]))) { goto L11; }
  T0 = VV[64];
  goto L3;
L11:;
  T0 = ECL_NIL;
  goto L3;
L5:;
  T0 = value0;
  goto L3;
L3:;
  if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[65],v1relative_to);
  T0 = cl_realp(v2n);
  if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("REAL",703),v2n);
  value0 = cl_streamp(v3stream);
  if ((value0)!=ECL_NIL) { goto L17; }
  if (!(ecl_eql(v3stream,ECL_T))) { goto L23; }
  value0 = VV[89];
  goto L21;
L23:;
  value0 = ECL_NIL;
  goto L21;
L21:;
  if ((value0)!=ECL_NIL) { goto L20; }
  if (!((v3stream)==(ECL_NIL))) { goto L26; }
  T0 = VV[90];
  goto L15;
L26:;
  T0 = ECL_NIL;
  goto L15;
L20:;
  T0 = value0;
  goto L15;
L17:;
  T0 = value0;
  goto L15;
L15:;
  if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[129],v3stream);
  {
   cl_object v4stream;
   if (!((v3stream)==(ECL_T))) { goto L30; }
   v4stream = ecl_symbol_value(ECL_SYM("*TERMINAL-IO*",68));
   goto L29;
L30:;
   if (!((v3stream)==(ECL_NIL))) { goto L33; }
   v4stream = ecl_symbol_value(ECL_SYM("*STANDARD-OUTPUT*",67));
   goto L29;
L33:;
   v4stream = v3stream;
L29:;
   if (Null(L6pretty_stream_p(v4stream))) { goto L28; }
   if (Null(ecl_symbol_value(ECL_SYM("*PRINT-PRETTY*",55)))) { goto L28; }
   T0 = ecl_round1(v2n);
   L26enqueue_indent(v4stream, v1relative_to, T0);
  }
L28:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for PPRINT-TAB                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_pprint_tab(cl_narg narg, cl_object v1kind, cl_object v2colnum, cl_object v3colinc, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>4)) FEwrong_num_arguments_anonym();
 {
  cl_object v4stream;
  va_list args; va_start(args,v3colinc);
  {
   int i = 3;
   if (i >= narg) {
    v4stream = ECL_NIL;
   } else {
    i++;
    v4stream = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (!(ecl_eql(v1kind,ECL_SYM("LINE",1601)))) { goto L8; }
  value0 = VV[130];
  goto L6;
L8:;
  value0 = ECL_NIL;
  goto L6;
L6:;
  if ((value0)!=ECL_NIL) { goto L5; }
  if (!(ecl_eql(v1kind,VV[97]))) { goto L12; }
  value0 = VV[131];
  goto L10;
L12:;
  value0 = ECL_NIL;
  goto L10;
L10:;
  if ((value0)!=ECL_NIL) { goto L5; }
  if (!(ecl_eql(v1kind,VV[96]))) { goto L16; }
  value0 = VV[132];
  goto L14;
L16:;
  value0 = ECL_NIL;
  goto L14;
L14:;
  if ((value0)!=ECL_NIL) { goto L5; }
  if (!(ecl_eql(v1kind,VV[98]))) { goto L19; }
  T0 = VV[133];
  goto L3;
L19:;
  T0 = ECL_NIL;
  goto L3;
L5:;
  T0 = value0;
  goto L3;
L3:;
  if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[134],v1kind);
  {
   cl_object v5;
   v5 = ecl_make_fixnum(0);
   if (!(ECL_FIXNUMP(v2colnum)||ECL_BIGNUMP(v2colnum))) { goto L25; }
   v5 = v2colnum;
   T0 = ecl_make_bool(ecl_number_compare(v5,ecl_make_fixnum(0))>=0);
   goto L22;
L25:;
   T0 = ECL_NIL;
   goto L22;
  }
L22:;
  if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("UNSIGNED-BYTE",885),v2colnum);
  {
   cl_object v5;
   v5 = ecl_make_fixnum(0);
   if (!(ECL_FIXNUMP(v3colinc)||ECL_BIGNUMP(v3colinc))) { goto L33; }
   v5 = v3colinc;
   T0 = ecl_make_bool(ecl_number_compare(v5,ecl_make_fixnum(0))>=0);
   goto L30;
L33:;
   T0 = ECL_NIL;
   goto L30;
  }
L30:;
  if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("UNSIGNED-BYTE",885),v3colinc);
  value0 = cl_streamp(v4stream);
  if ((value0)!=ECL_NIL) { goto L40; }
  if (!(ecl_eql(v4stream,ECL_T))) { goto L46; }
  value0 = VV[89];
  goto L44;
L46:;
  value0 = ECL_NIL;
  goto L44;
L44:;
  if ((value0)!=ECL_NIL) { goto L43; }
  if (!((v4stream)==(ECL_NIL))) { goto L49; }
  T0 = VV[90];
  goto L38;
L49:;
  T0 = ECL_NIL;
  goto L38;
L43:;
  T0 = value0;
  goto L38;
L40:;
  T0 = value0;
  goto L38;
L38:;
  if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[129],v4stream);
  {
   cl_object v5stream;
   if (!((v4stream)==(ECL_T))) { goto L53; }
   v5stream = ecl_symbol_value(ECL_SYM("*TERMINAL-IO*",68));
   goto L52;
L53:;
   if (!((v4stream)==(ECL_NIL))) { goto L56; }
   v5stream = ecl_symbol_value(ECL_SYM("*STANDARD-OUTPUT*",67));
   goto L52;
L56:;
   v5stream = v4stream;
L52:;
   if (Null(L6pretty_stream_p(v5stream))) { goto L51; }
   if (Null(ecl_symbol_value(ECL_SYM("*PRINT-PRETTY*",55)))) { goto L51; }
   L32enqueue_tab(v5stream, v1kind, v2colnum, v3colinc);
  }
L51:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for PPRINT-FILL                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_pprint_fill(cl_narg narg, cl_object v1stream, cl_object v2list, ...)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>4)) FEwrong_num_arguments_anonym();
 {
  cl_object v3colon_;
  cl_object v4atsign_;
  va_list args; va_start(args,v2list);
  {
   int i = 2;
   if (i >= narg) {
    v3colon_ = ECL_T;
   } else {
    i++;
    v3colon_ = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v4atsign_ = ECL_NIL;
   } else {
    i++;
    v4atsign_ = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = cl_streamp(v1stream);
  if ((value0)!=ECL_NIL) { goto L6; }
  if (!(ecl_eql(v1stream,ECL_T))) { goto L12; }
  value0 = VV[89];
  goto L10;
L12:;
  value0 = ECL_NIL;
  goto L10;
L10:;
  if ((value0)!=ECL_NIL) { goto L9; }
  if (!((v1stream)==(ECL_NIL))) { goto L15; }
  T0 = VV[90];
  goto L4;
L15:;
  T0 = ECL_NIL;
  goto L4;
L9:;
  T0 = value0;
  goto L4;
L6:;
  T0 = value0;
  goto L4;
L4:;
  if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[129],v1stream);
  {cl_object v5;
   v5 = ECL_NIL;
   v5 = ecl_make_cfun((cl_objectfn_fixed)LC49__pprint_logical_block_487,ECL_NIL,Cblock,2);
   T0 = v5;
  }
  if (Null(v3colon_)) { goto L21; }
  T1 = _ecl_static_23;
  goto L20;
L21:;
  T1 = _ecl_static_17;
L20:;
  if (Null(v3colon_)) { goto L24; }
  T2 = _ecl_static_24;
  goto L23;
L24:;
  T2 = _ecl_static_17;
L23:;
  value0 = si_pprint_logical_block_helper(6, T0, v2list, v1stream, T1, ECL_NIL, T2);
  return value0;
 }
}
/*	local function PPRINT-LOGICAL-BLOCK-487                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC49__pprint_logical_block_487(cl_object v1, cl_object v2stream)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_make_fixnum(0);
   if (!(v1==ECL_NIL)) { goto L2; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
L4:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L7; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L7:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v4;
    v4 = v1;
    if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
    if (Null(v4)) { goto L15; }
    {
     cl_object v5;
     v5 = ECL_CONS_CDR(v4);
     v1 = v5;
     v4 = ECL_CONS_CAR(v4);
    }
L15:;
    T0 = v4;
   }
   si_write_object(T0, v2stream);
   if (!(v1==ECL_NIL)) { goto L21; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L21:;
   cl_write_char(2, CODE_CHAR(32), v2stream);
   cl_pprint_newline(2, VV[109], v2stream);
   goto L4;
  }
 }
}
/*	function definition for PPRINT-LINEAR                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_pprint_linear(cl_narg narg, cl_object v1stream, cl_object v2list, ...)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>4)) FEwrong_num_arguments_anonym();
 {
  cl_object v3colon_;
  cl_object v4atsign_;
  va_list args; va_start(args,v2list);
  {
   int i = 2;
   if (i >= narg) {
    v3colon_ = ECL_T;
   } else {
    i++;
    v3colon_ = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v4atsign_ = ECL_NIL;
   } else {
    i++;
    v4atsign_ = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = cl_streamp(v1stream);
  if ((value0)!=ECL_NIL) { goto L6; }
  if (!(ecl_eql(v1stream,ECL_T))) { goto L12; }
  value0 = VV[89];
  goto L10;
L12:;
  value0 = ECL_NIL;
  goto L10;
L10:;
  if ((value0)!=ECL_NIL) { goto L9; }
  if (!((v1stream)==(ECL_NIL))) { goto L15; }
  T0 = VV[90];
  goto L4;
L15:;
  T0 = ECL_NIL;
  goto L4;
L9:;
  T0 = value0;
  goto L4;
L6:;
  T0 = value0;
  goto L4;
L4:;
  if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[129],v1stream);
  {cl_object v5;
   v5 = ECL_NIL;
   v5 = ecl_make_cfun((cl_objectfn_fixed)LC50__pprint_logical_block_503,ECL_NIL,Cblock,2);
   T0 = v5;
  }
  if (Null(v3colon_)) { goto L21; }
  T1 = _ecl_static_23;
  goto L20;
L21:;
  T1 = _ecl_static_17;
L20:;
  if (Null(v3colon_)) { goto L24; }
  T2 = _ecl_static_24;
  goto L23;
L24:;
  T2 = _ecl_static_17;
L23:;
  value0 = si_pprint_logical_block_helper(6, T0, v2list, v1stream, T1, ECL_NIL, T2);
  return value0;
 }
}
/*	local function PPRINT-LOGICAL-BLOCK-503                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC50__pprint_logical_block_503(cl_object v1, cl_object v2stream)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_make_fixnum(0);
   if (!(v1==ECL_NIL)) { goto L2; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
L4:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L7; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L7:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v4;
    v4 = v1;
    if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
    if (Null(v4)) { goto L15; }
    {
     cl_object v5;
     v5 = ECL_CONS_CDR(v4);
     v1 = v5;
     v4 = ECL_CONS_CAR(v4);
    }
L15:;
    T0 = v4;
   }
   si_write_object(T0, v2stream);
   if (!(v1==ECL_NIL)) { goto L21; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L21:;
   cl_write_char(2, CODE_CHAR(32), v2stream);
   cl_pprint_newline(2, VV[106], v2stream);
   goto L4;
  }
 }
}
/*	function definition for PPRINT-TABULAR                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_pprint_tabular(cl_narg narg, cl_object v1stream, cl_object v2list, ...)
{
 cl_object T0, T1, T2;
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>5)) FEwrong_num_arguments_anonym();
 {
  cl_object v3colon_;
  cl_object v4atsign_;
  cl_object v5tabsize;
  va_list args; va_start(args,v2list);
  {
   int i = 2;
   if (i >= narg) {
    v3colon_ = ECL_T;
   } else {
    i++;
    v3colon_ = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v4atsign_ = ECL_NIL;
   } else {
    i++;
    v4atsign_ = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v5tabsize = ecl_make_fixnum(16);
   } else {
    i++;
    v5tabsize = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = cl_streamp(v1stream);
  if ((value0)!=ECL_NIL) { goto L7; }
  if (!(ecl_eql(v1stream,ECL_T))) { goto L13; }
  value0 = VV[89];
  goto L11;
L13:;
  value0 = ECL_NIL;
  goto L11;
L11:;
  if ((value0)!=ECL_NIL) { goto L10; }
  if (!((v1stream)==(ECL_NIL))) { goto L16; }
  T0 = VV[90];
  goto L5;
L16:;
  T0 = ECL_NIL;
  goto L5;
L10:;
  T0 = value0;
  goto L5;
L7:;
  T0 = value0;
  goto L5;
L5:;
  if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[129],v1stream);
  {
   cl_object v6;
   v6 = ecl_make_fixnum(0);
   if (!(ECL_FIXNUMP(v5tabsize)||ECL_BIGNUMP(v5tabsize))) { goto L24; }
   v6 = v5tabsize;
   T0 = ecl_make_bool(ecl_number_compare(v6,ecl_make_fixnum(0))>=0);
   goto L21;
L24:;
   T0 = ECL_NIL;
   goto L21;
  }
L21:;
  if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("UNSIGNED-BYTE",885),v5tabsize);
  {
   cl_object env1 = env0;
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(v5tabsize,env1);            /*  TABSIZE         */
   {cl_object v6;
    v6 = ECL_NIL;
    v6 = ecl_make_cclosure_va((cl_objectfn)LC51__pprint_logical_block_524,env1,Cblock);
    T0 = v6;
   }
   if (Null(v3colon_)) { goto L30; }
   T1 = _ecl_static_23;
   goto L29;
L30:;
   T1 = _ecl_static_17;
L29:;
   if (Null(v3colon_)) { goto L33; }
   T2 = _ecl_static_24;
   goto L32;
L33:;
   T2 = _ecl_static_17;
L32:;
   value0 = si_pprint_logical_block_helper(6, T0, v2list, v1stream, T1, ECL_NIL, T2);
   return value0;
  }
 }
}
/*	closure PPRINT-LOGICAL-BLOCK-524                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC51__pprint_logical_block_524(cl_narg narg, cl_object v1, cl_object v2stream, ...)
{
 cl_object T0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  TABSIZE         */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_make_fixnum(0);
   if (!(v1==ECL_NIL)) { goto L2; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
L4:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L7; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L7:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v4;
    v4 = v1;
    if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
    if (Null(v4)) { goto L15; }
    {
     cl_object v5;
     v5 = ECL_CONS_CDR(v4);
     v1 = v5;
     v4 = ECL_CONS_CAR(v4);
    }
L15:;
    T0 = v4;
   }
   si_write_object(T0, v2stream);
   if (!(v1==ECL_NIL)) { goto L21; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L21:;
   cl_write_char(2, CODE_CHAR(32), v2stream);
   value0 = ECL_CONS_CAR(CLV0);
   if ((value0)!=ECL_NIL) { goto L27; }
   T0 = ecl_make_fixnum(16);
   goto L25;
L27:;
   T0 = value0;
   goto L25;
L25:;
   cl_pprint_tab(4, VV[98], ecl_make_fixnum(0), T0, v2stream);
   cl_pprint_newline(2, VV[109], v2stream);
   goto L4;
  }
 }
 }
}
/*	function definition for MAKE-PPRINT-DISPATCH-ENTRY            */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L52make_pprint_dispatch_entry(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 cl_object v1;
 cl_object v2;
 cl_object v3;
 cl_object v4;
 ecl_va_list args; ecl_va_start(args,narg,narg,0);
 {
  cl_object keyvars[8];
  cl_parse_key(args,4,L52make_pprint_dispatch_entrykeys,keyvars,NULL,FALSE);
  ecl_va_end(args);
  if (Null(keyvars[4])) {
   v1 = ecl_function_dispatch(cl_env_copy,VV[201])(0) /*  REQUIRED-ARGUMENT */;
  } else {
   v1 = keyvars[0];
  }
  if (Null(keyvars[5])) {
   v2 = ecl_make_fixnum(0);
  } else {
   v2 = keyvars[1];
  }
  if (Null(keyvars[6])) {
   {
    bool v5;
    v5 = ecl_boundp(cl_env_copy,VV[135]);
    v3 = (v5)?ECL_NIL:ECL_T;
   }
  } else {
   v3 = keyvars[2];
  }
  if (Null(keyvars[7])) {
   v4 = ecl_function_dispatch(cl_env_copy,VV[201])(0) /*  REQUIRED-ARGUMENT */;
  } else {
   v4 = keyvars[3];
  }
 }
 if ((cl_functionp(v4))!=ECL_NIL) { goto L5; }
 if (ECL_SYMBOLP(v4)) { goto L5; }
 si_structure_type_error(4, v4, VV[140], VV[136], ECL_SYM("FUNCTION",396));
L5:;
 if (!(ecl_eql(v3,ECL_T))) { goto L12; }
 goto L8;
 goto L10;
L12:;
 goto L10;
L10:;
 if (!((v3)==(ECL_NIL))) { goto L15; }
 goto L8;
 goto L9;
L15:;
 goto L9;
L9:;
 si_structure_type_error(4, v3, VV[91], VV[136], VV[141]);
L8:;
 if ((cl_realp(v2))!=ECL_NIL) { goto L17; }
 si_structure_type_error(4, v2, ECL_SYM("REAL",703), VV[136], VV[142]);
L17:;
 value0 = si_make_structure(5, VV[143], v1, v2, v3, v4);
 return value0;
}
/*	function definition for %PRINT-PPRINT-DISPATCH-ENTRY          */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L54_print_pprint_dispatch_entry(cl_object v1entry, cl_object v2stream, cl_object v3depth)
{
 cl_object env0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 env0 = ECL_NIL;
 CLV0 = env0 = CONS(v1entry,env0);                /*  ENTRY           */
 CLV1 = env0 = CONS(v2stream,env0);               /*  STREAM          */
 {cl_object v4;
  v4 = ECL_NIL;
  v4 = ecl_make_cclosure_va((cl_objectfn)LC53_print_unreadable_object_body_,env0,Cblock);
  value0 = si_print_unreadable_object_function(ECL_CONS_CAR(CLV0), ECL_CONS_CAR(CLV1), ECL_T, ECL_NIL, v4);
  return value0;
 }
}
/*	closure .PRINT-UNREADABLE-OBJECT-BODY.                        */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC53_print_unreadable_object_body_(cl_narg narg, ...)
{
 cl_object T0, T1, T2;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  STREAM          */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
TTL:
 T0 = ecl_function_dispatch(cl_env_copy,VV[259])(1, ECL_CONS_CAR(CLV0)) /*  PPRINT-DISPATCH-ENTRY-TYPE */;
 T1 = ecl_function_dispatch(cl_env_copy,VV[260])(1, ECL_CONS_CAR(CLV0)) /*  PPRINT-DISPATCH-ENTRY-PRIORITY */;
 T2 = ecl_function_dispatch(cl_env_copy,VV[261])(1, ECL_CONS_CAR(CLV0)) /*  PPRINT-DISPATCH-ENTRY-INITIAL-P */;
 value0 = cl_format(5, ECL_CONS_CAR(CLV1), _ecl_static_26, T0, T1, T2);
 return value0;
 }
}
/*	function definition for MAKE-PPRINT-DISPATCH-TABLE            */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L55make_pprint_dispatch_table(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 cl_object v1;
 cl_object v2;
 ecl_va_list args; ecl_va_start(args,narg,narg,0);
 {
  cl_object keyvars[4];
  cl_parse_key(args,2,L55make_pprint_dispatch_tablekeys,keyvars,NULL,FALSE);
  ecl_va_end(args);
  v1 = keyvars[0];
  if (Null(keyvars[3])) {
   T0 = (ECL_SYM("EQL",334)->symbol.gfdef);
   v2 = cl_make_hash_table(2, ECL_SYM("TEST",1316), T0);
  } else {
   v2 = keyvars[1];
  }
 }
 if (ECL_LISTP(v1)) { goto L3; }
 si_structure_type_error(4, v1, ECL_SYM("LIST",481), VV[146], VV[150]);
L3:;
 value0 = si_make_structure(3, VV[151], v1, v2);
 return value0;
}
/*	function definition for %PRINT-PPRINT-DISPATCH-TABLE          */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L56_print_pprint_dispatch_table(cl_object v1table, cl_object v2stream, cl_object v3depth)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 value0 = si_print_unreadable_object_function(v1table, v2stream, ECL_T, ECL_T, ECL_NIL);
 return value0;
}
/*	function definition for CONS-TYPE-SPECIFIER-P                 */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L57cons_type_specifier_p(cl_object v1spec)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 if (!(ECL_CONSP(v1spec))) { goto L2; }
 T0 = _ecl_car(v1spec);
 if (!((T0)==(ECL_SYM("CONS",251)))) { goto L2; }
 if (Null(_ecl_cdr(v1spec))) { goto L2; }
 T0 = _ecl_cddr(v1spec);
 if (!(T0==ECL_NIL)) { goto L2; }
 {
  cl_object v2car;
  v2car = _ecl_cadr(v1spec);
  if (!(ECL_CONSP(v2car))) { goto L9; }
  {
   cl_object v3carcar;
   v3carcar = _ecl_car(v2car);
   if ((v3carcar)==(ECL_SYM("MEMBER",552))) { goto L13; }
   if (!((v3carcar)==(ECL_SYM("EQL",334)))) { goto L9; }
   goto L11;
L13:;
  }
L11:;
  if (Null(_ecl_cdr(v2car))) { goto L9; }
  T0 = _ecl_cddr(v2car);
  value0 = ecl_make_bool(T0==ECL_NIL);
  cl_env_copy->nvalues = 1;
  return value0;
L9:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
L2:;
 value0 = ECL_NIL;
 cl_env_copy->nvalues = 1;
 return value0;
}
/*	function definition for ENTRY<                                */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L58entry_(cl_object v1e1, cl_object v2e2)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 if (Null(ecl_function_dispatch(cl_env_copy,VV[261])(1, v1e1) /*  PPRINT-DISPATCH-ENTRY-INITIAL-P */)) { goto L1; }
 if (Null(ecl_function_dispatch(cl_env_copy,VV[261])(1, v2e2) /*  PPRINT-DISPATCH-ENTRY-INITIAL-P */)) { goto L3; }
 T0 = ecl_function_dispatch(cl_env_copy,VV[260])(1, v1e1) /*  PPRINT-DISPATCH-ENTRY-PRIORITY */;
 T1 = ecl_function_dispatch(cl_env_copy,VV[260])(1, v2e2) /*  PPRINT-DISPATCH-ENTRY-PRIORITY */;
 value0 = ecl_make_bool(ecl_number_compare(T0,T1)<0);
 cl_env_copy->nvalues = 1;
 return value0;
L3:;
 value0 = ECL_T;
 cl_env_copy->nvalues = 1;
 return value0;
L1:;
 if (Null(ecl_function_dispatch(cl_env_copy,VV[261])(1, v2e2) /*  PPRINT-DISPATCH-ENTRY-INITIAL-P */)) { goto L5; }
 value0 = ECL_NIL;
 cl_env_copy->nvalues = 1;
 return value0;
L5:;
 T0 = ecl_function_dispatch(cl_env_copy,VV[260])(1, v1e1) /*  PPRINT-DISPATCH-ENTRY-PRIORITY */;
 T1 = ecl_function_dispatch(cl_env_copy,VV[260])(1, v2e2) /*  PPRINT-DISPATCH-ENTRY-PRIORITY */;
 value0 = ecl_make_bool(ecl_number_compare(T0,T1)<0);
 cl_env_copy->nvalues = 1;
 return value0;
}
/*	function definition for COPY-PPRINT-DISPATCH                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_copy_pprint_dispatch(cl_narg narg, ...)
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
  cl_object v1table;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1table = ECL_SYM_VAL(cl_env_copy,ECL_SYM("*PRINT-PPRINT-DISPATCH*",54));
   } else {
    i++;
    v1table = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = si_of_class_p(2, v1table, VV[146]);
  if ((value0)!=ECL_NIL) { goto L5; }
  T0 = ecl_make_bool(v1table==ECL_NIL);
  goto L3;
L5:;
  T0 = value0;
  goto L3;
L3:;
  if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[154],v1table);
  {
   cl_object v2orig;
   value0 = v1table;
   if ((value0)!=ECL_NIL) { goto L9; }
   v2orig = ecl_symbol_value(VV[135]);
   goto L7;
L9:;
   v2orig = value0;
   goto L7;
L7:;
   {
    cl_object v3new;
    cl_object env1 = env0;
    T0 = ecl_function_dispatch(cl_env_copy,VV[266])(1, v2orig) /*  PPRINT-DISPATCH-TABLE-ENTRIES */;
    T1 = cl_copy_list(T0);
    v3new = L55make_pprint_dispatch_table(2, VV[155], T1);
    T0 = ecl_function_dispatch(cl_env_copy,VV[267])(1, v3new) /*  PPRINT-DISPATCH-TABLE-CONS-ENTRIES */;
    env1 = ECL_NIL;
    CLV0 = env1 = CONS(T0,env1);                  /*  NEW-CONS-ENTRIES */
    {cl_object v4;
     v4 = ECL_NIL;
     v4 = ecl_make_cclosure_va((cl_objectfn)LC59__g540,env1,Cblock);
     T0 = v4;
    }
    T1 = ecl_function_dispatch(cl_env_copy,VV[267])(1, v2orig) /*  PPRINT-DISPATCH-TABLE-CONS-ENTRIES */;
    cl_maphash(T0, T1);
    value0 = v3new;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	closure G540                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC59__g540(cl_narg narg, cl_object v1key, cl_object v2value, ...)
{
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  NEW-CONS-ENTRIES */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = si_hash_set(v1key, ECL_CONS_CAR(CLV0), v2value);
  return value0;
 }
 }
}
/*	function definition for DEFAULT-PPRINT-DISPATCH               */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L60default_pprint_dispatch(cl_object v1stream, cl_object v2object)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 value0 = si_write_ugly_object(v2object, v1stream);
 return value0;
}
/*	function definition for PPRINT-DISPATCH                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_pprint_dispatch(cl_narg narg, cl_object v1object, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2table;
  va_list args; va_start(args,v1object);
  {
   int i = 1;
   if (i >= narg) {
    v2table = ECL_SYM_VAL(cl_env_copy,ECL_SYM("*PRINT-PPRINT-DISPATCH*",54));
   } else {
    i++;
    v2table = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = si_of_class_p(2, v2table, VV[146]);
  if ((value0)!=ECL_NIL) { goto L5; }
  T0 = ecl_make_bool(v2table==ECL_NIL);
  goto L3;
L5:;
  T0 = value0;
  goto L3;
L3:;
  if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[154],v2table);
  {
   cl_object v3table;
   cl_object v4cons_entry;
   cl_object v5entry;
   value0 = v2table;
   if ((value0)!=ECL_NIL) { goto L9; }
   v3table = ecl_symbol_value(VV[135]);
   goto L7;
L9:;
   v3table = value0;
   goto L7;
L7:;
   if (!(ECL_CONSP(v1object))) { goto L13; }
   T0 = ecl_car(v1object);
   T1 = ecl_function_dispatch(cl_env_copy,VV[267])(1, v3table) /*  PPRINT-DISPATCH-TABLE-CONS-ENTRIES */;
   v4cons_entry = ecl_gethash_safe(T0,T1,ECL_NIL);
   goto L11;
L13:;
   v4cons_entry = ECL_NIL;
   goto L11;
L11:;
   {
    cl_object v6;
    v6 = ecl_function_dispatch(cl_env_copy,VV[266])(1, v3table) /*  PPRINT-DISPATCH-TABLE-ENTRIES */;
    goto L19;
L18:;
    {
     cl_object v7entry;
     v7entry = ecl_car(v6);
     if (Null(v4cons_entry)) { goto L23; }
     if (Null(L58entry_(v7entry, v4cons_entry))) { goto L23; }
     v5entry = v4cons_entry;
     goto L15;
L23:;
     T0 = ecl_function_dispatch(cl_env_copy,VV[259])(1, v7entry) /*  PPRINT-DISPATCH-ENTRY-TYPE */;
     if (Null(cl_typep(2, v1object, T0))) { goto L26; }
     v5entry = v7entry;
     goto L15;
L26:;
    }
    v6 = ecl_cdr(v6);
L19:;
    if (Null(v6)) { goto L30; }
    goto L18;
L30:;
    v5entry = v4cons_entry;
   }
L15:;
   if (Null(v5entry)) { goto L32; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[269])(1, v5entry) /*  PPRINT-DISPATCH-ENTRY-FUNCTION */;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = ECL_T;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
L32:;
   T0 = (VV[156]->symbol.gfdef);
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = ECL_NIL;
   cl_env_copy->values[0] = T0;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for SET-PPRINT-DISPATCH                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_set_pprint_dispatch(cl_narg narg, cl_object v1type, cl_object v2function, ...)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>4)) FEwrong_num_arguments_anonym();
 {
  cl_object v3priority;
  cl_object v4table;
  va_list args; va_start(args,v2function);
  {
   int i = 2;
   if (i >= narg) {
    v3priority = ecl_make_fixnum(0);
   } else {
    i++;
    v3priority = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v4table = ECL_SYM_VAL(cl_env_copy,ECL_SYM("*PRINT-PPRINT-DISPATCH*",54));
   } else {
    i++;
    v4table = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = ecl_make_bool(v2function==ECL_NIL);
  if ((value0)!=ECL_NIL) { goto L6; }
  value0 = cl_functionp(v2function);
  if ((value0)!=ECL_NIL) { goto L6; }
  T0 = ecl_make_bool(ECL_SYMBOLP(v2function));
  goto L4;
L6:;
  T0 = value0;
  goto L4;
L4:;
  if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[157],v2function);
  T0 = cl_realp(v3priority);
  if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("REAL",703),v3priority);
  T0 = si_of_class_p(2, v4table, VV[146]);
  if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[146],v4table);
  if (Null(v2function)) { goto L13; }
  if (Null(L57cons_type_specifier_p(v1type))) { goto L15; }
  T0 = ecl_cadr(v1type);
  T1 = ecl_cadr(T0);
  T2 = ecl_function_dispatch(cl_env_copy,VV[267])(1, v4table) /*  PPRINT-DISPATCH-TABLE-CONS-ENTRIES */;
  T3 = L52make_pprint_dispatch_entry(6, ECL_SYM("TYPE",1318), v1type, VV[158], v3priority, ECL_SYM("FUNCTION",1241), v2function);
  si_hash_set(T1, T2, T3);
  goto L12;
L15:;
  {
   cl_object v5;
   cl_object v6;
   cl_object v7list;
   T0 = ecl_function_dispatch(cl_env_copy,VV[266])(1, v4table) /*  PPRINT-DISPATCH-TABLE-ENTRIES */;
   T1 = (VV[259]->symbol.gfdef);
   T2 = (ECL_SYM("EQUAL",335)->symbol.gfdef);
   v5 = cl_delete(6, v1type, T0, ECL_SYM("KEY",1262), T1, ECL_SYM("TEST",1316), T2);
   v6 = L52make_pprint_dispatch_entry(6, ECL_SYM("TYPE",1318), v1type, VV[158], v3priority, ECL_SYM("FUNCTION",1241), v2function);
   v7list = v5;
   {
    cl_object v8;
    cl_object v9prev;
    cl_object v10next;
    v8 = v7list;
    v9prev = ECL_NIL;
    v10next = v8;
    goto L28;
L27:;
    T0 = ecl_car(v10next);
    if (Null(L58entry_(T0, v6))) { goto L30; }
    if (Null(v9prev)) { goto L33; }
    {
     cl_object v11;
     v11 = CONS(v6,v10next);
     if (ecl_unlikely(ECL_ATOM(v9prev))) FEtype_error_cons(v9prev);
     T0 = v9prev;
     (ECL_CONS_CDR(T0)=v11,T0);
     goto L32;
    }
L33:;
    v7list = CONS(v6,v10next);
L32:;
    goto L22;
L30:;
    v9prev = v10next;
    v10next = ecl_cdr(v10next);
L28:;
    if (v10next==ECL_NIL) { goto L43; }
    goto L27;
L43:;
    if (Null(v9prev)) { goto L45; }
    {
     cl_object v11;
     v11 = ecl_list1(v6);
     if (ecl_unlikely(ECL_ATOM(v9prev))) FEtype_error_cons(v9prev);
     T0 = v9prev;
     (ECL_CONS_CDR(T0)=v11,T0);
     goto L22;
    }
L45:;
    v7list = ecl_list1(v6);
   }
L22:;
   ecl_structure_set(v4table,VV[146],0,v7list);
   goto L12;
  }
L13:;
  if (Null(L57cons_type_specifier_p(v1type))) { goto L52; }
  T0 = ecl_cadr(v1type);
  T1 = ecl_cadr(T0);
  T2 = ecl_function_dispatch(cl_env_copy,VV[267])(1, v4table) /*  PPRINT-DISPATCH-TABLE-CONS-ENTRIES */;
  cl_remhash(T1, T2);
  goto L12;
L52:;
  {
   cl_object v8;
   T0 = ecl_function_dispatch(cl_env_copy,VV[266])(1, v4table) /*  PPRINT-DISPATCH-TABLE-ENTRIES */;
   T1 = (VV[259]->symbol.gfdef);
   T2 = (ECL_SYM("EQUAL",335)->symbol.gfdef);
   v8 = cl_delete(6, v1type, T0, ECL_SYM("KEY",1262), T1, ECL_SYM("TEST",1316), T2);
   ecl_structure_set(v4table,VV[146],0,v8);
  }
L12:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for PPRINT-ARRAY                          */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L61pprint_array(cl_object v1stream, cl_object v2array)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 if (!(ECL_SYM_VAL(cl_env_copy,ECL_SYM("*PRINT-ARRAY*",44))==ECL_NIL)) { goto L6; }
 if (ECL_SYM_VAL(cl_env_copy,ECL_SYM("*PRINT-READABLY*",57))==ECL_NIL) { goto L3; }
 goto L4;
L6:;
 goto L4;
L4:;
 if (ECL_STRINGP(v2array)) { goto L3; }
 if (!(ECL_BIT_VECTOR_P(v2array))) { goto L1; }
 goto L2;
L3:;
L2:;
 value0 = si_write_ugly_object(v2array, v1stream);
 return value0;
L1:;
 if (Null(ECL_SYM_VAL(cl_env_copy,ECL_SYM("*PRINT-READABLY*",57)))) { goto L9; }
 value0 = L69pprint_raw_array(v1stream, v2array);
 return value0;
L9:;
 if (!(ECL_VECTORP(v2array))) { goto L11; }
 value0 = L63pprint_vector(v1stream, v2array);
 return value0;
L11:;
 value0 = L67pprint_multi_dim_array(v1stream, v2array);
 return value0;
}
/*	function definition for PPRINT-VECTOR                         */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L63pprint_vector(cl_object v1stream, cl_object v2vector)
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 env0 = ECL_NIL;
 CLV0 = env0 = CONS(v2vector,env0);               /*  VECTOR          */
 {cl_object v3;
  v3 = ECL_NIL;
  v3 = ecl_make_cclosure_va((cl_objectfn)LC62__pprint_logical_block_569,env0,Cblock);
  T0 = v3;
 }
 value0 = si_pprint_logical_block_helper(6, T0, ECL_NIL, v1stream, _ecl_static_28, ECL_NIL, _ecl_static_24);
 return value0;
}
/*	closure PPRINT-LOGICAL-BLOCK-569                              */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC62__pprint_logical_block_569(cl_narg narg, cl_object v1, cl_object v2stream, ...)
{
 cl_object T0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  VECTOR          */
 { /* ... closure scanning finished */
TTL:
 {
  cl_object v3;
  v3 = ecl_make_fixnum(0);
  {
   cl_fixnum v4;
   v4 = ecl_length(ECL_CONS_CAR(CLV0));
   {
    cl_fixnum v5i;
    v5i = 0;
    goto L5;
L4:;
    if ((v5i)==0) { goto L7; }
    cl_write_char(2, CODE_CHAR(32), v2stream);
    cl_pprint_newline(2, VV[109], v2stream);
L7:;
    if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L11; }
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
L11:;
    v3 = ecl_plus(v3,ecl_make_fixnum(1));
    T0 = ecl_aref_unsafe(ECL_CONS_CAR(CLV0),v5i);
    si_write_object(T0, v2stream);
    v5i = (v5i)+1;
L5:;
    if (!((v5i)<(v4))) { goto L19; }
    goto L4;
L19:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
 }
}
/*	function definition for PPRINT-ARRAY-CONTENTS                 */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L66pprint_array_contents(cl_object v1stream, cl_object v2array)
{
 cl_object T0;
 cl_object env0;
 volatile struct ecl_cclosure aux_closure;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 env0 = ECL_NIL;
 CLV0 = env0 = CONS(v2array,env0);                /*  ARRAY           */
 T0 = cl_array_dimensions(ECL_CONS_CAR(CLV0));
 value0 = (aux_closure.env=env0,cl_env_copy->function=(cl_object)&aux_closure,LC65output_guts(3, v1stream, ecl_make_fixnum(0), T0));
 return value0;
}
/*	closure OUTPUT-GUTS                                           */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC65output_guts(cl_narg narg, cl_object v1stream, cl_object v2index, cl_object v3dimensions, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1, CLV2
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  ARRAY           */
 { /* ... closure scanning finished */
 CLV1 = env0 = CONS(v2index,env0);                /*  INDEX           */
 CLV2 = env0 = CONS(v3dimensions,env0);           /*  DIMENSIONS      */
 if (!(ECL_CONS_CAR(CLV2)==ECL_NIL)) { goto L1; }
 T0 = ecl_aref_unsafe(ECL_CONS_CAR(CLV0),ecl_fixnum(ECL_CONS_CAR(CLV1)));
 value0 = si_write_object(T0, v1stream);
 return value0;
L1:;
 {cl_object v4;
  v4 = ECL_NIL;
  v4 = ecl_make_cclosure_va((cl_objectfn)LC64__pprint_logical_block_583,env0,Cblock);
  T0 = v4;
 }
 value0 = si_pprint_logical_block_helper(6, T0, ECL_NIL, v1stream, _ecl_static_23, ECL_NIL, _ecl_static_24);
 return value0;
 }
}
/*	closure PPRINT-LOGICAL-BLOCK-583                              */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC64__pprint_logical_block_583(cl_narg narg, cl_object v1, cl_object v2stream, ...)
{
 cl_object T0;
 volatile struct ecl_cclosure aux_closure;
 cl_object CLV0, CLV1, CLV2
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV2 = env0;                                     /*  DIMENSIONS      */
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
TTL:
 {
  cl_object v3;
  v3 = ecl_make_fixnum(0);
  {
   cl_object v4dim;
   v4dim = _ecl_car(ECL_CONS_CAR(CLV2));
   if (ecl_zerop(v4dim)) { goto L3; }
   {
    cl_object v5dims;
    cl_object v6index;
    cl_object v7step;
    cl_object v8count;
    v5dims = _ecl_cdr(ECL_CONS_CAR(CLV2));
    v6index = ECL_CONS_CAR(CLV1);
    T0 = (ECL_SYM("*",18)->symbol.gfdef);
    v7step = cl_reduce(2, T0, v5dims);
    v8count = ecl_make_fixnum(0);
L10:;
    if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L13; }
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
L13:;
    v3 = ecl_plus(v3,ecl_make_fixnum(1));
    (aux_closure.env=ecl_nthcdr(2,env0),cl_env_copy->function=(cl_object)&aux_closure,LC65output_guts(3, v2stream, v6index, v5dims));
    v8count = ecl_plus(v8count,ecl_make_fixnum(1));
    T0 = v8count;
    if (!(ecl_number_equalp(T0,v4dim))) { goto L18; }
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
L18:;
    cl_write_char(2, CODE_CHAR(32), v2stream);
    if (Null(v5dims)) { goto L25; }
    T0 = VV[106];
    goto L24;
L25:;
    T0 = VV[109];
L24:;
    cl_pprint_newline(2, T0, v2stream);
    v6index = ecl_plus(v6index,v7step);
    goto L10;
   }
L3:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
 }
}
/*	function definition for PPRINT-MULTI-DIM-ARRAY                */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L67pprint_multi_dim_array(cl_object v1stream, cl_object v2array)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  int8_t v3;
  v3 = (int8_t)((((v2array)->d.t == t_array)?(v2array)->array.rank:1));
  cl_write_string(2, _ecl_static_15, v1stream);
  cl_write(9, ecl_make_int8_t(v3), ECL_SYM("STREAM",1313), v1stream, ECL_SYM("BASE",1201), ecl_make_fixnum(10), ECL_SYM("RADIX",1295), ECL_NIL, ECL_SYM("ESCAPE",1230), ECL_NIL);
  cl_write_string(2, _ecl_static_29, v1stream);
 }
 value0 = L66pprint_array_contents(v1stream, v2array);
 return value0;
}
/*	function definition for PPRINT-RAW-ARRAY                      */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L69pprint_raw_array(cl_object v1stream, cl_object v2array)
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 env0 = ECL_NIL;
 CLV0 = env0 = CONS(v2array,env0);                /*  ARRAY           */
 cl_write_string(2, _ecl_static_30, v1stream);
 {cl_object v3;
  v3 = ECL_NIL;
  v3 = ecl_make_cclosure_va((cl_objectfn)LC68__pprint_logical_block_602,env0,Cblock);
  T0 = v3;
 }
 value0 = si_pprint_logical_block_helper(6, T0, ECL_NIL, v1stream, _ecl_static_23, ECL_NIL, _ecl_static_24);
 return value0;
}
/*	closure PPRINT-LOGICAL-BLOCK-602                              */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC68__pprint_logical_block_602(cl_narg narg, cl_object v1, cl_object v2stream, ...)
{
 cl_object T0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  ARRAY           */
 { /* ... closure scanning finished */
TTL:
 T0 = cl_array_element_type(ECL_CONS_CAR(CLV0));
 si_write_object(T0, v2stream);
 cl_write_char(2, CODE_CHAR(32), v2stream);
 cl_pprint_newline(2, VV[109], v2stream);
 T0 = cl_array_dimensions(ECL_CONS_CAR(CLV0));
 si_write_object(T0, v2stream);
 cl_write_char(2, CODE_CHAR(32), v2stream);
 cl_pprint_newline(2, VV[109], v2stream);
 value0 = L66pprint_array_contents(v2stream, ECL_CONS_CAR(CLV0));
 return value0;
 }
}
/*	function definition for PPRINT-LAMBDA-LIST                    */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L73pprint_lambda_list(cl_narg narg, cl_object v1stream, cl_object v2lambda_list, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {cl_object v3;
  v3 = ECL_NIL;
  v3 = ecl_make_cfun((cl_objectfn_fixed)LC72__pprint_logical_block_611,ECL_NIL,Cblock,2);
  T0 = v3;
 }
 value0 = si_pprint_logical_block_helper(6, T0, v2lambda_list, v1stream, _ecl_static_23, ECL_NIL, _ecl_static_24);
 return value0;
}
/*	local function PPRINT-LOGICAL-BLOCK-611                       */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC72__pprint_logical_block_611(cl_object v1, cl_object v2stream)
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v3;
  v3 = ecl_make_fixnum(0);
  {
   cl_object v4first;
   cl_object env1 = env0;
   env1 = ECL_NIL;
   CLV0 = env1 = CONS(ECL_SYM("REQUIRED",1008),env1); /*  STATE       */
   v4first = ECL_T;
L3:;
   if (!(v1==ECL_NIL)) { goto L5; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L5:;
   if ((v4first)!=ECL_NIL) { goto L7; }
   cl_write_char(2, CODE_CHAR(32), v2stream);
L7:;
   {
    cl_object v5arg;
    if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L11; }
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
L11:;
    v3 = ecl_plus(v3,ecl_make_fixnum(1));
    {
     cl_object v6;
     v6 = v1;
     if (Null(v6)) { goto L17; }
     {
      cl_object v7;
      v7 = ECL_CONS_CDR(v6);
      v1 = v7;
      v6 = ECL_CONS_CAR(v6);
     }
L17:;
     v5arg = v6;
    }
    if ((v4first)!=ECL_NIL) { goto L23; }
    if (!((v5arg)==(ECL_SYM("&OPTIONAL",11)))) { goto L25; }
    ECL_CONS_CAR(CLV0) = VV[161];
    cl_pprint_newline(2, VV[106], v2stream);
    goto L23;
L25:;
    if (!((v5arg)==(ECL_SYM("&REST",12)))) { goto L34; }
    goto L31;
    goto L32;
L34:;
    goto L32;
L32:;
    if (!((v5arg)==(ECL_SYM("&BODY",8)))) { goto L29; }
    goto L30;
L31:;
L30:;
    ECL_CONS_CAR(CLV0) = ECL_SYM("REQUIRED",1008);
    cl_pprint_newline(2, VV[106], v2stream);
    goto L23;
L29:;
    if (!((v5arg)==(ECL_SYM("&KEY",10)))) { goto L39; }
    ECL_CONS_CAR(CLV0) = ECL_SYM("KEY",1262);
    cl_pprint_newline(2, VV[106], v2stream);
    goto L23;
L39:;
    if (!((v5arg)==(ECL_SYM("&AUX",7)))) { goto L43; }
    ECL_CONS_CAR(CLV0) = VV[161];
    cl_pprint_newline(2, VV[106], v2stream);
    goto L23;
L43:;
    cl_pprint_newline(2, VV[109], v2stream);
L23:;
    if (!(ecl_eql(ECL_CONS_CAR(CLV0),ECL_SYM("REQUIRED",1008)))) { goto L47; }
    L73pprint_lambda_list(2, v2stream, v5arg);
    goto L9;
L47:;
    if (!(ecl_eql(ECL_CONS_CAR(CLV0),VV[161]))) { goto L54; }
    goto L51;
    goto L52;
L54:;
    goto L52;
L52:;
    if (!(ecl_eql(ECL_CONS_CAR(CLV0),ECL_SYM("KEY",1262)))) { goto L49; }
    goto L50;
L51:;
L50:;
    {cl_object v6;
     v6 = ECL_NIL;
     v6 = ecl_make_cclosure_va((cl_objectfn)LC71__pprint_logical_block_636,env1,Cblock);
     T0 = v6;
    }
    si_pprint_logical_block_helper(6, T0, v5arg, v2stream, _ecl_static_23, ECL_NIL, _ecl_static_24);
    goto L9;
L49:;
    si_ecase_error(ECL_CONS_CAR(CLV0), VV[166]);
   }
L9:;
   v4first = ECL_NIL;
   goto L3;
  }
 }
}
/*	closure PPRINT-LOGICAL-BLOCK-636                              */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC71__pprint_logical_block_636(cl_narg narg, cl_object v1, cl_object v2stream, ...)
{
 cl_object T0, T1;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  STATE           */
 { /* ... closure scanning finished */
TTL:
 {
  cl_object v3;
  v3 = ecl_make_fixnum(0);
  if (!(v1==ECL_NIL)) { goto L2; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  if (!((ECL_CONS_CAR(CLV0))==(ECL_SYM("KEY",1262)))) { goto L5; }
  {cl_object v4;
   v4 = ECL_NIL;
   v4 = ecl_make_cfun((cl_objectfn_fixed)LC70__pprint_logical_block_645,ECL_NIL,Cblock,2);
   T0 = v4;
  }
  if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L8; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L8:;
  v3 = ecl_plus(v3,ecl_make_fixnum(1));
  {
   cl_object v4;
   v4 = v1;
   if (Null(v4)) { goto L15; }
   {
    cl_object v5;
    v5 = ECL_CONS_CDR(v4);
    v1 = v5;
    v4 = ECL_CONS_CAR(v4);
   }
L15:;
   T1 = v4;
  }
  si_pprint_logical_block_helper(6, T0, T1, v2stream, _ecl_static_23, ECL_NIL, _ecl_static_24);
  goto L4;
L5:;
  if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L21; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L21:;
  v3 = ecl_plus(v3,ecl_make_fixnum(1));
  {
   cl_object v4;
   v4 = v1;
   if (Null(v4)) { goto L28; }
   {
    cl_object v5;
    v5 = ECL_CONS_CDR(v4);
    v1 = v5;
    v4 = ECL_CONS_CAR(v4);
   }
L28:;
   T0 = v4;
  }
  L73pprint_lambda_list(2, v2stream, T0);
L4:;
L34:;
  if (!(v1==ECL_NIL)) { goto L36; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L36:;
  cl_write_char(2, CODE_CHAR(32), v2stream);
  cl_pprint_newline(2, VV[106], v2stream);
  if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L40; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L40:;
  v3 = ecl_plus(v3,ecl_make_fixnum(1));
  {
   cl_object v4;
   v4 = v1;
   if (Null(v4)) { goto L47; }
   {
    cl_object v5;
    v5 = ECL_CONS_CDR(v4);
    v1 = v5;
    v4 = ECL_CONS_CAR(v4);
   }
L47:;
   T0 = v4;
  }
  si_write_object(T0, v2stream);
  goto L34;
 }
 }
}
/*	local function PPRINT-LOGICAL-BLOCK-645                       */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC70__pprint_logical_block_645(cl_object v1, cl_object v2stream)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v3;
  v3 = ecl_make_fixnum(0);
  if (!(v1==ECL_NIL)) { goto L2; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L5; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L5:;
  v3 = ecl_plus(v3,ecl_make_fixnum(1));
  {
   cl_object v4;
   v4 = v1;
   if (Null(v4)) { goto L12; }
   {
    cl_object v5;
    v5 = ECL_CONS_CDR(v4);
    v1 = v5;
    v4 = ECL_CONS_CAR(v4);
   }
L12:;
   T0 = v4;
  }
  si_write_object(T0, v2stream);
  if (!(v1==ECL_NIL)) { goto L18; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L18:;
  cl_write_char(2, CODE_CHAR(32), v2stream);
  cl_pprint_newline(2, VV[109], v2stream);
  if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L23; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L23:;
  v3 = ecl_plus(v3,ecl_make_fixnum(1));
  {
   cl_object v4;
   v4 = v1;
   if (Null(v4)) { goto L30; }
   {
    cl_object v5;
    v5 = ECL_CONS_CDR(v4);
    v1 = v5;
    v4 = ECL_CONS_CAR(v4);
   }
L30:;
   T0 = v4;
  }
  L73pprint_lambda_list(2, v2stream, T0);
L36:;
  if (!(v1==ECL_NIL)) { goto L38; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L38:;
  cl_write_char(2, CODE_CHAR(32), v2stream);
  cl_pprint_newline(2, VV[109], v2stream);
  if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L42; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L42:;
  v3 = ecl_plus(v3,ecl_make_fixnum(1));
  {
   cl_object v4;
   v4 = v1;
   if (Null(v4)) { goto L49; }
   {
    cl_object v5;
    v5 = ECL_CONS_CDR(v4);
    v1 = v5;
    v4 = ECL_CONS_CAR(v4);
   }
L49:;
   T0 = v4;
  }
  si_write_object(T0, v2stream);
  goto L36;
 }
}
/*	function definition for PPRINT-LAMBDA                         */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L75pprint_lambda(cl_narg narg, cl_object v1stream, cl_object v2list, ...)
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
  cl_object env1 = env0;
  env1 = ECL_NIL;
  CLV0 = env1 = CONS(v2list,env1);                /*  ARG             */
  {cl_object v3;
   v3 = ECL_NIL;
   v3 = ecl_make_cclosure_va((cl_objectfn)LC74__pprint_logical_block_684,env1,Cblock);
   T0 = v3;
  }
  si_pprint_logical_block_helper(6, T0, ECL_CONS_CAR(CLV0), v1stream, _ecl_static_23, ECL_NIL, _ecl_static_24);
 }
 value0 = ECL_NIL;
 cl_env_copy->nvalues = 1;
 return value0;
}
/*	closure PPRINT-LOGICAL-BLOCK-684                              */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC74__pprint_logical_block_684(cl_narg narg, cl_object v1, cl_object v2stream, ...)
{
 cl_object T0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  ARG             */
 { /* ... closure scanning finished */
TTL:
 {
  cl_object v3;
  v3 = ecl_make_fixnum(0);
  {
   cl_object v4args;
   v4args = ECL_CONS_CAR(CLV0);
   goto L5;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L3; }
   goto L4;
L5:;
   goto L7;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L3; }
   goto L4;
L7:;
   goto L9;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L3; }
   goto L4;
L9:;
   if (!(v4args==ECL_NIL)) { goto L3; }
L4:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L3:;
   if (!(v4args==ECL_NIL)) { goto L12; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_32, ECL_SYM("OFFSET",1279), ecl_make_fixnum(6));
L12:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L15; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L15:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L21; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L21:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L30; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L30:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
   goto L38;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L36; }
   goto L37;
L38:;
   goto L40;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L36; }
   goto L37;
L40:;
   goto L42;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L36; }
   goto L37;
L42:;
   if (!(v4args==ECL_NIL)) { goto L36; }
L37:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L36:;
   cl_pprint_indent(3, ECL_SYM("BLOCK",1202), ecl_make_fixnum(3), v2stream);
   cl_write_string(2, _ecl_static_33, v2stream);
   cl_pprint_newline(2, VV[109], v2stream);
   if (!(v4args==ECL_NIL)) { goto L48; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_32, ECL_SYM("OFFSET",1279), ecl_make_fixnum(39));
L48:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L51; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L51:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L57; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L57:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L66; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L66:;
    T0 = v5;
   }
   L73pprint_lambda_list(4, v2stream, T0, ECL_NIL, ECL_NIL);
   cl_pprint_indent(3, ECL_SYM("BLOCK",1202), ecl_make_fixnum(1), v2stream);
L73:;
   if (!(v4args==ECL_NIL)) { goto L75; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L75:;
   cl_write_string(2, _ecl_static_33, v2stream);
   cl_pprint_newline(2, VV[106], v2stream);
   if (!(v4args==ECL_NIL)) { goto L79; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_32, ECL_SYM("OFFSET",1279), ecl_make_fixnum(50));
L79:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L82; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L82:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L88; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L88:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L97; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L97:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
   goto L73;
  }
 }
 }
}
/*	function definition for PPRINT-BLOCK                          */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L77pprint_block(cl_narg narg, cl_object v1stream, cl_object v2list, ...)
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
  cl_object env1 = env0;
  env1 = ECL_NIL;
  CLV0 = env1 = CONS(v2list,env1);                /*  ARG             */
  {cl_object v3;
   v3 = ECL_NIL;
   v3 = ecl_make_cclosure_va((cl_objectfn)LC76__pprint_logical_block_723,env1,Cblock);
   T0 = v3;
  }
  si_pprint_logical_block_helper(6, T0, ECL_CONS_CAR(CLV0), v1stream, _ecl_static_23, ECL_NIL, _ecl_static_24);
 }
 value0 = ECL_NIL;
 cl_env_copy->nvalues = 1;
 return value0;
}
/*	closure PPRINT-LOGICAL-BLOCK-723                              */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC76__pprint_logical_block_723(cl_narg narg, cl_object v1, cl_object v2stream, ...)
{
 cl_object T0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  ARG             */
 { /* ... closure scanning finished */
TTL:
 {
  cl_object v3;
  v3 = ecl_make_fixnum(0);
  {
   cl_object v4args;
   v4args = ECL_CONS_CAR(CLV0);
   goto L5;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L3; }
   goto L4;
L5:;
   goto L7;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L3; }
   goto L4;
L7:;
   goto L9;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L3; }
   goto L4;
L9:;
   if (!(v4args==ECL_NIL)) { goto L3; }
L4:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L3:;
   if (!(v4args==ECL_NIL)) { goto L12; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_34, ECL_SYM("OFFSET",1279), ecl_make_fixnum(6));
L12:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L15; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L15:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L21; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L21:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L30; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L30:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
   goto L38;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L36; }
   goto L37;
L38:;
   goto L40;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L36; }
   goto L37;
L40:;
   goto L42;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L36; }
   goto L37;
L42:;
   if (!(v4args==ECL_NIL)) { goto L36; }
L37:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L36:;
   cl_pprint_indent(3, ECL_SYM("BLOCK",1202), ecl_make_fixnum(3), v2stream);
   cl_write_string(2, _ecl_static_33, v2stream);
   cl_pprint_newline(2, VV[109], v2stream);
   if (!(v4args==ECL_NIL)) { goto L48; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_34, ECL_SYM("OFFSET",1279), ecl_make_fixnum(17));
L48:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L51; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L51:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L57; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L57:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L66; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L66:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
   cl_pprint_indent(3, ECL_SYM("BLOCK",1202), ecl_make_fixnum(1), v2stream);
L73:;
   if (!(v4args==ECL_NIL)) { goto L75; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L75:;
   cl_write_string(2, _ecl_static_33, v2stream);
   cl_pprint_newline(2, VV[106], v2stream);
   if (!(v4args==ECL_NIL)) { goto L79; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_34, ECL_SYM("OFFSET",1279), ecl_make_fixnum(28));
L79:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L82; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L82:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L88; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L88:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L97; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L97:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
   goto L73;
  }
 }
 }
}
/*	function definition for PPRINT-FLET                           */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L81pprint_flet(cl_narg narg, cl_object v1stream, cl_object v2list, ...)
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
  cl_object env1 = env0;
  env1 = ECL_NIL;
  CLV0 = env1 = CONS(v2list,env1);                /*  ARG             */
  {cl_object v3;
   v3 = ECL_NIL;
   v3 = ecl_make_cclosure_va((cl_objectfn)LC80__pprint_logical_block_762,env1,Cblock);
   T0 = v3;
  }
  si_pprint_logical_block_helper(6, T0, ECL_CONS_CAR(CLV0), v1stream, _ecl_static_23, ECL_NIL, _ecl_static_24);
 }
 value0 = ECL_NIL;
 cl_env_copy->nvalues = 1;
 return value0;
}
/*	closure PPRINT-LOGICAL-BLOCK-762                              */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC80__pprint_logical_block_762(cl_narg narg, cl_object v1, cl_object v2stream, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  ARG             */
 { /* ... closure scanning finished */
TTL:
 {
  cl_object v3;
  v3 = ecl_make_fixnum(0);
  {
   cl_object v4args;
   v4args = ECL_CONS_CAR(CLV0);
   goto L5;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L3; }
   goto L4;
L5:;
   goto L7;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L3; }
   goto L4;
L7:;
   goto L9;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L3; }
   goto L4;
L9:;
   if (!(v4args==ECL_NIL)) { goto L3; }
L4:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L3:;
   if (!(v4args==ECL_NIL)) { goto L12; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_35, ECL_SYM("OFFSET",1279), ecl_make_fixnum(6));
L12:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L15; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L15:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L21; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L21:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L30; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L30:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
   goto L38;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L36; }
   goto L37;
L38:;
   goto L40;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L36; }
   goto L37;
L40:;
   goto L42;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L36; }
   goto L37;
L42:;
   if (!(v4args==ECL_NIL)) { goto L36; }
L37:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L36:;
   cl_write_string(2, _ecl_static_33, v2stream);
   cl_pprint_newline(2, VV[108], v2stream);
   {
    cl_object env1 = env0;
    if (!(v4args==ECL_NIL)) { goto L47; }
    cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_35, ECL_SYM("OFFSET",1279), ecl_make_fixnum(15));
L47:;
    if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L50; }
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
L50:;
    v3 = ecl_plus(v3,ecl_make_fixnum(1));
    {
     cl_object v5;
     v5 = v1;
     if (Null(v5)) { goto L56; }
     {
      cl_object v6;
      v6 = ECL_CONS_CDR(v5);
      v1 = v6;
      v5 = ECL_CONS_CAR(v5);
     }
L56:;
    }
    {
     cl_object v5;
     v5 = v4args;
     if (Null(v5)) { goto L65; }
     {
      cl_object v6;
      v6 = ECL_CONS_CDR(v5);
      v4args = v6;
      v5 = ECL_CONS_CAR(v5);
     }
L65:;
     T0 = v5;
    }
    CLV1 = env1 = CONS(T0,env1);                  /*  ARG             */
    {cl_object v5;
     v5 = ECL_NIL;
     v5 = ecl_make_cclosure_va((cl_objectfn)LC79__pprint_logical_block_791,env1,Cblock);
     T0 = v5;
    }
    si_pprint_logical_block_helper(6, T0, ECL_CONS_CAR(CLV1), v2stream, _ecl_static_23, ECL_NIL, _ecl_static_24);
   }
   cl_pprint_indent(3, ECL_SYM("BLOCK",1202), ecl_make_fixnum(1), v2stream);
   cl_pprint_newline(2, VV[57], v2stream);
L74:;
   if (!(v4args==ECL_NIL)) { goto L76; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L76:;
   if (!(v4args==ECL_NIL)) { goto L79; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_35, ECL_SYM("OFFSET",1279), ecl_make_fixnum(102));
L79:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L82; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L82:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L88; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L88:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L97; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L97:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
   goto L105;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L103; }
   goto L104;
L105:;
   goto L107;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L103; }
   goto L104;
L107:;
   goto L109;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L103; }
   goto L104;
L109:;
   if (!(v4args==ECL_NIL)) { goto L103; }
L104:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L103:;
   cl_write_string(2, _ecl_static_33, v2stream);
   cl_pprint_newline(2, VV[106], v2stream);
   goto L74;
  }
 }
 }
}
/*	closure PPRINT-LOGICAL-BLOCK-791                              */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC79__pprint_logical_block_791(cl_narg narg, cl_object v1, cl_object v2stream, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1, CLV2
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  ARG             */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
TTL:
 {
  cl_object v3;
  v3 = ecl_make_fixnum(0);
  {
   cl_object v4args;
   v4args = ECL_CONS_CAR(CLV1);
L3:;
   if (!(v4args==ECL_NIL)) { goto L5; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L5:;
   {
    cl_object env1 = env0;
    if (!(v4args==ECL_NIL)) { goto L8; }
    cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_35, ECL_SYM("OFFSET",1279), ecl_make_fixnum(21));
L8:;
    if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L11; }
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
L11:;
    v3 = ecl_plus(v3,ecl_make_fixnum(1));
    {
     cl_object v5;
     v5 = v1;
     if (Null(v5)) { goto L17; }
     {
      cl_object v6;
      v6 = ECL_CONS_CDR(v5);
      v1 = v6;
      v5 = ECL_CONS_CAR(v5);
     }
L17:;
    }
    {
     cl_object v5;
     v5 = v4args;
     if (Null(v5)) { goto L26; }
     {
      cl_object v6;
      v6 = ECL_CONS_CDR(v5);
      v4args = v6;
      v5 = ECL_CONS_CAR(v5);
     }
L26:;
     T0 = v5;
    }
    CLV2 = env1 = CONS(T0,env1);                  /*  ARG             */
    {cl_object v5;
     v5 = ECL_NIL;
     v5 = ecl_make_cclosure_va((cl_objectfn)LC78__pprint_logical_block_809,env1,Cblock);
     T0 = v5;
    }
    si_pprint_logical_block_helper(6, T0, ECL_CONS_CAR(CLV2), v2stream, _ecl_static_23, ECL_NIL, _ecl_static_24);
   }
   goto L35;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L33; }
   goto L34;
L35:;
   goto L37;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L33; }
   goto L34;
L37:;
   goto L39;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L33; }
   goto L34;
L39:;
   if (!(v4args==ECL_NIL)) { goto L33; }
L34:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L33:;
   cl_write_string(2, _ecl_static_33, v2stream);
   cl_pprint_newline(2, VV[106], v2stream);
   goto L3;
  }
 }
 }
}
/*	closure PPRINT-LOGICAL-BLOCK-809                              */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC78__pprint_logical_block_809(cl_narg narg, cl_object v1, cl_object v2stream, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1, CLV2
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV2 = env0;                                     /*  ARG             */
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
TTL:
 {
  cl_object v3;
  v3 = ecl_make_fixnum(0);
  {
   cl_object v4args;
   v4args = ECL_CONS_CAR(CLV2);
   goto L5;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L3; }
   goto L4;
L5:;
   goto L7;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L3; }
   goto L4;
L7:;
   goto L9;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L3; }
   goto L4;
L9:;
   if (!(v4args==ECL_NIL)) { goto L3; }
L4:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L3:;
   if (!(v4args==ECL_NIL)) { goto L12; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_35, ECL_SYM("OFFSET",1279), ecl_make_fixnum(25));
L12:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L15; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L15:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L21; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L21:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L30; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L30:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
   goto L38;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L36; }
   goto L37;
L38:;
   goto L40;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L36; }
   goto L37;
L40:;
   goto L42;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L36; }
   goto L37;
L42:;
   if (!(v4args==ECL_NIL)) { goto L36; }
L37:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L36:;
   cl_pprint_indent(3, ECL_SYM("BLOCK",1202), ecl_make_fixnum(3), v2stream);
   cl_write_string(2, _ecl_static_33, v2stream);
   cl_pprint_newline(2, VV[109], v2stream);
   if (!(v4args==ECL_NIL)) { goto L48; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_35, ECL_SYM("OFFSET",1279), ecl_make_fixnum(58));
L48:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L51; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L51:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L57; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L57:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L66; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L66:;
    T0 = v5;
   }
   L73pprint_lambda_list(4, v2stream, T0, ECL_NIL, ECL_NIL);
   cl_pprint_indent(3, ECL_SYM("BLOCK",1202), ecl_make_fixnum(1), v2stream);
   cl_pprint_newline(2, VV[57], v2stream);
L74:;
   if (!(v4args==ECL_NIL)) { goto L76; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L76:;
   if (!(v4args==ECL_NIL)) { goto L79; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_35, ECL_SYM("OFFSET",1279), ecl_make_fixnum(70));
L79:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L82; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L82:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L88; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L88:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L97; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L97:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
   goto L105;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L103; }
   goto L104;
L105:;
   goto L107;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L103; }
   goto L104;
L107:;
   goto L109;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L103; }
   goto L104;
L109:;
   if (!(v4args==ECL_NIL)) { goto L103; }
L104:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L103:;
   cl_write_string(2, _ecl_static_33, v2stream);
   cl_pprint_newline(2, VV[106], v2stream);
   goto L74;
  }
 }
 }
}
/*	function definition for PPRINT-LET                            */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L85pprint_let(cl_narg narg, cl_object v1stream, cl_object v2list, ...)
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
  cl_object env1 = env0;
  env1 = ECL_NIL;
  CLV0 = env1 = CONS(v2list,env1);                /*  ARG             */
  {cl_object v3;
   v3 = ECL_NIL;
   v3 = ecl_make_cclosure_va((cl_objectfn)LC84__pprint_logical_block_864,env1,Cblock);
   T0 = v3;
  }
  si_pprint_logical_block_helper(6, T0, ECL_CONS_CAR(CLV0), v1stream, _ecl_static_23, ECL_NIL, _ecl_static_24);
 }
 value0 = ECL_NIL;
 cl_env_copy->nvalues = 1;
 return value0;
}
/*	closure PPRINT-LOGICAL-BLOCK-864                              */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC84__pprint_logical_block_864(cl_narg narg, cl_object v1, cl_object v2stream, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  ARG             */
 { /* ... closure scanning finished */
TTL:
 {
  cl_object v3;
  v3 = ecl_make_fixnum(0);
  {
   cl_object v4args;
   v4args = ECL_CONS_CAR(CLV0);
   goto L5;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L3; }
   goto L4;
L5:;
   goto L7;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L3; }
   goto L4;
L7:;
   goto L9;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L3; }
   goto L4;
L9:;
   if (!(v4args==ECL_NIL)) { goto L3; }
L4:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L3:;
   if (!(v4args==ECL_NIL)) { goto L12; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_36, ECL_SYM("OFFSET",1279), ecl_make_fixnum(6));
L12:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L15; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L15:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L21; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L21:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L30; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L30:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
   goto L38;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L36; }
   goto L37;
L38:;
   goto L40;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L36; }
   goto L37;
L40:;
   goto L42;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L36; }
   goto L37;
L42:;
   if (!(v4args==ECL_NIL)) { goto L36; }
L37:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L36:;
   cl_write_string(2, _ecl_static_33, v2stream);
   cl_pprint_newline(2, VV[108], v2stream);
   {
    cl_object env1 = env0;
    if (!(v4args==ECL_NIL)) { goto L47; }
    cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_36, ECL_SYM("OFFSET",1279), ecl_make_fixnum(15));
L47:;
    if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L50; }
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
L50:;
    v3 = ecl_plus(v3,ecl_make_fixnum(1));
    {
     cl_object v5;
     v5 = v1;
     if (Null(v5)) { goto L56; }
     {
      cl_object v6;
      v6 = ECL_CONS_CDR(v5);
      v1 = v6;
      v5 = ECL_CONS_CAR(v5);
     }
L56:;
    }
    {
     cl_object v5;
     v5 = v4args;
     if (Null(v5)) { goto L65; }
     {
      cl_object v6;
      v6 = ECL_CONS_CDR(v5);
      v4args = v6;
      v5 = ECL_CONS_CAR(v5);
     }
L65:;
     T0 = v5;
    }
    CLV1 = env1 = CONS(T0,env1);                  /*  ARG             */
    {cl_object v5;
     v5 = ECL_NIL;
     v5 = ecl_make_cclosure_va((cl_objectfn)LC83__pprint_logical_block_893,env1,Cblock);
     T0 = v5;
    }
    si_pprint_logical_block_helper(6, T0, ECL_CONS_CAR(CLV1), v2stream, _ecl_static_23, ECL_NIL, _ecl_static_24);
   }
   cl_pprint_indent(3, ECL_SYM("BLOCK",1202), ecl_make_fixnum(1), v2stream);
   cl_pprint_newline(2, VV[57], v2stream);
L74:;
   if (!(v4args==ECL_NIL)) { goto L76; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L76:;
   if (!(v4args==ECL_NIL)) { goto L79; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_36, ECL_SYM("OFFSET",1279), ecl_make_fixnum(60));
L79:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L82; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L82:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L88; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L88:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L97; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L97:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
   goto L105;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L103; }
   goto L104;
L105:;
   goto L107;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L103; }
   goto L104;
L107:;
   goto L109;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L103; }
   goto L104;
L109:;
   if (!(v4args==ECL_NIL)) { goto L103; }
L104:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L103:;
   cl_write_string(2, _ecl_static_33, v2stream);
   cl_pprint_newline(2, VV[106], v2stream);
   goto L74;
  }
 }
 }
}
/*	closure PPRINT-LOGICAL-BLOCK-893                              */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC83__pprint_logical_block_893(cl_narg narg, cl_object v1, cl_object v2stream, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1, CLV2
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  ARG             */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
TTL:
 {
  cl_object v3;
  v3 = ecl_make_fixnum(0);
  {
   cl_object v4args;
   v4args = ECL_CONS_CAR(CLV1);
L3:;
   if (!(v4args==ECL_NIL)) { goto L5; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L5:;
   {
    cl_object env1 = env0;
    if (!(v4args==ECL_NIL)) { goto L8; }
    cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_36, ECL_SYM("OFFSET",1279), ecl_make_fixnum(21));
L8:;
    if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L11; }
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
L11:;
    v3 = ecl_plus(v3,ecl_make_fixnum(1));
    {
     cl_object v5;
     v5 = v1;
     if (Null(v5)) { goto L17; }
     {
      cl_object v6;
      v6 = ECL_CONS_CDR(v5);
      v1 = v6;
      v5 = ECL_CONS_CAR(v5);
     }
L17:;
    }
    {
     cl_object v5;
     v5 = v4args;
     if (Null(v5)) { goto L26; }
     {
      cl_object v6;
      v6 = ECL_CONS_CDR(v5);
      v4args = v6;
      v5 = ECL_CONS_CAR(v5);
     }
L26:;
     T0 = v5;
    }
    CLV2 = env1 = CONS(T0,env1);                  /*  ARG             */
    {cl_object v5;
     v5 = ECL_NIL;
     v5 = ecl_make_cclosure_va((cl_objectfn)LC82__pprint_logical_block_911,env1,Cblock);
     T0 = v5;
    }
    si_pprint_logical_block_helper(6, T0, ECL_CONS_CAR(CLV2), v2stream, _ecl_static_23, ECL_NIL, _ecl_static_24);
   }
   goto L35;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L33; }
   goto L34;
L35:;
   goto L37;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L33; }
   goto L34;
L37:;
   goto L39;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L33; }
   goto L34;
L39:;
   if (!(v4args==ECL_NIL)) { goto L33; }
L34:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L33:;
   cl_write_string(2, _ecl_static_33, v2stream);
   cl_pprint_newline(2, VV[106], v2stream);
   goto L3;
  }
 }
 }
}
/*	closure PPRINT-LOGICAL-BLOCK-911                              */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC82__pprint_logical_block_911(cl_narg narg, cl_object v1, cl_object v2stream, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1, CLV2
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV2 = env0;                                     /*  ARG             */
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
TTL:
 {
  cl_object v3;
  v3 = ecl_make_fixnum(0);
  {
   cl_object v4args;
   v4args = ECL_CONS_CAR(CLV2);
   goto L5;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L3; }
   goto L4;
L5:;
   goto L7;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L3; }
   goto L4;
L7:;
   goto L9;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L3; }
   goto L4;
L9:;
   if (!(v4args==ECL_NIL)) { goto L3; }
L4:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L3:;
   if (!(v4args==ECL_NIL)) { goto L12; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_36, ECL_SYM("OFFSET",1279), ecl_make_fixnum(25));
L12:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L15; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L15:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L21; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L21:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L30; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L30:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
L36:;
   if (!(v4args==ECL_NIL)) { goto L38; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L38:;
   cl_write_string(2, _ecl_static_33, v2stream);
   cl_pprint_newline(2, VV[106], v2stream);
   if (!(v4args==ECL_NIL)) { goto L42; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_36, ECL_SYM("OFFSET",1279), ecl_make_fixnum(33));
L42:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L45; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L45:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L51; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L51:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L60; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L60:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
   goto L36;
  }
 }
 }
}
/*	function definition for PPRINT-PROGN                          */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L87pprint_progn(cl_narg narg, cl_object v1stream, cl_object v2list, ...)
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
  cl_object env1 = env0;
  env1 = ECL_NIL;
  CLV0 = env1 = CONS(v2list,env1);                /*  ARG             */
  {cl_object v3;
   v3 = ECL_NIL;
   v3 = ecl_make_cclosure_va((cl_objectfn)LC86__pprint_logical_block_954,env1,Cblock);
   T0 = v3;
  }
  si_pprint_logical_block_helper(6, T0, ECL_CONS_CAR(CLV0), v1stream, _ecl_static_23, ECL_NIL, _ecl_static_24);
 }
 value0 = ECL_NIL;
 cl_env_copy->nvalues = 1;
 return value0;
}
/*	closure PPRINT-LOGICAL-BLOCK-954                              */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC86__pprint_logical_block_954(cl_narg narg, cl_object v1, cl_object v2stream, ...)
{
 cl_object T0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  ARG             */
 { /* ... closure scanning finished */
TTL:
 {
  cl_object v3;
  v3 = ecl_make_fixnum(0);
  {
   cl_object v4args;
   v4args = ECL_CONS_CAR(CLV0);
   goto L5;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L3; }
   goto L4;
L5:;
   goto L7;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L3; }
   goto L4;
L7:;
   goto L9;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L3; }
   goto L4;
L9:;
   if (!(v4args==ECL_NIL)) { goto L3; }
L4:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L3:;
   if (!(v4args==ECL_NIL)) { goto L12; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_37, ECL_SYM("OFFSET",1279), ecl_make_fixnum(6));
L12:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L15; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L15:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L21; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L21:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L30; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L30:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
L36:;
   if (!(v4args==ECL_NIL)) { goto L38; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L38:;
   cl_write_string(2, _ecl_static_33, v2stream);
   cl_pprint_newline(2, VV[106], v2stream);
   if (!(v4args==ECL_NIL)) { goto L42; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_37, ECL_SYM("OFFSET",1279), ecl_make_fixnum(14));
L42:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L45; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L45:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L51; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L51:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L60; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L60:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
   goto L36;
  }
 }
 }
}
/*	function definition for PPRINT-PROGV                          */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L89pprint_progv(cl_narg narg, cl_object v1stream, cl_object v2list, ...)
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
  cl_object env1 = env0;
  env1 = ECL_NIL;
  CLV0 = env1 = CONS(v2list,env1);                /*  ARG             */
  {cl_object v3;
   v3 = ECL_NIL;
   v3 = ecl_make_cclosure_va((cl_objectfn)LC88__pprint_logical_block_984,env1,Cblock);
   T0 = v3;
  }
  si_pprint_logical_block_helper(6, T0, ECL_CONS_CAR(CLV0), v1stream, _ecl_static_23, ECL_NIL, _ecl_static_24);
 }
 value0 = ECL_NIL;
 cl_env_copy->nvalues = 1;
 return value0;
}
/*	closure PPRINT-LOGICAL-BLOCK-984                              */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC88__pprint_logical_block_984(cl_narg narg, cl_object v1, cl_object v2stream, ...)
{
 cl_object T0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  ARG             */
 { /* ... closure scanning finished */
TTL:
 {
  cl_object v3;
  v3 = ecl_make_fixnum(0);
  {
   cl_object v4args;
   v4args = ECL_CONS_CAR(CLV0);
   goto L5;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L3; }
   goto L4;
L5:;
   goto L7;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L3; }
   goto L4;
L7:;
   goto L9;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L3; }
   goto L4;
L9:;
   if (!(v4args==ECL_NIL)) { goto L3; }
L4:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L3:;
   if (!(v4args==ECL_NIL)) { goto L12; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_38, ECL_SYM("OFFSET",1279), ecl_make_fixnum(6));
L12:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L15; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L15:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L21; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L21:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L30; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L30:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
   goto L38;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L36; }
   goto L37;
L38:;
   goto L40;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L36; }
   goto L37;
L40:;
   goto L42;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L36; }
   goto L37;
L42:;
   if (!(v4args==ECL_NIL)) { goto L36; }
L37:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L36:;
   cl_pprint_indent(3, ECL_SYM("BLOCK",1202), ecl_make_fixnum(3), v2stream);
   cl_write_string(2, _ecl_static_33, v2stream);
   cl_pprint_newline(2, VV[106], v2stream);
   if (!(v4args==ECL_NIL)) { goto L48; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_38, ECL_SYM("OFFSET",1279), ecl_make_fixnum(16));
L48:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L51; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L51:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L57; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L57:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L66; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L66:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
   goto L74;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L72; }
   goto L73;
L74:;
   goto L76;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L72; }
   goto L73;
L76:;
   goto L78;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L72; }
   goto L73;
L78:;
   if (!(v4args==ECL_NIL)) { goto L72; }
L73:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L72:;
   cl_write_string(2, _ecl_static_33, v2stream);
   cl_pprint_newline(2, VV[106], v2stream);
   if (!(v4args==ECL_NIL)) { goto L83; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_38, ECL_SYM("OFFSET",1279), ecl_make_fixnum(23));
L83:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L86; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L86:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L92; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L92:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L101; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L101:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
   goto L109;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L107; }
   goto L108;
L109:;
   goto L111;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L107; }
   goto L108;
L111:;
   goto L113;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L107; }
   goto L108;
L113:;
   if (!(v4args==ECL_NIL)) { goto L107; }
L108:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L107:;
   cl_pprint_indent(3, ECL_SYM("BLOCK",1202), ecl_make_fixnum(1), v2stream);
L116:;
   if (!(v4args==ECL_NIL)) { goto L118; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L118:;
   cl_write_string(2, _ecl_static_33, v2stream);
   cl_pprint_newline(2, VV[106], v2stream);
   if (!(v4args==ECL_NIL)) { goto L122; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_38, ECL_SYM("OFFSET",1279), ecl_make_fixnum(36));
L122:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L125; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L125:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L131; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L131:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L140; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L140:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
   goto L116;
  }
 }
 }
}
/*	function definition for PPRINT-QUOTE                          */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L90pprint_quote(cl_narg narg, cl_object v1stream, cl_object v2list, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 if (!(ECL_CONSP(v2list))) { goto L1; }
 T0 = _ecl_cdr(v2list);
 if (!(ECL_CONSP(T0))) { goto L1; }
 T0 = _ecl_cddr(v2list);
 if (!(T0==ECL_NIL)) { goto L1; }
 {
  cl_object v3;
  v3 = _ecl_car(v2list);
  if (!((v3)==(ECL_SYM("FUNCTION",396)))) { goto L6; }
  cl_write_string(2, _ecl_static_39, v1stream);
  T0 = _ecl_cadr(v2list);
  value0 = si_write_object(T0, v1stream);
  return value0;
L6:;
  if (!((v3)==(ECL_SYM("QUOTE",679)))) { goto L9; }
  cl_write_char(2, CODE_CHAR(39), v1stream);
  T0 = _ecl_cadr(v2list);
  value0 = si_write_object(T0, v1stream);
  return value0;
L9:;
  value0 = cl_pprint_fill(2, v1stream, v2list);
  return value0;
 }
L1:;
 value0 = cl_pprint_fill(2, v1stream, v2list);
 return value0;
}
/*	function definition for PPRINT-SETQ                           */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L92pprint_setq(cl_narg narg, cl_object v1stream, cl_object v2list, ...)
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 env0 = ECL_NIL;
 CLV0 = env0 = CONS(v2list,env0);                 /*  LIST            */
 {cl_object v3;
  v3 = ECL_NIL;
  v3 = ecl_make_cclosure_va((cl_objectfn)LC91__pprint_logical_block_1033,env0,Cblock);
  T0 = v3;
 }
 value0 = si_pprint_logical_block_helper(6, T0, ECL_CONS_CAR(CLV0), v1stream, _ecl_static_23, ECL_NIL, _ecl_static_24);
 return value0;
}
/*	closure PPRINT-LOGICAL-BLOCK-1033                             */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC91__pprint_logical_block_1033(cl_narg narg, cl_object v1, cl_object v2stream, ...)
{
 cl_object T0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  LIST            */
 { /* ... closure scanning finished */
TTL:
 {
  cl_object v3;
  v3 = ecl_make_fixnum(0);
  if (!(v1==ECL_NIL)) { goto L2; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L5; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L5:;
  v3 = ecl_plus(v3,ecl_make_fixnum(1));
  {
   cl_object v4;
   v4 = v1;
   if (Null(v4)) { goto L12; }
   {
    cl_object v5;
    v5 = ECL_CONS_CDR(v4);
    v1 = v5;
    v4 = ECL_CONS_CAR(v4);
   }
L12:;
   T0 = v4;
  }
  si_write_object(T0, v2stream);
  if (!(v1==ECL_NIL)) { goto L18; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L18:;
  cl_write_char(2, CODE_CHAR(32), v2stream);
  cl_pprint_newline(2, VV[108], v2stream);
  T0 = _ecl_cdr(ECL_CONS_CAR(CLV0));
  if (!(ECL_CONSP(T0))) { goto L22; }
  T0 = _ecl_cddr(ECL_CONS_CAR(CLV0));
  if (!(ECL_CONSP(T0))) { goto L22; }
L25:;
  cl_pprint_indent(3, VV[63], ecl_make_fixnum(2), v2stream);
  if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L29; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L29:;
  v3 = ecl_plus(v3,ecl_make_fixnum(1));
  {
   cl_object v4;
   v4 = v1;
   if (Null(v4)) { goto L36; }
   {
    cl_object v5;
    v5 = ECL_CONS_CDR(v4);
    v1 = v5;
    v4 = ECL_CONS_CAR(v4);
   }
L36:;
   T0 = v4;
  }
  si_write_object(T0, v2stream);
  if (!(v1==ECL_NIL)) { goto L42; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L42:;
  cl_write_char(2, CODE_CHAR(32), v2stream);
  cl_pprint_newline(2, VV[106], v2stream);
  cl_pprint_indent(3, VV[63], ecl_make_fixnum(-2), v2stream);
  if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L48; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L48:;
  v3 = ecl_plus(v3,ecl_make_fixnum(1));
  {
   cl_object v4;
   v4 = v1;
   if (Null(v4)) { goto L55; }
   {
    cl_object v5;
    v5 = ECL_CONS_CDR(v4);
    v1 = v5;
    v4 = ECL_CONS_CAR(v4);
   }
L55:;
   T0 = v4;
  }
  si_write_object(T0, v2stream);
  if (!(v1==ECL_NIL)) { goto L61; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L61:;
  cl_write_char(2, CODE_CHAR(32), v2stream);
  cl_pprint_newline(2, VV[106], v2stream);
  goto L25;
L22:;
  cl_pprint_indent(3, VV[63], ecl_make_fixnum(0), v2stream);
  if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L67; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L67:;
  v3 = ecl_plus(v3,ecl_make_fixnum(1));
  {
   cl_object v4;
   v4 = v1;
   if (Null(v4)) { goto L74; }
   {
    cl_object v5;
    v5 = ECL_CONS_CDR(v4);
    v1 = v5;
    v4 = ECL_CONS_CAR(v4);
   }
L74:;
   T0 = v4;
  }
  si_write_object(T0, v2stream);
  if (!(v1==ECL_NIL)) { goto L80; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L80:;
  cl_write_char(2, CODE_CHAR(32), v2stream);
  cl_pprint_newline(2, VV[106], v2stream);
  if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L84; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L84:;
  v3 = ecl_plus(v3,ecl_make_fixnum(1));
  {
   cl_object v4;
   v4 = v1;
   if (Null(v4)) { goto L91; }
   {
    cl_object v5;
    v5 = ECL_CONS_CDR(v4);
    v1 = v5;
    v4 = ECL_CONS_CAR(v4);
   }
L91:;
   T0 = v4;
  }
  value0 = si_write_object(T0, v2stream);
  return value0;
 }
 }
}
/*	function definition for PPRINT-TAGBODY                        */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L94pprint_tagbody(cl_narg narg, cl_object v1stream, cl_object v2list, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {cl_object v3;
  v3 = ECL_NIL;
  v3 = ecl_make_cfun((cl_objectfn_fixed)LC93__pprint_logical_block_1063,ECL_NIL,Cblock,2);
  T0 = v3;
 }
 value0 = si_pprint_logical_block_helper(6, T0, v2list, v1stream, _ecl_static_23, ECL_NIL, _ecl_static_24);
 return value0;
}
/*	local function PPRINT-LOGICAL-BLOCK-1063                      */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC93__pprint_logical_block_1063(cl_object v1, cl_object v2stream)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v3;
  v3 = ecl_make_fixnum(0);
  if (!(v1==ECL_NIL)) { goto L2; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L5; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L5:;
  v3 = ecl_plus(v3,ecl_make_fixnum(1));
  {
   cl_object v4;
   v4 = v1;
   if (Null(v4)) { goto L12; }
   {
    cl_object v5;
    v5 = ECL_CONS_CDR(v4);
    v1 = v5;
    v4 = ECL_CONS_CAR(v4);
   }
L12:;
   T0 = v4;
  }
  si_write_object(T0, v2stream);
L18:;
  if (!(v1==ECL_NIL)) { goto L20; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L20:;
  cl_write_char(2, CODE_CHAR(32), v2stream);
  {
   cl_object v4form_or_tag;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L24; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L24:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L30; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L30:;
    v4form_or_tag = v5;
   }
   {
    cl_fixnum v5;
    if (!(ECL_ATOM(v4form_or_tag))) { goto L38; }
    v5 = 0;
    goto L37;
L38:;
    v5 = 1;
L37:;
    cl_pprint_indent(3, ECL_SYM("BLOCK",1202), ecl_make_fixnum(v5), v2stream);
   }
   cl_pprint_newline(2, VV[106], v2stream);
   si_write_object(v4form_or_tag, v2stream);
  }
  goto L18;
 }
}
/*	function definition for PPRINT-CASE                           */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L97pprint_case(cl_narg narg, cl_object v1stream, cl_object v2list, ...)
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
  cl_object env1 = env0;
  env1 = ECL_NIL;
  CLV0 = env1 = CONS(v2list,env1);                /*  ARG             */
  {cl_object v3;
   v3 = ECL_NIL;
   v3 = ecl_make_cclosure_va((cl_objectfn)LC96__pprint_logical_block_1084,env1,Cblock);
   T0 = v3;
  }
  si_pprint_logical_block_helper(6, T0, ECL_CONS_CAR(CLV0), v1stream, _ecl_static_23, ECL_NIL, _ecl_static_24);
 }
 value0 = ECL_NIL;
 cl_env_copy->nvalues = 1;
 return value0;
}
/*	closure PPRINT-LOGICAL-BLOCK-1084                             */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC96__pprint_logical_block_1084(cl_narg narg, cl_object v1, cl_object v2stream, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  ARG             */
 { /* ... closure scanning finished */
TTL:
 {
  cl_object v3;
  v3 = ecl_make_fixnum(0);
  {
   cl_object v4args;
   v4args = ECL_CONS_CAR(CLV0);
   goto L5;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L3; }
   goto L4;
L5:;
   goto L7;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L3; }
   goto L4;
L7:;
   goto L9;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L3; }
   goto L4;
L9:;
   if (!(v4args==ECL_NIL)) { goto L3; }
L4:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L3:;
   if (!(v4args==ECL_NIL)) { goto L12; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_40, ECL_SYM("OFFSET",1279), ecl_make_fixnum(6));
L12:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L15; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L15:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L21; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L21:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L30; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L30:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
   goto L38;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L36; }
   goto L37;
L38:;
   goto L40;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L36; }
   goto L37;
L40:;
   goto L42;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L36; }
   goto L37;
L42:;
   if (!(v4args==ECL_NIL)) { goto L36; }
L37:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L36:;
   cl_write_string(2, _ecl_static_33, v2stream);
   cl_pprint_indent(3, ECL_SYM("BLOCK",1202), ecl_make_fixnum(3), v2stream);
   cl_pprint_newline(2, VV[109], v2stream);
   if (!(v4args==ECL_NIL)) { goto L48; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_40, ECL_SYM("OFFSET",1279), ecl_make_fixnum(17));
L48:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L51; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L51:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L57; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L57:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L66; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L66:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
   cl_pprint_indent(3, ECL_SYM("BLOCK",1202), ecl_make_fixnum(1), v2stream);
L73:;
   if (!(v4args==ECL_NIL)) { goto L75; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L75:;
   cl_write_string(2, _ecl_static_33, v2stream);
   cl_pprint_newline(2, VV[106], v2stream);
   {
    cl_object env1 = env0;
    if (!(v4args==ECL_NIL)) { goto L79; }
    cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_40, ECL_SYM("OFFSET",1279), ecl_make_fixnum(29));
L79:;
    if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L82; }
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
L82:;
    v3 = ecl_plus(v3,ecl_make_fixnum(1));
    {
     cl_object v5;
     v5 = v1;
     if (Null(v5)) { goto L88; }
     {
      cl_object v6;
      v6 = ECL_CONS_CDR(v5);
      v1 = v6;
      v5 = ECL_CONS_CAR(v5);
     }
L88:;
    }
    {
     cl_object v5;
     v5 = v4args;
     if (Null(v5)) { goto L97; }
     {
      cl_object v6;
      v6 = ECL_CONS_CDR(v5);
      v4args = v6;
      v5 = ECL_CONS_CAR(v5);
     }
L97:;
     T0 = v5;
    }
    CLV1 = env1 = CONS(T0,env1);                  /*  ARG             */
    {cl_object v5;
     v5 = ECL_NIL;
     v5 = ecl_make_cclosure_va((cl_objectfn)LC95__pprint_logical_block_1120,env1,Cblock);
     T0 = v5;
    }
    si_pprint_logical_block_helper(6, T0, ECL_CONS_CAR(CLV1), v2stream, _ecl_static_23, ECL_NIL, _ecl_static_24);
   }
   goto L73;
  }
 }
 }
}
/*	closure PPRINT-LOGICAL-BLOCK-1120                             */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC95__pprint_logical_block_1120(cl_narg narg, cl_object v1, cl_object v2stream, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  ARG             */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
TTL:
 {
  cl_object v3;
  v3 = ecl_make_fixnum(0);
  {
   cl_object v4args;
   v4args = ECL_CONS_CAR(CLV1);
   goto L5;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L3; }
   goto L4;
L5:;
   goto L7;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L3; }
   goto L4;
L7:;
   goto L9;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L3; }
   goto L4;
L9:;
   if (!(v4args==ECL_NIL)) { goto L3; }
L4:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L3:;
   if (!(v4args==ECL_NIL)) { goto L12; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_40, ECL_SYM("OFFSET",1279), ecl_make_fixnum(49));
L12:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L15; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L15:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L21; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L21:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L30; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L30:;
    T0 = v5;
   }
   cl_pprint_fill(4, v2stream, T0, ECL_T, ECL_NIL);
   goto L38;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L36; }
   goto L37;
L38:;
   goto L40;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L36; }
   goto L37;
L40:;
   goto L42;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L36; }
   goto L37;
L42:;
   if (!(v4args==ECL_NIL)) { goto L36; }
L37:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L36:;
L44:;
   if (!(v4args==ECL_NIL)) { goto L46; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L46:;
   cl_write_string(2, _ecl_static_33, v2stream);
   cl_pprint_newline(2, VV[106], v2stream);
   if (!(v4args==ECL_NIL)) { goto L50; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_40, ECL_SYM("OFFSET",1279), ecl_make_fixnum(59));
L50:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L53; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L53:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L59; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L59:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L68; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L68:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
   goto L44;
  }
 }
 }
}
/*	function definition for PPRINT-DEFUN                          */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L99pprint_defun(cl_narg narg, cl_object v1stream, cl_object v2list, ...)
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
  cl_object env1 = env0;
  env1 = ECL_NIL;
  CLV0 = env1 = CONS(v2list,env1);                /*  ARG             */
  {cl_object v3;
   v3 = ECL_NIL;
   v3 = ecl_make_cclosure_va((cl_objectfn)LC98__pprint_logical_block_1153,env1,Cblock);
   T0 = v3;
  }
  si_pprint_logical_block_helper(6, T0, ECL_CONS_CAR(CLV0), v1stream, _ecl_static_23, ECL_NIL, _ecl_static_24);
 }
 value0 = ECL_NIL;
 cl_env_copy->nvalues = 1;
 return value0;
}
/*	closure PPRINT-LOGICAL-BLOCK-1153                             */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC98__pprint_logical_block_1153(cl_narg narg, cl_object v1, cl_object v2stream, ...)
{
 cl_object T0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  ARG             */
 { /* ... closure scanning finished */
TTL:
 {
  cl_object v3;
  v3 = ecl_make_fixnum(0);
  {
   cl_object v4args;
   v4args = ECL_CONS_CAR(CLV0);
   goto L5;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L3; }
   goto L4;
L5:;
   goto L7;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L3; }
   goto L4;
L7:;
   goto L9;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L3; }
   goto L4;
L9:;
   if (!(v4args==ECL_NIL)) { goto L3; }
L4:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L3:;
   if (!(v4args==ECL_NIL)) { goto L12; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_41, ECL_SYM("OFFSET",1279), ecl_make_fixnum(6));
L12:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L15; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L15:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L21; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L21:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L30; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L30:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
   goto L38;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L36; }
   goto L37;
L38:;
   goto L40;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L36; }
   goto L37;
L40:;
   goto L42;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L36; }
   goto L37;
L42:;
   if (!(v4args==ECL_NIL)) { goto L36; }
L37:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L36:;
   cl_write_string(2, _ecl_static_33, v2stream);
   cl_pprint_newline(2, VV[108], v2stream);
   cl_pprint_indent(3, VV[63], ecl_make_fixnum(0), v2stream);
   if (!(v4args==ECL_NIL)) { goto L48; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_41, ECL_SYM("OFFSET",1279), ecl_make_fixnum(17));
L48:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L51; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L51:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L57; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L57:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L66; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L66:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
   goto L74;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L72; }
   goto L73;
L74:;
   goto L76;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L72; }
   goto L73;
L76:;
   goto L78;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L72; }
   goto L73;
L78:;
   if (!(v4args==ECL_NIL)) { goto L72; }
L73:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L72:;
   cl_write_string(2, _ecl_static_33, v2stream);
   cl_pprint_newline(2, VV[109], v2stream);
   if (!(v4args==ECL_NIL)) { goto L83; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_41, ECL_SYM("OFFSET",1279), ecl_make_fixnum(47));
L83:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L86; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L86:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L92; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L92:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L101; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L101:;
    T0 = v5;
   }
   L73pprint_lambda_list(4, v2stream, T0, ECL_NIL, ECL_NIL);
   cl_pprint_indent(3, ECL_SYM("BLOCK",1202), ecl_make_fixnum(1), v2stream);
L108:;
   if (!(v4args==ECL_NIL)) { goto L110; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L110:;
   cl_write_string(2, _ecl_static_33, v2stream);
   cl_pprint_newline(2, VV[106], v2stream);
   if (!(v4args==ECL_NIL)) { goto L114; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_41, ECL_SYM("OFFSET",1279), ecl_make_fixnum(58));
L114:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L117; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L117:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L123; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L123:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L132; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L132:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
   goto L108;
  }
 }
 }
}
/*	function definition for PPRINT-DESTRUCTURING-BIND             */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L101pprint_destructuring_bind(cl_narg narg, cl_object v1stream, cl_object v2list, ...)
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
  cl_object env1 = env0;
  env1 = ECL_NIL;
  CLV0 = env1 = CONS(v2list,env1);                /*  ARG             */
  {cl_object v3;
   v3 = ECL_NIL;
   v3 = ecl_make_cclosure_va((cl_objectfn)LC100__pprint_logical_block_1201,env1,Cblock);
   T0 = v3;
  }
  si_pprint_logical_block_helper(6, T0, ECL_CONS_CAR(CLV0), v1stream, _ecl_static_23, ECL_NIL, _ecl_static_24);
 }
 value0 = ECL_NIL;
 cl_env_copy->nvalues = 1;
 return value0;
}
/*	closure PPRINT-LOGICAL-BLOCK-1201                             */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC100__pprint_logical_block_1201(cl_narg narg, cl_object v1, cl_object v2stream, ...)
{
 cl_object T0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  ARG             */
 { /* ... closure scanning finished */
TTL:
 {
  cl_object v3;
  v3 = ecl_make_fixnum(0);
  {
   cl_object v4args;
   v4args = ECL_CONS_CAR(CLV0);
   goto L5;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L3; }
   goto L4;
L5:;
   goto L7;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L3; }
   goto L4;
L7:;
   goto L9;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L3; }
   goto L4;
L9:;
   if (!(v4args==ECL_NIL)) { goto L3; }
L4:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L3:;
   if (!(v4args==ECL_NIL)) { goto L12; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_42, ECL_SYM("OFFSET",1279), ecl_make_fixnum(6));
L12:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L15; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L15:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L21; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L21:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L30; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L30:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
   goto L38;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L36; }
   goto L37;
L38:;
   goto L40;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L36; }
   goto L37;
L40:;
   goto L42;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L36; }
   goto L37;
L42:;
   if (!(v4args==ECL_NIL)) { goto L36; }
L37:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L36:;
   cl_pprint_indent(3, ECL_SYM("BLOCK",1202), ecl_make_fixnum(3), v2stream);
   cl_write_string(2, _ecl_static_33, v2stream);
   cl_pprint_newline(2, VV[106], v2stream);
   if (!(v4args==ECL_NIL)) { goto L48; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_42, ECL_SYM("OFFSET",1279), ecl_make_fixnum(39));
L48:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L51; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L51:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L57; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L57:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L66; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L66:;
    T0 = v5;
   }
   L73pprint_lambda_list(4, v2stream, T0, ECL_T, ECL_NIL);
   goto L74;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L72; }
   goto L73;
L74:;
   goto L76;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L72; }
   goto L73;
L76:;
   goto L78;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L72; }
   goto L73;
L78:;
   if (!(v4args==ECL_NIL)) { goto L72; }
L73:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L72:;
   cl_write_string(2, _ecl_static_33, v2stream);
   cl_pprint_newline(2, VV[106], v2stream);
   if (!(v4args==ECL_NIL)) { goto L83; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_42, ECL_SYM("OFFSET",1279), ecl_make_fixnum(46));
L83:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L86; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L86:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L92; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L92:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L101; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L101:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
   goto L109;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L107; }
   goto L108;
L109:;
   goto L111;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L107; }
   goto L108;
L111:;
   goto L113;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L107; }
   goto L108;
L113:;
   if (!(v4args==ECL_NIL)) { goto L107; }
L108:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L107:;
   cl_pprint_indent(3, ECL_SYM("BLOCK",1202), ecl_make_fixnum(1), v2stream);
L116:;
   if (!(v4args==ECL_NIL)) { goto L118; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L118:;
   cl_write_string(2, _ecl_static_33, v2stream);
   cl_pprint_newline(2, VV[106], v2stream);
   if (!(v4args==ECL_NIL)) { goto L122; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_42, ECL_SYM("OFFSET",1279), ecl_make_fixnum(59));
L122:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L125; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L125:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L131; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L131:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L140; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L140:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
   goto L116;
  }
 }
 }
}
/*	function definition for PPRINT-DO                             */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L105pprint_do(cl_narg narg, cl_object v1stream, cl_object v2list, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {cl_object v3;
  v3 = ECL_NIL;
  v3 = ecl_make_cfun((cl_objectfn_fixed)LC104__pprint_logical_block_1249,ECL_NIL,Cblock,2);
  T0 = v3;
 }
 value0 = si_pprint_logical_block_helper(6, T0, v2list, v1stream, _ecl_static_23, ECL_NIL, _ecl_static_24);
 return value0;
}
/*	local function PPRINT-LOGICAL-BLOCK-1249                      */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC104__pprint_logical_block_1249(cl_object v1, cl_object v2stream)
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v3;
  v3 = ecl_make_fixnum(0);
  if (!(v1==ECL_NIL)) { goto L2; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L5; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L5:;
  v3 = ecl_plus(v3,ecl_make_fixnum(1));
  {
   cl_object v4;
   v4 = v1;
   if (Null(v4)) { goto L12; }
   {
    cl_object v5;
    v5 = ECL_CONS_CDR(v4);
    v1 = v5;
    v4 = ECL_CONS_CAR(v4);
   }
L12:;
   T0 = v4;
  }
  si_write_object(T0, v2stream);
  if (!(v1==ECL_NIL)) { goto L18; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L18:;
  cl_write_char(2, CODE_CHAR(32), v2stream);
  cl_pprint_indent(3, VV[63], ecl_make_fixnum(0), v2stream);
  {
   cl_object v4;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L24; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L24:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L30; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L30:;
    v4 = v5;
   }
   {
    cl_object env1 = env0;
    env1 = ECL_NIL;
    CLV0 = env1 = CONS(v4,env1);                  /*  ARG             */
    {cl_object v5;
     v5 = ECL_NIL;
     v5 = ecl_make_cclosure_va((cl_objectfn)LC103__pprint_logical_block_1269,env1,Cblock);
     T0 = v5;
    }
    si_pprint_logical_block_helper(6, T0, ECL_CONS_CAR(CLV0), v2stream, _ecl_static_23, ECL_NIL, _ecl_static_24);
   }
  }
  if (!(v1==ECL_NIL)) { goto L38; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L38:;
  cl_write_char(2, CODE_CHAR(32), v2stream);
  cl_pprint_newline(2, VV[106], v2stream);
  if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L43; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L43:;
  v3 = ecl_plus(v3,ecl_make_fixnum(1));
  {
   cl_object v4;
   v4 = v1;
   if (Null(v4)) { goto L50; }
   {
    cl_object v5;
    v5 = ECL_CONS_CDR(v4);
    v1 = v5;
    v4 = ECL_CONS_CAR(v4);
   }
L50:;
   T0 = v4;
  }
  cl_pprint_linear(2, v2stream, T0);
L56:;
  if (!(v1==ECL_NIL)) { goto L58; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L58:;
  cl_write_char(2, CODE_CHAR(32), v2stream);
  {
   cl_object v4form_or_tag;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L62; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L62:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L68; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L68:;
    v4form_or_tag = v5;
   }
   {
    cl_fixnum v5;
    if (!(ECL_ATOM(v4form_or_tag))) { goto L76; }
    v5 = 0;
    goto L75;
L76:;
    v5 = 1;
L75:;
    cl_pprint_indent(3, ECL_SYM("BLOCK",1202), ecl_make_fixnum(v5), v2stream);
   }
   cl_pprint_newline(2, VV[106], v2stream);
   si_write_object(v4form_or_tag, v2stream);
  }
  goto L56;
 }
}
/*	closure PPRINT-LOGICAL-BLOCK-1269                             */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC103__pprint_logical_block_1269(cl_narg narg, cl_object v1, cl_object v2stream, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  ARG             */
 { /* ... closure scanning finished */
TTL:
 {
  cl_object v3;
  v3 = ecl_make_fixnum(0);
  {
   cl_object v4args;
   v4args = ECL_CONS_CAR(CLV0);
L3:;
   if (!(v4args==ECL_NIL)) { goto L5; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L5:;
   {
    cl_object env1 = env0;
    if (!(v4args==ECL_NIL)) { goto L8; }
    cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_43, ECL_SYM("OFFSET",1279), ecl_make_fixnum(8));
L8:;
    if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L11; }
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
L11:;
    v3 = ecl_plus(v3,ecl_make_fixnum(1));
    {
     cl_object v5;
     v5 = v1;
     if (Null(v5)) { goto L17; }
     {
      cl_object v6;
      v6 = ECL_CONS_CDR(v5);
      v1 = v6;
      v5 = ECL_CONS_CAR(v5);
     }
L17:;
    }
    {
     cl_object v5;
     v5 = v4args;
     if (Null(v5)) { goto L26; }
     {
      cl_object v6;
      v6 = ECL_CONS_CDR(v5);
      v4args = v6;
      v5 = ECL_CONS_CAR(v5);
     }
L26:;
     T0 = v5;
    }
    CLV1 = env1 = CONS(T0,env1);                  /*  ARG             */
    {cl_object v5;
     v5 = ECL_NIL;
     v5 = ecl_make_cclosure_va((cl_objectfn)LC102__pprint_logical_block_1287,env1,Cblock);
     T0 = v5;
    }
    si_pprint_logical_block_helper(6, T0, ECL_CONS_CAR(CLV1), v2stream, _ecl_static_23, ECL_NIL, _ecl_static_24);
   }
   goto L35;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L33; }
   goto L34;
L35:;
   goto L37;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L33; }
   goto L34;
L37:;
   goto L39;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L33; }
   goto L34;
L39:;
   if (!(v4args==ECL_NIL)) { goto L33; }
L34:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L33:;
   cl_pprint_newline(2, VV[57], v2stream);
   goto L3;
  }
 }
 }
}
/*	closure PPRINT-LOGICAL-BLOCK-1287                             */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC102__pprint_logical_block_1287(cl_narg narg, cl_object v1, cl_object v2stream, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  ARG             */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
TTL:
 {
  cl_object v3;
  v3 = ecl_make_fixnum(0);
  {
   cl_object v4args;
   v4args = ECL_CONS_CAR(CLV1);
   goto L5;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L3; }
   goto L4;
L5:;
   goto L7;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L3; }
   goto L4;
L7:;
   goto L9;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L3; }
   goto L4;
L9:;
   if (!(v4args==ECL_NIL)) { goto L3; }
L4:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L3:;
   if (!(v4args==ECL_NIL)) { goto L12; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_43, ECL_SYM("OFFSET",1279), ecl_make_fixnum(12));
L12:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L15; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L15:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L21; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L21:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L30; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L30:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
   goto L38;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L36; }
   goto L37;
L38:;
   goto L40;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L36; }
   goto L37;
L40:;
   goto L42;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L36; }
   goto L37;
L42:;
   if (!(v4args==ECL_NIL)) { goto L36; }
L37:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L36:;
   cl_write_string(2, _ecl_static_33, v2stream);
   cl_pprint_newline(2, VV[108], v2stream);
   cl_pprint_indent(3, VV[63], ecl_make_fixnum(0), v2stream);
   if (!(v4args==ECL_NIL)) { goto L48; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_43, ECL_SYM("OFFSET",1279), ecl_make_fixnum(23));
L48:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L51; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L51:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L57; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L57:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L66; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L66:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
L72:;
   if (!(v4args==ECL_NIL)) { goto L74; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L74:;
   cl_write_string(2, _ecl_static_33, v2stream);
   cl_pprint_newline(2, VV[106], v2stream);
   if (!(v4args==ECL_NIL)) { goto L78; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_43, ECL_SYM("OFFSET",1279), ecl_make_fixnum(31));
L78:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L81; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L81:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L87; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L87:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L96; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L96:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
   goto L72;
  }
 }
 }
}
/*	function definition for PPRINT-DOLIST                         */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L108pprint_dolist(cl_narg narg, cl_object v1stream, cl_object v2list, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {cl_object v3;
  v3 = ECL_NIL;
  v3 = ecl_make_cfun((cl_objectfn_fixed)LC107__pprint_logical_block_1335,ECL_NIL,Cblock,2);
  T0 = v3;
 }
 value0 = si_pprint_logical_block_helper(6, T0, v2list, v1stream, _ecl_static_23, ECL_NIL, _ecl_static_24);
 return value0;
}
/*	local function PPRINT-LOGICAL-BLOCK-1335                      */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC107__pprint_logical_block_1335(cl_object v1, cl_object v2stream)
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v3;
  v3 = ecl_make_fixnum(0);
  if (!(v1==ECL_NIL)) { goto L2; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L5; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L5:;
  v3 = ecl_plus(v3,ecl_make_fixnum(1));
  {
   cl_object v4;
   v4 = v1;
   if (Null(v4)) { goto L12; }
   {
    cl_object v5;
    v5 = ECL_CONS_CDR(v4);
    v1 = v5;
    v4 = ECL_CONS_CAR(v4);
   }
L12:;
   T0 = v4;
  }
  si_write_object(T0, v2stream);
  if (!(v1==ECL_NIL)) { goto L18; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L18:;
  cl_pprint_indent(3, ECL_SYM("BLOCK",1202), ecl_make_fixnum(3), v2stream);
  cl_write_char(2, CODE_CHAR(32), v2stream);
  cl_pprint_newline(2, VV[109], v2stream);
  {
   cl_object v4;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L25; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L25:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L31; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L31:;
    v4 = v5;
   }
   {
    cl_object env1 = env0;
    env1 = ECL_NIL;
    CLV0 = env1 = CONS(v4,env1);                  /*  ARG             */
    {cl_object v5;
     v5 = ECL_NIL;
     v5 = ecl_make_cclosure_va((cl_objectfn)LC106__pprint_logical_block_1355,env1,Cblock);
     T0 = v5;
    }
    si_pprint_logical_block_helper(6, T0, ECL_CONS_CAR(CLV0), v2stream, _ecl_static_23, ECL_NIL, _ecl_static_24);
   }
  }
L39:;
  if (!(v1==ECL_NIL)) { goto L41; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L41:;
  cl_write_char(2, CODE_CHAR(32), v2stream);
  {
   cl_object v4form_or_tag;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L45; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L45:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L51; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L51:;
    v4form_or_tag = v5;
   }
   {
    cl_fixnum v5;
    if (!(ECL_ATOM(v4form_or_tag))) { goto L59; }
    v5 = 0;
    goto L58;
L59:;
    v5 = 1;
L58:;
    cl_pprint_indent(3, ECL_SYM("BLOCK",1202), ecl_make_fixnum(v5), v2stream);
   }
   cl_pprint_newline(2, VV[106], v2stream);
   si_write_object(v4form_or_tag, v2stream);
  }
  goto L39;
 }
}
/*	closure PPRINT-LOGICAL-BLOCK-1355                             */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC106__pprint_logical_block_1355(cl_narg narg, cl_object v1, cl_object v2stream, ...)
{
 cl_object T0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  ARG             */
 { /* ... closure scanning finished */
TTL:
 {
  cl_object v3;
  v3 = ecl_make_fixnum(0);
  {
   cl_object v4args;
   v4args = ECL_CONS_CAR(CLV0);
   goto L5;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L3; }
   goto L4;
L5:;
   goto L7;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L3; }
   goto L4;
L7:;
   goto L9;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L3; }
   goto L4;
L9:;
   if (!(v4args==ECL_NIL)) { goto L3; }
L4:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L3:;
   if (!(v4args==ECL_NIL)) { goto L12; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_44, ECL_SYM("OFFSET",1279), ecl_make_fixnum(6));
L12:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L15; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L15:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L21; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L21:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L30; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L30:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
   goto L38;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L36; }
   goto L37;
L38:;
   goto L40;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L36; }
   goto L37;
L40:;
   goto L42;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L36; }
   goto L37;
L42:;
   if (!(v4args==ECL_NIL)) { goto L36; }
L37:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L36:;
   cl_write_string(2, _ecl_static_33, v2stream);
   cl_pprint_newline(2, VV[109], v2stream);
   cl_pprint_indent(3, VV[63], ecl_make_fixnum(0), v2stream);
   if (!(v4args==ECL_NIL)) { goto L48; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_44, ECL_SYM("OFFSET",1279), ecl_make_fixnum(17));
L48:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L51; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L51:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L57; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L57:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L66; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L66:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
L72:;
   if (!(v4args==ECL_NIL)) { goto L74; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L74:;
   cl_write_string(2, _ecl_static_33, v2stream);
   cl_pprint_newline(2, VV[106], v2stream);
   if (!(v4args==ECL_NIL)) { goto L78; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_44, ECL_SYM("OFFSET",1279), ecl_make_fixnum(25));
L78:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L81; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L81:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L87; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L87:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L96; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L96:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
   goto L72;
  }
 }
 }
}
/*	function definition for PPRINT-TYPECASE                       */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L111pprint_typecase(cl_narg narg, cl_object v1stream, cl_object v2list, ...)
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
  cl_object env1 = env0;
  env1 = ECL_NIL;
  CLV0 = env1 = CONS(v2list,env1);                /*  ARG             */
  {cl_object v3;
   v3 = ECL_NIL;
   v3 = ecl_make_cclosure_va((cl_objectfn)LC110__pprint_logical_block_1399,env1,Cblock);
   T0 = v3;
  }
  si_pprint_logical_block_helper(6, T0, ECL_CONS_CAR(CLV0), v1stream, _ecl_static_23, ECL_NIL, _ecl_static_24);
 }
 value0 = ECL_NIL;
 cl_env_copy->nvalues = 1;
 return value0;
}
/*	closure PPRINT-LOGICAL-BLOCK-1399                             */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC110__pprint_logical_block_1399(cl_narg narg, cl_object v1, cl_object v2stream, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  ARG             */
 { /* ... closure scanning finished */
TTL:
 {
  cl_object v3;
  v3 = ecl_make_fixnum(0);
  {
   cl_object v4args;
   v4args = ECL_CONS_CAR(CLV0);
   goto L5;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L3; }
   goto L4;
L5:;
   goto L7;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L3; }
   goto L4;
L7:;
   goto L9;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L3; }
   goto L4;
L9:;
   if (!(v4args==ECL_NIL)) { goto L3; }
L4:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L3:;
   if (!(v4args==ECL_NIL)) { goto L12; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_45, ECL_SYM("OFFSET",1279), ecl_make_fixnum(6));
L12:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L15; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L15:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L21; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L21:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L30; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L30:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
   goto L38;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L36; }
   goto L37;
L38:;
   goto L40;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L36; }
   goto L37;
L40:;
   goto L42;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L36; }
   goto L37;
L42:;
   if (!(v4args==ECL_NIL)) { goto L36; }
L37:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L36:;
   cl_write_string(2, _ecl_static_33, v2stream);
   cl_pprint_indent(3, ECL_SYM("BLOCK",1202), ecl_make_fixnum(3), v2stream);
   cl_pprint_newline(2, VV[109], v2stream);
   if (!(v4args==ECL_NIL)) { goto L48; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_45, ECL_SYM("OFFSET",1279), ecl_make_fixnum(17));
L48:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L51; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L51:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L57; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L57:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L66; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L66:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
   cl_pprint_indent(3, ECL_SYM("BLOCK",1202), ecl_make_fixnum(1), v2stream);
L73:;
   if (!(v4args==ECL_NIL)) { goto L75; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L75:;
   cl_write_string(2, _ecl_static_33, v2stream);
   cl_pprint_newline(2, VV[106], v2stream);
   {
    cl_object env1 = env0;
    if (!(v4args==ECL_NIL)) { goto L79; }
    cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_45, ECL_SYM("OFFSET",1279), ecl_make_fixnum(29));
L79:;
    if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L82; }
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
L82:;
    v3 = ecl_plus(v3,ecl_make_fixnum(1));
    {
     cl_object v5;
     v5 = v1;
     if (Null(v5)) { goto L88; }
     {
      cl_object v6;
      v6 = ECL_CONS_CDR(v5);
      v1 = v6;
      v5 = ECL_CONS_CAR(v5);
     }
L88:;
    }
    {
     cl_object v5;
     v5 = v4args;
     if (Null(v5)) { goto L97; }
     {
      cl_object v6;
      v6 = ECL_CONS_CDR(v5);
      v4args = v6;
      v5 = ECL_CONS_CAR(v5);
     }
L97:;
     T0 = v5;
    }
    CLV1 = env1 = CONS(T0,env1);                  /*  ARG             */
    {cl_object v5;
     v5 = ECL_NIL;
     v5 = ecl_make_cclosure_va((cl_objectfn)LC109__pprint_logical_block_1435,env1,Cblock);
     T0 = v5;
    }
    si_pprint_logical_block_helper(6, T0, ECL_CONS_CAR(CLV1), v2stream, _ecl_static_23, ECL_NIL, _ecl_static_24);
   }
   goto L73;
  }
 }
 }
}
/*	closure PPRINT-LOGICAL-BLOCK-1435                             */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC109__pprint_logical_block_1435(cl_narg narg, cl_object v1, cl_object v2stream, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  ARG             */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
TTL:
 {
  cl_object v3;
  v3 = ecl_make_fixnum(0);
  {
   cl_object v4args;
   v4args = ECL_CONS_CAR(CLV1);
   goto L5;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L3; }
   goto L4;
L5:;
   goto L7;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L3; }
   goto L4;
L7:;
   goto L9;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L3; }
   goto L4;
L9:;
   if (!(v4args==ECL_NIL)) { goto L3; }
L4:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L3:;
   if (!(v4args==ECL_NIL)) { goto L12; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_45, ECL_SYM("OFFSET",1279), ecl_make_fixnum(33));
L12:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L15; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L15:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L21; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L21:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L30; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L30:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
   goto L38;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L36; }
   goto L37;
L38:;
   goto L40;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L36; }
   goto L37;
L40:;
   goto L42;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L36; }
   goto L37;
L42:;
   if (!(v4args==ECL_NIL)) { goto L36; }
L37:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L36:;
L44:;
   if (!(v4args==ECL_NIL)) { goto L46; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L46:;
   cl_write_string(2, _ecl_static_33, v2stream);
   cl_pprint_newline(2, VV[106], v2stream);
   if (!(v4args==ECL_NIL)) { goto L50; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_45, ECL_SYM("OFFSET",1279), ecl_make_fixnum(43));
L50:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L53; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L53:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L59; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L59:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L68; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L68:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
   goto L44;
  }
 }
 }
}
/*	function definition for PPRINT-PROG                           */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L113pprint_prog(cl_narg narg, cl_object v1stream, cl_object v2list, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {cl_object v3;
  v3 = ECL_NIL;
  v3 = ecl_make_cfun((cl_objectfn_fixed)LC112__pprint_logical_block_1465,ECL_NIL,Cblock,2);
  T0 = v3;
 }
 value0 = si_pprint_logical_block_helper(6, T0, v2list, v1stream, _ecl_static_23, ECL_NIL, _ecl_static_24);
 return value0;
}
/*	local function PPRINT-LOGICAL-BLOCK-1465                      */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC112__pprint_logical_block_1465(cl_object v1, cl_object v2stream)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v3;
  v3 = ecl_make_fixnum(0);
  if (!(v1==ECL_NIL)) { goto L2; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L5; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L5:;
  v3 = ecl_plus(v3,ecl_make_fixnum(1));
  {
   cl_object v4;
   v4 = v1;
   if (Null(v4)) { goto L12; }
   {
    cl_object v5;
    v5 = ECL_CONS_CDR(v4);
    v1 = v5;
    v4 = ECL_CONS_CAR(v4);
   }
L12:;
   T0 = v4;
  }
  si_write_object(T0, v2stream);
  if (!(v1==ECL_NIL)) { goto L18; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L18:;
  cl_write_char(2, CODE_CHAR(32), v2stream);
  cl_pprint_newline(2, VV[108], v2stream);
  if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L23; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L23:;
  v3 = ecl_plus(v3,ecl_make_fixnum(1));
  {
   cl_object v4;
   v4 = v1;
   if (Null(v4)) { goto L30; }
   {
    cl_object v5;
    v5 = ECL_CONS_CDR(v4);
    v1 = v5;
    v4 = ECL_CONS_CAR(v4);
   }
L30:;
   T0 = v4;
  }
  cl_pprint_fill(2, v2stream, T0);
L36:;
  if (!(v1==ECL_NIL)) { goto L38; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L38:;
  cl_write_char(2, CODE_CHAR(32), v2stream);
  {
   cl_object v4form_or_tag;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L42; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L42:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L48; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L48:;
    v4form_or_tag = v5;
   }
   {
    cl_fixnum v5;
    if (!(ECL_ATOM(v4form_or_tag))) { goto L56; }
    v5 = 0;
    goto L55;
L56:;
    v5 = 1;
L55:;
    cl_pprint_indent(3, ECL_SYM("BLOCK",1202), ecl_make_fixnum(v5), v2stream);
   }
   cl_pprint_newline(2, VV[106], v2stream);
   si_write_object(v4form_or_tag, v2stream);
  }
  goto L36;
 }
}
/*	function definition for PPRINT-FUNCTION-CALL                  */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L115pprint_function_call(cl_narg narg, cl_object v1stream, cl_object v2list, ...)
{
 cl_object T0;
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 {
  cl_object env1 = env0;
  env1 = ECL_NIL;
  CLV0 = env1 = CONS(v2list,env1);                /*  ARG             */
  {cl_object v3;
   v3 = ECL_NIL;
   v3 = ecl_make_cclosure_va((cl_objectfn)LC114__pprint_logical_block_1490,env1,Cblock);
   T0 = v3;
  }
  si_pprint_logical_block_helper(6, T0, ECL_CONS_CAR(CLV0), v1stream, _ecl_static_23, ECL_NIL, _ecl_static_24);
 }
 value0 = ECL_NIL;
 cl_env_copy->nvalues = 1;
 return value0;
}
/*	closure PPRINT-LOGICAL-BLOCK-1490                             */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC114__pprint_logical_block_1490(cl_narg narg, cl_object v1, cl_object v2stream, ...)
{
 cl_object T0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  ARG             */
 { /* ... closure scanning finished */
TTL:
 {
  cl_object v3;
  v3 = ecl_make_fixnum(0);
  {
   cl_object v4args;
   v4args = ECL_CONS_CAR(CLV0);
   goto L5;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L3; }
   goto L4;
L5:;
   goto L7;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L3; }
   goto L4;
L7:;
   goto L9;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L3; }
   goto L4;
L9:;
   if (!(v4args==ECL_NIL)) { goto L3; }
L4:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L3:;
   if (!(v4args==ECL_NIL)) { goto L12; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_46, ECL_SYM("OFFSET",1279), ecl_make_fixnum(6));
L12:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L15; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L15:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L21; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L21:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L30; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L30:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
   goto L38;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L36; }
   goto L37;
L38:;
   goto L40;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L36; }
   goto L37;
L40:;
   goto L42;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L36; }
   goto L37;
L42:;
   if (!(v4args==ECL_NIL)) { goto L36; }
L37:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L36:;
   cl_write_string(2, _ecl_static_33, v2stream);
   cl_pprint_newline(2, VV[109], v2stream);
   cl_pprint_indent(3, VV[63], ecl_make_fixnum(0), v2stream);
L47:;
   if (!(v4args==ECL_NIL)) { goto L49; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L49:;
   if (!(v4args==ECL_NIL)) { goto L52; }
   cl_error(7, ECL_SYM("FORMAT-ERROR",1074), VV[168], _ecl_static_31, ECL_SYM("CONTROL-STRING",1211), _ecl_static_46, ECL_SYM("OFFSET",1279), ecl_make_fixnum(20));
L52:;
   if ((si_pprint_pop_helper(3, v1, v3, v2stream))!=ECL_NIL) { goto L55; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L55:;
   v3 = ecl_plus(v3,ecl_make_fixnum(1));
   {
    cl_object v5;
    v5 = v1;
    if (Null(v5)) { goto L61; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v1 = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L61:;
   }
   {
    cl_object v5;
    v5 = v4args;
    if (Null(v5)) { goto L70; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     v4args = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L70:;
    T0 = v5;
   }
   si_write_object(T0, v2stream);
   goto L78;
   if (Null(cl_LE(3, ECL_NIL, ECL_NIL, ECL_NIL))) { goto L76; }
   goto L77;
L78:;
   goto L80;
   if (!((ECL_NIL)==(ECL_NIL))) { goto L76; }
   goto L77;
L80:;
   goto L82;
   if (!((ECL_NIL)==(ecl_make_fixnum(0)))) { goto L76; }
   goto L77;
L82:;
   if (!(v4args==ECL_NIL)) { goto L76; }
L77:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L76:;
   cl_write_string(2, _ecl_static_33, v2stream);
   cl_pprint_newline(2, VV[106], v2stream);
   goto L47;
  }
 }
 }
}

#include "clos/pprint.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecluqu66Xj3TlRr9_pW0AZE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:LSP;PPRINT.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_ecluqu66Xj3TlRr9_pW0AZE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[0]) /*  MAPC */;
 si_do_deftype(3, VV[0], VVtemp[1], VVtemp[2]);
 si_do_deftype(3, VV[1], VVtemp[3], ECL_SYM("FIXNUM",372));
 si_Xmake_constant(VV[2], ecl_make_fixnum(128));
 si_Xmake_constant(VV[3], ecl_make_fixnum(80));
 {
  cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC1__g0,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 T1 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T0, VVtemp[6]);
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC2__g1,ECL_NIL,Cblock,0);
  T2 = v1;
 }
 T3 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T2, VVtemp[7]);
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC3__g2,ECL_NIL,Cblock,0);
  T4 = v1;
 }
 T5 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T4, VVtemp[12]);
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC4__g3,ECL_NIL,Cblock,0);
  T6 = v1;
 }
 T7 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T6, VVtemp[13]);
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC5__g4,ECL_NIL,Cblock,0);
  T8 = v1;
 }
 T9 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T8, VVtemp[14]);
 T10 = cl_list(13, VVtemp[5], T1, T3, VVtemp[8], VVtemp[9], VVtemp[10], VVtemp[11], T5, T7, T9, VVtemp[15], VVtemp[16], VVtemp[17]);
 T11 = cl_list(2, VV[5], VVtemp[18]);
 clos_load_defclass(VV[4], VVtemp[4], T10, T11);
 }
 ecl_cmp_defun(VV[186]);                          /*  PRETTY-STREAM-P */
 ecl_cmp_defun(VV[187]);                          /*  MAKE-PRETTY-STREAM */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC8__g5,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("PRINT-OBJECT",961), ECL_NIL, VVtemp[19], VVtemp[20], T0, ECL_T);
 }
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[21]) /*  MAPC */;
 ecl_cmp_defun(VV[188]);                          /*  INDEX-POSN      */
 ecl_cmp_defun(VV[189]);                          /*  POSN-INDEX      */
 ecl_cmp_defun(VV[190]);                          /*  POSN-COLUMN     */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC12__g8,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-WRITE-CHAR",1643), ECL_NIL, VVtemp[19], VVtemp[22], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC13__g9,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-FORCE-OUTPUT",1628), ECL_NIL, VVtemp[23], VVtemp[24], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC14__g10,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-CLEAR-OUTPUT",1623), ECL_NIL, VVtemp[23], VVtemp[24], T0, ECL_T);
 }
 (void)0; /* No entry created for PRETTY-OUT */
 (void)0; /* No entry created for PRETTY-SOUT */
 si_define_structure(15, VV[14], _ecl_static_1, ECL_NIL, ECL_NIL, VVtemp[25], VVtemp[26], VV[15], ECL_NIL, ECL_NIL, ECL_NIL, VVtemp[27], ecl_make_fixnum(6), ECL_NIL, ECL_NIL, VV[16]);
 VV[24]= cl_find_class(1, VV[14]);
 ecl_cmp_defun(VV[191]);                          /*  MAKE-LOGICAL-BLOCK */
 (void)0; /* No entry created for REALLY-START-LOGICAL-BLOCK */
 (void)0; /* No entry created for SET-INDENTATION */
 (void)0; /* No entry created for REALLY-END-LOGICAL-BLOCK */
 si_define_structure(15, VV[32], _ecl_static_2, ECL_NIL, ECL_NIL, VVtemp[28], VVtemp[29], VV[33], ECL_NIL, ECL_NIL, ECL_NIL, VVtemp[30], ecl_make_fixnum(1), ECL_NIL, ECL_NIL, VV[34]);
 VV[35]= cl_find_class(1, VV[32]);
 ecl_cmp_defun(VV[195]);                          /*  MAKE-QUEUED-OP  */
 si_define_structure(15, VV[37], _ecl_static_3, ECL_NIL, ECL_NIL, VVtemp[31], VVtemp[32], VV[38], VV[32], ECL_NIL, ECL_NIL, VVtemp[33], ecl_make_fixnum(3), ECL_NIL, ECL_NIL, VV[39]);
 VV[45]= cl_find_class(1, VV[37]);
 ecl_cmp_defun(VV[196]);                          /*  MAKE-SECTION-START */
 si_define_structure(15, VV[40], _ecl_static_4, ECL_NIL, ECL_NIL, VVtemp[34], VVtemp[35], VV[47], VV[37], ECL_NIL, ECL_NIL, VVtemp[36], ecl_make_fixnum(4), ECL_NIL, ECL_NIL, VV[48]);
 VV[52]= cl_find_class(1, VV[40]);
 ecl_cmp_defun(VV[200]);                          /*  MAKE-NEWLINE    */
 (void)0; /* No entry created for ENQUEUE-NEWLINE */
 si_define_structure(15, VV[58], _ecl_static_5, ECL_NIL, ECL_NIL, VVtemp[37], VVtemp[38], VV[59], VV[32], ECL_NIL, ECL_NIL, VVtemp[39], ecl_make_fixnum(3), ECL_NIL, ECL_NIL, VV[60]);
 VV[66]= cl_find_class(1, VV[58]);
 ecl_cmp_defun(VV[208]);                          /*  MAKE-INDENTATION */
 (void)0; /* No entry created for ENQUEUE-INDENT */
 si_define_structure(15, VV[69], _ecl_static_6, ECL_NIL, ECL_NIL, VVtemp[40], VVtemp[41], VV[70], VV[37], ECL_NIL, ECL_NIL, VVtemp[42], ecl_make_fixnum(6), ECL_NIL, ECL_NIL, VV[71]);
 VV[76]= cl_find_class(1, VV[69]);
 ecl_cmp_defun(VV[212]);                          /*  MAKE-BLOCK-START */
 (void)0; /* No entry created for START-LOGICAL-BLOCK */
 si_define_structure(15, VV[41], _ecl_static_7, ECL_NIL, ECL_NIL, VVtemp[43], VVtemp[44], VV[80], VV[32], ECL_NIL, ECL_NIL, VVtemp[45], ecl_make_fixnum(2), ECL_NIL, ECL_NIL, VV[81]);
 VV[82]= cl_find_class(1, VV[41]);
 ecl_cmp_defun(VV[219]);                          /*  MAKE-BLOCK-END  */
 (void)0; /* No entry created for END-LOGICAL-BLOCK */
 si_define_structure(15, VV[84], _ecl_static_8, ECL_NIL, ECL_NIL, VVtemp[46], VVtemp[47], VV[85], VV[32], ECL_NIL, ECL_NIL, VVtemp[48], ecl_make_fixnum(5), ECL_NIL, ECL_NIL, VV[86]);
 VV[94]= cl_find_class(1, VV[84]);
 ecl_cmp_defun(VV[223]);                          /*  MAKE-TAB        */
 (void)0; /* No entry created for ENQUEUE-TAB */
 (void)0; /* No entry created for COMPUTE-TAB-SIZE */
 (void)0; /* No entry created for INDEX-COLUMN */
 (void)0; /* No entry created for EXPAND-TABS */
 (void)0; /* No entry created for ASSURE-SPACE-IN-BUFFER */
 (void)0; /* No entry created for MAYBE-OUTPUT */
 (void)0; /* No entry created for MISERING-P */
 (void)0; /* No entry created for FITS-ON-LINE-P */
 (void)0; /* No entry created for OUTPUT-LINE */
 (void)0; /* No entry created for OUTPUT-PARTIAL-LINE */
 (void)0; /* No entry created for FORCE-PRETTY-OUTPUT */
 ecl_cmp_defun(VV[248]);                          /*  PPRINT-POP-HELPER */
 (void)0; /* No entry created for CHECK-PRINT-LEVEL */
 (void)0; /* No entry created for SEARCH-PRINT-CIRCLE */
 (void)0; /* No entry created for DO-PPRINT-LOGICAL-BLOCK */
 ecl_cmp_defun(VV[249]);                          /*  PPRINT-LOGICAL-BLOCK-HELPER */
 ecl_cmp_defmacro(VV[250]);                       /*  PPRINT-LOGICAL-BLOCK */
 ecl_cmp_defmacro(VV[251]);                       /*  PPRINT-EXIT-IF-LIST-EXHAUSTED */
 ecl_cmp_defmacro(VV[252]);                       /*  PPRINT-POP      */
 (void)0; /* No entry created for PPRINT-NEWLINE */
 (void)0; /* No entry created for PPRINT-INDENT */
 (void)0; /* No entry created for PPRINT-TAB */
 (void)0; /* No entry created for PPRINT-FILL */
 (void)0; /* No entry created for PPRINT-LINEAR */
 (void)0; /* No entry created for PPRINT-TABULAR */
 si_Xmake_special(VV[135]);
 si_define_structure(15, VV[136], _ecl_static_25, ECL_NIL, ECL_NIL, VVtemp[49], VVtemp[50], VV[137], ECL_NIL, VV[138], ECL_NIL, VVtemp[51], ecl_make_fixnum(4), ECL_NIL, ECL_NIL, VV[139]);
 VV[143]= cl_find_class(1, VV[136]);
 ecl_cmp_defun(VV[253]);                          /*  MAKE-PPRINT-DISPATCH-ENTRY */
 ecl_cmp_defun(VV[258]);                          /*  %PRINT-PPRINT-DISPATCH-ENTRY */
 si_define_structure(15, VV[146], _ecl_static_27, ECL_NIL, ECL_NIL, VVtemp[52], VVtemp[53], VV[147], ECL_NIL, VV[148], ECL_NIL, VVtemp[54], ecl_make_fixnum(2), ECL_NIL, ECL_NIL, VV[149]);
 VV[151]= cl_find_class(1, VV[146]);
 ecl_cmp_defun(VV[262]);                          /*  MAKE-PPRINT-DISPATCH-TABLE */
 ecl_cmp_defun(VV[265]);                          /*  %PRINT-PPRINT-DISPATCH-TABLE */
 (void)0; /* No entry created for CONS-TYPE-SPECIFIER-P */
 (void)0; /* No entry created for ENTRY< */
 (void)0; /* No entry created for COPY-PPRINT-DISPATCH */
 ecl_cmp_defun(VV[268]);                          /*  DEFAULT-PPRINT-DISPATCH */
 (void)0; /* No entry created for PPRINT-DISPATCH */
 (void)0; /* No entry created for SET-PPRINT-DISPATCH */
 ecl_cmp_defun(VV[270]);                          /*  PPRINT-ARRAY    */
 ecl_cmp_defun(VV[271]);                          /*  PPRINT-VECTOR   */
 (void)0; /* No entry created for PPRINT-ARRAY-CONTENTS */
 (void)0; /* No entry created for PPRINT-MULTI-DIM-ARRAY */
 (void)0; /* No entry created for PPRINT-RAW-ARRAY */
 ecl_cmp_defun(VV[272]);                          /*  PPRINT-LAMBDA-LIST */
 ecl_cmp_defun(VV[273]);                          /*  PPRINT-LAMBDA   */
 ecl_cmp_defun(VV[274]);                          /*  PPRINT-BLOCK    */
 ecl_cmp_defun(VV[275]);                          /*  PPRINT-FLET     */
 ecl_cmp_defun(VV[276]);                          /*  PPRINT-LET      */
 ecl_cmp_defun(VV[277]);                          /*  PPRINT-PROGN    */
 ecl_cmp_defun(VV[278]);                          /*  PPRINT-PROGV    */
 ecl_cmp_defun(VV[279]);                          /*  PPRINT-QUOTE    */
 ecl_cmp_defun(VV[280]);                          /*  PPRINT-SETQ     */
 ecl_cmp_defun(VV[281]);                          /*  PPRINT-TAGBODY  */
 ecl_cmp_defun(VV[282]);                          /*  PPRINT-CASE     */
 ecl_cmp_defun(VV[283]);                          /*  PPRINT-DEFUN    */
 ecl_cmp_defun(VV[284]);                          /*  PPRINT-DESTRUCTURING-BIND */
 ecl_cmp_defun(VV[285]);                          /*  PPRINT-DO       */
 ecl_cmp_defun(VV[286]);                          /*  PPRINT-DOLIST   */
 ecl_cmp_defun(VV[287]);                          /*  PPRINT-TYPECASE */
 ecl_cmp_defun(VV[288]);                          /*  PPRINT-PROG     */
 ecl_cmp_defun(VV[289]);                          /*  PPRINT-FUNCTION-CALL */
 {
  cl_object T0, T1, T2, T3, T4;
 T0 = L55make_pprint_dispatch_table(0);
 ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-PPRINT-DISPATCH*",54),T0); /*  *PRINT-PPRINT-DISPATCH* */
 T0 = (VV[159]->symbol.gfdef);
 cl_set_pprint_dispatch(2, ECL_SYM("ARRAY",96), T0);
 T0 = (VV[185]->symbol.gfdef);
 cl_set_pprint_dispatch(3, VVtemp[55], T0, ecl_make_fixnum(-1));
 T0 = (ECL_SYM("PPRINT-FILL",650)->symbol.gfdef);
 cl_set_pprint_dispatch(3, ECL_SYM("CONS",251), T0, ecl_make_fixnum(-2));
 {
  cl_object v1;
  v1 = VVtemp[56];
  goto L411;
L410:;
  {
   cl_object v2magic_form;
   v2magic_form = _ecl_car(v1);
   T0 = _ecl_car(v2magic_form);
   T1 = cl_list(2, ECL_SYM("EQL",334), T0);
   T2 = cl_list(2, ECL_SYM("CONS",251), T1);
   T3 = _ecl_cadr(v2magic_form);
   T4 = cl_symbol_function(T3);
   cl_set_pprint_dispatch(2, T2, T4);
  }
  v1 = _ecl_cdr(v1);
L411:;
  if (Null(v1)) { goto L418; }
  goto L410;
L418:;
 }
 ECL_SETQ(cl_env_copy,VV[135],ECL_SYM_VAL(cl_env_copy,ECL_SYM("*PRINT-PPRINT-DISPATCH*",54)));
 T0 = ECL_SYM_VAL(cl_env_copy,VV[135]);
 ecl_bds_unwind1(cl_env_copy);
 ECL_SETQ(cl_env_copy,ECL_SYM("*PRINT-PPRINT-DISPATCH*",54),cl_copy_pprint_dispatch(1, ECL_NIL));
 {
  cl_object v1;
  v1 = _ecl_cdr(ECL_SYM_VAL(cl_env_copy,ECL_SYM("+IO-SYNTAX-PROGV-LIST+",1720)));
  {
   cl_object v2;
   v2 = ECL_SYM_VAL(cl_env_copy,VV[135]);
   (ECL_CONS_CAR(v1)=v2,v1);
  }
 }
 {
  cl_object v3;
  v3 = _ecl_cdr(ECL_SYM_VAL(cl_env_copy,ECL_SYM("+ECL-SYNTAX-PROGV-LIST+",1721)));
  {
   cl_object v4;
   v4 = ECL_SYM_VAL(cl_env_copy,VV[135]);
   (ECL_CONS_CAR(v3)=v4,v3);
  }
 }
 cl_set(ECL_SYM("*PRINT-PRETTY*",55),ECL_T);
 }
}
