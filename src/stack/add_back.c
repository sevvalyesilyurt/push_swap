#include "push_swap.h"

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
