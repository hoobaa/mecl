/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:LSP;CMDLINE.LSP                                   */
#include <ecl/ecl-cmp.h>
#include "lsp/cmdline.eclh"
/*	function definition for COMMAND-ARGS                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1command_args()
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v1;
   cl_object v2i;
   v1 = ecl_fixnum(si_argc());
   v2i = ecl_make_fixnum(0);
   {
    cl_object v3;
    cl_object v4;
    v3 = ecl_list1(ECL_NIL);
    v4 = v3;
L5:;
    if (!(ecl_number_compare(v2i,ecl_make_fixnum(v1))>=0)) { goto L7; }
    goto L6;
L7:;
    if (ecl_unlikely(ECL_ATOM(v4))) FEtype_error_cons(v4);
    T0 = v4;
    T1 = si_argv(v2i);
    v4 = ecl_list1(T1);
    (ECL_CONS_CDR(T0)=v4,T0);
    v2i = ecl_one_plus(v2i);
    goto L5;
L6:;
    value0 = ecl_cdr(v3);
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for COMMAND-ARG-ERROR                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2command_arg_error(cl_narg narg, cl_object v1str, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2fmt_args;
  ecl_va_list args; ecl_va_start(args,v1str,narg,1);
  v2fmt_args = cl_grab_rest_args(args);
  ecl_va_end(args);
  T0 = (ECL_SYM("FORMAT",387)->symbol.gfdef);
  cl_apply(4, T0, ecl_symbol_value(ECL_SYM("*ERROR-OUTPUT*",33)), v1str, v2fmt_args);
  ecl_princ(ecl_symbol_value(ECL_SYM("*HELP-MESSAGE*",1812)),ecl_symbol_value(ECL_SYM("*ERROR-OUTPUT*",33)));
  value0 = si_quit(1, ecl_make_fixnum(1));
  return value0;
 }
}
/*	function definition for PRODUCE-INIT-CODE                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3produce_init_code(cl_object v1option_list, cl_object v2rules)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3commands;
   cl_object v4stop;
   cl_object v5loadrc;
   v3commands = ECL_NIL;
   v4stop = ECL_NIL;
   v5loadrc = ECL_T;
   goto L6;
L5:;
   {
    cl_object v6option;
    cl_object v7rule;
    {
     cl_object v8;
     v8 = v1option_list;
     if (ecl_unlikely(!ECL_LISTP(v8))) FEtype_error_list(v8);
     if (Null(v8)) { goto L13; }
     {
      cl_object v9;
      v9 = ECL_CONS_CDR(v8);
      v1option_list = v9;
      v8 = ECL_CONS_CAR(v8);
     }
L13:;
     v6option = v8;
    }
    {
     cl_object v8;
     v8 = v2rules;
     goto L23;
L22:;
     {
      cl_object v9;
      cl_object v10;
      if (ecl_unlikely(ECL_ATOM(v8))) FEtype_error_cons(v8);
      v9 = v8;
      v10 = ECL_CONS_CAR(v9);
      if (Null(v10)) { goto L25; }
      {
       cl_object v11;
       if (ecl_unlikely(ECL_ATOM(v10))) FEtype_error_cons(v10);
       T0 = v10;
       v11 = ECL_CONS_CAR(T0);
       if (Null(cl_stringE(2, v6option, v11))) { goto L25; }
       v7rule = v10;
       goto L19;
      }
     }
L25:;
     v8 = ECL_CONS_CDR(v8);
L23:;
     if (v8==ECL_NIL) { goto L36; }
     goto L22;
L36:;
     v7rule = ECL_NIL;
    }
L19:;
    if ((v7rule)!=ECL_NIL) { goto L38; }
    {
     cl_object v8;
     v8 = v2rules;
     goto L46;
L45:;
     {
      cl_object v9;
      cl_object v10;
      if (ecl_unlikely(ECL_ATOM(v8))) FEtype_error_cons(v8);
      v9 = v8;
      v10 = ECL_CONS_CAR(v9);
      if (Null(v10)) { goto L48; }
      {
       cl_object v11;
       if (ecl_unlikely(ECL_ATOM(v10))) FEtype_error_cons(v10);
       T0 = v10;
       v11 = ECL_CONS_CAR(T0);
       if (Null(cl_stringE(2, _ecl_static_2, v11))) { goto L48; }
       v7rule = v10;
       goto L42;
      }
     }
L48:;
     v8 = ECL_CONS_CDR(v8);
L46:;
     if (v8==ECL_NIL) { goto L59; }
     goto L45;
L59:;
     v7rule = ECL_NIL;
    }
L42:;
    v4stop = ECL_T;
    if ((v7rule)!=ECL_NIL) { goto L38; }
    L2command_arg_error(2, _ecl_static_3, v6option);
L38:;
    {
     cl_object v8;
     v8 = ecl_cadddr(v7rule);
     if (!(ecl_eql(v8,VV[2]))) { goto L65; }
     v5loadrc = ECL_NIL;
     goto L63;
L65:;
     if (!(ecl_eql(v8,VV[3]))) { goto L68; }
     v5loadrc = ECL_T;
     goto L63;
L68:;
     if (!(ecl_eql(v8,VV[4]))) { goto L63; }
     T0 = CONS(v6option,v1option_list);
     T1 = cl_list(2, ECL_SYM("QUOTE",679), T0);
     v1option_list = ecl_list1(T1);
     v4stop = ECL_T;
    }
L63:;
    {
     cl_object v8;
     cl_object v9;
     T0 = ecl_caddr(v7rule);
     v8 = cl_copy_tree(T0);
     v9 = ecl_cadr(v7rule);
     if (ecl_equal(v9,ecl_make_fixnum(0))) { goto L77; }
     if (!(v1option_list==ECL_NIL)) { goto L79; }
     L2command_arg_error(2, _ecl_static_4, v6option);
L79:;
     if ((v9)==(ECL_SYM("REST",719))) { goto L83; }
     if (!((v9)==(ECL_SYM("&REST",12)))) { goto L81; }
     goto L82;
L83:;
L82:;
     cl_nsubst(3, v1option_list, v9, v8);
     v1option_list = ECL_NIL;
     goto L77;
L81:;
     {
      cl_object v10;
      v10 = v1option_list;
      if (ecl_unlikely(!ECL_LISTP(v10))) FEtype_error_list(v10);
      if (Null(v10)) { goto L91; }
      {
       cl_object v11;
       v11 = ECL_CONS_CDR(v10);
       v1option_list = v11;
       v10 = ECL_CONS_CAR(v10);
      }
L91:;
      T0 = v10;
     }
     cl_nsubst(3, T0, v9, v8);
L77:;
     v3commands = CONS(v8,v3commands);
    }
   }
L6:;
   if ((v4stop)!=ECL_NIL) { goto L98; }
   if (v1option_list==ECL_NIL) { goto L98; }
   goto L5;
L98:;
   T0 = cl_nreverse(v3commands);
   T1 = ecl_append(T0,VV[6]);
   T2 = cl_listX(3, ECL_SYM("LET",477), VV[5], T1);
   cl_env_copy->nvalues = 3;
   cl_env_copy->values[2] = v1option_list;
   cl_env_copy->values[1] = v5loadrc;
   cl_env_copy->values[0] = T2;
   return cl_env_copy->values[0];
  }
 }
}
/*	function definition for PROCESS-COMMAND-ARGS                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L9process_command_args(volatile cl_narg narg, ...)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7;
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  volatile cl_object v1args;
  volatile cl_object v2rules;
  ecl_va_list args; ecl_va_start(args,narg,narg,0);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,L9process_command_argskeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[2])) {
    v1args = ecl_cdr(ecl_symbol_value(ECL_SYM("*COMMAND-ARGS*",1816)));
   } else {
    v1args = keyvars[0];
   }
   if (Null(keyvars[3])) {
    v2rules = ecl_symbol_value(ECL_SYM("+DEFAULT-COMMAND-ARG-RULES+",1814));
   } else {
    v2rules = keyvars[1];
   }
  }
  {
   volatile cl_object v4;                         /*  COMMANDS        */
   volatile cl_object v5;                         /*  LOADRC          */
   value0 = L3produce_init_code(v1args, v2rules);
   v4 = value0;
   {
    const int v6 = cl_env_copy->nvalues;
    cl_object v7;
    v7 = (v6<=1)? ECL_NIL : cl_env_copy->values[1];
    v5 = v7;
   }
   {
    volatile cl_object env1 = env0;
    env1 = ECL_NIL;
    CLV0 = env1 = CONS(ECL_NIL,env1);
    CLV1 = env1 = CONS(ECL_NEW_FRAME_ID(cl_env_copy),env1); /*  TAGBODY */
    if (ecl_frs_push(cl_env_copy,ECL_CONS_CAR(CLV1))) {
    if (cl_env_copy->values[0]==ecl_make_fixnum(0))goto L4;
    if (cl_env_copy->values[0]==ecl_make_fixnum(1))goto L5;
    ecl_internal_error("GO found an inexistent tag");
    }
    {cl_object v6;
     v6 = ECL_NIL;
     v6 = ecl_make_cclosure_va((cl_objectfn)LC4__g39,env1,Cblock);
     T0 = v6;
    }
    {cl_object v6;
     v6 = ECL_NIL;
     v6 = ecl_make_cfun((cl_objectfn_fixed)LC5__g40,ECL_NIL,Cblock,1);
     T1 = v6;
    }
    T2 = ecl_function_dispatch(cl_env_copy,VV[15])(6, ECL_SYM("NAME",1273), ECL_SYM("CONTINUE",250), ECL_SYM("FUNCTION",1241), T0, VV[8], T1) /*  MAKE-RESTART */;
    {cl_object v6;
     v6 = ECL_NIL;
     v6 = ecl_make_cclosure_va((cl_objectfn)LC6__g41,env1,Cblock);
     T3 = v6;
    }
    {cl_object v6;
     v6 = ECL_NIL;
     v6 = ecl_make_cfun((cl_objectfn_fixed)LC7__g42,ECL_NIL,Cblock,1);
     T4 = v6;
    }
    T5 = ecl_function_dispatch(cl_env_copy,VV[15])(6, ECL_SYM("NAME",1273), ECL_SYM("ABORT",77), ECL_SYM("FUNCTION",1241), T3, VV[8], T4) /*  MAKE-RESTART */;
    T6 = cl_list(2, T2, T5);
    T7 = CONS(T6,ecl_symbol_value(ECL_SYM("*RESTART-CLUSTERS*",4)));
    ecl_bds_bind(cl_env_copy,ECL_SYM("*RESTART-CLUSTERS*",4),T7); /*  *RESTART-CLUSTERS* */
    {cl_object v6;
     v6 = ECL_NIL;
     v6 = ecl_make_cfun((cl_objectfn_fixed)LC8__g43,ECL_NIL,Cblock,1);
     T0 = v6;
    }
    T1 = CONS(ECL_SYM("ERROR",337),T0);
    T2 = ecl_list1(T1);
    T3 = CONS(T2,ecl_symbol_value(ECL_SYM("*HANDLER-CLUSTERS*",5)));
    ecl_bds_bind(cl_env_copy,ECL_SYM("*HANDLER-CLUSTERS*",5),T3); /*  *HANDLER-CLUSTERS* */
    if (Null(v5)) { goto L12; }
    {
     cl_object v6;
     v6 = ecl_symbol_value(ECL_SYM("*LISP-INIT-FILE-LIST*",1813));
     goto L17;
L16:;
     {
      cl_object v7file;
      v7file = ecl_car(v6);
      if (Null(cl_load(7, v7file, ECL_SYM("IF-DOES-NOT-EXIST",1244), ECL_NIL, ECL_SYM("SEARCH-LIST",1305), ECL_NIL, ECL_SYM("VERBOSE",1325), ECL_NIL))) { goto L21; }
      goto L12;
L21:;
     }
     v6 = ecl_cdr(v6);
L17:;
     if (Null(v6)) { goto L25; }
     goto L16;
L25:;
    }
L12:;
    value0 = cl_eval(v4);
    ecl_frs_pop(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    ecl_bds_unwind1(cl_env_copy);
    return value0;
L4:;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    ecl_frs_pop(cl_env_copy);
    return value0;
L5:;
    value0 = si_quit(2, ecl_make_fixnum(-1), ECL_NIL);
    ecl_frs_pop(cl_env_copy);
    return value0;
   }
  }
 }
}
/*	closure G39                                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC4__g39(cl_narg narg, ...)
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
/*	local function G40                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC5__g40(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_write_string(2, _ecl_static_5, v1stream);
  return value0;
 }
}
/*	closure G41                                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC6__g41(cl_narg narg, ...)
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
  cl_go(ECL_CONS_CAR(CLV1),ecl_make_fixnum(1));
 }
 }
}
/*	local function G42                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC7__g42(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_write_string(2, _ecl_static_6, v1stream);
  return value0;
 }
}
/*	local function G43                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC8__g43(cl_object v1c)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(ecl_symbol_value(VV[0]))) { goto L1; }
  value0 = (cl_env_copy->function=(ECL_SYM("INVOKE-DEBUGGER",445)->symbol.gfdef))->cfun.entry(1, v1c) /*  INVOKE-DEBUGGER */;
  return value0;
