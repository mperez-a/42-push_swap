/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nums.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperez-a <mperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:30:00 by mperez-a          #+#    #+#             */
/*   Updated: 2023/04/18 18:20:48 by mperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_nums(t_stack **stack_a, t_stack **stack_b)
{
	int len;

	len = ft_numelements(stack_a);
	if (len > 5 && len <= 20)
		sort_big(stack_a, stack_b, 2, len);
	if (len > 20 && len <= 100)
		sort_big(stack_a, stack_b, 5, len);
	if (len > 100 && len <= 250)
		sort_big(stack_a, stack_b, 6, len);
	if (len > 250 && len <= 500)
		sort_big(stack_a, stack_b, 7, len);
}

int	ft_find_index_minor(t_stack **stack_a)
{
	t_stack	*tmp;
	int		minor;
	int		index;

	tmp = *stack_a;
	minor = tmp->content;
	index = tmp->index;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (minor <= tmp->content)
			continue ;
		minor = tmp->content;
		index = tmp->index;
	}
	return (index);
}

int	ft_find_index_biggest(t_stack **a)
{
	t_stack	*tmp;
	int		biggest;
	int		index;

	tmp = *a;
	biggest = tmp->content;
	index = tmp->index;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (biggest > tmp->content)
			continue ;
		biggest = tmp->content;
		index = tmp->index;
	}
	return (index);
}