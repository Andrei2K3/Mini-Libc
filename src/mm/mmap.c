// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	/* TODO: Implement mmap(). */
	long apel = syscall(__NR_mmap, addr, length, prot, flags, fd, offset);
	if (apel < 0)
	{
		errno = -apel;
		return MAP_FAILED;
	}
	return (void *)apel;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	/* TODO: Implement mremap(). */
	long apel = syscall(__NR_mremap, old_address, old_size, new_size, flags);
	if (apel < 0)
	{
		errno = -apel;
		return MAP_FAILED;
	}
	return (void *)apel;
}

int munmap(void *addr, size_t length)
{
	/* TODO: Implement munmap(). */
	int apel = syscall(__NR_munmap, addr, length);
	if (apel < 0)
	{
		errno = -errno;
		return -1;
	}
	return apel;
}
