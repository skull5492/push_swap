/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorreir <jtorreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:37:30 by jtorreir          #+#    #+#             */
/*   Updated: 2023/12/07 16:37:30 by jtorreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	free_stacks(long *stack_a, long *stack_b, \
int *stack_a_numbers, int *stack_b_numbers)
{
	free(stack_a);
	free(stack_b);
	free(stack_a_numbers);
	free(stack_b_numbers);
	exit(0);
}

int	stack_size(int argc, char **argv)
{
	int	i;
	int	size;

	i = 0;
	size = 1;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == 32)
				size++;
			i++;
		}
	}
	else
		size = argc - 1;
	return (size);
}

int	dupe_numbers(long *stack_a, int stack_a_numbers)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stack_a_numbers)
	{
		j = 0;
		while (j < stack_a_numbers)
		{
			if ((stack_a[i] == stack_a[j]) && (i != j))
			{
				write(1, "Error\n", 6);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_parameters(long *stack_a, long *stack_b, \
int *stack_a_numbers, int *stack_b_numbers)
{
	stack_a_push(stack_a, stack_b, stack_a_numbers, stack_b_numbers);
	rotate_stack_a(stack_a, stack_a_numbers);
}
