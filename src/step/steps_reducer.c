/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_reducer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 23:48:55 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/17 08:36:27 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	steps_reducer_extra(t_stack *steps_stack)
{
	t_node	*cur;
	t_step	*steps[3];

	cur = steps_stack->head;
	while (cur && cur->next && cur->next->next)
	{
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
			cur = steps_stack->head;
			continue ;
		}
		cur = cur->next;
	}
}
