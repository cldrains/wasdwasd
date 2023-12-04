#include "push_swap.h"

int swap(t_lst **stack) 
{
	int		tmp_val;
	int		tmp_index;
	t_lst	*head;
	t_lst	*next;

    if (ft_lst_len(*stack) < 2) 
        return (-1);
    head = *stack;
    next = head->next;
    tmp_val = head->value;
    tmp_index = head->index;
    head->value = next->value;
    head->index = next->index;
    next->value = tmp_val;
    next->index = tmp_index;
    return (0);
}

int	sa(t_lst **stack_a)
{
	if (swap(stack_a) == -1)
		return (-1);
	return (ft_printf("sa\n"), 0);
}

int	sb(t_lst **stack_b)
{
	if (swap(stack_b) == -1)
		return (-1);
	return (ft_printf("sb\n"), 0);
}

int	ss(t_lst **stack_a, t_lst **stack_b)
{	
	if ((ft_lst_len(*stack_a) < 2) || (ft_lst_len(*stack_b) < 2))
		return (-1);
	swap(stack_a);
	swap(stack_b);
	return (ft_printf("ss\n"), 0);
}
