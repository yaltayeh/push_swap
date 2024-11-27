/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:24:09 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/27 12:07:05 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "merge_sort.h"

static t_ps_data	*clone_data(t_ps_data *data)
{
	t_ps_data	*new_data;

	new_data = malloc(sizeof(t_ps_data));
	if (!new_data)
		return (NULL);
	new_data->logged = data->logged;
	new_data->a = ft_stack_copy(data->a);
	new_data->b = ft_stack_copy(data->b);
	new_data->len = data->len;
	new_data->steps = ft_stack_copy(data->steps);
	return (new_data);
}

static void	set_mergers_values(int			(*mergers[8])(t_ps_data *, size_t *))
{
	mergers[0] = head_b_tail_a;
	mergers[1] = head_a_tail_a;
	mergers[2] = head_a_head_b_2a;
	mergers[3] = tail_a_tail_b_2a;
	mergers[4] = head_a_tail_b;
	mergers[5] = head_b_tail_b;
	mergers[6] = head_a_head_b_2b;
	mergers[7] = tail_a_tail_b_2b;
}

static int	run_best_possible2(t_ps_data **data, size_t blocks[4], \
								size_t possibles[8], int repet)
{
	int			(*mergers[8])(t_ps_data *, size_t *);
	t_ps_data	*copy_data[8];
	size_t		step_counts[8];
	int			i;
	int			best_i;

	set_mergers_values(mergers);
	ft_bzero(copy_data, sizeof(copy_data));
	ft_bzero(step_counts, sizeof(step_counts));
	i = 0;
	while (i < 8)
	{
		if (possibles[i])
		{
			copy_data[i] = clone_data(*data);
			if (mergers[i](copy_data[i], blocks))
				return (-1);
			if (0 < repet)
				if (make_one_merge2(&copy_data[i], repet - 1) == -1)
					return (-1);
			steps_reducer_extra(copy_data[i]->steps);
			steps_reducer(copy_data[i]->steps);
			step_counts[i] = ft_stack_size(copy_data[i]->steps);
			// while (step_counts[i] != ft_stack_size(data[i]->steps))
			// {
			// 	step_counts[i] = ft_stack_size(copy_data[i]->steps);
			// 	steps_reducer(copy_data[i]->steps);
			// 	steps_reducer_extra(copy_data[i]->steps);
			// 	// ft_fprintf(2, "test: %d\n", (int)step_counts[i]);
			// }
		}
		i++;
	}
	best_i = select_best_poss(step_counts);
	i = 0;
	while (i < 8)
	{
		if (i != best_i)
			free_ps_data(&copy_data[i]);
		i++;
	}
	free_ps_data(data);
	*data = copy_data[best_i];
	return (0);
}

int	make_one_merge2(t_ps_data **data, int repet)
{
	size_t	blocks[4];
	size_t	possibles[8];

	if (get_blocks(*data, blocks) == -1)
		return (-1);
	if (blocks[HEAD_A] == (*data)->len)
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
		ft_bzero(possibles, sizeof(int) * 4);
	if (blocks[HEAD_A] == 0)
		ft_bzero(&possibles[4], sizeof(int) * 4);
	if (blocks[HEAD_A] == ft_stack_size((*data)->a))
		possibles[1] = 0;
	if (blocks[HEAD_B] == ft_stack_size((*data)->b))
		possibles[5] = 0;
	return (run_best_possible2(data, blocks, possibles, repet));
}
