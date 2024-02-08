/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:22:00 by bchedru           #+#    #+#             */
/*   Updated: 2024/02/08 16:10:59 by bchedru          ###   ########.fr       */
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
	int		size;

	tmp = (*stack)->next;
	size = ft_lstsize(*stack);
	if (size <= 1)
		return (1);
	else if (size == 2)
		return (ft_swap(*stack, a_or_b));
	ft_lstadd_front(&tmp, *stack);
	(*stack)->next = NULL;
	*stack = tmp;
	ft_printf("rr %c\n", a_or_b);
	return (0);
}
