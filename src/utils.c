/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:15:49 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/28 07:13:20 by yaltayeh         ###   ########.fr       */
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
	if (err_code == ERR_OVERFLOW)
		ft_fprintf(2, "Found overflow arg\n");
	else if (err_code == ERR_NOTNUMBER)
		ft_fprintf(2, "Found non number arg\n");
	else if (err_code == ERR_MALLOC)
		perror("push_swap");
	else if (err_code == ERR_DOUBLE)
		ft_fprintf(2, "Found double args\n");
	else if (err_code == ERR_CMP_FUNC)
		ft_fprintf(2, "Error from cmp function\n");
	ft_fprintf(2, "Error\n");
	free_ps_data(data);
	exit(err_code);
}

static int	add_new_node(t_stack *stack, int number)
{
	t_node	*node;

	node = NULL;
	if (ft_stack_search(stack, (t_data)number, &node))
		return (ERR_CMP_FUNC);
	if (node)
		return (ERR_DOUBLE);
	node = ft_init_node((t_data)number);
	if (!node)
		return (ERR_MALLOC);
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
				return (ERR_OVERFLOW);
			if (*slice != '\0')
				return (ERR_NOTNUMBER);
			ret = add_new_node(stack, number);
			if (ret)
				return (ret);
			slice = ft_strtok(NULL, ", \n\t");
		}
		i++;
	}
	return (0);
}
