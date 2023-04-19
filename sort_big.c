/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperez-a <mperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:28:29 by mperez-a          #+#    #+#             */
/*   Updated: 2023/04/18 18:28:41 by mperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_stack **stack_a, t_stack **stack_b, int chunks, int size)
{
	int	chunk_size;
	int	count;
	int num_elements;
	int len;

	count = 1;
	num_elements = 0;
	chunk_size = size / chunks;
	len = ft_numelements(stack_a);
	//printf("chunk_size = %d\n", chunk_size);
	while (chunks >= count)
	{
		while (num_elements < len)
		{
			put_min_in_top(stack_a);
			push(stack_a, stack_b, 'b');
			//printf("count = %d\n", count);
			num_elements++;
		}
		count++;
		//printf("count 2 = %d\n", count);
	}
}

void	put_min_in_top(t_stack **stack_a)
{
	int	min;
	int i;
	int	len;
	int	min_pos;
	t_stack *tmp;

	i = 1;
	tmp = *stack_a;
	len = ft_numelements(stack_a);
	//printf("****************************************\n");
	//printf("len = %d\n", len);
	min = ft_find_index_minor(stack_a);
	//printf("min = %d\n", min);
	min_pos = ft_find_minor(stack_a);
	//printf("min_pos = %d\n", min_pos);
	while ((*stack_a)->index != min)
		rotate(stack_a, 'a');
	/*while ((tmp))
	{
		if ((tmp)->index == min)
			return ;
		while (i < len)
		{
			if (min_pos > (len / 2))
			{
				printf("min_posa = %d\n", min_pos);
				reverse_rotate(stack_a, 'a');
			}
			if (min_pos <= (len / 2))
			{
				printf("min_pos = %d\n", min_pos);
				rotate(stack_a, 'a');
			}
			i++;
		}
		(tmp) = (tmp)->next;
	}*/
}