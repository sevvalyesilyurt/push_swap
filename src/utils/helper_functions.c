/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 21:28:19 by sevyesil          #+#    #+#             */
/*   Updated: 2026/04/29 11:30:28 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	free_stack(t_node **node)
{
	t_node	*temp;
	t_node	*next;

	if (!node)
		return ;
	temp = *node;
	while (temp)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	*node = NULL;
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
