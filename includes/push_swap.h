#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node
{
	long			nbr;
	long			index;
	struct s_node	*next;
}					t_node;

// bench kısmı struct olucak
typedef struct s_bench
{
	float			disorder;
	char			*strategy;
	int				total_ops;
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
	int				is_bench;
}					t_bench;

// stack yapısı için gerekli fonksiyonlar
t_node				*new_node(long number);
t_node				*last_node(t_node *lst);
int					size_node(t_node *node);
void				free_stack(t_node **node);
void				add_back(t_node **node, t_node *new);
void				add_front(t_node **node, t_node *new);

// stack'teki işlemler için kullanacağımız fonksiyonlar
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