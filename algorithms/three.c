/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdecourt <bdecourt@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 00:18:29 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/18 14:37:33 by bdecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
	if (first > second && second < third && first < third)
		do_sa(a);
	else if (first > second && second > third)
	{
		do_sa(a);
		do_rra(a);
	}
	else if (first > second && second < third && first > third)
		do_ra(a);
	else if (first < second && second > third && first < third)
	{
		do_sa(a);
		do_ra(a);
	}
	else if (first < second && second > third && first > third)
		do_rra(a);
}
