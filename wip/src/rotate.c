/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:39:44 by ottouti           #+#    #+#             */
/*   Updated: 2023/12/01 20:33:39 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Function that performs the rotate instruction and updates the indexes
for stack_a*/
void	rotate_a(t_stack **stack, bool print)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!*stack || (*stack)-> next == NULL)
		return ;
	first = *stack;
	second = (*stack)-> next;
	last = stklast(*stack);
	last -> next = first;
	first -> prev = last;
	second -> prev = NULL;
	first -> next = NULL;
	*stack = second;
	find_index(*stack);
	if (print)
		ft_printf("ra\n");
}

/*Function that performs the rotate instruction and updates the indexes for
stack_b*/
void	rotate_b(t_stack **stack, bool print)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!*stack || (*stack)-> next == NULL)
		return ;
	first = *stack;
	second = (*stack)-> next;
	last = stklast(*stack);
	last -> next = first;
	first -> prev = last;
	second -> prev = NULL;
	first -> next = NULL;
	*stack = second;
	find_index(*stack);
	if (print)
		ft_printf("rb\n");
}

/*Function that will perform both rotation instructions until 
the cheapest node and the target node are both on top of their 
respective stacks.*/
void	rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
{
	while (*stack_b != cheapest -> target_node && *stack_a != cheapest)
	{
		rotate_a(stack_a, false);
		rotate_b(stack_b, false);
		ft_printf("rr\n");
	}
}
