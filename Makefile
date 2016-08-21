NAME = fdf

CC = gcc

INCLUDES = "libft/includes"

FLAGS = -Wall -Wextra -Werror

MLXFLA = -lmlx -framework OpenGL -framework AppKit

SRC =	action_listenner.c all_tab.c arrow_coor.c draw_line.c \
	error_gev.c eventml.c fdf.c get_next_line.c img_func.c \
	libftfunc.c normal_coor.c our_give.c smallscale_coor.c testa_color.c

LIB = libft/libft.a

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : 
	make -C libft/
	$(CC) $(FLAGS) -c $(SRC) -I $(INCLUDES)
	$(CC) $(FLAGS) -o $(NAME) $(SRC) $(MLXFLA) $(LIB) -I $(INCLUDES)

clean :	
	make -C libft/ clean
	rm -f $(OBJ)

fclean : clean
	rm -f $(LIB)
	rm -f $(NAME)

re : fclean all