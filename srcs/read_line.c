/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 09:02:21 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/21 02:51:20 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/get_next_line.h"


char	**ft_allocation(char **map, char *file_name)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("\033[1;31m🛑ERROR: opening file\033[0m\n", 2);
		return (NULL);
	}
	while ((line = get_next_line(fd)))
	{
		if (line[0] == '1')
		{
			map[i] = line;
			printf("✅ Map Line [%d]: %s", i, map[i]);
			i++;
		}
		else
			free(line);
	}
	map[i] = NULL;
	printf("\n✅ Last Stored Line: %s\n", map[i - 1]);
	return (map);
}

int	get_lenght(char *str)
{
	int	i = 0;

	while (str[i] && str[i] != '\n')
		i++;
	return (i);	
}
char	**read_map(char *file_name)
{
	int		fd;
	int		wc;
	char	*line;	
	char 	**map;
	int		size = 0;

	wc = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("\033[1;31m🛑ERROR: opening file\033[0m\n", 2);
		return (NULL);
	}
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
	// while ((line = get_next_line(fd)) != NULL)
	// {
	// 	if (line[0] == '1')
	// 		wc++;
	// 	free(line); 
	// }

	printf("Number of valid map lines: %d\n", wc);
	map = malloc(sizeof(char *) * (wc + 1));
	if (!map)
		return (NULL);
	ft_allocation(map, file_name);	


	return (map);
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
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{	ft_free_arr(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
