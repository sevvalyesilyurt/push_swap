#include "libft.h"

void	sort_dispatch(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size <= 1)
		return ;
	else if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
	}
	else if (size == 3)
		sort_simple(a);
	else if (size <= 5)
		sort_small(a, b);
	else if (size <= 100)
		sort_medium(a, b);
	else
		sort_complex(a, b);
}

void	sort_simple(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

static int	find_min(t_stack *a)
{
	int	min;

	min = a->value;
	while (a)
	{
		if (a->value < min)
			min = a->value;
		a = a->next;
	}
	return (min);
}

void	sort_small(t_stack **a, t_stack **b)
{
	int	min;

	while (ft_lstsize(*a) > 3)
	{
		min = find_min(*a);
		while ((*a)->value != min)
			ra(a);
		pb(a, b);
	}
	sort_simple(a);
	while (*b)
		pa(a, b);
}

void	sort_medium(t_stack **a, t_stack **b)
{
	int	size;
	int	i;

	size = ft_lstsize(*a);
	i = 0;
	while (i < size)
	{
		pb(a, b);
		i++;
	}
	while (*b)
	{
		pa(a, b);
		if ((*a)->value > (*a)->next->value)
			sa(a);
	}
}