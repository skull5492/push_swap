/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorreir <jtorreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:51:13 by jtorreir          #+#    #+#             */
/*   Updated: 2023/12/07 16:51:13 by jtorreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_and_exit(int *stack_a_numbers, int *stack_b_numbers)
{
	free(stack_a_numbers);
	free(stack_b_numbers);
	exit(0);
}

void	free_and_exit_errors(int *stack_a_numbers, int *stack_b_numbers)
{
	free(stack_a_numbers);
	free(stack_b_numbers);
	write(1, "Error\n", 6);
	exit(0);
}

void	check_parameters(int argc, char **argv, \
int *stack_a_numbers, int *stack_b_numbers)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (argc < 2)
		free_and_exit(stack_a_numbers, stack_b_numbers);
	while (i < argc)
	{
		if ((argv[i][ft_strlen(argv[i]) - 1] == ' ') || (argv[i][0] == ' '))
			free_and_exit_errors(stack_a_numbers, stack_b_numbers);
		j = 0;
		while (j < ft_strlen(argv[i]))
		{
			if (((argv[i][j] < 48) || (argv[i][j] > 57)) && (argv[i][j] != 32))
			{
				if (argv[i][j] != 45)
					free_and_exit_errors(stack_a_numbers, stack_b_numbers);
			}
			if ((argv[i][j] == 32) && (argv[i][j + 1] == 32))
				free_and_exit_errors(stack_a_numbers, stack_b_numbers);
			j++;
		}
		i++;
	}
}

void	set_numbers(int *stack_a_numbers, int *stack_b_numbers, int argc)
{
	stack_a_numbers[0] = argc - 1;
	stack_a_numbers[1] = stack_a_numbers[0];
	*stack_b_numbers = 0;
}

int	main(int argc, char **argv)
{
	long	*stack_a;
	long	*stack_b;
	int		*stack_a_numbers;
	int		*stack_b_numbers;

	stack_a_numbers = (int *)malloc(2 * sizeof(int));
	stack_b_numbers = (int *)malloc(sizeof(int));
	check_parameters(argc, argv, stack_a_numbers, stack_b_numbers);
	set_numbers(stack_a_numbers, stack_b_numbers, argc);
	stack_a = (long *)malloc(sizeof(long) * (stack_size(argc, argv)));
	stack_b = (long *)malloc(sizeof(long) * (stack_size(argc, argv)));
	if ((seperating_input_numbers(stack_a, stack_a_numbers, argv) == -1) \
	|| (sort_stack_check(stack_a, stack_a_numbers) == 0))
		free_stacks(stack_a, stack_b, stack_a_numbers, stack_b_numbers);
	if ((stack_a_numbers[1] == 2) && (stack_a[0] > stack_a[1]))
		reverse_both_stacks(stack_a, stack_b, stack_a_numbers, stack_b_numbers);
	else if (stack_a_numbers[1] == 3)
		sort_3_numbers(stack_a, stack_a_numbers);
	else if (stack_a_numbers[1] == 5)
		sort_5_numbers(stack_a, stack_b, stack_a_numbers, stack_b_numbers);
	else
		sort_beyond_3_and_5_numbers(stack_a, stack_b, \
		stack_a_numbers, stack_b_numbers);
	free_stacks(stack_a, stack_b, stack_a_numbers, stack_b_numbers);
	return (0);
}
