/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:LSP;ARRAYLIB.LSP                                  */
#include <ecl/ecl-cmp.h>
#include "lsp/arraylib.eclh"
/*	function definition for MAKE-ARRAY                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_make_array(cl_narg narg, cl_object v1dimensions, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2element_type;
  cl_object v3initial_element;
  cl_object v4initial_element_supplied_p;
  cl_object v5initial_contents;
  cl_object v6initial_contents_supplied_p;
  cl_object v7adjustable;
  cl_object v8fill_pointer;
  cl_object v9displaced_to;
  cl_object v10displaced_index_offset;
  ecl_va_list args; ecl_va_start(args,v1dimensions,narg,1);
  {
   cl_object keyvars[14];
   cl_parse_key(args,7,cl_make_arraykeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[7])) {
    v2element_type = ECL_T;
   } else {
    v2element_type = keyvars[0];
   }
   v3initial_element = keyvars[1];
   v4initial_element_supplied_p = keyvars[8];
   v5initial_contents = keyvars[2];
   v6initial_contents_supplied_p = keyvars[9];
   v7adjustable = keyvars[3];
   v8fill_pointer = keyvars[4];
   v9displaced_to = keyvars[5];
   if (Null(keyvars[13])) {
    v10displaced_index_offset = ecl_make_fixnum(0);
   } else {
    v10displaced_index_offset = keyvars[6];
   }
  }
  {
   cl_object v11x;
   v11x = si_make_pure_array(v2element_type, v1dimensions, v7adjustable, v8fill_pointer, v9displaced_to, v10displaced_index_offset);
   if (Null(v4initial_element_supplied_p)) { goto L4; }
   if (Null(v6initial_contents_supplied_p)) { goto L6; }
   cl_error(1, _ecl_static_1);
L6:;
   value0 = si_fill_array_with_elt(v11x, v3initial_element, ecl_make_fixnum(0), ECL_NIL);
   return value0;
L4:;
   if (Null(v6initial_contents_supplied_p)) { goto L8; }
   value0 = L2fill_array_with_seq(v11x, v5initial_contents);
   return value0;
L8:;
   value0 = v11x;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for FILL-ARRAY-WITH-SEQ                   */
/*	optimize speed 1, debug 1, space 1, safety 0                  */
static cl_object L2fill_array_with_seq(cl_object v1array, cl_object v2initial_contents)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v3dims;
  v3dims = cl_array_dimensions(v1array);
  if (Null(v3dims)) { goto L3; }
  LC1iterate_over_contents(v1array, v2initial_contents, v3dims, ecl_make_fixnum(0));
  goto L1;
L3:;
  ecl_aset_unsafe(v1array,0,v2initial_contents);
 }
L1:;
 value0 = v1array;
 cl_env_copy->nvalues = 1;
 return value0;
}
/*	local function ITERATE-OVER-CONTENTS                          */
/*	optimize speed 1, debug 1, space 1, safety 0                  */
static cl_object LC1iterate_over_contents(cl_object v1array, cl_object v2contents, cl_object v3dims, cl_object v4written)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 cl_fixnum v5written;
 v5written = ecl_fixnum(v4written);
TTL:
 {
  cl_fixnum v6;
  v6 = ecl_length(v2contents);
  T0 = _ecl_car(v3dims);
  if (!(!ecl_number_equalp(ecl_make_fixnum(v6),T0))) { goto L1; }
 }
 cl_error(1, _ecl_static_2);
L1:;
 {
  cl_fixnum v6;
  v6 = ecl_length(v3dims);
  if (!((v6)==(1))) { goto L4; }
 }
 {
  cl_object v6it;
  v6it = si_make_seq_iterator(1, v2contents);
  goto L9;
L8:;
  T0 = si_seq_iterator_ref(v2contents, v6it);
  ecl_aset_unsafe(v1array,v5written,T0);
  v5written = (v5written)+(1);
  v6it = si_seq_iterator_next(v2contents, v6it);
L9:;
  if (v6it==ECL_NIL) { goto L16; }
  goto L8;
L16:;
  goto L3;
 }
L4:;
 {
  cl_object v7it;
  v7it = si_make_seq_iterator(1, v2contents);
  goto L21;
L20:;
  T0 = si_seq_iterator_ref(v2contents, v7it);
  T1 = _ecl_cdr(v3dims);
  v5written = ecl_fixnum(LC1iterate_over_contents(v1array, T0, T1, ecl_make_fixnum(v5written)));
  v7it = si_seq_iterator_next(v2contents, v7it);
L21:;
  if (v7it==ECL_NIL) { goto L27; }
  goto L20;
L27:;
 }
