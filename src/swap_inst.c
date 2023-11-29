/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_inst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:00:51 by ottouti           #+#    #+#             */
/*   Updated: 2023/11/28 22:38:55 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*swap_a(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*second_node;

	first_node = *stack;
	second_node = (*stack) -> next;
	if (!*stack || !(*stack) -> next)
		return (NULL);
	first_node -> next = second_node -> next;
	first_node -> prev = second_node;
	second_node -> next = first_node;
	second_node -> prev = NULL;
	*stack = second_node;
	return ("sa");
}

char	*swap_b(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*second_node;

	first_node = *stack;
	second_node = (*stack) -> next;
	if (!*stack || !(*stack) -> next)
		return (NULL);
	first_node -> next = second_node -> next;
	first_node -> prev = second_node;
	second_node -> next = first_node;
	second_node -> prev = NULL;
	*stack = second_node;
	return ("sb");
}