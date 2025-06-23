/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:54:47 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/23 14:58:46 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_node *stack_a)
{
	t_node	*current;

	if (!stack_a || !stack_a->next)
		return (1);
	current = stack_a;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	assign_indexes(t_node *stack_a)
{
	t_node	*current;
	t_node	*min_node;
	int		index;

	index = 0;
	while (1)
	{
		current = stack_a;
		min_node = NULL;
		while (current)
		{
			if (current->index == -1 && (!min_node
					|| current->value < min_node->value))
				min_node = current;
			current = current->next;
		}
		if (!min_node)
			break ;
		min_node->index = index;
		index++;
	}
}

void	ft_free_stack(t_stack *stack)
{
	t_node	*temp;

	if (stack->a)
	{
		while (stack->a)
		{
			temp = stack->a;
			stack->a = stack->a->next;
			free(temp);
		}
	}
	if (stack->b)
	{
		while (stack->b)
		{
			temp = stack->b;
			stack->b = stack->b->next;
			free(temp);
		}
	}
	free(stack);
}
