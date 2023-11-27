/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:03:44 by ottouti           #+#    #+#             */
/*   Updated: 2023/11/27 13:42:02 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void create_node(char *integer, t_list **stack)
{
	int		num;
	t_list	*new_node;
	
	new_node = (t_list *) malloc(sizeof(t_list));
	if (!new_node)
		return ;
	num = ft_atoi(integer);
	new_node -> content = (int *) malloc(sizeof(int));
	if (!new_node -> content)
	{
		free(new_node);
		return ;
	}
	*((int *)new_node->content) = num;
	new_node -> next = NULL;
	ft_lstadd_back(stack, new_node);
}

t_list	*create_stack(int count, char **integers, int is_str)
{
	int		i;
	t_list	*stack;
	
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

void	sort(t_list **stack_a, t_list **stack_b, t_list **insts)
{
	int	count;

	if (!*stack_a || *stack_b)
		return ;
	count = ft_lstsize(*stack_a);
	if (count == 1)
		return ;
	else if (count <= 3)
		tiny_sort(stack_a, insts);
	else if (count > 3)
		insert_sort(stack_a, stack_b, insts);
}