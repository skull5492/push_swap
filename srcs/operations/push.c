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
	int	i;

	(stack_a_numbers[1])++;
	a = stack_a_numbers[1] - 1;
	i = a;
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = stack_b[0];
	i = 0;
	while (i < (*stack_b_numbers - 1))
	{
		stack_b[i] = stack_b[i + 1];
		i++;
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
	int	i;

	(*stack_b_numbers)++;
	a = *stack_b_numbers - 1;
	i = a;
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = stack_a[0];
	i = 0;
	while (i < stack_a_numbers[1] - 1)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	(stack_a_numbers[1])--;
	if (stack_a_numbers[1] == 0)
		stack_a = NULL;
	write(1, "pb\n", 3);
}
