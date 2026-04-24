#include "push_swap.h"
#include <stdlib.h>

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
