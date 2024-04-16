/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:59:31 by bchedru           #+#    #+#             */
/*   Updated: 2024/04/16 18:56:27 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "get_next_line.h"
#include <stdio.h>

static int	ft_strcmp(const char *s1, const char *s2)
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

static void	error(t_stack_node *a, t_stack_node *b)
{
	free_stack(&a);
	free_stack(&b);
	write(STDOUT_FILENO, "Error\n", 6);
	exit(1);
}

static void	parse_cmd(char *cmd, t_stack_node *a, t_stack_node *b)
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

static void	gnl_loop(int fd, t_stack_node *a, t_stack_node *b)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		parse_cmd(line, a, b);
		line = get_next_line(fd);
	}
}
static void	print_stack(t_stack_node *a)
{
	while (a)
	{
		printf("%d\n", a->value);
		a = a->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				len;

	a = NULL;
	b = NULL;
	len = 0;
	if (argc == 1)
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	stack_init(&a, argv + 1, argc == 2);
	len = stack_len(a);
	gnl_loop(STDIN_FILENO, a, b);
	printf("%d == %d\n", stack_len(a), len);
	if (stack_sorted(a) && len == stack_len(a))
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
	print_stack(a);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
