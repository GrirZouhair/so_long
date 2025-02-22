/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:23:11 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/23 00:07:31 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

static void	ft_find_player_position(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
	*x = -1;
	*y = -1;
}

static void	flood_fill(char **map, int x, int y, int *ec)
{
	if (map[y] == NULL || map[y][x] == '\0' || x < 0 || y < 0
		|| map[y][x] == '1' || map[y][x] == 'E')
		return ;
	if (map[y][x] == 'C' || map[y][x] == 'E')
		(*ec)++;
	map[y][x] = '1';
	flood_fill(map, x + 1, y, ec);
	flood_fill(map, x - 1, y, ec);
	flood_fill(map, x, y + 1, ec);
	flood_fill(map, x, y - 1, ec);
}

int	count_collection(char **map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

static int	ft_validate_path(char **map)
{
	int		x;
	int		y;
	int		i;
	int		j;
	char	**copy;
	int		ec;

	(1) && (i = 0, ec = 0);
	copy = ft_duplicate_map(map);
	ft_find_player_position(map, &x, &y);
	flood_fill(copy, x, y, &ec);
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{
			if (copy[i][j] == 'C')
				return (ft_putstr_fd("\033[1;31m🛑ERROR:path\033[0m\n", 2), 0);
			j++;
		}
		i++;
	}
	if (ec != count_collection(map))
		return (ft_putstr_fd("\033[1;31m🛑ERROR:invalid placement\033[0m\n", 2), 0);
	return (1);
}

int	validate_map(char **map)
{
	if (!ft_valid_char(map) || !ft_valid_elements(map)
		||!ft_valid_walls(map) || !ft_validate_path(map))
		return (0);
	return (1);
}
