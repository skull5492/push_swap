/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorreir <jtorreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:44:01 by jtorreir          #+#    #+#             */
/*   Updated: 2023/12/22 20:16:42 by jtorreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	extra_stack_b(long *stack_a, long *stack_b, \
int *stack_a_numbers, int *stack_b_numbers)
{
	while (*stack_b_numbers != 0)
		stack_a_push(stack_a, stack_b, \
		stack_a_numbers, stack_b_numbers);
}

void	test_values(int *loop_through)
{
	loop_through[0] = 0;
	loop_through[1] = 0;
}

void	space_save(long *stack_b, int i)
{
	stack_b[i] = stack_b[i + 1]; 
	i++;
}

void	space_save_2(long *stack_a, int *stack_a_numbers, int i, long *temp)
{
	*temp = stack_a[stack_a_numbers[1] - 1];
	i = stack_a_numbers[1] - 1;
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
}
