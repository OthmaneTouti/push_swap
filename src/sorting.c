/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:22:37 by ottouti           #+#    #+#             */
/*   Updated: 2023/11/27 14:32:19 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_inst(char *inst, t_list **insts)
{
	t_list	*node;

	node = ft_lstnew(inst);
	ft_lstadd_back(insts, node);
}

void	tiny_sort(t_list **stack_a, t_list **insts)
{
	t_list	*max_node;
	
	max_node = find_max_node(*stack_a);
	if (*stack_a == max_node)
		write_inst(rotate_a(stack_a), insts);
	else if ((*stack_a) -> next == max_node)
		write_inst(reverse_rotate_a(stack_a), insts);
	if (*(int *)(*stack_a) -> content > *(int *)(*stack_a) -> next -> content)
		write_inst(swap_a(stack_a), insts);
}

void	insert_sort(t_list **stack_a, t_list **stack_b, t_list **insts)
{
	t_list	*node_a;
	t_list	*node_b;
	int		pushed;
	
	pushed = 0;
	while(ft_lstsize(*stack_a) != 3)
		write_inst(push_b(stack_a, stack_b), insts);
	tiny_sort(stack_a, insts);
	node_b = *stack_b;
	while (node_b)
	{
		node_a = *stack_a;
		while(node_a)
		{
			if (*(int *)node_b -> content < *(int *)node_a -> content)
			{
				write_inst(push_a(&node_a, &node_b), insts);
				pushed = 1;
				break ;
			}
			node_a = node_a -> next;
			pushed = 0;
		}
		if (!*stack_b)
			return ;
		else if (ft_lstsize(*stack_b) == 1)
		{
			write_inst(push_a(stack_a, stack_a), insts);
			write_inst(rotate_a(stack_a), insts);
			return ;
		}
		if (!pushed)
			node_b = node_b -> next;
	}
}