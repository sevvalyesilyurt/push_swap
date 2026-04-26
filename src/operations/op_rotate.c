/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahelman <ahelman@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 21:16:13 by ahelman           #+#    #+#             */
/*   Updated: 2026/04/26 19:46:01 by ahelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	rev_rotate_node(t_stack *stack)
{
	t_node	*prev;
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	prev = NULL;
	last = stack->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack->top;
	stack->top = last;
}

void	rra(t_ps *ps)
{
	if (!ps || ps->a.size < 2)
		return ;
	rev_rotate_node(&ps->a);
	write(1, "rra\n", 4);
	ps->stats.rra++;
	ps->stats.total++;
}

void	rrb(t_ps *ps)
{
	if (!ps || ps->b.size < 2)
		return ;
	rev_rotate_node(&ps->b);
	write(1, "rrb\n", 4);
	ps->stats.rrb++;
	ps->stats.total++;
}

void	rrr(t_ps *ps)
{
	if (!ps || (ps->a.size < 2 && ps->b.size < 2))
		return ;
	rev_rotate_node(&ps->a);
	rev_rotate_node(&ps->b);
	write(1, "rrr\n", 4);
	ps->stats.rrr++;
	ps->stats.total++;
}
