/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperez-a <mperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:17:38 by mperez-a          #+#    #+#             */
/*   Updated: 2023/05/10 10:07:25 by mperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_newlst(int pos, int content)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->pos = pos - 1;
	node->index = -1;
	node->content = content;
	node->next = NULL;
	return (node);
}

t_stack	*ft_lastlst(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_addlst_back(t_stack **lst, t_stack *new)
{
	t_stack	*aux;

	aux = *lst;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	if (new)
	{
		aux = ft_lastlst(*lst);
		aux->next = new;
	}
}
