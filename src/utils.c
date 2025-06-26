/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:54:47 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/26 17:53:08 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Check if the stack is sorted in ascending order.
 *
 * Returns 1 if the stack is sorted (each value <= next value), or 0 if not.
 * An empty stack or a single-node stack is considered sorted.
 *
 * @param stack_a Pointer to the head of the stack.
 *
 * @return int 1 if sorted, 0 otherwise.
 */
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

/**
 * @brief Assign ascending indexes to nodes in stack 'a' based on their values.
 *
 * Iteratively finds the unindexed node with the smallest value and assigns it
 * the next index, starting from 0. Stops when all nodes have been indexed.
 *
 * @param stack_a Pointer to the head of stack 'a'.
 */
void	ft_assign_indexes(t_node *stack_a)
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

/**
 * @brief Free all nodes in stacks 'a' and 'b' and the stack structure.
 *
 * Iterates through both stacks 'a' and 'b', frees all their nodes, and
 * finally frees the stack structure itself.
 *
 * @param stack Pointer to the stack structure to be freed.
 */
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

/**
 * @brief Add a new node at the end of a linked list.
 *
 * Appends new_node to the end of the list pointed to by lst. If the list
 * is empty, new_node becomes the first element.
 *
 * @param lst Pointer to the pointer of the list head.
 * @param new_node Pointer to the node to add at the end.
 */
void	ft_lstadd_back_node(t_node **lst, t_node *new_node)
{
	t_node	*current;

	if (!lst || !new_node)
		return ;
	if (!*lst)
	{
		*lst = new_node;
		return ;
	}
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = new_node;
}

/**
 * @brief Calculate the size (number of nodes) of a stack.
 *
 * Counts and returns how many nodes are in the given linked list stack.
 *
 * @param stack Pointer to the head of the stack.
 *
 * @return int Number of nodes in the stack.
 */
int	ft_stack_size(t_node *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}
