/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machapui <machapui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 20:29:17 by bdecourt          #+#    #+#             */
/*   Updated: 2026/06/01 11:32:16 by machapui         ###   ########.fr       */
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

void	do_ra(t_stack **stack_a, t_count *count)
{
	rotating(stack_a);
	ft_printf(1, "%s", "ra\n");
	count->ra++;
	count->total++;
}

void	do_rb(t_stack **stack_b, t_count *count)
{
	rotating(stack_b);
	ft_printf(1, "%s", "rb\n");
	count->rb++;
	count->total++;
}

void	do_rr(t_stack **stack_a, t_stack **stack_b, t_count *count)
{
	rotating(stack_a);
	rotating(stack_b);
	ft_printf(1, "%s", "rr\n");
	count->rb++;
	count->total++;
}
