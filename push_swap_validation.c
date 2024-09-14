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
            printf("ERROR!");
			exit (0);
        }
		i++;
	}
    printf("valid number!");
}
char  **validation_number(const char *str)
{
    int i;
    char **tmp;

    i = 0;
    tmp = ft_split(str, ' ');
    while (tmp[i])
    {
        is_valid_number(tmp[i]);
        i++;
    }
    return tmp;
}
void validation_duplicate_numbers(t_variablesint *list_number)
{
    int i;
    int j;

    i = 0;
    while (list_number[i])
    {
        j = i + 1;
        printf("\n%d",list_number[i]);
        while (list_number[j])
        {
            if (list_number[i] == list_number[j])
            {
                printf("ERROR!");
                free_variables(variables);
                exit(0);
            }
            j++;
        }
        i++;
    }
}
int *convert_number_to_int(char **str)
{
    int i;
    int *array_num;

    i = 0;
    array_num = (int *)malloc(sizeof(int) * 100);
    while (str[i])
    {
        array_num[i] = ft_atoi(str[i]);
        i++;
    }
    return (array_num);
}

