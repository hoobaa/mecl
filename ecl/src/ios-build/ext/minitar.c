/*	Compiler: ECL 12.12.1                                         */
/*	Source: EXT:QUICKLISP;MINITAR.LISP                            */
#include <ecl/ecl-cmp.h>
#include "ext/minitar.eclh"
/*	function definition for MAKE-BLOCK-BUFFER                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1make_block_buffer()
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = si_make_vector(ECL_SYM("BYTE8",1330), ecl_make_fixnum(512), ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
  value0 = si_fill_array_with_elt(T0, ecl_make_fixnum(0), ecl_make_fixnum(0), ECL_NIL);
  return value0;
 }
}
/*	function definition for SKIP-N-BLOCKS                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2skip_n_blocks(cl_object v1n, cl_object v2stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3block;
   v3block = L1make_block_buffer();
   {
    cl_object v4i;
    v4i = ecl_make_fixnum(0);
    goto L4;
L3:;
    cl_read_sequence(2, v3block, v2stream);
    v4i = ecl_one_plus(v4i);
L4:;
    if (!(ecl_number_compare(v4i,v1n)<0)) { goto L9; }
    goto L3;
L9:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for ASCII-SUBSEQ                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3ascii_subseq(cl_object v1vector, cl_object v2start, cl_object v3end)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4string;
   T0 = ecl_minus(v3end,v2start);
   v4string = cl_make_string(1, T0);
   {
    cl_object v5i;
    v5i = ecl_make_fixnum(0);
    {
     cl_object v6j;
     cl_object v7;
     T0 = cl_realp(v2start);
     if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("REAL",703),v2start);
     v6j = v2start;
     T0 = cl_realp(v3end);
     if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("REAL",703),v3end);
     v7 = v3end;
L8:;
     if (!(ecl_number_compare(v6j,v7)>=0)) { goto L10; }
     goto L9;
L10:;
     {
      cl_fixnum v8;
      if (ecl_unlikely((ecl_fixnum(v6j))>=(v1vector)->vector.dim))
           FEwrong_index(ECL_NIL,v1vector,-1,ecl_make_fixnum(ecl_fixnum(v6j)),(v1vector)->vector.dim);
      v8 = ecl_fixnum(v6j);
      T0 = ecl_aref_unsafe(v1vector,v8);
     }
     T1 = cl_code_char(T0);
     si_char_set(v4string,v5i,T1);
     {
      cl_object v8;
      v8 = ecl_one_plus(v5i);
      T0 = cl_realp(v8);
      if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("REAL",703),v8);
      v5i = v8;
     }
     {
      cl_object v8;
      v8 = ecl_one_plus(v6j);
      T0 = cl_realp(v8);
      if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("REAL",703),v8);
      v6j = v8;
     }
     goto L8;
L9:;
    }
   }
   value0 = v4string;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for BLOCK-ASCIIZ-STRING                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4block_asciiz_string(cl_object v1block, cl_object v2start, cl_object v3length)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4end;
   cl_object v5eos;
   v4end = ecl_plus(v2start,v3length);
   value0 = cl_position(6, ecl_make_fixnum(0), v1block, ECL_SYM("START",1310), v2start, ECL_SYM("END",1225), v4end);
   if ((value0)!=ECL_NIL) { goto L4; }
   v5eos = v4end;
   goto L2;
L4:;
   v5eos = value0;
   goto L2;
L2:;
   value0 = L3ascii_subseq(v1block, v2start, v5eos);
   return value0;
  }
 }
}
/*	function definition for PREFIX                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5prefix(cl_object v1header)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (ecl_unlikely((345)>=(v1header)->vector.dim))
           FEwrong_index(ECL_NIL,v1header,-1,ecl_make_fixnum(345),(v1header)->vector.dim);
  T0 = ecl_aref_unsafe(v1header,345);
  if (!(ecl_plusp(T0))) { goto L1; }
  value0 = L4block_asciiz_string(v1header, ecl_make_fixnum(345), ecl_make_fixnum(155));
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for NAME                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6name(cl_object v1header)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L4block_asciiz_string(v1header, ecl_make_fixnum(0), ecl_make_fixnum(100));
  return value0;
 }
}
/*	function definition for PAYLOAD-SIZE                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7payload_size(cl_object v1header)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = L4block_asciiz_string(v1header, ecl_make_fixnum(124), ecl_make_fixnum(12));
  value0 = cl_parse_integer(3, T0, ECL_SYM("RADIX",1295), ecl_make_fixnum(8));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for NTH-BLOCK                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8nth_block(cl_object volatile v1n, cl_object volatile v2file)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   volatile cl_object v3stream;
   v3stream = cl_open(3, v2file, ECL_SYM("ELEMENT-TYPE",1224), VV[7]);
   {
    volatile bool unwinding = FALSE;
    cl_index v4=ECL_STACK_INDEX(cl_env_copy),v5;
    ecl_frame_ptr next_fr;
    if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
      unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
    } else {
    {
     struct ecl_stack_frame _ecl_inner_frame_aux;
     volatile cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
     {
      cl_object v6;
      v6 = _ecl_inner_frame;
      {
       cl_object v7block;
       v7block = L1make_block_buffer();
       T0 = ecl_one_minus(v1n);
       L2skip_n_blocks(T0, v3stream);
       cl_read_sequence(2, v7block, v3stream);
       cl_env_copy->values[0] = v7block;
       cl_env_copy->nvalues = 1;
      }
      ecl_stack_frame_push_values(v6);
      if (Null(v3stream)) { goto L10; }
      cl_close(1, v3stream);
L10:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v6);
     }
     ecl_stack_frame_close(_ecl_inner_frame);
    }
    }
    ecl_frs_pop(cl_env_copy);
    v5=ecl_stack_push_values(cl_env_copy);
    if (Null(v3stream)) { goto L12; }
    cl_close(3, v3stream, ECL_SYM("ABORT",1195), ECL_T);
L12:;
    ecl_stack_pop_values(cl_env_copy,v5);
    if (unwinding) ecl_unwind(cl_env_copy,next_fr);
    ECL_STACK_SET_INDEX(cl_env_copy,v4);
    return cl_env_copy->values[0];
   }
  }
 }
}
/*	function definition for PAYLOAD-TYPE                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L9payload_type(cl_object v1code)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!((v1code)==(ecl_make_fixnum(0)))) { goto L1; }
  value0 = ECL_SYM("FILE",1237);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (!((v1code)==(ecl_make_fixnum(48)))) { goto L3; }
  value0 = ECL_SYM("FILE",1237);
  cl_env_copy->nvalues = 1;
  return value0;
L3:;
  if (!((v1code)==(ecl_make_fixnum(50)))) { goto L5; }
  value0 = VV[9];
  cl_env_copy->nvalues = 1;
  return value0;
L5:;
  if (!((v1code)==(ecl_make_fixnum(76)))) { goto L7; }
  value0 = VV[10];
  cl_env_copy->nvalues = 1;
  return value0;
L7:;
  if (!((v1code)==(ecl_make_fixnum(53)))) { goto L9; }
  value0 = ECL_SYM("DIRECTORY",1219);
  cl_env_copy->nvalues = 1;
  return value0;
L9:;
  if (!((v1code)==(ecl_make_fixnum(103)))) { goto L11; }
  value0 = VV[11];
  cl_env_copy->nvalues = 1;
  return value0;
L11:;
  value0 = VV[12];
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for FULL-PATH                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L10full_path(cl_object v1header)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   cl_object v3;
   v2 = L5prefix(v1header);
   v3 = L6name(v1header);
   if (Null(v2)) { goto L3; }
   value0 = cl_format(4, ECL_NIL, _ecl_static_2, v2, v3);
   return value0;
L3:;
   value0 = v3;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for SAVE-FILE                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L11save_file(cl_object volatile v1file, cl_object volatile v2size, cl_object volatile v3stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   volatile cl_object v5;                         /*  FULL-BLOCKS     */
   volatile cl_object v6;                         /*  PARTIAL         */
   value0 = ecl_truncate2(v2size,ecl_make_fixnum(512));
   v5 = value0;
   v6 = cl_env_copy->values[1];
   cl_ensure_directories_exist(1, v1file);
   {
    volatile cl_object v7outstream;
    v7outstream = cl_open(7, v1file, ECL_SYM("DIRECTION",1218), ECL_SYM("OUTPUT",1282), ECL_SYM("IF-EXISTS",1245), ECL_SYM("SUPERSEDE",1314), ECL_SYM("ELEMENT-TYPE",1224), VV[7]);
    {
     volatile bool unwinding = FALSE;
     cl_index v8=ECL_STACK_INDEX(cl_env_copy),v9;
     ecl_frame_ptr next_fr;
     if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
       unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
     } else {
     {
      struct ecl_stack_frame _ecl_inner_frame_aux;
      volatile cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
      {
       cl_object v10;
       v10 = _ecl_inner_frame;
       {
        cl_object v11block;
        v11block = L1make_block_buffer();
        {
         cl_object v12i;
         v12i = ecl_make_fixnum(0);
         goto L13;
L12:;
         cl_read_sequence(2, v11block, v3stream);
         cl_write_sequence(2, v11block, v7outstream);
         v12i = ecl_one_plus(v12i);
L13:;
         if (!(ecl_number_compare(v12i,v5)<0)) { goto L19; }
         goto L12;
L19:;
        }
        if (!(ecl_plusp(v6))) { goto L21; }
        cl_read_sequence(2, v11block, v3stream);
        cl_env_copy->values[0] = cl_write_sequence(4, v11block, v7outstream, ECL_SYM("END",1225), v6);
        goto L8;
L21:;
        cl_env_copy->values[0] = ECL_NIL;
        cl_env_copy->nvalues = 1;
       }
L8:;
       ecl_stack_frame_push_values(v10);
       if (Null(v7outstream)) { goto L24; }
       cl_close(1, v7outstream);
L24:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v10);
      }
      ecl_stack_frame_close(_ecl_inner_frame);
     }
     }
     ecl_frs_pop(cl_env_copy);
     v9=ecl_stack_push_values(cl_env_copy);
     if (Null(v7outstream)) { goto L26; }
     cl_close(3, v7outstream, ECL_SYM("ABORT",1195), ECL_T);
