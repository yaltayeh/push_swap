/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:14:24 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/18 08:07:19 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push(t_stack *from, t_stack *to)
{
	t_node	*node;

	node = ft_stack_head_pop(from);
	if (!node)
		return (0);
	ft_stack_head_push(to, node);
	return (1);
}

int	pa(t_ps_data *data)
{
	if (push(data->b, data->a))
	{
		if (data->logged)
			if (!new_step(data, __func__))
				return (-1);
		return (1);
	}
	return (0);
}

int	pb(t_ps_data *data)
{
	if (push(data->a, data->b))
	{
		if (data->logged)
			if (!new_step(data, __func__))
				return (-1);
		return (1);
	}
	return (0);
}
