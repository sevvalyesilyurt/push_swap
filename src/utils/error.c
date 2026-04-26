/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahelman <ahelman@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 21:28:19 by sevyesil          #+#    #+#             */
/*   Updated: 2026/04/26 20:59:18 by ahelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	free_stack(t_node **stack)
{
	t_node	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	error_exit(t_ps *ps)
{
	if (ps)
	{
		if (ps->a.top)
			free_stack(&(ps->a.top));
		if (ps->b.top)
			free_stack(&(ps->b.top));
	}
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
