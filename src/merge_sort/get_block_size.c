/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_block_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:17:48 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/15 16:06:14 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	a_head_block(t_stack *a, size_t *size)
{
	t_node	*cur;
	int		test;

	*size = 0;
	cur = a->head;
	while (cur)
	{
		test = 0;
		if (cur->next)
			if (ft_cmp_node(cur, cur->next, &test))
				return (-1);
		cur = cur->next;
		(*size)++;
		if (test >= 0)
			break ;
	}
	return (0);
}

int	a_tail_block(t_stack *a, size_t *size)
{
	t_node	*cur;
	int		test;

	*size = 0;
	cur = a->tail;
	while (cur)
	{
		test = 0;
		if (cur->prev)
			if (ft_cmp_node(cur, cur->prev, &test))
				return (-1);
		cur = cur->prev;
		(*size)++;
		if (test <= 0)
			break ;
	}
	return (0);
}

int	b_head_block(t_stack *b, size_t *size)
{
	t_node	*cur;
	int		test;

	cur = b->head;
	*size = 0;
	while (cur)
	{
		test = 0;
		if (cur->next)
			if (ft_cmp_node(cur, cur->next, &test))
				return (-1);
		cur = cur->next;
		(*size)++;
		if (test <= 0)
			break ;
	}
	return (0);
}

int	b_tail_block(t_stack *b, size_t *size)
{
	t_node	*cur;
	int		test;

	cur = b->tail;
	*size = 0;
	while (cur)
	{
		test = 0;
		if (cur->prev)
			if (ft_cmp_node(cur, cur->prev, &test))
				return (-1);
		cur = cur->prev;
		(*size)++;
		if (test >= 0)
			break ;
	}
	return (0);
}
