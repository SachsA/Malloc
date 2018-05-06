/*
** EPITECH PROJECT, 2018
** align size
** File description:
** align size
*/

#include <stddef.h>
#include "my_malloc.h"

size_t align_size(size_t size)
{
	size = (size + XF) & ~XF;
	return (size);
}
