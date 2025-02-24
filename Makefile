# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/07 06:19:25 by zogrir            #+#    #+#              #
#    Updated: 2025/02/24 08:10:19 by zogrir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
NAME_BNS = so_long_bonus

SRC_MANDATORY = srcs/tools/ft_strncmp.c srcs/tools/get_next_line_utils.c srcs/tools/get_next_line.c srcs/tools/map_extention.c srcs/tools/freeing.c srcs/read_line.c srcs/valid_map1.c srcs/valid_map2.c \
srcs/main.c srcs/window_textures.c srcs/key_handler.c srcs/tools/ft_putnbr_fd.c

SRC_BONUS = BONUS/srcs/tools/ft_strncmp_bonus.c  BONUS/srcs/tools/get_next_line_utils_bonus.c  BONUS/srcs/tools/get_next_line_bonus.c  BONUS/srcs/tools/map_extention_bonus.c  BONUS/srcs/tools/freeing_bonus.c  BONUS/srcs/read_line_bonus.c \
BONUS/srcs/valid_map1_bonus.c  BONUS/srcs/valid_map2_bonus.c   BONUS/srcs/main_bonus.c  BONUS/srcs/window_textures_bonus.c  BONUS/srcs/key_handler_bonus.c  BONUS/srcs/tools/ft_putnbr_fd_bonus.c  BONUS/srcs/tools/ft_itoa_bonus.c

OBJ_MANDATORY = $(SRC_MANDATORY:%.c=%.o)
OBJ_BONUS = $(SRC_BONUS:%.c=%.o)

all:$(NAME)
bonus : $(NAME_BNS)

%.o:%.c so_long.h get_next_line.h
	$(CC) $(CFLAGS) -c %< -o %@

%.o:%.c so_long_bonus.h get_next_line_bonus.h
	$(CC) $(CFLAGS) -c %< -o %@

$(NAME):$(OBJ_MANDATORY)
	$(CC) $(CFLAGS) $(OBJ_MANDATORY) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(NAME_BNS):$(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -lmlx -framework OpenGL -framework AppKit -o $(NAME_BNS)
clean:
	rm -rf $(OBJ_MANDATORY) $(OBJ_BONUS)
fclean:clean
	rm -rf $(NAME) $(NAME_BNS)
re: fclean all