L1:;
  cl_format(3, ecl_symbol_value(ECL_SYM("*ERROR-OUTPUT*",33)), _ecl_static_7, v1c);
  value0 = si_quit(1, ecl_make_fixnum(1));
  return value0;
 }
}

#include "lsp/cmdline.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecldD4pCprV6IBm9_ZBy9ZE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:LSP;CMDLINE.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_ecldD4pCprV6IBm9_ZBy9ZE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 si_Xmake_special(VV[0]);
 cl_set(VV[0],ECL_NIL);
 si_Xmake_special(ECL_SYM("*LISP-INIT-FILE-LIST*",1813));
 cl_set(ECL_SYM("*LISP-INIT-FILE-LIST*",1813),VVtemp[0]);
 si_Xmake_special(ECL_SYM("*HELP-MESSAGE*",1812));
 cl_set(ECL_SYM("*HELP-MESSAGE*",1812),_ecl_static_1);
 ecl_cmp_defun(VV[10]);                           /*  COMMAND-ARGS    */
 si_Xmake_special(ECL_SYM("*COMMAND-ARGS*",1816));
 cl_set(ECL_SYM("*COMMAND-ARGS*",1816),L1command_args());
 si_Xmake_special(ECL_SYM("*UNPROCESSED-ECL-COMMAND-ARGS*",1818));
 cl_set(ECL_SYM("*UNPROCESSED-ECL-COMMAND-ARGS*",1818),ECL_NIL);
 (void)0; /* No entry created for COMMAND-ARG-ERROR */
 si_Xmake_constant(ECL_SYM("+DEFAULT-COMMAND-ARG-RULES+",1814), VVtemp[1]);
 ecl_cmp_defun(VV[11]);                           /*  PRODUCE-INIT-CODE */
 ecl_cmp_defun(VV[12]);                           /*  PROCESS-COMMAND-ARGS */
}
