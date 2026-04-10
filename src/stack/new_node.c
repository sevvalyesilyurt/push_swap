#include "includes/push_swap.h"
#include <stdlib.h>

t_node	*new_node(long number)
{
	t_node *new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->nbr = number;
	new_node->index = 0; 
	new_node->next = NULL;
	return (new_node);
}