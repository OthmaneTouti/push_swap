/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:03:44 by ottouti           #+#    #+#             */
/*   Updated: 2023/11/20 15:20:42 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void create_node(char *integer, t_list **stack, int is_a)
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
	if (is_a)
		*(new_node -> content) = num;
	else
		new_node -> content = NULL;
	new_node -> next = NULL;
	ft_lstadd_back(stack, new_node);
}

t_list	*create_stack(int count, char **integers, int is_a)
{
	int		i;
	t_list	*stack_a;
	
	stack_a = NULL;
	i = 0;
	while (i < count)
	{
		create_node(integers[i], &stack_a, is_a);
		i++;
	}
	return (stack_a);
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
	stack_a = create_stack(argc - 1, argv + 1, 1);
	stack_b = create_stack(argc - 1, argv + 1, 0);
	swap(&stack_a);
	while (stack_a != NULL)
	{
		printf("%d\n", *stack_a -> content);
		if (stack_b -> content == NULL)
			printf("null\n");
		stack_a = stack_a -> next;
		stack_b = stack_b -> next;
	}
	return (0);
}
