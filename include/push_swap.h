#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"

# define DEF_OP(name) int	name(t_list **steps, t_list **s)
# define DEF_OP2(name) int	name(t_list **steps, t_list **a, t_list **b)


typedef struct s_step
{
	int id;
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


# define OP_CMP(name) ft_strncmp(title, name, -1) == 0

int	name_to_type(const char *title);

t_step *init_step(int id, const char *title);

t_step	*new_step(t_list **steps, const char *title);

int steps_count;
# define NEW_STEP  \
		t_step * step = new_step(steps, __func__);


/**  
 * swap: Swap the first 2 elements at the top of stack a. 
 * Do nothing if there is only one or no elements.
*/
DEF_OP(swap);
DEF_OP2(sa);
DEF_OP2(sb);
DEF_OP2(ss);

/** 
 * push: Take the first element at the top of a 
 * and put it at the top of a.
 * Do nothing if b is empty.
*/
DEF_OP2(push);
DEF_OP2(pa);
DEF_OP2(pb);

/** 
 * rotate: Shift up all elements of stack s by 1.
 * The first element becomes the last one.
*/
DEF_OP(rotate);
DEF_OP2(ra);
DEF_OP2(rb);
DEF_OP2(rr);

/** 
 * reverse rotate: Shift down all elements of stack s
 * by 1. The last element becomes the first one.
*/
DEF_OP(reverse_rotate);
DEF_OP2(rra);
DEF_OP2(rrb);
DEF_OP2(rrr);

#endif