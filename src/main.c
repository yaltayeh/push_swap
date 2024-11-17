/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 01:19:47 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/17 08:36:52 by yaltayeh         ###   ########.fr       */
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

t_ps_data	*init_ps_data(void)
{
	t_ps_data	*data;

	data = ft_calloc(1, sizeof(t_ps_data));
	if (!data)
		exit_handler(1, &data);
	data->a = ft_init_stack(FT_INT, int_cmp, NULL, NULL);
	if (!data->a)
		exit_handler(1, &data);
	data->b = ft_init_stack(FT_INT, int_cmp, NULL, NULL);
	if (!data->b)
		exit_handler(1, &data);
	data->steps = ft_init_stack(FT_POINTER, ft_strcmp, step_copy, free);
	if (!data->steps)
		exit_handler(1, &data);
	data->logged = 0;
	return (data);
}

int	print_step(t_step *step)
{
	if (!step)
		return (1);
	ft_printf("%s\n", step->title);
	return (0);
}

int	main(const int argc, char **argv)
{
	t_ps_data	*data;
	int			err;
	size_t		steps_count;

	if (argc == 1)
		return (0);
	data = init_ps_data();
	data->logged = 1;
	err = parser_stack(data->a, argc, argv);
	if (err)
		exit_handler(err, &data);
	err = merge_sort(data);
	if (err)
		exit_handler(err, &data);
	ft_fprintf(2, "main step count: %d\n", (int)ft_stack_size(data->steps));
	steps_count = -1;
	while (steps_count != ft_stack_size(data->steps))
	{
		steps_count = ft_stack_size(data->steps);
		steps_reducer_extra(data->steps);
		steps_reducer(data->steps);
	}
	ft_stack_head_iter(data->steps, print_step);
	exit_handler(0, &data);
}
