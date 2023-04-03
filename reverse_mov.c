/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_mov.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperez-a <mperez-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:49:30 by mperez-a          #+#    #+#             */
/*   Updated: 2023/03/07 12:08:11 by mperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_mov(t_stack **stack)
{
	int		first;
	t_stack	*tmp;

	tmp = *stack;
	first = tmp->content;
	while (tmp->next)
	{
		tmp->content = tmp->next->content;
		tmp = tmp->next;
	}
	tmp->content = first;
}

void	rotate(t_stack **stack, char c)
{
	rotate_mov(stack);
	ft_printf("r%c\n", c);
}
