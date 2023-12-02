/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:01:29 by ottouti           #+#    #+#             */
/*   Updated: 2023/12/01 20:15:51 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "../include/libft.h"
# include <stdbool.h>
# include <limits.h>

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
void	stkclear(t_stack **stack);
void	stkadd_back(t_stack **lst, t_stack *new);
void	sort(t_stack **stack_a, t_stack **stack_b);
void	tiny_sort(t_stack **stack_a);
void	init_nodes_a(t_stack *stack_a, t_stack *stack_b);
void	init_nodes_b(t_stack *stack_a, t_stack *stack_b);
void	find_target_a(t_stack *stack_a, t_stack *stack_b);
void	find_target_b(t_stack *stack_a, t_stack *stack_b);
void	find_index(t_stack *stack);
void	find_cost(t_stack *stack_a, t_stack *stack_b);
void	find_cheapest(t_stack *stack);
void	move_a_to_b(t_stack **stack_a, t_stack **stack_b);
void	move_b_to_a(t_stack **stack_a, t_stack **stack_b);
void	rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest);
void	rev_rotate_both(t_stack **stack_a, t_stack **stack_b,
						t_stack *cheapest);
void	swap_a(t_stack **stack);
void	swap_b(t_stack **stack);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	prep_for_push(t_stack **stack, t_stack *top_node, char name);
void	rotate_a(t_stack **stack, bool print);
void	rotate_b(t_stack **stack, bool print);
void	reverse_rotate_a(t_stack **stack, bool print);
void	reverse_rotate_b(t_stack **stack, bool print);
t_stack	*create_stack(int count, char **integers, int is_str);
t_stack	*find_max_node(t_stack *stack);
t_stack	*find_min_node(t_stack *stack);
t_stack	*stklast(t_stack *stack);
t_stack *get_cheapest(t_stack *stack);

#endif