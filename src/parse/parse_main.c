/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahelman <ahelman@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 19:01:56 by sevyesil          #+#    #+#             */
/*   Updated: 2026/04/27 00:43:32 by ahelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

int	parse_flags(t_ps *ps, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc && argv[i][0] == '-')
	{
		if (argv[i][1] == '\0')
			error_exit(ps);
		if (ft_strcmp(argv[i], "--debug") == 0)
			ps->flags.bench = 1;
		else if (ft_strcmp(argv[i], "-v") == 0)
			ps->flags.strategy = 0;
		else
			break ;
		i++;
	}
	return (i);
}

void	parse_split(t_ps *ps, char *str)
{
	char	**new_str;
	int		j;

	j = 0;
	if (str == NULL || str[0] == '\0')
		error_exit(ps);
	new_str = ft_split(str, ' ');
	if (!new_str || !new_str[0])
	{
		free_split(new_str);
		error_exit(ps);
	}
	while (new_str[j])
	{
		parse_numbers(ps, new_str[j]);
		j++;
	}
	free_split(new_str);
}

void	parse_main(t_ps *ps, int argc, char **argv)
{
	int	i;

	i = parse_flags(ps, argc, argv);
	if (i == argc)
		exit(0);
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			error_exit(ps);
		parse_split(ps, argv[i]);
		i++;
	}
}
