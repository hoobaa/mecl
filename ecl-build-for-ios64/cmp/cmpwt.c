/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPWT.LSP                                     */
#include <ecl/ecl-cmp.h>
#include "cmp/cmpwt.eclh"
/*	function definition for DATA-PERMANENT-STORAGE-SIZE           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1data_permanent_storage_size()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_make_fixnum(ecl_length(ecl_symbol_value(VV[0])));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for DATA-TEMPORARY-STORAGE-SIZE           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2data_temporary_storage_size()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_make_fixnum(ecl_length(ecl_symbol_value(VV[2])));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for DATA-SIZE                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3data_size()
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = L1data_permanent_storage_size();
  T1 = L2data_temporary_storage_size();
  value0 = ecl_plus(T0,T1);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for DATA-INIT                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4data_init(volatile cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  volatile cl_object v1filename;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1filename = ECL_NIL;
   } else {
    i++;
    v1filename = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (Null(v1filename)) { goto L2; }
  if (Null(cl_probe_file(v1filename))) { goto L2; }
  {
   volatile cl_object v2s;
   v2s = cl_open(3, v1filename, ECL_SYM("DIRECTION",1218), ECL_SYM("INPUT",1254));
   {
    volatile bool unwinding = FALSE;
    cl_index v3=ECL_STACK_INDEX(cl_env_copy),v4;
    ecl_frame_ptr next_fr;
    if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
      unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
    } else {
    {
     struct ecl_stack_frame _ecl_inner_frame_aux;
     volatile cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
     {
      cl_object v5;
      v5 = _ecl_inner_frame;
      cl_set(VV[0],cl_read(1, v2s));
      cl_set(VV[2],cl_read(1, v2s));
      cl_env_copy->values[0] = ecl_symbol_value(VV[2]);
      cl_env_copy->nvalues = 1;
      ecl_stack_frame_push_values(v5);
      if (Null(v2s)) { goto L14; }
      cl_close(1, v2s);
L14:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v5);
     }
     ecl_stack_frame_close(_ecl_inner_frame);
    }
    }
    ecl_frs_pop(cl_env_copy);
    v4=ecl_stack_push_values(cl_env_copy);
    if (Null(v2s)) { goto L16; }
    cl_close(3, v2s, ECL_SYM("ABORT",1195), ECL_T);
L16:;
    ecl_stack_pop_values(cl_env_copy,v4);
    if (unwinding) ecl_unwind(cl_env_copy,next_fr);
    ECL_STACK_SET_INDEX(cl_env_copy,v3);
    return cl_env_copy->values[0];
   }
  }
L2:;
  cl_set(VV[0],si_make_vector(ECL_T, ecl_make_fixnum(128), ECL_T, ecl_make_fixnum(0), ECL_NIL, ecl_make_fixnum(0)));
  cl_set(VV[2],si_make_vector(ECL_T, ecl_make_fixnum(128), ECL_T, ecl_make_fixnum(0), ECL_NIL, ecl_make_fixnum(0)));
  value0 = ecl_symbol_value(VV[2]);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for DATA-GET-ALL-OBJECTS                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5data_get_all_objects()
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v1;
   cl_object v2array;
   cl_object v3;
   v1 = cl_list(2, ecl_symbol_value(VV[0]), ecl_symbol_value(VV[2]));
   v2array = ECL_NIL;
   v3 = v1;
   {
    cl_object v4;
    cl_object v5;
    v4 = ecl_list1(ECL_NIL);
    v5 = v4;
L6:;
    if (!(ecl_endp(v3))) { goto L8; }
    goto L7;
L8:;
    v2array = _ecl_car(v3);
    {
     cl_object v6;
     v6 = _ecl_cdr(v3);
     if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
     v3 = v6;
    }
    {
     cl_object v6;
     {
      cl_object v7object;
      cl_object v8vv_record;
      cl_object v9rest;
      cl_object v10;
      cl_fixnum v11;
      cl_fixnum v12;
      v7object = ECL_NIL;
      v8vv_record = ECL_NIL;
      v9rest = ECL_NIL;
      if (ecl_unlikely(!ECL_VECTORP(v2array))) FEtype_error_vector(v2array);
      v10 = v2array;
      v11 = 0;
      v12 = 0;
      {
       cl_object v13;
       cl_object v14;
       v13 = ecl_list1(ECL_NIL);
       v14 = v13;
       v12 = ecl_length(v10);
L28:;
       if (!((v11)>=(v12))) { goto L32; }
       goto L29;
L32:;
       {
        cl_object v15;
        {
         cl_fixnum v16;
         if (ecl_unlikely((v11)>=(v10)->vector.dim))
           FEwrong_index(ECL_NIL,v10,-1,ecl_make_fixnum(v11),(v10)->vector.dim);
         v16 = v11;
         v15 = ecl_aref_unsafe(v10,v16);
        }
        v7object = ecl_car(v15);
        v15 = ecl_cdr(v15);
        v8vv_record = ecl_car(v15);
        v15 = ecl_cdr(v15);
        v9rest = v15;
       }
       {
        cl_object v15;
        v15 = ecl_make_integer((v11)+1);
        {
         bool v16;
         v16 = ECL_FIXNUMP(v15);
         if (ecl_unlikely(!(v16)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v15);
        }
        v11 = ecl_fixnum(v15);
       }
       if (ecl_unlikely(ECL_ATOM(v14))) FEtype_error_cons(v14);
       T0 = v14;
       if (Null(ecl_gethash_safe(v7object,ecl_symbol_value(VV[6]),ECL_NIL))) { goto L57; }
       T1 = ecl_make_fixnum(0);
       goto L56;
L57:;
       if (Null(ecl_function_dispatch(cl_env_copy,VV[56])(1, v8vv_record) /*  VV-USED-P */)) { goto L59; }
       T1 = v7object;
       goto L56;
