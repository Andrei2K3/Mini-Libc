// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int truncate(const char *path, off_t length)
{
	/* TODO: Implement truncate(). */
	int apel = syscall(__NR_truncate, path, length);
    if (apel < 0)
	{
        errno = -apel;
		return -1;
	}
    return apel;
	//return -1;
}
