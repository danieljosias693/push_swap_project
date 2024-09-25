#include "push_swap.h"

static void init_push_swap(t_variables *variables)
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    init_stack(&stack_a , variables);
    if (ft_stack_size(stack_a) == 2)
        sort_2_element(&stack_a);
    else if (ft_stack_size(stack_a) == 3)
        sort_3_element(&stack_a);
    else if (ft_stack_size(stack_a) > 3 && ft_stack_size(stack_a) < 6)
        sort_4_element(&stack_a, &stack_b);
    printf("SORT STACK:\n");
    print_stack(stack_a);
    print_stack(stack_b);
    free_stack(stack_a);
}

int main(int ac, char **av)
{
    t_variables *variables;

    variables = (t_variables *)malloc(sizeof(t_variables));
    variables->matriz_number = NULL;
    variables->list_number = NULL;
    if (ac < 2)
        return (free_variables(variables), 0);
    else if (ac == 2)
    {
        variables->matriz_number = validation_number(variables, av[1]);
        variables->list_number = convert_number_to_int(variables);
        validation_duplicate_numbers(variables);
        init_push_swap(variables);
        free_variables(variables);
    }
    else
    {
        validation_number_2_args(variables, ac, av);
        variables->list_number = convert_number_to_int(variables);
        validation_duplicate_numbers(variables);
        init_push_swap(variables);
        free_variables(variables);
    }
    return (0);
}
