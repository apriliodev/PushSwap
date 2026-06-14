/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machapui <machapui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 01:14:45 by bdecourt          #+#    #+#             */
/*   Updated: 2026/06/01 11:32:33 by machapui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf/ft_printf.h"
#include "push_swap.h"

t_stack	*before_tail(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

static void	r_rotating(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*btail;

	if (!*stack || !(*stack)->next)
		return ;
	tail = stack_last(*stack);
	btail = before_tail(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	btail->next = NULL;
}

void	do_rra(t_stack **stack_a, t_count *count)
{
	r_rotating(stack_a);
	ft_printf(1, "%s", "rra\n");
	count->rra++;
	count->total++;
}

void	do_rrb(t_stack **stack_b, t_count *count)
{
	r_rotating(stack_b);
	ft_printf(1, "%s", "rrb\n");
	count->rrb++;
	count->total++;
}

void	do_rrr(t_stack **stack_a, t_stack **stack_b, t_count *count)
{
	r_rotating(stack_a);
	r_rotating(stack_b);
	ft_printf(1, "%s", "rrr\n");
	count->rrr++;
	count->total++;
}
