/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdecourt <bdecourt@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 20:45:20 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/17 22:14:12 by bdecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "printf/ft_printf.h"

int ft_log2(int n)
{
    int bits;
    bits = 0;
    while (n > 0)
    {
        n = n / 2;
        bits++;
    }
    return (bits);
}

void radix_sort(t_stack **stack_a, t_stack **stack_b)
{
    int n;
    int bits;
    int k;
    int i;

    k = 0;
    n = stack_size(*stack_a);
    bits = ft_log2(n);

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