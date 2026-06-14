/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunkbased.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machapui <machapui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 19:22:20 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/28 14:23:06 by machapui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include "push_swap.h"

void	push_chunk(t_arrgg rr)
{
	int	i;
	int	n;

	i = 0;
	n = stack_size(*rr.stack_a);
	while (i < n)
	{
		if ((*rr.stack_a)->index >= rr.min && (*rr.stack_a)->index < rr.max)
			do_pb(rr.stack_a, rr.stack_b, rr.count);
		else
			do_ra(rr.stack_a, rr.count);
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

void	bring_back(t_stack **stack_a, t_stack **stack_b, t_count *count)
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
				do_rb(stack_b, count);
		}
		else
		{
			while ((*stack_b)->index != max->index)
				do_rrb(stack_b, count);
		}
		do_pa(stack_a, stack_b, count);
	}
}

void	chunk_sort(t_stack **stack_a, t_stack **stack_b, t_count *count)
{
	int		n;
	int		chunksize;
	int		chunk;
	t_arrgg	rr;

	chunk = 0;
	n = stack_size(*stack_a);
	chunksize = get_chunk_size(*stack_a);
	assign_index(*stack_a);
	rr.stack_a = stack_a;
	rr.stack_b = stack_b;
	rr.count = count;
	while (chunk * chunksize < n)
	{
		rr.min = chunk * chunksize;
		rr.max = (chunk + 1) * chunksize;
		push_chunk(rr);
		chunk++;
	}
	bring_back(stack_a, stack_b, count);
}
