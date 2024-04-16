/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:59:31 by bchedru           #+#    #+#             */
/*   Updated: 2024/04/16 17:06:24 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "get_next_line.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	error(t_stack_node *a, t_stack_node *b)
{
	free_stack(&a);
	free_stack(&b);
	write(STDOUT_FILENO, "Error\n", 6);
	exit(1);
}

void	parse_cmd(char *cmd, t_stack_node *a, t_stack_node *b)
{
	if (ft_strcmp(cmd, "pa\n"))
		pa(&a, &b, true);
	else if (ft_strcmp(cmd, "pb\n"))
		pb(&b, &a, true);
	else if (ft_strcmp(cmd, "sa\n"))
		sa(&a, true);
	else if (ft_strcmp(cmd, "sb\n"))
		sb(&b, true);
	else if (ft_strcmp(cmd, "ra\n"))
		ra(&b, true);
	else if (ft_strcmp(cmd, "rb\n"))
		rb(&b, true);
	else if (ft_strcmp(cmd, "rr\n"))
		rr(&a, &b, true);
	else if (ft_strcmp(cmd, "rra\n"))
		rra(&a, true);
	else if (ft_strcmp(cmd, "rrb\n"))
		rrb(&b, true);
	else if (ft_strcmp(cmd, "rrr\n"))
		rrr(&a, &b, true);
	else
		error(a, b);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*cmd;
	int				len;

	a = NULL;
	b = NULL;
	cmd = "\0";
	len = 0;
	if (argc == 1)
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	stack_init(&a, argv, argc == 2);
	len = stack_len(a);
	cmd = get_next_line(STDIN_FILENO);
	parse_cmd(cmd, a, b);
	if (stack_sorted(a) && stack_len(a) == len)
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
	free(a);
	return (0);
}
