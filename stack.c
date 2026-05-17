/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdecourt <bdecourt@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 23:42:13 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/17 23:47:27 by bdecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

static t_stack	*new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->next = NULL;
	return (node);
}

static void	add_back(t_stack **stack, t_stack *node)
{
	t_stack	*last;

	if (!*stack)
	{
		*stack = node;
		return ;
	}
	last = stack_last(*stack);
	last->next = node;
}

t_stack	*create_stack(int argc, char **argv, int start)
{
	t_stack	*stack;
	t_stack	*node;
	int		i;

	stack = NULL;
	i = start;
	while (i < argc)
	{
		if (!is_number(argv[i]) || !is_in_range(argv[i]))
		{
			free_stack(&stack);
			return (NULL);
		}
		node = new_node(ft_atoi(argv[i]));
		if (!node)
		{
			free_stack(&stack);
			return (NULL);
		}
		add_back(&stack, node);
		i++;
	}
	if (has_duplicate(stack))
	{
		free_stack(&stack);
		return (NULL);
	}
	return (stack);
}