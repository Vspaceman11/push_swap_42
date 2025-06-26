/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:28:46 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/26 17:44:45 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Converts numeric part of string to a long integer.
 *
 * Iterates over the digits starting from position i and builds the number.
 *
 * @param str The input string containing digits.
 * @param i The starting index in the string.
 * @return The resulting long integer value.
 */
static long	ft_cast_to_long(const char *str, long i)
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

/**
 * @brief Converts a string to a long integer.
 *
 * Handles optional leading whitespace and one optional '+' or '-' sign.
 * Returns 0 if more than one sign character is found.
 *
 * @param str The string to convert.
 * @return The converted long integer.
 */
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
	result = ft_cast_to_long(str, i);
	if (sign < 0)
		result *= -1;
	return (result);
}

/**
 * @brief Checks if a number is already present in the stack.
 *
 * @param stack_a Pointer to the top of stack A.
 * @param num The number to check for duplicates.
 * @return 1 if the number is found, 0 otherwise.
 */
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

/**
 * @brief Checks if a string is a valid integer number.
 *
 * @param str The string to check.
 * @return 1 if the string represents a number, 0 otherwise.
 *
 * Accepts optional '+' or '-' sign followed by at least one digit.
 */
int	ft_is_number(const char *str)
{
	int	i;

	i = 0;
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

/**
 * @brief Frees a split string array.
 *
 * @param str The array of strings to be freed.
 *
 * Iterates through the array, freeing each string, and then frees the array
 * itself. Does nothing if the pointer is NULL.
 */
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
