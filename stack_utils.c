/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:53:39 by bchedru           #+#    #+#             */
/*   Updated: 2024/03/26 17:36:56 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	append_node(t_list **stack, t_list *new)
{
	t_list	*last_node;

	if (NULL == stack)
		return ;
	if (NULL == *stack)
	{
		*stack = new;
		new->previous = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = new;
		new->previous = last_node;
	}
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
		temp = ft_lstnew((int) nbr);
		append_node(a, temp);
		i++;
	}
	if (flag_free_heap)
		ft_free_tab(argv);
}
