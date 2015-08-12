/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPTYPE-ARITH.LSP                             */
#include <ecl/ecl-cmp.h>
#include "cmp/cmptype-arith.eclh"
/*	function definition for MEMBER-TYPE                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1member_type(cl_object v1type, cl_object v2disjoint_supertypes)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = v2disjoint_supertypes;
   goto L4;
L3:;
   {
    cl_object v4;
    cl_object v5;
    if (ecl_unlikely(ECL_ATOM(v3))) FEtype_error_cons(v3);
    v4 = v3;
    v5 = ECL_CONS_CAR(v4);
    if (Null(cl_subtypep(2, v1type, v5))) { goto L6; }
    value0 = v4;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L6:;
   v3 = ECL_CONS_CDR(v3);
L4:;
   if (v3==ECL_NIL) { goto L13; }
   goto L3;
L13:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for OBJECT-TYPE                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2object_type(cl_object v1thing)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2type;
   if (Null(v1thing)) { goto L2; }
   v2type = cl_type_of(v1thing);
   goto L1;
L2:;
   v2type = ECL_SYM("SYMBOL",840);
L1:;
   if (Null(ecl_memql(v2type,VV[2]))) { goto L4; }
   value0 = v2type;
   cl_env_copy->nvalues = 1;
   return value0;
L4:;
   if (!((v2type)==(ECL_SYM("BASE-CHAR",120)))) { goto L11; }
   goto L8;
   goto L9;
L11:;
   goto L9;
L9:;
   if (!((v2type)==(ECL_SYM("STANDARD-CHAR",794)))) { goto L15; }
   goto L8;
   goto L13;
L15:;
   goto L13;
L13:;
   if (!((v2type)==(ECL_SYM("CHARACTER",222)))) { goto L19; }
   goto L8;
   goto L17;
L19:;
   goto L17;
L17:;
   if (!((v2type)==(ECL_SYM("EXTENDED-CHAR",346)))) { goto L6; }
   goto L7;
L8:;
L7:;
   value0 = ECL_SYM("CHARACTER",222);
   cl_env_copy->nvalues = 1;
   return value0;
L6:;
   if (!((v2type)==(ECL_SYM("STRING",805)))) { goto L27; }
   goto L24;
   goto L25;
L27:;
   goto L25;
L25:;
   if (!((v2type)==(ECL_SYM("BASE-STRING",121)))) { goto L31; }
   goto L24;
   goto L29;
L31:;
   goto L29;
L29:;
   if (!((v2type)==(ECL_SYM("BIT-VECTOR",134)))) { goto L22; }
   goto L23;
L24:;
L23:;
   value0 = v2type;
   cl_env_copy->nvalues = 1;
   return value0;
L22:;
   if (!((v2type)==(ECL_SYM("VECTOR",898)))) { goto L34; }
   T0 = cl_array_element_type(v1thing);
   value0 = cl_list(2, ECL_SYM("VECTOR",898), T0);
   return value0;
L34:;
   if (!((v2type)==(ECL_SYM("ARRAY",96)))) { goto L36; }
   T0 = cl_array_element_type(v1thing);
   value0 = cl_list(2, ECL_SYM("ARRAY",96), T0);
   return value0;
L36:;
   if (!((v2type)==(ECL_SYM("STANDARD-OBJECT",976)))) { goto L38; }
   value0 = ECL_SYM("STANDARD-OBJECT",976);
   cl_env_copy->nvalues = 1;
   return value0;
L38:;
   if (!((v2type)==(ECL_SYM("STRUCTURE-OBJECT",978)))) { goto L40; }
   value0 = ECL_SYM("STRUCTURE-OBJECT",978);
   cl_env_copy->nvalues = 1;
   return value0;
L40:;
   value0 = ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for VALID-TYPE-SPECIFIER                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4valid_type_specifier(cl_object volatile v1type)
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
     v2 = ecl_make_cclosure_va((cl_objectfn)LC3__g11,env2,Cblock);
     T0 = v2;
    }
    T1 = CONS(ECL_SYM("ERROR",337),T0);
    T2 = ecl_list1(T1);
    T3 = CONS(T2,ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5)));
    ecl_bds_bind(cl_env_copy,ECL_SYM("*HANDLER-CLUSTERS*",5),T3); /*  *HANDLER-CLUSTERS* */
    if (Null(cl_subtypep(2, v1type, ECL_T))) { goto L4; }
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = v1type;
    cl_env_copy->values[0] = ECL_T;
    value0 = cl_env_copy->values[0];
    ecl_frs_pop(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    return value0;
L4:;
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = ECL_NIL;
    cl_env_copy->values[0] = ECL_NIL;
    value0 = cl_env_copy->values[0];
    ecl_frs_pop(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    return value0;
L1:;
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = ECL_NIL;
    cl_env_copy->values[0] = ECL_NIL;
    value0 = cl_env_copy->values[0];
    ecl_frs_pop(cl_env_copy);
    return value0;
   }
  }
 }
}
/*	closure G11                                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC3__g11(cl_narg narg, cl_object v1si__temp, ...)
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
/*	function definition for KNOWN-TYPE-P                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5known_type_p(cl_object v1type)
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
/*	function definition for TRIVIAL-TYPE-P                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6trivial_type_p(cl_object v1type)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_subtypep(2, ECL_T, v1type);
  return value0;
 }
}
/*	function definition for TYPE-AND-EMPTY-CACHE                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7type_and_empty_cache()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = si_make_vector(ECL_T, ecl_make_fixnum(1024), ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
  return value0;
 }
}
/*	function definition for TYPE-AND                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L9type_and(cl_object v1t1, cl_object v2t2)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v3hash;
   cl_object v4elt;
   {
    cl_object v5;
    T0 = si_hash_equal(2, v1t1, v2t2);
    v5 = ecl_boole(ECL_BOOLAND,(T0),(ecl_make_fixnum(1023)));
    {
     cl_fixnum v6;
     v6 = 0;
     if (!(ECL_FIXNUMP(v5))) { goto L7; }
     v6 = ecl_fixnum(v5);
     if (!((v6)<=(1023))) { goto L12; }
     T0 = ecl_make_bool((v6)>=(0));
     goto L4;
L12:;
     T0 = ECL_NIL;
     goto L4;
L7:;
     T0 = ECL_NIL;
     goto L4;
    }
L4:;
    if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[20],v5);
    v3hash = ecl_fixnum(v5);
   }
   {
    cl_object v5;
    v5 = ecl_symbol_value(VV[14]);
    {
     cl_fixnum v6;
     if (ecl_unlikely((v3hash)>=(v5)->vector.dim))
           FEwrong_index(ECL_NIL,v5,-1,ecl_make_fixnum(v3hash),(v5)->vector.dim);
     v6 = v3hash;
     v4elt = ecl_aref_unsafe(v5,v6);
    }
   }
   if (Null(v4elt)) { goto L19; }
   {
    cl_object v5;
    if (ecl_unlikely(ECL_ATOM(v4elt))) FEtype_error_cons(v4elt);
    v5 = v4elt;
    if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
    if (Null(v5)) { goto L28; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     if (ecl_unlikely(ECL_ATOM(v6))) FEtype_error_cons(v6);
     v4elt = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L28:;
    T0 = v5;
   }
   if (!(ecl_equal(T0,v1t1))) { goto L19; }
   {
    cl_object v5;
    if (ecl_unlikely(ECL_ATOM(v4elt))) FEtype_error_cons(v4elt);
    v5 = v4elt;
    if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
    if (Null(v5)) { goto L40; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     if (ecl_unlikely(ECL_ATOM(v6))) FEtype_error_cons(v6);
     v4elt = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L40:;
    T0 = v5;
   }
   if (!(ecl_equal(T0,v2t2))) { goto L19; }
   value0 = ecl_car(v4elt);
   cl_env_copy->nvalues = 1;
   return value0;
L19:;
   {
    cl_object v5output;
    v5output = LC8type_and(v1t1, v2t2);
    {
     cl_object v6;
     v6 = ecl_symbol_value(VV[14]);
     {
      cl_fixnum v7;
      if (ecl_unlikely((v3hash)>=(v6)->vector.dim))
           FEwrong_index(ECL_NIL,v6,-1,ecl_make_fixnum(v3hash),(v6)->vector.dim);
      v7 = v3hash;
      T0 = cl_list(3, v1t1, v2t2, v5output);
      ecl_aset_unsafe(v6,v7,T0);
     }
    }
    value0 = v5output;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	local function TYPE-AND                                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC8type_and(cl_object v1t1, cl_object v2t2)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((v1t1)==(v2t2)) { goto L3; }
  if (!((v2t2)==(ECL_SYM("*",18)))) { goto L1; }
  goto L2;
L3:;
L2:;
  value0 = v1t1;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (!((v1t1)==(ECL_SYM("*",18)))) { goto L5; }
  value0 = v2t2;
  cl_env_copy->nvalues = 1;
  return value0;
L5:;
  {
   cl_object v3tag1;
   cl_object v4tag2;
   ecl_bds_push(cl_env_copy,VV[16]);              /*  *HIGHEST-TYPE-TAG* */
   ecl_bds_bind(cl_env_copy,VV[17],ECL_T);        /*  *SAVE-TYPES-DATABASE* */
   ecl_bds_push(cl_env_copy,VV[18]);              /*  *MEMBER-TYPES*  */
   ecl_bds_push(cl_env_copy,VV[19]);              /*  *ELEMENTARY-TYPES* */
   v3tag1 = ecl_function_dispatch(cl_env_copy,VV[48])(1, v1t1) /*  SAFE-CANONICAL-TYPE */;
   v4tag2 = ecl_function_dispatch(cl_env_copy,VV[48])(1, v2t2) /*  SAFE-CANONICAL-TYPE */;
   if (!(ecl_numberp(v3tag1))) { goto L9; }
   if (!(ecl_numberp(v4tag2))) { goto L9; }
   v3tag1 = ecl_function_dispatch(cl_env_copy,VV[48])(1, v1t1) /*  SAFE-CANONICAL-TYPE */;
   v4tag2 = ecl_function_dispatch(cl_env_copy,VV[48])(1, v2t2) /*  SAFE-CANONICAL-TYPE */;
   T0 = ecl_boole(ECL_BOOLAND,(v3tag1),(v4tag2));
   if (!(ecl_zerop(T0))) { goto L16; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   ecl_bds_unwind_n(cl_env_copy,4);
   return value0;
L16:;
   T0 = ecl_boole(ECL_BOOLANDC2,(v3tag1),(v4tag2));
   if (!(ecl_zerop(T0))) { goto L18; }
   value0 = v1t1;
   cl_env_copy->nvalues = 1;
   ecl_bds_unwind_n(cl_env_copy,4);
   return value0;
L18:;
   T0 = ecl_boole(ECL_BOOLANDC2,(v4tag2),(v3tag1));
   if (!(ecl_zerop(T0))) { goto L20; }
   value0 = v2t2;
   cl_env_copy->nvalues = 1;
   ecl_bds_unwind_n(cl_env_copy,4);
   return value0;
L20:;
   value0 = cl_list(3, ECL_SYM("AND",87), v1t1, v2t2);
   ecl_bds_unwind_n(cl_env_copy,4);
   return value0;
L9:;
   if (!((v3tag1)==(ECL_SYM("CONS",251)))) { goto L22; }
   ecl_function_dispatch(cl_env_copy,VV[49])(2, _ecl_static_1, v1t1) /*  CMPWARN */;
   value0 = v2t2;
   cl_env_copy->nvalues = 1;
   ecl_bds_unwind_n(cl_env_copy,4);
   return value0;
L22:;
   if (!((v4tag2)==(ECL_SYM("CONS",251)))) { goto L25; }
   ecl_function_dispatch(cl_env_copy,VV[49])(2, _ecl_static_1, v2t2) /*  CMPWARN */;
   value0 = v1t1;
   cl_env_copy->nvalues = 1;
   ecl_bds_unwind_n(cl_env_copy,4);
   return value0;
L25:;
   if (!(v3tag1==ECL_NIL)) { goto L28; }
   ecl_function_dispatch(cl_env_copy,VV[50])(2, _ecl_static_2, v1t1) /*  CMPNOTE */;
   value0 = v2t2;
   cl_env_copy->nvalues = 1;
   ecl_bds_unwind_n(cl_env_copy,4);
   return value0;
L28:;
   ecl_function_dispatch(cl_env_copy,VV[50])(2, _ecl_static_2, v2t2) /*  CMPNOTE */;
   value0 = v1t1;
   cl_env_copy->nvalues = 1;
   ecl_bds_unwind_n(cl_env_copy,4);
   return value0;
  }
 }
}
/*	function definition for VALUES-NUMBER-FROM-TYPE               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L10values_number_from_type(cl_object v1type)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((v1type)==(ECL_T)) { goto L3; }
  if (!((v1type)==(ECL_SYM("*",18)))) { goto L1; }
  goto L2;
L3:;
L2:;
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = ecl_make_fixnum(64);
  cl_env_copy->values[0] = ecl_make_fixnum(0);
  return cl_env_copy->values[0];
L1:;
  if (ECL_ATOM(v1type)) { goto L7; }
  T0 = ecl_car(v1type);
  if ((T0)==(ECL_SYM("VALUES",895))) { goto L5; }
  goto L6;
L7:;
L6:;
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = ecl_make_fixnum(1);
  cl_env_copy->values[0] = ecl_make_fixnum(1);
  return cl_env_copy->values[0];
L5:;
  if ((ecl_memql(ECL_SYM("&REST",12),v1type))!=ECL_NIL) { goto L11; }
  if (Null(ecl_memql(ECL_SYM("&OPTIONAL",11),v1type))) { goto L9; }
  goto L10;
L11:;
L10:;
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = ecl_make_fixnum(64);
  cl_env_copy->values[0] = ecl_make_fixnum(0);
  return cl_env_copy->values[0];
L9:;
  {
   cl_object v2l;
   {
    cl_fixnum v3;
    v3 = ecl_length(v1type);
    v2l = ecl_make_integer((v3)-1);
   }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v2l;
   cl_env_copy->values[0] = v2l;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for VALUES-TYPE-PRIMARY-TYPE-EMPTY-CACHE  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L11values_type_primary_type_empty_cache()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = si_make_vector(ECL_T, ecl_make_fixnum(1024), ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
  return value0;
 }
}
/*	function definition for VALUES-TYPE-PRIMARY-TYPE              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L13values_type_primary_type(cl_object v1type)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v2hash;
   cl_object v3elt;
   {
    cl_object v4;
    T0 = si_hash_equal(1, v1type);
    v4 = ecl_boole(ECL_BOOLAND,(T0),(ecl_make_fixnum(1023)));
    {
     cl_fixnum v5;
     v5 = 0;
     if (!(ECL_FIXNUMP(v4))) { goto L7; }
     v5 = ecl_fixnum(v4);
     if (!((v5)<=(1023))) { goto L12; }
     T0 = ecl_make_bool((v5)>=(0));
     goto L4;
L12:;
     T0 = ECL_NIL;
     goto L4;
L7:;
     T0 = ECL_NIL;
     goto L4;
    }
L4:;
    if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[20],v4);
    v2hash = ecl_fixnum(v4);
   }
   {
    cl_object v4;
    v4 = ecl_symbol_value(VV[23]);
    {
     cl_fixnum v5;
     if (ecl_unlikely((v2hash)>=(v4)->vector.dim))
           FEwrong_index(ECL_NIL,v4,-1,ecl_make_fixnum(v2hash),(v4)->vector.dim);
     v5 = v2hash;
     v3elt = ecl_aref_unsafe(v4,v5);
    }
   }
   if (Null(v3elt)) { goto L19; }
   {
    cl_object v4;
    if (ecl_unlikely(ECL_ATOM(v3elt))) FEtype_error_cons(v3elt);
    v4 = v3elt;
    if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
    if (Null(v4)) { goto L27; }
    {
     cl_object v5;
     v5 = ECL_CONS_CDR(v4);
     if (ecl_unlikely(ECL_ATOM(v5))) FEtype_error_cons(v5);
     v3elt = v5;
     v4 = ECL_CONS_CAR(v4);
    }
L27:;
    T0 = v4;
   }
   if (!(ecl_equal(T0,v1type))) { goto L19; }
   value0 = ecl_car(v3elt);
   cl_env_copy->nvalues = 1;
   return value0;
L19:;
   {
    cl_object v4output;
    v4output = LC12values_type_primary_type(v1type);
    {
     cl_object v5;
     v5 = ecl_symbol_value(VV[23]);
     {
      cl_fixnum v6;
      if (ecl_unlikely((v2hash)>=(v5)->vector.dim))
           FEwrong_index(ECL_NIL,v5,-1,ecl_make_fixnum(v2hash),(v5)->vector.dim);
      v6 = v2hash;
      T0 = cl_list(2, v1type, v4output);
      ecl_aset_unsafe(v5,v6,T0);
     }
    }
    value0 = v4output;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	local function VALUES-TYPE-PRIMARY-TYPE                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC12values_type_primary_type(cl_object v1type)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_CONSP(v1type))) { goto L1; }
  T0 = ecl_car(v1type);
  if (!((T0)==(ECL_SYM("VALUES",895)))) { goto L1; }
  T0 = ecl_cdr(v1type);
  if (!(T0==ECL_NIL)) { goto L4; }
  v1type = ECL_SYM("NULL",605);
  goto L1;
L4:;
  {
   cl_object v2subtype;
   v2subtype = ecl_cadr(v1type);
   if ((v2subtype)==(ECL_SYM("&OPTIONAL",11))) { goto L10; }
   if (!((v2subtype)==(ECL_SYM("&REST",12)))) { goto L8; }
   goto L9;
L10:;
L9:;
   v1type = ecl_cddr(v1type);
   if (v1type==ECL_NIL) { goto L16; }
   v2subtype = ecl_car(v1type);
   if ((v2subtype)==(ECL_SYM("&OPTIONAL",11))) { goto L16; }
   if (!((v2subtype)==(ECL_SYM("&REST",12)))) { goto L14; }
   goto L15;
L16:;
L15:;
   ecl_function_dispatch(cl_env_copy,VV[54])(2, _ecl_static_3, v1type) /*  CMPERR */;