L3:;
 value0 = ecl_make_fixnum(v5written);
 cl_env_copy->nvalues = 1;
 return value0;
}
/*	function definition for VECTOR                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_vector(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1objects;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1objects = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v2a;
   {
    cl_fixnum v3;
    v3 = ecl_length(v1objects);
    v2a = si_make_vector(ECL_T, ecl_make_fixnum(v3), ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
   }
   value0 = L2fill_array_with_seq(v2a, v1objects);
   return value0;
  }
 }
}
/*	function definition for ARRAY-DIMENSIONS                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_array_dimensions(cl_object v1array)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   int8_t v2;
   cl_fixnum v3i;
   cl_object v4d;
   v2 = (int8_t)(ecl_array_rank(v1array));
   v3i = (cl_fixnum)(v2);
   v4d = ECL_NIL;
   goto L6;
L5:;
   {
    int8_t v5;
    v3i = (v3i)-(1);
    v5 = (int8_t)(v3i);
    {
     cl_fixnum v6;
     v6 = ecl_array_dimension(v1array,(cl_fixnum)(v5));
     v4d = CONS(ecl_make_fixnum(v6),v4d);
    }
   }
L6:;
   if ((v3i)==(0)) { goto L12; }
   goto L5;
L12:;
   value0 = v4d;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for ARRAY-IN-BOUNDS-P                     */
