/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_extention.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 04:37:16 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/07 06:46:26 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void map_extention(char *file_extention)
{
	size_t len;
	size_t ext_len;

	len = ft_strlen(file_extention);
	ext_len = ft_strlen(".ber");
	if (len >= ext_len && ft_strncmp(file_extention + len - ext_len, ".ber", ext_len) == 0)
		return ;
	ft_putstr_fd("\033[1;31m🛑ERROR: Adding to list failed\033[0m\n", 2);
    exit(1);
}
#include<stdio.h>
int main()
{
    char s[] = "example.beer";
   	map_extention(s);
    return 0;
}