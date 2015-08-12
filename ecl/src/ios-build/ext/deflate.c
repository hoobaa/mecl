/*	Compiler: ECL 12.12.1                                         */
/*	Source: EXT:DEFLATE;DEFLATE.LISP                              */
#include <ecl/ecl-cmp.h>
#include "ext/deflate.eclh"
/*	local function G0                                             */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object LC2__g0()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC1__g1,ECL_NIL,Cblock,2);
  value0 = v1;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G1                                             */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object LC1__g1(cl_object v1c, cl_object v2s)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v3;
  v3 = ECL_SYM_VAL(cl_env_copy,ECL_SYM("+IO-SYNTAX-PROGV-LIST+",1720));
  {
   cl_object v5, v6; cl_index v4;
   v5 = ECL_CONS_CAR(v3);
   v6 = ECL_CONS_CDR(v3);
   v4 = ecl_progv(cl_env_copy, v5, v6);
   ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-READABLY*",57),ECL_NIL); /*  *PRINT-READABLY* */
   T0 = (cl_env_copy->function=(ECL_SYM("SIMPLE-CONDITION-FORMAT-CONTROL",768)->symbol.gfdef))->cfun.entry(1, v1c) /*  SIMPLE-CONDITION-FORMAT-CONTROL */;
   T1 = (cl_env_copy->function=(ECL_SYM("SIMPLE-CONDITION-FORMAT-ARGUMENTS",769)->symbol.gfdef))->cfun.entry(1, v1c) /*  SIMPLE-CONDITION-FORMAT-ARGUMENTS */;
   value0 = cl_format(4, v2s, _ecl_static_1, T0, T1);
   ecl_bds_unwind(cl_env_copy,v4);
   return value0;
  }
 }
}
/*	local function G2                                             */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object LC4__g2()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC3__g3,ECL_NIL,Cblock,2);
  value0 = v1;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G3                                             */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object LC3__g3(cl_object v1c, cl_object v2s)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v3;
  v3 = ECL_SYM_VAL(cl_env_copy,ECL_SYM("+IO-SYNTAX-PROGV-LIST+",1720));
  {
   cl_object v5, v6; cl_index v4;
   v5 = ECL_CONS_CAR(v3);
   v6 = ECL_CONS_CDR(v3);
   v4 = ecl_progv(cl_env_copy, v5, v6);
   ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-READABLY*",57),ECL_NIL); /*  *PRINT-READABLY* */
   T0 = (cl_env_copy->function=(ECL_SYM("SIMPLE-CONDITION-FORMAT-CONTROL",768)->symbol.gfdef))->cfun.entry(1, v1c) /*  SIMPLE-CONDITION-FORMAT-CONTROL */;
   T1 = (cl_env_copy->function=(ECL_SYM("SIMPLE-CONDITION-FORMAT-ARGUMENTS",769)->symbol.gfdef))->cfun.entry(1, v1c) /*  SIMPLE-CONDITION-FORMAT-ARGUMENTS */;
   value0 = cl_format(4, v2s, _ecl_static_2, T0, T1);
   ecl_bds_unwind(cl_env_copy,v4);
   return value0;
  }
 }
}
/*	local function G4                                             */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object LC6__g4()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC5__g5,ECL_NIL,Cblock,2);
  value0 = v1;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G5                                             */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object LC5__g5(cl_object v1c, cl_object v2s)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v3;
  v3 = ECL_SYM_VAL(cl_env_copy,ECL_SYM("+IO-SYNTAX-PROGV-LIST+",1720));
  {
   cl_object v5, v6; cl_index v4;
   v5 = ECL_CONS_CAR(v3);
   v6 = ECL_CONS_CDR(v3);
   v4 = ecl_progv(cl_env_copy, v5, v6);
   ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-READABLY*",57),ECL_NIL); /*  *PRINT-READABLY* */
   T0 = (cl_env_copy->function=(ECL_SYM("SIMPLE-CONDITION-FORMAT-CONTROL",768)->symbol.gfdef))->cfun.entry(1, v1c) /*  SIMPLE-CONDITION-FORMAT-CONTROL */;
   T1 = (cl_env_copy->function=(ECL_SYM("SIMPLE-CONDITION-FORMAT-ARGUMENTS",769)->symbol.gfdef))->cfun.entry(1, v1c) /*  SIMPLE-CONDITION-FORMAT-ARGUMENTS */;
   value0 = cl_format(4, v2s, _ecl_static_2, T0, T1);
   ecl_bds_unwind(cl_env_copy,v4);
   return value0;
  }
 }
}
/*	function definition for UPDATE-ADLER32-CHECKSUM               */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L7update_adler32_checksum(cl_object v1crc, cl_object v2buffer, cl_object v3end)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 cl_fixnum v4crc;
 cl_fixnum v5end;
 v4crc = ecl_fixnum(v1crc);
 v5end = ecl_fixnum(v3end);
TTL:
 {
  cl_fixnum v6;
  cl_fixnum v7;
  cl_fixnum v8s1;
  cl_fixnum v9s2;
  v6 = ecl_fixnum(ecl_make_fixnum((((~((cl_fixnum)-1 << (16))) << (0)) & (cl_fixnum)(v4crc)) >> (0)));
  v7 = ecl_fixnum(ecl_make_fixnum((((~((cl_fixnum)-1 << (16))) << (16)) & (cl_fixnum)(v4crc)) >> (16)));
  v8s1 = v6;
  v9s2 = v7;
  {
   cl_fixnum v10i;
   v10i = 0;
   goto L8;
L7:;
   {
    uint8_t v11;
    v11 = (uint8_t)((v2buffer)->vector.self.b8[v10i]);
    T0 = ecl_plus(ecl_make_fixnum(v8s1),ecl_make_uint8_t(v11));
    v8s1 = ecl_fixnum((ecl_floor2(T0,ecl_make_fixnum(65521)),cl_env_copy->values[1]));
   }
   T0 = ecl_plus(ecl_make_fixnum(v9s2),ecl_make_fixnum(v8s1));
   v9s2 = ecl_fixnum((ecl_floor2(T0,ecl_make_fixnum(65521)),cl_env_copy->values[1]));
   v10i = (v10i)+1;
L8:;
   if (!((v10i)<(v5end))) { goto L17; }
   goto L7;
L17:;
  }
  T0 = cl_byte(ecl_make_fixnum(16), ecl_make_fixnum(16));
  value0 = cl_dpb(ecl_make_fixnum(v9s2), T0, ecl_make_fixnum(v8s1));
  return value0;
 }
}
/*	function definition for GENERATE-CRC32-TABLE                  */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object L8generate_crc32_table()
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v1result;
  v1result = si_make_vector(ECL_SYM("BYTE32",1332), ecl_make_fixnum(256), ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
  {
   cl_fixnum v2;
   v2 = (v1result)->vector.fillp;
   {
    cl_fixnum v3i;
    v3i = 0;
    goto L6;
L5:;
    {
     cl_object v4cur;
     v4cur = ecl_make_fixnum(v3i);
     {
      cl_fixnum v5k;
      v5k = 0;
      goto L13;
L12:;
      T0 = ecl_boole(ECL_BOOLAND,(v4cur),(ecl_make_fixnum(1)));
      if (!(ecl_number_equalp(ecl_make_fixnum(1),T0))) { goto L17; }
      T0 = ecl_ash(v4cur,-1);
      v4cur = ecl_boole(ECL_BOOLXOR,(T0),(ecl_make_fixnum(3988292384)));
      goto L16;
L17:;
      v4cur = ecl_ash(v4cur,-1);
L16:;
      v5k = (v5k)+1;
L13:;
      if (!((v5k)<(8))) { goto L21; }
      goto L12;
L21:;
     }
     (v1result)->vector.self.b32[v3i]= ecl_fixnum(v4cur);
    }
    v3i = (v3i)+1;
L6:;
    if (!((v3i)<(v2))) { goto L25; }
    goto L5;
L25:;
    value0 = v1result;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for UPDATE-CRC32-CHECKSUM                 */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L9update_crc32_checksum(cl_object v1crc, cl_object v2buffer, cl_object v3end)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 cl_fixnum v4crc;
 cl_fixnum v5end;
 v4crc = ecl_fixnum(v1crc);
 v5end = ecl_fixnum(v3end);
TTL:
 {
  cl_object v6;
  cl_fixnum v7cur;
  v6 = ecl_make_fixnum(((v4crc) ^ (4294967295)));
  v7cur = ecl_fixnum(v6);
  {
   cl_fixnum v8i;
   v8i = 0;
   goto L6;
L5:;
   {
    uint8_t v9index;
    {
     uint8_t v10;
     v10 = (uint8_t)((v2buffer)->vector.self.b8[v8i]);
     {
      cl_fixnum v11;
      v11 = ((v7cur) ^ ((cl_fixnum)(v10)));
      v9index = (uint8_t)(((255) & (v11)));
     }
    }
    {
     cl_fixnum v10;
     v10 = (cl_fixnum)((VV[10])->vector.self.b32[(cl_fixnum)(v9index)]);
     T0 = ecl_ash(ecl_make_fixnum(v7cur),-8);
     v7cur = ecl_fixnum(ecl_boole(ECL_BOOLXOR,(ecl_make_fixnum(v10)),(T0)));
    }
   }
   v8i = (v8i)+1;
L6:;
   if (!((v8i)<(v5end))) { goto L15; }
   goto L5;
L15:;
  }
  value0 = ecl_make_fixnum(((v7cur) ^ (4294967295)));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for MAKE-SLIDING-WINDOW-STREAM            */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object L10make_sliding_window_stream(cl_narg narg, ...)
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
  cl_parse_key(args,5,L10make_sliding_window_streamkeys,keyvars,NULL,FALSE);
  ecl_va_end(args);
  v1 = keyvars[0];
  if (Null(keyvars[6])) {
   v2 = si_make_vector(ECL_SYM("BYTE8",1330), ecl_make_fixnum(32768), ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
  } else {
   v2 = keyvars[1];
  }
  if (Null(keyvars[7])) {
   v3 = ecl_make_fixnum(0);
  } else {
   v3 = keyvars[2];
  }
  v4 = keyvars[3];
  if (Null(keyvars[9])) {
   v5 = ecl_make_fixnum(0);
  } else {
   v5 = keyvars[4];
  }
 }
 {
  cl_fixnum v6;
  v6 = 0;
  if (!(ECL_FIXNUMP(v5))) { goto L8; }
  v6 = ecl_fixnum(v5);
  if (!((v6)<=(4294967295))) { goto L13; }
  if ((v6)>=(0)) { goto L4; }
  goto L5;
L13:;
  goto L5;
L8:;
  goto L5;
 }
L5:;
 si_structure_type_error(4, v5, VV[16], VV[13], VV[17]);
L4:;
 if (ECL_SYMBOLP(v4)) { goto L15; }
 si_structure_type_error(4, v4, ECL_SYM("SYMBOL",840), VV[13], VV[18]);
L15:;
 if (ECL_FIXNUMP(v3)) { goto L17; }
 si_structure_type_error(4, v3, ECL_SYM("FIXNUM",372), VV[13], VV[19]);
L17:;
 if ((cl_typep(2, v2, VV[20]))!=ECL_NIL) { goto L19; }
 si_structure_type_error(4, v2, VV[20], VV[13], VV[21]);
L19:;
 if ((cl_streamp(v1))!=ECL_NIL) { goto L21; }
 si_structure_type_error(4, v1, ECL_SYM("STREAM",799), VV[13], ECL_SYM("STREAM",799));
L21:;
 value0 = si_make_structure(6, VV[22], v1, v2, v3, v4, v5);
 return value0;
}
/*	function definition for SLIDING-WINDOW-STREAM-WRITE-BYTE      */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object L11sliding_window_stream_write_byte(cl_object v1stream, cl_object v2byte)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 uint8_t v3byte;
 v3byte = ecl_fixnum(v2byte);
TTL:
 {
  cl_fixnum v4end;
  v4end = ecl_fixnum(ecl_function_dispatch(cl_env_copy,VV[97])(1, v1stream) /*  SLIDING-WINDOW-STREAM-BUFFER-END */);
  if ((v4end)<(32768)) { goto L2; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[98])(1, v1stream) /*  SLIDING-WINDOW-STREAM-BUFFER */;
  T1 = ecl_function_dispatch(cl_env_copy,VV[99])(1, v1stream) /*  SLIDING-WINDOW-STREAM-STREAM */;
  cl_write_sequence(2, T0, T1);
  {
   cl_object v5;
   v5 = ecl_function_dispatch(cl_env_copy,VV[100])(1, v1stream) /*  SLIDING-WINDOW-STREAM-CHECKSUM */;
   if (!(ecl_eql(v5,VV[24]))) { goto L7; }
   {
    cl_fixnum v6;
    T0 = ecl_function_dispatch(cl_env_copy,VV[101])(1, v1stream) /*  SLIDING-WINDOW-STREAM-CHECKSUM-VALUE */;
    T1 = ecl_function_dispatch(cl_env_copy,VV[98])(1, v1stream) /*  SLIDING-WINDOW-STREAM-BUFFER */;
    v6 = ecl_fixnum(L7update_adler32_checksum(T0, T1, ecl_make_fixnum(32768)));
    (v1stream)->instance.slots[4]=ecl_make_fixnum(v6);
    goto L5;
   }
L7:;
   if (!(ecl_eql(v5,VV[25]))) { goto L5; }
   {
    cl_fixnum v7;
    T0 = ecl_function_dispatch(cl_env_copy,VV[101])(1, v1stream) /*  SLIDING-WINDOW-STREAM-CHECKSUM-VALUE */;
    T1 = ecl_function_dispatch(cl_env_copy,VV[98])(1, v1stream) /*  SLIDING-WINDOW-STREAM-BUFFER */;
    v7 = ecl_fixnum(L9update_crc32_checksum(T0, T1, ecl_make_fixnum(32768)));
    (v1stream)->instance.slots[4]=ecl_make_fixnum(v7);
   }
  }
L5:;
  v4end = 0;
L2:;
  {
   cl_object v5;
   v5 = ecl_function_dispatch(cl_env_copy,VV[98])(1, v1stream) /*  SLIDING-WINDOW-STREAM-BUFFER */;
   ecl_aset_unsafe(v5,v4end,ecl_make_uint8_t(v3byte));
  }
  {
   cl_object v5;
   v5 = ecl_make_integer((v4end)+1);
   value0 = (v1stream)->instance.slots[2]=v5;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for SLIDING-WINDOW-STREAM-FLUSH           */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object L12sliding_window_stream_flush(cl_object v1stream)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_fixnum v2end;
  v2end = ecl_fixnum(ecl_function_dispatch(cl_env_copy,VV[97])(1, v1stream) /*  SLIDING-WINDOW-STREAM-BUFFER-END */);
  if ((v2end)==0) { goto L2; }
  {
   cl_object v3;
   v3 = ecl_function_dispatch(cl_env_copy,VV[100])(1, v1stream) /*  SLIDING-WINDOW-STREAM-CHECKSUM */;
   if (!(ecl_eql(v3,VV[24]))) { goto L6; }
   {
    cl_fixnum v4;
    T0 = ecl_function_dispatch(cl_env_copy,VV[101])(1, v1stream) /*  SLIDING-WINDOW-STREAM-CHECKSUM-VALUE */;
    T1 = ecl_function_dispatch(cl_env_copy,VV[98])(1, v1stream) /*  SLIDING-WINDOW-STREAM-BUFFER */;
    v4 = ecl_fixnum(L7update_adler32_checksum(T0, T1, ecl_make_fixnum(v2end)));
    (v1stream)->instance.slots[4]=ecl_make_fixnum(v4);
    goto L4;
   }
L6:;
   if (!(ecl_eql(v3,VV[25]))) { goto L4; }
   {
    cl_fixnum v5;
    T0 = ecl_function_dispatch(cl_env_copy,VV[101])(1, v1stream) /*  SLIDING-WINDOW-STREAM-CHECKSUM-VALUE */;
    T1 = ecl_function_dispatch(cl_env_copy,VV[98])(1, v1stream) /*  SLIDING-WINDOW-STREAM-BUFFER */;
    v5 = ecl_fixnum(L9update_crc32_checksum(T0, T1, ecl_make_fixnum(v2end)));
    (v1stream)->instance.slots[4]=ecl_make_fixnum(v5);
   }
  }
L4:;
  T0 = ecl_function_dispatch(cl_env_copy,VV[98])(1, v1stream) /*  SLIDING-WINDOW-STREAM-BUFFER */;
  T1 = ecl_function_dispatch(cl_env_copy,VV[99])(1, v1stream) /*  SLIDING-WINDOW-STREAM-STREAM */;
  value0 = cl_write_sequence(4, T0, T1, ECL_SYM("END",1225), ecl_make_fixnum(v2end));
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for SLIDING-WINDOW-STREAM-COPY-BYTES      */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object L13sliding_window_stream_copy_bytes(cl_object v1stream, cl_object v2distance, cl_object v3length)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 cl_fixnum v4distance;
 cl_fixnum v5length;
 v4distance = ecl_fixnum(v2distance);
 v5length = ecl_fixnum(v3length);
TTL:
 {
  cl_fixnum v6end;
  cl_fixnum v7start;
  cl_object v8buffer;
  v6end = ecl_fixnum(ecl_function_dispatch(cl_env_copy,VV[97])(1, v1stream) /*  SLIDING-WINDOW-STREAM-BUFFER-END */);
  T0 = ecl_minus(ecl_make_fixnum(v6end),ecl_make_fixnum(v4distance));
  v7start = ecl_fixnum((ecl_floor2(T0,ecl_make_fixnum(32768)),cl_env_copy->values[1]));
  v8buffer = ecl_function_dispatch(cl_env_copy,VV[98])(1, v1stream) /*  SLIDING-WINDOW-STREAM-BUFFER */;
  {
   cl_fixnum v9i;
   v9i = 0;
   goto L6;
L5:;
   {
    uint8_t v10;
    T0 = ecl_plus(ecl_make_fixnum(v7start),ecl_make_fixnum(v9i));
    T1 = (ecl_floor2(T0,ecl_make_fixnum(32768)),cl_env_copy->values[1]);
    v10 = (uint8_t)((v8buffer)->vector.self.b8[ecl_fixnum(T1)]);
    {
     cl_fixnum v11end;
     v11end = ecl_fixnum(ecl_function_dispatch(cl_env_copy,VV[97])(1, v1stream) /*  SLIDING-WINDOW-STREAM-BUFFER-END */);
     if ((v11end)<(32768)) { goto L11; }
     T0 = ecl_function_dispatch(cl_env_copy,VV[98])(1, v1stream) /*  SLIDING-WINDOW-STREAM-BUFFER */;
     T1 = ecl_function_dispatch(cl_env_copy,VV[99])(1, v1stream) /*  SLIDING-WINDOW-STREAM-STREAM */;
     cl_write_sequence(2, T0, T1);
     {
      cl_object v12;
      v12 = ecl_function_dispatch(cl_env_copy,VV[100])(1, v1stream) /*  SLIDING-WINDOW-STREAM-CHECKSUM */;
      if (!(ecl_eql(v12,VV[24]))) { goto L16; }
      {
       cl_fixnum v13;
       T0 = ecl_function_dispatch(cl_env_copy,VV[101])(1, v1stream) /*  SLIDING-WINDOW-STREAM-CHECKSUM-VALUE */;
       T1 = ecl_function_dispatch(cl_env_copy,VV[98])(1, v1stream) /*  SLIDING-WINDOW-STREAM-BUFFER */;
       v13 = ecl_fixnum(L7update_adler32_checksum(T0, T1, ecl_make_fixnum(32768)));
       (v1stream)->instance.slots[4]=ecl_make_fixnum(v13);
       goto L14;
      }
L16:;
      if (!(ecl_eql(v12,VV[25]))) { goto L14; }
      {
       cl_fixnum v14;
       T0 = ecl_function_dispatch(cl_env_copy,VV[101])(1, v1stream) /*  SLIDING-WINDOW-STREAM-CHECKSUM-VALUE */;
       T1 = ecl_function_dispatch(cl_env_copy,VV[98])(1, v1stream) /*  SLIDING-WINDOW-STREAM-BUFFER */;
       v14 = ecl_fixnum(L9update_crc32_checksum(T0, T1, ecl_make_fixnum(32768)));
       (v1stream)->instance.slots[4]=ecl_make_fixnum(v14);
      }
     }
L14:;
     v11end = 0;
L11:;
     {
      cl_object v12;
      v12 = ecl_function_dispatch(cl_env_copy,VV[98])(1, v1stream) /*  SLIDING-WINDOW-STREAM-BUFFER */;
      ecl_aset_unsafe(v12,v11end,ecl_make_uint8_t(v10));
     }
     {
      cl_object v12;
      v12 = ecl_make_integer((v11end)+1);
      (v1stream)->instance.slots[2]=v12;
     }
    }
   }
   v9i = (v9i)+1;
L6:;
   if (!((v9i)<(v5length))) { goto L27; }
   goto L5;
L27:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for MAKE-BIT-STREAM                       */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object L14make_bit_stream(cl_narg narg, ...)
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
  cl_parse_key(args,4,L14make_bit_streamkeys,keyvars,NULL,FALSE);
  ecl_va_end(args);
  v1 = keyvars[0];
  if (Null(keyvars[5])) {
   v2 = ecl_make_fixnum(0);
  } else {
   v2 = keyvars[1];
  }
  if (Null(keyvars[6])) {
   v3 = ecl_make_fixnum(0);
  } else {
   v3 = keyvars[2];
  }
  if (Null(keyvars[7])) {
   v4 = ecl_make_fixnum(0);
  } else {
   v4 = keyvars[3];
  }
 }
 {
  cl_fixnum v5;
  v5 = 0;
  if (!(ECL_FIXNUMP(v4))) { goto L8; }
  v5 = ecl_fixnum(v4);
  if (!((v5)<=(255))) { goto L13; }
  if ((v5)>=(0)) { goto L4; }
  goto L5;
L13:;
  goto L5;
L8:;
  goto L5;
 }
L5:;
 si_structure_type_error(4, v4, VV[32], VV[29], VV[33]);
L4:;
 {
  cl_fixnum v5;
  v5 = 0;
  if (!(ECL_FIXNUMP(v3))) { goto L19; }
  v5 = ecl_fixnum(v3);
  if (!((v5)<=(536870911))) { goto L24; }
  if ((v5)>=(0)) { goto L15; }
  goto L16;
L24:;
  goto L16;
L19:;
  goto L16;
 }
L16:;
 si_structure_type_error(4, v3, VV[34], VV[29], VV[35]);
L15:;
 if (ECL_FIXNUMP(v2)) { goto L26; }
 si_structure_type_error(4, v2, ECL_SYM("FIXNUM",372), VV[29], VV[36]);
L26:;
 if ((cl_streamp(v1))!=ECL_NIL) { goto L28; }
 si_structure_type_error(4, v1, ECL_SYM("STREAM",799), VV[29], ECL_SYM("STREAM",799));
L28:;
 value0 = si_make_structure(5, VV[37], v1, v2, v3, v4);
 return value0;
}
/*	function definition for BIT-STREAM-GET-BYTE                   */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object L15bit_stream_get_byte(cl_object v1stream)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 T0 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v1stream) /*  BIT-STREAM-STREAM */;
 value0 = cl_read_byte(1, T0);
 return value0;
}
/*	function definition for BIT-STREAM-READ-BITS                  */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object L16bit_stream_read_bits(cl_object v1stream, cl_object v2bits)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
L2:;
 T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1stream) /*  BIT-STREAM-BIT-COUNT */;
 if (ecl_number_compare(T0,v2bits)<0) { goto L4; }
 goto L3;
L4:;
 {
  cl_object v3;
  T0 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1stream) /*  BIT-STREAM-BITS */;
  {
   uint8_t v4;
   T1 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v1stream) /*  BIT-STREAM-STREAM */;
   v4 = ecl_fixnum(cl_read_byte(1, T1));
   T1 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1stream) /*  BIT-STREAM-BIT-COUNT */;
   T2 = cl_ash(ecl_make_uint8_t(v4), T1);
   v3 = ecl_boole(ECL_BOOLIOR,(T0),(T2));
  }
  (v1stream)->instance.slots[2]=v3;
 }
 {
  cl_object v3;
  T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1stream) /*  BIT-STREAM-BIT-COUNT */;
  v3 = ecl_plus(T0,ecl_make_fixnum(8));
  (v1stream)->instance.slots[3]=v3;
 }
 goto L2;
