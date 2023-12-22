/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorreir <jtorreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:49:05 by jtorreir          #+#    #+#             */
/*   Updated: 2023/11/09 15:49:05 by jtorreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	reverse_rotate_stack_a(long *stack_a, int *stack_a_numbers)
{
	int		i;
	long	*temp;

	i = stack_a_numbers[1] - 1;
	temp = (long *)malloc(sizeof(long));
	*temp = stack_a[stack_a_numbers[1] - 1];
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = *temp;
	free(temp);
	write(1, "rra\n", 4);
}

void	reverse_rotate_stack_b(long *stack_b, int *stack_b_numbers)
{
	int		i;
	long	*temp;

	i = *stack_b_numbers - 1;
	temp = (long *)malloc(sizeof(long));
	*temp = stack_b[*stack_b_numbers - 1];
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = *temp;
	free(temp);
	write(1, "rrb\n", 4);
}

void	reverse_both_stacks(long *stack_a, long *stack_b, \
int *stack_a_numbers, int *stack_b_numbers)
{
	long	*temp;
	int		i;

	i = 0;
	temp = (long *)malloc(sizeof(long));
	if (stack_a_numbers[1] > 1)
	{
		space_save_2(stack_a, stack_a_numbers, i, temp);
		stack_a[0] = *temp;
		free(temp);
	}
	if (*stack_b_numbers > 1)
	{
		*temp = stack_b[0];
		i = 0;
		while (i < *stack_b_numbers - 1)
			space_save(stack_b, i);
		stack_b[*stack_b_numbers - 1] = *temp;
		free(temp);
	}
	write(1, "rrr\n", 4);
}
