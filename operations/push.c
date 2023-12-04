

#include "push_swap.h"


// Takes the first element of one stack and puts it at the top of another | pa and pb

int push(t_lst **stack_to, t_lst **stack_from)
{
    t_lst *tmp;

    if (!stack_from || !*stack_from || ft_lst_len(*stack_from) == 0)
        return (-1);
    tmp = *stack_from;
    *stack_from = tmp->next;
    tmp->next = *stack_to;
    *stack_to = tmp;
    return (0);
}

int	pa(t_lst **stack_a, t_lst **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	return (ft_printf("pa\n"), 0);
}

int	pb(t_lst **stack_a, t_lst **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	return (ft_printf("pb\n"), 0);
}
