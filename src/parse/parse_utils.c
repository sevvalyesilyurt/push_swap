/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 18:13:25 by sevyesil          #+#    #+#             */
/*   Updated: 2026/04/26 17:01:30 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include "push_swap.h"
#include <limits.h>
#include <stdio.h>

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;

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

void	parse_numbers(t_node **a, char *str)
{
	long	number;
	t_node	*tmp;

	tmp = *a;
	if (ps_validatestringkontrolu(str) == 0)
		error_exit(a);
	number = ft_atoi(str);
	if (number < INT_MIN || number > INT_MAX)
		error_exit(a);
	while (tmp)
	{
		if (tmp->nbr == number)
			error_exit(a);
		tmp = tmp->next;
	}
	add_back(a, new_node((int)number));
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
