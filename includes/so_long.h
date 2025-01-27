/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 10:36:55 by zogrir            #+#    #+#             */
/*   Updated: 2025/01/05 08:33:21 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

#include<mlx.h>
#include "../includes/get_next_line.h"
#include<fcntl.h>
#include<unistd.h>

typedef struct game_controll
{
	int		c;
	int		p;
	int		e;
	int		w;
	int		h;
};

typedef struct game_vars
{
	void	*mlx;
	void	*img;
	void	*win;
	int		mouvement;
	char	**map;
	int 	collect;
} game_vars;



int	ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
void map_extention(char *file_extention);

#endif