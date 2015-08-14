/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:LSP;TRACE.LSP                                     */
#include <ecl/ecl-cmp.h>
#include "lsp/trace.eclh"
/*	local function TRACE                                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC1trace(cl_object v1, cl_object v2)
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
   T0 = cl_list(2, ECL_SYM("QUOTE",679), v3);
   value0 = cl_list(2, VV[2], T0);
   return value0;
  }
 }
}
/*	function definition for TRACE*                                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2trace_(cl_object v1r)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(v1r==ECL_NIL)) { goto L1; }
  {
   cl_object v2;
   cl_object v3;
   cl_object v4;
   v2 = ecl_symbol_value(ECL_SYM("*TRACE-LIST*",1832));
   v3 = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v2))) FEtype_error_list(v2);
   v4 = v2;
   {
    cl_object v5;
    cl_object v6;
    v5 = ecl_list1(ECL_NIL);
    v6 = v5;
L9:;
    if (!(ecl_endp(v4))) { goto L11; }
    goto L10;
L11:;
    v3 = _ecl_car(v4);
    {
     cl_object v7;
     v7 = _ecl_cdr(v4);
     if (ecl_unlikely(!ECL_LISTP(v7))) FEtype_error_list(v7);
     v4 = v7;
    }
    if (ecl_unlikely(ECL_ATOM(v6))) FEtype_error_cons(v6);
    T0 = v6;
    T1 = ecl_car(v3);
    v6 = ecl_list1(T1);
    (ECL_CONS_CDR(T0)=v6,T0);
    goto L9;
L10:;
    value0 = ecl_cdr(v5);
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
L1:;
  {
   cl_object v7;
   cl_object v8;
   v7 = ECL_NIL;
   if (ecl_unlikely(!ECL_LISTP(v1r))) FEtype_error_list(v1r);
   v8 = v1r;
L28:;
   if (!(ecl_endp(v8))) { goto L30; }
   goto L29;
L30:;
   v7 = _ecl_car(v8);
   {
    cl_object v9;
    v9 = _ecl_cdr(v8);
    if (ecl_unlikely(!ECL_LISTP(v9))) FEtype_error_list(v9);
    v8 = v9;
   }
   L5trace_one(v7);
   goto L28;
L29:;
   value0 = v1r;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function UNTRACE                                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC3untrace(cl_object v1, cl_object v2)
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
   T0 = cl_list(2, ECL_SYM("QUOTE",679), v3);
   value0 = cl_list(2, VV[5], T0);
   return value0;
  }
 }
}
/*	function definition for UNTRACE*                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L4untrace_(cl_object v1r)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   value0 = v1r;
   if ((value0)!=ECL_NIL) { goto L3; }
   v2 = L2trace_(ECL_NIL);
   goto L1;
L3:;
   v2 = value0;
   goto L1;
L1:;
   {
    cl_object v3;
    cl_object v4;
    v3 = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v2))) FEtype_error_list(v2);
    v4 = v2;
L8:;
    if (!(ecl_endp(v4))) { goto L10; }
    goto L9;
L10:;
    v3 = _ecl_car(v4);
    {
     cl_object v5;
     v5 = _ecl_cdr(v4);
     if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
     v4 = v5;
    }
    L14untrace_one(v3);
    goto L8;
L9:;
    value0 = v2;
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for TRACE-ONE                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5trace_one(cl_object v1spec)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2break;
   cl_object v3exitbreak;
   cl_object v4entrycond;
   cl_object v5exitcond;
   cl_object v6entry;
   cl_object v7exit;
   cl_object v8step;
   cl_object v9barfp;
   cl_object v10fname;
   cl_object v11oldf;
   v2break = ECL_NIL;
   v3exitbreak = ECL_NIL;
   v4entrycond = ECL_T;
   v5exitcond = ECL_T;
   v6entry = ECL_NIL;
   v7exit = ECL_NIL;
   v8step = ECL_NIL;
   v9barfp = ECL_T;
   v10fname = ECL_NIL;
   v11oldf = ECL_NIL;
   if (Null(si_valid_function_name_p(v1spec))) { goto L12; }
   v10fname = v1spec;
   goto L11;
L12:;
   if (Null(si_proper_list_p(v1spec))) { goto L15; }
   cl_error(2, _ecl_static_1, v1spec);
   goto L11;
L15:;
   T0 = ecl_car(v1spec);
   if (Null(si_valid_function_name_p(T0))) { goto L17; }
   v10fname = ecl_car(v1spec);
   {
    cl_object v12specs;
    v12specs = ecl_cdr(v1spec);
    goto L24;
L23:;
    {
     cl_object v13;
     v13 = ecl_car(v12specs);
     if (!(ecl_eql(v13,VV[9]))) { goto L28; }
     v9barfp = v12specs;
     v12specs = ecl_cdr(v12specs);
     v2break = ecl_car(v12specs);
     goto L26;
L28:;
     if (!(ecl_eql(v13,VV[10]))) { goto L35; }
     v9barfp = v12specs;
     v12specs = ecl_cdr(v12specs);
     v3exitbreak = ecl_car(v12specs);
     goto L26;
L35:;
     if (!(ecl_eql(v13,VV[11]))) { goto L42; }
     v8step = ECL_T;
     goto L26;
L42:;
     if (!(ecl_eql(v13,VV[12]))) { goto L45; }
     v9barfp = v12specs;
     v12specs = ecl_cdr(v12specs);
     v4entrycond = ecl_car(v12specs);
     v5exitcond = v4entrycond;
     goto L26;
L45:;
     if (!(ecl_eql(v13,VV[13]))) { goto L53; }
     v9barfp = v12specs;
     v12specs = ecl_cdr(v12specs);
     v4entrycond = ecl_car(v12specs);
     goto L26;
L53:;
     if (!(ecl_eql(v13,VV[14]))) { goto L60; }
     v9barfp = v12specs;
     v12specs = ecl_cdr(v12specs);
     v5exitcond = ecl_car(v12specs);
     goto L26;
L60:;
     if (!(ecl_eql(v13,ECL_SYM("PRINT",1290)))) { goto L67; }
     v9barfp = v12specs;
     v12specs = ecl_cdr(v12specs);
     v6entry = ecl_car(v12specs);
     goto L26;
L67:;
     if (!(ecl_eql(v13,VV[15]))) { goto L74; }
     v9barfp = v12specs;
     v12specs = ecl_cdr(v12specs);
     v7exit = ecl_car(v12specs);
     goto L26;
L74:;
     T0 = ecl_car(v12specs);
     cl_error(2, _ecl_static_2, T0);
    }
L26:;
    if ((v9barfp)!=ECL_NIL) { goto L81; }
    cl_error(1, _ecl_static_3);
L81:;
    v12specs = ecl_cdr(v12specs);
L24:;
    if (v12specs==ECL_NIL) { goto L85; }
    goto L23;
L85:;
    goto L11;
   }
L17:;
   T0 = ecl_car(v1spec);
   if (Null(si_proper_list_p(T0))) { goto L87; }
   {
    cl_object v13results;
    v13results = ECL_NIL;
    {
     cl_object v14;
     v14 = ecl_car(v1spec);
     goto L94;
L93:;
     {
      cl_object v15fname;
      v15fname = ecl_car(v14);
      T0 = ecl_cdr(v1spec);
      T1 = CONS(v15fname,T0);
      T2 = L5trace_one(T1);
      v13results = CONS(T2,v13results);
     }
     v14 = ecl_cdr(v14);
L94:;
     if (Null(v14)) { goto L102; }
     goto L93;
L102:;
    }
    value0 = cl_nreverse(v13results);
    return value0;
   }
L87:;
   cl_error(2, _ecl_static_1, v1spec);
L11:;
   T0 = cl_fboundp(v10fname);
   if (!(T0==ECL_NIL)) { goto L104; }
   (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(2, _ecl_static_4, v10fname) /*  WARN */;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L104:;
   if (!(ECL_SYMBOLP(v10fname))) { goto L107; }
   if (Null(cl_special_operator_p(v10fname))) { goto L109; }
   (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(2, _ecl_static_5, v10fname) /*  WARN */;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L109:;
   if (Null(cl_macro_function(1, v10fname))) { goto L107; }
   (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(2, _ecl_static_6, v10fname) /*  WARN */;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L107:;
   {
    cl_object v12record;
    v12record = L7trace_record(v10fname);
    if (Null(v12record)) { goto L114; }
    if (Null(L13traced_and_redefined_p(v12record))) { goto L117; }
    L11delete_from_trace_list(v10fname);
    goto L114;
L117:;
    (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(2, _ecl_static_7, v10fname) /*  WARN */;
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L114:;
   v11oldf = cl_fdefinition(v10fname);
   T0 = cl_list(2, ECL_SYM("QUOTE",679), v11oldf);
   T1 = cl_list(3, ECL_SYM("APPLY",89), T0, VV[18]);
   T2 = cl_list(2, ECL_SYM("MULTIPLE-VALUE-LIST",574), T1);
   T3 = cl_list(3, ECL_SYM("SETQ",751), ECL_SYM("VALUES",895), T2);
   if (Null(v4entrycond)) { goto L124; }
   if (!((ECL_T)==(v4entrycond))) { goto L126; }
   T5 = cl_list(2, ECL_SYM("QUOTE",679), v10fname);
   T6 = cl_listX(5, VV[20], VV[21], T5, VV[18], v6entry);
   T4 = ecl_list1(T6);
   goto L123;
L126:;
   T5 = cl_list(2, ECL_SYM("QUOTE",679), v10fname);
   T6 = cl_listX(5, VV[20], VV[21], T5, VV[18], v6entry);
   T7 = cl_list(3, ECL_SYM("WHEN",905), v4entrycond, T6);
   T4 = ecl_list1(T7);
   goto L123;
L124:;
   T4 = ECL_NIL;
L123:;
   if (Null(v2break)) { goto L129; }
   T6 = cl_list(2, ECL_SYM("QUOTE",679), v10fname);
   T7 = cl_list(3, ECL_SYM("BREAK",158), _ecl_static_8, T6);
   T8 = cl_list(3, ECL_SYM("LET",477), VV[22], T7);
   T9 = cl_list(3, ECL_SYM("WHEN",905), v2break, T8);
   T5 = ecl_list1(T9);
   goto L128;
L129:;
   T5 = ECL_NIL;
L128:;
   T6 = cl_list(2, ECL_SYM("QUOTE",679), v11oldf);
   T7 = cl_list(3, ECL_SYM("APPLY",89), T6, VV[18]);
   T8 = cl_list(2, ECL_SYM("MULTIPLE-VALUE-LIST",574), T7);
   T9 = cl_list(3, ECL_SYM("LET",477), VV[22], T8);
   T10 = cl_list(3, ECL_SYM("SETQ",751), ECL_SYM("VALUES",895), T9);
   if (Null(v5exitcond)) { goto L132; }
   if (!((ECL_T)==(v5exitcond))) { goto L134; }
   T12 = cl_list(2, ECL_SYM("QUOTE",679), v10fname);
   T13 = cl_listX(5, VV[20], VV[23], T12, ECL_SYM("VALUES",895), v7exit);
   T11 = ecl_list1(T13);
   goto L131;
L134:;
   T12 = cl_list(2, ECL_SYM("QUOTE",679), v10fname);
   T13 = cl_listX(5, VV[20], VV[23], T12, ECL_SYM("VALUES",895), v7exit);
   T14 = cl_list(3, ECL_SYM("WHEN",905), v5exitcond, T13);
   T11 = ecl_list1(T14);
   goto L131;
L132:;
   T11 = ECL_NIL;
L131:;
   if (Null(v3exitbreak)) { goto L137; }
   T13 = cl_list(2, ECL_SYM("QUOTE",679), v10fname);
   T14 = cl_list(3, ECL_SYM("BREAK",158), _ecl_static_9, T13);
   T15 = cl_list(3, ECL_SYM("LET",477), VV[22], T14);
   T16 = cl_list(3, ECL_SYM("WHEN",905), v3exitbreak, T15);
   T12 = ecl_list1(T16);
   goto L136;
L137:;
   T12 = ECL_NIL;
L136:;
   T13 = ecl_append(T11,T12);
   T14 = CONS(T10,T13);
   T15 = cl_append(3, T4, T5, T14);
   T16 = cl_listX(3, ECL_SYM("LET",477), VV[19], T15);
   T17 = cl_list(4, ECL_SYM("IF",946), VV[8], T3, T16);
   T18 = cl_list(4, ECL_SYM("LET*",478), VV[17], T17, VV[24]);
   T19 = cl_list(4, ECL_SYM("DEFUN",289), v10fname, VV[16], T18);
   cl_eval(T19);
   L12add_to_trace_list(v10fname, v11oldf);
   value0 = ecl_list1(v10fname);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for TRACE-PRINT                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L6trace_print(cl_narg narg, cl_object v1direction, cl_object v2fname, cl_object v3vals, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 {
  cl_object v4extras;
  ecl_va_list args; ecl_va_start(args,v3vals,narg,3);
  v4extras = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v5;
   T0 = ecl_one_minus(ecl_symbol_value(VV[0]));
   T1 = ecl_times(T0,ecl_make_fixnum(2));
   v5 = (ecl_number_compare(T1,ecl_symbol_value(VV[1]))<=0?T1:ecl_symbol_value(VV[1]));
   ecl_bds_bind(cl_env_copy,ECL_SYM("*PRINT-CIRCLE*",47),ECL_T); /*  *PRINT-CIRCLE* */
   cl_fresh_line(1, ecl_symbol_value(ECL_SYM("*TRACE-OUTPUT*",69)));
   if (!((v1direction)==(VV[26]))) { goto L4; }
   {
    cl_object v7;                                 /*  BARS            */
    cl_object v8;                                 /*  REM             */
    value0 = ecl_floor2(v5,ecl_make_fixnum(4));
    v7 = value0;
    v8 = cl_env_copy->values[1];
    {
     cl_object v9i;
     v9i = ecl_make_fixnum(0);
     goto L11;
L10:;
     if (!(ecl_number_compare(v9i,ecl_make_fixnum(10))<0)) { goto L15; }
     T0 = _ecl_static_10;
     goto L14;
L15:;
     T0 = _ecl_static_11;
L14:;
     ecl_princ(T0,ecl_symbol_value(ECL_SYM("*TRACE-OUTPUT*",69)));
     v9i = ecl_one_plus(v9i);
L11:;
     if (!(ecl_number_compare(v9i,v7)<0)) { goto L19; }
     goto L10;
L19:;
    }
    if (!(ecl_plusp(v8))) { goto L6; }
    cl_format(4, ecl_symbol_value(ECL_SYM("*TRACE-OUTPUT*",69)), _ecl_static_12, v8, _ecl_static_13);
   }
L6:;
   cl_format(5, ecl_symbol_value(ECL_SYM("*TRACE-OUTPUT*",69)), _ecl_static_14, ecl_symbol_value(VV[0]), v2fname, v3vals);
   goto L3;
L4:;
   if (!((v1direction)==(ECL_SYM("EXIT",1740)))) { goto L3; }
   {
    cl_object v7;                                 /*  BARS            */
    cl_object v8;                                 /*  REM             */
    value0 = ecl_floor2(v5,ecl_make_fixnum(4));
    v7 = value0;
    v8 = cl_env_copy->values[1];
    {
     cl_object v9i;
     v9i = ecl_make_fixnum(0);
     goto L28;
L27:;
     ecl_princ_str("|   ",ecl_symbol_value(ECL_SYM("*TRACE-OUTPUT*",69)));
     v9i = ecl_one_plus(v9i);
L28:;
     if (!(ecl_number_compare(v9i,v7)<0)) { goto L34; }
     goto L27;
L34:;
    }
    if (!(ecl_plusp(v8))) { goto L23; }
    cl_format(4, ecl_symbol_value(ECL_SYM("*TRACE-OUTPUT*",69)), _ecl_static_12, v8, _ecl_static_13);
   }
L23:;
   cl_format(5, ecl_symbol_value(ECL_SYM("*TRACE-OUTPUT*",69)), _ecl_static_15, ecl_symbol_value(VV[0]), v2fname, v3vals);
L3:;
   if (Null(v4extras)) { goto L37; }
   {
    cl_object v7;                                 /*  BARS            */
    cl_object v8;                                 /*  REM             */
    value0 = ecl_floor2(v5,ecl_make_fixnum(4));
    v7 = value0;
    v8 = cl_env_copy->values[1];
    {
     cl_object v9i;
     v9i = ecl_make_fixnum(0);
     goto L44;
L43:;
     ecl_princ_str("|   ",ecl_symbol_value(ECL_SYM("*TRACE-OUTPUT*",69)));
     v9i = ecl_one_plus(v9i);
L44:;
     if (!(ecl_number_compare(v9i,v7)<0)) { goto L50; }
     goto L43;
L50:;
    }
    if (!(ecl_plusp(v8))) { goto L39; }
    cl_format(4, ecl_symbol_value(ECL_SYM("*TRACE-OUTPUT*",69)), _ecl_static_12, v8, _ecl_static_13);
   }
L39:;
   value0 = cl_format(3, ecl_symbol_value(ECL_SYM("*TRACE-OUTPUT*",69)), _ecl_static_16, v4extras);
   ecl_bds_unwind1(cl_env_copy);
   return value0;
L37:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
 }
}
/*	function definition for TRACE-RECORD                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7trace_record(cl_object v1fname)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   cl_object v3;
   v2 = ecl_symbol_value(ECL_SYM("*TRACE-LIST*",1832));
   v3 = si_make_seq_iterator(2, v2, ecl_make_fixnum(0));
L3:;
   if ((v3)!=ECL_NIL) { goto L5; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L5:;
   {
    cl_object v4;
    v4 = si_seq_iterator_ref(v2, v3);
    T0 = ecl_car(v4);
    if (!(ecl_equal(v1fname,T0))) { goto L7; }
    value0 = v4;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L7:;
   v3 = si_seq_iterator_next(v2, v3);
   goto L3;
  }
 }
}
/*	function definition for TRACE-RECORD-NAME                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8trace_record_name(cl_object v1record)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_car(v1record);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for TRACE-RECORD-DEFINITION               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L9trace_record_definition(cl_object v1record)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_cadr(v1record);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for TRACE-RECORD-OLD-DEFINITION           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L10trace_record_old_definition(cl_object v1record)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_caddr(v1record);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for TRACED-OLD-DEFINITION                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
cl_object si_traced_old_definition(cl_object v1fname)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2record;
   v2record = L7trace_record(v1fname);
   if (Null(v2record)) { goto L2; }
   if ((L13traced_and_redefined_p(v2record))!=ECL_NIL) { goto L4; }
   value0 = L10trace_record_old_definition(v2record);
   return value0;
L4:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for DELETE-FROM-TRACE-LIST                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L11delete_from_trace_list(cl_object v1fname)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_symbol_value(ECL_SYM("*TRACE-LIST*",1832));
  T1 = (ECL_SYM("FIRST",371)->symbol.gfdef);
  T2 = (ECL_SYM("EQUAL",335)->symbol.gfdef);
  cl_set(ECL_SYM("*TRACE-LIST*",1832),cl_delete(6, v1fname, T0, ECL_SYM("KEY",1262), T1, ECL_SYM("TEST",1316), T2));
  value0 = ecl_symbol_value(ECL_SYM("*TRACE-LIST*",1832));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for ADD-TO-TRACE-LIST                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L12add_to_trace_list(cl_object v1fname, cl_object v2old_definition)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = cl_fdefinition(v1fname);
  T1 = cl_list(3, v1fname, T0, v2old_definition);
  cl_set(ECL_SYM("*TRACE-LIST*",1832),CONS(T1,ecl_symbol_value(ECL_SYM("*TRACE-LIST*",1832))));
  value0 = ecl_symbol_value(ECL_SYM("*TRACE-LIST*",1832));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for TRACED-AND-REDEFINED-P                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L13traced_and_redefined_p(cl_object v1record)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v1record)) { goto L2; }
  T0 = L9trace_record_definition(v1record);
  T1 = L8trace_record_name(v1record);
  T2 = cl_fdefinition(T1);
  {
   bool v2;
   v2 = (T0)==(T2);
   value0 = (v2)?ECL_NIL:ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L2:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for UNTRACE-ONE                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L14untrace_one(cl_object v1fname)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2record;
   v2record = L7trace_record(v1fname);
   if (!(v2record==ECL_NIL)) { goto L3; }
   (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(2, _ecl_static_17, v1fname) /*  WARN */;
   goto L2;
L3:;
   if (Null(L13traced_and_redefined_p(v2record))) { goto L5; }
   (cl_env_copy->function=(ECL_SYM("WARN",903)->symbol.gfdef))->cfun.entry(2, _ecl_static_18, v1fname) /*  WARN */;
   goto L2;
L5:;
   T0 = L10trace_record_old_definition(v2record);
   si_fset(4, v1fname, T0, ECL_NIL, ECL_NIL);
L2:;
   L11delete_from_trace_list(v1fname);
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 0;
   return value0;
  }
 }
}
/*	local function STEP                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC15step(cl_object v1, cl_object v2)
{
 cl_object T0;
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
   T0 = cl_list(2, ECL_SYM("QUOTE",679), v4form);
   value0 = cl_list(2, VV[36], T0);
   return value0;
  }
 }
}
/*	function definition for STEP*                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L16step_(cl_object volatile v1form)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_bds_bind(cl_env_copy,ECL_SYM("*STEP-ACTION*",1033),ECL_T); /*  *STEP-ACTION* */
  ecl_bds_bind(cl_env_copy,ECL_SYM("*STEP-LEVEL*",1032),ecl_make_fixnum(0)); /*  *STEP-LEVEL* */
  T0 = cl_make_hash_table(4, ECL_SYM("SIZE",1308), ecl_make_fixnum(128), ECL_SYM("TEST",1316), ECL_SYM("EQ",333));
  ecl_bds_bind(cl_env_copy,VV[34],T0);            /*  *STEP-FUNCTIONS* */
  value0 = ecl_symbol_value(VV[33]);
  if (ecl_frs_push(cl_env_copy,value0)) {         /*  BEGIN CATCH 1   */
   value0 = cl_env_copy->values[0];
  } else {
   value0 = si_eval_with_env(3, v1form, ECL_NIL, ECL_T);
  }
  ecl_frs_pop(cl_env_copy);                       /*  END CATCH 1     */
  ecl_bds_unwind1(cl_env_copy);
  ecl_bds_unwind1(cl_env_copy);
  ecl_bds_unwind1(cl_env_copy);
  return value0;
 }
}
/*	function definition for STEPPABLE-FUNCTION                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L17steppable_function(cl_object v1form)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  ecl_bds_bind(cl_env_copy,ECL_SYM("*STEP-ACTION*",1033),ECL_NIL); /*  *STEP-ACTION* */
  value0 = ecl_gethash_safe(v1form,ecl_symbol_value(VV[34]),ECL_NIL);
  if ((value0)!=ECL_NIL) { goto L2; }
  {
   cl_object v3;                                  /*  F               */
   cl_object v4;                                  /*  ENV             */
   cl_object v5;                                  /*  NAME            */
   value0 = cl_function_lambda_expression(v1form);
   v3 = value0;
   v4 = cl_env_copy->values[1];
   v5 = cl_env_copy->values[2];
   if ((L7trace_record(v5))!=ECL_NIL) { goto L5; }
   if (Null(v3)) { goto L5; }
   T0 = ecl_symbol_value(VV[34]);
   T1 = cl_list(2, ECL_SYM("FUNCTION",396), v3);
   T2 = si_eval_with_env(3, T1, v4, ECL_T);
   value0 = si_hash_set(v1form, T0, T2);
   ecl_bds_unwind1(cl_env_copy);
   return value0;
L5:;
   value0 = v1form;
   cl_env_copy->nvalues = 1;
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
L2:;
  cl_env_copy->nvalues = 1;
  ecl_bds_unwind1(cl_env_copy);
  return value0;
 }
}
/*	function definition for STEPPER                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L19stepper(cl_object volatile v1form)
{
 cl_object T0, T1, T2;
 cl_object volatile env0;
 cl_object volatile CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 volatile cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1form,env0);                /*  FORM            */
  if (ECL_SYMBOLP(ECL_CONS_CAR(CLV0))) { goto L3; }
  if (Null(cl_functionp(ECL_CONS_CAR(CLV0)))) { goto L1; }
  goto L2;
