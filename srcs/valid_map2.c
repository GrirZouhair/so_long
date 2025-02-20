/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:23:11 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/20 16:27:52 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/so_long.h"

int	ft_valid_walls(char **map)
{
	int	i;
	int	width;
	int	height;

	i = 0;
	width = ft_strlen(map[0]);
	height = 0;
	while (map[height])
		height++;
	while (i < width - 1)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (ft_putstr_fd("\033[1;31m🛑ERROR: we need walls X\033[0m\n", 2), 0);
		i++;		
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width-1] != '1')
			return (ft_putstr_fd("\033[1;31m🛑ERROR: we need walls Y\033[0m\n", 2), 0);
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
				return;
			}
			j++;
		}
		i++;
	}
	*x = -1;
	*y = -1;
}


static void flood_fill(char **map, int x, int y)
{
	if (map[y] == NULL || map[y][x] == '\0' || x < 0 || y < 0)
		return;
	if (map[y][x] == '1' || map[y][x] == 'Z') 
		return;
	map[y][x] = 'Z';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}


int	ft_validate_path(char **map)
{
	int	x;
	int	y;
	int	i;
	int	j;

	i = 0;
	char **copy = ft_duplicate_map(map);
	ft_find_player_position(map, &x, &y);
	flood_fill(copy, x, y);
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{
			if ((copy[i][j] == 'C') || (copy[i][j] == 'E'))
				return (ft_putstr_fd("\033[1;31m🛑ERROR: path not found\033[0m\n", 2), 0);
			j++;
		}
		i++;
	}
	return(1);
}



int	validate_map(char **map)
{
	if (!ft_valid_char(map) 
	||	!ft_valid_elements(map) 
	|| !ft_validate_path(map))
	{
		return (0);
	}
	return (1);
			
}
//|| !ft_valid_rectangular(map)  || !ft_valid_walls(map)
// int main()
// {
// 	char *map[] = {
// 		"1111111",
// 		"100PC01",
// 		"10000E1",
// 		"1111111",
// 		NULL // Null-terminate the array
// 	};

// 	if (validate_map(map))
// 		printf("\033[1;32m✅ Map is correctly surrounded by walls.\033[0m\n");
// 	else
// 		printf("\033[1;31m❌ Map validation failed.\033[0m\n");

// 	return (0);
// }