/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 04:33:57 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/15 10:34:02 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include<stdlib.h>
#include<unistd.h>

#include<stdio.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	map_extention(char *file_extention);
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
void 	ft_free_arr(char **arr);




char **ft_duplicate_map(char **map);


int		ft_valid_char(char **map);
int		ft_valid_rectangular(char **map);
int		ft_valid_elements(char **map);
int		ft_valid_walls(char **map);
int		ft_validate_path(char **map);
int		validate_map(char **map);
char	**read_map(char *file_name);
#endif