L14:;
   v2subtype = L26type_or(ECL_SYM("NULL",605), v2subtype);
L8:;
   v1type = v2subtype;
  }
L1:;
  value0 = v1type;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for VALUES-TYPE-TO-N-TYPES-EMPTY-CACHE    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L14values_type_to_n_types_empty_cache()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = si_make_vector(ECL_T, ecl_make_fixnum(1024), ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
  return value0;
 }
}
/*	function definition for VALUES-TYPE-TO-N-TYPES                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L16values_type_to_n_types(cl_object v1type, cl_object v2length)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v3hash;
   cl_object v4elt;
   {
    cl_object v5;
    T0 = si_hash_equal(2, v1type, v2length);
    v5 = ecl_boole(ECL_BOOLAND,(T0),(ecl_make_fixnum(1023)));
    {
     cl_fixnum v6;
     v6 = 0;
     if (!(ECL_FIXNUMP(v5))) { goto L7; }
     v6 = ecl_fixnum(v5);
     if (!((v6)<=(1023))) { goto L12; }
     T0 = ecl_make_bool((v6)>=(0));
     goto L4;
L12:;
     T0 = ECL_NIL;
     goto L4;
L7:;
     T0 = ECL_NIL;
     goto L4;
    }
L4:;
    if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[20],v5);
    v3hash = ecl_fixnum(v5);
   }
   {
    cl_object v5;
    v5 = ecl_symbol_value(VV[26]);
    {
     cl_fixnum v6;
     if (ecl_unlikely((v3hash)>=(v5)->vector.dim))
           FEwrong_index(ECL_NIL,v5,-1,ecl_make_fixnum(v3hash),(v5)->vector.dim);
     v6 = v3hash;
     v4elt = ecl_aref_unsafe(v5,v6);
    }
   }
   if (Null(v4elt)) { goto L19; }
   {
    cl_object v5;
    if (ecl_unlikely(ECL_ATOM(v4elt))) FEtype_error_cons(v4elt);
    v5 = v4elt;
    if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
    if (Null(v5)) { goto L28; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     if (ecl_unlikely(ECL_ATOM(v6))) FEtype_error_cons(v6);
     v4elt = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L28:;
    T0 = v5;
   }
   if (!(ecl_equal(T0,v1type))) { goto L19; }
   {
    cl_object v5;
    if (ecl_unlikely(ECL_ATOM(v4elt))) FEtype_error_cons(v4elt);
    v5 = v4elt;
    if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
    if (Null(v5)) { goto L40; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     if (ecl_unlikely(ECL_ATOM(v6))) FEtype_error_cons(v6);
     v4elt = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L40:;
    T0 = v5;
   }
   if (!(ecl_equal(T0,v2length))) { goto L19; }
   value0 = ecl_car(v4elt);
   cl_env_copy->nvalues = 1;
   return value0;
L19:;
   {
    cl_object v5output;
    v5output = LC15values_type_to_n_types(v1type, v2length);
    {
     cl_object v6;
     v6 = ecl_symbol_value(VV[26]);
     {
      cl_fixnum v7;
      if (ecl_unlikely((v3hash)>=(v6)->vector.dim))
           FEwrong_index(ECL_NIL,v6,-1,ecl_make_fixnum(v3hash),(v6)->vector.dim);
      v7 = v3hash;
      T0 = cl_list(3, v1type, v2length, v5output);
      ecl_aset_unsafe(v6,v7,T0);
     }
    }
    value0 = v5output;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	local function VALUES-TYPE-TO-N-TYPES                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC15values_type_to_n_types(cl_object v1type, cl_object v2length)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (ECL_ATOM(v1type)) { goto L3; }
  T0 = ecl_car(v1type);
  if ((T0)==(ECL_SYM("VALUES",895))) { goto L1; }
  goto L2;
L3:;
L2:;
  if (!(ecl_plusp(v2length))) { goto L6; }
  T0 = ecl_one_minus(v2length);
  T1 = cl_make_list(3, T0, ECL_SYM("INITIAL-ELEMENT",1251), ECL_SYM("NULL",605));
  value0 = CONS(v1type,T1);
  cl_env_copy->nvalues = 1;
  return value0;
L6:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  {
   cl_object v3l;
   cl_object v4output;
   cl_object v5n;
   v3l = ecl_cdr(v1type);
   v4output = ECL_NIL;
   v5n = v2length;
   goto L13;
L12:;
   {
    cl_object v6type;
    {
     cl_object v7;
     v7 = v3l;
     if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
     if (Null(v7)) { goto L20; }
     {
      cl_object v8;
      v8 = ECL_CONS_CDR(v7);
      v3l = v8;
      v7 = ECL_CONS_CAR(v7);
     }
L20:;
     v6type = v7;
    }
    {
     cl_object v7;
     v7 = v6type;
     if (!((v7)==(ECL_SYM("&OPTIONAL",11)))) { goto L28; }
     if (!(v3l==ECL_NIL)) { goto L30; }
     ecl_function_dispatch(cl_env_copy,VV[54])(2, _ecl_static_3, v6type) /*  CMPERR */;
