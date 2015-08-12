/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPFFI.LSP                                    */
#include <ecl/ecl-cmp.h>
#include "cmp/cmpffi.eclh"
/*	function definition for C-NUMBER-REP-TYPE-P                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1c_number_rep_type_p(cl_object v1rep_type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_memql(v1rep_type,VV[5]);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for C-INTEGER-REP-TYPE-P                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2c_integer_rep_type_p(cl_object v1rep_type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_memql(v1rep_type,VV[7]);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for C-INTEGER-REP-TYPE-BITS               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3c_integer_rep_type_bits(cl_object v1rep_type)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_assql(v1rep_type,ecl_symbol_value(VV[0]));
  T1 = ecl_cdr(T0);
  value0 = cl_abs(T1);
  return value0;
 }
}
/*	function definition for C-NUMBER-TYPE-P                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4c_number_type_p(cl_object v1type)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = L9lisp_type__rep_type(v1type);
  value0 = L1c_number_rep_type_p(T0);
  return value0;
 }
}
/*	function definition for C-INTEGER-TYPE-P                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5c_integer_type_p(cl_object v1type)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = L9lisp_type__rep_type(v1type);
  value0 = L2c_integer_rep_type_p(T0);
  return value0;
 }
}
/*	function definition for C-INTEGER-TYPE-BITS                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6c_integer_type_bits(cl_object v1type)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = L9lisp_type__rep_type(v1type);
  value0 = ecl_function_dispatch(cl_env_copy,VV[94])(1, T0) /*  C-NUMBER-REP-TYPE-BITS */;
  return value0;
 }
}
/*	function definition for REP-TYPE-RECORD                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7rep_type_record(cl_object v1rep_type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_gethash(2, v1rep_type, ecl_symbol_value(VV[4]));
  return value0;
 }
}
/*	function definition for REP-TYPE->LISP-TYPE                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8rep_type__lisp_type(cl_object v1rep_type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2output;
   v2output = L7rep_type_record(v1rep_type);
   if (Null(v2output)) { goto L2; }
   if (!((v1rep_type)==(ECL_SYM("VOID",1381)))) { goto L4; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L4:;
   value0 = ecl_car(v2output);
   if ((value0)!=ECL_NIL) { goto L7; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[97])(2, _ecl_static_1, v1rep_type) /*  CMPERR */;
   return value0;
L7:;
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
   if (Null(L11lisp_type_p(v1rep_type))) { goto L9; }
   value0 = v1rep_type;
   cl_env_copy->nvalues = 1;
   return value0;
L9:;
   value0 = ecl_function_dispatch(cl_env_copy,VV[97])(2, _ecl_static_2, v1rep_type) /*  CMPERR */;
   return value0;
  }
 }
}
/*	function definition for LISP-TYPE->REP-TYPE                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L9lisp_type__rep_type(cl_object v1type)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(v1type==ECL_NIL)) { goto L1; }
  value0 = ECL_SYM("OBJECT",1278);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (Null(L7rep_type_record(v1type))) { goto L3; }
  value0 = v1type;
  cl_env_copy->nvalues = 1;
  return value0;
L3:;
  {
   cl_object v2l;
   v2l = ecl_symbol_value(VV[3]);
   goto L8;
L7:;
   T0 = ecl_cadr(v2l);
   T1 = ecl_car(T0);
   if (Null(cl_subtypep(2, v1type, T1))) { goto L10; }
   value0 = ecl_car(v2l);
   cl_env_copy->nvalues = 1;
   return value0;
L10:;
   v2l = ecl_cddr(v2l);
L8:;
   if (ecl_endp(v2l)) { goto L14; }
   goto L7;
L14:;
   value0 = ECL_SYM("OBJECT",1278);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for REP-TYPE-NAME                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L10rep_type_name(cl_object v1type)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = L7rep_type_record(v1type);
  value0 = ecl_cadr(T0);
  if ((value0)!=ECL_NIL) { goto L2; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[97])(2, _ecl_static_3, v1type) /*  CMPERR */;
  return value0;
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for LISP-TYPE-P                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L11lisp_type_p(cl_object v1type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_subtypep(2, v1type, ECL_T);
  return value0;
 }
}
/*	function definition for WT-TO-OBJECT-CONVERSION               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L12wt_to_object_conversion(cl_object v1loc_rep_type, cl_object v2loc)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_CONSP(v2loc))) { goto L1; }
  {
   cl_object v3;
   v3 = ecl_car(v2loc);
   if (!((v3)==(VV[18]))) { goto L8; }
   goto L5;
   goto L6;
L8:;
   goto L6;
L6:;
   if (!((v3)==(VV[20]))) { goto L12; }
   goto L5;
   goto L10;
L12:;
   goto L10;
L10:;
   if (!((v3)==(VV[22]))) { goto L1; }
   goto L2;
L5:;
  }
L2:;
  T0 = ecl_caddr(v2loc);
  ecl_function_dispatch(cl_env_copy,VV[102])(1, T0) /*  WT            */;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  {
   cl_object v3x;
   T0 = L7rep_type_record(v1loc_rep_type);
   v3x = ecl_caddr(T0);
   if ((v3x)!=ECL_NIL) { goto L17; }
   ecl_function_dispatch(cl_env_copy,VV[97])(2, _ecl_static_4, v1loc_rep_type) /*  CMPERR */;
L17:;
   value0 = ecl_function_dispatch(cl_env_copy,VV[102])(4, v3x, _ecl_static_5, v2loc, _ecl_static_6) /*  WT */;
   return value0;
  }
 }
}
/*	function definition for WT-FROM-OBJECT-CONVERSION             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L13wt_from_object_conversion(cl_object v1dest_type, cl_object v2loc_type, cl_object v3rep_type, cl_object v4loc)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v5x;
   T0 = L7rep_type_record(v3rep_type);
   v5x = ecl_cdddr(T0);
   if ((v5x)!=ECL_NIL) { goto L2; }
   ecl_function_dispatch(cl_env_copy,VV[97])(2, _ecl_static_7, v3rep_type) /*  CMPERR */;
L2:;
   if ((ecl_function_dispatch(cl_env_copy,VV[104])(0) /*  POLICY-ASSUME-NO-ERRORS */)!=ECL_NIL) { goto L7; }
   if (Null(cl_subtypep(2, v2loc_type, v1dest_type))) { goto L5; }
   goto L6;
L7:;
L6:;
   T0 = ecl_cadr(v5x);
   goto L4;
L5:;
   T0 = ecl_car(v5x);
L4:;
   value0 = ecl_function_dispatch(cl_env_copy,VV[102])(4, T0, _ecl_static_5, v4loc, _ecl_static_6) /*  WT */;
   return value0;
  }
 }
}
/*	function definition for LOC-MOVABLE-P                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L14loc_movable_p(cl_object v1loc)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_ATOM(v1loc))) { goto L1; }
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  {
   cl_object v2;
   v2 = ecl_car(v1loc);
   if (!((v2)==(VV[26]))) { goto L9; }
   goto L6;
   goto L7;
L9:;
   goto L7;
L7:;
   if (!((v2)==(VV[28]))) { goto L4; }
   goto L5;
L6:;
L5:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L4:;
   if (!((v2)==(ECL_SYM("C-INLINE",1973)))) { goto L12; }
   T0 = ecl_cddddr(v1loc);
   T1 = ecl_car(T0);
   value0 = Null(T1)?ECL_T:ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L12:;
   value0 = ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for LOC-TYPE                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L15loc_type(cl_object v1loc)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!((v1loc)==(ECL_NIL))) { goto L1; }
  value0 = ECL_SYM("NULL",605);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (Null(ecl_function_dispatch(cl_env_copy,VV[107])(1, v1loc) /*  VAR-P */)) { goto L3; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[108])(1, v1loc) /*  VAR-TYPE */;
  return value0;
