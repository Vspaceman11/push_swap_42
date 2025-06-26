/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:19:15 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/26 16:34:57 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_get_max_index_position(t_node *stack)
{
	int		max_index;
	int		position;
	int		i;
	t_node	*current;

	max_index = -1;
	position = 0;
	i = 0;
	current = stack;
	while (current)
	{
		if (current->index > max_index)
		{
			max_index = current->index;
			position = i;
		}
		current = current->next;
		i++;
	}
	return (position);
}

void	ft_push_back_to_a(t_stack *stack)
{
	int	position;
	int	size;

	while (stack->b)
	{
		size = ft_stack_size(stack->b);
		position = ft_get_max_index_position(stack->b);
		if (position <= size / 2)
		{
			while (position--)
				rb(stack);
		}
		else
		{
			while (position++ < size)
				rrb(stack);
		}
		pa(stack);
	}
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
