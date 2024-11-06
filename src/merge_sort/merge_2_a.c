/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_2_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:17:51 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/06 01:27:02 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "merge_sort.h"

int	head_b_tail_a(t_ps_data *data, int blocks[4])
{
	return (merge_2_a(data, blocks[HEAD_B], blocks[TAIL_A]));
}

int	head_a_tail_a(t_ps_data *data, int blocks[4])
{
	int	head_a;

	head_a = blocks[HEAD_A];
	while (head_a--)
		if (pb(data) == -1)
			return (-1);
	return (merge_2_a(data, blocks[HEAD_A], blocks[TAIL_A]));
}

int	head_a_head_b_2a(t_ps_data *data, int blocks[4])
{
	int	head_a;

	head_a = blocks[HEAD_A];
	while (head_a--)
		if (ra(data) == -1)
			return (-1);
	return (merge_2_a(data, blocks[HEAD_B], blocks[HEAD_A]));
}

int	tail_a_tail_b_2a(t_ps_data *data, int blocks[4])
{
	int	tail_b;

	tail_b = blocks[TAIL_B];
	while (tail_b--)
		if (rrb(data) == -1)
			return (-1);
	return (merge_2_a(data, blocks[TAIL_B], blocks[TAIL_A]));
}

int	merge_2_a(t_ps_data *data, int head_b, int tail_a)
{
	int		test;

	test = 0;
	while (head_b && tail_a)
	{
		if (ft_cmp_node(data->b->head, data->a->tail, &test))
			return (-1);
		if (test > 0)
		{
			if (pa(data) == -1)
				return (-1);
			head_b--;
		}
		else
		{
			if (rra(data) == -1)
				return (-1);
			tail_a--;
		}
	}
	while (head_b--)
		if (pa(data) == -1)
			return (-1);
	while (tail_a--)
		if (rra(data) == -1)
			return (-1);
	return (0);
}