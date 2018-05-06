/*
** EPITECH PROJECT, 2018
** malloc h
** File description:
** malloc h
*/

#ifndef MY_MALLOC_H_
	#define MY_MALLOC_H_

	#include <stddef.h>

	#define XF 0xf

	typedef struct block_s {
		size_t size;
		unsigned char free;
		struct block_s *next;
	} block_t;

	block_t *first;
	block_t *last;

	#define FAIL_SB ((void *)-1)
	#define BLOCK_SIZE sizeof(block_t)

	void free(void *p);
	void show_alloc_mem();
	void *malloc(size_t size);
	size_t align_size(size_t size);
	void *realloc(void *p, size_t size);
	void *calloc(size_t nitems, size_t size);

	void mutex_lock_malloc();
	void mutex_unlock_malloc();

#endif
