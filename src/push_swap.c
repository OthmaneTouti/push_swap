/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:03:44 by ottouti           #+#    #+#             */
/*   Updated: 2023/11/21 13:24:30 by ottouti          ###   ########.fr       */
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
		return ;
	*(new_node -> content) = num;
	new_node -> next = NULL;
	ft_lstadd_back(stack, new_node);
}

t_list	*create_stack(int count, char **integers)
{
	int		i;
	t_list	*stack;
	
	stack = NULL;
	i = 0;
	while (i < count)
	{
		create_node(integers[i], &stack);
		i++;
	}
	return (stack);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (0);
	if (!validate_integers(argc - 1, argv + 1))
	{
		ft_printf("Error\n");
		return (1);
	}
	stack_a = create_stack(argc - 1, argv + 1);
	stack_b = NULL;
	printf("Stack a:\n");
	while (stack_a != NULL)
	{
		printf("%d\n", *stack_a -> content);
		stack_a = stack_a -> next;
	}
	printf("Stack b:\n");
	while (stack_b != NULL)
	{
		printf("%d\n", *stack_b -> content);
		stack_b = stack_b -> next;
	}
	ft_lstclear(&stack_a, &del);
	ft_lstclear(&stack_b, &del);
	return (0);
}
