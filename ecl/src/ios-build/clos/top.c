/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:LSP;TOP.LSP                                       */
#include <ecl/ecl-cmp.h>
#include "clos/top.eclh"
/*	function definition for TOP-LEVEL                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1top_level(volatile cl_narg narg, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  volatile cl_object v1process_command_line;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1process_command_line = ECL_NIL;
   } else {
    i++;
    v1process_command_line = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = ecl_symbol_value(ECL_SYM("*QUIT-TAG*",1737));
  if (ecl_frs_push(cl_env_copy,value0)) {         /*  BEGIN CATCH 2   */
   value0 = cl_env_copy->values[0];
  } else {
   ecl_bds_bind(cl_env_copy,ECL_SYM("*DEBUGGER-HOOK*",31),ECL_NIL); /*  *DEBUGGER-HOOK* */
   ecl_bds_bind(cl_env_copy,ECL_SYM("+",14),ECL_NIL); /*  +           */
   ecl_bds_bind(cl_env_copy,ECL_SYM("++",15),ECL_NIL); /*  ++         */
   ecl_bds_bind(cl_env_copy,ECL_SYM("+++",16),ECL_NIL); /*  +++       */
   ecl_bds_bind(cl_env_copy,ECL_SYM("-",17),ECL_NIL); /*  -           */
   ecl_bds_bind(cl_env_copy,ECL_SYM("*",18),ECL_NIL); /*  *           */
   ecl_bds_bind(cl_env_copy,ECL_SYM("**",19),ECL_NIL); /*  **         */
   ecl_bds_bind(cl_env_copy,ECL_SYM("***",20),ECL_NIL); /*  ***       */
   ecl_bds_bind(cl_env_copy,ECL_SYM("/",21),ECL_NIL); /*  /           */
   ecl_bds_bind(cl_env_copy,ECL_SYM("//",22),ECL_NIL); /*  //         */
   ecl_bds_bind(cl_env_copy,ECL_SYM("///",23),ECL_NIL); /*  ///       */
   si_select_package(_ecl_static_1);
   if ((ecl_symbol_value(VV[20]))!=ECL_NIL) { goto L7; }
   if (v1process_command_line==ECL_NIL) { goto L7; }
   ecl_function_dispatch(cl_env_copy,ECL_SYM("PROCESS-COMMAND-ARGS",1817))(0) /*  PROCESS-COMMAND-ARGS */;
   T0 = (cl_env_copy->function=(ECL_SYM("LISP-IMPLEMENTATION-VERSION",480)->symbol.gfdef))->cfun.entry(0) /*  LISP-IMPLEMENTATION-VERSION */;
   T1 = ecl_function_dispatch(cl_env_copy,ECL_SYM("LISP-IMPLEMENTATION-VCS-ID",1764))(0) /*  LISP-IMPLEMENTATION-VCS-ID */;
   cl_format(4, ECL_T, _ecl_static_2, T0, T1);
   cl_format(2, ECL_T, _ecl_static_3);
   cl_format(2, ecl_symbol_value(ECL_SYM("*STANDARD-OUTPUT*",67)), _ecl_static_4);
L7:;
   cl_set(VV[20],ECL_T);
   ecl_bds_bind(cl_env_copy,VV[14],ecl_make_fixnum(-1)); /*  *TPL-LEVEL* */
   L24tpl(0);
   ecl_bds_unwind1(cl_env_copy);
   value0 = ecl_make_fixnum(0);
   cl_env_copy->nvalues = 1;
   ecl_bds_unwind_n(cl_env_copy,11);
  }
  ecl_frs_pop(cl_env_copy);                       /*  END CATCH 2     */
  return value0;
 }
}
/*	function definition for CANDIDATE-TO-GET-CONSOLE-P            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2candidate_to_get_console_p(cl_object v1process)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_make_bool(ecl_symbol_value(VV[24])==ECL_NIL);
  if ((value0)!=ECL_NIL) { goto L2; }
  value0 = ecl_make_bool((ecl_symbol_value(VV[24]))==(v1process));
  if ((value0)!=ECL_NIL) { goto L2; }
  T0 = mp_process_active_p(ecl_symbol_value(VV[24]));
  value0 = Null(T0)?ECL_T:ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for REGISTER-IN-WAITING-LIST              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3register_in_waiting_list(cl_object volatile v1process)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   volatile cl_object v2;
   volatile cl_object v3;
   volatile cl_object v4;
   v2 = ecl_symbol_value(VV[22]);
   v3 = mp_lock_owner(v2);
   v4 = mp_lock_count(v2);
   {
    struct ecl_stack_frame _ecl_inner_frame_aux;
    volatile cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
    {
     volatile cl_object v5;
     v5 = _ecl_inner_frame;
     {
      volatile cl_object v6;
      v6 = ecl_symbol_value(ECL_SYM("*INTERRUPTS-ENABLED*",1023));
      ecl_bds_bind(cl_env_copy,ECL_SYM("*INTERRUPTS-ENABLED*",1023),ECL_NIL); /*  *INTERRUPTS-ENABLED* */
      ecl_bds_bind(cl_env_copy,ECL_SYM("*ALLOW-WITH-INTERRUPTS*",1730),ECL_NIL); /*  *ALLOW-WITH-INTERRUPTS* */
      {
       volatile bool unwinding = FALSE;
       cl_index v7=ECL_STACK_INDEX(cl_env_copy),v8;
       ecl_frame_ptr next_fr;
       if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
         unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
       } else {
       ecl_bds_bind(cl_env_copy,ECL_SYM("*INTERRUPTS-ENABLED*",1023),v6); /*  *INTERRUPTS-ENABLED* */
       mp_get_lock(1, v2);
       cl_set(VV[25],CONS(v1process,ecl_symbol_value(VV[25])));
       T0 = ecl_symbol_value(VV[25]);
       ecl_bds_unwind1(cl_env_copy);
       cl_env_copy->values[0] = T0;
       cl_env_copy->nvalues = 1;
       }
       ecl_frs_pop(cl_env_copy);
       v8=ecl_stack_push_values(cl_env_copy);
       T0 = ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398));
       T1 = mp_lock_owner(v2);
       if (!((T0)==(T1))) { goto L12; }
       if (!((v3)==(ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398))))) { goto L15; }
       T0 = mp_lock_count(v2);
       if (!(ecl_number_compare(T0,v4)>0)) { goto L12; }
       goto L13;
L15:;
L13:;
       mp_giveup_lock(v2);
L12:;
       ecl_stack_pop_values(cl_env_copy,v8);
       if (unwinding) ecl_unwind(cl_env_copy,next_fr);
       ECL_STACK_SET_INDEX(cl_env_copy,v7);
       ecl_bds_unwind1(cl_env_copy);
       ecl_bds_unwind1(cl_env_copy);
      }
     }
     ecl_stack_frame_push_values(v5);
     if (Null(ecl_symbol_value(ECL_SYM("*INTERRUPTS-ENABLED*",1023)))) { goto L17; }
     si_check_pending_interrupts();
L17:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v5);
     value0 = cl_env_copy->values[0];
    }
    ecl_stack_frame_close(_ecl_inner_frame);
   }
   return value0;
  }
 }
}
/*	function definition for DELETE-FROM-WAITING-LIST              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4delete_from_waiting_list(cl_object volatile v1process)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   volatile cl_object v2;
   volatile cl_object v3;
   volatile cl_object v4;
   v2 = ecl_symbol_value(VV[22]);
   v3 = mp_lock_owner(v2);
   v4 = mp_lock_count(v2);
   {
    struct ecl_stack_frame _ecl_inner_frame_aux;
    volatile cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
    {
     volatile cl_object v5;
     v5 = _ecl_inner_frame;
     {
      volatile cl_object v6;
      v6 = ecl_symbol_value(ECL_SYM("*INTERRUPTS-ENABLED*",1023));
      ecl_bds_bind(cl_env_copy,ECL_SYM("*INTERRUPTS-ENABLED*",1023),ECL_NIL); /*  *INTERRUPTS-ENABLED* */
      ecl_bds_bind(cl_env_copy,ECL_SYM("*ALLOW-WITH-INTERRUPTS*",1730),ECL_NIL); /*  *ALLOW-WITH-INTERRUPTS* */
      {
       volatile bool unwinding = FALSE;
       cl_index v7=ECL_STACK_INDEX(cl_env_copy),v8;
       ecl_frame_ptr next_fr;
       if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
         unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
       } else {
       ecl_bds_bind(cl_env_copy,ECL_SYM("*INTERRUPTS-ENABLED*",1023),v6); /*  *INTERRUPTS-ENABLED* */
       mp_get_lock(1, v2);
       cl_set(VV[25],cl_delete(2, v1process, ecl_symbol_value(VV[25])));
       T0 = ecl_symbol_value(VV[25]);
       ecl_bds_unwind1(cl_env_copy);
       cl_env_copy->values[0] = T0;
       cl_env_copy->nvalues = 1;
       }
       ecl_frs_pop(cl_env_copy);
       v8=ecl_stack_push_values(cl_env_copy);
       T0 = ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398));
       T1 = mp_lock_owner(v2);
       if (!((T0)==(T1))) { goto L12; }
       if (!((v3)==(ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398))))) { goto L15; }
       T0 = mp_lock_count(v2);
       if (!(ecl_number_compare(T0,v4)>0)) { goto L12; }
       goto L13;
L15:;
L13:;
       mp_giveup_lock(v2);
L12:;
       ecl_stack_pop_values(cl_env_copy,v8);
       if (unwinding) ecl_unwind(cl_env_copy,next_fr);
       ECL_STACK_SET_INDEX(cl_env_copy,v7);
       ecl_bds_unwind1(cl_env_copy);
       ecl_bds_unwind1(cl_env_copy);
      }
     }
     ecl_stack_frame_push_values(v5);
     if (Null(ecl_symbol_value(ECL_SYM("*INTERRUPTS-ENABLED*",1023)))) { goto L17; }
     si_check_pending_interrupts();
L17:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v5);
     value0 = cl_env_copy->values[0];
    }
    ecl_stack_frame_close(_ecl_inner_frame);
   }
   return value0;
  }
 }
}
/*	function definition for GRAB-CONSOLE                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5grab_console(cl_object volatile v1process)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   volatile cl_object v2repeat;
   v2repeat = ECL_T;
L2:;
   if ((v2repeat)!=ECL_NIL) { goto L4; }
   goto L3;
L4:;
   {
    volatile cl_object v3;
    volatile cl_object v4;
    volatile cl_object v5;
    v3 = ecl_symbol_value(VV[22]);
    v4 = mp_lock_owner(v3);
    v5 = mp_lock_count(v3);
    {
     struct ecl_stack_frame _ecl_inner_frame_aux;
     volatile cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
     {
      volatile cl_object v6;
      v6 = _ecl_inner_frame;
      {
       volatile cl_object v7;
       v7 = ecl_symbol_value(ECL_SYM("*INTERRUPTS-ENABLED*",1023));
       ecl_bds_bind(cl_env_copy,ECL_SYM("*INTERRUPTS-ENABLED*",1023),ECL_NIL); /*  *INTERRUPTS-ENABLED* */
       ecl_bds_bind(cl_env_copy,ECL_SYM("*ALLOW-WITH-INTERRUPTS*",1730),ECL_NIL); /*  *ALLOW-WITH-INTERRUPTS* */
       {
        volatile bool unwinding = FALSE;
        cl_index v8=ECL_STACK_INDEX(cl_env_copy),v9;
        ecl_frame_ptr next_fr;
        if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
          unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
        } else {
        ecl_bds_bind(cl_env_copy,ECL_SYM("*INTERRUPTS-ENABLED*",1023),v7); /*  *INTERRUPTS-ENABLED* */
        mp_get_lock(1, v3);
        if (Null(L2candidate_to_get_console_p(v1process))) { goto L17; }
        cl_set(VV[24],v1process);
        v2repeat = ECL_NIL;
        cl_env_copy->values[0] = ECL_NIL;
        cl_env_copy->nvalues = 1;
        ecl_bds_unwind1(cl_env_copy);
        goto L15;
L17:;
        cl_env_copy->values[0] = mp_condition_variable_wait(ecl_symbol_value(VV[23]), ecl_symbol_value(VV[22]));
        ecl_bds_unwind1(cl_env_copy);
L15:;
        }
        ecl_frs_pop(cl_env_copy);
        v9=ecl_stack_push_values(cl_env_copy);
        T0 = ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398));
        T1 = mp_lock_owner(v3);
        if (!((T0)==(T1))) { goto L22; }
        if (!((v4)==(ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398))))) { goto L25; }
        T0 = mp_lock_count(v3);
        if (!(ecl_number_compare(T0,v5)>0)) { goto L22; }
        goto L23;
L25:;
L23:;
        mp_giveup_lock(v3);
L22:;
        ecl_stack_pop_values(cl_env_copy,v9);
        if (unwinding) ecl_unwind(cl_env_copy,next_fr);
        ECL_STACK_SET_INDEX(cl_env_copy,v8);
        ecl_bds_unwind1(cl_env_copy);
        ecl_bds_unwind1(cl_env_copy);
       }
      }
      ecl_stack_frame_push_values(v6);
      if (Null(ecl_symbol_value(ECL_SYM("*INTERRUPTS-ENABLED*",1023)))) { goto L27; }
      si_check_pending_interrupts();
L27:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v6);
     }
     ecl_stack_frame_close(_ecl_inner_frame);
    }
   }
   goto L2;
L3:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for RELEASE-CONSOLE                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6release_console(cl_object volatile v1process)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   volatile cl_object v2;
   volatile cl_object v3;
   volatile cl_object v4;
   v2 = ecl_symbol_value(VV[22]);
   v3 = mp_lock_owner(v2);
   v4 = mp_lock_count(v2);
   {
    struct ecl_stack_frame _ecl_inner_frame_aux;
    volatile cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
    {
     volatile cl_object v5;
     v5 = _ecl_inner_frame;
     {
      volatile cl_object v6;
      v6 = ecl_symbol_value(ECL_SYM("*INTERRUPTS-ENABLED*",1023));
      ecl_bds_bind(cl_env_copy,ECL_SYM("*INTERRUPTS-ENABLED*",1023),ECL_NIL); /*  *INTERRUPTS-ENABLED* */
      ecl_bds_bind(cl_env_copy,ECL_SYM("*ALLOW-WITH-INTERRUPTS*",1730),ECL_NIL); /*  *ALLOW-WITH-INTERRUPTS* */
      {
       volatile bool unwinding = FALSE;
       cl_index v7=ECL_STACK_INDEX(cl_env_copy),v8;
       ecl_frame_ptr next_fr;
       if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
         unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
       } else {
       ecl_bds_bind(cl_env_copy,ECL_SYM("*INTERRUPTS-ENABLED*",1023),v6); /*  *INTERRUPTS-ENABLED* */
       mp_get_lock(1, v2);
       if (!((v1process)==(ecl_symbol_value(VV[24])))) { goto L13; }
       cl_set(VV[24],ECL_NIL);
       goto L11;
L13:;
       goto L11;
L11:;
       cl_env_copy->values[0] = mp_condition_variable_signal(ecl_symbol_value(VV[23]));
       ecl_bds_unwind1(cl_env_copy);
       }
       ecl_frs_pop(cl_env_copy);
       v8=ecl_stack_push_values(cl_env_copy);
       T0 = ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398));
       T1 = mp_lock_owner(v2);
       if (!((T0)==(T1))) { goto L16; }
       if (!((v3)==(ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398))))) { goto L19; }
       T0 = mp_lock_count(v2);
       if (!(ecl_number_compare(T0,v4)>0)) { goto L16; }
       goto L17;
L19:;
L17:;
       mp_giveup_lock(v2);
L16:;
       ecl_stack_pop_values(cl_env_copy,v8);
       if (unwinding) ecl_unwind(cl_env_copy,next_fr);
       ECL_STACK_SET_INDEX(cl_env_copy,v7);
       ecl_bds_unwind1(cl_env_copy);
       ecl_bds_unwind1(cl_env_copy);
      }
     }
     ecl_stack_frame_push_values(v5);
     if (Null(ecl_symbol_value(ECL_SYM("*INTERRUPTS-ENABLED*",1023)))) { goto L21; }
     si_check_pending_interrupts();