L3:;
 T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1stream) /*  BIT-STREAM-BIT-COUNT */;
 if (!(ecl_number_equalp(T0,v2bits))) { goto L12; }
 {
  cl_object v3;
  v3 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1stream) /*  BIT-STREAM-BITS */;
  (v1stream)->instance.slots[2]=ecl_make_fixnum(0);
  (v1stream)->instance.slots[3]=ecl_make_fixnum(0);
  value0 = v3;
  cl_env_copy->nvalues = 1;
  return value0;
 }
L12:;
 {
  cl_object v4;
  T0 = cl_byte(v2bits, ecl_make_fixnum(0));
  T1 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1stream) /*  BIT-STREAM-BITS */;
  v4 = cl_ldb(T0, T1);
  {
   cl_object v5;
   T0 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1stream) /*  BIT-STREAM-BITS */;
   T1 = ecl_negate(v2bits);
   v5 = cl_ash(T0, T1);
   (v1stream)->instance.slots[2]=v5;
  }
  {
   cl_object v5;
   T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1stream) /*  BIT-STREAM-BIT-COUNT */;
   v5 = ecl_minus(T0,v2bits);
   (v1stream)->instance.slots[3]=v5;
  }
  value0 = v4;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for BIT-STREAM-COPY-BLOCK                 */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L17bit_stream_copy_block(cl_object v1stream, cl_object v2out_stream)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 (v1stream)->instance.slots[2]=ecl_make_fixnum(0);
 (v1stream)->instance.slots[3]=ecl_make_fixnum(0);
 {
  cl_object v3len;
  cl_object v4nlen;
  {
   uint8_t v5;
   T0 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v1stream) /*  BIT-STREAM-STREAM */;
   v5 = ecl_fixnum(cl_read_byte(1, T0));
   {
    uint8_t v6;
    T0 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v1stream) /*  BIT-STREAM-STREAM */;
    v6 = ecl_fixnum(cl_read_byte(1, T0));
    T0 = ecl_ash(ecl_make_uint8_t(v6),8);
    v3len = ecl_boole(ECL_BOOLIOR,(ecl_make_uint8_t(v5)),(T0));
   }
  }
  T0 = cl_byte(ecl_make_fixnum(16), ecl_make_fixnum(0));
  {
   uint8_t v5;
   T1 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v1stream) /*  BIT-STREAM-STREAM */;
   v5 = ecl_fixnum(cl_read_byte(1, T1));
   {
    uint8_t v6;
    T1 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v1stream) /*  BIT-STREAM-STREAM */;
    v6 = ecl_fixnum(cl_read_byte(1, T1));
    T1 = ecl_ash(ecl_make_uint8_t(v6),8);
    T2 = ecl_boole(ECL_BOOLIOR,(ecl_make_uint8_t(v5)),(T1));
    T3 = ecl_boole(ECL_BOOLXOR,(T2),ecl_make_fixnum(-1));
    v4nlen = cl_ldb(T0, T3);
   }
  }
  if (ecl_number_equalp(v3len,v4nlen)) { goto L9; }
  T0 = cl_list(2, v3len, v4nlen);
  cl_error(5, VV[1], ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_5, ECL_SYM("FORMAT-ARGUMENTS",1239), T0);
L9:;
  {
   cl_object v5i;
   v5i = ecl_make_fixnum(0);
   goto L13;
L12:;
   {
    uint8_t v6;
    T0 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v1stream) /*  BIT-STREAM-STREAM */;
    v6 = ecl_fixnum(cl_read_byte(1, T0));
    {
     cl_fixnum v7end;
     v7end = ecl_fixnum(ecl_function_dispatch(cl_env_copy,VV[97])(1, v2out_stream) /*  SLIDING-WINDOW-STREAM-BUFFER-END */);
     if ((v7end)<(32768)) { goto L18; }
     T0 = ecl_function_dispatch(cl_env_copy,VV[98])(1, v2out_stream) /*  SLIDING-WINDOW-STREAM-BUFFER */;
     T1 = ecl_function_dispatch(cl_env_copy,VV[99])(1, v2out_stream) /*  SLIDING-WINDOW-STREAM-STREAM */;
     cl_write_sequence(2, T0, T1);
     {
      cl_object v8;
      v8 = ecl_function_dispatch(cl_env_copy,VV[100])(1, v2out_stream) /*  SLIDING-WINDOW-STREAM-CHECKSUM */;
      if (!(ecl_eql(v8,VV[24]))) { goto L23; }
      {
       cl_fixnum v9;
       T0 = ecl_function_dispatch(cl_env_copy,VV[101])(1, v2out_stream) /*  SLIDING-WINDOW-STREAM-CHECKSUM-VALUE */;
       T1 = ecl_function_dispatch(cl_env_copy,VV[98])(1, v2out_stream) /*  SLIDING-WINDOW-STREAM-BUFFER */;
       v9 = ecl_fixnum(L7update_adler32_checksum(T0, T1, ecl_make_fixnum(32768)));
       (v2out_stream)->instance.slots[4]=ecl_make_fixnum(v9);
       goto L21;
      }
L23:;
      if (!(ecl_eql(v8,VV[25]))) { goto L21; }
      {
       cl_fixnum v10;
       T0 = ecl_function_dispatch(cl_env_copy,VV[101])(1, v2out_stream) /*  SLIDING-WINDOW-STREAM-CHECKSUM-VALUE */;
       T1 = ecl_function_dispatch(cl_env_copy,VV[98])(1, v2out_stream) /*  SLIDING-WINDOW-STREAM-BUFFER */;
       v10 = ecl_fixnum(L9update_crc32_checksum(T0, T1, ecl_make_fixnum(32768)));
       (v2out_stream)->instance.slots[4]=ecl_make_fixnum(v10);
      }
     }
L21:;
     v7end = 0;
L18:;
     {
      cl_object v8;
      v8 = ecl_function_dispatch(cl_env_copy,VV[98])(1, v2out_stream) /*  SLIDING-WINDOW-STREAM-BUFFER */;
      ecl_aset_unsafe(v8,v7end,ecl_make_uint8_t(v6));
     }
     {
      cl_object v8;
      v8 = ecl_make_integer((v7end)+1);
      (v2out_stream)->instance.slots[2]=v8;
     }
    }
   }
   v5i = ecl_one_plus(v5i);
L13:;
   if (!(ecl_number_compare(v5i,v3len)<0)) { goto L34; }
   goto L12;
L34:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for MAKE-DECODE-TREE                      */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object L18make_decode_tree(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 cl_object v1;
 cl_object v2;
 ecl_va_list args; ecl_va_start(args,narg,narg,0);
 {
  cl_object keyvars[4];
  cl_parse_key(args,2,L18make_decode_treekeys,keyvars,NULL,FALSE);
  ecl_va_end(args);
  if (Null(keyvars[2])) {
   T0 = si_make_vector(ECL_SYM("INTEGER64",1338), ecl_make_fixnum(16), ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
   v1 = si_fill_array_with_elt(T0, ecl_make_fixnum(0), ecl_make_fixnum(0), ECL_NIL);
  } else {
   v1 = keyvars[0];
  }
  if (Null(keyvars[3])) {
   T0 = si_make_vector(ECL_SYM("INTEGER64",1338), ecl_make_fixnum(16), ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
   v2 = si_fill_array_with_elt(T0, ecl_make_fixnum(0), ecl_make_fixnum(0), ECL_NIL);
  } else {
   v2 = keyvars[1];
  }
 }
 if ((cl_typep(2, v2, VV[45]))!=ECL_NIL) { goto L3; }
 si_structure_type_error(4, v2, VV[45], VV[42], VV[46]);
L3:;
 if ((cl_typep(2, v1, VV[45]))!=ECL_NIL) { goto L5; }
 si_structure_type_error(4, v1, VV[45], VV[42], VV[47]);
L5:;
 value0 = si_make_structure(3, VV[48], v1, v2);
 return value0;
}
/*	function definition for MAKE-HUFFMAN-DECODE-TREE              */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object L19make_huffman_decode_tree(cl_object v1code_lengths)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v2max_length;
  cl_object v3next_code;
  cl_object v4code_symbols;
  cl_object v5length_count;
  T0 = (ECL_SYM("MAX",551)->symbol.gfdef);
  v2max_length = cl_reduce(4, T0, v1code_lengths, VV[50], ecl_make_fixnum(0));
  T0 = ecl_one_plus(v2max_length);
  T1 = si_make_pure_array(ECL_SYM("INTEGER64",1338), T0, ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
  v3next_code = si_fill_array_with_elt(T1, ecl_make_fixnum(0), ecl_make_fixnum(0), ECL_NIL);
  {
   cl_fixnum v6;
   v6 = ecl_length(v1code_lengths);
   T0 = si_make_pure_array(ECL_SYM("INTEGER64",1338), ecl_make_fixnum(v6), ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
   v4code_symbols = si_fill_array_with_elt(T0, ecl_make_fixnum(0), ecl_make_fixnum(0), ECL_NIL);
  }
  T0 = ecl_one_plus(v2max_length);
  T1 = si_make_pure_array(ECL_SYM("INTEGER64",1338), T0, ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
  v5length_count = si_fill_array_with_elt(T1, ecl_make_fixnum(0), ecl_make_fixnum(0), ECL_NIL);
  {
   cl_object v6index;
   v6index = ecl_make_fixnum(1);
   {
    cl_object v7code;
    v7code = ECL_NIL;
    {
     cl_object v8length;
     cl_fixnum v9;
     cl_fixnum v10;
     v8length = ECL_NIL;
     v9 = 0;
     v10 = 0;
     v10 = (v1code_lengths)->vector.fillp;
L15:;
     if (!((v9)>=(v10))) { goto L19; }
     goto L16;
L19:;
     v8length = ecl_aref_unsafe(v1code_lengths,v9);
     v9 = (v9)+1;
     {
      cl_object v11;
      {
       long v12;
       v12 = (long)((v5length_count)->vector.self.i64[ecl_fixnum(v8length)]);
       v11 = ecl_plus(ecl_make_long(v12),ecl_make_fixnum(1));
      }
      (v5length_count)->vector.self.i64[ecl_fixnum(v8length)]= ecl_to_long(v11);
     }
     goto L15;
L16:;
     (v5length_count)->array.self.fix[0]= 0;
    }
    if (!(ecl_number_compare(v6index,v2max_length)>0)) { goto L30; }
    goto L10;
L30:;
    v7code = ecl_make_fixnum(0);
L9:;
    (v3next_code)->vector.self.i64[ecl_fixnum(v6index)]= ecl_to_long(v7code);
    v6index = ecl_one_plus(v6index);
    if (!(ecl_number_compare(v6index,v2max_length)>0)) { goto L37; }
    goto L10;
L37:;
    {
     long v8;
     T0 = ecl_one_minus(v6index);
     v8 = (long)((v5length_count)->vector.self.i64[ecl_fixnum(T0)]);
     v7code = ecl_plus(v7code,ecl_make_long(v8));
    }
    goto L9;
L10:;
   }
  }
  {
   cl_object v6length;
   cl_fixnum v7;
   cl_fixnum v8;
   v6length = ECL_NIL;
   v7 = 0;
   v8 = 0;
   {
    cl_object v9index;
    v9index = ecl_make_fixnum(0);
    v8 = (v1code_lengths)->vector.fillp;
    if (!((v7)>=(v8))) { goto L52; }
    goto L49;
L52:;
    v6length = ecl_aref_unsafe(v1code_lengths,v7);
    v7 = (v7)+1;
L48:;
    if (ecl_zerop(v6length)) { goto L58; }
    {
     cl_fixnum v10;
     v10 = (cl_fixnum)((v3next_code)->vector.self.i64[ecl_fixnum(v6length)]);
     (v4code_symbols)->vector.self.i64[v10]= ecl_to_long(v9index);
    }
    {
     cl_object v10;
     {
      long v11;
      v11 = (long)((v3next_code)->vector.self.i64[ecl_fixnum(v6length)]);
      v10 = ecl_plus(ecl_make_long(v11),ecl_make_fixnum(1));
     }
     (v3next_code)->vector.self.i64[ecl_fixnum(v6length)]= ecl_to_long(v10);
    }
L58:;
    if (!((v7)>=(v8))) { goto L64; }
    goto L49;
L64:;
    v6length = ecl_aref_unsafe(v1code_lengths,v7);
    v7 = (v7)+1;
    v9index = ecl_one_plus(v9index);
    goto L48;
L49:;
   }
  }
  value0 = L18make_decode_tree(4, VV[51], v5length_count, VV[52], v4code_symbols);
  return value0;
 }
}
/*	function definition for READ-HUFFMAN-CODE                     */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L20read_huffman_code(cl_object v1bit_stream, cl_object v2decode_tree)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v3length_count;
  v3length_count = ecl_function_dispatch(cl_env_copy,VV[118])(1, v2decode_tree) /*  DECODE-TREE-LENGTH-COUNT */;
  {
   cl_object v4code_symbols;
   v4code_symbols = ecl_function_dispatch(cl_env_copy,VV[119])(1, v2decode_tree) /*  DECODE-TREE-CODE-SYMBOLS */;
   {
    cl_fixnum v5code;
    v5code = 0;
    {
     cl_fixnum v6index;
     v6index = 0;
     {
      cl_fixnum v7first;
      v7first = 0;
      {
       cl_fixnum v8;
       cl_fixnum v9length;
       v8 = (v3length_count)->vector.fillp;
       v9length = 1;
       {
        cl_object v10count;
        v10count = ECL_NIL;
        {
         cl_object v11;
         v11 = ECL_NIL;
L15:;
         T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
         if (ecl_number_compare(T0,ecl_make_fixnum(1))<0) { goto L17; }
         goto L16;
L17:;
         {
          cl_object v12;
          T0 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          {
          uint8_t v13;
          T1 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v1bit_stream) /*  BIT-STREAM-STREAM */;
          v13 = ecl_fixnum(cl_read_byte(1, T1));
          T1 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          T2 = cl_ash(ecl_make_uint8_t(v13), T1);
          v12 = ecl_boole(ECL_BOOLIOR,(T0),(T2));
          }
          (v1bit_stream)->instance.slots[2]=v12;
         }
         {
          cl_object v12;
          T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          v12 = ecl_plus(T0,ecl_make_fixnum(8));
          (v1bit_stream)->instance.slots[3]=v12;
         }
         goto L15;
L16:;
         T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
         if (!(ecl_number_equalp(T0,ecl_make_fixnum(1)))) { goto L25; }
         {
          cl_object v12;
          v12 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          (v1bit_stream)->instance.slots[2]=ecl_make_fixnum(0);
          (v1bit_stream)->instance.slots[3]=ecl_make_fixnum(0);
          v5code = ecl_fixnum(v12);
          goto L13;
         }
L25:;
         {
          cl_object v13;
          T0 = cl_byte(ecl_make_fixnum(1), ecl_make_fixnum(0));
          T1 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          v13 = cl_ldb(T0, T1);
          {
          cl_object v14;
          T0 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          {
          cl_fixnum v15;
          v15 = -(1);
          v14 = cl_ash(T0, ecl_make_fixnum(v15));
          }
          (v1bit_stream)->instance.slots[2]=v14;
          }
          {
          cl_object v14;
          T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          v14 = ecl_minus(T0,ecl_make_fixnum(1));
          (v1bit_stream)->instance.slots[3]=v14;
          }
          v5code = ecl_fixnum(v13);
         }
L13:;
         v6index = 0;
         v7first = 0;
L10:;
         if (!((v9length)>=(v8))) { goto L39; }
         goto L11;
L39:;
         v10count = ecl_make_int64_t((v3length_count)->vector.self.i64[v9length]);
         T0 = ecl_plus(ecl_make_fixnum(v7first),v10count);
         if (!((v5code)<(ecl_fixnum(T0)))) { goto L46; }
         T0 = ecl_minus(ecl_make_fixnum(v5code),ecl_make_fixnum(v7first));
         T1 = ecl_plus(ecl_make_fixnum(v6index),T0);
         v11 = ecl_make_int64_t((v4code_symbols)->vector.self.i64[ecl_fixnum(T1)]);
         goto L45;
L46:;
         v11 = ECL_NIL;
L45:;
         if (Null(v11)) { goto L43; }
         value0 = v11;
         cl_env_copy->nvalues = 1;
         return value0;
L43:;
         T0 = ecl_times(ecl_make_fixnum(v5code),ecl_make_fixnum(2));
L52:;
         T2 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
         if (ecl_number_compare(T2,ecl_make_fixnum(1))<0) { goto L54; }
         goto L53;
L54:;
         {
          cl_object v12;
          T2 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          {
          uint8_t v13;
          T3 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v1bit_stream) /*  BIT-STREAM-STREAM */;
          v13 = ecl_fixnum(cl_read_byte(1, T3));
          T3 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          T4 = cl_ash(ecl_make_uint8_t(v13), T3);
          v12 = ecl_boole(ECL_BOOLIOR,(T2),(T4));
          }
          (v1bit_stream)->instance.slots[2]=v12;
         }
         {
          cl_object v12;
          T2 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          v12 = ecl_plus(T2,ecl_make_fixnum(8));
          (v1bit_stream)->instance.slots[3]=v12;
         }
         goto L52;
L53:;
         T2 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
         if (!(ecl_number_equalp(T2,ecl_make_fixnum(1)))) { goto L62; }
         {
          cl_object v12;
          v12 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          (v1bit_stream)->instance.slots[2]=ecl_make_fixnum(0);
          (v1bit_stream)->instance.slots[3]=ecl_make_fixnum(0);
          T1 = v12;
          goto L50;
         }
L62:;
         {
          cl_object v13;
          T2 = cl_byte(ecl_make_fixnum(1), ecl_make_fixnum(0));
          T3 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          v13 = cl_ldb(T2, T3);
          {
          cl_object v14;
          T2 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          {
          cl_fixnum v15;
          v15 = -(1);
          v14 = cl_ash(T2, ecl_make_fixnum(v15));
          }
          (v1bit_stream)->instance.slots[2]=v14;
          }
          {
          cl_object v14;
          T2 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          v14 = ecl_minus(T2,ecl_make_fixnum(1));
          (v1bit_stream)->instance.slots[3]=v14;
          }
          T1 = v13;
         }
L50:;
         v5code = ecl_fixnum(ecl_plus(T0,T1));
         v6index = ecl_fixnum(ecl_plus(ecl_make_fixnum(v6index),v10count));
         T0 = ecl_plus(ecl_make_fixnum(v7first),v10count);
         v7first = ecl_fixnum(ecl_times(T0,ecl_make_fixnum(2)));
         v9length = (v9length)+1;
         goto L10;
L11:;
         T0 = ecl_list1(ecl_make_fixnum(v5code));
         cl_error(5, VV[1], ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_7, ECL_SYM("FORMAT-ARGUMENTS",1239), T0);
         value0 = ECL_NIL;
         cl_env_copy->nvalues = 1;
         return value0;
        }
       }
      }
     }
    }
   }
  }
 }
}
/*	function definition for DECODE-CODE-LENGTH-ENTRIES            */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object L21decode_code_length_entries(cl_object v1bit_stream, cl_object v2count, cl_object v3decode_tree)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v4;
  cl_object v5index;
  T0 = si_make_pure_array(ECL_SYM("INTEGER64",1338), v2count, ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
  v4 = si_fill_array_with_elt(T0, ecl_make_fixnum(0), ecl_make_fixnum(0), ECL_NIL);
  v5index = ecl_make_fixnum(0);
  goto L5;
L4:;
  {
   cl_object v6code;
   {
    cl_object v7length_count;
    v7length_count = ecl_function_dispatch(cl_env_copy,VV[118])(1, v3decode_tree) /*  DECODE-TREE-LENGTH-COUNT */;
    {
     cl_object v8code_symbols;
     v8code_symbols = ecl_function_dispatch(cl_env_copy,VV[119])(1, v3decode_tree) /*  DECODE-TREE-CODE-SYMBOLS */;
     {
      cl_fixnum v9code;
      v9code = 0;
      {
       cl_fixnum v10index;
       v10index = 0;
       {
        cl_fixnum v11first;
        v11first = 0;
        {
         cl_fixnum v12;
         cl_fixnum v13length;
         v12 = (v7length_count)->vector.fillp;
         v13length = 1;
         {
          cl_object v14count;
          v14count = ECL_NIL;
          {
          cl_object v15;
          v15 = ECL_NIL;
L23:;
          T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          if (ecl_number_compare(T0,ecl_make_fixnum(1))<0) { goto L25; }
          goto L24;
L25:;
          {
          cl_object v16;
          T0 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          {
          uint8_t v17;
          T1 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v1bit_stream) /*  BIT-STREAM-STREAM */;
          v17 = ecl_fixnum(cl_read_byte(1, T1));
          T1 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          T2 = cl_ash(ecl_make_uint8_t(v17), T1);
          v16 = ecl_boole(ECL_BOOLIOR,(T0),(T2));
          }
          (v1bit_stream)->instance.slots[2]=v16;
          }
          {
          cl_object v16;
          T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          v16 = ecl_plus(T0,ecl_make_fixnum(8));
          (v1bit_stream)->instance.slots[3]=v16;
          }
          goto L23;
L24:;
          T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          if (!(ecl_number_equalp(T0,ecl_make_fixnum(1)))) { goto L33; }
          {
          cl_object v16;
          v16 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          (v1bit_stream)->instance.slots[2]=ecl_make_fixnum(0);
          (v1bit_stream)->instance.slots[3]=ecl_make_fixnum(0);
          v9code = ecl_fixnum(v16);
          goto L21;
          }
L33:;
          {
          cl_object v17;
          T0 = cl_byte(ecl_make_fixnum(1), ecl_make_fixnum(0));
          T1 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          v17 = cl_ldb(T0, T1);
          {
          cl_object v18;
          T0 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          {
          cl_fixnum v19;
          v19 = -(1);
          v18 = cl_ash(T0, ecl_make_fixnum(v19));
          }
          (v1bit_stream)->instance.slots[2]=v18;
          }
          {
          cl_object v18;
          T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          v18 = ecl_minus(T0,ecl_make_fixnum(1));
          (v1bit_stream)->instance.slots[3]=v18;
          }
          v9code = ecl_fixnum(v17);
          }
L21:;
          v10index = 0;
          v11first = 0;
L18:;
          if (!((v13length)>=(v12))) { goto L47; }
          goto L19;
L47:;
          v14count = ecl_make_int64_t((v7length_count)->vector.self.i64[v13length]);
          T0 = ecl_plus(ecl_make_fixnum(v11first),v14count);
          if (!((v9code)<(ecl_fixnum(T0)))) { goto L54; }
          T0 = ecl_minus(ecl_make_fixnum(v9code),ecl_make_fixnum(v11first));
          T1 = ecl_plus(ecl_make_fixnum(v10index),T0);
          v15 = ecl_make_int64_t((v8code_symbols)->vector.self.i64[ecl_fixnum(T1)]);
          goto L53;
L54:;
          v15 = ECL_NIL;
L53:;
          if (Null(v15)) { goto L51; }
          v6code = v15;
          goto L8;
L51:;
          T0 = ecl_times(ecl_make_fixnum(v9code),ecl_make_fixnum(2));
L60:;
          T2 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          if (ecl_number_compare(T2,ecl_make_fixnum(1))<0) { goto L62; }
          goto L61;
L62:;
          {
          cl_object v16;
          T2 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          {
          uint8_t v17;
          T3 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v1bit_stream) /*  BIT-STREAM-STREAM */;
          v17 = ecl_fixnum(cl_read_byte(1, T3));
          T3 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          T4 = cl_ash(ecl_make_uint8_t(v17), T3);
          v16 = ecl_boole(ECL_BOOLIOR,(T2),(T4));
          }
          (v1bit_stream)->instance.slots[2]=v16;
          }
          {
          cl_object v16;
          T2 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          v16 = ecl_plus(T2,ecl_make_fixnum(8));
          (v1bit_stream)->instance.slots[3]=v16;
          }
          goto L60;
L61:;
          T2 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          if (!(ecl_number_equalp(T2,ecl_make_fixnum(1)))) { goto L70; }
          {
          cl_object v16;
          v16 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          (v1bit_stream)->instance.slots[2]=ecl_make_fixnum(0);
          (v1bit_stream)->instance.slots[3]=ecl_make_fixnum(0);
          T1 = v16;
          goto L58;
          }
L70:;
          {
          cl_object v17;
          T2 = cl_byte(ecl_make_fixnum(1), ecl_make_fixnum(0));
          T3 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          v17 = cl_ldb(T2, T3);
          {
          cl_object v18;
          T2 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          {
          cl_fixnum v19;
          v19 = -(1);
          v18 = cl_ash(T2, ecl_make_fixnum(v19));
          }
          (v1bit_stream)->instance.slots[2]=v18;
          }
          {
          cl_object v18;
          T2 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          v18 = ecl_minus(T2,ecl_make_fixnum(1));
          (v1bit_stream)->instance.slots[3]=v18;
          }
          T1 = v17;
          }
L58:;
          v9code = ecl_fixnum(ecl_plus(T0,T1));
          v10index = ecl_fixnum(ecl_plus(ecl_make_fixnum(v10index),v14count));
          T0 = ecl_plus(ecl_make_fixnum(v11first),v14count);
          v11first = ecl_fixnum(ecl_times(T0,ecl_make_fixnum(2)));
          v13length = (v13length)+1;
          goto L18;
L19:;
          T0 = ecl_list1(ecl_make_fixnum(v9code));
          cl_error(5, VV[1], ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_7, ECL_SYM("FORMAT-ARGUMENTS",1239), T0);
          v6code = ECL_NIL;
          }
         }
        }
       }
      }
     }
    }
   }
