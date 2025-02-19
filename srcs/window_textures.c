/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:17:19 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/19 16:41:31 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void init_window(t_game *game, int w_win, int h_win)
{
    game->mlx = mlx_init();
    if (!game->mlx)
    {
        ft_putstr_fd("\033[1;31m🛑ERROR: Failed to initialize MiniLibX\033[0m\n", 2);
        exit(1);
    }
    game->win = mlx_new_window(game->mlx, w_win * 32, h_win * 32, "so_long_zouhair");
    if (!game->win)
    {
        ft_putstr_fd("\033[1;31m🛑ERROR: Failed to create window\033[0m\n", 2);
        exit(1);    
    }
    game->width_win = w_win;
    game->height_win = h_win;
}

void load_textures(t_game *game, t_textures *tx)
{
    tx->wall = mlx_xpm_file_to_image(game->mlx, "./assets/wall.xpm", &game->width_win, &game->height_win);
    tx->floor = mlx_xpm_file_to_image(game->mlx, "./assets/floor.xpm", &game->width_win, &game->height_win);
    tx->player = mlx_xpm_file_to_image(game->mlx, "./assets/player.xpm", &game->width_win, &game->height_win);
    tx->collective = mlx_xpm_file_to_image(game->mlx, "./assets/key.xpm", &game->width_win, &game->height_win);
    tx->exit = mlx_xpm_file_to_image(game->mlx, "./assets/exit.xpm", &game->width_win, &game->height_win);
}

void	render_map(t_game *game, char **map, t_textures *tx)
{
	int	x, y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!tx->floor || !tx->wall || !tx->player || !tx->collective || !tx->exit)
			{
				write(1, "the issue here", 17);
			}
			mlx_put_image_to_window(game->mlx, game->win, tx->floor, x * 32, y * 32);
			if (map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, tx->wall, x * 32, y * 32);
			else if (map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, tx->player, x * 32, y * 32);
			else if (map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, tx->collective, x * 32, y * 32);
			else if (map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, tx->exit, x * 32, y * 32);
			x++;
		}
		y++;
	}
}