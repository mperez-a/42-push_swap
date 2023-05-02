/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperez-a <mperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:34:41 by mperez-a          #+#    #+#             */
/*   Updated: 2023/04/26 11:53:15 by mperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mostra(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		printf("\ncontenido = %d\n", tmp->content);
		printf("posicion =  %d\n", tmp->pos);
		printf("next = %p\n", tmp->next);
		printf("index = %d\n", tmp->index);
		tmp = tmp->next;
	}
	if (tmp == NULL)
	{
		printf("\nHas llegado al final de la lista\n");
	}
}

t_stack	*fill_stacka(t_stack *stack_a, int argc, char **argv)
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
	stack_a = fill_stacka(stack_a, argc, argv);
	elements = ft_numelements(&stack_a);
	ft_put_index(&stack_a);
	if (!ft_issorted(stack_a) && (elements == 2 || elements == 3))
		sort_small(&stack_a, elements);
	else if (!ft_issorted(stack_a) && elements <= 5)
		sort_four_five(&stack_a, &stack_b, elements);
	else if (!ft_issorted(stack_a) && elements > 5)
		sort_nums(&stack_a, &stack_b, elements);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (argc == 2)
		{
			ft_putstr_fd("Error\n", 2);
			exit(-1);
		}
		else if (argc > 2)
		{
			if (!check_input(argv))
			{
				ft_putstr_fd("Error\n", 2);
				exit(-1);
			}
			push_swap(argc, argv);
		}
	}
}
