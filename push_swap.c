/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:38:58 by bchedru           #+#    #+#             */
/*   Updated: 2024/02/08 17:01:13 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_list	*youpi;
	t_list	*tralala;
	t_list	*tjhk;
	t_list	*qwe;
	t_list	*rty;
	t_list	*uio;
	t_list	*b;

	youpi = ft_lstnew(21);
	tralala = ft_lstnew(42);
	tjhk = ft_lstnew(84);
	qwe = ft_lstnew(69);
	rty = ft_lstnew(420);
	uio = ft_lstnew(2);
	b = NULL;
	ft_lstadd_front(&youpi, tralala);
	ft_lstadd_front(&youpi, tjhk);
	ft_lstadd_front(&youpi, qwe);
	ft_lstadd_front(&youpi, rty);
	ft_lstadd_front(&youpi, uio);
	ft_push(&youpi, &b, 'b');
	while(youpi)
	{
		if(push_where(&b, youpi->content))
		{
			ft_push(&youpi, &b, 'b');
			ft_rotate(&b, 'b');
		}
		else
			ft_push(&youpi, &b, 'b');
	}
	while(b)
		ft_push(&b, &youpi, 'a');
	while(youpi)
	{
		ft_printf("%d\n",youpi->content);
		youpi = youpi->next;
	}
	return (0);
}
