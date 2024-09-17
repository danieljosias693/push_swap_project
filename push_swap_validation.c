#include "push_swap.h"

static void is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
        {
            printf("ERROR");
			exit (0);
        }
		i++;
	}
}

static void verify_number_in_limit(t_variables *variables, char *str)
{
    long int num;

    num = ft_atol(str);
    if (num < INT_MIN || num > INT_MAX)
    {
        printf("ERROR");
        free_variables(variables);
        exit(0);
    }
}

char  **validation_number(t_variables *variables, const char *str)
{
    int i;
    char **tmp;

    i = 0;
    tmp = ft_split(str, ' ');
    while (tmp[i])
    {
        is_valid_number(tmp[i]);
        verify_number_in_limit(variables, tmp[i]);
        i++;
    }
    return tmp;
}
void validation_duplicate_numbers(t_variables *variables)
{
    int i;
    int j;

    i = 0;
    while (variables->list_number[i])
    {
        j = i + 1;
        while (variables->list_number[j])
        {
            if (variables->list_number[i] == variables->list_number[j])
            {
                printf("ERROR");
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

    array_num = (int *)malloc(sizeof(int) * 100);
    ft_memset(array_num, 0, 100 * sizeof(int));
    while (variables->matriz_number[i])
    {
        array_num[i] = ft_atoi(variables->matriz_number[i]);
        i++;
    }
    return (array_num);
}

char **validation_number_2_args(int ac, char **av)
{
    int i;
    int j = 0;
    int k = 0;
    char **mat;
    char **tmp;

    i = 1;
    tmp = NULL;
    mat = (char **)malloc(sizeof(char *) * 4096);

    if (!mat)
        return (NULL);
    while(i <= ac)
    {
        j = 0;
        tmp = ft_split(av[i], ' ');
        while(tmp[j])
        {
            mat[k] = tmp[j];
            j++;
            k++;
        }
        i++;
    }
    free_matriz(tmp, j);
    return (mat);
}