/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperez-a <mperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:28:29 by mperez-a          #+#    #+#             */
/*   Updated: 2023/05/02 20:57:10 by mperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_stack **stack_a, t_stack **stack_b, int chunks, int size)
{
	move_chunk(stack_a, stack_b, chunks);
	while ((*stack_b)->next)
	{
		put_min_in_top(stack_b, size);
		push(stack_b, stack_a, 'a');
	}
	while(*stack_b)
	{
		push(stack_b, stack_a, 'a');
	}
	mostra(stack_a);
}

void	put_min_in_top(t_stack **stack_b, int size)
{
	int	min;
	int	min_pos;
	t_stack *tmp;

	min = ft_find_index_minor(stack_b);
	if (min == (*stack_b)->index)
		return;
		
	tmp = *stack_b;
	min_pos = ft_find_pos_minor(stack_b);
	while (tmp->next)
	{
		if (tmp->index == min)
		{
			break ;
		}
		if (min_pos > (size / 2))
			rotate(stack_b, 'b');
		else
			reverse_rotate(stack_b, 'b');
	}
	if ((*stack_b)->content > (*stack_b)->next->content)
		swap(stack_b, 'b');
}

void	move_chunk(t_stack **stack_a, t_stack **stack_b, int chunks)
{
	int	num_elements;
	int	count;
	int	start;
	int	chunk_size;
	int	double_size;

	num_elements = 0;
	count = 1;
	start = 0;
	chunk_size = ft_numelements(stack_a) / chunks;
	double_size = chunk_size;

	if (ft_issorted(*stack_a))
		return ;
	while (count++ <= chunks)
	{
		while (num_elements < chunk_size)
		{
			if ((*stack_a)->index < chunk_size)
			{
				push(stack_a, stack_b, 'b');
				if ((ft_numelements(stack_b) > 1) && ((*stack_b)->index <= ((chunk_size + start) / 2)))
				{
					rotate(stack_b, 'b');
				}
			}
			else
			{
				rotate(stack_a, 'a');
			}
			num_elements++;
		}
		start = chunk_size;
		chunk_size = chunk_size + chunk_size;
	}
	while (*stack_a)
	{
		push(stack_a, stack_b, 'b');
	}
}
