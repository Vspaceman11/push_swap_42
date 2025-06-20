/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:28:46 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/20 17:20:05 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static	int	ft_cast_to_int(const char *str, long i)
{
	long	result;

	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

long	ft_atol(const char *str)
{
	long	i;
	long	result;
	int		sign;
	int		sign_count;

	i = 0;
	sign = 1;
	sign_count = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		sign_count++;
		if (sign_count > 1)
			return (0);
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = ft_cast_to_int(str, i);
	if (sign < 0)
		result *= -1;
	return (result);
}

int	ft_is_duplicate(t_node *stack_a, int num)
{
	while (stack_a)
	{
		if (stack_a->value == num)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

int	ft_is_number(char *str)
{
	int	i;

	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	if (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
void	ft_free_split(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
