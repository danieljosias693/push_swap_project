/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_second.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvemba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:26:09 by dvemba            #+#    #+#             */
/*   Updated: 2024/10/02 18:26:11 by dvemba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
			j++;
		}
		i++;
	}
}

static void	map_stack_to_array(t_stack *stack, int *array)
{
	int	i;

	i = 0;
	while (stack)
	{
		array[i++] = stack->number;
		stack = stack->next;
	}
}

static void	replace_stack_with_index(t_stack *stack, int *array, int size)
{
	int	i;

	while (stack)
	{
		i = 0;
		while (i < size)
		{
			if (stack->number == array[i])
			{
				stack->number = i;
				break ;
			}
			i++;
		}
		stack = stack->next;
	}
}

void radix_sort(t_stack **stack_a, t_stack **stack_b)
{
    int array[ft_stack_size(*stack_a)];
    int max_bits;
    int bit_mask;
    int original_size;
    int i;

    i = 0;
    map_stack_to_array(*stack_a, array);
    bubble_sort(array, ft_stack_size(*stack_a));
    replace_stack_with_index(*stack_a, array, ft_stack_size(*stack_a));
    max_bits = get_max_bits(*stack_a);
    while (i < max_bits) 
    { 
        bit_mask = 1 << i;
        original_size = ft_stack_size(*stack_a);
        while (original_size--) 
        {
            if (((*stack_a)->number & bit_mask) == 0) 
                pb(stack_a, stack_b);
            else 
                ra(stack_a, 0);
        }
        while (*stack_b) 
            pa(stack_a, stack_b);
        i++;
    }
}
