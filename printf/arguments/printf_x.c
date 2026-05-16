/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdecourt <bdecourt@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 22:12:43 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/05 23:10:09 by bdecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	puthexa(unsigned int nb, char *str)
{
	int	count;

	count = 0;
	if (nb >= 16)
		count += puthexa(nb / 16, str);
	count += printf_c(str[nb % 16]);
	return (count);
}

int	printf_x(unsigned int nb, int arg)
{
	char	*str;

	if (arg == 'x')
		str = "0123456789abcdef";
	else
		str = "0123456789ABCDEF";
	return (puthexa(nb, str));
}
