/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:32:56 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/23 16:18:43 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	rotate(&stack->a);
	ft_printf("ra\n");
}

void	rb(t_stack *stack)
{
	rotate(&stack->b);
	ft_printf("rb\n");
}

void	rr(t_stack *stack)
{
	rotate(&stack->a);
	rotate(&stack->b);
	ft_printf("rr\n");
}

void	rra(t_stack *stack)
{
	reverse_rotate(&stack->a);
	ft_printf("rra\n");
}

void	rrb(t_stack *stack)
{
	reverse_rotate(&stack->b);
	ft_printf("rrb\n");
}