L21:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v5);
     value0 = cl_env_copy->values[0];
    }
    ecl_stack_frame_close(_ecl_inner_frame);
   }
   return value0;
  }
 }
}
/*	local function WITH-GRABBED-CONSOLE                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC7with_grabbed_console(cl_object v1, cl_object v2)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_cdr(v1);
   T0 = cl_listX(4, ECL_SYM("PROGN",671), VV[31], VV[32], v3);
   value0 = cl_listX(3, ECL_SYM("UNWIND-PROTECT",888), T0, VV[33]);
   return value0;
  }
 }
}
/*	function definition for SIMPLE-TERMINAL-INTERRUPT             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8simple_terminal_interrupt()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_error(1, ECL_SYM("INTERACTIVE-INTERRUPT",1663));
  return value0;
 }
}
/*	function definition for SHOW-PROCESS-LIST                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L9show_process_list(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1process_list;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1process_list = mp_all_processes();
   } else {
    i++;
    v1process_list = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v2current;
   v2current = ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398));
   {
    cl_object v3rank;
    v3rank = ecl_make_fixnum(1);
    {
     cl_object v4process;
     cl_object v5;
     v4process = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v1process_list))) FEtype_error_list(v1process_list);
     v5 = v1process_list;
L7:;
     if (!(ecl_endp(v5))) { goto L9; }
     goto L8;
L9:;
     v4process = _ecl_car(v5);
     {
      cl_object v6;
      v6 = _ecl_cdr(v5);
      if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
      v5 = v6;
     }
     if (!((v4process)==(v2current))) { goto L19; }
     T0 = _ecl_static_6;
     goto L18;
L19:;
     T0 = _ecl_static_7;
L18:;
     cl_format(4, ECL_T, T0, v3rank, v4process);
     v3rank = ecl_one_plus(v3rank);
     goto L7;
L8:;
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
  }
 }
}
/*	function definition for QUERY-PROCESS                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L10query_process(cl_narg narg, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1process_list;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1process_list = mp_all_processes();
   } else {
    i++;
    v1process_list = va_arg(args,cl_object);
   }
  }
  va_end(args);
  cl_format(2, ECL_T, _ecl_static_8);
  {
   cl_object v2code;
   v2code = ECL_NIL;
L4:;
   L9show_process_list(1, v1process_list);
   L25tpl_prompt();
   v2code = L26tpl_read();
   if (!(ecl_zerop(v2code))) { goto L10; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L10:;
   if (!(ECL_FIXNUMP(v2code))) { goto L12; }
   {
    cl_fixnum v3;
    v3 = ecl_length(v1process_list);
    if (Null(cl_LE(3, ecl_make_fixnum(1), v2code, ecl_make_fixnum(v3)))) { goto L12; }
   }
   T0 = ecl_one_minus(v2code);
   T1 = ecl_elt(v1process_list,ecl_fixnum(T0));
   value0 = ecl_list1(T1);
   cl_env_copy->nvalues = 1;
   return value0;
L12:;
   cl_format(2, ECL_T, _ecl_static_9);
   goto L4;
  }
 }
}
/*	function definition for SINGLE-THREADED-TERMINAL-INTERRUPT    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L12single_threaded_terminal_interrupt()
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
    {cl_object v1;
     v1 = ECL_NIL;
     v1 = ecl_make_cclosure_va((cl_objectfn)LC11__g78,env2,Cblock);
     T0 = v1;
    }
    T1 = ecl_function_dispatch(cl_env_copy,VV[143])(4, ECL_SYM("NAME",1273), ECL_SYM("CONTINUE",250), ECL_SYM("FUNCTION",1241), T0) /*  MAKE-RESTART */;
    T2 = ecl_list1(T1);
    T3 = CONS(T2,ecl_symbol_value(ECL_SYM("*RESTART-CLUSTERS*",4)));
    ecl_bds_bind(cl_env_copy,ECL_SYM("*RESTART-CLUSTERS*",4),T3); /*  *RESTART-CLUSTERS* */
    value0 = L8simple_terminal_interrupt();
    ecl_frs_pop(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    return value0;
L1:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    ecl_frs_pop(cl_env_copy);
    return value0;
   }
  }
 }
}
/*	closure G78                                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC11__g78(cl_narg narg, ...)
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
 {
  cl_object v1temp;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1temp = cl_grab_rest_args(args);
  ecl_va_end(args);
  ECL_CONS_CAR(CLV0) = v1temp;
  cl_go(ECL_CONS_CAR(CLV1),ecl_make_fixnum(0));
 }
 }
}
/*	function definition for TERMINAL-INTERRUPT                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L17terminal_interrupt(volatile cl_narg narg, ...)
{
 cl_object T0, T1, T2, T3, T4, T5, T6;
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1, CLV2
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  volatile cl_object v1process;
  volatile cl_object v2correctablep;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L17terminal_interruptkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v1process = keyvars[0];
   if (Null(keyvars[3])) {
    v2correctablep = ECL_T;
   } else {
    v2correctablep = keyvars[1];
   }
  }
  {
   struct ecl_stack_frame _ecl_inner_frame_aux;
   volatile cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
   {
    volatile cl_object v3;
    v3 = _ecl_inner_frame;
    {
     volatile cl_object v4;
     ecl_bds_bind(cl_env_copy,ECL_SYM("*INTERRUPTS-ENABLED*",1023),ECL_NIL); /*  *INTERRUPTS-ENABLED* */
     v4 = ecl_symbol_value(ECL_SYM("*ALLOW-WITH-INTERRUPTS*",1730));
     ecl_bds_bind(cl_env_copy,ECL_SYM("*ALLOW-WITH-INTERRUPTS*",1730),ECL_NIL); /*  *ALLOW-WITH-INTERRUPTS* */
     {
      volatile cl_object v5suspended;
      volatile cl_object v6break_process;
      volatile cl_object env1 = env0;
      v5suspended = ECL_NIL;
      v6break_process = ECL_NIL;
      {
       cl_object v7this;
       v7this = ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398));
       {
        cl_object v8;
        cl_object v9p;
        cl_object v10;
        v8 = mp_all_processes();
        v9p = ECL_NIL;
        if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
        v10 = v8;
        {
         cl_object v11;
         cl_object v12;
         v11 = ecl_list1(ECL_NIL);
         v12 = v11;
L17:;
         if (!(ecl_endp(v10))) { goto L19; }
         goto L18;
L19:;
         v9p = _ecl_car(v10);
         {
          cl_object v13;
          v13 = _ecl_cdr(v10);
          if (ecl_unlikely(!ECL_LISTP(v13))) FEtype_error_list(v13);
          v10 = v13;
         }
         if ((v9p)==(v7this)) { goto L27; }
         {
          cl_object v13;
          v13 = mp_process_name(v9p);
          if (!((v13)==(ECL_SYM("SIGNAL-SERVICING",1765)))) { goto L33; }
          goto L27;
          goto L31;
L33:;
          goto L31;
L31:;
          if (!((v13)==(ECL_SYM("HANDLE-SIGNAL",1732)))) { goto L36; }
          goto L27;
          goto L28;
L36:;
          goto L28;
         }
L28:;
         if (ecl_unlikely(ECL_ATOM(v12))) FEtype_error_cons(v12);
         T1 = v12;
         v12 = ecl_list1(v9p);
         (ECL_CONS_CDR(T1)=v12,T1);
L27:;
         goto L17;
L18:;
         T0 = ecl_cdr(v11);
         goto L9;
        }
       }
      }
L9:;
      env1 = ECL_NIL;
      CLV0 = env1 = CONS(T0,env1);                /*  ALL-PROCESSES   */
      {
       cl_fixnum v7;
       v7 = ecl_length(ECL_CONS_CAR(CLV0));
       if (!((v7)==(1))) { goto L43; }
      }
      if (Null(ecl_symbol_value(VV[40]))) { goto L43; }
      T0 = ecl_car(ECL_CONS_CAR(CLV0));
      T1 = (VV[41]->symbol.gfdef);
      mp_interrupt_process(T0, T1);
      value0 = ECL_NIL;
      cl_env_copy->nvalues = 1;
      ecl_stack_frame_close(_ecl_inner_frame);
      ecl_bds_unwind1(cl_env_copy);
      ecl_bds_unwind1(cl_env_copy);
      return value0;
L43:;
      {
       cl_object v7i;
       cl_object v8;
       v7i = ECL_NIL;
       if (ecl_unlikely(!ECL_LISTP(ECL_CONS_CAR(CLV0)))) FEtype_error_list(ECL_CONS_CAR(CLV0));
       v8 = ECL_CONS_CAR(CLV0);
L52:;
       if (!(ecl_endp(v8))) { goto L54; }
       goto L53;
L54:;
       v7i = _ecl_car(v8);
       {
        cl_object v9;
        v9 = _ecl_cdr(v8);
        if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
        v8 = v9;
       }
       cl_format(3, ECL_T, _ecl_static_10, v7i);
       v5suspended = CONS(v7i,v5suspended);
       mp_process_suspend(v7i);
       goto L52;
L53:;
      }
      {cl_object v7;
       v7 = ECL_NIL;
       v7 = ecl_make_cclosure_va((cl_objectfn)LC13do_query_process,env1,Cblock);
       ecl_bds_bind(cl_env_copy,ECL_SYM("*ALLOW-WITH-INTERRUPTS*",1730),v4); /*  *ALLOW-WITH-INTERRUPTS* */
       ecl_bds_bind(cl_env_copy,ECL_SYM("*INTERRUPTS-ENABLED*",1023),v4); /*  *INTERRUPTS-ENABLED* */
       if (Null(v4)) { goto L68; }
       si_check_pending_interrupts();
L68:;
       {
        volatile cl_object env2 = env1;
        CLV1 = env2 = CONS(ECL_NIL,env2);
        {
         volatile cl_object env3 = env2;
         CLV2 = env3 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env3); /*  TAGBODY */
         if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV2))) {
         if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L70;
         if (cl_env_copy->values[0]==ecl_make_fixnum(1))goto L71;
         ecl_internal_error("GO found an inexistent tag");
         }
         {cl_object v8;
          v8 = ECL_NIL;
          v8 = ecl_make_cclosure_va((cl_objectfn)LC14__g107,env3,Cblock);
          T0 = v8;
         }
         T1 = ecl_function_dispatch(cl_env_copy,VV[143])(4, ECL_SYM("NAME",1273), ECL_SYM("CONTINUE",250), ECL_SYM("FUNCTION",1241), T0) /*  MAKE-RESTART */;
         {cl_object v8;
          v8 = ECL_NIL;
          v8 = ecl_make_cclosure_va((cl_objectfn)LC15__g108,env3,Cblock);
          T2 = v8;
         }
         {cl_object v8;
          v8 = ECL_NIL;
          v8 = ecl_make_cfun((cl_objectfn_fixed)LC16__g109,ECL_NIL,Cblock,1);
          T3 = v8;
         }
         T4 = ecl_function_dispatch(cl_env_copy,VV[143])(8, ECL_SYM("NAME",1273), ECL_SYM("INTERRUPT-PROCESS",1425), ECL_SYM("FUNCTION",1241), T2, VV[44], T3, VV[45], v7) /*  MAKE-RESTART */;
         T5 = cl_list(2, T1, T4);
         T6 = CONS(T5,ecl_symbol_value(ECL_SYM("*RESTART-CLUSTERS*",4)));
         ecl_bds_bind(cl_env_copy,ECL_SYM("*RESTART-CLUSTERS*",4),T6); /*  *RESTART-CLUSTERS* */
         L8simple_terminal_interrupt();
         ecl_frs_pop(cl_env_copy);
         ecl_bds_unwind1(cl_env_copy);
         ecl_bds_unwind1(cl_env_copy);
         ecl_bds_unwind1(cl_env_copy);
         goto L67;
L70:;
         v6break_process = ECL_NIL;
         ecl_frs_pop(cl_env_copy);
         ecl_bds_unwind1(cl_env_copy);
         ecl_bds_unwind1(cl_env_copy);
         goto L67;
L71:;
         {
          cl_object v8;
          cl_object v9process;
          v8 = ECL_CONS_CAR(CLV1);
          if (Null(v8)) { goto L81; }
          {
          cl_object v10;
          v10 = v8;
          if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
          if (Null(v10)) { goto L86; }
          {
          cl_object v11;
          v11 = ECL_CONS_CDR(v10);
          v8 = v11;
          v10 = ECL_CONS_CAR(v10);
          }
L86:;
          v9process = v10;
          goto L80;
          }
L81:;
          v9process = si_dm_too_few_arguments(ECL_NIL);
L80:;
          v6break_process = v9process;
          ecl_frs_pop(cl_env_copy);
          ecl_bds_unwind1(cl_env_copy);
          ecl_bds_unwind1(cl_env_copy);
          goto L67;
         }
        }
       }
      }
L67:;
      {
       cl_object v7process;
       cl_object v8;
       v7process = ECL_NIL;
       if (ecl_unlikely(!ECL_LISTP(v5suspended))) FEtype_error_list(v5suspended);
       v8 = v5suspended;
L97:;
       if (!(ecl_endp(v8))) { goto L99; }
       goto L98;
L99:;
       v7process = _ecl_car(v8);
       {
        cl_object v9;
        v9 = _ecl_cdr(v8);
        if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
        v8 = v9;
       }
       if ((v7process)==(v6break_process)) { goto L107; }
       mp_process_resume(v7process);
L107:;
       goto L97;
L98:;
      }
      if (Null(v6break_process)) { goto L110; }
      T0 = (VV[41]->symbol.gfdef);
      cl_env_copy->values[0] = mp_interrupt_process(v6break_process, T0);
      ecl_bds_unwind1(cl_env_copy);
      ecl_bds_unwind1(cl_env_copy);
      goto L5;
L110:;
      cl_env_copy->values[0] = ECL_NIL;
      cl_env_copy->nvalues = 1;
      ecl_bds_unwind1(cl_env_copy);
      ecl_bds_unwind1(cl_env_copy);
     }
    }
L5:;
    ecl_stack_frame_push_values(v3);
    if (Null(ecl_symbol_value(ECL_SYM("*INTERRUPTS-ENABLED*",1023)))) { goto L113; }
    si_check_pending_interrupts();
L113:;cl_env_copy->values[0]=ecl_stack_frame_pop_values(v3);
    value0 = cl_env_copy->values[0];
   }
   ecl_stack_frame_close(_ecl_inner_frame);
  }
  return value0;
 }
}
/*	closure DO-QUERY-PROCESS                                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC13do_query_process(cl_narg narg, ...)
{
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  ALL-PROCESSES   */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=0)) FEwrong_num_arguments_anonym();
 {
TTL:
  ecl_print(ECL_CONS_CAR(CLV0),ECL_NIL);
  value0 = L10query_process(1, ECL_CONS_CAR(CLV0));
  return value0;
 }
 }
}
/*	closure G107                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC14__g107(cl_narg narg, ...)
{
 cl_object CLV0, CLV1, CLV2
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV2 = env0;                                     /*  TAGBODY         */
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 {
  cl_object v1temp;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1temp = cl_grab_rest_args(args);
  ecl_va_end(args);
  ECL_CONS_CAR(CLV1) = v1temp;
  cl_go(ECL_CONS_CAR(CLV2),ecl_make_fixnum(0));
 }
 }
}
/*	closure G108                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC15__g108(cl_narg narg, ...)
{
 cl_object CLV0, CLV1, CLV2
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV2 = env0;                                     /*  TAGBODY         */
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 {
  cl_object v1temp;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1temp = cl_grab_rest_args(args);
  ecl_va_end(args);
  ECL_CONS_CAR(CLV1) = v1temp;
  cl_go(ECL_CONS_CAR(CLV2),ecl_make_fixnum(1));
 }
 }
}
/*	local function G109                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC16__g109(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_princ_str("Interrupt a certain process.",v1stream);
  value0 = _ecl_static_11;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for TPL                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L24tpl(volatile cl_narg narg, ...)
{
 cl_object T0, T1, T2, T3, T4;
 cl_object volatile env0;
 volatile struct ecl_cclosure aux_closure;
 cl_object volatile CLV0, CLV1, CLV2, CLV3, CLV4
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  volatile cl_object v1broken_at;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  {
   cl_object keyvars[8];
   cl_parse_key(args,4,L24tplkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[4])) {
    ecl_bds_bind(cl_env_copy,VV[18],ecl_symbol_value(VV[17])); /*  *TPL-COMMANDS* */
   } else {
    ecl_bds_bind(cl_env_copy,VV[18],keyvars[0]);  /*  *TPL-COMMANDS*  */
   }
   if (Null(keyvars[5])) {
    ecl_bds_push(cl_env_copy,VV[9]);              /*  *TPL-PROMPT-HOOK* */
   } else {
    ecl_bds_bind(cl_env_copy,VV[9],keyvars[1]);   /*  *TPL-PROMPT-HOOK* */
   }
   v1broken_at = keyvars[2];
   env0 = ECL_NIL;
   CLV0 = env0 = CONS(keyvars[3],env0);           /*  QUIET           */
  }
  {
   volatile cl_object env1 = env0;
   ecl_bds_bind(cl_env_copy,VV[3],ecl_symbol_value(VV[4])); /*  *IHS-BASE* */
   if (Null(v1broken_at)) { goto L2; }
   T0 = L69ihs_search(2, ECL_T, v1broken_at);
   goto L1;
L2:;
   T0 = si_ihs_top();
L1:;
   ecl_bds_bind(cl_env_copy,VV[4],T0);            /*  *IHS-TOP*       */
   if (Null(v1broken_at)) { goto L5; }
   T0 = si_ihs_prev(ecl_symbol_value(VV[4]));
   goto L4;
L5:;
   T0 = ecl_symbol_value(VV[4]);
L4:;
   ecl_bds_bind(cl_env_copy,VV[5],T0);            /*  *IHS-CURRENT*   */
   value0 = si_sch_frs_base(ecl_symbol_value(VV[7]), ecl_symbol_value(VV[3]));
   if ((value0)!=ECL_NIL) { goto L9; }
   T1 = si_frs_top();
   T0 = ecl_make_integer((ecl_to_fixnum(T1))+1);
   goto L7;
L9:;
   T0 = value0;
   goto L7;
L7:;
   ecl_bds_bind(cl_env_copy,VV[6],T0);            /*  *FRS-BASE*      */
   T0 = si_frs_top();
   ecl_bds_bind(cl_env_copy,VV[7],T0);            /*  *FRS-TOP*       */
   T0 = CONS(ecl_symbol_value(ECL_SYM("*QUIT-TAG*",1737)),ecl_symbol_value(VV[0]));
   ecl_bds_bind(cl_env_copy,VV[0],T0);            /*  *QUIT-TAGS*     */
   ecl_bds_bind(cl_env_copy,ECL_SYM("*QUIT-TAG*",1737),ecl_symbol_value(VV[0])); /*  *QUIT-TAG* */
   T0 = ecl_one_plus(ecl_symbol_value(VV[14]));
   ecl_bds_bind(cl_env_copy,VV[14],T0);           /*  *TPL-LEVEL*     */
   CLV1 = env1 = CONS(ecl_symbol_value(VV[1]),env1); /*  BREAK-LEVEL  */
   CLV2 = env1 = CONS(ECL_NIL,env1);              /*  VALUES          */
   L68set_break_env();
   L67set_current_ihs();
L13:;
   cl_set(ECL_SYM("+++",16),ecl_symbol_value(ECL_SYM("++",15)));
   cl_set(ECL_SYM("++",15),ecl_symbol_value(ECL_SYM("+",14)));
   cl_set(ECL_SYM("+",14),ecl_symbol_value(ECL_SYM("-",17)));
   value0 = ecl_symbol_value(ECL_SYM("*QUIT-TAG*",1737));
   if (ecl_frs_push(cl_env_copy,value0)) {        /*  BEGIN CATCH 22  */
    value0 = cl_env_copy->values[0];
   } else {
    if (!(ecl_zerop(ECL_CONS_CAR(CLV1)))) { goto L27; }
    {
     volatile cl_object env2 = env1;
     CLV3 = env2 = CONS(ECL_NIL,env2);
     {
      volatile cl_object env3 = env2;
      CLV4 = env3 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env3); /*  TAGBODY */
      if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV4))) {
      if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L29;
      ecl_internal_error("GO found an inexistent tag");
      }
      {cl_object v2;
       v2 = ECL_NIL;
       v2 = ecl_make_cclosure_va((cl_objectfn)LC20__g130,env3,Cblock);
       T0 = v2;
      }
      {cl_object v2;
       v2 = ECL_NIL;
       v2 = ecl_make_cfun((cl_objectfn_fixed)LC21__g131,ECL_NIL,Cblock,1);
       T1 = v2;
      }
      T2 = ecl_function_dispatch(cl_env_copy,VV[143])(6, ECL_SYM("NAME",1273), VV[47], ECL_SYM("FUNCTION",1241), T0, VV[44], T1) /*  MAKE-RESTART */;
      T3 = ecl_list1(T2);
      T4 = CONS(T3,ecl_symbol_value(ECL_SYM("*RESTART-CLUSTERS*",4)));
      ecl_bds_bind(cl_env_copy,ECL_SYM("*RESTART-CLUSTERS*",4),T4); /*  *RESTART-CLUSTERS* */
      (aux_closure.env=ecl_nthcdr(2,env3),cl_env_copy->function=(cl_object)&aux_closure,LC19rep(0));
      ecl_frs_pop(cl_env_copy);
      ecl_bds_unwind1(cl_env_copy);
      goto L26;
