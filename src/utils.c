/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:30:57 by ottouti           #+#    #+#             */
/*   Updated: 2023/11/21 13:55:13 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_limits(char *integer)
{
	int	ascii_sum;
	int limit;

	ascii_sum = 0;
	limit = 526;
	if (*integer == '-' || *integer == '+')
	{
		if (*integer == '-')
			limit += 1;
		integer++;
	}
	while (*integer)
	{
		ascii_sum += *integer;
		integer++;
	}
	if (ascii_sum > limit)
		return (0);
	return (1);
}

int	validate_integers(int count, char **integers)
{
	int		i;
	char	*str;

	i = 0;
	while (i < count)
	{
		str = integers[i];
		if (!check_limits(str))
			return (0);
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

void	del(void *content)
{
	if (!content)
		return ;
	free(content);
}
