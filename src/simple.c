/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tevers <tevers@EMAILEMAIL>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:33:22 by shovsepy          #+#    #+#             */
/*   Updated: 2023/12/04 20:12:02 by tevers           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_distance(t_lst **stack, int index)
{
    t_lst *head;
    int distance;
	
	head = *stack;
	distance = 0;
    while (head) 
	{
        if (head->index == index) 
			break;
        distance++;
        head = head->next;
    }

    return (distance);
}

static int get_min(t_lst **stack, int val)
{
    t_lst *head;
    int min;

	head = *stack;
	min = head->index;
    while (head->next) 
	{
        head = head->next;
        if ((head->index < min) && head->index != val) 
			min = head->index;
    }
    return min;
}

void sort_3(t_lst **stack_a) 
{
	int	min;
	int	next_min;

    if (is_sorted(stack_a)) 
		return;
    t_lst *head = *stack_a;
    min = get_min(stack_a, -1);
    next_min = get_min(stack_a, min);
    if (head->index == min && head->next->index != next_min)
	{
        ra(stack_a);
        sa(stack_a);
        rra(stack_a);
	}
	else if (head->index == next_min)
		(head->next->index == min) ? sa(stack_a) : rra(stack_a);
    else
		(head->next->index == min) ? ra(stack_a) : (sa(stack_a), rra(stack_a));
}

void sort_4(t_lst **stack_a, t_lst **stack_b) {
    if (is_sorted(stack_a)) return;

    int distance = get_distance(stack_a, get_min(stack_a, -1));

    if (distance == 1) ra(stack_a);
    else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);}
    else if (distance == 3) 
		rra(stack_a);

    if (is_sorted(stack_a)) 
		return;
    pb(stack_a, stack_b);
    sort_3(stack_a);
    pa(stack_a, stack_b);
}

void sort_5(t_lst **stack_a, t_lst **stack_b) {
    int distance;

	distance = get_distance(stack_a, get_min(stack_a, -1));
    if (distance == 1) 
		ra(stack_a);
    else if (distance == 2) 
	{
		ra(stack_a);
		ra(stack_a);
	}
    else if (distance == 3)
	{
		rra(stack_a); 
		rra(stack_a);
	}
    else if (distance == 4) 
		rra(stack_a);

    if (is_sorted(stack_a)) 
		return;
    pb(stack_a, stack_b);
    sort_4(stack_a, stack_b);
    pa(stack_a, stack_b);
}
