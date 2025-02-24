/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:23:11 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/24 08:12:16 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

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

static void	flood_fill(t_flood *data, int x, int y)
{
	if (x < 0 || y < 0 || data->copy[y] == NULL || data->copy[y][x] == '\0')
		return ;
	if (data->copy[y][x] == '1' || data->copy[y][x] == 'V')
		return ;
	if (data->copy[y][x] == 'E')
	{
		data->exit_num = 1;
		return ;
	}
	if (data->copy[y][x] == 'C')
		data->collected++;
	data->copy[y][x] = 'V';
	flood_fill(data, x + 1, y);
	flood_fill(data, x - 1, y);
	flood_fill(data, x, y + 1);
	flood_fill(data, x, y - 1);
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
				count++;
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
	t_flood	data;

	x = 0;
	y = 0;
	data.copy = ft_duplicate_map(map);
	data.collected = 0;
	data.exit_num = 0;
	data.total_collectibles = count_collection(map);
	ft_find_player_position(map, &x, &y);
	flood_fill(&data, x, y);
	if (data.collected != data.total_collectibles)
		return (ft_free_arr(data.copy),
			ft_putstr_fd("\033[1;31m🛑ERROR:keys prblm\033[0m\n", 2), 0);
	if (!data.exit_num)
		return (ft_free_arr(data.copy),
			ft_putstr_fd("\033[1;31m🛑ERROR: exit prblm\033[0m\n", 2), 0);
	ft_free_arr(data.copy);
	return (1);
}

int	validate_map(char **map)
{
	if (!ft_valid_char(map) || !ft_valid_elements(map)
		||!ft_valid_walls(map) || !ft_validate_path(map))
		return (0);
	return (1);
}
