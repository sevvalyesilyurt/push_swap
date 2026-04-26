#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* --- 1. Düğüm Yapısı (Singly Linked List) --- */

typedef struct s_node
{
	long			nbr;
	long			index;

	int				pos;
	int				target_pos;

	int				cost_a;
	int				cost_b;

	struct s_node	*next;
}	t_node;
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
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}					t_strategy;

typedef struct s_flags
{
	int				bench;
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
// push
void				pb(t_node **a, t_node **b, int print);
void				pa(t_node **b, t_node **a, int print);
// swap
void				sa(t_node **a, int print);
void				sb(t_node **b, int print);
void				ss(t_node **a, t_node **b, int print);
// reverse rotate
void				rrr(t_node **a, t_node **b, int print);
void				rra(t_node **a, int print);
void				rrb(t_node **b, int print);
// rotate
void				rr(t_node **a, t_node **b, int print);
void				ra(t_node **a, int print);
void				rb(t_node **b, int print);
// utils kısmı
void				error_exit(t_node **a);
void				free_stack(t_node **stack);
// sorting
void				sort_dispatch(t_node **a, t_node **b);
int					calculate_cost_a(t_node *a, t_node *b);
int					calculate_cost_b(t_node *b);
void				sort_simple(t_node **a);
void				sort_small(t_node **a, t_node **b);
void				sort_medium(t_node **a, t_node **b);
void				sort_complex(t_node **a, t_node **b);
int					find_min_pos(t_node *a);
int					find_pos(t_node *a, int i);
int					push_target(t_node **a, t_node **b, int i);
void				bring_to_top(t_node **a, int pos, int size);
// sort_utils
void				set_index(t_node *a);
void				set_position(t_node *stack);
void				set_target_pos(t_node *a, t_node *b);
void				set_cost(t_node *a, t_node *b);

// sort_complex_utils
void				do_cheapest(t_node **a, t_node **b);
void				final_rotate(t_node **a);

//parserlar

int					parse_flags(int argc, char **argv);
void				parse_split(t_node **a, char *str);
void				free_split(char **split);
int					ft_strcmp(char *s1, char *s2);
void				parse_numbers(t_node **a, char *str);
int					ps_validatestringkontrolu(char *str);
void				parse_main(t_node **a, int argc, char **argv);

#endif