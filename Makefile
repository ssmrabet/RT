NAME 	= RT
HEADERS = includes
OBJS 	= $(SRC:.c=.o)
CC 		= gcc
FLAGS 	= -Wall -Werror -Wextra
LIB 	= libft/libft.a
LIBMLX 	= minilibx_macos/libmlx.a
LMX 	= -framework OpenGL -framework AppKit 
SRC 	= 	src/add.c \
	src/inter.c \
	src/mouse.c \
	src/add2.c \
	src/key.c \
	src/objects.c \
	src/draw.c \
	src/lighting.c \
	src/parser.c \
	src/free.c \
	src/color.c \
	src/main.c \
	src/corr.c \

all: $(NAME)

$(NAME):		$(OBJS) $(LIB) $(LIBMLX)
				@$(CC) $(FLAGS) $(LMX) $(SRC) $(LIB) $(LIBMLX) -o $(NAME)
				@echo "\033[35mLE PROGRAMME EST PRET !"

$(LIBMLX):
				@make -s -C minilibx_macos
$(LIB):
				@make -s -C libft

%.o : %.c		$(HEADERS)/rt.h
				@$(CC) $(FLAGS) -I $(HEADERS) -c $< -o $@

clean:
				@rm -f $(OBJS)
				@make clean -s -C libft/
				@make clean -s -C minilibx_macos/
				@echo "\033[33mCLEAN DONE"

fclean: clean
				@make fclean -s -C libft/ 
				@rm -f $(NAME)
				@echo "\033[31mFCLEAN DONE"

re: fclean all

.PHONY: clean fclean re
