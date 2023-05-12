#--------------------------------------------------------------------Executable
NAME	:= so_long


#-------------------------------------------------------------------------Flags
CFLAGS	:+= -Wextra -Wall -Werror -Wunreachable-code -Ofast
ASANFLAGS :+= -fsanitize=address -fsanitize=leak


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
       src/utils/free.c src/graphics/load_images.c src/map/check_map.c \
       src/move/directions.c src/map/collectable.c src/map/path.c


#-----------------------------------------------------------------------Objects
OBJS	:= ${SRCS:.c=.o}


#-------------------------------------------------------------------------Rules
all: libmlx $(NAME))

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@rm -f $(LIBMLX)/build

fclean: clean
	@rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx