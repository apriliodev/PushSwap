/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machapui <machapui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 22:25:04 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/29 15:45:57 by machapui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	check_arg(const char *str, va_list args, int i, int fd)
{
	int	count;

	count = 0;
	if (str[i] == 'c')
		count += printf_c((char)va_arg(args, int), fd);
	else if (str[i] == 's')
		count += printf_s(va_arg(args, char *), fd);
	else if (str[i] == 'd' || str[i] == 'i')
		count += printf_d(va_arg(args, int), fd);
	else if (str[i] == 'u')
		count += printf_u(va_arg(args, unsigned int), fd);
	else if (str[i] == 'x' || str[i] == 'X')
		count += printf_x(va_arg(args, unsigned int), str[i], fd);
	else if (str[i] == 'p')
		count += printf_p(va_arg(args, void *), fd);
	else if (str[i] == '%')
		count += printf_c('%', fd);
	else if (str[i] == 'f')
		count += print_f((float)va_arg(args, double), fd);
	return (count);
}

int	ft_printf(int fd, const char *input, ...)
{
	va_list	arguments;
	int		i;
	int		count;

	va_start(arguments, input);
	i = 0;
	count = 0;
	while (input[i])
	{
		if (input[i] == '%')
		{
			count += check_arg(input, arguments, ++i, fd);
			if (count < 0)
				return (-1);
		}
		else
		{
			count += printf_c(input[i], fd);
			if (count < 0)
				return (-1);
		}
		i++;
	}
	va_end(arguments);
	return (count);
}
