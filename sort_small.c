/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperez-a <mperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:46:15 by mperez-a          #+#    #+#             */
/*   Updated: 2023/05/08 10:30:07 by mperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_stack **a, int elements)
{
	if (elements == 2)
		swap(a, 'a');
	if (elements == 3)
		sort_three(a);
}

void	sort_four_five(t_stack **a, t_stack **b, int elements)
{
	if (elements == 4)
		sort_four(a, b);
	if (elements == 5)
		sort_five(a, b);
}

void	sort_three(t_stack **stack)
{
	if (ft_issorted(*stack))
		return ;
	if ((*stack)->content < (*stack)->next->content)
		reverse_rotate(stack, 'a');
	else if (ft_find_pos_biggest(stack) == 0)
		rotate(stack, 'a');
	if (!ft_issorted(*stack))
		swap(stack, 'a');
}

void	sort_four(t_stack **a, t_stack **b)
{
	if (ft_issorted(*a) && ft_issorted(*b))
		return ;
	if (ft_find_pos_minor(a) == 1)
		swap(a, 'a');
	else if (ft_find_pos_minor(a) == 2)
		reverse_rotate(a, 'a');
	if (ft_find_pos_minor(a) == 3)
		reverse_rotate(a, 'a');
	if (ft_issorted(*a))
		return ;
	push(a, b, 'b');
	sort_three(a);
	push(b, a, 'a');
}

void	sort_five(t_stack **a, t_stack **b)
{
	if (ft_issorted(*a) && ft_issorted(*b))
		return ;
	if (ft_find_pos_minor(a) == 1)
		swap(a, 'a');
	else if (ft_find_pos_minor(a) == 2)
		reverse_rotate(a, 'a');
	if (ft_find_pos_minor(a) == 3)
		reverse_rotate(a, 'a');
	if (ft_find_pos_minor(a) == 4)
		reverse_rotate(a, 'a');
	push(a, b, 'b');
	if (ft_find_pos_minor(a) == 1)
		swap(a, 'a');
	else if (ft_find_pos_minor(a) == 2)
		reverse_rotate(a, 'a');
	if (ft_find_pos_minor(a) == 3)
		reverse_rotate(a, 'a');
	if (!ft_issorted(*a))
	{
		push(a, b, 'b');
		sort_three(a);
		push(b, a, 'a');
	}
	push(b, a, 'a');
}
