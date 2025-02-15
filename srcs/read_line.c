/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 09:02:21 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/15 12:02:20 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/get_next_line.h"

char	**ft_allocation(char **map, char *file_name)
{
	int	i;
	int	fd;
	char *line;

	i = 0;
	fd = open(file_name, O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	
	return (map);
}

char	**read_map(char *file_name)
{
	int		fd;
	int		wc;
	char	*line;	
	char 	**map;

	wc = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("\033[1;31m🛑ERROR: opening file\033[0m\n", 2);
		return (NULL);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		wc++;
		free(line);
	}
	map = malloc(sizeof(char *) * (wc + 1));
	if (!map)
		return (NULL);
	return (ft_allocation(map, file_name));	
}


char **ft_duplicate_map(char **map)
{
	char **copy;
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while ((map[wc] != NULL))
		wc++;
	copy = malloc(sizeof(char *) * (wc + 1));
	if (!copy)
		return (NULL);
	while (i < wc)
	{
		copy[i] = map[i];
		if (!copy[i])
		{	ft_free_arr(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
