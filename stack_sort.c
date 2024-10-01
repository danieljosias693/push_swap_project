#include "push_swap.h"

void  sort_2_element(t_stack **stack_a)
{
    int first;
    int second;

    first = (*stack_a)->number;
    second = (*stack_a)->next->number;
    if (first > second)
        sa(stack_a, 0);
}

void  sort_3_element(t_stack **stack_a)
{
    int first;
    int second;
    int third;

    first = (*stack_a)->number;
    second = (*stack_a)->next->number;
    third = (*stack_a)->next->next->number;
    if ((first > second) && (second > third) && (third < first))
    {
        ra(stack_a, 0);
        sa(stack_a, 0);
    }
    else if ((first > second) && (second < third) && (third > first))
        sa(stack_a, 0);
    else if ((first > second) && (second < third) && (third < first))
        ra(stack_a, 0);
    else if ((first < second) && (second > third) && (third > first))
    {
        sa(stack_a, 0);
        ra(stack_a, 0);
    }
    else if ((first < second) && (second > third) && (third < first))
        rra(stack_a, 0);
}

void sort_4_element(t_stack **stack_a, t_stack **stack_b)
{
    if (!is_sorted(*stack_a))
        return;
    while (ft_stack_size(*stack_a) > 3)
    {
        if (get_position_min_in_stack(*stack_a) > (ft_stack_size(*stack_a) / 2))
            rra(stack_a, 0);
        else if (get_position_min_in_stack(*stack_a) == 1)
            pb(stack_a,stack_b);
        else
            ra(stack_a, 0);
    }
    sort_3_element(stack_a);
    while (ft_stack_size(*stack_b) > 0)
        pa(stack_a, stack_b);
}

static int get_max_bits(t_stack *stack)
{
    int max;
    int bits; 
    
    bits = 0;
    max = stack->number;
    while (stack) {
        if (stack->number > max) {
            max = stack->number;
        }
        stack = stack->next;
    }
    while (max) 
    {
        bits++;
        max >>= 1;
    }
    return bits;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int *arr, int size)
{
    int i = 0;
    while (i < size - 1) 
    {
        int j = 0;
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

int stack_size(t_stack *stack)
{
    int size = 0;
    while (stack) 
    {
        size++;
        stack = stack->next;
    }
    return size;
}

void map_stack_to_array(t_stack *stack, int *array)
{
    int i = 0;
    while (stack) 
    {
        array[i++] = stack->number;
        stack = stack->next;
    }
}

void replace_stack_with_index(t_stack *stack, int *array, int size)
{
    while (stack) 
    {
        int i = 0;
        while (i < size) 
        {
            if (stack->number == array[i]) 
            {
                stack->number = i;
                break;
            }
            i++;
        }
        stack = stack->next;
    }
}

void radix_sort(t_stack **stack_a, t_stack **stack_b)
{
    int array[stack_size(*stack_a)];
    int max_bits;
    int bit_mask;
    int original_size;
    int i;

    i = 0;
    max_bits = get_max_bits(*stack_a);
    map_stack_to_array(*stack_a, array);
    bubble_sort(array, stack_size(*stack_a));
    replace_stack_with_index(*stack_a, array, stack_size(*stack_a));
    while (i < max_bits) 
    { 
        bit_mask = 1 << i;
        original_size = stack_size(*stack_a);
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

