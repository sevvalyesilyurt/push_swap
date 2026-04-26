/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahelman <ahelman@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 16:18:38 by sevyesil          #+#    #+#             */
/*   Updated: 2026/04/26 23:00:49 by ahelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pos(t_node *a, int i)
{
	int pos;

	pos = 0;
	while (a)
	{
		if (a->index == i)
			return (pos);
		a = a->next;
		pos++;
	}
	return (-1);
}

void	sort_simple(t_node **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->nbr;
	second = (*a)->next->nbr;
	third = (*a)->next->next->nbr;
	if (first > second && second < third && first < third)
		sa(a, 1);
	else if (first > second && second > third)
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (first > second && second < third && first > third)
		ra(a, 1);
	else if (first < second && second > third && first < third)
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (first < second && second > third && first > third)
		rra(a, 1);
}

void	sort_small(t_node **a, t_node **b)
{
	int	min_pos;
	int	size;

	while (size_node(*a) > 3)
	{
		min_pos = find_min_pos(*a);
		size = size_node(*a);

		if (min_pos <= size / 2)
			while (min_pos--)
				ra(a, 1);
		else
			while (size - min_pos++)
				rra(a, 1);

		pb(a, b, 1);
	}
	sort_simple(a);
	while (*b)
		pa(a, b, 1);
}

void	sort_complex(t_node **a, t_node **b)
{
	while (size_node(*a) > 3)
	{
		set_position(*a);
		set_position(*b);
		set_target_pos(*a, *b);
		set_cost(*a, *b);
		do_cheapest(a, b);
	}
	sort_simple(a);
	while (*b)
	{
		set_position(*a);
		set_position(*b);
		set_target_pos(*a, *b);
		set_cost(*a, *b);
		do_cheapest(a, b);
	}
	final_rotate(a);
}
