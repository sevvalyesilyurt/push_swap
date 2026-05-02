/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahelman <ahelman@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 21:16:13 by ahelman           #+#    #+#             */
/*   Updated: 2026/05/02 10:53:58 by ahelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	rotate_node(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	stack->top = stack->top->next;
	first->next = NULL;
	last = stack->top;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	ra(t_ps *ps)
{
	if (!ps || ps->a.size < 2)
		return ;
	rotate_node(&ps->a);
	write(1, "ra\n", 3);
	ps->stats.ra++;
	ps->stats.total++;
}

void	rb(t_ps *ps)
{
	if (!ps || ps->b.size < 2)
		return ;
	rotate_node(&ps->b);
	write(1, "rb\n", 3);
	ps->stats.rb++;
	ps->stats.total++;
}

void	rr(t_ps *ps)
{
	if (!ps || (ps->a.size < 2 && ps->b.size < 2))
		return ;
	rotate_node(&ps->a);
	rotate_node(&ps->b);
	write(1, "rr\n", 3);
	ps->stats.rr++;
	ps->stats.total++;
}