L59:;
       T1 = ecl_make_fixnum(0);
L56:;
       v14 = ecl_list1(T1);
       (ECL_CONS_CDR(T0)=v14,T0);
       goto L28;
L29:;
       v6 = ecl_cdr(v13);
       goto L18;
      }
     }
L18:;
     if (ecl_unlikely(ECL_ATOM(v5))) FEtype_error_cons(v5);
     T0 = v5;
     (ECL_CONS_CDR(T0)=v6,T0);
     if (Null(v6)) { goto L16; }
    }
    T0 = ecl_cdr(v5);
    v5 = ecl_last(T0,1);
L16:;
    goto L6;
L7:;
    value0 = ecl_cdr(v4);
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for DATA-DUMP-ARRAY                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6data_dump_array()
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_symbol_value(ECL_SYM("*COMPILER-CONSTANTS*",1017)))) { goto L1; }
  T0 = L5data_get_all_objects();
  cl_set(ECL_SYM("*COMPILER-CONSTANTS*",1017),cl_concatenate(2, ECL_SYM("VECTOR",898), T0));
  value0 = _ecl_static_1;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  T0 = L3data_size();
  if (!(ecl_plusp(T0))) { goto L5; }
  {
   cl_object v1data;
   cl_object v2data_string;
   cl_fixnum v3l;
   ecl_bds_bind(cl_env_copy,VV[8],ecl_make_fixnum(0)); /*  *WT-STRING-SIZE* */
   v1data = L5data_get_all_objects();
   {
    cl_object v4;
    v4 = ecl_symbol_value(ECL_SYM("+ECL-SYNTAX-PROGV-LIST+",1721));
    {
     cl_object v6, v7; cl_index v5;
     v6 = _ecl_car(v4);
     v7 = _ecl_cdr(v4);
     v5 = ecl_progv(cl_env_copy, v6, v7);
     v2data_string = cl_prin1_to_string(v1data);
     ecl_bds_unwind(cl_env_copy,v5);
    }
   }
   v3l = ecl_length(v2data_string);
   T0 = ecl_make_integer((v3l)-1);
   value0 = cl_subseq(3, v2data_string, ecl_make_fixnum(1), T0);
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
L5:;
  value0 = _ecl_static_1;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for DATA-C-DUMP                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7data_c_dump(cl_object volatile v1filename)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   volatile cl_object v2stream;
   v2stream = cl_open(9, v1filename, ECL_SYM("DIRECTION",1218), ECL_SYM("OUTPUT",1282), ECL_SYM("IF-DOES-NOT-EXIST",1244), ECL_SYM("CREATE",1213), ECL_SYM("IF-EXISTS",1245), ECL_SYM("SUPERSEDE",1314), ECL_SYM("EXTERNAL-FORMAT",1236), ECL_SYM("DEFAULT",1215));
   {
    volatile bool unwinding = FALSE;
    cl_index v3=ECL_STACK_INDEX(cl_env_copy),v4;
    ecl_frame_ptr next_fr;
    if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
      unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
    } else {
    {
     struct ecl_stack_frame _ecl_inner_frame_aux;
     volatile cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
     {
      cl_object v5;
      v5 = _ecl_inner_frame;
      {
       cl_object v6string;
       v6string = L6data_dump_array();
       if (Null(ecl_symbol_value(VV[10]))) { goto L8; }
       {
        cl_fixnum v7;
        v7 = ecl_length(v6string);
        if (!((v7)>0)) { goto L8; }
       }
       ecl_bds_bind(cl_env_copy,VV[8],ecl_make_fixnum(0)); /*  *WT-STRING-SIZE* */
       ecl_princ_str("static const char compiler_data_text[] = ",v2stream);
       ecl_function_dispatch(cl_env_copy,VV[59])(2, v6string, v2stream) /*  WT-FILTERED-DATA */;
       ecl_princ_char((ecl_character)(59),v2stream);
       cl_env_copy->values[0] = cl_format(3, v2stream, _ecl_static_3, ecl_symbol_value(VV[8]));
       ecl_bds_unwind1(cl_env_copy);
       goto L6;
L8:;
       ecl_princ_str("#define compiler_data_text NULL\n#define compiler_data_text_size 0",v2stream);
       cl_env_copy->values[0] = _ecl_static_4;
       cl_env_copy->nvalues = 1;
      }
L6:;
      ecl_stack_frame_push_values(v5);
      if (Null(v2stream)) { goto L16; }
      cl_close(1, v2stream);
L16:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v5);
     }
     ecl_stack_frame_close(_ecl_inner_frame);
    }
    }
    ecl_frs_pop(cl_env_copy);
    v4=ecl_stack_push_values(cl_env_copy);
    if (Null(v2stream)) { goto L18; }
    cl_close(3, v2stream, ECL_SYM("ABORT",1195), ECL_T);
