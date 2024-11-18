/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:14:32 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/18 08:07:00 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_stack *s)
{
	t_node	*node;

	if (!s || !(s->head && s->head->next))
		return (0);
	node = ft_stack_head_pop(s);
	ft_stack_tail_push(s, node);
	return (1);
}

int	ra(t_ps_data *data)
{
	if (rotate(data->a))
	{
		if (data->logged)
			if (!new_step(data, __func__))
				return (-1);
		return (1);
	}
	return (0);
}

int	rb(t_ps_data *data)
{
	if (rotate(data->b))
	{
		if (data->logged)
			if (!new_step(data, __func__))
				return (-1);
		return (1);
	}
	return (0);
}

int	rr(t_ps_data *data)
{
	t_step	*step;
	int		stat;

	stat = rotate(data->a) | rotate(data->b) << 1;
	if (!data->logged)
		return (!!stat);
	if (stat == 1)
		step = new_step(data, "ra");
	else if (stat == 2)
		step = new_step(data, "rb");
	else if (stat == 3)
		step = new_step(data, __func__);
	else
		return (0);
	if (!step)
		return (-1);
	return (1);
}
