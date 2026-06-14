/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machapui <machapui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 22:10:34 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/27 11:33:43 by machapui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int nb, int fd)
{
	int	count;

	count = 0;
	if (nb >= 10)
	{
		count += ft_putunbr(nb / 10, fd);
		count += ft_putunbr(nb % 10, fd);
	}
	else
		count += printf_c(nb + 48, fd);
	return (count);
}

int	printf_u(unsigned int nbr, int fd)
{
	return (ft_putunbr(nbr, fd));
}
