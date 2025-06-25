/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:19:15 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/25 18:30:28 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_max_node(t_node *stack)
{
	t_node	*max = stack;
	while (stack)
	{
		if (stack->index > max->index)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

void	push_descending_to_b(t_stack *stack)
{
	t_node	*max;
	int		size;

	size = ft_stack_size(stack->a);
	while (size > 3)
	{
		max = get_max_node(stack->a);
		int pos = ft_get_node_position(stack->a, max);
		if (pos <= size / 2)
			while (stack->a != max)
				ra(stack);
		else
			while (stack->a != max)
				rra(stack);
		pb(stack);
		size--;
	}
}



// static void	ft_update_chunk(int *min, int *max, int chunk_size, int size)
// {
// 	*min += chunk_size;
// 	*max += chunk_size;
// 	if (*max > size)
// 		*max = size;
// }

// void	ft_push_chunks(t_stack *stack, int chunk_count)
// {
// 	int		size;
// 	int		chunk_size;
// 	int		current_max;
// 	int		current_min;
// 	t_node	*head;

// 	size = ft_stack_size(stack->a);
// 	chunk_size = size / chunk_count;
// 	current_max = chunk_size;
// 	current_min = 0;

// 	while (stack->a)
// 	{
// 		head = stack->a;
// 		if (head->index >= current_min && head->index < current_max)
// 		{
// 			pb(stack);
// 			if (stack->b && stack->b->index < (current_min + current_max))
// 				rb(stack);
// 		}
// 		else
// 			ra(stack);
// 		if (ft_stack_size(stack->b) >= current_max)
// 			ft_update_chunk(&current_min, &current_max, chunk_size, size);
// 	}
// }

int	get_max_index_position(t_node *stack)
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
		position = get_max_index_position(stack->b);
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

void	turk_sort(t_stack *stack)
{
	t_node	*best;
	int	size;

	ft_assign_indexes(stack->a);
	// ft_push_chunks(stack, ft_get_chunk_count(stack));
	// push_descending_to_b(stack);
	while ((size = ft_stack_size(stack->a)) > 3)
	{
		pb(stack);
	}
	ft_sort_three(stack);
	while (stack->b)
	{
		ft_calculate_costs(stack);
		best = ft_find_best_move(stack);
		ft_do_best_move(stack, best);
	}
	while (stack->b)
		pa(stack);
	rotate_a_to_index_0(stack);
}

