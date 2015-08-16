/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:LSP;MISLIB.LSP                                    */
#include <ecl/ecl-cmp.h>
#include "lsp/mislib.eclh"
/*	function definition for LOGICAL-PATHNAME-TRANSLATIONS         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_logical_pathname_translations(cl_object v1p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = si_pathname_translations(1, v1p);
  return value0;
 }
}
/*	function definition for LOAD-LOGICAL-PATHNAME-TRANSLATIONS    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_load_logical_pathname_translations(cl_object volatile v1host)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   bool v2;
   v2 = ECL_STRINGP(v1host);
   if (ecl_unlikely(!(v2)))
         FEwrong_type_argument(ECL_SYM("STRING",805),v1host);
  }
  if ((cl_string_equal(2, v1host, _ecl_static_1))!=ECL_NIL) { goto L2; }
  if ((si_pathname_translations(1, v1host))!=ECL_NIL) { goto L2; }
  {
   volatile cl_object v2in_str;
   T0 = cl_string_downcase(1, v1host);
   T1 = cl_make_pathname(6, ECL_SYM("DEFAULTS",1216), _ecl_static_2, ECL_SYM("NAME",1273), T0, ECL_SYM("TYPE",1318), _ecl_static_3);
   v2in_str = cl_open(1, T1);
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
      if (Null(ecl_symbol_value(ECL_SYM("*LOAD-VERBOSE*",39)))) { goto L12; }
      T0 = ecl_symbol_value(ECL_SYM("*ERROR-OUTPUT*",33));
      T1 = cl_truename(v2in_str);
      T2 = cl_namestring(T1);
      cl_format(3, T0, _ecl_static_4, T2);
L12:;
      T0 = cl_read(1, v2in_str);
      cl_env_copy->values[0] = si_pathname_translations(2, v1host, T0);
      ecl_stack_frame_push_values(v5);
      if (Null(v2in_str)) { goto L14; }
      cl_close(1, v2in_str);
L14:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v5);
     }
     ecl_stack_frame_close(_ecl_inner_frame);
    }
    }
    ecl_frs_pop(cl_env_copy);
    v4=ecl_stack_push_values(cl_env_copy);
    if (Null(v2in_str)) { goto L16; }
    cl_close(3, v2in_str, ECL_SYM("ABORT",1195), ECL_T);
L16:;
    ecl_stack_pop_values(cl_env_copy,v4);
    if (unwinding) ecl_unwind(cl_env_copy,next_fr);
    ECL_STACK_SET_INDEX(cl_env_copy,v3);
   }
  }
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for DO-TIME                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1do_time(cl_object v1closure)
{
 cl_object T0, T1, T2, T3, T4, T5;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2real_start;
   cl_object v3run_start;
   cl_object v4consed_start;
   cl_object v5gc_no_start;
   cl_object v6real_end;
   cl_object v7run_end;
   cl_object v8consed_end;
   cl_object v9gc_no_end;
   T0 = ecl_one_plus(ecl_symbol_value(VV[0]));
   ecl_bds_bind(cl_env_copy,VV[0],T0);            /*  *DO-TIME-LEVEL* */
   v2real_start = ECL_NIL;
   v3run_start = ECL_NIL;
   v4consed_start = ECL_NIL;
   v5gc_no_start = ECL_NIL;
   v6real_end = ECL_NIL;
   v7run_end = ECL_NIL;
   v8consed_end = ECL_NIL;
   v9gc_no_end = ECL_NIL;
   si_gc(1, ECL_T);
   if (!(ecl_zerop(ecl_symbol_value(VV[0])))) { goto L10; }
   si_gc_stats(ecl_make_fixnum(0));
