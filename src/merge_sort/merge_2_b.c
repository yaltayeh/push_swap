/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_2_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:17:55 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/15 17:14:51 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "merge_sort.h"

int	head_a_tail_b(t_ps_data *data, size_t blocks[4])
{
	return (merge_2_b(data, blocks[HEAD_A], blocks[TAIL_B]));
}

int	head_b_tail_b(t_ps_data *data, size_t blocks[4])
{
	size_t	head_b;

	head_b = blocks[HEAD_B];
	while (head_b--)
		if (pa(data) == -1)
			return (-1);
	return (merge_2_b(data, blocks[HEAD_B], blocks[TAIL_B]));
}

int	head_a_head_b_2b(t_ps_data *data, size_t blocks[4])
{
	size_t	head_b;

	head_b = blocks[HEAD_B];
	while (head_b--)
		if (rb(data) == -1)
			return (-1);
	return (merge_2_b(data, blocks[HEAD_A], blocks[HEAD_B]));
}

int	tail_a_tail_b_2b(t_ps_data *data, size_t blocks[4])
{
	size_t	tail_a;

	tail_a = blocks[TAIL_A];
	while (tail_a--)
		if (rra(data) == -1)
			return (-1);
	return (merge_2_b(data, blocks[TAIL_A], blocks[TAIL_B]));
}

int	merge_2_b(t_ps_data *data, size_t head_a, size_t tail_b)
{
	int		test;

	while (head_a && tail_b)
	{
		ft_cmp_node(data->a->head, data->b->tail, &test);
		if (test < 0)
		{
			if (pb(data) == -1)
				return (-1);
			head_a--;
		}
		else
		{
			if (rrb(data) == -1)
				return (-1);
			tail_b--;
		}
	}
	while (head_a--)
		if (pb(data) == -1)
			return (-1);
	while (tail_b--)
		if (rrb(data) == -1)
			return (-1);
	return (0);
}
