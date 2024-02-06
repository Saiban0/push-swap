/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:43:41 by kcouchma          #+#    #+#             */
/*   Updated: 2024/02/06 16:35:07 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*add2list;

	add2list = malloc(sizeof(t_list));
	if (add2list)
	{
		add2list->content = content;
		add2list->next = NULL;
	}
	return (add2list);
}
