/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:00:59 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/28 10:27:19 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Parses and validates space-separated input in one argument.
 *
 * @param tmp Array of strings resulting from splitting argv[1].
 * @param stack Pointer to the stack structure to be filled.
 *
 * This function checks each string in tmp for numeric validity, overflows, and
 * duplicates. Valid integers are added as nodes to stack A. On error, frees tmp
 * and exits the program.
 */
void	ft_if_input_2(char **tmp, t_stack *stack)
{
	int		i;
	long	num;
	t_node	*new;

	i = 0;
	while (tmp[i])
	{
		if (!ft_is_number(tmp[i]))
			ft_error_split(stack, tmp);
		num = ft_atol(tmp[i]);
		if (num > INT_MAX || num < INT_MIN)
			ft_error_split(stack, tmp);
		if (ft_is_duplicate(stack->a, (int)num))
			ft_error_split(stack, tmp);
		new = ft_calloc(1, sizeof(t_node));
		if (!new)
			ft_error_split(stack, tmp);
		new->value = (int)num;
		new->index = -1;
		new->next = NULL;
		ft_lstadd_back_node(&stack->a, new);
		i++;
	}
}

/**
 * @brief Parses multiple numeric arguments and fills stack A.
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of argument strings.
 * @param stack Pointer to the stack structure to be filled.
 *
 * This function validates and converts each argument from argv[1] to argv[i]
 * into an integer. If any argument is not a number, overflows, or duplicates an
 * existing value in stack A, the program exits with an error.
 */
void	ft_if_input_many_args(int argc, char **argv, t_stack *stack)
{
	int		i;
	long	num;
	t_node	*new;

	i = 1;
	while (i < argc)
	{
		if (!ft_is_number(argv[i]))
			ft_error(stack);
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			ft_error(stack);
		if (ft_is_duplicate(stack->a, (int)num))
			ft_error(stack);
		new = ft_calloc(1, sizeof(t_node));
		if (!new)
			ft_error(stack);
		new->value = (int)num;
		new->index = -1;
		new->next = NULL;
		ft_lstadd_back_node(&stack->a, new);
		i++;
	}
}

/**
 * @brief Parses the input arguments and fills stack A with valid integers.
 *
 * @param argc The number of arguments passed to the program.
 * @param argv The argument values passed to the program.
 * @param stack The stack structure to be filled with parsed integers.
 *
 * This function handles both types of inputs:
 * 1. Single quoted string of numbers.
 * 2. Multiple separate arguments.
 * It splits the input, validates it, and fills the stack accordingly.
 */
void	ft_parser(int argc, char **argv, t_stack *stack)
{
	char	**tmp;

	if (argc == 2)
	{
		tmp = ft_split(argv[1], ' ');
		if (!tmp)
		{
			free(tmp);
			ft_error(stack);
		}
		ft_if_input_2(tmp, stack);
		ft_free_split(tmp);
	}
	else
		ft_if_input_many_args(argc, argv, stack);
}
