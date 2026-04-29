/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dispatch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 16:27:16 by sevyesil          #+#    #+#             */
/*   Updated: 2026/04/29 11:34:17 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_sorted(t_node *a)
{
	while (a && a->next)
	{
		if (a->nbr > a->next->nbr)
			return (0);
		a = a->next;
	}
	return (1);
}

void	sort_dispatch(t_ps *ps)
{
	if (ps->a.size <= 3)
	{
		sort_small(ps);
		return ;
	}
	if (ps->flags.strategy == SIMPLE)
		sort_simple(ps);
	else if (ps->flags.strategy == MEDIUM)
		sort_medium(ps);
	else if (ps->flags.strategy == COMPLEX)
		sort_complex(ps);
}

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
	int		i;

	if (!a)
		return (0);
	min = a->nbr;
	pos = 0;
	i = 0;
	while (a)
	{
		if (a->nbr < min)
		{
			min = a->nbr;
			pos = i;
		}
		a = a->next;
		i++;
	}
	return (pos);
}

