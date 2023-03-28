# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 13:32:36 by lilizarr          #+#    #+#              #
#    Updated: 2023/03/28 10:58:34 by lilizarr         ###   ########.fr        #
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
SRC =	utils.c \
		fdf.c
OBJS_DIR = obj/
OBJS = $(addprefix $(OBJS_DIR), $(SRC:.c=.o))
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = lib/libft/
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_FLAGS = -L./$(LIBFT_DIR) -lft
CINCLUDES += -I $(LIBFT_DIR)
	
ifeq ($(shell uname), Linux)
	# do something Linux
	MLX_DIR = lib/minilibx_linux
	MLX_FLAGS = -L./$(MLX_DIR) -lmlx -lXext -lX11 -lm
endif
ifeq ($(shell uname), Darwin)
	# do something MacOS
	MLX_DIR = lib/minilibx_macos/
#	MLX_FLAGS = -framework OpenGL -framework AppKit
	MLX_FLAGS = -L./$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
	#MLX_FLAGS = -I../minilibx_macos -lmlx -framework OpenGL -framework AppKit
endif

MLX = $(MLX_DIR)libmlx.a
CINCLUDES += -I $(MLX_DIR)

# $(NAME): $(OBJS)
# 	cc $(FLAGS) $^ $(LIBFT) -o $@

# $(OBJS_DIR): 
# 	mkdir -p $@

# $(addprefix $(OBJS_DIR), %.o): %.c
# 	cc -c $(FLAGS) $^ -o $@

all: $(OBJS_DIR) $(NAME)

#@$(CC) $(CDEBUG) $(CFLAGS) $(CINCLUDES) $(OBJS) -o $@ $(LIBFT_FLAGS) $(MLX_FLAGS)
	$(BANNER_FDF)

$(OBJS_DIR): 
	@mkdir -p $@

$(addprefix $(OBJS_DIR), %.o): %.c | $(OBJ_DIR)
	@cc -c $(CFLAGS) $(CINCLUDES) $< -o $@

$(NAME): $(OBJS)
	@echo $(RED)
	@make -C $(MLX_DIR)
	@echo $(BLUE)
	@make -C $(LIBFT_DIR)
	@echo $(GREEN)
	cc $(CFLAGS) $(CINCLUDES) $(LIBFT_FLAGS) $(MLX_FLAGS) $(LIBFT) $(MLX) $^ -o $@

# libft:
# 	@echo $(BLUE)
# 	@make -C $(LIBFT_DIR) 
# 	$(BANNER_FDF)

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