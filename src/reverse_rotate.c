/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:08:27 by ottouti           #+#    #+#             */
/*   Updated: 2023/12/01 20:40:05 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Function that performs the reverse rotate instruction for stack_a*/
void	reverse_rotate_a(t_stack **stack, bool print)
{
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = stklast(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
	if (print)
		ft_printf("rra\n");
}

/*Function that performs the reverse rotate instruction for stack_b*/
void	reverse_rotate_b(t_stack **stack, bool print)
{
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = stklast(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
	if (print)
		ft_printf("rrb\n");
}

/*Function that will perform both reverse rotation instructions until 
the cheapest node and the target node are both on top of their 
respective stacks.*/
void	rev_rotate_both(t_stack **stack_a,
						t_stack **stack_b,
						t_stack *cheapest)
{
	while (*stack_b != cheapest -> target_node && *stack_a != cheapest)
	{
		reverse_rotate_a(stack_a, false);
		reverse_rotate_b(stack_b, false);
		ft_printf("rrr\n");
	}
}
