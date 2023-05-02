/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_mov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperez-a <mperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:56:32 by mperez-a          #+#    #+#             */
/*   Updated: 2023/05/02 20:41:26 by mperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_mov(t_stack **stack)
{
	int	tmp;
	int	index;

	tmp = (*stack)->content;
	index = (*stack)->index;
	(*stack)->content = (*stack)->next->content;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->content = tmp;
	(*stack)->next->index = index;
}

void	swap(t_stack **stack, char c)
{
	swap_mov(stack);
	ft_printf("s%c\n", c);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_mov(stack_a);
	swap_mov(stack_b);
	ft_printf("ss\n");
}
