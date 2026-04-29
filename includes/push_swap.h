/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahelman <ahelman@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:40:50 by sevyesil          #+#    #+#             */
/*   Updated: 2026/04/29 17:08:57 by ahelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* --- 1. Düğüm Yapısı (Singly Linked List) --- */

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
/* --- 2. Stack Yapısı (Meta Veri) --- */
typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

/* --- 3. İstatistikler (Benchmarking) --- */
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

/* --- 4. Strateji ve Flagler --- */
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

/* --- 5. Ana Context (Her şeyin başı) --- */
typedef struct s_ps
{
	t_stack			a;
	t_stack			b;
	t_flags			flags;
	t_op_stats		stats;
	double			disorder;
}					t_ps;

// stack yapısı için gerekli fonksiyonlar
t_node				*new_node(long number);
t_node				*last_node(t_node *lst);
int					size_node(t_node *node);
void				free_stack(t_node **node);
void				add_back(t_node **node, t_node *new);
void				add_front(t_node **node, t_node *new);

// stack'teki işlemler için kullanacağımız fonksiyonlar
// operations

// push (src boşsa çalışmaz)
void				pa(t_ps *ps);
void				pb(t_ps *ps);

// swap (size < 2 ise çalışmaz)
void				sa(t_ps *ps);
void				sb(t_ps *ps);
void				ss(t_ps *ps);

// rotate (size < 2 ise çalışmaz)
void				ra(t_ps *ps);
void				rb(t_ps *ps);
void				rr(t_ps *ps);

// reverse rotate (size < 2 ise çalışmaz)
void				rra(t_ps *ps);
void				rrb(t_ps *ps);
void				rrr(t_ps *ps);
// utils kısmı
void				error_exit(t_ps *ps);
void				free_stack(t_node **stack);
int					stack_is_sorted(t_node *a);
char				**ft_split(char const *s, char c);
long				ft_atol(const char *str);
int					ft_strcmp(char *s1, char *s2);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);

// sorting
void				sort_dispatch(t_ps *ps);
void				sort_simple(t_ps *ps);
void				sort_small(t_ps *ps);
void				sort_medium(t_ps *ps);
void				sort_complex(t_ps *ps);
int					find_min_pos(t_node *a);

// bench
void				print_bench(t_ps *ps);

// sort_utils
void				set_index(t_node *a);
void				set_position(t_node *stack);
void				set_target_pos(t_node *a, t_node *b);
void				set_cost(t_node *a, t_node *b);

// sort_complex_utils
void				do_cheapest(t_ps *ps);
void				final_rotate(t_ps *ps);

// parserlar
int					parse_flags(t_ps *ps, int argc, char **argv);
void				parse_split(t_ps *ps, char *str);
void				parse_main(t_ps *ps, int argc, char **argv);

void				parse_free_split(char **split);
long				ft_atol(const char *str);
int					ft_strcmp(char *s1, char *s2);

int					ps_validate_string_control(char *str);
void				parse_numbers(t_ps *ps, char *str);

#endif
