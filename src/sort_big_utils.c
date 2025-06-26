/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:43:32 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/26 17:49:16 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Find the node with the minimum index in a stack.
 *
 * Traverses the stack to locate the node that has the smallest index value.
 * Returns a pointer to this node.
 *
 * @param stack Pointer to the head of the stack.
 *
 * @return t_node* Pointer to the node with the minimum index.
 */
t_node	*ft_get_node_with_min_index(t_node *stack)
{
	t_node	*min;

	min = stack;
	while (stack)
	{
		if (stack->index < min->index)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

/**
 * @brief Get the zero-based position of a target node in a stack.
 *
 * Iterates through the stack to find the position of the target node.
 * Returns the index (starting from 0) where the target node is found.
 *
 * @param stack Pointer to the head of the stack.
 * @param target Pointer to the node whose position is to be found.
 *
 * @return int Position of the target node in the stack.
 */
int	ft_get_node_position(t_node *stack, t_node *target)
{
	int	position;

	position = 0;
	while (stack && stack != target)
	{
		stack = stack->next;
		position++;
	}
	return (position);
}

/**
 * @brief Calculate the cost to bring a target node to the top of a stack.
 *
 * Computes the minimal number of rotations needed to move the target node
 * to the top of the given stack. Positive cost means rotate up, negative
 * means rotate down.
 *
 * @param stack Pointer to the head of the stack.
 * @param target Pointer to the target node within the stack.
 * @param size Size of the stack.
 *
 * @return int Number of moves (positive or negative) to bring target to top.
 */
int	ft_get_cost_to_top(t_node *stack, t_node *target, int size)
{
	int		position;

	position = ft_get_node_position(stack, target);
	if (position <= size / 2)
		return (position);
	else
		return (position - size);
}

/**
 * @brief Calculate cost to insert a node from stack 'b' into stack 'a'.
 *
 * Finds the target node in stack 'a' which has the smallest index greater
 * than b_index. If none is found, selects the node with the minimal index.
 * Calculates the cost (number of moves) to bring the target node to the top
 * of stack 'a'. The cost is positive if rotation up is shorter, negative
 * if rotation down is shorter.
 *
 * @param a Pointer to the head of stack 'a'.
 * @param b_index Index of the node from stack 'b'.
 * @param size Size of stack 'a'.
 *
 * @return int Cost to bring target node to top of stack 'a'.
 */
int	ft_get_target_cost(t_node *a, int b_index, int size)
{
	t_node	*current;
	t_node	*target;
	int		position;

	current = a;
	target = NULL;
	while (current)
	{
		if (current->index > b_index
			&& (!target || current->index < target->index))
			target = current;
		current = current->next;
	}
	if (!target)
		target = ft_get_node_with_min_index(a);
	position = ft_get_node_position(a, target);
	if (position <= size / 2)
		return (position);
	else
		return (position - size);
}

/**
 * @brief Calculate the operation costs for each node in stack 'b'.
 *
 * For every node in stack 'b', calculates the cost to bring it to the
 * top of stack 'b' and the cost to position it correctly in stack 'a'.
 * The results are stored in the node's cost_b and cost_a fields.
 *
 * @param stack Pointer to the stack structure containing stacks 'a' and 'b'.
 */
void	ft_calculate_costs(t_stack *stack)
{
	t_node	*current;
	int		size_a;
	int		size_b;

	size_a = ft_stack_size(stack->a);
	size_b = ft_stack_size(stack->b);
	current = stack->b;
	while (current)
	{
		current->cost_b = ft_get_cost_to_top(stack->b, current, size_b);
		current->cost_a = ft_get_target_cost(stack->a, current->index, size_a);
		current = current->next;
	}
}
