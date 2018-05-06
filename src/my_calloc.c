/*
** EPITECH PROJECT, 2018
** calloc
** File description:
** calloc
*/

#include <string.h>
#include "my_malloc.h"

void *calloc(size_t nitems, size_t size)
{
	void *ptr;
	size_t new_size;

	if (nitems == 0 || size == 0)
		return (NULL);
	new_size = nitems * size;
	ptr = malloc(new_size);
	if (ptr == NULL)
		return (NULL);
	memset(ptr, 0, new_size);
	return (ptr);
}
