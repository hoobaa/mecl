/*	Compiler: ECL 12.12.1                                         */
/*	Source: EXT:SOCKETS;SOCKETS.LISP                              */
#include <ecl/ecl-cmp.h>
#include "ext/sockets.eclh"
/*	function definition for FF-SOCKET                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L1ff_socket(cl_object v1, cl_object v2, cl_object v3)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   int v4;
   ecl_disable_interrupts();v4=socket(ecl_to_int(v1),ecl_to_int(v2),ecl_to_int(v3));ecl_enable_interrupts();
   value0 = ecl_make_int(v4);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for FF-LISTEN                             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L2ff_listen(cl_object v1, cl_object v2)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   int v3;
   ecl_disable_interrupts();v3=listen(ecl_to_int(v1),ecl_to_int(v2));ecl_enable_interrupts();
   value0 = ecl_make_int(v3);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for FF-CLOSE                              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L3ff_close(cl_object v1)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   int v2;
   ecl_disable_interrupts();v2=close(ecl_to_int(v1));ecl_enable_interrupts();
   value0 = ecl_make_int(v2);
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for SPLIT                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L5split(cl_narg narg, cl_object v1string, ...)
{
 cl_object T0, T1;
 cl_object env0;
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 if (ecl_unlikely(narg>3)) FEwrong_num_arguments_anonym();
 {
  cl_object v2max;
  va_list args; va_start(args,v1string);
  {
   int i = 1;
   if (i >= narg) {
    v2max = ECL_NIL;
   } else {
    i++;
    v2max = va_arg(args,cl_object);
   }
   if (i >= narg) {
    env0 = ECL_NIL;
    CLV0 = env0 = CONS(VV[7],env0);               /*  WS              */
   } else {
    i++;
    env0 = ECL_NIL;
    CLV0 = env0 = CONS(va_arg(args,cl_object),env0); /*  WS           */
   }
  }
  va_end(args);
  {cl_object v3;
   v3 = ECL_NIL;
   v3 = ecl_make_cclosure_va((cl_objectfn)LC4is_ws,env0,Cblock);
   {
    cl_object v4start;
    v4start = ECL_NIL;
    {
     cl_object v5index;
     v5index = ECL_NIL;
     {
      cl_fixnum v6word_count;
      v6word_count = 0;
      {
       cl_object v7;
       cl_object v8;
       v7 = ecl_list1(ECL_NIL);
       v8 = v7;
       v4start = cl_position_if_not(2, v3, v1string);
L7:;
       if (Null(v4start)) { goto L14; }
       if (Null(v2max)) { goto L16; }
       T0 = ecl_make_integer((v6word_count)+1);
       if (!(ecl_number_equalp(T0,v2max))) { goto L16; }
       v5index = ECL_NIL;
       goto L12;
L16:;
       v5index = cl_position_if(4, v3, v1string, ECL_SYM("START",1310), v4start);
       goto L12;
L14:;
       v5index = ECL_NIL;
       goto L12;
L12:;
       if ((v4start)!=ECL_NIL) { goto L19; }
       goto L8;
L19:;
       if (ecl_unlikely(ECL_ATOM(v8))) FEtype_error_cons(v8);
       T0 = v8;
       T1 = cl_subseq(3, v1string, v4start, v5index);
       v8 = ecl_list1(T1);
       (ECL_CONS_CDR(T0)=v8,T0);
       {
        cl_object v9;
        v9 = ecl_make_integer((v6word_count)+1);
        {
         bool v10;
         v10 = ECL_FIXNUMP(v9);
         if (ecl_unlikely(!(v10)))
         FEwrong_type_argument(ECL_SYM("FIXNUM",372),v9);
        }
        v6word_count = ecl_fixnum(v9);
       }
       if ((v5index)!=ECL_NIL) { goto L29; }
       goto L8;
L29:;
       v4start = cl_position_if_not(4, v3, v1string, ECL_SYM("START",1310), v5index);
       goto L7;
L8:;
       value0 = ecl_cdr(v7);
       cl_env_copy->nvalues = 1;
       return value0;
      }
     }
    }
   }
  }
 }
}
/*	closure IS-WS                                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC4is_ws(cl_narg narg, cl_object v1char, ...)
{
 cl_object CLV0
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV0 = env0;                                     /*  WS              */
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=1)) FEwrong_num_arguments_anonym();
 {
TTL:
  {
   cl_object v2;
   v2 = si_make_seq_iterator(2, ECL_CONS_CAR(CLV0), ecl_make_fixnum(0));
L2:;
   if ((v2)!=ECL_NIL) { goto L4; }
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
L4:;
   {
    cl_object v3;
    v3 = si_seq_iterator_ref(ECL_CONS_CAR(CLV0), v2);
    if (!(ecl_eql(v1char,v3))) { goto L6; }
    value0 = v3;
    cl_env_copy->nvalues = 1;
    return value0;
   }
L6:;
   v2 = si_seq_iterator_next(ECL_CONS_CAR(CLV0), v2);
   goto L2;
  }
 }
 }
}
/*	local function G28                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC6__g28(cl_object v1host_ent)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[162])(1, v1host_ent) /*  HOST-ENT-ADDRESSES */;
  value0 = ecl_car(T0);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for GET-HOST-BY-NAME                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L7get_host_by_name(cl_object v1host_name)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2host_ent;
   v2host_ent = (cl_env_copy->function=(ECL_SYM("MAKE-INSTANCE",949)->symbol.gfdef))->cfun.entry(1, VV[9]) /*  MAKE-INSTANCE */;
   {
    cl_object v3;
    v3 = si_copy_to_simple_base_string(v1host_name);
    T0 = ecl_fdefinition(VV[164]);
    T1 = ecl_fdefinition(VV[165]);
    T2 = ecl_fdefinition(VV[166]);
    T3 = ecl_fdefinition(VV[167]);
    {
     cl_object v4;
     
{
	struct hostent *hostent = gethostbyname(ecl_base_string_pointer_safe(v3));

	if (hostent != NULL) {
 	        char **aliases;
                char **addrs;
                cl_object aliases_list = ECL_NIL;
                cl_object addr_list = ECL_NIL;
                int length = hostent->h_length;

		funcall(3,T0,make_simple_base_string(hostent->h_name),v2host_ent);
                funcall(3,T2,ecl_make_integer(hostent->h_addrtype),v2host_ent);

                for (aliases = hostent->h_aliases; *aliases != NULL; aliases++) {
                        aliases_list = CONS(make_simple_base_string(*aliases),aliases_list);
                }
                funcall(3,T1,aliases_list,v2host_ent);

                for (addrs = hostent->h_addr_list; *addrs != NULL; addrs++) {
                        int pos;
                        cl_object vector = funcall(2,ECL_SYM("MAKE-ARRAY",522),MAKE_FIXNUM(length));
                        for (pos = 0; pos < length; pos++)
                                ecl_aset(vector, pos, MAKE_FIXNUM((unsigned char)((*addrs)[pos])));
                        addr_list = CONS(vector, addr_list);


                }
                funcall(3,T3,addr_list,v2host_ent);

                v4= v2host_ent;
	} else {
		v4= ECL_NIL;
	}
}
     if (Null(v4)) { goto L2; }
    }
   }
   value0 = v2host_ent;
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
   value0 = L45name_service_error(_ecl_static_2);
   return value0;
  }
 }
}
/*	function definition for GET-HOST-BY-ADDRESS                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L8get_host_by_address(cl_object v1address)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  goto L3;
L2:;
  si_assert_failure(1, VV[13]);
L3:;
  if (!(ECL_VECTORP(v1address))) { goto L9; }
  {
   cl_fixnum v2;
   v2 = ecl_length(v1address);
   if ((v2)==(4)) { goto L6; }
   goto L7;
  }
L9:;
  goto L7;
L7:;
  goto L2;
L6:;
  {
   cl_object v2host_ent;
   v2host_ent = (cl_env_copy->function=(ECL_SYM("MAKE-INSTANCE",949)->symbol.gfdef))->cfun.entry(1, VV[9]) /*  MAKE-INSTANCE */;
   T0 = ecl_fdefinition(VV[164]);
   T1 = ecl_fdefinition(VV[165]);
   T2 = ecl_fdefinition(VV[166]);
   T3 = ecl_fdefinition(VV[167]);
   {
    cl_object v3;
    
{
	unsigned char vector[4];
	struct hostent *hostent;
	vector[0] = fixint(ecl_aref(v1address,0));
	vector[1] = fixint(ecl_aref(v1address,1));
	vector[2] = fixint(ecl_aref(v1address,2));
	vector[3] = fixint(ecl_aref(v1address,3));
	ecl_disable_interrupts();
	hostent = gethostbyaddr(wincoerce(const char *, vector),4,AF_INET);
	ecl_enable_interrupts();

	if (hostent != NULL) {
 	        char **aliases;
                char **addrs;
                cl_object aliases_list = ECL_NIL;
                cl_object addr_list = ECL_NIL;
                int length = hostent->h_length;

		funcall(3,T0,make_simple_base_string(hostent->h_name),v2host_ent);
                funcall(3,T2,ecl_make_integer(hostent->h_addrtype),v2host_ent);

                for (aliases = hostent->h_aliases; *aliases != NULL; aliases++) {
                        aliases_list = CONS(make_simple_base_string(*aliases),aliases_list);
                }
                funcall(3,T1,aliases_list,v2host_ent);

                for (addrs = hostent->h_addr_list; *addrs != NULL; addrs++) {
                        int pos;
                        cl_object vector = funcall(2,ECL_SYM("MAKE-ARRAY",522),MAKE_FIXNUM(length));
                        for (pos = 0; pos < length; pos++)
                                ecl_aset(vector, pos, MAKE_FIXNUM((unsigned char)((*addrs)[pos])));
                        addr_list = CONS(vector, addr_list);


                }
                funcall(3,T3,addr_list,v2host_ent);

                v3= v2host_ent;
	} else {
		v3= ECL_NIL;
	}
}
    if (Null(v3)) { goto L12; }
   }
   value0 = v2host_ent;
   cl_env_copy->nvalues = 1;
   return value0;
L12:;
   value0 = L45name_service_error(_ecl_static_3);
   return value0;
  }
 }
}
/*	local function G32                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC9__g32()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = cl_error(1, _ecl_static_4);
  return value0;
 }
}
/*	local function G33                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC11__g33(cl_object v1object, cl_object v2stream)
{
 cl_object env0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
  env0 = ECL_NIL;
  CLV0 = env0 = CONS(v1object,env0);              /*  OBJECT          */
  CLV1 = env0 = CONS(v2stream,env0);              /*  STREAM          */
  {cl_object v3;
   v3 = ECL_NIL;
   v3 = ecl_make_cclosure_va((cl_objectfn)LC10si___print_unreadable_object_body_,env0,Cblock);
   value0 = si_print_unreadable_object_function(ECL_CONS_CAR(CLV0), ECL_CONS_CAR(CLV1), ECL_T, ECL_T, v3);
   return value0;
  }
 }
}
/*	closure .PRINT-UNREADABLE-OBJECT-BODY.                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC10si___print_unreadable_object_body_(cl_narg narg, ...)
{
 cl_object T0;
 cl_object CLV0, CLV1
 ;
 const cl_env_ptr cl_env_copy = ecl_process_env();cl_object env0 = cl_env_copy->function->cclosure.env;
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 /* Scanning closure data ... */
 CLV1 = env0;                                     /*  STREAM          */
 CLV0 = _ecl_cdr(CLV1);
 { /* ... closure scanning finished */
 if (ecl_unlikely(narg!=0)) FEwrong_num_arguments_anonym();
 {
TTL:
  ecl_princ_str("descriptor ",ECL_CONS_CAR(CLV1));
  T0 = cl_slot_value(ECL_CONS_CAR(CLV0), VV[16]);
  value0 = ecl_princ(T0,ECL_CONS_CAR(CLV1));
  cl_env_copy->nvalues = 1;
  return value0;
 }
 }
}
/*	local function G48                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC12__g48(cl_narg narg, cl_object v1socket, cl_object v2slot_names, ...)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3protocol;
  cl_object v4type;
  ecl_va_list args; ecl_va_start(args,v2slot_names,narg,2);
  {
   cl_object keyvars[4];
   cl_parse_key(args,2,LC12__g48keys,keyvars,NULL,TRUE);
   ecl_va_end(args);
   v3protocol = keyvars[0];
   v4type = keyvars[1];
  }
  {
   cl_object v5proto_num;
   cl_object v6fd;
   if (Null(v3protocol)) { goto L2; }
   if (Null(cl_keywordp(v3protocol))) { goto L2; }
   T0 = ecl_symbol_name(v3protocol);
   T1 = cl_string_downcase(1, T0);
   v5proto_num = L17get_protocol_by_name(T1);
   goto L1;
L2:;
   if (Null(v3protocol)) { goto L5; }
   v5proto_num = v3protocol;
   goto L1;
L5:;
   v5proto_num = ecl_make_fixnum(0);
L1:;
   if (Null(cl_slot_boundp(v1socket, VV[16]))) { goto L12; }
   value0 = ecl_function_dispatch(cl_env_copy,VV[171])(1, v1socket) /*  SOCKET-FILE-DESCRIPTOR */;
   goto L10;
L12:;
   value0 = ECL_NIL;
   goto L10;
L10:;
   if ((value0)!=ECL_NIL) { goto L9; }
   T0 = ecl_function_dispatch(cl_env_copy,VV[172])(1, v1socket) /*  SOCKET-FAMILY */;
   {
    cl_object v7;
    value0 = v4type;
    if ((value0)!=ECL_NIL) { goto L17; }
    v7 = ecl_function_dispatch(cl_env_copy,VV[173])(1, v1socket) /*  SOCKET-TYPE */;
    goto L15;
L17:;
    v7 = value0;
    goto L15;
L15:;
    if (!(ecl_eql(v7,VV[17]))) { goto L19; }
    T1 = ecl_make_int(SOCK_DGRAM);
    goto L14;
L19:;
    if (!(ecl_eql(v7,ECL_SYM("STREAM",1313)))) { goto L22; }
    T1 = ecl_make_int(SOCK_STREAM);
    goto L14;
L22:;
    T1 = si_ecase_error(v7, VV[20]);
   }
