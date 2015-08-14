/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:LSP;SEQLIB.LSP                                    */
#include <ecl/ecl-cmp.h>
#include "lsp/seqlib.eclh"
/*	function definition for SEQTYPE                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1seqtype(cl_object v1sequence)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_LISTP(v1sequence))) { goto L1; }
  value0 = ECL_SYM("LIST",481);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (Null(si_base_string_p(v1sequence))) { goto L3; }
  value0 = ECL_SYM("BASE-STRING",121);
  cl_env_copy->nvalues = 1;
  return value0;
L3:;
  if (!(ECL_STRINGP(v1sequence))) { goto L5; }
  value0 = ECL_SYM("STRING",805);
  cl_env_copy->nvalues = 1;
  return value0;
L5:;
  if (!(ECL_BIT_VECTOR_P(v1sequence))) { goto L7; }
  value0 = ECL_SYM("BIT-VECTOR",134);
  cl_env_copy->nvalues = 1;
  return value0;
L7:;
  if (!(ECL_VECTORP(v1sequence))) { goto L9; }
  T0 = cl_array_element_type(v1sequence);
  value0 = cl_list(2, ECL_SYM("VECTOR",898), T0);
  return value0;
L9:;
  value0 = cl_error(2, _ecl_static_1, v1sequence);
  return value0;
 }
}
/*	function definition for SEQUENCE-COUNT                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_sequence_count(cl_object v1count)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(v1count==ECL_NIL)) { goto L1; }
  value0 = ecl_make_fixnum(536870911);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (!(ECL_FIXNUMP(v1count))) { goto L3; }
  value0 = v1count;
  cl_env_copy->nvalues = 1;
  return value0;
L3:;
  if (!(ECL_FIXNUMP(v1count)||ECL_BIGNUMP(v1count))) { goto L5; }
  if (!(ecl_minusp(v1count))) { goto L7; }
  value0 = ecl_make_fixnum(-1);
  cl_env_copy->nvalues = 1;
  return value0;
L7:;
  value0 = ecl_make_fixnum(536870911);
  cl_env_copy->nvalues = 1;
  return value0;
L5:;
  T0 = ecl_list1(v1count);
  value0 = cl_error(9, ECL_SYM("SIMPLE-TYPE-ERROR",773), ECL_SYM("DATUM",1214), v1count, ECL_SYM("EXPECTED-TYPE",1232), ECL_SYM("INTEGER",437), ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_2, ECL_SYM("FORMAT-ARGUMENTS",1239), T0);
  return value0;
 }
}
/*	function definition for TEST-ERROR                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2test_error()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_error(1, _ecl_static_3);
  return value0;
 }
}
/*	function definition for UNSAFE-FUNCALL1                       */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object L3unsafe_funcall1(cl_object v1f, cl_object v2x)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 value0 = (cl_env_copy->function=v1f)->cfun.entry(1, v2x);
 return value0;
}
/*	function definition for REDUCE                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_reduce(cl_narg narg, cl_object v1function, cl_object v2sequence, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3from_end;
  cl_object v4start;
  cl_object v5end;
  cl_object v6key;
  cl_object v7initial_value;
  cl_object v8ivsp;
  ecl_va_list args; ecl_va_start(args,v2sequence,narg,2);
  {
   cl_object keyvars[10];
   cl_parse_key(args,5,cl_reducekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3from_end = keyvars[0];
   if (Null(keyvars[6])) {
    v4start = ecl_make_fixnum(0);
   } else {
    v4start = keyvars[1];
   }
   v5end = keyvars[2];
   v6key = keyvars[3];
   v7initial_value = keyvars[4];
   v8ivsp = keyvars[9];
  }
  {
   cl_object v9function;
   v9function = si_coerce_to_function(v1function);
   {
    cl_fixnum v11;                                /*  START           */
    cl_fixnum v12;                                /*  END             */
    value0 = si_sequence_start_end(ECL_SYM("SUBSEQ",829), v2sequence, v4start, v5end);
    v11 = ecl_fixnum(value0);
    v12 = ecl_fixnum(cl_env_copy->values[1]);
    {
     cl_object v13key;
     if (Null(v6key)) { goto L5; }
     v13key = si_coerce_to_function(v6key);
     goto L4;
L5:;
     v13key = (ECL_SYM("IDENTITY",426)->symbol.gfdef);
L4:;
     if (!((v11)>=(v12))) { goto L7; }
     if (Null(v8ivsp)) { goto L9; }
     value0 = v7initial_value;
     cl_env_copy->nvalues = 1;
     return value0;
L9:;
     value0 = (cl_env_copy->function=v9function)->cfun.entry(0);
     return value0;
L7:;
     if (!(ECL_LISTP(v2sequence))) { goto L11; }
     if (Null(v3from_end)) { goto L13; }
     {
      cl_object v14output;
      v14output = ECL_NIL;
      {
       cl_fixnum v15;
       cl_object v16;
       cl_fixnum v17;
       v15 = v11;
       v16 = ecl_nthcdr(v15,v2sequence);
       v17 = (v12)-(v15);
       goto L22;
L21:;
       {
        cl_object v18elt;
        v18elt = ECL_CONS_CAR(v16);
        v14output = CONS(v18elt,v14output);
       }
       v15 = (v15)+1;
       v16 = ECL_CONS_CDR(v16);
       v17 = (v17)-1;
L22:;
       if ((v17)<=(0)) { goto L33; }
       goto L21;
L33:;
      }
      v2sequence = v14output;
      v12 = (v12)-(v11);
      v11 = 0;
     }
L13:;
     goto L42;
L41:;
     v2sequence = ECL_CONS_CDR(v2sequence);
     v11 = (v11)-1;
     v12 = (v12)-1;
L42:;
     if (!((v11)>0)) { goto L50; }
     goto L41;
L50:;
     if ((v8ivsp)!=ECL_NIL) { goto L52; }
     T0 = ECL_CONS_CAR(v2sequence);
     v7initial_value = (cl_env_copy->function=v13key)->cfun.entry(1, T0);
     v2sequence = ECL_CONS_CDR(v2sequence);
     v12 = (v12)-1;
L52:;
     {
      cl_fixnum v14;
      cl_object v15;
      cl_fixnum v16;
      v14 = 0;
      v15 = ecl_nthcdr(v14,v2sequence);
      v16 = (v12)-(v14);
      goto L64;
L63:;
      {
       cl_object v17elt;
       v17elt = ECL_CONS_CAR(v15);
       if (Null(v3from_end)) { goto L69; }
       T0 = (cl_env_copy->function=v13key)->cfun.entry(1, v17elt);
       v7initial_value = (cl_env_copy->function=v9function)->cfun.entry(2, T0, v7initial_value);
       goto L68;
L69:;
       T0 = (cl_env_copy->function=v13key)->cfun.entry(1, v17elt);
       v7initial_value = (cl_env_copy->function=v9function)->cfun.entry(2, v7initial_value, T0);
L68:;
      }
      v14 = (v14)+1;
      v15 = ECL_CONS_CDR(v15);
      v16 = (v16)-1;
L64:;
      if ((v16)<=(0)) { goto L79; }
      goto L63;
L79:;
      value0 = v7initial_value;
      cl_env_copy->nvalues = 1;
      return value0;
     }
L11:;
     if (Null(v3from_end)) { goto L81; }
     if ((v8ivsp)!=ECL_NIL) { goto L83; }
     {
      cl_fixnum v17;
      v17 = (v12)-1;
      T0 = ecl_aref_unsafe(v2sequence,v17);
     }
     v7initial_value = (cl_env_copy->function=v13key)->cfun.entry(1, T0);
     v12 = (v12)-1;
L83:;
     {
      cl_fixnum v17;
      v17 = v12;
      goto L92;
L91:;
      {
       cl_object v18elt;
       v17 = (v17)-1;
       v18elt = ecl_aref_unsafe(v2sequence,v17);
       T0 = (cl_env_copy->function=v13key)->cfun.entry(1, v18elt);
       v7initial_value = (cl_env_copy->function=v9function)->cfun.entry(2, T0, v7initial_value);
      }
L92:;
      if ((v17)==(v11)) { goto L99; }
      goto L91;
L99:;
      value0 = v7initial_value;
      cl_env_copy->nvalues = 1;
      return value0;
     }
L81:;
     if ((v8ivsp)!=ECL_NIL) { goto L101; }
     T0 = ecl_aref_unsafe(v2sequence,v11);
     v7initial_value = (cl_env_copy->function=v13key)->cfun.entry(1, T0);
     v11 = (v11)+1;
L101:;
     {
      cl_fixnum v18;
      v18 = v11;
      goto L110;
L109:;
      {
       cl_object v19elt;
       v19elt = ecl_aref_unsafe(v2sequence,v18);
       T0 = (cl_env_copy->function=v13key)->cfun.entry(1, v19elt);
       v7initial_value = (cl_env_copy->function=v9function)->cfun.entry(2, v7initial_value, T0);
      }
      v18 = (v18)+1;
L110:;
      if ((v18)==(v12)) { goto L118; }
      goto L109;
L118:;
      value0 = v7initial_value;
      cl_env_copy->nvalues = 1;
      return value0;
     }
    }
   }
  }
 }
}
/*	function definition for FILL                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_fill(cl_narg narg, cl_object v1sequence, cl_object v2item, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3start;
  cl_object v4end;
  ecl_va_list args; ecl_va_start(args,v2item,narg,2);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,cl_fillkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[2])) {
    v3start = ecl_make_fixnum(0);
   } else {
    v3start = keyvars[0];
   }
   v4end = keyvars[1];
  }
  {
   cl_fixnum v6;                                  /*  START           */
   cl_fixnum v7;                                  /*  END             */
   value0 = si_sequence_start_end(ECL_SYM("SUBSEQ",829), v1sequence, v3start, v4end);
   v6 = ecl_fixnum(value0);
   v7 = ecl_fixnum(cl_env_copy->values[1]);
   if (!(ECL_LISTP(v1sequence))) { goto L3; }
   {
    cl_object v8x;
    cl_fixnum v9i;
    v8x = ecl_nthcdr(v6,v1sequence);
    v9i = (v7)-(v6);
    goto L9;
L8:;
    (ECL_CONS_CAR(v8x)=v2item,v8x);
    v8x = ECL_CONS_CDR(v8x);
    v9i = (v9i)-1;
L9:;
    if ((v9i)==0) { goto L17; }
    goto L8;
L17:;
    value0 = v1sequence;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L3:;
   value0 = si_fill_array_with_elt(v1sequence, v2item, ecl_make_fixnum(v6), ecl_make_fixnum(v7));
   return value0;
  }
 }
}
/*	function definition for REPLACE                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_replace(cl_narg narg, cl_object v1sequence1, cl_object v2sequence2, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3start1;
  cl_object v4end1;
  cl_object v5start2;
  cl_object v6end2;
  ecl_va_list args; ecl_va_start(args,v2sequence2,narg,2);
  {
   cl_object keyvars[8];
   cl_parse_key(args,4,cl_replacekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[4])) {
    v3start1 = ecl_make_fixnum(0);
   } else {
    v3start1 = keyvars[0];
   }
   v4end1 = keyvars[1];
   if (Null(keyvars[6])) {
    v5start2 = ecl_make_fixnum(0);
   } else {
    v5start2 = keyvars[2];
   }
   v6end2 = keyvars[3];
  }
  {
   cl_fixnum v8;                                  /*  START1          */
   cl_fixnum v9;                                  /*  END1            */
   value0 = si_sequence_start_end(ECL_SYM("SUBSEQ",829), v1sequence1, v3start1, v4end1);
   v8 = ecl_to_fixnum(value0);
   v9 = ecl_to_fixnum(cl_env_copy->values[1]);
   {
    cl_fixnum v11;                                /*  START2          */
    cl_fixnum v12;                                /*  END2            */
    value0 = si_sequence_start_end(ECL_SYM("SUBSEQ",829), v2sequence2, v5start2, v6end2);
    v11 = ecl_to_fixnum(value0);
    v12 = ecl_to_fixnum(cl_env_copy->values[1]);
    {
     cl_fixnum v13length;
     T0 = ecl_minus(ecl_make_fixnum(v12),ecl_make_fixnum(v11));
     T1 = ecl_minus(ecl_make_fixnum(v9),ecl_make_fixnum(v8));
     v13length = ecl_fixnum((ecl_number_compare(T0,T1)<=0?T0:T1));
     if (!(ECL_VECTORP(v1sequence1))) { goto L7; }
     if (!(ECL_VECTORP(v2sequence2))) { goto L7; }
     ecl_copy_subarray(v1sequence1,v8,v2sequence2,v11,v13length);
     goto L3;
L7:;
     {
      cl_object v14data;
      cl_object v15it2;
      cl_object v16it1;
      if (!((v1sequence1)==(v2sequence2))) { goto L11; }
      if (!((v8)>(v11))) { goto L11; }
      v14data = cl_subseq(3, v2sequence2, ecl_make_fixnum(v11), ecl_make_fixnum(v12));
      goto L10;
L11:;
      v14data = v2sequence2;
L10:;
      v15it2 = si_make_seq_iterator(2, v14data, ecl_make_fixnum(v11));
      v16it1 = si_make_seq_iterator(2, v1sequence1, ecl_make_fixnum(v8));
      goto L18;
L17:;
      T0 = si_seq_iterator_ref(v2sequence2, v15it2);
      si_seq_iterator_set(v1sequence1, v16it1, T0);
      v13length = (v13length)-(1);
      v15it2 = si_seq_iterator_next(v14data, v15it2);
      v16it1 = si_seq_iterator_next(v1sequence1, v16it1);
L18:;
      if ((v13length)<=(0)) { goto L27; }
      if (v16it1==ECL_NIL) { goto L27; }
      if (v15it2==ECL_NIL) { goto L27; }
      goto L17;
L27:;
     }
    }
   }
  }
L3:;
  value0 = v1sequence1;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for FILTER-VECTOR                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4filter_vector(cl_object v1which, cl_object v2out, cl_object v3in, cl_object v4start, cl_object v5end, cl_object v6from_end, cl_object v7count, cl_object v8test, cl_object v9test_not, cl_object v10key)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v11;
   if (Null(v8test)) { goto L2; }
   if (Null(v9test_not)) { goto L4; }
   L2test_error();
L4:;
   v11 = si_coerce_to_function(v8test);
   goto L1;
L2:;
   if (Null(v9test_not)) { goto L6; }
   v11 = si_coerce_to_function(v9test_not);
   goto L1;
L6:;
   v11 = (ECL_SYM("EQL",334)->symbol.gfdef);
