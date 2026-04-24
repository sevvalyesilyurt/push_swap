/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 16:10:52 by sevyesil          #+#    #+#             */
/*   Updated: 2026/04/24 19:08:47 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	set_index(t_node *a)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	current = a;
	while (current)
	{
		index = 0;
		compare = a;
		while (compare)
		{
			if (compare->nbr < current->nbr)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

void	set_position(t_node *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return ;
	while (stack)
	{
		stack->pos = i;
		stack = stack->next;
		i++;
	}
}

int	find_min_pos(t_node *a)
{
	int		min;
	int		pos;

	if (!a)
		return (0);
	min = a->index;
	pos = a->pos;
	while (a)
	{
		if (a->index < min)
		{
			min = a->index;
			pos = a->pos;
		}
		a = a->next;
	}
	return (pos);
}

static int	get_target_pos(t_node *a, int b_index)
{
	t_node	*tmp;
	int		target_index;
	int		target_pos;

	target_index = INT_MAX;
	target_pos = 0;
	tmp = a;
	while (tmp)
	{
		if (tmp->index > b_index && tmp->index < target_index)
		{
			target_index = tmp->index;
			target_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (target_index == INT_MAX)
		target_pos = find_min_pos(a);
	return (target_pos);
}

void	set_target_pos(t_node *a, t_node *b)
{
	t_node	*tmp;

	tmp = b;
	while (tmp)
	{
		tmp->target_pos = get_target_pos(a, tmp->index);
		tmp = tmp->next;
	}
}

