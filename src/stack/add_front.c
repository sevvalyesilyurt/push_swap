#include "includes/push_swap.h"

void	add_front(t_node **node, t_node *new)
{
	if (!new || !node)
		return ;
	new->next = *node;
	*node = new;
}