L29:;
      ecl_frs_pop(cl_env_copy);
      goto L26;
     }
    }
L27:;
    {
     volatile cl_object env2 = env1;
     CLV3 = env2 = CONS(ECL_NIL,env2);
     {
      volatile cl_object env3 = env2;
      CLV4 = env3 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env3); /*  TAGBODY */
      if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV4))) {
      if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L36;
      ecl_internal_error("GO found an inexistent tag");
      }
      {cl_object v2;
       v2 = ECL_NIL;
       v2 = ecl_make_cclosure_va((cl_objectfn)LC22__g137,env3,Cblock);
       T0 = v2;
      }
      {cl_object v2;
       v2 = ECL_NIL;
       v2 = ecl_make_cclosure_va((cl_objectfn)LC23__g138,env3,Cblock);
       T1 = v2;
      }
      T2 = ecl_function_dispatch(cl_env_copy,VV[143])(6, ECL_SYM("NAME",1273), VV[48], ECL_SYM("FUNCTION",1241), T0, VV[44], T1) /*  MAKE-RESTART */;
      T3 = ecl_list1(T2);
      T4 = CONS(T3,ecl_symbol_value(ECL_SYM("*RESTART-CLUSTERS*",4)));
      ecl_bds_bind(cl_env_copy,ECL_SYM("*RESTART-CLUSTERS*",4),T4); /*  *RESTART-CLUSTERS* */
      (aux_closure.env=ecl_nthcdr(2,env3),cl_env_copy->function=(cl_object)&aux_closure,LC19rep(0));
      ecl_frs_pop(cl_env_copy);
      ecl_bds_unwind1(cl_env_copy);
      goto L26;
L36:;
      ecl_frs_pop(cl_env_copy);
      goto L26;
     }
    }
L26:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
   }
   ecl_frs_pop(cl_env_copy);                      /*  END CATCH 22    */
   if (Null(value0)) { goto L14; }
   ECL_CONS_CAR(CLV0) = ECL_NIL;
L14:;
   goto L13;
  }
 }
}
/*	closure REP                                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC19rep(volatile cl_narg narg, ...)
{
 cl_object T0, T1, T2, T3;
 cl_object volatile CLV0, CLV1, CLV2, CLV3
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object volatile env0 = cl_env_copy->function->cclosure.env;
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV2 = env0;                                     /*  VALUES          */
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=0)) FEwrong_num_arguments_anonym();
 {
TTL:
  {
   CLV3 = env0 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env0); /*  REP    */
   if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV3))!=0) {
   value0 = cl_env_copy->values[0];
   ecl_frs_pop(cl_env_copy);
   return value0;
   } else {
   {cl_object v1;
    v1 = ECL_NIL;
    v1 = ecl_make_cclosure_va((cl_objectfn)LC18__g119,env0,Cblock);
    T0 = v1;
   }
   T1 = CONS(ECL_SYM("SERIOUS-CONDITION",742),T0);
   T2 = ecl_list1(T1);
   T3 = CONS(T2,ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5)));
   ecl_bds_bind(cl_env_copy,ECL_SYM("*HANDLER-CLUSTERS*",5),T3); /*  *HANDLER-CLUSTERS* */
   {
    volatile bool unwinding = FALSE;
    cl_index v1=ECL_STACK_INDEX(cl_env_copy),v2;
    ecl_frame_ptr next_fr;
    if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
      unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
    } else {
    L3register_in_waiting_list(ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398)));
    L5grab_console(ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398)));
    if ((ECL_CONS_CAR(CLV0))!=ECL_NIL) { goto L5; }
    L58break_where();
    ECL_CONS_CAR(CLV0) = ECL_T;
L5:;
    L25tpl_prompt();
    cl_set(ECL_SYM("-",17),ecl_function_dispatch(cl_env_copy,VV[60])(0) /*  TPL-READ */);
    {
     struct ecl_stack_frame _ecl_inner_frame_aux;
     volatile cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
     {
      cl_object v3;
      v3 = _ecl_inner_frame;
      cl_env_copy->values[0] = si_eval_with_env(2, ecl_symbol_value(ECL_SYM("-",17)), ecl_symbol_value(VV[2]));
      ecl_stack_frame_push_values(v3);cl_env_copy->values[0]=ecl_apply_from_stack_frame(v3,ECL_SYM("LIST",481));
      value0 = cl_env_copy->values[0];
     }
     ecl_stack_frame_close(_ecl_inner_frame);
    }
    ECL_CONS_CAR(CLV2) = value0;
    cl_set(ECL_SYM("///",23),ecl_symbol_value(ECL_SYM("//",22)));
    cl_set(ECL_SYM("//",22),ecl_symbol_value(ECL_SYM("/",21)));
    cl_set(ECL_SYM("/",21),ECL_CONS_CAR(CLV2));
    cl_set(ECL_SYM("***",20),ecl_symbol_value(ECL_SYM("**",19)));
    cl_set(ECL_SYM("**",19),ecl_symbol_value(ECL_SYM("*",18)));
    cl_set(ECL_SYM("*",18),ecl_car(ecl_symbol_value(ECL_SYM("/",21))));
    cl_env_copy->values[0] = L32tpl_print(ECL_CONS_CAR(CLV2));
    }
    ecl_frs_pop(cl_env_copy);
    v2=ecl_stack_push_values(cl_env_copy);
    L4delete_from_waiting_list(ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398)));
    L6release_console(ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398)));
    ecl_stack_pop_values(cl_env_copy,v2);
    if (unwinding) ecl_unwind(cl_env_copy,next_fr);
    value0 = cl_env_copy->values[0];
    ecl_frs_pop(cl_env_copy);
    ECL_STACK_SET_INDEX(cl_env_copy,v1);
    ecl_bds_unwind1(cl_env_copy);
    return value0;
   }}
  }
 }
 }
}
/*	closure G130                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC20__g130(cl_narg narg, ...)
{
 cl_object CLV0, CLV1, CLV2, CLV3, CLV4
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV4 = env0;                                     /*  TAGBODY         */
 CLV3 = _ecl_cdr(CLV4);
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 {
  cl_object v1temp;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1temp = cl_grab_rest_args(args);
  ecl_va_end(args);
  ECL_CONS_CAR(CLV3) = v1temp;
  cl_go(ECL_CONS_CAR(CLV4),ecl_make_fixnum(0));
 }
 }
}
/*	local function G131                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC21__g131(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_format(2, v1stream, _ecl_static_13);
  return value0;
 }
}
/*	closure G137                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC22__g137(cl_narg narg, ...)
{
 cl_object CLV0, CLV1, CLV2, CLV3, CLV4
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV4 = env0;                                     /*  TAGBODY         */
 CLV3 = _ecl_cdr(CLV4);
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 {
  cl_object v1temp;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1temp = cl_grab_rest_args(args);
  ecl_va_end(args);
  ECL_CONS_CAR(CLV3) = v1temp;
  cl_go(ECL_CONS_CAR(CLV4),ecl_make_fixnum(0));
 }
 }
}
/*	closure G138                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC23__g138(cl_narg narg, cl_object v1stream, ...)
{
 cl_object CLV0, CLV1, CLV2, CLV3, CLV4
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV4 = env0;
 CLV3 = _ecl_cdr(CLV4);
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);                           /*  BREAK-LEVEL     */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  value0 = cl_format(3, v1stream, _ecl_static_14, ECL_CONS_CAR(CLV1));
  return value0;
 }
 }
}
/*	closure G119                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC18__g119(cl_narg narg, cl_object v1condition, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1, CLV2, CLV3
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV3 = env0;                                     /*  REP             */
 CLV2 = _ecl_cdr(CLV3);
 CLV1 = _ecl_cdr(CLV2);
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  {
   cl_object v2;
   v2 = ecl_make_bool(ecl_number_compare(ECL_CONS_CAR(CLV1),ecl_make_fixnum(1))<0);
   if (Null(v2)) { goto L2; }
   value0 = v2;
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
   {
    cl_object v3;
    v3 = ecl_symbol_value(VV[35]);
    if (Null(v3)) { goto L5; }
    value0 = v3;
    cl_env_copy->nvalues = 1;
    return value0;
L5:;
    T0 = cl_type_of(v1condition);
    cl_format(4, ECL_T, _ecl_static_12, T0, v1condition);
    cl_clear_input(0);
    cl_env_copy->values[0] = ECL_T;
    cl_env_copy->nvalues = 1;
    cl_return_from(ECL_CONS_CAR(CLV3),ECL_NIL);
   }
  }
 }
 }
}
/*	function definition for TPL-PROMPT                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L25tpl_prompt()
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v1;
   v1 = ecl_symbol_value(VV[9]);
   if (!(ECL_STRINGP(v1))) { goto L2; }
   value0 = cl_format(2, ECL_T, ecl_symbol_value(VV[9]));
   return value0;
L2:;
   if (Null(cl_functionp(v1))) { goto L4; }
   value0 = ecl_function_dispatch(cl_env_copy,ecl_symbol_value(VV[9]))(0);
   return value0;
L4:;
   cl_fresh_line(0);
   T1 = ecl_symbol_value(ECL_SYM("*PACKAGE*",43));
   T2 = cl_find_package(VV[50]);
   if (!((T1)==(T2))) { goto L8; }
   T0 = _ecl_static_16;
   goto L7;
L8:;
   T0 = cl_package_name(ecl_symbol_value(ECL_SYM("*PACKAGE*",43)));
L7:;
   T1 = ecl_minus(ecl_symbol_value(VV[14]),ecl_symbol_value(ECL_SYM("*STEP-LEVEL*",1032)));
   T2 = ecl_minus(T1,ecl_make_fixnum(-1));
   value0 = cl_format(5, ECL_T, _ecl_static_15, T0, T2, _ecl_static_16);
   return value0;
  }
 }
}
/*	function definition for TPL-READ                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L26tpl_read()
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_bds_bind(cl_env_copy,ECL_SYM("*READ-SUPPRESS*",64),ECL_NIL); /*  *READ-SUPPRESS* */
  cl_finish_output(0);
L2:;
  {
   cl_object v1;
   v1 = cl_peek_char(4, ECL_NIL, ecl_symbol_value(ECL_SYM("*STANDARD-INPUT*",66)), ECL_NIL, ECL_SYM("EOF",1228));
   if (!(((v1)==ECL_CODE_CHAR((ecl_character)(41))))) { goto L5; }
   (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(1, _ecl_static_17) /*  WARN */;
   cl_read_char(0);
   goto L3;
L5:;
   if (!(((v1)==ECL_CODE_CHAR((ecl_character)(32))))) { goto L14; }
   goto L11;
   goto L12;
L14:;
   goto L12;
L12:;
   if (!(((v1)==ECL_CODE_CHAR((ecl_character)(9))))) { goto L9; }
   goto L10;
L11:;
L10:;
   cl_read_char(0);
   goto L3;
L9:;
   if (!(((v1)==ECL_CODE_CHAR((ecl_character)(10))))) { goto L22; }
   goto L19;
   goto L20;
L22:;
   goto L20;
L20:;
   if (!(((v1)==ECL_CODE_CHAR((ecl_character)(13))))) { goto L17; }
   goto L18;
L19:;
L18:;
   cl_read_char(0);
   {
    cl_object v2command;
    v2command = L28tpl_make_command(VV[57], _ecl_static_16);
    if (Null(v2command)) { goto L3; }
    value0 = v2command;
    cl_env_copy->nvalues = 1;
    ecl_bds_unwind1(cl_env_copy);
    return value0;
   }
L17:;
   if (!(ecl_eql(v1,ECL_SYM("EOF",1228)))) { goto L28; }
   ecl_terpri(ECL_NIL);
   value0 = L28tpl_make_command(ECL_SYM("EOF",1228), _ecl_static_16);
   ecl_bds_unwind1(cl_env_copy);
   return value0;
L28:;
   if (!(((v1)==ECL_CODE_CHAR((ecl_character)(58))))) { goto L31; }
   T0 = cl_read_preserving_whitespace(0);
   T1 = cl_read_line(0);
   value0 = L28tpl_make_command(T0, T1);
   ecl_bds_unwind1(cl_env_copy);
   return value0;
L31:;
   if (!(((v1)==ECL_CODE_CHAR((ecl_character)(63))))) { goto L33; }
   cl_read_char(0);
   {
    cl_object v3;
    v3 = cl_peek_char(4, ECL_NIL, ecl_symbol_value(ECL_SYM("*STANDARD-INPUT*",66)), ECL_NIL, ECL_SYM("EOF",1228));
    if (Null(ecl_memql(v3,VV[58]))) { goto L37; }
    T0 = cl_read_line(0);
    value0 = L28tpl_make_command(VV[59], T0);
    ecl_bds_unwind1(cl_env_copy);
    return value0;
L37:;
    cl_unread_char(1, CODE_CHAR(63));
    value0 = cl_read_preserving_whitespace(0);
    ecl_bds_unwind1(cl_env_copy);
    return value0;
   }
L33:;
   value0 = cl_read(0);
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
L3:;
  goto L2;
 }
}
/*	function definition for HARDEN-COMMAND                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L27harden_command(cl_object v1cmd_form)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(3, ECL_SYM("HANDLER-BIND",417), VV[63], v1cmd_form);
  value0 = cl_list(3, ECL_SYM("BLOCK",137), VV[62], T0);
  return value0;
 }
}
/*	function definition for TPL-MAKE-COMMAND                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L28tpl_make_command(cl_object v1name, cl_object v2line)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3c;
   v3c = ECL_NIL;
   {
    cl_object v4;
    v4 = ecl_symbol_value(VV[18]);
    goto L6;
L5:;
    {
     cl_object v5commands;
     v5commands = ecl_car(v4);
     {
      cl_object v6;
      v6 = ecl_cdr(v5commands);
      goto L16;
L15:;
      {
       cl_object v7;
       cl_object v8;
       if (ecl_unlikely(ECL_ATOM(v6))) FEtype_error_cons(v6);
       v7 = v6;
       v8 = ECL_CONS_CAR(v7);
       if (Null(v8)) { goto L18; }
       {
        cl_object v9;
        if (ecl_unlikely(ECL_ATOM(v8))) FEtype_error_cons(v8);
        T0 = v8;
        v9 = ECL_CONS_CAR(T0);
        if (Null(ecl_memql(v1name,v9))) { goto L18; }
        v3c = v8;
        goto L12;
       }
      }
L18:;
      v6 = ECL_CONS_CDR(v6);
L16:;
      if (v6==ECL_NIL) { goto L29; }
      goto L15;
L29:;
      v3c = ECL_NIL;
     }
L12:;
     if (Null(v3c)) { goto L10; }
     goto L2;
L10:;
    }
    v4 = ecl_cdr(v4);
L6:;
    if (Null(v4)) { goto L33; }
    goto L5;
L33:;
   }
L2:;
   if (!(v3c==ECL_NIL)) { goto L35; }
   if (!((v1name)==(VV[57]))) { goto L37; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L37:;
   T0 = cl_list(2, ECL_SYM("QUOTE",679), v1name);
   value0 = cl_list(2, VV[65], T0);
   return value0;
L35:;
   T0 = ecl_caddr(v3c);
   if (!((T0)==(VV[66]))) { goto L39; }
   T0 = ecl_cadr(v3c);
   T1 = cl_list(2, ECL_SYM("INVOKE-RESTART-INTERACTIVELY",447), T0);
   value0 = cl_list(2, ECL_SYM("PROGN",671), T1);
   return value0;
L39:;
   T0 = ecl_caddr(v3c);
   if (!((T0)==(VV[67]))) { goto L41; }
   T0 = ecl_cadr(v3c);
   T1 = L29tpl_parse_forms(1, v2line);
   value0 = CONS(T0,T1);
   cl_env_copy->nvalues = 1;
   return value0;
L41:;
   T0 = ecl_caddr(v3c);
   if (!((T0)==(VV[68]))) { goto L43; }
   T0 = ecl_cadr(v3c);
   T1 = L31tpl_parse_strings(v2line);
   T2 = CONS(T0,T1);
   value0 = L27harden_command(T2);
   return value0;
L43:;
   T0 = ecl_caddr(v3c);
   if (!((T0)==(VV[69]))) { goto L45; }
   T0 = ecl_cadr(v3c);
   value0 = L27harden_command(T0);
   return value0;
L45:;
   T0 = ecl_cadr(v3c);
   T1 = L29tpl_parse_forms(2, v2line, ECL_T);
   T2 = CONS(T0,T1);
   value0 = L27harden_command(T2);
   return value0;
  }
 }
}
/*	function definition for TPL-PARSE-FORMS                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L29tpl_parse_forms(cl_narg narg, cl_object v1line, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2quote;
  va_list args; va_start(args,v1line);
  {
   int i = 1;
   if (i >= narg) {
    v2quote = ECL_NIL;
   } else {
    i++;
    v2quote = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v3stream;
   v3stream = cl_make_string_input_stream(3, v1line, ecl_make_fixnum(0), ECL_NIL);
   {
    cl_object v4;
    cl_object v5form;
    cl_object v6list;
    v4 = cl_read(3, v3stream, ECL_NIL, ecl_symbol_value(VV[10]));
    v5form = v4;
    v6list = ECL_NIL;
    goto L8;
L7:;
    if (Null(v2quote)) { goto L13; }
    T0 = cl_list(2, ECL_SYM("QUOTE",679), v5form);
    goto L12;
L13:;
    T0 = v5form;
L12:;
    v6list = CONS(T0,v6list);
    v5form = cl_read(3, v3stream, ECL_NIL, ecl_symbol_value(VV[10]));
L8:;
    if ((v5form)==(ecl_symbol_value(VV[10]))) { goto L17; }
    goto L7;
L17:;
    value0 = cl_nreverse(v6list);
    return value0;
   }
  }
 }
}
/*	function definition for TPL-PARSE-STRINGS                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L31tpl_parse_strings(cl_object v1line)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   cl_fixnum v3;
   cl_object v4i;
   cl_object v5start;
   cl_object v6end;
   cl_object v7list;
   {cl_object v8;
    v8 = ECL_NIL;
    v8 = ecl_make_cfun((cl_objectfn_fixed)LC30__g168,ECL_NIL,Cblock,1);
    v2 = v8;
   }
   v3 = ecl_length(v1line);
   v4i = ecl_make_fixnum(0);
   v5start = ECL_NIL;
   v6end = ECL_NIL;
   v7list = ECL_NIL;
   goto L9;
L8:;
   v5start = cl_position_if_not(4, v2, v1line, ECL_SYM("START",1310), v4i);
   if (!(v5start==ECL_NIL)) { goto L12; }
   v6end = ecl_make_fixnum(v3);
   goto L11;
L12:;
   T0 = ecl_elt(v1line,ecl_to_size(v5start));
   if (!((ecl_char_code(T0))==((ecl_character)(34)))) { goto L16; }
   {
    cl_object v9;                                 /*  STRING          */
    cl_object v10;                                /*  N               */
    value0 = cl_read_from_string(5, v1line, ECL_T, ECL_NIL, ECL_SYM("START",1310), v5start);
    v9 = value0;
    v10 = cl_env_copy->values[1];
    v7list = CONS(v9,v7list);
    v6end = v10;
    goto L11;
   }
