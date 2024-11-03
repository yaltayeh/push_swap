/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:14:32 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/02 21:14:33 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int rotate(t_stack *s)
{
	t_node	*node;

	if (!s || !(s->head && s->head->next))
		return (0);
	node = ft_stack_head_pop(s);
	ft_stack_tail_push(s, node);
	return (1);
}

int	ra(t_stack *steps, t_stack *a, t_stack *b)
{
	(void)b;
	if (rotate(a))
	{
		if (!new_step(steps, __func__))
			return (-1);
		return (1);
	}
	return (0);
}

int	rb(t_stack *steps, t_stack *a, t_stack *b)
{
	(void)a;
	if (rotate(b))
	{
		if (!new_step(steps, __func__))
			return (-1);
		return (1);
	}
	return (0);
}

int	rr(t_stack *steps, t_stack *a, t_stack *b)
{
	t_step	*step;
	int		stat;

	stat = rotate(a) | rotate(b) << 1;
	if (stat == 1)
		step = new_step(steps, "ra");
	else if (stat == 2)
		step = new_step(steps, "rb");
	else if (stat == 3)
		step = new_step(steps, __func__);
	else
		return (0);
	if (!step)
		return (-1);
	return (1);
}