L18:;
    ecl_stack_pop_values(cl_env_copy,v4);
    if (unwinding) ecl_unwind(cl_env_copy,next_fr);
    ECL_STACK_SET_INDEX(cl_env_copy,v3);
    return cl_env_copy->values[0];
   }
  }
 }
}
/*	function definition for DATA-BINARY-DUMP                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8data_binary_dump(cl_narg narg, cl_object v1filename, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2string;
  va_list args; va_start(args,v1filename);
  {
   int i = 1;
   if (i >= narg) {
    v2string = ECL_NIL;
   } else {
    i++;
    v2string = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if ((ecl_symbol_value(VV[10]))!=ECL_NIL) { goto L2; }
  value0 = v2string;
  if ((value0)!=ECL_NIL) { goto L6; }
  T0 = L6data_dump_array();
  goto L4;
L6:;
  T0 = value0;
  goto L4;
L4:;
  value0 = si_add_cdata(v1filename, T0);
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for WT-DATA-BEGIN                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L9wt_data_begin(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for WT-DATA-END                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L10wt_data_end(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_princ_char((ecl_character)(59),v1stream);
  cl_format(3, v1stream, _ecl_static_3, ecl_symbol_value(VV[8]));
  cl_set(VV[8],ecl_make_fixnum(0));
  value0 = ecl_make_fixnum(0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for DATA-EMPTY-LOC                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L11data_empty_loc()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L13add_object(5, ecl_make_fixnum(0), VV[15], ECL_T, VV[16], ECL_T);
  return value0;
 }
}
/*	function definition for ADD-LOAD-FORM                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L12add_load_form(cl_object v1object, cl_object v2location)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(clos_need_to_make_load_form_p(v1object, ecl_symbol_value(VV[18])))) { goto L1; }
  if ((ecl_symbol_value(VV[19]))==(VV[20])) { goto L3; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[65])(3, _ecl_static_5, v1object, ecl_symbol_value(VV[19])) /*  CMPERR */;
  return value0;
