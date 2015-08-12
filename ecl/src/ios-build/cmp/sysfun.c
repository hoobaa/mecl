/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;SYSFUN.LSP                                    */
#include <ecl/ecl-cmp.h>
#include "cmp/sysfun.eclh"
/*	function definition for DEF-INLINE                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1def_inline(cl_narg narg, cl_object v1c__name, cl_object v2safety, cl_object v3c__arg_types, cl_object v4c__return_rep_type, cl_object v5c__expansion, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<5)) FEwrong_num_arguments_anonym();
 {
  cl_object v6c__one_liner;
  cl_object v7c__exact_return_type;
  cl_object v8c__inline_or_warn;
  cl_object v9c__multiple_values;
  ecl_va_list args; ecl_va_start(args,v5c__expansion,narg,5);
  {
   cl_object keyvars[8];
   cl_parse_key(args,4,L1def_inlinekeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   if (Null(keyvars[4])) {
    v6c__one_liner = ECL_T;
   } else {
    v6c__one_liner = keyvars[0];
   }
   v7c__exact_return_type = keyvars[1];
   v8c__inline_or_warn = keyvars[2];
   if (Null(keyvars[7])) {
    v9c__multiple_values = ECL_T;
   } else {
    v9c__multiple_values = keyvars[3];
   }
  }
  {
   cl_object v10c__arg_rep_types;
   v10c__arg_rep_types = ECL_NIL;
   if (!(ecl_eql(v2safety,VV[0]))) { goto L6; }
   v2safety = VV[1];
   goto L5;
L6:;
   if (!(ecl_eql(v2safety,VV[2]))) { goto L8; }
   v2safety = VV[3];
   goto L5;
L8:;
   if (!(ecl_eql(v2safety,VV[4]))) { goto L10; }
   v2safety = VV[5];
   goto L5;
L10:;
   v2safety = cl_error(1, _ecl_static_1);
L5:;
   {
    cl_object v11;
    cl_object v12;
    v11 = ECL_NIL;
    if (ecl_unlikely(!ECL_LISTP(v3c__arg_types))) FEtype_error_list(v3c__arg_types);
    v12 = v3c__arg_types;
    {
     cl_object v13;
     cl_object v14;
     v13 = ecl_list1(ECL_NIL);
     v14 = v13;
L19:;
     if (!(ecl_endp(v12))) { goto L21; }
     goto L20;
L21:;
     v11 = _ecl_car(v12);
     {
      cl_object v15;
      v15 = _ecl_cdr(v12);
      if (ecl_unlikely(!ECL_LISTP(v15))) FEtype_error_list(v15);
      v12 = v15;
     }
     if (ecl_unlikely(ECL_ATOM(v14))) FEtype_error_cons(v14);
     T0 = v14;
     if (!((v11)==(ECL_SYM("*",18)))) { goto L34; }
     T1 = v11;
     goto L33;
L34:;
     T1 = ecl_function_dispatch(cl_env_copy,VV[45])(1, v11) /*  LISP-TYPE->REP-TYPE */;
L33:;
     v14 = ecl_list1(T1);
     (ECL_CONS_CDR(T0)=v14,T0);
     goto L19;
L20:;
     v10c__arg_rep_types = ecl_cdr(v13);
     goto L13;
    }
   }
L13:;
   if (!((v4c__return_rep_type)==(ECL_T))) { goto L38; }
   v4c__return_rep_type = ECL_SYM("OBJECT",1278);
L38:;
   if (Null(v8c__inline_or_warn)) { goto L41; }
   si_put_sysprop(v1c__name, VV[6], ECL_T);
L41:;
   {
    cl_object v11c__return_type;
    cl_object v12c__inline_info;
    cl_object v13c__previous;
    if (!(ECL_CONSP(v4c__return_rep_type))) { goto L44; }
    T0 = ecl_car(v4c__return_rep_type);
    if (!((T0)==(ECL_SYM("VALUES",895)))) { goto L44; }
    v11c__return_type = ECL_T;
    goto L43;
L44:;
    v11c__return_type = ecl_function_dispatch(cl_env_copy,VV[46])(1, v4c__return_rep_type) /*  REP-TYPE->LISP-TYPE */;
L43:;
    v12c__inline_info = ecl_function_dispatch(cl_env_copy,VV[47])(18, ECL_SYM("NAME",1273), v1c__name, VV[7], v10c__arg_rep_types, VV[8], v4c__return_rep_type, VV[9], v11c__return_type, VV[10], v3c__arg_types, VV[11], v7c__exact_return_type, VV[12], v9c__multiple_values, VV[13], v6c__one_liner, VV[14], v5c__expansion) /*  MAKE-INLINE-INFO */;
    v13c__previous = si_get_sysprop(v1c__name, v2safety);
    T0 = CONS(v12c__inline_info,v13c__previous);
    value0 = si_put_sysprop(v1c__name, v2safety, T0);
    return value0;
   }
  }
 }
}

