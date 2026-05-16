/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdecourt <bdecourt@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 20:30:31 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/17 00:49:34 by bdecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_C
# define PUSH_SWAP_C


/*Notre structure avec la declaration de linked list*/
typedef struct s_stack
{
	int				stack_a;
	int				stack_b;
    int             index;
	void			*content;
	struct s_stack	*next;
}					t_stack;

#endif