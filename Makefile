# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 11:26:20 by vbauguen          #+#    #+#              #
#    Updated: 2016/06/06 14:54:34 by vbauguen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent

NAME = wolf3d\

SRC =	main.c\
		initialisation.c\
		ray.c\
		draw.c\
		reaction.c\
		movement.c\
		map_checking.c\

OBJ = $(SRC:.c=.o)

GCCF = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(OBJ)	
	@make -C minilibx_macos re
	@make -C libft re
	@gcc -o $(NAME) $(OBJ) -L libft -lft -lmlx -framework OpenGL -framework Appkit


%.o: %.c libft/libft.h
	gcc -c $(GCCF) -I libft/ $< -o $@

.PHONY: clean fclean re

clean:
	@rm -rf $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean

re: fclean all
