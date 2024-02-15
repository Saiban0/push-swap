/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:23:23 by bchedru           #+#    #+#             */
/*   Updated: 2024/02/15 18:10:20 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init_nodes(t_list *a, t_list *b)
{
	set_current_pos(a);
	set_current_pos(b);
	set_targets(a, b);
	set_price(a, b);
	set_cheapest(b);
}

void	set_current_pos(t_list *stack)
{
	int	pos;
	int	median;

	pos = 0;
	median = ft_lstsize(stack) / 2;
	while(stack)
	{
		stack->curr_pos = pos;
		if (pos <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		pos++;
		stack = stack->next;
	}
}

void	set_price(t_list *a, t_list *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(a);
	len_b = ft_lstsize(b);
	while(b)
	{
		b->cost = b->curr_pos;
		if (!b->above_median)
			b->cost = len_b - (b->curr_pos);
		if (b->target->above_median)
			b->cost += b->target->curr_pos;
		else
			b->cost + len_a - (b->target->curr_pos);
		b = b->next;
	}
}