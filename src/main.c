/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 01:19:47 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/18 10:00:28 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include <push_swap.h>
#include <sys/errno.h>
#include <stdio.h>

int			print_step(t_step *step);
int			int_cmp(int a, int b);
t_ps_data	*init_ps_data(void);

int	main(const int argc, char **argv)
{
	t_ps_data	*data;
	t_ps_data	*copy;
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
	steps_count = -1;
	ft_stack_head_iter(data->steps, print_step);
	ft_fprintf(2, "\n\n\n");
	while (steps_count != ft_stack_size(data->steps))
	{
		steps_count = ft_stack_size(data->steps);
		steps_reducer_extra(data->steps);
		steps_reducer(data->steps);
	}
	ft_stack_head_iter(data->steps, print_step);
	free_ps_data(&data);
	return (0);
}

int	print_step(t_step *step)
{
	if (!step)
		return (1);
	ft_printf("%s\n", step->title);
	ft_fprintf(2, "%s (%d, %d)\n", step->title, 
				(int)step->stack_len[0], 
				(int)step->stack_len[1] 
				);
	return (0);
}

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