L8:;
   if (Null(ecl_memql(v6code,VV[58]))) { goto L88; }
   (v4)->vector.self.i64[ecl_fixnum(v5index)]= ecl_to_long(v6code);
   v5index = ecl_plus(v5index,ecl_make_fixnum(1));
   goto L7;
L88:;
   if (!((v6code)==(ecl_make_fixnum(16)))) { goto L92; }
   {
    cl_object v7length;
L97:;
    T1 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
    if (ecl_number_compare(T1,ecl_make_fixnum(2))<0) { goto L99; }
    goto L98;
L99:;
    {
     cl_object v8;
     T1 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
     {
      uint8_t v9;
      T2 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v1bit_stream) /*  BIT-STREAM-STREAM */;
      v9 = ecl_fixnum(cl_read_byte(1, T2));
      T2 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
      T3 = cl_ash(ecl_make_uint8_t(v9), T2);
      v8 = ecl_boole(ECL_BOOLIOR,(T1),(T3));
     }
     (v1bit_stream)->instance.slots[2]=v8;
    }
    {
     cl_object v8;
     T1 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
     v8 = ecl_plus(T1,ecl_make_fixnum(8));
     (v1bit_stream)->instance.slots[3]=v8;
    }
    goto L97;
L98:;
    T1 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
    if (!(ecl_number_equalp(T1,ecl_make_fixnum(2)))) { goto L107; }
    {
     cl_object v8;
     v8 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
     (v1bit_stream)->instance.slots[2]=ecl_make_fixnum(0);
     (v1bit_stream)->instance.slots[3]=ecl_make_fixnum(0);
     T0 = v8;
     goto L95;
    }
L107:;
    {
     cl_object v9;
     T1 = cl_byte(ecl_make_fixnum(2), ecl_make_fixnum(0));
     T2 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
     v9 = cl_ldb(T1, T2);
     {
      cl_object v10;
      T1 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
      {
       cl_fixnum v11;
       v11 = -(2);
       v10 = cl_ash(T1, ecl_make_fixnum(v11));
      }
      (v1bit_stream)->instance.slots[2]=v10;
     }
     {
      cl_object v10;
      T1 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
      v10 = ecl_minus(T1,ecl_make_fixnum(2));
      (v1bit_stream)->instance.slots[3]=v10;
     }
     T0 = v9;
    }
L95:;
    v7length = ecl_plus(ecl_make_fixnum(3),T0);
    {
     cl_object v8i;
     v8i = ecl_make_fixnum(0);
     goto L120;
L119:;
     T0 = ecl_plus(v5index,v8i);
     {
      long v9;
      T1 = ecl_one_minus(v5index);
      v9 = (long)((v4)->vector.self.i64[ecl_fixnum(T1)]);
      (v4)->vector.self.i64[ecl_fixnum(T0)]= v9;
     }
     v8i = ecl_one_plus(v8i);
L120:;
     if (!(ecl_number_compare(v8i,v7length)<0)) { goto L126; }
     goto L119;
L126:;
    }
    v5index = ecl_plus(v5index,v7length);
    goto L7;
   }
L92:;
   if (!((v6code)==(ecl_make_fixnum(17)))) { goto L129; }
   {
    cl_object v8length;
L134:;
    T1 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
    if (ecl_number_compare(T1,ecl_make_fixnum(3))<0) { goto L136; }
    goto L135;
L136:;
    {
     cl_object v9;
     T1 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
     {
      uint8_t v10;
      T2 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v1bit_stream) /*  BIT-STREAM-STREAM */;
      v10 = ecl_fixnum(cl_read_byte(1, T2));
      T2 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
      T3 = cl_ash(ecl_make_uint8_t(v10), T2);
      v9 = ecl_boole(ECL_BOOLIOR,(T1),(T3));
     }
     (v1bit_stream)->instance.slots[2]=v9;
    }
    {
     cl_object v9;
     T1 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
     v9 = ecl_plus(T1,ecl_make_fixnum(8));
     (v1bit_stream)->instance.slots[3]=v9;
    }
    goto L134;
L135:;
    T1 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
    if (!(ecl_number_equalp(T1,ecl_make_fixnum(3)))) { goto L144; }
    {
     cl_object v9;
     v9 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
     (v1bit_stream)->instance.slots[2]=ecl_make_fixnum(0);
     (v1bit_stream)->instance.slots[3]=ecl_make_fixnum(0);
     T0 = v9;
     goto L132;
    }
L144:;
    {
     cl_object v10;
     T1 = cl_byte(ecl_make_fixnum(3), ecl_make_fixnum(0));
     T2 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
     v10 = cl_ldb(T1, T2);
     {
      cl_object v11;
      T1 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
      {
       cl_fixnum v12;
       v12 = -(3);
       v11 = cl_ash(T1, ecl_make_fixnum(v12));
      }
      (v1bit_stream)->instance.slots[2]=v11;
     }
     {
      cl_object v11;
      T1 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
      v11 = ecl_minus(T1,ecl_make_fixnum(3));
      (v1bit_stream)->instance.slots[3]=v11;
     }
     T0 = v10;
    }
L132:;
    v8length = ecl_plus(ecl_make_fixnum(3),T0);
    {
     cl_object v9i;
     v9i = ecl_make_fixnum(0);
     goto L157;
L156:;
     T0 = ecl_plus(v5index,v9i);
     (v4)->array.self.fix[ecl_fixnum(T0)]= 0;
     v9i = ecl_one_plus(v9i);
L157:;
     if (!(ecl_number_compare(v9i,v8length)<0)) { goto L162; }
     goto L156;
L162:;
    }
    v5index = ecl_plus(v5index,v8length);
    goto L7;
   }
L129:;
   if (!((v6code)==(ecl_make_fixnum(18)))) { goto L165; }
   {
    cl_object v9length;
L170:;
    T1 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
    if (ecl_number_compare(T1,ecl_make_fixnum(7))<0) { goto L172; }
    goto L171;
L172:;
    {
     cl_object v10;
     T1 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
     {
      uint8_t v11;
      T2 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v1bit_stream) /*  BIT-STREAM-STREAM */;
      v11 = ecl_fixnum(cl_read_byte(1, T2));
      T2 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
      T3 = cl_ash(ecl_make_uint8_t(v11), T2);
      v10 = ecl_boole(ECL_BOOLIOR,(T1),(T3));
     }
     (v1bit_stream)->instance.slots[2]=v10;
    }
    {
     cl_object v10;
     T1 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
     v10 = ecl_plus(T1,ecl_make_fixnum(8));
     (v1bit_stream)->instance.slots[3]=v10;
    }
    goto L170;
L171:;
    T1 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
    if (!(ecl_number_equalp(T1,ecl_make_fixnum(7)))) { goto L180; }
    {
     cl_object v10;
     v10 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
     (v1bit_stream)->instance.slots[2]=ecl_make_fixnum(0);
     (v1bit_stream)->instance.slots[3]=ecl_make_fixnum(0);
     T0 = v10;
     goto L168;
    }
L180:;
    {
     cl_object v11;
     T1 = cl_byte(ecl_make_fixnum(7), ecl_make_fixnum(0));
     T2 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
     v11 = cl_ldb(T1, T2);
     {
      cl_object v12;
      T1 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
      {
       cl_fixnum v13;
       v13 = -(7);
       v12 = cl_ash(T1, ecl_make_fixnum(v13));
      }
      (v1bit_stream)->instance.slots[2]=v12;
     }
     {
      cl_object v12;
      T1 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
      v12 = ecl_minus(T1,ecl_make_fixnum(7));
      (v1bit_stream)->instance.slots[3]=v12;
     }
     T0 = v11;
    }
L168:;
    v9length = ecl_plus(ecl_make_fixnum(11),T0);
    {
     cl_object v10i;
     v10i = ecl_make_fixnum(0);
     goto L193;
L192:;
     T0 = ecl_plus(v5index,v10i);
     (v4)->array.self.fix[ecl_fixnum(T0)]= 0;
     v10i = ecl_one_plus(v10i);
L193:;
     if (!(ecl_number_compare(v10i,v9length)<0)) { goto L198; }
     goto L192;
L198:;
    }
    v5index = ecl_plus(v5index,v9length);
    goto L7;
   }
L165:;
   si_ecase_error(v6code, VV[59]);
  }
L7:;
L5:;
  if (ecl_number_compare(v5index,v2count)>=0) { goto L201; }
  goto L4;
L201:;
  value0 = v4;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for DECODE-HUFFMAN-TABLES                 */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object L22decode_huffman_tables(cl_object v1bit_stream)
{
 cl_object T0, T1, T2, T3, T4, T5;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v2hlit;
  cl_object v3hdist;
  cl_object v4hclen;
L3:;
  T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
  if (ecl_number_compare(T0,ecl_make_fixnum(5))<0) { goto L5; }
  goto L4;
L5:;
  {
   cl_object v5;
   T0 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
   {
    uint8_t v6;
    T1 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v1bit_stream) /*  BIT-STREAM-STREAM */;
    v6 = ecl_fixnum(cl_read_byte(1, T1));
    T1 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
    T2 = cl_ash(ecl_make_uint8_t(v6), T1);
    v5 = ecl_boole(ECL_BOOLIOR,(T0),(T2));
   }
   (v1bit_stream)->instance.slots[2]=v5;
  }
  {
   cl_object v5;
   T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
   v5 = ecl_plus(T0,ecl_make_fixnum(8));
   (v1bit_stream)->instance.slots[3]=v5;
  }
  goto L3;
L4:;
  T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
  if (!(ecl_number_equalp(T0,ecl_make_fixnum(5)))) { goto L13; }
  {
   cl_object v5;
   v5 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
   (v1bit_stream)->instance.slots[2]=ecl_make_fixnum(0);
   (v1bit_stream)->instance.slots[3]=ecl_make_fixnum(0);
   v2hlit = v5;
   goto L1;
  }
L13:;
  {
   cl_object v6;
   T0 = cl_byte(ecl_make_fixnum(5), ecl_make_fixnum(0));
   T1 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
   v6 = cl_ldb(T0, T1);
   {
    cl_object v7;
    T0 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
    {
     cl_fixnum v8;
     v8 = -(5);
     v7 = cl_ash(T0, ecl_make_fixnum(v8));
    }
    (v1bit_stream)->instance.slots[2]=v7;
   }
   {
    cl_object v7;
    T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
    v7 = ecl_minus(T0,ecl_make_fixnum(5));
    (v1bit_stream)->instance.slots[3]=v7;
   }
   v2hlit = v6;
  }
L1:;
L25:;
  T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
  if (ecl_number_compare(T0,ecl_make_fixnum(5))<0) { goto L27; }
  goto L26;
L27:;
  {
   cl_object v5;
   T0 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
   {
    uint8_t v6;
    T1 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v1bit_stream) /*  BIT-STREAM-STREAM */;
    v6 = ecl_fixnum(cl_read_byte(1, T1));
    T1 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
    T2 = cl_ash(ecl_make_uint8_t(v6), T1);
    v5 = ecl_boole(ECL_BOOLIOR,(T0),(T2));
   }
   (v1bit_stream)->instance.slots[2]=v5;
  }
  {
   cl_object v5;
   T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
   v5 = ecl_plus(T0,ecl_make_fixnum(8));
   (v1bit_stream)->instance.slots[3]=v5;
  }
  goto L25;
