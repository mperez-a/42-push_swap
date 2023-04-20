/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperez-a <mperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:28:29 by mperez-a          #+#    #+#             */
/*   Updated: 2023/04/20 18:39:48 by mperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_stack **stack_a, t_stack **stack_b, int chunks, int size)
{
	int	chunk_size;
	
	chunk_size = size / chunks;
	while ((*stack_a)->next)
	{
		put_min_in_top(stack_a, size);
		push(stack_a, stack_b, 'b');
	}
	
	while(*stack_b)
	{
		push(stack_b, stack_a, 'a');
	}
}

void	put_min_in_top(t_stack **stack_a, int size)
{
	int	min;
	int	min_pos;
	t_stack *tmp;

	min = ft_find_index_minor(stack_a);
	if (min == (*stack_a)->index)
		return;
		
	tmp = *stack_a;
	min_pos = ft_find_pos_minor(stack_a);
	while (tmp->next)
	{
		if (tmp->index == min)
			break ;
		if (min_pos > (size / 2))
			reverse_rotate(stack_a, 'a');
		else
			rotate(stack_a, 'a');
	}
	if ((*stack_a)->content > (*stack_a)->next->content)
		swap(stack_a, 'a');
}
