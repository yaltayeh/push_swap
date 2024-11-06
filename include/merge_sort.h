/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:18:09 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/06 00:40:28 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MERGE_SORT_H
# define MERGE_SORT_H

# include "push_swap.h"

# define HEAD_A 0
# define TAIL_A 1
# define HEAD_B 2
# define TAIL_B 3

typedef struct s_ps_data	t_ps_data;

int	a_head_block(t_stack *a, int *size);
int	a_tail_block(t_stack *a, int *size);
int	b_head_block(t_stack *b, int *size);
int	b_tail_block(t_stack *b, int *size);

int	head_b_tail_a(t_ps_data *data, int blocks[4]);
int	head_a_tail_a(t_ps_data *data, int blocks[4]);
int	head_a_head_b_2a(t_ps_data *data, int blocks[4]);
int	tail_a_tail_b_2a(t_ps_data *data, int blocks[4]);

int	head_a_tail_b(t_ps_data *data, int blocks[4]);
int	head_b_tail_b(t_ps_data *data, int blocks[4]);
int	head_a_head_b_2b(t_ps_data *data, int blocks[4]);
int	tail_a_tail_b_2b(t_ps_data *data, int blocks[4]);

int	merge_2_a(t_ps_data *data, int head_b, int tail_a);
int	merge_2_b(t_ps_data *data, int head_a, int tail_b);
int	merge_sort(t_ps_data *data);

#endif