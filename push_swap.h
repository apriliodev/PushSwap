/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdecourt <bdecourt@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 20:30:31 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/17 23:31:23 by bdecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
 
# include "libft/libft.h"
# include "printf/ft_printf.h"
 
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
 
/* algorithms/utils.c */
int					stack_size(t_stack *stack);
t_stack				*stack_last(t_stack *stack);
int					ft_sqrt(int n);
int					get_chunk_size(t_stack *stack);
void				assign_index(t_stack *stack);
 
/* algorithms/bubblesort.c */
void				bubble_sort(t_stack **stack);
 
/* algorithms/chunkbased.c */
void				push_chunk(t_stack **a, t_stack **b, int min, int max);
t_stack				*find_max_b(t_stack *b);
void				bring_back(t_stack **a, t_stack **b);
void				chunk_sort(t_stack **a, t_stack **b);
 
/* algorithms/radix.c */
int					ft_log2(int n);
void				radix_sort(t_stack **stack_a, t_stack **stack_b);
 
/* algorithms/three.c */
void				sort_three(t_stack **a);
 
/* push_swap.c */
void				sort(t_stack **a, t_stack **b);
 
#endif
