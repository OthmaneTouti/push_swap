/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:54:03 by ottouti           #+#    #+#             */
/*   Updated: 2023/12/01 16:25:03 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Function that calls the approriate functions to make both stacks ready to push
from a to b. Depending on if the cheapest node to move and it's target are
above or below the median it calls for the rotation or the reverse rotation of both stacks
until the approriate nodes are on top. Then it calls the prep_for_push function which will rotate
the stacks individually until the right nodes are on top.
Then it pushes the cheapest node to it's target in stack_b*/
void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*stack_a);
	if (cheapest_node -> above_median
		&& cheapest_node -> target_node -> above_median)
		rotate_both(stack_a, stack_b, cheapest_node);
	else if (!cheapest_node -> above_median
		&& !cheapest_node -> target_node -> above_median)
		rev_rotate_both(stack_a, stack_b, cheapest_node);
	prep_for_push(stack_a, cheapest_node, 'a');
	prep_for_push(stack_b, cheapest_node -> target_node, 'b');
	push_b(stack_a, stack_b);
}

/*Same thing here but from b to a.
We are only rotating stack_a because stack_b is already in order.*/
void	move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	prep_for_push(stack_a, (*stack_b) -> target_node, 'a');
	push_a(stack_a, stack_b);
}