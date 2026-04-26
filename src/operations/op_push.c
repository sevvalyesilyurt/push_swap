#include "push_swap.h"
#include <unistd.h>

static void	push_node(t_node **src, t_node **dst)
{
	t_node	*tmp;

	if (!src || !dst || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}

void	pb(t_node **a, t_node **b, int print)
{
	if (!a || !*a)
		return ;
	push_node(a, b);
	if (print)
		write(1, "pb\n", 3);
}

void	pa(t_node **a, t_node **b, int print)
{
	if (!b || !*b)
		return ;
	push_node(b, a);
	if (print)
		write(1, "pa\n", 3);
}

