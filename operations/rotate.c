#include "push_swap.h"

int rotate(t_lst **stack) 
{
	t_lst *head;
	t_lst *tail;

    if (ft_lst_len(*stack) < 2) 
        return (-1);
    head = *stack;
    tail = ft_lst_last(head);
    *stack = head->next;
    head->next = NULL;
    tail->next = head;
    return (0);
}

int	ra(t_lst **stack_a)
{
	if (rotate(stack_a) == -1)
		return (-1);
	return (ft_printf("ra\n"), 0);
}

int	rb(t_lst **stack_b)
{
	if (rotate(stack_b) == -1)
		return (-1);
	return (ft_printf("rb\n"), 0);
}

int	rr(t_lst **stack_a, t_lst **stack_b)
{
	if ((ft_lst_len(*stack_a) < 2) || (ft_lst_len(*stack_b) < 2))
		return (-1);
	rotate(stack_a);
	rotate(stack_b);
	return (ft_printf("rr\n"), 0);
}