L30:;
     {
      cl_object v8;
      v8 = v3l;
      if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
      if (Null(v8)) { goto L36; }
      {
       cl_object v9;
       v9 = ECL_CONS_CDR(v8);
       v3l = v9;
       v8 = ECL_CONS_CAR(v8);
      }
L36:;
      v6type = v8;
     }
     goto L26;
L28:;
     if (!((v7)==(ECL_SYM("&REST",12)))) { goto L26; }
     if (!(v3l==ECL_NIL)) { goto L43; }
     ecl_function_dispatch(cl_env_copy,VV[54])(2, _ecl_static_3, v6type) /*  CMPERR */;
L43:;
     T0 = ecl_car(v3l);
     T1 = cl_make_list(3, v5n, ECL_SYM("INITIAL-ELEMENT",1251), T0);
     value0 = cl_nreconc(v4output, T1);
     return value0;
    }
L26:;
    v4output = CONS(v6type,v4output);
   }
   v5n = ecl_one_minus(v5n);
L13:;
   if (v3l==ECL_NIL) { goto L48; }
   if (ecl_zerop(v5n)) { goto L48; }
   goto L12;
L48:;
   value0 = cl_nreverse(v4output);
   return value0;
  }
 }
}
/*	function definition for SPLIT-VALUES-TYPE                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L17split_values_type(cl_object v1type)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (ECL_ATOM(v1type)) { goto L3; }
  T0 = ecl_car(v1type);
  if ((T0)==(ECL_SYM("VALUES",895))) { goto L1; }
  goto L2;
L3:;
L2:;
  T0 = ecl_list1(v1type);
  cl_env_copy->nvalues = 3;
  cl_env_copy->values[2] = ECL_NIL;
  cl_env_copy->values[1] = ECL_NIL;
  cl_env_copy->values[0] = T0;
  return cl_env_copy->values[0];
L1:;
  {
   cl_object v2;
   cl_object v3;
   v2 = ecl_memql(ECL_SYM("&REST",12),v1type);
   v3 = ecl_memql(ECL_SYM("&OPTIONAL",11),v1type);
   T0 = ecl_cdr(v1type);
   value0 = v2;
   if ((value0)!=ECL_NIL) { goto L9; }
   T1 = v3;
   goto L7;
L9:;
   T1 = value0;
   goto L7;
L7:;
   T2 = cl_ldiff(T0, T1);
   T3 = ecl_memql(ECL_SYM("&OPTIONAL",11),v1type);
   T4 = ecl_cdr(T3);
   T5 = cl_ldiff(T4, v2);
   T6 = ecl_memql(ECL_SYM("&REST",12),v1type);
   T7 = ecl_cdr(T6);
   cl_env_copy->nvalues = 3;
   cl_env_copy->values[2] = T7;
   cl_env_copy->values[1] = T5;
   cl_env_copy->values[0] = T2;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for VALUES-TYPE-OR-EMPTY-CACHE            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L18values_type_or_empty_cache()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = si_make_vector(ECL_T, ecl_make_fixnum(1024), ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
  return value0;
 }
}
/*	function definition for VALUES-TYPE-OR                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L20values_type_or(cl_object v1t1, cl_object v2t2)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v3hash;
   cl_object v4elt;
   {
    cl_object v5;
    T0 = si_hash_equal(2, v1t1, v2t2);
    v5 = ecl_boole(ECL_BOOLAND,(T0),(ecl_make_fixnum(1023)));
    {
     cl_fixnum v6;
     v6 = 0;
     if (!(ECL_FIXNUMP(v5))) { goto L7; }
     v6 = ecl_fixnum(v5);
     if (!((v6)<=(1023))) { goto L12; }
     T0 = ecl_make_bool((v6)>=(0));
     goto L4;
L12:;
     T0 = ECL_NIL;
     goto L4;
L7:;
     T0 = ECL_NIL;
     goto L4;
    }
L4:;
    if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[20],v5);
    v3hash = ecl_fixnum(v5);
   }
   {
    cl_object v5;
    v5 = ecl_symbol_value(VV[30]);
    {
     cl_fixnum v6;
     if (ecl_unlikely((v3hash)>=(v5)->vector.dim))
           FEwrong_index(ECL_NIL,v5,-1,ecl_make_fixnum(v3hash),(v5)->vector.dim);
     v6 = v3hash;
     v4elt = ecl_aref_unsafe(v5,v6);
    }
   }
   if (Null(v4elt)) { goto L19; }
   {
    cl_object v5;
    if (ecl_unlikely(ECL_ATOM(v4elt))) FEtype_error_cons(v4elt);
    v5 = v4elt;
    if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
    if (Null(v5)) { goto L28; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     if (ecl_unlikely(ECL_ATOM(v6))) FEtype_error_cons(v6);
     v4elt = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L28:;
    T0 = v5;
   }
   if (!(ecl_equal(T0,v1t1))) { goto L19; }
   {
    cl_object v5;
    if (ecl_unlikely(ECL_ATOM(v4elt))) FEtype_error_cons(v4elt);
    v5 = v4elt;
    if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
    if (Null(v5)) { goto L40; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     if (ecl_unlikely(ECL_ATOM(v6))) FEtype_error_cons(v6);
     v4elt = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L40:;
    T0 = v5;
   }
   if (!(ecl_equal(T0,v2t2))) { goto L19; }
   value0 = ecl_car(v4elt);
   cl_env_copy->nvalues = 1;
   return value0;
L19:;
   {
    cl_object v5output;
    v5output = LC19values_type_or(v1t1, v2t2);
    {
     cl_object v6;
     v6 = ecl_symbol_value(VV[30]);
     {
      cl_fixnum v7;
      if (ecl_unlikely((v3hash)>=(v6)->vector.dim))
           FEwrong_index(ECL_NIL,v6,-1,ecl_make_fixnum(v3hash),(v6)->vector.dim);
      v7 = v3hash;
      T0 = cl_list(3, v1t1, v2t2, v5output);
      ecl_aset_unsafe(v6,v7,T0);
     }
    }
    value0 = v5output;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	local function VALUES-TYPE-OR                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC19values_type_or(cl_object v1t1, cl_object v2t2)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((v2t2)==(ECL_T)) { goto L3; }
  if (!(ecl_equalp(v2t2,VV[32]))) { goto L1; }
  goto L2;
L3:;
L2:;
  value0 = v2t2;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if ((v1t1)==(ECL_T)) { goto L7; }
  if (!(ecl_equalp(v1t1,VV[32]))) { goto L5; }
  goto L6;
L7:;
L6:;
  value0 = v1t1;
  cl_env_copy->nvalues = 1;
  return value0;
L5:;
  if ((v1t1)!=ECL_NIL) { goto L9; }
  value0 = v2t2;
  cl_env_copy->nvalues = 1;
  return value0;
L9:;
  if ((v2t2)!=ECL_NIL) { goto L11; }
  value0 = v1t1;
  cl_env_copy->nvalues = 1;
  return value0;
L11:;
  {
   cl_object v4;                                  /*  REQ1            */
   cl_object v5;                                  /*  OPT1            */
   cl_object v6;                                  /*  REST1           */
   value0 = L17split_values_type(v1t1);
   v4 = value0;
   {
    const int v7 = cl_env_copy->nvalues;
    cl_object v8;
    v8 = (v7<=1)? ECL_NIL : cl_env_copy->values[1];
    v5 = v8;
    v8 = (v7<=2)? ECL_NIL : cl_env_copy->values[2];
    v6 = v8;
   }
   {
    cl_object v8;                                 /*  REQ2            */
    cl_object v9;                                 /*  OPT2            */
    cl_object v10;                                /*  REST2           */
    value0 = L17split_values_type(v2t2);
    v8 = value0;
    {
     const int v11 = cl_env_copy->nvalues;
     cl_object v12;
     v12 = (v11<=1)? ECL_NIL : cl_env_copy->values[1];
     v9 = v12;
     v12 = (v11<=2)? ECL_NIL : cl_env_copy->values[2];
     v10 = v12;
    }
    {
     cl_object v11req;
     cl_object v12opt;
     cl_object v13rest;
     v11req = ECL_NIL;
     v12opt = ECL_NIL;
     v13rest = ECL_NIL;
     {
      cl_object v14t1;
      cl_object v15;
      v14t1 = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
      v15 = v4;
L22:;
      if (!(ecl_endp(v15))) { goto L24; }
      goto L23;
L24:;
      v14t1 = _ecl_car(v15);
      {
       cl_object v16;
       v16 = _ecl_cdr(v15);
       if (ecl_unlikely(!ECL_LISTP(v16))) FEtype_error_list(v16);
       v15 = v16;
      }
      if (Null(v8)) { goto L33; }
      {
       cl_object v16;
       v16 = v8;
       if (ecl_unlikely(!ECL_LISTP(v16))) FEtype_error_list(v16);
       if (Null(v16)) { goto L40; }
       {
        cl_object v17;
        v17 = ECL_CONS_CDR(v16);
        v8 = v17;
        v16 = ECL_CONS_CAR(v16);
       }
L40:;
       T0 = v16;
      }
      T1 = L26type_or(v14t1, T0);
      v11req = CONS(T1,v11req);
      goto L32;
L33:;
      if (Null(v9)) { goto L46; }
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
       T0 = v16;
      }
      T1 = L26type_or(v14t1, T0);
      v12opt = CONS(T1,v12opt);
      goto L32;
L46:;
      if (Null(v10)) { goto L59; }
      T0 = ecl_car(v10);
      T1 = L26type_or(v14t1, T0);
      v12opt = CONS(T1,v12opt);
      goto L32;
L59:;
      v12opt = CONS(v14t1,v12opt);
L32:;
      goto L22;
L23:;
     }
     {
      cl_object v14t1;
      cl_object v15;
      v14t1 = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
      v15 = v5;
L68:;
      if (!(ecl_endp(v15))) { goto L70; }
      goto L69;
L70:;
      v14t1 = _ecl_car(v15);
      {
       cl_object v16;
       v16 = _ecl_cdr(v15);
       if (ecl_unlikely(!ECL_LISTP(v16))) FEtype_error_list(v16);
       v15 = v16;
      }
      if (Null(v8)) { goto L79; }
      {
       cl_object v16;
       v16 = v8;
       if (ecl_unlikely(!ECL_LISTP(v16))) FEtype_error_list(v16);
       if (Null(v16)) { goto L86; }
       {
        cl_object v17;
        v17 = ECL_CONS_CDR(v16);
        v8 = v17;
        v16 = ECL_CONS_CAR(v16);
       }
L86:;
       T0 = v16;
      }
      T1 = L26type_or(v14t1, T0);
      v12opt = CONS(T1,v12opt);
      goto L78;
L79:;
      if (Null(v9)) { goto L92; }
      {
       cl_object v16;
       v16 = v9;
       if (ecl_unlikely(!ECL_LISTP(v16))) FEtype_error_list(v16);
       if (Null(v16)) { goto L99; }
       {
        cl_object v17;
        v17 = ECL_CONS_CDR(v16);
        v9 = v17;
        v16 = ECL_CONS_CAR(v16);
       }
L99:;
       T0 = v16;
      }
      T1 = L26type_or(v14t1, T0);
      v12opt = CONS(T1,v12opt);
      goto L78;
L92:;
      if (Null(v10)) { goto L105; }
      T0 = ecl_car(v10);
      T1 = L26type_or(v14t1, T0);
      v12opt = CONS(T1,v12opt);
      goto L78;
L105:;
      v12opt = CONS(v14t1,v12opt);
L78:;
      goto L68;
L69:;
     }
     {
      cl_object v14t1;
      if (Null(v6)) { goto L112; }
      v14t1 = ecl_car(v6);
      goto L111;
L112:;
      v14t1 = ECL_T;
L111:;
      {
       cl_object v15t2;
       cl_object v16;
       v15t2 = ECL_NIL;
       if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
       v16 = v8;
L118:;
       if (!(ecl_endp(v16))) { goto L120; }
       goto L119;
L120:;
       v15t2 = _ecl_car(v16);
       {
        cl_object v17;
        v17 = _ecl_cdr(v16);
        if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
        v16 = v17;
       }
       T0 = L26type_or(v14t1, v15t2);
       v12opt = CONS(T0,v12opt);
       goto L118;
L119:;
      }
      {
       cl_object v15t2;
       cl_object v16;
       v15t2 = ECL_NIL;
       if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
       v16 = v9;
L135:;
       if (!(ecl_endp(v16))) { goto L137; }
       goto L136;
L137:;
       v15t2 = _ecl_car(v16);
       {
        cl_object v17;
        v17 = _ecl_cdr(v16);
        if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
        v16 = v17;
       }
       T0 = L26type_or(v14t1, v15t2);
       v12opt = CONS(T0,v12opt);
       goto L135;
L136:;
      }
      if (Null(v10)) { goto L148; }
      T0 = ecl_car(v10);
      T1 = L26type_or(v14t1, T0);
      v13rest = ecl_list1(T1);
      goto L110;
L148:;
      v13rest = v6;
     }
L110:;
     T0 = cl_nreverse(v11req);
     if (Null(v12opt)) { goto L154; }
     T2 = cl_nreverse(v12opt);
     T1 = CONS(ECL_SYM("&OPTIONAL",11),T2);
     goto L152;
L154:;
     T1 = ECL_NIL;
     goto L152;
L152:;
     if (Null(v13rest)) { goto L158; }
     T2 = CONS(ECL_SYM("&OPTIONAL",11),v13rest);
     goto L156;
L158:;
     T2 = ECL_NIL;
     goto L156;
L156:;
     T3 = cl_append(3, T0, T1, T2);
     value0 = CONS(ECL_SYM("VALUES",895),T3);
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
  }
 }
}
/*	function definition for VALUES-TYPE-AND-EMPTY-CACHE           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L21values_type_and_empty_cache()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = si_make_vector(ECL_T, ecl_make_fixnum(1024), ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
  return value0;
 }
}
/*	function definition for VALUES-TYPE-AND                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L23values_type_and(cl_object v1t1, cl_object v2t2)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v3hash;
   cl_object v4elt;
   {
    cl_object v5;
    T0 = si_hash_equal(2, v1t1, v2t2);
    v5 = ecl_boole(ECL_BOOLAND,(T0),(ecl_make_fixnum(1023)));
    {
     cl_fixnum v6;
     v6 = 0;
     if (!(ECL_FIXNUMP(v5))) { goto L7; }
     v6 = ecl_fixnum(v5);
     if (!((v6)<=(1023))) { goto L12; }
     T0 = ecl_make_bool((v6)>=(0));
     goto L4;
L12:;
     T0 = ECL_NIL;
     goto L4;
L7:;
     T0 = ECL_NIL;
     goto L4;
    }
L4:;
    if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[20],v5);
    v3hash = ecl_fixnum(v5);
   }
   {
    cl_object v5;
    v5 = ecl_symbol_value(VV[34]);
    {
     cl_fixnum v6;
     if (ecl_unlikely((v3hash)>=(v5)->vector.dim))
           FEwrong_index(ECL_NIL,v5,-1,ecl_make_fixnum(v3hash),(v5)->vector.dim);
     v6 = v3hash;
     v4elt = ecl_aref_unsafe(v5,v6);
    }
   }
   if (Null(v4elt)) { goto L19; }
   {
    cl_object v5;
    if (ecl_unlikely(ECL_ATOM(v4elt))) FEtype_error_cons(v4elt);
    v5 = v4elt;
    if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
    if (Null(v5)) { goto L28; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     if (ecl_unlikely(ECL_ATOM(v6))) FEtype_error_cons(v6);
     v4elt = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L28:;
    T0 = v5;
   }
   if (!(ecl_equal(T0,v1t1))) { goto L19; }
   {
    cl_object v5;
    if (ecl_unlikely(ECL_ATOM(v4elt))) FEtype_error_cons(v4elt);
    v5 = v4elt;
    if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
    if (Null(v5)) { goto L40; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     if (ecl_unlikely(ECL_ATOM(v6))) FEtype_error_cons(v6);
     v4elt = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L40:;
    T0 = v5;
   }
   if (!(ecl_equal(T0,v2t2))) { goto L19; }
   value0 = ecl_car(v4elt);
   cl_env_copy->nvalues = 1;
   return value0;
L19:;
   {
    cl_object v5output;
    v5output = LC22values_type_and(v1t1, v2t2);
    {
     cl_object v6;
     v6 = ecl_symbol_value(VV[34]);
     {
      cl_fixnum v7;
      if (ecl_unlikely((v3hash)>=(v6)->vector.dim))
           FEwrong_index(ECL_NIL,v6,-1,ecl_make_fixnum(v3hash),(v6)->vector.dim);
      v7 = v3hash;
      T0 = cl_list(3, v1t1, v2t2, v5output);
      ecl_aset_unsafe(v6,v7,T0);
     }
    }
    value0 = v5output;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	local function VALUES-TYPE-AND                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC22values_type_and(cl_object v1t1, cl_object v2t2)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((v2t2)==(ECL_T)) { goto L3; }
  if (!(ecl_equalp(v2t2,VV[32]))) { goto L1; }
  goto L2;
L3:;
L2:;
  value0 = v1t1;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if ((v1t1)==(ECL_T)) { goto L7; }
  if (!(ecl_equalp(v1t1,VV[32]))) { goto L5; }
  goto L6;
L7:;
L6:;
  value0 = v2t2;
  cl_env_copy->nvalues = 1;
  return value0;
L5:;
  if (v1t1==ECL_NIL) { goto L11; }
  if (!(v2t2==ECL_NIL)) { goto L9; }
  goto L10;
L11:;
L10:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L9:;
  {
   cl_object v4;                                  /*  REQ1            */
   cl_object v5;                                  /*  OPT1            */
   cl_object v6;                                  /*  REST1           */
   value0 = L17split_values_type(v1t1);
   v4 = value0;
   {
    const int v7 = cl_env_copy->nvalues;
    cl_object v8;
    v8 = (v7<=1)? ECL_NIL : cl_env_copy->values[1];
    v5 = v8;
    v8 = (v7<=2)? ECL_NIL : cl_env_copy->values[2];
    v6 = v8;
   }
   {
    cl_object v8;                                 /*  REQ2            */
    cl_object v9;                                 /*  OPT2            */
    cl_object v10;                                /*  REST2           */
    value0 = L17split_values_type(v2t2);
    v8 = value0;
    {
     const int v11 = cl_env_copy->nvalues;
     cl_object v12;
     v12 = (v11<=1)? ECL_NIL : cl_env_copy->values[1];
     v9 = v12;
     v12 = (v11<=2)? ECL_NIL : cl_env_copy->values[2];
     v10 = v12;
    }
    {
     cl_object v11req;
     cl_object v12opt;
     cl_object v13rest;
     v11req = ECL_NIL;
     v12opt = ECL_NIL;
     v13rest = ECL_NIL;
     {
      cl_object v14t1;
      cl_object v15;
      v14t1 = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
      v15 = v4;
L22:;
      if (!(ecl_endp(v15))) { goto L24; }
      goto L23;
L24:;
      v14t1 = _ecl_car(v15);
      {
       cl_object v16;
       v16 = _ecl_cdr(v15);
       if (ecl_unlikely(!ECL_LISTP(v16))) FEtype_error_list(v16);
       v15 = v16;
      }
      if (Null(v8)) { goto L33; }
      {
       cl_object v16;
       v16 = v8;
       if (ecl_unlikely(!ECL_LISTP(v16))) FEtype_error_list(v16);
       if (Null(v16)) { goto L40; }
       {
        cl_object v17;
        v17 = ECL_CONS_CDR(v16);
        v8 = v17;
        v16 = ECL_CONS_CAR(v16);
       }
L40:;
       T0 = v16;
      }
      T1 = L9type_and(v14t1, T0);
      v11req = CONS(T1,v11req);
      goto L32;
L33:;
      if (Null(v9)) { goto L46; }
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
       T0 = v16;
      }
      T1 = L9type_and(v14t1, T0);
      v11req = CONS(T1,v11req);
      goto L32;
L46:;
      if (Null(v10)) { goto L59; }
      T0 = ecl_car(v10);
      T1 = L9type_and(v14t1, T0);
      v11req = CONS(T1,v11req);
      goto L32;
L59:;
      v5 = ECL_NIL;
      v6 = ECL_NIL;
      goto L18;
L32:;
      goto L22;
L23:;
     }
L18:;
     {
      cl_object v14;
      cl_object v15t1;
      cl_object v16;
      v14 = v5;
      v15t1 = ECL_NIL;
      if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
      v16 = v14;
L72:;
      if (!(ecl_endp(v16))) { goto L74; }
      goto L73;
L74:;
      v15t1 = _ecl_car(v16);
      {
       cl_object v17;
       v17 = _ecl_cdr(v16);
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       v16 = v17;
      }
      if (Null(v8)) { goto L83; }
      {
       cl_object v17;
       v17 = v8;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L90; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v8 = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L90:;
       T0 = v17;
      }
      T1 = L9type_and(v15t1, T0);
      v11req = CONS(T1,v11req);
      goto L82;
L83:;
      if (Null(v9)) { goto L96; }
      {
       cl_object v17;
       v17 = v9;
       if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
       if (Null(v17)) { goto L103; }
       {
        cl_object v18;
        v18 = ECL_CONS_CDR(v17);
        v9 = v18;
        v17 = ECL_CONS_CAR(v17);
       }
L103:;
       T0 = v17;
      }
      T1 = L9type_and(v15t1, T0);
      v12opt = CONS(T1,v12opt);
      goto L82;
L96:;
      if (Null(v10)) { goto L109; }
      T0 = ecl_car(v10);
      T1 = L9type_and(v15t1, T0);
      v12opt = CONS(T1,v12opt);
      goto L82;
L109:;
      v5 = ECL_NIL;
      v6 = ECL_NIL;
      goto L67;
L82:;
      goto L72;
L73:;
     }
L67:;
     if (Null(v13rest)) { goto L117; }
     {
      cl_object v14t1;
      v14t1 = ecl_car(v13rest);
      {
       cl_object v15t2;
       cl_object v16;
       v15t2 = ECL_NIL;
       if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
       v16 = v8;
L124:;
       if (!(ecl_endp(v16))) { goto L126; }
       goto L125;
L126:;
       v15t2 = _ecl_car(v16);
       {
        cl_object v17;
        v17 = _ecl_cdr(v16);
        if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
        v16 = v17;
       }
       T0 = L9type_and(v14t1, v15t2);
       v11req = CONS(T0,v11req);
       goto L124;
L125:;
      }
      {
       cl_object v15t2;
       cl_object v16;
       v15t2 = ECL_NIL;
       if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
       v16 = v9;
L141:;
       if (!(ecl_endp(v16))) { goto L143; }
       goto L142;
L143:;
       v15t2 = _ecl_car(v16);
       {
        cl_object v17;
        v17 = _ecl_cdr(v16);
        if (ecl_unlikely(!ECL_LISTP(v17))) FEtype_error_list(v17);
        v16 = v17;
       }
       T0 = L9type_and(v14t1, v15t2);
       v12opt = CONS(T0,v12opt);
       goto L141;
L142:;
      }
      if (Null(v10)) { goto L117; }
      T0 = ecl_car(v10);
      T1 = L9type_and(v14t1, T0);
      v13rest = ecl_list1(T1);
     }
L117:;
     T0 = cl_nreverse(v11req);
     if (Null(v12opt)) { goto L158; }
     T2 = cl_nreverse(v12opt);
     T1 = CONS(ECL_SYM("&OPTIONAL",11),T2);
     goto L156;
L158:;
     T1 = ECL_NIL;
     goto L156;
L156:;
     if (Null(v13rest)) { goto L162; }
     T2 = CONS(ECL_SYM("&OPTIONAL",11),v13rest);
     goto L160;
L162:;
     T2 = ECL_NIL;
     goto L160;
L160:;
     T3 = cl_append(3, T0, T1, T2);
     value0 = CONS(ECL_SYM("VALUES",895),T3);
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
  }
 }
}
/*	function definition for TYPE-OR-EMPTY-CACHE                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L24type_or_empty_cache()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = si_make_vector(ECL_T, ecl_make_fixnum(1024), ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
  return value0;
 }
}
/*	function definition for TYPE-OR                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L26type_or(cl_object v1t1, cl_object v2t2)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v3hash;
   cl_object v4elt;
   {
    cl_object v5;
    T0 = si_hash_equal(2, v1t1, v2t2);
    v5 = ecl_boole(ECL_BOOLAND,(T0),(ecl_make_fixnum(1023)));
    {
     cl_fixnum v6;
     v6 = 0;
     if (!(ECL_FIXNUMP(v5))) { goto L7; }
     v6 = ecl_fixnum(v5);
     if (!((v6)<=(1023))) { goto L12; }
     T0 = ecl_make_bool((v6)>=(0));
     goto L4;
L12:;
     T0 = ECL_NIL;
     goto L4;
L7:;
     T0 = ECL_NIL;
     goto L4;
    }
L4:;
    if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[20],v5);
    v3hash = ecl_fixnum(v5);
   }
   {
    cl_object v5;
    v5 = ecl_symbol_value(VV[37]);
    {
     cl_fixnum v6;
     if (ecl_unlikely((v3hash)>=(v5)->vector.dim))
           FEwrong_index(ECL_NIL,v5,-1,ecl_make_fixnum(v3hash),(v5)->vector.dim);
     v6 = v3hash;
     v4elt = ecl_aref_unsafe(v5,v6);
    }
   }
   if (Null(v4elt)) { goto L19; }
   {
    cl_object v5;
    if (ecl_unlikely(ECL_ATOM(v4elt))) FEtype_error_cons(v4elt);
    v5 = v4elt;
    if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
    if (Null(v5)) { goto L28; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     if (ecl_unlikely(ECL_ATOM(v6))) FEtype_error_cons(v6);
     v4elt = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L28:;
    T0 = v5;
   }
   if (!(ecl_equal(T0,v1t1))) { goto L19; }
   {
    cl_object v5;
    if (ecl_unlikely(ECL_ATOM(v4elt))) FEtype_error_cons(v4elt);
    v5 = v4elt;
    if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
    if (Null(v5)) { goto L40; }
    {
     cl_object v6;
     v6 = ECL_CONS_CDR(v5);
     if (ecl_unlikely(ECL_ATOM(v6))) FEtype_error_cons(v6);
     v4elt = v6;
     v5 = ECL_CONS_CAR(v5);
    }
L40:;
    T0 = v5;
   }
   if (!(ecl_equal(T0,v2t2))) { goto L19; }
   value0 = ecl_car(v4elt);
   cl_env_copy->nvalues = 1;
   return value0;
L19:;
   {
    cl_object v5output;
    v5output = LC25type_or(v1t1, v2t2);
    {
     cl_object v6;
     v6 = ecl_symbol_value(VV[37]);
     {
      cl_fixnum v7;
      if (ecl_unlikely((v3hash)>=(v6)->vector.dim))
           FEwrong_index(ECL_NIL,v6,-1,ecl_make_fixnum(v3hash),(v6)->vector.dim);
      v7 = v3hash;
      T0 = cl_list(3, v1t1, v2t2, v5output);
      ecl_aset_unsafe(v6,v7,T0);
     }
    }
    value0 = v5output;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	local function TYPE-OR                                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC25type_or(cl_object v1t1, cl_object v2t2)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((v1t1)==(v2t2)) { goto L3; }
  if (!((v2t2)==(ECL_SYM("*",18)))) { goto L1; }
  goto L2;
L3:;
L2:;
  value0 = v1t1;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (!((v1t1)==(ECL_SYM("*",18)))) { goto L5; }
  value0 = v2t2;
  cl_env_copy->nvalues = 1;
  return value0;
L5:;
  {
   cl_object v3tag1;
   cl_object v4tag2;
   ecl_bds_push(cl_env_copy,VV[16]);              /*  *HIGHEST-TYPE-TAG* */
   ecl_bds_bind(cl_env_copy,VV[17],ECL_T);        /*  *SAVE-TYPES-DATABASE* */
   ecl_bds_push(cl_env_copy,VV[18]);              /*  *MEMBER-TYPES*  */
   ecl_bds_push(cl_env_copy,VV[19]);              /*  *ELEMENTARY-TYPES* */
   v3tag1 = ecl_function_dispatch(cl_env_copy,VV[48])(1, v1t1) /*  SAFE-CANONICAL-TYPE */;
   v4tag2 = ecl_function_dispatch(cl_env_copy,VV[48])(1, v2t2) /*  SAFE-CANONICAL-TYPE */;
   if (!(ecl_numberp(v3tag1))) { goto L9; }
   if (!(ecl_numberp(v4tag2))) { goto L9; }
   v3tag1 = ecl_function_dispatch(cl_env_copy,VV[48])(1, v1t1) /*  SAFE-CANONICAL-TYPE */;
   v4tag2 = ecl_function_dispatch(cl_env_copy,VV[48])(1, v2t2) /*  SAFE-CANONICAL-TYPE */;
   T0 = ecl_boole(ECL_BOOLANDC2,(v3tag1),(v4tag2));
   if (!(ecl_zerop(T0))) { goto L16; }
   value0 = v2t2;
   cl_env_copy->nvalues = 1;
   ecl_bds_unwind_n(cl_env_copy,4);
   return value0;
