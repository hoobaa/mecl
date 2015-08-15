/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CLOS;STREAMS.LSP                                  */
#include <ecl/ecl-cmp.h>
#include "clos/streams.eclh"
/*	function definition for BUG-OR-ERROR                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1bug_or_error(cl_object v1stream, cl_object v2fun)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(cl_streamp(v1stream))) { goto L1; }
  value0 = cl_error(3, _ecl_static_31, v1stream, v2fun);
  return value0;
L1:;
  value0 = cl_error(5, ECL_SYM("TYPE-ERROR",870), ECL_SYM("DATUM",1214), v1stream, ECL_SYM("EXPECTED-TYPE",1232), ECL_SYM("STREAM",799));
  return value0;
 }
}
/*	local function G0                                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC2__g0(cl_object v1stream, cl_object v2column)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3current_column;
   v3current_column = ecl_function_dispatch(cl_env_copy,ECL_SYM("STREAM-LINE-COLUMN",1631))(1, v1stream) /*  STREAM-LINE-COLUMN */;
   if (Null(v3current_column)) { goto L2; }
   {
    cl_object v4fill;
    v4fill = ecl_minus(v2column,v3current_column);
    {
     cl_object v5i;
     v5i = ecl_make_fixnum(0);
     goto L8;
L7:;
     ecl_function_dispatch(cl_env_copy,ECL_SYM("STREAM-WRITE-CHAR",1643))(2, v1stream, CODE_CHAR(32)) /*  STREAM-WRITE-CHAR */;
     v5i = ecl_one_plus(v5i);
L8:;
     if (!(ecl_number_compare(v5i,v4fill)<0)) { goto L13; }
     goto L7;
L13:;
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
}
/*	local function G6                                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC3__g6(cl_object v1stream)
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
/*	local function G7                                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC4__g7(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_clear_input(1, v1stream);
  return value0;
 }
}
/*	local function G8                                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC5__g8(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L1bug_or_error(v1stream, ECL_SYM("STREAM-CLEAR-INPUT",1622));
  return value0;
 }
}
/*	local function G9                                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC6__g9(cl_object v1stream)
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
/*	local function G10                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC7__g10(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_clear_output(1, v1stream);
  return value0;
 }
}
/*	local function G11                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC8__g11(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L1bug_or_error(v1stream, ECL_SYM("STREAM-CLEAR-OUTPUT",1623));
  return value0;
 }
}
/*	local function G16                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC9__g16(cl_narg narg, cl_object v1stream, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2abort;
  ecl_va_list args; ecl_va_start(args,v1stream,narg,1);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,LC9__g16keys,keyvars,NULL,TRUE);
   ecl_va_end(args);
   v2abort = keyvars[0];
  }
  (cl_env_copy->function=ecl_fdefinition(VV[8]))->cfun.entry(2, ECL_NIL, v1stream) /*  (SETF OPEN-STREAM-P) */;
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G19                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC10__g19(cl_narg narg, cl_object v1stream, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2abort;
  ecl_va_list args; ecl_va_start(args,v1stream,narg,1);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,LC10__g19keys,keyvars,NULL,TRUE);
   ecl_va_end(args);
   v2abort = keyvars[0];
  }
  value0 = cl_close(3, v1stream, ECL_SYM("ABORT",1195), v2abort);
  return value0;
 }
}
/*	local function G20                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC11__g20(cl_narg narg, cl_object v1stream, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2abort;
  ecl_va_list args; ecl_va_start(args,v1stream,narg,1);
  {
   cl_object keyvars[2];
   cl_parse_key(args,1,LC11__g20keys,keyvars,NULL,TRUE);
   ecl_va_end(args);
   v2abort = keyvars[0];
  }
  value0 = L1bug_or_error(v1stream, ECL_SYM("CLOSE",1616));
  return value0;
 }
}
/*	local function G21                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC12__g21(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ECL_SYM("CHARACTER",222);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G22                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC13__g22(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_stream_element_type(v1stream);
  return value0;
 }
}
/*	local function G23                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC14__g23(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L1bug_or_error(v1stream, ECL_SYM("STREAM-ELEMENT-TYPE",1624));
  return value0;
 }
}
/*	local function G24                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC15__g24(cl_object v1stream)
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
/*	local function G25                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC16__g25(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_finish_output(1, v1stream);
  return value0;
 }
}
/*	local function G26                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC17__g26(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L1bug_or_error(v1stream, ECL_SYM("STREAM-FINISH-OUTPUT",1627));
  return value0;
 }
}
/*	local function G27                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC18__g27(cl_object v1stream)
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
/*	local function G28                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC19__g28(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_force_output(1, v1stream);
  return value0;
 }
}
/*	local function G29                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC20__g29(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L1bug_or_error(v1stream, ECL_SYM("STREAM-FORCE-OUTPUT",1628));
  return value0;
 }
}
/*	local function G30                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC21__g30(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if ((ecl_function_dispatch(cl_env_copy,ECL_SYM("STREAM-START-LINE-P",1639))(1, v1stream) /*  STREAM-START-LINE-P */)!=ECL_NIL) { goto L1; }
  ecl_function_dispatch(cl_env_copy,ECL_SYM("STREAM-TERPRI",1640))(1, v1stream) /*  STREAM-TERPRI */;
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G31                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC22__g31(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_fresh_line(1, v1stream);
  return value0;
 }
}
/*	local function G32                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC23__g32(cl_object v1stream)
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
/*	local function G33                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC24__g33(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G34                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC25__g34(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_input_stream_p(v1stream);
  return value0;
 }
}
/*	local function G35                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC26__g35(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L1bug_or_error(v1stream, ECL_SYM("INPUT-STREAM-P",1618));
  return value0;
 }
}
/*	local function G36                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC27__g36(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_interactive_stream_p(v1stream);
  return value0;
 }
}
/*	local function G37                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC28__g37(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L1bug_or_error(v1stream, ECL_SYM("STREAM-INTERACTIVE-P",1630));
  return value0;
 }
}
/*	local function G38                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC29__g38(cl_object v1stream)
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
/*	local function G39                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC30__g39(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2char;
   v2char = ecl_function_dispatch(cl_env_copy,ECL_SYM("STREAM-READ-CHAR-NO-HANG",1636))(1, v1stream) /*  STREAM-READ-CHAR-NO-HANG */;
   if (!(ECL_CHARACTERP(v2char))) { goto L2; }
   ecl_function_dispatch(cl_env_copy,ECL_SYM("STREAM-UNREAD-CHAR",1641))(2, v1stream, v2char) /*  STREAM-UNREAD-CHAR */;
   value0 = ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G40                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC31__g40(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_listen(1, v1stream);
  return value0;
 }
}
/*	local function G41                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC32__g41(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L1bug_or_error(v1stream, ECL_SYM("STREAM-LISTEN",1632));
  return value0;
 }
}
/*	local function G42                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC33__g42(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_open_stream_p(v1stream);
  return value0;
 }
}
/*	local function G43                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC34__g43(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L1bug_or_error(v1stream, ECL_SYM("OPEN-STREAM-P",1620));
  return value0;
 }
}
/*	local function G44                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC35__g44(cl_object v1stream)
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
/*	local function G45                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC36__g45(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G46                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC37__g46(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_output_stream_p(v1stream);
  return value0;
 }
}
/*	local function G47                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC38__g47(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L1bug_or_error(v1stream, ECL_SYM("OUTPUT-STREAM-P",1619));
  return value0;
 }
}
/*	local function G48                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC39__g48(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2char;
   v2char = ecl_function_dispatch(cl_env_copy,ECL_SYM("STREAM-READ-CHAR",1635))(1, v1stream) /*  STREAM-READ-CHAR */;
   if ((v2char)==(ECL_SYM("EOF",1228))) { goto L2; }
   ecl_function_dispatch(cl_env_copy,ECL_SYM("STREAM-UNREAD-CHAR",1641))(2, v1stream, v2char) /*  STREAM-UNREAD-CHAR */;
