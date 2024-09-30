# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpibool <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 14:37:14 by cpibool           #+#    #+#              #
#    Updated: 2024/09/28 01:27:35 by cpibool          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
FLAG = -Wall -Wextra -Werror
RM = rm -f

FILE = ft_printf.c \
	   	print_char.c \
		print_string.c \
		print_digit_base.c \
		print_pointer.c

OBJ = $(FILE:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAG) -c $(FILE)
	ar rsc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
