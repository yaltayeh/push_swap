/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:17:58 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/28 05:58:07 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "merge_sort.h"

int	select_best_poss(size_t poss[8])
{
	size_t	i;
	size_t	min;
	int		min_i;

	min = UINT_MAX;
	min_i = -1;
	i = 0;
	while (i < 8)
	{
		if (poss[i] > 0 && poss[i] < min)
		{
			min = poss[i];
			min_i = i;
		}
		i++;
	}
	return (min_i);
}

static int	run_best_possible(t_ps_data *data, \
			size_t blocks[4], size_t possibles[8])
{
	int	(*mergers[8])(t_ps_data *, size_t *);
	int	best_poss_index;

	mergers[0] = head_b_tail_a;
	mergers[1] = head_a_tail_a;
	mergers[2] = head_a_head_b_2a;
	mergers[3] = tail_a_tail_b_2a;
	mergers[4] = head_a_tail_b;
	mergers[5] = head_b_tail_b;
	mergers[6] = head_a_head_b_2b;
	mergers[7] = tail_a_tail_b_2b;
	best_poss_index = select_best_poss(possibles);
	if (best_poss_index < 0)
		return (-1);
	return (mergers[best_poss_index](data, blocks));
}

int	get_blocks(t_ps_data *data, size_t blocks[4])
{
	if (a_head_block(data->a, &blocks[HEAD_A]))
		return (-1);
	if (a_tail_block(data->a, &blocks[TAIL_A]))
		return (-1);
	if (b_head_block(data->b, &blocks[HEAD_B]))
		return (-1);
	if (b_tail_block(data->b, &blocks[TAIL_B]))
		return (-1);
	return (0);
}

static int	make_one_merge(t_ps_data *data)
{
	size_t	blocks[4];
	size_t	possibles[8];

	if (get_blocks(data, blocks) == -1)
		return (-1);
	if (blocks[HEAD_A] == data->len)
		return (1);
	possibles[0] = blocks[HEAD_B] + blocks[TAIL_A];
	possibles[1] = blocks[HEAD_A] * 2 + blocks[TAIL_A];
	possibles[2] = blocks[HEAD_A] * 2 + blocks[HEAD_B];
	possibles[3] = blocks[TAIL_A] + blocks[TAIL_B] * 2;
	possibles[4] = blocks[HEAD_A] + blocks[TAIL_B];
	possibles[5] = blocks[HEAD_B] * 2 + blocks[TAIL_B];
	possibles[6] = blocks[HEAD_A] + blocks[HEAD_B] * 2;
	possibles[7] = blocks[TAIL_A] * 2 + blocks[TAIL_B];
	if (blocks[HEAD_B] == 0)
		ft_bzero(possibles, sizeof(size_t) * 4);
	if (blocks[HEAD_A] == 0)
		ft_bzero(&possibles[4], sizeof(size_t) * 4);
	if (blocks[HEAD_A] == ft_stack_size(data->a))
		possibles[1] = 0;
	if (blocks[HEAD_B] == ft_stack_size(data->b))
		possibles[5] = 0;
	return (run_best_possible(data, blocks, possibles));
}

int	merge_sort(t_ps_data **data)
{
	int		ret;

	if (!(*data)->steps || !(*data)->a || !(*data)->b || \
		(*data)->a->data_type != (*data)->b->data_type)
		return (-1);
	ret = 0;
	while (ret == 0)
		ret = make_one_merge(*data);
	if (ret < 0)
		return (ret);
	return (0);
}
