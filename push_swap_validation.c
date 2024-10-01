#include "push_swap.h"

static void is_valid_number(t_variables *variables, char *str, char **tmp)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] != '\0')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
        {
            write(2, "Error\n", 6);
            free_matriz(tmp);
            free_variables(variables);
			exit (0);
        }
		i++;
	}
}

static void verify_number_in_limit(t_variables *variables, char *str, char **tmp)
{
    if (!ft_atol(str))
    {
        write(2, "Error\n", 6);
        free_matriz(tmp);
        free_variables(variables);
        exit(1);
    }
}

void validation_number(t_variables *variables, const char *str)
{
    int i;
    char **tmp;

    i = 0;
    tmp = NULL;
    variables->matriz_number = ft_split(str, ' ');
    while (variables->matriz_number[i])
    {
        is_valid_number(variables, variables->matriz_number[i], tmp);
        verify_number_in_limit(variables, variables->matriz_number[i], tmp);
        i++;
    }
    variables->size_of_list = i;
}

void validation_duplicate_numbers(t_variables *variables)
{
    int i;
    int j;
    int size;

    size = variables->size_of_list;
    i = 0;
    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            if (variables->list_number[i] == variables->list_number[j])
            {
                write(2, "Error\n", 6);
                free_variables(variables);
                exit(0);
            }
            j++;
        }
        i++;
    }
}

int *convert_number_to_int(t_variables *variables)
{
    int i;
    int *array_num;

    i = 0;
    array_num = (int *)malloc(sizeof(int) * variables->size_of_list);
    while (i < variables->size_of_list)
    {
        array_num[i] = ft_atoi(variables->matriz_number[i]);
        i++;
    }
    return (array_num);
}

void validation_number_2_args(t_variables *variables, int ac, char **av)
{
    int i;
    int j;
    int k;
    char **tmp;

    i = 1;
    k = 0;
    variables->matriz_number = (char **)malloc(sizeof(char *) * (ac * 10));
    while(i < ac)
    {
        j = 0;
        tmp = ft_split(av[i], ' ');
        while(tmp[j])
        {
            is_valid_number(variables, tmp[j], tmp);
            verify_number_in_limit(variables, tmp[j], tmp);
            variables->matriz_number[k] = ft_strdup(tmp[j]);
            j++;
            k++;
        }
        free_matriz(tmp);
        i++;
    }
    variables->size_of_list = k;
    variables->matriz_number[k]= NULL;
}
