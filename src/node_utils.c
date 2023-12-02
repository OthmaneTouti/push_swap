/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:47:43 by ottouti           #+#    #+#             */
/*   Updated: 2023/12/01 20:26:02 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Function that creates a node for stack_a. The string from stdinput is
converted to an integer by the ft_atoi function and then assigned to the
nbr value of the stack. Next is set to NULL to signify that this is the last
node and the prev parameter is set to the current last node of the stack or
NULL if this is the first node of the stack. Finally, the node is added to
the end of the current stack.*/
void	create_node(char *integer, t_stack **stack)
{
	int		num;
	t_stack	*new_node;

	new_node = (t_stack *) malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	num = ft_atoi(integer);
	new_node -> nbr = num;
	new_node -> next = NULL;
	new_node -> prev = stklast(*stack);
	stkadd_back(stack, new_node);
}

/*Function that finds index of each of the nodes in the stack. It also
calculates the median (mid point) of the stack and assigns a true or
false value to each node according to their index being above or below
the median. This is useful to know if we need to rotate or reverse_rotate
the stack to get a particular node on top.*/
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

/*Function that calculates the cost (number of instructions) necessary to get
the current node on top of stack_a and to get it's target node on top of
stack_b. First, if the current node is above the median, the cost to bring it
on top is simply it's index (rotating the stack until it's on top). If not,
we have to reverse rotate and thus the cost is the length of stack_a minus the
index of the node we want on top. Then we add to this the cost of bringing the
target node on top of stack_b, using the same logic*/
void	find_cost(t_stack *stack_a, t_stack *stack_b)
{
	int	size_a;
	int	size_b;

	size_a = stksize(stack_a);
	size_b = stksize(stack_b);
	while (stack_a)
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

/*Simple function that finds the smallest cost of all the nodes in the stack
and sets the cheapest parameter to true in that node.*/
void	find_cheapest(t_stack *stack)
{
	t_stack	*cheapest_node;
	long	cheapest_cost;

	cheapest_cost = LONG_MAX;
	while (stack)
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
