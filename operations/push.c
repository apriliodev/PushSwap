/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machapui <machapui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 01:42:57 by bdecourt          #+#    #+#             */
/*   Updated: 2026/06/01 11:32:00 by machapui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf/ft_printf.h"
#include "push_swap.h"

void	pushing(t_stack **res, t_stack **des)
{
	t_stack	*tmp;

	if (*res == NULL)
		return ;
	tmp = (*res)->next;
	(*res)->next = *des;
	*des = *res;
	*res = tmp;
}

void	do_pa(t_stack **stack_a, t_stack **stack_b, t_count *count)
{
	pushing(stack_b, stack_a);
	ft_printf(1, "%s", "pa\n");
	count->pa++;
	count->total++;
}

void	do_pb(t_stack **stack_a, t_stack **stack_b, t_count *count)
{
	pushing(stack_a, stack_b);
	ft_printf(1, "%s", "pb\n");
	count->pb++;
	count->total++;
}
