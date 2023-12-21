/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_way_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorreir <jtorreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:15:01 by jtorreir          #+#    #+#             */
/*   Updated: 2023/11/24 15:15:01 by jtorreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	stack_a_rotation(long *stack_a, int *stack_a_numbers)
{
	rotate_stack_a(stack_a, stack_a_numbers);
	rotate_stack_a(stack_a, stack_a_numbers);
}

void	first_stack(long *stack_a, long *stack_b, \
int *stack_a_numbers, int *stack_b_numbers)
{
	if (stack_b[0] < stack_a[0])
		stack_a_push(stack_a, stack_b, stack_a_numbers, stack_b_numbers);
	else if ((stack_b[0] > stack_a[0]) && (stack_b[0] < stack_a[1]))
	{
		rotate_stack_a(stack_a, stack_a_numbers);
		stack_a_push(stack_a, stack_b, stack_a_numbers, stack_b_numbers);
		reverse_rotate_stack_a(stack_a, stack_a_numbers);
	}
	else if ((stack_b[0] > stack_a[1]) && (stack_b[0] < stack_a[2]))
	{
		reverse_rotate_stack_a(stack_a, stack_a_numbers);
		stack_a_push(stack_a, stack_b, stack_a_numbers, stack_b_numbers);
		reverse_rotate_stack_a(stack_a, stack_a_numbers);
		reverse_rotate_stack_a(stack_a, stack_a_numbers);
	}
	else if (stack_b[0] > stack_a[2])
	{
		stack_a_push(stack_a, stack_b, stack_a_numbers, stack_b_numbers);
		rotate_stack_a(stack_a, stack_a_numbers);
	}
}

void	second_stack(long *stack_a, long *stack_b, \
int *stack_a_numbers, int *stack_b_numbers)
{
	if (stack_b[0] < stack_a[0])
	{
		stack_a_push(stack_a, stack_b, stack_a_numbers, stack_b_numbers);
	}
	else if ((stack_b[0] > stack_a[0]) && (stack_b[0] < stack_a[1]))
	{
		stack_a_push(stack_a, stack_b, stack_a_numbers, stack_b_numbers);
		swap_stack_a(stack_a, stack_a_numbers);
	}
	else if ((stack_b[0] > stack_a[1]) && (stack_b[0] < stack_a[2]))
	{
		rotate_stack_a(stack_a, stack_a_numbers);
		stack_a_push(stack_a, stack_b, stack_a_numbers, stack_b_numbers);
		swap_stack_a(stack_a, stack_a_numbers);
		reverse_rotate_stack_a(stack_a, stack_a_numbers);
	}
	else if ((stack_b[0] > stack_a[2]) && (stack_b[0] < stack_a[3]))
	{
		reverse_rotate_stack_a(stack_a, stack_a_numbers);
		stack_a_push(stack_a, stack_b, stack_a_numbers, stack_b_numbers);
		stack_a_rotation(stack_a, stack_a_numbers);
	}
	else if (stack_b[0] > stack_a[3])
		ft_parameters(stack_a, stack_b, stack_a_numbers, stack_b_numbers);
}

void	sort_5_numbers(long *stack_a, long *stack_b, \
int *stack_a_numbers, int *stack_b_numbers)
{
	stack_b_push(stack_a, stack_b, stack_a_numbers, stack_b_numbers);
	stack_b_push(stack_a, stack_b, stack_a_numbers, stack_b_numbers);
	sort_3_numbers(stack_a, stack_a_numbers);
	while (*stack_b_numbers != 0)
	{
		if (stack_a_numbers[1] == 3)
			first_stack(stack_a, stack_b, stack_a_numbers, stack_b_numbers);
		else if (stack_a_numbers[1] == 4)
			second_stack(stack_a, stack_b, stack_a_numbers, stack_b_numbers);
	}
}
