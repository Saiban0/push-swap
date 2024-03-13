/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:58:10 by bchedru           #+#    #+#             */
/*   Updated: 2024/03/13 15:43:09 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **a, t_list **b)
{
	while(ft_lstsize(*a) > 3)
		ft_push(a, b, 'b');
	tiny_sort(a);
	
}

void	stack_init(t_list **a, char **argv, int flag_free_heap)
{
	long	nbr;
	int		i;
	t_list	*temp;

	i = 0;
	temp = NULL;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(a, argv, flag_free_heap);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, argv, flag_free_heap);
		if (error_repetition(*a, (int)nbr))
			error_free(a, argv, flag_free_heap);
		temp = ft_lstnew((int) nbr);
		ft_lstadd_back(a, temp);
		i++;
	}
	if (flag_free_heap)
		free_matrix(argv);
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
	if (!stack_sorted(a))
	{
		if (ft_lstsize(a) == 2)
			ft_swap(a, 'a');
		else if (ft_lstsize(a) == 3)
			tiny_sort(&a);
		else
			push_swap(&a, &b);
	}
	clear_stack(&a);
}
