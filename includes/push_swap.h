#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node
{
	long			nbr;
	long			index;
	struct s_node	*next;
}					t_node;

// stack yapısı için gerekli fonksiyonlar
t_node				*new_node(long number);
t_node				*last_node(t_node *lst);
int					size_node(t_node *node);
void				add_back(t_node **node, t_node *new);
void				add_front(t_node **node, t_node *new);

#endif