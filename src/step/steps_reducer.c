/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_reducer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 23:48:55 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/28 07:09:09 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	test1(t_node *cur)
{
	t_step	*steps[2];

	if (!cur->next)
		return (0);
	steps[0] = cur->data.ptr;
	steps[1] = cur->next->data.ptr;
	if (steps[0]->op_flag == steps[1]->op_flag \
		&& (steps[0]->stack_flag ^ steps[1]->stack_flag) == 3)
	{
		ft_stack_delnode(cur->next);
		if (steps[0]->op_flag == OP_PUSH)
			ft_stack_delnode(cur);
		else
		{
			steps[0]->stack_flag = STACK_BOTH;
			set_title(steps[0]);
			set_op(steps[0]);
		}
		return (1);
	}
	return (0);
}

static int	test2(t_node *cur)
{
	t_step	*steps[2];

	if (!cur->next)
		return (0);
	steps[0] = cur->data.ptr;
	steps[1] = cur->next->data.ptr;
	if (steps[0]->op_flag + steps[1]->op_flag == (OP_ROTATE + OP_RROTATE) \
		&& steps[0]->stack_flag == steps[1]->stack_flag)
	{
		ft_stack_delnode(cur->next);
		ft_stack_delnode(cur);
		return (1);
	}
	return (0);
}

static int	test3(t_node *cur)
{
	t_step	*steps[3];

	if (!cur->next || !cur->next->next)
		return (0);
	steps[0] = cur->data.ptr;
	steps[1] = cur->next->data.ptr;
	steps[2] = cur->next->next->data.ptr;
	if ((!ft_strcmp(steps[0]->title, "pb") && \
			!ft_strcmp(steps[1]->title, "rra") && \
			!ft_strcmp(steps[2]->title, "pa")) \
		|| (!ft_strcmp(steps[0]->title, "pa") && \
			!ft_strcmp(steps[1]->title, "rrb") && \
			!ft_strcmp(steps[2]->title, "pb")))
	{
		steps[2]->op_flag = OP_SWAP;
		set_op(steps[2]);
		set_title(steps[2]);
		ft_stack_delnode(cur);
		return (1);
	}
	return (0);
}

void	steps_reducer(t_stack *steps)
{
	t_node	*cur;

	if (!steps)
		return ;
	cur = steps->head;
	while (cur)
	{
		if (test1(cur) || test2(cur) || test3(cur))
		{
			cur = steps->head;
			continue ;
		}
		cur = cur->next;
	}
}