#include "cmp/sysfun.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclHwegKK0D3HSk9_Kr0UOE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;SYSFUN.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclHwegKK0D3HSk9_Kr0UOE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[40]);                           /*  DEF-INLINE      */
 {
  cl_object T0;
 {
  cl_object v1c__i;
  cl_object v2;
  v1c__i = ECL_NIL;
  if (ecl_unlikely(!ECL_LISTP(VVtemp[0]))) FEtype_error_list(VVtemp[0]);
  v2 = VVtemp[0];
L11:;
  v1c__i = _ecl_car(v2);
  {
   cl_object v3;
   v3 = _ecl_cdr(v2);
   if (ecl_unlikely(!ECL_LISTP(v3))) FEtype_error_list(v3);
   v2 = v3;
  }
  T0 = ecl_fdefinition(VV[15]);
  cl_apply(2, T0, v1c__i);
  if (!(ecl_endp(v2))) { goto L21; }
  goto L12;
L21:;
  goto L11;
L12:;
 }
 }
 si_select_package(_ecl_static_2);
 {
  cl_object T0;
 si_Xmake_special(VV[16]);
 if (ecl_boundp(cl_env_copy,VV[16])) { goto L26; }
 {
  struct ecl_stack_frame _ecl_inner_frame_aux;
   volatile cl_object _ecl_inner_frame = ecl_stack_frame_open(cl_env_copy,(cl_object)&_ecl_inner_frame_aux,0);
  {
   cl_object v1;
   v1 = _ecl_inner_frame;
   ecl_stack_frame_push(v1,ECL_SYM("MAKE-ARRAY",522));
   ecl_stack_frame_push(v1,ECL_SYM("VECTOR",898));
   ecl_stack_frame_push(v1,ECL_SYM("ARRAY-DIMENSIONS",99));
   ecl_stack_frame_push(v1,ECL_SYM("ARRAY-IN-BOUNDS-P",103));
   ecl_stack_frame_push(v1,ECL_SYM("ARRAY-ROW-MAJOR-INDEX",106));
   ecl_stack_frame_push(v1,ECL_SYM("BIT",123));
   ecl_stack_frame_push(v1,ECL_SYM("SBIT",736));
   ecl_stack_frame_push(v1,ECL_SYM("BIT-AND",124));
   ecl_stack_frame_push(v1,ECL_SYM("BIT-IOR",128));
   ecl_stack_frame_push(v1,ECL_SYM("BIT-XOR",136));
   ecl_stack_frame_push(v1,ECL_SYM("BIT-EQV",127));
   ecl_stack_frame_push(v1,ECL_SYM("BIT-NAND",129));
   ecl_stack_frame_push(v1,ECL_SYM("BIT-NOR",130));
   ecl_stack_frame_push(v1,ECL_SYM("BIT-ANDC1",125));
   ecl_stack_frame_push(v1,ECL_SYM("BIT-ANDC2",126));
   ecl_stack_frame_push(v1,ECL_SYM("BIT-ORC1",132));
   ecl_stack_frame_push(v1,ECL_SYM("BIT-ORC2",133));
   ecl_stack_frame_push(v1,ECL_SYM("BIT-NOT",131));
   ecl_stack_frame_push(v1,ECL_SYM("VECTOR-POP",899));
   ecl_stack_frame_push(v1,ECL_SYM("ADJUST-ARRAY",83));
   ecl_stack_frame_push(v1,ECL_SYM("DO-CHECK-TYPE",1786));
   ecl_stack_frame_push(v1,ECL_SYM("ECASE-ERROR",1783));
   ecl_stack_frame_push(v1,ECL_SYM("ETYPECASE-ERROR",1784));
   ecl_stack_frame_push(v1,ECL_SYM("WRONG-TYPE-ARGUMENT",1611));
   ecl_stack_frame_push(v1,ECL_SYM("CCASE-ERROR",1782));
   ecl_stack_frame_push(v1,ECL_SYM("CTYPECASE-ERROR",1785));
   ecl_stack_frame_push(v1,ECL_SYM("SETF-DEFINITION",1935));
   ecl_stack_frame_push(v1,ECL_SYM("SAFE-EVAL",1133));
   ecl_stack_frame_push(v1,ECL_SYM("ABORT",77));
   ecl_stack_frame_push(v1,ECL_SYM("CONTINUE",250));
   ecl_stack_frame_push(v1,ECL_SYM("MUFFLE-WARNING",571));
   ecl_stack_frame_push(v1,ECL_SYM("STORE-VALUE",798));
   ecl_stack_frame_push(v1,ECL_SYM("USE-VALUE",893));
   ecl_stack_frame_push(v1,ECL_SYM("BIND-SIMPLE-RESTARTS",2025));
   ecl_stack_frame_push(v1,ECL_SYM("BIND-SIMPLE-HANDLERS",2026));
   ecl_stack_frame_push(v1,ECL_SYM("ASSERT-FAILURE",1781));
   ecl_stack_frame_push(v1,ECL_SYM("DESCRIBE",299));
   ecl_stack_frame_push(v1,ECL_SYM("INSPECT",436));
   ecl_stack_frame_push(v1,ECL_SYM("READ-FROM-STRING",695));
   ecl_stack_frame_push(v1,ECL_SYM("WRITE-TO-STRING",923));
   ecl_stack_frame_push(v1,ECL_SYM("PRIN1-TO-STRING",659));
   ecl_stack_frame_push(v1,ECL_SYM("PRINC-TO-STRING",661));
   ecl_stack_frame_push(v1,ECL_SYM("Y-OR-N-P",924));
   ecl_stack_frame_push(v1,ECL_SYM("YES-OR-NO-P",925));
   ecl_stack_frame_push(v1,ECL_SYM("STRING-TO-OBJECT",1150));
   ecl_stack_frame_push(v1,ECL_SYM("UNION",882));
   ecl_stack_frame_push(v1,ECL_SYM("NUNION",609));
   ecl_stack_frame_push(v1,ECL_SYM("INTERSECTION",444));
   ecl_stack_frame_push(v1,ECL_SYM("NINTERSECTION",582));
   ecl_stack_frame_push(v1,ECL_SYM("SET-DIFFERENCE",744));
   ecl_stack_frame_push(v1,ECL_SYM("NSET-DIFFERENCE",590));
   ecl_stack_frame_push(v1,ECL_SYM("SET-EXCLUSIVE-OR",746));
   ecl_stack_frame_push(v1,ECL_SYM("NSET-EXCLUSIVE-OR",591));
   ecl_stack_frame_push(v1,ECL_SYM("SUBSETP",830));
   ecl_stack_frame_push(v1,ECL_SYM("RASSOC-IF",684));
   ecl_stack_frame_push(v1,ECL_SYM("RASSOC-IF-NOT",685));
   ecl_stack_frame_push(v1,ECL_SYM("ASSOC-IF",115));
   ecl_stack_frame_push(v1,ECL_SYM("ASSOC-IF-NOT",116));
   ecl_stack_frame_push(v1,ECL_SYM("MEMBER-IF",553));
   ecl_stack_frame_push(v1,ECL_SYM("MEMBER-IF-NOT",554));
   ecl_stack_frame_push(v1,ECL_SYM("SUBST-IF",832));
   ecl_stack_frame_push(v1,ECL_SYM("SUBST-IF-NOT",833));
   ecl_stack_frame_push(v1,ECL_SYM("NSUBST-IF",597));
   ecl_stack_frame_push(v1,ECL_SYM("NSUBST-IF-NOT",598));
   ecl_stack_frame_push(v1,ECL_SYM("LOGICAL-PATHNAME-TRANSLATIONS",499));
   ecl_stack_frame_push(v1,ECL_SYM("LOAD-LOGICAL-PATHNAME-TRANSLATIONS",488));
   ecl_stack_frame_push(v1,ECL_SYM("DECODE-UNIVERSAL-TIME",276));
   ecl_stack_frame_push(v1,ECL_SYM("ENCODE-UNIVERSAL-TIME",328));
   ecl_stack_frame_push(v1,ECL_SYM("GET-DECODED-TIME",403));
   ecl_stack_frame_push(v1,ECL_SYM("ENSURE-DIRECTORIES-EXIST",332));
   ecl_stack_frame_push(v1,ECL_SYM("SIMPLE-PROGRAM-ERROR",1143));
   ecl_stack_frame_push(v1,ECL_SYM("SIGNAL-SIMPLE-ERROR",1144));
   ecl_stack_frame_push(v1,ECL_SYM("PROVIDE",674));
   ecl_stack_frame_push(v1,ECL_SYM("REQUIRE",718));
   ecl_stack_frame_push(v1,ECL_SYM("ISQRT",448));
   ecl_stack_frame_push(v1,ECL_SYM("PHASE",640));
   ecl_stack_frame_push(v1,ECL_SYM("SIGNUM",762));
   ecl_stack_frame_push(v1,ECL_SYM("CIS",225));
   ecl_stack_frame_push(v1,ECL_SYM("ASIN",111));
   ecl_stack_frame_push(v1,ECL_SYM("ACOS",80));
   ecl_stack_frame_push(v1,ECL_SYM("ASINH",112));
   ecl_stack_frame_push(v1,ECL_SYM("ACOSH",81));
   ecl_stack_frame_push(v1,ECL_SYM("ATANH",118));
   ecl_stack_frame_push(v1,ECL_SYM("FFLOOR",350));
   ecl_stack_frame_push(v1,ECL_SYM("FCEILING",348));
   ecl_stack_frame_push(v1,ECL_SYM("FTRUNCATE",392));
   ecl_stack_frame_push(v1,ECL_SYM("FROUND",391));
   ecl_stack_frame_push(v1,ECL_SYM("LOGTEST",506));
   ecl_stack_frame_push(v1,ECL_SYM("BYTE",162));
   ecl_stack_frame_push(v1,ECL_SYM("BYTE-SIZE",164));
   ecl_stack_frame_push(v1,ECL_SYM("BYTE-POSITION",163));
   ecl_stack_frame_push(v1,ECL_SYM("LDB",457));
   ecl_stack_frame_push(v1,ECL_SYM("LDB-TEST",458));
   ecl_stack_frame_push(v1,ECL_SYM("MASK-FIELD",550));
   ecl_stack_frame_push(v1,ECL_SYM("DPB",318));
   ecl_stack_frame_push(v1,ECL_SYM("DEPOSIT-FIELD",298));
   ecl_stack_frame_push(v1,ECL_SYM("FIND-ALL-SYMBOLS",364));
   ecl_stack_frame_push(v1,ECL_SYM("APROPOS",90));
   ecl_stack_frame_push(v1,ECL_SYM("APROPOS-LIST",91));
   ecl_stack_frame_push(v1,ECL_SYM("FIND-RELATIVE-PACKAGE",1608));
   ecl_stack_frame_push(v1,ECL_SYM("PACKAGE-PARENT",1609));
   ecl_stack_frame_push(v1,ECL_SYM("PACKAGE-CHILDREN",1610));
   ecl_stack_frame_push(v1,ECL_SYM("UPGRADED-ARRAY-ELEMENT-TYPE",889));
   ecl_stack_frame_push(v1,ECL_SYM("UPGRADED-COMPLEX-PART-TYPE",890));
   ecl_stack_frame_push(v1,ECL_SYM("TYPEP",875));
   ecl_stack_frame_push(v1,ECL_SYM("SUBTYPEP",837));
   ecl_stack_frame_push(v1,ECL_SYM("COERCE",231));
   ecl_stack_frame_push(v1,ECL_SYM("DO-DEFTYPE",1584));
   ecl_stack_frame_push(v1,ECL_SYM("MAKE-SEQUENCE",533));
   ecl_stack_frame_push(v1,ECL_SYM("CONCATENATE",244));
   ecl_stack_frame_push(v1,ECL_SYM("MAP",541));
   ecl_stack_frame_push(v1,ECL_SYM("SOME",786));
   ecl_stack_frame_push(v1,ECL_SYM("EVERY",342));
   ecl_stack_frame_push(v1,ECL_SYM("NOTANY",585));
   ecl_stack_frame_push(v1,ECL_SYM("NOTEVERY",586));
   ecl_stack_frame_push(v1,ECL_SYM("MAP-INTO",542));
   ecl_stack_frame_push(v1,ECL_SYM("REDUCE",706));
   ecl_stack_frame_push(v1,ECL_SYM("FILL",361));
   ecl_stack_frame_push(v1,ECL_SYM("REPLACE",717));
   ecl_stack_frame_push(v1,ECL_SYM("REMOVE",710));
   ecl_stack_frame_push(v1,ECL_SYM("REMOVE-IF",712));
   ecl_stack_frame_push(v1,ECL_SYM("REMOVE-IF-NOT",713));
   ecl_stack_frame_push(v1,ECL_SYM("DELETE",291));
   ecl_stack_frame_push(v1,ECL_SYM("DELETE-IF",294));
   ecl_stack_frame_push(v1,ECL_SYM("DELETE-IF-NOT",295));
   ecl_stack_frame_push(v1,ECL_SYM("COUNT",266));
   ecl_stack_frame_push(v1,ECL_SYM("COUNT-IF",267));
   ecl_stack_frame_push(v1,ECL_SYM("COUNT-IF-NOT",268));
   ecl_stack_frame_push(v1,ECL_SYM("SUBSTITUTE",834));
   ecl_stack_frame_push(v1,ECL_SYM("SUBSTITUTE-IF",835));
   ecl_stack_frame_push(v1,ECL_SYM("SUBSTITUTE-IF-NOT",836));
   ecl_stack_frame_push(v1,ECL_SYM("NSUBSTITUTE",599));
   ecl_stack_frame_push(v1,ECL_SYM("NSUBSTITUTE-IF",600));
   ecl_stack_frame_push(v1,ECL_SYM("NSUBSTITUTE-IF-NOT",601));
   ecl_stack_frame_push(v1,ECL_SYM("FIND",363));
   ecl_stack_frame_push(v1,ECL_SYM("FIND-IF",365));
   ecl_stack_frame_push(v1,ECL_SYM("FIND-IF-NOT",366));
   ecl_stack_frame_push(v1,ECL_SYM("POSITION",644));
   ecl_stack_frame_push(v1,ECL_SYM("POSITION-IF",645));
   ecl_stack_frame_push(v1,ECL_SYM("POSITION-IF-NOT",646));
   ecl_stack_frame_push(v1,ECL_SYM("REMOVE-DUPLICATES",711));
   ecl_stack_frame_push(v1,ECL_SYM("DELETE-DUPLICATES",292));
   ecl_stack_frame_push(v1,ECL_SYM("MISMATCH",559));
   ecl_stack_frame_push(v1,ECL_SYM("SEARCH",739));
   ecl_stack_frame_push(v1,ECL_SYM("SORT",787));
   ecl_stack_frame_push(v1,ECL_SYM("STABLE-SORT",793));
   ecl_stack_frame_push(v1,ECL_SYM("MERGE",555));
   ecl_stack_frame_push(v1,ECL_SYM("CONSTANTLY",253));
   ecl_stack_frame_push(v1,ECL_SYM("DO-DEFSETF",1933));
   ecl_stack_frame_push(v1,ECL_SYM("DO-DEFINE-SETF-METHOD",1934));
   ecl_stack_frame_push(v1,ECL_SYM("SYSTEM",1160));
   ecl_stack_frame_push(v1,ECL_SYM("PPRINT-FILL",650));
   ecl_stack_frame_push(v1,ECL_SYM("COPY-PPRINT-DISPATCH",258));
   ecl_stack_frame_push(v1,ECL_SYM("PPRINT-DISPATCH",648));
   ecl_stack_frame_push(v1,ECL_SYM("PPRINT-LINEAR",652));
   ecl_stack_frame_push(v1,ECL_SYM("PPRINT-NEWLINE",654));
   ecl_stack_frame_push(v1,ECL_SYM("PPRINT-TAB",656));
   ecl_stack_frame_push(v1,ECL_SYM("PPRINT-TABULAR",657));
   ecl_stack_frame_push(v1,ECL_SYM("SET-PPRINT-DISPATCH",748));
   ecl_stack_frame_push(v1,ECL_SYM("PPRINT-INDENT",651));
   T0 = ecl_append(VVtemp[1],VVtemp[2]);
   ecl_stack_frame_push(v1,T0);
   T0 = (ECL_SYM("LIST*",482)->symbol.gfdef);cl_env_copy->values[0]=ecl_apply_from_stack_frame(v1,T0);
   value0 = cl_env_copy->values[0];
  }
  ecl_stack_frame_close(_ecl_inner_frame);
 }
 cl_set(VV[16],value0);
L26:;
 }
 {
  cl_object T0, T1;
 T0 = ecl_append(VVtemp[3],VVtemp[4]);
 T1 = cl_listX(26, VV[17], VV[18], VV[19], VV[20], VV[21], VV[22], VV[23], VV[24], VV[25], VV[26], VV[27], VV[28], VV[29], VV[30], VV[31], VV[32], VV[33], VV[34], VV[35], ECL_SYM("SEQUENCE-COUNT",1775), VV[36], VV[37], VV[38], VV[39], ECL_SYM("TRACED-OLD-DEFINITION",1831), T0);
 (cl_env_copy->function=(ECL_SYM("PROCLAIM",666)->symbol.gfdef))->cfun.entry(1, T1) /*  PROCLAIM */;
 }
}