L3:;
  if (Null(ecl_function_dispatch(cl_env_copy,VV[109])(1, v1loc) /*  VV-P */)) { goto L5; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[110])(1, v1loc) /*  VV-TYPE */;
  return value0;
L5:;
  if (!(ECL_FIXNUMP(v1loc))) { goto L7; }
  value0 = ECL_SYM("FIXNUM",372);
  cl_env_copy->nvalues = 1;
  return value0;
L7:;
  if (!(ECL_ATOM(v1loc))) { goto L9; }
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
L9:;
  {
   cl_object v2;
   v2 = ecl_car(v1loc);
   if (!((v2)==(VV[32]))) { goto L12; }
   value0 = ECL_SYM("FIXNUM",372);
   cl_env_copy->nvalues = 1;
   return value0;
L12:;
   if (!((v2)==(VV[33]))) { goto L14; }
   T0 = ecl_cadr(v1loc);
   T1 = cl_code_char(T0);
   value0 = cl_type_of(T1);
   return value0;
L14:;
   if (!((v2)==(VV[20]))) { goto L16; }
   value0 = ECL_SYM("DOUBLE-FLOAT",315);
   cl_env_copy->nvalues = 1;
   return value0;
L16:;
   if (!((v2)==(VV[18]))) { goto L18; }
   value0 = ECL_SYM("SINGLE-FLOAT",778);
   cl_env_copy->nvalues = 1;
   return value0;
L18:;
   if (!((v2)==(VV[22]))) { goto L20; }
   value0 = ECL_SYM("LONG-FLOAT",508);
   cl_env_copy->nvalues = 1;
   return value0;
L20:;
   if (!((v2)==(ECL_SYM("C-INLINE",1973)))) { goto L22; }
   {
    cl_object v3type;
    T0 = ecl_cadr(v1loc);
    v3type = ecl_car(T0);
    if (!(ECL_CONSP(v3type))) { goto L25; }
    T0 = ecl_car(v3type);
    if (!((T0)==(ECL_SYM("VALUES",895)))) { goto L25; }
    value0 = ECL_T;
    cl_env_copy->nvalues = 1;
    return value0;
L25:;
    if (Null(L11lisp_type_p(v3type))) { goto L28; }
    value0 = v3type;
    cl_env_copy->nvalues = 1;
    return value0;
L28:;
    value0 = L8rep_type__lisp_type(v3type);
    return value0;
   }
L22:;
   if (!((v2)==(VV[34]))) { goto L30; }
   T0 = ecl_cadr(v1loc);
   value0 = ecl_function_dispatch(cl_env_copy,VV[108])(1, T0) /*  VAR-TYPE */;
   return value0;
L30:;
   if (!((v2)==(VV[35]))) { goto L32; }
   value0 = ecl_caddr(v1loc);
   if ((value0)!=ECL_NIL) { goto L35; }
   value0 = ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
L35:;
   cl_env_copy->nvalues = 1;
   return value0;
L32:;
   if (!((v2)==(ECL_SYM("THE",856)))) { goto L37; }
   value0 = ecl_cadr(v1loc);
   cl_env_copy->nvalues = 1;
   return value0;
L37:;
   if (!((v2)==(VV[36]))) { goto L39; }
   value0 = ecl_cadddr(v1loc);
   cl_env_copy->nvalues = 1;
   return value0;
L39:;
   value0 = ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for LOC-REPRESENTATION-TYPE               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L16loc_representation_type(cl_object v1loc)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!((v1loc)==(ECL_NIL))) { goto L6; }
  goto L3;
  goto L4;
L6:;
  goto L4;
L4:;
  if (!(ecl_eql(v1loc,ECL_T))) { goto L1; }
  goto L2;
L3:;
L2:;
  value0 = ECL_SYM("OBJECT",1278);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (Null(ecl_function_dispatch(cl_env_copy,VV[107])(1, v1loc) /*  VAR-P */)) { goto L9; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, v1loc) /*  VAR-REP-TYPE */;
  return value0;
L9:;
  if (Null(ecl_function_dispatch(cl_env_copy,VV[109])(1, v1loc) /*  VV-P */)) { goto L11; }
  value0 = ECL_SYM("OBJECT",1278);
  cl_env_copy->nvalues = 1;
  return value0;
L11:;
  if (!(ECL_FIXNUMP(v1loc))) { goto L13; }
  value0 = ECL_SYM("FIXNUM",1367);
  cl_env_copy->nvalues = 1;
  return value0;
L13:;
  if (!((v1loc)==(VV[40]))) { goto L15; }
  value0 = ECL_SYM("VOID",1381);
  cl_env_copy->nvalues = 1;
  return value0;
L15:;
  if (!(ECL_ATOM(v1loc))) { goto L17; }
  value0 = ECL_SYM("OBJECT",1278);
  cl_env_copy->nvalues = 1;
  return value0;
