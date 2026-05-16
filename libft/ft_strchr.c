/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdecourt <baptiste.decourtray@learner.4    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 18:58:37 by bdecourt          #+#    #+#             */
/*   Updated: 2026/04/27 19:12:06 by bdecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			tofind;

	i = 0;
	tofind = (char)c;
	while (s[i])
	{
		if (s[i] == tofind)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == tofind)
		return ((char *) &s[i]);
	return (NULL);
}