L14:;
   v6fd = L1ff_socket(T0, T1, v5proto_num);
   goto L7;
L9:;
   v6fd = value0;
   goto L7;
L7:;
   if (!(ecl_number_equalp(v6fd,ecl_make_fixnum(-1)))) { goto L25; }
   L44socket_error(_ecl_static_7);
L25:;
   (cl_env_copy->function=ECL_CONS_CAR(VV[174]))->cfun.entry(3, v6fd, v1socket, VV[16]) /*  (SETF SLOT-VALUE) */;
   value0 = (cl_env_copy->function=ECL_CONS_CAR(VV[174]))->cfun.entry(3, v5proto_num, v1socket, VV[21]) /*  (SETF SLOT-VALUE) */;
   return value0;
  }
 }
}
/*	local function G59                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC13__g59(cl_object v1socket, cl_object v2backlog)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3r;
   T0 = ecl_function_dispatch(cl_env_copy,VV[171])(1, v1socket) /*  SOCKET-FILE-DESCRIPTOR */;
   v3r = L2ff_listen(T0, v2backlog);
   if (!(ecl_number_equalp(v3r,ecl_make_fixnum(-1)))) { goto L2; }
   value0 = L44socket_error(_ecl_static_21);
   return value0;
L2:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G60                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC14__g60(cl_object v1socket)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[171])(1, v1socket) /*  SOCKET-FILE-DESCRIPTOR */;
  value0 = L3ff_close(T0);
  return value0;
 }
}
/*	local function G67                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC15__g67(cl_object v1socket)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2fd;
   v2fd = ecl_function_dispatch(cl_env_copy,VV[171])(1, v1socket) /*  SOCKET-FILE-DESCRIPTOR */;
   if ((v2fd)==(ecl_make_fixnum(-1))) { goto L2; }
   if (Null(cl_slot_boundp(v1socket, ECL_SYM("STREAM",799)))) { goto L5; }
   {
    cl_object v3stream;
    v3stream = cl_slot_value(v1socket, ECL_SYM("STREAM",799));
    T0 = cl_two_way_stream_input_stream(v3stream);
    cl_close(1, T0);
    T0 = cl_two_way_stream_output_stream(v3stream);
    cl_close(1, T0);
   }
   cl_slot_makunbound(v1socket, ECL_SYM("STREAM",799));
   goto L4;
L5:;
   T0 = ecl_function_dispatch(cl_env_copy,VV[33])(1, v1socket) /*  SOCKET-CLOSE-LOW-LEVEL */;
   if (!(ecl_number_equalp(T0,ecl_make_fixnum(-1)))) { goto L4; }
   L44socket_error(_ecl_static_22);
L4:;
   value0 = (cl_env_copy->function=ECL_CONS_CAR(VV[174]))->cfun.entry(3, ecl_make_fixnum(-1), v1socket, VV[16]) /*  (SETF SLOT-VALUE) */;
   return value0;
L2:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G71                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC16__g71(cl_narg narg, cl_object v1socket, cl_object v2buffer, cl_object v3length, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 {
  cl_object v4oob;
  cl_object v5peek;
  cl_object v6waitall;
  cl_object v7element_type;
  ecl_va_list args; ecl_va_start(args,v3length,narg,3);
  {
   cl_object keyvars[8];
   cl_parse_key(args,4,LC16__g71keys,keyvars,NULL,TRUE);
   ecl_va_end(args);
   v4oob = keyvars[0];
   v5peek = keyvars[1];
   v6waitall = keyvars[2];
   v7element_type = keyvars[3];
  }
  if ((v2buffer)!=ECL_NIL) { goto L1; }
  if ((v3length)!=ECL_NIL) { goto L1; }
  cl_error(1, _ecl_static_23);
L1:;
  {
   cl_object v8;
   cl_object v9;
   cl_object v10;
   value0 = v2buffer;
   if ((value0)!=ECL_NIL) { goto L6; }
   v8 = si_make_pure_array(v7element_type, v3length, ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
   goto L4;
L6:;
   v8 = value0;
   goto L4;
L4:;
   value0 = v3length;
   if ((value0)!=ECL_NIL) { goto L10; }
   v9 = ecl_make_fixnum(ecl_length(v2buffer));
   goto L8;
L10:;
   v9 = value0;
   goto L8;
L8:;
   v10 = ecl_function_dispatch(cl_env_copy,VV[171])(1, v1socket) /*  SOCKET-FILE-DESCRIPTOR */;
   {
    cl_object v12;                                /*  LEN-RECV        */
    cl_object v13;                                /*  ERRNO           */
    {
     long v14;
     int v15;
     
{
        int flags = ( (v4oob)!=ECL_NIL ? MSG_OOB : 0 )  |
                    ( (v5peek)!=ECL_NIL ? MSG_PEEK : 0 ) |
                    ( (v6waitall)!=ECL_NIL ? MSG_WAITALL : 0 );
        cl_type type = type_of(v8);
	ssize_t len;

        ecl_disable_interrupts();
        len = recvfrom(ecl_to_int(v10), wincoerce(char*, safe_buffer_pointer(v8, ecl_to_int(v9))),
                       ecl_to_int(v9), flags, NULL,NULL);
	ecl_enable_interrupts();
        if (len >= 0) {
               if (type == t_vector) { v8->vector.fillp = len; }
               else if (type == t_base_string) { v8->base_string.fillp = len; }
        }
        v14= len;
        v15= errno;
}

     cl_env_copy->values[0] = ecl_make_long(v14);
     cl_env_copy->values[1] = ecl_make_int(v15);cl_env_copy->nvalues=2;
     value0 = cl_env_copy->values[0];
    }
    v12 = value0;
    v13 = cl_env_copy->values[1];
    if (!(ecl_number_equalp(v12,ecl_make_fixnum(-1)))) { goto L14; }
    T0 = cl_list(2, ecl_symbol_value(VV[2]), ecl_symbol_value(VV[3]));
    if (Null(ecl_memql(v13,T0))) { goto L14; }
    value0 = ECL_NIL;
    cl_env_copy->nvalues = 1;
    return value0;
L14:;
    if (!(ecl_number_equalp(v12,ecl_make_fixnum(-1)))) { goto L17; }
    value0 = L44socket_error(_ecl_static_24);
    return value0;
L17:;
    cl_env_copy->nvalues = 2;
    cl_env_copy->values[1] = v12;
    cl_env_copy->values[0] = v8;
    return cl_env_copy->values[0];
   }
  }
 }
}
/*	function definition for GET-PROTOCOL-BY-NAME                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L17get_protocol_by_name(cl_object v1string_or_symbol)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2string;
   v2string = cl_string(v1string_or_symbol);
   {
    cl_object v3;
    v3 = si_copy_to_simple_base_string(v2string);
    value0 = ecl_make_int(getprotobyname(ecl_base_string_pointer_safe(v3))->p_proto);
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	function definition for MAKE-INET-ADDRESS                     */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L18make_inet_address(cl_object v1dotted_quads)
{
 cl_object T0, T1;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = (ECL_SYM("PARSE-INTEGER",628)->symbol.gfdef);
  T1 = L5split(3, v1dotted_quads, ECL_NIL, VV[35]);
  value0 = cl_map(3, ECL_SYM("VECTOR",898), T0, T1);
  return value0;
 }
}
/*	local function G76                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC19__g76()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_symbol_value(VV[0]);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for MAKE-INET-SOCKET                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L20make_inet_socket(cl_object v1type, cl_object v2protocol)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = (cl_env_copy->function=(ECL_SYM("MAKE-INSTANCE",949)->symbol.gfdef))->cfun.entry(5, VV[37], ECL_SYM("TYPE",1318), v1type, VV[38], v2protocol) /*  MAKE-INSTANCE */;
  return value0;
 }
}
/*	local function G79                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC21__g79(cl_narg narg, cl_object v1socket, ...)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2address;
  ecl_va_list args; ecl_va_start(args,v1socket,narg,1);
  v2address = cl_grab_rest_args(args);
  ecl_va_end(args);
  goto L3;
L2:;
  {
   cl_object v3;
   T0 = ecl_list1(v2address);
   v3 = si_assert_failure(4, VV[40], VV[41], T0, _ecl_static_26);
   v2address = v3;
  }
L3:;
  {
   cl_fixnum v3;
   v3 = ecl_length(v2address);
   if ((2)==(v3)) { goto L9; }
  }
  goto L2;
L9:;
  {
   cl_object v3;
   cl_object v4;
   v3 = ecl_car(v2address);
   v4 = ecl_cadr(v2address);
   {
    cl_fixnum v5;
    if (ecl_unlikely((0)>=(v3)->vector.dim))
           FEwrong_index(ECL_NIL,v3,-1,ecl_make_fixnum(0),(v3)->vector.dim);
    T0 = ecl_aref_unsafe(v3,0);
    if (ecl_unlikely((1)>=(v3)->vector.dim))
           FEwrong_index(ECL_NIL,v3,-1,ecl_make_fixnum(1),(v3)->vector.dim);
    T1 = ecl_aref_unsafe(v3,1);
    if (ecl_unlikely((2)>=(v3)->vector.dim))
           FEwrong_index(ECL_NIL,v3,-1,ecl_make_fixnum(2),(v3)->vector.dim);
    T2 = ecl_aref_unsafe(v3,2);
    if (ecl_unlikely((3)>=(v3)->vector.dim))
           FEwrong_index(ECL_NIL,v3,-1,ecl_make_fixnum(3),(v3)->vector.dim);
    T3 = ecl_aref_unsafe(v3,3);
    T4 = ecl_function_dispatch(cl_env_copy,VV[171])(1, v1socket) /*  SOCKET-FILE-DESCRIPTOR */;
    {
     int v6;
     
{
	struct sockaddr_in sockaddr;
	int output;
	ecl_disable_interrupts();
	fill_inet_sockaddr(&sockaddr, ecl_to_int(v4), ecl_to_int(T0), ecl_to_int(T1), ecl_to_int(T2), ecl_to_int(T3));
	output = bind(ecl_to_int(T4),(struct sockaddr*)&sockaddr, sizeof(struct sockaddr_in));
	ecl_enable_interrupts();
	v6= output;
}
     v5 = (cl_fixnum)(v6);
    }
    if (!((-1)==(v5))) { goto L13; }
   }
   value0 = L44socket_error(_ecl_static_27);
   return value0;
L13:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G85                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC22__g85(cl_object v1socket)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2sfd;
   v2sfd = ecl_function_dispatch(cl_env_copy,VV[171])(1, v1socket) /*  SOCKET-FILE-DESCRIPTOR */;
   {
    cl_object v4;                                 /*  FD              */
    cl_object v5;                                 /*  VECTOR          */
    cl_object v6;                                 /*  PORT            */
    {
     int v7;
     cl_object v8;
     int v9;
     {
        struct sockaddr_in sockaddr;
        socklen_t addr_len = (socklen_t)sizeof(struct sockaddr_in);
        int new_fd;

	ecl_disable_interrupts();
	new_fd = accept(ecl_to_int(v2sfd), (struct sockaddr*)&sockaddr, &addr_len);
	ecl_enable_interrupts();

	v7= new_fd;
	v8= ECL_NIL;
	v9= 0;
        if (new_fd != -1) {
                uint32_t ip = ntohl(sockaddr.sin_addr.s_addr);
                uint16_t port = ntohs(sockaddr.sin_port);
                cl_object vector = cl_make_array(1,MAKE_FIXNUM(4));

                ecl_aset(vector,0, MAKE_FIXNUM( ip>>24 ));
		ecl_aset(vector,1, MAKE_FIXNUM( (ip>>16) & 0xFF));
		ecl_aset(vector,2, MAKE_FIXNUM( (ip>>8) & 0xFF));
                ecl_aset(vector,3, MAKE_FIXNUM( ip & 0xFF ));

		v8= vector;
		v9= port;
	}
}
     cl_env_copy->values[0] = ecl_make_int(v7);
     cl_env_copy->values[1] = v8;
     cl_env_copy->values[2] = ecl_make_int(v9);cl_env_copy->nvalues=3;
     value0 = cl_env_copy->values[0];
    }
    v4 = value0;
    v5 = cl_env_copy->values[1];
    v6 = cl_env_copy->values[2];
    if (!((ecl_fixnum(v4))==(-1))) { goto L3; }
    value0 = L44socket_error(_ecl_static_28);
    return value0;
L3:;
    T0 = cl_class_of(v1socket);
    T1 = ecl_function_dispatch(cl_env_copy,VV[173])(1, v1socket) /*  SOCKET-TYPE */;
    T2 = ecl_function_dispatch(cl_env_copy,VV[182])(1, v1socket) /*  SOCKET-PROTOCOL */;
    T3 = (cl_env_copy->function=(ECL_SYM("MAKE-INSTANCE",949)->symbol.gfdef))->cfun.entry(7, T0, ECL_SYM("TYPE",1318), T1, VV[38], T2, VV[42], v4) /*  MAKE-INSTANCE */;
    cl_env_copy->nvalues = 3;
    cl_env_copy->values[2] = v6;
    cl_env_copy->values[1] = v5;
    cl_env_copy->values[0] = T3;
    return cl_env_copy->values[0];
   }
  }
 }
}
/*	local function G86                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC23__g86(cl_narg narg, cl_object v1socket, ...)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2address;
  ecl_va_list args; ecl_va_start(args,v1socket,narg,1);
  v2address = cl_grab_rest_args(args);
  ecl_va_end(args);
  {
   cl_object v3;
   cl_object v4;
   v3 = ecl_car(v2address);
   v4 = ecl_cadr(v2address);
   {
    cl_fixnum v5;
    if (ecl_unlikely((0)>=(v3)->vector.dim))
           FEwrong_index(ECL_NIL,v3,-1,ecl_make_fixnum(0),(v3)->vector.dim);
    T0 = ecl_aref_unsafe(v3,0);
    if (ecl_unlikely((1)>=(v3)->vector.dim))
           FEwrong_index(ECL_NIL,v3,-1,ecl_make_fixnum(1),(v3)->vector.dim);
    T1 = ecl_aref_unsafe(v3,1);
    if (ecl_unlikely((2)>=(v3)->vector.dim))
           FEwrong_index(ECL_NIL,v3,-1,ecl_make_fixnum(2),(v3)->vector.dim);
    T2 = ecl_aref_unsafe(v3,2);
    if (ecl_unlikely((3)>=(v3)->vector.dim))
           FEwrong_index(ECL_NIL,v3,-1,ecl_make_fixnum(3),(v3)->vector.dim);
    T3 = ecl_aref_unsafe(v3,3);
    T4 = ecl_function_dispatch(cl_env_copy,VV[171])(1, v1socket) /*  SOCKET-FILE-DESCRIPTOR */;
    {
     int v6;
     
{
	struct sockaddr_in sockaddr;
	int output;

	ecl_disable_interrupts();
	fill_inet_sockaddr(&sockaddr, ecl_to_int(v4), ecl_to_int(T0), ecl_to_int(T1), ecl_to_int(T2), ecl_to_int(T3));
	output = connect(ecl_to_int(T4),(struct sockaddr*)&sockaddr, sizeof(struct sockaddr_in));
	ecl_enable_interrupts();

	v6= output;
}
     v5 = (cl_fixnum)(v6);
    }
    if (!((-1)==(v5))) { goto L3; }
   }
   value0 = L44socket_error(_ecl_static_29);
   return value0;
