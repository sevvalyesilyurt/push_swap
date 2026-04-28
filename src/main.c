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

void	compute_disorder(t_ps *ps)
{
	t_node	*i_node;
	t_node	*j_node;
	double	mistakes;
	double	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	i_node = ps->a.top;
	while (i_node && i_node->next)
	{
		j_node = i_node->next;
		while (j_node)
		{
			total_pairs++;
			if (i_node->nbr > j_node->nbr)
				mistakes++;
			j_node = j_node->next;
		}
		i_node = i_node->next;
	}
	if (total_pairs > 0)
		ps->disorder = mistakes / total_pairs;
	else
		ps->disorder = 0;
}

void	select_strategy(t_ps *ps)
{
	if (ps->flags.strategy != ADAPTIVE)
		return ;
	if (ps->disorder < 0.2)
		ps->flags.strategy = SIMPLE;
	else if (ps->disorder >= 0.2 && ps->disorder < 0.5)
		ps->flags.strategy = MEDIUM;
	else if (ps->disorder >= 0.5)
		ps->flags.strategy = COMPLEX;
}

int	main(int argc, char **argv)
{
	t_ps	ps;

	ps = (t_ps){0};
	if (argc < 2)
		return (0);
	parse_main(&ps, argc, argv);
	if (is_sorted(ps.a.top))
	{
		free_stack(&ps.a.top);
		return (0);
	}
	compute_disorder(&ps);// disorder ölçen fonksiyon
	select_strategy(&ps); // strateji seçen fonksiyon
	set_index(ps.a.top); // buraya kadar değiştirdim yapıları ps için uygun hale getircem
	sort_dispatch(&ps);
	free_stack(&ps.a.top);
	free_stack(&ps.b.top);
	return (0);
}
/*
örnek flagler
./push_swap 3 2 1
./push_swap --simple 3 2 1
./push_swap --medium 3 2 1
./push_swap --complex 3 2 1
./push_swap --adaptive 3 2 1
./push_swap --bench --adaptive 3 2 1
*/
