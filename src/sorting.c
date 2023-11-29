/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:22:37 by ottouti           #+#    #+#             */
/*   Updated: 2023/11/28 23:02:45 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_inst(char *inst, t_list **insts)
{
	t_list	*node;

	node = ft_lstnew(inst);
	ft_lstadd_back(insts, node);
}

// void	tiny_sort(t_stack **stack_a, t_stack **insts)
// {
// 	t_stack	*max_node;
	
// 	max_node = find_max_node(*stack_a);
// 	if (*stack_a == max_node)
// 		write_inst(rotate_a(stack_a), insts);
// 	else if ((*stack_a) -> next == max_node)
// 		write_inst(reverse_rotate_a(stack_a), insts);
// 	if (*(int *)(*stack_a) -> nbr > *(int *)(*stack_a) -> next -> nbr)
// 		write_inst(swap_a(stack_a), insts);
// }

// void	insert_sort(t_stack **stack_a, t_stack **stack_b, t_stack **insts)
// {
// 	int		pushed;
	
// 	pushed = 0;
// 	while(ft_lstsize(*stack_a) != 3)
// 		write_inst(push_b(stack_a, stack_b), insts);
// 	tiny_sort(stack_a, insts);
// 	while (*stack_b)
// 	{
// 		if (*(int *)(*stack_b) -> nbr < *(int *)(*stack_a) -> nbr)
// 		{
// 			write_inst(push_a(stack_a, stack_b), insts);
// 			pushed = 1;
// 		}
// 		write_inst(rotate_a(stack_a), insts);
// 		pushed = 0;
// 		if (!*stack_b)
// 			return ;
// 		else if (ft_lstsize(*stack_b) == 1)
// 		{
// 			write_inst(push_a(stack_a, stack_a), insts);
// 			write_inst(rotate_a(stack_a), insts);
// 			return ;
// 		}
// 		if (!pushed)
// 			write_inst(rotate_b(stack_b), insts);
// 	}
// }