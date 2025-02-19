/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:23:51 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/19 15:53:44 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	player_movement(t_player *player, int new_x, int new_y)
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