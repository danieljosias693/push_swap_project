/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvemba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:37:43 by dvemba            #+#    #+#             */
/*   Updated: 2024/10/02 17:44:35 by dvemba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_push_swap(t_variables *variables)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	init_stack(&stack_a, variables);
	if (ft_stack_size(stack_a) == 2)
		sort_2_element(&stack_a);
	else if (ft_stack_size(stack_a) == 3)
		sort_3_element(&stack_a);
	else if (ft_stack_size(stack_a) >= 4 && ft_stack_size(stack_a) <= 5)
		sort_4_and_5_element(&stack_a, &stack_b);
	else if (ft_stack_size(stack_a) > 5)
		radix_sort(&stack_a, &stack_b, ft_stack_size(stack_a));
	free_stack(stack_a);
}

int	main(int ac, char **av)
{
	t_variables	*variables;

	variables = (t_variables *)malloc(sizeof(t_variables));
	variables->matriz_number = NULL;
	variables->list_number = NULL;
	if (ac < 2)
		return (free_variables(variables), 0);
	else if (ac == 2)
	{
		validation_number(variables, av[1]);
		variables->list_number = convert_number_to_int(variables);
		validation_duplicate_numbers(variables);
		init_push_swap(variables);
		free_variables(variables);
	}
	else if (ac > 2)
	{
		validation_number_2_args(variables, ac, av);
		variables->list_number = convert_number_to_int(variables);
		validation_duplicate_numbers(variables);
		init_push_swap(variables);
		free_variables(variables);
	}
	return (0);
}
