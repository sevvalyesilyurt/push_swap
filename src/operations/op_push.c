/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahelman <ahelman@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 21:12:55 by ahelman           #+#    #+#             */
/*   Updated: 2026/04/26 19:45:39 by ahelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	push_node(t_stack *src, t_stack *dst)
{
	t_node	*tmp;

	if (!src || !dst || !src->top)
		return ;
	tmp = src->top;
	src->top = src->top->next;
	tmp->next = dst->top;
	dst->top = tmp;
	src->size--;
	dst->size++;
}

void	pa(t_ps *ps)
{
	if (!ps || !ps->b.top)
		return ;
	push_node(&ps->b, &ps->a);
	write(1, "pa\n", 3);
	ps->stats.pa++;
	ps->stats.total++;
}

void	pb(t_ps *ps)
{
	if (!ps || !ps->a.top)
		return ;
	push_node(&ps->a, &ps->b);
	write(1, "pb\n", 3);
	ps->stats.pb++;
	ps->stats.total++;
}
