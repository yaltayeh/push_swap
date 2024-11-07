/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:15:49 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/07 10:19:55 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <sys/errno.h>

int	print_stack(int value)
{
	ft_fprintf(0, "%11d\n", value);
	return (0);
}

int	print_step(t_step *step)
{
	if (!step)
		return (1);
	ft_printf("%s\n", step->title);
	return (0);
}

int	print_step2(t_step *step)
{
	if (!step)
		return (1);
	ft_fprintf(2, "%-4s: %p\n", step->title, step->op);
	return (0);
}

static int	add_new_node(t_stack *stack, int number)
{
	t_node	*node;

	node = NULL;
	if (ft_stack_search(stack, (t_data)number, &node))
		return (-1);
	if (node)
		return (EINVAL);
	node = ft_init_node((t_data)number);
	if (!node)
		return (ENOMEM);
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
		return (ENOMEM);
	i = 1;
	while (stack && i < argc)
	{
		slice = ft_strtok(argv[i], ", \n\t");
		while (slice)
		{
			if (ft_atoi_save_r(&slice, &number))
				return (EOVERFLOW);
			if (*slice != '\0')
				return (EINVAL);
			ret = add_new_node(stack, number);
			if (ret)
				return (ret);
			slice = ft_strtok(NULL, ", \n\t");
		}
		i++;
	}
	return (0);
}
