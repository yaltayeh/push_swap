/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:16:09 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/06 00:39:57 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "libft.h"
# include "merge_sort.h"

# define OP_SWAP 1
# define OP_PUSH 2
# define OP_ROTATE 3
# define OP_REVERSE_ROTATE 4

# define STACK_A 1
# define STACK_B 2
# define STACK_BOTH 3

typedef struct s_ps_data
{
	t_stack	*steps;
	t_stack	*a;
	t_stack	*b;
}	t_ps_data;

typedef struct s_step
{
	char	title[4];
	int		op_flag;
	int		stack_flag;
	int		(*op)(t_ps_data *data);
}	t_step;

t_step	*init_step(const char *title);
t_step	*new_step(t_stack *steps, const char *title);
void	steps_reducer(t_stack *steps);
int		parser_stack(t_stack *stack, const int argc, char **argv);

int		print_stack(int value);
int		print_step(t_step *step);
int		print_step2(t_step *step);

int		sa(t_ps_data *data);
int		sb(t_ps_data *data);
int		ss(t_ps_data *data);

int		pa(t_ps_data *data);
int		pb(t_ps_data *data);

int		ra(t_ps_data *data);
int		rb(t_ps_data *data);
int		rr(t_ps_data *data);

int		rra(t_ps_data *data);
int		rrb(t_ps_data *data);
int		rrr(t_ps_data *data);

#endif