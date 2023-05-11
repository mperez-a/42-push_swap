/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperez-a <mperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:35:38 by mperez-a          #+#    #+#             */
/*   Updated: 2023/05/10 15:22:21 by mperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_input(char **argv)
{
	int				i;
	long long int	num;

	i = 1;
	num = 0;
	while (argv[i])
	{
		if (!ft_isnum(argv[i]))
			return (0);
		num = ft_atol(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (0);
		if (ft_isdup(argv, num, i))
			return (0);
		i++;
	}
	return (1);
}

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (ft_isspace(str[i]))
			i++;
		if ((i == 0) && (str[i] == '-' || str[i] == '+'))
			i++;
		if (str[i] == '\0')
			return (0);
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_isdup(char **argv, int num, int elements)
{
	int	i;

	i = 1;
	while (i < elements)
	{
		if (num == ft_atol(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_numelements(t_stack **a)
{
	t_stack	*tmp;
	int		elements;

	tmp = *a;
	elements = 0;
	while (tmp)
	{
		tmp = tmp->next;
		elements++;
	}
	return (elements);
}

int	ft_issorted(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