L1:;
   {
    cl_object v12key;
    if (Null(v10key)) { goto L9; }
    v12key = si_coerce_to_function(v10key);
    goto L8;
L9:;
    v12key = (ECL_SYM("IDENTITY",426)->symbol.gfdef);
L8:;
    {
     cl_fixnum v14;                               /*  START           */
     cl_fixnum v15;                               /*  END             */
     cl_fixnum v16;                               /*  L               */
     value0 = si_sequence_start_end(ECL_SYM("SUBSEQ",829), v3in, v4start, v5end);
     v14 = ecl_fixnum(value0);
     v15 = ecl_fixnum(cl_env_copy->values[1]);
     v16 = ecl_fixnum(cl_env_copy->values[2]);
     {
      cl_fixnum v17_count;
      v17_count = ecl_fixnum(si_sequence_count(v7count));
      if (!((v17_count)>0)) { goto L13; }
      {
       cl_fixnum v18existing;
       v18existing = 0;
       if ((v2out)==(v3in)) { goto L16; }
       v18existing = ecl_fixnum(cl_count(12, v1which, v3in, ECL_SYM("START",1310), ecl_make_fixnum(v14), ECL_SYM("END",1225), ecl_make_fixnum(v15), ECL_SYM("TEST",1316), v8test, ECL_SYM("TEST-NOT",1317), v9test_not, ECL_SYM("KEY",1262), v12key));
       if (!((v18existing)==0)) { goto L20; }
       cl_env_copy->nvalues = 2;
       cl_env_copy->values[1] = ecl_make_fixnum(v16);
       cl_env_copy->values[0] = v3in;
       return cl_env_copy->values[0];
L20:;
       T0 = cl_array_element_type(v3in);
       {
        cl_fixnum v19;
        v19 = (v18existing)<=(v17_count)?v18existing:v17_count;
        T1 = ecl_minus(ecl_make_fixnum(v16),ecl_make_fixnum(v19));
        v2out = si_make_pure_array(T0, T1, ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
       }
L16:;
       if ((v2out)==(v3in)) { goto L23; }
       ecl_copy_subarray(v2out,0,v3in,0,v14);
L23:;
       {
        cl_fixnum v19skip;
        v19skip = 0;
        if (Null(v6from_end)) { goto L27; }
        if ((v18existing)>0) { goto L29; }
        v18existing = ecl_fixnum(cl_count(12, v1which, v3in, ECL_SYM("START",1310), ecl_make_fixnum(v14), ECL_SYM("END",1225), ecl_make_fixnum(v15), ECL_SYM("TEST",1316), v8test, ECL_SYM("TEST-NOT",1317), v9test_not, ECL_SYM("KEY",1262), v12key));
L29:;
        if (!((v18existing)<(v17_count))) { goto L33; }
        v19skip = 0;
        goto L32;
L33:;
        v19skip = (v18existing)-(v17_count);
L32:;
L27:;
        if (!((v2out)==(v3in))) { goto L35; }
        {
         cl_fixnum v20index;
         v20index = v14;
         goto L40;
L39:;
         {
          cl_object v21elt;
          v21elt = ecl_aref_unsafe(v3in,v20index);
          if (Null(v9test_not)) { goto L47; }
          T0 = (cl_env_copy->function=v12key)->cfun.entry(1, v21elt);
          if (((cl_env_copy->function=v11)->cfun.entry(2, v1which, T0))!=ECL_NIL) { goto L44; }
          goto L46;
L47:;
          T0 = (cl_env_copy->function=v12key)->cfun.entry(1, v21elt);
          if (Null((cl_env_copy->function=v11)->cfun.entry(2, v1which, T0))) { goto L44; }
L46:;
          {
          cl_fixnum v22;
          v19skip = (v19skip)-(1);
          v22 = v19skip;
          if (!((v22)<0)) { goto L44; }
          }
          goto L25;
L44:;
          v14 = (v14)+(1);
         }
         v20index = (v20index)+1;
L40:;
         if ((v20index)==(v15)) { goto L56; }
         goto L39;
L56:;
         goto L25;
        }
L35:;
        {
         cl_fixnum v21index;
         v21index = v14;
         goto L61;
L60:;
         {
          cl_object v22elt;
          v22elt = ecl_aref_unsafe(v3in,v21index);
          if (Null(v9test_not)) { goto L68; }
          T0 = (cl_env_copy->function=v12key)->cfun.entry(1, v22elt);
          if (((cl_env_copy->function=v11)->cfun.entry(2, v1which, T0))!=ECL_NIL) { goto L65; }
          goto L67;
L68:;
          T0 = (cl_env_copy->function=v12key)->cfun.entry(1, v22elt);
          if (Null((cl_env_copy->function=v11)->cfun.entry(2, v1which, T0))) { goto L65; }
L67:;
          {
          cl_fixnum v23;
          v19skip = (v19skip)-(1);
          v23 = v19skip;
          if (!((v23)<0)) { goto L65; }
          }
          goto L25;
L65:;
          ecl_aset_unsafe(v2out,v14,v22elt);
          v14 = (v14)+1;
         }
         v21index = (v21index)+1;
L61:;
         if ((v21index)==(v15)) { goto L78; }
         goto L60;
L78:;
        }
       }
L25:;
       {
        cl_fixnum v19index;
        cl_fixnum v20;
        v19index = v14;
        v20 = v15;
        goto L85;
L84:;
        {
         cl_object v21elt;
         v21elt = ecl_aref_unsafe(v3in,v19index);
         if (Null(v9test_not)) { goto L91; }
         T0 = (cl_env_copy->function=v12key)->cfun.entry(1, v21elt);
         if (((cl_env_copy->function=v11)->cfun.entry(2, v1which, T0))!=ECL_NIL) { goto L89; }
         goto L90;
L91:;
         T0 = (cl_env_copy->function=v12key)->cfun.entry(1, v21elt);
         if (Null((cl_env_copy->function=v11)->cfun.entry(2, v1which, T0))) { goto L89; }
L90:;
         {
          cl_fixnum v22;
          v17_count = (v17_count)-(1);
          v22 = v17_count;
          if (!((v22)==0)) { goto L87; }
         }
         v15 = (v19index)+1;
         goto L80;
L89:;
         ecl_aset_unsafe(v2out,v14,v21elt);
         v14 = (v14)+1;
        }
L87:;
        v19index = (v19index)+1;
L85:;
        if ((v19index)==(v20)) { goto L104; }
        goto L84;
L104:;
       }
L80:;
       ecl_copy_subarray(v2out,v14,v3in,v15,v16);
       T0 = ecl_minus(ecl_make_fixnum(v16),ecl_make_fixnum(v15));
       T1 = ecl_plus(ecl_make_fixnum(v14),T0);
       cl_env_copy->nvalues = 2;
       cl_env_copy->values[1] = T1;
       cl_env_copy->values[0] = v2out;
       return cl_env_copy->values[0];
      }
L13:;
      value0 = v3in;
      cl_env_copy->nvalues = 1;
      return value0;
     }
    }
   }
  }
 }
}
/*	function definition for REMOVE-LIST                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5remove_list(cl_object v1which, cl_object v2sequence, cl_object v3start, cl_object v4end, cl_object v5count, cl_object v6test, cl_object v7test_not, cl_object v8key)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v9;
   if (Null(v6test)) { goto L2; }
   if (Null(v7test_not)) { goto L4; }
   L2test_error();
L4:;
   v9 = si_coerce_to_function(v6test);
   goto L1;
L2:;
   if (Null(v7test_not)) { goto L6; }
   v9 = si_coerce_to_function(v7test_not);
   goto L1;
L6:;
   v9 = (ECL_SYM("EQL",334)->symbol.gfdef);
L1:;
   {
    cl_object v10key;
    if (Null(v8key)) { goto L9; }
    v10key = si_coerce_to_function(v8key);
    goto L8;
L9:;
    v10key = (ECL_SYM("IDENTITY",426)->symbol.gfdef);
L8:;
    {
     cl_fixnum v12;                               /*  START           */
     cl_fixnum v13;                               /*  END             */
     value0 = si_sequence_start_end(ECL_SYM("SUBSEQ",829), v2sequence, v3start, v4end);
     v12 = ecl_fixnum(value0);
     v13 = ecl_fixnum(cl_env_copy->values[1]);
     {
      cl_fixnum v14_count;
      v14_count = ecl_fixnum(si_sequence_count(v5count));
      if (!((v14_count)>0)) { goto L13; }
      {
       cl_object v15output;
       cl_fixnum v16index;
       v15output = ECL_NIL;
       v16index = 0;
       goto L19;
L18:;
       T0 = ECL_CONS_CAR(v2sequence);
       v15output = CONS(T0,v15output);
       v2sequence = ECL_CONS_CDR(v2sequence);
       v16index = (v16index)+1;
L19:;
       if (Null(v2sequence)) { goto L27; }
       if (!((v16index)<(v12))) { goto L27; }
       goto L18;
L27:;
L31:;
       if ((v16index)<(v13)) { goto L33; }
       goto L30;
L33:;
       {
        cl_object v17elt;
        v17elt = ECL_CONS_CAR(v2sequence);
        v2sequence = ECL_CONS_CDR(v2sequence);
        if (Null(v7test_not)) { goto L41; }
        T0 = (cl_env_copy->function=v10key)->cfun.entry(1, v17elt);
        if (((cl_env_copy->function=v9)->cfun.entry(2, v1which, T0))!=ECL_NIL) { goto L39; }
        goto L40;
L41:;
        T0 = (cl_env_copy->function=v10key)->cfun.entry(1, v17elt);
        if (Null((cl_env_copy->function=v9)->cfun.entry(2, v1which, T0))) { goto L39; }
L40:;
        {
         cl_fixnum v18;
         v14_count = (v14_count)-(1);
         v18 = v14_count;
         if (!((v18)==0)) { goto L38; }
        }
        goto L30;
L39:;
        v15output = CONS(v17elt,v15output);
L38:;
        v16index = (v16index)+(1);
       }
       goto L31;
L30:;
       value0 = cl_nreconc(v15output, v2sequence);
       return value0;
      }
L13:;
      value0 = v2sequence;
      cl_env_copy->nvalues = 1;
      return value0;
     }
    }
   }
  }
 }
}
/*	function definition for REMOVE                                */
/*	optimize speed 3, debug 0, space 1, safety 1                  */
cl_object cl_remove(cl_narg narg, cl_object v1which, cl_object v2sequence, ...)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3test;
  cl_object v4test_not;
  cl_object v5start;
  cl_object v6end;
  cl_object v7from_end;
  cl_object v8count;
  cl_object v9key;
  ecl_va_list args; ecl_va_start(args,v2sequence,narg,2);
  {
   cl_object keyvars[14];
   cl_parse_key(args,7,cl_removekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3test = keyvars[0];
   v4test_not = keyvars[1];
   if (Null(keyvars[9])) {
    v5start = ecl_make_fixnum(0);
   } else {
    v5start = keyvars[2];
   }
   v6end = keyvars[3];
   v7from_end = keyvars[4];
   v8count = keyvars[5];
   v9key = keyvars[6];
  }
  if (ecl_unlikely(!(ECL_LISTP(v2sequence) || ECL_VECTORP(v2sequence))))
           FEtype_error_sequence(v2sequence);
  if (!(ECL_LISTP(v2sequence))) { goto L3; }
  if (Null(v7from_end)) { goto L5; }
  {
   cl_fixnum v10l;
   v10l = ecl_length(v2sequence);
   T0 = cl_reverse(v2sequence);
   if (Null(v6end)) { goto L9; }
   T1 = ecl_minus(ecl_make_fixnum(v10l),v6end);
   goto L8;
L9:;
   T1 = ecl_make_fixnum(0);
L8:;
   T2 = ecl_minus(ecl_make_fixnum(v10l),v5start);
   T3 = cl_delete(16, v1which, T0, ECL_SYM("START",1310), T1, ECL_SYM("END",1225), T2, VV[4], ECL_NIL, ECL_SYM("TEST",1316), v3test, ECL_SYM("TEST-NOT",1317), v4test_not, ECL_SYM("KEY",1262), v9key, ECL_SYM("COUNT",1450), v8count);
   value0 = cl_nreverse(T3);
   return value0;
  }
L5:;
  value0 = L5remove_list(v1which, v2sequence, v5start, v6end, v8count, v3test, v4test_not, v9key);
  return value0;
L3:;
  value0 = L4filter_vector(v1which, ECL_NIL, v2sequence, v5start, v6end, v7from_end, v8count, v3test, v4test_not, v9key);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for REMOVE-IF                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_remove_if(cl_narg narg, cl_object v1predicate, cl_object v2sequence, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3start;
  cl_object v4end;
  cl_object v5from_end;
  cl_object v6count;
  cl_object v7key;
  ecl_va_list args; ecl_va_start(args,v2sequence,narg,2);
  {
   cl_object keyvars[10];
   cl_parse_key(args,5,cl_remove_ifkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[5])) {
    v3start = ecl_make_fixnum(0);
   } else {
    v3start = keyvars[0];
   }
   v4end = keyvars[1];
   v5from_end = keyvars[2];
   v6count = keyvars[3];
   v7key = keyvars[4];
  }
  T0 = si_coerce_to_function(v1predicate);
  T1 = (VV[1]->symbol.gfdef);
  value0 = cl_remove(14, T0, v2sequence, ECL_SYM("START",1310), v3start, ECL_SYM("END",1225), v4end, VV[4], v5from_end, ECL_SYM("COUNT",1450), v6count, ECL_SYM("TEST",1316), T1, ECL_SYM("KEY",1262), v7key);
  return value0;
 }
}
/*	function definition for REMOVE-IF-NOT                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_remove_if_not(cl_narg narg, cl_object v1predicate, cl_object v2sequence, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3start;
  cl_object v4end;
  cl_object v5from_end;
  cl_object v6count;
  cl_object v7key;
  ecl_va_list args; ecl_va_start(args,v2sequence,narg,2);
  {
   cl_object keyvars[10];
   cl_parse_key(args,5,cl_remove_if_notkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[5])) {
    v3start = ecl_make_fixnum(0);
   } else {
    v3start = keyvars[0];
   }
   v4end = keyvars[1];
   v5from_end = keyvars[2];
   v6count = keyvars[3];
   v7key = keyvars[4];
  }
  T0 = si_coerce_to_function(v1predicate);
  T1 = (VV[1]->symbol.gfdef);
  value0 = cl_remove(14, T0, v2sequence, ECL_SYM("START",1310), v3start, ECL_SYM("END",1225), v4end, VV[4], v5from_end, ECL_SYM("COUNT",1450), v6count, ECL_SYM("TEST-NOT",1317), T1, ECL_SYM("KEY",1262), v7key);
  return value0;
 }
}
/*	function definition for DELETE-LIST                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6delete_list(cl_object v1which, cl_object v2sequence, cl_object v3start, cl_object v4end, cl_object v5count, cl_object v6test, cl_object v7test_not, cl_object v8key)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v9;
   if (Null(v6test)) { goto L2; }
   if (Null(v7test_not)) { goto L4; }
   L2test_error();
L4:;
   v9 = si_coerce_to_function(v6test);
   goto L1;
L2:;
   if (Null(v7test_not)) { goto L6; }
   v9 = si_coerce_to_function(v7test_not);
   goto L1;
L6:;
   v9 = (ECL_SYM("EQL",334)->symbol.gfdef);
L1:;
   {
    cl_object v10key;
    if (Null(v8key)) { goto L9; }
    v10key = si_coerce_to_function(v8key);
    goto L8;
L9:;
    v10key = (ECL_SYM("IDENTITY",426)->symbol.gfdef);
L8:;
    {
     cl_fixnum v12;                               /*  START           */
     cl_fixnum v13;                               /*  END             */
     value0 = si_sequence_start_end(ECL_SYM("SUBSEQ",829), v2sequence, v3start, v4end);
     v12 = ecl_fixnum(value0);
     v13 = ecl_fixnum(cl_env_copy->values[1]);
     {
      cl_fixnum v14_count;
      v14_count = ecl_fixnum(si_sequence_count(v5count));
      if (!((v14_count)>0)) { goto L13; }
      {
       cl_object v15splice;
       cl_object v16output;
       cl_fixnum v17index;
       v15splice = CONS(ECL_NIL,v2sequence);
       v16output = v15splice;
       v17index = 0;
       goto L20;
L19:;
       v2sequence = ECL_CONS_CDR(v2sequence);
       v15splice = ECL_CONS_CDR(v15splice);
       v17index = (v17index)+1;
L20:;
       if (Null(v2sequence)) { goto L28; }
       if (!((v17index)<(v12))) { goto L28; }
       goto L19;
L28:;
L32:;
       if ((v17index)<(v13)) { goto L34; }
       goto L31;
L34:;
       {
        cl_object v18elt;
        v18elt = ECL_CONS_CAR(v2sequence);
        v2sequence = ECL_CONS_CDR(v2sequence);
        if (Null(v7test_not)) { goto L42; }
        T0 = (cl_env_copy->function=v10key)->cfun.entry(1, v18elt);
        if (((cl_env_copy->function=v9)->cfun.entry(2, v1which, T0))!=ECL_NIL) { goto L40; }
        goto L41;
L42:;
        T0 = (cl_env_copy->function=v10key)->cfun.entry(1, v18elt);
        if (Null((cl_env_copy->function=v9)->cfun.entry(2, v1which, T0))) { goto L40; }
L41:;
        (ECL_CONS_CDR(v15splice)=v2sequence,v15splice);
        {
         cl_fixnum v19;
         v14_count = (v14_count)-(1);
         v19 = v14_count;
         if (!((v19)==0)) { goto L39; }
        }
        goto L31;
L40:;
        v15splice = ECL_CONS_CDR(v15splice);
L39:;
        v17index = (v17index)+(1);
       }
       goto L32;
L31:;
       value0 = ECL_CONS_CDR(v16output);
       cl_env_copy->nvalues = 1;
       return value0;
      }
L13:;
      value0 = v2sequence;
      cl_env_copy->nvalues = 1;
      return value0;
     }
    }
   }
  }
 }
}
/*	function definition for DELETE                                */
/*	optimize speed 3, debug 0, space 1, safety 1                  */
cl_object cl_delete(cl_narg narg, cl_object v1which, cl_object v2sequence, ...)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3test;
  cl_object v4test_not;
  cl_object v5start;
  cl_object v6end;
  cl_object v7from_end;
  cl_object v8count;
  cl_object v9key;
  ecl_va_list args; ecl_va_start(args,v2sequence,narg,2);
  {
   cl_object keyvars[14];
   cl_parse_key(args,7,cl_deletekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3test = keyvars[0];
   v4test_not = keyvars[1];
   if (Null(keyvars[9])) {
    v5start = ecl_make_fixnum(0);
   } else {
    v5start = keyvars[2];
   }
   v6end = keyvars[3];
   v7from_end = keyvars[4];
   v8count = keyvars[5];
   v9key = keyvars[6];
  }
  if (!(ECL_LISTP(v2sequence))) { goto L2; }
  if (Null(v7from_end)) { goto L4; }
  {
   cl_fixnum v10l;
   v10l = ecl_length(v2sequence);
   T0 = cl_nreverse(v2sequence);
   if (Null(v6end)) { goto L8; }
   T1 = ecl_minus(ecl_make_fixnum(v10l),v6end);
   goto L7;
L8:;
   T1 = ecl_make_fixnum(0);
L7:;
   T2 = ecl_minus(ecl_make_fixnum(v10l),v5start);
   T3 = L6delete_list(v1which, T0, T1, T2, v8count, v3test, v4test_not, v9key);
   value0 = cl_nreverse(T3);
   return value0;
  }
L4:;
  value0 = L6delete_list(v1which, v2sequence, v5start, v6end, v8count, v3test, v4test_not, v9key);
  return value0;
L2:;
  if (ECL_VECTORP(v2sequence)) { goto L10; }
  value0 = si_signal_type_error(v2sequence, ECL_SYM("SEQUENCE",741));
  return value0;
L10:;
  if (!(ECL_ARRAY_HAS_FILL_POINTER_P(v2sequence))) { goto L12; }
  {
   cl_object v12;                                 /*  SEQUENCE        */
   cl_object v13;                                 /*  L               */
   value0 = L4filter_vector(v1which, v2sequence, v2sequence, v5start, v6end, v7from_end, v8count, v3test, v4test_not, v9key);
   v12 = value0;
   {
    const int v14 = cl_env_copy->nvalues;
    cl_object v15;
    v15 = (v14<=1)? ECL_NIL : cl_env_copy->values[1];
    v13 = v15;
   }
   si_fill_pointer_set(v12, v13);
   value0 = v12;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L12:;
  value0 = L4filter_vector(v1which, ECL_NIL, v2sequence, v5start, v6end, v7from_end, v8count, v3test, v4test_not, v9key);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for DELETE-IF                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_delete_if(cl_narg narg, cl_object v1predicate, cl_object v2sequence, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3start;
  cl_object v4end;
  cl_object v5from_end;
  cl_object v6count;
  cl_object v7key;
  ecl_va_list args; ecl_va_start(args,v2sequence,narg,2);
  {
   cl_object keyvars[10];
   cl_parse_key(args,5,cl_delete_ifkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[5])) {
    v3start = ecl_make_fixnum(0);
   } else {
    v3start = keyvars[0];
   }
   v4end = keyvars[1];
   v5from_end = keyvars[2];
   v6count = keyvars[3];
   v7key = keyvars[4];
  }
  T0 = si_coerce_to_function(v1predicate);
  T1 = (VV[1]->symbol.gfdef);
  value0 = cl_delete(14, T0, v2sequence, ECL_SYM("START",1310), v3start, ECL_SYM("END",1225), v4end, VV[4], v5from_end, ECL_SYM("COUNT",1450), v6count, ECL_SYM("TEST",1316), T1, ECL_SYM("KEY",1262), v7key);
  return value0;
 }
}
/*	function definition for DELETE-IF-NOT                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_delete_if_not(cl_narg narg, cl_object v1predicate, cl_object v2sequence, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3start;
  cl_object v4end;
  cl_object v5from_end;
  cl_object v6count;
  cl_object v7key;
  ecl_va_list args; ecl_va_start(args,v2sequence,narg,2);
  {
   cl_object keyvars[10];
   cl_parse_key(args,5,cl_delete_if_notkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[5])) {
    v3start = ecl_make_fixnum(0);
   } else {
    v3start = keyvars[0];
   }
   v4end = keyvars[1];
   v5from_end = keyvars[2];
   v6count = keyvars[3];
   v7key = keyvars[4];
  }
  T0 = si_coerce_to_function(v1predicate);
  T1 = (VV[1]->symbol.gfdef);
  value0 = cl_delete(14, T0, v2sequence, ECL_SYM("START",1310), v3start, ECL_SYM("END",1225), v4end, VV[4], v5from_end, ECL_SYM("COUNT",1450), v6count, ECL_SYM("TEST-NOT",1317), T1, ECL_SYM("KEY",1262), v7key);
  return value0;
 }
}
/*	function definition for COUNT                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_count(cl_narg narg, cl_object v1item, cl_object v2sequence, ...)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3test;
  cl_object v4test_not;
  cl_object v5from_end;
  cl_object v6start;
  cl_object v7end;
  cl_object v8key;
  ecl_va_list args; ecl_va_start(args,v2sequence,narg,2);
  {
   cl_object keyvars[12];
   cl_parse_key(args,6,cl_countkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3test = keyvars[0];
   v4test_not = keyvars[1];
   v5from_end = keyvars[2];
   if (Null(keyvars[9])) {
    v6start = ecl_make_fixnum(0);
   } else {
    v6start = keyvars[3];
   }
   v7end = keyvars[4];
   v8key = keyvars[5];
  }
  {
   cl_object v9;
   if (Null(v3test)) { goto L3; }
   if (Null(v4test_not)) { goto L5; }
   L2test_error();
L5:;
   v9 = si_coerce_to_function(v3test);
   goto L2;
L3:;
   if (Null(v4test_not)) { goto L7; }
   v9 = si_coerce_to_function(v4test_not);
   goto L2;
L7:;
   v9 = (ECL_SYM("EQL",334)->symbol.gfdef);
L2:;
   {
    cl_object v10key;
    if (Null(v8key)) { goto L10; }
    v10key = si_coerce_to_function(v8key);
    goto L9;
L10:;
    v10key = (ECL_SYM("IDENTITY",426)->symbol.gfdef);
L9:;
    {
     cl_fixnum v12;                               /*  START           */
     cl_fixnum v13;                               /*  END             */
     cl_fixnum v14;                               /*  L               */
     value0 = si_sequence_start_end(ECL_SYM("SUBSEQ",829), v2sequence, v6start, v7end);
     v12 = ecl_fixnum(value0);
     v13 = ecl_fixnum(cl_env_copy->values[1]);
     v14 = ecl_fixnum(cl_env_copy->values[2]);
     {
      cl_fixnum v15counter;
      v15counter = 0;
      if (Null(v5from_end)) { goto L14; }
      if (!(ECL_LISTP(v2sequence))) { goto L16; }
      T0 = cl_reverse(v2sequence);
      T1 = ecl_minus(ecl_make_fixnum(v14),ecl_make_fixnum(v13));
      T2 = ecl_minus(ecl_make_fixnum(v14),ecl_make_fixnum(v12));
      value0 = cl_count(12, v1item, T0, ECL_SYM("START",1310), T1, ECL_SYM("END",1225), T2, ECL_SYM("TEST",1316), v3test, ECL_SYM("TEST-NOT",1317), v4test_not, ECL_SYM("KEY",1262), v10key);
      return value0;
L16:;
      {
       cl_fixnum v16;
       v16 = v13;
       goto L21;
L20:;
       {
        cl_object v17elt;
        v16 = (v16)-1;
        v17elt = ecl_aref_unsafe(v2sequence,v16);
        if (Null(v4test_not)) { goto L27; }
        T0 = (cl_env_copy->function=v10key)->cfun.entry(1, v17elt);
        if (((cl_env_copy->function=v9)->cfun.entry(2, v1item, T0))!=ECL_NIL) { goto L23; }
        goto L26;
L27:;
        T0 = (cl_env_copy->function=v10key)->cfun.entry(1, v17elt);
        if (Null((cl_env_copy->function=v9)->cfun.entry(2, v1item, T0))) { goto L23; }
L26:;
        v15counter = (v15counter)+(1);
       }
L23:;
L21:;
       if ((v16)==(v12)) { goto L32; }
       goto L20;
L32:;
       value0 = ecl_make_fixnum(v15counter);
       cl_env_copy->nvalues = 1;
       return value0;
      }
L14:;
      if (!(ECL_LISTP(v2sequence))) { goto L34; }
      {
       cl_fixnum v17;
       cl_object v18;
       cl_fixnum v19;
       v17 = v12;
       v18 = ecl_nthcdr(v17,v2sequence);
       v19 = (v13)-(v17);
       goto L41;
L40:;
       {
        cl_object v20elt;
        v20elt = ECL_CONS_CAR(v18);
        if (Null(v4test_not)) { goto L46; }
        T0 = (cl_env_copy->function=v10key)->cfun.entry(1, v20elt);
        if (((cl_env_copy->function=v9)->cfun.entry(2, v1item, T0))!=ECL_NIL) { goto L43; }
        goto L45;
L46:;
        T0 = (cl_env_copy->function=v10key)->cfun.entry(1, v20elt);
        if (Null((cl_env_copy->function=v9)->cfun.entry(2, v1item, T0))) { goto L43; }
L45:;
        v15counter = (v15counter)+(1);
       }
L43:;
       v17 = (v17)+1;
       v18 = ECL_CONS_CDR(v18);
       v19 = (v19)-1;
L41:;
       if ((v19)<=(0)) { goto L57; }
       goto L40;
L57:;
       value0 = ecl_make_fixnum(v15counter);
       cl_env_copy->nvalues = 1;
       return value0;
      }
L34:;
      {
       cl_fixnum v20;
       v20 = v12;
       goto L62;
L61:;
       {
        cl_object v21elt;
        v21elt = ecl_aref_unsafe(v2sequence,v20);
        if (Null(v4test_not)) { goto L67; }
        T0 = (cl_env_copy->function=v10key)->cfun.entry(1, v21elt);
        if (((cl_env_copy->function=v9)->cfun.entry(2, v1item, T0))!=ECL_NIL) { goto L64; }
        goto L66;
L67:;
        T0 = (cl_env_copy->function=v10key)->cfun.entry(1, v21elt);
        if (Null((cl_env_copy->function=v9)->cfun.entry(2, v1item, T0))) { goto L64; }
L66:;
        v15counter = (v15counter)+(1);
       }
L64:;
       v20 = (v20)+1;
L62:;
       if ((v20)==(v13)) { goto L74; }
       goto L61;
L74:;
       value0 = ecl_make_fixnum(v15counter);
       cl_env_copy->nvalues = 1;
       return value0;
      }
     }
    }
   }
  }
 }
}
/*	function definition for COUNT-IF                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_count_if(cl_narg narg, cl_object v1predicate, cl_object v2sequence, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3from_end;
  cl_object v4start;
  cl_object v5end;
  cl_object v6key;
  ecl_va_list args; ecl_va_start(args,v2sequence,narg,2);
  {
   cl_object keyvars[8];
   cl_parse_key(args,4,cl_count_ifkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3from_end = keyvars[0];
   if (Null(keyvars[5])) {
    v4start = ecl_make_fixnum(0);
   } else {
    v4start = keyvars[1];
   }
   v5end = keyvars[2];
   v6key = keyvars[3];
  }
  T0 = si_coerce_to_function(v1predicate);
  T1 = (VV[1]->symbol.gfdef);
  value0 = cl_count(12, T0, v2sequence, VV[4], v3from_end, ECL_SYM("START",1310), v4start, ECL_SYM("END",1225), v5end, ECL_SYM("TEST",1316), T1, ECL_SYM("KEY",1262), v6key);
  return value0;
 }
}
/*	function definition for COUNT-IF-NOT                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_count_if_not(cl_narg narg, cl_object v1predicate, cl_object v2sequence, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3from_end;
  cl_object v4start;
  cl_object v5end;
  cl_object v6key;
  ecl_va_list args; ecl_va_start(args,v2sequence,narg,2);
  {
   cl_object keyvars[8];
   cl_parse_key(args,4,cl_count_if_notkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3from_end = keyvars[0];
   if (Null(keyvars[5])) {
    v4start = ecl_make_fixnum(0);
   } else {
    v4start = keyvars[1];
   }
   v5end = keyvars[2];
   v6key = keyvars[3];
  }
  T0 = si_coerce_to_function(v1predicate);
  T1 = (VV[1]->symbol.gfdef);
  value0 = cl_count(12, T0, v2sequence, VV[4], v3from_end, ECL_SYM("START",1310), v4start, ECL_SYM("END",1225), v5end, ECL_SYM("TEST-NOT",1317), T1, ECL_SYM("KEY",1262), v6key);
  return value0;
 }
}
/*	function definition for SUBSTITUTE                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_substitute(cl_narg narg, cl_object v1new, cl_object v2old, cl_object v3sequence, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 {
  cl_object v4test;
  cl_object v5test_not;
  cl_object v6start;
  cl_object v7end;
  cl_object v8from_end;
  cl_object v9count;
  cl_object v10key;
  ecl_va_list args; ecl_va_start(args,v3sequence,narg,3);
  {
   cl_object keyvars[14];
   cl_parse_key(args,7,cl_substitutekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v4test = keyvars[0];
   v5test_not = keyvars[1];
   if (Null(keyvars[9])) {
    v6start = ecl_make_fixnum(0);
   } else {
    v6start = keyvars[2];
   }
   v7end = keyvars[3];
   v8from_end = keyvars[4];
   v9count = keyvars[5];
   v10key = keyvars[6];
  }
  T0 = ecl_copy_seq(v3sequence);
  value0 = cl_nsubstitute(17, v1new, v2old, T0, ECL_SYM("START",1310), v6start, ECL_SYM("END",1225), v7end, VV[4], v8from_end, ECL_SYM("COUNT",1450), v9count, ECL_SYM("KEY",1262), v10key, ECL_SYM("TEST",1316), v4test, ECL_SYM("TEST-NOT",1317), v5test_not);
  return value0;
 }
}
/*	function definition for SUBSTITUTE-IF                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_substitute_if(cl_narg narg, cl_object v1new, cl_object v2predicate, cl_object v3sequence, ...)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 {
  cl_object v4start;
  cl_object v5end;
  cl_object v6from_end;
  cl_object v7count;
  cl_object v8key;
  ecl_va_list args; ecl_va_start(args,v3sequence,narg,3);
  {
   cl_object keyvars[10];
   cl_parse_key(args,5,cl_substitute_ifkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[5])) {
    v4start = ecl_make_fixnum(0);
   } else {
    v4start = keyvars[0];
   }
   v5end = keyvars[1];
   v6from_end = keyvars[2];
   v7count = keyvars[3];
   v8key = keyvars[4];
  }
  T0 = si_coerce_to_function(v2predicate);
  T1 = ecl_copy_seq(v3sequence);
  T2 = (VV[1]->symbol.gfdef);
  value0 = cl_nsubstitute(17, v1new, T0, T1, ECL_SYM("KEY",1262), v8key, ECL_SYM("TEST",1316), T2, ECL_SYM("START",1310), v4start, ECL_SYM("END",1225), v5end, VV[4], v6from_end, ECL_SYM("COUNT",1450), v7count, ECL_SYM("KEY",1262), v8key);
  return value0;
 }
}
/*	function definition for SUBSTITUTE-IF-NOT                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_substitute_if_not(cl_narg narg, cl_object v1new, cl_object v2predicate, cl_object v3sequence, ...)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 {
  cl_object v4start;
  cl_object v5end;
  cl_object v6from_end;
  cl_object v7count;
  cl_object v8key;
  ecl_va_list args; ecl_va_start(args,v3sequence,narg,3);
  {
   cl_object keyvars[10];
   cl_parse_key(args,5,cl_substitute_if_notkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[5])) {
    v4start = ecl_make_fixnum(0);
   } else {
    v4start = keyvars[0];
   }
   v5end = keyvars[1];
   v6from_end = keyvars[2];
   v7count = keyvars[3];
   v8key = keyvars[4];
  }
  T0 = si_coerce_to_function(v2predicate);
  T1 = ecl_copy_seq(v3sequence);
  T2 = (VV[1]->symbol.gfdef);
  value0 = cl_nsubstitute(17, v1new, T0, T1, ECL_SYM("KEY",1262), v8key, ECL_SYM("TEST-NOT",1317), T2, ECL_SYM("START",1310), v4start, ECL_SYM("END",1225), v5end, VV[4], v6from_end, ECL_SYM("COUNT",1450), v7count, ECL_SYM("KEY",1262), v8key);
  return value0;
 }
}
/*	function definition for NSUBSTITUTE                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_nsubstitute(cl_narg narg, cl_object v1new, cl_object v2old, cl_object v3sequence, ...)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 {
  cl_object v4test;
  cl_object v5test_not;
  cl_object v6start;
  cl_object v7end;
  cl_object v8from_end;
  cl_object v9count;
  cl_object v10key;
  ecl_va_list args; ecl_va_start(args,v3sequence,narg,3);
  {
   cl_object keyvars[14];
   cl_parse_key(args,7,cl_nsubstitutekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v4test = keyvars[0];
   v5test_not = keyvars[1];
   if (Null(keyvars[9])) {
    v6start = ecl_make_fixnum(0);
   } else {
    v6start = keyvars[2];
   }
   v7end = keyvars[3];
   v8from_end = keyvars[4];
   v9count = keyvars[5];
   v10key = keyvars[6];
  }
  {
   cl_object v11;
   if (Null(v4test)) { goto L3; }
   if (Null(v5test_not)) { goto L5; }
   L2test_error();
L5:;
   v11 = si_coerce_to_function(v4test);
   goto L2;
L3:;
   if (Null(v5test_not)) { goto L7; }
   v11 = si_coerce_to_function(v5test_not);
   goto L2;
L7:;
   v11 = (ECL_SYM("EQL",334)->symbol.gfdef);
L2:;
   {
    cl_object v12key;
    if (Null(v10key)) { goto L10; }
    v12key = si_coerce_to_function(v10key);
    goto L9;
L10:;
    v12key = (ECL_SYM("IDENTITY",426)->symbol.gfdef);
L9:;
    {
     cl_fixnum v14;                               /*  START           */
     cl_fixnum v15;                               /*  END             */
     cl_fixnum v16;                               /*  L               */
     value0 = si_sequence_start_end(ECL_SYM("SUBSEQ",829), v3sequence, v6start, v7end);
     v14 = ecl_fixnum(value0);
     v15 = ecl_fixnum(cl_env_copy->values[1]);
     v16 = ecl_fixnum(cl_env_copy->values[2]);
     {
      cl_fixnum v17_count;
      v17_count = ecl_fixnum(si_sequence_count(v9count));
      if (!((v17_count)>0)) { goto L14; }
      if (Null(v8from_end)) { goto L16; }
      if (!(ECL_LISTP(v3sequence))) { goto L18; }
      T0 = cl_nreverse(v3sequence);
      T1 = ecl_minus(ecl_make_fixnum(v16),ecl_make_fixnum(v15));
      T2 = ecl_minus(ecl_make_fixnum(v16),ecl_make_fixnum(v14));
      T3 = cl_nsubstitute(15, v1new, v2old, T0, ECL_SYM("START",1310), T1, ECL_SYM("END",1225), T2, ECL_SYM("KEY",1262), v12key, ECL_SYM("TEST",1316), v4test, ECL_SYM("TEST-NOT",1317), v5test_not, ECL_SYM("COUNT",1450), v9count);
      value0 = cl_nreverse(T3);
      return value0;
L18:;
      {
       cl_fixnum v18;
       v18 = v15;
       goto L23;
L22:;
       {
        cl_object v19elt;
        v18 = (v18)-1;
        v19elt = ecl_aref_unsafe(v3sequence,v18);
        if (Null(v5test_not)) { goto L29; }
        T0 = (cl_env_copy->function=v12key)->cfun.entry(1, v19elt);
        if (((cl_env_copy->function=v11)->cfun.entry(2, v2old, T0))!=ECL_NIL) { goto L25; }
        goto L28;
L29:;
        T0 = (cl_env_copy->function=v12key)->cfun.entry(1, v19elt);
        if (Null((cl_env_copy->function=v11)->cfun.entry(2, v2old, T0))) { goto L25; }
L28:;
        ecl_aset_unsafe(v3sequence,v18,v1new);
        {
         cl_fixnum v20;
         v17_count = (v17_count)-(1);
         v20 = v17_count;
         if (!((v20)==0)) { goto L25; }
        }
        value0 = v3sequence;
        cl_env_copy->nvalues = 1;
        return value0;
       }
L25:;
L23:;
       if ((v18)==(v14)) { goto L37; }
       goto L22;
L37:;
       value0 = v3sequence;
       cl_env_copy->nvalues = 1;
       return value0;
      }
L16:;
      if (!(ECL_LISTP(v3sequence))) { goto L39; }
      {
       cl_fixnum v19;
       cl_object v20;
       cl_fixnum v21;
       v19 = v14;
       v20 = ecl_nthcdr(v19,v3sequence);
       v21 = (v15)-(v19);
       goto L46;
L45:;
       {
        cl_object v22elt;
        v22elt = ECL_CONS_CAR(v20);
        if (Null(v5test_not)) { goto L51; }
        T0 = (cl_env_copy->function=v12key)->cfun.entry(1, v22elt);
        if (((cl_env_copy->function=v11)->cfun.entry(2, v2old, T0))!=ECL_NIL) { goto L48; }
        goto L50;
L51:;
        T0 = (cl_env_copy->function=v12key)->cfun.entry(1, v22elt);
        if (Null((cl_env_copy->function=v11)->cfun.entry(2, v2old, T0))) { goto L48; }
L50:;
        (ECL_CONS_CAR(v20)=v1new,v20);
        {
         cl_fixnum v23;
         v17_count = (v17_count)-(1);
         v23 = v17_count;
         if (!((v23)==0)) { goto L48; }
        }
        value0 = v3sequence;
        cl_env_copy->nvalues = 1;
        return value0;
       }
L48:;
       v19 = (v19)+1;
       v20 = ECL_CONS_CDR(v20);
       v21 = (v21)-1;
L46:;
       if ((v21)<=(0)) { goto L65; }
       goto L45;
L65:;
       value0 = v3sequence;
       cl_env_copy->nvalues = 1;
       return value0;
      }
L39:;
      {
       cl_fixnum v22;
       v22 = v14;
       goto L70;
L69:;
       {
        cl_object v23elt;
        v23elt = ecl_aref_unsafe(v3sequence,v22);
        if (Null(v5test_not)) { goto L75; }
        T0 = (cl_env_copy->function=v12key)->cfun.entry(1, v23elt);
        if (((cl_env_copy->function=v11)->cfun.entry(2, v2old, T0))!=ECL_NIL) { goto L72; }
        goto L74;
L75:;
        T0 = (cl_env_copy->function=v12key)->cfun.entry(1, v23elt);
        if (Null((cl_env_copy->function=v11)->cfun.entry(2, v2old, T0))) { goto L72; }
L74:;
        ecl_aset_unsafe(v3sequence,v22,v1new);
        {
         cl_fixnum v24;
         v17_count = (v17_count)-(1);
         v24 = v17_count;
         if (!((v24)==0)) { goto L72; }
        }
        value0 = v3sequence;
        cl_env_copy->nvalues = 1;
        return value0;
       }
L72:;
       v22 = (v22)+1;
L70:;
       if ((v22)==(v15)) { goto L85; }
       goto L69;
L85:;
       value0 = v3sequence;
       cl_env_copy->nvalues = 1;
       return value0;
      }
L14:;
      value0 = v3sequence;
      cl_env_copy->nvalues = 1;
      return value0;
     }
    }
   }
  }
 }
}
/*	function definition for NSUBSTITUTE-IF                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_nsubstitute_if(cl_narg narg, cl_object v1new, cl_object v2predicate, cl_object v3sequence, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 {
  cl_object v4start;
  cl_object v5end;
  cl_object v6from_end;
  cl_object v7count;
  cl_object v8key;
  ecl_va_list args; ecl_va_start(args,v3sequence,narg,3);
  {
   cl_object keyvars[10];
   cl_parse_key(args,5,cl_nsubstitute_ifkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[5])) {
    v4start = ecl_make_fixnum(0);
   } else {
    v4start = keyvars[0];
   }
   v5end = keyvars[1];
   v6from_end = keyvars[2];
   v7count = keyvars[3];
   v8key = keyvars[4];
  }
  T0 = si_coerce_to_function(v2predicate);
  T1 = (VV[1]->symbol.gfdef);
  value0 = cl_nsubstitute(17, v1new, T0, v3sequence, ECL_SYM("KEY",1262), v8key, ECL_SYM("TEST",1316), T1, ECL_SYM("START",1310), v4start, ECL_SYM("END",1225), v5end, VV[4], v6from_end, ECL_SYM("COUNT",1450), v7count, ECL_SYM("KEY",1262), v8key);
  return value0;
 }
}
/*	function definition for NSUBSTITUTE-IF-NOT                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_nsubstitute_if_not(cl_narg narg, cl_object v1new, cl_object v2predicate, cl_object v3sequence, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 {
  cl_object v4start;
  cl_object v5end;
  cl_object v6from_end;
  cl_object v7count;
  cl_object v8key;
  ecl_va_list args; ecl_va_start(args,v3sequence,narg,3);
  {
   cl_object keyvars[10];
   cl_parse_key(args,5,cl_nsubstitute_if_notkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[5])) {
    v4start = ecl_make_fixnum(0);
   } else {
    v4start = keyvars[0];
   }
   v5end = keyvars[1];
   v6from_end = keyvars[2];
   v7count = keyvars[3];
   v8key = keyvars[4];
  }
  T0 = si_coerce_to_function(v2predicate);
  T1 = (VV[1]->symbol.gfdef);
  value0 = cl_nsubstitute(17, v1new, T0, v3sequence, ECL_SYM("KEY",1262), v8key, ECL_SYM("TEST-NOT",1317), T1, ECL_SYM("START",1310), v4start, ECL_SYM("END",1225), v5end, VV[4], v6from_end, ECL_SYM("COUNT",1450), v7count, ECL_SYM("KEY",1262), v8key);
  return value0;
 }
}
/*	function definition for FIND                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_find(cl_narg narg, cl_object v1item, cl_object v2sequence, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3test;
  cl_object v4test_not;
  cl_object v5start;
  cl_object v6end;
  cl_object v7from_end;
  cl_object v8key;
  ecl_va_list args; ecl_va_start(args,v2sequence,narg,2);
  {
   cl_object keyvars[12];
   cl_parse_key(args,6,cl_findkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3test = keyvars[0];
   v4test_not = keyvars[1];
   if (Null(keyvars[8])) {
    v5start = ecl_make_fixnum(0);
   } else {
    v5start = keyvars[2];
   }
   v6end = keyvars[3];
   v7from_end = keyvars[4];
   v8key = keyvars[5];
  }
  {
   cl_object v9;
   if (Null(v3test)) { goto L3; }
   if (Null(v4test_not)) { goto L5; }
   L2test_error();
L5:;
   v9 = si_coerce_to_function(v3test);
   goto L2;
L3:;
   if (Null(v4test_not)) { goto L7; }
   v9 = si_coerce_to_function(v4test_not);
   goto L2;
L7:;
   v9 = (ECL_SYM("EQL",334)->symbol.gfdef);
L2:;
   {
    cl_object v10key;
    if (Null(v8key)) { goto L10; }
    v10key = si_coerce_to_function(v8key);
    goto L9;
L10:;
    v10key = (ECL_SYM("IDENTITY",426)->symbol.gfdef);
L9:;
    {
     cl_fixnum v12;                               /*  START           */
     cl_fixnum v13;                               /*  END             */
     value0 = si_sequence_start_end(ECL_SYM("SUBSEQ",829), v2sequence, v5start, v6end);
     v12 = ecl_fixnum(value0);
     v13 = ecl_fixnum(cl_env_copy->values[1]);
     {
      cl_object v14output;
      v14output = ECL_NIL;
      if (!(ECL_LISTP(v2sequence))) { goto L14; }
      {
       cl_fixnum v15index;
       cl_object v16;
       cl_fixnum v17;
       v15index = v12;
       v16 = ecl_nthcdr(v15index,v2sequence);
       v17 = (v13)-(v15index);
       goto L21;
L20:;
       {
        cl_object v18elt;
        v18elt = ECL_CONS_CAR(v16);
        if (Null(v4test_not)) { goto L26; }
        T0 = (cl_env_copy->function=v10key)->cfun.entry(1, v18elt);
        if (((cl_env_copy->function=v9)->cfun.entry(2, v1item, T0))!=ECL_NIL) { goto L23; }
        goto L25;
L26:;
        T0 = (cl_env_copy->function=v10key)->cfun.entry(1, v18elt);
        if (Null((cl_env_copy->function=v9)->cfun.entry(2, v1item, T0))) { goto L23; }
L25:;
        if ((v7from_end)!=ECL_NIL) { goto L30; }
        value0 = v18elt;
        cl_env_copy->nvalues = 1;
        return value0;
L30:;
        v14output = v18elt;
       }
L23:;
       v15index = (v15index)+1;
       v16 = ECL_CONS_CDR(v16);
       v17 = (v17)-1;
L21:;
       if ((v17)<=(0)) { goto L39; }
       goto L20;
L39:;
       value0 = v14output;
       cl_env_copy->nvalues = 1;
       return value0;
      }
L14:;
      {
       cl_fixnum v18index;
       v18index = v12;
       goto L44;
L43:;
       {
        cl_object v19elt;
        v19elt = ecl_aref_unsafe(v2sequence,v18index);
        if (Null(v4test_not)) { goto L49; }
        T0 = (cl_env_copy->function=v10key)->cfun.entry(1, v19elt);
        if (((cl_env_copy->function=v9)->cfun.entry(2, v1item, T0))!=ECL_NIL) { goto L46; }
        goto L48;
L49:;
        T0 = (cl_env_copy->function=v10key)->cfun.entry(1, v19elt);
        if (Null((cl_env_copy->function=v9)->cfun.entry(2, v1item, T0))) { goto L46; }
L48:;
        if ((v7from_end)!=ECL_NIL) { goto L53; }
        value0 = v19elt;
        cl_env_copy->nvalues = 1;
        return value0;
L53:;
        v14output = v19elt;
       }
L46:;
       v18index = (v18index)+1;
L44:;
       if ((v18index)==(v13)) { goto L58; }
       goto L43;
L58:;
       value0 = v14output;
       cl_env_copy->nvalues = 1;
       return value0;
      }
     }
    }
   }
  }
 }
}
/*	function definition for FIND-IF                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_find_if(cl_narg narg, cl_object v1predicate, cl_object v2sequence, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3from_end;
  cl_object v4start;
  cl_object v5end;
  cl_object v6key;
  ecl_va_list args; ecl_va_start(args,v2sequence,narg,2);
  {
   cl_object keyvars[8];
   cl_parse_key(args,4,cl_find_ifkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3from_end = keyvars[0];
   if (Null(keyvars[5])) {
    v4start = ecl_make_fixnum(0);
   } else {
    v4start = keyvars[1];
   }
   v5end = keyvars[2];
   v6key = keyvars[3];
  }
  T0 = si_coerce_to_function(v1predicate);
  T1 = (VV[1]->symbol.gfdef);
  value0 = cl_find(12, T0, v2sequence, VV[4], v3from_end, ECL_SYM("START",1310), v4start, ECL_SYM("END",1225), v5end, ECL_SYM("TEST",1316), T1, ECL_SYM("KEY",1262), v6key);
  return value0;
 }
}
/*	function definition for FIND-IF-NOT                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_find_if_not(cl_narg narg, cl_object v1predicate, cl_object v2sequence, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3from_end;
  cl_object v4start;
  cl_object v5end;
  cl_object v6key;
  ecl_va_list args; ecl_va_start(args,v2sequence,narg,2);
  {
   cl_object keyvars[8];
   cl_parse_key(args,4,cl_find_if_notkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3from_end = keyvars[0];
   if (Null(keyvars[5])) {
    v4start = ecl_make_fixnum(0);
   } else {
    v4start = keyvars[1];
   }
   v5end = keyvars[2];
   v6key = keyvars[3];
  }
  T0 = si_coerce_to_function(v1predicate);
  T1 = (VV[1]->symbol.gfdef);
  value0 = cl_find(12, T0, v2sequence, VV[4], v3from_end, ECL_SYM("START",1310), v4start, ECL_SYM("END",1225), v5end, ECL_SYM("TEST-NOT",1317), T1, ECL_SYM("KEY",1262), v6key);
  return value0;
 }
}
/*	function definition for POSITION                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_position(cl_narg narg, cl_object v1item, cl_object v2sequence, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3test;
  cl_object v4test_not;
  cl_object v5from_end;
  cl_object v6start;
  cl_object v7end;
  cl_object v8key;
  ecl_va_list args; ecl_va_start(args,v2sequence,narg,2);
  {
   cl_object keyvars[12];
   cl_parse_key(args,6,cl_positionkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3test = keyvars[0];
   v4test_not = keyvars[1];
   v5from_end = keyvars[2];
   if (Null(keyvars[9])) {
    v6start = ecl_make_fixnum(0);
   } else {
    v6start = keyvars[3];
   }
   v7end = keyvars[4];
   v8key = keyvars[5];
  }
  {
   cl_object v9;
   if (Null(v3test)) { goto L3; }
   if (Null(v4test_not)) { goto L5; }
   L2test_error();
L5:;
   v9 = si_coerce_to_function(v3test);
   goto L2;
L3:;
   if (Null(v4test_not)) { goto L7; }
   v9 = si_coerce_to_function(v4test_not);
   goto L2;
L7:;
   v9 = (ECL_SYM("EQL",334)->symbol.gfdef);
L2:;
   {
    cl_object v10key;
    if (Null(v8key)) { goto L10; }
    v10key = si_coerce_to_function(v8key);
    goto L9;
L10:;
    v10key = (ECL_SYM("IDENTITY",426)->symbol.gfdef);
L9:;
    {
     cl_fixnum v12;                               /*  START           */
     cl_fixnum v13;                               /*  END             */
     value0 = si_sequence_start_end(ECL_SYM("SUBSEQ",829), v2sequence, v6start, v7end);
     v12 = ecl_fixnum(value0);
     v13 = ecl_fixnum(cl_env_copy->values[1]);
     {
      cl_object v14output;
      v14output = ECL_NIL;
      if (!(ECL_LISTP(v2sequence))) { goto L14; }
      {
       cl_fixnum v15index;
       cl_object v16;
       cl_fixnum v17;
       v15index = v12;
       v16 = ecl_nthcdr(v15index,v2sequence);
       v17 = (v13)-(v15index);
       goto L21;
L20:;
       {
        cl_object v18elt;
        v18elt = ECL_CONS_CAR(v16);
        if (Null(v4test_not)) { goto L26; }
        T0 = (cl_env_copy->function=v10key)->cfun.entry(1, v18elt);
        if (((cl_env_copy->function=v9)->cfun.entry(2, v1item, T0))!=ECL_NIL) { goto L23; }
        goto L25;
L26:;
        T0 = (cl_env_copy->function=v10key)->cfun.entry(1, v18elt);
        if (Null((cl_env_copy->function=v9)->cfun.entry(2, v1item, T0))) { goto L23; }
L25:;
        if ((v5from_end)!=ECL_NIL) { goto L30; }
        value0 = ecl_make_fixnum(v15index);
        cl_env_copy->nvalues = 1;
        return value0;
L30:;
        v14output = ecl_make_fixnum(v15index);
       }
L23:;
       v15index = (v15index)+1;
       v16 = ECL_CONS_CDR(v16);
       v17 = (v17)-1;
L21:;
       if ((v17)<=(0)) { goto L39; }
       goto L20;
L39:;
       value0 = v14output;
       cl_env_copy->nvalues = 1;
       return value0;
      }
L14:;
      {
       cl_fixnum v18index;
       v18index = v12;
       goto L44;
L43:;
       {
        cl_object v19elt;
        v19elt = ecl_aref_unsafe(v2sequence,v18index);
        if (Null(v4test_not)) { goto L49; }
        T0 = (cl_env_copy->function=v10key)->cfun.entry(1, v19elt);
        if (((cl_env_copy->function=v9)->cfun.entry(2, v1item, T0))!=ECL_NIL) { goto L46; }
        goto L48;
L49:;
        T0 = (cl_env_copy->function=v10key)->cfun.entry(1, v19elt);
        if (Null((cl_env_copy->function=v9)->cfun.entry(2, v1item, T0))) { goto L46; }
L48:;
        if ((v5from_end)!=ECL_NIL) { goto L53; }
        value0 = ecl_make_fixnum(v18index);
        cl_env_copy->nvalues = 1;
        return value0;
L53:;
        v14output = ecl_make_fixnum(v18index);
       }
L46:;
       v18index = (v18index)+1;
L44:;
       if ((v18index)==(v13)) { goto L58; }
       goto L43;
L58:;
       value0 = v14output;
       cl_env_copy->nvalues = 1;
       return value0;
      }
     }
    }
   }
  }
 }
}
/*	function definition for POSITION-IF                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_position_if(cl_narg narg, cl_object v1predicate, cl_object v2sequence, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3from_end;
  cl_object v4start;
  cl_object v5end;
  cl_object v6key;
  ecl_va_list args; ecl_va_start(args,v2sequence,narg,2);
  {
   cl_object keyvars[8];
   cl_parse_key(args,4,cl_position_ifkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3from_end = keyvars[0];
   if (Null(keyvars[5])) {
    v4start = ecl_make_fixnum(0);
   } else {
    v4start = keyvars[1];
   }
   v5end = keyvars[2];
   v6key = keyvars[3];
  }
  T0 = si_coerce_to_function(v1predicate);
  T1 = (VV[1]->symbol.gfdef);
  value0 = cl_position(12, T0, v2sequence, VV[4], v3from_end, ECL_SYM("START",1310), v4start, ECL_SYM("END",1225), v5end, ECL_SYM("TEST",1316), T1, ECL_SYM("KEY",1262), v6key);
  return value0;
 }
}
/*	function definition for POSITION-IF-NOT                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_position_if_not(cl_narg narg, cl_object v1predicate, cl_object v2sequence, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3from_end;
  cl_object v4start;
  cl_object v5end;
  cl_object v6key;
  ecl_va_list args; ecl_va_start(args,v2sequence,narg,2);
  {
   cl_object keyvars[8];
   cl_parse_key(args,4,cl_position_if_notkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3from_end = keyvars[0];
   if (Null(keyvars[5])) {
    v4start = ecl_make_fixnum(0);
   } else {
    v4start = keyvars[1];
   }
   v5end = keyvars[2];
   v6key = keyvars[3];
  }
  T0 = si_coerce_to_function(v1predicate);
  T1 = (VV[1]->symbol.gfdef);
  value0 = cl_position(12, T0, v2sequence, VV[4], v3from_end, ECL_SYM("START",1310), v4start, ECL_SYM("END",1225), v5end, ECL_SYM("TEST-NOT",1317), T1, ECL_SYM("KEY",1262), v6key);
  return value0;
 }
}
/*	function definition for REMOVE-DUPLICATES-LIST                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8remove_duplicates_list(cl_object v1sequence, cl_object v2start, cl_object v3end, cl_object v4from_end, cl_object v5test, cl_object v6test_not, cl_object v7key)
{
 cl_object T0;
 volatile cl_object lex0[3];
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  lex0[0] = v6test_not;
  if (Null(v5test)) { goto L2; }
  if (Null(lex0[0])) { goto L4; }
  L2test_error();
L4:;
  T0 = si_coerce_to_function(v5test);
  goto L1;
L2:;
  if (Null(lex0[0])) { goto L6; }
  T0 = si_coerce_to_function(lex0[0]);
  goto L1;
L6:;
  T0 = (ECL_SYM("EQL",334)->symbol.gfdef);
L1:;
  lex0[1] = T0;
  if (Null(v7key)) { goto L9; }
  T0 = si_coerce_to_function(v7key);
  goto L8;
L9:;
  T0 = (ECL_SYM("IDENTITY",426)->symbol.gfdef);
L8:;
  lex0[2] = T0;                                   /*  KEY             */
  {
   cl_fixnum v9;                                  /*  START           */
   cl_fixnum v10;                                 /*  END             */
   value0 = si_sequence_start_end(ECL_SYM("SUBSEQ",829), v1sequence, v2start, v3end);
   v9 = ecl_fixnum(value0);
   v10 = ecl_fixnum(cl_env_copy->values[1]);
   {
    cl_object v11output;
    v11output = ECL_NIL;
    goto L15;
L14:;
    T0 = ECL_CONS_CAR(v1sequence);
    v11output = CONS(T0,v11output);
    v1sequence = ECL_CONS_CDR(v1sequence);
    v9 = (v9)-1;
    v10 = (v10)-1;
L15:;
    if (Null(v1sequence)) { goto L25; }
    if (!((v9)>0)) { goto L25; }
    goto L14;
L25:;
    {
     cl_object v12;
     cl_object v13;
     v12 = v1sequence;
     {
      cl_fixnum v14;
      v14 = (v10)-(v9);
      v13 = ecl_nthcdr(v14,v1sequence);
     }
L30:;
     if (!((v1sequence)==(v13))) { goto L32; }
     value0 = cl_nreconc(v11output, v1sequence);
     return value0;
L32:;
     if ((LC7already_in_list_p(lex0, v12, v1sequence, v13, v4from_end))!=ECL_NIL) { goto L34; }
     T0 = ECL_CONS_CAR(v1sequence);
     v11output = CONS(T0,v11output);
L34:;
     v1sequence = ECL_CONS_CDR(v1sequence);
     goto L30;
    }
   }
  }
 }
}
/*	local function ALREADY-IN-LIST-P                              */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC7already_in_list_p(volatile cl_object *lex0, cl_object v1start, cl_object v2current, cl_object v3end, cl_object v4from_end)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v5elt;
  T0 = ECL_CONS_CAR(v2current);
  v5elt = (cl_env_copy->function=lex0[2])->cfun.entry(1, T0);
  if (Null(v4from_end)) { goto L2; }
