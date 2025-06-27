/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:32:58 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/27 14:44:38 by vpushkar         ###   ########.fr       */
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

/**
 * @brief Pushes the top element from stack b to stack a.
 *
 * Removes the first node from stack b and adds it to the top of stack a.
 * If the helper flag is 0, prints "pa" to the standard output.
 *
 * @param stack  Pointer to the t_stack structure containing both stacks.
 * @param helper Flag to suppress printing (0 = print, 1 = silent).
 */
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

/**
 * @brief Pushes the top element from stack a to stack b.
 *
 * Removes the first node from stack a and adds it to the top of stack b.
 * If the helper flag is 0, prints "pb" to the standard output.
 *
 * @param stack  Pointer to the t_stack structure containing both stacks.
 * @param helper Flag to suppress printing (0 = print, 1 = silent).
 */
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
