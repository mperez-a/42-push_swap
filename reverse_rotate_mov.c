/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_mov.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperez-a <mperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:50:10 by mperez-a          #+#    #+#             */
/*   Updated: 2023/03/24 15:17:50 by mperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_mov(t_stack **stack)
{
	t_stack *tmp;
	int	current;
	int	next;

	tmp = *stack;
	current = tmp->content;
	while (tmp->next)
	{
		tmp = tmp->next;
		next = tmp->content;
		tmp->content = current;
		current = next;
	}
	(*stack)->content = current;
}

void	reverse_rotate(t_stack **stack, char c)
{
	reverse_rotate_mov(stack);
	ft_printf("rr%c\n", c);
}
