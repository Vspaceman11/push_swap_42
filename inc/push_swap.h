/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:33:27 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/23 16:37:44 by vpushkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// include

# include <unistd.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

// struct
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*a;
	t_node	*b;
	int		size;
}	t_stack;

// error.c
void	ft_error(void);
// parse.c
void	ft_parser(int argc, char **argv, t_stack *stack);
void	ft_if_input_2(char **tmp, t_stack *stack);
void	ft_if_input_many_args(int argc, char **argv, t_stack *stack);

// parse_utils.c
int		ft_is_duplicate(t_node *stack_a, int num);
long	ft_atol(const char *str);
int		ft_is_number(const char *str);
void	ft_free_split(char **str);

// utils.c
int		ft_is_sorted(t_node *stack_a);
void	assign_indexes(t_node *stack_a);
void	ft_free_stack(t_stack *stack);

// operations_1.c
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);
void	pa(t_stack *stack);
void	pb(t_stack *stack);

// operations_2.c
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);

// operations_3.c
void	rrr(t_stack *stack);
void	swap(t_node *stack);
void	rotate(t_node **head);
void	reverse_rotate(t_node **head);
#endif
