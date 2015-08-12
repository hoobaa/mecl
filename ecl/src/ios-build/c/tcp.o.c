#line 1 "/Users/strobolights/dev/mecl/ecl/src/c/tcp.d"
/* -*- mode: c; c-basic-offset: 8 -*- */
/* tcp.c  -- stream interface to TCP					*/

/*
    Copyright (c) 1990, Giuseppe Attardi.
    Copyright (c) 2001, Juan Jose Garcia Ripoll.

    ECL is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Library Public License as published
    by the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    See file '../Copyright' for full details.
*/

#include <ecl/ecl.h>
#include <stdio.h>
#include <sys/types.h>
#include <errno.h>

#if defined(ECL_MS_WINDOWS_HOST)
#include <winsock.h>
#else
//extern int errno;
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#endif
#include <string.h>

#if defined(ECL_MS_WINDOWS_HOST)
#include <io.h>
#else
#include <sys/ioctl.h>
#endif

/* Maximum length for a unix socket pathname */
#define UNIX_MAX_PATH	107

#if defined(ECL_MS_WINDOWS_HOST)
WSADATA wsadata;
int wsock_initialized = 0;
#define INIT_TCP								\
	if ( !wsock_initialized )						\
	{									\
		if ( WSAStartup( MAKEWORD( 2, 2 ), &wsadata ) != NO_ERROR )	\
			FEerror( "Unable to initialize Windows socket library.", 0 );	\
		else								\
			wsock_initialized = 1;					\
	}
#else
#define INIT_TCP
#endif

void
ecl_tcp_close_all(void)
{
#if defined(ECL_MS_WINDOWS_HOST)
	if ( wsock_initialized )
	{
		WSACleanup();
		wsock_initialized = 0;
	}
#endif
}

/***********************************************************************
 * Client side
 **********************************************************************/

/* 
 * Attempts to connect to server, given host and port. Returns file 
 * descriptor (network socket) or 0 if connection fails.
 */
static
int connect_to_server(char *host, int port)
{
  struct sockaddr_in inaddr;	/* INET socket address. */
  struct sockaddr *addr;	/* address to connect to */
  struct hostent *host_ptr;
  int addrlen;			/* length of address */
#if !defined(ECL_MS_WINDOWS_HOST)
  extern char *getenv();
  extern struct hostent *gethostbyname();
#endif
  int fd;			/* Network socket */

  INIT_TCP

  /* Get the statistics on the specified host. */
  if ((inaddr.sin_addr.s_addr = inet_addr(host)) == -1) {
    if ((host_ptr = gethostbyname(host)) == NULL) {
      /* No such host! */
      errno = EINVAL;
      return(0);
    }
    /* Check the address type for an internet host. */
    if (host_ptr->h_addrtype != AF_INET) {
      /* Not an Internet host! */
#if defined(ECL_MS_WINDOWS_HOST)
      errno = WSAEPROTOTYPE;
#else
      errno = EPROTOTYPE;
#endif
      return(0);
    }
    /* Set up the socket data. */
    inaddr.sin_family = host_ptr->h_addrtype;
    memcpy((char *)&inaddr.sin_addr, (char *)host_ptr->h_addr,
	   sizeof(inaddr.sin_addr));
  } 
  else
    inaddr.sin_family = AF_INET;

  addr = (struct sockaddr *) &inaddr;
  addrlen = sizeof (struct sockaddr_in);
  inaddr.sin_port = port;
  inaddr.sin_port = htons(inaddr.sin_port);
  /*
   * Open the network connection.
   */
  if ((fd = socket((int) addr->sa_family, SOCK_STREAM, 0)) < 0)
    return(0);			/* errno set by system call. */

  ecl_disable_interrupts();
#ifdef TCP_NODELAY
  /* make sure to turn off TCP coalescence */
#if defined(ECL_MS_WINDOWS_HOST)
  { char mi;
    setsockopt (fd, IPPROTO_TCP, TCP_NODELAY, &mi, sizeof (char));
  }
#else
  { int mi;
    setsockopt (fd, IPPROTO_TCP, TCP_NODELAY, &mi, sizeof (int));
  }
#endif
#endif
  if (connect(fd, addr, addrlen) == -1) {
#if defined(ECL_MS_WINDOWS_HOST)
    closesocket(fd);
#else
    (void) close (fd);
#endif
    fd = 0;
  }
  ecl_enable_interrupts();
  return(fd);
}


/***********************************************************************
 * Server side
 **********************************************************************/
/*
 * Creates a server port. Returns file 
 * descriptor (network socket) or 0 if connection fails.
 */

