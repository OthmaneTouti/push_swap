/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:30:57 by ottouti           #+#    #+#             */
/*   Updated: 2023/12/01 20:41:58 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Function that checks if the stack is sorted. This is very useful to avoid 
unecessary parsing.*/
int	is_sorted(t_stack *stack)
{
	t_stack	*node;

	node = stack;
	while (node -> next)
	{
		if (node -> nbr > node -> next -> nbr)
			return (0);
		node = node -> next;
	}
	return (1);
}

/*Function that finds the node with the highest number and returns it*/
t_stack	*find_max_node(t_stack *stack)
{
	t_stack	*max_node;
	t_stack	*current;

	max_node = stack;
	current = stack;
	while (current)
	{
		if (current -> nbr > max_node -> nbr)
			max_node = current;
		current = current -> next;
	}
	return (max_node);
}

/*Function that finds the node with the lowest number and returns it*/
t_stack	*find_min_node(t_stack *stack)
{
	t_stack	*min_node;
	t_stack	*current;

	min_node = stack;
	current = stack;
	while (current)
	{
		if (current -> nbr < min_node -> nbr)
			min_node = current;
		current = current -> next;
	}
	return (min_node);
}

/*This simple function just finds the node with the lowest cost value
and returns it.*/
t_stack	*get_cheapest(t_stack *stack)
{
	while (stack)
	{
		if (stack -> cheapest)
			break ;
		stack = stack -> next;
	}
	return (stack);
}
