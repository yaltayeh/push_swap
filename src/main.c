/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 01:19:47 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/28 07:00:58 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include <push_swap.h>
#include <sys/errno.h>
#include <stdio.h>

static int	print_step(t_step *step)
{
	if (!step)
		return (1);
	ft_printf("%s\n", step->title);
	return (0);
}

static int	int_cmp(int a, int b)
{
	if (a > b)
		return (1);
	else if (b > a)
		return (-1);
	else
		return (0);
}

static int	copy_int(int i32)
{
	return (i32);
}

static t_ps_data	*init_ps_data(void)
{
	t_ps_data	*data;

	data = ft_calloc(1, sizeof(t_ps_data));
	if (!data)
		exit_handler(1, &data);
	data->a = ft_init_stack(FT_INT, int_cmp, copy_int, NULL);
	if (!data->a)
		exit_handler(1, &data);
	data->b = ft_init_stack(FT_INT, int_cmp, copy_int, NULL);
	if (!data->b)
		exit_handler(1, &data);
	data->steps = ft_init_stack(FT_POINTER, ft_strcmp, step_copy, free);
	if (!data->steps)
		exit_handler(1, &data);
	data->logged = 0;
	return (data);
}

int	main(const int argc, char **argv)
{
	t_ps_data	*data;
	int			err;

	if (argc == 1)
		return (0);
	data = init_ps_data();
	if (!data)
		exit_handler(ERR_MALLOC, &data);
	data->logged = 1;
	err = parser_stack(data->a, argc, argv);
	if (err)
		exit_handler(err, &data);
	data->len = ft_stack_size(data->a) + ft_stack_size(data->b);
	err = merge_sort(&data);
	if (err)
		exit_handler(err, &data);
	steps_reducer(data->steps);
	ft_stack_head_iter(data->steps, print_step);
	free_ps_data(&data);
	return (0);
}