int
create_server_port(int port)
{
  struct sockaddr_in inaddr;	/* INET socket address. */
  struct sockaddr *addr;	/* address to connect to */
  int addrlen;			/* length of address */
  int request, conn;		/* Network socket */

  INIT_TCP

  /*
   * Open the network connection.
   */
  if ((request = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    return(0);			/* errno set by system call. */
  }

#ifdef SO_REUSEADDR
    /* Necesary to restart the server without a reboot */
#if defined(ECL_MS_WINDOWS_HOST)
    {
	char one = 1;
	setsockopt(request, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(char));
    }
#else
    {
	int one = 1;
	setsockopt(request, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(int));
    }
#endif
#endif /* SO_REUSEADDR */
#ifdef TCP_NODELAY
  /* make sure to turn off TCP coalescence */
#if defined(ECL_MS_WINDOWS_HOST)
  { char mi;
    setsockopt(request, IPPROTO_TCP, TCP_NODELAY, &mi, sizeof (char));
  }
#else
  { int mi;
    setsockopt(request, IPPROTO_TCP, TCP_NODELAY, &mi, sizeof (int));
  }
#endif
#endif

  /* Set up the socket data. */
  memset((char *)&inaddr, 0, sizeof(inaddr));
  inaddr.sin_family = AF_INET;
#if defined(ECL_MS_WINDOWS_HOST)
  inaddr.sin_port = htons((unsigned short)port);
#else
  inaddr.sin_port = htons(port);
#endif
  inaddr.sin_addr.s_addr = htonl(INADDR_ANY);

  if (bind(request, (struct sockaddr *)&inaddr, sizeof (inaddr)))
    FElibc_error("Binding TCP socket", 0);
  if (listen(request, 1))
    FElibc_error("TCP listening", 0);
#if 0 && defined(ECL_THREADS)
  /* Don't make this file-descriptor non-blocking
   * just block on it before we attempt to accept from it
   * Think _hard_ about moving this out of here, into somewhere sane
   * and creating an 'accepting' stream type, which is bound to a port
   * on reading returns streams
   */
  {
    FILE *fp;			/* need to use FILE *'s rather than fd... *sigh* */
    if ((fp = fdopen(request, "r")) == (FILE *)0)
      printf("fdopen didn't work on accept fd!\n"); fflush(stdout);
    fcntl(request, F_SETFL, O_NONBLOCK);
    clearerr(fp);

  loop:	errno = 0;
    if ((conn = accept(request, (struct sockaddr *)NULL, (int *)NULL)) < 0)
    if (errno) {
      lwpblockon(active, fp, PD_INPUT);
      clearerr(fp);
      goto loop;
    } else {
      fclose(fp);
      FElibc_error("Accepting requests", 0);
    }
    fclose(fp);
  }
#else
  if ((conn = accept(request, (struct sockaddr *)NULL, NULL)) < 0)
    FElibc_error("Accepting requests", 0);
#endif	/* THREADS */

  return(conn);
}

/***********************************************************************
 * Public interface to lisp environment
 **********************************************************************/

/* 
   open-client-stream --

   To test this function, try:
   (setq s (si:open-client-stream "host" 13))
   (read-line s)
   "Wed Jun 22 19:44:36 METDST 1994"
*/
cl_object
si_open_client_stream(cl_object host, cl_object port)
{
   int fd, p;			/* file descriptor */
   cl_object stream;

   /* Ensure "host" is a string that we can pass to a C function */
   host = si_copy_to_simple_base_string(host);

   if (ecl_unlikely(!ECL_FIXNUMP(port) ||
                    ecl_fixnum_minusp(port) ||
                    ecl_fixnum_greater(port,ecl_make_fixnum(65536)))) {
           FEwrong_type_nth_arg(ecl_make_fixnum(/*SI::OPEN-CLIENT-STREAM*/1187), 2, port,
                                ecl_read_from_cstring("(INTEGER 0 65535)"));
   }
   p = ecl_fixnum(port);

   if (host->base_string.fillp > BUFSIZ - 1)
     FEerror("~S is a too long file name.", 1, host);

   ecl_disable_interrupts();
   fd = connect_to_server((char*)host->base_string.self, ecl_fixnum(port)); 
   ecl_enable_interrupts();

   if (fd == 0)
     {
#line 292
	const cl_env_ptr the_env = ecl_process_env();
#line 292
	#line 292
	cl_object __value0 = ECL_NIL;
#line 292
	the_env->nvalues = 1;
#line 292
	return __value0;
#line 292
}


#if defined(ECL_MS_WINDOWS_HOST)
   stream = ecl_make_stream_from_fd(host, fd, ecl_smm_io_wsock, 8, 0, ECL_NIL);
#else
   stream = ecl_make_stream_from_fd(host, fd, ecl_smm_io, 8, 0, ECL_NIL);
#endif

   {
#line 300
	const cl_env_ptr the_env = ecl_process_env();
#line 300
	#line 300
	cl_object __value0 = stream;
#line 300
	the_env->nvalues = 1;
#line 300
	return __value0;
#line 300
}

}

cl_object
si_open_server_stream(cl_object port)
{
   int fd;			/* file descriptor */
   cl_index p;

   if (ecl_unlikely(!ECL_FIXNUMP(port) ||
                    ecl_fixnum_minusp(port) ||
                    ecl_fixnum_greater(port,ecl_make_fixnum(65536)))) {
           FEwrong_type_only_arg(ecl_make_fixnum(/*SI::OPEN-CLIENT-STREAM*/1187), port,
                                 ecl_read_from_cstring("(INTEGER 0 65535)"));
   }
   p = ecl_fixnum(port);
   ecl_disable_interrupts();
   fd = create_server_port(p);
   ecl_enable_interrupts();

   {
#line 320
	const cl_env_ptr the_env = ecl_process_env();
#line 320
	#line 320
	cl_object __value0 = ((fd == 0)? ECL_NIL : ecl_make_stream_from_fd(ECL_NIL, fd, ecl_smm_io, 8, 0, ECL_NIL));
#line 320
	the_env->nvalues = 1;
#line 320
	return __value0;
#line 320
}

}

/************************************************************
 * Unix sockets						    *
 ************************************************************/

cl_object
si_open_unix_socket_stream(cl_object path)
{
#if defined(ECL_MS_WINDOWS_HOST)
	FEerror("UNIX socket not supported under Win32 platform", 0);
#else
	int fd;			/* file descriptor */
	struct sockaddr_un addr;

	if (ecl_unlikely(ecl_t_of(path) != t_base_string))
                FEwrong_type_nth_arg(ecl_make_fixnum(/*SI::OPEN-UNIX-SOCKET-STREAM*/1189), 1, path,
                                     ecl_make_fixnum(/*STRING*/805));
	if (path->base_string.fillp > UNIX_MAX_PATH-1)
		FEerror("~S is a too long file name.", 1, path);

	fd = socket(PF_UNIX, SOCK_STREAM, 0);
	if (fd < 0) {
		FElibc_error("Unable to create unix socket", 0);
		{
#line 345
			const cl_env_ptr the_env = ecl_process_env();
#line 345
			#line 345
			cl_object __value0 = ECL_NIL;
#line 345
			the_env->nvalues = 1;
#line 345
			return __value0;
#line 345
		}

	}

	memcpy(addr.sun_path, path->base_string.self, path->base_string.fillp);
	addr.sun_path[path->base_string.fillp] = 0;
	addr.sun_family = AF_UNIX;

	if (connect(fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		close(fd);
		FElibc_error("Unable to connect to unix socket ~A", 1, path);
		{
#line 355
			const cl_env_ptr the_env = ecl_process_env();
#line 355
			#line 355
			cl_object __value0 = ECL_NIL;
#line 355
			the_env->nvalues = 1;
#line 355
			return __value0;
#line 355
		}

	}

	{
#line 358
		const cl_env_ptr the_env = ecl_process_env();
#line 358
		#line 358
		cl_object __value0 = ecl_make_stream_from_fd(path, fd, ecl_smm_io, 8, 0, ECL_NIL);
#line 358
		the_env->nvalues = 1;
#line 358
		return __value0;
#line 358
	}

#endif
}

/************************************************************
 * Hostname resolution					    *
 ************************************************************/
cl_object
si_lookup_host_entry(cl_object host_or_address)
{
	struct hostent *he;
	unsigned long l;
	char address[4];
	cl_object name, aliases, addresses;
	int i;

	INIT_TCP

	switch (ecl_t_of(host_or_address)) {
	case t_base_string:
		host_or_address = si_copy_to_simple_base_string(host_or_address);
		he = gethostbyname((char*)host_or_address->base_string.self);
		break;
	case t_fixnum:
		l = ecl_fixnum(host_or_address);
		goto addr;
	case t_bignum:
		l = _ecl_big_to_ulong(host_or_address);
	addr:	address[0] = l & 0xFF;
		address[1] = (l >> 8) & 0xFF;
		address[2] = (l >> 16) & 0xFF;
		address[3] = (l >> 24) & 0xFF;
		he = gethostbyaddr(&address, 4, AF_INET);
		break;
	default:
		FEerror("LOOKUP-HOST-ENTRY: Number or string expected, got ~S",
			1, host_or_address);
	}
	if (he == NULL)
		{
#line 397
			const cl_env_ptr the_env = ecl_process_env();
#line 397
			#line 397
			cl_object __value0 = ECL_NIL;
#line 397
			cl_object __value1 = ECL_NIL;
#line 397
			cl_object __value2 = ECL_NIL;
#line 397
			the_env->nvalues = 3;
#line 397
			the_env->values[2] = __value2;
#line 397
			the_env->values[1] = __value1;
#line 397
			return __value0;
#line 397
		}

	name = make_base_string_copy(he->h_name);
	aliases = ECL_NIL;
	for (i = 0; he->h_aliases[i] != 0; i++)
		aliases = CONS(make_base_string_copy(he->h_aliases[i]), aliases);
	addresses = ECL_NIL;
	for (i = 0; he->h_addr_list[i]; i++) {
		unsigned long *s = (unsigned long*)(he->h_addr_list[i]);
		l = *s;
		addresses = CONS(ecl_make_integer(l), addresses);
	}
	{
#line 408
		const cl_env_ptr the_env = ecl_process_env();
#line 408
		#line 408
		cl_object __value0 = name;
#line 408
		cl_object __value1 = aliases;
#line 408
		cl_object __value2 = addresses;
#line 408
		the_env->nvalues = 3;
#line 408
		the_env->values[2] = __value2;
#line 408
		the_env->values[1] = __value1;
#line 408
		return __value0;
#line 408
	}

}
