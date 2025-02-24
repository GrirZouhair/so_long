/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 09:02:21 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/24 08:12:08 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

char	**ft_allocation(char **map, char *file_name)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("\033[1;31m🛑ERR:file\033[0m\n", 2), NULL);
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '1')
		{
			map[i] = line;
			i++;
		}
		else
			free(line);
		line = get_next_line(fd);
	}
	map[i] = NULL;
	return (close(fd), map);
}

int	get_lenght(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	**read_map(char *file_name)
{
	int		fd;
	int		wc;
	char	*line;
	char	**map;
	int		size;

	wc = 0;
	size = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("\033[1;31m🛑ERR:file\033[0m\n", 2), NULL);
	line = get_next_line(fd);
	size = get_lenght(line);
	while (line)
	{
		if (get_lenght(line) != size)
			exit(1);
		wc++;
		free(line);
		line = get_next_line(fd);
	}
	map = malloc(sizeof(char *) * (wc + 1));
	if (!map)
		return (close(fd), NULL);
	return (close(fd), ft_allocation(map, file_name), map);
}

char	**ft_duplicate_map(char **map)
{
	char	**copy;
	int		i;
	int		wc;

	i = 0;
	wc = 0;
	while ((map[wc] != NULL))
		wc++;
	copy = malloc(sizeof(char *) * (wc + 1));
	if (!copy)
		return (NULL);
	while (i < wc)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
			return (ft_free_arr(copy), NULL);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
