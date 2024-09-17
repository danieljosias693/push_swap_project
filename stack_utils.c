#include "push_swap.h"

t_stack *create_new_stack(int number)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->number = number;
	new_node->next = NULL;
	return (new_node);
}
// void free_stack(t_stack *stack)
// {
// 	t_stack *tmp;

// 	tmp = NULL;
// 	if (!stack)
// 		return ;
// 	while (stack != NULL)
// 	{
// 		tmp = stack->next;
// 		free(stack);
// 		stack = tmp;
// 	}
// }
void free_variables(t_variables *variables)
{
	int i;

	i = 0;
	if (!variables)
		return;
	if (!variables->matriz_number)
		return;
	while (variables->matriz_number[i])
	{
		free(variables->matriz_number[i]);
		i++;
	}
	free(variables->matriz_number);
	if (variables->list_number)
		free(variables->list_number);
	free(variables);
}

long int ft_atol(const char *str)
{
	int sign;
	int i;
	long int res;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 8 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

void free_matriz(char **mat , int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}