/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_way_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorreir <jtorreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:31:07 by jtorreir          #+#    #+#             */
/*   Updated: 2023/10/26 17:31:07 by jtorreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_3_numbers(long *stack_a, int *stack_a_numbers)
{
	if ((stack_a[0] > stack_a[1]) && (stack_a[1] < stack_a[2]) \
	&& (stack_a[0] < stack_a[2]))
		swap_stack_a(stack_a, stack_a_numbers);
	if ((stack_a[0] > stack_a[1]) && (stack_a[1] > stack_a[2]) \
	&& (stack_a[0] > stack_a[2]))
	{
		swap_stack_a(stack_a, stack_a_numbers);
		reverse_rotate_stack_a(stack_a, stack_a_numbers);
	}
	if ((stack_a[0] > stack_a[1]) && (stack_a[1] < stack_a[2]) \
	&& (stack_a[0] > stack_a[2]))
		rotate_stack_a(stack_a, stack_a_numbers);
	if ((stack_a[0] < stack_a[1]) && (stack_a[1] > stack_a[2]) \
	&& (stack_a[0] < stack_a[2]))
	{
		swap_stack_a(stack_a, stack_a_numbers);
		rotate_stack_a(stack_a, stack_a_numbers);
	}
	if ((stack_a[0] < stack_a[1]) && (stack_a[1] > stack_a[2]) \
	&& (stack_a[0] > stack_a[2]))
		reverse_rotate_stack_a(stack_a, stack_a_numbers);
}
