#include "push_swap.h"

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