L3:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G89                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC24__g89(cl_object v1socket)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2vector;
   cl_object v3fd;
   cl_fixnum v4port;
   v2vector = si_make_vector(ECL_T, ecl_make_fixnum(4), ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
   v3fd = ecl_function_dispatch(cl_env_copy,VV[171])(1, v1socket) /*  SOCKET-FILE-DESCRIPTOR */;
   {
    int v5;
    {
        struct sockaddr_in name;
        socklen_t len = sizeof(struct sockaddr_in);
        int ret;

	ecl_disable_interrupts();
	ret = getpeername(ecl_to_int(v3fd),(struct sockaddr*)&name,&len);
	ecl_enable_interrupts();

        if (ret == 0) {
                uint32_t ip = ntohl(name.sin_addr.s_addr);
                uint16_t port = ntohs(name.sin_port);

                ecl_aset(v2vector,0, MAKE_FIXNUM( ip>>24 ));
		ecl_aset(v2vector,1, MAKE_FIXNUM( (ip>>16) & 0xFF));
		ecl_aset(v2vector,2, MAKE_FIXNUM( (ip>>8) & 0xFF));
                ecl_aset(v2vector,3, MAKE_FIXNUM( ip & 0xFF ));

                v5= port;
         } else {
                v5= -1;
         }
}
    v4port = (cl_fixnum)(v5);
   }
   if (!((v4port)>=(0))) { goto L4; }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = ecl_make_fixnum(v4port);
   cl_env_copy->values[0] = v2vector;
   return cl_env_copy->values[0];
L4:;
   value0 = L44socket_error(_ecl_static_30);
   return value0;
  }
 }
}
/*	local function G90                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC25__g90(cl_object v1socket)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2vector;
   cl_object v3fd;
   cl_fixnum v4port;
   v2vector = si_make_vector(ECL_T, ecl_make_fixnum(4), ECL_NIL, ECL_NIL, ECL_NIL, ecl_make_fixnum(0));
   v3fd = ecl_function_dispatch(cl_env_copy,VV[171])(1, v1socket) /*  SOCKET-FILE-DESCRIPTOR */;
   {
    int v5;
    {
        struct sockaddr_in name;
        socklen_t len = sizeof(struct sockaddr_in);
        int ret;

	ecl_disable_interrupts();
	ret = getsockname(ecl_to_int(v3fd),(struct sockaddr*)&name,&len);
	ecl_enable_interrupts();

        if (ret == 0) {
                uint32_t ip = ntohl(name.sin_addr.s_addr);
                uint16_t port = ntohs(name.sin_port);

                ecl_aset(v2vector,0, MAKE_FIXNUM( ip>>24 ));
		ecl_aset(v2vector,1, MAKE_FIXNUM( (ip>>16) & 0xFF));
		ecl_aset(v2vector,2, MAKE_FIXNUM( (ip>>8) & 0xFF));
                ecl_aset(v2vector,3, MAKE_FIXNUM( ip & 0xFF ));

                v5= port;
         } else {
                v5= -1;
         }
}
    v4port = (cl_fixnum)(v5);
   }
   if (!((v4port)>=(0))) { goto L4; }
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = ecl_make_fixnum(v4port);
   cl_env_copy->values[0] = v2vector;
   return cl_env_copy->values[0];
L4:;
   value0 = L44socket_error(_ecl_static_31);
   return value0;
  }
 }
}
/*	local function G91                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC26__g91(cl_narg narg, cl_object v1socket, cl_object v2buffer, cl_object v3length, ...)
{
 cl_object T0, T1, T2, T3, T4;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<3)) FEwrong_num_arguments_anonym();
 {
  cl_object v4address;
  cl_object v5external_format;
  cl_object v6oob;
  cl_object v7eor;
  cl_object v8dontroute;
  cl_object v9dontwait;
  cl_object v10nosignal;
  cl_object v11confirm;
  cl_object v12more;
  ecl_va_list args; ecl_va_start(args,v3length,narg,3);
  {
   cl_object keyvars[18];
   cl_parse_key(args,9,LC26__g91keys,keyvars,NULL,TRUE);
   ecl_va_end(args);
   v4address = keyvars[0];
   v5external_format = keyvars[1];
   v6oob = keyvars[2];
   v7eor = keyvars[3];
   v8dontroute = keyvars[4];
   v9dontwait = keyvars[5];
   v10nosignal = keyvars[6];
   v11confirm = keyvars[7];
   v12more = keyvars[8];
  }
  goto L3;
L2:;
  si_assert_failure(1, VV[43]);
L3:;
  if (ECL_STRINGP(v2buffer)) { goto L6; }
  if (ECL_VECTORP(v2buffer)) { goto L6; }
  goto L2;
L6:;
  {
   cl_object v13;
   cl_object v14;
   value0 = v3length;
   if ((value0)!=ECL_NIL) { goto L11; }
   v13 = ecl_make_fixnum(ecl_length(v2buffer));
   goto L9;
L11:;
   v13 = value0;
   goto L9;
L9:;
   v14 = ecl_function_dispatch(cl_env_copy,VV[171])(1, v1socket) /*  SOCKET-FILE-DESCRIPTOR */;
   {
    long v15len_sent;
    if (Null(v4address)) { goto L15; }
    goto L19;
L18:;
    si_assert_failure(1, VV[40]);
L19:;
    {
     cl_fixnum v16;
     v16 = ecl_length(v4address);
     if ((2)==(v16)) { goto L22; }
    }
    goto L18;
L22:;
    T0 = ecl_cadr(v4address);
    {
     cl_object v16;
     v16 = ecl_car(v4address);
     if (ecl_unlikely((0)>=(v16)->vector.dim))
           FEwrong_index(ECL_NIL,v16,-1,ecl_make_fixnum(0),(v16)->vector.dim);
     T1 = ecl_aref_unsafe(v16,0);
    }
    {
     cl_object v16;
     v16 = ecl_car(v4address);
     if (ecl_unlikely((1)>=(v16)->vector.dim))
           FEwrong_index(ECL_NIL,v16,-1,ecl_make_fixnum(1),(v16)->vector.dim);
     T2 = ecl_aref_unsafe(v16,1);
    }
    {
     cl_object v16;
     v16 = ecl_car(v4address);
     if (ecl_unlikely((2)>=(v16)->vector.dim))
           FEwrong_index(ECL_NIL,v16,-1,ecl_make_fixnum(2),(v16)->vector.dim);
     T3 = ecl_aref_unsafe(v16,2);
    }
    {
     cl_object v16;
     v16 = ecl_car(v4address);
     if (ecl_unlikely((3)>=(v16)->vector.dim))
           FEwrong_index(ECL_NIL,v16,-1,ecl_make_fixnum(3),(v16)->vector.dim);
     T4 = ecl_aref_unsafe(v16,3);
    }
    {
     long v16;
     
{
	int sock = ecl_to_int(v14);
	int length = ecl_to_int(v13);
	void *buffer = safe_buffer_pointer(v2buffer, length);
        int flags = ( (v6oob)!=ECL_NIL ? MSG_OOB : 0 )  |
                    ( (v7eor)!=ECL_NIL ? MSG_EOR : 0 ) |
                    ( (v8dontroute)!=ECL_NIL ? MSG_DONTROUTE : 0 ) |
                    ( (v9dontwait)!=ECL_NIL ? MSG_DONTWAIT : 0 ) |
                    ( (v10nosignal)!=ECL_NIL ? MSG_NOSIGNAL : 0 ) |
                    ( (v11confirm)!=ECL_NIL ? MSG_CONFIRM : 0 );
        cl_type type = type_of(v2buffer);
        struct sockaddr_in sockaddr;
	ssize_t len;

	ecl_disable_interrupts();
	fill_inet_sockaddr(&sockaddr, ecl_to_int(T0), ecl_to_int(T1), ecl_to_int(T2), ecl_to_int(T3), ecl_to_int(T4));
#if (MSG_NOSIGNAL == 0) && defined(SO_NOSIGPIPE)
	{
		int sockopt = (v10nosignal)!=ECL_NIL;
		setsockopt(ecl_to_int(v14),SOL_SOCKET,SO_NOSIGPIPE,
			   wincoerce(char *,&sockopt),
			   sizeof(int));
	}
#endif
        len = sendto(sock, wincoerce(char *,buffer),
                     length, flags,(struct sockaddr*)&sockaddr, 
                     sizeof(struct sockaddr_in));
	ecl_enable_interrupts();
        v16= len;
}

     v15len_sent = v16;
     goto L14;
    }
L15:;
    {
     long v17;
     
{
	int sock = ecl_to_int(v14);
	int length = ecl_to_int(v13);
	void *buffer = safe_buffer_pointer(v2buffer, length);
        int flags = ( (v6oob)!=ECL_NIL ? MSG_OOB : 0 )  |
                    ( (v7eor)!=ECL_NIL ? MSG_EOR : 0 ) |
                    ( (v8dontroute)!=ECL_NIL ? MSG_DONTROUTE : 0 ) |
                    ( (v9dontwait)!=ECL_NIL ? MSG_DONTWAIT : 0 ) |
                    ( (v10nosignal)!=ECL_NIL ? MSG_NOSIGNAL : 0 ) |
                    ( (v11confirm)!=ECL_NIL ? MSG_CONFIRM : 0 );
        cl_type type = type_of(v2buffer);
        ssize_t len;
	ecl_disable_interrupts();
#if (MSG_NOSIGNAL == 0) && defined(SO_NOSIGPIPE)
	{
		int sockopt = (v10nosignal)!=ECL_NIL;
		setsockopt(ecl_to_int(v14),SOL_SOCKET,SO_NOSIGPIPE,
			   wincoerce(char *,&sockopt),
			   sizeof(int));
	}
#endif
	len = send(sock, wincoerce(char *, buffer), length, flags);
	ecl_enable_interrupts();
        v17= len;
}

     v15len_sent = v17;
    }
L14:;
    if (!(ecl_number_equalp(ecl_make_long(v15len_sent),ecl_make_fixnum(-1)))) { goto L40; }
    value0 = L44socket_error(_ecl_static_32);
    return value0;
L40:;
    value0 = ecl_make_long(v15len_sent);
    cl_env_copy->nvalues = 1;
    return value0;
   }
  }
 }
}
/*	local function G98                                            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC27__g98()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_symbol_value(VV[1]);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	local function G101                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC28__g101(cl_narg narg, cl_object v1socket, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2address;
  ecl_va_list args; ecl_va_start(args,v1socket,narg,1);
  v2address = cl_grab_rest_args(args);
  ecl_va_end(args);
  goto L3;
L2:;
  {
   cl_object v3;
   T0 = ecl_list1(v2address);
   v3 = si_assert_failure(4, VV[45], VV[41], T0, _ecl_static_34);
   v2address = v3;
  }
L3:;
  {
   cl_fixnum v3;
   v3 = ecl_length(v2address);
   if ((1)==(v3)) { goto L9; }
  }
  goto L2;
L9:;
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   v3 = ecl_car(v2address);
   v4 = ecl_function_dispatch(cl_env_copy,VV[171])(1, v1socket) /*  SOCKET-FILE-DESCRIPTOR */;
   v5 = ecl_function_dispatch(cl_env_copy,VV[172])(1, v1socket) /*  SOCKET-FAMILY */;
   {
    cl_fixnum v6;
    {
     cl_object v7;
     v7 = si_copy_to_simple_base_string(v3);
     {
      int v8;
      
{
        struct sockaddr_un sockaddr;
	size_t size;
	int output;
#ifdef BSD
        sockaddr.sun_len = sizeof(struct sockaddr_un);
#endif
        sockaddr.sun_family = ecl_to_int(v5);
        strncpy(sockaddr.sun_path,ecl_base_string_pointer_safe(v7),sizeof(sockaddr.sun_path));
	sockaddr.sun_path[sizeof(sockaddr.sun_path)-1] = '0';

	ecl_disable_interrupts();
	output = bind(ecl_to_int(v4),(struct sockaddr*)&sockaddr, sizeof(struct sockaddr_un));
	ecl_enable_interrupts();

        v8= output;
}
      v6 = (cl_fixnum)(v8);
     }
    }
    if (!((-1)==(v6))) { goto L14; }
   }
   value0 = L44socket_error(_ecl_static_27);
   return value0;
