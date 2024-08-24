// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/types.h>
#include <unistd.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

#define makedev(x, y) ( \
		(((x)&0xfffff000ULL) << 32) | \
	(((x)&0x00000fffULL) << 8) | \
		(((y)&0xffffff00ULL) << 12) | \
	(((y)&0x000000ffULL)) \
	)

/* Structure describing file characteristics as defined in linux/stat.h */
struct statx {
	uint32_t stx_mask;
	uint32_t stx_blksize;
	uint64_t stx_attributes;
	uint32_t stx_nlink;
	uint32_t stx_uid;
	uint32_t stx_gid;
	uint16_t stx_mode;
	uint16_t pad1;
	uint64_t stx_ino;
	uint64_t stx_size;
	uint64_t stx_blocks;
	uint64_t stx_attributes_mask;
	struct {
		int64_t tv_sec;
		uint32_t tv_nsec;
		int32_t pad;
	} stx_atime, stx_btime, stx_ctime, stx_mtime;
	uint32_t stx_rdev_major;
	uint32_t stx_rdev_minor;
	uint32_t stx_dev_major;
	uint32_t stx_dev_minor;
	uint64_t spare[14];
};

int fstatat_statx(int fd, const char *restrict path, struct stat *restrict st, int flag)
{
	/* TODO: Implement fstatat_statx(). Use statx and makedev above. */
	struct statx stx;
    int result = syscall(332, fd, path, flag, st, &stx);
    if (result == 0) {
        st->st_dev = makedev(stx.stx_dev_major, stx.stx_dev_minor);
        st->st_ino = stx.stx_ino;
        st->st_mode = stx.stx_mode;
        st->st_nlink = stx.stx_nlink;
        st->st_uid = stx.stx_uid;
        st->st_gid = stx.stx_gid;
        st->st_size = stx.stx_size;
        st->st_blksize = stx.stx_blksize;
        st->st_blocks = stx.stx_blocks;
        st->st_atime = stx.stx_atime.tv_sec;
        st->st_mtime = stx.stx_mtime.tv_sec;
        st->st_ctime = stx.stx_ctime.tv_sec;
    } else {
        errno = -result;
    }

    return result;
}

int fstatat(int fd, const char *restrict path, struct stat *restrict st, int flag)
{
	/* TODO: Implement fstatat(). Use fstatat_statx(). */
	return -1;
}