L2:;
   value0 = v2char;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G49                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC40__g49(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_peek_char(1, v1stream);
  return value0;
 }
}
/*	local function G50                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC41__g50(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L1bug_or_error(v1stream, ECL_SYM("STREAM-PEEK-CHAR",1633));
  return value0;
 }
}
/*	local function G51                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC42__g51(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_read_byte(1, v1stream);
  return value0;
 }
}
/*	local function G52                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC43__g52(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L1bug_or_error(v1stream, ECL_SYM("STREAM-READ-BYTE",1634));
  return value0;
 }
}
/*	local function G53                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC44__g53(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_read_char(1, v1stream);
  return value0;
 }
}
/*	local function G54                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC45__g54(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L1bug_or_error(v1stream, ECL_SYM("STREAM-READ-CHAR",1635));
  return value0;
 }
}
/*	local function G55                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC46__g55(cl_object v1stream, cl_object v2character)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_unread_char(2, v2character, v1stream);
  return value0;
 }
}
/*	local function G56                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC47__g56(cl_object v1stream, cl_object v2character)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L1bug_or_error(v1stream, ECL_SYM("STREAM-UNREAD-CHAR",1641));
  return value0;
 }
}
/*	local function G57                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC48__g57(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("STREAM-READ-CHAR",1635))(1, v1stream) /*  STREAM-READ-CHAR */;
  return value0;
 }
}
/*	local function G58                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC49__g58(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_read_char_no_hang(1, v1stream);
  return value0;
 }
}
/*	local function G59                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC50__g59(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L1bug_or_error(v1stream, ECL_SYM("STREAM-READ-CHAR-NO-HANG",1636));
  return value0;
 }
}
/*	local function G72                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC51__g72(cl_object v1stream)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   cl_object v3res;
   cl_object v4len;
   cl_object v5index;
   v2 = cl_make_string(1, ecl_make_fixnum(80));
   v3res = v2;
   v4len = ecl_make_fixnum(80);
   v5index = ecl_make_fixnum(0);
L5:;
   {
    cl_object v6ch;
    v6ch = ecl_function_dispatch(cl_env_copy,ECL_SYM("STREAM-READ-CHAR",1635))(1, v1stream) /*  STREAM-READ-CHAR */;
    if (!((v6ch)==(ECL_SYM("EOF",1228)))) { goto L8; }
    T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SHRINK-VECTOR",1776))(2, v3res, v5index) /*  SHRINK-VECTOR */;
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = ECL_T;
    cl_env_copy->values[0] = T0;
    return cl_env_copy->values[0];
L8:;
    if (!(ecl_char_code(v6ch)==ecl_char_code(CODE_CHAR(10)))) { goto L10; }
    T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("SHRINK-VECTOR",1776))(2, v3res, v5index) /*  SHRINK-VECTOR */;
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = ECL_NIL;
    cl_env_copy->values[0] = T0;
    return cl_env_copy->values[0];
L10:;
    if (!(ecl_number_equalp(v5index,v4len))) { goto L12; }
    v4len = ecl_times(v4len,ecl_make_fixnum(2));
    {
     cl_object v7new;
     v7new = cl_make_string(1, v4len);
     cl_replace(2, v7new, v3res);
     v3res = v7new;
    }
