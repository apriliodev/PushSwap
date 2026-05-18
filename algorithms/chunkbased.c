/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunkbased.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdecourt <bdecourt@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 19:22:20 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/18 14:38:15 by bdecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include "push_swap.h"

void	push_chunk(t_stack **stack_a, t_stack **stack_b, int min, int max)
{
	int	i;
	int	n;

	i = 0;
	n = stack_size(*stack_a);
	while (i < n)
	{
		if ((*stack_a)->index >= min && (*stack_a)->index < max)
			do_pb(stack_a, stack_b);
		else
			do_ra(stack_a);
		i++;
	}
}

t_stack	*find_max_b(t_stack *b)
{
	t_stack	*max;
	t_stack	*tmp;

	max = b;
	tmp = b;
	while (tmp)
	{
		if (tmp->index > max->index)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

int	find_pos(t_stack *stack, t_stack *node)
{
	int	pos;

	pos = 0;
	while (stack != node)
	{
		pos++;
		stack = stack->next;
	}
	return (pos);
}

void	bring_back(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*max;
	int		pos;
	int		size;

	while (*stack_b)
	{
		max = find_max_b(*stack_b);
		pos = find_pos(*stack_b, max);
		size = stack_size(*stack_b);
		if (pos <= size / 2)
		{
			while ((*stack_b)->index != max->index)
				do_rb(stack_b);
		}
		else
		{
			while ((*stack_b)->index != max->index)
				do_rrb(stack_b);
		}
		do_pa(stack_a, stack_b);
	}
}

void	chunk_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	n;
	int	chunksize;
	int	chunk;

	chunk = 0;
	n = stack_size(*stack_a);
	chunksize = get_chunk_size(*stack_a);
	assign_index(*stack_a);
	while (chunk * chunksize < n)
	{
		push_chunk(stack_a, stack_b, chunk * chunksize, (chunk + 1)
			* chunksize);
		chunk++;
	}
	bring_back(stack_a, stack_b);
}
