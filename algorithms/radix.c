/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdecourt <bdecourt@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 20:45:20 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/18 14:33:38 by bdecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include "push_swap.h"

/*RADIX*/
/*
int	ft_log2(int n)
{
	int	bits;

	bits = 0;
	while (n > 0)
	{
		n = n / 2;
		bits++;
	}
	return (bits);
}
static void	handle_small(t_stack **a, int size)
{
	if (size == 2 && (*a)->index > (*a)->next->index)
	do_sa(a);
	else if (size == 3)
	sort_three(a);
}

static void	radix_msd(t_stack **a, t_stack **b, int size, int bit)
{
	int	pushed;
	int	i;

	if (size <= 1 || bit < 0)
	return ;
	if (size <= 3)
	return (handle_small(a, size));
	pushed = 0;
	i = 0;
	while (i < size)
	{
		if (((*a)->index >> bit) & 1)
		{
			do_pb(a, b);
			pushed++;
		}
		else
		do_ra(a);
		i++;
	}
	radix_msd(a, b, size - pushed, bit - 1);
	radix_msd(b, a, pushed, bit - 1);
	while (pushed-- > 0)
	do_pa(a, b);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	n;
	int	bits;

	n = stack_size(*stack_a);
	bits = ft_log2(n) - 1;
	radix_msd(stack_a, stack_b, n, bits);
}

*/
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

static void	handle_small(t_stack **a, int size)
{
	if (size == 1)
		return ;
	if (size == 2 && (*a)->index > (*a)->next->index)
		do_sa(a);
	else if (size == 3)
		sort_three(a);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	max_bits;
	int	n;
	int	i;
	int	j;

	n = stack_size(*stack_a);
	if (n <= 3)
		return (handle_small(stack_a, n));
	i = 0;
	max_bits = count_max_bits(*stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j < n)
		{
			if ((((*stack_a)->index >> i) & 1) == 0)
				do_pb(stack_a, stack_b);
			else
				do_ra(stack_a);
			j++;
		}
		while (*stack_b)
			do_pa(stack_a, stack_b);
		i++;
	}
}

/*
void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	n;
	int	bits;
	int	k;
	int	i;

	k = 0;
	n = stack_size(*stack_a);
	bits = ft_log2(n);
	ft_printf("n=%d bits=%d index[0]=%d\n", n, bits, (*stack_a)->index);
	while (k < bits)
	{
		i = 0;
		while(i < n)
		{
			if ((((*stack_a)->index >> k) & 1) == 0)
			do_pb(stack_a, stack_b);
			else
			do_ra(stack_a);
			i++;
		}
		while (*stack_b)
		do_pa(stack_a, stack_b);
		k++;
	}
}
*/
