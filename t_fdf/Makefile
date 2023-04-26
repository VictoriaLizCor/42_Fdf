NAME = fdf

SRCS_DIR := src/
SRCS =	src/fdf.c			\
		src/render.c		\
		src/draw_line.c		\
		src/color.c			\
		src/utils.c			\
		src/hooks.c			\
		src/check_error.c

CFLAGS = -Wall -Wextra #-Werror
CINCLUDES += -I include/
HEADER +=	include/fdf.h
		

OBJS_DIR = obj/
OBJS := $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.c=.o)))
LIBFT_DIR = lib/libft/
LIBFT =  $(LIBFT_DIR)libft.a
# LIBFT_FILE = $(LIBFT_DIR)libft.a
LIBFT_FLAGS = -L./$(LIBFT_DIR) -lft
CINCLUDES += -I $(LIBFT_DIR)
#sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
ifeq ($(shell uname), Linux)
	MLX_DIR = lib/minilibx_linux/
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd
	CINCLUDES += -I /usr/include/
endif
ifeq ($(shell uname), Darwin)
	MLX_DIR = lib/minilibx_macos/
	MLX_FLAGS = -L.. -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
	HEADER +=	include/hook_key.h
endif
# cc -I /usr/include/ minilib_main.c -L.. -lmlx -L ../minilibx_linux/ -lXext -lX11 -lm -lbsd
MLX = $(MLX_DIR)libmlx.a
# MLX_FILE = $(MLX_DIR)libmlx.a
CINCLUDES += -I $(MLX_DIR)

all: $(LIBFT) $(MLX) $(OBJS_DIR) $(NAME)

$(NAME): $(HEADER) $(OBJS)
	@echo $(GREEN)
	cc -g $(CFLAGS) $(CINCLUDES) $(OBJS) -o $@ $(LIBFT) $(MLX) $(LIBFT_FLAGS) $(MLX_FLAGS)
	$(BANNER_FDF)


 #$(LIBFT) $(MLX)
# $(LIBFT_DIR)$(LIBFT) $(MLX_DIR)$(MLX) re
# $(MLX_FLAGS) $(LIBFT_FLAGS)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c | $(OBJS_DIR)
	@echo $(GREEN)
	cc $(CFLAGS) $(CINCLUDES) -c $< -o $@
	

$(OBJS_DIR):
	@mkdir -p $@

$(MLX):
	@echo $(RED)
	@make --no-print-directory -C $(MLX_DIR)

$(LIBFT):
	@echo $(BLUE)
	@make -C $(LIBFT_DIR)

# display :
# $(shell export $(shell DISPLAY=$(shell cat /etc/resolv.conf | grep nameserver | awk '{print $$NF}'):0.0))
# $(eval ST=$(shell cat /etc/resolv.conf | grep nameserver | awk '{print $$NF}'):0.0)
# @echo $(ST)
# export DISPLAY=$(shell echo $(ST))
#  $(DISPLAY)
#export DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0.0
#  xmodmap -pke | grep Caps
# install:
# 	$(shell sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev)

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

.PHONY: clean fclean re display

define IMG

		████████████████████████████████████████████████
		::::::::::::::::::::::::::::::::::::::::::::::::
		::██╗::████████╗:::::██╗::::██╗██████╗██████╗:::
		::██║::██╚════██╗::::██║::::████╔═══████╔══██╗::
		::███████║█████╔╝::::██║:█╗:████║:::████████╔╝::
		::╚════████╔═══╝:::::██║███╗████║:::████╔══██╗::
		:::::::█████████╗::::╚███╔███╔╚██████╔██████╔╝::
		:::::::╚═╚══════╝::::╚══╝╚══╝ ╚═════╝╚═════╝::::
		:::::::::::███████╗::::██████╗:::::███████╗:::::
		:::::::::::██╔════╝::::██╔══██╗::::██╔════╝:::::
		:::::::::::█████╗::::::██║::██║::::█████╗:::::::
		:::::::::::██╔══╝::::::██║::██║::::██╔══╝:::::::
		:::::::::::██║:::::::::██████╔╝::::██║::::::::::
		:::::::::::╚═╝:::::::::╚═════╝:::::╚═╝::::::::::
		████████████████████████████████████████████████


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
# $(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
# $(OBJS): $(SRCS) | $(OBJS_DIR)
# SRC =	fdf.c	\
# 		utils.c
# SRCS = $(wildcard $(SRCS_DIR)/*.c)
# OBJS := $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))
# $(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADER)| $(OBJS_DIR)
# $(addprefix $(OBJS_DIR), %.o) : $(SRCS_DIR)%.c | $(OBJS_DIR)