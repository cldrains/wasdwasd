#include "push_swap.h"

int rev_rotate(t_lst **stack) 
{
    if (ft_lst_len(*stack) < 2) 
        return (-1);

    t_lst *head = *stack;
    t_lst *tail = ft_lst_last(head);

    while (head->next->next != NULL) {
        head = head->next;
    }

    head->next = NULL;
    tail->next = *stack;
    *stack = tail;

    return (0);
}

int	rra(t_lst **stack_a)
{
	if (rev_rotate(stack_a) == -1)
		return (-1);
	return (ft_printf("rra\n"), 0);
}

int	rrb(t_lst **stack_b)
{
	if (rev_rotate(stack_b) == -1)
		return (-1);
	return (ft_printf("rrb\n"), 0);
}

int	rrr(t_lst **stack_a, t_lst **stack_b)
{
	if ((ft_lst_len(*stack_a) < 2) || (ft_lst_len(*stack_b) < 2))
		return (-1);
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	return (ft_printf("rrr\n"), 0);
}