/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 16:13:38 by sevyesil          #+#    #+#             */
/*   Updated: 2026/05/02 03:00:45 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	abs_val(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void	rotate_stack(t_ps *ps, int cost, int is_a)
{
	while (cost > 0)
	{
		if (is_a)
			ra(ps);
		else
			rb(ps);
		cost--;
	}
	while (cost < 0)
	{
		if (is_a)
			rra(ps);
		else
			rrb(ps);
		cost++;
	}
}

static void	do_rotate(t_ps *ps, int cost_a, int cost_b)
{
	while (cost_a > 0 && cost_b > 0)
	{
		rr(ps);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(ps);
		cost_a++;
		cost_b++;
	}
	rotate_stack(ps, cost_a, 1);
	rotate_stack(ps, cost_b, 0);
}

void	do_cheapest(t_ps *ps)
{
	t_node	*tmp;
	int		best_cost;
	int		cost_a;
	int		cost_b;

	tmp = ps->b.top;
	best_cost = INT_MAX;
	while (tmp)
	{
		if (abs_val(tmp->cost_a) + abs_val(tmp->cost_b) < best_cost)
		{
			best_cost = abs_val(tmp->cost_a) + abs_val(tmp->cost_b);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	do_rotate(ps, cost_a, cost_b);
	pa(ps);
}

void	final_rotate(t_ps *ps)
{
	int	size;
	int	min_pos;

	set_position(ps->a.top);
	size = ps->a.size;
	min_pos = find_min_pos(ps->a.top);
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			ra(ps);
			min_pos--;
		}
	}
	else
	{
		min_pos = size - min_pos;
		while (min_pos > 0)
		{
			rra(ps);
			min_pos--;
		}
	}
}
