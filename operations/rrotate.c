/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdecourt <bdecourt@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 01:14:45 by bdecourt          #+#    #+#             */
/*   Updated: 2026/05/17 01:27:09 by bdecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "printf.h"

t_stack *before_tail(t_stack *stack)
{
    while (stack && stack->next && stack->next->next != NULL) /*Tant qu'on est dans la stack, et qu'il y a un suivant, et que le suivant du suivant n'est pas NULL (permet d'arriver a l'avant dernier)*/
        stack = stack->next; /*On continue*/
    return (stack);
}

static void r_rotating(t_stack **stack)
{
    t_stack *tmp;
    t_stack *tail;
    t_stack *btail;

    tail = ft_lstlast(*stack); /*On donne a tail la valeur de la tail (Fin de chaine)*/
    btail = before_tail(*stack); /*Ma fonction beforetail qui recupere le node juste avant la tail*/
    tmp = *stack; /*tmp prend la valeur de stack (premier node)*/
    *stack = tail; /*le premier node prend la valeur de la tail (dernier node)*/
    (*stack)->next = tmp; /*On met le next de stack egal a tmp qui vaut le premier (comme on a mis stack au dernier on rajoute le premier node apres le dernier node)*/
    btail->next = NULL; /*On supprime l'avant dernier node*/
}

void do_rra(t_stack **stack_a)
{
    r_rotating(stack_a);
    ft_printf("%s", "rra\n");
}
void do_rrb(t_stack **stack_b)
{
    r_rotating(stack_b);
    ft_printf("%s", "rrb\n");
}

void do_rrr(t_stack **stack_a, t_stack **stack_b);
{
    r_rotating(stack_a);
    r_rotating(stack_b);
    ft_printf("%s", "rrr\n");
}