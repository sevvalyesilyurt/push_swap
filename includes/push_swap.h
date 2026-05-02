/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahelman <ahelman@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:40:50 by sevyesil          #+#    #+#             */
/*   Updated: 2026/05/02 10:53:21 by ahelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node
{
	long			nbr;
	int				index;

	int				pos;
	int				target_pos;

	int				cost_a;
	int				cost_b;

	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

typedef struct s_op_stats
{
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total;
}					t_op_stats;

typedef enum e_strategy
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}					t_strategy;

typedef struct s_flags
{
	int				bench;
	int				adaptive;
	t_strategy		strategy;
}					t_flags;

typedef struct s_ps
{
	t_stack			a;
	t_stack			b;
	t_flags			flags;
	t_op_stats		stats;
	double			disorder;
}					t_ps;

t_node				*new_node(long number);
t_node				*last_node(t_node *lst);
void				free_stack(t_node **node);
void				add_back(t_node **node, t_node *new);
void				add_front(t_node **node, t_node *new);

void				pa(t_ps *ps);
void				pb(t_ps *ps);

void				sa(t_ps *ps);
void				sb(t_ps *ps);
void				ss(t_ps *ps);

void				ra(t_ps *ps);
void				rb(t_ps *ps);
void				rr(t_ps *ps);

void				rra(t_ps *ps);
void				rrb(t_ps *ps);
void				rrr(t_ps *ps);

void				error_exit(t_ps *ps);
void				free_stack(t_node **stack);
int					stack_is_sorted(t_node *a);
char				**ft_split(char const *s, char c);
int					ft_strcmp(char *s1, char *s2);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);

void				sort_dispatch(t_ps *ps);
void				sort_simple(t_ps *ps);
void				sort_small(t_ps *ps);
void				sort_medium(t_ps *ps);
void				sort_complex(t_ps *ps);
int					find_min_pos(t_node *a);

void				print_bench(t_ps *ps);

void				set_index(t_node *a);
void				set_position(t_node *stack);
void				do_cheapest(t_ps *ps);
void				final_rotate(t_ps *ps);

void				parse_main(t_ps *ps, int argc, char **argv);
void				parse_free_split(char **split);
int					ps_validate_string_control(char *str);
void				parse_numbers(t_ps *ps, char *str);

int					ft_strcmp(char *s1, char *s2);

#endif