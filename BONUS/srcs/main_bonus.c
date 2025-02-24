/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:13:05 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/24 08:19:57 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	ft_player_pos(t_player *p, char **map)
{
	int	i;
	int	j;

	i = 0;
	p->map = map;
	while (p->map[i])
	{
		j = 0;
		while (p->map[i][j])
		{
			if (p->map[i][j] == 'P')
			{
				p->x = j;
				p->y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	ft_count(char **map, int *h, int *w)
{
	while (map[*h])
	{
		*w = get_lenght(map[0]);
		(*h)++;
	}
}

int	main(int ac, char **av)
{
	t_game	game;
	int		map_width;
	int		map_height;
	char	**map;

	game.player.moves = 1;
	(1) && (map_height = 0, map_width = 0);
	map_extention(av[1]);
	map = read_map(av[1]);
	if (!validate_map(map))
		return (ft_free_arr(map),
			ft_putstr_fd("\033[1;31m🛑ERROR: few args\033[0m\n", 2), 0);
	if (ac > 1)
	{
		ft_count(map, &map_height, &map_width);
		init_window(&game, map_width, map_height);
		load_textures(&game, &game.tx);
		render_map(&game, map);
		ft_player_pos(&game.player, map);
		mlx_key_hook(game.win, key_handler, &game);
		mlx_loop(game.mlx);
	}
	else
		return (ft_free_arr(map),
			ft_putstr_fd("\033[1;31m🛑ERROR: few args\033[0m\n", 2), 0);
}