L17:;
  {
   cl_object v2;
   v2 = ecl_car(v1loc);
   if (!((v2)==(VV[32]))) { goto L20; }
   value0 = ECL_SYM("FIXNUM",1367);
   cl_env_copy->nvalues = 1;
   return value0;
L20:;
   if (!((v2)==(VV[33]))) { goto L22; }
   T0 = ecl_cadr(v1loc);
   if (!(ecl_number_compare(T0,ecl_make_fixnum(255))<=0)) { goto L24; }
   value0 = ECL_SYM("UNSIGNED-CHAR",1387);
   cl_env_copy->nvalues = 1;
   return value0;
L24:;
   value0 = VV[41];
   cl_env_copy->nvalues = 1;
   return value0;
L22:;
   if (!((v2)==(VV[20]))) { goto L26; }
   value0 = ECL_SYM("DOUBLE",1366);
   cl_env_copy->nvalues = 1;
   return value0;
L26:;
   if (!((v2)==(VV[18]))) { goto L28; }
   value0 = ECL_SYM("FLOAT",1368);
   cl_env_copy->nvalues = 1;
   return value0;
L28:;
   if (!((v2)==(VV[22]))) { goto L30; }
   value0 = VV[42];
   cl_env_copy->nvalues = 1;
   return value0;
L30:;
   if (!((v2)==(ECL_SYM("C-INLINE",1973)))) { goto L32; }
   {
    cl_object v3type;
    T0 = ecl_cadr(v1loc);
    v3type = ecl_car(T0);
    if (!(ECL_CONSP(v3type))) { goto L35; }
    T0 = ecl_car(v3type);
    if (!((T0)==(ECL_SYM("VALUES",895)))) { goto L35; }
    value0 = ECL_SYM("OBJECT",1278);
    cl_env_copy->nvalues = 1;
    return value0;
L35:;
    if (Null(L11lisp_type_p(v3type))) { goto L38; }
    value0 = L9lisp_type__rep_type(v3type);
    return value0;
L38:;
    value0 = v3type;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L32:;
   if (!((v2)==(VV[34]))) { goto L40; }
   T0 = ecl_cadr(v1loc);
   value0 = ecl_function_dispatch(cl_env_copy,VV[112])(1, T0) /*  VAR-REP-TYPE */;
   return value0;
L40:;
   if (!((v2)==(VV[35]))) { goto L42; }
   value0 = ecl_caddr(v1loc);
   if ((value0)!=ECL_NIL) { goto L46; }
   T0 = ECL_T;
   goto L44;
L46:;
   T0 = value0;
   goto L44;
L44:;
   value0 = L9lisp_type__rep_type(T0);
   return value0;
L42:;
   if (!((v2)==(VV[43]))) { goto L53; }
   goto L50;
   goto L51;
L53:;
   goto L51;
L51:;
   if (!((v2)==(VV[45]))) { goto L48; }
   goto L49;
L50:;
L49:;
   value0 = VV[47];
   cl_env_copy->nvalues = 1;
   return value0;
L48:;
   if (!((v2)==(ECL_SYM("THE",856)))) { goto L56; }
   v1loc = ecl_caddr(v1loc);
   goto TTL;
L56:;
   value0 = ECL_SYM("OBJECT",1278);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for WT-COERCE-LOC                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L19wt_coerce_loc(cl_object v1dest_rep_type, cl_object v2loc)
{
 cl_object T0;
 volatile cl_object lex0[4];
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  lex0[0] = v1dest_rep_type;                      /*  DEST-REP-TYPE   */
TTL:
  lex0[0] = L9lisp_type__rep_type(lex0[0]);
  T0 = L8rep_type__lisp_type(lex0[0]);
  lex0[1] = T0;                                   /*  DEST-TYPE       */
  T0 = L15loc_type(v2loc);
  lex0[2] = T0;                                   /*  LOC-TYPE        */
  T0 = L16loc_representation_type(v2loc);
  lex0[3] = T0;                                   /*  LOC-REP-TYPE    */
  if (!((lex0[0])==(lex0[3]))) { goto L3; }
  ecl_function_dispatch(cl_env_copy,VV[102])(1, v2loc) /*  WT         */;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L3:;
  if (Null(ecl_memql(lex0[0],VV[7]))) { goto L6; }
  if (Null(ecl_memql(lex0[3],VV[5]))) { goto L8; }
  T0 = L10rep_type_name(lex0[0]);
  value0 = ecl_function_dispatch(cl_env_copy,VV[102])(5, _ecl_static_5, T0, _ecl_static_9, v2loc, _ecl_static_6) /*  WT */;
  return value0;
L8:;
  if (!(ecl_eql(lex0[3],ECL_SYM("OBJECT",1278)))) { goto L10; }
  LC18ensure_valid_object_type(lex0, lex0[1]);
  value0 = L13wt_from_object_conversion(lex0[1], lex0[2], lex0[0], v2loc);
  return value0;
L10:;
  value0 = LC17coercion_error(lex0);
  return value0;
L6:;
  if (!(ecl_eql(lex0[0],ECL_SYM("CHAR",1364)))) { goto L19; }
  goto L16;
  goto L17;
L19:;
  goto L17;
L17:;
  if (!(ecl_eql(lex0[0],ECL_SYM("UNSIGNED-CHAR",1387)))) { goto L23; }
  goto L16;
  goto L21;
L23:;
  goto L21;
L21:;
  if (!(ecl_eql(lex0[0],VV[41]))) { goto L14; }
  goto L15;
L16:;
L15:;
  if (!(ecl_eql(lex0[3],ECL_SYM("CHAR",1364)))) { goto L31; }
  goto L28;
  goto L29;
L31:;
  goto L29;
L29:;
  if (!(ecl_eql(lex0[3],ECL_SYM("UNSIGNED-CHAR",1387)))) { goto L35; }
  goto L28;
  goto L33;
L35:;
  goto L33;
L33:;
  if (!(ecl_eql(lex0[3],VV[41]))) { goto L26; }
  goto L27;
L28:;
L27:;
  T0 = L10rep_type_name(lex0[0]);
  value0 = ecl_function_dispatch(cl_env_copy,VV[102])(5, _ecl_static_5, T0, _ecl_static_9, v2loc, _ecl_static_6) /*  WT */;
  return value0;
L26:;
  if (!(ecl_eql(lex0[3],ECL_SYM("OBJECT",1278)))) { goto L38; }
  LC18ensure_valid_object_type(lex0, lex0[1]);
  value0 = L13wt_from_object_conversion(lex0[1], lex0[2], lex0[0], v2loc);
  return value0;
L38:;
  value0 = LC17coercion_error(lex0);
  return value0;
L14:;
  if (!(ecl_eql(lex0[0],ECL_SYM("FLOAT",1368)))) { goto L47; }
  goto L44;
  goto L45;
L47:;
  goto L45;
L45:;
  if (!(ecl_eql(lex0[0],ECL_SYM("DOUBLE",1366)))) { goto L51; }
  goto L44;
  goto L49;
L51:;
  goto L49;
L49:;
  if (!(ecl_eql(lex0[0],VV[42]))) { goto L42; }
  goto L43;
L44:;
L43:;
  if (Null(ecl_memql(lex0[3],VV[5]))) { goto L54; }
  T0 = L10rep_type_name(lex0[0]);
  value0 = ecl_function_dispatch(cl_env_copy,VV[102])(5, _ecl_static_5, T0, _ecl_static_9, v2loc, _ecl_static_6) /*  WT */;
  return value0;
L54:;
  if (!(ecl_eql(lex0[3],ECL_SYM("OBJECT",1278)))) { goto L56; }
  LC18ensure_valid_object_type(lex0, ECL_SYM("FLOAT",374));
  value0 = L13wt_from_object_conversion(lex0[1], lex0[2], lex0[0], v2loc);
  return value0;
L56:;
  value0 = LC17coercion_error(lex0);
  return value0;
L42:;
  if (!(ecl_eql(lex0[0],VV[47]))) { goto L60; }
  if (Null(ecl_memql(lex0[3],VV[5]))) { goto L63; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[102])(1, _ecl_static_10) /*  WT */;
  return value0;
L63:;
  if (!(ecl_eql(lex0[3],ECL_SYM("OBJECT",1278)))) { goto L65; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[102])(3, _ecl_static_5, v2loc, _ecl_static_11) /*  WT */;
  return value0;
L65:;
  value0 = LC17coercion_error(lex0);
  return value0;
L60:;
  if (!(ecl_eql(lex0[0],ECL_SYM("OBJECT",1278)))) { goto L68; }
  value0 = L12wt_to_object_conversion(lex0[3], v2loc);
  return value0;
L68:;
  if (!(ecl_eql(lex0[0],ECL_SYM("POINTER-VOID",1377)))) { goto L71; }
  if (!(ecl_eql(lex0[3],ECL_SYM("OBJECT",1278)))) { goto L74; }
  value0 = L13wt_from_object_conversion(lex0[1], lex0[2], lex0[0], v2loc);
  return value0;
L74:;
  if (!(ecl_eql(lex0[3],ECL_SYM("CSTRING",1365)))) { goto L77; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[102])(3, _ecl_static_12, v2loc, _ecl_static_6) /*  WT */;
  return value0;
L77:;
  value0 = LC17coercion_error(lex0);
  return value0;
L71:;
  if (!(ecl_eql(lex0[0],ECL_SYM("CSTRING",1365)))) { goto L80; }
  value0 = LC17coercion_error(lex0);
  return value0;
L80:;
  if (!(ecl_eql(lex0[0],VV[59]))) { goto L83; }
  if (!(ecl_eql(lex0[3],ECL_SYM("OBJECT",1278)))) { goto L86; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[102])(3, _ecl_static_13, v2loc, _ecl_static_6) /*  WT */;
  return value0;
L86:;
  if (!(ecl_eql(lex0[3],ECL_SYM("POINTER-VOID",1377)))) { goto L89; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[102])(3, _ecl_static_12, v2loc, _ecl_static_6) /*  WT */;
  return value0;
L89:;
  value0 = LC17coercion_error(lex0);
  return value0;
L83:;
  value0 = LC17coercion_error(lex0);
  return value0;
 }
}
/*	local function ENSURE-VALID-OBJECT-TYPE                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC18ensure_valid_object_type(volatile cl_object *lex0, cl_object v1a_lisp_type)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(3, ECL_SYM("AND",87), lex0[2], v1a_lisp_type);
  if (Null(cl_subtypep(2, T0, ECL_NIL))) { goto L1; }
  value0 = LC17coercion_error(lex0);
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function COERCION-ERROR                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC17coercion_error(volatile cl_object *lex0)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[114])(5, _ecl_static_8, lex0[2], lex0[3], lex0[1], lex0[0]) /*  CMPWARN */;
  return value0;
 }
}
/*	function definition for C1CLINES                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L20c1clines(cl_object v1args)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = (ECL_SYM("STRINGP",825)->symbol.gfdef);
  if ((cl_every(2, T0, v1args))!=ECL_NIL) { goto L1; }
  ecl_function_dispatch(cl_env_copy,VV[97])(2, _ecl_static_14, v1args) /*  CMPERR */;
