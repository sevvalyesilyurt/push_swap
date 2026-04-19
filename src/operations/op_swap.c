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

void	sa(t_node **a, int print)
{
	if (!a || !*a || !(*a)->next)
		return ;
	swap_node(a);
	if (print)
		write(1, "sa\n", 3);
}
void	sb(t_node **b, int print)
{
	if (!b || !*b || !(*b)->next)
		return ;
	swap_node(b);
	if (print)
		write(1, "sb\n", 3);
}
void	ss(t_node **a, t_node **b, int print)
{
	if (!b || !*b || !(*b)->next)
		return ;
	if (!a || !*a || !(*a)->next)
		return ;
	swap_node(a);
	swap_node(b);
	if (print)
		write(1, "ss\n", 3);
}
// print bench için eklendi, yazdrıma durmunu kontrol etmek için
