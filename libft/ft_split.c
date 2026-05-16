/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdecourt <baptiste.decourtray@learner.4    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 23:39:35 by bdecourt          #+#    #+#             */
/*   Updated: 2026/04/27 18:50:47 by bdecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != 0)
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			count++;
		i++;
	}
	return (count);
}

static int	sep_word(char **result, char const *s, char c, int word)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s[j])
	{
		if (s[j] == c || s[j] == 0)
			i = j + 1;
		if (s[j] != c && (s[j + 1] == c || s[j + 1] == 0))
		{
			result[word] = malloc(sizeof(char) * (j - i + 2));
			if (!result[word])
			{
				while (word++)
					free(result[word]);
				return (0);
			}
			ft_strlcpy(result[word], (s + i), j - i + 2);
			word++;
		}
		j++;
	}
	result[word] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!result)
		return (NULL);
	if (!sep_word(result, s, c, 0))
		return (NULL);
	return (result);
}