L16:;
   value0 = cl_position_if(4, v2, v1line, ECL_SYM("START",1310), v5start);
   if ((value0)!=ECL_NIL) { goto L25; }
   v6end = ecl_make_fixnum(v3);
   goto L23;
L25:;
   v6end = value0;
   goto L23;
L23:;
   T0 = cl_subseq(3, v1line, v5start, v6end);
   v7list = CONS(T0,v7list);
L11:;
   v4i = v6end;
L9:;
   if (ecl_number_compare(v4i,ecl_make_fixnum(v3))>=0) { goto L30; }
   goto L8;
L30:;
   value0 = cl_nreverse(v7list);
   return value0;
  }
 }
}
/*	local function G168                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC30__g168(cl_object v1c)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_make_bool(((v1c)==ECL_CODE_CHAR((ecl_character)(32))));
  if ((value0)!=ECL_NIL) { goto L2; }
  value0 = ecl_make_bool(((v1c)==ECL_CODE_CHAR((ecl_character)(9))));
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for TPL-PRINT                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L32tpl_print(cl_object v1values)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  cl_fresh_line(0);
  {
   cl_object v2;
   v2 = v1values;
   goto L5;
L4:;
   {
    cl_object v3v;
    v3v = ecl_car(v2);
    ecl_prin1(v3v,ECL_NIL);
    ecl_terpri(ECL_NIL);
   }
   v2 = ecl_cdr(v2);
L5:;
   if (Null(v2)) { goto L13; }
   goto L4;
L13:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for TPL-UNKNOWN-COMMAND                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L33tpl_unknown_command(cl_object v1command)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  cl_format(3, ECL_T, _ecl_static_18, v1command);
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  return value0;
 }
}
/*	function definition for TPL-POP-COMMAND                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L34tpl_pop_command(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  {
   cl_object v1;
   v1 = ecl_symbol_value(VV[0]);
   if (ecl_unlikely(!ECL_LISTP(v1))) FEtype_error_list(v1);
   if (Null(v1)) { goto L5; }
   {
    cl_object v2;
    v2 = ECL_CONS_CDR(v1);
    cl_set(VV[0],v2);
    v1 = ECL_CONS_CAR(v1);
   }
L5:;
   T0 = v1;
  }
  cl_env_copy->values[0] = ECL_T;
  cl_env_copy->nvalues = 1;
  cl_throw(T0);
 }
}
/*	function definition for TPL-QUIT-COMMAND                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L35tpl_quit_command(cl_narg narg, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1level;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1level = ecl_make_fixnum(0);
   } else {
    i++;
    v1level = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (!(ecl_number_compare(v1level,ecl_make_fixnum(0))>=0)) { goto L2; }
  if (!(ecl_number_compare(v1level,ecl_symbol_value(VV[14]))<0)) { goto L2; }
  {
   cl_object v2x;
   T0 = ecl_minus(ecl_symbol_value(VV[14]),v1level);
   T1 = ecl_minus(T0,ecl_make_fixnum(1));
   v2x = ecl_nth(ecl_to_size(T1),ecl_symbol_value(VV[0]));
   cl_env_copy->values[0] = v2x;
   cl_env_copy->nvalues = 1;
   cl_throw(v2x);
  }
L2:;
  value0 = L59tpl_print_current();
  return value0;
 }
}
/*	function definition for TPL-PREVIOUS                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L36tpl_previous(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1n;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1n = ecl_make_fixnum(1);
   } else {
    i++;
    v1n = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v2i;
   v2i = si_ihs_prev(ecl_symbol_value(VV[5]));
   goto L6;
L5:;
   if (Null(L65ihs_visible(v2i))) { goto L8; }
   cl_set(VV[5],v2i);
   v1n = ecl_minus(v1n,ecl_make_fixnum(1));
L8:;
   v2i = si_ihs_prev(v2i);
L6:;
   if (ecl_number_compare(v2i,ecl_symbol_value(VV[3]))<0) { goto L15; }
   if (ecl_number_compare(v1n,ecl_make_fixnum(0))<=0) { goto L15; }
   goto L5;
L15:;
  }
  L68set_break_env();
  value0 = L59tpl_print_current();
  return value0;
 }
}
/*	function definition for TPL-NEXT                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L37tpl_next(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1n;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1n = ecl_make_fixnum(1);
   } else {
    i++;
    v1n = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v2i;
   v2i = si_ihs_next(ecl_symbol_value(VV[5]));
   goto L6;
L5:;
   if (Null(L65ihs_visible(v2i))) { goto L8; }
   cl_set(VV[5],v2i);
   v1n = ecl_minus(v1n,ecl_make_fixnum(1));
L8:;
   v2i = si_ihs_next(v2i);
L6:;
   if (ecl_number_compare(v2i,ecl_symbol_value(VV[4]))>0) { goto L15; }
   if (ecl_number_compare(v1n,ecl_make_fixnum(0))<=0) { goto L15; }
   goto L5;
L15:;
  }
  L68set_break_env();
  value0 = L59tpl_print_current();
  return value0;
 }
}
/*	function definition for TPL-GO                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L38tpl_go(cl_object v1ihs_index)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = (ecl_number_compare(v1ihs_index,ecl_symbol_value(VV[3]))>=0?v1ihs_index:ecl_symbol_value(VV[3]));
  cl_set(VV[5],(ecl_number_compare(T0,ecl_symbol_value(VV[4]))<=0?T0:ecl_symbol_value(VV[4])));
  if (Null(L65ihs_visible(ecl_symbol_value(VV[5])))) { goto L3; }
  L68set_break_env();
  value0 = L59tpl_print_current();
  return value0;
L3:;
  value0 = L36tpl_previous(0);
  return value0;
 }
}
/*	function definition for TPL-PRINT-MESSAGE                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L39tpl_print_message()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_symbol_value(VV[12]))) { goto L1; }
  ecl_princ(ecl_symbol_value(VV[12]),ECL_NIL);
  ecl_terpri(ECL_NIL);
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  return value0;
 }
}
/*	function definition for TPL-DISASSEMBLE-COMMAND               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L40tpl_disassemble_command()
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-LEVEL*",51),ecl_make_fixnum(2)); /*  *PRINT-LEVEL* */
  ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-LENGTH*",50),ecl_make_fixnum(4)); /*  *PRINT-LENGTH* */
  ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-PRETTY*",55),ECL_T); /*  *PRINT-PRETTY* */
  ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-ESCAPE*",48),ECL_NIL); /*  *PRINT-ESCAPE* */
  ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-READABLY*",57),ECL_NIL); /*  *PRINT-READABLY* */
  T0 = si_ihs_fun(ecl_symbol_value(VV[5]));
  if ((si_bc_disassemble(T0))!=ECL_NIL) { goto L1; }
  L59tpl_print_current();
  cl_format(2, ECL_T, _ecl_static_19);
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  ecl_bds_unwind_n(cl_env_copy,5);
  return value0;
 }
}
/*	function definition for TPL-LAMBDA-EXPRESSION-COMMAND         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L41tpl_lambda_expression_command()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v1function;
   cl_object v2le;
   v1function = si_ihs_fun(ecl_symbol_value(VV[5]));
   v2le = cl_function_lambda_expression(v1function);
   if (Null(v2le)) { goto L4; }
   cl_pprint(1, v2le);
   goto L3;
L4:;
   cl_format(2, ECL_T, _ecl_static_20);
L3:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 0;
   return value0;
  }
 }
}
/*	function definition for RECONSTRUCT-BYTECODES-LAMBDA-LIST     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L42reconstruct_bytecodes_lambda_list(cl_object v1data)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2output;
   v2output = ECL_NIL;
   {
    cl_object v3;
    {
     cl_object v4;
     v4 = v1data;
     if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
     if (Null(v4)) { goto L7; }
     {
      cl_object v5;
      v5 = ECL_CONS_CDR(v4);
      v1data = v5;
      v4 = ECL_CONS_CAR(v4);
     }
L7:;
     v3 = v4;
    }
    {
     cl_fixnum v4n;
     v4n = 0;
     goto L15;
L14:;
     {
      cl_object v5;
      v5 = v1data;
      if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
      if (Null(v5)) { goto L23; }
      {
       cl_object v6;
       v6 = ECL_CONS_CDR(v5);
       v1data = v6;
       v5 = ECL_CONS_CAR(v5);
      }
L23:;
      T0 = v5;
     }
     v2output = CONS(T0,v2output);
     {
      cl_object v5;
      v5 = ecl_make_integer((v4n)+1);
      {
       bool v6;
       v6 = ECL_FIXNUMP(v5);
       if (ecl_unlikely(!(v6)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v5);
      }
      v4n = ecl_fixnum(v5);
     }
L15:;
     if (!(ecl_number_compare(ecl_make_fixnum(v4n),v3)<0)) { goto L33; }
     goto L14;
L33:;
    }
   }
   {
    cl_fixnum v3l;
    {
     cl_object v4;
     {
      cl_object v5;
      v5 = v1data;
      if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
      if (Null(v5)) { goto L41; }
      {
       cl_object v6;
       v6 = ECL_CONS_CDR(v5);
       v1data = v6;
       v5 = ECL_CONS_CAR(v5);
      }
L41:;
      v4 = v5;
     }
     {
      bool v5;
      v5 = ECL_FIXNUMP(v4);
      if (ecl_unlikely(!(v5)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v4);
     }
     v3l = ecl_fixnum(v4);
    }
    if ((v3l)==0) { goto L35; }
    v2output = CONS(ECL_SYM("&OPTIONAL",11),v2output);
    {
     cl_fixnum v4n;
     v4n = 0;
     goto L53;
L52:;
     T0 = ecl_car(v1data);
     v2output = CONS(T0,v2output);
     v1data = ecl_cdddr(v1data);
     v4n = (v4n)+1;
L53:;
     if (!((v4n)<(v3l))) { goto L61; }
     goto L52;
L61:;
    }
   }
L35:;
   {
    cl_object v3rest;
    {
     cl_object v4;
     v4 = v1data;
     if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
     if (Null(v4)) { goto L68; }
     {
      cl_object v5;
      v5 = ECL_CONS_CDR(v4);
      v1data = v5;
      v4 = ECL_CONS_CAR(v4);
     }
L68:;
     v3rest = v4;
    }
    if (Null(v3rest)) { goto L63; }
    v2output = CONS(ECL_SYM("&REST",12),v2output);
    v2output = CONS(v3rest,v2output);
   }
L63:;
   {
    cl_object v3allow_other_keys;
    {
     cl_object v4;
     v4 = v1data;
     if (ecl_unlikely(!ECL_LISTP(v4))) FEtype_error_list(v4);
     if (Null(v4)) { goto L83; }
     {
      cl_object v5;
      v5 = ECL_CONS_CDR(v4);
      v1data = v5;
      v4 = ECL_CONS_CAR(v4);
     }
L83:;
     v3allow_other_keys = v4;
    }
    if ((v3allow_other_keys)==(ecl_make_fixnum(0))) { goto L78; }
    v2output = CONS(ECL_SYM("&KEY",10),v2output);
    {
     cl_fixnum v4l;
     {
      cl_object v5;
      {
       cl_object v6;
       v6 = v1data;
       if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
       if (Null(v6)) { goto L98; }
       {
        cl_object v7;
        v7 = ECL_CONS_CDR(v6);
        v1data = v7;
        v6 = ECL_CONS_CAR(v6);
       }
L98:;
       v5 = v6;
      }
      {
       bool v6;
       v6 = ECL_FIXNUMP(v5);
       if (ecl_unlikely(!(v6)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v5);
      }
      v4l = ecl_fixnum(v5);
     }
     {
      cl_fixnum v5n;
      v5n = 0;
      goto L107;
L106:;
      {
       cl_object v6key;
       cl_object v7var;
       v6key = ecl_car(v1data);
       v7var = ecl_cadr(v1data);
       if (Null(cl_keywordp(v6key))) { goto L115; }
       if ((cl_stringE(2, v6key, v7var))!=ECL_NIL) { goto L112; }
       goto L113;
L115:;
       goto L113;
L113:;
       T0 = cl_list(2, v6key, v7var);
       v7var = ecl_list1(T0);
L112:;
       v2output = CONS(v7var,v2output);
      }
      v5n = (v5n)+1;
L107:;
      if (!((v5n)<(v4l))) { goto L121; }
      goto L106;
L121:;
     }
    }
    if (Null(v3allow_other_keys)) { goto L78; }
    v2output = CONS(ECL_SYM("&ALLOW-OTHER-KEYS",6),v2output);
   }
L78:;
   value0 = cl_nreverse(v2output);
   return value0;
  }
 }
}
/*	function definition for LAMBDA-LIST-FROM-ANNOTATIONS          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L43lambda_list_from_annotations(cl_object v1name)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2args;
   v2args = ecl_function_dispatch(cl_env_copy,ECL_SYM("GET-ANNOTATION",1758))(3, v1name, ECL_SYM("LAMBDA-LIST",998), ECL_NIL) /*  GET-ANNOTATION */;
   if (Null(v2args)) { goto L4; }
   T0 = ECL_T;
   goto L2;
L4:;
   T0 = ECL_NIL;
   goto L2;
L2:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = T0;
   cl_env_copy->values[0] = v2args;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for FUNCTION-LAMBDA-LIST                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L44function_lambda_list(cl_object v1function)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_SYMBOLP(v1function))) { goto L1; }
  if ((cl_special_operator_p(v1function))!=ECL_NIL) { goto L5; }
  if (Null(cl_macro_function(1, v1function))) { goto L3; }
  goto L4;
L5:;
L4:;
  value0 = L43lambda_list_from_annotations(v1function);
  return value0;
L3:;
  v1function = cl_fdefinition(v1function);
  goto TTL;
L1:;
  if (Null(si_of_class_p(2, v1function, ECL_SYM("GENERIC-FUNCTION",945)))) { goto L9; }
  T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("GENERIC-FUNCTION-LAMBDA-LIST",1521))(1, v1function) /*  GENERIC-FUNCTION-LAMBDA-LIST */;
  cl_env_copy->nvalues = 2;
  cl_env_copy->values[1] = ECL_T;
  cl_env_copy->values[0] = T0;
  return cl_env_copy->values[0];
L9:;
  {
   cl_object v2;
   {
    cl_object v3f;
    v3f = cl_function_lambda_expression(v1function);
    if (Null(v3f)) { goto L13; }
    {
     cl_object v4list;
     cl_object v5ndx;
     T0 = ecl_car(v3f);
     if (!((T0)==(ECL_SYM("LAMBDA",452)))) { goto L16; }
     v4list = ecl_cadr(v3f);
     goto L15;
L16:;
     v4list = ecl_caddr(v3f);
L15:;
     v5ndx = cl_position(2, ECL_SYM("&AUX",7), v4list);
     if (Null(v5ndx)) { goto L20; }
     T1 = ecl_one_minus(v5ndx);
     T0 = cl_subseq(3, v4list, ecl_make_fixnum(0), T1);
     goto L19;
L20:;
     T0 = v4list;
L19:;
     cl_env_copy->nvalues = 2;
     cl_env_copy->values[1] = ECL_T;
     cl_env_copy->values[0] = T0;
     return cl_env_copy->values[0];
    }
L13:;
    v2 = ECL_NIL;
   }
   if (Null(v2)) { goto L22; }
   value0 = v2;
   cl_env_copy->nvalues = 1;
   return value0;
L22:;
   {
    cl_object v3;
    {
     cl_object v5;                                /*  BYTECODES       */
     cl_object v6;                                /*  DATA            */
     value0 = si_bc_split(v1function);
     {
      const int v7 = cl_env_copy->nvalues;
      cl_object v8;
      v8 = (v7<=1)? ECL_NIL : cl_env_copy->values[1];
      v5 = v8;
      v8 = (v7<=2)? ECL_NIL : cl_env_copy->values[2];
      v6 = v8;
     }
     if (Null(v5)) { goto L26; }
     v6 = si_coerce_to_list(1, v6);
     T0 = L42reconstruct_bytecodes_lambda_list(v6);
     cl_env_copy->nvalues = 2;
     cl_env_copy->values[1] = ECL_T;
     cl_env_copy->values[0] = T0;
     return cl_env_copy->values[0];
L26:;
     v3 = ECL_NIL;
    }
    if (Null(v3)) { goto L30; }
    value0 = v3;
    cl_env_copy->nvalues = 1;
    return value0;
L30:;
    T0 = si_compiled_function_name(v1function);
    value0 = L43lambda_list_from_annotations(T0);
    return value0;
   }
  }
 }
}
/*	function definition for DECODE-ENV-ELT                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L45decode_env_elt(cl_object v1env, cl_object v2ndx)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   
	cl_object v = v1env;
	cl_index ndx = ecl_to_fixnum(v2ndx);
	typedef struct ecl_var_debug_info *pinfo;
	pinfo d = (pinfo)(v->vector.self.t[1]) + ndx;
	cl_object name = make_constant_base_string(d->name);
	void *value = (void*)(v->vector.self.t[2+ndx]);
	cl_object output;
	switch (d->type) {
	case _ecl_object_loc:
		output = *((cl_object*)value);
		break;
	case _ecl_fixnum_loc: {
		cl_fixnum *p = (cl_fixnum*)value;
		output = ecl_make_integer(*p);
		break;
	}
	case _ecl_float_loc: {
		float *p = (float*)value;
		output = ecl_make_single_float(*p);
		break;
	}
	case _ecl_double_loc: {
		double *p = (double*)value;
		output = ecl_make_double_float(*p);
		break;
	}
#ifdef ECL_SSE2
	case _ecl_int_sse_pack_loc: {
		__m128i *p = (__m128i*)value;
		output = ecl_make_int_sse_pack(_mm_loadu_si128(p));
		break;
	}
	case _ecl_float_sse_pack_loc: {
		__m128 *p = (__m128*)value;
		output = ecl_make_float_sse_pack(_mm_loadu_ps((float*)p));
		break;
	}
	case _ecl_double_sse_pack_loc: {
		__m128d *p = (__m128d*)value;
		output = ecl_make_double_sse_pack(_mm_loadu_pd((double*)p));
		break;
	}
#endif
	default: {
		ecl_base_char *p = (ecl_base_char*)value;
		output = ECL_CODE_CHAR(*p);
		break;
	}
	}
	v3= CONS(name,output);

   value0 = v3;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for DECODE-IHS-ENV                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L46decode_ihs_env(cl_object v1_break_env_)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  ecl_bds_bind(cl_env_copy,VV[2],v1_break_env_);  /*  *BREAK-ENV*     */
