/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdecourt <bdecourt@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 18:58:49 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/18 14:38:39 by bdecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	ft_sqrt(int n)
{
	int	i;

	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

int	get_chunk_size(t_stack *stack)
{
	int	n;
	int	sqrtn;

	n = stack_size(stack);
	sqrtn = ft_sqrt(n);
	return (n / sqrtn);
}

void	assign_index(t_stack *stack)
{
	t_stack	*i;
	t_stack	*j;
	int		count;

	i = stack;
	while (i)
	{
		count = 0;
		j = stack;
		while (j)
		{
			if (j->value < i->value)
				count++;
			j = j->next;
		}
		i->index = count;
		i = i->next;
	}
}
