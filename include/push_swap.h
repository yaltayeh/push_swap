#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"

# define DEF_OP(name) int	name(t_list **s)
# define DEF_OP2(name) int	name(t_list **s1, t_list **s2)

/** 
 * swap: Swap the first 2 elements at the top of stack a. 
 * Do nothing if there is only one or no elements.
*/
DEF_OP(swap);

/** 
 * push: Take the first element at the top of a 
 * and put it at the top of a.
 * Do nothing if b is empty.
*/
DEF_OP2(push);

/** 
 * rotate: Shift up all elements of stack s by 1.
 * The first element becomes the last one.
*/
DEF_OP(rotate);

/** 
 * reverse rotate: Shift down all elements of stack s
 * by 1. The last element becomes the first one.
*/
DEF_OP(reverse_rotate);

#endif