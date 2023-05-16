/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperez-a <mperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:28:29 by mperez-a          #+#    #+#             */
/*   Updated: 2023/05/15 16:55:20 by mperez-a         ###   ########.fr       */
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
}

void	init_variables(t_stack **stack_a, t_init *i_var, int chunks)
{
	i_var->elements_counter = 0;
	i_var->counter = 1;
	i_var->start = 0;
	i_var->chunk_size = ft_numelements(stack_a) / chunks;
	i_var->multiply_size = i_var->chunk_size;
}

void	move_chunk(t_stack **sa, t_stack **sb, int chunks)
{
	t_init	i_var;

	init_variables(sa, &i_var, chunks);
	while (i_var.counter++ <= chunks)
	{
		while (i_var.elements_counter < i_var.chunk_size)
		{
			if ((*sa)->index < i_var.chunk_size)
			{
				push(sa, sb, 'b');
				if (((*sb)->index) <= ((i_var.chunk_size + i_var.start) / 2))
					rotate(sb, 'b');
				i_var.elements_counter++;
			}
			else
				rotate(sa, 'a');
		}
		i_var.start = i_var.chunk_size;
		i_var.chunk_size = i_var.chunk_size + i_var.multiply_size;
	}
	while (ft_numelements(sa))
		push(sa, sb, 'b');
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
	while (tmp->next->index != max)
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