/*	optimize speed 1, debug 1, space 1, safety 0                  */
cl_object cl_array_in_bounds_p(cl_narg narg, cl_object v1array, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2indices;
  ecl_va_list args; ecl_va_start(args,v1array,narg,1);
  v2indices = cl_grab_rest_args(args);
  ecl_va_end(args);
  if (ecl_unlikely(!ECL_ARRAYP(v1array))) FEtype_error_array(v1array);
  {
   cl_object v3indices;
   int8_t v4r;
   cl_fixnum v5i;
   v3indices = v2indices;
   v4r = (int8_t)((((v1array)->d.t == t_array)?(v1array)->array.rank:1));
   v5i = 0;
   goto L7;
L6:;
   if (Null(v3indices)) { goto L10; }
   {
    cl_object v6index;
    v6index = ECL_CONS_CAR(v3indices);
    if (!(ECL_FIXNUMP(v6index))) { goto L14; }
    if ((ecl_fixnum(v6index))<0) { goto L14; }
    {
     cl_fixnum v7;
     v7 = ecl_array_dimension(v1array,v5i);
     if (!((ecl_fixnum(v6index))>=(v7))) { goto L9; }
     goto L13;
    }
L14:;
L13:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L10:;
   cl_error(3, _ecl_static_3, ecl_make_int8_t(v4r), ecl_make_fixnum(v5i));
L9:;
   v3indices = ECL_CONS_CDR(v3indices);
   v5i = (v5i)+1;
L7:;
   if ((v5i)>=((cl_fixnum)(v4r))) { goto L21; }
   goto L6;
L21:;
   value0 = ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for ROW-MAJOR-INDEX-INNER                 */
/*	optimize speed 1, debug 1, space 1, safety 0                  */
static cl_object L4row_major_index_inner(cl_object v1array, cl_object v2indices)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  int8_t v3r;
  cl_fixnum v4i;
  cl_fixnum v5j;
  cl_object v6s;
  v3r = (int8_t)((((v1array)->d.t == t_array)?(v1array)->array.rank:1));
  v4i = 0;
  v5j = 0;
  v6s = v2indices;
  goto L7;
L6:;
  {
   cl_fixnum v7d;
   cl_object v8o;
   cl_fixnum v9ndx;
   v7d = ecl_array_dimension(v1array,v4i);
   v8o = ECL_CONS_CAR(v6s);
   v9ndx = 0;
   if (!(ECL_FIXNUMP(v8o))) { goto L16; }
   v9ndx = ecl_fixnum(v8o);
   if (!((0)<=(v9ndx))) { goto L16; }
   {
    cl_fixnum v10;
    v10 = ecl_array_dimension(v1array,v4i);
    if ((v9ndx)<(v10)) { goto L13; }
    goto L14;
   }
L16:;
   goto L14;
L14:;
   LC3indexing_error(v1array, v2indices);
L13:;
   v5j = (v5j)*(v7d);
   v5j = (v5j)+(v9ndx);
  }
  v4i = (v4i)+1;
  v6s = ECL_CONS_CDR(v6s);
L7:;
  if (v6s==ECL_NIL) { goto L27; }
  goto L6;
L27:;
  if (!((v4i)<((cl_fixnum)(v3r)))) { goto L29; }
  LC3indexing_error(v1array, v2indices);
L29:;
  value0 = ecl_make_fixnum(v5j);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function INDEXING-ERROR                                 */
/*	optimize speed 1, debug 1, space 1, safety 0                  */
static cl_object LC3indexing_error(cl_object v1array, cl_object v2indices)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 value0 = cl_error(3, _ecl_static_4, v2indices, v1array);
 return value0;
}
/*	function definition for ARRAY-ROW-MAJOR-INDEX                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_array_row_major_index(cl_narg narg, cl_object v1array, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2indices;
  ecl_va_list args; ecl_va_start(args,v1array,narg,1);
  v2indices = cl_grab_rest_args(args);
  ecl_va_end(args);
  if (ecl_unlikely(!ECL_ARRAYP(v1array))) FEtype_error_array(v1array);
  value0 = L4row_major_index_inner(v1array, v2indices);
  return value0;
 }
}
/*	function definition for BIT                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_bit(cl_narg narg, cl_object v1bit_array, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2indices;
  ecl_va_list args; ecl_va_start(args,v1bit_array,narg,1);
  v2indices = cl_grab_rest_args(args);
  ecl_va_end(args);
  if (ecl_unlikely(!ECL_ARRAYP(v1bit_array))) FEtype_error_array(v1bit_array);
  T0 = L4row_major_index_inner(v1bit_array, v2indices);
  value0 = ecl_aref(v1bit_array,ecl_to_size(T0));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for SBIT                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_sbit(cl_narg narg, cl_object v1bit_array, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2indices;
  ecl_va_list args; ecl_va_start(args,v1bit_array,narg,1);
  v2indices = cl_grab_rest_args(args);
  ecl_va_end(args);
  if (ecl_unlikely(!ECL_ARRAYP(v1bit_array))) FEtype_error_array(v1bit_array);
  T0 = L4row_major_index_inner(v1bit_array, v2indices);
  value0 = ecl_aref(v1bit_array,ecl_to_size(T0));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for BIT-AND                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_bit_and(cl_narg narg, cl_object v1bit_array1, cl_object v2bit_array2, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v3result_bit_array;
  va_list args; va_start(args,v2bit_array2);
  {
   int i = 2;
   if (i >= narg) {
    v3result_bit_array = ECL_NIL;
   } else {
    i++;
    v3result_bit_array = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = si_bit_array_op(ecl_make_fixnum(1), v1bit_array1, v2bit_array2, v3result_bit_array);
  return value0;
 }
}
/*	function definition for BIT-IOR                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_bit_ior(cl_narg narg, cl_object v1bit_array1, cl_object v2bit_array2, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v3result_bit_array;
  va_list args; va_start(args,v2bit_array2);
  {
   int i = 2;
   if (i >= narg) {
    v3result_bit_array = ECL_NIL;
   } else {
    i++;
    v3result_bit_array = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = si_bit_array_op(ecl_make_fixnum(7), v1bit_array1, v2bit_array2, v3result_bit_array);
  return value0;
 }
}
/*	function definition for BIT-XOR                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_bit_xor(cl_narg narg, cl_object v1bit_array1, cl_object v2bit_array2, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v3result_bit_array;
  va_list args; va_start(args,v2bit_array2);
  {
   int i = 2;
   if (i >= narg) {
    v3result_bit_array = ECL_NIL;
   } else {
    i++;
    v3result_bit_array = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = si_bit_array_op(ecl_make_fixnum(6), v1bit_array1, v2bit_array2, v3result_bit_array);
  return value0;
 }
}
/*	function definition for BIT-EQV                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_bit_eqv(cl_narg narg, cl_object v1bit_array1, cl_object v2bit_array2, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v3result_bit_array;
  va_list args; va_start(args,v2bit_array2);
  {
   int i = 2;
   if (i >= narg) {
    v3result_bit_array = ECL_NIL;
   } else {
    i++;
    v3result_bit_array = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = si_bit_array_op(ecl_make_fixnum(9), v1bit_array1, v2bit_array2, v3result_bit_array);
  return value0;
 }
}
/*	function definition for BIT-NAND                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_bit_nand(cl_narg narg, cl_object v1bit_array1, cl_object v2bit_array2, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v3result_bit_array;
  va_list args; va_start(args,v2bit_array2);
  {
   int i = 2;
   if (i >= narg) {
    v3result_bit_array = ECL_NIL;
   } else {
    i++;
    v3result_bit_array = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = si_bit_array_op(ecl_make_fixnum(14), v1bit_array1, v2bit_array2, v3result_bit_array);
  return value0;
 }
}
/*	function definition for BIT-NOR                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_bit_nor(cl_narg narg, cl_object v1bit_array1, cl_object v2bit_array2, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v3result_bit_array;
  va_list args; va_start(args,v2bit_array2);
  {
   int i = 2;
   if (i >= narg) {
    v3result_bit_array = ECL_NIL;
   } else {
    i++;
    v3result_bit_array = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = si_bit_array_op(ecl_make_fixnum(8), v1bit_array1, v2bit_array2, v3result_bit_array);
  return value0;
 }
}
/*	function definition for BIT-ANDC1                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_bit_andc1(cl_narg narg, cl_object v1bit_array1, cl_object v2bit_array2, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v3result_bit_array;
  va_list args; va_start(args,v2bit_array2);
  {
   int i = 2;
   if (i >= narg) {
    v3result_bit_array = ECL_NIL;
   } else {
    i++;
    v3result_bit_array = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = si_bit_array_op(ecl_make_fixnum(4), v1bit_array1, v2bit_array2, v3result_bit_array);
  return value0;
 }
}
/*	function definition for BIT-ANDC2                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_bit_andc2(cl_narg narg, cl_object v1bit_array1, cl_object v2bit_array2, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v3result_bit_array;
  va_list args; va_start(args,v2bit_array2);
  {
   int i = 2;
   if (i >= narg) {
    v3result_bit_array = ECL_NIL;
   } else {
    i++;
    v3result_bit_array = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = si_bit_array_op(ecl_make_fixnum(2), v1bit_array1, v2bit_array2, v3result_bit_array);
  return value0;
 }
}
/*	function definition for BIT-ORC1                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_bit_orc1(cl_narg narg, cl_object v1bit_array1, cl_object v2bit_array2, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v3result_bit_array;
  va_list args; va_start(args,v2bit_array2);
  {
   int i = 2;
   if (i >= narg) {
    v3result_bit_array = ECL_NIL;
   } else {
    i++;
    v3result_bit_array = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = si_bit_array_op(ecl_make_fixnum(13), v1bit_array1, v2bit_array2, v3result_bit_array);
  return value0;
 }
}
/*	function definition for BIT-ORC2                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_bit_orc2(cl_narg narg, cl_object v1bit_array1, cl_object v2bit_array2, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v3result_bit_array;
  va_list args; va_start(args,v2bit_array2);
  {
   int i = 2;
   if (i >= narg) {
    v3result_bit_array = ECL_NIL;
   } else {
    i++;
    v3result_bit_array = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = si_bit_array_op(ecl_make_fixnum(11), v1bit_array1, v2bit_array2, v3result_bit_array);
  return value0;
 }
}
/*	function definition for BIT-NOT                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_bit_not(cl_narg narg, cl_object v1bit_array, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2result_bit_array;
  va_list args; va_start(args,v1bit_array);
  {
   int i = 1;
   if (i >= narg) {
    v2result_bit_array = ECL_NIL;
   } else {
    i++;
    v2result_bit_array = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = si_bit_array_op(ecl_make_fixnum(12), v1bit_array, v1bit_array, v2result_bit_array);
  return value0;
 }
}
/*	function definition for VECTOR-POP                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_vector_pop(cl_object v1vector)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v2fp;
   v2fp = ecl_fixnum(cl_fill_pointer(v1vector));
   if (!((v2fp)==0)) { goto L2; }
   cl_error(2, _ecl_static_5, v1vector);
L2:;
   {
    cl_fixnum v3;
    v2fp = (v2fp)-(1);
    v3 = v2fp;
    ((v1vector)->vector.fillp)=(v3);
   }
   value0 = ecl_aref_unsafe(v1vector,v2fp);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for COPY-ARRAY-CONTENTS                   */
/*	optimize speed 1, debug 1, space 1, safety 0                  */
static cl_object L6copy_array_contents(cl_object v1dest, cl_object v2orig)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 value0 = cl_array_dimensions(v1dest);
 if ((value0)!=ECL_NIL) { goto L3; }
 T0 = VV[0];
 goto L1;
L3:;
 T0 = value0;
 goto L1;
L1:;
 value0 = cl_array_dimensions(v2orig);
 if ((value0)!=ECL_NIL) { goto L7; }
 T1 = VV[0];
 goto L5;
L7:;
 T1 = value0;
 goto L5;
L5:;
 value0 = LC5do_copy(v1dest, v2orig, T0, T1, ecl_make_fixnum(0), ecl_make_fixnum(0));
 return value0;
}
/*	local function DO-COPY                                        */
/*	optimize speed 1, debug 1, space 1, safety 0                  */
static cl_object LC5do_copy(cl_object v1dest, cl_object v2orig, cl_object v3dims1, cl_object v4dims2, cl_object v5start1, cl_object v6start2)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 cl_fixnum v7start1;
 cl_fixnum v8start2;
 v7start1 = ecl_fixnum(v5start1);
 v8start2 = ecl_fixnum(v6start2);
TTL:
 {
  cl_fixnum v9d1;
  cl_fixnum v10d2;
  cl_fixnum v11l;
  cl_fixnum v12i1;
  cl_fixnum v13i2;
  {
   cl_object v14;
   v14 = v3dims1;
   if (Null(v14)) { goto L4; }
   {
    cl_object v15;
    v15 = ECL_CONS_CDR(v14);
    v3dims1 = v15;
    v14 = ECL_CONS_CAR(v14);
   }
L4:;
   v9d1 = ecl_fixnum(v14);
  }
  {
   cl_object v14;
   v14 = v4dims2;
   if (Null(v14)) { goto L13; }
   {
    cl_object v15;
    v15 = ECL_CONS_CDR(v14);
    v4dims2 = v15;
    v14 = ECL_CONS_CAR(v14);
   }
L13:;
   v10d2 = ecl_fixnum(v14);
  }
  v11l = (v9d1)<=(v10d2)?v9d1:v10d2;
  v12i1 = v7start1;
  v13i2 = v8start2;
  if (!(v3dims1==ECL_NIL)) { goto L22; }
  value0 = (ecl_copy_subarray(v1dest,v12i1,v2orig,v13i2,v11l),v1dest);
  cl_env_copy->nvalues = 1;
  return value0;
L22:;
  {
   cl_object v14;
   cl_object v15;
   T0 = (ECL_SYM("*",18)->symbol.gfdef);
   v14 = cl_apply(2, T0, v3dims1);
   T0 = (ECL_SYM("*",18)->symbol.gfdef);
   v15 = cl_apply(2, T0, v4dims2);
   {
    cl_fixnum v16i;
    v16i = 0;
    goto L30;
L29:;
    LC5do_copy(v1dest, v2orig, v3dims1, v4dims2, ecl_make_fixnum(v12i1), ecl_make_fixnum(v13i2));
    v12i1 = (v12i1)+(ecl_fixnum(v14));
    v13i2 = (v13i2)+(ecl_fixnum(v15));
    v16i = (v16i)+1;
L30:;
    if (!((v16i)<(v11l))) { goto L39; }
    goto L29;
L39:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for ADJUST-ARRAY                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_adjust_array(cl_narg narg, cl_object v1array, cl_object v2new_dimensions, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3r;
  cl_object v4element_type;
  cl_object v5initial_element;
  cl_object v6initial_contents;
  cl_object v7fill_pointer;
  cl_object v8displaced_to;
  cl_object v9displaced_index_offset;
  ecl_va_list args; ecl_va_start(args,v2new_dimensions,narg,2);
  {
   cl_object keyvars[12];
   cl_parse_key(args,6,cl_adjust_arraykeys,keyvars,(cl_object*)&v3r,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[6])) {
    v4element_type = cl_array_element_type(v1array);
   } else {
    v4element_type = keyvars[0];
   }
   v5initial_element = keyvars[1];
   v6initial_contents = keyvars[2];
   v7fill_pointer = keyvars[3];
   v8displaced_to = keyvars[4];
   v9displaced_index_offset = keyvars[5];
  }
  if (!(ECL_FIXNUMP(v2new_dimensions)||ECL_BIGNUMP(v2new_dimensions))) { goto L2; }
  v2new_dimensions = ecl_list1(v2new_dimensions);
L2:;
  if (!((ECL_ARRAYP(v1array)?(void)0:FEtype_error_array(v1array),ECL_ARRAY_HAS_FILL_POINTER_P(v1array)))) { goto L6; }
  if ((v7fill_pointer)!=ECL_NIL) { goto L5; }
  T0 = cl_fill_pointer(v1array);
  v3r = cl_listX(3, ECL_SYM("FILL-POINTER",1238), T0, v3r);
  goto L5;
L6:;
  if (Null(v7fill_pointer)) { goto L5; }
  cl_error(7, ECL_SYM("SIMPLE-TYPE-ERROR",773), ECL_SYM("DATUM",1214), v1array, ECL_SYM("EXPECTED-TYPE",1232), VV[1], ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_6);
L5:;
  {
   cl_object v10x;
   T0 = (ECL_SYM("MAKE-ARRAY",522)->symbol.gfdef);
   v10x = cl_apply(7, T0, v2new_dimensions, ECL_SYM("ADJUSTABLE",1194), ECL_T, ECL_SYM("ELEMENT-TYPE",1224), v4element_type, v3r);
   if ((v8displaced_to)!=ECL_NIL) { goto L13; }
   if ((v6initial_contents)!=ECL_NIL) { goto L13; }
   L6copy_array_contents(v10x, v1array);
L13:;
   value0 = si_replace_array(v1array, v10x);
   return value0;
  }
 }
}
/*	function definition for SHRINK-VECTOR                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7shrink_vector(cl_object v1vec, cl_object v2len)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!((ECL_ARRAYP(v1vec)? (void)0: FEtype_error_array(v1vec),ECL_ADJUSTABLE_ARRAY_P(v1vec)))) { goto L1; }
  value0 = cl_adjust_array(2, v1vec, v2len);
  return value0;
L1:;
  if (Null(ecl_function_dispatch(cl_env_copy,VV[17])(1, v1vec) /*  SIMPLE-ARRAY-P */)) { goto L3; }
  {
   cl_object v3new_vec;
   T0 = cl_array_element_type(v1vec);
   v3new_vec = si_make_pure_array(T0, v2len, ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
   value0 = si_copy_subarray(v3new_vec, ecl_make_fixnum(0), v1vec, ecl_make_fixnum(0), v2len);
   return value0;
  }
L3:;
  if (!(ECL_VECTORP(v1vec))) { goto L6; }
  si_fill_pointer_set(v1vec, v2len);
  value0 = v1vec;
  cl_env_copy->nvalues = 1;
  return value0;
L6:;
  T0 = cl_type_of(v1vec);
  value0 = cl_error(3, _ecl_static_7, v1vec, T0);
  return value0;
 }
}

