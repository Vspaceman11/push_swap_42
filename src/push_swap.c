/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:24:13 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/27 14:45:45 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Entry point of push_swap program.
 *
 * Initializes the stack structure, parses input arguments into stack a,
 * and sorts the stack using an appropriate algorithm based on size.
 * Frees allocated memory before exiting.
 *
 * @param argc Number of arguments.
 * @param argv Array of argument strings.
 * @return 0 on successful completion.
 */
int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		ft_error(stack);
	ft_parser(argc, argv, stack);
	if (ft_is_sorted(stack->a))
		return (ft_free_stack(stack), 0);
	if (ft_stack_size(stack->a) == 2)
		ft_sort_two(stack);
	else if (ft_stack_size(stack->a) == 3)
		ft_sort_three(stack);
	else if (ft_stack_size(stack->a) <= 5)
		ft_sort_small(stack);
	else
		ft_sort_big(stack);
	ft_free_stack(stack);
	return (0);
}
