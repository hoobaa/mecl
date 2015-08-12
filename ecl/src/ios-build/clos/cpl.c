/*	Compiler: ECL 12.12.1                                         */
/*	Source: SRC:CLOS;CPL.LSP                                      */
#include <ecl/ecl-cmp.h>
#include "clos/cpl.eclh"
/*	function definition for COMPUTE-CLOS-CLASS-PRECEDENCE-LIST    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7compute_clos_class_precedence_list(cl_object v1new_class, cl_object v2superclasses)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (!(v2superclasses==ECL_NIL)) { goto L1; }
  value0 = ecl_list1(v1new_class);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  T0 = ecl_cdr(v2superclasses);
  if (!(ecl_endp(T0))) { goto L3; }
  {
   cl_object v3class;
   v3class = ecl_car(v2superclasses);
   T0 = cl_slot_value(v3class, VV[1]);
   value0 = CONS(v1new_class,T0);
   cl_env_copy->nvalues = 1;
   return value0;
  }
L3:;
  {
   cl_object v5;                                  /*  CLASS-LIST      */
   cl_object v6;                                  /*  PRECEDENCE-LISTS */
   value0 = LC1walk_supers(v2superclasses);
   v5 = value0;
   {
    const int v7 = cl_env_copy->nvalues;
    cl_object v8;
    v8 = (v7<=1)? ECL_NIL : cl_env_copy->values[1];
    v6 = v8;
   }
   {
    cl_object v7cpl;
    v7cpl = ecl_list1(v1new_class);
    goto L10;
L9:;
    {
     cl_object v8candidates;
     cl_object v9next;
     v8candidates = LC4free_elements(v5, v6);
     v9next = LC5next_element(v8candidates, v7cpl);
     if ((v9next)!=ECL_NIL) { goto L15; }
     LC2cycle_error(v1new_class);
L15:;
     v6 = LC6delete_class(v9next, v6);
     v5 = cl_delete(2, v9next, v5);
     v7cpl = CONS(v9next,v7cpl);
    }
L10:;
    if (v5==ECL_NIL) { goto L22; }
    goto L9;
L22:;
    if (Null(v6)) { goto L24; }
    value0 = LC2cycle_error(v1new_class);
    return value0;
L24:;
    value0 = cl_nreverse(v7cpl);
    return value0;
   }
  }
 }
}
/*	local function DELETE-CLASS                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC6delete_class(cl_object v1class, cl_object v2precedence_lists)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3l;
   v3l = v2precedence_lists;
   goto L4;
L3:;
   {
    cl_object v4one_list;
    v4one_list = ecl_car(v3l);
    T0 = ecl_car(v4one_list);
    if (!((v1class)==(T0))) { goto L6; }
    {
     cl_object v5;
     v5 = ecl_cdr(v4one_list);
     if (ecl_unlikely(ECL_ATOM(v3l))) FEtype_error_cons(v3l);
     T0 = v3l;
     (ECL_CONS_CAR(T0)=v5,T0);
    }
   }
L6:;
   v3l = ecl_cdr(v3l);
L4:;
   if (v3l==ECL_NIL) { goto L15; }
   goto L3;
L15:;
   value0 = cl_delete(2, ECL_NIL, v2precedence_lists);
   return value0;
  }
 }
}
/*	local function NEXT-ELEMENT                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC5next_element(cl_object v1free_list, cl_object v2cpl)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (v2cpl==ECL_NIL) { goto L3; }
  if (ecl_endp(v1free_list)) { goto L3; }
  T0 = ecl_cdr(v1free_list);
  if (!(ecl_endp(T0))) { goto L1; }
  goto L2;
L3:;
L2:;
  value0 = ecl_car(v1free_list);
  cl_env_copy->nvalues = 1;
  return value0;
L1:;
  {
   cl_object v3;
   v3 = v2cpl;
   goto L9;
L8:;
   {
    cl_object v4i;
    v4i = ecl_car(v3);
    {
     cl_object v5;
     v5 = cl_slot_value(v4i, VV[0]);
     goto L17;
L16:;
     {
      cl_object v6j;
      v6j = ecl_car(v5);
      if (Null(ecl_memql(v6j,v1free_list))) { goto L21; }
      value0 = v6j;
      cl_env_copy->nvalues = 1;
      return value0;
L21:;
     }
     v5 = ecl_cdr(v5);
L17:;
     if (Null(v5)) { goto L25; }
     goto L16;
L25:;
    }
   }
   v3 = ecl_cdr(v3);
L9:;
   if (Null(v3)) { goto L29; }
   goto L8;
L29:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function FREE-ELEMENTS                                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC4free_elements(cl_object v1class_list, cl_object v2precedence_lists)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3output;
   v3output = ECL_NIL;
   {
    cl_object v4;
    v4 = v1class_list;
    goto L6;
L5:;
    {
     cl_object v5class;
     v5class = ecl_car(v4);
     if (Null(LC3has_no_precedent(v5class, v2precedence_lists))) { goto L10; }
     v3output = CONS(v5class,v3output);
L10:;
    }
    v4 = ecl_cdr(v4);
L6:;
    if (Null(v4)) { goto L15; }
    goto L5;
L15:;
   }
   value0 = v3output;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function HAS-NO-PRECEDENT                               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC3has_no_precedent(cl_object v1class, cl_object v2precedence_lists)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   v3 = v2precedence_lists;
   goto L4;
L3:;
   {
    cl_object v4partial_order;
    v4partial_order = ecl_car(v3);
    T0 = ecl_cdr(v4partial_order);
    if (Null(ecl_memql(v1class,T0))) { goto L8; }
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
L8:;
   }
   v3 = ecl_cdr(v3);
L4:;
   if (Null(v3)) { goto L12; }
   goto L3;
L12:;
   value0 = ECL_T;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function CYCLE-ERROR                                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC2cycle_error(cl_object v1class)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = (cl_env_copy->function=(ECL_SYM("CLASS-NAME",934)->symbol.gfdef))->cfun.entry(1, v1class) /*  CLASS-NAME */;
  value0 = cl_error(2, _ecl_static_1, T0);
  return value0;
 }
}
/*	local function WALK-SUPERS                                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC1walk_supers(cl_object v1superclasses)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2;
   cl_object v3class_list;
   cl_object v4precedence_lists;
   v2 = ecl_list1(v1superclasses);
   v3class_list = ECL_NIL;
   v4precedence_lists = v2;
L4:;
   if ((v1superclasses)!=ECL_NIL) { goto L6; }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v4precedence_lists;
   cl_env_copy->values[0] = v3class_list;
   return cl_env_copy->values[0];
L6:;
   {
    cl_object v5next_class;
    {
     cl_object v6;
     v6 = v1superclasses;
     if (ecl_unlikely(!ECL_LISTP(v6))) FEtype_error_list(v6);
     if (Null(v6)) { goto L12; }
     {
      cl_object v7;
      v7 = ECL_CONS_CDR(v6);
      v1superclasses = v7;
      v6 = ECL_CONS_CAR(v6);
     }
L12:;
     v5next_class = v6;
    }
    if ((ecl_memql(v5next_class,v3class_list))!=ECL_NIL) { goto L5; }
    {
     cl_object v6more_classes;
     v6more_classes = cl_slot_value(v5next_class, VV[0]);
     v3class_list = CONS(v5next_class,v3class_list);
     T0 = CONS(v5next_class,v6more_classes);
     v4precedence_lists = CONS(T0,v4precedence_lists);
     v1superclasses = ecl_append(v6more_classes,v1superclasses);
    }
   }
L5:;
   goto L4;
  }
 }
}

#include "clos/cpl.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclPtSxnn2WOLgq9_xosTOE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("SRC:CLOS;CPL.LSP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclPtSxnn2WOLgq9_xosTOE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 ecl_cmp_defun(VV[3]);                            /*  COMPUTE-CLOS-CLASS-PRECEDENCE-LIST */
}
