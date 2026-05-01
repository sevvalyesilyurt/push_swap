/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 20:44:59 by sevyesil          #+#    #+#             */
/*   Updated: 2026/05/01 19:08:33 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <math.h>

static	int	find_max_pos(t_node *b)
{
	int	max;
	int	pos;
	int	i;

	max = b->nbr;
	pos = 0;
	i = 0;
	while (b)
	{
		if (b->nbr > max)
		{
			max = b->nbr;
			pos = i;
		}
		b = b->next;
		i++;
	}
	return (pos);
}

static void	push_chunks_to_b(t_ps *ps, int chunk_size)
{
	int	current_max;

	current_max = chunk_size;
	while (ps->a.size > 0)
	{
		if (ps->a.top->index <= current_max)
		{
			pb(ps);
			if (ps->b.top->index < current_max - (chunk_size / 2))
				rb(ps);
		}
		else
			ra(ps);
		if (ps->b.size >= current_max)
			current_max += chunk_size;
	}
}

static void	push_back_to_a(t_ps *ps)
{
	int	max_pos;

	while (ps->b.size > 0)
	{
		max_pos = find_max_pos(ps->b.top);
		if (max_pos <= ps->b.size / 2)
		{
			while (max_pos-- > 0)
				rb(ps);
		}
		else
		{
			max_pos = ps->b.size - max_pos;
			while (max_pos-- > 0)
				rrb(ps);
		}
		pa(ps);
	}
}

void	sort_medium(t_ps *ps)
{
	int	size;
	int	chunk_size;

	size = ps->a.size;
	chunk_size = sqrt(size);
	if (chunk_size < 1)
		chunk_size = 1;
	push_chunks_to_b(ps, chunk_size);
	push_back_to_a(ps);
}
