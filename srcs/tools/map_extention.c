/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_extention.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 04:37:16 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/22 10:29:47 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	map_extention(char *file_extention)
{
	size_t	len;
	size_t	ext_len;

	len = ft_strlen(file_extention);
	ext_len = ft_strlen(".ber");
	if (len >= ext_len
		&& ft_strncmp(file_extention + len - ext_len, ".ber", ext_len) == 0)
		return ;
	ft_putstr_fd("\033[1;31m🛑ERROR: Adding to list failed\033[0m\n", 2);
	exit(1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (fd == -1 || !s)
		return ;
	while (*s)
		write(fd, s++, 1);
	write(1, "\n", 1);
}
