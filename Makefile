# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 17:28:37 by gfezzuog          #+#    #+#              #
#    Updated: 2022/10/29 14:05:22 by gfezzuog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = ft_matrix.c \
	  ft_mapchecker.c \
	  ft_countinglen.c \


HDRS = libft.h

OBJ = $(SRC:.c=.o)

RM = rm -f

%.o: %.c
	gcc -g -Wall -Wextra -Werror -Imlx -I ${HDRS} -c $< -o $@

$(NAME): $(OBJ)
	make -C ./libft/ all
	make -C ./mlx/
	gcc $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit ./libft/libft.a -o $(NAME)

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