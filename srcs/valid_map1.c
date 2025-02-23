/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:08:44 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/23 10:51:38 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
