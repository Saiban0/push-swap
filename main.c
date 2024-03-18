/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:58:10 by bchedru           #+#    #+#             */
/*   Updated: 2024/03/18 16:20:45 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **a, t_list **b)
{
	while (ft_lstsize(*a) > 3)
		ft_push(a, b, 'b');
	tiny_sort(a);
}

int	check_syntax(char *argv)
{
	int	i;

	i = 0;
	if (!argv || !argv[0])
		return (1);
	while (argv[i])
	{
		if ((argv[i] != '-' && argv[i] != '+')
			&& !(argv[i] >= '0' && argv[i] <= '9'))
			return (1);
		i++;
	}
	argv++;
	return (0);
}

void	ft_free_stack(t_list **stack)
{
	t_list	*temp;

	if (!*stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(stack);
		*stack = temp;
	}
	*stack = NULL;
}

void	ft_free_tab(char **argv)
{
	int	i;

	i = -1;
	if (!argv || !*argv)
		return ;
	while (argv[i])
		free(argv[i++]);
}

void	error_free(t_list **a, char **argv, int flag_free_heap)
{
	ft_free_stack(a);
	if (flag_free_heap)
		ft_free_tab(argv);
	write(2, "Error\n", 6);
	exit(1);
}

void	stack_init(t_list **a, char **argv, int flag_free_heap)
{
	long	nbr;
	int		i;
	t_list	*temp;

	i = 1;
	temp = NULL;
	while (argv[i])
	{
		if (check_syntax(argv[i]))
			error_free(a, argv, flag_free_heap);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, argv, flag_free_heap);
		// if (error_repetition(*a, (int)nbr))line
		// 	error_free(a, argv, flag_free_heap);
		temp = ft_lstnew((int) nbr);
		ft_lstadd_back(a, temp);
		i++;
	}
	if (flag_free_heap)
		ft_free_tab(argv);
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
	display_stack(&a);
	clear_stack(&a);
}
