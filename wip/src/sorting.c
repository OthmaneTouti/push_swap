/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:22:37 by ottouti           #+#    #+#             */
/*   Updated: 2023/11/30 14:07:49 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void min_on_top(t_stack **stack_a)
{
	t_stack	*min_node;

	min_node = find_min_node(*stack_a);
	while((*stack_a) -> nbr != min_node -> nbr)
	{
		if (min_node -> above_median)
			rotate_a(stack_a, true);
		else
			reverse_rotate_a(stack_a, true);
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stksize(*stack_a);
	if (size-- > 3 && !is_sorted(*stack_a))
		push_b(stack_a, stack_b);
	if (size-- > 3 && !is_sorted(*stack_a))
		push_b(stack_a, stack_b);
	while (size-- > 3 && !is_sorted(*stack_a))
	{
		init_nodes_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	tiny_sort(stack_a);
	while (*stack_b)
	{
		init_nodes_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	find_index(*stack_a);
	min_on_top(stack_a);
}
