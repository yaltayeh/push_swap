#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"

typedef struct s_step
{
	char title[16];
	int type;
} t_step;

enum e_type_flags 
{
	STACK_A = 1 << 0,
	STACK_B = 1 << 1,
	STACK_BOTH = STACK_A | STACK_B,
	SWAP = 1 << 2,
	PUSH = 1 << 3,
	ROTATE = 1 << 4,
	RROTATE = 1 << 5,
};

int	name_to_type(const char *title);
t_step *init_step(const char *title);
t_step	*new_step(t_list **steps, const char *title);
int	steps_reducer(t_list **steps);

t_list	*test_sort(t_list **a, t_list **b);

int	sa(t_list **steps, t_list **a, t_list **b);
int	sb(t_list **steps, t_list **a, t_list **b);
int	ss(t_list **steps, t_list **a, t_list **b);

int pa(t_list **steps, t_list **a, t_list **b);
int pb(t_list **steps, t_list **a, t_list **b);

int	ra(t_list **steps, t_list **a, t_list **b);
int	rb(t_list **steps, t_list **a, t_list **b);
int	rr(t_list **steps, t_list **a, t_list **b);

int	rra(t_list **steps, t_list **a, t_list **b);
int	rrb(t_list **steps, t_list **a, t_list **b);
int	rrr(t_list **steps, t_list **a, t_list **b);


#endif