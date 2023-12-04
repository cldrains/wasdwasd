/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tevers <tevers@EMAILEMAIL>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:33:22 by shovsepy          #+#    #+#             */
/*   Updated: 2023/12/04 20:19:12 by tevers           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

// Util functions
// t_lst	*ft_lstnew(int value);
// t_lst	*ft_lstlast(t_lst *head);
// void	ft_lstadd_front(t_lst **stack, t_lst *new);
// void	ft_lstadd_back(t_lst **stack, t_lst *new);
void	printList(t_lst *head);
int		ft_lstsize(t_lst *head);

void	ft_error(char *msg);
void	validate_input(int argc, char **argv);
int		get_distance(t_lst **stack, int index);
void	index_stack(t_lst **stack);

void	make_top(t_lst **stack, int distance);
void	ft_free(char **str);

/* ~ ~ ~ ~ ~ ~ SORT ~ ~ ~ ~ ~ ~ */
int		is_sorted(t_lst **stack);
void	sort_5(t_lst **stack_a, t_lst **stack_b);
void	sort_4(t_lst **stack_a, t_lst **stack_b);
void	sort_3(t_lst **stack_a);
void	radix_sort(t_lst **stack_a, t_lst **stack_b);
int		get_max_value(t_lst *stack);

/* ~ ~ ~ ~ ~ ~ OPERATIONS ~ ~ ~ ~ ~ ~ */
int		swap(t_lst **stack);
int		push(t_lst **stack_to, t_lst **stack_from);
int		rotate(t_lst **stack);
int		rev_rotate(t_lst **stack);
int		sa(t_lst **stack_a);
int		sb(t_lst **stack_b);
int		ss(t_lst **stack_a, t_lst **stack_b);
int		pa(t_lst **stack_a, t_lst **stack_b);
int		pb(t_lst **stack_b, t_lst **stack_a);
int		ra(t_lst **stack_a);
int		rb(t_lst **stack_b);
int		rr(t_lst **stack_a, t_lst **stack_b);
int		rra(t_lst **stack_a);
int		rrb(t_lst **stack_b);
int		rrr(t_lst **stack_a, t_lst **stack_b);

#endif