L1:;
  T0 = cl_copy_list(v1args);
  cl_set(VV[62],ecl_nconc(ecl_symbol_value(VV[62]),T0));
  value0 = VV[63];
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for OUTPUT-CLINES                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L23output_clines(cl_object volatile v1output_stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   cl_object v3s;
   cl_object v4;
   v2 = ecl_symbol_value(VV[62]);
   v3s = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v2))) FEtype_error_list(v2);
   v4 = v2;
L6:;
   if (!(ecl_endp(v4))) { goto L8; }
   goto L7;
L8:;
   v3s = _ecl_car(v4);
   {
    cl_object v5;
    v5 = _ecl_cdr(v4);
    if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
    v4 = v5;
   }
   ecl_terpri(v1output_stream);
   {
    cl_object v5;
    v5 = si_make_seq_iterator(2, v3s, ecl_make_fixnum(0));
L21:;
    if ((v5)!=ECL_NIL) { goto L23; }
    goto L18;
L23:;
    {
     cl_object v6;
     v6 = si_seq_iterator_ref(v3s, v5);
     if (!((ECL_CODE_CHAR((ecl_character)(64))==(v6)))) { goto L25; }
     if (Null(v6)) { goto L18; }
     goto L19;
    }
L25:;
    v5 = si_seq_iterator_next(v3s, v5);
    goto L21;
   }
L19:;
   LC22parse_one_string(v3s, v1output_stream);
   goto L17;
L18:;
   cl_write_string(2, v3s, v1output_stream);
L17:;
   goto L6;
L7:;
  }
  ecl_terpri(v1output_stream);
  cl_set(VV[62],ECL_NIL);
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function PARSE-ONE-STRING                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC22parse_one_string(cl_object volatile v1s, cl_object volatile v2output_stream)
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
   volatile cl_object v3stream;
   v3stream = cl_make_string_input_stream(3, v1s, ecl_make_fixnum(0), ECL_NIL);
   {
    volatile cl_object v4c;
    v4c = ECL_NIL;
L3:;
    v4c = cl_read_char(3, v3stream, ECL_NIL, ECL_NIL);
    if ((v4c)!=ECL_NIL) { goto L7; }
    goto L4;
L7:;
    if (!((v4c)==(CODE_CHAR(64)))) { goto L10; }
    {
     volatile cl_object v5object;
     {
      volatile cl_object env1 = env0;
      env1 = ECL_NIL;
      CLV0 = env1 = CONS(ECL_NIL,env1);
      {
       volatile cl_object env2 = env1;
       CLV1 = env2 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env2); /*  TAGBODY */
       if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV1))) {
       if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L13;
       ecl_internal_error("GO found an inexistent tag");
       }
       {cl_object v6;
        v6 = ECL_NIL;
        v6 = ecl_make_cclosure_va((cl_objectfn)LC21__g46,env2,Cblock);
        T0 = v6;
       }
       T1 = CONS(ECL_SYM("SERIOUS-CONDITION",742),T0);
       T2 = ecl_list1(T1);
       T3 = CONS(T2,ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5)));
       ecl_bds_bind(cl_env_copy,ECL_SYM("*HANDLER-CLUSTERS*",5),T3); /*  *HANDLER-CLUSTERS* */
       value0 = cl_read(1, v3stream);
       ecl_frs_pop(cl_env_copy);
       v5object = value0;
       ecl_bds_unwind1(cl_env_copy);
       goto L12;
L13:;
       value0 = ecl_function_dispatch(cl_env_copy,VV[97])(2, _ecl_static_15, v1s) /*  CMPERR */;
       ecl_frs_pop(cl_env_copy);
       v5object = value0;
       goto L12;
      }
     }
L12:;
     ecl_bds_bind(cl_env_copy,VV[65],v2output_stream); /*  *COMPILER-OUTPUT1* */
     T0 = ecl_function_dispatch(cl_env_copy,VV[117])(3, v5object, VV[66], ECL_T) /*  ADD-OBJECT */;
     ecl_function_dispatch(cl_env_copy,VV[102])(1, T0) /*  WT         */;
     ecl_bds_unwind1(cl_env_copy);
     goto L9;
    }
L10:;
    cl_write_char(2, v4c, v2output_stream);
L9:;
    goto L3;
L4:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	closure G46                                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC21__g46(cl_narg narg, cl_object v1si__temp, ...)
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
/*	function definition for C1C-INLINE                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L25c1c_inline(cl_object v1args)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   cl_object v3arguments;
   cl_object v4arg_types;
   cl_object v5output_type;
   cl_object v6c_expression;
   cl_object v7;
   cl_object v8side_effects;
   cl_object v9;
   cl_object v10one_liner;
   cl_object v11output_rep_type;
   v2 = v1args;
   if (!(v2==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1args);
L3:;
   {
    cl_object v12;
    v12 = ecl_car(v2);
    v2 = ecl_cdr(v2);
    v3arguments = v12;
   }
   if (!(v2==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1args);
L9:;
   {
    cl_object v12;
    v12 = ecl_car(v2);
    v2 = ecl_cdr(v2);
    v4arg_types = v12;
   }
   if (!(v2==ECL_NIL)) { goto L15; }
   si_dm_too_few_arguments(v1args);
L15:;
   {
    cl_object v12;
    v12 = ecl_car(v2);
    v2 = ecl_cdr(v2);
    v5output_type = v12;
   }
   if (!(v2==ECL_NIL)) { goto L21; }
   si_dm_too_few_arguments(v1args);
L21:;
   {
    cl_object v12;
    v12 = ecl_car(v2);
    v2 = ecl_cdr(v2);
    v6c_expression = v12;
   }
   v7 = si_search_keyword(2, v2, VV[68]);
   if (!((v7)==(ECL_SYM("MISSING-KEYWORD",1929)))) { goto L28; }
   v8side_effects = ECL_T;
   goto L27;
L28:;
   v8side_effects = v7;
L27:;
   v9 = si_search_keyword(2, v2, VV[69]);
   if (!((v9)==(ECL_SYM("MISSING-KEYWORD",1929)))) { goto L32; }
   v10one_liner = ECL_NIL;
   goto L31;
L32:;
   v10one_liner = v9;
L31:;
   v11output_rep_type = ECL_NIL;
   si_check_keyword(2, v2, VV[70]);
   {
    cl_fixnum v12;
    v12 = ecl_length(v3arguments);
    {
     cl_fixnum v13;
     v13 = ecl_length(v4arg_types);
     if ((v12)==(v13)) { goto L36; }
    }
   }
   T0 = CONS(ECL_SYM("C-INLINE",1973),v1args);
   ecl_function_dispatch(cl_env_copy,VV[97])(2, _ecl_static_16, T0) /*  CMPERR */;
