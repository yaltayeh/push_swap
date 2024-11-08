/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:17:58 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/08 00:45:59 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "merge_sort.h"

static int	select_best_poss(int poss[8])
{
	int	i;
	float	min;
	int	min_i;

	min = INT_MAX;
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

static int	run_best_possible(t_ps_data *data, int blocks[4], int possibles[8])
{
	int	(*mergers[8])(t_ps_data *, int *);
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

int	make_one_merge(t_ps_data *data, int target)
{
	int	blocks[4];
	int	possibles[8];

	if (a_head_block(data->a, &blocks[HEAD_A]))
		return (-1);
	if (a_tail_block(data->a, &blocks[TAIL_A]))
		return (-1);
	if (b_head_block(data->b, &blocks[HEAD_B]))
		return (-1);
	if (b_tail_block(data->b, &blocks[TAIL_B]))
		return (-1);
	if (blocks[HEAD_A] == target)
		return (1);
	possibles[0] = ( blocks[HEAD_B] + blocks[TAIL_A]		) * 500;
	possibles[1] = ( blocks[HEAD_A] * 2 + blocks[TAIL_A]	) * 500;
	possibles[2] = ( blocks[HEAD_A] * 2 + blocks[HEAD_B]	) * 500;
	possibles[3] = ( blocks[TAIL_A] + blocks[TAIL_B] * 2	) * 500;
	possibles[4] = ( blocks[HEAD_A] + blocks[TAIL_B]		) * 500;
	possibles[5] = ( blocks[HEAD_B] * 2 + blocks[TAIL_B]	) * 500;
	possibles[6] = ( blocks[HEAD_A] + blocks[HEAD_B] * 2	) * 500;
	possibles[7] = ( blocks[TAIL_A] * 2 + blocks[TAIL_B]	) * 500;
	if (blocks[HEAD_B] == 0)
		ft_bzero(possibles, sizeof(int) * 4);
	if (blocks[HEAD_A] == 0)
		ft_bzero(&possibles[4], sizeof(int) * 4);
	if (blocks[HEAD_A] == (int)ft_stack_size(data->a))
		possibles[1] = 0;
	if (blocks[HEAD_B] == (int)ft_stack_size(data->b))
		possibles[5] = 0;
	return (run_best_possible(data, blocks, possibles));
}






static t_ps_data	*clone_data(t_ps_data *data)
{
	t_ps_data	*new_data;

	new_data = malloc(sizeof(t_ps_data));
	if (!new_data)
		return (NULL);
	new_data->logged = data->logged;
	new_data->a = ft_stack_copy(data->a);
	new_data->b = ft_stack_copy(data->b);
	new_data->steps = ft_stack_copy(data->steps);
	return (new_data); 
}


static int	make_one_merge2(t_ps_data **data, int repet);

static int	run_best_possible2(t_ps_data **data, int blocks[4], int possibles[8], int repet)
{
	int	(*mergers[8])(t_ps_data *, int *);
	t_ps_data	*copy_data[8];
	int 	step_counts[8];
	int		i;
	int		best_i;

	mergers[0] = head_b_tail_a;
	mergers[1] = head_a_tail_a;
	mergers[2] = head_a_head_b_2a;
	mergers[3] = tail_a_tail_b_2a;
	mergers[4] = head_a_tail_b;
	mergers[5] = head_b_tail_b;
	mergers[6] = head_a_head_b_2b;
	mergers[7] = tail_a_tail_b_2b;
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
			steps_reducer(copy_data[i]->steps);
			step_counts[i] = (int)ft_stack_size(copy_data[i]->steps);
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

static int	make_one_merge2(t_ps_data **data, int repet)
{
	int	blocks[4];
	int	possibles[8];

	if (repet <= 0)
		return (0);
	if (a_head_block((*data)->a, &blocks[HEAD_A]))
		return (-1);
	if (a_tail_block((*data)->a, &blocks[TAIL_A]))
		return (-1);
	if (b_head_block((*data)->b, &blocks[HEAD_B]))
		return (-1);
	if (b_tail_block((*data)->b, &blocks[TAIL_B]))
		return (-1);
	if (blocks[HEAD_A] == (int)(ft_stack_size((*data)->a) + ft_stack_size((*data)->b)))
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
	if (blocks[HEAD_A] == (int)ft_stack_size((*data)->a))
		possibles[1] = 0;
	if (blocks[HEAD_B] == (int)ft_stack_size((*data)->b))
		possibles[5] = 0;

	// ft_fprintf(2, "repet: %d\n[", repet);
	// for (int i = 0; i < 8; i++)
	// 	ft_fprintf(2, "%d%s", possibles[i], i == 7 ? "": ", ");
	// ft_fprintf(2, "]\n");
	
	return (run_best_possible2(data, blocks, possibles, repet));
}






int	move_1_2_to_b(t_ps_data *data)
{
	int	head_a;

	while (ft_stack_size(data->a) * 1.f > ft_stack_size(data->b) * 1.f)
	{
		if (a_head_block(data->a, &head_a))
			return (-1);
		if (merge_2_b(data, head_a, 0))
			return (-1);
	}
	return (0);
}

int	merge_sort(t_ps_data **data)
{
	//int	target;
	//t_ps_data	*copy_data[3];
	int	ret;

	if (!(*data) || !(*data)->steps || !(*data)->a || !(*data)->b || \
		(*data)->a->data_type != (*data)->b->data_type)
		return (-1);
	ret = 0;
	//target = (int)(ft_stack_size(data->a) + ft_stack_size(data->b));
	// if (move_1_2_to_b(data))
	// 	return (-1);
	// for (int i = 0; i < 3; i++)
	// {
	// 	copy_data[i] = clone_data(*data);
	// 	ret = 0;
	// 	while (ret != 1)
	// 	{
	// 		ret = make_one_merge2(&copy_data[i], i + 1);
	// 		//ret = make_one_merge(data, target);
	// 		if (ret < 0)
	// 			return (ret);
	// 	}
	// 	ft_fprintf(2, "%i: steps %d\n", i + 1, (int)ft_stack_size(copy_data[i]->steps));
	// }
	ret = 0;
	while (ret != 1)
	{
		//ret = make_one_merge2(data, 1);
		ret = make_one_merge(*data, (int)(ft_stack_size((*data)->a) + ft_stack_size((*data)->b)));
		if (ret < 0)
			return (ret);
	}

	return (0);
}
