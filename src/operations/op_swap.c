#include "includes/push_swap.h"
#include <unistd.h>

static void	swap_node(t_node **src)
{
	t_node	*tmp;

	if (!src || !*src || !(*src)->next)
		return ;
	tmp = (*src)->next;
	(*src)->next = (*src)->next->next;
	tmp->next = (*src);
	*src = tmp;
}

void	sa(t_node **a)
{
	if (!a || !*a || !(*a)->next)
		return ;
	swap_node(a);
	write(1, "sa\n", 3);
}
void	sb(t_node **b)
{
	if (!b || !*b || !(*b)->next)
		return ;
	swap_node(b);
	write(1, "sb\n", 3);
}
void	ss(t_node **a, t_node **b)
{
	if (!b || !*b || !(*b)->next)
		return ;
	if (!a || !*a || !(*a)->next)
		return ;
	swap_node(a);
	swap_node(b);
	write(1, "ss\n", 3);
}
// ekrana yazadırmayan sadece işlem yapan halleri

void	just_sa(t_node **a)
{
	swap_node(a);
}

void	just_sb(t_node **b)
{
	swap_node(b);
}

void	just_ss(t_node **a, t_node **b)
{
	if (!b || !*b || !(*b)->next)
		return ;
	if (!a || !*a || !(*a)->next)
		return ;
	swap_node(a);
	swap_node(b);
}
