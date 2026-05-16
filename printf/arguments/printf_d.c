/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdecourt <bdecourt@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 23:27:03 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/05 23:10:27 by bdecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
		count += write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		count += write(1, "-", 1);
		nb = -nb;
		count += ft_putnbr(nb);
	}
	else
	{
		if (nb >= 10)
		{
			count += ft_putnbr(nb / 10);
			count += ft_putnbr(nb % 10);
		}
		else
			count += printf_c(nb + 48);
	}
	return (count);
}

int	printf_d(int nb)
{
	int	count;

	count = 0;
	count += ft_putnbr(nb);
	if (count < 0)
		return (-1);
	return (count);
}
