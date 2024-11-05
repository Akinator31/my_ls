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

LIBDIR = 	lib/libmy.a \
			lib/libmy_printf.a

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIBDIR)

clean:
	rm -f *.o
	rm -f lib/my/*.o

fclean: clean

re: fclean all
