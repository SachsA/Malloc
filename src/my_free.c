/*
** EPITECH PROJECT, 2018
** my_free
** File description:
** free
*/

#include <unistd.h>
#include "my_malloc.h"

static void set_last(void)
{
	block_t *tmp = first;

	if (first == last) {
		first = NULL;
		last = NULL;
	} else {
		while (tmp != NULL) {
			if (tmp->next == last) {
				tmp->next = NULL;
				last = tmp;
			}
			tmp = tmp->next;
		}
	}
}

void free(void *block)
{
	void *limit;
	block_t *new_block;

	if (block == NULL)
		return;
	mutex_lock_malloc();
	new_block = (block_t *)block - 1;
	limit = sbrk(0);
	if ((char *)block + new_block->size == limit) {
		set_last();
		sbrk(-BLOCK_SIZE - new_block->size);
		mutex_unlock_malloc();
		return;
	}
	new_block->free = 1;
	mutex_unlock_malloc();
}
