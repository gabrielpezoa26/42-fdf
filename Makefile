# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 14:04:57 by gcesar-n          #+#    #+#              #
#    Updated: 2025/01/09 14:05:47 by gcesar-n         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

MLX = -L/usr/local/lib -lmlx
LIBS = -lXext -lX11 -lm

LIBFT = ./libft/libft.a

SRC = fdf.c\

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -I./libft -I./gnl

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o fdf $(OBJ) $(LIBFT) $(LIBS) $(MLX)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f fdf

re: fclean all