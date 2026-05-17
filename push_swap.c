/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdecourt <bdecourt@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 20:31:20 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/17 23:34:24 by bdecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort(t_stack **a, t_stack **b)
{
    float   disorder;

    assign_index(*a);
    disorder = compute_disorder(*a);
    if (disorder < 0.2)
        bubble_sort(a);
    else if (disorder < 0.5)
        chunk_sort(a, b);
    else
        radix_sort(a, b);
}