TTL:
  {
   cl_object v2env;
   v2env = ecl_symbol_value(VV[2]);
   if (!(ECL_VECTORP(v2env))) { goto L2; }
   {
    cl_object v3next;
    T0 = (v2env)->vector.self.t[0];
    v3next = L46decode_ihs_env(T0);
    {
     cl_object v4l;
     {
      cl_fixnum v5;
      v5 = ecl_length(v2env);
      v4l = ecl_minus(ecl_make_fixnum(v5),ecl_make_fixnum(2));
     }
     {
      cl_object v5i;
      cl_object v6;
      v5i = ecl_make_fixnum(0);
      v6 = v4l;
L10:;
      if (!(ecl_number_compare(v5i,v6)>=0)) { goto L12; }
      goto L11;
L12:;
      T1 = L45decode_env_elt(v2env, v5i);
      v3next = CONS(T1,v3next);
      v5i = ecl_one_plus(v5i);
      goto L10;
L11:;
      T0 = ECL_NIL;
     }
    }
    value0 = cl_nreconc(T0, v3next);
    ecl_bds_unwind1(cl_env_copy);
    return value0;
   }
L2:;
   value0 = v2env;
   cl_env_copy->nvalues = 1;
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
 }
}
/*	function definition for IHS-ENVIRONMENT                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L50ihs_environment(cl_object v1ihs_index)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2functions;
   cl_object v3blocks;
   cl_object v4local_variables;
   cl_object v5record0;
   cl_object v6record1;
   v2functions = ECL_NIL;
   v3blocks = ECL_NIL;
   v4local_variables = ECL_NIL;
   v5record0 = ECL_NIL;
   v6record1 = ECL_NIL;
   {
    cl_object v7;
    T0 = si_ihs_env(v1ihs_index);
    v7 = L46decode_ihs_env(T0);
    goto L10;
L9:;
    {
     cl_object v8record;
     v8record = ecl_car(v7);
     if (!(ECL_ATOM(v8record))) { goto L15; }
     T0 = si_compiled_function_name(v8record);
     v2functions = CONS(T0,v2functions);
     goto L14;
L15:;
     v5record0 = ecl_car(v8record);
     v6record1 = ecl_cdr(v8record);
     if (!(ECL_STRINGP(v5record0))) { goto L24; }
     T0 = cl_find_package(_ecl_static_21);
     ecl_bds_bind(cl_env_copy,ECL_SYM("*PACKAGE*",43),T0); /*  *PACKAGE* */
     {
      cl_object v9;
      v9 = ecl_symbol_value(ECL_SYM("+IO-SYNTAX-PROGV-LIST+",1720));
      {
       cl_object v11, v12; cl_index v10;
       v11 = _ecl_car(v9);
       v12 = _ecl_cdr(v9);
       v10 = ecl_progv(cl_env_copy, v11, v12);
       v5record0 = cl_read_from_string(1, v5record0);
       ecl_bds_unwind(cl_env_copy,v10);
       ecl_bds_unwind1(cl_env_copy);
      }
     }
L24:;
     if (ECL_SYMBOLP(v5record0)) { goto L30; }
     if (!(ECL_STRINGP(v5record0))) { goto L18; }
     goto L19;
L30:;
L19:;
     v4local_variables = cl_acons(v5record0, v6record1, v4local_variables);
     goto L14;
L18:;
     if (!(ECL_SYMBOLP(v6record1))) { goto L14; }
     v3blocks = CONS(v6record1,v3blocks);
L14:;
    }
    v7 = ecl_cdr(v7);
L10:;
    if (Null(v7)) { goto L37; }
    goto L9;
L37:;
   }
   {
    cl_object v8;                                 /*  SPECIAL-VARIABLES */
    cl_object v9;                                 /*  RESTARTS        */
    T0 = LC48special_variables_alist(v1ihs_index);
    value0 = LC49extract_restarts(T0);
    v8 = value0;
    v9 = cl_env_copy->values[1];
    T0 = cl_nreverse(v4local_variables);
    cl_env_copy->nvalues = 5;
    cl_env_copy->values[4] = v9;
    cl_env_copy->values[3] = v3blocks;
    cl_env_copy->values[2] = v2functions;
    cl_env_copy->values[1] = v8;
    cl_env_copy->values[0] = T0;
    return cl_env_copy->values[0];
   }
  }
 }
}
/*	local function EXTRACT-RESTARTS                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC49extract_restarts(cl_object v1variables_alist)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2record;
   v2record = ecl_assql(ECL_SYM("*RESTART-CLUSTERS*",4),v1variables_alist);
   if (Null(v2record)) { goto L2; }
   {
    cl_object v3bindings;
    cl_object v4new_bindings;
    v3bindings = ecl_cdr(v2record);
    v4new_bindings = ecl_car(v3bindings);
    T0 = cl_delete(2, v2record, v1variables_alist);
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = v4new_bindings;
    cl_env_copy->values[0] = T0;
    return cl_env_copy->values[0];
   }
L2:;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = ECL_NIL;
   cl_env_copy->values[0] = v1variables_alist;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function SPECIAL-VARIABLES-ALIST                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC48special_variables_alist(cl_object v1ihs_index)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v2top;
   v2top = ecl_fixnum(si_ihs_top());
   if (ecl_number_compare(v1ihs_index,ecl_make_fixnum(v2top))>0) { goto L2; }
   {
    cl_object v3bds_min;
    cl_fixnum v4bds_top;
    cl_object v5bds_max;
    cl_object v6variables;
    T0 = si_ihs_bds(v1ihs_index);
    v3bds_min = ecl_one_plus(T0);
    v4bds_top = ecl_fixnum(si_bds_top());
    if (!(ecl_number_equalp(v1ihs_index,ecl_make_fixnum(v2top)))) { goto L7; }
    v5bds_max = ecl_make_fixnum(v4bds_top);
    goto L6;
L7:;
    T0 = ecl_one_plus(v1ihs_index);
    v5bds_max = si_ihs_bds(T0);
L6:;
    v6variables = LC47newly_bound_special_variables(v3bds_min, v5bds_max);
    {
     cl_object v7output;
     v7output = ECL_NIL;
     {
      cl_object v8;
      cl_object v9i;
      cl_object v10;
      v8 = ecl_one_plus(v5bds_max);
      T0 = cl_realp(v8);
      if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("REAL",703),v8);
      v9i = v8;
      v10 = ecl_make_fixnum(v4bds_top);
      {
       cl_object v11var;
       v11var = ECL_NIL;
L16:;
       if (!(ecl_number_compare(v9i,v10)>0)) { goto L18; }
       goto L17;
L18:;
       v11var = si_bds_var(v9i);
       if (Null(si_memq(v11var,v6variables))) { goto L22; }
       v6variables = cl_delete(2, v11var, v6variables);
       T0 = si_bds_val(v9i);
       v7output = cl_acons(v11var, T0, v7output);
L22:;
       v9i = ecl_one_plus(v9i);
       goto L16;
L17:;
       {
        cl_object v12v;
        cl_object v13;
        v12v = ECL_NIL;
        if (ecl_unlikely(!ECL_LISTP(v6variables))) FEtype_error_list(v6variables);
        v13 = v6variables;
        {
         cl_object v14;
         cl_object v15;
         v14 = ecl_list1(ECL_NIL);
         v15 = v14;
L37:;
         if (!(ecl_endp(v13))) { goto L39; }
         goto L38;
L39:;
         v12v = _ecl_car(v13);
         {
          cl_object v16;
          v16 = _ecl_cdr(v13);
          if (ecl_unlikely(!ECL_LISTP(v16))) FEtype_error_list(v16);
          v13 = v16;
         }
         if (ecl_unlikely(ECL_ATOM(v15))) FEtype_error_cons(v15);
         T1 = v15;
         T2 = cl_symbol_value(v12v);
         T3 = CONS(v12v,T2);
         v15 = ecl_list1(T3);
         (ECL_CONS_CDR(T1)=v15,T1);
         goto L37;
L38:;
         T0 = ecl_cdr(v14);
         goto L31;
        }
       }
L31:;
       value0 = ecl_append(T0,v7output);
       cl_env_copy->nvalues = 1;
       return value0;
      }
     }
    }
   }
L2:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function NEWLY-BOUND-SPECIAL-VARIABLES                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC47newly_bound_special_variables(cl_object v1bds_min, cl_object v2bds_max)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3i;
   cl_object v4;
   T0 = cl_realp(v1bds_min);
   if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("REAL",703),v1bds_min);
   v3i = v1bds_min;
   T0 = cl_realp(v2bds_max);
   if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(ECL_SYM("REAL",703),v2bds_max);
   v4 = v2bds_max;
   {
    cl_object v5variable;
    v5variable = ECL_NIL;
    {
     cl_object v6;
     cl_object v7;
     cl_object v8output;
     v6 = ecl_list1(ECL_NIL);
     v7 = v6;
     v8output = ECL_NIL;
L9:;
     if (!(ecl_number_compare(v3i,v4)>0)) { goto L11; }
     goto L10;
L11:;
     v5variable = si_bds_var(v3i);
     if ((si_memq(v5variable,v8output))!=ECL_NIL) { goto L15; }
     if (ecl_unlikely(ECL_ATOM(v7))) FEtype_error_cons(v7);
     T0 = v7;
     v7 = ecl_list1(v5variable);
     (ECL_CONS_CDR(T0)=v7,T0);
     v8output = ecl_cdr(v6);
L15:;
     v3i = ecl_one_plus(v3i);
     goto L9;
L10:;
     value0 = v8output;
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
  }
 }
}
/*	function definition for TPL-PRINT-VARIABLES                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L51tpl_print_variables(cl_object v1prefix, cl_object v2variables, cl_object v3no_values)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  cl_format(2, ECL_T, v1prefix);
  if (Null(v2variables)) { goto L2; }
  {
   cl_object v4var;
   cl_object v5value;
   cl_object v6;
   v4var = ECL_NIL;
   v5value = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v2variables))) FEtype_error_list(v2variables);
   v6 = v2variables;
L8:;
   if (!(ecl_endp(v6))) { goto L10; }
   goto L9;
L10:;
   {
    cl_object v7;
    v7 = _ecl_car(v6);
    v4var = ecl_car(v7);
    v7 = ecl_cdr(v7);
    v5value = v7;
   }
   {
    cl_object v7;
    v7 = _ecl_cdr(v6);
    if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
    v6 = v7;
   }
   if (Null(v3no_values)) { goto L24; }
   cl_format(3, ECL_T, _ecl_static_22, v4var);
   goto L23;
L24:;
   cl_format(4, ECL_T, _ecl_static_23, v4var, v5value);
L23:;
   goto L8;
L9:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L2:;
  value0 = cl_format(2, ECL_T, _ecl_static_24);
  return value0;
 }
}
/*	function definition for TPL-VARIABLES-COMMAND                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L52tpl_variables_command(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1no_values;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1no_values = ECL_NIL;
   } else {
    i++;
    v1no_values = va_arg(args,cl_object);
   }
  }
  va_end(args);
  ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-LEVEL*",51),ecl_make_fixnum(2)); /*  *PRINT-LEVEL* */
  ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-LENGTH*",50),ecl_make_fixnum(4)); /*  *PRINT-LENGTH* */
  ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-PRETTY*",55),ECL_T); /*  *PRINT-PRETTY* */
  ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-ESCAPE*",48),ECL_NIL); /*  *PRINT-ESCAPE* */
  ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-READABLY*",57),ECL_NIL); /*  *PRINT-READABLY* */
  {
   cl_object v3;                                  /*  LOCAL-VARIABLES */
   cl_object v4;                                  /*  SPECIAL-VARIABLES */
   cl_object v5;                                  /*  FUNCTIONS       */
   cl_object v6;                                  /*  BLOCKS          */
   cl_object v7;                                  /*  RESTARTS        */
   value0 = L50ihs_environment(ecl_symbol_value(VV[5]));
   v3 = value0;
   {
    const int v8 = cl_env_copy->nvalues;
    cl_object v9;
    v9 = (v8<=1)? ECL_NIL : cl_env_copy->values[1];
    v4 = v9;
    v9 = (v8<=2)? ECL_NIL : cl_env_copy->values[2];
    v5 = v9;
    v9 = (v8<=3)? ECL_NIL : cl_env_copy->values[3];
    v6 = v9;
    v9 = (v8<=4)? ECL_NIL : cl_env_copy->values[4];
    v7 = v9;
   }
   cl_format(3, ECL_T, _ecl_static_25, v5);
   cl_format(3, ECL_T, _ecl_static_26, v6);
   if (Null(v7)) { goto L6; }
   cl_format(2, ECL_T, _ecl_static_27);
   {
    cl_object v8r;
    cl_object v9;
    v8r = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
    v9 = v7;
L12:;
    if (!(ecl_endp(v9))) { goto L14; }
    goto L13;
L14:;
    v8r = _ecl_car(v9);
    {
     cl_object v10;
     v10 = _ecl_cdr(v9);
     if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
     v9 = v10;
    }
    T0 = (cl_env_copy->function=(ECL_SYM("RESTART-NAME",723)->symbol.gfdef))->cfun.entry(1, v8r) /*  RESTART-NAME */;
    cl_format(4, ECL_T, _ecl_static_28, T0, v8r);
    goto L12;
L13:;
   }
L6:;
   L51tpl_print_variables(_ecl_static_29, v3, v1no_values);
   L51tpl_print_variables(_ecl_static_30, v4, v1no_values);
  }
  ecl_terpri(ECL_NIL);
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  ecl_bds_unwind_n(cl_env_copy,5);
  return value0;
 }
}
/*	function definition for TPL-INSPECT-COMMAND                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L53tpl_inspect_command(cl_object v1var_name)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ECL_SYMBOLP(v1var_name))) { goto L1; }
  v1var_name = ecl_symbol_name(v1var_name);
L1:;
  {
   cl_object v2val_pair;
   {
    cl_object v3;
    v3 = L46decode_ihs_env(ecl_symbol_value(VV[2]));
    goto L8;
L7:;
    {
     cl_object v4;
     cl_object v5;
     if (ecl_unlikely(ECL_ATOM(v3))) FEtype_error_cons(v3);
     v4 = v3;
     v5 = ECL_CONS_CAR(v4);
     if (Null(v5)) { goto L10; }
     {
      cl_object v6;
      if (ecl_unlikely(ECL_ATOM(v5))) FEtype_error_cons(v5);
      T0 = v5;
      v6 = ECL_CONS_CAR(T0);
      {
       cl_object v7s2;
       v7s2 = v6;
       if (!(ECL_SYMBOLP(v7s2))) { goto L20; }
       v7s2 = ecl_symbol_name(v7s2);
L20:;
       if (!(ECL_STRINGP(v7s2))) { goto L23; }
       if (Null(cl_string_equal(2, v1var_name, v7s2))) { goto L10; }
       goto L18;
L23:;
       goto L10;
      }
L18:;
      v2val_pair = v5;
      goto L4;
     }
    }
L10:;
    v3 = ECL_CONS_CDR(v3);
L8:;
    if (v3==ECL_NIL) { goto L27; }
    goto L7;
L27:;
    v2val_pair = ECL_NIL;
   }
L4:;
   if (Null(v2val_pair)) { goto L29; }
   {
    cl_object v3val;
    v3val = ecl_cdr(v2val_pair);
    value0 = cl_inspect(v3val);
    return value0;
   }
L29:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for TPL-BDS-COMMAND                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L54tpl_bds_command(cl_narg narg, ...)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1var;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1var = ECL_NIL;
   } else {
    i++;
    v1var = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (Null(v1var)) { goto L2; }
  {
   cl_object v2;
   cl_fixnum v3;
   cl_object v4bi;
   T0 = ecl_one_minus(ecl_symbol_value(VV[6]));
   T1 = (ecl_number_compare(ecl_make_fixnum(0),T0)>=0?ecl_make_fixnum(0):T0);
   T2 = si_frs_bds(T1);
   v2 = ecl_make_integer((ecl_to_fixnum(T2))+1);
   T0 = ecl_one_plus(ecl_symbol_value(VV[7]));
   v3 = ecl_fixnum(si_frs_bds(T0));
   v4bi = v2;
   goto L9;
L8:;
   T0 = si_bds_var(v4bi);
   if (!((T0)==(v1var))) { goto L11; }
   {
    cl_object v5val;
    v5val = si_bds_val(v4bi);
    if (!((v5val)==(ecl_symbol_value(ECL_SYM("UNBOUND",2))))) { goto L14; }
    value0 = _ecl_static_31;
    cl_env_copy->nvalues = 1;
    return value0;
L14:;
    value0 = v5val;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L11:;
   v4bi = ecl_one_plus(v4bi);
L9:;
   if (ecl_number_compare(v4bi,ecl_make_fixnum(v3))>0) { goto L18; }
   goto L8;
L18:;
   cl_format(2, ECL_T, _ecl_static_32);
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 0;
   return value0;
  }
L2:;
  {
   cl_object v5;
   cl_fixnum v6;
   cl_object v7;
   cl_object v8bi;
   cl_object v9fi;
   T0 = ecl_one_minus(ecl_symbol_value(VV[6]));
   T1 = (ecl_number_compare(ecl_make_fixnum(0),T0)>=0?ecl_make_fixnum(0):T0);
   T2 = si_frs_bds(T1);
   v5 = ecl_make_integer((ecl_to_fixnum(T2))+1);
   T0 = ecl_one_plus(ecl_symbol_value(VV[7]));
   v6 = ecl_fixnum(si_frs_bds(T0));
   v7 = ecl_symbol_value(VV[6]);
   v8bi = v5;
   v9fi = v7;
   ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-LEVEL*",51),ecl_make_fixnum(2)); /*  *PRINT-LEVEL* */
   ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-LENGTH*",50),ecl_make_fixnum(4)); /*  *PRINT-LENGTH* */
   ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-PRETTY*",55),ECL_T); /*  *PRINT-PRETTY* */
   goto L28;
