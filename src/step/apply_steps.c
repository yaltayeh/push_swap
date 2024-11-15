/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_steps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:36:53 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/15 16:44:20 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	apply_steps(t_ps_data *data, t_stack *steps)
{
	t_step	*step;
	t_node	*head;

	head = steps->head;
	while (head)
	{
		step = head->data.ptr;
		if (step->op(data) == -1)
			return (-1);
		head = head->next;
	}
	return (0);
}
