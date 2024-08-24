// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	/* TODO: Implement open system call. */
	va_list list;
    mode_t mode = 0;
    va_start(list, flags);
	int result = -1;
    if (flags & O_CREAT) {
        mode = va_arg(list, mode_t);
        result = syscall(2, filename, flags, mode);
    } else {
        result = syscall(2, filename, flags);
    }
    va_end(list);
    if (result < 0) {
        errno = -result;
        return -1;
    }
    return result;
}

