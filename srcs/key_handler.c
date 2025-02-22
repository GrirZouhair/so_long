/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:23:51 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/22 10:50:03 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	count_collectibles(char **map)
{
	int	i;
	int	j;
	int	collective;

	collective = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				collective++;
			j++;
		}
		i++;
	}
	return (collective);
}

static void	player_movement(t_game *game, int new_x, int new_y)
{
	t_player	*player;

	player = &game->player;
	if (player->map[new_y][new_x] == '1')
		return ;
	if (player->map[new_y][new_x] != 'E')
	{
		player->map[player->y][player->x] = '0';
		player->x = new_x;
		player->y = new_y;
		player->map[new_y][new_x] = 'P';
	}
	else if (count_collectibles(player->map) == 0)
	{
		exit(0);
	}
	render_map(game, player->map);
}

static void	handle_movement(t_game *game, int key_code)
{
	t_player	*player;
	int			new_x;
	int			new_y;

	player = &game->player;
	new_x = player->x;
	new_y = player->y;
	if (key_code == KEY_W)
		new_y--;
	else if (key_code == KEY_A)
		new_x--;
	else if (key_code == KEY_S)
		new_y++;
	else if (key_code == KEY_D)
		new_x++;
	else
		return ;
	ft_putnbr_fd(game->player.moves++, 1);
	player_movement(game, new_x, new_y);
}

int	key_handler(int key_code, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	handle_movement(game, key_code);
	if (key_code == KEY_EXIT)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(1);
	}
	return (1);
}
