/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdecourt <bdecourt@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 20:45:20 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/18 00:19:57 by bdecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include "push_swap.h"

/*RADIX*/
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
/*
int	main(void)
{
	t_stack	a;
	t_stack	b;
	t_stack	c;
	t_stack	d;
	t_stack	e;
	t_stack	f;
	t_stack	g;
	t_stack	h;
	t_stack	i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	a.value = 5; b.value = 2; c.value = 8;
	d.value = 1; e.value = 9; f.value = 3;
	g.value = 7; h.value = 4; i.value = 6;
	a.next = &b; b.next = &c; c.next = &d;
	d.next = &e; e.next = &f; f.next = &g;
	g.next = &h; h.next = &i; i.next = NULL;
	stack_a = &a;
	stack_b = NULL;
	assign_index(stack_a);
	ft_printf("Avant : ");
	ft_printf("%d->%d->%d->%d->%d->%d->%d->%d->%d\n",
	a.value, b.value, c.value, d.value, e.value,
	f.value, g.value, h.value, i.value);
	radix_sort(&stack_a, &stack_b);
	ft_printf("Apres : ");
	while (stack_a)
	{
		ft_printf("%d -> ", stack_a->value);
		stack_a = stack_a->next;
	}
	ft_printf("NULL\n");
	return (0);
}
*/