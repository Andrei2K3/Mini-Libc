// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	/* TODO: Implement close(). */
	int fdd = syscall(__NR_close, fd);
	if(fdd < 0)
	{
		errno = -fdd;
		return -1;
	}
	return fdd;
	//return -1;
}
