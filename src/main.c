/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tevers <tevers@EMAILEMAIL>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:33:22 by shovsepy          #+#    #+#             */
/*   Updated: 2023/12/04 20:13:25 by tevers           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **str)
{
	int		i;
	char	*tmp;

	i = -1;
	while (str[++i])
	{
		tmp = str[i];
		free(tmp);
		tmp = NULL;
	}
	free(str);
}

void	ft_error(char *s)
{
	ft_putendl_fd(s, 1);
	exit(0);
}

static void allocate_stack(t_lst **stack, int argc, char **argv) 
{
    char **args;
    int i;
	
	i = (argc == 2) ? 0 : 1;
    args = (argc == 2) ? ft_split(argv[1], ' ') : argv;
    while (args[i]) 
	{
        t_lst *new = ft_lst_new(ft_atoi(args[i]));
        ft_lst_add_back(stack, new);
        i++;
    }
    index_stack(stack);
    if (argc == 2)
        ft_free(args);
}

void	sort_stack(t_lst **stack_a, t_lst **stack_b)
{
    int size;

	size = ft_lst_len(*stack_a);
    if (is_sorted(stack_a) || size < 2) 
		return;
    if (size == 2) 
		sa(stack_a);
    else if (size == 3) 
		sort_3(stack_a);
    else if (size == 4) 
		sort_4(stack_a, stack_b);
    else if (size == 5) 
		sort_5(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_lst	**stack_a;
	t_lst	**stack_b;

	if (argc < 2)
		return (-1);
	validate_input(argc, argv);
	stack_a = (t_lst **)malloc(sizeof(t_lst));
	if (!stack_a)
		return (-1);
	*stack_a = NULL;
	allocate_stack(stack_a, argc, argv);
	if (is_sorted(stack_a))
		return (ft_lst_free(stack_a), 0);
	stack_b = (t_lst **)malloc(sizeof(t_lst));
	if (!stack_b)
		return (free(stack_a), -1);
	*stack_b = NULL;
	sort_stack(stack_a, stack_b);
	ft_lst_free(stack_a);
	ft_lst_free(stack_b);
	return (0);
}

