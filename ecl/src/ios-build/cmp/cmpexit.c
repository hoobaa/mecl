/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPEXIT.LSP                                   */
#include <ecl/ecl-cmp.h>
#include "cmp/cmpexit.eclh"
/*	function definition for UNWIND-BDS                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1unwind_bds(cl_object v1bds_lcl, cl_object v2bds_bind, cl_object v3stack_frame, cl_object v4ihs_p)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  cl_fixnum v5bds_bind;
  v5bds_bind = ecl_to_fixnum(v2bds_bind);
TTL:
  {
   cl_object v6some;
   v6some = ECL_NIL;
   if (Null(v3stack_frame)) { goto L2; }
   v6some = ECL_T;
   if (!(ECL_STRINGP(v3stack_frame))) { goto L6; }
   ecl_function_dispatch(cl_env_copy,VV[28])(3, _ecl_static_1, v3stack_frame, _ecl_static_2) /*  WT-NL */;
   goto L2;
L6:;
   ecl_function_dispatch(cl_env_copy,VV[28])(3, _ecl_static_3, v3stack_frame, _ecl_static_2) /*  WT-NL */;
L2:;
   if (Null(v1bds_lcl)) { goto L8; }
   v6some = ECL_T;
   ecl_function_dispatch(cl_env_copy,VV[28])(3, _ecl_static_4, v1bds_lcl, _ecl_static_2) /*  WT-NL */;
L8:;
   if (!((v5bds_bind)<(4))) { goto L13; }
   {
    cl_fixnum v7n;
    v7n = 0;
    goto L17;
L16:;
    v6some = ECL_T;
    ecl_function_dispatch(cl_env_copy,VV[28])(1, _ecl_static_5) /*  WT-NL */;
    v7n = (v7n)+1;
L17:;
    if (!((v7n)<(v5bds_bind))) { goto L24; }
    goto L16;
L24:;
    goto L12;
   }
L13:;
   v6some = ECL_T;
   ecl_function_dispatch(cl_env_copy,VV[28])(3, _ecl_static_6, ecl_make_fixnum(v5bds_bind), _ecl_static_2) /*  WT-NL */;
L12:;
   if (!((v4ihs_p)==(VV[0]))) { goto L29; }
   v6some = ECL_T;
   ecl_function_dispatch(cl_env_copy,VV[28])(1, _ecl_static_7) /*  WT-NL */;
   goto L28;
L29:;
   if (!((v4ihs_p)==(VV[1]))) { goto L28; }
   v6some = ECL_T;
   ecl_function_dispatch(cl_env_copy,VV[28])(1, _ecl_static_8) /*  WT-NL */;