L26:;
  T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
  if (!(ecl_number_equalp(T0,ecl_make_fixnum(5)))) { goto L35; }
  {
   cl_object v5;
   v5 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
   (v1bit_stream)->instance.slots[2]=ecl_make_fixnum(0);
   (v1bit_stream)->instance.slots[3]=ecl_make_fixnum(0);
   v3hdist = v5;
   goto L23;
  }
L35:;
  {
   cl_object v6;
   T0 = cl_byte(ecl_make_fixnum(5), ecl_make_fixnum(0));
   T1 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
   v6 = cl_ldb(T0, T1);
   {
    cl_object v7;
    T0 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
    {
     cl_fixnum v8;
     v8 = -(5);
     v7 = cl_ash(T0, ecl_make_fixnum(v8));
    }
    (v1bit_stream)->instance.slots[2]=v7;
   }
   {
    cl_object v7;
    T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
    v7 = ecl_minus(T0,ecl_make_fixnum(5));
    (v1bit_stream)->instance.slots[3]=v7;
   }
   v3hdist = v6;
  }
L23:;
L47:;
  T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
  if (ecl_number_compare(T0,ecl_make_fixnum(4))<0) { goto L49; }
  goto L48;
L49:;
  {
   cl_object v5;
   T0 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
   {
    uint8_t v6;
    T1 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v1bit_stream) /*  BIT-STREAM-STREAM */;
    v6 = ecl_fixnum(cl_read_byte(1, T1));
    T1 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
    T2 = cl_ash(ecl_make_uint8_t(v6), T1);
    v5 = ecl_boole(ECL_BOOLIOR,(T0),(T2));
   }
   (v1bit_stream)->instance.slots[2]=v5;
  }
  {
   cl_object v5;
   T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
   v5 = ecl_plus(T0,ecl_make_fixnum(8));
   (v1bit_stream)->instance.slots[3]=v5;
  }
  goto L47;
L48:;
  T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
  if (!(ecl_number_equalp(T0,ecl_make_fixnum(4)))) { goto L57; }
  {
   cl_object v5;
   v5 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
   (v1bit_stream)->instance.slots[2]=ecl_make_fixnum(0);
   (v1bit_stream)->instance.slots[3]=ecl_make_fixnum(0);
   v4hclen = v5;
   goto L45;
  }
L57:;
  {
   cl_object v6;
   T0 = cl_byte(ecl_make_fixnum(4), ecl_make_fixnum(0));
   T1 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
   v6 = cl_ldb(T0, T1);
   {
    cl_object v7;
    T0 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
    {
     cl_fixnum v8;
     v8 = -(4);
     v7 = cl_ash(T0, ecl_make_fixnum(v8));
    }
    (v1bit_stream)->instance.slots[2]=v7;
   }
   {
    cl_object v7;
    T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
    v7 = ecl_minus(T0,ecl_make_fixnum(4));
    (v1bit_stream)->instance.slots[3]=v7;
   }
   v4hclen = v6;
  }
L45:;
  {
   cl_object v5cl_decode_tree;
   {
    cl_object v6code_lengths;
    T0 = si_make_vector(ECL_SYM("BYTE8",1330), ecl_make_fixnum(19), ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
    v6code_lengths = si_fill_array_with_elt(T0, ecl_make_fixnum(0), ecl_make_fixnum(0), ECL_NIL);
    {
     cl_object v7;
     cl_object v8index;
     v7 = ecl_plus(v4hclen,ecl_make_fixnum(4));
     v8index = ecl_make_fixnum(0);
     {
      cl_object v9code_length;
      v9code_length = ECL_NIL;
      {
       cl_object v10code_index;
       v10code_index = ECL_NIL;
L73:;
       if (!(ecl_number_compare(v8index,v7)>=0)) { goto L75; }
       goto L74;
L75:;
L80:;
       T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
       if (ecl_number_compare(T0,ecl_make_fixnum(3))<0) { goto L82; }
       goto L81;
L82:;
       {
        cl_object v11;
        T0 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
        {
         uint8_t v12;
         T1 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v1bit_stream) /*  BIT-STREAM-STREAM */;
         v12 = ecl_fixnum(cl_read_byte(1, T1));
         T1 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
         T2 = cl_ash(ecl_make_uint8_t(v12), T1);
         v11 = ecl_boole(ECL_BOOLIOR,(T0),(T2));
        }
        (v1bit_stream)->instance.slots[2]=v11;
       }
       {
        cl_object v11;
        T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
        v11 = ecl_plus(T0,ecl_make_fixnum(8));
        (v1bit_stream)->instance.slots[3]=v11;
       }
       goto L80;
L81:;
       T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
       if (!(ecl_number_equalp(T0,ecl_make_fixnum(3)))) { goto L90; }
       {
        cl_object v11;
        v11 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
        (v1bit_stream)->instance.slots[2]=ecl_make_fixnum(0);
        (v1bit_stream)->instance.slots[3]=ecl_make_fixnum(0);
        v9code_length = v11;
        goto L78;
       }
L90:;
       {
        cl_object v12;
        T0 = cl_byte(ecl_make_fixnum(3), ecl_make_fixnum(0));
        T1 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
        v12 = cl_ldb(T0, T1);
        {
         cl_object v13;
         T0 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
         {
          cl_fixnum v14;
          v14 = -(3);
          v13 = cl_ash(T0, ecl_make_fixnum(v14));
         }
         (v1bit_stream)->instance.slots[2]=v13;
        }
        {
         cl_object v13;
         T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
         v13 = ecl_minus(T0,ecl_make_fixnum(3));
         (v1bit_stream)->instance.slots[3]=v13;
        }
        v9code_length = v12;
       }
L78:;
       {
        cl_object v11;
        v11 = ECL_SYM_VAL(cl_env_copy,VV[57]);
        v10code_index = ecl_aref_unsafe(v11,ecl_fixnum(v8index));
       }
       (v6code_lengths)->vector.self.b8[ecl_fixnum(v10code_index)]= ecl_fixnum(v9code_length);
       v8index = ecl_one_plus(v8index);
       goto L73;
L74:;
       v5cl_decode_tree = L19make_huffman_decode_tree(v6code_lengths);
       goto L67;
      }
     }
    }
   }
L67:;
   {
    cl_object v6entries;
    T0 = ecl_plus(v2hlit,ecl_make_fixnum(257));
    T1 = ecl_plus(T0,v3hdist);
    T2 = ecl_plus(T1,ecl_make_fixnum(1));
    v6entries = L21decode_code_length_entries(v1bit_stream, T2, v5cl_decode_tree);
    T0 = ecl_plus(v2hlit,ecl_make_fixnum(257));
    T1 = cl_subseq(3, v6entries, ecl_make_fixnum(0), T0);
    T2 = L19make_huffman_decode_tree(T1);
    T3 = ecl_plus(v2hlit,ecl_make_fixnum(257));
    T4 = cl_subseq(2, v6entries, T3);
    T5 = L19make_huffman_decode_tree(T4);
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = T5;
    cl_env_copy->values[0] = T2;
    return cl_env_copy->values[0];
   }
  }
 }
}
/*	function definition for DECODE-LENGTH-ENTRY                   */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object L23decode_length_entry(cl_object v1symbol, cl_object v2bit_stream)
{
 cl_object T0, T1, T2, T3, T4, T5, T6;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 if (!(ecl_number_compare(v1symbol,ecl_make_fixnum(264))<=0)) { goto L1; }
 value0 = ecl_minus(v1symbol,ecl_make_fixnum(254));
 cl_env_copy->nvalues = 1;
 return value0;
L1:;
 if (!(ecl_number_compare(v1symbol,ecl_make_fixnum(268))<=0)) { goto L3; }
 T0 = ecl_minus(v1symbol,ecl_make_fixnum(265));
 T1 = ecl_times(T0,ecl_make_fixnum(2));
 T2 = ecl_plus(ecl_make_fixnum(11),T1);
L7:;
 T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v2bit_stream) /*  BIT-STREAM-BIT-COUNT */;
 if (ecl_number_compare(T4,ecl_make_fixnum(1))<0) { goto L9; }
 goto L8;
L9:;
 {
  cl_object v3;
  T4 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v2bit_stream) /*  BIT-STREAM-BITS */;
  {
   uint8_t v4;
   T5 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v2bit_stream) /*  BIT-STREAM-STREAM */;
   v4 = ecl_fixnum(cl_read_byte(1, T5));
   T5 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v2bit_stream) /*  BIT-STREAM-BIT-COUNT */;
   T6 = cl_ash(ecl_make_uint8_t(v4), T5);
   v3 = ecl_boole(ECL_BOOLIOR,(T4),(T6));
  }
  (v2bit_stream)->instance.slots[2]=v3;
 }
 {
  cl_object v3;
  T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v2bit_stream) /*  BIT-STREAM-BIT-COUNT */;
  v3 = ecl_plus(T4,ecl_make_fixnum(8));
  (v2bit_stream)->instance.slots[3]=v3;
 }
 goto L7;
L8:;
 T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v2bit_stream) /*  BIT-STREAM-BIT-COUNT */;
 if (!(ecl_number_equalp(T4,ecl_make_fixnum(1)))) { goto L17; }
 {
  cl_object v3;
  v3 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v2bit_stream) /*  BIT-STREAM-BITS */;
  (v2bit_stream)->instance.slots[2]=ecl_make_fixnum(0);
  (v2bit_stream)->instance.slots[3]=ecl_make_fixnum(0);
  T3 = v3;
  goto L5;
 }
L17:;
 {
  cl_object v4;
  T4 = cl_byte(ecl_make_fixnum(1), ecl_make_fixnum(0));
  T5 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v2bit_stream) /*  BIT-STREAM-BITS */;
  v4 = cl_ldb(T4, T5);
  {
   cl_object v5;
   T4 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v2bit_stream) /*  BIT-STREAM-BITS */;
   {
    cl_fixnum v6;
    v6 = -(1);
    v5 = cl_ash(T4, ecl_make_fixnum(v6));
   }
   (v2bit_stream)->instance.slots[2]=v5;
  }
  {
   cl_object v5;
   T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v2bit_stream) /*  BIT-STREAM-BIT-COUNT */;
   v5 = ecl_minus(T4,ecl_make_fixnum(1));
   (v2bit_stream)->instance.slots[3]=v5;
  }
  T3 = v4;
 }
L5:;
 value0 = ecl_plus(T2,T3);
 cl_env_copy->nvalues = 1;
 return value0;
L3:;
 if (!(ecl_number_compare(v1symbol,ecl_make_fixnum(272))<=0)) { goto L27; }
 T0 = ecl_minus(v1symbol,ecl_make_fixnum(269));
 T1 = ecl_times(T0,ecl_make_fixnum(4));
 T2 = ecl_plus(ecl_make_fixnum(19),T1);
L31:;
 T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v2bit_stream) /*  BIT-STREAM-BIT-COUNT */;
 if (ecl_number_compare(T4,ecl_make_fixnum(2))<0) { goto L33; }
 goto L32;
L33:;
 {
  cl_object v3;
  T4 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v2bit_stream) /*  BIT-STREAM-BITS */;
  {
   uint8_t v4;
   T5 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v2bit_stream) /*  BIT-STREAM-STREAM */;
   v4 = ecl_fixnum(cl_read_byte(1, T5));
   T5 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v2bit_stream) /*  BIT-STREAM-BIT-COUNT */;
   T6 = cl_ash(ecl_make_uint8_t(v4), T5);
   v3 = ecl_boole(ECL_BOOLIOR,(T4),(T6));
  }
  (v2bit_stream)->instance.slots[2]=v3;
 }
 {
  cl_object v3;
  T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v2bit_stream) /*  BIT-STREAM-BIT-COUNT */;
  v3 = ecl_plus(T4,ecl_make_fixnum(8));
  (v2bit_stream)->instance.slots[3]=v3;
 }
 goto L31;
L32:;
 T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v2bit_stream) /*  BIT-STREAM-BIT-COUNT */;
 if (!(ecl_number_equalp(T4,ecl_make_fixnum(2)))) { goto L41; }
 {
  cl_object v3;
  v3 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v2bit_stream) /*  BIT-STREAM-BITS */;
  (v2bit_stream)->instance.slots[2]=ecl_make_fixnum(0);
  (v2bit_stream)->instance.slots[3]=ecl_make_fixnum(0);
  T3 = v3;
  goto L29;
 }
L41:;
 {
  cl_object v4;
  T4 = cl_byte(ecl_make_fixnum(2), ecl_make_fixnum(0));
  T5 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v2bit_stream) /*  BIT-STREAM-BITS */;
  v4 = cl_ldb(T4, T5);
  {
   cl_object v5;
   T4 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v2bit_stream) /*  BIT-STREAM-BITS */;
   {
    cl_fixnum v6;
    v6 = -(2);
    v5 = cl_ash(T4, ecl_make_fixnum(v6));
   }
   (v2bit_stream)->instance.slots[2]=v5;
  }
  {
   cl_object v5;
   T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v2bit_stream) /*  BIT-STREAM-BIT-COUNT */;
   v5 = ecl_minus(T4,ecl_make_fixnum(2));
   (v2bit_stream)->instance.slots[3]=v5;
  }
  T3 = v4;
 }
L29:;
 value0 = ecl_plus(T2,T3);
 cl_env_copy->nvalues = 1;
 return value0;
L27:;
 if (!(ecl_number_compare(v1symbol,ecl_make_fixnum(276))<=0)) { goto L51; }
 T0 = ecl_minus(v1symbol,ecl_make_fixnum(273));
 T1 = ecl_times(T0,ecl_make_fixnum(8));
 T2 = ecl_plus(ecl_make_fixnum(35),T1);
L55:;
 T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v2bit_stream) /*  BIT-STREAM-BIT-COUNT */;
 if (ecl_number_compare(T4,ecl_make_fixnum(3))<0) { goto L57; }
 goto L56;
L57:;
 {
  cl_object v3;
  T4 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v2bit_stream) /*  BIT-STREAM-BITS */;
  {
   uint8_t v4;
   T5 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v2bit_stream) /*  BIT-STREAM-STREAM */;
   v4 = ecl_fixnum(cl_read_byte(1, T5));
   T5 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v2bit_stream) /*  BIT-STREAM-BIT-COUNT */;
   T6 = cl_ash(ecl_make_uint8_t(v4), T5);
   v3 = ecl_boole(ECL_BOOLIOR,(T4),(T6));
  }
  (v2bit_stream)->instance.slots[2]=v3;
 }
 {
  cl_object v3;
  T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v2bit_stream) /*  BIT-STREAM-BIT-COUNT */;
  v3 = ecl_plus(T4,ecl_make_fixnum(8));
  (v2bit_stream)->instance.slots[3]=v3;
 }
 goto L55;
L56:;
 T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v2bit_stream) /*  BIT-STREAM-BIT-COUNT */;
 if (!(ecl_number_equalp(T4,ecl_make_fixnum(3)))) { goto L65; }
 {
  cl_object v3;
  v3 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v2bit_stream) /*  BIT-STREAM-BITS */;
  (v2bit_stream)->instance.slots[2]=ecl_make_fixnum(0);
  (v2bit_stream)->instance.slots[3]=ecl_make_fixnum(0);
  T3 = v3;
  goto L53;
 }
L65:;
 {
  cl_object v4;
  T4 = cl_byte(ecl_make_fixnum(3), ecl_make_fixnum(0));
  T5 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v2bit_stream) /*  BIT-STREAM-BITS */;
  v4 = cl_ldb(T4, T5);
  {
   cl_object v5;
   T4 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v2bit_stream) /*  BIT-STREAM-BITS */;
   {
    cl_fixnum v6;
    v6 = -(3);
    v5 = cl_ash(T4, ecl_make_fixnum(v6));
   }
   (v2bit_stream)->instance.slots[2]=v5;
  }
  {
   cl_object v5;
   T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v2bit_stream) /*  BIT-STREAM-BIT-COUNT */;
   v5 = ecl_minus(T4,ecl_make_fixnum(3));
   (v2bit_stream)->instance.slots[3]=v5;
  }
  T3 = v4;
 }
L53:;
 value0 = ecl_plus(T2,T3);
 cl_env_copy->nvalues = 1;
 return value0;
L51:;
 if (!(ecl_number_compare(v1symbol,ecl_make_fixnum(280))<=0)) { goto L75; }
 T0 = ecl_minus(v1symbol,ecl_make_fixnum(277));
 T1 = ecl_times(T0,ecl_make_fixnum(16));
 T2 = ecl_plus(ecl_make_fixnum(67),T1);
L79:;
 T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v2bit_stream) /*  BIT-STREAM-BIT-COUNT */;
 if (ecl_number_compare(T4,ecl_make_fixnum(4))<0) { goto L81; }
 goto L80;
L81:;
 {
  cl_object v3;
  T4 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v2bit_stream) /*  BIT-STREAM-BITS */;
  {
   uint8_t v4;
   T5 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v2bit_stream) /*  BIT-STREAM-STREAM */;
   v4 = ecl_fixnum(cl_read_byte(1, T5));
   T5 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v2bit_stream) /*  BIT-STREAM-BIT-COUNT */;
   T6 = cl_ash(ecl_make_uint8_t(v4), T5);
   v3 = ecl_boole(ECL_BOOLIOR,(T4),(T6));
  }
  (v2bit_stream)->instance.slots[2]=v3;
 }
 {
  cl_object v3;
  T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v2bit_stream) /*  BIT-STREAM-BIT-COUNT */;
  v3 = ecl_plus(T4,ecl_make_fixnum(8));
  (v2bit_stream)->instance.slots[3]=v3;
 }
 goto L79;
L80:;
 T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v2bit_stream) /*  BIT-STREAM-BIT-COUNT */;
 if (!(ecl_number_equalp(T4,ecl_make_fixnum(4)))) { goto L89; }
 {
  cl_object v3;
  v3 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v2bit_stream) /*  BIT-STREAM-BITS */;
  (v2bit_stream)->instance.slots[2]=ecl_make_fixnum(0);
  (v2bit_stream)->instance.slots[3]=ecl_make_fixnum(0);
  T3 = v3;
  goto L77;
 }
L89:;
 {
  cl_object v4;
  T4 = cl_byte(ecl_make_fixnum(4), ecl_make_fixnum(0));
  T5 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v2bit_stream) /*  BIT-STREAM-BITS */;
  v4 = cl_ldb(T4, T5);
  {
   cl_object v5;
   T4 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v2bit_stream) /*  BIT-STREAM-BITS */;
   {
    cl_fixnum v6;
    v6 = -(4);
    v5 = cl_ash(T4, ecl_make_fixnum(v6));
   }
   (v2bit_stream)->instance.slots[2]=v5;
  }
  {
   cl_object v5;
   T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v2bit_stream) /*  BIT-STREAM-BIT-COUNT */;
   v5 = ecl_minus(T4,ecl_make_fixnum(4));
   (v2bit_stream)->instance.slots[3]=v5;
  }
  T3 = v4;
 }
L77:;
 value0 = ecl_plus(T2,T3);
 cl_env_copy->nvalues = 1;
 return value0;
L75:;
 if (!(ecl_number_compare(v1symbol,ecl_make_fixnum(284))<=0)) { goto L99; }
 T0 = ecl_minus(v1symbol,ecl_make_fixnum(281));
 T1 = ecl_times(T0,ecl_make_fixnum(32));
 T2 = ecl_plus(ecl_make_fixnum(131),T1);
L103:;
 T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v2bit_stream) /*  BIT-STREAM-BIT-COUNT */;
 if (ecl_number_compare(T4,ecl_make_fixnum(5))<0) { goto L105; }
 goto L104;
L105:;
 {
  cl_object v3;
  T4 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v2bit_stream) /*  BIT-STREAM-BITS */;
  {
   uint8_t v4;
   T5 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v2bit_stream) /*  BIT-STREAM-STREAM */;
   v4 = ecl_fixnum(cl_read_byte(1, T5));
   T5 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v2bit_stream) /*  BIT-STREAM-BIT-COUNT */;
   T6 = cl_ash(ecl_make_uint8_t(v4), T5);
   v3 = ecl_boole(ECL_BOOLIOR,(T4),(T6));
  }
  (v2bit_stream)->instance.slots[2]=v3;
 }
 {
  cl_object v3;
  T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v2bit_stream) /*  BIT-STREAM-BIT-COUNT */;
  v3 = ecl_plus(T4,ecl_make_fixnum(8));
  (v2bit_stream)->instance.slots[3]=v3;
 }
 goto L103;
