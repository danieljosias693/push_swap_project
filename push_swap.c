#include "push_swap.h"

void init_push_swap()
{
    
}
int main(int ac, char **av)
{
    t_variables *variables;

    variables = (t_variables *)malloc(sizeof(t_variables));
    if (ac < 2)
    {
        printf("ERROR!");
        return (0);
    }
    else if (ac == 2)
    {
        variables->matriz_number = validation_number(av[1]);
        variables->list_number = convert_number_to_int(variables->matriz_number);
        validation_duplicate_numbers(variables->list_number);

    }
    return (0);
}