/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:01:18 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/27 14:37:16 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Check if the input instruction is valid.
 *
 * @param str Instruction string with newline.
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
 * @brief Execute one valid instruction on the stacks.
 *
 * @param str Instruction line (must be valid).
 * @param stack Pointer to the t_stack structure.
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
 * @brief Read and execute all instructions from stdin.
 *
 * @param stack Pointer to the t_stack structure.
 * @return 0 if OK, 1 if error.
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

int	main(int argc, char **argv)
{
	t_stack	*stack;

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
