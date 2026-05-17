/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdecourt <bdecourt@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 20:20:23 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/17 19:00:57 by bdecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "push_swap.h"

static void	swaping(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

void	do_sa(t_stack **stack_a)
{
	swaping(*stack_a);
	ft_printf("%s", "sa\n");
}

void	do_sb(t_stack **stack_b)
{
	swaping(*stack_b);
	ft_printf("%s", "sb\n");
}

void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	swaping(*stack_a);
	swaping(*stack_b);
	ft_printf("%s", "ss\n");
}