#include "lsp/arraylib.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclaIpyegzEoXPh9_9dpkfE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:LSP;ARRAYLIB.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclaIpyegzEoXPh9_9dpkfE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 (void)0; /* No entry created for MAKE-ARRAY */
 (void)0; /* No entry created for FILL-ARRAY-WITH-SEQ */
 (void)0; /* No entry created for VECTOR */
 (void)0; /* No entry created for ARRAY-DIMENSIONS */
 (void)0; /* No entry created for ARRAY-IN-BOUNDS-P */
 (void)0; /* No entry created for ROW-MAJOR-INDEX-INNER */
 (void)0; /* No entry created for ARRAY-ROW-MAJOR-INDEX */
 (void)0; /* No entry created for BIT */
 (void)0; /* No entry created for SBIT */
 (void)0; /* No entry created for BIT-AND */
 (void)0; /* No entry created for BIT-IOR */
 (void)0; /* No entry created for BIT-XOR */
 (void)0; /* No entry created for BIT-EQV */
 (void)0; /* No entry created for BIT-NAND */
 (void)0; /* No entry created for BIT-NOR */
 (void)0; /* No entry created for BIT-ANDC1 */
 (void)0; /* No entry created for BIT-ANDC2 */
 (void)0; /* No entry created for BIT-ORC1 */
 (void)0; /* No entry created for BIT-ORC2 */
 (void)0; /* No entry created for BIT-NOT */
 (void)0; /* No entry created for VECTOR-POP */
 (void)0; /* No entry created for COPY-ARRAY-CONTENTS */
 (void)0; /* No entry created for ADJUST-ARRAY */
 ecl_cmp_defun(VV[16]);                           /*  SHRINK-VECTOR   */
}
