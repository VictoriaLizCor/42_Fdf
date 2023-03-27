# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 13:32:36 by lilizarr          #+#    #+#              #
#    Updated: 2023/03/27 14:31:16 by lilizarr         ###   ########.fr        #
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
SRC = ./
OBJS_DIR = obj/
OBJS = $(addprefix $(OBJS_DIR), $(SRC:.c=.o))
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = lib/libft/
LIBFT = $(LIBFT_DIR)libft.a
	
ifeq ($(shell uname), Linux)
# do something Linux
MLX_DIR = mlx/minilibx_linux/
MLX = $(MLX_DIR)libmlx.a
#MLX_FLAGS = -I../minilibx_macos -lmlx -framework OpenGL -framework AppKit
endif
ifeq ($(shell uname), Darwin)
# do something MacOS
MLX_DIR = mlx/minilibx_macos/
MLX = $(MLX_DIR)libmlx.a
MLX_FLAGS = $(MLX) -framework OpenGL -framework AppKit
#MLX_FLAGS = -I../minilibx_macos -lmlx -framework OpenGL -framework AppKit
endif

all: $(OBJS_DIR) $(NAME)

$(NAME): $(OBJS)
	@make -C $(MLX_DIR)
	@make -C $(LIBFT_DIR)
	cc $(CFLAGS) $(MLX_FLAGS) $^ $(LIBFT)  -o $@

$(OBJS_DIR): 
	mkdir -p $@

$(addprefix $(OBJS_DIR), %.o): %.c
	cc -c $(CFLAGS) $(MLX_FLAGS) $^ -o $@

libft:
	@echo $(BLUE)
	@make -C $(LIBFT_DIR) 
	$(BANNER_FDF)

clean:
	@echo "\n************  CLEAN LIBFT ************" 
	@make -C $(LIBFT_DIR) clean
	@echo "\n************  CLEAN XML ************" 
	@make -C $(MLX_DIR) clean
	@echo "\n************  CLEAN ROOT  ************"
	rm -rf $(OBJS_DIR)

fclean:	clean
	@echo "\n************  FCLEAN LIBFT  ************"
	@make -C $(LIBFT_DIR) fclean
	@echo "\n************  CLEAN XML ************" 
	@make -C $(MLX_DIR) clean
	@echo "\n************  FCLEAN ROOT   ************"
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re

# -Og -g3 -fsanitize=address
#SRC+= mlx_png.c mlx_mouse.m
# add to match string put with X11 in size and position
# CFLAGS+= -DSTRINGPUTX11