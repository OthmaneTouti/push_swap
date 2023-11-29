/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:01:29 by ottouti           #+#    #+#             */
/*   Updated: 2023/11/29 16:04:14 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "../include/libft.h"
# include <stdbool.h>

typedef	struct s_stack
{
	int				nbr;
	int				index;
	int				cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

int		validate_integers(int count, char **integers);
int		check_limits(char *integer);
int		check_duplicates(char **integers);
int		stksize(t_stack *stack);
int		is_sorted(t_stack *stack);
void 	create_node(char *integer, t_stack **stack);
//void	free_node(t_stack *stack);
void	stkclear(t_stack **stack);
void	push_swap(t_stack **stack_a, t_stack **stack_b, t_list **inst);
void	write_inst(char *inst, t_list **insts);
void	tiny_sort(t_stack **stack_a, t_list **insts);
void	stkadd_back(t_stack **lst, t_stack *new);
void	sort(t_stack **stack_a, t_stack **stack_b, t_list **insts);
char	*swap_a(t_stack **stack);
char	*swap_b(t_stack **stack);
char	*push_a(t_stack **stack_a, t_stack **stack_b);
char	*push_b(t_stack **stack_a, t_stack **stack_b);
char	*rotate_a(t_stack **stack);
char	*rotate_b(t_stack **stack);
char	*reverse_rotate_a(t_stack **stack);
char	*reverse_rotate_b(t_stack **stack);
t_stack	*create_stack(int count, char **integers, int is_str);
t_stack	*find_max_node(t_stack *stack);
t_stack	*stklast(t_stack *stack);

#endif