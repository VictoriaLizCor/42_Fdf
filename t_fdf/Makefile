# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 13:32:36 by lilizarr          #+#    #+#              #
#    Updated: 2023/03/28 14:38:59 by lilizarr         ###   ########.fr        #
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


NAME = fdf
SRCS =	src/fdf.c	\
		src/utils.c

OBJS_DIR = obj
CFLAGS = -Wall -Wextra -Werror
# CINCLUDES += -I include/
# HEADER = include/fdf.h

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:%.c=%.o)))
# OBJS =  $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))
LIBFT_DIR = lib/libft/
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_FLAGS = -L./$(LIBFT_DIR) -lft
CINCLUDES += -I $(LIBFT_DIR)
	
ifeq ($(shell uname), Linux)
	MLX_DIR = lib/minilibx_linux
	MLX_FLAGS = -L./$(MLX_DIR) -lmlx -lXext -lX11 -lm
endif
ifeq ($(shell uname), Darwin)
	MLX_DIR = lib/minilibx_macos/
	MLX_FLAGS = -L./$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

MLX = $(MLX_DIR)libmlx.a
CINCLUDES += -I $(MLX_DIR)

all: $(NAME)

$(OBJS) : $(SRCS) | $(OBJS_DIR)
	gcc $(CDEBUG) $(CFLAGS) $(CINCLUDES) -c $< -o $@

$(NAME): $(OBJS) | $(HEADER)
	@echo $(RED)
	@make -C $(MLX_DIR)
	@echo $(BLUE)
	@make -C $(LIBFT_DIR)
	@echo $(GREEN)
	gcc $(CFLAGS) ${CINCLUDES} $(OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $@
#	cc $(CFLAGS) ${CINCLUDES} $(LIBFT_FLAGS) $(MLX_FLAGS) $(OBJS) -o $@
	$(BANNER_FDF)
# $(MLX) $(LIBFT)
# cc $(CFLAGS) $(CINCLUDES) $(LIBFT_FLAGS) $(MLX_FLAGS) $^ -o $@
	

$(OBJS_DIR): 
	@mkdir -p $@


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