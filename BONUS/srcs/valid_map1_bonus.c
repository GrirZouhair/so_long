/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map1_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:08:44 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/24 08:12:12 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static int	ft_check(char c)
{
	if (c == '\n')
		return (1);
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
	{
		return (1);
	}
	return (0);
}

int	ft_valid_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_check(map[i][j]) == 0)
			{
				ft_putstr_fd("\033[1;31m🛑ERROR: Invalid character\033[0m\n", 2);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_valid_rectangular(char **map)
{
	size_t	width;
	int		i;

	i = 0;
	width = 0;
	if (!map || !map[0])
		return (0);
	width = ft_strlen(map[0]);
	while (map[i])
	{
		if (width != ft_strlen(map[i]))
		{
			ft_putstr_fd("\033[1;31m🛑ERROR: Map not rectangular\033[0m\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_valid_elements(char **map)
{
	int	i;
	int	j;
	int	wc_e;
	int	wc_c;
	int	wc_p;

	(1) && (i = 0, wc_e = 0, wc_c = 0, wc_p = 0);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				wc_e++;
			else if (map[i][j] == 'C')
				wc_c++;
			else if (map[i][j] == 'P')
				wc_p++;
			j++;
		}
		i++;
	}
	if (wc_e != 1 || wc_c <= 0 || wc_p != 1)
		return ((ft_putstr_fd("\033[1;31m🛑ERR:invalid\033[0m\n", 2), 0));
	return (1);
}

int	ft_valid_walls(char **map)
{
	int	i;
	int	width;
	int	height;

	i = 0;
	width = get_lenght(map[0]);
	height = 0;
	while (map[height])
		height++;
	if (height > 64 || width > 120)
		return (ft_putstr_fd("\033[1;31m🛑ERR:Too much line\033[0m\n", 2), 0);
	while (i < width - 1)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (ft_putstr_fd("\033[1;31m🛑ERR: Wall X\033[0m\n", 2), 0);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (ft_putstr_fd("\033[1;31m🛑ERR: Wall Y\033[0m\n", 2), 0);
		i++;
	}
	return (1);
}
