/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 19:01:56 by sevyesil          #+#    #+#             */
/*   Updated: 2026/05/02 22:08:18 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static	int	parse_flags(t_ps *ps, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (argv[i][2] == '\0')
			error_exit(ps);
		if (ft_strcmp(argv[i], "--bench") == 0)
			ps->flags.bench = 1;
		else if (ft_strcmp(argv[i], "--adaptive") == 0)
			ps->flags.strategy = ADAPTIVE;
		else if (ft_strcmp(argv[i], "--simple") == 0)
			ps->flags.strategy = SIMPLE;
		else if (ft_strcmp(argv[i], "--medium") == 0)
			ps->flags.strategy = MEDIUM;
		else if (ft_strcmp(argv[i], "--complex") == 0)
			ps->flags.strategy = COMPLEX;
		else
			error_exit(ps);
		i++;
	}
	return (i);
}

static	void	parse_split(t_ps *ps, char *str)
{
	char	**new_str;
	int		j;

	j = 0;
	if (str == NULL || str[0] == '\0')
		error_exit(ps);
	new_str = ft_split(str, ' ');
	if (!new_str || !new_str[0])
	{
		parse_free_split(new_str);
		error_exit(ps);
	}
	while (new_str[j])
	{
		parse_numbers(ps, new_str[j]);
		j++;
	}
	parse_free_split(new_str);
}

void	parse_main(t_ps *ps, int argc, char **argv)
{
	int	i;

	i = parse_flags(ps, argc, argv);
	if (i == argc)
		return ;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			error_exit(ps);
		parse_split(ps, argv[i]);
		i++;
	}
}