L14:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G109                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC29__g109(cl_object v1socket)
{
 cl_object T0, T1, T2, T3;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;                                  /*  FD              */
   cl_object v4;                                  /*  NAME            */
   T0 = ecl_function_dispatch(cl_env_copy,VV[171])(1, v1socket) /*  SOCKET-FILE-DESCRIPTOR */;
   {
    int v5;
    cl_object v6;
    {
        struct sockaddr_un sockaddr;
        socklen_t addr_len = (socklen_t)sizeof(struct sockaddr_un);
        int new_fd;
	ecl_disable_interrupts();
	new_fd = accept(ecl_to_int(T0), (struct sockaddr *)&sockaddr, &addr_len);
	ecl_enable_interrupts();
	v5= new_fd;
	v6= (new_fd == -1) ? ECL_NIL : make_base_string_copy(sockaddr.sun_path);
}
    cl_env_copy->values[0] = ecl_make_int(v5);
    cl_env_copy->values[1] = v6;cl_env_copy->nvalues=2;
    value0 = cl_env_copy->values[0];
   }
   v3 = value0;
   v4 = cl_env_copy->values[1];
   if (!((ecl_fixnum(v3))==(-1))) { goto L2; }
   value0 = L44socket_error(_ecl_static_28);
   return value0;
L2:;
   T0 = cl_class_of(v1socket);
   T1 = ecl_function_dispatch(cl_env_copy,VV[173])(1, v1socket) /*  SOCKET-TYPE */;
   T2 = ecl_function_dispatch(cl_env_copy,VV[182])(1, v1socket) /*  SOCKET-PROTOCOL */;
   T3 = (cl_env_copy->function=(ECL_SYM("MAKE-INSTANCE",949)->symbol.gfdef))->cfun.entry(7, T0, ECL_SYM("TYPE",1318), T1, VV[38], T2, VV[42], v3) /*  MAKE-INSTANCE */;
   cl_env_copy->nvalues = 2;
   cl_env_copy->values[1] = v4;
   cl_env_copy->values[0] = T3;
   return cl_env_copy->values[0];
  }
 }
}
/*	local function G112                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC30__g112(cl_narg narg, cl_object v1socket, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2address;
  ecl_va_list args; ecl_va_start(args,v1socket,narg,1);
  v2address = cl_grab_rest_args(args);
  ecl_va_end(args);
  goto L3;
L2:;
  {
   cl_object v3;
   T0 = ecl_list1(v2address);
   v3 = si_assert_failure(4, VV[45], VV[41], T0, _ecl_static_35);
   v2address = v3;
  }
L3:;
  {
   cl_fixnum v3;
   v3 = ecl_length(v2address);
   if ((1)==(v3)) { goto L9; }
  }
  goto L2;
L9:;
  {
   cl_object v3;
   cl_object v4;
   cl_object v5;
   v3 = ecl_car(v2address);
   v4 = ecl_function_dispatch(cl_env_copy,VV[171])(1, v1socket) /*  SOCKET-FILE-DESCRIPTOR */;
   v5 = ecl_function_dispatch(cl_env_copy,VV[172])(1, v1socket) /*  SOCKET-FAMILY */;
   {
    cl_fixnum v6;
    {
     cl_object v7;
     v7 = si_copy_to_simple_base_string(v3);
     {
      int v8;
      
{
        struct sockaddr_un sockaddr;
	int output;
#ifdef BSD
        sockaddr.sun_len = sizeof(struct sockaddr_un);
#endif
        sockaddr.sun_family = ecl_to_int(v5);
        strncpy(sockaddr.sun_path,ecl_base_string_pointer_safe(v7),sizeof(sockaddr.sun_path));
	sockaddr.sun_path[sizeof(sockaddr.sun_path)-1] = '0';

	ecl_disable_interrupts();
	output = connect(ecl_to_int(v4),(struct sockaddr*)&sockaddr, sizeof(struct sockaddr_un));
	ecl_enable_interrupts();

        v8= output;
}
      v6 = (cl_fixnum)(v8);
     }
    }
    if (!((-1)==(v6))) { goto L14; }
   }
   value0 = L44socket_error(_ecl_static_29);
   return value0;
L14:;
   value0 = ECL_NIL;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G120                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC31__g120(cl_object v1socket)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2fd;
   cl_object v3peer;
   v2fd = ecl_function_dispatch(cl_env_copy,VV[171])(1, v1socket) /*  SOCKET-FILE-DESCRIPTOR */;
   {
    cl_object v4;
    
{
        struct sockaddr_un name;
        socklen_t len = sizeof(struct sockaddr_un);
        int ret;

	ecl_disable_interrupts();
	ret = getpeername(ecl_to_int(v2fd),(struct sockaddr*)&name,&len);
	ecl_enable_interrupts();

        if (ret == 0) {
                v4= make_base_string_copy(name.sun_path);
        } else {
                v4= ECL_NIL;
        }
}
    v3peer = v4;
   }
   if (Null(v3peer)) { goto L3; }
   value0 = v3peer;
   cl_env_copy->nvalues = 1;
   return value0;
L3:;
   value0 = L44socket_error(_ecl_static_30);
   return value0;
  }
 }
}
/*	local function G121                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC32__g121(cl_object v1socket)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v2fd;
   v2fd = ecl_function_dispatch(cl_env_copy,VV[171])(1, v1socket) /*  SOCKET-FILE-DESCRIPTOR */;
   {
    cl_fixnum v3;
    v3 = (cl_fixnum)(fcntl(ecl_to_int(v2fd),F_GETFL,NULL)&O_NONBLOCK);
    {
     bool v4;
     v4 = (v3)==0;
     value0 = (v4)?ECL_NIL:ECL_T;
     cl_env_copy->nvalues = 1;
     return value0;
    }
   }
  }
 }
}
/*	local function G122                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC33__g122(cl_object v1non_blocking_p, cl_object v2socket)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_fixnum v4;
   v3 = ecl_function_dispatch(cl_env_copy,VV[171])(1, v2socket) /*  SOCKET-FILE-DESCRIPTOR */;
   if (Null(v1non_blocking_p)) { goto L3; }
   v4 = 1;
   goto L2;
L3:;
   v4 = 0;
L2:;
   {
    cl_fixnum v5;
    {
     int v6;
     
{
        int oldflags = fcntl(ecl_to_int(v3),F_GETFL,NULL);
        int newflags = (oldflags & ~O_NONBLOCK) |
                       ((int)(v4) ? O_NONBLOCK : 0);
	ecl_disable_interrupts();
        v6= fcntl(ecl_to_int(v3),F_SETFL,newflags);
	ecl_enable_interrupts();
}
     v5 = (cl_fixnum)(v6);
    }
    if (!((-1)==(v5))) { goto L5; }
   }
   value0 = L44socket_error(_ecl_static_36);
   return value0;
L5:;
   value0 = v1non_blocking_p;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for DUP                                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L34dup(cl_object v1fd)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_make_int(dup(ecl_to_int(v1fd)));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for MAKE-STREAM-FROM-FD                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L35make_stream_from_fd(cl_narg narg, cl_object v1fd, cl_object v2mode, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<2)) FEwrong_num_arguments_anonym();
 {
  cl_object v3buffering;
  cl_object v4element_type;
  cl_object v5external_format;
  cl_object v6name;
  ecl_va_list args; ecl_va_start(args,v2mode,narg,2);
  {
   cl_object keyvars[8];
   cl_parse_key(args,4,L35make_stream_from_fdkeys,keyvars,NULL,FALSE);
   ecl_va_end(args);
   v3buffering = keyvars[0];
   v4element_type = keyvars[1];
   if (Null(keyvars[6])) {
    v5external_format = ECL_SYM("DEFAULT",1215);
   } else {
    v5external_format = keyvars[2];
   }
   if (Null(keyvars[7])) {
    v6name = _ecl_static_37;
   } else {
    v6name = keyvars[3];
   }
  }
  goto L5;
L4:;
  {
   cl_object v7;
   T0 = ecl_list1(v6name);
   v7 = si_assert_failure(4, VV[47], VV[48], T0, _ecl_static_38);
   v6name = v7;
  }
L5:;
  if (ECL_STRINGP(v6name)) { goto L11; }
  goto L4;
L11:;
  {
   cl_object v7smm_mode;
   cl_object v8external_format;
   cl_object v9stream;
   if (!(ecl_eql(v2mode,ECL_SYM("INPUT",1254)))) { goto L14; }
   v7smm_mode = ecl_make_int(ecl_smm_input);
   goto L13;
L14:;
   if (!(ecl_eql(v2mode,ECL_SYM("OUTPUT",1282)))) { goto L16; }
   v7smm_mode = ecl_make_int(ecl_smm_output);
   goto L13;
L16:;
   if (!(ecl_eql(v2mode,VV[49]))) { goto L18; }
   v7smm_mode = ecl_make_int(ecl_smm_io);
   goto L13;
L18:;
   v7smm_mode = si_ecase_error(v2mode, VV[50]);
L13:;
   if ((cl_subtypep(2, v4element_type, ECL_SYM("INTEGER",437)))!=ECL_NIL) { goto L21; }
   v8external_format = v5external_format;
   goto L20;
L21:;
   v8external_format = ECL_NIL;
L20:;
   v9stream = 
ecl_make_stream_from_fd(v6name,ecl_to_int(v1fd),(enum ecl_smmode)ecl_to_int(v7smm_mode),
			ecl_normalize_stream_element_type(v4element_type),
                        0,v8external_format);
   if (Null(v3buffering)) { goto L24; }
   si_set_buffering_mode(v9stream, v3buffering);
L24:;
   value0 = v9stream;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	function definition for AUTO-CLOSE-TWO-WAY-STREAM             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L36auto_close_two_way_stream(cl_object v1stream)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  (v1stream)->stream.flags |= ECL_STREAM_CLOSE_COMPONENTS;
  value0 = ECL_NIL;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for SOCKET-MAKE-STREAM-INNER              */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L37socket_make_stream_inner(cl_object v1fd, cl_object v2input, cl_object v3output, cl_object v4buffering, cl_object v5element_type, cl_object v6external_format)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  if (Null(v2input)) { goto L1; }
  if (Null(v3output)) { goto L1; }
  {
   cl_object v7in;
   cl_object v8out;
   cl_object v9stream;
   T0 = L34dup(v1fd);
   v7in = L37socket_make_stream_inner(T0, ECL_T, ECL_NIL, v4buffering, v5element_type, v6external_format);
   v8out = L37socket_make_stream_inner(v1fd, ECL_NIL, ECL_T, v4buffering, v5element_type, v6external_format);
   v9stream = cl_make_two_way_stream(v7in, v8out);
   L36auto_close_two_way_stream(v9stream);
   value0 = v9stream;
   cl_env_copy->nvalues = 1;
   return value0;
  }
L1:;
  if (Null(v2input)) { goto L8; }
  value0 = L35make_stream_from_fd(8, v1fd, ECL_SYM("INPUT",1254), VV[52], v4buffering, ECL_SYM("ELEMENT-TYPE",1224), v5element_type, ECL_SYM("EXTERNAL-FORMAT",1236), v6external_format);
  return value0;
L8:;
  if (Null(v3output)) { goto L10; }
  value0 = L35make_stream_from_fd(8, v1fd, ECL_SYM("OUTPUT",1282), VV[52], v4buffering, ECL_SYM("ELEMENT-TYPE",1224), v5element_type, ECL_SYM("EXTERNAL-FORMAT",1236), v6external_format);
  return value0;
L10:;
  value0 = cl_error(1, _ecl_static_39);
  return value0;
 }
}
/*	local function G142                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC38__g142(cl_narg narg, cl_object v1socket, ...)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 if (ecl_unlikely(narg<1)) FEwrong_num_arguments_anonym();
 {
  cl_object v2input;
  cl_object v3input_p;
  cl_object v4output;
  cl_object v5output_p;
  cl_object v6buffering;
  cl_object v7element_type;
  cl_object v8external_format;
  ecl_va_list args; ecl_va_start(args,v1socket,narg,1);
  {
   cl_object keyvars[10];
   cl_parse_key(args,5,LC38__g142keys,keyvars,NULL,TRUE);
   ecl_va_end(args);
   v2input = keyvars[0];
   v3input_p = keyvars[5];
   v4output = keyvars[1];
   v5output_p = keyvars[6];
   if (Null(keyvars[7])) {
    v6buffering = ECL_SYM("FULL",1602);
   } else {
    v6buffering = keyvars[2];
   }
   if (Null(keyvars[8])) {
    v7element_type = ECL_SYM("BASE-CHAR",120);
   } else {
    v7element_type = keyvars[3];
   }
   if (Null(keyvars[9])) {
    v8external_format = ECL_SYM("DEFAULT",1215);
   } else {
    v8external_format = keyvars[4];
   }
  }
  {
   cl_object v9stream;
   if (Null(cl_slot_boundp(v1socket, ECL_SYM("STREAM",799)))) { goto L6; }
   v9stream = cl_slot_value(v1socket, ECL_SYM("STREAM",799));
   goto L4;
L6:;
   v9stream = ECL_NIL;
   goto L4;
L4:;
   if ((v9stream)!=ECL_NIL) { goto L8; }
   if ((v3input_p)!=ECL_NIL) { goto L10; }
   if ((v5output_p)!=ECL_NIL) { goto L10; }
   v2input = ECL_T;
   v4output = ECL_T;
L10:;
   T0 = ecl_function_dispatch(cl_env_copy,VV[171])(1, v1socket) /*  SOCKET-FILE-DESCRIPTOR */;
   v9stream = L37socket_make_stream_inner(T0, v2input, v4output, v6buffering, v7element_type, v8external_format);
   (cl_env_copy->function=ECL_CONS_CAR(VV[174]))->cfun.entry(3, v9stream, v1socket, ECL_SYM("STREAM",799)) /*  (SETF SLOT-VALUE) */;
