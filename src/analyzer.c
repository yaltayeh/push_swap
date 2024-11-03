/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyzer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:14:57 by yaltayeh          #+#    #+#             */
/*   Updated: 2024/11/02 21:15:10 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

typedef	struct s_op
{
	char	name[4];
	int		(*op)(t_stack *step, t_stack *a, t_stack *b);
}	t_op;


const struct s_op ops[] = {
	{"sa", sa},
	{"sb", sb},
	{"ss", ss},

	{"rra", rra},
	{"rrb", rrb},
	{"rrr", rrr},

	{"ra", ra},
	{"rb", rb},
	{"rr", rr},

	{"pa", pa},
	{"pb", pb},
};

const int ops_count = sizeof(ops) / sizeof(ops[0]); 

int main()
{
    char    *line;
	int	counter[ops_count];

	ft_bzero(counter, sizeof(counter));
    while ((line = get_next_line(0)))
    {
		int i = 0;
		for (; i < ops_count; i++)
			if (!ft_strncmp(line, ops[i].name, ft_strlen(line) - 1))
				break;
		if (i == ops_count)
		{
			ft_fprintf(2, "op '%s' not found.\n", line);
			free(line);
			exit(1);
		}
		counter[i]++;
		free(line);
    }
	ft_printf("-------------------\n");
	for (int i = 0; i < ops_count; i++)
	{
		ft_printf("%s: %d\t", ops[i].name, counter[i]);
		if ((i + 1) % 3 == 0)
			ft_printf("\n");
	}
	ft_printf("\n-------------------\n");
	return (0);
}