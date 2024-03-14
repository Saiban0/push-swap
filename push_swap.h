/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:39:30 by bchedru           #+#    #+#             */
/*   Updated: 2024/03/14 17:02:14 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

int		ft_swap(t_list *stack, char a_or_b);
int		ft_push(t_list **src, t_list **dest, char a_or_b);
int		ft_rotate(t_list **stack, char a_or_b);
int		ft_reverse_rotate(t_list **stack, char a_or_b);
int		stack_sorted(t_list *stack);
void	tiny_sort(t_list **stack);
void	init_nodes(t_list *a, t_list *b);
void	set_current_pos(t_list *stack);
void	set_price(t_list *a, t_list *b);
t_list	*find_highest(t_list **stack);
t_list	*find_lowest(t_list **stack);
long	ft_atol(char *str);
void	clear_stack(t_list **stack);
void	stack_init(t_list **a, char **argv, int flag_free_heap);

#endif