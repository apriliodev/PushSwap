/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubblesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdecourt <bdecourt@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 18:10:26 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/17 19:01:46 by bdecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void    bubble_sort(t_stack **stack)
{
    int size;
    int i;

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
    }
}

#include <stdio.h>

int	main(void)
{
	t_stack	a;
	t_stack	b;
	t_stack	c;
	t_stack	d;

	a.value = 3;
	b.value = 1;
	c.value = 4;
	d.value = 2;
	a.index = 0;
	b.index = 1;
	c.index = 2;
	d.index = 3;
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = NULL;
	printf("Avant : ");
	printf("%d -> %d -> %d -> %d\n", a.value, b.value, c.value, d.value);
	printf("Disorder: %.2f\n", compute_disorder(&a));
	t_stack *stack;
    stack = &a;
    bubble_sort(&stack);
	printf("Apres  : ");
	printf("%d -> %d -> %d -> %d\n", a.value, b.value, c.value, d.value);
	printf("Disorder: %.2f\n", compute_disorder(&a));
	return (0);
}