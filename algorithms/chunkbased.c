/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunkbased.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdecourt <bdecourt@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 19:22:20 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/17 20:28:32 by bdecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include "push_swap.h"

void	push_chunk(t_stack **stack_a, t_stack **stack_b, int min, int max)
{
	int	i;
	int	n;

	i = 0;
	n = stack_size(*stack_a);
	while (i < n)
	{
		if ((*stack_a)->index >= min && (*stack_a)->index < max)
			do_pb(stack_a, stack_b);
		else
			do_ra(stack_a);
		i++;
	}
}

t_stack	*find_max_b(t_stack *b)
{
	t_stack	*max;
	t_stack	*tmp;

	max = b;
	tmp = b;
	while (tmp)
	{
		if (tmp->index > max->index)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

void	bring_back(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*max;

	while (*stack_b)
	{
		max = find_max_b(*stack_b);
		while ((*stack_b)->index != max->index)
			do_rb(stack_b);
		do_pa(stack_a, stack_b);
	}
}

void	chunk_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	n;
	int	chunksize;
	int	chunk;

	chunk = 0;
	n = stack_size(*stack_a);
	chunksize = get_chunk_size(*stack_a);
	assign_index(*stack_a);
	while (chunk * chunksize < n)
	{
		push_chunk(stack_a, stack_b, chunk * chunksize, (chunk + 1)
			* chunksize);
		chunk++;
	}
	bring_back(stack_a, stack_b);
}

int	main(void)
{
	t_stack a;
	t_stack b;
	t_stack c;
	t_stack d;
	t_stack e;
	t_stack f;
	t_stack g;
	t_stack h;
	t_stack i;
	t_stack *stack_a;
	t_stack *stack_b;

	a.value = 5;
	b.value = 2;
	c.value = 8;
	d.value = 1;
	e.value = 9;
	f.value = 3;
	g.value = 7;
	h.value = 4;
	i.value = 6;
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &g;
	g.next = &h;
	h.next = &i;
	i.next = NULL;
	stack_a = &a;
	stack_b = NULL;
	ft_printf("Avant    : ");
	ft_printf("%d->%d->%d->%d->%d->%d->%d->%d->%d\n", a.value, b.value, c.value,
		d.value, e.value, f.value, g.value, h.value, i.value);
	ft_printf("Disorder : %.2f\n", compute_disorder(stack_a));
	chunk_sort(&stack_a, &stack_b);
	ft_printf("Apres    : ");
	while (stack_a)
	{
		ft_printf("%d -> ", stack_a->value);
		stack_a = stack_a->next;
	}
	ft_printf("NULL\n");
	return (0);
}