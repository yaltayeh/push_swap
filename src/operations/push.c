/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:14:24 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/02 21:14:28 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int push(t_stack *s1, t_stack *s2)
{
	t_node	*node;

	node = ft_stack_head_pop(s1);
	if (!node)
		return (0);
	ft_stack_head_push(s2, node);
	return (1);
}

int pa(t_stack *steps, t_stack *a, t_stack *b)
{
	if (push(b, a))
	{
		if (!new_step(steps, __func__))
			return (-1);
		return (1);
	}
	return (0);
}

int pb(t_stack *steps, t_stack *a, t_stack *b)
{
	if (push(a, b))
	{
		if (!new_step(steps, __func__))
			return (-1);
		return (1);
	}
	return (0);
}