L36:;
   {
    cl_object v12ndx;
    v12ndx = cl_position(2, ECL_SYM("CSTRING",1365), v4arg_types);
    if (Null(v12ndx)) { goto L38; }
    {
     cl_object v13var;
     cl_object v14arguments;
     cl_object v15value;
     v13var = cl_gensym(0);
     v14arguments = cl_copy_list(v3arguments);
     v15value = ecl_elt(v14arguments,ecl_fixnum(v12ndx));
     ecl_elt_set(v14arguments,ecl_to_size(v12ndx),v13var);
     ecl_elt_set(v4arg_types,ecl_to_size(v12ndx),VV[59]);
     T0 = cl_list(2, v13var, v15value);
     T1 = cl_listX(6, ECL_SYM("C-INLINE",1973), v14arguments, v4arg_types, v5output_type, v6c_expression, v2);
     T2 = cl_list(3, ECL_SYM("WITH-CSTRING",2019), T0, T1);
     value0 = ecl_function_dispatch(cl_env_copy,VV[119])(1, T2) /*  C1EXPR */;
     return value0;
    }
   }
L38:;
   if (!((v5output_type)==(ECL_SYM("VOID",1381)))) { goto L47; }
   v11output_rep_type = ECL_NIL;
   v5output_type = ECL_NIL;
   goto L46;
L47:;
   if (!(ecl_equal(v5output_type,VV[71]))) { goto L52; }
   v11output_rep_type = VV[72];
   goto L46;
L52:;
   if (!(ECL_CONSP(v5output_type))) { goto L55; }
   T0 = ecl_car(v5output_type);
   if (!((T0)==(ECL_SYM("VALUES",895)))) { goto L55; }
   {
    cl_object v12x;
    {
     cl_object v13;
     cl_object v14;
     cl_object v15;
     v13 = ecl_cdr(v5output_type);
     v14 = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v13))) FEtype_error_list(v13);
     v15 = v13;
     {
      cl_object v16;
      cl_object v17;
      v16 = ecl_list1(ECL_NIL);
      v17 = v16;
L65:;
      if (!(ecl_endp(v15))) { goto L67; }
      goto L66;
L67:;
      v14 = _ecl_car(v15);
      {
       cl_object v18;
       v18 = _ecl_cdr(v15);
       if (ecl_unlikely(!ECL_LISTP(v18))) FEtype_error_list(v18);
       v15 = v18;
      }
      if (ecl_unlikely(ECL_ATOM(v17))) FEtype_error_cons(v17);
      T0 = v17;
      T1 = LC24produce_type_pair(v14);
      v17 = ecl_list1(T1);
      (ECL_CONS_CDR(T0)=v17,T0);
      goto L65;
L66:;
      v12x = ecl_cdr(v16);
      goto L58;
     }
    }
L58:;
    {
     cl_object v13;
     cl_object v14;
     v13 = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v12x))) FEtype_error_list(v12x);
     v14 = v12x;
     {
      cl_object v15;
      cl_object v16;
      v15 = ecl_list1(ECL_NIL);
      v16 = v15;
L89:;
      if (!(ecl_endp(v14))) { goto L91; }
      goto L90;
L91:;
      v13 = _ecl_car(v14);
      {
       cl_object v17;
       v17 = _ecl_cdr(v14);
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       v14 = v17;
      }
      if (ecl_unlikely(ECL_ATOM(v16))) FEtype_error_cons(v16);
      T0 = v16;
      T1 = ecl_cdr(v13);
      v16 = ecl_list1(T1);
      (ECL_CONS_CDR(T0)=v16,T0);
      goto L89;
L90:;
      v11output_rep_type = ecl_cdr(v15);
      goto L83;
     }
    }
L83:;
    {
     cl_object v13;
     cl_object v14;
     v13 = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v12x))) FEtype_error_list(v12x);
     v14 = v12x;
     {
      cl_object v15;
      cl_object v16;
      v15 = ecl_list1(ECL_NIL);
      v16 = v15;
L112:;
      if (!(ecl_endp(v14))) { goto L114; }
      goto L113;
L114:;
      v13 = _ecl_car(v14);
      {
       cl_object v17;
       v17 = _ecl_cdr(v14);
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       v14 = v17;
      }
      if (ecl_unlikely(ECL_ATOM(v16))) FEtype_error_cons(v16);
      T1 = v16;
      T2 = ecl_car(v13);
      v16 = ecl_list1(T2);
      (ECL_CONS_CDR(T1)=v16,T1);
      goto L112;
L113:;
      T0 = ecl_cdr(v15);
      goto L106;
     }
    }
L106:;
    v5output_type = CONS(ECL_SYM("VALUES",895),T0);
    goto L46;
   }
L55:;
   {
    cl_object v13x;
    v13x = LC24produce_type_pair(v5output_type);
    v5output_type = ecl_car(v13x);
    T0 = ecl_cdr(v13x);
    v11output_rep_type = ecl_list1(T0);
   }
L46:;
   if (!(ECL_LISTP(v3arguments))) { goto L135; }
   if (!(ECL_LISTP(v4arg_types))) { goto L135; }
   if (ECL_STRINGP(v6c_expression)) { goto L132; }
   goto L133;
L135:;
   goto L133;
L133:;
   T0 = CONS(ECL_SYM("C-INLINE",1973),v1args);
   ecl_function_dispatch(cl_env_copy,VV[97])(2, _ecl_static_17, T0) /*  CMPERR */;
L132:;
   {
    cl_object v12processed_arguments;
    cl_object v13processed_arg_types;
    v12processed_arguments = ECL_NIL;
    v13processed_arg_types = ECL_NIL;
    goto L142;
L141:;
    {
     cl_object v14;
     v14 = v4arg_types;
     if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
     if (Null(v14)) { goto L153; }
     {
      cl_object v15;
      v15 = ECL_CONS_CDR(v14);
      v4arg_types = v15;
      v14 = ECL_CONS_CAR(v14);
     }
L153:;
     value0 = v14;
    }
    if ((value0)!=ECL_NIL) { goto L148; }
    T0 = ECL_T;
    goto L146;
L148:;
    T0 = value0;
    goto L146;
L146:;
    v13processed_arg_types = CONS(T0,v13processed_arg_types);
    {
     cl_object v14;
     v14 = v3arguments;
     if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
     if (Null(v14)) { goto L165; }
     {
      cl_object v15;
      v15 = ECL_CONS_CDR(v14);
      v3arguments = v15;
      v14 = ECL_CONS_CAR(v14);
     }
L165:;
     T0 = v14;
    }
    T1 = ecl_function_dispatch(cl_env_copy,VV[119])(1, T0) /*  C1EXPR */;
    v12processed_arguments = CONS(T1,v12processed_arguments);
L142:;
    if (!(ecl_endp(v3arguments))) { goto L174; }
    if (ecl_endp(v4arg_types)) { goto L171; }
    goto L172;
L174:;
    goto L172;
L172:;
    goto L141;
L171:;
    T0 = cl_nreverse(v12processed_arguments);
    T1 = cl_nreverse(v13processed_arg_types);
    value0 = ecl_function_dispatch(cl_env_copy,VV[120])(12, ECL_SYM("C-INLINE",1973), ECL_SYM("TYPE",1318), v5output_type, VV[68], v8side_effects, VV[73], T0, T1, v11output_rep_type, v6c_expression, v8side_effects, v10one_liner) /*  MAKE-C1FORM* */;
    return value0;
   }
  }
 }
}
/*	local function PRODUCE-TYPE-PAIR                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC24produce_type_pair(cl_object v1type)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(L11lisp_type_p(v1type))) { goto L1; }
  T0 = L9lisp_type__rep_type(v1type);
  value0 = CONS(v1type,T0);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  T0 = L8rep_type__lisp_type(v1type);
  value0 = CONS(T0,v1type);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for PRODUCE-INLINE-LOC                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L27produce_inline_loc(cl_object v1inlined_arguments, cl_object v2arg_types, cl_object v3output_rep_type, cl_object v4c_expression, cl_object v5side_effects, cl_object v6one_liner)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v7args_to_be_saved;
   cl_object v8coerced_arguments;
   v7args_to_be_saved = ECL_NIL;
   v8coerced_arguments = ECL_NIL;
   {
    cl_fixnum v9;
    v9 = ecl_length(v4c_expression);
    if (!((v9)>(1))) { goto L3; }
   }
   {
    ecl_character v9;
    v9 = ecl_char(v4c_expression,0);
    if (!((CODE_CHAR(v9))==(CODE_CHAR(64)))) { goto L3; }
   }
   {
    cl_object v9ndx;
    v9ndx = ecl_make_fixnum(1);
    goto L9;
L8:;
    {
     ecl_character v10c;
     v10c = CHAR_CODE(cl_char(v4c_expression, v9ndx));
     if (!((CODE_CHAR(v10c))==(CODE_CHAR(59)))) { goto L13; }
     T0 = ecl_one_plus(v9ndx);
     v4c_expression = cl_subseq(2, v4c_expression, T0);
     goto L3;
L13:;
     if (ecl_alphanumericp(v10c)) { goto L17; }
     v7args_to_be_saved = ECL_NIL;
     goto L3;
L17:;
     {
      cl_fixnum v11;
      v11 = v10c;
      {
       cl_fixnum v12;
       v12 = (ecl_character)(48);
       T0 = ecl_minus(ecl_make_fixnum(v11),ecl_make_fixnum(v12));
       v7args_to_be_saved = CONS(T0,v7args_to_be_saved);
      }
     }
    }
    v9ndx = ecl_one_plus(v9ndx);
L9:;
    {
     cl_fixnum v10;
     v10 = ecl_length(v4c_expression);
     if (ecl_number_compare(v9ndx,ecl_make_fixnum(v10))>=0) { goto L24; }
    }
    goto L8;
L24:;
   }
L3:;
   v8coerced_arguments = L29coerce_locs(3, v1inlined_arguments, v2arg_types, v7args_to_be_saved);
   if (!(v3output_rep_type==ECL_NIL)) { goto L28; }
   if (Null(v5side_effects)) { goto L31; }
   ecl_function_dispatch(cl_env_copy,VV[122])(0)  /*  WT-NL           */;
   L30wt_c_inline_loc(v3output_rep_type, v4c_expression, v8coerced_arguments, ECL_T, ECL_NIL);
   if (Null(v6one_liner)) { goto L30; }
   ecl_function_dispatch(cl_env_copy,VV[102])(1, _ecl_static_18) /*  WT */;
   goto L30;
