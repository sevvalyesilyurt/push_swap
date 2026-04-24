#include "push_swap.h"
#include <unistd.h>

static int	is_sorted(t_node *a)
{
	while (a && a->next)
	{
		if (a->nbr > a->next->nbr)
			return (0);
		a = a->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;

	if (argc < 2)
		return (0);

	parse_main(&a, argc, argv);

	if (is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	set_index(a);
	sort_dispatch(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