L10:;
   value0 = si_gc_stats(ECL_T);
   v4consed_start = value0;
   {
    const int v10 = cl_env_copy->nvalues;
    cl_object v11;
    v11 = (v10<=1)? ECL_NIL : cl_env_copy->values[1];
    v5gc_no_start = v11;
   }
   v2real_start = cl_get_internal_real_time();
   v3run_start = cl_get_internal_run_time();
   {
    struct ecl_stack_frame _ecl_inner_frame_aux;
    cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
    {
     cl_object v10;
     v10 = _ecl_inner_frame;
     cl_env_copy->values[0] = ecl_function_dispatch(cl_env_copy,v1closure)(0);
     ecl_stack_frame_push_values(v10);
     v7run_end = cl_get_internal_run_time();
     v6real_end = cl_get_internal_real_time();
     si_gc(1, ECL_T);
     value0 = si_gc_stats(ECL_NIL);
     v8consed_end = value0;
     {
      const int v11 = cl_env_copy->nvalues;
      cl_object v12;
      v12 = (v11<=1)? ECL_NIL : cl_env_copy->values[1];
      v9gc_no_end = v12;
     }
     cl_fresh_line(1, ecl_symbol_value(ECL_SYM("*TRACE-OUTPUT*",69)));
     T0 = ecl_minus(v6real_end,v2real_start);
     T1 = ecl_divide(T0,ecl_make_fixnum(1000));
     T2 = ecl_minus(v7run_end,v3run_start);
     T3 = ecl_divide(T2,ecl_make_fixnum(1000));
     T4 = ecl_minus(v9gc_no_end,v5gc_no_start);
     T5 = ecl_minus(v8consed_end,v4consed_start);
     cl_format(6, ecl_symbol_value(ECL_SYM("*TRACE-OUTPUT*",69)), _ecl_static_5, T1, T3, T4, T5);cl_env_copy->values[0]=ecl_stack_frame_pop_values(v10);
     value0 = cl_env_copy->values[0];
    }
    ecl_stack_frame_close(_ecl_inner_frame);
   }
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
 }
}
/*	local function TIME                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC2time(cl_object v1, cl_object v2)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4form;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4form = v5;
   }
   if (Null(v3)) { goto L8; }
   si_dm_too_many_arguments(v1);
L8:;
   T0 = cl_list(3, ECL_SYM("LAMBDA",452), ECL_NIL, v4form);
   T1 = cl_list(2, ECL_SYM("FUNCTION",396), T0);
   value0 = cl_list(2, VV[1], T1);
   return value0;
  }
 }
}
/*	function definition for LEAP-YEAR-P                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3leap_year_p(cl_object v1y)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = (ecl_floor2(v1y,ecl_make_fixnum(4)),cl_env_copy->values[1]);
  if (!(ecl_zerop(T0))) { goto L2; }
  T0 = (ecl_floor2(v1y,ecl_make_fixnum(100)),cl_env_copy->values[1]);
  {
   bool v2;
   v2 = ecl_zerop(T0);
   value0 = (v2)?ECL_NIL:ECL_T;
  }
  if ((value0)!=ECL_NIL) { goto L5; }
  T0 = (ecl_floor2(v1y,ecl_make_fixnum(400)),cl_env_copy->values[1]);
  value0 = ecl_make_bool(ecl_zerop(T0));
  cl_env_copy->nvalues = 1;
  return value0;
L5:;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for NUMBER-OF-DAYS-FROM-1900              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4number_of_days_from_1900(cl_object v1y)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2y1;
   v2y1 = ecl_one_minus(v1y);
   T0 = ecl_minus(v1y,ecl_make_fixnum(1900));
   T1 = ecl_times(T0,ecl_make_fixnum(365));
   T2 = ecl_floor2(v2y1,ecl_make_fixnum(4));
   T3 = ecl_plus(T1,T2);
   T4 = ecl_floor2(v2y1,ecl_make_fixnum(100));
   T5 = ecl_negate(T4);
   T6 = ecl_plus(T3,T5);
   T7 = ecl_floor2(v2y1,ecl_make_fixnum(400));
   T8 = ecl_plus(T6,T7);
   value0 = ecl_plus(T8,ecl_make_fixnum(-460));
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for GET-LOCAL-TIME-ZONE                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5get_local_time_zone()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v1;
   
{
  cl_fixnum mw;
#if 0 && defined(HAVE_TZSET)
  tzset();
  mw = timezone/60;
#else
  struct tm ltm, gtm;
  time_t when = time(0) /*0L*/;

  ltm = *localtime(&when);
  gtm = *gmtime(&when);

  mw = (gtm.tm_min + 60 * gtm.tm_hour) - (ltm.tm_min + 60 * ltm.tm_hour);

  if ((gtm.tm_wday + 1) % 7 == ltm.tm_wday)
    mw -= 24*60;
  else if (gtm.tm_wday == (ltm.tm_wday + 1) % 7)
    mw += 24*60;