L31:;
   ecl_function_dispatch(cl_env_copy,VV[123])(2, _ecl_static_19, v4c_expression) /*  CMPNOTE */;
L30:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L28:;
   if (Null(v6one_liner)) { goto L36; }
   if (!(ecl_equalp(v3output_rep_type,VV[72]))) { goto L39; }
   T0 = ECL_SYM("VALUES",895);
   goto L38;
L39:;
   T0 = ECL_NIL;
L38:;
   value0 = cl_list(6, ECL_SYM("C-INLINE",1973), v3output_rep_type, v4c_expression, v8coerced_arguments, v5side_effects, T0);
   return value0;
L36:;
   if (!(ecl_equalp(v3output_rep_type,VV[72]))) { goto L41; }
   L30wt_c_inline_loc(v3output_rep_type, v4c_expression, v8coerced_arguments, v5side_effects, ECL_SYM("VALUES",895));
   value0 = ECL_SYM("VALUES",895);
   cl_env_copy->nvalues = 1;
   return value0;
L41:;
   ecl_function_dispatch(cl_env_copy,VV[124])(0)  /*  OPEN-INLINE-BLOCK */;
   {
    cl_object v9output_vars;
    {
     cl_object v10;
     cl_object v11;
     v10 = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v3output_rep_type))) FEtype_error_list(v3output_rep_type);
     v11 = v3output_rep_type;
     {
      cl_object v12;
      cl_object v13;
      v12 = ecl_list1(ECL_NIL);
      v13 = v12;
L51:;
      if (!(ecl_endp(v11))) { goto L53; }
      goto L52;
L53:;
      v10 = _ecl_car(v11);
      {
       cl_object v14;
       v14 = _ecl_cdr(v11);
       if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
       v11 = v14;
      }
      if (ecl_unlikely(ECL_ATOM(v13))) FEtype_error_cons(v13);
      T0 = v13;
      T1 = LC26make_output_var(v10);
      v13 = ecl_list1(T1);
      (ECL_CONS_CDR(T0)=v13,T0);
      goto L51;
L52:;
      v9output_vars = ecl_cdr(v12);
      goto L45;
     }
    }
L45:;
    L30wt_c_inline_loc(v3output_rep_type, v4c_expression, v8coerced_arguments, v5side_effects, v9output_vars);
    {
     cl_fixnum v10;
     v10 = ecl_length(v9output_vars);
     if (!((v10)==(1))) { goto L69; }
    }
    value0 = ecl_car(v9output_vars);
    cl_env_copy->nvalues = 1;
    return value0;
L69:;
    {
     cl_object v10v;
     cl_object v11;
     v10v = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v9output_vars))) FEtype_error_list(v9output_vars);
     v11 = v9output_vars;
     {
      cl_object v12i;
      v12i = ecl_make_fixnum(0);
      if (!(ecl_endp(v11))) { goto L78; }
      goto L77;
L78:;
      v10v = _ecl_car(v11);
      {
       cl_object v13;
       v13 = _ecl_cdr(v11);
       if (ecl_unlikely(!ECL_LISTP(v13))) FEtype_error_list(v13);
       v11 = v13;
      }
L76:;
      T0 = cl_list(2, VV[77], v12i);
      ecl_bds_bind(cl_env_copy,VV[76],T0);        /*  *DESTINATION*   */
      ecl_function_dispatch(cl_env_copy,VV[125])(1, v10v) /*  SET-LOC */;
      ecl_bds_unwind1(cl_env_copy);
      if (!(ecl_endp(v11))) { goto L87; }
      goto L77;
L87:;
      v10v = _ecl_car(v11);
      {
       cl_object v13;
       v13 = _ecl_cdr(v11);
       if (ecl_unlikely(!ECL_LISTP(v13))) FEtype_error_list(v13);
       v11 = v13;
      }
      v12i = ecl_one_plus(v12i);
      goto L76;
L77:;
     }
    }
    {
     cl_fixnum v10;
     v10 = ecl_length(v9output_vars);
     ecl_function_dispatch(cl_env_copy,VV[102])(3, _ecl_static_21, ecl_make_fixnum(v10), _ecl_static_18) /*  WT */;
    }
    value0 = ECL_SYM("VALUES",895);
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	local function MAKE-OUTPUT-VAR                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC26make_output_var(cl_object v1type)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2var;
   v2var = ecl_function_dispatch(cl_env_copy,VV[126])(2, VV[75], v1type) /*  MAKE-LCL-VAR */;
   T0 = L10rep_type_name(v1type);
   ecl_function_dispatch(cl_env_copy,VV[122])(4, T0, _ecl_static_20, v2var, _ecl_static_18) /*  WT-NL */;
   value0 = v2var;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for C2C-INLINE                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L28c2c_inline(cl_narg narg, cl_object v1c1form, cl_object v2arguments, ...)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3rest;
  ecl_va_list args; ecl_va_start(args,v2arguments,narg,2);
  v3rest = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v4;
   v4 = ecl_symbol_value(VV[79]);
   ecl_bds_bind(cl_env_copy,VV[80],ecl_make_fixnum(0)); /*  *INLINE-BLOCKS* */
   ecl_bds_bind(cl_env_copy,VV[79],v4);           /*  *TEMP*          */
   T0 = ecl_fdefinition(VV[78]);
   T1 = ecl_function_dispatch(cl_env_copy,VV[128])(1, v2arguments) /*  INLINE-ARGS */;
   T2 = cl_apply(3, T0, T1, v3rest);
   ecl_function_dispatch(cl_env_copy,VV[129])(1, T2) /*  UNWIND-EXIT  */;
   value0 = ecl_function_dispatch(cl_env_copy,VV[130])(0) /*  CLOSE-INLINE-BLOCKS */;
   ecl_bds_unwind1(cl_env_copy);
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
 }
}
/*	function definition for COERCE-LOCS                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L29coerce_locs(cl_narg narg, cl_object v1inlined_args, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v2types;
  cl_object v3args_to_be_saved;
  va_list args; va_start(args,v1inlined_args);
  {
   int i = 1;
   if (i >= narg) {
    v2types = ECL_NIL;
   } else {
    i++;
    v2types = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v3args_to_be_saved = ECL_NIL;
   } else {
    i++;
    v3args_to_be_saved = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v4l;
   cl_object v5item;
   cl_object v6i;
   v4l = v1inlined_args;
   v5item = ecl_car(v4l);
   v6i = ecl_make_fixnum(0);
   goto L8;
L7:;
   {
    cl_object v7type;
    cl_object v8rep_type;
    cl_object v9loc;
    if (Null(v2types)) { goto L12; }
    {
     cl_object v10;
     v10 = v2types;
     if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
     if (Null(v10)) { goto L17; }
     {
      cl_object v11;
      v11 = ECL_CONS_CDR(v10);
      v2types = v11;
      v10 = ECL_CONS_CAR(v10);
     }
L17:;
     v7type = v10;
     goto L11;
    }
L12:;
    v7type = ECL_SYM("OBJECT",1278);
L11:;
    v8rep_type = L9lisp_type__rep_type(v7type);
    v9loc = ecl_cadr(v5item);
    if ((L14loc_movable_p(v9loc))!=ECL_NIL) { goto L26; }
    if (Null(ecl_memql(v6i,v3args_to_be_saved))) { goto L26; }
    {
     cl_object v10lcl;
     v10lcl = ecl_function_dispatch(cl_env_copy,VV[126])(2, VV[75], v8rep_type) /*  MAKE-LCL-VAR */;
     ecl_function_dispatch(cl_env_copy,VV[122])(0) /*  WT-NL          */;
     ecl_function_dispatch(cl_env_copy,VV[124])(0) /*  OPEN-INLINE-BLOCK */;
     T0 = L10rep_type_name(v8rep_type);
     ecl_function_dispatch(cl_env_copy,VV[102])(4, T0, _ecl_static_20, v10lcl, _ecl_static_22) /*  WT */;
     L19wt_coerce_loc(v8rep_type, v9loc);
     ecl_function_dispatch(cl_env_copy,VV[102])(1, _ecl_static_18) /*  WT */;
     v9loc = v10lcl;
     goto L25;
    }
