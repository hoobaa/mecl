/*	Compiler: ECL 12.12.1                                         */
/*	Source: EXT:SERVE-EVENT;SERVE-EVENT.LISP                      */
#include <ecl/ecl-cmp.h>
#include "ext/serve-event.eclh"
/*	function definition for MAKE-HANDLER                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1make_handler(cl_object v1descriptor, cl_object v2direction, cl_object v3function)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((cl_functionp(v3function))!=ECL_NIL) { goto L1; }
  si_structure_type_error(4, v3function, ECL_SYM("FUNCTION",396), VV[1], ECL_SYM("FUNCTION",396));
L1:;
  if (!(ecl_eql(v2direction,ECL_SYM("INPUT",1254)))) { goto L7; }
  goto L3;
  goto L5;
L7:;
  goto L5;
L5:;
  if (!(ecl_eql(v2direction,ECL_SYM("OUTPUT",1282)))) { goto L10; }
  goto L3;
  goto L4;
L10:;
  goto L4;
L4:;
  si_structure_type_error(4, v2direction, VV[5], VV[1], VV[6]);
L3:;
  value0 = si_make_structure(4, VV[7], v2direction, v1descriptor, v3function);
  return value0;
 }
}
/*	function definition for COERCE-TO-DESCRIPTOR                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2coerce_to_descriptor(cl_object v1stream_or_fd, cl_object v2direction)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_FIXNUMP(v1stream_or_fd))) { goto L1; }
  value0 = v1stream_or_fd;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  if (Null(si_of_class_p(2, v1stream_or_fd, ECL_SYM("FILE-STREAM",358)))) { goto L3; }
  value0 = si_file_stream_fd(v1stream_or_fd);
  return value0;
L3:;
  if (Null(si_of_class_p(2, v1stream_or_fd, ECL_SYM("TWO-WAY-STREAM",866)))) { goto L5; }
  if (!(ecl_eql(v2direction,ECL_SYM("INPUT",1254)))) { goto L9; }
  v1stream_or_fd = cl_two_way_stream_input_stream(v1stream_or_fd);
  goto L8;
L9:;
  if (!(ecl_eql(v2direction,ECL_SYM("OUTPUT",1282)))) { goto L11; }
  v1stream_or_fd = cl_two_way_stream_output_stream(v1stream_or_fd);
  goto L8;
L11:;
  v1stream_or_fd = ECL_NIL;
L8:;
  goto TTL;
L5:;
  if (Null(cl_streamp(v1stream_or_fd))) { goto L14; }
  value0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("STREAM-FILE-DESCRIPTOR",1625))(2, v1stream_or_fd, v2direction) /*  STREAM-FILE-DESCRIPTOR */;
  return value0;
