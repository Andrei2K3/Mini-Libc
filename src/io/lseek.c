// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

off_t lseek(int fd, off_t offset, int whence)
{
	/* TODO: Implement lseek(). */
	off_t apel = syscall(__NR_lseek, fd, offset, whence);

    if (apel < 0)
	{
        errno = -apel;
        return -1;
    }

    return apel;
	//return -1;
}
