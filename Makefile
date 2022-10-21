# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 17:28:37 by gfezzuog          #+#    #+#              #
#    Updated: 2022/10/21 17:46:53 by gfezzuog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = so_long.c \


HDRS = libft.h

OBJ = $(SRC:.c=.o)

RM = rm -f

%.o: %.c
	gcc -Wall -Wextra -Werror -Imlx -I ${HDRS} -c $< -o $@

$(NAME): $(OBJ)
	make -C ./mlx/
	gcc $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

ex: $(NAME)
	./$(NAME) maps/map2.ber
	make clean
	make -C ./mlx/ clean

clean:
	${RM} $(OBJ)
	make -C ./mlx/ clean

fclean: clean
	${RM} $(NAME) ${OBJ}
	make -C ./mlx/ clean

re: $(NAME)

.PHONY: all clean fclean re