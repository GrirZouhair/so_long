/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:17:19 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/23 01:12:49 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_window(t_game *game, int w_win, int h_win)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putstr_fd("\033[1;31m🛑ERR:Failed MiniLibX\033[0m\n", 2);
		exit(1);
	}
	game->win = mlx_new_window(game->mlx, w_win * 32, h_win * 32, "so_long");
	if (!game->win)
	{
		ft_putstr_fd("\033[1;31m🛑ERROR: Failed to create window\033[0m\n", 2);
		exit(1);
	}
	game->width_win = w_win;
	game->height_win = h_win;
}

void	load_textures(t_game *game, t_textures *tx)
{
	tx->wall = mlx_xpm_file_to_image(game->mlx, "./assets/wall.xpm",
			&game->width_win, &game->height_win);
	tx->floor = mlx_xpm_file_to_image(game->mlx, "./assets/floor.xpm",
			&game->width_win, &game->height_win);
	tx->player = mlx_xpm_file_to_image(game->mlx, "./assets/player.xpm",
			&game->width_win, &game->height_win);
	tx->collective = mlx_xpm_file_to_image(game->mlx, "./assets/key.xpm",
			&game->width_win, &game->height_win);
	tx->exit = mlx_xpm_file_to_image(game->mlx, "./assets/exit.xpm",
			&game->width_win, &game->height_win);
}

static void    render_tile(t_game *game, char tile, int x, int y)
{
    char *tmp = ft_itoa(game->player.moves);
    mlx_put_image_to_window(game->mlx, game->win,
        game->tx.floor, x * 32, y * 32);
    mlx_string_put(game->mlx, game->win, 1, 1,
        0xFFFFFF, tmp);
    if (tile == '1')
    {
        mlx_put_image_to_window(game->mlx, game->win,
            game->tx.wall, x * 32, y * 32);
    }
    else if (tile == 'P')
    {
        mlx_put_image_to_window(game->mlx, game->win,
            game->tx.player, x * 32, y * 32);
    }
    else if (tile == 'C')
    {
        mlx_put_image_to_window(game->mlx, game->win,
            game->tx.collective, x * 32, y * 32);
    }
    else if (tile == 'E')
    {
        mlx_put_image_to_window(game->mlx, game->win,
            game->tx.exit, x * 32, y * 32);
    }
    free(tmp);
}

void	render_map(t_game *game, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			render_tile(game, map[y][x], x, y);
			x++;
		}
		y++;
	}
}
