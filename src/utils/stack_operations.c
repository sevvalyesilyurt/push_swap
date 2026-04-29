/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:39:55 by sevyesil          #+#    #+#             */
/*   Updated: 2026/04/29 13:40:23 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_node	*new_node(long number)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->nbr = number;
	new_node->index = 0;
	new_node->next = NULL;
	return (new_node);
}

int	size_node(t_node *node)
{
	int	size;

	size = 0;
	while (node)
	{
		node = node->next;
		size++;
	}
	return (size);
}

t_node	*last_node(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	add_front(t_node **node, t_node *new)
{
	if (!new || !node)
		return ;
	new->next = *node;
	*node = new;
}

void	add_back(t_node **node, t_node *new)
{
	t_node	*temp;

	if (!new || !node)
		return ;
	if (!*node)
	{
		*node = new;
		return ;
	}
	temp = last_node(*node);
	temp->next = new;
}
