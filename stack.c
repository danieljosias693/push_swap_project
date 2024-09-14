#include "push_swap.h"

void add_new_node(t_stack **head, int number)
{
    t_stack *new_node;
    t_stack *tmp;

    new_node = NULL;
    tmp = NULL;
    new_node = create_new_stack(number);
    if (!*head)
    {
        *head = new_node;
        return ;
    }
    tmp = *head;
    while ((*head)->next != NULL)
        *head = (*head)->next;
    (*head)->next = new_node;
    *head = tmp;
}

void print_stack(t_stack *stack)
{
    t_stack *tmp;

    tmp = stack;
    if (!tmp)
        return ;
    while (tmp != NULL)
    {
        printf("%d",tmp->number);
        tmp = tmp->next;
    }
}