/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdecourt <bdecourt@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 20:29:17 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/17 01:27:42 by bdecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

/*Pas d'explication ici tu peux capter avec celles dans rrotate.c*/

static void rotating(t_stack **stack)
{
    t_stack *tmp;
    t_stack *tail;
    
    tmp = *stack;
    *stack = (*stack)->next;
    tail = ft_lstlast(*stack);
    tmp->next = NULL;
    tail->next = tmp;
}

void do_ra(t_stack **stack_a)
{
    rotating(stack_a);
    ft_printf("%s", "ra\n");    
}

void do_rb(t_stack **stack_b)
{
    rotating(stack_b);
    ft_printf("%s", "rb\n");
}

void do_rr(t_stack **stack_a, t_stack **stack_b)
{
    rotating(stack_a);
    rotating(stack_b);
    ft_printf("%s", "rr\n");
}