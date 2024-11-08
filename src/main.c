/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 01:19:47 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/07 23:55:30 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include <push_swap.h>
#include <sys/errno.h>
#include <stdio.h>

int	int_cmp(int a, int b)
{
	if (a > b)
		return (1);
	else if (b > a)
		return (-1);
	else
		return (0);
}
int int_cpy(int value)
{
	return (value);
}

t_ps_data	*init_ps_data()
{
	t_ps_data	*data;

	data = malloc(sizeof(t_ps_data));
	if (!data)
		return (NULL);
	data->a = ft_init_stack(FT_INT, int_cmp, int_cpy, NULL);
	if (!data->a)
		return (free_ps_data(&data), NULL);
	data->b = ft_init_stack(FT_INT, int_cmp, int_cpy, NULL);
	if (!data->b)
		return (free_ps_data(&data), NULL);
	data->steps = ft_init_stack(FT_POINTER, ft_strcmp, step_copy, free);
	if (!data->steps)
		return (free_ps_data(&data), NULL);
	return (data);
}

int	ft_stack_range(t_stack *stack, int min, int max)
{
	t_node	*node;

	while (min < max)
	{
		node = ft_init_node((t_data)min);
		if (!node)
			return (-1);
		ft_stack_tail_push(stack, node);
		min++;
	}
	return (0);
}

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

int	main(const int argc, char **argv)
{
	t_ps_data	*data;

	if (argc == 1)
		return (0);
	data = init_ps_data();
	if (!data)
		return (1);
	data->logged = 1;
	if (parser_stack(data->a, argc, argv))
	{
		ft_fprintf(2, "Error\n");
		return (1);
	}
	if (merge_sort(&data))
	{
		ft_fprintf(2, "Error in sorting\n");
		return (1);
	}
	// ft_fprintf(2, "main steps before: %d\n", (int)ft_stack_size(data->steps));
	//steps_reducer(data->steps);
	ft_fprintf(2, "main steps: %d\n", (int)ft_stack_size(data->steps));
	ft_stack_head_iter(data->steps, print_step);

	// t_ps_data	*index;
	// t_stack		*steps;
	// index = init_ps_data();
	// if	(ft_stack_range(index->a, 0, (int)ft_stack_size(data->a)))
	// 	return (1);
	
	// steps = ft_stack_copy(data->steps);
	// ft_stack_head_iter(steps, step_reverse);
	// //ft_stack_tail_iter(steps, print_step);
	// apply_steps(index, steps);
	// index->logged = 1;
	// ft_stack_head_iter(index->a, print_stack);
	// if (merge_sort(index))
	// {
	// 	ft_fprintf(2, "Error in sorting\n");
	// 	return (1);
	// }
	// steps_reducer(index->steps);
	// ft_stack_head_iter(index->steps, print_step);
	// ft_stack_head_iter(index->a, print_stack);
	// ft_fprintf(2, "index steps: %d\n", (int)ft_stack_size(index->steps));
	// free_ps_data(index);
	// ft_stack_clear(&steps);
	free_ps_data(&data);
	return (0);
}
