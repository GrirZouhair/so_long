/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_extention.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:49:38 by zogrir            #+#    #+#             */
/*   Updated: 2025/01/03 17:42:14 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include<stdio.h>

void map_extention(char *file_extention)
{
	size_t len;
	size_t ext_len;

	len = ft_strlen(file_extention);
	ext_len = ft_strlen(".ber");
	if (len >= ext_len && ft_strncmp(file_extention + len - ext_len, ".ber", len) == 0)
		return ;
	printf("\033[1;31m🛑ERROR: file is not valid\033[0m\n");
    exit(1);
}



// int main()
// {
//     char s[] = "example.beer";
//    	map_extention(s);
//     return 0;
// }