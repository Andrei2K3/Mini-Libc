// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int ftruncate(int fd, off_t length)
{
	/* TODO: Implement ftruncate(). */
	int apel = syscall(__NR_ftruncate, fd, length);
	if(apel < 0)
	{
		errno = -apel;
		return -1;
	}
	return apel;
	//return -1;
}
