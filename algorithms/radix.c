/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machapui <machapui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 20:45:20 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/28 14:08:16 by machapui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include "push_swap.h"

/*RADIX*/
static int	count_max_bits(t_stack *stack)
{
	int	i;
	int	bits;
	int	max_index;

	i = 0;
	bits = 0;
	max_index = stack->index;
	while (stack)
	{
		if (max_index < stack->index)
			max_index = stack->index;
		stack = stack->next;
	}
	while (max_index >> i != 0)
	{
		bits++;
		i++;
	}
	return (bits);
}

static void	handle_small(t_stack **a, int size, t_count *count)
{
	if (size == 1)
		return ;
	if (size == 2 && (*a)->index > (*a)->next->index)
		do_sa(a, count);
	else if (size == 3)
		sort_three(a, count);
}

void	sort_three(t_stack **a, t_count *count)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
	if (first > second && second < third && first < third)
		do_sa(a, count);
	else if (first > second && second > third)
	{
		do_sa(a, count);
		do_rra(a, count);
	}
	else if (first > second && second < third && first > third)
		do_ra(a, count);
	else if (first < second && second > third && first < third)
	{
		do_sa(a, count);
		do_ra(a, count);
	}
	else if (first < second && second > third && first > third)
		do_rra(a, count);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, t_count *count)
{
	int	max_bits;
	int	n;
	int	i;
	int	j;

	n = stack_size(*stack_a);
	if (n <= 3)
		return (handle_small(stack_a, n, count));
	i = 0;
	max_bits = count_max_bits(*stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j < n)
		{
			if ((((*stack_a)->index >> i) & 1) == 0)
				do_pb(stack_a, stack_b, count);
			else
				do_ra(stack_a, count);
			j++;
		}
		while (*stack_b)
			do_pa(stack_a, stack_b, count);
		i++;
	}
}
