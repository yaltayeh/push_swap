/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:16:09 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/15 16:39:47 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "libft.h"
# include "merge_sort.h"

# define OP_SWAP 0
# define OP_PUSH 3
# define OP_ROTATE 6
# define OP_REVERSE_ROTATE 9

# define STACK_A 1
# define STACK_B 2
# define STACK_BOTH 3

typedef struct s_ps_data
{
	t_stack	*steps;
	t_stack	*a;
	t_stack	*b;
	int		logged;
}	t_ps_data;

typedef struct s_step
{
	char	title[4];
	int		op_flag;
	int		stack_flag;
	int		(*op)(t_ps_data *data);
}	t_step;

void	exit_handler(int err_code, t_ps_data **data) \
			__attribute__((noreturn));

int		parser_stack(t_stack *stack, const int argc, char **argv);

int		get_stack(const char *title);
void	set_type(t_step *step);
void	set_op(t_step *step);
void	set_title(t_step *step);
t_step	*init_step(const char *title);

t_step	*new_step(t_stack *steps, const char *title);
void	steps_reducer(t_stack *steps);
void	step_reverse(t_step *step);
t_step	*step_copy(t_step *step, size_t i, int *err);

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