L8:;
   value0 = v9stream;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G149                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC39__g149(cl_object v1socket)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_function_dispatch(cl_env_copy,VV[171])(1, v1socket) /*  SOCKET-FILE-DESCRIPTOR */;
  return value0;
 }
}
/*	local function G150                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC41__g150()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {cl_object v1;
   v1 = ECL_NIL;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC40__g151,ECL_NIL,Cblock,2);
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G151                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC40__g151(cl_object v1c, cl_object v2s)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3num;
   v3num = ecl_function_dispatch(cl_env_copy,VV[204])(1, v1c) /*  SOCKET-ERROR-ERRNO */;
   T0 = ecl_function_dispatch(cl_env_copy,VV[205])(1, v1c) /*  SOCKET-ERROR-SYSCALL */;
   value0 = ecl_function_dispatch(cl_env_copy,VV[58])(1, v1c) /*  SOCKET-ERROR-SYMBOL */;
   if ((value0)!=ECL_NIL) { goto L4; }
   T1 = ecl_function_dispatch(cl_env_copy,VV[204])(1, v1c) /*  SOCKET-ERROR-ERRNO */;
   goto L2;
L4:;
   T1 = value0;
   goto L2;
L2:;
   T2 = ecl_cstring_to_base_string_or_nil(strerror(ecl_to_int(v3num)));
   value0 = cl_format(5, v2s, _ecl_static_40, T0, T1, T2);
   return value0;
  }
 }
}
/*	local function DEFINE-SOCKET-CONDITION                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC42define_socket_condition(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4symbol;
   cl_object v5name;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4symbol = v6;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5name = v6;
   }
   if (Null(v3)) { goto L14; }
   si_dm_too_many_arguments(v1);
L14:;
   T0 = ecl_symbol_name(v4symbol);
   T1 = cl_list(2, VV[56], T0);
   T2 = cl_list(3, ECL_SYM("DEFCONSTANT",277), v4symbol, T1);
   T3 = cl_list(2, ECL_SYM("QUOTE",679), v4symbol);
   T4 = cl_list(5, ECL_SYM("SYMBOL",840), ECL_SYM("READER",1006), VV[58], ECL_SYM("INITFORM",996), T3);
   T5 = ecl_list1(T4);
   T6 = cl_list(4, ECL_SYM("DEFINE-CONDITION",278), v5name, VV[57], T5);
   T7 = cl_list(2, ECL_SYM("QUOTE",679), v5name);
   T8 = cl_list(2, ECL_SYM("EXPORT",344), T7);
   T9 = cl_list(2, ECL_SYM("QUOTE",679), v5name);
   T10 = cl_list(3, ECL_SYM("CONS",251), v4symbol, T9);
   T11 = cl_list(3, ECL_SYM("PUSH",677), T10, VV[59]);
   value0 = cl_list(6, ECL_SYM("LET",477), ECL_NIL, T2, T6, T8, T11);
   return value0;
  }
 }
}
/*	function definition for CONDITION-FOR-ERRNO                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L43condition_for_errno(cl_object v1err)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_assql(v1err,ecl_symbol_value(VV[59]));
  value0 = ecl_cdr(T0);
  if ((value0)!=ECL_NIL) { goto L2; }
  value0 = VV[55];
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for SOCKET-ERROR                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L44socket_error(cl_object v1where)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_fixnum v2errno;
   cl_object v3condition;
   v2errno = (cl_fixnum)(errno);
   v3condition = L43condition_for_errno(ecl_make_fixnum(v2errno));
   value0 = cl_error(5, v3condition, VV[89], ecl_make_fixnum(v2errno), VV[90], v1where);
   return value0;
  }
 }
}
/*	function definition for NAME-SERVICE-ERROR                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L45name_service_error(cl_object v1where)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  L50get_name_service_errno();
  {
   cl_fixnum v2;
   v2 = (cl_fixnum)(NETDB_INTERNAL);
   if (!(ecl_number_equalp(ecl_symbol_value(VV[92]),ecl_make_fixnum(v2)))) { goto L2; }
  }
  value0 = L44socket_error(v1where);
  return value0;
L2:;
  {
   cl_object v2condition;
   v2condition = L49condition_for_name_service_errno(ecl_symbol_value(VV[92]));
   value0 = cl_error(5, v2condition, VV[89], ecl_symbol_value(VV[92]), VV[90], v1where);
   return value0;
  }
 }
}
/*	local function G174                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC47__g174()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {cl_object v1;
   v1 = ECL_NIL;
   v1 = ecl_make_cfun((cl_objectfn_fixed)LC46__g175,ECL_NIL,Cblock,2);
   value0 = v1;
   cl_env_copy->nvalues = 1;
   return value0;
  }
 }
}
/*	local function G175                                           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC46__g175(cl_object v1c, cl_object v2s)
{
 cl_object T0, T1, T2;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3num;
   v3num = ecl_function_dispatch(cl_env_copy,VV[210])(1, v1c) /*  NAME-SERVICE-ERROR-ERRNO */;
   T0 = ecl_function_dispatch(cl_env_copy,VV[211])(1, v1c) /*  NAME-SERVICE-ERROR-SYSCALL */;
   value0 = ecl_function_dispatch(cl_env_copy,VV[95])(1, v1c) /*  NAME-SERVICE-ERROR-SYMBOL */;
   if ((value0)!=ECL_NIL) { goto L4; }
   T1 = ecl_function_dispatch(cl_env_copy,VV[210])(1, v1c) /*  NAME-SERVICE-ERROR-ERRNO */;
   goto L2;
L4:;
   T1 = value0;
   goto L2;
