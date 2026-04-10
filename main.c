/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahelman <ahelman@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 19:44:27 by sevyesil          #+#    #+#             */
/*   Updated: 2026/04/10 19:13:20 by ahelman          ###   ########.fr       */
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

st_list	argumandan_linkedlist(char const **argv)
{
	t_list	**stack_a;

	while (condition)
	{
		/* code */
	}
	

}

int	main(int argc, char const *argv[])
{
	
}
