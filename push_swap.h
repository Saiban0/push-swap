/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:39:30 by bchedru           #+#    #+#             */
/*   Updated: 2024/02/09 11:24:17 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

int		ft_swap(t_list *stack, char a_or_b);
int		ft_push(t_list **src, t_list **dest, char a_or_b);
int		ft_rotate(t_list **stack, char a_or_b);
int		ft_reverse_rotate(t_list **stack, char a_or_b);
int		stack_sorted(t_list *stack);


#endif