L27:;
   goto L33;
L32:;
   L57print_frs(v9fi);
   v9fi = ecl_plus(v9fi,ecl_make_fixnum(1));
L33:;
   if (ecl_number_compare(v9fi,ecl_symbol_value(VV[7]))>0) { goto L38; }
   T0 = si_frs_bds(v9fi);
   if (ecl_number_compare(T0,v8bi)>=0) { goto L38; }
   goto L32;
L38:;
   T0 = si_bds_var(v8bi);
   {
    cl_object v10val;
    v10val = si_bds_val(v8bi);
    if (!((v10val)==(ecl_symbol_value(ECL_SYM("UNBOUND",2))))) { goto L44; }
    T1 = _ecl_static_31;
    goto L42;
L44:;
    T1 = v10val;
   }
L42:;
   cl_format(5, ECL_T, _ecl_static_33, v8bi, T0, T1);
   v8bi = ecl_one_plus(v8bi);
L28:;
   if (ecl_number_compare(v8bi,ecl_make_fixnum(v6))>0) { goto L48; }
   goto L27;
L48:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 0;
   ecl_bds_unwind1(cl_env_copy);
   ecl_bds_unwind1(cl_env_copy);
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
 }
}
/*	function definition for TPL-BACKTRACE                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L55tpl_backtrace(cl_narg narg, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1n;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1n = ECL_NIL;
   } else {
    i++;
    v1n = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v2;
   cl_object v3;
   cl_object v4base;
   cl_object v5top;
   v2 = ecl_symbol_value(VV[3]);
   v3 = ecl_symbol_value(VV[4]);
   ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-PRETTY*",55),ECL_NIL); /*  *PRINT-PRETTY* */
   v4base = v2;
   v5top = v3;
   cl_format(2, ECL_T, _ecl_static_34);
   if (!(v1n==ECL_NIL)) { goto L9; }
   {
    cl_object v6i;
    v6i = v5top;
    goto L14;
L13:;
    if (Null(L65ihs_visible(v6i))) { goto L16; }
    {
     cl_object v7;
     cl_object v8;
     if (!(ecl_number_equalp(v6i,ecl_symbol_value(VV[5])))) { goto L19; }
     v7 = ECL_SYM("UPCASE",1322);
     goto L18;
L19:;
     v7 = ECL_SYM("DOWNCASE",1223);
L18:;
     v8 = L66ihs_fname(v6i);
     ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-CASE*",46),v7); /*  *PRINT-CASE* */
     ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-READABLY*",57),ECL_NIL); /*  *PRINT-READABLY* */
     cl_format(3, ECL_T, _ecl_static_35, v8);
     if (!((v8)==(ECL_SYM("BYTECODES",1659)))) { goto L23; }
     T0 = si_ihs_fun(v6i);
     T1 = cl_function_lambda_expression(T0);
     cl_format(3, ECL_T, _ecl_static_36, T1);
L23:;
     T0 = ecl_terpri(ECL_NIL);
     ecl_bds_unwind1(cl_env_copy);
     ecl_bds_unwind1(cl_env_copy);
    }
L16:;
    v6i = si_ihs_prev(v6i);
L14:;
    if (ecl_number_compare(v6i,v4base)<0) { goto L27; }
    goto L13;
L27:;
    goto L8;
   }
L9:;
   if (!((ECL_T)==(v1n))) { goto L30; }
   v4base = ecl_make_fixnum(0);
   goto L29;
L30:;
   if (ECL_FIXNUMP(v1n)||ECL_BIGNUMP(v1n)) { goto L33; }
   cl_error(1, _ecl_static_37);
L33:;
   v5top = ecl_symbol_value(VV[5]);
L29:;
   {
    cl_object v7;
    cl_object v8i;
    cl_object v9j;
    if (!((ECL_T)==(v1n))) { goto L37; }
    v7 = ecl_symbol_value(VV[4]);
    goto L36;
L37:;
    v7 = v1n;
L36:;
    v8i = v5top;
    v9j = ecl_make_fixnum(0);
    goto L43;
L42:;
    if ((L65ihs_visible(v8i))!=ECL_NIL) { goto L47; }
    if (!((ECL_T)==(v1n))) { goto L45; }
    goto L46;
L47:;
L46:;
    {
     cl_object v10;
     cl_object v11;
     if (!(ecl_number_equalp(v8i,ecl_symbol_value(VV[5])))) { goto L50; }
     v10 = ECL_SYM("UPCASE",1322);
     goto L49;
L50:;
     v10 = ECL_SYM("DOWNCASE",1223);
L49:;
     v11 = L66ihs_fname(v8i);
     ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-CASE*",46),v10); /*  *PRINT-CASE* */
     ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-READABLY*",57),ECL_NIL); /*  *PRINT-READABLY* */
     T0 = L66ihs_fname(v8i);
     cl_format(3, ECL_T, _ecl_static_35, T0);
     if (!((v11)==(ECL_SYM("BYTECODES",1659)))) { goto L54; }
     T0 = si_ihs_fun(v8i);
     T1 = cl_function_lambda_expression(T0);
     cl_format(3, ECL_T, _ecl_static_36, T1);
L54:;
     T0 = ecl_terpri(ECL_NIL);
     ecl_bds_unwind1(cl_env_copy);
     ecl_bds_unwind1(cl_env_copy);
    }
L45:;
    v8i = si_ihs_prev(v8i);
    v9j = ecl_one_plus(v9j);
L43:;
    if (ecl_number_compare(v8i,v4base)<0) { goto L59; }
    if (ecl_number_compare(v9j,v7)>=0) { goto L59; }
    goto L42;
L59:;
    if (!(ecl_zerop(v8i))) { goto L8; }
    cl_format(2, ECL_T, _ecl_static_38);
   }
L8:;
   T0 = ecl_terpri(ECL_NIL);
   ecl_bds_unwind1(cl_env_copy);
  }
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  return value0;
 }
}
/*	function definition for TPL-FRS-COMMAND                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L56tpl_frs_command(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1n;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1n = ECL_NIL;
   } else {
    i++;
    v1n = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if ((v1n)!=ECL_NIL) { goto L2; }
  v1n = ecl_symbol_value(VV[4]);
L2:;
  if (ECL_FIXNUMP(v1n)||ECL_BIGNUMP(v1n)) { goto L5; }
  cl_error(1, _ecl_static_39);
L5:;
  {
   cl_object v2;
   cl_object v3i;
   cl_object v4k;
   v2 = ecl_symbol_value(VV[4]);
   v3i = v2;
   v4k = v1n;
   goto L12;
L11:;
   {
    cl_object v5j;
    value0 = si_sch_frs_base(ecl_symbol_value(VV[6]), v3i);
    if ((value0)!=ECL_NIL) { goto L17; }
    v5j = ecl_one_plus(ecl_symbol_value(VV[7]));
    goto L15;
L17:;
    v5j = value0;
    goto L15;
L15:;
    ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-LEVEL*",51),ecl_make_fixnum(2)); /*  *PRINT-LEVEL* */
    ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-LENGTH*",50),ecl_make_fixnum(4)); /*  *PRINT-LENGTH* */
    ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-PRETTY*",55),ECL_T); /*  *PRINT-PRETTY* */
    goto L21;
L20:;
    L57print_frs(v5j);
    v5j = ecl_plus(v5j,ecl_make_fixnum(1));
L21:;
    if (ecl_number_compare(v5j,ecl_symbol_value(VV[7]))>0) { goto L26; }
    T0 = si_frs_ihs(v5j);
    if (ecl_number_compare(T0,v3i)>0) { goto L26; }
    goto L20;
L26:;
    ecl_bds_unwind1(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
   }
   v3i = si_ihs_prev(v3i);
   v4k = ecl_one_minus(v4k);
L12:;
   if (ecl_number_equalp(v4k,ecl_make_fixnum(0))) { goto L32; }
   goto L11;
L32:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 0;
   return value0;
  }
 }
}
/*	function definition for PRINT-FRS                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L57print_frs(cl_object v1i)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_symbol_value(ECL_SYM("*DEBUG-IO*",30));
  T1 = si_frs_ihs(v1i);
  T2 = si_frs_bds(v1i);
  value0 = cl_format(5, T0, _ecl_static_40, v1i, T1, T2);
  return value0;
 }
}
/*	function definition for BREAK-WHERE                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L58break_where()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ecl_number_compare(ecl_symbol_value(VV[14]),ecl_make_fixnum(0))<=0)) { goto L1; }
  value0 = cl_format(3, ECL_T, _ecl_static_41, ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398)));
  return value0;
L1:;
  value0 = L59tpl_print_current();
  return value0;
 }
}
/*	function definition for TPL-PRINT-CURRENT                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L59tpl_print_current()
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v1;
   v1 = L66ihs_fname(ecl_symbol_value(VV[5]));
   ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-READABLY*",57),ECL_NIL); /*  *PRINT-READABLY* */
   cl_format(3, ECL_T, _ecl_static_42, v1);
   if (!((v1)==(ECL_SYM("BYTECODES",1659)))) {
   ecl_bds_unwind1(cl_env_copy);
    goto L1;
   }
   T0 = si_ihs_fun(ecl_symbol_value(VV[5]));
   T1 = cl_function_lambda_expression(T0);
   cl_format(3, ECL_T, _ecl_static_36, T1);
   ecl_bds_unwind1(cl_env_copy);
  }
L1:;
  cl_format(3, ECL_T, _ecl_static_43, ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398)));
  {
   cl_object v1fun;
   v1fun = si_ihs_fun(ecl_symbol_value(VV[5]));
   if (!(ECL_SYMBOLP(v1fun))) { goto L8; }
   if (Null(cl_fboundp(v1fun))) { goto L8; }
   v1fun = cl_fdefinition(v1fun);
L8:;
   {
    cl_object v3;                                 /*  FILE            */
    cl_object v4;                                 /*  POSITION        */
    value0 = si_compiled_function_file(v1fun);
    v3 = value0;
    v4 = cl_env_copy->values[1];
    if (Null(v3)) { goto L6; }
    cl_format(4, ECL_T, _ecl_static_44, v3, v4);
   }
  }
L6:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  return value0;
 }
}
/*	function definition for TPL-HIDE                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L60tpl_hide(cl_object v1fname)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((si_memq(v1fname,ecl_symbol_value(VV[15])))!=ECL_NIL) { goto L1; }
  cl_set(VV[15],CONS(v1fname,ecl_symbol_value(VV[15])));
  if ((L65ihs_visible(ecl_symbol_value(VV[5])))!=ECL_NIL) { goto L1; }
  L67set_current_ihs();
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  return value0;
 }
}
/*	function definition for TPL-UNHIDE                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L61tpl_unhide(cl_object v1fname)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_symbol_value(VV[15]);
  T1 = (ECL_SYM("EQ",333)->symbol.gfdef);
  cl_set(VV[15],cl_delete(4, v1fname, T0, ECL_SYM("TEST",1316), T1));
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  return value0;
 }
}
/*	function definition for TPL-UNHIDE-PACKAGE                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L62tpl_unhide_package(cl_object v1package)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_find_package(v1package);
  T1 = ecl_symbol_value(VV[16]);
  T2 = (ECL_SYM("EQ",333)->symbol.gfdef);
  cl_set(VV[16],cl_delete(4, T0, T1, ECL_SYM("TEST",1316), T2));
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  return value0;
 }
}
/*	function definition for TPL-UNHIDE-ALL                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L63tpl_unhide_all()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  cl_set(VV[15],ECL_NIL);
  cl_set(VV[16],ECL_NIL);
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  return value0;
 }
}
/*	function definition for TPL-HIDE-PACKAGE                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L64tpl_hide_package(cl_object v1package)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  v1package = cl_find_package(v1package);
  if ((si_memq(v1package,ecl_symbol_value(VV[16])))!=ECL_NIL) { goto L3; }
  cl_set(VV[16],CONS(v1package,ecl_symbol_value(VV[16])));
  if ((L65ihs_visible(ecl_symbol_value(VV[5])))!=ECL_NIL) { goto L3; }
  L67set_current_ihs();
L3:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  return value0;
 }
}
/*	function definition for IHS-VISIBLE                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L65ihs_visible(cl_object v1i)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2fname;
   v2fname = L66ihs_fname(v1i);
   if (!(ECL_CONSP(v2fname))) { goto L2; }
   T0 = ecl_car(v2fname);
   if (!((ECL_SYM("SETF",750))==(T0))) { goto L2; }
   v2fname = ecl_cadr(v2fname);
L2:;
   value0 = ecl_make_bool((v2fname)==(ECL_SYM("EVAL",339)));
   if ((value0)!=ECL_NIL) { goto L7; }
   value0 = ecl_make_bool((v2fname)==(ECL_SYM("BYTECODES",1659)));
   if ((value0)!=ECL_NIL) { goto L7; }
   T0 = cl_symbol_package(v2fname);
   if ((si_memq(T0,ecl_symbol_value(VV[16])))!=ECL_NIL) { goto L11; }
   if (v2fname==ECL_NIL) { goto L11; }
   T0 = si_memq(v2fname,ecl_symbol_value(VV[15]));
   value0 = Null(T0)?ECL_T:ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L11:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L7:;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for IHS-FNAME                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L66ihs_fname(cl_object v1i)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2function;
   v2function = si_ihs_fun(v1i);
   if (!(ECL_SYMBOLP(v2function))) { goto L2; }
   value0 = v2function;
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
   if (Null(cl_compiled_function_p(v2function))) { goto L4; }
   value0 = si_compiled_function_name(v2function);
   if ((value0)!=ECL_NIL) { goto L7; }
   value0 = ECL_SYM("LAMBDA",452);
   cl_env_copy->nvalues = 1;
   return value0;
L7:;
   cl_env_copy->nvalues = 1;
   return value0;
L4:;
   if (!(ECL_INSTANCEP(v2function))) { goto L9; }
   value0 = cl_slot_value(v2function, VV[102]);
   return value0;
L9:;
   value0 = VV[103];
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for SET-CURRENT-IHS                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L67set_current_ihs()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v1i;
   v1i = ecl_symbol_value(VV[5]);
   goto L5;
L4:;
   v1i = si_ihs_prev(v1i);
L5:;
   if (Null(L65ihs_visible(v1i))) { goto L13; }
   cl_set(VV[5],v1i);
   if ((ecl_symbol_value(VV[5]))!=ECL_NIL) { goto L9; }
   goto L11;
L13:;
   goto L11;
L11:;
   if (ecl_number_compare(v1i,ecl_symbol_value(VV[3]))<=0) { goto L9; }
   goto L4;
L9:;
  }
  value0 = L68set_break_env();
  return value0;
 }
}
/*	function definition for SET-BREAK-ENV                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L68set_break_env()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  cl_set(VV[2],si_ihs_env(ecl_symbol_value(VV[5])));
  value0 = ecl_symbol_value(VV[2]);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for IHS-SEARCH                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L69ihs_search(cl_narg narg, cl_object v1string, cl_object v2unrestricted, ...)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v3start;
  va_list args; va_start(args,v2unrestricted);
  {
   int i = 2;
   if (i >= narg) {
    v3start = si_ihs_top();
   } else {
    i++;
    v3start = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v4ihs;
   v4ihs = v3start;
   goto L5;
L4:;
   if ((v2unrestricted)!=ECL_NIL) { goto L10; }
   if (Null(L65ihs_visible(v4ihs))) { goto L7; }
   goto L9;
L10:;
L9:;
   T0 = cl_string(v1string);
   T1 = L66ihs_fname(v4ihs);
   T2 = ecl_symbol_name(T1);
   T3 = (ECL_SYM("CHAR-EQUAL",207)->symbol.gfdef);
   if (Null(cl_search(4, T0, T2, ECL_SYM("TEST",1316), T3))) { goto L7; }
   value0 = v4ihs;
   cl_env_copy->nvalues = 1;
   return value0;
L7:;
   v4ihs = si_ihs_prev(v4ihs);
L5:;
   if (ecl_number_compare(v4ihs,ecl_symbol_value(VV[3]))<0) { goto L15; }
   goto L4;
L15:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for TPL-BACKWARD-SEARCH                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L70tpl_backward_search(cl_object v1string)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2new_ihs;
   v2new_ihs = L69ihs_search(3, v1string, ECL_NIL, ecl_symbol_value(VV[5]));
   if (Null(v2new_ihs)) { goto L3; }
   cl_set(VV[5],v2new_ihs);
   L67set_current_ihs();
   L59tpl_print_current();
   goto L2;
L3:;
   cl_format(3, ecl_symbol_value(ECL_SYM("*DEBUG-IO*",30)), _ecl_static_45, v1string);
L2:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 0;
   return value0;
  }
 }
}
/*	function definition for TPL-FORWARD-SEARCH                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L71tpl_forward_search(cl_object v1string)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2ihs;
   v2ihs = si_ihs_next(ecl_symbol_value(VV[5]));
   goto L5;
L4:;
   if (Null(L65ihs_visible(v2ihs))) { goto L7; }
   T0 = L66ihs_fname(v2ihs);
   T1 = ecl_symbol_name(T0);
   T2 = (ECL_SYM("CHAR-EQUAL",207)->symbol.gfdef);
   if (Null(cl_search(4, v1string, T1, ECL_SYM("TEST",1316), T2))) { goto L7; }
   cl_set(VV[5],v2ihs);
   L67set_current_ihs();
   L59tpl_print_current();
   goto L1;
L7:;
   v2ihs = si_ihs_next(v2ihs);
L5:;
   if (ecl_number_compare(v2ihs,ecl_symbol_value(VV[4]))>0) { goto L17; }
   goto L4;
L17:;
   cl_format(3, ecl_symbol_value(ECL_SYM("*DEBUG-IO*",30)), _ecl_static_45, v1string);
  }
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  return value0;
 }
}
/*	function definition for TPL-APROPOS-COMMAND                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L72tpl_apropos_command(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v1string;
  cl_object v2pkg;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1string = ECL_NIL;
   } else {
    i++;
    v1string = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v2pkg = ECL_NIL;
   } else {
    i++;
    v2pkg = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (Null(v1string)) { goto L3; }
  value0 = cl_apropos(2, v1string, v2pkg);
  return value0;
L3:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for TPL-DOCUMENT-COMMAND                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L73tpl_document_command(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1symbol;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1symbol = ECL_NIL;
   } else {
    i++;
    v1symbol = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (Null(v1symbol)) { goto L2; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[195])(1, v1symbol) /*  HELP */;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for TPL-STEP-COMMAND                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L74tpl_step_command(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1form;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1form = ECL_NIL;
   } else {
    i++;
    v1form = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (Null(v1form)) { goto L2; }
  value0 = ecl_function_dispatch(cl_env_copy,VV[197])(1, v1form) /*  STEP* */;
  return value0;
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for TPL-TRACE-COMMAND                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L75tpl_trace_command(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1functions;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1functions = cl_grab_rest_args(args);
  ecl_va_end(args);
  value0 = ecl_function_dispatch(cl_env_copy,VV[199])(1, v1functions) /*  TRACE* */;
  return value0;
 }
}
/*	function definition for TPL-UNTRACE-COMMAND                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L76tpl_untrace_command(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1functions;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1functions = cl_grab_rest_args(args);
  ecl_va_end(args);
  value0 = ecl_function_dispatch(cl_env_copy,VV[201])(1, v1functions) /*  UNTRACE* */;
  return value0;
 }
}
/*	function definition for TPL-LOAD-COMMAND                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L77tpl_load_command(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1files;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1files = cl_grab_rest_args(args);
  ecl_va_end(args);
  if (Null(v1files)) { goto L1; }
  cl_set(VV[115],v1files);
L1:;
  {
   cl_object v2;
   v2 = ecl_symbol_value(VV[115]);
   goto L8;
L7:;
   {
    cl_object v3file;
    v3file = ecl_car(v2);
    cl_load(1, v3file);
   }
   v2 = ecl_cdr(v2);
L8:;
   if (Null(v2)) { goto L15; }
   goto L7;
L15:;
  }
  value0 = ecl_symbol_value(VV[115]);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for TPL-COMPILE-COMMAND                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L78tpl_compile_command(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_object v1files;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  v1files = cl_grab_rest_args(args);
  ecl_va_end(args);
  if (Null(v1files)) { goto L1; }
  cl_set(VV[117],v1files);
L1:;
  {
   cl_object v2;
   v2 = ecl_symbol_value(VV[117]);
   goto L8;
L7:;
   {
    cl_object v3file;
    v3file = ecl_car(v2);
    (cl_env_copy->function=(ECL_SYM("COMPILE-FILE",234)->symbol.gfdef))->cfun.entry(1, v3file) /*  COMPILE-FILE */;
   }
   v2 = ecl_cdr(v2);
