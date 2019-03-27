# Malloc

### Goal
###### The project : Recode C library functions.
###### void *malloc(size_t size);
###### void *realloc(void *ptr, size_t size);
###### void free(void *ptr);

### Program compilation of a shared Library:
  ```sh
        make
```

### Usage
- There is a "./test" : it will run some tests, do not hesitate to test it with the real malloc and our malloc.

##### How to use it ?!?!
```sh
        LD_LIBRARY_PATH=$(pwd)
```
```sh
        LD_PRELOAD=/path/to/our/library/libmy_malloc.so ./path/to/your/c/program --> for example : ./test
```

#### Project realised by:
- **Alexandre Sachs : [alexandre.sachs@epitech.eu](https://github.com/SachsA)**
- **Martin Cotoni : [martin.cotoni@epitech.eu](https://github.com/cotonim)**
