/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:24:13 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/24 16:57:44 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *stack, char name)
{
	ft_printf("Stack %c: ", name);
	while (stack)
	{
		ft_printf("%d ", stack->value);
		stack = stack->next;
	}
	ft_printf("\n");
}

// void	test_operations(void)
// {
// 	t_stack *stack = ft_calloc(1, sizeof(t_stack));
// 	t_node *n1 = ft_calloc(1, sizeof(t_node));
// 	t_node *n2 = ft_calloc(1, sizeof(t_node));
// 	t_node *n3 = ft_calloc(1, sizeof(t_node));
// 	t_node *n4 = ft_calloc(1, sizeof(t_node));

// 	n1->value = 10;
// 	n2->value = 20;
// 	n3->value = 30;
// 	n4->value = 40;

// 	n1->next = n2;
// 	n2->next = n3;
// 	n3->next = n4;
// 	stack->a = n1;

// 	ft_printf("=== Initial ===\n");
// 	print_stack(stack->a, 'A');
// 	print_stack(stack->b, 'B');

// 	pb(stack);
// 	print_stack(stack->a, 'A');
// 	print_stack(stack->b, 'B');
// 	pb(stack);
// 	print_stack(stack->a, 'A');
// 	print_stack(stack->b, 'B');
// 	// pb(stack);
// 	// print_stack(stack->a, 'A');
// 	// print_stack(stack->b, 'B');

// 	sb(stack);
// 	print_stack(stack->a, 'A');
// 	print_stack(stack->b, 'B');

// 	rb(stack);
// 	print_stack(stack->a, 'A');
// 	print_stack(stack->b, 'B');

// 	rrb(stack);
// 	print_stack(stack->a, 'A');
// 	print_stack(stack->b, 'B');

// 	ss(stack);
// 	print_stack(stack->a, 'A');
// 	print_stack(stack->b, 'B');

// 	rr(stack);
// 	print_stack(stack->a, 'A');
// 	print_stack(stack->b, 'B');
// 	rrr(stack);
// 	print_stack(stack->a, 'A');
// 	print_stack(stack->b, 'B');

// 	ft_free_stack(stack);
// }

int	main(int argc, char **argv)
{
	t_stack	*stack;
	int	size;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		ft_error();
	ft_parser(argc, argv, stack);
	size = ft_stack_size(stack->a);
	if (ft_stack_size(stack->a) == 2)
		ft_sort_two(stack);
	else if (ft_stack_size(stack->a) == 3)
		ft_sort_three(stack);
	else if (ft_stack_size(stack->a) <= 5)
		ft_sort_small(stack);
	else
		turk_sort(stack);
	print_stack(stack->a, 'A');
	print_stack(stack->b, 'B');
	// test_operations();
	ft_free_stack(stack);
	return (0);
}