L2:;
   T2 = L51get_name_service_error_message(v3num);
   value0 = cl_format(5, v2s, _ecl_static_42, T0, T1, T2);
   return value0;
  }
 }
}
/*	local function DEFINE-NAME-SERVICE-CONDITION                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC48define_name_service_condition(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4symbol;
   cl_object v5name;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4symbol = v6;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v6;
    v6 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5name = v6;
   }
   if (Null(v3)) { goto L14; }
   si_dm_too_many_arguments(v1);
L14:;
   T0 = ecl_symbol_name(v4symbol);
   T1 = cl_list(2, VV[56], T0);
   T2 = cl_list(3, ECL_SYM("DEFCONSTANT",277), v4symbol, T1);
   T3 = cl_list(2, ECL_SYM("QUOTE",679), v4symbol);
   T4 = cl_list(5, ECL_SYM("SYMBOL",840), ECL_SYM("READER",1006), VV[95], ECL_SYM("INITFORM",996), T3);
   T5 = ecl_list1(T4);
   T6 = cl_list(4, ECL_SYM("DEFINE-CONDITION",278), v5name, VV[94], T5);
   T7 = cl_list(2, ECL_SYM("QUOTE",679), v5name);
   T8 = cl_list(3, ECL_SYM("CONS",251), v4symbol, T7);
   T9 = cl_list(3, ECL_SYM("PUSH",677), T8, VV[96]);
   T10 = cl_list(2, ECL_SYM("QUOTE",679), v4symbol);
   T11 = cl_list(2, ECL_SYM("EXPORT",344), T10);
   value0 = cl_list(6, ECL_SYM("LET",477), ECL_NIL, T2, T6, T9, T11);
   return value0;
  }
 }
}
/*	function definition for CONDITION-FOR-NAME-SERVICE-ERRNO      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L49condition_for_name_service_errno(cl_object v1err)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_assql(v1err,ecl_symbol_value(VV[96]));
  value0 = ecl_cdr(T0);
  if ((value0)!=ECL_NIL) { goto L2; }
  value0 = VV[110];
  cl_env_copy->nvalues = 1;
  return value0;
L2:;
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for GET-NAME-SERVICE-ERRNO                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L50get_name_service_errno()
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  cl_set(VV[92],ecl_make_int(h_errno));
  value0 = ecl_symbol_value(VV[92]);
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for GET-NAME-SERVICE-ERROR-MESSAGE        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L51get_name_service_error_message(cl_object v1num)
{
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  value0 = ecl_cstring_to_base_string_or_nil(strerror(ecl_to_int(v1num)));
  cl_env_copy->nvalues = 1;
  return value0;
 }
}
/*	function definition for GET-SOCKOPT-INT                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L52get_sockopt_int(cl_object v1fd, cl_object v2level, cl_object v3const)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4ret;
   {
    cl_object v5;
    {
        int sockopt, ret;
        socklen_t socklen = sizeof(int);

	ecl_disable_interrupts();
	ret = getsockopt(ecl_to_int(v1fd),ecl_to_int(v2level),ecl_to_int(v3const),wincoerce(char*,&sockopt),&socklen);
	ecl_enable_interrupts();

        v5= (ret == 0) ? ecl_make_integer(sockopt) : ECL_NIL;
}
    v4ret = v5;
   }
   if (Null(v4ret)) { goto L2; }
   value0 = v4ret;
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
   T0 = ecl_cstring_to_base_string_or_nil(strerror(errno));
   value0 = cl_error(2, _ecl_static_43, T0);
   return value0;
  }
 }
}
/*	function definition for GET-SOCKOPT-BOOL                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L53get_sockopt_bool(cl_object v1fd, cl_object v2level, cl_object v3const)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4ret;
   {
    cl_object v5;
    {
        int sockopt, ret;
        socklen_t socklen = sizeof(int);

	ecl_disable_interrupts();
	ret = getsockopt(ecl_to_int(v1fd),ecl_to_int(v2level),ecl_to_int(v3const),wincoerce(char*,&sockopt),&socklen);
	ecl_enable_interrupts();

        v5= (ret == 0) ? ecl_make_integer(sockopt) : ECL_NIL;
}
    v4ret = v5;
   }
   if (Null(v4ret)) { goto L2; }
   value0 = ecl_make_bool(!ecl_number_equalp(v4ret,ecl_make_fixnum(0)));
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
   T0 = ecl_cstring_to_base_string_or_nil(strerror(errno));
   value0 = cl_error(2, _ecl_static_43, T0);
   return value0;
  }
 }
}
/*	function definition for GET-SOCKOPT-TIMEVAL                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L54get_sockopt_timeval(cl_object v1fd, cl_object v2level, cl_object v3const)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4ret;
   {
    cl_object v5;
    {
	struct timeval tv;
        socklen_t socklen = sizeof(struct timeval);
        int ret;

	ecl_disable_interrupts();
	ret = getsockopt(ecl_to_int(v1fd),ecl_to_int(v2level),ecl_to_int(v3const),wincoerce(char*,&tv),&socklen);
	ecl_enable_interrupts();

        v5= (ret == 0) ? ecl_make_doublefloat((double)tv.tv_sec
					+ ((double)tv.tv_usec) / 1000000.0) : ECL_NIL;
}
    v4ret = v5;
   }
   if (Null(v4ret)) { goto L2; }
   value0 = v4ret;
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
   T0 = ecl_cstring_to_base_string_or_nil(strerror(errno));
   value0 = cl_error(2, _ecl_static_43, T0);
   return value0;
  }
 }
}
/*	function definition for GET-SOCKOPT-LINGER                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L55get_sockopt_linger(cl_object v1fd, cl_object v2level, cl_object v3const)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v4ret;
   {
    cl_object v5;
    {
	struct linger sockopt;
	socklen_t socklen = sizeof(struct linger);
	int ret;

	ecl_disable_interrupts();
	ret = getsockopt(ecl_to_int(v1fd),ecl_to_int(v2level),ecl_to_int(v3const),wincoerce(char*,&sockopt),&socklen);
	ecl_enable_interrupts();

	v5= (ret == 0) ? ecl_make_integer((sockopt.l_onoff != 0) ? sockopt.l_linger : 0) : ECL_NIL;
}
    v4ret = v5;
   }
   if (Null(v4ret)) { goto L2; }
   value0 = v4ret;
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
   T0 = ecl_cstring_to_base_string_or_nil(strerror(errno));
   value0 = cl_error(2, _ecl_static_43, T0);
   return value0;
  }
 }
}
/*	function definition for SET-SOCKOPT-INT                       */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L56set_sockopt_int(cl_object v1fd, cl_object v2level, cl_object v3const, cl_object v4value)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v5ret;
   {
    cl_object v6;
    {
        int sockopt = ecl_to_int(v4value);
        int ret;

	ecl_disable_interrupts();
	ret = setsockopt(ecl_to_int(v1fd),ecl_to_int(v2level),ecl_to_int(v3const),wincoerce(char *,&sockopt),sizeof(int));
	ecl_enable_interrupts();

        v6= (ret == 0) ? ECL_T : ECL_NIL;
}
    v5ret = v6;
   }
   if (Null(v5ret)) { goto L2; }
   value0 = v4value;
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
   T0 = ecl_cstring_to_base_string_or_nil(strerror(errno));
   value0 = cl_error(2, _ecl_static_43, T0);
   return value0;
  }
 }
}
/*	function definition for SET-SOCKOPT-BOOL                      */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L57set_sockopt_bool(cl_object v1fd, cl_object v2level, cl_object v3const, cl_object v4value)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v5ret;
   {
    cl_object v6;
    {
        int sockopt = (v4value == ECL_NIL) ? 0 : 1;
        int ret;

	ecl_disable_interrupts();
	ret = setsockopt(ecl_to_int(v1fd),ecl_to_int(v2level),ecl_to_int(v3const),wincoerce(char *,&sockopt),sizeof(int));
	ecl_enable_interrupts();

        v6= (ret == 0) ? ECL_T : ECL_NIL;
}
    v5ret = v6;
   }
   if (Null(v5ret)) { goto L2; }
   value0 = v4value;
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
   T0 = ecl_cstring_to_base_string_or_nil(strerror(errno));
   value0 = cl_error(2, _ecl_static_43, T0);
   return value0;
  }
 }
}
/*	function definition for SET-SOCKOPT-TIMEVAL                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L58set_sockopt_timeval(cl_object v1fd, cl_object v2level, cl_object v3const, cl_object v4value)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v5ret;
   {
    cl_object v6;
    {
	struct timeval tv;
	double tmp = ecl_to_double(v4value);
	int ret;

	ecl_disable_interrupts();
	tv.tv_sec = (int)tmp;
	tv.tv_usec = (int)((tmp-floor(tmp))*1000000.0);
        ret = setsockopt(ecl_to_int(v1fd),ecl_to_int(v2level),ecl_to_int(v3const),&tv,sizeof(struct timeval));
	ecl_enable_interrupts();

        v6= (ret == 0) ? ECL_T : ECL_NIL;
}
    v5ret = v6;
   }
   if (Null(v5ret)) { goto L2; }
   value0 = v4value;
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
   T0 = ecl_cstring_to_base_string_or_nil(strerror(errno));
   value0 = cl_error(2, _ecl_static_43, T0);
   return value0;
  }
 }
}
/*	function definition for SET-SOCKOPT-LINGER                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L59set_sockopt_linger(cl_object v1fd, cl_object v2level, cl_object v3const, cl_object v4value)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v5ret;
   {
    cl_object v6;
    {
	struct linger sockopt = {0, 0};
	int value = ecl_to_int(v4value);
	int ret;

	if (value > 0) {
		sockopt.l_onoff = 1;
		sockopt.l_linger = value;
	}

	ecl_disable_interrupts();
	ret = setsockopt(ecl_to_int(v1fd),ecl_to_int(v2level),ecl_to_int(v3const),wincoerce(char *,&sockopt),
			 sizeof(struct linger));
	ecl_enable_interrupts();

	v6= (ret == 0) ? ECL_T : ECL_NIL;
}
    v5ret = v6;
   }
   if (Null(v5ret)) { goto L2; }
   value0 = v4value;
   cl_env_copy->nvalues = 1;
   return value0;
L2:;
   T0 = ecl_cstring_to_base_string_or_nil(strerror(errno));
   value0 = cl_error(2, _ecl_static_43, T0);
   return value0;
  }
 }
}
/*	local function DEFINE-SOCKOPT                                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object LC60define_sockopt(cl_object v1, cl_object v2)
{
 cl_object T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  {
   cl_object v3;
   cl_object v4name;
   cl_object v5c_level;
   cl_object v6c_const;
   cl_object v7type;
   cl_object v8read_only;
   v3 = ecl_cdr(v1);
   if (!(v3==ECL_NIL)) { goto L3; }
   si_dm_too_few_arguments(v1);
L3:;
   {
    cl_object v9;
    v9 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v4name = v9;
   }
   if (!(v3==ECL_NIL)) { goto L9; }
   si_dm_too_few_arguments(v1);
L9:;
   {
    cl_object v9;
    v9 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v5c_level = v9;
   }
   if (!(v3==ECL_NIL)) { goto L15; }
   si_dm_too_few_arguments(v1);
L15:;
   {
    cl_object v9;
    v9 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v6c_const = v9;
   }
   if (!(v3==ECL_NIL)) { goto L21; }
   si_dm_too_few_arguments(v1);
L21:;
   {
    cl_object v9;
    v9 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v7type = v9;
   }
   if (Null(v3)) { goto L27; }
   {
    cl_object v9;
    v9 = ecl_car(v3);
    v3 = ecl_cdr(v3);
    v8read_only = v9;
    goto L26;
   }
L27:;
   v8read_only = ECL_NIL;
L26:;
   if (Null(v3)) { goto L32; }
   si_dm_too_many_arguments(v1);
L32:;
   T0 = cl_list(2, ECL_SYM("QUOTE",679), v4name);
   T1 = cl_list(2, ECL_SYM("EXPORT",344), T0);
   T2 = cl_format(3, ECL_NIL, _ecl_static_44, v7type);
   T3 = cl_intern(1, T2);
   T4 = cl_list(2, VV[56], v5c_level);
   T5 = cl_list(2, VV[56], v6c_const);
   T6 = cl_list(4, T3, VV[123], T4, T5);
   T7 = cl_list(4, ECL_SYM("DEFUN",289), v4name, VV[122], T6);
   if ((v8read_only)!=ECL_NIL) { goto L35; }
   T9 = cl_list(2, ECL_SYM("SETF",750), v4name);
   T10 = cl_format(3, ECL_NIL, _ecl_static_45, v7type);
   T11 = cl_intern(1, T10);
   T12 = cl_list(2, VV[56], v5c_level);
   T13 = cl_list(2, VV[56], v6c_const);
   T14 = cl_list(5, T11, VV[123], T12, T13, VV[125]);
   T15 = cl_list(4, ECL_SYM("DEFUN",289), T9, VV[124], T14);
   T8 = ecl_list1(T15);
   goto L34;
L35:;
   T8 = ECL_NIL;
L34:;
   value0 = cl_listX(4, ECL_SYM("PROGN",671), T1, T7, T8);
   return value0;
  }
 }
}
/*	function definition for SOCKOPT-TYPE                          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L61sockopt_type(cl_object v1socket)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[171])(1, v1socket) /*  SOCKET-FILE-DESCRIPTOR */;
  {
   cl_fixnum v2;
   v2 = (cl_fixnum)(SOL_SOCKET);
   {
    cl_fixnum v3;
    v3 = (cl_fixnum)(SO_TYPE);
    value0 = L52get_sockopt_int(T0, ecl_make_fixnum(v2), ecl_make_fixnum(v3));
    return value0;
   }
  }
 }
}
/*	function definition for SOCKOPT-RECEIVE-BUFFER                */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L62sockopt_receive_buffer(cl_object v1socket)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[171])(1, v1socket) /*  SOCKET-FILE-DESCRIPTOR */;
  {
   cl_fixnum v2;
   v2 = (cl_fixnum)(SOL_SOCKET);
   {
    cl_fixnum v3;
    v3 = (cl_fixnum)(SO_RCVBUF);
    value0 = L52get_sockopt_int(T0, ecl_make_fixnum(v2), ecl_make_fixnum(v3));
    return value0;
   }
  }
 }
}
/*	function definition for (SETF SOCKOPT-RECEIVE-BUFFER)         */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L63_setf_sockopt_receive_buffer_(cl_object v1value, cl_object v2socket)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[171])(1, v2socket) /*  SOCKET-FILE-DESCRIPTOR */;
  {
   cl_fixnum v3;
   v3 = (cl_fixnum)(SOL_SOCKET);
   {
    cl_fixnum v4;
    v4 = (cl_fixnum)(SO_RCVBUF);
    value0 = L56set_sockopt_int(T0, ecl_make_fixnum(v3), ecl_make_fixnum(v4), v1value);
    return value0;
   }
  }
 }
}
/*	function definition for SOCKOPT-RECEIVE-TIMEOUT               */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L64sockopt_receive_timeout(cl_object v1socket)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[171])(1, v1socket) /*  SOCKET-FILE-DESCRIPTOR */;
  {
   cl_fixnum v2;
   v2 = (cl_fixnum)(SOL_SOCKET);
   {
    cl_fixnum v3;
    v3 = (cl_fixnum)(SO_RCVTIMEO);
    value0 = L54get_sockopt_timeval(T0, ecl_make_fixnum(v2), ecl_make_fixnum(v3));
    return value0;
   }
  }
 }
}
/*	function definition for (SETF SOCKOPT-RECEIVE-TIMEOUT)        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L65_setf_sockopt_receive_timeout_(cl_object v1value, cl_object v2socket)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[171])(1, v2socket) /*  SOCKET-FILE-DESCRIPTOR */;
  {
   cl_fixnum v3;
   v3 = (cl_fixnum)(SOL_SOCKET);
   {
    cl_fixnum v4;
    v4 = (cl_fixnum)(SO_RCVTIMEO);
    value0 = L58set_sockopt_timeval(T0, ecl_make_fixnum(v3), ecl_make_fixnum(v4), v1value);
    return value0;
   }
  }
 }
}
/*	function definition for SOCKOPT-SEND-TIMEOUT                  */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L66sockopt_send_timeout(cl_object v1socket)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[171])(1, v1socket) /*  SOCKET-FILE-DESCRIPTOR */;
  {
   cl_fixnum v2;
   v2 = (cl_fixnum)(SOL_SOCKET);
   {
    cl_fixnum v3;
    v3 = (cl_fixnum)(SO_SNDTIMEO);
    value0 = L54get_sockopt_timeval(T0, ecl_make_fixnum(v2), ecl_make_fixnum(v3));
    return value0;
   }
  }
 }
}
/*	function definition for (SETF SOCKOPT-SEND-TIMEOUT)           */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L67_setf_sockopt_send_timeout_(cl_object v1value, cl_object v2socket)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[171])(1, v2socket) /*  SOCKET-FILE-DESCRIPTOR */;
  {
   cl_fixnum v3;
   v3 = (cl_fixnum)(SOL_SOCKET);
   {
    cl_fixnum v4;
    v4 = (cl_fixnum)(SO_SNDTIMEO);
    value0 = L58set_sockopt_timeval(T0, ecl_make_fixnum(v3), ecl_make_fixnum(v4), v1value);
    return value0;
   }
  }
 }
}
/*	function definition for SOCKOPT-REUSE-ADDRESS                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L68sockopt_reuse_address(cl_object v1socket)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[171])(1, v1socket) /*  SOCKET-FILE-DESCRIPTOR */;
  {
   cl_fixnum v2;
   v2 = (cl_fixnum)(SOL_SOCKET);
   {
    cl_fixnum v3;
    v3 = (cl_fixnum)(SO_REUSEADDR);
    value0 = L53get_sockopt_bool(T0, ecl_make_fixnum(v2), ecl_make_fixnum(v3));
    return value0;
   }
  }
 }
}
/*	function definition for (SETF SOCKOPT-REUSE-ADDRESS)          */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L69_setf_sockopt_reuse_address_(cl_object v1value, cl_object v2socket)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[171])(1, v2socket) /*  SOCKET-FILE-DESCRIPTOR */;
  {
   cl_fixnum v3;
   v3 = (cl_fixnum)(SOL_SOCKET);
   {
    cl_fixnum v4;
    v4 = (cl_fixnum)(SO_REUSEADDR);
    value0 = L57set_sockopt_bool(T0, ecl_make_fixnum(v3), ecl_make_fixnum(v4), v1value);
    return value0;
   }
  }
 }
}
/*	function definition for SOCKOPT-KEEP-ALIVE                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L70sockopt_keep_alive(cl_object v1socket)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[171])(1, v1socket) /*  SOCKET-FILE-DESCRIPTOR */;
  {
   cl_fixnum v2;
   v2 = (cl_fixnum)(SOL_SOCKET);
   {
    cl_fixnum v3;
    v3 = (cl_fixnum)(SO_KEEPALIVE);
    value0 = L53get_sockopt_bool(T0, ecl_make_fixnum(v2), ecl_make_fixnum(v3));
    return value0;
   }
  }
 }
}
/*	function definition for (SETF SOCKOPT-KEEP-ALIVE)             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L71_setf_sockopt_keep_alive_(cl_object v1value, cl_object v2socket)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[171])(1, v2socket) /*  SOCKET-FILE-DESCRIPTOR */;
  {
   cl_fixnum v3;
   v3 = (cl_fixnum)(SOL_SOCKET);
   {
    cl_fixnum v4;
    v4 = (cl_fixnum)(SO_KEEPALIVE);
    value0 = L57set_sockopt_bool(T0, ecl_make_fixnum(v3), ecl_make_fixnum(v4), v1value);
    return value0;
   }
  }
 }
}
/*	function definition for SOCKOPT-DONT-ROUTE                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L72sockopt_dont_route(cl_object v1socket)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[171])(1, v1socket) /*  SOCKET-FILE-DESCRIPTOR */;
  {
   cl_fixnum v2;
   v2 = (cl_fixnum)(SOL_SOCKET);
   {
    cl_fixnum v3;
    v3 = (cl_fixnum)(SO_DONTROUTE);
    value0 = L53get_sockopt_bool(T0, ecl_make_fixnum(v2), ecl_make_fixnum(v3));
    return value0;
   }
  }
 }
}
/*	function definition for (SETF SOCKOPT-DONT-ROUTE)             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L73_setf_sockopt_dont_route_(cl_object v1value, cl_object v2socket)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[171])(1, v2socket) /*  SOCKET-FILE-DESCRIPTOR */;
  {
   cl_fixnum v3;
   v3 = (cl_fixnum)(SOL_SOCKET);
   {
    cl_fixnum v4;
    v4 = (cl_fixnum)(SO_DONTROUTE);
    value0 = L57set_sockopt_bool(T0, ecl_make_fixnum(v3), ecl_make_fixnum(v4), v1value);
    return value0;
   }
  }
 }
}
/*	function definition for SOCKOPT-LINGER                        */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L74sockopt_linger(cl_object v1socket)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[171])(1, v1socket) /*  SOCKET-FILE-DESCRIPTOR */;
  {
   cl_fixnum v2;
   v2 = (cl_fixnum)(SOL_SOCKET);
   {
    cl_fixnum v3;
    v3 = (cl_fixnum)(SO_LINGER);
    value0 = L55get_sockopt_linger(T0, ecl_make_fixnum(v2), ecl_make_fixnum(v3));
    return value0;
   }
  }
 }
}
/*	function definition for (SETF SOCKOPT-LINGER)                 */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L75_setf_sockopt_linger_(cl_object v1value, cl_object v2socket)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[171])(1, v2socket) /*  SOCKET-FILE-DESCRIPTOR */;
  {
   cl_fixnum v3;
   v3 = (cl_fixnum)(SOL_SOCKET);
   {
    cl_fixnum v4;
    v4 = (cl_fixnum)(SO_LINGER);
    value0 = L59set_sockopt_linger(T0, ecl_make_fixnum(v3), ecl_make_fixnum(v4), v1value);
    return value0;
   }
  }
 }
}
/*	function definition for SOCKOPT-REUSE-PORT                    */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L76sockopt_reuse_port(cl_object v1socket)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[171])(1, v1socket) /*  SOCKET-FILE-DESCRIPTOR */;
  {
   cl_fixnum v2;
   v2 = (cl_fixnum)(SOL_SOCKET);
   {
    cl_fixnum v3;
    v3 = (cl_fixnum)(SO_REUSEPORT);
    value0 = L53get_sockopt_bool(T0, ecl_make_fixnum(v2), ecl_make_fixnum(v3));
    return value0;
   }
  }
 }
}
/*	function definition for (SETF SOCKOPT-REUSE-PORT)             */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L77_setf_sockopt_reuse_port_(cl_object v1value, cl_object v2socket)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[171])(1, v2socket) /*  SOCKET-FILE-DESCRIPTOR */;
  {
   cl_fixnum v3;
   v3 = (cl_fixnum)(SOL_SOCKET);
   {
    cl_fixnum v4;
    v4 = (cl_fixnum)(SO_REUSEPORT);
    value0 = L57set_sockopt_bool(T0, ecl_make_fixnum(v3), ecl_make_fixnum(v4), v1value);
    return value0;
   }
  }
 }
}
/*	function definition for SOCKOPT-TCP-NODELAY                   */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L78sockopt_tcp_nodelay(cl_object v1socket)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[171])(1, v1socket) /*  SOCKET-FILE-DESCRIPTOR */;
  {
   cl_fixnum v2;
   v2 = (cl_fixnum)(IPPROTO_TCP);
   {
    cl_fixnum v3;
    v3 = (cl_fixnum)(TCP_NODELAY);
    value0 = L53get_sockopt_bool(T0, ecl_make_fixnum(v2), ecl_make_fixnum(v3));
    return value0;
   }
  }
 }
}
/*	function definition for (SETF SOCKOPT-TCP-NODELAY)            */
/*	optimize speed 1, debug 1, space 1, safety 2                  */
static cl_object L79_setf_sockopt_tcp_nodelay_(cl_object v1value, cl_object v2socket)
{
 cl_object T0;
 const cl_env_ptr cl_env_copy = ecl_process_env();
 cl_object value0;
 ecl_cs_check(cl_env_copy,value0);
 {
TTL:
  T0 = ecl_function_dispatch(cl_env_copy,VV[171])(1, v2socket) /*  SOCKET-FILE-DESCRIPTOR */;
  {
   cl_fixnum v3;
   v3 = (cl_fixnum)(IPPROTO_TCP);
   {
    cl_fixnum v4;
    v4 = (cl_fixnum)(TCP_NODELAY);
    value0 = L57set_sockopt_bool(T0, ecl_make_fixnum(v3), ecl_make_fixnum(v4), v1value);
    return value0;
   }
  }
 }
}

