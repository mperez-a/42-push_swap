/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_mov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperez-a <mperez-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:48:28 by mperez-a          #+#    #+#             */
/*   Updated: 2023/03/10 18:59:39 by mperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap_mov(t_stack **stack)
{
    int tmp;

    tmp = (*stack)->content;
    (*stack)->content = (*stack)->next->content;
    (*stack)->next->content = tmp;
}

void    swap(t_stack **stack, char c)
{
    swap_mov(stack);
    ft_printf("s%c\n", c);
}

void	ss_mov(t_stack **stack_a, t_stack **stack_b)
{
	swap_mov(stack_a);
	swap_mov(stack_b);
	ft_printf("ss\n");
}
