/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CMP;CMPMAP.LSP                                    */
#include <ecl/ecl-cmp.h>
#include "cmp/cmpmap.eclh"
/*	function definition for EXPAND-MAPCAR                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1expand_mapcar(cl_object v1whole)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v2;
   v2 = ecl_length(v1whole);
   if (!((v2)<(3))) { goto L1; }
  }
  T0 = ecl_fdefinition(ECL_SYM("PROGRAM-ERROR",672));
  T1 = ecl_function_dispatch(cl_env_copy,VV[9])(1, v1whole) /*  FIRT  */;
  si_signal_simple_error(5, T0, ECL_NIL, _ecl_static_1, T1, v1whole);
L1:;
  {
   cl_object v2which;
   v2which = ecl_car(v1whole);
   if (!((v2which)==(ECL_SYM("FUNCALL",394)))) { goto L5; }
   v1whole = ecl_cdr(v1whole);
   v2which = ecl_car(v1whole);
   if (!(ECL_CONSP(v2which))) { goto L5; }
   T0 = ecl_car(v2which);
   if (!((T0)==(ECL_SYM("FUNCTION",396)))) { goto L12; }
   v2which = ecl_cadr(v2which);
   goto L5;
L12:;
   value0 = v1whole;
   cl_env_copy->nvalues = 1;
   return value0;
L5:;
   {
    cl_object v3function;
    cl_object v4args;
    cl_object v5iterators;
    cl_object v6for_statements;
    cl_object v7in_or_on;
    cl_object v8do_or_collect;
    cl_object v9list_1_form;
    cl_object v10finally_form;
    v3function = ecl_cadr(v1whole);
    v4args = ecl_cddr(v1whole);
    v5iterators = ECL_NIL;
    v6for_statements = ECL_NIL;
    v7in_or_on = VV[0];
    v8do_or_collect = VV[1];
    v9list_1_form = ECL_NIL;
    v10finally_form = ECL_NIL;
    if ((v2which)==(ECL_SYM("MAPCAR",545))) { goto L23; }
    if (!((v2which)==(ECL_SYM("MAPLIST",549)))) { goto L25; }
    v7in_or_on = VV[2];
    goto L23;
L25:;
    if (!((v2which)==(ECL_SYM("MAPC",543)))) { goto L28; }
    v8do_or_collect = VV[3];
    goto L23;
L28:;
    if (!((v2which)==(ECL_SYM("MAPL",548)))) { goto L31; }
    v7in_or_on = VV[2];
    v8do_or_collect = VV[3];
    goto L23;
L31:;
    if (!((v2which)==(ECL_SYM("MAPCAN",544)))) { goto L36; }
    v8do_or_collect = ECL_SYM("NCONC",581);
    goto L23;
L36:;
    if (!((v2which)==(ECL_SYM("MAPCON",546)))) { goto L23; }
    v7in_or_on = VV[2];
    v8do_or_collect = ECL_SYM("NCONC",581);
L23:;
    if (!((v8do_or_collect)==(VV[3]))) { goto L43; }
    {
     cl_object v11var;
     v11var = cl_gensym(0);
     T0 = ecl_car(v4args);
     v9list_1_form = cl_list(4, VV[4], v11var, ECL_SYM("=",74), T0);
     T0 = ecl_cdr(v4args);
     v4args = CONS(v11var,T0);
     T0 = cl_list(2, ECL_SYM("RETURN",724), v11var);
     v10finally_form = cl_list(2, VV[5], T0);
    }
L43:;
    {
     cl_object v11;
     cl_object v12arg;
     cl_object v13;
     v11 = cl_reverse(v4args);
     v12arg = ECL_NIL;
     if (ecl_unlikely(!ECL_LISTP(v11))) FEtype_error_list(v11);
     v13 = v11;
L56:;
     if (!(ecl_endp(v13))) { goto L58; }
     goto L57;
L58:;
     v12arg = _ecl_car(v13);
     {
      cl_object v14;
      v14 = _ecl_cdr(v13);
      if (ecl_unlikely(!ECL_LISTP(v14))) FEtype_error_list(v14);
      v13 = v14;
     }
     {
      cl_object v14var;
      v14var = cl_gensym(0);
      v5iterators = CONS(v14var,v5iterators);
      v6for_statements = cl_listX(5, VV[6], v14var, v7in_or_on, v12arg, v6for_statements);
     }
     goto L56;
L57:;
    }
    T0 = cl_listX(3, ECL_SYM("FUNCALL",394), v3function, v5iterators);
    T1 = cl_listX(3, v8do_or_collect, T0, v10finally_form);
    T2 = cl_append(3, v9list_1_form, v6for_statements, T1);
    value0 = CONS(ECL_SYM("LOOP",512),T2);
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	local function MAPCAR                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC2mapcar(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_cdr(v1);
   value0 = L1expand_mapcar(v1);
   return value0;
  }
 }
}
/*	local function MAPC                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC3mapc(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_cdr(v1);
   value0 = L1expand_mapcar(v1);
   return value0;
  }
 }
}
/*	local function MAPCAN                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC4mapcan(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_cdr(v1);
   value0 = L1expand_mapcar(v1);
   return value0;
  }
 }
}
/*	local function MAPLIST                                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC5maplist(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_cdr(v1);
   value0 = L1expand_mapcar(v1);
   return value0;
  }
 }
}
/*	local function MAPL                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC6mapl(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_cdr(v1);
   value0 = L1expand_mapcar(v1);
   return value0;
  }
 }
}
/*	local function MAPCON                                         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC7mapcon(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = ecl_cdr(v1);
   value0 = L1expand_mapcar(v1);
   return value0;
  }
 }
}

#include "cmp/cmpmap.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclPJMOrzmToGmk9_XdqtVE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CMP;CMPMAP.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclPJMOrzmToGmk9_XdqtVE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[8]);                            /*  EXPAND-MAPCAR   */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC2mapcar,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("MAPCAR",545), ECL_SYM("COMPILER-MACRO",238), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC3mapc,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("MAPC",543), ECL_SYM("COMPILER-MACRO",238), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC4mapcan,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("MAPCAN",544), ECL_SYM("COMPILER-MACRO",238), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC5maplist,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("MAPLIST",549), ECL_SYM("COMPILER-MACRO",238), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC6mapl,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("MAPL",548), ECL_SYM("COMPILER-MACRO",238), T0);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC7mapcon,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 si_put_sysprop(ECL_SYM("MAPCON",546), ECL_SYM("COMPILER-MACRO",238), T0);
 }
}
