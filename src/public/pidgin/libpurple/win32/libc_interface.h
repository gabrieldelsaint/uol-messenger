/*
 * purple
 *
 * File: libc_interface.h
 *
 * Copyright (C) 2002-2003, Herman Bloggs <hermanator12002@yahoo.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02111-1301  USA
 *
 */
#ifndef _LIBC_INTERFACE_H_
#define _LIBC_INTERFACE_H_
#include <winsock2.h>
#include <ws2tcpip.h>
#include <io.h>
#include <errno.h>
#include "libc_internal.h"
#include <glib.h>
/* UOL << */
#include <stdio.h>
/* UOL >> */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef _MSC_VER
#define S_IRUSR S_IREAD
#define S_IWUSR S_IWRITE
#define S_IXUSR S_IEXEC

#define S_ISDIR(m)	 (((m)&S_IFDIR)==S_IFDIR)

/* UOL << */
#ifndef S_ISREG
#define S_ISREG(m) (((m) & S_IFMT) == S_IFREG)
#endif
/* UOL >> */

#define F_OK 0
#endif

/* sys/socket.h */
/* UOL << */
#ifndef _MSC_VER
/* UOL >> */
#define socket( namespace, style, protocol ) \
wpurple_socket( namespace, style, protocol )
/* UOL << */
#else
#define socket( nameSpace, style, protocol ) \
wpurple_socket( nameSpace, style, protocol )
#endif
/* UOL >> */

#define connect( socket, addr, length ) \
wpurple_connect( socket, addr, length )

/* UOL << */
#ifndef _MSC_VER
/* UOL >> */
#define getsockopt( args... ) \
wpurple_getsockopt( args )
/* UOL << */
#else
#define getsockopt( socket, level, optname, optval, optlenptr) \
wpurple_getsockopt( socket, level, optname, optval, optlenptr)
#endif
/* UOL >> */

/* UOL << */
#ifndef _MSC_VER
/* UOL >> */
#define setsockopt( args... ) \
wpurple_setsockopt( args )
/* UOL << */
#else
#define setsockopt(socket, level, optname, optval, optlen) \
wpurple_setsockopt(socket, level, optname, optval, optlen)
#endif
/* UOL >> */

#define getsockname( socket, addr, lenptr ) \
wpurple_getsockname( socket, addr, lenptr )

#define bind( socket, addr, length ) \
wpurple_bind( socket, addr, length )

#define listen( socket, n ) \
wpurple_listen( socket, n )

#define sendto(socket, buf, len, flags, to, tolen) \
wpurple_sendto(socket, buf, len, flags, to, tolen)

#define recv(fd, buf, len, flags) \
wpurple_recv(fd, buf, len, flags)

#define send(socket, buf, buflen, flags) \
wpurple_send(socket, buf, buflen, flags)

/* sys/ioctl.h */
#define ioctl( fd, command, val ) \
wpurple_ioctl( fd, command, val )

/* fcntl.h */
/* UOL << */
#ifndef _MSC_VER
/* UOL >> */
#define fcntl( fd, command, ... ) \
wpurple_fcntl( fd, command, ##__VA_ARGS__ )
/* UOL << */
#else
#define fcntl( fd, command, val ) \
wpurple_fcntl( fd, command, val )
#endif
/* UOL >> */

/* arpa/inet.h */
#define inet_aton( name, addr ) \
wpurple_inet_aton( name, addr )

#define inet_ntop( af, src, dst, cnt ) \
wpurple_inet_ntop( af, src, dst, cnt )

/* netdb.h */
#define gethostbyname( name ) \
wpurple_gethostbyname( name )

/* netinet/in.h */
#define ntohl( netlong ) \
(unsigned int)ntohl( netlong )

/* string.h */
#define hstrerror( herror ) \
wpurple_strerror( errno )
#define strerror( errornum ) \
wpurple_strerror( errornum )
#define g_strerror( errornum ) \
wpurple_strerror( errornum )

/* unistd.h */
#define read( fd, buf, buflen ) \
wpurple_read( fd, buf, buflen )

#define write( socket, buf, buflen ) \
wpurple_write( socket, buf, buflen )

#define close( fd ) \
wpurple_close( fd )

#if !GLIB_CHECK_VERSION(2,8,0)
#define g_access( filename, mode) \
wpurple_g_access( filename, mode )
#endif

#ifndef sleep
#define sleep(x) Sleep((x)*1000)
#endif

#define gethostname( name, size ) \
wpurple_gethostname( name, size )

#define fsync(fd) _commit(fd)

/* sys/time.h */
#define gettimeofday( timeval, timezone ) \
wpurple_gettimeofday( timeval, timezone )

/* stdio.h */
#define snprintf _snprintf
#define vsnprintf _vsnprintf

#define rename( oldname, newname ) \
wpurple_rename( oldname, newname )

#if GLIB_CHECK_VERSION(2,6,0)
#ifdef g_rename
# undef g_rename
#endif
/* This is necessary because we want rename on win32 to be able to overwrite an existing file, it is done in internal.h if GLib < 2.6*/
#define g_rename(oldname, newname) \
wpurple_rename(oldname, newname)
#endif

/* sys/stat.h */
#define fchmod(a,b)

/* time.h */
#define localtime_r( time, resultp ) \
wpurple_localtime_r( time, resultp )

#ifdef __cplusplus
}
#endif /* __cplusplus */

/* UOL <LINK_FIX> << */
extern FILE* wpurple_fopen(const gchar *filename, const gchar *mode);
extern gint wpurple_mkstemp(const gchar *filename);

#ifdef _MSC_VER
#if GLIB_CHECK_VERSION(2,6,0)

#ifdef g_fopen
# undef g_fopen
#endif
/* replaces g_fopen - file descriptors passed between different versions of MSVCRT
   causes access violation (http://msdn2.microsoft.com/en-us/library/ms235460(VS.80).aspx) */
#define g_fopen(filename, mode) \
wpurple_fopen(filename, mode)

#ifdef g_mkstemp
# undef g_mkstemp
#endif
/* replaces g_mkstemp - file descriptors passed between different versions of MSVCRT
   causes access violation (http://msdn2.microsoft.com/en-us/library/ms235460(VS.80).aspx) */
#define g_mkstemp(filename) \
wpurple_mkstemp(filename)
#endif

#endif
/* UOL >> */

#endif /* _LIBC_INTERFACE_H_ */
