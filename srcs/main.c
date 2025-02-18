/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:13:05 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/18 13:17:58 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"



void	player_movement(t_player *player, int new_x, int new_y)
{
	int collective = 0;
	int i = 0;
	int j;
	
	if (player->map[new_y][new_x] == '1')
		return;
	if (player->map[new_y][new_x] == 'E')
	{
		collective = 0;
		while (player->map[i])
		{
			j = 0;
			while (player->map[i][j])
			{
				if (player->map[i][j] == 'C')
					collective++;
				j++;
			}
			i++;
		}
		if (collective == 0)
		{
			printf("you're won");
			exit(1);
		}		
	}

	if (player->map[new_y][new_x] == 'C')
		player->map[new_y][new_x] = '0';
	player->x = new_x;
	player->y = new_y;
	player->map[new_y][new_x] = 'P';
	player->moves++;
	printf("moves [%d]\n", player->moves);
	
}



int	keyHandler(int key_code, void *param)
{
	t_game *game = (t_game *)param;
	t_player *player = &game->player;
	int new_x = player->x;
	int new_y = player->y;
	if (key_code == KEY_W)
		new_y--;
	else if (key_code == KEY_A)
		new_x--;
	else if (key_code == KEY_S)
		new_y++;
	else if (key_code == KEY_D)
		new_x++;
	player_movement(player, new_x, new_y);
	if (key_code == KEY_EXIT)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(1);
	}
	return (1);
}
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
