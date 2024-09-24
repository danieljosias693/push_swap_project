#include "push_swap.h"

void add_new_node(t_stack **head, int number)
{
    t_stack *new_node;
    t_stack *tmp;

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

void print_stack(t_stack *stack)
{
    t_stack *tmp;

    tmp = stack;
    if (!tmp)
        return ;
    while (tmp != NULL)
    {
        printf("%d\n",tmp->number);
        tmp = tmp->next;
    }
}

void init_stack(t_stack **stack_a , t_variables *variables)
{
    int i;

    i = 0;
    if (!stack_a || !variables || !variables->list_number)
        return;
    while (i < variables->size_of_list)
    {
        add_new_node(stack_a, variables->list_number[i]);
        i++;
    }
    print_stack(*stack_a);
}
