/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tevers <tevers@EMAILEMAIL>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:53:36 by tevers            #+#    #+#             */
/*   Updated: 2023/12/04 11:14:40 by tevers           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_lst_new(int value)
{
	t_lst	*node;

	node = malloc(sizeof(t_lst));
	if (!node)
		return (NULL);
	node->value = value;
    node->index = -1;
	node->next = NULL;
	return (node);
}

void	ft_lst_free(t_lst **lst)
{
	t_lst	*tmp;
	t_lst	*head;

	head = *lst;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(lst);
}

void	ft_lst_print(t_lst *lst)
{
	t_lst	*tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		ft_printf("%i", tmp->value);
		tmp = tmp->next;
	}
}