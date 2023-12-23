/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorreir <jtorreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:41:39 by jtorreir          #+#    #+#             */
/*   Updated: 2023/12/07 16:41:39 by jtorreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_strlen(const char *bruh)
{
	int	i;

	i = 0;
	while (bruh[i])
		i++;
	return (i);
}

int	ft_isdigit(int i)
{
	while ('0' <= i && i <= '9')
		return (1);
	return (0);
}

int	stack_number_check(char *numbers)
{
	int	i;
	int	minus;

	i = 0;
	minus = 0;
	while (numbers[i])
	{
		if (numbers[i] == 45 && ft_isdigit(numbers[i + 1]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	number_limits(long *stack_a, int stack_a_numbers)
{
	int	i;

	i = 0;
	while (i < stack_a_numbers)
	{
		if ((stack_a[i] > 2147483647) || (stack_a[i] < -2147483648))
		{
			write(1, "Error\n", 6);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	sort_stack_check(long *stack_a, int *stack_a_numbers)
{
	int		i;
	int		j;
	long	max;

	i = 1;
	j = 0;
	max = stack_a[0];
	while (i < stack_a_numbers[1])
	{
		if (stack_a[i] > max)
		{
			max = stack_a[i];
			j++;
		}
		i++;
	}
	if (j == stack_a_numbers[1] - 1)
		return (0);
	return (-1);
}
