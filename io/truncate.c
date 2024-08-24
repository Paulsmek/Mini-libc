// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int truncate(const char *path, off_t length)
{
	/* TODO: Implement truncate(). */
	int result = syscall(76, path, length);
	if (result < 0) {
        // An error occurred, set errno and return -1
        errno = -result; // Assuming syscall returns negative values for errors
        return -1;
    }
    return 0; // Success
}
