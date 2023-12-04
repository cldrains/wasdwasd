/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tevers <tevers@EMAILEMAIL>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:33:22 by shovsepy          #+#    #+#             */
/*   Updated: 2023/12/04 20:14:38 by tevers           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_lst **stack) 
{
    t_lst *head;
	
	head = *stack;
    while (head && head->next)
	{
        if (head->value > head->next->value) 
			return 0;
	    head = head->next;
    }
    return (1);
}

static int	get_max_bits(t_lst **stack)
{
	t_lst	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*head_a;
	int		max_bits;
	int		size;
	int		i;
	int		j;

	j = 0;
	head_a = *stack_a;
	size = ft_lst_len(head_a);
	max_bits = get_max_bits(stack_a);
	while (j < max_bits)
	{
		i = 0;
		while (i++ < size)
		{
			head_a = *stack_a;
			if (((head_a->index >> j) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lst_len(*stack_b) != 0)
			pa(stack_a, stack_b);
		j++;
	}
}