#endif
  v1= ecl_make_ratio(ecl_make_fixnum(mw),ecl_make_fixnum(60));
}
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for RECODE-UNIVERSAL-TIME                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6recode_universal_time(cl_object v1sec, cl_object v2min, cl_object v3hour, cl_object v4day, cl_object v5month, cl_object v6year, cl_object v7tz, cl_object v8dst)
{
 cl_object T0, T1, T2, T3, T4, T5, T6;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v9days;
   {
    cl_fixnum v10;
    if (Null(L3leap_year_p(v6year))) { goto L3; }
    if (!(ecl_number_compare(v5month,ecl_make_fixnum(2))>0)) { goto L3; }
    v10 = 1;
    goto L2;
L3:;
    v10 = 0;
L2:;
    T0 = ecl_one_minus(v4day);
    T1 = ecl_plus(ecl_make_fixnum(v10),T0);
    T2 = ecl_one_minus(v5month);
    T3 = ecl_aref1(ecl_symbol_value(VV[3]),ecl_to_size(T2));
    T4 = ecl_plus(T1,T3);
    T5 = L4number_of_days_from_1900(v6year);
    v9days = ecl_plus(T4,T5);
   }
   T0 = ecl_plus(v7tz,v8dst);
   T1 = ecl_plus(T0,v3hour);
   T2 = ecl_times(ecl_make_fixnum(24),v9days);
   T3 = ecl_plus(T1,T2);
   T4 = ecl_times(ecl_make_fixnum(60),T3);
   T5 = ecl_plus(v2min,T4);
   T6 = ecl_times(ecl_make_fixnum(60),T5);
   value0 = ecl_plus(v1sec,T6);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for DECODE-UNIVERSAL-TIME                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_decode_universal_time(cl_narg narg, cl_object v1orig_ut, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2tz;
  cl_object v3tz_p;
  va_list args; va_start(args,v1orig_ut);
  {
   int i = 1;
   if (i >= narg) {
    v2tz = ECL_NIL;
    v3tz_p = ECL_NIL;
   } else {
    i++;
    v2tz = va_arg(args,cl_object);
    v3tz_p = ECL_T;
   }
  }
  va_end(args);
  {
   cl_object v4dstp;
   v4dstp = ECL_NIL;
L3:;
   {
    cl_object v5ut;
    cl_object v6sec;
    cl_object v7min;
    cl_object v8hour;
    cl_object v9day;
    cl_object v10month;
    cl_object v11year;
    cl_object v12dow;
    cl_object v13days;
    v5ut = v1orig_ut;
    v6sec = ECL_NIL;
    v7min = ECL_NIL;
    v8hour = ECL_NIL;
    v9day = ECL_NIL;
    v10month = ECL_NIL;
    v11year = ECL_NIL;
    v12dow = ECL_NIL;
    v13days = ECL_NIL;
    if ((v2tz)!=ECL_NIL) { goto L14; }
    v2tz = L5get_local_time_zone();
L14:;
    {
     cl_object v14;
     {
      cl_fixnum v15;
      if (Null(v4dstp)) { goto L20; }
      v15 = -1;
      goto L19;
L20:;
      v15 = 0;
L19:;
      T0 = ecl_plus(v2tz,ecl_make_fixnum(v15));
      T1 = ecl_times(T0,ecl_make_fixnum(3600));
      v14 = ecl_round1(T1);
     }
     v5ut = ecl_minus(v5ut,v14);
    }
    value0 = ecl_floor2(v5ut,ecl_make_fixnum(60));
    v5ut = value0;
    v6sec = cl_env_copy->values[1];
    value0 = ecl_floor2(v5ut,ecl_make_fixnum(60));
    v5ut = value0;
    v7min = cl_env_copy->values[1];
    value0 = ecl_floor2(v5ut,ecl_make_fixnum(24));
    v13days = value0;
    v8hour = cl_env_copy->values[1];
    v12dow = (ecl_floor2(v13days,ecl_make_fixnum(7)),cl_env_copy->values[1]);
    T0 = ecl_floor2(v13days,ecl_make_fixnum(366));
    v11year = ecl_plus(ecl_make_fixnum(1900),T0);
    {
     cl_object v14x;
     v14x = ECL_NIL;
     goto L37;
L36:;
     v11year = ecl_plus(v11year,ecl_make_fixnum(1));
L37:;
     T0 = L4number_of_days_from_1900(v11year);
     v14x = ecl_minus(v13days,T0);
     {
      cl_fixnum v15;
      if (Null(L3leap_year_p(v11year))) { goto L45; }
      v15 = 366;
      goto L44;
L45:;
      v15 = 365;
L44:;
      if (ecl_number_compare(v14x,ecl_make_fixnum(v15))<0) { goto L41; }
     }
     goto L36;
L41:;
     v9day = ecl_one_plus(v14x);
    }
    if (Null(L3leap_year_p(v11year))) { goto L48; }
    if (!(ecl_number_equalp(v9day,ecl_make_fixnum(60)))) { goto L50; }
    v10month = ecl_make_fixnum(2);
    v9day = ecl_make_fixnum(29);
    goto L48;
L50:;
    if (!(ecl_number_compare(v9day,ecl_make_fixnum(60))>0)) { goto L48; }
    v9day = ecl_minus(v9day,ecl_make_fixnum(1));
L48:;
    if ((v10month)!=ECL_NIL) { goto L57; }
    T0 = ecl_symbol_value(VV[3]);
    T1 = (ECL_SYM("<=",73)->symbol.gfdef);
    v10month = cl_position(4, v9day, T0, ECL_SYM("TEST",1316), T1);
    T0 = ecl_one_minus(v10month);
    T1 = ecl_aref1(ecl_symbol_value(VV[3]),ecl_to_size(T0));
    v9day = ecl_minus(v9day,T1);
L57:;
    if ((v3tz_p)!=ECL_NIL) { goto L63; }
    if (Null(L7daylight_saving_time_p(v1orig_ut, v11year))) { goto L63; }
    v3tz_p = ECL_T;
    v4dstp = ECL_T;
    goto L4;
L63:;
    cl_env_copy->nvalues = 9;
    cl_env_copy->values[8] = v2tz;
    cl_env_copy->values[7] = v4dstp;
    cl_env_copy->values[6] = v12dow;
    cl_env_copy->values[5] = v11year;
    cl_env_copy->values[4] = v10month;
    cl_env_copy->values[3] = v9day;
    cl_env_copy->values[2] = v8hour;
    cl_env_copy->values[1] = v7min;
    cl_env_copy->values[0] = v6sec;
    return cl_env_copy->values[0];
   }
L4:;
   goto L3;
  }
 }
}
/*	function definition for ENCODE-UNIVERSAL-TIME                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_encode_universal_time(cl_narg narg, cl_object v1sec, cl_object v2min, cl_object v3hour, cl_object v4day, cl_object v5month, cl_object v6year, ...)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<6)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>7)) FEwrong_num_arguments_anonym();
 {
  int8_t v7sec;
  int8_t v8min;
  int8_t v9hour;
  int8_t v10day;
  int8_t v11month;
  cl_object v12tz;
  va_list args; va_start(args,v6year);
  v7sec = ecl_to_int8_t(v1sec);
  v8min = ecl_to_int8_t(v2min);
  v9hour = ecl_to_int8_t(v3hour);
  v10day = ecl_to_int8_t(v4day);
  v11month = ecl_to_int8_t(v5month);
  {
   int i = 6;
   if (i >= narg) {
    v12tz = ECL_NIL;
   } else {
    i++;
    v12tz = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (Null(cl_LE(3, ecl_make_fixnum(0), v6year, ecl_make_fixnum(99)))) { goto L2; }
  {
   cl_object v14;                                 /*  THIS-YEAR       */
   value0 = cl_get_decoded_time();
   v14 = cl_env_copy->values[5];
   {
    cl_object v15;
    T0 = ecl_minus(v14,v6year);
    T1 = ecl_minus(T0,ecl_make_fixnum(50));
    T2 = ecl_ceiling2(T1,ecl_make_fixnum(100));
    v15 = ecl_times(ecl_make_fixnum(100),T2);
    {
     cl_object v16;
     v16 = ecl_plus(v6year,v15);
     {
      cl_object v17;
      v17 = ecl_make_fixnum(0);
      v17 = v16;
      T0 = ecl_make_bool(ecl_number_compare(v17,ecl_make_fixnum(0))>=0);
      goto L9;
      T0 = ECL_NIL;
      goto L9;
     }
L9:;
     if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("UNSIGNED-BYTE",885),v16);
     v6year = v16;
    }
   }
  }
