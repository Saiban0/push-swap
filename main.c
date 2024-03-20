/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:58:10 by bchedru           #+#    #+#             */
/*   Updated: 2024/03/20 17:07:34 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		//move_nodes(a, b);
	}
	set_current_pos(*a);
	lowest = find_lowest(*a);
	if (lowest->above_median)
		while (*a != lowest)
			ra(a, 0);
	else
		while (*a != lowest)
			rra(a, 0);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	stack_init(&a, argv, 0);
	init_nodes(a, b);
	if (!stack_sorted(a))
	{
		if (ft_lstsize(a) == 2)
			sa(&a, 0);
		else if (ft_lstsize(a) == 3)
			tiny_sort(&a);
		else
			push_swap(&a, &b);
	}
	display_stack(&a);
	clear_stack(&a);
}
