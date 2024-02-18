// SPDX-License-Identifier: BSD-3-Clause

#include <internal/syscall.h>
#include <errno.h>
#include <time.h>

int nanosleep(const struct timespec *t1, struct timespec *t2)
{
int apel = syscall(__NR_nanosleep, t1, t2);

if (apel < 0) {
	errno = -apel;
return -1;
}

return apel;
//return -1;
}
