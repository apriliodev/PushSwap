/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubblesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdecourt <bdecourt@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 18:10:26 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/18 14:32:43 by bdecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "push_swap.h"

/*SELECTION SORT*/
/*
int	find_pos(t_stack *stack_a, t_stack *node)
{
	int	pos;

	pos = 0;
	while (stack_a != node)
	{
		pos++;
		stack_a = stack_a->next;
	}
	return (pos);
}
t_stack	*find_min(t_stack *stack_a)
{
	t_stack	*min;
	t_stack	*tmp;

	min = stack_a;
	tmp = stack_a;
	while (tmp)
	{
		if (tmp->value < min->value)
		min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

void	selection_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		size;
	int		pos;
	t_stack	*min;

	size = stack_size(*stack_a);
	while (size > 1)
	{
		min = find_min(*stack_a);
		pos = find_pos(*stack_a, min);
		if (pos <= size / 2)
		{
			while (pos-- > 0)
			do_ra(stack_a);
		}
		else
		{
			pos = size - pos;
			while (pos-- > 0)
			do_rra(stack_a);
		}
		do_pb(stack_a, stack_b);
		size--;
	}
	while (*stack_b)
	do_pa(stack_a, stack_b);
}
*/

/*BUBBLE SORT*/
void	bubble_sort(t_stack **stack)
{
	int	size;
	int	i;

	size = stack_size(*stack);
	while (compute_disorder(*stack) != 0)
	{
		i = 0;
		while (i < size - 1)
		{
			if ((*stack)->value > (*stack)->next->value)
				do_sa(stack);
			do_ra(stack);
			i++;
		}
		i = 0;
		while (i < size - 1)
		{
			do_rra(stack);
			i++;
		}
		size--;
	}
}
