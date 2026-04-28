/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dispatch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 16:27:16 by sevyesil          #+#    #+#             */
/*   Updated: 2026/04/28 20:33:08 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_dispatch(t_ps *ps)
{
	if (ps->a.size <= 5)
	{
		sort_small(ps);
		return ;
	}
	if (ps->flags.strategy == SIMPLE)
		sort_simple(ps);
	else if (ps->flags.strategy == MEDIUM)
		sort_medium(ps);
	else if (ps->flags.strategy == COMPLEX)
		sort_complex(ps);
}

