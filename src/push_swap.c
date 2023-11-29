/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:03:44 by ottouti           #+#    #+#             */
/*   Updated: 2023/11/29 15:58:55 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void create_node(char *integer, t_stack **stack)
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

t_stack	*create_stack(int count, char **integers, int is_str)
{
	int		i;
	t_stack	*stack;
	
	i = 0;
	if (is_str)
	{
		count = 0;
		while(integers[i])
		{
			count++;
			i++;
		}
		i = 0;
	}
	if (!validate_integers(count, integers))
		return (NULL);
	stack = NULL;
	while (i < count)
	{
		create_node(integers[i], &stack);
		i++;
	}
	return (stack);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b, t_list **insts)
{
	int	count;

	if (!*stack_a || *stack_b || *insts)
		return ;
	count = stksize(*stack_a);
	if (count == 1 || is_sorted(*stack_a))
		return ;
	else if (count <= 3)
	 	tiny_sort(stack_a, insts);
	else if (count > 3)
		sort(stack_a, stack_b, insts);
}