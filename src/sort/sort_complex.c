/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:56:32 by sevyesil          #+#    #+#             */
/*   Updated: 2026/04/17 17:08:39 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_dispatch(t_node **a, t_node **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size <= 1)
		return ;
	else if (size == 2)
	{
		if ((*a)->nbr> (*a)->next->nbr)
			sa(a);
	}
	else if (size == 3)
		sort_simple(a);
	else if (size <= 5)
		sort_small(a, b);
	else if (size <= 100)
		sort_medium(a, b);
	else
		sort_complex(a, b);
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
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

static	int	find_min(t_node *a)
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

void	sort_small(t_node **a, t_node **b)
{
	int	min;

	while (ft_lstsize(*a) > 3)
	{
		min = find_min(*a);
		while ((*a)->nbr != min)
			ra(a);
		pb(a, b);
	}
	sort_simple(a);
	while (*b)
		pa(a, b);
}
