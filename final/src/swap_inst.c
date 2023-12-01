/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_inst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:00:51 by ottouti           #+#    #+#             */
/*   Updated: 2023/11/30 15:40:56 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*second_node;

	first_node = *stack;
	second_node = (*stack) -> next;
	if (!*stack || !(*stack) -> next)
		return ;
	first_node -> next = second_node -> next;
	second_node -> next -> prev = first_node;
	first_node -> prev = second_node;
	second_node -> next = first_node;
	second_node -> prev = NULL;
	*stack = second_node;
	find_index(*stack);
	ft_printf("sa\n");
}

void	swap_b(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*second_node;

	first_node = *stack;
	second_node = (*stack) -> next;
	if (!*stack || !(*stack) -> next)
		return ;
	first_node -> next = second_node -> next;
	second_node -> next -> prev = first_node;
	first_node -> prev = second_node;
	second_node -> next = first_node;
	second_node -> prev = NULL;
	*stack = second_node;
	find_index(*stack);
	ft_printf("sb\n");
}