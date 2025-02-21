/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 09:12:48 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/21 00:48:40 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*destination;
	unsigned char		*source;
	unsigned int		i;

	i = 0;
	destination = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (!dst || !src)
		return (NULL);
	while (n > 0)
	{
		destination[i] = source[i];
		i++;
		n--;
	}
	return (dst);
}



static int	calculate_length(int size, char **strs, int i)
{
	int	len;

	if (i == size)
		return (0);
	len = ft_strlen(strs[i]);
	if (i < size - 1)
		len += 1;
	return (len + calculate_length(size, strs, i + 1));
}

static void	ft_merge(int size, char **strs, char *args)
{
	int	i;
	int	pos;
	int	len;

	pos = 0;
	i = 0;
	if (size == i)
		return ;
	while (i < size)
	{
		len = ft_strlen(strs[i]);
		ft_memcpy(args + pos, strs[i], len);
		pos += len;
		if (i < size - 1)
		{
			args[pos] = ' ';
			(pos)++;
		}
		i++;
	}
	args[pos] = '\0';
}

char	*ft_join(int size, char **strs)
{
	char	*args;
	int		total_len;

	total_len = 0;
	if (size <= 0)
	{
		args = malloc(1);
		args[0] = '\0';
		return (args);
	}
	total_len = calculate_length(size, strs, 0);
	args = malloc(total_len + 1);
	if (!args)
		return (free(args), NULL);
	ft_merge(size, strs, args);
	return (args);
}
