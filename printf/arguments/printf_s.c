/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machapui <machapui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 22:06:37 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/27 11:33:43 by machapui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_s(char *str, int fd)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (!str)
	{
		count += write(fd, "(null)", 6);
		return (count);
	}
	while (str[i])
	{
		count += write(fd, &str[i], 1);
		i++;
	}
	return (count);
}
