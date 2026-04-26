/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahelman <ahelman@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 21:14:19 by ahelman           #+#    #+#             */
/*   Updated: 2026/04/26 19:46:27 by ahelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	swap_node(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = stack->top->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
}

void	sa(t_ps *ps)
{
	if (!ps || ps->a.size < 2)
		return ;
	swap_node(&ps->a);
	write(1, "sa\n", 3);
	ps->stats.sa++;
	ps->stats.total++;
}

void	sb(t_ps *ps)
{
	if (!ps || ps->b.size < 2)
		return ;
	swap_node(&ps->b);
	write(1, "sb\n", 3);
	ps->stats.sb++;
	ps->stats.total++;
}

void	ss(t_ps *ps)
{
	if (!ps || (ps->a.size < 2 && ps->b.size < 2))
		return ;
	swap_node(&ps->a);
	swap_node(&ps->b);
	write(1, "ss\n", 3);
	ps->stats.ss++;
	ps->stats.total++;
}
