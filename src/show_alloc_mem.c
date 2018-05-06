/*
** EPITECH PROJECT, 2018
** show_alloc_mem
** File description:
** show_alloc_mem
*/

#include <unistd.h>
#include <stdio.h>
#include "my_malloc.h"

static void print_bytes(size_t sz, block_t *tmp)
{
	printf("0x%lX - 0x%lX: %lu bytes\n", sz, sz + tmp->size, tmp->size);
}

void show_alloc_mem(void)
{
	size_t sz;
	block_t *tmp = first;

	printf("break : 0x%lX\n", (size_t)sbrk(0));
	while (tmp != NULL) {
		sz = (size_t)tmp + BLOCK_SIZE;
		if (tmp->free != 0)
			print_bytes(sz, tmp);
		tmp = tmp->next;
	}
}
