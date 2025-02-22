# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/07 06:19:25 by zogrir            #+#    #+#              #
#    Updated: 2025/02/22 23:49:20 by zogrir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
NAME = so_long

SRC_MANDATORY = srcs/tools/ft_strncmp.c srcs/tools/get_next_line_utils.c srcs/tools/get_next_line.c srcs/tools/map_extention.c srcs/tools/freeing.c srcs/read_line.c srcs/valid_map1.c srcs/valid_map2.c \
srcs/main.c srcs/window_textures.c srcs/key_handler.c srcs/tools/ft_putnbr_fd.c srcs/tools/ft_itoa.c

OBJ_MANDATORY = $(SRC_MANDATORY:%.c=%.o)

all:$(NAME)

%.o:%.c so_long.h get_next_line.h
	$(CC) $(CFLAGS) -c %< -o %@

$(NAME):$(OBJ_MANDATORY)
	$(CC) $(CFLAGS) $(OBJ_MANDATORY) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJ_MANDATORY)
fclean:clean
	rm -rf $(NAME)
re: fclean all
