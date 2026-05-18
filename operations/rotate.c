/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdecourt <bdecourt@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 20:29:17 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/18 14:36:01 by bdecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "push_swap.h"

/*Pas d'explication ici tu peux capter avec celles dans rrotate.c*/

static void	rotating(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tail = stack_last(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

void	do_ra(t_stack **stack_a)
{
	rotating(stack_a);
	ft_printf("%s", "ra\n");
}

void	do_rb(t_stack **stack_b)
{
	rotating(stack_b);
	ft_printf("%s", "rb\n");
}

void	do_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotating(stack_a);
	rotating(stack_b);
	ft_printf("%s", "rr\n");
}
