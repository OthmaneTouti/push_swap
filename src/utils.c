/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:30:57 by ottouti           #+#    #+#             */
/*   Updated: 2023/11/29 17:34:23 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*node;

	node = stack;
	while (node -> next)
	{
		if (node -> nbr > node -> next -> nbr)
			return (0);
		node = node -> next;
	}
	return (1);
}

t_stack	*find_max_node(t_stack *stack)
{
	t_stack	*max_node;
	t_stack	*current;
	
	max_node = stack;
	current = stack;
	while(current)
	{
		if (current -> nbr > max_node -> nbr)
			max_node = current;
		current = current -> next;
	}
	return (max_node);
}

t_stack	*find_min_node(t_stack *stack)
{
	t_stack	*min_node;
	t_stack	*current;

	min_node = stack;
	current = stack;
	while(current)
	{
		if (current -> nbr < min_node -> nbr)
			min_node = current;
		current = current -> next;
	}
	return (min_node);
}

void	write_inst(char *inst, t_list **insts)
{
	t_list	*node;
	t_list	*last_inst;

	if (*insts && *inst == 'r')
	{
		last_inst = ft_lstlast(*insts);
		if ((!ft_strncmp(last_inst->content, "ra", 2) && !ft_strncmp(inst, "rb", 2))
			|| (!ft_strncmp(last_inst->content, "rb", 2) && !ft_strncmp(inst, "ra", 2)))
			{
				last_inst -> content = "rr";
				return ;
			}
		else if ((!ft_strncmp(last_inst->content, "rra", 3) && !ft_strncmp(inst, "rrb", 3))
			|| (!ft_strncmp(last_inst->content, "rrb", 3) && !ft_strncmp(inst, "rra", 3)))
			{
				last_inst -> content = "rrr";
				return ;
			}
	}
	node = ft_lstnew(inst);
	ft_lstadd_back(insts, node);
}