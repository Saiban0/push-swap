/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:58:10 by bchedru           #+#    #+#             */
/*   Updated: 2024/03/21 15:40:39 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort(t_list **stack)
{
	t_list	*highest;

	highest = find_highest(*stack);
	if (*stack == highest)
		ra(stack, 0);
	else if ((*stack)->next == highest)
		rra(stack, 0);
	if ((*stack)->content > (*stack)->next->content)
		sa(stack, 0);
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