L104:;
 T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v2bit_stream) /*  BIT-STREAM-BIT-COUNT */;
 if (!(ecl_number_equalp(T4,ecl_make_fixnum(5)))) { goto L113; }
 {
  cl_object v3;
  v3 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v2bit_stream) /*  BIT-STREAM-BITS */;
  (v2bit_stream)->instance.slots[2]=ecl_make_fixnum(0);
  (v2bit_stream)->instance.slots[3]=ecl_make_fixnum(0);
  T3 = v3;
  goto L101;
 }
L113:;
 {
  cl_object v4;
  T4 = cl_byte(ecl_make_fixnum(5), ecl_make_fixnum(0));
  T5 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v2bit_stream) /*  BIT-STREAM-BITS */;
  v4 = cl_ldb(T4, T5);
  {
   cl_object v5;
   T4 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v2bit_stream) /*  BIT-STREAM-BITS */;
   {
    cl_fixnum v6;
    v6 = -(5);
    v5 = cl_ash(T4, ecl_make_fixnum(v6));
   }
   (v2bit_stream)->instance.slots[2]=v5;
  }
  {
   cl_object v5;
   T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v2bit_stream) /*  BIT-STREAM-BIT-COUNT */;
   v5 = ecl_minus(T4,ecl_make_fixnum(5));
   (v2bit_stream)->instance.slots[3]=v5;
  }
  T3 = v4;
 }
L101:;
 value0 = ecl_plus(T2,T3);
 cl_env_copy->nvalues = 1;
 return value0;
L99:;
 if (!(ecl_number_equalp(v1symbol,ecl_make_fixnum(285)))) { goto L123; }
 value0 = ecl_make_fixnum(258);
 cl_env_copy->nvalues = 1;
 return value0;
L123:;
 T0 = ecl_list1(v1symbol);
 value0 = cl_error(5, VV[1], ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_8, ECL_SYM("FORMAT-ARGUMENTS",1239), T0);
 return value0;
}
/*	function definition for DECODE-DISTANCE-ENTRY                 */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object L24decode_distance_entry(cl_object v1symbol, cl_object v2bit_stream)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 if (!(ecl_number_compare(v1symbol,ecl_make_fixnum(3))<=0)) { goto L1; }
 value0 = ecl_one_plus(v1symbol);
 cl_env_copy->nvalues = 1;
 return value0;
L1:;
 {
  cl_object v4;                                   /*  ORDER           */
  cl_object v5;                                   /*  OFFSET          */
  value0 = ecl_truncate2(v1symbol,ecl_make_fixnum(2));
  v4 = value0;
  v5 = cl_env_copy->values[1];
  {
   cl_object v6extra_bits;
   cl_object v7factor;
   v6extra_bits = ecl_one_minus(v4);
   v7factor = cl_ash(ecl_make_fixnum(1), v6extra_bits);
   T0 = cl_ash(ecl_make_fixnum(1), v4);
   T1 = ecl_one_plus(T0);
   T2 = ecl_times(v5,v7factor);
   T3 = ecl_plus(T1,T2);
L8:;
   T5 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v2bit_stream) /*  BIT-STREAM-BIT-COUNT */;
   if (ecl_number_compare(T5,v6extra_bits)<0) { goto L10; }
   goto L9;
L10:;
   {
    cl_object v8;
    T5 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v2bit_stream) /*  BIT-STREAM-BITS */;
    {
     uint8_t v9;
     T6 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v2bit_stream) /*  BIT-STREAM-STREAM */;
     v9 = ecl_fixnum(cl_read_byte(1, T6));
     T6 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v2bit_stream) /*  BIT-STREAM-BIT-COUNT */;
     T7 = cl_ash(ecl_make_uint8_t(v9), T6);
     v8 = ecl_boole(ECL_BOOLIOR,(T5),(T7));
    }
    (v2bit_stream)->instance.slots[2]=v8;
   }
   {
    cl_object v8;
    T5 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v2bit_stream) /*  BIT-STREAM-BIT-COUNT */;
    v8 = ecl_plus(T5,ecl_make_fixnum(8));
    (v2bit_stream)->instance.slots[3]=v8;
   }
   goto L8;
L9:;
   T5 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v2bit_stream) /*  BIT-STREAM-BIT-COUNT */;
   if (!(ecl_number_equalp(T5,v6extra_bits))) { goto L18; }
   {
    cl_object v8;
    v8 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v2bit_stream) /*  BIT-STREAM-BITS */;
    (v2bit_stream)->instance.slots[2]=ecl_make_fixnum(0);
    (v2bit_stream)->instance.slots[3]=ecl_make_fixnum(0);
    T4 = v8;
    goto L6;
   }
L18:;
   {
    cl_object v9;
    T5 = cl_byte(v6extra_bits, ecl_make_fixnum(0));
    T6 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v2bit_stream) /*  BIT-STREAM-BITS */;
    v9 = cl_ldb(T5, T6);
    {
     cl_object v10;
     T5 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v2bit_stream) /*  BIT-STREAM-BITS */;
     T6 = ecl_negate(v6extra_bits);
     v10 = cl_ash(T5, T6);
     (v2bit_stream)->instance.slots[2]=v10;
    }
    {
     cl_object v10;
     T5 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v2bit_stream) /*  BIT-STREAM-BIT-COUNT */;
     v10 = ecl_minus(T5,v6extra_bits);
     (v2bit_stream)->instance.slots[3]=v10;
    }
    T4 = v9;
   }
L6:;
   value0 = ecl_plus(T3,T4);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for DECODE-HUFFMAN-BLOCK                  */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object L25decode_huffman_block(cl_object v1bit_stream, cl_object v2window_stream, cl_object v3lit_decode_tree, cl_object v4dist_decode_tree)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v5symbol;
  {
   cl_object v6length_count;
   v6length_count = ecl_function_dispatch(cl_env_copy,VV[118])(1, v3lit_decode_tree) /*  DECODE-TREE-LENGTH-COUNT */;
   {
    cl_object v7code_symbols;
    v7code_symbols = ecl_function_dispatch(cl_env_copy,VV[119])(1, v3lit_decode_tree) /*  DECODE-TREE-CODE-SYMBOLS */;
    {
     cl_fixnum v8code;
     v8code = 0;
     {
      cl_fixnum v9index;
      v9index = 0;
      {
       cl_fixnum v10first;
       v10first = 0;
       {
        cl_fixnum v11;
        cl_fixnum v12length;
        v11 = (v6length_count)->vector.fillp;
        v12length = 1;
        {
         cl_object v13count;
         v13count = ECL_NIL;
         {
          cl_object v14;
          v14 = ECL_NIL;
L16:;
          T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          if (ecl_number_compare(T0,ecl_make_fixnum(1))<0) { goto L18; }
          goto L17;
L18:;
          {
          cl_object v15;
          T0 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          {
          uint8_t v16;
          T1 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v1bit_stream) /*  BIT-STREAM-STREAM */;
          v16 = ecl_fixnum(cl_read_byte(1, T1));
          T1 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          T2 = cl_ash(ecl_make_uint8_t(v16), T1);
          v15 = ecl_boole(ECL_BOOLIOR,(T0),(T2));
          }
          (v1bit_stream)->instance.slots[2]=v15;
          }
          {
          cl_object v15;
          T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          v15 = ecl_plus(T0,ecl_make_fixnum(8));
          (v1bit_stream)->instance.slots[3]=v15;
          }
          goto L16;
L17:;
          T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          if (!(ecl_number_equalp(T0,ecl_make_fixnum(1)))) { goto L26; }
          {
          cl_object v15;
          v15 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          (v1bit_stream)->instance.slots[2]=ecl_make_fixnum(0);
          (v1bit_stream)->instance.slots[3]=ecl_make_fixnum(0);
          v8code = ecl_fixnum(v15);
          goto L14;
          }
L26:;
          {
          cl_object v16;
          T0 = cl_byte(ecl_make_fixnum(1), ecl_make_fixnum(0));
          T1 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          v16 = cl_ldb(T0, T1);
          {
          cl_object v17;
          T0 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          T1 = ecl_negate(ecl_make_fixnum(1));
          v17 = cl_ash(T0, T1);
          (v1bit_stream)->instance.slots[2]=v17;
          }
          {
          cl_object v17;
          T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          v17 = ecl_minus(T0,ecl_make_fixnum(1));
          (v1bit_stream)->instance.slots[3]=v17;
          }
          v8code = ecl_fixnum(v16);
          }
L14:;
          v9index = 0;
          v10first = 0;
L11:;
          if (!((v12length)>=(v11))) { goto L40; }
          goto L12;
L40:;
          v13count = ecl_make_int64_t((v6length_count)->vector.self.i64[v12length]);
          T0 = ecl_plus(ecl_make_fixnum(v10first),v13count);
          if (!((v8code)<(ecl_fixnum(T0)))) { goto L47; }
          T0 = ecl_minus(ecl_make_fixnum(v8code),ecl_make_fixnum(v10first));
          T1 = ecl_plus(ecl_make_fixnum(v9index),T0);
          v14 = ecl_make_int64_t((v7code_symbols)->vector.self.i64[ecl_fixnum(T1)]);
          goto L46;
L47:;
          v14 = ECL_NIL;
L46:;
          if (Null(v14)) { goto L44; }
          v5symbol = v14;
          goto L1;
L44:;
          T0 = ecl_times(ecl_make_fixnum(v8code),ecl_make_fixnum(2));
L53:;
          T2 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          if (ecl_number_compare(T2,ecl_make_fixnum(1))<0) { goto L55; }
          goto L54;
L55:;
          {
          cl_object v15;
          T2 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          {
          uint8_t v16;
          T3 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v1bit_stream) /*  BIT-STREAM-STREAM */;
          v16 = ecl_fixnum(cl_read_byte(1, T3));
          T3 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          T4 = cl_ash(ecl_make_uint8_t(v16), T3);
          v15 = ecl_boole(ECL_BOOLIOR,(T2),(T4));
          }
          (v1bit_stream)->instance.slots[2]=v15;
          }
          {
          cl_object v15;
          T2 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          v15 = ecl_plus(T2,ecl_make_fixnum(8));
          (v1bit_stream)->instance.slots[3]=v15;
          }
          goto L53;
L54:;
          T2 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          if (!(ecl_number_equalp(T2,ecl_make_fixnum(1)))) { goto L63; }
          {
          cl_object v15;
          v15 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          (v1bit_stream)->instance.slots[2]=ecl_make_fixnum(0);
          (v1bit_stream)->instance.slots[3]=ecl_make_fixnum(0);
          T1 = v15;
          goto L51;
          }
L63:;
          {
          cl_object v16;
          T2 = cl_byte(ecl_make_fixnum(1), ecl_make_fixnum(0));
          T3 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          v16 = cl_ldb(T2, T3);
          {
          cl_object v17;
          T2 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          T3 = ecl_negate(ecl_make_fixnum(1));
          v17 = cl_ash(T2, T3);
          (v1bit_stream)->instance.slots[2]=v17;
          }
          {
          cl_object v17;
          T2 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          v17 = ecl_minus(T2,ecl_make_fixnum(1));
          (v1bit_stream)->instance.slots[3]=v17;
          }
          T1 = v16;
          }
L51:;
          v8code = ecl_fixnum(ecl_plus(T0,T1));
          v9index = ecl_fixnum(ecl_plus(ecl_make_fixnum(v9index),v13count));
          T0 = ecl_plus(ecl_make_fixnum(v10first),v13count);
          v10first = ecl_fixnum(ecl_times(T0,ecl_make_fixnum(2)));
          v12length = (v12length)+1;
          goto L11;
L12:;
          T0 = ecl_list1(ecl_make_fixnum(v8code));
          cl_error(5, VV[1], ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_7, ECL_SYM("FORMAT-ARGUMENTS",1239), T0);
          v5symbol = ECL_NIL;
         }
        }
       }
      }
     }
    }
   }
  }
L1:;
  goto L83;
L82:;
  if (!(ecl_number_compare(v5symbol,ecl_make_fixnum(255))<=0)) { goto L86; }
  {
   cl_fixnum v6end;
   v6end = ecl_fixnum(ecl_function_dispatch(cl_env_copy,VV[97])(1, v2window_stream) /*  SLIDING-WINDOW-STREAM-BUFFER-END */);
   if ((v6end)<(32768)) { goto L89; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[98])(1, v2window_stream) /*  SLIDING-WINDOW-STREAM-BUFFER */;
   T1 = ecl_function_dispatch(cl_env_copy,VV[99])(1, v2window_stream) /*  SLIDING-WINDOW-STREAM-STREAM */;
   cl_write_sequence(2, T0, T1);
   {
    cl_object v7;
    v7 = ecl_function_dispatch(cl_env_copy,VV[100])(1, v2window_stream) /*  SLIDING-WINDOW-STREAM-CHECKSUM */;
    if (!(ecl_eql(v7,VV[24]))) { goto L94; }
    {
     cl_fixnum v8;
     T0 = ecl_function_dispatch(cl_env_copy,VV[101])(1, v2window_stream) /*  SLIDING-WINDOW-STREAM-CHECKSUM-VALUE */;
     T1 = ecl_function_dispatch(cl_env_copy,VV[98])(1, v2window_stream) /*  SLIDING-WINDOW-STREAM-BUFFER */;
     v8 = ecl_fixnum(L7update_adler32_checksum(T0, T1, ecl_make_fixnum(32768)));
     (v2window_stream)->instance.slots[4]=ecl_make_fixnum(v8);
     goto L92;
    }
L94:;
    if (!(ecl_eql(v7,VV[25]))) { goto L92; }
    {
     cl_fixnum v9;
     T0 = ecl_function_dispatch(cl_env_copy,VV[101])(1, v2window_stream) /*  SLIDING-WINDOW-STREAM-CHECKSUM-VALUE */;
     T1 = ecl_function_dispatch(cl_env_copy,VV[98])(1, v2window_stream) /*  SLIDING-WINDOW-STREAM-BUFFER */;
     v9 = ecl_fixnum(L9update_crc32_checksum(T0, T1, ecl_make_fixnum(32768)));
     (v2window_stream)->instance.slots[4]=ecl_make_fixnum(v9);
    }
   }
L92:;
   v6end = 0;
L89:;
   {
    cl_object v7;
    v7 = ecl_function_dispatch(cl_env_copy,VV[98])(1, v2window_stream) /*  SLIDING-WINDOW-STREAM-BUFFER */;
    ecl_aset_unsafe(v7,v6end,v5symbol);
   }
   {
    cl_object v7;
    v7 = ecl_make_integer((v6end)+1);
    (v2window_stream)->instance.slots[2]=v7;
    goto L85;
   }
  }
L86:;
  {
   cl_object v8;
   cl_object v9;
   if (!(ecl_number_compare(v5symbol,ecl_make_fixnum(264))<=0)) { goto L104; }
   v8 = ecl_minus(v5symbol,ecl_make_fixnum(254));
   goto L103;
L104:;
   if (!(ecl_number_compare(v5symbol,ecl_make_fixnum(268))<=0)) { goto L106; }
   T0 = ecl_minus(v5symbol,ecl_make_fixnum(265));
   T1 = ecl_times(T0,ecl_make_fixnum(2));
   T2 = ecl_plus(ecl_make_fixnum(11),T1);
L110:;
   T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
   if (ecl_number_compare(T4,ecl_make_fixnum(1))<0) { goto L112; }
   goto L111;
L112:;
   {
    cl_object v10;
    T4 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
    {
     uint8_t v11;
     T5 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v1bit_stream) /*  BIT-STREAM-STREAM */;
     v11 = ecl_fixnum(cl_read_byte(1, T5));
     T5 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
     T6 = cl_ash(ecl_make_uint8_t(v11), T5);
     v10 = ecl_boole(ECL_BOOLIOR,(T4),(T6));
    }
    (v1bit_stream)->instance.slots[2]=v10;
   }
   {
    cl_object v10;
    T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
    v10 = ecl_plus(T4,ecl_make_fixnum(8));
    (v1bit_stream)->instance.slots[3]=v10;
   }
   goto L110;
L111:;
   T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
   if (!(ecl_number_equalp(T4,ecl_make_fixnum(1)))) { goto L120; }
   {
    cl_object v10;
    v10 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
    (v1bit_stream)->instance.slots[2]=ecl_make_fixnum(0);
    (v1bit_stream)->instance.slots[3]=ecl_make_fixnum(0);
    T3 = v10;
    goto L108;
   }
L120:;
   {
    cl_object v11;
    T4 = cl_byte(ecl_make_fixnum(1), ecl_make_fixnum(0));
    T5 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
    v11 = cl_ldb(T4, T5);
    {
     cl_object v12;
     T4 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
     {
      cl_fixnum v13;
      v13 = -(1);
      v12 = cl_ash(T4, ecl_make_fixnum(v13));
     }
     (v1bit_stream)->instance.slots[2]=v12;
    }
    {
     cl_object v12;
     T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
     v12 = ecl_minus(T4,ecl_make_fixnum(1));
     (v1bit_stream)->instance.slots[3]=v12;
    }
    T3 = v11;
   }
L108:;
   v8 = ecl_plus(T2,T3);
   goto L103;
L106:;
   if (!(ecl_number_compare(v5symbol,ecl_make_fixnum(272))<=0)) { goto L130; }
   T0 = ecl_minus(v5symbol,ecl_make_fixnum(269));
   T1 = ecl_times(T0,ecl_make_fixnum(4));
   T2 = ecl_plus(ecl_make_fixnum(19),T1);
L134:;
   T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
   if (ecl_number_compare(T4,ecl_make_fixnum(2))<0) { goto L136; }
   goto L135;
L136:;
   {
    cl_object v10;
    T4 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
    {
     uint8_t v11;
     T5 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v1bit_stream) /*  BIT-STREAM-STREAM */;
     v11 = ecl_fixnum(cl_read_byte(1, T5));
     T5 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
     T6 = cl_ash(ecl_make_uint8_t(v11), T5);
     v10 = ecl_boole(ECL_BOOLIOR,(T4),(T6));
    }
    (v1bit_stream)->instance.slots[2]=v10;
   }
   {
    cl_object v10;
    T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
    v10 = ecl_plus(T4,ecl_make_fixnum(8));
    (v1bit_stream)->instance.slots[3]=v10;
   }
   goto L134;
L135:;
   T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
   if (!(ecl_number_equalp(T4,ecl_make_fixnum(2)))) { goto L144; }
   {
    cl_object v10;
    v10 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
    (v1bit_stream)->instance.slots[2]=ecl_make_fixnum(0);
    (v1bit_stream)->instance.slots[3]=ecl_make_fixnum(0);
    T3 = v10;
    goto L132;
   }
L144:;
   {
    cl_object v11;
    T4 = cl_byte(ecl_make_fixnum(2), ecl_make_fixnum(0));
    T5 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
    v11 = cl_ldb(T4, T5);
    {
     cl_object v12;
     T4 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
     {
      cl_fixnum v13;
      v13 = -(2);
      v12 = cl_ash(T4, ecl_make_fixnum(v13));
     }
     (v1bit_stream)->instance.slots[2]=v12;
    }
    {
     cl_object v12;
     T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
     v12 = ecl_minus(T4,ecl_make_fixnum(2));
     (v1bit_stream)->instance.slots[3]=v12;
    }
    T3 = v11;
   }
L132:;
   v8 = ecl_plus(T2,T3);
   goto L103;
L130:;
   if (!(ecl_number_compare(v5symbol,ecl_make_fixnum(276))<=0)) { goto L154; }
   T0 = ecl_minus(v5symbol,ecl_make_fixnum(273));
   T1 = ecl_times(T0,ecl_make_fixnum(8));
   T2 = ecl_plus(ecl_make_fixnum(35),T1);
L158:;
   T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
   if (ecl_number_compare(T4,ecl_make_fixnum(3))<0) { goto L160; }
   goto L159;
L160:;
   {
    cl_object v10;
    T4 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
    {
     uint8_t v11;
     T5 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v1bit_stream) /*  BIT-STREAM-STREAM */;
     v11 = ecl_fixnum(cl_read_byte(1, T5));
     T5 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
     T6 = cl_ash(ecl_make_uint8_t(v11), T5);
     v10 = ecl_boole(ECL_BOOLIOR,(T4),(T6));
    }
    (v1bit_stream)->instance.slots[2]=v10;
   }
   {
    cl_object v10;
    T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
    v10 = ecl_plus(T4,ecl_make_fixnum(8));
    (v1bit_stream)->instance.slots[3]=v10;
   }
   goto L158;
