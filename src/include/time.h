/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef __TIME_H__
#define __TIME_H__	1

#ifdef __cplusplus
extern "C" {
#endif

struct timespec {
    long long tv_sec;  // Numarul de secunde
    long tv_nsec; // Numarul de nanosecunde
};

int nanosleep(const struct timespec *t1, struct timespec *t2);

#ifdef __cplusplus
}
#endif

#endif
