/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 04:33:57 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/07 06:16:29 by zogrir           ###   ########.fr       */
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



#endif