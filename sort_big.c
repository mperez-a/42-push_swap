/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperez-a <mperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:28:29 by mperez-a          #+#    #+#             */
/*   Updated: 2023/05/10 13:44:21 by mperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_stack **stack_a, t_stack **stack_b, int chunks)
{
	int		len;

	move_chunk(stack_a, stack_b, chunks);
	len = ft_numelements(stack_b);
	while (len > 0)
	{
		put_max_in_top(stack_b, len);
		push(stack_b, stack_a, 'a');
		len = ft_numelements(stack_b) + 1;
		len--;
	}
	//mostra(stack_a);
}

void	move_chunk(t_stack **stack_a, t_stack **stack_b, int chunks)
{
	int	chunk_size;
	int	multiply_size;
	int	elements_counter;
	int	start;
	int	counter;

	chunk_size = ft_numelements(stack_a) / chunks;
	multiply_size = chunk_size;
	elements_counter = 0;
	start = 0;
	counter = 1;
	if (ft_issorted(*stack_a))
		return ;
	while (counter++ <= chunks)
	{
		while (elements_counter < chunk_size)
		{
			if ((*stack_a)->index < chunk_size)
			{
				push(stack_a, stack_b, 'b');
				if (((*stack_b)->index) <= ((chunk_size + start) / 2))
					rotate(stack_b, 'b');
				elements_counter++;
			}
			else
				rotate(stack_a, 'a');
		}
		ft_put_index(stack_a);
		start = chunk_size;
		chunk_size = chunk_size + multiply_size;
	}
	while (ft_numelements(stack_a))
		push(stack_a, stack_b, 'b');
}

void	put_max_in_top(t_stack **stack_b, int size)
{
	int		max;
	int		max_pos;
	t_stack	*tmp;

	max = ft_find_index_biggest(stack_b);
	if (max == (*stack_b)->index)
		return ;
	tmp = *stack_b;
	max_pos = ft_find_pos_biggest(stack_b);
	while (tmp->next)
	{
		size = ft_numelements(stack_b);
		if (tmp->index == max)
			break ;
		if (max_pos < (size / 2))
			rotate(stack_b, 'b');
		else
			reverse_rotate(stack_b, 'b');
	}
	if ((*stack_b)->content < (*stack_b)->next->content)
		swap(stack_b, 'b');
}
