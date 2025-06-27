/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:19:15 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/27 17:08:53 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Rotate stack 'a' to bring the node with index 0 to the top.
 *
 * This function finds the node with index 0 in stack 'a' and rotates
 * the stack either upwards (ra) or downwards (rra) to bring this node
 * to the top with the minimal number of rotations.
 *
 * @param stack Pointer to the stack structure containing stack 'a'.
 */
void	ft_rotate_a_to_index_0(t_stack *stack)
{
	t_node	*current;
	int		pos;
	int		size;

	current = stack->a;
	pos = 0;
	size = ft_stack_size(stack->a);
	while (current && current->index != 0)
	{
		current = current->next;
		pos++;
	}
	if (pos <= size / 2)
		while (pos-- > 0)
			ra(stack);
	else
		while (pos++ < size)
			rra(stack);
}

/**
 * @brief Pushes lower and upper indexed elements from stack a to b based on a
 *        threshold and leaves 3 elements for final sorting.
 *
 * This function is used to simplify the sorting process by pushing elements
 * with index less than or greater than a calculated threshold to stack b.
 * Only the three elements with middle-range indexes are left in stack a.
 * Final sorting of the remaining elements is done with ft_sort_three.
 *
 * @param stack Pointer to the stack structure containing stacks a and b.
 */

static void	ft_swap_dirty(t_stack *stack)
{
	int		size;
	float	k;
	int		val_min;

	k = 0.8f;
	size = ft_stack_size(stack->a);
	while (ft_stack_size(stack->a) > 3)
	{
		val_min = size - (int)((float)(ft_stack_size(stack->a) * k));
		if (val_min > size - 3)
			val_min = size - 3;
		if (stack->a->index <= val_min)
			pb(stack, 0);
		else if (stack->a->index >= size - val_min && size <= 200)
		{
			pb(stack, 0);
			rb(stack);
		}
		else
			ra(stack);
	}
	ft_sort_three(stack);
}

/**
 * @brief Sorts a large stack using indexed cost-based move strategy.
 *
 * Assigns indexes to elements in stack a, pushes elements from a to b using
 * a threshold, then iteratively calculates costs and performs optimal moves
 * until stack b is empty. Finally, rotates stack a so that index 0 is on top.
 *
 * @param stack Pointer to the stack structure containing stacks a and b.
 */
void	ft_sort_big(t_stack *stack)
{
	t_node	*best;

	ft_assign_indexes(stack->a);
	ft_swap_dirty(stack);
	while (stack->b)
	{
		ft_calculate_costs(stack);
		best = ft_find_best_move(stack);
		ft_do_best_move(stack, best);
	}
	while (stack->b)
		pa(stack, 0);
	ft_rotate_a_to_index_0(stack);
}
