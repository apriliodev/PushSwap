/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machapui <machapui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 22:22:24 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/27 11:33:43 by machapui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putptrhexa(unsigned long nb, int fd)
{
	int		count;
	char	c;

	count = 0;
	if (nb >= 16)
		count += putptrhexa(nb / 16, fd);
	if (nb % 16 < 10)
		c = (nb % 16) + '0';
	else
		c = (nb % 16) - 10 + 'a';
	count += write(fd, &c, 1);
	return (count);
}

int	printf_p(void *ptr, int fd)
{
	unsigned long	adr;
	int				count;

	count = 0;
	if (!ptr)
	{
		count += write(fd, "(nil)", 5);
		return (count);
	}
	adr = (unsigned long)ptr;
	count += write(fd, "0x", 2);
	count += putptrhexa(adr, fd);
	return (count);
}
