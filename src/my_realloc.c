/*
** EPITECH PROJECT, 2018
** my_realloc
** File description:
** realloc
*/

#include <string.h>
#include "my_malloc.h"

void *realloc(void *block, size_t size)
{
	void *res;
	block_t *new_block;

	if (block == NULL)
		return (malloc(size));
	if (size == 0 && block != NULL) {
		free(block);
		return (NULL);
	}
	new_block = (block_t *)block - 1;
	if (new_block->size >= size)
		return (block);
	res = malloc(size);
	if (res != NULL) {
		memcpy(res, block, new_block->size);
		free(block);
	}
	return (res);
}