L14:;
  value0 = si_etypecase_error(v1stream_or_fd, VV[10]);
  return value0;
 }
}
/*	function definition for ADD-FD-HANDLER                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3add_fd_handler(cl_object v1stream_or_fd, cl_object v2direction, cl_object v3function)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ecl_eql(v2direction,ECL_SYM("INPUT",1254)))) { goto L5; }
  goto L1;
  goto L3;
L5:;
  goto L3;
L3:;
  if (!(ecl_eql(v2direction,ECL_SYM("OUTPUT",1282)))) { goto L8; }
  goto L1;
  goto L2;
L8:;
  goto L2;
L2:;
  T0 = ecl_list1(v2direction);
  cl_error(9, ECL_SYM("SIMPLE-TYPE-ERROR",773), ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_2, ECL_SYM("FORMAT-ARGUMENTS",1239), T0, ECL_SYM("DATUM",1214), v2direction, ECL_SYM("EXPECTED-TYPE",1232), VV[5]);
L1:;
  {
   cl_object v4handler;
   T0 = L2coerce_to_descriptor(v1stream_or_fd, v2direction);
   v4handler = L1make_handler(T0, v2direction, v3function);
   cl_set(VV[9],CONS(v4handler,ecl_symbol_value(VV[9])));
   value0 = v4handler;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for REMOVE-FD-HANDLER                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4remove_fd_handler(cl_object v1handler)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  cl_set(VV[9],cl_delete(2, v1handler, ecl_symbol_value(VV[9])));
  value0 = ecl_symbol_value(VV[9]);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function WITH-FD-HANDLER                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC5with_fd_handler(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   cl_object v6fd;
   cl_object v7direction;
   cl_object v8function;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v9;
    v9 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4 = v9;
   }
   v5 = v4;
   if (!(v5==ECL_NIL)) { goto L10; }
   si_dm_too_few_arguments(v1);
L10:;
   {
    cl_object v9;
    v9 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v6fd = v9;
   }
   if (!(v5==ECL_NIL)) { goto L16; }
   si_dm_too_few_arguments(v1);
L16:;
   {
    cl_object v9;
    v9 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v7direction = v9;
   }
   if (!(v5==ECL_NIL)) { goto L22; }
   si_dm_too_few_arguments(v1);
L22:;
   {
    cl_object v9;
    v9 = ecl_car(v5);
    v5 = ecl_cdr(v5);
    v8function = v9;
   }
   if (Null(v5)) { goto L27; }
   si_dm_too_many_arguments(v1);
L27:;
   {
    cl_object v9handler;
    v9handler = cl_gensym(0);
    T0 = ecl_list1(v9handler);
    T1 = cl_list(4, VV[12], v6fd, v7direction, v8function);
    T2 = cl_list(3, ECL_SYM("SETF",750), v9handler, T1);
    T3 = cl_listX(3, ECL_SYM("PROGN",671), T2, v3);
    T4 = cl_list(2, VV[13], v9handler);
    T5 = cl_list(3, ECL_SYM("WHEN",905), v9handler, T4);
    T6 = cl_list(3, ECL_SYM("UNWIND-PROTECT",888), T3, T5);
    value0 = cl_list(3, ECL_SYM("LET",477), T0, T6);
    return value0;
   }
  }
 }
}
/*	local function FD-ZERO                                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC6fd_zero(cl_object v1, cl_object v2)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4fdset;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v5;
    v5 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4fdset = v5;
   }
   if (Null(v3)) { goto L8; }
   si_dm_too_many_arguments(v1);
L8:;
   T0 = ecl_list1(v4fdset);
   value0 = cl_listX(3, ECL_SYM("C-INLINE",1973), T0, VV[15]);
   return value0;
  }
 }
}
/*	local function FD-SET                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC7fd_set(cl_object v1, cl_object v2)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4fd;
   cl_object v5fdset;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4fd = v6;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5fdset = v6;
   }
   if (Null(v3)) { goto L14; }
   si_dm_too_many_arguments(v1);
L14:;
   T0 = cl_list(2, v4fd, v5fdset);
   value0 = cl_listX(3, ECL_SYM("C-INLINE",1973), T0, VV[17]);
   return value0;
  }
 }
}
/*	local function FD-ISSET                                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC8fd_isset(cl_object v1, cl_object v2)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4fd;
   cl_object v5fdset;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4fd = v6;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5fdset = v6;
   }
   if (Null(v3)) { goto L14; }
   si_dm_too_many_arguments(v1);
L14:;
   T0 = cl_list(2, v4fd, v5fdset);
   value0 = cl_listX(3, ECL_SYM("C-INLINE",1973), T0, VV[19]);
   return value0;
  }
 }
}
/*	function definition for FDSET-SIZE                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L9fdset_size()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_make_int(sizeof(fd_set));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for SERVE-EVENT                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L10serve_event(volatile cl_narg narg, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  volatile cl_object v1seconds;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1seconds = ECL_NIL;
   } else {
    i++;
    v1seconds = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   volatile cl_object v2fsize;
   v2fsize = L9fdset_size();
   {
    volatile cl_object v3rfd;
    T0 = cl_list(3, ECL_SYM("ARRAY",1199), ECL_SYM("UNSIGNED-CHAR",1387), v2fsize);
    v3rfd = ecl_function_dispatch(cl_env_copy,ECL_SYM("ALLOCATE-FOREIGN-OBJECT",1971))(1, T0) /*  ALLOCATE-FOREIGN-OBJECT */;
    {
     volatile bool unwinding = FALSE;
     cl_index v4=ECL_STACK_INDEX(cl_env_copy),v5;
     ecl_frame_ptr next_fr;
     if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
       unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
     } else {
     {
      volatile cl_object v6wfd;
      T0 = cl_list(3, ECL_SYM("ARRAY",1199), ECL_SYM("UNSIGNED-CHAR",1387), v2fsize);
      v6wfd = ecl_function_dispatch(cl_env_copy,ECL_SYM("ALLOCATE-FOREIGN-OBJECT",1971))(1, T0) /*  ALLOCATE-FOREIGN-OBJECT */;
      {
       volatile bool unwinding = FALSE;
       cl_index v7=ECL_STACK_INDEX(cl_env_copy),v8;
       ecl_frame_ptr next_fr;
       if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
         unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
       } else {
       FD_ZERO((fd_set*)v3rfd->foreign.data);
       FD_ZERO((fd_set*)v6wfd->foreign.data);
       {
        cl_object v9maxfd;
        v9maxfd = ecl_make_fixnum(0);
        {
         cl_object v10;
         v10 = ecl_symbol_value(VV[9]);
         goto L14;
L13:;
         {
          cl_object v11handler;
          v11handler = ecl_car(v10);
          {
          cl_object v12fd;
          v12fd = ecl_function_dispatch(cl_env_copy,VV[35])(1, v11handler) /*  HANDLER-DESCRIPTOR */;
          {
          cl_object v13;
          v13 = ecl_function_dispatch(cl_env_copy,VV[36])(1, v11handler) /*  HANDLER-DIRECTION */;
          if (!(ecl_eql(v13,ECL_SYM("INPUT",1254)))) { goto L22; }
          FD_SET(ecl_to_int(v12fd), (fd_set*)v3rfd->foreign.data);;
          goto L20;
L22:;
          if (!(ecl_eql(v13,ECL_SYM("OUTPUT",1282)))) { goto L24; }
          FD_SET(ecl_to_int(v12fd), (fd_set*)v6wfd->foreign.data);;
          goto L20;
L24:;
          si_ecase_error(v13, VV[3]);
          }
L20:;
          if (!(ecl_number_compare(v12fd,v9maxfd)>0)) { goto L18; }
          v9maxfd = v12fd;
          }
L18:;
         }
         v10 = ecl_cdr(v10);
L14:;
         if (Null(v10)) { goto L30; }
         goto L13;
L30:;
        }
        {
         cl_object v11;                           /*  RETVAL          */
         cl_object v12;                           /*  ERRNO           */
         if (!(v1seconds==ECL_NIL)) { goto L33; }
         T0 = ecl_one_plus(v9maxfd);
         {
          int v13;
          int v14;
          { v13= select(ecl_to_int(T0), (fd_set*)v3rfd->foreign.data,
                                                      (fd_set*)v6wfd->foreign.data,
                                                      NULL, NULL);
                             v14= errno; }
          cl_env_copy->values[0] = ecl_make_int(v13);
          cl_env_copy->values[1] = ecl_make_int(v14);cl_env_copy->nvalues=2;
          value0 = cl_env_copy->values[0];
          goto L32;
         }
L33:;
         T0 = ecl_one_plus(v9maxfd);
         {
          int v15;
          int v16;
          { struct timeval tv;
                             double seconds = ecl_to_double(v1seconds);
                                tv.tv_sec = seconds;
                                tv.tv_usec = (seconds * 1e6);
                                v15= select(ecl_to_int(T0), (fd_set*)v3rfd->foreign.data,
                                                         (fd_set*)v6wfd->foreign.data,
                                                         NULL, &tv);
                                v16= errno; }
          cl_env_copy->values[0] = ecl_make_int(v15);
          cl_env_copy->values[1] = ecl_make_int(v16);cl_env_copy->nvalues=2;
          value0 = cl_env_copy->values[0];
         }
L32:;
         v11 = value0;
         v12 = cl_env_copy->values[1];
         if (!((ecl_fixnum(v11))==0)) { goto L35; }
         cl_env_copy->values[0] = ECL_NIL;
         cl_env_copy->nvalues = 1;
         goto L6;
L35:;
         if (!((ecl_fixnum(v11))<0)) { goto L37; }
         if (!(ecl_number_equalp(v12,ecl_symbol_value(VV[0])))) { goto L39; }
         cl_env_copy->values[0] = ECL_NIL;
         cl_env_copy->nvalues = 1;
         goto L6;
L39:;
         cl_env_copy->values[0] = cl_error(1, _ecl_static_3);
         goto L6;
L37:;
         if (!((ecl_fixnum(v11))>0)) { goto L41; }
         {
          cl_object v13;
          v13 = ecl_symbol_value(VV[9]);
          goto L47;
L46:;
          {
          cl_object v14handler;
          v14handler = ecl_car(v13);
          {
          cl_object v15fd;
          v15fd = ecl_function_dispatch(cl_env_copy,VV[35])(1, v14handler) /*  HANDLER-DESCRIPTOR */;
          {
          cl_object v16;
          v16 = ecl_function_dispatch(cl_env_copy,VV[36])(1, v14handler) /*  HANDLER-DIRECTION */;
          if (!(ecl_eql(v16,ECL_SYM("INPUT",1254)))) { goto L56; }
          T0 = ecl_make_int(FD_ISSET(ecl_to_int(v15fd), (fd_set*)v3rfd->foreign.data));
          goto L54;
L56:;
          if (!(ecl_eql(v16,ECL_SYM("OUTPUT",1282)))) { goto L58; }
          T0 = ecl_make_int(FD_ISSET(ecl_to_int(v15fd), (fd_set*)v6wfd->foreign.data));
          goto L54;
L58:;
          T0 = si_ecase_error(v16, VV[3]);
          }
L54:;
          if (!(ecl_plusp(T0))) { goto L51; }
          T0 = ecl_function_dispatch(cl_env_copy,VV[37])(1, v14handler) /*  HANDLER-FUNCTION */;
          T1 = ecl_function_dispatch(cl_env_copy,VV[35])(1, v14handler) /*  HANDLER-DESCRIPTOR */;
          ecl_function_dispatch(cl_env_copy,T0)(1, T1);
          }
L51:;
          }
          v13 = ecl_cdr(v13);
L47:;
          if (Null(v13)) { goto L63; }
          goto L46;
L63:;
         }
         cl_env_copy->values[0] = ECL_T;
         cl_env_copy->nvalues = 1;
         goto L6;
L41:;
         cl_env_copy->values[0] = ECL_NIL;
         cl_env_copy->nvalues = 1;
        }
       }
L6:;
       }
       ecl_frs_pop(cl_env_copy);
       v8=ecl_stack_push_values(cl_env_copy);
       ecl_function_dispatch(cl_env_copy,ECL_SYM("FREE-FOREIGN-OBJECT",2006))(1, v6wfd) /*  FREE-FOREIGN-OBJECT */;
       ecl_stack_pop_values(cl_env_copy,v8);
       if (unwinding) ecl_unwind(cl_env_copy,next_fr);
       ECL_STACK_SET_INDEX(cl_env_copy,v7);
      }
     }
     }
     ecl_frs_pop(cl_env_copy);
     v5=ecl_stack_push_values(cl_env_copy);
     ecl_function_dispatch(cl_env_copy,ECL_SYM("FREE-FOREIGN-OBJECT",2006))(1, v3rfd) /*  FREE-FOREIGN-OBJECT */;
     ecl_stack_pop_values(cl_env_copy,v5);
     if (unwinding) ecl_unwind(cl_env_copy,next_fr);
     ECL_STACK_SET_INDEX(cl_env_copy,v4);
     return cl_env_copy->values[0];
    }
   }
  }
 }
}
/*	function definition for SERVE-ALL-EVENTS                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L11serve_all_events(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1timeout;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1timeout = ECL_NIL;
   } else {
    i++;
    v1timeout = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v2;
   cl_object v3res;
   cl_object v4sval;
   v2 = L10serve_event(1, v1timeout);
   v3res = ECL_NIL;
   v4sval = v2;
   goto L7;
L6:;
   v3res = ECL_T;
   v4sval = L10serve_event(1, ecl_make_fixnum(0));
L7:;
   if (v4sval==ECL_NIL) { goto L13; }
   goto L6;
L13:;
   value0 = v3res;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}

#include "ext/serve-event.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclrvERBJLFNbNm9_FfEkYE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("EXT:SERVE-EVENT;SERVE-EVENT.LISP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclrvERBJLFNbNm9_FfEkYE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 ecl_function_dispatch(cl_env_copy,VV[24])(10, _ecl_static_0, ECL_NIL, ECL_NIL, VVtemp[0], ECL_NIL, ECL_NIL, VVtemp[1], ECL_NIL, ECL_NIL, ECL_NIL) /*  DODEFPACKAGE */;
 si_select_package(_ecl_static_0);
 {
  cl_fixnum v1;
  v1 = (cl_fixnum)(EINTR);
  si_Xmake_constant(VV[0], ecl_make_fixnum(v1));
 }
 si_define_structure(15, VV[1], _ecl_static_1, ECL_NIL, ECL_NIL, VVtemp[2], VVtemp[3], ECL_NIL, ECL_NIL, ECL_NIL, ECL_NIL, VVtemp[4], ecl_make_fixnum(3), ECL_NIL, ECL_NIL, VV[2]);
 VV[7]= cl_find_class(1, VV[1]);
 ecl_cmp_defun(VV[25]);                           /*  MAKE-HANDLER    */
 si_Xmake_special(VV[9]);
 if (ecl_boundp(cl_env_copy,VV[9])) { goto L20; }
 cl_set(VV[9],ECL_NIL);
L20:;
 ecl_cmp_defun(VV[26]);                           /*  COERCE-TO-DESCRIPTOR */
 ecl_cmp_defun(VV[27]);                           /*  ADD-FD-HANDLER  */
 ecl_cmp_defun(VV[28]);                           /*  REMOVE-FD-HANDLER */
 ecl_cmp_defmacro(VV[29]);                        /*  WITH-FD-HANDLER */
 ecl_cmp_defmacro(VV[30]);                        /*  FD-ZERO         */
 ecl_cmp_defmacro(VV[31]);                        /*  FD-SET          */
 ecl_cmp_defmacro(VV[32]);                        /*  FD-ISSET        */
 ecl_cmp_defun(VV[33]);                           /*  FDSET-SIZE      */
 ecl_cmp_defun(VV[34]);                           /*  SERVE-EVENT     */
 ecl_cmp_defun(VV[38]);                           /*  SERVE-ALL-EVENTS */
 cl_provide(VV[22]);
}
