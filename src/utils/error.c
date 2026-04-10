/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 21:28:19 by sevyesil          #+#    #+#             */
/*   Updated: 2026/04/09 21:31:14 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

void	error_exit(t_stack **a)
{
	if (a && *a)
		free_stack(a);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