L12:;
    ecl_elt_set(v3res,ecl_to_size(v5index),v6ch);
    v5index = ecl_plus(v5index,ecl_make_fixnum(1));
   }
   goto L5;
  }
 }
}
/*	local function G82                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC52__g82(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_read_line(1, v1stream);
  return value0;
 }
}
/*	local function G83                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC53__g83(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L1bug_or_error(v1stream, ECL_SYM("STREAM-READ-LINE",1637));
  return value0;
 }
}
/*	local function G84                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC54__g84(cl_narg narg, cl_object v1stream, cl_object v2sequence, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>4)) FEwrong_num_arguments_anonym();
 {
  cl_object v3start;
  cl_object v4end;
  va_list args; va_start(args,v2sequence);
  {
   int i = 2;
   if (i >= narg) {
    v3start = ecl_make_fixnum(0);
   } else {
    i++;
    v3start = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v4end = ECL_NIL;
   } else {
    i++;
    v4end = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = si_do_read_sequence(v2sequence, v1stream, v3start, v4end);
  return value0;
 }
}
/*	local function G85                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC55__g85(cl_narg narg, cl_object v1stream, cl_object v2sequence, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>4)) FEwrong_num_arguments_anonym();
 {
  cl_object v3start;
  cl_object v4end;
  va_list args; va_start(args,v2sequence);
  {
   int i = 2;
   if (i >= narg) {
    v3start = ecl_make_fixnum(0);
   } else {
    i++;
    v3start = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v4end = ECL_NIL;
   } else {
    i++;
    v4end = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = si_do_read_sequence(v2sequence, v1stream, v3start, v4end);
  return value0;
 }
}
/*	local function G86                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC56__g86(cl_narg narg, cl_object v1stream, cl_object v2sequence, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>4)) FEwrong_num_arguments_anonym();
 {
  cl_object v3start;
  cl_object v4end;
  va_list args; va_start(args,v2sequence);
  {
   int i = 2;
   if (i >= narg) {
    v3start = ecl_make_fixnum(0);
   } else {
    i++;
    v3start = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v4end = ECL_NIL;
   } else {
    i++;
    v4end = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = si_do_read_sequence(v1stream, v2sequence, v3start, v4end);
  return value0;
 }
}
/*	local function G87                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC57__g87(cl_narg narg, cl_object v1stream, cl_object v2sequence, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>4)) FEwrong_num_arguments_anonym();
 {
  cl_object v3start;
  cl_object v4end;
  va_list args; va_start(args,v2sequence);
  {
   int i = 2;
   if (i >= narg) {
    v3start = ECL_NIL;
   } else {
    i++;
    v3start = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v4end = ECL_NIL;
   } else {
    i++;
    v4end = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = L1bug_or_error(v1stream, ECL_SYM("STREAM-READ-SEQUENCE",1638));
  return value0;
 }
}
/*	local function G88                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC58__g88(cl_object v1stream)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("STREAM-LINE-COLUMN",1631))(1, v1stream) /*  STREAM-LINE-COLUMN */;
  value0 = ecl_make_bool((T0)==(ecl_make_fixnum(0)));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G89                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC59__g89(cl_narg narg, cl_object v1stream, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2position;
  va_list args; va_start(args,v1stream);
  {
   int i = 1;
   if (i >= narg) {
    v2position = ECL_NIL;
   } else {
    i++;
    v2position = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = cl_file_position(2, v1stream, v2position);
  return value0;
 }
}
/*	local function G90                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC60__g90(cl_narg narg, cl_object v1stream, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2position;
  va_list args; va_start(args,v1stream);
  {
   int i = 1;
   if (i >= narg) {
    v2position = ECL_NIL;
   } else {
    i++;
    v2position = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G91                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC61__g91(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ECL_T;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G92                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC62__g92(cl_object v1stream)
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
/*	local function G93                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC63__g93(cl_object v1stream, cl_object v2integer)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_write_byte(v2integer, v1stream);
  return value0;
 }
}
/*	local function G94                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC64__g94(cl_object v1stream, cl_object v2integer)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L1bug_or_error(v1stream, ECL_SYM("STREAM-WRITE-BYTE",1642));
  return value0;
 }
}
/*	local function G95                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC65__g95(cl_object v1stream, cl_object v2character)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_write_char(2, v2character, v1stream);
  return value0;
 }
}
/*	local function G96                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC66__g96(cl_object v1stream, cl_object v2character)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L1bug_or_error(v1stream, ECL_SYM("STREAM-WRITE-CHAR",1643));
  return value0;
 }
}
/*	local function G97                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC67__g97(cl_narg narg, cl_object v1stream, cl_object v2sequence, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>4)) FEwrong_num_arguments_anonym();
 {
  cl_object v3start;
  cl_object v4end;
  va_list args; va_start(args,v2sequence);
  {
   int i = 2;
   if (i >= narg) {
    v3start = ecl_make_fixnum(0);
   } else {
    i++;
    v3start = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v4end = ECL_NIL;
   } else {
    i++;
    v4end = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = si_do_write_sequence(v2sequence, v1stream, v3start, v4end);
  return value0;
 }
}
/*	local function G98                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC68__g98(cl_narg narg, cl_object v1stream, cl_object v2sequence, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>4)) FEwrong_num_arguments_anonym();
 {
  cl_object v3start;
  cl_object v4end;
  va_list args; va_start(args,v2sequence);
  {
   int i = 2;
   if (i >= narg) {
    v3start = ecl_make_fixnum(0);
   } else {
    i++;
    v3start = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v4end = ECL_NIL;
   } else {
    i++;
    v4end = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = si_do_write_sequence(v2sequence, v1stream, v3start, v4end);
  return value0;
 }
}
/*	local function G99                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC69__g99(cl_narg narg, cl_object v1stream, cl_object v2sequence, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>4)) FEwrong_num_arguments_anonym();
 {
  cl_object v3start;
  cl_object v4end;
  va_list args; va_start(args,v2sequence);
  {
   int i = 2;
   if (i >= narg) {
    v3start = ecl_make_fixnum(0);
   } else {
    i++;
    v3start = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v4end = ECL_NIL;
   } else {
    i++;
    v4end = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = si_do_write_sequence(v2sequence, v1stream, v3start, v4end);
  return value0;
 }
}
/*	local function G100                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC70__g100(cl_narg narg, cl_object v1stream, cl_object v2sequence, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>4)) FEwrong_num_arguments_anonym();
 {
  cl_object v3start;
  cl_object v4end;
  va_list args; va_start(args,v2sequence);
  {
   int i = 2;
   if (i >= narg) {
    v3start = ECL_NIL;
   } else {
    i++;
    v3start = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v4end = ECL_NIL;
   } else {
    i++;
    v4end = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = L1bug_or_error(v1stream, ECL_SYM("STREAM-WRITE-SEQUENCE",1644));
  return value0;
 }
}
/*	local function G101                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC71__g101(cl_narg narg, cl_object v1stream, cl_object v2string, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>4)) FEwrong_num_arguments_anonym();
 {
  cl_object v3start;
  cl_object v4end;
  va_list args; va_start(args,v2string);
  {
   int i = 2;
   if (i >= narg) {
    v3start = ecl_make_fixnum(0);
   } else {
    i++;
    v3start = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v4end = ECL_NIL;
   } else {
    i++;
    v4end = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   bool v5;
   v5 = ECL_STRINGP(v2string);
   if (ecl_unlikely(!(v5)))
         FEwrong_type_argument(ECL_SYM("STRING",805),v2string);
  }
  {
   bool v5;
   v5 = ECL_FIXNUMP(v3start);
   if (ecl_unlikely(!(v5)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v3start);
  }
  {
   cl_fixnum v5end;
   {
    cl_object v6;
    value0 = v4end;
    if ((value0)!=ECL_NIL) { goto L9; }
    v6 = ecl_make_fixnum(ecl_length(v2string));
    goto L7;
L9:;
    v6 = value0;
    goto L7;
L7:;
    {
     bool v7;
     v7 = ECL_FIXNUMP(v6);
     if (ecl_unlikely(!(v7)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v6);
    }
    v5end = ecl_fixnum(v6);
   }
   {
    cl_fixnum v6pos;
    {
     cl_fixnum v7;
     v7 = 0;
     v7 = ecl_fixnum(v3start);
     if (!((v7)<=(2305843009213693951))) { goto L22; }
     T0 = ecl_make_bool((v7)>=(0));
     goto L14;
L22:;
     T0 = ECL_NIL;
     goto L14;
     T0 = ECL_NIL;
     goto L14;
    }
L14:;
    if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[2],v3start);
    v6pos = ecl_fixnum(v3start);
    goto L26;
L25:;
    {
     ecl_character v7;
     {
      cl_fixnum v8;
      if (ecl_unlikely((v6pos)>=(v2string)->vector.dim))
           FEwrong_index(ECL_NIL,v2string,-1,ecl_make_fixnum(v6pos),(v2string)->vector.dim);
      v8 = v6pos;
      v7 = CHAR_CODE(ecl_aref_unsafe(v2string,v8));
     }
     ecl_function_dispatch(cl_env_copy,ECL_SYM("STREAM-WRITE-CHAR",1643))(2, v1stream, CODE_CHAR(v7)) /*  STREAM-WRITE-CHAR */;
    }
    {
     cl_object v7;
     v7 = ecl_make_integer((v6pos)+1);
     {
      cl_fixnum v8;
      v8 = 0;
      if (!(ECL_FIXNUMP(v7))) { goto L40; }
      v8 = ecl_fixnum(v7);
      if (!((v8)<=(2305843009213693951))) { goto L45; }
      T0 = ecl_make_bool((v8)>=(0));
      goto L37;
L45:;
      T0 = ECL_NIL;
      goto L37;
L40:;
      T0 = ECL_NIL;
      goto L37;
     }
L37:;
     if (ecl_unlikely(!((T0)!=ECL_NIL)))
         FEwrong_type_argument(VV[2],v7);
     v6pos = ecl_fixnum(v7);
    }