L2:;
  {
   cl_object v13dst;
   v13dst = ecl_make_fixnum(0);
   if ((v12tz)!=ECL_NIL) { goto L17; }
   T0 = L5get_local_time_zone();
   v12tz = cl_rational(T0);
   T0 = L6recode_universal_time(ecl_make_int8_t(v7sec), ecl_make_int8_t(v8min), ecl_make_int8_t(v9hour), ecl_make_int8_t(v10day), ecl_make_int8_t(v11month), v6year, v12tz, ecl_make_fixnum(-1));
   if (Null(L7daylight_saving_time_p(T0, v6year))) { goto L17; }
   v13dst = ecl_make_fixnum(-1);
L17:;
   value0 = L6recode_universal_time(ecl_make_int8_t(v7sec), ecl_make_int8_t(v8min), ecl_make_int8_t(v9hour), ecl_make_int8_t(v10day), ecl_make_int8_t(v11month), v6year, v12tz, v13dst);
   return value0;
  }
 }
}
/*	function definition for DAYLIGHT-SAVING-TIME-P                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7daylight_saving_time_p(cl_object v1universal_time, cl_object v2year)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3unix_time;
   v3unix_time = ecl_minus(v1universal_time,ecl_make_fixnum(2208988800));
   if (!(ecl_minusp(v3unix_time))) { goto L3; }
   {
    cl_fixnum v4;
    if (Null(L3leap_year_p(v2year))) { goto L7; }
    v4 = 2524521600;
    goto L6;
L7:;
    v4 = 2556144000;
L6:;
    T0 = cl_encode_universal_time(7, ecl_make_fixnum(0), ecl_make_fixnum(0), ecl_make_fixnum(0), ecl_make_fixnum(1), ecl_make_fixnum(1), v2year, ecl_make_fixnum(0));
    T1 = ecl_minus(v1universal_time,T0);
    T2 = ecl_minus(T1,ecl_make_fixnum(2208988800));
    v3unix_time = ecl_plus(ecl_make_fixnum(v4),T2);
   }
   goto L2;
L3:;
   if (ECL_FIXNUMP(v3unix_time)) { goto L2; }
   {
    cl_fixnum v4;
    if (Null(L3leap_year_p(v2year))) { goto L12; }
    v4 = 4165516800;
    goto L11;
L12:;
    v4 = 4197139200;
L11:;
    T0 = cl_encode_universal_time(7, ecl_make_fixnum(0), ecl_make_fixnum(0), ecl_make_fixnum(0), ecl_make_fixnum(1), ecl_make_fixnum(1), v2year, ecl_make_fixnum(0));
    T1 = ecl_minus(v1universal_time,T0);
    T2 = ecl_minus(T1,ecl_make_fixnum(2208988800));
    v3unix_time = ecl_plus(ecl_make_fixnum(v4),T2);
   }
L2:;
   {
    bool v4;
    
{
	time_t when = (ecl_to_ulong(v3unix_time));
	struct tm *ltm = localtime(&when);
	v4= ltm->tm_isdst;
}
    value0 = ecl_make_bool(v4);
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for GET-DECODED-TIME                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_get_decoded_time()
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_get_universal_time();
  value0 = cl_decode_universal_time(1, T0);
  return value0;
 }
}
/*	function definition for ENSURE-DIRECTORIES-EXIST              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object cl_ensure_directories_exist(cl_narg narg, cl_object v1pathname, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2verbose;
  cl_object v3mode;
  ecl_va_list args; ecl_va_start(args,v1pathname,narg,1);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,cl_ensure_directories_existkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v2verbose = keyvars[0];
   if (Null(keyvars[3])) {
    v3mode = ecl_make_fixnum(511);
   } else {
    v3mode = keyvars[1];
   }
  }
  {
   cl_object v4created;
   cl_object v5full_pathname;
   cl_object v6d;
   v4created = ECL_NIL;
   v5full_pathname = cl_merge_pathnames(1, v1pathname);
   v6d = ECL_NIL;
   if (Null(si_logical_pathname_p(v5full_pathname))) { goto L5; }
   v5full_pathname = cl_translate_logical_pathname(1, v5full_pathname);
L5:;
   if ((cl_wild_pathname_p(2, v5full_pathname, ECL_SYM("DIRECTORY",1219)))!=ECL_NIL) { goto L10; }
   if ((cl_wild_pathname_p(2, v5full_pathname, ECL_SYM("HOST",1243)))!=ECL_NIL) { goto L10; }
   if (Null(cl_wild_pathname_p(2, v5full_pathname, ECL_SYM("DEVICE",1217)))) { goto L8; }
   goto L9;
L10:;
L9:;
   cl_error(3, ECL_SYM("FILE-ERROR",353), ECL_SYM("PATHNAME",1285), v1pathname);
L8:;
   T0 = cl_make_pathname(8, ECL_SYM("NAME",1273), ECL_NIL, ECL_SYM("TYPE",1318), ECL_NIL, ECL_SYM("DIRECTORY",1219), ECL_NIL, ECL_SYM("DEFAULTS",1216), v5full_pathname);
   ecl_bds_bind(cl_env_copy,ECL_SYM("*DEFAULT-PATHNAME-DEFAULTS*",32),T0); /*  *DEFAULT-PATHNAME-DEFAULTS* */
   {
    cl_object v7;
    v7 = cl_pathname_directory(1, v5full_pathname);
    goto L17;
L16:;
    {
     cl_object v8item;
     v8item = ecl_car(v7);
     T0 = ecl_list1(v8item);
     v6d = ecl_nconc(v6d,T0);
     {
      cl_object v9p;
      v9p = cl_make_pathname(4, ECL_SYM("DIRECTORY",1219), v6d, ECL_SYM("DEFAULTS",1216), ecl_symbol_value(ECL_SYM("*DEFAULT-PATHNAME-DEFAULTS*",32)));
      if (ECL_SYMBOLP(v8item)) { goto L23; }
      if ((si_file_kind(v9p, ECL_NIL))!=ECL_NIL) { goto L23; }
      v4created = ECL_T;
      {
       cl_object v10ps;
       v10ps = cl_namestring(v9p);
       if (Null(v2verbose)) { goto L30; }
       cl_format(3, ECL_T, _ecl_static_6, v10ps);
L30:;
       si_mkdir(v10ps, v3mode);
      }
     }
L23:;
    }
    v7 = ecl_cdr(v7);
L17:;
    if (Null(v7)) { goto L34; }
    goto L16;
L34:;
   }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v4created;
   cl_env_copy->values[0] = v1pathname;
   ecl_bds_unwind1(cl_env_copy);
   return cl_env_copy->values[0];
  }
 }
}
/*	local function WITH-HASH-TABLE-ITERATOR                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC8with_hash_table_iterator(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6iterator;
   cl_object v7package;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v8;
    v8 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4 = v8;
   }
   v5 = v4;
   if (!(v5==ECL_NIL)) { goto L10; }
   si_dm_too_few_arguments(v1);
L10:;
   {
    cl_object v8;
    v8 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v6iterator = v8;
   }
   if (!(v5==ECL_NIL)) { goto L16; }
   si_dm_too_few_arguments(v1);
L16:;
   {
    cl_object v8;
    v8 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v7package = v8;
   }
   if (Null(v5)) { goto L21; }
   si_dm_too_many_arguments(v1);
L21:;
   T0 = cl_list(2, ECL_SYM("HASH-TABLE-ITERATOR",1089), v7package);
   T1 = cl_list(2, v6iterator, T0);
   T2 = ecl_list1(T1);
   T3 = cl_list(2, ECL_SYM("QUOTE",679), v6iterator);
   T4 = cl_list(3, ECL_SYM("LIST",481), VV[4], T3);
   T5 = cl_list(3, v6iterator, ECL_NIL, T4);
   T6 = ecl_list1(T5);
   T7 = cl_listX(3, ECL_SYM("MACROLET",521), T6, v3);
   value0 = cl_list(3, ECL_SYM("LET",477), T2, T7);
   return value0;
  }
 }
}
/*	function definition for SHARP-!-READER                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L9sharp___reader(cl_object v1stream, cl_object v2subchar, cl_object v3arg)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  cl_read_line(1, v1stream);
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  return value0;
 }
}
/*	function definition for SIMPLE-PROGRAM-ERROR                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_simple_program_error(cl_narg narg, cl_object v1message, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2datum;
  ecl_va_list args; ecl_va_start(args,v1message,narg,1);
  v2datum = cl_grab_rest_args(args);
  ecl_va_end(args);
  value0 = si_signal_simple_error(4, ECL_SYM("PROGRAM-ERROR",672), ECL_NIL, v1message, v2datum);
  return value0;
 }
}

#include "lsp/mislib.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclATunWhrIuBer9_MGN5hE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:LSP;MISLIB.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclATunWhrIuBer9_MGN5hE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 (void)0; /* No entry created for LOGICAL-PATHNAME-TRANSLATIONS */
 si_do_defsetf(ECL_SYM("LOGICAL-PATHNAME-TRANSLATIONS",499), ECL_SYM("PATHNAME-TRANSLATIONS",1116));
 (void)0; /* No entry created for LOAD-LOGICAL-PATHNAME-TRANSLATIONS */
 si_Xmake_special(VV[0]);
 cl_set(VV[0],ecl_make_fixnum(-1));
 ecl_cmp_defun(VV[7]);                            /*  DO-TIME         */
 ecl_cmp_defmacro(VV[8]);                         /*  TIME            */
 (void)0; /* No entry created for LEAP-YEAR-P */
 (void)0; /* No entry created for NUMBER-OF-DAYS-FROM-1900 */
 si_Xmake_constant(VV[3], VVtemp[0]);
 (void)0; /* No entry created for GET-LOCAL-TIME-ZONE */
 (void)0; /* No entry created for RECODE-UNIVERSAL-TIME */
 (void)0; /* No entry created for DECODE-UNIVERSAL-TIME */
 (void)0; /* No entry created for ENCODE-UNIVERSAL-TIME */
 (void)0; /* No entry created for DAYLIGHT-SAVING-TIME-P */
 (void)0; /* No entry created for GET-DECODED-TIME */
 (void)0; /* No entry created for ENSURE-DIRECTORIES-EXIST */
 ecl_cmp_defmacro(VV[11]);                        /*  WITH-HASH-TABLE-ITERATOR */
 ecl_cmp_defun(VV[12]);                           /*  SHARP-!-READER  */
 cl_set_dispatch_macro_character(3, CODE_CHAR(35), CODE_CHAR(33), VV[6]);
 (void)0; /* No entry created for SIMPLE-PROGRAM-ERROR */
}
