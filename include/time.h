/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef __TIME_H__
#define __TIME_H__	1

#ifdef __cplusplus
extern "C" {
#endif

#include <internal/io.h>
#include <internal/types.h>


typedef long time_t;
typedef long suseconds_t;

struct timespec {
    time_t tv_sec;       // Represent seconds
    suseconds_t tv_nsec; // Represent nanoseconds
};

int nanosleep(const struct timespec *req, struct timespec *rem);

#ifdef __cplusplus
}
#endif

#endif
