/*
** EPITECH PROJECT, 2018
** thread malloc realloc
** File description:
** malloc
*/

#include <pthread.h>
#include <stdlib.h>
#include "my_malloc.h"

static pthread_mutex_t malloc_mutex = PTHREAD_MUTEX_INITIALIZER;

void mutex_lock_malloc(void)
{
	if (pthread_mutex_lock(&malloc_mutex) != 0)
		abort();
}

void mutex_unlock_malloc(void)
{
	if (pthread_mutex_unlock(&malloc_mutex) != 0)
		abort();
}
