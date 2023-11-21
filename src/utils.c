/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ottouti <ottouti@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:30:57 by ottouti           #+#    #+#             */
/*   Updated: 2023/11/21 14:17:31 by ottouti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(char **integers)
{
	int	i;
	int	j;

	i = 0;
	while (integers[i])
	{
		j = 0;
		while(integers[j])
		{
			if (i == j)
			{
				j++;
				continue ;
			}
			if (!ft_strncmp(integers[i], integers[j], 12))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

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
		return (1);
	return (0);
}

int	validate_integers(int count, char **integers)
{
	int		i;
	char	*str;

	i = 0;
	while (i < count)
	{
		str = integers[i];
		if (check_limits(str) || check_duplicates(integers))
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
