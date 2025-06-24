/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:08:32 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/24 15:50:34 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_stack *stack)
{
	if (stack->a->value > stack->a->next->value)
		sa(stack);
}

void	ft_sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->a->value;
	b = stack->a->next->value;
	c = stack->a->next->next->value;
	if (a < b && b < c)
		return ;
	if (a > b && b < c && a < c)
		sa(stack);
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack);
	}
	else if (a > b && b > c && a > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a < b && b > c && a > c)
		rra(stack);
}

int	ft_find_min(t_node *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	ft_find_position(t_node *stack, int value)
{
	int	position;

	position = 0;
	while (stack)
	{
		if (stack->value == value)
			return (position);
		stack = stack->next;
		position++;
	}
	return (-1);
}

void	ft_sort_small(t_stack *stack)
{
	int	size;
	int	min;
	int	position;

	size = ft_stack_size(stack->a);
	while (ft_stack_size(stack->a) > 3)
	{
		min = ft_find_min(stack->a);
		position = ft_find_position(stack->a, min);
		if (position <= ft_stack_size(stack->a) / 2)
			while (stack->a->value != min)
				ra(stack);
		else
			while (stack->a->value != min)
				rra(stack);
		pb(stack);
	}
	ft_sort_three(stack);
	while (stack->b)
		pa(stack);
}
