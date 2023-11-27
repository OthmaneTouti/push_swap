/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:06:57 by ottouti           #+#    #+#             */
/*   Updated: 2023/11/27 12:39:16 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*insts;

	if (argc == 1 ||(argc == 2 && !argv[1][0]))
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
	insts = NULL;
	sort(&stack_a, &stack_b, &insts);
	ft_printf("Stack a:\n");
	while (stack_a != NULL)
	{
		ft_printf("%d\n", *((int *)stack_a -> content));
		stack_a = stack_a -> next;
	}
	ft_printf("Stack b:\n");
	while (stack_b != NULL)
	{
		ft_printf("%d\n", *((int *)stack_b -> content));
		stack_b = stack_b -> next;
	}
	ft_printf("Instructions:\n");
	while (insts != NULL)
	{
		if (insts -> content != NULL)
		{
			ft_printf("%s\n", (char *)insts -> content);
		}
		insts = insts -> next;
	}
	ft_lstclear(&stack_a, &del);
	ft_lstclear(&stack_b, &del);
	return (0);
}