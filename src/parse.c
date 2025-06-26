/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:00:59 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/26 16:35:21 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_if_input_2(char **tmp, t_stack *stack)
{
	int		i;
	long	num;
	t_node	*new;

	i = 0;
	while (tmp[i])
	{
		if (!ft_is_number(tmp[i]))
			ft_error_split(stack, tmp);
		num = ft_atol(tmp[i]);
		if (num > INT_MAX || num < INT_MIN)
			ft_error_split(stack, tmp);
		if (ft_is_duplicate(stack->a, (int)num))
			ft_error_split(stack, tmp);
		new = ft_calloc(1, sizeof(t_node));
		if (!new)
			ft_error_split(stack, tmp);
		new->value = (int)num;
		new->index = -1;
		new->next = NULL;
		ft_lstadd_back_node(&stack->a, new);
		i++;
	}
}

void	ft_if_input_many_args(int argc, char **argv, t_stack *stack)
{
	int		i;
	long	num;
	t_node	*new;

	i = 1;
	while (i < argc)
	{
		if (!ft_is_number(argv[i]))
			ft_error(stack);
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			ft_error(stack);
		if (ft_is_duplicate(stack->a, (int)num))
			ft_error(stack);
		new = ft_calloc(1, sizeof(t_node));
		if (!new)
			ft_error(stack);
		new->value = (int)num;
		new->index = -1;
		new->next = NULL;
		ft_lstadd_back_node(&stack->a, new);
		i++;
	}
}

void	ft_parser(int argc, char **argv, t_stack *stack)
{
	char	**tmp;

	if (argc < 2)
		ft_error(stack);
	if (argc == 2)
	{
		tmp = ft_split(argv[1], ' ');
		if (!tmp)
		{
			free(tmp);
			ft_error(stack);
		}
		ft_if_input_2(tmp, stack);
		ft_free_split(tmp);
	}
	else
		ft_if_input_many_args(argc, argv, stack);
}
