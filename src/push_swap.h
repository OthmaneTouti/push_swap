/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:01:29 by ottouti           #+#    #+#             */
/*   Updated: 2023/11/20 15:20:54 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "../include/libft.h"

int		validate_integers(int count, char **integers);
void 	create_node(char *integer, t_list **stack, int is_a);
void	swap(t_list **stack);
t_list	*create_stack(int count, char **integers, int is_a);

#endif