L16:;
   T0 = ecl_boole(ECL_BOOLANDC2,(v4tag2),(v3tag1));
   if (!(ecl_zerop(T0))) { goto L18; }
   value0 = v1t1;
   cl_env_copy->nvalues = 1;
   ecl_bds_unwind_n(cl_env_copy,4);
   return value0;
L18:;
   value0 = cl_list(3, ECL_SYM("OR",614), v1t1, v2t2);
   ecl_bds_unwind_n(cl_env_copy,4);
   return value0;
L9:;
   if (!((v3tag1)==(ECL_SYM("CONS",251)))) { goto L20; }
   ecl_function_dispatch(cl_env_copy,VV[49])(2, _ecl_static_1, v1t1) /*  CMPWARN */;
   value0 = ECL_T;
   cl_env_copy->nvalues = 1;
   ecl_bds_unwind_n(cl_env_copy,4);
   return value0;
L20:;
   if (!((v4tag2)==(ECL_SYM("CONS",251)))) { goto L23; }
   ecl_function_dispatch(cl_env_copy,VV[49])(2, _ecl_static_1, v2t2) /*  CMPWARN */;
   value0 = ECL_T;
   cl_env_copy->nvalues = 1;
   ecl_bds_unwind_n(cl_env_copy,4);
   return value0;
