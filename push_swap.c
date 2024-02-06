/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:38:58 by bchedru           #+#    #+#             */
/*   Updated: 2024/02/06 19:22:29 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_list	*youpi;
	t_list	*tralala;
	t_list	*tjhk;

	youpi = ft_lstnew(21);
	tralala = ft_lstnew(42);
	tjhk = ft_lstnew(84);
	ft_lstadd_front(&youpi, tralala);
	ft_lstadd_front(&youpi, tjhk);
	ft_reverse_rotate(&tralala, 'a');
	ft_printf("%d", youpi->next->next->content);
	return (0);
}