L26:;
    T0 = L16loc_representation_type(v9loc);
    if (ecl_equal(v8rep_type,T0)) { goto L25; }
    v9loc = cl_list(3, VV[82], v8rep_type, v9loc);
L25:;
    if (ecl_unlikely(ECL_ATOM(v4l))) FEtype_error_cons(v4l);
    T0 = v4l;
    (ECL_CONS_CAR(T0)=v9loc,T0);
   }
   v4l = ecl_cdr(v4l);
   v5item = ecl_car(v4l);
   v6i = ecl_one_plus(v6i);
L8:;
   if (ecl_endp(v4l)) { goto L48; }
   goto L7;
L48:;
   value0 = v1inlined_args;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for WT-C-INLINE-LOC                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L30wt_c_inline_loc(cl_object v1output_rep_type, cl_object v2c_expression, cl_object v3coerced_arguments, cl_object v4side_effects, cl_object v5output_vars)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v6s;
   v6s = cl_make_string_input_stream(3, v2c_expression, ecl_make_fixnum(0), ECL_NIL);
   if (Null(v5output_vars)) { goto L2; }
   if ((v5output_vars)==(ECL_SYM("VALUES",895))) { goto L2; }
   ecl_function_dispatch(cl_env_copy,VV[122])(0)  /*  WT-NL           */;
L2:;
   {
    cl_object v7c;
    v7c = cl_read_char(3, v6s, ECL_NIL, ECL_NIL);
    goto L8;
L7:;
    if (!(((v7c)==ECL_CODE_CHAR((ecl_character)(64))))) { goto L11; }
    {
     cl_object v8object;
     v8object = cl_read(1, v6s);
     if (!(ECL_CONSP(v8object))) { goto L14; }
     T0 = ecl_car(v8object);
     if (!(ecl_equal(T0,ECL_SYM("RETURN",724)))) { goto L14; }
     if (!((v5output_vars)==(ECL_SYM("VALUES",895)))) { goto L17; }
     ecl_function_dispatch(cl_env_copy,VV[97])(1, _ecl_static_23) /*  CMPERR */;
     goto L10;
L17:;
     {
      cl_object v9;
      cl_fixnum v10;
      value0 = ecl_cadr(v8object);
      if ((value0)!=ECL_NIL) { goto L21; }
      v9 = ecl_make_fixnum(0);
      goto L19;
L21:;
      v9 = value0;
      goto L19;
L19:;
      v10 = ecl_length(v5output_vars);
      if (!(ecl_number_compare(v9,ecl_make_fixnum(v10))<0)) { goto L24; }
      T0 = ecl_nth(ecl_to_size(v9),v5output_vars);
      ecl_function_dispatch(cl_env_copy,VV[102])(1, T0) /*  WT        */;
      goto L10;
L24:;
      ecl_function_dispatch(cl_env_copy,VV[97])(3, _ecl_static_24, v9, ecl_make_fixnum(v10)) /*  CMPERR */;
      goto L10;
     }
L14:;
     if (!(ECL_CONSP(v8object))) { goto L26; }
     T0 = ecl_car(v8object);
     if (!((T0)==(ECL_SYM("QUOTE",679)))) { goto L26; }
     v8object = ecl_cadr(v8object);
L26:;
     T0 = ecl_function_dispatch(cl_env_copy,VV[117])(3, v8object, VV[66], ECL_T) /*  ADD-OBJECT */;
     ecl_function_dispatch(cl_env_copy,VV[102])(1, T0) /*  WT         */;
     goto L10;
    }
L11:;
    if (!(((v7c)==ECL_CODE_CHAR((ecl_character)(35))))) { goto L30; }
    {
     cl_object v11k;
     cl_object v12next_char;
     cl_object v13index;
     v11k = cl_read_char(1, v6s);
     v12next_char = cl_peek_char(4, ECL_NIL, v6s, ECL_NIL, ECL_NIL);
     v13index = cl_digit_char_p(2, v11k, ecl_make_fixnum(36));
     if (!((v11k)==(CODE_CHAR(35)))) { goto L35; }
     ecl_function_dispatch(cl_env_copy,VV[102])(1, CODE_CHAR(35)) /*  WT */;
     goto L10;
L35:;
     if (v13index==ECL_NIL) { goto L39; }
     if (Null(v12next_char)) { goto L37; }
     if (Null(cl_alphanumericp(v12next_char))) { goto L37; }
     goto L38;
L39:;
L38:;
     ecl_function_dispatch(cl_env_copy,VV[102])(2, CODE_CHAR(35), v11k) /*  WT */;
     goto L10;
L37:;
     {
      cl_fixnum v14;
      v14 = ecl_length(v3coerced_arguments);
      if (!(ecl_number_compare(v13index,ecl_make_fixnum(v14))<0)) { goto L42; }
     }
     T0 = ecl_nth(ecl_to_size(v13index),v3coerced_arguments);
     ecl_function_dispatch(cl_env_copy,VV[102])(1, T0) /*  WT         */;
     goto L10;
L42:;
     ecl_function_dispatch(cl_env_copy,VV[97])(1, _ecl_static_25) /*  CMPERR */;
     goto L10;
    }
L30:;
    cl_write_char(2, v7c, ecl_symbol_value(VV[65]));
L10:;
    v7c = cl_read_char(3, v6s, ECL_NIL, ECL_NIL);
L8:;
    if (v7c==ECL_NIL) { goto L46; }
    goto L7;
L46:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for C-INLINE-SAFE-STRING                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L31c_inline_safe_string(cl_object v1constant_string)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2c;
   cl_object v3;
   cl_fixnum v4;
   cl_fixnum v5;
   v2c = ECL_NIL;
   if (ecl_unlikely(!ECL_VECTORP(v1constant_string))) FEtype_error_vector(v1constant_string);
   v3 = v1constant_string;
   v4 = 0;
   v5 = 0;
   {
    cl_object v6;
    cl_object v7;
    v6 = ecl_list1(ECL_NIL);
    v7 = v6;
    v5 = ecl_length(v3);
L9:;
    if (!((v4)>=(v5))) { goto L13; }
    goto L10;
L13:;
    {
     cl_fixnum v8;
     if (ecl_unlikely((v4)>=(v3)->vector.dim))
           FEwrong_index(ECL_NIL,v3,-1,ecl_make_fixnum(v4),(v3)->vector.dim);
     v8 = v4;
     v2c = ecl_aref_unsafe(v3,v8);
    }
    {
     cl_object v8;
     v8 = ecl_make_integer((v4)+1);
     {
      bool v9;
      v9 = ECL_FIXNUMP(v8);
      if (ecl_unlikely(!(v9)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v8);
     }
     v4 = ecl_fixnum(v8);
    }
    if (!(((v2c)==ECL_CODE_CHAR((ecl_character)(35))))) { goto L29; }
    goto L26;
    goto L27;
L29:;
    goto L27;
L27:;
    if (!(((v2c)==ECL_CODE_CHAR((ecl_character)(64))))) { goto L24; }
    goto L25;
L26:;
L25:;
    if (ecl_unlikely(ECL_ATOM(v7))) FEtype_error_cons(v7);
    T1 = v7;
    v7 = ecl_list1(v2c);
    (ECL_CONS_CDR(T1)=v7,T1);
L24:;
    if (ecl_unlikely(ECL_ATOM(v7))) FEtype_error_cons(v7);
    T1 = v7;
    v7 = ecl_list1(v2c);
    (ECL_CONS_CDR(T1)=v7,T1);
    goto L9;
L10:;
    T0 = ecl_cdr(v6);
    goto L1;
   }
  }
L1:;
  T1 = cl_concatenate(2, ECL_SYM("STRING",805), T0);
  value0 = ecl_function_dispatch(cl_env_copy,VV[134])(1, T1) /*  C-FILTERED-STRING */;
  return value0;
 }
}

