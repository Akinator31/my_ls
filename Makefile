##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile for my_printf project
##

SRC = 	my_ls.c \
		src/flags/flag_std_and_a.c \
		src/flags/flag_l.c \
		src/utils/my_is_a_flag.c \
		src/utils/my_arrlen.c \

LINKED_LIST_LIB =	lib/my_list/add_data.c \
					lib/my_list/info_list.c \
					lib/my_list/remove_data.c \
					lib/my_list/utils_list.c \

OBJ = $(SRC:.c=.o) $(LINKED_LIST_LIB:.c=.o)

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
	rm -f lib/my_list/*.o
	rm -f src/flags/*.o
	make clean -C lib/my_lib
	make clean -C lib/my_printf

fclean: clean

re: fclean all
