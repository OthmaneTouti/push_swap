/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_inst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:00:51 by ottouti           #+#    #+#             */
/*   Updated: 2023/11/24 13:23:52 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*swap_a(t_list **stack)
{
	t_list	*first_node;
	t_list	*second_node;

	first_node = *stack;
	second_node = (*stack) -> next;
	if (!*stack || !(*stack) -> next)
		return (NULL);
	first_node -> next = second_node -> next;
	second_node -> next = first_node;
	*stack = second_node;
	return ("sa");
}

char	*swap_b(t_list **stack)
{
	t_list	*first_node;
	t_list	*second_node;

	first_node = *stack;
	second_node = (*stack) -> next;
	if (!*stack || !(*stack) -> next)
		return (NULL);
	first_node -> next = second_node -> next;
	second_node -> next = first_node;
	*stack = second_node;
	return ("sb");
}