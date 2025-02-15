# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/07 06:19:25 by zogrir            #+#    #+#              #
#    Updated: 2025/02/15 10:30:31 by zogrir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long

SRC_MANDATORY = srcs/ft_strncmp.c srcs/get_next_line_utils.c srcs/get_next_line.c srcs/map_extention.c srcs/freeing.c srcs/read_line.c srcs/valid_map1.c srcs/valid_map2.c \
srcs/main.c

OBJ_MANDATORY = $(SRC_MANDATORY:%.c=%.o)

all:$(NAME)

%.o:%.c so_long.h get_next_line.h
	$(CC) $(CFLAGS) -c %< -o %@
$(NAME):$(OBJ_MANDATORY)
	$(CC) $(CFLAGS) $(OBJ_MANDATORY) -o $(NAME)

clean:
	rm -rf $(OBJ_MANDATORY)
fclean:clean
	rm -rf $(NAME)
re: fclean all