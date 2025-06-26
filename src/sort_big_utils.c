/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:43:32 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/26 17:28:58 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_get_cost_to_top(t_node *stack, t_node *target, int size)
{
	int		position;

	position = ft_get_node_position(stack, target);
	if (position <= size / 2)
		return (position);
	else
		return (position - size);
}

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
