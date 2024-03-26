/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:39:30 by bchedru           #+#    #+#             */
/*   Updated: 2024/03/26 16:45:47 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

void	pa(t_list **a, t_list **b, int checker);
void	pb(t_list **b, t_list **a, int checker);
void	sa(t_list **a, int checker);
void	sb(t_list **b, int checker);
void	ss(t_list **a, t_list **b, int checker);
void	ra(t_list **a, int checker);
void	rb(t_list **b, int checker);
void	rr(t_list **a, t_list **b, int checker);
void	rra(t_list **a, int checker);
void	rrb(t_list **b, int checker);
void	rrr(t_list **a, t_list **b, int checker);
int		stack_sorted(t_list *stack);
void	tiny_sort(t_list **stack);
void	init_nodes(t_list *a, t_list *b);
void	set_current_pos(t_list *stack);
void	set_cheapest(t_list *b);
void	set_price(t_list *a, t_list *b);
t_list	*find_highest(t_list *stack);
t_list	*find_lowest(t_list *stack);
t_list	*find_cheapest(t_list *stack);
t_list	*find_last_node(t_list *stack);
long	ft_atol(char *str);
void	clear_stack(t_list **stack);
void	stack_init(t_list **a, char **argv, int flag_free_heap);
void	display_stack(t_list **stack);
void	push_swap(t_list **a, t_list **b);

#endif