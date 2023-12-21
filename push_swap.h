/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorreir <jtorreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:06:04 by jtorreir          #+#    #+#             */
/*   Updated: 2023/10/26 17:06:04 by jtorreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>

void	stack_a_push(long *stack_a, long *stack_b, int *stack_a_numbers, int *stack_b_numbers);
void	stack_b_push(long *stack_a, long *stack_b, int *stack_a_numbers, int *stack_b_numbers);

void	reverse_rotate_stack_a(long *stack_a, int *stack_a_numbers);
void	reverse_rotate_stack_b(long *stack_b, int *stack_b_numbers);
void	reverse_both_stacks(long *stack_a, long *stack_b, int *stack_a_numbers, int *stack_b_numbers);

void	rotate_stack_a(long *stack_a, int *stack_a_numbers);
void	rotate_stack_b(long *stack_b, int *stack_b_numbers);
void	rotate_stack_a_and_stack_b(long *stack_a, long *stack_b, int *stack_a_numbers, int *stack_b_numbers);

void	swap_stack_a(long *stack_a, int *stack_a_numbers);
void	swap_stack_b(long *stack_b, int *stack_b_numbers);
void	swap_both_stacks(long *stack_a, long *stack_b, int *stack_a_numbers, int *stack_b_numbers);

void	sort_3_numbers(long *stack_a, int *stack_a_numbers);
void	sort_5_numbers(long *stack_a, long *stack_b, int *stack_a_numbers, int *stack_b_numbers);
void	sort_beyond_3_and_5_numbers(long *stack_a, long *stack_b, int *stack_a_numbers, int *stack_b_numbers);

char	**ft_split(char const *str, char c);

int		ft_strlen(const char *str);
int		number_limits(long *stack_a, int stack_a_numbers);
int		dupe_numbers(long *stack_a, int stack_a_numbers);
int		stack_number_check(char *numbers);
int		stack_size(int argc, char **argv);
int		seperating_input_numbers(long *stack_a, int *stack_a_numbers, char **argv);
int		sort_stack_check(long *stack_a, int *stack_a_numbers);
void	ft_parameters(long *stack_a, long *stack_b, int *stack_a_numbers, int *stack_b_numbers);
void	free_stacks(long *stack_a, long *stack_b, int *stack_a_numbers, int *stack_b_numbers);

//void	printList(long *stack_a, int size);
#endif