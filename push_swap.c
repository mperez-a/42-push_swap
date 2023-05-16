/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperez-a <mperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:34:41 by mperez-a          #+#    #+#             */
/*   Updated: 2023/05/10 15:46:54 by mperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*fill_stack_a(t_stack *stack_a, int argc, char **argv)
{
	t_stack	*node;
	int		n;
	int		i;

	i = 1;
	n = 0;
	while (n < argc - 1)
	{
		node = ft_newlst(i, ft_atol(argv[i]));
		ft_addlst_back(&stack_a, node);
		n++;
		i++;
	}
	return (stack_a);
}

void	push_swap(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		elements;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = fill_stack_a(stack_a, argc, argv);
	elements = ft_numelements(&stack_a);
	ft_put_index(&stack_a);
	if (!ft_issorted(stack_a) && (elements == 2 || elements == 3))
		sort_small(&stack_a, elements);
	else if (!ft_issorted(stack_a) && elements <= 5)
		sort_four_five(&stack_a, &stack_b, elements);
	else if (!ft_issorted(stack_a) && elements > 5)
		sort_nums(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (argc >= 2)
		{
			if (argc == 2)
			{
				if (argv[1][0] == '\0')
				{
					ft_putstr_fd("Error\n", 2);
					exit(-1);
				}
			}
			if (!check_input(argv))
			{
				ft_putstr_fd("Error\n", 2);
				exit(-1);
			}
			push_swap(argc, argv);
		}
	}
}
