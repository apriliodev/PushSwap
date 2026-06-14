/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machapui <machapui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 20:20:23 by bdecourt          #+#    #+#             */
/*   Updated: 2026/06/01 11:32:51 by machapui         ###   ########.fr       */
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

void	do_sa(t_stack **stack_a, t_count *count)
{
	swaping(*stack_a);
	ft_printf(1, "%s", "sa\n");
	count->sa++;
	count->total++;
}

void	do_sb(t_stack **stack_b, t_count *count)
{
	swaping(*stack_b);
	ft_printf(1, "%s", "sb\n");
	count->sb++;
	count->total++;
}

void	do_ss(t_stack **stack_a, t_stack **stack_b, t_count *count)
{
	swaping(*stack_a);
	swaping(*stack_b);
	ft_printf(1, "%s", "ss\n");
	count->ss++;
	count->total++;
}
