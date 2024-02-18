// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	struct mem_list *list = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (list == MAP_FAILED)
		return NULL;

	list->start = NULL;
	list->len = size;
	list->prev = list;
	list->next = list;

	return (void *)list;
	// return NULL;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	size_t nrTotal = nmemb * size;
	struct mem_list *list = malloc(nrTotal);
	if (list == MAP_FAILED)
		return NULL;

	list->start = NULL;
	list->len = size;
	list->prev = list;
	list->next = list;

	memset(list, 0, nrTotal);
	return list;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	struct mem_list *list = ptr;
	if (ptr != NULL)
		munmap(ptr, list->len);
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	if (ptr == NULL)
		return malloc(size);

	struct mem_list *oldPtr = ptr;
	size_t oldSize = oldPtr->len;


	struct mem_list *newPtr = malloc(size);
	if(newPtr == NULL)
		return NULL;
	newPtr->start = NULL;
	newPtr->len = size;
	newPtr->prev = newPtr;
	newPtr->next = newPtr;


	size_t whatCopy = size;
	if (oldSize < whatCopy)
		whatCopy = size;

	memcpy(newPtr, ptr, whatCopy);
	free(ptr);
	return newPtr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	size_t sizeTotal = nmemb * size;
	return realloc(ptr, sizeTotal);
}
