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
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm $(LIB42)libft.a

#------------------------------------------------------------------------Source
SRC     := src/map/validate_map.c src/map/make_map.c src/utils/free_map.c \
       src/map/print.c src/map/check_path.c src/graphics/draw_map.c \
       src/graphics/load_images.c src/map/check_map.c \
       src/move/directions.c src/map/collectable.c src/map/path.c

#-----------------------------------------------------------------------Objects
OBJS	:= ${SRCS:.c=.o}

#---------------------------------------------------------------------Directory
OBJ_DIR := objs/

#-------------------------------------------------------------------------Rules
all: libmlx lib42 $(NAME)

$(OBJ_DIR)%.o : %.c
	@echo "hi dir"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
	@echo "OBJ_DIR done!"

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
	@echo "MLX42 ready!"

lib42:
	@echo "hi"
	@$(MAKE) -C $(LIB42)
	@echo "Lib42 ready!"

$(NAME): $(OBJ_DIR)
	@echo "haro"
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJ_DIR)
	@rm -f $(LIBMLX)/build

fclean: clean
	@rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx