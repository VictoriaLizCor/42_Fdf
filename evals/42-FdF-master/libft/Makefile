# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/01 21:02:30 by pbondoer          #+#    #+#              #
#    Updated: 2023/04/16 14:11:44 by lilizarr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRC		= $(shell ls | grep -E "ft_.+\.c") \
		  get_next_line.c

OBJ		= $(SRC:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: fclean all fclean
