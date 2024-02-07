##
## EPITECH PROJECT, 2023
## Makefile My_ls
## File description:
## My_ls
##

SRC_LIB	=	lib/my/my_strlen.c	\
			lib/my/my_put_nbr.c	\
			lib/my/my_putchar.c	\
			lib/my/my_strlen.c	\
			lib/my/my_putstr.c	\
			lib/my/mini_printf.c	\
			lib/my/my_strcat.c	\
			lib/my/my_strcpy.c	\
			lib/my/my_strlowcase.c	\
			lib/my/get_number_char.c	\

SRC =	main.c	\
		stock_modifiers.c	\
		is_in_str.c	\
		my_ls_with_path.c	\
		my_ls_multiple_path.c	\
		sort_array_str.c	\
		my_ls_d.c	\
		find_last_arg.c	\
		print_long_ls.c	\
		print_type.c	\
		print_datas.c	\
		total_path.c	\
		check_null.c	\
		sort_time.c	\

OBJ	=	$(SRC_LIB:.c=.o)

CFLAGS_LIB 	=	-I./include/ -Werror -Wall -Wextra

CFLAGS 	=	-I./include/ -L./lib/my/ -lmy -Werror -Wall -Wextra

NAME	=	my_ls

all: libmy.a
	gcc -o $(NAME) $(SRC) $(CFLAGS)

libmy.a:	$(OBJ)
	gcc -c $(SRC_LIB) $(CFLAGS_LIB)
	ar rc lib/my/libmy.a $(OBJ)
	find -name "*.o" -delete

clean:
	rm -f libmy.a

fclean: clean
	rm -f $(NAME)

re: fclean all