L23:;
   if (!(v3tag1==ECL_NIL)) { goto L26; }
   ecl_function_dispatch(cl_env_copy,VV[50])(2, _ecl_static_4, v1t1) /*  CMPNOTE */;
   value0 = ECL_T;
   cl_env_copy->nvalues = 1;
   ecl_bds_unwind_n(cl_env_copy,4);
   return value0;
L26:;
   ecl_function_dispatch(cl_env_copy,VV[50])(2, _ecl_static_4, v2t2) /*  CMPNOTE */;
   value0 = ECL_T;
   cl_env_copy->nvalues = 1;
   ecl_bds_unwind_n(cl_env_copy,4);
   return value0;
  }
 }
}
/*	function definition for TYPE>=                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L27type__(cl_object v1type1, cl_object v2type2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_subtypep(2, v2type2, v1type1);
  return value0;
 }
}

#include "cmp/cmptype-arith.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclV9elzdkpTg5i9_3PxTOE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPTYPE-ARITH.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclV9elzdkpTg5i9_3PxTOE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 si_do_deftype(3, VV[0], VVtemp[0], ECL_T);
 ecl_cmp_defun(VV[41]);                           /*  MEMBER-TYPE     */
 ecl_cmp_defun(VV[42]);                           /*  OBJECT-TYPE     */
 ecl_cmp_defun(VV[43]);                           /*  VALID-TYPE-SPECIFIER */
 ecl_cmp_defun(VV[44]);                           /*  KNOWN-TYPE-P    */
 ecl_cmp_defun(VV[45]);                           /*  TRIVIAL-TYPE-P  */
 si_Xmake_special(VV[14]);
 cl_set(VV[14],si_make_vector(ECL_T, ecl_make_fixnum(1024), ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0)));
 ecl_cmp_defun(VV[46]);                           /*  TYPE-AND-EMPTY-CACHE */
 ecl_cmp_defun(VV[47]);                           /*  TYPE-AND        */
 ecl_cmp_defun(VV[51]);                           /*  VALUES-NUMBER-FROM-TYPE */
 si_Xmake_special(VV[23]);
 cl_set(VV[23],si_make_vector(ECL_T, ecl_make_fixnum(1024), ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0)));
 ecl_cmp_defun(VV[52]);                           /*  VALUES-TYPE-PRIMARY-TYPE-EMPTY-CACHE */
 ecl_cmp_defun(VV[53]);                           /*  VALUES-TYPE-PRIMARY-TYPE */
 si_Xmake_special(VV[26]);
 cl_set(VV[26],si_make_vector(ECL_T, ecl_make_fixnum(1024), ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0)));
 ecl_cmp_defun(VV[55]);                           /*  VALUES-TYPE-TO-N-TYPES-EMPTY-CACHE */
 ecl_cmp_defun(VV[56]);                           /*  VALUES-TYPE-TO-N-TYPES */
 ecl_cmp_defun(VV[57]);                           /*  SPLIT-VALUES-TYPE */
 si_Xmake_special(VV[30]);
 cl_set(VV[30],si_make_vector(ECL_T, ecl_make_fixnum(1024), ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0)));
 ecl_cmp_defun(VV[58]);                           /*  VALUES-TYPE-OR-EMPTY-CACHE */
 ecl_cmp_defun(VV[59]);                           /*  VALUES-TYPE-OR  */
 si_Xmake_special(VV[34]);
 cl_set(VV[34],si_make_vector(ECL_T, ecl_make_fixnum(1024), ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0)));
 ecl_cmp_defun(VV[60]);                           /*  VALUES-TYPE-AND-EMPTY-CACHE */
 ecl_cmp_defun(VV[61]);                           /*  VALUES-TYPE-AND */
 si_Xmake_special(VV[37]);
 cl_set(VV[37],si_make_vector(ECL_T, ecl_make_fixnum(1024), ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0)));
 ecl_cmp_defun(VV[62]);                           /*  TYPE-OR-EMPTY-CACHE */
 ecl_cmp_defun(VV[63]);                           /*  TYPE-OR         */
 ecl_cmp_defun(VV[64]);                           /*  TYPE>=          */
}
