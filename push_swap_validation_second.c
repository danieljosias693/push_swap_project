/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_validation_second.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvemba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:34:16 by dvemba            #+#    #+#             */
/*   Updated: 2024/10/02 18:34:17 by dvemba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*convert_number_to_int(t_variables *variables)
{
	int	i;
	int	*array_num;

	i = 0;
	array_num = (int *)malloc(sizeof(int) * variables->size_of_list);
	while (i < variables->size_of_list)
	{
		array_num[i] = ft_atoi(variables->matriz_number[i]);
		i++;
	}
	return (array_num);
}
