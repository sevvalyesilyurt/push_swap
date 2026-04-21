void	set_cost(t_node *a, t_node *b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(a);
	size_b = ft_lstsize(b);
	while (b)
	{
		b->cost_b = b->pos;
		if (b->pos > size_b / 2)
			b->cost_b = (size_b - b->pos) * -1;
		b->cost_a = b->target_pos;
		if (b->target_pos > size_a / 2)
			b->cost_a = (size_a - b->target_pos) * -1;
		b = b->next;
	}
}

static void	rotate_stack(t_node **stack, int cost, int is_a)
{
	while (cost > 0)
	{
		if (is_a)
			ra(stack);
		else
			rb(stack);
		cost--;
	}
	while (cost < 0)
	{
		if (is_a)
			rra(stack);
		else
			rrb(stack);
		cost++;
	}
}
static void	do_rotate(t_node **a, t_node **b, int cost_a, int cost_b)
{
	while (cost_a > 0 && cost_b > 0)
	{
		rr(a, b);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(a, b);
		cost_a++;
		cost_b++;
	}
	rotate_stack(a, cost_a, 1);
	rotate_stack(b, cost_b, 0);
}
#include "push_swap.h"

void	final_rotate(t_node **a)
{
	int	size;
	int	min_pos;

	set_position(*a);
	size = ft_lstsize(*a);
	min_pos = find_min_pos(*a);
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			ra(a);
			min_pos--;
		}
	}
	else
	{
		min_pos = size - min_pos;
		while (min_pos > 0)
		{
			rra(a);
			min_pos--;
		}
	}
}
void	sort_complex(t_node **a, t_node **b)
{
	while (ft_lstsize(*a) > 3)
	{
		set_position(*a);
		set_position(*b);
		set_target_pos(*a, *b);
		set_cost(*a, *b);
		do_cheapest(a, b);
	}
	sort_simple(a);
	while (*b)
	{
		set_position(*a);
		set_position(*b);
		set_target_pos(*a, *b);
		set_cost(*a, *b);
		do_cheapest(a, b);
	}
	final_rotate(a);   // 🔥 EN SON
}