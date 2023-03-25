# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 13:32:36 by lilizarr          #+#    #+#              #
#    Updated: 2023/03/25 15:34:20 by lilizarr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

define IMG

██████████████████████████████████████████████
::::::::::::::::::::::::::::::::::::::::::::::
██╗::████████╗:::::██╗::::██╗██████╗██████╗:::
██║::██╚════██╗::::██║::::████╔═══████╔══██╗::
███████║█████╔╝::::██║:█╗:████║:::████████╔╝::
╚════████╔═══╝:::::██║███╗████║:::████╔══██╗::
:::::█████████╗::::╚███╔███╔╚██████╔██████╔╝::
:::::╚═╚══════╝::::╚══╝╚══╝ ╚═════╝╚═════╝::::
:::::::::███████╗::::██████╗:::::███████╗:::::
:::::::::██╔════╝::::██╔══██╗::::██╔════╝:::::
:::::::::█████╗::::::██║::██║::::█████╗:::::::
:::::::::██╔══╝::::::██║::██║::::██╔══╝:::::::
:::::::::██║:::::::::██████╔╝::::██║::::::::::
:::::::::╚═╝:::::::::╚═════╝:::::╚═╝::::::::::
██████████████████████████████████████████████

endef
export IMG

CROSS = "\033[8m"
RED = "\033[0;1;91m"
GREEN = "\033[0;1;32m"
BLUE = "\033[0;1;34m"
BANNER_FDF = @echo $(GREEN) "$$IMG"

# get Operating System
UNAME := $(shell uname)

NAME = fdf
SRC = 
OBJS_DIR = obj/
OBJS = $(addprefix $(OBJS_DIR), $(SRC:.c=.o))
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = lib/libft/
LIBFT = $(LIBFT_DIR)libft.a


MLX_FLAGS = 
# cc -I../minilibx_macos -lmlx -framework OpenGL -framework AppKit main_macos.c
all: $(MAKE_LIBFT) $(OBJS_DIR) $(NAME)
# 
$(MAKE_LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	cc $(CFLAGS) $^ $(LIBFT) -o $@

$(OBJS_DIR): 
	mkdir -p $@

$(addprefix $(OBJS_DIR), %.o): %.c
	cc -c $(CFLAGS) $^ -o $@

libft:
	@echo $(BLUE)
	@make -C $(LIBFT_DIR) 
	$(BANNER_FDF)

env:
	@echo $(shell uname)
	
ifeq ($(UNAME), Linux)
# do something Linux
endif
ifeq ($(UNAME), Darwin)
# do something MacOS
endif
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

.PHONY: clean fclean re