L26:;
     ecl_stack_pop_values(cl_env_copy,v9);
     if (unwinding) ecl_unwind(cl_env_copy,next_fr);
     ECL_STACK_SET_INDEX(cl_env_copy,v8);
     return cl_env_copy->values[0];
    }
   }
  }
 }
}
/*	function definition for UNPACK-TARBALL                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L12unpack_tarball(volatile cl_narg narg, cl_object volatile v1tarfile, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  volatile cl_object v2directory;
  ecl_va_list args; ecl_va_start(args,v1tarfile,narg,1);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L12unpack_tarballkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[1])) {
    v2directory = ecl_symbol_value(ECL_SYM("*DEFAULT-PATHNAME-DEFAULTS*",32));
   } else {
    v2directory = keyvars[0];
   }
  }
  {
   volatile cl_object v3block;
   v3block = L1make_block_buffer();
   {
    volatile cl_object v4stream;
    v4stream = cl_open(3, v1tarfile, ECL_SYM("ELEMENT-TYPE",1224), VV[7]);
    {
     volatile bool unwinding = FALSE;
     cl_index v5=ECL_STACK_INDEX(cl_env_copy),v6;
     ecl_frame_ptr next_fr;
     if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
       unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
     } else {
     {
      struct ecl_stack_frame _ecl_inner_frame_aux;
      volatile cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
      {
       cl_object v7;
       v7 = _ecl_inner_frame;
L9:;
       {
        cl_fixnum v8size;
        v8size = ecl_fixnum(cl_read_sequence(2, v3block, v4stream));
        if (!((v8size)==0)) { goto L12; }
        cl_env_copy->values[0] = ECL_NIL;
        cl_env_copy->nvalues = 1;
        goto L8;
L12:;
        if ((v8size)==(512)) { goto L14; }
        cl_error(1, _ecl_static_3);
L14:;
        T0 = (ECL_SYM("ZEROP",926)->symbol.gfdef);
        if (Null(cl_every(2, T0, v3block))) { goto L16; }
        cl_env_copy->values[0] = ECL_NIL;
        cl_env_copy->nvalues = 1;
        goto L8;
L16:;
        {
         cl_object v9payload_code;
         cl_object v10payload_type;
         cl_object v11tar_path;
         cl_object v12full_path;
         cl_object v13payload_size;
         cl_object v14block_count;
         if (ecl_unlikely((156)>=(v3block)->vector.dim))
           FEwrong_index(ECL_NIL,v3block,-1,ecl_make_fixnum(156),(v3block)->vector.dim);
         v9payload_code = ecl_aref_unsafe(v3block,156);
         v10payload_type = L9payload_type(v9payload_code);
         v11tar_path = L10full_path(v3block);
         v12full_path = cl_merge_pathnames(2, v11tar_path, v2directory);
         v13payload_size = L7payload_size(v3block);
         T0 = L7payload_size(v3block);
         v14block_count = ecl_ceiling2(T0,ecl_make_fixnum(512));
         if (!(ecl_eql(v10payload_type,ECL_SYM("FILE",1237)))) { goto L27; }
         L11save_file(v12full_path, v13payload_size, v4stream);
         goto L10;
L27:;
         if (!(ecl_eql(v10payload_type,ECL_SYM("DIRECTORY",1219)))) { goto L29; }
         cl_ensure_directories_exist(1, v12full_path);
         goto L10;
L29:;
         if (!(ecl_eql(v10payload_type,VV[9]))) { goto L36; }
         goto L33;
         goto L34;
L36:;
         goto L34;
L34:;
         if (!(ecl_eql(v10payload_type,VV[10]))) { goto L40; }
         goto L33;
         goto L38;
L40:;
         goto L38;
L38:;
         if (!(ecl_eql(v10payload_type,VV[11]))) { goto L31; }
         goto L32;
L33:;
L32:;
         L2skip_n_blocks(v14block_count, v4stream);
         goto L10;
L31:;
         (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(2, _ecl_static_4, v9payload_code) /*  WARN */;
         L2skip_n_blocks(v14block_count, v4stream);
        }
       }
