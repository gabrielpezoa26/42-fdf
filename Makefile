# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 14:04:57 by gcesar-n          #+#    #+#              #
#    Updated: 2025/02/05 12:06:52 by gabriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
BONUS_NAME = fdf_bonus

CC = cc
CFLAGS = -Wextra -Wall -Werror -Wunreachable-code -Ofast -g
INCLUDES = -I ./src -I ./MLX42/include -I ./MLX42/include/MLX42 -I ./libft

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX42_DIR = ./MLX42
MLX42_BUILD = $(MLX42_DIR)/build
LIBMLX42 = $(MLX42_BUILD)/libmlx42.a
LIBS = $(LIBMLX42) -ldl -lglfw -pthread -lm

SRCS_MANDATORY =	src/error_handler.c \
					src/main.c \
					src/map_parser.c \
					src/render.c \
					src/utils.c \
					src/setup.c \
					src/controls.c

SRCS_BONUS =	src/error_handler.c \
				bonus_files/main_bonus.c \
				src/map_parser.c \
				src/render.c \
				src/utils.c \
				src/setup.c \
				bonus_files/controls_bonus.c

OBJS_MANDATORY = $(SRCS_MANDATORY:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

DEPS = ./src/fdf.h

all: $(NAME)

$(NAME): $(OBJS_MANDATORY) $(LIBMLX42) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_MANDATORY) -o $(NAME) $(LIBFT) $(LIBS)
	@echo "linkingggg $(NAME) without bonus files"

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJS_BONUS) $(LIBMLX42) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(BONUS_NAME) $(LIBFT) $(LIBS)
	@echo "linkingggg $(BONUS_NAME) with bonus files"

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "compilinggg $<"

$(LIBMLX42):
	cmake -DDEBUG=1 $(MLX42_DIR) -B $(MLX42_BUILD)
	make -C $(MLX42_BUILD) -j4

$(LIBFT):
	make -C $(LIBFT_DIR) all

clean:
	rm -rf $(OBJS_MANDATORY) $(OBJS_BONUS)
	make clean -C $(LIBFT_DIR)
	rm -rf $(MLX42_BUILD)
	@echo "cleaningggg"

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	make fclean -C $(LIBFT_DIR)
	@echo "full cleaningggg"

re: fclean all
