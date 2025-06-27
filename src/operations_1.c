/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:32:58 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/27 13:40:53 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	swap(stack->a);
	ft_printf("sa\n");
}

void	sb(t_stack *stack)
{
	swap(stack->b);
	ft_printf("sb\n");
}

void	ss(t_stack *stack)
{
	swap(stack->a);
	swap(stack->b);
	ft_printf("ss\n");
}

void	pa(t_stack *stack, int helper)
{
	t_node	*top;

	if (!stack->b)
		return ;
	top = stack->b;
	stack->b = stack->b->next;
	top->next = stack->a;
	stack->a = top;
	if (helper == 0)
		ft_printf("pa\n");
}

void	pb(t_stack *stack, int helper)
{
	t_node	*top;

	if (!stack->a)
		return ;
	top = stack->a;
	stack->a = stack->a->next;
	top->next = stack->b;
	stack->b = top;
	if (helper == 0)
		ft_printf("pb\n");
}
