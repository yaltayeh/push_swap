/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:14:29 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/02 21:14:30 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int reverse_rotate(t_stack *s)
{
	t_node	*node;

	if (!s || !(s->head && s->head->next))
		return (0);
	node = ft_stack_tail_pop(s);
	ft_stack_head_push(s, node);
	return (1);
}

int	rra(t_stack *steps, t_stack *a, t_stack *b)
{
	(void)b;
	if (reverse_rotate(a))
	{
		if (!new_step(steps, __func__))
			return (-1);
		return (1);
	}
	return (0);
}

int	rrb(t_stack *steps, t_stack *a, t_stack *b)
{
	(void)a;
	if (reverse_rotate(b))
	{
		if (!new_step(steps, __func__))
			return (-1);
		return (1);
	}
	return (0);
}

int	rrr(t_stack *steps, t_stack *a, t_stack *b)
{
	t_step	*step;
	int		stat;

	stat = reverse_rotate(a) | reverse_rotate(b) << 1;
	if (stat == 1)
		step = new_step(steps, "rra");
	else if (stat == 2)
		step = new_step(steps, "rrb");
	else if (stat == 3)
		step = new_step(steps, __func__);
	else
		return (0);
	if (!step)
		return (-1);
	return (1);
}
