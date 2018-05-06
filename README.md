Epitech, SECOND year Project. C Unix Memory : recode Malloc.

The goal of the project is to recode severals functions of the C library :

--> void *malloc(size_t size);

--> void *realloc(void *ptr, size_t size);

--> void free(void *ptr);


To compile : make.

To recompile the project : make re.

To clean all : make fclean.

-----> It will compile you a shared library.

There is a "./test" : it will run some tests, do not hesitate to test it with the real one and our malloc.


HOW TO USE OUR MALLOC:

LD_LIBRARY_PATH=$(pwd)

LD_PRELOAD=/path/to/our/library/libmy_malloc.so ./path/to/your/c/program    ------> for example : ./test


Group that make the project : Alexandre Sachs. Martin Cotoni. (Both in Epitech Bordeaux)