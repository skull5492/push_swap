/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorreir <jtorreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:28:51 by jtorreir          #+#    #+#             */
/*   Updated: 2023/10/26 17:28:51 by jtorreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	stack_a_push(long *stack_a, long *stack_b, \
int *stack_a_numbers, int *stack_b_numbers)
{
	int	a;

	(stack_a_numbers[1])++;
	a = stack_a_numbers[1] - 1;
	while (a > 0)
	{
		stack_a[a] = stack_a[a - 1];
		a--;
	}
	stack_a[0] = stack_b[0];
	a = 0;
	while (a < *stack_b_numbers)
	{
		stack_b[a] = stack_b[a + 1];
		a++;
	}
	(*stack_b_numbers)--;
	if (*stack_b_numbers == 0)
		stack_b = NULL;
	write(1, "pa\n", 3); 
}

void	stack_b_push(long *stack_a, long *stack_b, \
int *stack_a_numbers, int *stack_b_numbers)
{
	int	a;

	(*stack_b_numbers)++;
	a = *stack_b_numbers - 1;
	while (a > 0)
	{
		stack_b[a] = stack_b[a - 1];
		a--;
	}
	stack_b[0] = stack_a[0];
	a = 0;
	while (a < stack_a_numbers[1])
	{
		stack_a[a] = stack_a[a + 1];
		a++;
	}
	(stack_a_numbers[1])--;
	if (stack_a_numbers[1] == 0)
		stack_a = NULL;
	write(1, "pb\n", 3); 
}
