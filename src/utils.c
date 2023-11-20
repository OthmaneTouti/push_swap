/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:30:57 by ottouti           #+#    #+#             */
/*   Updated: 2023/11/20 13:29:52 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_integers(int count, char **integers)
{
	int		i;
	char	*str;

	i = 0;
	while (i < count)
	{
		str = integers[i];
		while (*str)
		{
			if (ft_isdigit((unsigned char) *str) == 0
				|| *str == '-' || *str == '+')
			{
				if ((*str == '-' || *str == '+')
					&& !ft_isdigit(*(str + 1)))
					return (0);
				else if (*str != '-' && *str != '+')
					return (0);
			}
			str++;
		}
		i++;
	}
	return (1);
}
