/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machapui <machapui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 18:24:36 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/27 09:14:01 by machapui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_stack *stack)
{
	float	mistakes;
	float	total_pairs;
	int		lstsize;

	lstsize = stack_size(stack);
	if (lstsize <= 1)
		return (0);
	total_pairs = lstsize - 1;
	mistakes = 0;
	while (stack->next)
	{
		if ((stack->value) > (stack->next->value))
			mistakes++;
		stack = stack->next;
	}
	return (mistakes / total_pairs);
}