L8:;
   if (Null(v2)) { goto L15; }
   goto L7;
L15:;
  }
  cl_set(VV[115],ecl_symbol_value(VV[117]));
  value0 = ecl_symbol_value(VV[115]);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for TPL-HELP-COMMAND                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L79tpl_help_command(cl_narg narg, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1topic;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1topic = ECL_NIL;
   } else {
    i++;
    v1topic = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (!(v1topic==ECL_NIL)) { goto L3; }
  {
   cl_object v2;
   v2 = ecl_symbol_value(VV[18]);
   goto L8;
L7:;
   {
    cl_object v3commands;
    v3commands = ecl_car(v2);
    T0 = ecl_car(v3commands);
    cl_format(3, ECL_T, _ecl_static_46, T0);
    {
     cl_object v4;
     v4 = ecl_cdr(v3commands);
     goto L17;
L16:;
     {
      cl_object v5c;
      v5c = ecl_car(v4);
      if (Null(ecl_cadddr(v5c))) { goto L21; }
      T0 = ecl_cadddr(v5c);
      cl_format(3, ECL_T, _ecl_static_47, T0);
L21:;
     }
     v4 = ecl_cdr(v4);
L17:;
     if (Null(v4)) { goto L25; }
     goto L16;
L25:;
    }
   }
   v2 = ecl_cdr(v2);
L8:;
   if (Null(v2)) { goto L29; }
   goto L7;
L29:;
   goto L2;
  }
L3:;
  if (ECL_STRINGP(v1topic)) { goto L33; }
  if (!(ECL_SYMBOLP(v1topic))) { goto L31; }
  goto L32;
L33:;
L32:;
  {
   cl_object v3c;
   v3c = ECL_NIL;
   T0 = cl_string(v1topic);
   T1 = cl_find_package(ECL_SYM("KEYWORD",449));
   v1topic = cl_intern(2, T0, T1);
   {
    cl_object v4;
    v4 = ecl_symbol_value(VV[18]);
    goto L42;
L41:;
    {
     cl_object v5commands;
     v5commands = ecl_car(v4);
     {
      cl_object v6;
      v6 = ecl_cdr(v5commands);
      goto L52;
L51:;
      {
       cl_object v7;
       cl_object v8;
       if (ecl_unlikely(ECL_ATOM(v6))) FEtype_error_cons(v6);
       v7 = v6;
       v8 = ECL_CONS_CAR(v7);
       if (Null(v8)) { goto L54; }
       {
        cl_object v9;
        if (ecl_unlikely(ECL_ATOM(v8))) FEtype_error_cons(v8);
        T0 = v8;
        v9 = ECL_CONS_CAR(T0);
        if (Null(ecl_memql(v1topic,v9))) { goto L54; }
        v3c = v8;
        goto L48;
       }
      }
L54:;
      v6 = ECL_CONS_CDR(v6);
L52:;
      if (v6==ECL_NIL) { goto L65; }
      goto L51;
L65:;
      v3c = ECL_NIL;
     }
L48:;
     if (Null(v3c)) { goto L46; }
     goto L38;
L46:;
    }
    v4 = ecl_cdr(v4);
L42:;
    if (Null(v4)) { goto L69; }
    goto L41;
L69:;
   }
L38:;
   T0 = ecl_cddddr(v3c);
   T1 = ecl_car(T0);
   if (!(T1==ECL_NIL)) { goto L71; }
   T0 = cl_string(v1topic);
   cl_format(3, ECL_T, _ecl_static_48, T0);
   goto L2;
L71:;
   ecl_terpri(ECL_NIL);
   T0 = ecl_cddddr(v3c);
   T1 = ecl_car(T0);
   cl_format(2, ECL_T, T1);
   ecl_terpri(ECL_NIL);
   goto L2;
  }
L31:;
  cl_format(3, ECL_T, _ecl_static_49, v1topic);
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  return value0;
 }
}
/*	function definition for TPL-HELP-STACK-COMMAND                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L80tpl_help_stack_command()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_format(2, ECL_T, _ecl_static_50);
  return value0;
 }
}
/*	function definition for COMPUTE-RESTART-COMMANDS              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L81compute_restart_commands(cl_narg narg, cl_object v1condition, ...)
{
 cl_object T0, T1, T2, T3, T4, T5, T6;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2display;
  ecl_va_list args; ecl_va_start(args,v1condition,narg,1);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,L81compute_restart_commandskeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v2display = keyvars[0];
  }
  {
   cl_object v3;
   cl_object v4;
   cl_object v5restart_commands;
   v3 = (cl_env_copy->function=(ECL_SYM("COMPUTE-RESTARTS",243)->symbol.gfdef))->cfun.entry(1, v1condition) /*  COMPUTE-RESTARTS */;
   v4 = ecl_list1(_ecl_static_51);
   v5restart_commands = v4;
   if (Null(v2display)) { goto L4; }
   if (Null(v3)) { goto L7; }
   T0 = _ecl_static_52;
   goto L6;
L7:;
   T0 = _ecl_static_53;
L6:;
   cl_format(2, v2display, T0);
L4:;
   {
    cl_object v6restart;
    cl_object v7;
    cl_object v8i;
    v6restart = ECL_NIL;
    v7 = v3;
    v8i = ecl_make_fixnum(1);
    if (!(ecl_endp(v7))) { goto L15; }
    goto L14;
L15:;
    v6restart = _ecl_car(v7);
L13:;
    {
     cl_object v9;
     v9 = _ecl_cdr(v7);
     if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
     v7 = v9;
    }
    {
     cl_object v9;
     cl_object v10;
     cl_object v11;
     v9 = cl_format(3, ECL_NIL, _ecl_static_54, v8i);
     T0 = (cl_env_copy->function=(ECL_SYM("RESTART-NAME",723)->symbol.gfdef))->cfun.entry(1, v6restart) /*  RESTART-NAME */;
     v10 = cl_format(3, ECL_NIL, _ecl_static_55, T0);
     v11 = cl_princ_to_string(v6restart);
     T0 = cl_string_upcase(1, v9);
     T1 = cl_intern(2, T0, VV[121]);
     T2 = ecl_list1(T1);
     T3 = cl_format(5, ECL_NIL, _ecl_static_56, v9, v11, v10);
     T4 = cl_string_downcase(1, v9);
     T5 = cl_format(6, ECL_NIL, _ecl_static_57, T4, _ecl_static_58, v10, v11);
     T6 = cl_list(5, T2, v6restart, VV[66], T3, T5);
     v5restart_commands = CONS(T6,v5restart_commands);
     if (Null(v2display)) { goto L23; }
     cl_format(5, v2display, _ecl_static_59, v8i, v10, v6restart);
    }
L23:;
    if (!(ecl_endp(v7))) { goto L30; }
    goto L14;
L30:;
    {
     cl_object v9;
     v9 = _ecl_car(v7);
     v8i = ecl_one_plus(v8i);
     v6restart = v9;
    }
    goto L13;
L14:;
   }
   if (Null(v2display)) { goto L38; }
   ecl_terpri(v2display);
L38:;
   value0 = cl_nreverse(v5restart_commands);
   return value0;
  }
 }
}
/*	function definition for UPDATE-DEBUG-COMMANDS                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L83update_debug_commands(cl_object v1restart_commands)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2commands;
   v2commands = cl_copy_list(ecl_symbol_value(VV[18]));
   if ((ecl_memql(ecl_symbol_value(VV[19]),v2commands))!=ECL_NIL) { goto L2; }
   T0 = ecl_list1(ecl_symbol_value(VV[19]));
   v2commands = ecl_nconc(v2commands,T0);
L2:;
   {cl_object v3;
    v3 = ECL_NIL;
    v3 = ecl_make_cfun((cl_objectfn_fixed)LC82__g354,ECL_NIL,Cblock,1);
    T0 = v3;
   }
   cl_delete_if(2, T0, v2commands);
   T0 = ecl_list1(v1restart_commands);
   value0 = ecl_nconc(v2commands,T0);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G354                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC82__g354(cl_object v1x)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_car(v1x);
  value0 = cl_stringE(2, _ecl_static_51, T0);
  return value0;
 }
}
/*	function definition for CHECK-DEFAULT-DEBUGGER-RUNAWAY        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L84check_default_debugger_runaway()
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(ecl_number_compare(ecl_symbol_value(VV[124]),ecl_symbol_value(VV[1]))<0)) { goto L1; }
  cl_format(3, ecl_symbol_value(ECL_SYM("*ERROR-OUTPUT*",33)), _ecl_static_60, ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398)));
  T0 = ecl_plus(ecl_symbol_value(VV[124]),ecl_make_fixnum(3));
  if (!(ecl_number_compare(T0,ecl_symbol_value(VV[1]))<0)) { goto L4; }
  si_quit(1, ecl_make_fixnum(-1));
L4:;
  value0 = ecl_function_dispatch(cl_env_copy,VV[209])(0) /*  EXIT-PROCESS */;
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for TPL-SWITCH-COMMAND                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L85tpl_switch_command(cl_narg narg, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1rank;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1rank = ECL_NIL;
   } else {
    i++;
    v1rank = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v2elect;
   v2elect = ECL_NIL;
   if (!(ECL_FIXNUMP(v1rank)||ECL_BIGNUMP(v1rank))) { goto L5; }
   {
    cl_object v3max;
    v3max = cl_list_length(ecl_symbol_value(VV[25]));
    if (!(ecl_number_compare(ecl_make_fixnum(0),v1rank)<0)) { goto L11; }
    if (ecl_number_compare(v1rank,v3max)<=0) { goto L7; }
    goto L9;
L11:;
    goto L9;
L9:;
    cl_error(1, _ecl_static_61);
   }
L7:;
   T0 = ecl_one_minus(v1rank);
   v2elect = ecl_elt(ecl_symbol_value(VV[25]),ecl_fixnum(T0));
   goto L4;
L5:;
   {
    cl_object v3;
    cl_object v4;
    v3 = ecl_symbol_value(VV[25]);
    v4 = si_make_seq_iterator(2, v3, ecl_make_fixnum(0));
L17:;
    if ((v4)!=ECL_NIL) { goto L19; }
    v2elect = ECL_NIL;
    goto L14;
L19:;
    {
     cl_object v5;
     v5 = si_seq_iterator_ref(v3, v4);
     T0 = mp_process_name(v5);
     if (!(ecl_eql(v1rank,T0))) { goto L21; }
     v2elect = v5;
     goto L14;
    }
L21:;
    v4 = si_seq_iterator_next(v3, v4);
    goto L17;
   }
L14:;
L4:;
   if (Null(v2elect)) { goto L2; }
   cl_set(VV[24],v2elect);
  }
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  return value0;
 }
}
/*	function definition for TPL-WAITING-COMMAND                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L86tpl_waiting_command()
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  cl_format(2, ECL_T, _ecl_static_62);
  {
   cl_object v1;
   cl_object v2process;
   cl_object v3;
   v1 = ecl_symbol_value(VV[25]);
   v2process = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v1))) FEtype_error_list(v1);
   v3 = v1;
   {
    cl_object v4rank;
    v4rank = ecl_make_fixnum(1);
    if (!(ecl_endp(v3))) { goto L10; }
    goto L9;
L10:;
    v2process = _ecl_car(v3);
    {
     cl_object v5;
     v5 = _ecl_cdr(v3);
     if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
     v3 = v5;
    }
L8:;
    if (!((v2process)==(ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398))))) { goto L20; }
    T0 = _ecl_static_63;
    goto L19;
L20:;
    T0 = _ecl_static_64;
L19:;
    cl_format(4, ECL_T, T0, v4rank, v2process);
    if (!(ecl_endp(v3))) { goto L22; }
    goto L9;
L22:;
    v2process = _ecl_car(v3);
    {
     cl_object v5;
     v5 = _ecl_cdr(v3);
     if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
     v3 = v5;
    }
    v4rank = ecl_one_plus(v4rank);
    goto L8;
L9:;
   }
  }
  ecl_terpri(ECL_NIL);
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  return value0;
 }
}
/*	function definition for DEFAULT-DEBUGGER                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L87default_debugger(cl_object v1condition)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   v2 = ecl_symbol_value(ECL_SYM("+IO-SYNTAX-PROGV-LIST+",1720));
   {
    cl_object v4, v5; cl_index v3;
    v4 = _ecl_car(v2);
    v5 = _ecl_cdr(v2);
    v3 = ecl_progv(cl_env_copy, v4, v5);
    ecl_bds_bind(cl_env_copy,ECL_SYM("*STANDARD-INPUT*",66),ecl_symbol_value(ECL_SYM("*DEBUG-IO*",30))); /*  *STANDARD-INPUT* */
    ecl_bds_bind(cl_env_copy,ECL_SYM("*STANDARD-OUTPUT*",67),ecl_symbol_value(ECL_SYM("*DEBUG-IO*",30))); /*  *STANDARD-OUTPUT* */
    ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-READABLY*",57),ECL_NIL); /*  *PRINT-READABLY* */
    ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-PRETTY*",55),ECL_NIL); /*  *PRINT-PRETTY* */
    ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-CIRCLE*",47),ECL_T); /*  *PRINT-CIRCLE* */
    value0 = ecl_symbol_value(VV[13]);
    if ((value0)!=ECL_NIL) { goto L6; }
    T0 = ecl_symbol_value(ECL_SYM("*READTABLE*",65));
    goto L4;
L6:;
    T0 = value0;
    goto L4;
L4:;
    ecl_bds_bind(cl_env_copy,ECL_SYM("*READTABLE*",65),T0); /*  *READTABLE* */
    T0 = cl_type_of(v1condition);
    T1 = cl_format(4, ECL_NIL, _ecl_static_65, T0, v1condition);
    ecl_bds_bind(cl_env_copy,VV[12],T1);          /*  *BREAK-MESSAGE* */
    T0 = ecl_one_plus(ecl_symbol_value(VV[1]));
    ecl_bds_bind(cl_env_copy,VV[1],T0);           /*  *BREAK-LEVEL*   */
    ecl_bds_bind(cl_env_copy,VV[2],ECL_NIL);      /*  *BREAK-ENV*     */
    L84check_default_debugger_runaway();
    cl_set(VV[24],ecl_symbol_value(ECL_SYM("*CURRENT-PROCESS*",1398)));
    if (Null(cl_listen(1, ecl_symbol_value(ECL_SYM("*DEBUG-IO*",30))))) { goto L11; }
    cl_clear_input(1, ecl_symbol_value(ECL_SYM("*DEBUG-IO*",30)));
L11:;
    cl_finish_output(0);
    cl_fresh_line(1, ecl_symbol_value(ECL_SYM("*ERROR-OUTPUT*",33)));
    ecl_terpri(ecl_symbol_value(ECL_SYM("*ERROR-OUTPUT*",33)));
    ecl_princ(ecl_symbol_value(VV[12]),ecl_symbol_value(ECL_SYM("*ERROR-OUTPUT*",33)));
