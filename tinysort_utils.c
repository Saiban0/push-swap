/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tinysort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:22:51 by bchedru           #+#    #+#             */
/*   Updated: 2024/03/12 16:03:11 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_list *stack)
{
	if (stack == NULL)
		return (-1);
	while (stack ->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	find_highest(t_list **stack)
{
	int	max;

	max = (*stack)->content;
	while (stack)
	{
		if ((*stack)->content > max)
			max = (*stack)->content;
		stack = (*stack)->next;
	}
	return (max);
}

int	find_lowest(t_list **stack)
{
	int	min;

	min = (*stack)->content;
	while (stack)
	{
		if ((*stack)->content < min)
			min = (*stack)->content;
		stack = (*stack)->next;
	}
	return (min);
}

void	tiny_sort(t_list **stack)
{
	t_list	*highest;

	highest = find_highest(*stack);
	if (*stack == highest)
		ft_rotate(stack, 'a');
	else if ((*stack)->next == highest)
		ft_reverse_rotate(&stack, 'a');
	if ((*stack)->cost > (*stack)->next->cost)
		ft_swap(&stack, 'a');
}
