/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorreir <jtorreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:31:59 by jtorreir          #+#    #+#             */
/*   Updated: 2023/10/26 17:31:59 by jtorreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rotate_stack_a(long *stack_a, int *stack_a_numbers)
{
	int		i;
	long	temp;

	i = 0;
	temp = stack_a[0];
	if (stack_a_numbers[1] <= 1)
		stack_a = NULL;
	while (i < stack_a_numbers[1] - 1) 
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[stack_a_numbers[1] - 1] = temp;
	write(1, "ra\n", 3);
}

void	rotate_stack_b(long *stack_b, int *stack_b_numbers)
{
	int		i;
	long	temp;

	i = 0;
	temp = stack_b[0];
	if (*stack_b_numbers <= 1)
		stack_b = NULL;
	while (i < *stack_b_numbers - 1) 
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[*stack_b_numbers - 1] = temp;
	write(1, "rb\n", 3);
}

void	rotate_stack_a_and_stack_b(long *stack_a, long *stack_b, \
int *stack_a_numbers, int *stack_b_numbers)
{
	int		i;
	long	temp;

	i = -1;
	temp = 0;
	if (stack_a_numbers[1] > 1)
	{
		temp = stack_a[0];
		while (++i < stack_a_numbers[1] - 1)
			stack_a[i] = stack_a[i + 1];
		stack_a[stack_a_numbers[1] - 1] = temp;
	}
	if (*stack_b_numbers > 1)
	{
		temp = stack_b[0];
		while (++i < *stack_b_numbers - 1)
			stack_b[i] = stack_b[i + 1];
		stack_b[*stack_b_numbers - 1] = temp;
	}
	write(1, "rr\n", 3);
}
