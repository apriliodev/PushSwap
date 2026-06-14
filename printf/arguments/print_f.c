/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdecourt <bdecourt@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 15:18:15 by machapui          #+#    #+#             */
/*   Updated: 2026/05/29 15:51:08 by machapui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putfloat(float disorder, int fd)
{
	long	avantvir;
	long	apresvir;

	if (disorder < 0)
	{
		disorder = -disorder;
		printf_c('-', fd);
	}
	avantvir = (long)disorder;
	printf_u(avantvir, fd);
	printf_c('.', fd);
	disorder = disorder - (float)avantvir;
	disorder = disorder * 100;
	apresvir = (long)disorder;
	if (apresvir < 10)
		printf_c('0', fd);
	return (printf_u(apresvir, fd));
}

int	print_f(float disorder, int fd)
{
	return (ft_putfloat(disorder, fd));
}
