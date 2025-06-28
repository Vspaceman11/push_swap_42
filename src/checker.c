/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:01:18 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/28 10:44:33 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Checks if the given string is a valid stack operation.
 *
 * Compares the input string to all valid push_swap instructions.
 * If the instruction is valid, returns 0.
 * Otherwise, writes "Error\n" to stderr and returns 1.
 *
 * @param str The instruction string to validate (must end with '\n').
 * @return 0 if valid, 1 if invalid.
 */
static int	ft_check_moves(char *str)
{
	if (
		ft_strncmp(str, "sa\n", 3) == 0
		|| ft_strncmp(str, "sb\n", 3) == 0
		|| ft_strncmp(str, "ss\n", 3) == 0
		|| ft_strncmp(str, "pa\n", 3) == 0
		|| ft_strncmp(str, "pb\n", 3) == 0
		|| ft_strncmp(str, "ra\n", 3) == 0
		|| ft_strncmp(str, "rb\n", 3) == 0
		|| ft_strncmp(str, "rr\n", 3) == 0
		|| ft_strncmp(str, "rra\n", 4) == 0
		|| ft_strncmp(str, "rrb\n", 4) == 0
		|| ft_strncmp(str, "rrr\n", 4) == 0
	)
		return (0);
	return (write(2, "Error\n", 6), 1);
}

/**
 * @brief Executes additional stack operations not handled by ft_execute_move.
 *
 * This function handles rotate and reverse rotate operations for stacks a
 * and b, as well as simultaneous operations ("rr", "rrr") based on the input
 * string. It is called if the instruction was not handled in ft_execute_move.
 *
 * @param str   The instruction string (e.g., "rb\n", "rrr\n", etc.).
 * @param stack Pointer to the t_stack structure containing both stacks.
 */
static void	ft_execute_move_2(char *str, t_stack *stack)
{
	if (ft_strncmp(str, "rb\n", 3) == 0)
		rotate(&stack->b);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
	{
		rotate(&stack->a);
		rotate(&stack->b);
	}
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		reverse_rotate(&stack->a);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		reverse_rotate(&stack->b);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
	{
		reverse_rotate(&stack->a);
		reverse_rotate(&stack->b);
	}
}

/**
 * @brief Executes a single stack operation based on the input string.
 *
 * This function compares the given string to valid stack operation
 * commands (like "sa", "pb", etc.) and performs the corresponding
 * action on the provided stack structure.
 *
 * Operations handled here include swaps and pushes. If the instruction
 * is not matched in this function, it is passed to ft_execute_move_2.
 *
 * @param str   The instruction string (e.g., "sa\n", "pb\n", etc.).
 * @param stack Pointer to the t_stack structure containing both stacks.
 */
static void	ft_execute_move(char *str, t_stack *stack)
{
	if (ft_strncmp(str, "sa\n", 3) == 0)
		swap(stack->a);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		swap(stack->b);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
	{
		swap(stack->a);
		swap(stack->b);
	}
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		pa(stack, 1);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		pb(stack, 1);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		rotate(&stack->a);
	else
		ft_execute_move_2(str, stack);
}

/**
 * @brief Reads and applies stack operations from standard input.
 *
 * This function reads one instruction per line from stdin and executes
 * it on the provided stacks. If an invalid instruction is found, it stops
 * and returns 1. Otherwise, it continues until EOF and returns 0.
 *
 * @param stack Pointer to the t_stack structure (stack a and stack b).
 * @return 0 on success, 1 if an invalid instruction was encountered.
 */
static int	ft_get_move(t_stack *stack)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (ft_check_moves(line))
		{
			free(line);
			return (1);
		}
		ft_execute_move(line, stack);
		free(line);
		line = get_next_line(0);
	}
	return (0);
}

/**
 * @brief Entry point for the checker program.
 *
 * Allocates and initializes the stacks, parses the input arguments into
 * stack a, then reads and executes moves from standard input. After
 * executing all moves, it checks if stack a is sorted and stack b is empty.
 * Prints "OK" if sorted, "KO" otherwise. Frees all allocated memory before
 * exiting.
 *
 * @param argc Number of command line arguments.
 * @param argv Array of command line argument strings.
 * @return 0 on success, 1 if an error occurs (invalid move or input).
 */
int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc < 2)
		return (0);
	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		ft_error(stack);
	ft_parser(argc, argv, stack);
	if (ft_get_move(stack))
		return (ft_free_stack(stack), 1);
	if (ft_is_sorted(stack->a) && !stack->b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_stack(stack);
	return (0);
}
