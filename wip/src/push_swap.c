/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:03:44 by ottouti           #+#    #+#             */
/*   Updated: 2023/12/01 20:38:49 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*This function counts the number of nodes in stack a and calls
the appropriate function*/
static void	triage(t_stack **stack_a, t_stack **stack_b)
{
	int	count;

	if (!*stack_a || *stack_b)
		return ;
	count = stksize(*stack_a);
	if (count == 1)
		return ;
	else if (count <= 3)
		tiny_sort(stack_a);
	else if (count > 3)
		sort(stack_a, stack_b);
}

/*main function, calls the create stack function with the arguments given
to the program, calls the triage function and frees the stacks at the end
of the program.*/
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	stack_a = create_stack(argc - 1, argv + 1, argc == 2);
	if (!stack_a)
	{
		ft_printf("Error\n");
		return (1);
	}
	stack_b = NULL;
	triage(&stack_a, &stack_b);
	stkclear(&stack_a);
	stkclear(&stack_b);
	return (0);
}
