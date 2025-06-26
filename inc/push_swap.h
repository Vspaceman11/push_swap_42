/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpushkar <vpushkar@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:33:27 by vpushkar          #+#    #+#             */
/*   Updated: 2025/06/26 16:27:09 by vpushkar         ###   ########.fr       */
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
	int				cost_a;
	int				cost_b;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*a;
	t_node	*b;
	int		size;
}	t_stack;

// error.c
void	ft_error(t_stack *stack);
void	ft_error_split(t_stack *stack, char **split);
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
void	ft_assign_indexes(t_node *stack_a);
void	ft_free_stack(t_stack *stack);
void	ft_lstadd_back_node(t_node **lst, t_node *new_node);
int		ft_stack_size(t_node *stack);

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

// sort_small.c
void	ft_sort_two(t_stack *stack);
void	ft_sort_three(t_stack *stack);
void	ft_sort_small(t_stack *stack);
int		ft_find_position(t_node *stack, int value);
int		ft_find_min(t_node *stack);

// sort_big.c
void	ft_push_chunks(t_stack *stack, int chunk_count);
int		ft_get_max_index_position(t_node *stack);
void	ft_push_back_to_a(t_stack *stack);
void	ft_sort_big(t_stack *stack);

// sort_big_utils.c
int		ft_get_position_of_min_index(t_node *stack);
int		ft_get_node_position(t_node *stack, t_node *target);
int		ft_get_cost_to_top(t_node *stack, t_node *target, int size);
int		ft_get_target_cost(t_node *a, int b_index, int size);
void	ft_calculate_costs(t_stack *stack);

// sort_big_utils_2.c
t_node	*ft_find_best_move(t_stack *stack);
void	ft_do_best_move(t_stack *stack, t_node *target);
// sort_big_utils_3.c
int		ft_get_chunk_count(t_stack *stack);
void	ft_rotate_a_to_index_0(t_stack *stack);
t_node	*ft_get_node_with_min_index(t_node *stack);

#endif
