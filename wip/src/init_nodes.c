/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:45:28 by ottouti           #+#    #+#             */
/*   Updated: 2023/12/01 13:28:45 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Initiates nodes of the stack for this current pass.
Updates the indexes of both stacks, finds every target of stacks a,
calculates the cost of moving each node to a and finds the cheapest node to move*/
void	init_nodes_a(t_stack *stack_a, t_stack *stack_b)
{
	find_index(stack_a);
	find_index(stack_b);
	find_target_a(stack_a, stack_b);
	find_cost(stack_a, stack_b);
	find_cheapest(stack_a);
}

/*Initiates the nodes of stack b to get ready to move them back to a.
Starts by updating the indexes then finds every target to move nodes back to a.*/
void	init_nodes_b(t_stack *stack_a, t_stack *stack_b)
{
	find_index(stack_a);
	find_index(stack_b);
	find_target_b(stack_a, stack_b);
}