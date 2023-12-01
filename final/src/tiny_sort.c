/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:03:32 by ottouti           #+#    #+#             */
/*   Updated: 2023/11/30 13:48:40 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
