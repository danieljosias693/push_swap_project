/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvemba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:38:26 by dvemba            #+#    #+#             */
/*   Updated: 2024/10/02 17:38:29 by dvemba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = NULL;
	if (!stack)
		return ;
	while (stack != NULL)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

void	free_variables(t_variables *variables)
{
	int	i;

	i = 0;
	if (!variables)
		return ;
	if (variables->list_number)
		free(variables->list_number);
	if (variables->matriz_number)
	{
		while (variables->matriz_number[i])
		{
			free(variables->matriz_number[i]);
			i++;
		}
		free(variables->matriz_number);
	}
	free(variables);
}

int	ft_atol(const char *str)
{
	int				sign;
	int				i;
	long long int	res;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 8 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if (sign == -1 && (-res) < INT_MIN)
			return (0);
		else if (sign == 1 && res > INT_MAX)
			return (0);
		i++;
	}
	return (-1);
}

void	free_matriz(char **mat)
{
	int	i;

	i = 0;
	if (!mat)
	{
		return ;
	}
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}

int	get_position_min_in_stack(t_stack *stack)
{
	int		min_value;
	int		i;
	t_stack	*tmp;

	i = 1;
	tmp = stack;
	min_value = stack->number;
	while (stack)
	{
		if (stack->number < min_value)
			min_value = stack->number;
		stack = stack->next;
	}
	while (min_value != tmp->number)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