L159:;
   T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
   if (!(ecl_number_equalp(T4,ecl_make_fixnum(3)))) { goto L168; }
   {
    cl_object v10;
    v10 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
    (v1bit_stream)->instance.slots[2]=ecl_make_fixnum(0);
    (v1bit_stream)->instance.slots[3]=ecl_make_fixnum(0);
    T3 = v10;
    goto L156;
   }
L168:;
   {
    cl_object v11;
    T4 = cl_byte(ecl_make_fixnum(3), ecl_make_fixnum(0));
    T5 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
    v11 = cl_ldb(T4, T5);
    {
     cl_object v12;
     T4 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
     {
      cl_fixnum v13;
      v13 = -(3);
      v12 = cl_ash(T4, ecl_make_fixnum(v13));
     }
     (v1bit_stream)->instance.slots[2]=v12;
    }
    {
     cl_object v12;
     T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
     v12 = ecl_minus(T4,ecl_make_fixnum(3));
     (v1bit_stream)->instance.slots[3]=v12;
    }
    T3 = v11;
   }
L156:;
   v8 = ecl_plus(T2,T3);
   goto L103;
L154:;
   if (!(ecl_number_compare(v5symbol,ecl_make_fixnum(280))<=0)) { goto L178; }
   T0 = ecl_minus(v5symbol,ecl_make_fixnum(277));
   T1 = ecl_times(T0,ecl_make_fixnum(16));
   T2 = ecl_plus(ecl_make_fixnum(67),T1);
L182:;
   T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
   if (ecl_number_compare(T4,ecl_make_fixnum(4))<0) { goto L184; }
   goto L183;
L184:;
   {
    cl_object v10;
    T4 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
    {
     uint8_t v11;
     T5 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v1bit_stream) /*  BIT-STREAM-STREAM */;
     v11 = ecl_fixnum(cl_read_byte(1, T5));
     T5 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
     T6 = cl_ash(ecl_make_uint8_t(v11), T5);
     v10 = ecl_boole(ECL_BOOLIOR,(T4),(T6));
    }
    (v1bit_stream)->instance.slots[2]=v10;
   }
   {
    cl_object v10;
    T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
    v10 = ecl_plus(T4,ecl_make_fixnum(8));
    (v1bit_stream)->instance.slots[3]=v10;
   }
   goto L182;
L183:;
   T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
   if (!(ecl_number_equalp(T4,ecl_make_fixnum(4)))) { goto L192; }
   {
    cl_object v10;
    v10 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
    (v1bit_stream)->instance.slots[2]=ecl_make_fixnum(0);
    (v1bit_stream)->instance.slots[3]=ecl_make_fixnum(0);
    T3 = v10;
    goto L180;
   }
L192:;
   {
    cl_object v11;
    T4 = cl_byte(ecl_make_fixnum(4), ecl_make_fixnum(0));
    T5 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
    v11 = cl_ldb(T4, T5);
    {
     cl_object v12;
     T4 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
     {
      cl_fixnum v13;
      v13 = -(4);
      v12 = cl_ash(T4, ecl_make_fixnum(v13));
     }
     (v1bit_stream)->instance.slots[2]=v12;
    }
    {
     cl_object v12;
     T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
     v12 = ecl_minus(T4,ecl_make_fixnum(4));
     (v1bit_stream)->instance.slots[3]=v12;
    }
    T3 = v11;
   }
L180:;
   v8 = ecl_plus(T2,T3);
   goto L103;
L178:;
   if (!(ecl_number_compare(v5symbol,ecl_make_fixnum(284))<=0)) { goto L202; }
   T0 = ecl_minus(v5symbol,ecl_make_fixnum(281));
   T1 = ecl_times(T0,ecl_make_fixnum(32));
   T2 = ecl_plus(ecl_make_fixnum(131),T1);
L206:;
   T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
   if (ecl_number_compare(T4,ecl_make_fixnum(5))<0) { goto L208; }
   goto L207;
L208:;
   {
    cl_object v10;
    T4 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
    {
     uint8_t v11;
     T5 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v1bit_stream) /*  BIT-STREAM-STREAM */;
     v11 = ecl_fixnum(cl_read_byte(1, T5));
     T5 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
     T6 = cl_ash(ecl_make_uint8_t(v11), T5);
     v10 = ecl_boole(ECL_BOOLIOR,(T4),(T6));
    }
    (v1bit_stream)->instance.slots[2]=v10;
   }
   {
    cl_object v10;
    T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
    v10 = ecl_plus(T4,ecl_make_fixnum(8));
    (v1bit_stream)->instance.slots[3]=v10;
   }
   goto L206;
L207:;
   T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
   if (!(ecl_number_equalp(T4,ecl_make_fixnum(5)))) { goto L216; }
   {
    cl_object v10;
    v10 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
    (v1bit_stream)->instance.slots[2]=ecl_make_fixnum(0);
    (v1bit_stream)->instance.slots[3]=ecl_make_fixnum(0);
    T3 = v10;
    goto L204;
   }
L216:;
   {
    cl_object v11;
    T4 = cl_byte(ecl_make_fixnum(5), ecl_make_fixnum(0));
    T5 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
    v11 = cl_ldb(T4, T5);
    {
     cl_object v12;
     T4 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
     {
      cl_fixnum v13;
      v13 = -(5);
      v12 = cl_ash(T4, ecl_make_fixnum(v13));
     }
     (v1bit_stream)->instance.slots[2]=v12;
    }
    {
     cl_object v12;
     T4 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
     v12 = ecl_minus(T4,ecl_make_fixnum(5));
     (v1bit_stream)->instance.slots[3]=v12;
    }
    T3 = v11;
   }
L204:;
   v8 = ecl_plus(T2,T3);
   goto L103;
L202:;
   if (!(ecl_number_equalp(v5symbol,ecl_make_fixnum(285)))) { goto L226; }
   v8 = ecl_make_fixnum(258);
   goto L103;
L226:;
   T0 = ecl_list1(v5symbol);
   v8 = cl_error(5, VV[1], ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_8, ECL_SYM("FORMAT-ARGUMENTS",1239), T0);
L103:;
   {
    cl_object v10;
    {
     cl_object v11length_count;
     v11length_count = ecl_function_dispatch(cl_env_copy,VV[118])(1, v4dist_decode_tree) /*  DECODE-TREE-LENGTH-COUNT */;
     {
      cl_object v12code_symbols;
      v12code_symbols = ecl_function_dispatch(cl_env_copy,VV[119])(1, v4dist_decode_tree) /*  DECODE-TREE-CODE-SYMBOLS */;
      {
       cl_fixnum v13code;
       v13code = 0;
       {
        cl_fixnum v14index;
        v14index = 0;
        {
         cl_fixnum v15first;
         v15first = 0;
         {
          cl_fixnum v16;
          cl_fixnum v17length;
          v16 = (v11length_count)->vector.fillp;
          v17length = 1;
          {
          cl_object v18count;
          v18count = ECL_NIL;
          {
          cl_object v19;
          v19 = ECL_NIL;
L244:;
          T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          if (ecl_number_compare(T0,ecl_make_fixnum(1))<0) { goto L246; }
          goto L245;
L246:;
          {
          cl_object v20;
          T0 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          {
          uint8_t v21;
          T1 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v1bit_stream) /*  BIT-STREAM-STREAM */;
          v21 = ecl_fixnum(cl_read_byte(1, T1));
          T1 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          T2 = cl_ash(ecl_make_uint8_t(v21), T1);
          v20 = ecl_boole(ECL_BOOLIOR,(T0),(T2));
          }
          (v1bit_stream)->instance.slots[2]=v20;
          }
          {
          cl_object v20;
          T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          v20 = ecl_plus(T0,ecl_make_fixnum(8));
          (v1bit_stream)->instance.slots[3]=v20;
          }
          goto L244;
L245:;
          T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          if (!(ecl_number_equalp(T0,ecl_make_fixnum(1)))) { goto L254; }
          {
          cl_object v20;
          v20 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          (v1bit_stream)->instance.slots[2]=ecl_make_fixnum(0);
          (v1bit_stream)->instance.slots[3]=ecl_make_fixnum(0);
          v13code = ecl_fixnum(v20);
          goto L242;
          }
L254:;
          {
          cl_object v21;
          T0 = cl_byte(ecl_make_fixnum(1), ecl_make_fixnum(0));
          T1 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          v21 = cl_ldb(T0, T1);
          {
          cl_object v22;
          T0 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          {
          cl_fixnum v23;
          v23 = -(1);
          v22 = cl_ash(T0, ecl_make_fixnum(v23));
          }
          (v1bit_stream)->instance.slots[2]=v22;
          }
          {
          cl_object v22;
          T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          v22 = ecl_minus(T0,ecl_make_fixnum(1));
          (v1bit_stream)->instance.slots[3]=v22;
          }
          v13code = ecl_fixnum(v21);
          }
L242:;
          v14index = 0;
          v15first = 0;
L239:;
          if (!((v17length)>=(v16))) { goto L268; }
          goto L240;
L268:;
          v18count = ecl_make_int64_t((v11length_count)->vector.self.i64[v17length]);
          T0 = ecl_plus(ecl_make_fixnum(v15first),v18count);
          if (!((v13code)<(ecl_fixnum(T0)))) { goto L275; }
          T0 = ecl_minus(ecl_make_fixnum(v13code),ecl_make_fixnum(v15first));
          T1 = ecl_plus(ecl_make_fixnum(v14index),T0);
          v19 = ecl_make_int64_t((v12code_symbols)->vector.self.i64[ecl_fixnum(T1)]);
          goto L274;
L275:;
          v19 = ECL_NIL;
L274:;
          if (Null(v19)) { goto L272; }
          v10 = v19;
          goto L229;
L272:;
          T0 = ecl_times(ecl_make_fixnum(v13code),ecl_make_fixnum(2));
L281:;
          T2 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          if (ecl_number_compare(T2,ecl_make_fixnum(1))<0) { goto L283; }
          goto L282;
L283:;
          {
          cl_object v20;
          T2 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          {
          uint8_t v21;
          T3 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v1bit_stream) /*  BIT-STREAM-STREAM */;
          v21 = ecl_fixnum(cl_read_byte(1, T3));
          T3 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          T4 = cl_ash(ecl_make_uint8_t(v21), T3);
          v20 = ecl_boole(ECL_BOOLIOR,(T2),(T4));
          }
          (v1bit_stream)->instance.slots[2]=v20;
          }
          {
          cl_object v20;
          T2 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          v20 = ecl_plus(T2,ecl_make_fixnum(8));
          (v1bit_stream)->instance.slots[3]=v20;
          }
          goto L281;
L282:;
          T2 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          if (!(ecl_number_equalp(T2,ecl_make_fixnum(1)))) { goto L291; }
          {
          cl_object v20;
          v20 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          (v1bit_stream)->instance.slots[2]=ecl_make_fixnum(0);
          (v1bit_stream)->instance.slots[3]=ecl_make_fixnum(0);
          T1 = v20;
          goto L279;
          }
L291:;
          {
          cl_object v21;
          T2 = cl_byte(ecl_make_fixnum(1), ecl_make_fixnum(0));
          T3 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          v21 = cl_ldb(T2, T3);
          {
          cl_object v22;
          T2 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          {
          cl_fixnum v23;
          v23 = -(1);
          v22 = cl_ash(T2, ecl_make_fixnum(v23));
          }
          (v1bit_stream)->instance.slots[2]=v22;
          }
          {
          cl_object v22;
          T2 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          v22 = ecl_minus(T2,ecl_make_fixnum(1));
          (v1bit_stream)->instance.slots[3]=v22;
          }
          T1 = v21;
          }
L279:;
          v13code = ecl_fixnum(ecl_plus(T0,T1));
          v14index = ecl_fixnum(ecl_plus(ecl_make_fixnum(v14index),v18count));
          T0 = ecl_plus(ecl_make_fixnum(v15first),v18count);
          v15first = ecl_fixnum(ecl_times(T0,ecl_make_fixnum(2)));
          v17length = (v17length)+1;
          goto L239;
L240:;
          T0 = ecl_list1(ecl_make_fixnum(v13code));
          cl_error(5, VV[1], ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_7, ECL_SYM("FORMAT-ARGUMENTS",1239), T0);
          v10 = ECL_NIL;
          }
          }
         }
        }
       }
      }
     }
    }
L229:;
    if (!(ecl_number_compare(v10,ecl_make_fixnum(3))<=0)) { goto L309; }
    v9 = ecl_one_plus(v10);
    goto L228;
L309:;
    {
     cl_object v12;                               /*  ORDER           */
     cl_object v13;                               /*  OFFSET          */
     value0 = ecl_truncate2(v10,ecl_make_fixnum(2));
     v12 = value0;
     v13 = cl_env_copy->values[1];
     {
      cl_object v14extra_bits;
      cl_object v15factor;
      v14extra_bits = ecl_one_minus(v12);
      v15factor = cl_ash(ecl_make_fixnum(1), v14extra_bits);
      T0 = cl_ash(ecl_make_fixnum(1), v12);
      T1 = ecl_one_plus(T0);
      T2 = ecl_times(v13,v15factor);
      T3 = ecl_plus(T1,T2);
L316:;
      T5 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
      if (ecl_number_compare(T5,v14extra_bits)<0) { goto L318; }
      goto L317;
L318:;
      {
       cl_object v16;
       T5 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
       {
        uint8_t v17;
        T6 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v1bit_stream) /*  BIT-STREAM-STREAM */;
        v17 = ecl_fixnum(cl_read_byte(1, T6));
        T6 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
        T7 = cl_ash(ecl_make_uint8_t(v17), T6);
        v16 = ecl_boole(ECL_BOOLIOR,(T5),(T7));
       }
       (v1bit_stream)->instance.slots[2]=v16;
      }
      {
       cl_object v16;
       T5 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
       v16 = ecl_plus(T5,ecl_make_fixnum(8));
       (v1bit_stream)->instance.slots[3]=v16;
      }
      goto L316;
L317:;
      T5 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
      if (!(ecl_number_equalp(T5,v14extra_bits))) { goto L326; }
      {
       cl_object v16;
       v16 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
       (v1bit_stream)->instance.slots[2]=ecl_make_fixnum(0);
       (v1bit_stream)->instance.slots[3]=ecl_make_fixnum(0);
       T4 = v16;
       goto L314;
      }
L326:;
      {
       cl_object v17;
       T5 = cl_byte(v14extra_bits, ecl_make_fixnum(0));
       T6 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
       v17 = cl_ldb(T5, T6);
       {
        cl_object v18;
        T5 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
        T6 = ecl_negate(v14extra_bits);
        v18 = cl_ash(T5, T6);
        (v1bit_stream)->instance.slots[2]=v18;
       }
       {
        cl_object v18;
        T5 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
        v18 = ecl_minus(T5,v14extra_bits);
        (v1bit_stream)->instance.slots[3]=v18;
       }
       T4 = v17;
      }
L314:;
      v9 = ecl_plus(T3,T4);
     }
    }
   }
L228:;
   L13sliding_window_stream_copy_bytes(v2window_stream, v9, v8);
  }
L85:;
  {
   cl_object v6length_count;
   v6length_count = ecl_function_dispatch(cl_env_copy,VV[118])(1, v3lit_decode_tree) /*  DECODE-TREE-LENGTH-COUNT */;
   {
    cl_object v7code_symbols;
    v7code_symbols = ecl_function_dispatch(cl_env_copy,VV[119])(1, v3lit_decode_tree) /*  DECODE-TREE-CODE-SYMBOLS */;
    {
     cl_fixnum v8code;
     v8code = 0;
     {
      cl_fixnum v9index;
      v9index = 0;
      {
       cl_fixnum v10first;
       v10first = 0;
       {
        cl_fixnum v11;
        cl_fixnum v12length;
        v11 = (v6length_count)->vector.fillp;
        v12length = 1;
        {
         cl_object v13count;
         v13count = ECL_NIL;
         {
          cl_object v14;
          v14 = ECL_NIL;
L352:;
          T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          if (ecl_number_compare(T0,ecl_make_fixnum(1))<0) { goto L354; }
          goto L353;
L354:;
          {
          cl_object v15;
          T0 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          {
          uint8_t v16;
          T1 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v1bit_stream) /*  BIT-STREAM-STREAM */;
          v16 = ecl_fixnum(cl_read_byte(1, T1));
          T1 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          T2 = cl_ash(ecl_make_uint8_t(v16), T1);
          v15 = ecl_boole(ECL_BOOLIOR,(T0),(T2));
          }
          (v1bit_stream)->instance.slots[2]=v15;
          }
          {
          cl_object v15;
          T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          v15 = ecl_plus(T0,ecl_make_fixnum(8));
          (v1bit_stream)->instance.slots[3]=v15;
          }
          goto L352;
L353:;
          T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          if (!(ecl_number_equalp(T0,ecl_make_fixnum(1)))) { goto L362; }
          {
          cl_object v15;
          v15 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          (v1bit_stream)->instance.slots[2]=ecl_make_fixnum(0);
          (v1bit_stream)->instance.slots[3]=ecl_make_fixnum(0);
          v8code = ecl_fixnum(v15);
          goto L350;
          }
L362:;
          {
          cl_object v16;
          T0 = cl_byte(ecl_make_fixnum(1), ecl_make_fixnum(0));
          T1 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          v16 = cl_ldb(T0, T1);
          {
          cl_object v17;
          T0 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          {
          cl_fixnum v18;
          v18 = -(1);
          v17 = cl_ash(T0, ecl_make_fixnum(v18));
          }
          (v1bit_stream)->instance.slots[2]=v17;
          }
          {
          cl_object v17;
          T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          v17 = ecl_minus(T0,ecl_make_fixnum(1));
          (v1bit_stream)->instance.slots[3]=v17;
          }
          v8code = ecl_fixnum(v16);
          }
L350:;
          v9index = 0;
          v10first = 0;
L347:;
          if (!((v12length)>=(v11))) { goto L376; }
          goto L348;
L376:;
          v13count = ecl_make_int64_t((v6length_count)->vector.self.i64[v12length]);
          T0 = ecl_plus(ecl_make_fixnum(v10first),v13count);
          if (!((v8code)<(ecl_fixnum(T0)))) { goto L383; }
          T0 = ecl_minus(ecl_make_fixnum(v8code),ecl_make_fixnum(v10first));
          T1 = ecl_plus(ecl_make_fixnum(v9index),T0);
          v14 = ecl_make_int64_t((v7code_symbols)->vector.self.i64[ecl_fixnum(T1)]);
          goto L382;
L383:;
          v14 = ECL_NIL;
L382:;
          if (Null(v14)) { goto L380; }
          v5symbol = v14;
          goto L337;
L380:;
          T0 = ecl_times(ecl_make_fixnum(v8code),ecl_make_fixnum(2));
L389:;
          T2 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          if (ecl_number_compare(T2,ecl_make_fixnum(1))<0) { goto L391; }
          goto L390;
L391:;
          {
          cl_object v15;
          T2 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          {
          uint8_t v16;
          T3 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v1bit_stream) /*  BIT-STREAM-STREAM */;
          v16 = ecl_fixnum(cl_read_byte(1, T3));
          T3 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          T4 = cl_ash(ecl_make_uint8_t(v16), T3);
          v15 = ecl_boole(ECL_BOOLIOR,(T2),(T4));
          }
          (v1bit_stream)->instance.slots[2]=v15;
          }
          {
          cl_object v15;
          T2 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          v15 = ecl_plus(T2,ecl_make_fixnum(8));
          (v1bit_stream)->instance.slots[3]=v15;
          }
          goto L389;
L390:;
          T2 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          if (!(ecl_number_equalp(T2,ecl_make_fixnum(1)))) { goto L399; }
          {
          cl_object v15;
          v15 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          (v1bit_stream)->instance.slots[2]=ecl_make_fixnum(0);
          (v1bit_stream)->instance.slots[3]=ecl_make_fixnum(0);
          T1 = v15;
          goto L387;
          }
L399:;
          {
          cl_object v16;
          T2 = cl_byte(ecl_make_fixnum(1), ecl_make_fixnum(0));
          T3 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          v16 = cl_ldb(T2, T3);
          {
          cl_object v17;
          T2 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
          {
          cl_fixnum v18;
          v18 = -(1);
          v17 = cl_ash(T2, ecl_make_fixnum(v18));
          }
          (v1bit_stream)->instance.slots[2]=v17;
          }
          {
          cl_object v17;
          T2 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
          v17 = ecl_minus(T2,ecl_make_fixnum(1));
          (v1bit_stream)->instance.slots[3]=v17;
          }
          T1 = v16;
          }
L387:;
          v8code = ecl_fixnum(ecl_plus(T0,T1));
          v9index = ecl_fixnum(ecl_plus(ecl_make_fixnum(v9index),v13count));
          T0 = ecl_plus(ecl_make_fixnum(v10first),v13count);
          v10first = ecl_fixnum(ecl_times(T0,ecl_make_fixnum(2)));
          v12length = (v12length)+1;
          goto L347;
L348:;
          T0 = ecl_list1(ecl_make_fixnum(v8code));
          cl_error(5, VV[1], ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_7, ECL_SYM("FORMAT-ARGUMENTS",1239), T0);
          v5symbol = ECL_NIL;
         }
        }
       }
      }
     }
    }
   }
  }
