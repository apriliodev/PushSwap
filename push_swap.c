/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdecourt <bdecourt@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 20:31:20 by bdecourt          #+#    #+#             */
/*   Updated: 2026/06/14 23:52:51 by bdecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*sort(t_stack **a, t_stack **b, t_count *count)
{
	float	disorder;

	assign_index(*a);
	disorder = compute_disorder(*a);
	if (disorder < 0.2)
	{
		selection_sort(a, b, count);
		return ("O(n2)");
	}
	else if (disorder < 0.5)
	{
		chunk_sort(a, b, count);
		return ("O(n√n)");
	}
	radix_sort(a, b, count);
	return ("O(n log n)");
}

static int	get_flag(char *arg)
{
	if (ft_strncmp(arg, "--simple", 8) == 0)
		return (1);
	if (ft_strncmp(arg, "--medium", 8) == 0)
		return (2);
	if (ft_strncmp(arg, "--complex", 9) == 0)
		return (3);
	if (ft_strncmp(arg, "--adaptive", 10) == 0)
		return (4);
	return (0);
}

static void	error(t_stack **a)
{
	free_stack(a);
	write(2, "Error\n", 6);
}

static char	*run_sort(t_stack **a, t_stack **b, int flag, t_count *count)
{
	assign_index(*a);
	if (is_sorted(*a))
		return ("O(1)");
	if (flag == 1)
	{
		selection_sort(a, b, count);
		return ("O(n2)");
	}
	else if (flag == 2)
	{
		chunk_sort(a, b, count);
		return ("O(n√n)");
	}
	else if (flag == 3)
	{
		radix_sort(a, b, count);
		return ("O(n log n)");
	}
	return (sort(a, b, count));
}

int	main(int argc, char **argv)
{
	t_arg	ss;

	if (argc == 1)
		return (0);
	ss.count = zero_for_touch(ss.count);
	ss.count.bench = (check_bench(argv) == 0);
	ss.flag = get_flag(argv[1 + (check_bench(argv) == 0)]);
	ss.start = 1 + (ss.flag > 0) + (check_bench(argv) == 0);
	ss.stack_a = create_stack(argc, argv, ss.start);
	if (!ss.stack_a)
		return (error(&ss.stack_a), 1);
	ss.stack_b = NULL;
	ss.disbench = compute_disorder(ss.stack_a);
	ss.str = run_sort(&ss.stack_a, &ss.stack_b, ss.flag, &ss.count);
	ss.count.str = ss.str;
	free_stack(&ss.stack_a);
	if (check_bench(argv) == 0)
		ft_bench(argv[1], ss.disbench, &ss.count);
	return (0);
}
