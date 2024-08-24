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
    if (size == 0) return NULL;
    void *start = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (start == MAP_FAILED) {
        return NULL;
    }

    int result = mem_list_add(start, size);

    if (result == -1) {
        return NULL;
    }

    return start;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
    size_t total_size = nmemb * size;
    void *mem = malloc(total_size);

    if (mem != NULL) {
        memset(mem, 0, total_size);
    }

    return mem;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
    struct mem_list *iter = mem_list_find(ptr);
    munmap(iter->start, iter->len);
    int result = mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	if (size == 0) {
        mem_list_del(ptr);
        return NULL;
    }
    if (ptr == NULL) {
        return malloc(size);
    }

    struct mem_list *item = mem_list_find(ptr);
    if (item == NULL) {
        return NULL;
    }

    if (item->len >= size) {
        return ptr;
    }

    void *new_ptr = malloc(size);

    if (new_ptr) {
        size_t copy_size = (item->len < size) ? item->len : size;
        memcpy(new_ptr, ptr, copy_size);
        mem_list_del(ptr);
        return new_ptr;
    } else {
        return NULL;
    }
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
    size_t new_size = nmemb * size;
    return realloc(ptr, new_size);
}
