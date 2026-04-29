/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahelman <ahelman@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 20:32:10 by sevyesil          #+#    #+#             */
/*   Updated: 2026/04/29 14:52:52 by ahelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	set_cost(t_node *a, t_node *b)
{
	int	size_a;
	int	size_b;

	size_a = size_node(a);
	size_b = size_node(b);
	while (b)
	{
		if (b->pos <= size_b / 2)
			b->cost_b = b->pos;
		else
			b->cost_b = (b->pos - size_b);
		if (b->target_pos <= size_a / 2)
			b->cost_a = b->target_pos;
		else
			b->cost_a = (b->target_pos - size_a);
		b = b->next;
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
		set_cost(ps->a.top, ps->b.top);
		do_cheapest(ps);
	}
	final_rotate(ps);
}
