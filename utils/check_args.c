/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tevers <tevers@EMAILEMAIL>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:33:22 by shovsepy          #+#    #+#             */
/*   Updated: 2023/12/04 16:50:18 by tevers           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dup(int num, char **argv, int i)
{
	while (argv[++i])
		if (ft_atoi(argv[i]) == num)
			return (1);
	return (0);
}

int	check_max(char *str)
{
	int		i;
	char	c;
	long	number;

	i = 0;
	c = 0;
	number = 0;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			c = 1;
	if (str[0] == '\0')
		return (1);
	while (57 >= str[i] && str[i] >= 48)
	{
 		number = 10 * number + (str[i++] - 48);
		if (number > 2147483647 && c != 1)
			return (1);
		if (number > 2147483648)
			return (1);
	}
	return (0);
}

int	check_digit(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '-' || s[0] == '+')
		i++;
	if (s[0] == '\0')
		return (1);
	if (i == 1)
		if (!ft_isdigit(s[1]))
			return (1);
	while (s[i])
		if (!ft_isdigit(s[i++]))
			return (1);
	return (0);
}

void	validate_input(int argc, char **argv)
{
	char	**args;
	long	tmp;
	int		i;

	i = -1;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		args = argv;
		i++;
	}
	while (args[++i])
	{
		tmp = ft_atoi(args[i]);
		if (check_digit(args[i]) || check_dup(tmp, args, i) || check_max(args[i]))
			ft_error("Error");
	}
	if (argc == 2)
		ft_free(args);
}