#include "ext/sockets.data"
#ifdef __cplusplus
extern "C"
#endif
ECL_DLLEXPORT void _eclekPx67Hqtmli9_CSzkfE21(cl_object flag)
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
 flag->cblock.source = make_constant_base_string("EXT:SOCKETS;SOCKETS.LISP.NEWEST");
 return;}
 #ifdef ECL_DYNAMIC_VV
 VV = Cblock->cblock.data;
 #endif
 Cblock->cblock.data_text = "@EcLtAg:_eclekPx67Hqtmli9_CSzkfE21@";
 VVtemp = Cblock->cblock.temp_data;
 ECL_DEFINE_SETF_FUNCTIONS
 si_select_package(_ecl_static_0);
 {
  cl_fixnum v1;
  v1 = (cl_fixnum)(AF_INET);
  si_Xmake_constant(VV[0], ecl_make_fixnum(v1));
 }
 {
  cl_fixnum v1;
  v1 = (cl_fixnum)(AF_LOCAL);
  si_Xmake_constant(VV[1], ecl_make_fixnum(v1));
 }
 {
  cl_fixnum v1;
  v1 = (cl_fixnum)(EAGAIN);
  si_Xmake_constant(VV[2], ecl_make_fixnum(v1));
 }
 {
  cl_fixnum v1;
  v1 = (cl_fixnum)(EINTR);
  si_Xmake_constant(VV[3], ecl_make_fixnum(v1));
 }
 ecl_cmp_defun(VV[158]);                          /*  FF-SOCKET       */
 ecl_cmp_defun(VV[159]);                          /*  FF-LISTEN       */
 ecl_cmp_defun(VV[160]);                          /*  FF-CLOSE        */
 ecl_cmp_defun(VV[161]);                          /*  SPLIT           */
 {
  cl_object T0;
 T0 = cl_list(2, ECL_SYM("DOCUMENTATION",1222), _ecl_static_1);
 clos_load_defclass(VV[9], ECL_NIL, VVtemp[0], T0);
 }
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, VV[10], VV[11], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[1], ECL_SYM("DOCUMENTATION",1222), _ecl_static_1) /*  ENSURE-GENERIC-FUNCTION */;
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC6__g28,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, VV[10], ECL_NIL, VVtemp[1], VVtemp[1], T0, ECL_T);
 }
 ecl_cmp_defun(VV[163]);                          /*  GET-HOST-BY-NAME */
 ecl_cmp_defun(VV[168]);                          /*  GET-HOST-BY-ADDRESS */
 {
  cl_object T0, T1, T2, T3;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC9__g32,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 T1 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T0, VVtemp[3]);
 T2 = cl_list(5, VVtemp[2], T1, VVtemp[4], VVtemp[5], VVtemp[6]);
 T3 = cl_list(2, ECL_SYM("DOCUMENTATION",1222), _ecl_static_5);
 clos_load_defclass(VV[15], ECL_NIL, T2, T3);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC11__g33,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("PRINT-OBJECT",961), ECL_NIL, VVtemp[7], VVtemp[8], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC12__g48,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, ECL_SYM("SHARED-INITIALIZE",965), VVtemp[9], VVtemp[7], VVtemp[10], T0, ECL_T);
 }
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, VV[22], VV[11], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[11], ECL_SYM("DOCUMENTATION",1222), _ecl_static_8) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, VV[23], VV[11], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[12], ECL_SYM("DOCUMENTATION",1222), _ecl_static_9) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, VV[24], VV[11], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[11], ECL_SYM("DOCUMENTATION",1222), _ecl_static_10) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, VV[25], VV[11], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[12], ECL_SYM("DOCUMENTATION",1222), _ecl_static_11) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, VV[26], VV[11], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[12], ECL_SYM("DOCUMENTATION",1222), _ecl_static_12) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, VV[27], VV[11], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[13], ECL_SYM("DOCUMENTATION",1222), _ecl_static_13) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, VV[28], VV[11], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[14], ECL_SYM("DOCUMENTATION",1222), _ecl_static_14) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, VV[29], VV[11], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[15], ECL_SYM("DOCUMENTATION",1222), _ecl_static_15) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, VV[30], VV[11], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[12], ECL_SYM("DOCUMENTATION",1222), _ecl_static_16) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, VV[31], VV[11], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[16], ECL_SYM("DOCUMENTATION",1222), _ecl_static_17) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, VV[32], VV[11], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[12], ECL_SYM("DOCUMENTATION",1222), _ecl_static_18) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, VVtemp[17], VV[11], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[18], ECL_SYM("DOCUMENTATION",1222), _ecl_static_19) /*  ENSURE-GENERIC-FUNCTION */;
 (cl_env_copy->function=(ECL_SYM("ENSURE-GENERIC-FUNCTION",942)->symbol.gfdef))->cfun.entry(7, VV[33], VV[11], ECL_T, ECL_SYM("LAMBDA-LIST",998), VVtemp[12], ECL_SYM("DOCUMENTATION",1222), _ecl_static_20) /*  ENSURE-GENERIC-FUNCTION */;
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC13__g59,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VV[27], ECL_NIL, VVtemp[7], VVtemp[13], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC14__g60,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, VV[33], ECL_NIL, VVtemp[12], VVtemp[12], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC15__g67,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, VV[30], ECL_NIL, VVtemp[12], VVtemp[12], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC16__g71,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, VV[28], ECL_NIL, VVtemp[19], VVtemp[14], T0, ECL_T);
 }
 ecl_cmp_defun(VV[179]);                          /*  GET-PROTOCOL-BY-NAME */
 ecl_cmp_defun(VV[180]);                          /*  MAKE-INET-ADDRESS */
 {
  cl_object T0, T1, T2, T3;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC19__g76,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 T1 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T0, VVtemp[20]);
 T2 = ecl_list1(T1);
 T3 = cl_list(2, ECL_SYM("DOCUMENTATION",1222), _ecl_static_25);
 clos_load_defclass(VV[37], VVtemp[12], T2, T3);
 }
 ecl_cmp_defun(VV[181]);                          /*  MAKE-INET-SOCKET */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC21__g79,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, VV[22], ECL_NIL, VVtemp[21], VVtemp[11], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC22__g85,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, VV[23], ECL_NIL, VVtemp[21], VVtemp[12], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC23__g86,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, VV[24], ECL_NIL, VVtemp[21], VVtemp[11], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC24__g89,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, VV[25], ECL_NIL, VVtemp[21], VVtemp[12], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC25__g90,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, VV[26], ECL_NIL, VVtemp[21], VVtemp[12], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC26__g91,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, VV[29], ECL_NIL, VVtemp[19], VVtemp[15], T0, ECL_T);
 }
 {
  cl_object T0, T1, T2, T3;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC27__g98,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 T1 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T0, VVtemp[22]);
 T2 = ecl_list1(T1);
 T3 = cl_list(2, ECL_SYM("DOCUMENTATION",1222), _ecl_static_33);
 clos_load_defclass(VV[44], VVtemp[12], T2, T3);
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC28__g101,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, VV[22], ECL_NIL, VVtemp[23], VVtemp[11], T0, ECL_T);
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC29__g109,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, VV[23], ECL_NIL, VVtemp[23], VVtemp[12], T0, ECL_T);
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC30__g112,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, VV[24], ECL_NIL, VVtemp[23], VVtemp[11], T0, ECL_T);
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC31__g120,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, VV[25], ECL_NIL, VVtemp[23], VVtemp[12], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC32__g121,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, VV[32], ECL_NIL, VVtemp[12], VVtemp[12], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC33__g122,ECL_NIL,Cblock,2);
  T0 = v1;
 }
 clos_install_method(6, VVtemp[17], ECL_NIL, VVtemp[24], VVtemp[18], T0, ECL_T);
 }
 ecl_cmp_defun(VV[192]);                          /*  DUP             */
 ecl_cmp_defun(VV[193]);                          /*  MAKE-STREAM-FROM-FD */
 (void)0; /* No entry created for AUTO-CLOSE-TWO-WAY-STREAM */
 ecl_cmp_defun(VV[198]);                          /*  SOCKET-MAKE-STREAM-INNER */
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun_va((cl_objectfn)LC38__g142,ECL_NIL,Cblock);
  T0 = v1;
 }
 clos_install_method(6, VV[31], ECL_NIL, VVtemp[12], VVtemp[25], T0, ECL_T);
 }
 {
  cl_object T0;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC39__g149,ECL_NIL,Cblock,1);
  T0 = v1;
 }
 clos_install_method(6, VV[54], ECL_NIL, VVtemp[12], VVtemp[12], T0, ECL_T);
 }
 {
  cl_object T0, T1, T2, T3;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC41__g150,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 T1 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T0, VVtemp[27]);
 T2 = cl_list(4, T1, VVtemp[28], VVtemp[29], VVtemp[30]);
 T3 = cl_list(2, ECL_SYM("DOCUMENTATION",1222), _ecl_static_41);
 clos_load_defclass(VV[55], VVtemp[26], T2, T3);
 }
 ecl_cmp_defmacro(VV[206]);                       /*  DEFINE-SOCKET-CONDITION */
 si_Xmake_special(VV[59]);
 cl_set(VV[59],ECL_NIL);
 {
  cl_object T0;
 {
  cl_fixnum v1;
  v1 = (cl_fixnum)(EADDRINUSE);
  si_Xmake_constant(VV[61], ecl_make_fixnum(v1));
 }
 clos_load_defclass(VV[62], VV[57], VVtemp[31], ECL_NIL);
 cl_export(1, VV[62]);
 T0 = CONS(ecl_symbol_value(VV[61]),VV[62]);
 cl_set(VV[59],CONS(T0,ecl_symbol_value(VV[59])));
 }
 {
  cl_object T0;
 {
  cl_fixnum v1;
  v1 = (cl_fixnum)(EAGAIN);
  si_Xmake_constant(VV[63], ecl_make_fixnum(v1));
 }
 clos_load_defclass(VV[64], VV[57], VVtemp[32], ECL_NIL);
 cl_export(1, VV[64]);
 T0 = CONS(ecl_symbol_value(VV[63]),VV[64]);
 cl_set(VV[59],CONS(T0,ecl_symbol_value(VV[59])));
 }
 {
  cl_object T0;
 {
  cl_fixnum v1;
  v1 = (cl_fixnum)(EBADF);
  si_Xmake_constant(VV[65], ecl_make_fixnum(v1));
 }
 clos_load_defclass(VV[66], VV[57], VVtemp[33], ECL_NIL);
 cl_export(1, VV[66]);
 T0 = CONS(ecl_symbol_value(VV[65]),VV[66]);
 cl_set(VV[59],CONS(T0,ecl_symbol_value(VV[59])));
 }
 {
  cl_object T0;
 {
  cl_fixnum v1;
  v1 = (cl_fixnum)(ECONNREFUSED);
  si_Xmake_constant(VV[67], ecl_make_fixnum(v1));
 }
 clos_load_defclass(VV[68], VV[57], VVtemp[34], ECL_NIL);
 cl_export(1, VV[68]);
 T0 = CONS(ecl_symbol_value(VV[67]),VV[68]);
 cl_set(VV[59],CONS(T0,ecl_symbol_value(VV[59])));
 }
 {
  cl_object T0;
 {
  cl_fixnum v1;
  v1 = (cl_fixnum)(ETIMEDOUT);
  si_Xmake_constant(VV[69], ecl_make_fixnum(v1));
 }
 clos_load_defclass(VV[70], VV[57], VVtemp[35], ECL_NIL);
 cl_export(1, VV[70]);
 T0 = CONS(ecl_symbol_value(VV[69]),VV[70]);
 cl_set(VV[59],CONS(T0,ecl_symbol_value(VV[59])));
 }
 {
  cl_object T0;
 {
  cl_fixnum v1;
  v1 = (cl_fixnum)(EINTR);
  si_Xmake_constant(VV[71], ecl_make_fixnum(v1));
 }
 clos_load_defclass(VV[64], VV[57], VVtemp[36], ECL_NIL);
 cl_export(1, VV[64]);
 T0 = CONS(ecl_symbol_value(VV[71]),VV[64]);
 cl_set(VV[59],CONS(T0,ecl_symbol_value(VV[59])));
 }
 {
  cl_object T0;
 {
  cl_fixnum v1;
  v1 = (cl_fixnum)(EINVAL);
  si_Xmake_constant(VV[72], ecl_make_fixnum(v1));
 }
 clos_load_defclass(VV[73], VV[57], VVtemp[37], ECL_NIL);
 cl_export(1, VV[73]);
 T0 = CONS(ecl_symbol_value(VV[72]),VV[73]);
 cl_set(VV[59],CONS(T0,ecl_symbol_value(VV[59])));
 }
 {
  cl_object T0;
 {
  cl_fixnum v1;
  v1 = (cl_fixnum)(ENOBUFS);
  si_Xmake_constant(VV[74], ecl_make_fixnum(v1));
 }
 clos_load_defclass(VV[75], VV[57], VVtemp[38], ECL_NIL);
 cl_export(1, VV[75]);
 T0 = CONS(ecl_symbol_value(VV[74]),VV[75]);
 cl_set(VV[59],CONS(T0,ecl_symbol_value(VV[59])));
 }
 {
  cl_object T0;
 {
  cl_fixnum v1;
  v1 = (cl_fixnum)(ENOMEM);
  si_Xmake_constant(VV[76], ecl_make_fixnum(v1));
 }
 clos_load_defclass(VV[77], VV[57], VVtemp[39], ECL_NIL);
 cl_export(1, VV[77]);
 T0 = CONS(ecl_symbol_value(VV[76]),VV[77]);
 cl_set(VV[59],CONS(T0,ecl_symbol_value(VV[59])));
 }
 {
  cl_object T0;
 {
  cl_fixnum v1;
  v1 = (cl_fixnum)(EOPNOTSUPP);
  si_Xmake_constant(VV[78], ecl_make_fixnum(v1));
 }
 clos_load_defclass(VV[79], VV[57], VVtemp[40], ECL_NIL);
 cl_export(1, VV[79]);
 T0 = CONS(ecl_symbol_value(VV[78]),VV[79]);
 cl_set(VV[59],CONS(T0,ecl_symbol_value(VV[59])));
 }
 {
  cl_object T0;
 {
  cl_fixnum v1;
  v1 = (cl_fixnum)(EPERM);
  si_Xmake_constant(VV[80], ecl_make_fixnum(v1));
 }
 clos_load_defclass(VV[81], VV[57], VVtemp[41], ECL_NIL);
 cl_export(1, VV[81]);
 T0 = CONS(ecl_symbol_value(VV[80]),VV[81]);
 cl_set(VV[59],CONS(T0,ecl_symbol_value(VV[59])));
 }
 {
  cl_object T0;
 {
  cl_fixnum v1;
  v1 = (cl_fixnum)(EPROTONOSUPPORT);
  si_Xmake_constant(VV[82], ecl_make_fixnum(v1));
 }
 clos_load_defclass(VV[83], VV[57], VVtemp[42], ECL_NIL);
 cl_export(1, VV[83]);
 T0 = CONS(ecl_symbol_value(VV[82]),VV[83]);
 cl_set(VV[59],CONS(T0,ecl_symbol_value(VV[59])));
 }
 {
  cl_object T0;
 {
  cl_fixnum v1;
  v1 = (cl_fixnum)(ESOCKTNOSUPPORT);
  si_Xmake_constant(VV[84], ecl_make_fixnum(v1));
 }
 clos_load_defclass(VV[85], VV[57], VVtemp[43], ECL_NIL);
 cl_export(1, VV[85]);
 T0 = CONS(ecl_symbol_value(VV[84]),VV[85]);
 cl_set(VV[59],CONS(T0,ecl_symbol_value(VV[59])));
 }
 {
  cl_object T0;
 {
  cl_fixnum v1;
  v1 = (cl_fixnum)(ENETUNREACH);
  si_Xmake_constant(VV[86], ecl_make_fixnum(v1));
 }
 clos_load_defclass(VV[87], VV[57], VVtemp[44], ECL_NIL);
 cl_export(1, VV[87]);
 T0 = CONS(ecl_symbol_value(VV[86]),VV[87]);
 cl_set(VV[59],CONS(T0,ecl_symbol_value(VV[59])));
 }
 ecl_cmp_defun(VV[207]);                          /*  CONDITION-FOR-ERRNO */
 ecl_cmp_defun(VV[208]);                          /*  SOCKET-ERROR    */
 si_Xmake_special(VV[92]);
 if (ecl_boundp(cl_env_copy,VV[92])) { goto L301; }
 cl_set(VV[92],ecl_make_fixnum(0));