L28:;
   value0 = v6some;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for UNWIND-EXIT                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2unwind_exit(cl_narg narg, cl_object v1loc, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2jump_p;
  va_list args; va_start(args,v1loc);
  {
   int i = 1;
   if (i >= narg) {
    v2jump_p = ECL_NIL;
   } else {
    i++;
    v2jump_p = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v3bds_lcl;
   cl_fixnum v4bds_bind;
   cl_object v5stack_frame;
   cl_object v6ihs_p;
   v3bds_lcl = ECL_NIL;
   v4bds_bind = 0;
   v5stack_frame = ECL_NIL;
   v6ihs_p = ECL_NIL;
   if (!(ECL_CONSP(ecl_symbol_value(VV[3])))) { goto L6; }
   {
    cl_object v7;
    v7 = ecl_car(ecl_symbol_value(VV[3]));
    if (!((v7)==(VV[4]))) { goto L9; }
    T0 = ecl_cadr(ecl_symbol_value(VV[3]));
    ecl_function_dispatch(cl_env_copy,VV[30])(2, v1loc, T0) /*  SET-JUMP-TRUE */;
    if (!((v1loc)==(ECL_T))) { goto L6; }
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
L9:;
    if (!((v7)==(VV[5]))) { goto L6; }
    T0 = ecl_cadr(ecl_symbol_value(VV[3]));
    ecl_function_dispatch(cl_env_copy,VV[31])(2, v1loc, T0) /*  SET-JUMP-FALSE */;
    if (!((v1loc)==(ECL_NIL))) { goto L6; }
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L6:;
   {
    cl_object v7;
    v7 = ecl_symbol_value(VV[6]);
    goto L19;
L18:;
    {
     cl_object v8ue;
     v8ue = ecl_car(v7);
     if (!(ECL_CONSP(v8ue))) { goto L24; }
     T0 = ecl_car(v8ue);
     if (!((T0)==(VV[7]))) { goto L26; }
     v5stack_frame = ecl_cadr(v8ue);
     goto L23;
L26:;
     T0 = ecl_car(v8ue);
     if (!((T0)==(VV[8]))) { goto L29; }
     v3bds_lcl = v8ue;
     v4bds_bind = 0;
     goto L23;
L29:;
     if (!((v8ue)==(ecl_symbol_value(VV[9])))) { goto L34; }
     if (!(ECL_CONSP(ecl_symbol_value(VV[3])))) { goto L37; }
     T0 = ecl_car(ecl_symbol_value(VV[3]));
     if ((T0)==(VV[4])) { goto L40; }
     T0 = ecl_car(ecl_symbol_value(VV[3]));
     if (!((T0)==(VV[5]))) { goto L37; }
     goto L38;
L40:;
L38:;
     L1unwind_bds(v3bds_lcl, ecl_make_fixnum(v4bds_bind), v5stack_frame, v6ihs_p);
     goto L36;
L37:;
     if ((v3bds_lcl)!=ECL_NIL) { goto L42; }
     if ((v4bds_bind)>0) { goto L42; }
     if ((v5stack_frame)!=ECL_NIL) { goto L42; }
     ecl_function_dispatch(cl_env_copy,VV[32])(1, v1loc) /*  SET-LOC  */;
     goto L36;
L42:;
     if ((ecl_function_dispatch(cl_env_copy,VV[33])(1, v1loc) /*  LOC-REFERS-TO-SPECIAL */)!=ECL_NIL) { goto L48; }
     if (Null(ecl_function_dispatch(cl_env_copy,VV[33])(1, ecl_symbol_value(VV[3])) /*  LOC-REFERS-TO-SPECIAL */)) { goto L46; }
     goto L47;
L48:;
L47:;
     {
      cl_object v9temp;
      ecl_bds_push(cl_env_copy,VV[10]);           /*  *TEMP*          */
      v9temp = ecl_function_dispatch(cl_env_copy,VV[34])(0) /*  MAKE-TEMP-VAR */;
      ecl_bds_bind(cl_env_copy,VV[3],v9temp);     /*  *DESTINATION*   */
      ecl_function_dispatch(cl_env_copy,VV[32])(1, v1loc) /*  SET-LOC */;
      ecl_bds_unwind1(cl_env_copy);
      L1unwind_bds(v3bds_lcl, ecl_make_fixnum(v4bds_bind), v5stack_frame, v6ihs_p);
      ecl_function_dispatch(cl_env_copy,VV[32])(1, v9temp) /*  SET-LOC */;
      ecl_bds_unwind1(cl_env_copy);
      goto L36;
     }
L46:;
     ecl_function_dispatch(cl_env_copy,VV[32])(1, v1loc) /*  SET-LOC  */;
     L1unwind_bds(v3bds_lcl, ecl_make_fixnum(v4bds_bind), v5stack_frame, v6ihs_p);
L36:;
     if (Null(v2jump_p)) { goto L54; }
     ecl_function_dispatch(cl_env_copy,VV[28])(0) /*  WT-NL           */;
     ecl_function_dispatch(cl_env_copy,VV[35])(1, ecl_symbol_value(VV[9])) /*  WT-GO */;
L54:;
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 1;
     return value0;
L34:;
     v2jump_p = ECL_T;
     goto L23;
L24:;
     if (!(ecl_numberp(v8ue))) { goto L58; }
     L4baboon_unwind_exit(v8ue);
     v3bds_lcl = v8ue;
     v4bds_bind = 0;
     goto L23;
L58:;
     if (!((v8ue)==(VV[0]))) { goto L64; }
     v6ihs_p = v8ue;
     goto L23;
L64:;
     if (!((v8ue)==(VV[1]))) { goto L67; }
     value0 = v6ihs_p;
     if ((value0)!=ECL_NIL) { goto L71; }
     v6ihs_p = v8ue;
     goto L69;
L71:;
     v6ihs_p = value0;
     goto L69;
L69:;
     goto L23;
L67:;
     if (!((v8ue)==(VV[11]))) { goto L73; }
     {
      cl_object v9;
      v9 = ecl_plus(ecl_make_fixnum(v4bds_bind),ecl_make_fixnum(1));
      {
       bool v10;
       v10 = ECL_FIXNUMP(v9);
       if (ecl_unlikely(!(v10)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v9);
      }
      v4bds_bind = ecl_fixnum(v9);
     }
     goto L23;
L73:;
     if (!((v8ue)==(ECL_SYM("RETURN",724)))) { goto L78; }
     if ((ecl_symbol_value(VV[9]))==(ECL_SYM("RETURN",724))) { goto L80; }
     L4baboon_unwind_exit(v8ue);
L80:;
     if (!((v1loc)==(ECL_SYM("VALUES",895)))) { goto L83; }
     L1unwind_bds(v3bds_lcl, ecl_make_fixnum(v4bds_bind), v5stack_frame, v6ihs_p);
     ecl_function_dispatch(cl_env_copy,VV[28])(1, _ecl_static_9) /*  WT-NL */;
     goto L82;
L83:;
     if (!((v1loc)==(ECL_SYM("RETURN",724)))) { goto L86; }
     L1unwind_bds(v3bds_lcl, ecl_make_fixnum(v4bds_bind), v5stack_frame, v6ihs_p);
     ecl_function_dispatch(cl_env_copy,VV[28])(1, _ecl_static_10) /*  WT-NL */;
     goto L82;
L86:;
     ecl_bds_bind(cl_env_copy,VV[3],ECL_SYM("RETURN",724)); /*  *DESTINATION* */
     ecl_function_dispatch(cl_env_copy,VV[32])(1, v1loc) /*  SET-LOC  */;
     ecl_bds_unwind1(cl_env_copy);
     L1unwind_bds(v3bds_lcl, ecl_make_fixnum(v4bds_bind), v5stack_frame, v6ihs_p);
     ecl_function_dispatch(cl_env_copy,VV[28])(1, _ecl_static_10) /*  WT-NL */;
L82:;
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 1;
     return value0;
L78:;
     if (Null(ecl_memql(v8ue,VV[12]))) { goto L91; }
     if (!((ecl_symbol_value(VV[9]))==(v8ue))) { goto L23; }
     T0 = cl_getf(2, VV[14], v8ue);
     v1loc = cl_list(3, VV[13], T0, v1loc);
     if ((v3bds_lcl)!=ECL_NIL) { goto L99; }
     if (!((v4bds_bind)>0)) { goto L97; }
     goto L98;
L99:;
L98:;
     {
      cl_object v9lcl;
      T0 = ecl_cadr(v1loc);
      v9lcl = ecl_function_dispatch(cl_env_copy,VV[36])(2, ECL_SYM("TYPE",1318), T0) /*  MAKE-LCL-VAR */;
      ecl_function_dispatch(cl_env_copy,VV[37])(0) /*  WT-NL-OPEN-BRACE */;
      ecl_function_dispatch(cl_env_copy,VV[28])(5, _ecl_static_11, v9lcl, _ecl_static_12, v1loc, _ecl_static_13) /*  WT-NL */;
      L1unwind_bds(v3bds_lcl, ecl_make_fixnum(v4bds_bind), v5stack_frame, v6ihs_p);
      ecl_function_dispatch(cl_env_copy,VV[28])(3, _ecl_static_14, v9lcl, _ecl_static_2) /*  WT-NL */;
      ecl_function_dispatch(cl_env_copy,VV[38])(0) /*  WT-NL-CLOSE-BRACE */;
      goto L96;
     }
L97:;
     ecl_function_dispatch(cl_env_copy,VV[28])(3, _ecl_static_14, v1loc, _ecl_static_2) /*  WT-NL */;
L96:;
     value0 = ECL_NIL;
     cl_env_copy->nvalues = 1;
     return value0;
L91:;
     if (!((v8ue)==(VV[15]))) { goto L106; }
     T0 = ecl_function_dispatch(cl_env_copy,VV[39])(1, ecl_symbol_value(VV[3])) /*  TMP-DESTINATION */;
     ecl_bds_bind(cl_env_copy,VV[3],T0);          /*  *DESTINATION*   */
     ecl_function_dispatch(cl_env_copy,VV[32])(1, v1loc) /*  SET-LOC  */;
     v1loc = ecl_symbol_value(VV[3]);
     ecl_bds_unwind1(cl_env_copy);
     ecl_function_dispatch(cl_env_copy,VV[28])(1, _ecl_static_15) /*  WT-NL */;
     goto L23;
L106:;
     if ((v8ue)==(VV[16])) { goto L23; }
     if (!((v8ue)==(VV[17]))) { goto L112; }
     v2jump_p = ECL_T;
     goto L23;
L112:;
     L4baboon_unwind_exit(v8ue);
L23:;
    }
    v7 = ecl_cdr(v7);
L19:;
    if (Null(v7)) { goto L117; }
    goto L18;
L117:;
    value0 = L3baboon_improper__exit_();
    return value0;
   }
  }
 }
}
/*	function definition for BABOON-IMPROPER-*EXIT*                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3baboon_improper__exit_()
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, ecl_symbol_value(VV[9]), ecl_symbol_value(VV[6]));
  value0 = ecl_function_dispatch(cl_env_copy,VV[41])(4, ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_16, ECL_SYM("FORMAT-ARGUMENTS",1239), T0) /*  BABOON */;
  return value0;
 }
}
/*	function definition for BABOON-UNWIND-EXIT                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4baboon_unwind_exit(cl_object v1ue)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_list(2, v1ue, ecl_symbol_value(VV[6]));
  value0 = ecl_function_dispatch(cl_env_copy,VV[41])(4, ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_17, ECL_SYM("FORMAT-ARGUMENTS",1239), T0) /*  BABOON */;
  return value0;
 }
}
/*	function definition for UNWIND-NO-EXIT-UNTIL                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5unwind_no_exit_until(cl_object v1last_cons)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2bds_lcl;
   v2bds_lcl = ECL_NIL;
   {
    cl_object v3bds_bind;
    v3bds_bind = ecl_make_fixnum(0);
    {
     cl_object v4stack_frame;
     v4stack_frame = ECL_NIL;
     {
      cl_object v5ihs_p;
      v5ihs_p = ECL_NIL;
      {
       cl_object v6unwind_exit;
       v6unwind_exit = ecl_symbol_value(VV[6]);
       {
        cl_object v7ue;
        v7ue = ECL_NIL;
L7:;
        if (!(ECL_ATOM(v6unwind_exit))) { goto L9; }
        goto L8;
L9:;
        v7ue = ecl_car(v6unwind_exit);
        if (!((v6unwind_exit)==(v1last_cons))) { goto L13; }
        goto L8;
L13:;
        if (!(ECL_CONSP(v7ue))) { goto L16; }
        T0 = ecl_car(v7ue);
        if (!((T0)==(VV[7]))) { goto L15; }
        v4stack_frame = ecl_cadr(v7ue);
        goto L15;
L16:;
        if (!(ecl_numberp(v7ue))) { goto L20; }
        v2bds_lcl = v7ue;
        v3bds_bind = ecl_make_fixnum(0);
        goto L15;
L20:;
        if (!((v7ue)==(VV[11]))) { goto L25; }
        v3bds_bind = ecl_plus(v3bds_bind,ecl_make_fixnum(1));
        goto L15;
L25:;
        if (!((v7ue)==(VV[15]))) { goto L28; }
        ecl_function_dispatch(cl_env_copy,VV[28])(1, _ecl_static_15) /*  WT-NL */;
        goto L15;
