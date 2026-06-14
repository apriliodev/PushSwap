/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machapui <machapui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 23:27:03 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/27 11:33:43 by machapui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_putnbr(int nb, int fd)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
		count += write(fd, "-2147483648", 11);
	else if (nb < 0)
	{
		count += write(fd, "-", 1);
		nb = -nb;
		count += ft_putnbr(nb, fd);
	}
	else
	{
		if (nb >= 10)
		{
			count += ft_putnbr(nb / 10, fd);
			count += ft_putnbr(nb % 10, fd);
		}
		else
			count += printf_c(nb + 48, fd);
	}
	return (count);
}

int	printf_d(int nb, int fd)
{
	int	count;

	count = 0;
	count += ft_putnbr(nb, fd);
	if (count < 0)
		return (-1);
	return (count);
}
