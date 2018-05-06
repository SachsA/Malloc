##
## EPITECH PROJECT, 2018
## make
## File description:
## make
##

GCC		=	gcc

CFLAGS		=	-I ./Include

RM		=	rm -rf

SRC		=	./src/thread_malloc_realloc.c		\
			./src/show_alloc_mem.c			\
			./src/align_size.c			\
			./src/my_realloc.c			\
			./src/my_calloc.c			\
			./src/my_malloc.c			\
			./src/my_free.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		+=	-W -Wall -Wextra -fPIC
CFLAGS		+=	-I ./include

NAME		=	./libmy_malloc.so

all:			$(NAME)

$(NAME):		$(OBJ)
			$(GCC) -shared -o $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
