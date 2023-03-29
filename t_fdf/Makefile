NAME = fdf
SRCS_DIR := src
# SRC =	fdf.c	\
# 		utils.c
# SRCS = $(wildcard $(SRCS_DIR)/*.c)
SRCS =	src/utils.c	\
		src/fdf.c
CFLAGS = -Wall -Wextra -Werror
CINCLUDES += -I include/
HEADER = include/fdf.h
OBJS_DIR = obj
# OBJS := $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))
OBJS := $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))
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

$(NAME): $(OBJS) $(HEADER) | $(OBJS_DIR)
	@echo $(RED)
	@make -C $(MLX_DIR)
	@echo $(BLUE)
	@make -C $(LIBFT_DIR)
	@echo $(GREEN)
	cc $(CFLAGS) $(CINCLUDES) $(LIBFT_FLAGS) $(MLX_FLAGS) $(OBJS) -o $@
	$(BANNER_FDF)

# $(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
# $(OBJS): $(SRCS) | $(OBJS_DIR)
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADER)| $(OBJS_DIR)
	cc -c $(CFLAGS) $(CINCLUDES) $< -o $@ 

$(OBJS_DIR):
	@mkdir $@

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
	@echo "\n"

re: fclean all

.PHONY: clean fclean re

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
#-Og -g3 -fsanitize=address
#SRC+= mlx_png.c mlx_mouse.m
# add to match string put with X11 in size and position
# CFLAGS+= -DSTRINGPUTX11
#SRCS_FILES = $(addprefix $(SRCS_DIR), %.c)
#OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
#OBJS = $(addprefix $(OBJS_DIR), $(SRCS:%.c=%.o))
#OBJS = $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.c=.o)))
#$(OBJS): $(addprefix $(SRCS_DIR), %.c)
#cc -c $(FLAGS) $^ -o $@
#$(OBJS) : 
#gcc $(CFLAGS) $(CINCLUDES) -c -o $@
#$($(OBJ_DIR)/%.o) : $(SRCS) | $(OBJ_DIR)
#$(addprefix $(OBJS_DIR), %.o) : $(SRCS)
#$(OBJS) : $(addprefix $(SRCS_DIR), $(SRCS))
#$(addprefix $(OBJS_DIR), %.o)