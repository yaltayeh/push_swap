/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:15:49 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/18 08:11:15 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_ps_data(t_ps_data **data_ref)
{
	t_ps_data	*data;

	data = *data_ref;
	if (!data)
		return ;
	if (data->a)
		ft_stack_clear(&data->a);
	if (data->b)
		ft_stack_clear(&data->b);
	if (data->steps)
		ft_stack_clear(&data->steps);
	free(data);
	*data_ref = NULL;
}

void	exit_handler(int err_code, t_ps_data **data)
{
	ft_fprintf(2, "Error\n");
	free_ps_data(data);
	exit(err_code);
}

static int	add_new_node(t_stack *stack, int number)
{
	t_node	*node;

	node = NULL;
	if (ft_stack_search(stack, (t_data)number, &node))
		return (-1);
	if (node)
		return (-1);
	node = ft_init_node((t_data)number);
	if (!node)
		return (-1);
	ft_stack_tail_push(stack, node);
	return (0);
}

int	parser_stack(t_stack *stack, const int argc, char **argv)
{
	int			i;
	const char	*slice;
	int			ret;
	int			number;

	if (!stack)
		return (-1);
	i = 1;
	while (stack && i < argc)
	{
		slice = ft_strtok(argv[i], ", \n\t");
		while (slice)
		{
			if (ft_atoi_save_r(&slice, &number))
				return (-1);
			if (*slice != '\0')
				return (-1);
			ret = add_new_node(stack, number);
			if (ret)
				return (ret);
			slice = ft_strtok(NULL, ", \n\t");
		}
		i++;
	}
	return (0);
}