L26:;
    if ((v6pos)>=(v5end)) { goto L47; }
    goto L25;
L47:;
   }
  }
  value0 = v2string;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G114                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC72__g114(cl_narg narg, cl_object v1stream, cl_object v2string, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>4)) FEwrong_num_arguments_anonym();
 {
  cl_object v3start;
  cl_object v4end;
  va_list args; va_start(args,v2string);
  {
   int i = 2;
   if (i >= narg) {
    v3start = ecl_make_fixnum(0);
   } else {
    i++;
    v3start = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v4end = ECL_NIL;
   } else {
    i++;
    v4end = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = cl_write_string(6, v2string, v1stream, ECL_SYM("START",1310), v3start, ECL_SYM("END",1225), v4end);
  return value0;
 }
}
/*	local function G115                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC73__g115(cl_narg narg, cl_object v1stream, cl_object v2string, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>4)) FEwrong_num_arguments_anonym();
 {
  cl_object v3start;
  cl_object v4end;
  va_list args; va_start(args,v2string);
  {
   int i = 2;
   if (i >= narg) {
    v3start = ECL_NIL;
   } else {
    i++;
    v3start = va_arg(args,cl_object);
   }
   if (i >= narg) {
    v4end = ECL_NIL;
   } else {
    i++;
    v4end = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = L1bug_or_error(v1stream, ECL_SYM("STREAM-WRITE-STRING",1645));
  return value0;
 }
}
/*	local function G116                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC74__g116(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("STREAM-WRITE-CHAR",1643))(2, v1stream, CODE_CHAR(10)) /*  STREAM-WRITE-CHAR */;
  return value0;
 }
}
/*	local function G117                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC75__g117(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_terpri(v1stream);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G118                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC76__g118(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = L1bug_or_error(v1stream, ECL_SYM("STREAM-TERPRI",1640));
  return value0;
 }
}
/*	local function G119                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC77__g119(cl_narg narg, cl_object v1stream, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2direction;
  va_list args; va_start(args,v1stream);
  {
   int i = 1;
   if (i >= narg) {
    v2direction = ECL_SYM("INPUT",1254);
   } else {
    i++;
    v2direction = va_arg(args,cl_object);
   }
  }
  va_end(args);
  {
   cl_object v4;                                  /*  PREDICATE       */
   cl_object v5;                                  /*  KIND            */
   if (!(ecl_eql(v2direction,ECL_SYM("INPUT",1254)))) { goto L3; }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = _ecl_static_32;
   cl_env_copy->values[0] = ECL_SYM("INPUT-STREAM-P",1618);
   value0 = cl_env_copy->values[0];
   goto L2;
