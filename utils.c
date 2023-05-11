/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperez-a <mperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:59:41 by mperez-a          #+#    #+#             */
/*   Updated: 2023/05/10 09:38:34 by mperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	ft_atol(char *str)
{
	long long int	num;
	long long int	neg;

	num = 0;
	neg = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = neg * -1;
		str++;
	}
	while (*str == '0')
		str++;
	if (*str == '\0')
		return (num);
	while (*str && (*str >= '0' && *str <= '9'))
	{
		num = num * 10 + *str - '0';
		str++;
	}
	return (num * neg);
}

int	ft_find_pos_minor(t_stack **stack_b)
{
	t_stack	*tmp;
	int		minor;
	int		pos;

	tmp = *stack_b;
	minor = tmp->content;
	pos = tmp->pos;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (minor <= tmp->content)
			continue ;
		minor = tmp->content;
		pos = tmp->pos;
	}
	return (pos);
}

int	ft_find_pos_biggest(t_stack **a)
{
	t_stack	*tmp;
	int		biggest;
	int		pos;

	tmp = *a;
	biggest = tmp->content;
	pos = tmp->pos;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (biggest > tmp->content)
			continue ;
		biggest = tmp->content;
		pos = tmp->pos;
	}
	return (pos);
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
