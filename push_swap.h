/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdecourt <bdecourt@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 20:30:31 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/17 18:59:56 by bdecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

/* Structure */
typedef struct s_stack
{
	int				index;
	int				value;
	struct s_stack	*next;
}					t_stack;

/* operations/swap.c */
void				do_sa(t_stack **stack_a);
void				do_sb(t_stack **stack_b);
void				do_ss(t_stack **stack_a, t_stack **stack_b);

/* operations/push.c */
void				pushing(t_stack **res, t_stack **des);
void				do_pa(t_stack **stack_a, t_stack **stack_b);
void				do_pb(t_stack **stack_a, t_stack **stack_b);

/* operations/rotate.c */
void				do_ra(t_stack **stack_a);
void				do_rb(t_stack **stack_b);
void				do_rr(t_stack **stack_a, t_stack **stack_b);

/* operations/rrotate.c */
t_stack				*before_tail(t_stack *stack);
void				do_rra(t_stack **stack_a);
void				do_rrb(t_stack **stack_b);
void				do_rrr(t_stack **stack_a, t_stack **stack_b);

/* algorithms/disorder.c */
float				compute_disorder(t_stack *stack_a);

/* algorithms/first.c */
void				bubble_sort(t_stack **stack);

/*algorithms/utils.c*/
int					stack_size(t_stack *stack);
#endif