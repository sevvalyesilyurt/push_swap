/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahelman <ahelman@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 19:01:56 by sevyesil          #+#    #+#             */
/*   Updated: 2026/04/19 19:43:32 by ahelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <unistd.h>
#include "push_swap.h"
#include <limits.h>

void free_split(char **split)
{
	int i;

	i = 0;
	if (!split)
		return;

	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] != '\0' && s1[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}

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
				debug = 1;
			else if (ft_strcmp(argv[i], "-v") == 0)
				verbose = 1;
			else
				break ;
		}
		else
			break ;
		i++;
	}
	return (i);
}

void	parse_numbers(t_node **a, char *str)
{
	long	number;
	t_node	*tmp;

	tmp = *a;
	if (ps_validatestringkontrolu(str) == 0)
		error_exit(a);
	number = ft_atol(str);
	if (number < INT_MIN || number > INT_MAX)
		error_exit(a);
	while (tmp)
	{
		if (tmp->nbr == number)
			error_exit(a);
		tmp = tmp->next;
	}
	ft_lstadd_back(a, ft_lstnew((int)number));
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

int	ps_validatestringkontrolu(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	if (str[0] == '\0')
		return (0);
	if (str[0] == '+' || str[0] == '-')
		i++;
	if (ft_strlen(str) <= 1 && (str[0] == '+' || str[0] == '-'))
		return (0);
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}


void parse_main(t_node **a, int argc, char **argv)
{
	int	i;

	i = parse_flags(argc, argv);

	while (i < argc)
	{
		parse_split(a, argv[i]);
		i++;
	}
}
