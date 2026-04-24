/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 16:13:38 by sevyesil          #+#    #+#             */
/*   Updated: 2026/04/24 18:42:50 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include <limits.h>

static int	abs_val(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void	rotate_stack(t_node **stack, int cost, int is_a)
{
	while (cost > 0)
	{
		if (is_a)
			ra(stack, 1);
		else
			rb(stack, 1);
		cost--;
	}
	while (cost < 0)
	{
		if (is_a)
			rra(stack, 1);
		else
			rrb(stack, 1);
		cost++;
	}
}

static void	do_rotate(t_node **a, t_node **b, int cost_a, int cost_b)
{
	while (cost_a > 0 && cost_b > 0)
	{
		rr(a, b, 1);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(a, b, 1);
		cost_a++;
		cost_b++;
	}
	rotate_stack(a, cost_a, 1);
	rotate_stack(b, cost_b, 0);
}

void	do_cheapest(t_node **a, t_node **b)
{
	t_node	*tmp;
	int		best_cost;
	int		cost_a;
	int		cost_b;

	tmp = *b;
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
	do_rotate(a, b, cost_a, cost_b);
	pa(a, b, 1);
}

void	final_rotate(t_node **a)
{
	int	size;
	int	min_pos;

	set_position(*a);
	size = size_node(*a);
	min_pos = find_min_pos(*a);
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			ra(a, 1);
			min_pos--;
		}
	}
	else
	{
		min_pos = size - min_pos;
		while (min_pos > 0)
		{
			rra(a, 1);
			min_pos--;
		}
	}
}
