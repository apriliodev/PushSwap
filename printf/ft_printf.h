/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machapui <machapui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 22:31:09 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/27 11:33:43 by machapui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(int fd, const char *input, ...);
int	printf_c(char c, int fd);
int	printf_d(int nb, int fd);
int	printf_p(void *ptr, int fd);
int	printf_s(char *str, int fd);
int	printf_u(unsigned int nbr, int fd);
int	printf_x(unsigned int nb, int arg, int fd);
int	print_f(float disorder, int fd);

#endif