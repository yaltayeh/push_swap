/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:15:44 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/02 21:15:47 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static unsigned char get_stack(const char *title)
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

static void name_to_type(t_step *step)
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

// static void	*get_op(t_step *step)
// {
// 	return (NULL);
// }

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

t_step *init_step(const char *title)
{
	t_step	*step;

	step = ft_calloc(1, sizeof(t_step));
	if (!step)
		return (NULL);
	ft_strlcpy(step->title, title, sizeof(step->title));
	name_to_type(step);
	return (step);
}

void	update_step(t_step *step)
{
	size_t	len;

	len = ft_strlen(step->title);
	if (len > 1)
	{
		step->title[len - 1] = step->title[len - 2];
		step->stack_flag = STACK_BOTH;
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
		next_step = NULL;
		if (head->next)
		{
			next_step = head->next->data.ptr;
			if (step->op_flag == next_step->op_flag)
				if ((step->stack_flag ^ next_step->stack_flag) == 3)
				{
					ft_stack_delnode(head->next);
					if (step->op_flag == OP_PUSH)
						ft_stack_delnode(head);
					else
						update_step(step);
					head = steps->head;
					continue;
				}
		}
		head = head->next;
	}
}
