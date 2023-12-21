/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorreir <jtorreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:40:38 by jtorreir          #+#    #+#             */
/*   Updated: 2023/11/24 15:40:38 by jtorreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	stack_section_sort(long *array, int *stack_size)
{
	long	i;
	long	j;
	long	temp;

	i = 0;
	j = 0;
	while (i < stack_size[0])
	{
		j = i + 1;
		while (j < stack_size[0])
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	first_stack_a_swap(long *copy, long *copy_swap_stack_a, long *stack_a, int *stack_a_numbers)
{
	int	i;

	i = 0;
	while (i < stack_a_numbers[0])
	{
		copy[i] = stack_a[i];
		copy_swap_stack_a[i] = stack_a[i];
		i++;
	}
}

void	second_stack_a_swap(long *copy, long *copy_swap_stack_a, long *stack_a, int *stack_a_numbers)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stack_a_numbers[1])
	{
		j = 0;
		while (j < stack_a_numbers[0])
		{
			if (copy_swap_stack_a[i] == copy[j])
				stack_a[i] = j;
			j++;
		}
		++i;
	}
}

void	third_stack_a_swap(long *stack_a, long *stack_b, int *stack_a_numbers, int *stack_b_numbers)
{
	int	maximum_number;
	int	maximum_bits;
	int	loop_through[2];

	maximum_number = stack_a_numbers[1] - 1;
	maximum_bits = 0;
	loop_through[0] = 0;
	loop_through[1] = 0;
	while ((maximum_number >> maximum_bits) != 0)
		++maximum_bits;
	while (loop_through[0] < maximum_bits)
	{
		loop_through[1] = 0;
		while (loop_through[1] < stack_a_numbers[0])
		{
			if (((stack_a[0] >> loop_through[0]) & 1) == 1)
				rotate_stack_a(stack_a, stack_a_numbers);
			else
				stack_b_push(stack_a, stack_b, stack_a_numbers, stack_b_numbers);
			++loop_through[1];
		}
		while (*stack_b_numbers != 0)
			stack_a_push(stack_a, stack_b, stack_a_numbers, stack_b_numbers);
		++loop_through[0];
	}
}

void	sort_beyond_3_and_5_numbers(long *stack_a, long *stack_b, int *stack_a_numbers, int *stack_b_numbers)
{
	long	*copy;
	long	*copy_swap_stack_a;

	copy = (long *)malloc(stack_a_numbers[0] * sizeof(long));
	copy_swap_stack_a = (long *)malloc(stack_a_numbers[0] * sizeof(long));
	first_stack_a_swap(copy, copy_swap_stack_a, stack_a, stack_a_numbers);
	stack_section_sort(copy, stack_a_numbers);
	second_stack_a_swap(copy, copy_swap_stack_a, stack_a, stack_a_numbers);
	free(copy);
	free(copy_swap_stack_a);
	third_stack_a_swap(stack_a, stack_b, stack_a_numbers, stack_b_numbers);
}
