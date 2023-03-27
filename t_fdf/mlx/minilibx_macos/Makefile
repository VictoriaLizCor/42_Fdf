#
#

NOM = libmlx.a
SRC_c = mlx_shaders.c mlx_xpm.c mlx_int_str_to_wordtab.c 
SRC_m = mlx_new_window.m mlx_init_loop.m mlx_new_image.m 
OBJS_DIR = obj/
OBJ_c = $(addprefix $(OBJS_DIR), $(SRC_c:.c=.o))
OBJ_m=   $(addprefix $(OBJS_DIR), $(SRC_m:.m=.o))
CFLAGS+=-O2 -Wno-deprecated-declarations

all: $(OBJS_DIR) $(NOM)

$(NOM):	$(OBJ_c) $(OBJ_m)
	ar -r $(NOM) $(OBJ_c) $(OBJ_m)
	@ar -t $@
#	ranlib $(NOM)

$(OBJS_DIR) : 
	@mkdir -p $@
	@echo mkdir -p $(shell pwd | awk -F / '{print $$(NF-1)"/"$$(NF)}')/$(OBJS_DIR)

$(addprefix $(OBJS_DIR), %.o): %.c 
	@cc -c $(CFLAGS) $^ -o $@

$(addprefix $(OBJS_DIR), %.o): %.m 
	@cc -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(NOM) *~
	@rm -rf $(OBJS_DIR)
	@echo rm -f $(shell pwd | awk -F / '{print $$(NF-1)"/"$$(NF)}')/$(OBJS_DIR)
	rm -f mlx_app

re: clean all
