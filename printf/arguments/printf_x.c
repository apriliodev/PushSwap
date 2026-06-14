/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machapui <machapui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 22:12:43 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/29 15:52:50 by machapui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	puthexa(unsigned int nb, char *str, int fd)
{
	int	count;

	count = 0;
	if (nb >= 16)
		count += puthexa(nb / 16, str, fd);
	count += printf_c(str[nb % 16], fd);
	return (count);
}

int	printf_x(unsigned int nb, int arg, int fd)
{
	char	*str;

	if (arg == 'x')
		str = "0123456789abcdef";
	else
		str = "0123456789ABCDEF";
	return (puthexa(nb, str, fd));
}
