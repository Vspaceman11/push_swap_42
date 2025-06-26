/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:32:54 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/26 17:53:54 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack *stack)
{
	reverse_rotate(&stack->a);
	reverse_rotate(&stack->b);
	ft_printf("rrr\n");
}

/**
 * @brief Swap the first two nodes' values and indexes in the stack.
 *
 * Exchanges the value and index fields of the first two nodes in the stack.
 * Does nothing if the stack has fewer than two nodes.
 *
 * @param stack Pointer to the head node of the stack.
 */
void	swap(t_node *stack)
{
	int	tmp_value;
	int	tmp_index;

	if (!stack || !stack->next)
		return ;
	tmp_value = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp_value;
	tmp_index = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp_index;
}

/**
 * @brief Perform a rotate operation on a linked list.
 *
 * Moves the first node of the list to the end, effectively rotating the list
 * up by one position. Does nothing if the list is empty or has one node.
 *
 * @param head Pointer to the pointer of the head node of the list.
 */
void	rotate(t_node **head)
{
	t_node	*first;
	t_node	*last;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	*head = (*head)->next;
	last = *head;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

/**
 * @brief Perform a reverse rotate on a linked list.
 *
 * Moves the last node of the list to the front, effectively rotating the
 * list down by one position. Does nothing if the list is empty or has one node.
 *
 * @param head Pointer to the pointer of the head node of the list.
 */
void	reverse_rotate(t_node **head)
{
	t_node	*prev;
	t_node	*last;

	if (!*head || !(*head)->next)
		return ;
	prev = *head;
	while (prev->next && prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *head;
	*head = last;
}
