/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubblesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdecourt <bdecourt@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 18:10:26 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/17 23:22:33 by bdecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "printf/ft_printf.h"
/*SELECTION SORT*/
/*
int find_pos(t_stack *stack_a, t_stack *node)
{
    int pos;
    pos = 0;
    
    while (stack_a != node)
    {
        pos++;
        stack_a = stack_a->next;
    }
    return (pos);
}
t_stack *find_min(t_stack *stack_a)
{
    t_stack *min;
    t_stack *tmp;
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

void    selection_sort(t_stack **stack_a, t_stack **stack_b)
{
    int     size;
    int     pos;
    t_stack *min;
    
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
        i = 0;
        while (i < size - 1)
        {
            do_rra(stack);
            i++;
        }
        size--;
    }
}
/*
int	main(void)
{
	t_stack	a1; t_stack b1; t_stack c1;
	t_stack	d1; t_stack e1; t_stack f1;
	t_stack	a2; t_stack b2; t_stack c2;
	t_stack	d2; t_stack e2; t_stack f2;
	t_stack	*stack_a1;
	t_stack	*stack_a2;
	t_stack	*stack_b2;
    
	a1.value=5; b1.value=2; c1.value=8;
	d1.value=1; e1.value=9; f1.value=3;
	a1.next=&b1; b1.next=&c1; c1.next=&d1;
	d1.next=&e1; e1.next=&f1; f1.next=NULL;
	a2.value=5; b2.value=2; c2.value=8;
	d2.value=1; e2.value=9; f2.value=3;
	a2.next=&b2; b2.next=&c2; c2.next=&d2;
	d2.next=&e2; e2.next=&f2; f2.next=NULL;
	stack_a1 = &a1;
	stack_a2 = &a2;
	stack_b2 = NULL;
	ft_printf("=== BUBBLE SORT ===\n");
	ft_printf("Avant : %d->%d->%d->%d->%d->%d\n",
    a1.value, b1.value, c1.value, d1.value, e1.value, f1.value);
	bubble_sort(&stack_a1);
	ft_printf("Apres : ");
	while (stack_a1)
	{
		ft_printf("%d -> ", stack_a1->value);
		stack_a1 = stack_a1->next;
	}
	ft_printf("NULL\n\n");
	ft_printf("=== SELECTION SORT ===\n");
	ft_printf("Avant : %d->%d->%d->%d->%d->%d\n",
    a2.value, b2.value, c2.value, d2.value, e2.value, f2.value);
	selection_sort(&stack_a2, &stack_b2);
	ft_printf("Apres : ");
	while (stack_a2)
	{
		ft_printf("%d -> ", stack_a2->value);
		stack_a2 = stack_a2->next;
	}
	ft_printf("NULL\n");
	return (0);
}
*/