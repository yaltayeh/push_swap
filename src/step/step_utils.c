/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:15:44 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/24 14:12:17 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_step	*new_step(t_ps_data *data, const char *title)
{
	t_step	*step;
	t_node	*node;

	step = init_step(title);
	if (!step)
		return (NULL);
	node = ft_init_node((t_data)(void *)step);
	if (!node)
		return (free(step), NULL);
	ft_stack_tail_push(data->steps, node);
	return (step);
}

void	step_reverse(t_step *step)
{
	if (step->op_flag == OP_SWAP)
		;
	else if (step->op_flag == OP_PUSH)
		step->stack_flag = 3 - step->stack_flag;
	else if (step->op_flag == OP_ROTATE)
		step->op_flag = OP_REVERSE_ROTATE;
	else if (step->op_flag == OP_REVERSE_ROTATE)
		step->op_flag = OP_ROTATE;
	set_title(step);
	set_op(step);
}

t_step	*step_copy(t_step *step, size_t i, int *err)
{
	t_step	*copy;

	(void)i;
	*err = 0;
	copy = init_step(step->title);
	if (!copy)
	{
		*err = -1;
		return (NULL);
	}
	return (copy);
}
