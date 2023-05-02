/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperez-a <mperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:49:30 by mperez-a          #+#    #+#             */
/*   Updated: 2023/05/02 20:41:16 by mperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_mov(t_stack **stack)
{
	int		first;
	t_stack	*tmp;
	int		firts_index;

	tmp = *stack;
	first = tmp->content;
	firts_index = tmp->index;
	while (tmp->next)
	{
		tmp->content = tmp->next->content;
		tmp->index = tmp->next->index;
		tmp = tmp->next;
	}
	tmp->content = first;
	tmp->index = firts_index;
}

void	rotate(t_stack **stack, char c)
{
	rotate_mov(stack);
	ft_printf("r%c\n", c);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_mov(stack_a);
	rotate_mov(stack_b);
	ft_printf("rr\n");
}
