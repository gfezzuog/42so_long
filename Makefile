# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 17:28:37 by gfezzuog          #+#    #+#              #
#    Updated: 2022/11/08 17:37:05 by gfezzuog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = so_long.c \
	  ft_matrix.c \
	  ft_mapchecker.c \
	  ft_countinglen.c \
	  ft_mapchecker2.c \
	  ft_helper.c \


HDRS = libft.h

OBJ = $(SRC:.c=.o)

RM = rm -f

%.o: %.c
	gcc -g -Wall -Wextra -Werror -I ${HDRS} -c $< -o $@

$(NAME): $(OBJ)
	make -C ./libft/ all
#	make -C ./mlx/
	gcc  $(OBJ) ./libft/libft.a -o $(NAME)
#	 -Lmlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

ex: $(NAME)
#	./$(NAME) maps/map2.ber
#	make clean
#	make -C ./mlx/ clean

clean:
	${RM} $(OBJ)
	make -C ./libft/ clean
#	make -C ./mlx/ clean

fclean: clean
	${RM} $(NAME) ${OBJ}
	make -C ./libft/ clean
#	make -C ./mlx/ clean

re: $(NAME)

.PHONY: all clean fclean re