L28:;
        {
         cl_object v8;
         v8 = ecl_make_bool((v7ue)==(VV[17]));
         if (Null(v8)) { goto L31; }
         goto L15;
L31:;
         if (!((v7ue)==(VV[1]))) { goto L33; }
         v5ihs_p = v7ue;
         goto L15;
L33:;
         L4baboon_unwind_exit(v7ue);
        }
L15:;
        v6unwind_exit = _ecl_cdr(v6unwind_exit);
        goto L7;
L8:;
        value0 = L1unwind_bds(v2bds_lcl, v3bds_bind, v4stack_frame, v5ihs_p);
        return value0;
       }
      }
     }
    }
   }
  }
 }
}
/*	function definition for UNWIND-NO-EXIT                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6unwind_no_exit(cl_object v1exit)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2where;
   v2where = si_memq(v1exit,ecl_symbol_value(VV[6]));
   if ((v2where)!=ECL_NIL) { goto L2; }
   T0 = ecl_list1(v1exit);
   ecl_function_dispatch(cl_env_copy,VV[41])(4, ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_18, ECL_SYM("FORMAT-ARGUMENTS",1239), T0) /*  BABOON */;
L2:;
   value0 = L5unwind_no_exit_until(v2where);
   return value0;
  }
 }
}
/*	function definition for TAIL-RECURSION-POSSIBLE               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7tail_recursion_possible()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v1;
   v1 = ecl_symbol_value(VV[6]);
   goto L4;
L3:;
   {
    cl_object v2ue;
    v2ue = ecl_car(v1);
    if (!((v2ue)==(VV[16]))) { goto L9; }
    value0 = ECL_T;
    cl_env_copy->nvalues = 1;
    return value0;
L9:;
    if (ecl_numberp(v2ue)) { goto L13; }
    if ((v2ue)==(VV[11])) { goto L13; }
    if (!((v2ue)==(VV[15]))) { goto L11; }
    goto L12;
L13:;
L12:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
L11:;
    {
     cl_object v3;
     value0 = ecl_make_bool(ECL_CONSP(v2ue));
     if ((value0)!=ECL_NIL) { goto L18; }
     value0 = ecl_make_bool((v2ue)==(VV[17]));
     if ((value0)!=ECL_NIL) { goto L18; }
     v3 = ecl_make_bool((v2ue)==(VV[1]));
     goto L16;
L18:;
     v3 = value0;
     goto L16;
L16:;
     if (Null(v3)) { goto L21; }
     goto L8;
L21:;
     ecl_function_dispatch(cl_env_copy,VV[41])(0) /*  BABOON          */;
    }
