/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machapui <machapui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 13:50:10 by machapui          #+#    #+#             */
/*   Updated: 2026/05/29 14:50:45 by machapui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bench(char *arg, float disorder, t_count *count)
{
	if (ft_strncmp(arg, "--bench", 7) == 0)
	{
		if (disorder)
			ft_printf(2, "[bench] disorder: %f%%\n", disorder * 100);
		else
			ft_printf(2, "[bench] disorder: error\n");
		if (count->flag == 0 || count->flag == 4)
			ft_printf(2, "[bench] strategy: Adaptive / %s\n", count->str);
		else if (count->flag == 1)
			ft_printf(2, "[bench] strategy: Simple / %s\n", count->str);
		else if (count->flag == 2)
			ft_printf(2, "[bench] strategy: Medium / %s\n", count->str);
		else if (count->flag == 3)
			ft_printf(2, "[bench] strategy: Complex / %s\n", count->str);
		ft_printf(2, "[bench] total_ops: %d\n", count->total);
		ft_printf(2, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", count->sa,
			count->sb, count->ss, count->pa, count->pb);
		ft_printf(2, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
			count->ra, count->rb, count->rr, count->rra, count->rrb,
			count->rrr);
	}
}
