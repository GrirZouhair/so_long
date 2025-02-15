/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:13:05 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/15 12:24:20 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		char **map = read_map(av[1]);
		if(validate_map(map))
		{
			printf("done");
		}else{
			printf("not done");
		}
	}else
	{
	ft_putstr_fd("\033[1;31m🛑ERROR: few args\033[0m\n", 2);
	exit(1);
		
	}
}