L4:;
  if (!((v1start)==(v2current))) { goto L6; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L6:;
  if (Null(lex0[0])) { goto L10; }
  T1 = ECL_CONS_CAR(v1start);
  T0 = (cl_env_copy->function=lex0[2])->cfun.entry(1, T1);
  if (((cl_env_copy->function=lex0[1])->cfun.entry(2, v5elt, T0))!=ECL_NIL) { goto L8; }
  goto L9;
L10:;
  T1 = ECL_CONS_CAR(v1start);
  T0 = (cl_env_copy->function=lex0[2])->cfun.entry(1, T1);
  if (Null((cl_env_copy->function=lex0[1])->cfun.entry(2, v5elt, T0))) { goto L8; }
L9:;
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
L8:;
  v1start = ECL_CONS_CDR(v1start);
  goto L4;
L2:;
L16:;
  v2current = ECL_CONS_CDR(v2current);
  if (!((v2current)==(v3end))) { goto L20; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L20:;
  if (Null(lex0[0])) { goto L23; }
  T1 = ECL_CONS_CAR(v2current);
  T0 = (cl_env_copy->function=lex0[2])->cfun.entry(1, T1);
  if (((cl_env_copy->function=lex0[1])->cfun.entry(2, v5elt, T0))!=ECL_NIL) { goto L17; }
  goto L22;
L23:;
  T1 = ECL_CONS_CAR(v2current);
  T0 = (cl_env_copy->function=lex0[2])->cfun.entry(1, T1);
  if (Null((cl_env_copy->function=lex0[1])->cfun.entry(2, v5elt, T0))) { goto L17; }
L22:;
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
L17:;
  goto L16;
 }
}
/*	function definition for REMOVE-DUPLICATES                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_remove_duplicates(cl_narg narg, cl_object v1sequence, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2test;
  cl_object v3test_not;
  cl_object v4from_end;
  cl_object v5start;
  cl_object v6end;
  cl_object v7key;
  ecl_va_list args; ecl_va_start(args,v1sequence,narg,1);
  {
   cl_object keyvars[12];
   cl_parse_key(args,6,cl_remove_duplicateskeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v2test = keyvars[0];
   v3test_not = keyvars[1];
   v4from_end = keyvars[2];
   if (Null(keyvars[9])) {
    v5start = ecl_make_fixnum(0);
   } else {
    v5start = keyvars[3];
   }
   v6end = keyvars[4];
   v7key = keyvars[5];
  }
  if (!(ECL_LISTP(v1sequence))) { goto L2; }
  value0 = L8remove_duplicates_list(v1sequence, v5start, v6end, v4from_end, v2test, v3test_not, v7key);
  return value0;
L2:;
  if (!(ECL_VECTORP(v1sequence))) { goto L4; }
  {
   cl_object v8l;
   cl_object v9v;
   v8l = L12filter_duplicates_vector(ECL_NIL, v1sequence, v5start, v6end, v4from_end, v2test, v3test_not, v7key);
   T0 = cl_array_element_type(v1sequence);
   v9v = si_make_pure_array(T0, v8l, ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
   L12filter_duplicates_vector(v9v, v1sequence, v5start, v6end, v4from_end, v2test, v3test_not, v7key);
   value0 = v9v;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L4:;
  if (ECL_VECTORP(v1sequence)) { goto L9; }
  value0 = si_signal_type_error(v1sequence, ECL_SYM("SEQUENCE",741));
  return value0;
L9:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for DELETE-DUPLICATES-LIST                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L10delete_duplicates_list(cl_object v1sequence, cl_object v2start, cl_object v3end, cl_object v4from_end, cl_object v5test, cl_object v6test_not, cl_object v7key)
{
 cl_object T0;
 volatile cl_object lex0[3];
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  lex0[0] = v6test_not;
  if (Null(v5test)) { goto L2; }
  if (Null(lex0[0])) { goto L4; }
  L2test_error();
L4:;
  T0 = si_coerce_to_function(v5test);
  goto L1;
L2:;
  if (Null(lex0[0])) { goto L6; }
  T0 = si_coerce_to_function(lex0[0]);
  goto L1;
L6:;
  T0 = (ECL_SYM("EQL",334)->symbol.gfdef);
L1:;
  lex0[1] = T0;
  if (Null(v7key)) { goto L9; }
  T0 = si_coerce_to_function(v7key);
  goto L8;
L9:;
  T0 = (ECL_SYM("IDENTITY",426)->symbol.gfdef);
L8:;
  lex0[2] = T0;                                   /*  KEY             */
  {
   cl_fixnum v9;                                  /*  START           */
   cl_fixnum v10;                                 /*  END             */
   value0 = si_sequence_start_end(ECL_SYM("SUBSEQ",829), v1sequence, v2start, v3end);
   v9 = ecl_fixnum(value0);
   v10 = ecl_fixnum(cl_env_copy->values[1]);
   {
    cl_object v11splice;
    cl_object v12output;
    v11splice = CONS(ECL_NIL,v1sequence);
    v12output = v11splice;
    goto L16;
L15:;
    v11splice = ECL_CONS_CDR(v11splice);
    v1sequence = ECL_CONS_CDR(v1sequence);
    v9 = (v9)-1;
    v10 = (v10)-1;
L16:;
    if (Null(v1sequence)) { goto L26; }
    if (!((v9)>0)) { goto L26; }
    goto L15;
L26:;
    {
     cl_object v13;
     cl_object v14;
     v13 = v11splice;
     {
      cl_fixnum v15;
      v15 = (v10)-(v9);
      v14 = ecl_nthcdr(v15,v1sequence);
     }
L31:;
     if (!((v1sequence)==(v14))) { goto L33; }
     value0 = ECL_CONS_CDR(v12output);
     cl_env_copy->nvalues = 1;
     return value0;
L33:;
     T0 = ECL_CONS_CDR(v13);
     if (Null(LC9already_in_list_p(lex0, T0, v1sequence, v14, v4from_end))) { goto L35; }
     v1sequence = ECL_CONS_CDR(v1sequence);
     (ECL_CONS_CDR(v11splice)=v1sequence,v11splice);
     goto L32;
L35:;
     v1sequence = ECL_CONS_CDR(v1sequence);
     v11splice = ECL_CONS_CDR(v11splice);
L32:;
     goto L31;
    }
   }
  }
 }
}
/*	local function ALREADY-IN-LIST-P                              */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC9already_in_list_p(volatile cl_object *lex0, cl_object v1start, cl_object v2current, cl_object v3end, cl_object v4from_end)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v5elt;
  T0 = ECL_CONS_CAR(v2current);
  v5elt = (cl_env_copy->function=lex0[2])->cfun.entry(1, T0);
  if (Null(v4from_end)) { goto L2; }
