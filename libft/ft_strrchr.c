/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdecourt <baptiste.decourtray@learner.4    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 23:32:53 by bdecourt          #+#    #+#             */
/*   Updated: 2026/04/27 19:31:30 by bdecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*res;
	char			tofind;

	i = 0;
	res = NULL;
	tofind = (char)c;
	while (s[i])
	{
		if (s[i] == tofind)
			res = ((char *) &s[i]);
		i++;
	}
	if (s[i] == tofind)
		res = ((char *) &s[i]);
	return (res);
}