L337:;
L83:;
  if (ecl_number_equalp(v5symbol,ecl_make_fixnum(256))) { goto L417; }
  goto L82;
L417:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for DECODE-BLOCK                          */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object L26decode_block(cl_object v1bit_stream, cl_object v2window_stream)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v3finalp;
  cl_object v4type;
L4:;
  T1 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
  if (ecl_number_compare(T1,ecl_make_fixnum(1))<0) { goto L6; }
  goto L5;
L6:;
  {
   cl_object v5;
   T1 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
   {
    uint8_t v6;
    T2 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v1bit_stream) /*  BIT-STREAM-STREAM */;
    v6 = ecl_fixnum(cl_read_byte(1, T2));
    T2 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
    T3 = cl_ash(ecl_make_uint8_t(v6), T2);
    v5 = ecl_boole(ECL_BOOLIOR,(T1),(T3));
   }
   (v1bit_stream)->instance.slots[2]=v5;
  }
  {
   cl_object v5;
   T1 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
   v5 = ecl_plus(T1,ecl_make_fixnum(8));
   (v1bit_stream)->instance.slots[3]=v5;
  }
  goto L4;
L5:;
  T1 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
  if (!(ecl_number_equalp(T1,ecl_make_fixnum(1)))) { goto L14; }
  {
   cl_object v5;
   v5 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
   (v1bit_stream)->instance.slots[2]=ecl_make_fixnum(0);
   (v1bit_stream)->instance.slots[3]=ecl_make_fixnum(0);
   T0 = v5;
   goto L2;
  }
L14:;
  {
   cl_object v6;
   T1 = cl_byte(ecl_make_fixnum(1), ecl_make_fixnum(0));
   T2 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
   v6 = cl_ldb(T1, T2);
   {
    cl_object v7;
    T1 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
    {
     cl_fixnum v8;
     v8 = -(1);
     v7 = cl_ash(T1, ecl_make_fixnum(v8));
    }
    (v1bit_stream)->instance.slots[2]=v7;
   }
   {
    cl_object v7;
    T1 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
    v7 = ecl_minus(T1,ecl_make_fixnum(1));
    (v1bit_stream)->instance.slots[3]=v7;
   }
   T0 = v6;
  }
L2:;
  {
   bool v5;
   v5 = ecl_zerop(T0);
   v3finalp = (v5)?ECL_NIL:ECL_T;
  }
L26:;
  T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
  if (ecl_number_compare(T0,ecl_make_fixnum(2))<0) { goto L28; }
  goto L27;
L28:;
  {
   cl_object v5;
   T0 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
   {
    uint8_t v6;
    T1 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v1bit_stream) /*  BIT-STREAM-STREAM */;
    v6 = ecl_fixnum(cl_read_byte(1, T1));
    T1 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
    T2 = cl_ash(ecl_make_uint8_t(v6), T1);
    v5 = ecl_boole(ECL_BOOLIOR,(T0),(T2));
   }
   (v1bit_stream)->instance.slots[2]=v5;
  }
  {
   cl_object v5;
   T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
   v5 = ecl_plus(T0,ecl_make_fixnum(8));
   (v1bit_stream)->instance.slots[3]=v5;
  }
  goto L26;
L27:;
  T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
  if (!(ecl_number_equalp(T0,ecl_make_fixnum(2)))) { goto L36; }
  {
   cl_object v5;
   v5 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
   (v1bit_stream)->instance.slots[2]=ecl_make_fixnum(0);
   (v1bit_stream)->instance.slots[3]=ecl_make_fixnum(0);
   v4type = v5;
   goto L24;
  }
L36:;
  {
   cl_object v6;
   T0 = cl_byte(ecl_make_fixnum(2), ecl_make_fixnum(0));
   T1 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
   v6 = cl_ldb(T0, T1);
   {
    cl_object v7;
    T0 = ecl_function_dispatch(cl_env_copy,VV[113])(1, v1bit_stream) /*  BIT-STREAM-BITS */;
    {
     cl_fixnum v8;
     v8 = -(2);
     v7 = cl_ash(T0, ecl_make_fixnum(v8));
    }
    (v1bit_stream)->instance.slots[2]=v7;
   }
   {
    cl_object v7;
    T0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1bit_stream) /*  BIT-STREAM-BIT-COUNT */;
    v7 = ecl_minus(T0,ecl_make_fixnum(2));
    (v1bit_stream)->instance.slots[3]=v7;
   }
   v4type = v6;
  }
L24:;
  if (!((v4type)==(ecl_make_fixnum(0)))) { goto L47; }
  (v1bit_stream)->instance.slots[2]=ecl_make_fixnum(0);
  (v1bit_stream)->instance.slots[3]=ecl_make_fixnum(0);
  {
   cl_object v5len;
   cl_object v6nlen;
   {
    uint8_t v7;
    T0 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v1bit_stream) /*  BIT-STREAM-STREAM */;
    v7 = ecl_fixnum(cl_read_byte(1, T0));
    {
     uint8_t v8;
     T0 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v1bit_stream) /*  BIT-STREAM-STREAM */;
     v8 = ecl_fixnum(cl_read_byte(1, T0));
     T0 = ecl_ash(ecl_make_uint8_t(v8),8);
     v5len = ecl_boole(ECL_BOOLIOR,(ecl_make_uint8_t(v7)),(T0));
    }
   }
   T0 = cl_byte(ecl_make_fixnum(16), ecl_make_fixnum(0));
   {
    uint8_t v7;
    T1 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v1bit_stream) /*  BIT-STREAM-STREAM */;
    v7 = ecl_fixnum(cl_read_byte(1, T1));
    {
     uint8_t v8;
     T1 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v1bit_stream) /*  BIT-STREAM-STREAM */;
     v8 = ecl_fixnum(cl_read_byte(1, T1));
     T1 = ecl_ash(ecl_make_uint8_t(v8),8);
     T2 = ecl_boole(ECL_BOOLIOR,(ecl_make_uint8_t(v7)),(T1));
     T3 = ecl_boole(ECL_BOOLXOR,(T2),ecl_make_fixnum(-1));
     v6nlen = cl_ldb(T0, T3);
    }
   }
   if (ecl_number_equalp(v5len,v6nlen)) { goto L57; }
   T0 = cl_list(2, v5len, v6nlen);
   cl_error(5, VV[1], ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_5, ECL_SYM("FORMAT-ARGUMENTS",1239), T0);
L57:;
   {
    cl_object v7i;
    v7i = ecl_make_fixnum(0);
    goto L61;
L60:;
    {
     uint8_t v8;
     T0 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v1bit_stream) /*  BIT-STREAM-STREAM */;
     v8 = ecl_fixnum(cl_read_byte(1, T0));
     {
      cl_fixnum v9end;
      v9end = ecl_fixnum(ecl_function_dispatch(cl_env_copy,VV[97])(1, v2window_stream) /*  SLIDING-WINDOW-STREAM-BUFFER-END */);
      if ((v9end)<(32768)) { goto L66; }
      T0 = ecl_function_dispatch(cl_env_copy,VV[98])(1, v2window_stream) /*  SLIDING-WINDOW-STREAM-BUFFER */;
      T1 = ecl_function_dispatch(cl_env_copy,VV[99])(1, v2window_stream) /*  SLIDING-WINDOW-STREAM-STREAM */;
      cl_write_sequence(2, T0, T1);
      {
       cl_object v10;
       v10 = ecl_function_dispatch(cl_env_copy,VV[100])(1, v2window_stream) /*  SLIDING-WINDOW-STREAM-CHECKSUM */;
       if (!(ecl_eql(v10,VV[24]))) { goto L71; }
       {
        cl_fixnum v11;
        T0 = ecl_function_dispatch(cl_env_copy,VV[101])(1, v2window_stream) /*  SLIDING-WINDOW-STREAM-CHECKSUM-VALUE */;
        T1 = ecl_function_dispatch(cl_env_copy,VV[98])(1, v2window_stream) /*  SLIDING-WINDOW-STREAM-BUFFER */;
        v11 = ecl_fixnum(L7update_adler32_checksum(T0, T1, ecl_make_fixnum(32768)));
        (v2window_stream)->instance.slots[4]=ecl_make_fixnum(v11);
        goto L69;
       }
L71:;
       if (!(ecl_eql(v10,VV[25]))) { goto L69; }
       {
        cl_fixnum v12;
        T0 = ecl_function_dispatch(cl_env_copy,VV[101])(1, v2window_stream) /*  SLIDING-WINDOW-STREAM-CHECKSUM-VALUE */;
        T1 = ecl_function_dispatch(cl_env_copy,VV[98])(1, v2window_stream) /*  SLIDING-WINDOW-STREAM-BUFFER */;
        v12 = ecl_fixnum(L9update_crc32_checksum(T0, T1, ecl_make_fixnum(32768)));
        (v2window_stream)->instance.slots[4]=ecl_make_fixnum(v12);
       }
      }
L69:;
      v9end = 0;
L66:;
      {
       cl_object v10;
       v10 = ecl_function_dispatch(cl_env_copy,VV[98])(1, v2window_stream) /*  SLIDING-WINDOW-STREAM-BUFFER */;
       ecl_aset_unsafe(v10,v9end,ecl_make_uint8_t(v8));
      }
      {
       cl_object v10;
       v10 = ecl_make_integer((v9end)+1);
       (v2window_stream)->instance.slots[2]=v10;
      }
     }
    }
    v7i = ecl_one_plus(v7i);
L61:;
    if (!(ecl_number_compare(v7i,v5len)<0)) { goto L82; }
    goto L60;
L82:;
    goto L46;
   }
  }
L47:;
  if (!((v4type)==(ecl_make_fixnum(1)))) { goto L84; }
  L25decode_huffman_block(v1bit_stream, v2window_stream, ECL_SYM_VAL(cl_env_copy,VV[55]), ECL_SYM_VAL(cl_env_copy,VV[56]));
  goto L46;
L84:;
  if (!((v4type)==(ecl_make_fixnum(2)))) { goto L86; }
  {
   cl_object v9;                                  /*  LIT-DECODE-TREE */
   cl_object v10;                                 /*  DIST-DECODE-TREE */
   value0 = L22decode_huffman_tables(v1bit_stream);
   v9 = value0;
   {
    const int v11 = cl_env_copy->nvalues;
    cl_object v12;
    v12 = (v11<=1)? ECL_NIL : cl_env_copy->values[1];
    v10 = v12;
   }
   L25decode_huffman_block(v1bit_stream, v2window_stream, v9, v10);
   goto L46;
  }
L86:;
  if (!((v4type)==(ecl_make_fixnum(3)))) { goto L89; }
  T0 = ecl_list1(v4type);
  cl_error(5, VV[1], ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_9, ECL_SYM("FORMAT-ARGUMENTS",1239), T0);
  goto L46;
L89:;
  si_ecase_error(v4type, VV[65]);
