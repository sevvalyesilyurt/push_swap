#include "includes/push_swap.h"
#include <unistd.h>

static void	rotate_node(t_node **src)
{
	t_node	*tmp;

	if (!src || !*src || !(*src)->next)
		return ;
	tmp = *src;
	*src = (*src)->next;
	last_node(*src)->next = tmp;
	tmp->next = NULL;
}

void	rrr(t_node **a, t_node **b, int print)
{
	if (!a || !*a || !(*a)->next)
		return ;
	if (!b || !*b || !(*b)->next)
		return ;
	rotate_node(a);
	rotate_node(b);
	if (print)
		write(1, "rr\n", 3);
}

void	rra(t_node **a, int print)
{
	if (!a || !*a || !(*a)->next)
		return ;
	rotate_node(a);
	if (print)
		write(1, "ra\n", 3);
}

void	rrb(t_node **b, int print)
{
	if (!b || !*b || !(*b)->next)
		return ;
	rotate_node(b);
	if (print)
		write(1, "rb\n", 3);
}