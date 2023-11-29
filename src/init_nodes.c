/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:45:28 by ottouti           #+#    #+#             */
/*   Updated: 2023/11/29 17:14:14 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_nodes_a(t_stack *stack_a, t_stack *stack_b)
{
	find_index(stack_a);
	find_index(stack_b);
	find_target(stack_a, stack_b);
	//find_cost(stack_a, stack_b);
	//find_cheapest(stack_a);
}