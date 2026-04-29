/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:10:30 by sevyesil          #+#    #+#             */
/*   Updated: 2026/04/29 13:12:45 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

long	ft_atol(const char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

void	free_stack(t_node **node)
{
	t_node	*temp;
	t_node	*next;

	if (!node)
		return ;
	temp = *node;
	while (temp)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	*node = NULL;
}

void	error_exit(t_ps *ps)
{
	if (ps)
	{
		if (ps->a.top)
			free_stack(&(ps->a.top));
		if (ps->b.top)
			free_stack(&(ps->b.top));
	}
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
