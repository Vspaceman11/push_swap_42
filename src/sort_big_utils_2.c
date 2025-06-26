/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:04:25 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/26 17:50:46 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Return the absolute value of an integer.
 *
 * If the input number is negative, returns its negation; otherwise,
 * returns the number itself.
 *
 * @param n Integer value.
 *
 * @return int Absolute value of n.
 */
static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

/**
 * @brief Find the node in stack 'b' with the lowest total move cost.
 *
 * Iterates through all nodes in stack 'b' to find the one whose combined
 * cost (cost_a + cost_b) is minimal. Returns a pointer to this node.
 *
 * @param stack Pointer to the stack structure containing stack 'b'.
 *
 * @return t_node* Pointer to the node with the lowest total cost.
 */
t_node	*ft_find_best_move(t_stack *stack)
{
	t_node	*current;
	t_node	*best;
	int		best_cost;
	int		current_cost;

	best = NULL;
	best_cost = INT_MAX;
	current = stack->b;
	while (current)
	{
		current_cost = ft_abs(current->cost_a) + ft_abs(current->cost_b);
		if (current_cost < best_cost)
		{
			best_cost = current_cost;
			best = current;
		}
		current = current->next;
	}
	return (best);
}

/**
 * @brief Rotate stack 'a' up or down based on the given cost.
 *
 * Executes 'ra' rotations if cost is positive, or 'rra' rotations if cost
 * is negative, until the cost becomes zero.
 *
 * @param stack Pointer to the stack structure containing stack 'a'.
 * @param cost Number of rotations: positive for 'ra', negative for 'rra'.
 */
static void	do_rotate_a(t_stack *stack, int cost)
{
	while (cost > 0)
	{
		ra(stack);
		cost--;
	}
	while (cost < 0)
	{
		rra(stack);
		cost++;
	}
}

/**
 * @brief Rotate stack 'b' up or down according to the given cost.
 *
 * Performs 'rb' rotations if cost is positive, or 'rrb' rotations if cost
 * is negative, until the cost reaches zero.
 *
 * @param stack Pointer to the stack structure containing stack 'b'.
 * @param cost Number of rotations: positive for 'rb', negative for 'rrb'.
 */
static void	do_rotate_b(t_stack *stack, int cost)
{
	while (cost > 0)
	{
		rb(stack);
		cost--;
	}
	while (cost < 0)
	{
		rrb(stack);
		cost++;
	}
}

/**
 * @brief Execute the most efficient sequence of moves to push target from
 *        stack 'b' to stack 'a'.
 *
 * Combines simultaneous rotations (rr or rrr) when possible to minimize
 * total moves. Then performs remaining rotations on each stack separately,
 * and finally pushes the target node from 'b' to 'a'.
 *
 * @param stack Pointer to the stack structure containing stacks 'a' and 'b'.
 * @param target Pointer to the target node in stack 'b' to move.
 */
void	ft_do_best_move(t_stack *stack, t_node *target)
{
	int	cost_a;
	int	cost_b;

	cost_a = target->cost_a;
	cost_b = target->cost_b;
	while (cost_a > 0 && cost_b > 0)
	{
		rr(stack);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(stack);
		cost_a++;
		cost_b++;
	}
	do_rotate_a(stack, cost_a);
	do_rotate_b(stack, cost_b);
	pa(stack);
}
