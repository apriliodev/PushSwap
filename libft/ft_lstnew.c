/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdecourt <baptiste.decourtray@learner.4    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 23:40:52 by bdecourt          #+#    #+#             */
/*   Updated: 2026/04/28 13:51:54 by bdecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*array;

	array = (t_list *)malloc(sizeof(t_list) * 1);
	if (!array)
		return (NULL);
	array->content = content;
	array->next = NULL;
	return (array);
}