L10:;
       goto L9;
L8:;
       ecl_stack_frame_push_values(v7);
       if (Null(v4stream)) { goto L45; }
       cl_close(1, v4stream);
L45:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v7);
      }
      ecl_stack_frame_close(_ecl_inner_frame);
     }
     }
     ecl_frs_pop(cl_env_copy);
     v6=ecl_stack_push_values(cl_env_copy);
     if (Null(v4stream)) { goto L47; }
     cl_close(3, v4stream, ECL_SYM("ABORT",1195), ECL_T);
L47:;
     ecl_stack_pop_values(cl_env_copy,v6);
     if (unwinding) ecl_unwind(cl_env_copy,next_fr);
     ECL_STACK_SET_INDEX(cl_env_copy,v5);
     return cl_env_copy->values[0];
    }
   }
  }
 }
}
/*	function definition for CONTENTS                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L13contents(cl_object volatile v1tarfile)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   volatile cl_object v2;
   volatile cl_object v3result;
   v2 = L1make_block_buffer();
   v3result = ECL_NIL;
   {
    volatile cl_object v4stream;
    v4stream = cl_open(3, v1tarfile, ECL_SYM("ELEMENT-TYPE",1224), VV[7]);
    {
     volatile bool unwinding = FALSE;
     cl_index v5=ECL_STACK_INDEX(cl_env_copy),v6;
     ecl_frame_ptr next_fr;
     if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
       unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
     } else {
     {
      struct ecl_stack_frame _ecl_inner_frame_aux;
      volatile cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
      {
       cl_object v7;
       v7 = _ecl_inner_frame;
L9:;
       {
        cl_fixnum v8size;
        v8size = ecl_fixnum(cl_read_sequence(2, v2, v4stream));
        if (!((v8size)==0)) { goto L12; }
        cl_env_copy->values[0] = cl_nreverse(v3result);
        goto L8;
L12:;
        if ((v8size)==(512)) { goto L14; }
        cl_error(1, _ecl_static_3);
L14:;
        T0 = (ECL_SYM("ZEROP",926)->symbol.gfdef);
        if (Null(cl_every(2, T0, v2))) { goto L16; }
        cl_env_copy->values[0] = cl_nreverse(v3result);
        goto L8;
L16:;
        {
         cl_object v9payload_type;
         cl_object v10tar_path;
         cl_object v11payload_size;
         if (ecl_unlikely((156)>=(v2)->vector.dim))
           FEwrong_index(ECL_NIL,v2,-1,ecl_make_fixnum(156),(v2)->vector.dim);
         T0 = ecl_aref_unsafe(v2,156);
         v9payload_type = L9payload_type(T0);
         v10tar_path = L10full_path(v2);
         v11payload_size = L7payload_size(v2);
         T0 = ecl_ceiling2(v11payload_size,ecl_make_fixnum(512));
         L2skip_n_blocks(T0, v4stream);
         if (!(ecl_eql(v9payload_type,ECL_SYM("FILE",1237)))) { goto L26; }
         v3result = CONS(v10tar_path,v3result);
         goto L10;
L26:;
         if (!(ecl_eql(v9payload_type,ECL_SYM("DIRECTORY",1219)))) { goto L10; }
         v3result = CONS(v10tar_path,v3result);
        }
       }
L10:;
       goto L9;
L8:;
       ecl_stack_frame_push_values(v7);
       if (Null(v4stream)) { goto L32; }
       cl_close(1, v4stream);
L32:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v7);
      }
      ecl_stack_frame_close(_ecl_inner_frame);
     }
     }
     ecl_frs_pop(cl_env_copy);
     v6=ecl_stack_push_values(cl_env_copy);
     if (Null(v4stream)) { goto L34; }
     cl_close(3, v4stream, ECL_SYM("ABORT",1195), ECL_T);
L34:;
     ecl_stack_pop_values(cl_env_copy,v6);
     if (unwinding) ecl_unwind(cl_env_copy,next_fr);
     ECL_STACK_SET_INDEX(cl_env_copy,v5);
     return cl_env_copy->values[0];
    }
   }
  }
 }
}

#include "ext/minitar.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclTaxIcB1NOGWj9_k55UOE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("EXT:QUICKLISP;MINITAR.LISP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclTaxIcB1NOGWj9_k55UOE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 ecl_function_dispatch(cl_env_copy,VV[21])(10, _ecl_static_0, ECL_NIL, _ecl_static_1, VVtemp[0], ECL_NIL, ECL_NIL, VVtemp[1], ECL_NIL, ECL_NIL, ECL_NIL) /*  DODEFPACKAGE */;
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[22]);                           /*  MAKE-BLOCK-BUFFER */
 ecl_cmp_defun(VV[23]);                           /*  SKIP-N-BLOCKS   */
 ecl_cmp_defun(VV[24]);                           /*  ASCII-SUBSEQ    */
 ecl_cmp_defun(VV[25]);                           /*  BLOCK-ASCIIZ-STRING */
 ecl_cmp_defun(VV[26]);                           /*  PREFIX          */
 ecl_cmp_defun(VV[27]);                           /*  NAME            */
 ecl_cmp_defun(VV[28]);                           /*  PAYLOAD-SIZE    */
 ecl_cmp_defun(VV[29]);                           /*  NTH-BLOCK       */
 ecl_cmp_defun(VV[30]);                           /*  PAYLOAD-TYPE    */
 ecl_cmp_defun(VV[31]);                           /*  FULL-PATH       */
 ecl_cmp_defun(VV[32]);                           /*  SAVE-FILE       */
 ecl_cmp_defun(VV[33]);                           /*  UNPACK-TARBALL  */
 ecl_cmp_defun(VV[35]);                           /*  CONTENTS        */
}
