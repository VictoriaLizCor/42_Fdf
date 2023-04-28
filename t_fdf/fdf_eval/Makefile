NAME = fdf

SRCS_DIR := src/
SRCS =	src/fdf.c			\
		src/render.c		\
		src/draw_line.c		\
		src/color.c			\
		src/utils.c			\
		src/hooks.c			\
		src/check_error.c

CFLAGS = -Wall -Wextra -Werror
CINCLUDES += -I include/
HEADER +=	include/fdf.h
HEADER +=	include/hook_key.h
HEADER +=	include/hook_key.h

OBJS_DIR = obj/
OBJS := $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.c=.o)))
LIBFT_DIR = lib/libft/
LIBFT =  $(LIBFT_DIR)libft.a

LIBFT_FLAGS = -L./$(LIBFT_DIR) -lft
CINCLUDES += -I $(LIBFT_DIR)

ifeq ($(shell uname), Linux)
	MLX_DIR = lib/minilibx_linux/
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd
	CINCLUDES += -I /usr/include/
endif
ifeq ($(shell uname), Darwin)
	MLX_DIR = lib/minilibx_macos/
	MLX_FLAGS = -L.. -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif
MLX = $(MLX_DIR)libmlx.a
CINCLUDES += -I $(MLX_DIR)

all: $(LIBFT) $(MLX) $(OBJS_DIR) $(NAME)

$(NAME): $(HEADER) $(OBJS)
	@echo $(GREEN)
	cc -g $(CFLAGS) $(CINCLUDES) $(OBJS) -o $@ $(LIBFT) $(MLX) $(LIBFT_FLAGS) $(MLX_FLAGS)
	$(BANNER_FDF)




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

#sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
#export DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0.0