/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorreir <jtorreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:45:37 by jtorreir          #+#    #+#             */
/*   Updated: 2023/12/07 16:45:37 by jtorreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (str[i] - '0') + (result * 10);
		i++;
	}
	return (result * sign);
}

void	free_string(char **bruh)
{
	int	i;

	i = 0;
	while (bruh[i])
	{
		free(bruh[i]);
		i++;
	}
}

int	numbers_input(long *stack_a, int *stack_a_numbers, \
char **argv, char**numbers_list)
{
	int	i;
	int	numbers;

	i = 0;
	numbers = 0;
	numbers_list = ft_split(argv[1], 32);
	while (numbers_list[i])
	{
		numbers++;
		i++;
	}
	stack_a_numbers[0] = numbers;
	stack_a_numbers[1] = stack_a_numbers[0];
	i = 0;
	while (i < stack_a_numbers[0])
	{
		stack_a[i] = ft_atoi(numbers_list[i]);
		i++;
	}
	free_string(numbers_list);
	free(numbers_list);
	return (0);
}

int	standard_input(long *stack_a, int *stack_a_numbers, char **argv)
{
	int	i;

	i = 0;
	while (i < stack_a_numbers[1])
	{
		if (stack_number_check(argv[i + 1]) == 1)
			stack_a[i] = ft_atoi(argv[i + 1]);
		else
		{
			write(1, "Error\n", 6);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	seperating_input_numbers(long *stack_a, int *stack_a_numbers, char **argv)
{
	char	**numbers_list;

	numbers_list = NULL;
	if (stack_a_numbers[0] == 1)
	{
		if (numbers_input(stack_a, stack_a_numbers, argv, numbers_list) == -1)
			return (-1);
	}
	else
	{
		if (standard_input(stack_a, stack_a_numbers, argv) == -1)
			return (-1);
	}
	if (dupe_numbers(stack_a, stack_a_numbers[1]) == -1)
		return (-1);
	if (number_limits(stack_a, stack_a_numbers[1] == -1))
		return (-1);
	return (0);
}
