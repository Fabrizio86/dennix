/* Copyright (c) 2016, 2017, 2018 Dennis Wölfing
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/* libc/include/sys/libc-types.h
 * Data types.
 */

#include <dennix/types.h>

#if defined(__need_clockid_t) && !defined(__clockid_t_defined)
typedef __clockid_t clockid_t;
#  define __clockid_t_defined
#endif

#if defined(__need_dev_t) && !defined(__dev_t_defined)
typedef __dev_t dev_t;
#  define __dev_t_defined
#endif

#if defined(__need_FILE) && !defined(__FILE_defined)
typedef struct __FILE FILE;
#  define __FILE_defined
#endif

#if defined(__need_ino_t) && !defined(__ino_t_defined)
typedef __ino_t ino_t;
#  define __ino_t_defined
#endif

#if defined(__need_mode_t) && !defined(__mode_t_defined)
typedef __mode_t mode_t;
#  define __mode_t_defined
#endif

#if defined(__need_off_t) && !defined(__off_t_defined)
typedef __off_t off_t;
#  define __off_t_defined
#endif

#if defined(__need_pid_t) && !defined(__pid_t_defined)
typedef __pid_t pid_t;
#  define __pid_t_defined
#endif

#if defined(__need_NULL) || defined(__need_ptrdiff_t) || \
    defined(__need_size_t) || defined(__need_wchar_t) || defined(__need_wint_t)
#  include <stddef.h>
#endif

#if defined(__need_ssize_t) && !defined(__ssize_t_defined)
typedef __SSIZE_TYPE__ ssize_t;
#  define __ssize_t_defined
#endif

#if defined(__need_time_t) && !defined(__time_t_defined)
typedef __time_t time_t;
#  define __time_t_defined
#endif

#undef __need_clockid_t
#undef __need_dev_t
#undef __need_FILE
#undef __need_ino_t
#undef __need_mode_t
#undef __need_off_t
#undef __need_pid_t
#undef __need_ssize_t
#undef __need_time_t