L301:;
 ecl_cmp_defun(VV[209]);                          /*  NAME-SERVICE-ERROR */
 {
  cl_object T0, T1, T2;
 {cl_object v1;
  v1 = ECL_NIL;
  v1 = ecl_make_cfun((cl_objectfn_fixed)LC47__g174,ECL_NIL,Cblock,0);
  T0 = v1;
 }
 T1 = cl_listX(3, ECL_SYM("INITFUNCTION",997), T0, VVtemp[46]);
 T2 = cl_list(4, T1, VVtemp[47], VVtemp[48], VVtemp[49]);
 clos_load_defclass(VV[93], VVtemp[45], T2, ECL_NIL);
 }
 ecl_cmp_defmacro(VV[212]);                       /*  DEFINE-NAME-SERVICE-CONDITION */
 si_Xmake_special(VV[96]);
 cl_set(VV[96],ECL_NIL);
 {
  cl_object T0;
 {
  cl_fixnum v1;
  v1 = (cl_fixnum)(NETDB_INTERNAL);
  si_Xmake_constant(VV[98], ecl_make_fixnum(v1));
 }
 clos_load_defclass(VV[99], VV[94], VVtemp[50], ECL_NIL);
 T0 = CONS(ecl_symbol_value(VV[98]),VV[99]);
 cl_set(VV[96],CONS(T0,ecl_symbol_value(VV[96])));
 cl_export(1, VV[98]);
 }
 {
  cl_object T0;
 {
  cl_fixnum v1;
  v1 = (cl_fixnum)(NETDB_SUCCESS);
  si_Xmake_constant(VV[100], ecl_make_fixnum(v1));
 }
 clos_load_defclass(VV[101], VV[94], VVtemp[51], ECL_NIL);
 T0 = CONS(ecl_symbol_value(VV[100]),VV[101]);
 cl_set(VV[96],CONS(T0,ecl_symbol_value(VV[96])));
 cl_export(1, VV[100]);
 }
 {
  cl_object T0;
 {
  cl_fixnum v1;
  v1 = (cl_fixnum)(HOST_NOT_FOUND);
  si_Xmake_constant(VV[102], ecl_make_fixnum(v1));
 }
 clos_load_defclass(VV[103], VV[94], VVtemp[52], ECL_NIL);
 T0 = CONS(ecl_symbol_value(VV[102]),VV[103]);
 cl_set(VV[96],CONS(T0,ecl_symbol_value(VV[96])));
 cl_export(1, VV[102]);
 }
 {
  cl_object T0;
 {
  cl_fixnum v1;
  v1 = (cl_fixnum)(TRY_AGAIN);
  si_Xmake_constant(VV[104], ecl_make_fixnum(v1));
 }
 clos_load_defclass(VV[105], VV[94], VVtemp[53], ECL_NIL);
 T0 = CONS(ecl_symbol_value(VV[104]),VV[105]);
 cl_set(VV[96],CONS(T0,ecl_symbol_value(VV[96])));
 cl_export(1, VV[104]);
 }
 {
  cl_object T0;
 {
  cl_fixnum v1;
  v1 = (cl_fixnum)(NO_RECOVERY);
  si_Xmake_constant(VV[106], ecl_make_fixnum(v1));
 }
 clos_load_defclass(VV[107], VV[94], VVtemp[54], ECL_NIL);
 T0 = CONS(ecl_symbol_value(VV[106]),VV[107]);
 cl_set(VV[96],CONS(T0,ecl_symbol_value(VV[96])));
 cl_export(1, VV[106]);
 }
 {
  cl_object T0;
 {
  cl_fixnum v1;
  v1 = (cl_fixnum)(NO_ADDRESS);
  si_Xmake_constant(VV[108], ecl_make_fixnum(v1));
 }
 clos_load_defclass(VV[109], VV[94], VVtemp[55], ECL_NIL);
 T0 = CONS(ecl_symbol_value(VV[108]),VV[109]);
 cl_set(VV[96],CONS(T0,ecl_symbol_value(VV[96])));
 cl_export(1, VV[108]);
 }
 ecl_cmp_defun(VV[213]);                          /*  CONDITION-FOR-NAME-SERVICE-ERRNO */
 ecl_cmp_defun(VV[214]);                          /*  GET-NAME-SERVICE-ERRNO */
 ecl_cmp_defun(VV[215]);                          /*  GET-NAME-SERVICE-ERROR-MESSAGE */
 ecl_cmp_defun(VV[216]);                          /*  GET-SOCKOPT-INT */
 ecl_cmp_defun(VV[217]);                          /*  GET-SOCKOPT-BOOL */
 ecl_cmp_defun(VV[218]);                          /*  GET-SOCKOPT-TIMEVAL */
 ecl_cmp_defun(VV[219]);                          /*  GET-SOCKOPT-LINGER */
 ecl_cmp_defun(VV[220]);                          /*  SET-SOCKOPT-INT */
 ecl_cmp_defun(VV[221]);                          /*  SET-SOCKOPT-BOOL */
 ecl_cmp_defun(VV[222]);                          /*  SET-SOCKOPT-TIMEVAL */
 ecl_cmp_defun(VV[223]);                          /*  SET-SOCKOPT-LINGER */
 ecl_cmp_defmacro(VV[224]);                       /*  DEFINE-SOCKOPT  */
 cl_export(1, VV[127]);
 ecl_cmp_defun(VV[225]);                          /*  SOCKOPT-TYPE    */
 cl_export(1, VV[129]);
 ecl_cmp_defun(VV[226]);                          /*  SOCKOPT-RECEIVE-BUFFER */
 ecl_cmp_defun(VV[227]);                          /*  (SETF SOCKOPT-RECEIVE-BUFFER) */
 cl_export(1, VV[132]);
 ecl_cmp_defun(VV[228]);                          /*  SOCKOPT-RECEIVE-TIMEOUT */
 ecl_cmp_defun(VV[229]);                          /*  (SETF SOCKOPT-RECEIVE-TIMEOUT) */
 cl_export(1, VV[135]);
 ecl_cmp_defun(VV[230]);                          /*  SOCKOPT-SEND-TIMEOUT */
 ecl_cmp_defun(VV[231]);                          /*  (SETF SOCKOPT-SEND-TIMEOUT) */
 cl_export(1, VV[138]);
 ecl_cmp_defun(VV[232]);                          /*  SOCKOPT-REUSE-ADDRESS */
 ecl_cmp_defun(VV[233]);                          /*  (SETF SOCKOPT-REUSE-ADDRESS) */
 cl_export(1, VV[141]);
 ecl_cmp_defun(VV[234]);                          /*  SOCKOPT-KEEP-ALIVE */
 ecl_cmp_defun(VV[235]);                          /*  (SETF SOCKOPT-KEEP-ALIVE) */
 cl_export(1, VV[144]);
 ecl_cmp_defun(VV[236]);                          /*  SOCKOPT-DONT-ROUTE */
 ecl_cmp_defun(VV[237]);                          /*  (SETF SOCKOPT-DONT-ROUTE) */
 cl_export(1, VV[147]);
 ecl_cmp_defun(VV[238]);                          /*  SOCKOPT-LINGER  */
 ecl_cmp_defun(VV[239]);                          /*  (SETF SOCKOPT-LINGER) */
 cl_export(1, VV[150]);
 ecl_cmp_defun(VV[240]);                          /*  SOCKOPT-REUSE-PORT */
 ecl_cmp_defun(VV[241]);                          /*  (SETF SOCKOPT-REUSE-PORT) */
 cl_export(1, VV[153]);
 ecl_cmp_defun(VV[242]);                          /*  SOCKOPT-TCP-NODELAY */
 ecl_cmp_defun(VV[243]);                          /*  (SETF SOCKOPT-TCP-NODELAY) */
 cl_provide(VV[156]);
 cl_provide(VV[157]);
}
