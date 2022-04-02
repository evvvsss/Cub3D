LIBFT = ./libft/libft.a

CFLAGS = -I./includes #-Wall -Werror -Wextra
NAME = cube3d


SRC = 	./src/main.c 				\
		./src/main2.c 				\
		./src/parsing/parser1.c		\
		./src/parsing/parser2.c		\
		./src/error.c 				\
		./src/parsing/parser3.c		\
		./src/parsing/parser.c 		\
		./src/appearance/map.c		\
		./src/appearance/degrees.c 	\
		./src/appearance/map2.c 	\
		./src/appearance/walls.c 	\
		./src/appearance/color.c 	\
		./src/appearance/draw.c 	\



CC = gcc

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(MAKE) -C ./libft
		$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJ) ./libft/libft.a

%.o: %.c
		gcc  $(CFLAGS) -c $< -o $@

clean:
		$(MAKE) clean -C ./libft
		rm -rf $(OBJ)

fclean: clean
		$(MAKE) fclean -C ./libft
		rm -rf $(NAME)
re: fclean all

.PHONY:	all clean fclean re