/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:47:43 by ottouti           #+#    #+#             */
/*   Updated: 2023/11/29 17:00:23 by ottouti          ###   ########.fr       */
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

void	find_target(t_stack *stack_a, t_stack *stack_b)
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