/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tevers <tevers@EMAILEMAIL>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:53:36 by tevers            #+#    #+#             */
/*   Updated: 2023/12/04 11:17:54 by tevers           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_add_front(t_lst **lst, t_lst *new_node)
{
	new_node->next = *lst;
	*lst = new_node;
}


t_lst	*ft_lst_last(t_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lst_add_back(t_lst **lst, t_lst *new_node)
{
	t_lst	*last;

	if (!*lst)
	{
		*lst = new_node;
		return ;
	}
	last = ft_lst_last(*lst);
	last->next = new_node;
}

int	ft_lst_len(t_lst *lst)
{
	t_lst	*cur;
	int		i;

	if (!lst)
		return (0);
	i = 1;
	cur = lst;
	while (cur->next)
	{
		cur = cur->next;
		i++;
	}
	return (i);
}
