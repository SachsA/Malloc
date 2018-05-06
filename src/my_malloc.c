/*
** EPITECH PROJECT, 2018
** my_malloc
** File description:
** malloc
*/

#include <unistd.h>
#include "my_malloc.h"

static block_t *get_free_block(size_t size)
{
	block_t *tmp = first;

	while (tmp != NULL) {
		if (tmp->free == 1 && tmp->size >= size) {
			tmp->free = 0;
			mutex_unlock_malloc();
			return ((void *)(tmp + 1));
		}
		tmp = tmp->next;
	}
	return (NULL);
}

static block_t *init_block(block_t *block, void *ptr, size_t size)
{
	block = ptr;
	block->size = size;
	block->free = 0;
	block->next = NULL;
	if (first == NULL)
		first = block;
	if (last != NULL)
		last->next = block;
	last = block;
	return (block);
}

void *malloc(size_t size)
{
	void *ptr;
	block_t *block;

	if (size == 0)
		return NULL;
	size = align_size(size);
	mutex_lock_malloc();
	block = get_free_block(size);
	if (block != NULL)
		return (block);
	ptr = sbrk(BLOCK_SIZE + size);
	if (ptr == FAIL_SB) {
		mutex_unlock_malloc();
		return (NULL);
	}
	block = init_block(block, ptr, size);
	mutex_unlock_malloc();
	return ((void *)(block + 1));
}
