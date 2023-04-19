/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperez-a <mperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:59:41 by mperez-a          #+#    #+#             */
/*   Updated: 2023/04/18 17:42:13 by mperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	ft_error(t_stack stack_a)
{
	ft_printf("Error\n");
	ft_free(stack_a);
	exit(-1);
}*/

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

int	ft_find_minor(t_stack **stack_a)
{
	t_stack	*tmp;
	int		minor;
	int		pos;

	tmp = *stack_a;
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

int	ft_find_biggest(t_stack **a)
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

	index = 1;
	while (index <= ft_numelements(stack))
	{
		min_content = INT_MAX;
		current = *stack;
		while (current)
		{
			if (current->content < min_content && current->index == 0)
				min_content = current->content;
			current = current->next;
		}
		current = *stack;
		while (current)
		{
			if (current->content == min_content && current->index == 0)
				current->index = index;
			current = current->next;
		}
		index++;
	}
}
