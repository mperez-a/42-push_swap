/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_mov.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperez-a <mperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:50:10 by mperez-a          #+#    #+#             */
/*   Updated: 2023/05/02 20:41:20 by mperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_mov(t_stack **stack)
{
	t_stack	*tmp;
	int		current;
	int		next;
	int		current_index;
	int		next_index;

	tmp = *stack;
	current = tmp->content;
	current_index = tmp->index;
	while (tmp->next)
	{
		tmp = tmp->next;
		next = tmp->content;
		next_index = tmp->index;
		tmp->content = current;
		tmp->index = current_index;
		current = next;
		current_index = next_index;
	}
	(*stack)->content = current;
	(*stack)->index = current_index;
}

void	reverse_rotate(t_stack **stack, char c)
{
	reverse_rotate_mov(stack);
	ft_printf("rr%c\n", c);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_mov(stack_a);
	reverse_rotate_mov(stack_b);
	ft_printf("rrr\n");
}
