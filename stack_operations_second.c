/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_second.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvemba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:28:34 by dvemba            #+#    #+#             */
/*   Updated: 2024/10/02 18:28:41 by dvemba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, int i)
{
	t_stack	*first;
	t_stack	*last;

	if (!(*a) || !(*a)->next)
		return ;
	first = *a;
	last = *a;
	while (last->next)
		last = last->next;
	*a = first->next;
	first->next = NULL;
	last->next = first;
	if (i == 0)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int i)
{
	t_stack	*first;
	t_stack	*last;

	if (!(*b) || !(*b)->next)
		return ;
	first = *b;
	last = *b;
	while (last->next)
		last = last->next;
	*b = first->next;
	first->next = NULL;
	last->next = first;
	if (i == 0)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, 1);
	rb(b, 1);
	write(1, "rr\n", 3);
}

void	rra(t_stack **a, int i)
{
	t_stack	*first;
	t_stack	*last;

	if (!(*a) || !(*a)->next)
		return ;
	first = NULL;
	last = (*a);
	while (last->next)
	{
		first = last;
		last = last->next;
	}
	first->next = NULL;
	last->next = *a;
	(*a) = last;
	if (i == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int i)
{
	t_stack	*first;
	t_stack	*last;

	if ((!*b) || !(*b)->next)
		return ;
	first = NULL;
	last = *b;
	while (last->next)
	{
		first = last;
		last = last->next;
	}
	first->next = NULL;
	last->next = (*b);
	*b = last;
	if (i == 0)
		write(1, "rrb\n", 4);
}
