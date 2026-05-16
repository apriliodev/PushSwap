/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdecourt <bdecourt@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 22:31:09 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/05 23:09:03 by bdecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *input, ...);
int	printf_c(char c);
int	printf_d(int nb);
int	printf_p(void *ptr);
int	printf_s(char *str);
int	printf_u(unsigned int nbr);
int	printf_x(unsigned int nb, int arg);

#endif