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
    print_stack(*stack_a);
}
