// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <errno.h>
#include <time.h>

unsigned int sleep(unsigned int seconds)
{
struct timespec t1, t2;

t1.tv_sec = seconds;
t1.tv_nsec = 0;
int apel = nanosleep(&t1, &t2);

if (apel == -1)
	return errno;

return apel;
}