#include "cmp/cmpffi.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclZoKaNPWJBKEq9_8jzTOE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPFFI.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclZoKaNPWJBKEq9_8jzTOE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 si_Xmake_constant(VV[0], VVtemp[0]);
 {
  cl_object T0, T1, T2;
 {
  cl_object v1;
  cl_object v2;
  cl_object v3;
  v1 = ecl_symbol_value(VV[0]);
  v2 = ECL_NIL;
  if (ecl_unlikely(!ECL_LISTP(v1))) FEtype_error_list(v1);
  v3 = v1;
  {
   cl_object v4;
   cl_object v5;
   v4 = ecl_list1(ECL_NIL);
   v5 = v4;
L14:;
   v2 = _ecl_car(v3);
   {
    cl_object v6;
    v6 = _ecl_cdr(v3);
    if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
    v3 = v6;
   }
   if (ecl_unlikely(ECL_ATOM(v5))) FEtype_error_cons(v5);
   T1 = v5;
   T2 = ecl_car(v2);
   v5 = ecl_list1(T2);
   (ECL_CONS_CDR(T1)=v5,T1);
   if (!(ecl_endp(v3))) { goto L26; }
   goto L15;
L26:;
   goto L14;
L15:;
   T0 = ecl_cdr(v4);
   goto L7;
  }
 }
L7:;
 si_Xmake_constant(VV[1], T0);
 }
 {
  cl_object T0;
 T0 = ecl_append(ecl_symbol_value(VV[1]),VVtemp[1]);
 si_Xmake_constant(VV[2], T0);
 }
 si_Xmake_constant(VV[3], VVtemp[2]);
 si_Xmake_special(VV[4]);
 {
  cl_object v1table;
  v1table = cl_make_hash_table(4, ECL_SYM("SIZE",1308), ecl_make_fixnum(128), ECL_SYM("TEST",1316), ECL_SYM("EQ",333));
  {
   cl_object v2record;
   v2record = ecl_symbol_value(VV[3]);
   {
    cl_object v3rep_type;
    v3rep_type = ECL_NIL;
    {
     cl_object v4information;
     v4information = ECL_NIL;
L48:;
     v3rep_type = ecl_car(v2record);
     v4information = ecl_cadr(v2record);
     si_hash_set(v3rep_type, v1table, v4information);
     v2record = ecl_cddr(v2record);
     if (!(ECL_ATOM(v2record))) { goto L57; }
     goto L49;
L57:;
     goto L48;
L49:;
     cl_set(VV[4],v1table);
     goto L43;
    }
   }
  }
 }
L43:;
 ecl_cmp_defun(VV[88]);                           /*  C-NUMBER-REP-TYPE-P */
 ecl_cmp_defun(VV[89]);                           /*  C-INTEGER-REP-TYPE-P */
 ecl_cmp_defun(VV[90]);                           /*  C-INTEGER-REP-TYPE-BITS */
 ecl_cmp_defun(VV[91]);                           /*  C-NUMBER-TYPE-P */
 ecl_cmp_defun(VV[92]);                           /*  C-INTEGER-TYPE-P */
 ecl_cmp_defun(VV[93]);                           /*  C-INTEGER-TYPE-BITS */
 ecl_cmp_defun(VV[95]);                           /*  REP-TYPE-RECORD */
 ecl_cmp_defun(VV[96]);                           /*  REP-TYPE->LISP-TYPE */
 ecl_cmp_defun(VV[98]);                           /*  LISP-TYPE->REP-TYPE */
 ecl_cmp_defun(VV[99]);                           /*  REP-TYPE-NAME   */
 ecl_cmp_defun(VV[100]);                          /*  LISP-TYPE-P     */
 ecl_cmp_defun(VV[101]);                          /*  WT-TO-OBJECT-CONVERSION */
 ecl_cmp_defun(VV[103]);                          /*  WT-FROM-OBJECT-CONVERSION */
 ecl_cmp_defun(VV[105]);                          /*  LOC-MOVABLE-P   */
 ecl_cmp_defun(VV[106]);                          /*  LOC-TYPE        */
 ecl_cmp_defun(VV[111]);                          /*  LOC-REPRESENTATION-TYPE */
 ecl_cmp_defun(VV[113]);                          /*  WT-COERCE-LOC   */
 ecl_cmp_defun(VV[115]);                          /*  C1CLINES        */
 ecl_cmp_defun(VV[116]);                          /*  OUTPUT-CLINES   */
 ecl_cmp_defun(VV[118]);                          /*  C1C-INLINE      */
 ecl_cmp_defun(VV[121]);                          /*  PRODUCE-INLINE-LOC */
 ecl_cmp_defun(VV[127]);                          /*  C2C-INLINE      */
 ecl_cmp_defun(VV[131]);                          /*  COERCE-LOCS     */
 ecl_cmp_defun(VV[132]);                          /*  WT-C-INLINE-LOC */
 ecl_cmp_defun(VV[133]);                          /*  C-INLINE-SAFE-STRING */
}
