/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubblesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdecourt <bdecourt@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 18:10:26 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/17 19:20:26 by bdecourt         ###   ########.fr       */
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
        i = 0;
        while (i < size - 1)
        {
            do_rra(stack);
            i++;
        }
        size--;
    }
}
