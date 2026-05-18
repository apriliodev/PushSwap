/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdecourt <bdecourt@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 18:24:36 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/18 13:41:49 by bdecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
 /*
 float   compute_disorder(t_stack *stack_a)
 {
    t_stack *i;
    t_stack *j;
    int     mistakes;
    int     total_pairs;
    
    mistakes = 0;
    total_pairs = 0;
    i = stack_a;
    while (i)
    {
        j = i->next;
        while (j)
        {
            total_pairs++;
            if (i->value > j->value)
            mistakes++;
            j = j->next;
        }
        i = i->next;
    }
    if (total_pairs == 0)
    return (0.0f);
    return ((float)mistakes / total_pairs);
}
*/
float    compute_disorder(t_stack *stack)
{
    float    mistakes;
    float    total_pairs;
    int        lstsize;

    lstsize = stack_size(stack);
    if (lstsize <= 1)
        return (0);
    total_pairs = lstsize - 1;
    mistakes = 0;
    while (stack->next)
    {
        if ((stack->value) > (stack->next->value))
            mistakes++;
        stack = stack->next;
    }
    return (mistakes / total_pairs);
}