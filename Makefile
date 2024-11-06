##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile for my_printf project
##

SRC = 	my_ls.c \
		src/utils/is_a_flag.c \

OBJ = $(SRC:.c=.o)

NAME = my_ls

LIBFILE =	lib/my_lib/libmy.a \
			lib/my_printf/libmy_printf.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib/my_lib
	make -C lib/my_printf
	gcc -o $(NAME) $(OBJ) $(LIBFILE)

clean:
	rm -f *.o
	rm -f lib/my/*.o
	rm -f src/utils/*.o
	make clean -C lib/my_lib
	make clean -C lib/my_printf

fclean: clean

re: fclean all
