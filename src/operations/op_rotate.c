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

void	just_ra(t_node **a)
{
	rotate_node(a);
}

void	just_rb(t_node **b)
{
	rotate_node(b);
}

void	just_rr(t_node **a, t_node **b)
{
	if (!a || !*a || !(*a)->next)
		return ;
	if (!b || !*b || !(*b)->next)
		return ;
	rotate_node(a);
	rotate_node(b);
}

void	rr(t_node **a, t_node **b)
{
	if (!a || !*a || !(*a)->next)
		return ;
	if (!b || !*b || !(*b)->next)
		return ;
	rotate_node(a);
	rotate_node(b);
	write(1, "rr\n", 3);
}

void	ra(t_node **a)
{
	if (!a || !*a || !(*a)->next)
		return ;
	rotate_node(a);
	write(1, "ra\n", 3);
}

void	rb(t_node **b)
{
	if (!b || !*b || !(*b)->next)
		return ;
	rotate_node(b);
	write(1, "rb\n", 3);
}
