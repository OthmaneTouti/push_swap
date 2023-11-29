/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:30:57 by ottouti           #+#    #+#             */
/*   Updated: 2023/11/28 23:02:21 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



// void	free_node(t_stack *stack)
// {
// 	if (!stack)
// 		return ;
// 	free(stack -> nbr);
// 	free(stack -> index);
// 	if (stack -> cost)
// 		free(stack ->cost);
// 	if (stack -> above_median)
// 		free(stack -> above_median);
// 	if (stack -> cheapest)
// 		free(stack -> cheapest);
// }

t_stack	*find_max_node(t_stack *stack)
{
	t_stack	*max_node;
	t_stack	*current;
	
	max_node = stack;
	current = stack;
	while(current)
	{
		if (current -> nbr > max_node -> nbr)
			max_node = current;
		current = current -> next;
	}
	return (max_node);
}