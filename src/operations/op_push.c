#include "includes/push_swap.h"
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

void	pb(t_node **a, t_node **b)
{
	if (!a || !*a)
		return ;
	push_node(a, b);
	write(1, "pb\n", 3);
}

void	pa(t_node **b, t_node **a)
{
	if (!b || !*b)
		return ;
	push_node(b, a);
	write(1, "pa\n", 3);
}
// bu kısımdakiler sadece işlem yapıyor ekrana yazdırmıyor
// bench ve ona benzer durumlar için (bu yorumlar silinecek)
void	just_pb(t_node **a, t_node **b)
{
	push_node(a, b);
}

void	just_pa(t_node **b, t_node **a)
{
	push_node(b, a);
}
