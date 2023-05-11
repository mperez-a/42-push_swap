/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperez-a <mperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:03:53 by mperez-a          #+#    #+#             */
/*   Updated: 2023/05/10 12:30:55 by mperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_update_position(t_stack **stack)
{
	t_stack	*tmp;
	int		position;

	tmp = *stack;
	position = 0;
	while (tmp)
	{
		tmp->pos = position;
		position++;
		tmp = tmp->next;
	}
}

void	ft_put_index(t_stack **stack)
{
	int		min_content;
	int		index;
	t_stack	*current;

	index = 0;
	while (index < ft_numelements(stack))
	{
		min_content = INT_MAX;
		current = *stack;
		while (current)
		{
			if (current->content < min_content && current->index == -1)
				min_content = current->content;
			current = current->next;
		}
		current = *stack;
		while (current)
		{
			if (current->content == min_content && current->index == -1)
				current->index = index;
			current = current->next;
		}
		index++;
	}
}
