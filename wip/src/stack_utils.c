/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 22:44:15 by ottouti           #+#    #+#             */
/*   Updated: 2023/12/01 20:36:33 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Function for freeing a stack*/
void	stkclear(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next_node;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current != NULL)
	{
		next_node = current -> next;
		free(current);
		current = next_node;
	}
	*stack = NULL;
}

/*Function for finding the length of a stack*/
int	stksize(t_stack *stack)
{
	t_stack	*current;
	int		count;

	current = stack;
	count = 0;
	while (current != NULL)
	{
		count++;
		current = current -> next;
	}
	return (count);
}

/*Function that returns the last node of a stack*/
t_stack	*stklast(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
		return (NULL);
	current = stack;
	while (current -> next != NULL)
		current = current -> next;
	return (current);
}

/*Function that adds a node to the end of a stack*/
void	stkadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = stklast(*stack);
	new -> prev = last;
	last -> next = new;
}

/*Function that initializes stack_a. It first checks if the parameter given
to the program is one long string (for example "3 9 8 7 2 1") or an array of
single characters. It then checks if there are no errors in the input. It
then intializes the stack as NULL and calls the create_node function for
every integer in the input to create the necessary number of nodes.*/
t_stack	*create_stack(int count, char **integers, int is_str)
{
	int		i;
	t_stack	*stack;

	i = 0;
	if (is_str)
	{
		count = 0;
		while (integers[i])
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
