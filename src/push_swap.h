/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:01:29 by ottouti           #+#    #+#             */
/*   Updated: 2023/11/27 13:44:07 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "../include/libft.h"

int		validate_integers(int count, char **integers);
int		check_limits(char *integer);
int		check_duplicates(char **integers);
void 	create_node(char *integer, t_list **stack);
void	del(void *content);
void	sort(t_list **stack_a, t_list **stack_b, t_list **inst);
void	write_inst(char *inst, t_list **insts);
void	tiny_sort(t_list **stack_a, t_list **insts);
void	insert_sort(t_list **stack_a, t_list **stack_b, t_list **insts);
char	*swap_a(t_list **stack);
char	*swap_b(t_list **stack);
char	*push_a(t_list **stack_a, t_list **stack_b);
char	*push_b(t_list **stack_a, t_list **stack_b);
char	*rotate_a(t_list **stack);
char	*rotate_b(t_list **stack);
char	*reverse_rotate_a(t_list **stack);
char	*reverse_rotate_b(t_list **stack);
t_list	*create_stack(int count, char **integers, int is_str);
t_list	*find_max_node(t_list *stack);

#endif