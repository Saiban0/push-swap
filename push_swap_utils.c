/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:22:00 by bchedru           #+#    #+#             */
/*   Updated: 2024/03/14 17:09:49 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(t_list *stack, char a_or_b)
{
	int	tmp;

	tmp = stack->content;
	if (ft_lstsize(stack) <= 1)
		return (1);
	stack->content = stack->next->content;
	stack->next->content = tmp;
	ft_printf("s %c\n", a_or_b);
	return (0);
}

int	ft_push(t_list **src, t_list **dest, char a_or_b)
{
	t_list	*tmp;

	tmp = (*src)->next;
	if (ft_lstsize(*src) == 0)
		return (1);
	ft_lstadd_front(dest, *src);
	*src = tmp;
	ft_printf("p %c\n", a_or_b);
	return (0);
}

int	ft_rotate(t_list **stack, char a_or_b)
{
	t_list	*tmp;
	int		size;

	tmp = (*stack)->next;
	size = ft_lstsize(*stack);
	if (size <= 1)
		return (1);
	else if (size == 2)
		return (ft_swap(*stack, a_or_b));
	ft_lstadd_back(&tmp, *stack);
	(*stack)->next = NULL;
	*stack = tmp;
	ft_printf("r %c\n", a_or_b);
	return (0);
}

int	ft_reverse_rotate(t_list **stack, char a_or_b)
{
	t_list	*tmp;
	t_list	**end;
	int		size;

	tmp = *stack;
	end = stack;
	size = ft_lstsize(*stack);
	if (size <= 1)
		return (1);
	else if (size == 2)
		return (ft_swap(*stack, a_or_b));
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		while ((*end)->next->next)
			end = &(*end)->next;
		ft_lstadd_front(stack, tmp);
		(*end)->next = NULL;
	}
	ft_printf("rr %c\n", a_or_b);
	return (0);
}

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
	while (!ft_isalpha(str[i]))
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
