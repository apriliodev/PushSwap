/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilspushswap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdecourt <bdecourt@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:23:42 by machapui          #+#    #+#             */
/*   Updated: 2026/06/14 23:53:14 by bdecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	error(t_stack **a)
// {
// 	free_stack(a);
// 	write(2, "Error\n", 6);
// }
t_count	zero_for_touch(t_count count)
{
	count.sa = 0;
	count.sb = 0;
	count.ss = 0;
	count.pa = 0;
	count.pb = 0;
	count.ra = 0;
	count.rb = 0;
	count.rr = 0;
	count.rra = 0;
	count.rrb = 0;
	count.rrr = 0;
	count.total = 0;
	count.dissorder = 0;
	count.bench = 0;
	return (count);
}

int	check_bench(char **argv)
{
	if (ft_strncmp(argv[1], "--bench", 7) == 0)
		return (0);
	return (1);
}

int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

// int	ft_flm(t_stack **a)
// {
// 	if (!a)
// 	{
// 		error(&a);
// 		return (1);
// 	}
// 	return (0);
// }
