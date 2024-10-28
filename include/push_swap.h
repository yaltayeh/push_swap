#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "libft.h"

# define OP_SWAP 1
# define OP_PUSH 2
# define OP_ROTATE 3
# define OP_REVERSE_ROTATE 4

# define STACK_A 1
# define STACK_B 2
# define STACK_BOTH (STACK_A | STACK_B)

#define print_block(with_poiner)			\
	do							\
	{							\
		int a_block;			\
		int b_block;			\
		block_count(with_poiner a, with_poiner b, &a_block, &b_block);			\
		ft_fprintf(2, "-------------------\na_block: %d\nb_block: %d\n-------------------\n", a_block, b_block);\
	} while (0);\

typedef struct s_step
{
	char title[4];
	unsigned char op;
	unsigned char stack;
} t_step;

t_step *init_step(const char *title);
t_step	*new_step(t_list **steps, const char *title);
void	steps_reducer(t_list **steps);
int	parser_stack(t_list **stack, const int argc, char **argv);
void block_count(t_list *a, t_list *b, int *a_count, int *b_count);

void print_stack(t_content value);
void print_step(t_content content);
void print_step2(t_content content);


t_list	*get_small(t_list *s);
t_list	*get_big(t_list *s);
int	check_mask(t_list *s, int mask);

void    merge_sort(t_list **steps, t_list **a, t_list **b);
void	test2_sort(t_list **steps, t_list **a, t_list **b);
void	test_sort(t_list **steps, t_list **a, t_list **b);
t_list *radix_sort(t_list **a, t_list **b);


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