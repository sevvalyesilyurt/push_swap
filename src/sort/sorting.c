/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 16:18:38 by sevyesil          #+#    #+#             */
/*   Updated: 2026/04/24 18:39:39 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min(t_node *a)
{
	int	min;

	min = a->nbr;
	while (a)
	{
		if (a->nbr < min)
			min = a->nbr;
		a = a->next;
	}
	return (min);
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
	int	min;

	while (size_node(*a) > 3)
	{
		min = find_min(*a);
		while ((*a)->nbr != min)
			ra(a, 1);
		pb(a, b, 1);
	}
	sort_simple(a);
	while (*b)
		pa(a, b, 1);
}


void	sort_medium(t_node **a, t_node **b)
{
	int	size;
	int	min_pos;

	while (*a)
	{
		size = size_node(*a);
		min_pos = find_min_pos(*a);
		if (min_pos <= size / 2)
		{
			while (min_pos-- > 0)
				ra(a, 1);
		}
		else
		{
			min_pos = size - min_pos;
			while (min_pos-- > 0)
				rra(a, 1);
		}
		pb(a, b, 1);
	}
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
