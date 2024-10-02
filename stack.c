/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvemba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:38:16 by dvemba            #+#    #+#             */
/*   Updated: 2024/10/02 17:38:17 by dvemba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_new_stack(int number)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->number = number;
	new_node->next = NULL;
	return (new_node);
}

void	add_new_node(t_stack **head, int number)
{
	t_stack	*new_node;
	t_stack	*tmp;

	new_node = NULL;
	new_node = create_new_stack(number);
	if (!*head)
	{
		*head = new_node;
		return ;
	}
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_node;
}

void	init_stack(t_stack **stack_a, t_variables *variables)
{
	int	i;

	i = 0;
	if (!stack_a || !variables || !variables->list_number)
		return ;
	while (i < variables->size_of_list)
	{
		add_new_node(stack_a, variables->list_number[i]);
		i++;
	}
}

int	is_sorted(t_stack *a)
{
	t_stack	*current;

	current = a;
	while (current->next != NULL)
	{
		if (current->number > current->next->number)
		{
			return (1);
		}
		current = current->next;
	}
	return (0);
}

int	ft_stack_size(t_stack *stack)
{
	if (stack == 0)
		return (0);
	else
		return (1 + ft_stack_size(stack->next));
}