L46:;
  value0 = Null(v3finalp)?ECL_T:ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for PARSE-ZLIB-HEADER                     */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object L27parse_zlib_header(cl_object v1input_stream)
{
 cl_object T0, T1, T2, T3, T4, T5;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v2;
  cl_object v3;
  v2 = cl_read_byte(1, v1input_stream);
  v3 = cl_read_byte(1, v1input_stream);
  T0 = ecl_times(v2,ecl_make_fixnum(256));
  T1 = ecl_plus(T0,v3);
  T2 = (ecl_floor2(T1,ecl_make_fixnum(31)),cl_env_copy->values[1]);
  if (ecl_zerop(T2)) { goto L3; }
  T0 = cl_list(2, v2, v3);
  cl_error(5, VV[2], ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_10, ECL_SYM("FORMAT-ARGUMENTS",1239), T0);
L3:;
  {
   cl_object v4dict;
   T0 = cl_byte(ecl_make_fixnum(1), ecl_make_fixnum(5));
   T1 = cl_ldb(T0, v3);
   if (ecl_zerop(T1)) { goto L6; }
   v4dict = L28parse_zlib_checksum(v1input_stream);
   goto L5;
L6:;
   v4dict = ECL_NIL;
L5:;
   T0 = cl_byte(ecl_make_fixnum(4), ecl_make_fixnum(0));
   T1 = cl_ldb(T0, v2);
   T2 = cl_byte(ecl_make_fixnum(4), ecl_make_fixnum(4));
   T3 = cl_ldb(T2, v2);
   T4 = cl_byte(ecl_make_fixnum(2), ecl_make_fixnum(6));
   T5 = cl_ldb(T4, v3);
   cl_env_copy->nvalues = 4;
   cl_env_copy->values[3] = T5;
   cl_env_copy->values[2] = v4dict;
   cl_env_copy->values[1] = T3;
   cl_env_copy->values[0] = T1;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for PARSE-ZLIB-CHECKSUM                   */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object L28parse_zlib_checksum(cl_object v1input_stream)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 T0 = cl_read_byte(1, v1input_stream);
 T1 = ecl_times(T0,ecl_make_fixnum(256));
 T2 = ecl_times(T1,ecl_make_fixnum(256));
 T3 = ecl_times(T2,ecl_make_fixnum(256));
 T4 = cl_read_byte(1, v1input_stream);
 T5 = ecl_times(T4,ecl_make_fixnum(256));
 T6 = ecl_times(T5,ecl_make_fixnum(256));
 T7 = ecl_plus(T3,T6);
 T8 = cl_read_byte(1, v1input_stream);
 T9 = ecl_times(T8,ecl_make_fixnum(256));
 T10 = ecl_plus(T7,T9);
 T11 = cl_read_byte(1, v1input_stream);
 value0 = ecl_plus(T10,T11);
 cl_env_copy->nvalues = 1;
 return value0;
}
/*	function definition for PARSE-ZLIB-FOOTER                     */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object L29parse_zlib_footer(cl_object v1input_stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 value0 = L28parse_zlib_checksum(v1input_stream);
 return value0;
}
/*	function definition for PARSE-GZIP-HEADER                     */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object L30parse_gzip_header(cl_object v1input_stream)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v2;
  cl_object v3;
  cl_object v4;
  cl_object v5;
  v2 = cl_read_byte(1, v1input_stream);
  v3 = cl_read_byte(1, v1input_stream);
  v4 = cl_read_byte(1, v1input_stream);
  v5 = cl_read_byte(1, v1input_stream);
  if (!(ecl_number_equalp(v2,ecl_make_fixnum(31)))) { goto L8; }
  if (ecl_number_equalp(v3,ecl_make_fixnum(139))) { goto L5; }
  goto L6;
L8:;
  goto L6;
L6:;
  T0 = cl_list(4, ecl_make_fixnum(31), ecl_make_fixnum(139), v2, v3);
  cl_error(5, VV[3], ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_11, ECL_SYM("FORMAT-ARGUMENTS",1239), T0);
L5:;
  if (ecl_number_equalp(v4,ecl_make_fixnum(8))) { goto L10; }
  T0 = ecl_list1(v4);
  cl_error(5, VV[3], ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_12, ECL_SYM("FORMAT-ARGUMENTS",1239), T0);
L10:;
  T0 = cl_byte(ecl_make_fixnum(3), ecl_make_fixnum(5));
  T1 = cl_ldb(T0, v5);
  if (ecl_zerop(T1)) { goto L12; }
  T0 = ecl_list1(v5);
  cl_error(5, VV[3], ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_13, ECL_SYM("FORMAT-ARGUMENTS",1239), T0);
L12:;
  T0 = cl_byte(ecl_make_fixnum(1), ecl_make_fixnum(0));
  T1 = cl_ldb(T0, v5);
  {
   bool v6;
   v6 = ecl_number_equalp(ecl_make_fixnum(1),T1);
   T2 = L31parse_gzip_mtime(v1input_stream);
   T3 = cl_read_byte(1, v1input_stream);
   T4 = cl_read_byte(1, v1input_stream);
   T6 = cl_byte(ecl_make_fixnum(1), ecl_make_fixnum(2));
   T7 = cl_ldb(T6, v5);
   if (ecl_zerop(T7)) { goto L15; }
   T5 = L32parse_gzip_extra(v1input_stream);
   goto L14;
L15:;
   T5 = ECL_NIL;
L14:;
   T7 = cl_byte(ecl_make_fixnum(1), ecl_make_fixnum(3));
   T8 = cl_ldb(T7, v5);
   if (ecl_zerop(T8)) { goto L18; }
   T6 = L33parse_gzip_string(v1input_stream);
   goto L17;
L18:;
   T6 = ECL_NIL;
L17:;
   T8 = cl_byte(ecl_make_fixnum(1), ecl_make_fixnum(4));
   T9 = cl_ldb(T8, v5);
   if (ecl_zerop(T9)) { goto L21; }
   T7 = L33parse_gzip_string(v1input_stream);
   goto L20;
L21:;
   T7 = ECL_NIL;
L20:;
   T9 = cl_byte(ecl_make_fixnum(1), ecl_make_fixnum(1));
   T10 = cl_ldb(T9, v5);
   if (ecl_zerop(T10)) { goto L24; }
   T9 = cl_read_byte(1, v1input_stream);
   T10 = cl_read_byte(2, v1input_stream, ecl_make_fixnum(256));
   T8 = ecl_plus(T9,T10);
   goto L23;
L24:;
   T8 = ECL_NIL;
L23:;
   cl_env_copy->nvalues = 9;
   cl_env_copy->values[8] = T8;
   cl_env_copy->values[7] = T7;
   cl_env_copy->values[6] = T6;
   cl_env_copy->values[5] = T5;
   cl_env_copy->values[4] = T4;
   cl_env_copy->values[3] = T3;
   cl_env_copy->values[2] = T2;
   cl_env_copy->values[1] = ecl_make_bool(v6);
   cl_env_copy->values[0] = v4;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for PARSE-GZIP-MTIME                      */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object L31parse_gzip_mtime(cl_object v1input_stream)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v2time;
  T0 = cl_read_byte(1, v1input_stream);
  T1 = cl_read_byte(1, v1input_stream);
  T2 = ecl_times(T1,ecl_make_fixnum(256));
  T3 = ecl_plus(T0,T2);
  T4 = cl_read_byte(1, v1input_stream);
  T5 = ecl_times(T4,ecl_make_fixnum(256));
  T6 = ecl_times(T5,ecl_make_fixnum(256));
  T7 = ecl_plus(T3,T6);
  T8 = cl_read_byte(1, v1input_stream);
  T9 = ecl_times(T8,ecl_make_fixnum(256));
  T10 = ecl_times(T9,ecl_make_fixnum(256));
  T11 = ecl_times(T10,ecl_make_fixnum(256));
  v2time = ecl_plus(T7,T11);
  if (!(ecl_zerop(v2time))) { goto L2; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ecl_plus(v2time,ecl_make_fixnum(2208988800));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for PARSE-GZIP-EXTRA                      */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object L32parse_gzip_extra(cl_object v1input_stream)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v2length;
  cl_object v3result;
  T0 = cl_read_byte(1, v1input_stream);
  T1 = cl_read_byte(1, v1input_stream);
  T2 = ecl_times(T1,ecl_make_fixnum(256));
  v2length = ecl_plus(T0,T2);
  v3result = si_make_pure_array(ECL_SYM("BYTE8",1330), v2length, ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
  cl_read_sequence(2, v3result, v1input_stream);
  value0 = v3result;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for PARSE-GZIP-STRING                     */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object L33parse_gzip_string(cl_object v1input_stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v2string;
  v2string = cl_make_string_output_stream(0);
  {
   cl_object v3value;
   v3value = ECL_NIL;
L4:;
   v3value = cl_read_byte(1, v1input_stream);
   if (!(ecl_zerop(v3value))) { goto L8; }
   goto L5;
L8:;
   {
    ecl_character v4;
    v4 = ecl_fixnum(v3value);
    cl_write_char(2, CODE_CHAR(v4), v2string);
   }
   goto L4;
L5:;
  }
  value0 = cl_get_output_stream_string(v2string);
  return value0;
 }
}
/*	function definition for PARSE-GZIP-CHECKSUM                   */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object L34parse_gzip_checksum(cl_object v1input_stream)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 T0 = cl_read_byte(1, v1input_stream);
 T1 = cl_read_byte(1, v1input_stream);
 T2 = ecl_times(T1,ecl_make_fixnum(256));
 T3 = ecl_plus(T0,T2);
 T4 = cl_read_byte(1, v1input_stream);
 T5 = ecl_times(T4,ecl_make_fixnum(256));
 T6 = ecl_times(T5,ecl_make_fixnum(256));
 T7 = ecl_plus(T3,T6);
 T8 = cl_read_byte(1, v1input_stream);
 T9 = ecl_times(T8,ecl_make_fixnum(256));
 T10 = ecl_times(T9,ecl_make_fixnum(256));
 T11 = ecl_times(T10,ecl_make_fixnum(256));
 value0 = ecl_plus(T7,T11);
 cl_env_copy->nvalues = 1;
 return value0;
}
/*	function definition for PARSE-GZIP-FOOTER                     */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object L35parse_gzip_footer(cl_object v1input_stream)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 T0 = L34parse_gzip_checksum(v1input_stream);
 T1 = cl_read_byte(1, v1input_stream);
 T2 = cl_read_byte(1, v1input_stream);
 T3 = ecl_times(T2,ecl_make_fixnum(256));
 T4 = ecl_plus(T1,T3);
 T5 = cl_read_byte(1, v1input_stream);
 T6 = ecl_times(T5,ecl_make_fixnum(256));
 T7 = ecl_times(T6,ecl_make_fixnum(256));
 T8 = ecl_plus(T4,T7);
 T9 = cl_read_byte(1, v1input_stream);
 T10 = ecl_times(T9,ecl_make_fixnum(256));
 T11 = ecl_times(T10,ecl_make_fixnum(256));
 T12 = ecl_times(T11,ecl_make_fixnum(256));
 T13 = ecl_plus(T8,T12);
 cl_env_copy->nvalues = 2;
 cl_env_copy->values[1] = T13;
 cl_env_copy->values[0] = T0;
 return cl_env_copy->values[0];
}
/*	function definition for INFLATE-STREAM                        */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object L36inflate_stream(cl_narg narg, cl_object v1input_stream, cl_object v2output_stream, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 cl_object v3checksum;
 ecl_va_list args; ecl_va_start(args,v2output_stream,narg,2);
 {
  cl_object keyvars[2];
  cl_parse_key(args,1,L36inflate_streamkeys,keyvars,NULL,FALSE);
  ecl_va_end(args);
  v3checksum = keyvars[0];
 }
 {
  cl_object v4window_stream;
  if (!((v3checksum)==(ECL_NIL))) { goto L3; }
  T0 = ecl_make_fixnum(0);
  goto L2;
L3:;
  if (!(ecl_eql(v3checksum,VV[25]))) { goto L6; }
  T0 = ecl_make_fixnum(0);
  goto L2;
L6:;
  if (!(ecl_eql(v3checksum,VV[24]))) { goto L8; }
  T0 = ecl_make_fixnum(1);
  goto L2;
L8:;
  T0 = si_ecase_error(v3checksum, VV[81]);
L2:;
  v4window_stream = L10make_sliding_window_stream(6, ECL_SYM("STREAM",1313), v2output_stream, VV[78], v3checksum, VV[79], T0);
  {
   cl_object v5bit_stream;
   v5bit_stream = L14make_bit_stream(2, ECL_SYM("STREAM",1313), v1input_stream);
L11:;
   if ((L26decode_block(v5bit_stream, v4window_stream))!=ECL_NIL) { goto L13; }
   goto L12;
L13:;
   goto L11;
L12:;
   L12sliding_window_stream_flush(v4window_stream);
   if (Null(v3checksum)) { goto L16; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[101])(1, v4window_stream) /*  SLIDING-WINDOW-STREAM-CHECKSUM-VALUE */;
   return value0;
L16:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for INFLATE-ZLIB-STREAM                   */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object L37inflate_zlib_stream(cl_narg narg, cl_object v1input_stream, cl_object v2output_stream, ...)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 cl_object v3check_checksum;
 ecl_va_list args; ecl_va_start(args,v2output_stream,narg,2);
 {
  cl_object keyvars[2];
  cl_parse_key(args,1,L37inflate_zlib_streamkeys,keyvars,NULL,FALSE);
  ecl_va_end(args);
  v3check_checksum = keyvars[0];
 }
 {
  cl_object v5;                                   /*  CM              */
  cl_object v6;                                   /*  CINFO           */
  cl_object v7;                                   /*  DICTID          */
  cl_object v8;                                   /*  FLEVEL          */
  value0 = L27parse_zlib_header(v1input_stream);
  v5 = value0;
  {
   const int v9 = cl_env_copy->nvalues;
   cl_object v10;
   v10 = (v9<=1)? ECL_NIL : cl_env_copy->values[1];
   v6 = v10;
   v10 = (v9<=2)? ECL_NIL : cl_env_copy->values[2];
   v7 = v10;
   v10 = (v9<=3)? ECL_NIL : cl_env_copy->values[3];
   v8 = v10;
  }
  if (ecl_number_equalp(v5,ecl_make_fixnum(8))) { goto L2; }
  T0 = ecl_list1(v5);
  cl_error(5, VV[2], ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_14, ECL_SYM("FORMAT-ARGUMENTS",1239), T0);
L2:;
  if (ecl_number_compare(v6,ecl_make_fixnum(7))<=0) { goto L4; }
  T0 = ecl_plus(ecl_make_fixnum(8),v6);
  T1 = ecl_plus(ecl_make_fixnum(8),v6);
  T2 = ecl_expt(ecl_make_fixnum(2),T1);
  T3 = cl_list(2, T0, T2);
  cl_error(5, VV[2], ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_15, ECL_SYM("FORMAT-ARGUMENTS",1239), T3);
L4:;
  if (v7==ECL_NIL) { goto L6; }
  T0 = ecl_list1(v7);
  cl_error(5, VV[2], ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_16, ECL_SYM("FORMAT-ARGUMENTS",1239), T0);
L6:;
  {
   cl_object v9;
   cl_object v10;
   if (Null(v3check_checksum)) { goto L10; }
   T0 = VV[24];
   goto L9;
L10:;
   T0 = ECL_NIL;
L9:;
   v9 = L36inflate_stream(4, v1input_stream, v2output_stream, VV[78], T0);
   v10 = L29parse_zlib_footer(v1input_stream);
   if (Null(v3check_checksum)) { goto L13; }
   if (ecl_number_equalp(v10,v9)) { goto L13; }
   T0 = cl_list(2, v10, v9);
   cl_error(5, VV[2], ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_17, ECL_SYM("FORMAT-ARGUMENTS",1239), T0);
L13:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v8;
   cl_env_copy->values[0] = v10;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for INFLATE-GZIP-STREAM                   */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object L38inflate_gzip_stream(cl_narg narg, cl_object v1input_stream, cl_object v2output_stream, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 cl_object v3check_checksum;
 ecl_va_list args; ecl_va_start(args,v2output_stream,narg,2);
 {
  cl_object keyvars[2];
  cl_parse_key(args,1,L38inflate_gzip_streamkeys,keyvars,NULL,FALSE);
  ecl_va_end(args);
  v3check_checksum = keyvars[0];
 }
 {
  cl_object v5;                                   /*  CM              */
  cl_object v6;                                   /*  MTIME           */
  cl_object v7;                                   /*  FNAME           */
  cl_object v8;                                   /*  FCOMMENT        */
  value0 = L30parse_gzip_header(v1input_stream);
  v5 = value0;
  {
   const int v9 = cl_env_copy->nvalues;
   cl_object v10;
   v10 = (v9<=2)? ECL_NIL : cl_env_copy->values[2];
   v6 = v10;
   v10 = (v9<=6)? ECL_NIL : cl_env_copy->values[6];
   v7 = v10;
   v10 = (v9<=7)? ECL_NIL : cl_env_copy->values[7];
   v8 = v10;
  }
  if (ecl_number_equalp(v5,ecl_make_fixnum(8))) { goto L2; }
  T0 = ecl_list1(v5);
  cl_error(5, VV[3], ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_14, ECL_SYM("FORMAT-ARGUMENTS",1239), T0);
L2:;
  {
   cl_object v9;
   cl_object v10;
   if (Null(v3check_checksum)) { goto L6; }
   T0 = VV[25];
   goto L5;
L6:;
   T0 = ECL_NIL;
L5:;
   v9 = L36inflate_stream(4, v1input_stream, v2output_stream, VV[78], T0);
   v10 = L35parse_gzip_footer(v1input_stream);
   if (Null(v3check_checksum)) { goto L9; }
   if (ecl_number_equalp(v10,v9)) { goto L9; }
   T0 = cl_list(2, v10, v9);
   cl_error(5, VV[3], ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_17, ECL_SYM("FORMAT-ARGUMENTS",1239), T0);
L9:;
   cl_env_copy->nvalues = 4;
   cl_env_copy->values[3] = v8;
   cl_env_copy->values[2] = v6;
   cl_env_copy->values[1] = v7;
   cl_env_copy->values[0] = v10;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for GUNZIP                                */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object L39gunzip(cl_object volatile v1input_file, cl_object volatile v2output_file)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
TTL:
 {
  volatile cl_object v3input;
  v3input = cl_open(3, v1input_file, ECL_SYM("ELEMENT-TYPE",1224), VV[32]);
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
     volatile cl_object v6;
     v6 = _ecl_inner_frame;
     {
      volatile cl_object v7output;
      v7output = cl_open(7, v2output_file, ECL_SYM("DIRECTION",1218), ECL_SYM("OUTPUT",1282), ECL_SYM("IF-EXISTS",1245), ECL_SYM("SUPERSEDE",1314), ECL_SYM("ELEMENT-TYPE",1224), VV[32]);
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
         cl_env_copy->values[0] = L38inflate_gzip_stream(2, v3input, v7output);
         ecl_stack_frame_push_values(v10);
         if (Null(v7output)) { goto L14; }
         cl_close(1, v7output);
L14:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v10);
        }
        ecl_stack_frame_close(_ecl_inner_frame);
       }
       }
       ecl_frs_pop(cl_env_copy);
       v9=ecl_stack_push_values(cl_env_copy);
       if (Null(v7output)) { goto L16; }
       cl_close(3, v7output, ECL_SYM("ABORT",1195), ECL_T);
L16:;
       ecl_stack_pop_values(cl_env_copy,v9);
       if (unwinding) ecl_unwind(cl_env_copy,next_fr);
       ECL_STACK_SET_INDEX(cl_env_copy,v8);
      }
     }
     ecl_stack_frame_push_values(v6);
     if (Null(v3input)) { goto L18; }
     cl_close(1, v3input);
L18:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v6);
    }
    ecl_stack_frame_close(_ecl_inner_frame);
   }
   }
   ecl_frs_pop(cl_env_copy);
   v5=ecl_stack_push_values(cl_env_copy);
   if (Null(v3input)) { goto L20; }
   cl_close(3, v3input, ECL_SYM("ABORT",1195), ECL_T);
L20:;
   ecl_stack_pop_values(cl_env_copy,v5);
   if (unwinding) ecl_unwind(cl_env_copy,next_fr);
   ECL_STACK_SET_INDEX(cl_env_copy,v4);
  }
 }
 value0 = cl_probe_file(v2output_file);
 return value0;
}

#include "ext/deflate.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecl4N1I9dXpmctk9_HM5UOE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("EXT:DEFLATE;DEFLATE.LISP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_ecl4N1I9dXpmctk9_HM5UOE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 ecl_function_dispatch(cl_env_copy,VV[86])(10, _ecl_static_0, ECL_NIL, ECL_NIL, VVtemp[0], ECL_NIL, ECL_NIL, VVtemp[1], ECL_NIL, ECL_NIL, ECL_NIL) /*  DODEFPACKAGE */;
 si_select_package(_ecl_static_0);
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[2]) /*  MAPC */;
 clos_load_defclass(VV[0], VVtemp[3], ECL_NIL, ECL_NIL);
 {
  cl_object T0, T1, T2;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC2__g0,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 T1 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T0, VVtemp[5]);
 T2 = ecl_list1(T1);
 clos_load_defclass(VV[1], VVtemp[4], T2, ECL_NIL);
 }
 {
  cl_object T0, T1, T2;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC4__g2,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 T1 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T0, VVtemp[6]);
 T2 = ecl_list1(T1);
 clos_load_defclass(VV[2], VVtemp[4], T2, ECL_NIL);
 }
 {
  cl_object T0, T1, T2;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC6__g4,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 T1 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T0, VVtemp[6]);
 T2 = ecl_list1(T1);
 clos_load_defclass(VV[3], VVtemp[4], T2, ECL_NIL);
 }
 si_Xmake_constant(VV[4], ecl_make_fixnum(1));
 si_Xmake_constant(VV[5], ecl_make_fixnum(65521));
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[7]) /*  MAPC */;
 ecl_cmp_defun(VV[87]);                           /*  UPDATE-ADLER32-CHECKSUM */
 si_Xmake_constant(VV[7], ecl_make_fixnum(0));
 si_Xmake_constant(VV[8], ecl_make_fixnum(3988292384));
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[8]) /*  MAPC */;
 ecl_cmp_defun(VV[88]);                           /*  GENERATE-CRC32-TABLE */
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[9]) /*  MAPC */;
 VV[10]= L8generate_crc32_table();
 ecl_cmp_defun(VV[89]);                           /*  UPDATE-CRC32-CHECKSUM */
 si_Xmake_constant(VV[12], ecl_make_fixnum(32768));
 si_define_structure(15, VV[13], _ecl_static_3, ECL_NIL, ECL_NIL, VVtemp[10], VVtemp[11], VV[14], ECL_NIL, ECL_NIL, ECL_NIL, VVtemp[12], ecl_make_fixnum(5), ECL_NIL, ECL_NIL, VV[15]);
 VV[22]= cl_find_class(1, VV[13]);
 ecl_cmp_defun(VV[90]);                           /*  MAKE-SLIDING-WINDOW-STREAM */
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[13]) /*  MAPC */;
 ecl_cmp_defun(VV[96]);                           /*  SLIDING-WINDOW-STREAM-WRITE-BYTE */
 ecl_cmp_defun(VV[102]);                          /*  SLIDING-WINDOW-STREAM-FLUSH */
 ecl_cmp_defun(VV[103]);                          /*  SLIDING-WINDOW-STREAM-COPY-BYTES */
 si_define_structure(15, VV[29], _ecl_static_4, ECL_NIL, ECL_NIL, VVtemp[14], VVtemp[15], VV[30], ECL_NIL, ECL_NIL, ECL_NIL, VVtemp[16], ecl_make_fixnum(4), ECL_NIL, ECL_NIL, VV[31]);
 VV[37]= cl_find_class(1, VV[29]);
 ecl_cmp_defun(VV[104]);                          /*  MAKE-BIT-STREAM */
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[17]) /*  MAPC */;
 ecl_cmp_defun(VV[109]);                          /*  BIT-STREAM-GET-BYTE */
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[18]) /*  MAPC */;
 ecl_cmp_defun(VV[111]);                          /*  BIT-STREAM-READ-BITS */
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[19]) /*  MAPC */;
 ecl_cmp_defun(VV[114]);                          /*  BIT-STREAM-COPY-BLOCK */
 si_define_structure(15, VV[42], _ecl_static_6, ECL_NIL, ECL_NIL, VVtemp[20], VVtemp[21], VV[43], ECL_NIL, ECL_NIL, ECL_NIL, VVtemp[22], ecl_make_fixnum(2), ECL_NIL, ECL_NIL, VV[44]);
 VV[48]= cl_find_class(1, VV[42]);
 ecl_cmp_defun(VV[115]);                          /*  MAKE-DECODE-TREE */
 ecl_cmp_defun(VV[116]);                          /*  MAKE-HUFFMAN-DECODE-TREE */
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[23]) /*  MAPC */;
 ecl_cmp_defun(VV[117]);                          /*  READ-HUFFMAN-CODE */
 {
  cl_object T0, T1, T2, T3, T4;
 si_Xmake_special(VV[55]);
 T0 = cl_make_sequence(4, ECL_SYM("VECTOR",898), ecl_make_fixnum(144), ECL_SYM("INITIAL-ELEMENT",1251), ecl_make_fixnum(8));
 T1 = cl_make_sequence(4, ECL_SYM("VECTOR",898), ecl_make_fixnum(112), ECL_SYM("INITIAL-ELEMENT",1251), ecl_make_fixnum(9));
 T2 = cl_make_sequence(4, ECL_SYM("VECTOR",898), ecl_make_fixnum(24), ECL_SYM("INITIAL-ELEMENT",1251), ecl_make_fixnum(7));
 T3 = cl_make_sequence(4, ECL_SYM("VECTOR",898), ecl_make_fixnum(8), ECL_SYM("INITIAL-ELEMENT",1251), ecl_make_fixnum(8));
 T4 = cl_concatenate(5, ECL_SYM("VECTOR",898), T0, T1, T2, T3);
 ECL_SETQ(cl_env_copy,VV[55],L19make_huffman_decode_tree(T4));
 }
 {
  cl_object T0;
 si_Xmake_special(VV[56]);
 T0 = cl_make_sequence(4, ECL_SYM("VECTOR",898), ecl_make_fixnum(32), ECL_SYM("INITIAL-ELEMENT",1251), ecl_make_fixnum(5));
 ECL_SETQ(cl_env_copy,VV[56],L19make_huffman_decode_tree(T0));
 }
 si_Xmake_special(VV[57]);
 ECL_SETQ(cl_env_copy,VV[57],VVtemp[24]);
 ecl_cmp_defun(VV[120]);                          /*  DECODE-CODE-LENGTH-ENTRIES */
 ecl_cmp_defun(VV[121]);                          /*  DECODE-HUFFMAN-TABLES */
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[25]) /*  MAPC */;
 ecl_cmp_defun(VV[122]);                          /*  DECODE-LENGTH-ENTRY */
 (cl_env_copy->function=(ECL_SYM("MAPC",543)->symbol.gfdef))->cfun.entry(2, ECL_SYM("PROCLAIM",666), VVtemp[26]) /*  MAPC */;
 ecl_cmp_defun(VV[123]);                          /*  DECODE-DISTANCE-ENTRY */
 ecl_cmp_defun(VV[124]);                          /*  DECODE-HUFFMAN-BLOCK */
 ecl_cmp_defun(VV[125]);                          /*  DECODE-BLOCK    */
 ecl_cmp_defun(VV[126]);                          /*  PARSE-ZLIB-HEADER */
 ecl_cmp_defun(VV[127]);                          /*  PARSE-ZLIB-CHECKSUM */
 ecl_cmp_defun(VV[128]);                          /*  PARSE-ZLIB-FOOTER */
 si_Xmake_constant(VV[70], ecl_make_fixnum(31));
 si_Xmake_constant(VV[71], ecl_make_fixnum(139));
 ecl_cmp_defun(VV[129]);                          /*  PARSE-GZIP-HEADER */
 ecl_cmp_defun(VV[130]);                          /*  PARSE-GZIP-MTIME */
 ecl_cmp_defun(VV[131]);                          /*  PARSE-GZIP-EXTRA */
 ecl_cmp_defun(VV[132]);                          /*  PARSE-GZIP-STRING */
 ecl_cmp_defun(VV[133]);                          /*  PARSE-GZIP-CHECKSUM */
 ecl_cmp_defun(VV[134]);                          /*  PARSE-GZIP-FOOTER */
 ecl_cmp_defun(VV[135]);                          /*  INFLATE-STREAM  */
 ecl_cmp_defun(VV[136]);                          /*  INFLATE-ZLIB-STREAM */
 ecl_cmp_defun(VV[138]);                          /*  INFLATE-GZIP-STREAM */
 ecl_cmp_defun(VV[139]);                          /*  GUNZIP          */
}