L3:;
L2:;
  T0 = si_coerce_to_function(ECL_CONS_CAR(CLV0));
  value0 = L17steppable_function(T0);
  return value0;
L1:;
  {
   volatile cl_object v2prompt;
   volatile cl_object env1 = env0;
   ecl_bds_bind(cl_env_copy,VV[32],ECL_CONS_CAR(CLV0)); /*  *STEP-FORM* */
   ecl_bds_bind(cl_env_copy,ECL_SYM("*STEP-ACTION*",1033),ECL_NIL); /*  *STEP-ACTION* */
   T0 = ecl_times(ecl_symbol_value(VV[40]),ecl_make_fixnum(2));
   T1 = (ecl_number_compare(T0,ecl_make_fixnum(20))<=0?T0:ecl_make_fixnum(20));
   CLV1 = env1 = CONS(T1,env1);                   /*  INDENT          */
   v2prompt = ECL_NIL;
   {cl_object v3;
    v3 = ECL_NIL;
    v3 = ecl_make_cclosure_va((cl_objectfn)LC18__g73,env1,Cblock);
    v2prompt = v3;
   }
   value0 = ecl_symbol_value(VV[33]);
   if (ecl_frs_push(cl_env_copy,value0)) {        /*  BEGIN CATCH 10  */
    value0 = cl_env_copy->values[0];
   } else {
    T0 = ecl_symbol_value(VV[35]);
    T1 = cl_adjoin(2, ecl_symbol_value(VV[43]), ecl_symbol_value(VV[44]));
    T2 = cl_adjoin(2, T0, T1);
    value0 = ecl_function_dispatch(cl_env_copy,VV[66])(8, VV[41], ECL_T, VV[42], T2, VV[45], ECL_SYM("STEPPER",1148), VV[46], v2prompt) /*  TPL */;
   }
   ecl_frs_pop(cl_env_copy);                      /*  END CATCH 10    */
   if (Null(value0)) { goto L8; }
   cl_env_copy->values[0] = ECL_T;
   cl_env_copy->nvalues = 1;
   cl_throw(ecl_symbol_value(VV[33]));
L8:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   ecl_bds_unwind1(cl_env_copy);
   ecl_bds_unwind1(cl_env_copy);
   return value0;
  }
 }
}
/*	closure G73                                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC18__g73(cl_narg narg, ...)
{
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  INDENT          */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=0)) FEwrong_num_arguments_anonym();
 {
TTL:
  cl_format(3, ecl_symbol_value(ECL_SYM("*DEBUG-IO*",30)), _ecl_static_19, ECL_CONS_CAR(CLV1));
  cl_write(9, ECL_CONS_CAR(CLV0), ECL_SYM("STREAM",1313), ecl_symbol_value(ECL_SYM("*DEBUG-IO*",30)), ECL_SYM("PRETTY",1289), ECL_NIL, ECL_SYM("LEVEL",1264), ecl_make_fixnum(2), ECL_SYM("LENGTH",1263), ecl_make_fixnum(2));
  ecl_princ_char((ecl_character)(32),ecl_symbol_value(ECL_SYM("*DEBUG-IO*",30)));
  value0 = CODE_CHAR(ecl_princ_char((ecl_character)(45),ecl_symbol_value(ECL_SYM("*DEBUG-IO*",30))));
  cl_env_copy->nvalues = 1;
  return value0;
 }
 }
}
/*	function definition for STEP-NEXT                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L20step_next()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  cl_env_copy->values[0] = ECL_NIL;
  cl_env_copy->nvalues = 1;
  cl_throw(ecl_symbol_value(VV[33]));
 }
}
/*	function definition for STEP-SKIP                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L21step_skip(cl_narg narg, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg>1)) FEwrong_num_arguments_anonym();
 {
  cl_object v1when;
  va_list args; va_start(args,narg);
  {
   int i = 0;
   if (i >= narg) {
    v1when = ecl_make_fixnum(0);
   } else {
    i++;
    v1when = va_arg(args,cl_object);
   }
  }
  va_end(args);
  cl_set(ECL_SYM("*STEP-ACTION*",1033),ecl_make_fixnum(0));
  cl_env_copy->values[0] = ECL_NIL;
  cl_env_copy->nvalues = 1;
  cl_throw(ecl_symbol_value(VV[33]));
 }
}
/*	function definition for STEP-PRINT                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L22step_print()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  cl_write(9, ecl_symbol_value(VV[32]), ECL_SYM("STREAM",1313), ecl_symbol_value(ECL_SYM("*DEBUG-IO*",30)), ECL_SYM("PRETTY",1289), ECL_T, ECL_SYM("LEVEL",1264), ECL_NIL, ECL_SYM("LENGTH",1263), ECL_NIL);
  ecl_terpri(ECL_NIL);
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 0;
  return value0;
 }
}
/*	function definition for STEP-QUIT                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L23step_quit()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  cl_env_copy->values[0] = ECL_T;
  cl_env_copy->nvalues = 1;
  cl_throw(ecl_symbol_value(VV[33]));
 }
}

#include "lsp/trace.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _ecl0i7oRRI7KYIr9_Ifw9ZE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:LSP;TRACE.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_ecl0i7oRRI7KYIr9_Ifw9ZE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 si_Xmake_special(VV[0]);
 cl_set(VV[0],ecl_make_fixnum(0));
 si_Xmake_special(VV[1]);
 cl_set(VV[1],ecl_make_fixnum(20));
 ecl_cmp_defmacro(VV[52]);                        /*  TRACE           */
 ecl_cmp_defun(VV[53]);                           /*  TRACE*          */
 ecl_cmp_defmacro(VV[54]);                        /*  UNTRACE         */
 ecl_cmp_defun(VV[55]);                           /*  UNTRACE*        */
 si_Xmake_special(VV[8]);
 cl_set(VV[8],ECL_NIL);
 ecl_cmp_defun(VV[56]);                           /*  TRACE-ONE       */
 ecl_cmp_defun(VV[57]);                           /*  TRACE-PRINT     */
 (void)0; /* No entry created for TRACE-RECORD */
 (void)0; /* No entry created for TRACE-RECORD-NAME */
 (void)0; /* No entry created for TRACE-RECORD-DEFINITION */
 (void)0; /* No entry created for TRACE-RECORD-OLD-DEFINITION */
 ecl_cmp_defun(VV[58]);                           /*  TRACED-OLD-DEFINITION */
 ecl_cmp_defun(VV[59]);                           /*  DELETE-FROM-TRACE-LIST */
 ecl_cmp_defun(VV[60]);                           /*  ADD-TO-TRACE-LIST */
 (void)0; /* No entry created for TRACED-AND-REDEFINED-P */
 ecl_cmp_defun(VV[61]);                           /*  UNTRACE-ONE     */
 si_Xmake_special(ECL_SYM("*STEP-LEVEL*",1032));
 cl_set(ECL_SYM("*STEP-LEVEL*",1032),ecl_make_fixnum(0));
 si_Xmake_special(ECL_SYM("*STEP-ACTION*",1033));
 cl_set(ECL_SYM("*STEP-ACTION*",1033),ECL_NIL);
 si_Xmake_special(VV[32]);
 cl_set(VV[32],ECL_NIL);
 si_Xmake_special(VV[33]);
 cl_set(VV[33],CONS(ECL_NIL,ECL_NIL));
 si_Xmake_special(VV[34]);
 cl_set(VV[34],ECL_NIL);
 si_Xmake_constant(VV[35], VVtemp[0]);
 ecl_cmp_defmacro(VV[62]);                        /*  STEP            */
 ecl_cmp_defun(VV[63]);                           /*  STEP*           */
 ecl_cmp_defun(VV[64]);                           /*  STEPPABLE-FUNCTION */
 ecl_cmp_defun(VV[65]);                           /*  STEPPER         */
 ecl_cmp_defun(VV[67]);                           /*  STEP-NEXT       */
 ecl_cmp_defun(VV[68]);                           /*  STEP-SKIP       */
 ecl_cmp_defun(VV[69]);                           /*  STEP-PRINT      */
 ecl_cmp_defun(VV[70]);                           /*  STEP-QUIT       */
}
