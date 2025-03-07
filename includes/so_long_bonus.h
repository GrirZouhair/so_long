/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 04:33:57 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/23 12:24:07 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# include "get_next_line_bonus.h"

typedef struct s_player
{
	char	**map;
	int		x;
	int		y;
	int		moves;
}	t_player;

typedef struct s_textures
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*collective;
	void	*exit;
}	t_textures;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			width_win;
	int			height_win;
	t_player	player;
	t_textures	tx;
}	t_game;

typedef struct s_movement
{
	int	w;
	int	a;
	int	s;
	int	d;
}	t_movement;

typedef struct s_flood
{
	char	**copy;
	int		collected;
	int		total_collectibles;
	int		exit_num;
}	t_flood;

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_EXIT 53

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	map_extention(char *file_extention);
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
void	ft_free_arr(char **arr);
char	**ft_duplicate_map(char **map);
int		ft_valid_char(char **map);
int		ft_valid_rectangular(char **map);
int		ft_valid_elements(char **map);
int		ft_valid_walls(char **map);
int		validate_map(char **map);
char	**read_map(char *file_name);
void	init_window(t_game *game, int w_win, int h_win);
void	load_textures(t_game *game, t_textures *tx);
void	render_map(t_game *game, char **map);
int		key_handler(int key_code, void *param);
int		get_lenght(char *str);
void	ft_putnbr_fd(int n, int fd);
char	*ft_itoa(int n);
#endif