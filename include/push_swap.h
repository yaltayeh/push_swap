/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:16:09 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/02 23:53:12 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	char	title[4];
	int		op_flag;
	int		stack_flag;
	int		(*op)(t_stack *steps, t_stack *a, t_stack *b);
} t_step;

t_step *init_step(const char *title);
t_step	*new_step(t_stack *steps, const char *title);
void	steps_reducer(t_stack *steps);
int	parser_stack(t_stack **stack, const int argc, char **argv);

int print_stack(int value);
int print_step(t_step *step);
int print_step2(t_step *step, size_t i);


int merge_2_a(t_stack *steps, t_stack *a, t_stack *b);
int merge_2_b(t_stack *steps, t_stack *a, t_stack *b);
int    merge_sort(t_stack *steps, t_stack *a, t_stack *b);

int	sa(t_stack *steps, t_stack *a, t_stack *b);
int	sb(t_stack *steps, t_stack *a, t_stack *b);
int	ss(t_stack *steps, t_stack *a, t_stack *b);

int pa(t_stack *steps, t_stack *a, t_stack *b);
int pb(t_stack *steps, t_stack *a, t_stack *b);

int	ra(t_stack *steps, t_stack *a, t_stack *b);
int	rb(t_stack *steps, t_stack *a, t_stack *b);
int	rr(t_stack *steps, t_stack *a, t_stack *b);

int	rra(t_stack *steps, t_stack *a, t_stack *b);
int	rrb(t_stack *steps, t_stack *a, t_stack *b);
int	rrr(t_stack *steps, t_stack *a, t_stack *b);

#endif