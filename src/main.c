/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:41:12 by sevyesil          #+#    #+#             */
/*   Updated: 2026/05/01 19:06:30 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ps->flags.adaptive = 1;
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
	if (stack_is_sorted(ps.a.top))
	{
		free_stack(&ps.a.top);
		return (0);
	}
	compute_disorder(&ps);
	select_strategy(&ps);
	set_index(ps.a.top);
	sort_dispatch(&ps);
	print_bench(&ps);
	free_stack(&ps.a.top);
	free_stack(&ps.b.top);
	return (0);
}
