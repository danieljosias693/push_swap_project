/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvemba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:38:00 by dvemba            #+#    #+#             */
/*   Updated: 2024/10/02 17:38:02 by dvemba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, int i)
{
	t_stack	*first;
	t_stack	*second;

	if (!(*a) || !(*a)->next)
		return ;
	first = *a;
	second = (*a)->next;
	first->next = second->next;
	second->next = first;
	*a = second;
	if (i == 0)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int i)
{
	t_stack	*first;
	t_stack	*second;

	if (!(*b) || !(*b)->next)
		return ;
	first = *b;
	second = (*b)->next;
	first->next = second->next;
	second->next = first;
	*b = second;
	if (i == 0)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a, 1);
	sb(b, 1);
	write(1, "ss\n", 1);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*top_b;

	if (!(*b))
		return ;
	top_b = *b;
	*b = top_b->next;
	top_b->next = *a;
	*a = top_b;
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*top_a;

	if (!(*a))
		return ;
	top_a = *a;
	*a = top_a->next;
	top_a->next = *b;
	*b = top_a;
	write(1, "pb\n", 3);
}
