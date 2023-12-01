/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_inst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:39:44 by ottouti           #+#    #+#             */
/*   Updated: 2023/12/01 13:11:51 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **stack, bool print)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!*stack || (*stack) -> next == NULL)
		return ;
	first = *stack;
	second = (*stack) -> next;
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

void	rotate_b(t_stack **stack, bool print)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!*stack || (*stack) -> next == NULL)
		return ;
	first = *stack;
	second = (*stack) -> next;
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

void	rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
{
	while (*stack_b != cheapest -> target_node && *stack_a != cheapest)
	{
		rotate_a(stack_a, false);
		rotate_b(stack_b, false);
		ft_printf("rr\n");
	}
}