L4:;
  if (!((v1start)==(v2current))) { goto L6; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L6:;
  if (Null(lex0[0])) { goto L10; }
  T1 = ECL_CONS_CAR(v1start);
  T0 = (cl_env_copy->function=lex0[2])->cfun.entry(1, T1);
  if (((cl_env_copy->function=lex0[1])->cfun.entry(2, v5elt, T0))!=ECL_NIL) { goto L8; }
  goto L9;
L10:;
  T1 = ECL_CONS_CAR(v1start);
  T0 = (cl_env_copy->function=lex0[2])->cfun.entry(1, T1);
  if (Null((cl_env_copy->function=lex0[1])->cfun.entry(2, v5elt, T0))) { goto L8; }
L9:;
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
L8:;
  v1start = ECL_CONS_CDR(v1start);
  goto L4;
L2:;
L16:;
  v2current = ECL_CONS_CDR(v2current);
  if (!((v2current)==(v3end))) { goto L20; }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L20:;
  if (Null(lex0[0])) { goto L23; }
  T1 = ECL_CONS_CAR(v2current);
  T0 = (cl_env_copy->function=lex0[2])->cfun.entry(1, T1);
  if (((cl_env_copy->function=lex0[1])->cfun.entry(2, v5elt, T0))!=ECL_NIL) { goto L17; }
  goto L22;
L23:;
  T1 = ECL_CONS_CAR(v2current);
  T0 = (cl_env_copy->function=lex0[2])->cfun.entry(1, T1);
  if (Null((cl_env_copy->function=lex0[1])->cfun.entry(2, v5elt, T0))) { goto L17; }
L22:;
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
L17:;
  goto L16;
 }
}
/*	function definition for FILTER-DUPLICATES-VECTOR              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L12filter_duplicates_vector(cl_object v1out, cl_object v2in, cl_object v3start, cl_object v4end, cl_object v5from_end, cl_object v6test, cl_object v7test_not, cl_object v8key)
{
 cl_object T0;
 volatile cl_object lex0[3];
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  lex0[0] = v7test_not;
  if (Null(v6test)) { goto L2; }
  if (Null(lex0[0])) { goto L4; }
  L2test_error();
L4:;
  T0 = si_coerce_to_function(v6test);
  goto L1;
L2:;
  if (Null(lex0[0])) { goto L6; }
  T0 = si_coerce_to_function(lex0[0]);
  goto L1;
L6:;
  T0 = (ECL_SYM("EQL",334)->symbol.gfdef);
L1:;
  lex0[1] = T0;
  if (Null(v8key)) { goto L9; }
  T0 = si_coerce_to_function(v8key);
  goto L8;
L9:;
  T0 = (ECL_SYM("IDENTITY",426)->symbol.gfdef);
L8:;
  lex0[2] = T0;                                   /*  KEY             */
  {
   cl_fixnum v10;                                 /*  START           */
   cl_fixnum v11;                                 /*  END             */
   cl_fixnum v12;                                 /*  LENGTH          */
   value0 = si_sequence_start_end(ECL_SYM("SUBSEQ",829), v2in, v3start, v4end);
   v10 = ecl_fixnum(value0);
   v11 = ecl_fixnum(cl_env_copy->values[1]);
   v12 = ecl_fixnum(cl_env_copy->values[2]);
   if (Null(v1out)) { goto L12; }
   if ((v1out)==(v2in)) { goto L12; }
   ecl_copy_subarray(v1out,0,v2in,0,v10);
L12:;
   {
    cl_fixnum v13index;
    cl_fixnum v14jndex;
    v13index = v10;
    v14jndex = v10;
L17:;
    if (!((v13index)==(v11))) { goto L19; }
    if (Null(v1out)) { goto L21; }
    ecl_copy_subarray(v1out,v14jndex,v2in,v11,v12);
L21:;
    T0 = ecl_minus(ecl_make_fixnum(v12),ecl_make_fixnum(v11));
    value0 = ecl_plus(ecl_make_fixnum(v14jndex),T0);
    cl_env_copy->nvalues = 1;
    return value0;
L19:;
    if ((LC11already_in_vector_p(lex0, v2in, ecl_make_fixnum(v10), ecl_make_fixnum(v13index), ecl_make_fixnum(v11), v5from_end))!=ECL_NIL) { goto L23; }
    if (Null(v1out)) { goto L25; }
    T0 = ecl_aref_unsafe(v2in,v13index);
    ecl_aset_unsafe(v1out,v14jndex,T0);
L25:;
    v14jndex = (v14jndex)+1;
L23:;
    v13index = (v13index)+1;
    goto L17;
   }
  }
 }
}
/*	local function ALREADY-IN-VECTOR-P                            */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object LC11already_in_vector_p(volatile cl_object *lex0, cl_object v1sequence, cl_object v2start, cl_object v3current, cl_object v4end, cl_object v5from_end)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 cl_fixnum v6start;
 cl_fixnum v7current;
 cl_fixnum v8end;
 v6start = ecl_fixnum(v2start);
 v7current = ecl_fixnum(v3current);
 v8end = ecl_fixnum(v4end);
