/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:19:15 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/26 17:28:35 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			pb(stack);
		else if (stack->a->value >= size - val_min && size <= 200)
		{
			pb(stack);
			rb(stack);
		}
		else
			ra(stack);
	}
	ft_sort_three(stack);
}

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
		pa(stack);
	ft_rotate_a_to_index_0(stack);
}
