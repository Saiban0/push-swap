/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:22:00 by bchedru           #+#    #+#             */
/*   Updated: 2024/03/19 14:29:31 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	long	res;
	int		i;
	int		sign;

	res = 0;
	i = 0;
	sign = 1;
	while (str[i] <= ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			sign *= -1;
			break ;
		}
		i++;
	}
	while (!ft_isalpha(str[i]) && str[i])
	{
		res = (res * 10) + str[i] - '0';
		i++;
	}
	return (res * sign);
}

void	clear_stack(t_list **stack)
{
	t_list	*current;
	t_list	*next;

	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void	display_stack(t_list **stack)
{
	while(*stack)
	{
		ft_printf("%d", (*stack)->content);
		*stack = (*stack)->next;
	}
}
