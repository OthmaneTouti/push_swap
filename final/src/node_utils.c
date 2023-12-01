/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:47:43 by ottouti           #+#    #+#             */
/*   Updated: 2023/12/01 14:28:12 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stksize(stack) / 2;
	while (stack)
	{
		stack -> index = i;
		if (i <= median)
			stack -> above_median = true;
		else
			stack -> above_median = false;
		stack = stack -> next;
		i++;
	}
}

void	find_target_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_b;
	t_stack	*target;
	long	best_match;

	while (stack_a)
	{
		best_match = LONG_MIN;
		current_b = stack_b;
		while (current_b)
		{
			if (current_b -> nbr < stack_a -> nbr
				&& current_b -> nbr > best_match)
			{
				best_match = current_b -> nbr;
				target = current_b;
			}
			current_b = current_b -> next;
		}
		if (best_match == LONG_MIN)
			stack_a -> target_node = find_max_node(stack_b);
		else
			stack_a -> target_node = target;
		stack_a = stack_a -> next;
	}
}

void	find_target_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_a;
	t_stack	*target;
	long	best_match;

	while (stack_b)
	{
		best_match = LONG_MAX;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a -> nbr > stack_b -> nbr
				&& current_a -> nbr < best_match)
			{
				best_match = current_a -> nbr;
				target = current_a;
			}
			current_a = current_a -> next;
		}
		if (best_match == LONG_MAX)
			stack_b -> target_node = find_min_node(stack_a);
		else
			stack_b -> target_node = target;
		stack_b = stack_b -> next;
	}
}

void	find_cost(t_stack *stack_a, t_stack *stack_b)
{
	int	size_a;
	int	size_b;

	size_a = stksize(stack_a);
	size_b = stksize(stack_b);
	while(stack_a)
	{
		stack_a -> cost = stack_a -> index;
		if (!stack_a -> above_median)
			stack_a -> cost = size_a - (stack_a -> index);
		if (stack_a -> target_node -> above_median)
			stack_a -> cost += stack_a -> target_node -> index;
		else
			stack_a -> cost += size_b - (stack_a -> target_node -> index);
		stack_a = stack_a -> next;
	}
}

void	find_cheapest(t_stack *stack)
{
	t_stack	*cheapest_node;
	long	cheapest_cost;

	cheapest_cost = LONG_MAX;
	while(stack)
	{
		if (stack -> cost < cheapest_cost)
		{
			cheapest_cost = stack -> cost;
			cheapest_node = stack;
		}
		stack = stack -> next;
	}
	if (cheapest_cost != LONG_MAX)
		cheapest_node -> cheapest = true;
}
