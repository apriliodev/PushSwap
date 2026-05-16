/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdecourt <bdecourt@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 01:42:57 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/17 01:48:16 by bdecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"
#include "push_swap.h"

void	pushing(t_stack **res, t_stack **des)
{
	t_stack *tmp;

	if (*res == NULL)
		return ;
	tmp = (*res)->next;
	(*res)->next = *des;
	*des = *res;
	*res = tmp;
}

void do_pa(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_a, stack_b);
    ft_printf("%s", "pa\n");
}

void do_pb(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_b, stack_a);
    ft_printf("%s", "pb\n");
}