#include "push_swap.h"

void init_push_swap()
{
    
}
int main(int ac, char **av)
{
    t_variables *variables;

    variables = (t_variables *)malloc(sizeof(t_variables));
    variables->matriz_number = NULL;
    variables->list_number = NULL;
    if (ac < 2)
        return (0);
    else if (ac == 2)
    {
        variables->matriz_number = validation_number(variables, av[1]);
        variables->list_number = convert_number_to_int(variables);
        validation_duplicate_numbers(variables);
        free_variables(variables);
    }
    else
    {
        variables->matriz_number = validation_number_2_args(variables, ac,av);
        variables->list_number = convert_number_to_int(variables);
        validation_duplicate_numbers(variables);
        int i = 0;
        while (variables->matriz_number[i])
        {
            printf("%s\n", variables->matriz_number[i]);
            i++;
        }
        free_variables(variables);
    }
    return (0);
}