L3:;
   if (!(ecl_eql(v2direction,ECL_SYM("OUTPUT",1282)))) { goto L5; }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = _ecl_static_33;
   cl_env_copy->values[0] = ECL_SYM("OUTPUT-STREAM-P",1619);
   value0 = cl_env_copy->values[0];
   goto L2;
L5:;
   T0 = ecl_list1(v2direction);
   value0 = cl_error(9, ECL_SYM("SIMPLE-TYPE-ERROR",773), ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_34, ECL_SYM("FORMAT-ARGUMENTS",1239), T0, ECL_SYM("DATUM",1214), v2direction, ECL_SYM("EXPECTED-TYPE",1232), VV[3]);
L2:;
   v4 = value0;
   {
    const int v6 = cl_env_copy->nvalues;
    cl_object v7;
    v7 = (v6<=1)? ECL_NIL : cl_env_copy->values[1];
    v5 = v7;
   }
   if ((ecl_function_dispatch(cl_env_copy,v4)(1, v1stream))!=ECL_NIL) { goto L7; }
   T0 = cl_list(3, v5, v1stream, v2direction);
   T1 = cl_list(2, ECL_SYM("SATISFIES",735), v4);
   value0 = cl_error(9, ECL_SYM("SIMPLE-TYPE-ERROR",773), ECL_SYM("FORMAT-CONTROL",1240), _ecl_static_35, ECL_SYM("FORMAT-ARGUMENTS",1239), T0, ECL_SYM("DATUM",1214), v1stream, ECL_SYM("EXPECTED-TYPE",1232), T1);
   return value0;
