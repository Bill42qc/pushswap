/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin <bmartin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:06:33 by bmartin           #+#    #+#             */
/*   Updated: 2023/03/02 22:31:00 by bmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"
#include "libft.h"

int	ft_atoi(const char *str)
{
	int		sign;
	long	result;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	result = ft_atoi2(str, i, result, sign);
	if (result <= INT_MAX && result >= -INT_MIN)
		return (result);
	else
	{
		print_error();
		return (0);
	}
}

long	ft_atoi2(const char *str, int i, long result, int sign)
{
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i++] - '0';
	}
	result = result * sign;
	return (result);
}
