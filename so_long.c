/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:50:12 by zogrir            #+#    #+#             */
/*   Updated: 2025/01/03 18:17:24 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


int main(int argc, char **argv)
{
	game_vars	vars;
	if (argc <= 1)
	{
		write(1, "error", 5); // you should to update it into perror
		exit(1);
	}
	(void)argv; // ignore the message about unused variable
	map_extention(argv[1]);
	vars.map = map_creation(argv[1]);
}