/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvemba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:06:18 by dvemba            #+#    #+#             */
/*   Updated: 2024/10/02 14:07:28 by dvemba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <errno.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
}					t_stack;

typedef struct s_variables
{
	char			**matriz_number;
	int				*list_number;
	int				size_of_list;
}					t_variables;

t_stack				*create_new_stack(int number);
void				swap(int *a, int *b);
void				sa(t_stack **a, int i);
void				sb(t_stack **b, int i);
void				ss(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				ra(t_stack **a, int i);
void				rb(t_stack **b, int i);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a, int i);
void				rrb(t_stack **b, int i);
void				rrr(t_stack **a, t_stack **b);
void				sort_2_element(t_stack **stack_a);
void				sort_3_element(t_stack **stack_a);
void				sort_4_and_5_element(t_stack **stack_a, t_stack **stack_b);
void				add_new_node(t_stack **head, int number);
void				print_stack(t_stack *stack);
void				validation_duplicate_numbers(t_variables *variables);
void				free_stack(t_stack *stack);
void				free_variables(t_variables *variables);
void				free_matriz(char **mat);
void				validation_number_2_args(t_variables *variables, int ac,
						char **av);
void				init_stack(t_stack **stack_a, t_variables *variables);
void				validation_number(t_variables *variables, const char *str);
void				radix_sort(t_stack **stack_a, t_stack **stack_b, int size);
int					*convert_number_to_int(t_variables *variables);
int					ft_atol(const char *str);
int					ft_stack_size(t_stack *stack);
int					get_position_min_in_stack(t_stack *stack);
int					is_sorted(t_stack *a);
int					get_max_bits(t_stack *stack);
#endif
