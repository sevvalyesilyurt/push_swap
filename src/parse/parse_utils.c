/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 18:13:25 by sevyesil          #+#    #+#             */
/*   Updated: 2026/04/29 13:12:16 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <limits.h>

void	parse_free_split(char **split)
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

int	ps_validate_string_control(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

void	parse_numbers(t_ps *ps, char *str)
{
	long	number;
	t_node	*tmp;

	if (ps_validate_string_control(str) == 0)
		error_exit(ps);
	number = ft_atol(str);
	if (number < INT_MIN || number > INT_MAX)
		error_exit(ps);
	tmp = ps->a.top;
	while (tmp)
	{
		if (tmp->nbr == (int)number)
			error_exit(ps);
		tmp = tmp->next;
	}
	add_back(&(ps->a.top), new_node((int)number));
	ps->a.size++;
}
