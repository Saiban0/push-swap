/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tinysort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:22:51 by bchedru           #+#    #+#             */
/*   Updated: 2024/03/14 17:13:31 by bchedru          ###   ########.fr       */
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

t_list	*find_highest(t_list **stack)
{
	t_list	*max;

	max = *stack;
	while (stack)
	{
		if ((*stack)->content > max->content)
			max = *stack;
		stack = &(*stack)->next;
	}
	return (max);
}

t_list	*find_lowest(t_list **stack)
{
	t_list	*min;

	min = *stack;
	while (stack)
	{
		if ((*stack)->content < min->content)
			min = *stack;
		stack = &(*stack)->next;
	}
	return (min);
}

void	tiny_sort(t_list **stack)
{
	t_list	*highest;

	highest = find_highest(stack);
	if (*stack == highest)
		ft_rotate(stack, 'a');
	else if ((*stack)->next == highest)
		ft_reverse_rotate(stack, 'a');
	if ((*stack)->cost > (*stack)->next->cost)
		ft_swap(*stack, 'a');
}
