/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorreir <jtorreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:44:01 by jtorreir          #+#    #+#             */
/*   Updated: 2023/12/21 15:51:15 by jtorreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_maxbit(int maximum_number, int maximum_bits)
{
	while ((maximum_number >> maximum_bits) != 0)
		++maximum_bits;
}

void	extra_stack_b(long *stack_a, long *stack_b, \
int *stack_a_numbers, int *stack_b_numbers)
{
	while (*stack_b_numbers != 0)
		stack_a_push(stack_a, stack_b, \
		stack_a_numbers, stack_b_numbers);
}
