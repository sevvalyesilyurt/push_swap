#include "includes/push_swap.h"
#include <unistd.h>

static void	reverse_rotate_node(t_node **src)
{
	t_node	*new_start;
	t_node	*new_end;

	if (!src || !*src || !(*src)->next)
		return ;
	new_start = last_node(*src);
	new_end = (*src);
	while (new_end->next->next)
		new_end = new_end->next;
	new_end->next = NULL;
	new_start->next = (*src);
	*src = new_start;
}

void	rrr(t_node **a, t_node **b, int print)
{
	if (!a || !*a || !(*a)->next)
		return ;
	if (!b || !*b || !(*b)->next)
		return ;
	reverse_rotate_node(a);
	reverse_rotate_node(b);
	if (print)
		write(1, "rrr\n", 4);
}

void	rra(t_node **a, int print)
{
	if (!a || !*a || !(*a)->next)
		return ;
	reverse_rotate_node(a);
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_node **b, int print)
{
	if (!b || !*b || !(*b)->next)
		return ;
	reverse_rotate_node(b);
	if (print)
		write(1, "rrb\n", 4);
}