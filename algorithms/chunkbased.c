/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunkbased.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdecourt <bdecourt@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 19:22:20 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/17 19:53:11 by bdecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunk(t_stack **stack_a, t_stack **stack_b, int min, int max)
{
    int i;
    int n;

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

t_stack     *find_max_b(t_stack *b)
{
    t_stack *max;
    t_stack *tmp;

    max = b;
    tmp = b;
    while (tmp)
    {
        if(tmp->index > max->index)
            max = tmp;
        tmp = tmp->next;
    }
    return (max);
}