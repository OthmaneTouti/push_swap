/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:49:47 by ottouti           #+#    #+#             */
/*   Updated: 2023/12/01 16:00:44 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Function that gives every node in stack_a a target in stack_a.
A good target (best_match) is the closest smaller number in stack_b.
If we can't find a smaller number in stack_b, it means that the
number is stack_a should go at the bottom of stack_b, so we set the
target to the max value of stack_b.*/
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

/*Same idea as the above function. In this case we are giving nodes in stack_b
target nodes in stack_a. To do so, find the closest bigger number in stack_a and
set it as the target. That way, when we push the nodes back in stack_a, they will
be pushed to the correct position. If we can't find a bigger node in stack_a, we set
the target to the minimum value of stack_a. That way the biggest number will come before
the minumum, and we can rotate the stack later to put the minimum back on top
(see min_on_top function)*/
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
