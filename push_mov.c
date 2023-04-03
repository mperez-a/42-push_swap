/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_mov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperez-a <mperez-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:02:36 by mperez-a          #+#    #+#             */
/*   Updated: 2023/03/09 13:14:14 by mperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_mov(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
	ft_update_position(src);
}

void	push(t_stack **src, t_stack **dst, char c)
{
	push_mov(src, dst);
	ft_printf("p%c\n", c);
}
