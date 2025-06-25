/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:19:06 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/25 18:09:14 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_chunk_count(t_stack *stack)
{
	// int	size;

	// size = ft_stack_size(stack->a);
	// if (size <= 100)
	// 	return (size / 20);
	// else
	// 	return (size / 25);
	int	size = ft_stack_size(stack->a);
	if (size <= 1)
		return (1);
	if (size <= 100)
		return (5);
	else
		return (11);
}

void	rotate_a_to_index_0(t_stack *stack)
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

t_node	*get_node_with_min_index(t_node *stack)
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
