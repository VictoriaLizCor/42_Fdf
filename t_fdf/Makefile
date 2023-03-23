# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 13:32:36 by lilizarr          #+#    #+#              #
#    Updated: 2023/03/23 16:10:59 by lilizarr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = 

OBJS_DIR = obj/
OBJS = $(addprefix $(OBJS_DIR), $(SRC:.c=.o))
LIBFT_DIR = lib/libft/
LIBFT = $(LIBFT_DIR)libft.a
FLAGS = -Wall -Wextra -Werror

all: $(MAKE_LIBFT) $(OBJS_DIR) $(NAME)
# 
$(MAKE_LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	cc $(FLAGS) $^ $(LIBFT) -o $@

$(OBJS_DIR): 
	mkdir -p $@

$(addprefix $(OBJS_DIR), %.o): %.c
	cc -c $(FLAGS) $^ -o $@

clean:
	@echo "\n************  CLEAN LIBFT ************" 
	@make -C $(LIBFT_DIR) clean
	@echo "\n************  CLEAN ROOT  ************"
	rm -rf $(OBJS_DIR)

fclean:	clean
	@echo "\n************  FCLEAN LIBFT  ************"
	@make -C $(LIBFT_DIR) fclean
	@echo "\n************  FCLEAN ROOT   ************"
	rm -f $(NAME)

re: fclean all
