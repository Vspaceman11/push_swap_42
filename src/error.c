/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:57:36 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/26 16:11:32 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_stack *stack)
{
	ft_free_stack(stack);
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_error_split(t_stack *stack, char **split)
{
	ft_free_split(split);
	ft_free_stack(stack);
	write(2, "Error\n", 6);
	exit(1);
}