L3:;
  {
   cl_object v4;                                  /*  MAKE-FORM       */
   cl_object v5;                                  /*  INIT-FORM       */
   value0 = (cl_env_copy->function=(ECL_SYM("MAKE-LOAD-FORM",951)->symbol.gfdef))->cfun.entry(1, v1object) /*  MAKE-LOAD-FORM */;
   v4 = value0;
   {
    const int v6 = cl_env_copy->nvalues;
    cl_object v7;
    v7 = (v6<=1)? ECL_NIL : cl_env_copy->values[1];
    v5 = v7;
   }
   si_hash_set(v1object, ecl_symbol_value(VV[6]), v2location);
   if (Null(v4)) { goto L7; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[66])(1, v4) /*  C1EXPR   */;
   T1 = ecl_function_dispatch(cl_env_copy,VV[67])(4, VV[22], VV[23], v2location, T0) /*  MAKE-C1FORM* */;
   cl_set(VV[21],CONS(T1,ecl_symbol_value(VV[21])));
L7:;
   if (Null(v5)) { goto L10; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[66])(1, v5) /*  C1EXPR   */;
   T1 = ecl_function_dispatch(cl_env_copy,VV[67])(4, VV[24], VV[23], v2location, T0) /*  MAKE-C1FORM* */;
   cl_set(VV[21],CONS(T1,ecl_symbol_value(VV[21])));
   value0 = ecl_symbol_value(VV[21]);
   cl_env_copy->nvalues = 1;
   return value0;
L10:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for ADD-OBJECT                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L13add_object(cl_narg narg, cl_object v1object, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2duplicate;
  cl_object v3permanent;
  ecl_va_list args; ecl_va_start(args,v1object,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L13add_objectkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v2duplicate = keyvars[0];
   if (Null(keyvars[3])) {
    value0 = ecl_make_bool(ECL_SYMBOLP(v1object));
    if ((value0)!=ECL_NIL) { goto L3; }
    v3permanent = ecl_symbol_value(VV[26]);
    goto L1;
L3:;
    v3permanent = value0;
    goto L1;
L1:;
   } else {
    v3permanent = keyvars[1];
   }
  }
  {
   cl_object v4test;
   cl_object v5array;
   cl_object v6x;
   cl_fixnum v7next_ndx;
   cl_object v8found;
   if (Null(ecl_symbol_value(ECL_SYM("*COMPILER-CONSTANTS*",1017)))) { goto L6; }
   v4test = ECL_SYM("EQ",333);
   goto L5;
L6:;
   v4test = ECL_SYM("EQUAL",335);
L5:;
   if (Null(v3permanent)) { goto L9; }
   v5array = ecl_symbol_value(VV[0]);
   goto L8;
L9:;
   v5array = ecl_symbol_value(VV[2]);
L8:;
   if ((v3permanent)!=ECL_NIL) { goto L16; }
   {
    cl_object v9;
    cl_object v10;
    v9 = ecl_symbol_value(VV[0]);
    v10 = si_make_seq_iterator(2, v9, ecl_make_fixnum(0));
L20:;
    if ((v10)!=ECL_NIL) { goto L22; }
    value0 = ECL_NIL;
    goto L14;
L22:;
    {
     cl_object v11;
     v11 = si_seq_iterator_ref(v9, v10);
     T0 = ecl_car(v11);
     if (Null(ecl_function_dispatch(cl_env_copy,v4test)(2, v1object, T0))) { goto L24; }
     value0 = v11;
     goto L14;
    }
L24:;
    v10 = si_seq_iterator_next(v9, v10);
    goto L20;
   }
L16:;
   value0 = ECL_NIL;
   goto L14;
L14:;
   if ((value0)!=ECL_NIL) { goto L13; }
   {
    cl_object v9;
    v9 = si_make_seq_iterator(2, v5array, ecl_make_fixnum(0));
L30:;
    if ((v9)!=ECL_NIL) { goto L32; }
    v6x = ECL_NIL;
    goto L11;
L32:;
    {
     cl_object v10;
     v10 = si_seq_iterator_ref(v5array, v9);
     T0 = ecl_car(v10);
     if (Null(ecl_function_dispatch(cl_env_copy,v4test)(2, v1object, T0))) { goto L34; }
     v6x = v10;
     goto L11;
    }
L34:;
    v9 = si_seq_iterator_next(v5array, v9);
    goto L30;
   }
L13:;
   v6x = value0;
   goto L11;
L11:;
   v7next_ndx = ecl_length(v5array);
   v8found = ECL_NIL;
   {
    cl_object v9;
    v9 = L27add_static_constant(v1object);
    if (Null(v9)) { goto L42; }
    value0 = v9;
    cl_env_copy->nvalues = 1;
    return value0;
L42:;
    if (Null(v6x)) { goto L44; }
    if (Null(v2duplicate)) { goto L44; }
    v6x = ecl_function_dispatch(cl_env_copy,VV[69])(8, ECL_SYM("LOCATION",999), ecl_make_fixnum(v7next_ndx), VV[27], v2duplicate, VV[28], v3permanent, ECL_SYM("VALUE",1945), v1object) /*  MAKE-VV */;
    {
     cl_object v10;
     v10 = cl_list(3, v1object, v6x, ecl_make_fixnum(v7next_ndx));
     {
      cl_fixnum v11;
      cl_fixnum v12;
      v11 = ((v5array)->vector.fillp);
      v12 = ((v5array)->array.dim);
      if (!((v11)<(v12))) { goto L54; }
      {
       cl_fixnum v13;
       v13 = (1)+(v11);
       ((v5array)->vector.fillp)=(v13);
      }
      ecl_aset_unsafe(v5array,v11,v10);
      goto L49;
L54:;
      cl_vector_push_extend(2, v10, v5array);
     }
    }
L49:;
    value0 = v6x;
    cl_env_copy->nvalues = 1;
    return value0;
L44:;
    if (Null(v6x)) { goto L58; }
    value0 = ecl_cadr(v6x);
    cl_env_copy->nvalues = 1;
    return value0;
L58:;
    if ((v2duplicate)!=ECL_NIL) { goto L60; }
    if (!(ECL_SYMBOLP(v1object))) { goto L60; }
    value0 = si_mangle_name(1, v1object);
    v8found = value0;
    {
     const int v10 = cl_env_copy->nvalues;
     cl_object v11;
     v11 = (v10<=1)? ECL_NIL : cl_env_copy->values[1];
     v6x = v11;
    }
    if (Null(value0)) { goto L60; }
    value0 = v6x;
    cl_env_copy->nvalues = 1;
    return value0;
L60:;
    v6x = ecl_function_dispatch(cl_env_copy,VV[69])(8, ECL_SYM("LOCATION",999), ecl_make_fixnum(v7next_ndx), VV[27], v2duplicate, VV[28], v3permanent, ECL_SYM("VALUE",1945), v1object) /*  MAKE-VV */;
    {
     cl_object v10;
     v10 = cl_list(3, v1object, v6x, ecl_make_fixnum(v7next_ndx));
     {
      cl_fixnum v11;
      cl_fixnum v12;
      v11 = ((v5array)->vector.fillp);
      v12 = ((v5array)->array.dim);
      if (!((v11)<(v12))) { goto L72; }
      {
       cl_fixnum v13;
       v13 = (1)+(v11);
       ((v5array)->vector.fillp)=(v13);
      }
      ecl_aset_unsafe(v5array,v11,v10);
      goto L67;
L72:;
      cl_vector_push_extend(2, v10, v5array);
     }
    }
L67:;
    if ((ecl_symbol_value(ECL_SYM("*COMPILER-CONSTANTS*",1017)))!=ECL_NIL) { goto L76; }
    L12add_load_form(v1object, v6x);
L76:;
    value0 = v6x;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for ADD-SYMBOL                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L14add_symbol(cl_object v1symbol)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L13add_object(5, v1symbol, VV[15], ECL_NIL, VV[16], ECL_T);
  return value0;
 }
}
/*	function definition for ADD-KEYWORDS                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L16add_keywords(cl_object v1keywords)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2x;
   {cl_object v3;
    v3 = ECL_NIL;
    v3 = ecl_make_cfun((cl_objectfn_fixed)LC15__g62,ECL_NIL,Cblock,2);
    T0 = v3;
   }
   v2x = cl_search(4, v1keywords, ecl_symbol_value(VV[0]), ECL_SYM("TEST",1316), T0);
   if (Null(v2x)) { goto L3; }
   T0 = ecl_elt(ecl_symbol_value(VV[0]),ecl_fixnum(v2x));
   value0 = ecl_cadr(T0);
   cl_env_copy->nvalues = 1;
   return value0;
L3:;
   {
    cl_object v3;
    {
     cl_object v4;
     v4 = v1keywords;
     if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
     if (Null(v4)) { goto L10; }
     {
      cl_object v5;
      v5 = ECL_CONS_CDR(v4);
      v1keywords = v5;
      v4 = ECL_CONS_CAR(v4);
     }
L10:;
     T0 = v4;
    }
    v3 = L13add_object(5, T0, VV[15], ECL_T, VV[16], ECL_T);
    {
     cl_object v4;
     v4 = v1keywords;
     goto L20;
L19:;
     {
      cl_object v5k;
      v5k = ecl_car(v4);
      L13add_object(5, v5k, VV[15], ECL_T, VV[16], ECL_T);
     }
     v4 = ecl_cdr(v4);
L20:;
     if (Null(v4)) { goto L27; }
     goto L19;
L27:;
    }
    value0 = v3;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	local function G62                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC15__g62(cl_object v1k, cl_object v2record)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_car(v2record);
  value0 = ecl_make_bool((v1k)==(T0));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for STATIC-BASE-STRING-BUILDER            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L17static_base_string_builder(cl_object v1name, cl_object v2value, cl_object v3stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  cl_format(3, v3stream, _ecl_static_6, v1name);
  ecl_function_dispatch(cl_env_copy,VV[59])(4, v2value, v3stream, VV[32], ECL_T) /*  WT-FILTERED-DATA */;
  {
   cl_fixnum v4;
   v4 = ecl_length(v2value);
   value0 = cl_format(3, v3stream, _ecl_static_7, ecl_make_fixnum(v4));
   return value0;
  }
 }
}
/*	function definition for STATIC-SINGLE-FLOAT-BUILDER           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L18static_single_float_builder(cl_object v1name, cl_object v2value, cl_object v3stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_bds_bind(cl_env_copy,ECL_SYM("*READ-DEFAULT-FLOAT-FORMAT*",62),ECL_SYM("SINGLE-FLOAT",778)); /*  *READ-DEFAULT-FLOAT-FORMAT* */
  ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-READABLY*",57),ECL_T); /*  *PRINT-READABLY* */
  value0 = cl_format(5, v3stream, _ecl_static_8, v1name, v2value, v3stream);
  ecl_bds_unwind1(cl_env_copy);
  ecl_bds_unwind1(cl_env_copy);
  return value0;
 }
}
/*	function definition for STATIC-DOUBLE-FLOAT-BUILDER           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L19static_double_float_builder(cl_object v1name, cl_object v2value, cl_object v3stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_bds_bind(cl_env_copy,ECL_SYM("*READ-DEFAULT-FLOAT-FORMAT*",62),ECL_SYM("DOUBLE-FLOAT",315)); /*  *READ-DEFAULT-FLOAT-FORMAT* */
  ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-READABLY*",57),ECL_T); /*  *PRINT-READABLY* */
  value0 = cl_format(5, v3stream, _ecl_static_9, v1name, v2value, v3stream);
  ecl_bds_unwind1(cl_env_copy);
  ecl_bds_unwind1(cl_env_copy);
  return value0;
 }
}
/*	function definition for STATIC-LONG-FLOAT-BUILDER             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L20static_long_float_builder(cl_object v1name, cl_object v2value, cl_object v3stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_bds_bind(cl_env_copy,ECL_SYM("*READ-DEFAULT-FLOAT-FORMAT*",62),ECL_SYM("LONG-FLOAT",508)); /*  *READ-DEFAULT-FLOAT-FORMAT* */
  ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-READABLY*",57),ECL_T); /*  *PRINT-READABLY* */
  value0 = cl_format(5, v3stream, _ecl_static_10, v1name, v2value, v3stream);
  ecl_bds_unwind1(cl_env_copy);
  ecl_bds_unwind1(cl_env_copy);
  return value0;
 }
}
/*	function definition for STATIC-RATIONAL-BUILDER               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L21static_rational_builder(cl_object v1name, cl_object v2value, cl_object v3stream)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_bds_bind(cl_env_copy,ECL_SYM("*READ-DEFAULT-FLOAT-FORMAT*",62),ECL_SYM("DOUBLE-FLOAT",315)); /*  *READ-DEFAULT-FLOAT-FORMAT* */
  ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-READABLY*",57),ECL_T); /*  *PRINT-READABLY* */
  T0 = cl_numerator(v2value);
  T1 = cl_denominator(v2value);
  value0 = cl_format(5, v3stream, _ecl_static_11, v1name, T0, T1);
  ecl_bds_unwind1(cl_env_copy);
  ecl_bds_unwind1(cl_env_copy);
  return value0;
 }
}
/*	function definition for STATIC-CONSTANT-DELEGATE              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L22static_constant_delegate(cl_object v1name, cl_object v2value, cl_object v3stream)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = L26static_constant_expression(v2value);
  value0 = ecl_function_dispatch(cl_env_copy,T0)(3, v1name, v2value, v3stream);
  return value0;
 }
}
/*	function definition for STATIC-COMPLEX-BUILDER                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L23static_complex_builder(cl_object v1name, cl_object v2value, cl_object v3stream)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4name_real;
   cl_object v5name_imag;
   ecl_bds_bind(cl_env_copy,ECL_SYM("*READ-DEFAULT-FLOAT-FORMAT*",62),ECL_SYM("DOUBLE-FLOAT",315)); /*  *READ-DEFAULT-FLOAT-FORMAT* */
   ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-READABLY*",57),ECL_T); /*  *PRINT-READABLY* */
   v4name_real = cl_concatenate(3, ECL_SYM("STRING",805), v1name, _ecl_static_12);
   v5name_imag = cl_concatenate(3, ECL_SYM("STRING",805), v1name, _ecl_static_13);
   T0 = cl_realpart(v2value);
   L22static_constant_delegate(v4name_real, T0, v3stream);
   ecl_terpri(v3stream);
   T0 = cl_imagpart(v2value);
   L22static_constant_delegate(v5name_imag, T0, v3stream);
   ecl_terpri(v3stream);
   value0 = cl_format(5, v3stream, _ecl_static_14, v1name, v4name_real, v5name_imag);
   ecl_bds_unwind1(cl_env_copy);
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
 }
}
/*	function definition for STATIC-CONSTANT-BUILDER               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L25static_constant_builder(cl_object v1format, cl_object v2value)
{
 cl_object env0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1format,env0);              /*  FORMAT          */
  CLV1 = env0 = CONS(v2value,env0);               /*  VALUE           */
  {cl_object v3;
   v3 = ECL_NIL;
   v3 = ecl_make_cclosure_va((cl_objectfn)LC24__g69,env0,Cblock);
   value0 = v3;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	closure G69                                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC24__g69(cl_narg narg, cl_object v1name, cl_object v2stream, ...)
{
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  VALUE           */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=2)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = cl_format(4, v2stream, ECL_CONS_CAR(CLV0), v1name, ECL_CONS_CAR(CLV1));
  return value0;
 }
 }
}
/*	function definition for STATIC-CONSTANT-EXPRESSION            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L26static_constant_expression(cl_object v1object)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(si_base_string_p(v1object))) { goto L1; }
  value0 = ecl_fdefinition(VV[33]);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (Null(si_of_class_p(2, v1object, ECL_SYM("RATIO",686)))) { goto L3; }
  T0 = cl_numerator(v1object);
  if (Null(L26static_constant_expression(T0))) { goto L6; }
  T0 = cl_denominator(v1object);
  if (Null(L26static_constant_expression(T0))) { goto L6; }
  value0 = ecl_fdefinition(VV[37]);
  cl_env_copy->nvalues = 1;
  return value0;
L6:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L3:;
  if (!(ECL_SINGLE_FLOAT_P(v1object))) { goto L9; }
  if ((si_float_nan_p(v1object))!=ECL_NIL) { goto L12; }
  if ((si_float_infinity_p(v1object))!=ECL_NIL) { goto L12; }
  value0 = ecl_fdefinition(VV[34]);
  cl_env_copy->nvalues = 1;
  return value0;
L12:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L9:;
  if (!(ECL_DOUBLE_FLOAT_P(v1object))) { goto L15; }
  if ((si_float_nan_p(v1object))!=ECL_NIL) { goto L18; }
  if ((si_float_infinity_p(v1object))!=ECL_NIL) { goto L18; }
  value0 = ecl_fdefinition(VV[35]);
  cl_env_copy->nvalues = 1;
  return value0;
L18:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L15:;
  if (!(ECL_LONG_FLOAT_P(v1object))) { goto L21; }
  if ((si_float_nan_p(v1object))!=ECL_NIL) { goto L24; }
  if ((si_float_infinity_p(v1object))!=ECL_NIL) { goto L24; }
  value0 = ecl_fdefinition(VV[36]);
  cl_env_copy->nvalues = 1;
  return value0;
L24:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L21:;
  if (Null(cl_complexp(v1object))) { goto L27; }
  T0 = cl_realpart(v1object);
  if (Null(L26static_constant_expression(T0))) { goto L30; }
  T0 = cl_imagpart(v1object);
  if (Null(L26static_constant_expression(T0))) { goto L30; }
  value0 = ecl_fdefinition(VV[39]);
  cl_env_copy->nvalues = 1;
  return value0;
L30:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L27:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for ADD-STATIC-CONSTANT                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L27add_static_constant(cl_object v1object)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((ecl_symbol_value(ECL_SYM("*COMPILER-CONSTANTS*",1017)))!=ECL_NIL) { goto L1; }
  if (Null(ecl_symbol_value(VV[42]))) { goto L1; }
  if (!(ECL_LISTP(ecl_symbol_value(VV[43])))) { goto L1; }
  {
   cl_object v2record;
   {
    cl_object v3;
    cl_object v4;
    v3 = ecl_symbol_value(VV[43]);
    v4 = si_make_seq_iterator(2, v3, ecl_make_fixnum(0));
L8:;
    if ((v4)!=ECL_NIL) { goto L10; }
    v2record = ECL_NIL;
    goto L5;
L10:;
    {
     cl_object v5;
     v5 = si_seq_iterator_ref(v3, v4);
     T0 = ecl_car(v5);
     if (!(ecl_equal(v1object,T0))) { goto L12; }
     v2record = v5;
     goto L5;
    }
L12:;
    v4 = si_seq_iterator_next(v3, v4);
    goto L8;
   }
L5:;
   if (Null(v2record)) { goto L17; }
   value0 = ecl_cadr(v2record);
   cl_env_copy->nvalues = 1;
   return value0;
L17:;
   {
    cl_object v3builder;
    v3builder = L26static_constant_expression(v1object);
    if (Null(v3builder)) { goto L20; }
    {
     cl_object v4c_name;
     {
      cl_fixnum v5;
      v5 = ecl_length(ecl_symbol_value(VV[43]));
      v4c_name = cl_format(3, ECL_NIL, _ecl_static_15, ecl_make_fixnum(v5));
     }
     T0 = cl_list(3, v1object, v4c_name, v3builder);
     cl_set(VV[43],CONS(T0,ecl_symbol_value(VV[43])));
     value0 = ecl_function_dispatch(cl_env_copy,VV[69])(4, ECL_SYM("LOCATION",999), v4c_name, ECL_SYM("VALUE",1945), v1object) /*  MAKE-VV */;
     return value0;
    }
