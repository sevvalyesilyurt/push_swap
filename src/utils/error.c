/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahelman <ahelman@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 21:28:19 by sevyesil          #+#    #+#             */
/*   Updated: 2026/04/18 17:59:48 by ahelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "includes/libft.h"
#include "includes/push_swap.h"

void	error_exit(t_node **a)
{
	if (a && *a)
		free_stack(a);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
