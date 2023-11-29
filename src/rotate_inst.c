/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_inst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:39:44 by ottouti           #+#    #+#             */
/*   Updated: 2023/11/28 23:18:02 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*rotate_a(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!*stack || (*stack) -> next == NULL)
		return (NULL);
	first = *stack;
	second = (*stack) -> next;
	last = stklast(*stack);
	last -> next = first;
	first -> prev = last;
	second -> prev = NULL;
	first -> next = NULL;
	*stack = second;
	return ("ra");
}

char	*rotate_b(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!*stack || (*stack) -> next == NULL)
		return (NULL);
	first = *stack;
	second = (*stack) -> next;
	last = stklast(*stack);
	last -> next = first;
	first -> prev = last;
	second -> prev = NULL;
	first -> next = NULL;
	*stack = second;
	return ("rb");
}

char	*reverse_rotate_a(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*second_to_last;
	
	if (!*stack || (*stack) -> next == NULL)
		return (NULL);
	first = *stack;
	last = stklast(*stack);
	second_to_last = last -> prev;
	last -> next = first;
	last -> prev = NULL;
	first -> prev = last;
	second_to_last -> next = NULL;
	*stack = last;
	return ("rra");
}

char	*reverse_rotate_b(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*second_to_last;
	
	if (!*stack || (*stack) -> next == NULL)
		return (NULL);
	first = *stack;
	last = stklast(*stack);
	second_to_last = last -> prev;
	last -> next = first;
	last -> prev = NULL;
	second_to_last -> next = NULL;
	*stack = last;
	return ("rrb");
}