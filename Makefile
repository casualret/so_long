# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thsiu <thsiu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 21:15:48 by thsiu             #+#    #+#              #
#    Updated: 2022/03/18 14:43:43 by thsiu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
FLAGS = -Wall -Werror -Wextra
FLAGS_M = -lmlx -framework OpenGL -framework AppKit
RM = rm -rf

HEADER = ./libs/so_long.h

SRC = ./src/so_long.c ./src/utils.c ./src/read_map.c ./src/map_render.c \
		./src/map_check_funcs.c ./src/keybinds.c ./src/itoa.c ./src/get_next_line.c \
		./src/ft_strlen.c ./src/ft_strlcpy.c ./src/ft_strjoin.c ./src/ft_strdup.c \
		./src/ft_memcpy.c ./src/animations.c 

OBJ = $(patsubst %.c,%.o,$(SRC))

all:	$(NAME)

$(NAME): 	$(OBJ)
			$(CC) $(FLAGS) $(FLAGS_M) $(OBJ) -o $(NAME)

%.o:	%.c Makefile $(HEADER)
		$(CC) $(FLAGS) -c $< -o $@

clean:
		$(RM) ${OBJ}
		@echo *.o files is clean

fclean:	clean
		$(RM) so_long
		@echo all files is clean!

re:	fclean all

.PHONY: all clean fclean re