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
void free_stack(t_stack *stack)
{
	t_stack *tmp;

	if (!stack)
		return ;
	while (stack != NULL)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}
void free_variables(t_variables *variables)
{
	int i;

	i = 0;
	if (!variables)
		return;
	while (variables->matriz_number[i])
	{
		free(variables->matriz_number[i]);
		i++;
	}
	free(variables->matriz_number);
	free(variables->list_number);
	free(variables);
}
