/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:15:44 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/15 16:46:54 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_step	*new_step(t_stack *steps, const char *title)
{
	t_step	*step;
	t_node	*node;

	step = init_step(title);
	if (!step)
		return (NULL);
	node = ft_init_node((t_data)(void *)step);
	if (!node)
		return (free(step), NULL);
	ft_stack_tail_push(steps, node);
	return (step);
}

static void	steps_reducer_utils(t_step *step, t_node *head)
{
	ft_stack_delnode(head->next);
	if (step->op_flag == OP_PUSH)
		ft_stack_delnode(head);
	else
	{
		step->stack_flag = STACK_BOTH;
		set_title(step);
	}
}

void	steps_reducer(t_stack *steps)
{
	t_node	*head;
	t_step	*step;
	t_step	*next_step;

	if (!steps)
		return ;
	head = steps->head;
	while (head)
	{
		step = head->data.ptr;
		if (head->next)
		{
			next_step = head->next->data.ptr;
			if (step->op_flag == next_step->op_flag \
				&& (step->stack_flag ^ next_step->stack_flag) == 3)
			{
				steps_reducer_utils(step, head);
				head = steps->head;
				continue ;
			}
		}
		head = head->next;
	}
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
