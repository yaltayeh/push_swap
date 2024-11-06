/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 01:19:47 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/06 01:23:20 by yaltayeh         ###   ########.fr       */
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

int	main(const int argc, char **argv)
{
	t_ps_data	*data;

	data = malloc(sizeof(t_ps_data));
	if (argc == 1)
		return (0);
	data->a = ft_init_stack(FT_INT, int_cmp, NULL, NULL);
	if (parser_stack(data->a, argc, argv))
	{
		ft_fprintf(2, "Error\n");
		return (1);
	}
	data->b = ft_init_stack(FT_INT, int_cmp, NULL, NULL);
	data->steps = ft_init_stack(FT_POINTER, ft_strcmp, NULL, free);
	if (merge_sort(data))
	{
		ft_fprintf(2, "Error in sorting\n");
		return (1);
	}
	steps_reducer(data->steps);
	ft_stack_head_iter(data->steps, print_step);
	ft_stack_clear(&data->a);
	ft_stack_clear(&data->b);
	ft_stack_clear(&data->steps);
	return (0);
}
