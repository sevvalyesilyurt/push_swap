/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 20:32:10 by sevyesil          #+#    #+#             */
/*   Updated: 2026/05/02 03:36:51 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static	void	set_cost(t_ps *ps)
{
	int			size_a;
	int			size_b;
	t_node		*tmp;

	size_a = ps->a.size;
	size_b = ps->b.size;
	tmp = ps->b.top;
	while (tmp)
	{
		if (tmp->pos <= size_b / 2)
			tmp->cost_b = tmp->pos;
		else
			tmp->cost_b = tmp->pos - size_b;
		if (tmp->target_pos <= size_a / 2)
			tmp->cost_a = tmp->target_pos;
		else
			tmp->cost_a = tmp->target_pos - size_a;
		tmp = tmp->next;
	}
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

static	void	set_target_pos(t_node *a, t_node *b)
{
	t_node	*tmp;

	tmp = b;
	while (tmp)
	{
		tmp->target_pos = get_target_pos(a, tmp->index);
		tmp = tmp->next;
	}
}

void	sort_complex(t_ps *ps)
{
	while (ps->a.size > 3)
		pb(ps);
	sort_small(ps);
	while (ps->b.top)
	{
		set_position(ps->a.top);
		set_position(ps->b.top);
		set_target_pos(ps->a.top, ps->b.top);
		set_cost(ps);
		do_cheapest(ps);
	}
	final_rotate(ps);
}
