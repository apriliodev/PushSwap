/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdecourt <bdecourt@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 20:31:20 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/18 14:00:30 by bdecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort(t_stack **a, t_stack **b)
{
    float   disorder;

    assign_index(*a);
    disorder = compute_disorder(*a);
    if (disorder < 0.2)
        bubble_sort(a);
    else if (disorder < 0.5)
        chunk_sort(a, b);
    else
        radix_sort(a, b);
}

static void	error(t_stack **a)
{
	free_stack(a);
    write(2, "Error\n", 6);
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

static void	run_sort(t_stack **a, t_stack **b, int flag)
{
	assign_index(*a);
	if (flag == 1)
		bubble_sort(a);
	else if (flag == 2)
		chunk_sort(a, b);
	else if (flag == 3)
		radix_sort(a, b);
	else
		sort(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		flag;
	int		start;

	if (argc == 1)
		return (0);
	flag = get_flag(argv[1]);
	start = 1;
	if (flag > 0)
		start = 2;
	stack_a = create_stack(argc, argv, start);
	if (!stack_a)
	{
		error(&stack_a);
		return (1);
	}
	stack_b = NULL;
	run_sort(&stack_a, &stack_b, flag);
	free_stack(&stack_a);
	return (0);
}