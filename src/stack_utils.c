/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 22:44:15 by ottouti           #+#    #+#             */
/*   Updated: 2023/11/28 23:04:53 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stkclear(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next_node;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current != NULL)
	{
		next_node = current -> next;
		free(current);
		current = next_node;
	}
	*stack = NULL;
}

int	stksize(t_stack *stack)
{
	t_stack	*current;
	int		count;

	current = stack;
	count = 0;
	while (current != NULL)
	{
		count++;
		current = current -> next;
	}
	return (count);
}

t_stack	*stklast(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
		return (NULL);
	current = stack;
	while (current -> next != NULL)
		current = current -> next;
	return (current);
}

void	stkadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = stklast(*lst);
	new -> prev = last;
	last -> next = new;
}

