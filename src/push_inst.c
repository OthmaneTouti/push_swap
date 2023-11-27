/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_inst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:11:40 by ottouti           #+#    #+#             */
/*   Updated: 2023/11/24 13:24:13 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_a;
	t_list	*first_b;
	t_list	*second_b;

	if (!*stack_b)
		return (NULL);
	first_a = *stack_a;
	first_b = *stack_b;
	second_b = (*stack_b) -> next;
	first_b -> next = first_a;
	*stack_a = first_b;
	*stack_b = second_b;
	return ("pa");
}

char	*push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_a;
	t_list	*first_b;
	t_list	*second_a;

	if (!*stack_a)
		return (NULL);
	first_a = *stack_a;
	first_b = *stack_b;
	second_a = (*stack_a) -> next;
	first_a -> next = first_b;
	*stack_b = first_a;
	*stack_a = second_a;
	return ("pb");
}
