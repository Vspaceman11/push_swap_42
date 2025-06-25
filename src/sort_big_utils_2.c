/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:04:25 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/25 16:59:52 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

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
