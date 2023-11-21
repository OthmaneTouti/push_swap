/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:01:29 by ottouti           #+#    #+#             */
/*   Updated: 2023/11/21 13:24:03 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "../include/libft.h"

int		validate_integers(int count, char **integers);
void 	create_node(char *integer, t_list **stack);
void	swap(t_list **stack);
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);
void	del(void *content);
t_list	*create_stack(int count, char **integers);

#endif