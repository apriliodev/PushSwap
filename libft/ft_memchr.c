/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdecourt <baptiste.decourtray@learner.4    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 22:53:09 by bdecourt          #+#    #+#             */
/*   Updated: 2026/04/27 19:27:58 by bdecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	occ;

	i = 0;
	str = (unsigned char *)s;
	occ = (unsigned char) c;
	while (i < n)
	{
		if (str[i] == occ)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