TTL:
 if (Null(v5from_end)) { goto L2; }
 v8end = v7current;
 goto L1;
L2:;
 v6start = (v7current)+1;
L1:;
 {
  cl_object v9base;
  T0 = ecl_aref_unsafe(v1sequence,v7current);
  v9base = (cl_env_copy->function=lex0[2])->cfun.entry(1, T0);
  {
   cl_fixnum v10;
   v10 = v6start;
   goto L11;
L10:;
   {
    cl_object v11elt;
    v11elt = ecl_aref_unsafe(v1sequence,v10);
    if (Null(lex0[0])) { goto L16; }
    T0 = (cl_env_copy->function=lex0[2])->cfun.entry(1, v11elt);
    if (((cl_env_copy->function=lex0[1])->cfun.entry(2, v9base, T0))!=ECL_NIL) { goto L13; }
    goto L15;
L16:;
    T0 = (cl_env_copy->function=lex0[2])->cfun.entry(1, v11elt);
    if (Null((cl_env_copy->function=lex0[1])->cfun.entry(2, v9base, T0))) { goto L13; }
L15:;
    value0 = ECL_T;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L13:;
   v10 = (v10)+1;
L11:;
   if ((v10)==(v8end)) { goto L22; }
   goto L10;
L22:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for DELETE-DUPLICATES                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_delete_duplicates(cl_narg narg, cl_object v1sequence, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2test;
  cl_object v3test_not;
  cl_object v4from_end;
  cl_object v5start;
  cl_object v6end;
  cl_object v7key;
  ecl_va_list args; ecl_va_start(args,v1sequence,narg,1);
  {
   cl_object keyvars[12];
   cl_parse_key(args,6,cl_delete_duplicateskeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v2test = keyvars[0];
   v3test_not = keyvars[1];
   v4from_end = keyvars[2];
   if (Null(keyvars[9])) {
    v5start = ecl_make_fixnum(0);
   } else {
    v5start = keyvars[3];
   }
   v6end = keyvars[4];
   v7key = keyvars[5];
  }
  if (!(ECL_LISTP(v1sequence))) { goto L2; }
  value0 = L10delete_duplicates_list(v1sequence, v5start, v6end, v4from_end, v2test, v3test_not, v7key);
  return value0;
L2:;
  if (ECL_VECTORP(v1sequence)) { goto L4; }
  value0 = si_signal_type_error(v1sequence, ECL_SYM("SEQUENCE",741));
  return value0;
L4:;
  if (!((ECL_ARRAYP(v1sequence)?(void)0:FEtype_error_array(v1sequence),ECL_ARRAY_HAS_FILL_POINTER_P(v1sequence)))) { goto L6; }
  {
   cl_object v8l;
   v8l = L12filter_duplicates_vector(v1sequence, v1sequence, v5start, v6end, v4from_end, v2test, v3test_not, v7key);
   si_fill_pointer_set(v1sequence, v8l);
   value0 = v1sequence;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L6:;
  {
   cl_object v9l;
   cl_object v10v;
   v9l = L12filter_duplicates_vector(ECL_NIL, v1sequence, v5start, v6end, v4from_end, v2test, v3test_not, v7key);
   T0 = cl_array_element_type(v1sequence);
   v10v = si_make_pure_array(T0, v9l, ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
   L12filter_duplicates_vector(v10v, v1sequence, v5start, v6end, v4from_end, v2test, v3test_not, v7key);
   value0 = v10v;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for MISMATCH                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_mismatch(cl_narg narg, cl_object v1sequence1, cl_object v2sequence2, ...)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3from_end;
  cl_object v4test;
  cl_object v5test_not;
  cl_object v6key;
  cl_object v7start1;
  cl_object v8start2;
  cl_object v9end1;
  cl_object v10end2;
  ecl_va_list args; ecl_va_start(args,v2sequence2,narg,2);
  {
   cl_object keyvars[16];
   cl_parse_key(args,8,cl_mismatchkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3from_end = keyvars[0];
   v4test = keyvars[1];
   v5test_not = keyvars[2];
   v6key = keyvars[3];
   if (Null(keyvars[12])) {
    v7start1 = ecl_make_fixnum(0);
   } else {
    v7start1 = keyvars[4];
   }
   if (Null(keyvars[13])) {
    v8start2 = ecl_make_fixnum(0);
   } else {
    v8start2 = keyvars[5];
   }
   v9end1 = keyvars[6];
   v10end2 = keyvars[7];
  }
  {
   cl_fixnum v12;                                 /*  START1          */
   cl_fixnum v13;                                 /*  END1            */
   value0 = si_sequence_start_end(ECL_SYM("SUBSEQ",829), v1sequence1, v7start1, v9end1);
   v12 = ecl_to_fixnum(value0);
   v13 = ecl_to_fixnum(cl_env_copy->values[1]);
   {
    cl_fixnum v15;                                /*  START2          */
    cl_fixnum v16;                                /*  END2            */
    value0 = si_sequence_start_end(ECL_SYM("SUBSEQ",829), v2sequence2, v8start2, v10end2);
    v15 = ecl_to_fixnum(value0);
    v16 = ecl_to_fixnum(cl_env_copy->values[1]);
    {
     cl_object v17;
     if (Null(v4test)) { goto L6; }
     if (Null(v5test_not)) { goto L8; }
     L2test_error();
L8:;
     v17 = si_coerce_to_function(v4test);
     goto L5;
L6:;
     if (Null(v5test_not)) { goto L10; }
     v17 = si_coerce_to_function(v5test_not);
     goto L5;
L10:;
     v17 = (ECL_SYM("EQL",334)->symbol.gfdef);
L5:;
     {
      cl_object v18key;
      if (Null(v6key)) { goto L13; }
      v18key = si_coerce_to_function(v6key);
      goto L12;
L13:;
      v18key = (ECL_SYM("IDENTITY",426)->symbol.gfdef);
L12:;
      if ((v3from_end)!=ECL_NIL) { goto L15; }
      {
       cl_fixnum v19i1;
       cl_fixnum v20i2;
       v19i1 = v12;
       v20i2 = v15;
       goto L21;
L20:;
       if (Null(v5test_not)) { goto L25; }
       T1 = ecl_elt(v1sequence1,v19i1);
       T0 = (cl_env_copy->function=v18key)->cfun.entry(1, T1);
       T2 = ecl_elt(v2sequence2,v20i2);
       T1 = (cl_env_copy->function=v18key)->cfun.entry(1, T2);
       if (Null((cl_env_copy->function=v17)->cfun.entry(2, T0, T1))) { goto L23; }
       goto L24;
L25:;
       T1 = ecl_elt(v1sequence1,v19i1);
       T0 = (cl_env_copy->function=v18key)->cfun.entry(1, T1);
       T2 = ecl_elt(v2sequence2,v20i2);
       T1 = (cl_env_copy->function=v18key)->cfun.entry(1, T2);
       if (((cl_env_copy->function=v17)->cfun.entry(2, T0, T1))!=ECL_NIL) { goto L23; }
L24:;
       value0 = ecl_make_fixnum(v19i1);
       cl_env_copy->nvalues = 1;
       return value0;
L23:;
       {
        cl_object v21;
        v21 = ecl_make_integer((v19i1)+1);
        {
         bool v22;
         v22 = ECL_FIXNUMP(v21);
         if (ecl_unlikely(!(v22)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v21);
        }
        v19i1 = ecl_fixnum(v21);
       }
       {
        cl_object v21;
        v21 = ecl_make_integer((v20i2)+1);
        {
         bool v22;
         v22 = ECL_FIXNUMP(v21);
         if (ecl_unlikely(!(v22)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v21);
        }
        v20i2 = ecl_fixnum(v21);
       }
L21:;
       if ((v19i1)>=(v13)) { goto L38; }
       if ((v20i2)>=(v16)) { goto L38; }
       goto L20;
L38:;
       if (!((v19i1)>=(v13))) { goto L41; }
       if (!((v20i2)>=(v16))) { goto L41; }
       value0 = ECL_NIL;
       cl_env_copy->nvalues = 1;
       return value0;
L41:;
       value0 = ecl_make_fixnum(v19i1);
       cl_env_copy->nvalues = 1;
       return value0;
      }
L15:;
      {
       cl_object v21;
       cl_object v22;
       cl_fixnum v23i1;
       cl_fixnum v24i2;
       v21 = ecl_make_integer((v13)-1);
       v22 = ecl_make_integer((v16)-1);
       {
        bool v25;
        v25 = ECL_FIXNUMP(v21);
        if (ecl_unlikely(!(v25)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v21);
       }
       v23i1 = ecl_fixnum(v21);
       {
        bool v25;
        v25 = ECL_FIXNUMP(v22);
        if (ecl_unlikely(!(v25)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v22);
       }
       v24i2 = ecl_fixnum(v22);
       goto L52;
L51:;
       if (Null(v5test_not)) { goto L56; }
       T1 = ecl_elt(v1sequence1,v23i1);
       T0 = (cl_env_copy->function=v18key)->cfun.entry(1, T1);
       T2 = ecl_elt(v2sequence2,v24i2);
       T1 = (cl_env_copy->function=v18key)->cfun.entry(1, T2);
       if (Null((cl_env_copy->function=v17)->cfun.entry(2, T0, T1))) { goto L54; }
       goto L55;
L56:;
       T1 = ecl_elt(v1sequence1,v23i1);
       T0 = (cl_env_copy->function=v18key)->cfun.entry(1, T1);
       T2 = ecl_elt(v2sequence2,v24i2);
       T1 = (cl_env_copy->function=v18key)->cfun.entry(1, T2);
       if (((cl_env_copy->function=v17)->cfun.entry(2, T0, T1))!=ECL_NIL) { goto L54; }
L55:;
       value0 = ecl_make_integer((v23i1)+1);
       cl_env_copy->nvalues = 1;
       return value0;
L54:;
       {
        cl_object v25;
        v25 = ecl_make_integer((v23i1)-1);
        {
         bool v26;
         v26 = ECL_FIXNUMP(v25);
         if (ecl_unlikely(!(v26)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v25);
        }
        v23i1 = ecl_fixnum(v25);
       }
       {
        cl_object v25;
        v25 = ecl_make_integer((v24i2)-1);
        {
         bool v26;
         v26 = ECL_FIXNUMP(v25);
         if (ecl_unlikely(!(v26)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v25);
        }
        v24i2 = ecl_fixnum(v25);
       }
L52:;
       if ((v23i1)<(v12)) { goto L69; }
       if ((v24i2)<(v15)) { goto L69; }
       goto L51;
L69:;
       if (!((v23i1)<(v12))) { goto L72; }
       if (!((v24i2)<(v15))) { goto L72; }
       value0 = ECL_NIL;
       cl_env_copy->nvalues = 1;
       return value0;
L72:;
       value0 = ecl_make_integer((v23i1)+1);
       cl_env_copy->nvalues = 1;
       return value0;
      }
     }
    }
   }
  }
 }
}
/*	function definition for SEARCH                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_search(cl_narg narg, cl_object v1sequence1, cl_object v2sequence2, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3from_end;
  cl_object v4test;
  cl_object v5test_not;
  cl_object v6key;
  cl_object v7start1;
  cl_object v8start2;
  cl_object v9end1;
  cl_object v10end2;
  ecl_va_list args; ecl_va_start(args,v2sequence2,narg,2);
  {
   cl_object keyvars[16];
   cl_parse_key(args,8,cl_searchkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3from_end = keyvars[0];
   v4test = keyvars[1];
   v5test_not = keyvars[2];
   v6key = keyvars[3];
   if (Null(keyvars[12])) {
    v7start1 = ecl_make_fixnum(0);
   } else {
    v7start1 = keyvars[4];
   }
   if (Null(keyvars[13])) {
    v8start2 = ecl_make_fixnum(0);
   } else {
    v8start2 = keyvars[5];
   }
   v9end1 = keyvars[6];
   v10end2 = keyvars[7];
  }
  if (!(ECL_VECTORP(v1sequence1))) { goto L3; }
  if (!(ECL_VECTORP(v2sequence2))) { goto L3; }
  value0 = L13search_vector(v1sequence1, v7start1, v9end1, v2sequence2, v8start2, v10end2, v4test, v5test_not, v6key, v3from_end);
  return value0;
L3:;
  value0 = L14search_generic(v1sequence1, v7start1, v9end1, v2sequence2, v8start2, v10end2, v4test, v5test_not, v6key, v3from_end);
  return value0;
 }
}
/*	function definition for SEARCH-VECTOR                         */
/*	optimize speed 3, debug 0, space 0, safety 0                  */
static cl_object L13search_vector(cl_object v1sequence1, cl_object v2start1, cl_object v3end1, cl_object v4sequence2, cl_object v5start2, cl_object v6end2, cl_object v7test, cl_object v8test_not, cl_object v9key, cl_object v10from_end)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_object v11;
  if (Null(v7test)) { goto L2; }
  if (Null(v8test_not)) { goto L4; }
  L2test_error();
L4:;
  v11 = si_coerce_to_function(v7test);
  goto L1;
L2:;
  if (Null(v8test_not)) { goto L6; }
  v11 = si_coerce_to_function(v8test_not);
  goto L1;
L6:;
  v11 = (ECL_SYM("EQL",334)->symbol.gfdef);
L1:;
  {
   cl_object v12key;
   if (Null(v9key)) { goto L9; }
   v12key = si_coerce_to_function(v9key);
   goto L8;
L9:;
   v12key = (ECL_SYM("IDENTITY",426)->symbol.gfdef);
L8:;
   {
    cl_fixnum v14;                                /*  START1          */
    cl_fixnum v15;                                /*  END1            */
    value0 = si_sequence_start_end(ECL_SYM("SUBSEQ",829), v1sequence1, v2start1, v3end1);
    v14 = ecl_fixnum(value0);
    v15 = ecl_fixnum(cl_env_copy->values[1]);
    {
     cl_fixnum v17;                               /*  START2          */
     cl_fixnum v18;                               /*  END2            */
     value0 = si_sequence_start_end(ECL_SYM("SUBSEQ",829), v4sequence2, v5start2, v6end2);
     v17 = ecl_fixnum(value0);
     v18 = ecl_fixnum(cl_env_copy->values[1]);
     {
      cl_fixnum v19last_index;
      cl_object v20last;
      cl_fixnum v21start2;
      cl_object v22base;
      v19last_index = -1;
      {
       cl_fixnum v23l;
       cl_fixnum v24e;
       v23l = (v15)-(v14);
       v24e = (v18)-(v23l);
       if ((v23l)>0) { goto L17; }
       if (Null(v10from_end)) { goto L19; }
       value0 = ecl_make_fixnum(v18);
       cl_env_copy->nvalues = 1;
       return value0;
L19:;
       value0 = ecl_make_fixnum(0);
       cl_env_copy->nvalues = 1;
       return value0;
L17:;
       v20last = ecl_make_integer((v24e)+1);
      }
      v21start2 = v17;
      T0 = ecl_aref_unsafe(v1sequence1,v14);
      v22base = (cl_env_copy->function=v12key)->cfun.entry(1, T0);
      goto L26;
L25:;
      if (Null(v8test_not)) { goto L30; }
      T1 = ecl_aref_unsafe(v4sequence2,v21start2);
      T0 = (cl_env_copy->function=v12key)->cfun.entry(1, T1);
      if (((cl_env_copy->function=v11)->cfun.entry(2, v22base, T0))!=ECL_NIL) { goto L28; }
      goto L29;
L30:;
      T1 = ecl_aref_unsafe(v4sequence2,v21start2);
      T0 = (cl_env_copy->function=v12key)->cfun.entry(1, T1);
      if (Null((cl_env_copy->function=v11)->cfun.entry(2, v22base, T0))) { goto L28; }
L29:;
      {
       cl_fixnum v23i1;
       cl_fixnum v24i2;
       v23i1 = v14;
       v24i2 = v21start2;
L38:;
       v23i1 = (v23i1)+1;
       v24i2 = (v24i2)+1;
       if ((v23i1)>=(v15)) { goto L46; }
       if (!((v24i2)>=(v18))) { goto L44; }
       goto L45;
L46:;
L45:;
       if (Null(v10from_end)) { goto L48; }
       v19last_index = v21start2;
       goto L28;
L48:;
       value0 = ecl_make_fixnum(v21start2);
       cl_env_copy->nvalues = 1;
       return value0;
L44:;
       if (Null(v8test_not)) { goto L53; }
       T1 = ecl_aref_unsafe(v1sequence1,v23i1);
       T0 = (cl_env_copy->function=v12key)->cfun.entry(1, T1);
       T2 = ecl_aref_unsafe(v4sequence2,v24i2);
       T1 = (cl_env_copy->function=v12key)->cfun.entry(1, T2);
       if (Null((cl_env_copy->function=v11)->cfun.entry(2, T0, T1))) { goto L39; }
       goto L52;
L53:;
       T1 = ecl_aref_unsafe(v1sequence1,v23i1);
       T0 = (cl_env_copy->function=v12key)->cfun.entry(1, T1);
       T2 = ecl_aref_unsafe(v4sequence2,v24i2);
       T1 = (cl_env_copy->function=v12key)->cfun.entry(1, T2);
       if (((cl_env_copy->function=v11)->cfun.entry(2, T0, T1))!=ECL_NIL) { goto L39; }
L52:;
       goto L28;
L39:;
       goto L38;
      }
L28:;
      v21start2 = (v21start2)+1;
L26:;
      if (ecl_number_compare(ecl_make_fixnum(v21start2),v20last)>=0) { goto L66; }
      goto L25;
L66:;
      if (!((v19last_index)<0)) { goto L68; }
      value0 = ECL_NIL;
      cl_env_copy->nvalues = 1;
      return value0;
L68:;
      value0 = ecl_make_fixnum(v19last_index);
      cl_env_copy->nvalues = 1;
      return value0;
     }
    }
   }
  }
 }
}
/*	function definition for SEARCH-GENERIC                        */
/*	optimize speed 3, debug 0, space 0, safety 2                  */
static cl_object L14search_generic(cl_object v1sequence1, cl_object v2start1, cl_object v3end1, cl_object v4sequence2, cl_object v5start2, cl_object v6end2, cl_object v7test, cl_object v8test_not, cl_object v9key, cl_object v10from_end)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v11;
   if (Null(v7test)) { goto L2; }
   if (Null(v8test_not)) { goto L4; }
   L2test_error();
L4:;
   v11 = si_coerce_to_function(v7test);
   goto L1;
L2:;
   if (Null(v8test_not)) { goto L6; }
   v11 = si_coerce_to_function(v8test_not);
   goto L1;
L6:;
   v11 = (ECL_SYM("EQL",334)->symbol.gfdef);
L1:;
   {
    cl_object v12key;
    if (Null(v9key)) { goto L9; }
    v12key = si_coerce_to_function(v9key);
    goto L8;
L9:;
    v12key = (ECL_SYM("IDENTITY",426)->symbol.gfdef);
L8:;
    {
     cl_fixnum v14;                               /*  START1          */
     cl_fixnum v15;                               /*  END1            */
     value0 = si_sequence_start_end(ECL_SYM("SUBSEQ",829), v1sequence1, v2start1, v3end1);
     v14 = ecl_to_fixnum(value0);
     v15 = ecl_to_fixnum(cl_env_copy->values[1]);
     {
      cl_fixnum v17;                              /*  START2          */
      cl_fixnum v18;                              /*  END2            */
      value0 = si_sequence_start_end(ECL_SYM("SUBSEQ",829), v4sequence2, v5start2, v6end2);
      v17 = ecl_to_fixnum(value0);
      v18 = ecl_to_fixnum(cl_env_copy->values[1]);
      {
       cl_fixnum v19last_index;
       cl_fixnum v20start2;
       cl_fixnum v21last;
       cl_object v22it1;
       cl_object v23base;
       cl_object v24it2;
       v19last_index = -1;
       v20start2 = v17;
       {
        cl_object v25;
        {
         cl_fixnum v26l;
         cl_fixnum v27e;
         {
          cl_object v28;
          v28 = ecl_minus(ecl_make_fixnum(v15),ecl_make_fixnum(v14));
          {
          bool v29;
          v29 = ECL_FIXNUMP(v28);
          if (ecl_unlikely(!(v29)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v28);
          }
          v26l = ecl_fixnum(v28);
         }
         {
          cl_object v28;
          v28 = ecl_minus(ecl_make_fixnum(v18),ecl_make_fixnum(v26l));
          {
          bool v29;
          v29 = ECL_FIXNUMP(v28);
          if (ecl_unlikely(!(v29)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v28);
          }
          v27e = ecl_fixnum(v28);
         }
         if ((v26l)>0) { goto L23; }
         if (Null(v10from_end)) { goto L25; }
         value0 = ecl_make_fixnum(v18);
         cl_env_copy->nvalues = 1;
         return value0;
L25:;
         value0 = ecl_make_fixnum(0);
         cl_env_copy->nvalues = 1;
         return value0;
L23:;
         v25 = ecl_make_integer((v27e)+1);
        }
        {
         bool v26;
         v26 = ECL_FIXNUMP(v25);
         if (ecl_unlikely(!(v26)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v25);
        }
        v21last = ecl_fixnum(v25);
       }
       v22it1 = si_make_seq_iterator(2, v1sequence1, ecl_make_fixnum(v14));
       T0 = si_seq_iterator_ref(v1sequence1, v22it1);
       v23base = (cl_env_copy->function=v12key)->cfun.entry(1, T0);
       v24it2 = si_make_seq_iterator(2, v4sequence2, ecl_make_fixnum(v20start2));
       goto L33;
L32:;
       if (Null(v8test_not)) { goto L37; }
       T1 = si_seq_iterator_ref(v4sequence2, v24it2);
       T0 = (cl_env_copy->function=v12key)->cfun.entry(1, T1);
       if (((cl_env_copy->function=v11)->cfun.entry(2, v23base, T0))!=ECL_NIL) { goto L35; }
       goto L36;
L37:;
       T1 = si_seq_iterator_ref(v4sequence2, v24it2);
       T0 = (cl_env_copy->function=v12key)->cfun.entry(1, T1);
       if (Null((cl_env_copy->function=v11)->cfun.entry(2, v23base, T0))) { goto L35; }
L36:;
       {
        cl_object v25it1;
        cl_object v26it2;
        cl_fixnum v27i1;
        cl_fixnum v28i2;
        v25it1 = v22it1;
        v26it2 = v24it2;
        v27i1 = v14;
        v28i2 = v20start2;
L45:;
        v25it1 = si_seq_iterator_next(v1sequence1, v25it1);
        v26it2 = si_seq_iterator_next(v4sequence2, v26it2);
        {
         cl_object v29;
         v29 = ecl_make_integer((v27i1)+1);
         {
          bool v30;
          v30 = ECL_FIXNUMP(v29);
          if (ecl_unlikely(!(v30)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v29);
         }
         v27i1 = ecl_fixnum(v29);
        }
        {
         cl_object v29;
         v29 = ecl_make_integer((v28i2)+1);
         {
          bool v30;
          v30 = ECL_FIXNUMP(v29);
          if (ecl_unlikely(!(v30)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v29);
         }
         v28i2 = ecl_fixnum(v29);
        }
        if ((v27i1)>=(v15)) { goto L61; }
        if ((v28i2)>=(v18)) { goto L61; }
        if (v25it1==ECL_NIL) { goto L61; }
        if (!(v26it2==ECL_NIL)) { goto L59; }
        goto L60;
L61:;
L60:;
        if (Null(v10from_end)) { goto L65; }
        v19last_index = v20start2;
        goto L35;
L65:;
        value0 = ecl_make_fixnum(v20start2);
        cl_env_copy->nvalues = 1;
        return value0;
L59:;
        if (Null(v8test_not)) { goto L70; }
        T1 = si_seq_iterator_ref(v1sequence1, v25it1);
        T0 = (cl_env_copy->function=v12key)->cfun.entry(1, T1);
        T2 = si_seq_iterator_ref(v4sequence2, v26it2);
        T1 = (cl_env_copy->function=v12key)->cfun.entry(1, T2);
        if (Null((cl_env_copy->function=v11)->cfun.entry(2, T0, T1))) { goto L46; }
        goto L69;
L70:;
        T1 = si_seq_iterator_ref(v1sequence1, v25it1);
        T0 = (cl_env_copy->function=v12key)->cfun.entry(1, T1);
        T2 = si_seq_iterator_ref(v4sequence2, v26it2);
        T1 = (cl_env_copy->function=v12key)->cfun.entry(1, T2);
        if (((cl_env_copy->function=v11)->cfun.entry(2, T0, T1))!=ECL_NIL) { goto L46; }
L69:;
        goto L35;
L46:;
        goto L45;
       }
L35:;
       {
        cl_object v25;
        v25 = ecl_make_integer((v20start2)+1);
        {
         bool v26;
         v26 = ECL_FIXNUMP(v25);
         if (ecl_unlikely(!(v26)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v25);
        }
        v20start2 = ecl_fixnum(v25);
       }
       v24it2 = si_seq_iterator_next(v4sequence2, v24it2);
L33:;
       if (v24it2==ECL_NIL) { goto L83; }
       if ((v20start2)>=(v21last)) { goto L83; }
       goto L32;
L83:;
       if (!((v19last_index)<0)) { goto L86; }
       value0 = ECL_NIL;
       cl_env_copy->nvalues = 1;
       return value0;
L86:;
       value0 = ecl_make_fixnum(v19last_index);
       cl_env_copy->nvalues = 1;
       return value0;
      }
     }
    }
   }
  }
 }
}
/*	function definition for SORT                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_sort(cl_narg narg, cl_object v1sequence, cl_object v2predicate, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3key;
  ecl_va_list args; ecl_va_start(args,v2predicate,narg,2);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,cl_sortkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3key = keyvars[0];
  }
  if (Null(v3key)) { goto L4; }
  v3key = si_coerce_to_function(v3key);
  goto L3;
L4:;
  v3key = (ECL_SYM("IDENTITY",426)->symbol.gfdef);
L3:;
  v2predicate = si_coerce_to_function(v2predicate);
  if (!(ECL_LISTP(v1sequence))) { goto L7; }
  value0 = L15list_merge_sort(v1sequence, v2predicate, v3key);
  return value0;
L7:;
  {
   cl_fixnum v4;
   v4 = ecl_length(v1sequence);
   T0 = ecl_make_integer((v4)-1);
   value0 = L16quick_sort(v1sequence, ecl_make_fixnum(0), T0, v2predicate, v3key);
   return value0;
  }
 }
}
/*	function definition for LIST-MERGE-SORT                       */
/*	optimize speed 3, debug 1, space 1, safety 0                  */
static cl_object L15list_merge_sort(cl_object v1l, cl_object v2predicate, cl_object v3key)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
TTL:
 {
  cl_fixnum v4i;
  cl_object v5left;
  cl_object v6right;
  cl_object v7l0;
  cl_object v8l1;
  cl_object v9key_left;
  cl_object v10key_right;
  v4i = 0;
  v5left = ECL_NIL;
  v6right = ECL_NIL;
  v7l0 = ECL_NIL;
  v8l1 = ECL_NIL;
  v9key_left = ECL_NIL;
  v10key_right = ECL_NIL;
  v4i = ecl_length(v1l);
  if (!((v4i)<(2))) { goto L14; }
  value0 = v1l;
  cl_env_copy->nvalues = 1;
  return value0;
L14:;
  if (!((v4i)==(2))) { goto L13; }
  T0 = _ecl_car(v1l);
  v9key_left = (cl_env_copy->function=v3key)->cfun.entry(1, T0);
  T0 = _ecl_cadr(v1l);
  v10key_right = (cl_env_copy->function=v3key)->cfun.entry(1, T0);
  if (Null((cl_env_copy->function=v2predicate)->cfun.entry(2, v9key_left, v10key_right))) { goto L21; }
  value0 = v1l;
  cl_env_copy->nvalues = 1;
  return value0;
L21:;
  if (Null((cl_env_copy->function=v2predicate)->cfun.entry(2, v10key_right, v9key_left))) { goto L23; }
  value0 = cl_nreverse(v1l);
  return value0;
L23:;
  value0 = v1l;
  cl_env_copy->nvalues = 1;
  return value0;
L13:;
  v4i = ecl_fixnum(ecl_floor2(ecl_make_fixnum(v4i),ecl_make_fixnum(2)));
  {
   cl_fixnum v11j;
   cl_object v12l1;
   v11j = 1;
   v12l1 = v1l;
   goto L32;
L31:;
   v11j = (v11j)+1;
   v12l1 = _ecl_cdr(v12l1);
L32:;
   if ((v11j)>=(v4i)) { goto L37; }
   goto L31;
L37:;
   v5left = v1l;
   v6right = _ecl_cdr(v12l1);
   (ECL_CONS_CDR(v12l1)=ECL_NIL,v12l1);
  }
  v5left = L15list_merge_sort(v5left, v2predicate, v3key);
  v6right = L15list_merge_sort(v6right, v2predicate, v3key);
  if (!(v5left==ECL_NIL)) { goto L48; }
  value0 = v6right;
  cl_env_copy->nvalues = 1;
  return value0;
L48:;
  if (!(v6right==ECL_NIL)) { goto L47; }
  value0 = v5left;
  cl_env_copy->nvalues = 1;
  return value0;
L47:;
  v7l0 = CONS(ECL_NIL,ECL_NIL);
  v8l1 = v7l0;
  T0 = _ecl_car(v5left);
  v9key_left = (cl_env_copy->function=v3key)->cfun.entry(1, T0);
  T0 = _ecl_car(v6right);
  v10key_right = (cl_env_copy->function=v3key)->cfun.entry(1, T0);
L8:;
  if (Null((cl_env_copy->function=v2predicate)->cfun.entry(2, v9key_left, v10key_right))) { goto L60; }
  goto L9;
L60:;
  if (Null((cl_env_copy->function=v2predicate)->cfun.entry(2, v10key_right, v9key_left))) { goto L62; }
  goto L10;
L62:;
  goto L9;
L9:;
  (ECL_CONS_CDR(v8l1)=v5left,v8l1);
  v8l1 = _ecl_cdr(v8l1);
  v5left = _ecl_cdr(v5left);
  if (!(v5left==ECL_NIL)) { goto L69; }
  (ECL_CONS_CDR(v8l1)=v6right,v8l1);
  value0 = _ecl_cdr(v7l0);
  cl_env_copy->nvalues = 1;
  return value0;
L69:;
  T0 = _ecl_car(v5left);
  v9key_left = (cl_env_copy->function=v3key)->cfun.entry(1, T0);
  goto L8;
L10:;
  (ECL_CONS_CDR(v8l1)=v6right,v8l1);
  v8l1 = _ecl_cdr(v8l1);
  v6right = _ecl_cdr(v6right);
  if (!(v6right==ECL_NIL)) { goto L80; }
  (ECL_CONS_CDR(v8l1)=v5left,v8l1);
  value0 = _ecl_cdr(v7l0);
  cl_env_copy->nvalues = 1;
  return value0;
L80:;
  T0 = _ecl_car(v6right);
  v10key_right = (cl_env_copy->function=v3key)->cfun.entry(1, T0);
  goto L8;
 }
}
/*	function definition for QUICK-SORT                            */
/*	optimize speed 1, debug 1, space 1, safety 0                  */
static cl_object L16quick_sort(cl_object v1seq, cl_object v2start, cl_object v3end, cl_object v4pred, cl_object v5key)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 cl_fixnum v6start;
 cl_fixnum v7end;
 v6start = ecl_fixnum(v2start);
 v7end = ecl_fixnum(v3end);
TTL:
 if (!((v6start)<(v7end))) { goto L1; }
 {
  cl_fixnum v8j;
  v8j = (v7end)+1;
  {
   cl_fixnum v9i;
   cl_fixnum v10l;
   cl_fixnum v11l_half;
   cl_fixnum v12p;
   cl_object v13d;
   cl_object v14kd;
   v9i = v6start;
   v10l = (v7end)-(v6start);
   v11l_half = ((v10l) >> (1));
   v12p = (v6start)+(v11l_half);
   v13d = ecl_elt(v1seq,v12p);
   v14kd = (cl_env_copy->function=v5key)->cfun.entry(1, v13d);
   {
    cl_object v15;
    cl_object v16;
    v15 = ecl_elt(v1seq,v6start);
    v16 = ecl_elt(v1seq,v12p);
    ecl_elt_set(v1seq,v12p,v15);
    ecl_elt_set(v1seq,v6start,v16);
   }
L17:;
L20:;
   {
    cl_fixnum v15;
    v8j = (v8j)-(1);
    v15 = v8j;
    if ((v15)>(v9i)) { goto L22; }
   }
   goto L16;
L22:;
   T1 = ecl_elt(v1seq,v8j);
   T0 = (cl_env_copy->function=v5key)->cfun.entry(1, T1);
   if (Null((cl_env_copy->function=v4pred)->cfun.entry(2, T0, v14kd))) { goto L21; }
   goto L19;
L21:;
   goto L20;
L19:;
L30:;
   {
    cl_fixnum v15;
    v9i = (v9i)+(1);
    v15 = v9i;
    if ((v15)<(v8j)) { goto L32; }
   }
   goto L16;
L32:;
   T1 = ecl_elt(v1seq,v9i);
   T0 = (cl_env_copy->function=v5key)->cfun.entry(1, T1);
   if (((cl_env_copy->function=v4pred)->cfun.entry(2, T0, v14kd))!=ECL_NIL) { goto L31; }
   goto L29;
L31:;
   goto L30;
L29:;
   {
    cl_object v15;
    cl_object v16;
    v15 = ecl_elt(v1seq,v8j);
    v16 = ecl_elt(v1seq,v9i);
    ecl_elt_set(v1seq,v9i,v15);
    ecl_elt_set(v1seq,v8j,v16);
   }
   goto L17;
L16:;
   T0 = ecl_elt(v1seq,v8j);
   ecl_elt_set(v1seq,v6start,T0);
   ecl_elt_set(v1seq,v8j,v13d);
  }
  {
   cl_fixnum v9;
   v9 = (v8j)-(v6start);
   {
    cl_fixnum v10;
    v10 = (v7end)-(v8j);
    if (!((v9)<(v10))) { goto L45; }
   }
  }
  T0 = ecl_make_integer((v8j)-1);
  L16quick_sort(v1seq, ecl_make_fixnum(v6start), T0, v4pred, v5key);
  v6start = (v8j)+1;
  goto TTL;
L45:;
  T0 = ecl_make_integer((v8j)+1);
  L16quick_sort(v1seq, T0, ecl_make_fixnum(v7end), v4pred, v5key);
  v7end = (v8j)-1;
  goto TTL;
 }
L1:;
 value0 = v1seq;
 cl_env_copy->nvalues = 1;
 return value0;
}
/*	function definition for STABLE-SORT                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_stable_sort(cl_narg narg, cl_object v1sequence, cl_object v2predicate, ...)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3key;
  ecl_va_list args; ecl_va_start(args,v2predicate,narg,2);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,cl_stable_sortkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3key = keyvars[0];
  }
  if (Null(v3key)) { goto L4; }
  v3key = si_coerce_to_function(v3key);
  goto L3;
L4:;
  v3key = (ECL_SYM("IDENTITY",426)->symbol.gfdef);
L3:;
  v2predicate = si_coerce_to_function(v2predicate);
  if (!(ECL_LISTP(v1sequence))) { goto L7; }
  value0 = L15list_merge_sort(v1sequence, v2predicate, v3key);
  return value0;
L7:;
  if (ECL_STRINGP(v1sequence)) { goto L11; }
  if (!(ECL_BIT_VECTOR_P(v1sequence))) { goto L9; }
  goto L10;
L11:;
L10:;
  value0 = cl_sort(4, v1sequence, v2predicate, ECL_SYM("KEY",1262), v3key);
  return value0;
L9:;
  T0 = si_coerce_to_list(1, v1sequence);
  T1 = L15list_merge_sort(T0, v2predicate, v3key);
  T2 = L1seqtype(v1sequence);
  value0 = cl_coerce(T1, T2);
  return value0;
 }
}
/*	function definition for MERGE                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_merge(cl_narg narg, cl_object v1result_type, cl_object v2sequence1, cl_object v3sequence2, cl_object v4predicate, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<4)) FEwrong_num_arguments_anonym();
 {
  cl_object v5key;
  ecl_va_list args; ecl_va_start(args,v4predicate,narg,4);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,cl_mergekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v5key = keyvars[0];
  }
  {
   cl_fixnum v6l1;
   cl_fixnum v7l2;
   v6l1 = ecl_length(v2sequence1);
   v7l2 = ecl_length(v3sequence2);
   {
    cl_object v8key;
    if (Null(v5key)) { goto L4; }
    v8key = si_coerce_to_function(v5key);
    goto L3;
L4:;
    v8key = (ECL_SYM("IDENTITY",426)->symbol.gfdef);
L3:;
    {
     cl_object v9predicate;
     v9predicate = si_coerce_to_function(v4predicate);
     {
      cl_fixnum v10size;
      cl_fixnum v11j;
      cl_object v12newseq;
      cl_fixnum v13i1;
      cl_fixnum v14i2;
      v10size = ecl_to_fixnum(ecl_plus(ecl_make_fixnum(v6l1),ecl_make_fixnum(v7l2)));
      v11j = 0;
      v12newseq = cl_make_sequence(2, v1result_type, ecl_make_fixnum(v10size));
      v13i1 = 0;
      v14i2 = 0;
      goto L14;
L13:;
      if (!((v13i1)>=(v6l1))) { goto L17; }
      T0 = ecl_elt(v3sequence2,v14i2);
      ecl_elt_set(v12newseq,v11j,T0);
      {
       cl_object v15;
       v15 = ecl_make_integer((v14i2)+1);
       {
        bool v16;
        v16 = ECL_FIXNUMP(v15);
        if (ecl_unlikely(!(v16)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v15);
       }
       v14i2 = ecl_fixnum(v15);
      }
      goto L16;
L17:;
      {
       cl_object v15v1;
       v15v1 = ecl_elt(v2sequence1,v13i1);
       if (!((v14i2)>=(v7l2))) { goto L24; }
       ecl_elt_set(v12newseq,v11j,v15v1);
       {
        cl_object v16;
        v16 = ecl_make_integer((v13i1)+1);
        {
         bool v17;
         v17 = ECL_FIXNUMP(v16);
         if (ecl_unlikely(!(v17)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v16);
        }
        v13i1 = ecl_fixnum(v16);
       }
       goto L16;
L24:;
       {
        cl_object v16v2;
        cl_object v17k2;
        cl_object v18k1;
        v16v2 = ecl_elt(v3sequence2,v14i2);
        v17k2 = (cl_env_copy->function=v8key)->cfun.entry(1, v16v2);
        v18k1 = (cl_env_copy->function=v8key)->cfun.entry(1, v15v1);
        if (Null((cl_env_copy->function=v9predicate)->cfun.entry(2, v18k1, v17k2))) { goto L33; }
        ecl_elt_set(v12newseq,v11j,v15v1);
        {
         cl_object v19;
         v19 = ecl_make_integer((v13i1)+1);
         {
          bool v20;
          v20 = ECL_FIXNUMP(v19);
          if (ecl_unlikely(!(v20)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v19);
         }
         v13i1 = ecl_fixnum(v19);
        }
        goto L16;
L33:;
        if (Null((cl_env_copy->function=v9predicate)->cfun.entry(2, v17k2, v18k1))) { goto L39; }
        ecl_elt_set(v12newseq,v11j,v16v2);
        {
         cl_object v19;
         v19 = ecl_make_integer((v14i2)+1);
         {
          bool v20;
          v20 = ECL_FIXNUMP(v19);
          if (ecl_unlikely(!(v20)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v19);
         }
         v14i2 = ecl_fixnum(v19);
        }
        goto L16;
L39:;
        ecl_elt_set(v12newseq,v11j,v15v1);
        {
         cl_object v19;
         v19 = ecl_make_integer((v13i1)+1);
         {
          bool v20;
          v20 = ECL_FIXNUMP(v19);
          if (ecl_unlikely(!(v20)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v19);
         }
         v13i1 = ecl_fixnum(v19);
        }
       }
      }
L16:;
      {
       cl_object v15;
       v15 = ecl_make_integer((v11j)+1);
       {
        bool v16;
        v16 = ECL_FIXNUMP(v15);
        if (ecl_unlikely(!(v16)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v15);
       }
       v11j = ecl_fixnum(v15);
      }
L14:;
      if ((v11j)==(v10size)) { goto L53; }
      goto L13;
L53:;
      value0 = v12newseq;
      cl_env_copy->nvalues = 1;
      return value0;
     }
    }
   }
  }
 }
}
/*	function definition for COMPLEMENT                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L18complement(cl_object v1f)
{
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1f,env0);                   /*  F               */
  {cl_object v2;
   v2 = ECL_NIL;
   v2 = ecl_make_cclosure_va((cl_objectfn)LC17__g462,env0,Cblock);
   value0 = v2;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	closure G462                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC17__g462(cl_narg narg, ...)
{
 cl_object T0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  F               */
 { /* ... closure scanning finished */
 {
  cl_object v1x;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1x = cl_grab_rest_args(args);
  ecl_va_end(args);
  T0 = cl_apply(2, ECL_CONS_CAR(CLV0), v1x);
  value0 = Null(T0)?ECL_T:ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
 }
}

#include "lsp/seqlib.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecl29TP6va7_kR6xWE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:LSP;SEQLIB.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_ecl29TP6va7_kR6xWE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 (void)0; /* No entry created for SEQTYPE */
 ecl_cmp_defun(VV[10]);                           /*  SEQUENCE-COUNT  */
 (void)0; /* No entry created for TEST-ERROR */
 ecl_cmp_defun(VV[11]);                           /*  UNSAFE-FUNCALL1 */
 (void)0; /* No entry created for REDUCE */
 (void)0; /* No entry created for FILL */
 (void)0; /* No entry created for REPLACE */
 ecl_cmp_defun(VV[21]);                           /*  FILTER-VECTOR   */
 ecl_cmp_defun(VV[22]);                           /*  REMOVE-LIST     */
 (void)0; /* No entry created for REMOVE */
 (void)0; /* No entry created for REMOVE-IF */
 (void)0; /* No entry created for REMOVE-IF-NOT */
 ecl_cmp_defun(VV[30]);                           /*  DELETE-LIST     */
 (void)0; /* No entry created for DELETE */
 (void)0; /* No entry created for DELETE-IF */
 (void)0; /* No entry created for DELETE-IF-NOT */
 (void)0; /* No entry created for COUNT */
 (void)0; /* No entry created for COUNT-IF */
 (void)0; /* No entry created for COUNT-IF-NOT */
 (void)0; /* No entry created for SUBSTITUTE */
 (void)0; /* No entry created for SUBSTITUTE-IF */
 (void)0; /* No entry created for SUBSTITUTE-IF-NOT */
 (void)0; /* No entry created for NSUBSTITUTE */
 (void)0; /* No entry created for NSUBSTITUTE-IF */
 (void)0; /* No entry created for NSUBSTITUTE-IF-NOT */
 (void)0; /* No entry created for FIND */
 (void)0; /* No entry created for FIND-IF */
 (void)0; /* No entry created for FIND-IF-NOT */
 (void)0; /* No entry created for POSITION */
 (void)0; /* No entry created for POSITION-IF */
 (void)0; /* No entry created for POSITION-IF-NOT */
 ecl_cmp_defun(VV[43]);                           /*  REMOVE-DUPLICATES-LIST */
 (void)0; /* No entry created for REMOVE-DUPLICATES */
 ecl_cmp_defun(VV[44]);                           /*  DELETE-DUPLICATES-LIST */
 ecl_cmp_defun(VV[45]);                           /*  FILTER-DUPLICATES-VECTOR */
 (void)0; /* No entry created for DELETE-DUPLICATES */
 (void)0; /* No entry created for MISMATCH */
 (void)0; /* No entry created for SEARCH */
 (void)0; /* No entry created for SEARCH-VECTOR */
 (void)0; /* No entry created for SEARCH-GENERIC */
 (void)0; /* No entry created for SORT */
 (void)0; /* No entry created for LIST-MERGE-SORT */
 (void)0; /* No entry created for QUICK-SORT */
 (void)0; /* No entry created for STABLE-SORT */
 (void)0; /* No entry created for MERGE */
 ecl_cmp_defun(VV[54]);                           /*  COMPLEMENT      */
}
