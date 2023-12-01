/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_inst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:11:40 by ottouti           #+#    #+#             */
/*   Updated: 2023/12/01 14:27:18 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first_a;
	t_stack	*first_b;
	t_stack	*second_b;

	if (!*stack_b)
		return ;
	first_a = *stack_a;
	first_b = *stack_b;
	second_b = (*stack_b) -> next;
	first_b -> next = first_a;
	if (first_a)
		first_a -> prev = first_b;
	if (second_b)
		second_b -> prev = NULL;
	*stack_a = first_b;
	*stack_b = second_b;
	find_index(*stack_a);
	find_index(*stack_b);
	ft_printf("pa\n");
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first_a;
	t_stack	*first_b;
	t_stack	*second_a;

	if (!*stack_a)
		return ;
	first_a = *stack_a;
	first_b = *stack_b;
	second_a = (*stack_a) -> next;
	first_a -> next = first_b;
	if (first_b)
		first_b -> prev = first_a;
	if (second_a)
		second_a -> prev = NULL;
	*stack_b = first_a;
	*stack_a = second_a;
	find_index(*stack_a);
	find_index(*stack_b);
	ft_printf("pb\n");
}

void	prep_for_push(t_stack **stack, t_stack *top_node, char name)
{
	while(*stack != top_node)
	{
		if (name == 'a')
		{
			if (top_node -> above_median)
				rotate_a(stack, true);
			else
				reverse_rotate_a(stack, true);
		}
		else if (name == 'b')
		{
			if (top_node -> above_median)
				rotate_b(stack, true);
			else
				reverse_rotate_b(stack, true);
		}
	}
}
