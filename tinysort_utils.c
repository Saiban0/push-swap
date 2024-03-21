/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tinysort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:22:51 by bchedru           #+#    #+#             */
/*   Updated: 2024/03/21 15:41:39 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_list *stack)
{
	if (stack == NULL)
		return (-1);
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_list	*find_highest(t_list *stack)
{
	t_list	*max;

	max = stack;
	while (stack)
	{
		if (stack->content > max->content)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_list	*find_lowest(t_list *stack)
{
	t_list	*min;

	min = stack;
	while (stack)
	{
		if (stack->content < min->content)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_list	*find_last_node(t_list *stack)
{
	t_list	*last;

	last = stack;
	while (stack)
	{
		last = stack;
		stack = stack->next;
	}
	return (last);
}


t_list	*find_cheapest(t_list *stack)
{
	t_list	*min;

	min = stack;
	while (stack)
	{
		if (stack->cost < min->cost)
			min = stack;
		stack = stack->next;
	}
	return (min);
}