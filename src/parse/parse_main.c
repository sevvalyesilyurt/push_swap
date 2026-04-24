/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 19:01:56 by sevyesil          #+#    #+#             */
/*   Updated: 2026/04/24 18:24:25 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include "push_swap.h"
#include <limits.h>
#include <stdio.h>

int	parse_flags(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			if (argv[i][1] == '\0')
				error_exit(NULL);
			if (ft_strcmp(argv[i], "--debug") == 0)
				printf("AHMET BU İF KONTROLU debug=1");
			else if (ft_strcmp(argv[i], "-v") == 0)
				printf("AHMET İF KONTROLU BU verbose=1");
			else
				break ;
		}
		else
			break ;
		i++;
	}
	return (i);
}

void	parse_split(t_node **a, char *str)
{
	char	**new_str;
	int		j;

	j = 0;
	if (str == NULL || str[0] == '\0')
		error_exit(a);
	new_str = ft_split(str, ' ');
	if (!new_str || !new_str[0])
	{
		free_split(new_str);
		error_exit(a);
	}
	while (new_str[j])
	{
		parse_numbers(a, new_str[j]);
		j++;
	}
	free_split(new_str);
}

void	parse_main(t_node **a, int argc, char **argv)
{
	int	i;

	i = parse_flags(argc, argv);

	while (i < argc)
	{
		parse_split(a, argv[i]);
		i++;
	}
}
