/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahelman <ahelman@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:14:35 by ahelman           #+#    #+#             */
/*   Updated: 2026/04/29 17:21:46 by ahelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <unistd.h>

static void	print_strategy(t_flags flags)
{
	if (flags.adaptive == 1)
	{
		ft_putstr_fd("Adaptive ", 2);
		if (flags.strategy == SIMPLE)
			ft_putstr_fd("/ O(n^2)", 2);
		else if (flags.strategy == MEDIUM)
			ft_putstr_fd("/ O(n√n)", 2);
		else if (flags.strategy == COMPLEX)
			ft_putstr_fd("/ O(n log n)", 2);
	}
	else if (flags.strategy == SIMPLE)
		ft_putstr_fd("Simple / O(n^2)", 2);
	else if (flags.strategy == MEDIUM)
		ft_putstr_fd("Medium / O(n√n)", 2);
	else if (flags.strategy == COMPLEX)
		ft_putstr_fd("Complex / O(n log n)", 2);
}

static void	print_disorder(double disorder)
{
	int	percent;

	percent = (int)(disorder * 100);
	ft_putnbr_fd(percent, 2);
}

void	print_op_stats(t_ps *ps)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(ps->stats.sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(ps->stats.sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(ps->stats.ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(ps->stats.pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(ps->stats.pb, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(ps->stats.ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(ps->stats.rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(ps->stats.rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(ps->stats.rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(ps->stats.rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(ps->stats.rrr, 2);
	ft_putstr_fd("\n", 2);
}

void	print_bench(t_ps *ps)
{
	if (!ps->flags.bench)
		return ;
	ft_putstr_fd("[bench] disorder: ", 2);
	print_disorder(ps->disorder);
	ft_putstr_fd("%\n", 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	print_strategy(ps->flags);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(ps->stats.total, 2);
	ft_putstr_fd("\n", 2);
	print_op_stats(ps);
}
