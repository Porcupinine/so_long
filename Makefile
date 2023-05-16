#--------------------------------------------------------------------Executable
NAME	:= so_long

#----------------------------------------------------------------------Compiler
CC 		=  -gcc

#-------------------------------------------------------------------------Flags
CFLAGS	+= -Wextra -Wall -Werror -Wunreachable-code -Ofast
ASANFLAGS += -fsanitize=address -fsanitize=leak

#----------------------------------------------------------------Libraries path
LIBMLX	:= ./MLX42
LIB42   := ./lib42

#-----------------------------------------------------------------------Headers
HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIB42)/include

#---------------------------------------------------------------------Libraries
LIBS	:= $(LIBMLX)/build/libmlx42.a -lglfw3 -framework Cocoa \
			-framework OpenGL -framework IOKit $(LIB42)/libft.a

#------------------------------------------------------------------------Source
SRC     := src/map/validate_map.c src/map/make_map.c src/utils/free_map.c \
       src/map/print.c src/map/check_path.c src/graphics/draw_map.c \
       src/graphics/load_images.c src/map/check_map.c \
       src/move/directions.c src/map/collectable.c src/move/move_player.c \
       src/utils/queue_functions.c main.c

#-----------------------------------------------------------------------Objects
OBJS	:= ${SRC:.c=.o}

#---------------------------------------------------------------------Directory
OBJ_DIR := objs/
OBJECTS_PREFIXED := $(addprefix $(OBJ_DIR), $(OBJS))

#-------------------------------------------------------------------------Rules
all: $(NAME)

$(OBJ_DIR)%.o : %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

lib42_build:
	@$(MAKE) -C $(LIB42)

$(NAME): libmlx lib42_build $(OBJECTS_PREFIXED)
	@$(CC) $(OBJECTS_PREFIXED) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx lib42_build