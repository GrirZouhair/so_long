/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:27:35 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/24 08:11:49 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

static int	ft_len(int n)
{
	long int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
	}
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*ft_char(char *s, unsigned int number, long int len, int sign)
{
	while (len > 0)
	{
		s[len - 1] = (number % 10) + '0';
		number /= 10;
		len--;
	}
	if (sign)
	{
		s[0] = '-';
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char			*s;
	long int		len;
	unsigned int	number;
	int				sign;

	n -= 1;
	number = 0;
	sign = 0;
	len = ft_len(n);
	s = (char *)malloc(len + 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (n == 0)
	{
		s[0] = '0';
		return (s);
	}
	else
		number = n;
	s = ft_char(s, number, len, sign);
	return (s);
}
