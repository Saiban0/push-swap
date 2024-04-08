/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:08:16 by bchedru           #+#    #+#             */
/*   Updated: 2024/04/08 17:47:31 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_average(t_stack_node *stack)
{
	int				res;
	int				i;
	t_stack_node	*temp;

	i = 0;
	res = 0;
	temp = stack;
	while(temp)
	{
		res += temp->value;
		i++;
		temp = temp->next;
	}
	return (res / i);
}

static int	check_stack_underaverage(t_stack_node *stack, int average)
{
	t_stack_node	*temp;

	temp = stack;
	while(stack->next)
	{
		if (stack->value > average)
			return (1);
		stack = stack->next;
	}
	stack = temp;
	return (0);
}

void	push_average(t_stack_node **a, t_stack_node **b)
{
	int	average;
	int	len_a;

	average = stack_average(*a);
	len_a = 0;
	while (check_stack_underaverage(*a, average))
	{
		if((*a)->value > average)
			pb(b, a ,false);
		else
			ra(a, false);
	}
	len_a = stack_len(*a);
	while(len_a-- > 3)
		pb(b, a , false);
	set_current_position(*a);
	set_current_position(*b);
}
