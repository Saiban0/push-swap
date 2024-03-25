/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:44:41 by bchedru           #+#    #+#             */
/*   Updated: 2024/03/25 17:56:02 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rr_to_cheapest(t_list **a, t_list **b, t_list *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rr(a, b, 0);
	set_current_pos(*a);
	set_current_pos(*b);
}

static void	rrr_to_cheapest(t_list **a, t_list **b, t_list *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rrr(a, b, 0);
	set_current_pos(*a);
	set_current_pos(*b);
}

void	finish_rotation(t_list **stack, t_list *top, char name)
{
	while (*stack != top)
	{
		if (name == 'a')
		{
			if (top->above_median)
				ra(stack, 0);
			else
				rra(stack, 0);
		}
		else if (name == 'b')
		{
			if (top->above_median)
				rb(stack, 0);
			else
				rrb(stack, 0);
		}
	}
}

static void	process_stacks(t_list **a, t_list **b)
{
	t_list	*cheapest;

	cheapest = find_cheapest(*b);
	if (cheapest->above_median && cheapest->target->above_median)
		rr_to_cheapest(a, b, cheapest);
	else if (!(cheapest->above_median) && !(cheapest->target->above_median))
		rrr_to_cheapest(a, b, cheapest);
	finish_rotation(b, cheapest, 'b');
	finish_rotation(a, cheapest, 'a');
	pa(a, b, 0);
}

void	push_swap(t_list **a, t_list **b)
{
	int		len_a;
	t_list	*lowest;

	len_a = ft_lstsize(*a);
	while (len_a-- > 3)
		pb(b, a, 0);
	tiny_sort(a);
	while (*b)
	{
		init_nodes(*a, *b);
		process_stacks(a, b);
	}
	set_current_pos(*a);
	lowest = find_cheapest(*a);
	if (lowest->above_median)
		while (*a != lowest)
			ra(a, 0);
	else
		while (*a != lowest)
			rra(a, 0);
}
