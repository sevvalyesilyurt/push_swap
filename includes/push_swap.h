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

#endif