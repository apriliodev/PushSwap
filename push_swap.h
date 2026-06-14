/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdecourt <bdecourt@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 20:30:31 by bdecourt          #+#    #+#             */
/*   Updated: 2026/06/14 23:52:04 by bdecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

/* Structure */
typedef struct s_stack
{
	int				index;
	int				value;
	struct s_stack	*next;
}					t_stack;

typedef struct s_count
{
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total;
	float			dissorder;
	int				bench;
	int				flag;
	char			*str;
	int				size;
	int				pos;

}					t_count;

typedef struct s_arrgg
{
	t_stack			**stack_a;
	t_stack			**stack_b;
	int				min;
	int				max;
	t_count			*count;
}					t_arrgg;

typedef struct s_arg
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	t_count			count;
	int				flag;
	int				start;
	float			disbench;
	char			*str;
}					t_arg;

/* operations/swap.c */
void				do_sa(t_stack **stack_a, t_count *count);
void				do_sb(t_stack **stack_b, t_count *count);
void				do_ss(t_stack **stack_a, t_stack **stack_b, t_count *count);

/* operations/push.c */
void				pushing(t_stack **res, t_stack **des);
void				do_pa(t_stack **stack_a, t_stack **stack_b, t_count *count);
void				do_pb(t_stack **stack_a, t_stack **stack_b, t_count *count);

/* operations/rotate.c */
void				do_ra(t_stack **stack_a, t_count *count);
void				do_rb(t_stack **stack_b, t_count *count);
void				do_rr(t_stack **stack_a, t_stack **stack_b, t_count *count);

/* operations/rrotate.c */
t_stack				*before_tail(t_stack *stack);
void				do_rra(t_stack **stack_a, t_count *count);
void				do_rrb(t_stack **stack_b, t_count *count);
void				do_rrr(t_stack **stack_a, t_stack **stack_b,
						t_count *count);

/* algorithms/disorder.c */
float				compute_disorder(t_stack *stack_a);

/* algorithms/utils.c */
int					stack_size(t_stack *stack);
t_stack				*stack_last(t_stack *stack);
int					ft_sqrt(int n);
int					get_chunk_size(t_stack *stack);
void				assign_index(t_stack *stack);
int					ft_flm(t_stack **a);

/* algorithms/radix.c */
void				radix_sort(t_stack **stack_a, t_stack **stack_b,
						t_count *count);

/* algorithms/selectionsort.c */
void				bubble_sort(t_stack **stack, t_count *count);
void				selection_sort(t_stack **a, t_stack **b, t_count *count);
/* algorithms/chunkbased.c */
void				push_chunk(t_arrgg rr);
t_stack				*find_max_b(t_stack *b);
void				bring_back(t_stack **stack_a, t_stack **stack_b,
						t_count *count);
void				chunk_sort(t_stack **stack_a, t_stack **stack_b,
						t_count *count);
int					check_bench(char **argv);
int					check_bench(char **argv);

/* algorithms/three.c */
void				sort_three(t_stack **a, t_count *count);

/* stack.c */
void				free_stack(t_stack **stack);
t_stack				*create_stack(int argc, char **argv, int start);

/* parsing.c */
int					is_number(char *str);
int					is_in_range(char *str);
int					has_duplicate(t_stack *stack_a);

/* push_swap.c */
char				*sort(t_stack **a, t_stack **b, t_count *count);
void				ft_bench(char *arg, float dissorder, t_count *count);
t_count				zero_for_touch(t_count count);
int					is_sorted(t_stack *a);

#endif