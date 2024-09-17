#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <errno.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int number;
	struct t_stack *next;
} t_stack;

typedef struct s_variables
{
    char **matriz_number;
	int *list_number;
}	t_variables;

t_stack *create_new_stack(int number);
void free_stack(t_stack *stack);
void add_new_node(t_stack **head, int number);
void print_stack(t_stack *stack);
void validation_duplicate_numbers(t_variables *variables);
void free_variables(t_variables *variables);
void free_matriz(char **mat , int size);
char  **validation_number(t_variables *variables, const char *str);
char **validation_number_2_args(int ac, char **av);
int *convert_number_to_int(t_variables *variables);
long int ft_atol(const char *str);
#endif