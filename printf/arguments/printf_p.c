/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdecourt <bdecourt@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 22:22:24 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/05 23:11:29 by bdecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putptrhexa(unsigned long nb)
{
	int		count;
	char	c;

	count = 0;
	if (nb >= 16)
		count += putptrhexa(nb / 16);
	if (nb % 16 < 10)
		c = (nb % 16) + '0';
	else
		c = (nb % 16) - 10 + 'a';
	count += write(1, &c, 1);
	return (count);
}

int	printf_p(void *ptr)
{
	unsigned long	adr;
	int				count;

	count = 0;
	if (!ptr)
	{
		count += write(1, "(nil)", 5);
		return (count);
	}
	adr = (unsigned long)ptr;
	count += write(1, "0x", 2);
	count += putptrhexa(adr);
	return (count);
}
