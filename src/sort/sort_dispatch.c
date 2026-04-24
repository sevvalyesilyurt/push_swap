/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dispatch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 16:27:16 by sevyesil          #+#    #+#             */
/*   Updated: 2026/04/24 19:26:17 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_dispatch(t_node **a, t_node **b)
{
	int	size;

	size = size_node(*a);
	if (size <= 1)
		return ;
	else if (size == 2)
	{
		if ((*a)->nbr > (*a)->next->nbr)
			sa(a, 1);
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

void	set_cost(t_node *a, t_node *b)
{
	while (b)
	{
		b->cost_a = calculate_cost_a(a, b);
		b->cost_b = calculate_cost_b(b);
		b = b->next;
	}
}

int	calculate_cost_a(t_node *a, t_node *b)
{
	int	size;

	size = size_node(a);
	if (b->target_pos <= size / 2)
		return (b->target_pos);
	return (-(size - b->target_pos));
}

int	calculate_cost_b(t_node *b)
{
	int	size;

	size = size_node(b);
	if (b->pos <= size / 2)
		return (b->pos);
	return (-(size - b->pos));
}