L8:;
   }
   v1 = ecl_cdr(v1);
L4:;
   if (Null(v1)) { goto L25; }
   goto L3;
L25:;
   value0 = ecl_function_dispatch(cl_env_copy,VV[41])(0) /*  BABOON   */;
   return value0;
  }
 }
}
/*	function definition for C2TRY-TAIL-RECURSIVE-CALL             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8c2try_tail_recursive_call(cl_object v1fun, cl_object v2args)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_symbol_value(VV[24]))) { goto L1; }
  T0 = ecl_car(ecl_symbol_value(VV[24]));
  if (!((v1fun)==(T0))) { goto L1; }
  if (Null(ecl_function_dispatch(cl_env_copy,VV[47])(0) /*  LAST-CALL-P */)) { goto L1; }
  if (Null(L7tail_recursion_possible())) { goto L1; }
  T0 = ecl_function_dispatch(cl_env_copy,VV[48])(1, v1fun) /*  FUN-NAME */;
  if (Null(ecl_function_dispatch(cl_env_copy,VV[49])(1, T0) /*  INLINE-POSSIBLE */)) { goto L1; }
  {
   cl_fixnum v3;
   v3 = ecl_length(v2args);
   T0 = ecl_cdr(ecl_symbol_value(VV[24]));
   {
    cl_fixnum v4;
    v4 = ecl_length(T0);
    if (!((v3)==(v4))) { goto L1; }
   }
  }
  ecl_bds_bind(cl_env_copy,VV[3],VV[25]);         /*  *DESTINATION*   */
  T0 = ecl_function_dispatch(cl_env_copy,VV[50])(0) /*  NEXT-LABEL    */;
  ecl_bds_bind(cl_env_copy,VV[9],T0);             /*  *EXIT*          */
  T0 = CONS(ecl_symbol_value(VV[9]),ecl_symbol_value(VV[6]));
  ecl_bds_bind(cl_env_copy,VV[6],T0);             /*  *UNWIND-EXIT*   */
  T0 = ecl_cdr(ecl_symbol_value(VV[24]));
  ecl_function_dispatch(cl_env_copy,VV[51])(3, ECL_NIL, T0, v2args) /*  C2PSETQ */;
  ecl_function_dispatch(cl_env_copy,VV[52])(1, ecl_symbol_value(VV[9])) /*  WT-LABEL */;
  ecl_bds_unwind1(cl_env_copy);
  ecl_bds_unwind1(cl_env_copy);
  ecl_bds_unwind1(cl_env_copy);
  L6unwind_no_exit(VV[16]);
  ecl_function_dispatch(cl_env_copy,VV[28])(1, _ecl_static_19) /*  WT-NL */;
  T0 = ecl_function_dispatch(cl_env_copy,VV[48])(1, v1fun) /*  FUN-NAME */;
  ecl_function_dispatch(cl_env_copy,VV[53])(2, _ecl_static_20, T0) /*  CMPDEBUG */;
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}

#include "cmp/cmpexit.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclyHQHRTZAt9Pi9_gQyTOE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPEXIT.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclyHQHRTZAt9Pi9_gQyTOE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[27]);                           /*  UNWIND-BDS      */
 ecl_cmp_defun(VV[29]);                           /*  UNWIND-EXIT     */
 ecl_cmp_defun(VV[40]);                           /*  BABOON-IMPROPER-*EXIT* */
 ecl_cmp_defun(VV[42]);                           /*  BABOON-UNWIND-EXIT */
 ecl_cmp_defun(VV[43]);                           /*  UNWIND-NO-EXIT-UNTIL */
 ecl_cmp_defun(VV[44]);                           /*  UNWIND-NO-EXIT  */
 ecl_cmp_defun(VV[45]);                           /*  TAIL-RECURSION-POSSIBLE */
 ecl_cmp_defun(VV[46]);                           /*  C2TRY-TAIL-RECURSIVE-CALL */
}
