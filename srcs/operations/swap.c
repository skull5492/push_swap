/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorreir <jtorreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:49:19 by jtorreir          #+#    #+#             */
/*   Updated: 2023/11/09 15:49:19 by jtorreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	swap_stack_a(long *stack_a, int *stack_a_numbers)
{
	long	*temp;

	temp = (long *)malloc(sizeof(long));
	if (stack_a_numbers[1] > 1)
	{
		temp[0] = stack_a[0];
		stack_a[0] = stack_a[1];
		stack_a[1] = temp[0];
	}
	free(temp);
	write(1, "sa\n", 3);
}

void	swap_stack_b(long *stack_b, int *stack_b_numbers)
{
	long	*temp2;

	temp2 = (long *)malloc(sizeof(long));
	if (*stack_b_numbers > 1)
	{
		temp2[0] = stack_b[0];
		stack_b[0] = stack_b[1];
		stack_b[1] = temp2[0];
	}
	free(temp2);
	write(1, "sb\n", 3);
}

void	swap_both_stacks(long *stack_a, long *stack_b, int *stack_a_numbers, int *stack_b_numbers)
{
	long	*temp3;

	temp3 = (long *)malloc(sizeof(long));
	if (stack_a_numbers[1] > 1)
	{
		temp3[0] = stack_a[0];
		stack_a[0] = stack_a[1];
		stack_a[1] = temp3[0];
	}
	if (*stack_b_numbers > 1)
	{
		temp3[0] = stack_b[0];
		stack_b[0] = stack_b[1];
		stack_b[1] = temp3[0];
	}
	free(temp3);
	write(1, "ss\n", 3);
}