L7:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G121                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC78__g121(cl_narg narg, cl_object v1stream, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2direction;
  va_list args; va_start(args,v1stream);
  {
   int i = 1;
   if (i >= narg) {
    v2direction = ECL_NIL;
   } else {
    i++;
    v2direction = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = L1bug_or_error(v1stream, ECL_SYM("STREAM-FILE-DESCRIPTOR",1625));
  return value0;
 }
}
/*	local function G122                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC79__g122(cl_narg narg, cl_object v1stream, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2direction;
  va_list args; va_start(args,v1stream);
  {
   int i = 1;
   if (i >= narg) {
    v2direction = ECL_SYM("INPUT",1254);
   } else {
    i++;
    v2direction = va_arg(args,cl_object);
   }
  }
  va_end(args);
  if (!(ecl_eql(v2direction,ECL_SYM("INPUT",1254)))) { goto L3; }
  T0 = cl_two_way_stream_input_stream(v1stream);
  goto L2;
L3:;
  if (!(ecl_eql(v2direction,ECL_SYM("OUTPUT",1282)))) { goto L5; }
  T0 = cl_two_way_stream_output_stream(v1stream);
  goto L2;
L5:;
  T0 = ECL_NIL;
L2:;
  value0 = ecl_function_dispatch(cl_env_copy,ECL_SYM("STREAM-FILE-DESCRIPTOR",1625))(2, T0, v2direction) /*  STREAM-FILE-DESCRIPTOR */;
  return value0;
 }
}
/*	local function G124                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC80__g124(cl_narg narg, cl_object v1stream, ...)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>2)) FEwrong_num_arguments_anonym();
 {
  cl_object v2direction;
  va_list args; va_start(args,v1stream);
  {
   int i = 1;
   if (i >= narg) {
    v2direction = ECL_SYM("INPUT",1254);
   } else {
    i++;
    v2direction = va_arg(args,cl_object);
   }
  }
  va_end(args);
  value0 = si_file_stream_fd(v1stream);
  return value0;
 }
}
/*	function definition for REDEFINE-CL-FUNCTIONS                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L81redefine_cl_functions()
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v1x;
   v1x = si_package_lock(_ecl_static_36, ECL_NIL);
   {
    cl_object v2cl_symbol;
    cl_object v3;
    v2cl_symbol = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(VV[4]))) FEtype_error_list(VV[4]);
    v3 = VV[4];
    {
     cl_object v4gray_package;
     v4gray_package = cl_find_package(_ecl_static_0);
L7:;
     v2cl_symbol = _ecl_car(v3);
     {
      cl_object v5;
      v5 = _ecl_cdr(v3);
      if (ecl_unlikely(!ECL_LISTP(v5))) FEtype_error_list(v5);
      v3 = v5;
     }
     T0 = cl_fdefinition(v2cl_symbol);
     if ((si_of_class_p(2, T0, ECL_SYM("GENERIC-FUNCTION",945)))!=ECL_NIL) { goto L15; }
     {
      cl_object v5gray_symbol;
      T0 = ecl_symbol_name(v2cl_symbol);
      v5gray_symbol = cl_find_symbol(2, T0, v4gray_package);
      T0 = cl_fdefinition(v5gray_symbol);
      si_fset(4, v2cl_symbol, T0, ECL_NIL, ECL_NIL);
      cl_unintern(2, v5gray_symbol, v4gray_package);
      cl_import(2, v2cl_symbol, v4gray_package);
      cl_export(2, v2cl_symbol, v4gray_package);
     }
L15:;
     if (!(ecl_endp(v3))) { goto L21; }
     goto L8;
L21:;
     goto L7;
L8:;
    }
   }
   si_package_lock(_ecl_static_36, v1x);
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}

#include "clos/streams.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclT9LBgSoBij8q9_eCukfE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CLOS;STREAMS.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclT9LBgSoBij8q9_eCukfE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 cl_import(1, ECL_SYM("ANSI-STREAM",1772));
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, ECL_SYM("STREAM-ADVANCE-TO-COLUMN",1621), VV[0], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[0], ECL_SYM("DOCUMENTATION",1222), _ecl_static_1) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, ECL_SYM("STREAM-CLEAR-INPUT",1622), VV[0], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[1], ECL_SYM("DOCUMENTATION",1222), _ecl_static_2) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, ECL_SYM("STREAM-CLEAR-OUTPUT",1623), VV[0], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[1], ECL_SYM("DOCUMENTATION",1222), _ecl_static_3) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, ECL_SYM("CLOSE",1616), VV[0], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[2], ECL_SYM("DOCUMENTATION",1222), _ecl_static_4) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, ECL_SYM("STREAM-ELEMENT-TYPE",1624), VV[0], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[1], ECL_SYM("DOCUMENTATION",1222), _ecl_static_5) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, ECL_SYM("STREAM-FINISH-OUTPUT",1627), VV[0], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[1], ECL_SYM("DOCUMENTATION",1222), _ecl_static_6) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, ECL_SYM("STREAM-FORCE-OUTPUT",1628), VV[0], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[1], ECL_SYM("DOCUMENTATION",1222), _ecl_static_7) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, ECL_SYM("STREAM-FRESH-LINE",1629), VV[0], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[1], ECL_SYM("DOCUMENTATION",1222), _ecl_static_8) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, ECL_SYM("INPUT-STREAM-P",1618), VV[0], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[1], ECL_SYM("DOCUMENTATION",1222), _ecl_static_9) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, VV[1], VV[0], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[1], ECL_SYM("DOCUMENTATION",1222), _ecl_static_10) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, ECL_SYM("STREAM-INTERACTIVE-P",1630), VV[0], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[1], ECL_SYM("DOCUMENTATION",1222), _ecl_static_11) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, ECL_SYM("STREAM-LINE-COLUMN",1631), VV[0], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[1], ECL_SYM("DOCUMENTATION",1222), _ecl_static_12) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(5, ECL_SYM("STREAM-LISTEN",1632), VV[0], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[1]) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, ECL_SYM("OPEN-STREAM-P",1620), VV[0], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[1], ECL_SYM("DOCUMENTATION",1222), _ecl_static_13) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, ECL_SYM("OUTPUT-STREAM-P",1619), VV[0], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[1], ECL_SYM("DOCUMENTATION",1222), _ecl_static_14) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, ECL_SYM("STREAM-PEEK-CHAR",1633), VV[0], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[1], ECL_SYM("DOCUMENTATION",1222), _ecl_static_15) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, ECL_SYM("STREAM-READ-BYTE",1634), VV[0], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[1], ECL_SYM("DOCUMENTATION",1222), _ecl_static_16) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, ECL_SYM("STREAM-READ-CHAR",1635), VV[0], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[1], ECL_SYM("DOCUMENTATION",1222), _ecl_static_17) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, ECL_SYM("STREAM-READ-CHAR-NO-HANG",1636), VV[0], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[1], ECL_SYM("DOCUMENTATION",1222), _ecl_static_18) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, ECL_SYM("STREAM-READ-LINE",1637), VV[0], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[1], ECL_SYM("DOCUMENTATION",1222), _ecl_static_19) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, ECL_SYM("STREAM-READ-SEQUENCE",1638), VV[0], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[3], ECL_SYM("DOCUMENTATION",1222), _ecl_static_20) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, ECL_SYM("STREAM-START-LINE-P",1639), VV[0], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[1], ECL_SYM("DOCUMENTATION",1222), _ecl_static_21) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, ECL_SYM("STREAM-TERPRI",1640), VV[0], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[1], ECL_SYM("DOCUMENTATION",1222), _ecl_static_22) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, ECL_SYM("STREAM-UNREAD-CHAR",1641), VV[0], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[4], ECL_SYM("DOCUMENTATION",1222), _ecl_static_23) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, ECL_SYM("STREAM-WRITE-BYTE",1642), VV[0], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[5], ECL_SYM("DOCUMENTATION",1222), _ecl_static_24) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, ECL_SYM("STREAM-WRITE-CHAR",1643), VV[0], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[4], ECL_SYM("DOCUMENTATION",1222), _ecl_static_25) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, ECL_SYM("STREAM-WRITE-STRING",1645), VV[0], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[6], ECL_SYM("DOCUMENTATION",1222), _ecl_static_26) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, ECL_SYM("STREAM-WRITE-SEQUENCE",1644), VV[0], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[3], ECL_SYM("DOCUMENTATION",1222), _ecl_static_27) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, ECL_SYM("STREAM-FILE-POSITION",1626), VV[0], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[7], ECL_SYM("DOCUMENTATION",1222), _ecl_static_28) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, ECL_SYM("STREAM-FILE-DESCRIPTOR",1625), VV[0], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[8], ECL_SYM("DOCUMENTATION",1222), _ecl_static_29) /*  ENSURE-GENERIC-FUNCTION */;
 {
  cl_object T0;
 T0 = cl_list(2, ECL_SYM("DOCUMENTATION",1222), _ecl_static_30);
 clos_load_defclass(ECL_SYM("FUNDAMENTAL-STREAM",1646), VVtemp[9], VVtemp[10], T0);
 }
 clos_load_defclass(ECL_SYM("FUNDAMENTAL-INPUT-STREAM",1647), VVtemp[11], ECL_NIL, ECL_NIL);
 clos_load_defclass(ECL_SYM("FUNDAMENTAL-OUTPUT-STREAM",1648), VVtemp[11], ECL_NIL, ECL_NIL);
 clos_load_defclass(ECL_SYM("FUNDAMENTAL-CHARACTER-STREAM",1649), VVtemp[11], ECL_NIL, ECL_NIL);
 clos_load_defclass(ECL_SYM("FUNDAMENTAL-BINARY-STREAM",1650), VVtemp[11], ECL_NIL, ECL_NIL);
 clos_load_defclass(ECL_SYM("FUNDAMENTAL-CHARACTER-INPUT-STREAM",1651), VVtemp[12], ECL_NIL, ECL_NIL);
 clos_load_defclass(ECL_SYM("FUNDAMENTAL-CHARACTER-OUTPUT-STREAM",1652), VVtemp[13], ECL_NIL, ECL_NIL);
 clos_load_defclass(ECL_SYM("FUNDAMENTAL-BINARY-INPUT-STREAM",1653), VVtemp[14], ECL_NIL, ECL_NIL);
 clos_load_defclass(ECL_SYM("FUNDAMENTAL-BINARY-OUTPUT-STREAM",1654), VVtemp[15], ECL_NIL, ECL_NIL);
 (void)0; /* No entry created for BUG-OR-ERROR */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC2__g0,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-ADVANCE-TO-COLUMN",1621), ECL_NIL, VVtemp[16], VVtemp[0], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC3__g6,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-CLEAR-INPUT",1622), ECL_NIL, VVtemp[17], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC4__g7,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-CLEAR-INPUT",1622), ECL_NIL, VVtemp[18], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC5__g8,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-CLEAR-INPUT",1622), ECL_NIL, VVtemp[19], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC6__g9,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-CLEAR-OUTPUT",1623), ECL_NIL, VVtemp[20], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC7__g10,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-CLEAR-OUTPUT",1623), ECL_NIL, VVtemp[18], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC8__g11,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-CLEAR-OUTPUT",1623), ECL_NIL, VVtemp[19], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC9__g16,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("CLOSE",1616), ECL_NIL, VVtemp[11], VVtemp[2], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC10__g19,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("CLOSE",1616), ECL_NIL, VVtemp[18], VVtemp[2], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC11__g20,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("CLOSE",1616), ECL_NIL, VVtemp[19], VVtemp[2], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC12__g21,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-ELEMENT-TYPE",1624), ECL_NIL, VVtemp[21], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC13__g22,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-ELEMENT-TYPE",1624), ECL_NIL, VVtemp[18], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC14__g23,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-ELEMENT-TYPE",1624), ECL_NIL, VVtemp[19], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC15__g24,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-FINISH-OUTPUT",1627), ECL_NIL, VVtemp[20], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC16__g25,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-FINISH-OUTPUT",1627), ECL_NIL, VVtemp[18], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC17__g26,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-FINISH-OUTPUT",1627), ECL_NIL, VVtemp[19], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC18__g27,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-FORCE-OUTPUT",1628), ECL_NIL, VVtemp[20], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC19__g28,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-FORCE-OUTPUT",1628), ECL_NIL, VVtemp[18], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC20__g29,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-FORCE-OUTPUT",1628), ECL_NIL, VVtemp[19], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC21__g30,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-FRESH-LINE",1629), ECL_NIL, VVtemp[22], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC22__g31,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-FRESH-LINE",1629), ECL_NIL, VVtemp[18], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC23__g32,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("INPUT-STREAM-P",1618), ECL_NIL, VVtemp[11], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC24__g33,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("INPUT-STREAM-P",1618), ECL_NIL, VVtemp[23], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC25__g34,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("INPUT-STREAM-P",1618), ECL_NIL, VVtemp[18], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC26__g35,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("INPUT-STREAM-P",1618), ECL_NIL, VVtemp[19], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC27__g36,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-INTERACTIVE-P",1630), ECL_NIL, VVtemp[18], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC28__g37,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-INTERACTIVE-P",1630), ECL_NIL, VVtemp[19], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC29__g38,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-LINE-COLUMN",1631), ECL_NIL, VVtemp[22], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC30__g39,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-LISTEN",1632), ECL_NIL, VVtemp[17], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC31__g40,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-LISTEN",1632), ECL_NIL, VVtemp[18], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC32__g41,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-LISTEN",1632), ECL_NIL, VVtemp[19], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC33__g42,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("OPEN-STREAM-P",1620), ECL_NIL, VVtemp[18], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC34__g43,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("OPEN-STREAM-P",1620), ECL_NIL, VVtemp[19], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC35__g44,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("OUTPUT-STREAM-P",1619), ECL_NIL, VVtemp[11], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC36__g45,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("OUTPUT-STREAM-P",1619), ECL_NIL, VVtemp[20], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC37__g46,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("OUTPUT-STREAM-P",1619), ECL_NIL, VVtemp[18], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC38__g47,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("OUTPUT-STREAM-P",1619), ECL_NIL, VVtemp[19], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC39__g48,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-PEEK-CHAR",1633), ECL_NIL, VVtemp[17], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC40__g49,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-PEEK-CHAR",1633), ECL_NIL, VVtemp[18], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC41__g50,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-PEEK-CHAR",1633), ECL_NIL, VVtemp[19], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC42__g51,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-READ-BYTE",1634), ECL_NIL, VVtemp[18], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC43__g52,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-READ-BYTE",1634), ECL_NIL, VVtemp[19], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC44__g53,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-READ-CHAR",1635), ECL_NIL, VVtemp[18], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC45__g54,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-READ-CHAR",1635), ECL_NIL, VVtemp[19], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC46__g55,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-UNREAD-CHAR",1641), ECL_NIL, VVtemp[24], VVtemp[4], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC47__g56,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-UNREAD-CHAR",1641), ECL_NIL, VVtemp[24], VVtemp[4], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC48__g57,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-READ-CHAR-NO-HANG",1636), ECL_NIL, VVtemp[17], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC49__g58,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-READ-CHAR-NO-HANG",1636), ECL_NIL, VVtemp[18], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC50__g59,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-READ-CHAR-NO-HANG",1636), ECL_NIL, VVtemp[19], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC51__g72,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-READ-LINE",1637), ECL_NIL, VVtemp[17], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC52__g82,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-READ-LINE",1637), ECL_NIL, VVtemp[18], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC53__g83,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-READ-LINE",1637), ECL_NIL, VVtemp[19], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC54__g84,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-READ-SEQUENCE",1638), ECL_NIL, VVtemp[25], VVtemp[26], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC55__g85,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-READ-SEQUENCE",1638), ECL_NIL, VVtemp[27], VVtemp[26], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC56__g86,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-READ-SEQUENCE",1638), ECL_NIL, VVtemp[24], VVtemp[26], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC57__g87,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-READ-SEQUENCE",1638), ECL_NIL, VVtemp[28], VVtemp[3], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC58__g88,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-START-LINE-P",1639), ECL_NIL, VVtemp[22], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC59__g89,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-FILE-POSITION",1626), ECL_NIL, VVtemp[18], VVtemp[7], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC60__g90,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-FILE-POSITION",1626), ECL_NIL, VVtemp[19], VVtemp[7], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC61__g91,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAMP",1617), ECL_NIL, VVtemp[1], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC62__g92,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAMP",1617), ECL_NIL, VVtemp[19], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC63__g93,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-WRITE-BYTE",1642), ECL_NIL, VVtemp[24], VVtemp[5], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC64__g94,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-WRITE-BYTE",1642), ECL_NIL, VVtemp[28], VVtemp[5], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC65__g95,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-WRITE-CHAR",1643), ECL_NIL, VVtemp[24], VVtemp[4], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC66__g96,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-WRITE-CHAR",1643), ECL_NIL, VVtemp[28], VVtemp[4], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC67__g97,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-WRITE-SEQUENCE",1644), ECL_NIL, VVtemp[16], VVtemp[29], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC68__g98,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-WRITE-SEQUENCE",1644), ECL_NIL, VVtemp[30], VVtemp[29], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC69__g99,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-WRITE-SEQUENCE",1644), ECL_NIL, VVtemp[24], VVtemp[29], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC70__g100,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-WRITE-SEQUENCE",1644), ECL_NIL, VVtemp[28], VVtemp[3], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC71__g101,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-WRITE-STRING",1645), ECL_NIL, VVtemp[16], VVtemp[31], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC72__g114,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-WRITE-STRING",1645), ECL_NIL, VVtemp[24], VVtemp[31], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC73__g115,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-WRITE-STRING",1645), ECL_NIL, VVtemp[28], VVtemp[6], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC74__g116,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-TERPRI",1640), ECL_NIL, VVtemp[22], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC75__g117,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-TERPRI",1640), ECL_NIL, VVtemp[18], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC76__g118,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-TERPRI",1640), ECL_NIL, VVtemp[19], VVtemp[1], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC77__g119,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-FILE-DESCRIPTOR",1625), VVtemp[32], VVtemp[19], VVtemp[33], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC78__g121,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-FILE-DESCRIPTOR",1625), ECL_NIL, VVtemp[19], VVtemp[8], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC79__g122,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-FILE-DESCRIPTOR",1625), ECL_NIL, VVtemp[34], VVtemp[33], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC80__g124,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("STREAM-FILE-DESCRIPTOR",1625), ECL_NIL, VVtemp[35], VVtemp[33], T0, ECL_T);
 }
 {
  cl_object T0;
 {
  cl_object v1p;
  v1p = cl_find_package(_ecl_static_0);
  cl_export(2, VVtemp[36], v1p);
  {
   cl_object v2;
   cl_object v3;
   cl_object v4s;
   T0 = cl_find_package(_ecl_static_36);
   v2 = si_packages_iterator(3, T0, VVtemp[37], ECL_T);
   v3 = ECL_NIL;
   v4s = ECL_NIL;
   goto L213;
L212:;
   value0 = ecl_function_dispatch(cl_env_copy,v2)(0);
   v3 = value0;
   {
    const int v5 = cl_env_copy->nvalues;
    cl_object v6;
    v6 = (v5<=1)? ECL_NIL : cl_env_copy->values[1];
    v4s = v6;
   }
   if ((v3)!=ECL_NIL) { goto L217; }
   goto L205;
L217:;
   if ((ecl_memql(v4s,VVtemp[38]))!=ECL_NIL) { goto L219; }
   cl_export(2, v4s, v1p);
L219:;
L213:;
   goto L212;
  }
 }
L205:;
 }
 ecl_cmp_defun(VV[9]);                            /*  REDEFINE-CL-FUNCTIONS */
 cl_set(VV[6],ECL_T);
}