L20:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for WT-VV-INDEX                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L28wt_vv_index(cl_object v1index, cl_object v2permanent_p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (ecl_numberp(v1index)) { goto L1; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[83])(1, v1index) /*  WT */;
  return value0;
L1:;
  if (Null(v2permanent_p)) { goto L3; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[83])(3, _ecl_static_16, v1index, _ecl_static_17) /*  WT */;
  return value0;
L3:;
  value0 = ecl_function_dispatch(cl_env_copy,VV[83])(3, _ecl_static_18, v1index, _ecl_static_17) /*  WT */;
  return value0;
 }
}
/*	function definition for SET-VV-INDEX                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L29set_vv_index(cl_object v1loc, cl_object v2index, cl_object v3permanent_p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_function_dispatch(cl_env_copy,VV[85])(0)    /*  WT-NL           */;
  L28wt_vv_index(v2index, v3permanent_p);
  ecl_function_dispatch(cl_env_copy,VV[83])(1, _ecl_static_19) /*  WT */;
  ecl_function_dispatch(cl_env_copy,VV[86])(2, ECL_SYM("OBJECT",1278), v1loc) /*  WT-COERCE-LOC */;
  value0 = ecl_function_dispatch(cl_env_copy,VV[83])(1, _ecl_static_20) /*  WT */;
  return value0;
 }
}
/*	function definition for WT-VV                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L30wt_vv(cl_object v1vv_loc)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_structure_set(v1vv_loc,VV[47],1,ECL_T);
  T0 = ecl_function_dispatch(cl_env_copy,VV[88])(1, v1vv_loc) /*  VV-LOCATION */;
  T1 = ecl_function_dispatch(cl_env_copy,VV[89])(1, v1vv_loc) /*  VV-PERMANENT-P */;
  value0 = L28wt_vv_index(T0, T1);
  return value0;
 }
}
/*	function definition for SET-VV                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L31set_vv(cl_object v1loc, cl_object v2vv_loc)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_structure_set(v2vv_loc,VV[47],1,ECL_T);
  T0 = ecl_function_dispatch(cl_env_copy,VV[88])(1, v2vv_loc) /*  VV-LOCATION */;
  T1 = ecl_function_dispatch(cl_env_copy,VV[89])(1, v2vv_loc) /*  VV-PERMANENT-P */;
  value0 = L29set_vv_index(v1loc, T0, T1);
  return value0;
 }
}
/*	function definition for VV-TYPE                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L32vv_type(cl_object v1loc)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2value;
   v2value = ecl_function_dispatch(cl_env_copy,VV[92])(1, v1loc) /*  VV-VALUE */;
   if (Null(v2value)) { goto L2; }
   if (ECL_FIXNUMP(v2value)) { goto L2; }
   value0 = cl_type_of(v2value);
   return value0;
