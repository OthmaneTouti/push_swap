/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_inst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:39:44 by ottouti           #+#    #+#             */
/*   Updated: 2023/11/27 11:18:06 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*rotate_a(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (!*stack || (*stack) -> next == NULL)
		return (NULL);
	first = *stack;
	second = (*stack) -> next;
	last = ft_lstlast(*stack);
	last -> next = first;
	first -> next = NULL;
	*stack = second;
	return ("ra");
}

char	*rotate_b(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (!*stack || (*stack) -> next == NULL)
		return (NULL);
	first = *stack;
	second = (*stack) -> next;
	last = ft_lstlast(*stack);
	last -> next = first;
	first -> next = NULL;
	*stack = second;
	return ("rb");
}

char	*reverse_rotate_a(t_list **stack)
{
	t_list	*first;
	t_list	*last;
	t_list	*second_to_last;
	
	if (!*stack || (*stack) -> next == NULL)
		return (NULL);
	first = *stack;
	last = ft_lstlast(*stack);
	second_to_last = *stack;
	while (second_to_last -> next != last)
		second_to_last = second_to_last -> next;
	last -> next = first;
	second_to_last -> next = NULL;
	*stack = last;
	return ("rra");
}

char	*reverse_rotate_b(t_list **stack)
{
	t_list	*first;
	t_list	*last;
	t_list	*second_to_last;
	
	if (!*stack || (*stack) -> next == NULL)
		return (NULL);
	first = *stack;
	last = ft_lstlast(*stack);
	second_to_last = *stack;
	while (second_to_last -> next != last)
		second_to_last = second_to_last -> next;
	last -> next = first;
	second_to_last -> next = NULL;
	*stack = last;
	return ("rrb");
}