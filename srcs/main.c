/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:13:05 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/19 15:03:37 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void ft_player_pos(t_player *p, char **map)
{
	int i = 0;
	int j;
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
				return;
			}
			j++;
		}
		i++;
	}
	
}

int main(int ac, char **av)
{
	t_game game; 
    t_textures tx;
	int map_width = 0;
	int map_height = 0;
    if (ac > 1)
	{
		char **map = read_map(av[1]);
		while (map[map_height])
		{
			map_width = ft_strlen(map[map_height]);
			map_height++;
		}
   		init_window(&game, map_width , map_height);
    	load_textures(&game, &tx);
		render_map(&game, map, &tx);
		ft_player_pos(&game.player, map);
		mlx_key_hook(game.win, keyHandler, &game);
		mlx_loop(game.mlx);
	}else
	{
		ft_putstr_fd("\033[1;31m🛑ERROR: few args\033[0m\n", 2);
		exit(1);
	}

    return 0;
}
