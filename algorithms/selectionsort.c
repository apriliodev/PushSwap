/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selectionsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machapui <machapui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 18:10:26 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/29 15:22:37 by machapui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "../push_swap.h"

static	int	find_min_pos(t_stack *stack)
{
	int	pos;
	int	min_pos;
	int	min_val;

	pos = 0;
	min_pos = 0;
	min_val = stack->value;
	while (stack)
	{
		if (stack->value < min_val)
		{
			min_val = stack->value;
			min_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (min_pos);
}

void	selection_sort(t_stack **a, t_stack **b, t_count *count)
{
	count->size = stack_size(*a);
	while (count->size > 0)
	{
		count->pos = find_min_pos(*a);
		if (count->pos <= count->size / 2)
		{
			while (count->pos-- > 0)
				do_ra(a, count);
		}
		else
		{
			count->pos = count->size - count->pos;
			while (count->pos-- > 0)
				do_rra(a, count);
		}
		do_pb(a, b, count);
		count->size--;
	}
	count->size = stack_size(*b);
	while (count->size-- > 0)
		do_rrb(b, count);
	while (*b)
		do_pa(a, b, count);
}
