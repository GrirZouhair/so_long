/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:45:39 by zogrir            #+#    #+#             */
/*   Updated: 2025/02/24 08:11:45 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long_bonus.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = n;
	if (fd >= 0)
	{
		if (nbr < 0)
		{
			ft_putchar_fd('-', fd);
			nbr *= -1;
		}
		if (nbr > 9)
		{
			ft_putnbr_fd((nbr / 10), fd);
			ft_putchar_fd((nbr % 10) + '0', fd);
		}
		else
		{
			ft_putchar_fd((nbr % 10) + '0', fd);
		}
	}
}
