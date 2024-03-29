// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	/* TODO: Implement stat(). */
	int apel = syscall(__NR_stat, path, buf);

	if (apel < 0)
	{
        errno = -apel;
        return -1;
    }

    return apel;
	//return -1;
}
