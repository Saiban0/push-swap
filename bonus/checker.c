/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:59:31 by bchedru           #+#    #+#             */
/*   Updated: 2024/04/09 17:56:34 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	
}
