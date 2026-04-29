/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple_and_small.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 16:10:52 by sevyesil          #+#    #+#             */
/*   Updated: 2026/04/29 13:39:29 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_simple(t_ps *ps)
{
	int	min_pos;
	int	size;

	while (ps->a.size > 0)
	{
		min_pos = find_min_pos(ps->a.top);
		size = ps->a.size;
		if (min_pos <= size / 2)
		{
			while (min_pos-- > 0)
				ra(ps);
		}
		else
		{
			min_pos = size - min_pos;
			while (min_pos-- > 0)
				rra(ps);
		}
		if (stack_is_sorted(ps->a.top) == 1 && ps->b.size == 0)
			return ;
		pb(ps);
	}
	while (ps->b.size > 0)
		pa(ps);
}

void	sort_small(t_ps *ps)
{
	int	a;
	int	b;
	int	c;

	a = ps->a.top->index;
	b = ps->a.top->next->index;
	c = ps->a.top->next->next->index;
	if (a > b && b < c && a < c)
		sa(ps);
	else if (a > b && b > c)
	{
		sa(ps);
		rra(ps);
	}
	else if (a > b && b < c && a > c)
		ra(ps);
	else if (a < b && b > c && a < c)
	{
		sa(ps);
		ra(ps);
	}
	else if (a < b && b > c && a > c)
		rra(ps);
}
