/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:14:34 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/06 01:28:15 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap(t_stack *stack)
{
	t_node	*node1;
	t_node	*node2;

	if (!stack || !stack->head || !stack->head->next)
		return (0);
	node1 = ft_stack_head_pop(stack);
	node2 = ft_stack_head_pop(stack);
	ft_stack_head_push(stack, node1);
	ft_stack_head_push(stack, node2);
	return (1);
}

int	sa(t_ps_data *data)
{
	if (swap(data->a))
	{
		if (!new_step(data->steps, __func__))
			return (-1);
		return (1);
	}
	return (0);
}

int	sb(t_ps_data *data)
{
	if (swap(data->b))
	{
		if (!new_step(data->steps, __func__))
			return (-1);
		return (1);
	}
	return (0);
}

int	ss(t_ps_data *data)
{
	t_step	*step;
	int		stat;

	stat = swap(data->a) | swap(data->b) << 1;
	if (stat == 1)
		step = new_step(data->steps, "sa");
	else if (stat == 2)
		step = new_step(data->steps, "sb");
	else if (stat == 3)
		step = new_step(data->steps, __func__);
	else
		return (0);
	if (!step)
		return (-1);
	return (1);
}