L17:;
    {
     cl_object v6restart_commands;
     cl_object v7debug_commands;
     v6restart_commands = L81compute_restart_commands(3, v1condition, VV[128], ECL_T);
     v7debug_commands = L83update_debug_commands(v6restart_commands);
     L24tpl(2, VV[129], v7debug_commands);
    }
    goto L17;
   }
  }
 }
}
/*	function definition for INVOKE-DEBUGGER                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L88invoke_debugger(cl_object v1condition)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2old_hook;
   v2old_hook = ecl_symbol_value(ECL_SYM("*INVOKE-DEBUGGER-HOOK*",1755));
   if (Null(v2old_hook)) { goto L1; }
   ecl_bds_bind(cl_env_copy,ECL_SYM("*INVOKE-DEBUGGER-HOOK*",1755),ECL_NIL); /*  *INVOKE-DEBUGGER-HOOK* */
   ecl_function_dispatch(cl_env_copy,v2old_hook)(2, v1condition, v2old_hook);
   ecl_bds_unwind1(cl_env_copy);
  }
L1:;
  {
   cl_object v2old_hook;
   v2old_hook = ecl_symbol_value(ECL_SYM("*DEBUGGER-HOOK*",31));
   if (Null(v2old_hook)) { goto L4; }
   ecl_bds_bind(cl_env_copy,ECL_SYM("*DEBUGGER-HOOK*",31),ECL_NIL); /*  *DEBUGGER-HOOK* */
   ecl_function_dispatch(cl_env_copy,v2old_hook)(2, v1condition, v2old_hook);
   ecl_bds_unwind1(cl_env_copy);
  }
L4:;
  if (!(ecl_number_compare(ecl_make_fixnum(0),ecl_symbol_value(VV[14]))<=0)) { goto L8; }
  ecl_function_dispatch(cl_env_copy,VV[130])(1, v1condition) /*  DEFAULT-DEBUGGER */;
  goto L7;
L8:;
  ecl_bds_push(cl_env_copy,ECL_SYM("*INVOKE-DEBUGGER-HOOK*",1755)); /*  *INVOKE-DEBUGGER-HOOK* */
  ecl_bds_push(cl_env_copy,ECL_SYM("*DEBUGGER-HOOK*",31)); /*  *DEBUGGER-HOOK* */
  ecl_bds_push(cl_env_copy,VV[4]);                /*  *IHS-TOP*       */
  ecl_bds_push(cl_env_copy,VV[14]);               /*  *TPL-LEVEL*     */
  ecl_bds_push(cl_env_copy,VV[18]);               /*  *TPL-COMMANDS*  */
  ecl_bds_bind(cl_env_copy,ECL_SYM("+",14),ECL_NIL); /*  +            */
  ecl_bds_bind(cl_env_copy,ECL_SYM("++",15),ECL_NIL); /*  ++          */
  ecl_bds_bind(cl_env_copy,ECL_SYM("+++",16),ECL_NIL); /*  +++        */
  ecl_bds_bind(cl_env_copy,ECL_SYM("-",17),ECL_NIL); /*  -            */
  ecl_bds_bind(cl_env_copy,ECL_SYM("*",18),ECL_NIL); /*  *            */
  ecl_bds_bind(cl_env_copy,ECL_SYM("**",19),ECL_NIL); /*  **          */
  ecl_bds_bind(cl_env_copy,ECL_SYM("***",20),ECL_NIL); /*  ***        */
  ecl_bds_bind(cl_env_copy,ECL_SYM("/",21),ECL_NIL); /*  /            */
  ecl_bds_bind(cl_env_copy,ECL_SYM("//",22),ECL_NIL); /*  //          */
  ecl_bds_bind(cl_env_copy,ECL_SYM("///",23),ECL_NIL); /*  ///        */
  ecl_function_dispatch(cl_env_copy,VV[130])(1, v1condition) /*  DEFAULT-DEBUGGER */;
  ecl_bds_unwind_n(cl_env_copy,15);
L7:;
  value0 = cl_finish_output(0);
  return value0;
 }
}
/*	function definition for SAFE-EVAL                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_safe_eval(volatile cl_narg narg, cl_object volatile v1form, cl_object volatile v2env, ...)
{
 cl_object T0, T1, T2, T3;
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  volatile cl_object v3err_value_p;
  va_list args; va_start(args,v2env);
  {
   int i = 2;
   if (i >= narg) {
    env0 = ECL_NIL;
    CLV0 = env0 = CONS(ECL_NIL,env0);             /*  ERR-VALUE       */
    v3err_value_p = ECL_NIL;
   } else {
    i++;
    env0 = ECL_NIL;
    CLV0 = env0 = CONS(va_arg(args,cl_object),env0); /*  ERR-VALUE    */
    v3err_value_p = ECL_T;
   }
  }
  va_end(args);
  {
   CLV1 = env0 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env0); /*  SAFE-EVAL */
   if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV1))!=0) {
   value0 = cl_env_copy->values[0];
   ecl_frs_pop(cl_env_copy);
   return value0;
   } else {
   {
    volatile cl_object v4output;
    volatile cl_object v5ok;
    v4output = ECL_NIL;
    v5ok = ECL_NIL;
    {
     volatile bool unwinding = FALSE;
     cl_index v6=ECL_STACK_INDEX(cl_env_copy),v7;
     ecl_frame_ptr next_fr;
     if (ecl_frs_push(cl_env_copy,ECL_PROTECT_TAG)) {
       unwinding = TRUE; next_fr=cl_env_copy->nlj_fr;
     } else {
     if (Null(v3err_value_p)) { goto L5; }
     {cl_object v8;
      v8 = ECL_NIL;
      v8 = ecl_make_cclosure_va((cl_objectfn)LC89__g371,env0,Cblock);
      T0 = v8;
      goto L4;
     }
L5:;
     T0 = (VV[131]->symbol.gfdef);
L4:;
     T1 = CONS(ECL_SYM("SERIOUS-CONDITION",742),T0);
     T2 = ecl_list1(T1);
     T3 = CONS(T2,ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5)));
     ecl_bds_bind(cl_env_copy,ECL_SYM("*HANDLER-CLUSTERS*",5),T3); /*  *HANDLER-CLUSTERS* */
     v4output = si_eval_with_env(2, v1form, v2env);
     v5ok = ECL_T;
     cl_env_copy->values[0] = ECL_T;
     cl_env_copy->nvalues = 1;
     ecl_bds_unwind1(cl_env_copy);
     }
     ecl_frs_pop(cl_env_copy);
     v7=ecl_stack_push_values(cl_env_copy);
     if (Null(v5ok)) { goto L11; }
     value0 = v4output;
     cl_env_copy->nvalues = 1;
     ecl_frs_pop(cl_env_copy);
     ECL_STACK_SET_INDEX(cl_env_copy,v6);
     return value0;
L11:;
     value0 = ECL_CONS_CAR(CLV0);
     cl_env_copy->nvalues = 1;
     ecl_frs_pop(cl_env_copy);
     ECL_STACK_SET_INDEX(cl_env_copy,v6);
     return value0;
     ecl_stack_pop_values(cl_env_copy,v7);
     if (unwinding) ecl_unwind(cl_env_copy,next_fr);
     value0 = cl_env_copy->values[0];
     ecl_frs_pop(cl_env_copy);
     ECL_STACK_SET_INDEX(cl_env_copy,v6);
     return value0;
    }
   }}
  }
 }
}
/*	closure G371                                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC89__g371(cl_narg narg, cl_object v1condition, ...)
{
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  SAFE-EVAL       */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  cl_env_copy->values[0] = ECL_CONS_CAR(CLV0);
  cl_env_copy->nvalues = 1;
  cl_return_from(ECL_CONS_CAR(CLV1),ECL_NIL);
 }
 }
}

#include "clos/top.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclPKhqiz3cklOm9_d6wTOE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:LSP;TOP.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclPKhqiz3cklOm9_d6wTOE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 cl_export(1, VVtemp[0]);
 si_Xmake_special(ECL_SYM("*QUIT-TAG*",1737));
 cl_set(ECL_SYM("*QUIT-TAG*",1737),CONS(ECL_NIL,ECL_NIL));
 si_Xmake_special(VV[0]);
 cl_set(VV[0],ECL_NIL);
 si_Xmake_special(VV[1]);
 cl_set(VV[1],ecl_make_fixnum(0));
 si_Xmake_special(VV[2]);
 cl_set(VV[2],ECL_NIL);
 si_Xmake_special(VV[3]);
 cl_set(VV[3],ecl_make_fixnum(0));
 si_Xmake_special(VV[4]);
 cl_set(VV[4],si_ihs_top());
 si_Xmake_special(VV[5]);
 cl_set(VV[5],ecl_make_fixnum(0));
 si_Xmake_special(VV[6]);
 cl_set(VV[6],ecl_make_fixnum(0));
 si_Xmake_special(VV[7]);
 cl_set(VV[7],ecl_make_fixnum(0));
 si_Xmake_special(VV[8]);
 cl_set(VV[8],ECL_T);
 si_Xmake_special(VV[9]);
 cl_set(VV[9],ECL_NIL);
 si_Xmake_special(VV[10]);
 cl_set(VV[10],CONS(ECL_NIL,ECL_NIL));
 si_Xmake_special(VV[11]);
 cl_set(VV[11],ECL_NIL);
 si_Xmake_special(VV[12]);
 cl_set(VV[12],ECL_NIL);
 si_Xmake_special(VV[13]);
 cl_set(VV[13],ECL_NIL);
 si_Xmake_special(VV[14]);
 cl_set(VV[14],ecl_make_fixnum(-1));
 si_Xmake_special(ECL_SYM("*STEP-LEVEL*",1032));
 cl_set(ECL_SYM("*STEP-LEVEL*",1032),ecl_make_fixnum(0));
 si_Xmake_special(VV[15]);
 cl_set(VV[15],VVtemp[1]);
 {
  cl_object T0;
 si_Xmake_special(VV[16]);
 T0 = cl_find_package(ECL_SYM("SYSTEM",1160));
 cl_set(VV[16],ecl_list1(T0));
 }
 si_Xmake_constant(VV[17], VVtemp[2]);
 si_Xmake_special(VV[18]);
 cl_set(VV[18],ecl_symbol_value(VV[17]));
 si_Xmake_constant(VV[19], VVtemp[3]);
 si_Xmake_special(VV[20]);
 cl_set(VV[20],ECL_NIL);
 ecl_cmp_defun(VV[132]);                          /*  TOP-LEVEL       */
 si_Xmake_special(VV[22]);
 cl_set(VV[22],mp_make_lock(2, ECL_SYM("NAME",1273), _ecl_static_5));
 si_Xmake_special(VV[23]);
 cl_set(VV[23],mp_make_condition_variable());
 si_Xmake_special(VV[24]);
 cl_set(VV[24],ECL_NIL);
 si_Xmake_special(VV[25]);
 cl_set(VV[25],ECL_NIL);
 ecl_cmp_defun(VV[133]);                          /*  CANDIDATE-TO-GET-CONSOLE-P */
 ecl_cmp_defun(VV[134]);                          /*  REGISTER-IN-WAITING-LIST */
 ecl_cmp_defun(VV[135]);                          /*  DELETE-FROM-WAITING-LIST */
 ecl_cmp_defun(VV[136]);                          /*  GRAB-CONSOLE    */
 ecl_cmp_defun(VV[137]);                          /*  RELEASE-CONSOLE */
 ecl_cmp_defmacro(VV[138]);                       /*  WITH-GRABBED-CONSOLE */
 si_Xmake_special(VV[35]);
 cl_set(VV[35],ECL_NIL);
 si_Xmake_special(VV[36]);
 cl_set(VV[36],ECL_NIL);
 ecl_cmp_defun(VV[139]);                          /*  SIMPLE-TERMINAL-INTERRUPT */
 ecl_cmp_defun(VV[140]);                          /*  SHOW-PROCESS-LIST */
 ecl_cmp_defun(VV[141]);                          /*  QUERY-PROCESS   */
 si_Xmake_special(VV[40]);
 cl_set(VV[40],ECL_T);
 ecl_cmp_defun(VV[142]);                          /*  SINGLE-THREADED-TERMINAL-INTERRUPT */
 ecl_cmp_defun(VV[144]);                          /*  TERMINAL-INTERRUPT */
 ecl_cmp_defun(VV[147]);                          /*  TPL             */
 ecl_cmp_defun(VV[152]);                          /*  TPL-PROMPT      */
 ecl_cmp_defun(VV[153]);                          /*  TPL-READ        */
 si_Xmake_special(VV[61]);
 cl_set(VV[61],ECL_NIL);
 ecl_cmp_defun(VV[154]);                          /*  HARDEN-COMMAND  */
 ecl_cmp_defun(VV[155]);                          /*  TPL-MAKE-COMMAND */
 ecl_cmp_defun(VV[156]);                          /*  TPL-PARSE-FORMS */
 ecl_cmp_defun(VV[157]);                          /*  TPL-PARSE-STRINGS */
 ecl_cmp_defun(VV[158]);                          /*  TPL-PRINT       */
 ecl_cmp_defun(VV[159]);                          /*  TPL-UNKNOWN-COMMAND */
 ecl_cmp_defun(VV[160]);                          /*  TPL-POP-COMMAND */
 ecl_cmp_defun(VV[161]);                          /*  TPL-QUIT-COMMAND */
 ecl_cmp_defun(VV[162]);                          /*  TPL-PREVIOUS    */
 ecl_cmp_defun(VV[163]);                          /*  TPL-NEXT        */
 ecl_cmp_defun(VV[164]);                          /*  TPL-GO          */
 ecl_cmp_defun(VV[165]);                          /*  TPL-PRINT-MESSAGE */
 ecl_cmp_defun(VV[166]);                          /*  TPL-DISASSEMBLE-COMMAND */
 ecl_cmp_defun(VV[167]);                          /*  TPL-LAMBDA-EXPRESSION-COMMAND */
 (void)0; /* No entry created for RECONSTRUCT-BYTECODES-LAMBDA-LIST */
 (void)0; /* No entry created for LAMBDA-LIST-FROM-ANNOTATIONS */
 ecl_cmp_defun(VV[168]);                          /*  FUNCTION-LAMBDA-LIST */
 ecl_cmp_defun(VV[169]);                          /*  DECODE-ENV-ELT  */
 ecl_cmp_defun(VV[170]);                          /*  DECODE-IHS-ENV  */
 ecl_cmp_defun(VV[171]);                          /*  IHS-ENVIRONMENT */
 ecl_cmp_defun(VV[172]);                          /*  TPL-PRINT-VARIABLES */
 ecl_cmp_defun(VV[173]);                          /*  TPL-VARIABLES-COMMAND */
 ecl_cmp_defun(VV[174]);                          /*  TPL-INSPECT-COMMAND */
 ecl_cmp_defun(VV[175]);                          /*  TPL-BDS-COMMAND */
 ecl_cmp_defun(VV[176]);                          /*  TPL-BACKTRACE   */
 ecl_cmp_defun(VV[177]);                          /*  TPL-FRS-COMMAND */
 ecl_cmp_defun(VV[178]);                          /*  PRINT-FRS       */
 ecl_cmp_defun(VV[179]);                          /*  BREAK-WHERE     */
 ecl_cmp_defun(VV[180]);                          /*  TPL-PRINT-CURRENT */
 ecl_cmp_defun(VV[181]);                          /*  TPL-HIDE        */
 ecl_cmp_defun(VV[182]);                          /*  TPL-UNHIDE      */
 ecl_cmp_defun(VV[183]);                          /*  TPL-UNHIDE-PACKAGE */
 ecl_cmp_defun(VV[184]);                          /*  TPL-UNHIDE-ALL  */
 ecl_cmp_defun(VV[185]);                          /*  TPL-HIDE-PACKAGE */
 ecl_cmp_defun(VV[186]);                          /*  IHS-VISIBLE     */
 ecl_cmp_defun(VV[187]);                          /*  IHS-FNAME       */
 ecl_cmp_defun(VV[188]);                          /*  SET-CURRENT-IHS */
 ecl_cmp_defun(VV[189]);                          /*  SET-BREAK-ENV   */
 ecl_cmp_defun(VV[190]);                          /*  IHS-SEARCH      */
 ecl_cmp_defun(VV[191]);                          /*  TPL-BACKWARD-SEARCH */
 ecl_cmp_defun(VV[192]);                          /*  TPL-FORWARD-SEARCH */
 ecl_cmp_defun(VV[193]);                          /*  TPL-APROPOS-COMMAND */
 ecl_cmp_defun(VV[194]);                          /*  TPL-DOCUMENT-COMMAND */
 ecl_cmp_defun(VV[196]);                          /*  TPL-STEP-COMMAND */
 ecl_cmp_defun(VV[198]);                          /*  TPL-TRACE-COMMAND */
 ecl_cmp_defun(VV[200]);                          /*  TPL-UNTRACE-COMMAND */
 si_Xmake_special(VV[115]);
 cl_set(VV[115],ECL_NIL);
 ecl_cmp_defun(VV[202]);                          /*  TPL-LOAD-COMMAND */
 si_Xmake_special(VV[117]);
 cl_set(VV[117],ECL_NIL);
 ecl_cmp_defun(VV[203]);                          /*  TPL-COMPILE-COMMAND */
 ecl_cmp_defun(VV[204]);                          /*  TPL-HELP-COMMAND */
 ecl_cmp_defun(VV[205]);                          /*  TPL-HELP-STACK-COMMAND */
 ecl_cmp_defun(VV[206]);                          /*  COMPUTE-RESTART-COMMANDS */
 ecl_cmp_defun(VV[207]);                          /*  UPDATE-DEBUG-COMMANDS */
 si_Xmake_special(VV[124]);
 cl_set(VV[124],ecl_make_fixnum(16));
 ecl_cmp_defun(VV[208]);                          /*  CHECK-DEFAULT-DEBUGGER-RUNAWAY */
 ecl_cmp_defun(VV[210]);                          /*  TPL-SWITCH-COMMAND */
 ecl_cmp_defun(VV[211]);                          /*  TPL-WAITING-COMMAND */
 ecl_cmp_defun(VV[212]);                          /*  DEFAULT-DEBUGGER */
 ecl_cmp_defun(VV[213]);                          /*  INVOKE-DEBUGGER */
 (void)0; /* No entry created for SAFE-EVAL */
}
