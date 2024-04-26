/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin <bmartin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:33:27 by bmartin           #+#    #+#             */
/*   Updated: 2023/03/02 20:57:17 by bmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_arg(int ac, char **av)
{
	if (ac > 2)
		many_arg(ac, av);
	else if (ac == 2)
		one_arg(av[1]);
	else
		print_error();
}

void	many_arg(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit_or_space(av[i][j]) != 1)
				print_error();
			j++;
		}
		fake_minus_check(av[i]);
		i++;
	}
	check_no_double_string(av);
}

void	one_arg(char *av)
{
	int	j;

	j = 0;
	while (av[j])
	{
		if (ft_isdigit_or_space(av[j]) != 1)
			print_error();
		j++;
	}
	fake_minus_check(av);
}

int	ft_isdigit_or_space(int c)
{
	if ((c >= '0' && c <= '9') || c == '-' || c == ' ')
		return (1);
	return (0);
}

void	fake_minus_check(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		if (str[i] == '-' && ft_isdigit(str[i + 1]) != 1 && str[i - 1] != ' ' )
			print_error();
		i++;
	}
	return ;
}
