/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:19:15 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/27 13:42:03 by vpushkar         ###   ########.fr       */
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
 * @brief Pushes elements from stack A to B in sorted chunks.
 *
 * Uses a float ratio to determine value thresholds and pushes smaller
 * elements to stack B. Larger elements are rotated to bottom in B if
 * conditions match. Leaves 3 elements in A and sorts them.
 *
 * @param stack The stack structure with stacks A and B.
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
		if (stack->a->value <= val_min)
			pb(stack, 0);
		else if (stack->a->value >= size - val_min && size <= 200)
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
 * @brief Sorts large stack using cost-based insertion method.
 *
 * Assigns indexes, pushes elements to stack B using sorted chunks,
 * calculates optimal move costs, and reinserts them into stack A.
 * Finishes by rotating A so that the smallest index is on top.
 *
 * @param stack The stack structure containing stacks A and B.
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
