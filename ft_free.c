/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperez-a <mperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:02:31 by mperez-a          #+#    #+#             */
/*   Updated: 2023/05/10 12:29:38 by mperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_args(int numargs, char **args)
{
	int	i;

	i = 0;
	while (i < numargs)
		free(args[i++]);
	free(args);
}

void	ft_free_stack(t_stack **stackx)
{
	t_stack	*nextnode;

	if (stackx)
	{
		while (*stackx)
		{
			nextnode = (*stackx)->next;
			free(*stackx);
			*stackx = nextnode;
		}	
	}
	*stackx = NULL;
}
