/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 19:44:27 by sevyesil          #+#    #+#             */
/*   Updated: 2026/03/31 21:09:13 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	duplicate_control(char *t_stack)
{
	int	i;
	int	j;

	i = 0;
	while (t_stack[i])
	{
		j = 0;
		while (t_stack[j])
		{
			if (t_stack[i] == t_stack[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

t_list	argumandan_linkedlist(char const **argv)
{
	t_list	**stack_a;

	while (condition)
	{
		/* code */
	}
	

}

int	main(int argc, char const *argv[])
{
	int	i;

	i = 1;
	if (argc < 2)
		return (-1);
	
	return 0;
}
