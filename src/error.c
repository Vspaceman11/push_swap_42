/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:57:36 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/26 17:54:21 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Free the stack and exit the program with an error message.
 *
 * Frees all memory allocated for the stack, writes "Error" to standard
 * error, and terminates the program with exit code 1.
 *
 * @param stack Pointer to the stack structure to free.
 */
void	ft_error(t_stack *stack)
{
	ft_free_stack(stack);
	write(2, "Error\n", 6);
	exit(1);
}

/**
 * @brief Free resources and exit the program with an error message.
 *
 * Frees a string array created by split and the stack structure, prints
 * "Error" to standard error, then terminates the program with exit code 1.
 *
 * @param stack Pointer to the stack structure to free.
 * @param split Null-terminated array of strings to free.
 */
void	ft_error_split(t_stack *stack, char **split)
{
	ft_free_split(split);
	ft_free_stack(stack);
	write(2, "Error\n", 6);
	exit(1);
}
