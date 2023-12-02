/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:22:37 by ottouti           #+#    #+#             */
/*   Updated: 2023/12/01 20:15:38 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*At the end of the program, the minimum value of stack_a won't necessarily
be on top of the stack. This function rotates the stack until it is.*/
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

/*Function that sorts 3 digits. It first checks if the max value of the stack
is on top. If so, it rotates the stack so that the max value is last. If not,
it checks if the max value is second, if so it reverse rotates the stack so that
the max value is last. Finally, it checks if the first value is greater than the
second value. If so, it swaps them.*/
void	tiny_sort(t_stack **stack_a)
{
	t_stack	*max_node;
	
	max_node = find_max_node(*stack_a);
	if (*stack_a == max_node)
		rotate_a(stack_a, true);
	else if ((*stack_a) -> next == max_node && max_node -> next)
		reverse_rotate_a(stack_a, true);
	if ((*stack_a) -> nbr > (*stack_a) -> next -> nbr)
		swap_a(stack_a);
}

/*This function initiates the sorting algorithm. It starts by pushing 2 nodes
to b without checking anything (except if stack_a has a length of 4, in which case
it pushes only one node) so that stack_b has a minimum and maximum node. This will
allow us to find targets and calculate the cheapest node to move in the init_nodes functions.
The nodes are then pushed to stack_b and these previous steps are repeated until there is only 
3 nodes left in stack_a. The program then performs a tiny_sort on stack_a to sort 3 integers,
which is a trivial operation. We then move all the nodes back to stack_a while finding the right
positions for them and we bring the minimum of stack_a on top.*/
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
