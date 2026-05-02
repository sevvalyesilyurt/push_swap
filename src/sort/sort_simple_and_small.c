/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple_and_small.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 16:10:52 by sevyesil          #+#    #+#             */
/*   Updated: 2026/05/02 22:04:25 by sevyesil         ###   ########.fr       */
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

static void	sort_three(t_ps *ps)
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

static	void	sort_five_number(t_ps *ps)
{
	int	min;

	min = 0;
	while (ps->a.size > 3)
	{
		min = find_min_pos(ps->a.top);
		if (min <= ps->a.size / 2)
		{
			while (min--)
				ra(ps);
			pb(ps);
		}
		else
		{
			while (min-- && find_min_pos(ps->a.top) != 0)
				rra(ps);
			pb(ps);
		}
	}
	sort_three(ps);
	while (ps->b.size > 0)
		pa(ps);
}

void	sort_small(t_ps *ps)
{
	if (ps->a.size < 2)
		return ;
	if (ps->a.size == 2)
	{
		if (ps->a.top->nbr > ps->a.top->next->nbr)
			sa(ps);
		return ;
	}
	if (ps->a.size == 3)
	{
		sort_three(ps);
		return ;
	}
	if (ps->a.size <= 5)
	{
		sort_five_number(ps);
		return ;
	}
}
