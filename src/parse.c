/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:00:59 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/20 17:20:50 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_if_input_2(char **argv, t_stack *stack)
{
	int		i;
	int		num;
	char	**tmp;
	t_node	*new;

	i = 0;
	tmp = ft_split(argv[1], ' ');
	if (!tmp)
	{
		free(tmp);
		ft_error();
	}
	while (tmp[i])
	{
		if (!ft_is_number(tmp[i]))
			ft_error();
		num = ft_atol(tmp[i]);
		if (num > INT_MAX || num < INT_MIN)
			ft_error();
		if (ft_is_duplicate(stack->a, num))
			ft_error();
		new = ft_calloc(1, sizeof(t_node));
		if (!new)
			ft_error();
		new->value = (int)num;
		new->index = -1;
		new->next = NULL;
		ft_lstadd_back(&stack->a, new);
		i++;
	}
	ft_free_split(tmp);
}

int	ft_parser(int argc, char **argv, t_stack *stack)
{
	int i;

	i = 1;
	if (argc < 1)
		return (ft_error(), 1);
	if (argc == 2)
	{
		ft_if_input_2(argv, stack);
	}
	while (i < argc)
	{

		i++;
	}
}
