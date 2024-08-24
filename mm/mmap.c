// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	/* TODO: Implement mmap(). */
    long mem = syscall(9, addr, length, prot, flags, fd, offset);
    if (mem < 0) {
        errno = -mem;
        return MAP_FAILED;
    }

    return (void *) mem;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	/* TODO: Implement mremap(). */
	long new_address = syscall(25, old_address, old_size, new_size, flags);

    if (new_address < 0) {
        errno = -new_address;
        return MAP_FAILED;
    }

    return (void *) new_address;
}

int munmap(void *addr, size_t length)
{
	/* TODO: Implement munmap(). */
	int result = syscall(11, addr, length);

    if (result == -1) {
        errno = -result;
        return -1;
    }

    return 0;
}
