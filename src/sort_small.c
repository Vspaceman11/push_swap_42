/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:08:32 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/27 13:42:13 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Sort exactly two elements in stack 'a'.
 *
 * Swaps the two elements if they are in the wrong order.
 *
 * @param stack Pointer to the stack structure containing stack 'a'.
 */
void	ft_sort_two(t_stack *stack)
{
	if (stack->a->value > stack->a->next->value)
		sa(stack);
}

/**
 * @brief Sort exactly three elements in stack 'a'.
 *
 * Uses a minimal sequence of swap and rotate operations to sort three
 * elements in ascending order.
 *
 * @param stack Pointer to the stack structure containing stack 'a'.
 */
void	ft_sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->a->value;
	b = stack->a->next->value;
	c = stack->a->next->next->value;
	if (a < b && b < c)
		return ;
	if (a > b && b < c && a < c)
		sa(stack);
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack);
	}
	else if (a > b && b > c && a > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a < b && b > c && a > c)
		rra(stack);
}

/**
 * @brief Find the minimum value in the stack.
 *
 * Iterates through the stack to locate and return the smallest value.
 *
 * @param stack Pointer to the head of the stack.
 *
 * @return int The minimum value found in the stack.
 */
int	ft_find_min(t_node *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

/**
 * @brief Find the position of a node with a given value in the stack.
 *
 * Traverses the stack and returns the zero-based position of the first node
 * whose value equals the given value. Returns -1 if the value is not found.
 *
 * @param stack Pointer to the head of the stack.
 * @param value The value to search for.
 *
 * @return int Position of the node with the given value, or -1 if not found.
 */
int	ft_find_position(t_node *stack, int value)
{
	int	position;

	position = 0;
	while (stack)
	{
		if (stack->value == value)
			return (position);
		stack = stack->next;
		position++;
	}
	return (-1);
}

/**
 * @brief Sort a small stack by pushing minimum elements to stack 'b'.
 *
 * While stack 'a' has more than 3 elements, finds the minimum value, rotates
 * stack 'a' to bring it to the top, and pushes it to stack 'b'. Then sorts
 * the remaining 3 elements in stack 'a' and finally pushes back all elements
 * from 'b' to 'a'.
 *
 * @param stack Pointer to the stack structure containing stacks 'a' and 'b'.
 */
void	ft_sort_small(t_stack *stack)
{
	int	min;
	int	position;

	while (ft_stack_size(stack->a) > 3)
	{
		min = ft_find_min(stack->a);
		position = ft_find_position(stack->a, min);
		if (position <= ft_stack_size(stack->a) / 2)
			while (stack->a->value != min)
				ra(stack);
		else
			while (stack->a->value != min)
				rra(stack);
		pb(stack, 0);
	}
	ft_sort_three(stack);
	while (stack->b)
		pa(stack, 0);
}