L2:;
   value0 = ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}

#include "cmp/cmpwt.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclBc151eNFzSSm9_dyqtVE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPWT.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclBc151eNFzSSm9_dyqtVE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[51]);                           /*  DATA-PERMANENT-STORAGE-SIZE */
 ecl_cmp_defun(VV[52]);                           /*  DATA-TEMPORARY-STORAGE-SIZE */
 ecl_cmp_defun(VV[53]);                           /*  DATA-SIZE       */
 ecl_cmp_defun(VV[54]);                           /*  DATA-INIT       */
 ecl_cmp_defun(VV[55]);                           /*  DATA-GET-ALL-OBJECTS */
 ecl_cmp_defun(VV[57]);                           /*  DATA-DUMP-ARRAY */
 ecl_cmp_defun(VV[58]);                           /*  DATA-C-DUMP     */
 ecl_cmp_defun(VV[60]);                           /*  DATA-BINARY-DUMP */
 ecl_cmp_defun(VV[61]);                           /*  WT-DATA-BEGIN   */
 ecl_cmp_defun(VV[62]);                           /*  WT-DATA-END     */
 ecl_cmp_defun(VV[63]);                           /*  DATA-EMPTY-LOC  */
 ecl_cmp_defun(VV[64]);                           /*  ADD-LOAD-FORM   */
 ecl_cmp_defun(VV[68]);                           /*  ADD-OBJECT      */
 ecl_cmp_defun(VV[70]);                           /*  ADD-SYMBOL      */
 ecl_cmp_defun(VV[71]);                           /*  ADD-KEYWORDS    */
 ecl_cmp_defun(VV[72]);                           /*  STATIC-BASE-STRING-BUILDER */
 ecl_cmp_defun(VV[73]);                           /*  STATIC-SINGLE-FLOAT-BUILDER */
 ecl_cmp_defun(VV[74]);                           /*  STATIC-DOUBLE-FLOAT-BUILDER */
 ecl_cmp_defun(VV[75]);                           /*  STATIC-LONG-FLOAT-BUILDER */
 ecl_cmp_defun(VV[76]);                           /*  STATIC-RATIONAL-BUILDER */
 ecl_cmp_defun(VV[77]);                           /*  STATIC-CONSTANT-DELEGATE */
 ecl_cmp_defun(VV[78]);                           /*  STATIC-COMPLEX-BUILDER */
 ecl_cmp_defun(VV[79]);                           /*  STATIC-CONSTANT-BUILDER */
 ecl_cmp_defun(VV[80]);                           /*  STATIC-CONSTANT-EXPRESSION */
 ecl_cmp_defun(VV[81]);                           /*  ADD-STATIC-CONSTANT */
 ecl_cmp_defun(VV[82]);                           /*  WT-VV-INDEX     */
 ecl_cmp_defun(VV[84]);                           /*  SET-VV-INDEX    */
 ecl_cmp_defun(VV[87]);                           /*  WT-VV           */
 ecl_cmp_defun(VV[90]);                           /*  SET-VV          */
 ecl_cmp_defun(VV[91]);                           /*  VV-TYPE         */
}
