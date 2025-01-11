# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 14:04:57 by gcesar-n          #+#    #+#              #
#    Updated: 2025/01/11 16:50:07 by gabriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = cc

MLX = -L/usr/local/lib -lmlx
LIBS = -lXext -lX11 -lm

LIBFT = ./libft/libft.a

SRC = ./src/fdf.c ./src/fdf_utils.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I./libft -I./includes

all: $(NAME)
	@echo "compiling aaaaaaaaa"

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o fdf $(OBJ) $(LIBFT) $(LIBS) $(MLX)

clean:
	@echo "cleaningggggg"
	rm -f $(OBJ)

fclean: clean
	@echo "full cleannnnn"
	rm -f fdf

re: fclean all
	@echo "cleaning and compilingggg"