/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:16:33 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/18 08:02:24 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack(const char *title)
{
	size_t	len;

	len = ft_strlen(title);
	if (title[len - 1] == 'a')
		return (STACK_A);
	else if (title[len - 1] == 'b')
		return (STACK_B);
	else if (ft_strchr("rs", title[len - 1]))
		return (STACK_BOTH);
	return (0);
}

void	set_type(t_step *step)
{
	step->stack_flag = get_stack(step->title);
	if (step->title[0] == 's')
		step->op_flag = OP_SWAP;
	else if (step->title[0] == 'p')
		step->op_flag = OP_PUSH;
	else if (step->title[0] == 'r')
	{
		if (ft_strlen(step->title) == 2)
			step->op_flag = OP_ROTATE;
		else
			step->op_flag = OP_REVERSE_ROTATE;
	}
	else
		step->op_flag = 0;
}

void	set_op(t_step *step)
{
	int	(*ops[12])(t_ps_data *data);
	int	index;

	ops[0] = sa;
	ops[1] = sb;
	ops[2] = ss;
	ops[3] = pa;
	ops[4] = pb;
	ops[5] = NULL;
	ops[6] = ra;
	ops[7] = rb;
	ops[8] = rr;
	ops[9] = rra;
	ops[10] = rrb;
	ops[11] = rrr;
	index = step->op_flag + step->stack_flag - 1;
	if (index >= 0 && index < 12)
		step->op = ops[index];
	else
		step->op = NULL;
}

void	set_title(t_step *step)
{
	char	*titles[12];
	int		index;

	titles[0] = "sa";
	titles[1] = "sb";
	titles[2] = "ss";
	titles[3] = "pa";
	titles[4] = "pb";
	titles[5] = "";
	titles[6] = "ra";
	titles[7] = "rb";
	titles[8] = "rr";
	titles[9] = "rra";
	titles[10] = "rrb";
	titles[11] = "rrr";
	index = step->op_flag + step->stack_flag - 1;
	if (index >= 0 && index < 12)
		ft_strlcpy(step->title, titles[index], sizeof(step->title));
	else
		ft_strlcpy(step->title, "", sizeof(step->title));
}

t_step	*init_step(const char *title, size_t len_stack_a, size_t len_stack_b)
{
	t_step	*step;

	step = ft_calloc(1, sizeof(t_step));
	if (!step)
		return (NULL);
	ft_strlcpy(step->title, title, sizeof(step->title));
	set_type(step);
	set_op(step);
	step->stack_len[0] = len_stack_a;
	step->stack_len[1] = len_stack_b;
	return (step);
}
