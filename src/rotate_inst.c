/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_inst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:39:44 by ottouti           #+#    #+#             */
/*   Updated: 2023/11/21 13:28:30 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (!*stack || (*stack) -> next == NULL)
		return ;
	first = *stack;
	second = (*stack) -> next;
	last = ft_lstlast(*stack);
	last -> next = first;
	first -> next = NULL;
	*stack = second;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;
	t_list	*second_to_last;
	
	if (!*stack || (*stack) -> next == NULL)
		return ;
	first = *stack;
	last = ft_lstlast(*stack);
	second_to_last = *stack;
	while (second_to_last -> next != last)
		second_to_last = second_to_last -> next;
	last -> next = first;
	second_to_last -> next = NULL;
	*stack = last;
}